/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

    DATA_SUMMONS           = 8,
    DATA_ICE_WALL_1        = 9,
    DATA_ICE_WALL_2        = 10,
    DATA_ICE_WALL_3        = 11,
    DATA_ICE_WALL_4        = 12,

    DATA_PHASE             = 13,
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
    NPC_KORELN                                    = 37582,
    NPC_LORALEN                                     = 37779,
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
    boss_horAI(Creature *pCreature) : ScriptedAI(pCreature), summons(pCreature)
    {
        pInstance = me->GetInstanceScript();
    }

    InstanceScript* pInstance;
    EventMap events;
    SummonList summons;

    void Reset()
    {
        events.Reset();
        me->SetVisible(false);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
        me->SetReactState(REACT_PASSIVE);
    }

    void DamageTaken(Unit* /*pWho*/, uint32 &uiDamage)
    {
        if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            uiDamage = 0;
    }

    void DoAction(const int32 actionID)
    {
        switch(actionID)
        {
            case ACTION_ENTER_COMBAT:  // called by InstanceScript when boss shall enter in combat.
                // Just in case. Should have been done by InstanceScript
                me->SetVisible(true);

                // Reset flags
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_AGGRESSIVE);

                if (Unit *pUnit = me->SelectNearestTarget())
                    AttackStart(pUnit);

                DoZoneInCombat();
                break;
        }
    }

    void JustSummoned(Creature *pSummoned)
    {
        summons.Summon(pSummoned);

        if (Unit *pUnit = pSummoned->SelectNearestTarget())
        {
            if (pSummoned->AI())
                pSummoned->AI()->AttackStart(pUnit);
            else
            {
                pSummoned->GetMotionMaster()->MoveChase(pUnit);
                pSummoned->Attack(pUnit, true);
            }
        }

        if (pSummoned->AI())
            pSummoned->AI()->DoZoneInCombat();
    }

    void SummonedCreatureDespawn(Creature *pSummoned)
    {
        summons.Despawn(pSummoned);
        if (summons.empty())
        {
            if (pSummoned->isAlive())
                pInstance->SetData(DATA_WAVE_COUNT, NOT_STARTED);
            else
                pInstance->SetData(DATA_WAVE_COUNT, SPECIAL);
        }
    }
};

#endif
