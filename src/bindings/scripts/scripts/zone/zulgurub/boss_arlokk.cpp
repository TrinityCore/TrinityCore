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
SDName: Boss_Arlokk
SD%Complete: 95
SDComment: Wrong cleave and red aura is missing.
SDCategory: Zul'Gurub
EndScriptData */

#include "precompiled.h"
#include "def_zulgurub.h"

bool GOHello_go_gong_of_bethekk(Player* pPlayer, GameObject* pGo)
{
    if (ScriptedInstance* m_pInstance = (ScriptedInstance*)pGo->GetInstanceData())
    {
        if (m_pInstance->GetData(TYPE_ARLOKK) == DONE || m_pInstance->GetData(TYPE_ARLOKK) == IN_PROGRESS)
            return true;

        m_pInstance->SetData(TYPE_ARLOKK, IN_PROGRESS);
    }

    return false;
}

enum
{
    SAY_AGGRO                   = -1309011,
    SAY_FEAST_PANTHER           = -1309012,
    SAY_DEATH                   = -1309013,

    SPELL_SHADOWWORDPAIN        = 23952,
    SPELL_GOUGE                 = 24698,
    SPELL_MARK                  = 24210,
    SPELL_CLEAVE                = 26350,                    //Perhaps not right. Not a red aura...
    SPELL_PANTHER_TRANSFORM     = 24190,

    MODEL_ID_NORMAL             = 15218,
    MODEL_ID_PANTHER            = 15215,
    MODEL_ID_BLANK              = 11686,

    NPC_ZULIAN_PROWLER          = 15101
};

struct TRINITY_DLL_DECL boss_arlokkAI : public ScriptedAI
{
    boss_arlokkAI(Creature *c) : ScriptedAI(c)
    {
        m_pInstance = c->GetInstanceData();
    }

    ScriptedInstance *m_pInstance;

    uint32 m_uiShadowWordPain_Timer;
    uint32 m_uiGouge_Timer;
    uint32 m_uiMark_Timer;
    uint32 m_uiCleave_Timer;
    uint32 m_uiVanish_Timer;
    uint32 m_uiSummon_Timer;
    uint32 m_uiVisible_Timer;

    uint64 markedTargetGUID;
    uint32 Counter;

    bool m_bPhaseTwo;
    bool m_bVanishedOnce;

    void Reset()
    {
        m_uiShadowWordPain_Timer = 8000;
        m_uiGouge_Timer = 14000;
        m_uiMark_Timer = 35000;
        m_uiCleave_Timer = 4000;
        m_uiVanish_Timer = 60000;
        m_uiSummon_Timer = 5000;
        m_uiVisible_Timer = 6000;

        Counter = 0;

        markedTargetGUID = 0;
        m_bPhaseTwo = false;
        m_bVanishedOnce = false;

        m_creature->SetDisplayId(MODEL_ID_NORMAL);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
    }

    void EnterCombat(Unit* pWho)
    {
        DoScriptText(SAY_AGGRO, m_creature);
    }

    void JustDied(Unit* pKiller)
    {
        DoScriptText(SAY_DEATH, m_creature);
        m_creature->SetDisplayId(MODEL_ID_NORMAL);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

        if(m_pInstance)
            m_pInstance->SetData(TYPE_ARLOKK, DONE);
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (!UpdateVictim())
            return;

        if( m_creature->getVictim() && m_creature->isAlive())
        {
            if (!m_bPhaseTwo && m_uiShadowWordPain_Timer < uiDiff)
            {
                DoCast(m_creature->getVictim(),SPELL_SHADOWWORDPAIN);
                m_uiShadowWordPain_Timer = 15000;
            }
            else
                m_uiShadowWordPain_Timer -= uiDiff;

            if (!m_bPhaseTwo && m_uiMark_Timer < uiDiff)
            {
                if(Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                {
                    DoCast(target, SPELL_MARK);
                    markedTargetGUID = target->GetGUID();
                }
                m_uiMark_Timer = 15000;
            }
            else
                m_uiMark_Timer -= uiDiff;

            if (m_uiSummon_Timer < uiDiff && Counter < 31)
            {
                Unit* target = SelectUnit(SELECT_TARGET_RANDOM,0);

                Creature *Panther = m_creature->SummonCreature(15101,-11532.79980,-1649.6734,41.4800,0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
                Player *markedTarget = Unit::GetPlayer(markedTargetGUID);

                if(markedTarget && Panther )
                {
                    DoScriptText(SAY_FEAST_PANTHER, m_creature, markedTarget);
                    Panther ->AI()->AttackStart(markedTarget);
                }
                else if(Panther && target)
                    Panther ->AI()->AttackStart(target);

                Panther = m_creature->SummonCreature(15101,-11532.9970,-1606.4840,41.2979,0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);

                if(markedTarget && Panther )
                    Panther ->AI()->AttackStart(markedTarget);
                else if(Panther && target)
                     Panther ->AI()->AttackStart(target);

                Counter++;
                m_uiSummon_Timer = 5000;
            }
            else
                m_uiSummon_Timer -= uiDiff;

            if (m_uiVanish_Timer < uiDiff)
            {
                //Invisble Model
                m_creature->SetDisplayId(MODEL_ID_BLANK);
                m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                //m_creature->CombatStop();
                DoResetThreat();
                m_bVanishedOnce = true;
                m_uiVanish_Timer = 45000;
                m_uiVisible_Timer = 6000;
            }
            else
                m_uiVanish_Timer -= uiDiff;

            if (m_bVanishedOnce)
            {
                if(m_uiVisible_Timer < uiDiff)
                {
                    //The Panther Model
                    m_creature->SetDisplayId(MODEL_ID_PANTHER);
                    m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                    const CreatureInfo *cinfo = m_creature->GetCreatureInfo();
                    m_creature->SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, (cinfo->mindmg +((cinfo->mindmg/100) * 35)));
                    m_creature->SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, (cinfo->maxdmg +((cinfo->maxdmg/100) * 35)));
                    m_creature->UpdateDamagePhysical(BASE_ATTACK);

                    if(Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM,0))
                        AttackStart(pTarget);

                    m_bPhaseTwo = true;
                }
                else
                    m_uiVisible_Timer -= uiDiff;
            }

            //Cleave_Timer
            if(m_bPhaseTwo && m_uiCleave_Timer < uiDiff)
            {
                DoCast(m_creature->getVictim(), SPELL_CLEAVE);
                m_uiCleave_Timer = 16000;
            }
            else
                m_uiCleave_Timer -=uiDiff;

            //Gouge_Timer
            if(m_bPhaseTwo && m_uiGouge_Timer < uiDiff)
            {
                DoCast(m_creature->getVictim(), SPELL_GOUGE);

                if(DoGetThreat(m_creature->getVictim()))
                    DoModifyThreatPercent(m_creature->getVictim(),-80);

                m_uiGouge_Timer = 17000+rand()%10000;
            }
            else
                m_uiGouge_Timer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    }
};

CreatureAI* GetAI_boss_arlokk(Creature *_Creature)
{
    return new boss_arlokkAI (_Creature);
}

void AddSC_boss_arlokk()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "go_gong_of_bethekk";
    newscript->pGOHello = &GOHello_go_gong_of_bethekk;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="boss_arlokk";
    newscript->GetAI = &GetAI_boss_arlokk;
    newscript->RegisterSelf();
}

