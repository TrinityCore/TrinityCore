/*
* This file is part of the Pandaria 5.4.8 Project. See THANKS file for Copyright information
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
//From:https://github.com/alexkulya/pandaria_5.4.8/blob/master/src/server/scripts/Custom/battle_pay_items.cpp

#include "ScriptMgr.h"
#include "GridNotifiersImpl.h"
#include "DatabaseEnv.h"
#include "Chat.h"
#include "ServiceMgr.h"
#include "Item.h"
#include "SmartScript.h"

#define GetText(a, b, c) a->GetSession()->GetSessionDbLocaleIndex() == LOCALE_ruRU ? b : c

namespace BattlePay
{
    enum Type :int64
    {
        Gold_1K = 10000000U,
        Gold_5K = 50000000U,
        Gold_10K = 100000000U,
        Gold_30K = 300000000U,
        Gold_80K = 800000000U,
        Gold_150K = 1500000000U,

        Points_1 = 10000,
        Points_2 = 20000,
        Points_5 = 50000,
        Points_10 = 100000
    };
}

enum SkillsID
{
    FIRST_AID       = 129, // First Aid
    BLACKSMITHING   = 164, // Blacksmithing
    LEATHERWORKING  = 165, // Leatherworking
    ALCHEMY         = 171, // Alchemy
    HERBALISM       = 182, // Herbalism
    COOKING         = 185, // Cooking
    MINING          = 186, // Mining
    TAILORING       = 197, // Tailoring
    ENGINEERING     = 202, // Engineering
    ENCHANTING      = 333, // Enchanting
    FISHING         = 356, // Fishing
    SKINNING        = 393, // Skinning
    JEWELCRAFTING   = 755, // Jewelcrafting
    INSCRIPTION     = 773, // Inscription
    ARCHAEOLOGY     = 794  // Archaeology
};

enum SpellID_600
{
    SPELL_600_FIRST_AID = 110406, // First Aid
    SPELL_600_BLACKSMITHING = 110396, // Blacksmithing
    SPELL_600_LEATHERWORKING = 110423, // Leatherworking
    SPELL_600_ALCHEMY = 105206, // Alchemy
    SPELL_600_HERBALISM = 110413, // Herbalism
    SPELL_600_COOKING = 104381, // Cooking
    SPELL_600_MINING = 102161, // Mining
    SPELL_600_TAILORING = 110426, // Tailoring
    SPELL_600_ENGINEERING = 110403, // Engineering
    SPELL_600_ENCHANTING = 110400, // Enchanting
    SPELL_600_FISHING = 110410, // Fishing
    SPELL_600_SKINNING = 102216, // Skinning
    SPELL_600_JEWELCRAFTING = 110420, // Jewelcrafting
    SPELL_600_INSCRIPTION = 110417, // Inscription
    SPELL_600_ARCHAEOLOGY = 110393  // Archaeology
};

class battle_pay_currency_honor_1000 : public ItemScript
{
public:
    battle_pay_currency_honor_1000(const char* ScriptName) : ItemScript(ScriptName) { }

    bool OnUse(Player* player, Item* item, SpellCastTargets const& /*targets*/, ObjectGuid /*castId*/) override
    {
        if (player->IsInCombat() || player->InArena() || player->InBattleground())
        {
            player->GetSession()->SendNotification(GetText(player, "Вы не можете использовать этот жетон, пока находитесь в бою, на арене или поле боя.", "You may not use this token whilst you are in combat or present in an arena or battleground."));
        }
        else if (player->HasItemCount(item->GetEntry(), 1, true))
        {
            player->ModifyCurrency(392, 1000 * 100);//CURRENCY_PRECISION
            ChatHandler(player->GetSession()).SendSysMessage(GetText(player, "Спасибо за помощь проекту Pandaria 5.4.8, вы только что получили 1000 очков чести.", "Thanks for helping the Pandaria 5.4.8 project, you just received 1000 honor points."));
            player->DestroyItemCount(item->GetEntry(), 1, true);
            player->SaveToDB();
        }
        else
        {
            ChatHandler(player->GetSession()).SendSysMessage(GetText(player, "У вас нет необходимого жетона.", "You do not have the necessary token."));
        }
        return true;
    }
};

class battle_pay_currency_justice_1000 : public ItemScript
{
public:
    battle_pay_currency_justice_1000(const char* ScriptName) : ItemScript(ScriptName) { }

    bool OnUse(Player* player, Item* item, SpellCastTargets const& /*targets*/, ObjectGuid /*castId*/) override
    {
        if (player->IsInCombat() || player->InArena() || player->InBattleground())
        {
            player->GetSession()->SendNotification(GetText(player, "Вы не можете использовать этот жетон, пока находитесь в бою, на арене или поле боя.", "You may not use this token whilst you are in combat or present in an arena or battleground."));
        }
        else if (player->HasItemCount(item->GetEntry(), 1, true))
        {
            //player->ModifyCurrency(CURRENCY_TYPE_JUSTICE_POINTS, 1000 * CURRENCY_PRECISION, true, true, true);//org
            player->ModifyCurrency(395, 1000 * 100);//CURRENCY_TYPE_JUSTICE_POINTS-->395,CURRENCY_PRECISION->100
            ChatHandler(player->GetSession()).SendSysMessage(GetText(player, "Спасибо за помощь проекту Pandaria 5.4.8, вы только что получили 1000 очков справедливости.", "Thanks for helping the Pandaria 5.4.8 project, you just received 1000 justice points."));
            player->DestroyItemCount(item->GetEntry(), 1, true);
            player->SaveToDB();
        }
        else
        {
            ChatHandler(player->GetSession()).SendSysMessage(GetText(player, "У вас нет необходимого жетона.", "You do not have the necessary token."));
        }
        return true;
    }
};

class battle_pay_currency_valor_1000 : public ItemScript
{
public:
    battle_pay_currency_valor_1000(const char* ScriptName) : ItemScript(ScriptName) { }

    bool OnUse(Player* player, Item* item, SpellCastTargets const& /*targets*/, ObjectGuid /*castId*/) override
    {
        if (player->IsInCombat() || player->InArena() || player->InBattleground())
        {
            player->GetSession()->SendNotification(GetText(player, "Вы не можете использовать этот жетон, пока находитесь в бою, на арене или поле боя.", "You may not use this token whilst you are in combat or present in an arena or battleground."));
        }
        else if (player->HasItemCount(item->GetEntry(), 1, true))
        {
            player->ModifyCurrency(396, 1000 * 100);// CURRENCY_TYPE_VALOR_POINTS = 396,CURRENCY_PRECISION=100
            //player->ModifyCurrency(CURRENCY_TYPE_VALOR_POINTS, 1000 * CURRENCY_PRECISION, true, true, true);//org
            ChatHandler(player->GetSession()).SendSysMessage(GetText(player, "Спасибо за помощь проекту Pandaria 5.4.8, вы только что получили 1000 очков доблести.", "Thanks for helping the Pandaria 5.4.8 project, you just received 1000 valor points."));
            player->DestroyItemCount(item->GetEntry(), 1, true);
            player->SaveToDB();
        }
        else
        {
            ChatHandler(player->GetSession()).SendSysMessage(GetText(player, "У вас нет необходимого жетона.", "You do not have the necessary token."));
        }
        return true;
    }
};

class battle_pay_currency_conquest_1000 : public ItemScript
{
public:
    battle_pay_currency_conquest_1000(const char* ScriptName) : ItemScript(ScriptName) { }

    bool OnUse(Player* player, Item* item, SpellCastTargets const& /*targets*/, ObjectGuid /*castId*/) override
    {
        if (player->IsInCombat() || player->InArena() || player->InBattleground())
        {
            player->GetSession()->SendNotification(GetText(player, "Вы не можете использовать этот жетон, пока находитесь в бою, на арене или поле боя.", "You may not use this token whilst you are in combat or present in an arena or battleground."));
        }
        else if (player->HasItemCount(item->GetEntry(), 1, true))
        {
            player->ModifyCurrency(390, 1000 * 100);//CURRENCY_PRECISION=100
            ChatHandler(player->GetSession()).SendSysMessage(GetText(player, "Спасибо за помощь проекту Pandaria 5.4.8, вы только что получили 1000 очков завоевания.", "Thanks for helping the Pandaria 5.4.8 project, you just received 1000 conquest points."));
            player->DestroyItemCount(item->GetEntry(), 1, true);
            player->SaveToDB();
        }
        else
        {
            ChatHandler(player->GetSession()).SendSysMessage(GetText(player, "У вас нет необходимого жетона.", "You do not have the necessary token."));
        }
        return true;
    }
};

template<int64 Gold>
class battle_pay_gold : public ItemScript
{
public:
    battle_pay_gold(const char* ScriptName) : ItemScript(ScriptName) { }

    bool OnUse(Player* player, Item* item, SpellCastTargets const& /*targets*/, ObjectGuid /*castId*/) override
    {
        if (player->IsInCombat() || player->InArena() || player->InBattleground())
        {
            player->GetSession()->SendNotification(GetText(player, "Вы не можете использовать этот жетон, пока находитесь в бою, на арене или поле боя.", "You may not use this token whilst you are in combat or present in an arena or battleground."));
        }
        else if (uint64(player->GetMoney() + Gold) > MAX_MONEY_AMOUNT)
        {
            ChatHandler(player->GetSession()).SendSysMessage(GetText(player, "Превышен максимально допустимый лимит золота.", "Maximum allowed gold limit exceeded."));
        }
        else
        {
            player->ModifyMoney(Gold);
            player->DestroyItemCount(item->GetEntry(), 1, true);

            std::ostringstream gold_amount_message_ru, gold_amount_message_en;
            gold_amount_message_ru << "Спасибо за помощь проекту Pandaria 5.4.8, вы только что получили " << Gold / 10000 << " золотых.";
            gold_amount_message_en << "Thanks for helping the Pandaria 5.4.8 project, you just received " << Gold / 10000 << " gold.";
            ChatHandler(player->GetSession()).SendSysMessage(GetText(player, gold_amount_message_ru.str().c_str(), gold_amount_message_en.str().c_str()));
            player->SaveToDB();
        }
        return true;
    }
};

template<uint32 Level>
class battle_pay_level : public ItemScript
{
public:
    battle_pay_level(const char* ScriptName) : ItemScript(ScriptName) { }

    bool OnUse(Player* player, Item* item, SpellCastTargets const& /*targets*/, ObjectGuid /*castId*/) override
    {
        if (player->IsInCombat() || player->InArena() || player->InBattleground())
        {
            player->GetSession()->SendNotification(GetText(player, "Вы не можете использовать этот жетон, пока находитесь в бою, на арене или поле боя.", "You may not use this token whilst you are in combat or present in an arena or battleground."));
        }
        else if (Level <= player->getLevel())
        {
            ChatHandler(player->GetSession()).SendSysMessage(GetText(player, "Текущий уровень вашего персонажа слишком высокий.", "Your current character level is too high."));
        }
        else
        {
            player->GiveLevel(Level);
            ChatHandler(player->GetSession()).SendSysMessage(GetText(player, "Спасибо за помощь проекту Pandaria 5.4.8, вы только что повысили уровень своего порсонажа до 90-го.", "Thanks for helping the Pandaria 5.4.8 project, you just leveled up your character to level 90."));
            player->DestroyItemCount(item->GetEntry(), 1, true);
            player->SaveToDB();
        }
        return true;
    }
};

template<AtLoginFlags FlagAtLogin>
class battle_pay_service : public ItemScript
{
public:
    battle_pay_service(const char* ScriptName) : ItemScript(ScriptName) { }

    bool OnUse(Player* player, Item* item, SpellCastTargets const& /*targets*/, ObjectGuid /*castId*/) override
    {
        if (player->IsInCombat() || player->InArena() || player->InBattleground())
        {
            player->GetSession()->SendNotification(GetText(player, "Вы не можете использовать этот жетон, пока находитесь в бою, на арене или поле боя.", "You may not use this token whilst you are in combat or present in an arena or battleground."));
        }
        else if (player->HasAtLoginFlag((AtLoginFlags)0xFFFFFFFF))
        {
            ChatHandler(player->GetSession()).SendSysMessage(GetText(player, "Вы уже активировали эту функцию.", "You have already activated this feature."));
        }
        else
        {
            player->SetAtLoginFlag(FlagAtLogin);
            player->DestroyItemCount(item->GetEntry(), 1, true);
            ChatHandler(player->GetSession()).SendSysMessage(GetText(player, "Спасибо за помощь проекту Pandaria 5.4.8, вы только что активировали функцию по изменению своего персонажа. Пожалуйста перезайдите на свою учетную запись.", "Thanks for helping the Pandaria 5.4.8 project, you have just activated the function to change your character. Please re-login to your account."));
            player->SaveToDB();
        }
        return true;
    }
};

template<int64 Points>
class battle_pay_pandaria_token : public ItemScript
{
public:
    battle_pay_pandaria_token(const char* ScriptName) : ItemScript(ScriptName) { }

    bool OnUse(Player* player, Item* item, SpellCastTargets const& /*targets*/, ObjectGuid /*castId*/) override
    {
        if (player->IsInCombat() || player->InArena() || player->InBattleground())
        {
            player->GetSession()->SendNotification(GetText(player, "Вы не можете использовать этот жетон, пока находитесь в бою, на арене или поле боя.", "You may not use this token whilst you are in combat or present in an arena or battleground."));
        }
        else
        {
            //player->AddVirtualPointsCount(Points);
            player->DestroyItemCount(item->GetEntry(), 1, true);

            std::ostringstream points_amount_message_ru, points_amount_message_en;
            points_amount_message_ru << "Спасибо за помощь проекту Pandaria 5.4.8, вы только что получили виртуальных очков: " << Points / 10000;
            points_amount_message_en << "Thanks for helping the Pandaria 5.4.8 project, you just received virtual poins: " << Points / 10000;
            ChatHandler(player->GetSession()).SendSysMessage(GetText(player, points_amount_message_ru.str().c_str(), points_amount_message_en.str().c_str()));
            player->SaveToDB();
        }
        return true;
    }
};

class battle_pay_boost_profession : public ItemScript
{
public:
    battle_pay_boost_profession(const char* ScriptName) : ItemScript(ScriptName) { }

    bool OnUse(Player* player, Item* /*item*/, SpellCastTargets const& /*targets*/, ObjectGuid /*castId*/) override 
    {
        //bool ru = player->GetSession()->GetSessionDbLocaleIndex() == LOCALE_ruRU;

        player->PlayerTalkClass->ClearMenus();
        player->SaveToDB();

        /*if (player->HasSkill(FIRST_AID))
            player->ADD_GOSSIP_ITEM_DB(51002, 0, GOSSIP_SENDER_MAIN, FIRST_AID);
        if (player->HasSkill(BLACKSMITHING))
            player->ADD_GOSSIP_ITEM_DB(51002, 1, GOSSIP_SENDER_MAIN, BLACKSMITHING);
        if (player->HasSkill(LEATHERWORKING))
            player->ADD_GOSSIP_ITEM_DB(51002, 2, GOSSIP_SENDER_MAIN, LEATHERWORKING);
        if (player->HasSkill(ALCHEMY))
            player->ADD_GOSSIP_ITEM_DB(51002, 3, GOSSIP_SENDER_MAIN, ALCHEMY);
        if (player->HasSkill(HERBALISM))
            player->ADD_GOSSIP_ITEM_DB(51002, 4, GOSSIP_SENDER_MAIN, HERBALISM);
        if (player->HasSkill(COOKING))
            player->ADD_GOSSIP_ITEM_DB(51002, 5, GOSSIP_SENDER_MAIN, COOKING);
        if (player->HasSkill(MINING))
            player->ADD_GOSSIP_ITEM_DB(51002, 6, GOSSIP_SENDER_MAIN, MINING);
        if (player->HasSkill(TAILORING))
            player->ADD_GOSSIP_ITEM_DB(51002, 7, GOSSIP_SENDER_MAIN, TAILORING);
        if (player->HasSkill(ENGINEERING))
            player->ADD_GOSSIP_ITEM_DB(51002, 8, GOSSIP_SENDER_MAIN, ENGINEERING);
        if (player->HasSkill(ENCHANTING))
            player->ADD_GOSSIP_ITEM_DB(51002, 9, GOSSIP_SENDER_MAIN, ENCHANTING);
        if (player->HasSkill(FISHING))
            player->ADD_GOSSIP_ITEM_DB(51002, 10, GOSSIP_SENDER_MAIN, FISHING);
        if (player->HasSkill(SKINNING))
            player->ADD_GOSSIP_ITEM_DB(51002, 11, GOSSIP_SENDER_MAIN, SKINNING);
        if (player->HasSkill(JEWELCRAFTING))
            player->ADD_GOSSIP_ITEM_DB(51002, 12, GOSSIP_SENDER_MAIN, JEWELCRAFTING);
        if (player->HasSkill(INSCRIPTION))
            player->ADD_GOSSIP_ITEM_DB(51002, 13, GOSSIP_SENDER_MAIN, INSCRIPTION);
        if (player->HasSkill(ARCHAEOLOGY))
            player->ADD_GOSSIP_ITEM_DB(51002, 14, GOSSIP_SENDER_MAIN, ARCHAEOLOGY);

        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, ru ? "|TInterface/PaperDollInfoFrame/UI-GearManager-LeaveItem-Transparent:28|t Закрыть" : "|TInterface/PaperDollInfoFrame/UI-GearManager-LeaveItem-Transparent:28|t Close", GOSSIP_SENDER_MAIN, 1);
        player->SEND_GOSSIP_MENU(20010, item->GetGUID());*/
        return true;
    }

    void OnGossipSelect(Player* player, Item* item, uint32 /*sender*/, uint32 action)
    {
        bool ru = player->GetSession()->GetSessionDbLocaleIndex() == LOCALE_ruRU;

        player->PlayerTalkClass->ClearMenus();
        uint32 confirm = 0;

        switch (action)
        {
        /*case 1:
            player->CLOSE_GOSSIP_MENU();
            break;*/
        case FIRST_AID:
            if (!player->HasSpell(SPELL_600_FIRST_AID))
            {
                player->LearnSpell(SPELL_600_FIRST_AID, false);
                confirm = 1;
            }
            break;
        case BLACKSMITHING:
            if (!player->HasSpell(SPELL_600_BLACKSMITHING))
            {
                player->LearnSpell(SPELL_600_BLACKSMITHING, false);
                confirm = 1;
            }
            break;
        case LEATHERWORKING:
            if (!player->HasSpell(SPELL_600_LEATHERWORKING))
            {
                player->LearnSpell(SPELL_600_LEATHERWORKING, false);
                confirm = 1;
            }
            break;
        case ALCHEMY:
            if (!player->HasSpell(SPELL_600_ALCHEMY))
            {
                player->LearnSpell(SPELL_600_ALCHEMY, false);
                confirm = 1;
            }
            break;
        case HERBALISM:
            if (!player->HasSpell(SPELL_600_HERBALISM))
            {
                player->LearnSpell(SPELL_600_HERBALISM, false);
                confirm = 1;
            }
            break;
        case COOKING:
            if (!player->HasSpell(SPELL_600_COOKING))
            {
                player->LearnSpell(SPELL_600_COOKING, false);
                confirm = 1;
            }
            break;
        case MINING:
            if (!player->HasSpell(SPELL_600_MINING))
            {
                player->LearnSpell(SPELL_600_MINING, false);
                confirm = 1;
            }
            break;
        case TAILORING:
            if (!player->HasSpell(SPELL_600_TAILORING))
            {
                player->LearnSpell(SPELL_600_TAILORING, false);
                confirm = 1;
            }
            break;
        case ENGINEERING:
            if (!player->HasSpell(SPELL_600_ENGINEERING))
            {
                player->LearnSpell(SPELL_600_ENGINEERING, false);
                confirm = 1;
            }
            break;
        case ENCHANTING:
            if (!player->HasSpell(SPELL_600_ENCHANTING))
            {
                player->LearnSpell(SPELL_600_ENCHANTING, false);
                confirm = 1;
            }
            break;
        case FISHING:
            if (!player->HasSpell(SPELL_600_FISHING))
            {
                player->LearnSpell(SPELL_600_FISHING, false);
                confirm = 2;
            }
            break;
        case SKINNING:
            if (!player->HasSpell(SPELL_600_SKINNING))
            {
                player->LearnSpell(SPELL_600_SKINNING, false);
                confirm = 1;
            }
            break;
        case JEWELCRAFTING:
            if (!player->HasSpell(SPELL_600_JEWELCRAFTING))
            {
                player->LearnSpell(SPELL_600_JEWELCRAFTING, false);
                confirm = 1;
            }
            break;
        case INSCRIPTION:
            if (!player->HasSpell(SPELL_600_INSCRIPTION))
            {
                player->LearnSpell(SPELL_600_INSCRIPTION, false);
                confirm = 1;
            }
            break;
        case ARCHAEOLOGY:
            if (!player->HasSpell(SPELL_600_ARCHAEOLOGY))
            {
                player->LearnSpell(SPELL_600_ARCHAEOLOGY, false);
                confirm = 1;
            }
            break;
        }

        if (confirm == 1)
        {
            int32 max_value_prof = player->GetMaxSkillValue(action);

            if (player->HasSkill(action) && player->GetSkillValue(action) < max_value_prof)
                player->SetSkill(action, player->GetSkillStep(action), max_value_prof, max_value_prof);

            ChatHandler(player->GetSession()).PSendSysMessage(ru ? "Спасибо за поддержку проекта!" : "Thanks for supporting the project!");
            player->DestroyItemCount(item->GetEntry(), 1, true);

            std::ostringstream infoSkill;
            infoSkill << "Skill: " << uint32(action) << " Value: " << uint32(max_value_prof);
            sServiceMgr->ExecutedServices(player->GetGUID().GetCounter(), SERVICE_TYPE_BOOST_PROFESSION, std::string("Boosted name: ") + player->GetName(), infoSkill.str());
            //player->CLOSE_GOSSIP_MENU;
        }
        else if (confirm == 2)
        {
            player->SetSkill(action, player->GetSkillStep(action), 600, 600);

            ChatHandler(player->GetSession()).PSendSysMessage(ru ? "Спасибо за поддержку проекта!" : "Thanks for supporting the project!");
            player->DestroyItemCount(item->GetEntry(), 1, true);

            std::ostringstream infoSkill;
            infoSkill << "Skill: " << uint32(action) << " Value: 600";
            sServiceMgr->ExecutedServices(player->GetGUID().GetCounter(), SERVICE_TYPE_BOOST_PROFESSION, std::string("Boosted name: ") + player->GetName(), infoSkill.str());
            //player->CLOSE_GOSSIP_MENU();
        }
        else
        {
            ChatHandler(player->GetSession()).PSendSysMessage(ru ? "Произошла ошибка." : "An error has occurred.");
            player->CastSpell(player, 27880, true);
        }

        player->SaveToDB();
    }
};

class battle_pay_boost_profession_small : public ItemScript
{
public:
    battle_pay_boost_profession_small(const char* ScriptName) : ItemScript(ScriptName) { }

    bool OnUse(Player* player, Item* /*item*/, SpellCastTargets const& /*targets*/, ObjectGuid /*castId*/) override
    {
        //bool ru = player->GetSession()->GetSessionDbLocaleIndex() == LOCALE_ruRU;

        player->PlayerTalkClass->ClearMenus();
        player->SaveToDB();

        //if (player->HasSkill(FIRST_AID))
        //    player->ADD_GOSSIP_ITEM_DB(51002, 0, GOSSIP_SENDER_MAIN, FIRST_AID);
        //if (player->HasSkill(BLACKSMITHING))
        //    player->ADD_GOSSIP_ITEM_DB(51002, 1, GOSSIP_SENDER_MAIN, BLACKSMITHING);
        //if (player->HasSkill(LEATHERWORKING))
        //    player->ADD_GOSSIP_ITEM_DB(51002, 2, GOSSIP_SENDER_MAIN, LEATHERWORKING);
        //if (player->HasSkill(ALCHEMY))
        //    player->ADD_GOSSIP_ITEM_DB(51002, 3, GOSSIP_SENDER_MAIN, ALCHEMY);
        //if (player->HasSkill(HERBALISM))
        //    player->ADD_GOSSIP_ITEM_DB(51002, 4, GOSSIP_SENDER_MAIN, HERBALISM);
        //if (player->HasSkill(COOKING))
        //    player->ADD_GOSSIP_ITEM_DB(51002, 5, GOSSIP_SENDER_MAIN, COOKING);
        //if (player->HasSkill(MINING))
        //    player->ADD_GOSSIP_ITEM_DB(51002, 6, GOSSIP_SENDER_MAIN, MINING);
        //if (player->HasSkill(TAILORING))
        //    player->ADD_GOSSIP_ITEM_DB(51002, 7, GOSSIP_SENDER_MAIN, TAILORING);
        //if (player->HasSkill(ENGINEERING))
        //    player->ADD_GOSSIP_ITEM_DB(51002, 8, GOSSIP_SENDER_MAIN, ENGINEERING);
        //if (player->HasSkill(ENCHANTING))
        //    player->ADD_GOSSIP_ITEM_DB(51002, 9, GOSSIP_SENDER_MAIN, ENCHANTING);
        //if (player->HasSkill(FISHING))
        //    player->ADD_GOSSIP_ITEM_DB(51002, 10, GOSSIP_SENDER_MAIN, FISHING);
        //if (player->HasSkill(SKINNING))
        //    player->ADD_GOSSIP_ITEM_DB(51002, 11, GOSSIP_SENDER_MAIN, SKINNING);
        //if (player->HasSkill(JEWELCRAFTING))
        //    player->ADD_GOSSIP_ITEM_DB(51002, 12, GOSSIP_SENDER_MAIN, JEWELCRAFTING);
        //if (player->HasSkill(INSCRIPTION))
        //    player->ADD_GOSSIP_ITEM_DB(51002, 13, GOSSIP_SENDER_MAIN, INSCRIPTION);
        //if (player->HasSkill(ARCHAEOLOGY))
        //    player->ADD_GOSSIP_ITEM_DB(51002, 14, GOSSIP_SENDER_MAIN, ARCHAEOLOGY);

        //player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, ru ? "|TInterface/PaperDollInfoFrame/UI-GearManager-LeaveItem-Transparent:28|t Закрыть" : "|TInterface/PaperDollInfoFrame/UI-GearManager-LeaveItem-Transparent:28|t Close", GOSSIP_SENDER_MAIN, 1);
        //player->SEND_GOSSIP_MENU(20011, item->GetGUID());
        return true;
    }

    void OnGossipSelect(Player* player, Item* item, uint32 /*sender*/, uint32 action)
    {
        bool ru = player->GetSession()->GetSessionDbLocaleIndex() == LOCALE_ruRU;

        player->PlayerTalkClass->ClearMenus();

        if (player->HasSkill(action))
        {
            int32 max_value_prof = player->GetMaxSkillValue(action);

            if (player->HasSkill(action) && player->GetSkillValue(action) < max_value_prof)
                player->SetSkill(action, player->GetSkillStep(action), max_value_prof, max_value_prof);

            ChatHandler(player->GetSession()).PSendSysMessage(ru ? "Спасибо за поддержку проекта!" : "Thanks for supporting the project!");
            player->DestroyItemCount(item->GetEntry(), 1, true);

            std::ostringstream infoSkill;
            infoSkill << "Skill: " << uint32(action) << " Value: " << uint32(max_value_prof);
            sServiceMgr->ExecutedServices(player->GetGUID().GetCounter(), SERVICE_TYPE_BOOST_PROFESSION_SMALL, std::string("Boosted name: ") + player->GetName(), infoSkill.str());
            player->SaveToDB();
        }
        else
        {
            ChatHandler(player->GetSession()).PSendSysMessage(ru ? "Произошла ошибка." : "An error has occurred.");
            player->CastSpell(player, 27880, true);
        }

        //player->CLOSE_GOSSIP_MENU();
    }
};

void AddSC_battle_pay_items()
{
    new battle_pay_currency_honor_1000("battle_pay_currency_honor_1000");
    new battle_pay_currency_justice_1000("battle_pay_currency_justice_1000");
    new battle_pay_currency_valor_1000("battle_pay_currency_valor_1000");
    new battle_pay_currency_conquest_1000("battle_pay_currency_conquest_1000");
    new battle_pay_gold<BattlePay::Gold_1K>("battle_pay_gold_1k");
    new battle_pay_gold<BattlePay::Gold_5K>("battle_pay_gold_5k");
    new battle_pay_gold<BattlePay::Gold_10K>("battle_pay_gold_10k");
    new battle_pay_gold<BattlePay::Gold_30K>("battle_pay_gold_30k");
    new battle_pay_gold<BattlePay::Gold_80K>("battle_pay_gold_80k");
    new battle_pay_gold<BattlePay::Gold_150K>("battle_pay_gold_150k");
    new battle_pay_level<90>("battle_pay_service_level_90");
    new battle_pay_service<AtLoginFlags::AT_LOGIN_RENAME>("battle_pay_service_rename");
    new battle_pay_service<AtLoginFlags::AT_LOGIN_CHANGE_FACTION>("battle_pay_service_change_faction");
    new battle_pay_service<AtLoginFlags::AT_LOGIN_CHANGE_RACE>("battle_pay_service_change_race");
    new battle_pay_service<AtLoginFlags::AT_LOGIN_CUSTOMIZE>("battle_pay_service_customize");
    new battle_pay_pandaria_token<BattlePay::Points_1>("battle_pay_pandaria_token_1");
    new battle_pay_pandaria_token<BattlePay::Points_2>("battle_pay_pandaria_token_2");
    new battle_pay_pandaria_token<BattlePay::Points_5>("battle_pay_pandaria_token_5");
    new battle_pay_pandaria_token<BattlePay::Points_10>("battle_pay_pandaria_token_10");
    new battle_pay_boost_profession("battle_pay_boost_profession");
    new battle_pay_boost_profession_small("battle_pay_boost_profession_small");
}
