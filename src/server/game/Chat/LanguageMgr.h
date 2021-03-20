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

#ifndef _LANGUAGE_MGR_H
#define _LANGUAGE_MGR_H

#include "Define.h"
#include "Hash.h"
#include "Language.h"
#include "SharedDefines.h"
#include <string>
#include <vector>
#include <unordered_map>

class TC_GAME_API LanguageMgr
{
    typedef std::pair<uint32, uint8> WordKey;
    typedef std::vector<char const*> WordList;
    typedef std::unordered_map<WordKey, WordList> WordsMap;

    // Constructors
    private:
        LanguageMgr();
        ~LanguageMgr();

    // Accessors (const or static functions)
    public:
        static LanguageMgr* instance();

        void LoadLanguages();

        //
        std::string Translate(std::string const& msg, uint16 targetPlayerLanguageSkill, Language sourcePlayerLanguage) const;

        uint32 SStrHash(char const* string, bool caseInsensitive, uint32 seed = 0x7FED7FED) const;

    private:
        WordList const* FindWordGroup(Language language, uint32 wordLen) const;

        WordsMap _wordsMap;
};

#define sLanguageMgr LanguageMgr::instance()

#endif
