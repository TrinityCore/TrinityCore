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

#include "LanguageMgr.h"
#include "DB2Stores.h"
#include "Log.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "Timer.h"

#include <sstream>

LanguageMgr::LanguageMgr() : _langsMap(), _wordsMap() { }

LanguageMgr::~LanguageMgr()
{
    _langsMap.clear();
    _wordsMap.clear();
}

LanguageMgr* LanguageMgr::instance()
{
    static LanguageMgr instance;
    return &instance;
}

void LanguageMgr::LoadSpellEffectLanguage(SpellEffectEntry const* spellEffect)
{
    ASSERT(spellEffect && spellEffect->Effect == SPELL_EFFECT_LANGUAGE);

    uint32 languageId = uint32(spellEffect->EffectMiscValue[0]);
    auto iter = _langsMap.find(languageId);
    if (iter == _langsMap.end())
    {
        TC_LOG_WARN("languages.spell", "LoadSpellEffectLanguage called on Spell %u with language %u which does not exist in Language.db2!",
            spellEffect->SpellID, languageId);
        return;
    }
    LanguageDesc& desc = iter->second;
    desc.SpellId = spellEffect->SpellID;
}

uint32 LanguageMgr::GetSpellLanguage(uint32 spellId) const
{
    if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId, DIFFICULTY_NONE))
    {
        SpellEffectInfoVector const& effects = spellInfo->GetEffects();
        if (effects.size() != 1 || effects[0]->Effect != SPELL_EFFECT_LANGUAGE)
            TC_LOG_WARN("languages.spell", "Invalid language spell %u. Expected 1 effect with SPELL_EFFECT_LANGUAGE", spellId);
        else
            return effects[0]->MiscValue;
    }
    return 0;
}

bool LanguageMgr::IsRelevantLanguageSkill(SkillLineEntry const* skillLineEntry) const
{
    if (!skillLineEntry)
        return false;

    SkillRaceClassInfoEntry const* entry = sDB2Manager.GetAvailableSkillRaceClassInfo(skillLineEntry->ID);
    return entry != nullptr;
}

void LanguageMgr::LoadLanguages()
{
    uint32 oldMSTime = getMSTime();

    // Load languages from Languages.db2. Just the id, we don't need the name
    for (LanguagesEntry const* langEntry : sLanguagesStore)
        _langsMap.emplace(langEntry->ID, LanguageDesc());

    // Add the languages used in code in case they don't exist
    _langsMap.emplace(LANG_UNIVERSAL, LanguageDesc());
    _langsMap.emplace(LANG_ADDON, LanguageDesc());
    _langsMap.emplace(LANG_ADDON_LOGGED, LanguageDesc());

    // Log load time
    TC_LOG_INFO("server.loading", ">> Loaded %u languages in %u ms", uint32(_langsMap.size()), GetMSTimeDiffToNow(oldMSTime));
}

void LanguageMgr::LoadLanguagesSkills()
{
    uint32 oldMSTime = getMSTime();

    uint32 count = 0;
    for (SkillLineEntry const* skillLineEntry : sSkillLineStore)
    {
        if (skillLineEntry->CategoryID != SKILL_CATEGORY_LANGUAGES)
            continue;

        if (!IsRelevantLanguageSkill(skillLineEntry))
            continue;

        std::vector<SkillLineAbilityEntry const*> const* skills = sDB2Manager.GetSkillLineAbilitiesBySkill(skillLineEntry->ID);

        // We're expecting only 1 skill
        if (skills->size() != 1)
            TC_LOG_WARN("server.loading", "Found language skill line with %u spells. Expected 1. Will use 1st if available", uint32(skills->size()));

        if (SkillLineAbilityEntry const* ability = skills->empty() ? nullptr : skills->at(0))
        {
            if (uint32 languageId = GetSpellLanguage(ability->Spell))
            {
                auto iter = _langsMap.find(languageId);
                if (iter == _langsMap.cend())
                    TC_LOG_WARN("server.loading", "Spell %u has language %u, which doesn't exist in Languages.db2", ability->Spell, languageId);
                else
                {
                    iter->second.SpellId = ability->Spell;
                    iter->second.SkillId = skillLineEntry->ID;
                    ++count;
                }
            }
        }
    }

    // Languages that don't have skills will be added in SpellMgr::LoadSpellInfoStore() (e.g. LANG_ZOMBIE, LANG_SHATH_YAR)

    // Log load time
    TC_LOG_INFO("server.loading", ">> Loaded %u languages skills in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void LanguageMgr::LoadLanguagesWords()
{
    uint32 oldMSTime = getMSTime();

    uint32 wordsNum = 0;
    for (LanguageWordsEntry const* wordEntry : sLanguageWordsStore)
    {
        uint8 length = std::min(18U, uint32(strlen(wordEntry->Word)));

        WordKey key = WordKey(wordEntry->LanguageID, length);

        auto result = _wordsMap.insert(std::make_pair(key, WordList()));
        result.first->second.push_back(wordEntry->Word);
        ++wordsNum;
    }

    // log load time
    TC_LOG_INFO("server.loading", ">> Loaded %u word groups from %u words in %u ms", uint32(_wordsMap.size()), wordsNum, GetMSTimeDiffToNow(oldMSTime));
}

LanguageMgr::WordList const* LanguageMgr::FindWordGroup(uint32 language, uint32 wordLen) const
{
    WordsMap::const_iterator iter = _wordsMap.find(WordKey(language, wordLen));
    if (iter != _wordsMap.end())
        return &(iter->second);
    return nullptr;
}

std::string LanguageMgr::Translate(std::string const& msg, uint32 sourcePlayerLanguage) const
{
    std::stringstream result;
    Tokenizer tokens(msg, ' ');
    bool first = true;
    for (char const* str : tokens)
    {
        const char* nextPart = str;
        uint32 wordLen = std::min(18U, (uint32)strlen(str));
        LanguageMgr::WordList const* wordGroup = FindWordGroup(sourcePlayerLanguage, wordLen);
        if (!wordGroup)
            nextPart = "";
        else
        {
            uint32 wordHash = SStrHash(str, true);
            uint8 idxInsideGroup = wordHash % wordGroup->size();
            nextPart = wordGroup->at(idxInsideGroup);
        }

        if (first)
            first = false;
        else
            result << " ";

        result << nextPart;
    }
    return result.str();
}

static char upper_backslash(char c) { return c == '/' ? '\\' : toupper(c); }

static uint32 const s_hashtable[16] = {
    0x486E26EE, 0xDCAA16B3, 0xE1918EEF, 0x202DAFDB,
    0x341C7DC7, 0x1C365303, 0x40EF2D37, 0x65FD5E49,
    0xD6057177, 0x904ECE93, 0x1C38024F, 0x98FD323B,
    0xE3061AE7, 0xA39B0FA1, 0x9797F25F, 0xE4444563,
};

uint32 LanguageMgr::SStrHash(char const* string, bool caseInsensitive, uint32 seed) const
{
    ASSERT(string);

    uint32 shift = 0xEEEEEEEE;
    while (*string) {
        char c = *string++;

        if (caseInsensitive)
            c = upper_backslash(c);

        seed = (s_hashtable[c >> 4] - s_hashtable[c & 0xF]) ^ (shift + seed);
        shift = c + seed + 33 * shift + 3;
    }

    return seed ? seed : 1;
}

bool LanguageMgr::IsLanguageExist(uint32 languageId) const
{
    auto iter = _langsMap.find(languageId);
    return iter != _langsMap.cend();
}

LanguageDesc const* LanguageMgr::GetLanguageDescById(uint32 languageId) const
{
    auto iter = _langsMap.find(languageId);
    if (iter == _langsMap.cend())
        return nullptr;
    return &(iter->second);
}
