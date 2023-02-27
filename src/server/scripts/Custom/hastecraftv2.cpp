/*
SPP Praevius Core Hastecraft V3
Written by MDic
*/
#include <map>

#include "Config.h"
#include "ScriptMgr.h"
#include "Unit.h"
#include "Player.h"
#include "Pet.h"
#include "Map.h"
#include "Group.h"
#include "InstanceScript.h"
#include "Chat.h"
#include "Log.h"
//haste 急速
//猜测本文件为单人随机地下城的加速脚本
namespace {

	class Hastecraft_player_instance_handler : public PlayerScript
	{

	public:
		Hastecraft_player_instance_handler() : PlayerScript("Hastecraft_player_instance_handler")
		{
            TC_LOG_INFO("scripts.hastecraft.player.instance", "[Hastecraft] Hastecraft_player_instance_handler Loaded");
		}
        void OnLogin(Player* player, bool /*firstLogin*/) override
		{

			// Hastecraft v2
			uint32 HastecraftMelee = sConfigMgr->GetIntDefault("HastecraftMelee", 0);
			uint32 HastecraftRanged = sConfigMgr->GetIntDefault("HastecraftRanged", 0);
			uint32 HastecraftSpell = sConfigMgr->GetIntDefault("HastecraftSpell", 0);

			// Announce Module
			if (sConfigMgr->GetBoolDefault("Hastecraft.Announce", true))
			{
				ChatHandler(player->GetSession()).SendSysMessage("This server is running the |cff4CFF00Hastecraft V3 |rmodule.");
			}
			// Hastecraft v2
			if (sConfigMgr->GetBoolDefault("Hastecraft.enabled", true))
			{
				player->ApplyRatingMod(CR_HASTE_MELEE, int32(HastecraftMelee * CR_HASTE_MELEE), true);
				player->ApplyRatingMod(CR_HASTE_RANGED, int32(HastecraftRanged * CR_HASTE_RANGED), true);
				player->ApplyRatingMod(CR_HASTE_SPELL, int32(HastecraftSpell * CR_HASTE_SPELL), true);
			}
		};
	};

}

void AddSC_Hastecraft()
{
	new Hastecraft_player_instance_handler();
}
