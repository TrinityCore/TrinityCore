#include "botpch.h"
#include "../../playerbot.h"
#include "ReadyCheckAction.h"
#include "../../PlayerbotAIConfig.h"

using namespace ai;
#include "botpch.h"
#include "../../playerbot.h"
#include "ReadyCheckAction.h"
#include "../../PlayerbotAIConfig.h"

using namespace ai;

string formatPercent(string name, uint8 value, float percent)
{
    ostringstream out;

    string color;
    if (percent > 75)
        color = "|cff00ff00";
    else if (percent > 50)
        color = "|cffffff00";
    else
        color = "|cffff0000";

    out << "|cffffffff[" << name << "]" << color << "x" << (int)value;
    return out.str();
}

class ReadyChecker
{
public:
    virtual bool Check(PlayerbotAI *ai, AiObjectContext* context) = 0;
    virtual string GetName() = 0;
    virtual bool PrintAlways() { return true; }

    static list<ReadyChecker*> checkers;
};

list<ReadyChecker*> ReadyChecker::checkers;

class HealthChecker : public ReadyChecker
{
public:
    virtual bool Check(PlayerbotAI *ai, AiObjectContext* context)
    {
        return AI_VALUE2(uint8, "health", "self target") > sPlayerbotAIConfig.almostFullHealth;
    }
    virtual string GetName() { return "HP"; }
};

class ManaChecker : public ReadyChecker
{
public:
    virtual bool Check(PlayerbotAI *ai, AiObjectContext* context)
    {
        return !AI_VALUE2(bool, "has mana", "self target") || AI_VALUE2(uint8, "mana", "self target") > sPlayerbotAIConfig.mediumHealth;
    }
    virtual string GetName() { return "MP"; }
};

class DistanceChecker : public ReadyChecker
{
public:
    virtual bool Check(PlayerbotAI *ai, AiObjectContext* context)
    {
        Player* bot = ai->GetBot();
        Player* master = ai->GetMaster();
        if (master)
        {
            bool distance = bot->GetDistance(master) <= sPlayerbotAIConfig.sightDistance;
            if (!distance)
            {
                return false;
            }
        }
        return true;
    }
    virtual bool PrintAlways() { return false; }
    virtual string GetName() { return "Far away"; }
};

class HunterChecker : public ReadyChecker
{
public:
    virtual bool Check(PlayerbotAI *ai, AiObjectContext* context)
    {
        Player* bot = ai->GetBot();
        if (bot->getClass() == CLASS_HUNTER)
        {
            if (!bot->GetUInt32Value(PLAYER_AMMO_ID))
            {
                ai->TellMaster("Out of ammo!");
                return false;
            }

            if (!bot->GetPet())
            {
                ai->TellMaster("No pet!");
                return false;
            }

            if (bot->GetPet()->GetHappinessState() == UNHAPPY)
            {
                ai->TellMaster("Pet is unhappy!");
                return false;
            }
        }
        return true;
    }
    virtual bool PrintAlways() { return false; }
    virtual string GetName() { return "Far away"; }
};


class ItemCountChecker : public ReadyChecker
{
public:
    ItemCountChecker(string item, string name) { this->item = item; this->name = name; }

    virtual bool Check(PlayerbotAI *ai, AiObjectContext* context)
    {
        return AI_VALUE2(uint8, "item count", item) > 0;
    }
    virtual string GetName() { return name; }

private:
    string item, name;
};

class ManaPotionChecker : public ItemCountChecker
{
public:
    ManaPotionChecker(string item, string name) : ItemCountChecker(item, name) {}

    virtual bool Check(PlayerbotAI *ai, AiObjectContext* context)
    {
        return !AI_VALUE2(bool, "has mana", "self target") || ItemCountChecker::Check(ai, context);
    }
};

bool ReadyCheckAction::Execute(Event event)
{
    WorldPacket &p = event.getPacket();
    ObjectGuid player;
    p.rpos(0);
    if (!p.empty())
    {
        p >> player;
        if (player == bot->GetObjectGuid())
            return false;
    }

	return ReadyCheck();
}

bool ReadyCheckAction::ReadyCheck()
{
    if (ReadyChecker::checkers.empty())
    {
        ReadyChecker::checkers.push_back(new HealthChecker());
        ReadyChecker::checkers.push_back(new ManaChecker());
        ReadyChecker::checkers.push_back(new DistanceChecker());
        ReadyChecker::checkers.push_back(new HunterChecker());

        ReadyChecker::checkers.push_back(new ItemCountChecker("food", "Food"));
        ReadyChecker::checkers.push_back(new ManaPotionChecker("drink", "Water"));
        ReadyChecker::checkers.push_back(new ItemCountChecker("healing potion", "Hpot"));
        ReadyChecker::checkers.push_back(new ManaPotionChecker("mana potion", "Mpot"));
    }

    bool result = true;
    for (list<ReadyChecker*>::iterator i = ReadyChecker::checkers.begin(); i != ReadyChecker::checkers.end(); ++i)
    {
        ReadyChecker* checker = *i;
        bool ok = checker->Check(ai, context);
        result = result && ok;
    }

    ostringstream out;

    uint8 hp = AI_VALUE2(uint8, "item count", "healing potion");
    out << formatPercent("Hp", hp, 100.0 * hp / 5);

    out << ", ";
    uint8 food = AI_VALUE2(uint8, "item count", "food");
    out << formatPercent("Food", food, 100.0 * food / 20);

    if (AI_VALUE2(bool, "has mana", "self target"))
    {
        out << ", ";
        uint8 mp = AI_VALUE2(uint8, "item count", "mana potion");
        out << formatPercent("Mp", mp, 100.0 * mp / 5);

        out << ", ";
        uint8 water = AI_VALUE2(uint8, "item count", "water");
        out << formatPercent("Water", water, 100.0 * water / 20);
    }

    ai->TellMaster(out);

    WorldPacket packet(MSG_RAID_READY_CHECK);
    packet << bot->GetObjectGuid();
    packet << uint8(1);
    bot->GetSession()->HandleRaidReadyCheckOpcode(packet);

    ai->ChangeStrategy("-ready check", BOT_STATE_NON_COMBAT);

    return true;
}

bool FinishReadyCheckAction::Execute(Event event)
{
    return ReadyCheck();
}
