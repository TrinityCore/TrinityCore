#include "pch.h"

#include "../aitest.h"
#include "../../../plugins/playerbot/strategy/Priest/PriestAiObjectContext.h"
#include "EfficiencyActionExecutionListener.h"
#include "AbstractEfficiencyTestCase.h"

using namespace ai;


class PriestEfficiencyTestCase : public AbstractEfficiencyTestCase
{

CPPUNIT_TEST_SUITE( PriestEfficiencyTestCase );
  CPPUNIT_TEST( lvl19_shadow );
  CPPUNIT_TEST( lvl19_holy );
  CPPUNIT_TEST_SUITE_END();

protected:
    map<string, SpellInfo> lvl19()
    {
        map<string, SpellInfo> spellInfo;
        spellInfo["mind blast"] = SpellInfo(62, 1.5, 8, 74);
        spellInfo["shadow word: pain"] = SpellInfo(80, 0, 18, 120);
        spellInfo["smite"] = SpellInfo(54, 2.5, 0, 58);
        spellInfo["shoot"] = SpellInfo(0, 0, 1, 15);
        return spellInfo;
    }

 	void lvl19_shadow()
	{
        setupEngine(new PriestAiObjectContext(ai), "shadow", "aoe", NULL);
        run(lvl19(), 777);
	}

 	void lvl19_holy()
	{
        setupEngine(new PriestAiObjectContext(ai), "holy", "aoe", NULL);
        run(lvl19(), 777);
	}
};

CPPUNIT_TEST_SUITE_REGISTRATION( PriestEfficiencyTestCase );
