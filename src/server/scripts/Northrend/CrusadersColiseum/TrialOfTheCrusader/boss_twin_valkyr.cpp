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

// Known bugs:
//    - They should be floating but they aren't respecting the floor =(
//    - Hardcoded bullets spawner

#include "ScriptMgr.h"
#include "CellImpl.h"
#include "GridNotifiersImpl.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "trial_of_the_crusader.h"

enum Texts
{
    SAY_AGGRO               = 0,
    SAY_NIGHT               = 1,
    SAY_LIGHT               = 2,
    EMOTE_VORTEX            = 3,
    EMOTE_TWIN_PACT         = 4,
    SAY_TWIN_PACT           = 5,
    SAY_KILL_PLAYER         = 6,
    SAY_BERSERK             = 7,
    SAY_DEATH               = 8
};

enum Misc
{
    EQUIP_MAIN_1            = 9423,
    EQUIP_MAIN_2            = 37377,
    POINT_INITIAL_MOVEMENT  = 1,
    SPLINE_INITIAL_MOVEMENT = 1,
    PHASE_EVENT             = 1,
    PHASE_COMBAT            = 2
};

enum Summons
{
    NPC_BULLET_CONTROLLER        = 34743,

    NPC_BULLET_DARK              = 34628,
    NPC_BULLET_LIGHT             = 34630
};

enum BossSpells
{
    SPELL_LIGHT_TWIN_SPIKE      = 66075,
    SPELL_LIGHT_SURGE           = 65766,
    SPELL_LIGHT_SHIELD          = 65858,
    SPELL_LIGHT_TWIN_PACT       = 65876,
    SPELL_LIGHT_VORTEX          = 66046,
    SPELL_LIGHT_VORTEX_DAMAGE   = 66048,
    SPELL_LIGHT_TOUCH           = 67297,
    SPELL_LIGHT_ESSENCE         = 65686,
    SPELL_EMPOWERED_LIGHT       = 65748,
    SPELL_TWIN_EMPATHY_LIGHT    = 66133,
    SPELL_UNLEASHED_LIGHT       = 65795,

    SPELL_DARK_TWIN_SPIKE       = 66069,
    SPELL_DARK_SURGE            = 65768,
    SPELL_DARK_SHIELD           = 65874,
    SPELL_DARK_TWIN_PACT        = 65875,
    SPELL_DARK_VORTEX           = 66058,
    SPELL_DARK_VORTEX_DAMAGE    = 66059,
    SPELL_DARK_TOUCH            = 67282,
    SPELL_DARK_ESSENCE          = 65684,
    SPELL_EMPOWERED_DARK        = 65724,
    SPELL_TWIN_EMPATHY_DARK     = 66132,
    SPELL_UNLEASHED_DARK        = 65808,

    SPELL_CONTROLLER_PERIODIC   = 66149,
    SPELL_POWER_TWINS           = 65879,
    SPELL_BERSERK               = 64238,
    SPELL_POWERING_UP           = 67590,
    SPELL_SURGE_OF_SPEED        = 65828,

    SPELL_SUMMON_PERIODIC_LIGHT = 66152,
    SPELL_SUMMON_PERIODIC_DARK  = 66153

};

enum Events
{
    EVENT_TWIN_SPIKE      = 1,
    EVENT_TOUCH           = 2,
    EVENT_SPECIAL_ABILITY = 3,
    EVENT_BERSERK         = 4,
    EVENT_START_MOVE      = 5
};

enum Stages
{
    STAGE_DARK_VORTEX,
    STAGE_DARK_PACT,
    STAGE_LIGHT_VORTEX,
    STAGE_LIGHT_PACT,
    MAX_STAGES
};

// branch compatibility macros
#define SPELL_DARK_ESSENCE_HELPER SPELL_DARK_ESSENCE
#define SPELL_LIGHT_ESSENCE_HELPER SPELL_LIGHT_ESSENCE

#define SPELL_POWERING_UP_HELPER SPELL_POWERING_UP

#define SPELL_UNLEASHED_DARK_HELPER SPELL_UNLEASHED_DARK
#define SPELL_UNLEASHED_LIGHT_HELPER SPELL_UNLEASHED_LIGHT

enum Actions
{
    ACTION_VORTEX,
    ACTION_PACT
};

#define ESSENCE_REMOVE 0
#define ESSENCE_APPLY 1

class OrbsDespawner : public BasicEvent
{
    public:
        explicit OrbsDespawner(Creature* creature) : _creature(creature) { }

        bool Execute(uint64 /*currTime*/, uint32 /*diff*/) override
        {
            Trinity::CreatureWorker<OrbsDespawner> worker(_creature, *this);
            Cell::VisitGridObjects(_creature, worker, SIZE_OF_GRIDS);
            return true;
        }

        void operator()(Creature* creature) const
        {
            switch (creature->GetEntry())
            {
                case NPC_BULLET_DARK:
                case NPC_BULLET_LIGHT:
                    creature->DespawnOrUnsummon();
                    return;
                default:
                    return;
            }
        }

    private:
        Creature* _creature;
};

static uint32 GetSisterData(uint32 sisterEntry)
{
    return sisterEntry == NPC_FJOLA_LIGHTBANE ? DATA_FJOLA_LIGHTBANE : DATA_EYDIS_DARKBANE;
}

struct boss_twin_baseAI : public BossAI
{
    boss_twin_baseAI(Creature* creature, uint32 bossId) : BossAI(creature, bossId)
    {
        AuraState = AURA_STATE_NONE;
        Weapon = 0;
        SisterNpcId = 0;
        MyEmphatySpellId = 0;
        OtherEssenceSpellId = 0;
        SurgeSpellId = 0;
        VortexSpellId = 0;
        ShieldSpellId = 0;
        TwinPactSpellId = 0;
        SpikeSpellId = 0;
        TouchSpellId = 0;
        SetBoundary(instance->GetBossBoundary(DATA_TWIN_VALKIRIES));
    }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        me->ModifyAuraState(AuraState, true);
        summons.DespawnAll();
    }

    void JustAppeared() override
    {
        events.Reset();
        events.SetPhase(PHASE_EVENT);
        events.ScheduleEvent(EVENT_START_MOVE, 4s);
    }

    void JustReachedHome() override
    {
        instance->SetBossState(DATA_TWIN_VALKIRIES, FAIL);
        HandleRemoveAuras();
        summons.DespawnAll();
        me->DespawnOrUnsummon();
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type == SPLINE_CHAIN_MOTION_TYPE && pointId == POINT_INITIAL_MOVEMENT)
        {
            me->SetImmuneToPC(false);
            me->SetReactState(REACT_AGGRESSIVE);
            if (me->GetEntry() == NPC_FJOLA_LIGHTBANE) // avoid call twice
                instance->DoCloseDoorOrButton(instance->GetGuidData(DATA_MAIN_GATE));
        }
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_KILL_PLAYER);
    }

    void HandleRemoveAuras()
    {
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_LIGHT_ESSENCE);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_POWERING_UP);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DARK_ESSENCE);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_POWERING_UP);
        me->m_Events.AddEventAtOffset(new OrbsDespawner(me), 100ms);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        if (Creature* pSister = GetSister())
        {
            if (!pSister->IsAlive())
            {
                me->SetDynamicFlag(UNIT_DYNFLAG_LOOTABLE);
                pSister->SetDynamicFlag(UNIT_DYNFLAG_LOOTABLE);
                events.Reset();
                summons.DespawnAll();
                HandleRemoveAuras();
                instance->SetBossState(DATA_TWIN_VALKIRIES, DONE);
            }
            else
            {
                me->RemoveDynamicFlag(UNIT_DYNFLAG_LOOTABLE);
                instance->SetBossState(DATA_TWIN_VALKIRIES, SPECIAL);
            }
        }
        summons.DespawnAll();
    }

    // Called when sister pointer needed
    Creature* GetSister()
    {
        return instance->GetCreature(GetSisterData(SisterNpcId));
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        DoZoneInCombat();
        if (Creature* pSister = GetSister())
        {
            me->AddAura(MyEmphatySpellId, pSister);
            DoZoneInCombat(pSister);
        }
        instance->SetBossState(DATA_TWIN_VALKIRIES, IN_PROGRESS);

        Talk(SAY_AGGRO);
        DoCast(me, SurgeSpellId);
        me->SetCombatPulseDelay(5);
        me->setActive(true);

        events.ScheduleEvent(EVENT_TWIN_SPIKE, 20s);
        events.ScheduleEvent(EVENT_BERSERK, IsHeroic() ? 6min : 8min);
        if (IsHeroic())
            events.ScheduleEvent(EVENT_TOUCH, 10s, 15s);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_VORTEX:
                Talk(EMOTE_VORTEX);
                DoCastAOE(VortexSpellId);
                break;
            case ACTION_PACT:
                Talk(EMOTE_TWIN_PACT);
                Talk(SAY_TWIN_PACT);
                if (Creature* sister = GetSister())
                    sister->CastSpell(sister, SPELL_POWER_TWINS, false);
                DoCast(me, ShieldSpellId);
                DoCast(me, TwinPactSpellId);
                break;
            default:
                break;
        }
    }

    void EnableDualWield(bool mode = true)
    {
        SetEquipmentSlots(false, Weapon, mode ? Weapon : int32(EQUIP_UNEQUIP), EQUIP_UNEQUIP);
        me->SetCanDualWield(mode);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_TWIN_SPIKE:
                DoCastVictim(SpikeSpellId);
                events.Repeat(20s);
                break;
            case EVENT_TOUCH:
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 200.0f, true, true, OtherEssenceSpellId))
                {
                    CastSpellExtraArgs args;
                    args.AddSpellMod(SPELLVALUE_MAX_TARGETS, 1); // @todo spellmgr correction instead?
                    me->CastSpell(target, TouchSpellId, args);
                }
                events.Repeat(10s, 15s);
                break;
            case EVENT_BERSERK:
                DoCast(me, SPELL_BERSERK);
                Talk(SAY_BERSERK);
                break;
            case EVENT_START_MOVE:
                events.SetPhase(PHASE_COMBAT);
                me->GetMotionMaster()->MoveAlongSplineChain(POINT_INITIAL_MOVEMENT, SPLINE_INITIAL_MOVEMENT, false);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && !events.IsInPhase(PHASE_EVENT))
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            ExecuteEvent(eventId);
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

    protected:
        AuraStateType AuraState;
        uint32 Weapon;
        uint32 SisterNpcId;
        uint32 MyEmphatySpellId;
        uint32 OtherEssenceSpellId;
        uint32 SurgeSpellId;
        uint32 VortexSpellId;
        uint32 ShieldSpellId;
        uint32 TwinPactSpellId;
        uint32 SpikeSpellId;
        uint32 TouchSpellId;
};

struct boss_fjola : public boss_twin_baseAI
{
    boss_fjola(Creature* creature) : boss_twin_baseAI(creature, DATA_FJOLA_LIGHTBANE)
    {
        GenerateStageSequence();
    }

    void Reset() override
    {
        SetEquipmentSlots(false, EQUIP_MAIN_1, EQUIP_UNEQUIP, EQUIP_NO_CHANGE);
        Weapon = EQUIP_MAIN_1;
        AuraState = AURA_STATE_RAID_ENCOUNTER;
        SisterNpcId = NPC_EYDIS_DARKBANE;
        MyEmphatySpellId = SPELL_TWIN_EMPATHY_DARK;
        OtherEssenceSpellId = SPELL_DARK_ESSENCE_HELPER;
        SurgeSpellId = SPELL_LIGHT_SURGE;
        VortexSpellId = SPELL_LIGHT_VORTEX;
        ShieldSpellId = SPELL_LIGHT_SHIELD;
        TwinPactSpellId = SPELL_LIGHT_TWIN_PACT;
        TouchSpellId = SPELL_LIGHT_TOUCH;
        SpikeSpellId = SPELL_LIGHT_TWIN_SPIKE;

        instance->DoStopCriteriaTimer(CriteriaStartEvent::SendEvent,  EVENT_START_TWINS_FIGHT);
        boss_twin_baseAI::Reset();
    }

    void ExecuteEvent(uint32 eventId) override
    {
        if (eventId == EVENT_SPECIAL_ABILITY)
        {
            if (CurrentStage == MAX_STAGES)
                GenerateStageSequence();

            switch (Stage[CurrentStage])
            {
                case STAGE_DARK_VORTEX:
                    if (Creature* sister = GetSister())
                        sister->AI()->DoAction(ACTION_VORTEX);
                    break;
                case STAGE_DARK_PACT:
                    if (Creature* sister = GetSister())
                        sister->AI()->DoAction(ACTION_PACT);
                    break;
                case STAGE_LIGHT_VORTEX:
                    DoAction(ACTION_VORTEX);
                    break;
                case STAGE_LIGHT_PACT:
                    DoAction(ACTION_PACT);
                    break;
                default:
                    break;
            }
            ++CurrentStage;
            events.ScheduleEvent(EVENT_SPECIAL_ABILITY, 45s);
        }
        else
            boss_twin_baseAI::ExecuteEvent(eventId);
    }

    void JustEngagedWith(Unit* who) override
    {
        instance->DoStartCriteriaTimer(CriteriaStartEvent::SendEvent,  EVENT_START_TWINS_FIGHT);
        events.ScheduleEvent(EVENT_SPECIAL_ABILITY, 45s);
        me->SummonCreature(NPC_BULLET_CONTROLLER, ToCCommonLoc[1].GetPositionX(), ToCCommonLoc[1].GetPositionY(), ToCCommonLoc[1].GetPositionZ(), 0.0f, TEMPSUMMON_MANUAL_DESPAWN);
        boss_twin_baseAI::JustEngagedWith(who);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        instance->DoUseDoorOrButton(instance->GetGuidData(DATA_MAIN_GATE));
        boss_twin_baseAI::EnterEvadeMode(why);
    }

    void JustReachedHome() override
    {
        instance->DoUseDoorOrButton(instance->GetGuidData(DATA_MAIN_GATE));
        boss_twin_baseAI::JustReachedHome();
    }

    void GenerateStageSequence()
    {
        CurrentStage = 0;

        // Initialize and clean up.
        for (int i = 0; i < MAX_STAGES; ++i)
            Stage[i] = i;

        // Allocate an unique random stage to each position in the array.
        for (int i = 0; i < MAX_STAGES - 1; ++i)
        {
            int random = i + urand(0, MAX_STAGES - i);
            std::swap(Stage[i], Stage[random]);
        }
    }
    private:
        uint8 Stage[4];
        uint8 CurrentStage;
};

struct boss_eydis : public boss_twin_baseAI
{
    boss_eydis(Creature* creature) : boss_twin_baseAI(creature, DATA_EYDIS_DARKBANE) { }

    void Reset() override
    {
        SetEquipmentSlots(false, EQUIP_MAIN_2, EQUIP_UNEQUIP, EQUIP_NO_CHANGE);
        Weapon = EQUIP_MAIN_2;
        AuraState = AURA_STATE_VULNERABLE;
        SisterNpcId = NPC_FJOLA_LIGHTBANE;
        MyEmphatySpellId = SPELL_TWIN_EMPATHY_LIGHT;
        OtherEssenceSpellId = SPELL_LIGHT_ESSENCE_HELPER;
        SurgeSpellId = SPELL_DARK_SURGE;
        VortexSpellId = SPELL_DARK_VORTEX;
        ShieldSpellId = SPELL_DARK_SHIELD;
        TwinPactSpellId = SPELL_DARK_TWIN_PACT;
        TouchSpellId = SPELL_DARK_TOUCH;
        SpikeSpellId = SPELL_DARK_TWIN_SPIKE;
        boss_twin_baseAI::Reset();
    }
};

struct npc_essence_of_twin : public ScriptedAI
{
    npc_essence_of_twin(Creature* creature) : ScriptedAI(creature) { }

    uint32 GetData(uint32 data) const override
    {
        uint32 spellReturned = 0;
        switch (me->GetEntry())
        {
            case NPC_LIGHT_ESSENCE:
                spellReturned = (data == ESSENCE_REMOVE) ? SPELL_DARK_ESSENCE_HELPER : SPELL_LIGHT_ESSENCE_HELPER;
                break;
            case NPC_DARK_ESSENCE:
                spellReturned = (data == ESSENCE_REMOVE) ? SPELL_LIGHT_ESSENCE_HELPER : SPELL_DARK_ESSENCE_HELPER;
                break;
            default:
                break;
        }

        return spellReturned;
    }

    bool OnGossipHello(Player* player) override
    {
        player->RemoveAurasDueToSpell(GetData(ESSENCE_REMOVE));
        player->CastSpell(player, GetData(ESSENCE_APPLY), true);
        CloseGossipMenuFor(player);
        return true;
    }
};

struct npc_unleashed_ballAI : public ScriptedAI
{
    npc_unleashed_ballAI(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        RangeCheckTimer = 500;
    }

    void MoveToNextPoint()
    {
        float x0 = ToCCommonLoc[1].GetPositionX(), y0 = ToCCommonLoc[1].GetPositionY(), r = 47.0f;
        float y = y0;
        float x = frand(x0 - r, x0 + r);
        float sq = std::pow(r, 2.f) - std::pow(x - x0, 2.f);
        float rt = std::sqrt(std::fabs(sq));
        if (urand(0, 1))
            y = y0 + rt;
        else
            y = y0 - rt;
        me->GetMotionMaster()->MovePoint(0, x, y, me->GetPositionZ());
    }

    void Reset() override
    {
        me->SetUnitFlag(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_UNINTERACTIBLE);
        me->SetReactState(REACT_PASSIVE);
        me->SetDisableGravity(true);
        me->SetCanFly(true);
        SetCombatMovement(false);
        MoveToNextPoint();
        Initialize();
    }

    void MovementInform(uint32 uiType, uint32 uiId) override
    {
        if (uiType != POINT_MOTION_TYPE)
            return;

        switch (uiId)
        {
            case 0:
                if (urand(0, 3) == 0)
                    MoveToNextPoint();
                else
                    me->DisappearAndDie();
                break;
            default:
                break;
        }
    }

    protected:
        uint32 RangeCheckTimer;
};

struct npc_unleashed_dark : public npc_unleashed_ballAI
{
    npc_unleashed_dark(Creature* creature) : npc_unleashed_ballAI(creature) { }

    void UpdateAI(uint32 diff) override
    {
        if (RangeCheckTimer < diff)
        {
            if (me->SelectNearestPlayer(3.0f))
            {
                DoCastAOE(SPELL_UNLEASHED_DARK_HELPER);
                me->GetMotionMaster()->MoveIdle();
                me->DespawnOrUnsummon(1s);
            }
            RangeCheckTimer = 500;
        }
        else
            RangeCheckTimer -= diff;
    }
};

struct npc_unleashed_light : public npc_unleashed_ballAI
{
    npc_unleashed_light(Creature* creature) : npc_unleashed_ballAI(creature) { }

    void UpdateAI(uint32 diff) override
    {
        if (RangeCheckTimer < diff)
        {
            if (me->SelectNearestPlayer(3.0f))
            {
                DoCastAOE(SPELL_UNLEASHED_LIGHT_HELPER);
                me->GetMotionMaster()->MoveIdle();
                me->DespawnOrUnsummon(1s);
            }
            RangeCheckTimer = 500;
        }
        else
            RangeCheckTimer -= diff;
    }
};

struct npc_bullet_controller : public ScriptedAI
{
    npc_bullet_controller(Creature* creature) : ScriptedAI(creature)
    {
        SetCombatMovement(false);
    }

    void Reset() override
    {
        DoCastAOE(SPELL_CONTROLLER_PERIODIC);
    }

    void UpdateAI(uint32 /*diff*/) override
    {
        UpdateVictim();
    }
};

// 66149, 68396 - Bullet Controller Periodic
class spell_bullet_controller : public AuraScript
{
    PrepareAuraScript(spell_bullet_controller);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_PERIODIC_LIGHT, SPELL_SUMMON_PERIODIC_DARK });
    }

    void PeriodicTick(AuraEffect const* /*aurEff*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        CastSpellExtraArgs args1(TRIGGERED_FULL_MASK), args2(TRIGGERED_FULL_MASK);
        args1.AddSpellMod(SPELLVALUE_MAX_TARGETS, urand(1, 6));
        args2.AddSpellMod(SPELLVALUE_MAX_TARGETS, urand(1, 6));
        caster->CastSpell(GetTarget(), SPELL_SUMMON_PERIODIC_LIGHT, args1);
        caster->CastSpell(GetTarget(), SPELL_SUMMON_PERIODIC_DARK, args2);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_bullet_controller::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 67590, 67602, 67603, 67604 - Powering Up
class spell_powering_up : public SpellScript
{
    PrepareSpellScript(spell_powering_up);

    uint32 spellId = 0;
    uint32 poweringUp = 0;

    bool Load() override
    {
        spellId = SPELL_SURGE_OF_SPEED;
        if (!sSpellMgr->GetSpellInfo(spellId, GetCastDifficulty()))
            return false;

        poweringUp = SPELL_POWERING_UP;
        if (!sSpellMgr->GetSpellInfo(poweringUp, GetCastDifficulty()))
            return false;

        return true;
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
        {
            if (Aura* pAura = target->GetAura(poweringUp))
            {
                if (pAura->GetStackAmount() >= 100)
                {
                    if (target->HasAura(SPELL_DARK_ESSENCE_HELPER))
                        target->CastSpell(target, SPELL_EMPOWERED_DARK, true);

                    if (target->HasAura(SPELL_LIGHT_ESSENCE_HELPER))
                        target->CastSpell(target, SPELL_EMPOWERED_LIGHT, true);

                    target->RemoveAurasDueToSpell(poweringUp);
                }
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_powering_up::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 65684, 67176, 67177, 67178 - Dark Essence
// 65686, 67222, 67223, 67224 - Light Essence
class spell_valkyr_essences : public AuraScript
{
    PrepareAuraScript(spell_valkyr_essences);

public:
    spell_valkyr_essences()
    {
        spellId = 0;
    }

private:
    uint32 spellId;

    bool Load() override
    {
        spellId = SPELL_SURGE_OF_SPEED;
        if (!sSpellMgr->GetSpellInfo(spellId, GetCastDifficulty()))
            return false;
        return true;
    }

    void Absorb(AuraEffect* /*aurEff*/, DamageInfo & dmgInfo, uint32 & /*absorbAmount*/)
    {
        if (Unit* owner = GetUnitOwner())
        {
            if (dmgInfo.GetSpellInfo())
            {
                uint32 poweringUp = SPELL_POWERING_UP;
                if (urand(0, 99) < 5)
                    GetTarget()->CastSpell(GetTarget(), spellId, true);

                // Twin Vortex part
                uint32 lightVortex = SPELL_LIGHT_VORTEX_DAMAGE;
                uint32 darkVortex = SPELL_DARK_VORTEX_DAMAGE;
                int32 stacksCount = dmgInfo.GetSpellInfo()->GetEffect(EFFECT_0).CalcValue() / 1000 - 1;

                if (lightVortex && darkVortex && stacksCount)
                {
                    if (dmgInfo.GetSpellInfo()->Id == darkVortex || dmgInfo.GetSpellInfo()->Id == lightVortex)
                    {
                        if (Aura* aura = owner->GetAura(poweringUp))
                        {
                            aura->ModStackAmount(stacksCount);
                            owner->CastSpell(owner, poweringUp, true);
                        }
                        else
                        {
                            owner->CastSpell(owner, poweringUp, true);
                            if (Aura* newAura = owner->GetAura(poweringUp))
                                newAura->ModStackAmount(stacksCount);
                        }
                    }
                }

                // Picking floating balls
                uint32 unleashedDark = SPELL_UNLEASHED_DARK;
                uint32 unleashedLight = SPELL_UNLEASHED_LIGHT;

                if (unleashedDark && unleashedLight)
                {
                    if (dmgInfo.GetSpellInfo()->Id == unleashedDark || dmgInfo.GetSpellInfo()->Id == unleashedLight)
                    {
                        // need to do the things in this order, else players might have 100 charges of Powering Up without anything happening
                        if (Aura* aura = owner->GetAura(poweringUp))
                        {
                            // 2 lines together add the correct amount of buff stacks
                            aura->ModStackAmount(stacksCount);
                            owner->CastSpell(owner, poweringUp, true);
                        }
                        else
                        {
                            owner->CastSpell(owner, poweringUp, true);
                            if (Aura* newAura = owner->GetAura(poweringUp))
                                newAura->ModStackAmount(stacksCount);
                        }
                    }
                }
            }
        }
    }

    void Register() override
    {
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_valkyr_essences::Absorb, EFFECT_0);
    }
};

// 65879, 67244, 67245, 67246 - Power of the Twins
// 65916, 67248, 67249, 67250 - Power of the Twins
class spell_power_of_the_twins : public AuraScript
{
    PrepareAuraScript(spell_power_of_the_twins);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
        {
            if (Creature* valk = instance->GetCreature(GetSisterData(GetCaster()->GetEntry())))
                ENSURE_AI(boss_twin_baseAI, valk->AI())->EnableDualWield(true);
        }
    }

    void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
        {
            if (Creature* valk = instance->GetCreature(GetSisterData(GetCaster()->GetEntry())))
                ENSURE_AI(boss_twin_baseAI, valk->AI())->EnableDualWield(false);
        }
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_power_of_the_twins::HandleEffectApply, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_power_of_the_twins::HandleEffectRemove, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
};

void AddSC_boss_twin_valkyr()
{
    RegisterTrialOfTheCrusaderCreatureAI(boss_fjola);
    RegisterTrialOfTheCrusaderCreatureAI(boss_eydis);
    RegisterTrialOfTheCrusaderCreatureAI(npc_unleashed_light);
    RegisterTrialOfTheCrusaderCreatureAI(npc_unleashed_dark);
    RegisterTrialOfTheCrusaderCreatureAI(npc_essence_of_twin);
    RegisterTrialOfTheCrusaderCreatureAI(npc_bullet_controller);

    RegisterSpellScript(spell_bullet_controller);
    RegisterSpellScript(spell_powering_up);
    RegisterSpellScript(spell_valkyr_essences);
    RegisterSpellScript(spell_power_of_the_twins);
}
