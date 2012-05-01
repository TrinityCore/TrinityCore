/*
* Copyright (C) 2010-2011 TrinityCore <http://www.trinitycore.org/>
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

/* Script
Name: Totalizator
Complete:
Author patch based, supported by: Ishigu, Ishigure
Modified patch, supported by; Wasy
Category: Custom teleport
End*/

#include "ScriptPCH.h"

#define C_TOTALIZATORMOB_COUNT 6
#define SPELL_FIREWORK 11544

const uint32 TotalizatorMobIDs[] =
{
    99110, //cat
    99111, //2
    99112, //3
    99113, //4
    99114, //5
    99115, //6
};

const Position PosMobStart[] =
{
    {-7860.0f, -500.0f, 170.8f, 3.12f},
    {-7860.0f, -490.0f, 170.8f, 3.12f},
    {-7860.0f, -480.0f, 170.8f, 3.12f},
    {-7860.0f, -470.0f, 170.8f, 3.12f},
    {-7860.0f, -460.0f, 170.8f, 3.12f},
    {-7860.0f, -450.0f, 170.8f, 3.12f},
};

const Position PosMobEnd[] =
{
    {-7900.0f, -500.0f, 170.8f, 3.12f},
    {-7900.0f, -490.0f, 170.8f, 3.12f},
    {-7900.0f, -480.0f, 170.8f, 3.12f},
    {-7900.0f, -470.0f, 170.8f, 3.12f},
    {-7900.0f, -460.0f, 170.8f, 3.12f},
    {-7900.0f, -450.0f, 170.8f, 3.12f},
};

struct ITRate
{
    Player* m_player;
    uint32 m_rate;
    uint8 m_mob;
};

class custom_totalizator_controler : public CreatureScript
{
public:
    custom_totalizator_controler() : CreatureScript("custom_totalizator_controler") { }

    struct custom_totalizator_controlerAI : public ScriptedAI
    {
        custom_totalizator_controlerAI(Creature* creature) : ScriptedAI(creature)
        {
            for (uint32 i = 0; i < C_TOTALIZATORMOB_COUNT; ++i)
                if (Creature* mob = me->SummonCreature(TotalizatorMobIDs[i], PosMobStart[i], TEMPSUMMON_MANUAL_DESPAWN, 0, 0))
                    TotalizatorMobs.push_back(mob);
        }

        std::vector<Creature*> TotalizatorMobs;
        std::vector<ITRate> Rates;

        bool bStarted;
        bool bReset;
        bool bAnnounce1, bAnnounce3, bAnnounce0;
        uint64 uiWinner;
        uint64 uiWinnerIdx;

        uint32 TotalizatorTimer;
        uint32 ResetTimer;

        void Reset()
        {
            bStarted = false;
            bReset = true;
            bAnnounce1 = false;
            bAnnounce3 = false;
            bAnnounce0 = false;
            uiWinner = 0;
            uiWinnerIdx = 0;
            TotalizatorTimer = 4*MINUTE*IN_MILLISECONDS;
            ResetTimer = 20*IN_MILLISECONDS;
        }

        void UpdateAI(const uint32 diff)
        {
            if (TotalizatorTimer <= diff)
            {
                StartTotalizator();
                TotalizatorTimer = 4*MINUTE*IN_MILLISECONDS;
            }
            else TotalizatorTimer -= diff;

            if (TotalizatorTimer <= 3*MINUTE*IN_MILLISECONDS && !bAnnounce3)
            {
                me->MonsterSay("До старта осталось 3 минуты...", LANG_UNIVERSAL, NULL);
                bAnnounce3 = true;
            }
            else if (TotalizatorTimer <= 1*MINUTE*IN_MILLISECONDS && !bAnnounce1)
            {
                me->MonsterSay("До старта осталось 1 минута...", LANG_UNIVERSAL, NULL);
                bAnnounce1 = true;
            }
            else if (TotalizatorTimer <= 10*IN_MILLISECONDS && !bAnnounce0)
            {
                me->MonsterSay("До старта осталось 10 секунд...", LANG_UNIVERSAL, NULL);
                bAnnounce0 = true;
            }

            if (!bReset)
                if (ResetTimer <= diff)
                {
                    ResetTotalizator();
                    bReset = true;
                    ResetTimer = 20*IN_MILLISECONDS;
                }
                else ResetTimer -= diff;
        }

        void AddRate(Player* player, uint32 money, uint32 mob)
        {
            if (!GetRates(player))
            {
                ITRate annulled;
                annulled.m_player = player;
                annulled.m_rate = money;
                annulled.m_mob = (uint8)mob;

                Rates.push_back(annulled);
            }
            else
                me->MonsterWhisper("Вы успешно аннулировали свою ставку, золото отправлено в фонд Короля-Лича!", player->GetGUID(), false);
        }

        uint32 GetRates(Player* player)
        {
            for (std::vector<ITRate>::const_iterator itr = Rates.begin(); itr != Rates.end(); ++itr)
                if ((*itr).m_player == player)
                    return (*itr).m_rate;

            return 0;
        }

        uint32 GetMobRates(Player* player)
        {
            for (std::vector<ITRate>::const_iterator itr = Rates.begin(); itr != Rates.end(); ++itr)
                if ((*itr).m_player == player)
                    return (*itr).m_mob;

            return 0;
        }

        void ProcessRates(uint32 winner)
        {
            for (std::vector<ITRate>::const_iterator itr = Rates.begin(); itr != Rates.end(); ++itr)
                if (Player* player = (*itr).m_player)
                    if (player && (*itr).m_mob == winner)
                        RewardRate(player);

            ClearRates(); // Удалить все
        }

        void RewardRate(Player* player)
        {
            if (uint32 rate = GetRates(player))
                if (rate > 0)
                {
                    uint32 itemchancef = rate/50;
                    if (itemchancef > 45)
                        itemchancef = 45; // Max. 45%

                    bool item = (urand(0, 100) <= itemchancef) ? true : false;

                    if (!item) // Нет Item = Отправить деньги
                    {
                        std::string subject = "Тотализатор";
                        std::string text    = "Вы выиграли Гонку, денежный приз!";
                        int32 money = (int32)(rate * 1.4f + (int32)rate/10)*10000;

                        MailSender sender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM);
                        SQLTransaction trans = CharacterDatabase.BeginTransaction();

                        MailDraft(subject, text)
                            .AddMoney(money)
                            .SendMailTo(trans, MailReceiver(player, GUID_LOPART(player->GetGUID())), sender);

                        CharacterDatabase.CommitTransaction(trans);
                    }
                    else
                    {
                        uint32 chance = urand(0, 100);
                        uint32 item_id = 0;

                        if (chance <= 13)
                            item_id = 49426; // Эмблема льда
                        else
                            switch (urand(0, 2))
                        {
                            case 0:
                                item_id = 57000; // Красный Ивент-кристалл
                                break;
                            case 1:
                                item_id = 57001; // Зеленый Ивент-кристалл
                                break;
                            case 2:
                                item_id = 57002; // Синий Ивент-кристалл
                                break;
                        }

                        std::string subject = "Тотализатор";
                        std::string text    = "Вы выиграли Гонку - ваш приз!";
                        int32 money = (int32)(rate * 1.3f + (int32)rate/10)*10000;

                        MailSender sender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM);
                        MailDraft draft(subject, text);

                        SQLTransaction trans = CharacterDatabase.BeginTransaction();

                        if (Item* item = Item::CreateItem(item_id, 1, player))
                        {
                            item->SaveToDB(trans);
                            draft.AddItem(item);
                        }
                        draft.AddMoney(money);

                        draft.SendMailTo(trans, MailReceiver(player, GUID_LOPART(player->GetGUID())), sender);
                        CharacterDatabase.CommitTransaction(trans);
                    }

                    player->SaveToDB();

                    // награда
                    char buff[2048];
                    sprintf(buff, "- %s выиграл(а) что-то.", player->GetName());
                    me->MonsterSay(buff, LANG_UNIVERSAL, NULL);
                }
        }

        void ClearRates()
        {
            Rates.clear();
        }

        void StartTotalizator()
        {
            bStarted = true;
            int i = 0;
            for (std::vector<Creature*>::const_iterator itr = TotalizatorMobs.begin(); itr != TotalizatorMobs.end(); ++itr)
            {
                if (!(*itr))
                    continue;

                float speed = (rand() / (float(RAND_MAX) + 1)) * (2.4f - 0.12f) + 0.12f; // * (max - min) + min;

                (*itr)->SetHomePosition(PosMobEnd[i].GetPositionX(), PosMobEnd[i].GetPositionY(), PosMobEnd[i].GetPositionZ(), 3.12f);
                (*itr)->SetSpeed(MOVE_WALK, speed, true);
                (*itr)->SetSpeed(MOVE_RUN, speed, true);

                /*char buff[2048];
                sprintf(buff, "%s %f", (*itr)->GetName(), speed);
                me->MonsterSay(buff, LANG_UNIVERSAL, NULL);*/

                (*itr)->GetMotionMaster()->MoveTargetedHome();
                ++i;
            }
        }

        void StopTotalizator()
        {
            bStarted = false;
            for (std::vector<Creature*>::const_iterator itr = TotalizatorMobs.begin(); itr != TotalizatorMobs.end(); ++itr)
            {
                if (!(*itr))
                    continue;

                (*itr)->GetMotionMaster()->Clear(true);
                (*itr)->StopMoving();
            }
        }

        void ResetTotalizator()
        {
            bStarted = false;

            int i = 0;
            for (std::vector<Creature*>::const_iterator itr = TotalizatorMobs.begin(); itr != TotalizatorMobs.end(); ++itr)
            {
                if (!(*itr))
                    continue;

                (*itr)->SetHomePosition(PosMobStart[i].GetPositionX(), PosMobStart[i].GetPositionY(), PosMobStart[i].GetPositionZ(), 3.12f);
                (*itr)->GetMotionMaster()->MoveTargetedHome();
                ++i;
            }
        }

        void Reached(uint64 uiGUID, uint32 uiEntry)
        {
            for (std::vector<Creature*>::const_iterator itr = TotalizatorMobs.begin(); itr != TotalizatorMobs.end(); ++itr)
            {
                if (!(*itr))
                    continue;

                if (uiGUID == (*itr)->GetGUID() && bStarted)
                {
                    StopTotalizator();
                    uiWinner = uiGUID;

                    switch (uiEntry) //creature_template entry
                    {
                    case 99110:
                        uiWinnerIdx = 1; // Киска
                        break;
                    case 99111:
                        uiWinnerIdx = 2; // Убийца комаров
                        break;
                    case 99112:
                        uiWinnerIdx = 3; // Флинк с веслом
                        break;
                    case 99113:
                        uiWinnerIdx = 4; // Саламандра
                        break;
                    case 99114:
                        uiWinnerIdx = 5; // Бырло
                        break;
                    case 99115:
                        uiWinnerIdx = 6; // Ангелочек
                        break;
                    default:
                        uiWinnerIdx = 0;
                        break;
                    }

                    (*itr)->CastSpell((*itr), SPELL_FIREWORK, true);

                    char buff[2048];
                    sprintf(buff, "У нас есть победитель! %s выиграл(а) гонку!", (*itr)->GetName());
                    me->MonsterSay(buff, LANG_UNIVERSAL, NULL);

                    ProcessRates(uiWinnerIdx);
                    bAnnounce3 = false;
                    bAnnounce1 = false;
                    bAnnounce0 = false;
                    bReset = false;
                }
                else if (!bStarted)
                {
                    (*itr)->SetOrientation(3.12f);
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new custom_totalizator_controlerAI(creature);
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Ваша ставка в ЗОЛОТЕ:", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        //player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "DEBUG: Вознаграждение", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();

        switch (action)
        {
        case GOSSIP_ACTION_INFO_DEF + 1:
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "На кого вы хотите сделать ставку? 1 ед. = 1 золотому", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

            player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_DOT, "Киска", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11, "Сколько золота вы хотите положить на ставку?", 0, true);
            player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_DOT, "Убийца комаров", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12, "Сколько золота вы хотите положить на ставку?", 0, true);
            player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_DOT, "Флинк с веслом", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 13, "Сколько золота вы хотите положить на ставку?", 0, true);
            player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_DOT, "Саламандра ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 14, "Сколько золота вы хотите положить на ставку?", 0, true);
            player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_DOT, "Бырло", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 15, "Сколько золота вы хотите положить на ставку?", 0, true);
            player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_DOT, "Ангелочек", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 16, "Сколько золота вы хотите положить на ставку?", 0, true);

            player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:
            player->CLOSE_GOSSIP_MENU();
            //CAST_AI(custom_totalizator_controler::custom_totalizator_controlerAI, creature->AI())->RewardRate(player);
            break;
        }

        return true;
    }

    bool OnGossipSelectCode(Player* player, Creature* creature, uint32 sender, uint32 action, const char* code)
    {
        player->PlayerTalkClass->ClearMenus();

        if (sender == GOSSIP_SENDER_MAIN)
        {
            if (action > GOSSIP_ACTION_INFO_DEF + 10 && action < GOSSIP_ACTION_INFO_DEF + 17 && atoi(code) > 0)
            {
                if (player->GetMoney() >= (uint32)atol(code)*10000)
                {
                    player->ModifyMoney(-1 * (int32)atoi(code)*10000);
                    uint32 idx = action - 1010;
                    CAST_AI(custom_totalizator_controler::custom_totalizator_controlerAI, creature->AI())->AddRate(player, (uint32)atol(code), idx);

                    char* mobname = "";
                    switch (idx) //creature_template entry
                    {
                    case 1: mobname = "Киска";
                        break;
                    case 2: mobname = "Убийца комаров";
                        break;
                    case 3: mobname = "Флинк с веслом";
                        break;
                    case 4: mobname = "Саламандра ";
                        break;
                    case 5: mobname = "Бырло";
                        break;
                    case 6: mobname = "Ангелочек";
                        break;
                    default: mobname = "";
                    }
                    char buff[2048];
                    sprintf(buff, "Вы поставили: %s золота, на гонщика %s. Ожидайте старта...", code, mobname);
                    creature->MonsterWhisper(buff, player->GetGUID());
                }
                else
                    creature->MonsterWhisper("Вы не можете позволить это себе!", player->GetGUID());
                player->CLOSE_GOSSIP_MENU();
            }
            return true;
        }

        return false;
    }
};

class custom_totalizator_participant : public CreatureScript
{
public:
    custom_totalizator_participant() : CreatureScript("custom_totalizator_participant") { }

    struct custom_totalizator_participantAI : public ScriptedAI
    {
        custom_totalizator_participantAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        void JustReachedHome()
        {
            if (Creature* cControler = me->FindNearestCreature(99116, 150.0f))
                CAST_AI(custom_totalizator_controler::custom_totalizator_controlerAI, cControler->AI())->Reached(me->GetGUID(), me->GetEntry());
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new custom_totalizator_participantAI(creature);
    }
};

void AddSC_custom_totalizator()
{
    new custom_totalizator_controler();
    new custom_totalizator_participant();
}
