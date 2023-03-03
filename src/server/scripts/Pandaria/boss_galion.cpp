///*
//Pandaria
//World boss
//Antoine Vallee for Pandashan Servers
//
//*/
//#include "ScriptMgr.h"
//#include "ScriptedCreature.h"
//#include "ObjectMgr.h"
//#include "ScriptMgr.h"
//
//enum eBosses
//{
//    BOSS_GALION,
//    BOSS_OONDASTA,
//};
//
//enum eSpells
//{
//    SPELL_STOMP = 121787,
//    SPELL_CANNON_BARRAGE = 121600,
//    SPELL_FIRE_SHOT = 121673,
//    SPELL_EMPALLING_PULL = 121747,
//    SPELL_BERSERK = 47008,
//
//
//    // oondasta
//    SPELL_CRUSH = 137504,// INCREASE DAMAGE
//    SPELL_FRILL_BLAST = 137505,
//    SPELL_PURSING_ROAR = 137457,
//    SPELL_SPIRITFIRE_BEAM = 137508,
//    SPELL_GROWING_FURY = 137502,
//};
//
//enum eEvents
//{
//    EVENT_STOMP = 1,
//    EVENT_CANNON = 2,
//    EVENT_FIRE_SHOT = 3,
//    EVENT_EMPALLING = 4,
//    EVENT_SPAWN = 6,
//    EVENT_BERSERK = 7,
//
//    // Oondasta
//    EVENT_CRUSH = 8,
//    EVENT_GROWING_FURY = 9,
//    EVENT_FRILL_BLAST = 10,
//    EVENT_SPIRITFIRE_BEAM = 11,
//    EVENT_PURSING_ROAR = 12,
//};
//
//enum eCreatures
//{
//    CREATURE_GALION = 62351,
//};
//
//
//class boss_galion : public CreatureScript
//{
//public:
//    boss_galion() : CreatureScript("boss_galion") { }
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new boss_galion_AI(creature);
//    }
//
//    struct boss_galion_AI : public BossAI
//    {
//        boss_galion_AI(Creature* creature) : BossAI(creature, BOSS_GALION)
//        {}
//        void Reset()
//        {
//            events.Reset();
//            _Reset();
//        }
//
//        void KilledUnit(Unit* u)
//        {
//        }
//
//        void EnterCombat(Unit* unit)
//        {
//            events.ScheduleEvent(EVENT_STOMP, 50000);
//            events.ScheduleEvent(EVENT_CANNON, 25000);
//            events.ScheduleEvent(EVENT_SPAWN, 60000);
//            events.ScheduleEvent(EVENT_FIRE_SHOT, 10000);
//            events.ScheduleEvent(EVENT_BERSERK, 900000);
//        }
//
//        void UpdateAI(const uint32 diff)
//        {
//            if (!UpdateVictim())
//                return;
//
//            events.Update(diff);
//            while (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_STOMP:
//                {
//                    me->CastSpell(me, SPELL_STOMP, true);
//                    events.ScheduleEvent(EVENT_STOMP, 60000);
//                    break;
//                }
//                case EVENT_CANNON:
//                {
//                    me->CastSpell(me, SPELL_CANNON_BARRAGE, true);
//                    events.ScheduleEvent(EVENT_CANNON, 60000);
//                    break;
//                }
//                case EVENT_SPAWN:
//                {
//                    for (uint8 i = 0; i<6; ++i)
//                        me->SummonCreature(CREATURE_GALION, me->GetPositionX() + rand() % 5, me->GetPositionY() + 3 + rand() % 5, me->GetPositionZ() + 2, 10.0f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
//
//                    events.ScheduleEvent(EVENT_SPAWN, 60000);
//                    break;
//                }
//                case EVENT_BERSERK:
//                {
//                    me->CastSpell(me, SPELL_BERSERK, false);
//                    break;
//                }
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//    };
//};
//
//class npc_galion : public CreatureScript
//{
//public:
//    npc_galion() : CreatureScript("npc_galion") { }
//
//    struct npc_galionAI : public ScriptedAI
//    {
//        npc_galionAI(Creature* creature) : ScriptedAI(creature)
//        {
//        }
//        EventMap events;
//        void Reset()
//        {
//            events.Reset();
//        }
//        void EnterCombat(Unit* unit)
//        {
//            events.ScheduleEvent(EVENT_EMPALLING, 50000);
//        }
//        void UpdateAI(const uint32 diff)
//        {
//            if (!UpdateVictim())
//                return;
//
//            events.Update(diff);
//
//            while (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_EMPALLING:
//                {
//                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
//                        me->CastSpell(target, SPELL_EMPALLING_PULL, true);
//                    events.ScheduleEvent(EVENT_EMPALLING, 60000);
//                    break;
//                }
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new npc_galionAI(creature);
//    }
//};
//
//// Oondasta
//class boss_oondasta : public CreatureScript
//{
//public:
//    boss_oondasta() : CreatureScript("boss_oondasta") { }
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new boss_oondasta_AI(creature);
//    }
//
//    struct boss_oondasta_AI : public BossAI
//    {
//        boss_oondasta_AI(Creature* creature) : BossAI(creature, BOSS_OONDASTA)
//        {}
//        void Reset()
//        {
//            events.Reset();
//            _Reset();
//        }
//        void EnterCombat(Unit* unit)
//        {
//            events.ScheduleEvent(EVENT_GROWING_FURY, urand(30000, 45000));
//            events.ScheduleEvent(EVENT_SPIRITFIRE_BEAM, urand(15000, 20000));
//            events.ScheduleEvent(EVENT_FRILL_BLAST, urand(40000, 55000));
//            events.ScheduleEvent(EVENT_PURSING_ROAR, urand(9000, 17000));
//            events.ScheduleEvent(EVENT_CRUSH, urand(10000, 23000));
//
//            me->CastSpell(me, 138391);
//        }
//
//        void UpdateAI(const uint32 diff)
//        {
//            if (!UpdateVictim())
//                return;
//
//            events.Update(diff);
//
//            if (me->HasUnitState(UNIT_STATE_CASTING))
//                return;
//
//            while (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_GROWING_FURY:
//                {
//                    me->CastSpell(me, SPELL_GROWING_FURY, false);
//                    events.ScheduleEvent(EVENT_GROWING_FURY, urand(30000, 45000));
//                    break;
//                }
//                case EVENT_SPIRITFIRE_BEAM:
//                {
//                    me->CastSpell(me, SPELL_SPIRITFIRE_BEAM, false);
//                    events.ScheduleEvent(EVENT_SPIRITFIRE_BEAM, urand(15000, 20000));
//                    break;
//                }
//                case EVENT_FRILL_BLAST:
//                {
//                    me->CastSpell(me, SPELL_FRILL_BLAST, false);
//                    events.ScheduleEvent(EVENT_FRILL_BLAST, urand(40000, 55000));
//                    break;
//                }
//                case EVENT_PURSING_ROAR:
//                {
//                    me->CastSpell(me, SPELL_PURSING_ROAR, false);
//                    events.ScheduleEvent(EVENT_PURSING_ROAR, urand(16000, 26000));
//                    break;
//                }
//                case EVENT_CRUSH:
//                {
//                    me->CastSpell(me, SPELL_CRUSH, true);
//                    events.ScheduleEvent(EVENT_CRUSH, urand(10000, 23000));
//                    break;
//                }
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//    };
//};
//void AddSC_boss_galion()
//{
//    new boss_galion();
//    new npc_galion();
//    new boss_oondasta();
//}
