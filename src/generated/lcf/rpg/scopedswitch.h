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

#ifndef LCF_RPG_SCOPEDSWITCH_H
#define LCF_RPG_SCOPEDSWITCH_H

// Headers
#include "lcf/dbstring.h"
#include "lcf/context.h"
#include <ostream>
#include <type_traits>

/**
 * rpg::ScopedSwitch class.
 */
namespace lcf {
namespace rpg {
	class ScopedSwitch {
	public:
		DBString name;
		bool default_value = false;
		bool default_value_defined = false;
		bool is_readonly = false;
		bool show_in_editor = false;
		bool auto_reset = false;
		bool map_group_inherited_value = false;
	};

	inline bool operator==(const ScopedSwitch& l, const ScopedSwitch& r) {
		return l.name == r.name
		&& l.default_value == r.default_value
		&& l.default_value_defined == r.default_value_defined
		&& l.is_readonly == r.is_readonly
		&& l.show_in_editor == r.show_in_editor
		&& l.auto_reset == r.auto_reset
		&& l.map_group_inherited_value == r.map_group_inherited_value;
	}

	inline bool operator!=(const ScopedSwitch& l, const ScopedSwitch& r) {
		return !(l == r);
	}

	std::ostream& operator<<(std::ostream& os, const ScopedSwitch& obj);

	template <typename F, typename ParentCtx = Context<void,void>>
	void ForEachString(ScopedSwitch& obj, const F& f, const ParentCtx* parent_ctx = nullptr) {
		const auto ctx1 = Context<ScopedSwitch, ParentCtx>{ "name", -1, &obj, parent_ctx };
		f(obj.name, ctx1);
		(void)obj;
		(void)f;
		(void)parent_ctx;
	}

} // namespace rpg
} // namespace lcf

#endif
