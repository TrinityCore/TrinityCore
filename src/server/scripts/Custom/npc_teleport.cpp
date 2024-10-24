/*
 * Copyright (C) 20??-2008 Wilibald09
 * Copyright (C) 2011-2015 ArkCORE <http://www.arkania.net/>
 * Copyright (C) 2008-2019 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "sc_npc_teleport.h"
#include "Creature.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "WorldSession.h"
#include <sstream>

#define GOSSIP_SHOW_DEST        1000
#define GOSSIP_TELEPORT         1001
#define GOSSIP_NEXT_PAGEC       1002
#define GOSSIP_PREV_PAGEC       1003
#define GOSSIP_NEXT_PAGED       1004
#define GOSSIP_PREV_PAGED       1005
#define GOSSIP_MAIN_MENU        1006

#define SPELL_ID_PASSIVE_RESURRECTION_SICKNESS  15007
#define SPELL_VISUAL_TELEPORT   35517

#define NB_ITEM_PAGE            15
#define MSG_CAT                 100000
#define MSG_DEST                100001

#define NEXT_PAGE               "-> [Next Page]"
#define PREV_PAGE               "<- [Previous Page]"
#define MAIN_MENU               "<= [Main Menu]"

using namespace nsNpcTel;

namespace
{
    Page PageC, PageD;
    Page Cat;

    // Conversion function int->string
    std::string ConvertStr(const int64 &val)
    {
        std::ostringstream ostr;
        ostr << val;
        return ostr.str();
    }

    // Conversion function intMoney->stringMoney
    std::string ConvertMoney(const uint32 &Money)
    {
        std::string Str(ConvertStr(Money));
        uint32 SizeStr = Str.length();

        if (SizeStr > 4)
            Str = Str.insert(Str.length()-4, "g");
        if (SizeStr > 2)
            Str = Str.insert(Str.length()-2, "s");
        Str += "c";

        return Str;
    }

    // Teleport Player
    void Teleport(Player * const player, const uint16 &map,
                  const float &X, const float &Y, const float &Z, const float &orient)
    {
        player->CastSpell(player, SPELL_VISUAL_TELEPORT, true);
        player->TeleportTo(map, X, Y, Z, orient);
    }

    // Display categories
    void AffichCat(Player * const player, Creature * const creature)
    {
        uint8 loc = player->GetSession()->GetSessionDbcLocale();

        if (PageC[player] > 0)
            AddGossipItemFor(player, GOSSIP_ICON_TALK, PREV_PAGE, GOSSIP_PREV_PAGEC, 0);

        VCatDest_t i (PageC[player] * NB_ITEM_PAGE);
        for ( ; i < TabCatDest.size() && i < (NB_ITEM_PAGE * (PageC[player] + 1)); ++i)
        {
            if (TabCatDest[i].IsAllowedToTeleport(player))
                AddGossipItemFor(player, GOSSIP_ICON_TRAINER, TabCatDest[i].GetName(loc, player->IsGameMaster()).c_str(), GOSSIP_SHOW_DEST, i); //book categorie
        }

        if (i < TabCatDest.size())
            AddGossipItemFor(player, GOSSIP_ICON_TALK, NEXT_PAGE, GOSSIP_NEXT_PAGEC, 0);

        SendGossipMenuFor(player, MSG_CAT, creature);
    }

    // Display destination categories
    void AffichDest(Player * const player, Creature * const creature)
    {
        uint8 loc = player->GetSession()->GetSessionDbcLocale();

        if (PageD[player] > 0)
            AddGossipItemFor(player, GOSSIP_ICON_TALK, PREV_PAGE, GOSSIP_PREV_PAGED, 0);

        CatDest::VDest_t i (PageD[player] * NB_ITEM_PAGE);
        for ( ; i < TabCatDest[Cat[player]].size() && i < (NB_ITEM_PAGE * (PageD[player] + 1)); ++i)
        {
            std::string icon = TabCatDest[Cat[player]].GetDest(i).m_icon;
            std::string size = TabCatDest[Cat[player]].GetDest(i).m_size;
            std::string name = TabCatDest[Cat[player]].GetDest(i).m_name[loc];
            if (name.length() == 0)
                name = TabCatDest[Cat[player]].GetDest(i).m_name[0];
            name = "|TInterface/ICONS/"+icon+":"+size+":"+size+"|t "+name;

            AddGossipItemFor(player, GOSSIP_ICON_TAXI, name.c_str(), GOSSIP_TELEPORT, i); //taxi destination
        }

        if (i < TabCatDest[Cat[player]].size())
            AddGossipItemFor(player, GOSSIP_ICON_TALK, NEXT_PAGE, GOSSIP_NEXT_PAGED, 0);

        if (CatDest::CountOfCategoryAllowedBy(player) > 1)
            AddGossipItemFor(player, GOSSIP_ICON_TALK, MAIN_MENU, GOSSIP_MAIN_MENU, 0);

        SendGossipMenuFor(player,MSG_DEST, creature);
    }

    // Verification before teleportation
    void ActionTeleport(Player * const player, Creature * const creature, const uint32 &id)
    {
        Dest dest (TabCatDest[Cat[player]].GetDest(id));

        if (player->GetLevel() < dest.m_level && !player->IsGameMaster())
        {
            LocaleConstant loc_idx = player->GetSession()->GetSessionDbLocaleIndex();
            char const* text = sObjectMgr->GetTrinityString(8000, loc_idx);
            std::string msg(text + (" " + ConvertStr(dest.m_level) + "."));

            creature->Whisper(msg.c_str(), LANG_UNIVERSAL, player);
            return;
        }

        if (player->GetMoney() < dest.m_cost && !player->IsGameMaster())
        {
            LocaleConstant loc_idx = player->GetSession()->GetSessionDbLocaleIndex();
            char const* text = sObjectMgr->GetTrinityString(8001, loc_idx);
            std::string msg(text + (" " + ConvertMoney(dest.m_cost) + "."));

            creature->Whisper(msg.c_str(), LANG_UNIVERSAL, player);
            return;
        }

        if (!player->IsGameMaster() && dest.m_cost)
            player->ModifyMoney(-1 * dest.m_cost);

        Teleport(player, dest.m_map, dest.m_X, dest.m_Y, dest.m_Z, dest.m_orient);
    }
}

class npc_teleport_gossip : public CreatureScript
{
    public:
        npc_teleport_gossip() : CreatureScript("npc_teleport") {}

        struct npc_teleport_gossipAI : public ScriptedAI
        {
            npc_teleport_gossipAI(Creature* creature) : ScriptedAI(creature) { }

            bool OnGossipHello(Player* player) override
            {
                PageC(player) = PageD(player) = Cat(player) = 0;

                if (player->IsInCombat())
                {
                    CloseGossipMenuFor(player);

                    LocaleConstant loc_idx = player->GetSession()->GetSessionDbLocaleIndex();
                    char const* text = sObjectMgr->GetTrinityString(8002, loc_idx);
                    me->Whisper(text, LANG_UNIVERSAL, player);

                    return true;
                }
                AffichCat(player, me);
                return true;
            }

            bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
            {
                uint32 const sender = player->PlayerTalkClass->GetGossipOptionSender(gossipListId);
                uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
                ClearGossipMenuFor(player);
                switch (sender)
                {
                    // Display destinations
                    case GOSSIP_SHOW_DEST:
                        Cat(player) = action;
                        AffichDest(player, me);
                        break;

                    // Previous categories page
                    case GOSSIP_PREV_PAGEC:
                        --PageC(player);
                        AffichCat(player, me);
                        break;

                    // Next page categories
                    case GOSSIP_NEXT_PAGEC:
                        ++PageC(player);
                        AffichCat(player, me);
                        break;

                    // Previous destinations page
                    case GOSSIP_PREV_PAGED:
                        --PageD(player);
                        AffichDest(player, me);
                        break;

                    // Next destination page
                    case GOSSIP_NEXT_PAGED:
                        ++PageD(player);
                        AffichDest(player, me);
                        break;

                    // Display main menu
                    case GOSSIP_MAIN_MENU:
                        OnGossipHello(player);
                        break;

                    // Teleportation
                    case GOSSIP_TELEPORT:
                        CloseGossipMenuFor(player);
                        if (player->HasAura(SPELL_ID_PASSIVE_RESURRECTION_SICKNESS)) {
                            DoCast(player, 38588, false); // Healing effect
                            player->RemoveAurasDueToSpell(SPELL_ID_PASSIVE_RESURRECTION_SICKNESS);
                        }

                        ActionTeleport(player, me, action);
                        break;
                }
                return true;
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_teleport_gossipAI(creature);
        }
};

class npc_teleport_load : public WorldScript
{
public:
    npc_teleport_load() : WorldScript("npc_teleport") {}

    void OnStartup() override
    {
        LoadNpcTele();
    }
};

void AddSC_npc_teleport()
{
    new npc_teleport_gossip();
    new npc_teleport_load();
}
// End of TeleNPC2
