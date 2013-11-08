/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "DatabaseEnv.h"
#include "ReputationMgr.h"
#include "DBCStores.h"
#include "Player.h"
#include "WorldPacket.h"
#include "World.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "Opcodes.h"

const int32 ReputationMgr::PointsInRank[MAX_REPUTATION_RANK] = {36000, 3000, 3000, 3000, 6000, 12000, 21000, 1000};

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

bool ReputationMgr::IsAtWar(uint32 faction_id) const
{
    FactionEntry const* factionEntry = sFactionStore.LookupEntry(faction_id);

    if (!factionEntry)
    {
        TC_LOG_ERROR("misc", "ReputationMgr::IsAtWar: Can't get AtWar flag of %s for unknown faction (faction id) #%u.", _player->GetName().c_str(), faction_id);
        return 0;
    }

    return IsAtWar(factionEntry);
}

bool ReputationMgr::IsAtWar(FactionEntry const* factionEntry) const
{
    if (!factionEntry)
        return false;

    if (FactionState const* factionState = GetState(factionEntry))
        return (factionState->Flags & FACTION_FLAG_AT_WAR);
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

    uint32 raceMask = _player->getRaceMask();
    uint32 classMask = _player->getClassMask();
    for (int i=0; i < 4; i++)
    {
        if ((factionEntry->BaseRepRaceMask[i] & raceMask  ||
            (factionEntry->BaseRepRaceMask[i] == 0  &&
             factionEntry->BaseRepClassMask[i] != 0)) &&
            (factionEntry->BaseRepClassMask[i] & classMask ||
             factionEntry->BaseRepClassMask[i] == 0))

            return factionEntry->BaseRepValue[i];
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

    uint32 raceMask = _player->getRaceMask();
    uint32 classMask = _player->getClassMask();
    for (int i=0; i < 4; i++)
    {
        if ((factionEntry->BaseRepRaceMask[i] & raceMask  ||
            (factionEntry->BaseRepRaceMask[i] == 0  &&
             factionEntry->BaseRepClassMask[i] != 0)) &&
            (factionEntry->BaseRepClassMask[i] & classMask ||
             factionEntry->BaseRepClassMask[i] == 0))

            return factionEntry->ReputationFlags[i];
    }
    return 0;
}

void ReputationMgr::SendForceReactions()
{
    WorldPacket data;
    data.Initialize(SMSG_SET_FORCED_REACTIONS, 4+_forcedReactions.size()*(4+4));
    data << uint32(_forcedReactions.size());
    for (ForcedReactions::const_iterator itr = _forcedReactions.begin(); itr != _forcedReactions.end(); ++itr)
    {
        data << uint32(itr->first);                         // faction_id (Faction.dbc)
        data << uint32(itr->second);                        // reputation rank
    }
    _player->SendDirectMessage(&data);
}

void ReputationMgr::SendState(FactionState const* faction)
{
    uint32 count = 1;

    WorldPacket data(SMSG_SET_FACTION_STANDING, 17);
    data << float(0);
    data << uint8(_sendFactionIncreased);
    _sendFactionIncreased = false; // Reset

    size_t p_count = data.wpos();
    data << uint32(count);

    data << uint32(faction->ReputationListID);
    data << uint32(faction->Standing);

    for (FactionStateList::iterator itr = _factions.begin(); itr != _factions.end(); ++itr)
    {
        if (itr->second.needSend)
        {
            itr->second.needSend = false;
            if (itr->second.ReputationListID != faction->ReputationListID)
            {
                data << uint32(itr->second.ReputationListID);
                data << uint32(itr->second.Standing);
                ++count;
            }
        }
    }

    data.put<uint32>(p_count, count);
    _player->SendDirectMessage(&data);
}

void ReputationMgr::SendInitialReputations()
{
    uint8 count = 128;
    WorldPacket data(SMSG_INITIALIZE_FACTIONS, 4 + count * 5);
    data << uint32(count);

    RepListID a = 0;

    for (FactionStateList::iterator itr = _factions.begin(); itr != _factions.end(); ++itr)
    {
        // fill in absent fields
        for (; a != itr->first; ++a)
        {
            data << uint8(0);
            data << uint32(0);
        }

        // fill in encountered data
        data << uint8(itr->second.Flags);
        data << uint32(itr->second.Standing);

        itr->second.needSend = false;

        ++a;
    }

    // fill in absent fields
    for (; a != count; ++a)
    {
        data << uint8(0);
        data << uint32(0);
    }

    _player->SendDirectMessage(&data);
}

void ReputationMgr::SendStates()
{
    for (FactionStateList::iterator itr = _factions.begin(); itr != _factions.end(); ++itr)
        SendState(&(itr->second));
}

void ReputationMgr::SendVisible(FactionState const* faction) const
{
    if (_player->GetSession()->PlayerLoading())
        return;

    // make faction visible in reputation list at client
    WorldPacket data(SMSG_SET_FACTION_VISIBLE, 4);
    data << faction->ReputationListID;
    _player->SendDirectMessage(&data);
}

void ReputationMgr::Initialize()
{
    _factions.clear();
    _visibleFactionCount = 0;
    _honoredFactionCount = 0;
    _reveredFactionCount = 0;
    _exaltedFactionCount = 0;
    _sendFactionIncreased = false;

    for (unsigned int i = 1; i < sFactionStore.GetNumRows(); i++)
    {
        FactionEntry const* factionEntry = sFactionStore.LookupEntry(i);

        if (factionEntry && (factionEntry->reputationListID >= 0))
        {
            FactionState newFaction;
            newFaction.ID = factionEntry->ID;
            newFaction.ReputationListID = factionEntry->reputationListID;
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

bool ReputationMgr::SetReputation(FactionEntry const* factionEntry, int32 standing, bool incremental)
{
    sScriptMgr->OnPlayerReputationChange(_player, factionEntry->ID, standing, incremental);
    bool res = false;
    // if spillover definition exists in DB, override DBC
    if (const RepSpilloverTemplate* repTemplate = sObjectMgr->GetRepSpilloverTemplate(factionEntry->ID))
    {
        for (uint32 i = 0; i < MAX_SPILLOVER_FACTIONS; ++i)
        {
            if (repTemplate->faction[i])
            {
                if (_player->GetReputationRank(repTemplate->faction[i]) <= ReputationRank(repTemplate->faction_rank[i]))
                {
                    // bonuses are already given, so just modify standing by rate
                    int32 spilloverRep = int32(standing * repTemplate->faction_rate[i]);
                    SetOneFactionReputation(sFactionStore.LookupEntry(repTemplate->faction[i]), spilloverRep, incremental);
                }
            }
        }
    }
    else
    {
        float spillOverRepOut = float(standing);
        // check for sub-factions that receive spillover
        SimpleFactionsList const* flist = GetFactionTeamList(factionEntry->ID);
        // if has no sub-factions, check for factions with same parent
        if (!flist && factionEntry->team && factionEntry->spilloverRateOut != 0.0f)
        {
            spillOverRepOut *= factionEntry->spilloverRateOut;
            if (FactionEntry const* parent = sFactionStore.LookupEntry(factionEntry->team))
            {
                FactionStateList::iterator parentState = _factions.find(parent->reputationListID);
                // some team factions have own reputation standing, in this case do not spill to other sub-factions
                if (parentState != _factions.end() && (parentState->second.Flags & FACTION_FLAG_SPECIAL))
                {
                    SetOneFactionReputation(parent, int32(spillOverRepOut), incremental);
                }
                else    // spill to "sister" factions
                {
                    flist = GetFactionTeamList(factionEntry->team);
                }
            }
        }
        if (flist)
        {
            // Spillover to affiliated factions
            for (SimpleFactionsList::const_iterator itr = flist->begin(); itr != flist->end(); ++itr)
            {
                if (FactionEntry const* factionEntryCalc = sFactionStore.LookupEntry(*itr))
                {
                    if (factionEntryCalc == factionEntry || GetRank(factionEntryCalc) > ReputationRank(factionEntryCalc->spilloverMaxRankIn))
                        continue;
                    int32 spilloverRep = int32(spillOverRepOut * factionEntryCalc->spilloverRateIn);
                    if (spilloverRep != 0 || !incremental)
                        res = SetOneFactionReputation(factionEntryCalc, spilloverRep, incremental);
                }
            }
        }
    }

    // spillover done, update faction itself
    FactionStateList::iterator faction = _factions.find(factionEntry->reputationListID);
    if (faction != _factions.end())
    {
        res = SetOneFactionReputation(factionEntry, standing, incremental);
        // only this faction gets reported to client, even if it has no own visible standing
        SendState(&faction->second);
    }
    return res;
}

bool ReputationMgr::SetOneFactionReputation(FactionEntry const* factionEntry, int32 standing, bool incremental)
{
    FactionStateList::iterator itr = _factions.find(factionEntry->reputationListID);
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
        _player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_KNOWN_FACTIONS,          factionEntry->ID);
        _player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_GAIN_REPUTATION,         factionEntry->ID);
        _player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_GAIN_EXALTED_REPUTATION, factionEntry->ID);
        _player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_GAIN_REVERED_REPUTATION, factionEntry->ID);
        _player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_GAIN_HONORED_REPUTATION, factionEntry->ID);

        return true;
    }
    return false;
}

void ReputationMgr::SetVisible(FactionTemplateEntry const*factionTemplateEntry)
{
    if (!factionTemplateEntry->faction)
        return;

    if (FactionEntry const* factionEntry = sFactionStore.LookupEntry(factionTemplateEntry->faction))
        // Never show factions of the opposing team
        if (!(factionEntry->BaseRepRaceMask[1] & _player->getRaceMask() && factionEntry->BaseRepValue[1] == Reputation_Bottom))
            SetVisible(factionEntry);
}

void ReputationMgr::SetVisible(FactionEntry const* factionEntry)
{
    if (factionEntry->reputationListID < 0)
        return;

    FactionStateList::iterator itr = _factions.find(factionEntry->reputationListID);
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
    // not allow declare war to own faction
    if (atWar && (faction->Flags & FACTION_FLAG_PEACE_FORCED))
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
            if (factionEntry && (factionEntry->reputationListID >= 0))
            {
                FactionState* faction = &_factions[factionEntry->reputationListID];

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

void ReputationMgr::SaveToDB(SQLTransaction& trans)
{
    for (FactionStateList::iterator itr = _factions.begin(); itr != _factions.end(); ++itr)
    {
        if (itr->second.needSave)
        {
            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_REPUTATION_BY_FACTION);
            stmt->setUInt32(0, _player->GetGUIDLow());
            stmt->setUInt16(1, uint16(itr->second.ID));
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_REPUTATION_BY_FACTION);
            stmt->setUInt32(0, _player->GetGUIDLow());
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
