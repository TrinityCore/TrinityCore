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
    DATA_GENERAL_UMBRISS                = 0,
    DATA_FORGEMASTER_THRONGUS           = 1,
    DATA_DRAHGA_SHADOWBURNER            = 2,
    DATA_ERUDAX                         = 3,

    // Encounter Data
    DATA_VALIONA                        = 4,
    DATA_FACELESS_PORTAL_STALKER        = 5,
    DATA_SHADOW_GALE_STALKER            = 6,
    DATA_SHADOW_GALE_CONTROLLER_STALKER = 7,
    DATA_FACELESS_CORRUPTOR_1           = 8,
    DATA_FACELESS_CORRUPTOR_2           = 9
};

enum GBCreatureIds
{
    // Bosses
    BOSS_GENERAL_UMBRISS                = 39625,
    BOSS_FORGEMASTER_THRONGUS           = 40177,
    BOSS_DRAHGA_SHADOWBURNER            = 40319,
    BOSS_ERUDAX                         = 40484,

    // General Umbriss encounter
    NPC_BLITZ_STALKER                   = 40040,
    NPC_GROUND_SIEGE_STALKER            = 40030,
    NPC_MALIGNANT_TROGG                 = 39984,
    NPC_TROGG_DWELLER                   = 45467,

    // Forgemaster Throngus Encounter
    NPC_CAVE_IN_STALKER                 = 40228,
    NPC_FIXATE_STALKER                  = 40255,

    // Drahga Shadowburner Encounter
    NPC_INVOCATION_OF_FLAME_STALKER     = 40355,
    NPC_INVOKED_FLAMING_SPIRIT          = 40357,
    NPC_SEEPING_TWILIGHT                = 40365,
    NPC_DEVOURING_FLAMES                = 48798,
    NPC_VALIONA                         = 40320,

    // Erudax Encounter
    NPC_FACELESS_PORTAL_STALKER         = 44314,
    NPC_ALEXSTRASZAS_EGG                = 40486,
    NPC_SHADOW_GALE_STALKER             = 40567,
    NPC_SHADOW_GALE_CONTROLLER_STALKER  = 40566,
    NPC_FACELESS_CORRUPTOR_1            = 40600,
    NPC_FACELESS_CORRUPTOR_2            = 48844,
    NPC_TWILIGHT_HATCHLING              = 39388,
    NPC_HATCHED_TWILIGHT_EGG            = 40846,

};

enum GBSpells
{
    SPELL_PORTAL_VISUAL = 82847
};

template<class AI>
AI* GetGrimBatolAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, GBScriptName);
}

#define RegisterGrtimBatolCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetGrimBatolAI)

#endif // GRIM_BATOL_H_
