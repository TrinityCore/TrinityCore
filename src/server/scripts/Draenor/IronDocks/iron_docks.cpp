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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "GridNotifiers.h"
#include "iron_docks.hpp"
#include "ScriptMgr.h"
#include "Vehicle.h"

enum eSpells
{
    /// Misc
    SpellSelfStun = 94563,
    SpellEmoteWork = 43831,
    SpellCarryCrate = 173166,
    SpellCarrySack = 167539,
    SpellApplauseCheer = 84062
};

enum eMovementInformed
{
    MovementInformedClefthoofTargetArrivDest = 1,
    MovementInformedIronStarWallContact
};

enum eEmotes
{
    EmoteWork01 = 133,
    EmoteFight = 36,
};

enum eAction
{
    ActionQuietDeath = 744
};

void AddSC_iron_docks()
{
    
}
