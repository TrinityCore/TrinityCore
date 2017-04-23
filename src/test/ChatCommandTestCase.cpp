#include "pch.h"

#include "aitest.h"
#include "MockAiObjectContext.h"
#include "MockedAiObjectContextTestCase.h"
#include "../../plugins/playerbot/strategy/generic/ChatCommandHandlerStrategy.h"

using namespace ai;


class ChatCommandTestCase : public MockedAiObjectContextTestCase
{
  CPPUNIT_TEST_SUITE( ChatCommandTestCase );
      CPPUNIT_TEST( stats );
      CPPUNIT_TEST( leave );
      CPPUNIT_TEST( quests );
      CPPUNIT_TEST( reputation );
      CPPUNIT_TEST( log );
      CPPUNIT_TEST( los );
      CPPUNIT_TEST( drop );
      CPPUNIT_TEST( query );
      CPPUNIT_TEST( ll );
      CPPUNIT_TEST( loot_all );
      CPPUNIT_TEST( release );
      CPPUNIT_TEST( teleport );
      CPPUNIT_TEST( taxi );
      CPPUNIT_TEST( repair );
      CPPUNIT_TEST( use );
      CPPUNIT_TEST( item_count );
      CPPUNIT_TEST( reward );
      CPPUNIT_TEST( trade );
      CPPUNIT_TEST( equip );
      CPPUNIT_TEST( unequip );
      CPPUNIT_TEST( sell );
      CPPUNIT_TEST( buy );
      CPPUNIT_TEST( talents );
      CPPUNIT_TEST( spells );
      CPPUNIT_TEST( strategy );
      CPPUNIT_TEST( trainer );
      CPPUNIT_TEST( attack );
      CPPUNIT_TEST( chat );
      CPPUNIT_TEST( accept );
      CPPUNIT_TEST( home );
      CPPUNIT_TEST( destroy );
      CPPUNIT_TEST( reset_ai );
      CPPUNIT_TEST( emote );
      CPPUNIT_TEST( buff );
      CPPUNIT_TEST( help );
      CPPUNIT_TEST( gb );
      CPPUNIT_TEST( bank );
      CPPUNIT_TEST( follow );
      CPPUNIT_TEST( flee );
      CPPUNIT_TEST( stay );
      CPPUNIT_TEST( grind );
      CPPUNIT_TEST( tank_attack );
      CPPUNIT_TEST( talk );
      CPPUNIT_TEST( cast );
      CPPUNIT_TEST( invite );
      CPPUNIT_TEST( spell );
      CPPUNIT_TEST( rti );
      CPPUNIT_TEST( revive );
      CPPUNIT_TEST( runaway );
      CPPUNIT_TEST( warning );
      CPPUNIT_TEST( position );
      CPPUNIT_TEST( summon );
      CPPUNIT_TEST( who );
      CPPUNIT_TEST( save_mana );
      CPPUNIT_TEST( max_dps );
      CPPUNIT_TEST( tell_attackers );
      CPPUNIT_TEST( formation );
      CPPUNIT_TEST( sendmail );
  CPPUNIT_TEST_SUITE_END();

public:
    void setUp()
    {
		EngineTestBase::setUp();
		setupEngine(context = new MockAiObjectContext(ai, new AiObjectContext(ai), &ai->buffer), "chat", NULL);
    }

protected:
 	void stats()
	{
        assertCommand("stats");
	}

    void leave()
    {
        assertCommand("leave");
    }

    void reputation()
    {
        assertCommand("rep", "reputation");
        assertCommand("reputation");
    }

    void quests()
    {
        assertCommand("quests");
        assertParametrizedCommand("quests", "summary");
        assertParametrizedCommand("quests", "completed");
        assertParametrizedCommand("quests", "incompleted");
    }

    void log()
    {
        assertCommand("log");
        assertParametrizedCommand("log", "debug");
    }

    void los()
    {
        assertCommand("los");
        assertParametrizedCommand("los", "targets");
        assertParametrizedCommand("los", "npcs");
        assertParametrizedCommand("los", "gos");
        assertParametrizedCommand("los", "game objects");
        assertParametrizedCommand("los", "corpses");
    }

    void drop()
    {
        assertCommand("drop");
    }

    void query()
    {
        trigger("q");
        tick();
        tick();

        assertActions(">S:query quest>S:query item usage");
    }

    void ll()
    {
        assertCommand("ll");
        assertParametrizedCommand("ll", "?");
        assertParametrizedCommand("ll", "[item]");
        assertParametrizedCommand("ll", "-[item]");
        assertParametrizedCommand("ll", "all");
    }

    void loot_all()
    {
        trigger("add all loot");
        tick();
        tick();

        assertActions(">S:add all loot>S:loot");
    }

    void release()
    {
        assertCommand("release");
    }

    void teleport()
    {
        assertCommand("teleport");
    }

    void taxi()
    {
        assertCommand("taxi");
    }

    void repair()
    {
        assertCommand("repair");
    }

    void use()
    {
        trigger("u");
        tick();

        assertActions(">S:use");
    }

    void item_count()
    {
        trigger("c");
        tick();

        assertActions(">S:item count");
    }

    void reward()
    {
        trigger("r");
        tick();

        assertActions(">S:reward");
    }
    void trade()
    {
        trigger("t");
        tick();
        trigger("nt");
        tick();

        assertActions(">S:trade>S:trade");
    }
    void sell()
    {
        trigger("s");
        tick();

        assertActions(">S:sell");
    }
    void buy()
    {
        trigger("b");
        tick();

        assertActions(">S:buy");
    }
    void equip()
    {
        trigger("e");
        tick();

        assertActions(">S:equip");
    }
    void unequip()
    {
        trigger("ue");
        tick();

        assertActions(">S:unequip");
    }

    void talents()
    {
        assertParametrizedCommand("talents", "1");
        assertParametrizedCommand("talents", "2");
    }

    void spells()
    {
        assertCommand("spells");
    }

    void strategy()
    {
        assertParametrizedCommand("co", "?");
        assertParametrizedCommand("nc", "?");
        assertParametrizedCommand("dead", "?");
    }

    void trainer()
    {
        assertParametrizedCommand("trainer", "?");
        assertParametrizedCommand("trainer", "learn");
    }

    void attack()
    {
        trigger("attack");
        tick();
        assertActions(">S:attack my target");
    }

    void chat()
    {
        assertParametrizedCommand("chat", "?");
        assertParametrizedCommand("chat", "raid");
    }

    void accept()
    {
        trigger("accept");
        tick();
        assertActions(">S:accept quest");
    }

    void home()
    {
        assertCommand("home");
    }

    void reset_ai()
    {
        assertCommand("reset ai");
    }

    void destroy()
    {
        assertCommand("destroy");
    }

    void emote()
    {
        assertCommand("emote");
    }

    void buff()
    {
        assertCommand("buff");
        assertParametrizedCommand("buff", "?");
    }

    void help()
    {
        assertCommand("help");
    }

    void follow()
    {
        trigger("follow");
        tick();
        assertActions(">S:follow chat shortcut");
    }

    void stay()
    {
        trigger("stay");
        tick();
        assertActions(">S:stay chat shortcut");
    }

    void flee()
    {
        trigger("flee");
        tick();
        assertActions(">S:flee chat shortcut");
    }

    void grind()
    {
        trigger("grind");
        tick();
        assertActions(">S:grind chat shortcut");
    }

    void tank_attack()
    {
        trigger("tank attack");
        tick();
        tick();
        assertActions(">S:tank attack chat shortcut>S:attack my target");
    }

    void gb()
    {
        assertParametrizedCommand("gb", "link");
    }

    void bank()
    {
        assertParametrizedCommand("bank", "link");
    }

    void talk()
    {
        trigger("talk");
        tick();
        assertActions(">S:gossip hello");
    }

    void cast()
    {
        trigger("cast");
        tick();
        assertActions(">S:cast custom spell");
    }

    void invite()
    {
        trigger("invite");
        tick();
        assertActions(">S:invite");
    }

    void spell()
    {
        trigger("spell");
        tick();
        assertActions(">S:spell");
    }

    void rti()
    {
        trigger("rti");
        tick();
        assertActions(">S:rti");
    }

    void revive()
    {
        trigger("revive");
        tick();
        assertActions(">S:spirit healer");
    }

    void runaway()
    {
        trigger("runaway");
        tick();
        assertActions(">S:runaway chat shortcut");
    }

    void warning()
    {
        trigger("warning");
        tick();
        assertActions(">S:runaway chat shortcut");
    }

    void position()
    {
        assertParametrizedCommand("position", "guard");
    }

    void summon()
    {
        assertParametrizedCommand("summon", "summon");
    }

    void who()
    {
        assertCommand("who", "who");
    }

    void save_mana()
    {
        assertParametrizedCommand("save mana", "save mana");
    }

    void max_dps()
    {
        trigger("max dps");
        tick();
        assertActions(">S:max dps chat shortcut");
    }

    void tell_attackers()
    {
        trigger("attackers");
        tick();
        assertActions(">S:tell attackers");
    }

    void formation()
    {
        trigger("formation");
        tick();
        assertActions(">S:formation");
    }

    void sendmail()
    {
        trigger("sendmail");
        tick();
        assertActions(">S:sendmail");
    }

};

CPPUNIT_TEST_SUITE_REGISTRATION( ChatCommandTestCase );
