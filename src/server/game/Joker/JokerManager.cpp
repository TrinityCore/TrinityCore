#include "JokerManager.h"

JokerManager::JokerManager()
{
    updateDelay = JOKER_MANAGER_SAVE_GAP;
    accompanyTimeMap.clear();
    petLoyaltyLevelMap.clear();
    classicBookSpellSet.clear();

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

    classicBookSpellSet.insert(25286);
    classicBookSpellSet.insert(25288);
    classicBookSpellSet.insert(25289);
    classicBookSpellSet.insert(25290);
    classicBookSpellSet.insert(25291);
    classicBookSpellSet.insert(25292);
    classicBookSpellSet.insert(25290);
    classicBookSpellSet.insert(25291);
    classicBookSpellSet.insert(25292);
    classicBookSpellSet.insert(25290);
    classicBookSpellSet.insert(25291);
    classicBookSpellSet.insert(25292);
    classicBookSpellSet.insert(19801);
    classicBookSpellSet.insert(25294);
    classicBookSpellSet.insert(25295);
    classicBookSpellSet.insert(25296);
    classicBookSpellSet.insert(25300);
    classicBookSpellSet.insert(25302);
    classicBookSpellSet.insert(31016);
    classicBookSpellSet.insert(21564);
    classicBookSpellSet.insert(25314);
    classicBookSpellSet.insert(25315);
    classicBookSpellSet.insert(25316);
    classicBookSpellSet.insert(25392);
    classicBookSpellSet.insert(27683);
    classicBookSpellSet.insert(39374);
    classicBookSpellSet.insert(25357);
    classicBookSpellSet.insert(25361);
    classicBookSpellSet.insert(29228);
    classicBookSpellSet.insert(23028);
    classicBookSpellSet.insert(25304);
    classicBookSpellSet.insert(25306);
    classicBookSpellSet.insert(25345);
    classicBookSpellSet.insert(27090);
    classicBookSpellSet.insert(27127);
    classicBookSpellSet.insert(28609);
    classicBookSpellSet.insert(28612);
    classicBookSpellSet.insert(33717);
    classicBookSpellSet.insert(21849);
    classicBookSpellSet.insert(21850);
    classicBookSpellSet.insert(25297);
    classicBookSpellSet.insert(25298);
    classicBookSpellSet.insert(25299);
    classicBookSpellSet.insert(26991);
    classicBookSpellSet.insert(31018);
    classicBookSpellSet.insert(31709);
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
