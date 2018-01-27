/*
* Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef GRIM_BATOL_H_
#define GRIM_BATOL_H_

#define GBScriptName "instance_grim_batol"
#define DataHeader   "GB"

uint32 const EncounterCount = 5;

enum GBDataTypes
{
    // Encounter States
    DATA_GENERAL_UMBRISS        = 0,
    DATA_FORGEMASTER_THRONGUS   = 1,
    DATA_DRAHGA_SHADOWBURNER    = 2,
    DATA_ERUDAX                 = 3
};

enum GBCreatureIds
{
    // Bosses
    BOSS_GENERAL_UMBRISS        = 39625,
    BOSS_FORGEMASTER_THRONGUS   = 40177,
    BOSS_DRAHGA_SHADOWBURNER    = 40319,
    BOSS_ERUDAX                 = 40484,

    // General Umbriss encounter
    NPC_BLITZ_STALKER           = 40040,
    NPC_GROUND_SIEGE_STALKER    = 40030,
    NPC_MALIGNANT_TROGG         = 39984,
    NPC_TROGG_DWELLER           = 45467,

    // Forgemaster Throngus Encounter
    NPC_CAVE_IN_STALKER         = 40228,
    NPC_FIXATE_STALKER          = 40255,
};

template<class AI>
AI* GetGrimBatolAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, GBScriptName);
}

#endif // GRIM_BATOL_H_
