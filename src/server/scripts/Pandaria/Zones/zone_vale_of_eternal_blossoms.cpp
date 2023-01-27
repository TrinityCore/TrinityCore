
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"

enum eZhaoSpells
{
    SPELL_LAVA_BURST        =  75068,
    SPELL_LIGHTNING_SPEAR   = 116570,
};

enum eZhaoEvents
{
    EVENT_LAVA_BURST        = 1,
    EVENT_LIGHTNING_SPEAR   = 2,
};

enum eSpells
{
    SPELL_JADE_FIRE         = 127422,
    SPELL_JADE_STRENGHT     = 127462,
    SPELL_LIGHTNING_BREATH  = 126491,
    SPELL_LIGHTNING_POOL    = 129695,
    SPELL_LIGHTNING_WHIRL   = 126522,
};
class mob_zhao_jin : public CreatureScript
{
    public:
        mob_zhao_jin() : CreatureScript("mob_zhao_jin")
		{ 
		}

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_zhao_jinAI(creature);
        }

        struct mob_zhao_jinAI : public ScriptedAI
        {
            mob_zhao_jinAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset()
            {
                events.Reset();
                
                events.ScheduleEvent(EVENT_LAVA_BURST,      10000);
                events.ScheduleEvent(EVENT_LIGHTNING_SPEAR, 15000);
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
                        case EVENT_LAVA_BURST:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_LAVA_BURST, false);
                            events.ScheduleEvent(EVENT_LAVA_BURST,      10000);
                            break;
                        case EVENT_LIGHTNING_SPEAR:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_LIGHTNING_SPEAR, false);
                            events.ScheduleEvent(EVENT_LIGHTNING_SPEAR, 15000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

#define SAY_LAO_1   "Come quickly. There is a gap in their defenses."
#define SAY_LAO_2   "Let's go while the way is clear. The cave is just ahead."
#define SAY_LAO_3   "Let's wait for the next wave."
#define SAY_LAO_4   "Stop. Let them pass."
#define SAY_LAO_5   "Wait for a safe moment, then plant the explosives at the mouth of the cave."
#define SAY_LAO_6   "Well, that should put a damper on their plans. Good work. I trust you can get back on your own."

class npc_lao_softfoot : public CreatureScript
{
    public:
        npc_lao_softfoot() : CreatureScript("npc_lao_softfoot") 
		{ 
		}

        bool OnGossipHello(Player* player, Creature* creature)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Start", GOSSIP_SENDER_MAIN,  GOSSIP_ACTION_INFO_DEF);
            
            player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
        {
            if (action == GOSSIP_ACTION_INFO_DEF)
                creature->AI()->DoAction(1);
            return true;
        }

        struct npc_lao_softfootAI : public npc_escortAI
        {
            npc_lao_softfootAI(Creature* creature) : npc_escortAI(creature) { }
            
            void Reset()
            {

            }

            void DoAction(const int32 action)
            {
                if (action == 1)
                    Start(true, true);
            }

            void WaypointReached(uint32 waypointId)
            {
            }

            void JustDied(Unit* /*killer*/)
            {
                if (HasEscortState(STATE_ESCORT_ESCORTING))
                    if (Player* player = GetPlayerForEscort())
                        player->FailQuest(30634); // Barring Entry
            }

            void UpdateAI(const uint32 uiDiff)
            {
                npc_escortAI::UpdateAI(uiDiff);

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_lao_softfootAI(creature);
        }
};

class mob_reanimated_jade_warrior : public CreatureScript
{
    public:
        mob_reanimated_jade_warrior() : CreatureScript("mob_reanimated_jade_warrior")
        {
        }

        struct mob_reanimated_jade_warriorAI : public ScriptedAI
        {
            mob_reanimated_jade_warriorAI(Creature* creature) : ScriptedAI(creature) { }

            uint32 jadeFireTimer;
            uint32 jadeStrenghtTimer;

            void Reset()
            {
                jadeFireTimer	  = urand(10000, 12000);
                jadeStrenghtTimer = urand(5000, 7000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;
                if (jadeFireTimer <= diff)
                {
                if (Unit* target = me->SelectNearestTarget(5.0f))
                    if (!target->IsFriendlyTo(me))
                        me->CastSpell(target, SPELL_JADE_FIRE, true);
                jadeFireTimer = urand(20000, 22000);
                }
                else
                    jadeFireTimer -= diff;

                if (jadeStrenghtTimer <= diff)
                {
                    me->CastSpell(me, SPELL_JADE_STRENGHT, true);
                    jadeStrenghtTimer = urand(20000, 22000);
                }
                else
                   jadeStrenghtTimer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_reanimated_jade_warriorAI(creature);
        }
};

class mob_subjuged_serpent : public CreatureScript
{
    public:
        mob_subjuged_serpent() : CreatureScript("mob_subjuged_serpent") 
		{
		}

        struct mob_subjuged_serpentAI : public ScriptedAI
        {
            mob_subjuged_serpentAI(Creature* creature) : ScriptedAI(creature) { }

            uint32 lightningBreathTimer;
            uint32 lightningPoolTimer;
            uint32 lightningWhirlTimer;

            void Reset()
            {
                lightningBreathTimer = urand(2000, 3000);
                lightningPoolTimer   = urand(5000, 7000);
                lightningWhirlTimer  = urand(3000, 6000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (lightningBreathTimer <= diff)
                {
                    if (Unit* target = me->SelectNearestTarget(5.0f))
                        if (!target->IsFriendlyTo(me))
                        {
                            me->CastSpell(target, SPELL_LIGHTNING_BREATH, true);
                            lightningBreathTimer = urand(13000, 18000);
                        }
                }
                else
                    lightningBreathTimer -= diff;

                if (lightningPoolTimer <= diff)
                {
                    if (Unit* target = me->SelectNearestTarget(5.0f))
                        if (!target->IsFriendlyTo(me))
                        {
                            me->CastSpell(target, SPELL_LIGHTNING_POOL, true);
                            lightningPoolTimer = urand(27000, 29000);
                        }
                 }
                 else
                     lightningPoolTimer -= diff;

                 if (lightningWhirlTimer <= diff)
                 {
                     if (Unit* target = me->SelectNearestTarget(5.0f))
                         if (!target->IsFriendlyTo(me))
                         {
                             me->CastSpell(target, SPELL_LIGHTNING_WHIRL, true);
                             lightningWhirlTimer = urand(7000, 10000);
                         }
                 }
                 else
                 lightningWhirlTimer -= diff;

                 DoMeleeAttackIfReady();
                 }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_subjuged_serpentAI(creature);
        }
};

enum eShaoTienBehemothSpells
{
    SPELL_CRUSHING_STOMP     = 131046,
    SPELL_GROUND_STOMP       = 127236,
    SPELL_PARALYZED          = 129553,
    SPELL_THUNDERING_SLAM    = 131043,
};

enum eShaoTienBehemothEvents
{
    EVENT_CRUSHING_STOMP        = 1,
    EVENT_GROUND_STOMP          = 2,
    EVENT_PARALYZED             = 3,
    EVENT_THUNDERING_SLAM       = 4,
};

class mob_shao_tien_behemoth : public CreatureScript
{
    public:
        mob_shao_tien_behemoth() : CreatureScript("mob_shao_tien_behemoth")
        {
        }

        struct mob_shao_tien_behemothAI : public ScriptedAI
        {
            mob_shao_tien_behemothAI(Creature* creature) : ScriptedAI(creature) { }

            uint32 lightningBreathTimer;
            uint32 lightningPoolTimer;
            uint32 lightningWhirlTimer;
            EventMap events;

            void Reset()
            {
                events.Reset();

                events.ScheduleEvent(EVENT_CRUSHING_STOMP,           8000);
                events.ScheduleEvent(EVENT_GROUND_STOMP,            12000);
                events.ScheduleEvent(EVENT_PARALYZED,               17000);
                events.ScheduleEvent(EVENT_THUNDERING_SLAM,         25000);
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
                        case EVENT_CRUSHING_STOMP:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_CRUSHING_STOMP, false);
                            events.ScheduleEvent(EVENT_CRUSHING_STOMP, 320000);
                            break;
                        case EVENT_GROUND_STOMP:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(me, SPELL_GROUND_STOMP, false);
                            events.ScheduleEvent(EVENT_GROUND_STOMP, 17000);
                            break;
                        case EVENT_PARALYZED:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_PARALYZED, false);
                            events.ScheduleEvent(EVENT_PARALYZED, 21000);
                            break;
                        case EVENT_THUNDERING_SLAM:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_THUNDERING_SLAM, false);
                            events.ScheduleEvent(EVENT_THUNDERING_SLAM, 25000);
                            break;
                        default:
                            break;
                    }
                }
                 DoMeleeAttackIfReady();
             }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_shao_tien_behemothAI(creature);
        }
};

enum eShaoTienSurvivorSpells
{
    SPELL_STEALTH                =  77806,
    SPELL_RAIN_OF_SHADOW         = 127487,
    SPELL_SHADOW_EMPOWERMENT     = 127486,
    SPELL_SUCCUMB_TO_SHADOWS     = 127484,
    SPELL_SHADO_PAN_FLARE        = 123193
};

enum eShaoTienurvivorEvents
{
    EVENT_STEALTH                   = 1,
    EVENT_RAIN_OF_SHADOW            = 2,
    EVENT_SHADOW_EMPOWERMENT        = 3,
    EVENT_SUCCUMB_TO_SHADOWS        = 4
};

class mob_shao_tien_surveyor : public CreatureScript
{
    public:
        mob_shao_tien_surveyor() : CreatureScript("mob_shao_tien_surveyor")
        {
        }

        struct mob_shao_tien_surveyorAI : public ScriptedAI
        {
            mob_shao_tien_surveyorAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap events;

            void Reset()
            {
                me->CastSpell(me, SPELL_STEALTH, true);
                events.Reset();
                events.ScheduleEvent(EVENT_CRUSHING_STOMP,           8000);
                events.ScheduleEvent(EVENT_GROUND_STOMP,            12000);
                events.ScheduleEvent(EVENT_PARALYZED,               17000);
                events.ScheduleEvent(EVENT_THUNDERING_SLAM,         25000);
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
                        case EVENT_CRUSHING_STOMP:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_CRUSHING_STOMP, false);
                            events.ScheduleEvent(EVENT_CRUSHING_STOMP, 320000);
                            break;
                        case EVENT_GROUND_STOMP:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(me, SPELL_GROUND_STOMP, false);
                            events.ScheduleEvent(EVENT_GROUND_STOMP, 17000);
                            break;
                        case EVENT_PARALYZED:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_PARALYZED, false);
                            events.ScheduleEvent(EVENT_PARALYZED, 21000);
                            break;
                        case EVENT_THUNDERING_SLAM:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_THUNDERING_SLAM, false);
                            events.ScheduleEvent(EVENT_THUNDERING_SLAM, 25000);
                            break;
                        default:
                            break;
                    }
                }
                 DoMeleeAttackIfReady();
             }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_shao_tien_surveyorAI(creature);
        }
};

class spell_shadow_pan_flare : public SpellScriptLoader
{
    public:
        spell_shadow_pan_flare() : SpellScriptLoader("spell_shadow_pan_flare") { }

        class spell_shadow_pan_flare_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_shadow_pan_flare_SpellScript);

            void HandleOnHit()
            {
                if (Unit* caster = GetCaster()->ToPlayer())
                {
                    std::list<Creature*> surveyorList;
                    GetCreatureListWithEntryInGrid(surveyorList, caster, 59379, 100.0f);

                    for (auto itr : surveyorList)
                        itr->RemoveAura(SPELL_STEALTH);
                }
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_shadow_pan_flare_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_shadow_pan_flare_SpellScript();
        }
};

void AddSC_vale_of_eternal_blossoms()
{
    new mob_zhao_jin();
    new npc_lao_softfoot();
    new mob_reanimated_jade_warrior();
    new mob_subjuged_serpent();
    new mob_shao_tien_behemoth();
    new mob_shao_tien_surveyor();
    new spell_shadow_pan_flare();
}
