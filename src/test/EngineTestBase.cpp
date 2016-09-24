#include "pch.h"
#include "aitest.h"
#include "EngineTestBase.h"
#include "MockedTargets.h"
#include "AiObjectContextWrapper.h"

class TestActionExecutionListener : public ActionExecutionListener
{
public:
    TestActionExecutionListener(MockPlayerbotAIBase *ai) : ai(ai) {}

    virtual bool Before(Action* action, Event event) { return true; }
    virtual bool AllowExecution(Action* action, Event event) { return false; }
    virtual bool OverrideResult(Action* action, bool executed, Event event) { return executed; }
    virtual void After(Action* action, bool executed, Event event)
    {
        string name = action->getName();

        ai->buffer.append(">");
        MockedTargets::Append(ai->buffer, action->GetTarget());
        ai->buffer.append(":");
        ai->buffer.append(name);

        if (!event.getParam().empty())
        {
            ai->buffer.append("(");
            ai->buffer.append(event.getParam());
            ai->buffer.append(")");
        }

        if (name == "caster form")
        {
            ai->auras[MockedTargets::GetSelf()].remove("dire bear form");
            ai->auras[MockedTargets::GetSelf()].remove("bear form");
            ai->auras[MockedTargets::GetSelf()].remove("cat form");
            ai->auras[MockedTargets::GetSelf()].remove("moonkin form");
            ai->auras[MockedTargets::GetSelf()].remove("travel form");
            ai->auras[MockedTargets::GetSelf()].remove("aquatic form");
        }
        if (name == "remove shadowform")
        {
            ai->auras[MockedTargets::GetSelf()].remove("shadowform");
        }
        if (name == "reach melee" ||
                name == "feral charge - bear" || name == "feral charge - cat" ||
                name == "charge")
        {
            ai->GetAiObjectContext()->GetValue<float>("distance", "current target")->Set(ATTACK_DISTANCE - 1);
        }

        remove(name, " on party");
        remove(name, " on cc");
        remove(name, " on enemy healer");
        if (name.find("cleanse") != string ::npos)
            name = "cleanse";
        if (name.find("purify") != string ::npos)
            name = "purify";

        if (name != "shoot" && name != "auto shot")
            ai->spellCooldowns.push_back(name);
    }

    void remove(string & name, string pattern)
    {
        size_t pos = name.find(pattern);
        if (pos != string ::npos)
            name = name.substr(0, pos);
    }

private:
    MockPlayerbotAIBase *ai;
};


void EngineTestBase::setUp()
{
	ai = new MockPlayerbotAIBase();
}

void EngineTestBase::tearDown()
{
    if (engine)
        delete engine;
    if (ai)
        delete ai;
}

void EngineTestBase::va_generic(void (EngineTestBase::*callback)(const char*), va_list vl)
{
	const char* cur;
	do
	{
		cur = va_arg(vl, const char*);
		if (cur)
			(this->*callback)(cur);
	}
	while (cur);

	va_end(vl);
}


void EngineTestBase::setupEngine(AiObjectContext* aiObjectContext, ...)
{
    context = new AiObjectContextWrapper(ai, aiObjectContext);
    ai->SetContext(context);
    engine = new Engine(ai, context);
	engine->testMode = true;
    engine->AddActionExecutionListener(new TestActionExecutionListener(ai));

	va_list vl;
	va_start(vl, aiObjectContext);

	va_generic(&EngineTestBase::setupEngineCallback, vl);

	engine->Init();
}

void EngineTestBase::setupEngineCallback(const char* name)
{
	engine->addStrategy(name);
}

void EngineTestBase::tick()
{
	engine->DoNextAction(NULL);
}

void EngineTestBase::ticks(int count)
{
    for (int i = 0; i < count; ++i)
    {
        tick();
        ai->buffer.append(",");
    }
}

void EngineTestBase::assertActions(string  expected)
{
	bool pass = ai->buffer == expected;
	if (!pass)
	{
		std::cout << "\n===\n";
		std::cout << "Exp: " << expected << "\n";
		std::cout << "Act: " << ai->buffer << "\n";
		std::cout << "===\n";
	}
    CPPUNIT_ASSERT(pass);
}

void EngineTestBase::tickWithNoTarget()
{
    context->GetValue<Unit*>("current target")->Set(NULL);
    set<uint8>("my attacker count", 0);

	tick();

    set<uint8>("my attacker count", 1);
    context->GetValue<Unit*>("current target")->Set(MockedTargets::GetCurrentTarget());
}

void EngineTestBase::spellUnavailable(string  spell)
{
	ai->spellCooldowns.push_back(spell);
}

void EngineTestBase::tickWithSpellUnavailable(string  spell)
{
	spellUnavailable(spell);
	tick();
}

void EngineTestBase::tickWithSpellAvailable(string  spell)
{
	spellAvailable(spell);
	tick();
}

void EngineTestBase::spellAvailable(string  spell)
{
    list<string > remove;
    for (list<string >::iterator i = ai->spellCooldowns.begin(); i != ai->spellCooldowns.end(); i++)
    {
        if (i->find(spell) != string ::npos) remove.push_back(*i);
    }
    for (list<string >::iterator i = remove.begin(); i != remove.end(); i++)
    {
        ai->spellCooldowns.remove(*i);
    }
}

void EngineTestBase::addAura(string  spell)
{
	ai->auras[MockedTargets::GetSelf()].push_back(spell);
}

void EngineTestBase::removeAura(string  spell)
{
	ai->auras[MockedTargets::GetSelf()].remove(spell);
}

void EngineTestBase::tickOutOfSpellRange()
{
    set<float>("distance", "current target", 49.0f);
    tick();
    set<float>("distance", "current target", 15.0f);
}

void EngineTestBase::tickOutOfMeleeRange()
{
    set<float>("distance", "current target", 15.0f);
    tick();
    set<float>("distance", "current target", ATTACK_DISTANCE - 1);
}

void EngineTestBase::setInMeleeRange()
{
    set<float>("distance", "current target", ATTACK_DISTANCE - 1);
}

void EngineTestBase::tickInMeleeRange()
{
    set<float>("distance", "current target", ATTACK_DISTANCE - 1);
	tick();
}

void EngineTestBase::tickWithNoAggro()
{
    set<bool>("has aggro", "current target", false);
    tick();
    set<bool>("has aggro", "current target", true);
}

void EngineTestBase::tickWithRage(int amount)
{
    set<uint8>("rage", "self target", amount);
    tick();
    set<uint8>("rage", "self target", 0);
}

void EngineTestBase::tickWithEnergy(int amount)
{
    set<uint8>("energy", "self target", amount);
	tick();
    set<uint8>("energy", "self target", 0);
}

void EngineTestBase::tickWithAttackerCount(int count)
{
    set<uint8>("attacker count", count);
	tick();
    set<uint8>("attacker count", 1);
}

void EngineTestBase::tickWithMyAttackerCount(int count)
{
    set<uint8>("my attacker count", count);
	tickWithAttackerCount(count + 1);
    set<uint8>("my attacker count", 1);
}

void EngineTestBase::tickWithLowHealth(int amount)
{
	lowHealth(amount);
	tick();
	healthRestored();
}

void EngineTestBase::tickWithPartyLowHealth(int amount)
{
    set<uint8>("health", "party member to heal", amount);
	tick();
    set<uint8>("health", "party member to heal", 100);
}

void EngineTestBase::tickWithAoeHeal(string type, int amount)
{
    set<uint8>("health", "party member to heal", 45);
	set<uint8>("aoe heal", "medium", amount);
	tick();
	set<uint8>("aoe heal", "medium", 0);
    set<uint8>("health", "party member to heal", 100);
}

void EngineTestBase::tickWithAuraToDispel(uint32 type)
{
	ai->dispels[MockedTargets::GetSelf()] = type;
	tick();
	ai->dispels[MockedTargets::GetSelf()] = 0;
}

void EngineTestBase::tickWithPartyAuraToDispel(uint32 type)
{
	ai->dispels[MockedTargets::GetPartyMember()] = type;
	tick();
	ai->dispels[MockedTargets::GetPartyMember()] = 0;
}

void EngineTestBase::tickWithTargetAuraToDispel(uint32 type)
{
	ai->dispels[MockedTargets::GetCurrentTarget()] = type;
	tick();
	ai->dispels[MockedTargets::GetCurrentTarget()] = 0;
}

void EngineTestBase::lowHealth(int amount)
{
    set<uint8>("health", "self target", amount);
}

void EngineTestBase::lowMana(int amount)
{
    set<uint8>("mana", "self target", amount);
}

void EngineTestBase::healthRestored()
{
    set<uint8>("health", "self target", 100);
}

void EngineTestBase::tickWithComboPoints(int amount)
{
    set<uint8>("combo", "current target", amount);
	tick();
    set<uint8>("combo", "current target", 0);
}

void EngineTestBase::tickWithTargetIsCastingNonMeleeSpell()
{
    ai->targetIsCastingNonMeleeSpell = true;
    tick();
    ai->targetIsCastingNonMeleeSpell = false;
}

void EngineTestBase::tickWithBalancePercent(int percent)
{
    set<uint8>("balance", percent);
	tick();
    set<uint8>("balance", 100);
}

void EngineTestBase::tickWithNoPet()
{
    context->GetValue<Unit*>("pet target")->Set(NULL);
	tick();
    context->GetValue<Unit*>("pet target")->Set(MockedTargets::GetPet());
}

void EngineTestBase::tickWithPetLowHealth(int amount)
{
    set<uint8>("health", "pet target", amount);
	tick();
    set<uint8>("health", "pet target", 100);
}

void EngineTestBase::tickWithPetDead()
{
    set<bool>("dead", "pet target", true);
    tick();
    set<bool>("dead", "pet target", false);
}

void EngineTestBase::tickWithLowMana(int amount)
{
    Value<float>* distance = context->GetValue<float>("distance", "current target");
    float oldDistance = distance->Get();
    distance->Set(5.0f);
    set<uint8>("mana", "self target", amount);
    tick();
    set<uint8>("mana", "self target", 100);
    distance->Set(oldDistance);
}

void EngineTestBase::tickWithTargetLowHealth(int amount)
{
    set<uint8>("health", "current target", amount);
    tick();
    set<uint8>("health", "current target", 100);
}
void EngineTestBase::tickWithTargetIsMoving()
{
    set<bool>("moving", "current target", true);
    tick();
    set<bool>("moving", "current target", false);
}

void EngineTestBase::tickInSpellRange()
{
    set<float>("distance", "current target", 15.0f);
    tick();
}

void EngineTestBase::addTargetAura(string  spell)
{
	ai->auras[MockedTargets::GetCurrentTarget()].push_back(spell);
}

void EngineTestBase::removeTargetAura(string  spell)
{
    ai->auras[MockedTargets::GetCurrentTarget()].remove(spell);
}

void EngineTestBase::addPartyAura(string  spell)
{
    ai->auras[MockedTargets::GetPartyMember()].push_back(spell);
}

void EngineTestBase::removePartyAura(string  spell)
{
    ai->auras[MockedTargets::GetPartyMember()].remove(spell);
}

void EngineTestBase::tickWithLootAvailable()
{
    set<bool>("has available loot", true);
	tick();
    set<bool>("has available loot", false);
}

void EngineTestBase::tickWithNoDrink()
{
    list<Item*> items;
    set<list<Item*> >("inventory items", "drink", items);

	tick();

	items.push_back((Item*)(void*)0x01);
    set<list<Item*> >("inventory items", "drink", items);
}

void EngineTestBase::tickWithNoFood()
{
    list<Item*> items;
    set<list<Item*> >("inventory items", "food", items);

	tick();

	items.push_back((Item*)(void*)0x01);
    set<list<Item*> >("inventory items", "food", items);
}

void EngineTestBase::itemAvailable(string  item, int amount)
{
    set<uint8>("item count", item, 2);
}

void EngineTestBase::tickWithDeadPartyMember()
{
    context->GetValue<Unit*>("party member to resurrect")->Set(MockedTargets::GetPartyMember());
	tick();
    context->GetValue<Unit*>("party member to resurrect")->Set(NULL);
}

void EngineTestBase::tickBehindTarget()
{
    set<bool>("behind", "current target", true);
    tick();
    set<bool>("behind", "current target", false);
}

void EngineTestBase::tickWithCcTarget(string  spell)
{
    set<uint8>("attacker count", 3);
    context->GetValue<Unit*>("cc target", spell)->Set(MockedTargets::GetCc());
    tick();
    set<uint8>("attacker count", 1);
    context->GetValue<Unit*>("cc target", spell)->Set(NULL);
}

void EngineTestBase::tickWhileSwimming()
{
    set<bool>("swimming", "self target", true);
    tick();
    set<bool>("swimming", "self target", false);
}

void EngineTestBase::tickWithItemForSpell(string spell)
{
    set<Item*>("item for spell", "1", (Item*)(void*)0x01);
    tick();
    set<Item*>("item for spell", "1", NULL);
}

void EngineTestBase::tickWithEnemyHealerIsCastingInterruptableSpell(string interrupt)
{
    set<Unit*>("enemy healer target", interrupt, MockedTargets::GetEnemyHealer());
    tick();
    set<Unit*>("enemy healer target", interrupt, NULL);
}

void EngineTestBase::runStressTest()
{
    int count = 20;
    std::cout << "\n";

    ai->buffer = "";
    ai->spellCooldowns.clear();
    ticks(count);
    std::cout << "Normal:\n" << ai->buffer << "\n\n";
    CPPUNIT_ASSERT(ai->buffer.find(",,,,,,,") == string::npos);

    ai->targetIsCastingNonMeleeSpell = true;
    ai->buffer = "";
    ai->spellCooldowns.clear();
    ticks(count);
    std::cout << "Spell Cast:\n" << ai->buffer << "\n\n";
    CPPUNIT_ASSERT(ai->buffer.find(",,,,,,,") == string::npos);

    set<uint8>("attacker count", 5);
    ai->buffer = "";
    ai->spellCooldowns.clear();
    ticks(count);
    std::cout << "AOE:\n" << ai->buffer << "\n\n";
    CPPUNIT_ASSERT(ai->buffer.find(",,,,,,,") == string::npos);

    set<uint8>("health", "current target", 10);
    ai->buffer = "";
    ai->spellCooldowns.clear();
    ticks(count);
    std::cout << "Target Low Health:\n" << ai->buffer << "\n\n";
    CPPUNIT_ASSERT(ai->buffer.find(",,,,,,,") == string::npos);

    ai->dispels[MockedTargets::GetCurrentTarget()] = DISPEL_DISEASE;
    ai->buffer = "";
    ai->spellCooldowns.clear();
    ticks(count);
    std::cout << "Dispel:\n" << ai->buffer << "\n\n";
    CPPUNIT_ASSERT(ai->buffer.find(",,,,,,,") == string::npos);

    context->GetValue<Unit*>("cc target", "entangling roots")->Set(MockedTargets::GetCc());
    ai->buffer = "";
    ai->spellCooldowns.clear();
    ticks(count);
    std::cout << "CC:\n" << ai->buffer << "\n\n";
    CPPUNIT_ASSERT(ai->buffer.find(",,,,,,,") == string::npos);

    set<bool>("moving", "current target", true);
    ai->buffer = "";
    ai->spellCooldowns.clear();
    ticks(count);
    std::cout << "Snare:\n" << ai->buffer << "\n\n";
    CPPUNIT_ASSERT(ai->buffer.find(",,,,,,,") == string::npos);

    lowHealth(10);
    ai->buffer = "";
    ai->spellCooldowns.clear();
    ticks(count);
    std::cout << "Low Health:\n" << ai->buffer << "\n\n";
    CPPUNIT_ASSERT(ai->buffer.find(",,,,,,,") == string::npos);

    lowMana(20);
    ai->buffer = "";
    ai->spellCooldowns.clear();
    ticks(count);
    std::cout << "Low Mana:\n" << ai->buffer << "\n\n";
    CPPUNIT_ASSERT(ai->buffer.find(",,,,,,,") == string::npos);
}
