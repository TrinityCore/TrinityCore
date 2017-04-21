#include "pch.h"

#include "aitest.h"
#include "MockPlayerbotAIBase.h"

using namespace ai;

class TestValue : public CalculatedValue<int>
{
public:
    TestValue(PlayerbotAI* ai) : CalculatedValue<int>(ai, "name", 2), increment(0) {}
    virtual int Calculate() { return ++increment; }

private:
    int increment;
};

class TestManualValue : public ManualSetValue<int>
{
public:
    TestManualValue(PlayerbotAI* ai) : ManualSetValue<int>(ai, 0, "name") {}
};

class TestValueContext : public NamedObjectContext<UntypedValue>
{
public:
    TestValueContext()
    {
        creators["value"] = &TestValueContext::value;
        creators["manual value"] = &TestValueContext::manual_value;
    }

private:
    static UntypedValue* value(PlayerbotAI* ai) { return new TestValue(ai); }
    static UntypedValue* manual_value(PlayerbotAI* ai) { return new TestManualValue(ai); }
};

class TestValueAiObjectContext : public AiObjectContext
{
public:
    TestValueAiObjectContext(PlayerbotAI* const ai) : AiObjectContext(ai)
    {
        valueContexts.Add(new TestValueContext());
    }
};


class ValueTestCase : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( ValueTestCase );
      CPPUNIT_TEST( empty );
      CPPUNIT_TEST( calculate );
      CPPUNIT_TEST( manual );
      CPPUNIT_TEST( fromContext );
  CPPUNIT_TEST_SUITE_END();

protected:

public:
	void setUp()
	{
	}

protected:
    void empty()
	{
        MockPlayerbotAIBase ai;
        TestValue value(&ai);
        CPPUNIT_ASSERT(value == 1);
	}
    
    void calculate()
    {
        MockPlayerbotAIBase ai;
        TestValue value(&ai);

        value.Update();
        CPPUNIT_ASSERT(value == 1);
        
        value.Update();
        CPPUNIT_ASSERT(value == 1);
    
        value.Update();
        CPPUNIT_ASSERT(value == 2);
    
        value.Update();
        CPPUNIT_ASSERT(value == 2);
    }

    void manual()
    {
        MockPlayerbotAIBase ai;
        TestManualValue value(&ai);
        CPPUNIT_ASSERT(value == 0);

        value.Set(3);
        CPPUNIT_ASSERT(value == 3);

        value.Update();
        CPPUNIT_ASSERT(value == 3);
    }

    void fromContext()
    {
        MockPlayerbotAIBase ai;
        TestValueAiObjectContext context(&ai);
        Value<int> *value = context.GetValue<int>("manual value");
        CPPUNIT_ASSERT(value);

        value->Set(3);
        CPPUNIT_ASSERT(3 == value->Get());

        value = context.GetValue<int>("value");
        context.Update();
        context.Update();
        CPPUNIT_ASSERT(1 == value->Get());
    }

};

CPPUNIT_TEST_SUITE_REGISTRATION( ValueTestCase );
