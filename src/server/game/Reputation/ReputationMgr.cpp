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

#include "ReputationMgr.h"
#include "CharacterPackets.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "Language.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ReputationPackets.h"
#include "ScriptMgr.h"
#include "World.h"
#include "WorldSession.h"

uint32 const ReputationRankStrIndex[MAX_REPUTATION_RANK] =
{
    LANG_REP_HATED,    LANG_REP_HOSTILE, LANG_REP_UNFRIENDLY, LANG_REP_NEUTRAL,
    LANG_REP_FRIENDLY, LANG_REP_HONORED, LANG_REP_REVERED,    LANG_REP_EXALTED
};

std::set<int32> const ReputationMgr::ReputationRankThresholds =
{
    -42000,
    // Hated
    -6000,
    // Hostile
    -3000,
    // Unfriendly
    0,
    // Neutral
    3000,
    // Friendly
    9000,
    // Honored
    21000,
    // Revered
    42000
    // Exalted
};

const int32 ReputationMgr::Reputation_Cap = 42000;
const int32 ReputationMgr::Reputation_Bottom = -42000;

template<typename T, typename F, typename... Rest>
static int32 ReputationToRankHelper(std::set<T, Rest...> const& thresholds, int32 standing, F thresholdExtractor)
{
    auto itr = thresholds.begin();
    auto end = thresholds.end();
    int32 rank = -1;
    while (itr != end && standing >= thresholdExtractor(*itr))
    {
        ++rank;
        ++itr;
    }

    return rank;
}

ReputationRank ReputationMgr::ReputationToRank(FactionEntry const* factionEntry, int32 standing)
{
    int32 rank = MIN_REPUTATION_RANK;
    if (DB2Manager::FriendshipRepReactionSet const* friendshipReactions = sDB2Manager.GetFriendshipRepReactions(factionEntry->FriendshipRepID))
        rank = ReputationToRankHelper(*friendshipReactions, standing, [](FriendshipRepReactionEntry const* frr) { return frr->ReactionThreshold; });
    else
        rank = ReputationToRankHelper(ReputationRankThresholds, standing, [](int32 threshold) { return threshold; });

    return ReputationRank(rank);
}

FactionState const* ReputationMgr::GetState(FactionEntry const* factionEntry) const
{
    return factionEntry->CanHaveReputation() ? GetState(factionEntry->ReputationIndex) : nullptr;
}

bool ReputationMgr::IsAtWar(uint32 faction_id) const
{
    FactionEntry const* factionEntry = sFactionStore.LookupEntry(faction_id);

    if (!factionEntry)
    {
        TC_LOG_ERROR("misc", "ReputationMgr::IsAtWar: Can't get AtWar flag of {} for unknown faction (faction id) #{}.", _player->GetName(), faction_id);
        return false;
    }

    return IsAtWar(factionEntry);
}

bool ReputationMgr::IsAtWar(FactionEntry const* factionEntry) const
{
    if (!factionEntry)
        return false;

    if (FactionState const* factionState = GetState(factionEntry))
        return factionState->Flags.HasFlag(ReputationFlags::AtWar);
    return false;
}

int32 ReputationMgr::GetReputation(uint32 faction_id) const
{
    FactionEntry const* factionEntry = sFactionStore.LookupEntry(faction_id);

    if (!factionEntry)
    {
        TC_LOG_ERROR("misc", "ReputationMgr::GetReputation: Can't get reputation of {} for unknown faction (faction id) #{}.", _player->GetName(), faction_id);
        return 0;
    }

    return GetReputation(factionEntry);
}

int32 ReputationMgr::GetBaseReputation(FactionEntry const* factionEntry) const
{
    int32 dataIndex = GetFactionDataIndexForRaceAndClass(factionEntry);
    if (dataIndex < 0)
        return 0;

    return factionEntry->ReputationBase[dataIndex];
}

int32 ReputationMgr::GetMinReputation(FactionEntry const* factionEntry) const
{
    if (DB2Manager::FriendshipRepReactionSet const* friendshipReactions = sDB2Manager.GetFriendshipRepReactions(factionEntry->FriendshipRepID))
        return (*friendshipReactions->begin())->ReactionThreshold;

    return *ReputationRankThresholds.begin();
}

int32 ReputationMgr::GetMaxReputation(FactionEntry const* factionEntry) const
{
    if (ParagonReputationEntry const* paragonReputation = sDB2Manager.GetParagonReputation(factionEntry->ID))
    {
        // has reward quest, cap is just before threshold for another quest reward
        // for example: if current reputation is 12345 and quests are given every 10000 and player has unclaimed reward
        // then cap will be 19999

        // otherwise cap is one theshold level larger
        // if current reputation is 12345 and questa are given every 10000 and player does NOT have unclaimed reward
        // then cap will be 29999

        int32 reputation = GetReputation(factionEntry);
        int32 cap = reputation + paragonReputation->LevelThreshold - reputation % paragonReputation->LevelThreshold - 1;

        if (_player->GetQuestStatus(paragonReputation->QuestID) == QUEST_STATUS_NONE)
            cap += paragonReputation->LevelThreshold;

        return cap;
    }

    if (IsRenownReputation(factionEntry))
    {
        // Compared to a paragon reputation, DF renown reputations
        // have a maximum value of 2500 which resets with each level of renown acquired.
        // We calculate the total reputation necessary to raise the renown to the maximum
        return GetRenownMaxLevel(factionEntry) * GetRenownLevelThreshold(factionEntry);
    }

    if (DB2Manager::FriendshipRepReactionSet const* friendshipReactions = sDB2Manager.GetFriendshipRepReactions(factionEntry->FriendshipRepID))
        return (*friendshipReactions->rbegin())->ReactionThreshold;

    int32 dataIndex = GetFactionDataIndexForRaceAndClass(factionEntry);
    if (dataIndex >= 0)
        return factionEntry->ReputationMax[dataIndex];

    return *ReputationRankThresholds.rbegin();
}

int32 ReputationMgr::GetReputation(FactionEntry const* factionEntry) const
{
    // Faction without recorded reputation. Just ignore.
    if (!factionEntry)
        return 0;

    if (FactionState const* state = GetState(factionEntry))
        return GetBaseReputation(factionEntry) + state->Standing;

    return 0;
}

ReputationRank ReputationMgr::GetRank(FactionEntry const* factionEntry) const
{
    int32 reputation = GetReputation(factionEntry);
    return ReputationToRank(factionEntry, reputation);
}

ReputationRank ReputationMgr::GetBaseRank(FactionEntry const* factionEntry) const
{
    int32 reputation = GetBaseReputation(factionEntry);
    return ReputationToRank(factionEntry, reputation);
}

std::string ReputationMgr::GetReputationRankName(FactionEntry const* factionEntry) const
{
    ReputationRank rank = GetRank(factionEntry);
    if (!factionEntry->FriendshipRepID)
        return sObjectMgr->GetTrinityString(ReputationRankStrIndex[GetRank(factionEntry)], _player->GetSession()->GetSessionDbcLocale());

    if (DB2Manager::FriendshipRepReactionSet const* friendshipReactions = sDB2Manager.GetFriendshipRepReactions(factionEntry->FriendshipRepID))
    {
        auto itr = friendshipReactions->begin();
        std::advance(itr, uint32(rank));
        return (*itr)->Reaction[_player->GetSession()->GetSessionDbcLocale()];
    }

    return "";
}

ReputationRank const* ReputationMgr::GetForcedRankIfAny(FactionTemplateEntry const* factionTemplateEntry) const
{
    return GetForcedRankIfAny(factionTemplateEntry->Faction);
}

bool ReputationMgr::IsParagonReputation(FactionEntry const* factionEntry) const
{
    if (sDB2Manager.GetParagonReputation(factionEntry->ID))
        return true;

    return false;
}

int32 ReputationMgr::GetParagonLevel(uint32 paragonFactionId) const
{
    return GetParagonLevel(sFactionStore.LookupEntry(paragonFactionId));
}

int32 ReputationMgr::GetParagonLevel(FactionEntry const* paragonFactionEntry) const
{
    if (!paragonFactionEntry)
        return 0;

    if (ParagonReputationEntry const* paragonReputation = sDB2Manager.GetParagonReputation(paragonFactionEntry->ID))
        return GetReputation(paragonFactionEntry) / paragonReputation->LevelThreshold;

    return 0;
}

bool ReputationMgr::HasMaximumRenownReputation(FactionEntry const* factionEntry) const
{
    if (!IsRenownReputation(factionEntry))
        return false;

    return GetRenownLevel(factionEntry) >= GetRenownMaxLevel(factionEntry);
}

bool ReputationMgr::IsRenownReputation(FactionEntry const* factionEntry) const
{
    return factionEntry->RenownCurrencyID > 0;
}

int32 ReputationMgr::GetRenownLevel(FactionEntry const* renownFactionEntry) const
{
    if (!renownFactionEntry)
        return 0;

    if (CurrencyTypesEntry const* currency = sCurrencyTypesStore.LookupEntry(renownFactionEntry->RenownCurrencyID))
        return _player->GetCurrencyQuantity(currency->ID);

    return 0;
}

int32 ReputationMgr::GetRenownLevelThreshold(FactionEntry const* renownFactionEntry) const
{
    if (!renownFactionEntry || !IsRenownReputation(renownFactionEntry))
        return 0;

    int32 dataIndex = GetFactionDataIndexForRaceAndClass(renownFactionEntry);
    if (dataIndex >= 0)
        return renownFactionEntry->ReputationMax[dataIndex];

    return 0;
}

int32 ReputationMgr::GetRenownMaxLevel(FactionEntry const* renownFactionEntry) const
{
    if (!renownFactionEntry)
        return 0;

    if (CurrencyTypesEntry const* currency = sCurrencyTypesStore.LookupEntry(renownFactionEntry->RenownCurrencyID))
        return _player->GetCurrencyMaxQuantity(currency);

    return 0;
}

void ReputationMgr::ApplyForceReaction(uint32 faction_id, ReputationRank rank, bool apply)
{
    if (apply)
        _forcedReactions[faction_id] = rank;
    else
        _forcedReactions.erase(faction_id);
}

ReputationFlags ReputationMgr::GetDefaultStateFlags(FactionEntry const* factionEntry) const
{
    ReputationFlags flags = [&]()
    {
        int32 dataIndex = GetFactionDataIndexForRaceAndClass(factionEntry);
        if (dataIndex < 0)
            return ReputationFlags::None;

        return static_cast<ReputationFlags>(factionEntry->ReputationFlags[dataIndex]);
    }();

    if (sDB2Manager.GetParagonReputation(factionEntry->ID))
        flags |= ReputationFlags::ShowPropagated;

    return flags;
}

void ReputationMgr::SendForceReactions()
{
    WorldPackets::Reputation::SetForcedReactions setForcedReactions;
    setForcedReactions.Reactions.resize(_forcedReactions.size());

    std::size_t i = 0;
    for (ForcedReactions::const_iterator itr = _forcedReactions.begin(); itr != _forcedReactions.end(); ++itr)
    {
        WorldPackets::Reputation::ForcedReaction& forcedReaction = setForcedReactions.Reactions[i++];
        forcedReaction.Faction = int32(itr->first);
        forcedReaction.Reaction = int32(itr->second);
    }

    _player->SendDirectMessage(setForcedReactions.Write());
}

void ReputationMgr::SendState(FactionState const* faction)
{
    WorldPackets::Reputation::SetFactionStanding setFactionStanding;
    setFactionStanding.BonusFromAchievementSystem = 0.0f;

    auto getStandingForPacket = [](FactionState const* state)
    {
        return state->VisualStandingIncrease ? state->VisualStandingIncrease : state->Standing;
    };

    if (faction)
        setFactionStanding.Faction.emplace_back(int32(faction->ReputationListID), getStandingForPacket(faction));

    for (auto& [reputationIndex, state] : _factions)
    {
        if (state.needSend)
        {
            state.needSend = false;
            if (!faction || state.ReputationListID != faction->ReputationListID)
                setFactionStanding.Faction.emplace_back(int32(state.ReputationListID), getStandingForPacket(&state));
        }
    }

    setFactionStanding.ShowVisual = _sendFactionIncreased;
    _player->SendDirectMessage(setFactionStanding.Write());

    _sendFactionIncreased = false; // Reset
}

void ReputationMgr::SendInitialReputations()
{
    WorldPackets::Reputation::InitializeFactions initFactions;

    for (FactionStateList::iterator itr = _factions.begin(); itr != _factions.end(); ++itr)
    {
        WorldPackets::Reputation::FactionData& factionData = initFactions.Factions.emplace_back();
        factionData.FactionID = itr->second.ID;
        factionData.Flags = itr->second.Flags.AsUnderlyingType();
        factionData.Standing = itr->second.Standing;
        /// @todo faction bonus
        WorldPackets::Reputation::FactionBonusData& bonus = initFactions.Bonuses.emplace_back();
        bonus.FactionID = itr->second.ID;
        bonus.FactionHasBonus = false;
        itr->second.needSend = false;
    }

    _player->SendDirectMessage(initFactions.Write());
}

void ReputationMgr::SendVisible(FactionState const* faction, bool visible) const
{
    if (_player->GetSession()->PlayerLoading())
        return;

    // make faction visible/not visible in reputation list at client
    WorldPackets::Character::SetFactionVisible packet(visible);
    packet.FactionIndex = faction->ReputationListID;
    _player->SendDirectMessage(packet.Write());
}

void ReputationMgr::Initialize()
{
    _factions.clear();
    _visibleFactionCount = 0;
    _honoredFactionCount = 0;
    _reveredFactionCount = 0;
    _exaltedFactionCount = 0;
    _sendFactionIncreased = false;

    for (FactionEntry const* factionEntry : sFactionStore)
    {
        if (factionEntry->CanHaveReputation())
        {
            FactionState newFaction;
            newFaction.ID = factionEntry->ID;
            newFaction.ReputationListID = factionEntry->ReputationIndex;
            newFaction.Standing = 0;
            newFaction.VisualStandingIncrease = 0;
            newFaction.Flags = GetDefaultStateFlags(factionEntry);
            newFaction.needSend = true;
            newFaction.needSave = true;

            if (newFaction.Flags.HasFlag(ReputationFlags::Visible))
                ++_visibleFactionCount;

            if (!factionEntry->FriendshipRepID)
                UpdateRankCounters(REP_HOSTILE, GetBaseRank(factionEntry));

            _factions[newFaction.ReputationListID] = newFaction;
        }
    }
}

bool ReputationMgr::SetReputation(FactionEntry const* factionEntry, int32 standing, bool incremental, bool spillOverOnly, bool noSpillover)
{
    sScriptMgr->OnPlayerReputationChange(_player, factionEntry->ID, standing, incremental);
    bool res = false;
    if (!noSpillover)
    {
        // if spillover definition exists in DB, override DBC
        if (RepSpilloverTemplate const* repTemplate = sObjectMgr->GetRepSpilloverTemplate(factionEntry->ID))
        {
            for (uint32 i = 0; i < MAX_SPILLOVER_FACTIONS; ++i)
            {
                if (repTemplate->faction[i])
                {
                    if (_player->GetReputationRank(repTemplate->faction[i]) <= ReputationRank(repTemplate->faction_rank[i]))
                    {
                        // bonuses are already given, so just modify standing by rate
                        int32 spilloverRep = int32(standing * repTemplate->faction_rate[i]);
                        SetOneFactionReputation(sFactionStore.AssertEntry(repTemplate->faction[i]), spilloverRep, incremental);
                    }
                }
            }
        }
        else
        {
            float spillOverRepOut = float(standing);
            // check for sub-factions that receive spillover
            std::vector<uint32> const* flist = sDB2Manager.GetFactionTeamList(factionEntry->ID);
            // if has no sub-factions, check for factions with same parent
            if (!flist && factionEntry->ParentFactionID && factionEntry->ParentFactionMod[1] != 0.0f)
            {
                spillOverRepOut *= factionEntry->ParentFactionMod[1];
                if (FactionEntry const* parent = sFactionStore.LookupEntry(factionEntry->ParentFactionID))
                {
                    FactionStateList::iterator parentState = _factions.find(parent->ReputationIndex);
                    // some team factions have own reputation standing, in this case do not spill to other sub-factions
                    if (parentState != _factions.end() && parentState->second.Flags.HasFlag(ReputationFlags::HeaderShowsBar))
                    {
                        SetOneFactionReputation(parent, int32(spillOverRepOut), incremental);
                    }
                    else    // spill to "sister" factions
                    {
                        flist = sDB2Manager.GetFactionTeamList(factionEntry->ParentFactionID);
                    }
                }
            }
            if (flist)
            {
                // Spillover to affiliated factions
                for (std::vector<uint32>::const_iterator itr = flist->begin(); itr != flist->end(); ++itr)
                {
                    if (FactionEntry const* factionEntryCalc = sFactionStore.LookupEntry(*itr))
                    {
                        if (factionEntryCalc == factionEntry || GetRank(factionEntryCalc) > ReputationRank(factionEntryCalc->ParentFactionCap[0]))
                            continue;
                        int32 spilloverRep = int32(spillOverRepOut * factionEntryCalc->ParentFactionMod[0]);
                        if (spilloverRep != 0 || !incremental)
                            res = SetOneFactionReputation(factionEntryCalc, spilloverRep, incremental);
                    }
                }
            }
        }
    }

    // spillover done, update faction itself
    FactionStateList::iterator faction = _factions.find(factionEntry->ReputationIndex);
    if (faction != _factions.end())
    {
        FactionEntry const* primaryFactionToModify = factionEntry;
        if (incremental && standing > 0 && CanGainParagonReputationForFaction(factionEntry))
        {
            primaryFactionToModify = sFactionStore.AssertEntry(factionEntry->ParagonFactionID);
            faction = _factions.find(primaryFactionToModify->ReputationIndex);
        }

        if (faction != _factions.end())
        {
            // if we update spillover only, do not update main reputation (rank exceeds creature reward rate)
            if (!spillOverOnly)
                res = SetOneFactionReputation(primaryFactionToModify, standing, incremental);

            // only this faction gets reported to client, even if it has no own visible standing
            SendState(&faction->second);
        }
    }
    return res;
}

bool ReputationMgr::SetOneFactionReputation(FactionEntry const* factionEntry, int32 standing, bool incremental)
{
    FactionStateList::iterator itr = _factions.find(factionEntry->ReputationIndex);
    if (itr != _factions.end())
    {
        // Ignore renown reputation already raised to the maximum level
        if (HasMaximumRenownReputation(factionEntry) && standing > 0)
        {
            itr->second.needSend = false;
            itr->second.needSave = false;
            return false;
        }

        int32 baseRep = GetBaseReputation(factionEntry);
        int32 oldStanding = itr->second.Standing + baseRep;

        if (incremental || IsRenownReputation(factionEntry))
        {
            // int32 *= float cause one point loss?
            standing = int32(floor((float)standing * sWorld->getRate(RATE_REPUTATION_GAIN) + 0.5f));
            standing += oldStanding;
        }

        if (standing > GetMaxReputation(factionEntry))
            standing = GetMaxReputation(factionEntry);
        else if (standing < GetMinReputation(factionEntry))
            standing = GetMinReputation(factionEntry);

        // Ignore rank for paragon or renown reputation
        if (!IsParagonReputation(factionEntry) && !IsRenownReputation(factionEntry))
        {
            ReputationRank oldRank = ReputationToRank(factionEntry, oldStanding);
            ReputationRank newRank = ReputationToRank(factionEntry, standing);

            if (newRank <= REP_HOSTILE)
                SetAtWar(&itr->second, true);

            if (newRank > oldRank)
                _sendFactionIncreased = true;

            if (!factionEntry->FriendshipRepID)
                UpdateRankCounters(oldRank, newRank);
        }
        else
            _sendFactionIncreased = true; // TODO: Check Paragon reputation

        // Calculate new standing and reputation change
        int32 newStanding = 0;
        int32 reputationChange = standing - oldStanding;

        if (!IsRenownReputation(factionEntry))
            newStanding = standing - baseRep;
        else
        {
            if (CurrencyTypesEntry const* currency = sCurrencyTypesStore.LookupEntry(factionEntry->RenownCurrencyID))
            {
                int32 renownLevelThreshold = GetRenownLevelThreshold(factionEntry);
                int32 oldRenownLevel = GetRenownLevel(factionEntry);

                int32 totalReputation = (oldRenownLevel * renownLevelThreshold) + (standing - baseRep);
                int32 newRenownLevel = totalReputation / renownLevelThreshold;
                newStanding = totalReputation % renownLevelThreshold;

                if (newRenownLevel >= GetRenownMaxLevel(factionEntry))
                {
                    newStanding = 0;
                    reputationChange += (GetRenownMaxLevel(factionEntry) * renownLevelThreshold) - totalReputation;
                }

                itr->second.VisualStandingIncrease = reputationChange;

                // If the reputation is decreased by command, we will send CurrencyDestroyReason::Cheat
                if (oldRenownLevel != newRenownLevel)
                    _player->ModifyCurrency(currency->ID, newRenownLevel - oldRenownLevel, CurrencyGainSource::RenownRepGain, CurrencyDestroyReason::Cheat);
            }
        }

        _player->ReputationChanged(factionEntry, reputationChange);

        itr->second.Standing = newStanding;
        itr->second.needSend = true;
        itr->second.needSave = true;

        SetVisible(&itr->second);

        ParagonReputationEntry const* paragonReputation = sDB2Manager.GetParagonReputation(factionEntry->ID);
        if (paragonReputation)
        {
            int32 oldParagonLevel = oldStanding / paragonReputation->LevelThreshold;
            int32 newParagonLevel = standing / paragonReputation->LevelThreshold;
            if (oldParagonLevel != newParagonLevel)
                if (Quest const* paragonRewardQuest = sObjectMgr->GetQuestTemplate(paragonReputation->QuestID))
                    _player->AddQuestAndCheckCompletion(paragonRewardQuest, nullptr);
        }

        _player->UpdateCriteria(CriteriaType::TotalFactionsEncountered, factionEntry->ID);
        _player->UpdateCriteria(CriteriaType::ReputationGained,         factionEntry->ID);
        _player->UpdateCriteria(CriteriaType::TotalExaltedFactions,     factionEntry->ID);
        _player->UpdateCriteria(CriteriaType::TotalReveredFactions,     factionEntry->ID);
        _player->UpdateCriteria(CriteriaType::TotalHonoredFactions,     factionEntry->ID);

        return true;
    }
    return false;
}

void ReputationMgr::SetVisible(FactionTemplateEntry const* factionTemplateEntry)
{
    if (!factionTemplateEntry->Faction)
        return;

    if (FactionEntry const* factionEntry = sFactionStore.LookupEntry(factionTemplateEntry->Faction))
        // Never show factions of the opposing team
        if (!(factionEntry->ReputationRaceMask[1].HasRace(_player->GetRace()) && factionEntry->ReputationBase[1] == Reputation_Bottom))
            SetVisible(factionEntry);
}

void ReputationMgr::SetVisible(FactionEntry const* factionEntry)
{
    if (!factionEntry->CanHaveReputation())
        return;

    FactionStateList::iterator itr = _factions.find(factionEntry->ReputationIndex);
    if (itr == _factions.end())
        return;

    SetVisible(&itr->second);
}

void ReputationMgr::SetVisible(FactionState* faction)
{
    // always invisible or hidden faction can't be make visible
    if (faction->Flags.HasFlag(ReputationFlags::Hidden))
        return;

    if (faction->Flags.HasFlag(ReputationFlags::Header) && !faction->Flags.HasFlag(ReputationFlags::HeaderShowsBar))
        return;

    if (sDB2Manager.GetParagonReputation(faction->ID))
        return;

    // already set
    if (faction->Flags.HasFlag(ReputationFlags::Visible))
        return;

    faction->Flags |= ReputationFlags::Visible;
    faction->needSend = true;
    faction->needSave = true;

    ++_visibleFactionCount;

    SendVisible(faction);
}

void ReputationMgr::SetAtWar(RepListID repListID, bool on)
{
    FactionStateList::iterator itr = _factions.find(repListID);
    if (itr == _factions.end())
        return;

    // always invisible or hidden faction can't change war state
    if (itr->second.Flags.HasFlag(ReputationFlags::Hidden | ReputationFlags::Header))
        return;

    SetAtWar(&itr->second, on);
}

void ReputationMgr::SetAtWar(FactionState* faction, bool atWar) const
{
    // Do not allow to declare war to our own faction. But allow for rival factions (eg Aldor vs Scryer).
    if (atWar && faction->Flags.HasFlag(ReputationFlags::Peaceful) && GetRank(sFactionStore.AssertEntry(faction->ID)) > REP_HATED)
        return;

    // already set
    if (faction->Flags.HasFlag(ReputationFlags::AtWar) == atWar)
        return;

    if (atWar)
        faction->Flags |= ReputationFlags::AtWar;
    else
        faction->Flags &= ~ReputationFlags::AtWar;

    faction->needSend = true;
    faction->needSave = true;
}

void ReputationMgr::SetInactive(RepListID repListID, bool on)
{
    FactionStateList::iterator itr = _factions.find(repListID);
    if (itr == _factions.end())
        return;

    SetInactive(&itr->second, on);
}

void ReputationMgr::SetInactive(FactionState* faction, bool inactive) const
{
    // always invisible or hidden faction can't be inactive
    if (faction->Flags.HasFlag(ReputationFlags::Hidden | ReputationFlags::Header) || !faction->Flags.HasFlag(ReputationFlags::Visible))
        return;

    // already set
    if (faction->Flags.HasFlag(ReputationFlags::Inactive) == inactive)
        return;

    if (inactive)
        faction->Flags |= ReputationFlags::Inactive;
    else
        faction->Flags &= ~ReputationFlags::Inactive;

    faction->needSend = true;
    faction->needSave = true;
}

void ReputationMgr::LoadFromDB(PreparedQueryResult result)
{
    // Set initial reputations (so everything is nifty before DB data load)
    Initialize();

    //QueryResult* result = CharacterDatabase.PQuery("SELECT faction, standing, flags FROM character_reputation WHERE guid = '{}'", GetGUIDLow());

    if (result)
    {
        do
        {
            Field* fields = result->Fetch();

            FactionEntry const* factionEntry = sFactionStore.LookupEntry(fields[0].GetUInt16());
            if (factionEntry && factionEntry->CanHaveReputation())
            {
                FactionState* faction = &_factions[factionEntry->ReputationIndex];

                // update standing to current
                faction->Standing = fields[1].GetInt32();

                // update counters
                if (!factionEntry->FriendshipRepID)
                {
                    int32 BaseRep = GetBaseReputation(factionEntry);
                    ReputationRank old_rank = ReputationToRank(factionEntry, BaseRep);
                    ReputationRank new_rank = ReputationToRank(factionEntry, BaseRep + faction->Standing);
                    UpdateRankCounters(old_rank, new_rank);
                }

                EnumFlag<ReputationFlags> dbFactionFlags = static_cast<ReputationFlags>(fields[2].GetUInt16());

                if (dbFactionFlags.HasFlag(ReputationFlags::Visible))
                    SetVisible(faction);                                    // have internal checks for forced invisibility

                if (dbFactionFlags.HasFlag(ReputationFlags::Inactive))
                    SetInactive(faction, true);                             // have internal checks for visibility requirement

                if (dbFactionFlags.HasFlag(ReputationFlags::AtWar))    // DB at war
                    SetAtWar(faction, true);                                // have internal checks for ReputationFlags::Peaceful
                else                                                        // DB not at war
                {
                    // allow remove if visible (and then not FACTION_FLAG_INVISIBLE_FORCED or FACTION_FLAG_HIDDEN)
                    if (faction->Flags.HasFlag(ReputationFlags::Visible))
                        SetAtWar(faction, false);                           // have internal checks for ReputationFlags::Peaceful
                }

                // set atWar for hostile
                if (GetRank(factionEntry) <= REP_HOSTILE)
                    SetAtWar(faction, true);

                // reset changed flag if values similar to saved in DB
                if (faction->Flags == dbFactionFlags)
                {
                    faction->needSend = false;
                    faction->needSave = false;
                }
            }
        }
        while (result->NextRow());
    }
}

void ReputationMgr::SaveToDB(CharacterDatabaseTransaction trans)
{
    for (FactionStateList::iterator itr = _factions.begin(); itr != _factions.end(); ++itr)
    {
        if (itr->second.needSave)
        {
            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_REPUTATION_BY_FACTION);
            stmt->setUInt64(0, _player->GetGUID().GetCounter());
            stmt->setUInt16(1, uint16(itr->second.ID));
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_REPUTATION_BY_FACTION);
            stmt->setUInt64(0, _player->GetGUID().GetCounter());
            stmt->setUInt16(1, uint16(itr->second.ID));
            stmt->setInt32(2, itr->second.Standing);
            stmt->setUInt16(3, itr->second.Flags.AsUnderlyingType());
            trans->Append(stmt);

            itr->second.needSave = false;
        }
    }
}

void ReputationMgr::UpdateRankCounters(ReputationRank old_rank, ReputationRank new_rank)
{
    if (old_rank >= REP_EXALTED)
        --_exaltedFactionCount;
    if (old_rank >= REP_REVERED)
        --_reveredFactionCount;
    if (old_rank >= REP_HONORED)
        --_honoredFactionCount;

    if (new_rank >= REP_EXALTED)
        ++_exaltedFactionCount;
    if (new_rank >= REP_REVERED)
        ++_reveredFactionCount;
    if (new_rank >= REP_HONORED)
        ++_honoredFactionCount;
}

int32 ReputationMgr::GetFactionDataIndexForRaceAndClass(FactionEntry const* factionEntry) const
{
    if (!factionEntry)
        return -1;

    uint8 race = _player->GetRace();
    uint32 classMask = _player->GetClassMask();
    for (int32 i = 0; i < 4; i++)
    {
        if ((factionEntry->ReputationRaceMask[i].HasRace(race) || (factionEntry->ReputationRaceMask[i].IsEmpty() && factionEntry->ReputationClassMask[i] != 0))
            && (factionEntry->ReputationClassMask[i] & classMask || factionEntry->ReputationClassMask[i] == 0))

            return i;
    }

    return -1;
}

bool ReputationMgr::CanGainParagonReputationForFaction(FactionEntry const* factionEntry) const
{
    if (!sFactionStore.LookupEntry(factionEntry->ParagonFactionID))
        return false;

    if (GetRank(factionEntry) != REP_EXALTED && !HasMaximumRenownReputation(factionEntry))
        return false;

    ParagonReputationEntry const* paragonReputation = sDB2Manager.GetParagonReputation(factionEntry->ParagonFactionID);
    if (!paragonReputation)
        return false;

    Quest const* quest = sObjectMgr->GetQuestTemplate(paragonReputation->QuestID);
    if (!quest)
        return false;

    return _player->GetLevel() >= _player->GetQuestMinLevel(quest);
}
