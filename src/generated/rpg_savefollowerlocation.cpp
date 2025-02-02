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

// Headers
#include "lcf/rpg/savefollowerlocation.h"

namespace lcf {
namespace rpg {

std::ostream& operator<<(std::ostream& os, const SaveFollowerLocation& obj) {
	os << "SaveFollowerLocation{";
	os << "follower_id="<< obj.follower_id;
	os << ", actor_id="<< obj.actor_id;
	os << ", is_init="<< obj.is_init;
	os << ", is_frozen="<< obj.is_frozen;
	os << ", auto_sync="<< obj.auto_sync;
	os << ", force_reset="<< obj.force_reset;
	os << ", awaitable="<< obj.awaitable;
	os << "}";
	return os;
}

} // namespace rpg
} // namespace lcf
