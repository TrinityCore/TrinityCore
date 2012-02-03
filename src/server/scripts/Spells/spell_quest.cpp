/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "Vehicle.h"

class spell_generic_quest_update_entry_SpellScript : public SpellScript
{
    PrepareSpellScript(spell_generic_quest_update_entry_SpellScript)
private:
    uint16 _spellEffect;
    uint8 _effIndex;
    uint32 _originalEntry;
    uint32 _newEntry;
    bool _shouldAttack;
    uint32 _despawnTime;

public:
    spell_generic_quest_update_entry_SpellScript(uint16 spellEffect, uint8 effIndex, uint32 originalEntry, uint32 newEntry, bool shouldAttack, uint32 despawnTime = 0) :
        SpellScript(), _spellEffect(spellEffect), _effIndex(effIndex), _originalEntry(originalEntry),
        _newEntry(newEntry), _shouldAttack(shouldAttack), _despawnTime(despawnTime) { }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Creature* creatureTarget = GetHitCreature())
            if (!creatureTarget->isPet() && creatureTarget->GetEntry() == _originalEntry)
            {
                creatureTarget->UpdateEntry(_newEntry);
                if (_shouldAttack && creatureTarget->IsAIEnabled)
                    creatureTarget->AI()->AttackStart(GetCaster());

                if (_despawnTime)
                    creatureTarget->DespawnOrUnsummon(_despawnTime);
            }
    }

    void Register()
    {
        OnEffectHitTarget += SpellEffectFn(spell_generic_quest_update_entry_SpellScript::HandleDummy, _effIndex, _spellEffect);
    }
};

// http://www.wowhead.com/quest=55 Morbent Fel
// 8913 Sacred Cleansing
enum eQuest55Data
{
    NPC_MORBENT             = 1200,
    NPC_WEAKENED_MORBENT    = 24782,
};

class spell_q55_sacred_cleansing : public SpellScriptLoader
{
public:
    spell_q55_sacred_cleansing() : SpellScriptLoader("spell_q55_sacred_cleansing") { }

    SpellScript* GetSpellScript() const
    {
        return new spell_generic_quest_update_entry_SpellScript(SPELL_EFFECT_DUMMY, EFFECT_1, NPC_MORBENT, NPC_WEAKENED_MORBENT, true);
    }
};

// http://www.wowhead.com/quest=5206 Marauders of Darrowshire
// 17271 Test Fetid Skull
enum eQuest5206Data
{
    SPELL_CREATE_RESONATING_SKULL = 17269,
    SPELL_CREATE_BONE_DUST = 17270
};

class spell_q5206_test_fetid_skull : public SpellScriptLoader
{
public:
    spell_q5206_test_fetid_skull() : SpellScriptLoader("spell_q5206_test_fetid_skull") { }

    class spell_q5206_test_fetid_skull_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_q5206_test_fetid_skull_SpellScript)
        bool Validate(SpellInfo const* /*spellEntry*/)
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_CREATE_RESONATING_SKULL))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_CREATE_BONE_DUST))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* pCaster = GetCaster();
            if (pCaster->GetTypeId() == TYPEID_PLAYER)
            {
                uint32 spellId = roll_chance_i(50) ? SPELL_CREATE_RESONATING_SKULL : SPELL_CREATE_BONE_DUST;
                pCaster->CastSpell(pCaster, spellId, true, NULL);
            }
        }

        void Register()
        {
            OnEffectHit += SpellEffectFn(spell_q5206_test_fetid_skull_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_q5206_test_fetid_skull_SpellScript();
    }
};

// http://www.wowhead.com/quest=6124 Curing the Sick (A)
// http://www.wowhead.com/quest=6129 Curing the Sick (H)
// 19512 Apply Salve
enum eQuests6124_6129Data
{
    NPC_SICKLY_GAZELLE  = 12296,
    NPC_CURED_GAZELLE   = 12297,
    NPC_SICKLY_DEER     = 12298,
    NPC_CURED_DEER      = 12299,
    DESPAWN_TIME        = 30000
};

class spell_q6124_6129_apply_salve : public SpellScriptLoader
{
public:
    spell_q6124_6129_apply_salve() : SpellScriptLoader("spell_q6124_6129_apply_salve") { }

    class spell_q6124_6129_apply_salve_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_q6124_6129_apply_salve_SpellScript)
        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (GetCastItem())
                if (Player* pCaster = GetCaster()->ToPlayer())
                    if (Creature* creatureTarget = GetHitCreature())
                    {
                        uint32 uiNewEntry = 0;
                        switch (pCaster->GetTeam())
                        {
                            case HORDE:
                                if (creatureTarget->GetEntry() == NPC_SICKLY_GAZELLE)
                                    uiNewEntry = NPC_CURED_GAZELLE;
                                break;
                            case ALLIANCE:
                                if (creatureTarget->GetEntry() == NPC_SICKLY_DEER)
                                    uiNewEntry = NPC_CURED_DEER;
                                break;
                        }
                        if (uiNewEntry)
                        {
                            creatureTarget->UpdateEntry(uiNewEntry);
                            creatureTarget->DespawnOrUnsummon(DESPAWN_TIME);
                        }
                    }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_q6124_6129_apply_salve_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_q6124_6129_apply_salve_SpellScript();
    }
};

// http://www.wowhead.com/quest=10255 Testing the Antidote
// 34665 Administer Antidote
enum eQuest10255Data
{
    NPC_HELBOAR     = 16880,
    NPC_DREADTUSK   = 16992,
};

class spell_q10255_administer_antidote : public SpellScriptLoader
{
public:
    spell_q10255_administer_antidote() : SpellScriptLoader("spell_q10255_administer_antidote") { }

    SpellScript* GetSpellScript() const
    {
        return new spell_generic_quest_update_entry_SpellScript(SPELL_EFFECT_DUMMY, EFFECT_0, NPC_HELBOAR, NPC_DREADTUSK, true);
    }
};

// http://www.wowhead.com/quest=11396 Bring Down Those Shields (A)
// http://www.wowhead.com/quest=11399 Bring Down Those Shields (H)
enum eQuest11396_11399Data
{
    SPELL_FORCE_SHIELD_ARCANE_PURPLE_X3 = 43874,
    SPELL_SCOURGING_CRYSTAL_CONTROLLER = 43878
};

// 43874 Scourge Mur'gul Camp: Force Shield Arcane Purple x3
class spell_q11396_11399_force_shield_arcane_purple_x3 : public SpellScriptLoader
{
public:
    spell_q11396_11399_force_shield_arcane_purple_x3() : SpellScriptLoader("spell_q11396_11399_force_shield_arcane_purple_x3") { }

    class spell_q11396_11399_force_shield_arcane_purple_x3_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_q11396_11399_force_shield_arcane_purple_x3_AuraScript)
        void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* target = GetTarget();
            target->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
            target->AddUnitState(UNIT_STATE_ROOT);
        }

        void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            GetTarget()->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(spell_q11396_11399_force_shield_arcane_purple_x3_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_q11396_11399_force_shield_arcane_purple_x3_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }

    };

    AuraScript* GetAuraScript() const
    {
        return new spell_q11396_11399_force_shield_arcane_purple_x3_AuraScript();
    }
};

// 50133 Scourging Crystal Controller
class spell_q11396_11399_scourging_crystal_controller : public SpellScriptLoader
{
public:
    spell_q11396_11399_scourging_crystal_controller() : SpellScriptLoader("spell_q11396_11399_scourging_crystal_controller") { }

    class spell_q11396_11399_scourging_crystal_controller_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_q11396_11399_scourging_crystal_controller_SpellScript);
        bool Validate(SpellInfo const* /*spellEntry*/)
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_FORCE_SHIELD_ARCANE_PURPLE_X3))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_SCOURGING_CRYSTAL_CONTROLLER))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* target = GetTargetUnit())
                if (target->GetTypeId() == TYPEID_UNIT && target->HasAura(SPELL_FORCE_SHIELD_ARCANE_PURPLE_X3))
                    // Make sure nobody else is channeling the same target
                    if (!target->HasAura(SPELL_SCOURGING_CRYSTAL_CONTROLLER))
                        GetCaster()->CastSpell(target, SPELL_SCOURGING_CRYSTAL_CONTROLLER, true, GetCastItem());
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_q11396_11399_scourging_crystal_controller_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_q11396_11399_scourging_crystal_controller_SpellScript();
    };
};

// 43882 Scourging Crystal Controller Dummy
class spell_q11396_11399_scourging_crystal_controller_dummy : public SpellScriptLoader
{
public:
    spell_q11396_11399_scourging_crystal_controller_dummy() : SpellScriptLoader("spell_q11396_11399_scourging_crystal_controller_dummy") { }

    class spell_q11396_11399_scourging_crystal_controller_dummy_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_q11396_11399_scourging_crystal_controller_dummy_SpellScript);
        bool Validate(SpellInfo const* /*spellEntry*/)
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_FORCE_SHIELD_ARCANE_PURPLE_X3))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* target = GetTargetUnit())
                if (target->GetTypeId() == TYPEID_UNIT)
                    target->RemoveAurasDueToSpell(SPELL_FORCE_SHIELD_ARCANE_PURPLE_X3);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_q11396_11399_scourging_crystal_controller_dummy_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_q11396_11399_scourging_crystal_controller_dummy_SpellScript();
    };
};

// http://www.wowhead.com/quest=11515 Blood for Blood
// 44936 Quest - Fel Siphon Dummy
enum eQuest11515Data
{
    NPC_FELBLOOD_INITIATE   = 24918,
    NPC_EMACIATED_FELBLOOD  = 24955
};

class spell_q11515_fel_siphon_dummy : public SpellScriptLoader
{
public:
    spell_q11515_fel_siphon_dummy() : SpellScriptLoader("spell_q11515_fel_siphon_dummy") { }

    SpellScript* GetSpellScript() const
    {
        return new spell_generic_quest_update_entry_SpellScript(SPELL_EFFECT_DUMMY, EFFECT_0, NPC_FELBLOOD_INITIATE, NPC_EMACIATED_FELBLOOD, true);
    }
};

// http://www.wowhead.com/quest=11587 Prison Break
// 45449 Arcane Prisoner Rescue
enum eQuest11587Data
{
    SPELL_SUMMON_ARCANE_PRISONER_MALE    = 45446,    // Summon Arcane Prisoner - Male
    SPELL_SUMMON_ARCANE_PRISONER_FEMALE  = 45448,    // Summon Arcane Prisoner - Female
    SPELL_ARCANE_PRISONER_KILL_CREDIT    = 45456     // Arcane Prisoner Kill Credit
};

class spell_q11587_arcane_prisoner_rescue : public SpellScriptLoader
{
public:
    spell_q11587_arcane_prisoner_rescue() : SpellScriptLoader("spell_q11587_arcane_prisoner_rescue") { }

    class spell_q11587_arcane_prisoner_rescue_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_q11587_arcane_prisoner_rescue_SpellScript)
        bool Validate(SpellInfo const* /*spellEntry*/)
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_SUMMON_ARCANE_PRISONER_MALE))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_SUMMON_ARCANE_PRISONER_FEMALE))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_ARCANE_PRISONER_KILL_CREDIT))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (Unit* unitTarget = GetHitUnit())
            {
                uint32 spellId = SPELL_SUMMON_ARCANE_PRISONER_MALE;
                if (rand() % 2)
                    spellId = SPELL_SUMMON_ARCANE_PRISONER_FEMALE;
                caster->CastSpell(caster, spellId, true);
                unitTarget->CastSpell(caster, SPELL_ARCANE_PRISONER_KILL_CREDIT, true);
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_q11587_arcane_prisoner_rescue_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_q11587_arcane_prisoner_rescue_SpellScript();
    }
};

// http://www.wowhead.com/quest=11730 Master and Servant
// 46023 The Ultrasonic Screwdriver
enum eQuest11730Data
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

class spell_q11730_ultrasonic_screwdriver : public SpellScriptLoader
{
public:
    spell_q11730_ultrasonic_screwdriver() : SpellScriptLoader("spell_q11730_ultrasonic_screwdriver") { }

    class spell_q11730_ultrasonic_screwdriver_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_q11730_ultrasonic_screwdriver_SpellScript)
        bool Validate(SpellInfo const* /*spellEntry*/)
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_SUMMON_SCAVENGEBOT_004A8))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_SUMMON_SENTRYBOT_57K))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_SUMMON_DEFENDOTANK_66D))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_SUMMON_SCAVENGEBOT_005B6))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_SUMMON_55D_COLLECTATRON))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_ROBOT_KILL_CREDIT))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Item* castItem = GetCastItem();
            if (!castItem)
                return;

            Unit* pCaster = GetCaster();
            if (pCaster->GetTypeId() != TYPEID_PLAYER)
                return;

            Creature* target = GetHitCreature();
            if (!target)
                return;

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
            pCaster->CastSpell(pCaster, spellId, true, castItem);
            pCaster->CastSpell(pCaster, SPELL_ROBOT_KILL_CREDIT, true);
            target->DespawnOrUnsummon();
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_q11730_ultrasonic_screwdriver_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_q11730_ultrasonic_screwdriver_SpellScript();
    }
};

// http://www.wowhead.com/quest=12459 That Which Creates Can Also Destroy
// 49587 Seeds of Nature's Wrath
enum eQuest12459Data
{
    NPC_REANIMATED_FROSTWYRM        = 26841,
    NPC_WEAK_REANIMATED_FROSTWYRM   = 27821,

    NPC_TURGID                      = 27808,
    NPC_WEAK_TURGID                 = 27809,

    NPC_DEATHGAZE                   = 27122,
    NPC_WEAK_DEATHGAZE              = 27807,
};

class spell_q12459_seeds_of_natures_wrath : public SpellScriptLoader
{
public:
    spell_q12459_seeds_of_natures_wrath() : SpellScriptLoader("spell_q12459_seeds_of_natures_wrath") { }

    class spell_q12459_seeds_of_natures_wrath_SpellScript : public SpellScript
    {
    public:
        PrepareSpellScript(spell_q12459_seeds_of_natures_wrath_SpellScript)
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

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_q12459_seeds_of_natures_wrath_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_q12459_seeds_of_natures_wrath_SpellScript();
    }
};

// http://www.wowhead.com/quest=12634 Some Make Lemonade, Some Make Liquor
// 51840 Despawn Fruit Tosser
enum eQuest12634Data
{
    SPELL_BANANAS_FALL_TO_GROUND    = 51836,
    SPELL_ORANGE_FALLS_TO_GROUND    = 51837,
    SPELL_PAPAYA_FALLS_TO_GROUND    = 51839,
    SPELL_SUMMON_ADVENTUROUS_DWARF  = 52070
};

class spell_q12634_despawn_fruit_tosser : public SpellScriptLoader
{
public:
    spell_q12634_despawn_fruit_tosser() : SpellScriptLoader("spell_q12634_despawn_fruit_tosser") { }

    class spell_q12634_despawn_fruit_tosser_SpellScript : public SpellScript
    {
    public:
        PrepareSpellScript(spell_q12634_despawn_fruit_tosser_SpellScript)
        bool Validate(SpellInfo const* /*spellEntry*/)
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_BANANAS_FALL_TO_GROUND))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_ORANGE_FALLS_TO_GROUND))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_PAPAYA_FALLS_TO_GROUND))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_SUMMON_ADVENTUROUS_DWARF))
                return false;
            return true;
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
            GetCaster()->CastSpell(GetCaster(), spellId, true, NULL);
        }

        void Register()
        {
            OnEffectHit += SpellEffectFn(spell_q12634_despawn_fruit_tosser_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_q12634_despawn_fruit_tosser_SpellScript();
    }
};

// http://www.wowhead.com/quest=12683 Burning to Help
// 52308 Take Sputum Sample
class spell_q12683_take_sputum_sample : public SpellScriptLoader
{
public:
    spell_q12683_take_sputum_sample() : SpellScriptLoader("spell_q12683_take_sputum_sample") { }

    class spell_q12683_take_sputum_sample_SpellScript : public SpellScript
    {
    public:
        PrepareSpellScript(spell_q12683_take_sputum_sample_SpellScript)
        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            uint32 reqAuraId = GetSpellInfo()->Effects[EFFECT_1].CalcValue();

            Unit* pCaster = GetCaster();
            if (pCaster->HasAuraEffect(reqAuraId, 0))
            {
                uint32 spellId = GetSpellInfo()->Effects[EFFECT_0].CalcValue();
                pCaster->CastSpell(pCaster, spellId, true, NULL);
            }
        }

        void Register()
        {
            OnEffectHit += SpellEffectFn(spell_q12683_take_sputum_sample_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_q12683_take_sputum_sample_SpellScript();
    }
};

// http://www.wowhead.com/quest=12851 Going Bearback
// 54798 FLAMING Arrow Triggered Effect
enum eQuest12851Data
{
    NPC_FROSTGIANT = 29351,
    NPC_FROSTWORG  = 29358,
    SPELL_FROSTGIANT_CREDIT = 58184,
    SPELL_FROSTWORG_CREDIT  = 58183,
    SPELL_IMMOLATION        = 54690,
    SPELL_ABLAZE            = 54683,
};

class spell_q12851_going_bearback : public SpellScriptLoader
{
public:
    spell_q12851_going_bearback() : SpellScriptLoader("spell_q12851_going_bearback") { }

    class spell_q12851_going_bearback_AuraScript : public AuraScript
    {
    public:
        PrepareAuraScript(spell_q12851_going_bearback_AuraScript)
        void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
            {
                Unit* target = GetTarget();
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

        void Register()
        {
            AfterEffectApply += AuraEffectApplyFn(spell_q12851_going_bearback_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        }

    };

    AuraScript* GetAuraScript() const
    {
        return new spell_q12851_going_bearback_AuraScript();
    }
};

// http://www.wowhead.com/quest=12937 Relief for the Fallen
// 55804 Healing Finished
enum eQuest12937Data
{
    SPELL_TRIGGER_AID_OF_THE_EARTHEN    = 55809,
    NPC_FALLEN_EARTHEN_DEFENDER         = 30035,
};

class spell_q12937_relief_for_the_fallen : public SpellScriptLoader
{
public:
    spell_q12937_relief_for_the_fallen() : SpellScriptLoader("spell_q12937_relief_for_the_fallen") { }

    class spell_q12937_relief_for_the_fallen_SpellScript : public SpellScript
    {
    public:
        PrepareSpellScript(spell_q12937_relief_for_the_fallen_SpellScript)
        bool Validate(SpellInfo const* /*spellEntry*/)
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_TRIGGER_AID_OF_THE_EARTHEN))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* pCaster = GetCaster();
            if (Player* player = pCaster->ToPlayer())
            {
                if (Creature* target = GetHitCreature())
                {
                    player->CastSpell(player, SPELL_TRIGGER_AID_OF_THE_EARTHEN, true, NULL);
                    player->KilledMonsterCredit(NPC_FALLEN_EARTHEN_DEFENDER, 0);
                    target->DespawnOrUnsummon();
                }
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_q12937_relief_for_the_fallen_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_q12937_relief_for_the_fallen_SpellScript();
    }
};

enum eWhoarethey
{
    SPELL_QUESTGIVER = 48917,

    SPELL_MALE_DISGUISE = 38080,
    SPELL_FEMALE_DISGUISE = 38081,
    SPELL_GENERIC_DISGUISE = 32756
};

class spell_q10041_q10040_who_are_they : public SpellScriptLoader
{
    public:
        spell_q10041_q10040_who_are_they() : SpellScriptLoader("spell_q10041_q10040_who_are_they") { }

        class spell_q10041_q10040_who_are_they_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_q10041_q10040_who_are_they_SpellScript);

            bool Validate(SpellInfo const* /*spellEntry*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_QUESTGIVER))
                    return false;
                return true;
            }

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                if (!GetHitUnit() || !GetHitUnit()->ToPlayer())
                    return;

                GetHitUnit()->CastSpell(GetHitUnit(), GetHitUnit()->getGender() == GENDER_MALE ? SPELL_MALE_DISGUISE : SPELL_FEMALE_DISGUISE, true);
                GetHitUnit()->CastSpell(GetHitUnit(), SPELL_GENERIC_DISGUISE, true);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_q10041_q10040_who_are_they_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_q10041_q10040_who_are_they_SpellScript();
        }
};

enum symboloflife
{
    SPELL_PERMANENT_FEIGN_DEATH = 29266,
};

// 8593 Symbol of life dummy
class spell_symbol_of_life_dummy : public SpellScriptLoader
{
public:
    spell_symbol_of_life_dummy() : SpellScriptLoader("spell_symbol_of_life_dummy") { }

    class spell_symbol_of_life_dummy_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_symbol_of_life_dummy_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Creature* target = GetHitCreature())
            {
                if (target->HasAura(SPELL_PERMANENT_FEIGN_DEATH))
                {
                    target->RemoveAurasDueToSpell(SPELL_PERMANENT_FEIGN_DEATH);
                    target->SetUInt32Value(UNIT_DYNAMIC_FLAGS, 0);
                    target->SetUInt32Value(UNIT_FIELD_FLAGS_2, 0);
                    target->SetHealth(target->GetMaxHealth() / 2);
                    target->SetPower(POWER_MANA, uint32(target->GetMaxPower(POWER_MANA) * 0.75f));
                }
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_symbol_of_life_dummy_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_symbol_of_life_dummy_SpellScript();
    };
};

// http://www.wowhead.com/quest=12659 Scalps!
// 52090 Ahunae's Knife
enum eQuest12659Data
{
    NPC_SCALPS_KC_BUNNY = 28622,
};

class spell_q12659_ahunaes_knife : public SpellScriptLoader
{
public:
    spell_q12659_ahunaes_knife() : SpellScriptLoader("spell_q12659_ahunaes_knife") { }

    class spell_q12659_ahunaes_knife_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_q12659_ahunaes_knife_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Player* caster = GetCaster()->ToPlayer();
            if (!caster)
                return;

            if (Creature* target = GetTargetUnit()->ToCreature())
            {
                target->ForcedDespawn();
                caster->KilledMonsterCredit(NPC_SCALPS_KC_BUNNY, 0);
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_q12659_ahunaes_knife_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_q12659_ahunaes_knife_SpellScript();
    };
};

enum StoppingTheSpread
{
    NPC_VILLAGER_KILL_CREDIT                     = 18240,
    SPELL_FLAMES                                 = 39199,
};

class spell_q9874_liquid_fire : public SpellScriptLoader
{
    public:
        spell_q9874_liquid_fire() : SpellScriptLoader("spell_q9874_liquid_fire")
        {
        }

        class spell_q9874_liquid_fire_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_q9874_liquid_fire_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Player* caster = GetCaster()->ToPlayer();
                Creature* target = GetHitUnit()->ToCreature();
                if (!caster || !target || (target && target->HasAura(SPELL_FLAMES)))
                    return;

                caster->KilledMonsterCredit(NPC_VILLAGER_KILL_CREDIT, 0);
                target->CastSpell(target, SPELL_FLAMES, true);
                target->DespawnOrUnsummon(60000);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_q9874_liquid_fire_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_q9874_liquid_fire_SpellScript();
        };
};

enum SalvagingLifesStength
{
    NPC_SHARD_KILL_CREDIT                        = 29303,
};

class spell_q12805_lifeblood_dummy : public SpellScriptLoader
{
    public:
        spell_q12805_lifeblood_dummy() : SpellScriptLoader("spell_q12805_lifeblood_dummy")
        {
        }

        class spell_q12805_lifeblood_dummy_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_q12805_lifeblood_dummy_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Player* caster = GetCaster()->ToPlayer();
                Creature* target = GetHitUnit()->ToCreature();
                if (!caster || !target)
                    return;

                caster->KilledMonsterCredit(NPC_SHARD_KILL_CREDIT, 0);
                target->CastSpell(target, uint32(GetEffectValue()), true);
                target->DespawnOrUnsummon(2000);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_q12805_lifeblood_dummy_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_q12805_lifeblood_dummy_SpellScript();
        };
};

/*
 http://www.wowhead.com/quest=13283 King of the Mountain
 http://www.wowhead.com/quest=13280 King of the Mountain
 59643 Plant Horde Battle Standard
 4338 Plant Alliance Battle Standard
 */
enum eBattleStandard
{
    NPC_KING_OF_THE_MOUNTAINT_KC                    = 31766,
};

class spell_q13280_13283_plant_battle_standard: public SpellScriptLoader
{
public:
    spell_q13280_13283_plant_battle_standard() : SpellScriptLoader("spell_q13280_13283_plant_battle_standard") { }

    class spell_q13280_13283_plant_battle_standard_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_q13280_13283_plant_battle_standard_SpellScript)
        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (caster->IsVehicle())
                if (Unit* player = caster->GetVehicleKit()->GetPassenger(0))
                     player->ToPlayer()->KilledMonsterCredit(NPC_KING_OF_THE_MOUNTAINT_KC, 0);
        }

        void Register()
        {
            OnEffectHit += SpellEffectFn(spell_q13280_13283_plant_battle_standard_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_q13280_13283_plant_battle_standard_SpellScript();
    }
};

enum ChumTheWaterSummons
{
    SUMMON_ANGRY_KVALDIR = 66737,
    SUMMON_NORTH_SEA_MAKO = 66738,
    SUMMON_NORTH_SEA_THRESHER = 66739,
    SUMMON_NORTH_SEA_BLUE_SHARK = 66740
};

class spell_q14112_14145_chum_the_water: public SpellScriptLoader
{
public:
    spell_q14112_14145_chum_the_water() : SpellScriptLoader("spell_q14112_14145_chum_the_water") { }

    class spell_q14112_14145_chum_the_water_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_q14112_14145_chum_the_water_SpellScript);
    
        bool Validate(SpellInfo const* /*spellEntry*/)
        {
            if (!sSpellMgr->GetSpellInfo(SUMMON_ANGRY_KVALDIR))
                return false;
            if (!sSpellMgr->GetSpellInfo(SUMMON_NORTH_SEA_MAKO))
                return false;
            if (!sSpellMgr->GetSpellInfo(SUMMON_NORTH_SEA_THRESHER))
                return false;
            if (!sSpellMgr->GetSpellInfo(SUMMON_NORTH_SEA_BLUE_SHARK))
                return false;
            return true;
        }

        void HandleScriptEffect(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            caster->CastSpell(caster, RAND(SUMMON_ANGRY_KVALDIR, SUMMON_NORTH_SEA_MAKO, SUMMON_NORTH_SEA_THRESHER, SUMMON_NORTH_SEA_BLUE_SHARK));
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_q14112_14145_chum_the_water_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_q14112_14145_chum_the_water_SpellScript();
    }
};

// http://old01.wowhead.com/quest=9452 - Red Snapper - Very Tasty!
enum RedSnapperVeryTasty
{
    SPELL_CAST_NET      = 29866,
    ITEM_RED_SNAPPER    = 23614,
    NPC_ANGRY_MURLOC    = 17102,
};

class spell_q9452_cast_net: public SpellScriptLoader
{
    public:
        spell_q9452_cast_net() : SpellScriptLoader("spell_q9452_cast_net") { }

        class spell_q9452_cast_net_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_q9452_cast_net_SpellScript)

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Player* caster = GetCaster()->ToPlayer();

                if (!caster)
                    return;

                switch (urand(0, 2))
                {
                    case 0: case 1:
                        caster->AddItem(ITEM_RED_SNAPPER, 1);
                        break;
                    case 2:
                        if (Creature* murloc = caster->SummonCreature(NPC_ANGRY_MURLOC, caster->GetPositionX()+5, caster->GetPositionY(), caster->GetPositionZ(), 0.0f, TEMPSUMMON_MANUAL_DESPAWN, 120000))
                            murloc->AI()->AttackStart(caster);
                        break;
                }
            }

            void Register()
            {
                OnEffectHit += SpellEffectFn(spell_q9452_cast_net_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_q9452_cast_net_SpellScript();
        }
};

void AddSC_quest_spell_scripts()
{
    new spell_q55_sacred_cleansing();
    new spell_q5206_test_fetid_skull();
    new spell_q6124_6129_apply_salve();
    new spell_q10255_administer_antidote();
    new spell_q11396_11399_force_shield_arcane_purple_x3();
    new spell_q11396_11399_scourging_crystal_controller();
    new spell_q11396_11399_scourging_crystal_controller_dummy();
    new spell_q11515_fel_siphon_dummy();
    new spell_q11587_arcane_prisoner_rescue();
    new spell_q11730_ultrasonic_screwdriver();
    new spell_q12459_seeds_of_natures_wrath();
    new spell_q12634_despawn_fruit_tosser();
    new spell_q12683_take_sputum_sample();
    new spell_q12851_going_bearback();
    new spell_q12937_relief_for_the_fallen();
    new spell_q10041_q10040_who_are_they();
    new spell_symbol_of_life_dummy();
    new spell_q12659_ahunaes_knife();
    new spell_q9874_liquid_fire();
    new spell_q12805_lifeblood_dummy();
    new spell_q13280_13283_plant_battle_standard();
    new spell_q14112_14145_chum_the_water();
    new spell_q9452_cast_net();
}
