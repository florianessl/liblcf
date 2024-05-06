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
#include "lcf/ldb/reader.h"
#include "lcf/ldb/chunks.h"
#include "reader_struct_impl.h"

namespace lcf {

// Read ScopedSwitch.

template <>
char const* const Struct<rpg::ScopedSwitch>::name = "ScopedSwitch";
static TypedField<rpg::ScopedSwitch, DBString> static_name(
	&rpg::ScopedSwitch::name,
	LDB_Reader::ChunkScopedSwitch::name,
	"name",
	0,
	0
);
static TypedField<rpg::ScopedSwitch, bool> static_default_value(
	&rpg::ScopedSwitch::default_value,
	LDB_Reader::ChunkScopedSwitch::default_value,
	"default_value",
	1,
	0
);
static TypedField<rpg::ScopedSwitch, bool> static_default_value_defined(
	&rpg::ScopedSwitch::default_value_defined,
	LDB_Reader::ChunkScopedSwitch::default_value_defined,
	"default_value_defined",
	1,
	0
);
static TypedField<rpg::ScopedSwitch, bool> static_is_readonly(
	&rpg::ScopedSwitch::is_readonly,
	LDB_Reader::ChunkScopedSwitch::is_readonly,
	"is_readonly",
	1,
	0
);
static TypedField<rpg::ScopedSwitch, bool> static_show_in_editor(
	&rpg::ScopedSwitch::show_in_editor,
	LDB_Reader::ChunkScopedSwitch::show_in_editor,
	"show_in_editor",
	1,
	0
);
static TypedField<rpg::ScopedSwitch, bool> static_auto_reset(
	&rpg::ScopedSwitch::auto_reset,
	LDB_Reader::ChunkScopedSwitch::auto_reset,
	"auto_reset",
	1,
	0
);
static TypedField<rpg::ScopedSwitch, bool> static_map_group_inherited_value(
	&rpg::ScopedSwitch::map_group_inherited_value,
	LDB_Reader::ChunkScopedSwitch::map_group_inherited_value,
	"map_group_inherited_value",
	1,
	0
);


template <>
Field<rpg::ScopedSwitch> const* Struct<rpg::ScopedSwitch>::fields[] = {
	&static_name,
	&static_default_value,
	&static_default_value_defined,
	&static_is_readonly,
	&static_show_in_editor,
	&static_auto_reset,
	&static_map_group_inherited_value,
	NULL
};

template class Struct<rpg::ScopedSwitch>;

} //namespace lcf
