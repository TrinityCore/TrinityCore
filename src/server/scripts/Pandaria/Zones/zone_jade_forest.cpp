#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"

enum eShadowOfDoubtSpells
{
    SPELL_DEAFENED = 108918,
    SPELL_SHA_BOLT = 126139,
    SPELL_GROWING_DOUBT = 126147,
};

enum eShadowOfDoubtEvents
{
    EVENT_DEAFENED = 1,
    EVENT_GROWING_DOUBT = 2,
    EVENT_SHA_BOLT = 3,
};

enum Texts
{
	SAY_KORNAS_AGGRO	= 0,
	SAY_KRAXIK_AGGRO	= 1,
	SAY_FEROCIOUS_AGGRO	= 2,
	SAY_MORGRINN_AGGRO	= 3,
	SAY_FERDINAND_AGGRO	= 4,
	SAY_AETHIS_AGGRO	= 5,
	SAY_SARNAK_AGGRO	= 6,
	SAY_UROBI_AGGRO		= 7
};

class mob_shadow_of_doubt : public CreatureScript
{
public:
    mob_shadow_of_doubt() : CreatureScript("mob_shadow_of_doubt")
    {
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_shadow_of_doubtAI(creature);
    }

    struct mob_shadow_of_doubtAI : public ScriptedAI
    {
        mob_shadow_of_doubtAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();

            events.ScheduleEvent(EVENT_DEAFENED, 30000);
            events.ScheduleEvent(EVENT_GROWING_DOUBT, 9000);
            events.ScheduleEvent(EVENT_SHA_BOLT, 15000);
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
                case EVENT_DEAFENED:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_DEAFENED, false);
                    events.ScheduleEvent(EVENT_DEAFENED, 30000);
                    break;
                case EVENT_GROWING_DOUBT:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_GROWING_DOUBT, false);
                    events.ScheduleEvent(EVENT_GROWING_DOUBT, 9000);
                    break;
                case EVENT_SHA_BOLT:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_SHA_BOLT, false);
                    events.ScheduleEvent(EVENT_SHA_BOLT, 15000);
                    break;

                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

enum eKorNasSpells
{
    SPELL_SHADOWBOLT = 125212,
    SPELL_VOIDCLOUD = 125241,
};

enum eKorNasEvents
{
    EVENT_SHADOWBOLT = 1,
    EVENT_VOIDCLOUD = 2,
};

class mob_kor_nas_nightsavage : public CreatureScript
{
public:
    mob_kor_nas_nightsavage() : CreatureScript("mob_kor_nas_nightsavage")
    {
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_kor_nas_nightsavageAI(creature);
    }

    struct mob_kor_nas_nightsavageAI : public ScriptedAI
    {
        mob_kor_nas_nightsavageAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();

            events.ScheduleEvent(EVENT_SHADOWBOLT, 50000);
            events.ScheduleEvent(EVENT_VOIDCLOUD, 15000);
        }

        void EnterCombat(Unit* /*who*/)
        {
        	Talk(SAY_KORNAS_AGGRO);
        };

        void JustDied(Unit* /*killer*/)
        {
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
                    events.ScheduleEvent(EVENT_SHADOWBOLT, 70000);
                    break;
                case EVENT_VOIDCLOUD:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_VOIDCLOUD, false);
                    events.ScheduleEvent(EVENT_VOIDCLOUD, 35000);
                    break;
                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

enum eKraxIkSpells
{
    SPELL_BLADE_FURY = 125370,
    SPELL_STEALTH = 128933,
    SPELL_TORNADO = 125398,
    SPELL_TORNADO_DMG = 131693,
    SPELL_WINDSONG = 125373,
};

enum eKraxIkEvents
{
    EVENT_BLADE_FURY = 1,
    EVENT_TORNADO = 2,
    EVENT_WINDSONG = 3,
};

class mob_krax_ik : public CreatureScript
{
public:
    mob_krax_ik() : CreatureScript("mob_krax_ik")
    {
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_krax_ikAI(creature);
    }

    struct mob_krax_ikAI : public ScriptedAI
    {
        mob_krax_ikAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();

            me->CastSpell(me, SPELL_STEALTH, true);

            events.ScheduleEvent(EVENT_TORNADO, 5000);
            events.ScheduleEvent(EVENT_BLADE_FURY, 25000);
            events.ScheduleEvent(EVENT_WINDSONG, 30000);
        }

        void EnterCombat(Unit* /*attacker*/)
        {
        	Talk(SAY_KRAXIK_AGGRO);
            me->RemoveAurasDueToSpell(SPELL_STEALTH);
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
                    events.ScheduleEvent(EVENT_BLADE_FURY, 20000);
                    break;
                case EVENT_WINDSONG:
                    me->CastSpell(me, SPELL_WINDSONG, false);
                    events.ScheduleEvent(EVENT_WINDSONG, 30000);
                    break;
                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

enum eMisterFerociousSpells
{
    SPELL_GOING_BANANAS = 125363,
    SPELL_BANANARANG = 125311,
    SPELL_TOSS_FILTH = 125365
};

enum eMisterFerociousEvents
{
    EVENT_GOING_BANANAS = 1,
    EVENT_BANANARANG = 2,
    EVENT_TOSS_FILTH = 3
};

class mob_mister_ferocious : public CreatureScript
{
public:
    mob_mister_ferocious() : CreatureScript("mob_mister_ferocious")
    {
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_mister_ferociousAI(creature);
    }

    struct mob_mister_ferociousAI : public ScriptedAI
    {
        mob_mister_ferociousAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();

            events.ScheduleEvent(EVENT_GOING_BANANAS, 12000);
            events.ScheduleEvent(EVENT_BANANARANG, 8000);
            events.ScheduleEvent(EVENT_TOSS_FILTH, 15000);
        }

        void EnterCombat(Unit* /*who*/)
        {
        	Talk(SAY_FEROCIOUS_AGGRO);
		};

        void JustDied(Unit* /*killer*/)
        {
        }

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
                case EVENT_GOING_BANANAS:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_GOING_BANANAS, false);
                    events.ScheduleEvent(EVENT_GOING_BANANAS, 10000);
                    break;
                case EVENT_BANANARANG:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_BANANARANG, false);
                    events.ScheduleEvent(EVENT_BANANARANG, 20000);
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

enum eMorgrinnCrackSpells
{
    SPELL_DEVASTATING_ARC       = 124946,
    SPELL_SUMMON_QUILEN         = 124980,
    SPELL_TITANIC_STRENGTH      = 124976,
};

enum eMorgrinnCrackEvents
{
    EVENT_DEVASTATING_ARC       = 1,
    EVENT_SUMMON_QUILEN         = 2,
    EVENT_TITANIC_STRENGTH      = 3,
};

class mob_morgrinn_crackfang : public CreatureScript
{
    public:
        mob_morgrinn_crackfang() : CreatureScript("mob_morgrinn_crackfang")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_morgrinn_crackfangAI(creature);
        }

        struct mob_morgrinn_crackfangAI : public ScriptedAI
        {
            mob_morgrinn_crackfangAI(Creature* creature) : ScriptedAI(creature)
            {
            }

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
            	Talk(SAY_MORGRINN_AGGRO);
            }

            void JustDied(Unit* /*killer*/)
            {
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
                            events.ScheduleEvent(EVENT_DEVASTATING_ARC,      60000);
                            break;
                        case EVENT_SUMMON_QUILEN:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SUMMON_QUILEN, false);
                            events.ScheduleEvent(EVENT_SUMMON_QUILEN, 50000);
                            break;
                        case EVENT_TITANIC_STRENGTH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_TITANIC_STRENGTH, false);
                            events.ScheduleEvent(EVENT_TITANIC_STRENGTH,      30000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum eFerdinandSpells
{
    SPELL_BELLOWING_RAGE        =   124297,
    SPELL_EMPOWERING_FLAMES     =   130388,
    SPELL_HOOF_STOMP            =   124289,
    SPELL_RUSHING_CHARGE        =   124302
};

enum eFerdinandEvents
{
    EVENT_BELLOWING_RAGE        = 1,
    EVENT_EMPOWERING_FLAMES     = 2,
    EVENT_HOOF_STOMP            = 3,    
    EVENT_RUSHING_CHARGE        = 4
};


class mob_ferdinand : public CreatureScript
{
    public:
        mob_ferdinand() : CreatureScript("mob_ferdinand")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_ferdinandAI(creature);
        }

        struct mob_ferdinandAI : public ScriptedAI
        {
            mob_ferdinandAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset()
            {
                events.Reset();

                events.ScheduleEvent(EVENT_BELLOWING_RAGE,   20000);
                events.ScheduleEvent(EVENT_HOOF_STOMP,  10000);
                events.ScheduleEvent(EVENT_RUSHING_CHARGE, 10000);            
            }

            void EnterCombat(Unit* /*who*/)
            {
            	Talk(SAY_FERDINAND_AGGRO);
            }


            void JustDied(Unit* /*killer*/)
            {
            }

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

enum eAethisSpells
{
    SPELL_RAIN_DANCE    = 124860,
    SPELL_TORRENT       = 124935,
    SPELL_WATER_BOLT    = 124854
};

enum eAethisEvents
{
    EVENT_RAIN_DANCE        = 1,
    EVENT_TORRENT           = 2,
    EVENT_WATER_BOLT        = 3
};

class mob_aethis : public CreatureScript
{
    public:
        mob_aethis() : CreatureScript("mob_aethis")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_aethisAI(creature);
        }

        struct mob_aethisAI : public ScriptedAI
        {
            mob_aethisAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset()
            {
                events.Reset();
                
                events.ScheduleEvent(EVENT_RAIN_DANCE,   5000);
                events.ScheduleEvent(EVENT_TORRENT,     15000);
                events.ScheduleEvent(EVENT_WATER_BOLT,  25000);
            }

            void EnterCombat(Unit* /*who*/)
            {
            	Talk(SAY_AETHIS_AGGRO);
            }

            void JustDied(Unit* /*killer*/)
            {
            }

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
                            events.ScheduleEvent(EVENT_RAIN_DANCE,       25000);
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

enum eSarnakSpells
{
    SPELL_GRAPPLING_HOOK        = 125623,
    SPELL_VANISH                = 125632,
    SPELL_VICIOUS_REND          = 125624,
    SPELL_SMOKED_BLADE          = 125633
};

enum eSarnakEvents
{
    EVENT_GRAPPLING_HOOK         = 1,
    EVENT_VANISH                 = 2,
    EVENT_VICIOUS_REND           = 3,
    EVENT_SMOKED_BLADE           = 4
};
class mob_sarnak : public CreatureScript
{
    public:
        mob_sarnak() : CreatureScript("mob_sarnak")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_sarnakAI(creature);
        }

        struct mob_sarnakAI : public ScriptedAI
        {
            mob_sarnakAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset()
            {
                events.Reset();

                events.ScheduleEvent(EVENT_GRAPPLING_HOOK,   17000);
                events.ScheduleEvent(EVENT_VANISH,     12000);
                events.ScheduleEvent(EVENT_VICIOUS_REND,  7000);
            }
            void EnterCombat(Unit* /*who*/)
            {
            	Talk(SAY_SARNAK_AGGRO);
            }

            void JustDied(Unit* /*killer*/)
            {
            }

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
                            events.ScheduleEvent(EVENT_GRAPPLING_HOOK,       5000);
                            break;
                        case EVENT_VANISH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_VANISH, false);
                            events.ScheduleEvent(EVENT_VANISH, 30000);
                            events.ScheduleEvent(EVENT_SMOKED_BLADE, urand(0,8000));
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

enum eUrobiWalkerSpells
{
    SPELL_CHI_BURST                     =   125817,
    SPELL_HEALING_MIST                  =   125802,
    SPELL_SPINNING_CRANE_KICK           =   125799
};

enum eUrobiWalkerEvents
{
    EVENT_CHI_BURST                   = 1,
    EVENT_HEALING_MIST                = 2,
    EVENT_SPINNING_CRANE_KICK         = 3
};

class mob_urobi_walker : public CreatureScript
{
    public:
        mob_urobi_walker() : CreatureScript("mob_urobi_walker")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_urobi_walkerAI(creature);
        }

        struct mob_urobi_walkerAI : public ScriptedAI
        {
            mob_urobi_walkerAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset()
            {
                events.Reset();

                events.ScheduleEvent(EVENT_CHI_BURST,   10000);
                events.ScheduleEvent(EVENT_HEALING_MIST,     15000);
                events.ScheduleEvent(EVENT_SPINNING_CRANE_KICK,  5000);          
            }
            void EnterCombat(Unit* /*who*/)
            {
            	Talk(SAY_UROBI_AGGRO);
            }



            void JustDied(Unit* /*killer*/)
            {
            }

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
                            events.ScheduleEvent(EVENT_CHI_BURST,       5000);
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


enum eAkkalarSpells
{
    SPELL_BOUCLIER_D_EAU = 79892,
    SPELL_BOUCLIER_D_EAU_2 = 34828,
    SPELL_BOUCLIER_DE_TERRE = 79927,
    SPELL_CARAPACE_BOUCLIER = 83488,
    SPELL_MOT_DE_POUVOIR = 11835
};

enum eAkkalarEvents
{
    EVENT_BOUCLIER_D_EAU = 1,
    EVENT_BOUCLIER_D_EAU_2 = 2,
    EVENT_BOUCLIER_DE_TERRE = 3,
    EVENT_CARAPACE_BOUCLIER = 4,
    EVENT_MOT_DE_POUVOIR = 5
};

class mob_akkalar : public CreatureScript
{
public:
    mob_akkalar() : CreatureScript("mob_akkalar")
    {
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_akkalarAI(creature);
    }

    struct mob_akkalarAI : public ScriptedAI
    {
        mob_akkalarAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();

            events.ScheduleEvent(EVENT_BOUCLIER_D_EAU, 10000);
            events.ScheduleEvent(EVENT_BOUCLIER_D_EAU_2, 20000);
            events.ScheduleEvent(EVENT_BOUCLIER_DE_TERRE, 30000);
            events.ScheduleEvent(EVENT_CARAPACE_BOUCLIER, 40000);
            events.ScheduleEvent(EVENT_MOT_DE_POUVOIR, 50000);
        }

        void JustDied(Unit* /*killer*/)
        {
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
                case EVENT_BOUCLIER_D_EAU:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_BOUCLIER_D_EAU, false);
                    events.ScheduleEvent(EVENT_BOUCLIER_D_EAU, 620000);
                    break;
                case EVENT_BOUCLIER_D_EAU_2:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_BOUCLIER_D_EAU_2, false);
                    events.ScheduleEvent(EVENT_BOUCLIER_D_EAU_2, 70000);
                    break;
                case EVENT_BOUCLIER_DE_TERRE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_BOUCLIER_DE_TERRE, false);
                    events.ScheduleEvent(EVENT_BOUCLIER_DE_TERRE, 80000);
                    break;
                case EVENT_CARAPACE_BOUCLIER:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_CARAPACE_BOUCLIER, false);
                    events.ScheduleEvent(EVENT_CARAPACE_BOUCLIER, 90000);
                    break;
                case EVENT_MOT_DE_POUVOIR:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_MOT_DE_POUVOIR, false);
                    events.ScheduleEvent(EVENT_MOT_DE_POUVOIR, 100000);
                    break;
                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

enum eGrookinOutrunnerSpells
{
    SPELL_SHOOT = 23337,
    SPELL_CLEAVE = 40505
};

enum eGrookinOutrunnerEvents
{
    EVENT_SHOOT = 1,
    EVENT_CLEAVE = 2
};

class mob_grookin_outrunner : public CreatureScript
{
public:
    mob_grookin_outrunner() : CreatureScript("mob_grookin_outrunner")
    {
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_grookin_outrunnerAI(creature);
    }

    struct mob_grookin_outrunnerAI : public ScriptedAI
    {
        mob_grookin_outrunnerAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();

            events.ScheduleEvent(EVENT_SHOOT, 7000);
            events.ScheduleEvent(EVENT_CLEAVE, 12000);
        }

        void JustDied(Unit* /*killer*/)
        {
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
                case EVENT_SHOOT:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_SHOOT, false);
                    events.ScheduleEvent(EVENT_SHOOT, 10000);
                    break;
                case EVENT_CLEAVE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_CLEAVE, false);
                    events.ScheduleEvent(EVENT_CLEAVE, 10000);
                    break;
                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

enum eBambooPythonSpells
{
    SPELL_SWAMP_FEVER = 116026
};

enum eBambooPythonEvents
{
    EVENT_SWAMP_FEVER = 1
};

class mob_bamboo_python : public CreatureScript
{
public:
    mob_bamboo_python() : CreatureScript("mob_bamboo_python")
    {
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_bamboo_pythonAI(creature);
    }

    struct mob_bamboo_pythonAI : public ScriptedAI
    {
        mob_bamboo_pythonAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();

            events.ScheduleEvent(EVENT_SWAMP_FEVER, 7000);
        }

        void EnterCombat(Unit* /*attacker*/)
        {
            me->RemoveAurasDueToSpell(SPELL_STEALTH);
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
                case EVENT_SWAMP_FEVER:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_SWAMP_FEVER, false);
                    events.ScheduleEvent(EVENT_SWAMP_FEVER, 15000);
                    break;
                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

#define    SPELL_STEALTH    77806

class mob_lurking_tiger : public CreatureScript
{
public:
    mob_lurking_tiger() : CreatureScript("mob_lurking_tiger")
    {
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_lurking_tigerAI(creature);
    }

    struct mob_lurking_tigerAI : public ScriptedAI
    {
        mob_lurking_tigerAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

        void Reset()
        {
            me->CastSpell(me, SPELL_STEALTH, true);
        }

        void UpdateAI(const uint32 /*diff*/)
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            DoMeleeAttackIfReady();
        }
    };
};

enum eRakiraSpells
{
    SPELL_BLOODY_PREY = 131145,
    SPELL_CLAW_RIP = 131130,
    SPELL_GROWL = 2649,
    SPELL_HOWL_OF_THE_DENMOTHER = 131199,
    SPELL_ROAR_OF_COURAGE = 93435
};

enum eRakiraEvents
{
    EVENT_BLOODY_PREY = 1,
    EVENT_CLAW_RIP = 2,
    EVENT_GROWL = 3,
    EVENT_HOWL_OF_THE_DENMOTHER = 4,
    EVENT_ROAR_OF_COURAGE = 5
};

class mob_rakira : public CreatureScript
{
public:
    mob_rakira() : CreatureScript("mob_rakira")
    {
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_rakiraAI(creature);
    }

    struct mob_rakiraAI : public ScriptedAI
    {
        mob_rakiraAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();

            events.ScheduleEvent(EVENT_BLOODY_PREY, 8000);
            events.ScheduleEvent(EVENT_CLAW_RIP, 15000);
            events.ScheduleEvent(EVENT_GROWL, 22000);
            events.ScheduleEvent(EVENT_HOWL_OF_THE_DENMOTHER, 30000);
            events.ScheduleEvent(EVENT_ROAR_OF_COURAGE, 40000);
        }

        void JustDied(Unit* /*killer*/)
        {
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
                case EVENT_BLOODY_PREY:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_BLOODY_PREY, false);
                    events.ScheduleEvent(EVENT_BLOODY_PREY, 10000);
                    break;
                case EVENT_CLAW_RIP:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_CLAW_RIP, false);
                    events.ScheduleEvent(EVENT_CLAW_RIP, 15000);
                    break;
                case EVENT_GROWL:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_GROWL, false);
                    events.ScheduleEvent(EVENT_GROWL, 22000);
                    break;
                case EVENT_HOWL_OF_THE_DENMOTHER:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_HOWL_OF_THE_DENMOTHER, false);
                    events.ScheduleEvent(EVENT_HOWL_OF_THE_DENMOTHER, 30000);
                    break;
                case EVENT_ROAR_OF_COURAGE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_ROAR_OF_COURAGE, false);
                    events.ScheduleEvent(EVENT_ROAR_OF_COURAGE, 47000);
                    break;
                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

enum eRoShenSpells
{
    SPELL_CLAW_SLASH = 131133,
    SPELL_BLOOD_CRAZED = 131150,
    SPELL_BLOODTHIRST = 131141,
    SPELL_FRENZY = 19615
};

enum eRoShenEvents
{
    EVENT_BLOOD_CRAZED = 6,
    EVENT_BLOODTHIRST = 7,
    EVENT_CLAW_SLASH = 8,
    EVENT_FRENZY = 9
};

class mob_ro_shen : public CreatureScript
{
public:
    mob_ro_shen() : CreatureScript("mob_ro_shen")
    {
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_ro_shenAI(creature);
    }

    struct mob_ro_shenAI : public ScriptedAI
    {
        mob_ro_shenAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();

            events.ScheduleEvent(EVENT_BLOODY_PREY, 8000);
            events.ScheduleEvent(EVENT_CLAW_RIP, 15000);
            events.ScheduleEvent(EVENT_GROWL, 22000);
            events.ScheduleEvent(EVENT_ROAR_OF_COURAGE, 30000);
            events.ScheduleEvent(EVENT_BLOOD_CRAZED, 40000);
            events.ScheduleEvent(EVENT_BLOODTHIRST, 50000);
            events.ScheduleEvent(EVENT_CLAW_SLASH, 60000);
            events.ScheduleEvent(EVENT_FRENZY, 70000);
        }

        void JustDied(Unit* /*killer*/)
        {
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
                case EVENT_BLOODY_PREY:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_BLOODY_PREY, false);
                    events.ScheduleEvent(EVENT_BLOODY_PREY, 10000);
                    break;
                case EVENT_CLAW_RIP:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_CLAW_RIP, false);
                    events.ScheduleEvent(EVENT_CLAW_RIP, 15000);
                    break;
                case EVENT_GROWL:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_GROWL, false);
                    events.ScheduleEvent(EVENT_GROWL, 28000);
                    break;
                case EVENT_ROAR_OF_COURAGE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_ROAR_OF_COURAGE, false);
                    events.ScheduleEvent(EVENT_ROAR_OF_COURAGE, 70000);
                    break;
                case EVENT_BLOOD_CRAZED:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_BLOOD_CRAZED, false);
                    events.ScheduleEvent(EVENT_BLOOD_CRAZED, 31000);
                    break;
                case EVENT_BLOODTHIRST:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_BLOODTHIRST, false);
                    events.ScheduleEvent(EVENT_BLOODTHIRST, 40000);
                    break;
                case EVENT_CLAW_SLASH:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_CLAW_SLASH, false);
                    events.ScheduleEvent(EVENT_CLAW_SLASH, 25000);
                    break;
                case EVENT_FRENZY:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_FRENZY, false);
                    events.ScheduleEvent(EVENT_FRENZY, 50000);
                    break;
                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

enum eShaReminantSpells
{
    SPELL_SHADOW_CLAW = 116128,
    SPELL_OVERWHELMING_GUILT = 131150,
};

enum eShaReminantEvents
{
    EVENT_SHADOW_CLAW = 1,
    EVENT_OVERWHELMING_GUILT = 2,
};

class mob_sha_reminant : public CreatureScript
{
public:
    mob_sha_reminant() : CreatureScript("mob_sha_reminant")
    {
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_sha_reminantAI(creature);
    }

    struct mob_sha_reminantAI : public ScriptedAI
    {
        mob_sha_reminantAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();

            events.ScheduleEvent(EVENT_SHADOW_CLAW, 10000);
            events.ScheduleEvent(EVENT_OVERWHELMING_GUILT, 15000);
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
                case EVENT_SHADOW_CLAW:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_SHADOW_CLAW, false);
                    events.ScheduleEvent(EVENT_SHADOW_CLAW, 10000);
                    break;
                case EVENT_OVERWHELMING_GUILT:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_OVERWHELMING_GUILT, false);
                    events.ScheduleEvent(EVENT_OVERWHELMING_GUILT, 15000);
                    break;
                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

#define GOSSIP_CHOICE_1 "Challenge the Patriarch."

enum ePandriarchWindfurSpells
{
    SPELL_THUNDERING_PALM = 109497,
    SPELL_WIND_SWORD = 113504,
    //    SPELL_WINDFUR_PUNCH     = 105497, <-- Needs to be scritped
};

enum ePandriarchWindfurEvents
{
    EVENT_THUNDERING_PALM = 1,
    EVENT_WIND_SWORD = 2,
    //    EVENT_WINDFUR_PUNCH        = 3,
};

class mob_pandriarch_windfur : public CreatureScript
{
public:
    mob_pandriarch_windfur() : CreatureScript("mob_pandriarch_windfur")
    {
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_CHOICE_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        player->SEND_GOSSIP_MENU(75009, creature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();

        if (action == GOSSIP_ACTION_INFO_DEF + 1)
        {
            if (player->GetQuestStatus(29920) == QUEST_STATUS_INCOMPLETE)
            {
                creature->setFaction(14);
                creature->SetReactState(REACT_DEFENSIVE);
                creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
                creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                creature->AI()->Reset();
                creature->CombatStart(player, true);
            }
            player->CLOSE_GOSSIP_MENU();
        }

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_pandriarch_windfurAI(creature);
    }

    struct mob_pandriarch_windfurAI : public ScriptedAI
    {
        mob_pandriarch_windfurAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;
        uint64 playerGuid;

        void Reset()
        {
            events.Reset();

            events.ScheduleEvent(EVENT_THUNDERING_PALM, urand(3000, 7000));
            events.ScheduleEvent(EVENT_WIND_SWORD, urand(8000, 10000));
            //                events.ScheduleEvent(EVENT_WINDFUR_PUNCH, urand (13000, 17000));
        }

        void DamageTaken(Unit* attacker, uint32& damage)
        {
            if (Player* player = attacker->ToPlayer())
            {
                if (me->HealthBelowPctDamaged(10, damage))
                {
                    damage = 0;
                    me->CombatStop();
                    me->GetMotionMaster()->MovePoint(0, 1996.76001f, -2216.780029f, 247.725006f);
                    me->setFaction(35);
                    me->SetFullHealth();
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    player->KilledMonsterCredit(56206);
                }

                if (damage > me->GetHealth())
                    damage = 0;
            }
        }

        void EnterCombat(Unit* who)
        {
            if (Player* player = who->ToPlayer())
            {
                if (player->GetQuestStatus(29920) == QUEST_STATUS_INCOMPLETE)
                    return;
                else
                {
                    me->CombatStop();
                    me->setFaction(35);
                }
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
                case EVENT_THUNDERING_PALM:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_THUNDERING_PALM, false);
                    events.ScheduleEvent(EVENT_THUNDERING_PALM, 10000);
                    break;
                case EVENT_WIND_SWORD:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_WIND_SWORD, false);
                    events.ScheduleEvent(EVENT_WIND_SWORD, 15000);
                    break;
                    /*                        case EVENT_WINDFUR_PUNCH:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                    me->CastSpell(target, SPELL_WINDFUR_PUNCH, false);
                    events.ScheduleEvent(EVENT_WINDFUR_PUNCH,      15000);
                    break;*/
                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

enum ePandriarchBramblestaffSpells
{
    SPELL_ROLL = 113512,
    SPELL_STAFF_STRIKE = 84647,
    SPELL_THROW_BRAMBLESTAFF = 106763,
    //    SPELL_WHIRLWIND              = 15576,  <-- Needs to be scripted
    //    SPELL_WHIRLWIND_2            = 17207,  <-- Needs to be scripted
};

enum ePandriarchBramblestaffEvents
{
    EVENT_ROLL = 1,
    EVENT_STAFF_STRIKE = 2,
    EVENT_THROW_BRAMBLESTAFF = 3,
    //    EVENT_WHIRLWIND            = 4,
    //    EVENT_WHIRLWIND_2          = 5,
};

class mob_pandriarch_bramblestaff : public CreatureScript
{
public:
    mob_pandriarch_bramblestaff() : CreatureScript("mob_pandriarch_bramblestaff")
    {
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_CHOICE_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        player->SEND_GOSSIP_MENU(75010, creature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();

        if (action == GOSSIP_ACTION_INFO_DEF + 1)
        {
            if (player->GetQuestStatus(29920) == QUEST_STATUS_INCOMPLETE)
            {
                creature->setFaction(14);
                creature->SetReactState(REACT_DEFENSIVE);
                creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
                creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                creature->AI()->Reset();
                creature->CombatStart(player, true);
            }
            player->CLOSE_GOSSIP_MENU();
        }

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_pandriarch_bramblestaffAI(creature);
    }

    struct mob_pandriarch_bramblestaffAI : public ScriptedAI
    {
        mob_pandriarch_bramblestaffAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;
        uint64 playerGuid;

        void Reset()
        {
            events.Reset();

            events.ScheduleEvent(EVENT_ROLL, urand(3000, 7000));
            events.ScheduleEvent(EVENT_STAFF_STRIKE, urand(8000, 10000));
            events.ScheduleEvent(EVENT_THROW_BRAMBLESTAFF, urand(13000, 17000));
            //                events.ScheduleEvent(EVENT_WHIRLWIND, urand (20000, 23000));
            //                events.ScheduleEvent(EVENT_WHIRLWIND_2, urand (24000, 27000));
        }

        void DamageTaken(Unit* attacker, uint32& damage)
        {
            if (Player* player = attacker->ToPlayer())
            {
                if (me->HealthBelowPctDamaged(10, damage) || damage > me->GetHealth())
                {
                    damage = 0;
                    me->CombatStop();
                    me->GetMotionMaster()->MovePoint(0, 1862.300049f, -2325.060059f, 257.062012f);
                    me->setFaction(35);
                    me->SetFullHealth();
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    player->KilledMonsterCredit(56209);
                }
            }
        }

        void EnterCombat(Unit* who)
        {
            if (Player* player = who->ToPlayer())
            {
                if (player->GetQuestStatus(29920) == QUEST_STATUS_INCOMPLETE)
                    return;
                else
                {
                    me->CombatStop();
                    me->setFaction(35);
                }
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
                case EVENT_ROLL:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_ROLL, false);
                    events.ScheduleEvent(EVENT_ROLL, 10000);
                    break;
                case EVENT_STAFF_STRIKE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_STAFF_STRIKE, false);
                    events.ScheduleEvent(EVENT_STAFF_STRIKE, 10000);
                    break;
                case EVENT_THROW_BRAMBLESTAFF:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_THROW_BRAMBLESTAFF, false);
                    events.ScheduleEvent(EVENT_THROW_BRAMBLESTAFF, 10000);
                    break;
                    /*                        case EVENT_WHIRLWIND:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                    me->CastSpell(target, SPELL_WHIRLWIND, false);
                    events.ScheduleEvent(EVENT_WHIRLWIND,      10000);
                    break;
                    case EVENT_WHIRLWIND_2:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                    me->CastSpell(target, SPELL_WHIRLWIND_2, false);
                    events.ScheduleEvent(EVENT_WHIRLWIND_2,      10000);
                    break;*/
                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

enum ePandriarchGoldendraftSpells
{
    SPELL_EXPLOSIVE_LAGER = 104909,
    SPELL_FIRE_ALE = 105091,
};

enum ePandriarchGoldendraftEvents
{
    EVENT_EXPLOSIVE_LAGER = 1,
    EVENT_FIRE_ALE = 2,
};

class mob_pandriarch_goldendraft : public CreatureScript
{
public:
    mob_pandriarch_goldendraft() : CreatureScript("mob_pandriarch_goldendraft")
    {
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_CHOICE_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        player->SEND_GOSSIP_MENU(75010, creature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();

        if (action == GOSSIP_ACTION_INFO_DEF + 1)
        {
            if (player->GetQuestStatus(29920) == QUEST_STATUS_INCOMPLETE)
            {
                creature->setFaction(14);
                creature->SetReactState(REACT_DEFENSIVE);
                creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
                creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                creature->AI()->Reset();
                creature->CombatStart(player, true);
            }
            player->CLOSE_GOSSIP_MENU();
        }

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_pandriarch_goldendraftAI(creature);
    }

    struct mob_pandriarch_goldendraftAI : public ScriptedAI
    {
        mob_pandriarch_goldendraftAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;
        uint64 playerGuid;

        void Reset()
        {
            events.Reset();

            events.ScheduleEvent(EVENT_EXPLOSIVE_LAGER, urand(3000, 7000));
            events.ScheduleEvent(EVENT_FIRE_ALE, urand(8000, 10000));
        }

        void DamageTaken(Unit* attacker, uint32& damage)
        {
            if (Player* player = attacker->ToPlayer())
            {
                if (me->HealthBelowPctDamaged(10, damage) || damage > me->GetHealth())
                {
                    damage = 0;
                    me->CombatStop();
                    me->GetMotionMaster()->MovePoint(0, 1942.630005f, -2290.530029f, 240.429001f);
                    me->setFaction(35);
                    me->SetFullHealth();
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    player->KilledMonsterCredit(56210);
                }
            }
        }

        void EnterCombat(Unit* who)
        {
            if (Player* player = who->ToPlayer())
            {
                if (player->GetQuestStatus(29920) == QUEST_STATUS_INCOMPLETE)
                    return;
                else
                {
                    me->CombatStop();
                    me->setFaction(35);
                }
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
                case EVENT_EXPLOSIVE_LAGER:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_EXPLOSIVE_LAGER, false);
                    events.ScheduleEvent(EVENT_EXPLOSIVE_LAGER, 10000);
                    break;
                case EVENT_FIRE_ALE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_FIRE_ALE, false);
                    events.ScheduleEvent(EVENT_FIRE_ALE, 10000);
                    break;
                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

enum eBigBaoSpells
{
    SPELL_FORCE_BURST = 129858,
    SPELL_KNOCK_AWAY = 129837,
    SPELL_PULL_CLOSE = 129839,
    SPELL_RACE_AGAINST_THE_CLOCK = 129772,
    SPELL_WAR_STOMP = 129831
};

enum eBigBaoEvents
{
    EVENT_FORCE_BURST = 1,
    EVENT_KNOCK_AWAY = 2,
    EVENT_PULL_CLOSE = 3,
    EVENT_WAR_STOMP = 4
};

#define GOSSIP_CHOICE_2 "Let's see which one of us is the better student. I challenge you to a duel !"

class mob_big_bao : public CreatureScript
{
public:
    mob_big_bao() : CreatureScript("mob_big_bao")
    {
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_CHOICE_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        player->SEND_GOSSIP_MENU(75012, creature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();

        if (action == GOSSIP_ACTION_INFO_DEF + 1)
        {
            if (player->GetQuestStatus(31718) == QUEST_STATUS_INCOMPLETE)
            {
                creature->setFaction(14);
                creature->SetReactState(REACT_DEFENSIVE);
                creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                creature->AI()->Reset();
                creature->CombatStart(player, true);
            }
            player->CLOSE_GOSSIP_MENU();
        }

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_big_baoAI(creature);
    }

    struct mob_big_baoAI : public ScriptedAI
    {
        mob_big_baoAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;
        uint64 playerGuid;

        void Reset()
        {
            events.Reset();

            events.ScheduleEvent(EVENT_FORCE_BURST, 3000);
            events.ScheduleEvent(EVENT_KNOCK_AWAY, 8000);
            events.ScheduleEvent(EVENT_PULL_CLOSE, 13000);
            events.ScheduleEvent(EVENT_WAR_STOMP, 18000);
        }

        void EnterCombat(Unit* who)
        {
            if (Player* player = who->ToPlayer())
            {
                if (player->GetQuestStatus(31718) == QUEST_STATUS_INCOMPLETE)
                    player->CastSpell(player, SPELL_RACE_AGAINST_THE_CLOCK);
                else
                {
                    me->CombatStop();
                    me->setFaction(35);
                }
            }
        }

        void DamageTaken(Unit* attacker, uint32& damage)
        {
            if (Player* player = attacker->ToPlayer())
            {
                if (me->HealthBelowPctDamaged(10, damage) || damage > me->GetHealth())
                {
                    damage = 0;
                    me->CombatStop();
                    me->GetMotionMaster()->MovePoint(0, 1604.75f, -2562.139893f, 153.134003f);
                    me->setFaction(35);
                    me->SetFullHealth();
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    player->KilledMonsterCredit(58508);
                }
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
                case EVENT_FORCE_BURST:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_FORCE_BURST, false);
                    events.ScheduleEvent(EVENT_FORCE_BURST, 10000);
                    break;
                case EVENT_KNOCK_AWAY:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_KNOCK_AWAY, false);
                    events.ScheduleEvent(EVENT_KNOCK_AWAY, 10000);
                    break;
                case EVENT_PULL_CLOSE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_PULL_CLOSE, false);
                    events.ScheduleEvent(EVENT_PULL_CLOSE, 10000);
                    break;
                case EVENT_WAR_STOMP:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_FIRE_ALE, false);
                    events.ScheduleEvent(SPELL_WAR_STOMP, 10000);
                    break;
                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

enum eHutiaSpells
{
    SPELL_FRENZY_2 = 19615,
    SPELL_SPIRIT_BEAST_BLESSING = 127830,
    SPELL_SPIRIT_HEAL_2 = 138477,
    SPELL_SPIRIT_MEND = 90361,
    SPELL_STRONG_WILL = 138472
};

enum eHutiaEvents
{
    EVENT_FRENZY_2 = 1,
    EVENT_SPIRIT_BEAST_BLESSING = 2,
    EVENT_SPIRIT_HEAL = 3
};

class mob_hutia : public CreatureScript
{
public:
    mob_hutia() : CreatureScript("mob_hutia")
    {
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_hutiatAI(creature);
    }

    struct mob_hutiatAI : public ScriptedAI
    {
        mob_hutiatAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();

            me->CastSpell(me, SPELL_SPIRIT_MEND, false);
            me->CastSpell(me, SPELL_STRONG_WILL, false);

            events.ScheduleEvent(EVENT_FRENZY_2, 7000);
            events.ScheduleEvent(EVENT_SPIRIT_BEAST_BLESSING, 12000);
            events.ScheduleEvent(EVENT_SPIRIT_HEAL, 19000);
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
                case EVENT_FRENZY_2:
                    me->CastSpell(me, SPELL_FRENZY_2, false);
                    events.ScheduleEvent(EVENT_FRENZY_2, 30000);
                    break;
                case EVENT_SPIRIT_BEAST_BLESSING:
                    me->CastSpell(me, SPELL_SPIRIT_BEAST_BLESSING, false);
                    events.ScheduleEvent(EVENT_SPIRIT_BEAST_BLESSING, 40000);
                    break;
                case EVENT_SPIRIT_HEAL:
                    me->CastSpell(me, SPELL_SPIRIT_HEAL_2, false);
                    events.ScheduleEvent(EVENT_SPIRIT_HEAL, 40000);
                    break;
                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

class npc_nectarbreeze_farmer : public CreatureScript
{
public:
    npc_nectarbreeze_farmer() : CreatureScript("npc_nectarbreeze_farmer")
    {
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (player->GetQuestStatus(29579) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Get to Hanae's house. It's safe there.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();

        if (action == GOSSIP_ACTION_INFO_DEF + 1)
        {
            if (player->GetQuestStatus(29579) == QUEST_STATUS_INCOMPLETE)
            {
                player->CastSpell(player, 102469, true);
                creature->AI()->Talk(0);
                creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                creature->ForcedDespawn(2000);
            }
            player->CLOSE_GOSSIP_MENU();
        }

        return true;
    }
};

class npc_windward_hatchling : public CreatureScript
{
public:
    npc_windward_hatchling() : CreatureScript("npc_windward_hatchling") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_windward_hatchlingAI(creature);
    }

    struct npc_windward_hatchlingAI : public ScriptedAI
    {
        npc_windward_hatchlingAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset()
        {
        }

        void SpellHit(Unit* caster, SpellInfo const* spell)
        {
            if (auto player = caster->ToPlayer())
                if (player->GetQuestStatus(30136) == QUEST_STATUS_INCOMPLETE && spell->Id == 110171)
                    if (auto summon = player->SummonCreature(58248, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 120000))
                    {
                        summon->SetOwnerGUID(player->GetGUID());
                        summon->SetDisplayId(me->GetDisplayId());
                        summon->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, M_PI);
                        me->ForcedDespawn();
                    }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };
};

class npc_windward_nest_trigger : public CreatureScript
{
public:
    npc_windward_nest_trigger() : CreatureScript("npc_windward_nest_trigger") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_windward_nest_triggerAI(creature);
    }

    struct npc_windward_nest_triggerAI : public ScriptedAI
    {
        npc_windward_nest_triggerAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() { }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() == TYPEID_UNIT && who->GetEntry() == 58248)
            {
                if (who->GetDistance(me) > 5.0f)
                    return;

                if (auto owner = who->GetCharmerOrOwnerPlayerOrPlayerItself())
                {
                    owner->KilledMonsterCredit(58246);
                    who->GetMotionMaster()->MoveFollow(me, 0, 0);
                    who->ToCreature()->SetOwnerGUID(0);
                    who->ToCreature()->ForcedDespawn(1000);
                }
            }
        }
    };
};


class npc_instructor_skythorn : public CreatureScript
{
public:
    npc_instructor_skythorn() : CreatureScript("npc_instructor_skythorn") {}

    struct npc_instructor_skythornAI : public ScriptedAI
    {
        npc_instructor_skythornAI(Creature* creature) : ScriptedAI(creature) {}

        uint64 playerGUID;
        uint8 eventPhase;
        uint32 eventTimer;

        void Reset()
        {
            eventTimer = 0;
            playerGUID = 0;
            eventPhase = 0;
        }

        void BeginEvent(Player* player)
        {
            eventTimer = 10000;
            playerGUID = player->GetGUID();
            Talk(0, playerGUID);
            eventPhase = 1;
        }

        void UpdateAI(uint32 const diff)
        {
            if (eventPhase)
            {
                if (eventTimer < diff)
                {
                    Talk(eventPhase, playerGUID);
                    eventTimer = 8000;
                    ++eventPhase;
                    if (eventPhase == 4)
                    {
                        if (auto player = Player::GetPlayer(*me, playerGUID))
                            player->KilledMonsterCredit(58315);
                        Reset();
                    }
                }
                else
                    eventTimer -= diff;
            }
        }
    };

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
    {
        if (quest->GetQuestId() == 30142)
            CAST_AI(npc_instructor_skythorn::npc_instructor_skythornAI, creature->AI())->BeginEvent(player);

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_instructor_skythornAI(creature);
    }
};

class npc_the_pearlfin_situation_q : public CreatureScript
{
public:
    npc_the_pearlfin_situation_q() : CreatureScript("npc_the_pearlfin_situation_q") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (creature->isVendor())
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

        if (player->GetQuestStatus(29883) == QUEST_STATUS_INCOMPLETE)
        {
            std::string gossip = "";
            switch (creature->GetEntry())
            {
            case 59058:
                gossip = "Please allow us a chance to prove our friendship. We wish you no harm";
                break;
            case 56693:
                gossip = "What are you doing?";
                break;
            case 56690:
                gossip = "My friends and I come with peaceful intentions.";
                break;
            case 54960:
                gossip = "I come from the Alliance. We wish to be allies, not enemies.";
                break;
            }
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, gossip, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        }

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF + 1)
        {
            creature->AI()->Talk(0);
            player->KilledMonsterCredit(creature->GetEntry());
            player->CLOSE_GOSSIP_MENU();
        }
        else if (action == GOSSIP_ACTION_TRADE)
            player->GetSession()->SendListInventory(creature->GetGUID());

        return false;
    }
};

enum events
{
    EVENT_LIGHTBREATH = 1,
    EVENT_GENERATE_MOVE = 2
};

// ##npc entry 58213##
class npc_windward_matriarch : public CreatureScript
{
public:
    npc_windward_matriarch() : CreatureScript("npc_windward_matriarch")
    {
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_windward_matriarchAI(creature);
    }

    struct npc_windward_matriarchAI : public ScriptedAI
    {
        npc_windward_matriarchAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void Reset()
        {
            events.Reset();
            events.ScheduleEvent(EVENT_LIGHTBREATH, 1500);
        }


        void EnterCombat(Unit* /*who*/) { events.ScheduleEvent(EVENT_LIGHTBREATH, 1500); }

        void JustDied(Unit* /*killer*/) {}

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_LIGHTBREATH:
                    DoCast(SelectTarget(SELECT_TARGET_TOPAGGRO), 129013);
                    events.ScheduleEvent(EVENT_LIGHTBREATH, 6000);
                    break;
                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

// ##npc entry 58416##
class npc_injured_hatchling : public CreatureScript
{
public:
    npc_injured_hatchling() : CreatureScript("npc_injured_hatchling")
    {
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_injured_hatchlingAI(creature);
    }

    struct npc_injured_hatchlingAI : public ScriptedAI
    {
        npc_injured_hatchlingAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetHealth((uint32)me->GetMaxHealth()*0.2f);
        }
    };
};
void AddSC_jade_forest()
{
    //Rare mobs
    new mob_kor_nas_nightsavage();
    new mob_krax_ik();
    new mob_mister_ferocious();
    new mob_morgrinn_crackfang();
    new mob_ferdinand();
    new mob_aethis();
    new mob_sarnak();
    new mob_urobi_walker();
    //Elite mobs
    new mob_shadow_of_doubt();
    new mob_akkalar();
    new mob_grookin_outrunner();
    new mob_bamboo_python();
    new mob_lurking_tiger();
    new mob_rakira();
    new mob_ro_shen();
    new mob_sha_reminant();
    new mob_hutia();
    //Standard Mobs
    new mob_pandriarch_windfur();
    new mob_pandriarch_bramblestaff();
    new mob_pandriarch_goldendraft();
    new mob_big_bao();
    //Quest scripts
    new npc_nectarbreeze_farmer();
    new npc_windward_hatchling();
    new npc_windward_nest_trigger();
    new npc_instructor_skythorn();
    new npc_the_pearlfin_situation_q();
    new npc_windward_matriarch();
    new npc_injured_hatchling();
}