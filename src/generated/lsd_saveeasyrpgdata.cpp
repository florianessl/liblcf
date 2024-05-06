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

// Read SaveEasyRpgData.

template <>
char const* const Struct<rpg::SaveEasyRpgData>::name = "SaveEasyRpgData";
static TypedField<rpg::SaveEasyRpgData, int32_t> static_version(
	&rpg::SaveEasyRpgData::version,
	LSD_Reader::ChunkSaveEasyRpgData::version,
	"version",
	0,
	0
);
static TypedField<rpg::SaveEasyRpgData, int32_t> static_codepage(
	&rpg::SaveEasyRpgData::codepage,
	LSD_Reader::ChunkSaveEasyRpgData::codepage,
	"codepage",
	0,
	0
);
static TypedField<rpg::SaveEasyRpgData, std::vector<rpg::SaveScopedSwitchData>> static_scoped_switches(
	&rpg::SaveEasyRpgData::scoped_switches,
	LSD_Reader::ChunkSaveEasyRpgData::scoped_switches,
	"scoped_switches",
	0,
	0
);
static TypedField<rpg::SaveEasyRpgData, std::vector<rpg::SaveScopedVariableData>> static_scoped_variables(
	&rpg::SaveEasyRpgData::scoped_variables,
	LSD_Reader::ChunkSaveEasyRpgData::scoped_variables,
	"scoped_variables",
	0,
	0
);
static CountField<rpg::SaveEasyRpgData, std::vector<bool>> static_size_frame_main_switches(
	&rpg::SaveEasyRpgData::frame_main_switches,
	LSD_Reader::ChunkSaveEasyRpgData::frame_main_switches_size,
	0,
	0
);
static TypedField<rpg::SaveEasyRpgData, std::vector<bool>> static_frame_main_switches(
	&rpg::SaveEasyRpgData::frame_main_switches,
	LSD_Reader::ChunkSaveEasyRpgData::frame_main_switches,
	"frame_main_switches",
	1,
	0
);
static CountField<rpg::SaveEasyRpgData, std::vector<bool>> static_size_frame_parallel_switches(
	&rpg::SaveEasyRpgData::frame_parallel_switches,
	LSD_Reader::ChunkSaveEasyRpgData::frame_parallel_switches_size,
	0,
	0
);
static TypedField<rpg::SaveEasyRpgData, std::vector<bool>> static_frame_parallel_switches(
	&rpg::SaveEasyRpgData::frame_parallel_switches,
	LSD_Reader::ChunkSaveEasyRpgData::frame_parallel_switches,
	"frame_parallel_switches",
	1,
	0
);
static CountField<rpg::SaveEasyRpgData, std::vector<int32_t>> static_size_frame_main_variables(
	&rpg::SaveEasyRpgData::frame_main_variables,
	LSD_Reader::ChunkSaveEasyRpgData::frame_main_variables_size,
	0,
	0
);
static TypedField<rpg::SaveEasyRpgData, std::vector<int32_t>> static_frame_main_variables(
	&rpg::SaveEasyRpgData::frame_main_variables,
	LSD_Reader::ChunkSaveEasyRpgData::frame_main_variables,
	"frame_main_variables",
	1,
	0
);
static CountField<rpg::SaveEasyRpgData, std::vector<int32_t>> static_size_frame_parallel_variables(
	&rpg::SaveEasyRpgData::frame_parallel_variables,
	LSD_Reader::ChunkSaveEasyRpgData::frame_parallel_variables_size,
	0,
	0
);
static TypedField<rpg::SaveEasyRpgData, std::vector<int32_t>> static_frame_parallel_variables(
	&rpg::SaveEasyRpgData::frame_parallel_variables,
	LSD_Reader::ChunkSaveEasyRpgData::frame_parallel_variables,
	"frame_parallel_variables",
	1,
	0
);
static TypedField<rpg::SaveEasyRpgData, std::vector<rpg::SaveEasyRpgWindow>> static_windows(
	&rpg::SaveEasyRpgData::windows,
	LSD_Reader::ChunkSaveEasyRpgData::windows,
	"windows",
	0,
	0
);


template <>
Field<rpg::SaveEasyRpgData> const* Struct<rpg::SaveEasyRpgData>::fields[] = {
	&static_version,
	&static_codepage,
	&static_scoped_switches,
	&static_scoped_variables,
	&static_size_frame_main_switches,
	&static_frame_main_switches,
	&static_size_frame_parallel_switches,
	&static_frame_parallel_switches,
	&static_size_frame_main_variables,
	&static_frame_main_variables,
	&static_size_frame_parallel_variables,
	&static_frame_parallel_variables,
	&static_windows,
	NULL
};

template class Struct<rpg::SaveEasyRpgData>;

} //namespace lcf
