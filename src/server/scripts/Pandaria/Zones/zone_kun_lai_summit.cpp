#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"

enum eNessosSpells
{
    SPELL_VICIOUS_REND          = 125624,
    SPELL_GRAPPLING_HOOK        = 125623,
    SPELL_VANISH                = 125632,
    SPELL_SMOKED_BLADE          = 125633,
};

enum eNessosEvents
{
    EVENT_VICIOUS_REND          = 1,
    EVENT_GRAPPLING_HOOK        = 2,
    EVENT_VANISH                = 3,
    EVENT_SMOKED_BLADE          = 4,
};

enum Texts
{
    SAY_AHONE_WANDERER_AGGRO    = 0,
    SAY_SKITHIK_AGGRO           = 1,
    SAY_NESSOS_ORACLE_AGGRO     = 2,
    SAY_HAVAK_AGGRO             = 3,
    SAY_BORGINN_DARKFIST_AGGRO  = 4,
    SAY_KORDA_TORROS_AGGRO      = 5,
    SAY_ZAI_OUTCAST_AGGRO       = 6,
    SAY_SCRITCH_AGGRO           = 7
};

class mob_nessos_the_oracle : public CreatureScript
{
    public:
        mob_nessos_the_oracle() : CreatureScript("mob_nessos_the_oracle") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_nessos_the_oracleAI(creature);
        }

        struct mob_nessos_the_oracleAI : public ScriptedAI
        {
            mob_nessos_the_oracleAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap events;

            void Reset()
            {
                events.Reset();

                events.ScheduleEvent(EVENT_VICIOUS_REND, 7 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_GRAPPLING_HOOK, 17 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_VANISH, 12 * IN_MILLISECONDS);
            }

            void EnterCombat(Unit* /*who*/)
            {
                Talk(SAY_NESSOS_ORACLE_AGGRO);
            }

            void JustDied(Unit* /*killer*/) { }

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
                            events.ScheduleEvent(EVENT_VICIOUS_REND, 7 * IN_MILLISECONDS);
                            break;
                        case EVENT_GRAPPLING_HOOK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_GRAPPLING_HOOK, false);
                            events.ScheduleEvent(EVENT_GRAPPLING_HOOK, 17 * IN_MILLISECONDS);
                            break;
                        case EVENT_VANISH:
                            me->CastSpell(me, SPELL_VANISH, false);
                            events.ScheduleEvent(EVENT_VANISH, 20 * IN_MILLISECONDS);
                            events.ScheduleEvent(EVENT_SMOKED_BLADE, urand(0, 8) * IN_MILLISECONDS);
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

enum eAhoneWandererSpells
{
    SPELL_CHI_BURST                   =   125817,
    SPELL_HEALING_MIST                =   125802,
    SPELL_SPINNING_CRANE_KICK         =   125799
};

enum eAhoneWandererEvents
{
    EVENT_CHI_BURST                   = 1,
    EVENT_HEALING_MIST                = 2,
    EVENT_SPINNING_CRANE_KICK         = 3
};

class mob_ahone_the_wanderer : public CreatureScript
{
    public:
        mob_ahone_the_wanderer() : CreatureScript("mob_ahone_the_wanderer") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_ahone_the_wandererAI(creature);
        }

        struct mob_ahone_the_wandererAI : public ScriptedAI
        {
            mob_ahone_the_wandererAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap events;

            void Reset()
            {
                events.Reset();

                events.ScheduleEvent(EVENT_CHI_BURST, 10 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_HEALING_MIST, 15 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SPINNING_CRANE_KICK, 5 * IN_MILLISECONDS);          
            }

            void EnterCombat(Unit* /*who*/)
            {
                Talk(SAY_AHONE_WANDERER_AGGRO);
            }

            void JustDied(Unit* /*killer*/) { }

            void JustSummoned(Creature* summon)
            {
                summon->DespawnOrUnsummon(12 * IN_MILLISECONDS);
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
                        case EVENT_CHI_BURST:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_CHI_BURST, false);
                            events.ScheduleEvent(EVENT_CHI_BURST, 5 * IN_MILLISECONDS);
                            break;
                        case EVENT_HEALING_MIST:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_HEALING_MIST, false);
                            events.ScheduleEvent(EVENT_HEALING_MIST, 35 * IN_MILLISECONDS);
                            break;
                        case EVENT_SPINNING_CRANE_KICK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SPINNING_CRANE_KICK, false);
                            events.ScheduleEvent(EVENT_SPINNING_CRANE_KICK, 15 * IN_MILLISECONDS);
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
    SPELL_WINDSONG      = 125373
};

enum eSkiThikEvents
{
    EVENT_BLADE_FURY    = 1,
    EVENT_TORNADO       = 2,
    EVENT_WINDSONG      = 3
};

enum eSkiThikCreatures
{
    NPC_TORNADO_ST      = 64267
};

class mob_ski_thik : public CreatureScript
{
    public:
        mob_ski_thik() : CreatureScript("mob_ski_thik") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_ski_thikAI(creature);
        }

        struct mob_ski_thikAI : public ScriptedAI
        {
            mob_ski_thikAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap events;

            void Reset()
            {
                events.Reset();
                
                events.ScheduleEvent(EVENT_BLADE_FURY, 8 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_TORNADO, 40 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_WINDSONG, 32 * IN_MILLISECONDS);
            }

            void EnterCombat(Unit* /*who*/)
            {
                Talk(SAY_SKITHIK_AGGRO);
            }

            void JustDied(Unit* /*killer*/) { }

            void JustSummoned(Creature* summon)
            {
                if (summon->GetEntry() == NPC_TORNADO_ST)
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
                            events.ScheduleEvent(EVENT_BLADE_FURY, 8 * IN_MILLISECONDS);
                            break;
                        case EVENT_TORNADO:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_TORNADO, false);
                            events.ScheduleEvent(EVENT_TORNADO, 40 * IN_MILLISECONDS);
                            break;
                        case EVENT_WINDSONG:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_WINDSONG, false);
                            events.ScheduleEvent(EVENT_WINDSONG, 32 * IN_MILLISECONDS);
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
    SPELL_TITANIC_STRENGH      = 124976
};

enum eHavakEvents
{
    EVENT_DEVASTATING_ARC       = 1,
    EVENT_SUMMON_QUILEN         = 2,
    EVENT_TITANIC_STRENGH       = 3
};

class mob_havak : public CreatureScript
{
    public:
        mob_havak() : CreatureScript("mob_havak") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_havakAI(creature);
        }

        struct mob_havakAI : public ScriptedAI
        {
            mob_havakAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap events;

            void Reset()
            {
                events.Reset();

                events.ScheduleEvent(EVENT_DEVASTATING_ARC, 50 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SUMMON_QUILEN, 15 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_TITANIC_STRENGH, 32 * IN_MILLISECONDS);
            }

            void EnterCombat(Unit* /*who*/)
            {
                Talk(SAY_HAVAK_AGGRO);
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
                            events.ScheduleEvent(EVENT_DEVASTATING_ARC, 50 * IN_MILLISECONDS);
                            break;
                        case EVENT_SUMMON_QUILEN:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SUMMON_QUILEN, false);
                            events.ScheduleEvent(EVENT_SUMMON_QUILEN, 80 * IN_MILLISECONDS);
                            break;
                        case EVENT_TITANIC_STRENGH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_TITANIC_STRENGH, false);
                            events.ScheduleEvent(EVENT_TITANIC_STRENGH, 40 * IN_MILLISECONDS);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eBorginnDarkfistSpells
{
    SPELL_SHADOWBOLT = 125212,
    SPELL_VOIDCLOUD  = 125241
};

enum eBorginnDarkfistEvents
{
    EVENT_SHADOWBOLT = 1,
    EVENT_VOIDCLOUD  = 2
};

class mob_borginn_darkfist : public CreatureScript
{
public:
    mob_borginn_darkfist() : CreatureScript("mob_borginn_darkfist") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_borginn_darkfistAI(creature);
    }

    struct mob_borginn_darkfistAI : public ScriptedAI
    {
        mob_borginn_darkfistAI(Creature* creature) : ScriptedAI(creature) { }

        EventMap events;

        void Reset()
        {
            events.Reset();

            events.ScheduleEvent(EVENT_SHADOWBOLT, 50 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_VOIDCLOUD, 15 * IN_MILLISECONDS);
        }

        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_BORGINN_DARKFIST_AGGRO);
        }

        void JustDied(Unit* /*killer*/) { }

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
                case EVENT_SHADOWBOLT:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_SHADOWBOLT, false);
                    events.ScheduleEvent(EVENT_SHADOWBOLT, 70 * IN_MILLISECONDS);
                    break;
                case EVENT_VOIDCLOUD:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_VOIDCLOUD, false);
                    events.ScheduleEvent(EVENT_VOIDCLOUD, 35 * IN_MILLISECONDS);
                    break;
                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

enum eScritchSpells
{
    SPELL_GOING_BANANAS = 125363,
    SPELL_BANANARANG    = 125311,
    SPELL_TOSS_FILTH    = 125365
};

enum eScritchEvents
{
    EVENT_GOING_BANANAS = 1,
    EVENT_BANANARANG    = 2,
    EVENT_TOSS_FILTH    = 3
};

class mob_scritch : public CreatureScript
{
public:
    mob_scritch() : CreatureScript("mob_scritch") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_scritchAI(creature);
    }

    struct mob_scritchAI : public ScriptedAI
    {
        mob_scritchAI(Creature* creature) : ScriptedAI(creature) { }

        EventMap events;

        void Reset()
        {
            events.Reset();

            events.ScheduleEvent(EVENT_GOING_BANANAS, 12 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_BANANARANG, 8 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_TOSS_FILTH, 15 * IN_MILLISECONDS);
        }

        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_SCRITCH_AGGRO);
        }

        void JustDied(Unit* /*killer*/) { }

        void JustSummoned(Creature* summon)
        {
            summon->DespawnOrUnsummon(12 * IN_MILLISECONDS);
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
                case EVENT_GOING_BANANAS:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_GOING_BANANAS, false);
                    events.ScheduleEvent(EVENT_GOING_BANANAS, 10 * IN_MILLISECONDS);
                    break;
                case EVENT_BANANARANG:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_BANANARANG, false);
                    events.ScheduleEvent(EVENT_BANANARANG, 20 * IN_MILLISECONDS);
                    break;
                case EVENT_TOSS_FILTH:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_TOSS_FILTH, false);
                    events.ScheduleEvent(EVENT_TOSS_FILTH, 15 * IN_MILLISECONDS);
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
    SPELL_DRAIN_LIFE        = 84533,
    SPELL_SHADOW_BOLT       = 9613,
    SPELL_SHADOW_CRASH      = 129132
};

enum eMogujiaSoulCallerEvents
{
    EVENT_DRAIN_LIFE        = 1,
    EVENT_SHADOW_BOLT       = 2,
    EVENT_SHADOW_CRASH      = 3
};

class mob_mogujia_soul_caller : public CreatureScript
{
    public:
        mob_mogujia_soul_caller() : CreatureScript("mob_mogujia_soul_caller") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_mogujia_soul_callerAI(creature);
        }

        struct mob_mogujia_soul_callerAI : public ScriptedAI
        {
            mob_mogujia_soul_callerAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap events;

            void Reset()
            {
                events.Reset();
                
                events.ScheduleEvent(EVENT_DRAIN_LIFE, 20 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SHADOW_BOLT, 15 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SHADOW_CRASH, 32 * IN_MILLISECONDS);
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
                            events.ScheduleEvent(EVENT_DRAIN_LIFE, 20 * IN_MILLISECONDS);
                            break;
                        case EVENT_SHADOW_BOLT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SHADOW_BOLT, false);
                            events.ScheduleEvent(EVENT_SHADOW_BOLT, 15 * IN_MILLISECONDS);
                            break;
                        case EVENT_SHADOW_CRASH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_SHADOW_CRASH, false);
                            events.ScheduleEvent(EVENT_SHADOW_CRASH, 32 * IN_MILLISECONDS);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eKordaTorrosSpells
{
    SPELL_BELLOWING_RAGE        =   124297,
    SPELL_EMPOWERING_FLAMES     =   130388,
    SPELL_HOOF_STOMP            =   124289,
    SPELL_RUSHING_CHARGE        =   124302
};

enum eKordaTorrosEvents
{
    EVENT_BELLOWING_RAGE        = 1,
    EVENT_EMPOWERING_FLAMES     = 2,
    EVENT_HOOF_STOMP            = 3,    
    EVENT_RUSHING_CHARGE        = 4
};

class mob_korda_torros : public CreatureScript
{
    public:
        mob_korda_torros() : CreatureScript("mob_korda_torros") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_korda_torrosAI(creature);
        }

        struct mob_korda_torrosAI : public ScriptedAI
        {
            mob_korda_torrosAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap events;

            void Reset()
            {
                events.Reset();

                events.ScheduleEvent(EVENT_BELLOWING_RAGE, 20 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_HOOF_STOMP, 10 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_RUSHING_CHARGE, 10 * IN_MILLISECONDS);            
            }

            void EnterCombat(Unit* /*who*/)
            {
                Talk(SAY_KORDA_TORROS_AGGRO);
            }

            void JustDied(Unit* /*killer*/) { }

            void JustSummoned(Creature* summon)
            {
                summon->DespawnOrUnsummon(12 * IN_MILLISECONDS);
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
                        case EVENT_BELLOWING_RAGE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_BELLOWING_RAGE, false);
                            events.ScheduleEvent(EVENT_BELLOWING_RAGE, 30 * IN_MILLISECONDS);
                            break;
                        case EVENT_HOOF_STOMP:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_HOOF_STOMP, false);
                            events.ScheduleEvent(EVENT_HOOF_STOMP, 15 * IN_MILLISECONDS);
                            break;
                        case EVENT_RUSHING_CHARGE:
                                if(Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                    me->CastSpell(target, SPELL_RUSHING_CHARGE, false);
                                events.ScheduleEvent(EVENT_RUSHING_CHARGE, 10 * IN_MILLISECONDS);
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
    SPELL_UNSTABLE_SERUM        =  127373
};

enum eQuilenStonemawEvents
{
    EVENT_UNSTABLE_SERUM        = 1
};

class mob_quilen_stonemaw : public CreatureScript
{
    public:
        mob_quilen_stonemaw() : CreatureScript("mob_quilen_stonemaw") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_quilen_stonemawAI(creature);
        }

        struct mob_quilen_stonemawAI : public ScriptedAI
        {
            mob_quilen_stonemawAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap events;

            void Reset()
            {
                events.Reset();

                events.ScheduleEvent(EVENT_UNSTABLE_SERUM, 5 * IN_MILLISECONDS);
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
                            events.ScheduleEvent(EVENT_UNSTABLE_SERUM, 5 * IN_MILLISECONDS);
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
    SPELL_WATER_BOLT    = 124854
};

enum eZaiTheOutcastEvents
{
    EVENT_RAIN_DANCE    = 1,
    EVENT_TORRENT       = 2,
    EVENT_WATER_BOLT    = 3
};

enum eZaiTheOutcastCreatures
{
    NPC_TORNADO_ZTO     = 64267
};

class mob_zai_the_outcast : public CreatureScript
{
    public:
        mob_zai_the_outcast() : CreatureScript("mob_zai_the_outcast") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_zai_the_outcastAI(creature);
        }

        struct mob_zai_the_outcastAI : public ScriptedAI
        {
            mob_zai_the_outcastAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap events;

            void Reset()
            {
                events.Reset();

                events.ScheduleEvent(EVENT_RAIN_DANCE, 8 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_TORRENT, 40 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_WATER_BOLT, 32 * IN_MILLISECONDS);
            }

            void EnterCombat(Unit* /*who*/)
            {
                Talk(SAY_ZAI_OUTCAST_AGGRO);
            }

            void JustDied(Unit* /*killer*/) { }

            void JustSummoned(Creature* summon)
            {
                if (summon->GetEntry() == NPC_TORNADO_ZTO)
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
                            events.ScheduleEvent(EVENT_RAIN_DANCE, 8 * IN_MILLISECONDS);
                            break;
                        case EVENT_TORRENT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_TORRENT, false);
                            events.ScheduleEvent(EVENT_TORRENT, 40 * IN_MILLISECONDS);
                            break;
                        case EVENT_WATER_BOLT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_WATER_BOLT, false);
                            events.ScheduleEvent(EVENT_WATER_BOLT, 32 * IN_MILLISECONDS);
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
    new mob_ahone_the_wanderer();
    new mob_scritch();
    new mob_korda_torros();
    new mob_borginn_darkfist();
    new mob_nessos_the_oracle();
    new mob_ski_thik();
    new mob_havak();
    new mob_mogujia_soul_caller();
    new mob_quilen_stonemaw();
    new mob_zai_the_outcast();
}
