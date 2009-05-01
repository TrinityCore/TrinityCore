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
SDName: Alterac_Mountains
SD%Complete: 100
SDComment: Quest support: 6681
SDCategory: Alterac Mountains
EndScriptData */

/* ContentData
npc_ravenholdt
EndContentData */

#include "precompiled.h"

/*######
## npc_ravenholdt
######*/

struct TRINITY_DLL_DECL npc_ravenholdtAI : public ScriptedAI
{
    npc_ravenholdtAI(Creature *c) : ScriptedAI(c) {}

    void Reset() { }

    void MoveInLineOfSight(Unit *who)
    {
        if( who->GetTypeId() == TYPEID_PLAYER )
            if( ((Player*)who)->GetQuestStatus(6681) == QUEST_STATUS_INCOMPLETE )
                ((Player*)who)->KilledMonster(m_creature->GetEntry(),m_creature->GetGUID() );
    }

    void EnterCombat(Unit* who) { }
};

CreatureAI* GetAI_npc_ravenholdt(Creature *_Creature)
{
    return new npc_ravenholdtAI (_Creature);
}

void AddSC_alterac_mountains()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="npc_ravenholdt";
    newscript->GetAI = &GetAI_npc_ravenholdt;
    newscript->RegisterSelf();
}

