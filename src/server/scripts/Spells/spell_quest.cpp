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
 * Scripts for spells with SPELLFAMILY_GENERIC spells used for quests.
 * This file is only for spells used in multiple zones.
 * Scriptnames of files in this file should be prefixed with "spell_quest_".
 */

#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "SpellAuras.h"
#include "SpellScript.h"

enum TamingTheBeast
{
    SPELL_TAME_ICE_CLAW_BEAR           = 19548,
    SPELL_TAME_LARGE_CRAG_BOAR         = 19674,
    SPELL_TAME_SNOW_LEOPARD            = 19687,
    SPELL_TAME_ADULT_PLAINSTRIDER      = 19688,
    SPELL_TAME_PRAIRIE_STALKER         = 19689,
    SPELL_TAME_SWOOP                   = 19692,
    SPELL_TAME_WEBWOOD_LURKER          = 19693,
    SPELL_TAME_DIRE_MOTTLED_BOAR       = 19694,
    SPELL_TAME_SURF_CRAWLER            = 19696,
    SPELL_TAME_ARMORED_SCORPID         = 19697,
    SPELL_TAME_NIGHTSABER_STALKER      = 19699,
    SPELL_TAME_STRIGID_SCREECHER       = 19700,
    SPELL_TAME_BARBED_CRAWLER          = 30646,
    SPELL_TAME_GREATER_TIMBERSTRIDER   = 30653,
    SPELL_TAME_NIGHTSTALKER            = 30654,
    SPELL_TAME_CRAZED_DRAGONHAWK       = 30099,
    SPELL_TAME_ELDER_SPRINGPAW         = 30102,
    SPELL_TAME_MISTBAT                 = 30105,
    SPELL_TAME_ICE_CLAW_BEAR_1         = 19597,
    SPELL_TAME_LARGE_CRAG_BOAR_1       = 19677,
    SPELL_TAME_SNOW_LEOPARD_1          = 19676,
    SPELL_TAME_ADULT_PLAINSTRIDER_1    = 19678,
    SPELL_TAME_PRAIRIE_STALKER_1       = 19679,
    SPELL_TAME_SWOOP_1                 = 19680,
    SPELL_TAME_WEBWOOD_LURKER_1        = 19684,
    SPELL_TAME_DIRE_MOTTLED_BOAR_1     = 19681,
    SPELL_TAME_SURF_CRAWLER_1          = 19682,
    SPELL_TAME_ARMORED_SCORPID_1       = 19683,
    SPELL_TAME_NIGHTSABER_STALKER_1    = 19685,
    SPELL_TAME_STRIGID_SCREECHER_1     = 19686,
    SPELL_TAME_BARBED_CRAWLER_1        = 30647,
    SPELL_TAME_GREATER_TIMBERSTRIDER_1 = 30648,
    SPELL_TAME_NIGHTSTALKER_1          = 30652,
    SPELL_TAME_CRAZED_DRAGONHAWK_1     = 30100,
    SPELL_TAME_ELDER_SPRINGPAW_1       = 30103,
    SPELL_TAME_MISTBAT_1               = 30104
};

class spell_quest_taming_the_beast : public AuraScript
{
    PrepareAuraScript(spell_quest_taming_the_beast);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_TAME_ICE_CLAW_BEAR_1,
            SPELL_TAME_LARGE_CRAG_BOAR_1,
            SPELL_TAME_SNOW_LEOPARD_1,
            SPELL_TAME_ADULT_PLAINSTRIDER_1,
            SPELL_TAME_PRAIRIE_STALKER_1,
            SPELL_TAME_SWOOP_1,
            SPELL_TAME_WEBWOOD_LURKER_1,
            SPELL_TAME_DIRE_MOTTLED_BOAR_1,
            SPELL_TAME_SURF_CRAWLER_1,
            SPELL_TAME_ARMORED_SCORPID_1,
            SPELL_TAME_NIGHTSABER_STALKER_1,
            SPELL_TAME_STRIGID_SCREECHER_1,
            SPELL_TAME_BARBED_CRAWLER_1,
            SPELL_TAME_GREATER_TIMBERSTRIDER_1,
            SPELL_TAME_NIGHTSTALKER_1,
            SPELL_TAME_CRAZED_DRAGONHAWK_1,
            SPELL_TAME_ELDER_SPRINGPAW_1,
            SPELL_TAME_MISTBAT_1
        });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (!GetCaster() || !GetCaster()->IsAlive() || !GetTarget()->IsAlive())
            return;

        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        uint32 finalSpellId = 0;
        switch (GetId())
        {
            case SPELL_TAME_ICE_CLAW_BEAR:         finalSpellId = SPELL_TAME_ICE_CLAW_BEAR_1; break;
            case SPELL_TAME_LARGE_CRAG_BOAR:       finalSpellId = SPELL_TAME_LARGE_CRAG_BOAR_1; break;
            case SPELL_TAME_SNOW_LEOPARD:          finalSpellId = SPELL_TAME_SNOW_LEOPARD_1; break;
            case SPELL_TAME_ADULT_PLAINSTRIDER:    finalSpellId = SPELL_TAME_ADULT_PLAINSTRIDER_1; break;
            case SPELL_TAME_PRAIRIE_STALKER:       finalSpellId = SPELL_TAME_PRAIRIE_STALKER_1; break;
            case SPELL_TAME_SWOOP:                 finalSpellId = SPELL_TAME_SWOOP_1; break;
            case SPELL_TAME_WEBWOOD_LURKER:        finalSpellId = SPELL_TAME_WEBWOOD_LURKER_1; break;
            case SPELL_TAME_DIRE_MOTTLED_BOAR:     finalSpellId = SPELL_TAME_DIRE_MOTTLED_BOAR_1; break;
            case SPELL_TAME_SURF_CRAWLER:          finalSpellId = SPELL_TAME_SURF_CRAWLER_1; break;
            case SPELL_TAME_ARMORED_SCORPID:       finalSpellId = SPELL_TAME_ARMORED_SCORPID_1; break;
            case SPELL_TAME_NIGHTSABER_STALKER:    finalSpellId = SPELL_TAME_NIGHTSABER_STALKER_1; break;
            case SPELL_TAME_STRIGID_SCREECHER:     finalSpellId = SPELL_TAME_STRIGID_SCREECHER_1; break;
            case SPELL_TAME_BARBED_CRAWLER:        finalSpellId = SPELL_TAME_BARBED_CRAWLER_1; break;
            case SPELL_TAME_GREATER_TIMBERSTRIDER: finalSpellId = SPELL_TAME_GREATER_TIMBERSTRIDER_1; break;
            case SPELL_TAME_NIGHTSTALKER:          finalSpellId = SPELL_TAME_NIGHTSTALKER_1; break;
            case SPELL_TAME_CRAZED_DRAGONHAWK:     finalSpellId = SPELL_TAME_CRAZED_DRAGONHAWK_1; break;
            case SPELL_TAME_ELDER_SPRINGPAW:       finalSpellId = SPELL_TAME_ELDER_SPRINGPAW_1; break;
            case SPELL_TAME_MISTBAT:               finalSpellId = SPELL_TAME_MISTBAT_1; break;
        }

        if (finalSpellId)
            GetCaster()->CastSpell(GetTarget(), finalSpellId, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_quest_taming_the_beast::OnRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 53099, 57896, 58418, 58420, 59064, 59065, 59439, 60900, 60940
class spell_quest_portal_with_condition : public SpellScript
{
    PrepareSpellScript(spell_quest_portal_with_condition);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ uint32(spellInfo->GetEffect(EFFECT_0).CalcValue()) }) &&
            sObjectMgr->GetQuestTemplate(uint32(spellInfo->GetEffect(EFFECT_1).CalcValue()));
    }

    void HandleScriptEffect(SpellEffIndex /* effIndex */)
    {
        Player* target = GetHitPlayer();
        if (!target)
            return;

        uint32 spellId = GetEffectInfo().CalcValue();
        uint32 questId = GetEffectInfo(EFFECT_1).CalcValue();

        // This probably should be a way to throw error in SpellCastResult
        if (target->IsActiveQuest(questId))
            target->CastSpell(target, spellId, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_quest_portal_with_condition::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum TributeSpells
{
    SPELL_GROMS_TROLL_TRIBUTE       = 24101,
    SPELL_GROMS_TAUREN_TRIBUTE      = 24102,
    SPELL_GROMS_UNDEAD_TRIBUTE      = 24103,
    SPELL_GROMS_ORC_TRIBUTE         = 24104,
    SPELL_GROMS_BLOODELF_TRIBUTE    = 69530,
    SPELL_UTHERS_HUMAN_TRIBUTE      = 24105,
    SPELL_UTHERS_GNOME_TRIBUTE      = 24106,
    SPELL_UTHERS_DWARF_TRIBUTE      = 24107,
    SPELL_UTHERS_NIGHTELF_TRIBUTE   = 24108,
    SPELL_UTHERS_DRAENEI_TRIBUTE    = 69533
};

// 24194 - Uther's Tribute
// 24195 - Grom's Tribute
class spell_quest_uther_grom_tribute : public SpellScript
{
    PrepareSpellScript(spell_quest_uther_grom_tribute);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_GROMS_TROLL_TRIBUTE,    SPELL_UTHERS_HUMAN_TRIBUTE,
            SPELL_GROMS_TAUREN_TRIBUTE,   SPELL_UTHERS_GNOME_TRIBUTE,
            SPELL_GROMS_UNDEAD_TRIBUTE,   SPELL_UTHERS_DWARF_TRIBUTE,
            SPELL_GROMS_ORC_TRIBUTE,      SPELL_UTHERS_NIGHTELF_TRIBUTE,
            SPELL_GROMS_BLOODELF_TRIBUTE, SPELL_UTHERS_DRAENEI_TRIBUTE
        });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Player* caster = GetCaster()->ToPlayer();
        if (!caster)
            return;

        uint32 spell = 0;
        switch (caster->GetRace())
        {
            case RACE_TROLL:    spell = SPELL_GROMS_TROLL_TRIBUTE; break;
            case RACE_TAUREN:   spell = SPELL_GROMS_TAUREN_TRIBUTE; break;
            case RACE_UNDEAD_PLAYER: spell = SPELL_GROMS_UNDEAD_TRIBUTE; break;
            case RACE_ORC:      spell = SPELL_GROMS_ORC_TRIBUTE; break;
            case RACE_BLOODELF: spell = SPELL_GROMS_BLOODELF_TRIBUTE; break;
            case RACE_HUMAN:    spell = SPELL_UTHERS_HUMAN_TRIBUTE; break;
            case RACE_GNOME:    spell = SPELL_UTHERS_GNOME_TRIBUTE; break;
            case RACE_DWARF:    spell = SPELL_UTHERS_DWARF_TRIBUTE; break;
            case RACE_NIGHTELF: spell = SPELL_UTHERS_NIGHTELF_TRIBUTE; break;
            case RACE_DRAENEI:  spell = SPELL_UTHERS_DRAENEI_TRIBUTE; break;
            default: break;
        }

        if (spell)
            caster->CastSpell(caster, spell);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_quest_uther_grom_tribute::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum RelicOfTheEarthenRing
{
    SPELL_TOTEM_OF_THE_EARTHEN_RING     = 66747
};

// 66744 - Make Player Destroy Totems
class spell_quest_make_player_destroy_totems : public SpellScript
{
    PrepareSpellScript(spell_quest_make_player_destroy_totems);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TOTEM_OF_THE_EARTHEN_RING });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        // Ignore reagent cost, consumed by quest
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_TOTEM_OF_THE_EARTHEN_RING, TRIGGERED_IGNORE_POWER_AND_REAGENT_COST);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_quest_make_player_destroy_totems::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_quest_spell_scripts()
{
    RegisterSpellScript(spell_quest_taming_the_beast);
    RegisterSpellScript(spell_quest_portal_with_condition);
    RegisterSpellScript(spell_quest_uther_grom_tribute);
    RegisterSpellScript(spell_quest_make_player_destroy_totems);
}
