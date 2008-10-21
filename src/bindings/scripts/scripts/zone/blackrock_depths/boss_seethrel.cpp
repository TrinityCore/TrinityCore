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
SDName: Boss_Seethrel
SD%Complete: 100
SDComment:
SDCategory: Blackrock Depths
EndScriptData */

#include "precompiled.h"

#define SPELL_FROSTBOLT         16799
#define SPELL_FROSTARMOR        15784                       //This is actually a buff he gives himself
#define SPELL_BLIZZARD          19099
#define SPELL_FROSTNOVA         15063
#define SPELL_FROSTWARD         15004

struct TRINITY_DLL_DECL boss_seethrelAI : public ScriptedAI
{
    boss_seethrelAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 FrostArmor_Timer;
    uint32 Frostbolt_Timer;
    uint32 Blizzard_Timer;
    uint32 FrostNova_Timer;
    uint32 FrostWard_Timer;

    void Reset()
    {
        FrostArmor_Timer = 2000;
        Frostbolt_Timer = 6000;
        Blizzard_Timer = 18000;
        FrostNova_Timer = 12000;
        FrostWard_Timer = 25000;

        m_creature->CastSpell(m_creature,SPELL_FROSTARMOR,true);
    }

    void Aggro(Unit *who)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        //FrostArmor_Timer
        if (FrostArmor_Timer < diff)
        {
            DoCast(m_creature, SPELL_FROSTARMOR);
            FrostArmor_Timer = 180000;
        }else FrostArmor_Timer -= diff;

        //Frostbolt_Timer
        if (Frostbolt_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_FROSTBOLT);
            Frostbolt_Timer = 15000;
        }else Frostbolt_Timer -= diff;

        //Blizzard_Timer
        if (Blizzard_Timer < diff)
        {
            Unit* target = NULL;
            target = SelectUnit(SELECT_TARGET_RANDOM,0);
            if (target) DoCast(target,SPELL_BLIZZARD);
            Blizzard_Timer = 22000;
        }else Blizzard_Timer -= diff;

        //FrostNova_Timer
        if (FrostNova_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_FROSTNOVA);
            FrostNova_Timer = 14000;
        }else FrostNova_Timer -= diff;

        //FrostWard_Timer
        if (FrostWard_Timer < diff)
        {
            DoCast(m_creature,SPELL_FROSTWARD);
            FrostWard_Timer = 68000;
        }else FrostWard_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_seethrel(Creature *_Creature)
{
    return new boss_seethrelAI (_Creature);
}

void AddSC_boss_seethrel()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_seethrel";
    newscript->GetAI = GetAI_boss_seethrel;
    m_scripts[nrscripts++] = newscript;
}
