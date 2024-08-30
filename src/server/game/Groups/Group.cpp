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

#include "Group.h"
#include "Battleground.h"
#include "BattlegroundMgr.h"
#include "CharacterCache.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "Formulas.h"
#include "GameObject.h"
#include "GameTime.h"
#include "GroupMgr.h"
#include "Item.h"
#include "LFGMgr.h"
#include "Log.h"
#include "Loot.h"
#include "MapManager.h"
#include "MiscPackets.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "PartyPackets.h"
#include "Pet.h"
#include "Player.h"
#include "UpdateData.h"
#include "WorldSession.h"

Seconds Group::CountdownInfo::GetTimeLeft() const
{
    return Seconds(std::max<time_t>(_endTime - GameTime::GetGameTime(), 0));
}

void Group::CountdownInfo::StartCountdown(Seconds duration, Optional<time_t> startTime)
{
    _startTime = startTime ? *startTime : GameTime::GetGameTime();
    _endTime = _startTime + duration.count();
}

bool Group::CountdownInfo::IsRunning() const
{
    return _endTime > GameTime::GetGameTime();
}

Group::Group() : m_leaderGuid(), m_leaderFactionGroup(0), m_leaderName(""), m_groupFlags(GROUP_FLAG_NONE), m_groupCategory(GROUP_CATEGORY_HOME),
m_dungeonDifficulty(DIFFICULTY_NORMAL), m_raidDifficulty(DIFFICULTY_NORMAL_RAID), m_legacyRaidDifficulty(DIFFICULTY_10_N),
m_bgGroup(nullptr), m_bfGroup(nullptr), m_lootMethod(PERSONAL_LOOT), m_lootThreshold(ITEM_QUALITY_UNCOMMON), m_looterGuid(),
m_masterLooterGuid(), m_subGroupsCounts(nullptr), m_guid(), m_dbStoreId(0), m_isLeaderOffline(false),
m_readyCheckStarted(false), m_readyCheckTimer(Milliseconds::zero()), m_activeMarkers(0), m_scriptRef(this, NoopGroupDeleter())
{
    for (uint8 i = 0; i < TARGET_ICONS_COUNT; ++i)
        m_targetIcons[i].Clear();

    for (uint8 i = 0; i < RAID_MARKERS_COUNT; ++i)
        m_markers[i] = nullptr;

    m_countdowns = { nullptr, nullptr, nullptr };
}

Group::~Group()
{
    if (m_bgGroup)
    {
        TC_LOG_DEBUG("bg.battleground", "Group::~Group: battleground group being deleted.");
        if (m_bgGroup->GetBgRaid(ALLIANCE) == this)
            m_bgGroup->SetBgRaid(ALLIANCE, nullptr);
        else if (m_bgGroup->GetBgRaid(HORDE) == this)
            m_bgGroup->SetBgRaid(HORDE, nullptr);
        else
            TC_LOG_ERROR("misc", "Group::~Group: battleground group is not linked to the correct battleground.");
    }

    // Sub group counters clean up
    delete[] m_subGroupsCounts;
}

void Group::Update(uint32 diff)
{
    if (m_isLeaderOffline)
    {
        m_leaderOfflineTimer.Update(diff);
        if (m_leaderOfflineTimer.Passed())
        {
            SelectNewPartyOrRaidLeader();
            m_isLeaderOffline = false;
        }
    }

    UpdateReadyCheck(diff);
}

void Group::SelectNewPartyOrRaidLeader()
{
    Player* newLeader = nullptr;

    // Attempt to give leadership to main assistant first
    if (isRaidGroup())
    {
        for (Group::MemberSlot const& memberSlot : m_memberSlots)
        {
            if ((memberSlot.flags & MEMBER_FLAG_ASSISTANT) == MEMBER_FLAG_ASSISTANT)
                if (Player* player = ObjectAccessor::FindPlayer(memberSlot.guid))
                {
                    newLeader = player;
                    break;
                }
        }
    }

    // If there aren't assistants in raid, or if the group is not a raid, pick the first available member
    if (!newLeader)
    {
        for (Group::MemberSlot const& memberSlot : m_memberSlots)
            if (Player* player = ObjectAccessor::FindPlayer(memberSlot.guid))
            {
                newLeader = player;
                break;
            }
    }

    if (newLeader)
    {
        ChangeLeader(newLeader->GetGUID());
        SendUpdate();
    }
}

bool Group::Create(Player* leader)
{
    ObjectGuid leaderGuid = leader->GetGUID();

    m_guid = ObjectGuid::Create<HighGuid::Party>(sGroupMgr->GenerateGroupId());
    m_leaderGuid = leaderGuid;
    m_leaderFactionGroup = Player::GetFactionGroupForRace(leader->GetRace());
    m_leaderName = leader->GetName();
    leader->SetPlayerFlag(PLAYER_FLAGS_GROUP_LEADER);

    if (isBGGroup() || isBFGroup())
    {
        m_groupFlags = GROUP_MASK_BGRAID;
        m_groupCategory = GROUP_CATEGORY_INSTANCE;
    }

    if (m_groupFlags & GROUP_FLAG_RAID)
        _initRaidSubGroupsCounter();

    m_lootThreshold = ITEM_QUALITY_UNCOMMON;
    m_looterGuid = leaderGuid;
    m_masterLooterGuid.Clear();

    m_dungeonDifficulty = DIFFICULTY_NORMAL;
    m_raidDifficulty = DIFFICULTY_NORMAL_RAID;
    m_legacyRaidDifficulty = DIFFICULTY_10_N;

    if (!isBGGroup() && !isBFGroup())
    {
        m_dungeonDifficulty = leader->GetDungeonDifficultyID();
        m_raidDifficulty = leader->GetRaidDifficultyID();
        m_legacyRaidDifficulty = leader->GetLegacyRaidDifficultyID();

        m_dbStoreId = sGroupMgr->GenerateNewGroupDbStoreId();

        sGroupMgr->RegisterGroupDbStoreId(m_dbStoreId, this);

        // Store group in database
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GROUP);

        uint8 index = 0;

        stmt->setUInt32(index++, m_dbStoreId);
        stmt->setUInt64(index++, m_leaderGuid.GetCounter());
        stmt->setUInt8(index++, uint8(m_lootMethod));
        stmt->setUInt64(index++, m_looterGuid.GetCounter());
        stmt->setUInt8(index++, uint8(m_lootThreshold));
        stmt->setBinary(index++, m_targetIcons[0].GetRawValue());
        stmt->setBinary(index++, m_targetIcons[1].GetRawValue());
        stmt->setBinary(index++, m_targetIcons[2].GetRawValue());
        stmt->setBinary(index++, m_targetIcons[3].GetRawValue());
        stmt->setBinary(index++, m_targetIcons[4].GetRawValue());
        stmt->setBinary(index++, m_targetIcons[5].GetRawValue());
        stmt->setBinary(index++, m_targetIcons[6].GetRawValue());
        stmt->setBinary(index++, m_targetIcons[7].GetRawValue());
        stmt->setUInt16(index++, m_groupFlags);
        stmt->setUInt32(index++, uint8(m_dungeonDifficulty));
        stmt->setUInt32(index++, uint8(m_raidDifficulty));
        stmt->setUInt32(index++, uint8(m_legacyRaidDifficulty));
        stmt->setUInt64(index++, m_masterLooterGuid.GetCounter());
        stmt->setInt8(index++, int8(m_pingRestriction));

        CharacterDatabase.Execute(stmt);

        if (InstanceMap* leaderInstance = leader->GetMap()->ToInstanceMap())
            leaderInstance->TrySetOwningGroup(this);

        bool addMemberResult = AddMember(leader);
        ASSERT(addMemberResult); // If the leader can't be added to a new group because it appears full, something is clearly wrong.
    }
    else if (!AddMember(leader))
        return false;

    return true;
}

void Group::LoadGroupFromDB(Field* fields)
{
    m_dbStoreId = fields[17].GetUInt32();
    m_guid = ObjectGuid::Create<HighGuid::Party>(sGroupMgr->GenerateGroupId());
    m_leaderGuid = ObjectGuid::Create<HighGuid::Player>(fields[0].GetUInt64());

    // group leader not exist
    CharacterCacheEntry const* leader = sCharacterCache->GetCharacterCacheByGuid(m_leaderGuid);
    if (!leader)
        return;

    m_leaderFactionGroup = Player::GetFactionGroupForRace(leader->Race);
    m_leaderName = leader->Name;
    m_lootMethod = LootMethod(fields[1].GetUInt8());
    m_looterGuid = ObjectGuid::Create<HighGuid::Player>(fields[2].GetUInt64());
    m_lootThreshold = ItemQualities(fields[3].GetUInt8());

    for (uint8 i = 0; i < TARGET_ICONS_COUNT; ++i)
        m_targetIcons[i].SetRawValue(fields[4 + i].GetBinary());

    m_groupFlags  = GroupFlags(fields[12].GetUInt16());
    if (m_groupFlags & GROUP_FLAG_RAID)
        _initRaidSubGroupsCounter();

    m_dungeonDifficulty = Player::CheckLoadedDungeonDifficultyID(Difficulty(fields[13].GetUInt8()));
    m_raidDifficulty = Player::CheckLoadedRaidDifficultyID(Difficulty(fields[14].GetUInt8()));
    m_legacyRaidDifficulty = Player::CheckLoadedLegacyRaidDifficultyID(Difficulty(fields[15].GetUInt8()));

    m_masterLooterGuid = ObjectGuid::Create<HighGuid::Player>(fields[16].GetUInt64());

    m_pingRestriction = RestrictPingsTo(fields[18].GetInt8());

    if (m_groupFlags & GROUP_FLAG_LFG)
        sLFGMgr->_LoadFromDB(fields, GetGUID());
}

void Group::LoadMemberFromDB(ObjectGuid::LowType guidLow, uint8 memberFlags, uint8 subgroup, uint8 roles)
{
    MemberSlot member;
    member.guid = ObjectGuid::Create<HighGuid::Player>(guidLow);

    // skip non-existed member
    CharacterCacheEntry const* character = sCharacterCache->GetCharacterCacheByGuid(member.guid);
    if (!character)
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GROUP_MEMBER);
        stmt->setUInt64(0, guidLow);
        CharacterDatabase.Execute(stmt);
        return;
    }

    if (m_groupFlags & GROUP_FLAG_EVERYONE_ASSISTANT)
        memberFlags |= MEMBER_FLAG_ASSISTANT;

    member.name         = character->Name;
    member.race         = Races(character->Race);
    member._class       = character->Class;
    member.group        = subgroup;
    member.flags        = memberFlags;
    member.roles        = roles;
    member.readyChecked = false;

    m_memberSlots.push_back(member);

    SubGroupCounterIncrease(subgroup);

    sLFGMgr->SetupGroupMember(member.guid, GetGUID());
}

void Group::ConvertToLFG()
{
    m_groupFlags = GroupFlags(m_groupFlags | GROUP_FLAG_LFG | GROUP_FLAG_LFG_RESTRICTED);
    m_groupCategory = GROUP_CATEGORY_INSTANCE;
    m_lootMethod = PERSONAL_LOOT;
    if (!isBGGroup() && !isBFGroup())
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GROUP_TYPE);

        stmt->setUInt16(0, m_groupFlags);
        stmt->setUInt32(1, m_dbStoreId);

        CharacterDatabase.Execute(stmt);
    }

    SendUpdate();
}

void Group::ConvertToRaid()
{
    m_groupFlags = GroupFlags(m_groupFlags | GROUP_FLAG_RAID);

    _initRaidSubGroupsCounter();

    if (!isBGGroup() && !isBFGroup())
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GROUP_TYPE);

        stmt->setUInt16(0, m_groupFlags);
        stmt->setUInt32(1, m_dbStoreId);

        CharacterDatabase.Execute(stmt);
    }

    SendUpdate();

    // update quest related GO states (quest activity dependent from raid membership)
    for (member_citerator citr = m_memberSlots.begin(); citr != m_memberSlots.end(); ++citr)
        if (Player* player = ObjectAccessor::FindPlayer(citr->guid))
            player->UpdateVisibleObjectInteractions(false, true, false, true);
}

void Group::ConvertToGroup()
{
    if (m_memberSlots.size() > 5)
        return; // What message error should we send?

    m_groupFlags = GroupFlags(m_groupFlags & ~GROUP_FLAG_RAID);

    if (m_subGroupsCounts)
    {
        delete[] m_subGroupsCounts;
        m_subGroupsCounts = nullptr;
    }

    if (!isBGGroup() && !isBFGroup())
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GROUP_TYPE);

        stmt->setUInt16(0, m_groupFlags);
        stmt->setUInt32(1, m_dbStoreId);

        CharacterDatabase.Execute(stmt);
    }

    SendUpdate();

    // update quest related GO states (quest activity dependent from raid membership)
    for (member_citerator citr = m_memberSlots.begin(); citr != m_memberSlots.end(); ++citr)
        if (Player* player = ObjectAccessor::FindPlayer(citr->guid))
            player->UpdateVisibleObjectInteractions(false, true, false, true);
}

bool Group::AddInvite(Player* player)
{
    if (!player || player->GetGroupInvite())
        return false;
    Group* group = player->GetGroup();
    if (group && (group->isBGGroup() || group->isBFGroup()))
        group = player->GetOriginalGroup();
    if (group)
        return false;

    RemoveInvite(player);

    m_invitees.insert(player);

    player->SetGroupInvite(this);

    sScriptMgr->OnGroupInviteMember(this, player->GetGUID());

    return true;
}

bool Group::AddLeaderInvite(Player* player)
{
    if (!AddInvite(player))
        return false;

    m_leaderGuid = player->GetGUID();
    m_leaderFactionGroup = Player::GetFactionGroupForRace(player->GetRace());
    m_leaderName = player->GetName();
    return true;
}

void Group::RemoveInvite(Player* player)
{
    if (player)
    {
        m_invitees.erase(player);
        player->SetGroupInvite(nullptr);
    }
}

void Group::RemoveAllInvites()
{
    for (InvitesList::iterator itr = m_invitees.begin(); itr != m_invitees.end(); ++itr)
        if (*itr)
            (*itr)->SetGroupInvite(nullptr);

    m_invitees.clear();
}

Player* Group::GetInvited(ObjectGuid guid) const
{
    for (InvitesList::const_iterator itr = m_invitees.begin(); itr != m_invitees.end(); ++itr)
    {
        if ((*itr) && (*itr)->GetGUID() == guid)
            return (*itr);
    }
    return nullptr;
}

Player* Group::GetInvited(const std::string& name) const
{
    for (InvitesList::const_iterator itr = m_invitees.begin(); itr != m_invitees.end(); ++itr)
    {
        if ((*itr) && (*itr)->GetName() == name)
            return (*itr);
    }
    return nullptr;
}

bool Group::AddMember(Player* player)
{
    // Get first not-full group
    uint8 subGroup = 0;
    if (m_subGroupsCounts)
    {
        bool groupFound = false;
        for (; subGroup < MAX_RAID_SUBGROUPS; ++subGroup)
        {
            if (m_subGroupsCounts[subGroup] < MAX_GROUP_SIZE)
            {
                groupFound = true;
                break;
            }
        }
        // We are raid group and no one slot is free
        if (!groupFound)
            return false;
    }

    MemberSlot member;
    member.guid         = player->GetGUID();
    member.name         = player->GetName();
    member.race         = Races(player->GetRace());
    member._class       = player->GetClass();
    member.group        = subGroup;
    member.flags        = 0;
    member.roles        = 0;
    member.readyChecked = false;
    m_memberSlots.push_back(member);

    SubGroupCounterIncrease(subGroup);

    player->SetGroupInvite(nullptr);
    if (player->GetGroup())
    {
        if (isBGGroup() || isBFGroup()) // if player is in group and he is being added to BG raid group, then call SetBattlegroundRaid()
            player->SetBattlegroundOrBattlefieldRaid(this, subGroup);
        else //if player is in bg raid and we are adding him to normal group, then call SetOriginalGroup()
            player->SetOriginalGroup(this, subGroup);
    }
    else //if player is not in group, then call set group
        player->SetGroup(this, subGroup);

    player->SetPartyType(m_groupCategory, GROUP_TYPE_NORMAL);
    player->ResetGroupUpdateSequenceIfNeeded(this);

    // if the same group invites the player back, cancel the homebind timer
    player->m_InstanceValid = player->CheckInstanceValidity(false);

    if (!isRaidGroup())                                      // reset targetIcons for non-raid-groups
    {
        for (uint8 i = 0; i < TARGET_ICONS_COUNT; ++i)
            m_targetIcons[i].Clear();
    }

    // insert into the table if we're not a battleground group
    if (!isBGGroup() && !isBFGroup())
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GROUP_MEMBER);

        stmt->setUInt32(0, m_dbStoreId);
        stmt->setUInt64(1, member.guid.GetCounter());
        stmt->setUInt8(2, member.flags);
        stmt->setUInt8(3, member.group);
        stmt->setUInt8(4, member.roles);

        CharacterDatabase.Execute(stmt);
    }

    SendUpdate();
    sScriptMgr->OnGroupAddMember(this, player->GetGUID());

    if (!IsLeader(player->GetGUID()) && !isBGGroup() && !isBFGroup())
    {
        if (player->GetDungeonDifficultyID() != GetDungeonDifficultyID())
        {
            player->SetDungeonDifficultyID(GetDungeonDifficultyID());
            player->SendDungeonDifficulty();
        }
        if (player->GetRaidDifficultyID() != GetRaidDifficultyID())
        {
            player->SetRaidDifficultyID(GetRaidDifficultyID());
            player->SendRaidDifficulty(false);
        }
        if (player->GetLegacyRaidDifficultyID() != GetLegacyRaidDifficultyID())
        {
            player->SetLegacyRaidDifficultyID(GetLegacyRaidDifficultyID());
            player->SendRaidDifficulty(true);
        }
    }

    player->SetGroupUpdateFlag(GROUP_UPDATE_FULL);
    if (Pet* pet = player->GetPet())
        pet->SetGroupUpdateFlag(GROUP_UPDATE_PET_FULL);

    UpdatePlayerOutOfRange(player);

    // quest related GO state dependent from raid membership
    if (isRaidGroup())
        player->UpdateVisibleObjectInteractions(false, true, false, true);

    player->FailCriteria(CriteriaFailEvent::ModifyPartyStatus, 0);

    {
        // Broadcast new player group member fields to rest of the group
        UpdateData groupData(player->GetMapId());
        WorldPacket groupDataPacket;

        // Broadcast group members' fields to player
        for (GroupReference* itr = GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            if (itr->GetSource() == player)
                continue;

            if (Player* existingMember = itr->GetSource())
            {
                if (player->HaveAtClient(existingMember))
                    existingMember->BuildValuesUpdateBlockForPlayerWithFlag(&groupData, UF::UpdateFieldFlag::PartyMember, player);

                if (existingMember->HaveAtClient(player))
                {
                    UpdateData newData(player->GetMapId());
                    WorldPacket newDataPacket;
                    player->BuildValuesUpdateBlockForPlayerWithFlag(&newData, UF::UpdateFieldFlag::PartyMember, existingMember);
                    if (newData.HasData())
                    {
                        newData.BuildPacket(&newDataPacket);
                        existingMember->SendDirectMessage(&newDataPacket);
                    }
                }
            }
        }

        if (groupData.HasData())
        {
            groupData.BuildPacket(&groupDataPacket);
            player->SendDirectMessage(&groupDataPacket);
        }
    }

    return true;
}

bool Group::RemoveMember(ObjectGuid guid, RemoveMethod method /*= GROUP_REMOVEMETHOD_DEFAULT*/, ObjectGuid kicker /*= 0*/, const char* reason /*= nullptr*/)
{
    BroadcastGroupUpdate();

    sScriptMgr->OnGroupRemoveMember(this, guid, method, kicker, reason);

    Player* player = ObjectAccessor::FindConnectedPlayer(guid);
    if (player)
    {
        for (GroupReference* itr = GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            if (Player* groupMember = itr->GetSource())
            {
                if (groupMember->GetGUID() == guid)
                    continue;

                groupMember->RemoveAllGroupBuffsFromCaster(guid);
                player->RemoveAllGroupBuffsFromCaster(groupMember->GetGUID());
            }
        }
    }

    // LFG group vote kick handled in scripts
    if (isLFGGroup() && method == GROUP_REMOVEMETHOD_KICK)
        return !m_memberSlots.empty();

    if (player)
        player->FailCriteria(CriteriaFailEvent::ModifyPartyStatus, 0);

    // remove member and change leader (if need) only if strong more 2 members _before_ member remove (BG/BF allow 1 member group)
    if (GetMembersCount() > ((isBGGroup() || isLFGGroup() || isBFGroup()) ? 1u : 2u))
    {
        if (player)
        {
            // Battleground group handling
            if (isBGGroup() || isBFGroup())
                player->RemoveFromBattlegroundOrBattlefieldRaid();
            else
            // Regular group
            {
                if (player->GetOriginalGroup() == this)
                    player->SetOriginalGroup(nullptr);
                else
                    player->SetGroup(nullptr);

                // quest related GO state dependent from raid membership
                player->UpdateVisibleObjectInteractions(false, true, false, true);
            }

            player->SetPartyType(m_groupCategory, GROUP_TYPE_NONE);

            if (method == GROUP_REMOVEMETHOD_KICK || method == GROUP_REMOVEMETHOD_KICK_LFG)
                player->SendDirectMessage(WorldPackets::Party::GroupUninvite().Write());

            _homebindIfInstance(player);
        }

        // Remove player from group in DB
        if (!isBGGroup() && !isBFGroup())
        {
            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GROUP_MEMBER);
            stmt->setUInt64(0, guid.GetCounter());
            CharacterDatabase.Execute(stmt);
            DelinkMember(guid);
        }

        // Update subgroups
        member_witerator slot = _getMemberWSlot(guid);
        if (slot != m_memberSlots.end())
        {
            SubGroupCounterDecrease(slot->group);
            m_memberSlots.erase(slot);
        }

        // Pick new leader if necessary
        if (m_leaderGuid == guid)
        {
            for (member_witerator itr = m_memberSlots.begin(); itr != m_memberSlots.end(); ++itr)
            {
                if (ObjectAccessor::FindConnectedPlayer(itr->guid))
                {
                    ChangeLeader(itr->guid);
                    break;
                }
            }
        }

        SendUpdate();

        if (isLFGGroup() && GetMembersCount() == 1)
        {
            Player* leader = ObjectAccessor::FindConnectedPlayer(GetLeaderGUID());
            uint32 mapId = sLFGMgr->GetDungeonMapId(GetGUID());
            if (!mapId || !leader || (leader->IsAlive() && leader->GetMapId() != mapId))
            {
                Disband();
                return false;
            }
        }

        if (m_memberMgr.getSize() < ((isLFGGroup() || isBGGroup()) ? 1u : 2u))
            Disband();
        else if (player)
        {
            // send update to removed player too so party frames are destroyed clientside
            SendUpdateDestroyGroupToPlayer(player);
        }

        return true;
    }
    // If group size before player removal <= 2 then disband it
    else
    {
        Disband();
        return false;
    }
}

void Group::ChangeLeader(ObjectGuid newLeaderGuid)
{
    member_witerator slot = _getMemberWSlot(newLeaderGuid);

    if (slot == m_memberSlots.end())
        return;

    Player* newLeader = ObjectAccessor::FindConnectedPlayer(slot->guid);

    // Don't allow switching leader to offline players
    if (!newLeader)
        return;

    sScriptMgr->OnGroupChangeLeader(this, newLeaderGuid, m_leaderGuid);

    if (!isBGGroup() && !isBFGroup())
    {
        CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

        // Update the group leader
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GROUP_LEADER);

        stmt->setUInt64(0, newLeader->GetGUID().GetCounter());
        stmt->setUInt32(1, m_dbStoreId);

        trans->Append(stmt);

        CharacterDatabase.CommitTransaction(trans);
    }

    if (Player* oldLeader = ObjectAccessor::FindConnectedPlayer(m_leaderGuid))
        oldLeader->RemovePlayerFlag(PLAYER_FLAGS_GROUP_LEADER);

    newLeader->SetPlayerFlag(PLAYER_FLAGS_GROUP_LEADER);
    m_leaderGuid = newLeader->GetGUID();
    m_leaderFactionGroup = Player::GetFactionGroupForRace(newLeader->GetRace());
    m_leaderName = newLeader->GetName();
    ToggleGroupMemberFlag(slot, MEMBER_FLAG_ASSISTANT, false);

    WorldPackets::Party::GroupNewLeader groupNewLeader;
    groupNewLeader.Name = m_leaderName;
    groupNewLeader.PartyIndex = GetGroupCategory();
    BroadcastPacket(groupNewLeader.Write(), true);
}

void Group::Disband(bool hideDestroy /* = false */)
{
    sScriptMgr->OnGroupDisband(this);

    Player* player;
    for (member_citerator citr = m_memberSlots.begin(); citr != m_memberSlots.end(); ++citr)
    {
        player = ObjectAccessor::FindConnectedPlayer(citr->guid);
        if (!player)
            continue;

        //we cannot call _removeMember because it would invalidate member iterator
        //if we are removing player from battleground raid
        if (isBGGroup() || isBFGroup())
            player->RemoveFromBattlegroundOrBattlefieldRaid();
        else
        {
            //we can remove player who is in battleground from his original group
            if (player->GetOriginalGroup() == this)
                player->SetOriginalGroup(nullptr);
            else
                player->SetGroup(nullptr);
        }

        player->SetPartyType(m_groupCategory, GROUP_TYPE_NONE);

        // quest related GO state dependent from raid membership
        if (isRaidGroup())
            player->UpdateVisibleObjectInteractions(false, true, false, true);

        if (!hideDestroy)
            player->SendDirectMessage(WorldPackets::Party::GroupDestroyed().Write());

        SendUpdateDestroyGroupToPlayer(player);

        _homebindIfInstance(player);
    }

    m_memberSlots.clear();

    RemoveAllInvites();

    if (!isBGGroup() && !isBFGroup())
    {
        CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GROUP);
        stmt->setUInt32(0, m_dbStoreId);
        trans->Append(stmt);

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GROUP_MEMBER_ALL);
        stmt->setUInt32(0, m_dbStoreId);
        trans->Append(stmt);

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_LFG_DATA);
        stmt->setUInt32(0, m_dbStoreId);
        trans->Append(stmt);

        CharacterDatabase.CommitTransaction(trans);

        sGroupMgr->FreeGroupDbStoreId(this);
    }

    sGroupMgr->RemoveGroup(this);
    delete this;
}

void Group::SetTargetIcon(uint8 symbol, ObjectGuid target, ObjectGuid changedBy)
{
    if (symbol >= TARGET_ICONS_COUNT)
        return;

    // clean other icons
    if (!target.IsEmpty())
        for (uint8 i = 0; i < TARGET_ICONS_COUNT; ++i)
            if (m_targetIcons[i] == target)
                SetTargetIcon(i, ObjectGuid::Empty, changedBy);

    m_targetIcons[symbol] = target;

    WorldPackets::Party::SendRaidTargetUpdateSingle updateSingle;
    updateSingle.PartyIndex = GetGroupCategory();
    updateSingle.Target = target;
    updateSingle.ChangedBy = changedBy;
    updateSingle.Symbol = symbol;
    BroadcastPacket(updateSingle.Write(), true);
}

void Group::SendTargetIconList(WorldSession* session) const
{
    if (!session)
        return;

    WorldPackets::Party::SendRaidTargetUpdateAll updateAll;
    updateAll.PartyIndex = GetGroupCategory();
    for (uint8 i = 0; i < TARGET_ICONS_COUNT; i++)
        updateAll.TargetIcons.try_emplace(i, m_targetIcons[i]);

    session->SendPacket(updateAll.Write());
}

void Group::SendUpdate() const
{
    for (MemberSlot const& memberSlot : m_memberSlots)
        SendUpdateToPlayer(memberSlot.guid, &memberSlot);
}

void Group::SendUpdateToPlayer(ObjectGuid playerGUID, MemberSlot const* slot) const
{
    Player* player = ObjectAccessor::FindConnectedPlayer(playerGUID);

    if (!player || !player->GetSession() || player->GetGroup() != this)
        return;

    // if MemberSlot wasn't provided
    if (!slot)
    {
        member_citerator witr = _getMemberCSlot(playerGUID);

        if (witr == m_memberSlots.end()) // if there is no MemberSlot for such a player
            return;

        slot = &(*witr);
    }

    WorldPackets::Party::PartyUpdate partyUpdate;

    partyUpdate.PartyFlags = m_groupFlags;
    partyUpdate.PartyIndex = m_groupCategory;
    partyUpdate.PartyType = IsCreated() ? GROUP_TYPE_NORMAL : GROUP_TYPE_NONE;

    partyUpdate.PartyGUID = m_guid;
    partyUpdate.LeaderGUID = m_leaderGuid;
    partyUpdate.LeaderFactionGroup = m_leaderFactionGroup;

    partyUpdate.SequenceNum = player->NextGroupUpdateSequenceNumber(m_groupCategory);

    partyUpdate.PingRestriction = m_pingRestriction;

    partyUpdate.MyIndex = -1;
    uint8 index = 0;
    for (member_citerator citr = m_memberSlots.begin(); citr != m_memberSlots.end(); ++citr, ++index)
    {
        if (slot->guid == citr->guid)
            partyUpdate.MyIndex = index;

        Player* member = ObjectAccessor::FindConnectedPlayer(citr->guid);

        WorldPackets::Party::PartyPlayerInfo& playerInfos = partyUpdate.PlayerList.emplace_back();

        playerInfos.GUID = citr->guid;
        playerInfos.Name = citr->name;
        playerInfos.Class = citr->_class;

        playerInfos.FactionGroup = Player::GetFactionGroupForRace(citr->race);

        playerInfos.Connected = member && member->GetSession() && !member->GetSession()->PlayerLogout();

        playerInfos.Subgroup = citr->group;         // groupid
        playerInfos.Flags = citr->flags;            // See enum GroupMemberFlags
        playerInfos.RolesAssigned = citr->roles;    // Lfg Roles
    }

    if (GetMembersCount() > 1)
    {
        // LootSettings
        partyUpdate.LootSettings.emplace();
        partyUpdate.LootSettings->Method = m_lootMethod;
        partyUpdate.LootSettings->Threshold = m_lootThreshold;
        partyUpdate.LootSettings->LootMaster = m_lootMethod == MASTER_LOOT ? m_masterLooterGuid : ObjectGuid::Empty;

        // Difficulty Settings
        partyUpdate.DifficultySettings.emplace();
        partyUpdate.DifficultySettings->DungeonDifficultyID = m_dungeonDifficulty;
        partyUpdate.DifficultySettings->RaidDifficultyID = m_raidDifficulty;
        partyUpdate.DifficultySettings->LegacyRaidDifficultyID = m_legacyRaidDifficulty;
    }

    // LfgInfos
    if (isLFGGroup())
    {
        partyUpdate.LfgInfos.emplace();

        partyUpdate.LfgInfos->Slot = sLFGMgr->GetLFGDungeonEntry(sLFGMgr->GetDungeon(m_guid));
        partyUpdate.LfgInfos->BootCount = 0;
        partyUpdate.LfgInfos->Aborted = false;

        partyUpdate.LfgInfos->MyFlags = sLFGMgr->GetState(m_guid) == lfg::LFG_STATE_FINISHED_DUNGEON ? 2 : 0;
        partyUpdate.LfgInfos->MyRandomSlot = sLFGMgr->GetSelectedRandomDungeon(player->GetGUID());

        partyUpdate.LfgInfos->MyPartialClear = 0;
        partyUpdate.LfgInfos->MyGearDiff = 0.0f;
        partyUpdate.LfgInfos->MyFirstReward = false;
        if (lfg::LfgReward const* reward = sLFGMgr->GetRandomDungeonReward(partyUpdate.LfgInfos->MyRandomSlot, player->GetLevel()))
            if (Quest const* quest = sObjectMgr->GetQuestTemplate(reward->firstQuest))
                partyUpdate.LfgInfos->MyFirstReward = player->CanRewardQuest(quest, false);

        partyUpdate.LfgInfos->MyStrangerCount = 0;
        partyUpdate.LfgInfos->MyKickVoteCount = 0;
    }

    player->SendDirectMessage(partyUpdate.Write());
}

void Group::SendUpdateDestroyGroupToPlayer(Player* player) const
{
    WorldPackets::Party::PartyUpdate partyUpdate;
    partyUpdate.PartyFlags = GROUP_FLAG_DESTROYED;
    partyUpdate.PartyIndex = m_groupCategory;
    partyUpdate.PartyType = GROUP_TYPE_NONE;
    partyUpdate.PartyGUID = m_guid;
    partyUpdate.MyIndex = -1;
    partyUpdate.SequenceNum = player->NextGroupUpdateSequenceNumber(m_groupCategory);
    player->SendDirectMessage(partyUpdate.Write());
}

void Group::UpdatePlayerOutOfRange(Player const* player) const
{
    if (!player || !player->IsInWorld())
        return;

    WorldPackets::Party::PartyMemberFullState packet;
    packet.Initialize(player);
    packet.Write();

    for (GroupReference const* itr = GetFirstMember(); itr != nullptr; itr = itr->next())
    {
        Player const* member = itr->GetSource();
        if (member && member != player && (!member->IsInMap(player) || !member->IsWithinDist(player, member->GetSightRange(), false)))
            member->SendDirectMessage(packet.GetRawPacket());
    }
}

void Group::BroadcastAddonMessagePacket(WorldPacket const* packet, const std::string& prefix, bool ignorePlayersInBGRaid, int group /*= -1*/, ObjectGuid ignore /*= ObjectGuid::Empty*/) const
{
    for (GroupReference const* itr = GetFirstMember(); itr != nullptr; itr = itr->next())
    {
        Player* player = itr->GetSource();
        if (!player || (!ignore.IsEmpty() && player->GetGUID() == ignore) || (ignorePlayersInBGRaid && player->GetGroup() != this))
            continue;

        if (player->GetSession()->IsAddonRegistered(prefix) && (group == -1 || itr->getSubGroup() == group))
            player->SendDirectMessage(packet);
    }
}

void Group::BroadcastPacket(WorldPacket const* packet, bool ignorePlayersInBGRaid, int group, ObjectGuid ignoredPlayer) const
{
    for (GroupReference const* itr = GetFirstMember(); itr != nullptr; itr = itr->next())
    {
        Player const* player = itr->GetSource();
        if (!player || (!ignoredPlayer.IsEmpty() && player->GetGUID() == ignoredPlayer) || (ignorePlayersInBGRaid && player->GetGroup() != this))
            continue;

        if (group == -1 || itr->getSubGroup() == group)
            player->SendDirectMessage(packet);
    }
}

bool Group::_setMembersGroup(ObjectGuid guid, uint8 group)
{
    member_witerator slot = _getMemberWSlot(guid);
    if (slot == m_memberSlots.end())
        return false;

    slot->group = group;

    SubGroupCounterIncrease(group);

    if (!isBGGroup() && !isBFGroup())
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GROUP_MEMBER_SUBGROUP);

        stmt->setUInt8(0, group);
        stmt->setUInt64(1, guid.GetCounter());

        CharacterDatabase.Execute(stmt);
    }

    return true;
}

bool Group::SameSubGroup(Player const* member1, Player const* member2) const
{
    if (!member1 || !member2)
        return false;

    if (member1->GetGroup() != this || member2->GetGroup() != this)
        return false;
    else
        return member1->GetSubGroup() == member2->GetSubGroup();
}

// Allows setting sub groups both for online or offline members
void Group::ChangeMembersGroup(ObjectGuid guid, uint8 group)
{
    // Only raid groups have sub groups
    if (!isRaidGroup())
        return;

    // Check if player is really in the raid
    member_witerator slot = _getMemberWSlot(guid);
    if (slot == m_memberSlots.end())
        return;

    uint8 prevSubGroup = slot->group;
    // Abort if the player is already in the target sub group
    if (prevSubGroup == group)
        return;

    // Update the player slot with the new sub group setting
    slot->group = group;

    // Increase the counter of the new sub group..
    SubGroupCounterIncrease(group);

    // ..and decrease the counter of the previous one
    SubGroupCounterDecrease(prevSubGroup);

    // Preserve new sub group in database for non-raid groups
    if (!isBGGroup() && !isBFGroup())
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GROUP_MEMBER_SUBGROUP);

        stmt->setUInt8(0, group);
        stmt->setUInt64(1, guid.GetCounter());

        CharacterDatabase.Execute(stmt);
    }

    // In case the moved player is online, update the player object with the new sub group references
    if (Player* player = ObjectAccessor::FindConnectedPlayer(guid))
    {
        if (player->GetGroup() == this)
            player->GetGroupRef().setSubGroup(group);
        else
        {
            // If player is in BG raid, it is possible that he is also in normal raid - and that normal raid is stored in m_originalGroup reference
            player->GetOriginalGroupRef().setSubGroup(group);
        }
    }

    // Broadcast the changes to the group
    SendUpdate();
}

void Group::SwapMembersGroups(ObjectGuid firstGuid, ObjectGuid secondGuid)
{
    if (!isRaidGroup())
        return;

    member_witerator slots[2];
    slots[0] = _getMemberWSlot(firstGuid);
    slots[1] = _getMemberWSlot(secondGuid);
    if (slots[0] == m_memberSlots.end() || slots[1] == m_memberSlots.end())
        return;

    if (slots[0]->group == slots[1]->group)
        return;

    uint8 tmp = slots[0]->group;
    slots[0]->group = slots[1]->group;
    slots[1]->group = tmp;

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    for (uint8 i = 0; i < 2; i++)
    {
        // Preserve new sub group in database for non-raid groups
        if (!isBGGroup() && !isBFGroup())
        {
            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GROUP_MEMBER_SUBGROUP);

            stmt->setUInt8(0, slots[i]->group);
            stmt->setUInt64(1, slots[i]->guid.GetCounter());

            trans->Append(stmt);
        }

        if (Player* player = ObjectAccessor::FindConnectedPlayer(slots[i]->guid))
        {
            if (player->GetGroup() == this)
                player->GetGroupRef().setSubGroup(slots[i]->group);
            else
                player->GetOriginalGroupRef().setSubGroup(slots[i]->group);
        }
    }
    CharacterDatabase.CommitTransaction(trans);

    SendUpdate();
}

// Retrieve the next Round-Roubin player for the group
//
// No update done if loot method is FFA.
//
// If the RR player is not yet set for the group, the first group member becomes the round-robin player.
// If the RR player is set, the next player in group becomes the round-robin player.
//
// If ifneed is true,
//      the current RR player is checked to be near the looted object.
//      if yes, no update done.
//      if not, he loses his turn.
void Group::UpdateLooterGuid(WorldObject* pLootedObject, bool ifneed)
{
    // round robin style looting applies for all low
    // quality items in each loot method except free for all
    if (GetLootMethod() == FREE_FOR_ALL)
        return;

    ObjectGuid oldLooterGUID = GetLooterGuid();
    member_citerator guid_itr = _getMemberCSlot(oldLooterGUID);
    if (guid_itr != m_memberSlots.end())
    {
        if (ifneed)
        {
            // not update if only update if need and ok
            Player* looter = ObjectAccessor::FindPlayer(guid_itr->guid);
            if (looter && looter->IsAtGroupRewardDistance(pLootedObject))
                return;
        }
        ++guid_itr;
    }

    // search next after current
    Player* pNewLooter = nullptr;
    for (member_citerator itr = guid_itr; itr != m_memberSlots.end(); ++itr)
    {
        if (Player* player = ObjectAccessor::FindPlayer(itr->guid))
            if (player->IsAtGroupRewardDistance(pLootedObject))
            {
                pNewLooter = player;
                break;
            }
    }

    if (!pNewLooter)
    {
        // search from start
        for (member_citerator itr = m_memberSlots.begin(); itr != guid_itr; ++itr)
        {
            if (Player* player = ObjectAccessor::FindPlayer(itr->guid))
                if (player->IsAtGroupRewardDistance(pLootedObject))
                {
                    pNewLooter = player;
                    break;
                }
        }
    }

    if (pNewLooter)
    {
        if (oldLooterGUID != pNewLooter->GetGUID())
        {
            SetLooterGuid(pNewLooter->GetGUID());
            SendUpdate();
        }
    }
    else
    {
        SetLooterGuid(ObjectGuid::Empty);
        SendUpdate();
    }
}

GroupJoinBattlegroundResult Group::CanJoinBattlegroundQueue(BattlegroundTemplate const* bgOrTemplate, BattlegroundQueueTypeId bgQueueTypeId, uint32 MinPlayerCount, uint32 /*MaxPlayerCount*/, bool isRated, uint32 arenaSlot, ObjectGuid& errorGuid) const
{
    // check if this group is LFG group
    if (isLFGGroup())
        return ERR_LFG_CANT_USE_BATTLEGROUND;

    BattlemasterListEntry const* bgEntry = sBattlemasterListStore.LookupEntry(bgOrTemplate->Id);
    if (!bgEntry)
        return ERR_BATTLEGROUND_JOIN_FAILED;            // shouldn't happen

    // check for min / max count
    uint32 memberscount = GetMembersCount();

    if (int32(memberscount) > bgEntry->MaxGroupSize)         // no MinPlayerCount for battlegrounds
        return ERR_BATTLEGROUND_NONE;                        // ERR_GROUP_JOIN_BATTLEGROUND_TOO_MANY handled on client side

    // get a player as reference, to compare other players' stats to (arena team id, queue id based on level, etc.)
    Player* reference = ASSERT_NOTNULL(GetFirstMember())->GetSource();
    // no reference found, can't join this way
    if (!reference)
        return ERR_BATTLEGROUND_JOIN_FAILED;

    PVPDifficultyEntry const* bracketEntry = DB2Manager::GetBattlegroundBracketByLevel(bgOrTemplate->MapIDs.front(), reference->GetLevel());
    if (!bracketEntry)
        return ERR_BATTLEGROUND_JOIN_FAILED;

    uint32 arenaTeamId = reference->GetArenaTeamId(arenaSlot);
    Team team = reference->GetTeam();
    bool isMercenary = reference->HasAura(SPELL_MERCENARY_CONTRACT_HORDE) || reference->HasAura(SPELL_MERCENARY_CONTRACT_ALLIANCE);

    // check every member of the group to be able to join
    memberscount = 0;
    for (GroupReference const* itr = GetFirstMember(); itr != nullptr; itr = itr->next(), ++memberscount)
    {
        Player* member = itr->GetSource();
        // offline member? don't let join
        if (!member)
            return ERR_BATTLEGROUND_JOIN_FAILED;
        // rbac permissions
        if (!member->CanJoinToBattleground(bgOrTemplate))
            return ERR_BATTLEGROUND_JOIN_TIMED_OUT;
        // don't allow cross-faction join as group
        if (member->GetTeam() != team)
        {
            errorGuid = member->GetGUID();
            return ERR_BATTLEGROUND_JOIN_TIMED_OUT;
        }
        // not in the same battleground level braket, don't let join
        PVPDifficultyEntry const* memberBracketEntry = DB2Manager::GetBattlegroundBracketByLevel(bracketEntry->MapID, member->GetLevel());
        if (memberBracketEntry != bracketEntry)
            return ERR_BATTLEGROUND_JOIN_RANGE_INDEX;
        // don't let join rated matches if the arena team id doesn't match
        if (isRated && member->GetArenaTeamId(arenaSlot) != arenaTeamId)
            return ERR_BATTLEGROUND_JOIN_FAILED;
        // don't let join if someone from the group is already in that bg queue
        if (member->InBattlegroundQueueForBattlegroundQueueType(bgQueueTypeId))
            return ERR_BATTLEGROUND_JOIN_FAILED;            // not blizz-like
        // don't let join if someone from the group is in bg queue random
        bool isInRandomBgQueue = member->InBattlegroundQueueForBattlegroundQueueType(BattlegroundMgr::BGQueueTypeId(BATTLEGROUND_RB, BattlegroundQueueIdType::Battleground, false, 0))
            || member->InBattlegroundQueueForBattlegroundQueueType(BattlegroundMgr::BGQueueTypeId(BATTLEGROUND_RANDOM_EPIC, BattlegroundQueueIdType::Battleground, false, 0));
        if (bgOrTemplate->Id != BATTLEGROUND_AA && isInRandomBgQueue)
            return ERR_IN_RANDOM_BG;
        // don't let join to bg queue random if someone from the group is already in bg queue
        if (BattlegroundMgr::IsRandomBattleground(bgOrTemplate->Id) && member->InBattlegroundQueue(true) && !isInRandomBgQueue)
            return ERR_IN_NON_RANDOM_BG;
        // check for deserter debuff in case not arena queue
        if (bgOrTemplate->Id != BATTLEGROUND_AA && member->IsDeserter())
            return ERR_GROUP_JOIN_BATTLEGROUND_DESERTERS;
        // check if member can join any more battleground queues
        if (!member->HasFreeBattlegroundQueueId())
            return ERR_BATTLEGROUND_TOO_MANY_QUEUES;        // not blizz-like
        // check if someone in party is using dungeon system
        if (member->isUsingLfg())
            return ERR_LFG_CANT_USE_BATTLEGROUND;
        // check Freeze debuff
        if (member->HasAura(9454))
            return ERR_BATTLEGROUND_JOIN_FAILED;
        if (isMercenary != (member->HasAura(SPELL_MERCENARY_CONTRACT_HORDE) || member->HasAura(SPELL_MERCENARY_CONTRACT_ALLIANCE)))
            return ERR_BATTLEGROUND_JOIN_MERCENARY;
    }

    // only check for MinPlayerCount since MinPlayerCount == MaxPlayerCount for arenas...
    if (bgOrTemplate->IsArena() && memberscount != MinPlayerCount)
        return ERR_ARENA_TEAM_PARTY_SIZE;

    return ERR_BATTLEGROUND_NONE;
}

void Group::SetDungeonDifficultyID(Difficulty difficulty)
{
    m_dungeonDifficulty = difficulty;
    if (!isBGGroup() && !isBFGroup())
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GROUP_DIFFICULTY);

        stmt->setUInt8(0, uint8(m_dungeonDifficulty));
        stmt->setUInt32(1, m_dbStoreId);

        CharacterDatabase.Execute(stmt);
    }

    for (GroupReference* itr = GetFirstMember(); itr != nullptr; itr = itr->next())
    {
        Player* player = itr->GetSource();
        if (!player->GetSession())
            continue;

        player->SetDungeonDifficultyID(difficulty);
        player->SendDungeonDifficulty();
    }
}

void Group::SetRaidDifficultyID(Difficulty difficulty)
{
    m_raidDifficulty = difficulty;
    if (!isBGGroup() && !isBFGroup())
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GROUP_RAID_DIFFICULTY);

        stmt->setUInt8(0, uint8(m_raidDifficulty));
        stmt->setUInt32(1, m_dbStoreId);

        CharacterDatabase.Execute(stmt);
    }

    for (GroupReference* itr = GetFirstMember(); itr != nullptr; itr = itr->next())
    {
        Player* player = itr->GetSource();
        if (!player->GetSession())
            continue;

        player->SetRaidDifficultyID(difficulty);
        player->SendRaidDifficulty(false);
    }
}

void Group::SetLegacyRaidDifficultyID(Difficulty difficulty)
{
    m_legacyRaidDifficulty = difficulty;
    if (!isBGGroup() && !isBFGroup())
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GROUP_LEGACY_RAID_DIFFICULTY);

        stmt->setUInt8(0, uint8(m_legacyRaidDifficulty));
        stmt->setUInt32(1, m_dbStoreId);

        CharacterDatabase.Execute(stmt);
    }

    for (GroupReference* itr = GetFirstMember(); itr != nullptr; itr = itr->next())
    {
        Player* player = itr->GetSource();
        if (!player->GetSession())
            continue;

        player->SetLegacyRaidDifficultyID(difficulty);
        player->SendRaidDifficulty(true);
    }
}

Difficulty Group::GetDifficultyID(MapEntry const* mapEntry) const
{
    if (!mapEntry->IsRaid())
        return m_dungeonDifficulty;

    MapDifficultyEntry const* defaultDifficulty = sDB2Manager.GetDefaultMapDifficulty(mapEntry->ID);
    if (!defaultDifficulty)
        return m_legacyRaidDifficulty;

    DifficultyEntry const* difficulty = sDifficultyStore.LookupEntry(defaultDifficulty->DifficultyID);
    if (!difficulty || difficulty->Flags & DIFFICULTY_FLAG_LEGACY)
        return m_legacyRaidDifficulty;

    return m_raidDifficulty;
}

void Group::ResetInstances(InstanceResetMethod method, Player* notifyPlayer)
{
    for (GroupInstanceReference& ref : m_ownedInstancesMgr)
    {
        InstanceMap* map = ref.GetSource();
        switch (map->Reset(method))
        {
            case InstanceResetResult::Success:
                notifyPlayer->SendResetInstanceSuccess(map->GetId());
                m_recentInstances.erase(map->GetId());
                break;
            case InstanceResetResult::NotEmpty:
                if (method == InstanceResetMethod::Manual)
                    notifyPlayer->SendResetInstanceFailed(INSTANCE_RESET_FAILED, map->GetId());
                else if (method == InstanceResetMethod::OnChangeDifficulty)
                    m_recentInstances.erase(map->GetId()); // map might not have been reset on difficulty change but we still don't want to zone in there again
                break;
            case InstanceResetResult::CannotReset:
                m_recentInstances.erase(map->GetId()); // forget the instance, allows retrying different lockout with a new leader
                break;
            default:
                break;
        }
    }
}

void Group::LinkOwnedInstance(GroupInstanceReference* ref)
{
    m_ownedInstancesMgr.insertLast(ref);
}

void Group::_homebindIfInstance(Player* player)
{
    if (player && !player->IsGameMaster() && sMapStore.LookupEntry(player->GetMapId())->IsDungeon())
        player->m_InstanceValid = false;
}

void Group::BroadcastGroupUpdate(void)
{
    // FG: HACK: force flags update on group leave - for values update hack
    // -- not very efficient but safe
    for (member_citerator citr = m_memberSlots.begin(); citr != m_memberSlots.end(); ++citr)
    {
        if (Player * pp = ObjectAccessor::FindPlayer(citr->guid))
        {
            pp->ForceUpdateFieldChange(pp->m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::PvpFlags));
            pp->ForceUpdateFieldChange(pp->m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::FactionTemplate));
            TC_LOG_DEBUG("misc", "-- Forced group value update for '{}'", pp->GetName());
        }
    }
}

void Group::StartCountdown(CountdownTimerType timerType, Seconds duration, Optional<time_t> startTime)
{
    if (AsUnderlyingType(timerType) < 0 || AsUnderlyingType(timerType) >= std::ssize(m_countdowns))
        return;

    if (!m_countdowns[AsUnderlyingType(timerType)])
        m_countdowns[AsUnderlyingType(timerType)] = std::make_unique<CountdownInfo>();

    m_countdowns[AsUnderlyingType(timerType)]->StartCountdown(duration, startTime);
}

Group::CountdownInfo const* Group::GetCountdownInfo(CountdownTimerType timerType) const
{
    if (AsUnderlyingType(timerType) < 0 || AsUnderlyingType(timerType) >= std::ssize(m_countdowns))
        return nullptr;

    return m_countdowns[AsUnderlyingType(timerType)].get();
}

void Group::SetLootMethod(LootMethod method)
{
    m_lootMethod = method;
}

void Group::SetLooterGuid(ObjectGuid guid)
{
    m_looterGuid = guid;
}

void Group::SetMasterLooterGuid(ObjectGuid guid)
{
    m_masterLooterGuid = guid;
}

void Group::SetLootThreshold(ItemQualities threshold)
{
    m_lootThreshold = threshold;
}

void Group::SetLfgRoles(ObjectGuid guid, uint8 roles)
{
    member_witerator slot = _getMemberWSlot(guid);
    if (slot == m_memberSlots.end())
        return;

    slot->roles = roles;
    SendUpdate();
}

uint8 Group::GetLfgRoles(ObjectGuid guid) const
{
    member_citerator slot = _getMemberCSlot(guid);
    if (slot == m_memberSlots.end())
        return 0;

    return slot->roles;
}

void Group::UpdateReadyCheck(uint32 diff)
{
    if (!m_readyCheckStarted)
        return;

    m_readyCheckTimer -= Milliseconds(diff);
    if (m_readyCheckTimer <= Milliseconds::zero())
        EndReadyCheck();
}

void Group::StartReadyCheck(ObjectGuid starterGuid, Milliseconds duration)
{
    if (m_readyCheckStarted)
        return;

    member_witerator slot = _getMemberWSlot(starterGuid);
    if (slot == m_memberSlots.end())
        return ;

    m_readyCheckStarted = true;
    m_readyCheckTimer = duration;

    SetOfflineMembersReadyChecked();

    SetMemberReadyChecked(&(*slot));

    WorldPackets::Party::ReadyCheckStarted readyCheckStarted;
    readyCheckStarted.PartyGUID = m_guid;
    readyCheckStarted.PartyIndex = GetGroupCategory();
    readyCheckStarted.InitiatorGUID = starterGuid;
    readyCheckStarted.Duration = duration;
    BroadcastPacket(readyCheckStarted.Write(), false);
}

void Group::EndReadyCheck(void)
{
    if (!m_readyCheckStarted)
        return;

    m_readyCheckStarted = false;
    m_readyCheckTimer = Milliseconds::zero();

    ResetMemberReadyChecked();

    WorldPackets::Party::ReadyCheckCompleted readyCheckCompleted;
    readyCheckCompleted.PartyIndex = 0;
    readyCheckCompleted.PartyGUID = m_guid;
    BroadcastPacket(readyCheckCompleted.Write(), false);
}

bool Group::IsReadyCheckCompleted(void) const
{
    for (member_citerator citr = m_memberSlots.begin(); citr != m_memberSlots.end(); ++citr)
        if (!citr->readyChecked)
            return false;
    return true;
}

void Group::SetMemberReadyCheck(ObjectGuid guid, bool ready)
{
    if (!m_readyCheckStarted)
        return;

    member_witerator slot = _getMemberWSlot(guid);
    if (slot != m_memberSlots.end())
        SetMemberReadyCheck(&(*slot), ready);
}

void Group::SetMemberReadyCheck(MemberSlot* slot, bool ready)
{
    WorldPackets::Party::ReadyCheckResponse response;
    response.PartyGUID = m_guid;
    response.Player = slot->guid;
    response.IsReady = ready;
    BroadcastPacket(response.Write(), false);

    SetMemberReadyChecked(slot);
}

void Group::SetOfflineMembersReadyChecked(void)
{
    for (member_witerator itr = m_memberSlots.begin(); itr != m_memberSlots.end(); ++itr)
    {
        Player* player = ObjectAccessor::FindConnectedPlayer(itr->guid);
        if (!player || !player->GetSession())
            SetMemberReadyCheck(&(*itr), false);
    }
}

void Group::SetMemberReadyChecked(MemberSlot* slot)
{
    slot->readyChecked = true;
    if (IsReadyCheckCompleted())
        EndReadyCheck();
}

void Group::ResetMemberReadyChecked(void)
{
    for (member_witerator itr = m_memberSlots.begin(); itr != m_memberSlots.end(); ++itr)
        itr->readyChecked = false;
}

void Group::AddRaidMarker(uint8 markerId, uint32 mapId, float positionX, float positionY, float positionZ, ObjectGuid transportGuid)
{
    if (markerId >= RAID_MARKERS_COUNT || m_markers[markerId])
        return;

    m_activeMarkers |= (1 << markerId);
    m_markers[markerId] = std::make_unique<RaidMarker>(mapId, positionX, positionY, positionZ, transportGuid);
    SendRaidMarkersChanged();
}

void Group::DeleteRaidMarker(uint8 markerId)
{
    if (markerId > RAID_MARKERS_COUNT)
        return;

    for (uint8 i = 0; i < RAID_MARKERS_COUNT; i++)
        if (m_markers[i] && (markerId == i || markerId == RAID_MARKERS_COUNT))
        {
            m_markers[i] = nullptr;
            m_activeMarkers &= ~(1 << i);
        }

    SendRaidMarkersChanged();
}

void Group::SendRaidMarkersChanged(WorldSession* session) const
{
    WorldPackets::Party::RaidMarkersChanged packet;

    packet.PartyIndex = GetGroupCategory();
    packet.ActiveMarkers = m_activeMarkers;

    for (uint8 i = 0; i < RAID_MARKERS_COUNT; i++)
        if (m_markers[i])
            packet.RaidMarkers.push_back(m_markers[i].get());

    if (session)
        session->SendPacket(packet.Write());
    else
        BroadcastPacket(packet.Write(), false);
}

bool Group::IsFull() const
{
    return isRaidGroup() ? (m_memberSlots.size() >= MAX_RAID_SIZE) : (m_memberSlots.size() >= MAX_GROUP_SIZE);
}

bool Group::isLFGGroup() const
{
    return (m_groupFlags & GROUP_FLAG_LFG) != 0;
}

bool Group::isRaidGroup() const
{
    return (m_groupFlags & GROUP_FLAG_RAID) != 0;
}

bool Group::isBGGroup() const
{
    return m_bgGroup != nullptr;
}

bool Group::isBFGroup() const
{
    return m_bfGroup != nullptr;
}

bool Group::IsCreated() const
{
    return GetMembersCount() > 0;
}

ObjectGuid Group::GetLeaderGUID() const
{
    return m_leaderGuid;
}

ObjectGuid Group::GetGUID() const
{
    return m_guid;
}

char const* Group::GetLeaderName() const
{
    return m_leaderName.c_str();
}

LootMethod Group::GetLootMethod() const
{
    return m_lootMethod;
}

ObjectGuid Group::GetLooterGuid() const
{
    if (GetLootMethod() == FREE_FOR_ALL)
        return ObjectGuid::Empty;
    return m_looterGuid;
}

ObjectGuid Group::GetMasterLooterGuid() const
{
    return m_masterLooterGuid;
}

ItemQualities Group::GetLootThreshold() const
{
    return m_lootThreshold;
}

bool Group::IsMember(ObjectGuid guid) const
{
    return _getMemberCSlot(guid) != m_memberSlots.end();
}

bool Group::IsLeader(ObjectGuid guid) const
{
    return (GetLeaderGUID() == guid);
}

ObjectGuid Group::GetMemberGUID(std::string const& name) const
{
    auto itr = std::ranges::find(m_memberSlots, name, &MemberSlot::name);
    if (itr != m_memberSlots.end())
        return itr->guid;

    return ObjectGuid::Empty;
}

uint8 Group::GetMemberFlags(ObjectGuid guid) const
{
    member_citerator mslot = _getMemberCSlot(guid);
    if (mslot == m_memberSlots.end())
        return 0u;
    return mslot->flags;
}

bool Group::SameSubGroup(ObjectGuid guid1, ObjectGuid guid2) const
{
    member_citerator mslot2 = _getMemberCSlot(guid2);
    if (mslot2 == m_memberSlots.end())
       return false;
    return SameSubGroup(guid1, &*mslot2);
}

bool Group::SameSubGroup(ObjectGuid guid1, MemberSlot const* slot2) const
{
    member_citerator mslot1 = _getMemberCSlot(guid1);
    if (mslot1 == m_memberSlots.end() || !slot2)
        return false;
    return (mslot1->group == slot2->group);
}

bool Group::HasFreeSlotSubGroup(uint8 subgroup) const
{
    return (m_subGroupsCounts && m_subGroupsCounts[subgroup] < MAX_GROUP_SIZE);
}

uint8 Group::GetMemberGroup(ObjectGuid guid) const
{
    member_citerator mslot = _getMemberCSlot(guid);
    if (mslot == m_memberSlots.end())
       return (MAX_RAID_SUBGROUPS+1);
    return mslot->group;
}

void Group::SetBattlegroundGroup(Battleground* bg)
{
    m_bgGroup = bg;
}

void Group::SetBattlefieldGroup(Battlefield *bf)
{
    m_bfGroup = bf;
}

void Group::SetGroupMemberFlag(ObjectGuid guid, bool apply, GroupMemberFlags flag)
{
    // Assistants, main assistants and main tanks are only available in raid groups
    if (!isRaidGroup())
       return;

    // Check if player is really in the raid
    member_witerator slot = _getMemberWSlot(guid);
    if (slot == m_memberSlots.end())
        return;

    // Do flag specific actions, e.g ensure uniqueness
    switch (flag)
    {
        case MEMBER_FLAG_MAINASSIST:
            RemoveUniqueGroupMemberFlag(MEMBER_FLAG_MAINASSIST);         // Remove main assist flag from current if any.
            break;
        case MEMBER_FLAG_MAINTANK:
            RemoveUniqueGroupMemberFlag(MEMBER_FLAG_MAINTANK);           // Remove main tank flag from current if any.
            break;
        case MEMBER_FLAG_ASSISTANT:
            break;
        default:
            return;                                                      // This should never happen
    }

    // Switch the actual flag
    ToggleGroupMemberFlag(slot, flag, apply);

    // Preserve the new setting in the db
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GROUP_MEMBER_FLAG);

    stmt->setUInt8(0, slot->flags);
    stmt->setUInt64(1, guid.GetCounter());

    CharacterDatabase.Execute(stmt);

    // Broadcast the changes to the group
    SendUpdate();
}

void Group::LinkMember(GroupReference* pRef)
{
    m_memberMgr.insertFirst(pRef);
}

void Group::DelinkMember(ObjectGuid guid)
{
    GroupReference* ref = m_memberMgr.getFirst();
    while (ref)
    {
        GroupReference* nextRef = ref->next();
        if (ref->GetSource()->GetGUID() == guid)
        {
            ref->unlink();
            break;
        }
        ref = nextRef;
    }
}

void Group::_initRaidSubGroupsCounter()
{
    // Sub group counters initialization
    if (!m_subGroupsCounts)
        m_subGroupsCounts = new uint8[MAX_RAID_SUBGROUPS];

    memset((void*)m_subGroupsCounts, 0, (MAX_RAID_SUBGROUPS)*sizeof(uint8));

    for (member_citerator itr = m_memberSlots.begin(); itr != m_memberSlots.end(); ++itr)
        ++m_subGroupsCounts[itr->group];
}

Group::member_citerator Group::_getMemberCSlot(ObjectGuid Guid) const
{
    return std::ranges::find(m_memberSlots, Guid, &MemberSlot::guid);
}

Group::member_witerator Group::_getMemberWSlot(ObjectGuid Guid)
{
    return std::ranges::find(m_memberSlots, Guid, &MemberSlot::guid);
}

void Group::SubGroupCounterIncrease(uint8 subgroup)
{
    if (m_subGroupsCounts)
        ++m_subGroupsCounts[subgroup];
}

void Group::SubGroupCounterDecrease(uint8 subgroup)
{
    if (m_subGroupsCounts)
        --m_subGroupsCounts[subgroup];
}

void Group::RemoveUniqueGroupMemberFlag(GroupMemberFlags flag)
{
    for (member_witerator itr = m_memberSlots.begin(); itr != m_memberSlots.end(); ++itr)
        if (itr->flags & flag)
            itr->flags &= ~flag;
}

void Group::ToggleGroupMemberFlag(member_witerator slot, uint8 flag, bool apply)
{
    if (apply)
        slot->flags |= flag;
    else
        slot->flags &= ~flag;
}

void Group::StartLeaderOfflineTimer()
{
    m_isLeaderOffline = true;
    m_leaderOfflineTimer.Reset(2 * MINUTE * IN_MILLISECONDS);
}

void Group::StopLeaderOfflineTimer()
{
    m_isLeaderOffline = false;
}

void Group::SetEveryoneIsAssistant(bool apply)
{
    if (apply)
        m_groupFlags = GroupFlags(m_groupFlags | GROUP_FLAG_EVERYONE_ASSISTANT);
    else
        m_groupFlags = GroupFlags(m_groupFlags & ~GROUP_FLAG_EVERYONE_ASSISTANT);

    for (member_witerator itr = m_memberSlots.begin(); itr != m_memberSlots.end(); ++itr)
        ToggleGroupMemberFlag(itr, MEMBER_FLAG_ASSISTANT, apply);

    if (!isBGGroup() && !isBFGroup())
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GROUP_TYPE);

        stmt->setUInt16(0, m_groupFlags);
        stmt->setUInt32(1, m_dbStoreId);

        CharacterDatabase.Execute(stmt);
    }

    SendUpdate();
}

RestrictPingsTo Group::GetRestrictPings() const
{
    return m_pingRestriction;
}

void Group::SetRestrictPingsTo(RestrictPingsTo restrictTo)
{
    m_pingRestriction = restrictTo;

    if (!isBGGroup() && !isBFGroup())
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GROUP_PING_RESTRICTION);

        stmt->setInt8(0, int8(m_pingRestriction));
        stmt->setUInt32(1, m_dbStoreId);

        CharacterDatabase.Execute(stmt);
    }

    SendUpdate();
}
