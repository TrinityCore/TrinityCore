/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
    @todo
        If the boss is to close to a scrap pile -> no summon  -- Needs retail confirmation
        Codestyle
*/

#include "ScriptMgr.h"
#include "CombatLogPackets.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "ulduar.h"
#include "Vehicle.h"

enum Spells
{
    SPELL_TYMPANIC_TANTRUM                      = 62776,
    SPELL_SEARING_LIGHT                         = 63018,

    SPELL_SUMMON_LIFE_SPARK                     = 64210,
    SPELL_SUMMON_VOID_ZONE                      = 64203,

    SPELL_GRAVITY_BOMB                          = 63024,

    SPELL_HEARTBREAK                            = 65737,

    // Cast by 33337 at Heartbreak:
    SPELL_RECHARGE_PUMMELER                     = 62831,    // Summons 33344
    SPELL_RECHARGE_SCRAPBOT                     = 62828,    // Summons 33343
    SPELL_RECHARGE_BOOMBOT                      = 62835,    // Summons 33346

    // Cast by 33329 on 33337 (visual?)
    SPELL_ENERGY_ORB                            = 62790,    // Triggers 62826 - needs spellscript for periodic tick to cast one of the random spells above

    SPELL_HEART_HEAL_TO_FULL                    = 17683,
    SPELL_HEART_OVERLOAD                        = 62789,

    SPELL_HEART_LIGHTNING_TETHER                = 64799,    // Cast on self?
    SPELL_ENRAGE                                = 26662,
    SPELL_STAND                                 = 37752,
    SPELL_SUBMERGE                              = 37751,

    //------------------VOID ZONE--------------------
    SPELL_VOID_ZONE                             = 64203,
    SPELL_CONSUMPTION                           = 64208,

    // Life Spark
    SPELL_ARCANE_POWER_STATE                    = 49411,
    SPELL_STATIC_CHARGED                        = 64227,
    SPELL_SHOCK                                 = 64230,

    //----------------XT-002 HEART-------------------
    SPELL_EXPOSED_HEART                         = 63849,
    SPELL_HEART_RIDE_VEHICLE                    = 63852,
    SPELL_RIDE_VEHICLE_EXPOSED                  = 63313, //Heart Exposed

    //---------------XM-024 PUMMELLER----------------
    SPELL_ARCING_SMASH                          = 8374,
    SPELL_TRAMPLE                               = 5568,
    SPELL_UPPERCUT                              = 10966,

    // Scrabot:
    SPELL_SCRAPBOT_RIDE_VEHICLE                 = 47020,
    SPELL_SCRAP_REPAIR                          = 62832,
    SPELL_SUICIDE                               = 7,

    //------------------BOOMBOT-----------------------
    SPELL_AURA_BOOMBOT                          = 65032,
    SPELL_BOOM                                  = 62834,

    // Achievement-related spells
    SPELL_ACHIEVEMENT_CREDIT_NERF_SCRAPBOTS     = 65037
};

enum Events
{
    EVENT_TYMPANIC_TANTRUM = 1,
    EVENT_SEARING_LIGHT,
    EVENT_GRAVITY_BOMB,
    EVENT_HEART_PHASE,
    EVENT_ENERGY_ORB,
    EVENT_DISPOSE_HEART,
    EVENT_ENRAGE,
    EVENT_ENTER_HARD_MODE,
};

enum Timers
{
    TIMER_TYMPANIC_TANTRUM_MIN                  = 32000,
    TIMER_TYMPANIC_TANTRUM_MAX                  = 36000,
    TIMER_SEARING_LIGHT                         = 20000,
    TIMER_GRAVITY_BOMB                          = 20000,
    TIMER_HEART_PHASE                           = 30000,
    TIMER_ENERGY_ORB_MIN                        = 9000,
    TIMER_ENERGY_ORB_MAX                        = 10000,
    TIMER_ENRAGE                                = 600000,

    // Pummeller
    // Timers may be off
    TIMER_ARCING_SMASH                          = 27000,
    TIMER_TRAMPLE                               = 22000,
    TIMER_UPPERCUT                              = 17000,

    TIMER_SPAWN_ADD                             = 12000,
};

enum Actions
{
    ACTION_ENTER_HARD_MODE,
};

enum XT002Data
{
    DATA_TRANSFERED_HEALTH,
    DATA_HARD_MODE,
    DATA_HEALTH_RECOVERED,
    DATA_GRAVITY_BOMB_CASUALTY,
};

enum Yells
{
    SAY_AGGRO                                   = 0,
    SAY_HEART_OPENED                            = 1,
    SAY_HEART_CLOSED                            = 2,
    SAY_TYMPANIC_TANTRUM                        = 3,
    SAY_SLAY                                    = 4,
    SAY_BERSERK                                 = 5,
    SAY_DEATH                                   = 6,
    SAY_SUMMON                                  = 7,
    EMOTE_HEART_OPENED                          = 8,
    EMOTE_HEART_CLOSED                          = 9,
    EMOTE_TYMPANIC_TANTRUM                      = 10,
    EMOTE_SCRAPBOT                              = 11
};

enum AchievementCredits
{
    ACHIEV_MUST_DECONSTRUCT_FASTER              = 21027,
};

enum VehicleSeats
{
    HEART_VEHICLE_SEAT_NORMAL   = 0,
    HEART_VEHICLE_SEAT_EXPOSED  = 1,
};

/*-------------------------------------------------------
 *
 *        XT-002 DECONSTRUCTOR
 *
 *///----------------------------------------------------
class boss_xt002 : public CreatureScript
{
    public:
        boss_xt002() : CreatureScript("boss_xt002") { }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<boss_xt002_AI>(creature);
        }

        struct boss_xt002_AI : public BossAI
        {
            boss_xt002_AI(Creature* creature) : BossAI(creature, BOSS_XT002)
            {
                Initialize();
                _transferHealth = 0;
            }

            void Initialize()
            {
                _healthRecovered = false;
                _gravityBombCasualty = false;
                _hardMode = false;

                _phase = 1;
                _heartExposed = 0;
            }

            void Reset() override
            {
                _Reset();

                me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_AGGRESSIVE);
                DoCastSelf(SPELL_STAND);

                Initialize();

                instance->DoStopCriteriaTimer(CRITERIA_TIMED_TYPE_EVENT, ACHIEV_MUST_DECONSTRUCT_FASTER);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                summons.DespawnAll();
                _DespawnAtEvade();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                Talk(SAY_AGGRO);
                _EnterCombat();

                events.ScheduleEvent(EVENT_ENRAGE, TIMER_ENRAGE);
                events.ScheduleEvent(EVENT_GRAVITY_BOMB, TIMER_GRAVITY_BOMB);
                events.ScheduleEvent(EVENT_SEARING_LIGHT, TIMER_SEARING_LIGHT);
                //Tantrum is cast a bit slower the first time.
                events.ScheduleEvent(EVENT_TYMPANIC_TANTRUM, urand(TIMER_TYMPANIC_TANTRUM_MIN, TIMER_TYMPANIC_TANTRUM_MAX) * 2);

                instance->DoStartCriteriaTimer(CRITERIA_TIMED_TYPE_EVENT, ACHIEV_MUST_DECONSTRUCT_FASTER);
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_ENTER_HARD_MODE:
                        events.ScheduleEvent(EVENT_ENTER_HARD_MODE, 1);
                        break;
                }
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void JustDied(Unit* /*killer*/) override
            {
                Talk(SAY_DEATH);
                _JustDied();
                me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
            }

            void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
            {
                if (!_hardMode && _phase == 1 && !HealthAbovePct(100 - 25 * (_heartExposed+1)))
                    ExposeHeart();
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
                        case EVENT_SEARING_LIGHT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_SEARING_LIGHT);

                            events.ScheduleEvent(EVENT_SEARING_LIGHT, TIMER_SEARING_LIGHT);
                            break;
                        case EVENT_GRAVITY_BOMB:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_GRAVITY_BOMB);

                            events.ScheduleEvent(EVENT_GRAVITY_BOMB, TIMER_GRAVITY_BOMB);
                            break;
                        case EVENT_TYMPANIC_TANTRUM:
                            Talk(SAY_TYMPANIC_TANTRUM);
                            Talk(EMOTE_TYMPANIC_TANTRUM);
                            DoCast(SPELL_TYMPANIC_TANTRUM);
                            events.ScheduleEvent(EVENT_TYMPANIC_TANTRUM, urand(TIMER_TYMPANIC_TANTRUM_MIN, TIMER_TYMPANIC_TANTRUM_MAX));
                            break;
                        case EVENT_DISPOSE_HEART:
                            SetPhaseOne();
                            break;
                        case EVENT_ENRAGE:
                            Talk(SAY_BERSERK);
                            DoCastSelf(SPELL_ENRAGE);
                            break;
                        case EVENT_ENTER_HARD_MODE:
                            me->SetFullHealth();
                            DoCastSelf(SPELL_HEARTBREAK, true);
                            me->AddLootMode(LOOT_MODE_HARD_MODE_1);
                            _hardMode = true;
                            SetPhaseOne();
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                if (_phase == 1)
                    DoMeleeAttackIfReady();
            }

            void PassengerBoarded(Unit* who, int8 seatId, bool apply) override
            {
                if (apply && who->GetEntry() == NPC_XS013_SCRAPBOT)
                {
                    // Need this so we can properly determine when to expose heart again in damagetaken hook
                    if (me->GetHealthPct() > (25 * (4 - _heartExposed)))
                        ++_heartExposed;

                    Talk(EMOTE_SCRAPBOT);
                    DoCast(who, SPELL_SCRAP_REPAIR, true);
                    _healthRecovered = true;
                }

                if (apply && seatId == HEART_VEHICLE_SEAT_EXPOSED)
                    who->CastSpell(who, SPELL_EXPOSED_HEART);   // Channeled
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_HARD_MODE:
                        return _hardMode ? 1 : 0;
                    case DATA_HEALTH_RECOVERED:
                        return _healthRecovered ? 1 : 0;
                    case DATA_GRAVITY_BOMB_CASUALTY:
                        return _gravityBombCasualty ? 1 : 0;
                }

                return 0;
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_TRANSFERED_HEALTH:
                        _transferHealth = data;
                        break;
                    case DATA_GRAVITY_BOMB_CASUALTY:
                        _gravityBombCasualty = (data > 0) ? true : false;
                        break;
                }
            }

            void ExposeHeart()
            {
                Talk(SAY_HEART_OPENED);
                Talk(EMOTE_HEART_OPENED);

                DoCastSelf(SPELL_SUBMERGE);  // Will make creature untargetable
                me->AttackStop();
                me->SetReactState(REACT_PASSIVE);

                Unit* heart = me->GetVehicleKit() ? me->GetVehicleKit()->GetPassenger(HEART_VEHICLE_SEAT_NORMAL) : nullptr;
                if (heart)
                {
                    heart->CastSpell(heart, SPELL_HEART_OVERLOAD);
                    heart->CastSpell(me, SPELL_HEART_LIGHTNING_TETHER);
                    heart->CastSpell(heart, SPELL_HEART_HEAL_TO_FULL, true);
                    heart->CastSpell(me, SPELL_RIDE_VEHICLE_EXPOSED, true);
                    heart->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                    heart->AddUnitFlag(UNIT_FLAG_UNK_29);
               }

                events.CancelEvent(EVENT_SEARING_LIGHT);
                events.CancelEvent(EVENT_GRAVITY_BOMB);
                events.CancelEvent(EVENT_TYMPANIC_TANTRUM);

                // Start "end of phase 2 timer"
                events.ScheduleEvent(EVENT_DISPOSE_HEART, TIMER_HEART_PHASE);

                // Phase 2 has officially started
                _phase = 2;
                _heartExposed++;
            }

            void SetPhaseOne()
            {
                Talk(SAY_HEART_CLOSED);
                Talk(EMOTE_HEART_CLOSED);

                me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_AGGRESSIVE);
                DoCastSelf(SPELL_STAND);

                _phase = 1;

                events.RescheduleEvent(EVENT_SEARING_LIGHT, TIMER_SEARING_LIGHT / 2);
                events.RescheduleEvent(EVENT_GRAVITY_BOMB, TIMER_GRAVITY_BOMB);
                events.RescheduleEvent(EVENT_TYMPANIC_TANTRUM, urand(TIMER_TYMPANIC_TANTRUM_MIN, TIMER_TYMPANIC_TANTRUM_MAX));

                Unit* heart = me->GetVehicleKit() ? me->GetVehicleKit()->GetPassenger(HEART_VEHICLE_SEAT_EXPOSED) : nullptr;
                if (!heart)
                    return;

                heart->CastSpell(me, SPELL_HEART_RIDE_VEHICLE, true);
                heart->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                heart->RemoveUnitFlag(UNIT_FLAG_UNK_29);
                heart->RemoveAurasDueToSpell(SPELL_EXPOSED_HEART);

                if (!_hardMode)
                {
                    if (!_transferHealth)
                        _transferHealth = (heart->GetMaxHealth() - heart->GetHealth());

                    if (_transferHealth >= me->GetHealth())
                        _transferHealth = me->GetHealth() - 1;

                    me->ModifyHealth(-((int32)_transferHealth));
                    me->LowerPlayerDamageReq(_transferHealth);
                }
            }

            private:
                // Achievement related
                bool _healthRecovered;       // Did a scrapbot recover XT-002's health during the encounter?
                bool _hardMode;              // Are we in hard mode? Or: was the heart killed during phase 2?
                bool _gravityBombCasualty;   // Did someone die because of Gravity Bomb damage?

                uint8 _phase;
                uint8 _heartExposed;
                uint32 _transferHealth;
        };
};

/*-------------------------------------------------------
 *
 *        XT-002 HEART
 *
 *///----------------------------------------------------

class npc_xt002_heart : public CreatureScript
{
    public:
        npc_xt002_heart() : CreatureScript("npc_xt002_heart") { }

        struct npc_xt002_heartAI : public NullCreatureAI
        {
            npc_xt002_heartAI(Creature* creature) : NullCreatureAI(creature), _instance(creature->GetInstanceScript()) { }

            void JustDied(Unit* /*killer*/) override
            {
                if (Creature* xt002 = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(BOSS_XT002)))
                {
                    xt002->AI()->SetData(DATA_TRANSFERED_HEALTH, me->GetHealth());
                    xt002->AI()->DoAction(ACTION_ENTER_HARD_MODE);
                }
            }

        private:
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<npc_xt002_heartAI>(creature);
        }
};

/*-------------------------------------------------------
 *
 *        XS-013 SCRAPBOT
 *
 *///----------------------------------------------------
class npc_scrapbot : public CreatureScript
{
    public:
        npc_scrapbot() : CreatureScript("npc_scrapbot") { }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<npc_scrapbotAI>(creature);
        }

        struct npc_scrapbotAI : public ScriptedAI
        {
            npc_scrapbotAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
                _instance = me->GetInstanceScript();
            }

            void Initialize()
            {
                _rangeCheckTimer = 500;
            }

            void Reset() override
            {
                me->SetReactState(REACT_PASSIVE);

                Initialize();

                if (Creature* pXT002 = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(BOSS_XT002)))
                    me->GetMotionMaster()->MoveFollow(pXT002, 0.0f, 0.0f);
            }

            void UpdateAI(uint32 diff) override
            {
                if (_rangeCheckTimer <= diff)
                {
                    if (Creature* xt002 = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(BOSS_XT002)))
                    {
                        if (me->IsWithinMeleeRange(xt002))
                        {
                            DoCast(xt002, SPELL_SCRAPBOT_RIDE_VEHICLE);
                            // Unapply vehicle aura again
                            xt002->RemoveAurasDueToSpell(SPELL_SCRAPBOT_RIDE_VEHICLE);
                            me->DespawnOrUnsummon();
                        }
                    }
                }
                else
                    _rangeCheckTimer -= diff;
            }

            private:
                InstanceScript* _instance;
                uint32 _rangeCheckTimer;
        };
};

/*-------------------------------------------------------
 *
 *        XM-024 PUMMELLER
 *
 *///----------------------------------------------------
class npc_pummeller : public CreatureScript
{
    public:
        npc_pummeller() : CreatureScript("npc_pummeller") { }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<npc_pummellerAI>(creature);
        }

        struct npc_pummellerAI : public ScriptedAI
        {
            npc_pummellerAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
                _instance = creature->GetInstanceScript();
            }

            void Initialize()
            {
                _arcingSmashTimer = TIMER_ARCING_SMASH;
                _trampleTimer = TIMER_TRAMPLE;
                _uppercutTimer = TIMER_UPPERCUT;
            }

            void Reset() override
            {
                Initialize();

                if (Creature* xt002 = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(BOSS_XT002)))
                {
                    Position pos = xt002->GetPosition();
                    me->GetMotionMaster()->MovePoint(0, pos);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->IsWithinMeleeRange(me->GetVictim()))
                {
                    if (_arcingSmashTimer <= diff)
                    {
                        DoCastVictim(SPELL_ARCING_SMASH);
                        _arcingSmashTimer = TIMER_ARCING_SMASH;
                    }
                    else
                        _arcingSmashTimer -= diff;

                    if (_trampleTimer <= diff)
                    {
                        DoCastVictim(SPELL_TRAMPLE);
                        _trampleTimer = TIMER_TRAMPLE;
                    }
                    else
                        _trampleTimer -= diff;

                    if (_uppercutTimer <= diff)
                    {
                        DoCastVictim(SPELL_UPPERCUT);
                        _uppercutTimer = TIMER_UPPERCUT;
                    }
                    else
                        _uppercutTimer -= diff;
                }

                DoMeleeAttackIfReady();
            }

            private:
                InstanceScript* _instance;
                uint32 _arcingSmashTimer;
                uint32 _trampleTimer;
                uint32 _uppercutTimer;
        };
};

/*-------------------------------------------------------
 *
 *        XE-321 BOOMBOT
 *
 *///----------------------------------------------------
class BoomEvent : public BasicEvent
{
    public:
        BoomEvent(Creature* me) : _me(me)
        {
        }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            // This hack is here because we suspect our implementation of spell effect execution on targets
            // is done in the wrong order. We suspect that EFFECT_0 needs to be applied on all targets,
            // then EFFECT_1, etc - instead of applying each effect on target1, then target2, etc.
            // The above situation causes the visual for this spell to be bugged, so we remove the instakill
            // effect and implement a script hack for that.

            _me->CastSpell(_me, SPELL_BOOM, false);
            return true;
        }

    private:
        Creature* _me;
};

class npc_boombot : public CreatureScript
{
    public:
        npc_boombot() : CreatureScript("npc_boombot") { }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<npc_boombotAI>(creature);
        }

        struct npc_boombotAI : public ScriptedAI
        {
            npc_boombotAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
                _instance = creature->GetInstanceScript();
            }

            void Initialize()
            {
                _boomed = false;
            }

            void Reset() override
            {
                Initialize();

                DoCast(SPELL_AURA_BOOMBOT); // For achievement

                /// @todo proper waypoints?
                if (Creature* pXT002 = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(BOSS_XT002)))
                    me->GetMotionMaster()->MoveFollow(pXT002, 0.0f, 0.0f);
            }

            void DamageTaken(Unit* /*who*/, uint32& damage) override
            {
                if (damage >= (me->GetHealth() - me->GetMaxHealth() * 0.5f) && !_boomed)
                {
                    _boomed = true; // Prevent recursive calls

                    WorldPackets::CombatLog::SpellInstakillLog instakill;
                    instakill.Caster = me->GetGUID();
                    instakill.Target = me->GetGUID();
                    instakill.SpellID = SPELL_BOOM;
                    me->SendMessageToSet(instakill.Write(), false);

                    me->DealDamage(me, me->GetHealth(), nullptr, NODAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false);

                    damage = 0;

                    // Visual only seems to work if the instant kill event is delayed or the spell itself is delayed
                    // Casting done from player and caster source has the same targetinfo flags,
                    // so that can't be the issue
                    // See BoomEvent class
                    // Schedule 1s delayed
                    me->m_Events.AddEvent(new BoomEvent(me), me->m_Events.CalculateTime(1*IN_MILLISECONDS));
                }
            }

            void UpdateAI(uint32 /*diff*/) override
            {
                if (!UpdateVictim())
                    return;

                // No melee attack
            }

           private:
                InstanceScript* _instance;
                bool _boomed;
        };
};


class npc_life_spark : public CreatureScript
{
    public:
        npc_life_spark() : CreatureScript("npc_life_spark") { }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<npc_life_sparkAI>(creature);
        }

        struct npc_life_sparkAI : public ScriptedAI
        {
            npc_life_sparkAI(Creature* creature) : ScriptedAI(creature){ }

            void Reset() override
            {
                DoCastSelf(SPELL_ARCANE_POWER_STATE);
                _scheduler.CancelAll();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                DoCastSelf(SPELL_STATIC_CHARGED);
                _scheduler.Schedule(Seconds(12), [this](TaskContext spellShock)
                {
                    DoCastVictim(SPELL_SHOCK);
                    spellShock.Repeat();
                });
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                _scheduler.Update(diff, [this]
                {
                    DoMeleeAttackIfReady();
                });
            }

            private:
                TaskScheduler _scheduler;
        };
};

class npc_xt_void_zone : public CreatureScript
{
public:
    npc_xt_void_zone() : CreatureScript("npc_xt_void_zone") { }

    struct npc_xt_void_zoneAI : public PassiveAI
    {
        npc_xt_void_zoneAI(Creature* creature) : PassiveAI(creature) { }

        void Reset() override
        {
            _scheduler.Schedule(Seconds(1), [this](TaskContext consumption)
            {
                DoCastSelf(SPELL_CONSUMPTION);
                consumption.Repeat();
            });
        }

        void UpdateAI(uint32 diff) override
        {
            _scheduler.Update(diff);
        }

    private:
        TaskScheduler _scheduler;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetUlduarAI<npc_xt_void_zoneAI>(creature);
    }

};

class spell_xt002_searing_light_spawn_life_spark : public SpellScriptLoader
{
    public:
        spell_xt002_searing_light_spawn_life_spark() : SpellScriptLoader("spell_xt002_searing_light_spawn_life_spark") { }

        class spell_xt002_searing_light_spawn_life_spark_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_xt002_searing_light_spawn_life_spark_AuraScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_SUMMON_LIFE_SPARK });
            }

            void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (GetOwner()->GetTypeId() == TYPEID_PLAYER)
                    if (Unit* xt002 = GetCaster())
                        if (xt002->HasAura(aurEff->GetAmount()))   // Heartbreak aura indicating hard mode
                            xt002->CastSpell(GetUnitOwner(), SPELL_SUMMON_LIFE_SPARK, true);
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_xt002_searing_light_spawn_life_spark_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_xt002_searing_light_spawn_life_spark_AuraScript();
        }
};

class spell_xt002_gravity_bomb_aura : public SpellScriptLoader
{
    public:
        spell_xt002_gravity_bomb_aura() : SpellScriptLoader("spell_xt002_gravity_bomb_aura") { }

        class spell_xt002_gravity_bomb_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_xt002_gravity_bomb_aura_AuraScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_SUMMON_VOID_ZONE });
            }

            void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (GetOwner()->GetTypeId() == TYPEID_PLAYER)
                    if (Unit* xt002 = GetCaster())
                        if (xt002->HasAura(aurEff->GetAmount()))   // Heartbreak aura indicating hard mode
                            xt002->CastSpell(GetUnitOwner(), SPELL_SUMMON_VOID_ZONE, true);
            }

            void OnPeriodic(AuraEffect const* aurEff)
            {
                Unit* xt002 = GetCaster();
                if (!xt002)
                    return;

                Unit* owner = GetOwner()->ToUnit();
                if (!owner)
                    return;

                if (aurEff->GetAmount() >= int32(owner->GetHealth()))
                    if (xt002->GetAI())
                        xt002->GetAI()->SetData(DATA_GRAVITY_BOMB_CASUALTY, 1);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_xt002_gravity_bomb_aura_AuraScript::OnPeriodic, EFFECT_2, SPELL_AURA_PERIODIC_DAMAGE);
                AfterEffectRemove += AuraEffectRemoveFn(spell_xt002_gravity_bomb_aura_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_xt002_gravity_bomb_aura_AuraScript();
        }
};

class spell_xt002_gravity_bomb_damage : public SpellScriptLoader
{
    public:
        spell_xt002_gravity_bomb_damage() : SpellScriptLoader("spell_xt002_gravity_bomb_damage") { }

        class spell_xt002_gravity_bomb_damage_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_xt002_gravity_bomb_damage_SpellScript);

            void HandleScript(SpellEffIndex /*eff*/)
            {
                Unit* caster = GetCaster();
                if (!caster)
                    return;

                if (GetHitDamage() >= int32(GetHitUnit()->GetHealth()))
                    if (caster->GetAI())
                        caster->GetAI()->SetData(DATA_GRAVITY_BOMB_CASUALTY, 1);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_xt002_gravity_bomb_damage_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_xt002_gravity_bomb_damage_SpellScript();
        }
};

class spell_xt002_heart_overload_periodic : public SpellScriptLoader
{
    public:
        spell_xt002_heart_overload_periodic() : SpellScriptLoader("spell_xt002_heart_overload_periodic") { }

        class spell_xt002_heart_overload_periodic_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_xt002_heart_overload_periodic_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_ENERGY_ORB,
                    SPELL_RECHARGE_BOOMBOT,
                    SPELL_RECHARGE_PUMMELER,
                    SPELL_RECHARGE_SCRAPBOT
                });
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (Unit* caster = GetCaster())
                {
                    if (InstanceScript* instance = caster->GetInstanceScript())
                    {
                        if (Unit* toyPile = ObjectAccessor::GetUnit(*caster, instance->GetGuidData(DATA_TOY_PILE_0 + urand(0, 3))))
                        {
                            caster->CastSpell(toyPile, SPELL_ENERGY_ORB, true);

                            // This should probably be incorporated in a dummy effect handler, but I've had trouble getting the correct target
                            // Weighed randomization (approximation)
                            uint32 const spells[] = { SPELL_RECHARGE_SCRAPBOT, SPELL_RECHARGE_SCRAPBOT, SPELL_RECHARGE_SCRAPBOT,
                                SPELL_RECHARGE_PUMMELER, SPELL_RECHARGE_BOOMBOT };

                            for (uint8 i = 0; i < 5; ++i)
                            {
                                uint8 a = urand(0, 4);
                                uint32 spellId = spells[a];
                                toyPile->CastSpell(toyPile, spellId, true, nullptr, nullptr, instance->GetGuidData(BOSS_XT002));
                            }
                        }
                    }

                    if (Creature* base = caster->GetVehicleCreatureBase())
                        base->AI()->Talk(SAY_SUMMON);
                }
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_xt002_heart_overload_periodic_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_xt002_heart_overload_periodic_SpellScript();
        }
};

class spell_xt002_tympanic_tantrum : public SpellScriptLoader
{
    public:
        spell_xt002_tympanic_tantrum() : SpellScriptLoader("spell_xt002_tympanic_tantrum") { }

        class spell_xt002_tympanic_tantrum_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_xt002_tympanic_tantrum_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if([](WorldObject* target)
                {
                    return target->GetTypeId() != TYPEID_PLAYER && (target->GetTypeId() != TYPEID_UNIT || !target->ToUnit()->IsPet());
                });
            }

            void RecalculateDamage()
            {
                SetHitDamage(GetHitUnit()->CountPctFromMaxHealth(GetHitDamage()));
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_xt002_tympanic_tantrum_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_xt002_tympanic_tantrum_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
                OnHit += SpellHitFn(spell_xt002_tympanic_tantrum_SpellScript::RecalculateDamage);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_xt002_tympanic_tantrum_SpellScript();
        }
};

class spell_xt002_submerged : public SpellScriptLoader
{
    public:
        spell_xt002_submerged() : SpellScriptLoader("spell_xt002_submerged") { }

        class spell_xt002_submerged_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_xt002_submerged_SpellScript);

            void HandleScript(SpellEffIndex /*eff*/)
            {
                Creature* target = GetHitCreature();
                if (!target)
                    return;

                target->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                target->SetStandState(UNIT_STAND_STATE_SUBMERGED);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_xt002_submerged_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_xt002_submerged_SpellScript();
        }
};

class spell_xt002_321_boombot_aura : public SpellScriptLoader
{
    public:
        spell_xt002_321_boombot_aura() : SpellScriptLoader("spell_xt002_321_boombot_aura") { }

        class spell_xt002_321_boombot_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_xt002_321_boombot_aura_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_ACHIEVEMENT_CREDIT_NERF_SCRAPBOTS });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                if (eventInfo.GetActionTarget()->GetEntry() != NPC_XS013_SCRAPBOT)
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                InstanceScript* instance = eventInfo.GetActor()->GetInstanceScript();
                if (!instance)
                    return;

                instance->DoCastSpellOnPlayers(SPELL_ACHIEVEMENT_CREDIT_NERF_SCRAPBOTS);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_xt002_321_boombot_aura_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_xt002_321_boombot_aura_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_xt002_321_boombot_aura_AuraScript();
        }
};

class achievement_nerf_engineering : public AchievementCriteriaScript
{
    public:
        achievement_nerf_engineering() : AchievementCriteriaScript("achievement_nerf_engineering") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (!target || !target->GetAI())
                return false;

            return !(target->GetAI()->GetData(DATA_HEALTH_RECOVERED));
        }
};

class achievement_heartbreaker : public AchievementCriteriaScript
{
    public:
        achievement_heartbreaker() : AchievementCriteriaScript("achievement_heartbreaker") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (!target || !target->GetAI())
                return false;

            return target->GetAI()->GetData(DATA_HARD_MODE) != 0;
        }
};

class achievement_nerf_gravity_bombs : public AchievementCriteriaScript
{
    public:
        achievement_nerf_gravity_bombs() : AchievementCriteriaScript("achievement_nerf_gravity_bombs") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (!target || !target->GetAI())
                return false;

            return !(target->GetAI()->GetData(DATA_GRAVITY_BOMB_CASUALTY));
        }
};

void AddSC_boss_xt002()
{
    new npc_xt002_heart();
    new npc_scrapbot();
    new npc_pummeller();
    new npc_boombot();

    new npc_life_spark();
    new npc_xt_void_zone();
    new boss_xt002();

    new spell_xt002_searing_light_spawn_life_spark();
    new spell_xt002_gravity_bomb_aura();
    new spell_xt002_gravity_bomb_damage();
    new spell_xt002_heart_overload_periodic();
    new spell_xt002_tympanic_tantrum();
    new spell_xt002_submerged();
    new spell_xt002_321_boombot_aura();

    new achievement_nerf_engineering();
    new achievement_heartbreaker();
    new achievement_nerf_gravity_bombs();
}
