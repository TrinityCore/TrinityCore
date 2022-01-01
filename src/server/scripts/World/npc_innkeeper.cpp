/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

/* ScriptData
SDName: Npc_Innkeeper
SDAuthor: WarHead
SD%Complete: 99%
SDComment: Complete
SDCategory: NPCs
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "GameEventMgr.h"
#include "Player.h"
#include "WorldSession.h"

enum Spells
{
    SPELL_TRICK_OR_TREATED      = 24755,
    SPELL_TREAT                 = 24715
};

#define LOCALE_TRICK_OR_TREAT_0 "Trick or Treat!"
#define LOCALE_TRICK_OR_TREAT_1 "트릭 오어 트릿!"
#define LOCALE_TRICK_OR_TREAT_2 "Des bonbons ou des blagues!"
#define LOCALE_TRICK_OR_TREAT_3 "Süßes oder Saures!"
#define LOCALE_TRICK_OR_TREAT_4 "不给糖果就捣蛋！"
#define LOCALE_TRICK_OR_TREAT_5 "不給糖果就搗蛋！"
#define LOCALE_TRICK_OR_TREAT_6 "¡Truco o trato!"
#define LOCALE_TRICK_OR_TREAT_7 "Truco o trato!"
#define LOCALE_TRICK_OR_TREAT_8 "Кошелек или жизнь!"

#define LOCALE_INNKEEPER_0 "Make this inn my home."
#define LOCALE_INNKEEPER_1 "이거 내 집에서 만들어."
#define LOCALE_INNKEEPER_2 "Faites de cette auberge votre foyer."
#define LOCALE_INNKEEPER_3 "Ich möchte dieses Gasthaus zu meinem Heimatort machen."
#define LOCALE_INNKEEPER_4 "让这个旅馆成为我的家。"
#define LOCALE_INNKEEPER_5 "讓這個旅館成爲我的家。"
#define LOCALE_INNKEEPER_6 "Fija tu hogar en esta taberna."
#define LOCALE_INNKEEPER_7 "Haz esto en mi casa."
#define LOCALE_INNKEEPER_8 "Сделай это в моем доме."

#define LOCALE_VENDOR_0 "I want to browse your goods."
#define LOCALE_VENDOR_1 "나는 당신의 상품을 검색하고 싶습니다."
#define LOCALE_VENDOR_2 "Je voudrais regarder vos articles."
#define LOCALE_VENDOR_3 "Ich sehe mich nur mal um."
#define LOCALE_VENDOR_4 "我想浏览一下你的货物。"
#define LOCALE_VENDOR_5 "我想游覽一下你的貨物。"
#define LOCALE_VENDOR_6 "Quiero ver tus mercancías."
#define LOCALE_VENDOR_7 "Quiero navegar por tus productos."
#define LOCALE_VENDOR_8 "Я хочу просмотреть ваши товары."

class npc_innkeeper : public CreatureScript
{
public:
    npc_innkeeper() : CreatureScript("npc_innkeeper") { }

    struct npc_innkeeperAI : public ScriptedAI
    {
        npc_innkeeperAI(Creature* creature) : ScriptedAI(creature) { }

        bool OnGossipHello(Player* player) override
        {
            if (IsHolidayActive(HOLIDAY_HALLOWS_END) && !player->HasAura(SPELL_TRICK_OR_TREATED))
            {
                char const* localizedEntry;
                switch (player->GetSession()->GetSessionDbcLocale())
                {
                    case LOCALE_koKR: localizedEntry = LOCALE_TRICK_OR_TREAT_1; break;
                    case LOCALE_frFR: localizedEntry = LOCALE_TRICK_OR_TREAT_2; break;
                    case LOCALE_deDE: localizedEntry = LOCALE_TRICK_OR_TREAT_3; break;
                    case LOCALE_zhCN: localizedEntry = LOCALE_TRICK_OR_TREAT_4; break;
                    case LOCALE_zhTW: localizedEntry = LOCALE_TRICK_OR_TREAT_5; break;
                    case LOCALE_esES: localizedEntry = LOCALE_TRICK_OR_TREAT_6; break;
                    case LOCALE_esMX: localizedEntry = LOCALE_TRICK_OR_TREAT_7; break;
                    case LOCALE_ruRU: localizedEntry = LOCALE_TRICK_OR_TREAT_8; break;
                    case LOCALE_enUS: default: localizedEntry = LOCALE_TRICK_OR_TREAT_0;
                }
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, localizedEntry, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            }

            if (me->IsQuestGiver())
                player->PrepareQuestMenu(me->GetGUID());

            if (me->IsVendor())
            {
                char const* localizedEntry;
                switch (player->GetSession()->GetSessionDbcLocale())
                {
                    case LOCALE_koKR: localizedEntry = LOCALE_VENDOR_1; break;
                    case LOCALE_frFR: localizedEntry = LOCALE_VENDOR_2; break;
                    case LOCALE_deDE: localizedEntry = LOCALE_VENDOR_3; break;
                    case LOCALE_zhCN: localizedEntry = LOCALE_VENDOR_4; break;
                    case LOCALE_zhTW: localizedEntry = LOCALE_VENDOR_5; break;
                    case LOCALE_esES: localizedEntry = LOCALE_VENDOR_6; break;
                    case LOCALE_esMX: localizedEntry = LOCALE_VENDOR_7; break;
                    case LOCALE_ruRU: localizedEntry = LOCALE_VENDOR_8; break;
                    case LOCALE_enUS: default: localizedEntry = LOCALE_VENDOR_0;
                }
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, localizedEntry, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);
            }

            if (me->IsInnkeeper())
            {
                char const* localizedEntry;
                switch (player->GetSession()->GetSessionDbcLocale())
                {
                    case LOCALE_koKR: localizedEntry = LOCALE_INNKEEPER_1; break;
                    case LOCALE_frFR: localizedEntry = LOCALE_INNKEEPER_2; break;
                    case LOCALE_deDE: localizedEntry = LOCALE_INNKEEPER_3; break;
                    case LOCALE_zhCN: localizedEntry = LOCALE_INNKEEPER_4; break;
                    case LOCALE_zhTW: localizedEntry = LOCALE_INNKEEPER_5; break;
                    case LOCALE_esES: localizedEntry = LOCALE_INNKEEPER_6; break;
                    case LOCALE_esMX: localizedEntry = LOCALE_INNKEEPER_7; break;
                    case LOCALE_ruRU: localizedEntry = LOCALE_INNKEEPER_8; break;
                    case LOCALE_enUS: default: localizedEntry = LOCALE_INNKEEPER_0;
                }
                AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, localizedEntry, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INN);
            }

            player->TalkedToCreature(me->GetEntry(), me->GetGUID());
            SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);
            if (action == GOSSIP_ACTION_INFO_DEF + 1 && IsHolidayActive(HOLIDAY_HALLOWS_END) && !player->HasAura(SPELL_TRICK_OR_TREATED))
            {
                player->CastSpell(player, SPELL_TRICK_OR_TREATED, true);

                if (urand(0, 1))
                    player->CastSpell(player, SPELL_TREAT, true);
                else
                {
                    uint32 trickspell = 0;
                    switch (urand(0, 13))
                    {
                        case 0: trickspell = 24753; break; // cannot cast, random 30sec
                        case 1: trickspell = 24713; break; // lepper gnome costume
                        case 2: trickspell = 24735; break; // male ghost costume
                        case 3: trickspell = 24736; break; // female ghostcostume
                        case 4: trickspell = 24710; break; // male ninja costume
                        case 5: trickspell = 24711; break; // female ninja costume
                        case 6: trickspell = 24708; break; // male pirate costume
                        case 7: trickspell = 24709; break; // female pirate costume
                        case 8: trickspell = 24723; break; // skeleton costume
                        case 9: trickspell = 24753; break; // Trick
                        case 10: trickspell = 24924; break; // Hallow's End Candy
                        case 11: trickspell = 24925; break; // Hallow's End Candy
                        case 12: trickspell = 24926; break; // Hallow's End Candy
                        case 13: trickspell = 24927; break; // Hallow's End Candy
                    }
                    player->CastSpell(player, trickspell, true);
                }
                CloseGossipMenuFor(player);
                return true;
            }

            CloseGossipMenuFor(player);

            switch (action)
            {
                case GOSSIP_ACTION_TRADE: player->GetSession()->SendListInventory(me->GetGUID()); break;
                case GOSSIP_ACTION_INN: player->SetBindPoint(me->GetGUID()); break;
            }
            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_innkeeperAI(creature);
    }
};

void AddSC_npc_innkeeper()
{
    new npc_innkeeper();
}
