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

#define SAY_AGGRO                   -1309011
#define SAY_FEAST_PANTHER           -1309012
#define SAY_DEATH                   -1309013

#define SPELL_SHADOWWORDPAIN       23952
#define SPELL_GOUGE                24698
#define SPELL_MARK                 24210
#define SPELL_CLEAVE               26350                    //Perhaps not right. Not a red aura...
#define SPELL_PANTHER_TRANSFORM    24190

struct TRINITY_DLL_DECL boss_arlokkAI : public ScriptedAI
{
    boss_arlokkAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = (c->GetInstanceData());
    }

    ScriptedInstance *pInstance;

    uint32 ShadowWordPain_Timer;
    uint32 Gouge_Timer;
    uint32 Mark_Timer;
    uint32 Cleave_Timer;
    uint32 Vanish_Timer;
    uint32 Summon_Timer;
    uint32 Visible_Timer;

    Unit* markedTarget;
    Creature *Panther;
    uint32 Counter;

    bool PhaseTwo;
    bool VanishedOnce;

    void Reset()
    {
        ShadowWordPain_Timer = 8000;
        Gouge_Timer = 14000;
        Mark_Timer = 35000;
        Cleave_Timer = 4000;
        Vanish_Timer = 60000;
        Summon_Timer = 5000;
        Visible_Timer = 6000;

        Counter = 0;

        markedTarget = NULL;
        PhaseTwo = false;
        VanishedOnce = false;

        m_creature->SetUInt32Value(UNIT_FIELD_DISPLAYID,15218);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
    }

    void EnterCombat(Unit *who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
    }

    void JustDied(Unit* Killer)
    {
        DoScriptText(SAY_DEATH, m_creature);
        m_creature->SetUInt32Value(UNIT_FIELD_DISPLAYID,15218);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

        if(pInstance)
            pInstance->SetData(DATA_ARLOKK_DEATH, 0);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if( m_creature->getVictim() && m_creature->isAlive())
        {
            if (!PhaseTwo && ShadowWordPain_Timer < diff)
            {
                DoCast(m_creature->getVictim(),SPELL_SHADOWWORDPAIN);
                ShadowWordPain_Timer = 15000;
            }else ShadowWordPain_Timer -= diff;

            if (!PhaseTwo && Mark_Timer < diff)
            {
                markedTarget = SelectUnit(SELECT_TARGET_RANDOM,0);

                DoCast(markedTarget,SPELL_MARK);
                Mark_Timer = 15000;
            }else Mark_Timer -= diff;

            if (Summon_Timer < diff && Counter < 31)
            {
                Unit* target = NULL;
                target = SelectUnit(SELECT_TARGET_RANDOM,0);

                Panther = m_creature->SummonCreature(15101,-11532.79980,-1649.6734,41.4800,0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);

                if(markedTarget && Panther )
                {
                    DoScriptText(SAY_FEAST_PANTHER, m_creature, markedTarget);
                    Panther ->AI()->AttackStart(markedTarget);
                }else if(Panther && target) Panther ->AI()->AttackStart(target);

                Panther = m_creature->SummonCreature(15101,-11532.9970,-1606.4840,41.2979,0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);

                if(markedTarget && Panther )
                    Panther ->AI()->AttackStart(markedTarget);
                else if(Panther && target)
                     Panther ->AI()->AttackStart(target);

                Counter++;
                Summon_Timer = 5000;
            }else Summon_Timer -= diff;

            if (Vanish_Timer < diff)
            {
                //Invisble Model
                m_creature->SetUInt32Value(UNIT_FIELD_DISPLAYID,11686);
                m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                //m_creature->CombatStop();
                DoResetThreat();
                VanishedOnce = true;
                Vanish_Timer = 45000;
                Visible_Timer = 6000;
            }else Vanish_Timer -= diff;

            if (VanishedOnce)
            {
                if(Visible_Timer < diff)
                {
                    Unit* target = NULL;
                    target = SelectUnit(SELECT_TARGET_RANDOM,0);
                    //The Panther Model
                    m_creature->SetUInt32Value(UNIT_FIELD_DISPLAYID,15215);
                    m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                    const CreatureInfo *cinfo = m_creature->GetCreatureInfo();
                    m_creature->SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, (cinfo->mindmg +((cinfo->mindmg/100) * 35)));
                    m_creature->SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, (cinfo->maxdmg +((cinfo->maxdmg/100) * 35)));
                    m_creature->UpdateDamagePhysical(BASE_ATTACK);
                    if(target)
                        AttackStart(target);
                    //The Panther Model
                    m_creature->SetUInt32Value(UNIT_FIELD_DISPLAYID,15215);
                    m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    PhaseTwo = true;
                }else Visible_Timer -= diff;
            }

            //Cleave_Timer
            if(PhaseTwo && Cleave_Timer < diff)
            {
                DoCast(m_creature->getVictim(), SPELL_CLEAVE);
                Cleave_Timer = 16000;
            }Cleave_Timer -=diff;

            //Gouge_Timer
            if(PhaseTwo && Gouge_Timer < diff)
            {
                DoCast(m_creature->getVictim(), SPELL_GOUGE);
                if(DoGetThreat(m_creature->getVictim()))
                    DoModifyThreatPercent(m_creature->getVictim(),-80);

                Gouge_Timer = 17000+rand()%10000;
            }else Gouge_Timer -= diff;

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
    newscript->Name="boss_arlokk";
    newscript->GetAI = &GetAI_boss_arlokk;
    newscript->RegisterSelf();
}

