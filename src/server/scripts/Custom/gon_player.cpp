#include "ScriptMgr.h"
#include "Player.h"
#include "GuildMgr.h"
#include "Guild.h"//��������,��Ȼ�ᱨ���������ʹ���
#include "Config.h"

class gon_playerscripts : public PlayerScript
{
    public:
        gon_playerscripts() : PlayerScript("gon_playerscripts") { }

    void OnLogin(Player* player, bool firstLogin)
    {
        if (sConfigMgr->GetBoolDefault("StartGuild.enable", false))//�����������,Ĭ�ϲ�����
        {
            if (firstLogin)
            {
                uint32 GUILD_ID_ALLIANCE = sConfigMgr->GetIntDefault("StartGuild.Alliance", 20);
                uint32 GUILD_ID_HORDE = sConfigMgr->GetIntDefault("StartGuild.Horde", 20);
                Guild* guild = sGuildMgr->GetGuildById(player->GetTeam() == ALLIANCE ? GUILD_ID_ALLIANCE : GUILD_ID_HORDE);
                if (guild)
                {
                    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
                    guild->AddMember(trans, player->GetGUID());//����Ӹ����,Ҫ��ô����?
                    //guild->AddMember(player->GetGUID());
                    //ԭ���������ô��...
                }
            }
        }
    }
};

void AddSC_gon_playerscripts()
{
    new gon_playerscripts();
}
