/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef Trainer_h__
#define Trainer_h__

#include "Common.h"
#include <array>
#include <string>
#include <vector>

class Creature;
class ObjectMgr;
class Player;

namespace Trainer
{
    enum class Type : uint32
    {
        None = 0,
        Talent = 1,
        Tradeskill = 2,
        Pet = 3,
    };

    enum class SpellState : uint8
    {
        Known = 0,
        Available = 1,
        Unavailable = 2
    };

    enum class FailReason : uint32
    {
        Unavailable = 0,
        NotEnoughMoney = 1
    };

    struct Spell
    {
        uint32 SpellId = 0;
        uint32 MoneyCost = 0;
        uint32 ReqSkillLine = 0;
        uint32 ReqSkillRank = 0;
        std::array<uint32, 3> ReqAbility = { };
        uint8 ReqLevel = 0;

        uint32 LearnedSpellId = 0;
        bool IsCastable() const { return LearnedSpellId != SpellId; }
    };

    class Trainer
    {
    public:
        Trainer(uint32 id, Type type, std::string greeting, std::vector<Spell> spells);

        void SendSpells(Creature const* npc, Player const* player, LocaleConstant locale) const;
        void TeachSpell(Creature const* npc, Player* player, uint32 spellId) const;

    private:
        Spell const* GetSpell(uint32 spellId) const;
        bool CanTeachSpell(Player const* player, Spell const* trainerSpell) const;
        SpellState GetSpellState(Player const* player, Spell const* trainerSpell) const;
        void SendTeachFailure(Creature const* npc, Player const* player, uint32 spellId, FailReason reason) const;
        std::string const& GetGreeting(LocaleConstant locale) const;

        friend ObjectMgr;
        void AddGreetingLocale(LocaleConstant locale, std::string greeting);

        uint32 _id;
        Type _type;
        std::vector<Spell> _spells;
        std::array<std::string, TOTAL_LOCALES> _greeting;
    };
}

#endif // Trainer_h__
