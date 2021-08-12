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
 * Ordered alphabetically using questId and scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_q#questID_".
 */

#include "ScriptMgr.h"
#include "CellImpl.h"
#include "CreatureAIImpl.h"
#include "CreatureTextMgr.h"
#include "GridNotifiersImpl.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "Vehicle.h"

class spell_generic_quest_update_entry_SpellScript : public SpellScript
{
    PrepareSpellScript(spell_generic_quest_update_entry_SpellScript);
    private:
        uint16 _spellEffect;
        uint8 _effIndex;
        uint32 _originalEntry;
        uint32 _newEntry;
        bool _shouldAttack;
        Milliseconds _despawnTime;

    public:
        spell_generic_quest_update_entry_SpellScript(uint16 spellEffect, uint8 effIndex, uint32 originalEntry, uint32 newEntry, bool shouldAttack, Milliseconds despawnTime = 0s) :
            SpellScript(), _spellEffect(spellEffect), _effIndex(effIndex), _originalEntry(originalEntry),
            _newEntry(newEntry), _shouldAttack(shouldAttack), _despawnTime(despawnTime) { }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Creature* creatureTarget = GetHitCreature())
                if (!creatureTarget->IsPet() && creatureTarget->GetEntry() == _originalEntry)
                {
                    creatureTarget->UpdateEntry(_newEntry);
                    if (_shouldAttack)
                        creatureTarget->EngageWithTarget(GetCaster());

                    if (_despawnTime != 0s)
                        creatureTarget->DespawnOrUnsummon(_despawnTime);
                }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_generic_quest_update_entry_SpellScript::HandleDummy, _effIndex, _spellEffect);
        }
};

// http://www.wowhead.com/quest=55 Morbent Fel
enum Quest55Data
{
    NPC_MORBENT             = 1200,
    NPC_WEAKENED_MORBENT    = 24782,
};

// 8913 - Sacred Cleansing
class spell_q55_sacred_cleansing : public SpellScriptLoader
{
    public:
        spell_q55_sacred_cleansing() : SpellScriptLoader("spell_q55_sacred_cleansing") { }

        SpellScript* GetSpellScript() const override
        {
            return new spell_generic_quest_update_entry_SpellScript(SPELL_EFFECT_DUMMY, EFFECT_1, NPC_MORBENT, NPC_WEAKENED_MORBENT, true);
        }
};

enum BendingShinbone
{
    SPELL_BENDING_SHINBONE1 = 8854,
    SPELL_BENDING_SHINBONE2 = 8855
};

// 8856 - Bending Shinbone
class spell_q1846_bending_shinbone : public SpellScript
{
    PrepareSpellScript(spell_q1846_bending_shinbone);

    void HandleScriptEffect(SpellEffIndex /* effIndex */)
    {
        Item* target = GetHitItem();
        Unit* caster = GetCaster();
        if (!target && caster->GetTypeId() != TYPEID_PLAYER)
            return;

        uint32 const spellId = roll_chance_i(20) ? SPELL_BENDING_SHINBONE1 : SPELL_BENDING_SHINBONE2;
        caster->CastSpell(caster, spellId, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q1846_bending_shinbone::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum ThaumaturgyChannel
{
    SPELL_THAUMATURGY_CHANNEL = 21029
};

// 9712 - Thaumaturgy Channel
class spell_q2203_thaumaturgy_channel : public AuraScript
{
    PrepareAuraScript(spell_q2203_thaumaturgy_channel);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_THAUMATURGY_CHANNEL });
    }

    void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, SPELL_THAUMATURGY_CHANNEL, false);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_q2203_thaumaturgy_channel::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// http://www.wowhead.com/quest=5206 Marauders of Darrowshire
enum Quest5206Data
{
    SPELL_CREATE_RESONATING_SKULL = 17269,
    SPELL_CREATE_BONE_DUST = 17270
};

// 17271 - Test Fetid Skull
class spell_q5206_test_fetid_skull : public SpellScript
{
    PrepareSpellScript(spell_q5206_test_fetid_skull);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    bool Validate(SpellInfo const* /*spellEntry*/) override
    {
        return ValidateSpellInfo({ SPELL_CREATE_RESONATING_SKULL, SPELL_CREATE_BONE_DUST });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        uint32 spellId = roll_chance_i(50) ? SPELL_CREATE_RESONATING_SKULL : SPELL_CREATE_BONE_DUST;
        caster->CastSpell(caster, spellId, true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_q5206_test_fetid_skull::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// http://www.wowhead.com/quest=6124 Curing the Sick (A)
// http://www.wowhead.com/quest=6129 Curing the Sick (H)
enum Quests6124_6129Data
{
    NPC_SICKLY_GAZELLE  = 12296,
    NPC_CURED_GAZELLE   = 12297,
    NPC_SICKLY_DEER     = 12298,
    NPC_CURED_DEER      = 12299,
};

constexpr Milliseconds Quest6124_6129_DESPAWN_TIME = 30s;

// 19512 - Apply Salve
class spell_q6124_6129_apply_salve : public SpellScript
{
    PrepareSpellScript(spell_q6124_6129_apply_salve);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Player* caster = GetCaster()->ToPlayer();
        if (GetCastItem())
            if (Creature* creatureTarget = GetHitCreature())
            {
                uint32 newEntry = 0;
                switch (caster->GetTeam())
                {
                    case HORDE:
                        if (creatureTarget->GetEntry() == NPC_SICKLY_GAZELLE)
                            newEntry = NPC_CURED_GAZELLE;
                        break;
                    case ALLIANCE:
                        if (creatureTarget->GetEntry() == NPC_SICKLY_DEER)
                            newEntry = NPC_CURED_DEER;
                        break;
                }
                if (newEntry)
                {
                    creatureTarget->UpdateEntry(newEntry);
                    creatureTarget->DespawnOrUnsummon(Quest6124_6129_DESPAWN_TIME);
                    caster->KilledMonsterCredit(newEntry);
                }
            }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q6124_6129_apply_salve::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// http://www.wowhead.com/quest=10255 Testing the Antidote
enum Quest10255Data
{
    NPC_HELBOAR     = 16880,
    NPC_DREADTUSK   = 16992,
};

// 34665 - Administer Antidote
class spell_q10255_administer_antidote : public SpellScriptLoader
{
    public:
        spell_q10255_administer_antidote() : SpellScriptLoader("spell_q10255_administer_antidote") { }

        SpellScript* GetSpellScript() const override
        {
            return new spell_generic_quest_update_entry_SpellScript(SPELL_EFFECT_DUMMY, EFFECT_0, NPC_HELBOAR, NPC_DREADTUSK, true);
        }
};

// http://www.wowhead.com/quest=11396 Bring Down Those Shields (A)
// http://www.wowhead.com/quest=11399 Bring Down Those Shields (H)
enum Quest11396_11399Data
{
    SPELL_FORCE_SHIELD_ARCANE_PURPLE_X3 = 43874,
    SPELL_SCOURGING_CRYSTAL_CONTROLLER = 43878
};

// 43874 - Scourge Mur'gul Camp: Force Shield Arcane Purple x3
class spell_q11396_11399_force_shield_arcane_purple_x3 : public AuraScript
{
    PrepareAuraScript(spell_q11396_11399_force_shield_arcane_purple_x3);

    void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->SetImmuneToPC(true);
        target->AddUnitState(UNIT_STATE_ROOT);
    }

    void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->SetImmuneToPC(false);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_q11396_11399_force_shield_arcane_purple_x3::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_q11396_11399_force_shield_arcane_purple_x3::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 50133 - Scourging Crystal Controller
class spell_q11396_11399_scourging_crystal_controller : public SpellScript
{
    PrepareSpellScript(spell_q11396_11399_scourging_crystal_controller);

    bool Validate(SpellInfo const* /*spellEntry*/) override
    {
        return ValidateSpellInfo({ SPELL_FORCE_SHIELD_ARCANE_PURPLE_X3, SPELL_SCOURGING_CRYSTAL_CONTROLLER });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
            if (target->GetTypeId() == TYPEID_UNIT && target->HasAura(SPELL_FORCE_SHIELD_ARCANE_PURPLE_X3))
                // Make sure nobody else is channeling the same target
                if (!target->HasAura(SPELL_SCOURGING_CRYSTAL_CONTROLLER))
                    GetCaster()->CastSpell(target, SPELL_SCOURGING_CRYSTAL_CONTROLLER, GetCastItem());
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q11396_11399_scourging_crystal_controller::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 43882 - Scourging Crystal Controller Dummy
class spell_q11396_11399_scourging_crystal_controller_dummy : public SpellScript
{
    PrepareSpellScript(spell_q11396_11399_scourging_crystal_controller_dummy);

    bool Validate(SpellInfo const* /*spellEntry*/) override
    {
        return ValidateSpellInfo({ SPELL_FORCE_SHIELD_ARCANE_PURPLE_X3 });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
            if (target->GetTypeId() == TYPEID_UNIT)
                target->RemoveAurasDueToSpell(SPELL_FORCE_SHIELD_ARCANE_PURPLE_X3);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q11396_11399_scourging_crystal_controller_dummy::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// http://www.wowhead.com/quest=11515 Blood for Blood
enum Quest11515Data
{
    NPC_FELBLOOD_INITIATE   = 24918,
    NPC_EMACIATED_FELBLOOD  = 24955
};

// 44936 - Quest - Fel Siphon Dummy
class spell_q11515_fel_siphon_dummy : public SpellScriptLoader
{
    public:
        spell_q11515_fel_siphon_dummy() : SpellScriptLoader("spell_q11515_fel_siphon_dummy") { }

        SpellScript* GetSpellScript() const override
        {
            return new spell_generic_quest_update_entry_SpellScript(SPELL_EFFECT_DUMMY, EFFECT_0, NPC_FELBLOOD_INITIATE, NPC_EMACIATED_FELBLOOD, true);
        }
};

// http://www.wowhead.com/quest=11587 Prison Break
enum Quest11587Data
{
    SPELL_SUMMON_ARCANE_PRISONER_MALE    = 45446,    // Summon Arcane Prisoner - Male
    SPELL_SUMMON_ARCANE_PRISONER_FEMALE  = 45448     // Summon Arcane Prisoner - Female
};

// 45449 - Arcane Prisoner Rescue
class spell_q11587_arcane_prisoner_rescue : public SpellScript
{
    PrepareSpellScript(spell_q11587_arcane_prisoner_rescue);

    bool Validate(SpellInfo const* /*spellEntry*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_ARCANE_PRISONER_MALE, SPELL_SUMMON_ARCANE_PRISONER_FEMALE });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        uint32 spellId = SPELL_SUMMON_ARCANE_PRISONER_MALE;
        if (rand32() % 2)
            spellId = SPELL_SUMMON_ARCANE_PRISONER_FEMALE;
        caster->CastSpell(caster, spellId, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q11587_arcane_prisoner_rescue::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// http://www.wowhead.com/quest=11730 Master and Servant
enum Quest11730Data
{
    SPELL_SUMMON_SCAVENGEBOT_004A8  = 46063,
    SPELL_SUMMON_SENTRYBOT_57K      = 46068,
    SPELL_SUMMON_DEFENDOTANK_66D    = 46058,
    SPELL_SUMMON_SCAVENGEBOT_005B6  = 46066,
    SPELL_SUMMON_55D_COLLECTATRON   = 46034,
    SPELL_ROBOT_KILL_CREDIT         = 46027,
    NPC_SCAVENGEBOT_004A8           = 25752,
    NPC_SENTRYBOT_57K               = 25753,
    NPC_DEFENDOTANK_66D             = 25758,
    NPC_SCAVENGEBOT_005B6           = 25792,
    NPC_55D_COLLECTATRON            = 25793
};

// 46023 - The Ultrasonic Screwdriver
class spell_q11730_ultrasonic_screwdriver : public SpellScript
{
    PrepareSpellScript(spell_q11730_ultrasonic_screwdriver);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER && GetCastItem();
    }

    bool Validate(SpellInfo const* /*spellEntry*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_SUMMON_SCAVENGEBOT_004A8,
            SPELL_SUMMON_SENTRYBOT_57K,
            SPELL_SUMMON_DEFENDOTANK_66D,
            SPELL_SUMMON_SCAVENGEBOT_005B6,
            SPELL_SUMMON_55D_COLLECTATRON,
            SPELL_ROBOT_KILL_CREDIT
        });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Item* castItem = GetCastItem();
        Unit* caster = GetCaster();
        if (Creature* target = GetHitCreature())
        {
            uint32 spellId = 0;
            switch (target->GetEntry())
            {
                case NPC_SCAVENGEBOT_004A8: spellId = SPELL_SUMMON_SCAVENGEBOT_004A8;    break;
                case NPC_SENTRYBOT_57K:     spellId = SPELL_SUMMON_SENTRYBOT_57K;        break;
                case NPC_DEFENDOTANK_66D:   spellId = SPELL_SUMMON_DEFENDOTANK_66D;      break;
                case NPC_SCAVENGEBOT_005B6: spellId = SPELL_SUMMON_SCAVENGEBOT_005B6;    break;
                case NPC_55D_COLLECTATRON:  spellId = SPELL_SUMMON_55D_COLLECTATRON;     break;
                default:
                    return;
            }
            caster->CastSpell(caster, spellId, castItem);
            caster->CastSpell(caster, SPELL_ROBOT_KILL_CREDIT, true);
            target->DespawnOrUnsummon();
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q11730_ultrasonic_screwdriver::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// http://www.wowhead.com/quest=12459 That Which Creates Can Also Destroy
enum Quest12459Data
{
    NPC_REANIMATED_FROSTWYRM        = 26841,
    NPC_WEAK_REANIMATED_FROSTWYRM   = 27821,

    NPC_TURGID                      = 27808,
    NPC_WEAK_TURGID                 = 27809,

    NPC_DEATHGAZE                   = 27122,
    NPC_WEAK_DEATHGAZE              = 27807,
};

// 49587 - Seeds of Nature's Wrath
class spell_q12459_seeds_of_natures_wrath : public SpellScript
{
    PrepareSpellScript(spell_q12459_seeds_of_natures_wrath);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Creature* creatureTarget = GetHitCreature())
        {
            uint32 uiNewEntry = 0;
            switch (creatureTarget->GetEntry())
            {
                case NPC_REANIMATED_FROSTWYRM:  uiNewEntry = NPC_WEAK_REANIMATED_FROSTWYRM; break;
                case NPC_TURGID:                uiNewEntry = NPC_WEAK_TURGID;               break;
                case NPC_DEATHGAZE:             uiNewEntry = NPC_WEAK_DEATHGAZE;            break;
            }
            if (uiNewEntry)
                creatureTarget->UpdateEntry(uiNewEntry);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q12459_seeds_of_natures_wrath::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// http://www.wowhead.com/quest=12634 Some Make Lemonade, Some Make Liquor
enum Quest12634Data
{
    SPELL_BANANAS_FALL_TO_GROUND    = 51836,
    SPELL_ORANGE_FALLS_TO_GROUND    = 51837,
    SPELL_PAPAYA_FALLS_TO_GROUND    = 51839,
    SPELL_SUMMON_ADVENTUROUS_DWARF  = 52070
};

// 51840 - Despawn Fruit Tosser
class spell_q12634_despawn_fruit_tosser : public SpellScript
{
    PrepareSpellScript(spell_q12634_despawn_fruit_tosser);

    bool Validate(SpellInfo const* /*spellEntry*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_BANANAS_FALL_TO_GROUND,
            SPELL_ORANGE_FALLS_TO_GROUND,
            SPELL_PAPAYA_FALLS_TO_GROUND,
            SPELL_SUMMON_ADVENTUROUS_DWARF
        });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        uint32 spellId = SPELL_BANANAS_FALL_TO_GROUND;
        switch (urand(0, 3))
        {
            case 1: spellId = SPELL_ORANGE_FALLS_TO_GROUND; break;
            case 2: spellId = SPELL_PAPAYA_FALLS_TO_GROUND; break;
        }
        // sometimes, if you're lucky, you get a dwarf
        if (roll_chance_i(5))
            spellId = SPELL_SUMMON_ADVENTUROUS_DWARF;
        GetCaster()->CastSpell(GetCaster(), spellId, true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_q12634_despawn_fruit_tosser::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// http://www.wowhead.com/quest=12683 Burning to Help
// 52308 - Take Sputum Sample
class spell_q12683_take_sputum_sample : public SpellScript
{
    PrepareSpellScript(spell_q12683_take_sputum_sample);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        uint32 reqAuraId = GetSpellInfo()->Effects[EFFECT_1].CalcValue();

        Unit* caster = GetCaster();
        if (caster->HasAuraEffect(reqAuraId, 0))
        {
            uint32 spellId = GetSpellInfo()->Effects[EFFECT_0].CalcValue();
            caster->CastSpell(caster, spellId, true);
        }
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_q12683_take_sputum_sample::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// http://www.wowhead.com/quest=12851 Going Bearback
enum Quest12851Data
{
    NPC_FROSTGIANT = 29351,
    NPC_FROSTWORG  = 29358,
    SPELL_FROSTGIANT_CREDIT = 58184,
    SPELL_FROSTWORG_CREDIT  = 58183,
    SPELL_IMMOLATION        = 54690,
    SPELL_ABLAZE            = 54683,
};

// 54798 - FLAMING Arrow Triggered Effect
class spell_q12851_going_bearback : public AuraScript
{
    PrepareAuraScript(spell_q12851_going_bearback);

    void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
        {
            Unit* target = GetTarget();
            // Already in fire
            if (target->HasAura(SPELL_ABLAZE))
                return;

            if (Player* player = caster->GetCharmerOrOwnerPlayerOrPlayerItself())
            {
                switch (target->GetEntry())
                {
                    case NPC_FROSTWORG:
                        target->CastSpell(player, SPELL_FROSTWORG_CREDIT, true);
                        target->CastSpell(target, SPELL_IMMOLATION, true);
                        target->CastSpell(target, SPELL_ABLAZE, true);
                        break;
                    case NPC_FROSTGIANT:
                        target->CastSpell(player, SPELL_FROSTGIANT_CREDIT, true);
                        target->CastSpell(target, SPELL_IMMOLATION, true);
                        target->CastSpell(target, SPELL_ABLAZE, true);
                        break;
                }
            }
        }
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_q12851_going_bearback::HandleEffectApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
};

enum Whoarethey
{
    SPELL_MALE_DISGUISE = 38080,
    SPELL_FEMALE_DISGUISE = 38081,
    SPELL_GENERIC_DISGUISE = 32756
};

// 48917 - Who Are They: Cast from Questgiver
class spell_q10041_q10040_who_are_they : public SpellScript
{
    PrepareSpellScript(spell_q10041_q10040_who_are_they);

    bool Validate(SpellInfo const* /*spellEntry*/) override
    {
        return ValidateSpellInfo({ SPELL_MALE_DISGUISE, SPELL_FEMALE_DISGUISE, SPELL_GENERIC_DISGUISE });
    }

    void HandleScript(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        if (Player* target = GetHitPlayer())
        {
            target->CastSpell(target, target->GetNativeGender() == GENDER_MALE ? SPELL_MALE_DISGUISE : SPELL_FEMALE_DISGUISE, true);
            target->CastSpell(target, SPELL_GENERIC_DISGUISE, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q10041_q10040_who_are_they::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// http://www.wowhead.com/quest=12659 Scalps!
enum Quest12659Data
{
    NPC_SCALPS_KC_BUNNY = 28622,
};

// 52090 - Ahunae's Knife
class spell_q12659_ahunaes_knife : public SpellScript
{
    PrepareSpellScript(spell_q12659_ahunaes_knife);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Player* caster = GetCaster()->ToPlayer();
        if (Creature* target = GetHitCreature())
        {
            target->DespawnOrUnsummon();
            caster->KilledMonsterCredit(NPC_SCALPS_KC_BUNNY);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q12659_ahunaes_knife::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

enum StoppingTheSpread
{
    NPC_VILLAGER_KILL_CREDIT                     = 18240,
    SPELL_FLAMES                                 = 39199
};

// 32146 - Liquid Fire
class spell_q9874_liquid_fire : public SpellScript
{
    PrepareSpellScript(spell_q9874_liquid_fire);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Player* caster = GetCaster()->ToPlayer();
        if (Creature* target = GetHitCreature())
            if (!target->HasAura(SPELL_FLAMES))
            {
                caster->KilledMonsterCredit(NPC_VILLAGER_KILL_CREDIT);
                target->CastSpell(target, SPELL_FLAMES, true);
                target->DespawnOrUnsummon(60s);
            }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q9874_liquid_fire::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

enum SalvagingLifesStength
{
    NPC_SHARD_KILL_CREDIT                        = 29303,
};

// 54190 - Lifeblood Dummy
class spell_q12805_lifeblood_dummy : public SpellScript
{
    PrepareSpellScript(spell_q12805_lifeblood_dummy);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Player* caster = GetCaster()->ToPlayer();
        if (Creature* target = GetHitCreature())
        {
            caster->KilledMonsterCredit(NPC_SHARD_KILL_CREDIT);
            target->CastSpell(target, uint32(GetEffectValue()), true);
            target->DespawnOrUnsummon(2s);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q12805_lifeblood_dummy::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

/*
 http://www.wowhead.com/quest=13283 King of the Mountain
 http://www.wowhead.com/quest=13280 King of the Mountain
 */
enum BattleStandard
{
    NPC_KING_OF_THE_MOUNTAINT_KC         = 31766,
    SPELL_PLANT_HORDE_BATTLE_STANDARD    = 59643,
    SPELL_HORDE_BATTLE_STANDARD_STATE    = 59642,
    SPELL_ALLIANCE_BATTLE_STANDARD_STATE = 4339,
    SPELL_JUMP_ROCKET_BLAST              = 4340
};

// 4338 - Plant Alliance Battle Standard
// 59643 - Plant Horde Battle Standard
class spell_q13280_13283_plant_battle_standard : public SpellScript
{
    PrepareSpellScript(spell_q13280_13283_plant_battle_standard);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        uint32 triggeredSpellID = SPELL_ALLIANCE_BATTLE_STANDARD_STATE;

        caster->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
        if (caster->IsVehicle())
            if (Unit* player = caster->GetVehicleKit()->GetPassenger(0))
                player->ToPlayer()->KilledMonsterCredit(NPC_KING_OF_THE_MOUNTAINT_KC);

        if (GetSpellInfo()->Id == SPELL_PLANT_HORDE_BATTLE_STANDARD)
            triggeredSpellID = SPELL_HORDE_BATTLE_STANDARD_STATE;

        target->RemoveAllAuras();
        target->CastSpell(target, triggeredSpellID, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q13280_13283_plant_battle_standard::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 4336 - Jump Jets
class spell_q13280_13283_jump_jets : public SpellScript
{
    PrepareSpellScript(spell_q13280_13283_jump_jets);

    void HandleCast()
    {
        Unit* caster = GetCaster();
        if (caster->IsVehicle())
            if (Unit* rocketBunny = caster->GetVehicleKit()->GetPassenger(1))
                rocketBunny->CastSpell(rocketBunny, SPELL_JUMP_ROCKET_BLAST, true);
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_q13280_13283_jump_jets::HandleCast);
    }
};

enum ChumTheWaterSummons
{
    SUMMON_ANGRY_KVALDIR = 66737,
    SUMMON_NORTH_SEA_MAKO = 66738,
    SUMMON_NORTH_SEA_THRESHER = 66739,
    SUMMON_NORTH_SEA_BLUE_SHARK = 66740
};

// 66741 - Chum the Water
class spell_q14112_14145_chum_the_water : public SpellScript
{
    PrepareSpellScript(spell_q14112_14145_chum_the_water);

    bool Validate(SpellInfo const* /*spellEntry*/) override
    {
        return ValidateSpellInfo({ SUMMON_ANGRY_KVALDIR, SUMMON_NORTH_SEA_MAKO, SUMMON_NORTH_SEA_THRESHER, SUMMON_NORTH_SEA_BLUE_SHARK });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, RAND(SUMMON_ANGRY_KVALDIR, SUMMON_NORTH_SEA_MAKO, SUMMON_NORTH_SEA_THRESHER, SUMMON_NORTH_SEA_BLUE_SHARK));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q14112_14145_chum_the_water::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum RedSnapperVeryTasty
{
    SPELL_FISHED_UP_RED_SNAPPER  = 29867,
    SPELL_FISHED_UP_MURLOC       = 29869
};

// 29866 - Cast Fishing Net
class spell_q9452_cast_net : public SpellScript
{
    PrepareSpellScript(spell_q9452_cast_net);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_FISHED_UP_RED_SNAPPER, SPELL_FISHED_UP_MURLOC });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();

        if (roll_chance_i(66))
            caster->CastSpell(caster, SPELL_FISHED_UP_RED_SNAPPER, true);
        else
            caster->CastSpell(nullptr, SPELL_FISHED_UP_MURLOC, true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_q9452_cast_net::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

enum BreakfastOfChampions
{
    SPELL_SUMMON_DEEP_JORMUNGAR     = 66510,
    SPELL_STORMFORGED_MOLE_MACHINE  = 66492
};

// 66512 - Pound Drum
class spell_q14076_14092_pound_drum : public SpellScript
{
    PrepareSpellScript(spell_q14076_14092_pound_drum);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_DEEP_JORMUNGAR, SPELL_STORMFORGED_MOLE_MACHINE });
    }

    void HandleSummon()
    {
        Unit* caster = GetCaster();

        if (roll_chance_i(50))
            caster->CastSpell(caster, SPELL_SUMMON_DEEP_JORMUNGAR, true);
        else
            caster->CastSpell(caster, SPELL_STORMFORGED_MOLE_MACHINE, true);
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_q14076_14092_pound_drum::HandleSummon);
    }
};

enum HodirsHelm
{
    SAY_1               = 1,
    SAY_2               = 2,
    NPC_KILLCREDIT      = 30210, // Hodir's Helm KC Bunny
    NPC_ICE_SPIKE_BUNNY = 30215
};

// 56278 - Read Pronouncement
class spell_q12987_read_pronouncement : public AuraScript
{
    PrepareAuraScript(spell_q12987_read_pronouncement);

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        // player must cast kill credit and do emote text, according to sniff
        if (Player* target = GetTarget()->ToPlayer())
        {
            if (Creature* trigger = target->FindNearestCreature(NPC_ICE_SPIKE_BUNNY, 25.0f))
            {
                sCreatureTextMgr->SendChat(trigger, SAY_1, target, CHAT_MSG_ADDON, LANG_ADDON, TEXT_RANGE_NORMAL, 0, TEAM_OTHER, false, target);
                target->KilledMonsterCredit(NPC_KILLCREDIT);
                sCreatureTextMgr->SendChat(trigger, SAY_2, target, CHAT_MSG_ADDON, LANG_ADDON, TEXT_RANGE_NORMAL, 0, TEAM_OTHER, false, target);
            }
        }
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_q12987_read_pronouncement::OnApply, EFFECT_0, SPELL_AURA_NONE, AURA_EFFECT_HANDLE_REAL);
    }
};

enum LeaveNothingToChance
{
    NPC_UPPER_MINE_SHAFT            = 27436,
    NPC_LOWER_MINE_SHAFT            = 27437,

    SPELL_UPPER_MINE_SHAFT_CREDIT   = 48744,
    SPELL_LOWER_MINE_SHAFT_CREDIT   = 48745,
};

// 48742 - Wintergarde Mine Explosion
class spell_q12277_wintergarde_mine_explosion : public SpellScript
{
    PrepareSpellScript(spell_q12277_wintergarde_mine_explosion);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Creature* unitTarget = GetHitCreature())
        {
            if (Unit* caster = GetCaster())
            {
                if (caster->GetTypeId() == TYPEID_UNIT)
                {
                    if (Unit* owner = caster->GetOwner())
                    {
                        switch (unitTarget->GetEntry())
                        {
                            case NPC_UPPER_MINE_SHAFT:
                                caster->CastSpell(owner, SPELL_UPPER_MINE_SHAFT_CREDIT, true);
                                break;
                            case NPC_LOWER_MINE_SHAFT:
                                caster->CastSpell(owner, SPELL_LOWER_MINE_SHAFT_CREDIT, true);
                                break;
                            default:
                                break;
                        }
                    }
                }
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q12277_wintergarde_mine_explosion::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

enum FocusOnTheBeach
{
    SPELL_BUNNY_CREDIT_BEAM = 47390,
};

// 50546 - The Focus on the Beach: Ley Line Focus Control Ring Effect
class spell_q12066_bunny_kill_credit : public SpellScript
{
    PrepareSpellScript(spell_q12066_bunny_kill_credit);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Creature* target = GetHitCreature())
            target->CastSpell(GetCaster(), SPELL_BUNNY_CREDIT_BEAM, false);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q12066_bunny_kill_credit::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

enum ACleansingSong
{
    SPELL_SUMMON_SPIRIT_ATAH        = 52954,
    SPELL_SUMMON_SPIRIT_HAKHALAN    = 52958,
    SPELL_SUMMON_SPIRIT_KOOSU       = 52959,

    AREA_BITTERTIDELAKE             = 4385,
    AREA_RIVERSHEART                = 4290,
    AREA_WINTERGRASPRIVER           = 4388,
};

// 52941 - Song of Cleansing
class spell_q12735_song_of_cleansing : public SpellScript
{
    PrepareSpellScript(spell_q12735_song_of_cleansing);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        switch (caster->GetAreaId())
        {
            case AREA_BITTERTIDELAKE:
                caster->CastSpell(caster, SPELL_SUMMON_SPIRIT_ATAH);
                break;
            case AREA_RIVERSHEART:
                caster->CastSpell(caster, SPELL_SUMMON_SPIRIT_HAKHALAN);
                break;
            case AREA_WINTERGRASPRIVER:
                caster->CastSpell(caster, SPELL_SUMMON_SPIRIT_KOOSU);
                break;
            default:
                break;
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q12735_song_of_cleansing::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum DefendingWyrmrestTemple
{
    SPELL_SUMMON_WYRMREST_DEFENDER       = 49207
};

// 49213 - Defending Wyrmrest Temple: Character Script Cast From Gossip
class spell_q12372_cast_from_gossip_trigger : public SpellScript
{
    PrepareSpellScript(spell_q12372_cast_from_gossip_trigger);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_SUMMON_WYRMREST_DEFENDER, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q12372_cast_from_gossip_trigger::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// http://www.wowhead.com/quest=12372 Defending Wyrmrest Temple
enum Quest12372Data
{
    // NPCs
    NPC_WYRMREST_TEMPLE_CREDIT       = 27698,
    // Spells
    WHISPER_ON_HIT_BY_FORCE_WHISPER       = 1
};

// 49370 - Wyrmrest Defender: Destabilize Azure Dragonshrine Effect
class spell_q12372_destabilize_azure_dragonshrine_dummy : public SpellScript
{
    PrepareSpellScript(spell_q12372_destabilize_azure_dragonshrine_dummy);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (GetHitCreature())
            if (Unit* caster = GetOriginalCaster())
                if (Vehicle* vehicle = caster->GetVehicleKit())
                    if (Unit* passenger = vehicle->GetPassenger(0))
                        if (Player* player = passenger->ToPlayer())
                            player->KilledMonsterCredit(NPC_WYRMREST_TEMPLE_CREDIT);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q12372_destabilize_azure_dragonshrine_dummy::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

enum q12372Creatures
{
    NPC_WYRMREST_DEFENDER = 27629
};

// 50287 - Azure Dragon: On Death Force Cast Wyrmrest Defender to Whisper to Controller - Random (cast from Azure Dragons and Azure Drakes on death)
class spell_q12372_azure_on_death_force_whisper : public SpellScript
{
    PrepareSpellScript(spell_q12372_azure_on_death_force_whisper);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Creature* defender = GetHitCreature();
        if (defender && defender->GetEntry() == NPC_WYRMREST_DEFENDER)
            defender->AI()->Talk(WHISPER_ON_HIT_BY_FORCE_WHISPER, defender->GetCharmerOrOwner());
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q12372_azure_on_death_force_whisper::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// "Bombing Run" and "Bomb Them Again!"
enum Quest11010_11102_11023Data
{
    // Spell
    SPELL_FLAK_CANNON_TRIGGER = 40110,
    SPELL_CHOOSE_LOC          = 40056,
    SPELL_AGGRO_CHECK         = 40112,
    // NPCs
    NPC_FEL_CANNON2           = 23082
};

// 40113 - Knockdown Fel Cannon: The Aggro Check Aura
class spell_q11010_q11102_q11023_aggro_check_aura : public AuraScript
{
    PrepareAuraScript(spell_q11010_q11102_q11023_aggro_check_aura);

    void HandleTriggerSpell(AuraEffect const* /*aurEff*/)
    {
        if (Unit* target = GetTarget())
            // On trigger proccing
            target->CastSpell(target, SPELL_AGGRO_CHECK);
    }

    void Register() override
    {
       OnEffectPeriodic += AuraEffectPeriodicFn(spell_q11010_q11102_q11023_aggro_check_aura::HandleTriggerSpell, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 40112 - Knockdown Fel Cannon: The Aggro Check
class spell_q11010_q11102_q11023_aggro_check : public SpellScript
{
    PrepareSpellScript(spell_q11010_q11102_q11023_aggro_check);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Player* playerTarget = GetHitPlayer())
            // Check if found player target is on fly mount or using flying form
            if (playerTarget->HasAuraType(SPELL_AURA_FLY) || playerTarget->HasAuraType(SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED))
                playerTarget->CastSpell(playerTarget, SPELL_FLAK_CANNON_TRIGGER, TRIGGERED_IGNORE_CASTER_MOUNTED_OR_ON_VEHICLE);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q11010_q11102_q11023_aggro_check::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 40119 - Knockdown Fel Cannon: The Aggro Burst
class spell_q11010_q11102_q11023_aggro_burst : public AuraScript
{
    PrepareAuraScript(spell_q11010_q11102_q11023_aggro_burst);

    void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
    {
        if (Unit* target = GetTarget())
            // On each tick cast Choose Loc to trigger summon
            target->CastSpell(target, SPELL_CHOOSE_LOC);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_q11010_q11102_q11023_aggro_burst::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 40056 - Knockdown Fel Cannon: Choose Loc
class spell_q11010_q11102_q11023_choose_loc : public SpellScript
{
    PrepareSpellScript(spell_q11010_q11102_q11023_choose_loc);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        // Check for player that is in 65 y range
        std::list<Player*> playerList;
        Trinity::AnyPlayerInObjectRangeCheck checker(caster, 65.0f);
        Trinity::PlayerListSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(caster, playerList, checker);
        Cell::VisitWorldObjects(caster, searcher, 65.0f);
        for (std::list<Player*>::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
            // Check if found player target is on fly mount or using flying form
            if ((*itr)->HasAuraType(SPELL_AURA_FLY) || (*itr)->HasAuraType(SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED))
                // Summom Fel Cannon (bunny version) at found player
                caster->SummonCreature(NPC_FEL_CANNON2, (*itr)->GetPositionX(), (*itr)->GetPositionY(), (*itr)->GetPositionZ());
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_q11010_q11102_q11023_choose_loc::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 39844 - Skyguard Blasting Charge
// 40160 - Throw Bomb
class spell_q11010_q11102_q11023_q11008_check_fly_mount : public SpellScript
{
    PrepareSpellScript(spell_q11010_q11102_q11023_q11008_check_fly_mount);

    SpellCastResult CheckRequirement()
    {
        Unit* caster = GetCaster();
        // This spell will be cast only if caster has one of these auras
        if (!(caster->HasAuraType(SPELL_AURA_FLY) || caster->HasAuraType(SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED)))
            return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;
        return SPELL_CAST_OK;
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_q11010_q11102_q11023_q11008_check_fly_mount::CheckRequirement);
    }
};

enum RecoverTheCargo
{
    SPELL_SUMMON_LOCKBOX        = 42288,
    SPELL_SUMMON_BURROWER       = 42289
};

// 42287 - Salvage Wreckage
class spell_q11140salvage_wreckage : public SpellScript
{
    PrepareSpellScript(spell_q11140salvage_wreckage);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_LOCKBOX, SPELL_SUMMON_BURROWER });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();

        if (roll_chance_i(50))
            caster->CastSpell(caster, SPELL_SUMMON_LOCKBOX, true);
        else
            caster->CastSpell(nullptr, SPELL_SUMMON_BURROWER, true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_q11140salvage_wreckage::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

enum SpellZuldrakRat
{
    SPELL_SUMMON_GORGED_LURKING_BASILISK    = 50928
};

// 50894 - Zul'Drak Rat
class spell_q12527_zuldrak_rat : public SpellScript
{
    PrepareSpellScript(spell_q12527_zuldrak_rat);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_GORGED_LURKING_BASILISK });
    }

    void HandleScriptEffect(SpellEffIndex /* effIndex */)
    {
        if (GetHitAura() && GetHitAura()->GetStackAmount() >= GetSpellInfo()->StackAmount)
        {
            GetHitUnit()->CastSpell((Unit*) nullptr, SPELL_SUMMON_GORGED_LURKING_BASILISK, true);
            if (Creature* basilisk = GetHitUnit()->ToCreature())
                basilisk->DespawnOrUnsummon();
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q12527_zuldrak_rat::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 55368 - Summon Stefan
class spell_q12661_q12669_q12676_q12677_q12713_summon_stefan : public SpellScript
{
    PrepareSpellScript(spell_q12661_q12669_q12676_q12677_q12713_summon_stefan);

    void SetDest(SpellDestination& dest)
    {
        // Adjust effect summon position
        Position const offset = { 0.0f, 0.0f, 20.0f, 0.0f };
        dest.RelocateOffset(offset);
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_q12661_q12669_q12676_q12677_q12713_summon_stefan::SetDest, EFFECT_0, TARGET_DEST_CASTER_BACK);
    }
};

enum QuenchingMist
{
    SPELL_FLICKERING_FLAMES = 53504
};

// 53350 - Quenching Mist
class spell_q12730_quenching_mist : public AuraScript
{
    PrepareAuraScript(spell_q12730_quenching_mist);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FLICKERING_FLAMES });
    }

    void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_FLICKERING_FLAMES);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_q12730_quenching_mist::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
    }
};

// 13291 - Borrowed Technology/13292 - The Solution Solution /Daily//13239 - Volatility/13261 - Volatiliy /Daily//
enum Quest13291_13292_13239_13261Data
{
    // NPCs
    NPC_SKYTALON       = 31583,
    NPC_DECOY          = 31578,
    // Spells
    SPELL_RIDE         = 59319
};

// 59318 - Grab Fake Soldier
class spell_q13291_q13292_q13239_q13261_frostbrood_skytalon_grab_decoy : public SpellScript
{
    PrepareSpellScript(spell_q13291_q13292_q13239_q13261_frostbrood_skytalon_grab_decoy);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_RIDE });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (!GetHitCreature())
            return;
        // TO DO: Being triggered is hack, but in checkcast it doesn't pass aurastate requirements.
        // Beside that the decoy won't keep it's freeze animation state when enter.
        GetHitCreature()->CastSpell(GetCaster(), SPELL_RIDE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q13291_q13292_q13239_q13261_frostbrood_skytalon_grab_decoy::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 59303 - Summon Frost Wyrm
class spell_q13291_q13292_q13239_q13261_armored_decoy_summon_skytalon : public SpellScript
{
    PrepareSpellScript(spell_q13291_q13292_q13239_q13261_armored_decoy_summon_skytalon);

    void SetDest(SpellDestination& dest)
    {
        // Adjust effect summon position
        Position const offset = { 0.0f, 0.0f, 20.0f, 0.0f };
        dest.RelocateOffset(offset);
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_q13291_q13292_q13239_q13261_armored_decoy_summon_skytalon::SetDest, EFFECT_0, TARGET_DEST_CASTER_BACK);
    }
};

// 12601 - Second Chances: Summon Landgren's Soul Moveto Target Bunny
class spell_q12847_summon_soul_moveto_bunny : public SpellScript
{
    PrepareSpellScript(spell_q12847_summon_soul_moveto_bunny);

    void SetDest(SpellDestination& dest)
    {
        // Adjust effect summon position
        Position const offset = { 0.0f, 0.0f, 2.5f, 0.0f };
        dest.RelocateOffset(offset);
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_q12847_summon_soul_moveto_bunny::SetDest, EFFECT_0, TARGET_DEST_CASTER);
    }
};

enum BearFlankMaster
{
    SPELL_CREATE_BEAR_FLANK = 56566,
    SPELL_BEAR_FLANK_FAIL   = 56569
};

// 56565 - Bear Flank Master
class spell_q13011_bear_flank_master : public SpellScript
{
    PrepareSpellScript(spell_q13011_bear_flank_master);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_CREATE_BEAR_FLANK,
            SPELL_BEAR_FLANK_FAIL
        });
    }

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Player* player = GetHitPlayer())
        {
            if (roll_chance_i(50))
            {
                Creature* creature = GetCaster()->ToCreature();
                player->CastSpell(creature, SPELL_BEAR_FLANK_FAIL);
                creature->AI()->Talk(0, player);
            }
            else
                player->CastSpell(player, SPELL_CREATE_BEAR_FLANK);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q13011_bear_flank_master::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 57385 - Argent Cannon
// 57412 - Reckoning Bomb
class spell_q13086_cannons_target : public SpellScript
{
    PrepareSpellScript(spell_q13086_cannons_target);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ static_cast<uint32>(spellInfo->Effects[EFFECT_0].CalcValue()) });
    }

    void HandleEffectDummy(SpellEffIndex /*effIndex*/)
    {
        if (WorldLocation const* pos = GetExplTargetDest())
            GetCaster()->CastSpell(pos->GetPosition(), GetEffectValue(), true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_q13086_cannons_target::HandleEffectDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

enum BurstAtTheSeams
{
    AREA_THE_BROKEN_FRONT                       =  4507,
    AREA_MORD_RETHAR_THE_DEATH_GATE             =  4508,

    NPC_DRAKKARI_CHIEFTAINK                     = 29099,
    NPC_ICY_GHOUL                               = 31142,
    NPC_VICIOUS_GEIST                           = 31147,
    NPC_RISEN_ALLIANCE_SOLDIERS                 = 31205,
    NPC_RENIMATED_ABOMINATION                   = 31692,

    QUEST_FUEL_FOR_THE_FIRE                     = 12690,

    SPELL_BLOATED_ABOMINATION_FEIGN_DEATH       = 52593,
    SPELL_BURST_AT_THE_SEAMS_BONE               = 52516,
    SPELL_EXPLODE_ABOMINATION_MEAT              = 52520,
    SPELL_EXPLODE_ABOMINATION_BLOODY_MEAT       = 52523,
    SPELL_TROLL_EXPLOSION                       = 52565,
    SPELL_EXPLODE_TROLL_MEAT                    = 52578,
    SPELL_EXPLODE_TROLL_BLOODY_MEAT             = 52580,

    SPELL_BURST_AT_THE_SEAMS_59576              = 59576, //script/knockback, That's Abominable
    SPELL_BURST_AT_THE_SEAMS_59579              = 59579, //dummy
    SPELL_BURST_AT_THE_SEAMS_52510              = 52510, //script/knockback, Fuel for the Fire
    SPELL_BURST_AT_THE_SEAMS_52508              = 52508, //damage 20000
    SPELL_BURST_AT_THE_SEAMS_59580              = 59580, //damage 50000

    SPELL_ASSIGN_GHOUL_KILL_CREDIT_TO_MASTER    = 59590,
    SPELL_ASSIGN_GEIST_KILL_CREDIT_TO_MASTER    = 60041,
    SPELL_ASSIGN_SKELETON_KILL_CREDIT_TO_MASTER = 60039,

    SPELL_DRAKKARI_SKULLCRUSHER_CREDIT          = 52590,
    SPELL_SUMMON_DRAKKARI_CHIEFTAIN             = 52616,
    SPELL_DRAKKARI_CHIEFTAINK_KILL_CREDIT       = 52620
};

// 59576 - Burst at the Seams
class spell_q13264_q13276_q13288_q13289_burst_at_the_seams_59576 : public SpellScript
{
    PrepareSpellScript(spell_q13264_q13276_q13288_q13289_burst_at_the_seams_59576);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_BURST_AT_THE_SEAMS_59576,
            SPELL_BLOATED_ABOMINATION_FEIGN_DEATH,
            SPELL_BURST_AT_THE_SEAMS_59579,
            SPELL_BURST_AT_THE_SEAMS_BONE,
            SPELL_EXPLODE_ABOMINATION_MEAT,
            SPELL_EXPLODE_ABOMINATION_BLOODY_MEAT
        });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Creature* creature = GetCaster()->ToCreature())
        {
            creature->CastSpell(creature, SPELL_BLOATED_ABOMINATION_FEIGN_DEATH, true);
            creature->CastSpell(creature, SPELL_BURST_AT_THE_SEAMS_59579, true);
            creature->CastSpell(creature, SPELL_BURST_AT_THE_SEAMS_BONE, true);
            creature->CastSpell(creature, SPELL_BURST_AT_THE_SEAMS_BONE, true);
            creature->CastSpell(creature, SPELL_BURST_AT_THE_SEAMS_BONE, true);
            creature->CastSpell(creature, SPELL_EXPLODE_ABOMINATION_MEAT, true);
            creature->CastSpell(creature, SPELL_EXPLODE_ABOMINATION_BLOODY_MEAT, true);
            creature->CastSpell(creature, SPELL_EXPLODE_ABOMINATION_BLOODY_MEAT, true);
            creature->CastSpell(creature, SPELL_EXPLODE_ABOMINATION_BLOODY_MEAT, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q13264_q13276_q13288_q13289_burst_at_the_seams_59576::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 59579 - Burst at the Seams
class spell_q13264_q13276_q13288_q13289_burst_at_the_seams_59579 : public AuraScript
{
    PrepareAuraScript(spell_q13264_q13276_q13288_q13289_burst_at_the_seams_59579);

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->CastSpell(target, SPELL_TROLL_EXPLOSION, true);
        target->CastSpell(target, SPELL_EXPLODE_ABOMINATION_MEAT, true);
        target->CastSpell(target, SPELL_EXPLODE_TROLL_MEAT, true);
        target->CastSpell(target, SPELL_EXPLODE_TROLL_MEAT, true);
        target->CastSpell(target, SPELL_EXPLODE_TROLL_BLOODY_MEAT, true);
        target->CastSpell(target, SPELL_BURST_AT_THE_SEAMS_BONE, true);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (Unit* caster = GetCaster())
        {
            switch (target->GetEntry())
            {
                case NPC_ICY_GHOUL:
                    target->CastSpell(caster, SPELL_ASSIGN_GHOUL_KILL_CREDIT_TO_MASTER, true);
                    break;
                case NPC_VICIOUS_GEIST:
                    target->CastSpell(caster, SPELL_ASSIGN_GEIST_KILL_CREDIT_TO_MASTER, true);
                    break;
                case NPC_RISEN_ALLIANCE_SOLDIERS:
                    target->CastSpell(caster, SPELL_ASSIGN_SKELETON_KILL_CREDIT_TO_MASTER, true);
                    break;
            }
        }
        target->CastSpell(target, SPELL_BURST_AT_THE_SEAMS_59580, true);
    }

    void Register() override
    {
        AfterEffectApply  += AuraEffectApplyFn(spell_q13264_q13276_q13288_q13289_burst_at_the_seams_59579::HandleApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectApplyFn(spell_q13264_q13276_q13288_q13289_burst_at_the_seams_59579::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 52593 - Bloated Abomination Feign Death
class spell_q13264_q13276_q13288_q13289_bloated_abom_feign_death : public AuraScript
{
    PrepareAuraScript(spell_q13264_q13276_q13288_q13289_bloated_abom_feign_death);

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_DEAD);
        target->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH);

        if (Creature* creature = target->ToCreature())
            creature->SetReactState(REACT_PASSIVE);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (Creature* creature = target->ToCreature())
            creature->DespawnOrUnsummon();
    }

    void Register() override
    {
        AfterEffectApply  += AuraEffectApplyFn(spell_q13264_q13276_q13288_q13289_bloated_abom_feign_death::HandleApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectApplyFn(spell_q13264_q13276_q13288_q13289_bloated_abom_feign_death::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 76245 - Area Restrict Abom
class spell_q13264_q13276_q13288_q13289_area_restrict_abom : public SpellScript
{
    PrepareSpellScript(spell_q13264_q13276_q13288_q13289_area_restrict_abom);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Creature* creature = GetHitCreature()) {
            uint32 area = creature->GetAreaId();
            if (area != AREA_THE_BROKEN_FRONT && area != AREA_MORD_RETHAR_THE_DEATH_GATE)
                creature->DespawnOrUnsummon();
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q13264_q13276_q13288_q13289_area_restrict_abom::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 59590 - Assign Ghoul Kill Credit to Master
// 60039 - Assign Skeleton Kill Credit to Master
// 60041 - Assign Geist Kill Credit to Master
class spell_q13264_q13276_q13288_q13289_assign_credit_to_master : public SpellScript
{
    PrepareSpellScript(spell_q13264_q13276_q13288_q13289_assign_credit_to_master);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
        {
            if (Unit* owner = target->GetOwner())
            {
                owner->CastSpell(owner, GetEffectValue(), true);
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q13264_q13276_q13288_q13289_assign_credit_to_master::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 52510 - Burst at the Seams
class spell_q12690_burst_at_the_seams_52510 : public SpellScript
{
    PrepareSpellScript(spell_q12690_burst_at_the_seams_52510);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_BURST_AT_THE_SEAMS_52510,
            SPELL_BURST_AT_THE_SEAMS_52508,
            SPELL_BURST_AT_THE_SEAMS_59580,
            SPELL_BURST_AT_THE_SEAMS_BONE,
            SPELL_EXPLODE_ABOMINATION_MEAT,
            SPELL_EXPLODE_ABOMINATION_BLOODY_MEAT
        });
    }

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    void HandleKnockBack(SpellEffIndex /*effIndex*/)
    {
        if (Unit* creature = GetHitCreature())
        {
            if (Unit* charmer = GetCaster()->GetCharmerOrOwner())
            {
                if (Player* player = charmer->ToPlayer())
                {
                    if (player->GetQuestStatus(QUEST_FUEL_FOR_THE_FIRE) == QUEST_STATUS_INCOMPLETE)
                    {
                        creature->CastSpell(creature, SPELL_BURST_AT_THE_SEAMS_BONE, true);
                        creature->CastSpell(creature, SPELL_EXPLODE_ABOMINATION_MEAT, true);
                        creature->CastSpell(creature, SPELL_EXPLODE_ABOMINATION_BLOODY_MEAT, true);
                        creature->CastSpell(creature, SPELL_BURST_AT_THE_SEAMS_52508, true);
                        creature->CastSpell(creature, SPELL_BURST_AT_THE_SEAMS_59580, true);

                        player->CastSpell(player, SPELL_DRAKKARI_SKULLCRUSHER_CREDIT, true);
                        uint16 count = player->GetReqKillOrCastCurrentCount(QUEST_FUEL_FOR_THE_FIRE, NPC_DRAKKARI_CHIEFTAINK);
                        if ((count % 20) == 0)
                            player->CastSpell(player, SPELL_SUMMON_DRAKKARI_CHIEFTAIN, true);
                    }
                }
            }
        }
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->ToCreature()->DespawnOrUnsummon(2s);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q12690_burst_at_the_seams_52510::HandleKnockBack, EFFECT_1, SPELL_EFFECT_KNOCK_BACK);
        OnEffectHitTarget += SpellEffectFn(spell_q12690_burst_at_the_seams_52510::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum EscapeFromSilverbrook
{
    SPELL_SUMMON_WORGEN = 48681
};

// 48682 - Escape from Silverbrook - Periodic Dummy
class spell_q12308_escape_from_silverbrook : public SpellScript
{
    PrepareSpellScript(spell_q12308_escape_from_silverbrook);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_WORGEN });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_SUMMON_WORGEN, true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_q12308_escape_from_silverbrook::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 48681 - Summon Silverbrook Worgen
class spell_q12308_escape_from_silverbrook_summon_worgen : public SpellScript
{
    PrepareSpellScript(spell_q12308_escape_from_silverbrook_summon_worgen);

    void ModDest(SpellDestination& dest)
    {
        float dist = GetSpellInfo()->Effects[EFFECT_0].CalcRadius(GetCaster());
        float angle = frand(0.75f, 1.25f) * float(M_PI);

        Position pos = GetCaster()->GetNearPosition(dist, angle);
        dest.Relocate(pos);
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_q12308_escape_from_silverbrook_summon_worgen::ModDest, EFFECT_0, TARGET_DEST_CASTER_SUMMON);
    }
};

enum BasicOrdersEmote
{
    SPELL_TEST_SALUTE        = 73835,
    SPELL_TEST_ROAR          = 73836,
    SPELL_TEST_CHEER         = 73725,
    SPELL_TEST_DANCE         = 73837,
    SPELL_TEST_STOP_DANCE    = 73886
};

/* 73725 - [DND] Test Cheer
   73835 - [DND] Test Salute
   73836 - [DND] Test Roar
   73837 - [DND] Test Dance
   73886 - [DND] Test Stop Dance */
class spell_q25199_emote : public AuraScript
{
    PrepareAuraScript(spell_q25199_emote);

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();

        switch (GetSpellInfo()->Id)
        {
            case SPELL_TEST_SALUTE:
                target->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE);
                break;
            case SPELL_TEST_ROAR:
                target->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                break;
            case SPELL_TEST_CHEER:
                target->HandleEmoteCommand(EMOTE_ONESHOT_CHEER);
                break;
            case SPELL_TEST_DANCE:
                target->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_DANCE);
                break;
            case SPELL_TEST_STOP_DANCE:
                target->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_NONE);
                break;
            default:
                return;
        }
        Remove();
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_q25199_emote::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

enum DeathComesFromOnHigh
{
    SPELL_FORGE_CREDIT                  = 51974,
    SPELL_TOWN_HALL_CREDIT              = 51977,
    SPELL_SCARLET_HOLD_CREDIT           = 51980,
    SPELL_CHAPEL_CREDIT                 = 51982,

    NPC_NEW_AVALON_FORGE                = 28525,
    NPC_NEW_AVALON_TOWN_HALL            = 28543,
    NPC_SCARLET_HOLD                    = 28542,
    NPC_CHAPEL_OF_THE_CRIMSON_FLAME     = 28544
};

// 51858 - Siphon of Acherus
class spell_q12641_death_comes_from_on_high : public SpellScript
{
    PrepareSpellScript(spell_q12641_death_comes_from_on_high);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_FORGE_CREDIT,
            SPELL_TOWN_HALL_CREDIT,
            SPELL_SCARLET_HOLD_CREDIT,
            SPELL_CHAPEL_CREDIT
        });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        uint32 spellId = 0;

        switch (GetHitCreature()->GetEntry())
        {
            case NPC_NEW_AVALON_FORGE:
                spellId = SPELL_FORGE_CREDIT;
                break;
            case NPC_NEW_AVALON_TOWN_HALL:
                spellId = SPELL_TOWN_HALL_CREDIT;
                break;
            case NPC_SCARLET_HOLD:
                spellId = SPELL_SCARLET_HOLD_CREDIT;
                break;
            case NPC_CHAPEL_OF_THE_CRIMSON_FLAME:
                spellId = SPELL_CHAPEL_CREDIT;
                break;
            default:
                return;
        }

        GetCaster()->CastSpell(nullptr, spellId, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q12641_death_comes_from_on_high::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

enum Recall_Eye_of_Acherus
{
    THE_EYE_OF_ACHERUS = 51852
};

// 52694 - Recall Eye of Acherus
class spell_q12641_recall_eye_of_acherus : public SpellScript
{
    PrepareSpellScript(spell_q12641_recall_eye_of_acherus);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Player* player = GetCaster()->GetCharmerOrOwner()->ToPlayer())
        {
            player->StopCastingCharm();
            player->StopCastingBindSight();
            player->RemoveAura(THE_EYE_OF_ACHERUS);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q12641_recall_eye_of_acherus::HandleDummy, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 51769 - Emblazon Runeblade
class spell_q12619_emblazon_runeblade : public AuraScript
{
    PrepareAuraScript(spell_q12619_emblazon_runeblade);

    void HandleEffectPeriodic(AuraEffect const* aurEff)
    {
        PreventDefaultAction();
        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell, aurEff);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_q12619_emblazon_runeblade::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 51770 - Emblazon Runeblade
class spell_q12619_emblazon_runeblade_effect : public SpellScript
{
    PrepareSpellScript(spell_q12619_emblazon_runeblade_effect);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetCaster(), uint32(GetEffectValue()), false);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_q12619_emblazon_runeblade_effect::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum Quest_The_Storm_King
{
    SPELL_RIDE_GYMER            = 43671,
    SPELL_GRABBED               = 55424
};

// 55516 - Gymer's Grab
class spell_q12919_gymers_grab : public SpellScript
{
    PrepareSpellScript(spell_q12919_gymers_grab);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_RIDE_GYMER });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (!GetHitCreature())
            return;
        CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
        args.AddSpellBP0(2);
        GetHitCreature()->CastSpell(GetCaster(), SPELL_RIDE_GYMER, args);
        GetHitCreature()->CastSpell(GetHitCreature(), SPELL_GRABBED, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q12919_gymers_grab::HandleScript, EFFECT_0,  SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum Quest_The_Storm_King_Throw
{
    SPELL_VARGUL_EXPLOSION      = 55569
};

// 55421 - Gymer's Throw
class spell_q12919_gymers_throw : public SpellScript
{
   PrepareSpellScript(spell_q12919_gymers_throw);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (caster->IsVehicle())
            if (Unit* passenger = caster->GetVehicleKit()->GetPassenger(1))
            {
                 passenger->ExitVehicle();
                 caster->CastSpell(passenger, SPELL_VARGUL_EXPLOSION, true);
            }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q12919_gymers_throw::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum Quest_The_Hunter_And_The_Prince
{
    SPELL_ILLIDAN_KILL_CREDIT      = 61748
};

// 61752 - Illidan Kill Credit Master
class spell_q13400_illidan_kill_master : public SpellScript
{
   PrepareSpellScript(spell_q13400_illidan_kill_master);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ILLIDAN_KILL_CREDIT });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (caster->IsVehicle())
            if (Unit* passenger = caster->GetVehicleKit()->GetPassenger(0))
                 passenger->CastSpell(passenger, SPELL_ILLIDAN_KILL_CREDIT, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q13400_illidan_kill_master::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

enum RelicOfTheEarthenRing
{
    SPELL_TOTEM_OF_THE_EARTHEN_RING = 66747
};

// 66744 - Make Player Destroy Totems
class spell_q14100_q14111_make_player_destroy_totems : public SpellScript
{
    PrepareSpellScript(spell_q14100_q14111_make_player_destroy_totems);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TOTEM_OF_THE_EARTHEN_RING });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Player* player = GetHitPlayer())
            player->CastSpell(player, SPELL_TOTEM_OF_THE_EARTHEN_RING, TRIGGERED_FULL_MASK); // ignore reagent cost, consumed by quest
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q14100_q14111_make_player_destroy_totems::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum Fumping
{
    SPELL_SUMMON_SAND_GNOME  = 39240,
    SPELL_SUMMON_BONE_SLICER = 39241
};

// 39238 - Fumping
class spell_q10929_fumping : public AuraScript
{
    PrepareAuraScript(spell_q10929_fumping);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_SAND_GNOME, SPELL_SUMMON_BONE_SLICER });
    }

    void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, urand(SPELL_SUMMON_SAND_GNOME, SPELL_SUMMON_BONE_SLICER), true);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_q10929_fumping::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 49285 - Hand Over Reins
class spell_q12414_hand_over_reins : public SpellScript
{
    PrepareSpellScript(spell_q12414_hand_over_reins);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Creature* caster = GetCaster()->ToCreature();
        GetHitUnit()->ExitVehicle();

        if (caster)
            caster->DespawnOrUnsummon();
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q12414_hand_over_reins::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 13790 13793 13811 13814 - Among the Champions
// 13665 13745 13750 13756 13761 13767 13772 13777 13782  13787 - The Grand Melee
class spell_q13665_q13790_bested_trigger : public SpellScript
{
    PrepareSpellScript(spell_q13665_q13790_bested_trigger);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit()->GetCharmerOrOwnerOrSelf();
        target->CastSpell(target, uint32(GetEffectValue()), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q13665_q13790_bested_trigger::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// herald of war and life without regret portal spells
// 59064 - Portal to Orgrimmar
// 59439 - Portal to Undercity
class spell_59064_59439_portals : public SpellScript
{
    PrepareSpellScript(spell_59064_59439_portals);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), uint32(GetEffectValue()));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_59064_59439_portals::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum ApplyHeatAndStir
{
    SPELL_SPURTS_AND_SMOKE    = 38594,
    SPELL_FAILED_MIX_1        = 43376,
    SPELL_FAILED_MIX_2        = 43378,
    SPELL_FAILED_MIX_3        = 43970,
    SPELL_SUCCESSFUL_MIX      = 43377,

    CREATURE_GENERIC_TRIGGER_LAB = 24042,

    TALK_0 = 0,
    TALK_1 = 1
};

// 43972 - Mixing Blood
class spell_q11306_mixing_blood : public SpellScript
{
    PrepareSpellScript(spell_q11306_mixing_blood);

    void HandleEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            if (Creature* trigger = caster->FindNearestCreature(CREATURE_GENERIC_TRIGGER_LAB, 100.0f))
                trigger->AI()->DoCastSelf(SPELL_SPURTS_AND_SMOKE);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_q11306_mixing_blood::HandleEffect, EFFECT_1, SPELL_EFFECT_SEND_EVENT);
    }
};

// 43375 - Mixing Vrykul Blood
class spell_q11306_mixing_vrykul_blood : public SpellScript
{
    PrepareSpellScript(spell_q11306_mixing_vrykul_blood);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
        {
            uint8 chance = urand(0, 99);
            uint32 spellId = 0;

            // 90% chance of getting one out of three failure effects
            if (chance < 30)
                spellId = SPELL_FAILED_MIX_1;
            else if (chance < 60)
                spellId = SPELL_FAILED_MIX_2;
            else if (chance < 90)
                spellId = SPELL_FAILED_MIX_3;
            else // 10% chance of successful cast
                spellId = SPELL_SUCCESSFUL_MIX;

            caster->CastSpell(caster, spellId, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q11306_mixing_vrykul_blood::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

// 43376 - Failed Mix
class spell_q11306_failed_mix_43376 : public SpellScript
{
    PrepareSpellScript(spell_q11306_failed_mix_43376);

    void HandleEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            if (Creature* trigger = caster->FindNearestCreature(CREATURE_GENERIC_TRIGGER_LAB, 100.0f))
                trigger->AI()->Talk(TALK_0, caster);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_q11306_failed_mix_43376::HandleEffect, EFFECT_1, SPELL_EFFECT_SEND_EVENT);
    }
};

// 43378 - Failed Mix
class spell_q11306_failed_mix_43378 : public SpellScript
{
    PrepareSpellScript(spell_q11306_failed_mix_43378);

    void HandleEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            if (Creature* trigger = caster->FindNearestCreature(CREATURE_GENERIC_TRIGGER_LAB, 100.0f))
                trigger->AI()->Talk(TALK_1, caster);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_q11306_failed_mix_43378::HandleEffect, EFFECT_2, SPELL_EFFECT_SEND_EVENT);
    }
};

// 46444 - Weakness to Lightning: Cast on Master Script Effect
class spell_q11896_weakness_to_lightning_46444 : public SpellScript
{
    PrepareSpellScript(spell_q11896_weakness_to_lightning_46444);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
        {
            if (Unit* owner = target->GetOwner())
            {
                target->CastSpell(owner, GetEffectValue(), true);
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_q11896_weakness_to_lightning_46444::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_quest_spell_scripts()
{
    new spell_q55_sacred_cleansing();
    RegisterSpellScript(spell_q1846_bending_shinbone);
    RegisterSpellScript(spell_q2203_thaumaturgy_channel);
    RegisterSpellScript(spell_q5206_test_fetid_skull);
    RegisterSpellScript(spell_q6124_6129_apply_salve);
    new spell_q10255_administer_antidote();
    RegisterSpellScript(spell_q11396_11399_force_shield_arcane_purple_x3);
    RegisterSpellScript(spell_q11396_11399_scourging_crystal_controller);
    RegisterSpellScript(spell_q11396_11399_scourging_crystal_controller_dummy);
    new spell_q11515_fel_siphon_dummy();
    RegisterSpellScript(spell_q11587_arcane_prisoner_rescue);
    RegisterSpellScript(spell_q11730_ultrasonic_screwdriver);
    RegisterSpellScript(spell_q12459_seeds_of_natures_wrath);
    RegisterSpellScript(spell_q12634_despawn_fruit_tosser);
    RegisterSpellScript(spell_q12683_take_sputum_sample);
    RegisterSpellScript(spell_q12851_going_bearback);
    RegisterSpellScript(spell_q10041_q10040_who_are_they);
    RegisterSpellScript(spell_q12659_ahunaes_knife);
    RegisterSpellScript(spell_q9874_liquid_fire);
    RegisterSpellScript(spell_q12805_lifeblood_dummy);
    RegisterSpellScript(spell_q13280_13283_plant_battle_standard);
    RegisterSpellScript(spell_q13280_13283_jump_jets);
    RegisterSpellScript(spell_q14112_14145_chum_the_water);
    RegisterSpellScript(spell_q9452_cast_net);
    RegisterSpellScript(spell_q14076_14092_pound_drum);
    RegisterSpellScript(spell_q12987_read_pronouncement);
    RegisterSpellScript(spell_q12277_wintergarde_mine_explosion);
    RegisterSpellScript(spell_q12066_bunny_kill_credit);
    RegisterSpellScript(spell_q12735_song_of_cleansing);
    RegisterSpellScript(spell_q12372_cast_from_gossip_trigger);
    RegisterSpellScript(spell_q12372_destabilize_azure_dragonshrine_dummy);
    RegisterSpellScript(spell_q11010_q11102_q11023_aggro_check_aura);
    RegisterSpellScript(spell_q11010_q11102_q11023_aggro_check);
    RegisterSpellScript(spell_q11010_q11102_q11023_aggro_burst);
    RegisterSpellScript(spell_q11010_q11102_q11023_choose_loc);
    RegisterSpellScript(spell_q11010_q11102_q11023_q11008_check_fly_mount);
    RegisterSpellScript(spell_q11140salvage_wreckage);
    RegisterSpellScript(spell_q12372_azure_on_death_force_whisper);
    RegisterSpellScript(spell_q12527_zuldrak_rat);
    RegisterSpellScript(spell_q12661_q12669_q12676_q12677_q12713_summon_stefan);
    RegisterSpellScript(spell_q12730_quenching_mist);
    RegisterSpellScript(spell_q13291_q13292_q13239_q13261_frostbrood_skytalon_grab_decoy);
    RegisterSpellScript(spell_q13291_q13292_q13239_q13261_armored_decoy_summon_skytalon);
    RegisterSpellScript(spell_q12847_summon_soul_moveto_bunny);
    RegisterSpellScript(spell_q13011_bear_flank_master);
    RegisterSpellScript(spell_q13086_cannons_target);
    RegisterSpellScript(spell_q13264_q13276_q13288_q13289_burst_at_the_seams_59576);
    RegisterSpellScript(spell_q13264_q13276_q13288_q13289_burst_at_the_seams_59579);
    RegisterSpellScript(spell_q13264_q13276_q13288_q13289_bloated_abom_feign_death);
    RegisterSpellScript(spell_q13264_q13276_q13288_q13289_area_restrict_abom);
    RegisterSpellScript(spell_q13264_q13276_q13288_q13289_assign_credit_to_master);
    RegisterSpellScript(spell_q12690_burst_at_the_seams_52510);
    RegisterSpellScript(spell_q11896_weakness_to_lightning_46444);
    RegisterSpellScript(spell_q12308_escape_from_silverbrook_summon_worgen);
    RegisterSpellScript(spell_q12308_escape_from_silverbrook);
    RegisterSpellScript(spell_q25199_emote);
    RegisterSpellScript(spell_q12641_death_comes_from_on_high);
    RegisterSpellScript(spell_q12641_recall_eye_of_acherus);
    RegisterSpellScript(spell_q12619_emblazon_runeblade);
    RegisterSpellScript(spell_q12619_emblazon_runeblade_effect);
    RegisterSpellScript(spell_q12919_gymers_grab);
    RegisterSpellScript(spell_q12919_gymers_throw);
    RegisterSpellScript(spell_q13400_illidan_kill_master);
    RegisterSpellScript(spell_q14100_q14111_make_player_destroy_totems);
    RegisterSpellScript(spell_q10929_fumping);
    RegisterSpellScript(spell_q12414_hand_over_reins);
    RegisterSpellScript(spell_q13665_q13790_bested_trigger);
    RegisterSpellScript(spell_59064_59439_portals);
    RegisterSpellScript(spell_q11306_mixing_blood);
    RegisterSpellScript(spell_q11306_mixing_vrykul_blood);
    RegisterSpellScript(spell_q11306_failed_mix_43376);
    RegisterSpellScript(spell_q11306_failed_mix_43378);
}
