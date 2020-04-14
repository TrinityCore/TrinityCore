#include "JokerManager.h"

JokerManager::JokerManager()
{
    updateDelay = JOKER_MANAGER_SAVE_GAP;
    accompanyTimeMap.clear();
    petLoyaltyLevelMap.clear();

    if (!sJokerConfig->Enable)
    {
        return;
    }

    for (int checkLevel = 0; checkLevel <= MAX_PET_LOYALTY_LEVEL; checkLevel++)
    {
        petLoyaltyLevelMap[checkLevel] = 7200000 * checkLevel;
    }

    QueryResult jhpQR = CharacterDatabase.Query("SELECT pet_guid, accompany_time FROM joker_hunter_pet");
    if (jhpQR)
    {
        do
        {
            Field* jhpField = jhpQR->Fetch();
            uint32 pet_guid = jhpField[0].GetUInt32();
            uint32 accompany_time = jhpField[1].GetUInt32();
            accompanyTimeMap[pet_guid] = accompany_time;
        } while (jhpQR->NextRow());
    }

    expansionCreatureMap.clear();
    QueryResult jcQR = WorldDatabase.Query("SELECT creature_entry, creature_faction, expansion FROM joker_creature_expansion");
    if (jcQR)
    {
        do
        {
            Field* fields = jcQR->Fetch();
            uint32 eachEntry = fields[0].GetUInt32();
            uint32 eachFaction = fields[1].GetUInt32();
            uint32 eachExpansion = fields[2].GetUInt32();
            expansionCreatureMap[eachExpansion][eachEntry] = eachFaction;
        } while (jcQR->NextRow());
    }

    expansionQuestMap.clear();
    QueryResult jqQR = WorldDatabase.Query("SELECT quest_id, expansion FROM joker_quest_expansion");
    if (jqQR)
    {
        do
        {
            Field* fields = jqQR->Fetch();
            uint32 eachID = fields[0].GetUInt32();
            uint32 eachExpansion = fields[1].GetUInt32();
            expansionQuestMap[eachExpansion].insert(eachID);
        } while (jqQR->NextRow());
    }
}

void JokerManager::UpdateJoker(uint32 pmDiff)
{
    if (!sJokerConfig->Enable)
    {
        return;
    }
    updateDelay -= pmDiff;
    if (updateDelay < 0)
    {
        updateDelay = JOKER_MANAGER_SAVE_GAP;

        std::unordered_set<uint32> currentPetGUIDSet;
        currentPetGUIDSet.clear();
        QueryResult jhpQR = CharacterDatabase.Query("SELECT pet_guid FROM joker_hunter_pet");
        if (jhpQR)
        {
            do
            {
                Field* jhpField = jhpQR->Fetch();
                uint32 pet_guid = jhpField[0].GetUInt32();
                currentPetGUIDSet.insert(pet_guid);
            } while (jhpQR->NextRow());
        }
        
        for (std::unordered_map<uint32, uint32>::iterator it = accompanyTimeMap.begin(); it != accompanyTimeMap.end(); it++)
        {
            std::ostringstream sqlStream;
            if (currentPetGUIDSet.find(it->first) == currentPetGUIDSet.end())
            {
                sqlStream << "INSERT INTO joker_hunter_pet (pet_guid, accompany_time) VALUES (" << it->first << ", " << it->second << ");";
            }
            else
            {
                sqlStream << "update joker_hunter_pet set accompany_time = " << it->second << " where pet_guid = " << it->first << ";";
            }
            std::string sql = sqlStream.str();
            CharacterDatabase.Execute(sql.c_str());
        }        
    }
}

JokerManager* JokerManager::instance()
{
    static JokerManager instance;
    return &instance;
}
