/*******************************************
*Made By - ??                              *
*Release by - Ghostcrawler336			   *
*Edit by: Ghostcrawler336/SymbolixDEV      * 
*Errors fixed by - Parranoia               *
*Warnings fixed by - Ghostcrawler336       *
****************************************/
#include "ScriptPCH.h"
#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "MapManager.h"
#include "Chat.h"
#include "Common.h"
#include "Language.h"

class vipcommands : public CommandScript
{
public:
	vipcommands() : CommandScript("vipcommands") { }

	ChatCommand* GetCommands() const
	{
		static ChatCommand vipCommandTable[] =

		{
			{ "mall", SEC_VIP, true, &HandleVipMallCommand, "", NULL },
			{ "duelzone", SEC_VIP, true, &HandleDuelZoneCommand, "", NULL },
			{ "bank", SEC_VIP, true, &HandleBankCommand, "", NULL },
			{ "appear", SEC_VIP, true, &HandleAppearCommand, "", NULL },
			{ "maxskill", SEC_VIP, true, &HandleMaxSkillCommand, "", NULL },
			{ "changerace", SEC_VIP, false, &HandleChangeRaceCommand, "", NULL },
			{ "changefaction", SEC_VIP, false, &HandleChangeFactionCommand, "", NULL },
			{ "customize", SEC_VIP, false, &HandleCustomizeCommand, "", NULL },
			{ "tele", SEC_VIP, false, &HandleTeleCommand, "", NULL },

			{ NULL, 0, false, NULL, "", NULL }
		};
		static ChatCommand commandTable[] =
		{
			{ "vip", SEC_VIP, true, NULL, "", vipCommandTable },
			{ NULL, 0, false, NULL, "", NULL }
		};
		return commandTable;
	}



	static bool HandleTeleCommand(ChatHandler* handler, const char* args)
	{
		if (!*args)
			return false;

		Player* me = handler->GetSession()->GetPlayer();

		// id, or string, or [name] Shift-click form |color|Htele:id|h[name]|h|r
		GameTele const* tele = handler->extractGameTeleFromLink((char*)args);

		if (!tele)
		{
			handler->SendSysMessage(LANG_COMMAND_TELE_NOTFOUND);
			handler->SetSentErrorMessage(true);
			return false;
		}

		if (me->isInCombat())
		{
			handler->SendSysMessage(LANG_YOU_IN_COMBAT);
			handler->SetSentErrorMessage(true);
			return false;
		}

		MapEntry const* map = sMapStore.LookupEntry(tele->mapId);
		if (!map || map->IsBattlegroundOrArena())
		{
			handler->SendSysMessage(LANG_CANNOT_TELE_TO_BG);
			handler->SetSentErrorMessage(true);
			return false;
		}

		// stop flight if need
		if (me->isInFlight())
		{
			me->GetMotionMaster()->MovementExpired();
			me->CleanupAfterTaxiFlight();
		}
		// save only in non-flight case
		else
			me->SaveRecallPosition();

		me->TeleportTo(tele->mapId, tele->position_x, tele->position_y, tele->position_z, tele->orientation);
		return true;
	}

	static bool HandlevipCommand(ChatHandler* handler, const char* args)
	{

		Player* me = handler->GetSession()->GetPlayer();

		me->Say("vip command?", LANG_UNIVERSAL);
		return true;
	}

	static bool HandleChangeRaceCommand(ChatHandler* handler, const char* args)
	{

		Player* me = handler->GetSession()->GetPlayer();
		me->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
		handler->PSendSysMessage("Relog to change race of your character.");
		return true;
	}

	static bool HandleChangeFactionCommand(ChatHandler* handler, const char* args)
	{

		Player* me = handler->GetSession()->GetPlayer();
		me->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
		handler->PSendSysMessage("Relog to change faction of your character.");
		return true;
	}


	static bool HandleCustomizeCommand(ChatHandler* handler, const char* args)
	{

		Player* me = handler->GetSession()->GetPlayer();
		me->SetAtLoginFlag(AT_LOGIN_CUSTOMIZE);
		handler->PSendSysMessage("Relog to customize your character.");
		return true;
	}

	static bool HandleVipMallCommand(ChatHandler* handler, const char* args)
	{

		Player* me = handler->GetSession()->GetPlayer();

		if (me->isInCombat())
		{
			handler->SendSysMessage(LANG_YOU_IN_COMBAT);
			handler->SetSentErrorMessage(true);
			return false;
		}

		// stop flight if need
		if (me->isInFlight())
		{
			me->GetMotionMaster()->MovementExpired();
			me->CleanupAfterTaxiFlight();
		}
		// save only in non-flight case
		else
			me->SaveRecallPosition();

		me->TeleportTo(0, 23.8378f, -1588.85f, 195.419f, 4.54306f); // MapId, X, Y, Z, O
		return true;
	}

	static bool HandleDuelZoneCommand(ChatHandler* handler, const char* args)
	{

		Player* me = handler->GetSession()->GetPlayer();

		if (me->isInCombat())
		{
			handler->SendSysMessage(LANG_YOU_IN_COMBAT);
			handler->SetSentErrorMessage(true);
			return false;
		}

		// stop flight if need
		if (me->isInFlight())
		{
			me->GetMotionMaster()->MovementExpired();
			me->CleanupAfterTaxiFlight();
		}
		// save only in non-flight case
		else
			me->SaveRecallPosition();

		me->TeleportTo(0, 0f, 0f, 0f, 0f); // MapId, X, Y, Z, O || Add you own tele 
		return true;
	}

	static bool HandleBankCommand(ChatHandler* handler, char const* /*args*/)
	{
		handler->GetSession()->SendShowBank(handler->GetSession()->GetPlayer()->GetGUID());
		return true;
	}

	static bool HandleMaxSkillCommand(ChatHandler* handler, char const* /*args*/)
	{
		Player* me = handler->GetSession()->GetPlayer();

		if (me->isInCombat())
		{
			handler->SendSysMessage(LANG_YOU_IN_COMBAT);
			handler->SetSentErrorMessage(true);
			return false;
		}

		me->UpdateSkillsToMaxSkillsForLevel();
		return true;
	}

	static bool HandleAppearCommand(ChatHandler* handler, char const* args)
	{
		Player* target;
		uint64 targetGuid;
		std::string targetName;
		if (!handler->extractPlayerTarget((char*)args, &target, &targetGuid, &targetName))
			return false;

		Player* _player = handler->GetSession()->GetPlayer();
		if (target == _player || targetGuid == _player->GetGUID())
		{
			handler->SendSysMessage(LANG_CANT_TELEPORT_SELF);
			handler->SetSentErrorMessage(true);
			return false;
		}
	}
};

void AddSC_vipcommands()
{
	new vipcommands();
}