//
// Created by adizbek on 5/8/17.
//

#include "ScriptMgr.h"
#include "ScriptPCH.h"
#include "WorldSession.h"
#include "GossipDef.h"
#include "ScriptedGossip.h"
#include "DatabaseEnv.h"
#include "QueryResult.h"
#include "DBCStructure.h"

class PLAYER_TRANSFER_NPC_SCRIPT : CreatureScript {

public:
    PLAYER_TRANSFER_NPC_SCRIPT() : CreatureScript("PLAYER_TRANSFER_NPC_SCRIPT") {}

    struct playerTransferAI : public CreatureAI {

        uint32 GOSSIP_ITEM_CHANGE_FRACTION = 50;
        uint32 GOSSIP_ITEM_CHANGE_RACE = 55;
        uint32 GOSSIP_ITEM_CHANGE_SKIN = 60;

        uint32 CHANGE_FRACTION_COST = 100 * 100 * 1000 * 30;
        uint32 CHANGE_RACE_COST = 100 * 100 * 1000 * 20;
        uint32 CHANGE_SKIN_COST = 100 * 100 * 1000 * 15;

        playerTransferAI(Creature *creature) : CreatureAI(creature) {
            
        }

        void UpdateAI(uint32 diff) override {
            
        }


        void ChangeFraction(Player *player, Creature *npc) {
            npc->Whisper("Вы можете выбрать фракцию в следующим входе в игру", LANG_UNIVERSAL, player);

            PreparedStatement *stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG);
            stmt->setUInt16(0, uint16(AT_LOGIN_CHANGE_FACTION));
            stmt->setUInt32(1, player->GetGUID().GetCounter());
            CharacterDatabase.Execute(stmt);
        }
        void ChangeRace(Player *player, Creature *npc) {
            npc->Whisper("Вы можете выбрать расу в следующим входе в игру", LANG_UNIVERSAL, player);

            PreparedStatement *stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG);
            stmt->setUInt16(0, uint16(AT_LOGIN_CHANGE_RACE));
            player->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
            stmt->setUInt32(1, player->GetGUID().GetCounter());
            CharacterDatabase.Execute(stmt);
        }
        void ChangeSkin(Player *player, Creature *npc) {
            npc->Whisper("Вы можете изменить внешность в следующим входе в игру", LANG_UNIVERSAL, player);

            PreparedStatement *stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG);
            stmt->setUInt16(0, uint16(AT_LOGIN_CUSTOMIZE));
            player->SetAtLoginFlag(AT_LOGIN_CUSTOMIZE);
            stmt->setUInt32(1, player->GetGUID().GetCounter());
            CharacterDatabase.Execute(stmt);
        }

        bool GossipHello(Player *player) override {
            // 30000 gold
            AddGossipItemFor(player, GOSSIP_ICON_TABARD,
                             std::string("Cменить фракцию ") +
                             std::string(player->GetSession()->IsPremium() ? "(бесплатно)" : "(30000 голд)"),
                             GOSSIP_ITEM_CHANGE_FRACTION, 0,
                             "Хотите ли сменить фракцию?", player->GetSession()->IsPremium() ? 0 : CHANGE_FRACTION_COST,
                             false);

            // 20000 gold
            AddGossipItemFor(player, GOSSIP_ICON_TABARD,
                             std::string("Cменить расу ") +
                             std::string(player->GetSession()->IsPremium() ? "(бесплатно)" : "(20000 голд)"),
                             GOSSIP_ITEM_CHANGE_RACE, 0,
                             "Хотите ли сменить расу?", player->GetSession()->IsPremium() ? 0 : CHANGE_RACE_COST, false);

            AddGossipItemFor(player, GOSSIP_ICON_TABARD,
                             std::string("Изменить внешность ") +
                             std::string(player->GetSession()->IsPremium() ? "(бесплатно)" : "(15000 голд)"),
                             GOSSIP_ITEM_CHANGE_SKIN, 0,
                             "Хотите ли изменить внешность?", player->GetSession()->IsPremium() ? 0 : CHANGE_SKIN_COST,
                             false);

            SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, me);

            return true;
        }
        
        bool GossipSelect(Player *player, uint32 sender, uint32 uiAction) override {
            ClearGossipMenuFor(player);

            if (uiAction == 0) {
                if (player->GetSession()->IsPremium()) {
                    ChangeFraction(player, me);
                } else {

                    if (player->GetMoney() >= CHANGE_FRACTION_COST) {
                        player->ModifyMoney(-1 * CHANGE_FRACTION_COST);

                        ChangeFraction(player, me);
                    } else {
                        me->Whisper("Не хватает монет.", LANG_UNIVERSAL, player);
                    }

                    CloseGossipMenuFor(player);
                }

            }

            if (uiAction == 1) {
                if (player->GetSession()->IsPremium()) {
                    ChangeRace(player, me);
                } else {

                    if (player->GetMoney() >= CHANGE_RACE_COST) {
                        player->ModifyMoney(-1 * CHANGE_RACE_COST);

                        ChangeRace(player, me);
                    } else {
                        me->Whisper("Не хватает монет.", LANG_UNIVERSAL, player);
                    }

                }

                CloseGossipMenuFor(player);
            }

            if (uiAction == 2) {
                if (player->GetSession()->IsPremium()) {
                    ChangeSkin(player, me);
                } else {

                    if (player->GetMoney() >= CHANGE_SKIN_COST) {
                        player->ModifyMoney(-1 * CHANGE_SKIN_COST);

                        ChangeSkin(player, me);
                    } else {
                        me->Whisper("Не хватает монет.", LANG_UNIVERSAL, player);
                    }

                }

                CloseGossipMenuFor(player);
            }

            return true;
        }
    };

private:
    CreatureAI *GetAI(Creature *creature) const override {
        return new playerTransferAI(creature);
    }

public:
    
};

void AddSC_PLAYER_TRANSFER_NPC_SCRIPT() {
    new PLAYER_TRANSFER_NPC_SCRIPT();
}
