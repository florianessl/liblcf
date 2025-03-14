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

#ifndef LCF_RPG_SAVEEASYRPGSHAKEDATA_H
#define LCF_RPG_SAVEEASYRPGSHAKEDATA_H

// Headers
#include <stdint.h>
#include "lcf/context.h"
#include <ostream>
#include <type_traits>

/**
 * rpg::SaveEasyRpgShakeData class.
 */
namespace lcf {
namespace rpg {
	class SaveEasyRpgShakeData {
	public:
		bool continuous = false;
		int32_t strength = 0;
		int32_t speed = 0;
		int32_t position = 0;
		int32_t time_left = 0;
	};

	inline bool operator==(const SaveEasyRpgShakeData& l, const SaveEasyRpgShakeData& r) {
		return l.continuous == r.continuous
		&& l.strength == r.strength
		&& l.speed == r.speed
		&& l.position == r.position
		&& l.time_left == r.time_left;
	}

	inline bool operator!=(const SaveEasyRpgShakeData& l, const SaveEasyRpgShakeData& r) {
		return !(l == r);
	}

	std::ostream& operator<<(std::ostream& os, const SaveEasyRpgShakeData& obj);

	template <typename F, typename ParentCtx = Context<void,void>>
	void ForEachString(SaveEasyRpgShakeData& obj, const F& f, const ParentCtx* parent_ctx = nullptr) {
		(void)obj;
		(void)f;
		(void)parent_ctx;
	}

} // namespace rpg
} // namespace lcf

#endif
