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

#include "GameObjectAI.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "LootMgr.h"
#include "QuestDef.h"

int32 GameObjectAI::Permissible(GameObject const* /*go*/)
{
    return PERMIT_BASE_NO;
}

void GameObjectAI::QuestReward(Player* player, Quest const* quest, uint32 opt)
{
    QuestReward(player, quest, LootItemType::Item, opt);
}

QuestGiverStatus GameObjectAI::GetDialogStatus(Player* /*player*/)
{
    return QuestGiverStatus::ScriptedDefault;
}

NullGameObjectAI::NullGameObjectAI(GameObject* g) : GameObjectAI(g) { }

int32 NullGameObjectAI::Permissible(GameObject const* /*go*/)
{
    return PERMIT_BASE_IDLE;
}
