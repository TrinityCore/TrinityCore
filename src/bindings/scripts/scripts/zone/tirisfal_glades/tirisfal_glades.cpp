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
SDName: Tirisfal_Glades
SD%Complete: 100
SDComment: Quest support: 590
SDCategory: Tirisfal Glades
EndScriptData */

/* ContentData
npc_calvin_montague
EndContentData */

#include "precompiled.h"

/*######
## npc_calvin_montague
######*/

#define QUEST_590           590
#define FACTION_FRIENDLY    68
#define FACTION_HOSTILE     16

struct TRINITY_DLL_DECL npc_calvin_montagueAI : public ScriptedAI
{
    npc_calvin_montagueAI(Creature* c) : ScriptedAI(c) { Reset(); }

    void Reset()
    {
        m_creature->setFaction(FACTION_FRIENDLY);
    }

    void Aggro(Unit* who) { }

    void JustDied(Unit* Killer)
    {
        if( Killer->GetTypeId() == TYPEID_PLAYER )
            if( ((Player*)Killer)->GetQuestStatus(QUEST_590) == QUEST_STATUS_INCOMPLETE )
                ((Player*)Killer)->AreaExploredOrEventHappens(QUEST_590);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_npc_calvin_montague(Creature *_Creature)
{
    return new npc_calvin_montagueAI (_Creature);
}

bool QuestAccept_npc_calvin_montague(Player* player, Creature* creature, Quest const* quest)
{
    if( quest->GetQuestId() == QUEST_590 )
    {
        creature->setFaction(FACTION_HOSTILE);
        ((npc_calvin_montagueAI*)creature->AI())->AttackStart(player);
    }
    return true;
}

void AddSC_tirisfal_glades()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="npc_calvin_montague";
    newscript->GetAI = GetAI_npc_calvin_montague;
    newscript->pQuestAccept = &QuestAccept_npc_calvin_montague;
    m_scripts[nrscripts++] = newscript;
}
