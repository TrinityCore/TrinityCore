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

    QueryResult eiQR = WorldDatabase.PQuery("SELECT expansion, item_entry, stack FROM joker_item_expansion");
    if (eiQR)
    {
        do
        {
            Field* fields = eiQR->Fetch();
            uint32 eachExpansion = fields[0].GetUInt32();
            uint32 eachItemEntry = fields[1].GetUInt32();
            uint32 eachItemStack = fields[2].GetUInt32();
            expansionItemMap[eachExpansion].insert(eachItemEntry);
            classicItemStackMap[eachItemEntry] = eachItemStack;
        } while (eiQR->NextRow());
    }

    // EJ instance_encounters and unique elite and raid elite
    ieSet.clear();
    ueSet.clear();
    reSet.clear();
    QueryResult ieQR = WorldDatabase.Query("SELECT creditEntry FROM instance_encounters");
    if (ieQR)
    {
        do
        {
            Field* ieField = ieQR->Fetch();
            uint32 eachEntry = ieField[0].GetUInt32();
            ieSet.insert(eachEntry);
        } while (ieQR->NextRow());
    }
    QueryResult ueQR = WorldDatabase.Query("SELECT id, count(*) cc FROM creature where id in (SELECT entry FROM creature_template where rank = 1) group by id");
    if (ueQR)
    {
        do
        {
            Field* ueField = ueQR->Fetch();
            uint32 eachEntry = ueField[0].GetUInt32();
            uint32 eachCount = ueField[1].GetUInt32();
            if (eachCount == 1)
            {
                ueSet.insert(eachEntry);
            }
        } while (ueQR->NextRow());
    }
    QueryResult reQR = WorldDatabase.Query("SELECT distinct id FROM world_trinity_core.creature where map = 409");
    if (reQR)
    {
        do
        {
            Field* reField = reQR->Fetch();
            uint32 eachEntry = reField[0].GetUInt32();
            reSet.insert(eachEntry);
        } while (reQR->NextRow());
    }
    reSet.insert(11663);
    reSet.insert(11664);
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
