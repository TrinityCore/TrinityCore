 /* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Shadowfang_Keep
SD%Complete: 75
SDComment: npc_shadowfang_prisoner using escortAI for movement to door. Might need additional code in case being attacked. Add proper texts/say().
SDCategory: Shadowfang Keep
EndScriptData */

/* ContentData
npc_shadowfang_prisoner
EndContentData */

#include "precompiled.h"
#include "../../npc/npc_escortAI.h"
#include "def_shadowfang_keep.h"

/*######
## npc_shadowfang_prisoner
######*/

#define SAY_FREE                -1033000
#define GOSSIP_ITEM_DOOR        "Thanks, I'll follow you to the door."

struct TRINITY_DLL_DECL npc_shadowfang_prisonerAI : public npc_escortAI
{
    npc_shadowfang_prisonerAI(Creature *c) : npc_escortAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
    }

    ScriptedInstance *pInstance;

    void WaypointReached(uint32 i)
    {
        if( pInstance && i == 6)
        {
            m_creature->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
            DoScriptText(SAY_FREE, m_creature);
            pInstance->SetData(TYPE_FREE_NPC, DONE);
        }
    }

    void Reset() {}
    void Aggro(Unit* who) {}
};

CreatureAI* GetAI_npc_shadowfang_prisoner(Creature *_Creature)
{
    npc_shadowfang_prisonerAI* prisonerAI = new npc_shadowfang_prisonerAI(_Creature);

    uint32 eCreature = _Creature->GetEntry();

    if( eCreature==3849)                                    //adamant
        prisonerAI->AddWaypoint(0, -254.47, 2117.48, 81.17);
    if( eCreature==3850)                                    //ashcrombe
        prisonerAI->AddWaypoint(0, -252.35, 2126.71, 81.17);

    prisonerAI->AddWaypoint(1, -253.63, 2131.27, 81.28);
    prisonerAI->AddWaypoint(2, -249.66, 2142.45, 87.01);
    prisonerAI->AddWaypoint(3, -248.08, 2143.68, 87.01);
    prisonerAI->AddWaypoint(4, -238.87, 2139.93, 87.01);
    prisonerAI->AddWaypoint(5, -235.47, 2149.18, 90.59);
    prisonerAI->AddWaypoint(6, -239.89, 2156.06, 90.62, 20000);

    return (CreatureAI*)prisonerAI;
}

bool GossipHello_npc_shadowfang_prisoner(Player *player, Creature *_Creature)
{
    ScriptedInstance* pInstance = ((ScriptedInstance*)_Creature->GetInstanceData());

    if (!pInstance)
        return false;

    if (pInstance->GetData(TYPE_FREE_NPC) != DONE && pInstance->GetData(TYPE_RETHILGORE) == DONE)
        player->ADD_GOSSIP_ITEM( 0, GOSSIP_ITEM_DOOR, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(), _Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_shadowfang_prisoner(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    if (action == GOSSIP_ACTION_INFO_DEF+1)
    {
        player->CLOSE_GOSSIP_MENU();
        ((npc_escortAI*)(_Creature->AI()))->Start(false, false, false);
    }
    return true;
}

/*######
## AddSC
######*/

void AddSC_shadowfang_keep()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="npc_shadowfang_prisoner";
    newscript->pGossipHello =  &GossipHello_npc_shadowfang_prisoner;
    newscript->pGossipSelect = &GossipSelect_npc_shadowfang_prisoner;
    newscript->GetAI = &GetAI_npc_shadowfang_prisoner;
    newscript->RegisterSelf();
}

