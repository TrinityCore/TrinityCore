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

namespace
{
    void StripHyperlinks(std::string const& source, std::string& dest)
    {
        dest.resize(source.length());
        size_t destSize = 0;
        bool skipSquareBrackets = false;
        for (size_t i = 0; i < source.length(); ++i)
        {
            char c = source[i];
            if (c != '|')
            {
                if (!skipSquareBrackets || (c != '[' && c != ']'))
                    dest[destSize++] = source[i];

                continue;
            }

            if (i + 1 >= source.length())
                break;

            switch (source[i + 1])
            {
                case 'c':
                case 'C':
                    // skip color
                    i += 9;
                    break;
                case 'r':
                    ++i;
                    break;
                case 'H':
                    // skip just past first |h
                    i = source.find("|h", i);
                    if (i != std::string::npos)
                        i += 2;
                    skipSquareBrackets = true;
                    break;
                case 'h':
                    ++i;
                    skipSquareBrackets = false;
                    break;
                case 'T':
                    // skip just past closing |t
                    i = source.find("|t", i);
                    if (i != std::string::npos)
                        i += 2;
                    break;
                default:
                    break;
            }
        }

        dest.resize(destSize);
    }

    void ReplaceUntranslatableCharactersWithSpace(std::string& text)
    {
        std::wstring wstrText;
        if (!Utf8toWStr(text, wstrText))
            return;

        for (wchar_t& w : wstrText)
            if (!isExtendedLatinCharacter(w) && !isNumeric(w) && w <= 0xFF && w != L'\\')
                w = L' ';

        WStrToUtf8(wstrText, text);
    }

    static char upper_backslash(char c)
    {
        return c == '/' ? '\\' : char(toupper(c));
    }

    static uint32 const sstr_hashtable[16] =
    {
        0x486E26EE, 0xDCAA16B3, 0xE1918EEF, 0x202DAFDB,
        0x341C7DC7, 0x1C365303, 0x40EF2D37, 0x65FD5E49,
        0xD6057177, 0x904ECE93, 0x1C38024F, 0x98FD323B,
        0xE3061AE7, 0xA39B0FA1, 0x9797F25F, 0xE4444563,
    };

    uint32 SStrHash(char const* string, bool caseInsensitive, uint32 seed = 0x7FED7FED)
    {
        ASSERT(string);

        uint32 shift = 0xEEEEEEEE;
        while (*string)
        {
            char c = *string++;

            if (caseInsensitive)
                c = upper_backslash(c);

            seed = (sstr_hashtable[c >> 4] - sstr_hashtable[c & 0xF]) ^ (shift + seed);
            shift = c + seed + 33 * shift + 3;
        }

        return seed ? seed : 1;
    }
}

std::string LanguageMgr::Translate(std::string const& msg, uint32 language, LocaleConstant locale) const
{
    std::string textToTranslate;
    StripHyperlinks(msg, textToTranslate);
    ReplaceUntranslatableCharactersWithSpace(textToTranslate);

    std::string result;
    result.reserve(textToTranslate.length());
    Tokenizer tokens(textToTranslate, ' ');
    for (char const* str : tokens)
    {
        uint32 wordLen = std::min(18u, uint32(strlen(str)));
        if (LanguageMgr::WordList const* wordGroup = FindWordGroup(language, wordLen))
        {
            uint32 wordHash = SStrHash(str, true);
            uint8 idxInsideGroup = wordHash % wordGroup->size();

            char const* replacementWord = (*wordGroup)[idxInsideGroup];

            switch (locale)
            {
                case LOCALE_koKR:
                case LOCALE_zhCN:
                case LOCALE_zhTW:
                {
                    size_t length = std::min(strlen(str), strlen(replacementWord));
                    for (size_t i = 0; i < length; ++i)
                    {
                        if (str[i] >= 'A' && str[i] <= 'Z')
                            result += char(toupper(replacementWord[i]));
                        else
                            result += replacementWord[i];
                    }
                    break;
                }
                default:
                {
                    std::wstring wstrSourceWord;
                    if (Utf8toWStr(str, wstrSourceWord))
                    {
                        size_t length = std::min(wstrSourceWord.length(), strlen(replacementWord));
                        for (size_t i = 0; i < length; ++i)
                        {
                            if (isUpper(wstrSourceWord[i]))
                                result += char(toupper(replacementWord[i]));
                            else
                                result += char(tolower(replacementWord[i]));
                        }
                    }
                    break;
                }
            }
        }

        result += ' ';
    }

    if (!result.empty())
        result.pop_back();

    return result;
}

bool LanguageMgr::IsLanguageExist(uint32 languageId) const
{
    return sLanguagesStore.HasRecord(languageId);
}

Trinity::IteratorPair<LanguageMgr::LanguagesMap::const_iterator> LanguageMgr::GetLanguageDescById(Language languageId) const
{
    return Trinity::Containers::MapEqualRange(_langsMap, languageId);
}
