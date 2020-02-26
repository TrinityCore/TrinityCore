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
SDName: Hyjal
SD%Complete: 80
SDComment: gossip text id's unknown
SDCategory: Caverns of Time, Mount Hyjal
EndScriptData */

/* ContentData
npc_jaina_proudmoore
npc_thrall
npc_tyrande_whisperwind
EndContentData */

#include "ScriptMgr.h"
#include "hyjalAI.h"
#include "InstanceScript.h"
#include "Log.h"
#include "Player.h"
#include "ScriptedGossip.h"

#define GOSSIP_ITEM_BEGIN_ALLY      "My companions and I are with you, Lady Proudmoore."
#define GOSSIP_ITEM_ANETHERON       "We are ready for whatever Archimonde might send our way, Lady Proudmoore."

#define GOSSIP_ITEM_BEGIN_HORDE     "I am with you, Thrall."
#define GOSSIP_ITEM_AZGALOR         "We have nothing to fear."

#define GOSSIP_ITEM_RETREAT         "We can't keep this up. Let's retreat!"

#define GOSSIP_ITEM_TYRANDE         "Aid us in defending Nordrassil"
#define ITEM_TEAR_OF_GODDESS        24494

#define GOSSIP_ITEM_GM1             "[GM] Toggle Debug Timers"

class npc_jaina_proudmoore : public CreatureScript
{
    public:
        npc_jaina_proudmoore() : CreatureScript("npc_jaina_proudmoore") { }

        struct npc_jaina_proudmooreAI : public hyjalAI
        {
            npc_jaina_proudmooreAI(Creature* creature) : hyjalAI(creature)
            {
                Reset();

                Spells[0].SpellId = SPELL_BLIZZARD;
                Spells[0].Cooldown = urand(15000, 35000);
                Spells[0].TargetType = TARGETTYPE_RANDOM;

                Spells[1].SpellId = SPELL_PYROBLAST;
                Spells[1].Cooldown = urand(5500, 9500);
                Spells[1].TargetType = TARGETTYPE_RANDOM;

                Spells[2].SpellId = SPELL_SUMMON_ELEMENTALS;
                Spells[2].Cooldown = urand(15000, 45000);
                Spells[2].TargetType = TARGETTYPE_SELF;
            }

            bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
            {
                uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
                ClearGossipMenuFor(player);
                switch (action)
                {
                    case GOSSIP_ACTION_INFO_DEF + 1:
                        StartEvent(player);
                        break;
                    case GOSSIP_ACTION_INFO_DEF + 2:
                        FirstBossDead = true;
                        WaveCount = 9;
                        StartEvent(player);
                        break;
                    case GOSSIP_ACTION_INFO_DEF + 3:
                        Retreat();
                        break;
                    case GOSSIP_ACTION_INFO_DEF:
                        Debug = !Debug;
                        TC_LOG_DEBUG("scripts", "HyjalAI - Debug mode has been toggled");
                        break;
                }
                return true;
            }

            bool GossipHello(Player* player) override
            {
                if (EventBegun)
                    return false;

                uint32 RageEncounter = GetInstanceData(DATA_RAGEWINTERCHILLEVENT);
                uint32 AnetheronEncounter = GetInstanceData(DATA_ANETHERONEVENT);
                if (RageEncounter == NOT_STARTED)
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_BEGIN_ALLY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                else if (RageEncounter == DONE && AnetheronEncounter == NOT_STARTED)
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_ANETHERON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                else if (RageEncounter == DONE && AnetheronEncounter == DONE)
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_RETREAT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);

                if (player->IsGameMaster())
                    AddGossipItemFor(player, GOSSIP_ICON_TRAINER, GOSSIP_ITEM_GM1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

                SendGossipMenuFor(player, 907, me->GetGUID());
                return true;
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetHyjalAI<npc_jaina_proudmooreAI>(creature);
        }
};

class npc_thrall : public CreatureScript
{
    public:
        npc_thrall() : CreatureScript("npc_thrall") { }

        struct npc_thrallAI : public hyjalAI
        {
            npc_thrallAI(Creature* creature) : hyjalAI(creature)
            {
                Reset();

                Spells[0].SpellId = SPELL_CHAIN_LIGHTNING;
                Spells[0].Cooldown = urand(3000, 8000);
                Spells[0].TargetType = TARGETTYPE_VICTIM;

                Spells[1].SpellId = SPELL_SUMMON_DIRE_WOLF;
                Spells[1].Cooldown = urand(6000, 41000);
                Spells[1].TargetType = TARGETTYPE_RANDOM;
            }

            bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
            {
                uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
                ClearGossipMenuFor(player);
                DeSpawnVeins(); //despawn the alliance veins
                switch (action)
                {
                    case GOSSIP_ACTION_INFO_DEF + 1:
                        StartEvent(player);
                        break;
                    case GOSSIP_ACTION_INFO_DEF + 2:
                        FirstBossDead = true;
                        WaveCount = 9;
                        StartEvent(player);
                        break;
                    case GOSSIP_ACTION_INFO_DEF + 3:
                        Retreat();
                        break;
                    case GOSSIP_ACTION_INFO_DEF:
                        Debug = !Debug;
                        TC_LOG_DEBUG("scripts", "HyjalAI - Debug mode has been toggled");
                        break;
                }
                return true;
            }

            bool GossipHello(Player* player) override
            {
                if (EventBegun)
                    return false;

                uint32 AnetheronEvent = GetInstanceData(DATA_ANETHERONEVENT);
                // Only let them start the Horde phases if Anetheron is dead.
                if (AnetheronEvent == DONE && GetInstanceData(DATA_ALLIANCE_RETREAT))
                {
                    uint32 KazrogalEvent = GetInstanceData(DATA_KAZROGALEVENT);
                    uint32 AzgalorEvent = GetInstanceData(DATA_AZGALOREVENT);
                    if (KazrogalEvent == NOT_STARTED)
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_BEGIN_HORDE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                    else if (KazrogalEvent == DONE && AzgalorEvent == NOT_STARTED)
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_AZGALOR, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                    else if (AzgalorEvent == DONE)
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_RETREAT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                }

                if (player->IsGameMaster())
                    AddGossipItemFor(player, GOSSIP_ICON_TRAINER, GOSSIP_ITEM_GM1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

                SendGossipMenuFor(player, 907, me->GetGUID());
                return true;
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetHyjalAI<npc_thrallAI>(creature);
        }
};

class npc_tyrande_whisperwind : public CreatureScript
{
    public:
        npc_tyrande_whisperwind() : CreatureScript("npc_tyrande_whisperwind") { }

        struct npc_tyrande_whisperwindAI : public hyjalAI
        {
            npc_tyrande_whisperwindAI(Creature* creature) : hyjalAI(creature)
            {
                Reset();
            }

            bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
            {
                uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
                ClearGossipMenuFor(player);
                if (action == GOSSIP_ACTION_INFO_DEF)
                {
                    ItemPosCountVec dest;
                    uint8 msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, ITEM_TEAR_OF_GODDESS, 1);
                    if (msg == EQUIP_ERR_OK)
                        if (Item* item = player->StoreNewItem(dest, ITEM_TEAR_OF_GODDESS, true))
                            player->SendNewItem(item, 1, true, false, true);

                    SendGossipMenuFor(player, 907, me->GetGUID());
                }
                return true;
            }

            bool GossipHello(Player* player) override
            {
                uint32 AzgalorEvent = GetInstanceData(DATA_AZGALOREVENT);

                // Only let them get item if Azgalor is dead.
                if (AzgalorEvent == DONE && !player->HasItemCount(ITEM_TEAR_OF_GODDESS))
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_TYRANDE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                SendGossipMenuFor(player, 907, me->GetGUID());
                return true;
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetHyjalAI<npc_tyrande_whisperwindAI>(creature);
        }
};

void AddSC_hyjal()
{
    new npc_jaina_proudmoore();
    new npc_thrall();
    new npc_tyrande_whisperwind();
}
