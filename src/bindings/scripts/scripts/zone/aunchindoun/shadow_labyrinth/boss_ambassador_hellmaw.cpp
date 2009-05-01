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
SDName: Boss_Ambassador_Hellmaw
SD%Complete: 75
SDComment: Waypoints after Intro not implemented. Enrage spell missing/not known
SDCategory: Auchindoun, Shadow Labyrinth
EndScriptData */

#include "precompiled.h"
#include "def_shadow_labyrinth.h"

#define SAY_INTRO       -1555000

#define SAY_AGGRO1      -1555001
#define SAY_AGGRO2      -1555002
#define SAY_AGGRO3      -1555003

#define SAY_HELP        -1555004

#define SAY_SLAY1       -1555005
#define SAY_SLAY2       -1555006

#define SAY_DEATH       -1555007

#define SPELL_BANISH            30231
#define SPELL_CORROSIVE_ACID    33551
#define SPELL_FEAR              33547
#define SPELL_ENRAGE            0                           //need to find proper spell

struct TRINITY_DLL_DECL boss_ambassador_hellmawAI : public ScriptedAI
{
    boss_ambassador_hellmawAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        HeroicMode = m_creature->GetMap()->IsHeroic();
    }

    ScriptedInstance* pInstance;
    bool HeroicMode;

    uint32 EventCheck_Timer;
    uint32 CorrosiveAcid_Timer;
    uint32 Fear_Timer;
    uint32 Enrage_Timer;
    bool Intro;
    bool IsBanished;

    void Reset()
    {
        EventCheck_Timer = 5000;
        CorrosiveAcid_Timer = 25000;
        Fear_Timer = 40000;
        Enrage_Timer = 180000;
        Intro = false;
        IsBanished = false;

        if (pInstance)
        {
            if (pInstance->GetData(TYPE_HELLMAW) == NOT_STARTED)
            {
                DoCast(m_creature,SPELL_BANISH);
                IsBanished = true;
            }
            else pInstance->SetData(TYPE_HELLMAW,FAIL);
            if (pInstance->GetData(TYPE_OVERSEER) == DONE)
            {
                if (m_creature->HasAura(SPELL_BANISH))
                    m_creature->RemoveAurasDueToSpell(SPELL_BANISH);
                Intro = true;
            }
        }
    }

    void MoveInLineOfSight(Unit *who)
    {
        if (m_creature->HasAura(SPELL_BANISH))
            return;

        ScriptedAI::MoveInLineOfSight(who);
    }

    void MovementInform(uint32 type, uint32 id)
    {
        if (type != POINT_MOTION_TYPE)
            return;
    }

    void DoIntro()
    {
        DoScriptText(SAY_INTRO, m_creature);

        if (m_creature->HasAura(SPELL_BANISH))
            m_creature->RemoveAurasDueToSpell(SPELL_BANISH);

        IsBanished = false;
        Intro = true;

        if (pInstance)
            pInstance->SetData(TYPE_HELLMAW, IN_PROGRESS);
    }

    void EnterCombat(Unit *who)
    {
        switch(rand()%3)
        {
            case 0: DoScriptText(SAY_AGGRO1, m_creature); break;
            case 1: DoScriptText(SAY_AGGRO2, m_creature); break;
            case 2: DoScriptText(SAY_AGGRO3, m_creature); break;
        }
    }

    void KilledUnit(Unit *victim)
    {
        switch(rand()%2)
        {
            case 0: DoScriptText(SAY_SLAY1, m_creature); break;
            case 1: DoScriptText(SAY_SLAY2, m_creature); break;
        }
    }

    void JustDied(Unit *victim)
    {
        DoScriptText(SAY_DEATH, m_creature);

        if (pInstance)
            pInstance->SetData(TYPE_HELLMAW, DONE);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!Intro)
        {
            if (EventCheck_Timer < diff)
            {
                if(pInstance)
                {
                    if (pInstance->GetData(TYPE_OVERSEER) == DONE)
                        DoIntro();
                }
                EventCheck_Timer = 5000;
            }else EventCheck_Timer -= diff;
        }

        if (!m_creature->isInCombat() && !IsBanished)
        {
            //this is where we add MovePoint()
            //DoWhine("I haz no mount!", LANG_UNIVERSAL, NULL);
        }

        if (!UpdateVictim() )
            return;

        if(m_creature->HasAura(SPELL_BANISH, 0))
        {
            EnterEvadeMode();
            return;
        }

        if (CorrosiveAcid_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_CORROSIVE_ACID);
            CorrosiveAcid_Timer = 15000 + rand()%10000;
        }else CorrosiveAcid_Timer -= diff;

        if (Fear_Timer < diff)
        {
            DoCast(m_creature,SPELL_FEAR);
            Fear_Timer = 20000 + rand()%15000;
        }else Fear_Timer -= diff;

        /*if (HeroicMode)
        {
            if (Enrage_Timer < diff)
            {
                DoCast(m_creature,SPELL_ENRAGE);
            }else Enrage_Timer -= diff;
        }*/

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_ambassador_hellmaw(Creature *_Creature)
{
    return new boss_ambassador_hellmawAI (_Creature);
}

void AddSC_boss_ambassador_hellmaw()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_ambassador_hellmaw";
    newscript->GetAI = &GetAI_boss_ambassador_hellmaw;
    newscript->RegisterSelf();
}

