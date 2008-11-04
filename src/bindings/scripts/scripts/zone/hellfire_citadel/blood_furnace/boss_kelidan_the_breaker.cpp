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
SDName: Boss_Kelidan_The_Breaker
SD%Complete: 60
SDComment: Event with channeleres vs. boss not implemented yet
SDCategory: Hellfire Citadel, Blood Furnace
EndScriptData */

/* ContentData
boss_kelidan_the_breaker
mob_shadowmoon_channeler
EndContentData */

#include "precompiled.h"

#define SAY_WAKE                    -1542000

#define SAY_ADD_AGGRO_1             -1542001
#define SAY_ADD_AGGRO_2             -1542002
#define SAY_ADD_AGGRO_3             -1542003

#define SAY_KILL_1                  -1542004
#define SAY_KILL_2                  -1542005
#define SAY_NOVA                    -1542006
#define SAY_DIE                     -1542007

#define SPELL_CORRUPTION            30938

#define SPELL_FIRE_NOVA             33775
#define H_SPELL_FIRE_NOVA           37371

#define SPELL_SHADOW_BOLT_VOLLEY    17228
#define H_SPELL_SHADOW_BOLT_VOLLEY  40070

#define SPELL_BURNING_NOVA          30940
#define SPELL_VORTEX                37370

struct TRINITY_DLL_DECL boss_kelidan_the_breakerAI : public ScriptedAI
{
    boss_kelidan_the_breakerAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        HeroicMode = m_creature->GetMap()->IsHeroic();
        Reset();
    }

    ScriptedInstance* pInstance;
    bool HeroicMode;

    uint32 ShadowVolley_Timer;
    uint32 BurningNova_Timer;
    uint32 Firenova_Timer;
    uint32 Corruption_Timer;
    bool Firenova;

    void Reset()
    {
        ShadowVolley_Timer = 1000;
        BurningNova_Timer = 15000;
        Corruption_Timer = 5000;
        Firenova = false;
    }

    void Aggro(Unit *who)
    {
        DoScriptText(SAY_WAKE, m_creature);
    }

    void KilledUnit(Unit* victim)
    {
        if (rand()%2)
            return;

        switch(rand()%2)
        {
            case 0: DoScriptText(SAY_KILL_1, m_creature); break;
            case 1: DoScriptText(SAY_KILL_2, m_creature); break;
        }
    }

    void JustDied(Unit* Killer)
    {
        DoScriptText(SAY_DIE, m_creature);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        if (Firenova)
        {
            if (Firenova_Timer < diff)
            {
                DoCast(m_creature,HeroicMode ? H_SPELL_FIRE_NOVA : SPELL_FIRE_NOVA);
                Firenova = false;
                ShadowVolley_Timer = 2000;
            }else Firenova_Timer -=diff;

            return;
        }

        if (ShadowVolley_Timer < diff)
        {
            DoCast(m_creature,HeroicMode ? H_SPELL_SHADOW_BOLT_VOLLEY : SPELL_SHADOW_BOLT_VOLLEY);
            ShadowVolley_Timer = 5000+rand()%8000;
        }else ShadowVolley_Timer -=diff;

        if (Corruption_Timer < diff)
        {
            DoCast(m_creature,SPELL_CORRUPTION);
            Corruption_Timer = 30000+rand()%20000;
        }else Corruption_Timer -=diff;

        if (BurningNova_Timer < diff)
        {
            if (m_creature->IsNonMeleeSpellCasted(false))
                m_creature->InterruptNonMeleeSpells(true);

            DoScriptText(SAY_NOVA, m_creature);

            if (HeroicMode)
                DoCast(m_creature,SPELL_VORTEX);

            DoCast(m_creature,SPELL_BURNING_NOVA);

            BurningNova_Timer = 20000+rand()%8000;
            Firenova_Timer= 5000;
            Firenova = true;
        }else BurningNova_Timer -=diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_kelidan_the_breaker(Creature *_Creature)
{
    return new boss_kelidan_the_breakerAI (_Creature);
}

/*######
## mob_shadowmoon_channeler
######*/

#define SPELL_SHADOW_BOLT       12739
#define H_SPELL_SHADOW_BOLT     15472

#define SPELL_MARK_OF_SHADOW    30937

#define SPELL_CHANNELING        0                           //initial spell channeling boss/each other not known
                                                            //when engaged all channelers must stop, trigger yell (SAY_ADD_AGGRO_*), and engage.

struct TRINITY_DLL_DECL mob_shadowmoon_channelerAI : public ScriptedAI
{
    mob_shadowmoon_channelerAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        HeroicMode = m_creature->GetMap()->IsHeroic();
        Reset();
    }

    ScriptedInstance* pInstance;
    bool HeroicMode;

    uint32 ShadowBolt_Timer;
    uint32 MarkOfShadow_Timer;

    void Reset()
    {
        ShadowBolt_Timer = 1000+rand()%1000;
        MarkOfShadow_Timer = 5000+rand()%2000;
    }

    void Aggro(Unit* who)
    {
        //trigger boss to yell
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        if (MarkOfShadow_Timer < diff)
        {
            if (Unit *target = SelectUnit(SELECT_TARGET_RANDOM, 0))
                DoCast(target,SPELL_MARK_OF_SHADOW);
            MarkOfShadow_Timer = 15000+rand()%5000;
        }else MarkOfShadow_Timer -=diff;

        if (ShadowBolt_Timer < diff)
        {
            DoCast(m_creature->getVictim(),HeroicMode ? H_SPELL_SHADOW_BOLT : SPELL_SHADOW_BOLT);
            ShadowBolt_Timer = 5000+rand()%1000;
        }else ShadowBolt_Timer -=diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_shadowmoon_channeler(Creature *_Creature)
{
    return new mob_shadowmoon_channelerAI (_Creature);
}

void AddSC_boss_kelidan_the_breaker()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_kelidan_the_breaker";
    newscript->GetAI = GetAI_boss_kelidan_the_breaker;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="mob_shadowmoon_channeler";
    newscript->GetAI = GetAI_mob_shadowmoon_channeler;
    m_scripts[nrscripts++] = newscript;
}
