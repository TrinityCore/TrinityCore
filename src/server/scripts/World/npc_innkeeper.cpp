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

enum Npc
{
    NPC_GOSSIP_MENU = 9733,
    NPC_GOSSIP_MENU_EVENT = 342,
};

class npc_innkeeper : public CreatureScript
{
public:
    npc_innkeeper() : CreatureScript("npc_innkeeper") { }

    struct npc_innkeeperAI : public ScriptedAI
    {
        npc_innkeeperAI(Creature* creature) : ScriptedAI(creature) { }

        bool OnGossipHello(Player* player) override
        {
            InitGossipMenuFor(player, NPC_GOSSIP_MENU);
            if (IsHolidayActive(HOLIDAY_HALLOWS_END) && !player->HasAura(SPELL_TRICK_OR_TREATED))
                AddGossipItemFor(player, NPC_GOSSIP_MENU_EVENT, 0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

            if (me->IsQuestGiver())
                player->PrepareQuestMenu(me->GetGUID());

            if (me->IsVendor())
                AddGossipItemFor(player, NPC_GOSSIP_MENU, 2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

            if (me->IsInnkeeper())
                AddGossipItemFor(player, NPC_GOSSIP_MENU, 1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INN);

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
