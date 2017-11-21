/*
* Ordered alphabetically using scriptname.
*/

#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellMgr.h"
#include "SpellAuraEffects.h"

enum MasterySpells
{
    SPELL_MAGE_MASTERY_ICICLES               = 76613,
    SPELL_MAGE_ICICLE_DAMAGE                 = 148022,
    SPELL_MAGE_ICICLE_PERIODIC_TRIGGER       = 148023,
    SPELL_MAGE_ICICLE_AURA                   = 205473,
    SPELL_MAGE_GLACIAL_SPIKE                 = 199786,
    SPELL_MAGE_GLACIAL_SPIKE_PROC            = 199844,
    SPELL_MAGE_GLACIAL_SPIKE_DAMAGE          = 228600,
    SPELL_MAGE_GLACIAL_SPIKE_AMOUNT          = 214325,
    SPELL_MAGE_IGNITE                        = 12846,
    SPELL_MAGE_IGNITE_AURA                   = 12654,
};

const int IcicleAuras[5] = { 214124, 214125, 214126, 214127, 214130 };
const int IcicleHits[5] = { 148017, 148018, 148019, 148020, 148021 };

// Mastery: Icicles - 76613
class spell_mastery_icicles_proc : public SpellScriptLoader
{
public:
    spell_mastery_icicles_proc() : SpellScriptLoader("spell_mastery_icicles_proc") { }

    class spell_mastery_icicles_proc_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mastery_icicles_proc_AuraScript);

        void OnProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
        {
            SpellInfo const* spellInfo = eventInfo.GetDamageInfo()->GetSpellInfo();

            if (!spellInfo)
                return;

            if (spellInfo->Id != 116 && spellInfo->Id != 228597)
                return;

            Unit* target = eventInfo.GetDamageInfo()->GetVictim();
            Unit* caster = eventInfo.GetDamageInfo()->GetAttacker();

            if (!target || !caster)
                return;

            Player* player = caster->ToPlayer();

            if (!player)
                return;

            // Calculate damage
            int32 hitDamage = eventInfo.GetDamageInfo()->GetDamage() + eventInfo.GetDamageInfo()->GetAbsorb();

            // if hitDamage == 0 we have a miss, so we need to except this variant
            if (hitDamage != 0)
            {
                hitDamage *= (player->GetFloatValue(PLAYER_MASTERY) * 2.25f) / 100.0f;

                // Prevent huge hits on player after hitting low level creatures
                if (player->getLevel() > target->getLevel())
                    hitDamage = std::min(int32(hitDamage), int32(target->GetMaxHealth()));

                // We need to get the first free icicle slot
                int8 icicleFreeSlot = -1; // -1 means no free slot
                for (int8 l_I = 0; l_I < 5; ++l_I)
                {
                    if (!player->HasAura(IcicleAuras[l_I]))
                    {
                        icicleFreeSlot = l_I;
                        break;
                    }
                }

                switch (icicleFreeSlot)
                {
                    case -1:
                    {
                        // We need to find the icicle with the smallest duration.
                        int8 smallestIcicle = 0;
                        int32 minDuration = 0xFFFFFF;
                        for (int8 i = 0; i < 5; i++)
                        {
                            if (Aura* tmpCurrentAura = player->GetAura(IcicleAuras[i]))
                            {
                                if (minDuration > tmpCurrentAura->GetDuration())
                                {
                                    minDuration = tmpCurrentAura->GetDuration();
                                    smallestIcicle = i;
                                }
                            }
                        }

                        if (!caster->HasSpell(SPELL_MAGE_GLACIAL_SPIKE))
                        {
                            // Launch the icicle with the smallest duration
                            if (AuraEffect* currentIcicleAuraEffect = player->GetAuraEffect(IcicleAuras[smallestIcicle], EFFECT_0))
                            {
                                int32 basePoints = currentIcicleAuraEffect->GetAmount();
                                player->CastSpell(target, IcicleHits[smallestIcicle], true);
                                player->CastCustomSpell(target, SPELL_MAGE_ICICLE_DAMAGE, &basePoints, NULL, NULL, true);
                                player->RemoveAura(IcicleAuras[smallestIcicle]);
                            }
                        }

                        icicleFreeSlot = smallestIcicle;
                        // No break because we'll add the icicle in the next case
                    }
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    {
                        if (Aura* currentIcicleAura = player->AddAura(IcicleAuras[icicleFreeSlot], player))
                        {
                            if (AuraEffect* effect = currentIcicleAura->GetEffect(EFFECT_0))
                                effect->SetAmount(hitDamage);

                            player->AddAura(SPELL_MAGE_ICICLE_AURA, player);

                            if (caster->HasSpell(SPELL_MAGE_GLACIAL_SPIKE))
                            {
                                if (Aura* glacialSpikeProc = player->GetAura(SPELL_MAGE_ICICLE_AURA))
                                {
                                    if (glacialSpikeProc->GetStackAmount() == 5)
                                        player->CastSpell(player, SPELL_MAGE_GLACIAL_SPIKE_PROC, true);
                                }
                            }
                        }

                        break;
                    }
                }
            }
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_mastery_icicles_proc_AuraScript::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_mastery_icicles_proc_AuraScript();
    }
};

// Ice Lance - 30455
class spell_mastery_icicles_trigger : public SpellScriptLoader
{
public:
    spell_mastery_icicles_trigger() : SpellScriptLoader("spell_mastery_icicles_trigger") { }

    class spell_mastery_icicles_trigger_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mastery_icicles_trigger_SpellScript);

        void HandleAfterHit()
        {
            if (Unit* caster = GetCaster())
            {
                if (Unit* target = GetHitUnit())
                {
                    if (target->IsAlive() && !caster->HasSpell(SPELL_MAGE_GLACIAL_SPIKE))
                    {
                        caster->Variables.Set("IciclesTarget", target->GetGUID());
                        caster->CastSpell(caster, SPELL_MAGE_ICICLE_PERIODIC_TRIGGER, true);
                    }
                }
            }
        }

        void Register() override
        {
            AfterHit += SpellHitFn(spell_mastery_icicles_trigger_SpellScript::HandleAfterHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mastery_icicles_trigger_SpellScript();
    }
};

// Icicles (periodic) - 148023
class spell_mastery_icicles_periodic : public SpellScriptLoader
{
public:
    spell_mastery_icicles_periodic() : SpellScriptLoader("spell_mastery_icicles_periodic") { }

    class spell_mastery_icicles_periodic_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mastery_icicles_periodic_AuraScript);

        uint32 icicles[5];
        int32 icicleCount;

        void OnApply(AuraEffect const* /*l_AurEff*/, AuraEffectHandleModes /*l_Mode*/)
        {
            icicleCount = 0;
            if (Unit* caster = GetCaster())
            {
                for (uint32 l_I = 0; l_I < 5; ++l_I)
                {
                    if (caster->HasAura(IcicleAuras[l_I]))
                        icicles[icicleCount++] = IcicleAuras[l_I];
                }
            }
        }

        void OnTick(AuraEffect const* /*aurEff*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (AuraEffect* aura = caster->GetAuraEffect(GetSpellInfo()->Id, EFFECT_0))
                {
                    // Maybe not the good target selection ...
                    if (Unit* target = ObjectAccessor::GetUnit(*caster, caster->Variables.GetValue<ObjectGuid>("IciclesTarget")))
                    {
                        if (target->IsAlive())
                        {
                            int32 amount = aura->GetAmount();
                            if (Aura* currentIcicleAura = caster->GetAura(icicles[amount]))
                            {
                                int32 basePoints = currentIcicleAura->GetEffect(0)->GetAmount();

                                caster->CastSpell(target, IcicleHits[amount], true);
                                caster->CastCustomSpell(target, SPELL_MAGE_ICICLE_DAMAGE, &basePoints, NULL, NULL, true);
                                caster->RemoveAura(IcicleAuras[amount]);
                            }

                            if (caster->HasAura(SPELL_MAGE_ICICLE_AURA))
                                caster->RemoveAurasDueToSpell(SPELL_MAGE_ICICLE_AURA);

                            if (++amount >= icicleCount)
                                caster->RemoveAura(aura->GetBase());
                            else
                                aura->SetAmount(amount);
                        }
                        else
                            caster->RemoveAura(aura->GetBase());
                    }
                }
            }
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_mastery_icicles_periodic_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_mastery_icicles_periodic_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_mastery_icicles_periodic_AuraScript();
    }
};

// Glacial Spike - 199786
class spell_mastery_icicles_glacial_spike : public SpellScriptLoader
{
public:
    spell_mastery_icicles_glacial_spike() : SpellScriptLoader("spell_mastery_icicles_glacial_spike") {}

    class spell_mastery_icicles_glacial_spike_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mastery_icicles_glacial_spike_SpellScript);

        void HandleOnCast()
        {
            Player* player = GetCaster()->ToPlayer();

            if (!player)
                return;

            // Remove aura with visual icicle
            for (uint32 l_I = 0; l_I < 5; ++l_I)
            {
                if (player->HasAura(IcicleAuras[l_I]))
                    player->RemoveAura(IcicleAuras[l_I]);
            }
        }

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            // Need rewrite with extra amount of icicles
            caster->CastSpell(target, SPELL_MAGE_GLACIAL_SPIKE_DAMAGE, true);

            if (caster->HasAura(SPELL_MAGE_ICICLE_AURA))
                caster->RemoveAurasDueToSpell(SPELL_MAGE_ICICLE_AURA);

            if (caster->HasAura(SPELL_MAGE_GLACIAL_SPIKE_PROC))
                caster->RemoveAurasDueToSpell(SPELL_MAGE_GLACIAL_SPIKE_PROC);
        }

        void Register() override
        {
            OnCast += SpellCastFn(spell_mastery_icicles_glacial_spike_SpellScript::HandleOnCast);
            OnEffectHitTarget += SpellEffectFn(spell_mastery_icicles_glacial_spike_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mastery_icicles_glacial_spike_SpellScript();
    }
};

// 12846 - Mastery : Ignite
// Called by Fireball - 133, Inferno Blast - 108853, Scorch - 2948, Pyroblast - 11366, Meteor - 153564, Flamestrike - 2120
class spell_mastery_ignite : public SpellScriptLoader
{
public:
    spell_mastery_ignite() : SpellScriptLoader("spell_mastery_ignite") { }

    class spell_mastery_ignite_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mastery_ignite_SpellScript);

        void HandleAfterHit()
        {
            if (Unit* caster = GetCaster())
            {
                if (Unit* target = GetHitUnit())
                {
                    if (caster->GetTypeId() == TYPEID_PLAYER && caster->HasAura(SPELL_MAGE_IGNITE) && caster->getLevel() >= 78)
                    {
                        const SpellInfo* igniteAura = sSpellMgr->GetSpellInfo(SPELL_MAGE_IGNITE_AURA);
                        if (GetSpellInfo()->Id != SPELL_MAGE_IGNITE_AURA && igniteAura != nullptr)
                        {
                            float masteryValue = caster->GetFloatValue(PLAYER_MASTERY) * 0.75f;

                            int32 basePoints = GetHitDamage() /*+ GetAbsorbedDamage()*/;
                            if (basePoints)
                            {
                                basePoints = int32(CalculatePct(basePoints, masteryValue));

                                if (igniteAura->GetEffect(EFFECT_0)->Amplitude > 0)
                                    basePoints = basePoints / (igniteAura->GetMaxDuration() / igniteAura->GetEffect(EFFECT_0)->Amplitude);

                                if (Aura* previousIgnite = target->GetAura(SPELL_MAGE_IGNITE_AURA, caster->GetGUID()))
                                {
                                    if (AuraEffect* igniteEffect = previousIgnite->GetEffect(EFFECT_0))
                                    {
                                        if (uint32 amplitude = igniteEffect->GetPeriod())
                                            basePoints += (igniteEffect->GetAmount() * (previousIgnite->GetDuration() / amplitude)) / (previousIgnite->GetMaxDuration() / amplitude);
                                    }
                                }

                                caster->CastCustomSpell(target, SPELL_MAGE_IGNITE_AURA, &basePoints, NULL, NULL, true);
                            }
                        }
                    }
                }
            }
        }

        void Register() override
        {
            AfterHit += SpellHitFn(spell_mastery_ignite_SpellScript::HandleAfterHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mastery_ignite_SpellScript();
    }
};

void AddSC_mastery_spell_scripts()
{
    new spell_mastery_icicles_proc();
    new spell_mastery_icicles_trigger();
    new spell_mastery_icicles_periodic();
    new spell_mastery_icicles_glacial_spike();
    new spell_mastery_ignite();
}
