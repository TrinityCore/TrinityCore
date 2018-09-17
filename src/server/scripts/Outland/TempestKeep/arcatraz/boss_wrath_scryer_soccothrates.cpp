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

/* ScriptData
SDName: boss_wrath_scryer_soccothrates
SD%Complete: 95%
SDComment: charge left to script
SDCategory: Tempest Keep, The Arcatraz
EndScriptData */

#include "ScriptMgr.h"
#include "arcatraz.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"

enum Say
{
    // Wrath-Scryer Soccothrates
    SAY_AGGRO                       = 1,
    SAY_SLAY                        = 2,
    SAY_KNOCK_AWAY                  = 3,
    SAY_DEATH                       = 4,
    SAY_DALLIAH_DEATH               = 6,
    SAY_SOCCOTHRATES_CONVO_1        = 7,
    SAY_SOCCOTHRATES_CONVO_2        = 8,
    SAY_SOCCOTHRATES_CONVO_3        = 9,
    SAY_SOCCOTHRATES_CONVO_4        = 10,

    // Dalliah the Doomsayer
    SAY_AGGRO_SOCCOTHRATES_FIRST    = 0,
    SAY_SOCCOTHRATES_25_PERCENT     = 6,
    SAY_DALLIAH_CONVO_1             = 8,
    SAY_DALLIAH_CONVO_2             = 9,
    SAY_DALLIAH_CONVO_3             = 10
};

enum Spells
{
    SPELL_FEL_IMMOLATION            = 36051,
    SPELL_FELFIRE_SHOCK             = 35759,
    SPELL_KNOCK_AWAY                = 36512,
    SPELL_FELFIRE_LINE_UP           = 35770,
    SPELL_CHARGE_TARGETING          = 36038,
    SPELL_CHARGE                    = 35754
};

enum Events
{
    EVENT_FELFIRE_SHOCK             = 1,
    EVENT_KNOCK_AWAY                = 2,

    EVENT_PREFIGHT_1                = 3,
    EVENT_PREFIGHT_2                = 4,
    EVENT_PREFIGHT_3                = 5,
    EVENT_PREFIGHT_4                = 6,
    EVENT_PREFIGHT_5                = 7,
    EVENT_PREFIGHT_6                = 8,
    EVENT_PREFIGHT_7                = 9,
    EVENT_PREFIGHT_8                = 10,
    EVENT_PREFIGHT_9                = 11,
    EVENT_ME_FIRST                  = 12,
    EVENT_DALLIAH_DEATH             = 13
};

class boss_wrath_scryer_soccothrates : public CreatureScript
{
    public:
        boss_wrath_scryer_soccothrates() : CreatureScript("boss_wrath_scryer_soccothrates") { }

        struct boss_wrath_scryer_soccothratesAI : public BossAI
        {
            boss_wrath_scryer_soccothratesAI(Creature* creature) : BossAI(creature, DATA_SOCCOTHRATES)
            {
                preFight = false;
                dalliahTaunt = false;
                dalliahDeath = false;
            }

            void Reset() override
            {
                _Reset();
                preFight = false;
                dalliahTaunt = false;
                dalliahDeath = false;
                DoCast(me, SPELL_FEL_IMMOLATION);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(SAY_DEATH);

                if (Creature* dalliah = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_DALLIAH)))
                    if (dalliah->IsAlive() && !dalliah->IsInCombat())
                        dalliah->AI()->SetData(1, 1);
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                _JustEngagedWith();
                events.ScheduleEvent(EVENT_FELFIRE_SHOCK, 12s, 14s);
                events.ScheduleEvent(EVENT_KNOCK_AWAY, 11s, 12s);
                events.ScheduleEvent(EVENT_ME_FIRST, 6s);
                Talk(SAY_AGGRO);
                preFight = false;
            }

            void KilledUnit(Unit* /*victim*/) override
            {
                Talk(SAY_SLAY);
            }

            void MoveInLineOfSight(Unit* who) override
            {
                if (instance->GetData(DATA_CONVERSATION) == NOT_STARTED && who->GetTypeId() == TYPEID_PLAYER && me->IsWithinDistInMap(who, 70.0f))
                {
                    Talk(SAY_SOCCOTHRATES_CONVO_1);
                    instance->SetData(DATA_CONVERSATION, DONE);

                    preFight = true;
                    events.ScheduleEvent(EVENT_PREFIGHT_1, 2000);
                }
            }

            void SetData(uint32 /*type*/, uint32 data) override
            {
                switch (data)
                {
                    case 1:
                        events.ScheduleEvent(EVENT_DALLIAH_DEATH, 6s);
                        dalliahDeath = true;
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                {
                    if (preFight)
                    {
                        events.Update(diff);

                        while (uint32 eventId = events.ExecuteEvent())
                        {
                            switch (eventId)
                            {
                                case EVENT_PREFIGHT_1:
                                    if (Creature* dalliah = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_DALLIAH)))
                                        dalliah->AI()->Talk(SAY_DALLIAH_CONVO_1);
                                    events.ScheduleEvent(EVENT_PREFIGHT_2, 3000);
                                    break;
                                case EVENT_PREFIGHT_2:
                                    Talk(SAY_SOCCOTHRATES_CONVO_2);
                                    events.ScheduleEvent(EVENT_PREFIGHT_3, 3000);
                                    break;
                                case EVENT_PREFIGHT_3:
                                    if (Creature* dalliah = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_DALLIAH)))
                                        dalliah->AI()->Talk(SAY_DALLIAH_CONVO_2);
                                    events.ScheduleEvent(EVENT_PREFIGHT_4, 6000);
                                    break;
                                case EVENT_PREFIGHT_4:
                                    Talk(SAY_SOCCOTHRATES_CONVO_3);
                                    events.ScheduleEvent(EVENT_PREFIGHT_5, 2000);
                                    break;
                                case EVENT_PREFIGHT_5:
                                    if (Creature* dalliah = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_DALLIAH)))
                                        dalliah->AI()->Talk(SAY_DALLIAH_CONVO_3);
                                    events.ScheduleEvent(EVENT_PREFIGHT_6, 3000);
                                    break;
                                case EVENT_PREFIGHT_6:
                                    Talk(SAY_SOCCOTHRATES_CONVO_4);
                                    events.ScheduleEvent(EVENT_PREFIGHT_7, 2000);
                                    break;
                                case EVENT_PREFIGHT_7:
                                    if (Creature* dalliah = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_DALLIAH)))
                                        dalliah->GetMotionMaster()->MovePoint(0, 118.6048f, 96.84852f, 22.44115f);
                                    events.ScheduleEvent(EVENT_PREFIGHT_8, 4000);
                                    break;
                                case EVENT_PREFIGHT_8:
                                    me->GetMotionMaster()->MovePoint(0, 122.1035f, 192.7203f, 22.44115f);
                                    events.ScheduleEvent(EVENT_PREFIGHT_9, 4000);
                                    break;
                                case EVENT_PREFIGHT_9:
                                    if (Creature* dalliah = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_DALLIAH)))
                                    {
                                        dalliah->SetFacingToObject(me);
                                        me->SetFacingToObject(dalliah);
                                        dalliah->SetHomePosition(dalliah->GetPositionX(), dalliah->GetPositionY(), dalliah->GetPositionZ(), 1.51737f);
                                        me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 4.725722f);
                                        preFight = false;
                                    }
                                    break;
                                default:
                                    break;
                            }
                        }
                    }

                    if (dalliahDeath)
                    {
                        events.Update(diff);

                        while (uint32 eventId = events.ExecuteEvent())
                        {
                            switch (eventId)
                            {
                                case EVENT_DALLIAH_DEATH:
                                    Talk(SAY_DALLIAH_DEATH);
                                    break;
                                default:
                                    break;
                            }
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
                        case EVENT_FELFIRE_SHOCK:
                            DoCastVictim(SPELL_FELFIRE_SHOCK, true);
                            events.ScheduleEvent(EVENT_FELFIRE_SHOCK, 12s, 14s);
                            break;
                        case EVENT_KNOCK_AWAY:
                            DoCast(me, SPELL_KNOCK_AWAY);
                            Talk(SAY_KNOCK_AWAY);
                            events.ScheduleEvent(EVENT_KNOCK_AWAY, 11s, 12s);
                            break;
                        case EVENT_ME_FIRST:
                            if (Creature* dalliah = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_DALLIAH)))
                                if (dalliah->IsAlive() && !dalliah->IsInCombat())
                                    dalliah->AI()->Talk(SAY_AGGRO_SOCCOTHRATES_FIRST);
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                if (HealthBelowPct(25) && !dalliahTaunt)
                {
                    if (Creature* dalliah = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_DALLIAH)))
                        dalliah->AI()->Talk(SAY_SOCCOTHRATES_25_PERCENT);
                    dalliahTaunt = true;
                }

                DoMeleeAttackIfReady();
            }

        private:
            bool preFight;
            bool dalliahTaunt;
            bool dalliahDeath;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetArcatrazAI<boss_wrath_scryer_soccothratesAI>(creature);
        }
};

void AddSC_boss_wrath_scryer_soccothrates()
{
    new boss_wrath_scryer_soccothrates();
}
