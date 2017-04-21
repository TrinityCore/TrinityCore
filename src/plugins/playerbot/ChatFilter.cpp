#include "../pchdef.h"
#include "playerbot.h"
#include "ChatFilter.h"
#include "strategy/values/RtiTargetValue.h"

using namespace ai;
using namespace std;

string ChatFilter::Filter(string message)
{
    if (message.find("@") == string::npos)
        return message;

    return message.substr(message.find(" ") + 1);
}

class StrategyChatFilter : public ChatFilter
{
public:
    StrategyChatFilter(PlayerbotAI* ai) : ChatFilter(ai) {}

    virtual string Filter(string message)
    {
        Player* bot = ai->GetBot();

        bool tank = message.find("@tank") == 0;
        if (tank && !ai->IsTank(bot))
            return "";

        bool dps = message.find("@dps") == 0;
        if (dps && ai->IsTank(bot))
            return "";

        bool heal = message.find("@heal") == 0;
        if (heal && !ai->IsHeal(bot))
            return "";

        if (tank || dps)
            return ChatFilter::Filter(message);

        return message;
    }
};

class LevelChatFilter : public ChatFilter
{
public:
    LevelChatFilter(PlayerbotAI* ai) : ChatFilter(ai) {}

    virtual string Filter(string message)
    {
        Player* bot = ai->GetBot();

        if (message[0] != '@')
            return message;

        if (message.find("-") != string::npos)
        {
            int fromLevel = atoi(message.substr(message.find("@") + 1, message.find("-")).c_str());
            int toLevel = atoi(message.substr(message.find("-") + 1, message.find(" ")).c_str());

            if (bot->getLevel() >= fromLevel && bot->getLevel() <= toLevel)
                return ChatFilter::Filter(message);

            return message;
        }

		int level = atoi(message.substr(message.find("@") + 1, message.find(" ")).c_str());
        if (bot->getLevel() == level)
            return ChatFilter::Filter(message);

        return message;
    }
};

class CombatTypeChatFilter : public ChatFilter
{
public:
    CombatTypeChatFilter(PlayerbotAI* ai) : ChatFilter(ai) {}

    virtual string Filter(string message)
    {
        Player* bot = ai->GetBot();

        bool melee = message.find("@melee") == 0;
        bool ranged = message.find("@ranged") == 0;

        if (!melee && !ranged)
            return message;

        switch (bot->getClass())
        {
            case CLASS_WARRIOR:
            case CLASS_PALADIN:
            case CLASS_ROGUE:
            case CLASS_DEATH_KNIGHT:
                if (ranged)
                    return "";
                break;

            case CLASS_HUNTER:
            case CLASS_PRIEST:
            case CLASS_MAGE:
            case CLASS_WARLOCK:
                if (melee)
                    return "";
                break;

            case CLASS_DRUID:
                if (ranged && ai->IsTank(bot))
                    return "";
                if (melee && !ai->IsTank(bot))
                    return "";
                break;

            case CLASS_SHAMAN:
                if (melee && ai->IsHeal(bot))
                    return "";
                if (ranged && !ai->IsHeal(bot))
                    return "";
                break;
        }

        return ChatFilter::Filter(message);
    }
};

class RtiChatFilter : public ChatFilter
{
public:
    RtiChatFilter(PlayerbotAI* ai) : ChatFilter(ai)
    {
        rtis.push_back("@star");
        rtis.push_back("@circle");
        rtis.push_back("@diamond");
        rtis.push_back("@triangle");
        rtis.push_back("@moon");
        rtis.push_back("@square");
        rtis.push_back("@cross");
        rtis.push_back("@skull");
    }

    virtual string Filter(string message)
    {
        Player* bot = ai->GetBot();
        Group *group = bot->GetGroup();
        if(!group)
            return message;

        bool found = false;
        for (list<string>::iterator i = rtis.begin(); i != rtis.end(); i++)
        {
            string rti = *i;

            bool isRti = message.find(rti) == 0;
            if (!isRti)
                continue;

            ObjectGuid rtiTarget = group->GetTargetIcon(RtiTargetValue::GetRtiIndex(rti.substr(1)));
            if (bot->GetGUID() == rtiTarget)
                return ChatFilter::Filter(message);

            Unit* target = *ai->GetAiObjectContext()->GetValue<Unit*>("current target");
            if (!target)
                return "";

            if (target->GetGUID() != rtiTarget)
                return "";

            if (found |= isRti)
                break;
        }

        if (found)
            return ChatFilter::Filter(message);

        return message;
    }

private:
    list<string> rtis;
};

class ClassChatFilter : public ChatFilter
{
public:
    ClassChatFilter(PlayerbotAI* ai) : ChatFilter(ai)
    {
        classNames["@death_knight"] = CLASS_DEATH_KNIGHT;
        classNames["@druid"] = CLASS_DRUID;
        classNames["@hunter"] = CLASS_HUNTER;
        classNames["@mage"] = CLASS_MAGE;
        classNames["@paladin"] = CLASS_PALADIN;
        classNames["@priest"] = CLASS_PRIEST;
        classNames["@rogue"] = CLASS_ROGUE;
        classNames["@shaman"] = CLASS_SHAMAN;
        classNames["@warlock"] = CLASS_WARLOCK;
        classNames["@warrior"] = CLASS_WARRIOR;
    }

    virtual string Filter(string message)
    {
        Player* bot = ai->GetBot();

        bool found = false;
        for (map<string, uint8>::iterator i = classNames.begin(); i != classNames.end(); i++)
        {
            bool isClass = message.find(i->first) == 0;
            if (isClass && bot->getClass() != i->second)
                return "";

            if (found |= isClass)
                break;
        }

        if (found)
            return ChatFilter::Filter(message);

        return message;
    }

private:
    map<string, uint8> classNames;
};



CompositeChatFilter::CompositeChatFilter(PlayerbotAI* ai) : ChatFilter(ai)
{
    filters.push_back(new StrategyChatFilter(ai));
    filters.push_back(new ClassChatFilter(ai));
    filters.push_back(new RtiChatFilter(ai));
    filters.push_back(new CombatTypeChatFilter(ai));
    filters.push_back(new LevelChatFilter(ai));
}

CompositeChatFilter::~CompositeChatFilter()
{
    for (list<ChatFilter*>::iterator i = filters.begin(); i != filters.end(); i++)
        delete (*i);
}

string CompositeChatFilter::Filter(string message)
{
    for (int j = 0; j < filters.size(); ++j)
    {
        for (list<ChatFilter*>::iterator i = filters.begin(); i != filters.end(); i++)
        {
            message = (*i)->Filter(message);
            if (message.empty())
                break;
        }
    }

    return message;
}

