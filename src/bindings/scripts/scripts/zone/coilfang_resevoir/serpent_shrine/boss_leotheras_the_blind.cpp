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
SDName: Boss_Leotheras_The_Blind
SD%Complete: 50
SDComment: Missing Inner Demons
SDCategory: Coilfang Resevoir, Serpent Shrine Cavern
EndScriptData */

#include "precompiled.h"
#include "def_serpent_shrine.h"

#define SAY_AGGRO               -1548009
#define SAY_SWITCH_TO_DEMON     -1548010
#define SAY_INNER_DEMONS        -1548011
#define SAY_DEMON_SLAY1         -1548012
#define SAY_DEMON_SLAY2         -1548013
#define SAY_DEMON_SLAY3         -1548014
#define SAY_NIGHTELF_SLAY1      -1548015
#define SAY_NIGHTELF_SLAY2      -1548016
#define SAY_NIGHTELF_SLAY3      -1548017
#define SAY_FINAL_FORM          -1548018
#define SAY_FREE                -1548019
#define SAY_DEATH               -1548020

#define SPELL_WHIRLWIND         40653
#define SPELL_CHAOS_BLAST       37675
//#define SPELL_INSIDIOUS_WHISPER 37676                       // useless - dummy effect that can't be implemented

#define MODEL_DEMON             14555
#define MODEL_NIGHTELF          20514

#define DEMON_FORM              21845

//Original Leotheras the Blind AI
struct TRINITY_DLL_DECL boss_leotheras_the_blindAI : public ScriptedAI
{
    boss_leotheras_the_blindAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Demon = 0;
        Reset();
    }

    ScriptedInstance *pInstance;

    uint32 Whirlwind_Timer;
    uint32 ChaosBlast_Timer;
    uint32 Switch_Timer;

    bool DemonForm;
    bool IsFinalForm;

    uint64 Demon;

    void Reset()
    {
        Whirlwind_Timer = 20000;
        ChaosBlast_Timer = 1000;
        Switch_Timer = 45000;

        DemonForm = false;
        IsFinalForm = false;

        m_creature->SetUInt32Value(UNIT_FIELD_DISPLAYID, MODEL_NIGHTELF);

        if (pInstance)
            pInstance->SetData(DATA_LEOTHERASTHEBLINDEVENT, NOT_STARTED);
    }

    void StartEvent()
    {
        DoScriptText(SAY_AGGRO, m_creature);

        if (pInstance)
            pInstance->SetData(DATA_LEOTHERASTHEBLINDEVENT, IN_PROGRESS);
    }

    void KilledUnit(Unit *victim)
    {
        if (victim->GetTypeId() != TYPEID_PLAYER)
            return;

        if (DemonForm)
        {
            switch(rand()%3)
            {
                case 0: DoScriptText(SAY_DEMON_SLAY1, m_creature); break;
                case 1: DoScriptText(SAY_DEMON_SLAY2, m_creature); break;
                case 2: DoScriptText(SAY_DEMON_SLAY3, m_creature); break;
            }
        }
        else
        {
            switch(rand()%3)
            {
                case 0: DoScriptText(SAY_NIGHTELF_SLAY1, m_creature); break;
                case 1: DoScriptText(SAY_NIGHTELF_SLAY2, m_creature); break;
                case 2: DoScriptText(SAY_NIGHTELF_SLAY3, m_creature); break;
            }
        }
    }

    void JustDied(Unit *victim)
    {
        DoScriptText(SAY_DEATH, m_creature);

        //despawn copy
        if (Demon)
        {
            Unit *pUnit = NULL;
            pUnit = Unit::GetUnit((*m_creature), Demon);

            if (pUnit)
                pUnit->DealDamage(pUnit, pUnit->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
        }

        if (pInstance)
            pInstance->SetData(DATA_LEOTHERASTHEBLINDEVENT, DONE);
    }

    void Aggro(Unit *who)
    {
        StartEvent();
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        if (!DemonForm)
        {
            //Whirlwind_Timer
            if (Whirlwind_Timer < diff)
            {
                DoCast(m_creature, SPELL_WHIRLWIND);
                Whirlwind_Timer = 25000;
            }else Whirlwind_Timer -= diff;

            //Switch_Timer
            if (!IsFinalForm)
            {
                if (Switch_Timer < diff)
                {
                    //switch to demon form
                    m_creature->SetUInt32Value(UNIT_FIELD_DISPLAYID, MODEL_DEMON);
                    DoScriptText(SAY_SWITCH_TO_DEMON, m_creature);
                    DemonForm = true;
                    Switch_Timer = 60000;
                }else Switch_Timer -= diff;
            }

            DoMeleeAttackIfReady();
        }
        else
        {
            //ChaosBlast_Timer
            if (ChaosBlast_Timer < diff)
            {
                DoCast(m_creature->getVictim(), SPELL_CHAOS_BLAST);
                ChaosBlast_Timer = 1500;
            }else ChaosBlast_Timer -= diff;

            //Switch_Timer
            if (Switch_Timer < diff)
            {
                //switch to nightelf form
                m_creature->SetUInt32Value(UNIT_FIELD_DISPLAYID, MODEL_NIGHTELF);
                DemonForm = false;

                Switch_Timer = 45000;
            }else Switch_Timer -= diff;
        }

        if (!IsFinalForm && (m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 15)
        {
            //at this point he divides himself in two parts
            Creature *Copy = NULL;
            Copy = DoSpawnCreature(DEMON_FORM, 0, 0, 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);

            if (Copy)
            {
                Demon = Copy->GetGUID();
                Copy->AI()->AttackStart(m_creature->getVictim());
            }

            //set nightelf final form
            IsFinalForm = true;
            DemonForm = false;

            DoScriptText(SAY_FINAL_FORM, m_creature);
            m_creature->SetUInt32Value(UNIT_FIELD_DISPLAYID, MODEL_NIGHTELF);
        }
    }
};

//Leotheras the Blind Demon Form AI
struct TRINITY_DLL_DECL boss_leotheras_the_blind_demonformAI : public ScriptedAI
{
    boss_leotheras_the_blind_demonformAI(Creature *c) : ScriptedAI(c)
    {
        Reset();
    }

    uint32 ChaosBlast_Timer;

    void Reset()
    {
        ChaosBlast_Timer = 1000;
    }

    void StartEvent()
    {
        DoScriptText(SAY_FREE, m_creature);
    }

    void KilledUnit(Unit *victim)
    {
        if (victim->GetTypeId() != TYPEID_PLAYER)
            return;

        switch(rand()%3)
        {
            case 0: DoScriptText(SAY_DEMON_SLAY1, m_creature); break;
            case 1: DoScriptText(SAY_DEMON_SLAY2, m_creature); break;
            case 2: DoScriptText(SAY_DEMON_SLAY3, m_creature); break;
        }
    }

    void JustDied(Unit *victim)
    {
        //invisibility (blizzlike, at the end of the fight he doesn't die, he disappears)
        m_creature->CastSpell(m_creature, 8149, true);
    }

    void Aggro(Unit *who)
    {
        StartEvent();
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        //ChaosBlast_Timer
        if (ChaosBlast_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_CHAOS_BLAST);
            ChaosBlast_Timer = 1500;
        }else ChaosBlast_Timer -= diff;

        //Do NOT deal any melee damage to the target.
    }
};

CreatureAI* GetAI_boss_leotheras_the_blind(Creature *_Creature)
{
    return new boss_leotheras_the_blindAI (_Creature);
}

CreatureAI* GetAI_boss_leotheras_the_blind_demonform(Creature *_Creature)
{
    return new boss_leotheras_the_blind_demonformAI (_Creature);
}

void AddSC_boss_leotheras_the_blind()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_leotheras_the_blind";
    newscript->GetAI = GetAI_boss_leotheras_the_blind;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="boss_leotheras_the_blind_demonform";
    newscript->GetAI = GetAI_boss_leotheras_the_blind_demonform;
    m_scripts[nrscripts++] = newscript;
}
