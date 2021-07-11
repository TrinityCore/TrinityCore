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
SDName: Boss_Grizzle
SD%Complete: 100
SDComment:
SDCategory: Blackrock Depths
EndScriptData */

#include "scriptPCH.h"

#define EMOTE_GENERIC_FRENZY_KILL   7797

#define SPELL_GROUNDTREMOR          6524
#define SPELL_FRENZY                8269

struct boss_grizzleAI : public ScriptedAI
{
    boss_grizzleAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 GroundTremor_Timer;
    uint32 Frenzy_Timer;

    void Reset() override
    {
        GroundTremor_Timer = 12000;
        Frenzy_Timer = 0;
    }

    void UpdateAI(uint32 const diff) override
    {
        //Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //GroundTremor_Timer
        if (GroundTremor_Timer < diff)
        {
            DoCastSpellIfCan(m_creature, SPELL_GROUNDTREMOR);
            GroundTremor_Timer = 8000;
        }
        else GroundTremor_Timer -= diff;

        //Frenzy_Timer
        if (m_creature->GetHealthPercent() < 51.0f)
        {
            if (Frenzy_Timer < diff)
            {
                if (DoCastSpellIfCan(m_creature, SPELL_FRENZY) == CAST_OK)
                {
                    DoScriptText(EMOTE_GENERIC_FRENZY_KILL, m_creature);
                    Frenzy_Timer = 15000;
                }
            }
            else Frenzy_Timer -= diff;
        }

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_grizzle(Creature* pCreature)
{
    return new boss_grizzleAI(pCreature);
}

void AddSC_boss_grizzle()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_grizzle";
    newscript->GetAI = &GetAI_boss_grizzle;
    newscript->RegisterSelf();
}
