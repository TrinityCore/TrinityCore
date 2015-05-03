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
		plr->ADD_GOSSIP_ITEM(3, "Outland", GOSSIP_SENDER_MAIN, 5);
		
		plr->ADD_GOSSIP_ITEM(3, "Nothrend", GOSSIP_SENDER_MAIN, 6);
		plr->ADD_GOSSIP_ITEM(3, "Cataclysm", GOSSIP_SENDER_MAIN, 7);
		plr->ADD_GOSSIP_ITEM(3, "Pandaria", GOSSIP_SENDER_MAIN, 8);
		plr->ADD_GOSSIP_ITEM(3, "Isles", GOSSIP_SENDER_MAIN, 9);
		if (plr->IsGameMaster())
		{
			plr->ADD_GOSSIP_ITEM(3, "GMIsland", GOSSIP_SENDER_MAIN, 30);
		}
		if (plr->getRace() == 24)
		{
			plr->ADD_GOSSIP_ITEM(3, "Choose Faction...", GOSSIP_SENDER_MAIN, 32);
		}
		plr->ADD_GOSSIP_ITEM(3, "Language Fix", GOSSIP_SENDER_MAIN, 43);
		plr->ADD_GOSSIP_ITEM(3, "Nevermind...", GOSSIP_SENDER_MAIN, 31);
		plr->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, npc->GetGUID());
		
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
				  plr->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, npc->GetGUID());
				  break;
		}
		case 4:
		{
				  plr->ADD_GOSSIP_ITEM(3, "Stormwind", GOSSIP_SENDER_MAIN, 14);
				  plr->ADD_GOSSIP_ITEM(3, "Darnassus", GOSSIP_SENDER_MAIN, 15);
				  plr->ADD_GOSSIP_ITEM(3, "Exodar", GOSSIP_SENDER_MAIN, 16);
				  plr->ADD_GOSSIP_ITEM(3, "Ironforge", GOSSIP_SENDER_MAIN, 17);
				  plr->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, npc->GetGUID());
				  break;
		}
		case 5:
		{
				  plr->ADD_GOSSIP_ITEM(3, "Shattrath City", GOSSIP_SENDER_MAIN, 18);
				  plr->ADD_GOSSIP_ITEM(3, "Netherstorm", GOSSIP_SENDER_MAIN, 19);
				  plr->ADD_GOSSIP_ITEM(3, "Dark Portal", GOSSIP_SENDER_MAIN, 20);
				  plr->ADD_GOSSIP_ITEM(3, "Zangarmarsh", GOSSIP_SENDER_MAIN, 21);
				  plr->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, npc->GetGUID());
				  break;
		}
		case 6:
		{
				  plr->ADD_GOSSIP_ITEM(3, "Dalaran", GOSSIP_SENDER_MAIN, 35);
				  plr->ADD_GOSSIP_ITEM(3, "Icecrown", GOSSIP_SENDER_MAIN, 36);
				  plr->ADD_GOSSIP_ITEM(3, "Borean Tundra", GOSSIP_SENDER_MAIN, 37);
				  plr->ADD_GOSSIP_ITEM(3, "Howling Fjord", GOSSIP_SENDER_MAIN, 38);
				  plr->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, npc->GetGUID());
				  break;
		}
		case 7:
		{
				  plr->ADD_GOSSIP_ITEM(3, "Deepholm", GOSSIP_SENDER_MAIN, 39);
				  plr->ADD_GOSSIP_ITEM(3, "Mount Hyjal", GOSSIP_SENDER_MAIN, 40);
				  plr->ADD_GOSSIP_ITEM(3, "Uldum", GOSSIP_SENDER_MAIN, 41);
				  plr->ADD_GOSSIP_ITEM(3, "Twilight Highlands", GOSSIP_SENDER_MAIN, 42);
				  plr->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, npc->GetGUID());
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
				  plr->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, npc->GetGUID());
				  break;
		}
		case 9:
		{
				  plr->ADD_GOSSIP_ITEM(3, "Timeless Isle", GOSSIP_SENDER_MAIN, 27);
				  plr->ADD_GOSSIP_ITEM(3, "Isle of Thunder", GOSSIP_SENDER_MAIN, 28);
				  plr->ADD_GOSSIP_ITEM(3, "Isle of Giants", GOSSIP_SENDER_MAIN, 29);
				  plr->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, npc->GetGUID());
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
				  plr->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, npc->GetGUID());
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
				   plr->LearnSpell(668, 0);
				   plr->LearnSpell(669, 0);
				   plr->LearnSpell(668, 1);
				   plr->LearnSpell(669, 1);
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