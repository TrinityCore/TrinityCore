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
SDName: Boss_High_Interrogator_Gerstahn
SD%Complete: 100
SDComment:
SDCategory: Blackrock Depths
EndScriptData */

#include "precompiled.h"

#define SPELL_SHADOWWORDPAIN        10894
#define SPELL_MANABURN              10876
#define SPELL_PSYCHICSCREAM         8122
#define SPELL_SHADOWSHIELD          22417

struct TRINITY_DLL_DECL boss_high_interrogator_gerstahnAI : public ScriptedAI
{
    boss_high_interrogator_gerstahnAI(Creature *c) : ScriptedAI(c) {}

    uint32 ShadowWordPain_Timer;
    uint32 ManaBurn_Timer;
    uint32 PsychicScream_Timer;
    uint32 ShadowShield_Timer;

    void Reset()
    {
        ShadowWordPain_Timer = 4000;
        ManaBurn_Timer = 14000;
        PsychicScream_Timer = 32000;
        ShadowShield_Timer = 8000;
    }

    void Aggro(Unit *who)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim() )
            return;

        //ShadowWordPain_Timer
        if (ShadowWordPain_Timer < diff)
        {
            Unit* target = NULL;
            target = SelectUnit(SELECT_TARGET_RANDOM,0);
            if (target)DoCast(target,SPELL_SHADOWWORDPAIN);
            ShadowWordPain_Timer = 7000;
        }else ShadowWordPain_Timer -= diff;

        //ManaBurn_Timer
        if (ManaBurn_Timer < diff)
        {
            Unit* target = NULL;
            target = SelectUnit(SELECT_TARGET_RANDOM,0);
            if (target)DoCast(target,SPELL_MANABURN);
            ManaBurn_Timer = 10000;
        }else ManaBurn_Timer -= diff;

        //PsychicScream_Timer
        if (PsychicScream_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_PSYCHICSCREAM);
            PsychicScream_Timer = 30000;
        }else PsychicScream_Timer -= diff;

        //ShadowShield_Timer
        if (ShadowShield_Timer < diff)
        {
            DoCast(m_creature,SPELL_SHADOWSHIELD);
            ShadowShield_Timer = 25000;
        }else ShadowShield_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_high_interrogator_gerstahn(Creature *_Creature)
{
    return new boss_high_interrogator_gerstahnAI (_Creature);
}

void AddSC_boss_high_interrogator_gerstahn()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_high_interrogator_gerstahn";
    newscript->GetAI = &GetAI_boss_high_interrogator_gerstahn;
    newscript->RegisterSelf();
}

