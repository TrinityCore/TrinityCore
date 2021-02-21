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
#include "Log.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ReputationPackets.h"
#include "ScriptMgr.h"
#include "World.h"
#include "WorldSession.h"

const int32 ReputationMgr::PointsInRank[MAX_REPUTATION_RANK] = {36000, 3000, 3000, 3000, 6000, 12000, 21000, 1000};

const int32 ReputationMgr::Reputation_Cap = 42999;
const int32 ReputationMgr::Reputation_Bottom = -42000;

ReputationRank ReputationMgr::ReputationToRank(int32 standing)
{
    int32 limit = Reputation_Cap + 1;
    for (int i = MAX_REPUTATION_RANK-1; i >= MIN_REPUTATION_RANK; --i)
    {
        limit -= PointsInRank[i];
        if (standing >= limit)
            return ReputationRank(i);
    }
    return MIN_REPUTATION_RANK;
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
        TC_LOG_ERROR("misc", "ReputationMgr::IsAtWar: Can't get AtWar flag of %s for unknown faction (faction id) #%u.", _player->GetName().c_str(), faction_id);
        return false;
    }

    return IsAtWar(factionEntry);
}

bool ReputationMgr::IsAtWar(FactionEntry const* factionEntry) const
{
    if (!factionEntry)
        return false;

    if (FactionState const* factionState = GetState(factionEntry))
        return (factionState->Flags & FACTION_FLAG_AT_WAR) != 0;
    return false;
}

int32 ReputationMgr::GetReputation(uint32 faction_id) const
{
    FactionEntry const* factionEntry = sFactionStore.LookupEntry(faction_id);

    if (!factionEntry)
    {
        TC_LOG_ERROR("misc", "ReputationMgr::GetReputation: Can't get reputation of %s for unknown faction (faction id) #%u.", _player->GetName().c_str(), faction_id);
        return 0;
    }

    return GetReputation(factionEntry);
}

int32 ReputationMgr::GetBaseReputation(FactionEntry const* factionEntry) const
{
    if (!factionEntry)
        return 0;

    uint8 race = _player->getRace();
    uint32 classMask = _player->getClassMask();
    for (int i=0; i < 4; i++)
    {
        if ((factionEntry->ReputationRaceMask[i].HasRace(race) ||
            (!factionEntry->ReputationRaceMask[i] &&
             factionEntry->ReputationClassMask[i] != 0)) &&
            (factionEntry->ReputationClassMask[i] & classMask ||
             factionEntry->ReputationClassMask[i] == 0))

            return factionEntry->ReputationBase[i];
    }

    // in faction.dbc exist factions with (RepListId >=0, listed in character reputation list) with all BaseRepRaceMask[i] == 0
    return 0;
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
    return ReputationToRank(reputation);
}

ReputationRank ReputationMgr::GetBaseRank(FactionEntry const* factionEntry) const
{
    int32 reputation = GetBaseReputation(factionEntry);
    return ReputationToRank(reputation);
}

ReputationRank const* ReputationMgr::GetForcedRankIfAny(FactionTemplateEntry const* factionTemplateEntry) const
{
    return GetForcedRankIfAny(factionTemplateEntry->Faction);
}

void ReputationMgr::ApplyForceReaction(uint32 faction_id, ReputationRank rank, bool apply)
{
    if (apply)
        _forcedReactions[faction_id] = rank;
    else
        _forcedReactions.erase(faction_id);
}

uint32 ReputationMgr::GetDefaultStateFlags(FactionEntry const* factionEntry) const
{
    if (!factionEntry)
        return 0;

    uint8 race = _player->getRace();
    uint32 classMask = _player->getClassMask();
    for (int i=0; i < 4; i++)
    {
        if ((factionEntry->ReputationRaceMask[i].HasRace(race) ||
            (!factionEntry->ReputationRaceMask[i] &&
             factionEntry->ReputationClassMask[i] != 0)) &&
            (factionEntry->ReputationClassMask[i] & classMask ||
             factionEntry->ReputationClassMask[i] == 0))

            return factionEntry->ReputationFlags[i];
    }
    return 0;
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
    setFactionStanding.ReferAFriendBonus = 0.0f;
    setFactionStanding.BonusFromAchievementSystem = 0.0f;

    if (faction)
        setFactionStanding.Faction.emplace_back(int32(faction->ReputationListID), faction->Standing);

    for (FactionStateList::iterator itr = _factions.begin(); itr != _factions.end(); ++itr)
    {
        if (itr->second.needSend)
        {
            itr->second.needSend = false;
            if (!faction || itr->second.ReputationListID != faction->ReputationListID)
                setFactionStanding.Faction.emplace_back(int32(itr->second.ReputationListID), itr->second.Standing);
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
        initFactions.FactionFlags[itr->first] = itr->second.Flags;
        initFactions.FactionStandings[itr->first] = itr->second.Standing;
        /// @todo faction bonus
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
            newFaction.Flags = GetDefaultStateFlags(factionEntry);
            newFaction.needSend = true;
            newFaction.needSave = true;

            if (newFaction.Flags & FACTION_FLAG_VISIBLE)
                ++_visibleFactionCount;

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
                    if (parentState != _factions.end() && (parentState->second.Flags & FACTION_FLAG_SPECIAL))
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
        // if we update spillover only, do not update main reputation (rank exceeds creature reward rate)
        if (!spillOverOnly)
            res = SetOneFactionReputation(factionEntry, standing, incremental);

        // only this faction gets reported to client, even if it has no own visible standing
        SendState(&faction->second);
    }
    return res;
}

bool ReputationMgr::SetOneFactionReputation(FactionEntry const* factionEntry, int32 standing, bool incremental)
{
    FactionStateList::iterator itr = _factions.find(factionEntry->ReputationIndex);
    if (itr != _factions.end())
    {
        int32 BaseRep = GetBaseReputation(factionEntry);

        if (incremental)
        {
            // int32 *= float cause one point loss?
            standing = int32(floor((float)standing * sWorld->getRate(RATE_REPUTATION_GAIN) + 0.5f));
            standing += itr->second.Standing + BaseRep;
        }

        if (standing > Reputation_Cap)
            standing = Reputation_Cap;
        else if (standing < Reputation_Bottom)
            standing = Reputation_Bottom;

        ReputationRank old_rank = ReputationToRank(itr->second.Standing + BaseRep);
        ReputationRank new_rank = ReputationToRank(standing);

        itr->second.Standing = standing - BaseRep;
        itr->second.needSend = true;
        itr->second.needSave = true;

        SetVisible(&itr->second);

        if (new_rank <= REP_HOSTILE)
            SetAtWar(&itr->second, true);

        if (new_rank > old_rank)
            _sendFactionIncreased = true;

        UpdateRankCounters(old_rank, new_rank);

        _player->ReputationChanged(factionEntry);
        _player->UpdateCriteria(CRITERIA_TYPE_KNOWN_FACTIONS,          factionEntry->ID);
        _player->UpdateCriteria(CRITERIA_TYPE_GAIN_REPUTATION,         factionEntry->ID);
        _player->UpdateCriteria(CRITERIA_TYPE_GAIN_EXALTED_REPUTATION, factionEntry->ID);
        _player->UpdateCriteria(CRITERIA_TYPE_GAIN_REVERED_REPUTATION, factionEntry->ID);
        _player->UpdateCriteria(CRITERIA_TYPE_GAIN_HONORED_REPUTATION, factionEntry->ID);

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
        if (!(factionEntry->ReputationRaceMask[1].HasRace(_player->getRace()) && factionEntry->ReputationBase[1] == Reputation_Bottom))
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
    // except if faction has FACTION_FLAG_SPECIAL
    if (faction->Flags & (FACTION_FLAG_INVISIBLE_FORCED|FACTION_FLAG_HIDDEN) && !(faction->Flags & FACTION_FLAG_SPECIAL))
        return;

    // already set
    if (faction->Flags & FACTION_FLAG_VISIBLE)
        return;

    faction->Flags |= FACTION_FLAG_VISIBLE;
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
    if (itr->second.Flags & (FACTION_FLAG_INVISIBLE_FORCED|FACTION_FLAG_HIDDEN))
        return;

    SetAtWar(&itr->second, on);
}

void ReputationMgr::SetAtWar(FactionState* faction, bool atWar) const
{
    // Do not allow to declare war to our own faction. But allow for rival factions (eg Aldor vs Scryer).
    if (atWar && (faction->Flags & FACTION_FLAG_PEACE_FORCED) && !(faction->Flags & FACTION_FLAG_RIVAL))
        return;

    // already set
    if (((faction->Flags & FACTION_FLAG_AT_WAR) != 0) == atWar)
        return;

    if (atWar)
        faction->Flags |= FACTION_FLAG_AT_WAR;
    else
        faction->Flags &= ~FACTION_FLAG_AT_WAR;

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
    if (inactive && ((faction->Flags & (FACTION_FLAG_INVISIBLE_FORCED|FACTION_FLAG_HIDDEN)) || !(faction->Flags & FACTION_FLAG_VISIBLE)))
        return;

    // already set
    if (((faction->Flags & FACTION_FLAG_INACTIVE) != 0) == inactive)
        return;

    if (inactive)
        faction->Flags |= FACTION_FLAG_INACTIVE;
    else
        faction->Flags &= ~FACTION_FLAG_INACTIVE;

    faction->needSend = true;
    faction->needSave = true;
}

void ReputationMgr::LoadFromDB(PreparedQueryResult result)
{
    // Set initial reputations (so everything is nifty before DB data load)
    Initialize();

    //QueryResult* result = CharacterDatabase.PQuery("SELECT faction, standing, flags FROM character_reputation WHERE guid = '%u'", GetGUIDLow());

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
                int32 BaseRep = GetBaseReputation(factionEntry);
                ReputationRank old_rank = ReputationToRank(BaseRep);
                ReputationRank new_rank = ReputationToRank(BaseRep + faction->Standing);
                UpdateRankCounters(old_rank, new_rank);

                uint32 dbFactionFlags = fields[2].GetUInt16();

                if (dbFactionFlags & FACTION_FLAG_VISIBLE)
                    SetVisible(faction);                    // have internal checks for forced invisibility

                if (dbFactionFlags & FACTION_FLAG_INACTIVE)
                    SetInactive(faction, true);              // have internal checks for visibility requirement

                if (dbFactionFlags & FACTION_FLAG_AT_WAR)  // DB at war
                    SetAtWar(faction, true);                 // have internal checks for FACTION_FLAG_PEACE_FORCED
                else                                        // DB not at war
                {
                    // allow remove if visible (and then not FACTION_FLAG_INVISIBLE_FORCED or FACTION_FLAG_HIDDEN)
                    if (faction->Flags & FACTION_FLAG_VISIBLE)
                        SetAtWar(faction, false);            // have internal checks for FACTION_FLAG_PEACE_FORCED
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

void ReputationMgr::SaveToDB(CharacterDatabaseTransaction& trans)
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
            stmt->setUInt16(3, uint16(itr->second.Flags));
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
