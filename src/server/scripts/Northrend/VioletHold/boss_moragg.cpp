/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

//Spells
enum Spells
{
    SPELL_CORROSIVE_SALIVA                     = 54527,
    SPELL_OPTIC_LINK                           = 54396
};

class boss_moragg : public CreatureScript
{
public:
    boss_moragg() : CreatureScript("boss_moragg") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_moraggAI>(creature);
    }

    struct boss_moraggAI : public ScriptedAI
    {
        boss_moraggAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        uint32 uiOpticLinkTimer;
        uint32 uiCorrosiveSalivaTimer;

        InstanceScript* instance;

        void Reset() override
        {
            uiOpticLinkTimer = 10000;
            uiCorrosiveSalivaTimer = 5000;

            if (instance->GetData(DATA_WAVE_COUNT) == 6)
                instance->SetData(DATA_1ST_BOSS_EVENT, NOT_STARTED);
            else if (instance->GetData(DATA_WAVE_COUNT) == 12)
                instance->SetData(DATA_2ND_BOSS_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (GameObject* pDoor = instance->instance->GetGameObject(instance->GetGuidData(DATA_MORAGG_CELL)))
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

        void AttackStart(Unit* who) override
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

        void MoveInLineOfSight(Unit* /*who*/) override { }


        void UpdateAI(uint32 diff) override
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (uiOpticLinkTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_OPTIC_LINK);
                uiOpticLinkTimer = 15000;
            } else uiOpticLinkTimer -= diff;

            if (uiCorrosiveSalivaTimer <= diff)
            {
                DoCastVictim(SPELL_CORROSIVE_SALIVA);
                uiCorrosiveSalivaTimer = 10000;
            } else uiCorrosiveSalivaTimer -= diff;

            DoMeleeAttackIfReady();
        }
        void JustDied(Unit* /*killer*/) override
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
    };

};

void AddSC_boss_moragg()
{
    new boss_moragg();
}
