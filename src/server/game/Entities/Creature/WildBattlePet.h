/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#ifndef TRINITYCORE_WILDBATTLEPET_H
#define TRINITYCORE_WILDBATTLEPET_H

class BattlePet;
class Creature;

class TC_GAME_API WildBattlePet
{
    public:
        WildBattlePet(Creature* creature);
        ~WildBattlePet();

        void Initialize();

        Creature* GetCreature() { return m_creature; }
        BattlePet* GetBattlePet() { return m_battlePet; }

        uint8 GetLevel() { return m_battlePet->Level; }

    private:
        Creature* m_creature;
        BattlePet* m_battlePet;
};

#endif
