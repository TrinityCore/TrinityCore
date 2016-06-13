#include "pch.h"

#include "../aitest.h"
#include "../../../plugins/playerbot/strategy/Druid/DruidAiObjectContext.h"
#include "EfficiencyActionExecutionListener.h"
#include "AbstractEfficiencyTestCase.h"

using namespace ai;


class DruidEfficiencyTestCase : public AbstractEfficiencyTestCase
{

CPPUNIT_TEST_SUITE( DruidEfficiencyTestCase );
  CPPUNIT_TEST( lvl19_caster );
  CPPUNIT_TEST_SUITE_END();

protected:
    map<string, SpellInfo> lvl19()
    {
        map<string, SpellInfo> spellInfo;
        spellInfo["entangling roots"] = SpellInfo(23, 1.5, 15, 50);
        spellInfo["faerie fire"] = SpellInfo(26, 0, 0, 0);
        spellInfo["hibernate"] = SpellInfo(23, 1.5, 0, 0);
        spellInfo["moonfire"] = SpellInfo(69, 0, 12, 28 + 52);
        spellInfo["wrath"] = SpellInfo(36, 2, 0, 53);
        return spellInfo;
    }

 	void lvl19_caster()
	{
        setupEngine(new DruidAiObjectContext(ai), "caster", "aoe", NULL);
        addTargetAura("faerie fire");
        run(lvl19(), 600);
	}

};

CPPUNIT_TEST_SUITE_REGISTRATION( DruidEfficiencyTestCase );
