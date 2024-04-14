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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "Containers.h"
#include "Conversation.h"
#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SharedDefines.h"
#include "SpellAuras.h"
#include "SpellHistory.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "trial_of_valor.h"

enum GuarmSpells
{
    SPELL_HELYATOSIS_AURA                   = 231561,
    SPELL_HELYATOSIS_INITIAL_ENERGIZE       = 235130,
    SPELL_MULTI_HEADED_AURA                 = 227512,
    SPELL_MULTI_HEADED_DAMAGE               = 227642,
    SPELL_FLASHING_FANGS                    = 227514,
    SPELL_OFF_THE_LEASH                     = 228201,

    SPELL_FLAME_LICK_SELECTOR               = 228226, // triggers 228227 missile
    SPELL_SHADOW_LICK_SELECTOR              = 228250, // triggers 228251 missile
    SPELL_FROST_LICK_SELECTOR               = 228246, // triggers 228247 missile

    SPELL_BERSERK                           = 26662,
    SPELL_BERSERK_TRAMPLE_AOE               = 232224,
    SPELL_BERSERK_CHARGE_AT                 = 232173, // triggers 232197

    SPELL_GUARDIANS_BREATH_COLOR_SELECTOR   = 228187,
    SPELL_GUARDIANS_BREATH_SUMMON_ATS_RGB   = 232811, // Red Green Blue
    SPELL_GUARDIANS_BREATH_SUMMON_ATS_RBG   = 232810, // Red Blue Green
    SPELL_GUARDIANS_BREATH_SUMMON_ATS_GRB   = 232775, // Green Red Blue
    SPELL_GUARDIANS_BREATH_SUMMON_ATS_GBR   = 232808, // Green Blue Red
    SPELL_GUARDIANS_BREATH_SUMMON_ATS_BRG   = 232809, // Blue Red Green
    SPELL_GUARDIANS_BREATH_SUMMON_ATS_BGR   = 232807, // Blue Green Red
    SPELL_GUARDIANS_BREATH_UNK              = 227573,
    SPELL_GUARDIANS_BREATH_CAST_RGB         = 227673, // Red Green Blue
    SPELL_GUARDIANS_BREATH_CAST_RBG         = 227667, // Red Blue Green
    SPELL_GUARDIANS_BREATH_CAST_GRB         = 227669, // Green Red Blue
    SPELL_GUARDIANS_BREATH_CAST_GBR         = 227660, // Green Blue Red
    SPELL_GUARDIANS_BREATH_CAST_BRG         = 227666, // Blue Red Green
    SPELL_GUARDIANS_BREATH_CAST_BGR         = 227658, // Blue Green Red
    SPELL_FIERY_PHLEGM                      = 232777, // Red
    SPELL_FIERY_PHLEGM_AURA                 = 228758,
    SPELL_SALTY_SPITTLE                     = 232798, // Green
    SPELL_SALTY_SPITTLE_AURA                = 228768,
    SPELL_DARK_DISCHARGE                    = 232800, // Blue
    SPELL_DARK_DISCHARGE_AURA               = 228769,
    SPELL_FROTHING_RAGE                     = 228174, // applied x times where x players not getting hit by breath

    SPELL_ROARING_LEAP_SELECTOR             = 227894, // @TODO: requires TARGET_DEST_CASTER_CLUMP_CENTROID
    SPELL_ROARING_LEAP_INITIAL_KNOCKBACK    = 227883,
    SPELL_ROARING_LEAP_JUMP                 = 229350, // triggers 227902
    SPELL_HEADLONG_CHARGE_INITIAL           = 227816,
    SPELL_HEADLONG_CHARGE_PERIODIC_DAMAGE   = 229480,
    SPELL_HEADLONG_CHARGE_DAMAGE            = 228344,
    SPELL_HEADLONG_CHARGE_AT                = 227833, // triggers 227843

    // Mythic
    SPELL_VOLATILE_FOAM_INITIAL             = 228824,
    SPELL_VOLATILE_FOAM_SELECTOR_RED        = 228684,
    SPELL_VOLATILE_FOAM_SELECTOR_GREEN      = 228809,
    SPELL_VOLATILE_FOAM_SELECTOR_BLUE       = 228817,
};

enum GuarmEvents
{
    EVENT_FLASHING_FANGS = 1,
    EVENT_CHECK_ENERGY,
    EVENT_LICK,
    EVENT_ROARING_LEAP,
    EVENT_HEADLONG_CHARGE,
    EVENT_OFF_THE_LEASH,
    EVENT_VOLATILE_FOAM,
    EVENT_BERSERK,
};

enum GuarmTalks
{
    TALK_GUARDIANS_BREATH_ANNOUNCE  = 0, // |TInterface\Icons\SPELL_FIRE_TWILIGHTFLAMEBREATH.BLP:20|t%s begins to cast |cFFFF0000|Hspell:227573|h[Guardian's Breath]|h|r!
    TALK_BERSERK                    = 1, // %s goes into a berserker rage!
};

enum GuarmPoints
{
    POINT_BERSERK_JUMP          = 0,

    POINT_HEADLONG_CHARGE       = 50,
    POINT_HEADLONG_CHARGE_MAX   = 53,
};

enum GuarmPaths
{
    PATH_HEADLONG_CHARGE1   = (114323 * 100) + 0,
    PATH_HEADLONG_CHARGE2   = (114323 * 100) + 1,
    PATH_HEADLONG_CHARGE3   = (114323 * 100) + 2,
    PATH_HEADLONG_CHARGE4   = (114323 * 100) + 3,
    PATH_BERSERK            = (114323 * 100) + 4,
};

enum GuarmSpellCategories
{
    SPELL_CATEGORY_GUARM = 1152,
};

enum GuarmConversations
{
    CONVERSATION_DEATH = 3917
};

enum GuarmActions
{
    ACTION_BREATH_HIT_TARGET = 0,
    ACTION_HANDLE_FROTHING_RAGE,
};

struct JumpMovePathPair
{
    Position JumpPos;
    uint32 PathID;
};

JumpMovePathPair const HeadlongChargePairs[] =
{
    { { 478.535f, 446.623f, 4.88632f }, PATH_HEADLONG_CHARGE1 },
    { { 460.708f, 445.918f, 4.91909f }, PATH_HEADLONG_CHARGE2 },
    { { 454.967f, 543.651f, 2.99177f }, PATH_HEADLONG_CHARGE3 },
    { { 475.189f, 543.391f, 3.25487f }, PATH_HEADLONG_CHARGE4 },
};

struct GuardiansBreathSpellPair
{
    uint32 SummonATSpellID;
    uint32 CastSpellID;
};

GuardiansBreathSpellPair const GuardiansBreathSpellPairs[] =
{
    { SPELL_GUARDIANS_BREATH_SUMMON_ATS_RGB, SPELL_GUARDIANS_BREATH_CAST_RGB },
    { SPELL_GUARDIANS_BREATH_SUMMON_ATS_RBG, SPELL_GUARDIANS_BREATH_CAST_RBG },
    { SPELL_GUARDIANS_BREATH_SUMMON_ATS_GRB, SPELL_GUARDIANS_BREATH_CAST_GRB },
    { SPELL_GUARDIANS_BREATH_SUMMON_ATS_GBR, SPELL_GUARDIANS_BREATH_CAST_GBR },
    { SPELL_GUARDIANS_BREATH_SUMMON_ATS_BRG, SPELL_GUARDIANS_BREATH_CAST_BRG },
    { SPELL_GUARDIANS_BREATH_SUMMON_ATS_BGR, SPELL_GUARDIANS_BREATH_CAST_BGR }
};

JumpMovePathPair const BerserkerPair = { { 464.035f, 549.979f, 2.95187f }, PATH_BERSERK };

// 114323 - Guarm
struct boss_guarm : public BossAI
{
    boss_guarm(Creature* creature) : BossAI(creature, DATA_GUARM), _lickCount(0), _unitsHitByBreathCount(0) { }

    void JustAppeared() override
    {
        DoCastAOE(SPELL_MULTI_HEADED_AURA);
        me->SetMaxPower(POWER_ENERGY, 100); // power is set to 0 in Creature::UpdateMaxPower
    }

    void JustDied(Unit* /*killer*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        Conversation::CreateConversation(CONVERSATION_DEATH, me, me->GetPosition(), ObjectGuid::Empty);

        _JustDied();
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        summons.DespawnAll();
        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

        DoCastAOE(SPELL_HELYATOSIS_AURA);
        DoCastAOE(SPELL_HELYATOSIS_INITIAL_ENERGIZE);

        events.ScheduleEvent(EVENT_FLASHING_FANGS, 6s);
        events.ScheduleEvent(EVENT_LICK, 12s);
        events.ScheduleEvent(EVENT_CHECK_ENERGY, 500ms);
        events.ScheduleEvent(EVENT_OFF_THE_LEASH, 45s);

        if (IsMythic())
        {
            events.ScheduleEvent(EVENT_VOLATILE_FOAM, 11s);
            events.ScheduleEvent(EVENT_BERSERK, 4min + 4s);
        }
        else if (IsHeroic())
            events.ScheduleEvent(EVENT_BERSERK, 5min);
        else if (GetDifficulty() == DIFFICULTY_NORMAL_RAID)
            events.ScheduleEvent(EVENT_BERSERK, 6min);
        else // LFR
            events.ScheduleEvent(EVENT_BERSERK, 7min);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        switch (events.ExecuteEvent())
        {
            case EVENT_FLASHING_FANGS:
                DoCastVictim(SPELL_FLASHING_FANGS);
                events.ScheduleEvent(EVENT_FLASHING_FANGS, 21s + 500ms);
                break;
            case EVENT_LICK:
                _lickCount++;
                DoCastAOE(RAND(SPELL_FLAME_LICK_SELECTOR, SPELL_SHADOW_LICK_SELECTOR, SPELL_FROST_LICK_SELECTOR));
                events.ScheduleEvent(EVENT_LICK, (_lickCount % 2) ? 4s : 10s);
                break;
            case EVENT_CHECK_ENERGY:
            {
                events.ScheduleEvent(EVENT_CHECK_ENERGY, 500ms);
                if (me->GetPower(POWER_ENERGY) < 100)
                    break;

                _unitsHitByBreathCount = 0;
                if (DoCastVictim(SPELL_GUARDIANS_BREATH_COLOR_SELECTOR) == SPELL_CAST_OK)
                    Talk(TALK_GUARDIANS_BREATH_ANNOUNCE);

                break;
            }
            case EVENT_ROARING_LEAP:
                DoCastAOE(SPELL_ROARING_LEAP_SELECTOR);
                break;
            case EVENT_HEADLONG_CHARGE:
                DoCastAOE(SPELL_HEADLONG_CHARGE_INITIAL);
                break;
            case EVENT_OFF_THE_LEASH:
                DoCastAOE(SPELL_OFF_THE_LEASH);
                events.ScheduleEvent(EVENT_OFF_THE_LEASH, 75s);
                events.ScheduleEvent(EVENT_ROARING_LEAP, 3s);
                events.ScheduleEvent(EVENT_HEADLONG_CHARGE, 13s);
                events.CancelEvent(EVENT_FLASHING_FANGS);
                events.CancelEvent(EVENT_LICK);
                events.CancelEvent(EVENT_VOLATILE_FOAM);
                break;
            case EVENT_VOLATILE_FOAM:
                DoCastAOE(SPELL_VOLATILE_FOAM_INITIAL);
                events.ScheduleEvent(EVENT_VOLATILE_FOAM, 22s);
                break;
            case EVENT_BERSERK:
                DoCastAOE(SPELL_BERSERK);
                Talk(TALK_BERSERK, me);
                events.CancelEvent(EVENT_FLASHING_FANGS);
                events.CancelEvent(EVENT_LICK);
                me->GetMotionMaster()->Clear(); // remove ChaseMovementGen
                me->SetReactState(REACT_PASSIVE);
                me->GetMotionMaster()->MoveJump(BerserkerPair.JumpPos, 42.0f, 21.5f, POINT_BERSERK_JUMP);
                break;
            default:
                break;
        }
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        me->SetReactState(REACT_AGGRESSIVE);
        events.ScheduleEvent(EVENT_FLASHING_FANGS, 16s);
        events.ScheduleEvent(EVENT_LICK, 18s);
        if (IsMythic())
            events.ScheduleEvent(EVENT_VOLATILE_FOAM, 20s);

        // Headlong Charge
        if (pathId != BerserkerPair.PathID)
        {
            me->RemoveAurasDueToSpell(SPELL_HEADLONG_CHARGE_PERIODIC_DAMAGE);
            me->RemoveAurasDueToSpell(SPELL_HEADLONG_CHARGE_AT);
            events.ScheduleEvent(EVENT_ROARING_LEAP, 5s);
        }
        else // Berserk
        {
            me->RemoveAurasDueToSpell(SPELL_BERSERK_CHARGE_AT);
        }
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type == EFFECT_MOTION_TYPE)
        {
            if (pointId >= POINT_HEADLONG_CHARGE && pointId <= POINT_HEADLONG_CHARGE_MAX)
            {
                uint32 headlongChargeId = pointId - POINT_HEADLONG_CHARGE;
                DoCastAOE(SPELL_HEADLONG_CHARGE_DAMAGE, true); // manually trigger first damage tick
                DoCastAOE(SPELL_HEADLONG_CHARGE_PERIODIC_DAMAGE, true);
                DoCastAOE(SPELL_HEADLONG_CHARGE_AT, true);

                me->GetMotionMaster()->MovePath(HeadlongChargePairs[headlongChargeId].PathID, false);
            }
            else if (pointId == POINT_BERSERK_JUMP)
            {
                DoCastAOE(SPELL_BERSERK_TRAMPLE_AOE);
                DoCastAOE(SPELL_BERSERK_CHARGE_AT);
                DoCastAOE(SPELL_ROARING_LEAP_INITIAL_KNOCKBACK, true);

                me->GetMotionMaster()->MovePath(BerserkerPair.PathID, false);
            }
        }
    }

    void DoAction(int32 param) override
    {
        switch (param)
        {
            case ACTION_BREATH_HIT_TARGET:
                _unitsHitByBreathCount++;
                break;
            case ACTION_HANDLE_FROTHING_RAGE:
            {
                uint32 engagedPlayers = 0;
                for (auto const& itr : me->GetThreatManager().GetUnsortedThreatList())
                {
                    if (itr->GetVictim()->IsPlayer())
                        engagedPlayers++;
                }

                uint32 frothingRageStacks = engagedPlayers - _unitsHitByBreathCount;
                if (frothingRageStacks > 0)
                {
                    if (Aura* aura = me->GetAura(SPELL_FROTHING_RAGE))
                        frothingRageStacks += aura->GetStackAmount();
                    me->SetAuraStack(SPELL_FROTHING_RAGE, me, frothingRageStacks);
                }
                break;
            }
            default:
                break;
        }
    }

private:
    uint8 _lickCount;
    uint8 _unitsHitByBreathCount;
};

// 227512 - Multi-Headed
class spell_multi_headed_proc_guarm : public AuraScript
{
    void HandleProc(ProcEventInfo& eventInfo)
    {
        GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_MULTI_HEADED_DAMAGE);
    }

    void Register() override
    {
        OnProc += AuraProcFn(spell_multi_headed_proc_guarm::HandleProc);
    }
};

// 227642 - Multi-Headed
class spell_multi_headed_damage_guarm : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.size() < 2)
            return;

        targets.sort(Trinity::ObjectDistanceOrderPred(GetExplTargetUnit()));
        targets.pop_front(); // skip expl target if multiple players are in range
        targets.resize(1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_multi_headed_damage_guarm::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
    }
};

// 228226 - Flame Lick
// 228250 - Shadow Lick
// 228246 - Frost Lick
class spell_lick_selector_guarm : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ (uint32)spellInfo->GetEffect(EFFECT_0).BasePoints }) && ValidateSpellEffect({ { spellInfo->Id, EFFECT_0 } });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectValue(), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_lick_selector_guarm::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 228187 - Guardian's Breath
class spell_guardians_breath_color_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_GUARDIANS_BREATH_SUMMON_ATS_RGB,
            SPELL_GUARDIANS_BREATH_SUMMON_ATS_RBG,
            SPELL_GUARDIANS_BREATH_SUMMON_ATS_GRB,
            SPELL_GUARDIANS_BREATH_SUMMON_ATS_GBR,
            SPELL_GUARDIANS_BREATH_SUMMON_ATS_BRG,
            SPELL_GUARDIANS_BREATH_SUMMON_ATS_BGR,
            SPELL_GUARDIANS_BREATH_UNK,
            SPELL_GUARDIANS_BREATH_CAST_RGB,
            SPELL_GUARDIANS_BREATH_CAST_RBG,
            SPELL_GUARDIANS_BREATH_CAST_GRB,
            SPELL_GUARDIANS_BREATH_CAST_GBR,
            SPELL_GUARDIANS_BREATH_CAST_BRG,
            SPELL_GUARDIANS_BREATH_CAST_BGR
        });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        GuardiansBreathSpellPair const& pair = GuardiansBreathSpellPairs[urand(0, 6)];
        caster->CastSpell(nullptr, pair.CastSpellID);
        caster->CastSpell(nullptr, pair.SummonATSpellID);
        caster->CastSpell(nullptr, SPELL_GUARDIANS_BREATH_UNK);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_guardians_breath_color_selector::HandleHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 227673 - Guardian's Breath
// 227667 - Guardian's Breath
// 227669 - Guardian's Breath
// 227660 - Guardian's Breath
// 227666 - Guardian's Breath
// 227658 - Guardian's Breath
class spell_guardians_breath : public SpellScript
{
    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster->IsAIEnabled())
            return;

        caster->GetAI()->DoAction(ACTION_HANDLE_FROTHING_RAGE);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_guardians_breath::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

/*
          Guarm
            v
    Color: R-- Spell: 232803 AreaTrigger: 13352
    Color: -R- Spell: 232773 AreaTrigger: 13352
    Color: --R Spell: 232804 AreaTrigger: 13352
    Color: G-- Spell: 232774 AreaTrigger: 13353
    Color: -G- Spell: 232805 AreaTrigger: 13353
    Color: --G Spell: 232806 AreaTrigger: 13353
    Color: B-- Spell: 232801 AreaTrigger: 13354
    Color: -B- Spell: 232802 AreaTrigger: 13354
    Color: --B Spell: 232776 AreaTrigger: 13354
*/

// 232803 - Guardian's Breath
// 232773 - Guardian's Breath
// 232804 - Guardian's Breath
// 232774 - Guardian's Breath
// 232805 - Guardian's Breath
// 232806 - Guardian's Breath
// 232801 - Guardian's Breath
// 232802 - Guardian's Breath
// 232776 - Guardian's Breath
template<uint32 ColorSpellId>
class at_guardians_breath : public AreaTriggerEntityScript
{
public:
    at_guardians_breath(char const* script) : AreaTriggerEntityScript(script) { }

    template<uint32 ColorSpell>
    struct at_guardians_breathAI : AreaTriggerAI
    {
        at_guardians_breathAI(AreaTrigger* at) : AreaTriggerAI(at) { }

        uint32 GetBreathDebuffByDamageSpell(uint32 breathDamageSpell) const
        {
            switch (breathDamageSpell)
            {
                case SPELL_FIERY_PHLEGM:
                    return SPELL_FIERY_PHLEGM_AURA;
                case SPELL_SALTY_SPITTLE:
                    return SPELL_SALTY_SPITTLE_AURA;
                case SPELL_DARK_DISCHARGE:
                    return SPELL_DARK_DISCHARGE_AURA;
            }
            return 0;
        }

        void OnRemove() override
        {
            InstanceScript* instance = at->GetInstanceScript();
            if (!instance)
                return;

            Creature* guarm = instance->GetCreature(DATA_GUARM);
            if (!guarm)
                return;

            if (!guarm->IsAIEnabled())
                return;

            for (ObjectGuid const& guid : at->GetInsideUnits())
            {
                Player* player = ObjectAccessor::GetPlayer(*at, guid);
                if (!player)
                    continue;

                if (player->isDead())
                    continue;

                guarm->GetAI()->DoAction(ACTION_BREATH_HIT_TARGET);
                guarm->CastSpell(player, ColorSpell, true);
                player->CastSpell(nullptr, GetBreathDebuffByDamageSpell(ColorSpell));
            }
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* at) const override
    {
        return new at_guardians_breathAI<ColorSpellId>(at);
    }
};

// 227720 - Mixed Elements
// 227721 - Mixed Elements
// 227735 - Mixed Elements
template<uint32 SpellId1, uint32 SpellId2>
class spell_mixed_elements : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SpellId1,
            SpellId2
        });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* target)
        {
            Player* unit = target->ToPlayer();
            if (!unit)
                return true;

            if (!unit->HasAura(SpellId1) || !unit->HasAura(SpellId2))
                return true;

            return false;
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mixed_elements::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// 227894 - Roaring Leap
class spell_roaring_leap_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ROARING_LEAP_INITIAL_KNOCKBACK, SPELL_ROARING_LEAP_JUMP });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        // @TODO: cast 232036 + implement (achievement)
        // @TODO: related to achievement aswell: 232393
        caster->CastSpell(nullptr, SPELL_ROARING_LEAP_INITIAL_KNOCKBACK, true);
        caster->CastSpell(*GetHitDest(), SPELL_ROARING_LEAP_JUMP);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_roaring_leap_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 227816 - Headlong Charge
class spell_headlong_charge_trigger : public SpellScript
{
    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Creature* caster = GetCaster()->ToCreature();
        if (!caster)
            return;

        uint8 pairId = urand(0, 3);
        caster->GetMotionMaster()->Clear(); // remove ChaseMovementGen
        caster->SetReactState(REACT_PASSIVE);
        caster->GetMotionMaster()->MoveJump(HeadlongChargePairs[pairId].JumpPos, 42.0f, 21.5f, POINT_HEADLONG_CHARGE + pairId);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_headlong_charge_trigger::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 228201 - Off the Leash
class spell_off_the_leash : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HELYATOSIS_AURA });
    }

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/ )
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_HELYATOSIS_AURA);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(nullptr, SPELL_HELYATOSIS_AURA);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_off_the_leash::HandleApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectApplyFn(spell_off_the_leash::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 228824 - Volatile Foam
class spell_volatile_foam_initial : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_VOLATILE_FOAM_SELECTOR_RED,
            SPELL_VOLATILE_FOAM_SELECTOR_GREEN,
            SPELL_VOLATILE_FOAM_SELECTOR_BLUE
        });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(nullptr, RAND(SPELL_VOLATILE_FOAM_SELECTOR_RED, SPELL_VOLATILE_FOAM_SELECTOR_GREEN, SPELL_VOLATILE_FOAM_SELECTOR_BLUE));
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_volatile_foam_initial::HandleHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 228684 - Volatile Foam // Red
// 228809 - Volatile Foam // Green
// 228817 - Volatile Foam // Blue
template<uint32 ExcludeSpellId>
class spell_volatile_foam_selector : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ (uint32)spellInfo->GetEffect(EFFECT_0).BasePoints });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* target)
        {
            Unit* unit = target->ToUnit();
            if (!unit)
                return true;

            if (unit->HasAura(ExcludeSpellId))
                return true;

            return false;
        });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectValue(), true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_volatile_foam_selector::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_volatile_foam_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 228794 - Flaming Volatile Foam   // after dispel
// 228811 - Briney Volatile Foam    // after dispel
// 228819 - Shadowy Volatile Foam   // after dispel
class spell_volatile_foam : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.sort(Trinity::ObjectDistanceOrderPred(GetExplTargetUnit()));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_volatile_foam::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_volatile_foam::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ALLY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_volatile_foam::FilterTargets, EFFECT_2, TARGET_UNIT_SRC_AREA_ALLY);
    }
};

// 228744 - Flaming Volatile Foam   // initial
// 228794 - Flaming Volatile Foam   // after dispel
// 228810 - Briney Volatile Foam    // initial
// 228811 - Briney Volatile Foam    // after dispel
// 228818 - Shadowy Volatile Foam   // initial
// 228819 - Shadowy Volatile Foam   // after dispel
template<uint32 SpellIdOnExpire>
class spell_volatile_foam_aura : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_0 } }) && ValidateSpellInfo(
        {
            (uint32)spellInfo->GetEffect(EFFECT_0).CalcValue(), // SpellIdOnDispel
            SpellIdOnExpire
        });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        AuraRemoveMode removeMode = GetTargetApplication()->GetRemoveMode();
        if (removeMode == AURA_REMOVE_BY_EXPIRE)
            target->CastSpell(target, SpellIdOnExpire);
        else if (removeMode == AURA_REMOVE_BY_ENEMY_SPELL)
            target->CastSpell(nullptr, GetSpellInfo()->GetEffect(EFFECT_0).CalcValue());
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_volatile_foam_aura::OnRemove, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_guarm()
{
    RegisterTrialOfValorCreatureAI(boss_guarm);
    RegisterSpellScript(spell_multi_headed_proc_guarm);
    RegisterSpellScript(spell_multi_headed_damage_guarm);
    RegisterSpellScript(spell_lick_selector_guarm);
    RegisterSpellScript(spell_guardians_breath_color_selector);
    RegisterSpellScript(spell_guardians_breath);
    new at_guardians_breath<SPELL_FIERY_PHLEGM>("at_guardians_breath_red");
    new at_guardians_breath<SPELL_SALTY_SPITTLE>("at_guardians_breath_green");
    new at_guardians_breath<SPELL_DARK_DISCHARGE>("at_guardians_breath_blue");
    RegisterSpellScriptWithArgs((spell_mixed_elements<SPELL_FIERY_PHLEGM_AURA, SPELL_SALTY_SPITTLE_AURA>), "spell_mixed_elements_red_green");
    RegisterSpellScriptWithArgs((spell_mixed_elements<SPELL_FIERY_PHLEGM_AURA, SPELL_DARK_DISCHARGE_AURA>), "spell_mixed_elements_red_blue");
    RegisterSpellScriptWithArgs((spell_mixed_elements<SPELL_SALTY_SPITTLE_AURA, SPELL_DARK_DISCHARGE_AURA>), "spell_mixed_elements_green_blue");
    RegisterSpellScript(spell_roaring_leap_selector);
    RegisterSpellScript(spell_headlong_charge_trigger);
    RegisterSpellScript(spell_off_the_leash);
    RegisterSpellScript(spell_volatile_foam_initial);
    RegisterSpellScriptWithArgs(spell_volatile_foam_selector<SPELL_FIERY_PHLEGM_AURA>, "spell_volatile_foam_selector_red");
    RegisterSpellScriptWithArgs(spell_volatile_foam_selector<SPELL_SALTY_SPITTLE_AURA>, "spell_volatile_foam_selector_green");
    RegisterSpellScriptWithArgs(spell_volatile_foam_selector<SPELL_DARK_DISCHARGE_AURA>, "spell_volatile_foam_selector_blue");
    RegisterSpellScriptWithArgs(spell_volatile_foam_aura<SPELL_FIERY_PHLEGM_AURA>, "spell_volatile_foam_aura_initial_red");
    RegisterSpellScriptWithArgs(spell_volatile_foam_aura<SPELL_SALTY_SPITTLE_AURA>, "spell_volatile_foam_aura_initial_green");
    RegisterSpellScriptWithArgs(spell_volatile_foam_aura<SPELL_DARK_DISCHARGE_AURA>, "spell_volatile_foam_aura_initial_blue");
    RegisterSpellAndAuraScriptPairWithArgs(spell_volatile_foam, spell_volatile_foam_aura<SPELL_FIERY_PHLEGM_AURA>, "spell_volatile_foam_aura_red");
    RegisterSpellAndAuraScriptPairWithArgs(spell_volatile_foam, spell_volatile_foam_aura<SPELL_SALTY_SPITTLE_AURA>, "spell_volatile_foam_aura_green");
    RegisterSpellAndAuraScriptPairWithArgs(spell_volatile_foam, spell_volatile_foam_aura<SPELL_DARK_DISCHARGE_AURA>, "spell_volatile_foam_aura_blue");
}
