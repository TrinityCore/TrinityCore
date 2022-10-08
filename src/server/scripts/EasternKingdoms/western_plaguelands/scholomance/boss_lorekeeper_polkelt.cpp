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
SDName: Boss_Lorekeeper_Polkelt
SD%Complete: 100
SDComment:
SDCategory: Scholomance
EndScriptData */

#include "scriptPCH.h"
#include "scholomance.h"

#define SPELL_VOLATILEINFECTION      24928
#define SPELL_DARKPLAGUE_AURA        12038
#define SPELL_CORROSIVEACID          8245
#define SPELL_NOXIOUSCATALYST        18151

struct boss_lorekeeperpolkeltAI : public ScriptedAI
{
    boss_lorekeeperpolkeltAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 VolatileInfection_Timer;
    uint32 Darkplague_Timer;
    uint32 CorrosiveAcid_Timer;
    uint32 NoxiousCatalyst_Timer;

    void Reset() override
    {
        VolatileInfection_Timer = 38000;
        CorrosiveAcid_Timer = 45000;
        NoxiousCatalyst_Timer = 35000;
    }

    void Aggro(Unit* /*pWho*/) override
    {
        DoCastSpellIfCan(m_creature, SPELL_DARKPLAGUE_AURA, CF_TRIGGERED | CF_AURA_NOT_PRESENT);        
    }
    
    void JustDied(Unit *killer) override
    {
        if (ScriptedInstance* pInstance = (ScriptedInstance*)m_creature->GetInstanceData())
            pInstance->SetData(TYPE_POLKELT, DONE);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //VolatileInfection_Timer
        if (VolatileInfection_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_VOLATILEINFECTION);
            VolatileInfection_Timer = 32000;
        }
        else VolatileInfection_Timer -= diff;

        //CorrosiveAcid_Timer
        if (CorrosiveAcid_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CORROSIVEACID);
            CorrosiveAcid_Timer = 25000;
        }
        else CorrosiveAcid_Timer -= diff;

        //NoxiousCatalyst_Timer
        if (NoxiousCatalyst_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_NOXIOUSCATALYST);
            NoxiousCatalyst_Timer = 38000;
        }
        else NoxiousCatalyst_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_lorekeeperpolkelt(Creature* pCreature)
{
    return new boss_lorekeeperpolkeltAI(pCreature);
}

void AddSC_boss_lorekeeperpolkelt()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_lorekeeper_polkelt";
    newscript->GetAI = &GetAI_boss_lorekeeperpolkelt;
    newscript->RegisterSelf();
}
