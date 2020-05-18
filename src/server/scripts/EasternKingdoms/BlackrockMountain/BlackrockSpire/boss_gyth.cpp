/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "blackrock_spire.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_REND_MOUNTS               = 16167, // Change model
    SPELL_CORROSIVE_ACID            = 16359, // Combat (self cast)
    SPELL_FLAMEBREATH               = 16390, // Combat (Self cast)
    SPELL_FREEZE                    = 16350, // Combat (Self cast)
    SPELL_KNOCK_AWAY                = 10101, // Combat
    SPELL_SUMMON_REND               = 16328  // Summons Rend near death
};

enum Misc
{
    NEFARIUS_PATH_2                 = 1379671,
    NEFARIUS_PATH_3                 = 1379672,
    GYTH_PATH_1                     = 1379681,
};

enum Events
{
    EVENT_CORROSIVE_ACID            = 1,
    EVENT_FREEZE                    = 2,
    EVENT_FLAME_BREATH              = 3,
    EVENT_KNOCK_AWAY                = 4,
    EVENT_SUMMONED_1                = 5,
    EVENT_SUMMONED_2                = 6
};

class boss_gyth : public CreatureScript
{
public:
    boss_gyth() : CreatureScript("boss_gyth")
    {

    }

    struct boss_gythAI : public BossAI
    {
        boss_gythAI(Creature* creature) : BossAI(creature, DATA_GYTH)
        {
            Initialize();
        }

        void Initialize()
        {
            SummonedRend = false;
        }

        bool SummonedRend;

        void Reset() override
        {
            Initialize();
            if (instance->GetBossState(DATA_GYTH) == IN_PROGRESS)
            {
                instance->SetBossState(DATA_GYTH, NOT_STARTED);
                me->DespawnOrUnsummon();
            }
        }

        void JustEngagedWith(Unit* who) override
        {
            BossAI::JustEngagedWith(who);

            events.ScheduleEvent(EVENT_CORROSIVE_ACID, 5000, 10000);            
            events.ScheduleEvent(EVENT_FLAME_BREATH, 10000, 15000);
            events.ScheduleEvent(EVENT_KNOCK_AWAY, 15000, 20000);
            events.ScheduleEvent(EVENT_FREEZE, 20000, 25000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            instance->SetBossState(DATA_GYTH, NOT_STARTED);
        }

        void SetData(uint32 /*type*/, uint32 data) override
        {
            switch (data)
            {
                case 1:
                    events.ScheduleEvent(EVENT_SUMMONED_1, 1s);
                    break;
                default:
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!SummonedRend && HealthBelowPct(50))
            {
                SpellCastResult scr = DoCast(me, SPELL_SUMMON_REND);
                if (scr == SpellCastResult::SPELL_CAST_OK)
                {
                    me->RemoveAura(SPELL_REND_MOUNTS);
                    SummonedRend = true;                    
                }
            }

            if (!UpdateVictim())
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SUMMONED_1:
                            me->AddAura(SPELL_REND_MOUNTS, me);
                            if (GameObject* portcullis = me->FindNearestGameObject(GO_DR_PORTCULLIS, 40.0f))
                            {
                                portcullis->SetGoState(GOState::GO_STATE_ACTIVE);                                
                            }                                
                            //if (Creature* victor = me->FindNearestCreature(NPC_LORD_VICTOR_NEFARIUS, 75.0f, true))
                            //    victor->AI()->SetData(1, 1);
                            events.ScheduleEvent(EVENT_SUMMONED_2, 2s);
                            break;
                        case EVENT_SUMMONED_2:
                            me->GetMotionMaster()->MovePath(GYTH_PATH_1, false);
                            break;
                        default:
                            break;
                    }
                }
                return;
            }

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CORROSIVE_ACID:
                    {
                        DoCast(SPELL_CORROSIVE_ACID);
                        events.Repeat(5000, 10000);
                        break;
                    }
                    case EVENT_FLAME_BREATH:
                    {
                        DoCast(SPELL_FLAMEBREATH);
                        events.Repeat(10000, 15000);
                        break;
                    }
                    case EVENT_KNOCK_AWAY:
                    {
                        DoCastVictim(SPELL_KNOCK_AWAY);
                        events.Repeat(15000, 20000);
                        break;
                    }
                    case EVENT_FREEZE:
                    {
                        DoCast(SPELL_FREEZE);
                        events.Repeat(20000, 25000);
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackrockSpireAI<boss_gythAI>(creature);
    }
};

void AddSC_boss_gyth()
{
    new boss_gyth();
}
