#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"

enum eNessosSpells
{
    SPELL_VICIOUS_REND        = 125624,
    SPELL_GRAPPLING_HOOK      = 125623,
    SPELL_VANISH              = 125632,
    SPELL_SMOKED_BLADE        = 125633,
};

enum eNessosEvents
{
    EVENT_VICIOUS_REND        = 1,
    EVENT_GRAPPLING_HOOK      = 2,
    EVENT_VANISH              = 3,
    EVENT_SMOKED_BLADE        = 4,
};

class mob_nessos_the_oracle : public CreatureScript
{
    public:
        mob_nessos_the_oracle() : CreatureScript("mob_nessos_the_oracle") 
		{ 
		}

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_nessos_the_oracleAI(creature);
        }

        struct mob_nessos_the_oracleAI : public ScriptedAI
        {
            mob_nessos_the_oracleAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset()
            {
                events.Reset();
                
                events.ScheduleEvent(EVENT_VICIOUS_REND,      7000);
                events.ScheduleEvent(EVENT_GRAPPLING_HOOK, 17000);
                events.ScheduleEvent(EVENT_VANISH, 12000);
            }

            void JustDied(Unit* /*killer*/)
            {
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);
                

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_VICIOUS_REND:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_VICIOUS_REND, false);
                            events.ScheduleEvent(EVENT_VICIOUS_REND,      7000);
                            break;
                        case EVENT_GRAPPLING_HOOK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_GRAPPLING_HOOK, false);
                            events.ScheduleEvent(EVENT_GRAPPLING_HOOK, 17000);
                            break;
                        case EVENT_VANISH:
                            me->CastSpell(me, SPELL_VANISH, false);
                            events.ScheduleEvent(EVENT_VANISH, 20000);
                            events.ScheduleEvent(EVENT_SMOKED_BLADE, urand(0, 8000));
                            break;
                        case EVENT_SMOKED_BLADE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SMOKED_BLADE, false);

                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eSkiThikSpells
{
    SPELL_BLADE_FURY    = 125370,
    SPELL_TORNADO       = 125398,
    SPELL_TORNADO_DMG   = 131693,
    SPELL_WINDSONG      = 125373,
};

enum eSkiThikEvents
{
    EVENT_BLADE_FURY    = 1,
    EVENT_TORNADO       = 2,
    EVENT_WINDSONG      = 3,
};

class mob_ski_thik : public CreatureScript
{
    public:
        mob_ski_thik() : CreatureScript("mob_ski_thik") 
		{ 
		}

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_ski_thikAI(creature);
        }

        struct mob_ski_thikAI : public ScriptedAI
        {
            mob_ski_thikAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset()
            {
                events.Reset();
                
                events.ScheduleEvent(EVENT_BLADE_FURY,       8000);
                events.ScheduleEvent(EVENT_TORNADO,         40000);
                events.ScheduleEvent(EVENT_WINDSONG,        32000);
            }

            void JustDied(Unit* /*killer*/)
            {
            }

            void JustSummoned(Creature* summon)
            {
                if (summon->GetEntry() == 64267)
                {
                    summon->AddAura(SPELL_TORNADO_DMG, summon);
                    summon->SetReactState(REACT_PASSIVE);
                    summon->GetMotionMaster()->MoveRandom(20.0f);
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);
                

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BLADE_FURY:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_BLADE_FURY, false);
                            events.ScheduleEvent(EVENT_BLADE_FURY,      8000);
                            break;
                        case EVENT_TORNADO:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_TORNADO, false);
                            events.ScheduleEvent(EVENT_TORNADO, 40000);
                            break;
                        case EVENT_WINDSONG:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_WINDSONG, false);
                            events.ScheduleEvent(EVENT_WINDSONG, 32000);
                            break;

                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eHavakSpells
{
    SPELL_DEVASTATING_ARC      = 124946,
    SPELL_SUMMON_QUILEN        = 124980,
    SPELL_TITANIC_STRENGH      = 124976,
};

enum eHavakEvents
{
    EVENT_DEVASTATING_ARC		= 1,
    EVENT_SUMMON_QUILEN         = 2,
    EVENT_TITANIC_STRENGH       = 3,
};

class mob_havak : public CreatureScript
{
    public:
        mob_havak() : CreatureScript("mob_havak")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_havakAI(creature);
        }

        struct mob_havakAI : public ScriptedAI
        {
            mob_havakAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset()
            {
                events.Reset();

                events.ScheduleEvent(EVENT_DEVASTATING_ARC,   50000);
                events.ScheduleEvent(EVENT_SUMMON_QUILEN,     15000);
                events.ScheduleEvent(EVENT_TITANIC_STRENGH,   32000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_DEVASTATING_ARC:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_DEVASTATING_ARC, false);
                            events.ScheduleEvent(EVENT_DEVASTATING_ARC,      50000);
                            break;
                        case EVENT_SUMMON_QUILEN:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SUMMON_QUILEN, false);
                            events.ScheduleEvent(EVENT_SUMMON_QUILEN, 80000);
                            break;
                        case EVENT_TITANIC_STRENGH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_TITANIC_STRENGH, false);
                            events.ScheduleEvent(EVENT_TITANIC_STRENGH, 40000);
                            break;

                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eMogujiaSoulCallerSpells
{
    SPELL_DRAIN_LIFE        =  84533,
    SPELL_SHADOW_BOLT       =   9613,
    SPELL_SHADOW_CRASH      = 129132,
};

enum eMogujiaSoulCallerEvents
{
    EVENT_DRAIN_LIFE		= 1,
    EVENT_SHADOW_BOLT       = 2,
    EVENT_SHADOW_CRASH      = 3,
};

class mob_mogujia_soul_caller : public CreatureScript
{
    public:
        mob_mogujia_soul_caller() : CreatureScript("mob_mogujia_soul_caller") 
		{ 
		}

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_mogujia_soul_callerAI(creature);
        }

        struct mob_mogujia_soul_callerAI : public ScriptedAI
        {
            mob_mogujia_soul_callerAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset()
            {
                events.Reset();
                
                events.ScheduleEvent(EVENT_DRAIN_LIFE,      20000);
                events.ScheduleEvent(EVENT_SHADOW_BOLT,     15000);
                events.ScheduleEvent(EVENT_SHADOW_CRASH,    32000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);
                
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_DRAIN_LIFE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_DRAIN_LIFE, false);
                            events.ScheduleEvent(EVENT_DRAIN_LIFE,      20000);
                            break;
                        case EVENT_SHADOW_BOLT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SHADOW_BOLT, false);
                            events.ScheduleEvent(EVENT_SHADOW_BOLT, 15000);
                            break;
                        case EVENT_SHADOW_CRASH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_SHADOW_CRASH, false);
                            events.ScheduleEvent(EVENT_SHADOW_CRASH, 32000);
                            break;
							
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eQuilenStonemawSpells
{
    SPELL_UNSTABLE_SERUM        =  127373,
};

enum eQuilenStonemawEvents
{
    EVENT_UNSTABLE_SERUM		= 1,
};

class mob_quilen_stonemaw : public CreatureScript
{
    public:
        mob_quilen_stonemaw() : CreatureScript("mob_quilen_stonemaw")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_quilen_stonemawAI(creature);
        }

        struct mob_quilen_stonemawAI : public ScriptedAI
        {
            mob_quilen_stonemawAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset()
            {
                events.Reset();
                events.ScheduleEvent(EVENT_UNSTABLE_SERUM,      5000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_UNSTABLE_SERUM:
                            if (Unit* target = me->SelectNearestTarget(5.0f))
                                me->CastSpell(target, SPELL_UNSTABLE_SERUM, false);
                            events.ScheduleEvent(EVENT_UNSTABLE_SERUM,      5000);
                            break;

                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eZaiTheOutcastSpells
{
    SPELL_RAIN_DANCE    = 124860,
    SPELL_TORRENT       = 124935,
    SPELL_WATER_BOLT    = 124854,
};

enum eZaiTheOutcastEvents
{
    EVENT_RAIN_DANCE    = 1,
    EVENT_TORRENT       = 2,
    EVENT_WATER_BOLT    = 3,
};

class mob_zai_the_outcast : public CreatureScript
{
    public:
        mob_zai_the_outcast() : CreatureScript("mob_zai_the_outcast")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_zai_the_outcastAI(creature);
        }

        struct mob_zai_the_outcastAI : public ScriptedAI
        {
            mob_zai_the_outcastAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset()
            {
                events.Reset();

                events.ScheduleEvent(EVENT_RAIN_DANCE,       8000);
                events.ScheduleEvent(EVENT_TORRENT,         40000);
                events.ScheduleEvent(EVENT_WATER_BOLT,      32000);
            }

            void JustDied(Unit* /*killer*/)
            {
            }

            void JustSummoned(Creature* summon)
            {
                if (summon->GetEntry() == 64267)
                {
                    summon->AddAura(SPELL_TORNADO_DMG, summon);
                    summon->SetReactState(REACT_PASSIVE);
                    summon->GetMotionMaster()->MoveRandom(20.0f);
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_RAIN_DANCE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_RAIN_DANCE, false);
                            events.ScheduleEvent(EVENT_RAIN_DANCE,      8000);
                            break;
                        case EVENT_TORRENT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_TORRENT, false);
                            events.ScheduleEvent(EVENT_TORRENT, 40000);
                            break;
                        case EVENT_WATER_BOLT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_WATER_BOLT, false);
                            events.ScheduleEvent(EVENT_WATER_BOLT, 32000);
                            break;

                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

void AddSC_kun_lai_summit()
{
    new mob_nessos_the_oracle();
    new mob_ski_thik();
    new mob_havak();
    new mob_mogujia_soul_caller();
    new mob_quilen_stonemaw();
    new mob_zai_the_outcast();
}
