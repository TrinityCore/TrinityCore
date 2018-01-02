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

#include "GameObject.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"

/*
 * Dalaran above Karazhan
 *
 * Legion Intro
 */

// 246854
class go_dalaran_karazhan : public GameObjectScript
{
public:
    go_dalaran_karazhan() : GameObjectScript("go_dalaran_karazhan") { }

    // This is also called on object Creation. Set dalaran to active to enable far sight
    void OnGameObjectStateChanged(GameObject* go, uint32 /*state*/) override
    {
        if (!go->isActiveObject())
            go->setActive(true);
    }
};

/*
 * Legion Dalaran
 */

class OnLegionArrival : public PlayerScript
{
public:
    OnLegionArrival() : PlayerScript("OnLegionArrival") { }

    enum
    {
        SPELL_MAGE_LEARN_GUARDIAN_HALL_TP   = 204287,
        SPELL_WAR_LEARN_JUMP_TO_SKYHOLD     = 192084,
        SPELL_CREATE_CLASS_HALL_ALLIANCE    = 185506,
        SPELL_CREATE_CLASS_HALL_HORDE       = 192191,
    };

    void OnLevelChanged(Player* player, uint8 /*oldLevel*/) override
    {
        if (player->getLevel() == 100)
        {
            if (player->getClass() == CLASS_MAGE)
                player->CastSpell(player, SPELL_MAGE_LEARN_GUARDIAN_HALL_TP, true);
            else if (player->getClass() == CLASS_WARRIOR)
                player->CastSpell(player, SPELL_WAR_LEARN_JUMP_TO_SKYHOLD, true);

            player->CastSpell(player, player->IsInAlliance() ? SPELL_CREATE_CLASS_HALL_ALLIANCE : SPELL_CREATE_CLASS_HALL_HORDE, true);
        }
    }
};

void AddSC_dalaran_legion()
{
    new go_dalaran_karazhan();
    new OnLegionArrival();
}
