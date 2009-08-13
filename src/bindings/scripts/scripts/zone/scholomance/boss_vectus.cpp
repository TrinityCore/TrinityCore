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
SDName: Boss_Vectus
SD%Complete: 100
SDComment:
SDCategory: Scholomance
EndScriptData */

#include "precompiled.h"

#define EMOTE_GENERIC_FRENZY_KILL   -1000001

#define SPELL_FIRESHIELD        19626
#define SPELL_BLASTWAVE         13021
#define SPELL_FRENZY            28371

struct TRINITY_DLL_DECL boss_vectusAI : public ScriptedAI
{
    boss_vectusAI(Creature *c) : ScriptedAI(c) {}

    uint32 FireShield_Timer;
    uint32 BlastWave_Timer;
    uint32 Frenzy_Timer;

    void Reset()
    {
        FireShield_Timer = 2000;
        BlastWave_Timer = 14000;
        Frenzy_Timer = 0;
    }

    void EnterCombat(Unit *who)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //FireShield_Timer
        if (FireShield_Timer < diff)
        {
            DoCast(m_creature, SPELL_FIRESHIELD);
            FireShield_Timer = 90000;
        }else FireShield_Timer -= diff;

        //BlastWave_Timer
        if (BlastWave_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_BLASTWAVE);
            BlastWave_Timer = 12000;
        }else BlastWave_Timer -= diff;

        //Frenzy_Timer
        if (m_creature->GetHealth()*100 / m_creature->GetMaxHealth() < 25)
        {
            if (Frenzy_Timer < diff)
            {
                DoCast(m_creature,SPELL_FRENZY);
                DoScriptText(EMOTE_GENERIC_FRENZY_KILL, m_creature);

                Frenzy_Timer = 24000;
            }else Frenzy_Timer -= diff;
        }

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_vectus(Creature* pCreature)
{
    return new boss_vectusAI (pCreature);
}

void AddSC_boss_vectus()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_vectus";
    newscript->GetAI = &GetAI_boss_vectus;
    newscript->RegisterSelf();
}

