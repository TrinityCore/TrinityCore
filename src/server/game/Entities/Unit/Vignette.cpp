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

#include "Vignette.h"
#include "CellImpl.h"
#include "DB2Stores.h"
#include "GridNotifiersImpl.h"
#include "VignettePackets.h"

namespace Vignettes
{
namespace
{
void UpdatePosition(VignetteData& vignette, WorldObject const* owner)
{
    vignette.Position = owner->GetPosition();
    if (WmoLocation const* wmoLocation = owner->GetCurrentWmo())
    {
        vignette.WMOGroupID = wmoLocation->GroupId;
        vignette.WMODoodadPlacementID = wmoLocation->UniqueId;
    }
}

template<WorldPackets::Vignette::VignetteDataSet WorldPackets::Vignette::VignetteUpdate::* Field>
void SendVignetteUpdate(VignetteData const& vignette, WorldObject const* owner)
{
    if (!owner->IsInWorld())
        return;

    WorldPackets::Vignette::VignetteUpdate vignetteUpdate;
    vignette.FillPacket(vignetteUpdate.*Field);
    vignetteUpdate.Write();

    auto sender = [&](Player const* receiver)
    {
        if (CanSee(receiver, vignette))
            receiver->SendDirectMessage(vignetteUpdate.GetRawPacket());
    };

    Trinity::MessageDistDeliverer notifier(owner, sender, owner->GetVisibilityRange());
    Cell::VisitWorldObjects(owner, notifier, owner->GetVisibilityRange());
}
}

void VignetteData::FillPacket(WorldPackets::Vignette::VignetteDataSet& dataSet) const
{
    dataSet.IDs.push_back(Guid);

    WorldPackets::Vignette::VignetteData& data = dataSet.Data.emplace_back();
    data.ObjGUID = Object;
    data.Position = Position;
    data.VignetteID = Data->ID;
    data.ZoneID = ZoneID;
    data.WMOGroupID = WMOGroupID;
    data.WMODoodadPlacementID = WMODoodadPlacementID;
}

std::unique_ptr<VignetteData> Create(VignetteEntry const* vignetteData, WorldObject const* owner)
{
    std::unique_ptr<VignetteData> vignette = std::make_unique<VignetteData>();
    vignette->Guid = ObjectGuid::Create<HighGuid::Vignette>(owner->GetMapId(), vignetteData->ID, owner->GetMap()->GenerateLowGuid<HighGuid::Vignette>());
    vignette->Object = owner->GetGUID();
    vignette->Position = owner->GetPosition();
    vignette->Data = vignetteData;
    vignette->ZoneID = owner->GetZoneId(); // not updateable
    UpdatePosition(*vignette, owner);

    if (vignetteData->IsInfiniteAOI())
        owner->GetMap()->AddInfiniteAOIVignette(vignette.get());
    else
        SendVignetteUpdate<&WorldPackets::Vignette::VignetteUpdate::Added>(*vignette, owner);

    return vignette;
}

void Update(VignetteData& vignette, WorldObject const* owner)
{
    UpdatePosition(vignette, owner);

    if (vignette.Data->IsInfiniteAOI())
        vignette.NeedUpdate = true;
    else
        SendVignetteUpdate<&WorldPackets::Vignette::VignetteUpdate::Updated>(vignette, owner);
}

void Remove(VignetteData& vignette, WorldObject const* owner)
{
    if (vignette.Data->IsInfiniteAOI())
        owner->GetMap()->RemoveInfiniteAOIVignette(&vignette);
    else
    {
        WorldPackets::Vignette::VignetteUpdate vignetteUpdate;
        vignetteUpdate.Removed.push_back(vignette.Guid);
        owner->SendMessageToSet(vignetteUpdate.Write(), true);
    }
}

bool CanSee(Player const* player, VignetteData const& vignette)
{
    if (vignette.Data->GetFlags().HasFlag(VignetteFlags::ZoneInfiniteAOI))
        if (vignette.ZoneID != player->GetZoneId())
            return false;

    if (vignette.Data->VisibleTrackingQuestID)
        if (player->IsQuestRewarded(vignette.Data->VisibleTrackingQuestID))
            return false;

    if (PlayerConditionEntry const* playerCondition = sPlayerConditionStore.LookupEntry(vignette.Data->PlayerConditionID))
        if (!ConditionMgr::IsPlayerMeetingCondition(player, playerCondition))
            return false;

    return true;
}
}
