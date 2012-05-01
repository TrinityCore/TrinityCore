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
Name: custom_goldperlevel
Complete:
Author patch based, supported by: ????
Modified patch, supported by; Wasy
Category: Custom
End */

#include "ScriptPCH.h"

class custom_goldperlevel : public PlayerScript
{
public:
    custom_goldperlevel() : PlayerScript("custom_goldperlevel") {}

    void OnLevelChanged(Player* player, uint8 newLevel)
    {
        std::string subject = "Поздравляем!";
        std::string text    = "Спонсор Alive-Legends дарит вам золото, которое поможет вам в развитии ваших заклинаний и профессий. Спасибо за то, что выбрали наш сервер, желаем удачи и приятной игры!";
        uint32 money        = 0;

        switch (newLevel)
        {
        case 10:
            if (player->getClass() != CLASS_DEATH_KNIGHT)
            {
                money = 100000;
                subject = "10 уровень!";
                text = "Поздравляем с достижением 10 уровня! Спонсор Alive-Legends дарит вам золото, которое поможет вам в развитии ваших заклинаний и профессий. Спасибо за то, что выбрали наш сервер, желаем удачи и приятной игры!";
            }
            break;
        case 20:
            if (player->getClass() != CLASS_DEATH_KNIGHT)
            {
                money = 150000;
                subject = "20 уровень!";
                text = "Поздравляем с достижением 20 уровня! Спонсор Alive-Legends дарит вам золото, которое поможет вам в развитии ваших заклинаний и профессий. Спасибо за то, что выбрали наш сервер, желаем удачи и приятной игры!";
            }
            break;
        case 30:
            if (player->getClass() != CLASS_DEATH_KNIGHT)
            {
                money = 250000;
                subject = "30 уровень!";
                text = "Поздравляем с достижением 30 уровня! Спонсор Alive-Legends дарит вам золото, которое поможет вам в развитии ваших заклинаний и профессий. Спасибо за то, что выбрали наш сервер, желаем удачи и приятной игры!";
            }
            break;
        case 40:
            if (player->getClass() != CLASS_DEATH_KNIGHT)
            {
                money = 500000;
                subject = "40 уровень!";
                text = "Поздравляем с достижением 40 уровня! Спонсор Alive-Legends дарит вам золото, которое поможет вам в развитии ваших заклинаний и профессий. Спасибо за то, что выбрали наш сервер, желаем удачи и приятной игры!";
            }
            break;
        case 50:
            if (player->getClass() != CLASS_DEATH_KNIGHT)
            {
                money = 1000000;
                subject = "50 уровень!";
                text = "Поздравляем с достижением 50 уровня! Спонсор Alive-Legends дарит вам золото, которое поможет вам в развитии ваших заклинаний и профессий. Спасибо за то, что выбрали наш сервер, желаем удачи и приятной игры!";
            }
            break;
        default:
            break;
        }
        if (money != 0)
        {
            MailSender sender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM);

            SQLTransaction trans = CharacterDatabase.BeginTransaction();

            MailDraft(subject, text)
                .AddMoney(money)
                .SendMailTo(trans, MailReceiver(player, GUID_LOPART(player->GetGUID())), sender);

            CharacterDatabase.CommitTransaction(trans);
        }
    }
};

void AddSC_custom_goldperlevel()
{
    new custom_goldperlevel();
}