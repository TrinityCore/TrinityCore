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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "violet_hold.h"

enum Spells
{
  SPELL_CAUTERIZING_FLAMES                      = 59466, //Only in heroic
  SPELL_FIREBOLT                                = 54235,
  H_SPELL_FIREBOLT                              = 59468,
  SPELL_FLAME_BREATH                            = 54282,
  H_SPELL_FLAME_BREATH                          = 59469,
  SPELL_LAVA_BURN                               = 54249,
  H_SPELL_LAVA_BURN                             = 59594
};

class boss_lavanthor : public CreatureScript
{
public:
    boss_lavanthor() : CreatureScript("boss_lavanthor") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new boss_lavanthorAI(creature);
    }

    struct boss_lavanthorAI : public ScriptedAI
    {
        boss_lavanthorAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        uint32 uiFireboltTimer;
        uint32 uiFlameBreathTimer;
        uint32 uiLavaBurnTimer;
        uint32 uiCauterizingFlamesTimer;

        InstanceScript* instance;

        void Reset() OVERRIDE
        {
            uiFireboltTimer = 1000;
            uiFlameBreathTimer = 5000;
            uiLavaBurnTimer = 10000;
            uiCauterizingFlamesTimer = 3000;
            if (instance)
            {
                if (instance->GetData(DATA_WAVE_COUNT) == 6)
                    instance->SetData(DATA_1ST_BOSS_EVENT, NOT_STARTED);
                else if (instance->GetData(DATA_WAVE_COUNT) == 12)
                    instance->SetData(DATA_2ND_BOSS_EVENT, NOT_STARTED);
            }
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            if (instance)
            {
            if (GameObject* pDoor = instance->instance->GetGameObject(instance->GetData64(DATA_LAVANTHOR_CELL)))
                    if (pDoor->GetGoState() == GO_STATE_READY)
                    {
                        EnterEvadeMode();
                        return;
                    }
                if (instance->GetData(DATA_WAVE_COUNT) == 6)
                    instance->SetData(DATA_1ST_BOSS_EVENT, IN_PROGRESS);
                else if (instance->GetData(DATA_WAVE_COUNT) == 12)
                    instance->SetData(DATA_2ND_BOSS_EVENT, IN_PROGRESS);
            }
        }

        void AttackStart(Unit* who) OVERRIDE
        {
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC) || me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                return;

            if (me->Attack(who, true))
            {
                me->AddThreat(who, 0.0f);
                me->SetInCombatWith(who);
                who->SetInCombatWith(me);
                DoStartMovement(who);
            }
        }

        void MoveInLineOfSight(Unit* /*who*/) OVERRIDE { }


        void UpdateAI(uint32 diff) OVERRIDE
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (uiFireboltTimer <= diff)
            {
                DoCastVictim(SPELL_FIREBOLT);
                uiFireboltTimer = urand(5000, 13000);
            } else uiFireboltTimer -= diff;

            if (uiFlameBreathTimer <= diff)
            {
                DoCastVictim(SPELL_FLAME_BREATH);
                uiFlameBreathTimer = urand(10000, 15000);
            } else uiFlameBreathTimer -= diff;

            if (uiLavaBurnTimer <= diff)
            {
                DoCastVictim(SPELL_LAVA_BURN);
                uiLavaBurnTimer = urand(15000, 23000);
            }

            if (IsHeroic())
            {
                if (uiCauterizingFlamesTimer <= diff)
                {
                    DoCastVictim(SPELL_CAUTERIZING_FLAMES);
                    uiCauterizingFlamesTimer = urand(10000, 16000);
                } else uiCauterizingFlamesTimer -= diff;
            }

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            if (instance)
            {
                if (instance->GetData(DATA_WAVE_COUNT) == 6)
                {
                    instance->SetData(DATA_1ST_BOSS_EVENT, DONE);
                    instance->SetData(DATA_WAVE_COUNT, 7);
                }
                else if (instance->GetData(DATA_WAVE_COUNT) == 12)
                {
                    instance->SetData(DATA_2ND_BOSS_EVENT, DONE);
                    instance->SetData(DATA_WAVE_COUNT, 13);
                }
            }
        }
    };

};

void AddSC_boss_lavanthor()
{
    new boss_lavanthor();
}
