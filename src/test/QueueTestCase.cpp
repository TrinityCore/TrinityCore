#include "pch.h"
#include "aitest.h"
#include "../plugins/playerbot/strategy/actions/GenericSpellActions.h"

using namespace ai;

class QueueTestCase : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE( QueueTestCase );
	CPPUNIT_TEST( queueMustHaveOrder );
	CPPUNIT_TEST_SUITE_END();

protected:

public:
	void setUp()
	{
	}

protected:
	void queueMustHaveOrder()
	{
		MockPlayerbotAIBase mock;
		CastSpellAction action1(&mock, "1");
        CastSpellAction action2(&mock, "2");
        CastSpellAction action3(&mock, "3");

		Queue q;
		q.Push(new ActionBasket(new ActionNode("action1", NULL, NULL, NULL), 0.5f, false, Event()));
		q.Push(new ActionBasket(new ActionNode("action2", NULL, NULL, NULL), 0.7f, false, Event()));
		q.Push(new ActionBasket(new ActionNode("action3", NULL, NULL, NULL), 0.3f, false, Event()));

		CPPUNIT_ASSERT(string (q.Pop()->getName()) == "action2");
		CPPUNIT_ASSERT(string (q.Pop()->getName()) == "action1");
		CPPUNIT_ASSERT(string (q.Pop()->getName()) == "action3");
		CPPUNIT_ASSERT(q.Pop() == NULL);
	}
};

CPPUNIT_TEST_SUITE_REGISTRATION( QueueTestCase );
