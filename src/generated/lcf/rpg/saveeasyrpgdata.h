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

#ifndef LCF_RPG_SAVEEASYRPGDATA_H
#define LCF_RPG_SAVEEASYRPGDATA_H

// Headers
#include <stdint.h>
#include <vector>
#include "lcf/rpg/saveeasyrpgwindow.h"
#include "lcf/rpg/savescopedswitchdata.h"
#include "lcf/rpg/savescopedvariabledata.h"
#include "lcf/context.h"
#include <ostream>
#include <type_traits>

/**
 * rpg::SaveEasyRpgData class.
 */
namespace lcf {
namespace rpg {
	class SaveEasyRpgData {
	public:
		int32_t version = 0;
		int32_t codepage = 0;
		std::vector<SaveScopedSwitchData> scoped_switches;
		std::vector<SaveScopedVariableData> scoped_variables;
		std::vector<SaveEasyRpgWindow> windows;
	};

	inline bool operator==(const SaveEasyRpgData& l, const SaveEasyRpgData& r) {
		return l.version == r.version
		&& l.codepage == r.codepage
		&& l.scoped_switches == r.scoped_switches
		&& l.scoped_variables == r.scoped_variables
		&& l.windows == r.windows;
	}

	inline bool operator!=(const SaveEasyRpgData& l, const SaveEasyRpgData& r) {
		return !(l == r);
	}

	std::ostream& operator<<(std::ostream& os, const SaveEasyRpgData& obj);

	template <typename F, typename ParentCtx = Context<void,void>>
	void ForEachString(SaveEasyRpgData& obj, const F& f, const ParentCtx* parent_ctx = nullptr) {
		for (int i = 0; i < static_cast<int>(obj.scoped_switches.size()); ++i) {
			const auto ctx3 = Context<SaveEasyRpgData, ParentCtx>{ "scoped_switches", i, &obj, parent_ctx };
			ForEachString(obj.scoped_switches[i], f, &ctx3);
		}
		for (int i = 0; i < static_cast<int>(obj.scoped_variables.size()); ++i) {
			const auto ctx4 = Context<SaveEasyRpgData, ParentCtx>{ "scoped_variables", i, &obj, parent_ctx };
			ForEachString(obj.scoped_variables[i], f, &ctx4);
		}
		for (int i = 0; i < static_cast<int>(obj.windows.size()); ++i) {
			const auto ctx5 = Context<SaveEasyRpgData, ParentCtx>{ "windows", i, &obj, parent_ctx };
			ForEachString(obj.windows[i], f, &ctx5);
		}
		(void)obj;
		(void)f;
		(void)parent_ctx;
	}

} // namespace rpg
} // namespace lcf

#endif
