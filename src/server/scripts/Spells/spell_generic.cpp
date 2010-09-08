/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
 * Scripts for spells with SPELLFAMILY_GENERIC which cannot be included in AI script file
 * of creature using it or can't be bound to any player class.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_gen_"
 */

#include "ScriptPCH.h"

enum NPCEntries
{
    NPC_DOOMGUARD                                = 11859,
    NPC_INFERNAL                                 = 89,
    NPC_IMP                                      = 416,
};

class spell_gen_pet_summoned : public SpellScriptLoader
{
public:
    spell_gen_pet_summoned() : SpellScriptLoader("spell_gen_pet_summoned") { }

    class spell_gen_pet_summonedSpellScript : public SpellScript
    {
        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            Unit *caster = GetCaster();
            if (caster->GetTypeId() != TYPEID_PLAYER)
                return;

            Player* plr = caster->ToPlayer();
            if (plr && plr->GetLastPetNumber())
            {
                PetType NewPetType = (plr->getClass() == CLASS_HUNTER) ? HUNTER_PET : SUMMON_PET;
                if (Pet* NewPet = new Pet(plr, NewPetType))
                {
                    if (NewPet->LoadPetFromDB(plr, 0, plr->GetLastPetNumber(), true))
                    {
                        // revive the pet if it is dead
                        if (NewPet->getDeathState() == DEAD)
                            NewPet->setDeathState(ALIVE);

                        NewPet->SetFullHealth();
                        NewPet->SetPower(NewPet->getPowerType(),NewPet->GetMaxPower(NewPet->getPowerType()));

                        switch (NewPet->GetEntry())
                        {
                            case NPC_DOOMGUARD:
                            case NPC_INFERNAL:
                                NewPet->SetEntry(NPC_IMP);
                                break;
                            default:
                                break;
                        }
                    }
                    else
                        delete NewPet;
                }
            }
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_gen_pet_summonedSpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_gen_pet_summonedSpellScript();
    }
};

class spell_gen_remove_flight_auras : public SpellScriptLoader
{
public:
    spell_gen_remove_flight_auras() : SpellScriptLoader("spell_gen_remove_flight_auras") {}

    class spell_gen_remove_flight_auras_SpellScript : public SpellScript
    {
        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            Unit *target = GetHitUnit();
            if (!target)
                return;
            target->RemoveAurasByType(SPELL_AURA_FLY);
            target->RemoveAurasByType(SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED);
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_gen_remove_flight_auras_SpellScript::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_gen_remove_flight_auras_SpellScript();
    }
};

class spell_creature_permanent_feign_death : public SpellScriptLoader
{
    public:
        spell_creature_permanent_feign_death() : SpellScriptLoader("spell_creature_permanent_feign_death") { }

        class spell_creature_permanent_feign_deathAuraScript : public AuraScript
        {
            void HandleEffectApply(AuraEffect const * /*aurEff*/, AuraApplication const * aurApp, AuraEffectHandleModes /*mode*/)
            {
                Unit* pTarget = aurApp->GetTarget();
                if (!pTarget)
                    return;

                pTarget->SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_DEAD);
                pTarget->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH);
            }

            void Register()
            {
                OnEffectApply += AuraEffectApplyFn(spell_creature_permanent_feign_deathAuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

    AuraScript *GetAuraScript() const
    {
        return new spell_creature_permanent_feign_deathAuraScript();
    }
};

enum PvPTrinketTriggeredSpells
{
    SPELL_WILL_OF_THE_FORSAKEN_COOLDOWN_TRIGGER         = 72752,
    SPELL_WILL_OF_THE_FORSAKEN_COOLDOWN_TRIGGER_WOTF    = 72757,
};
class spell_pvp_trinket_wotf_shared_cd : public SpellScriptLoader
{
public:
    spell_pvp_trinket_wotf_shared_cd() : SpellScriptLoader("spell_pvp_trinket_wotf_shared_cd") {}

    class spell_pvp_trinket_wotf_shared_cd_SpellScript : public SpellScript
    {
        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            if (!sSpellStore.LookupEntry(SPELL_WILL_OF_THE_FORSAKEN_COOLDOWN_TRIGGER))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_WILL_OF_THE_FORSAKEN_COOLDOWN_TRIGGER_WOTF))
                return false;
            return true;
        }

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            Player* pCaster = GetCaster()->ToPlayer();
            if (!pCaster)
                return;
            const SpellEntry* m_spellInfo = GetSpellInfo();

            pCaster->AddSpellCooldown(m_spellInfo->Id, NULL, time(NULL) + GetSpellRecoveryTime(sSpellStore.LookupEntry(SPELL_WILL_OF_THE_FORSAKEN_COOLDOWN_TRIGGER)) / IN_MILLISECONDS);
            WorldPacket data(SMSG_SPELL_COOLDOWN, 8+1+4);
            data << uint64(pCaster->GetGUID());
            data << uint8(0);
            data << uint32(m_spellInfo->Id);
            data << uint32(0);
            pCaster->GetSession()->SendPacket(&data);
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_pvp_trinket_wotf_shared_cd_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_pvp_trinket_wotf_shared_cd_SpellScript();
    }
};

void AddSC_generic_spell_scripts()
{
    new spell_gen_pet_summoned();
    new spell_gen_remove_flight_auras();
    new spell_creature_permanent_feign_death();
    new spell_pvp_trinket_wotf_shared_cd();
}
