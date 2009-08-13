 /* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
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

#include "precompiled.h"
#include "hyjalAI.h"

#define GOSSIP_ITEM_BEGIN_ALLY      "My companions and I are with you, Lady Proudmoore."
#define GOSSIP_ITEM_ANETHERON       "We are ready for whatever Archimonde might send our way, Lady Proudmoore."

#define GOSSIP_ITEM_BEGIN_HORDE     "I am with you, Thrall."
#define GOSSIP_ITEM_AZGALOR         "We have nothing to fear."

#define GOSSIP_ITEM_RETREAT         "We can't keep this up. Let's retreat!"

#define GOSSIP_ITEM_TYRANDE         "Aid us in defending Nordrassil"
#define ITEM_TEAR_OF_GODDESS        24494


CreatureAI* GetAI_npc_jaina_proudmoore(Creature* pCreature)
{
    hyjalAI* ai = new hyjalAI(pCreature);

    ai->Reset();
    ai->EnterEvadeMode();

    ai->Spell[0].SpellId = SPELL_BLIZZARD;
    ai->Spell[0].Cooldown = 15000 + rand()%20000;
    ai->Spell[0].TargetType = TARGETTYPE_RANDOM;

    ai->Spell[1].SpellId = SPELL_PYROBLAST;
    ai->Spell[1].Cooldown = 5500 + rand()%4000;
    ai->Spell[1].TargetType = TARGETTYPE_RANDOM;

    ai->Spell[2].SpellId = SPELL_SUMMON_ELEMENTALS;
    ai->Spell[2].Cooldown = 15000 + rand()%30000;
    ai->Spell[2].TargetType = TARGETTYPE_SELF;

    return ai;
}

bool GossipHello_npc_jaina_proudmoore(Player* pPlayer, Creature* pCreature)
{
    hyjalAI* ai = CAST_AI(hyjalAI, pCreature->AI());
    if (ai->EventBegun)
        return false;

    uint32 RageEncounter = ai->GetInstanceData(DATA_RAGEWINTERCHILLEVENT);
    uint32 AnetheronEncounter = ai->GetInstanceData(DATA_ANETHERONEVENT);
    if (RageEncounter == NOT_STARTED)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_BEGIN_ALLY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    else if (RageEncounter == DONE && AnetheronEncounter == NOT_STARTED)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_ANETHERON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    else if (RageEncounter == DONE && AnetheronEncounter == DONE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_RETREAT, GOSSIP_SENDER_MAIN,    GOSSIP_ACTION_INFO_DEF + 3);

    if (pPlayer->isGameMaster())
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "[GM] Toggle Debug Timers", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

    pPlayer->SEND_GOSSIP_MENU(907, pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_jaina_proudmoore(Player* pPlayer, Creature* pCreature, uint32 sender, uint32 action)
{
    hyjalAI* ai = CAST_AI(hyjalAI, pCreature->AI());
    switch(action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:
            ai->StartEvent(pPlayer);
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:
            ai->FirstBossDead = true;
            ai->WaveCount = 9;
            ai->StartEvent(pPlayer);
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:
            ai->Retreat();
            break;
         case GOSSIP_ACTION_INFO_DEF:
            ai->Debug = !ai->Debug;
            debug_log("TSCR: HyjalAI - Debug mode has been toggled");
            break;
    }
    return true;
}

CreatureAI* GetAI_npc_thrall(Creature* pCreature)
{
    hyjalAI* ai = new hyjalAI(pCreature);

    ai->Reset();
    ai->EnterEvadeMode();

    ai->Spell[0].SpellId = SPELL_CHAIN_LIGHTNING;
    ai->Spell[0].Cooldown = 3000 + rand()%5000;
    ai->Spell[0].TargetType = TARGETTYPE_VICTIM;

    ai->Spell[1].SpellId = SPELL_SUMMON_DIRE_WOLF;
    ai->Spell[1].Cooldown = 6000 + rand()%35000;
    ai->Spell[1].TargetType = TARGETTYPE_RANDOM;

    return ai;
}

bool GossipHello_npc_thrall(Player* pPlayer, Creature* pCreature)
{
    hyjalAI* ai = CAST_AI(hyjalAI, pCreature->AI());
    if (ai->EventBegun)
        return false;

    uint32 AnetheronEvent = ai->GetInstanceData(DATA_ANETHERONEVENT);
    // Only let them start the Horde phases if Anetheron is dead.
    if (AnetheronEvent == DONE && ai->GetInstanceData(DATA_ALLIANCE_RETREAT))
    {
        uint32 KazrogalEvent = ai->GetInstanceData(DATA_KAZROGALEVENT);
        uint32 AzgalorEvent  = ai->GetInstanceData(DATA_AZGALOREVENT);
        if (KazrogalEvent == NOT_STARTED)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_BEGIN_HORDE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        else if (KazrogalEvent == DONE && AzgalorEvent == NOT_STARTED)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_AZGALOR, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
        else if (AzgalorEvent == DONE)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_RETREAT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    }

    if (pPlayer->isGameMaster())
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "[GM] Toggle Debug Timers", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

    pPlayer->SEND_GOSSIP_MENU(907, pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_thrall(Player* pPlayer, Creature* pCreature, uint32 sender, uint32 action)
{
    hyjalAI* ai = CAST_AI(hyjalAI, pCreature->AI());
    ai->DeSpawnVeins();//despawn the alliance veins
    switch(action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:
            ai->StartEvent(pPlayer);
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:
            ai->FirstBossDead = true;
            ai->WaveCount = 9;
            ai->StartEvent(pPlayer);
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:
            ai->Retreat();
            break;
        case GOSSIP_ACTION_INFO_DEF:
            ai->Debug = !ai->Debug;
            debug_log("TSCR: HyjalAI - Debug mode has been toggled");
            break;
    }
    return true;
}

CreatureAI* GetAI_npc_tyrande_whisperwind(Creature* pCreature)
{
    hyjalAI* ai = new hyjalAI(pCreature);
    ai->Reset();
    ai->EnterEvadeMode();
    return ai;
}

bool GossipHello_npc_tyrande_whisperwind(Player* pPlayer, Creature* pCreature)
{
    hyjalAI* ai = CAST_AI(hyjalAI, pCreature->AI());
    uint32 AzgalorEvent = ai->GetInstanceData(DATA_AZGALOREVENT);

    // Only let them get item if Azgalor is dead.
    if (AzgalorEvent == DONE && !pPlayer->HasItemCount(ITEM_TEAR_OF_GODDESS,1))
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_TYRANDE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
    pPlayer->SEND_GOSSIP_MENU(907, pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_tyrande_whisperwind(Player* pPlayer, Creature* pCreature, uint32 sender, uint32 action)
{
    if (action == GOSSIP_ACTION_INFO_DEF)
    {
            ItemPosCountVec dest;
            uint8 msg = pPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, ITEM_TEAR_OF_GODDESS, 1);
            if (msg == EQUIP_ERR_OK)
            {
                 Item* item = pPlayer->StoreNewItem(dest, ITEM_TEAR_OF_GODDESS, true);
                 if (item && pPlayer)
                     pPlayer->SendNewItem(item,1,true,false,true);
            }
            pPlayer->SEND_GOSSIP_MENU(907, pCreature->GetGUID());
            hyjalAI* ai = CAST_AI(hyjalAI, pCreature->AI());
    }
    return true;
}

void AddSC_hyjal()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_jaina_proudmoore";
    newscript->GetAI = &GetAI_npc_jaina_proudmoore;
    newscript->pGossipHello = &GossipHello_npc_jaina_proudmoore;
    newscript->pGossipSelect = &GossipSelect_npc_jaina_proudmoore;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_thrall";
    newscript->GetAI = &GetAI_npc_thrall;
    newscript->pGossipHello = &GossipHello_npc_thrall;
    newscript->pGossipSelect = &GossipSelect_npc_thrall;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_tyrande_whisperwind";
    newscript->pGossipHello = &GossipHello_npc_tyrande_whisperwind;
    newscript->pGossipSelect = &GossipSelect_npc_tyrande_whisperwind;
    newscript->GetAI = &GetAI_npc_tyrande_whisperwind;
    newscript->RegisterSelf();
}

