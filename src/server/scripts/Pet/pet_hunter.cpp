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
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "npc_pet_hun_".
 */

#include "ScriptMgr.h"
#include "CreatureAIImpl.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "TemporarySummon.h"

enum HunterSpells
{
    SPELL_HUNTER_CRIPPLING_POISON       = 30981, // Viper
    SPELL_HUNTER_DEADLY_POISON_PASSIVE  = 34657, // Venomous Snake
    SPELL_HUNTER_MIND_NUMBING_POISON    = 25810  // Viper
};

enum HunterCreatures
{
    NPC_HUNTER_VIPER                    = 19921
};

enum PetSpellsMisc
{
    SPELL_PET_GUARD_DOG_HAPPINESS   = 54445,
    SPELL_PET_SILVERBACK_RANK_1     = 62800,
    SPELL_PET_SILVERBACK_RANK_2     = 62801,

    SPELL_PET_SWOOP                 = 52825,
    SPELL_PET_CHARGE                = 61685,

    PET_ICON_ID_GROWL               = 201,
    PET_ICON_ID_CLAW                = 262,
    PET_ICON_ID_BITE                = 1680,
    PET_ICON_ID_SMACK               = 473
};

struct npc_pet_hunter_snake_trap : public ScriptedAI
{
    npc_pet_hunter_snake_trap(Creature* creature) : ScriptedAI(creature), _isViper(false), _spellTimer(0) { }

    void JustEngagedWith(Unit* /*who*/) override { }

    void JustAppeared() override
    {
        _isViper = me->GetEntry() == NPC_HUNTER_VIPER ? true : false;

        me->SetMaxHealth(uint32(107 * (me->GetLevel() - 40) * 0.025f));
        // Add delta to make them not all hit the same time
        me->SetAttackTime(BASE_ATTACK, me->GetAttackTime(BASE_ATTACK) + urandms(0,6));

        if (!_isViper && !me->HasAura(SPELL_HUNTER_DEADLY_POISON_PASSIVE))
            DoCast(me, SPELL_HUNTER_DEADLY_POISON_PASSIVE, true);
    }

    // Redefined for random target selection:
    void MoveInLineOfSight(Unit* /*who*/) override { }

    void UpdateAI(uint32 diff) override
    {
        if (me->GetVictim() && me->GetVictim()->HasBreakableByDamageCrowdControlAura())
        { // don't break cc
            me->GetThreatManager().ClearFixate();
            me->InterruptNonMeleeSpells(false);
            me->AttackStop();
            return;
        }

        if (me->IsSummon() && !me->GetThreatManager().GetFixateTarget())
        { // find new target
            Unit* summoner = me->ToTempSummon()->GetSummonerUnit();

            std::vector<Unit*> targets;

            auto addTargetIfValid = [this, &targets, summoner](CombatReference* ref) mutable
            {
                Unit* enemy = ref->GetOther(summoner);
                if (!enemy->HasBreakableByDamageCrowdControlAura() && me->CanCreatureAttack(enemy) && me->IsWithinDistInMap(enemy, me->GetAttackDistance(enemy)))
                    targets.push_back(enemy);
            };

            for (std::pair<ObjectGuid const, PvPCombatReference*> const& pair : summoner->GetCombatManager().GetPvPCombatRefs())
                addTargetIfValid(pair.second);

            if (targets.empty())
                for (std::pair<ObjectGuid const, CombatReference*> const& pair : summoner->GetCombatManager().GetPvECombatRefs())
                    addTargetIfValid(pair.second);

            for (Unit* target : targets)
                me->EngageWithTarget(target);

            if (!targets.empty())
            {
                Unit* target = Trinity::Containers::SelectRandomContainerElement(targets);
                me->GetThreatManager().FixateTarget(target);
            }
        }

        if (!UpdateVictim())
            return;

        // Viper
        if (_isViper)
        {
            if (_spellTimer <= diff)
            {
                if (!urand(0, 2)) // 33% chance to cast
                    DoCastVictim(RAND(SPELL_HUNTER_MIND_NUMBING_POISON, SPELL_HUNTER_CRIPPLING_POISON));

                _spellTimer = 3000;
            }
            else
                _spellTimer -= diff;
        }

        DoMeleeAttackIfReady();
    }

private:
    bool _isViper;
    uint32 _spellTimer;
};

// 57627 - Charge
class spell_pet_charge : public AuraScript
{
    PrepareAuraScript(spell_pet_charge);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_PET_SWOOP,
            SPELL_PET_CHARGE
        });
    }

    void HandleDummy(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        // Remove +% AP aura
        Unit* pet = eventInfo.GetActor();
        Aura* aura = pet->GetAura(SPELL_PET_SWOOP, pet->GetGUID());
        if (!aura)
            aura = pet->GetAura(SPELL_PET_CHARGE, pet->GetGUID());

        if (!aura)
            return;

        aura->DropCharge(AURA_REMOVE_BY_EXPIRE);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pet_charge::HandleDummy, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// -53178 - Guard Dog
class spell_pet_guard_dog : public AuraScript
{
    PrepareAuraScript(spell_pet_guard_dog);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PET_GUARD_DOG_HAPPINESS });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        // Growl shares family flags with other spells
        // filter by spellIcon instead
        SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
        if (!spellInfo || spellInfo->SpellIconID != PET_ICON_ID_GROWL)
            return false;

        return true;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        Unit* caster = eventInfo.GetActor();
        caster->CastSpell(nullptr, SPELL_PET_GUARD_DOG_HAPPINESS, aurEff);

        Unit* target = eventInfo.GetProcTarget();
        if (!target->CanHaveThreatList())
            return;
        float addThreat = CalculatePct(ASSERT_NOTNULL(eventInfo.GetSpellInfo())->GetEffect(EFFECT_0).CalcValue(caster), aurEff->GetAmount());
        target->GetThreatManager().AddThreat(caster, addThreat, GetSpellInfo(), false, true);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_pet_guard_dog::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_pet_guard_dog::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// -62764 - Silverback
class spell_pet_silverback : public AuraScript
{
    PrepareAuraScript(spell_pet_silverback);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PET_GUARD_DOG_HAPPINESS });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        // Growl shares family flags with other spells
        // filter by spellIcon instead
        SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
        if (!spellInfo || spellInfo->SpellIconID != PET_ICON_ID_GROWL)
            return false;

        return true;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        static uint32 const triggerSpell[2] = { SPELL_PET_SILVERBACK_RANK_1, SPELL_PET_SILVERBACK_RANK_2 };

        PreventDefaultAction();

        uint32 spellId = triggerSpell[GetSpellInfo()->GetRank() - 1];
        eventInfo.GetActor()->CastSpell(nullptr, spellId, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_pet_silverback::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_pet_silverback::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// -61680 - Culling the Herd
class spell_pet_culling_the_herd : public AuraScript
{
    PrepareAuraScript(spell_pet_culling_the_herd);

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        // Claw, Bite and Smack share FamilyFlags with other spells
        // filter by spellIcon instead
        SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
        if (!spellInfo)
            return false;

        switch (spellInfo->SpellIconID)
        {
            case PET_ICON_ID_CLAW:
            case PET_ICON_ID_BITE:
            case PET_ICON_ID_SMACK:
                break;
            default:
                return false;
        }

        return true;
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_pet_culling_the_herd::CheckProc);
    }
};

void AddSC_hunter_pet_scripts()
{
    RegisterCreatureAI(npc_pet_hunter_snake_trap);
    RegisterSpellScript(spell_pet_charge);
    RegisterSpellScript(spell_pet_guard_dog);
    RegisterSpellScript(spell_pet_silverback);
    RegisterSpellScript(spell_pet_culling_the_herd);
}
