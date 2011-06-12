/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* ScriptData
SDName: Boss_Dathrohan_Balnazzar
SD%Complete: 95
SDComment: Possibly need to fix/improve summons after death
SDCategory: Stratholme
EndScriptData */

#include "ScriptPCH.h"

enum eEnums
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
    {3444.156f, -3090.626f, 135.002f, 2.240f},                  //G1 front, left
    {3449.123f, -3087.009f, 135.002f, 2.240f},                  //G1 front, right
    {3446.246f, -3093.466f, 135.002f, 2.240f},                  //G1 back left
    {3451.160f, -3089.904f, 135.002f, 2.240f},                  //G1 back, right

    {3457.995f, -3080.916f, 135.002f, 3.784f},                  //G2 front, left
    {3454.302f, -3076.330f, 135.002f, 3.784f},                  //G2 front, right
    {3460.975f, -3078.901f, 135.002f, 3.784f},                  //G2 back left
    {3457.338f, -3073.979f, 135.002f, 3.784f}                   //G2 back, right
};

class boss_dathrohan_balnazzar : public CreatureScript
{
public:
    boss_dathrohan_balnazzar() : CreatureScript("boss_dathrohan_balnazzar") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_dathrohan_balnazzarAI (pCreature);
    }

    struct boss_dathrohan_balnazzarAI : public ScriptedAI
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

            if (me->GetEntry() == NPC_BALNAZZAR)
                me->UpdateEntry(NPC_DATHROHAN);
        }

        void JustDied(Unit* /*Victim*/)
        {
            static uint32 uiCount = sizeof(m_aSummonPoint)/sizeof(SummonDef);

            for (uint8 i=0; i<uiCount; ++i)
                me->SummonCreature(NPC_ZOMBIE,
                m_aSummonPoint[i].m_fX, m_aSummonPoint[i].m_fY, m_aSummonPoint[i].m_fZ, m_aSummonPoint[i].m_fOrient,
                TEMPSUMMON_TIMED_DESPAWN, HOUR*IN_MILLISECONDS);
        }

        void EnterCombat(Unit* /*who*/)
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
                if (m_uiMindBlast_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_MINDBLAST);
                    m_uiMindBlast_Timer = 15000 + rand()%5000;
                } else m_uiMindBlast_Timer -= uiDiff;

                //CrusadersHammer
                if (m_uiCrusadersHammer_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_CRUSADERSHAMMER);
                    m_uiCrusadersHammer_Timer = 12000;
                } else m_uiCrusadersHammer_Timer -= uiDiff;

                //CrusaderStrike
                if (m_uiCrusaderStrike_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_CRUSADERSTRIKE);
                    m_uiCrusaderStrike_Timer = 15000;
                } else m_uiCrusaderStrike_Timer -= uiDiff;

                //HolyStrike
                if (m_uiHolyStrike_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_HOLYSTRIKE);
                    m_uiHolyStrike_Timer = 15000;
                } else m_uiHolyStrike_Timer -= uiDiff;

                //BalnazzarTransform
                if (HealthBelowPct(40))
                {
                    if (me->IsNonMeleeSpellCasted(false))
                        me->InterruptNonMeleeSpells(false);

                    //restore hp, mana and stun
                    DoCast(me, SPELL_BALNAZZARTRANSFORM);
                    me->UpdateEntry(NPC_BALNAZZAR);
                    m_bTransformed = true;
                }
            }
            else
            {
                //MindBlast
                if (m_uiMindBlast_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_MINDBLAST);
                    m_uiMindBlast_Timer = 15000 + rand()%5000;
                } else m_uiMindBlast_Timer -= uiDiff;

                //ShadowShock
                if (m_uiShadowShock_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_SHADOWSHOCK);
                    m_uiShadowShock_Timer = 11000;
                } else m_uiShadowShock_Timer -= uiDiff;

                //PsychicScream
                if (m_uiPsychicScream_Timer <= uiDiff)
                {
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_PSYCHICSCREAM);

                    m_uiPsychicScream_Timer = 20000;
                } else m_uiPsychicScream_Timer -= uiDiff;

                //DeepSleep
                if (m_uiDeepSleep_Timer <= uiDiff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_SLEEP);

                    m_uiDeepSleep_Timer = 15000;
                } else m_uiDeepSleep_Timer -= uiDiff;

                //MindControl
                if (m_uiMindControl_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_MINDCONTROL);
                    m_uiMindControl_Timer = 15000;
                } else m_uiMindControl_Timer -= uiDiff;
            }

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_dathrohan_balnazzar()
{
    new boss_dathrohan_balnazzar();
}
