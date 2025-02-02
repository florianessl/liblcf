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

#ifndef LCF_RPG_SAVESCOPEDVARIABLEDATA_H
#define LCF_RPG_SAVESCOPEDVARIABLEDATA_H

// Headers
#include <stdint.h>
#include "lcf/context.h"
#include <ostream>
#include <type_traits>

/**
 * rpg::SaveScopedVariableData class.
 */
namespace lcf {
namespace rpg {
	class SaveScopedVariableData {
	public:
		int32_t id = 1;
		int32_t scope = 0;
		int32_t value = 0;
		int32_t map_id = 0;
		int32_t event_id = 0;
		bool auto_reset = false;
	};

	inline bool operator==(const SaveScopedVariableData& l, const SaveScopedVariableData& r) {
		return l.id == r.id
		&& l.scope == r.scope
		&& l.value == r.value
		&& l.map_id == r.map_id
		&& l.event_id == r.event_id
		&& l.auto_reset == r.auto_reset;
	}

	inline bool operator!=(const SaveScopedVariableData& l, const SaveScopedVariableData& r) {
		return !(l == r);
	}

	std::ostream& operator<<(std::ostream& os, const SaveScopedVariableData& obj);

	template <typename F, typename ParentCtx = Context<void,void>>
	void ForEachString(SaveScopedVariableData& obj, const F& f, const ParentCtx* parent_ctx = nullptr) {
		(void)obj;
		(void)f;
		(void)parent_ctx;
	}

} // namespace rpg
} // namespace lcf

#endif
