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
SDName: Boss_Vilerel
SD%Complete: 100
SDComment:
SDCategory: Blackrock Depths
EndScriptData */

#include "precompiled.h"

#define SPELL_MINDBLAST             15587
#define SPELL_HEAL                  15586
#define SPELL_PRAYEROFHEALING       15585
#define SPELL_SHIELD                10901

struct TRINITY_DLL_DECL boss_vilerelAI : public ScriptedAI
{
    boss_vilerelAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 MindBlast_Timer;
    uint32 Heal_Timer;
    uint32 PrayerOfHealing_Timer;
    uint32 Shield_Timer;

    void Reset()
    {
        MindBlast_Timer = 10000;
        Heal_Timer = 35000;
        PrayerOfHealing_Timer = 25000;
        Shield_Timer = 3000;
    }

    void Aggro(Unit *who)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        //MindBlast_Timer
        if (MindBlast_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_MINDBLAST);
            MindBlast_Timer = 7000;
        }else MindBlast_Timer -= diff;

        //Heal_Timer
        if (Heal_Timer < diff)
        {
            DoCast(m_creature,SPELL_HEAL);
            Heal_Timer = 20000;
        }else Heal_Timer -= diff;

        //PrayerOfHealing_Timer
        if (PrayerOfHealing_Timer < diff)
        {
            DoCast(m_creature,SPELL_PRAYEROFHEALING);
            PrayerOfHealing_Timer = 30000;
        }else PrayerOfHealing_Timer -= diff;

        //Shield_Timer
        if (Shield_Timer < diff)
        {
            DoCast(m_creature,SPELL_SHIELD);
            Shield_Timer = 30000;
        }else Shield_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_vilerel(Creature *_Creature)
{
    return new boss_vilerelAI (_Creature);
}

void AddSC_boss_vilerel()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_vilerel";
    newscript->GetAI = GetAI_boss_vilerel;
    m_scripts[nrscripts++] = newscript;
}
