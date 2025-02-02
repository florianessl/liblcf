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

// Read SaveFollowerLocation.

template <>
char const* const Struct<rpg::SaveFollowerLocation>::name = "SaveFollowerLocation";
static TypedField<rpg::SaveFollowerLocation, bool> static_active(
	&rpg::SaveFollowerLocation::active,
	LSD_Reader::ChunkSaveFollowerLocation::active,
	"active",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, int32_t> static_map_id(
	&rpg::SaveFollowerLocation::map_id,
	LSD_Reader::ChunkSaveFollowerLocation::map_id,
	"map_id",
	1,
	0
);
static TypedField<rpg::SaveFollowerLocation, int32_t> static_position_x(
	&rpg::SaveFollowerLocation::position_x,
	LSD_Reader::ChunkSaveFollowerLocation::position_x,
	"position_x",
	1,
	0
);
static TypedField<rpg::SaveFollowerLocation, int32_t> static_position_y(
	&rpg::SaveFollowerLocation::position_y,
	LSD_Reader::ChunkSaveFollowerLocation::position_y,
	"position_y",
	1,
	0
);
static TypedField<rpg::SaveFollowerLocation, int32_t> static_direction(
	&rpg::SaveFollowerLocation::direction,
	LSD_Reader::ChunkSaveFollowerLocation::direction,
	"direction",
	1,
	0
);
static TypedField<rpg::SaveFollowerLocation, int32_t> static_facing(
	&rpg::SaveFollowerLocation::facing,
	LSD_Reader::ChunkSaveFollowerLocation::facing,
	"facing",
	1,
	0
);
static TypedField<rpg::SaveFollowerLocation, int32_t> static_anim_frame(
	&rpg::SaveFollowerLocation::anim_frame,
	LSD_Reader::ChunkSaveFollowerLocation::anim_frame,
	"anim_frame",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, int32_t> static_transparency(
	&rpg::SaveFollowerLocation::transparency,
	LSD_Reader::ChunkSaveFollowerLocation::transparency,
	"transparency",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, int32_t> static_remaining_step(
	&rpg::SaveFollowerLocation::remaining_step,
	LSD_Reader::ChunkSaveFollowerLocation::remaining_step,
	"remaining_step",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, int32_t> static_move_frequency(
	&rpg::SaveFollowerLocation::move_frequency,
	LSD_Reader::ChunkSaveFollowerLocation::move_frequency,
	"move_frequency",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, int32_t> static_layer(
	&rpg::SaveFollowerLocation::layer,
	LSD_Reader::ChunkSaveFollowerLocation::layer,
	"layer",
	1,
	0
);
static TypedField<rpg::SaveFollowerLocation, bool> static_overlap_forbidden(
	&rpg::SaveFollowerLocation::overlap_forbidden,
	LSD_Reader::ChunkSaveFollowerLocation::overlap_forbidden,
	"overlap_forbidden",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, int32_t> static_animation_type(
	&rpg::SaveFollowerLocation::animation_type,
	LSD_Reader::ChunkSaveFollowerLocation::animation_type,
	"animation_type",
	1,
	0
);
static TypedField<rpg::SaveFollowerLocation, bool> static_lock_facing(
	&rpg::SaveFollowerLocation::lock_facing,
	LSD_Reader::ChunkSaveFollowerLocation::lock_facing,
	"lock_facing",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, int32_t> static_move_speed(
	&rpg::SaveFollowerLocation::move_speed,
	LSD_Reader::ChunkSaveFollowerLocation::move_speed,
	"move_speed",
	1,
	0
);
static TypedField<rpg::SaveFollowerLocation, rpg::MoveRoute> static_move_route(
	&rpg::SaveFollowerLocation::move_route,
	LSD_Reader::ChunkSaveFollowerLocation::move_route,
	"move_route",
	1,
	0
);
static TypedField<rpg::SaveFollowerLocation, bool> static_move_route_overwrite(
	&rpg::SaveFollowerLocation::move_route_overwrite,
	LSD_Reader::ChunkSaveFollowerLocation::move_route_overwrite,
	"move_route_overwrite",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, int32_t> static_move_route_index(
	&rpg::SaveFollowerLocation::move_route_index,
	LSD_Reader::ChunkSaveFollowerLocation::move_route_index,
	"move_route_index",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, bool> static_move_route_finished(
	&rpg::SaveFollowerLocation::move_route_finished,
	LSD_Reader::ChunkSaveFollowerLocation::move_route_finished,
	"move_route_finished",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, bool> static_sprite_hidden(
	&rpg::SaveFollowerLocation::sprite_hidden,
	LSD_Reader::ChunkSaveFollowerLocation::sprite_hidden,
	"sprite_hidden",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, bool> static_move_route_through(
	&rpg::SaveFollowerLocation::move_route_through,
	LSD_Reader::ChunkSaveFollowerLocation::move_route_through,
	"move_route_through",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, int32_t> static_anim_paused(
	&rpg::SaveFollowerLocation::anim_paused,
	LSD_Reader::ChunkSaveFollowerLocation::anim_paused,
	"anim_paused",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, bool> static_through(
	&rpg::SaveFollowerLocation::through,
	LSD_Reader::ChunkSaveFollowerLocation::through,
	"through",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, int32_t> static_stop_count(
	&rpg::SaveFollowerLocation::stop_count,
	LSD_Reader::ChunkSaveFollowerLocation::stop_count,
	"stop_count",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, int32_t> static_anim_count(
	&rpg::SaveFollowerLocation::anim_count,
	LSD_Reader::ChunkSaveFollowerLocation::anim_count,
	"anim_count",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, int32_t> static_max_stop_count(
	&rpg::SaveFollowerLocation::max_stop_count,
	LSD_Reader::ChunkSaveFollowerLocation::max_stop_count,
	"max_stop_count",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, bool> static_jumping(
	&rpg::SaveFollowerLocation::jumping,
	LSD_Reader::ChunkSaveFollowerLocation::jumping,
	"jumping",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, int32_t> static_begin_jump_x(
	&rpg::SaveFollowerLocation::begin_jump_x,
	LSD_Reader::ChunkSaveFollowerLocation::begin_jump_x,
	"begin_jump_x",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, int32_t> static_begin_jump_y(
	&rpg::SaveFollowerLocation::begin_jump_y,
	LSD_Reader::ChunkSaveFollowerLocation::begin_jump_y,
	"begin_jump_y",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, bool> static_pause(
	&rpg::SaveFollowerLocation::pause,
	LSD_Reader::ChunkSaveFollowerLocation::pause,
	"pause",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, bool> static_flying(
	&rpg::SaveFollowerLocation::flying,
	LSD_Reader::ChunkSaveFollowerLocation::flying,
	"flying",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, std::string> static_sprite_name(
	&rpg::SaveFollowerLocation::sprite_name,
	LSD_Reader::ChunkSaveFollowerLocation::sprite_name,
	"sprite_name",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, int32_t> static_sprite_id(
	&rpg::SaveFollowerLocation::sprite_id,
	LSD_Reader::ChunkSaveFollowerLocation::sprite_id,
	"sprite_id",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, bool> static_processed(
	&rpg::SaveFollowerLocation::processed,
	LSD_Reader::ChunkSaveFollowerLocation::processed,
	"processed",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, int32_t> static_flash_red(
	&rpg::SaveFollowerLocation::flash_red,
	LSD_Reader::ChunkSaveFollowerLocation::flash_red,
	"flash_red",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, int32_t> static_flash_green(
	&rpg::SaveFollowerLocation::flash_green,
	LSD_Reader::ChunkSaveFollowerLocation::flash_green,
	"flash_green",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, int32_t> static_flash_blue(
	&rpg::SaveFollowerLocation::flash_blue,
	LSD_Reader::ChunkSaveFollowerLocation::flash_blue,
	"flash_blue",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, double> static_flash_current_level(
	&rpg::SaveFollowerLocation::flash_current_level,
	LSD_Reader::ChunkSaveFollowerLocation::flash_current_level,
	"flash_current_level",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, int32_t> static_flash_time_left(
	&rpg::SaveFollowerLocation::flash_time_left,
	LSD_Reader::ChunkSaveFollowerLocation::flash_time_left,
	"flash_time_left",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, int32_t> static_easyrpg_move_failure_count(
	&rpg::SaveFollowerLocation::easyrpg_move_failure_count,
	LSD_Reader::ChunkSaveFollowerLocation::easyrpg_move_failure_count,
	"easyrpg_move_failure_count",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, int32_t> static_follower_id(
	&rpg::SaveFollowerLocation::follower_id,
	LSD_Reader::ChunkSaveFollowerLocation::follower_id,
	"follower_id",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, int32_t> static_actor_id(
	&rpg::SaveFollowerLocation::actor_id,
	LSD_Reader::ChunkSaveFollowerLocation::actor_id,
	"actor_id",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, bool> static_is_init(
	&rpg::SaveFollowerLocation::is_init,
	LSD_Reader::ChunkSaveFollowerLocation::is_init,
	"is_init",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, bool> static_is_frozen(
	&rpg::SaveFollowerLocation::is_frozen,
	LSD_Reader::ChunkSaveFollowerLocation::is_frozen,
	"is_frozen",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, bool> static_auto_sync(
	&rpg::SaveFollowerLocation::auto_sync,
	LSD_Reader::ChunkSaveFollowerLocation::auto_sync,
	"auto_sync",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, bool> static_force_reset(
	&rpg::SaveFollowerLocation::force_reset,
	LSD_Reader::ChunkSaveFollowerLocation::force_reset,
	"force_reset",
	0,
	0
);
static TypedField<rpg::SaveFollowerLocation, bool> static_awaitable(
	&rpg::SaveFollowerLocation::awaitable,
	LSD_Reader::ChunkSaveFollowerLocation::awaitable,
	"awaitable",
	0,
	0
);


template <>
Field<rpg::SaveFollowerLocation> const* Struct<rpg::SaveFollowerLocation>::fields[] = {
	&static_active,
	&static_map_id,
	&static_position_x,
	&static_position_y,
	&static_direction,
	&static_facing,
	&static_anim_frame,
	&static_transparency,
	&static_remaining_step,
	&static_move_frequency,
	&static_layer,
	&static_overlap_forbidden,
	&static_animation_type,
	&static_lock_facing,
	&static_move_speed,
	&static_move_route,
	&static_move_route_overwrite,
	&static_move_route_index,
	&static_move_route_finished,
	&static_sprite_hidden,
	&static_move_route_through,
	&static_anim_paused,
	&static_through,
	&static_stop_count,
	&static_anim_count,
	&static_max_stop_count,
	&static_jumping,
	&static_begin_jump_x,
	&static_begin_jump_y,
	&static_pause,
	&static_flying,
	&static_sprite_name,
	&static_sprite_id,
	&static_processed,
	&static_flash_red,
	&static_flash_green,
	&static_flash_blue,
	&static_flash_current_level,
	&static_flash_time_left,
	&static_easyrpg_move_failure_count,
	&static_follower_id,
	&static_actor_id,
	&static_is_init,
	&static_is_frozen,
	&static_auto_sync,
	&static_force_reset,
	&static_awaitable,
	NULL
};

template class Struct<rpg::SaveFollowerLocation>;

} //namespace lcf
