/*
    Dungeon : Mogu'shan palace 87-89
    Gekkan
    Jade servers
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "mogu_shan_palace.h"

#define TYPE_GET_ENTOURAGE 14

class boss_gekkan : public CreatureScript
{
    public:
        boss_gekkan() : CreatureScript("boss_gekkan") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_gekkan_AI(creature);
        }

        enum eSpells
        {
            SPELL_RECKLESS_INSPIRATION = 118988,
        };

        enum eActions
        {
            ACTION_ENTOURAGE_DIED,
        };

        enum eEvents
        {
            EVENT_RECKLESS_INSPIRATION = 1,
        };

        enum eTalks
        {
            TALK_INTRO,
            TALK_KILLING,
            TALK_SPELL,
            TALK_AGGRO,
            TALK_DEATH,
        };

        struct boss_gekkan_AI : public BossAI
        {
            boss_gekkan_AI(Creature* creature) : BossAI(creature, DATA_GEKKAN)
            {
            }
            std::list<uint64> entourage;

            void EnterCombat(Unit* who)
            {
                //Get the four adds.
                if (me->GetInstanceScript())
                    for (int i = 0; i < 4; ++i)
                        entourage.push_back(me->GetInstanceScript()->GetData64(TYPE_GET_ENTOURAGE + i));
                events.ScheduleEvent(EVENT_RECKLESS_INSPIRATION, 3000);
                Talk(TALK_AGGRO);

                if (me->GetInstanceScript())
                    me->GetInstanceScript()->SetData(DATA_GEKKAN_ADDS, 1);
            }

            void JustDied(Unit* who)
            {
                for (auto guid : entourage)
                {
                    Creature* c = me->GetMap()->GetCreature(instance->GetObjectGuid(guid));
                    if (!c)
                        continue;
                    if (c->IsAlive())
                        me->CastSpell(c, SPELL_RECKLESS_INSPIRATION, false);
                }
                Talk(TALK_DEATH);
            }

            void KilledUnit(Unit* u)
            {
                Talk(TALK_KILLING);
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                case ACTION_ENTOURAGE_DIED:
                    {
                        //Delete the guid of the list if one dies.
                        uint64 dead_entourage = 0;
                        for (auto guid : entourage)
                        {
                            Creature* c = me->GetMap()->GetCreature(instance->GetObjectGuid(guid));
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

            void UpdateAI(uint32 diff)
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
                            std::list<uint64>::iterator itr = entourage.begin();
                            std::advance(itr, urand(0, entourage.size() - 1));
                            uint64 guid = *itr;
                            Creature* c = me->GetMap()->GetCreature(instance->GetObjectGuid(guid));
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
};

class mob_glintrok_skulker : public CreatureScript
{
    public:
        mob_glintrok_skulker() : CreatureScript("mob_glintrok_skulker") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_glintrok_skulker_AI(creature);
        }

        enum eSpells
        {
            SPELL_SHANK        = 118963,
        };

        struct mob_glintrok_skulker_AI : public ScriptedAI
        {
            mob_glintrok_skulker_AI(Creature* creature) : ScriptedAI(creature)
            {
            }
            EventMap events;

            void EnterCombat(Unit* unit)
            {
                events.ScheduleEvent(1, 2000);

                if (me->GetInstanceScript())
                    me->GetInstanceScript()->SetData(DATA_GEKKAN_ADDS, 1);
            }

            void UpdateAI(uint32 diff)
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
};

class mob_glintrok_ironhide : public CreatureScript
{
    public:
        mob_glintrok_ironhide() : CreatureScript("mob_glintrok_ironhide") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_glintrok_ironhide_AI(creature);
        }

        enum eSpells
        {
            SPELL_IRON_PROTECTOR        = 118958,
        };

        struct mob_glintrok_ironhide_AI : public ScriptedAI
        {
            mob_glintrok_ironhide_AI(Creature* creature) : ScriptedAI(creature)
            {
            }
            EventMap events;

            void EnterCombat(Unit* unit)
            {
                events.ScheduleEvent(1, 2000);

                if (me->GetInstanceScript())
                    me->GetInstanceScript()->SetData(DATA_GEKKAN_ADDS, 1);
            }

            void UpdateAI(uint32 diff)
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
};

class mob_glintrok_oracle : public CreatureScript
{
    public:
        mob_glintrok_oracle() : CreatureScript("mob_glintrok_oracle") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_glintrok_oracle_AI(creature);
        }

        enum eSpells
        {
            SPELL_CLEANSING_FLAME        = 118940,
            SPELL_FIRE_BOLT              = 118936,
        };

        struct mob_glintrok_oracle_AI : public ScriptedAI
        {
            mob_glintrok_oracle_AI(Creature* creature) : ScriptedAI(creature)
            {
            }
            EventMap events;

            void EnterCombat(Unit* unit)
            {
                events.ScheduleEvent(1, 2000);
                events.ScheduleEvent(2, 4000);

                if (me->GetInstanceScript())
                    me->GetInstanceScript()->SetData(DATA_GEKKAN_ADDS, 1);
            }

            void UpdateAI(uint32 diff)
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
};

class mob_glintrok_hexxer : public CreatureScript
{
    public:
        mob_glintrok_hexxer() : CreatureScript("mob_glintrok_hexxer") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_glintrok_hexxer_AI(creature);
        }

        enum eSpells
        {
            SPELL_HEX_OF_LETHARGY        = 118903,
            SPELL_DARK_BOLT              = 118917,
        };

        struct mob_glintrok_hexxer_AI : public ScriptedAI
        {
            mob_glintrok_hexxer_AI(Creature* creature) : ScriptedAI(creature)
            {
            }
            EventMap events;

            void EnterCombat(Unit* unit)
            {
                events.ScheduleEvent(1, 2000);
                events.ScheduleEvent(2, 4000);

                if (me->GetInstanceScript())
                    me->GetInstanceScript()->SetData(DATA_GEKKAN_ADDS, 1);
            }

            void UpdateAI(uint32 diff)
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
};

void AddSC_boss_gekkan()
{
    new boss_gekkan();
    new mob_glintrok_hexxer();
    new mob_glintrok_skulker();
    new mob_glintrok_oracle();
    new mob_glintrok_ironhide();
}
