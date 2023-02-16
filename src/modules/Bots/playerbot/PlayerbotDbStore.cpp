#include "../botpch.h"
#include "playerbot.h"
#include "PlayerbotAIConfig.h"
#include "PlayerbotFactory.h"
#include "PlayerbotDbStore.h"
#include <cstdlib>
#include <iostream>

#include "LootObjectStack.h"
#include "strategy/values/Formations.h"
#include "strategy/values/PositionValue.h"
INSTANTIATE_SINGLETON_1(PlayerbotDbStore);

using namespace std;
using namespace ai;

void PlayerbotDbStore::Load(PlayerbotAI *ai)
{
    uint64 guid = ai->GetBot()->GetObjectGuid().GetRawValue();
    uint32 account = sObjectMgr.GetPlayerAccountIdByGUID(ObjectGuid(guid));
    if (sPlayerbotAIConfig.IsInRandomAccountList(account))
        return;

    QueryResult* results = PlayerbotDatabase.PQuery("SELECT `key`,`value` FROM `ai_playerbot_db_store` WHERE `guid` = '%u'", guid);
    if (results)
    {
        ai->ClearStrategies(BOT_STATE_COMBAT);
        ai->ClearStrategies(BOT_STATE_NON_COMBAT);
        ai->ChangeStrategy("+chat", BOT_STATE_COMBAT);
        ai->ChangeStrategy("+chat", BOT_STATE_NON_COMBAT);

        do
        {
            Field* fields = results->Fetch();
            string key = fields[0].GetString();
            string value = fields[1].GetString();
            ExternalEventHelper helper(ai->GetAiObjectContext());
            helper.ParseChatCommand(value, ai->GetMaster());
            ai->DoNextAction();
        } while (results->NextRow());

        delete results;
    }
}

void PlayerbotDbStore::Save(PlayerbotAI *ai)
{
    uint64 guid = ai->GetBot()->GetObjectGuid().GetRawValue();
    uint32 account = sObjectMgr.GetPlayerAccountIdByGUID(ObjectGuid(guid));
    if (sPlayerbotAIConfig.IsInRandomAccountList(account))
        return;

    Reset(ai);

    SaveValue(guid, "co", FormatStrategies("co", ai->GetStrategies(BOT_STATE_COMBAT)));
    SaveValue(guid, "nc", FormatStrategies("nc", ai->GetStrategies(BOT_STATE_NON_COMBAT)));
    SaveValue(guid, "dead", FormatStrategies("dead", ai->GetStrategies(BOT_STATE_DEAD)));

    Value<Formation*>* formation = ai->GetAiObjectContext()->GetValue<Formation*>("formation");
    ostringstream outFormation; outFormation << "formation " << formation->Get()->getName();
    SaveValue(guid, "formation", outFormation.str());

    Value<LootStrategy*>* lootStrategy = ai->GetAiObjectContext()->GetValue<LootStrategy*>("loot strategy");
    ostringstream outLoot; outLoot << "ll " << lootStrategy->Get()->GetName();
    SaveValue(guid, "ll", outLoot.str());

    list<string>& outfits = ai->GetAiObjectContext()->GetValue<list<string>&>("outfit list")->Get();
    for (list<string>::iterator i = outfits.begin(); i != outfits.end(); ++i)
    {
        ostringstream outOutfit; outOutfit << "outfit " << *i;
        SaveValue(guid, "outfit", outOutfit.str());
    }

    set<uint32>& ss = ai->GetAiObjectContext()->GetValue<set<uint32>&>("skip spells list")->Get();
    ostringstream outSs;
    outSs << "ss ";
    bool first = true;
    for (set<uint32>::iterator i = ss.begin(); i != ss.end(); ++i)
    {
        if (first) first = false; else outSs << ",";
        outSs << *i;
    }
    SaveValue(guid, "ss", outSs.str());

    uint32 saveMana = (uint32)round(ai->GetAiObjectContext()->GetValue<double>("mana save level")->Get());
    ostringstream outSaveMana; outSaveMana << "save mana " << saveMana;
    SaveValue(guid, "save mana", outSaveMana.str());

    ai::PositionMap& posMap = ai->GetAiObjectContext()->GetValue<ai::PositionMap&>("position")->Get();
    for (ai::PositionMap::iterator i = posMap.begin(); i != posMap.end(); ++i)
    {
        ai::Position pos = i->second;
        if (pos.isSet())
        {
            ostringstream out; out << "position " << i->first << " " << pos.x << "," << pos.y << "," << pos.z;
            SaveValue(guid, "position", out.str());
        }
    }
}

string PlayerbotDbStore::FormatStrategies(string type, list<string> strategies)
{
    ostringstream out;
    out << type << " ";
    for(list<string>::iterator i = strategies.begin(); i != strategies.end(); ++i)
        out << "+" << (*i).c_str() << ",";

	string res = out.str();
    return res.substr(0, res.size() - 1);
}

void PlayerbotDbStore::Reset(PlayerbotAI *ai)
{
    uint64 guid = ai->GetBot()->GetObjectGuid().GetRawValue();
    uint32 account = sObjectMgr.GetPlayerAccountIdByGUID(ObjectGuid(guid));
    if (sPlayerbotAIConfig.IsInRandomAccountList(account))
        return;

    PlayerbotDatabase.PExecute("DELETE FROM `ai_playerbot_db_store` WHERE `guid` = '%u'", guid);
}

void PlayerbotDbStore::SaveValue(uint64 guid, string key, string value)
{
    PlayerbotDatabase.PExecute("INSERT INTO `ai_playerbot_db_store` (`guid`, `key`, `value`) VALUES ('%u', '%s', '%s')", guid, key.c_str(), value.c_str());
}
