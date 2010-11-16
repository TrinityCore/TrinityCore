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
#include "SpellAuraEffects.h"

// 41337 Aura of Anger
class spell_gen_aura_of_anger : public SpellScriptLoader
{
public:
    spell_gen_aura_of_anger() : SpellScriptLoader("spell_gen_aura_of_anger") { }

    class spell_gen_aura_of_anger_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_gen_aura_of_anger_AuraScript)
        void HandleEffectPeriodicUpdate(AuraEffect * aurEff)
        {
            if (AuraEffect * aurEff1 = aurEff->GetBase()->GetEffect(EFFECT_1))
                aurEff1->ChangeAmount(aurEff1->GetAmount() + 5);
            aurEff->SetAmount(100 * aurEff->GetTickNumber());
        }

        void Register()
        {
            OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_gen_aura_of_anger_AuraScript::HandleEffectPeriodicUpdate, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        }
    };

    AuraScript *GetAuraScript() const
    {
        return new spell_gen_aura_of_anger_AuraScript();
    }
};

// 46394 Brutallus Burn
class spell_gen_burn_brutallus : public SpellScriptLoader
{
public:
    spell_gen_burn_brutallus() : SpellScriptLoader("spell_gen_burn_brutallus") { }

    class spell_gen_burn_brutallus_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_gen_burn_brutallus_AuraScript)
        void HandleEffectPeriodicUpdate(AuraEffect * aurEff)
        {
            if (aurEff->GetTickNumber() % 11 == 0)
                aurEff->SetAmount(aurEff->GetAmount() * 2);
        }

        void Register()
        {
            OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_gen_burn_brutallus_AuraScript::HandleEffectPeriodicUpdate, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        }
    };

    AuraScript *GetAuraScript() const
    {
        return new spell_gen_burn_brutallus_AuraScript();
    }
};

// 45472 Parachute
enum eParachuteSpells
{
    SPELL_PARACHUTE         = 45472,
    SPELL_PARACHUTE_BUFF    = 44795,
};

class spell_gen_parachute : public SpellScriptLoader
{
public:
    spell_gen_parachute() : SpellScriptLoader("spell_gen_parachute") { }

    class spell_gen_parachute_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_gen_parachute_AuraScript)
        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            if (!sSpellStore.LookupEntry(SPELL_PARACHUTE))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_PARACHUTE_BUFF))
                return false;
            return true;
        }

        void HandleEffectPeriodic(AuraEffect const * /*aurEff*/, AuraApplication const * aurApp)
        {
            if (Unit* pTarget = aurApp->GetTarget())
                if (Player* pPlayerTarget = pTarget->ToPlayer())
                    if (pPlayerTarget->IsFalling())
                    {
                        pPlayerTarget->RemoveAurasDueToSpell(SPELL_PARACHUTE);
                        pPlayerTarget->CastSpell(pPlayerTarget, SPELL_PARACHUTE_BUFF, true);
                    }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_gen_parachute_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript *GetAuraScript() const
    {
        return new spell_gen_parachute_AuraScript();
    }
};

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
        PrepareSpellScript(spell_gen_pet_summonedSpellScript)
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
        PrepareSpellScript(spell_gen_remove_flight_auras_SpellScript)
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

// 66118 Leeching Swarm
enum eLeechingSwarmSpells
{
    SPELL_LEECHING_SWARM_DMG    = 66240,
    SPELL_LEECHING_SWARM_HEAL   = 66125,
};

class spell_gen_leeching_swarm : public SpellScriptLoader
{
public:
    spell_gen_leeching_swarm() : SpellScriptLoader("spell_gen_leeching_swarm") { }

    class spell_gen_leeching_swarm_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_gen_leeching_swarm_AuraScript)
        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            if (!sSpellStore.LookupEntry(SPELL_LEECHING_SWARM_DMG))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_LEECHING_SWARM_HEAL))
                return false;
            return true;
        }

        void HandleEffectPeriodic(AuraEffect const * aurEff, AuraApplication const * aurApp)
        {
            if (Unit* pTarget = aurApp->GetTarget())
                if (Unit* pCaster = GetCaster())
                {
                    int32 lifeLeeched = pTarget->CountPctFromMaxHealth(aurEff->GetAmount());
                    if (lifeLeeched < 250)
                        lifeLeeched = 250;
                    // Damage
                    pCaster->CastCustomSpell(pTarget, SPELL_LEECHING_SWARM_DMG, &lifeLeeched, 0, 0, false);
                    // Heal
                    pCaster->CastCustomSpell(pCaster, SPELL_LEECHING_SWARM_HEAL, &lifeLeeched, 0, 0, false);
                }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_gen_leeching_swarm_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript *GetAuraScript() const
    {
        return new spell_gen_leeching_swarm_AuraScript();
    }
};

// 24750 Trick
enum eTrickSpells
{
    SPELL_PIRATE_COSTUME_MALE           = 24708,
    SPELL_PIRATE_COSTUME_FEMALE         = 24709,
    SPELL_NINJA_COSTUME_MALE            = 24710,
    SPELL_NINJA_COSTUME_FEMALE          = 24711,
    SPELL_LEPER_GNOME_COSTUME_MALE      = 24712,
    SPELL_LEPER_GNOME_COSTUME_FEMALE    = 24713,
    SPELL_SKELETON_COSTUME              = 24723,
    SPELL_GHOST_COSTUME_MALE            = 24735,
    SPELL_GHOST_COSTUME_FEMALE          = 24736,
    SPELL_TRICK_BUFF                    = 24753,
};

class spell_gen_trick : public SpellScriptLoader
{
public:
    spell_gen_trick() : SpellScriptLoader("spell_gen_trick") {}

    class spell_gen_trick_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_gen_trick_SpellScript)
        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            if (!sSpellStore.LookupEntry(SPELL_PIRATE_COSTUME_MALE))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_PIRATE_COSTUME_FEMALE))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_NINJA_COSTUME_MALE))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_NINJA_COSTUME_FEMALE))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_LEPER_GNOME_COSTUME_MALE))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_LEPER_GNOME_COSTUME_FEMALE))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_SKELETON_COSTUME))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_GHOST_COSTUME_MALE))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_GHOST_COSTUME_FEMALE))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_TRICK_BUFF))
                return false;
            return true;
        }

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            if (Player* pTarget = GetHitPlayer())
            {
                uint8 gender = pTarget->getGender();
                uint32 spellId = SPELL_TRICK_BUFF;
                switch (urand(0, 5))
                {
                    case 1: spellId = gender ? SPELL_LEPER_GNOME_COSTUME_FEMALE : SPELL_LEPER_GNOME_COSTUME_MALE; break;
                    case 2: spellId = gender ? SPELL_PIRATE_COSTUME_FEMALE : SPELL_PIRATE_COSTUME_MALE; break;
                    case 3: spellId = gender ? SPELL_GHOST_COSTUME_FEMALE : SPELL_GHOST_COSTUME_MALE; break;
                    case 4: spellId = gender ? SPELL_NINJA_COSTUME_FEMALE : SPELL_NINJA_COSTUME_MALE; break;
                    case 5: spellId = SPELL_SKELETON_COSTUME; break;
                }
                GetCaster()->CastSpell(pTarget, spellId, true, NULL);
            }
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_gen_trick_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_gen_trick_SpellScript();
    }
};

// 24751 Trick or Treat
enum eTrickOrTreatSpells
{
    SPELL_TRICK                 = 24714,
    SPELL_TREAT                 = 24715,
    SPELL_TRICKED_OR_TREATED    = 24755
};

class spell_gen_trick_or_treat : public SpellScriptLoader
{
public:
    spell_gen_trick_or_treat() : SpellScriptLoader("spell_gen_trick_or_treat") {}

    class spell_gen_trick_or_treat_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_gen_trick_or_treat_SpellScript)
        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            if (!sSpellStore.LookupEntry(SPELL_TRICK))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_TREAT))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_TRICKED_OR_TREATED))
                return false;
            return true;
        }

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            if (Player* pTarget = GetHitPlayer())
            {
                GetCaster()->CastSpell(pTarget, roll_chance_i(50) ? SPELL_TRICK : SPELL_TREAT, true, NULL);
                GetCaster()->CastSpell(pTarget, SPELL_TRICKED_OR_TREATED, true, NULL);
            }
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_gen_trick_or_treat_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_gen_trick_or_treat_SpellScript();
    }
};

class spell_creature_permanent_feign_death : public SpellScriptLoader
{
    public:
        spell_creature_permanent_feign_death() : SpellScriptLoader("spell_creature_permanent_feign_death") { }

        class spell_creature_permanent_feign_deathAuraScript : public AuraScript
        {
            PrepareAuraScript(spell_creature_permanent_feign_deathAuraScript)
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
        PrepareSpellScript(spell_pvp_trinket_wotf_shared_cd_SpellScript)
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

enum AnimalBloodPoolSpell
{
    SPELL_SPAWN_BLOOD_POOL  = 63471,
};

class spell_gen_animal_blood : public SpellScriptLoader
{
    public:
        spell_gen_animal_blood() : SpellScriptLoader("spell_gen_animal_blood") { }

        class spell_gen_animal_blood_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_gen_animal_blood_AuraScript);

            bool Validate(SpellEntry const* /*spell*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_SPAWN_BLOOD_POOL))
                    return false;
                return true;
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraApplication const* /*aurApp*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetUnitOwner()->IsInWater())
                    GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_SPAWN_BLOOD_POOL, true);
            }

            void Register()
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_gen_animal_blood_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_gen_animal_blood_AuraScript();
        }
};

class spell_gen_shroud_of_death : public SpellScriptLoader
{
    public:
        spell_gen_shroud_of_death() : SpellScriptLoader("spell_gen_shroud_of_death") { }

        class spell_gen_shroud_of_deathAuraScript : public AuraScript
        {
            PrepareAuraScript(spell_gen_shroud_of_deathAuraScript)

            void HandleEffectApply(AuraEffect const * /*aurEff*/, AuraApplication const * aurApp, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* target = aurApp->GetTarget())
                {
                    target->m_serverSideVisibility.SetValue(SERVERSIDE_VISIBILITY_GHOST, GHOST_VISIBILITY_GHOST);
                    target->m_serverSideVisibilityDetect.SetValue(SERVERSIDE_VISIBILITY_GHOST, GHOST_VISIBILITY_GHOST);
                }
            }

            void HandleEffectRemove(AuraEffect const * /*aurEff*/, AuraApplication const * aurApp, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* target = aurApp->GetTarget())
                {
                    target->m_serverSideVisibility.SetValue(SERVERSIDE_VISIBILITY_GHOST, GHOST_VISIBILITY_ALIVE);
                    target->m_serverSideVisibilityDetect.SetValue(SERVERSIDE_VISIBILITY_GHOST, GHOST_VISIBILITY_ALIVE);
                }
            }

            void Register()
            {
                OnEffectApply += AuraEffectApplyFn(spell_gen_shroud_of_deathAuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                OnEffectRemove += AuraEffectRemoveFn(spell_gen_shroud_of_deathAuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript *GetAuraScript() const
        {
            return new spell_gen_shroud_of_deathAuraScript();
        }
};

void AddSC_generic_spell_scripts()
{
    new spell_gen_aura_of_anger();
    new spell_gen_burn_brutallus();
    new spell_gen_leeching_swarm();
    new spell_gen_parachute();
    new spell_gen_pet_summoned();
    new spell_gen_remove_flight_auras();
    new spell_gen_trick();
    new spell_gen_trick_or_treat();
    new spell_creature_permanent_feign_death();
    new spell_pvp_trinket_wotf_shared_cd();
    new spell_gen_animal_blood();
    new spell_gen_shroud_of_death();
}
