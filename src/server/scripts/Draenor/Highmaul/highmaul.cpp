/*
 * Copyright 2023 AzgathCore
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

#include "highmaul.h"
#include "GameObjectAI.h"
#include "Group.h"
#include "ScriptedGossip.h"
#include "Chat.h"
#include "ObjectMgr.h"

/// Gharg positions
Position const g_GhargFirstPos = { 3466.11f, 7577.58f, 15.203f, 0.8954f };
Position const g_GhargSecondPos = { 3483.23f, 7598.67f, 10.65f, 0.8954f };

/// Gharg Teleport position
Position const g_GhargTeleportPos = { 3475.60f, 7590.64f, 55.30f, 4.062f };

/// Mar'gok (Cosmetic) teleport position
Position const g_MargokTeleport = { 3432.25f, 7536.13f, 73.664f, 0.896154f };

/// Kargath Bladefist position
Position const g_KargathPos = { 3444.50f, 7550.76f, 55.39f, 0.90f };

/// Iron Warmaster (Brackenspore cosmetic) move positions
Position const g_IronWarmasterPos = { 4155.636719f, 7817.216309f, 0.253316f, 0.514213f };
Position const g_IronWarmasterJump = { 4182.975098f, 7839.367188f, 7.755508f, 5.603590f };

/// Teleporter to Imperator's Rise
Position const g_TeleporterSpawnPos = { 4186.096f, 8574.492f, 425.353f, 3.851739f };

void AddSC_highmaul()
{
   
}
