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

// Read ScopedVariable.

template <>
char const* const Struct<rpg::ScopedVariable>::name = "ScopedVariable";
static TypedField<rpg::ScopedVariable, DBString> static_name(
	&rpg::ScopedVariable::name,
	LDB_Reader::ChunkScopedVariable::name,
	"name",
	0,
	0
);
static TypedField<rpg::ScopedVariable, int32_t> static_default_value(
	&rpg::ScopedVariable::default_value,
	LDB_Reader::ChunkScopedVariable::default_value,
	"default_value",
	1,
	0
);
static TypedField<rpg::ScopedVariable, bool> static_default_value_defined(
	&rpg::ScopedVariable::default_value_defined,
	LDB_Reader::ChunkScopedVariable::default_value_defined,
	"default_value_defined",
	1,
	0
);
static TypedField<rpg::ScopedVariable, bool> static_is_readonly(
	&rpg::ScopedVariable::is_readonly,
	LDB_Reader::ChunkScopedVariable::is_readonly,
	"is_readonly",
	1,
	0
);
static TypedField<rpg::ScopedVariable, bool> static_show_in_editor(
	&rpg::ScopedVariable::show_in_editor,
	LDB_Reader::ChunkScopedVariable::show_in_editor,
	"show_in_editor",
	1,
	0
);
static TypedField<rpg::ScopedVariable, bool> static_auto_reset(
	&rpg::ScopedVariable::auto_reset,
	LDB_Reader::ChunkScopedVariable::auto_reset,
	"auto_reset",
	1,
	0
);
static TypedField<rpg::ScopedVariable, bool> static_map_group_inherited_value(
	&rpg::ScopedVariable::map_group_inherited_value,
	LDB_Reader::ChunkScopedVariable::map_group_inherited_value,
	"map_group_inherited_value",
	1,
	0
);


template <>
Field<rpg::ScopedVariable> const* Struct<rpg::ScopedVariable>::fields[] = {
	&static_name,
	&static_default_value,
	&static_default_value_defined,
	&static_is_readonly,
	&static_show_in_editor,
	&static_auto_reset,
	&static_map_group_inherited_value,
	NULL
};

template class Struct<rpg::ScopedVariable>;

} //namespace lcf
