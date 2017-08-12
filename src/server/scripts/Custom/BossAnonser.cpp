#include <ScriptPCH.h>
#include "Group.h"
#include "vector"
#include <unordered_map>
#include "WorldSession.h"

#define OTHER_LANG 36

class Anonser : public PlayerScript {
public:
    Anonser() : PlayerScript("Anonser") {}


    std::unordered_map<uint32, Player *> gm;

    void OnLogin(Player *player, bool b) override {
        if (player->GetSession()->GetSecurity() == AccountTypes::SEC_ADMINISTRATOR) {
            uint32 id = player->GetSession()->GetGUIDLow();

            if (gm.count(id) == 0) {
                gm[id] = player;
            }
        }


        std::string msg = "|cffFFA100[" + player->GetName() + "] |r|cff1E831Fзашел в игру.|r";
        SendMessageToGM(msg);
    }

    void OnLogout(Player *player) override {
        if (player->GetSession()->GetSecurity() == AccountTypes::SEC_ADMINISTRATOR) {
            uint32 id = player->GetSession()->GetGUIDLow();

            if (gm.count(id) != 0) {
                gm.erase(id);
            }
        }

        std::string msg = "|cffFFA100[" + player->GetName() + "] |r|cffDB2420вышел из игры.|r";
        SendMessageToGM(msg);
    }

    void OnChat(Player *player, uint32 type, uint32 lang, std::string &string, Channel *channel) override {
        if (player->GetSession()->GetSecurity() == SEC_ADMINISTRATOR)
            return;

        if (lang > OTHER_LANG)
            return;

        SendMessageToGM(
                "|cffFFA100[" + player->GetName() + "] |rнаписал в канал " +
                string);
    }

    void OnChat(Player *player, uint32 type, uint32 lang, std::string &string) override {
        if (player->GetSession()->GetSecurity() == SEC_ADMINISTRATOR)
            return;

        if (lang > OTHER_LANG)
            return;

        SendMessageToGM("|cffFFA100[" + player->GetName() + "] |rнаписал(чат) " + string);
    }

    void OnChat(Player *player, uint32 type, uint32 lang, std::string &string, Player *player1) override {
        if (player->GetSession()->GetSecurity() == SEC_ADMINISTRATOR)
            return;

        if (lang > OTHER_LANG)
            return;

        SendMessageToGM(
                "|cffFFA100[" + player->GetName() + "] |rнаписал игроку (" + player1->GetName() + ") " + string);
    }

    void OnChat(Player *player, uint32 type, uint32 lang, std::string &string, Group *group) override {
        if (player->GetSession()->GetSecurity() == SEC_ADMINISTRATOR)
            return;

        if (lang > OTHER_LANG)
            return;

        SendMessageToGM("|cffFFA100[" + player->GetName() + "] |rнаписал(группа) " + string);
    }

    void OnChat(Player *player, uint32 type, uint32 lang, std::string &string, Guild *guild) override {
        if (player->GetSession()->GetSecurity() == SEC_ADMINISTRATOR)
            return;

        if (lang > OTHER_LANG)
            return;

        SendMessageToGM("|cffFFA100[" + player->GetName() + "] |rнаписал(гильдия) " + string);
    }

    void SendMessageToGM(std::string msg) {
        for (auto g : gm) {
            if (g.second->IsGameMaster()) {
                g.second->SendChatMessage(msg.c_str());
            }
        }
    }
};

void AddSC_Boss_Anouncer() {
    new Anonser;
}
