#include "../botpch.h"
#include "playerbot.h"
#include "PlayerbotAIConfig.h"
#include "PlayerbotTextMgr.h"

#include "DatabaseEnv.h"
#include "PlayerbotAI.h"

void replaceAll(std::string& str, const std::string& from, const std::string& to);

PlayerbotTextMgr::PlayerbotTextMgr()
{
}

PlayerbotTextMgr::~PlayerbotTextMgr()
{
}

void PlayerbotTextMgr::LoadTemplates()
{
    sLog.outBasic("Loading playerbot texts...");
    QueryResult* results = PlayerbotDatabase.PQuery("SELECT `key`,`text` FROM `ai_playerbot_text`");
    int count = 0;
    if (results)
    {
        do
        {
            Field* fields = results->Fetch();
            string key = fields[0].GetString();
            string text = fields[1].GetString();
            templates[key].push_back(text);
            count++;
        } while (results->NextRow());

        delete results;
    }
    sLog.outBasic("%d playerbot texts loaded", count);
}

string PlayerbotTextMgr::Format(string key, map<string, string> placeholders)
{
    if (templates.empty()) LoadTemplates();
    vector<string>& list = templates[key];
    if (list.empty())
    {
        ostringstream out; out << "Unknown text: " << key;
        return out.str();
    }

    string str = list[urand(0, list.size() - 1)];
    for (map<string, string>::iterator i = placeholders.begin(); i != placeholders.end(); ++i)
        replaceAll(str, i->first, i->second);
    return str;
}
