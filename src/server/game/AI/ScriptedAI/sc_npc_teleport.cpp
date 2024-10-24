/*
 * Copyright (C) 20??-2008 Wilibald09
 * Copyright (C) 2011-2015 ArkCORE <http://www.arkania.net/>
 * Copyright (C) 2008-2019 TrinityCore <http://www.trinitycore.org/>
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

#include "Player.h"
#include "Log.h"
#include "sc_npc_teleport.h"
#include "WorldSession.h"
#include "DatabaseEnv.h"
#define TELE    nsNpcTel::CatDest
#define PAGE    nsNpcTel::Page
#define PAGEI   PAGE::Instance

nsNpcTel::VCatDest nsNpcTel::TabCatDest;

uint32 PAGE::operator [] (Player * const player) const
{
    for (VInst_t i(0); i < m_TabInstance.size(); ++i)
    {
        if (m_TabInstance[i].GetPlayer() == player)
            return m_TabInstance[i].GetPageId();
    }
    return 0;
}

PAGE::Instance & PAGE::operator () (Player * const player)
{
    for (VInst_t i(0); i < m_TabInstance.size(); ++i)
    {
        if (m_TabInstance[i].GetPlayer() == player)
            return m_TabInstance[i];
    }
    m_TabInstance.push_back(Instance(player));
    return m_TabInstance.back();
}

PAGE::Instance & PAGEI::operator = (const uint32 &id)
{
    m_PageId = id;
    return *this;
}

PAGE::Instance & PAGEI::operator ++ (void)
{
    ++m_PageId;
    return *this;
}

PAGE::Instance PAGEI::operator ++ (int32)
{
    Instance tmp (*this);
    ++m_PageId;
    return tmp;
}

PAGE::Instance & PAGEI::operator -- (void)
{
    --m_PageId;
    return *this;
}

PAGE::Instance PAGEI::operator -- (int32)
{
    Instance tmp (*this);
    --m_PageId;
    return tmp;
}

TELE::CatDest(const CatValue cat, const CatName catname)
    : m_catvalue(cat), m_catname(catname)
{
    m_TabDest.clear();
}

std::string TELE::GetName(const uint8 loc /* = 0 */, const bool IsGM /* = false */) const
{
    std::string icon = m_catname.icon;
    std::string size = m_catname.size;
    std::string colour = m_catname.colour;
    std::string name = m_catname.name[loc];
    if (name.length() == 0)
        name = m_catname.name[0];

    if (!IsGM || m_catvalue.flag != FLAG_TEAM)
    {
        return "|TInterface/ICONS/"+icon+":"+size+":"+size+"|t|c"+colour+" "+name;
    }

    switch (m_catvalue.data0)
    {
      case TEAM_HORDE:      return "|TInterface/ICONS/"+icon+":"+size+":"+size+"|t|c"+colour+" "+name + " (H)";
      case TEAM_ALLIANCE:   return "|TInterface/ICONS/"+icon+":"+size+":"+size+"|t|c"+colour+" "+name + " (A)";
    }
    return "|TInterface/ICONS/"+icon+":"+size+":"+size+"|t|c"+colour+" "+name;;
}

bool TELE::IsAllowedToTeleport(Player * const player) const
{
    if (player->IsGameMaster())
    {
        if (m_catvalue.flag == FLAG_GMLEVEL)
            return player->GetSession()->GetSecurity() >= m_catvalue.data0;
        return true;
    }

    switch (m_catvalue.flag)
    {
      case FLAG_TEAM:
        switch (m_catvalue.data0)
        {
          case TEAM_HORDE:      return player->GetTeam() == HORDE;
          case TEAM_ALLIANCE:   return player->GetTeam() == ALLIANCE;
          case TEAM_ALL:        return true;
          default: TC_LOG_ERROR("misc", "Invalid m_catvalue.data0 . Important problem..."); return false;
        }

      case FLAG_GUILD:
        return player->GetGuildId() == m_catvalue.data0;

      case FLAG_GMLEVEL:
        return player->GetSession()->GetSecurity() >= m_catvalue.data0;

      case FLAG_ISGM:
        return player->IsGameMaster();

      case FLAG_ACCOUNT:
        return player->GetSession()->GetAccountId() == m_catvalue.data0;

      case FLAG_LEVEL:
        return player->GetLevel() >= m_catvalue.data0;

      case FLAG_ITEM:
        return player->HasItemCount(m_catvalue.data0, m_catvalue.data1, true);

      case FLAG_QUEST:
        if (m_catvalue.data1 < MAX_QUEST_STATUS)
            return player->GetQuestStatus(m_catvalue.data0) == m_catvalue.data1;
        return player->GetQuestRewardStatus(m_catvalue.data0);

      case FLAG_GENDER:
        return player->GetGender() == m_catvalue.data0;

      case FLAG_RACE:
        return player->GetRace() == m_catvalue.data0;

      case FLAG_CLASS:
        return player->GetClass() == m_catvalue.data0;

      case FLAG_REPUTATION:
        return player->GetReputationRank(m_catvalue.data0) >= (int32)m_catvalue.data1;

      case FLAG_PLAYER:
        return player->GetGUID() == m_catvalue.data0;

      default: TC_LOG_ERROR("misc", "Invalid flag (category: %u). Important problem...", GetCatID()); return false;
    }

    TC_LOG_ERROR("misc", "Invalid flag (category: %u). Important problem...", GetCatID());
    return false;
}

uint32 TELE::CountOfCategoryAllowedBy(Player * const player)
{
    uint32 count(0);
    for (VCatDest_t i(0); i < TabCatDest.size(); ++i)
    {
        if (TabCatDest[i].IsAllowedToTeleport(player))
            ++count;
    }
    return count;
}

bool nsNpcTel::IsValidData(CatValue catvalue) //  const uint32 &cat, const Flag &flag, const uint64 &data0, const uint32 &data1
{
    switch (catvalue.flag)
    {
      case FLAG_TEAM:
        if (catvalue.data1)
            TC_LOG_ERROR("misc", "Invalid data1 (category: {}).", catvalue.catid);
        if (catvalue.data0 < MAX_FLAG_TEAM)
            return true;
        TC_LOG_ERROR("misc", "Invalid data0 (Team) (category: {}).", catvalue.catid);
        return false;

      case FLAG_GUILD:
        if (catvalue.data1)
            TC_LOG_ERROR("misc", "Invalid data1 (category: {}).", catvalue.catid);
        if (catvalue.data0)
            return true;
        TC_LOG_ERROR("misc", "Invalid data0 (GuildID) (category: {}).", catvalue.catid);
        return false;

      case FLAG_GMLEVEL:
        if (catvalue.data1)
            TC_LOG_ERROR("misc", "Invalid data1 (category: {}).", catvalue.catid);
        if (0 < catvalue.data0 && catvalue.data0 < 256)
            return true;
        TC_LOG_ERROR("misc", "Invalid data0 (GmLevel) (category: {}).", catvalue.catid);
        return false;

      case FLAG_ISGM:
        if (catvalue.data0)
            TC_LOG_ERROR("misc", "Invalid data0 (category: {}).", catvalue.catid);
        if (catvalue.data1)
            TC_LOG_ERROR("misc", "Invalid data1 (category: {}).", catvalue.catid);
        return true;

      case FLAG_ACCOUNT:
        if (catvalue.data1)
            TC_LOG_ERROR("misc", "Invalid data1 (category: {}).", catvalue.catid);
        if (catvalue.data0)
            return true;
        TC_LOG_ERROR("misc", "Invalid data0 (AccountID) (category: {}).", catvalue.catid);
        return false;

      case FLAG_LEVEL:
        if (catvalue.data1)
            TC_LOG_ERROR("misc", "Invalid data1 (category: {}).", catvalue.catid);
        if (0 < catvalue.data0 && catvalue.data0 < 256)
            return true;
        TC_LOG_ERROR("misc", "Invalid data0 (Level) (category: {}).", catvalue.catid);
        return false;

      case FLAG_ITEM:
        if (!catvalue.data0)
        {
            TC_LOG_ERROR("misc", "Invalid data0 (ItemID) (category: {}).", catvalue.catid);
            return false;
        }
        if (catvalue.data1)
            return true;
        TC_LOG_ERROR("misc", "Invalid data1 (Item Count) (category: {}).", catvalue.catid);
        return false;

      case FLAG_QUEST:
        if (!catvalue.data0)
        {
            TC_LOG_ERROR("misc", "Invalid data0 (QuestID) (category: {}).", catvalue.catid);
            return false;
        }
        if (catvalue.data1 < MAX_QUEST_STATUS + 1)
            return true;
        TC_LOG_ERROR("misc", "Invalid data1 (Quest Status) (category: {}).", catvalue.catid);
        return false;

      case FLAG_GENDER:
        if (catvalue.data1)
            TC_LOG_ERROR("misc", "Invalid data1 (category: {}).", catvalue.catid);
        if (catvalue.data0 < GENDER_NONE)
            return true;
        TC_LOG_ERROR("misc", "Invalid data0 (Gender) (category: {}).", catvalue.catid);
        return false;

      case FLAG_RACE:
        if (catvalue.data1)
            TC_LOG_ERROR("misc", "Invalid data1 (category: {}).", catvalue.catid);
        if (0 < catvalue.data0 && catvalue.data0 < MAX_RACES)
            return true;
        TC_LOG_ERROR("misc", "Invalid data0 (Race) (category: {}).", catvalue.catid);
        return false;

      case FLAG_CLASS:
        if (catvalue.data1)
            TC_LOG_ERROR("misc", "Invalid data1 (category: {}).", catvalue.catid);
        if (0 < catvalue.data0 && catvalue.data0 < MAX_CLASSES)
            return true;
        TC_LOG_ERROR("misc", "Invalid data0 (Class) (category: {}).", catvalue.catid);
        return false;

      case FLAG_REPUTATION:
        if (!catvalue.data0)
        {
            TC_LOG_ERROR("misc", "Invalid data0 (Faction/Reputation) (category: {}).", catvalue.catid);
            return false;
        }
        if (catvalue.data1 <= REP_EXALTED)
            return true;
        TC_LOG_ERROR("misc", "Invalid data1 (Faction/Reputation) (category: {}).", catvalue.catid);
        return false;

      case FLAG_PLAYER:
        if (catvalue.data1)
            TC_LOG_ERROR("misc", "Invalid data1 (category: {}).", catvalue.catid);
        if (catvalue.data0)
            return true;
        TC_LOG_ERROR("misc", "Invalid data0 (PlayerGuid) (category: {}).", catvalue.catid);
        return false;

      default: TC_LOG_ERROR("misc", "Invalid flag (category: {}).", catvalue.catid);
    }

    TC_LOG_ERROR("misc", "Invalid flag (category: {}).", catvalue.catid);
    return false;
}

void LoadNpcTele(void)
{
    const char *Table[] =
    {
        "custom_npc_tele_category",
        "custom_npc_tele_destination",
        "custom_npc_tele_association",
    };

    QueryResult result = WorldDatabase.PQuery(
        "SELECT `flag`, `data0`, `data1`, `cat_id`, C.`icon` `iconcat`, C.`size` `iconsize`,  C.`colour` `colourcat`, C.`name` `namecat`, "
        //       0       1        2        3                  4                   5                       6                     7
        "C.`name_loc1`, C.`name_loc2`, C.`name_loc3`, C.`name_loc4`, C.`name_loc5`, C.`name_loc6`, C.`name_loc7`, C.`name_loc8`, "
        //  8              9              10             11             12             13             14             15
        "D.`icon` `icondest`, D.`size` `sizedest`, D.`colour` `colourdest`, D.`name` `namedest`, "
        //         16                   17                     18                     19
        "D.`name_loc1`, D.`name_loc2`, D.`name_loc3`, D.`name_loc4`, D.`name_loc5`, D.`name_loc6`, D.`name_loc7`, D.`name_loc8`, "
        //  20             21             22             23             24             25             26             27
        "`pos_X`, `pos_Y`, `pos_Z`, `orientation`, `map`, `level`, `cost` "
        //28       29       30       31             32     33       34
        "FROM `{}` C, `{}` D, `{}` A "
        "WHERE C.`id` = `cat_id` AND D.`id` = `dest_id` "
        "ORDER BY `namecat`, `cat_id`, `namedest`", Table[0], Table[1], Table[2]);

    nsNpcTel::TabCatDest.clear();

    if (result)
    {
        TC_LOG_INFO("server.loading", "Loading {}, {} and {}...", Table[0], Table[1], Table[2]);

        uint32 catid = 0;
        uint32 nbDest = 0;
        bool IsValidCat = true;
        bool FirstTime = true;

        do
        {
            Field *fields = result->Fetch();

            if (!IsValidCat && catid == fields[3].GetUInt32() && !FirstTime)
                continue;

            IsValidCat = true;
            FirstTime = false;

            nsNpcTel::CatValue catvalue =
            {
                fields[3].GetUInt32(),
                (nsNpcTel::Flag)fields[0].GetUInt8(),
                fields[1].GetUInt64(),
                fields[2].GetUInt32()
            };

            if (!nsNpcTel::IsValidData(catvalue))
            {
                IsValidCat = false;
                catid = catvalue.catid;
                continue;
            }

            if (catid != catvalue.catid)
            {
                catid = catvalue.catid;
                nsNpcTel::CatName catname =
                {
                    fields[4].GetString(),  // Cat icon
                    fields[5].GetString(),  // Cat size
                    fields[6].GetString(),  // Cat colour
                    {
                        fields[7].GetString(),  // Cat Name
                        fields[8].GetString(),  // Cat Name Loc1
                        fields[9].GetString(),  // Cat Name Loc2
                        fields[10].GetString(),  // Cat Name Loc3
                        fields[11].GetString(),  // Cat Name Loc4
                        fields[12].GetString(),  // Cat Name Loc5
                        fields[13].GetString(), // Cat Name Loc6
                        fields[14].GetString(), // Cat Name Loc7
                        fields[15].GetString()  // Cat Name Loc8
                    }
                };

                nsNpcTel::CatDest categorie(catvalue, catname);
                nsNpcTel::TabCatDest.push_back(categorie);
            }

            nsNpcTel::Dest item =
            {
                fields[16].GetString(),    // Dest icon
                fields[17].GetString(),    // Dest size
                fields[18].GetString(),    // Dest colour
                {
                    fields[19].GetString(),    // Dest Name
                    fields[20].GetString(),    // Dest Name_loc1
                    fields[21].GetString(),    // Dest Name_loc2
                    fields[22].GetString(),    // Dest Name_loc3
                    fields[23].GetString(),    // Dest Name_loc4
                    fields[24].GetString(),    // Dest Name_loc5
                    fields[25].GetString(),    // Dest Name_loc6
                    fields[26].GetString(),    // Dest Name_loc7
                    fields[27].GetString()     // Dest Name_loc8
                },
                fields[28].GetFloat(),      // X
                fields[29].GetFloat(),      // Y
                fields[30].GetFloat(),      // Z
                fields[31].GetFloat(),      // Orientation
                fields[32].GetUInt16(),     // Map
                fields[33].GetUInt8(),      // Level
                fields[34].GetUInt32()      // Cost
            };

            nsNpcTel::TabCatDest.back().AddDest(item);
            ++nbDest;
        } while (result->NextRow());

        TC_LOG_INFO("server.loading", " ");
        TC_LOG_INFO("server.loading", "Loaded {} npc_teleport.", nbDest);
    }
    else
        TC_LOG_ERROR("misc", "WARNING >> Loaded 0 npc_teleport.");
}

#undef TELE
