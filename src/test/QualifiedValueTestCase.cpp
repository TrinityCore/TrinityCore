#include "pch.h"

#include "aitest.h"
#include "MockPlayerbotAIBase.h"

using namespace ai;

class TestQualifiedValue : public ManualSetValue<string >, public Qualified
{
public:
    TestQualifiedValue(PlayerbotAI* ai) : ManualSetValue<string >(ai, "", "name"), Qualified() {}
    virtual string Get() { return qualifier; }
};

class TestQualifiedValueContext : public NamedObjectContext<UntypedValue>
{
public:
    TestQualifiedValueContext()
    {
        creators["value"] = &TestQualifiedValueContext::value;
    }

private:
    static UntypedValue* value(PlayerbotAI* ai) { return new TestQualifiedValue(ai); }
};

class TestQualifiedValueAiObjectContext : public AiObjectContext
{
public:
    TestQualifiedValueAiObjectContext(PlayerbotAI* const ai) : AiObjectContext(ai)
    {
        valueContexts.Add(new TestQualifiedValueContext());
    }
};


class QualifiedValueTestCase : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( QualifiedValueTestCase );
      CPPUNIT_TEST( empty );
      CPPUNIT_TEST( qualifier );
      CPPUNIT_TEST( number );
  CPPUNIT_TEST_SUITE_END();

protected:

public:
	void setUp()
	{
	}

protected:
    void qualifier()
	{
        MockPlayerbotAIBase ai;
        TestQualifiedValueAiObjectContext context(&ai);
        
        Value<string > *value = context.GetValue<string >("value", "data");
        CPPUNIT_ASSERT(value->Get() == "data");
	}

    void empty()
    {
        MockPlayerbotAIBase ai;
        TestQualifiedValueAiObjectContext context(&ai);

        Value<string > *value = context.GetValue<string >("value");
        CPPUNIT_ASSERT(value->Get().empty());
    }

    void number()
    {
        MockPlayerbotAIBase ai;
        TestQualifiedValueAiObjectContext context(&ai);

        Value<string > *value = context.GetValue<string >("value", 5);
        CPPUNIT_ASSERT(value->Get() == "5");
    
        value = context.GetValue<string >("value", "5");
        CPPUNIT_ASSERT(value->Get() == "5");
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( QualifiedValueTestCase );
