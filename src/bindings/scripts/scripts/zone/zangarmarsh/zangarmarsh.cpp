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
EndContentData */

#include "precompiled.h"
#include "../../npc/npc_escortAI.h"

/*######
## npcs_ashyen_and_keleth
######*/

#define GOSSIP_ITEM_BLESS_ASH     "Grant me your mark, wise ancient."
#define GOSSIP_ITEM_BLESS_KEL     "Grant me your mark, mighty ancient."
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
    pPlayer->SEND_GOSSIP_MENU(pCreature->GetNpcTextId(), pCreature->GetGUID());

    return true;
}

bool GossipSelect_npcs_ashyen_and_keleth(Player* pPlayer, Creature* pCreature, uint32 sender, uint32 action)
{
    if (action == GOSSIP_ACTION_INFO_DEF+1)
    {
        pCreature->setPowerType(POWER_MANA);
        pCreature->SetMaxPower(POWER_MANA,200);             //set a "fake" mana value, we can't depend on database doing it in this case
        pCreature->SetPower(POWER_MANA,200);

        if (pCreature->GetEntry() == 17900)                //check which creature we are dealing with
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

enum
{
    SPELL_LIGHTNING_BOLT    = 9532,
    QUEST_CRACK_SKULLS      = 10009,
    FACTION_HOSTILE_CO      = 45
};

struct TRINITY_DLL_DECL npc_cooshcooshAI : public ScriptedAI
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
        if (m_creature->getFaction() != m_uiNormFaction)
            m_creature->setFaction(m_uiNormFaction);
    }

    void EnterCombat(Unit *who) {}

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (LightningBolt_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_LIGHTNING_BOLT);
            LightningBolt_Timer = 5000;
        }else LightningBolt_Timer -= diff;

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

bool GossipSelect_npc_cooshcoosh(Player* pPlayer, Creature* pCreature, uint32 sender, uint32 action)
{
    if (action == GOSSIP_ACTION_INFO_DEF)
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

#define GOSSIP_ITEM_KUR1 "Offer treat"
#define GOSSIP_ITEM_KUR2 "Im a messenger for Draenei"
#define GOSSIP_ITEM_KUR3 "Get message"

bool GossipHello_npc_elder_kuruti(Player* pPlayer, Creature* pCreature)
{
    if (pPlayer->GetQuestStatus(9803) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_KUR1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

    pPlayer->SEND_GOSSIP_MENU(9226, pCreature->GetGUID());

    return true;
}

bool GossipSelect_npc_elder_kuruti(Player* pPlayer, Creature* pCreature, uint32 sender, uint32 action)
{
    switch (action)
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

    pPlayer->SEND_GOSSIP_MENU(pCreature->GetNpcTextId(), pCreature->GetGUID());

    return true;
}

bool GossipSelect_npc_mortog_steamhead(Player* pPlayer, Creature* pCreature, uint32 sender, uint32 action)
{
    if (action == GOSSIP_ACTION_TRADE)
    {
        pPlayer->SEND_VENDORLIST(pCreature->GetGUID());
    }
    return true;
}

/*######
## npc_kayra_longmane
######*/

enum
{
    SAY_START           = -1000360,
    SAY_AMBUSH1         = -1000361,
    SAY_PROGRESS        = -1000362,
    SAY_AMBUSH2         = -1000363,
    SAY_NEAR_END        = -1000364,
    SAY_END             = -1000365,

    QUEST_ESCAPE_FROM   = 9752,
    NPC_SLAVEBINDER     = 18042
};

struct TRINITY_DLL_DECL npc_kayra_longmaneAI : public npc_escortAI
{
    npc_kayra_longmaneAI(Creature* c) : npc_escortAI(c) {}

    void Reset() { }

    void EnterCombat(Unit* who){}

    void WaypointReached(uint32 i)
    {
        Player* pUnit = Unit::GetPlayer(PlayerGUID);

        if (!pUnit)
            return;

        switch(i)
        {
            case 4:
                DoScriptText(SAY_AMBUSH1, m_creature, pUnit);
                DoSpawnCreature(NPC_SLAVEBINDER, -10.0f, -5.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                DoSpawnCreature(NPC_SLAVEBINDER, -8.0f, 5.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                break;
            case 5:
                DoScriptText(SAY_PROGRESS, m_creature, pUnit);
                SetRun();
                break;
            case 16:
                DoScriptText(SAY_AMBUSH2, m_creature, pUnit);
                DoSpawnCreature(NPC_SLAVEBINDER, -10.0f, -5.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                DoSpawnCreature(NPC_SLAVEBINDER, -8.0f, 5.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                break;
            case 17:
                SetRun(false);
                DoScriptText(SAY_NEAR_END, m_creature, pUnit);
                break;
            case 26:
                DoScriptText(SAY_END, m_creature, pUnit);
                pUnit->GroupEventHappens(QUEST_ESCAPE_FROM, m_creature);
                break;
        }
    }

    void JustDied(Unit* killer)
    {
        if (Player* pUnit = Unit::GetPlayer(PlayerGUID))
        {
            if (pUnit->GetQuestStatus(QUEST_ESCAPE_FROM) == QUEST_STATUS_INCOMPLETE)
                pUnit->FailQuest(QUEST_ESCAPE_FROM);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        npc_escortAI::UpdateAI(diff);
    }
};

bool QuestAccept_npc_kayra_longmane(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_ESCAPE_FROM)
    {
        DoScriptText(SAY_START, pCreature, pPlayer);
        CAST_AI(npc_escortAI, pCreature->AI())->Start(false, false, pPlayer->GetGUID());
    }
    return true;
}

CreatureAI* GetAI_npc_kayra_longmaneAI(Creature* pCreature)
{
    npc_kayra_longmaneAI* thisAI = new npc_kayra_longmaneAI(pCreature);

    thisAI->FillPointMovementListForCreature();

    return thisAI;
}
/*######
## AddSC
######*/

void AddSC_zangarmarsh()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="npcs_ashyen_and_keleth";
    newscript->pGossipHello =  &GossipHello_npcs_ashyen_and_keleth;
    newscript->pGossipSelect = &GossipSelect_npcs_ashyen_and_keleth;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_cooshcoosh";
    newscript->GetAI = &GetAI_npc_cooshcoosh;
    newscript->pGossipHello =  &GossipHello_npc_cooshcoosh;
    newscript->pGossipSelect = &GossipSelect_npc_cooshcoosh;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_elder_kuruti";
    newscript->pGossipHello =  &GossipHello_npc_elder_kuruti;
    newscript->pGossipSelect = &GossipSelect_npc_elder_kuruti;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_mortog_steamhead";
    newscript->pGossipHello =  &GossipHello_npc_mortog_steamhead;
    newscript->pGossipSelect = &GossipSelect_npc_mortog_steamhead;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_kayra_longmane";
    newscript->GetAI = &GetAI_npc_kayra_longmaneAI;
    newscript->pQuestAccept = &QuestAccept_npc_kayra_longmane;
    newscript->RegisterSelf();
}

