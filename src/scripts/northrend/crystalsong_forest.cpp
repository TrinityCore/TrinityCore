/*
 * Copyright (C) 2010 Trinity <http://www.trinitycore.org/>
 *
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

/* Script Data Start
SDName: CrystalSongForest
SDAuthor: Malcrom
SD%Complete: 99%
SDComment: 
SDCategory: CrystalsongForest
Script Data End */

#include "ScriptedPch.h"

/*******************************************************
 * npc_warmage_violetstand
 *******************************************************/

enum Spells
{
    SPELL_TRANSITUS_SHIELD_BEAM = 48310
};

enum NPCs 
{
    NPC_TRANSITUS_SHIELD_DUMMY   = 27306,
    NPC_WARMAGE_SARINA           = 32369,
    NPC_WARMAGE_HALISTER         = 32371,
    NPC_WARMAGE_ILSUDRIA         = 32372
};

struct npc_warmage_violetstandAI : public Scripted_NoMovementAI
{
    npc_warmage_violetstandAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature){}

    uint32 m_uiTimer;                 //Timer until recast
    std::list<Creature *> orbList;

    void Reset()
    {
        m_uiTimer = 0;
    }

    void Aggro(Unit* pWho){}

    void AttackStart(Unit* pWho){}

    void UpdateAI(const uint32 uiDiff)
    {
        if (m_uiTimer <= uiDiff)
        {
            m_creature->CastStop();           
            Creature* pTarget = GetClosestCreatureWithEntry(me,NPC_TRANSITUS_SHIELD_DUMMY,32.0f);

            switch(me->GetEntry())
            {
                case NPC_WARMAGE_SARINA:
                    GetCreatureListWithEntryInGrid(orbList, m_creature, NPC_TRANSITUS_SHIELD_DUMMY, 32.0f);
                    if (!orbList.empty())
                    {
                        for (std::list<Creature*>::iterator itr = orbList.begin(); itr != orbList.end(); ++itr)
                        {
                            if (Creature* pOrb = *itr)
                                if (pOrb->GetPositionY() < 1000)
                                    DoCast(pOrb,SPELL_TRANSITUS_SHIELD_BEAM);
                        }
                    }
                    m_uiTimer = 90000;
                    break;
				case NPC_WARMAGE_HALISTER:
                case NPC_WARMAGE_ILSUDRIA:
                    if (pTarget)
                        DoCast(pTarget,SPELL_TRANSITUS_SHIELD_BEAM);
                    m_uiTimer = 90000;
                    break;
            }
        }		
        else m_uiTimer -= uiDiff;

        ScriptedAI::UpdateAI(uiDiff);

        if (!UpdateVictim())
            return;
    }
};

CreatureAI* GetAI_npc_warmage_violetstand(Creature* pCreature)
{
    return new npc_warmage_violetstandAI(pCreature);
}

void AddSC_crystalsong_forest()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_warmage_violetstand";
    newscript->GetAI = &GetAI_npc_warmage_violetstand;
    newscript->RegisterSelf();
}