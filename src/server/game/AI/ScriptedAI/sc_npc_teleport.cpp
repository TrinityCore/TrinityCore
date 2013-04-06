/**
 *
 * @File : sc_npc_teleport.cpp
 *
 * @Authors : Wilibald09
 *
 * @Date : 28/08/2008
 *
 * @Version : 1.2
 *
 **/


#include "ScriptPCH.h"
#include "sc_npc_teleport.h"
//#include "ProgressBar.h"

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

TELE::CatDest(const uint32 &id, const std::string &name,
              const Flag &flag, const uint64 &data0, const uint32 &data1)
    : m_id(id), m_name(name), m_flag(flag), m_data0(data0), m_data1(data1)
{
    m_TabDest.clear();
}

std::string TELE::GetName(const bool IsGM /* = false */) const
{
    if (!IsGM || m_flag != FLAG_TEAM)
        return m_name;

    switch (m_data0)
    {
      case TEAM_HORDE:      return std::string(m_name + " (H)");
      case TEAM_ALLIANCE:   return std::string(m_name + " (A)");
    }
    return m_name;
}

bool TELE::IsAllowedToTeleport(Player * const player) const
{
    if (player->isGameMaster())
    {
        if (m_flag == FLAG_GMLEVEL)
            return player->GetSession()->GetSecurity() >= m_data0;
        return true;
    }

    switch (m_flag)
    {
      case FLAG_TEAM:
        switch (m_data0)
        {
          case TEAM_HORDE:      return player->GetTeam() == HORDE;
          case TEAM_ALLIANCE:   return player->GetTeam() == ALLIANCE;
          case TEAM_ALL:        return true;
        }

      case FLAG_GUILD:
        return player->GetGuildId() == m_data0;

      case FLAG_GMLEVEL:
        return player->GetSession()->GetSecurity() >= m_data0;

      case FLAG_ISGM:
        return player->isGameMaster();

      case FLAG_ACCOUNT:
        return player->GetSession()->GetAccountId() == m_data0;

      case FLAG_LEVEL:
        return player->getLevel() >= m_data0;

      case FLAG_ITEM:
        return player->HasItemCount(m_data0, m_data1, true);

      case FLAG_QUEST:
        if (m_data1 < MAX_QUEST_STATUS)
            return player->GetQuestStatus(m_data0) == m_data1;
        return player->GetQuestRewardStatus(m_data0);

      case FLAG_GENDER:
        return player->getGender() == m_data0;

      case FLAG_RACE:
        return player->getRace() == m_data0;

      case FLAG_CLASS:
        return player->getClass() == m_data0;

      case FLAG_REPUTATION:
        return player->GetReputationRank(m_data0) >= m_data1;

      case FLAG_PLAYER:
        return player->GetGUID() == m_data0;
    }

   sLog->outError(LOG_FILTER_GENERAL, "Invalid flag (category: %u). Important problem...", GetCatID());
    return false;
}

uint32 TELE::CountOfCategoryAllowedBy(Player * const player)
{
    uint32 count (0);
    for (VCatDest_t i(0); i < TabCatDest.size(); ++i)
    {
        if (TabCatDest[i].IsAllowedToTeleport(player))
            ++count;
    }
    return count;
}

bool nsNpcTel::IsValidData(const uint32 &cat,   const Flag &flag,
                           const uint64 &data0, const uint32 &data1)
{
    switch(flag)
    {
      case FLAG_TEAM:
        if (data1)
           sLog->outError(LOG_FILTER_GENERAL, "Invalid data1 (category: %u).", cat);
        if (data0 < MAX_FLAG_TEAM)
            return true;
        sLog->outError(LOG_FILTER_GENERAL, "Invalid data0 (Team) (category: %u).", cat);
        return false;

      case FLAG_GUILD:
        if (data1)
            sLog->outError(LOG_FILTER_GENERAL, "Invalid data1 (category: %u).", cat);
        if (data0)
            return true;
        sLog->outError(LOG_FILTER_GENERAL, "Invalid data0 (GuildID) (category: %u).", cat);
        return false;

      case FLAG_GMLEVEL:
        if (data1)
            sLog->outError(LOG_FILTER_GENERAL, "Invalid data1 (category: %u).", cat);
        if (0 < data0 && data0 < 256)
            return true;
        sLog->outError(LOG_FILTER_GENERAL, "Invalid data0 (GmLevel) (category: %u).", cat);
        return false;

      case FLAG_ISGM:
        if (data0)
            sLog->outError(LOG_FILTER_GENERAL, "Invalid data0 (category: %u).", cat);
        if (data1)
            sLog->outError(LOG_FILTER_GENERAL, "Invalid data1 (category: %u).", cat);
        return true;

      case FLAG_ACCOUNT:
        if (data1)
            sLog->outError(LOG_FILTER_GENERAL, "Invalid data1 (category: %u).", cat);
        if (data0)
            return true;
        sLog->outError(LOG_FILTER_GENERAL, "Invalid data0 (AccountID) (category: %u).", cat);
        return false;

      case FLAG_LEVEL:
        if (data1)
            sLog->outError(LOG_FILTER_GENERAL, "Invalid data1 (category: %u).", cat);
        if (0 < data0 && data0 < 256)
            return true;
        sLog->outError(LOG_FILTER_GENERAL, "Invalid data0 (Level) (category: %u).", cat);
        return false;

      case FLAG_ITEM:
        if (!data0)
        {
            sLog->outError(LOG_FILTER_GENERAL, "Invalid data0 (ItemID) (category: %u).", cat);
            return false;
        }
        if (data1)
            return true;
        sLog->outError(LOG_FILTER_GENERAL, "Invalid data1 (Item Count) (category: %u).", cat);
        return false;

      case FLAG_QUEST:
        if (!data0)
        {
           sLog->outError(LOG_FILTER_GENERAL, "Invalid data0 (QuestID) (category: %u).", cat);
            return false;
        }
        if (data1 < MAX_QUEST_STATUS + 1)
            return true;
        sLog->outError(LOG_FILTER_GENERAL, "Invalid data1 (Quest Status) (category: %u).", cat);
        return false;

      case FLAG_GENDER:
        if (data1)
            sLog->outError(LOG_FILTER_GENERAL, "Invalid data1 (category: %u).", cat);
        if (data0 < GENDER_NONE)
            return true;
        sLog->outError(LOG_FILTER_GENERAL, "Invalid data0 (Gender) (category: %u).", cat);
        return false;

      case FLAG_RACE:
        if (data1)
            sLog->outError(LOG_FILTER_GENERAL, "Invalid data1 (category: %u).", cat);
        if (0 < data0 && data0 < MAX_RACES)
            return true;
        sLog->outError(LOG_FILTER_GENERAL, "Invalid data0 (Race) (category: %u).", cat);
        return false;

      case FLAG_CLASS:
        if (data1)
            sLog->outError(LOG_FILTER_GENERAL, "Invalid data1 (category: %u).", cat);
        if (0 < data0 && data0 < MAX_CLASSES)
            return true;
        sLog->outError(LOG_FILTER_GENERAL, "Invalid data0 (Class) (category: %u).", cat);
        return false;

      case FLAG_REPUTATION:
        if (!data0)
        {
            sLog->outError(LOG_FILTER_GENERAL, "Invalid data0 (Faction/Reputation) (category: %u).", cat);
            return false;
        }
        if (data1 <= REP_EXALTED)
            return true;
        sLog->outError(LOG_FILTER_GENERAL, "Invalid data1 (Faction/Reputation) (category: %u).", cat);
        return false;

      case FLAG_PLAYER:
        if (data1)
            sLog->outError(LOG_FILTER_GENERAL, "Invalid data1 (category: %u).", cat);
        if (data0)
            return true;
        sLog->outError(LOG_FILTER_GENERAL, "Invalid data0 (PlayerGuid) (category: %u).", cat);
        return false;
    }

    sLog->outError(LOG_FILTER_GENERAL, "Invalid flag (category: %u).", cat);
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
        "SELECT `flag`, `data0`, `data1`, `cat_id`, C.`name` `namecat`, D.`name` `namedest`, "
        //      0        1        2        3                  4                   5
               "`pos_X`, `pos_Y`, `pos_Z`, `orientation`, `map`, `level`, `cost` "
        //      6        7        8        9              10     11       12
        "FROM `%s` C, `%s` D, `%s` A "
        "WHERE C.`id` = `cat_id` AND D.`id` = `dest_id` "
        "ORDER BY `namecat`, `cat_id`, `namedest`", Table[0], Table[1], Table[2]);

    nsNpcTel::TabCatDest.clear();

    if (result)
    {
        sLog->outError(LOG_FILTER_TSCR, "TSCR: Loading %s, %s and %s...", Table[0], Table[1], Table[2]);
        // barGoLink bar(result->GetRowCount());

        uint32 catid = 0;
        uint32 nbDest = 0;
        bool IsValidCat = true;
        bool FirstTime = true;

        do
        {
            // bar.step();
            Field *fields = result->Fetch();

            if (!IsValidCat && catid == fields[3].GetUInt32() && !FirstTime)
                continue;

            IsValidCat = true;
            FirstTime = false;

            if (!nsNpcTel::IsValidData(fields[3].GetUInt32(), (nsNpcTel::Flag)fields[0].GetUInt8(),
                                       fields[1].GetUInt64(), fields[2].GetUInt32()))
            {
                IsValidCat = false;
                catid = fields[3].GetUInt32();
                continue;
            }

            if (catid != fields[3].GetUInt32())
            {
                catid = fields[3].GetUInt32();
                nsNpcTel::CatDest categorie (catid, fields[4].GetString(), (nsNpcTel::Flag)fields[0].GetUInt8(),
                                             fields[1].GetUInt64(), fields[2].GetUInt32());
                nsNpcTel::TabCatDest.push_back(categorie);
            }

            nsNpcTel::Dest item =
            {
                fields[5].GetString(),   // Name
                fields[6].GetFloat(),       // X
                fields[7].GetFloat(),       // Y
                fields[8].GetFloat(),       // Z
                fields[9].GetFloat(),       // Orientation
                fields[10].GetUInt16(),     // Map
                fields[11].GetUInt8(),      // Level
                fields[12].GetUInt32(),     // Cost
            };

            nsNpcTel::TabCatDest.back().AddDest(item);
            ++nbDest;
        } while (result->NextRow());

        sLog->outError(LOG_FILTER_TSCR, "");
        sLog->outError(LOG_FILTER_TSCR, "TSCR: >> Loaded %u npc_teleport.", nbDest);
    }
	else 
	sLog->outError(LOG_FILTER_TSCR, "TSCR: WARNING >> Loaded 0 npc_teleport.");
}


#undef TELE
#undef PAGE
#undef PAGEI
