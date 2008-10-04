/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Eversong_Woods
SD%Complete: 100
SDComment: Quest support: 8346, 8483
SDCategory: Eversong Woods
EndScriptData */

/* ContentData
mobs_mana_tapped
npc_prospector_anvilward
EndContentData */

#include "precompiled.h"
#include "../../npc/npc_escortAI.h"

/*######
## mobs_mana_tapped
######*/

struct MANGOS_DLL_DECL mobs_mana_tappedAI : public ScriptedAI
{
    mobs_mana_tappedAI(Creature *c) : ScriptedAI(c) {Reset();}

    void Reset() { }

    void Aggro(Unit *who) { }

    void SpellHit(Unit *caster, const SpellEntry *spell)
    {
        if( caster->GetTypeId() == TYPEID_PLAYER)
            if( ((Player*)caster)->GetQuestStatus(8346) == QUEST_STATUS_INCOMPLETE && !((Player*)caster)->GetReqKillOrCastCurrentCount(8346, m_creature->GetEntry()) && spell->Id == 28734)
                ((Player*)caster)->CastedCreatureOrGO(15468, m_creature->GetGUID(), spell->Id);
        return;
    }
};
CreatureAI* GetAI_mobs_mana_tapped(Creature *_Creature)
{
    return new mobs_mana_tappedAI (_Creature);
}

/*######
## npc_prospector_anvilward
######*/

#define QUEST_THE_DWARVEN_SPY 8483

struct MANGOS_DLL_DECL npc_prospector_anvilwardAI : public npc_escortAI
{
    // CreatureAI functions
    npc_prospector_anvilwardAI(Creature *c) : npc_escortAI(c) {Reset();}

    // Pure Virtual Functions
    void WaypointReached(uint32 i)
    {
        switch (i)
        {
            case 0:
                m_creature->Say("Very well. Let's see what you have to show me, $N.", LANG_UNIVERSAL, PlayerGUID);
                break;
            case 5:
                m_creature->Say("What manner of trick is this, $R? If you seek to ambush me, I warn you I will not go down quietly!", LANG_UNIVERSAL, PlayerGUID);
                break;
            case 6:
                m_creature->setFaction(24);
                break;
        }
    }

    void Aggro(Unit* who) { }

    void Reset()
    {
        //Default npc faction
        m_creature->setFaction(35);
    }

    void JustDied(Unit* killer)
    {
        //Default npc faction
        m_creature->setFaction(35);
    }

    void UpdateAI(const uint32 diff)
    {
        npc_escortAI::UpdateAI(diff);                       //Must update npc_escortAI

    }
};

CreatureAI* GetAI_npc_prospector_anvilward(Creature *_Creature)
{
    npc_prospector_anvilwardAI* thisAI = new npc_prospector_anvilwardAI(_Creature);

    thisAI->AddWaypoint(0, 9294.78, -6682.51, 22.42);
    thisAI->AddWaypoint(1, 9298.27, -6667.99, 22.42);
    thisAI->AddWaypoint(2, 9309.63, -6658.84, 22.43);
    thisAI->AddWaypoint(3, 9304.43, -6649.31, 26.46);
    thisAI->AddWaypoint(4, 9298.83, -6648.00, 28.61);
    thisAI->AddWaypoint(5, 9291.06, -6653.46, 31.83,2500);
    thisAI->AddWaypoint(6, 9289.08, -6660.17, 31.85,5000);
    thisAI->AddWaypoint(7, 9291.06, -6653.46, 31.83);

    return (CreatureAI*)thisAI;
}

bool GossipHello_npc_prospector_anvilward(Player *player, Creature *_Creature)
{
    if( player->GetQuestStatus(QUEST_THE_DWARVEN_SPY) == QUEST_STATUS_INCOMPLETE )
        player->ADD_GOSSIP_ITEM(0, "I need a moment of your time, sir.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    player->SEND_GOSSIP_MENU(8239, _Creature->GetGUID());
    return true;
}

bool GossipSelect_npc_prospector_anvilward(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    switch(action)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            player->ADD_GOSSIP_ITEM( 0, "Why... yes, of course. I've something to show you right inside this building, Mr. Anvilward.",GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+2);
            player->SEND_GOSSIP_MENU(8240, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            player->CLOSE_GOSSIP_MENU();
            //attack,defend,walk
            ((npc_escortAI*)(_Creature->AI()))->Start(true, true, false, player->GetGUID());
            break;
    }
    return true;
}

void AddSC_eversong_woods()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="mobs_mana_tapped";
    newscript->GetAI = GetAI_mobs_mana_tapped;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name= "npc_prospector_anvilward";
    newscript->GetAI = GetAI_npc_prospector_anvilward;
    newscript->pGossipHello =  &GossipHello_npc_prospector_anvilward;
    newscript->pGossipSelect = &GossipSelect_npc_prospector_anvilward;
    m_scripts[nrscripts++] = newscript;
}
