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

#include "ChallengeModePackets.h"
#include "InstanceScript.h"
#include "Item.h"
#include "Log.h"
#include "Player.h"
#include "WorldSession.h"

void WorldSession::HandleChallengeModeStart(WorldPackets::ChallengeMode::StartRequest& start)
{
    GameObject* object = _player->GetGameObjectIfCanInteractWith(start.GobGUID, GAMEOBJECT_TYPE_KEYSTONE_RECEPTACLE);
    if (!object)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleChallengeModeStart - %s not found or you can not interact with it.", start.GobGUID.ToString().c_str());
        return;
    }

    Item* key = _player->GetItemByPos(start.Bag, start.Slot);
    if (!key)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleChallengeModeStart - item in Bag %u and Slot %u not found.", start.Bag, start.Slot);
        return;
    }

    if (key->GetTemplate()->GetClass() != ITEM_CLASS_REAGENT || key->GetTemplate()->GetSubClass() != ITEM_SUBCLASS_KEYSTONE)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleChallengeModeStart - Tried to start a challenge with item %s which have class %u and subclass %u.",
            key->GetGUID().ToString().c_str(),
            key->GetTemplate()->GetClass(),
            key->GetTemplate()->GetSubClass());
        return;
    }

    uint32 challengeModeId      = key->GetModifier(ITEM_MODIFIER_CHALLENGE_MAP_CHALLENGE_MODE_ID);
    uint32 challengeModeLevel   = key->GetModifier(ITEM_MODIFIER_CHALLENGE_KEYSTONE_LEVEL);

    MapChallengeModeEntry const* entry = sMapChallengeModeStore.LookupEntry(challengeModeId);
    if (!entry || !challengeModeLevel || entry->MapID != _player->GetMapId())
    {
        TC_LOG_DEBUG("network", "WORLD: HandleChallengeModeStart - Tried to start a challenge with wrong challengeModeId %u and level %u.", challengeModeId, challengeModeLevel);
        return;
    }

    if (InstanceScript* instanceScript = _player->GetInstanceScript())
        instanceScript->StartChallengeMode(challengeModeLevel);

    // Blizzard do not delete the key at challenge start, will require mort research
    _player->DestroyItem(start.Bag, start.Slot, true);
}
