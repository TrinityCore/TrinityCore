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
 * Scripts for spells with SPELLFAMILY_GENERIC spells used for quests.
 * Ordered alphabetically using questId and scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_q#questID_".
 */

#include "ScriptPCH.h"

class spell_generic_quest_update_entry_SpellScript : public SpellScript
{
private:
    uint32 _spellEffect;
    uint8 _effIndex;
    uint32 _originalEntry;
    uint32 _newEntry;
    bool _shouldAttack;
    uint32 _despawnTime;

public:
    spell_generic_quest_update_entry_SpellScript(uint32 spellEffect, uint8 effIndex, uint32 originalEntry, uint32 newEntry, bool shouldAttack, uint32 despawnTime = 0) :
        SpellScript(), _spellEffect(spellEffect), _effIndex(effIndex), _originalEntry(originalEntry),
        _newEntry(newEntry), _shouldAttack(shouldAttack), _despawnTime(despawnTime) { }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Creature* pCreatureTarget = GetHitCreature())
            if (!pCreatureTarget->isPet() && pCreatureTarget->GetEntry() == _originalEntry)
            {
                pCreatureTarget->UpdateEntry(_newEntry);
                if (_shouldAttack && pCreatureTarget->IsAIEnabled)
                    pCreatureTarget->AI()->AttackStart(GetCaster());

                if (_despawnTime)
                    pCreatureTarget->ForcedDespawn(_despawnTime);
            }
    }

    void Register()
    {
        OnEffect += SpellEffectFn(spell_generic_quest_update_entry_SpellScript::HandleDummy, _effIndex, _spellEffect);
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
        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            if (!sSpellStore.LookupEntry(SPELL_CREATE_RESONATING_SKULL))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_CREATE_BONE_DUST))
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
            OnEffect += SpellEffectFn(spell_q5206_test_fetid_skull_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
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
        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (GetCastItem())
                if (Player* pCaster = GetCaster()->ToPlayer())
                    if (Creature* pCreatureTarget = GetHitCreature())
                    {
                        uint32 uiNewEntry = 0;
                        switch (pCaster->GetTeam())
                        {
                            case HORDE:
                                if (pCreatureTarget->GetEntry() == NPC_SICKLY_GAZELLE)
                                    uiNewEntry = NPC_CURED_GAZELLE;
                                break;
                            case ALLIANCE:
                                if (pCreatureTarget->GetEntry() == NPC_SICKLY_DEER)
                                    uiNewEntry = NPC_CURED_DEER;
                                break;
                        }
                        if (uiNewEntry)
                        {
                            pCreatureTarget->UpdateEntry(uiNewEntry);
                            pCreatureTarget->ForcedDespawn(DESPAWN_TIME);
                        }
                    }
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_q6124_6129_apply_salve_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
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
        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            if (!sSpellStore.LookupEntry(SPELL_SUMMON_ARCANE_PRISONER_MALE))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_SUMMON_ARCANE_PRISONER_FEMALE))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_ARCANE_PRISONER_KILL_CREDIT))
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
            OnEffect += SpellEffectFn(spell_q11587_arcane_prisoner_rescue_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
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
        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            if (!sSpellStore.LookupEntry(SPELL_SUMMON_SCAVENGEBOT_004A8))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_SUMMON_SENTRYBOT_57K))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_SUMMON_DEFENDOTANK_66D))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_SUMMON_SCAVENGEBOT_005B6))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_SUMMON_55D_COLLECTATRON))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_ROBOT_KILL_CREDIT))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Item *castItem = GetCastItem();
            if (!castItem)
                return;

            Unit* pCaster = GetCaster();
            if (pCaster->GetTypeId() != TYPEID_PLAYER)
                return;

            Creature* pTarget = GetHitCreature();
            if (!pTarget)
                return;

            uint32 spellId = 0;
            switch (pTarget->GetEntry())
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
            pTarget->ForcedDespawn();
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_q11730_ultrasonic_screwdriver_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript * GetSpellScript() const
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
        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Creature* pCreatureTarget = GetHitCreature())
            {
                uint32 uiNewEntry = 0;
                switch (pCreatureTarget->GetEntry())
                {
                    case NPC_REANIMATED_FROSTWYRM:  uiNewEntry = NPC_WEAK_REANIMATED_FROSTWYRM; break;
                    case NPC_TURGID:                uiNewEntry = NPC_WEAK_TURGID;               break;
                    case NPC_DEATHGAZE:             uiNewEntry = NPC_WEAK_DEATHGAZE;            break;
                }
                if (uiNewEntry)
                    pCreatureTarget->UpdateEntry(uiNewEntry);
            }
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_q12459_seeds_of_natures_wrath_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
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
        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            if (!sSpellStore.LookupEntry(SPELL_BANANAS_FALL_TO_GROUND))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_ORANGE_FALLS_TO_GROUND))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_PAPAYA_FALLS_TO_GROUND))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_SUMMON_ADVENTUROUS_DWARF))
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
            OnEffect += SpellEffectFn(spell_q12634_despawn_fruit_tosser_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
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
        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            uint32 reqAuraId = SpellMgr::CalculateSpellEffectAmount(GetSpellInfo(), 1);

            Unit* pCaster = GetCaster();
            if (pCaster->HasAuraEffect(reqAuraId, 0))
            {
                uint32 spellId = SpellMgr::CalculateSpellEffectAmount(GetSpellInfo(), 0);
                pCaster->CastSpell(pCaster, spellId, true, NULL);
            }
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_q12683_take_sputum_sample_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_q12683_take_sputum_sample_SpellScript();
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
        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            if (!sSpellStore.LookupEntry(SPELL_TRIGGER_AID_OF_THE_EARTHEN))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* pCaster = GetCaster();
            if (Player* pPlayer = pCaster->ToPlayer())
            {
                if(Creature* pTarget = GetHitCreature())
                {
                    pPlayer->CastSpell(pPlayer, SPELL_TRIGGER_AID_OF_THE_EARTHEN, true, NULL);
                    pPlayer->KilledMonsterCredit(NPC_FALLEN_EARTHEN_DEFENDER, 0);
                    pTarget->ForcedDespawn();
                }
            }
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_q12937_relief_for_the_fallen_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_q12937_relief_for_the_fallen_SpellScript();
    }
};

void AddSC_quest_spell_scripts()
{
    new spell_q55_sacred_cleansing();
    new spell_q5206_test_fetid_skull();
    new spell_q6124_6129_apply_salve();
    new spell_q10255_administer_antidote();
    new spell_q11515_fel_siphon_dummy();
    new spell_q11587_arcane_prisoner_rescue();
    new spell_q11730_ultrasonic_screwdriver();
    new spell_q12459_seeds_of_natures_wrath();
    new spell_q12634_despawn_fruit_tosser();
    new spell_q12683_take_sputum_sample();
    new spell_q12937_relief_for_the_fallen();
}
