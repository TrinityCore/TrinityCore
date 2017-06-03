#include "pch.h"

#include "aitest.h"
#include "../plugins/playerbot/RandomItemMgr.h"
#include "cppunit/extensions/HelperMacros.h"
#include "cppunit/TestFixture.h"

using namespace ai;


class RandomItemMgrTestCase : public CPPUNIT_NS::TestFixture
{

    void Show(uint32 id)
    {
        ItemTemplate const* proto = sObjectMgr->GetItemTemplate(id);
        cout << proto->ItemId << " = " << proto->Name1 << endl;
    }

  CPPUNIT_TEST_SUITE( RandomItemMgrTestCase );
      CPPUNIT_TEST( guildTaskItems );
      CPPUNIT_TEST( guildTaskRewardItems );
  CPPUNIT_TEST_SUITE_END();

public:
    void setUp()
    {
        TC_LOG_INFO("server.loading", "Loading SpellInfo store...");
        sSpellMgr->LoadSpellInfoStore();

        TC_LOG_INFO("server.loading", "Loading SpellInfo corrections...");
        sSpellMgr->LoadSpellInfoCorrections();

        TC_LOG_INFO("server.loading", "Loading SkillLineAbilityMultiMap Data...");
        sSpellMgr->LoadSkillLineAbilityMap();

        TC_LOG_INFO("server.loading", "Loading SpellInfo custom attributes...");
        sSpellMgr->LoadSpellInfoCustomAttributes();

        TC_LOG_INFO("server.loading", "Loading Item Random Enchantments Table...");
        LoadRandomEnchantmentsTable();

        TC_LOG_INFO("server.loading", "Loading Items...");                         // must be after LoadRandomEnchantmentsTable and LoadPageTexts
        sObjectMgr->LoadItemTemplates();
    }
    virtual void tearDown()
    {
    }

protected:
 	void checkRandomItems(RandomItemType type)
	{
        RandomItemList const& list = sRandomItemMgr.Query(type, NULL);
        CPPUNIT_ASSERT(!list.empty());

        for (RandomItemList::const_iterator i = list.begin(); i != list.end(); ++i)
        {
            uint32 id = *i;
            Show(id);
        }

        cout << "Picking randoms" << endl;

        for (int i = 0; i < 10; i++)
        {
            uint32 id = sRandomItemMgr.GetRandomItem(type, NULL);
            CPPUNIT_ASSERT(id);
            Show(id);
        }
	}

 	void guildTaskItems()
 	{
 	   checkRandomItems(RANDOM_ITEM_GUILD_TASK);
	}

 	void guildTaskRewardItems()
 	{
 	   checkRandomItems(RANDOM_ITEM_GUILD_TASK_REWARD_EQUIP);
	}

};

//CPPUNIT_TEST_SUITE_REGISTRATION( RandomItemMgrTestCase );
