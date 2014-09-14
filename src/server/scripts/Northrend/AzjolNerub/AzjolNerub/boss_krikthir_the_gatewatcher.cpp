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

/*
 * Comment: Find in the future best timers and the event is not implemented.
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "azjol_nerub.h"

enum Spells
{
    SPELL_MIND_FLAY                               = 52586,
    SPELL_CURSE_OF_FATIGUE                        = 52592,
    SPELL_FRENZY                                  = 28747, //maybe 53361
    SPELL_SUMMON_SKITTERING_SWARMER               = 52438, //AOE Effect 140, maybe 52439
    SPELL_SUMMON_SKITTERING_SWARMER_1             = 52439, //Summon 3x 28735
    SPELL_ACID_SPLASH                             = 52446,
    SPELL_CHARGE                                  = 16979, //maybe is another spell
    SPELL_BACKSTAB                                = 52540,
    SPELL_SHADOW_BOLT                             = 52534,
    SPELL_SHADOW_NOVA                             = 52535,
    SPELL_STRIKE                                  = 52532,
    SPELL_CLEAVE                                  = 49806,
    SPELL_ENRAGE                                  = 52470,
    SPELL_INFECTED_BITE                           = 52469,
    SPELL_WEB_WRAP                                = 52086, //the spell is not working properly
    SPELL_BLINDING_WEBS                           = 52524,
    SPELL_POSION_SPRAY                            = 52493
};

enum Mobs
{
    NPC_SKITTERING_SWARMER                        = 28735,
    NPC_SKITTERING_SWARMER_CONTROLLER             = 32593,
    NPC_SKITTERING_INFECTIOR                      = 28736
};

enum Yells
{
    SAY_AGGRO                                     = 0,
    SAY_SLAY                                      = 1,
    SAY_DEATH                                     = 2,
    SAY_SWARM                                     = 3,
    SAY_PREFIGHT                                  = 4,
    SAY_SEND_GROUP                                = 5
};

Position const SpawnPoint[] =
{
    { 566.164f, 682.087f, 769.079f, 2.21657f  },
    { 529.042f, 706.941f, 777.298f, 1.0821f   },
    { 489.975f, 671.239f, 772.131f, 0.261799f },
    { 488.556f, 692.95f,  771.764f, 4.88692f  },
    { 553.34f,  640.387f, 777.419f, 1.20428f  },
    { 517.486f, 706.398f, 777.335f, 5.35816f  },
    { 504.01f,  637.693f, 777.479f, 0.506145f },
    { 552.625f, 706.408f, 777.177f, 3.4383f   }
};

enum Events
{
    EVENT_SUMMON                                  = 1,
    EVENT_MIND_FLAY,
    EVENT_CURSE_FATIGUE
};

class boss_krik_thir : public CreatureScript
{
    public:
        boss_krik_thir() : CreatureScript("boss_krik_thir") { }

        struct boss_krik_thirAI : public BossAI
        {
            boss_krik_thirAI(Creature* creature) : BossAI(creature, DATA_KRIKTHIR_THE_GATEWATCHER) { }

            void Reset() override
            {
                _Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                Talk(SAY_AGGRO);
                _EnterCombat();
                Summon();

                events.ScheduleEvent(EVENT_SUMMON, 15000);
                events.ScheduleEvent(EVENT_MIND_FLAY, 15000);
                events.ScheduleEvent(EVENT_CURSE_FATIGUE, 12000);
            }

            void Summon()
            {
                for (uint8 i = 0; i < 8; i++)
                {
                    me->SummonCreature(NPC_SKITTERING_SWARMER, SpawnPoint[i], TEMPSUMMON_TIMED_DESPAWN, 25000);
                    uint32 summon_entry = (i == 4 || i == 5 || i == 6) ? NPC_SKITTERING_INFECTIOR : NPC_SKITTERING_SWARMER;
                    me->SummonCreature(summon_entry, SpawnPoint[i], TEMPSUMMON_TIMED_DESPAWN, 25000);
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
                        case EVENT_SUMMON:
                            Summon();
                            events.ScheduleEvent(EVENT_SUMMON, 15000);
                            break;
                        case EVENT_MIND_FLAY:
                            DoCastVictim(SPELL_MIND_FLAY);
                            events.ScheduleEvent(EVENT_MIND_FLAY, 15000);
                            break;
                        case EVENT_CURSE_FATIGUE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                DoCast(target, SPELL_CURSE_OF_FATIGUE);
                            events.ScheduleEvent(EVENT_CURSE_FATIGUE, 10000);
                            break;
                        default:
                            break;
                    }
                }

                if (!me->HasAura(SPELL_FRENZY) && HealthBelowPct(10))
                    DoCast(me, SPELL_FRENZY, true);

                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*killer*/) override
            {
                Talk(SAY_DEATH);
                _JustDied();
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() != TYPEID_PLAYER)
                    return;

                Talk(SAY_SLAY);
            }

            void JustSummoned(Creature* summoned) override
            {
                summoned->GetMotionMaster()->MovePoint(0, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetAzjolNerubAI<boss_krik_thirAI>(creature);
        }
};

class npc_skittering_infector : public CreatureScript
{
    public:
        npc_skittering_infector() : CreatureScript("npc_skittering_infector") { }

        struct npc_skittering_infectorAI : public ScriptedAI
        {
            npc_skittering_infectorAI(Creature* creature) : ScriptedAI(creature) { }

            void JustDied(Unit* /*killer*/) override
            {
                DoCastAOE(SPELL_ACID_SPLASH);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetAzjolNerubAI<npc_skittering_infectorAI>(creature);
        }
};

enum TrashEvents
{
    // Anubar Skrimisher
    EVENT_ANUBAR_CHARGE = 1,
    EVENT_BACKSTAB,

    // Anubar Shadowcaster
    EVENT_SHADOW_BOLT,
    EVENT_SHADOW_NOVA,

    // Anubar Warrior
    EVENT_STRIKE,
    EVENT_CLEAVE,

    // Watcher Gashra
    EVENT_WEB_WRAP_GASHRA,
    EVENT_INFECTED_BITE_GASHRA,

    // Watcher Narjil
    EVENT_WEB_WRAP_NARJIL,
    EVENT_INFECTED_BITE_NARJIL,
    EVENT_BINDING_WEBS,

    // Watcher Silthik
    EVENT_WEB_WRAP_SILTHIK,
    EVENT_INFECTED_BITE_SILTHIK,
    EVENT_POISON_SPRAY
};

class npc_anub_ar_skirmisher : public CreatureScript
{
    public:
        npc_anub_ar_skirmisher() : CreatureScript("npc_anub_ar_skirmisher") { }

        struct npc_anub_ar_skirmisherAI : public ScriptedAI
        {
            npc_anub_ar_skirmisherAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                events.ScheduleEvent(EVENT_ANUBAR_CHARGE, 11000);
                events.ScheduleEvent(EVENT_BACKSTAB, 7000);
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
                        case EVENT_ANUBAR_CHARGE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            {
                                DoResetThreat();
                                me->AddThreat(target, 1.0f);
                                DoCast(target, SPELL_CHARGE, true);
                            }
                            events.ScheduleEvent(EVENT_ANUBAR_CHARGE, 15000);
                            break;
                        case EVENT_BACKSTAB:
                            DoCastVictim(SPELL_BACKSTAB);
                            events.ScheduleEvent(EVENT_BACKSTAB, 12000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            private:
                EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetAzjolNerubAI<npc_anub_ar_skirmisherAI>(creature);
        }
};

class npc_anub_ar_shadowcaster : public CreatureScript
{
    public:
        npc_anub_ar_shadowcaster() : CreatureScript("npc_anub_ar_shadowcaster") { }

        struct npc_anub_ar_shadowcasterAI : public ScriptedAI
        {
            npc_anub_ar_shadowcasterAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                events.ScheduleEvent(EVENT_SHADOW_BOLT, 6000);
                events.ScheduleEvent(EVENT_SHADOW_NOVA, 15000);
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
                        case EVENT_SHADOW_BOLT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                DoCast(target, SPELL_SHADOW_BOLT, true);
                            events.ScheduleEvent(EVENT_SHADOW_BOLT, 15000);
                            break;
                        case EVENT_SHADOW_NOVA:
                            DoCastVictim(SPELL_SHADOW_NOVA, true);
                            events.ScheduleEvent(EVENT_SHADOW_NOVA, 17000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            private:
                EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetAzjolNerubAI<npc_anub_ar_shadowcasterAI>(creature);
        }
};

class npc_anub_ar_warrior : public CreatureScript
{
    public:
        npc_anub_ar_warrior() : CreatureScript("npc_anub_ar_warrior") { }

        struct npc_anub_ar_warriorAI : public ScriptedAI
        {
            npc_anub_ar_warriorAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                events.ScheduleEvent(EVENT_CLEAVE, 11000);
                events.ScheduleEvent(EVENT_STRIKE, 6000);
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
                        case EVENT_CLEAVE:
                            DoCastVictim(SPELL_STRIKE, true);
                            events.ScheduleEvent(EVENT_CLEAVE, 15000);
                            break;
                        case EVENT_STRIKE:
                            DoCastVictim(SPELL_CLEAVE, true);
                            events.ScheduleEvent(EVENT_STRIKE, 17000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            private:
                EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetAzjolNerubAI<npc_anub_ar_warriorAI>(creature);
        }
};

class npc_watcher_gashra : public CreatureScript
{
    public:
        npc_watcher_gashra() : CreatureScript("npc_watcher_gashra") { }

        struct npc_watcher_gashraAI : public ScriptedAI
        {
            npc_watcher_gashraAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
            }

            void Reset() override
            {
                _events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                DoCast(me, SPELL_ENRAGE, true);
                _events.ScheduleEvent(EVENT_WEB_WRAP_GASHRA, 11000);
                _events.ScheduleEvent(EVENT_INFECTED_BITE_GASHRA, 4000);
            }

            void JustDied(Unit* /*killer*/) override
            {
                Creature* krikthir = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_KRIKTHIR_THE_GATEWATCHER));
                if (krikthir && krikthir->IsAlive())
                    krikthir->AI()->Talk(SAY_PREFIGHT);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_WEB_WRAP_GASHRA:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                DoCast(target, SPELL_WEB_WRAP, true);
                            _events.ScheduleEvent(EVENT_WEB_WRAP_GASHRA, 17000);
                            break;
                        case EVENT_INFECTED_BITE_GASHRA:
                            DoCastVictim(SPELL_INFECTED_BITE, true);
                            _events.ScheduleEvent(EVENT_INFECTED_BITE_GASHRA, 15000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            private:
                EventMap _events;
                InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetAzjolNerubAI<npc_watcher_gashraAI>(creature);
        }
};

class npc_watcher_narjil : public CreatureScript
{
    public:
        npc_watcher_narjil() : CreatureScript("npc_watcher_narjil") { }

        struct npc_watcher_narjilAI : public ScriptedAI
        {
            npc_watcher_narjilAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
            }

            void Reset() override
            {
                _events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _events.ScheduleEvent(EVENT_WEB_WRAP_NARJIL, 11000);
                _events.ScheduleEvent(EVENT_INFECTED_BITE_NARJIL, 4000);
                _events.ScheduleEvent(EVENT_BINDING_WEBS, 17000);
            }

            void JustDied(Unit* /*killer*/) override
            {
                Creature* krikthir = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_KRIKTHIR_THE_GATEWATCHER));
                if (krikthir && krikthir->IsAlive())
                    krikthir->AI()->Talk(SAY_PREFIGHT);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_WEB_WRAP_NARJIL:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                DoCast(target, SPELL_WEB_WRAP, true);
                            _events.ScheduleEvent(EVENT_WEB_WRAP_NARJIL, 15000);
                            break;
                        case EVENT_INFECTED_BITE_NARJIL:
                            DoCastVictim(SPELL_INFECTED_BITE, true);
                            _events.ScheduleEvent(EVENT_INFECTED_BITE_NARJIL, 11000);
                            break;
                        case EVENT_BINDING_WEBS:
                            DoCastVictim(SPELL_BLINDING_WEBS, true);
                            _events.ScheduleEvent(EVENT_BINDING_WEBS, 17000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            private:
                EventMap _events;
                InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetAzjolNerubAI<npc_watcher_narjilAI>(creature);
        }
};

class npc_watcher_silthik : public CreatureScript
{
    public:
        npc_watcher_silthik() : CreatureScript("npc_watcher_silthik") { }

        struct npc_watcher_silthikAI : public ScriptedAI
        {
            npc_watcher_silthikAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
            }

            void Reset() override
            {
                _events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _events.ScheduleEvent(EVENT_WEB_WRAP_SILTHIK, 11000);
                _events.ScheduleEvent(EVENT_INFECTED_BITE_SILTHIK, 4000);
                _events.ScheduleEvent(EVENT_POISON_SPRAY, 15000);
            }

            void JustDied(Unit* /*killer*/) override
            {
                Creature* krikthir = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_KRIKTHIR_THE_GATEWATCHER));
                if (krikthir && krikthir->IsAlive())
                    krikthir->AI()->Talk(SAY_PREFIGHT);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_WEB_WRAP_SILTHIK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                DoCast(target, SPELL_WEB_WRAP, true);
                            _events.ScheduleEvent(EVENT_WEB_WRAP_SILTHIK, 15000);
                            break;
                        case EVENT_INFECTED_BITE_SILTHIK:
                            DoCastVictim(SPELL_INFECTED_BITE, true);
                            _events.ScheduleEvent(EVENT_INFECTED_BITE_SILTHIK, 11000);
                            break;
                        case EVENT_POISON_SPRAY:
                            DoCastVictim(SPELL_POSION_SPRAY, true);
                            _events.ScheduleEvent(EVENT_POISON_SPRAY, 17000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            private:
                EventMap _events;
                InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetAzjolNerubAI<npc_watcher_silthikAI>(creature);
        }
};

class achievement_watch_him_die : public AchievementCriteriaScript
{
    public:
        achievement_watch_him_die() : AchievementCriteriaScript("achievement_watch_him_die")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            InstanceScript* instance = target->GetInstanceScript();
            if (!instance)
                return false;

            for (uint8 n = 0; n < 3; ++n)
            {
                if (Creature* watcher = ObjectAccessor::GetCreature(*target, instance->GetGuidData(DATA_WATCHER_GASHRA + n)))
                    if (!watcher->IsAlive())
                        return false;
            }

            return true;
        }
};

void AddSC_boss_krik_thir()
{
    new boss_krik_thir();
    new npc_skittering_infector();
    new npc_anub_ar_skirmisher();
    new npc_anub_ar_shadowcaster();
    new npc_watcher_gashra();
    new npc_anub_ar_warrior();
    new npc_watcher_silthik();
    new npc_watcher_narjil();
    new achievement_watch_him_die();
}
