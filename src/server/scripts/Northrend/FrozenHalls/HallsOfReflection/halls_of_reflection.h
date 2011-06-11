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
    DATA_FALRIC_EVENT,
    DATA_MARWYN_EVENT,
    DATA_LICHKING_EVENT,
    DATA_WAVE_COUNT,
    DATA_TEAM_IN_INSTANCE,
};

enum Data64
{
    DATA_FALRIC,
    DATA_MARWYN,
    DATA_LICHKING,
    DATA_FROSTMOURNE,
};

enum Creatures
{
    NPC_FALRIC                                    = 38112,
    NPC_MARWYN                                    = 38113,
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
};

enum GameObjects
{
    GO_FROSTMOURNE                                = 202302,
    GO_FROSTMOURNE_ALTAR                          = 202236,
    GO_FRONT_DOOR                                 = 201976,
    GO_ARTHAS_DOOR                                = 197341,
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
