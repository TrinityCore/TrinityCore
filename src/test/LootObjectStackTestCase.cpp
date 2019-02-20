#include "pch.h"

#include "aitest.h"
#include "MockPlayerbotAIBase.h"
#include "../../plugins/playerbot/LootObjectStack.h"

using namespace ai;
using namespace std;

class LootObjectStackTestCase : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( LootObjectStackTestCase );
      CPPUNIT_TEST( duplicates );
      CPPUNIT_TEST( shrink );
  CPPUNIT_TEST_SUITE_END();

protected:

public:
	void setUp()
	{
	}

protected:
	void duplicates()
	{
	    LootTargetList data;
	    data.insert(LootTarget(ObjectGuid(uint64(2))));
	    data.insert(LootTarget(ObjectGuid(uint64(2))));

	    CPPUNIT_ASSERT(data.size() == 1);
	}

	void shrink()
	{
	    LootTargetList data;
	    LootTarget t1 = LootTarget(ObjectGuid(uint64(2)));
	    t1.asOfTime = 10;
	    LootTarget t2 = LootTarget(ObjectGuid(uint64(3)));
	    t2.asOfTime = 5;

	    data.insert(t1);
	    data.insert(t2);
	    CPPUNIT_ASSERT(data.size() == 2);

	    data.shrink(7);
        CPPUNIT_ASSERT(data.size() == 1);
	    CPPUNIT_ASSERT(data.begin()->asOfTime == 10);
	}
};

CPPUNIT_TEST_SUITE_REGISTRATION( LootObjectStackTestCase );
