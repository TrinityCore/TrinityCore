#pragma execution_character_set("utf-8")
#include "ScriptMgr.h"
#include "Config.h"
#include "Player.h"
#include "World.h"

class Death_Announcer : public PlayerScript
{
public:
    Death_Announcer() : PlayerScript("Death_Announcer") {}

    void OnPlayerKilledByCreature(Creature* killer, Player* killed)
    {
        if (sConfigMgr->GetBoolDefault("KilledByCreature.Announcer", false))//world.conf 设定
        {
            if (killer->IsCreature())
            {
                std::string plr = killed->GetName();
                std::string creature_n = killer->GetName();
                //bool ingroup = killed->GetGroup();
                std::string tag_colour = "FF0000";
                std::string plr_colour = "7bbef7";
                std::string creature_colour = "ff0000";
                std::ostringstream stream;
                stream << "|CFF" << tag_colour <<
                    "|r|cff" << plr_colour << " " << plr <<
                    "|r -完犊子了- -凶手是- |CFF" << creature_colour << "" << creature_n << "|r " "-小怪：别拿豆包不当干粮-" << "!";
                sWorld->SendServerMessage(SERVER_MSG_STRING, stream.str().c_str());
            }
        }

        if (killer->isWorldBoss())
        {
            std::string plr = killed->GetName();
            std::string creature_n = killer->GetName();
            //bool ingroup = killed->GetGroup();
            std::string tag_colour = "FF0000";
            std::string plr_colour = "7bbef7";
            std::string creature_colour = "ff0000";
            std::ostringstream stream;
            stream << "|CFF" << tag_colour <<
                "|r|cff" << plr_colour << " " << plr <<
                "|r -被XX了- -凶手是- |CFF" << creature_colour << "" << creature_n << "|r " "-世界BOSS:我就是摸了你一下-" << "!";
            sWorld->SendServerMessage(SERVER_MSG_STRING, stream.str().c_str());
        }

        if (killer->IsDungeonBoss())
        {
            std::string plr = killed->GetName();
            std::string creature_n = killer->GetName();
            //bool ingroup = killed->GetGroup();
            std::string tag_colour = "FF0000";
            std::string plr_colour = "7bbef7";
            std::string creature_colour = "ff0000";
            std::ostringstream stream;
            stream << "|CFF" << tag_colour <<
                "|r|cff" << plr_colour << " " << plr <<
                "|r -从新投胎了- -凶手是- |CFF" << creature_colour << "" << creature_n << "|r " "副本BOSS:你什么档次啊，过来刷我？" << "!";
            sWorld->SendServerMessage(SERVER_MSG_STRING, stream.str().c_str());
        }
    }

    void OnPVPKill(Player* killer, Player* killed)
    {
        if (sConfigMgr->GetBoolDefault("PvPKill.Announcer", false))//world.conf
        {
            if (killer->IsPlayer())
            {
                std::string plr = killed->GetName();
                std::string creature_n = killer->GetName();
                //bool ingroup = killed->GetGroup();
                std::string tag_colour = "FF0000";
                std::string plr_colour = "7bbef7";
                std::string creature_colour = "ff0000";
                std::ostringstream stream;
                stream << "|CFF" << tag_colour <<
                    "|r|cff" << plr_colour << " " << plr <<
                    "|r -暴毙了- 凶手是- |CFF" << creature_colour << "" << creature_n << "|r " "场面过于血腥，此处省略……" << "!";
                sWorld->SendServerMessage(SERVER_MSG_STRING, stream.str().c_str());
            }
        }
    }
};

void AddSC_Death_Announcer()
{
    new Death_Announcer;
}
