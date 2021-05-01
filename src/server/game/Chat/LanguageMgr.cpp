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
#include "Containers.h"
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

    _langsMap.emplace(languageId, LanguageDesc{ spellEffect->SpellID, 0 }); // register without a skill id for now
}

void LanguageMgr::LoadLanguages()
{
    uint32 oldMSTime = getMSTime();

    // Load languages from Languages.db2. Just the id, we don't need the name
    for (LanguagesEntry const* langEntry : sLanguagesStore)
    {
        auto spellsRange = Trinity::Containers::MapEqualRange(_langsMap, langEntry->ID);
        if (spellsRange.begin() == spellsRange.end())
            _langsMap.emplace(langEntry->ID, LanguageDesc());
        else
        {
            std::vector<LanguageDesc> langsWithSkill;
            for (LanguagesMap::value_type const& spellItr : spellsRange)
                for (SkillLineAbilityMap::value_type const& skillPair : Trinity::Containers::MakeIteratorPair(sSpellMgr->GetSkillLineAbilityMapBounds(spellItr.second.SpellId)))
                    langsWithSkill.emplace_back(LanguageDesc{ spellItr.second.SpellId, uint32(skillPair.second->SkillLine) });

            for (LanguageDesc const& langDesc : langsWithSkill)
            {
                // erase temporary assignment that lacked skill
                Trinity::Containers::MultimapErasePair(_langsMap, langEntry->ID, { langDesc.SpellId, 0 });
                _langsMap.emplace(langEntry->ID, langDesc);
            }
        }
    }

    // Add the languages used in code in case they don't exist
    _langsMap.emplace(LANG_UNIVERSAL, LanguageDesc());
    _langsMap.emplace(LANG_ADDON, LanguageDesc());
    _langsMap.emplace(LANG_ADDON_LOGGED, LanguageDesc());

    // Log load time
    TC_LOG_INFO("server.loading", ">> Loaded %u languages in %u ms", uint32(_langsMap.size()), GetMSTimeDiffToNow(oldMSTime));
}

void LanguageMgr::LoadLanguagesWords()
{
    uint32 oldMSTime = getMSTime();

    uint32 wordsNum = 0;
    for (LanguageWordsEntry const* wordEntry : sLanguageWordsStore)
    {
        uint8 length = std::min(18U, uint32(strlen(wordEntry->Word)));

        WordKey key = WordKey(wordEntry->LanguageID, length);

        _wordsMap[key].push_back(wordEntry->Word);
        ++wordsNum;
    }

    // log load time
    TC_LOG_INFO("server.loading", ">> Loaded %u word groups from %u words in %u ms", uint32(_wordsMap.size()), wordsNum, GetMSTimeDiffToNow(oldMSTime));
}

LanguageMgr::WordList const* LanguageMgr::FindWordGroup(uint32 language, uint32 wordLen) const
{
    return Trinity::Containers::MapGetValuePtr(_wordsMap, WordKey(language, wordLen));
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
    return sLanguagesStore.HasRecord(languageId);
}

Trinity::IteratorPair<LanguageMgr::LanguagesMap::const_iterator> LanguageMgr::GetLanguageDescById(Language languageId) const
{
    return Trinity::Containers::MapEqualRange(_langsMap, languageId);
}
