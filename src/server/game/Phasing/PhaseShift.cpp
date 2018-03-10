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

#include "PhaseShift.h"
#include "Containers.h"

bool PhaseShift::AddPhase(uint32 phaseId, PhaseFlags flags, std::vector<Condition*> const* areaConditions, int32 references /*= 1*/)
{
    auto insertResult = Phases.emplace(phaseId, flags, nullptr);
    ModifyPhasesReferences(insertResult.first, references);
    if (areaConditions)
        insertResult.first->AreaConditions = areaConditions;

    return insertResult.second;
}

PhaseShift::EraseResult<PhaseShift::PhaseContainer> PhaseShift::RemovePhase(uint32 phaseId)
{
    auto itr = Phases.find(PhaseRef(phaseId, PhaseFlags::None, nullptr));
    if (itr != Phases.end())
    {
        ModifyPhasesReferences(itr, -1);
        if (!itr->References)
            return { Phases.erase(itr), true };
        return { itr, false };
    }
    return { Phases.end(), false };
}

bool PhaseShift::AddVisibleMapId(uint32 visibleMapId, TerrainSwapInfo const* visibleMapInfo, int32 references /*= 1*/)
{
    auto insertResult = VisibleMapIds.emplace(visibleMapId, VisibleMapIdRef{ 0, visibleMapInfo });
    insertResult.first->second.References += references;
    return insertResult.second;
}

PhaseShift::EraseResult<PhaseShift::VisibleMapIdContainer> PhaseShift::RemoveVisibleMapId(uint32 visibleMapId)
{
    auto itr = VisibleMapIds.find(visibleMapId);
    if (itr != VisibleMapIds.end())
    {
        if (!--itr->second.References)
            return { VisibleMapIds.erase(itr), true };
        return { itr, false };
    }
    return { VisibleMapIds.end(), false };
}

bool PhaseShift::AddUiWorldMapAreaIdSwap(uint32 uiWorldMapAreaId, int32 references /*= 1*/)
{
    auto insertResult = UiWorldMapAreaIdSwaps.emplace(uiWorldMapAreaId, UiWorldMapAreaIdSwapRef{ 0 });
    insertResult.first->second.References += references;
    return insertResult.second;
}

PhaseShift::EraseResult<PhaseShift::UiWorldMapAreaIdSwapContainer> PhaseShift::RemoveUiWorldMapAreaIdSwap(uint32 uiWorldMapAreaId)
{
    auto itr = UiWorldMapAreaIdSwaps.find(uiWorldMapAreaId);
    if (itr != UiWorldMapAreaIdSwaps.end())
    {
        if (!--itr->second.References)
            return { UiWorldMapAreaIdSwaps.erase(itr), true };
        return { itr, false };
    }
    return { UiWorldMapAreaIdSwaps.end(), false };
}

void PhaseShift::Clear()
{
    ClearPhases();
    PersonalGuid.Clear();
    VisibleMapIds.clear();
    UiWorldMapAreaIdSwaps.clear();
}

void PhaseShift::ClearPhases()
{
    Flags &= EnumClassFlag<PhaseShiftFlags>(PhaseShiftFlags::AlwaysVisible) | PhaseShiftFlags::Inverse;
    Phases.clear();
    NonCosmeticReferences = 0;
    CosmeticReferences = 0;
    DefaultReferences = 0;
    UpdateUnphasedFlag();
}

bool PhaseShift::CanSee(PhaseShift const& other) const
{
    if (Flags.HasFlag(PhaseShiftFlags::Unphased) && other.Flags.HasFlag(PhaseShiftFlags::Unphased))
        return true;
    if (Flags.HasFlag(PhaseShiftFlags::AlwaysVisible) || other.Flags.HasFlag(PhaseShiftFlags::AlwaysVisible))
        return true;
    if (Flags.HasFlag(PhaseShiftFlags::Inverse) && other.Flags.HasFlag(PhaseShiftFlags::Inverse))
        return true;

    PhaseFlags excludePhasesWithFlag = PhaseFlags::None;
    if (Flags.HasFlag(PhaseShiftFlags::NoCosmetic) && other.Flags.HasFlag(PhaseShiftFlags::NoCosmetic))
        excludePhasesWithFlag = PhaseFlags::Cosmetic;

    if (!Flags.HasFlag(PhaseShiftFlags::Inverse) && !other.Flags.HasFlag(PhaseShiftFlags::Inverse))
    {
        ObjectGuid ownerGuid = PersonalGuid;
        ObjectGuid otherPersonalGuid = other.PersonalGuid;
        return Trinity::Containers::Intersects(Phases.begin(), Phases.end(), other.Phases.begin(), other.Phases.end(),
            [&ownerGuid, &otherPersonalGuid, excludePhasesWithFlag](PhaseRef const& myPhase, PhaseRef const& /*otherPhase*/)
        {
            return !myPhase.Flags.HasFlag(excludePhasesWithFlag) && (!myPhase.Flags.HasFlag(PhaseFlags::Personal) || ownerGuid == otherPersonalGuid);
        });
    }

    auto checkInversePhaseShift = [excludePhasesWithFlag](PhaseShift const& phaseShift, PhaseShift const& excludedPhaseShift)
    {
        if (phaseShift.Flags.HasFlag(PhaseShiftFlags::Unphased) && !excludedPhaseShift.Flags.HasFlag(PhaseShiftFlags::InverseUnphased))
            return true;

        for (auto itr = phaseShift.Phases.begin(); itr != phaseShift.Phases.end(); ++itr)
        {
            if (itr->Flags.HasFlag(excludePhasesWithFlag))
                continue;

            auto itr2 = std::find(excludedPhaseShift.Phases.begin(), excludedPhaseShift.Phases.end(), *itr);
            if (itr2 == excludedPhaseShift.Phases.end() || itr2->Flags.HasFlag(excludePhasesWithFlag))
                return true;
        }

        return false;
    };

    if (other.Flags.HasFlag(PhaseShiftFlags::Inverse))
        return checkInversePhaseShift(*this, other);

    return checkInversePhaseShift(other, *this);
}

void PhaseShift::ModifyPhasesReferences(PhaseContainer::iterator itr, int32 references)
{
    itr->References += references;

    if (!IsDbPhaseShift)
    {
        if (itr->Flags.HasFlag(PhaseFlags::Cosmetic))
            CosmeticReferences += references;
        else if (itr->Id != DEFAULT_PHASE)
            NonCosmeticReferences += references;
        else
            DefaultReferences += references;

        if (CosmeticReferences)
            Flags |= PhaseShiftFlags::NoCosmetic;
        else
            Flags &= ~EnumClassFlag<PhaseShiftFlags>(PhaseShiftFlags::NoCosmetic);

        UpdateUnphasedFlag();
    }
}

void PhaseShift::UpdateUnphasedFlag()
{
    EnumClassFlag<PhaseShiftFlags> unphasedFlag = !Flags.HasFlag(PhaseShiftFlags::Inverse) ? PhaseShiftFlags::Unphased : PhaseShiftFlags::InverseUnphased;
    Flags &= ~EnumClassFlag<PhaseShiftFlags>(!Flags.HasFlag(PhaseShiftFlags::Inverse) ? PhaseShiftFlags::InverseUnphased : PhaseShiftFlags::Unphased);
    if (NonCosmeticReferences && !DefaultReferences)
        Flags &= ~unphasedFlag;
    else
        Flags |= unphasedFlag;
}
