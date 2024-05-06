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
#include "lcf/lsd/reader.h"
#include "lcf/lsd/chunks.h"
#include "reader_struct_impl.h"

namespace lcf {

// Read SaveScopedVariableData.

template <>
char const* const Struct<rpg::SaveScopedVariableData>::name = "SaveScopedVariableData";
static TypedField<rpg::SaveScopedVariableData, int32_t> static_id(
	&rpg::SaveScopedVariableData::id,
	LSD_Reader::ChunkSaveScopedVariableData::id,
	"id",
	1,
	0
);
static TypedField<rpg::SaveScopedVariableData, int32_t> static_scope(
	&rpg::SaveScopedVariableData::scope,
	LSD_Reader::ChunkSaveScopedVariableData::scope,
	"scope",
	1,
	0
);
static TypedField<rpg::SaveScopedVariableData, int32_t> static_value(
	&rpg::SaveScopedVariableData::value,
	LSD_Reader::ChunkSaveScopedVariableData::value,
	"value",
	1,
	0
);
static TypedField<rpg::SaveScopedVariableData, int32_t> static_map_id(
	&rpg::SaveScopedVariableData::map_id,
	LSD_Reader::ChunkSaveScopedVariableData::map_id,
	"map_id",
	1,
	0
);
static TypedField<rpg::SaveScopedVariableData, int32_t> static_event_id(
	&rpg::SaveScopedVariableData::event_id,
	LSD_Reader::ChunkSaveScopedVariableData::event_id,
	"event_id",
	1,
	0
);
static TypedField<rpg::SaveScopedVariableData, bool> static_auto_reset(
	&rpg::SaveScopedVariableData::auto_reset,
	LSD_Reader::ChunkSaveScopedVariableData::auto_reset,
	"auto_reset",
	1,
	0
);


template <>
Field<rpg::SaveScopedVariableData> const* Struct<rpg::SaveScopedVariableData>::fields[] = {
	&static_id,
	&static_scope,
	&static_value,
	&static_map_id,
	&static_event_id,
	&static_auto_reset,
	NULL
};

template class Struct<rpg::SaveScopedVariableData>;

} //namespace lcf
