/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
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

#include "Common.h"
#include "Opcodes.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "Player.h"
#include "World.h"
#include "ObjectMgr.h"
#include "Group.h"
#include "Formulas.h"
#include "ObjectAccessor.h"
#include "Battleground.h"
#include "BattlegroundMgr.h"
#include "MapManager.h"
#include "InstanceSaveMgr.h"
#include "MapInstanced.h"
#include "Util.h"
#include "LFGMgr.h"

Group::Group()
{
    m_leaderGuid        = 0;
    m_groupType         = GroupType(0);
    m_bgGroup           = NULL;
    m_lootMethod        = LootMethod(0);
    m_looterGuid        = 0;
    m_lootThreshold     = ITEM_QUALITY_UNCOMMON;
    m_subGroupsCounts   = NULL;
    m_guid              = 0;
    m_counter           = 0;
    m_maxEnchantingLevel= 0;
    m_LfgQueued         = false;
    m_LfgStatus         = LFG_STATUS_NOT_SAVED;
    m_LfgDungeonEntry   = 0;
    m_Lfgkicks          = 0;
    m_LfgkicksActive    = false;

    for (uint8 i = 0; i < TARGETICONCOUNT; ++i)
        m_targetIcons[i] = 0;
}

Group::~Group()
{
    if (m_bgGroup)
    {
        sLog.outDebug("Group::~Group: battleground group being deleted.");
        if (m_bgGroup->GetBgRaid(ALLIANCE) == this) m_bgGroup->SetBgRaid(ALLIANCE, NULL);
        else if (m_bgGroup->GetBgRaid(HORDE) == this) m_bgGroup->SetBgRaid(HORDE, NULL);
        else sLog.outError("Group::~Group: battleground group is not linked to the correct battleground.");
    }
    Rolls::iterator itr;
    while (!RollId.empty())
    {
        itr = RollId.begin();
        Roll *r = *itr;
        RollId.erase(itr);
        delete(r);
    }

    // it is undefined whether objectmgr (which stores the groups) or instancesavemgr
    // will be unloaded first so we must be prepared for both cases
    // this may unload some instance saves
    for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
        for (BoundInstancesMap::iterator itr2 = m_boundInstances[i].begin(); itr2 != m_boundInstances[i].end(); ++itr2)
            itr2->second.save->RemoveGroup(this);

    // Sub group counters clean up
    delete[] m_subGroupsCounts;
}

bool Group::Create(const uint64 &guid, const char * name)
{
    uint32 lowguid = sObjectMgr.GenerateLowGuid(HIGHGUID_GROUP);
    m_guid = MAKE_NEW_GUID(lowguid, 0, HIGHGUID_GROUP);
    m_leaderGuid = guid;
    m_leaderName = name;

    m_groupType  = isBGGroup() ? GROUPTYPE_BGRAID : GROUPTYPE_NORMAL;

    if (m_groupType & GROUPTYPE_RAID)
        _initRaidSubGroupsCounter();

    m_lootMethod = GROUP_LOOT;
    m_lootThreshold = ITEM_QUALITY_UNCOMMON;
    m_looterGuid = guid;

    m_dungeonDifficulty = DUNGEON_DIFFICULTY_NORMAL;
    m_raidDifficulty = RAID_DIFFICULTY_10MAN_NORMAL;
    if (!isBGGroup())
    {
        Player *leader = sObjectMgr.GetPlayer(guid);
        if (leader)
        {
            m_dungeonDifficulty = leader->GetDungeonDifficulty();
            m_raidDifficulty = leader->GetRaidDifficulty();
        }

        Player::ConvertInstancesToGroup(leader, this, guid);

        if (!AddMember(guid, name))
            return false;

        // store group in database
        SQLTransaction trans = CharacterDatabase.BeginTransaction();
        trans->PAppend("DELETE FROM groups WHERE guid ='%u'", lowguid);
        trans->PAppend("DELETE FROM group_member WHERE guid ='%u'", lowguid);
        trans->PAppend("INSERT INTO groups (guid,leaderGuid,lootMethod,looterGuid,lootThreshold,icon1,icon2,icon3,icon4,icon5,icon6,icon7,icon8,groupType,difficulty,raiddifficulty) "
            "VALUES ('%u','%u','%u','%u','%u','" UI64FMTD "','" UI64FMTD "','" UI64FMTD "','" UI64FMTD "','" UI64FMTD "','" UI64FMTD "','" UI64FMTD "','" UI64FMTD "','%u','%u','%u')",
            lowguid, GUID_LOPART(m_leaderGuid), uint32(m_lootMethod),
            GUID_LOPART(m_looterGuid), uint32(m_lootThreshold), m_targetIcons[0], m_targetIcons[1], m_targetIcons[2], m_targetIcons[3], m_targetIcons[4], m_targetIcons[5], m_targetIcons[6], m_targetIcons[7], uint8(m_groupType), uint32(m_dungeonDifficulty), m_raidDifficulty);
        
        CharacterDatabase.CommitTransaction(trans);
    }
    else if (!AddMember(guid, name))
        return false;

    return true;
}

bool Group::LoadGroupFromDB(const uint32 &groupGuid, QueryResult_AutoPtr result, bool loadMembers)
{
    if (isBGGroup())
        return false;

    Field *fields = result->Fetch();
    m_guid = MAKE_NEW_GUID(groupGuid, 0, HIGHGUID_GROUP);
    m_leaderGuid = MAKE_NEW_GUID(fields[0].GetUInt32(), 0, HIGHGUID_PLAYER);

    // group leader not exist
    if (!sObjectMgr.GetPlayerNameByGUID(fields[0].GetUInt32(), m_leaderName))
        return false;

    m_lootMethod = LootMethod(fields[1].GetUInt8());
    m_looterGuid = MAKE_NEW_GUID(fields[2].GetUInt32(), 0, HIGHGUID_PLAYER);
    m_lootThreshold = ItemQualities(fields[3].GetUInt16());

    for (uint8 i = 0; i < TARGETICONCOUNT; ++i)
        m_targetIcons[i] = fields[4+i].GetUInt64();

    m_groupType  = GroupType(fields[12].GetUInt8());
    if (m_groupType & GROUPTYPE_RAID)
        _initRaidSubGroupsCounter();

    uint32 diff = fields[13].GetUInt8();
    if (diff >= MAX_DUNGEON_DIFFICULTY)
        m_dungeonDifficulty = DUNGEON_DIFFICULTY_NORMAL;
    else
        m_dungeonDifficulty = Difficulty(diff);

    uint32 r_diff = fields[14].GetUInt8();
    if (r_diff >= MAX_RAID_DIFFICULTY)
       m_raidDifficulty = RAID_DIFFICULTY_10MAN_NORMAL;
    else
       m_raidDifficulty = Difficulty(r_diff);

    if (loadMembers)
    {
        //                                        0           1            2         3
        result = CharacterDatabase.PQuery("SELECT memberGuid, memberFlags, subgroup, roles FROM group_member WHERE guid=%u", groupGuid);
        if (!result)
            return false;

        do
        {
            fields = result->Fetch();
            LoadMemberFromDB(fields[0].GetUInt32(), fields[1].GetUInt8(), fields[2].GetUInt8(), fields[3].GetUInt8());
        } while (result->NextRow());

        if (GetMembersCount() < 2)                          // group too small
            return false;
    }

    return true;
}

bool Group::LoadMemberFromDB(uint32 guidLow, uint8 memberFlags, uint8 subgroup, uint8 roles)
{
    MemberSlot member;
    member.guid = MAKE_NEW_GUID(guidLow, 0, HIGHGUID_PLAYER);

    // skip non-existed member
    if (!sObjectMgr.GetPlayerNameByGUID(member.guid, member.name))
    {
        CharacterDatabase.PQuery("DELETE FROM group_member WHERE memberGuid=%u", guidLow);
        return false;
    }

    member.group = subgroup;
    member.flags = memberFlags;
    member.roles = roles;

    m_memberSlots.push_back(member);

    SubGroupCounterIncrease(subgroup);

    return true;
}

void Group::ConvertToLFG()
{
    m_groupType = GroupType(m_groupType | GROUPTYPE_LFG | GROUPTYPE_UNK1);
    m_lootMethod = NEED_BEFORE_GREED;
    if (!isBGGroup())
        CharacterDatabase.PExecute("UPDATE groups SET groupType='%u' WHERE guid='%u'", uint8(m_groupType), GUID_LOPART(m_guid));
    SendUpdate();
}

void Group::ConvertToRaid()
{
    m_groupType = GroupType(m_groupType | GROUPTYPE_RAID);

    _initRaidSubGroupsCounter();

    if (!isBGGroup())
        CharacterDatabase.PExecute("UPDATE groups SET groupType='%u' WHERE guid='%u'", uint8(m_groupType), GUID_LOPART(m_guid));
    SendUpdate();

    // update quest related GO states (quest activity dependent from raid membership)
    for (member_citerator citr = m_memberSlots.begin(); citr != m_memberSlots.end(); ++citr)
        if (Player* player = sObjectMgr.GetPlayer(citr->guid))
            player->UpdateForQuestWorldObjects();
}

bool Group::AddInvite(Player *player)
{
    if (!player || player->GetGroupInvite())
        return false;
    Group* group = player->GetGroup();
    if (group && group->isBGGroup())
        group = player->GetOriginalGroup();
    if (group)
        return false;

    RemoveInvite(player);

    m_invitees.insert(player);

    player->SetGroupInvite(this);

    return true;
}

bool Group::AddLeaderInvite(Player *player)
{
    if (!AddInvite(player))
        return false;

    m_leaderGuid = player->GetGUID();
    m_leaderName = player->GetName();
    return true;
}

uint32 Group::RemoveInvite(Player *player)
{
    m_invitees.erase(player);

    player->SetGroupInvite(NULL);
    return GetMembersCount();
}

void Group::RemoveAllInvites()
{
    for (InvitesList::iterator itr=m_invitees.begin(); itr != m_invitees.end(); ++itr)
        (*itr)->SetGroupInvite(NULL);

    m_invitees.clear();
}

Player* Group::GetInvited(const uint64& guid) const
{
    for (InvitesList::const_iterator itr = m_invitees.begin(); itr != m_invitees.end(); ++itr)
    {
        if ((*itr)->GetGUID() == guid)
            return (*itr);
    }
    return NULL;
}

Player* Group::GetInvited(const std::string& name) const
{
    for (InvitesList::const_iterator itr = m_invitees.begin(); itr != m_invitees.end(); ++itr)
    {
        if ((*itr)->GetName() == name)
            return (*itr);
    }
    return NULL;
}

bool Group::AddMember(const uint64 &guid, const char* name)
{
    if (isLfgQueued())
        sLFGMgr.Leave(NULL, this);

    if (!_addMember(guid, name))
        return false;

    SendUpdate();

    Player *player = sObjectMgr.GetPlayer(guid);
    if (player)
    {
        sLFGMgr.Leave(player);
        if (!IsLeader(player->GetGUID()) && !isBGGroup())
        {
            // reset the new member's instances, unless he is currently in one of them
            // including raid/heroic instances that they are not permanently bound to!
            player->ResetInstances(INSTANCE_RESET_GROUP_JOIN,false);
            player->ResetInstances(INSTANCE_RESET_GROUP_JOIN,true);

            if (player->getLevel() >= LEVELREQUIREMENT_HEROIC)
            {
                if (player->GetDungeonDifficulty() != GetDungeonDifficulty())
                {
                    player->SetDungeonDifficulty(GetDungeonDifficulty());
                    player->SendDungeonDifficulty(true);
                }
                if (player->GetRaidDifficulty() != GetRaidDifficulty())
                {
                    player->SetRaidDifficulty(GetRaidDifficulty());
                    player->SendRaidDifficulty(true);
                }
            }
        }
        player->SetGroupUpdateFlag(GROUP_UPDATE_FULL);
        UpdatePlayerOutOfRange(player);

        // quest related GO state dependent from raid membership
        if (isRaidGroup())
            player->UpdateForQuestWorldObjects();

        if (m_maxEnchantingLevel < player->GetSkillValue(SKILL_ENCHANTING))
            m_maxEnchantingLevel = player->GetSkillValue(SKILL_ENCHANTING);
    }

    return true;
}

uint32 Group::RemoveMember(const uint64 &guid, const RemoveMethod &method)
{
    BroadcastGroupUpdate();

    if (isLfgQueued())
        sLFGMgr.Leave(NULL, this);
    else if (isLFGGroup())
        sLFGMgr.OfferContinue(this);

    // remove member and change leader (if need) only if strong more 2 members _before_ member remove
    if (GetMembersCount() > (isBGGroup() ? 1u : 2u))           // in BG group case allow 1 members group
    {
        bool leaderChanged = _removeMember(guid);

        if (Player *player = sObjectMgr.GetPlayer(guid))
        {
            // quest related GO state dependent from raid membership
            if (isRaidGroup())
                player->UpdateForQuestWorldObjects();

            WorldPacket data;

            if (method == GROUP_REMOVEMETHOD_KICK)
            {
                data.Initialize(SMSG_GROUP_UNINVITE, 0);
                player->GetSession()->SendPacket(&data);
            }

            player->GetSession()->SendLfgUpdateParty(LFG_UPDATETYPE_LEADER);
            if (isLFGGroup() && player->GetMap()->IsDungeon())
                player->TeleportToBGEntryPoint();

            //we already removed player from group and in player->GetGroup() is his original group!
            if (Group* group = player->GetGroup())
            {
                group->SendUpdate();
            }
            else
            {
                data.Initialize(SMSG_GROUP_LIST, 1+1+1+1+8+4+4+8);
                data << uint8(0x10) << uint8(0) << uint8(0) << uint8(0);
                data << uint64(m_guid) << uint32(m_counter) << uint32(0) << uint64(0);
                player->GetSession()->SendPacket(&data);
            }

            _homebindIfInstance(player);
        }

        if (leaderChanged)
        {
            WorldPacket data(SMSG_GROUP_SET_LEADER, (m_memberSlots.front().name.size()+1));
            data << m_memberSlots.front().name;
            BroadcastPacket(&data, true);
        }

        SendUpdate();
        ResetMaxEnchantingLevel();
    }
    // if group before remove <= 2 disband it
    else
        Disband();

    return m_memberSlots.size();
}

void Group::ChangeLeader(const uint64 &guid)
{
    member_citerator slot = _getMemberCSlot(guid);

    if (slot == m_memberSlots.end())
        return;

    _setLeader(guid);

    WorldPacket data(SMSG_GROUP_SET_LEADER, slot->name.size()+1);
    data << slot->name;
    BroadcastPacket(&data, true);
    SendUpdate();
}

void Group::Disband(bool hideDestroy /* = false */)
{
    Player *player;

    for (member_citerator citr = m_memberSlots.begin(); citr != m_memberSlots.end(); ++citr)
    {
        player = sObjectMgr.GetPlayer(citr->guid);
        if (!player)
            continue;

        //we cannot call _removeMember because it would invalidate member iterator
        //if we are removing player from battleground raid
        if (isBGGroup())
            player->RemoveFromBattlegroundRaid();
        else
        {
            //we can remove player who is in battleground from his original group
            if (player->GetOriginalGroup() == this)
                player->SetOriginalGroup(NULL);
            else
                player->SetGroup(NULL);

            if (isLFGGroup() && player->GetMap()->IsDungeon())
                player->TeleportToBGEntryPoint();
            player->GetSession()->SendLfgUpdateParty(LFG_UPDATETYPE_GROUP_DISBAND);
            player->GetSession()->SendLfgUpdateParty(LFG_UPDATETYPE_LEADER);
        }

        // quest related GO state dependent from raid membership
        if (isRaidGroup())
            player->UpdateForQuestWorldObjects();

        if (!player->GetSession())
            continue;

        WorldPacket data;
        if (!hideDestroy)
        {
            data.Initialize(SMSG_GROUP_DESTROYED, 0);
            player->GetSession()->SendPacket(&data);
        }

        //we already removed player from group and in player->GetGroup() is his original group, send update
        if (Group* group = player->GetGroup())
        {
            group->SendUpdate();
        }
        else
        {
            data.Initialize(SMSG_GROUP_LIST, 1+1+1+1+8+4+4+8);
            data << uint8(0x10) << uint8(0) << uint8(0) << uint8(0);
            data << uint64(m_guid) << uint32(m_counter) << uint32(0) << uint64(0);
            player->GetSession()->SendPacket(&data);
        }

        _homebindIfInstance(player);
    }
    RollId.clear();
    m_memberSlots.clear();

    RemoveAllInvites();

    if (!isBGGroup())
    {
        uint32 lowguid = GUID_LOPART(m_guid);
        SQLTransaction trans = CharacterDatabase.BeginTransaction();
        trans->PAppend("DELETE FROM groups WHERE guid=%u", lowguid);
        trans->PAppend("DELETE FROM group_member WHERE guid=%u", lowguid);
        CharacterDatabase.CommitTransaction(trans);
        ResetInstances(INSTANCE_RESET_GROUP_DISBAND, false, NULL);
        ResetInstances(INSTANCE_RESET_GROUP_DISBAND, true, NULL);
    }

    m_guid = 0;
    m_leaderGuid = 0;
    m_leaderName = "";
}

/*********************************************************/
/***                   LOOT SYSTEM                     ***/
/*********************************************************/

void Group::SendLootStartRoll(uint32 CountDown, uint32 mapid, const Roll &r)
{
    WorldPacket data(SMSG_LOOT_START_ROLL, (8+4+4+4+4+4+4+1));
    data << uint64(r.itemGUID);                             // guid of rolled item
    data << uint32(mapid);                                  // 3.3.3 mapid
    data << uint32(r.totalPlayersRolling);                  // maybe the number of players rolling for it???
    data << uint32(r.itemid);                               // the itemEntryId for the item that shall be rolled for
    data << uint32(r.itemRandomSuffix);                     // randomSuffix
    data << uint32(r.itemRandomPropId);                     // item random property ID
    data << uint32(r.itemCount);                            // items in stack
    data << uint32(CountDown);                              // the countdown time to choose "need" or "greed"
    data << uint8(r.rollVoteMask);                          // roll type mask

    for (Roll::PlayerVote::const_iterator itr=r.playerVote.begin(); itr != r.playerVote.end(); ++itr)
    {
        Player *p = sObjectMgr.GetPlayer(itr->first);
        if (!p || !p->GetSession())
            continue;

        if (itr->second == NOT_EMITED_YET)
            p->GetSession()->SendPacket(&data);
    }
}

void Group::SendLootRoll(const uint64& SourceGuid, const uint64& TargetGuid, uint8 RollNumber, uint8 RollType, const Roll &r)
{
    WorldPacket data(SMSG_LOOT_ROLL, (8+4+8+4+4+4+1+1+1));
    data << uint64(SourceGuid);                             // guid of the item rolled
    data << uint32(0);                                      // unknown, maybe amount of players
    data << uint64(TargetGuid);
    data << uint32(r.itemid);                               // the itemEntryId for the item that shall be rolled for
    data << uint32(r.itemRandomSuffix);                     // randomSuffix
    data << uint32(r.itemRandomPropId);                     // Item random property ID
    data << uint8(RollNumber);                              // 0: "Need for: [item name]" > 127: "you passed on: [item name]"      Roll number
    data << uint8(RollType);                                // 0: "Need for: [item name]" 0: "You have selected need for [item name] 1: need roll 2: greed roll
    data << uint8(0);                                       // auto pass on NeedBeforeGreed loot because player cannot use the object

    for (Roll::PlayerVote::const_iterator itr=r.playerVote.begin(); itr != r.playerVote.end(); ++itr)
    {
        Player *p = sObjectMgr.GetPlayer(itr->first);
        if (!p || !p->GetSession())
            continue;

        if (itr->second != NOT_VALID)
            p->GetSession()->SendPacket(&data);
    }
}

void Group::SendLootRollWon(const uint64& SourceGuid, const uint64& TargetGuid, uint8 RollNumber, uint8 RollType, const Roll &r)
{
    WorldPacket data(SMSG_LOOT_ROLL_WON, (8+4+4+4+4+8+1+1));
    data << uint64(SourceGuid);                             // guid of the item rolled
    data << uint32(0);                                      // unknown, maybe amount of players
    data << uint32(r.itemid);                               // the itemEntryId for the item that shall be rolled for
    data << uint32(r.itemRandomSuffix);                     // randomSuffix
    data << uint32(r.itemRandomPropId);                     // Item random property
    data << uint64(TargetGuid);                             // guid of the player who won.
    data << uint8(RollNumber);                              // rollnumber realted to SMSG_LOOT_ROLL
    data << uint8(RollType);                                // Rolltype related to SMSG_LOOT_ROLL

    for (Roll::PlayerVote::const_iterator itr=r.playerVote.begin(); itr != r.playerVote.end(); ++itr)
    {
        Player *p = sObjectMgr.GetPlayer(itr->first);
        if (!p || !p->GetSession())
            continue;

        if (itr->second != NOT_VALID)
            p->GetSession()->SendPacket(&data);
    }
}

void Group::SendLootAllPassed(uint32 NumberOfPlayers, const Roll &r)
{
    WorldPacket data(SMSG_LOOT_ALL_PASSED, (8+4+4+4+4));
    data << uint64(r.itemGUID);                             // Guid of the item rolled
    data << uint32(NumberOfPlayers);                        // The number of players rolling for it???
    data << uint32(r.itemid);                               // The itemEntryId for the item that shall be rolled for
    data << uint32(r.itemRandomPropId);                     // Item random property ID
    data << uint32(r.itemRandomSuffix);                     // Item random suffix ID

    for (Roll::PlayerVote::const_iterator itr=r.playerVote.begin(); itr != r.playerVote.end(); ++itr)
    {
        Player *p = sObjectMgr.GetPlayer(itr->first);
        if (!p || !p->GetSession())
            continue;

        if (itr->second != NOT_VALID)
            p->GetSession()->SendPacket(&data);
    }
}

// notify group members which player is the allowed looter for the given creature
void Group::SendLooter(Creature *pCreature, Player *pLooter)
{
    ASSERT(pCreature);

    WorldPacket data(SMSG_LOOT_LIST, (8+8));
    data << uint64(pCreature->GetGUID());
    data << uint8(0); // unk1

    if (pLooter)
        data.append(pLooter->GetPackGUID());
    else
        data << uint8(0);

    BroadcastPacket(&data, false);
}

void Group::GroupLoot(Loot *loot, WorldObject* pLootedObject)
{
    std::vector<LootItem>::iterator i;
    ItemPrototype const *item;
    uint8 itemSlot = 0;

    for (i = loot->items.begin(); i != loot->items.end(); ++i, ++itemSlot)
    {
        if (i->freeforall)
            continue;

        item = sObjectMgr.GetItemPrototype(i->itemid);
        if (!item)
        {
            //sLog.outDebug("Group::GroupLoot: missing item prototype for item with id: %d", i->itemid);
            continue;
        }

        //roll for over-threshold item if it's one-player loot
        if (item->Quality >= uint32(m_lootThreshold))
        {
            uint64 newitemGUID = MAKE_NEW_GUID(sObjectMgr.GenerateLowGuid(HIGHGUID_ITEM),0,HIGHGUID_ITEM);
            Roll* r = new Roll(newitemGUID,*i);

            //a vector is filled with only near party members
            for (GroupReference *itr = GetFirstMember(); itr != NULL; itr = itr->next())
            {
                Player *member = itr->getSource();
                if (!member || !member->GetSession())
                    continue;
                if (i->AllowedForPlayer(member))
                {
                    if (member->IsWithinDistInMap(pLootedObject,sWorld.getFloatConfig(CONFIG_GROUP_XP_DISTANCE),false))
                    {
                        r->totalPlayersRolling++;

                        if (member->GetPassOnGroupLoot())
                        {
                            r->playerVote[member->GetGUID()] = PASS;
                            r->totalPass++;
                            // can't broadcast the pass now. need to wait until all rolling players are known.
                        }
                        else
                        {
                            r->playerVote[member->GetGUID()] = NOT_EMITED_YET;
                        }
                    }
                }
            }

            if (r->totalPlayersRolling > 0)
            {
                r->setLoot(loot);
                r->itemSlot = itemSlot;
                if (item->DisenchantID && m_maxEnchantingLevel >= item->RequiredDisenchantSkill)
                    r->rollVoteMask |= ROLL_FLAG_TYPE_DISENCHANT;

                loot->items[itemSlot].is_blocked = true;

                // If there is any "auto pass", broadcast the pass now.
                if (r->totalPass)
                {
                    for (Roll::PlayerVote::const_iterator itr=r->playerVote.begin(); itr != r->playerVote.end(); ++itr)
                    {
                        Player *p = sObjectMgr.GetPlayer(itr->first);
                        if (!p || !p->GetSession())
                            continue;

                        if (itr->second == PASS)
                            SendLootRoll(newitemGUID, p->GetGUID(), 128, ROLL_PASS, *r);
                    }
                }

                SendLootStartRoll(60000, pLootedObject->GetMapId(), *r);

                RollId.push_back(r);

                if (Creature* creature = dynamic_cast<Creature *>(pLootedObject))
                {
                    creature->m_groupLootTimer = 60000;
                    creature->lootingGroupLowGUID = GetLowGUID();
                }
                else if (GameObject* go = dynamic_cast<GameObject *>(pLootedObject))
                {
                    go->m_groupLootTimer = 60000;
                    go->lootingGroupLowGUID = GetLowGUID();
                }
            }
            else
            {
                delete r;
            }
        }
        else
            i->is_underthreshold=1;
    }
}

void Group::NeedBeforeGreed(Loot *loot, WorldObject* pLootedObject)
{
    ItemPrototype const *item;
    uint8 itemSlot = 0;
    for (std::vector<LootItem>::iterator i=loot->items.begin(); i != loot->items.end(); ++i, ++itemSlot)
    {
        if (i->freeforall)
            continue;

        item = sObjectMgr.GetItemPrototype(i->itemid);

        //roll for over-threshold item if it's one-player loot
        if (item->Quality >= uint32(m_lootThreshold))
        {
            uint64 newitemGUID = MAKE_NEW_GUID(sObjectMgr.GenerateLowGuid(HIGHGUID_ITEM),0,HIGHGUID_ITEM);
            Roll* r=new Roll(newitemGUID,*i);

            for (GroupReference *itr = GetFirstMember(); itr != NULL; itr = itr->next())
            {
                Player *playerToRoll = itr->getSource();
                if (!playerToRoll || !playerToRoll->GetSession())
                    continue;

                if (playerToRoll->CanUseItem(item) == EQUIP_ERR_OK && i->AllowedForPlayer(playerToRoll))
                {
                    if (playerToRoll->IsWithinDistInMap(pLootedObject,sWorld.getFloatConfig(CONFIG_GROUP_XP_DISTANCE),false))
                    {
                        r->totalPlayersRolling++;

                        if (playerToRoll->GetPassOnGroupLoot())
                        {
                            r->playerVote[playerToRoll->GetGUID()] = PASS;
                            r->totalPass++;
                            // can't broadcast the pass now. need to wait until all rolling players are known.
                        }
                        else
                        {
                            r->playerVote[playerToRoll->GetGUID()] = NOT_EMITED_YET;
                        }
                    }
                }
            }

            if (r->totalPlayersRolling > 0)
            {
                r->setLoot(loot);
                r->itemSlot = itemSlot;
                if (item->DisenchantID && m_maxEnchantingLevel >= item->RequiredDisenchantSkill)
                    r->rollVoteMask |= ROLL_FLAG_TYPE_DISENCHANT;

                if (item->Flags2 & ITEM_FLAGS_EXTRA_NEED_ROLL_DISABLED)
                    r->rollVoteMask &= ~ROLL_FLAG_TYPE_NEED;

                loot->items[itemSlot].is_blocked = true;

                // If there is any "auto pass", broadcast the pass now.
                if (r->totalPass)
                {
                    for (Roll::PlayerVote::const_iterator itr=r->playerVote.begin(); itr != r->playerVote.end(); ++itr)
                    {
                        Player *p = sObjectMgr.GetPlayer(itr->first);
                        if (!p || !p->GetSession())
                            continue;

                        if (itr->second == PASS)
                            SendLootRoll(newitemGUID, p->GetGUID(), 128, ROLL_PASS, *r);
                    }
                }

                SendLootStartRoll(60000, pLootedObject->GetMapId(), *r);

                RollId.push_back(r);

                if (Creature* creature = dynamic_cast<Creature *>(pLootedObject))
                {
                    creature->m_groupLootTimer = 60000;
                    creature->lootingGroupLowGUID = GetLowGUID();
                }
            }
            else
            {
                delete r;
            }
        }
        else
            i->is_underthreshold=1;
    }
}

void Group::MasterLoot(Loot* /*loot*/, WorldObject* pLootedObject)
{
    sLog.outDebug("Group::MasterLoot (SMSG_LOOT_MASTER_LIST, 330)");

    uint32 real_count = 0;

    WorldPacket data(SMSG_LOOT_MASTER_LIST, 330);
    data << (uint8)GetMembersCount();

    for (GroupReference *itr = GetFirstMember(); itr != NULL; itr = itr->next())
    {
        Player *looter = itr->getSource();
        if (!looter->IsInWorld())
            continue;

        if (looter->IsWithinDistInMap(pLootedObject,sWorld.getFloatConfig(CONFIG_GROUP_XP_DISTANCE),false))
        {
            data << uint64(looter->GetGUID());
            ++real_count;
        }
    }

    data.put<uint8>(0,real_count);

    for (GroupReference *itr = GetFirstMember(); itr != NULL; itr = itr->next())
    {
        Player *looter = itr->getSource();
        if (looter->IsWithinDistInMap(pLootedObject,sWorld.getFloatConfig(CONFIG_GROUP_XP_DISTANCE),false))
            looter->GetSession()->SendPacket(&data);
    }
}

void Group::CountRollVote(const uint64& playerGUID, const uint64& Guid, uint32 NumberOfPlayers, uint8 Choice)
{
    Rolls::iterator rollI = GetRoll(Guid);
    if (rollI == RollId.end())
        return;
    Roll* roll = *rollI;

    Roll::PlayerVote::iterator itr = roll->playerVote.find(playerGUID);
    // this condition means that player joins to the party after roll begins
    if (itr == roll->playerVote.end())
        return;

    if (roll->getLoot())
        if (roll->getLoot()->items.empty())
            return;

    switch (Choice)
    {
        case ROLL_PASS:                                     // Player choose pass
            SendLootRoll(0, playerGUID, 128, ROLL_PASS, *roll);
            ++roll->totalPass;
            itr->second = PASS;
            break;
        case ROLL_NEED:                                     // player choose Need
            SendLootRoll(0, playerGUID, 0, 0, *roll);
            ++roll->totalNeed;
            itr->second = NEED;
            break;
        case ROLL_GREED:                                    // player choose Greed
            SendLootRoll(0, playerGUID, 128, ROLL_GREED, *roll);
            ++roll->totalGreed;
            itr->second = GREED;
            break;
        case ROLL_DISENCHANT:                               // player choose Disenchant
            SendLootRoll(0, playerGUID, 128, ROLL_DISENCHANT, *roll);
            ++roll->totalGreed;
            itr->second = DISENCHANT;
            break;
    }

    if (roll->totalPass + roll->totalNeed + roll->totalGreed >= roll->totalPlayersRolling)
    {
        CountTheRoll(rollI, NumberOfPlayers);
    }
}

//called when roll timer expires
void Group::EndRoll(Loot *pLoot)
{
    for (Rolls::iterator itr = RollId.begin(); itr != RollId.end();)
    {
        if ((*itr)->getLoot() == pLoot) {
            CountTheRoll(itr, GetMembersCount());           //i don't have to edit player votes, who didn't vote ... he will pass
            itr = RollId.begin();
        }
        else
            itr++;
    }
}

void Group::CountTheRoll(Rolls::iterator rollI, uint32 NumberOfPlayers)
{
    Roll* roll = *rollI;
    if (!roll->isValid())                                   // is loot already deleted ?
    {
        RollId.erase(rollI);
        delete roll;
        return;
    }
    //end of the roll
    if (roll->totalNeed > 0)
    {
        if (!roll->playerVote.empty())
        {
            uint8 maxresul = 0;
            uint64 maxguid  = (*roll->playerVote.begin()).first;
            Player *player;

            for (Roll::PlayerVote::const_iterator itr=roll->playerVote.begin(); itr != roll->playerVote.end(); ++itr)
            {
                if (itr->second != NEED)
                    continue;

                uint8 randomN = urand(1, 100);
                SendLootRoll(0, itr->first, randomN, ROLL_NEED, *roll);
                if (maxresul < randomN)
                {
                    maxguid  = itr->first;
                    maxresul = randomN;
                }
            }
            SendLootRollWon(0, maxguid, maxresul, ROLL_NEED, *roll);
            player = sObjectMgr.GetPlayer(maxguid);

            if (player && player->GetSession())
            {
                player->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_ROLL_NEED_ON_LOOT, roll->itemid, maxresul);

                ItemPosCountVec dest;
                LootItem *item = &(roll->getLoot()->items[roll->itemSlot]);
                uint8 msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, roll->itemid, item->count);
                if (msg == EQUIP_ERR_OK)
                {
                    item->is_looted = true;
                    roll->getLoot()->NotifyItemRemoved(roll->itemSlot);
                    roll->getLoot()->unlootedCount--;
                    player->StoreNewItem(dest, roll->itemid, true, item->randomPropertyId);
                }
                else
                {
                    item->is_blocked = false;
                    player->SendEquipError(msg, NULL, NULL, roll->itemid);
                }
            }
        }
    }
    else if (roll->totalGreed > 0)
    {
        if (!roll->playerVote.empty())
        {
            uint8 maxresul = 0;
            uint64 maxguid = (*roll->playerVote.begin()).first;
            Player *player;
            RollVote rollvote = NOT_VALID;

            Roll::PlayerVote::iterator itr;
            for (itr = roll->playerVote.begin(); itr != roll->playerVote.end(); ++itr)
            {
                if (itr->second != GREED && itr->second != DISENCHANT)
                    continue;

                uint8 randomN = urand(1, 100);
                SendLootRoll(0, itr->first, randomN, itr->second, *roll);
                if (maxresul < randomN)
                {
                    maxguid  = itr->first;
                    maxresul = randomN;
                    rollvote = itr->second;
                }
            }
            SendLootRollWon(0, maxguid, maxresul, rollvote, *roll);
            player = sObjectMgr.GetPlayer(maxguid);

            if (player && player->GetSession())
            {
                player->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_ROLL_GREED_ON_LOOT, roll->itemid, maxresul);

                LootItem *item = &(roll->getLoot()->items[roll->itemSlot]);

                if (rollvote == GREED)
                {
                    ItemPosCountVec dest;
                    uint8 msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, roll->itemid, item->count);
                    if (msg == EQUIP_ERR_OK)
                    {
                        item->is_looted = true;
                        roll->getLoot()->NotifyItemRemoved(roll->itemSlot);
                        roll->getLoot()->unlootedCount--;
                        player->StoreNewItem(dest, roll->itemid, true, item->randomPropertyId);
                    }
                    else
                    {
                        item->is_blocked = false;
                        player->SendEquipError(msg, NULL, NULL, roll->itemid);
                    }
                }
                else if (rollvote == DISENCHANT)
                {
                    item->is_looted = true;
                    roll->getLoot()->NotifyItemRemoved(roll->itemSlot);
                    roll->getLoot()->unlootedCount--;
                    ItemPrototype const *pProto = ObjectMgr::GetItemPrototype(roll->itemid);
                    player->AutoStoreLoot(pProto->DisenchantID, LootTemplates_Disenchant, true);
                }
            }
        }
    }
    else
    {
        SendLootAllPassed(NumberOfPlayers, *roll);

        // remove is_blocked so that the item is lootable by all players
        LootItem *item = &(roll->getLoot()->items[roll->itemSlot]);
        if (item)
            item->is_blocked = false;
    }
    RollId.erase(rollI);
    delete roll;
}

void Group::SetTargetIcon(uint8 id, uint64 whoGuid, uint64 targetGuid)
{
    if (id >= TARGETICONCOUNT)
        return;

    // clean other icons
    if (targetGuid != 0)
        for (int i=0; i<TARGETICONCOUNT; ++i)
            if (m_targetIcons[i] == targetGuid)
                SetTargetIcon(i, 0, 0);

    m_targetIcons[id] = targetGuid;

    WorldPacket data(MSG_RAID_TARGET_UPDATE, (1+8+1+8));
    data << uint8(0);                                       // set targets
    data << uint64(whoGuid);
    data << uint8(id);
    data << uint64(targetGuid);
    BroadcastPacket(&data, true);
}

void Group::GetDataForXPAtKill(Unit const* victim, uint32& count,uint32& sum_level, Player* & member_with_max_level, Player* & not_gray_member_with_max_level)
{
    for (GroupReference *itr = GetFirstMember(); itr != NULL; itr = itr->next())
    {
        Player* member = itr->getSource();
        if (!member || !member->isAlive())                   // only for alive
            continue;

        if (!member->IsAtGroupRewardDistance(victim))        // at req. distance
            continue;

        ++count;
        sum_level += member->getLevel();
        if (!member_with_max_level || member_with_max_level->getLevel() < member->getLevel())
            member_with_max_level = member;

        uint32 gray_level = Trinity::XP::GetGrayLevel(member->getLevel());
        if (victim->getLevel() > gray_level && (!not_gray_member_with_max_level
           || not_gray_member_with_max_level->getLevel() < member->getLevel()))
            not_gray_member_with_max_level = member;
    }
}

void Group::SendTargetIconList(WorldSession *session)
{
    if (!session)
        return;

    WorldPacket data(MSG_RAID_TARGET_UPDATE, (1+TARGETICONCOUNT*9));
    data << uint8(1);                                       // list targets

    for (int i=0; i<TARGETICONCOUNT; ++i)
    {
        if (m_targetIcons[i] == 0)
            continue;

        data << uint8(i);
        data << uint64(m_targetIcons[i]);
    }

    session->SendPacket(&data);
}

void Group::SendUpdate()
{
    Player *player;
    for (member_citerator citr = m_memberSlots.begin(); citr != m_memberSlots.end(); ++citr)
    {
        player = sObjectMgr.GetPlayer(citr->guid);
        if (!player || !player->GetSession() || player->GetGroup() != this)
            continue;

        WorldPacket data(SMSG_GROUP_LIST, (1+1+1+1+1+4+8+4+4+(GetMembersCount()-1)*(13+8+1+1+1+1)+8+1+8+1+1+1+1));
        data << uint8(m_groupType);                         // group type (flags in 3.3)
        data << uint8(citr->group);
        data << uint8(citr->flags);
        if (isLFGGroup())
        {
            data << uint8(1);
            data << uint8(m_LfgStatus);
            data << uint32(m_LfgDungeonEntry);
        }
        else
            data << uint8(isBGGroup() ? 1 : 0);             // 2.0.x, isBattlegroundGroup?

        data << uint64(m_guid);
        data << uint32(m_counter++);                        // 3.3, value increases every time this packet gets sent
        data << uint32(GetMembersCount()-1);
        for (member_citerator citr2 = m_memberSlots.begin(); citr2 != m_memberSlots.end(); ++citr2)
        {
            if (citr->guid == citr2->guid)
                continue;
            Player* member = sObjectMgr.GetPlayer(citr2->guid);

            uint8 onlineState = (member) ? MEMBER_STATUS_ONLINE : MEMBER_STATUS_OFFLINE;
            onlineState = onlineState | ((isBGGroup()) ? MEMBER_STATUS_PVP : 0);

            data << citr2->name;
            data << uint64(citr2->guid);                    // guid
            data << uint8(onlineState);                     // online-state
            data << uint8(citr2->group);                    // groupid
            data << uint8(citr2->flags);                    // See enum GroupMemberFlags
            data << uint8(citr2->roles);                    // Lfg Roles
        }
        data << uint64(m_leaderGuid);                       // leader guid
        if (GetMembersCount()-1)
        {
            data << uint8(m_lootMethod);                    // loot method
            data << uint64(m_looterGuid);                   // looter guid
            data << uint8(m_lootThreshold);                 // loot threshold
            data << uint8(m_dungeonDifficulty);             // Dungeon Difficulty
            data << uint8(m_raidDifficulty);                // Raid Difficulty
            data << uint8(0);                               // 3.3
        }
        player->GetSession()->SendPacket(&data);
    }
}

void Group::UpdatePlayerOutOfRange(Player* pPlayer)
{
    if (!pPlayer || !pPlayer->IsInWorld())
        return;

    Player *player;
    WorldPacket data;
    pPlayer->GetSession()->BuildPartyMemberStatsChangedPacket(pPlayer, &data);

    for (GroupReference *itr = GetFirstMember(); itr != NULL; itr = itr->next())
    {
        player = itr->getSource();
        if (player && player != pPlayer && !pPlayer->isVisibleFor(player))
            player->GetSession()->SendPacket(&data);
    }
}

void Group::BroadcastPacket(WorldPacket *packet, bool ignorePlayersInBGRaid, int group, uint64 ignore)
{
    for (GroupReference *itr = GetFirstMember(); itr != NULL; itr = itr->next())
    {
        Player *pl = itr->getSource();
        if (!pl || (ignore != 0 && pl->GetGUID() == ignore) || (ignorePlayersInBGRaid && pl->GetGroup() != this))
            continue;

        if (pl->GetSession() && (group == -1 || itr->getSubGroup() == group))
            pl->GetSession()->SendPacket(packet);
    }
}

void Group::BroadcastReadyCheck(WorldPacket *packet)
{
    for (GroupReference *itr = GetFirstMember(); itr != NULL; itr = itr->next())
    {
        Player *pl = itr->getSource();
        if (pl && pl->GetSession())
            if (IsLeader(pl->GetGUID()) || IsAssistant(pl->GetGUID()))
                pl->GetSession()->SendPacket(packet);
    }
}

void Group::OfflineReadyCheck()
{
    for (member_citerator citr = m_memberSlots.begin(); citr != m_memberSlots.end(); ++citr)
    {
        Player *pl = sObjectMgr.GetPlayer(citr->guid);
        if (!pl || !pl->GetSession())
        {
            WorldPacket data(MSG_RAID_READY_CHECK_CONFIRM, 9);
            data << uint64(citr->guid);
            data << uint8(0);
            BroadcastReadyCheck(&data);
        }
    }
}

bool Group::_addMember(const uint64 &guid, const char* name)
{
    // get first not-full group
    uint8 groupid = 0;
    if (m_subGroupsCounts)
    {
        bool groupFound = false;
        for (; groupid < MAX_RAID_SUBGROUPS; ++groupid)
        {
            if (m_subGroupsCounts[groupid] < MAXGROUPSIZE)
            {
                groupFound = true;
                break;
            }
        }
        // We are raid group and no one slot is free
        if (!groupFound)
            return false;
    }

    return _addMember(guid, name, groupid);
}

bool Group::_addMember(const uint64 &guid, const char* name, uint8 group)
{
    if (IsFull())
        return false;

    if (!guid)
        return false;

    Player *player = sObjectMgr.GetPlayer(guid);

    MemberSlot member;
    member.guid      = guid;
    member.name      = name;
    member.group     = group;
    member.flags     = 0;
    member.roles     = 0;
    m_memberSlots.push_back(member);

    SubGroupCounterIncrease(group);

    if (player)
    {
        player->SetGroupInvite(NULL);
        //if player is in group and he is being added to BG raid group, then call SetBattlegroundRaid()
        if (player->GetGroup() && isBGGroup())
            player->SetBattlegroundRaid(this, group);
        //if player is in bg raid and we are adding him to normal group, then call SetOriginalGroup()
        else if (player->GetGroup())
            player->SetOriginalGroup(this, group);
        //if player is not in group, then call set group
        else
            player->SetGroup(this, group);
        // if the same group invites the player back, cancel the homebind timer
        InstanceGroupBind *bind = GetBoundInstance(player);
        if (bind && bind->save->GetInstanceId() == player->GetInstanceId())
            player->m_InstanceValid = true;
    }

    if (!isRaidGroup())                                      // reset targetIcons for non-raid-groups
    {
        for (uint8 i = 0; i < TARGETICONCOUNT; ++i)
            m_targetIcons[i] = 0;
    }

    if (!isBGGroup())
    {
        // insert into group table
        CharacterDatabase.PExecute("INSERT INTO group_member (guid, memberGuid, memberFlags, subgroup, roles) VALUES(%u, %u, %u, %u, %u)", GUID_LOPART(m_guid), GUID_LOPART(member.guid), member.flags, member.group, member.roles);
    }

    return true;
}

bool Group::_removeMember(const uint64 &guid)
{
    Player *player = sObjectMgr.GetPlayer(guid);
    if (player)
    {
        //if we are removing player from battleground raid
        if (isBGGroup())
            player->RemoveFromBattlegroundRaid();
        else
        {
            //we can remove player who is in battleground from his original group
            if (player->GetOriginalGroup() == this)
                player->SetOriginalGroup(NULL);
            else
                player->SetGroup(NULL);
            player->GetSession()->SendLfgUpdateParty(LFG_UPDATETYPE_LEADER);
        }
    }

    _removeRolls(guid);

    member_witerator slot = _getMemberWSlot(guid);
    if (slot != m_memberSlots.end())
    {
        SubGroupCounterDecrease(slot->group);

        m_memberSlots.erase(slot);
    }

    if (!isBGGroup())
        CharacterDatabase.PExecute("DELETE FROM group_member WHERE memberGuid=%u", GUID_LOPART(guid));

    if (m_leaderGuid == guid)                                // leader was removed
    {
        if (GetMembersCount() > 0)
            _setLeader(m_memberSlots.front().guid);
        return true;
    }

    return false;
}

void Group::_setLeader(const uint64 &guid)
{
    member_witerator slot = _getMemberWSlot(guid);
    if (slot == m_memberSlots.end())
        return;

    if (!isBGGroup())
    {
        // TODO: set a time limit to have this function run rarely cause it can be slow
        SQLTransaction trans = CharacterDatabase.BeginTransaction();

        // update the group's bound instances when changing leaders

        // remove all permanent binds from the group
        // in the DB also remove solo binds that will be replaced with permbinds
        // from the new leader
        trans->PAppend(
            "DELETE FROM group_instance WHERE guid=%u AND (permanent = 1 OR "
            "instance IN (SELECT instance FROM character_instance WHERE guid = '%u')"
            ")", GUID_LOPART(m_guid), GUID_LOPART(slot->guid)
        );

        Player *player = sObjectMgr.GetPlayer(slot->guid);
        if (player)
        {
            for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
            {
                for (BoundInstancesMap::iterator itr = m_boundInstances[i].begin(); itr != m_boundInstances[i].end();)
                {
                    if (itr->second.perm)
                    {
                        itr->second.save->RemoveGroup(this);
                        m_boundInstances[i].erase(itr++);
                    }
                    else
                        ++itr;
                }
            }
        }

        // copy the permanent binds from the new leader to the group
        // overwriting the solo binds with permanent ones if necessary
        // in the DB those have been deleted already
        Player::ConvertInstancesToGroup(player, this, slot->guid);

        // update the group leader
        trans->PAppend("UPDATE groups SET leaderGuid='%u' WHERE guid='%u'", GUID_LOPART(slot->guid), GUID_LOPART(m_guid));
        CharacterDatabase.CommitTransaction(trans);
    }

    m_leaderGuid = slot->guid;
    m_leaderName = slot->name;
    ToggleGroupMemberFlag(slot, MEMBER_FLAG_ASSISTANT, false);
}

void Group::_removeRolls(const uint64 &guid)
{
    for (Rolls::iterator it = RollId.begin(); it != RollId.end(); ++it)
    {
        Roll* roll = *it;
        Roll::PlayerVote::iterator itr2 = roll->playerVote.find(guid);
        if (itr2 == roll->playerVote.end())
            continue;

        if (itr2->second == GREED || itr2->second == DISENCHANT) --roll->totalGreed;
        if (itr2->second == NEED) --roll->totalNeed;
        if (itr2->second == PASS) --roll->totalPass;
        if (itr2->second != NOT_VALID) --roll->totalPlayersRolling;

        roll->playerVote.erase(itr2);

        CountRollVote(guid, roll->itemGUID, GetMembersCount()-1, MAX_ROLL_TYPE);
    }
}

bool Group::_setMembersGroup(const uint64 &guid, const uint8 &group)
{
    member_witerator slot = _getMemberWSlot(guid);
    if (slot == m_memberSlots.end())
        return false;

    slot->group = group;

    SubGroupCounterIncrease(group);

    if (!isBGGroup()) CharacterDatabase.PExecute("UPDATE group_member SET subgroup='%u' WHERE memberGuid='%u'", group, GUID_LOPART(guid));

    return true;
}

bool Group::_setAssistantFlag(const uint64 &guid, const bool &apply)
{
    member_witerator slot = _getMemberWSlot(guid);
    if (slot == m_memberSlots.end())
        return false;

    ToggleGroupMemberFlag(slot, MEMBER_FLAG_ASSISTANT, apply);

    if (!isBGGroup())
        CharacterDatabase.PExecute("UPDATE group_member SET memberFlags='%u' WHERE memberGuid='%u'", slot->flags, GUID_LOPART(guid));
    return true;
}

bool Group::_setMainTank(const uint64 &guid, const bool &apply)
{
    member_witerator slot = _getMemberWSlot(guid);  // First check member slots to see if the target exists
    if (slot == m_memberSlots.end())
        return false;

    RemoveUniqueGroupMemberFlag(MEMBER_FLAG_MAINTANK);          // Remove main tank flag from current if any.
    ToggleGroupMemberFlag(slot, MEMBER_FLAG_MAINTANK, apply);   // And apply main tank flag on new main tank.

    if (!isBGGroup())
        CharacterDatabase.PExecute("UPDATE group_member SET memberFlags='%u' WHERE memberGuid='%u'", slot->flags, GUID_LOPART(guid));
    return true;
}

bool Group::_setMainAssistant(const uint64 &guid, const bool &apply)
{
    member_witerator slot = _getMemberWSlot(guid);
    if (slot == m_memberSlots.end())
        return false;

    RemoveUniqueGroupMemberFlag(MEMBER_FLAG_MAINASSIST);         // Remove main assist flag from current if any.
    ToggleGroupMemberFlag(slot, MEMBER_FLAG_MAINASSIST, apply);  // Apply main assist flag on new main assist.

    if (!isBGGroup())
        CharacterDatabase.PExecute("UPDATE group_member SET memberFlags='%u' WHERE memberGuid='%u'", slot->flags, GUID_LOPART(guid));
    return true;
}

bool Group::SameSubGroup(Player const* member1, Player const* member2) const
{
    if (!member1 || !member2) return false;
    if (member1->GetGroup() != this || member2->GetGroup() != this) return false;
    else return member1->GetSubGroup() == member2->GetSubGroup();
}

// allows setting subgroup for offline members
void Group::ChangeMembersGroup(const uint64 &guid, const uint8 &group)
{
    if (!isRaidGroup())
        return;

    Player *player = sObjectMgr.GetPlayer(guid);

    if (!player)
    {
        uint8 prevSubGroup = GetMemberGroup(guid);
        if (prevSubGroup == group)
            return;

        if (_setMembersGroup(guid, group))
        {
            SubGroupCounterDecrease(prevSubGroup);
            SendUpdate();
        }
    }
    else
        // This methods handles itself groupcounter decrease
        ChangeMembersGroup(player, group);
}

// only for online members
void Group::ChangeMembersGroup(Player *player, const uint8 &group)
{
    if (!player || !isRaidGroup())
        return;

    uint8 prevSubGroup = player->GetSubGroup();
    if (prevSubGroup == group)
        return;

    if (_setMembersGroup(player->GetGUID(), group))
    {
        if (player->GetGroup() == this)
            player->GetGroupRef().setSubGroup(group);
        //if player is in BG raid, it is possible that he is also in normal raid - and that normal raid is stored in m_originalGroup reference
        else
        {
            prevSubGroup = player->GetOriginalSubGroup();
            player->GetOriginalGroupRef().setSubGroup(group);
        }
        SubGroupCounterDecrease(prevSubGroup);

        SendUpdate();
    }
}

// Retrieve the next Round-Roubin player for the group
//
// No update done if loot method is Master or FFA.
//
// If the RR player is not yet set for the group, the first group member becomes the round-robin player.
// If the RR player is set, the next player in group becomes the round-robin player.
//
// If ifneed is true,
//      the current RR player is checked to be near the looted object.
//      if yes, no update done.
//      if not, he looses his turn.
void Group::UpdateLooterGuid(WorldObject* pLootedObject, bool ifneed)
{
    switch (GetLootMethod())
    {
        case MASTER_LOOT:
        case FREE_FOR_ALL:
            return;
        default:
            // round robin style looting applies for all low
            // quality items in each loot method except free for all and master loot
            break;
    }

    uint64 oldLooterGUID = GetLooterGuid();
    member_citerator guid_itr = _getMemberCSlot(oldLooterGUID);
    if (guid_itr != m_memberSlots.end())
    {
        if (ifneed)
        {
            // not update if only update if need and ok
            Player* looter = ObjectAccessor::FindPlayer(guid_itr->guid);
            if (looter && looter->IsWithinDistInMap(pLootedObject,sWorld.getFloatConfig(CONFIG_GROUP_XP_DISTANCE),false))
                return;
        }
        ++guid_itr;
    }

    // search next after current
    Player *pNewLooter = NULL;
    for (member_citerator itr = guid_itr; itr != m_memberSlots.end(); ++itr)
    {
        if (Player* pl = ObjectAccessor::FindPlayer(itr->guid))
            if (pl->IsWithinDistInMap(pLootedObject,sWorld.getFloatConfig(CONFIG_GROUP_XP_DISTANCE),false))
            {
                pNewLooter = pl;
                break;
            }
    }

    if (!pNewLooter)
    {
        // search from start
        for (member_citerator itr = m_memberSlots.begin(); itr != guid_itr; ++itr)
        {
            if (Player* pl = ObjectAccessor::FindPlayer(itr->guid))
                if (pl->IsWithinDistInMap(pLootedObject,sWorld.getFloatConfig(CONFIG_GROUP_XP_DISTANCE),false))
                {
                    pNewLooter = pl;
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
        SetLooterGuid(0);
        SendUpdate();
    }
}

GroupJoinBattlegroundResult Group::CanJoinBattlegroundQueue(Battleground const* bgOrTemplate, BattlegroundQueueTypeId bgQueueTypeId, uint32 MinPlayerCount, uint32 /*MaxPlayerCount*/, bool isRated, uint32 arenaSlot)
{
    BattlemasterListEntry const* bgEntry = sBattlemasterListStore.LookupEntry(bgOrTemplate->GetTypeID());
    if (!bgEntry)
        return ERR_GROUP_JOIN_BATTLEGROUND_FAIL;            // shouldn't happen

    // check for min / max count
    uint32 memberscount = GetMembersCount();

    // only check for MinPlayerCount since MinPlayerCount == MaxPlayerCount for arenas...
    if (bgOrTemplate->isArena() && memberscount != MinPlayerCount)
        return ERR_ARENA_TEAM_PARTY_SIZE;

    if (memberscount > bgEntry->maxGroupSize)                // no MinPlayerCount for battlegrounds
        return ERR_BATTLEGROUND_NONE;                        // ERR_GROUP_JOIN_BATTLEGROUND_TOO_MANY handled on client side

    // get a player as reference, to compare other players' stats to (arena team id, queue id based on level, etc.)
    Player * reference = GetFirstMember()->getSource();
    // no reference found, can't join this way
    if (!reference)
        return ERR_BATTLEGROUND_JOIN_FAILED;

    PvPDifficultyEntry const* bracketEntry = GetBattlegroundBracketByLevel(bgOrTemplate->GetMapId(),reference->getLevel());
    if (!bracketEntry)
        return ERR_BATTLEGROUND_JOIN_FAILED;

    uint32 arenaTeamId = reference->GetArenaTeamId(arenaSlot);
    uint32 team = reference->GetTeam();

    BattlegroundQueueTypeId bgQueueTypeIdRandom = BattlegroundMgr::BGQueueTypeId(BATTLEGROUND_RB, 0);

    // check every member of the group to be able to join
    for (GroupReference *itr = GetFirstMember(); itr != NULL; itr = itr->next())
    {
        Player *member = itr->getSource();
        // offline member? don't let join
        if (!member)
            return ERR_BATTLEGROUND_JOIN_FAILED;
        // don't allow cross-faction join as group
        if (member->GetTeam() != team)
            return ERR_BATTLEGROUND_JOIN_TIMED_OUT;
        // not in the same battleground level braket, don't let join
        PvPDifficultyEntry const* memberBracketEntry = GetBattlegroundBracketByLevel(bracketEntry->mapId,member->getLevel());
        if (memberBracketEntry != bracketEntry)
            return ERR_BATTLEGROUND_JOIN_RANGE_INDEX;
        // don't let join rated matches if the arena team id doesn't match
        if (isRated && member->GetArenaTeamId(arenaSlot) != arenaTeamId)
            return ERR_BATTLEGROUND_JOIN_FAILED;
        // don't let join if someone from the group is already in that bg queue
        if (member->InBattlegroundQueueForBattlegroundQueueType(bgQueueTypeId))
            return ERR_BATTLEGROUND_JOIN_FAILED;            // not blizz-like
        // don't let join if someone from the group is in bg queue random
        if (member->InBattlegroundQueueForBattlegroundQueueType(bgQueueTypeIdRandom))
            return ERR_IN_RANDOM_BG;
        // don't let join to bg queue random if someone from the group is already in bg queue
        if (bgOrTemplate->GetTypeID() == BATTLEGROUND_RB && member->InBattlegroundQueue())
            return ERR_IN_NON_RANDOM_BG;
        // check for deserter debuff in case not arena queue
        if (bgOrTemplate->GetTypeID() != BATTLEGROUND_AA && !member->CanJoinToBattleground())
            return ERR_GROUP_JOIN_BATTLEGROUND_DESERTERS;
        // check if member can join any more battleground queues
        if (!member->HasFreeBattlegroundQueueId())
            return ERR_BATTLEGROUND_TOO_MANY_QUEUES;        // not blizz-like
    }
    return GroupJoinBattlegroundResult(bgOrTemplate->GetTypeID());
}

//===================================================
//============== Roll ===============================
//===================================================

void Roll::targetObjectBuildLink()
{
    // called from link()
    getTarget()->addLootValidatorRef(this);
}

void Group::SetDungeonDifficulty(Difficulty difficulty)
{
    m_dungeonDifficulty = difficulty;
    if (!isBGGroup())
       CharacterDatabase.PExecute("UPDATE groups SET difficulty = %u WHERE guid ='%u'", m_dungeonDifficulty, GUID_LOPART(m_guid));

    for (GroupReference *itr = GetFirstMember(); itr != NULL; itr = itr->next())
    {
        Player *player = itr->getSource();
        if (!player->GetSession() || player->getLevel() < LEVELREQUIREMENT_HEROIC)
            continue;
        player->SetDungeonDifficulty(difficulty);
        player->SendDungeonDifficulty(true);
    }
}

void Group::SetRaidDifficulty(Difficulty difficulty)
{
    m_raidDifficulty = difficulty;
    if (!isBGGroup())
        CharacterDatabase.PExecute("UPDATE groups SET raiddifficulty = %u WHERE guid ='%u'", m_raidDifficulty, GUID_LOPART(m_guid));

    for (GroupReference *itr = GetFirstMember(); itr != NULL; itr = itr->next())
    {
        Player *player = itr->getSource();
        if (!player->GetSession() || player->getLevel() < LEVELREQUIREMENT_HEROIC)
            continue;
        player->SetRaidDifficulty(difficulty);
        player->SendRaidDifficulty(true);
    }
}

bool Group::InCombatToInstance(uint32 instanceId)
{
    for (GroupReference *itr = GetFirstMember(); itr != NULL; itr = itr->next())
    {
        Player *pPlayer = itr->getSource();
        if (pPlayer && pPlayer->getAttackers().size() && pPlayer->GetInstanceId() == instanceId && (pPlayer->GetMap()->IsRaidOrHeroicDungeon()))
            for (std::set<Unit*>::const_iterator i = pPlayer->getAttackers().begin(); i != pPlayer->getAttackers().end(); ++i)
          if ((*i) && (*i)->GetTypeId() == TYPEID_UNIT && (*i)->ToCreature()->GetCreatureInfo()->flags_extra & CREATURE_FLAG_EXTRA_INSTANCE_BIND)
                    return true;
    }
    return false;
}

void Group::ResetInstances(uint8 method, bool isRaid, Player* SendMsgTo)
{
    if (isBGGroup())
        return;

    // method can be INSTANCE_RESET_ALL, INSTANCE_RESET_CHANGE_DIFFICULTY, INSTANCE_RESET_GROUP_DISBAND

    // we assume that when the difficulty changes, all instances that can be reset will be
    Difficulty diff = GetDifficulty(isRaid);

    for (BoundInstancesMap::iterator itr = m_boundInstances[diff].begin(); itr != m_boundInstances[diff].end();)
    {
        InstanceSave *p = itr->second.save;
        const MapEntry *entry = sMapStore.LookupEntry(itr->first);
        if (!entry || entry->IsRaid() != isRaid || (!p->CanReset() && method != INSTANCE_RESET_GROUP_DISBAND))
        {
            ++itr;
            continue;
        }

        if (method == INSTANCE_RESET_ALL)
        {
            // the "reset all instances" method can only reset normal maps
            if (entry->map_type == MAP_RAID || diff == DUNGEON_DIFFICULTY_HEROIC)
            {
                ++itr;
                continue;
            }
        }

        bool isEmpty = true;
        // if the map is loaded, reset it
        Map *map = sMapMgr.FindMap(p->GetMapId(), p->GetInstanceId());
        if (map && map->IsDungeon() && !(method == INSTANCE_RESET_GROUP_DISBAND && !p->CanReset()))
        {
            if (p->CanReset())
                isEmpty = ((InstanceMap*)map)->Reset(method);
            else
                isEmpty = !map->HavePlayers();
        }

        if (SendMsgTo)
        {
            if (isEmpty) SendMsgTo->SendResetInstanceSuccess(p->GetMapId());
            else SendMsgTo->SendResetInstanceFailed(0, p->GetMapId());
        }

        if (isEmpty || method == INSTANCE_RESET_GROUP_DISBAND || method == INSTANCE_RESET_CHANGE_DIFFICULTY)
        {
            // do not reset the instance, just unbind if others are permanently bound to it
            if (p->CanReset()) p->DeleteFromDB();
            else CharacterDatabase.PExecute("DELETE FROM group_instance WHERE instance = '%u'", p->GetInstanceId());
            // i don't know for sure if hash_map iterators
            m_boundInstances[diff].erase(itr);
            itr = m_boundInstances[diff].begin();
            // this unloads the instance save unless online players are bound to it
            // (eg. permanent binds or GM solo binds)
            p->RemoveGroup(this);
        }
        else
            ++itr;
    }
}

InstanceGroupBind* Group::GetBoundInstance(Player* player)
{
    uint32 mapid = player->GetMapId();
    MapEntry const* mapEntry = sMapStore.LookupEntry(mapid);
    return GetBoundInstance(mapEntry);
}

InstanceGroupBind* Group::GetBoundInstance(Map* aMap)
{
    // Currently spawn numbering not different from map difficulty
    Difficulty difficulty = GetDifficulty(aMap->IsRaid());

    // some instances only have one difficulty
    GetDownscaledMapDifficultyData(aMap->GetId(),difficulty);

    BoundInstancesMap::iterator itr = m_boundInstances[difficulty].find(aMap->GetId());
    if (itr != m_boundInstances[difficulty].end())
        return &itr->second;
    else
        return NULL;
}

InstanceGroupBind* Group::GetBoundInstance(MapEntry const* mapEntry)
{
    if (!mapEntry)
        return NULL;

    Difficulty difficulty = GetDifficulty(mapEntry->IsRaid());

    // some instances only have one difficulty
    GetDownscaledMapDifficultyData(mapEntry->MapID,difficulty);

    BoundInstancesMap::iterator itr = m_boundInstances[difficulty].find(mapEntry->MapID);
    if (itr != m_boundInstances[difficulty].end())
        return &itr->second;
    else
        return NULL;
}


InstanceGroupBind* Group::BindToInstance(InstanceSave *save, bool permanent, bool load)
{
    if (!save || isBGGroup())
        return NULL;

    InstanceGroupBind& bind = m_boundInstances[save->GetDifficulty()][save->GetMapId()];
    if (!load && (!bind.save || permanent != bind.perm || save != bind.save))
        CharacterDatabase.PExecute("REPLACE INTO group_instance (guid, instance, permanent) VALUES (%u, %u, %u)", GUID_LOPART(GetGUID()), save->GetInstanceId(), permanent);

    if (bind.save != save)
    {
        if (bind.save)
            bind.save->RemoveGroup(this);
        save->AddGroup(this);
    }

    bind.save = save;
    bind.perm = permanent;
    if (!load)
        sLog.outDebug("Group::BindToInstance: %d is now bound to map %d, instance %d, difficulty %d", GUID_LOPART(GetGUID()), save->GetMapId(), save->GetInstanceId(), save->GetDifficulty());
    return &bind;
}

void Group::UnbindInstance(uint32 mapid, uint8 difficulty, bool unload)
{
    BoundInstancesMap::iterator itr = m_boundInstances[difficulty].find(mapid);
    if (itr != m_boundInstances[difficulty].end())
    {
        if (!unload)
            CharacterDatabase.PExecute("DELETE FROM group_instance WHERE guid=%u AND instance=%u", GUID_LOPART(GetGUID()), itr->second.save->GetInstanceId());
        itr->second.save->RemoveGroup(this);                // save can become invalid
        m_boundInstances[difficulty].erase(itr);
    }
}

void Group::_homebindIfInstance(Player *player)
{
    if (player && !player->isGameMaster() && sMapStore.LookupEntry(player->GetMapId())->IsDungeon())
        player->m_InstanceValid = false;
}

void Group::BroadcastGroupUpdate(void)
{
    // FG: HACK: force flags update on group leave - for values update hack
    // -- not very efficient but safe
    for (member_citerator citr = m_memberSlots.begin(); citr != m_memberSlots.end(); ++citr)
    {

        Player *pp = sObjectMgr.GetPlayer(citr->guid);
        if (pp && pp->IsInWorld())
        {
            pp->ForceValuesUpdateAtIndex(UNIT_FIELD_BYTES_2);
            pp->ForceValuesUpdateAtIndex(UNIT_FIELD_FACTIONTEMPLATE);
            sLog.outStaticDebug("-- Forced group value update for '%s'", pp->GetName());
        }
    }
}

void Group::ResetMaxEnchantingLevel()
{
    m_maxEnchantingLevel = 0;
    Player *pMember = NULL;
    for (member_citerator citr = m_memberSlots.begin(); citr != m_memberSlots.end(); ++citr)
    {
        pMember = sObjectMgr.GetPlayer(citr->guid);
        if (pMember && m_maxEnchantingLevel < pMember->GetSkillValue(SKILL_ENCHANTING))
            m_maxEnchantingLevel = pMember->GetSkillValue(SKILL_ENCHANTING);
    }
}
