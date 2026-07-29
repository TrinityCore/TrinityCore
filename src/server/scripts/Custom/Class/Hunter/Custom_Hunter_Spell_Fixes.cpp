/*
 * This file is part of the Stefal WoW Project.
 * It is designed to work exclusively with the TrinityCore framework.
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
 * This code is provided for personal and educational use within the
 * Stefal WoW Project. It is not intended for commercial distribution,
 * resale, or any form of monetization.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "CreatureAI.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "Unit.h"
#include "Player.h"
#include "Pet.h"
#include "ObjectAccessor.h"

#include "Custom_Hunter_Defines.h"

namespace Scripts::Custom::Hunter
{
    // 883 - Call Pet 1
    // 83242 - Call Pet 2
    // 83243 - Call Pet 3
    // 83244 - Call Pet 4
    // 83245 - Call Pet 5
    class spell_hun_call_pet : public SpellScript
    {
        SpellCastResult CheckCast()
        {
            return SPELL_CAST_OK;
        }

        void HandleAfterCast() const
        {
            Unit* caster = GetCaster();
            Unit::AuraEffectList const& animalCompanion = caster->GetAuraEffectsByType(SPELL_AURA_ANIMAL_COMPANION);
            for (AuraEffect const* aurEff : animalCompanion)
            {
                if (uint32 triggerSpell = aurEff->GetSpellEffectInfo().TriggerSpell)
                {
                    if (sSpellMgr->GetSpellInfo(triggerSpell, DIFFICULTY_NONE))
                        caster->CastSpell(caster, triggerSpell, true);
                }
            }
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_hun_call_pet::CheckCast);
            AfterCast += SpellCastFn(spell_hun_call_pet::HandleAfterCast);
        }
    };

    // Kill Command - 34026
    class spell_hun_kill_command : public SpellScript
    {
        bool Validate(SpellInfo const* /*SpellEntry*/) override
        {
            if (!sSpellMgr->GetSpellInfo(Spells::KillCommand, DIFFICULTY_NONE))
                return false;
            return true;
        }

        SpellCastResult CheckCastMeet()
        {
            Unit* pet = GetCaster()->GetGuardianPet();
            Unit* petTarget = GetExplTargetUnit();

            if (!pet || pet->isDead())
                return SPELL_FAILED_NO_PET;

            // pet has a target and target is within 5 yards and target is in line of sight
            if (!petTarget || !pet->IsWithinDist(petTarget, 40.0f, true) || !petTarget->IsWithinLOSInMap(pet))
                return SPELL_FAILED_DONT_REPORT;

            if (pet->HasAuraType(SPELL_AURA_MOD_STUN) || pet->HasAuraType(SPELL_AURA_MOD_CONFUSE) || pet->HasAuraType(SPELL_AURA_MOD_SILENCE) ||
                pet->HasAuraType(SPELL_AURA_MOD_FEAR) || pet->HasAuraType(SPELL_AURA_MOD_FEAR_2))
                return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

            return SPELL_CAST_OK;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (Unit* pet = caster->GetGuardianPet())
            {
                if (!GetExplTargetUnit())
                    return;
                Unit* target = GetExplTargetUnit();

                pet->CastSpell(target, Spells::KillCommandTrigger, true);

                if (pet->GetVictim())
                {
                    pet->AttackStop();
                    pet->ToCreature()->AI()->AttackStart(target);
                }
                else
                    pet->ToCreature()->AI()->AttackStart(target);

                pet->CastSpell(target, Spells::KillCommandCharge, true);

                if (Player* player = caster->ToPlayer())
                {
                    ObjectGuid animalCompanionGuid = player->GetAnimalCompanion();
                    if (!animalCompanionGuid.IsEmpty() && animalCompanionGuid.IsPet())
                    {
                        if (Pet* animalCompanion = ObjectAccessor::GetPet(*player, animalCompanionGuid))
                        {
                            Unit* animalCompanionTarget = GetExplTargetUnit();
                            if (!animalCompanionTarget)
                                animalCompanionTarget = pet->GetVictim();

                            if (!animalCompanionTarget)
                                return;

                            animalCompanion->CastSpell(animalCompanionTarget, Spells::KillCommandTrigger, true);

                            if (animalCompanion->GetVictim())
                            {
                                animalCompanion->AttackStop();
                                animalCompanion->ToCreature()->AI()->AttackStart(animalCompanionTarget);
                            }
                            else
                                animalCompanion->ToCreature()->AI()->AttackStart(animalCompanionTarget);

                            animalCompanion->CastSpell(animalCompanionTarget, Spells::KillCommandCharge, true);
                        }
                    }
                }

                //191384 Aspect of the Beast
                if (caster->HasAura(Spells::AspectOfTheBeast))
                {
                    if (pet->HasAura(Spells::SpikedCollar))
                        caster->CastSpell(target, Spells::BestialFerocity, true);
                    if (pet->HasAura(Spells::GreatStamina))
                        pet->CastSpell(pet, Spells::BestialTenacity, true);
                    if (pet->HasAura(Spells::Cornered))
                        caster->CastSpell(target, Spells::BestialCunning, true);
                }
            }
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_hun_kill_command::CheckCastMeet);
            OnEffectHit += SpellEffectFn(spell_hun_kill_command::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
        }
    };

    // Kill Command (Damage) - 83381
    class spell_hun_kill_command_proc : public SpellScript
    {
        void HandleDamage(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* owner = caster->GetOwner();
            Unit* target = GetExplTargetUnit();

            if (!caster || !target)
                return;

            // If no owner (e.g. bot pet with no owner reference), use caster's own stats
            Unit* statSource = owner ? owner : caster;

            // (1.5 * (rap * 3) * bmMastery * lowNerf * (1 + versability))
            int32 dmg = 4.5f * statSource->m_unitData->RangedAttackPower;
            int32 lowNerf = std::min(int32(statSource->GetLevel()), 20) * 0.05f;

            if (Player const* ownerPlayer = statSource->ToPlayer())
                dmg = AddPct(dmg, ownerPlayer->m_activePlayerData->Mastery);

            dmg *= lowNerf;

            dmg = caster->SpellDamageBonusDone(target, GetSpellInfo(), dmg, SPELL_DIRECT_DAMAGE, GetEffectInfo(EFFECT_0));
            dmg = target->SpellDamageBonusTaken(caster, GetSpellInfo(), dmg, SPELL_DIRECT_DAMAGE);

            SetHitDamage(dmg);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_hun_kill_command_proc::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };
}

void AddSC_custom_hunter_spell_fixes()
{
    using namespace Scripts::Custom::Hunter;

    RegisterSpellScript(spell_hun_call_pet);
    RegisterSpellScript(spell_hun_kill_command);
    RegisterSpellScript(spell_hun_kill_command_proc);
}
