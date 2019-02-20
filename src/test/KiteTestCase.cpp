#include "pch.h"

#include "aitest.h"
#include "EngineTestBase.h"
#include "../../plugins/playerbot/strategy/warrior/WarriorAiObjectContext.h"

using namespace ai;


class KiteTestCase : public EngineTestBase
{
    CPPUNIT_TEST_SUITE( KiteTestCase );
    CPPUNIT_TEST( kite );
    CPPUNIT_TEST_SUITE_END();

public:
	virtual void setUp()
	{
		EngineTestBase::setUp();
		setupEngine(new WarriorAiObjectContext(ai), "tank", NULL);

		engine->addStrategy("kite");
        set<float>("distance", "current target", 0.0f);
		
		addAura("battle shout");
		addAura("defensive stance");
    }
 
protected:
    void kite()
    {
        set<bool>("has aggro", "current target", true);
		tick();

        assertActions(">S:runaway");
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( KiteTestCase );
