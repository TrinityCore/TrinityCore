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
SDName: Boss_Houndmaster_Loksey
SD%Complete: 100
SDComment: TODO: if this guy not involved in some special event, remove (and let ACID script)
SDCategory: Scarlet Monastery
EndScriptData */

#include "scriptPCH.h"

enum
{
    SAY_AGGRO                       = -1189021,
    SPELL_SUMMONSCARLETHOUND        = 17164,
    SPELL_BLOODLUST                 = 6742
};

struct boss_houndmaster_lokseyAI : public ScriptedAI
{
    boss_houndmaster_lokseyAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 BloodLust_Timer;

    void Reset() override
    {
        BloodLust_Timer = 20000;
    }

    void Aggro(Unit *who) override
    {
        DoScriptText(SAY_AGGRO, m_creature);
        DoCastSpellIfCan(m_creature, SPELL_SUMMONSCARLETHOUND);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (BloodLust_Timer < diff)
        {
            DoCastSpellIfCan(m_creature, SPELL_BLOODLUST);
            BloodLust_Timer = 20000;
        }
        else BloodLust_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_houndmaster_loksey(Creature* pCreature)
{
    return new boss_houndmaster_lokseyAI(pCreature);
}

void AddSC_boss_houndmaster_loksey()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_houndmaster_loksey";
    newscript->GetAI = &GetAI_boss_houndmaster_loksey;
    newscript->RegisterSelf();
}
