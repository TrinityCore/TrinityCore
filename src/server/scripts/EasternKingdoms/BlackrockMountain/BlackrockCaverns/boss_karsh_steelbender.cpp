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
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellMgr.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "InstanceScript.h"
#include "Map.h"

enum Text
{
    // Karsh Steelbender
    SAY_AGGRO                                   = 0,
    SAY_SLAY                                    = 1,
    SAY_SUPERHEATED_QUICKSILVER_ARMOR           = 2,
    SAY_DEATH                                   = 3,
    SAY_ANNOUNCE_SUPERHEATED_QUICKSILVER_ARMOR  = 4
};

enum Spells
{
    // Karsh Steelbender
    SPELL_QUICKSILVER_ARMOR                         = 75854,
    SPELL_QUICKSILVER_ARMOR_DAMAGE_REDUCTION        = 75842,
    SPELL_SUPERHEATED_QUICKSILVER_ARMOR_PROC_AURA   = 76015,
    SPELL_SUPERHEATED_QUICKSILVER_ARMOR             = 75846,
    SPELL_HEAT_WAVE                                 = 75851,
    SPELL_CLEAVE                                    = 15284,
    SPELL_BOUND_FLAMES                              = 93499,
    SPELL_FORCECAST_LAVA_SPOUT                      = 88538,
    SPELL_TRANSFORM                                 = 93750
};

enum Events
{
    // Karsh Steelbender
    EVENT_CLEAVE = 1,
    EVENT_QUICKSILVER_ARMOR,
    EVENT_SUPERHEATED_QUICKSILVER_ARMOR
};

enum Actions
{
    // Karsh Steelbender
    ACTION_ANNOUNCE_SUPERHEATED_QUICKSILVER_ARMOR = 0
};

class AttackStartEvent : public BasicEvent
{
    public:
        AttackStartEvent(Creature* owner) :  _owner(owner) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _owner->SetReactState(REACT_AGGRESSIVE);
            if (_owner->IsAIEnabled)
                _owner->AI()->DoZoneInCombat();
            return true;
        }

    private:
        Creature* _owner;
};

Position const InvisibleStalkerLavaFountainPos = { 237.2951f, 784.7761f, 95.99241f };

struct boss_karsh_steelbender : public BossAI
{
    boss_karsh_steelbender(Creature* creature) : BossAI(creature, DATA_KARSH_STEELBENDER) { }

    void Reset() override
    {
        DoCastSelf(SPELL_QUICKSILVER_ARMOR);
        DoCastSelf(SPELL_QUICKSILVER_ARMOR_DAMAGE_REDUCTION);
        DoCastSelf(SPELL_SUPERHEATED_QUICKSILVER_ARMOR_PROC_AURA);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        Talk(SAY_AGGRO);
        events.ScheduleEvent(EVENT_CLEAVE, 10s, 12s);
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
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*victim*/) override
    {
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        Talk(SAY_DEATH);
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);
        if (summon->GetEntry() == NPC_BOUND_FLAMES)
        {
            summon->SetCorpseDelay(6);
            summon->m_Events.AddEvent(new AttackStartEvent(summon), summon->m_Events.CalculateTime(2000));
            summon->SetReactState(REACT_PASSIVE);
        }
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_ANNOUNCE_SUPERHEATED_QUICKSILVER_ARMOR)
        {
            Talk(SAY_SUPERHEATED_QUICKSILVER_ARMOR);
            Talk(SAY_ANNOUNCE_SUPERHEATED_QUICKSILVER_ARMOR);
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
                case EVENT_CLEAVE:
                    DoCastVictim(SPELL_CLEAVE);
                    events.Repeat(10s, 12s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

class spell_karsh_quicksilver_armor : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_SUPERHEATED_QUICKSILVER_ARMOR,
                SPELL_TRANSFORM
            });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        if (Creature* stalker = target->FindNearestCreature(NPC_INVISIBLE_STALKER, 5.0f - target->GetCombatReach(), true))
        {
            if (stalker->GetExactDist2d(InvisibleStalkerLavaFountainPos) < 1.0f)
            {
                target->RemoveAurasDueToSpell(SPELL_QUICKSILVER_ARMOR_DAMAGE_REDUCTION);
                target->CastSpell(target, SPELL_TRANSFORM, true);
                target->CastSpell(target, SPELL_SUPERHEATED_QUICKSILVER_ARMOR);
            }
        }
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_karsh_quicksilver_armor::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class spell_karsh_superheated_quicksilver_armor : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HEAT_WAVE });
    }

    void HandleHeatWave()
    {
        Unit* target = GetHitUnit();
        if (!target)
            return;

        if (Aura* superheatedArmor = target->GetAura(sSpellMgr->GetSpellIdForDifficulty(SPELL_SUPERHEATED_QUICKSILVER_ARMOR, target)))
        {
            SpellInfo const* spell = sSpellMgr->AssertSpellInfo(SPELL_HEAT_WAVE);
            uint8 stacks = superheatedArmor->GetStackAmount();
            int32 bp = spell->Effects[EFFECT_0].CalcValue() * stacks;
            target->CastSpell(target, SPELL_HEAT_WAVE, CastSpellExtraArgs(true).AddSpellBP0(bp));
        }
    }

    void Register() override
    {
        AfterHit.Register(&spell_karsh_superheated_quicksilver_armor::HandleHeatWave);
    }
};

class spell_karsh_superheated_quicksilver_armor_AuraScript : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_QUICKSILVER_ARMOR_DAMAGE_REDUCTION,
                SPELL_FORCECAST_LAVA_SPOUT,
                SPELL_BOUND_FLAMES,
                SPELL_TRANSFORM
            });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* creature = GetTarget()->ToCreature())
            if (creature->IsAIEnabled)
                creature->AI()->DoAction(ACTION_ANNOUNCE_SUPERHEATED_QUICKSILVER_ARMOR);
    }

    void AfterRemmove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->RemoveAurasDueToSpell(SPELL_TRANSFORM);
        target->CastSpell(target, SPELL_QUICKSILVER_ARMOR_DAMAGE_REDUCTION);
        target->CastSpell(target, SPELL_FORCECAST_LAVA_SPOUT, true);

        if (target->GetMap()->IsHeroic())
            target->CastSpell(target, SPELL_BOUND_FLAMES, true);
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_karsh_superheated_quicksilver_armor_AuraScript::AfterApply, EFFECT_1, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove.Register(&spell_karsh_superheated_quicksilver_armor_AuraScript::AfterRemmove, EFFECT_1, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_karsh_superheated_quicksilver_armor_proc : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUPERHEATED_QUICKSILVER_ARMOR });
    }

    bool CheckProc(ProcEventInfo& /*eventInfo*/)
    {
        return (GetTarget()->HasAura(sSpellMgr->GetSpellIdForDifficulty(SPELL_SUPERHEATED_QUICKSILVER_ARMOR, GetTarget())));
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        Unit* target = GetTarget();
        if (Aura* superheatedArmor = target->GetAura(sSpellMgr->GetSpellIdForDifficulty(SPELL_SUPERHEATED_QUICKSILVER_ARMOR, target)))
        {
            uint8 stacks = superheatedArmor->GetStackAmount();
            SpellInfo const* spell = sSpellMgr->GetSpellInfo(GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell);
            if (!spell)
                return;

            int32 bp = spell->Effects[EFFECT_0].CalcValue() * stacks;
            target->CastSpell(eventInfo.GetProcTarget(), spell->Id, CastSpellExtraArgs(aurEff).AddSpellBP0(bp));
        }
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_karsh_superheated_quicksilver_armor_proc::CheckProc);
        OnEffectProc.Register(&spell_karsh_superheated_quicksilver_armor_proc::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

class achievement_too_hot_to_handle : public AchievementCriteriaScript
{
    public:
        achievement_too_hot_to_handle() : AchievementCriteriaScript("achievement_too_hot_to_handle") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (!target)
                return false;

            if (uint32 spellId = sSpellMgr->GetSpellIdForDifficulty(SPELL_SUPERHEATED_QUICKSILVER_ARMOR, target))
                return (target->HasAura(spellId) && target->GetAura(spellId)->GetStackAmount() >= 15);

            return false;
        }
};

void AddSC_boss_karsh_steelbender()
{
    RegisterBlackrockCavernsCreatureAI(boss_karsh_steelbender);
    RegisterSpellScript(spell_karsh_quicksilver_armor);
    RegisterSpellAndAuraScriptPair(spell_karsh_superheated_quicksilver_armor, spell_karsh_superheated_quicksilver_armor_AuraScript);
    RegisterSpellScript(spell_karsh_superheated_quicksilver_armor_proc);
    new achievement_too_hot_to_handle();
}
