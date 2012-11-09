/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
 
#include"ScriptPCH.h"
#include"WorldPacket.h"
#include"lost_city_of_the_tolvir.h"
#include"ScriptMgr.h"
#include"ScriptedCreature.h"
#include"SpellScript.h"
#include"SpellAuraEffects.h"

enum Spells
{
    SPELL_DUST_FLAIL         = 81642,
    SPELL_SCENT_OF_BLOOD     = 81690,
    H_SPELL_SCENT_OF_BLOOD     = 89998,
    SPELL_VENOMOUS_RAGE         = 81706,
    SPELL_VISCOUS_POISON     = 81630,
    H_SPELL_VISCOUS_POISON     = 90004,
};

enum Events
{
    EVENT_DUST_FLAIL         = 1,
    EVENT_SCENT_OF_BLOOD     = 2,
    EVENT_VENOMOUS_RAGE      = 3,
    EVENT_VISCOUS_POISON     = 4,
};

enum SummonIds
{
    NPC_FRENZIED_CROCOLISK   = 43658,
};

const Position SummonLocations[4] =
{
    //Frenzied Crocolisks
    {-11033.29f, -1674.57f, -0.56f, 1.09f},
    {-11029.84f, -1673.09f, -0.37f, 2.33f},
    {-11007.25f, -1666.37f, -0.23f, 2.46f},
    {-11006.83f, -1666.85f, -0.25f, 2.23f},
};

class boss_lockmaw : public CreatureScript
{
    public:
        boss_lockmaw() : CreatureScript("boss_lockmaw") {}

        CreatureAI* GetAI(Creature* creature) const
        {
           return new boss_lockmawAI(creature);
        }
        struct boss_lockmawAI : public ScriptedAI
        {
            boss_lockmawAI(Creature* creature) : ScriptedAI(creature), Summons(me)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            EventMap events;
            SummonList Summons;
            bool check_in;

            void Reset ()
            {
                events.Reset();
                Summons.DespawnAll();

                if (instance && (instance->GetData(DATA_LOCKMAW_EVENT) != DONE && !check_in))
                    instance->SetData(DATA_LOCKMAW_EVENT, NOT_STARTED);

                check_in = false;
            }

            void JustDied(Unit* /*Kill*/)
            {
                Summons.DespawnAll();
                if (instance)
                    instance->SetData(DATA_LOCKMAW_EVENT, DONE);
            }

            void EnterCombat(Unit* /*Ent*/)
            {
                if (instance)
                    instance->SetData(DATA_LOCKMAW_EVENT, IN_PROGRESS);

                DoZoneInCombat();
            }

            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())  /* No target to kill */
                    return;

                events.Update(uiDiff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_DUST_FLAIL:
                            DoCast(me->getVictim(), SPELL_DUST_FLAIL);
                            events.ScheduleEvent(EVENT_DUST_FLAIL, urand(6000, 10000));
                            return;
                        case EVENT_VISCOUS_POISON:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, true))
                                DoCast(me->getVictim(), SPELL_VISCOUS_POISON);
                                events.ScheduleEvent(EVENT_VISCOUS_POISON, 2000);
                            return;
                        case EVENT_SCENT_OF_BLOOD:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, true))
                                DoCast(me->getVictim(), SPELL_SCENT_OF_BLOOD);
                                for (uint8 i=0; i<4; i++)
                                {
                                  Creature* Crocolisk = me->SummonCreature(NPC_FRENZIED_CROCOLISK, SummonLocations[i], TEMPSUMMON_CORPSE_DESPAWN);
                                  Crocolisk->AddThreat(me->getVictim(), 0.0f);
                                  DoZoneInCombat(Crocolisk);
                                }
                                events.ScheduleEvent(EVENT_SCENT_OF_BLOOD, 6000);
                            return;
                        case EVENT_VENOMOUS_RAGE:
                            if (me->GetHealthPct() < 30)
                                DoCast(me, SPELL_VENOMOUS_RAGE);
                                events.ScheduleEvent(EVENT_VENOMOUS_RAGE, 1000);
                            return;
                        default:
                            break;
                    }
            }

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_lockmaw()
{
    new boss_lockmaw();
}