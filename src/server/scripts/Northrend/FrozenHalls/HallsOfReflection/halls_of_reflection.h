/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#ifndef DEF_HALLS_OF_REFLECTION_H
#define DEF_HALLS_OF_REFLECTION_H

#define HoRScriptName "instance_halls_of_reflection"
#define MAX_ENCOUNTER 3

/* Halls of Reflection encounters:
0- Falric
1- Marwyn
2- The Lich King
*/

enum Data
{
    DATA_FALRIC_EVENT                           = 0,
    DATA_MARWYN_EVENT                           = 1,
    DATA_LICHKING_EVENT                         = 2,
    DATA_INTRO_EVENT                            = 3,
    DATA_FROSWORN_EVENT                         = 4,

    DATA_WAVE_COUNT                             = 5,
    DATA_TEAM_IN_INSTANCE                       = 6,
    DATA_FROSTMOURNE                            = 7,
    DATA_FROSTWORN_DOOR                         = 8,
};

enum Creatures
{
    NPC_JAINA_PART1                               = 37221,
    NPC_SYLVANAS_PART1                            = 37223,
    NPC_UTHER                                     = 37225,
    NPC_LICH_KING_PART1                           = 37226,
    NPC_LORALEN                                   = 37779,
    NPC_KORELN                                    = 37582,

    NPC_FALRIC                                    = 38112,
    NPC_MARWYN                                    = 38113,
    NPC_WAVE_MERCENARY                            = 38177,
    NPC_WAVE_FOOTMAN                              = 38173,
    NPC_WAVE_RIFLEMAN                             = 38176,
    NPC_WAVE_PRIEST                               = 38175,
    NPC_WAVE_MAGE                                 = 38172,

    NPC_FROSTWORN_GENERAL                         = 36723,
    NPC_REFLECTION                                = 37068, // 37107 for tank only?

    NPC_JAINA_PART2                               = 36955,
    NPC_SYLVANAS_PART2                            = 37554,
    NPC_LICH_KING_PART2                           = 36954,
    NPC_BARTLETT                                  = 37182, // High Captain Justin Bartlett
    NPC_KORM                                      = 37833, // Sky-Reaver Korm Blackscar
    NPC_ICE_WALL                                  = 37014, // Ice Wall Target
};

enum GameObjects
{
    GO_FROSTMOURNE                                = 202302,
    GO_ENTRANCE_DOOR                              = 201976,
    GO_FROSTWORN_DOOR                             = 197341,
    GO_ARTHAS_DOOR                                = 197342,
    //GO_ESCAPE_DOOR                                = 197343, // always open ?

    GO_ICE_WALL                                   = 201385,
    GO_CAVE                                       = 201596,

    GO_STAIRS_SKYBREAKER                          = 201709,
    GO_SKYBREAKER                                 = 201598,
    GO_STAIRS_ORGRIM_HAMMER                       = 202211,
    GO_ORGRIM_HAMMER                              = 201599,
    GO_PORTAL                                     = 202079,

    GO_CAPTAIN_CHEST_1                            = 202212, //3145
    GO_CAPTAIN_CHEST_2                            = 201710, //30357
    GO_CAPTAIN_CHEST_3                            = 202337, //3246
    GO_CAPTAIN_CHEST_4                            = 202336, //3333
};

enum HorWorldStates
{
    WORLD_STATE_HOR_WAVES_ENABLED                 = 4884,
    WORLD_STATE_HOR_WAVE_COUNT                    = 4882,
};

// Common actions from Instance Script to Boss Script
enum Actions
{
    ACTION_ENTER_COMBAT,
};

enum TrashGeneralSpells
{
    // General spells
    SPELL_WELL_OF_SOULS                           = 72630, // cast when spawn(become visible)
    SPELL_SPIRIT_ACTIVATE                         = 72130, // cast when unit activates
};

enum InstanceEvents
{
    EVENT_SPAWN_WAVES                             = 1,
    EVENT_NEXT_WAVE                               = 2,
    EVENT_DO_WIPE                                 = 3,
    EVENT_ADD_WAVE                                = 4,
};

// Base class for FALRIC and MARWYN
// handled the summonList and the notification events to/from the InstanceScript
struct boss_horAI : ScriptedAI
{
    boss_horAI(Creature* creature) : ScriptedAI(creature), summons(creature)
    {
        instance = me->GetInstanceScript();
    }

    InstanceScript* instance;
    EventMap events;
    SummonList summons;

    void Reset()
    {
        events.Reset();
        me->SetVisible(false);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC|UNIT_FLAG_IMMUNE_TO_NPC);
        me->SetReactState(REACT_PASSIVE);
        if (instance->GetData(DATA_WAVE_COUNT) != NOT_STARTED)
            instance->ProcessEvent(0, EVENT_DO_WIPE);
    }

    void DoAction(int32 actionID)
    {
        switch (actionID)
        {
            case ACTION_ENTER_COMBAT:  // called by InstanceScript when boss shall enter in combat.
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC|UNIT_FLAG_IMMUNE_TO_NPC);
                me->SetReactState(REACT_AGGRESSIVE);

                if (Unit* unit = me->SelectNearestTarget())
                    AttackStart(unit);

                DoZoneInCombat();
                break;
        }
    }

    void JustSummoned(Creature* summoned)
    {
        summons.Summon(summoned);
    }
};

#endif
