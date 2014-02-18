/*
* GOSSIP_ICON_CHAT                = 0      White chat bubble
* GOSSIP_ICON_VENDOR              = 1      Brown bag
* GOSSIP_ICON_TAXI                = 2      Flight
* GOSSIP_ICON_TRAINER             = 3      Book
* GOSSIP_ICON_INTERACT_1          = 4      Interaction wheel
* GOSSIP_ICON_INTERACT_2          = 5      Interaction wheel
* GOSSIP_ICON_MONEY_BAG           = 6      Brown bag with yellow dot
* GOSSIP_ICON_TALK                = 7      White chat bubble with black dots
* GOSSIP_ICON_TABARD              = 8      Tabard
* GOSSIP_ICON_BATTLE              = 9      Two swords
* GOSSIP_ICON_DOT                 = 10     Yellow dot
* GOSSIP_ICON_CHAT_11             = 11,    White chat bubble
* GOSSIP_ICON_CHAT_12             = 12,    White chat bubble
* GOSSIP_ICON_CHAT_13             = 13,    White chat bubble
* GOSSIP_ICON_UNK_14              = 14,    INVALID - DO NOT USE
* GOSSIP_ICON_UNK_15              = 15,    INVALID - DO NOT USE
* GOSSIP_ICON_CHAT_16             = 16,    White chat bubble
* GOSSIP_ICON_CHAT_17             = 17,    White chat bubble
* GOSSIP_ICON_CHAT_18             = 18,    White chat bubble
* GOSSIP_ICON_CHAT_19             = 19,    White chat bubble
* GOSSIP_ICON_CHAT_20             = 20,    White chat bubble
*/

#include "ScriptPCH.h"
#include "Config.h"

#define EMOTE_FUNCTION_OFF "Function Disable!"

enum MenuStructure
{
	MAIN_MENU      = 1,
	MORPH_MENU     = 2,
	SCALE_MENU	   = 3,
};

enum Actions
{
	// Morph Actions
	ACTION_NAGA_LORD	                 = 10,
	ACTION_WORGEN                        = 11,
	ACTION_PANDAREN_MONK                 = 12,
	ACTION_ALGALON                       = 13,
	ACTION_RUARZOG						 = 14,
	ACTION_DEMORPH                       = 15,
	ACTION_UNDEAD_MASKED                 = 16,
	ACTION_SCARY_DWARF                   = 17,
	ACTION_UNDEAD_SHADES                 = 18,
	ACTION_VIKING                        = 19,
	ACTION_MINOTAUR                      = 20,
	ACTION_LICHKING                      = 21,

	// Scaled Actions
	ACTION_SCALE_VRYKUL_DEFAULT			 = 23,
	ACTION_SCALE_ONE					 = 24,
	ACTION_SCALE_TWO					 = 25,
	ACTION_SCALE_THREE					 = 26,
	ACTION_SCALE_FOUR					 = 27,
	ACTION_SCALE_FIVE					 = 28,
	ACTION_SCALE_ALGALON_FIX			 = 29,
};

enum DisplayId
{
	DISPLAY_ID_NAGA_LORD              = 13031, // Set Scale 0.55
	DISPLAY_ID_WORGEN                 = 657,   // set Scale 1.25
	DISPLAY_ID_PANDAREN_MONK          = 30414, // set Scale 4
	DISPLAY_ID_ALGALON                = 28641, // Set Scale 0.25
	DISPLAY_ID_RUARZOG				  =	25514, // Set Scale 0.75
	DISPLAY_ID_UNDEAD_MASKED		  =	21752, // set Scale 1
	DISPLAY_ID_SCARY_DWARF			  =	21824, // Set Scale 1.25
	DISPLAY_ID_UNDEAD_SHADES		  =	21959, // set Scale 1
	DISPLAY_ID_VIKING     			  =	21997, // Set Scale 0.75
	DISPLAY_ID_MINOTAUR				  =	22007, // Set Scale 0.80
	DISPLAY_ID_LICHKING				  =	22234, // Set Scale 2
};

class npc_morpher : public CreatureScript
{
public:
	npc_morpher() : CreatureScript("npc_morpher") { }

	bool OnGossipHello(Player* player, Creature* creature)
	{
		player->PlayerTalkClass->ClearMenus();

		if (sConfigMgr->GetBoolDefault("Server.Morpher.Enable", true))
		{
			player->PlayerTalkClass->ClearMenus();
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TABARD, "Morph Menu ->", GOSSIP_SENDER_MAIN, MORPH_MENU);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Scale Menu ->", GOSSIP_SENDER_MAIN, SCALE_MENU);
			player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
			return true;
		}
		return true;
	}

	bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
	{
		player->PlayerTalkClass->ClearMenus();

		switch (action)
		{
		case MORPH_MENU:
			if (sConfigMgr->GetBoolDefault("Permanent.Morph.Menu.Enable", true))
			{
				player->PlayerTalkClass->ClearMenus();
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Naga Lord", GOSSIP_SENDER_MAIN, ACTION_NAGA_LORD);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Worgen", GOSSIP_SENDER_MAIN, ACTION_WORGEN);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Pandaren Monk", GOSSIP_SENDER_MAIN, ACTION_PANDAREN_MONK);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Algalon", GOSSIP_SENDER_MAIN, ACTION_ALGALON);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Boss Ruarzog", GOSSIP_SENDER_MAIN, ACTION_RUARZOG);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Undead Masked", GOSSIP_SENDER_MAIN, ACTION_UNDEAD_MASKED);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Scary Dwarf", GOSSIP_SENDER_MAIN, ACTION_SCARY_DWARF);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Undead Shades", GOSSIP_SENDER_MAIN, ACTION_UNDEAD_SHADES);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Viking", GOSSIP_SENDER_MAIN, ACTION_VIKING);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Minotaur", GOSSIP_SENDER_MAIN, ACTION_MINOTAUR);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Lich King", GOSSIP_SENDER_MAIN, ACTION_LICHKING);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "[Demorph] Logout for Effect!!!", GOSSIP_SENDER_MAIN, ACTION_DEMORPH);
				player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,creature->GetGUID());
				return true;
			}
			else
			{
				player->CLOSE_GOSSIP_MENU();
				creature->MonsterTextEmote(EMOTE_FUNCTION_OFF, 0, true);
			}
			break;

		case ACTION_NAGA_LORD:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_NAGA_LORD);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 13031);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 0.55, 'Naga Lord');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.75f);
			break;

		case ACTION_WORGEN:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_WORGEN);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 657);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 2, 'Worgen');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 2);
			break;

		case ACTION_PANDAREN_MONK:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_PANDAREN_MONK);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 30414);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 4, 'Panda');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 4);
			break;

		case ACTION_ALGALON:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_ALGALON);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 28641);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 0.25, 'Alfalon');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.25f);
			break;

		case ACTION_RUARZOG:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_RUARZOG);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 25514);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 0.8, 'Ruarzog');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.8f);
			break;

		case ACTION_UNDEAD_MASKED:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_UNDEAD_MASKED);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 21752);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 1, 'Undead Masked');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1);
			break;

		case ACTION_SCARY_DWARF:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_SCARY_DWARF);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 21824);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 1.25, 'Scary Dwarf');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.25f);
			break;

		case ACTION_UNDEAD_SHADES:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_UNDEAD_SHADES);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 21959);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 1, 'Undead Shades');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1);
			break;

		case ACTION_VIKING:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_VIKING);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 21997);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 0.75, 'Viking');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.75f);
			break;

		case ACTION_MINOTAUR:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_MINOTAUR);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 22007);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 0.8, 'Minotaur');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.8f);
			break;

		case ACTION_LICHKING:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_LICHKING);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 22234);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 2, 'Lich King');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 2);
			break;

		case ACTION_DEMORPH:
			player->CLOSE_GOSSIP_MENU();
			player->DeMorph();
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 1, 'Player Default');", player->GetGUID());
			}
			break;

		case SCALE_MENU:
			if (sConfigMgr->GetBoolDefault("Permanent.Scale.Menu.Enable", true))
			{
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Set my Scale to One", GOSSIP_SENDER_MAIN, ACTION_SCALE_ONE);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Set my Scale to Two", GOSSIP_SENDER_MAIN, ACTION_SCALE_TWO);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Set my Scale to Three", GOSSIP_SENDER_MAIN, ACTION_SCALE_THREE);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Set my Scale to Four", GOSSIP_SENDER_MAIN, ACTION_SCALE_FOUR);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Set my Scale to Five", GOSSIP_SENDER_MAIN, ACTION_SCALE_FIVE);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "Vrykul Default Scale", GOSSIP_SENDER_MAIN, ACTION_SCALE_VRYKUL_DEFAULT);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "ALGALON Scale Fixer", GOSSIP_SENDER_MAIN, ACTION_SCALE_ALGALON_FIX);
				player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,creature->GetGUID());
				return true;
			}
			else
			{
				player->CLOSE_GOSSIP_MENU();
				creature->MonsterTextEmote(EMOTE_FUNCTION_OFF, 0, true);
			}
			break;

		case ACTION_SCALE_ONE:
			player->CLOSE_GOSSIP_MENU();
			{
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 1, 'Scaled One');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1);
			break;

		case ACTION_SCALE_TWO:
			player->CLOSE_GOSSIP_MENU();
			{
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 2, 'Scaled Two');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 2);
			break;

		case ACTION_SCALE_THREE:
			player->CLOSE_GOSSIP_MENU();
			{
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 3, 'Scaled Three');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 3);
			break;

		case ACTION_SCALE_FOUR:
			player->CLOSE_GOSSIP_MENU();
			{
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 4, 'Scaled Four');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 4);
			break;

		case ACTION_SCALE_FIVE:
			player->CLOSE_GOSSIP_MENU();
			{
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 5, 'Scaled Five');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 5);
			break;

		case ACTION_SCALE_VRYKUL_DEFAULT:
			player->CLOSE_GOSSIP_MENU();
			{
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 0.8, 'Vrykul Default');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.8f);
			break;

		case ACTION_SCALE_ALGALON_FIX:
			player->CLOSE_GOSSIP_MENU();
			{
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 0.25, 'Alagon Fix');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.25f);
			break;

		case MAIN_MENU:
			OnGossipHello(player, creature);
			break;
		}
		return true;
	}
};

void AddSC_npc_morpher()
{
	new npc_morpher();
}