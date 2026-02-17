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
 * Combat timers requires to be revisited
 * Everything related to split requires sniff verification, maybe something is missing or implemented wrongly
 * Solarian should have big aggro radius
 * Can transition start while in split phase? What should happen? Currently prevented
 * Boss does arcane melee damage, is this correct?
 */

#include "ScriptMgr.h"
#include "Containers.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "the_eye.h"

enum SolarianTexts
{
    SAY_AGGRO                           = 0,
    SAY_DEATH                           = 1,
    SAY_SLAY                            = 2,
    SAY_SUMMON                          = 3,
    SAY_VOID_1                          = 4,
    SAY_VOID_2                          = 5
};

enum SolarianSpells
{
    // Phase 1
    SPELL_ARCANE_MISSILES               = 33031,
    SPELL_BLINDING_LIGHT                = 33009,
    SPELL_WRATH_OF_THE_ASTROMANCER      = 42783,

    // Split
    SPELL_ASTROMANCER_SPLIT_LARGE_1     = 33189,
    SPELL_ASTROMANCER_SPLIT_LARGE_2     = 33281,
    SPELL_ASTROMANCER_SPLIT_LARGE_3     = 33282,
    SPELL_ASTROMANCER_SPLIT_LARGE_4     = 33347,
    SPELL_ASTROMANCER_SPLIT_LARGE_5     = 33348,
    SPELL_ASTROMANCER_SPLIT_LARGE_6     = 33349,
    SPELL_ASTROMANCER_SPLIT_LARGE_7     = 33350,
    SPELL_ASTROMANCER_SPLIT_LARGE_8     = 33351,
    SPELL_ASTROMANCER_SPLIT_SMALL_1     = 33352,
    SPELL_ASTROMANCER_SPLIT_SMALL_2     = 33353,
    SPELL_ASTROMANCER_SPLIT_SMALL_3     = 33354,
    SPELL_ASTROMANCER_SPLIT_SMALL_4     = 33355,

    SPELL_SUMMON_ASTROMANCER_ADDS       = 33362,
    SPELL_SUMMON_ASTROMANCER_SOLARIAN   = 33366,
    SPELL_SUMMON_ASTROMANCER_PRIEST     = 33367,

    // Phase 2
    SPELL_SOLARIAN_TRANSFORM            = 39117,
    SPELL_PSYCHIC_SCREAM                = 34322,
    SPELL_VOID_BOLT                     = 39329,

    // Solarium Priest
    SPELL_HOLY_SMITE                    = 25054,
    SPELL_GREAT_HEAL                    = 33387,
    SPELL_ARCANE_TORRENT                = 33390
};

enum SolarianEvents
{
    // Phase 1
    EVENT_ARCANE_MISSILES               = 1,
    EVENT_BLINDING_LIGHT,
    EVENT_WRATH_OF_THE_ASTROMANCER,

    // Split
    EVENT_SPLIT_1,
    EVENT_SPLIT_2,
    EVENT_SPLIT_3,
    EVENT_SPLIT_4,
    EVENT_SPLIT_5,
    EVENT_SPLIT_6,

    // Transition
    EVENT_TRANSITION_1,
    EVENT_TRANSITION_2,

    // Phase 2
    EVENT_PSYCHIC_SCREAM,
    EVENT_VOID_BOLT
};

enum SolarianMisc
{
    NPC_SPOTLIGHT                       = 18928,
    VOIDWALKER_ARMOR                    = 31000
};

static constexpr std::array<uint32, 4> SplitLargeRadiusSpells1 =
{
    SPELL_ASTROMANCER_SPLIT_LARGE_1,
    SPELL_ASTROMANCER_SPLIT_LARGE_2,
    SPELL_ASTROMANCER_SPLIT_LARGE_3,
    SPELL_ASTROMANCER_SPLIT_LARGE_4
};

static constexpr std::array<uint32, 4> SplitLargeRadiusSpells2 =
{
    SPELL_ASTROMANCER_SPLIT_LARGE_5,
    SPELL_ASTROMANCER_SPLIT_LARGE_6,
    SPELL_ASTROMANCER_SPLIT_LARGE_7,
    SPELL_ASTROMANCER_SPLIT_LARGE_8
};

static constexpr std::array<uint32, 4> SplitSmallRadiusSpells =
{
    SPELL_ASTROMANCER_SPLIT_SMALL_1,
    SPELL_ASTROMANCER_SPLIT_SMALL_2,
    SPELL_ASTROMANCER_SPLIT_SMALL_3,
    SPELL_ASTROMANCER_SPLIT_SMALL_4
};

static constexpr std::array<uint32, 3> SpotlightSummonSpells =
{
    SPELL_SUMMON_ASTROMANCER_SOLARIAN,
    SPELL_SUMMON_ASTROMANCER_PRIEST,
    SPELL_SUMMON_ASTROMANCER_PRIEST
};

// 18805 - High Astromancer Solarian
struct boss_high_astromancer_solarian : public BossAI
{
    boss_high_astromancer_solarian(Creature* creature) : BossAI(creature, DATA_SOLARIAN),
        _defaultArmor(creature->GetArmor()), _isSecondPhaseStarted(false), _isSplitInProgress(false) { }

    void Reset() override
    {
        _Reset();

        me->SetArmor(_defaultArmor);
        me->SetVisible(true);
        me->SetReactState(REACT_AGGRESSIVE);

        ///! HACK: Boss can throw main target in the air, this eventually causes health regen since boss
        /// can't reach target. For now we prevent health regeneration completely. Find a better solution
        me->SetRegenerateHealth(false);
        me->SetFullHealth();

        _spotlightsGuidVector.clear();
        _isSecondPhaseStarted = false;
        _isSplitInProgress = false;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        me->CallForHelp(120.0f);

        events.ScheduleEvent(EVENT_ARCANE_MISSILES, 0s);
        events.ScheduleEvent(EVENT_BLINDING_LIGHT, 30s);
        events.ScheduleEvent(EVENT_WRATH_OF_THE_ASTROMANCER, 20s, 30s);
        events.ScheduleEvent(EVENT_SPLIT_1, 50s);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_isSecondPhaseStarted && !_isSplitInProgress && me->HealthBelowPctDamaged(20, damage))
        {
            _isSecondPhaseStarted = true;
            events.ScheduleEvent(EVENT_TRANSITION_1, 0s);

            events.CancelEvent(EVENT_ARCANE_MISSILES);
            events.CancelEvent(EVENT_BLINDING_LIGHT);
            events.CancelEvent(EVENT_WRATH_OF_THE_ASTROMANCER);
            events.CancelEvent(EVENT_SPLIT_1);
        }
    }

    void JustSummoned(Creature* summon) override
    {
        // Do not engage summons
        summons.Summon(summon);

        if (summon->GetEntry() == NPC_SPOTLIGHT)
            _spotlightsGuidVector.push_back(summon->GetGUID());
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        _JustDied();

        me->RemoveAurasDueToSpell(SPELL_SOLARIAN_TRANSFORM);
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
                // Phase 1 (Looks like combat timers keep tick while in split phase, boss just doesn't cast spells)
                case EVENT_ARCANE_MISSILES:
                    if (me->GetReactState() != REACT_PASSIVE)
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                            DoCast(target, SPELL_ARCANE_MISSILES);
                    events.Repeat(3600ms);
                    break;
                case EVENT_BLINDING_LIGHT:
                    if (me->GetReactState() != REACT_PASSIVE)
                        DoCastSelf(SPELL_BLINDING_LIGHT);
                    events.Repeat(30s);
                    break;
                case EVENT_WRATH_OF_THE_ASTROMANCER:
                    if (me->GetReactState() != REACT_PASSIVE)
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
                            DoCast(target, SPELL_WRATH_OF_THE_ASTROMANCER);
                    events.Repeat(10s, 20s);
                    break;

                // Split
                case EVENT_SPLIT_1:
                    _isSplitInProgress = true;
                    me->SetReactState(REACT_PASSIVE);
                    me->NearTeleportTo(me->GetHomePosition());
                    events.ScheduleEvent(EVENT_SPLIT_2, 1s);
                    break;
                case EVENT_SPLIT_2:
                    _spotlightsGuidVector.clear();
                    DoCastSelf(Trinity::Containers::SelectRandomContainerElement(SplitSmallRadiusSpells));
                    DoCastSelf(Trinity::Containers::SelectRandomContainerElement(SplitLargeRadiusSpells1));
                    DoCastSelf(Trinity::Containers::SelectRandomContainerElement(SplitLargeRadiusSpells2));
                    events.ScheduleEvent(EVENT_SPLIT_3, 1s);
                    break;
                case EVENT_SPLIT_3:
                    Talk(SAY_SUMMON);
                    events.ScheduleEvent(EVENT_SPLIT_4, 1s);
                    break;
                case EVENT_SPLIT_4:
                    me->SetVisible(false);
                    events.ScheduleEvent(EVENT_SPLIT_5, 4s);
                    break;
                case EVENT_SPLIT_5:
                    for (ObjectGuid guid : _spotlightsGuidVector)
                        if (Creature* spotlight = ObjectAccessor::GetCreature(*me, guid))
                            spotlight->CastSpell(spotlight, SPELL_SUMMON_ASTROMANCER_ADDS);
                    events.ScheduleEvent(EVENT_SPLIT_6, 15s);
                    break;
                case EVENT_SPLIT_6:
                {
                    // We become visible here because otherwise spell below will not hit Solarian
                    me->SetVisible(true);

                    Trinity::Containers::RandomShuffle(_spotlightsGuidVector);

                    for (std::size_t i = 0; i < _spotlightsGuidVector.size() && i < SpotlightSummonSpells.size(); ++i)
                        if (Creature* spotlight = ObjectAccessor::GetCreature(*me, _spotlightsGuidVector[i]))
                            spotlight->CastSpell(spotlight, SpotlightSummonSpells[i]);

                    me->SetReactState(REACT_AGGRESSIVE);

                    _isSplitInProgress = false;

                    events.ScheduleEvent(EVENT_SPLIT_1, 70s);
                    break;
                }
                // Transition
                case EVENT_TRANSITION_1:
                    me->SetReactState(REACT_PASSIVE);
                    me->SetArmor(VOIDWALKER_ARMOR);
                    DoCastSelf(SPELL_SOLARIAN_TRANSFORM);
                    Talk(SAY_VOID_1);
                    events.ScheduleEvent(EVENT_TRANSITION_2, 2s);
                    break;
                case EVENT_TRANSITION_2:
                    me->SetReactState(REACT_AGGRESSIVE);
                    Talk(SAY_VOID_2);
                    events.ScheduleEvent(EVENT_PSYCHIC_SCREAM, 10s, 20s);
                    events.ScheduleEvent(EVENT_VOID_BOLT, 8s, 12s);
                    break;

                // Phase 2
                case EVENT_PSYCHIC_SCREAM:
                    DoCastSelf(SPELL_PSYCHIC_SCREAM);
                    events.Repeat(15s, 25s);
                    break;
                case EVENT_VOID_BOLT:
                    DoCastVictim(SPELL_VOID_BOLT);
                    events.Repeat(8s, 12s);
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
    uint32 _defaultArmor;
    bool _isSecondPhaseStarted;
    bool _isSplitInProgress;
    GuidVector _spotlightsGuidVector;
};

// 18806 - Solarium Priest
struct npc_solarium_priest : public ScriptedAI
{
    npc_solarium_priest(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void InitializeAI() override
    {
        me->SetCorpseDelay(1, true);
        ScriptedAI::InitializeAI();
    }

    void JustAppeared() override
    {
        DoZoneInCombat();

        if (Unit* target = SelectTarget(SelectTargetMethod::Random))
            AddThreat(target, 100000.0f);

        if (Creature* solarian = _instance->GetCreature(DATA_SOLARIAN))
            solarian->AI()->JustSummoned(me);
    }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void AttackStart(Unit* who) override
    {
        ScriptedAI::AttackStartCaster(who, 25.0f);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler
            .SetValidator([this]
            {
                return !me->HasUnitState(UNIT_STATE_CASTING);
            })
            .Schedule(0s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_HOLY_SMITE);
                task.Repeat(3s, 5s);
            })
            .Schedule(10s, 15s, [this](TaskContext task)
            {
                if (Unit* target = DoSelectLowestHpFriendly(100.0f))
                    DoCast(target, SPELL_GREAT_HEAL);
                task.Repeat(10s, 15s);
            })
            .Schedule(10s, 20s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_ARCANE_TORRENT);
                task.Repeat(10s, 20s);
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

// 18925 - Solarium Agent
struct npc_solarium_agent : public ScriptedAI
{
    npc_solarium_agent(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void InitializeAI() override
    {
        me->SetCorpseDelay(1, true);
        ScriptedAI::InitializeAI();
    }

    void JustAppeared() override
    {
        DoZoneInCombat();

        if (Unit* target = SelectTarget(SelectTargetMethod::Random))
            AddThreat(target, 100000.0f);

        if (Creature* solarian = _instance->GetCreature(DATA_SOLARIAN))
            solarian->AI()->JustSummoned(me);
    }

private:
    InstanceScript* _instance;
};

// 42783 - Wrath of the Astromancer
class spell_astromancer_wrath_of_the_astromancer : public AuraScript
{
    PrepareAuraScript(spell_astromancer_wrath_of_the_astromancer);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ uint32(spellInfo->GetEffect(EFFECT_1).CalcValue()) });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        GetTarget()->CastSpell(GetTarget(), uint32(GetEffectInfo(EFFECT_1).CalcValue()), true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_astromancer_wrath_of_the_astromancer::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_high_astromancer_solarian()
{
    RegisterTheEyeCreatureAI(boss_high_astromancer_solarian);
    RegisterTheEyeCreatureAI(npc_solarium_priest);
    RegisterTheEyeCreatureAI(npc_solarium_agent);
    RegisterSpellScript(spell_astromancer_wrath_of_the_astromancer);
}
