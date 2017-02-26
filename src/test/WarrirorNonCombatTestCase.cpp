#include "pch.h"

#include "aitest.h"
#include "../../plugins/playerbot/strategy/warrior/WarriorAiObjectContext.h"

using namespace ai;


class WarriorNonCombatTestCase : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( WarriorNonCombatTestCase );
    //CPPUNIT_TEST( buff );
    CPPUNIT_TEST_SUITE_END();

protected:
    MockPlayerbotAIBase *ai;

public:
    void setUp()
    {
    }

protected:
    void buff()
    {
        ai = new MockPlayerbotAIBase();

        Engine engine(ai, new WarriorAiObjectContext(ai));
        engine.addStrategy("nc");
        engine.Init();

        engine.DoNextAction(NULL);
        engine.DoNextAction(NULL);

        std::cout << ai->buffer;
		CPPUNIT_ASSERT(ai->buffer == ">S:defensive stance");
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( WarriorNonCombatTestCase );
