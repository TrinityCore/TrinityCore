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
SDName: Zangarmarsh
SD%Complete: 100
SDComment: Quest support: 9752, 9785, 9803, 10009. Mark Of ... buffs.
SDCategory: Zangarmarsh
EndScriptData */

/* ContentData
npcs_ashyen_and_keleth
npc_cooshcoosh
npc_elder_kuruti
npc_mortog_steamhead
npc_kayra_longmane
npc_timothy_daniels
EndContentData */

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"

/*######
## npcs_ashyen_and_keleth
######*/

#define GOSSIP_ITEM_BLESS_ASH     "Grant me your mark, wise ancient."
#define GOSSIP_ITEM_BLESS_KEL     "Grant me your mark, mighty ancient."
//signed for 17900 but used by 17900,17901
#define GOSSIP_REWARD_BLESS       -1000359
//#define TEXT_BLESSINGS        "<You need higher standing with Cenarion Expedition to recive a blessing.>"

bool GossipHello_npcs_ashyen_and_keleth(Player* pPlayer, Creature* pCreature)
{
    if (pPlayer->GetReputationRank(942) > REP_NEUTRAL)
    {
        if (pCreature->GetEntry() == 17900)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_BLESS_ASH, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        if (pCreature->GetEntry() == 17901)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_BLESS_KEL, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
    }
    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

    return true;
}

bool GossipSelect_npcs_ashyen_and_keleth(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
    {
        pCreature->setPowerType(POWER_MANA);
        pCreature->SetMaxPower(POWER_MANA,200);             //set a "fake" mana value, we can't depend on database doing it in this case
        pCreature->SetPower(POWER_MANA,200);

        if (pCreature->GetEntry() == 17900)                //check which Creature we are dealing with
        {
            switch (pPlayer->GetReputationRank(942))
            {                                               //mark of lore
                case REP_FRIENDLY:
                    pCreature->CastSpell(pPlayer, 31808, true);
                    DoScriptText(GOSSIP_REWARD_BLESS, pCreature);
                    break;
                case REP_HONORED:
                    pCreature->CastSpell(pPlayer, 31810, true);
                    DoScriptText(GOSSIP_REWARD_BLESS, pCreature);
                    break;
                case REP_REVERED:
                    pCreature->CastSpell(pPlayer, 31811, true);
                    DoScriptText(GOSSIP_REWARD_BLESS, pCreature);
                    break;
                case REP_EXALTED:
                    pCreature->CastSpell(pPlayer, 31815, true);
                    DoScriptText(GOSSIP_REWARD_BLESS, pCreature);
                    break;
            }
        }

        if (pCreature->GetEntry() == 17901)
        {
            switch (pPlayer->GetReputationRank(942))         //mark of war
            {
                case REP_FRIENDLY:
                    pCreature->CastSpell(pPlayer, 31807, true);
                    DoScriptText(GOSSIP_REWARD_BLESS, pCreature);
                    break;
                case REP_HONORED:
                    pCreature->CastSpell(pPlayer, 31812, true);
                    DoScriptText(GOSSIP_REWARD_BLESS, pCreature);
                    break;
                case REP_REVERED:
                    pCreature->CastSpell(pPlayer, 31813, true);
                    DoScriptText(GOSSIP_REWARD_BLESS, pCreature);
                    break;
                case REP_EXALTED:
                    pCreature->CastSpell(pPlayer, 31814, true);
                    DoScriptText(GOSSIP_REWARD_BLESS, pCreature);
                    break;
            }
        }
        pPlayer->CLOSE_GOSSIP_MENU();
        pPlayer->TalkedToCreature(pCreature->GetEntry(), pCreature->GetGUID());
    }
    return true;
}

/*######
## npc_cooshcoosh
######*/

#define GOSSIP_COOSH            "You owe Sim'salabim money. Hand them over or die!"

enum eCooshhooosh
{
    SPELL_LIGHTNING_BOLT    = 9532,
    QUEST_CRACK_SKULLS      = 10009,
    FACTION_HOSTILE_CO      = 45
};

struct npc_cooshcooshAI : public ScriptedAI
{
    npc_cooshcooshAI(Creature* c) : ScriptedAI(c)
    {
        m_uiNormFaction = c->getFaction();
    }

    uint32 m_uiNormFaction;
    uint32 LightningBolt_Timer;

    void Reset()
    {
        LightningBolt_Timer = 2000;
        if (me->getFaction() != m_uiNormFaction)
            me->setFaction(m_uiNormFaction);
    }

    void EnterCombat(Unit * /*who*/) {}

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (LightningBolt_Timer <= diff)
        {
            DoCast(me->getVictim(), SPELL_LIGHTNING_BOLT);
            LightningBolt_Timer = 5000;
        } else LightningBolt_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_cooshcoosh(Creature* pCreature)
{
    return new npc_cooshcooshAI (pCreature);
}

bool GossipHello_npc_cooshcoosh(Player* pPlayer, Creature* pCreature)
{
    if (pPlayer->GetQuestStatus(QUEST_CRACK_SKULLS) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_COOSH, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

    pPlayer->SEND_GOSSIP_MENU(9441, pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_cooshcoosh(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        pCreature->setFaction(FACTION_HOSTILE_CO);
        pCreature->AI()->AttackStart(pPlayer);
    }
    return true;
}

/*######
## npc_elder_kuruti
######*/

#define GOSSIP_ITEM_KUR1 "Greetings, elder. It is time for your people to end their hostility towards the draenei and their allies."
#define GOSSIP_ITEM_KUR2 "I did not mean to deceive you, elder. The draenei of Telredor thought to approach you in a way that would seem familiar to you."
#define GOSSIP_ITEM_KUR3 "I will tell them. Farewell, elder."

bool GossipHello_npc_elder_kuruti(Player* pPlayer, Creature* pCreature)
{
    if (pPlayer->GetQuestStatus(9803) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_KUR1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

    pPlayer->SEND_GOSSIP_MENU(9226, pCreature->GetGUID());

    return true;
}

bool GossipSelect_npc_elder_kuruti(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    switch (uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_KUR2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->SEND_GOSSIP_MENU(9227, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 1:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_KUR3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->SEND_GOSSIP_MENU(9229, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:
        {
            if (!pPlayer->HasItemCount(24573,1))
            {
                ItemPosCountVec dest;
                uint8 msg = pPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, 24573, 1, false);
                if (msg == EQUIP_ERR_OK)
                {
                    pPlayer->StoreNewItem(dest, 24573, true);
                }
                else
                    pPlayer->SendEquipError(msg,NULL,NULL);
            }
            pPlayer->SEND_GOSSIP_MENU(9231, pCreature->GetGUID());
            break;
        }
    }
    return true;
}

/*######
## npc_mortog_steamhead
######*/

bool GossipHello_npc_mortog_steamhead(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isVendor() && pPlayer->GetReputationRank(942) == REP_EXALTED)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

    return true;
}

bool GossipSelect_npc_mortog_steamhead(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_TRADE)
    {
        pPlayer->SEND_VENDORLIST(pCreature->GetGUID());
    }
    return true;
}

/*######
## npc_kayra_longmane
######*/

enum eKayra
{
    SAY_START           = -1000343,
    SAY_AMBUSH1         = -1000344,
    SAY_PROGRESS        = -1000345,
    SAY_AMBUSH2         = -1000346,
    SAY_NEAR_END        = -1000347,
    SAY_END             = -1000348, //this is signed for 10646

    QUEST_ESCAPE_FROM   = 9752,
    NPC_SLAVEBINDER     = 18042
};

struct npc_kayra_longmaneAI : public npc_escortAI
{
    npc_kayra_longmaneAI(Creature* c) : npc_escortAI(c) {}

    void Reset() { }

    void WaypointReached(uint32 i)
    {
        Player* pPlayer = GetPlayerForEscort();

        if (!pPlayer)
            return;

        switch(i)
        {
            case 4:
                DoScriptText(SAY_AMBUSH1, me, pPlayer);
                DoSpawnCreature(NPC_SLAVEBINDER, -10.0f, -5.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                DoSpawnCreature(NPC_SLAVEBINDER, -8.0f, 5.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                break;
            case 5:
                DoScriptText(SAY_PROGRESS, me, pPlayer);
                SetRun();
                break;
            case 16:
                DoScriptText(SAY_AMBUSH2, me, pPlayer);
                DoSpawnCreature(NPC_SLAVEBINDER, -10.0f, -5.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                DoSpawnCreature(NPC_SLAVEBINDER, -8.0f, 5.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                break;
            case 17:
                SetRun(false);
                DoScriptText(SAY_NEAR_END, me, pPlayer);
                break;
            case 25:
                DoScriptText(SAY_END, me, pPlayer);
                pPlayer->GroupEventHappens(QUEST_ESCAPE_FROM, me);
                break;
        }
    }
};

bool QuestAccept_npc_kayra_longmane(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_ESCAPE_FROM)
    {
        DoScriptText(SAY_START, pCreature, pPlayer);

        if (npc_escortAI* pEscortAI = CAST_AI(npc_kayra_longmaneAI, pCreature->AI()))
            pEscortAI->Start(false, false, pPlayer->GetGUID());
    }
    return true;
}

CreatureAI* GetAI_npc_kayra_longmaneAI(Creature* pCreature)
{
    return new npc_kayra_longmaneAI(pCreature);
}

/*######
## npc_timothy_daniels
######*/

#define GOSSIP_TIMOTHY_DANIELS_ITEM1    "Specialist, eh? Just what kind of specialist are you, anyway?"
#define GOSSIP_TEXT_BROWSE_POISONS      "Let me browse your reagents and poison supplies."

enum eTimothy
{
    GOSSIP_TEXTID_TIMOTHY_DANIELS1      = 9239
};

bool GossipHello_npc_timothy_daniels(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pCreature->isVendor())
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_POISONS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TIMOTHY_DANIELS_ITEM1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_timothy_daniels(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_TIMOTHY_DANIELS1, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_TRADE:
            pPlayer->SEND_VENDORLIST(pCreature->GetGUID());
            break;
    }

    return true;
}

/*######
## AddSC
######*/

void AddSC_zangarmarsh()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npcs_ashyen_and_keleth";
    newscript->pGossipHello =  &GossipHello_npcs_ashyen_and_keleth;
    newscript->pGossipSelect = &GossipSelect_npcs_ashyen_and_keleth;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_cooshcoosh";
    newscript->GetAI = &GetAI_npc_cooshcoosh;
    newscript->pGossipHello =  &GossipHello_npc_cooshcoosh;
    newscript->pGossipSelect = &GossipSelect_npc_cooshcoosh;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_elder_kuruti";
    newscript->pGossipHello =  &GossipHello_npc_elder_kuruti;
    newscript->pGossipSelect = &GossipSelect_npc_elder_kuruti;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_mortog_steamhead";
    newscript->pGossipHello =  &GossipHello_npc_mortog_steamhead;
    newscript->pGossipSelect = &GossipSelect_npc_mortog_steamhead;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_kayra_longmane";
    newscript->GetAI = &GetAI_npc_kayra_longmaneAI;
    newscript->pQuestAccept = &QuestAccept_npc_kayra_longmane;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_timothy_daniels";
    newscript->pGossipHello =  &GossipHello_npc_timothy_daniels;
    newscript->pGossipSelect = &GossipSelect_npc_timothy_daniels;
    newscript->RegisterSelf();
}

