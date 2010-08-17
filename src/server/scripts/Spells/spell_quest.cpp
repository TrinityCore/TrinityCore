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

enum Quest11587Spells
{
    QUEST11587_SPELL_SUMMON_ARCANE_PRISONER_MALE    = 45446,    // Summon Arcane Prisoner - Male
    QUEST11587_SPELL_SUMMON_ARCANE_PRISONER_FEMALE  = 45448,    // Summon Arcane Prisoner - Female
    QUEST11587_SPELL_ARCANE_PRISONER_KILL_CREDIT    = 45456     // Arcane Prisoner Kill Credit
};

// http://www.wowhead.com/quest=11587 Prison Break
// 45449 Arcane Prisoner Rescue
class spell_q11587_arcane_prisoner_rescue : public SpellHandlerScript
{
public:
    spell_q11587_arcane_prisoner_rescue() : SpellHandlerScript("spell_q11587_arcane_prisoner_rescue") { }

    class spell_q11587_arcane_prisoner_rescue_SpellScript : public SpellScript
    {
        bool Validate(SpellEntry const * spellEntry)
        {
            if (!sSpellStore.LookupEntry(QUEST11587_SPELL_SUMMON_ARCANE_PRISONER_MALE))
                return false;
            if (!sSpellStore.LookupEntry(QUEST11587_SPELL_SUMMON_ARCANE_PRISONER_FEMALE))
                return false;
            if (!sSpellStore.LookupEntry(QUEST11587_SPELL_ARCANE_PRISONER_KILL_CREDIT))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex effIndex)
        {
            Unit* caster = GetCaster();
            if (Unit* unitTarget = GetHitUnit())
            {
                uint32 spellId = QUEST11587_SPELL_SUMMON_ARCANE_PRISONER_MALE;
                if (rand() % 2)
                    spellId = QUEST11587_SPELL_SUMMON_ARCANE_PRISONER_FEMALE;
                caster->CastSpell(caster, spellId, true);
                unitTarget->CastSpell(caster, QUEST11587_SPELL_ARCANE_PRISONER_KILL_CREDIT, true);
            }
        }

        void Register()
        {
            EffectHandlers += EffectHandlerFn(spell_q11587_arcane_prisoner_rescue_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_q11587_arcane_prisoner_rescue_SpellScript();
    }
};

enum Quest11730Spells
{
    SPELL_QUEST_SUMMON_SCAVENGEBOT_004A8    = 46063,
    SPELL_QUEST_SUMMON_SENTRYBOT_57K        = 46068,
    SPELL_QUEST_SUMMON_DEFENDOTANK_66D      = 46058,
    SPELL_QUEST_SUMMON_SCAVENGEBOT_005B6    = 46066,
    SPELL_QUEST_SUMMON_55D_COLLECTATRON     = 46034,
    SPELL_QUEST_ROBOT_KILL_CREDIT           = 46027,
    NPC_SCAVENGEBOT_004A8                   = 25752,
    NPC_SENTRYBOT_57K                       = 25753,
    NPC_DEFENDOTANK_66D                     = 25758,
    NPC_SCAVENGEBOT_005B6                   = 25792,
    NPC_55D_COLLECTATRON                    = 25793
};

// http://www.wowhead.com/quest=11730 Master and Servant
// 46023 The Ultrasonic Screwdriver
class spell_q11730_ultrasonic_screwdriver : public SpellHandlerScript
{
public:
    spell_q11730_ultrasonic_screwdriver() : SpellHandlerScript("spell_q11730_ultrasonic_screwdriver") { }

    class spell_q11730_ultrasonic_screwdriver_SpellScript : public SpellScript
    {
        bool Validate(SpellEntry const * spellEntry)
        {
            if (!sSpellStore.LookupEntry(SPELL_QUEST_SUMMON_SCAVENGEBOT_004A8))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_QUEST_SUMMON_SENTRYBOT_57K))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_QUEST_SUMMON_DEFENDOTANK_66D))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_QUEST_SUMMON_SCAVENGEBOT_005B6))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_QUEST_SUMMON_55D_COLLECTATRON))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_QUEST_ROBOT_KILL_CREDIT))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex effIndex)
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
                case NPC_SCAVENGEBOT_004A8: spellId = SPELL_QUEST_SUMMON_SCAVENGEBOT_004A8;    break;
                case NPC_SENTRYBOT_57K:     spellId = SPELL_QUEST_SUMMON_SENTRYBOT_57K;        break;
                case NPC_DEFENDOTANK_66D:   spellId = SPELL_QUEST_SUMMON_DEFENDOTANK_66D;      break;
                case NPC_SCAVENGEBOT_005B6: spellId = SPELL_QUEST_SUMMON_SCAVENGEBOT_005B6;    break;
                case NPC_55D_COLLECTATRON:  spellId = SPELL_QUEST_SUMMON_55D_COLLECTATRON;     break;
                default:
                    return;
            }
            pCaster->CastSpell(pCaster, spellId, true, castItem);
            pCaster->CastSpell(pCaster, SPELL_QUEST_ROBOT_KILL_CREDIT, true);
            pTarget->ForcedDespawn();
        }

        void Register()
        {
            EffectHandlers += EffectHandlerFn(spell_q11730_ultrasonic_screwdriver_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript * GetSpellScript() const
    {
        return new spell_q11730_ultrasonic_screwdriver_SpellScript();
    }
};

void AddSC_quest_spell_scripts()
{
    new spell_q11587_arcane_prisoner_rescue();
    new spell_q11730_ultrasonic_screwdriver();
}
