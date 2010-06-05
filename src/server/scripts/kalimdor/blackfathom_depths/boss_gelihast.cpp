/*
* Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
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

#include "ScriptedPch.h"
#include "blackfathom_deeps.h"

enum Spells
{
    SPELL_NET                                              = 6533
};

struct boss_gelihastAI : public ScriptedAI
{
    boss_gelihastAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiNetTimer;

    ScriptedInstance *pInstance;

    void Reset()
    {
        uiNetTimer = urand(2000,4000);
        if (pInstance)
            pInstance->SetData(TYPE_GELIHAST, NOT_STARTED);
    }

    void EnterCombat(Unit* /*who*/)
    {
        if (pInstance)
            pInstance->SetData(TYPE_GELIHAST, IN_PROGRESS);
    }

    void JustDied(Unit* /*killer*/)
    {
        if (pInstance)
            pInstance->SetData(TYPE_GELIHAST, DONE);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (uiNetTimer < diff)
        {
            DoCastVictim(SPELL_NET);
            uiNetTimer = urand(4000,7000);
        } else uiNetTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_gelihast(Creature* pCreature)
{
    return new boss_gelihastAI (pCreature);
}

void AddSC_boss_gelihast()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_gelihast";
    newscript->GetAI = &GetAI_boss_gelihast;
    newscript->RegisterSelf();
}
