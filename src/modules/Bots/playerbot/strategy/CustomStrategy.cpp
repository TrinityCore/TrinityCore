#include "../../botpch.h"
#include "../playerbot.h"
#include "CustomStrategy.h"
#include <regex>

using namespace ai;

map<string, string> CustomStrategy::actionLinesCache;

NextAction* toNextAction(string action)
{
    vector<string> tokens = split(action, '!');
    if (tokens.size() == 2 && !tokens[0].empty())
        return new NextAction(tokens[0], atof(tokens[1].c_str()));
    else if (tokens.size() == 1 && !tokens[0].empty())
        return new NextAction(tokens[0], ACTION_NORMAL);

    sLog.outError("Invalid action '%s'", action);
    return NULL;
}

NextAction** toNextActionArray(string actions)
{
    vector<string> tokens = split(actions, ',');
    NextAction** res = new NextAction*[tokens.size() + 1];
    int index = 0;
    for (vector<string>::iterator i = tokens.begin(); i != tokens.end(); ++i)
    {
        NextAction* na = toNextAction(*i);
        if (na)
            res[index++] = na;
    }
	res[index++] = NULL;
    return res;
}

TriggerNode* toTriggerNode(string actionLine)
{
    vector<string> tokens = split(actionLine, '>');
    if (tokens.size() == 2)
        return new TriggerNode(tokens[0], toNextActionArray(tokens[1]));

    sLog.outError("Invalid action line '%s'", actionLine);
    return NULL;
}

void CustomStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    if (actionLines.empty())
    {
        if (actionLinesCache[qualifier].empty())
        {
            LoadActionLines((uint32)ai->GetBot()->GetGUIDLow());
            if (this->actionLines.empty())
                LoadActionLines(0);
        }
        else
        {
            vector<string> tokens = split(actionLinesCache[qualifier], '\n');
            regex tpl("\\(NULL,\\s*'.+',\\s*'(.+)'\\)(,|;)");
            for (vector<string>::iterator i = tokens.begin(); i != tokens.end(); ++i)
            {
                string line = *i;
                for (sregex_iterator j = sregex_iterator(line.begin(), line.end(), tpl); j != sregex_iterator(); ++j)
                {
                    smatch match = *j;
                    string actionLine = match[1].str();
                    if (!actionLine.empty())
                        this->actionLines.push_back(actionLine);
                }
            }
        }
    }

    for (list<string>::iterator i = actionLines.begin(); i != actionLines.end(); ++i)
    {
        TriggerNode* tn = toTriggerNode(*i);
        if (tn)
            triggers.push_back(tn);
    }
}

void CustomStrategy::LoadActionLines(uint32 owner)
{
    QueryResult* results = PlayerbotDatabase.PQuery("SELECT action_line FROM ai_playerbot_custom_strategy WHERE name = '%s' and owner = '%u' order by idx",
            qualifier.c_str(), owner);
    if (results)
    {
        do
        {
            Field* fields = results->Fetch();
            string action = fields[0].GetString();
            this->actionLines.push_back(action);
        } while (results->NextRow());

        delete results;
    }
}

void CustomStrategy::Reset()
{
    actionLines.clear();
    actionLinesCache[qualifier].clear();
}

CustomStrategy::CustomStrategy(PlayerbotAI* ai) : Strategy(ai), Qualified()
{
}
