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
    SPELL_POISON_CLOUD                                     = 3815,
    SPELL_FRENZIED_RAGE                                    = 3490
};

struct TRINITY_DLL_DECL boss_aku_maiAI : public ScriptedAI
{
    boss_aku_maiAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }
    
    uint32 uiPoisonCloudTimer;
    bool bIsEnraged;
    
    ScriptedInstance *pInstance;
    
    void Reset()
    {
        uiPoisonCloudTimer = urand(5000,9000);
        bIsEnraged = false;
        if (pInstance)
            pInstance->SetData(TYPE_AKU_MAI, NOT_STARTED);
    }
    
    void EnterCombat(Unit* who)
    {
        if (pInstance)
            pInstance->SetData(TYPE_AKU_MAI, IN_PROGRESS);
    }
    
    void JustDied(Unit* killer)
    {
        if (pInstance)
            pInstance->SetData(TYPE_AKU_MAI, DONE);
    }
    
    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;
        
        if (uiPoisonCloudTimer < diff)
        {
            DoCastVictim(SPELL_POISON_CLOUD);
            uiPoisonCloudTimer = urand(25000,50000);
        } else uiPoisonCloudTimer -= diff;

        if (!bIsEnraged && HealthBelowPct(30))
        {
            DoCast(m_creature,SPELL_FRENZIED_RAGE);
            bIsEnraged = true;
        }
        
        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_aku_mai(Creature* pCreature)
{
    return new boss_aku_maiAI (pCreature);
}

void AddSC_boss_aku_mai()
{
    Script *newscript;
    
    newscript = new Script;
    newscript->Name = "boss_aku_mai";
    newscript->GetAI = &GetAI_boss_aku_mai;
    newscript->RegisterSelf();
}
