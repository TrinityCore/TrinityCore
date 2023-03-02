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
SDName: Boss_Dathrohan_Balnazzar
SD%Complete: 95
SDComment: Possibly need to fix/improve summons after death
SDCategory: Stratholme
EndScriptData */

#include "scriptPCH.h"
#include "stratholme.h"

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
    SPELL_MINDCONTROL               = 17405,

    NPC_DATHROHAN                   = 10812,
    NPC_BALNAZZAR                   = 10813,
    //NPC_ZOMBIE                      = 10698                 //probably incorrect
    NPC_SKEL_BERSERKER              = 10391,
    NPC_SKEL_GUARDIAN               = 10390
};

struct SummonDef
{
    float m_fX, m_fY, m_fZ, m_fOrient;
};

SummonDef m_aSummonPoint[] =
{
    {3444.156f, -3090.626f, 135.002f, 2.240f},              //G1 front, left
    {3449.123f, -3087.009f, 135.002f, 2.240f},              //G1 front, right
    {3446.246f, -3093.466f, 135.002f, 2.240f},              //G1 back left
    {3451.160f, -3089.904f, 135.002f, 2.240f},              //G1 back, right

    {3457.995f, -3080.916f, 135.002f, 3.784f},              //G2 front, left
    {3454.302f, -3076.330f, 135.002f, 3.784f},              //G2 front, right
    {3460.975f, -3078.901f, 135.002f, 3.784f},              //G2 back left
    {3457.338f, -3073.979f, 135.002f, 3.784f},              //G2 back, right

    {3479.995f, -3062.916f, 135.002f, 3.784f},              //G3 front, left
    {3476.302f, -3058.330f, 135.002f, 3.784f},              //G3 front, right
    {3482.975f, -3060.901f, 135.002f, 3.784f},              //G3 back left
    {3479.338f, -3055.979f, 135.002f, 3.784f},              //G3 back, right

    {3501.995f, -3074.916f, 134.997f, 3.784f},              //G4 front, left
    {3498.302f, -3070.330f, 134.997f, 3.784f},              //G4 front, right
    {3504.975f, -3072.901f, 134.997f, 3.784f},              //G4 back left
    {3501.338f, -3067.979f, 134.997f, 3.784f},              //G4 back, right

    {3530.995f, -3053.916f, 134.997f, 3.784f},              //G5 front, left
    {3527.302f, -3049.330f, 134.997f, 3.784f},              //G5 front, right
    {3533.975f, -3051.901f, 134.997f, 3.784f},              //G5 back left
    {3530.338f, -3046.979f, 134.997f, 3.784f},              //G5 back, right

    {3559.995f, -3065.916f, 134.997f, 3.784f},              //G6 front, left
    {3556.302f, -3061.330f, 134.997f, 3.784f},              //G6 front, right
    {3562.975f, -3063.901f, 134.997f, 3.784f},              //G6 back left
    {3559.338f, -3058.979f, 134.997f, 3.784f},              //G6 back, right

    {3591.995f, -3085.916f, 135.664f, 3.784f},              //G7 front, left
    {3588.302f, -3081.330f, 135.664f, 3.784f},              //G7 front, right
    {3594.975f, -3083.901f, 135.664f, 3.784f},              //G7 back left
    {3591.338f, -3078.979f, 135.664f, 3.784f},              //G7 back, right

    {3624.995f, -3091.916f, 134.122f, 3.784f},              //G8 front, left
    {3621.302f, -3087.330f, 134.122f, 3.784f},              //G8 front, right
    {3627.975f, -3089.901f, 134.122f, 3.784f},              //G8 back left
    {3624.338f, -3084.979f, 134.122f, 3.784f}               //G8 back, right
};

struct boss_dathrohan_balnazzarAI : public ScriptedAI
{
    boss_dathrohan_balnazzarAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiCrusadersHammer_Timer;
    uint32 m_uiCrusaderStrike_Timer;
    uint32 m_uiMindBlast_Timer;
    uint32 m_uiHolyStrike_Timer;
    uint32 m_uiShadowShock_Timer;
    uint32 m_uiPsychicScream_Timer;
    uint32 m_uiDeepSleep_Timer;
    uint32 m_uiMindControl_Timer;
    uint32 m_uiTransform_Timer;
    bool m_bTransformed;

    uint64 MCPlayerGuid;
    float MCPlayerAggro;
    uint64 SleepPlayerGuid;
    float SleepPlayerAggro;

    void Reset() override
    {
        m_uiCrusadersHammer_Timer = 8000;
        m_uiCrusaderStrike_Timer = 12000;
        m_uiMindBlast_Timer = 6000;
        m_uiHolyStrike_Timer = 18000;
        m_uiShadowShock_Timer = 3000;
        m_uiPsychicScream_Timer = 12000;
        m_uiDeepSleep_Timer = 9000;
        m_uiMindControl_Timer = 18000;
        m_uiTransform_Timer = 0;
        m_bTransformed = false;

        MCPlayerGuid = 0;
        MCPlayerAggro = 0;
        SleepPlayerGuid = 0;
        SleepPlayerAggro = 0;

        if (m_creature->GetEntry() == NPC_BALNAZZAR)
            m_creature->UpdateEntry(NPC_DATHROHAN);

    }

    void JustDied(Unit* Victim) override
    {
        m_creature->MonsterSay("Damn you mortals! All my plans of revenge, all my hate... all burned to ash...");
        
        static uint32 uiCount = sizeof(m_aSummonPoint) / sizeof(SummonDef);

        for (uint8 i = 0; i < uiCount; ++i)
        {
            switch (urand(0, 1))
            {
                case 0:
                    m_creature->SummonCreature(NPC_SKEL_BERSERKER,
                                               m_aSummonPoint[i].m_fX, m_aSummonPoint[i].m_fY, m_aSummonPoint[i].m_fZ, m_aSummonPoint[i].m_fOrient,
                                               TEMPSUMMON_DEAD_DESPAWN, HOUR * IN_MILLISECONDS);
                    break;
                case 1:
                    m_creature->SummonCreature(NPC_SKEL_GUARDIAN,
                                               m_aSummonPoint[i].m_fX, m_aSummonPoint[i].m_fY, m_aSummonPoint[i].m_fZ, m_aSummonPoint[i].m_fOrient,
                                               TEMPSUMMON_DEAD_DESPAWN, HOUR * IN_MILLISECONDS);
                    break;
            }
        }
    }

    void Aggro(Unit* /*pWho*/) override
    {
        m_creature->MonsterYell("Today you have unmade what took me years to create! For this you shall all die by my hand!");
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //START NOT TRANSFORMED
        if (!m_bTransformed)
        {
            //MindBlast
            if (m_uiMindBlast_Timer < uiDiff)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_MINDBLAST) == CAST_OK)
                    m_uiMindBlast_Timer = urand(15000, 20000);
            }
            else m_uiMindBlast_Timer -= uiDiff;

            //CrusadersHammer
            if (m_uiCrusadersHammer_Timer < uiDiff)
            {
                if (DoCastSpellIfCan(m_creature, SPELL_CRUSADERSHAMMER) == CAST_OK)
                    m_uiCrusadersHammer_Timer = 12000;
            }
            else m_uiCrusadersHammer_Timer -= uiDiff;

            //CrusaderStrike
            if (m_uiCrusaderStrike_Timer < uiDiff)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CRUSADERSTRIKE) == CAST_OK)
                    m_uiCrusaderStrike_Timer = 15000;
            }
            else m_uiCrusaderStrike_Timer -= uiDiff;

            //HolyStrike
            if (m_uiHolyStrike_Timer < uiDiff)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_HOLYSTRIKE) == CAST_OK)
                    m_uiHolyStrike_Timer = 15000;
            }
            else m_uiHolyStrike_Timer -= uiDiff;

            //BalnazzarTransform
            if (m_creature->GetHealthPercent() < 40.0f)
            {
                if (m_creature->IsNonMeleeSpellCasted(false))
                    m_creature->InterruptNonMeleeSpells(false);

                //restore hp, mana and stun
                DoCastSpellIfCan(m_creature, SPELL_BALNAZZARTRANSFORM);
                m_creature->UpdateEntry(NPC_BALNAZZAR);
                m_uiTransform_Timer = 4000;
                m_bTransformed = true;
                return;
            }
        }
        else
        {
            if (m_uiTransform_Timer)
            {
                if (m_uiTransform_Timer <= uiDiff)
                {
                    m_creature->MonsterYell("You fools think you can defeat me so easily? Face the true might of the Nathrezim!");
                    m_uiTransform_Timer = 0;
                }
                else
                {
                    m_uiTransform_Timer -= uiDiff;
                    return;
                }
            }

            if (MCPlayerGuid)
            {
                if (Unit* pTarget = m_creature->GetMap()->GetPlayer(MCPlayerGuid))
                {
                    if (!pTarget->HasAura(SPELL_MINDCONTROL))
                    {
                        m_creature->GetThreatManager().modifyThreatPercent(pTarget, -100);
                        m_creature->GetThreatManager().addThreatDirectly(pTarget, MCPlayerAggro);
                        MCPlayerGuid = 0;
                        MCPlayerAggro = 0;
                    }
                }
            }
            else
            {
                MCPlayerGuid = 0;
                MCPlayerAggro = 0;
            }

            if (SleepPlayerGuid)
            {
                if (Unit* pTarget = m_creature->GetMap()->GetPlayer(SleepPlayerGuid))
                {
                    if (!pTarget->HasAura(SPELL_SLEEP))
                    {
                        m_creature->GetThreatManager().modifyThreatPercent(pTarget, -100);
                        m_creature->GetThreatManager().addThreatDirectly(pTarget, SleepPlayerAggro);
                        SleepPlayerGuid = 0;
                        SleepPlayerAggro = 0;
                    }
                }
            }
            else
            {
                SleepPlayerGuid = 0;
                SleepPlayerAggro = 0;
            }

            //MindBlast
            if (m_uiMindBlast_Timer < uiDiff)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_MINDBLAST) == CAST_OK)
                    m_uiMindBlast_Timer = urand(15000, 20000);
            }
            else m_uiMindBlast_Timer -= uiDiff;

            //ShadowShock
            if (m_uiShadowShock_Timer < uiDiff)
            {
                DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SHADOWSHOCK);
                m_uiShadowShock_Timer = 11000;
            }
            else m_uiShadowShock_Timer -= uiDiff;

            //PsychicScream
            if (m_uiPsychicScream_Timer < uiDiff)
            {
                if (DoCastSpellIfCan(m_creature, SPELL_PSYCHICSCREAM) == CAST_OK)
                    m_uiPsychicScream_Timer = 20000;
            }
            else m_uiPsychicScream_Timer -= uiDiff;

            //DeepSleep
            if (m_uiDeepSleep_Timer < uiDiff)
            {
                if (Unit *pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 1))
                {
                    if (!pTarget->HasAura(SPELL_SLEEP))
                    {
                        SleepPlayerGuid = pTarget->GetGUID();
                        SleepPlayerAggro = m_creature->GetThreatManager().getThreat(pTarget);
                        if (DoCastSpellIfCan(pTarget, SPELL_SLEEP) == CAST_OK)
                        {
                            m_creature->GetThreatManager().modifyThreatPercent(pTarget, -100);
                            m_uiDeepSleep_Timer = 15000;
                        }
                    }
                }
            }
            else m_uiDeepSleep_Timer -= uiDiff;

            //MindControl
            if (m_uiMindControl_Timer < uiDiff)
            {
                if (Unit *pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_TOPAGGRO, 1)) //ATTACKING_TARGET_RANDOM=>ATTACKING_TARGET_TOPAGGRO ,0 => 1 Alita
                {
                    if (pTarget != nullptr && !pTarget->HasAura(SPELL_SLEEP))
                    {
                        MCPlayerGuid = pTarget->GetGUID();
                        MCPlayerAggro = m_creature->GetThreatManager().getThreat(pTarget);
                        if (DoCastSpellIfCan(pTarget, SPELL_MINDCONTROL) == CAST_OK)
                            m_uiMindControl_Timer = urand(25000, 30000);
                    }
                }
            }
            else m_uiMindControl_Timer -= uiDiff;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_dathrohan_balnazzar(Creature* pCreature)
{
    return new boss_dathrohan_balnazzarAI(pCreature);
}

void AddSC_boss_dathrohan_balnazzar()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_dathrohan_balnazzar";
    newscript->GetAI = &GetAI_boss_dathrohan_balnazzar;
    newscript->RegisterSelf();
}
