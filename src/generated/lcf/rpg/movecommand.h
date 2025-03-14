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

#ifndef LCF_RPG_MOVECOMMAND_H
#define LCF_RPG_MOVECOMMAND_H

// Headers
#include <stdint.h>
#include "lcf/dbstring.h"
#include "lcf/enum_tags.h"
#include "lcf/context.h"
#include <ostream>
#include <type_traits>

/**
 * rpg::MoveCommand class.
 */
namespace lcf {
namespace rpg {
	class MoveCommand {
	public:
		enum class Code {
			move_up = 0,
			move_right = 1,
			move_down = 2,
			move_left = 3,
			move_upright = 4,
			move_downright = 5,
			move_downleft = 6,
			move_upleft = 7,
			move_random = 8,
			move_towards_hero = 9,
			move_away_from_hero = 10,
			move_forward = 11,
			face_up = 12,
			face_right = 13,
			face_down = 14,
			face_left = 15,
			turn_90_degree_right = 16,
			turn_90_degree_left = 17,
			turn_180_degree = 18,
			turn_90_degree_random = 19,
			face_random_direction = 20,
			face_hero = 21,
			face_away_from_hero = 22,
			wait = 23,
			begin_jump = 24,
			end_jump = 25,
			lock_facing = 26,
			unlock_facing = 27,
			increase_movement_speed = 28,
			decrease_movement_speed = 29,
			increase_movement_frequence = 30,
			decrease_movement_frequence = 31,
			switch_on = 32,
			switch_off = 33,
			change_graphic = 34,
			play_sound_effect = 35,
			walk_everywhere_on = 36,
			walk_everywhere_off = 37,
			stop_animation = 38,
			start_animation = 39,
			increase_transp = 40,
			decrease_transp = 41,
			EasyRpg_SetMoveSpeed = 200,
			EasyRpg_SetMoveFrequency = 201,
			EasyRpg_SetTransparency = 202,
			EasyRpg_SetLayer = 203,
			EasyRpg_SetFlying = 204,
			EasyRpg_WaitFixed = 205,
			EasyRpg_WaitFrame = 206,
			EasyRpg_SetFlipped = 207,
			EasyRpg_ShakeOnce = 208,
			EasyRpg_ShakeBegin = 209,
			EasyRpg_ShakeEnd = 210,
			EasyRpg_CloneEventGraphic = 211,
			EasyRpg_CloneActorGraphic = 212,
			EasyRpg_ClearGraphic = 213,
			EasyRpg_RevertGraphic = 214,
			EasyRpg_SetFixedGraphic = 220,
			EasyRpg_IncrementFixedGraphic_i = 221,
			EasyRpg_DecrementFixedGraphic_i = 222,
			EasyRpg_IncrementFixedGraphic_x = 223,
			EasyRpg_IncrementFixedGraphic_y = 224,
			EasyRpg_DecrementFixedGraphic_x = 225,
			EasyRpg_DecrementFixedGraphic_y = 226
		};
		static constexpr auto kCodeTags = lcf::EnumTags{
			Code::move_up, "move_up",
			Code::move_right, "move_right",
			Code::move_down, "move_down",
			Code::move_left, "move_left",
			Code::move_upright, "move_upright",
			Code::move_downright, "move_downright",
			Code::move_downleft, "move_downleft",
			Code::move_upleft, "move_upleft",
			Code::move_random, "move_random",
			Code::move_towards_hero, "move_towards_hero",
			Code::move_away_from_hero, "move_away_from_hero",
			Code::move_forward, "move_forward",
			Code::face_up, "face_up",
			Code::face_right, "face_right",
			Code::face_down, "face_down",
			Code::face_left, "face_left",
			Code::turn_90_degree_right, "turn_90_degree_right",
			Code::turn_90_degree_left, "turn_90_degree_left",
			Code::turn_180_degree, "turn_180_degree",
			Code::turn_90_degree_random, "turn_90_degree_random",
			Code::face_random_direction, "face_random_direction",
			Code::face_hero, "face_hero",
			Code::face_away_from_hero, "face_away_from_hero",
			Code::wait, "wait",
			Code::begin_jump, "begin_jump",
			Code::end_jump, "end_jump",
			Code::lock_facing, "lock_facing",
			Code::unlock_facing, "unlock_facing",
			Code::increase_movement_speed, "increase_movement_speed",
			Code::decrease_movement_speed, "decrease_movement_speed",
			Code::increase_movement_frequence, "increase_movement_frequence",
			Code::decrease_movement_frequence, "decrease_movement_frequence",
			Code::switch_on, "switch_on",
			Code::switch_off, "switch_off",
			Code::change_graphic, "change_graphic",
			Code::play_sound_effect, "play_sound_effect",
			Code::walk_everywhere_on, "walk_everywhere_on",
			Code::walk_everywhere_off, "walk_everywhere_off",
			Code::stop_animation, "stop_animation",
			Code::start_animation, "start_animation",
			Code::increase_transp, "increase_transp",
			Code::decrease_transp, "decrease_transp",
			Code::EasyRpg_SetMoveSpeed, "EasyRpg_SetMoveSpeed",
			Code::EasyRpg_SetMoveFrequency, "EasyRpg_SetMoveFrequency",
			Code::EasyRpg_SetTransparency, "EasyRpg_SetTransparency",
			Code::EasyRpg_SetLayer, "EasyRpg_SetLayer",
			Code::EasyRpg_SetFlying, "EasyRpg_SetFlying",
			Code::EasyRpg_WaitFixed, "EasyRpg_WaitFixed",
			Code::EasyRpg_WaitFrame, "EasyRpg_WaitFrame",
			Code::EasyRpg_SetFlipped, "EasyRpg_SetFlipped",
			Code::EasyRpg_ShakeOnce, "EasyRpg_ShakeOnce",
			Code::EasyRpg_ShakeBegin, "EasyRpg_ShakeBegin",
			Code::EasyRpg_ShakeEnd, "EasyRpg_ShakeEnd",
			Code::EasyRpg_CloneEventGraphic, "EasyRpg_CloneEventGraphic",
			Code::EasyRpg_CloneActorGraphic, "EasyRpg_CloneActorGraphic",
			Code::EasyRpg_ClearGraphic, "EasyRpg_ClearGraphic",
			Code::EasyRpg_RevertGraphic, "EasyRpg_RevertGraphic",
			Code::EasyRpg_SetFixedGraphic, "EasyRpg_SetFixedGraphic",
			Code::EasyRpg_IncrementFixedGraphic_i, "EasyRpg_IncrementFixedGraphic_i",
			Code::EasyRpg_DecrementFixedGraphic_i, "EasyRpg_DecrementFixedGraphic_i",
			Code::EasyRpg_IncrementFixedGraphic_x, "EasyRpg_IncrementFixedGraphic_x",
			Code::EasyRpg_IncrementFixedGraphic_y, "EasyRpg_IncrementFixedGraphic_y",
			Code::EasyRpg_DecrementFixedGraphic_x, "EasyRpg_DecrementFixedGraphic_x",
			Code::EasyRpg_DecrementFixedGraphic_y, "EasyRpg_DecrementFixedGraphic_y"
		};

		int32_t command_id = 0;
		DBString parameter_string;
		int32_t parameter_a = 0;
		int32_t parameter_b = 0;
		int32_t parameter_c = 0;
	};
	inline std::ostream& operator<<(std::ostream& os, MoveCommand::Code code) {
		os << static_cast<std::underlying_type_t<decltype(code)>>(code);
		return os;
	}

	inline bool operator==(const MoveCommand& l, const MoveCommand& r) {
		return l.command_id == r.command_id
		&& l.parameter_string == r.parameter_string
		&& l.parameter_a == r.parameter_a
		&& l.parameter_b == r.parameter_b
		&& l.parameter_c == r.parameter_c;
	}

	inline bool operator!=(const MoveCommand& l, const MoveCommand& r) {
		return !(l == r);
	}

	std::ostream& operator<<(std::ostream& os, const MoveCommand& obj);

	template <typename F, typename ParentCtx = Context<void,void>>
	void ForEachString(MoveCommand& obj, const F& f, const ParentCtx* parent_ctx = nullptr) {
		const auto ctx2 = Context<MoveCommand, ParentCtx>{ "parameter_string", -1, &obj, parent_ctx };
		f(obj.parameter_string, ctx2);
		(void)obj;
		(void)f;
		(void)parent_ctx;
	}

} // namespace rpg
} // namespace lcf

#endif
