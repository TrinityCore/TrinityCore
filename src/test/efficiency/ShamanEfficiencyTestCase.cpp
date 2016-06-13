#include "pch.h"

#include "../aitest.h"
#include "../../../plugins/playerbot/strategy/shaman/ShamanAiObjectContext.h"
#include "EfficiencyActionExecutionListener.h"
#include "AbstractEfficiencyTestCase.h"

using namespace ai;


class ShamanEfficiencyTestCase : public AbstractEfficiencyTestCase
{
  CPPUNIT_TEST_SUITE( ShamanEfficiencyTestCase );
  CPPUNIT_TEST( lvl19_melee );
  CPPUNIT_TEST( lvl19_caster );
  CPPUNIT_TEST_SUITE_END();

protected:
    map<string, SpellInfo> lvl19()
    {
        map<string, SpellInfo> spellInfo;
        spellInfo["earth shock"] = SpellInfo(62, 0, 6, 62, "shock");
        spellInfo["flame shock"] = SpellInfo(58, 0, 18, 45 + 72, "shock");
        spellInfo["lightning bolt"] = SpellInfo(34, 2.5, 0, 49);
        spellInfo["lightning shield"] = SpellInfo(0, 0, 0, 0);
        spellInfo["searing totem"] = SpellInfo(24, 0, 30, 10 * 30 / 1.5);
        spellInfo["fire nova"] = SpellInfo(75, 0, 6, 52);
        spellInfo["melee"] = SpellInfo(0, 0, 1, 15 + 6);
        return spellInfo;
    }

 	void lvl19_melee()
	{
        setupEngine(new ShamanAiObjectContext(ai), "melee", "melee aoe", NULL);
        run(lvl19(), 600);
	}

 	void lvl19_caster()
	{
        setupEngine(new ShamanAiObjectContext(ai), "caster", "caster aoe", NULL);
        run(lvl19(), 600);
	}

};

CPPUNIT_TEST_SUITE_REGISTRATION( ShamanEfficiencyTestCase );
