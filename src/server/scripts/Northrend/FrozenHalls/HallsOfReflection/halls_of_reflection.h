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

enum Data
{
    MAX_ENCOUNTER          = 4,

    DATA_FALRIC_EVENT      = 1,
    DATA_MARWYN_EVENT      = 2,
    DATA_FROSWORN_EVENT    = 3,
    DATA_LICHKING_EVENT    = 4,

    DATA_INTRO_EVENT       = 5,
    DATA_TEAM_IN_INSTANCE  = 6,
    DATA_WAVE_COUNT        = 7,
    DATA_WAVE_STATE       = 8,

    DATA_SUMMONS           = 9,
    DATA_ICE_WALL_1        = 10,
    DATA_ICE_WALL_2        = 11,
    DATA_ICE_WALL_3        = 12,
    DATA_ICE_WALL_4        = 13,

    DATA_PHASE             = 14,
};

enum Data64
{
    DATA_FALRIC            = 101,
    DATA_MARWYN            = 102,
    DATA_LICHKING          = 103,
    DATA_ESCAPE_LIDER      = 104,
    DATA_FROSTMOURNE       = 105,
    DATA_FRONT_DOOR        = 106,
    DATA_FROSTWORN_DOOR    = 107,
    DATA_ARTHAS_DOOR       = 108,
};

enum Creatures
{
    NPC_FALRIC                                    = 38112,
    NPC_MARWYN                                    = 38113,
    NPC_FROSTWORN_GENERAL                         = 36723,
    NPC_REFLECTION                                = 37107,
    NPC_LICH_KING_EVENT                           = 36954,
    NPC_QUELDELAR                                 = 37158,
    BOSS_LICH_KING                                = 37226,

    NPC_UTHER                                     = 37225,
    NPC_JAINA_PART1                               = 37221,
    NPC_JAINA_OUTRO                               = 36955,
    NPC_SYLVANAS_PART1                            = 37223,
    NPC_SYLVANA_OUTRO                             = 37554,
    NPC_BARTLETT                                  = 37182,
    NPC_KORM                                      = 37833,

    NPC_WAVE_MERCENARY                            = 38177,
    NPC_WAVE_FOOTMAN                              = 38173,
    NPC_WAVE_RIFLEMAN                             = 38176,
    NPC_WAVE_PRIEST                               = 38175,
    NPC_WAVE_MAGE                                 = 38172,
    NPC_WAVE_LOOT_DUMMY                           = 37906,

    NPC_ICE_WALL                                  = 37014,
    NPC_RAGING_GNOUL                              = 36940,
    NPC_RISEN_WITCH_DOCTOR                        = 36941,
    NPC_ABON                                      = 37069,

};

enum GameObjects
{
    GO_FROSTMOURNE               = 202302,
    GO_FROSTMOURNE_ALTAR         = 202236,
    GO_FRONT_DOOR                = 201976,
    GO_FROSTWORN_DOOR            = 197341,
    GO_ARTHAS_DOOR               = 197342,
    GO_RUN_DOOR                  = 197343,

    GO_ICE_WALL_1                = 201385,
    GO_ICE_WALL_2                = 201885,
    GO_ICE_WALL_3                = 202396,
    GO_ICE_WALL_4                = 500001,
    GO_CAVE                      = 201596,

    GO_STAIRS_SKYBREAKER         = 201709,
    GO_SKYBREAKER                = 500002,
    GO_STAIRS_ORGRIM_HAMMER      = 202211,
    GO_ORGRIM_HAMMER             = 500003,
    GO_PORTAL                    = 202079,
    GO_CAPTAIN_CHEST_1           = 202212, //3145
    GO_CAPTAIN_CHEST_2           = 201710, //30357
    GO_CAPTAIN_CHEST_3           = 202337, //3246
    GO_CAPTAIN_CHEST_4           = 202336, //3333
};

enum Achievements
{
    ACHIEV_HALLS_OF_REFLECTION_N   = 4518,
    ACHIEV_HALLS_OF_REFLECTION_H   = 4521,
    ACHIEV_NOT_RETREATING_EVENT    = 22615,
    SPELL_ACHIEV_CHECK             = 72830,
};

enum InstanceSpells
{
    SPELL_SPIRIT_SPAWN             = 72630, // Well of Corruption small.
    SPELL_SPIRIT_ACTIVATE_VIS      = 72130, // Visual for Falric/Marwyn trash
    SPELL_CAST_VISUAL              = 65633, // Sylvanas and Jaine use this aparently
    SPELL_BOSS_SPAWN_AURA          = 72712, // Falric, Marwyn and Uther
    SPELL_UTHER_DESPAWN            = 70693, // Todo, makes him invisible, but you're not able to see the visual from it as a player.
    SPELL_TAKE_FROSTMOURNE         = 72729,
    SPELL_FROSTMOURNE_DESPAWN      = 72726,
    SPELL_FROSTMOURNE_VISUAL       = 73220,
    SPELL_FROSTMOURNE_SOUNDS       = 70667,
};

const Position OutroSpawns[2] =
{
    {5564.25f, 2274.69f, 733.01f, 3.93f}, // Lich King
    {5556.27f, 2266.28f, 733.01f, 0.8f},  // Jaina/Sylvana
};

enum HorWorldStates
{
    WORLD_STATE_HOR                               = 4884,
    WORLD_STATE_HOR_WAVE_COUNT                    = 4882,
};

// Common actions from Instance Script to Boss Script
enum Actions
{
    ACTION_ENTER_COMBAT,
    ACTION_TRASH_ACTIVATE,
};


static Position SpawnLoc[]=
{

// Yes I know groups here don't agree with instance_halls, but I can't think of another way of doing it atm.
    // Priests
    {5277.74f, 2016.88f, 707.778f, 5.96903f},
    {5295.88f, 2040.34f, 707.778f, 5.07891f},
    {5320.37f, 1980.13f, 707.778f, 2.00713f},
    {5280.51f, 1997.84f, 707.778f, 0.296706f},
    {5302.45f, 2042.22f, 707.778f, 4.90438f},
    {5306.57f, 1977.47f, 707.778f, 1.50098f},

    // Mage
    {5312.75f, 2037.12f, 707.778f, 4.59022f},
    {5309.58f, 2042.67f, 707.778f, 4.69494f},
    {5275.08f, 2008.72f, 707.778f, 6.21337f},
    {5279.65f, 2004.66f, 707.778f, 0.069813f},
    {5275.48f, 2001.14f, 707.778f, 0.174533f},
    {5316.7f, 2041.55f, 707.778f, 4.50295f},

    // Mercenary
    {5302.25f, 1972.41f, 707.778f, 1.37881f},
    {5311.03f, 1972.23f, 707.778f, 1.64061f},
    {5277.36f, 1993.23f, 707.778f, 0.401426f},
    {5318.7f, 2036.11f, 707.778f, 4.2237f},
    {5335.72f, 1996.86f, 707.778f, 2.74017f},
    {5299.43f, 1979.01f, 707.778f, 1.23918f},

    // Footman
    {5306.06f, 2037, 707.778f, 4.81711f},
    {5344.15f, 2007.17f, 707.778f, 3.15905f},
    {5337.83f, 2010.06f, 707.778f, 3.22886f},
    {5343.29f, 1999.38f, 707.778f, 2.9147f},
    {5340.84f, 1992.46f, 707.778f, 2.75762f},
    {5325.07f, 1977.6f, 707.778f, 2.07694f},
    {5336.6f, 2017.28f, 707.778f, 3.47321f},
    {5313.82f, 1978.15f, 707.778f, 1.74533f},
    {5280.63f, 2012.16f, 707.778f, 6.05629f},
    {5322.96f, 2040.29f, 707.778f, 4.34587f},

    // Rifleman
    {5343.47f, 2015.95f, 707.778f, 3.49066f},
    {5337.86f, 2003.4f, 707.778f, 2.98451f},
    {5319.16f, 1974, 707.778f, 1.91986f},
    {5299.25f, 2036, 707.778f, 5.02655f},
    {5295.64f, 1973.76f, 707.778f, 1.18682f},
    {5282.9f, 2019.6f, 707.778f, 5.88176f},
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
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
        me->SetReactState(REACT_PASSIVE);
    }

    void DamageTaken(Unit* /*who*/, uint32 &uiDamage)
    {
        if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            uiDamage = 0;
    }

    void DoAction(int32 actionID)
    {
        switch (actionID)
        {
            case ACTION_ENTER_COMBAT:  // called by InstanceScript when boss shall enter in combat.
                // Just in case. Should have been done by InstanceScript
                me->SetVisible(true);

                // Reset flags
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_AGGRESSIVE);

                if (Unit* unit = me->SelectNearestTarget())
                    AttackStart(unit);

                DoZoneInCombat();
                break;
        }
    }
};

#endif
