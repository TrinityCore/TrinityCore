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

void Load();
int32 GenerateNewTraitConfigId();
TraitConfigType GetConfigTypeForTree(int32 traitTreeId);
void FillSpentCurrenciesMap(WorldPackets::Traits::TraitEntry const& entry, std::map<int32, int32>& cachedCurrencies);
std::vector<UF::TraitEntry> GetGrantedTraitEntriesForConfig(WorldPackets::Traits::TraitConfig const& traitConfig, Player const* player);
bool IsValidEntry(WorldPackets::Traits::TraitEntry const& traitEntry);
TalentLearnResult ValidateConfig(WorldPackets::Traits::TraitConfig const& traitConfig, Player const* player, bool requireSpendingAllCurrencies = false);
std::vector<TraitDefinitionEffectPointsEntry const*> const* GetTraitDefinitionEffectPointModifiers(int32 traitDefinitionId);
void InitializeStarterBuildTraitConfig(WorldPackets::Traits::TraitConfig& traitConfig, Player const* player);
}

#endif // TRINITY_TRAIT_MGR_H
