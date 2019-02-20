#include "pch.h"

#include "aitest.h"
#include "EngineTestBase.h"
#include "../../plugins/playerbot/strategy/warrior/WarriorAiObjectContext.h"

using namespace ai;


class RacialsTestCase : public EngineTestBase
{
    CPPUNIT_TEST_SUITE( RacialsTestCase );
    CPPUNIT_TEST( healing );
    CPPUNIT_TEST_SUITE_END();

public:
	virtual void setUp()
	{
		EngineTestBase::setUp();
		setupEngine(new WarriorAiObjectContext(ai), "tank", NULL);

		engine->addStrategy("racials");
        set<float>("distance", "current target", 0.0f);
		
		addAura("battle shout");
		addAura("defensive stance");
    }
 
protected:
    void healing()
    {
		tickWithLowHealth(39);
		tickWithLowHealth(39);

        tickWithLowMana(39);

        assertActions(">S:lifeblood>S:gift of the naaru>S:arcane torrent");
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( RacialsTestCase );
