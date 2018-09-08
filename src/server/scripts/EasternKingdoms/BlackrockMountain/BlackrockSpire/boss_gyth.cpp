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
    EVENT_BREATH                    = 1,
    EVENT_KNOCK_AWAY                = 2,
    EVENT_SUMMONED_1                = 3,
    EVENT_SUMMONED_2                = 4
};

class boss_gyth : public CreatureScript
{
public:
    boss_gyth() : CreatureScript("boss_gyth") { }

    struct boss_gythAI : public BossAI
    {
        boss_gythAI(Creature* creature) : BossAI(creature, DATA_GYTH)
        {
            SummonedRend = false;
            breathCombo = 0;
            breathComboSpellsNum = 0;
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
//RESPAWN REND HERE
//            if (!SummonedRend)
//                if (Creature* og_rend = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_WARCHIEF_REND_BLACKHAND)))
//                    og_rend->Respawn(true);
            me->DespawnOrUnsummon();
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            _JustEngagedWith();

            events.ScheduleEvent(EVENT_BREATH, 8s, 16s);
            events.ScheduleEvent(EVENT_KNOCK_AWAY, 12s, 18s);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (!SummonedRend && me->HealthBelowPctDamaged(25, damage))
            {
                DoCast(me, SPELL_SUMMON_REND);
                me->RemoveAura(SPELL_REND_MOUNTS);
                SummonedRend = true;
            }
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
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            if (!UpdateVictim())
            {
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SUMMONED_1:
                            me->AddAura(SPELL_REND_MOUNTS, me);
                            if (GameObject* portcullis = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(GO_DR_PORTCULLIS)))
                                portcullis->UseDoorOrButton();
                            if (Creature* victor = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_LORD_VICTOR_NEFARIUS)))
                                victor->AI()->SetData(1, 1);
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

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_BREATH:
                        if (breathCombo == 0)
                        {
                            breathComboSpells[0] = SPELL_CORROSIVE_ACID;
                            breathComboSpells[1] = SPELL_FREEZE;
                            breathComboSpells[2] = SPELL_FLAMEBREATH;
                            breathComboSpellsNum = 3;
                            breathCombo          = 3;
                            //breathCombo = urand(1, 3);
                        }

                        if (0 < breathComboSpellsNum && breathComboSpellsNum <= 3)
                        {
                            uint32 spellIndex = urand(0, breathComboSpellsNum - 1);
                            DoCast(me, breathComboSpells[spellIndex]);
                            breathComboSpells[spellIndex] = breathComboSpells[breathComboSpellsNum-1];
                            breathComboSpellsNum--;
                        }
                        breathCombo--;

                        if(breathCombo == 0)
                            events.ScheduleEvent(EVENT_BREATH, 10s, 16s);
                        else
                            events.ScheduleEvent(EVENT_BREATH, 1500ms);
                        break;
                    case EVENT_KNOCK_AWAY:
                        DoCastVictim(SPELL_KNOCK_AWAY);
                        events.ScheduleEvent(EVENT_KNOCK_AWAY, 14s, 20s);
                        break;
                    default:
                        break;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }
            DoMeleeAttackIfReady();
        }

        private:
            bool SummonedRend;
            uint32 breathCombo;
            uint32 breathComboSpells[3];
            uint32 breathComboSpellsNum;
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
