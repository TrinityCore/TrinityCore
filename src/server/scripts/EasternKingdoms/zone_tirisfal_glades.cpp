/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "ObjectMgr.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "ScriptedCreature.h"
#include "Player.h"
#include "QuestDef.h"
#include "ScriptedGossip.h"

class npc_agatha : public CreatureScript
{
public:
    npc_agatha() : CreatureScript("npc_agatha") { }

    enum
    {
        QUEST_FRESH_OUT_OF_THE_GRAVE    = 24959,
        SPELL_RIGOR_MORTIS              = 73523
    };

    bool OnQuestAccept(Player* player, Creature* /*creature*/, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_FRESH_OUT_OF_THE_GRAVE)
            player->RemoveAurasDueToSpell(SPELL_RIGOR_MORTIS);

        return true;
    }
};

class npc_valdred_moray : public CreatureScript
{
public:
    npc_valdred_moray() : CreatureScript("npc_valdred_moray") { }

    enum
    {
        NPC_ID_VALDRED_MORAY        = 49231,
        QUEST_THE_WAKENING          = 24960,
        OPTION_ID_QUEST             = 0,
        MENU_ID_QUEST_PART_1        = 12487,
        MENU_ID_QUEST_PART_2        = 12488,
        MENU_ID_QUEST_PART_3        = 12489,
        NPC_TEXT_ID_PART_1          = 17569,
        NPC_TEXT_ID_PART_2          = 17570,
        NPC_TEXT_ID_PART_3          = 17571
    };

    bool OnGossipHello(Player* player, Creature* creature) override
    {

        if (player->GetQuestStatus(QUEST_THE_WAKENING) == QUEST_STATUS_INCOMPLETE)
        {
            AddGossipItemFor(player, MENU_ID_QUEST_PART_1, GOSSIP_ICON_CHAT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, NPC_TEXT_ID_PART_1, creature->GetGUID());

        }
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        ClearGossipMenuFor(player);
        if (action == GOSSIP_ACTION_INFO_DEF + 1)
        {
            AddGossipItemFor(player, MENU_ID_QUEST_PART_2, GOSSIP_ICON_CHAT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            SendGossipMenuFor(player, NPC_TEXT_ID_PART_2, creature->GetGUID());

        }
        else if (action == GOSSIP_ACTION_INFO_DEF + 2)
        {
            AddGossipItemFor(player, MENU_ID_QUEST_PART_3, GOSSIP_ICON_CHAT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
            SendGossipMenuFor(player, NPC_TEXT_ID_PART_3, creature->GetGUID());
        }
        else if (action == GOSSIP_ACTION_INFO_DEF + 3)
        {
            player->KilledMonsterCredit(NPC_ID_VALDRED_MORAY);
        }
        return true;
    }
};

class npc_lilian_voss : public CreatureScript
{
public:
    npc_lilian_voss() : CreatureScript("npc_lilian_voss") { }

    enum
    {
        NPC_ID_LILIAN_VOSS      = 38895,
        QUEST_THE_WAKENING      = 24960,
        OPTION_ID_QUEST         = 0,
        MENU_ID_QUEST_PART_1    = 12483,
        MENU_ID_QUEST_PART_2    = 12484,
        NPC_TEXT_ID_PART_1      = 17564,
        NPC_TEXT_ID_PART_2      = 17565
    };

    bool OnGossipHello(Player* player, Creature* creature) override
    {

        if (player->GetQuestStatus(QUEST_THE_WAKENING) == QUEST_STATUS_INCOMPLETE)
        {
            AddGossipItemFor(player, MENU_ID_QUEST_PART_1, GOSSIP_ICON_CHAT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, NPC_TEXT_ID_PART_1, creature->GetGUID());

        }
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        ClearGossipMenuFor(player);
        if (action == GOSSIP_ACTION_INFO_DEF + 1)
        {
            AddGossipItemFor(player, MENU_ID_QUEST_PART_2, GOSSIP_ICON_CHAT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            SendGossipMenuFor(player, NPC_TEXT_ID_PART_2, creature->GetGUID());

        }
        else if (action == GOSSIP_ACTION_INFO_DEF + 2)
        {
            player->KilledMonsterCredit(NPC_ID_LILIAN_VOSS);
        }

        return true;
    }
};

class npc_marshal_redpath : public CreatureScript
{
public:
    npc_marshal_redpath() : CreatureScript("npc_marshal_redpath") { }

    enum
    {
        NPC_ID_MARSHAL_REDPATH = 49230,
        QUEST_THE_WAKENING = 24960,
        OPTION_ID_QUEST = 0,
        MENU_ID_QUEST_PART_1 = 12485,
        MENU_ID_QUEST_PART_2 = 12486,
        NPC_TEXT_ID_PART_1 = 17566,
        NPC_TEXT_ID_PART_2 = 17567
    };

    bool OnGossipHello(Player* player, Creature* creature) override
    {

        if (player->GetQuestStatus(QUEST_THE_WAKENING) == QUEST_STATUS_INCOMPLETE)
        {
            AddGossipItemFor(player, MENU_ID_QUEST_PART_1, GOSSIP_ICON_CHAT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, NPC_TEXT_ID_PART_1, creature->GetGUID());

        }
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        ClearGossipMenuFor(player);
        if (action == GOSSIP_ACTION_INFO_DEF + 1)
        {
            AddGossipItemFor(player, MENU_ID_QUEST_PART_2, GOSSIP_ICON_CHAT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            SendGossipMenuFor(player, NPC_TEXT_ID_PART_2, creature->GetGUID());

        }
        else if (action == GOSSIP_ACTION_INFO_DEF + 2)
        {
            player->KilledMonsterCredit(NPC_ID_MARSHAL_REDPATH);
        }

        return true;
    }
};

class npc_scarlet_corpse : public CreatureScript
{
public:
    npc_scarlet_corpse() : CreatureScript("npc_scarlet_corpse") { }

    enum {
        QUEST_RECRUITMENT       = 26800,
        NPC_SCARLET_CORPSE      = 49340
    };

    struct npc_scarlet_corpseAI : public ScriptedAI
    {
        npc_scarlet_corpseAI(Creature* creature) : ScriptedAI(creature) { }

        void OnSpellClick(Unit* clicker, bool& /*result*/) override
        {
            if (clicker->ToPlayer()->GetQuestStatus(QUEST_RECRUITMENT) == QUEST_STATUS_INCOMPLETE)
            {
                clicker->ToPlayer()->KilledMonsterCredit(NPC_SCARLET_CORPSE);

                clicker->ToPlayer()->GetSelectedUnit()->Kill(clicker->ToPlayer()->GetSelectedUnit());
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_scarlet_corpseAI(creature);
    }
};

void AddSC_tirisfal_glades()
{
    new npc_scarlet_corpse();
    new npc_marshal_redpath();
    new npc_lilian_voss();
    new npc_valdred_moray();
    new npc_agatha();
}
