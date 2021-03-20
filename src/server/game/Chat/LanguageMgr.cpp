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
#include "Timer.h"

#include <sstream>

LanguageMgr::LanguageMgr() : _wordsMap() { }

LanguageMgr::~LanguageMgr()
{
    _wordsMap.clear();
}

LanguageMgr* LanguageMgr::instance()
{
    static LanguageMgr instance;
    return &instance;
}

void LanguageMgr::LoadLanguages()
{
    uint32 oldMSTime = getMSTime();

    //
    uint32 wordsNum = 0;
    for (auto iter = sLanguageWordsStore.begin(); iter != sLanguageWordsStore.end(); ++iter)
    {
        uint8 length = std::min(18U, uint32(strlen(iter->Word)));

        WordKey key = WordKey(iter->LanguageID, length);

        auto result = _wordsMap.insert(std::make_pair(key, WordList()));
        result.first->second.push_back(iter->Word);
        ++wordsNum;
    }

    // log load time
    TC_LOG_INFO("server.loading", ">> Loaded %u word groups from %u words in %u ms", uint32(_wordsMap.size()), wordsNum, GetMSTimeDiffToNow(oldMSTime));
}

LanguageMgr::WordList const* LanguageMgr::FindWordGroup(Language language, uint32 wordLen) const
{
    WordsMap::const_iterator iter;
    while (wordLen > 0)
    {
        iter = _wordsMap.find(WordKey(language, wordLen));
        if (iter != _wordsMap.end())
            return &(iter->second);
        --wordLen;
    }

    return nullptr;
}

std::string LanguageMgr::Translate(std::string const& msg, uint16 targetPlayerLanguageSkill, Language sourcePlayerLanguage) const
{
    std::stringstream result;
    Tokenizer tokens(msg, ' ');
    bool first = true;
    for (char const* str : tokens)
    {
        uint32 wordHash = SStrHash(str, true);
        const char* nextPart = str;
        if (wordHash % 300 < targetPlayerLanguageSkill)
            continue;

        uint32 wordLen = std::min(18U, (uint32)strlen(str));
        LanguageMgr::WordList const* wordGroup = FindWordGroup(sourcePlayerLanguage, wordLen);
        if (wordGroup)
        {
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
    assert(string);

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
