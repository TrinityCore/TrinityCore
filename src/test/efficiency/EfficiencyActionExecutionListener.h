#pragma once

#include "../../plugins/playerbot/strategy/Action.h"
#include "../../plugins/playerbot/strategy/ActionBasket.h"
#include "../../plugins/playerbot/strategy/Queue.h"
#include "../../plugins/playerbot/strategy/Trigger.h"
#include "../../plugins/playerbot/strategy/Engine.h"

#include "../MockPlayerbotAIBase.h"

using namespace ai;

class SpellInfo
{
public:
    SpellInfo() : mana(0), castTime(0), cooldown(0), damage(0) {}
    SpellInfo(double mana, double castTime, double cooldown, double damage, string sharedCooldown = "") :
        mana(mana), castTime(castTime), cooldown(cooldown), damage(damage), sharedCooldown(sharedCooldown) {}
    SpellInfo(SpellInfo const& other)
    {
        mana = other.mana;
        castTime = other.castTime;
        cooldown = other.cooldown;
        damage = other.damage;
        sharedCooldown = other.sharedCooldown;
    }
    virtual ~SpellInfo() {}

    double mana, castTime, cooldown, damage;
    string sharedCooldown;
};

class EfficiencyActionExecutionListener : public ActionExecutionListener
{
public:
    EfficiencyActionExecutionListener(MockPlayerbotAIBase *ai, map<string, SpellInfo> spellInfo, double mana);

    virtual bool Before(Action* action, Event event);
    virtual bool AllowExecution(Action* action, Event event);
    virtual bool OverrideResult(Action* action, bool executed, Event event);
    virtual void After(Action* action, bool executed, Event event);
    void Report();
    bool CanContinue();

private:
    map<string, SpellInfo> spellInfo;
    map<string, double> cooldown;
    double mana, castTime, damage, fullMana;
    MockPlayerbotAIBase *ai;
    string log;
};

