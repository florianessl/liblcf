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
#include "lcf/rpg/scopedvariable.h"

namespace lcf {
namespace rpg {

std::ostream& operator<<(std::ostream& os, const ScopedVariable& obj) {
	os << "ScopedVariable{";
	os << "name="<< obj.name;
	os << ", default_value="<< obj.default_value;
	os << ", default_value_defined="<< obj.default_value_defined;
	os << ", is_readonly="<< obj.is_readonly;
	os << ", show_in_editor="<< obj.show_in_editor;
	os << ", auto_reset="<< obj.auto_reset;
	os << ", map_group_inherited_value="<< obj.map_group_inherited_value;
	os << "}";
	return os;
}

} // namespace rpg
} // namespace lcf
