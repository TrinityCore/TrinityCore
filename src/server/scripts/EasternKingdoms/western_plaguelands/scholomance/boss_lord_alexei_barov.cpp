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
SDName: Boss_Lord_Alexei_Barov
SD%Complete: 100
SDComment: aura applied/defined in database
SDCategory: Scholomance
EndScriptData */

#include "scriptPCH.h"
#include "scholomance.h"

#define SPELL_IMMOLATE             20294                    // Old ID  was 15570
#define SPELL_VEILOFSHADOW         17820

struct boss_lordalexeibarovAI : public ScriptedAI
{
    boss_lordalexeibarovAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 Immolate_Timer;
    uint32 VeilofShadow_Timer;

    void Reset() override
    {
        Immolate_Timer = 7000;
        VeilofShadow_Timer = 15000;

        m_creature->LoadCreatureAddon(true);
    }

    void JustDied(Unit *killer) override
    {
        if (ScriptedInstance* pInstance = (ScriptedInstance*)m_creature->GetInstanceData())
            pInstance->SetData(TYPE_ALEXEIBAROV, DONE);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //Immolate_Timer
        if (Immolate_Timer < diff)
        {
            Unit* target = nullptr;
            target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);
            if (target) DoCastSpellIfCan(target, SPELL_IMMOLATE);

            Immolate_Timer = 12000;
        }
        else Immolate_Timer -= diff;

        //VeilofShadow_Timer
        if (VeilofShadow_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_VEILOFSHADOW);
            VeilofShadow_Timer = 20000;
        }
        else VeilofShadow_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_lordalexeibarov(Creature* pCreature)
{
    return new boss_lordalexeibarovAI(pCreature);
}

void AddSC_boss_lordalexeibarov()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_lord_alexei_barov";
    newscript->GetAI = &GetAI_boss_lordalexeibarov;
    newscript->RegisterSelf();
}
