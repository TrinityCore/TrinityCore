#include "../../pchdef.h"
#include "../playerbot.h"
#include "CustomStrategy.h"
#include <regex>

using namespace ai;

map<string, string> CustomStrategy::actionLinesCache;

NextAction* toNextAction(string action)
{
    vector<string> tokens = split(action, '|');
    if (tokens.size() == 2)
        return new NextAction(tokens[0], atof(tokens[1].c_str()));
    else if (tokens.size() == 1)
        return new NextAction(tokens[0], ACTION_NORMAL);

    sLog->outMessage("playerbot", LOG_LEVEL_ERROR, "Invalid action '%s'", action);
    return NULL;
}

NextAction** toNextActionArray(string actions)
{
    vector<string> tokens = split(actions, ',');
    NextAction** res = new NextAction*[tokens.size() + 1];
    int index = 0;
    for (vector<string>::iterator i = tokens.begin(); i != tokens.end(); ++i)
    {
        res[index++] = toNextAction(*i);
    }
	res[index++] = NULL;
    return res;
}

TriggerNode* toTriggerNode(string actionLine)
{
    vector<string> tokens = split(actionLine, '>');
    if (tokens.size() == 2)
        return new TriggerNode(tokens[0], toNextActionArray(tokens[1]));

    sLog->outMessage("playerbot", LOG_LEVEL_ERROR, "Invalid action line '%s'", actionLine);
    return NULL;
}

void CustomStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
    if (actionLines.empty())
    {
        if (actionLinesCache[qualifier].empty())
        {
            QueryResult results = CharacterDatabase.PQuery("SELECT action_line FROM ai_playerbot_custom_strategy WHERE name = '%s'", qualifier.c_str());
            if (results)
            {
                do
                {
                    Field* fields = results->Fetch();
                    string action = fields[0].GetCString();
                    this->actionLines.push_back(action);
                } while (results->NextRow());
            }
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
        triggers.push_back(toTriggerNode(*i));
}

CustomStrategy::CustomStrategy(PlayerbotAI* ai) : Strategy(ai), Qualified()
{
}