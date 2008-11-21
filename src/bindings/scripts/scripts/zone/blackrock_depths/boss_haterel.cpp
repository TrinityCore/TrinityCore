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
SDName: Boss_Haterel
SD%Complete: 100
SDComment:
SDCategory: Blackrock Depths
EndScriptData */

#include "precompiled.h"

#define SPELL_SHADOWBOLT        17483                       //Not sure if right ID
#define SPELL_MANABURN          10876
#define SPELL_SHADOWSHIELD      22417
#define SPELL_STRIKE            15580

struct TRINITY_DLL_DECL boss_haterelAI : public ScriptedAI
{
    boss_haterelAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 ShadowBolt_Timer;
    uint32 ManaBurn_Timer;
    uint32 ShadowShield_Timer;
    uint32 Strike_Timer;

    void Reset()
    {
        ShadowBolt_Timer = 15000;
        ManaBurn_Timer = 3000;
        ShadowShield_Timer = 8000;
        Strike_Timer = 12000;
    }

    void Aggro(Unit *who)
    {
    }
    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        //ShadowBolt_Timer
        if (ShadowBolt_Timer < diff)
        {
            Unit* target = NULL;
            target = SelectUnit(SELECT_TARGET_RANDOM,0);
            if (target) DoCast(target,SPELL_SHADOWBOLT);
            ShadowBolt_Timer = 7000;
        }else ShadowBolt_Timer -= diff;

        //ManaBurn_Timer
        if (ManaBurn_Timer < diff)
        {
            Unit* target = NULL;
            target = SelectUnit(SELECT_TARGET_RANDOM,0);
            if (target) DoCast(target,SPELL_MANABURN);
            ManaBurn_Timer = 13000;
        }else ManaBurn_Timer -= diff;

        //ShadowShield_Timer
        if (ShadowShield_Timer < diff)
        {
            DoCast(m_creature,SPELL_SHADOWSHIELD);
            ShadowShield_Timer = 25000;
        }else ShadowShield_Timer -= diff;

        //Strike_Timer
        if (Strike_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_STRIKE);
            Strike_Timer = 10000;
        }else Strike_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_haterel(Creature *_Creature)
{
    return new boss_haterelAI (_Creature);
}

void AddSC_boss_haterel()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_haterel";
    newscript->GetAI = GetAI_boss_haterel;
    newscript->RegisterSelf();
}
