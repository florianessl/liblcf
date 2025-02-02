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
#include "lcf/rpg/savefollowerlocation.h"
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
		bool followers_enabled = false;
		bool followers_frozen = false;
		bool followers_auto_sync = true;
		bool followers_awaitable = false;
		SaveFollowerLocation follower1;
		SaveFollowerLocation follower2;
		SaveFollowerLocation follower3;
		std::vector<SaveEasyRpgWindow> windows;
	};

	inline bool operator==(const SaveEasyRpgData& l, const SaveEasyRpgData& r) {
		return l.version == r.version
		&& l.codepage == r.codepage
		&& l.followers_enabled == r.followers_enabled
		&& l.followers_frozen == r.followers_frozen
		&& l.followers_auto_sync == r.followers_auto_sync
		&& l.followers_awaitable == r.followers_awaitable
		&& l.follower1 == r.follower1
		&& l.follower2 == r.follower2
		&& l.follower3 == r.follower3
		&& l.windows == r.windows;
	}

	inline bool operator!=(const SaveEasyRpgData& l, const SaveEasyRpgData& r) {
		return !(l == r);
	}

	std::ostream& operator<<(std::ostream& os, const SaveEasyRpgData& obj);

	template <typename F, typename ParentCtx = Context<void,void>>
	void ForEachString(SaveEasyRpgData& obj, const F& f, const ParentCtx* parent_ctx = nullptr) {
		const auto ctx7 = Context<SaveEasyRpgData, ParentCtx>{ "follower1", -1, &obj, parent_ctx };
		ForEachString(obj.follower1, f, &ctx7);
		const auto ctx8 = Context<SaveEasyRpgData, ParentCtx>{ "follower2", -1, &obj, parent_ctx };
		ForEachString(obj.follower2, f, &ctx8);
		const auto ctx9 = Context<SaveEasyRpgData, ParentCtx>{ "follower3", -1, &obj, parent_ctx };
		ForEachString(obj.follower3, f, &ctx9);
		for (int i = 0; i < static_cast<int>(obj.windows.size()); ++i) {
			const auto ctx10 = Context<SaveEasyRpgData, ParentCtx>{ "windows", i, &obj, parent_ctx };
			ForEachString(obj.windows[i], f, &ctx10);
		}
		(void)obj;
		(void)f;
		(void)parent_ctx;
	}

} // namespace rpg
} // namespace lcf

#endif
