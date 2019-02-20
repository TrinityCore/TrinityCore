#include "pch.h"

#include "aitest.h"
#include "MockAiObjectContext.h"
#include "MockedAiObjectContextTestCase.h"
#include "../../plugins/playerbot/strategy/generic/ChatCommandHandlerStrategy.h"

using namespace ai;


class WorldPacketHandlerTestCase : public MockedAiObjectContextTestCase
{
  CPPUNIT_TEST_SUITE( WorldPacketHandlerTestCase );
      CPPUNIT_TEST( groupInvite );
      CPPUNIT_TEST( groupSetLeader );
      CPPUNIT_TEST( notEnoughMoney );
      CPPUNIT_TEST( notEnoughReputation );
      CPPUNIT_TEST( gossip_hello );
      CPPUNIT_TEST( useGameObject );
      CPPUNIT_TEST( roll );
      CPPUNIT_TEST( revive );
      CPPUNIT_TEST( resurrect_request );
      CPPUNIT_TEST( area_trigger );
      CPPUNIT_TEST( mount );
      CPPUNIT_TEST( taxi );
      CPPUNIT_TEST( cannot_equip );
      CPPUNIT_TEST( trade_status );
      CPPUNIT_TEST( loot );
      CPPUNIT_TEST( item_push_result );
      CPPUNIT_TEST( quest_objective_completed );
      CPPUNIT_TEST( party_command );
      CPPUNIT_TEST( taxi_done );
      CPPUNIT_TEST( ready_check );
      CPPUNIT_TEST( uninvite );
      CPPUNIT_TEST( lfg );
      CPPUNIT_TEST( lfg_leave );
      CPPUNIT_TEST( security_check );
      CPPUNIT_TEST( guild_accept );
      CPPUNIT_TEST( lfg_teleport );
  CPPUNIT_TEST_SUITE_END();

public:
    void setUp()
    {
		EngineTestBase::setUp();
		setupEngine(context = new MockAiObjectContext(ai, new AiObjectContext(ai), &ai->buffer), "default", NULL);
    }

protected:
    void groupInvite()
    {
        trigger("group invite");
        tick();

        assertActions(">S:accept invitation");
    }
    void groupSetLeader()
    {
        trigger("group set leader");
        tick();

        assertActions(">S:leader");
    }
    void notEnoughMoney()
    {
        trigger("not enough money");
        tick();
        assertActions(">S:tell not enough money");
    }
    void notEnoughReputation()
    {
        trigger("not enough reputation");
        tick();
        assertActions(">S:tell not enough reputation");
    }

    void useGameObject()
    {
        trigger("use game object");
        tick();
        tick();

        assertActions(">S:add loot>S:use meeting stone");
    }

    void gossip_hello()
    {
        trigger("gossip hello");
        tick();

        assertActions(">S:trainer");
    }

    void roll()
    {
        trigger("loot roll");
        tick();

        assertActions(">S:loot roll");
    }

    void revive()
    {
        engine->addStrategy("dead");

        trigger("dead");
        tick();

        assertActions(">S:revive from corpse");
    }

    void resurrect_request()
    {
        engine->addStrategy("dead");

        trigger("resurrect request");
        tick();

        assertActions(">S:accept resurrect");
    }

    void area_trigger()
    {
        trigger("area trigger");
        tick();
        trigger("within area trigger");
        tick();

        assertActions(">S:reach area trigger>S:area trigger");
    }

    void mount()
    {
        trigger("check mount state");
        tick();

        assertActions(">S:check mount state");
    }

    void taxi()
    {
        trigger("activate taxi");
        tick();
        tick();

        assertActions(">S:remember taxi>S:taxi");
    }
    void cannot_equip()
    {
        trigger("cannot equip");
        tick();
        assertActions(">S:tell cannot equip");
    }

    void trade_status()
    {
        trigger("trade status");
        tick();
        assertActions(">S:accept trade");
    }

    void loot()
    {
        trigger("loot response");
        tick();
        assertActions(">S:store loot");
    }

    void quest_objective_completed()
    {
        trigger("quest objective completed");
        tick();

        assertActions(">S:quest objective completed");
    }

    void item_push_result()
    {
        trigger("item push result");
        tick();

        assertActions(">S:query item usage");
    }

    void party_command()
    {
        trigger("party command");
        tick();

        assertActions(">S:party command");
    }

    void taxi_done()
    {
        trigger("taxi done");
        tick();

        assertActions(">S:taxi");
    }

    void ready_check()
    {
        trigger("ready check");
        tick();

        assertActions(">S:ready check");
    }

    void ready_check_finished()
    {
        trigger("ready check finished");
        tick();

        assertActions(">S:finish ready check");
    }

    void uninvite()
    {
        trigger("uninvite");
        tick();

        assertActions(">S:uninvite");
    }

    void lfg()
    {
        engine->addStrategy("lfg");
        trigger("no possible targets");
        tick();

        trigger("lfg role check");
        tick();

        trigger("lfg proposal");
        tick();

        trigger("lfg proposal active");
        tick();

        assertActions(">S:lfg join>S:lfg role check>S:lfg accept>S:lfg accept");
    }

    void lfg_leave()
    {
        trigger("seldom");
        tick();

        assertActions(">S:lfg leave");
    }

    void security_check()
    {
        trigger("often");
        tick();
        tick();

        assertActions(">S:security check>S:check mail");
    }

    void guild_accept()
    {
        trigger("guild invite");
        tick();

        assertActions(">S:guild accept");
    }

    void lfg_teleport()
    {
        trigger("lfg teleport");
        tick();

        assertActions(">S:lfg teleport");
    }

};

CPPUNIT_TEST_SUITE_REGISTRATION( WorldPacketHandlerTestCase );
