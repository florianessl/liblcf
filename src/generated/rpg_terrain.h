/* !!!! GENERATED FILE - DO NOT EDIT !!!!
 * --------------------------------------
 *
 * This file is part of liblcf. Copyright (c) 2017 liblcf authors.
 * https://github.com/EasyRPG/liblcf - https://easyrpg.org
 *
 * liblcf is Free/Libre Open Source Software, released under the MIT License.
 * For the full copyright and license information, please view the COPYING
 * file that was distributed with this source code.
 */

#ifndef LCF_RPG_TERRAIN_H
#define LCF_RPG_TERRAIN_H

// Headers
#include <stdint.h>
#include <string>
#include "rpg_sound.h"

/**
 * RPG::Terrain class.
 */
namespace RPG {
	class Terrain {
	public:
		enum BushDepth {
			BushDepth_normal = 0,
			BushDepth_third = 1,
			BushDepth_half = 2,
			BushDepth_full = 3
		};
		enum BGAssociation {
			BGAssociation_background = 0,
			BGAssociation_frame = 1
		};

		int ID = 0;
		std::string name;
		int32_t damage = 0;
		int32_t encounter_rate = 100;
		std::string background_name;
		bool boat_pass = false;
		bool ship_pass = false;
		bool airship_pass = true;
		bool airship_land = true;
		int32_t bush_depth = 0;
		Sound footstep;
		bool on_damage_se = false;
		int32_t background_type = 0;
		std::string background_a_name;
		bool background_a_scrollh = false;
		bool background_a_scrollv = false;
		int32_t background_a_scrollh_speed = 0;
		int32_t background_a_scrollv_speed = 0;
		bool background_b = false;
		std::string background_b_name;
		bool background_b_scrollh = false;
		bool background_b_scrollv = false;
		int32_t background_b_scrollh_speed = 0;
		int32_t background_b_scrollv_speed = 0;
		struct Flags {
			bool back_party = false;
			bool back_enemies = false;
			bool lateral_party = false;
			bool lateral_enemies = false;
		} special_flags;
		int32_t special_back_party = 15;
		int32_t special_back_enemies = 10;
		int32_t special_lateral_party = 10;
		int32_t special_lateral_enemies = 5;
		int32_t grid_location = 0;
		int32_t grid_a = 0;
		int32_t grid_b = 0;
		int32_t grid_c = 0;
	};
}

#endif
