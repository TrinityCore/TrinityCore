/////////////////////////////
//    World Chat           //
//  Made By Quadral        //
//                         //
//  Updated By Obitus      //
// on February 18th, 2016  //
//  Tested on 3.3.5a       //
/////////////////////////////
/*
__________________________________________________________________
-- WORLD DATABASE
INSERT INTO `command`(`name`,`permission`,`help`)
VALUES ('chat',1009,'Syntax:Use .chat to speak in worldchat!');
__________________________________________________________________

-- AUTH DATABASE
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(1009, 'Command: chat');

INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES
(195, 1009);
__________________________________________________________________

RBAC.h
RBAC_PERM_COMMAND_MODIFY_XP                              = 798,
// 799 - 834 6.x only
RBAC_PERM_COMMAND_DEBUG_LOADCELLS                        = 835,
RBAC_PERM_COMMAND_DEBUG_BOUNDARY                         = 836,

//Custom stuff                                                                                                          
RBAC_PERM_COMMAND_CUSTOM_CHAT							 = 1009,    //Add This Line to RBAC.h

// custom permissions 1000+
RBAC_PERM_MAX
___________________________________________________________________
*/

#include "ScriptMgr.h"
#include "Player.h"
#include "WorldSession.h"
#include "Chat.h"

#define MSG_COLOR_BLUEVIOLET "|cFF8A2BE2"
const char* CLASS_ICON;
const char* RACE_ICON;

#define FACTION_SPECIFIC 0


std::string GetNameLink(Player* player)
{
	std::string name = player->GetName();
	std::string color;

	switch (player->getRace())
	{
		// Done - Bloodelf
	case RACE_BLOODELF:
		if (player->getGender() == GENDER_MALE)
			RACE_ICON = "|TInterface/ICONS/Achievement_Character_Bloodelf_Male:15|t";
		else
			RACE_ICON = "|TInterface/ICONS/Achievement_Character_Bloodelf_Female:15|t";
		break;
		// Done - Dranei
	case RACE_DRAENEI:
		if (player->getGender() == GENDER_FEMALE)
			RACE_ICON = "|TInterface/ICONS/Achievement_Character_Draenei_Female:15|t";
		else
			RACE_ICON = "|TInterface/ICONS/Achievement_Character_Draenei_Male:15|t";
		break;
	case RACE_DWARF:
		if (player->getGender() == GENDER_FEMALE)
			RACE_ICON = "|TInterface/ICONS/Achievement_Character_Dwarf_Female:15|t";
		else
			RACE_ICON = "|TInterface/ICONS/Achievement_Character_Dwarf_Male:15|t";
		break;
		// Done - Gnome
	case RACE_GNOME:
		if (player->getGender() == GENDER_FEMALE)
			RACE_ICON = "|TInterface/ICONS/Achievement_Character_Gnome_Female:15|t";
		else
			RACE_ICON = "|TInterface/ICONS/Achievement_Character_Gnome_Male:15|t";
		break;
		// Done - Human
	case RACE_HUMAN:
		if (player->getGender() == GENDER_FEMALE)
			RACE_ICON = "|TInterface/ICONS/Achievement_Character_Human_Female:15|t";
		else
			RACE_ICON = "|TInterface/ICONS/Achievement_Character_Human_Male:15|t";
		break;
	case RACE_NIGHTELF:
		if (player->getGender() == GENDER_FEMALE)
			RACE_ICON = "|TInterface/ICONS/Achievement_Character_Nightelf_Female:15|t";
		else
			RACE_ICON = "|TInterface/ICONS/Achievement_Character_Nightelf_Male:15|t";
		break;
	case RACE_ORC:
		if (player->getGender() == GENDER_FEMALE)
			RACE_ICON = "|TInterface/ICONS/Achievement_Character_Orc_Female:15|t";
		else
			RACE_ICON = "|TInterface/ICONS/Achievement_Character_Orc_Male:15|t";
		break;
		// Done - Tauren
	case RACE_TAUREN:
		if (player->getGender() == GENDER_FEMALE)
			RACE_ICON = "|TInterface/ICONS/Achievement_Character_Tauren_Female:15|t";
		else
			RACE_ICON = "|TInterface/ICONS/Achievement_Character_Tauren_Male:15|t";
		break;
	case RACE_TROLL:
		if (player->getGender() == GENDER_FEMALE)
			RACE_ICON = "|TInterface/ICONS/Achievement_Character_Troll_Female:15|t";
		else
			RACE_ICON = "|TInterface/ICONS/Achievement_Character_Troll_Male:15|t";
		break;
	case RACE_UNDEAD_PLAYER:
		if (player->getGender() == GENDER_FEMALE)
			RACE_ICON = "|TInterface/ICONS/Achievement_Character_Undead_Female:15|t";
		else
			RACE_ICON = "|TInterface/ICONS/Achievement_Character_Undead_Male:15|t";
		break;
	}

	switch (player->getClass())
	{
	case CLASS_DEATH_KNIGHT:
		color = "|cffC41F3B";
		//CLASS_ICON = "|TInterface\\icons\\Spell_Deathknight_ClassIcon:15|t|r";
		break;
	case CLASS_DRUID:
		color = "|cffFF7D0A";
		//CLASS_ICON = "|TInterface\\icons\\Ability_Druid_Maul:15|t|r";
		break;
	case CLASS_HUNTER:
		color = "|cffABD473";
		//CLASS_ICON = "|TInterface\\icons\\INV_Weapon_Bow_07:15|t|r";
		break;
	case CLASS_MAGE:
		color = "|cff69CCF0";
		//CLASS_ICON = "|TInterface\\icons\\INV_Staff_13:15|t|r";
		break;
	case CLASS_PALADIN:
		color = "|cffF58CBA";
		//CLASS_ICON = "|TInterface\\icons\\INV_Hammer_01:15|t|r";
		break;
	case CLASS_PRIEST:
		color = "|cffFFFFFF";
		//CLASS_ICON = "|TInterface\\icons\\INV_Staff_30:15|t|r";
		break;
	case CLASS_ROGUE:
		color = "|cffFFF569";
		//CLASS_ICON = "|TInterface\\icons\\INV_ThrowingKnife_04:15|t|r";
		break;
	case CLASS_SHAMAN:
		color = "|cff0070DE";
		//CLASS_ICON = "|TInterface\\icons\\Spell_Nature_BloodLust:15|t|r";
		break;
	case CLASS_WARLOCK:
		color = "|cff9482C9";
		//CLASS_ICON = "|TInterface\\icons\\Spell_Nature_FaerieFire:15|t|r";
		break;
	case CLASS_WARRIOR:
		color = "|cffC79C6E";
		//CLASS_ICON = "|TInterface\\icons\\INV_Sword_27.png:15|t|r";
		break;
	}
	return "|Hplayer:" + name + "|h" + RACE_ICON + CLASS_ICON + "|cffFFFFFF[" + color + name + "|cffFFFFFF]|h|r";
}

class cs_world_chat : public CommandScript
{
public:
	cs_world_chat() : CommandScript("cs_world_chat") {}

	std::vector<ChatCommand> GetCommands() const override
	{
		static std::vector<ChatCommand> WorldChatCommandTable =
		{
			{ "chat", rbac::RBAC_PERM_COMMAND_CUSTOM_CHAT, false, &HandleWorldChatCommand, "" },
		};

		return WorldChatCommandTable;
	}

	static bool HandleWorldChatCommand(ChatHandler * handler, const char * args)
	{

		if (!handler->GetSession()->GetPlayer()->CanSpeak())
			return false;
		std::string temp = args;

		if (!args || temp.find_first_not_of(' ') == std::string::npos)
			return false;


		std::string msg = "";
		Player * player = handler->GetSession()->GetPlayer();

		switch (player->GetSession()->GetSecurity())
		{
			// Player
		case SEC_PLAYER:
			if (player->GetTeam() == ALLIANCE)
			{
				msg += "|cff00ff00[World]";
				msg += "|cfffa9900[Player]";
				msg += "|cff0000ff|TInterface\\pvpframe\\pvp-currency-alliance:15|t";
				msg += GetNameLink(player);
				msg += ": |cffffffff";
			}

			else //Horde
			{
				msg += "|cff00ff00[World]";
				msg += "|cfffa9900[Player]";
				msg += "|cffff0000|TInterface\\pvpframe\\pvp-currency-horde:16|t";
				msg += GetNameLink(player);
				msg += ": |cffffffff";
			}
			break;
			// VIP PLAYER
			/*
			case SEC_VIP_PLAYER:
			if (player->GetTeam() == ALLIANCE)
			{
			msg += "|cff00ff00[World] ";
			msg += "|cffff8a00[VIP]";
			msg += "|cff0000ff|TInterface\\pvpframe\\pvp-currency-alliance:17|t|r ";
			msg += GetNameLink(player);
			msg += ": |cfffaeb00";
			}

			else
			{

			msg += "|cff00ff00[World] ";
			msg += "|cffff8a00[VIP]";
			msg += "|cffff0000|TInterface\\pvpframe\\pvp-currency-horde:17|t|r ";
			msg += GetNameLink(player);
			msg += ": |cfffaeb00";
			}
			break;
			*/
			// Moderator/trial
		case SEC_MODERATOR:
			msg += "|cff00ff00[World]";
			msg += "|cff00ffff[Mod] ";
			msg += "|TINTERFACE/CHATFRAME/UI-CHATICON-BLIZZ:15|t";
			msg += GetNameLink(player);
			msg += ": |cff00ccff";
			break;
			// GM
		case SEC_GAMEMASTER:
			msg += "|cff00ff00[World]";
			msg += "|cff00ffff[GM] ";
			msg += "|TINTERFACE/CHATFRAME/UI-CHATICON-BLIZZ:15|t";
			msg += GetNameLink(player);
			msg += ": |cff00ccff";
			break;
			// Admin
		case SEC_ADMINISTRATOR:
			msg += "|cff00ff00[World]";
			msg += "|cfffa9900[Admin] ";
			msg += "|TINTERFACE/CHATFRAME/UI-CHATICON-BLIZZ:15|t";
			msg += GetNameLink(player);
			msg += ": |cff00ccff";
			/*
			std::string playerLink = ChatHandler(player->GetSession()).playerLink(player->GetName());

			std::ostringstream ss;
			ss << "Player's name:" << playerLink << "\n";
			*/
			break;

		}

		msg += args;

		if (FACTION_SPECIFIC)
		{
			SessionMap sessions = sWorld->GetAllSessions();
			for (SessionMap::iterator itr = sessions.begin(); itr != sessions.end(); ++itr)
				if (Player* plr = itr->second->GetPlayer())
					if (plr->GetTeam() == player->GetTeam())
						sWorld->SendServerMessage(SERVER_MSG_STRING, msg.c_str(), plr);

		}
		else
			sWorld->SendServerMessage(SERVER_MSG_STRING, msg.c_str(), 0);

		return true;

	}
};

void AddSC_cs_world_chat()
{
	new cs_world_chat;
}