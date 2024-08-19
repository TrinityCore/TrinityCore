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

#ifndef TRINITY_TRAIT_MGR_H
#define TRINITY_TRAIT_MGR_H

#include "Define.h"
#include <map>
#include <vector>

class Player;
struct TraitDefinitionEffectPointsEntry;
enum class TraitConfigType : int32;
enum TalentLearnResult : int32;

namespace UF
{
struct TraitConfig;
struct TraitEntry;
}

namespace WorldPackets::Traits
{
struct TraitConfig;
struct TraitEntry;
}

namespace TraitMgr
{
constexpr uint32 COMMIT_COMBAT_TRAIT_CONFIG_CHANGES_SPELL_ID = 384255u;
constexpr uint32 MAX_COMBAT_TRAIT_CONFIGS = 10u;

enum class LearnResult : int32
{
    Ok                              = 0,
    Unknown                         = 1,
    NotEnoughTalentsInPrimaryTree   = 2,
    NoPrimaryTreeSelected           = 3,
    CantDoThatRightNow              = 4,
    AffectingCombat                 = 5,
    CantRemoveTalent                = 6,
    CantDoThatChallengeModeActive   = 7,
    RestArea                        = 8,
    UnspentTalentPoints             = 9,
    InPvpMatch                      = 10
};

struct PlayerDataAccessor
{
    /*implicit*/ PlayerDataAccessor(Player const* player) : _player(player) { }

    uint64 GetMoney() const;
    int32 GetCurrencyQuantity(int32 currencyId) const;
    int32 GetLevel() const;
    bool IsQuestRewarded(int32 questId) const;
    bool HasAchieved(int32 achievementId) const;
    uint32 GetPrimarySpecialization() const;

private:
    Player const* _player;
};

void Load();
int32 GenerateNewTraitConfigId();
TraitConfigType GetConfigTypeForTree(int32 traitTreeId);
void FillSpentCurrenciesMap(WorldPackets::Traits::TraitEntry const& entry, std::map<int32, int32>& cachedCurrencies);
std::vector<UF::TraitEntry> GetGrantedTraitEntriesForConfig(WorldPackets::Traits::TraitConfig const& traitConfig, PlayerDataAccessor player);
bool IsValidEntry(WorldPackets::Traits::TraitEntry const& traitEntry);
LearnResult ValidateConfig(WorldPackets::Traits::TraitConfig& traitConfig, PlayerDataAccessor player, bool requireSpendingAllCurrencies = false, bool removeInvalidEntries = false);
bool CanApplyTraitNode(UF::TraitConfig const& traitConfig, UF::TraitEntry const& traitEntry);
std::vector<TraitDefinitionEffectPointsEntry const*> const* GetTraitDefinitionEffectPointModifiers(int32 traitDefinitionId);
void InitializeStarterBuildTraitConfig(WorldPackets::Traits::TraitConfig& traitConfig, PlayerDataAccessor player);
}

#endif // TRINITY_TRAIT_MGR_H
