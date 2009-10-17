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
SD%Complete: 80
SDComment: Enrage spell missing/not known
SDCategory: Auchindoun, Shadow Labyrinth
EndScriptData */

#include "precompiled.h"
#include "escort_ai.h"
#include "def_shadow_labyrinth.h"

enum
{
    SAY_INTRO       = -1555000,
    SAY_AGGRO1      = -1555001,
    SAY_AGGRO2      = -1555002,
    SAY_AGGRO3      = -1555003,
    SAY_HELP        = -1555004,
    SAY_SLAY1       = -1555005,
    SAY_SLAY2       = -1555006,
    SAY_DEATH       = -1555007,

    SPELL_BANISH            = 30231,
    SPELL_CORROSIVE_ACID    = 33551,
    SPELL_FEAR              = 33547,
    SPELL_ENRAGE            = 34970
};

struct TRINITY_DLL_DECL boss_ambassador_hellmawAI : public npc_escortAI
{
    boss_ambassador_hellmawAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        m_pInstance = pCreature->GetInstanceData();
        HeroicMode = pCreature->GetMap()->IsHeroic();
    }

    ScriptedInstance* m_pInstance;
    bool HeroicMode;

    uint32 EventCheck_Timer;
    uint32 CorrosiveAcid_Timer;
    uint32 Fear_Timer;
    uint32 Enrage_Timer;
    bool Intro;
    bool IsBanished;
    bool Enraged;

    void Reset()
    {
        EventCheck_Timer = 5000;
        CorrosiveAcid_Timer = 5000 + rand()%5000;
        Fear_Timer = 25000 + rand()%5000;
        Enrage_Timer = 180000;
        Intro = false;
        IsBanished = true;
        Enraged = false;

        if (m_pInstance && m_creature->isAlive())
        {
            if (m_pInstance->GetData(TYPE_OVERSEER) != DONE)
                m_creature->CastSpell(m_creature, SPELL_BANISH, true);
        }
    }

    void JustReachedHome()
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_HELLMAW, FAIL);
    }

    void MoveInLineOfSight(Unit* pWho)
    {
        if (m_creature->HasAura(SPELL_BANISH))
            return;

        npc_escortAI::MoveInLineOfSight(pWho);
    }

    void WaypointReached(uint32 i)
    {
    }

    void DoIntro()
    {
        if (m_creature->HasAura(SPELL_BANISH))
            m_creature->RemoveAurasDueToSpell(SPELL_BANISH);

        IsBanished = false;
        Intro = true;

        if (m_pInstance)
        {
            if (m_pInstance->GetData(TYPE_HELLMAW) != FAIL)
            {
                DoScriptText(SAY_INTRO, m_creature);
                Start(true, false, 0, NULL, false, true);
            }

            m_pInstance->SetData(TYPE_HELLMAW, IN_PROGRESS);
        }
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

        if (m_pInstance)
            m_pInstance->SetData(TYPE_HELLMAW, DONE);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!Intro && !HasEscortState(STATE_ESCORT_ESCORTING))
        {
            if (EventCheck_Timer < diff)
            {
                if (m_pInstance)
                {
                    if (m_pInstance->GetData(TYPE_OVERSEER) == DONE)
                    {
                        DoIntro();
                        return;
                    }
                }
                EventCheck_Timer = 5000;
                return;
            }
            else
            {
                EventCheck_Timer -= diff;
                return;
            }
        }

        npc_escortAI::UpdateAI(diff);

        if (!UpdateVictim())
            return;

        if (m_creature->HasAura(SPELL_BANISH, 0))
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

        if (HeroicMode)
        {
            if (!Enraged && Enrage_Timer < diff)
            {
                DoCast(m_creature,SPELL_ENRAGE);
                Enraged = true;
            }else Enrage_Timer -= diff;
        }
    }
};

CreatureAI* GetAI_boss_ambassador_hellmaw(Creature* pCreature)
{
    return new boss_ambassador_hellmawAI(pCreature);
}

void AddSC_boss_ambassador_hellmaw()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_ambassador_hellmaw";
    newscript->GetAI = &GetAI_boss_ambassador_hellmaw;
    newscript->RegisterSelf();
}

