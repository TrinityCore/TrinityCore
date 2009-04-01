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
SDName: Boss_Lorekeeper_Polkelt
SD%Complete: 100
SDComment:
SDCategory: Scholomance
EndScriptData */

#include "precompiled.h"
#include "def_scholomance.h"

#define SPELL_VOLATILEINFECTION      24928
#define SPELL_DARKPLAGUE             18270
#define SPELL_CORROSIVEACID          23313
#define SPELL_NOXIOUSCATALYST        18151

struct TRINITY_DLL_DECL boss_lorekeeperpolkeltAI : public ScriptedAI
{
    boss_lorekeeperpolkeltAI(Creature *c) : ScriptedAI(c) {}

    uint32 VolatileInfection_Timer;
    uint32 Darkplague_Timer;
    uint32 CorrosiveAcid_Timer;
    uint32 NoxiousCatalyst_Timer;

    void Reset()
    {
        VolatileInfection_Timer = 38000;
        Darkplague_Timer = 8000;
        CorrosiveAcid_Timer = 45000;
        NoxiousCatalyst_Timer = 35000;
    }

    void JustDied(Unit *killer)
    {
        ScriptedInstance *pInstance = (m_creature->GetInstanceData()) ? ((ScriptedInstance*)m_creature->GetInstanceData()) : NULL;
        if(pInstance)
        {
            pInstance->SetData(DATA_LOREKEEPERPOLKELT_DEATH, 0);

            if(pInstance->GetData(DATA_CANSPAWNGANDLING))
                m_creature->SummonCreature(1853, 180.73, -9.43856, 75.507, 1.61399, TEMPSUMMON_DEAD_DESPAWN, 0);
        }
    }

    void Aggro(Unit *who)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //VolatileInfection_Timer
        if (VolatileInfection_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_VOLATILEINFECTION);
            VolatileInfection_Timer = 32000;
        }else VolatileInfection_Timer -= diff;

        //Darkplague_Timer
        if (Darkplague_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_DARKPLAGUE);
            Darkplague_Timer = 8000;
        }else Darkplague_Timer -= diff;

        //CorrosiveAcid_Timer
        if (CorrosiveAcid_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_CORROSIVEACID);
            CorrosiveAcid_Timer = 25000;
        }else CorrosiveAcid_Timer -= diff;

        //NoxiousCatalyst_Timer
        if (NoxiousCatalyst_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_NOXIOUSCATALYST);
            NoxiousCatalyst_Timer = 38000;
        }else NoxiousCatalyst_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_lorekeeperpolkelt(Creature *_Creature)
{
    return new boss_lorekeeperpolkeltAI (_Creature);
}

void AddSC_boss_lorekeeperpolkelt()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_lorekeeper_polkelt";
    newscript->GetAI = &GetAI_boss_lorekeeperpolkelt;
    newscript->RegisterSelf();
}

