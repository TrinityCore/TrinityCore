/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __TRINITY_REPUTATION_MGR_H
#define __TRINITY_REPUTATION_MGR_H

#include "Common.h"
#include "SharedDefines.h"
#include "Language.h"
#include "DBCStructure.h"
#include "QueryResult.h"
#include <map>

static uint32 ReputationRankStrIndex[MAX_REPUTATION_RANK] =
{
    LANG_REP_HATED,    LANG_REP_HOSTILE, LANG_REP_UNFRIENDLY, LANG_REP_NEUTRAL,
    LANG_REP_FRIENDLY, LANG_REP_HONORED, LANG_REP_REVERED,    LANG_REP_EXALTED
};

enum FactionFlags
{
    FACTION_FLAG_NONE               = 0x00,                 // no faction flag
    FACTION_FLAG_VISIBLE            = 0x01,                 // makes visible in client (set or can be set at interaction with target of this faction)
    FACTION_FLAG_AT_WAR             = 0x02,                 // enable AtWar-button in client. player controlled (except opposition team always war state), Flag only set on initial creation
    FACTION_FLAG_HIDDEN             = 0x04,                 // hidden faction from reputation pane in client (player can gain reputation, but this update not sent to client)
    FACTION_FLAG_INVISIBLE_FORCED   = 0x08,                 // always overwrite FACTION_FLAG_VISIBLE and hide faction in rep.list, used for hide opposite team factions
    FACTION_FLAG_PEACE_FORCED       = 0x10,                 // always overwrite FACTION_FLAG_AT_WAR, used for prevent war with own team factions
    FACTION_FLAG_INACTIVE           = 0x20,                 // player controlled, state stored in characters.data (CMSG_SET_FACTION_INACTIVE)
    FACTION_FLAG_RIVAL              = 0x40,                 // flag for the two competing outland factions
    FACTION_FLAG_SPECIAL            = 0x80                  // horde and alliance home cities and their northrend allies have this flag
};

typedef uint32 RepListID;
struct FactionState
{
    uint32 ID;
    RepListID ReputationListID;
    uint8 Flags;
    int32  Standing;
    bool Changed;
};

typedef std::map<RepListID,FactionState> FactionStateList;
typedef std::map<uint32,ReputationRank> ForcedReactions;

class Player;

class ReputationMgr
{
    public:                                                 // constructors and global modifiers
        explicit ReputationMgr(Player* owner) : m_player(owner),
            m_visibleFactionCount(0), m_honoredFactionCount(0), m_reveredFactionCount(0), m_exaltedFactionCount(0) {}
        ~ReputationMgr() {}

        void SaveToDB(SQLTransaction& trans);
        void LoadFromDB(PreparedQueryResult result);
    public:                                                 // statics
        static const int32 PointsInRank[MAX_REPUTATION_RANK];
        static const int32 Reputation_Cap    =  42999;
        static const int32 Reputation_Bottom = -42000;

        static ReputationRank ReputationToRank(int32 standing);
    public:                                                 // accessors
        uint8 GetVisibleFactionCount() const { return m_visibleFactionCount; }
        uint8 GetHonoredFactionCount() const { return m_honoredFactionCount; }
        uint8 GetReveredFactionCount() const { return m_reveredFactionCount; }
        uint8 GetExaltedFactionCount() const { return m_exaltedFactionCount; }

        FactionStateList const& GetStateList() const { return m_factions; }

        FactionState const* GetState(FactionEntry const* factionEntry) const
        {
            return factionEntry->reputationListID >= 0 ? GetState(factionEntry->reputationListID) : NULL;
        }

        FactionState const* GetState(RepListID id) const
        {
            FactionStateList::const_iterator repItr = m_factions.find (id);
            return repItr != m_factions.end() ? &repItr->second : NULL;
        }

        int32 GetReputation(uint32 faction_id) const;
        int32 GetReputation(FactionEntry const* factionEntry) const;
        int32 GetBaseReputation(FactionEntry const* factionEntry) const;

        ReputationRank GetRank(FactionEntry const* factionEntry) const;
        ReputationRank GetBaseRank(FactionEntry const* factionEntry) const;
        uint32 GetReputationRankStrIndex(FactionEntry const* factionEntry)
        {
            return ReputationRankStrIndex[GetRank(factionEntry)];
        };

        ReputationRank const* GetForcedRankIfAny(FactionTemplateEntry const* factionTemplateEntry) const
        {
            ForcedReactions::const_iterator forceItr = m_forcedReactions.find(factionTemplateEntry->faction);
            return forceItr != m_forcedReactions.end() ? &forceItr->second : NULL;
        }

    public:                                                 // modifiers
        bool SetReputation(FactionEntry const* factionEntry, int32 standing)
        {
            return SetReputation(factionEntry, standing, false);
        }
        bool ModifyReputation(FactionEntry const* factionEntry, int32 standing)
        {
            return SetReputation(factionEntry, standing, true);
        }

        void SetVisible(FactionTemplateEntry const* factionTemplateEntry);
        void SetVisible(FactionEntry const* factionEntry);
        void SetAtWar(RepListID repListID, bool on);
        void SetInactive(RepListID repListID, bool on);

        void ApplyForceReaction(uint32 faction_id,ReputationRank rank,bool apply);

    public:                                                 // senders
        void SendInitialReputations();
        void SendForceReactions();
        void SendState(FactionState const* faction) const;
        void SendStates() const;

    private:                                                // internal helper functions
        void Initialize();
        uint32 GetDefaultStateFlags(FactionEntry const* factionEntry) const;
        bool SetReputation(FactionEntry const* factionEntry, int32 standing, bool incremental);
        bool SetOneFactionReputation(FactionEntry const* factionEntry, int32 standing, bool incremental);
        void SetVisible(FactionState* faction);
        void SetAtWar(FactionState* faction, bool atWar);
        void SetInactive(FactionState* faction, bool inactive);
        void SendVisible(FactionState const* faction) const;
        void UpdateRankCounters(ReputationRank old_rank, ReputationRank new_rank);
    private:
        Player* m_player;
        FactionStateList m_factions;
        ForcedReactions m_forcedReactions;
        uint8 m_visibleFactionCount :8;
        uint8 m_honoredFactionCount :8;
        uint8 m_reveredFactionCount :8;
        uint8 m_exaltedFactionCount :8;
};

#endif
