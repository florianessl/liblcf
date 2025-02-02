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
static TypedField<rpg::SaveEasyRpgData, bool> static_followers_enabled(
	&rpg::SaveEasyRpgData::followers_enabled,
	LSD_Reader::ChunkSaveEasyRpgData::followers_enabled,
	"followers_enabled",
	0,
	0
);
static TypedField<rpg::SaveEasyRpgData, bool> static_followers_frozen(
	&rpg::SaveEasyRpgData::followers_frozen,
	LSD_Reader::ChunkSaveEasyRpgData::followers_frozen,
	"followers_frozen",
	0,
	0
);
static TypedField<rpg::SaveEasyRpgData, bool> static_followers_auto_sync(
	&rpg::SaveEasyRpgData::followers_auto_sync,
	LSD_Reader::ChunkSaveEasyRpgData::followers_auto_sync,
	"followers_auto_sync",
	0,
	0
);
static TypedField<rpg::SaveEasyRpgData, bool> static_followers_awaitable(
	&rpg::SaveEasyRpgData::followers_awaitable,
	LSD_Reader::ChunkSaveEasyRpgData::followers_awaitable,
	"followers_awaitable",
	0,
	0
);
static TypedField<rpg::SaveEasyRpgData, rpg::SaveFollowerLocation> static_follower1(
	&rpg::SaveEasyRpgData::follower1,
	LSD_Reader::ChunkSaveEasyRpgData::follower1,
	"follower1",
	1,
	0
);
static TypedField<rpg::SaveEasyRpgData, rpg::SaveFollowerLocation> static_follower2(
	&rpg::SaveEasyRpgData::follower2,
	LSD_Reader::ChunkSaveEasyRpgData::follower2,
	"follower2",
	1,
	0
);
static TypedField<rpg::SaveEasyRpgData, rpg::SaveFollowerLocation> static_follower3(
	&rpg::SaveEasyRpgData::follower3,
	LSD_Reader::ChunkSaveEasyRpgData::follower3,
	"follower3",
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
	&static_followers_enabled,
	&static_followers_frozen,
	&static_followers_auto_sync,
	&static_followers_awaitable,
	&static_follower1,
	&static_follower2,
	&static_follower3,
	&static_windows,
	NULL
};

template class Struct<rpg::SaveEasyRpgData>;

} //namespace lcf
