/*
 * This file is part of the Stefal WoW Project.
 * It is designed to work exclusively with the TrinityCore framework.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * This code is provided for personal and educational use within the
 * Stefal WoW Project. It is not intended for commercial distribution,
 * resale, or any form of monetization.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once


extern std::vector<FSBSpellDefinition> HunterSpellsTable;

enum FSB_HUNTER_PET_SPELLS
{
    SPELL_HUNTER_SUMMON_HYENA = 117782,
    SPELL_HUNTER_SUMMON_ICEGAZER = 143601,
    SPELL_HUNTER_SUMMON_SKYTERROR = 178622,

    SPELL_HUNTER_MEND_PET = 136, //self
};

enum FSB_HUNTER_RANGED_SPELLS
{
    SPELL_HUNTER_SHOOT = 22411,

    SPELL_HUNTER_MARK = 257284, //0s, 60f
    SPELL_HUNTER_DISENGAGE = 781, //20s //ANY
    SPELL_HUNTER_WING_CLIP = 195645, //0s ANY
    SPELL_HUNTER_SCARE_BEAST = 1513, //20s, 30f //ANY

    SPELL_HUNTER_BINDING_SHOT = 109248, //45s, 30f //ANY
    SPELL_HUNTER_COUNTER_SHOT = 147362, //24s, 40f //ANY
    SPELL_HUNTER_SERPENT_STING = 259491, //40f //MARK
    SPELL_HUNTER_CONCUSSIVE_SHOT = 5116, //5s, 40f //MARK
    SPELL_HUNTER_TRANQUILIZING_SHOT = 19801, //10s, 40f, //MARK
    SPELL_HUNTER_SCATTER_SHOT = 213691, //30s, 20f //MARK

    

    // Generate Focus
    SPELL_HUNTER_STEADY_SHOT = 56641,
    SPELL_HUNTER_BARBED_SHOT = 217200, // 18s
    SPELL_HUNTER_RAPID_FIRE = 257044, //16s //MARK

    // Use focus
    SPELL_HUNTER_COBRA_SHOT = 193455, //40f //BEAST
    SPELL_HUNTER_AIMED_SHOT = 19434, //15s, 40f //MARK
    SPELL_HUNTER_ARCANE_SHOT = 185358, //40f //ANY
    SPELL_HUNTER_MULTI_SHOT = 257620, //40f //MARK
    SPELL_HUNTER_WAILLING_ARROW = 355589, //1m, 40f //MARK

    SPELL_HUNTER_RAPTOR_STRIKE = 186270, //BEAST
    SPELL_HUNTER_MONGOOSE_BITE = 259387, //BEAST

    SPELL_HUNTER_KILL_COMMAND = 34026, //8s, 50f, 30focus
    SPELL_HUNTER_WILDFIRE_BOMB = 259495, //18s, 40f, //BEAST
    SPELL_HUNTER_FLAMEFANG_PITCH = 1251592, //1m, 40f //BEAST

    //Powerups
    SPELL_HUNTER_BESTIAL_WRATH = 19574, //1.5m, 100f //BEAST
    SPELL_HUNTER_ASPECT_TURTLE = 186265, //3m //ANY
    // Heal self
    SPELL_HUNTER_EXHILARATION = 109304, //2m ANY
};

namespace FSBHunter
{
    
}
