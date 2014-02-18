/*
Made by: SymboliXDEV
Edited by: Rochet2
Work %: Untested
Compile: Success
*/

#include "ScriptPCH.h"

static const uint32 buffIdstools[] = { 43223, 5862, 33377, 33779, 31305, 70692, 42995 };

class teleporter_npc : public CreatureScript
{
public:
	teleporter_npc() : CreatureScript("teleporter_npc") { }

	bool OnGossipHello(Player * player, Creature * creature)
	{
		if (player->IsInCombat())
		{
			player->GetSession()->SendNotification("You are in Combat");
			return true;
		}

		// Placeholders for teleports
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teleport 1", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teleport 2", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
		
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Buff me", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Reset my Talents", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Remove my Sickness", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Reset my CDs", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Repair Items", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Clear Combat", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Reset Instances", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
		return true;
	}

	bool OnGossipSelect(Player* player, Creature * creature, uint32 sender, uint32 actions)
	{
		player->PlayerTalkClass->ClearMenus();

		if (sender != GOSSIP_SENDER_MAIN || actions <= GOSSIP_ACTION_INFO_DEF)
		{
			player->CLOSE_GOSSIP_MENU();
			return true;
		}

		switch (actions)
		{
		case GOSSIP_ACTION_INFO_DEF + 2:
			player->TeleportTo(1, 6457.238281f, -4244.459473f, 667.190369f, 1.446752f);
			player->CLOSE_GOSSIP_MENU();
			return true;

		case GOSSIP_ACTION_INFO_DEF + 1:
			player->TeleportTo(0, 0.0f, 0.0f, 0.0f, 0.0f);
			player->CLOSE_GOSSIP_MENU();
			return true;

		case GOSSIP_ACTION_INFO_DEF + 3:
			for (int i = 0; i < sizeof(buffIdstools) / sizeof(*buffIdstools); ++i)
				player->CastSpell(player, buffIdstools[i]);
			break;

		case GOSSIP_ACTION_INFO_DEF + 4: // Reset Talents
			player->resetTalents(true);
			player->SendTalentsInfoData(false);
			player->GetSession()->SendAreaTriggerMessage("Your talents has been reset.", player->GetGUID(), true);
			break;

		case GOSSIP_ACTION_INFO_DEF + 5: // Remove my siccness
			if (player->HasAura(15007))
				player->RemoveAura(15007);
			break;

		case GOSSIP_ACTION_INFO_DEF + 6: // reset my CD'S
			player->SetFullHealth();
			player->SetPower(POWER_MANA, player->GetMaxPower(POWER_MANA));
			player->RemoveAllSpellCooldown();
			break;

		case GOSSIP_ACTION_INFO_DEF + 7: // repair my items
			player->DurabilityRepairAll(false, 0.0f, false);
			break;

		case GOSSIP_ACTION_INFO_DEF + 8: // Clear Combat
			player->CombatStop();
			break;

		case GOSSIP_ACTION_INFO_DEF + 9: // Reset all Instances For PvE 
			for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
			{
				Player::BoundInstancesMap &binds = player->GetBoundInstances(Difficulty(i));
				for (Player::BoundInstancesMap::iterator itr = binds.begin(); itr != binds.end();)
				{
					player->UnbindInstance(itr, Difficulty(i));
				}
			}
			break;

		default: // Close
			player->CLOSE_GOSSIP_MENU();
			return true;
		}

		OnGossipHello(player, creature);
		return true;
	}
};

void AddSC_teleporter_npc()
{
	new teleporter_npc;
}