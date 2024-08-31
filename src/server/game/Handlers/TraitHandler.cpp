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

#include "WorldSession.h"
#include "Battleground.h"
#include "DB2Stores.h"
#include "Player.h"
#include "SpellHistory.h"
#include "TraitMgr.h"
#include "TraitPackets.h"

void WorldSession::HandleTraitsCommitConfig(WorldPackets::Traits::TraitsCommitConfig const& traitsCommitConfig)
{
    int32 configId = traitsCommitConfig.Config.ID;
    UF::TraitConfig const* existingConfig = _player->GetTraitConfig(configId);
    if (!existingConfig)
    {
        SendPacket(WorldPackets::Traits::TraitConfigCommitFailed(configId, 0, TALENT_FAILED_UNKNOWN).Write());
        return;
    }

    if (_player->IsInCombat())
    {
        SendPacket(WorldPackets::Traits::TraitConfigCommitFailed(configId, 0, TALENT_FAILED_AFFECTING_COMBAT).Write());
        return;
    }

    if (_player->GetBattleground() && _player->GetBattleground()->GetStatus() == STATUS_IN_PROGRESS)
    {
        SendPacket(WorldPackets::Traits::TraitConfigCommitFailed(configId, 0, TALENT_FAILED_IN_PVP_MATCH).Write());
        return;
    }

    auto findEntry = [](WorldPackets::Traits::TraitConfig& config, int32 traitNodeId, int32 traitNodeEntryId) -> WorldPackets::Traits::TraitEntry*
    {
        auto entryItr = std::find_if(config.Entries.begin(), config.Entries.end(), [=](WorldPackets::Traits::TraitEntry const& traitEntry)
        {
            return traitEntry.TraitNodeID == traitNodeId && traitEntry.TraitNodeEntryID == traitNodeEntryId;
        });
        return entryItr != config.Entries.end() ? &*entryItr : nullptr;
    };

    bool hasRemovedEntries = false;
    WorldPackets::Traits::TraitConfig newConfigState(*existingConfig);
    for (WorldPackets::Traits::TraitEntry const& newEntry : traitsCommitConfig.Config.Entries)
    {
        WorldPackets::Traits::TraitEntry* traitEntry = findEntry(newConfigState, newEntry.TraitNodeID, newEntry.TraitNodeEntryID);
        if (traitEntry && traitEntry->Rank > newEntry.Rank)
        {
            TraitNodeEntry const* traitNode = sTraitNodeStore.LookupEntry(newEntry.TraitNodeID);
            if (!traitNode)
            {
                SendPacket(WorldPackets::Traits::TraitConfigCommitFailed(configId, 0, TALENT_FAILED_UNKNOWN).Write());
                return;
            }

            TraitTreeEntry const* traitTree = sTraitTreeStore.LookupEntry(traitNode->TraitTreeID);
            if (!traitTree)
            {
                SendPacket(WorldPackets::Traits::TraitConfigCommitFailed(configId, 0, TALENT_FAILED_UNKNOWN).Write());
                return;
            }

            if (traitTree->GetFlags().HasFlag(TraitTreeFlag::CannotRefund))
            {
                SendPacket(WorldPackets::Traits::TraitConfigCommitFailed(configId, 0, TALENT_FAILED_CANT_REMOVE_TALENT).Write());
                return;
            }

            TraitNodeEntryEntry const* traitNodeEntry = sTraitNodeEntryStore.LookupEntry(newEntry.TraitNodeEntryID);
            if (!traitNodeEntry)
            {
                SendPacket(WorldPackets::Traits::TraitConfigCommitFailed(configId, 0, TALENT_FAILED_UNKNOWN).Write());
                return;
            }

            if (traitNodeEntry->TraitDefinitionID)
            {
                TraitDefinitionEntry const* traitDefinition = sTraitDefinitionStore.LookupEntry(traitNodeEntry->TraitDefinitionID);
                if (!traitDefinition)
                {
                    SendPacket(WorldPackets::Traits::TraitConfigCommitFailed(configId, 0, TALENT_FAILED_UNKNOWN).Write());
                    return;
                }

                if (traitDefinition->SpellID && _player->GetSpellHistory()->HasCooldown(traitDefinition->SpellID))
                {
                    SendPacket(WorldPackets::Traits::TraitConfigCommitFailed(configId, traitDefinition->SpellID, TALENT_FAILED_CANT_REMOVE_TALENT).Write());
                    return;
                }

                if (traitDefinition->VisibleSpellID && _player->GetSpellHistory()->HasCooldown(traitDefinition->VisibleSpellID))
                {
                    SendPacket(WorldPackets::Traits::TraitConfigCommitFailed(configId, traitDefinition->VisibleSpellID, TALENT_FAILED_CANT_REMOVE_TALENT).Write());
                    return;
                }
            }

            hasRemovedEntries = true;
        }

        if (traitEntry)
        {
            if (newEntry.Rank)
                traitEntry->Rank = newEntry.Rank;
            else
                newConfigState.Entries.erase(std::remove_if(newConfigState.Entries.begin(), newConfigState.Entries.end(), [&newEntry](WorldPackets::Traits::TraitEntry const& traitEntry)
                {
                    return traitEntry.TraitNodeID == newEntry.TraitNodeID && traitEntry.TraitNodeEntryID == newEntry.TraitNodeEntryID;
                }), newConfigState.Entries.end());
        }
        else
            newConfigState.Entries.emplace_back() = newEntry;
    }

    TraitMgr::LearnResult validationResult = TraitMgr::ValidateConfig(newConfigState, _player, true);
    if (validationResult != TraitMgr::LearnResult::Ok)
    {
        SendPacket(WorldPackets::Traits::TraitConfigCommitFailed(configId, 0, AsUnderlyingType(validationResult)).Write());
        return;
    }

    bool needsCastTime = newConfigState.Type == TraitConfigType::Combat && hasRemovedEntries;

    if (traitsCommitConfig.SavedLocalIdentifier)
        newConfigState.LocalIdentifier = traitsCommitConfig.SavedLocalIdentifier;
    else if (UF::TraitConfig const* savedConfig = _player->GetTraitConfig(traitsCommitConfig.SavedLocalIdentifier))
        newConfigState.LocalIdentifier = savedConfig->LocalIdentifier;

    _player->UpdateTraitConfig(std::move(newConfigState), traitsCommitConfig.SavedConfigID, needsCastTime);
}

void WorldSession::HandleClassTalentsRequestNewConfig(WorldPackets::Traits::ClassTalentsRequestNewConfig& classTalentsRequestNewConfig)
{
    if (classTalentsRequestNewConfig.Config.Type != TraitConfigType::Combat)
        return;

    if ((classTalentsRequestNewConfig.Config.CombatConfigFlags & TraitCombatConfigFlags::ActiveForSpec) != TraitCombatConfigFlags::None)
        return;

    int64 configCount = std::count_if(_player->m_activePlayerData->TraitConfigs.begin(), _player->m_activePlayerData->TraitConfigs.end(), [](UF::TraitConfig const& traitConfig)
    {
        return static_cast<TraitConfigType>(*traitConfig.Type) == TraitConfigType::Combat
            && (static_cast<TraitCombatConfigFlags>(*traitConfig.CombatConfigFlags) & TraitCombatConfigFlags::ActiveForSpec) == TraitCombatConfigFlags::None;
    });
    if (configCount >= TraitMgr::MAX_COMBAT_TRAIT_CONFIGS)
        return;

    auto findFreeLocalIdentifier = [&]()
    {
        int32 index = 1;
        while (_player->m_activePlayerData->TraitConfigs.FindIndexIf([&](UF::TraitConfig const& traitConfig)
        {
            return static_cast<TraitConfigType>(*traitConfig.Type) == TraitConfigType::Combat
                && traitConfig.ChrSpecializationID == int32(_player->GetPrimarySpecialization())
                && traitConfig.LocalIdentifier == index;
        }) >= 0)
            ++index;

        return index;
    };

    classTalentsRequestNewConfig.Config.ChrSpecializationID = AsUnderlyingType(_player->GetPrimarySpecialization());
    classTalentsRequestNewConfig.Config.LocalIdentifier = findFreeLocalIdentifier();

    for (UF::TraitEntry const& grantedEntry : TraitMgr::GetGrantedTraitEntriesForConfig(classTalentsRequestNewConfig.Config, _player))
    {
        auto entryItr = std::find_if(classTalentsRequestNewConfig.Config.Entries.begin(), classTalentsRequestNewConfig.Config.Entries.end(),
            [&](WorldPackets::Traits::TraitEntry const& entry) { return entry.TraitNodeID == grantedEntry.TraitNodeID && entry.TraitNodeEntryID == grantedEntry.TraitNodeEntryID; });

        WorldPackets::Traits::TraitEntry& newEntry = entryItr != classTalentsRequestNewConfig.Config.Entries.end() ? *entryItr : classTalentsRequestNewConfig.Config.Entries.emplace_back();
        newEntry.TraitNodeID = grantedEntry.TraitNodeID;
        newEntry.TraitNodeEntryID = grantedEntry.TraitNodeEntryID;
        newEntry.Rank = grantedEntry.Rank;
        newEntry.GrantedRanks = grantedEntry.GrantedRanks;
        if (TraitNodeEntryEntry const* traitNodeEntry = sTraitNodeEntryStore.LookupEntry(grantedEntry.TraitNodeEntryID))
            if (newEntry.Rank + newEntry.GrantedRanks > traitNodeEntry->MaxRanks)
                newEntry.Rank = std::max(0, traitNodeEntry->MaxRanks - newEntry.GrantedRanks);
    }

    TraitMgr::LearnResult validationResult = TraitMgr::ValidateConfig(classTalentsRequestNewConfig.Config, _player);
    if (validationResult != TraitMgr::LearnResult::Ok)
        return;

    _player->CreateTraitConfig(classTalentsRequestNewConfig.Config);
}

void WorldSession::HandleClassTalentsRenameConfig(WorldPackets::Traits::ClassTalentsRenameConfig& classTalentsRenameConfig)
{
    _player->RenameTraitConfig(classTalentsRenameConfig.ConfigID, classTalentsRenameConfig.Name.Move());
}

void WorldSession::HandleClassTalentsDeleteConfig(WorldPackets::Traits::ClassTalentsDeleteConfig const& classTalentsDeleteConfig)
{
    _player->DeleteTraitConfig(classTalentsDeleteConfig.ConfigID);
}

void WorldSession::HandleClassTalentsSetStarterBuildActive(WorldPackets::Traits::ClassTalentsSetStarterBuildActive const& classTalentsSetStarterBuildActive)
{
    UF::TraitConfig const* traitConfig = _player->GetTraitConfig(classTalentsSetStarterBuildActive.ConfigID);
    if (!traitConfig)
        return;

    if (static_cast<TraitConfigType>(*traitConfig->Type) != TraitConfigType::Combat)
        return;

    if (!EnumFlag(static_cast<TraitCombatConfigFlags>(*traitConfig->CombatConfigFlags)).HasFlag(TraitCombatConfigFlags::ActiveForSpec))
        return;

    if (classTalentsSetStarterBuildActive.Active)
    {
        WorldPackets::Traits::TraitConfig newConfigState(*traitConfig);

        auto findFreeLocalIdentifier = [&]()
        {
            int32 index = 1;
            while (_player->m_activePlayerData->TraitConfigs.FindIndexIf([&](UF::TraitConfig const& traitConfig)
            {
                return static_cast<TraitConfigType>(*traitConfig.Type) == TraitConfigType::Combat
                    && traitConfig.ChrSpecializationID == int32(_player->GetPrimarySpecialization())
                    && traitConfig.LocalIdentifier == index;
            }) >= 0)
                ++index;

            return index;
        };

        TraitMgr::InitializeStarterBuildTraitConfig(newConfigState, _player);
        newConfigState.CombatConfigFlags |= TraitCombatConfigFlags::StarterBuild;
        newConfigState.LocalIdentifier = findFreeLocalIdentifier();

        _player->UpdateTraitConfig(std::move(newConfigState), 0, true);
    }
    else
        _player->SetTraitConfigUseStarterBuild(classTalentsSetStarterBuildActive.ConfigID, false);
}

void WorldSession::HandleClassTalentsSetUsesSharedActionBars(WorldPackets::Traits::ClassTalentsSetUsesSharedActionBars const& classTalentsSetUsesSharedActionBars)
{
    _player->SetTraitConfigUseSharedActionBars(classTalentsSetUsesSharedActionBars.ConfigID, classTalentsSetUsesSharedActionBars.UsesShared,
        classTalentsSetUsesSharedActionBars.IsLastSelectedSavedConfig);
}
