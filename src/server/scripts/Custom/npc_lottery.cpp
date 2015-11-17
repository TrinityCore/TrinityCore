/*
 *
 * Copyright (C) 2013 Emu-Devstore <http://emu-devstore.com/>
 * Written by Teiby <http://www.teiby.de/>
 *
 */

#include "Config.h"
#include "Language.h"

#define EVENT_LOTTERY        132 // Use '.event start 132' or '.event stop 132' to start and stop manually. Event will start automatically every 24h (08:00pm)

#define LOTTERY_ENABLE        true
#define LOTTERY_MINLVL        1
#define LOTTERY_BETCOST        10    * 10000 // 10 Gold
#define LOTTERY_MAXNUMBER    30    // 1 - 30
#define LOTTERY_FIELDS        5    // how many numbers? (e.g. '5 10 22 3 25')
#define LOTTERY_BETCOUNT    1    // how many bets each player?


class npc_lottery : public CreatureScript
{
public:
    npc_lottery() : CreatureScript("npc_lottery") { }

    bool OnGossipHello(Player* player, Creature* pCreature)
    {
        if (player && LOTTERY_ENABLE)
        {
            if (player->getLevel() >= uint32(LOTTERY_MINLVL) && player->GetMoney() >= uint32(LOTTERY_BETCOST))
            {
                std::stringstream str;
                str << "Willst du dein Glück versuchen? " << LOTTERY_FIELDS << " Nummern zwischen 1 und " << LOTTERY_MAXNUMBER << " (durch Leerzeichen trennen), bezahle " << (uint32)(LOTTERY_BETCOST*0.0001f) << " Gold und warte auf die Auslosung (20:00).";
                str << " Du kannst nur " << LOTTERY_BETCOUNT << " Los kaufen" << (LOTTERY_BETCOUNT > 1 ? "s." : ".");


                pCreature->Whisper(str.str().c_str(), LANG_UNIVERSAL, player);
                player->ADD_GOSSIP_ITEM_EXTENDED(0, "Kaufe ein Los", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF, "", 0, true);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Script Info", GOSSIP_SENDER_MAIN, 9998);
                player->SEND_GOSSIP_MENU(player->GetGossipTextId(pCreature), pCreature->GetGUID());
            }
            else
           {
                std::stringstream str;
                str << "Du brauchst " << LOTTERY_MINLVL << " Gold and Level " << (uint32)(LOTTERY_BETCOST*0.0001f) << "+ um ein Los zu kaufen.";
                pCreature->Whisper(str.str().c_str(), LANG_UNIVERSAL, player);
            }
        }
        return true;
    }

    bool OnGossipSelectCode(Player* player, Creature* pCreature, uint32 uiSender, uint32 uiAction, const char* code)
    {
        player->PlayerTalkClass->ClearMenus();
       if (uiSender == GOSSIP_SENDER_MAIN)
        {
            switch (uiAction)
           {
                case GOSSIP_ACTION_INFO_DEF:
                {
                   char * charCode = (char*)code;
                    std::string strCode = (char*)code;
                    char * tmp;
                   int32 number[LOTTERY_FIELDS];
                    std::stringstream error;
                    error << "Du hast eine falsche Nummer eingegeben. Du musst " << LOTTERY_FIELDS << " Nummer (durch Leerzeichen trennen) zwischen 1 - " << LOTTERY_MAXNUMBER << "eingeben.";
                    std::string errordub = ("Du hast schon getipt");
                    std::string sNumbers;


                    QueryResult pBetGuid = WorldDatabase.PQuery("SELECT COUNT(*) FROM lottery_bets WHERE guid = %u", player->GetGUID().GetCounter());
                    if (pBetGuid && pBetGuid->Fetch()->GetUInt32() >= LOTTERY_BETCOUNT)
                    {
                        pCreature->Whisper(errordub.c_str(), LANG_UNIVERSAL, player);
                        player->CLOSE_GOSSIP_MENU();
                        return false;
                    }


                    tmp = strtok (charCode," ");
                    for (int8 n = 0; n < LOTTERY_FIELDS; n++)
                    {
                        if (tmp != NULL)
                        {
                            number[n] = atoi(tmp);
                            if (number[n] <= 0 || number[n] > LOTTERY_MAXNUMBER)
                            {
                                pCreature->Whisper(error.str().c_str(), LANG_UNIVERSAL, player);
                                player->CLOSE_GOSSIP_MENU();
                                return false;
                            }
                            tmp = strtok (NULL, " ");
                        }
                        else
                        {
                            pCreature->Whisper(error.str().c_str(), LANG_UNIVERSAL, player);
                            player->CLOSE_GOSSIP_MENU();
                            return false;
                        }
                    }

                    std::stringstream ssNumber;
                    for(int i = 0; i < LOTTERY_FIELDS; i++)
                    {
                        ssNumber << number[i];

                        if(i < LOTTERY_FIELDS-1)
                            ssNumber << " ";
                    }

                    sNumbers = "Du hast folgende Zahlen getipt: " + ssNumber.str();

                    uint32 betMaxID = 0;
                    QueryResult qbetMaxID = WorldDatabase.Query("SELECT MAX(id) FROM lottery_bets");

                    if (qbetMaxID)
                        betMaxID = qbetMaxID->Fetch()->GetUInt32();

                    WorldDatabase.PExecute("INSERT INTO lottery_bets (id, name, guid, bet) VALUES ('%u', '%s', '%u', '%s');", betMaxID+1, player->GetName().c_str(), player->GetGUID().GetCounter(), ssNumber.str().c_str());
                    pCreature->Whisper(sNumbers.c_str(), LANG_UNIVERSAL, player);
                    player->ModifyMoney(-LOTTERY_BETCOST);

                    player->CLOSE_GOSSIP_MENU();

                    return true;
                }
            }
        }

        return false;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
    {
        if(uiAction == 9998) // Script Info
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Entwickelt von: Teiby", GOSSIP_SENDER_MAIN, uiAction);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Website: www.teiby.de", GOSSIP_SENDER_MAIN, uiAction);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Version: 1.2", GOSSIP_SENDER_MAIN, uiAction);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "<-- Zurück", GOSSIP_SENDER_MAIN, 9999);
            pPlayer->SEND_GOSSIP_MENU(68, pCreature->GetGUID());
        }
        else if(uiAction == 9999)
        {
            pPlayer->PlayerTalkClass->ClearMenus();
            OnGossipHello(pPlayer, pCreature);
        }

        return true;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_lotteryAI (pCreature);
    }

    struct npc_lotteryAI : public ScriptedAI
    {
        npc_lotteryAI(Creature* pCreature) : ScriptedAI(pCreature) { }

        struct sWinner
        {
            uint32 guid;
            std::string name;
            std::string bets;
            uint32 points;
        };

        void UpdateAI(uint32 diff)
        {
            if (IsEventActive(EVENT_LOTTERY))
            {
                if (me->IsVisible())
                {
                    QueryResult qMaxID = WorldDatabase.Query("SELECT MAX(id) FROM lottery_bets");
                    if (!qMaxID)
                    {
                        me->SetVisible(false);
                        return;
                    }

                    uint32 betMaxID = qMaxID->Fetch()->GetUInt32();
                    uint32 luckyNumber[LOTTERY_FIELDS];
                    std::stringstream sLuckyNumber;
                    uint32 lotteryID;
                    const uint32 stakes = betMaxID * LOTTERY_BETCOST * 0.7f; // 70% (rest is added to the jackpot)

                    uint32 winnerCount[LOTTERY_FIELDS];

                    typedef std::list<sWinner> tdJW;
                    tdJW lJackpotWinners;
                    tdJW lWinners;

                    SQLTransaction ctrans = CharacterDatabase.BeginTransaction();
                    SQLTransaction wtrans = WorldDatabase.BeginTransaction();

                    for(int i = 0; i < LOTTERY_FIELDS; i++)
                        winnerCount[i] = 0;

                    QueryResult qlotteryID = WorldDatabase.Query("SELECT MAX(id) FROM lottery");
                    if (!qlotteryID)
                        lotteryID = 0;
                    else
                        lotteryID = qlotteryID->Fetch()->GetUInt32();

                    QueryResult qBets  = WorldDatabase.Query("SELECT guid, bet, name FROM lottery_bets");
                    if (qBets)
                    {
                        for (int8 n = 0; n < LOTTERY_FIELDS; n++)
                            luckyNumber[n] = urand(1, LOTTERY_MAXNUMBER);

                        for(int i = 0; i < LOTTERY_FIELDS; i++)
                        {
                            sLuckyNumber << luckyNumber[i];

                            if(i < LOTTERY_FIELDS-1)
                                sLuckyNumber << " ";
                        }

                        do
                        {
                            Field *fBets = qBets->Fetch();
                            uint32 guid = fBets[0].GetUInt32();
                            std::string bet = fBets[1].GetString();
                            std::string rBet = bet;
                            std::string name = fBets[2].GetString();
                            uint32 points = 0;

                            int32 number[LOTTERY_FIELDS];
                            char * tmp;

                            tmp = strtok ((char*)bet.c_str()," ");

                            for (int8 n = 0; n < LOTTERY_FIELDS; ++n)
                            {
                                if (tmp != NULL)
                                {
                                    number[n] = atoi(tmp);
                                    tmp = strtok (NULL, " ");
                                }
                            }

                            for (int8 n = 0; n < LOTTERY_FIELDS; ++n)
                                for (int8 i = 0; i < LOTTERY_FIELDS; ++i)
                                    if (number[i] == luckyNumber[n])
                                    {
                                        points++;
                                        number[i] = 0;
                                        break;
                                    }

                            if(points == 0)
                                continue;

                            sWinner winner;
                            winner.guid = guid;
                            winner.bets = rBet;
                            winner.name = name;
                            winner.points = points;

                            if(points == LOTTERY_FIELDS)
                                lJackpotWinners.push_back(winner);
                            else
                                lWinners.push_back(winner);

                            winnerCount[points-1]++;

                        } while (qBets->NextRow());


                        for(tdJW::const_iterator itr = lWinners.begin(); itr != lWinners.end(); itr++)
                        {
                            uint32 cash = stakes / pow(2, LOTTERY_FIELDS - itr->points) / winnerCount[itr->points-1];

                            std::stringstream text;
                            text << "Gratulation du hast die Richtigen Zahlen getipt!\n\n";
                            text << "Dein Los: " << itr->bets.c_str() << "\n";
                            text << "Lotto Resultat: " << sLuckyNumber.str().c_str() << "\n\n";
                            text << "Hits: " << itr->points << "\n";
                            text << "Sum of bets with " << itr->points << " hits: " << winnerCount[itr->points-1];

                            Player *pWinner = sObjectMgr->GetPlayerByLowGUID(itr->guid);
                            MailDraft("Won", text.str())
                                .AddMoney(cash)
                                .SendMailTo(ctrans, MailReceiver(pWinner, itr->guid), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));

                            wtrans->PAppend("INSERT INTO lottery_winners (id, name, guid, bet, betPoints) VALUES ('%u', '%s', '%u', '%s', '%u')", lotteryID+1, itr->name.c_str(), itr->guid, itr->bets.c_str(), itr->points);
                        }

                        uint32 jackpot;
                        QueryResult qJackpot  = WorldDatabase.PQuery("SELECT jackpot FROM lottery WHERE id = '%u'", lotteryID);
                        if (qJackpot)
                            jackpot = qJackpot->Fetch()->GetUInt32();
                        else
                            jackpot = 0;

                        jackpot += betMaxID * LOTTERY_BETCOST * 0.3f; // 30%

                        for(int i = 0; i < LOTTERY_FIELDS-1; i++)
                        {
                            if(winnerCount[i] == 0)
                                jackpot += stakes / pow(2, LOTTERY_FIELDS-i-1); // Add money to jackpot if there are no winners
                        }

                        if (winnerCount[LOTTERY_FIELDS-1] > 0)
                        {
                            jackpot /= winnerCount[LOTTERY_FIELDS-1];

                            for(tdJW::const_iterator itr = lJackpotWinners.begin(); itr != lJackpotWinners.end(); itr++)
                            {
                                std::stringstream text;
                                text << "Glückwunsch du hast den Jackpot geknackt\n\n";
                                text << "Dein Los: " << itr->bets.c_str() << "\n";
                                text << "Lotto Resultat: " << sLuckyNumber.str().c_str() << "\n\n";
                                text << "Hits: " << itr->points << "\n";
                                text << "Sum of bets with " << itr->points << " hits: " << winnerCount[itr->points-1];

                                Player *pJPWinner = sObjectMgr->GetPlayerByLowGUID(itr->guid);
                                MailDraft("Jackpot!", text.str())
                                    .AddMoney(jackpot)
                                    .SendMailTo(ctrans, MailReceiver(pJPWinner, itr->guid), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
                            }

                            if (winnerCount[LOTTERY_FIELDS-1] == 1)
                                sWorld->SendWorldText(LANG_LOTTERY_ANNOUNCE_JACKPOT, betMaxID, sLuckyNumber.str().c_str(), lJackpotWinners.begin()->name.c_str(), uint32(jackpot * 0.0001f));
                            else
                                sWorld->SendWorldText(LANG_LOTTERY_ANNOUNCE_JACKPOT_M_PLAYERS, betMaxID, sLuckyNumber.str().c_str(), winnerCount[LOTTERY_FIELDS-1], uint32(jackpot * 0.0001f));

                            jackpot = 0;
                        }
                        else
                        {
                            sWorld->SendWorldText(LANG_LOTTERY_ANNOUNCE, betMaxID, sLuckyNumber.str().c_str(), uint32(jackpot * 0.0001f));
                        }

                        wtrans->PAppend("INSERT INTO lottery (numbers, jackpot) VALUES ('%s', '%u')", sLuckyNumber.str().c_str(), jackpot);
                        wtrans->PAppend("DELETE FROM lottery_bets");

                        WorldDatabase.CommitTransaction(wtrans);
                        CharacterDatabase.CommitTransaction(ctrans);

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
