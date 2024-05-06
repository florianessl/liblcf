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

/*
 * Headers
 */
#include "lcf/lmu/reader.h"
#include "lcf/lmu/chunks.h"
#include "reader_struct.h"

namespace lcf {

// Read EasyRpgEventPageCondition.

template <>
char const* const Flags<rpg::EasyRpgEventPageCondition::Flags>::name = "EasyRpgEventPageCondition_Flags";

template <>
decltype(Flags<rpg::EasyRpgEventPageCondition::Flags>::flag_names) Flags<rpg::EasyRpgEventPageCondition::Flags>::flag_names = {
	"self_switch_a",
	"self_switch_b",
	"self_var",
	"map_switch_a",
	"map_switch_b",
	"map_var"
};

template <>
decltype(Flags<rpg::EasyRpgEventPageCondition::Flags>::flags_is2k3) Flags<rpg::EasyRpgEventPageCondition::Flags>::flags_is2k3 = {
	0,
	0,
	0,
	0,
	0,
	0
};

} //namespace lcf
