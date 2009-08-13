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
SDName: Boss_Dathrohan_Balnazzar
SD%Complete: 95
SDComment: Possibly need to fix/improve summons after death
SDCategory: Stratholme
EndScriptData */

#include "precompiled.h"

enum
{
    //Dathrohan spells
    SPELL_CRUSADERSHAMMER           = 17286,                //AOE stun
    SPELL_CRUSADERSTRIKE            = 17281,
    SPELL_HOLYSTRIKE                = 17284,                //weapon dmg +3

    //Transform
    SPELL_BALNAZZARTRANSFORM        = 17288,                //restore full HP/mana, trigger spell Balnazzar Transform Stun

    //Balnazzar spells
    SPELL_SHADOWSHOCK               = 17399,
    SPELL_MINDBLAST                 = 17287,
    SPELL_PSYCHICSCREAM             = 13704,
    SPELL_SLEEP                     = 12098,
    SPELL_MINDCONTROL               = 15690,

    NPC_DATHROHAN                   = 10812,
    NPC_BALNAZZAR                   = 10813,
    NPC_ZOMBIE                      = 10698                 //probably incorrect
};

struct SummonDef
{
    float m_fX, m_fY, m_fZ, m_fOrient;
};

SummonDef m_aSummonPoint[]=
{
    {3444.156, -3090.626, 135.002, 2.240},                  //G1 front, left
    {3449.123, -3087.009, 135.002, 2.240},                  //G1 front, right
    {3446.246, -3093.466, 135.002, 2.240},                  //G1 back left
    {3451.160, -3089.904, 135.002, 2.240},                  //G1 back, right

    {3457.995, -3080.916, 135.002, 3.784},                  //G2 front, left
    {3454.302, -3076.330, 135.002, 3.784},                  //G2 front, right
    {3460.975, -3078.901, 135.002, 3.784},                  //G2 back left
    {3457.338, -3073.979, 135.002, 3.784}                   //G2 back, right
};

struct TRINITY_DLL_DECL boss_dathrohan_balnazzarAI : public ScriptedAI
{
    boss_dathrohan_balnazzarAI(Creature *c) : ScriptedAI(c) {}

    uint32 m_uiCrusadersHammer_Timer;
    uint32 m_uiCrusaderStrike_Timer;
    uint32 m_uiMindBlast_Timer;
    uint32 m_uiHolyStrike_Timer;
    uint32 m_uiShadowShock_Timer;
    uint32 m_uiPsychicScream_Timer;
    uint32 m_uiDeepSleep_Timer;
    uint32 m_uiMindControl_Timer;
    bool m_bTransformed;

    void Reset()
    {
        m_uiCrusadersHammer_Timer = 8000;
        m_uiCrusaderStrike_Timer = 12000;
        m_uiMindBlast_Timer = 6000;
        m_uiHolyStrike_Timer = 18000;
        m_uiShadowShock_Timer = 4000;
        m_uiPsychicScream_Timer = 16000;
        m_uiDeepSleep_Timer = 20000;
        m_uiMindControl_Timer = 10000;
        m_bTransformed = false;

        if (m_creature->GetEntry() == NPC_BALNAZZAR)
            m_creature->UpdateEntry(NPC_DATHROHAN);
    }

    void JustDied(Unit* Victim)
    {
        static uint32 uiCount = sizeof(m_aSummonPoint)/sizeof(SummonDef);

        for (uint8 i=0; i<uiCount; ++i)
            m_creature->SummonCreature(NPC_ZOMBIE,
            m_aSummonPoint[i].m_fX, m_aSummonPoint[i].m_fY, m_aSummonPoint[i].m_fZ, m_aSummonPoint[i].m_fOrient,
            TEMPSUMMON_TIMED_DESPAWN, HOUR*IN_MILISECONDS);
    }

    void EnterCombat(Unit *who)
    {
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (!UpdateVictim())
            return;

        //START NOT TRANSFORMED
        if (!m_bTransformed)
        {
            //MindBlast
            if (m_uiMindBlast_Timer < uiDiff)
            {
                DoCast(m_creature->getVictim(),SPELL_MINDBLAST);
                m_uiMindBlast_Timer = 15000 + rand()%5000;
            }else m_uiMindBlast_Timer -= uiDiff;

            //CrusadersHammer
            if (m_uiCrusadersHammer_Timer < uiDiff)
            {
                DoCast(m_creature->getVictim(),SPELL_CRUSADERSHAMMER);
                m_uiCrusadersHammer_Timer = 12000;
            }else m_uiCrusadersHammer_Timer -= uiDiff;

            //CrusaderStrike
            if (m_uiCrusaderStrike_Timer < uiDiff)
            {
                DoCast(m_creature->getVictim(),SPELL_CRUSADERSTRIKE);
                m_uiCrusaderStrike_Timer = 15000;
            }else m_uiCrusaderStrike_Timer -= uiDiff;

            //HolyStrike
            if (m_uiHolyStrike_Timer < uiDiff)
            {
                DoCast(m_creature->getVictim(),SPELL_HOLYSTRIKE);
                m_uiHolyStrike_Timer = 15000;
            }else m_uiHolyStrike_Timer -= uiDiff;

            //BalnazzarTransform
            if (m_creature->GetHealth()*100 / m_creature->GetMaxHealth() < 40)
            {
                if (m_creature->IsNonMeleeSpellCasted(false))
                    m_creature->InterruptNonMeleeSpells(false);

                //restore hp, mana and stun
                DoCast(m_creature,SPELL_BALNAZZARTRANSFORM);
                m_creature->UpdateEntry(NPC_BALNAZZAR);
                m_bTransformed = true;
            }
        }
        else
        {
            //MindBlast
            if (m_uiMindBlast_Timer < uiDiff)
            {
                DoCast(m_creature->getVictim(),SPELL_MINDBLAST);
                m_uiMindBlast_Timer = 15000 + rand()%5000;
            }else m_uiMindBlast_Timer -= uiDiff;

            //ShadowShock
            if (m_uiShadowShock_Timer < uiDiff)
            {
                DoCast(m_creature->getVictim(),SPELL_SHADOWSHOCK);
                m_uiShadowShock_Timer = 11000;
            }else m_uiShadowShock_Timer -= uiDiff;

            //PsychicScream
            if (m_uiPsychicScream_Timer < uiDiff)
            {
                if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM,0))
                    DoCast(pTarget,SPELL_PSYCHICSCREAM);

                m_uiPsychicScream_Timer = 20000;
            }else m_uiPsychicScream_Timer -= uiDiff;

            //DeepSleep
            if (m_uiDeepSleep_Timer < uiDiff)
            {
                if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM,0))
                    DoCast(pTarget,SPELL_SLEEP);

                m_uiDeepSleep_Timer = 15000;
            }else m_uiDeepSleep_Timer -= uiDiff;

            //MindControl
            if (m_uiMindControl_Timer < uiDiff)
            {
                DoCast(m_creature->getVictim(),SPELL_MINDCONTROL);
                m_uiMindControl_Timer = 15000;
            }else m_uiMindControl_Timer -= uiDiff;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_dathrohan_balnazzar(Creature* pCreature)
{
    return new boss_dathrohan_balnazzarAI (pCreature);
}

void AddSC_boss_dathrohan_balnazzar()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_dathrohan_balnazzar";
    newscript->GetAI = &GetAI_boss_dathrohan_balnazzar;
    newscript->RegisterSelf();
}

