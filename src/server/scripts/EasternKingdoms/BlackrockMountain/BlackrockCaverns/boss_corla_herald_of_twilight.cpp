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
#include "blackrock_caverns.h"
#include "GameEventMgr.h"
#include "Map.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"

enum Texts
{
    // Corla
    SAY_AGGRO                   = 0,
    SAY_SLAY                    = 1,
    SAY_EVOLUTION_COMPLETE      = 2,
    YELL_DEATH                  = 3,
    SAY_ANNOUNCE_ZEALOT_EVOLVED = 4
};

enum Spells
{
    // Corla
    SPELL_EVOLUTION                             = 75610,
    SPELL_DRAIN_ESSENSE                         = 75645,
    SPELL_AURA_OF_ACCELERATION                  = 87376,
    SPELL_TWILIGHT_EVOLUTION                    = 75732,
    SPELL_WEAR_CHRISTMAS_HAT_RED_SELF_DND       = 61400,

    // Twilight Zealot
    SPELL_KNEELING_SUPPLICATION                 = 75608,
    SPELL_NETHER_BEAM_PERIODIC                  = 75706,
    SPELL_NETHER_BEAM_VISUAL                    = 75677,
    SPELL_EVOLUTION_STACKS_N                    = 75697,
    SPELL_EVOLUTION_STACKS_HC                   = 87378,

    SPELL_GRIEVOUS_WHIRL                        = 76524,
    SPELL_SHADOW_STRIKE                         = 82362,
    SPELL_INVISIBILITY_AND_STEALTH_DETECTION    = 18950,
    SPELL_FORCE_BLAST                           = 76522,
    SPELL_GRAVITY_STRIKE                        = 76561,

    // Invisible Stalker
    SPELL_NETHER_DRAGON_ESSENCE_VISUAL_1        = 75650,
    SPELL_NETHER_DRAGON_ESSENCE_VISUAL_2        = 75653,
    SPELL_NETHER_DRAGON_ESSENCE_VISUAL_3        = 75654
};

#define SPELL_DARK_COMMAND  RAID_MODE<uint32>(75823, 93462)

enum Events
{
    // Corla
    EVENT_DRAIN_ESSENSE = 1,
    EVENT_EVOLUTION,
    EVENT_DARK_COMMAND,

    // Twilight Zealot
    EVENT_GRIEVOUS_WHIRL,
    EVENT_SHADOW_STRIKE,
    EVENT_INVISIBILITY_AND_STEALTH_DETECTION,
    EVENT_GRAVITY_STRIKE,
    EVENT_FORCE_BLAST
};

enum Phases
{
    PHASE_OUT_OF_COMBAT = 1,
    PHASE_IN_COMBAT     = 2
};

enum Actions
{
    // Twilight Zealot
    ACTION_START_EVOLUTION = 0,
    ACTION_EVOLVE
};

enum Data
{
    DATA_ARRESTED_DEVELOPMENT = 0
};

enum Misc
{
    GAME_EVENT_WINTER_VEIL              = 2,
    SPELL_VISUAL_KIT_EVOLUTION_WARNING  = 16957
};

Position const TwilightZealotSummonPositions[] =
{
    { 585.0278f, 982.8993f, 155.4369f, 1.500983f },
    { 561.9618f, 983.0191f, 155.4369f, 1.553343f },
    { 573.4844f, 978.5851f, 155.4369f, 1.570796f } // Heroic only
};

struct boss_corla_herald_of_twilight : public BossAI
{
    boss_corla_herald_of_twilight(Creature* creature) : BossAI(creature, DATA_CORLA_HERALD_OF_TWILIGHT), _killedZealots(0) { }

    void JustAppeared() override
    {
        events.SetPhase(PHASE_OUT_OF_COMBAT);
        events.ScheduleEvent(EVENT_DRAIN_ESSENSE, 1ms, 0, PHASE_OUT_OF_COMBAT);

        for (uint8 i = 0; i < (IsHeroic() ? 3 : 2); i++)
            DoSummon(NPC_TWILIGHT_ZEALOT, TwilightZealotSummonPositions[i], 0, TEMPSUMMON_MANUAL_DESPAWN);

        if (sGameEventMgr->IsActiveEvent(GAME_EVENT_WINTER_VEIL))
            DoCastSelf(SPELL_WEAR_CHRISTMAS_HAT_RED_SELF_DND);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        Talk(SAY_AGGRO);
        me->CastStop();
        DoCastSelf(SPELL_AURA_OF_ACCELERATION);

        events.SetPhase(PHASE_IN_COMBAT);
        events.ScheduleEvent(EVENT_DARK_COMMAND, 24s, 0, PHASE_IN_COMBAT);

        for (ObjectGuid guid : summons)
            if (Creature* zealot = ObjectAccessor::GetCreature(*me, guid))
                if (zealot->IsAIEnabled)
                    zealot->AI()->DoAction(ACTION_START_EVOLUTION);
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();
        ClearAuras();
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(YELL_DEATH);
        ClearAuras();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void OnSpellCastFinished(SpellInfo const* spell, SpellFinishReason /*reason*/) override
    {
        if (spell->Id == SPELL_DARK_COMMAND)
            me->MakeInterruptable(false);
    }

    void SummonedCreatureDies(Creature* /*summon*/, Unit* /*killer*/) override
    {
        _killedZealots++;
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_ARRESTED_DEVELOPMENT)
            return _killedZealots == 3;

        return 0;
    }

    void UpdateAI(uint32 diff) override
    {
        bool isInCombat = !events.IsInPhase(PHASE_OUT_OF_COMBAT);

        if (!UpdateVictim() && isInCombat)
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING) && isInCombat)
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_DRAIN_ESSENSE:
                    DoCast(me, SPELL_DRAIN_ESSENSE);
                    events.Repeat(19s);
                    events.ScheduleEvent(EVENT_EVOLUTION, 17s, 0, PHASE_OUT_OF_COMBAT);
                    break;
                case EVENT_EVOLUTION:
                    me->CastStop();
                    DoCast(me, SPELL_EVOLUTION);
                    break;
                case EVENT_DARK_COMMAND:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
                    {
                        me->MakeInterruptable(true);
                        DoCast(target, SPELL_DARK_COMMAND);
                    }
                    events.Repeat(23s, 28s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
private:
    void ClearAuras()
    {
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DARK_COMMAND);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_EVOLUTION_STACKS_N);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_EVOLUTION_STACKS_HC);
    }

    uint8 _killedZealots;
};

struct npc_corla_twilight_zealot : public ScriptedAI
{
    npc_corla_twilight_zealot(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override { }

    void JustEngagedWith(Unit* /*who*/) override
    {
        if (InstanceScript* instance = me->GetInstanceScript())
            if (Creature* corla = instance->GetCreature(DATA_CORLA_HERALD_OF_TWILIGHT))
                if (!corla->IsInCombat())
                    corla->AI()->DoZoneInCombat();
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        DoCastSelf(SPELL_KNEELING_SUPPLICATION);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_START_EVOLUTION:
                DoCastSelf(SPELL_NETHER_BEAM_PERIODIC);
                break;
            case ACTION_EVOLVE:
                me->RemoveAllAuras();
                me->SetReactState(REACT_AGGRESSIVE);
                me->UpdateEntry(NPC_EVOLVED_TWILIGHT_ZEALOT);
                DoZoneInCombat();
                _events.ScheduleEvent(EVENT_GRIEVOUS_WHIRL, 1ms);
                _events.ScheduleEvent(EVENT_SHADOW_STRIKE, 50ms);
                _events.ScheduleEvent(EVENT_INVISIBILITY_AND_STEALTH_DETECTION, 2s);
                _events.ScheduleEvent(EVENT_FORCE_BLAST, 2s);
                _events.ScheduleEvent(EVENT_GRAVITY_STRIKE, 3s);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_GRIEVOUS_WHIRL:
                    DoCastAOE(SPELL_GRIEVOUS_WHIRL);
                    _events.Repeat(16s, 19s);
                    break;
                case EVENT_SHADOW_STRIKE:
                    DoCastVictim(SPELL_SHADOW_STRIKE);
                    _events.Repeat(14s, 17s);
                    break;
                case EVENT_INVISIBILITY_AND_STEALTH_DETECTION:
                    DoCastAOE(SPELL_INVISIBILITY_AND_STEALTH_DETECTION, true);
                    break;
                case EVENT_FORCE_BLAST:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true, true, 0))
                        DoCast(target, SPELL_FORCE_BLAST);
                    _events.Repeat(14s, 17s);
                    break;
                case EVENT_GRAVITY_STRIKE:
                    DoCastVictim(SPELL_GRAVITY_STRIKE);
                    _events.Repeat(10s, 11s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
private:
    EventMap _events;
};

class spell_corla_nether_dragon_essence : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_NETHER_DRAGON_ESSENCE_VISUAL_1,
                SPELL_NETHER_DRAGON_ESSENCE_VISUAL_2,
                SPELL_NETHER_DRAGON_ESSENCE_VISUAL_3
            });
    }

    void HandleTriggerSpell(AuraEffect const* /*aurEff*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, RAND(SPELL_NETHER_DRAGON_ESSENCE_VISUAL_1, SPELL_NETHER_DRAGON_ESSENCE_VISUAL_2, SPELL_NETHER_DRAGON_ESSENCE_VISUAL_3), true);
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_corla_nether_dragon_essence::HandleTriggerSpell, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_corla_nether_dragon_essence_visual : public SpellScript
{
    void ModDestHeight(SpellDestination& dest)
    {
        Position offset = { frand(-35.0f, 35.0f), frand(-25.0f, 25.0f), 0.0f, 0.0f };

        switch (GetSpellInfo()->Id)
        {
            case SPELL_NETHER_DRAGON_ESSENCE_VISUAL_1:
                offset.m_positionZ = 25.0f;
                break;
                case SPELL_NETHER_DRAGON_ESSENCE_VISUAL_2:
                offset.m_positionZ = 17.0f;
                break;
            case SPELL_NETHER_DRAGON_ESSENCE_VISUAL_3:
                offset.m_positionZ = 33.0f;
                break;
            default:
                break;
        }

        dest.RelocateOffset(offset);
    }

    void Register() override
    {
        OnDestinationTargetSelect.Register(&spell_corla_nether_dragon_essence_visual::ModDestHeight, EFFECT_0, TARGET_DEST_CASTER_RANDOM);
    }
};

class spell_corla_nether_beam : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_NETHER_BEAM_VISUAL,
                SPELL_EVOLUTION_STACKS_N,
                SPELL_EVOLUTION_STACKS_HC,
            });
    }

    bool Load() override
    {
        if (GetCaster()->GetMap()->IsHeroic())
            _evolutionSpellId = SPELL_EVOLUTION_STACKS_HC;

        return true;
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
        {
            if (Unit* caster = GetCaster())
            {
                caster->CastSpell(caster, SPELL_NETHER_BEAM_VISUAL, true);
                caster->CastSpell(caster, _evolutionSpellId, true);

                if (_evolutionSpellId == SPELL_EVOLUTION_STACKS_HC)
                    caster->CastSpell(caster, _evolutionSpellId, true);

                if (Aura const* aura = caster->GetAura(_evolutionSpellId))
                    if (aura->GetStackAmount() >= 75)
                        caster->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_EVOLUTION_WARNING, 0, 0);
            }
            return;
        }
        else if (targets.size() > 1)
        {
            if (Unit* caster = GetCaster())
            {
                targets.sort(Trinity::ObjectDistanceOrderPred(caster, true));
                targets.resize(1);
            }
        }
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        target->CastSpell(target, SPELL_NETHER_BEAM_VISUAL, true);
        target->CastSpell(target, _evolutionSpellId, true);

        if (_evolutionSpellId == SPELL_EVOLUTION_STACKS_HC)
            target->CastSpell(target, _evolutionSpellId, true);

        if (Aura const* aura = target->GetAura(_evolutionSpellId))
            if (aura->GetStackAmount() >= 75)
                target->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_EVOLUTION_WARNING, 0, 0);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_corla_nether_beam::FilterTargets, EFFECT_0, TARGET_UNIT_CONE_ENTRY);
        OnEffectHitTarget.Register(&spell_corla_nether_beam::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
private:
    uint32 _evolutionSpellId = SPELL_EVOLUTION_STACKS_N;
};

class spell_corla_evolution : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TWILIGHT_EVOLUTION });
    }

    void HandleEvolve()
    {
        Unit* target = GetHitUnit();
        if (!target)
            return;

        Aura* aura = target->GetAura(GetSpellInfo()->Id);
        if (!aura)
            return;

        if (aura->GetStackAmount() == GetSpellInfo()->StackAmount)
        {
            InstanceScript* instance = target->GetInstanceScript();
            if (!instance)
                return;

            if (Creature* corla = instance->GetCreature(DATA_CORLA_HERALD_OF_TWILIGHT))
            {
                corla->AI()->Talk(SAY_EVOLUTION_COMPLETE);
                if (Creature* creature = target->ToCreature())
                {
                    if (creature->IsAIEnabled)
                    {
                        corla->AI()->Talk(SAY_ANNOUNCE_ZEALOT_EVOLVED);
                        creature->AI()->DoAction(ACTION_EVOLVE);
                    }
                }
                else if (target->GetTypeId() == TYPEID_PLAYER)
                    corla->CastSpell(target, SPELL_TWILIGHT_EVOLUTION, true);
            }

            aura->Remove();
        }
    }

    void Register() override
    {
        AfterHit.Register(&spell_corla_evolution::HandleEvolve);
    }
};

class spell_corla_grievous_whirl : public AuraScript
{
    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        if (GetTarget()->GetHealth() == GetTarget()->GetMaxHealth())
            Remove();
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_corla_grievous_whirl::HandleProc, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

class achievement_arrested_development : public AchievementCriteriaScript
{
    public:
        achievement_arrested_development() : AchievementCriteriaScript("achievement_arrested_development") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (!target)
                return false;

            if (target->IsAIEnabled)
                return target->GetAI()->GetData(DATA_ARRESTED_DEVELOPMENT);

            return false;
        }
};


void AddSC_boss_corla()
{
    RegisterBlackrockCavernsCreatureAI(boss_corla_herald_of_twilight);
    RegisterBlackrockCavernsCreatureAI(npc_corla_twilight_zealot);
    RegisterSpellScript(spell_corla_nether_dragon_essence);
    RegisterSpellScript(spell_corla_nether_dragon_essence_visual);
    RegisterSpellScript(spell_corla_nether_beam);
    RegisterSpellScript(spell_corla_evolution);
    RegisterSpellScript(spell_corla_grievous_whirl);
    new achievement_arrested_development();
}
