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
#include "ScriptedCreature.h"
#include "zulgurub.h"
#include "GridNotifiers.h"
#include "MoveSplineInit.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "MotionMaster.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "Map.h"

enum Yells
{
    SAY_AGGRO                       = 0,
    SAY_TOXIC_LINK                  = 1,
    SAY_BLESSING_OF_THE_SNAKE_GOD   = 2,
    SAY_BLOODVENOM                  = 3,
    SAY_ANNOUNCE_BLOODVENOM         = 4,
    SAY_ANNOUNCE_EXHAUSTED          = 5,
    SAY_SLAY                        = 6,
    SAY_DEATH                       = 7
};

enum Spells
{
    // High Priest Venoxis
    SPELL_WORD_OF_HETHISS               = 96560,
    SPELL_WHISPERS_OF_HETHISS           = 96466,
    SPELL_TOXIC_LINK                    = 96475,
    SPELL_TOXIC_LINK_AURA               = 96477,
    SPELL_POOL_OF_ACRID_TEARS           = 96515,
    SPELL_BREATH_OF_HETHISS             = 96509,
    SPELL_TRANSFORM_REMOVAL_PRIMER      = 96617,
    SPELL_BLOODVENOM                    = 96842,
    SPELL_VENOM_TOTEM_BEAM_CENTER       = 97098,
    SPELL_VENOM_WITHDRAWAL              = 96653,

    // General Purpose Bunny JMF
    SPELL_TOTEM_BEAM_LEFT               = 96536,
    SPELL_TOTEM_BEAM_RIGHT              = 96537,
    SPELL_VENOM_TOTEM                   = 96534,
    SPELL_SNAKE_EYES                    = 96533,

    // Pool of Acrid Tears
    SPELL_VENOXIS_ULT_COSMETIC_MISSILE  = 96634,

    // Bloodvenom
    SPELL_BLOODVENOM_PERIODIC_AURA      = 97099
};

#define SPELL_BLESSING_OF_THE_SNAKE_GOD RAID_MODE<uint32>(96512, 97354)

enum Events
{
    // High Priest Venoxis
    EVENT_VENOMOUS_EFFUSION = 1,
    EVENT_WHISPERS_OF_HETHISS,
    EVENT_TOXIC_LINK,
    EVENT_BLESSING_OF_THE_SNAKE_GOD,
    EVENT_POOL_OF_ACRID_TEARS,
    EVENT_BREATH_OF_HETHISS,
    EVENT_PREPARE_BLOODVENOM,
    EVENT_TALK_BLOODVENOM,
    EVENT_BLOODVENOM,
    EVENT_VENOM_WITHDRAWAL
};

enum Points
{
    POINT_NONE = 0,
    POINT_ALTAR
};

enum WeaponDisplayIds
{
    WEAPON_DISPLAY_ID_NONE  = 0,
    WEAPON_DISPLAY_ID_STAVE = 68821
};

Position const PoisonCloudPositions[] =
{
    { -12019.1f, -1724.89f, 39.6277f, 0.0f },
    { -12031.1f, -1717.54f, 39.782f,  0.0f },
    { -12013.6f, -1723.38f, 39.3954f, 0.0f },
    { -12021.6f, -1718.47f, 39.3401f, 0.0f },
    { -12037.2f, -1705.58f, 40.3635f, 0.0f },
    { -12026.2f, -1712.12f, 39.3988f, 0.0f },
    { -12015.8f, -1713.22f, 39.3736f, 0.0f },
    { -12027.9f, -1705.49f, 39.3986f, 0.0f },
    { -12032.1f, -1700.49f, 39.4003f, 0.0f },
    { -12037.2f, -1694.58f, 39.3539f, 0.0f },
    { -12019.0f, -1707.24f, 39.456f,  0.0f },
    { -12022.3f, -1700.57f, 39.5043f, 0.0f },
    { -12037.0f, -1686.64f, 39.3952f, 0.0f },
    { -12027.5f, -1693.6f,  39.4573f, 0.0f },
    { -12031.2f, -1686.85f, 39.4894f, 0.0f },
    { -12017.0f, -1697.56f, 37.9073f, 0.0f },
    { -12036.9f, -1678.58f, 39.3986f, 0.0f },
    { -12013.7f, -1695.36f, 34.7955f, 0.0f },
    { -12010.5f, -1693.47f, 32.3669f, 0.0f },
    { -12034.4f, -1671.43f, 39.7001f, 0.0f },
    { -12000.8f, -1727.63f, 39.4153f, 0.0f },
    { -12005.5f, -1722.99f, 39.437f,  0.0f }
};

Position const SnakeEyesPositions[] =
{
    { -12024.7f, -1720.48f, 47.7639f,  0.925025f  },
    { -12038.1f, -1698.08f, 47.8078f,  0.0872665f },
    { -11983.2f, -1719.93f, 42.8957f,  1.88496f   },
    { -12025.1f, -1666.8f,  41.4725f,  5.044f     }
};

Position const TotemBeamLeftDummyPos            = { -12011.01f, -1705.972f, 43.47624f, 0.5235988f };
Position const TotemBeamRightDummyPos           = { -12021.83f, -1688.281f, 43.45235f, 0.5585054f };
Position const VenomousEffusionStalkerLeftPos   = { -12003.96f, -1698.644f, 32.36689f, 4.712389f  };
Position const VenomousEffusionStalkerRightPos  = { -12013.51f, -1684.175f, 32.36689f, 1.606759f  };
Position const AltarPos                         = { -12020.56f, -1699.814f, 39.55114f, 0.5585054f };
Position const VenomWithdrawalKnockbackPos      = { -12004.07f, -1689.513f, 32.40856f };

class DelayedFollowEvent : public BasicEvent
{
    public:
        DelayedFollowEvent(Creature* owner) : _owner(owner) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            if (_owner->IsAIEnabled)
                _owner->AI()->DoZoneInCombat();

            if (TempSummon* summon = _owner->ToTempSummon())
                if (Unit* target = summon->GetSummoner())
                    _owner->GetMotionMaster()->MoveFollow(target, 0.0f, 0.0f);
            return true;
        }
    private:
        Creature* _owner;
};

class DelayedBloodvenomCastEvent : public BasicEvent
{
    public:
        DelayedBloodvenomCastEvent(Creature* owner) : _owner(owner) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _owner->CastSpell(_owner, SPELL_BLOODVENOM_PERIODIC_AURA);
            return true;
        }
    private:
        Creature* _owner;
};

struct boss_high_priest_venoxis : public BossAI
{
    boss_high_priest_venoxis(Creature* creature) : BossAI(creature, DATA_HIGH_PRIEST_VENOXIS)
    {
        Initialize();
    }

    void Initialize()
    {
        _initialOrientation = 0.0f;
    }

    void Reset() override
    {
        _Reset();
        Initialize();
        if (Creature* leftBeamDummy = DoSummon(NPC_GENERAL_PURPOSE_DUMMY_JMF, TotemBeamLeftDummyPos, 0, TEMPSUMMON_MANUAL_DESPAWN))
        {
            leftBeamDummy->CastSpell(me, SPELL_TOTEM_BEAM_LEFT);
            leftBeamDummy->CastSpell(me, SPELL_VENOM_TOTEM, true);
            _leftTotemGUID = leftBeamDummy->GetGUID();
        }

        if (Creature* rightBeamDummy = DoSummon(NPC_GENERAL_PURPOSE_DUMMY_JMF, TotemBeamRightDummyPos, 0, TEMPSUMMON_MANUAL_DESPAWN))
        {
            rightBeamDummy->CastSpell(me, SPELL_TOTEM_BEAM_RIGHT);
            rightBeamDummy->CastSpell(me, SPELL_VENOM_TOTEM, true);
            _rightTotemGUID = rightBeamDummy->GetGUID();
        }

        for (uint8 i = 0; i < 22; i++)
            if (Creature* cloud = DoSummon(NPC_GENERAL_PURPOSE_DUMMY_JMF, PoisonCloudPositions[i], 0, TEMPSUMMON_MANUAL_DESPAWN))
                cloud->CastSpell(cloud, SPELL_POISON_CLOUD);

        for (uint8 i = 0; i < 4; i++)
            if (Creature* eyes = DoSummon(NPC_GENERAL_PURPOSE_DUMMY_JMF, SnakeEyesPositions[i], 0, TEMPSUMMON_MANUAL_DESPAWN))
                eyes->CastSpell(eyes, SPELL_SNAKE_EYES);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        Talk(SAY_AGGRO);
        me->RemoveAurasDueToSpell(SPELL_TOTEM_BEAM_LEFT);
        me->RemoveAurasDueToSpell(SPELL_TOTEM_BEAM_RIGHT);
        DoCastAOE(SPELL_WORD_OF_HETHISS);

        events.ScheduleEvent(EVENT_VENOMOUS_EFFUSION, 2s + 200ms);
        events.ScheduleEvent(EVENT_WHISPERS_OF_HETHISS, 6s);
        events.ScheduleEvent(EVENT_TOXIC_LINK, 14s + 400ms);
        events.ScheduleEvent(EVENT_BLESSING_OF_THE_SNAKE_GOD, 34s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        Talk(SAY_DEATH);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();
        _DespawnAtEvade();
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);
        if (summon->GetEntry() == NPC_BLOODVENOM)
        {
            summon->SetReactState(REACT_PASSIVE);
            summon->CastSpell(me, SPELL_VENOM_TOTEM_BEAM_CENTER);
            summon->m_Events.AddEvent(new DelayedFollowEvent(summon), summon->m_Events.CalculateTime(1000));
            summon->m_Events.AddEvent(new DelayedBloodvenomCastEvent(summon), summon->m_Events.CalculateTime(2000));
        }
    }

    void OnSpellCastFinished(SpellInfo const* spell, SpellFinishReason reason) override
    {
        if (reason != SPELL_FINISHED_SUCCESSFUL_CAST)
            return;

        switch (spell->Id)
        {
            case SPELL_TOXIC_LINK:
                Talk(SAY_TOXIC_LINK);
                break;
            case SPELL_BREATH_OF_HETHISS: // Tempfix to counter core issues with facing channel targets
                me->SetOrientation(_initialOrientation);
                break;
            default:
                break;
        }

        if (spell->Id == SPELL_BLESSING_OF_THE_SNAKE_GOD)
            me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, WEAPON_DISPLAY_ID_NONE);
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
            return;

        if (id == POINT_ALTAR)
        {
            me->SetFacingTo(AltarPos.GetOrientation());
            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_SPELL_CHANNEL_OMNI);
            events.ScheduleEvent(EVENT_TALK_BLOODVENOM, 2s + 500ms);
            events.ScheduleEvent(EVENT_BLOODVENOM, 4s + 500ms);
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
                case EVENT_VENOMOUS_EFFUSION:
                    if (Creature* effusionStalkerLeft = DoSummon(NPC_VENOMOUS_EFFUSION_STALKER, VenomousEffusionStalkerLeftPos, 43000, TEMPSUMMON_TIMED_DESPAWN))
                    {
                        // For some reason Blizzard uses other move speeds than their object packet indicates...
                        effusionStalkerLeft->SetSpeedRate(MOVE_WALK, 1.5f);
                        effusionStalkerLeft->GetMotionMaster()->MovePath(effusionStalkerLeft->GetEntry() * 10, false);
                        if (Creature* totemLeft = ObjectAccessor::GetCreature(*me, _leftTotemGUID))
                            totemLeft->CastSpell(effusionStalkerLeft, SPELL_TOTEM_BEAM_RIGHT);
                    }

                    if (Creature* effusionStalkerRight = DoSummon(NPC_VENOMOUS_EFFUSION_STALKER, VenomousEffusionStalkerRightPos, 42000, TEMPSUMMON_TIMED_DESPAWN))
                    {
                        effusionStalkerRight->SetSpeedRate(MOVE_WALK, 1.5f);
                        effusionStalkerRight->GetMotionMaster()->MovePath(effusionStalkerRight->GetEntry() * 10 + 1, false);
                        if (Creature* totemRight = ObjectAccessor::GetCreature(*me, _rightTotemGUID))
                            totemRight->CastSpell(effusionStalkerRight, SPELL_TOTEM_BEAM_RIGHT);
                    }
                    break;
                case EVENT_WHISPERS_OF_HETHISS:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
                    {
                        me->StopMoving();
                        DoCast(target, SPELL_WHISPERS_OF_HETHISS);
                    }

                    if (events.GetTimeUntilEvent(EVENT_BLESSING_OF_THE_SNAKE_GOD) > 8000) // Avoid some conflicts with phase 2
                        events.Repeat(8s + 500ms, 9s);
                    break;
                case EVENT_TOXIC_LINK:
                    DoCastAOE(SPELL_TOXIC_LINK);
                    break;
                case EVENT_BLESSING_OF_THE_SNAKE_GOD:
                    events.Reset();
                    Talk(SAY_BLESSING_OF_THE_SNAKE_GOD);
                    DoCastSelf(SPELL_BLESSING_OF_THE_SNAKE_GOD);
                    events.ScheduleEvent(EVENT_POOL_OF_ACRID_TEARS, 3s + 500ms);
                    events.ScheduleEvent(EVENT_BREATH_OF_HETHISS, 8s + 500ms);
                    events.ScheduleEvent(EVENT_PREPARE_BLOODVENOM, 24s);
                    break;
                case EVENT_POOL_OF_ACRID_TEARS:
                    if (Unit* target = SelectTarget(SELECT_TARGET_MAXDISTANCE, 0, 50.0f, true))
                        DoCast(target, SPELL_POOL_OF_ACRID_TEARS);
                    events.Repeat(3s + 500ms);
                    break;
                case EVENT_BREATH_OF_HETHISS:
                    DoCastAOE(SPELL_BREATH_OF_HETHISS);
                    _initialOrientation = me->GetOrientation();
                    events.Repeat(13s);
                    break;
                case EVENT_PREPARE_BLOODVENOM:
                    events.Reset();
                    if (me->IsMovementPreventedByCasting())
                        events.Repeat(1s);
                    else
                    {
                        DoCastSelf(SPELL_TRANSFORM_REMOVAL_PRIMER, true);
                        me->AttackStop();
                        me->SetReactState(REACT_PASSIVE);
                        me->GetMotionMaster()->MovePoint(POINT_ALTAR, AltarPos);
                    }
                    break;
                case EVENT_TALK_BLOODVENOM:
                    Talk(SAY_BLOODVENOM);
                    for (ObjectGuid guid : summons)
                    {
                        if (Creature* creature = ObjectAccessor::GetCreature(*me, guid))
                        {
                            if (creature->GetEntry() == NPC_POOL_OF_ACRID_TEARS)
                            {
                                creature->RemoveAllAuras();
                                creature->CastSpell(creature, SPELL_VENOXIS_ULT_COSMETIC_MISSILE, true);
                                creature->DespawnOrUnsummon(6s);
                            }
                        }
                    }
                    break;
                case EVENT_BLOODVENOM:
                    Talk(SAY_ANNOUNCE_BLOODVENOM);
                    DoCastAOE(SPELL_BLOODVENOM);
                    events.ScheduleEvent(EVENT_VENOM_WITHDRAWAL, 17s);
                    break;
                case EVENT_VENOM_WITHDRAWAL:
                    Talk(SAY_ANNOUNCE_EXHAUSTED);
                    DoCastSelf(SPELL_VENOM_WITHDRAWAL);
                    me->RemoveAurasDueToSpell(SPELL_BLESSING_OF_THE_SNAKE_GOD);
                    me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, WEAPON_DISPLAY_ID_STAVE);
                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
                    me->SetReactState(REACT_AGGRESSIVE);

                    events.ScheduleEvent(EVENT_VENOMOUS_EFFUSION, 12s);
                    events.ScheduleEvent(EVENT_TOXIC_LINK, 12s);
                    events.ScheduleEvent(EVENT_WHISPERS_OF_HETHISS, 14s, 15s);
                    events.ScheduleEvent(EVENT_BLESSING_OF_THE_SNAKE_GOD, 31s, 32s);

                    for (ObjectGuid guid : summons)
                    {
                        if (Creature* creature = ObjectAccessor::GetCreature(*me, guid))
                        {
                            if (creature->GetEntry() == NPC_VENOMOUS_EFFUSION)
                            {
                                creature->RemoveAllAuras();
                                creature->DespawnOrUnsummon(3s + 500ms);
                            }
                        }
                    }

                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
private:
    ObjectGuid _leftTotemGUID;
    ObjectGuid _rightTotemGUID;
    float _initialOrientation;
};

class spell_venoxis_venomous_effusion : public SpellScript
{
    void SetDest(SpellDestination& dest)
    {
        Unit* caster = GetCaster();

        Position pos = caster->GetPosition();
        pos.m_positionZ += 5.0f;
        pos.m_positionZ = GetCaster()->GetMap()->GetHeight(caster->GetPhaseShift(), pos) + 1.0f;
        dest.Relocate(pos);
    }

    void Register()
    {
        OnDestinationTargetSelect.Register(&spell_venoxis_venomous_effusion::SetDest, EFFECT_1, TARGET_DEST_CASTER);
    }
};

class spell_venoxis_whispers_of_hethiss : public AuraScript
{
    void HandleTick(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        if (Unit* caster = GetCaster())
           if (Unit* target = ObjectAccessor::GetUnit(*caster, caster->GetChannelObjectGuid()))
                caster->CastSpell(target, GetSpellInfo()->Effects[EFFECT_1].TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_venoxis_whispers_of_hethiss::HandleTick, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_venoxis_toxic_link_targeting : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.size() > 2)
            Trinity::Containers::RandomResize(targets, 2);
    }

    void HandleEffect(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_venoxis_toxic_link_targeting::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget.Register(&spell_venoxis_toxic_link_targeting::HandleEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_venoxis_toxic_link : public AuraScript
{
    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* target = GetTarget())
            target->CastSpell(target, GetSpellInfo()->Effects[EFFECT_2].BasePoints, true);
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_venoxis_toxic_link::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_venoxis_toxic_link_ally : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TOXIC_LINK_AURA });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
        {
            GetCaster()->RemoveAurasDueToSpell(SPELL_TOXIC_LINK_AURA);
            return;
        }

        targets.remove_if(Trinity::UnitAuraCheck(false, SPELL_TOXIC_LINK_AURA));

        if (targets.empty())
            GetCaster()->RemoveAurasDueToSpell(SPELL_TOXIC_LINK_AURA);
    }


    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_venoxis_toxic_link_ally::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
    }
};

class spell_venoxis_pool_of_acrid_tears : public AuraScript
{
    void HandlePeriodic(AuraEffect const* aurEff)
    {
        PreventDefaultAction();
        if (Unit* target = GetTarget())
        {
            uint32 triggerSpell = GetSpellInfo()->Effects[EFFECT_0].TriggerSpell;
            int32 radius = target->GetObjectScale() * 75;
            target->CastSpell(nullptr, triggerSpell, CastSpellExtraArgs(aurEff).SetOriginalCaster(target->GetGUID()).AddSpellMod(SPELLVALUE_RADIUS_MOD, radius));
        }
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_venoxis_pool_of_acrid_tears::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_venoxis_blood_venom_forcecast : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        if (targets.size() > 3)
            Trinity::Containers::RandomResize(targets, 3);
    }

    void HandleSummon(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        GetHitUnit()->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].TriggerSpell, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_venoxis_blood_venom_forcecast::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget.Register(&spell_venoxis_blood_venom_forcecast::HandleSummon, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
    }
};

class spell_venom_withdrawal : public SpellScript
{
    void HandleKnockback(SpellEffIndex effIndex)
    {
        // Let's do our own knockback to make sure that we hit our sniffed position
        PreventHitDefaultEffect(effIndex);
        float moveTimeHalf = 15.0f / Movement::gravity;
        float max_height = -Movement::computeFallElevation(moveTimeHalf, false, -15.0f);

        Movement::MoveSplineInit init(GetHitUnit());
        init.MoveTo(VenomWithdrawalKnockbackPos.GetPositionX(), VenomWithdrawalKnockbackPos.GetPositionY(), VenomWithdrawalKnockbackPos.GetPositionZ());
        init.SetParabolic(max_height, 0);
        init.SetOrientationFixed(true);
        init.SetVelocity(25.0f);
        init.Launch();
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_venom_withdrawal::HandleKnockback, EFFECT_2, SPELL_EFFECT_LEAP_BACK);
    }
};

void AddSC_boss_high_priest_venoxis()
{
    RegisterZulGurubCreatureAI(boss_high_priest_venoxis);
    RegisterSpellScript(spell_venoxis_venomous_effusion);
    RegisterSpellScript(spell_venoxis_whispers_of_hethiss);
    RegisterSpellScript(spell_venoxis_toxic_link_targeting);
    RegisterSpellScript(spell_venoxis_toxic_link);
    RegisterSpellScript(spell_venoxis_toxic_link_ally);
    RegisterSpellScript(spell_venoxis_pool_of_acrid_tears);
    RegisterSpellScript(spell_venoxis_blood_venom_forcecast);
    RegisterSpellScript(spell_venom_withdrawal);
}
