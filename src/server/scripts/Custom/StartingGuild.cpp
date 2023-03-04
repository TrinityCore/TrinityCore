#include "ScriptMgr.h"
#include "Player.h"
#include "GuildMgr.h"
#include "Guild.h"//这个库必须,不然会报不完整类型错误
#include "Config.h"
#include "Config.h"

class gon_playerscripts : public PlayerScript
{
    public:
        gon_playerscripts() : PlayerScript("gon_playerscripts") { }

    void OnLogin(Player* player, bool firstLogin)
    {
        if (sConfigMgr->GetBoolDefault("StartGuild.enable", false))//添加配置设置,默认不启用
        {
            if (firstLogin)
            {
                uint32 GUILD_ID_ALLIANCE = sConfigMgr->GetIntDefault("StartGuild.Alliance", 0);
                uint32 GUILD_ID_HORDE = sConfigMgr->GetIntDefault("StartGuild.Horde", 0);
                Guild* guild = sGuildMgr->GetGuildById(player->GetTeam() == ALLIANCE ? GUILD_ID_ALLIANCE : GUILD_ID_HORDE);
                if (guild)
                {
                    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
                    guild->AddMember(trans, player->GetGUID());//工会加个玩家,要这么费事?
                    //guild->AddMember(player->GetGUID());
                    //原来的语句这么简单...
                }


            }
        }
    }
};

void AddSC_gon_playerscripts()
{
    new gon_playerscripts();
}
