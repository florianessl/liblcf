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

// Read SaveScopedSwitchData.

template <>
char const* const Struct<rpg::SaveScopedSwitchData>::name = "SaveScopedSwitchData";
static TypedField<rpg::SaveScopedSwitchData, int32_t> static_id(
	&rpg::SaveScopedSwitchData::id,
	LSD_Reader::ChunkSaveScopedSwitchData::id,
	"id",
	1,
	0
);
static TypedField<rpg::SaveScopedSwitchData, int32_t> static_scope(
	&rpg::SaveScopedSwitchData::scope,
	LSD_Reader::ChunkSaveScopedSwitchData::scope,
	"scope",
	1,
	0
);
static TypedField<rpg::SaveScopedSwitchData, bool> static_on(
	&rpg::SaveScopedSwitchData::on,
	LSD_Reader::ChunkSaveScopedSwitchData::on,
	"on",
	1,
	0
);
static TypedField<rpg::SaveScopedSwitchData, int32_t> static_map_id(
	&rpg::SaveScopedSwitchData::map_id,
	LSD_Reader::ChunkSaveScopedSwitchData::map_id,
	"map_id",
	1,
	0
);
static TypedField<rpg::SaveScopedSwitchData, int32_t> static_event_id(
	&rpg::SaveScopedSwitchData::event_id,
	LSD_Reader::ChunkSaveScopedSwitchData::event_id,
	"event_id",
	1,
	0
);
static TypedField<rpg::SaveScopedSwitchData, bool> static_auto_reset(
	&rpg::SaveScopedSwitchData::auto_reset,
	LSD_Reader::ChunkSaveScopedSwitchData::auto_reset,
	"auto_reset",
	1,
	0
);


template <>
Field<rpg::SaveScopedSwitchData> const* Struct<rpg::SaveScopedSwitchData>::fields[] = {
	&static_id,
	&static_scope,
	&static_on,
	&static_map_id,
	&static_event_id,
	&static_auto_reset,
	NULL
};

template class Struct<rpg::SaveScopedSwitchData>;

} //namespace lcf
