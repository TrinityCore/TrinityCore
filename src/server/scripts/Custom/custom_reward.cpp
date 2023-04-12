///*
//* This file is part of the Pandaria 5.4.8 Project. See THANKS file for Copyright information
//*
//* This program is free software; you can redistribute it and/or modify it
//* under the terms of the GNU General Public License as published by the
//* Free Software Foundation; either version 2 of the License, or (at your
//* option) any later version.
//*
//* This program is distributed in the hope that it will be useful, but WITHOUT
//* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
//* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
//* more details.
//*
//* You should have received a copy of the GNU General Public License along
//* with this program. If not, see <http://www.gnu.org/licenses/>.
//*/
//
//#include "Chat.h"
//
//#define GetText(a, b, c) a->GetSession()->GetSessionDbLocaleIndex() == LOCALE_ruRU ? b : c
//
//#define TR_Enabled sWorld->getBoolConfig(CONFIG_TIME_REWARD_ENABLED)
//#define TR_Item_Enabled sWorld->getBoolConfig(CONFIG_TIME_REWARD_ITEM_ENABLED)
//#define TR_Item_ID sWorld->getIntConfig(CONFIG_TIME_REWARD_ITEM_ID)
//#define TR_Item_Count sWorld->getIntConfig(CONFIG_TIME_REWARD_ITEM_COUNT)
//#define TR_VP_Count sWorld->getIntConfig(CONFIG_TIME_REWARD_VP_COUNT)
//
//class played_time_reward : public PlayerScript
//{
//public:
//    played_time_reward() : PlayerScript("played_time_reward") { }
//
//    uint32 timeInterval = 0;
//
//    void OnUpdate(Player* player, uint32 diff)
//    {
//        timeInterval += diff;
//
//        if (timeInterval >= player->ptr_Interval)
//        {
//            timeInterval -= player->ptr_Interval;
//
//            if (player->IsInWorld() && TR_Enabled)
//            {
//                ChatHandler(player->GetSession()).PSendSysMessage(GetText(player, "Бонус за проведенное в игре время.", "Bonus for played time."));
//
//                if (TR_Item_Enabled)
//                {
//                    player->AddItem(TR_Item_ID, TR_Item_Count);
//                }
//                else
//                {
//                    //PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BATTLEPAY_INCREMENT_VIRTUAL_POINTS);
//                    /*stmt->setUInt32(0, TR_VP_Count);
//                    stmt->setUInt32(1, player->GetSession()->GetAccountId());
//                    LoginDatabase.Query(stmt);*/
//                }
//            }
//        }
//    }
//};
//
//void AddSC_custom_reward()
//{
//    new played_time_reward();
//}
