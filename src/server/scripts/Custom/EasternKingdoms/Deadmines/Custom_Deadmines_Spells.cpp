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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "SpellHistory.h"
#include "Spell.h"

#include "Custom_Instance_Deadmines.h"

namespace Scripts::EasternKingdoms::Deadmines
{
    // Spell: Glubtok Generic Proc (cooldown management)
    class spell_glubtok_generic_proc : public AuraScript
    {
        bool CheckProc(ProcEventInfo& /*eventInfo*/)
        {
            if (GetTarget()->GetSpellHistory()->HasCooldown(GetSpellInfo()->Id))
                return false;

            GetTarget()->GetSpellHistory()->AddCooldown(GetSpellInfo()->Id, 0, 4s);
            return true;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_glubtok_generic_proc::CheckProc);
        }
    };

    // 91397 Fire Wall
    // Spell: Glubtok Firewall Targetting (cooldown check for targets)
    // Hit check to award related achievement
    class spell_glubtok_firewall_targetting : public SpellScript
    {
        void HandleHit()
        {
            if (Player* player = GetHitUnit()->ToPlayer())
            {
                if (InstanceScript* instance = player->GetInstanceScript())
                {
                    // Mark this specific player as hit by firewall using their GUID
                    instance->SetData(player->GetGUID().GetCounter(), 1);
                }
            }
        }

        void SelectTarget(std::list<WorldObject*>& targets)
        {
            targets.remove_if([](WorldObject* target)
                {
                    if (target->ToUnit() && target->ToUnit()->GetSpellHistory()->HasCooldown(Spells::FireWallTriggered))
                        return true;

                    if (target->ToUnit())
                        target->ToUnit()->GetSpellHistory()->AddCooldown(Spells::FireWallTriggered, 0, 1s);
                    return false;
                });
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_glubtok_firewall_targetting::SelectTarget, EFFECT_0, TARGET_UNIT_DEST_AREA_ENTRY);
            OnHit += SpellHitFn(spell_glubtok_firewall_targetting::HandleHit);
        }
    };

    // 89769 - Explode (Mining Powder)
    class spell_mining_powder_explode : public SpellScript
    {
        void HandleThreat(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            Creature* miningPowder = caster->ToCreature();
            if (!miningPowder)
                return;

            // Get the attacker GUID from the mining powder AI using GetGUID
            ObjectGuid attackerGuid = miningPowder->AI()->GetGUID(1);

            if (Unit* attacker = ObjectAccessor::GetUnit(*caster, attackerGuid))
            {
                if (Unit* target = GetHitUnit())
                    target->GetThreatManager().AddThreat(attacker, GetHitDamage());
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_mining_powder_explode::HandleThreat, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    // 89250 - Summon Cauldron
    class spell_captain_cookie_summon_cauldron : public SpellScript
    {
        void SetDest(SpellDestination& dest) const
        {
            dest.Relocate(Positions::CookieCauldronSpawn);
        }

        void Register() override
        {
            OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_captain_cookie_summon_cauldron::SetDest, EFFECT_0, TARGET_DEST_NEARBY_ENTRY);
        }
    };

    // 88278 - Force Player to Ride Oaf
    class spell_helix_force_player_to_ride_oaf : public SpellScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ Spells::RideOaf });
        }

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            if (!GetCaster() || !GetHitUnit())
                return;

            GetHitUnit()->CastSpell(GetCaster(), Spells::RideOaf, true);
            if (Creature* creature = GetCaster()->ToCreature())
                if (creature->AI())
                    creature->AI()->DoAction(Actions::OafCharge);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_helix_force_player_to_ride_oaf::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };
}

void AddSC_custom_deadmines_spells()
{
    using namespace Scripts::EasternKingdoms::Deadmines;

    RegisterSpellScript(spell_glubtok_generic_proc);
    RegisterSpellScript(spell_glubtok_firewall_targetting);
    RegisterSpellScript(spell_captain_cookie_summon_cauldron);
    RegisterSpellScript(spell_helix_force_player_to_ride_oaf);
    RegisterSpellScript(spell_mining_powder_explode);
}
