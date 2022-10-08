/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "mogu_shan_palace.h"

#define TYPE_GET_ENTOURAGE 14

enum eSpells
{
    SPELL_RECKLESS_INSPIRATION = 118988,
    SPELL_SHANK                = 118963,
    SPELL_IRON_PROTECTOR       = 118958,
    SPELL_CLEANSING_FLAME      = 118940,
    SPELL_FIRE_BOLT            = 118936,
    SPELL_HEX_OF_LETHARGY      = 118903,
    SPELL_DARK_BOLT            = 118917
};

enum eActions
{
    ACTION_ENTOURAGE_DIED
};

enum eEvents
{
    EVENT_RECKLESS_INSPIRATION
};

enum eTalks
{
    TALK_INTRO,
    TALK_KILLING,
    TALK_SPELL,
    TALK_AGGRO,
    TALK_DEATH
};

class boss_gekkan : public CreatureScript
{
    public:
        boss_gekkan() : CreatureScript("boss_gekkan") {}

        struct boss_gekkan_AI : public BossAI
        {
            boss_gekkan_AI(Creature* creature) : BossAI(creature, DATA_GEKKAN) {}

            std::list<ObjectGuid> entourage;

            void EnterCombat(Unit* /*who*/) override
            {
                //Get the four adds.
                if (me->GetInstanceScript())
                    for (int i = 0; i < 4; ++i)
                        entourage.push_back(me->GetInstanceScript()->GetGuidData(TYPE_GET_ENTOURAGE + i));
                events.ScheduleEvent(EVENT_RECKLESS_INSPIRATION, 3000);
                Talk(TALK_AGGRO);

                if (me->GetInstanceScript())
                    me->GetInstanceScript()->SetData(DATA_GEKKAN_ADDS, 1);
            }

            void JustDied(Unit* /*who*/) override
            {
                for (auto guid : entourage)
                {
                    Creature* c = me->GetMap()->GetCreature(guid);
                    if (!c)
                        continue;
                    if (c->IsAlive())
                        me->CastSpell(c, SPELL_RECKLESS_INSPIRATION, false);
                }
                Talk(TALK_DEATH);
            }

            void KilledUnit(Unit* /*killer*/) override
            {
                Talk(TALK_KILLING);
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_ENTOURAGE_DIED:
                    {
                        //Delete the guid of the list if one dies.
                        ObjectGuid dead_entourage = ObjectGuid::Empty;
                        for (auto guid : entourage)
                        {
                            Creature* c = me->GetMap()->GetCreature(guid);
                            if (!c)
                                continue;
                            if (c->isDead())
                            {
                                dead_entourage = guid;
                                break;
                            }
                        }
                        entourage.remove(dead_entourage);
                        me->CastSpell(me, SPELL_RECKLESS_INSPIRATION, false);
                        Talk(TALK_SPELL);
                    }
                    break;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_RECKLESS_INSPIRATION:
                        {
                            //Cast on a random entourage the inspiration.
                            std::list<ObjectGuid>::iterator itr = entourage.begin();
                            std::advance(itr, urand(0, entourage.size() - 1));
                            ObjectGuid guid = *itr;
                            Creature* c = me->GetMap()->GetCreature(guid);
                            if (c)
                            {
                                me->CastSpell(c, SPELL_RECKLESS_INSPIRATION, false);
                                Talk(TALK_SPELL);
                            }
                            events.ScheduleEvent(EVENT_RECKLESS_INSPIRATION, 5000);
                        }
                        break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_gekkan_AI(creature);
        }
};

class mob_glintrok_skulker : public CreatureScript
{
    public:
        mob_glintrok_skulker() : CreatureScript("mob_glintrok_skulker") { }

        struct mob_glintrok_skulker_AI : public ScriptedAI
        {
            mob_glintrok_skulker_AI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void EnterCombat(Unit* /*unit*/) override
            {
                events.ScheduleEvent(1, 2000);

                if (me->GetInstanceScript())
                    me->GetInstanceScript()->SetData(DATA_GEKKAN_ADDS, 1);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case 1:
                        me->CastSpell(me->GetVictim(), SPELL_SHANK, false);
                        events.ScheduleEvent(1, 7000);
                        break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_glintrok_skulker_AI(creature);
        }
};

class mob_glintrok_ironhide : public CreatureScript
{
    public:
        mob_glintrok_ironhide() : CreatureScript("mob_glintrok_ironhide") {}

        struct mob_glintrok_ironhide_AI : public ScriptedAI
        {
            mob_glintrok_ironhide_AI(Creature* creature) : ScriptedAI(creature) { }

            EventMap events;

            void EnterCombat(Unit* /*unit*/) override
            {
                events.ScheduleEvent(1, 2000);

                if (me->GetInstanceScript())
                    me->GetInstanceScript()->SetData(DATA_GEKKAN_ADDS, 1);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case 1:
                        me->CastSpell(me, SPELL_IRON_PROTECTOR, false);
                        events.ScheduleEvent(1, 15000);
                        break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_glintrok_ironhide_AI(creature);
        }
};

class mob_glintrok_oracle : public CreatureScript
{
    public:
        mob_glintrok_oracle() : CreatureScript("mob_glintrok_oracle") {}

        struct mob_glintrok_oracle_AI : public ScriptedAI
        {
            mob_glintrok_oracle_AI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void EnterCombat(Unit* /*unit*/) override
            {
                events.ScheduleEvent(1, 2000);
                events.ScheduleEvent(2, 4000);

                if (me->GetInstanceScript())
                    me->GetInstanceScript()->SetData(DATA_GEKKAN_ADDS, 1);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case 1:
                        me->CastSpell(me, SPELL_CLEANSING_FLAME, false);
                        events.ScheduleEvent(1, 25000);
                        break;
                    case 2:
                        me->CastSpell(me->GetVictim(), SPELL_FIRE_BOLT, false);
                        events.ScheduleEvent(2, 7000);
                        break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_glintrok_oracle_AI(creature);
        }
};

class mob_glintrok_hexxer : public CreatureScript
{
    public:
        mob_glintrok_hexxer() : CreatureScript("mob_glintrok_hexxer") {}

        struct mob_glintrok_hexxer_AI : public ScriptedAI
        {
            mob_glintrok_hexxer_AI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void EnterCombat(Unit* /*unit*/) override
            {
                events.ScheduleEvent(1, 2000);
                events.ScheduleEvent(2, 4000);

                if (me->GetInstanceScript())
                    me->GetInstanceScript()->SetData(DATA_GEKKAN_ADDS, 1);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case 1:
                        me->CastSpell(me->GetVictim(), SPELL_HEX_OF_LETHARGY, false);
                        events.ScheduleEvent(1, 20000);
                        break;
                    case 2:
                        me->CastSpell(me->GetVictim(), SPELL_DARK_BOLT, false);
                        events.ScheduleEvent(2, 5000);
                        break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_glintrok_hexxer_AI(creature);
        }
};

void AddSC_boss_gekkan()
{
    new boss_gekkan();
    new mob_glintrok_hexxer();
    new mob_glintrok_skulker();
    new mob_glintrok_oracle();
    new mob_glintrok_ironhide();
}
