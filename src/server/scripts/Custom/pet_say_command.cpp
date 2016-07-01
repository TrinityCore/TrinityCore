		/*-------------------------------------*\
		|		   Coded by Obitus				|
		|		   	April 6, 2016				|
		|		Tested on TrinityCore 3.3.5		|
		\*-------------------------------------*/
		
		/*
		- psay (pet say) command
		- Works with Hunter pets, Warlock pets and DK pet (if you have Master of Ghouls talent).
		- Doesn't work with Mage pet, Shaman pets, Priest pet - Becasue these are temporary pets.
		- Doesn't work with companions - Becasue they don't count as pets
		
		+ a little clear chat script
		*/


#include "ScriptMgr.h"
#include "RBAC.h"
#include "Chat.h"
#include "Player.h"
#include "Pet.h"

/*
-- AUTH DATABASE
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
(1011, 'Command: psay');

INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES
(195, 1011);
____________________________________________________

RBAC.h
// 799 - 834 6.x only
RBAC_PERM_COMMAND_DEBUG_LOADCELLS                        = 835,
RBAC_PERM_COMMAND_DEBUG_BOUNDARY                         = 836,

//Custom commands
RBAC_SEC_PLAYER											 = 1011,  // ADD THIS LINE TO RBAC.h

// custom permissions 1000+
RBAC_PERM_MAX
*/

class custom_commands : public CommandScript
{
public:
	custom_commands() : CommandScript("custom_commands") { }

	std::vector<ChatCommand> GetCommands() const override
	{
		static std::vector<ChatCommand> CustomCommandTable =
		{
			{ "clearchat", rbac::RBAC_SEC_PLAYER, false, &HandleClearChatCommand, "" },
			{ "psay", rbac::RBAC_SEC_PLAYER, false, &HandlePetSayCommand, "" } //pet say
		};
		return CustomCommandTable;
	}

	static bool HandleClearChatCommand(ChatHandler * handler, const char * args)
	{
#define clearChat	"\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n"
		Player * player = handler->GetSession()->GetPlayer();
		ChatHandler(player->GetSession()).PSendSysMessage(clearChat);
		return true;
	}
	
	static bool HandlePetSayCommand(ChatHandler * handler, const char * msg)
	{
		Player * player = handler->GetSession()->GetPlayer();
		Pet* pet = player->GetPet();
		
		std::string playerText = msg;

		if (playerText.empty())
		{
			return false;
		}
		
		if (player->GetPet() && pet->IsAlive())
		{
			if (player->GetTeam() == ALLIANCE)
			{
				pet->Say(playerText, LANG_COMMON, NULL);
			}
			else
			{
				pet->Say(playerText, LANG_ORCISH, NULL);
			}	
		}
		else
		{
			player->GetSession()->SendNotification("Error! You either don't have a pet or your pet is dead or your pet has a limited duration");
		}
		return true;
	}
	
};

void AddSC_custom_commands()
{
	new custom_commands;
}