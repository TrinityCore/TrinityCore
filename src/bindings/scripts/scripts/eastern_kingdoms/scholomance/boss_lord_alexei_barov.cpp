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
SDName: Boss_Lord_Alexei_Barov
SD%Complete: 100
SDComment: aura applied/defined in database
SDCategory: Scholomance
EndScriptData */

#include "precompiled.h"
#include "def_scholomance.h"

#define SPELL_IMMOLATE             20294                    // Old ID  was 15570
#define SPELL_VEILOFSHADOW         17820

struct TRINITY_DLL_DECL boss_lordalexeibarovAI : public ScriptedAI
{
    boss_lordalexeibarovAI(Creature *c) : ScriptedAI(c) {}

    uint32 Immolate_Timer;
    uint32 VeilofShadow_Timer;

    void Reset()
    {
        Immolate_Timer = 7000;
        VeilofShadow_Timer = 15000;

        m_creature->LoadCreaturesAddon();
    }

    void JustDied(Unit *killer)
    {
        ScriptedInstance *pInstance = m_creature->GetInstanceData();
        if (pInstance)
        {
            pInstance->SetData(DATA_LORDALEXEIBAROV_DEATH, 0);

            if (pInstance->GetData(TYPE_GANDLING) == IN_PROGRESS)
                m_creature->SummonCreature(1853, 180.73, -9.43856, 75.507, 1.61399, TEMPSUMMON_DEAD_DESPAWN, 0);
        }
    }

    void EnterCombat(Unit *who)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //Immolate_Timer
        if (Immolate_Timer < diff)
        {
            Unit* target = NULL;
            target = SelectUnit(SELECT_TARGET_RANDOM,0);
            if (target) DoCast(target,SPELL_IMMOLATE);

            Immolate_Timer = 12000;
        }else Immolate_Timer -= diff;

        //VeilofShadow_Timer
        if (VeilofShadow_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_VEILOFSHADOW);
            VeilofShadow_Timer = 20000;
        }else VeilofShadow_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_lordalexeibarov(Creature* pCreature)
{
    return new boss_lordalexeibarovAI (pCreature);
}

void AddSC_boss_lordalexeibarov()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_lord_alexei_barov";
    newscript->GetAI = &GetAI_boss_lordalexeibarov;
    newscript->RegisterSelf();
}

