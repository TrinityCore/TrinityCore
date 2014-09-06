#include "pch.h"

#include "aitest.h"
#include "MockPlayerbotAIBase.h"

using namespace ai;

char *strstri(const char *haystack, const char *needle);

class EventTestCase : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( EventTestCase );
      CPPUNIT_TEST( emptyEvent );
      CPPUNIT_TEST( eventHandling );
      CPPUNIT_TEST( strstriTest1 );
      CPPUNIT_TEST( strstriTest2 );
  CPPUNIT_TEST_SUITE_END();

protected:

public:
	void setUp()
	{
	}

protected:
	void emptyEvent()
	{
        Event event;
        CPPUNIT_ASSERT(!event);
	}

    void eventHandling()
    {
        Event event("source", "param");

        Event event2 = event;

        CPPUNIT_ASSERT(!!event2);
        CPPUNIT_ASSERT(event2.getParam() == "param");
        CPPUNIT_ASSERT(event2.getSource() == "source");
    }

    void strstriTest1()
    {
        string a = "Mana Spring Totem V";
        string b = "strength of earth totem";
        CPPUNIT_ASSERT(!strstri(a.c_str(), b.c_str()));
    }

    void strstriTest2()
    {
        string a = "mana spring Totem V";
        string b = "mana Spring totem";
        CPPUNIT_ASSERT(strstri(a.c_str(), b.c_str()));
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( EventTestCase );
