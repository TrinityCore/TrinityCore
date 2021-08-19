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

#include "Common.h"
#include "Hash.h"
#include "IteratorPair.h"
#include "SharedDefines.h"
#include <vector>
#include <unordered_map>

struct LanguageDesc
{
    uint32 SpellId = 0;
    uint32 SkillId = 0;

    friend bool operator==(LanguageDesc const& left, LanguageDesc const& right)
    {
        return left.SpellId == right.SpellId && left.SkillId == right.SkillId;
    }
};

struct SpellEffectEntry;

class TC_GAME_API LanguageMgr
{
    friend class World;
    friend class SpellMgr;

    typedef std::pair<uint32, uint8> WordKey;
    typedef std::vector<char const*> WordList;
    typedef std::unordered_map<WordKey, WordList> WordsMap;

    typedef std::unordered_multimap<uint32, LanguageDesc> LanguagesMap;

    // Constructors
    private:
        LanguageMgr();
        ~LanguageMgr();

    // Accessors (const or static functions)
    public:
        static LanguageMgr* instance();

        //
        std::string Translate(std::string const& msg, uint32 language, LocaleConstant locale) const;

        bool IsLanguageExist(uint32 languageId) const;
        Trinity::IteratorPair<LanguagesMap::const_iterator> GetLanguageDescById(Language languageId) const;

        /* Calls a callback for each available language.
         * Callback signature: bool callback(uint32 lang, LanguageDesc const& languageDesc)
         */
        template <typename T>
        bool ForEachLanguage(T callback)
        {
            for (LanguagesMap::value_type const& pair : _langsMap)
                if (!callback(pair.first, pair.second))
                    return false;
            return true;
        }

    private:
        /* Create assosiation between language and spell id
         * Language is taken from effect value.
         * Assuming Effect == SPELL_EFFECT_LANGUAGE
         */
        void LoadSpellEffectLanguage(SpellEffectEntry const* spellEffect);

        void LoadLanguagesWords();
        void LoadLanguages();

        WordList const* FindWordGroup(uint32 language, uint32 wordLen) const;

        LanguagesMap _langsMap;
        WordsMap _wordsMap;
};

#define sLanguageMgr LanguageMgr::instance()

#endif
