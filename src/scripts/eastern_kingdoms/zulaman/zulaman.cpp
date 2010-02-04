/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/* ScriptData
SDName: Zulaman
SD%Complete: 90
SDComment: Forest Frog will turn into different NPC's. Workaround to prevent new entry from running this script
SDCategory: Zul'Aman
EndScriptData */

/* ContentData
npc_forest_frog
EndContentData */

#include "ScriptedPch.h"
#include "zulaman.h"

/*######
## npc_forest_frog
######*/

#define SPELL_REMOVE_AMANI_CURSE    43732
#define SPELL_PUSH_MOJO             43923
#define ENTRY_FOREST_FROG           24396

struct npc_forest_frogAI : public ScriptedAI
{
    npc_forest_frogAI(Creature* c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance *pInstance;

    void Reset() {}

    void EnterCombat(Unit *who) {}

    void DoSpawnRandom()
    {
        if (pInstance)
        {
            uint32 cEntry = 0;
            switch(rand()%11)
            {
                case 0: cEntry = 24024; break;          //Kraz
                case 1: cEntry = 24397; break;          //Mannuth
                case 2: cEntry = 24403; break;          //Deez
                case 3: cEntry = 24404; break;          //Galathryn
                case 4: cEntry = 24405; break;          //Adarrah
                case 5: cEntry = 24406; break;          //Fudgerick
                case 6: cEntry = 24407; break;          //Darwen
                case 7: cEntry = 24445; break;          //Mitzi
                case 8: cEntry = 24448; break;          //Christian
                case 9: cEntry = 24453; break;          //Brennan
                case 10: cEntry = 24455; break;         //Hollee
            }

            if (!pInstance->GetData(TYPE_RAND_VENDOR_1))
                if (rand()%10 == 1) cEntry = 24408;      //Gunter
            if (!pInstance->GetData(TYPE_RAND_VENDOR_2))
                if (rand()%10 == 1) cEntry = 24409;      //Kyren

            if (cEntry) m_creature->UpdateEntry(cEntry);

            if (cEntry == 24408) pInstance->SetData(TYPE_RAND_VENDOR_1,DONE);
            if (cEntry == 24409) pInstance->SetData(TYPE_RAND_VENDOR_2,DONE);
        }
    }

    void SpellHit(Unit *caster, const SpellEntry *spell)
    {
        if (spell->Id == SPELL_REMOVE_AMANI_CURSE && caster->GetTypeId() == TYPEID_PLAYER && m_creature->GetEntry() == ENTRY_FOREST_FROG)
        {
            //increase or decrease chance of mojo?
            if (rand()%99 == 50) DoCast(caster, SPELL_PUSH_MOJO, true);
            else DoSpawnRandom();
        }
    }
};
CreatureAI* GetAI_npc_forest_frog(Creature* pCreature)
{
    return new npc_forest_frogAI (pCreature);
}

/*######
## npc_zulaman_hostage
######*/

#define GOSSIP_HOSTAGE1        "I am glad to help you."

static uint32 HostageEntry[] = {23790, 23999, 24024, 24001};
static uint32 ChestEntry[] = {186648, 187021, 186672, 186667};

struct npc_zulaman_hostageAI : public ScriptedAI
{
    npc_zulaman_hostageAI(Creature *c) : ScriptedAI(c) {IsLoot = false;}
    bool IsLoot;
    uint64 PlayerGUID;
    void Reset() {}
    void EnterCombat(Unit *who) {}
    void JustDied(Unit* who)
    {
        Player* pPlayer = Unit::GetPlayer(PlayerGUID);
        if (pPlayer) pPlayer->SendLoot(m_creature->GetGUID(), LOOT_CORPSE);
    }
    void UpdateAI(const uint32 diff)
    {
        if (IsLoot)
            DoCast(m_creature, 7, false);
    }
};

bool GossipHello_npc_zulaman_hostage(Player* pPlayer, Creature* pCreature)
{
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HOSTAGE1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_zulaman_hostage(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF + 1)
        pPlayer->CLOSE_GOSSIP_MENU();

    if (!pCreature->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP))
        return true;
    pCreature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

    ScriptedInstance* pInstance = pCreature->GetInstanceData();
    if (pInstance)
    {
        //uint8 progress = pInstance->GetData(DATA_CHESTLOOTED);
        pInstance->SetData(DATA_CHESTLOOTED, 0);
        float x, y, z;
        pCreature->GetPosition(x, y, z);
        uint32 entry = pCreature->GetEntry();
        for (uint8 i = 0; i < 4; ++i)
        {
            if (HostageEntry[i] == entry)
            {
                pCreature->SummonGameObject(ChestEntry[i], x-2, y, z, 0, 0, 0, 0, 0, 0);
                break;
            }
        }
        /*Creature* summon = pCreature->SummonCreature(HostageInfo[progress], x-2, y, z, 0, TEMPSUMMON_DEAD_DESPAWN, 0);
        if (summon)
        {
            CAST_AI(npc_zulaman_hostageAI, summon->AI())->PlayerGUID = pPlayer->GetGUID();
            CAST_AI(npc_zulaman_hostageAI, summon->AI())->IsLoot = true;
            summon->SetDisplayId(10056);
            summon->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            summon->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        }*/
    }
    return true;
}

CreatureAI* GetAI_npc_zulaman_hostage(Creature* pCreature)
{
    return new npc_zulaman_hostageAI(pCreature);
}

void AddSC_zulaman()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_forest_frog";
    newscript->GetAI = &GetAI_npc_forest_frog;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_zulaman_hostage";
    newscript->GetAI = &GetAI_npc_zulaman_hostage;
    newscript->pGossipHello = &GossipHello_npc_zulaman_hostage;
    newscript->pGossipSelect = &GossipSelect_npc_zulaman_hostage;
    newscript->RegisterSelf();
}

