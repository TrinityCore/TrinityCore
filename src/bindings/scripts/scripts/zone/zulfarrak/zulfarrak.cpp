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
SDName: Zulfarrak
SD%Complete: 50
SDComment: Consider it temporary, no instance script made for this instance yet.
SDCategory: Zul'Farrak
EndScriptData */

/* ContentData
npc_sergeant_bly
npc_weegli_blastfuse
EndContentData */

#include "precompiled.h"

/*######
## npc_sergeant_bly
######*/

#define FACTION_HOSTILE             14
#define FACTION_FRIENDLY            35

#define SPELL_SHIELD_BASH           11972
#define SPELL_REVENGE               12170

#define GOSSIP_BLY                  "[PH] In that case, i will take my reward!"

struct TRINITY_DLL_DECL npc_sergeant_blyAI : public ScriptedAI
{
    npc_sergeant_blyAI(Creature *c) : ScriptedAI(c)
    {
        //pInstance = c->GetInstanceData();
    }

    //ScriptedInstance* pInstance;

    uint32 ShieldBash_Timer;
    uint32 Revenge_Timer;                                   //this is wrong, spell should never be used unless m_creature->getVictim() dodge, parry or block attack. Trinity support required.

    void Reset()
    {
        ShieldBash_Timer = 5000;
        Revenge_Timer = 8000;

        m_creature->setFaction(FACTION_FRIENDLY);

        /*if (pInstance)
            pInstance->SetData(0, NOT_STARTED);*/
    }

    void EnterCombat(Unit *who)
    {
        /*if (pInstance)
            pInstance->SetData(0, IN_PROGRESS);*/
    }

    void JustDied(Unit *victim)
    {
        /*if (pInstance)
            pInstance->SetData(0, DONE);*/
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (ShieldBash_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_SHIELD_BASH);
            ShieldBash_Timer = 15000;
        }else ShieldBash_Timer -= diff;

        if (Revenge_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_REVENGE);
            Revenge_Timer = 10000;
        }else Revenge_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_npc_sergeant_bly(Creature* pCreature)
{
    return new npc_sergeant_blyAI (pCreature);
}

bool GossipHello_npc_sergeant_bly(Player* pPlayer, Creature* pCreature)
{
    /*if (pInstance->GetData(0) == DONE)
    {*/
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BLY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
    pPlayer->SEND_GOSSIP_MENU(1517, pCreature->GetGUID());
    /*}
    else if (pInstance->GetData(0) == IN_PROGRESS)
        pPlayer->SEND_GOSSIP_MENU(1516, pCreature->GetGUID());
    else
        pPlayer->SEND_GOSSIP_MENU(1515, pCreature->GetGUID());*/

    return true;
}

bool GossipSelect_npc_sergeant_bly(Player* pPlayer, Creature* pCreature, uint32 sender, uint32 action)
{
    if (action == GOSSIP_ACTION_INFO_DEF+1)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        pCreature->setFaction(FACTION_HOSTILE);
        CAST_AI(npc_sergeant_blyAI, pCreature->AI())->AttackStart(pPlayer);
    }
    return true;
}

/*######
## npc_weegli_blastfuse
######*/

#define SPELL_BOMB                  8858
#define SPELL_GOBLIN_LAND_MINE      21688
#define SPELL_SHOOT                 6660
#define SPELL_WEEGLIS_BARREL        10772

#define GOSSIP_WEEGLI               "[PH] Please blow up the door."

struct TRINITY_DLL_DECL npc_weegli_blastfuseAI : public ScriptedAI
{
    npc_weegli_blastfuseAI(Creature *c) : ScriptedAI(c)
    {
        //pInstance = c->GetInstanceData();
    }

    //ScriptedInstance* pInstance;

    void Reset()
    {
        /*if (pInstance)
            pInstance->SetData(0, NOT_STARTED);*/
    }

    void EnterCombat(Unit *who)
    {
        /*if (pInstance)
            pInstance->SetData(0, IN_PROGRESS);*/
    }

    void JustDied(Unit *victim)
    {
        /*if (pInstance)
            pInstance->SetData(0, DONE);*/
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_npc_weegli_blastfuse(Creature* pCreature)
{
    return new npc_weegli_blastfuseAI (pCreature);
}

bool GossipHello_npc_weegli_blastfuse(Player* pPlayer, Creature* pCreature)
{
    //event not implemented yet, this is only placeholder for future developement
    /*if (pInstance->GetData(0) == DONE)
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_WEEGLI, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        pPlayer->SEND_GOSSIP_MENU(1514, pCreature->GetGUID());//if event can proceed to end
    }
    else if (pInstance->GetData(0) == IN_PROGRESS)
        pPlayer->SEND_GOSSIP_MENU(1513, pCreature->GetGUID());//if event are in progress
    else*/
    pPlayer->SEND_GOSSIP_MENU(1511, pCreature->GetGUID());   //if event not started
    return true;
}

bool GossipSelect_npc_weegli_blastfuse(Player* pPlayer, Creature* pCreature, uint32 sender, uint32 action)
{
    if (action == GOSSIP_ACTION_INFO_DEF+1)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        //here we make him run to door, set the charge and run away off to nowhere
    }
    return true;
}

void AddSC_zulfarrak()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="npc_sergeant_bly";
    newscript->GetAI = &GetAI_npc_sergeant_bly;
    newscript->pGossipHello =  &GossipHello_npc_sergeant_bly;
    newscript->pGossipSelect = &GossipSelect_npc_sergeant_bly;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_weegli_blastfuse";
    newscript->GetAI = &GetAI_npc_weegli_blastfuse;
    newscript->pGossipHello =  &GossipHello_npc_weegli_blastfuse;
    newscript->pGossipSelect = &GossipSelect_npc_weegli_blastfuse;
    newscript->RegisterSelf();
}

