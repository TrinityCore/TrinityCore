#include <ScriptPCH.h>
#include "Language.h"
#include "../../game/Entities/Player/Player.h"
#include "World.h"
#include "Chat.h"
#include "WorldSession.h"

//#include "AuctionHouseMgr.h"

class premium_commandscript : public CommandScript {
public:
    premium_commandscript() : CommandScript("premium_commandscript") {}

    std::vector<ChatCommand> GetCommands() const override {
        static std::vector<ChatCommand> premiumCommandTable =
                {
                        {"bank", SEC_PLAYER, false, &HandlePremiumBankCommand, ""},
                        {"buff", SEC_PLAYER, false, &HandlePremiumBuffCommand, ""},
                        {"mail", SEC_PLAYER, false, &HandlePremiumMailCommand, ""},
                        //{ "auc",  SEC_PLAYER,  false, &HandlePremiumAuctionCommand, "", NULL },
                };

        static std::vector<ChatCommand> commandTable =
                {
                        {"vip", SEC_PLAYER, false, NULL, "", premiumCommandTable},
                };

        return commandTable;
    }

    static bool HandlePremiumBankCommand(ChatHandler *handler, char const * /*args*/) {
        Player * player = handler->GetSession()->GetPlayer();
        if (player->GetSession()->IsPremium()) {
            //Different Checks
            if (player->IsInCombat() || player->IsInFlight() || player->GetMap()->IsBattlegroundOrArena() ||
                player->HasStealthAura() || player->HasFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH) ||
                player->isDead()) {
                //handler->SendSysMessage(LANG_PREMIUM_CANT_DO);
                handler->SetSentErrorMessage(true);
                return false;
            }

            handler->GetSession()->SendShowBank(handler->GetSession()->GetPlayer()->GetGUID());
        }
        return true;
    }

    static bool HandlePremiumMailCommand(ChatHandler *handler, char const * /*args*/) {
        Player * player = handler->GetSession()->GetPlayer();
        if (player->GetSession()->IsPremium()) {
            //Different Checks
            if (player->IsInCombat() || player->IsInFlight() || player->GetMap()->IsBattlegroundOrArena() ||
                player->HasStealthAura() || player->HasFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH) ||
                player->isDead()) {
//                handler->SendSysMessage(LANG_PREMIUM_CANT_DO);
                handler->SetSentErrorMessage(true);
                return false;
            }

            handler->GetSession()->SendShowMailBox(player->GetGUID());
        }
        return true;
    }

    static bool HandlePremiumBuffCommand(ChatHandler *handler, char const * /*args*/) {
        Player * player = handler->GetSession()->GetPlayer();

        if (player->GetSession()->IsPremium()) {
            //Different Checks
            if (player->IsInCombat() || player->IsInFlight() || player->GetMap()->IsBattlegroundOrArena() ||
                player->HasStealthAura() || player->HasFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH) ||
                player->isDead()) {
//                handler->SendSysMessage(LANG_PREMIUM_CANT_DO);
                handler->SetSentErrorMessage(true);
                return false;
            }

            player->CastSpell(player, 30550, true);
            player->CastSpell(player, 23766, true);
            player->CastSpell(player, 23769, true);
            player->CastSpell(player, 23738, true);
            player->CastSpell(player, 23737, true);
            player->CastSpell(player, 23736, true);
            player->CastSpell(player, 23767, true);
            player->CastSpell(player, 23735, true);
            player->CastSpell(player, 23768, true);
        }
        return true;
    }
    //static bool HandlePremiumAuctionCommand(ChatHandler* handler, char const* /*args*/)
    //{
    //Player* player = handler->GetSession()->GetPlayer();
    //if(player->GetSession()->IsPremium())
    //{
    //Different Checks
    //if(player->IsInCombat() || player->IsInFlight() || player->GetMap()->IsBattlegroundOrArena() || player->HasStealthAura() || player->HasFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH) || player->isDead())
    //{
    //    handler->SendSysMessage(LANG_PREMIUM_CANT_DO);
    //    handler->SetSentErrorMessage(true);
    //    return false;
    //}

    //handler->GetSession()->SendAuctionHello(player->GetGUID());
    //handler->GetSession()->SendAuctionHello(player->getFaction());

    //}
    //return true;
    //}
};

void AddSC_premium_commandscript() {
    new premium_commandscript();
}

