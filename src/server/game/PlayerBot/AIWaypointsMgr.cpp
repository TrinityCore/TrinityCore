
#include "AIWaypointsMgr.h"
#include "Player.h"
#include "TemporarySummon.h"
#include "Log.h"
#include "MotionMaster.h"

// ????? 21343
#define AIWP_CREATURE_ENTRY 18593

char AIWaypoint::resolverBuffer[128];

void AIWaypoint::LinkToAIWP(AIWaypoint* aiwp)
{
    if (!aiwp || aiwp == this)
        return;
    for (int i = 0; i < MAX_LINK_AIWP; i++)
    {
        if (linkAWP[i] == aiwp)
        {
            return;
        }
        if (linkAWP[i] == NULL)
        {
            linkAWP[i] = aiwp;
            return;
        }
    }
}

void AIWaypoint::BreakToAIWP(AIWaypoint* aiwp)
{
    if (!aiwp || aiwp == this)
        return;
    for (int i = 0; i < MAX_LINK_AIWP; i++)
    {
        if (linkAWP[i] == aiwp)
        {
            for (int j = i; j < MAX_LINK_AIWP; j++)
            {
                if (j = MAX_LINK_AIWP - 1)
                    linkAWP[j] = NULL;
                else
                    linkAWP[j] = linkAWP[j + 1];
            }
            return;
        }
    }
}

//void AIWaypoint::ProcessLinkInfo(AIWaypointsMgr* aiwpMgr)
//{
//	if (processLink.size() > (RESOLVER_BUF_SIZE - 1))
//		return;
//	memset(AIWaypoint::resolverBuffer, 0, RESOLVER_BUF_SIZE);
//	memcpy(AIWaypoint::resolverBuffer, processLink.c_str(), processLink.size());
//	AIWaypoint::resolverBuffer[processLink.size() + 1] = 0;
//
//	char* str = strtok(AIWaypoint::resolverBuffer, ",");
//	while (str)
//	{
//		uint32 entry = atoi(str);
//		if (entry == 0)
//			break;
//		AIWaypoint* aiwp = aiwpMgr->FindAIWaypoint(entry);
//		if (aiwp)
//		{
//			for (int i = 0; i < MAX_LINK_AIWP; i++)
//			{
//				if (linkAWP[i] == NULL)
//				{
//					linkAWP[i] = aiwp;
//					aiwp = 0;
//					break;
//				}
//			}
//		}
//		str = strtok(NULL, ",");
//	}
//}

void AIWaypoint::NewToDatabase()
{
    processLink.clear();
    for (int i = 0; i < MAX_LINK_AIWP; i++)
    {
        if (linkAWP[i] == NULL)
            break;
        memset(AIWaypoint::resolverBuffer, 0, RESOLVER_BUF_SIZE);
        itoa(linkAWP[i]->entry, AIWaypoint::resolverBuffer, 10);
        processLink += AIWaypoint::resolverBuffer;
        processLink += ',';
    }

    WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_INS_AIWAYPOINTS);
    stmt->setUInt32(0, entry);
    stmt->setUInt32(1, mapID);
    stmt->setFloat(2, posX);
    stmt->setFloat(3, posY);
    stmt->setFloat(4, posZ);
    stmt->setString(5, processLink);
    ///*PreparedQueryResultFuture resultFuture = */WorldDatabase.AsyncQuery(stmt);
}

void AIWaypoint::SaveToDatabase()
{
    processLink.clear();
    for (int i = 0; i < MAX_LINK_AIWP; i++)
    {
        if (linkAWP[i] == NULL)
            break;
        memset(AIWaypoint::resolverBuffer, 0, RESOLVER_BUF_SIZE);
        itoa(linkAWP[i]->entry, AIWaypoint::resolverBuffer, 10);
        processLink += AIWaypoint::resolverBuffer;
        processLink += ',';
    }

    WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_UPD_AIWAYPOINTS);
    stmt->setUInt32(0, mapID);
    stmt->setFloat(1, posX);
    stmt->setFloat(2, posY);
    stmt->setFloat(3, posZ);
    stmt->setString(4, processLink);
    stmt->setString(5, pointDesc);
    stmt->setUInt32(6, entry);
    /*PreparedQueryResultFuture resultFuture = */WorldDatabase.AsyncQuery(stmt);
}

void AIWaypoint::DeleteToDatabase()
{
    WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_AIWAYPOINTS);
    stmt->setUInt32(0, entry);
    //PreparedQueryResultFuture resultFuture = WorldDatabase.AsyncQuery(stmt);
}

AIWaypointsMgr::AIWaypointsMgr() :
    m_lastAIWPEntry(0)
{
}

AIWaypointsMgr::~AIWaypointsMgr()
{
    for (AIWPMap::iterator itAIWP = m_AIWaypointMap.begin();
        itAIWP != m_AIWaypointMap.end();
        itAIWP++)
    {
        delete itAIWP->second;
    }
    m_AIWaypointMap.clear();
}

AIWaypointsMgr* AIWaypointsMgr::instance()
{
    static AIWaypointsMgr instance;
    return &instance;
}

bool AIWaypointsMgr::LoadAIWaypoints()
{
    uint32 oldMSTime = getMSTime();

    m_lastAIWPEntry = 0;
    for (AIWPMap::iterator itAIWP = m_AIWaypointMap.begin();
        itAIWP != m_AIWaypointMap.end();
        itAIWP++)
    {
        delete itAIWP->second;
    }
    m_AIWaypointMap.clear();

    QueryResult curIncrementResult = WorldDatabase.Query("SELECT `AUTO_INCREMENT` FROM information_schema.`TABLES` WHERE `TABLE_NAME`='aiwaypoints'");
    if (curIncrementResult)
    {
        Field* fields = curIncrementResult->Fetch();
        uint32 curIncr = fields[0].GetUInt32();
        m_lastAIWPEntry = curIncr;
    }
    else
    {
        TC_LOG_INFO("server.loading", ">> Load aiwaypoints AUTO_INCREMENT error!!!");
        return false;
    }

    WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_ALL_AIWAYPOINTS);
    PreparedQueryResult result = WorldDatabase.Query(stmt);
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            uint32 entry = fields[0].GetUInt32();
            uint32 map = fields[1].GetUInt32();
            float x = fields[2].GetFloat();
            float y = fields[3].GetFloat();
            float z = fields[4].GetFloat();
            std::string link = fields[5].GetString();
            std::string desc = fields[6].GetString();
            AIWaypoint* aiwp = new AIWaypoint(entry, map, x, y, z, link, desc);
            if (m_AIWaypointMap.find(entry) == m_AIWaypointMap.end())
                m_AIWaypointMap[entry] = aiwp;
            else
            {
                delete aiwp;
            }
            if (m_lastAIWPEntry < aiwp->entry)
                m_lastAIWPEntry = aiwp->entry;
        } while (result->NextRow());

        //for (AIWPMap::iterator itAIWP = m_AIWaypointMap.begin();
        //	itAIWP != m_AIWaypointMap.end();
        //	itAIWP++)
        //{
        //	itAIWP->second->ProcessLinkInfo(this);
        //}
    }

    TC_LOG_INFO("server.loading", ">> Loaded %u ai way points %u ms", m_AIWaypointMap.size(), GetMSTimeDiffToNow(oldMSTime));
    return true;
}

AIWaypoint* AIWaypointsMgr::FindAIWaypoint(uint32 entry)
{
    AIWPMap::iterator itMap = m_AIWaypointMap.find(entry);
    if (itMap == m_AIWaypointMap.end())
        return NULL;
    return itMap->second;
}

AIWaypoint* AIWaypointsMgr::AddNewWaypoint(uint32 map, float x, float y, float z)
{
    if (m_AIWaypointMap.find(m_lastAIWPEntry) != m_AIWaypointMap.end())
        return NULL;
    AIWaypoint* aiwp = new AIWaypoint(m_lastAIWPEntry, map, x, y, z, "", "");
    m_AIWaypointMap[aiwp->entry] = aiwp;
    aiwp->NewToDatabase();
    ++m_lastAIWPEntry;
    return aiwp;
}

bool AIWaypointsMgr::MovementWaypoint(uint32 entry, float x, float y, float z)
{
    AIWPMap::iterator itMap = m_AIWaypointMap.find(entry);
    if (itMap == m_AIWaypointMap.end())
        return false;
    AIWaypoint* aiwp = itMap->second;
    aiwp->posX = x;
    aiwp->posY = y;
    aiwp->posZ = z;
    aiwp->SaveToDatabase();
    return true;
}

bool AIWaypointsMgr::WaypointDesc(uint32 point, std::string descStr)
{
    AIWPMap::iterator itPoint = m_AIWaypointMap.find(point);
    if (itPoint == m_AIWaypointMap.end())
        return false;
    itPoint->second->pointDesc = descStr;
    itPoint->second->SaveToDatabase();
    return true;
}

bool AIWaypointsMgr::LinkWaypoint(uint32 srcPoint, uint32 dstPoint)
{
    AIWPMap::iterator itSrc = m_AIWaypointMap.find(srcPoint);
    if (itSrc == m_AIWaypointMap.end())
        return false;
    AIWPMap::iterator itDst = m_AIWaypointMap.find(dstPoint);
    if (itDst == m_AIWaypointMap.end())
        return false;

    itDst->second->LinkToAIWP(itSrc->second);
    itSrc->second->LinkToAIWP(itDst->second);
    itSrc->second->SaveToDatabase();
    itDst->second->SaveToDatabase();
    return true;
}

bool AIWaypointsMgr::BreakWaypoint(uint32 srcPoint, uint32 dstPoint)
{
    AIWPMap::iterator itSrc = m_AIWaypointMap.find(srcPoint);
    if (itSrc == m_AIWaypointMap.end())
        return false;
    AIWPMap::iterator itDst = m_AIWaypointMap.find(dstPoint);
    if (itDst == m_AIWaypointMap.end())
        return false;

    itDst->second->BreakToAIWP(itSrc->second);
    itSrc->second->BreakToAIWP(itDst->second);
    itSrc->second->SaveToDatabase();
    itDst->second->SaveToDatabase();
    return true;
}

bool AIWaypointsMgr::DeleteWaypoint(uint32 entry)
{
    AIWPMap::iterator itMap = m_AIWaypointMap.find(entry);
    if (itMap == m_AIWaypointMap.end())
        return false;
    AIWaypoint* aiwp = itMap->second;
    aiwp->DeleteToDatabase();
    delete aiwp;
    m_AIWaypointMap.erase(itMap);
    return true;
}

bool AIWaypointsMgr::ShowAllAIWaypointsCreature(Player* player)
{
    for (AIWPMap::iterator itAIWP = m_AIWaypointMap.begin();
        itAIWP != m_AIWaypointMap.end();
        itAIWP++)
    {
        AIWaypoint* aiwp = itAIWP->second;
        if (aiwp->mapID != player->GetMapId())
            continue;
        if (m_AIWPCreatures.find(aiwp->entry) != m_AIWPCreatures.end())
            continue;
        TempSummon* pSummon = player->SummonCreature(AIWP_CREATURE_ENTRY, aiwp->posX, aiwp->posY, aiwp->posZ, player->GetOrientation());
        m_AIWPCreatures[aiwp->entry] = pSummon;
    }

    return false;
}

bool AIWaypointsMgr::CreateAIWPCreature(Player* player)
{
    if (!player)
        return false;

    float x = player->GetPositionX();
    float y = player->GetPositionY();
    float z = player->GetPositionZ();
    float o = player->GetOrientation();
    z += 0.01f;
    AIWaypoint* aiwp = AddNewWaypoint(player->GetMap()->GetId(), x, y, z);
    if (!aiwp)
        return false;
    TempSummon* pSummon = player->SummonCreature(AIWP_CREATURE_ENTRY, x, y, z, o);
    m_AIWPCreatures[aiwp->entry] = pSummon;
    return true;
}

bool AIWaypointsMgr::DeleteAIWPCreature(Creature* pCreature)
{
    if (!pCreature)
        return false;

    for (AIWPCreatures::iterator itCreature = m_AIWPCreatures.begin();
        itCreature != m_AIWPCreatures.end();
        itCreature++)
    {
        TempSummon* pSummon = itCreature->second;
        if (pSummon->GetGUID() != pCreature->GetGUID())
            continue;

        DeleteWaypoint(itCreature->first);
        m_AIWPCreatures.erase(itCreature);
        pCreature->CombatStop();
        pCreature->AddObjectToRemoveList();
        return true;
    }

    return false;
}

bool AIWaypointsMgr::MoveAIWPCreature(Player* player, Creature* pCreature)
{
    if (!player || !pCreature)
        return false;
    MotionMaster* pMotion = pCreature->GetMotionMaster();
    if (!pMotion)
        return false;

    float x = player->GetPositionX();
    float y = player->GetPositionY();
    float z = player->GetPositionZ();
    //float o = player->GetOrientation();
    z += 0.01f;
    for (AIWPCreatures::iterator itCreature = m_AIWPCreatures.begin();
        itCreature != m_AIWPCreatures.end();
        itCreature++)
    {
        TempSummon* pSummon = itCreature->second;
        if (pSummon->GetGUID() != pCreature->GetGUID())
            continue;

        MovementWaypoint(itCreature->first, x, y, z);
        pMotion->MovePoint(0, x, y, z);
        return true;
    }

    return false;
}

bool AIWaypointsMgr::AIWPCreatureDesc(Creature* pCreature, std::string descStr)
{
    if (!pCreature)
        return false;

    for (AIWPCreatures::iterator itCreature = m_AIWPCreatures.begin();
        itCreature != m_AIWPCreatures.end();
        itCreature++)
    {
        TempSummon* pSummon = itCreature->second;
        if (pSummon->GetGUID() != pCreature->GetGUID())
            continue;

        return WaypointDesc(itCreature->first, descStr);
    }

    return false;
}
