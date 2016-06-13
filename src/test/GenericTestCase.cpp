#include "pch.h"
#include "aitest.h"

#include "EngineTestBase.h"
#include "../../plugins/playerbot/strategy/druid/DruidAiObjectContext.h"

using namespace ai;

class GenericTestCase : public EngineTestBase
{
    CPPUNIT_TEST_SUITE( GenericTestCase );
	CPPUNIT_TEST( flee );
	CPPUNIT_TEST( adds );
	CPPUNIT_TEST( potions );
	CPPUNIT_TEST( guard );
	CPPUNIT_TEST( threat );
	CPPUNIT_TEST( facing );
	CPPUNIT_TEST( drop_target );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp()
    {
		EngineTestBase::setUp();
		setupEngine(new DruidAiObjectContext(ai), "bear", "flee", NULL);
    }

protected:
	void flee()
	{
	    list<Item*> items;
        set<list<Item*> >("inventory items", "drink", items);
	    set<list<Item*> >("inventory items", "food", items);

        set<float>("distance", "current target", 5);
		lowHealth(1);
		lowMana(1);
		tick();

		assertActions(">S:flee");
	}

	void adds()
	{
	    engine->addStrategy("flee from adds");

	    list<ObjectGuid> adds;
	    adds.push_front(ObjectGuid(uint64(1)));
	    set<list<ObjectGuid> >("nearest adds", adds);

	    tick();

		assertActions(">S:runaway");
	}

	void potions()
	{
        engine->addStrategy("flee");
	    engine->addStrategy("potions");

        set<uint8>("item count", "mana potion", 1);
        set<uint8>("item count", "drink", 1);
        set<uint8>("item count", "healing potion", 1);
        set<uint8>("item count", "food", 1);

        spellUnavailable("innervate");
        spellUnavailable("barskin");
        spellUnavailable("survival instincts");

        spellUnavailable("regrowth");
        spellUnavailable("healing touch");
        spellUnavailable("rejuvenation");

	    tickWithLowMana(1);

	    set<bool>("combat", "self target", true);
	    tickWithLowMana(1);
        set<uint8>("item count", "mana potion", 0);
	    tickWithLowMana(1);
        set<uint8>("item count", "drink", 0);
        set<float>("distance", "current target", 5);
	    tickWithLowMana(1);

	    tickWithLowHealth(1);
        set<uint8>("item count", "healing potion", 0);
	    tickWithLowHealth(1);
        set<uint8>("item count", "food", 0);
        set<float>("distance", "current target", 5);
	    tickWithLowHealth(1);

		assertActions(">S:flee>S:mana potion>S:drink>S:flee>S:healing potion>S:food>S:flee");
	}

	void guard()
	{
	    engine->removeStrategy("bear");
	    engine->addStrategy("guard");

	    tick();

		assertActions(">S:move to position");
	}

	void threat()
	{
	    engine->addStrategy("threat");

        set<uint8>("threat", "current target", 100);
	    tick();

		assertActions(">T:reach melee");
	}

	void facing()
	{
        addAura("dire bear form");
        addAura("thorns");
        addTargetAura("faerie fire (feral)");

        set<float>("distance", "current target", ATTACK_DISTANCE - 1);
        set<bool>("facing", "current target", false);
	    tick();
        set<bool>("facing", "current target", true);

		assertActions(">S:set facing");
	}

    void drop_target()
    {
        set<bool>("invalid target", "current target", true);
        tick();
        set<bool>("invalid target", "current target", false);

        assertActions(">S:drop target");
    }

};

CPPUNIT_TEST_SUITE_REGISTRATION( GenericTestCase );
