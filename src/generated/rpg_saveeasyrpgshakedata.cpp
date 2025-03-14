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
#include "lcf/rpg/saveeasyrpgshakedata.h"

namespace lcf {
namespace rpg {

std::ostream& operator<<(std::ostream& os, const SaveEasyRpgShakeData& obj) {
	os << "SaveEasyRpgShakeData{";
	os << "continuous="<< obj.continuous;
	os << ", strength="<< obj.strength;
	os << ", speed="<< obj.speed;
	os << ", position="<< obj.position;
	os << ", time_left="<< obj.time_left;
	os << "}";
	return os;
}

} // namespace rpg
} // namespace lcf
