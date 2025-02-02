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
#include "lcf/lmu/reader.h"
#include "lcf/lmu/chunks.h"
#include "reader_struct_impl.h"

namespace lcf {

// Read EasyRpgEventPageCondition.

template <>
char const* const Struct<rpg::EasyRpgEventPageCondition>::name = "EasyRpgEventPageCondition";
static TypedField<rpg::EasyRpgEventPageCondition, rpg::EasyRpgEventPageCondition::Flags> static_flags(
	&rpg::EasyRpgEventPageCondition::flags,
	LMU_Reader::ChunkEasyRpgEventPageCondition::flags,
	"flags",
	1,
	0
);
static TypedField<rpg::EasyRpgEventPageCondition, int32_t> static_self_switch_a_id(
	&rpg::EasyRpgEventPageCondition::self_switch_a_id,
	LMU_Reader::ChunkEasyRpgEventPageCondition::self_switch_a_id,
	"self_switch_a_id",
	0,
	0
);
static TypedField<rpg::EasyRpgEventPageCondition, int32_t> static_self_switch_b_id(
	&rpg::EasyRpgEventPageCondition::self_switch_b_id,
	LMU_Reader::ChunkEasyRpgEventPageCondition::self_switch_b_id,
	"self_switch_b_id",
	0,
	0
);
static TypedField<rpg::EasyRpgEventPageCondition, int32_t> static_self_var_id(
	&rpg::EasyRpgEventPageCondition::self_var_id,
	LMU_Reader::ChunkEasyRpgEventPageCondition::self_var_id,
	"self_var_id",
	0,
	0
);
static TypedField<rpg::EasyRpgEventPageCondition, int32_t> static_self_var_value(
	&rpg::EasyRpgEventPageCondition::self_var_value,
	LMU_Reader::ChunkEasyRpgEventPageCondition::self_var_value,
	"self_var_value",
	0,
	0
);
static TypedField<rpg::EasyRpgEventPageCondition, int32_t> static_self_var_operator(
	&rpg::EasyRpgEventPageCondition::self_var_operator,
	LMU_Reader::ChunkEasyRpgEventPageCondition::self_var_operator,
	"self_var_operator",
	0,
	0
);
static TypedField<rpg::EasyRpgEventPageCondition, int32_t> static_map_switch_a_id(
	&rpg::EasyRpgEventPageCondition::map_switch_a_id,
	LMU_Reader::ChunkEasyRpgEventPageCondition::map_switch_a_id,
	"map_switch_a_id",
	0,
	0
);
static TypedField<rpg::EasyRpgEventPageCondition, int32_t> static_map_switch_b_id(
	&rpg::EasyRpgEventPageCondition::map_switch_b_id,
	LMU_Reader::ChunkEasyRpgEventPageCondition::map_switch_b_id,
	"map_switch_b_id",
	0,
	0
);
static TypedField<rpg::EasyRpgEventPageCondition, int32_t> static_map_var_id(
	&rpg::EasyRpgEventPageCondition::map_var_id,
	LMU_Reader::ChunkEasyRpgEventPageCondition::map_var_id,
	"map_var_id",
	0,
	0
);
static TypedField<rpg::EasyRpgEventPageCondition, int32_t> static_map_var_value(
	&rpg::EasyRpgEventPageCondition::map_var_value,
	LMU_Reader::ChunkEasyRpgEventPageCondition::map_var_value,
	"map_var_value",
	0,
	0
);
static TypedField<rpg::EasyRpgEventPageCondition, int32_t> static_map_var_operator(
	&rpg::EasyRpgEventPageCondition::map_var_operator,
	LMU_Reader::ChunkEasyRpgEventPageCondition::map_var_operator,
	"map_var_operator",
	0,
	0
);


template <>
Field<rpg::EasyRpgEventPageCondition> const* Struct<rpg::EasyRpgEventPageCondition>::fields[] = {
	&static_flags,
	&static_self_switch_a_id,
	&static_self_switch_b_id,
	&static_self_var_id,
	&static_self_var_value,
	&static_self_var_operator,
	&static_map_switch_a_id,
	&static_map_switch_b_id,
	&static_map_var_id,
	&static_map_var_value,
	&static_map_var_operator,
	NULL
};

template class Struct<rpg::EasyRpgEventPageCondition>;

} //namespace lcf
