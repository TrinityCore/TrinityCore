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

#include "PhasingHandler.h"
#include "Chat.h"
#include "ConditionMgr.h"
#include "Creature.h"
#include "DB2Stores.h"
#include "DisableMgr.h"
#include "Language.h"
#include "Map.h"
#include "MiscPackets.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "PartyPackets.h"
#include "PhaseShift.h"
#include "Player.h"
#include "SpellAuraEffects.h"
#include "TerrainMgr.h"
#include "Vehicle.h"
#include <boost/container/small_vector.hpp>
#include <sstream>

namespace
{
PhaseShift const Empty;
PhaseShift const AlwaysVisible = []
{
    PhaseShift phaseShift;
    PhasingHandler::InitDbPhaseShift(phaseShift, PHASE_USE_FLAGS_ALWAYS_VISIBLE, 0, 0);
    return phaseShift;
}();

inline PhaseFlags GetPhaseFlags(uint32 phaseId)
{
    if (PhaseEntry const* phase = sPhaseStore.LookupEntry(phaseId))
    {
        if (phase->GetFlags().HasFlag(PhaseEntryFlags::Cosmetic))
            return PhaseFlags::Cosmetic;

        if (phase->GetFlags().HasFlag(PhaseEntryFlags::Personal))
            return PhaseFlags::Personal;
    }

    return PhaseFlags::None;
}
}

class PhasingHandler::ControlledUnitVisitor
{
public:
    explicit ControlledUnitVisitor(WorldObject* owner)
    {
        _visited.insert(owner);
    }

    template<typename Func>
    inline void VisitControlledOf(Unit* unit, Func&& func)
    {
        for (Unit* controlled : unit->m_Controlled)
            if (controlled->GetTypeId() != TYPEID_PLAYER
                && !controlled->GetVehicle())                   // Player inside nested vehicle should not phase the root vehicle and its accessories (only direct root vehicle control does)
                if (_visited.insert(controlled).second)
                    func(controlled);

        for (ObjectGuid summonGuid : unit->m_SummonSlot)
            if (!summonGuid.IsEmpty())
                if (Creature* summon = ObjectAccessor::GetCreature(*unit, summonGuid))
                    if (_visited.insert(summon).second)
                        func(summon);

        if (Vehicle const* vehicle = unit->GetVehicleKit())
            for (auto seat = vehicle->Seats.begin(); seat != vehicle->Seats.end(); ++seat)
                if (Unit* passenger = ObjectAccessor::GetUnit(*unit, seat->second.Passenger.Guid); passenger && passenger != unit)
                    if (_visited.insert(passenger).second)
                        func(passenger);
    }

private:
    Trinity::Containers::FlatSet<WorldObject*, std::less<WorldObject*>, boost::container::small_vector<WorldObject*, 8>> _visited;
};

void PhasingHandler::AddPhase(WorldObject* object, uint32 phaseId, bool updateVisibility)
{
    ControlledUnitVisitor visitor(object);
    AddPhase(object, phaseId, object->GetGUID(), updateVisibility, visitor);
}

void PhasingHandler::AddPhase(WorldObject* object, uint32 phaseId, ObjectGuid const& personalGuid, bool updateVisibility, ControlledUnitVisitor& visitor)
{
    bool changed = object->GetPhaseShift().AddPhase(phaseId, GetPhaseFlags(phaseId), nullptr);

    if (object->GetPhaseShift().PersonalReferences)
        object->GetPhaseShift().PersonalGuid = personalGuid;

    if (Unit* unit = object->ToUnit())
    {
        unit->OnPhaseChange();
        visitor.VisitControlledOf(unit, [&](Unit* controlled)
        {
            AddPhase(controlled, phaseId, personalGuid, updateVisibility, visitor);
        });
        unit->RemoveNotOwnSingleTargetAuras(true);
    }

    UpdateVisibilityIfNeeded(object, updateVisibility, changed);
}

void PhasingHandler::RemovePhase(WorldObject* object, uint32 phaseId, bool updateVisibility)
{
    ControlledUnitVisitor visitor(object);
    RemovePhase(object, phaseId, updateVisibility, visitor);
}

void PhasingHandler::RemovePhase(WorldObject* object, uint32 phaseId, bool updateVisibility, ControlledUnitVisitor& visitor)
{
    bool changed = object->GetPhaseShift().RemovePhase(phaseId).Erased;

    if (Unit* unit = object->ToUnit())
    {
        unit->OnPhaseChange();
        visitor.VisitControlledOf(unit, [&](Unit* controlled)
        {
            RemovePhase(controlled, phaseId, updateVisibility, visitor);
        });
        unit->RemoveNotOwnSingleTargetAuras(true);
    }

    UpdateVisibilityIfNeeded(object, updateVisibility, changed);
}

void PhasingHandler::AddPhaseGroup(WorldObject* object, uint32 phaseGroupId, bool updateVisibility)
{
    std::vector<uint32> const* phasesInGroup = sDB2Manager.GetPhasesForGroup(phaseGroupId);
    if (!phasesInGroup)
        return;

    ControlledUnitVisitor visitor(object);
    AddPhaseGroup(object, phasesInGroup, object->GetGUID(), updateVisibility, visitor);
}

void PhasingHandler::AddPhaseGroup(WorldObject* object, std::vector<uint32> const* phasesInGroup, ObjectGuid const& personalGuid, bool updateVisibility, ControlledUnitVisitor& visitor)
{
    bool changed = false;
    for (uint32 phaseId : *phasesInGroup)
        changed = object->GetPhaseShift().AddPhase(phaseId, GetPhaseFlags(phaseId), nullptr) || changed;

    if (object->GetPhaseShift().PersonalReferences)
        object->GetPhaseShift().PersonalGuid = personalGuid;

    if (Unit* unit = object->ToUnit())
    {
        unit->OnPhaseChange();
        visitor.VisitControlledOf(unit, [&](Unit* controlled)
        {
            AddPhaseGroup(controlled, phasesInGroup, personalGuid, updateVisibility, visitor);
        });
        unit->RemoveNotOwnSingleTargetAuras(true);
    }

    UpdateVisibilityIfNeeded(object, updateVisibility, changed);
}

void PhasingHandler::RemovePhaseGroup(WorldObject* object, uint32 phaseGroupId, bool updateVisibility)
{
    std::vector<uint32> const* phasesInGroup = sDB2Manager.GetPhasesForGroup(phaseGroupId);
    if (!phasesInGroup)
        return;

    ControlledUnitVisitor visitor(object);
    RemovePhaseGroup(object, phasesInGroup, updateVisibility, visitor);
}

void PhasingHandler::RemovePhaseGroup(WorldObject* object, std::vector<uint32> const* phasesInGroup, bool updateVisibility, ControlledUnitVisitor& visitor)
{
    bool changed = false;
    for (uint32 phaseId : *phasesInGroup)
        changed = object->GetPhaseShift().RemovePhase(phaseId).Erased || changed;

    if (Unit* unit = object->ToUnit())
    {
        unit->OnPhaseChange();
        visitor.VisitControlledOf(unit, [&](Unit* controlled)
        {
            RemovePhaseGroup(controlled, phasesInGroup, updateVisibility, visitor);
        });
        unit->RemoveNotOwnSingleTargetAuras(true);
    }

    UpdateVisibilityIfNeeded(object, updateVisibility, changed);
}

void PhasingHandler::AddVisibleMapId(WorldObject* object, uint32 visibleMapId)
{
    ControlledUnitVisitor visitor(object);
    AddVisibleMapId(object, visibleMapId, visitor);
}

void PhasingHandler::AddVisibleMapId(WorldObject* object, uint32 visibleMapId, ControlledUnitVisitor& visitor)
{
    TerrainSwapInfo const* terrainSwapInfo = sObjectMgr->GetTerrainSwapInfo(visibleMapId);
    bool changed = object->GetPhaseShift().AddVisibleMapId(visibleMapId, terrainSwapInfo);

    for (uint32 uiMapPhaseId : terrainSwapInfo->UiMapPhaseIDs)
        changed = object->GetPhaseShift().AddUiMapPhaseId(uiMapPhaseId) || changed;

    if (Unit* unit = object->ToUnit())
    {
        visitor.VisitControlledOf(unit, [&](Unit* controlled)
        {
            AddVisibleMapId(controlled, visibleMapId, visitor);
        });
    }

    UpdateVisibilityIfNeeded(object, false, changed);
}

void PhasingHandler::RemoveVisibleMapId(WorldObject* object, uint32 visibleMapId)
{
    ControlledUnitVisitor visitor(object);
    RemoveVisibleMapId(object, visibleMapId, visitor);
}

void PhasingHandler::RemoveVisibleMapId(WorldObject* object, uint32 visibleMapId, ControlledUnitVisitor& visitor)
{
    TerrainSwapInfo const* terrainSwapInfo = sObjectMgr->GetTerrainSwapInfo(visibleMapId);
    bool changed = object->GetPhaseShift().RemoveVisibleMapId(visibleMapId).Erased;

    for (uint32 uiWorldMapAreaIDSwap : terrainSwapInfo->UiMapPhaseIDs)
        changed = object->GetPhaseShift().RemoveUiMapPhaseId(uiWorldMapAreaIDSwap).Erased || changed;

    if (Unit* unit = object->ToUnit())
    {
        visitor.VisitControlledOf(unit, [&](Unit* controlled)
        {
            RemoveVisibleMapId(controlled, visibleMapId, visitor);
        });
    }

    UpdateVisibilityIfNeeded(object, false, changed);
}

void PhasingHandler::ResetPhaseShift(WorldObject* object)
{
    object->GetPhaseShift().Clear();
    object->GetSuppressedPhaseShift().Clear();
}

void PhasingHandler::InheritPhaseShift(WorldObject* target, WorldObject const* source)
{
    target->GetPhaseShift() = source->GetPhaseShift();
    target->GetSuppressedPhaseShift() = source->GetSuppressedPhaseShift();
}

void PhasingHandler::OnMapChange(WorldObject* object)
{
    PhaseShift& phaseShift = object->GetPhaseShift();
    PhaseShift& suppressedPhaseShift = object->GetSuppressedPhaseShift();
    ConditionSourceInfo srcInfo = ConditionSourceInfo(object);

    object->GetPhaseShift().VisibleMapIds.clear();
    object->GetPhaseShift().UiMapPhaseIds.clear();
    object->GetSuppressedPhaseShift().VisibleMapIds.clear();

    for (auto const& visibleMapPair : sObjectMgr->GetTerrainSwaps())
    {
        for (TerrainSwapInfo const* visibleMapInfo : visibleMapPair.second)
        {
            if (sConditionMgr->IsObjectMeetingNotGroupedConditions(CONDITION_SOURCE_TYPE_TERRAIN_SWAP, visibleMapInfo->Id, srcInfo))
            {
                if (visibleMapPair.first == object->GetMapId())
                    phaseShift.AddVisibleMapId(visibleMapInfo->Id, visibleMapInfo);

                // ui map is visible on all maps
                for (uint32 uiMapPhaseId : visibleMapInfo->UiMapPhaseIDs)
                    phaseShift.AddUiMapPhaseId(uiMapPhaseId);
            }
            else if (visibleMapPair.first == object->GetMapId())
                suppressedPhaseShift.AddVisibleMapId(visibleMapInfo->Id, visibleMapInfo);
        }
    }

    UpdateVisibilityIfNeeded(object, false, true);
}

void PhasingHandler::OnAreaChange(WorldObject* object)
{
    PhaseShift& phaseShift = object->GetPhaseShift();
    PhaseShift& suppressedPhaseShift = object->GetSuppressedPhaseShift();
    PhaseShift::PhaseContainer oldPhases = std::move(phaseShift.Phases); // for comparison
    ConditionSourceInfo srcInfo = ConditionSourceInfo(object);

    object->GetPhaseShift().ClearPhases();
    object->GetSuppressedPhaseShift().ClearPhases();

    uint32 areaId = object->GetAreaId();
    AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(areaId);
    while (areaEntry)
    {
        if (std::vector<PhaseAreaInfo> const* newAreaPhases = sObjectMgr->GetPhasesForArea(areaEntry->ID))
        {
            for (PhaseAreaInfo const& phaseArea : *newAreaPhases)
            {
                if (phaseArea.SubAreaExclusions.find(areaId) != phaseArea.SubAreaExclusions.end())
                    continue;

                uint32 phaseId = phaseArea.PhaseInfo->Id;
                if (DisableMgr::IsDisabledFor(DISABLE_TYPE_PHASE_AREA, phaseId, object))
                    continue;

                if (sConditionMgr->IsObjectMeetToConditions(srcInfo, phaseArea.Conditions))
                    phaseShift.AddPhase(phaseId, GetPhaseFlags(phaseId), &phaseArea.Conditions);
                else
                    suppressedPhaseShift.AddPhase(phaseId, GetPhaseFlags(phaseId), &phaseArea.Conditions);
            }
        }

        areaEntry = sAreaTableStore.LookupEntry(areaEntry->ParentAreaID);
    }

    bool changed = phaseShift.Phases != oldPhases;
    if (Unit* unit = object->ToUnit())
    {
        for (AuraEffect const* aurEff : unit->GetAuraEffectsByType(SPELL_AURA_PHASE))
        {
            uint32 phaseId = uint32(aurEff->GetMiscValueB());
            changed = phaseShift.AddPhase(phaseId, GetPhaseFlags(phaseId), nullptr) || changed;
        }

        for (AuraEffect const* aurEff : unit->GetAuraEffectsByType(SPELL_AURA_PHASE_GROUP))
            if (std::vector<uint32> const* phasesInGroup = sDB2Manager.GetPhasesForGroup(uint32(aurEff->GetMiscValueB())))
                for (uint32 phaseId : *phasesInGroup)
                    changed = phaseShift.AddPhase(phaseId, GetPhaseFlags(phaseId), nullptr) || changed;

        if (phaseShift.PersonalReferences)
            phaseShift.PersonalGuid = unit->GetGUID();

        if (changed)
            unit->OnPhaseChange();

        ControlledUnitVisitor visitor(unit);
        visitor.VisitControlledOf(unit, [&](Unit* controlled)
        {
            InheritPhaseShift(controlled, unit);
        });

        if (changed)
            unit->RemoveNotOwnSingleTargetAuras(true);
    }
    else
    {
        if (phaseShift.PersonalReferences)
            phaseShift.PersonalGuid = object->GetGUID();
    }

    UpdateVisibilityIfNeeded(object, true, changed);
}

bool PhasingHandler::OnConditionChange(WorldObject* object, bool updateVisibility /*= true*/)
{
    PhaseShift& phaseShift = object->GetPhaseShift();
    PhaseShift& suppressedPhaseShift = object->GetSuppressedPhaseShift();
    PhaseShift newSuppressions;
    ConditionSourceInfo srcInfo = ConditionSourceInfo(object);
    bool changed = false;

    for (auto itr = phaseShift.Phases.begin(); itr != phaseShift.Phases.end();)
    {
        if (itr->AreaConditions && !sConditionMgr->IsObjectMeetToConditions(srcInfo, *itr->AreaConditions))
        {
            newSuppressions.AddPhase(itr->Id, itr->Flags, itr->AreaConditions, itr->References);
            phaseShift.ModifyPhasesReferences(itr, -itr->References);
            itr = phaseShift.Phases.erase(itr);
        }
        else
            ++itr;
    }

    for (auto itr = suppressedPhaseShift.Phases.begin(); itr != suppressedPhaseShift.Phases.end();)
    {
        if (!DisableMgr::IsDisabledFor(DISABLE_TYPE_PHASE_AREA, itr->Id, object) && sConditionMgr->IsObjectMeetToConditions(srcInfo, *ASSERT_NOTNULL(itr->AreaConditions)))
        {
            changed = phaseShift.AddPhase(itr->Id, itr->Flags, itr->AreaConditions, itr->References) || changed;
            suppressedPhaseShift.ModifyPhasesReferences(itr, -itr->References);
            itr = suppressedPhaseShift.Phases.erase(itr);
        }
        else
            ++itr;
    }

    for (auto itr = phaseShift.VisibleMapIds.begin(); itr != phaseShift.VisibleMapIds.end();)
    {
        if (!sConditionMgr->IsObjectMeetingNotGroupedConditions(CONDITION_SOURCE_TYPE_TERRAIN_SWAP, itr->first, srcInfo))
        {
            newSuppressions.AddVisibleMapId(itr->first, itr->second.VisibleMapInfo, itr->second.References);
            for (uint32 uiMapPhaseId : itr->second.VisibleMapInfo->UiMapPhaseIDs)
                changed = phaseShift.RemoveUiMapPhaseId(uiMapPhaseId).Erased || changed;

            itr = phaseShift.VisibleMapIds.erase(itr);
        }
        else
            ++itr;
    }

    for (auto itr = suppressedPhaseShift.VisibleMapIds.begin(); itr != suppressedPhaseShift.VisibleMapIds.end();)
    {
        if (sConditionMgr->IsObjectMeetingNotGroupedConditions(CONDITION_SOURCE_TYPE_TERRAIN_SWAP, itr->first, srcInfo))
        {
            changed = phaseShift.AddVisibleMapId(itr->first, itr->second.VisibleMapInfo, itr->second.References) || changed;
            for (uint32 uiMapPhaseId : itr->second.VisibleMapInfo->UiMapPhaseIDs)
                changed = phaseShift.AddUiMapPhaseId(uiMapPhaseId) || changed;

            itr = suppressedPhaseShift.VisibleMapIds.erase(itr);
        }
        else
            ++itr;
    }

    Unit* unit = object->ToUnit();
    if (unit)
    {
        for (AuraEffect const* aurEff : unit->GetAuraEffectsByType(SPELL_AURA_PHASE))
        {
            uint32 phaseId = uint32(aurEff->GetMiscValueB());
            auto eraseResult = newSuppressions.RemovePhase(phaseId);
            // if condition was met previously there is nothing to erase
            if (eraseResult.Iterator != newSuppressions.Phases.end() || eraseResult.Erased)
                phaseShift.AddPhase(phaseId, GetPhaseFlags(phaseId), nullptr);
        }

        for (AuraEffect const* aurEff : unit->GetAuraEffectsByType(SPELL_AURA_PHASE_GROUP))
        {
            if (std::vector<uint32> const* phasesInGroup = sDB2Manager.GetPhasesForGroup(uint32(aurEff->GetMiscValueB())))
            {
                for (uint32 phaseId : *phasesInGroup)
                {
                    auto eraseResult = newSuppressions.RemovePhase(phaseId);
                    // if condition was met previously there is nothing to erase
                    if (eraseResult.Iterator != newSuppressions.Phases.end() || eraseResult.Erased)
                        phaseShift.AddPhase(phaseId, GetPhaseFlags(phaseId), nullptr);
                }
            }
        }
    }

    if (phaseShift.PersonalReferences)
        phaseShift.PersonalGuid = object->GetGUID();

    changed = changed || !newSuppressions.Phases.empty() || !newSuppressions.VisibleMapIds.empty();
    for (PhaseShift::PhaseRef const& phaseRef : newSuppressions.Phases)
        suppressedPhaseShift.AddPhase(phaseRef.Id, phaseRef.Flags, phaseRef.AreaConditions, phaseRef.References);

    for (std::pair<uint32 const, PhaseShift::VisibleMapIdRef> const& visibleMap : newSuppressions.VisibleMapIds)
        suppressedPhaseShift.AddVisibleMapId(visibleMap.first, visibleMap.second.VisibleMapInfo, visibleMap.second.References);

    if (unit)
    {
        if (changed)
            unit->OnPhaseChange();

        ControlledUnitVisitor visitor(unit);
        visitor.VisitControlledOf(unit, [&](Unit* controlled)
        {
            InheritPhaseShift(controlled, unit);
        });

        if (changed)
            unit->RemoveNotOwnSingleTargetAuras(true);
    }

    UpdateVisibilityIfNeeded(object, updateVisibility, changed);
    return changed;
}

void PhasingHandler::SendToPlayer(Player const* player, PhaseShift const& phaseShift)
{
    WorldPackets::Misc::PhaseShiftChange phaseShiftChange;
    phaseShiftChange.Client = player->GetGUID();
    phaseShiftChange.Phaseshift.PhaseShiftFlags = phaseShift.Flags.AsUnderlyingType();
    phaseShiftChange.Phaseshift.PersonalGUID = phaseShift.PersonalGuid;
    phaseShiftChange.Phaseshift.Phases.reserve(phaseShift.Phases.size());
    std::transform(phaseShift.Phases.begin(), phaseShift.Phases.end(), std::back_inserter(phaseShiftChange.Phaseshift.Phases),
        [](PhaseShift::PhaseRef const& phase) -> WorldPackets::Misc::PhaseShiftDataPhase { return { phase.Flags.AsUnderlyingType(), phase.Id }; });
    phaseShiftChange.VisibleMapIDs.reserve(phaseShift.VisibleMapIds.size());
    std::transform(phaseShift.VisibleMapIds.begin(), phaseShift.VisibleMapIds.end(), std::back_inserter(phaseShiftChange.VisibleMapIDs),
        [](PhaseShift::VisibleMapIdContainer::value_type const& visibleMapId) { return visibleMapId.first; });
    phaseShiftChange.UiMapPhaseIDs.reserve(phaseShift.UiMapPhaseIds.size());
    std::transform(phaseShift.UiMapPhaseIds.begin(), phaseShift.UiMapPhaseIds.end(), std::back_inserter(phaseShiftChange.UiMapPhaseIDs),
        [](PhaseShift::UiMapPhaseIdContainer::value_type const& uiWorldMapAreaIdSwap) { return uiWorldMapAreaIdSwap.first; });

    player->SendDirectMessage(phaseShiftChange.Write());
}

void PhasingHandler::SendToPlayer(Player const* player)
{
    SendToPlayer(player, player->GetPhaseShift());
}

void PhasingHandler::FillPartyMemberPhase(WorldPackets::Party::PartyMemberPhaseStates* partyMemberPhases, PhaseShift const& phaseShift)
{
    partyMemberPhases->PhaseShiftFlags = phaseShift.Flags.AsUnderlyingType();
    partyMemberPhases->PersonalGUID = phaseShift.PersonalGuid;
    partyMemberPhases->List.reserve(phaseShift.Phases.size());
    std::transform(phaseShift.Phases.begin(), phaseShift.Phases.end(), std::back_inserter(partyMemberPhases->List),
        [](PhaseShift::PhaseRef const& phase) -> WorldPackets::Party::PartyMemberPhase { return { phase.Flags.AsUnderlyingType(), phase.Id }; });
}

PhaseShift const& PhasingHandler::GetEmptyPhaseShift()
{
    return Empty;
}

PhaseShift const& PhasingHandler::GetAlwaysVisiblePhaseShift()
{
    return AlwaysVisible;
}

void PhasingHandler::InitDbPhaseShift(PhaseShift& phaseShift, uint8 phaseUseFlags, uint16 phaseId, uint32 phaseGroupId)
{
    phaseShift.ClearPhases();
    phaseShift.IsDbPhaseShift = true;

    EnumFlag<PhaseShiftFlags> flags = PhaseShiftFlags::None;
    if (phaseUseFlags & PHASE_USE_FLAGS_ALWAYS_VISIBLE)
        flags |= PhaseShiftFlags::AlwaysVisible | PhaseShiftFlags::Unphased;
    if (phaseUseFlags & PHASE_USE_FLAGS_INVERSE)
        flags |= PhaseShiftFlags::Inverse;

    if (phaseId)
        phaseShift.AddPhase(phaseId, GetPhaseFlags(phaseId), nullptr);
    else if (phaseGroupId)
        if (std::vector<uint32> const* phasesInGroup = sDB2Manager.GetPhasesForGroup(phaseGroupId))
            for (uint32 phaseInGroup : *phasesInGroup)
                phaseShift.AddPhase(phaseInGroup, GetPhaseFlags(phaseInGroup), nullptr);

    if (phaseShift.Phases.empty() || phaseShift.HasPhase(DEFAULT_PHASE))
    {
        if (flags.HasFlag(PhaseShiftFlags::Inverse))
            flags |= PhaseShiftFlags::InverseUnphased;
        else
            flags |= PhaseShiftFlags::Unphased;
    }

    phaseShift.Flags = flags;
}

void PhasingHandler::InitDbPersonalOwnership(PhaseShift& phaseShift, ObjectGuid const& personalGuid)
{
    ASSERT(phaseShift.IsDbPhaseShift);
    ASSERT(phaseShift.HasPersonalPhase());
    phaseShift.PersonalGuid = personalGuid;
}

void PhasingHandler::InitDbVisibleMapId(PhaseShift& phaseShift, int32 visibleMapId)
{
    phaseShift.VisibleMapIds.clear();
    if (visibleMapId != -1)
        phaseShift.AddVisibleMapId(visibleMapId, sObjectMgr->GetTerrainSwapInfo(visibleMapId));
}

bool PhasingHandler::InDbPhaseShift(WorldObject const* object, uint8 phaseUseFlags, uint16 phaseId, uint32 phaseGroupId)
{
    PhaseShift phaseShift;
    InitDbPhaseShift(phaseShift, phaseUseFlags, phaseId, phaseGroupId);
    return object->GetPhaseShift().CanSee(phaseShift);
}

uint32 PhasingHandler::GetTerrainMapId(PhaseShift const& phaseShift, uint32 mapId, TerrainInfo const* terrain, float x, float y)
{
    if (phaseShift.VisibleMapIds.empty())
        return mapId;

    if (phaseShift.VisibleMapIds.size() == 1)
        return phaseShift.VisibleMapIds.begin()->first;

    GridCoord gridCoord = Trinity::ComputeGridCoord(x, y);
    int32 gx = (MAX_NUMBER_OF_GRIDS - 1) - gridCoord.x_coord;
    int32 gy = (MAX_NUMBER_OF_GRIDS - 1) - gridCoord.y_coord;

    for (std::pair<uint32 const, PhaseShift::VisibleMapIdRef> const& visibleMap : phaseShift.VisibleMapIds)
        if (terrain->HasChildTerrainGridFile(visibleMap.first, gx, gy))
            return visibleMap.first;

    return mapId;
}

void PhasingHandler::SetAlwaysVisible(WorldObject* object, bool apply, bool updateVisibility)
{
    if (apply)
        object->GetPhaseShift().Flags |= PhaseShiftFlags::AlwaysVisible;
    else
        object->GetPhaseShift().Flags &= ~PhaseShiftFlags::AlwaysVisible;

    UpdateVisibilityIfNeeded(object, updateVisibility, true);
}

void PhasingHandler::SetInversed(WorldObject* object, bool apply, bool updateVisibility)
{
    if (apply)
        object->GetPhaseShift().Flags |= PhaseShiftFlags::Inverse;
    else
        object->GetPhaseShift().Flags &= PhaseShiftFlags::Inverse;

    object->GetPhaseShift().UpdateUnphasedFlag();

    UpdateVisibilityIfNeeded(object, updateVisibility, true);
}

void PhasingHandler::PrintToChat(ChatHandler* chat, WorldObject const* target)
{
    PhaseShift const& phaseShift = target->GetPhaseShift();

    std::string phaseOwnerName = "N/A";
    if (phaseShift.HasPersonalPhase())
        if (WorldObject* personalGuid = ObjectAccessor::GetWorldObject(*target, phaseShift.PersonalGuid))
            phaseOwnerName = personalGuid->GetName();

    chat->PSendSysMessage(LANG_PHASESHIFT_STATUS, phaseShift.Flags.AsUnderlyingType(),
        phaseShift.PersonalGuid.ToString().c_str(), phaseOwnerName.c_str());

    if (!phaseShift.Phases.empty())
    {
        std::ostringstream phases;
        std::string cosmetic = sObjectMgr->GetTrinityString(LANG_PHASE_FLAG_COSMETIC, chat->GetSessionDbLocaleIndex());
        std::string personal = sObjectMgr->GetTrinityString(LANG_PHASE_FLAG_PERSONAL, chat->GetSessionDbLocaleIndex());
        for (PhaseShift::PhaseRef const& phase : phaseShift.Phases)
        {
            phases << "\r\n";
            phases << ' ' << ' ' << ' ';
            phases << phase.Id << ' ' << '(' << sObjectMgr->GetPhaseName(phase.Id) << ')';
            if (phase.Flags.HasFlag(PhaseFlags::Cosmetic))
                phases << ' ' << '(' << cosmetic << ')';
            if (phase.Flags.HasFlag(PhaseFlags::Personal))
                phases << ' ' << '(' << personal << ')';
            if (DisableMgr::IsDisabledFor(DISABLE_TYPE_PHASE_AREA, phase.Id, nullptr))
                phases << " (Disabled)";
        }

        chat->PSendSysMessage(LANG_PHASESHIFT_PHASES, phases.str().c_str());
    }

    if (!phaseShift.VisibleMapIds.empty())
    {
        std::ostringstream visibleMapIds;
        for (PhaseShift::VisibleMapIdContainer::value_type const& visibleMapId : phaseShift.VisibleMapIds)
            visibleMapIds << visibleMapId.first << ',' << ' ';

        chat->PSendSysMessage(LANG_PHASESHIFT_VISIBLE_MAP_IDS, visibleMapIds.str().c_str());
    }

    if (!phaseShift.UiMapPhaseIds.empty())
    {
        std::ostringstream uiWorldMapAreaIdSwaps;
        for (PhaseShift::UiMapPhaseIdContainer::value_type const& uiWorldMapAreaIdSwap : phaseShift.UiMapPhaseIds)
            uiWorldMapAreaIdSwaps << uiWorldMapAreaIdSwap.first << ',' << ' ';

        chat->PSendSysMessage(LANG_PHASESHIFT_UI_WORLD_MAP_AREA_SWAPS, uiWorldMapAreaIdSwaps.str().c_str());
    }
}

std::string PhasingHandler::FormatPhases(PhaseShift const& phaseShift)
{
    std::ostringstream phases;
    for (PhaseShift::PhaseRef const& phase : phaseShift.Phases)
        phases << phase.Id << ',';

    return phases.str();
}

bool PhasingHandler::IsPersonalPhase(uint32 phaseId)
{
    if (PhaseEntry const* phase = sPhaseStore.LookupEntry(phaseId))
        return phase->GetFlags().HasFlag(PhaseEntryFlags::Personal);

    return false;
}

void PhasingHandler::UpdateVisibilityIfNeeded(WorldObject* object, bool updateVisibility, bool changed)
{
    if (changed && object->IsInWorld())
    {
        if (Player* player = object->ToPlayer())
            SendToPlayer(player);

        if (updateVisibility)
        {
            if (Player* player = object->ToPlayer())
                player->GetMap()->SendUpdateTransportVisibility(player);

            object->UpdateObjectVisibility();
        }
    }
}
