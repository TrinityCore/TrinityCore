#include "Chat.h"
#include "ObjectMgr.h"
#include "Log.h"
#include "RBAC.h"

class reload_full_creature_template_command : public CommandScript
{
public:
	reload_full_creature_template_command() : CommandScript("reload_full_creature_template_command") { }

	std::vector<ChatCommand> GetCommands() const
	{
		static std::vector<ChatCommand> customCommandTable =
		{
			{ "reload full_creature_template",	rbac::RBAC_PERM_COMMAND_RELOAD_FULL_CREATURE_TEMPLATE, 	true,	&HandleReloadFullCreatureTemplate,	"" }
		};
		return customCommandTable;
	}

	static bool HandleReloadFullCreatureTemplate(ChatHandler * handler, const char * args)
	{
		TC_LOG_INFO("misc", "Reloading Creature Template...");

		sObjectMgr->LoadCreatureTemplates();
		
		//No need to add checks here because InitializeQueriesData checks if the config setting is enabled or disabled
		sObjectMgr->InitializeQueriesData(QUERY_DATA_CREATURES);
		
		handler->SendGlobalGMSysMessage("Creature Template has been reloaded");

		return true;
	}
};

void AddSC_reload_full_creature_template_command()
{
	new reload_full_creature_template_command();
}