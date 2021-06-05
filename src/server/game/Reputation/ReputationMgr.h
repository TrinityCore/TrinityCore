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

#ifndef __TRINITY_REPUTATION_MGR_H
#define __TRINITY_REPUTATION_MGR_H

#include "Common.h"
#include "EnumFlag.h"
#include "Language.h"
#include "DatabaseEnvFwd.h"
#include "SharedDefines.h"
#include <set>
#include <map>

struct FactionEntry;
struct FactionTemplateEntry;

static uint32 ReputationRankStrIndex[MAX_REPUTATION_RANK] =
{
    LANG_REP_HATED,    LANG_REP_HOSTILE, LANG_REP_UNFRIENDLY, LANG_REP_NEUTRAL,
    LANG_REP_FRIENDLY, LANG_REP_HONORED, LANG_REP_REVERED,    LANG_REP_EXALTED
};

enum class ReputationFlags : uint16
{
    None                        = 0x0000,
    Visible                     = 0x0001,                   // makes visible in client (set or can be set at interaction with target of this faction)
    AtWar                       = 0x0002,                   // enable AtWar-button in client. player controlled (except opposition team always war state), Flag only set on initial creation
    Hidden                      = 0x0004,                   // hidden faction from reputation pane in client (player can gain reputation, but this update not sent to client)
    Header                      = 0x0008,                   // Display as header in UI
    Peaceful                    = 0x0010,
    Inactive                    = 0x0020,                   // player controlled (CMSG_SET_FACTION_INACTIVE)
    ShowPropagated              = 0x0040,
    HeaderShowsBar              = 0x0080,                   // Header has its own reputation bar
    CapitalCityForRaceChange    = 0x0100,
    Guild                       = 0x0200,
    GarrisonInvasion            = 0x0400
};

DEFINE_ENUM_FLAG(ReputationFlags);

typedef uint32 RepListID;
struct FactionState
{
    uint32 ID;
    RepListID ReputationListID;
    int32 Standing;
    EnumFlag<ReputationFlags> Flags = ReputationFlags::None;
    bool needSend;
    bool needSave;
};

typedef std::map<RepListID, FactionState> FactionStateList;
typedef std::map<uint32, ReputationRank> ForcedReactions;

class Player;

class TC_GAME_API ReputationMgr
{
    public:                                                 // constructors and global modifiers
        explicit ReputationMgr(Player* owner) : _player(owner),
            _visibleFactionCount(0), _honoredFactionCount(0), _reveredFactionCount(0), _exaltedFactionCount(0), _sendFactionIncreased(false) { }
        ~ReputationMgr() { }

        void SaveToDB(CharacterDatabaseTransaction& trans);
        void LoadFromDB(PreparedQueryResult result);
    public:                                                 // statics
        static std::set<int32> const ReputationRankThresholds;
        static const int32 Reputation_Cap;
        static const int32 Reputation_Bottom;

        static ReputationRank ReputationToRank(FactionEntry const* factionEntry, int32 standing);
    public:                                                 // accessors
        uint8 GetVisibleFactionCount() const { return _visibleFactionCount; }
        uint8 GetHonoredFactionCount() const { return _honoredFactionCount; }
        uint8 GetReveredFactionCount() const { return _reveredFactionCount; }
        uint8 GetExaltedFactionCount() const { return _exaltedFactionCount; }

        FactionStateList const& GetStateList() const { return _factions; }

        FactionState const* GetState(FactionEntry const* factionEntry) const;

        FactionState const* GetState(RepListID id) const
        {
            FactionStateList::const_iterator repItr = _factions.find (id);
            return repItr != _factions.end() ? &repItr->second : nullptr;
        }

        bool IsAtWar(uint32 faction_id) const;
        bool IsAtWar(FactionEntry const* factionEntry) const;

        int32 GetReputation(uint32 faction_id) const;
        int32 GetReputation(FactionEntry const* factionEntry) const;
        int32 GetBaseReputation(FactionEntry const* factionEntry) const;
        int32 GetMinReputation(FactionEntry const* factionEntry) const;
        int32 GetMaxReputation(FactionEntry const* factionEntry) const;

        ReputationRank GetRank(FactionEntry const* factionEntry) const;
        ReputationRank GetBaseRank(FactionEntry const* factionEntry) const;
        std::string GetReputationRankName(FactionEntry const* factionEntry) const;;

        ReputationRank const* GetForcedRankIfAny(FactionTemplateEntry const* factionTemplateEntry) const;

        ReputationRank const* GetForcedRankIfAny(uint32 factionId) const
        {
            ForcedReactions::const_iterator forceItr = _forcedReactions.find(factionId);
            return forceItr != _forcedReactions.end() ? &forceItr->second : nullptr;
        }

        int32 GetParagonLevel(uint32 paragonFactionId) const;
        int32 GetParagonLevel(FactionEntry const* paragonFactionEntry) const;

    public:                                                 // modifiers
        bool SetReputation(FactionEntry const* factionEntry, int32 standing)
        {
            return SetReputation(factionEntry, standing, false, false, false);
        }
        bool ModifyReputation(FactionEntry const* factionEntry, int32 standing, bool spillOverOnly = false, bool noSpillover = false)
        {
            return SetReputation(factionEntry, standing, true, spillOverOnly, noSpillover);
        }

        void SetVisible(FactionTemplateEntry const* factionTemplateEntry);
        void SetVisible(FactionEntry const* factionEntry);
        void SetAtWar(RepListID repListID, bool on);
        void SetInactive(RepListID repListID, bool on);

        void ApplyForceReaction(uint32 faction_id, ReputationRank rank, bool apply);

        //! Public for chat command needs
        bool SetOneFactionReputation(FactionEntry const* factionEntry, int32 standing, bool incremental);

    public:                                                 // senders
        void SendInitialReputations();
        void SendForceReactions();
        void SendState(FactionState const* faction);

    private:                                                // internal helper functions
        void Initialize();
        ReputationFlags GetDefaultStateFlags(FactionEntry const* factionEntry) const;
        bool SetReputation(FactionEntry const* factionEntry, int32 standing, bool incremental, bool spillOverOnly, bool noSpillover);
        void SetVisible(FactionState* faction);
        void SetAtWar(FactionState* faction, bool atWar) const;
        void SetInactive(FactionState* faction, bool inactive) const;
        void SendVisible(FactionState const* faction, bool visible = true) const;
        void UpdateRankCounters(ReputationRank old_rank, ReputationRank new_rank);
        int32 GetFactionDataIndexForRaceAndClass(FactionEntry const* factionEntry) const;
        bool CanGainParagonReputationForFaction(FactionEntry const* factionEntry) const;

    private:
        Player* _player;
        FactionStateList _factions;
        ForcedReactions _forcedReactions;
        uint8 _visibleFactionCount :8;
        uint8 _honoredFactionCount :8;
        uint8 _reveredFactionCount :8;
        uint8 _exaltedFactionCount :8;
        bool _sendFactionIncreased; //! Play visual effect on next SMSG_SET_FACTION_STANDING sent
};

#endif
