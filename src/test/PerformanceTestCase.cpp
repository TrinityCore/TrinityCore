#include "pch.h"

#include "aitest.h"
#include "EngineTestBase.h"
#include "../../plugins/playerbot/strategy/druid/DruidAiObjectContext.h"
#include "../../plugins/playerbot/strategy/paladin/PaladinAiObjectContext.h"
#include "../../plugins/playerbot/strategy/warrior/WarriorAiObjectContext.h"
#include "../../plugins/playerbot/strategy/warlock/WarlockAiObjectContext.h"
#include "../../plugins/playerbot/strategy/mage/MageAiObjectContext.h"
#include "../../plugins/playerbot/strategy/hunter/HunterAiObjectContext.h"
#include "../../plugins/playerbot/strategy/priest/PriestAiObjectContext.h"
#include "../../plugins/playerbot/strategy/shaman/ShamanAiObjectContext.h"
#include "../../plugins/playerbot/PlayerbotAIConfig.h"

using namespace ai;

#define MAX_TICKS 20

class EverythingFailedActionExecutionListener : public ActionExecutionListener
{
public:
    EverythingFailedActionExecutionListener(MockPlayerbotAIBase *ai) : ai(ai) {}

    virtual bool Before(Action* action, Event event)
    {
        string name = action->getName();
        if (name == "melee" ||
                name == "shoot" ||
                name == "auto shot" ||
                name == "reach melee" ||
                name == "reach spell")
            return true;

        return false;
    }

    virtual bool AllowExecution(Action* action, Event event) { return false; }
    virtual bool OverrideResult(Action* action, bool executed, Event event) { return executed; }
    virtual void After(Action* action, bool executed, Event event) {}

private:
    MockPlayerbotAIBase *ai;
};



class PerformanceTestCase : public EngineTestBase
{
    CPPUNIT_TEST_SUITE( PerformanceTestCase );
        CPPUNIT_TEST( druidBear );
        CPPUNIT_TEST( druidCat );
        CPPUNIT_TEST( paladin );
        CPPUNIT_TEST( warrior );
        CPPUNIT_TEST( warlock );
        CPPUNIT_TEST( priest );
        CPPUNIT_TEST( mage );
        CPPUNIT_TEST( hunter );
        CPPUNIT_TEST( shaman );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp()
    {
        EngineTestBase::setUp();
        setupEngine(new AiObjectContext(ai), "melee", NULL);
    }

protected:
    void run()
    {
        time_t timestamp = time(0);
        int i = 0;
        for (; i<sPlayerbotAIConfig.iterationsPerTick; ++i)
        {
            tick();

            if (!ai->buffer.empty())
                break;
        }

        CPPUNIT_ASSERT(!ai->buffer.empty());

        cout << ai->buffer << " - " << i << "ticks, time: " << (time(0) - timestamp);
    }

    void druidBear()
    {
        setupEngine(new DruidAiObjectContext(ai), "tank", NULL);
        engine->AddActionExecutionListener(new EverythingFailedActionExecutionListener(ai));

        sPlayerbotAIConfig.iterationsPerTick = MAX_TICKS;
        run();
        sPlayerbotAIConfig.iterationsPerTick = 10;
    }

    void paladin()
    {
        setupEngine(new PaladinAiObjectContext(ai), "tank", NULL);
        engine->AddActionExecutionListener(new EverythingFailedActionExecutionListener(ai));

        sPlayerbotAIConfig.iterationsPerTick = MAX_TICKS;
        run();
        sPlayerbotAIConfig.iterationsPerTick = 10;
    }

    void priest()
    {
        setupEngine(new PriestAiObjectContext(ai), "heal", NULL);
        engine->AddActionExecutionListener(new EverythingFailedActionExecutionListener(ai));

        sPlayerbotAIConfig.iterationsPerTick = MAX_TICKS;
        run();
        sPlayerbotAIConfig.iterationsPerTick = 10;
    }

    void mage()
    {
        setupEngine(new MageAiObjectContext(ai), "frost", NULL);
        engine->AddActionExecutionListener(new EverythingFailedActionExecutionListener(ai));

        sPlayerbotAIConfig.iterationsPerTick = MAX_TICKS;
        run();
        sPlayerbotAIConfig.iterationsPerTick = 10;
    }

    void hunter()
    {
        setupEngine(new HunterAiObjectContext(ai), "dps", NULL);
        engine->AddActionExecutionListener(new EverythingFailedActionExecutionListener(ai));

        sPlayerbotAIConfig.iterationsPerTick = MAX_TICKS;
        run();
        sPlayerbotAIConfig.iterationsPerTick = 10;
    }

    void warrior()
    {
        setupEngine(new WarriorAiObjectContext(ai), "tank", NULL);
        engine->AddActionExecutionListener(new EverythingFailedActionExecutionListener(ai));

        sPlayerbotAIConfig.iterationsPerTick = MAX_TICKS;
        run();
        sPlayerbotAIConfig.iterationsPerTick = 10;
    }

    void druidCat()
    {
        setupEngine(new DruidAiObjectContext(ai), "cat", NULL);
        engine->AddActionExecutionListener(new EverythingFailedActionExecutionListener(ai));

        sPlayerbotAIConfig.iterationsPerTick = MAX_TICKS;
        run();
        sPlayerbotAIConfig.iterationsPerTick = 10;
    }

    void warlock()
    {
        setupEngine(new WarlockAiObjectContext(ai), "dps", NULL);
        engine->AddActionExecutionListener(new EverythingFailedActionExecutionListener(ai));

        sPlayerbotAIConfig.iterationsPerTick = MAX_TICKS;
        run();
        sPlayerbotAIConfig.iterationsPerTick = 10;
    }

    void shaman()
    {
        setupEngine(new ShamanAiObjectContext(ai), "melee", NULL);
        engine->AddActionExecutionListener(new EverythingFailedActionExecutionListener(ai));

        sPlayerbotAIConfig.iterationsPerTick = MAX_TICKS;
        run();
        sPlayerbotAIConfig.iterationsPerTick = 10;
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( PerformanceTestCase );
