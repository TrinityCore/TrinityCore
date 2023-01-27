#include "ScriptMgr.h"
#include "SpellScript.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"

enum eKahTirSpells
{
    SPELL_DEVASTATING_ARC       = 124946,
    SPELL_SUMMON_QUILEN         = 124980,
    SPELL_TITANIC_STRENGTH      = 124976
};

enum eKahTirEvents
{
    EVENT_DEVASTATING_ARC       = 1,
    EVENT_SUMMON_QUILEN         = 2,
    EVENT_TITANIC_STRENGTH      = 3
};

enum Texts
{
    SAY_KAHTIR_AGGRO            = 0,
    SAY_LONBULL_AGGRO           = 1,
    SAY_YUL_AGGRO               = 2,
    SAY_NORLAXX_AGGRO           = 3,
    SAY_SILTRISS_AGGRO          = 4,
    SAY_LITHIK_AGGRO            = 5,
    SAY_ESHOLON_AGGRO           = 6,
    SAY_YOWLER_AGGRO            = 7
};

class mob_kah_tir : public CreatureScript
{
    public:
        mob_kah_tir() : CreatureScript("mob_kah_tir") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_kah_tirAI(creature);
        }

        struct mob_kah_tirAI : public ScriptedAI
        {
            mob_kah_tirAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap events;

            void Reset()
            {
                events.Reset();

                events.ScheduleEvent(EVENT_DEVASTATING_ARC, 40000);
                events.ScheduleEvent(EVENT_SUMMON_QUILEN, 12000);
                events.ScheduleEvent(EVENT_TITANIC_STRENGTH, 20000);
            }

            void EnterCombat(Unit* /*who*/)
            {
                Talk(SAY_KAHTIR_AGGRO);
            };

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
                        case EVENT_DEVASTATING_ARC:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_DEVASTATING_ARC, false);
                            events.ScheduleEvent(EVENT_DEVASTATING_ARC, 60000);
                            break;
                        case EVENT_SUMMON_QUILEN:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SUMMON_QUILEN, false);
                            events.ScheduleEvent(EVENT_SUMMON_QUILEN, 50000);
                            break;
                        case EVENT_TITANIC_STRENGTH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_TITANIC_STRENGTH, false);
                            events.ScheduleEvent(EVENT_TITANIC_STRENGTH, 30000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eLonBullSpells
{
    SPELL_BELLOWING_RAGE        =   124297,
    SPELL_EMPOWERING_FLAMES     =   130388,
    SPELL_HOOF_STOMP            =   124289,
    SPELL_RUSHING_CHARGE        =   124302
};

enum eLonBullEvents
{
    EVENT_BELLOWING_RAGE        = 1,
    EVENT_EMPOWERING_FLAMES     = 2,
    EVENT_HOOF_STOMP            = 3,    
    EVENT_RUSHING_CHARGE        = 4
};

class mob_lon_bull : public CreatureScript
{
    public:
        mob_lon_bull() : CreatureScript("mob_lon_bull")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_lon_bullAI(creature);
        }

        struct mob_lon_bullAI : public ScriptedAI
        {
            mob_lon_bullAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap events;

            void Reset()
            {
                events.Reset();

                events.ScheduleEvent(EVENT_BELLOWING_RAGE, 20000);
                events.ScheduleEvent(EVENT_EMPOWERING_FLAMES, 15000);
                events.ScheduleEvent(EVENT_HOOF_STOMP, 10000);
                events.ScheduleEvent(EVENT_RUSHING_CHARGE, 10000);            
            }

            void EnterCombat(Unit* /*who*/)
            {
                Talk(SAY_LONBULL_AGGRO);
            }

            void JustDied(Unit* /*killer*/) { }

            void JustSummoned(Creature* summon)
            {
                summon->DespawnOrUnsummon(12000);
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
                            events.ScheduleEvent(EVENT_BELLOWING_RAGE,       30000);
                            break;
                        case EVENT_EMPOWERING_FLAMES:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_EMPOWERING_FLAMES, false);
                            events.ScheduleEvent(EVENT_EMPOWERING_FLAMES, 15000);
                            break;
                        case EVENT_HOOF_STOMP:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_HOOF_STOMP, false);
                            events.ScheduleEvent(EVENT_HOOF_STOMP, 15000);
                            break;
                        case EVENT_RUSHING_CHARGE:
                                if(Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                    me->CastSpell(target, SPELL_RUSHING_CHARGE, false);
                                events.ScheduleEvent(EVENT_RUSHING_CHARGE, 10000);
                                break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eYulWildpawSpells
{
    SPELL_CHI_BURST                     =   125817,
    SPELL_HEALING_MIST                  =   125802,
    SPELL_SPINNING_CRANE_KICK           =   125799
};

enum eYulWildpawEvents
{
    EVENT_CHI_BURST                     = 1,
    EVENT_HEALING_MIST                  = 2,
    EVENT_SPINNING_CRANE_KICK           = 3
};

class mob_yul_wildpaw : public CreatureScript
{
    public:
        mob_yul_wildpaw() : CreatureScript("mob_yul_wildpaw") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_yul_wildpawAI(creature);
        }

        struct mob_yul_wildpawAI : public ScriptedAI
        {
            mob_yul_wildpawAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap events;

            void Reset()
            {
                events.Reset();

                events.ScheduleEvent(EVENT_CHI_BURST, 10000);
                events.ScheduleEvent(EVENT_HEALING_MIST, 15000);
                events.ScheduleEvent(EVENT_SPINNING_CRANE_KICK, 5000);          
            }
            void EnterCombat(Unit* /*who*/)
            {
                Talk(SAY_YUL_AGGRO);
            };

            void JustDied(Unit* /*killer*/) { }

            void JustSummoned(Creature* summon)
            {
                summon->DespawnOrUnsummon(12000);
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
                            events.ScheduleEvent(EVENT_CHI_BURST, 5000);
                            break;
                        case EVENT_HEALING_MIST:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_HEALING_MIST, false);
                            events.ScheduleEvent(EVENT_HEALING_MIST, 35000);
                            break;
                        case EVENT_SPINNING_CRANE_KICK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SPINNING_CRANE_KICK, false);
                            events.ScheduleEvent(EVENT_SPINNING_CRANE_KICK, 15000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eNorlaxxSpells
{
    SPELL_SHADOWBOLT       = 125212,
    SPELL_VOIDCLOUD        = 125241
};

enum eNorlaxxEvents
{
    EVENT_SHADOWBOLT       = 1,
    EVENT_VOIDCLOUD        = 2
};

class mob_norlaxx : public CreatureScript
{
    public:
        mob_norlaxx() : CreatureScript("mob_norlaxx") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_norlaxxAI(creature);
        }

        struct mob_norlaxxAI : public ScriptedAI
        {
            mob_norlaxxAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap events;

            void Reset()
            {
                events.Reset();

                events.ScheduleEvent(EVENT_SHADOWBOLT, 5000);
                events.ScheduleEvent(EVENT_VOIDCLOUD, 15000);
            }

            void EnterCombat(Unit* /*who*/)
            {
                Talk(SAY_NORLAXX_AGGRO);
            };

            void JustDied(Unit* /*killer*/) { }

            void JustSummoned(Creature* summon)
            {
                summon->DespawnOrUnsummon(12000);
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
                        case EVENT_SHADOWBOLT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SHADOWBOLT, false);
                            events.ScheduleEvent(EVENT_SHADOWBOLT, 5000);
                            break;
                        case EVENT_VOIDCLOUD:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_VOIDCLOUD, false);
                            events.ScheduleEvent(EVENT_VOIDCLOUD, 15000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eSiltrissSpells
{
    SPELL_GRAPPLING_HOOK        = 125623,
    SPELL_VANISH                = 125632,
    SPELL_VICIOUS_REND          = 125624,
    SPELL_SMOKED_BLADE          = 125633
};

enum eSiltrissEvents
{
    EVENT_GRAPPLING_HOOK        = 1,
    EVENT_VANISH                = 2,
    EVENT_VICIOUS_REND          = 3,
    EVENT_SMOKED_BLADE          = 4
};

class mob_siltriss_sharpener : public CreatureScript
{
    public:
        mob_siltriss_sharpener() : CreatureScript("mob_siltriss_sharpener") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_siltriss_sharpenerAI(creature);
        }

        struct mob_siltriss_sharpenerAI : public ScriptedAI
        {
            mob_siltriss_sharpenerAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap events;

            void Reset()
            {
                events.Reset();

                events.ScheduleEvent(EVENT_GRAPPLING_HOOK, 17000);
                events.ScheduleEvent(EVENT_VANISH, 12000);
                events.ScheduleEvent(EVENT_VICIOUS_REND, 7000);
            }

            void EnterCombat(Unit* /*who*/)
            {
                Talk(SAY_SILTRISS_AGGRO);
            };

            void JustDied(Unit* /*killer*/) { }

            void JustSummoned(Creature* summon)
            {
                summon->DespawnOrUnsummon(12000);
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
                        case EVENT_GRAPPLING_HOOK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_GRAPPLING_HOOK, false);
                            events.ScheduleEvent(EVENT_GRAPPLING_HOOK, 5000);
                            break;
                        case EVENT_VANISH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_VANISH, false);
                            events.ScheduleEvent(EVENT_VANISH, 30000);
                            events.ScheduleEvent(EVENT_SMOKED_BLADE, urand(0, 8000));
                            break;
                        case EVENT_SMOKED_BLADE:
							if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
								me->CastSpell(target, SPELL_SMOKED_BLADE, false);
								events.ScheduleEvent(EVENT_SMOKED_BLADE, 31500);
                        case EVENT_VICIOUS_REND:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_VICIOUS_REND, false);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eYowlerSpells
{
    SPELL_BANANA_RANG       = 125311,
    SPELL_GOING_BANANAS     = 125363,
    SPELL_TOSS_FILTH        = 125365
};

enum eYowlerEvents
{
    EVENT_BANANA_RANG       = 1,
    EVENT_GOING_BANANAS     = 2,
    EVENT_TOSS_FILTH        = 3
};

class mob_yowler : public CreatureScript
{
    public:
        mob_yowler() : CreatureScript("mob_yowler") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_yowlerAI(creature);
        }

        struct mob_yowlerAI : public ScriptedAI
        {
            mob_yowlerAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap events;

            void Reset()
            {
                events.Reset();

                events.ScheduleEvent(EVENT_BANANA_RANG, 8000);
                events.ScheduleEvent(EVENT_GOING_BANANAS, 12000);
                events.ScheduleEvent(EVENT_TOSS_FILTH, 15000);
            }

            void EnterCombat(Unit* /*who*/)
            {
               Talk(SAY_YOWLER_AGGRO); 
            };

            void JustDied(Unit* /*killer*/) { }

            void JustSummoned(Creature* summon)
            {
                summon->DespawnOrUnsummon(12000);
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
                        case EVENT_BANANA_RANG:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_BANANA_RANG, false);
                            events.ScheduleEvent(EVENT_BANANA_RANG, 10000);
                            break;
                        case EVENT_GOING_BANANAS:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_GOING_BANANAS, false);
                            events.ScheduleEvent(EVENT_GOING_BANANAS, 20000);
                            break;
                        case EVENT_TOSS_FILTH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_TOSS_FILTH, false);
                            events.ScheduleEvent(EVENT_TOSS_FILTH, 15000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eLithIkSpells
{
    SPELL_BLADE_FURY       = 125370,
    SPELL_TORNADO          = 125398,
    SPELL_TORNADO_DMG      = 131693,
    SPELL_WINDSONG         = 125373
};

enum eLithIkEvents
{
    EVENT_BLADE_FURY       = 1,
    EVENT_TORNADO          = 2,
    EVENT_WINDSONG         = 3
};

class mob_lith_ik : public CreatureScript
{
    public:
        mob_lith_ik() : CreatureScript("mob_lith_ik") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_lith_ikAI(creature);
        }

        struct mob_lith_ikAI : public ScriptedAI
        {
            mob_lith_ikAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap events;

            void Reset()
            {
                events.Reset();

                events.ScheduleEvent(EVENT_TORNADO, 5000);
                events.ScheduleEvent(EVENT_BLADE_FURY, 25000);
                events.ScheduleEvent(EVENT_WINDSONG, 30000);
            }

            void EnterCombat(Unit* /*who*/)
            {
                Talk(SAY_LITHIK_AGGRO);
            }

            void JustSummoned(Creature* summon)
            {
                if (summon->GetEntry() == 64267)
                {
                    summon->DespawnOrUnsummon(15000);
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
                        case EVENT_TORNADO:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_TORNADO, false);
                            events.ScheduleEvent(EVENT_TORNADO, 70000);
                            break;
                        case EVENT_BLADE_FURY:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_BLADE_FURY, false);
                            events.ScheduleEvent(EVENT_BLADE_FURY, 30000);
                            break;
                        case EVENT_WINDSONG:
                            me->CastSpell(me, SPELL_WINDSONG, false);
                            events.ScheduleEvent(EVENT_WINDSONG, 25000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eDarkwoodsFaerieSpells
{
    SPELL_DISGUISE         = 121308,
    SPELL_FAE_SPIRIT       = 122567,
    SPELL_NIGHT_SKY        = 123318,
    SPELL_STARSURGE        = 123330
};

enum eDarkwoodsFaerieEvents
{
    EVENT_DISGUISE          = 1,
    EVENT_FAE_SPIRIT        = 2,
    EVENT_NIGHT_SKY         = 3,
    EVENT_STARSURGE         = 4
};

class mob_darkwoods_faerie : public CreatureScript
{
    public:
        mob_darkwoods_faerie() : CreatureScript("mob_darkwoods_faerie") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_darkwoods_faerieAI(creature);
        }

        struct mob_darkwoods_faerieAI : public ScriptedAI
        {
            mob_darkwoods_faerieAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap events;

            void Reset()
            {
                events.Reset();

                events.ScheduleEvent(EVENT_DISGUISE, 5000);
                events.ScheduleEvent(EVENT_FAE_SPIRIT, 15000);
                events.ScheduleEvent(EVENT_NIGHT_SKY, 22000);
                events.ScheduleEvent(EVENT_STARSURGE, 30000);
            }

            void JustSummoned(Creature* summon)
            {
                if (summon->GetEntry() == 64267)
                {
                    summon->DespawnOrUnsummon(15000);
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
                        case EVENT_DISGUISE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(me, SPELL_DISGUISE, false);
                            events.ScheduleEvent(EVENT_DISGUISE, 70000);
                            break;
                        case EVENT_FAE_SPIRIT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_FAE_SPIRIT, false);
                            events.ScheduleEvent(EVENT_FAE_SPIRIT, 15000);
                            break;
                        case EVENT_NIGHT_SKY:
                            me->CastSpell(me, SPELL_NIGHT_SKY, false);
                            events.ScheduleEvent(EVENT_NIGHT_SKY, 22000);
                            break;
                        case EVENT_STARSURGE:
                            me->CastSpell(me, SPELL_STARSURGE, false);
                            events.ScheduleEvent(EVENT_STARSURGE, 30000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eHeiFengSpells
{
    SPELL_DEEP_BREATH          = 125030,
    SPELL_SERPENT_SWEEP        = 125063,
    SPELL_SHADOW_DETONATION    = 124956
};

enum eHeiFengEvents
{
    EVENT_DEEP_BREATH          = 1,
    EVENT_SERPENT_SWEEP        = 2,
    EVENT_SHADOW_DETONATION    = 3
};

class mob_hei_feng : public CreatureScript
{
    public:
        mob_hei_feng() : CreatureScript("mob_hei_feng") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_hei_fengAI(creature);
        }

        struct mob_hei_fengAI : public ScriptedAI
        {
            mob_hei_fengAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap events;

            void Reset()
            {
                events.Reset();

                events.ScheduleEvent(EVENT_DEEP_BREATH, 5000);
                events.ScheduleEvent(EVENT_SERPENT_SWEEP, 15000);
                events.ScheduleEvent(EVENT_SHADOW_DETONATION, 22000);
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
                        case EVENT_DEEP_BREATH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_DEEP_BREATH, false);
                            events.ScheduleEvent(EVENT_DEEP_BREATH, 30000);
                            break;
                        case EVENT_SERPENT_SWEEP:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SERPENT_SWEEP, false);
                            events.ScheduleEvent(EVENT_SERPENT_SWEEP, 15000);
                            break;
                        case EVENT_SHADOW_DETONATION:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SHADOW_DETONATION, false);
                            events.ScheduleEvent(EVENT_SHADOW_DETONATION, 22000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eEshelonSpells
{
    SPELL_RAIN_DANCE    = 124860,
    SPELL_TORRENT       = 124935,
    SPELL_WATER_BOLT    = 124854
};

enum eEshelonEvents
{
    EVENT_RAIN_DANCE        = 1,
    EVENT_TORRENT           = 2,
    EVENT_WATER_BOLT        = 3
};

class mob_eshelon : public CreatureScript
{
    public:
        mob_eshelon() : CreatureScript("mob_eshelon") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_eshelonAI(creature);
        }

        struct mob_eshelonAI : public ScriptedAI
        {
            mob_eshelonAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap events;

            void Reset()
            {
                events.Reset();
                
                events.ScheduleEvent(EVENT_RAIN_DANCE, 5000);
                events.ScheduleEvent(EVENT_TORRENT, 15000);
                events.ScheduleEvent(EVENT_WATER_BOLT, 25000);
            }

            void EnterCombat(Unit* /*who*/)
            {
                Talk(SAY_ESHOLON_AGGRO);
            }

            void JustDied(Unit* /*killer*/) { }

            void JustSummoned(Creature* summon)
            {
                summon->DespawnOrUnsummon(12000);
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
                            events.ScheduleEvent(EVENT_RAIN_DANCE, 25000);
                            break;
                        case EVENT_TORRENT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_TORRENT, false);
                            events.ScheduleEvent(EVENT_TORRENT, 15000);
                            break;
                        case EVENT_WATER_BOLT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_WATER_BOLT, false);
                            events.ScheduleEvent(EVENT_WATER_BOLT, 10000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

class mob_restless_leng : public CreatureScript
{
    public:
        mob_restless_leng() : CreatureScript("mob_restless_leng") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_restless_lengAI(creature);
        }

        struct mob_restless_lengAI : public ScriptedAI
        {
            mob_restless_lengAI(Creature* creature) : ScriptedAI(creature) { }

            void UpdateAI(const uint32 diff)
            {
                std::list<Player*> playerList;
                playerList.clear();
                GetPlayerListInGrid(playerList, me, 20.0f);

                for (auto player: playerList)
                    if (player->GetQuestStatus(31688) == QUEST_STATUS_INCOMPLETE)
                        player->KilledMonsterCredit(65586);
            }
        };
};

/// Wrathion/58038
class npc_wrathion_niuzao_temple : public CreatureScript
{
    public:
        npc_wrathion_niuzao_temple() : CreatureScript("npc_wrathion_niuzao_temple") { }

        bool OnGossipHello(Player* p_Player, Creature* p_Creature) override
        {
            if (p_Player->GetQuestStatus(32805) == QUEST_STATUS_INCOMPLETE)
            {
                if (!GetClosestCreatureWithEntry(p_Player, 71142, 80.0f))
                {
                    p_Player->KilledMonsterCredit(70928);
                    p_Player->SetPhaseMask(8, true);
                    p_Player->SummonCreature(71142, *p_Creature);
                }
            }
            return true;
        }
};

/// Wrathion/58038
class npc_wrathion_niuzao_challenge : public CreatureScript
{
    public:
        npc_wrathion_niuzao_challenge() : CreatureScript("npc_wrathion_niuzao_challenge") { }

        struct npc_wrathion_niuzao_challengeAI : public ScriptedAI
        {
            npc_wrathion_niuzao_challengeAI(Creature* creature) : ScriptedAI(creature)
            {
                m_PlayerGuid    = 0;
                m_ActionCounter = 0;
                m_SceneDone     = false;
            }

            enum eWrathionDatas
            {
                EventLaunchEvent         = 1,
                EventFightOver           = 2,
                EventDespawn             = 3,
                EventSummonDeathWing     = 4,
                SpellEyesOfTheDestroyer  = 142349
            };

            uint64 m_PlayerGuid;
            uint32 m_ActionCounter;
            EventMap m_Events;
            bool m_SceneDone;

            void DamageTaken(Unit*p_Attacker, uint32& p_Damage) override
            {
                if (p_Damage >= me->GetHealth())
                {
                    p_Damage = 0;
                    std::list<AreaTrigger*> l_AreatriggerList;

                    me->GetAreaTriggerList(l_AreatriggerList, 141466);

                    for (AreaTrigger* l_Areatrigger : l_AreatriggerList)
                        l_Areatrigger->Remove();

                    me->setFaction(35);
                    me->SetFullHealth();
                    me->RemoveAllAuras();

                    if (Creature* l_Xuen = GetClosestCreatureWithEntry(me, 71107, 50.0f))
                    {
                        if (l_Xuen->AI())
                            l_Xuen->AI()->Talk(7);
                    }

                    m_Events.ScheduleEvent(eWrathionDatas::EventFightOver, 500);
                }
            }

            void DoAction(int32 const p_Action)
            {
                if (p_Action == 1)
                {
                    me->AddAura(eWrathionDatas::SpellEyesOfTheDestroyer, me);
                    m_Events.ScheduleEvent(eWrathionDatas::EventSummonDeathWing, 3000);
                }
            }

            uint64 GetGUID(int32 /* = 0 */)
            {
                return m_PlayerGuid;
            }

            void IsSummonedBy(Unit* p_Summoner) override
            {
                m_PlayerGuid = p_Summoner->GetGUID();
                m_Events.ScheduleEvent(eWrathionDatas::EventLaunchEvent, 1500);
            }

            void UpdateAI(const uint32 p_Diff) override
            {
                m_Events.Update(p_Diff);

                switch (m_Events.ExecuteEvent())
                {
                    case eWrathionDatas::EventLaunchEvent:
                    {
                        if (m_SceneDone)
                            return;

                        ++m_ActionCounter;

                        switch (m_ActionCounter)
                        {
                            case 1:
                                Talk(0);
                                me->SetWalk(true);
                                me->GetMotionMaster()->MovePoint(1, 2271.74f, 4694.48389f, 146.48f);
                                m_Events.ScheduleEvent(eWrathionDatas::EventLaunchEvent, 10000);
                                break;
                            case 2:
                                Talk(1);
                                m_Events.ScheduleEvent(eWrathionDatas::EventLaunchEvent, 4000);
                                break;
                            case 3:
                                Talk(2);
                                m_Events.ScheduleEvent(eWrathionDatas::EventLaunchEvent, 4300);
                                break;
                            case 4:
                                if (Creature* l_Xuen = GetClosestCreatureWithEntry(me, 71144, 50.0f))
                                {
                                    if (l_Xuen->AI())
                                        l_Xuen->AI()->Talk(0);
                                }
                                m_Events.ScheduleEvent(eWrathionDatas::EventLaunchEvent, 7000);
                                break;
                            case 5:
                                if (Creature* l_Xuen = GetClosestCreatureWithEntry(me, 71144, 50.0f))
                                {
                                    if (l_Xuen->AI())
                                        l_Xuen->AI()->Talk(1);
                                }
                                m_Events.ScheduleEvent(eWrathionDatas::EventLaunchEvent, 6000);
                                break;
                            case 6:
                                Talk(3);
                                m_Events.ScheduleEvent(eWrathionDatas::EventLaunchEvent, 5000);
                                break;
                            case 7:
                                if (Creature* l_Xuen = GetClosestCreatureWithEntry(me, 71144, 50.0f))
                                {
                                    if (l_Xuen->AI())
                                        l_Xuen->AI()->Talk(2);
                                }
                                m_Events.ScheduleEvent(eWrathionDatas::EventLaunchEvent, 9250);
                                break;
                            case 8:
                                if (Creature* l_Xuen = GetClosestCreatureWithEntry(me, 71144, 50.0f))
                                {
                                    if (l_Xuen->AI())
                                        l_Xuen->AI()->Talk(3);
                                }
                                m_Events.ScheduleEvent(eWrathionDatas::EventLaunchEvent, 9500);
                                break;
                            case 9:
                                if (Creature* l_Xuen = GetClosestCreatureWithEntry(me, 71144, 50.0f))
                                {
                                    if (l_Xuen->AI())
                                        l_Xuen->AI()->Talk(4);
                                }
                                m_Events.ScheduleEvent(eWrathionDatas::EventLaunchEvent, 8800);
                                break;
                            case 10:
                                Talk(4);
                                m_Events.ScheduleEvent(eWrathionDatas::EventLaunchEvent, 7000);
                                break;
                            case 11:
                                if (Creature* l_Xuen = GetClosestCreatureWithEntry(me, 71144, 50.0f))
                                {
                                    if (l_Xuen->AI())
                                        l_Xuen->AI()->Talk(5);
                                }
                                m_Events.ScheduleEvent(eWrathionDatas::EventLaunchEvent, 1800);
                                break;
                            case 12:
                                Talk(5);
                                m_Events.ScheduleEvent(eWrathionDatas::EventLaunchEvent, 2700);
                                break;
                            case 13:
                                if (Creature* l_Xuen = GetClosestCreatureWithEntry(me, 71144, 50.0f))
                                {
                                    if (l_Xuen->AI())
                                        l_Xuen->AI()->Talk(6);
                                }
                                m_Events.ScheduleEvent(eWrathionDatas::EventLaunchEvent, 7800);
                                break;
                            case 14:
                                if (Creature* l_Xuen = GetClosestCreatureWithEntry(me, 71144, 50.0f))
                                {
                                    if (l_Xuen->AI())
                                        l_Xuen->AI()->Talk(7);
                                }
                                m_Events.ScheduleEvent(eWrathionDatas::EventLaunchEvent, 4000);
                                break;
                            case 15:
                                m_ActionCounter = 0;
                                m_SceneDone = true;
                                break;
                            default:
                                break;
                        }
                        break;
                    }
                    case eWrathionDatas::EventFightOver:
                    {
                        ++m_ActionCounter;

                        switch (m_ActionCounter)
                        {
                            case 1:
                                if (Creature* l_Xuen = GetClosestCreatureWithEntry(me, 71107, 50.0f))
                                {
                                    if (l_Xuen->AI())
                                        l_Xuen->AI()->Talk(8);
                                }
                                m_Events.ScheduleEvent(eWrathionDatas::EventLaunchEvent, 12000);
                                break;
                            case 2:
                                if (Creature* l_Xuen = GetClosestCreatureWithEntry(me, 71107, 50.0f))
                                {
                                    if (l_Xuen->AI())
                                        l_Xuen->AI()->Talk(9);
                                }
                                m_Events.ScheduleEvent(eWrathionDatas::EventLaunchEvent, 4500);
                                break;
                            case 3:
                                Talk(7);
                                break;
                            default:
                                break;
                        }

                        break;
                    }
                    case eWrathionDatas::EventSummonDeathWing:
                        me->SummonCreature(71321, me->m_positionX, me->m_positionY + 2.5f, me->m_positionZ);
                        break;
                    case eWrathionDatas::EventDespawn:
                        me->DespawnOrUnsummon();
                        break;
                    default:
                        break;
                }

                if (m_SceneDone)
                    DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_wrathion_niuzao_challengeAI(creature);
        }
};

/// Wrathion/58038
class npc_niuzao_challenge_gong : public CreatureScript
{
    public:
        npc_niuzao_challenge_gong() : CreatureScript("npc_niuzao_challenge_gong") { }

        bool OnGossipSelect(Player* p_Player, Creature* p_Creature, uint32 /*sender*/, uint32 p_Action)
        {
            p_Player->PlayerTalkClass->ClearMenus();

            if (p_Action == 1)
            {
                /// Quest Celestial Blessings
				if (p_Player->GetQuestStatus(32805) == QUEST_STATUS_INCOMPLETE && p_Player->GetRoleForGroup(p_Player->GetSpecializationId(p_Player->GetActiveSpec())) == Roles::ROLES_TANK)
                {
                    if (Creature* l_Wrathion = GetClosestCreatureWithEntry(p_Creature, 71142, 30.0f))
                    {
                        if (l_Wrathion->AI())
                            l_Wrathion->AI()->DoAction(1);
                    }
                }
                p_Player->CLOSE_GOSSIP_MENU();
            }

            return true;
        }
};

/// Wrathion/58038
class npc_vision_of_deathwing : public CreatureScript
{
    public:
        npc_vision_of_deathwing() : CreatureScript("npc_vision_of_deathwing") { }

        struct npc_vision_of_deathwingAI : public ScriptedAI
        {
            npc_vision_of_deathwingAI(Creature* creature) : ScriptedAI(creature)
            {
                m_PlayerGuid    = 0;
                m_WrathionGuid  = 0;
            }

            enum eDeathWingDatas
            {
                EventSummonAdds          = 1,
                EventCrumblingArc        = 2,
                SpellCrumblingArc        = 141653,
                EventReignOfFireAura     = 3,
                SpellReignOfFireAura     = 141510,
                EventBloodOfTheDeathBorn = 4,
                SpellBloodOfTheDeathBorn = 141500,
                EventEyeOfTheDestroyer   = 5,
                SpellEyesOfTheDestroyer  = 142349,
                EventFocusWrathion       = 6,
                EventNormalPhase         = 7,
                NpcMoltenElemental       = 71129,
                EventTrueSummon          = 8,
                EventSummonTears         = 9,
                SpellSummonTears         = 141483
            };

            uint64 m_PlayerGuid;
            uint64 m_WrathionGuid;
            EventMap m_Events;

            void InitiateEvents()
            {
                m_Events.Reset();

                m_Events.ScheduleEvent(eDeathWingDatas::EventCrumblingArc, 3000);
                m_Events.ScheduleEvent(eDeathWingDatas::EventSummonTears, 10000);
                m_Events.ScheduleEvent(eDeathWingDatas::EventBloodOfTheDeathBorn, 21000);
                m_Events.ScheduleEvent(eDeathWingDatas::EventReignOfFireAura, 32000);
                m_Events.ScheduleEvent(eDeathWingDatas::EventSummonAdds, 50000);

                me->SetDisplayId(48767);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);
                me->SetReactState(REACT_AGGRESSIVE);
                me->ClearUnitState(UNIT_STATE_ROOT);

                if (m_WrathionGuid)
                {
                    if (Creature* l_Wrathion = sObjectAccessor->GetCreature(*me, m_WrathionGuid))
                    {
                        me->NearTeleportTo(l_Wrathion->m_positionX, l_Wrathion->m_positionY + 1.2f, l_Wrathion->m_positionZ + 1.2f, 0.0f);
                        me->Attack(l_Wrathion, true);
                    }
                }

				me->DespawnOrUnsummon(eDeathWingDatas::NpcMoltenElemental);
				me->DespawnOrUnsummon(800001);
            }

            void EnterCombat(Unit* p_Killer) override
            {
                m_Events.Reset();
                InitiateEvents();
            }

            void IsSummonedBy(Unit* p_Summoner) override
            {
                m_WrathionGuid = p_Summoner->GetGUID();

                if (Creature* l_Wrathion = sObjectAccessor->GetCreature(*me, m_WrathionGuid))
                {
                    if (l_Wrathion->AI())
                        m_PlayerGuid = l_Wrathion->AI()->GetGUID();

                    me->AddThreat(l_Wrathion, 100000.0f);
                    me->Attack(l_Wrathion, true);

                    m_Events.ScheduleEvent(eDeathWingDatas::EventFocusWrathion, 10000);
                }
            }

            void JustDied(Unit* p_Killer)
            {
                if (Creature* l_Wrathion = sObjectAccessor->GetCreature(*me, m_WrathionGuid))
                    l_Wrathion->DespawnOrUnsummon();

                me->DespawnOrUnsummon();

                if (m_PlayerGuid)
                {
                    if (Player* l_Player = sObjectAccessor->GetPlayer(*me, m_PlayerGuid))
                        l_Player->SetPhaseMask(1, true);
                }
            }

            void UpdateAI(const uint32 p_Diff) override
            {
                m_Events.Update(p_Diff);

                switch (m_Events.ExecuteEvent())
                {
                    case eDeathWingDatas::EventFocusWrathion:
                    {
                        if (m_PlayerGuid && m_WrathionGuid)
                        {
                            if (Player* l_Player = sObjectAccessor->GetPlayer(*me, m_PlayerGuid))
                            {
                                ThreatManager& l_ThreatManager = me->getThreatManager();
                                float l_Aggro = l_ThreatManager.getThreat(l_Player, false);

                                l_ThreatManager.clearReferences();

                                if (Creature* l_Wrathion = sObjectAccessor->GetCreature(*me, m_WrathionGuid))
                                {
                                    l_ThreatManager.addThreat(l_Wrathion, l_Aggro * 1.5f);
                                    me->Attack(l_Wrathion, true);
                                }
                            }
                            m_Events.ScheduleEvent(eDeathWingDatas::EventFocusWrathion, 10000);
                        }
                        else
                        {
                            m_Events.Reset();
                            me->DespawnOrUnsummon();
                        }
                        break;
                    }
                    case eDeathWingDatas::EventCrumblingArc:
                        if (Unit* l_Target = SelectTarget(SELECT_TARGET_RANDOM))
                            me->CastSpell(l_Target, eDeathWingDatas::SpellCrumblingArc, false);
                        m_Events.ScheduleEvent(eDeathWingDatas::EventCrumblingArc, 28000);
                        break;
                    case eDeathWingDatas::EventReignOfFireAura:
                        me->AddAura(eDeathWingDatas::SpellReignOfFireAura, me);
                        m_Events.ScheduleEvent(eDeathWingDatas::EventReignOfFireAura, 28000);
                        break;
                    case eDeathWingDatas::EventBloodOfTheDeathBorn:
                        if (Unit* l_Target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                            me->CastSpell(l_Target, eDeathWingDatas::SpellBloodOfTheDeathBorn, false);
                        m_Events.ScheduleEvent(eDeathWingDatas::EventBloodOfTheDeathBorn, 28000);
                        break;
                    case eDeathWingDatas::EventSummonTears:
                        me->CastSpell(me, eDeathWingDatas::SpellSummonTears, false);
                        break;
                    case eDeathWingDatas::EventSummonAdds:
                    {
                        m_Events.Reset();

                        me->AttackStop();
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);
                        me->SetReactState(REACT_PASSIVE);
                        me->AddUnitState(UNIT_STATE_ROOT);
                        me->SetDisplayId(11686);

                        if (Creature* l_Wrathion = sObjectAccessor->GetCreature(*me, m_WrathionGuid))
                        {
                            l_Wrathion->AttackStop();
                            if (me->GetAreaId() == 6213)
                                l_Wrathion->NearTeleportTo(2254.4736f, 4713.8857f, 145.938f, M_PI);
                            else if (me->GetAreaId() == 6048)
                                l_Wrathion->NearTeleportTo(-1815.369f, 1053.9362f, -31.7267f, M_PI);

                        }

                        me->DespawnOrUnsummon(71041);
                        m_Events.ScheduleEvent(eDeathWingDatas::EventTrueSummon, 300);
                        break;
                    }
                    case eDeathWingDatas::EventTrueSummon:
                    {
                        float l_SpawnDist = 20.0f;
                        float l_Angle = me->GetOrientation();

                        for (uint8 l_Itr = 0; l_Itr <= 3; l_Itr++)
                        {
                            l_Angle += (M_PI / 2);

                            if (me->GetAreaId() == 6213)
                            {
                                float l_X = 2254.4736f + l_SpawnDist * cos(l_Angle);
                                float l_Y = 4713.8857f + l_SpawnDist * sin(l_Angle);

                                me->SummonCreature(eDeathWingDatas::NpcMoltenElemental, l_X, l_Y, me->GetPositionZ() + 1.5f);
                            }
                            else if (me->GetAreaId() == 6048)
                            {
                                float l_X = -1815.369f + l_SpawnDist * cos(l_Angle);
                                float l_Y = 1053.9362f + l_SpawnDist * sin(l_Angle);

                                me->SummonCreature(eDeathWingDatas::NpcMoltenElemental, l_X, l_Y, me->GetPositionZ() + 1.5f);
                            }
                        }

                        m_Events.ScheduleEvent(eDeathWingDatas::EventNormalPhase, 50000);
                        break;
                    }
                    case eDeathWingDatas::EventNormalPhase:
                        InitiateEvents();
                        break;
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_vision_of_deathwingAI(creature);
        }
};

/// Wrathion/58038
class npc_molten_elemental_wrathion : public CreatureScript
{
    public:
        npc_molten_elemental_wrathion() : CreatureScript("npc_molten_elemental_wrathion")
        {
        }

        struct npc_molten_elemental_wrathionAI : public ScriptedAI
        {
            npc_molten_elemental_wrathionAI(Creature* creature) : ScriptedAI(creature) { }

            enum eMoltenElementalDatas
            {
                EventSummonAdds = 1,
            };

            EventMap m_Events;

            void Reset() { }

            void IsSummonedBy(Unit* p_Summoner) override
            {
                me->SetReactState(REACT_PASSIVE);
                me->AddUnitState(UNIT_STATE_ROOT);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NOT_SELECTABLE);

                m_Events.Reset();

                m_Events.ScheduleEvent(eMoltenElementalDatas::EventSummonAdds, urand(4500, 6500));
            }

            void UpdateAI(const uint32 p_Diff) override
            {
                m_Events.Update(p_Diff);

                switch (m_Events.ExecuteEvent())
                {
                    case eMoltenElementalDatas::EventSummonAdds:
                        if (Creature* l_Wrathion = GetClosestCreatureWithEntry(me, me->GetAreaId() == 6213 ? 71142 : 64809, 70.0f))
                        {
                            if (Creature* l_Summon = me->SummonCreature(800001, *me))
                            {
                                if (l_Summon->AI())
                                    l_Summon->AI()->SetGUID(l_Wrathion->GetGUID());
                            }
                        }

                        m_Events.ScheduleEvent(eMoltenElementalDatas::EventSummonAdds, urand(4500, 6500));
                        break;
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_molten_elemental_wrathionAI(creature);
        }
};

/// Wrathion/58038
class npc_deathwing_vision_trigger : public CreatureScript
{
    public:
        npc_deathwing_vision_trigger() : CreatureScript("npc_deathwing_vision_trigger") { }

        struct npc_deathwing_vision_triggerAI : public ScriptedAI
        {
            npc_deathwing_vision_triggerAI(Creature* creature) : ScriptedAI(creature)
            {
                m_WrathionGuid = 0;
            }

            EventMap m_Events;
            uint64 m_WrathionGuid;

            enum eTriggerDatas
            {
                EventRushWrathion = 1
            };

            void SetGUID(uint64 p_Guid, int32 p_Index) override
            {
                m_WrathionGuid = p_Guid;
            }

            void IsSummonedBy(Unit* p_Summoner) override
            {
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                m_Events.ScheduleEvent(eTriggerDatas::EventRushWrathion, 250);
            }

            void Explode(Unit* p_Victim)
            {
                if (me->GetDistance2d(p_Victim) <= 1.2f)
                {
                    me->StopMoving();
                    me->GetMotionMaster()->Clear();
                    me->CastSpell(p_Victim, 138099, true);
                    me->DespawnOrUnsummon();
                }
            }

            void UpdateAI(const uint32 p_Diff) override
            {
                m_Events.Update(p_Diff);

                if (me->IsMoving())
                {
                    if (Creature* l_Wrathion = sObjectAccessor->GetCreature(*me, m_WrathionGuid))
                        Explode(l_Wrathion);
                    if (Player* l_Player = me->SelectNearestPlayer(1.2f))
                        Explode(l_Player);
                }

                if (m_Events.ExecuteEvent() == eTriggerDatas::EventRushWrathion)
                {
                    me->SetReactState(REACT_PASSIVE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                    if (Creature* l_Wrathion = sObjectAccessor->GetCreature(*me, m_WrathionGuid))
                        me->GetMotionMaster()->MoveCharge(l_Wrathion->m_positionX, l_Wrathion->m_positionY, l_Wrathion->m_positionZ, 10.0f);
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_deathwing_vision_triggerAI(creature);
        }
};

void AddSC_townlong_steppes()
{
    //Rare mobs
    new mob_kah_tir();
    new mob_lon_bull();
    new mob_yul_wildpaw();
    new mob_norlaxx();
    new mob_siltriss_sharpener();
    new mob_yowler();
    new mob_lith_ik();
    new mob_eshelon();

    //Elite mobs
    new mob_darkwoods_faerie();
    new mob_hei_feng();
    // Standard Mobs
    new mob_restless_leng();
    new npc_wrathion_niuzao_temple();
    new npc_wrathion_niuzao_challenge();
    new npc_niuzao_challenge_gong();
    new npc_vision_of_deathwing();
    new npc_molten_elemental_wrathion();
    new npc_deathwing_vision_trigger();
}
