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
#include "lcf/rpg/savescopedswitchdata.h"

namespace lcf {
namespace rpg {

std::ostream& operator<<(std::ostream& os, const SaveScopedSwitchData& obj) {
	os << "SaveScopedSwitchData{";
	os << "scope="<< obj.scope;
	os << ", on="<< obj.on;
	os << ", map_id="<< obj.map_id;
	os << ", event_id="<< obj.event_id;
	os << ", auto_reset="<< obj.auto_reset;
	os << "}";
	return os;
}

} // namespace rpg
} // namespace lcf
