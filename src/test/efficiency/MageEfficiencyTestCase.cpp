#include "pch.h"

#include "../aitest.h"
#include "../../../plugins/playerbot/strategy/mage/MageAiObjectContext.h"
#include "EfficiencyActionExecutionListener.h"
#include "AbstractEfficiencyTestCase.h"

using namespace ai;


class MageEfficiencyTestCase : public AbstractEfficiencyTestCase
{
  CPPUNIT_TEST_SUITE( MageEfficiencyTestCase );
  CPPUNIT_TEST( lvl19_frost );
  CPPUNIT_TEST( lvl19_fire );
  CPPUNIT_TEST( lvl19_arcane );
  CPPUNIT_TEST_SUITE_END();

protected:
    map<string, SpellInfo> lvl19()
    {
        map<string, SpellInfo> spellInfo;
        spellInfo["frostbolt"] = SpellInfo(27, 2, 0, 54);
        spellInfo["frost nova"] = SpellInfo(24, 0, 25, 20);
        spellInfo["arcane explosion"] = SpellInfo(67, 0, 0, 33);
        spellInfo["arcane missiles"] = SpellInfo(106, 4, 0, 36 * 4);
        spellInfo["polymorph"] = SpellInfo(24, 1.5, 0, 0);
        spellInfo["remove curse"] = SpellInfo(27, 0, 0, 0);
        spellInfo["fire blast"] = SpellInfo(72, 0, 8, 64);
        spellInfo["fireball"] = SpellInfo(54, 3, 0, 100);
        spellInfo["flamestrike"] = SpellInfo(120, 2, 0, 60);
        return spellInfo;
    }

 	void lvl19_frost()
	{
        setupEngine(new MageAiObjectContext(ai), "frost", NULL);
        run(lvl19(), 888);
	}

 	void lvl19_fire()
	{
        setupEngine(new MageAiObjectContext(ai), "fire", NULL);
        run(lvl19(), 888);
	}

 	void lvl19_arcane()
	{
        setupEngine(new MageAiObjectContext(ai), "arcane", NULL);
        run(lvl19(), 888);
	}

};

CPPUNIT_TEST_SUITE_REGISTRATION( MageEfficiencyTestCase );
