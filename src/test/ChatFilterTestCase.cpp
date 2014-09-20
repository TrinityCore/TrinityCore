#include "pch.h"

#include "aitest.h"
#include "../../plugins/playerbot/ChatFilter.h"

using namespace ai;

class ChatFilterTestCase : public CPPUNIT_NS::TestFixture
{
public:
	ChatFilterTestCase() : filter(NULL) {}

  CPPUNIT_TEST_SUITE( ChatFilterTestCase );
      CPPUNIT_TEST( filter1 );
  CPPUNIT_TEST_SUITE_END();

public:
	void setUp()
	{
	}

protected:
	ChatFilter filter;

	void filter1()
	{
	    string message = filter.Filter("@some message for some");
	    CPPUNIT_ASSERT(message == "message for some");
	}
};

CPPUNIT_TEST_SUITE_REGISTRATION( ChatFilterTestCase );
