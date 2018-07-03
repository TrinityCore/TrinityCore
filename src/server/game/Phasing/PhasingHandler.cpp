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

#include "PhasingHandler.h"
#include "Chat.h"
#include "ConditionMgr.h"
#include "Creature.h"
#include "DB2Stores.h"
#include "Language.h"
#include "Map.h"
#include "MiscPackets.h"
#include "ObjectMgr.h"
#include "PartyPackets.h"
#include "PhaseShift.h"
#include "Player.h"
#include "SpellAuraEffects.h"

namespace
{
PhaseShift const Empty;

inline PhaseFlags GetPhaseFlags(uint32 phaseId)
{
    if (PhaseEntry const* phase = sPhaseStore.LookupEntry(phaseId))
    {
        if (phase->Flags & PHASE_FLAG_COSMETIC)
            return PhaseFlags::Cosmetic;

        if (phase->Flags & PHASE_FLAG_PERSONAL)
            return PhaseFlags::Personal;
    }

    return PhaseFlags::None;
}

template<typename Func>
inline void ForAllControlled(Unit* unit, Func&& func)
{
    for (Unit* controlled : unit->m_Controlled)
        if (controlled->GetTypeId() != TYPEID_PLAYER)
            func(controlled);

    for (uint8 i = 0; i < MAX_SUMMON_SLOT; ++i)
        if (!unit->m_SummonSlot[i].IsEmpty())
            if (Creature* summon = unit->GetMap()->GetCreature(unit->m_SummonSlot[i]))
                func(summon);
}
}

void PhasingHandler::AddPhase(WorldObject* object, uint32 phaseId, bool updateVisibility)
{
    bool changed = object->GetPhaseShift().AddPhase(phaseId, GetPhaseFlags(phaseId), nullptr);

    if (Unit* unit = object->ToUnit())
    {
        unit->OnPhaseChange();
        ForAllControlled(unit, [&](Unit* controlled)
        {
            AddPhase(controlled, phaseId, updateVisibility);
        });
        unit->RemoveNotOwnSingleTargetAuras(true);
    }

    UpdateVisibilityIfNeeded(object, updateVisibility, changed);
}

void PhasingHandler::RemovePhase(WorldObject* object, uint32 phaseId, bool updateVisibility)
{
    bool changed = object->GetPhaseShift().RemovePhase(phaseId).Erased;

    if (Unit* unit = object->ToUnit())
    {
        unit->OnPhaseChange();
        ForAllControlled(unit, [&](Unit* controlled)
        {
            RemovePhase(controlled, phaseId, updateVisibility);
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

    bool changed = false;
    for (uint32 phaseId : *phasesInGroup)
        changed = object->GetPhaseShift().AddPhase(phaseId, GetPhaseFlags(phaseId), nullptr) || changed;

    if (Unit* unit = object->ToUnit())
    {
        unit->OnPhaseChange();
        ForAllControlled(unit, [&](Unit* controlled)
        {
            AddPhaseGroup(controlled, phaseGroupId, updateVisibility);
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

    bool changed = false;
    for (uint32 phaseId : *phasesInGroup)
        changed = object->GetPhaseShift().RemovePhase(phaseId).Erased || changed;

    if (Unit* unit = object->ToUnit())
    {
        unit->OnPhaseChange();
        ForAllControlled(unit, [&](Unit* controlled)
        {
            RemovePhaseGroup(controlled, phaseGroupId, updateVisibility);
        });
        unit->RemoveNotOwnSingleTargetAuras(true);
    }

    UpdateVisibilityIfNeeded(object, updateVisibility, changed);
}

void PhasingHandler::AddVisibleMapId(WorldObject* object, uint32 visibleMapId)
{
    TerrainSwapInfo const* terrainSwapInfo = sObjectMgr->GetTerrainSwapInfo(visibleMapId);
    bool changed = object->GetPhaseShift().AddVisibleMapId(visibleMapId, terrainSwapInfo);

    for (uint32 uiWorldMapAreaIDSwap : terrainSwapInfo->UiWorldMapAreaIDSwaps)
        changed = object->GetPhaseShift().AddUiWorldMapAreaIdSwap(uiWorldMapAreaIDSwap) || changed;

    if (Unit* unit = object->ToUnit())
    {
        ForAllControlled(unit, [&](Unit* controlled)
        {
            AddVisibleMapId(controlled, visibleMapId);
        });
    }

    UpdateVisibilityIfNeeded(object, false, changed);
}

void PhasingHandler::RemoveVisibleMapId(WorldObject* object, uint32 visibleMapId)
{
    TerrainSwapInfo const* terrainSwapInfo = sObjectMgr->GetTerrainSwapInfo(visibleMapId);
    bool changed = object->GetPhaseShift().RemoveVisibleMapId(visibleMapId).Erased;

    for (uint32 uiWorldMapAreaIDSwap : terrainSwapInfo->UiWorldMapAreaIDSwaps)
        changed = object->GetPhaseShift().RemoveUiWorldMapAreaIdSwap(uiWorldMapAreaIDSwap).Erased || changed;

    if (Unit* unit = object->ToUnit())
    {
        ForAllControlled(unit, [&](Unit* controlled)
        {
            RemoveVisibleMapId(controlled, visibleMapId);
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
    object->GetPhaseShift().UiWorldMapAreaIdSwaps.clear();
    object->GetSuppressedPhaseShift().VisibleMapIds.clear();

    if (std::vector<TerrainSwapInfo*> const* visibleMapIds = sObjectMgr->GetTerrainSwapsForMap(object->GetMapId()))
    {
        for (TerrainSwapInfo const* visibleMapInfo : *visibleMapIds)
        {
            if (sConditionMgr->IsObjectMeetingNotGroupedConditions(CONDITION_SOURCE_TYPE_TERRAIN_SWAP, visibleMapInfo->Id, srcInfo))
            {
                phaseShift.AddVisibleMapId(visibleMapInfo->Id, visibleMapInfo);
                for (uint32 uiWorldMapAreaIdSwap : visibleMapInfo->UiWorldMapAreaIDSwaps)
                    phaseShift.AddUiWorldMapAreaIdSwap(uiWorldMapAreaIdSwap);
            }
            else
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

        if (changed)
            unit->OnPhaseChange();

        ForAllControlled(unit, [&](Unit* controlled)
        {
            InheritPhaseShift(controlled, unit);
        });

        if (changed)
            unit->RemoveNotOwnSingleTargetAuras(true);
    }

    UpdateVisibilityIfNeeded(object, true, changed);
}

void PhasingHandler::OnConditionChange(WorldObject* object)
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
        if (sConditionMgr->IsObjectMeetToConditions(srcInfo, *ASSERT_NOTNULL(itr->AreaConditions)))
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
            for (uint32 uiWorldMapAreaIdSwap : itr->second.VisibleMapInfo->UiWorldMapAreaIDSwaps)
                changed = phaseShift.RemoveUiWorldMapAreaIdSwap(uiWorldMapAreaIdSwap).Erased || changed;

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
            for (uint32 uiWorldMapAreaIdSwap : itr->second.VisibleMapInfo->UiWorldMapAreaIDSwaps)
                changed = phaseShift.AddUiWorldMapAreaIdSwap(uiWorldMapAreaIdSwap) || changed;

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

    changed = changed || !newSuppressions.Phases.empty() || !newSuppressions.VisibleMapIds.empty();
    for (auto itr = newSuppressions.Phases.begin(); itr != newSuppressions.Phases.end(); ++itr)
        suppressedPhaseShift.AddPhase(itr->Id, itr->Flags, itr->AreaConditions, itr->References);

    for (auto itr = newSuppressions.VisibleMapIds.begin(); itr != newSuppressions.VisibleMapIds.end(); ++itr)
        suppressedPhaseShift.AddVisibleMapId(itr->first, itr->second.VisibleMapInfo, itr->second.References);

    if (unit)
    {
        if (changed)
            unit->OnPhaseChange();

        ForAllControlled(unit, [&](Unit* controlled)
        {
            InheritPhaseShift(controlled, unit);
        });

        if (changed)
            unit->RemoveNotOwnSingleTargetAuras(true);
    }

    UpdateVisibilityIfNeeded(object, true, changed);
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
    phaseShiftChange.UiWorldMapAreaIDSwaps.reserve(phaseShift.UiWorldMapAreaIdSwaps.size());
    std::transform(phaseShift.UiWorldMapAreaIdSwaps.begin(), phaseShift.UiWorldMapAreaIdSwaps.end(), std::back_inserter(phaseShiftChange.UiWorldMapAreaIDSwaps),
        [](PhaseShift::UiWorldMapAreaIdSwapContainer::value_type const& uiWorldMapAreaIdSwap) { return uiWorldMapAreaIdSwap.first; });

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

void PhasingHandler::InitDbPhaseShift(PhaseShift& phaseShift, uint8 phaseUseFlags, uint16 phaseId, uint32 phaseGroupId)
{
    phaseShift.ClearPhases();
    phaseShift.IsDbPhaseShift = true;

    EnumClassFlag<PhaseShiftFlags> flags = PhaseShiftFlags::None;
    if (phaseUseFlags & PHASE_USE_FLAGS_ALWAYS_VISIBLE)
        flags = flags | PhaseShiftFlags::AlwaysVisible | PhaseShiftFlags::Unphased;
    if (phaseUseFlags & PHASE_USE_FLAGS_INVERSE)
        flags |= PhaseShiftFlags::Inverse;

    if (phaseId)
        phaseShift.AddPhase(phaseId, GetPhaseFlags(phaseId), nullptr);
    else if (std::vector<uint32> const* phasesInGroup = sDB2Manager.GetPhasesForGroup(phaseGroupId))
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

uint32 PhasingHandler::GetTerrainMapId(PhaseShift const& phaseShift, Map const* map, float x, float y)
{
    if (phaseShift.VisibleMapIds.empty())
        return map->GetId();

    if (phaseShift.VisibleMapIds.size() == 1)
        return phaseShift.VisibleMapIds.begin()->first;

    GridCoord gridCoord = Trinity::ComputeGridCoord(x, y);
    int32 gx = (MAX_NUMBER_OF_GRIDS - 1) - gridCoord.x_coord;
    int32 gy = (MAX_NUMBER_OF_GRIDS - 1) - gridCoord.y_coord;

    int32 gxbegin = std::max(gx - 1, 0);
    int32 gxend = std::min(gx + 1, MAX_NUMBER_OF_GRIDS);
    int32 gybegin = std::max(gy - 1, 0);
    int32 gyend = std::min(gy + 1, MAX_NUMBER_OF_GRIDS);

    for (auto itr = phaseShift.VisibleMapIds.rbegin(); itr != phaseShift.VisibleMapIds.rend(); ++itr)
        for (int32 gxi = gxbegin; gxi < gxend; ++gxi)
            for (int32 gyi = gybegin; gyi < gyend; ++gyi)
                if (map->HasGrid(itr->first, gxi, gyi))
                    return itr->first;

    return map->GetId();
}

void PhasingHandler::SetAlwaysVisible(PhaseShift& phaseShift, bool apply)
{
    if (apply)
        phaseShift.Flags |= PhaseShiftFlags::AlwaysVisible;
    else
        phaseShift.Flags &= ~EnumClassFlag<PhaseShiftFlags>(PhaseShiftFlags::AlwaysVisible);
}

void PhasingHandler::SetInversed(PhaseShift& phaseShift, bool apply)
{
    if (apply)
        phaseShift.Flags |= PhaseShiftFlags::Inverse;
    else
        phaseShift.Flags &= ~EnumClassFlag<PhaseShiftFlags>(PhaseShiftFlags::Inverse);

    phaseShift.UpdateUnphasedFlag();
}

void PhasingHandler::PrintToChat(ChatHandler* chat, PhaseShift const& phaseShift)
{
    chat->PSendSysMessage(LANG_PHASESHIFT_STATUS, phaseShift.Flags.AsUnderlyingType(), phaseShift.PersonalGuid.ToString().c_str());
    if (!phaseShift.Phases.empty())
    {
        std::ostringstream phases;
        std::string cosmetic = sObjectMgr->GetTrinityString(LANG_PHASE_FLAG_COSMETIC, chat->GetSessionDbLocaleIndex());
        std::string personal = sObjectMgr->GetTrinityString(LANG_PHASE_FLAG_PERSONAL, chat->GetSessionDbLocaleIndex());
        for (PhaseShift::PhaseRef const& phase : phaseShift.Phases)
        {
            phases << phase.Id;
            if (phase.Flags.HasFlag(PhaseFlags::Cosmetic))
                phases << ' ' << '(' << cosmetic << ')';
            if (phase.Flags.HasFlag(PhaseFlags::Personal))
                phases << ' ' << '(' << personal << ')';
            phases << ", ";
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

    if (!phaseShift.UiWorldMapAreaIdSwaps.empty())
    {
        std::ostringstream uiWorldMapAreaIdSwaps;
        for (PhaseShift::UiWorldMapAreaIdSwapContainer::value_type const& uiWorldMapAreaIdSwap : phaseShift.UiWorldMapAreaIdSwaps)
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
