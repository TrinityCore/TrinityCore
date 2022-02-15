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

#include "PhaseShift.h"
#include "Containers.h"

PhaseShift::PhaseShift() = default;
PhaseShift::PhaseShift(PhaseShift const& right) = default;
PhaseShift::PhaseShift(PhaseShift&& right)  noexcept = default;
PhaseShift& PhaseShift::operator=(PhaseShift const& right) = default;
PhaseShift& PhaseShift::operator=(PhaseShift&& right) noexcept = default;
PhaseShift::~PhaseShift() = default;

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

bool PhaseShift::AddUiMapPhaseId(uint32 uiMapPhaseId, int32 references /*= 1*/)
{
    auto insertResult = UiMapPhaseIds.emplace(uiMapPhaseId, UiMapPhaseIdRef{ 0 });
    insertResult.first->second.References += references;
    return insertResult.second;
}

PhaseShift::EraseResult<PhaseShift::UiMapPhaseIdContainer> PhaseShift::RemoveUiMapPhaseId(uint32 uiMapPhaseId)
{
    auto itr = UiMapPhaseIds.find(uiMapPhaseId);
    if (itr != UiMapPhaseIds.end())
    {
        if (!--itr->second.References)
            return { UiMapPhaseIds.erase(itr), true };
        return { itr, false };
    }
    return { UiMapPhaseIds.end(), false };
}

void PhaseShift::Clear()
{
    ClearPhases();
    VisibleMapIds.clear();
    UiMapPhaseIds.clear();
}

void PhaseShift::ClearPhases()
{
    Flags &= PhaseShiftFlags::AlwaysVisible | PhaseShiftFlags::Inverse;
    PersonalGuid.Clear();
    Phases.clear();
    NonCosmeticReferences = 0;
    CosmeticReferences = 0;
    PersonalReferences = 0;
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
        if (phaseShift.Flags.HasFlag(PhaseShiftFlags::Unphased) && excludedPhaseShift.Flags.HasFlag(PhaseShiftFlags::InverseUnphased))
            return false;

        for (PhaseRef const& phase : phaseShift.Phases)
        {
            if (phase.Flags.HasFlag(excludePhasesWithFlag))
                continue;

            auto itr2 = std::find(excludedPhaseShift.Phases.begin(), excludedPhaseShift.Phases.end(), phase);
            if (itr2 != excludedPhaseShift.Phases.end() && !itr2->Flags.HasFlag(excludePhasesWithFlag))
                return false;
        }
        return true;
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

        if (itr->Flags.HasFlag(PhaseFlags::Personal))
            PersonalReferences += references;

        if (CosmeticReferences)
            Flags |= PhaseShiftFlags::NoCosmetic;
        else
            Flags &= ~PhaseShiftFlags::NoCosmetic;

        UpdateUnphasedFlag();
        UpdatePersonalGuid();
    }
}

void PhaseShift::UpdateUnphasedFlag()
{
    EnumFlag<PhaseShiftFlags> unphasedFlag = !Flags.HasFlag(PhaseShiftFlags::Inverse) ? PhaseShiftFlags::Unphased : PhaseShiftFlags::InverseUnphased;
    Flags &= ~(!Flags.HasFlag(PhaseShiftFlags::Inverse) ? PhaseShiftFlags::InverseUnphased : PhaseShiftFlags::Unphased);
    if (NonCosmeticReferences && !DefaultReferences)
        Flags &= ~unphasedFlag;
    else
        Flags |= unphasedFlag;
}

void PhaseShift::UpdatePersonalGuid()
{
    if (!PersonalReferences)
        PersonalGuid.Clear();
}

bool PhaseShift::HasPersonalPhase() const
{
    for (PhaseRef const& phaseRef : GetPhases())
        if (phaseRef.IsPersonal())
            return true;
    return false;
}
