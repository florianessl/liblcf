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
#include "lcf/rpg/easyrpgeventpagecondition.h"

namespace lcf {
namespace rpg {

std::ostream& operator<<(std::ostream& os, const EasyRpgEventPageCondition::Flags& obj) {
	for (size_t i = 0; i < obj.flags.size(); ++i) {
		os << (i == 0 ? "[" : ", ") << obj.flags[i];
	}
	os << "]";
	return os;
}

std::ostream& operator<<(std::ostream& os, const EasyRpgEventPageCondition& obj) {
	os << "EasyRpgEventPageCondition{";
	os << "flags="<< obj.flags;
	os << ", self_switch_a_id="<< obj.self_switch_a_id;
	os << ", self_switch_b_id="<< obj.self_switch_b_id;
	os << ", self_var_id="<< obj.self_var_id;
	os << ", self_var_value="<< obj.self_var_value;
	os << ", self_var_operator="<< obj.self_var_operator;
	os << ", map_switch_a_id="<< obj.map_switch_a_id;
	os << ", map_switch_b_id="<< obj.map_switch_b_id;
	os << ", map_var_id="<< obj.map_var_id;
	os << ", map_var_value="<< obj.map_var_value;
	os << ", map_var_operator="<< obj.map_var_operator;
	os << "}";
	return os;
}

} // namespace rpg
} // namespace lcf
