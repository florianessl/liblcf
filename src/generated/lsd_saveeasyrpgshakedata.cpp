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

// Read SaveEasyRpgShakeData.

template <>
char const* const Struct<rpg::SaveEasyRpgShakeData>::name = "SaveEasyRpgShakeData";
static TypedField<rpg::SaveEasyRpgShakeData, bool> static_continuous(
	&rpg::SaveEasyRpgShakeData::continuous,
	LSD_Reader::ChunkSaveEasyRpgShakeData::continuous,
	"continuous",
	0,
	0
);
static TypedField<rpg::SaveEasyRpgShakeData, int32_t> static_strength(
	&rpg::SaveEasyRpgShakeData::strength,
	LSD_Reader::ChunkSaveEasyRpgShakeData::strength,
	"strength",
	0,
	0
);
static TypedField<rpg::SaveEasyRpgShakeData, int32_t> static_speed(
	&rpg::SaveEasyRpgShakeData::speed,
	LSD_Reader::ChunkSaveEasyRpgShakeData::speed,
	"speed",
	0,
	0
);
static TypedField<rpg::SaveEasyRpgShakeData, int32_t> static_position(
	&rpg::SaveEasyRpgShakeData::position,
	LSD_Reader::ChunkSaveEasyRpgShakeData::position,
	"position",
	0,
	0
);
static TypedField<rpg::SaveEasyRpgShakeData, int32_t> static_time_left(
	&rpg::SaveEasyRpgShakeData::time_left,
	LSD_Reader::ChunkSaveEasyRpgShakeData::time_left,
	"time_left",
	0,
	0
);


template <>
Field<rpg::SaveEasyRpgShakeData> const* Struct<rpg::SaveEasyRpgShakeData>::fields[] = {
	&static_continuous,
	&static_strength,
	&static_speed,
	&static_position,
	&static_time_left,
	NULL
};

template class Struct<rpg::SaveEasyRpgShakeData>;

} //namespace lcf
