 /*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#include "ScriptPCH.h"
#include "hyjalAI.h"

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

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        hyjalAI* ai = CAST_AI(hyjalAI, creature->AI());
        switch (uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF + 1:
                ai->StartEvent(player);
                break;
            case GOSSIP_ACTION_INFO_DEF + 2:
                ai->FirstBossDead = true;
                ai->WaveCount = 9;
                ai->StartEvent(player);
                break;
            case GOSSIP_ACTION_INFO_DEF + 3:
                ai->Retreat();
                break;
             case GOSSIP_ACTION_INFO_DEF:
                ai->Debug = !ai->Debug;
                sLog->outDebug(LOG_FILTER_TSCR, "TSCR: HyjalAI - Debug mode has been toggled");
                break;
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        hyjalAI* ai = CAST_AI(hyjalAI, creature->AI());
        if (ai->EventBegun)
            return false;

        uint32 RageEncounter = ai->GetInstanceData(DATA_RAGEWINTERCHILLEVENT);
        uint32 AnetheronEncounter = ai->GetInstanceData(DATA_ANETHERONEVENT);
        if (RageEncounter == NOT_STARTED)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_BEGIN_ALLY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        else if (RageEncounter == DONE && AnetheronEncounter == NOT_STARTED)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_ANETHERON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
        else if (RageEncounter == DONE && AnetheronEncounter == DONE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_RETREAT, GOSSIP_SENDER_MAIN,    GOSSIP_ACTION_INFO_DEF + 3);

        if (player->isGameMaster())
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_ITEM_GM1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

        player->SEND_GOSSIP_MENU(907, creature->GetGUID());
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        hyjalAI* ai = new hyjalAI(creature);

        ai->Reset();
        ai->EnterEvadeMode();

        ai->Spells[0].SpellId = SPELL_BLIZZARD;
        ai->Spells[0].Cooldown = 15000 + rand()%20000;
        ai->Spells[0].TargetType = TARGETTYPE_RANDOM;

        ai->Spells[1].SpellId = SPELL_PYROBLAST;
        ai->Spells[1].Cooldown = 5500 + rand()%4000;
        ai->Spells[1].TargetType = TARGETTYPE_RANDOM;

        ai->Spells[2].SpellId = SPELL_SUMMON_ELEMENTALS;
        ai->Spells[2].Cooldown = 15000 + rand()%30000;
        ai->Spells[2].TargetType = TARGETTYPE_SELF;

        return ai;
    }

};

class npc_thrall : public CreatureScript
{
public:
    npc_thrall() : CreatureScript("npc_thrall") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        hyjalAI* ai = CAST_AI(hyjalAI, creature->AI());
        ai->DeSpawnVeins();//despawn the alliance veins
        switch (uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF + 1:
                ai->StartEvent(player);
                break;
            case GOSSIP_ACTION_INFO_DEF + 2:
                ai->FirstBossDead = true;
                ai->WaveCount = 9;
                ai->StartEvent(player);
                break;
            case GOSSIP_ACTION_INFO_DEF + 3:
                ai->Retreat();
                break;
            case GOSSIP_ACTION_INFO_DEF:
                ai->Debug = !ai->Debug;
                sLog->outDebug(LOG_FILTER_TSCR, "TSCR: HyjalAI - Debug mode has been toggled");
                break;
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        hyjalAI* ai = CAST_AI(hyjalAI, creature->AI());
        if (ai->EventBegun)
            return false;

        uint32 AnetheronEvent = ai->GetInstanceData(DATA_ANETHERONEVENT);
        // Only let them start the Horde phases if Anetheron is dead.
        if (AnetheronEvent == DONE && ai->GetInstanceData(DATA_ALLIANCE_RETREAT))
        {
            uint32 KazrogalEvent = ai->GetInstanceData(DATA_KAZROGALEVENT);
            uint32 AzgalorEvent  = ai->GetInstanceData(DATA_AZGALOREVENT);
            if (KazrogalEvent == NOT_STARTED)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_BEGIN_HORDE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            else if (KazrogalEvent == DONE && AzgalorEvent == NOT_STARTED)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_AZGALOR, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            else if (AzgalorEvent == DONE)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_RETREAT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
        }

        if (player->isGameMaster())
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_ITEM_GM1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

        player->SEND_GOSSIP_MENU(907, creature->GetGUID());
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        hyjalAI* ai = new hyjalAI(creature);

        ai->Reset();
        ai->EnterEvadeMode();

        ai->Spells[0].SpellId = SPELL_CHAIN_LIGHTNING;
        ai->Spells[0].Cooldown = 3000 + rand()%5000;
        ai->Spells[0].TargetType = TARGETTYPE_VICTIM;

        ai->Spells[1].SpellId = SPELL_SUMMON_DIRE_WOLF;
        ai->Spells[1].Cooldown = 6000 + rand()%35000;
        ai->Spells[1].TargetType = TARGETTYPE_RANDOM;

        return ai;
    }

};

class npc_tyrande_whisperwind : public CreatureScript
{
public:
    npc_tyrande_whisperwind() : CreatureScript("npc_tyrande_whisperwind") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        hyjalAI* ai = new hyjalAI(creature);
        ai->Reset();
        ai->EnterEvadeMode();
        return ai;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF)
        {
                ItemPosCountVec dest;
                uint8 msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, ITEM_TEAR_OF_GODDESS, 1);
                if (msg == EQUIP_ERR_OK)
                {
                     Item* item = player->StoreNewItem(dest, ITEM_TEAR_OF_GODDESS, true);
                     if (item && player)
                         player->SendNewItem(item, 1, true, false, true);
                }
                player->SEND_GOSSIP_MENU(907, creature->GetGUID());
                CAST_AI(hyjalAI, creature->AI());
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        hyjalAI* ai = CAST_AI(hyjalAI, creature->AI());
        uint32 AzgalorEvent = ai->GetInstanceData(DATA_AZGALOREVENT);

        // Only let them get item if Azgalor is dead.
        if (AzgalorEvent == DONE && !player->HasItemCount(ITEM_TEAR_OF_GODDESS, 1))
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_TYRANDE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
        player->SEND_GOSSIP_MENU(907, creature->GetGUID());
        return true;
    }

};

void AddSC_hyjal()
{
    new npc_jaina_proudmoore();
    new npc_thrall();
    new npc_tyrande_whisperwind();
}
