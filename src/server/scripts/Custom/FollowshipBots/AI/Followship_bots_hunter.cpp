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

#include "CharmInfo.h"
#include "CreatureData.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "Pet.h"
#include "PhasingHandler.h"

#include "Followship_bots_mgr.h"
#include "Followship_bots_utils.h"

#include "Followship_bots_pet_handler.h"
#include "Followship_bots_spells_handler.h"

std::vector<FSBSpellDefinition> HunterSpellsTable =
{
    // Spell ID                             Spell Type              ManaCost %  HP % for heal   Chance           Dist/Range     SelfCast    Cooldown Ms     RoleMask

    // ANY
    { SPELL_HUMAN_WILL_TO_SURVIVE,          FSBSpellType::Heal,     0.f,        80.f,           100.f,           0.f,           true,       180000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_DWARF_STONEFORM,                FSBSpellType::Heal,     0.f,        80.f,           100.f,           0.f,           true,       120000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_DRAENEI_GIFT_NAARU,             FSBSpellType::Heal,     0.f,        50.f,           100.f,           30.f,          false,      120000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_PANDAREN_QUAKING_PALM,          FSBSpellType::Damage,   0.f,        0.f,            100.f,           2.f,           false,      120000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_ORC_BLOOD_FURY,                 FSBSpellType::Damage,   0.f,        0.f,            100.f,           0.f,           true,       120000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_UNDEAD_WILL_OF_FORSAKEN,        FSBSpellType::Heal,     0.f,        80.f,           100.f,           0.f,           true,        30000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_TAUREN_WAR_STOMP,               FSBSpellType::Damage,   0.f,        0.f,            100.f,           8.f,           false,       90000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_TROLL_BERSERKING,               FSBSpellType::Damage,   0.f,        0.f,            100.f,           0.f,           true,       180000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_BLOODELF_ARCANE_TORRENT,        FSBSpellType::Damage,   0.f,        0.f,            100.f,           8.f,           false,      120000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_GOBLIN_ROCKET_BARRAGE,          FSBSpellType::Damage,   0.f,        0.f,            100.f,          30.f,           false,       90000,         FSB_RoleMask::FSB_ROLEMASK_ANY },

    { SPELL_HUNTER_EXHILARATION,            FSBSpellType::Heal,     0.f,        60.f,           100.f,           0.f,           true,       120000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_HUNTER_MEND_PET,                FSBSpellType::Heal,     0.f,        100.f,          100.f,           0.f,           true,       10000,          FSB_RoleMask::FSB_ROLEMASK_ANY },

    { SPELL_HUNTER_MARK,                    FSBSpellType::Damage,   0.f,        0.f,            100.f,           60.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_HUNTER_WING_CLIP,               FSBSpellType::Damage,   0.f,        0.f,            100.f,           40.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_HUNTER_SCARE_BEAST,             FSBSpellType::Damage,   0.f,        0.f,            100.f,           30.f,          false,      20000,          FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_HUNTER_DISENGAGE,               FSBSpellType::Damage,   0.f,        0.f,            100.f,           40.f,          true,       20000,          FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_HUNTER_COUNTER_SHOT,            FSBSpellType::Damage,   0.f,        0.f,            100.f,           40.f,          false,      24000,          FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_HUNTER_BINDING_SHOT,            FSBSpellType::Damage,   0.f,        0.f,            100.f,           30.f,          false,      45000,          FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_HUNTER_ASPECT_TURTLE,           FSBSpellType::Damage,   0.f,        0.f,            50.f,            0.f,           true,       180000,         FSB_RoleMask::FSB_ROLEMASK_ANY },

    { SPELL_HUNTER_SHOOT,                   FSBSpellType::Damage,   0.f,        0.f,            50.f,            40.f,          false,      1500,           FSB_RoleMask::FSB_ROLEMASK_ANY },

    { SPELL_HUNTER_ARCANE_SHOT,             FSBSpellType::Damage,   0.f,        0.f,            80.f,            40.f,          false,      1500,           FSB_RoleMask::FSB_ROLEMASK_ANY },

    { SPELL_HUNTER_STEADY_SHOT,             FSBSpellType::Damage,   0.f,        0.f,            50.f,            40.f,          false,      1500,           FSB_RoleMask::FSB_ROLEMASK_ANY },

    //BEAST
    { SPELL_HUNTER_BESTIAL_WRATH,           FSBSpellType::Damage,   0.f,        0.f,            100.f,           0.f,           true,       90000,          FSB_RoleMask::FSB_ROLEMASK_ASSIST },
    { SPELL_HUNTER_KILL_COMMAND,            FSBSpellType::Damage,   0.3f,       0.f,            100.f,           0.f,           false,      8000,           FSB_RoleMask::FSB_ROLEMASK_ASSIST },
    { SPELL_HUNTER_FLAMEFANG_PITCH,         FSBSpellType::Damage,   0.f,        0.f,            80.f,            40.f,          false,      60000,          FSB_RoleMask::FSB_ROLEMASK_ASSIST },
    { SPELL_HUNTER_WILDFIRE_BOMB,           FSBSpellType::Damage,   0.f,        0.f,            80.f,            40.f,          false,      18000,          FSB_RoleMask::FSB_ROLEMASK_ASSIST },
    { SPELL_HUNTER_COBRA_SHOT,              FSBSpellType::Damage,   0.f,        0.f,            80.f,            40.f,          false,      1500,           FSB_RoleMask::FSB_ROLEMASK_ASSIST },

    { SPELL_HUNTER_RAPTOR_STRIKE,           FSBSpellType::Damage,   0.f,        0.f,            70.f,            40.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_ASSIST },
    { SPELL_HUNTER_MONGOOSE_BITE,           FSBSpellType::Damage,   0.f,        0.f,            70.f,            40.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_ASSIST },

    { SPELL_HUNTER_BARBED_SHOT,             FSBSpellType::Damage,   0.f,        0.f,            50.f,            40.f,          false,      18000,          FSB_RoleMask::FSB_ROLEMASK_ASSIST },

    //MARK
    { SPELL_HUNTER_SERPENT_STING,           FSBSpellType::Damage,   0.f,        0.f,            100.f,           40.f,          false,      1500,           FSB_RoleMask::FSB_ROLEMASK_RANGED_DAMAGE },
    { SPELL_HUNTER_CONCUSSIVE_SHOT,         FSBSpellType::Damage,   0.f,        0.f,            100.f,           40.f,          false,      5000,           FSB_RoleMask::FSB_ROLEMASK_RANGED_DAMAGE },
    { SPELL_HUNTER_TRANQUILIZING_SHOT,      FSBSpellType::Damage,   0.f,        0.f,            100.f,           40.f,          false,      10000,          FSB_RoleMask::FSB_ROLEMASK_RANGED_DAMAGE },
    { SPELL_HUNTER_SCATTER_SHOT,            FSBSpellType::Damage,   0.f,        0.f,            100.f,           20.f,          false,      30000,          FSB_RoleMask::FSB_ROLEMASK_RANGED_DAMAGE },
    { SPELL_HUNTER_WAILLING_ARROW,          FSBSpellType::Damage,   0.f,        0.f,            80.f,            40.f,          false,      60000,          FSB_RoleMask::FSB_ROLEMASK_RANGED_DAMAGE },
    { SPELL_HUNTER_AIMED_SHOT,              FSBSpellType::Damage,   0.f,        0.f,            80.f,            40.f,          false,      15000,          FSB_RoleMask::FSB_ROLEMASK_RANGED_DAMAGE },
    { SPELL_HUNTER_MULTI_SHOT,              FSBSpellType::Damage,   0.f,        0.f,            80.f,            40.f,          false,      1500,           FSB_RoleMask::FSB_ROLEMASK_RANGED_DAMAGE },

    { SPELL_HUNTER_RAPID_FIRE,              FSBSpellType::Damage,   0.f,        0.f,            50.f,            40.f,          false,      16000,          FSB_RoleMask::FSB_ROLEMASK_RANGED_DAMAGE },
    
};

namespace FSBHunter
{

}
