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
SDName: Mulgore
SD%Complete: 100
SDCategory: Mulgore
EndScriptData */

/* ContentData
EndContentData */

#include "scriptPCH.h"

struct plainVisionAI : public npc_escortAI
{
    plainVisionAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        Reset();
        isEngaged = false;
    }

    bool isEngaged;

    void Reset() override { }

    void WaypointReached(uint32 i) override { }

    void UpdateEscortAI(uint32 const uiDiff) override
    {
        if (!isEngaged)
        {
            isEngaged = true;
            Start(false, 0, nullptr, false);
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_plainVision(Creature* pCreature)
{
    return new plainVisionAI(pCreature);
}

void AddSC_mulgore()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "npc_plains_vision";
    newscript->GetAI = &GetAI_plainVision;
    newscript->RegisterSelf();
}
