/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>.sourceforge.net/>
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
SDName: Dun_Morogh
SD%Complete: 50
SDComment: Quest support: 1783
SDCategory: Dun Morogh
EndScriptData */

/* ContentData
npc_narm_faulk
EndContentData */

#include "precompiled.h"

/*######
## npc_narm_faulk
######*/

#define SAY_HEAL -1000280

struct TRINITY_DLL_DECL npc_narm_faulkAI : public ScriptedAI
{
    uint32 lifeTimer;
    bool spellHit;

    npc_narm_faulkAI(Creature *c) : ScriptedAI(c) {}

    void Reset()
    {
        lifeTimer = 120000;
        m_creature->SetUInt32Value(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_DEAD);
        m_creature->SetStandState(UNIT_STAND_STATE_DEAD);
        spellHit = false;
    }

    void EnterCombat(Unit *who)
    {
    }

    void MoveInLineOfSight(Unit *who)
    {
        return;
    }

    void UpdateAI(const uint32 diff)
    {
       if (m_creature->IsStandState())
        {
            if (lifeTimer < diff)
            {
                EnterEvadeMode();
                return;
            }
            else
                lifeTimer -= diff;
        }
    }

    void SpellHit(Unit *Hitter, const SpellEntry *Spellkind)
    {
        if (Spellkind->Id == 8593 && !spellHit)
        {
            DoCast(m_creature,32343);
            m_creature->SetStandState(UNIT_STAND_STATE_STAND);
            m_creature->SetUInt32Value(UNIT_DYNAMIC_FLAGS, 0);
            //m_creature->RemoveAllAuras();
            DoScriptText(SAY_HEAL, m_creature);
            spellHit = true;
        }
    }

};
CreatureAI* GetAI_npc_narm_faulk(Creature* pCreature)
{
    return new npc_narm_faulkAI (pCreature);
}

void AddSC_dun_morogh()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="npc_narm_faulk";
    newscript->GetAI = &GetAI_npc_narm_faulk;
    newscript->RegisterSelf();
}

