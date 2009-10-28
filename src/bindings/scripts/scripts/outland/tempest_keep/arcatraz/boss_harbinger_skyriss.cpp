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
SDName: Boss_Harbinger_Skyriss
SD%Complete: 45
SDComment: CombatAI not fully implemented. Timers will need adjustments. Need more docs on how event fully work. Reset all event and force start over if fail at one point?
SDCategory: Tempest Keep, The Arcatraz
EndScriptData */

/* ContentData
boss_harbinger_skyriss
boss_harbinger_skyriss_illusion
EndContentData */

#include "precompiled.h"
#include "arcatraz.h"

#define SAY_INTRO               -1552000
#define SAY_AGGRO               -1552001
#define SAY_KILL_1              -1552002
#define SAY_KILL_2              -1552003
#define SAY_MIND_1              -1552004
#define SAY_MIND_2              -1552005
#define SAY_FEAR_1              -1552006
#define SAY_FEAR_2              -1552007
#define SAY_IMAGE               -1552008
#define SAY_DEATH               -1552009

#define SPELL_FEAR              39415

#define SPELL_MIND_REND         36924
#define H_SPELL_MIND_REND       39017

#define SPELL_DOMINATION        37162
#define H_SPELL_DOMINATION      39019

#define H_SPELL_MANA_BURN       39020

#define SPELL_66_ILLUSION       36931                       //entry 21466
#define SPELL_33_ILLUSION       36932                       //entry 21467

struct TRINITY_DLL_DECL boss_harbinger_skyrissAI : public ScriptedAI
{
    boss_harbinger_skyrissAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
        HeroicMode = c->GetMap()->IsHeroic();
        Intro = false;
    }

    ScriptedInstance *pInstance;
    bool HeroicMode;

    bool Intro;
    bool IsImage33;
    bool IsImage66;

    uint32 Intro_Phase;
    uint32 Intro_Timer;
    uint32 MindRend_Timer;
    uint32 Fear_Timer;
    uint32 Domination_Timer;
    uint32 ManaBurn_Timer;

    void Reset()
    {
        if (!Intro)
            m_creature->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_OOC_NOT_ATTACKABLE);

        IsImage33 = false;
        IsImage66 = false;

        Intro_Phase = 1;
        Intro_Timer = 5000;
        MindRend_Timer = 3000;
        Fear_Timer = 15000;
        Domination_Timer = 30000;
        ManaBurn_Timer = 25000;
    }

    void MoveInLineOfSight(Unit *who)
    {
        if (!Intro)
        {
            return;
        }
        ScriptedAI::MoveInLineOfSight(who);
    }

    void EnterCombat(Unit *who) {}

    void JustDied(Unit* Killer)
    {
        DoScriptText(SAY_DEATH, m_creature);
        if (pInstance)
            pInstance->SetData(TYPE_HARBINGERSKYRISS,DONE);
    }

    void JustSummoned(Creature *summon)
    {
        if (!summon)
            return;
        if (IsImage66)
            summon->SetHealth((summon->GetMaxHealth()*33)/100);
        else
            summon->SetHealth((summon->GetMaxHealth()*66)/100);
        if (m_creature->getVictim())
            if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                summon->AI()->AttackStart(pTarget);
     }

    void KilledUnit(Unit* victim)
    {
        //won't yell killing pet/other unit
        if (victim->GetEntry() == 21436)
            return;

        DoScriptText(RAND(SAY_KILL_1,SAY_KILL_2), m_creature);
    }

    void DoSplit(uint32 val)
    {
        if (m_creature->IsNonMeleeSpellCasted(false))
            m_creature->InterruptNonMeleeSpells(false);

        DoScriptText(SAY_IMAGE, m_creature);

        if (val == 66)
            DoCast(m_creature, SPELL_66_ILLUSION);
        else
            DoCast(m_creature, SPELL_33_ILLUSION);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!Intro)
        {
            if (!pInstance)
                return;

            if (Intro_Timer <= diff)
            {
                switch(Intro_Phase)
                {
                    case 1:
                        DoScriptText(SAY_INTRO, m_creature);
                        pInstance->HandleGameObject(pInstance->GetData64(DATA_SPHERE_SHIELD), true);
                        ++Intro_Phase;
                        Intro_Timer = 25000;
                        break;
                    case 2:
                        DoScriptText(SAY_AGGRO, m_creature);
                        if (Unit *mellic = Unit::GetUnit(*m_creature,pInstance->GetData64(DATA_MELLICHAR)))
                        {
                            //should have a better way to do this. possibly spell exist.
                            mellic->setDeathState(JUST_DIED);
                            mellic->SetHealth(0);
                            pInstance->SetData(TYPE_SHIELD_OPEN,IN_PROGRESS);
                        }
                        ++Intro_Phase;
                        Intro_Timer = 3000;
                        break;
                    case 3:
                        m_creature->RemoveFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_OOC_NOT_ATTACKABLE);
                        Intro = true;
                        break;
                }
            } else Intro_Timer -=diff;
        }

        if (!UpdateVictim())
            return;

        if (!IsImage66 && ((m_creature->GetHealth()*100) / m_creature->GetMaxHealth() <= 66))
        {
            DoSplit(66);
            IsImage66 = true;
        }
        if (!IsImage33 && ((m_creature->GetHealth()*100) / m_creature->GetMaxHealth() <= 33))
        {
            DoSplit(33);
            IsImage33 = true;
        }

        if (MindRend_Timer <= diff)
        {
            if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM,1))
                DoCast(pTarget,HEROIC(SPELL_MIND_REND, H_SPELL_MIND_REND));
            else
                DoCast(m_creature->getVictim(),HEROIC(SPELL_MIND_REND, H_SPELL_MIND_REND));

            MindRend_Timer = 8000;
        } else MindRend_Timer -=diff;

        if (Fear_Timer <= diff)
        {
            if (m_creature->IsNonMeleeSpellCasted(false))
                return;

            DoScriptText(RAND(SAY_FEAR_1,SAY_FEAR_2), m_creature);

            if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM,1))
                DoCast(pTarget,SPELL_FEAR);
            else
                DoCast(m_creature->getVictim(),SPELL_FEAR);

            Fear_Timer = 25000;
        } else Fear_Timer -=diff;

        if (Domination_Timer <= diff)
        {
            if (m_creature->IsNonMeleeSpellCasted(false))
                return;

            DoScriptText(RAND(SAY_MIND_1,SAY_MIND_2), m_creature);

            if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM,1))
                DoCast(pTarget,HEROIC(SPELL_DOMINATION, H_SPELL_DOMINATION));
            else
                DoCast(m_creature->getVictim(),HEROIC(SPELL_DOMINATION, H_SPELL_DOMINATION));

            Domination_Timer = 16000+rand()%16000;
        } else Domination_Timer -=diff;

        if (HeroicMode)
        {
            if (ManaBurn_Timer <= diff)
            {
                if (m_creature->IsNonMeleeSpellCasted(false))
                    return;

                if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM,1))
                    DoCast(pTarget,H_SPELL_MANA_BURN);

                ManaBurn_Timer = 16000+rand()%16000;
            } else ManaBurn_Timer -=diff;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_harbinger_skyriss(Creature* pCreature)
{
    return new boss_harbinger_skyrissAI (pCreature);
}

#define SPELL_MIND_REND_IMAGE   36929
#define H_SPELL_MIND_REND_IMAGE 39021

struct TRINITY_DLL_DECL boss_harbinger_skyriss_illusionAI : public ScriptedAI
{
    boss_harbinger_skyriss_illusionAI(Creature *c) : ScriptedAI(c)
    {
        HeroicMode = c->GetMap()->IsHeroic();
    }

    bool HeroicMode;

    void Reset() { }

    void EnterCombat(Unit *who) { }
};

CreatureAI* GetAI_boss_harbinger_skyriss_illusion(Creature* pCreature)
{
    return new boss_harbinger_skyriss_illusionAI (pCreature);
}

void AddSC_boss_harbinger_skyriss()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_harbinger_skyriss";
    newscript->GetAI = &GetAI_boss_harbinger_skyriss;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_harbinger_skyriss_illusion";
    newscript->GetAI = &GetAI_boss_harbinger_skyriss_illusion;
    newscript->RegisterSelf();
}

