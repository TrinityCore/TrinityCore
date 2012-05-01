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
Name: Doctor
Complete:
Author patch, supported by: Wasy
Category: Custom
End*/

#include "ScriptPCH.h"

// uint
uint32 RemoveByteFlag;
bool IsReset;
// Instance Unbind
Field* fields;
uint16 id;

class npc_customize_doctor : public CreatureScript
{
public:
    npc_customize_doctor() : CreatureScript("npc_customize_doctor") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        //Show Main Menu
        if (player->isInCombat()) {
            player->CLOSE_GOSSIP_MENU();
            creature->MonsterWhisper("Вы находитесь в бою. Приходите позже!", player->GetGUID());
            return true;
        } else {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Доктор... я хочу изменить свое имя, мне нужно скрыться!", GOSSIP_SENDER_MAIN, 1001);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Доктор... я хочу сделать пластическую операцию по смене Внешнего вида и Пола!", GOSSIP_SENDER_MAIN, 1002);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Доктор… мне нужна инъекция вражеской ДНК, я хочу сменить Фракцию (Альянс/Орда)... Это реально?", GOSSIP_SENDER_MAIN, 1003);

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            return true;
        }
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
    {
        if (sender != GOSSIP_SENDER_MAIN)
            return false;

        player->PlayerTalkClass->ClearMenus();

        switch (action)
        {
        case 1001:
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Стоимость услуги по смене имени 1500 Золотых. Вас устраивает?", GOSSIP_SENDER_MAIN, 1013);
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            break;
        case 1002:
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Стоимость Пластической хирургии 2500 Золотых. Вас устраивает?", GOSSIP_SENDER_MAIN, 1014);
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            break;
        case 1003:
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Стоимость Инъекции 20000 Золотых. Вас устраивает?", GOSSIP_SENDER_MAIN, 1015);
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            break;
        case 1013:
            if (player->GetMoney() < 15000000)
            {
                creature->MonsterWhisper("Тайные службы сообщили, что вы банкрот! Проваливайте, пусть вас поймают...", player->GetGUID());
            }else{
                player->ModifyMoney(-15000000);
                player->SetAtLoginFlag(AT_LOGIN_RENAME);
                creature->MonsterWhisper("Готово, теперь выйди из игры и зайди снова. Вам будет предложено ввести новое Имя!", player->GetGUID());
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 1014:
            if (player->GetMoney() < 25000000)
            {
                creature->MonsterWhisper("Тайные службы сообщили, что вы банкрот! Проваливайте, пусть вас поймают...", player->GetGUID());
            }else{
                player->ModifyMoney(-25000000);
                player->SetAtLoginFlag(AT_LOGIN_CUSTOMIZE);
                creature->MonsterWhisper("Готово противн.., теперь выйди из игры и зайди снова. Вам будет предложено изменить свой Внешний вид и Пол!", player->GetGUID());
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 1015:
            if (player->GetMoney() < 200000000)
            {
                creature->MonsterWhisper("Тайные службы сообщили, что вы банкрот! Проваливайте, пусть вас поймают...", player->GetGUID());
            }else{
                player->ModifyMoney(-200000000);
                player->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
                creature->MonsterWhisper("Готово, теперь выйди из игры и зайди снова. Вам будет предложено сменить Фракцию (Альянс/Орда)!", player->GetGUID());
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        default:
            player->CLOSE_GOSSIP_MENU();
        }
        return true;
    }
};

class npc_customize_pvp : public CreatureScript
{
public:
    npc_customize_pvp() : CreatureScript("npc_customize_pvp") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        //Show Main Menu
        if (player->isInCombat()) {
            player->CLOSE_GOSSIP_MENU();
            creature->MonsterWhisper("Вы находитесь в бою. Приходите позже!", player->GetGUID());
            return true;
        } else {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Восстановление здоровья.", GOSSIP_SENDER_MAIN, 1004);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Восстановление маны.", GOSSIP_SENDER_MAIN, 1005);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Сброс КД заклинаний.", GOSSIP_SENDER_MAIN, 1006);

            switch (player->GetTeam())
            {
            case ALLIANCE:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Удалить Изнеможение.", GOSSIP_SENDER_MAIN, 1007);
                break;
            case HORDE:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Удалить Пересыщение.", GOSSIP_SENDER_MAIN, 1008);
                break;
            default:
                break;
            }

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            return true;
        }
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
    {
        if (sender != GOSSIP_SENDER_MAIN)
            return false;

        player->PlayerTalkClass->ClearMenus();

        switch (action)
        {
        case 1004:
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Стоимость услуги по Восстановлению здоровья 10 меди. Вас устраивает?", GOSSIP_SENDER_MAIN, 1016);
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            break;
        case 1005:
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Стоимость услуги по Восстановлению маны 10 меди. Вас устраивает?", GOSSIP_SENDER_MAIN, 1017);
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            break;
        case 1006:
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Стоимость услуги по Сбросу КД заклинаний 10 меди. Вас устраивает?", GOSSIP_SENDER_MAIN, 1018);
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            break;
        case 1007:
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Стоимость услуги по Удалению Изнеможения 10 меди. Вас устраивает?", GOSSIP_SENDER_MAIN, 1019);
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            break;
        case 1008:
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Стоимость услуги по Удалению Пересыщения 10 меди. Вас устраивает?", GOSSIP_SENDER_MAIN, 1020);
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            break;
        case 1016:
            if (player->GetMoney() < 10)
            {
                creature->MonsterWhisper("Тайные службы сообщили, что вы банкрот!", player->GetGUID());
            }else{
                player->ModifyMoney(-10);
                player->SetHealth(player->GetMaxHealth());
                player->CastSpell(player, 61456, false);
                creature->MonsterWhisper("Ваше здоровье было восстановлено.", player->GetGUID());
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 1017:
            if (player->GetMoney() < 10)
            {
                creature->MonsterWhisper("Тайные службы сообщили, что вы банкрот!", player->GetGUID());
            }else{
                player->ModifyMoney(-10);
                player->SetPower(POWER_MANA, player->GetMaxPower(POWER_MANA));
                player->CastSpell(player, 61456, false);
                creature->MonsterWhisper("Ваша мана была восстановлена.", player->GetGUID());
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 1018:
            if (player->GetMoney() < 10)
            {
                creature->MonsterWhisper("Тайные службы сообщили, что вы банкрот!", player->GetGUID());
            }else{
                player->ModifyMoney(-10);
                player->RemoveAllSpellCooldown();
                player->CastSpell(player, 75459, false);
                creature->MonsterWhisper("Ваш кулдауны были удалены.", player->GetGUID());
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 1019:
            if (player->GetMoney() < 10)
            {
                creature->MonsterWhisper("Тайные службы сообщили, что вы банкрот!", player->GetGUID());
            }else{
                player->ModifyMoney(-10);
                player->RemoveAurasDueToSpell(57723);
                player->CastSpell(player, 61456, false);
                creature->MonsterWhisper("Изнеможение успешно удалено.", player->GetGUID());
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 1020:
            if (player->GetMoney() < 10)
            {
                creature->MonsterWhisper("Тайные службы сообщили, что вы банкрот!", player->GetGUID());
            }else{
                player->ModifyMoney(-10);
                player->RemoveAurasDueToSpell(57724);
                player->CastSpell(player, 61456, false);
                creature->MonsterWhisper("Пересыщение успешно удалено.", player->GetGUID());
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        default:
            player->CLOSE_GOSSIP_MENU();
        }
        return true;
    }
};

class npc_customize_reset : public CreatureScript
{
public:
    npc_customize_reset() : CreatureScript("npc_customize_reset") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        //Show Main Menu
        if (player->isInCombat()) {
            player->CLOSE_GOSSIP_MENU();
            creature->MonsterWhisper("Вы находитесь в бою. Приходите позже!", player->GetGUID());
            return true;
        } else {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Удалить все ауры", GOSSIP_SENDER_MAIN, 1009);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Удалить PvP флаги", GOSSIP_SENDER_MAIN, 1010);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Сброс КД на все данжи", GOSSIP_SENDER_MAIN, 1011);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Удалить Слабость после воскрешения", GOSSIP_SENDER_MAIN, 1012);

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            return true;
        }
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
    {
        if (sender != GOSSIP_SENDER_MAIN)
            return false;

        player->PlayerTalkClass->ClearMenus();

        switch (action)
        {
        case 1009:
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Стоимость услуги по Удалению всех аур 5 меди. Вас устраивает?", GOSSIP_SENDER_MAIN, 1021);
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            break;
        case 1010:
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Стоимость услуги по Удалению PvP флагов 5 меди. Вас устраивает?", GOSSIP_SENDER_MAIN, 1022);
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            break;
        case 1011:
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Стоимость услуги по Сбросу КД на все данжи 2 марки. Вас устраивает?", GOSSIP_SENDER_MAIN, 1023);
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            break;
        case 1012:
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Стоимость услуги по Удалению Слабости после воскрешения 1 Золотой. Вас устраивает?", GOSSIP_SENDER_MAIN, 1024);
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            break;
        case 1021:
            if (player->GetMoney() < 5)
            {
                creature->MonsterWhisper("Тайные службы сообщили, что вы банкрот!", player->GetGUID());
            }else{
                player->ModifyMoney(-5);
                player->RemoveAllAuras();
                creature->MonsterWhisper("Ауры успешно удалены.", player->GetGUID());
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 1022:
            if (player->GetMoney() < 1000)
            {
                creature->MonsterWhisper("Тайные службы сообщили, что вы банкрот!", player->GetGUID());
            }else{
                player->ModifyMoney(-1000);
                //player->CastSpell(player, 20762, true),
                player->RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_CONTESTED_PVP),
                    player->RemoveByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_PVP),
                    player->RemoveByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP),
                    player->RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_PVP_TIMER),
                    player->RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_IN_PVP),
                    creature->MonsterWhisper("PvP флаги успешно удалены.", player->GetGUID());
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 1023:
            if (player->GetMoney() < 1000)
            {
                creature->MonsterWhisper("Тайные службы сообщили, что вы банкрот!", player->GetGUID());
            }else{
                player->ModifyMoney(-1000);
                for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
                {
                    Player::BoundInstancesMap &binds = player->GetBoundInstances(Difficulty(i));
                    for (Player::BoundInstancesMap::iterator itr = binds.begin(); itr != binds.end();)
                    {
                        if (itr->first != player->GetMapId())
                        {
                            player->UnbindInstance(itr, Difficulty(i));
                            player->CLOSE_GOSSIP_MENU();
                        }
                        else
                            ++itr;
                    }
                }
                creature->MonsterWhisper("Все КД на данжи сброшены.", player->GetGUID());
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        case 1024:
            if (player->GetMoney() < 10000)
            {
                creature->MonsterWhisper("Тайные службы сообщили, что вы банкрот!", player->GetGUID());
            }else{
                player->ModifyMoney(-10000);
                creature->CastSpell(player, 38588, false);
                player->RemoveAurasDueToSpell(15007, 0);
                creature->MonsterWhisper("Слабость после воскрешения успешно удалена.", player->GetGUID());
            }
            player->CLOSE_GOSSIP_MENU();
            break;
        default:
            player->CLOSE_GOSSIP_MENU();
        }
        return true;
    }
};


void AddSC_npc_customize()
{
    new npc_customize_doctor();
    new npc_customize_pvp();
    new npc_customize_reset();
}