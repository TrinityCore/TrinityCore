#include "pch.h"

#include "../aitest.h"
#include "../../../plugins/playerbot/strategy/Warlock/WarlockAiObjectContext.h"
#include "EfficiencyActionExecutionListener.h"
#include "AbstractEfficiencyTestCase.h"

using namespace ai;


class WarlockEfficiencyTestCase : public AbstractEfficiencyTestCase
{
  CPPUNIT_TEST_SUITE( WarlockEfficiencyTestCase );
  CPPUNIT_TEST( lvl19_dps );
  CPPUNIT_TEST( lvl19_tank );
  CPPUNIT_TEST_SUITE_END();

protected:
    map<string, SpellInfo> lvl19()
    {
        map<string, SpellInfo> spellInfo;
        spellInfo["corruption"] = SpellInfo(42, 0, 15, 90);
        spellInfo["immolate"] = SpellInfo(60, 0, 15, 19 + 40);
        spellInfo["shadow bolt"] = SpellInfo(58, 2.8, 0, 52);
        spellInfo["curse of agony"] = SpellInfo(35, 0, 24, 180);
        spellInfo["shoot"] = SpellInfo(0, 0, 1, 15);
        return spellInfo;
    }

 	void lvl19_dps()
	{
        setupEngine(new WarlockAiObjectContext(ai), "dps", "aoe", NULL);
        run(lvl19(), 888);
	}

 	void lvl19_tank()
	{
        setupEngine(new WarlockAiObjectContext(ai), "tank", "aoe", NULL);
        run(lvl19(), 888);
	}
};

CPPUNIT_TEST_SUITE_REGISTRATION( WarlockEfficiencyTestCase );
