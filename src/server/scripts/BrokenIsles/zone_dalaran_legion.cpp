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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Player.h"
#include "ObjectMgr.h"

class OnLegionArrival : public PlayerScript
{
public:
    OnLegionArrival() : PlayerScript("OnLegionArrival") { }

    void OnLevelChanged(Player* player, uint8 /*oldLevel*/) override
    {
        if (player->getLevel() == 100 && player->getClass() == CLASS_MAGE)
            player->CastSpell(player, 204287, true); // Learn Guardian Hall teleportation
    }
};

void AddSC_dalaran_legion()
{
    new OnLegionArrival();
}
