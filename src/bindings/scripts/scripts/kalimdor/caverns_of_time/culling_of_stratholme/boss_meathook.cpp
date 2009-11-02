/*
* Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
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
SDName: Boss meathook
SDAuthor: Tartalo
SD%Complete: 100
SDComment: It may need timer adjustment
SDCategory:
Script Data End */

#include "precompiled.h"
#include "culling_of_stratholme.h"

enum Spells
{
    SPELL_CONSTRICTING_CHAINS                              = 52696, //Encases the targets in chains, dealing 1800 Physical damage every 1 sec. and stunning the target for 5 sec.
    H_SPELL_CONSTRICTING_CHAINS                            = 58823,
    SPELL_DISEASE_EXPULSION                                = 52666, //Meathook belches out a cloud of disease, dealing 1710 to 1890 Nature damage and interrupting the spell casting of nearby enemy targets for 4 sec.
    H_SPELL_DISEASE_EXPULSION                              = 58824,
    SPELL_FRENZY                                           = 58841 //Increases the caster's Physical damage by 10% for 30 sec.
};
//not in db
enum Yells
{
    SAY_AGGRO                                              = -1595026,
    SAY_SLAY_1                                             = -1595027,
    SAY_SLAY_2                                             = -1595028,
    SAY_SLAY_3                                             = -1595029,
    SAY_SPAWN                                              = -1595030,
    SAY_DEATH                                              = -1595031
};

struct TRINITY_DLL_DECL boss_meathookAI : public ScriptedAI
{
    boss_meathookAI(Creature *c) : ScriptedAI(c) 
    {
        pInstance = c->GetInstanceData();
        if (pInstance)
            DoScriptText(SAY_SPAWN,m_creature);
    }

    uint32 uiChainTimer;
    uint32 uiDiseaseTimer;
    uint32 uiFrenzyTimer;
    
    ScriptedInstance* pInstance;

    void Reset()
    {
        uiChainTimer = urand(12000,17000);   //seen on video 13, 17, 15, 12, 16
        uiDiseaseTimer = urand(2000,4000);   //approx 3s
        uiFrenzyTimer = urand(21000,26000);  //made it up
        
        if (pInstance)
            pInstance->SetData(DATA_MEATHOOK_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
        
        if (pInstance)
            pInstance->SetData(DATA_MEATHOOK_EVENT, IN_PROGRESS);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (uiDiseaseTimer <= diff)
        {
            DoCastAOE(HEROIC(SPELL_DISEASE_EXPULSION,H_SPELL_DISEASE_EXPULSION));
            uiDiseaseTimer = urand(1500,4000);
        } else uiDiseaseTimer -= diff;

        if (uiFrenzyTimer <= diff)
        {
            DoCast(m_creature, SPELL_FRENZY);
            uiFrenzyTimer = urand(21000,26000);
        } else uiFrenzyTimer -= diff;

        if (uiChainTimer <= diff)
        {
            if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                DoCast(pTarget, HEROIC(SPELL_CONSTRICTING_CHAINS,H_SPELL_CONSTRICTING_CHAINS)); //anyone but the tank
            uiChainTimer = urand(2000,4000);
        } else uiChainTimer -= diff;

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH, m_creature);
        
        if (pInstance)
            pInstance->SetData(DATA_MEATHOOK_EVENT, DONE);
    }

    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;

        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3), m_creature);
    }
};

CreatureAI* GetAI_boss_meathook(Creature* pCreature)
{
    return new boss_meathookAI (pCreature);
}

void AddSC_boss_meathook()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_meathook";
    newscript->GetAI = &GetAI_boss_meathook;
    newscript->RegisterSelf();
}
