/* Copyright (C) 2006,2007 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SD%Complete: 100
SDComment:
SDCategory: Caverns of Time, Mount Hyjal
EndScriptData */

/* ContentData
npc_jaina_proudmoore
npc_thrall
npc_tyrande_whisperwind
EndContentData */

#include "precompiled.h"
#include "hyjalAI.h"

#define GOSSIP_ITEM_BEGIN_ALLY  "We are ready to defend the Alliance base."
#define GOSSIP_ITEM_ANETHERON   "The defenses are holding up; we can continue."
#define GOSSIP_ITEM_RETREAT     "We can't keep this up. Let's retreat!"

#define GOSSIP_ITEM_BEGIN_HORDE "We're here to help! The Alliance are overrun."
#define GOSSIP_ITEM_AZGALOR     "We're okay so far. Let's do this!"

CreatureAI* GetAI_npc_jaina_proudmoore(Creature *_Creature)
{
    hyjalAI* ai = new hyjalAI(_Creature);

    ai->Reset();
    ai->EnterEvadeMode();

    ai->Spell[0].SpellId = SPELL_BLIZZARD;
    ai->Spell[0].Cooldown = 15000 + rand()%20000;
    ai->Spell[0].TargetType = TARGETTYPE_RANDOM;

    ai->Spell[1].SpellId = SPELL_PYROBLAST;
    ai->Spell[1].Cooldown = 2000 + rand()%7000;
    ai->Spell[1].TargetType = TARGETTYPE_RANDOM;

    ai->Spell[2].SpellId = SPELL_SUMMON_ELEMENTALS;
    ai->Spell[2].Cooldown = 15000 + rand()%30000;
    ai->Spell[2].TargetType = TARGETTYPE_SELF;

    return ai;
}

bool GossipHello_npc_jaina_proudmoore(Player *player, Creature *_Creature)
{
    hyjalAI* ai = ((hyjalAI*)_Creature->AI());
    if(ai->EventBegun)
        return false;

    uint32 RageEncounter = ai->GetInstanceData(DATA_RAGEWINTERCHILLEVENT);
    uint32 AnetheronEncounter = ai->GetInstanceData(DATA_ANETHERONEVENT);
    if(RageEncounter == NOT_STARTED)
        player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_BEGIN_ALLY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    else if(RageEncounter == DONE && AnetheronEncounter == NOT_STARTED)
        player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_ANETHERON, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    else if(RageEncounter == DONE && AnetheronEncounter == DONE)
        player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_RETREAT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);

    if(player->isGameMaster())
        player->ADD_GOSSIP_ITEM(2, "[GM] Toggle Debug Timers", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);

    player->SEND_GOSSIP_MENU(907, _Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_jaina_proudmoore(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    player->PlayerTalkClass->GetGossipMenu();
    hyjalAI* ai = ((hyjalAI*)_Creature->AI());
    switch(action)
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
        case GOSSIP_ACTION_INFO_DEF + 4:
            ai->Debug = !ai->Debug;
            outstring_log("SD2 : HyjalAI - Debug mode has been toggled");
            break;
    }

    return true;
}

CreatureAI* GetAI_npc_thrall(Creature *_Creature)
{
    hyjalAI* ai = new hyjalAI(_Creature);

    ai->Reset();
    ai->EnterEvadeMode();

    ai->Spell[0].SpellId = SPELL_CHAIN_LIGHTNING;
    ai->Spell[0].Cooldown = 2000 + rand()%5000;
    ai->Spell[0].TargetType = TARGETTYPE_VICTIM;

    ai->Spell[1].SpellId = SPELL_SUMMON_DIRE_WOLF;
    ai->Spell[1].Cooldown = 6000 + rand()%35000;
    ai->Spell[1].TargetType = TARGETTYPE_RANDOM;

    return ai;
}

bool GossipHello_npc_thrall(Player *player, Creature *_Creature)
{
    hyjalAI* ai = ((hyjalAI*)_Creature->AI());
    uint32 AnetheronEvent = ai->GetInstanceData(DATA_ANETHERONEVENT);
    if(AnetheronEvent >= DONE && !ai->EventBegun)           // Only let them start the Horde phase if Anetheron is dead.
    {
        uint32 KazrogalEvent = ai->GetInstanceData(DATA_KAZROGALEVENT);
        uint32 AzgalorEvent  = ai->GetInstanceData(DATA_AZGALOREVENT);
        if(KazrogalEvent == NOT_STARTED)
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_BEGIN_HORDE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        else if(KazrogalEvent == DONE && AzgalorEvent == NOT_STARTED)
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_AZGALOR, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
        else if(AzgalorEvent == DONE)
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_RETREAT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    }

    if(player->isGameMaster())
        player->ADD_GOSSIP_ITEM(2, "[GM] Toggle Debug Timers", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);

    player->SEND_GOSSIP_MENU(907, _Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_thrall(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    player->PlayerTalkClass->GetGossipMenu();
    hyjalAI* ai = ((hyjalAI*)_Creature->AI());
    switch(action)
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
        case GOSSIP_ACTION_INFO_DEF + 4:
            ai->Debug = !ai->Debug;
            outstring_log("SD2 : HyjalAI - Debug mode has been toggled");
            break;
    }

    return true;
}

bool GossipHello_npc_tyrande_whisperwind(Player* player, Creature* _Creature)
{
    player->ADD_GOSSIP_ITEM(1, "Aid us in defending Nordrassil", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);
    player->SEND_GOSSIP_MENU(907, _Creature->GetGUID());
    return true;
}

bool GossipSelect_npc_tyrande_whisperwind(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    if(action == GOSSIP_ACTION_TRADE)
        player->SEND_VENDORLIST( _Creature->GetGUID() );

    return true;
}

void AddSC_hyjal()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_jaina_proudmoore";
    newscript->GetAI = GetAI_npc_jaina_proudmoore;
    newscript->pGossipHello = &GossipHello_npc_jaina_proudmoore;
    newscript->pGossipSelect = &GossipSelect_npc_jaina_proudmoore;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name = "npc_thrall";
    newscript->GetAI = GetAI_npc_thrall;
    newscript->pGossipHello = &GossipHello_npc_thrall;
    newscript->pGossipSelect = &GossipSelect_npc_thrall;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name = "npc_tyrande_whisperwind";
    newscript->pGossipHello = &GossipHello_npc_tyrande_whisperwind;
    newscript->pGossipSelect = &GossipSelect_npc_tyrande_whisperwind;
    m_scripts[nrscripts++] = newscript;
}
