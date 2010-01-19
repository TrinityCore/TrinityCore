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
SDName: Boss_Death_knight_darkreaver
SD%Complete: 100
SDComment:
SDCategory: Scholomance
EndScriptData */

#include "ScriptedPch.h"

struct TRINITY_DLL_DECL boss_death_knight_darkreaverAI : public ScriptedAI
{
    boss_death_knight_darkreaverAI(Creature *c) : ScriptedAI(c) {}

    void Reset()
    {
    }

    void DamageTaken(Unit *done_by, uint32 &damage)
    {
        if (m_creature->GetHealth() <= damage)
            DoCast(m_creature, 23261, true);   //Summon Darkreaver's Fallen Charger
    }

    void EnterCombat(Unit *who)
    {
    }
};
CreatureAI* GetAI_boss_death_knight_darkreaver(Creature* pCreature)
{
    return new boss_death_knight_darkreaverAI (pCreature);
}

void AddSC_boss_death_knight_darkreaver()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_death_knight_darkreaver";
    newscript->GetAI = &GetAI_boss_death_knight_darkreaver;
    newscript->RegisterSelf();
}

