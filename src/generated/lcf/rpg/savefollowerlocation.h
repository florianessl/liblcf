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

#ifndef LCF_RPG_SAVEFOLLOWERLOCATION_H
#define LCF_RPG_SAVEFOLLOWERLOCATION_H

// Headers
#include "lcf/rpg/savemapeventbase.h"
#include <stdint.h>
#include "lcf/context.h"
#include <ostream>
#include <type_traits>

/**
 * rpg::SaveFollowerLocation class.
 */
namespace lcf {
namespace rpg {
	class SaveFollowerLocation : public SaveMapEventBase {
	public:
		int32_t follower_id = 0;
		int32_t actor_id = 0;
		bool is_init = 0;
		bool is_frozen = 0;
		bool auto_sync = 0;
		bool force_reset = 0;
		bool awaitable = 0;
	};

	inline bool operator==(const SaveFollowerLocation& l, const SaveFollowerLocation& r) {
		return l.follower_id == r.follower_id
		&& l.actor_id == r.actor_id
		&& l.is_init == r.is_init
		&& l.is_frozen == r.is_frozen
		&& l.auto_sync == r.auto_sync
		&& l.force_reset == r.force_reset
		&& l.awaitable == r.awaitable;
	}

	inline bool operator!=(const SaveFollowerLocation& l, const SaveFollowerLocation& r) {
		return !(l == r);
	}

	std::ostream& operator<<(std::ostream& os, const SaveFollowerLocation& obj);

	template <typename F, typename ParentCtx = Context<void,void>>
	void ForEachString(SaveFollowerLocation& obj, const F& f, const ParentCtx* parent_ctx = nullptr) {
		(void)obj;
		(void)f;
		(void)parent_ctx;
	}

} // namespace rpg
} // namespace lcf

#endif
