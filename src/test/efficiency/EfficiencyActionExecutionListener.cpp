#include "pch.h"
#include "../aitest.h"
#include "../EngineTestBase.h"
#include "../MockedTargets.h"
#include "../AiObjectContextWrapper.h"
#include "EfficiencyActionExecutionListener.h"


EfficiencyActionExecutionListener::EfficiencyActionExecutionListener(MockPlayerbotAIBase *ai, map<string, SpellInfo> spellInfo, double mana) :
    ai(ai), spellInfo(spellInfo), mana(mana), castTime(0), damage(0), fullMana(mana), log("")
{
}

bool EfficiencyActionExecutionListener::Before(Action* action, Event event)
{
    return true;
}

bool EfficiencyActionExecutionListener::AllowExecution(Action* action, Event event)
{
    return false;
}

bool EfficiencyActionExecutionListener::OverrideResult(Action* action, bool executed, Event event)
{
    if (!executed)
        return false;

    string name = action->getName();
    if (!spellInfo.count(name))
        return false;

    SpellInfo spell = spellInfo[name];

    string sharedCooldown = spell.sharedCooldown.empty() ? name : spell.sharedCooldown;
    if (cooldown.count(sharedCooldown) && cooldown[sharedCooldown] > 0)
        return false;

    if (mana < spell.mana)
        return false;

    return true;
}

void EfficiencyActionExecutionListener::After(Action* action, bool executed, Event event)
{
    string name = action->getName();
    if (!spellInfo.count(name))
        return;

    SpellInfo spell = spellInfo[name];

    double elapsed = max(executed ? 1.5 : 0.1, spell.castTime);
    for (map<string, double>::iterator i = cooldown.begin(); i != cooldown.end(); ++i)
    {
        int value = i->second - elapsed;
        string sharedCooldown = spell.sharedCooldown.empty() ? i->first : spell.sharedCooldown;
        cooldown[sharedCooldown] = value > 0 ? value : 0;
    }

    castTime += elapsed;

    if (!executed)
        return;

    mana -= spell.mana;
    string sharedCooldown = spell.sharedCooldown.empty() ? name : spell.sharedCooldown;
    cooldown[sharedCooldown] = spell.cooldown;
    damage += spell.damage;
    if (!log.empty())
        log += ",";
    log += name;
}

void EfficiencyActionExecutionListener::Report()
{
    cout << endl << log << endl <<
            "Time: " << castTime << endl <<
            "Damage: " << damage << endl <<
            "Mana: " << mana << endl;
    if (damage > 0 && castTime > 0)
        cout << "DPS: " << damage / castTime << endl;
}

bool EfficiencyActionExecutionListener::CanContinue()
{
    return castTime < 60 && mana > fullMana / 10;
}
