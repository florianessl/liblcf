/*
 * This file is part of liblcf. Copyright (c) liblcf authors.
 * https://github.com/EasyRPG/liblcf - https://easyrpg.org
 *
 * liblcf is Free/Libre Open Source Software, released under the MIT License.
 * For the full copyright and license information, please view the COPYING
 * file that was distributed with this source code.
 */

#ifndef LCF_INSPECTION_H
#define LCF_INSPECTION_H

#ifdef LCF_DEBUG_TRACE
#include <iostream>
#endif
#include <functional>
#include <string>
#include <vector>
#include <cstdlib>
#include "lcf/span.h"
#include "lcf/dbbitarray.h"
#include "log.h"

#define LCF_DEBUG_TRACE_INSPECT

namespace lcf {
	
namespace TypeInspection {

template<typename T, typename V>
bool SetPrimitiveValue(T& ref, V& value);
template<typename V>
bool SetBooleanValue(bool& ref, V& value);
template<typename V>
bool SetIntegerValue(int& ref, V& value);

template<typename V>
bool SetStringValue(std::string& ref, V& value);

} //namespace TypeInspection

struct InspectResult {
	bool success ;
	int type = 0;
	std::vector<int64_t> data;
	std::vector<std::string> strings;

	InspectResult() noexcept
		: success(false), type(0) {
	}

	InspectResult(const bool v) noexcept
		: success(true), type(1) {
		data.emplace_back(v);
	}

	template<class T, typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
	InspectResult(const T value) noexcept
		: success(true), type(2) {
		data.emplace_back(value);
	}

	InspectResult(std::string v)
		: success(true), type(3) {
		strings.emplace_back(v);
	}

	InspectResult(const std::vector<bool>& data) noexcept
		: success(true), type(1) {
		this->data.reserve(data.size());
		for (int i = 0; i < data.size(); ++i)
			this->data.emplace_back(data[i]);
	}

	template<class T, typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
	InspectResult(const std::vector<T>& data) noexcept
		: success(true), type(2) {
		this->data.reserve(data.size());
		for (int i = 0; i < data.size(); ++i)
			this->data.emplace_back(data[i]);
	}

	InspectResult(std::vector<std::string>& data) noexcept
		: success(true), type(3) {
		this->strings.reserve(data.size());
		for (int i = 0; i < data.size(); ++i)
			this->strings.emplace_back(data[i]);
	}

	InspectResult(std::vector<int64_t>& data, int type) noexcept
		: success(true), data(std::move(data)), type(type) {
	}

	std::vector<bool> ToBoolean() {
		std::vector<bool> result;
		switch (type) {
			case 1: // boolean
			case 2: // number
				result.reserve(data.size());
				for (auto& elem : data) {
					result.push_back(elem > 0);
				}
				break;
			case 3: // string_view
				result.reserve(strings.size());
				for (auto& str : strings) {
					result.push_back(!str.empty());
				}
				break;
			default:
				break;
		}
		return result;
	}

	std::vector<int> ToInteger() {
		std::vector<int> result;
		switch (type) {
			case 1: // boolean
			case 2: // number
				result.reserve(data.size());
				for (auto& elem : data) {
					result.push_back(elem);
				}
				break;
			case 3: // string_view
				result.reserve(strings.size());
				for (auto& str : strings) {
					result.push_back(atoi(str.data()));
				}
				break;
			default:
				break;
		}
		return result;
	}

	std::vector<std::string> ToString() {
		std::vector<std::string> result;
		switch (type) {
			case 1: // boolean
				result.reserve(data.size());
				for (auto& elem : data) {
					result.push_back(elem ? "true" : "false");
				}
				break;
			case 2: // number
				result.reserve(data.size());
				for (auto& elem : data) {
					result.push_back(std::to_string(elem));
				}
				break;
			case 3: // string_view
				result.reserve(strings.size());
				for (auto& str : strings) {
					result.push_back(str);
				}
				break;
			default:
				break;
		}
		return result;
	}
};

class InspectPath {
public:
	InspectPath() : extract_count(0) {
	}

	InspectPath(lcf::Span<std::pair<int, int>> fields, int extract_count)
		: extract_count(extract_count), mode(0) {
		assert(extract_count > 0);

		for (auto p : fields) {
			nodes.push_back(PathNode{ p.first, "", p.second});
		}
	}

	InspectPath(std::string_view path, int extract_count)
		: extract_count(extract_count), mode(1) {
		assert(extract_count > 0);

		bool read_idx = false;
		PathNode curr_node { 0, std::string(), 0 };
		std::string str_idx;

		for (auto c : path) {
			if (read_idx) {
				if (c == ']') {
					nodes[nodes.size() - 1].index = atoi(str_idx.c_str());
					str_idx.clear();
					read_idx = false;
					continue;
				}
				str_idx.push_back(c);
				continue;
			}
			if (c == '.') {
				if (!curr_node.field_tag.empty()) {
					nodes.push_back(curr_node);
				}
				curr_node = { 0, std::string(), 0 };
				continue;
			}
			if (c == '[') {
				nodes.push_back(curr_node);
				curr_node = { 0, std::string(), 0 };
				read_idx = true;
				continue;
			}
			curr_node.field_tag.push_back(c);
		}

		if (!curr_node.field_tag.empty()) {
			nodes.push_back(curr_node);
		}
	}

	bool IsValid() const {
		return extract_count > 0 && nodes.size() > 0;
	}

	bool UseTags() const {
		return mode == 1;
	}

	void Reset() {
		current_node = 0;
		cnt_extracted = 0;
	}

	InspectResult InspectContainer(std::function<InspectResult(int)> fn_inspect) {
		return HandleContainer<InspectResult, int>(fn_inspect);
	}

	InspectResult InspectContainer(std::function<InspectResult(std::string_view)> fn_inspect) {
		return HandleContainer<InspectResult, std::string_view>(fn_inspect);
	}

	bool TraverseContainer(std::function<bool(int)> fn_inspect) {
		return HandleContainer<bool, int>(fn_inspect);
	}

	bool TraverseContainer(std::function<bool(std::string_view)> fn_inspect) {
		return HandleContainer<bool, std::string_view>(fn_inspect);
	}

	std::vector<std::string> TraceContainer(std::function<std::vector<std::string>(int)> fn_inspect) {
		return HandleContainer<std::vector<std::string>, int>(fn_inspect);
	}

	std::vector<std::string> TraceContainer(std::function<std::vector<std::string>(std::string_view)> fn_inspect) {
		return HandleContainer<std::vector<std::string>, std::string_view>(fn_inspect);
	}

	InspectResult InspectVector(const int vector_size, std::function<InspectResult(int)> fn_inspect) {
		return HandleVector<InspectResult>(vector_size, fn_inspect);
	}

	bool TraverseVector(const int vector_size, std::function<bool(int)> fn_inspect) {
		return HandleVector<bool>(vector_size, fn_inspect);
	}

	std::vector<std::string> TraceVector(const int vector_size, std::function<std::vector<std::string>(int)> fn_inspect) {
		return HandleVector<std::vector<std::string>>(vector_size, fn_inspect);
	}
protected:
	int curr_field_id() {
		assert(mode == 0);
		return nodes[current_node].field_id;
	}
	std::string_view curr_field_tag() {
		assert(mode == 1);
		return nodes[current_node].field_tag;
	}
	int curr_index() {
		return nodes[current_node].index;
	}

	template<typename T, typename F>
	T HandleContainer(std::function<T(F)> fn_inspect) {
		T result;

		bool descended = false;
		auto opt_descend = [&]() {
			if (this->curr_index() == 0) {
				this->current_node++;
				descended = true;
			}
		};

		if constexpr (std::is_same<F, int>::value) {
			int field_id = this->curr_field_id();
			opt_descend();
			result = fn_inspect(field_id);
		} else if constexpr (std::is_same<F, std::string_view>::value) {
			std::string_view field_tag = this->curr_field_tag();
			opt_descend();
			result = fn_inspect(field_tag);
		} else {
			static_assert(false);
		}

		if (descended) {
			this->current_node--;
		}
		return result;
	}

	template<typename T>
	T HandleVector(const int vector_size, std::function<T(int)> fn_inspect) {
		T aggregate;
		int index_start = this->curr_index();
		this->current_node++;
		/*if (this->current_node < this->nodes.size()) {
			assert(this->curr_index() == 0);
		}*/

		if constexpr (std::is_same<T, bool>::value) {
			aggregate = false;
		}

		for (int i = 0; i < this->extract_count && this->cnt_extracted < this->extract_count; ++i) {
			if (index_start + i > vector_size) {
				if constexpr (std::is_same<T, InspectResult>::value) {
					aggregate.data.emplace_back(0);
					aggregate.strings.emplace_back("");
				} else if constexpr (std::is_same<T, std::vector<std::string>>::value) {
					aggregate.push_back("[" + std::to_string(index_start + i) + "]<not-found>");
				}
				continue;
			}

			T result = fn_inspect(index_start + i - 1);

			if constexpr (std::is_same<T, InspectResult>::value) {
				aggregate.type = result.type;
				if (!result.success) {
					return {};
				}
				if (result.type < 3) {
					for (auto elem : result.data) {
						aggregate.data.emplace_back(elem);
						this->cnt_extracted++;
					}
				} else {
					for (auto str : result.strings) {
						aggregate.strings.emplace_back(str);
						this->cnt_extracted++;
					}
				} 
			} else if constexpr (std::is_same<T, bool>::value) {
				aggregate = aggregate && result;
			} else if constexpr (std::is_same<T, std::vector<std::string>>::value) {
				if (result.empty()) {
					return {};
				}
				for (auto elem : result) {
					aggregate.push_back("[" + std::to_string(index_start + i) + "]" + elem);
					this->cnt_extracted++;
				}
			}
		}
		return aggregate;
	}

private:
	struct PathNode {
		int field_id;
		std::string field_tag;
		int index;
	};

	int mode = 0;
	std::vector<PathNode> nodes;
	int extract_count;
	int current_node = 0;
	int cnt_extracted = 0;
};

namespace TypeInspection {

template<typename T, typename V>
bool SetPrimitiveValue(T& ref, V& value) {
	if constexpr (std::is_same<T, bool>::value) {
		return SetBooleanValue(ref, value);
	} else if constexpr (std::is_same<T, int>::value) {
		return SetIntegerValue(ref, value);
	} else if constexpr (std::is_same<T, std::string>::value) {
		return SetStringValue(ref, value);
	} else if constexpr (std::is_same<T, lcf::DBString>::value) {
		return SetStringValue(ref, value);
	}
	return false;
}

template<typename V>
bool SetBooleanValue(bool& ref, V& value) {
	if constexpr (std::is_same<V, bool>::value) {
		ref = (value > 0);
		return true;
	} else if constexpr (std::is_same<V, int>::value) {
		ref = value;
		return true;
	} else if constexpr (std::is_same<V, std::string_view>::value) {
		std::string value_lc = std::string(value);
		std::transform(value_lc.begin(), value_lc.end(), value_lc.begin(), ::tolower);
		if (value == "t" || value == "true") {
			ref = true;
			return true;
		} else if (value == "f" || value == "false") {
			ref = false;
			return true;
		}
		ref = !value.empty();
	}
	return false;
}

template<typename V>
bool SetIntegerValue(int& ref, V& value) {
	if constexpr (std::is_same<V, bool>::value) {
		ref = value;
		return true;
	} else if constexpr (std::is_same<V, int>::value) {
		ref = value;
		return true;
	} else if constexpr (std::is_same<V, std::string_view>::value) {
		ref = atoi(value.data());
		return true;
	}
	return false;
}

template<typename V>
bool SetStringValue(std::string& ref, V& value) {
	if constexpr (std::is_same<V, bool>::value) {
		ref = (value ? "true" : "false");
		return true;
	} else if constexpr (std::is_same<V, int>::value) {
		ref = std::to_string(value);
		return true;
	} else if constexpr (std::is_same<V, std::string_view>::value) {
		ref = std::string(value);
		return true;
	}
	return false;
}

template<typename V>
bool SetStringValue(lcf::DBString& ref, V& value) {
	if constexpr (std::is_same<V, bool>::value) {
		ref = lcf::DBString(value ? "true" : "false");
		return true;
	} else if constexpr (std::is_same<V, int>::value) {
		ref = lcf::DBString(std::to_string(value));
		return true;
	} else if constexpr (std::is_same<V, std::string_view>::value) {
		ref = lcf::DBString(value);
		return true;
	}
	return false;
}

} //namespace TypeInspection

} //namespace lcf

#endif
