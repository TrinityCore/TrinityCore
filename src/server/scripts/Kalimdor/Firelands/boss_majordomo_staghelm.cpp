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

#include "firelands.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"

enum Spells
{
    // Majordomo Staghelm
    SPELL_ZERO_ENERGY_ZERO_REGEN    = 72242,
    SPELL_FORM_CONTROLLER           = 98386,
    SPELL_CONCENTRATION             = 98256,
    SPELL_CLUMP_CHECK               = 98399,
    SPELL_SCORPION_FORM             = 98379,
    SPELL_CAT_FORM                  = 98374,
    SPELL_FURY                      = 97235,
    SPELL_ADRENALINE                = 97238,
    SPELL_FLAME_SCYTHE              = 98474,
    SPELL_LEAPING_FLAMES_TARGETING  = 101165,
    SPELL_LEAPING_FLAMES_SUMMON     = 101222,
    SPELL_FIERY_CYCLONE             = 98443,
    SPELL_SEARING_SEEDS             = 98450,
    SPELL_BURNING_ORBS              = 98451,
    SPELL_BURNING_ORBS_SUMMON       = 98565,

    // Spirit of the Flame
    SPELL_STUN_AND_HATE             = 101224,

    // Player
    SPELL_SEARING_SEED              = 98620,
    SPELL_UNCOMMON_CONCENTRTATION   = 98254,
    SPELL_RARE_CONCENTRTATION       = 98253,
    SPELL_EPIC_CONCENTRTATION       = 98252,
    SPELL_LEGENDARY_CONCENTRATION   = 98245
};

enum Events
{
    // Majordomo Staghelm
    EVENT_ALLOW_COMBAT = 1,
    EVENT_FORM_ABILITY,
    EVENT_BALEROC_DIED_1,
    EVENT_BALEROC_DIED_2,
    EVENT_BALEROC_DIED_3
};

enum Actions
{
    ACTION_PLAYERS_CLUSTERED        = 0,
    ACTION_PLAYERS_SPLIT            = 1,
    ACTION_BALEROC_DIED             = 2,
    ACTION_DRUID_OF_THE_FLAME_DIED  = 3
};

enum Phases
{
    PHASE_INTRO     = 1,
    PHASE_COMBAT    = 2
};

enum Texts
{
    // Majordomo Staghelm
    SAY_INTRO                   = 0,
    SAY_SCORPION_FORM           = 1,
    SAY_ANNOUNCE_SCORPION_FORM  = 2,
    SAY_CAT_FORM                = 3,
    SAY_ANNOUNCE_CAT_FORM       = 4,
    SAY_SEARING_SEEDS           = 5,
    SAY_ANNOUNCE_SEARING_SEEDS  = 6,
    SAY_BURNING_ORBS            = 7,
    SAY_ANNOUNCE_BURNING_ORBS   = 8,
    SAY_SLAY                    = 9,
    SAY_DEATH                   = 10,
    SAY_BALEROC_DIED_1          = 11,
    SAY_BALEROC_DIED_2          = 12,
    SAY_BALEROC_DIED_3          = 13
};

enum Points
{
    // Majordomo Staghelm
    POINT_INTRO = 0
};

enum class Forms
{
    Druid       = 0,
    Cat         = 1,
    Scorpion    = 2
};

Position const MajordomoStaghelmMovePosition = { 523.4965f, -61.987846f, 83.94701f };

struct boss_majordomo_staghelm : public BossAI
{
    boss_majordomo_staghelm(Creature* creature) : BossAI(creature, DATA_MAJORDOMO_STAGHELM),
        _firstTransformation(true), _splitPlayersTicks(0), _clusteredPlayersTicks(0), _currentForm(Forms::Druid), _appliedSeeds(0), _formSwitchCount(0), _killedDruidsOfTheFlameCount(0) { }

    void InitializeAI() override
    {
        if (instance->GetBossState(DATA_MAJORDOMO_STAGHELM) == FAIL)
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
        me->SetPowerType(POWER_ENERGY);
        DoCastSelf(SPELL_ZERO_ENERGY_ZERO_REGEN);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        DoCastSelf(SPELL_ZERO_ENERGY_ZERO_REGEN);
        DoCastSelf(SPELL_FORM_CONTROLLER);
        if (IsHeroic())
            DoCastSelf(SPELL_CONCENTRATION);

        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        events.SetPhase(PHASE_COMBAT);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        BossAI::EnterEvadeMode(why);
        summons.DespawnAll();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->SetBossState(DATA_MAJORDOMO_STAGHELM, FAIL);
        me->DespawnOrUnsummon();
    }

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);
        me->RemoveAllDynObjects();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SEARING_SEEDS);
        Talk(SAY_DEATH);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->IsPlayer())
            Talk(SAY_SLAY, victim);
    }

    void MovementInform(uint32 motionType, uint32 pointId) override
    {
        if (motionType != POINT_MOTION_TYPE)
            return;

        if (pointId == POINT_INTRO)
            events.ScheduleEvent(EVENT_ALLOW_COMBAT, 1s);
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        switch (summon->GetEntry())
        {
            case NPC_SPIRIT_OF_THE_FLAME:
                summon->CastSpell(summon, SPELL_STUN_AND_HATE);
                summon->SetCorpseDelay(0);
                summon->m_Events.AddEventAtOffset([summon]()
                {
                    if (summon->IsAIEnabled)
                        summon->AI()->DoZoneInCombat();
                }, 1s);
                break;
            case NPC_BURNING_ORB:
                summon->SetCorpseDelay(0);
                break;
            default:
                break;
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_PLAYERS_CLUSTERED:
                ++_clusteredPlayersTicks;
                _splitPlayersTicks = 0;
                break;
            case ACTION_PLAYERS_SPLIT:
                ++_splitPlayersTicks;
                _clusteredPlayersTicks = 0;
                break;
            case ACTION_BALEROC_DIED:
                me->setActive(true);
                events.SetPhase(PHASE_INTRO);
                events.ScheduleEvent(EVENT_BALEROC_DIED_1, 10s);
                break;
            case ACTION_DRUID_OF_THE_FLAME_DIED:
                ++_killedDruidsOfTheFlameCount;
                if (_killedDruidsOfTheFlameCount >= (Is25ManRaid() ? 6 : 3))
                {
                    events.SetPhase(PHASE_INTRO);
                    Talk(SAY_INTRO);
                    me->GetMotionMaster()->MovePoint(POINT_INTRO, MajordomoStaghelmMovePosition, true, 5.f);
                }
                break;
            default:
                break;
        }

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (action != ACTION_PLAYERS_CLUSTERED && action != ACTION_PLAYERS_SPLIT)
            return;

        if ((_clusteredPlayersTicks >= 3 && _currentForm != Forms::Scorpion)
            || (_splitPlayersTicks >= 3 && _currentForm != Forms::Cat))
        {
            if (_formSwitchCount >= 2)
            {
                me->RemoveAurasDueToSpell(SPELL_SCORPION_FORM);
                me->RemoveAurasDueToSpell(SPELL_CAT_FORM);
                me->RemoveAurasDueToSpell(SPELL_ADRENALINE);
                DoCastAOE(SPELL_FIERY_CYCLONE);

                if (_currentForm == Forms::Cat)
                {
                    _appliedSeeds = 0;
                    DoCastAOE(SPELL_SEARING_SEEDS);
                    Talk(SAY_SEARING_SEEDS);
                    Talk(SAY_ANNOUNCE_SEARING_SEEDS);
                }
                else
                {
                    DoCastAOE(SPELL_BURNING_ORBS);
                    Talk(SAY_BURNING_ORBS);
                    Talk(SAY_ANNOUNCE_BURNING_ORBS);
                }

                _currentForm = Forms::Druid;
                _formSwitchCount = 0;
                return;
            }

            bool useScorpionForm = _clusteredPlayersTicks > _splitPlayersTicks;
            Talk(useScorpionForm ? SAY_SCORPION_FORM : SAY_CAT_FORM);
            Talk(useScorpionForm ? SAY_ANNOUNCE_SCORPION_FORM : SAY_ANNOUNCE_CAT_FORM);
            DoCastSelf(useScorpionForm ? SPELL_SCORPION_FORM : SPELL_CAT_FORM);

            if (!_firstTransformation)
                DoCastSelf(SPELL_FURY);
            else
                _firstTransformation = false;

            me->RemoveAurasDueToSpell(SPELL_ADRENALINE);
            events.RescheduleEvent(EVENT_FORM_ABILITY, 400ms, 0, PHASE_COMBAT);
            _currentForm = useScorpionForm ? Forms::Scorpion : Forms::Cat;
            ++_formSwitchCount;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && !events.IsInPhase(PHASE_INTRO))
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ALLOW_COMBAT:
                    DoCastSelf(SPELL_ZERO_ENERGY_ZERO_REGEN);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                    break;
                case EVENT_FORM_ABILITY:
                    if (me->GetPower(POWER_ENERGY) == me->GetMaxPower(POWER_ENERGY))
                    {
                        if (_currentForm == Forms::Scorpion)
                            DoCastVictim(SPELL_FLAME_SCYTHE);
                        else if (_currentForm == Forms::Cat)
                            DoCastAOE(SPELL_LEAPING_FLAMES_TARGETING, CastSpellExtraArgs().AddSpellMod(SPELLVALUE_MAX_TARGETS, 1));
                    }
                    events.Repeat(400ms);
                    break;
                case EVENT_BALEROC_DIED_1:
                    Talk(SAY_BALEROC_DIED_1);
                    events.ScheduleEvent(EVENT_BALEROC_DIED_2, 11s);
                    break;
                case EVENT_BALEROC_DIED_2:
                    Talk(SAY_BALEROC_DIED_2);
                    events.ScheduleEvent(EVENT_BALEROC_DIED_3, 11s);
                    break;
                case EVENT_BALEROC_DIED_3:
                    Talk(SAY_BALEROC_DIED_3);
                    if (!me->IsEngaged())
                        me->setActive(false);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    bool _firstTransformation;
    uint32 _splitPlayersTicks;
    uint32 _clusteredPlayersTicks;
    Forms _currentForm;
    uint8 _appliedSeeds;
    uint8 _formSwitchCount;
    uint8 _killedDruidsOfTheFlameCount;
};

class spell_majordomo_staghelm_form_controller : public AuraScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_CLUMP_CHECK });
    }

    void HandlePeriodicDummy(AuraEffect const* /*aurEff*/)
    {
        GetTarget()->CastSpell(nullptr, SPELL_CLUMP_CHECK, true);
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_majordomo_staghelm_form_controller::HandlePeriodicDummy, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class spell_majordomo_staghelm_clump_check : public SpellScript
{
    bool Load() override
    {
        _targetThreshold = GetCaster()->GetMap()->Is25ManRaid() ? 18 : 7;
        _radius = GetSpellInfo()->Effects[EFFECT_0].CalcRadius();
        return GetCaster()->IsCreature();
    }

    void CountClumpedTargets(std::list<WorldObject*>& targets)
    {
        bool hasClumpedPlayers = false;
        for (WorldObject const* target : targets)
        {
            std::vector<Player*> nearbyTargetsList;
            target->GetPlayerListInGrid(nearbyTargetsList, _radius);
            if (nearbyTargetsList.size() >= _targetThreshold)
            {
                hasClumpedPlayers = true;
                break;
            }
        }

        Creature* caster = GetCaster()->ToCreature();
        if (caster->IsAIEnabled)
            caster->AI()->DoAction(hasClumpedPlayers ? ACTION_PLAYERS_CLUSTERED : ACTION_PLAYERS_SPLIT);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_majordomo_staghelm_clump_check::CountClumpedTargets, EFFECT_0, TARGET_UNIT_AREA_ENEMY);
    }
private:
    uint8 _targetThreshold = 0;
    float _radius = 0.f;
};

class spell_majordomo_staghelm_leaping_flames_targeting : public SpellScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_LEAPING_FLAMES_SUMMON });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        std::list<WorldObject*> targetsCopy = targets;
        targets.remove_if([&](WorldObject const* target)
        {
            return target == GetCaster()->GetVictim();
        });

        // We only have the tank left fightning the caster so we use im
        if (targets.empty())
            targets = targetsCopy;
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
        {
            caster->CastSpell(nullptr, SPELL_LEAPING_FLAMES_SUMMON);
            caster->CastSpell(GetHitUnit(), GetEffectValue());
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_majordomo_staghelm_leaping_flames_targeting::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget.Register(&spell_majordomo_staghelm_leaping_flames_targeting::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_majordomo_staghelm_leaping_flames : public SpellScript
{
    void HandleJumpEffect(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            if (caster->IsAlive())
                caster->CastSpell(caster->GetPosition(), GetSpellInfo()->Effects[effIndex].TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectHit.Register(&spell_majordomo_staghelm_leaping_flames::HandleJumpEffect, EFFECT_0, SPELL_EFFECT_JUMP_DEST);
    }
};

class spell_majordomo_staghelm_searing_seeds : public SpellScript
{
    void CalculateDuration(std::list<WorldObject*>& targets)
    {
        uint32 baseValue = 10 * IN_MILLISECONDS;
        uint32 offsetValue = (GetCaster()->GetMap()->Is25ManRaid() ? 2 : 5) * IN_MILLISECONDS;
        uint8 targetCount = 0;

        for (WorldObject* target : targets)
        {
            ++targetCount;
            _durationForTarget[target->GetGUID()] = baseValue + offsetValue * targetCount;
        }
    }

    void HandleAuraDuration(SpellEffIndex /*effIndex*/)
    {
        if (Aura* aura = GetHitAura())
        {
            aura->SetMaxDuration(_durationForTarget[GetHitUnit()->GetGUID()]);
            aura->SetDuration(_durationForTarget[GetHitUnit()->GetGUID()]);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_majordomo_staghelm_searing_seeds::CalculateDuration, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget.Register(&spell_majordomo_staghelm_searing_seeds::HandleAuraDuration, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }

private:
    std::unordered_map<ObjectGuid, uint32> _durationForTarget;
};

class spell_majordomo_staghelm_searing_seeds_AuraScript : public AuraScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_SEARING_SEED });
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode().HasFlag(AuraRemoveFlags::Expired))
            GetTarget()->CastSpell(nullptr, SPELL_SEARING_SEED, true);
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_majordomo_staghelm_searing_seeds_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_majordomo_staghelm_concentration : public AuraScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_UNCOMMON_CONCENTRTATION,
                SPELL_RARE_CONCENTRTATION,
                SPELL_EPIC_CONCENTRTATION,
                SPELL_LEGENDARY_CONCENTRATION
            });
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        RemoveConcentration(GetTarget());
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        uint8 power = GetTarget()->GetPower(POWER_ALTERNATE_POWER);

        if (_oldPower != power)
        {
            uint32 oldConcentration = _currentConcentrationSpellId;
            if (power == 100)
                _currentConcentrationSpellId = SPELL_LEGENDARY_CONCENTRATION;
            else if (power >= 75)
                _currentConcentrationSpellId = SPELL_EPIC_CONCENTRTATION;
            else if (power >= 50)
                _currentConcentrationSpellId = SPELL_RARE_CONCENTRTATION;
            else if (power >= 25)
                _currentConcentrationSpellId = SPELL_UNCOMMON_CONCENTRTATION;

            if (oldConcentration != _currentConcentrationSpellId)
            {
                target->RemoveAurasDueToSpell(oldConcentration);
                target->CastSpell(target, _currentConcentrationSpellId, true);
            }

            _oldPower = power;
        }
    }

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        RemoveConcentration(GetTarget());
        GetTarget()->SetPower(POWER_ALTERNATE_POWER, 0);
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_majordomo_staghelm_concentration::HandleRemove, EFFECT_0, SPELL_AURA_ENABLE_ALT_POWER, AURA_EFFECT_HANDLE_REAL);
        OnEffectPeriodic.Register(&spell_majordomo_staghelm_concentration::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
        OnEffectProc.Register(&spell_majordomo_staghelm_concentration::HandleProc, EFFECT_0, SPELL_AURA_ENABLE_ALT_POWER);
    }
private:
    void RemoveConcentration(Unit* target)
    {
        target->RemoveAurasDueToSpell(SPELL_UNCOMMON_CONCENTRTATION);
        target->RemoveAurasDueToSpell(SPELL_RARE_CONCENTRTATION);
        target->RemoveAurasDueToSpell(SPELL_EPIC_CONCENTRTATION);
        target->RemoveAurasDueToSpell(SPELL_LEGENDARY_CONCENTRATION);
        _currentConcentrationSpellId = 0;
        _oldPower = 0;
    }

    uint8 _oldPower = 0;
    uint32 _currentConcentrationSpellId = 0;
};

class spell_majordomo_staghelm_burning_orbs : public SpellScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_BURNING_ORBS_SUMMON });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        for (uint8 i = 0; i < 5; ++i)
            caster->CastSpell(nullptr, SPELL_BURNING_ORBS_SUMMON);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_majordomo_staghelm_burning_orbs::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_boss_majordomo_staghelm()
{
    RegisterFirelandsCreatureAI(boss_majordomo_staghelm);
    RegisterSpellScript(spell_majordomo_staghelm_form_controller);
    RegisterSpellScript(spell_majordomo_staghelm_clump_check);
    RegisterSpellScript(spell_majordomo_staghelm_leaping_flames_targeting);
    RegisterSpellScript(spell_majordomo_staghelm_leaping_flames);
    RegisterSpellAndAuraScriptPair(spell_majordomo_staghelm_searing_seeds, spell_majordomo_staghelm_searing_seeds_AuraScript);
    RegisterSpellScript(spell_majordomo_staghelm_concentration);
    RegisterSpellScript(spell_majordomo_staghelm_burning_orbs);
}
