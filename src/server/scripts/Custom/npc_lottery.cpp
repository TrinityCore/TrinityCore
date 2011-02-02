#include "Config.h"

#define GOSSIP_BUY_TICKET           "Я хочу сделать ставку."
#define EVENT_LOTTERY               132

class npc_lottery : public CreatureScript
{
public:
    npc_lottery() : CreatureScript("npc_lottery") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pPlayer && !pPlayer->isGameMaster() && sConfig->GetBoolDefault("Lottery.Enable", false) && pPlayer->getLevel() >= sConfig->GetIntDefault("Lottery.MinUserLVL", 60))
        {
            pPlayer->PrepareGossipMenu(pCreature);
            pPlayer->ADD_GOSSIP_ITEM_EXTENDED(0, GOSSIP_BUY_TICKET, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF, "", 0, true);
            pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
        }
        return true;
    }

    bool OnGossipSelectCode(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction, const char* code)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        if (uiSender == GOSSIP_SENDER_MAIN)
        {
            switch (uiAction)
            {
                case GOSSIP_ACTION_INFO_DEF:
                {
                    int32 uCode = atoi(code);
                    if (uCode <= sConfig->GetIntDefault("Lottery.MaxBet", 30) && uCode > 0)
                    {
                        uint32 MaxID;
                        QueryResult qMaxID = WorldDatabase.Query("SELECT MAX(id) FROM lottery_bets");

                        if (qMaxID)
                            MaxID = qMaxID->Fetch()->GetUInt32();
                        else
                            MaxID = 0;

                         WorldDatabase.PExecute("INSERT INTO lottery_bets (id, name, guid, bet) VALUES ('%u', '%s', '%u', '%i')", MaxID+1, pPlayer->GetName(), pPlayer->GetGUIDLow(), uCode);
                         pPlayer->ModifyMoney(-sConfig->GetIntDefault("Lottery.BetCost", 500000));
                    }
                    else
                    {
                        std::string error = ("Вы ввели неверное число. Ваша ставка должна находится в пределах от 1 до " + std::string(sConfig->GetStringDefault("Lottery.MaxBet", "30")));
                        pCreature->MonsterWhisper(error.c_str(), pPlayer->GetGUID());
                    }
                    pPlayer->CLOSE_GOSSIP_MENU();

                    return true;
                }
            }
        }

        return false;
        }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_lotteryAI (pCreature);
    }

    struct npc_lotteryAI : public ScriptedAI
    {
        npc_lotteryAI(Creature* pCreature) : ScriptedAI(pCreature) { }

        void UpdateAI(const uint32 diff)
        {
            if (IsEventActive(EVENT_LOTTERY))
            {
                if (me->IsVisible())
                {
                    QueryResult qMaxID = WorldDatabase.Query("SELECT MAX(id) FROM lottery_bets");
                    if (!qMaxID)
                        return;

                    uint32 maxBets = qMaxID->Fetch()->GetUInt32();
                    uint32 winners = 0;

                    uint32 luckyNumber = 1/*urand(1, sConfig->GetIntDefault("Lottery.MaxBet", 30))*/;
                    QueryResult qWinners  = WorldDatabase.PQuery("SELECT guid FROM lottery_bets WHERE bet = '%u'", luckyNumber);  // Winners count
                    QueryResult qWinnersA = WorldDatabase.PQuery("SELECT guid FROM lottery_bets WHERE bet = '%u'", luckyNumber);
                    if (qWinners && qWinnersA)
                    {
                        sLog->outError("In qWinners");
                        do
                        {
                            ++winners;
                        } while (qWinners->NextRow());
                        uint32 cash = uint32(maxBets * sConfig->GetIntDefault("Lottery.BetCost", 500000) / winners * sConfig->GetFloatDefault("Lottery.CashMultiplier", 0.3f));
                        do
                        {
                            uint32 winnerGuid = qWinnersA->Fetch()->GetUInt32();
                            Player *pWinner = sObjectMgr->GetPlayerByLowGUID(winnerGuid);
                            SQLTransaction trans = CharacterDatabase.BeginTransaction();
                            MailDraft("Выигрыш", "Поздравляем! Ваше число оказалось счастливым!")
                                .AddMoney(cash)
                                .SendMailTo(trans, MailReceiver(pWinner, GUID_LOPART(winnerGuid)), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
                            CharacterDatabase.CommitTransaction(trans);
                        } while (qWinnersA->NextRow());

                        sWorld->SendWorldText(LANG_LOTTERY_MSG, maxBets, luckyNumber, winners, cash / 10000);
                        WorldDatabase.PExecute("INSERT INTO lottery_winners (name, guid) SELECT name, guid FROM lottery_bets WHERE bet = '%u'", luckyNumber);
                        WorldDatabase.PExecute("DELETE FROM lottery_bets");
                        me->SetVisible(false);
                    }
                }
            }
            else
            {
                if (!me->IsVisible())
                    me->SetVisible(true);
            }
        }
    };

};


void AddSC_npc_lottery()
{
    new npc_lottery;
}
