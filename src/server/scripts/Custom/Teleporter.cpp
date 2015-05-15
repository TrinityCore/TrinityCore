#include "ScriptMgr.h"
#include "ScriptedGossip.h"
#include "Player.h"

class Teleporter_NPC : public CreatureScript
{
public:
	Teleporter_NPC() : CreatureScript("Teleporter_NPC") {}

	bool OnGossipHello(Player* plr, Creature* npc)
	{
		//bool combat = plr->IsInCombat();
		//bool gamer = plr->IsGameMaster();
		uint32 pfaction = plr->getRace();
		
		plr->ADD_GOSSIP_ITEM(0, "Heal Me Up!", GOSSIP_SENDER_MAIN, 1);
		if (plr->IsInCombat())
		{
			plr->ADD_GOSSIP_ITEM(0, "Remove Combat", GOSSIP_SENDER_MAIN, 2);
		}
		
		if (plr->getRace() == 1 || plr->getRace() == 3 || plr->getRace() == 4 || plr->getRace() == 7 || plr->getRace() == 11 || plr->getRace() == 22 || plr->getRace() == 25)
			
		{
			plr->ADD_GOSSIP_ITEM(2, "Alliance Cities", GOSSIP_SENDER_MAIN, 4);
		}
		else if (plr->getRace() == 2 || plr->getRace() == 5 || plr->getRace() == 6 || plr->getRace() == 8 || plr->getRace() == 10 || plr->getRace() == 9 || plr->getRace() == 26)
		{
			plr->ADD_GOSSIP_ITEM(4, "Horde Cities", GOSSIP_SENDER_MAIN, 3);
		}
		if (plr->getLevel() > 57)
			plr->ADD_GOSSIP_ITEM(3, "Outland", GOSSIP_SENDER_MAIN, 5);
		if (plr->getLevel() > 67)
			plr->ADD_GOSSIP_ITEM(3, "Northrend", GOSSIP_SENDER_MAIN, 6);
		if (plr->getLevel() > 79)
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 7);
		if (plr->getLevel() > 84)
			plr->ADD_GOSSIP_ITEM(3, "Pandaria", GOSSIP_SENDER_MAIN, 8);
		if (plr->getLevel() > 89)
			plr->ADD_GOSSIP_ITEM(3, "Draenor", GOSSIP_SENDER_MAIN, 44);
		if (plr->getLevel() > 89)
			plr->ADD_GOSSIP_ITEM(3, "Isles", GOSSIP_SENDER_MAIN, 9);
		if (plr->getLevel() > 59)
			plr->ADD_GOSSIP_ITEM(3, "Raids", GOSSIP_SENDER_MAIN, 45);
		plr->ADD_GOSSIP_ITEM(3, "Dungeons", GOSSIP_SENDER_MAIN, 46);

		if (plr->IsGameMaster())
		{
			plr->ADD_GOSSIP_ITEM(3, "GMIsland", GOSSIP_SENDER_MAIN, 30);
		}
		if (plr->getRace() == 24)
		{
			plr->ADD_GOSSIP_ITEM(3, "Choose Faction...", GOSSIP_SENDER_MAIN, 32);
		}
		plr->ADD_GOSSIP_ITEM(3, "Add Garrison", GOSSIP_SENDER_MAIN, 43);
		plr->ADD_GOSSIP_ITEM(3, "Nevermind...", GOSSIP_SENDER_MAIN, 31);
		plr->SEND_GOSSIP_MENU(plr->GetGossipTextId(npc), npc->GetGUID());
		
		return true;
	}
	
	bool OnGossipSelect(Player* plr, Creature* npc, uint32 sender, uint32 uiAction)
	{
		if (!plr)
			return false;

		plr->PlayerTalkClass->ClearMenus();

		switch (uiAction)
		{
		case 1:
		{
				  uint32 MaxHealth = plr->GetMaxHealth();
				  plr->SetHealth(MaxHealth);
				  //plr->GetSession()->SendAreaTriggerMessage("You've been healed!");
				  
				  plr->CLOSE_GOSSIP_MENU();
				  break;
		}
		case 2:
		{
				  plr->CombatStop();
				  //plr->GetSession()->SendAreaTriggerMessage("Combat Removed!");
				  plr->CLOSE_GOSSIP_MENU();
				  break;

		}
		case 3:
		{
				  plr->ADD_GOSSIP_ITEM(3, "Orgrimmar", GOSSIP_SENDER_MAIN, 10);
				  plr->ADD_GOSSIP_ITEM(3, "Undercity", GOSSIP_SENDER_MAIN, 11);
				  plr->ADD_GOSSIP_ITEM(3, "Silvermoon City", GOSSIP_SENDER_MAIN, 12);
				  plr->ADD_GOSSIP_ITEM(3, "Thunderbluff", GOSSIP_SENDER_MAIN, 13);
				  plr->SEND_GOSSIP_MENU(plr->GetGossipTextId(npc), npc->GetGUID());
				  break;
		}
		case 4:
		{
				  plr->ADD_GOSSIP_ITEM(3, "Stormwind", GOSSIP_SENDER_MAIN, 14);
				  plr->ADD_GOSSIP_ITEM(3, "Darnassus", GOSSIP_SENDER_MAIN, 15);
				  plr->ADD_GOSSIP_ITEM(3, "Exodar", GOSSIP_SENDER_MAIN, 16);
				  plr->ADD_GOSSIP_ITEM(3, "Ironforge", GOSSIP_SENDER_MAIN, 17);
				  plr->SEND_GOSSIP_MENU(plr->GetGossipTextId(npc), npc->GetGUID());
				  break;
		}
		case 5:
		{
				  plr->ADD_GOSSIP_ITEM(3, "Shattrath City", GOSSIP_SENDER_MAIN, 18);
				  plr->ADD_GOSSIP_ITEM(3, "Netherstorm", GOSSIP_SENDER_MAIN, 19);
				  plr->ADD_GOSSIP_ITEM(3, "Dark Portal", GOSSIP_SENDER_MAIN, 20);
				  plr->ADD_GOSSIP_ITEM(3, "Zangarmarsh", GOSSIP_SENDER_MAIN, 21);
				  plr->SEND_GOSSIP_MENU(plr->GetGossipTextId(npc), npc->GetGUID());
				  break;
		}
		case 6:
		{
				  plr->ADD_GOSSIP_ITEM(3, "Dalaran", GOSSIP_SENDER_MAIN, 35);
				  plr->ADD_GOSSIP_ITEM(3, "Icecrown", GOSSIP_SENDER_MAIN, 36);
				  plr->ADD_GOSSIP_ITEM(3, "Borean Tundra", GOSSIP_SENDER_MAIN, 37);
				  plr->ADD_GOSSIP_ITEM(3, "Howling Fjord", GOSSIP_SENDER_MAIN, 38);
				  plr->SEND_GOSSIP_MENU(plr->GetGossipTextId(npc), npc->GetGUID());
				  break;
		}
		case 7:
		{
				  plr->ADD_GOSSIP_ITEM(3, "Deepholm", GOSSIP_SENDER_MAIN, 39);
				  plr->ADD_GOSSIP_ITEM(3, "Mount Hyjal", GOSSIP_SENDER_MAIN, 40);
				  plr->ADD_GOSSIP_ITEM(3, "Uldum", GOSSIP_SENDER_MAIN, 41);
				  plr->ADD_GOSSIP_ITEM(3, "Twilight Highlands", GOSSIP_SENDER_MAIN, 42);
				  plr->SEND_GOSSIP_MENU(plr->GetGossipTextId(npc), npc->GetGUID());
				  break;
		}
		case 8:
		{

				  if (plr->getRace() == 1 || plr->getRace() == 3 || plr->getRace() == 4 || plr->getRace() == 7 || plr->getRace() == 11 || plr->getRace() == 22 || plr->getRace() == 25)
				  {
					  plr->ADD_GOSSIP_ITEM(3, "Shrine of Seven Stars", GOSSIP_SENDER_MAIN, 22);
				  }
				  else if (plr->getRace() == 2 || plr->getRace() == 5 || plr->getRace() == 6 || plr->getRace() == 8 || plr->getRace() == 10 || plr->getRace() == 9 || plr->getRace() == 26)
				  {
					  plr->ADD_GOSSIP_ITEM(3, "Shrine of Two Moons", GOSSIP_SENDER_MAIN, 23);
				  }
				  plr->ADD_GOSSIP_ITEM(3, "Kun-Lai Summit", GOSSIP_SENDER_MAIN, 24);
				  plr->ADD_GOSSIP_ITEM(3, "Dread Wastes", GOSSIP_SENDER_MAIN, 25);
				  plr->ADD_GOSSIP_ITEM(3, "Jade Forest", GOSSIP_SENDER_MAIN, 26);
				  plr->SEND_GOSSIP_MENU(plr->GetGossipTextId(npc), npc->GetGUID());
				  break;
		}
		case 9:
		{
				  plr->ADD_GOSSIP_ITEM(3, "Timeless Isle", GOSSIP_SENDER_MAIN, 27);
				  plr->ADD_GOSSIP_ITEM(3, "Isle of Thunder", GOSSIP_SENDER_MAIN, 28);
				  plr->ADD_GOSSIP_ITEM(3, "Isle of Giants", GOSSIP_SENDER_MAIN, 29);
				  plr->SEND_GOSSIP_MENU(plr->GetGossipTextId(npc), npc->GetGUID());
				  break;
		}
		case 10:
		{
				   plr->TeleportTo(1, 1495.460083f, -4416.675781f, 23.841143f, 0.0f);
				   plr->CLOSE_GOSSIP_MENU();
				   break;
		}
		case 11:
		{
				   plr->TeleportTo(0, 1584.07f, 241.987f, -52.1534f, 0.049647f);
				   plr->CLOSE_GOSSIP_MENU();
				   break;
		}
		case 12:
		{
				   plr->TeleportTo(530, 9487.69f, -7279.2f, 14.2866f, 6.16478f);
				   plr->CLOSE_GOSSIP_MENU();
				   break;
		}
		case 13:
		{
				   plr->TeleportTo(1, -1277.37f, 124.804f, 131.287f, 5.22274f);
				   plr->CLOSE_GOSSIP_MENU();
				   break;
		}
		case 14:
		{
				   plr->TeleportTo(0, -8913.23f, 554.633f, 93.7944f, 0.0f);
				   plr->CLOSE_GOSSIP_MENU();
				   break;
		}
		case 15:
		{
				   plr->TeleportTo(1, 9949.56f, 2284.21f, 1341.4f, 1.59587f);
				   plr->CLOSE_GOSSIP_MENU();
				   break;
		}
		case 16:
		{
				   plr->TeleportTo(530, -3965.7f, -11653.6f, -138.844f, 0.852154f);
				   plr->CLOSE_GOSSIP_MENU();
				   break;
		}
		case 17:
		{
				   plr->TeleportTo(0, -5040.5f, -814.817f, 495.128f, 5.49652f);
				   plr->CLOSE_GOSSIP_MENU();
				   break;
		}
		case 18:
		{
				   plr->TeleportTo(530, -1838.16f, 5301.79f, -12.428f, 5.9517f);
				   plr->CLOSE_GOSSIP_MENU();
				   break;
		}
		case 19:
		{
				   plr->TeleportTo(530, 3830.23f, 3426.5f, 88.6145f, 5.16677f);
				   plr->CLOSE_GOSSIP_MENU();
				   break;
		}
		case 20:
		{
				   plr->TeleportTo(530, -249.429962f, 965.476685f, 84.335533f, 1.541424f);
				   plr->CLOSE_GOSSIP_MENU();
				   break;
		}
		case 21:
		{
				   plr->TeleportTo(530, -54.8621f, 5813.44f, 20.9764f, 0.081722f);
				   plr->CLOSE_GOSSIP_MENU();
				   break;
		}
		case 22:
		{
				   plr->TeleportTo(870, 830.350403f, 329.914886f, 503.099915f, 5.831141f);
				   plr->CLOSE_GOSSIP_MENU();
				   break;
		}
		case 23:
		{
				   plr->TeleportTo(870, 1630.452881f, 870.750427f, 470.600433f, 2.245020f);
				   plr->CLOSE_GOSSIP_MENU();
				   break;
		}
		case 24:
		{
				   plr->TeleportTo(870, 3053.692871f, 797.803589f, 529.378174f, 0.044326f);
				   plr->CLOSE_GOSSIP_MENU();
				   break;
		}
		case 25:
		{
				   plr->TeleportTo(870, 170.377182f, 3286.143799f, 215.481918f, 5.031626f);
				   plr->CLOSE_GOSSIP_MENU();
				   break;
		}
		case 26:
		{
				   plr->TeleportTo(870, 2444.329346f, -2406.259277f, 130.002411f, 2.476722f);
				   plr->CLOSE_GOSSIP_MENU();
				   break;
		}
		case 27:
		{
				   plr->TeleportTo(870, -650.070251f, -4749.848633f, 2.057746f, 4.712743f);
				   plr->CLOSE_GOSSIP_MENU();
				   break;
		}
		case 28:
		{
				   plr->TeleportTo(1064, 6549.56f, 5134.81f, 59.3f, 0.680899f);
				   plr->CLOSE_GOSSIP_MENU();
				   break;
		}
		case 29:
		{
				   plr->TeleportTo(870, 5762.377930f, 999.195374f, 39.033752f, 0.110310f);
				   plr->CLOSE_GOSSIP_MENU();
				   break;
		}
		case 30:
		{
				   plr->TeleportTo(1, 16226.2f, 16257.0f, 13.2022f, 1.65007f);
				   plr->CLOSE_GOSSIP_MENU();
				   break;
		}
		case 31:
		{
				   plr->CLOSE_GOSSIP_MENU();
				   break;
		}
		case 32:
		{
				  plr->ADD_GOSSIP_ITEM(3, "Alliance", GOSSIP_SENDER_MAIN, 33);
				  plr->ADD_GOSSIP_ITEM(3, "Horde", GOSSIP_SENDER_MAIN, 34);
				  plr->SEND_GOSSIP_MENU(plr->GetGossipTextId(npc), npc->GetGUID());
				  break;
		}
		case 33:
		{
			
				   //plr->SetRace(25);
				   plr->LearnSpell(668, false);
				   plr->LearnSpell(108127, false);
				   plr->CLOSE_GOSSIP_MENU();
				   break;
		}
		case 34:
		{
				   //plr->SetRace(26);
				   plr->LearnSpell(669, false);
				   plr->LearnSpell(108127, false);
				   plr->CLOSE_GOSSIP_MENU();
				   break;
		}
		case 35:
		{
				   plr->TeleportTo(571, 5804.15f, 624.771f, 647.767f, 1.64f);
				   plr->CLOSE_GOSSIP_MENU();
				   break;
		}
		case 36:
		{
				   plr->TeleportTo(571, 7253.64f, 1644.78f, 433.68f, 4.83412f);
				   plr->CLOSE_GOSSIP_MENU();
				   break;
		}
		case 37:
		{
				   plr->TeleportTo(571, 3256.57f, 5278.23f, 40.8046f, 0.246367f);
				   plr->CLOSE_GOSSIP_MENU();
				   break;
		}
		case 38:
		{
				   plr->TeleportTo(571, 1902.15f, -4883.91f, 171.363f, 3.11537f);
				   plr->CLOSE_GOSSIP_MENU();
				   break;
		}
		case 39:
		{
				   plr->TeleportTo(646, 915.004f, 503.842f, -49.23f, 0.196921f);
				   plr->CLOSE_GOSSIP_MENU();
				   break;
		}
		case 40:
		{
				   plr->TeleportTo(1, 5075.760f, -3201.270f, 1889.44f, 1.41445f);
				   plr->CLOSE_GOSSIP_MENU();
				   break;
		}
		case 41:
		{
				   plr->TeleportTo(1, -9574.83f, -924.954f, 100.272f, 3.13119f);
				   plr->CLOSE_GOSSIP_MENU();
				   break;
		}
		case 42:
		{
				   plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
				   plr->CLOSE_GOSSIP_MENU();
				   break;
		}

		case 43:
		{
			std::string memberName = "imba";
			/*TC_LOG_ERROR("sql.sql", "%s", memberName);
			TC_LOG_INFO("sql.sql", "%s", memberName);
			TC_LOG_DEBUG("sql.sql", "%s", memberName);*/
			TC_LOG_ERROR("server.worldserver", "%s", memberName);
			TC_LOG_INFO("server.worldserver", "%s", memberName);
			TC_LOG_DEBUG("server.worldserver", "%s", memberName);
				   plr->CLOSE_GOSSIP_MENU();
				   break;
		}
		case 44:
		{
			plr->ADD_GOSSIP_ITEM(3, "Ashran", GOSSIP_SENDER_MAIN, 47);
			plr->ADD_GOSSIP_ITEM(3, "Frostfire Ridge", GOSSIP_SENDER_MAIN, 48);
			plr->ADD_GOSSIP_ITEM(3, "Nagrand", GOSSIP_SENDER_MAIN, 49);
			plr->ADD_GOSSIP_ITEM(3, "Shadowmoon Valley", GOSSIP_SENDER_MAIN, 50);
			plr->SEND_GOSSIP_MENU(plr->GetGossipTextId(npc), npc->GetGUID());
			break;
		}
		case 45:
		{
			plr->ADD_GOSSIP_ITEM(3, "Classic", GOSSIP_SENDER_MAIN, 51);
			if (plr->getLevel() > 69)
				plr->ADD_GOSSIP_ITEM(3, "The Burning Crusade", GOSSIP_SENDER_MAIN, 52);
			if (plr->getLevel() > 79)
				plr->ADD_GOSSIP_ITEM(3, "Wrath of the Lich King", GOSSIP_SENDER_MAIN, 53);
			if (plr->getLevel() > 84)
				plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 54);
			if (plr->getLevel() > 89)
				plr->ADD_GOSSIP_ITEM(3, "Mists of Pandaria", GOSSIP_SENDER_MAIN, 55);
			if (plr->getLevel() > 99)
				plr->ADD_GOSSIP_ITEM(3, "Warlords of Draenor", GOSSIP_SENDER_MAIN, 56);
			plr->SEND_GOSSIP_MENU(plr->GetGossipTextId(npc), npc->GetGUID());
			break;
		}
		case 46:
		{
			plr->ADD_GOSSIP_ITEM(3, "Classic", GOSSIP_SENDER_MAIN, 57);
			if (plr->getLevel() > 59)
				plr->ADD_GOSSIP_ITEM(3, "The Burning Crusade", GOSSIP_SENDER_MAIN, 58);
			if (plr->getLevel() > 69)
				plr->ADD_GOSSIP_ITEM(3, "Wrath of the Lich King", GOSSIP_SENDER_MAIN, 59);
			if (plr->getLevel() > 79)
				plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 60);
			if (plr->getLevel() > 84)
				plr->ADD_GOSSIP_ITEM(3, "Mists of Pandaria", GOSSIP_SENDER_MAIN, 61);
			if (plr->getLevel() > 89)
				plr->ADD_GOSSIP_ITEM(3, "Warlords of Draenor", GOSSIP_SENDER_MAIN, 62);
			plr->SEND_GOSSIP_MENU(plr->GetGossipTextId(npc), npc->GetGUID());
			break;
		}
		case 47:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}
		case 48:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}
		case 49:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}
		case 50:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}
		case 51:
		{
			plr->ADD_GOSSIP_ITEM(3, "Blackwing Lair", GOSSIP_SENDER_MAIN, 63);
			plr->ADD_GOSSIP_ITEM(3, "Molten Core", GOSSIP_SENDER_MAIN, 64);
			plr->ADD_GOSSIP_ITEM(3, "Ruins of Ahn'Qiraj", GOSSIP_SENDER_MAIN, 65);
			plr->ADD_GOSSIP_ITEM(3, "Temple of Ahn'Qiraj", GOSSIP_SENDER_MAIN, 66);
			plr->SEND_GOSSIP_MENU(plr->GetGossipTextId(npc), npc->GetGUID());
			break;
		}
		case 52:
		{
			plr->ADD_GOSSIP_ITEM(3, "Black Temple", GOSSIP_SENDER_MAIN, 67);
			plr->ADD_GOSSIP_ITEM(3, "Gruul's Lair", GOSSIP_SENDER_MAIN, 68);
			plr->ADD_GOSSIP_ITEM(3, "Hyjal Summit", GOSSIP_SENDER_MAIN, 69);
			plr->ADD_GOSSIP_ITEM(3, "Karazhan", GOSSIP_SENDER_MAIN, 70);
			plr->ADD_GOSSIP_ITEM(3, "Magtheridon's Lair", GOSSIP_SENDER_MAIN, 71);
			plr->ADD_GOSSIP_ITEM(3, "Serpentshrine Cavern", GOSSIP_SENDER_MAIN, 72);
			plr->ADD_GOSSIP_ITEM(3, "Sunwell Plateau", GOSSIP_SENDER_MAIN, 73);
			plr->ADD_GOSSIP_ITEM(3, "The Eye", GOSSIP_SENDER_MAIN, 74);
			plr->SEND_GOSSIP_MENU(plr->GetGossipTextId(npc), npc->GetGUID());
			break;
		}
		case 53:
		{
			plr->ADD_GOSSIP_ITEM(3, "Icecrown Citadel", GOSSIP_SENDER_MAIN, 75);
			plr->ADD_GOSSIP_ITEM(3, "Naxxramas", GOSSIP_SENDER_MAIN, 76);
			plr->ADD_GOSSIP_ITEM(3, "Onyxia's Lair", GOSSIP_SENDER_MAIN, 77);
			plr->ADD_GOSSIP_ITEM(3, "The Eye of Eternity", GOSSIP_SENDER_MAIN, 78);
			plr->ADD_GOSSIP_ITEM(3, "The Obsidian Sanctum", GOSSIP_SENDER_MAIN, 79);
			plr->ADD_GOSSIP_ITEM(3, "The Ruby Sanctum", GOSSIP_SENDER_MAIN, 80);
			plr->ADD_GOSSIP_ITEM(3, "Trial of the Crusader", GOSSIP_SENDER_MAIN, 81);
			plr->ADD_GOSSIP_ITEM(3, "Ulduar", GOSSIP_SENDER_MAIN, 82);
			plr->ADD_GOSSIP_ITEM(3, "Vault of Archavon", GOSSIP_SENDER_MAIN, 83);
			plr->SEND_GOSSIP_MENU(plr->GetGossipTextId(npc), npc->GetGUID());
			break;
		}
		case 54:
		{
			plr->ADD_GOSSIP_ITEM(3, "Baradin Hold", GOSSIP_SENDER_MAIN, 84);
			plr->ADD_GOSSIP_ITEM(3, "Blackwing Descent", GOSSIP_SENDER_MAIN, 85);
			plr->ADD_GOSSIP_ITEM(3, "Dragon Soul", GOSSIP_SENDER_MAIN, 86);
			plr->ADD_GOSSIP_ITEM(3, "Firelands", GOSSIP_SENDER_MAIN, 87);
			plr->ADD_GOSSIP_ITEM(3, "The Bastion of Twilight", GOSSIP_SENDER_MAIN, 88);
			plr->ADD_GOSSIP_ITEM(3, "Throne of the Four Winds", GOSSIP_SENDER_MAIN, 89);
			plr->SEND_GOSSIP_MENU(plr->GetGossipTextId(npc), npc->GetGUID());
			break;
		}
		case 55:
		{
			plr->ADD_GOSSIP_ITEM(3, "Mogu'shan Vaults", GOSSIP_SENDER_MAIN, 90);
			plr->ADD_GOSSIP_ITEM(3, "Terrace of Endless Spring", GOSSIP_SENDER_MAIN, 91);
			plr->ADD_GOSSIP_ITEM(3, "Heart of Fear", GOSSIP_SENDER_MAIN, 92);
			plr->ADD_GOSSIP_ITEM(3, "Throne of Thunder", GOSSIP_SENDER_MAIN, 93);
			plr->ADD_GOSSIP_ITEM(3, "Siege of Orgrimmar", GOSSIP_SENDER_MAIN, 94);
			plr->SEND_GOSSIP_MENU(plr->GetGossipTextId(npc), npc->GetGUID());
			break;
		}
		case 56:
		{
			plr->ADD_GOSSIP_ITEM(3, "Highmaul", GOSSIP_SENDER_MAIN, 95);
			plr->ADD_GOSSIP_ITEM(3, "Blackrock Foundry", GOSSIP_SENDER_MAIN, 96);
			plr->SEND_GOSSIP_MENU(plr->GetGossipTextId(npc), npc->GetGUID());
			break;
		}
		case 57:
		{
			/* Classic Dungeons*/
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 97);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 98);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 99);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 100);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 101);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 102);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 103);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 104);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 105);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 106);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 107);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 108);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 109);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 110);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 111);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 112);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 113);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 114);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 115);
			plr->SEND_GOSSIP_MENU(plr->GetGossipTextId(npc), npc->GetGUID());
			break;
		}
		case 58:
		{
			/* TBC Dungeons*/
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 116);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 117);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 118);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 119);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 120);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 121);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 122);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 123);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 124);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 125);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 126);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 127);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 128);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 129);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 130);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 131);
			plr->SEND_GOSSIP_MENU(plr->GetGossipTextId(npc), npc->GetGUID());
			break;
		}
		case 59:
		{
			/* WOTLK Dungeons*/
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 132);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 133);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 134);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 135);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 136);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 137);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 138);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 139);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 140);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 141);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 142);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 143);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 144);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 145);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 146);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 147);
			plr->SEND_GOSSIP_MENU(plr->GetGossipTextId(npc), npc->GetGUID());
			break;
		}
		case 60:
		{
			/* CATA Dungeons*/
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 148);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 149);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 150);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 151);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 152);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 153);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 154);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 155);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 156);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 157);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 158);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 159);
			plr->SEND_GOSSIP_MENU(plr->GetGossipTextId(npc), npc->GetGUID());
			break;
		}
		case 61:
		{
			/* MOP Dungeons*/
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 160);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 161);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 162);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 163);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 164);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 165);
			plr->SEND_GOSSIP_MENU(plr->GetGossipTextId(npc), npc->GetGUID());
			plr->SEND_GOSSIP_MENU(plr->GetGossipTextId(npc), npc->GetGUID());
			break;
		}
		case 62:
		{
			/* WOD Dungeons*/
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 166);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 167);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 168);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 169);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 170);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 171);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 172);
			plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 173);
			plr->SEND_GOSSIP_MENU(plr->GetGossipTextId(npc), npc->GetGUID());
			break;
		}
		case 63:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 64:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 65:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 66:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 67:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 68:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 69:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 70:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 71:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 72:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 73:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 74:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 75:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 76:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 77:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 78:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 79:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 80:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 81:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 82:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 83:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 84:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 85:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 86:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 87:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 88:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 89:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 90:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 91:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 92:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 93:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 94:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 95:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 96:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 97:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 98:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 99:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 100:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 101:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 102:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 103:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 104:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 105:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 106:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 107:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 108:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 109:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 110:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 111:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 112:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 113:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 114:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 115:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 116:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 117:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 118:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 119:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 120:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 121:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 123:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 124:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 125:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 126:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 127:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 128:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 129:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 130:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 131:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 132:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 133:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 134:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 135:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 136:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 137:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 138:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 139:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 140:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 141:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 142:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 143:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 144:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 145:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 146:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 147:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 148:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 149:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 150:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 151:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 152:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 153:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 154:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 155:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 156:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 157:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 158:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 159:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 160:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 161:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 162:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 163:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 164:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 165:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 166:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 167:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 168:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 169:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 170:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 171:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 172:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}case 173:
		{
			//plr->TeleportTo(0, -3493.13f, -4912.95f, 77.1887f, 0.522433f);
			plr->CLOSE_GOSSIP_MENU();
			break;
		}
			return true;
		}
	}
};

void ADDSC_Teleporter_NPC()
{
	new Teleporter_NPC();
}