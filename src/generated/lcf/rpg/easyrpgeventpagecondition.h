/* !!!! GENERATED FILE - DO NOT EDIT !!!!
 * --------------------------------------
 *
 * This file is part of liblcf. Copyright (c) liblcf authors.
 * https://github.com/EasyRPG/liblcf - https://easyrpg.org
 *
 * liblcf is Free/Libre Open Source Software, released under the MIT License.
 * For the full copyright and license information, please view the COPYING
 * file that was distributed with this source code.
 */

#ifndef LCF_RPG_EASYRPGEVENTPAGECONDITION_H
#define LCF_RPG_EASYRPGEVENTPAGECONDITION_H

// Headers
#include <array>
#include <stdint.h>
#include "lcf/enum_tags.h"
#include "lcf/context.h"
#include <ostream>
#include <type_traits>

/**
 * rpg::EasyRpgEventPageCondition class.
 */
namespace lcf {
namespace rpg {
	class EasyRpgEventPageCondition {
	public:
		struct Flags {
			union {
				struct {
					bool self_switch_a;
					bool self_switch_b;
					bool self_var;
					bool map_switch_a;
					bool map_switch_b;
					bool map_var;
				};
				std::array<bool, 6> flags;
			};
			Flags() noexcept: self_switch_a(false), self_switch_b(false), self_var(false), map_switch_a(false), map_switch_b(false), map_var(false)
			{}
		} flags;
		int32_t self_switch_a_id = 1;
		int32_t self_switch_b_id = 1;
		int32_t self_var_id = 1;
		int32_t self_var_value = 0;
		int32_t self_var_operator = 1;
		int32_t map_switch_a_id = 1;
		int32_t map_switch_b_id = 1;
		int32_t map_var_id = 1;
		int32_t map_var_value = 0;
		int32_t map_var_operator = 1;
	};

	inline bool operator==(const EasyRpgEventPageCondition::Flags& l, const EasyRpgEventPageCondition::Flags& r) {
		return l.flags == r.flags;
	}

	inline bool operator!=(const EasyRpgEventPageCondition::Flags& l, const EasyRpgEventPageCondition::Flags& r) {
		return !(l == r);
	}

	std::ostream& operator<<(std::ostream& os, const EasyRpgEventPageCondition::Flags& obj);

	inline bool operator==(const EasyRpgEventPageCondition& l, const EasyRpgEventPageCondition& r) {
		return l.flags == r.flags
		&& l.self_switch_a_id == r.self_switch_a_id
		&& l.self_switch_b_id == r.self_switch_b_id
		&& l.self_var_id == r.self_var_id
		&& l.self_var_value == r.self_var_value
		&& l.self_var_operator == r.self_var_operator
		&& l.map_switch_a_id == r.map_switch_a_id
		&& l.map_switch_b_id == r.map_switch_b_id
		&& l.map_var_id == r.map_var_id
		&& l.map_var_value == r.map_var_value
		&& l.map_var_operator == r.map_var_operator;
	}

	inline bool operator!=(const EasyRpgEventPageCondition& l, const EasyRpgEventPageCondition& r) {
		return !(l == r);
	}

	std::ostream& operator<<(std::ostream& os, const EasyRpgEventPageCondition& obj);

	template <typename F, typename ParentCtx = Context<void,void>>
	void ForEachString(EasyRpgEventPageCondition& obj, const F& f, const ParentCtx* parent_ctx = nullptr) {
		(void)obj;
		(void)f;
		(void)parent_ctx;
	}

} // namespace rpg
} // namespace lcf

#endif
