/*
* Converted from the original LUA script to a module for Azerothcore(Sunwell) :D
*/
#include "ScriptMgr.h"
#include "Player.h"
#include "Configuration/Config.h"

class RandomEnchantsPlayer : public PlayerScript {
public:

	RandomEnchantsPlayer() : PlayerScript("RandomEnchantsPlayer") { }

	void OnLogin(Player* player, bool /*firstLogin*/) override 
	{
		if (sConfigMgr->GetBoolDefault("RandomEnchants.AnnounceOnLogin", true))
			ChatHandler(player->GetSession()).SendSysMessage(sConfigMgr->GetStringDefault("RandomEnchants.OnLoginMessage", "This server is running a RandomEnchants Module.").c_str());
	}
	void OnLootItem(Player* player, Item* item, uint32 count) override
	{
		if (sConfigMgr->GetBoolDefault("RandomEnchants.OnLoot", true))
			RollPossibleEnchant(player, item);
	}
	void OnCreateItem(Player* player, Item* item, uint32 count) override
	{
		if (sConfigMgr->GetBoolDefault("RandomEnchants.OnCreate", true))
			RollPossibleEnchant(player, item);
	}
	void OnQuestRewardItem(Player* player, Item* item, uint32 count) override
	{
		if (sConfigMgr->GetBoolDefault("RandomEnchants.OnQuestReward", true))
			RollPossibleEnchant(player, item);
	}
	void RollPossibleEnchant(Player* player, Item* item)
	{
		uint32 Quality = item->GetTemplate()->Quality;
		uint32 Class = item->GetTemplate()->Class;
		if ((Quality > 5 && Quality < 0)/*eliminates enchanting anything that isn't a recognized quality*/ || (Class != 2 && Class != 4)/*eliminates enchanting anything but weapons/armor*/)
			return;
		int slotRand[3] = { -1, -1, -1 };
		uint32 slotEnch[3] = { 0, 1, 5 };
		double roll1 = rand_chance();
		if (roll1 >= 70.0)
			slotRand[0] = getRandEnchantment(item);
		if (slotRand[0] != -1)
		{
			double roll2 = rand_chance();
			if (roll2 >= 65.0)
				slotRand[1] = getRandEnchantment(item);
			if (slotRand[1] != -1)
			{
				double roll3 = rand_chance();
				if (roll3 >= 60.0)
					slotRand[2] = getRandEnchantment(item);
			}
		}
		for (int i = 0; i < 2; i++)
		{
			if (slotRand[i] != -1)
			{
				if (sSpellItemEnchantmentStore.LookupEntry(slotRand[i]))//Make sure enchantment id exists
				{
					player->ApplyEnchantment(item, EnchantmentSlot(slotEnch[i]), false);
					item->SetEnchantment(EnchantmentSlot(slotEnch[i]), slotRand[i], 0, 0);
					player->ApplyEnchantment(item, EnchantmentSlot(slotEnch[i]), true);
				}
			}
		}
		ChatHandler chathandle = ChatHandler(player->GetSession());
		if (slotRand[2] != -1)
			chathandle.PSendSysMessage("Newly Acquired |cffFF0000 %s |rhas received|cffFF0000 3 |rrandom enchantments!", item->GetTemplate()->Name1.c_str());
		else if (slotRand[1] != -1)
			chathandle.PSendSysMessage("Newly Acquired |cffFF0000 %s |rhas received|cffFF0000 2 |rrandom enchantments!", item->GetTemplate()->Name1.c_str());
		else if (slotRand[0] != -1)
			chathandle.PSendSysMessage("Newly Acquired |cffFF0000 %s |rhas received|cffFF0000 1 |rrandom enchantment!", item->GetTemplate()->Name1.c_str());
	}
	int getRandEnchantment(Item* item)
	{
		uint32 Class = item->GetTemplate()->Class;
		std::string ClassQueryString = "";
		switch (Class)
		{
		case 2:
			ClassQueryString = "WEAPON";
			break;
		case 4:
			ClassQueryString = "ARMOR";
			break;
		}
		if (ClassQueryString == "")
			return -1;
		uint32 Quality = item->GetTemplate()->Quality;
		int rarityRoll = -1;
		switch (Quality)
		{
		case 0://grey
			rarityRoll = rand_norm() * 25;
			break;
		case 1://white
			rarityRoll = rand_norm() * 50;
			break;
		case 2://green
			rarityRoll = 45 + (rand_norm() * 20);
			break;
		case 3://blue
			rarityRoll = 65 + (rand_norm() * 15);
			break;
		case 4://purple
			rarityRoll = 80 + (rand_norm() * 14);
			break;
		case 5://orange
			rarityRoll = 93;
			break;
		}
		if (rarityRoll < 0)
			return -1;
		int tier = 0;
		if (rarityRoll <= 44)
			tier = 1;
		else if (rarityRoll <= 64)
			tier = 2;
		else if (rarityRoll <= 79)
			tier = 3;
		else if (rarityRoll <= 92)
			tier = 4;
		else
			tier = 5;

		QueryResult qr = WorldDatabase.PQuery("SELECT enchantID FROM item_enchantment_random_tiers WHERE tier='%d' AND exclusiveSubClass=NULL AND class='%s' OR exclusiveSubClass='%u' OR class='ANY' ORDER BY RAND() LIMIT 1", tier, ClassQueryString.c_str(), item->GetTemplate()->SubClass);
		return qr->Fetch()[0].GetUInt32();
	}
};
/*class RandomEnchantsWorld : public WorldScript
{
public:
	RandomEnchantsWorld() : WorldScript("RandomEnchantsWorld") { }

	void OnBeforeConfigLoad(bool reload) override
	{
		if (!reload) {
			std::string conf_path = _CONF_DIR;
			std::string cfg_file = conf_path + "/RandomEnchants.conf";
#ifdef WIN32
			cfg_file = "RandomEnchants.conf";
#endif
			std::string cfg_def_file = cfg_file + ".dist";
			sConfigMgr->LoadMore(cfg_def_file.c_str());

			sConfigMgr->LoadMore(cfg_file.c_str());
		}
	}
};*/

void AddSC_RandomEnchantsScripts() {
	//new RandomEnchantsWorld();
	new RandomEnchantsPlayer();
}