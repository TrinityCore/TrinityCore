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
            std::string wh = ("Здравствуй, незнакомец. Хочешь испытать удачу? О да, по глазам вижу чо хочешь. Всё очень просто: назови мне 5 чисел в диапазоне от 1 до " + 
                                std::string(sConfig->GetStringDefault("Lottery.MaxNubmer", "30")) + " (разделяя пробелами), заплати стоимость ставки и дождись розыгрыша. Всё очень просто.");
            pCreature->MonsterWhisper(wh.c_str(), pPlayer->GetGUID());
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
                    char * betStr = (char*)code;
                    std::string strCode = (char*)code;
                    char * tmp;
                    int32 number[5];
                    std::string error = ("Вы ввели неверное число. Ваша ставка должна находится в пределах от 1 до " + std::string(sConfig->GetStringDefault("Lottery.MaxNumber", "30")));

                    tmp = strtok (betStr," ");
                    for (int8 n = 0; n < 5; ++n)
                    {
                        if (tmp != NULL)
                        {
                            number[n] = atoi(tmp);
                            if (number[n] < 0 || number[n] > sConfig->GetIntDefault("Lottery.MaxNubmer", 30))
                            {
                                pCreature->MonsterWhisper(error.c_str(), pPlayer->GetGUID());
                                return false;
                            }
                            tmp = strtok (NULL, " ");
                        }
                        else
                        {
                            pCreature->MonsterWhisper(error.c_str(), pPlayer->GetGUID());
                            return false;
                        }
                    }
                    for (int8 n = 0; n < 5; ++n)
                    {
                        sLog->outError("%i", number[n]);
                    }

                    uint32 MaxID;
                    QueryResult qMaxID = WorldDatabase.Query("SELECT MAX(id) FROM lottery_bets");

                    if (qMaxID)
                        MaxID = qMaxID->Fetch()->GetUInt32();
                    else
                        MaxID = 0;

                    WorldDatabase.PExecute("INSERT INTO lottery_bets (id, name, guid, bet) VALUES ('%u', '%s', '%u', '%s')", MaxID+1, pPlayer->GetName(), pPlayer->GetGUIDLow(), strCode.c_str());
                    pPlayer->ModifyMoney(-sConfig->GetIntDefault("Lottery.BetCost", 500000));

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

                    uint32 MaxNumbers = qMaxID->Fetch()->GetUInt32();
                    uint32 luckyNumber[5];
                    uint32 Count;

                    QueryResult lCount = WorldDatabase.Query("SELECT MAX(id) FROM lottery");
                    if (!lCount)
                        Count = 0;
                    else
                        Count = lCount->Fetch()->GetUInt32();

                    QueryResult qBets  = WorldDatabase.Query("SELECT guid, bet, name FROM lottery_bets");
                    //QueryResult qWinnersA = WorldDatabase.PQuery("SELECT guid FROM lottery_bets WHERE bet = '%u'", luckyNumber);
                    if (qBets)
                    {
                        for (int8 n = 0; n < 5; ++n)
                        {
                            luckyNumber[n] = urand(1, sConfig->GetIntDefault("Lottery.MaxNumber", 30));
                            sLog->outError("LN: %i", luckyNumber[n]);
                        }

                        do
                        {
                            Field *fBets = qBets->Fetch();
                            uint32 guid = fBets[0].GetUInt32();
                            std::string bet = fBets[1].GetString();
                            std::string rBet = bet; 
                            std::string name = fBets[2].GetString();
                            uint32 points = 0;
                            uint32 cash;

                            //char * betStr = (char*)code;
                            int32 number[5];
                            char * tmp;

                            tmp = strtok ((char*)bet.c_str()," ");

                            for (int8 n = 0; n < 5; ++n)
                            {
                                if (tmp != NULL)
                                {
                                    number[n] = atoi(tmp);
                                    tmp = strtok (NULL, " ");
                                }
                            }

                            for (int8 n = 0; n < 5; ++n)
                            {
                                for (int8 i = 0; i < 5; ++i)
                                {
                                    if (number[n] == luckyNumber[i])
                                        ++points;
                                }
                            }

                            switch (points)
                            {
                                case 1:
                                {
                                    cash = uint32(MaxNumbers * sConfig->GetIntDefault("Lottery.BetCost", 500000) * 0.005f);
                                    break;
                                }
                                case 2:
                                {
                                    cash = uint32(MaxNumbers * sConfig->GetIntDefault("Lottery.BetCost", 500000) * 0.01f);
                                    break;
                                }
                                case 3:
                                {
                                    cash = uint32(MaxNumbers * sConfig->GetIntDefault("Lottery.BetCost", 500000) * 0.05f);
                                    break;
                                }
                                case 4:
                                {
                                    cash = uint32(MaxNumbers * sConfig->GetIntDefault("Lottery.BetCost", 500000) * 0.2f);
                                    break;
                                }
                                case 5:
                                {
                                    cash = uint32(MaxNumbers * sConfig->GetIntDefault("Lottery.BetCost", 500000) * 0.7f);
                                    break;
                                }
                                default:
                                    continue;
                            }

                            Player *pWinner = sObjectMgr->GetPlayerByLowGUID(guid);
                            SQLTransaction trans = CharacterDatabase.BeginTransaction();
                            MailDraft("Выигрыш", "Поздравляем! Ваше число оказалось счастливым!")
                                .AddMoney(cash)
                                .SendMailTo(trans, MailReceiver(pWinner, GUID_LOPART(guid)), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
                            CharacterDatabase.CommitTransaction(trans);

                            WorldDatabase.PExecute("INSERT INTO lottery_winners (id, name, guid, bet, betPoints) VALUES ('%u', '%s', '%u', '%s', '%u')", Count+1, name.c_str(), guid, rBet.c_str(), points);
                        } while (qBets->NextRow());
                        WorldDatabase.PExecute("INSERT INTO lottery (number_1, number_2, number_3, number_4, number_5) VALUES ('%u', '%u', '%u', '%u', '%u')", luckyNumber[0], luckyNumber[1], luckyNumber[2], luckyNumber[3], luckyNumber[4], luckyNumber[5]);
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
