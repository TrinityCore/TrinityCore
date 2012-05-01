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
Name: npc_mount
Complete:
Author patch based, supported by: Easy ????
Modified patch, supported by; Wasy
Category: Custom
End */

#include "ScriptPCH.h"

#define MSG_GOSSIP_TEXT_MOUNT "Я хотел бы арендовать лошадь."
#define MSG_COMBAT            "Вы находитесь в бою!"
#define MSG_HI_LEVEL          "У вас слишком большой уровень...(макс 67лв.)"
#define MSG_MOUTED            "Вы уже на средстве передвижения."
#define MSG_THANKS            "Нет, спасибо."

enum mount_spell_id
{
    SWIFT_WHITE_HAWKSTRIDER    = 46628,
    GREAT_BLUE_ELEKK           = 35713,
    FROST_RAM                  = 17460,
    FROST_SABER_OLD            = 16056,
    GREAT_WHITE_KODO           = 23247,
    SWIFT_BROWN_WOLF           = 23250,
    SWIFT_ORANGE_RAPTOR        = 23243,
    SWIFT_WHITE_MECHANOSTRIDER = 23223,
    SWIFT_BROWN_STEED          = 23229,
    DEATHCHARGER               = 17481
};

class npc_mount : public CreatureScript
{
public:
    npc_mount() : CreatureScript("npc_mount") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, MSG_GOSSIP_TEXT_MOUNT, GOSSIP_SENDER_MAIN, 1000);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, MSG_THANKS, GOSSIP_SENDER_MAIN, 1001);

        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
        return true;
    }

    void SendDefaultMenu_npc_mount(Player* player, Creature* creature, uint32 action)
    {
        if (player->isInCombat())
        {
            player->CLOSE_GOSSIP_MENU();
            creature->MonsterSay(MSG_COMBAT, LANG_UNIVERSAL, NULL);
            return;
        }
        switch (action)
        {
        case 1000:
            if (player->getLevel()>67)
            {
                creature->MonsterWhisper(MSG_HI_LEVEL, player->GetGUID());
                player->CLOSE_GOSSIP_MENU();
                break;
            }
            if (player->IsMounted())
            {
                creature->MonsterWhisper(MSG_MOUTED, player->GetGUID());
                player->CLOSE_GOSSIP_MENU();
                break;
            }
            player->CLOSE_GOSSIP_MENU();
            switch (player->getRace())
            {
                /*Horde*/
            case RACE_ORC:
                player->CastSpell(player, SWIFT_BROWN_WOLF, false);
                break;
            case RACE_TAUREN:
                player->CastSpell(player, GREAT_WHITE_KODO, false);
                break;
            case RACE_TROLL:
                player->CastSpell(player, SWIFT_ORANGE_RAPTOR, false);
                break;
            case RACE_BLOODELF:
                player->CastSpell(player, SWIFT_WHITE_HAWKSTRIDER, false);
                break;
            case RACE_UNDEAD_PLAYER:
                player->CastSpell(player, DEATHCHARGER, false);
                break;
                /*Alliance*/
            case RACE_HUMAN:
                player->CastSpell(player, SWIFT_BROWN_STEED, false);
                break;
            case RACE_DWARF:
                player->CastSpell(player, FROST_RAM, false);
                break;
            case RACE_NIGHTELF:
                player->CastSpell(player, FROST_SABER_OLD, false);
                break;
            case RACE_GNOME:
                player->CastSpell(player, SWIFT_WHITE_MECHANOSTRIDER, false);
                break;
            case RACE_DRAENEI:
                player->CastSpell(player, GREAT_BLUE_ELEKK, false);
                break;
            }
            break;
        case 1001:
            player->CLOSE_GOSSIP_MENU();
            break;
        }
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
    {
        if (sender == GOSSIP_SENDER_MAIN)
            SendDefaultMenu_npc_mount(player, creature, action);
        return true;
    }
};

void AddSC_npc_mount()
{
    new npc_mount;
}
