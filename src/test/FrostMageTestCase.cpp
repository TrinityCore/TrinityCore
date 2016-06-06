#include "pch.h"

#include "aitest.h"
#include "../../plugins/playerbot/strategy/mage/MageAiObjectContext.h"

using namespace ai;


class FrostMageTestCase : public EngineTestBase
{
  CPPUNIT_TEST_SUITE( FrostMageTestCase );
  CPPUNIT_TEST( combatVsMelee );
  CPPUNIT_TEST( dispel );
  CPPUNIT_TEST( boost );
  CPPUNIT_TEST( interruptSpells );
  CPPUNIT_TEST( cc );
  CPPUNIT_TEST( aoe );
  CPPUNIT_TEST( incompatibles );
  CPPUNIT_TEST( low_mana );
  CPPUNIT_TEST( interrupt_enemy_healer );
  CPPUNIT_TEST( stress );
  CPPUNIT_TEST_SUITE_END();

public:
    void setUp()
    {
		EngineTestBase::setUp();
		setupEngine(new MageAiObjectContext(ai), "frost", NULL);
    }

protected:
 	void combatVsMelee()
	{
        tick();
        spellAvailable("frostbolt");

		tickInMeleeRange();
		tickInMeleeRange();

		spellAvailable("frostbolt");
		tickInSpellRange();
        tick();

		tickWithLowHealth(19);

		context->GetValue<uint8>("speed", "current target")->Set(100);
        spellAvailable("frost nova");
        spellAvailable("frostbolt");
        tickInMeleeRange();
        tickInMeleeRange();
        context->GetValue<uint8>("speed", "current target")->Set(80);

		assertActions(">T:frostbolt>T:frost nova>S:flee>T:frostbolt>T:shoot>S:ice block>T:frost nova>T:frostbolt");
	}

    void dispel()
    {
        tick();

		tickWithAuraToDispel(DISPEL_CURSE);

		spellAvailable("remove curse");
		tickWithPartyAuraToDispel(DISPEL_CURSE);

        tick();

		tickWithTargetAuraToDispel(DISPEL_MAGIC);

		assertActions(">T:frostbolt>S:remove curse>P:remove curse on party>T:shoot>T:spellsteal");
    }

    void boost()
    {
        tick(); // frostbolt

		tickWithBalancePercent(1);

        spellAvailable("frostbolt");
        tick(); // frostbolt

        tick(); // shoot

		assertActions(">T:frostbolt>S:icy veins>T:frostbolt>T:shoot");
    }

    void interruptSpells()
    {
		tickWithTargetIsCastingNonMeleeSpell();

        tick(); // frostbolt

        assertActions(">T:counterspell>T:frostbolt");
    }

    void cc()
    {
        tickWithCcTarget("polymorph");

        assertActions(">Cc:polymorph");
    }

   	void aoe()
	{
        engine->addStrategy("frost aoe");

		tick();
		tickWithAttackerCount(4);
		tick();

		assertActions(">T:frostbolt>T:blizzard>T:shoot");
	}

   	void incompatibles()
   	{
        engine->addStrategies("frost", "fire", NULL);

        CPPUNIT_ASSERT(engine->ListStrategies() == "Strategies: fire");
   	}

    void low_mana()
    {
        engine->addStrategy("flee");
        addAura("arcane intellect");
        addPartyAura("arcane intellect");
        addAura("mage armor");

        tickWithLowMana(5);

        set<uint8>("item count", "drink", 0);
        set<float>("distance", "current target", 5);
        tickWithLowMana(5);
        tickWithLowMana(5);

        assertActions(">S:evocation>T:frost nova>S:flee");
    }

    void interrupt_enemy_healer()
    {
        tickWithEnemyHealerIsCastingInterruptableSpell("counterspell");

        assertActions(">H:counterspell on enemy healer");
    }

    void stress()
    {
        runStressTest();
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( FrostMageTestCase );
