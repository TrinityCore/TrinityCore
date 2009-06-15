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
SDName: Boss_Keristrasza
SD%Complete: 
SDComment: 
SDCategory: The Nexus, The Nexus
EndScriptData */

#include "precompiled.h"
#include "def_nexus.h"

//Spells
#define SPELL_FROZEN_PRISON                             47854
#define SPELL_TAIL_SWEEP                                50155
#define SPELL_CRYSTAL_CHAINS                            50997 
#define SPELL_ENRAGE                                    8599
#define SPELL_CRYSTALFIRE_BREATH_N                      48096
#define SPELL_CRYSTALFIRE_BREATH_H                      57091
#define SPELL_CRYSTALIZE                                48179 
#define SPELL_INTENSE_COLD                              48094

//Yell
#define SAY_AGGRO                                    -1576040
#define SAY_SLAY                                     -1576041
#define SAY_ENRAGE                                   -1576042
#define SAY_DEATH                                    -1576043
#define SAY_CRYSTAL_NOVA                             -1576044

struct TRINITY_DLL_DECL boss_keristraszaAI : public ScriptedAI
{
    boss_keristraszaAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
        HeroicMode = m_creature->GetMap()->IsHeroic();
        Reset();
    }

    ScriptedInstance* pInstance;
    bool HeroicMode;

    uint32 CRYSTALFIRE_BREATH_Timer;
    uint32 CRYSTAL_CHAINS_CRYSTALIZE_Timer;
    uint32 TAIL_SWEEP_Timer;
    bool Enrage;

    void Reset() 
    {
        CRYSTALFIRE_BREATH_Timer = 14000;
        CRYSTAL_CHAINS_CRYSTALIZE_Timer = HeroicMode ? 30000 : 11000;
        TAIL_SWEEP_Timer = 5000;
        Enrage = false;
        m_creature->RemoveAurasDueToSpell(SPELL_INTENSE_COLD);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
        if (pInstance && pInstance->GetData(DATA_KERISTRASZA_FREED) == DONE)
        {
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        }else{
            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);
            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            m_creature->CastSpell(m_creature, SPELL_FROZEN_PRISON, false);
        }
    }

    void MoveInLineOfSight(Unit *who)
    {
        if (pInstance && pInstance->GetData(DATA_KERISTRASZA_FREED) != DONE && pInstance->GetData(DATA_MAGUS_TELESTRA_EVENT) == DONE &&
            pInstance->GetData(DATA_ANOMALUS_EVENT) == DONE && pInstance->GetData(DATA_ORMOROK_EVENT) == DONE &&
            m_creature->IsHostileTo(who) && m_creature->IsWithinDist(who, 15.0f, false))
        {
            pInstance->SetData(DATA_KERISTRASZA_FREED, DONE);
        }
        if (pInstance->GetData(DATA_KERISTRASZA_FREED) == DONE)
        {
            m_creature->RemoveAurasDueToSpell(SPELL_FROZEN_PRISON);
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            ScriptedAI::MoveInLineOfSight(who);
        }
    }

    void Aggro(Unit* who) 
    {
        DoScriptText(SAY_AGGRO, m_creature);
        DoCast(m_creature, SPELL_INTENSE_COLD);
    }

    void UpdateAI(const uint32 diff) 
    {
        if (!UpdateVictim())
        {
            return;
        }
          
        if (!Enrage && (m_creature->GetHealth() < m_creature->GetMaxHealth() * 0.25))
        {
            DoScriptText(SAY_ENRAGE , m_creature);
            DoCast(m_creature, SPELL_ENRAGE);
            Enrage = true;
        }

        if (CRYSTALFIRE_BREATH_Timer < diff)
        {
            DoCast(m_creature->getVictim(), HeroicMode ? SPELL_CRYSTALFIRE_BREATH_H : SPELL_CRYSTALFIRE_BREATH_N);
            CRYSTALFIRE_BREATH_Timer = 14000;
        }else CRYSTALFIRE_BREATH_Timer -=diff;

        if (TAIL_SWEEP_Timer < diff)
        {
            DoCast(m_creature, SPELL_TAIL_SWEEP);
            TAIL_SWEEP_Timer = 5000;
        }else TAIL_SWEEP_Timer -=diff;

        if (CRYSTAL_CHAINS_CRYSTALIZE_Timer < diff)
        {
            DoScriptText(SAY_CRYSTAL_NOVA , m_creature);
            if (HeroicMode)
                DoCast(m_creature, SPELL_CRYSTALIZE);
            else
                if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_CRYSTAL_CHAINS);
            CRYSTAL_CHAINS_CRYSTALIZE_Timer = HeroicMode ? 30000 : 11000;
        }else CRYSTAL_CHAINS_CRYSTALIZE_Timer -= diff;

        DoMeleeAttackIfReady();    
    }

    void JustDied(Unit* killer)  
    {
        DoScriptText(SAY_DEATH, m_creature);
    }

    void KilledUnit(Unit *victim)
    {
        DoScriptText(SAY_SLAY, m_creature);
    }
};

CreatureAI* GetAI_boss_keristrasza(Creature *_Creature)
{
    return new boss_keristraszaAI (_Creature);
}

void AddSC_boss_keristrasza()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_keristrasza";
    newscript->GetAI = &GetAI_boss_keristrasza;
    newscript->RegisterSelf();
}
