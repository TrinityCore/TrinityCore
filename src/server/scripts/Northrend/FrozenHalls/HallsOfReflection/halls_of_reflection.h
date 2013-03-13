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
    DATA_BEGIN_EVENT,
    DATA_FALRIC_EVENT,
    DATA_MARWYN_EVENT,
    DATA_FROSTSWORN_EVENT,
    DATA_LICHKING_EVENT,
    DATA_WAVE_COUNT,
    DATA_WAVES_BEGIN,
    DATA_TEAM_IN_INSTANCE,
    DATA_ICE_WALL_1,
    DATA_ICE_WALL_2,
    DATA_ICE_WALL_3,
    DATA_ICE_WALL_4,
    DATA_PHASE,
    DATA_SUMMONS,
};

enum Data64
{
    DATA_FALRIC,
    DATA_MARWYN,
    DATA_LICHKING,
    DATA_ESCAPE_LIDER,
    DATA_FROSTMOURNE,
    DATA_ARTHAS_DOOR,
    DATA_FROSTSWORN_DOOR,
    DATA_LORALEN,
    DATA_LORALEN_PART2    
};

enum Creatures
{
    NPC_FALRIC                                    = 38112,
    NPC_MARWYN                                    = 38113,
    NPC_FROSTSWORN_GENERAL                        = 36723,
    NPC_REFLECTION                                = 37107,
    NPC_LICH_KING_EVENT                           = 37226,
    NPC_LICH_KING_BOSS                            = 36954,

    NPC_UTHER                                     = 37225,
    NPC_JAINA_PART1                               = 37221,
    NPC_JAINA_PART2                               = 36955,
    NPC_SYLVANAS_PART1                            = 37223,
    NPC_SYLVANAS_PART2                            = 37554,

    NPC_WAVE_MERCENARY                            = 38177,
    NPC_WAVE_FOOTMAN                              = 38173,
    NPC_WAVE_RIFLEMAN                             = 38176,
    NPC_WAVE_PRIEST                               = 38175,
    NPC_WAVE_MAGE                                 = 38172,
    NPC_LORALEN                                   = 37779,
    NPC_KORELN                                    = 37598,
    NPC_LORALEN_PART2                             = 37796,
    NPC_KORELN_PART2                              = 37582,

    NPC_ICE_WALL                                  = 37014,

    NPC_BARTLETT                                  = 37182,
    NPC_KORM                                      = 37833,

    NPC_RAGING_GNOUL                              = 36940,
    NPC_RISEN_WITCH_DOCTOR                        = 36941,
    NPC_ABON                                      = 37069,
};

enum GameObjects
{
    GO_FROSTMOURNE                                = 202302,
    GO_FROSTMOURNE_ALTAR                          = 202236,
    GO_FRONT_DOOR                                 = 201976,
    GO_FROSTSWORN_DOOR                            = 197341,
    GO_ARTHAS_DOOR                                = 197342,
    GO_RUN_DOOR                                   = 197343,

    GO_ICE_WALL_1                                 = 300247,//@CENTRY+0 <- SET BY DEV
    GO_ICE_WALL_2                                 = 300248,//@CENTRY+1 <- SET BY DEV
    GO_ICE_WALL_3                                 = 300249,//@CENTRY+2 <- SET BY DEV
    GO_ICE_WALL_4                                 = 300250,//@CENTRY+3 <- SET BY DEV
    GO_CAVE                                       = 201596,
    GO_STAIRS_SKYBREAKER                          = 201709,
    GO_SKYBREAKER                                 = 300252,//@CENTRY+5 <- SET BY DEV
    GO_STAIRS_ORGRIM_HAMMER                       = 202211,
    GO_ORGRIM_HAMMER                              = 300251,//@CENTRY+4 <- SET BY DEV
    GO_PORTAL                                     = 202079,
    GO_CAPTAIN_CHEST_1                            = 202212, //3145
    GO_CAPTAIN_CHEST_2                            = 201710, //30357
    GO_CAPTAIN_CHEST_3                            = 202337, //3246
    GO_CAPTAIN_CHEST_4                            = 202336, //3333
};

enum Achievements
{
    ACHIEV_HALLS_OF_REFLECTION_N   = 4518,
    ACHIEV_HALLS_OF_REFLECTION_H   = 4521,
    ACHIEV_NOT_RETREATING_EVENT    = 22615,
    SPELL_ACHIEV_CHECK             = 72830,
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

    void JustSummoned(Creature* summoned)
    {
        summons.Summon(summoned);

        if (Unit* target = summoned->SelectNearestTarget())
        {
            if (summoned->AI())
                   summoned->AI()->AttackStart(target);
            else
            {
                   summoned->GetMotionMaster()->MoveChase(target);
                   summoned->Attack(target, true);
            }
        }

        if (summoned->AI())
               summoned->AI()->DoZoneInCombat();
    }

    void SummonedCreatureDespawn(Creature* summoned)
    {
        summons.Despawn(summoned);
        if (summons.empty())
        {
            if (summoned->isAlive())
                   instance->SetData(DATA_WAVE_COUNT, NOT_STARTED);
            else
                   instance->SetData(DATA_WAVE_COUNT, SPECIAL);
        }
    }
};

#endif
