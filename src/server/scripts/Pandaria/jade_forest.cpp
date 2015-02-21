#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"

enum eShadowOfDoubtSpells
{
    SPELL_DEAFENED        = 108918,
    SPELL_SHA_BOLT        = 126139,
    SPELL_GROWING_DOUBT   = 126147,
};

enum eShadowOfDoubtEvents
{
    EVENT_DEAFENED              = 1,
    EVENT_GROWING_DOUBT         = 2,
    EVENT_SHA_BOLT              = 3,
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
                
                events.ScheduleEvent(EVENT_DEAFENED,      30000);
                events.ScheduleEvent(EVENT_GROWING_DOUBT,  9000);
                events.ScheduleEvent(EVENT_SHA_BOLT,	  15000);
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
                            events.ScheduleEvent(EVENT_DEAFENED,      30000);
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
    SPELL_SHADOWBOLT       = 125212,
    SPELL_VOIDCLOUD        = 125241,
};

enum eKorNasEvents
{
    EVENT_SHADOWBOLT    = 1,
    EVENT_VOIDCLOUD     = 2,
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

                events.ScheduleEvent(EVENT_SHADOWBOLT,      50000);
                events.ScheduleEvent(EVENT_VOIDCLOUD,  15000);
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
                        case EVENT_SHADOWBOLT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SHADOWBOLT, false);
                            events.ScheduleEvent(EVENT_SHADOWBOLT,      70000);
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
    SPELL_BLADE_FURY       = 125370,
    SPELL_STEALTH          = 128933,
    SPELL_TORNADO          = 125398,
    SPELL_TORNADO_DMG      = 131693,
    SPELL_WINDSONG         = 125373,
};

enum eKraxIkEvents
{
    EVENT_BLADE_FURY       = 1,
    EVENT_TORNADO          = 2,
    EVENT_WINDSONG         = 3,
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

                events.ScheduleEvent(EVENT_TORNADO,       5000);
                events.ScheduleEvent(EVENT_BLADE_FURY,   25000);
                events.ScheduleEvent(EVENT_WINDSONG,     30000);
            }

            void EnterCombat(Unit* attacker)
            {
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
                            events.ScheduleEvent(EVENT_TORNADO,      70000);
                            break;
                        case EVENT_BLADE_FURY:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_BLADE_FURY, false);
                            events.ScheduleEvent(EVENT_BLADE_FURY,      20000);
                            break;
                        case EVENT_WINDSONG:
                            me->CastSpell(me, SPELL_WINDSONG, false);
                            events.ScheduleEvent(EVENT_WINDSONG,      30000);
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
    SPELL_GOING_BANANAS     = 125363,
    SPELL_BANANARANG		= 125311,
    SPELL_TOSS_FILTH		= 125365,
};

enum eMisterFerociousEvents
{
    EVENT_GOING_BANANAS         = 1,
    EVENT_BANANARANG			= 2,
    EVENT_TOSS_FILTH		    = 3,
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

                events.ScheduleEvent(EVENT_GOING_BANANAS,		12000);
                events.ScheduleEvent(EVENT_BANANARANG,			 8000);
                events.ScheduleEvent(EVENT_TOSS_FILTH,			15000);
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
                        case EVENT_GOING_BANANAS:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_GOING_BANANAS, false);
                            events.ScheduleEvent(EVENT_GOING_BANANAS,      10000);
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

enum eAkkalarSpells
{
    SPELL_BOUCLIER_D_EAU        = 79892,
    SPELL_BOUCLIER_D_EAU_2		= 34828,
    SPELL_BOUCLIER_DE_TERRE		= 79927,
    SPELL_CARAPACE_BOUCLIER		= 83488,
    SPELL_MOT_DE_POUVOIR		= 11835,
};

enum eAkkalarEvents
{
    EVENT_BOUCLIER_D_EAU            = 1,
    EVENT_BOUCLIER_D_EAU_2			= 2,
    EVENT_BOUCLIER_DE_TERRE		    = 3,
    EVENT_CARAPACE_BOUCLIER			= 4,
    EVENT_MOT_DE_POUVOIR		    = 5,
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

                events.ScheduleEvent(EVENT_BOUCLIER_D_EAU,		10000);
                events.ScheduleEvent(EVENT_BOUCLIER_D_EAU_2,    20000);
                events.ScheduleEvent(EVENT_BOUCLIER_DE_TERRE,	30000);
                events.ScheduleEvent(EVENT_CARAPACE_BOUCLIER,	40000);
                events.ScheduleEvent(EVENT_MOT_DE_POUVOIR,		50000);
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
                            events.ScheduleEvent(EVENT_BOUCLIER_D_EAU,     620000);
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
    SPELL_SHOOT		= 23337,
    SPELL_CLEAVE 	= 40505,
};

enum eGrookinOutrunnerEvents
{
    EVENT_SHOOT             = 1,
    EVENT_CLEAVE		    = 2,
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

                events.ScheduleEvent(EVENT_SHOOT,		7000);
                events.ScheduleEvent(EVENT_CLEAVE,	    12000);
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
                            events.ScheduleEvent(EVENT_SHOOT,     10000);
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
    SPELL_SWAMP_FEVER		= 116026,
};

enum eBambooPythonEvents
{
    EVENT_SWAMP_FEVER             = 1,
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

                events.ScheduleEvent(EVENT_SWAMP_FEVER,		7000);
            }

            void EnterCombat(Unit* attacker)
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
                            events.ScheduleEvent(EVENT_SWAMP_FEVER,     15000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

#define    SPELL_STEALTH	77806

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

            void UpdateAI(const uint32 diff)
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
    SPELL_BLOODY_PREY	        	= 131145,
    SPELL_CLAW_RIP              	= 131130,
    SPELL_GROWL 	                = 2649,
    SPELL_HOWL_OF_THE_DENMOTHER 	= 131199,
    SPELL_ROAR_OF_COURAGE	        = 93435,
};

enum eRakiraEvents
{
    EVENT_BLOODY_PREY               = 1,
    EVENT_CLAW_RIP		            = 2,
    EVENT_GROWL                     = 3,
    EVENT_HOWL_OF_THE_DENMOTHER	    = 4,
    EVENT_ROAR_OF_COURAGE		    = 5,
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

                events.ScheduleEvent(EVENT_BLOODY_PREY,		             8000);
                events.ScheduleEvent(EVENT_CLAW_RIP,	                15000);
                events.ScheduleEvent(EVENT_GROWL,	                  	22000);
                events.ScheduleEvent(EVENT_HOWL_OF_THE_DENMOTHER,	    30000);
                events.ScheduleEvent(EVENT_ROAR_OF_COURAGE,	            40000);
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
                            events.ScheduleEvent(EVENT_BLOODY_PREY,      10000);
                            break;
                        case EVENT_CLAW_RIP:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_CLAW_RIP, false);
                            events.ScheduleEvent(EVENT_CLAW_RIP,      15000);
                            break;
                        case EVENT_GROWL:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_GROWL, false);
                            events.ScheduleEvent(EVENT_GROWL,      22000);
                            break;
                        case EVENT_HOWL_OF_THE_DENMOTHER:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_HOWL_OF_THE_DENMOTHER, false);
                            events.ScheduleEvent(EVENT_HOWL_OF_THE_DENMOTHER,      30000);
                            break;
                        case EVENT_ROAR_OF_COURAGE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_ROAR_OF_COURAGE, false);
                            events.ScheduleEvent(EVENT_ROAR_OF_COURAGE,      47000);
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
    SPELL_CLAW_SLASH                = 131133,
    SPELL_BLOOD_CRAZED	        	= 131150,
    SPELL_BLOODTHIRST              	= 131141,
    SPELL_FRENZY	                =  19615,
};

enum eRoShenEvents
{
    EVENT_BLOOD_CRAZED              = 6,
    EVENT_BLOODTHIRST		        = 7,
    EVENT_CLAW_SLASH                = 8,
    EVENT_FRENZY		            = 9,
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

                events.ScheduleEvent(EVENT_BLOODY_PREY,          8000);
                events.ScheduleEvent(EVENT_CLAW_RIP,            15000);
                events.ScheduleEvent(EVENT_GROWL,               22000);
                events.ScheduleEvent(EVENT_ROAR_OF_COURAGE,     30000);
                events.ScheduleEvent(EVENT_BLOOD_CRAZED,        40000);
                events.ScheduleEvent(EVENT_BLOODTHIRST,         50000);
                events.ScheduleEvent(EVENT_CLAW_SLASH,          60000);
                events.ScheduleEvent(EVENT_FRENZY,              70000);
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
                            events.ScheduleEvent(EVENT_BLOODY_PREY,      10000);
                            break;
                        case EVENT_CLAW_RIP:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_CLAW_RIP, false);
                            events.ScheduleEvent(EVENT_CLAW_RIP,      15000);
                            break;
                        case EVENT_GROWL:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_GROWL, false);
                            events.ScheduleEvent(EVENT_GROWL,      28000);
                            break;
                        case EVENT_ROAR_OF_COURAGE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_ROAR_OF_COURAGE, false);
                            events.ScheduleEvent(EVENT_ROAR_OF_COURAGE,      70000);
                            break;
                        case EVENT_BLOOD_CRAZED:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_BLOOD_CRAZED, false);
                            events.ScheduleEvent(EVENT_BLOOD_CRAZED,      31000);
                            break;
                        case EVENT_BLOODTHIRST:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_BLOODTHIRST, false);
                            events.ScheduleEvent(EVENT_BLOODTHIRST,      40000);
                            break;
                        case EVENT_CLAW_SLASH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_CLAW_SLASH, false);
                            events.ScheduleEvent(EVENT_CLAW_SLASH,      25000);
                            break;
                        case EVENT_FRENZY:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_FRENZY, false);
                            events.ScheduleEvent(EVENT_FRENZY,      50000);
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
    SPELL_SHADOW_CLAW               = 116128,
    SPELL_OVERWHELMING_GUILT      	= 131150,
};

enum eShaReminantEvents
{
    EVENT_SHADOW_CLAW               = 1,
    EVENT_OVERWHELMING_GUILT        = 2,
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

                events.ScheduleEvent(EVENT_SHADOW_CLAW,          10000);
                events.ScheduleEvent(EVENT_OVERWHELMING_GUILT,   15000);
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
                            events.ScheduleEvent(EVENT_SHADOW_CLAW,      10000);
                            break;
                        case EVENT_OVERWHELMING_GUILT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_OVERWHELMING_GUILT, false);
                            events.ScheduleEvent(EVENT_OVERWHELMING_GUILT,      15000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

void AddSC_jade_forest()
{
    //Rare mobs
    new mob_kor_nas_nightsavage();
    new mob_krax_ik();
    new mob_mister_ferocious();
    //Elite mobs
    new mob_shadow_of_doubt();
    new mob_akkalar();
    new mob_grookin_outrunner();
    new mob_bamboo_python();
    new mob_lurking_tiger();
    new mob_rakira();
    new mob_ro_shen();
    new mob_sha_reminant();
}
