#include "ScriptMgr.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GameEventMgr.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Unit.h"
#include "GameObject.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "InstanceScript.h"
#include "CombatAI.h"
#include "PassiveAI.h"
#include "Chat.h"
#include "DBCStructure.h"
#include "DBCStores.h"
#include "ObjectMgr.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"

class Tier_18_Vendor : public CreatureScript
{
public:
	Tier_18_Vendor() : CreatureScript("Tier_18_Vendor") {}

	bool OnGossipHello(Player* player, Creature* creature) override
	{
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Tier 18 Normal", GOSSIP_SENDER_MAIN, 1);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Tier 18 Heroic", GOSSIP_SENDER_MAIN, 2);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Tier 18 Mythic", GOSSIP_SENDER_MAIN, 3);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Goodbye", GOSSIP_SENDER_MAIN, 4);
		player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
		return true;
	}

	bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action) override
	{
		if (action == 4)
		{
			player->PlayerTalkClass->SendCloseGossip();
			return false;
		}
		if (action == 1)
		{
			if (player->getClass() == CLASS_DEATH_KNIGHT)
			{
			player->AddItem(124317, 1, 0);
			player->AddItem(124327, 1, 0);
			player->AddItem(124332, 1, 0);
			player->AddItem(124338, 1, 0);
			player->AddItem(124344, 1, 0);
			return true;
			}
			{
			if (player->getClass() == CLASS_DRUID)
				player->AddItem(124246, 1, 0);
			player->AddItem(124255, 1, 0);
			player->AddItem(124261, 1, 0);
			player->AddItem(124267, 1, 0);
			player->AddItem(124272, 1, 0);
			return true;
			}
			{
			if (player->getClass() == CLASS_HUNTER)
				player->AddItem(124284, 1, 0);
			player->AddItem(124292, 1, 0);
			player->AddItem(124296, 1, 0);
			player->AddItem(124301, 1, 0);
			player->AddItem(124307, 1, 0);
			return true;
			}
			{
			if (player->getClass() == CLASS_MAGE)
				player->AddItem(124154, 1, 0);
			player->AddItem(124160, 1, 0);
			player->AddItem(124165, 1, 0);
			player->AddItem(124171, 1, 0);
			player->AddItem(124177, 1, 0);
			return true;
			}
			{
			if (player->getClass() == CLASS_MONK)
			player->AddItem(124247, 1, 0);
			player->AddItem(124256, 1, 0);
			player->AddItem(124262, 1, 0);
			player->AddItem(124268, 1, 0);
			player->AddItem(124273, 1, 0);
			return true;
			}
			{
			if (player->getClass() == CLASS_PALADIN)
				player->AddItem(124318, 1, 0);
			player->AddItem(124328, 1, 0);
			player->AddItem(124333, 1, 0);
			player->AddItem(124339, 1, 0);
			player->AddItem(124345, 1, 0);
			return true;
			}
			{
			if (player->getClass() == CLASS_PRIEST)
				player->AddItem(124155, 1, 0);
			player->AddItem(124161, 1, 0);
			player->AddItem(124166, 1, 0);
			player->AddItem(124172, 1, 0);
			player->AddItem(124178, 1, 0);
			return true;
			}
			{
			if (player->getClass() == CLASS_ROGUE)
				player->AddItem(124248, 1, 0);
			player->AddItem(124257, 1, 0);
			player->AddItem(124263, 1, 0);
			player->AddItem(124269, 1, 0);
			player->AddItem(124274, 1, 0);
			return true;
			}
			{
			if (player->getClass() == CLASS_SHAMAN)
				player->AddItem(124293, 1, 0);
			player->AddItem(124297, 1, 0);
			player->AddItem(124302, 1, 0);
			player->AddItem(124303, 1, 0);
			player->AddItem(124308, 1, 0);
			return true;
			}
			{
			if (player->getClass() == CLASS_WARLOCK)
				player->AddItem(124156, 1, 0);
			player->AddItem(124162, 1, 0);
			player->AddItem(124167, 1, 0);
			player->AddItem(124173, 1, 0);
			player->AddItem(124179, 1, 0);
			return true;
			}
			{
			if (player->getClass() == CLASS_WARRIOR)
				player->AddItem(124319, 1, 0);
			player->AddItem(124329, 1, 0);
			player->AddItem(124334, 1, 0);
			player->AddItem(124340, 1, 0);
			player->AddItem(124346, 1, 0);
			return true;
			}
		}

		if (action == 2)
		{
			if (player->getClass() == CLASS_DEATH_KNIGHT)
			{
			player->AddItem(124317, 1, 566);
			player->AddItem(124327, 1, 566);
			player->AddItem(124332, 1, 566);
			player->AddItem(124338, 1, 566);
			player->AddItem(124344, 1, 566);
			return true;
			}
			{
			if (player->getClass() == CLASS_DRUID)
				player->AddItem(124246, 1, 566);
			player->AddItem(124255, 1, 566);
			player->AddItem(124261, 1, 566);
			player->AddItem(124267, 1, 566);
			player->AddItem(124272, 1, 566);
			return true;
			}
			{
			if (player->getClass() == CLASS_HUNTER)
				player->AddItem(124284, 1, 566);
			player->AddItem(124292, 1, 566);
			player->AddItem(124296, 1, 566);
			player->AddItem(124301, 1, 566);
			player->AddItem(124307, 1, 566);
			return true;
			}
			{
			if (player->getClass() == CLASS_MAGE)
				player->AddItem(124154, 1, 566);
			player->AddItem(124160, 1, 566);
			player->AddItem(124165, 1, 566);
			player->AddItem(124171, 1, 566);
			player->AddItem(124177, 1, 566);
			return true;
			}
			{
			if (player->getClass() == CLASS_MONK)
				player->AddItem(124247, 1, 566);
			player->AddItem(124256, 1, 566);
			player->AddItem(124262, 1, 566);
			player->AddItem(124268, 1, 566);
			player->AddItem(124273, 1, 566);
			return true;
			}
			{
			if (player->getClass() == CLASS_PALADIN)
				player->AddItem(124318, 1, 566);
			player->AddItem(124328, 1, 566);
			player->AddItem(124333, 1, 566);
			player->AddItem(124339, 1, 566);
			player->AddItem(124345, 1, 566);
			return true;
			}
			{
			if (player->getClass() == CLASS_PRIEST)
				player->AddItem(124155, 1, 566);
			player->AddItem(124161, 1, 566);
			player->AddItem(124166, 1, 566);
			player->AddItem(124172, 1, 566);
			player->AddItem(124178, 1, 566);
			return true;
			}
			{
			if (player->getClass() == CLASS_ROGUE)
				player->AddItem(124248, 1, 566);
			player->AddItem(124257, 1, 566);
			player->AddItem(124263, 1, 566);
			player->AddItem(124269, 1, 566);
			player->AddItem(124274, 1, 566);
			return true;
			}
			{
			if (player->getClass() == CLASS_SHAMAN)
				player->AddItem(124293, 1, 566);
			player->AddItem(124297, 1, 566);
			player->AddItem(124302, 1, 566);
			player->AddItem(124303, 1, 566);
			player->AddItem(124308, 1, 566);
			return true;
			}
			{
			if (player->getClass() == CLASS_WARLOCK)
				player->AddItem(124156, 1, 566);
			player->AddItem(124162, 1, 566);
			player->AddItem(124167, 1, 566);
			player->AddItem(124173, 1, 566);
			player->AddItem(124179, 1, 566);
			return true;
			}
			{
			if (player->getClass() == CLASS_WARRIOR)
			player->AddItem(124319, 1, 566);
			player->AddItem(124329, 1, 566);
			player->AddItem(124334, 1, 566);
			player->AddItem(124340, 1, 566);
			player->AddItem(124346, 1, 566);
			return true;
			}
		}

		if (player->getClass() == CLASS_DEATH_KNIGHT)
		player->AddItem(124317, 1, 567);
		player->AddItem(124327, 1, 567);
		player->AddItem(124332, 1, 567);
		player->AddItem(124338, 1, 567);
		player->AddItem(124344, 1, 567);
		if (player->getClass() == CLASS_DRUID)
			player->AddItem(124246, 1, 567);
		player->AddItem(124255, 1, 567);
		player->AddItem(124261, 1, 567);
		player->AddItem(124267, 1, 567);
		player->AddItem(124272, 1, 567);
		if (player->getClass() == CLASS_HUNTER)
			player->AddItem(124284, 1, 567);
		player->AddItem(124292, 1, 567);
		player->AddItem(124296, 1, 567);
		player->AddItem(124301, 1, 567);
		player->AddItem(124307, 1, 567);
		if (player->getClass() == CLASS_MAGE)
			player->AddItem(124154, 1, 567);
		player->AddItem(124160, 1, 567);
		player->AddItem(124165, 1, 567);
		player->AddItem(124171, 1, 567);
		player->AddItem(124177, 1, 567);
		if (player->getClass() == CLASS_MONK)
			player->AddItem(124247, 1, 567);
		player->AddItem(124256, 1, 567);
		player->AddItem(124262, 1, 567);
		player->AddItem(124268, 1, 567);
		player->AddItem(124273, 1, 567);
		if (player->getClass() == CLASS_PALADIN)
			player->AddItem(124318, 1, 567);
		player->AddItem(124328, 1, 567);
		player->AddItem(124333, 1, 567);
		player->AddItem(124339, 1, 567);
		player->AddItem(124345, 1, 567);
		if (player->getClass() == CLASS_PRIEST)
			player->AddItem(124155, 1, 567);
		player->AddItem(124161, 1, 567);
		player->AddItem(124166, 1, 567);
		player->AddItem(124172, 1, 567);
		player->AddItem(124178, 1, 567);
		if (player->getClass() == CLASS_ROGUE)
			player->AddItem(124248, 1, 567);
		player->AddItem(124257, 1, 567);
		player->AddItem(124263, 1, 567);
		player->AddItem(124269, 1, 567);
		player->AddItem(124274, 1, 567);
		if (player->getClass() == CLASS_SHAMAN)
			player->AddItem(124293, 1, 567);
		player->AddItem(124297, 1, 567);
		player->AddItem(124302, 1, 567);
		player->AddItem(124303, 1, 567);
		player->AddItem(124308, 1, 567);
		if (player->getClass() == CLASS_WARLOCK)
			player->AddItem(124156, 1, 567);
		player->AddItem(124162, 1, 567);
		player->AddItem(124167, 1, 567);
		player->AddItem(124173, 1, 567);
		player->AddItem(124179, 1, 567);
		if (player->getClass() == CLASS_WARRIOR)
			player->AddItem(124319, 1, 567);
		player->AddItem(124329, 1, 567);
		player->AddItem(124334, 1, 567);
		player->AddItem(124340, 1, 567);
		player->AddItem(124346, 1, 567);
		return true;
	}
};

void AddSC_Tier_18_Vendor()
{
	new Tier_18_Vendor;
}