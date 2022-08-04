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

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Opcodes.h"
#include "PassiveAI.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "ulduar.h"
#include "Vehicle.h"
#include "WorldPacket.h"

enum Spells
{
    SPELL_TYMPANIC_TANTRUM                  = 62776,
    SPELL_SEARING_LIGHT                     = 63018,
    SPELL_SUMMON_LIFE_SPARK                 = 64210,
    SPELL_SUMMON_VOID_ZONE                  = 64203,
    SPELL_GRAVITY_BOMB                      = 63024,
    SPELL_HEARTBREAK                        = 65737,
    SPELL_STAND                             = 37752,
    SPELL_SUBMERGE                          = 37751,
    SPELL_ENRAGE                            = 26662,
    SPELL_COOLDOWN_CREATURE_SPECIAL_2       = 64404,
    SPELL_SCRAP_REPAIR                      = 62832,

    // XT-Toy Pile
    SPELL_RECHARGE_PUMMELER                 = 62831,
    SPELL_RECHARGE_SCRAPBOT                 = 62828,
    SPELL_RECHARGE_BOOMBOT                  = 62835,

    // Heart of the Deconstructor
    SPELL_ENERGY_ORB                        = 62790,
    SPELL_RIDE_VEHICLE_EXPOSED              = 63313,
    SPELL_EXPOSED_HEART                     = 63849,
    SPELL_HEART_RIDE_VEHICLE                = 63852,
    SPELL_SCRAPBOT_RIDE_VEHICLE             = 47020,
    SPELL_FULL_HEAL                         = 17683,
    SPELL_HEART_OVERLOAD                    = 62789,
    SPELL_HEART_LIGHTNING_TETHER            = 64799,

    // Void Zone
    SPELL_CONSUMPTION                       = 64209,

    // Life Spark
    SPELL_ARCANE_POWER_STATE                = 49411,
    SPELL_STATIC_CHARGED                    = 64227,
    SPELL_SHOCK                             = 64230,

    // XM-024 Pummeller
    SPELL_ARCING_SMASH                      = 8374,
    SPELL_TRAMPLE                           = 5568,
    SPELL_UPPERCUT                          = 10966,

    //Boombot
    SPELL_321_BOOMBOT_AURA                  = 65032,
    SPELL_BOOM                              = 62834,

    // Achievement-related spells
    SPELL_ACHIEVEMENT_CREDIT_NERF_SCRAPBOTS = 65037
};

enum Events
{
    EVENT_TYMPANIC_TANTRUM = 1,
    EVENT_PHASE_CHECK,
    EVENT_SEARING_LIGHT,
    EVENT_GRAVITY_BOMB,
    EVENT_SUBMERGE,
    EVENT_DISPOSE_HEART,
    EVENT_ENRAGE,
    EVENT_ENTER_HARD_MODE,
    EVENT_RESUME_ATTACK
};

enum XT002Phases
{
    PHASE_1 = 1,
    PHASE_HEART
};

enum Actions
{
    ACTION_ENTER_HARD_MODE,
    ACTION_START_PHASE_HEART,
    ACTION_DISPOSE_HEART
};

enum XT002Data
{
    DATA_TRANSFERED_HEALTH,
    DATA_HARD_MODE,
    DATA_HEALTH_RECOVERED,
    DATA_GRAVITY_BOMB_CASUALTY
};

enum Yells
{
    SAY_AGGRO              = 0,
    SAY_HEART_OPENED       = 1,
    SAY_HEART_CLOSED       = 2,
    SAY_TYMPANIC_TANTRUM   = 3,
    SAY_SLAY               = 4,
    SAY_BERSERK            = 5,
    SAY_DEATH              = 6,
    SAY_SUMMON             = 7,
    EMOTE_HEART_OPENED     = 8,
    EMOTE_HEART_CLOSED     = 9,
    EMOTE_TYMPANIC_TANTRUM = 10,
    EMOTE_SCRAPBOT         = 11
};

enum Misc
{
    ACHIEV_MUST_DECONSTRUCT_FASTER = 21027,
    HEART_VEHICLE_SEAT_EXPOSED     = 1,
    GROUP_SEARING_GRAVITY          = 1
};

struct boss_xt002 : public BossAI
{
    boss_xt002(Creature* creature) : BossAI(creature, DATA_XT002)
    {
        Initialize();
    }

    void Initialize()
    {
        _healthRecovered = false;
        _gravityBombCasualty = false;
        _hardMode = false;
        _exposeHeartPercent = 75;
    }

    void ChangeNextExpose()
    {
        switch (_exposeHeartPercent)
        {
            case 75:
                _exposeHeartPercent = 50;
                break;
            case 50:
                _exposeHeartPercent = 25;
                break;
            default:
                _exposeHeartPercent = 0;
                break;
        }
    }

    void Reset() override
    {
        _Reset();
        events.SetPhase(PHASE_1);
        me->SetReactState(REACT_DEFENSIVE);
        Initialize();
        instance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_MUST_DECONSTRUCT_FASTER);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        summons.DespawnAll();
        _DespawnAtEvade();
    }

    void JustEngagedWith(Unit* who) override
    {
        Talk(SAY_AGGRO);
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_SEARING_LIGHT, Is25ManRaid() ? 9s : 11s, GROUP_SEARING_GRAVITY, PHASE_1);
        events.ScheduleEvent(EVENT_GRAVITY_BOMB, Is25ManRaid() ? 18s : 21s, GROUP_SEARING_GRAVITY, PHASE_1);
        events.ScheduleEvent(EVENT_ENRAGE, 10min);
        events.ScheduleEvent(EVENT_TYMPANIC_TANTRUM, 60s, 0, PHASE_1);
        events.ScheduleEvent(EVENT_PHASE_CHECK, 1s, 0, PHASE_1);
        instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_MUST_DECONSTRUCT_FASTER);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_ENTER_HARD_MODE)
            events.ScheduleEvent(EVENT_ENTER_HARD_MODE, 1ms);
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
        me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
    }

    void ExposeHeart()
    {
        events.SetPhase(PHASE_HEART);
        me->SetReactState(REACT_PASSIVE);
        me->AttackStop();
        Talk(SAY_HEART_OPENED);
        events.CancelEvent(EVENT_TYMPANIC_TANTRUM);
        events.ScheduleEvent(EVENT_SUBMERGE, 6s, 0, PHASE_HEART);
        ChangeNextExpose();
    }

    void DisposeHeart(bool isHardMode = false)
    {
        Talk(SAY_HEART_CLOSED);

        if (isHardMode)
        {
            me->SetReactState(REACT_AGGRESSIVE);
            RescheduleEvents();
        }
        else
        {
            Talk(EMOTE_HEART_CLOSED);
            events.ScheduleEvent(EVENT_RESUME_ATTACK, 1s, 0, PHASE_HEART);
        }

        DoCastSelf(SPELL_STAND);
        DoCastSelf(SPELL_COOLDOWN_CREATURE_SPECIAL_2);
        me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
        if (Creature* heart = instance->GetCreature(DATA_XT002_HEART))
        {
            if (heart->IsAlive())
                heart->AI()->DoAction(ACTION_DISPOSE_HEART);
            else
                heart->DespawnOrUnsummon();
        }

    }

    void RescheduleEvents()
    {
        events.SetPhase(PHASE_1);
        events.ScheduleEvent(EVENT_SEARING_LIGHT, 25s, GROUP_SEARING_GRAVITY, PHASE_1);
        events.ScheduleEvent(EVENT_GRAVITY_BOMB, Is25ManRaid() ? 33s : 15s, GROUP_SEARING_GRAVITY, PHASE_1);
        events.ScheduleEvent(EVENT_TYMPANIC_TANTRUM, 25s, 0, PHASE_1);
        if (!_hardMode)
            events.ScheduleEvent(EVENT_PHASE_CHECK, 1s, 0, PHASE_1);
    }

    void PassengerBoarded(Unit* who, int8 seatId, bool apply) override
    {
        if (!apply)
            return;

        if (who->GetEntry() == NPC_XS013_SCRAPBOT)
        {
            Talk(EMOTE_SCRAPBOT);
            _healthRecovered = true;
        }
        else if (seatId == HEART_VEHICLE_SEAT_EXPOSED)
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
            default:
                return 0;
        }
    }

    void SetData(uint32 type, uint32 data) override
    {
        switch (type)
        {
            case DATA_TRANSFERED_HEALTH:
                if (!_hardMode)
                {
                    uint32 transferHealth = data;
                    if (transferHealth >= me->GetHealth())
                        transferHealth = me->GetHealth() - 1;

                    me->ModifyHealth(-static_cast<int32>(transferHealth));
                    me->LowerPlayerDamageReq(transferHealth);
                }
                break;
            case DATA_GRAVITY_BOMB_CASUALTY:
                _gravityBombCasualty = (data > 0) ? true : false;
                break;
            default:
                break;
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
                case EVENT_SEARING_LIGHT:
                    DoCastSelf(SPELL_SEARING_LIGHT);
                    events.Repeat(Is25ManRaid() ? 16s : 20s);
                    break;
                case EVENT_GRAVITY_BOMB:
                    DoCastSelf(SPELL_GRAVITY_BOMB);
                    events.Repeat(Is25ManRaid() ? 16s : 20s);
                    break;
                case EVENT_TYMPANIC_TANTRUM:
                    Talk(SAY_TYMPANIC_TANTRUM);
                    Talk(EMOTE_TYMPANIC_TANTRUM);
                    events.DelayEvents(10s, GROUP_SEARING_GRAVITY);
                    DoCastSelf(SPELL_TYMPANIC_TANTRUM);
                    events.Repeat(1min);
                    break;
                case EVENT_PHASE_CHECK:
                    if (me->HealthBelowPct(_exposeHeartPercent))
                        ExposeHeart();
                    events.Repeat(1s);
                    break;
                case EVENT_SUBMERGE:
                    DoCastSelf(SPELL_SUBMERGE);
                    me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    Talk(EMOTE_HEART_OPENED);
                    if (Creature* heart = instance->GetCreature(DATA_XT002_HEART))
                        heart->AI()->DoAction(ACTION_START_PHASE_HEART);
                    events.ScheduleEvent(EVENT_DISPOSE_HEART, 30s, PHASE_HEART);
                    break;
                case EVENT_DISPOSE_HEART:
                    DisposeHeart();
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
                    DisposeHeart(_hardMode);
                    break;
                case EVENT_RESUME_ATTACK:
                    me->SetReactState(REACT_AGGRESSIVE);
                    RescheduleEvents();
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        if (events.IsInPhase(PHASE_1))
            DoMeleeAttackIfReady();
    }

private:
    bool _healthRecovered;       // Did a scrapbot recover XT-002's health during the encounter?
    bool _hardMode;              // Are we in hard mode? Or: was the heart killed during phase 2?
    bool _gravityBombCasualty;   // Did someone die because of Gravity Bomb damage?
    uint8 _exposeHeartPercent;
};

struct npc_xt002_heart : public NullCreatureAI
{
    npc_xt002_heart(Creature* creature) : NullCreatureAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        me->SetRegenerateHealth(false);
    }

    void DoAction(int32 action) override
    {
        Creature* xt002 = _instance->GetCreature(DATA_XT002);
        if (!xt002)
            return;

        if (action == ACTION_START_PHASE_HEART)
        {
            DoCastSelf(SPELL_FULL_HEAL);
            DoCast(xt002, SPELL_RIDE_VEHICLE_EXPOSED, true);
            DoCastSelf(SPELL_HEART_OVERLOAD);
            me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
            me->SetUnitFlag(UNIT_FLAG_PREVENT_EMOTES_FROM_CHAT_TEXT);
        }
        else if (action == ACTION_DISPOSE_HEART)
        {
            DoCast(xt002, SPELL_HEART_RIDE_VEHICLE, true);
            me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
            me->RemoveUnitFlag(UNIT_FLAG_PREVENT_EMOTES_FROM_CHAT_TEXT);
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* xt002 = _instance->GetCreature(DATA_XT002))
            xt002->AI()->DoAction(ACTION_ENTER_HARD_MODE);
    }

private:
    InstanceScript * _instance;
};

struct npc_scrapbot : public ScriptedAI
{
    npc_scrapbot(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        _scheduler.CancelAll();

        if (_instance->GetBossState(DATA_XT002) != IN_PROGRESS)
        {
            me->DespawnOrUnsummon();
            return;
        }

        if (Creature* xt002 = _instance->GetCreature(DATA_XT002))
            xt002->AI()->JustSummoned(me);

        _scheduler.
            Schedule(2s, [this](TaskContext /*StartMove*/)
            {
                if (Creature* xt002 = _instance->GetCreature(DATA_XT002))
                    me->GetMotionMaster()->MoveFollow(xt002, 0.0f, 0.0f);
            })
            .Schedule(1s, [this](TaskContext checkXt002)
            {
                if (Creature* xt002 = _instance->GetCreature(DATA_XT002))
                {
                    if (me->IsWithinMeleeRange(xt002))
                    {
                        DoCast(xt002, SPELL_SCRAPBOT_RIDE_VEHICLE);
                        _scheduler.Schedule(1s, [this](TaskContext /*ScrapRepair*/)
                        {
                            if (Creature* xt002 = _instance->GetCreature(DATA_XT002))
                                xt002->CastSpell(me, SPELL_SCRAP_REPAIR, true);
                            me->DespawnOrUnsummon(1s);
                        });
                    }
                    else
                        checkXt002.Repeat();
                }
                else
                    me->DespawnOrUnsummon();
            });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

struct npc_pummeller : public ScriptedAI
{
    npc_pummeller(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        _scheduler.CancelAll();

        if (_instance->GetBossState(DATA_XT002) != IN_PROGRESS)
        {
            me->DespawnOrUnsummon();
            return;
        }

        if (Creature* xt002 = _instance->GetCreature(DATA_XT002))
            xt002->AI()->JustSummoned(me);

        _scheduler.
            Schedule(1s, [this](TaskContext /*StartMove*/)
            {
                me->SetReactState(REACT_AGGRESSIVE);
                DoZoneInCombat();
            })
            .Schedule(17s, [this](TaskContext trample)
            {
                DoCastSelf(SPELL_TRAMPLE);
                trample.Repeat(11s);
            })
            .Schedule(19s, [this](TaskContext arcingSmash)
            {
                DoCastSelf(SPELL_ARCING_SMASH);
                arcingSmash.Repeat(8s);
            })
            .Schedule(19s, [this](TaskContext upperCut)
            {
                DoCastVictim(SPELL_UPPERCUT);
                upperCut.Repeat(14s);
            });

    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff, [this]
        {
            DoMeleeAttackIfReady();
        });
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

struct npc_boombot : public ScriptedAI
{
    npc_boombot(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()), _boomed(false) { }

    void Reset() override
    {
        DoCastSelf(SPELL_321_BOOMBOT_AURA);
        me->SetReactState(REACT_PASSIVE);
        _scheduler.CancelAll();

        if (_instance->GetBossState(DATA_XT002) != IN_PROGRESS)
        {
            me->DespawnOrUnsummon();
            return;
        }

        // HACK/workaround:
        // these values aren't confirmed - lack of data - and the values in DB are incorrect
        // these values are needed for correct damage of Boom spell
        me->SetFloatValue(UNIT_FIELD_MINDAMAGE, 15000.0f);
        me->SetFloatValue(UNIT_FIELD_MAXDAMAGE, 18000.0f);

        if (Creature* xt002 = _instance->GetCreature(DATA_XT002))
            xt002->AI()->JustSummoned(me);

        _scheduler.
            Schedule(4s, [this](TaskContext /*StartMove*/)
            {
                if (Creature* xt002 = _instance->GetCreature(DATA_XT002))
                    me->GetMotionMaster()->MoveFollow(xt002, 0.0f, 0.0f);

            })
            .Schedule(1s, [this](TaskContext checkXt002)
            {
                if (Creature* xt002 = _instance->GetCreature(DATA_XT002))
                {
                    if (me->IsWithinMeleeRange(xt002))
                        DoCastAOE(SPELL_BOOM);
                    else
                        checkXt002.Repeat();
                }
                else
                    me->DespawnOrUnsummon();
            });
    }

    void DamageTaken(Unit* /*who*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (damage >= (me->GetHealth() - me->GetMaxHealth() * 0.5f) && !_boomed)
        {
            _boomed = true; // Prevent recursive call
            damage = 0;
            DoCastAOE(SPELL_BOOM);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    InstanceScript* _instance;
    bool _boomed;
    TaskScheduler _scheduler;
};

struct npc_life_spark : public ScriptedAI
{
    npc_life_spark(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        DoCastSelf(SPELL_ARCANE_POWER_STATE);
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        DoCastSelf(SPELL_STATIC_CHARGED);
        _scheduler.Schedule(12s, [this](TaskContext spellShock)
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

struct npc_xt_void_zone : public PassiveAI
{
    npc_xt_void_zone(Creature* creature) : PassiveAI(creature) { }

    void JustAppeared() override
    {
        _scheduler.Schedule(2500ms, [this](TaskContext /*task*/)
        {
            DoCastSelf(SPELL_CONSUMPTION);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 63018, 65121 - Searing Light
class spell_xt002_searing_light_spawn_life_spark : public AuraScript
{
    PrepareAuraScript(spell_xt002_searing_light_spawn_life_spark);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_LIFE_SPARK });
    }

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (Player* player = GetOwner()->ToPlayer())
            if (Unit* xt002 = GetCaster())
                if (xt002->HasAura(aurEff->GetAmount()))   // Heartbreak aura indicating hard mode
                    xt002->CastSpell(player, SPELL_SUMMON_LIFE_SPARK, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_xt002_searing_light_spawn_life_spark::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// 63024, 64234 - Gravity Bomb
class spell_xt002_gravity_bomb_aura : public AuraScript
{
    PrepareAuraScript(spell_xt002_gravity_bomb_aura);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_VOID_ZONE });
    }

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (Player* player = GetOwner()->ToPlayer())
            if (Unit* xt002 = GetCaster())
                if (xt002->HasAura(aurEff->GetAmount()))   // Heartbreak aura indicating hard mode
                    xt002->CastSpell(player, SPELL_SUMMON_VOID_ZONE, true);
    }

    void OnPeriodic(AuraEffect const* aurEff)
    {
        Unit* xt002 = GetCaster();
        Unit* owner = GetTarget();
        if (!xt002)
            return;

        if (aurEff->GetAmount() >= int32(owner->GetHealth()))
            xt002->GetAI()->SetData(DATA_GRAVITY_BOMB_CASUALTY, 1);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_xt002_gravity_bomb_aura::OnPeriodic, EFFECT_2, SPELL_AURA_PERIODIC_DAMAGE);
        AfterEffectRemove += AuraEffectRemoveFn(spell_xt002_gravity_bomb_aura::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// 63025, 64233 - Gravity Bomb (Damage)
class spell_xt002_gravity_bomb_damage : public SpellScript
{
    PrepareSpellScript(spell_xt002_gravity_bomb_damage);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (GetHitDamage() >= int32(GetHitUnit()->GetHealth()))
            if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                if (Creature* xt002 = instance->GetCreature(DATA_XT002))
                    xt002->AI()->SetData(DATA_GRAVITY_BOMB_CASUALTY, 1);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_xt002_gravity_bomb_damage::HandleScript, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 62791 - XT-002 Heart Overload Trigger Spell (SERVERSIDE)
class spell_xt002_heart_overload_periodic : public SpellScript
{
    PrepareSpellScript(spell_xt002_heart_overload_periodic);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_ENERGY_ORB,
            SPELL_HEART_LIGHTNING_TETHER
         });
    }

    Creature* GetRandomToyPile()
    {
        std::list<Creature*> possibleCreatures;
        Unit* caster = GetCaster();
        caster->GetCreatureListWithEntryInGrid(possibleCreatures, NPC_XT_TOY_PILE);
        possibleCreatures.remove_if([caster](Creature* creature)
        {
            return caster->GetDistance2d(creature) < 60.0f;
        });

        if (possibleCreatures.empty())
            return nullptr;

        return Trinity::Containers::SelectRandomContainerElement(possibleCreatures);
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (Creature* toyPile = GetRandomToyPile())
        {
            caster->CastSpell(toyPile, SPELL_ENERGY_ORB, true);
            caster->CastSpell(nullptr, SPELL_HEART_LIGHTNING_TETHER, true);
        }
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_xt002_heart_overload_periodic::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 62826 - Energy Orb
class spell_xt002_energy_orb : public SpellScript
{
    PrepareSpellScript(spell_xt002_energy_orb);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_RECHARGE_BOOMBOT,
            SPELL_RECHARGE_PUMMELER,
            SPELL_RECHARGE_SCRAPBOT
        });
    }

    void HandleSummons(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        if (target->GetEntry() != NPC_XT_TOY_PILE)
            return;

        target->CastSpell(target, SPELL_RECHARGE_BOOMBOT, true);

        if (roll_chance_i(30))
            target->CastSpell(target, SPELL_RECHARGE_PUMMELER, true);

        for (uint8 i = 0; i < urand(5, 7); ++i)
            target->CastSpell(target, SPELL_RECHARGE_SCRAPBOT, true);

        if (Creature* base = GetCaster()->GetVehicleCreatureBase())
            base->AI()->Talk(SAY_SUMMON);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_xt002_energy_orb::HandleSummons, EFFECT_2, SPELL_EFFECT_DUMMY);
    }
};

// 62775 - Tympanic Tantrum
class spell_xt002_tympanic_tantrum : public SpellScript
{
    PrepareSpellScript(spell_xt002_tympanic_tantrum);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* object) -> bool
        {
            if (object->GetTypeId() == TYPEID_PLAYER)
                return false;

            if (Creature* creature = object->ToCreature())
                return !creature->IsPet();

            return true;
        });
    }

    void RecalculateDamage()
    {
        SetHitDamage(GetHitUnit()->CountPctFromMaxHealth(GetHitDamage()));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_xt002_tympanic_tantrum::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_xt002_tympanic_tantrum::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
        OnHit += SpellHitFn(spell_xt002_tympanic_tantrum::RecalculateDamage);
    }
};

// 65032 - 321-Boombot Aura
class spell_xt002_321_boombot_aura : public AuraScript
{
    PrepareAuraScript(spell_xt002_321_boombot_aura);

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
        if (InstanceScript* instance = eventInfo.GetActor()->GetInstanceScript())
            instance->DoCastSpellOnPlayers(SPELL_ACHIEVEMENT_CREDIT_NERF_SCRAPBOTS);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_xt002_321_boombot_aura::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_xt002_321_boombot_aura::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 63849 - Exposed Heart
class spell_xt002_exposed_heart : public AuraScript
{
    PrepareAuraScript(spell_xt002_exposed_heart);

    bool Load() override
    {
        _damageAmount = 0;
        return true;
    }

    void OnProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        DamageInfo* damageInfo = eventInfo.GetDamageInfo();
        if (!damageInfo || !damageInfo->GetDamage())
            return;

        _damageAmount += damageInfo->GetDamage();
    }

    void HandleLifeTransfer(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (InstanceScript* instance = GetTarget()->GetInstanceScript())
            if (Creature* xt002 = instance->GetCreature(DATA_XT002))
                xt002->AI()->SetData(DATA_TRANSFERED_HEALTH, _damageAmount);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_xt002_exposed_heart::OnProc, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN);
        AfterEffectRemove += AuraEffectRemoveFn(spell_xt002_exposed_heart::HandleLifeTransfer, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL);
    }

private:
    uint32 _damageAmount = 0;
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
    RegisterUlduarCreatureAI(boss_xt002);
    RegisterUlduarCreatureAI(npc_xt002_heart);
    RegisterUlduarCreatureAI(npc_scrapbot);
    RegisterUlduarCreatureAI(npc_pummeller);
    RegisterUlduarCreatureAI(npc_boombot);
    RegisterUlduarCreatureAI(npc_life_spark);
    RegisterUlduarCreatureAI(npc_xt_void_zone);

    RegisterSpellScript(spell_xt002_searing_light_spawn_life_spark);
    RegisterSpellScript(spell_xt002_gravity_bomb_aura);
    RegisterSpellScript(spell_xt002_gravity_bomb_damage);
    RegisterSpellScript(spell_xt002_heart_overload_periodic);
    RegisterSpellScript(spell_xt002_energy_orb);
    RegisterSpellScript(spell_xt002_tympanic_tantrum);
    RegisterSpellScript(spell_xt002_321_boombot_aura);
    RegisterSpellScript(spell_xt002_exposed_heart);

    new achievement_nerf_engineering();
    new achievement_heartbreaker();
    new achievement_nerf_gravity_bombs();
}
