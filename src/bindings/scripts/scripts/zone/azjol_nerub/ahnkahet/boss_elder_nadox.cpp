/*
 * Copyright (C) 2009 Trinity <http://www.trinitycore.org/>
 *
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
SDName: boss_elder_nadox
SD%Complete: 100
SDComment:
SDCategory: Ahn'kahet
EndScriptData */

#include "precompiled.h"
#include "def_ahnkahet.h"

#define SAY_AGGRO                              -1619014
#define SAY_SLAY_1                             -1619015
#define SAY_SLAY_2                             -1619016
#define SAY_SLAY_3                             -1619017
#define SAY_DEATH                              -1619018
#define SAY_EGG_SAC_1                          -1619019
#define SAY_EGG_SAC_2                          -1619020

#define SPELL_BROOD_PLAGUE                  56130
#define H_SPELL_BROOD_PLAGUE                59467
#define H_SPELL_BROOD_RAGE                  59465
#define SPELL_ENRAGE                        26662// Enraged if too far away from home

#define MOB_AHNKAHAR_SWARMER                30178
#define SPELL_SUMMON_SWARMERS               56119//2x 30178  -- 2x every 10secs

#define MOB_AHNKAHAR_SWARM_GUARD            30176
#define SPELL_SUMMON_SWARM_GUARD            56120//1x 30176  -- every 25secs
#define SPELL_GUARDIAN_AURA                 56151

struct TRINITY_DLL_DECL boss_elder_nadoxAI : public ScriptedAI
{
    boss_elder_nadoxAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
        HeroicMode = c->GetMap()->IsHeroic();
    }

    bool HeroicMode;
    uint32 plague_Timer;
    uint32 rage_Timer;

    uint32 swarmer_spawn_Timer;
    uint32 guard_spawn_Timer;
    uint32 enrage_Timer;


    ScriptedInstance *pInstance;

    void Reset()
    {
        plague_Timer = 13000;
        rage_Timer = 20000;

        swarmer_spawn_Timer = 10000;
        guard_spawn_Timer = 25000;

        enrage_Timer = 5000;

        if(pInstance)
            pInstance->SetData(DATA_ELDER_NADOX_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit *who)
    {
        DoScriptText(SAY_DEATH,m_creature);

        if(pInstance)
            pInstance->SetData(DATA_ELDER_NADOX_EVENT, IN_PROGRESS);
    }

    void KilledUnit(Unit *victim)
    {
        if(victim == m_creature)
            return;
        switch(rand()%3)
        {
        case 0: DoScriptText(SAY_SLAY_1,m_creature); break;
        case 1: DoScriptText(SAY_SLAY_2,m_creature); break;
        case 2: DoScriptText(SAY_SLAY_3,m_creature); break;
        }
    }

    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_SLAY_3,m_creature);

        if(pInstance)
            pInstance->SetData(DATA_ELDER_NADOX_EVENT, DONE);
    }

    void UpdateAI(const uint32 diff)
    {
        if(!UpdateVictim())
            return;

        if(plague_Timer < diff)
        {
            DoCast(m_creature->getVictim(),HeroicMode ? H_SPELL_BROOD_PLAGUE : SPELL_BROOD_PLAGUE);
            plague_Timer = 15000;
        }else plague_Timer -= diff;

        if(HeroicMode)
            if(rage_Timer < diff)
            {
                Unit* Swarmer = m_creature->FindNearestCreature(MOB_AHNKAHAR_SWARMER, 35);

                if(Swarmer)
                {
                    DoCast(Swarmer,H_SPELL_BROOD_RAGE,true);
                    rage_Timer = 15000;
                }
            }else rage_Timer -= diff;

        if(swarmer_spawn_Timer < diff)
        {
            DoCast(m_creature,SPELL_SUMMON_SWARMERS,true);
            DoCast(m_creature,SPELL_SUMMON_SWARMERS);
            if(rand()%3 == 0)
            {
                switch(rand()%2)
                {
                case 0: DoScriptText(SAY_EGG_SAC_1,m_creature); break;
                case 1: DoScriptText(SAY_EGG_SAC_2,m_creature); break;
                }
            }
            swarmer_spawn_Timer = 10000;
        }else swarmer_spawn_Timer -= diff;

        if(guard_spawn_Timer < diff)
        {
            m_creature->MonsterTextEmote("An Ahn'kahar Guardian hatches!",m_creature->GetGUID(),true);
            DoCast(m_creature,SPELL_SUMMON_SWARM_GUARD);
            guard_spawn_Timer = 25000;
        }else guard_spawn_Timer -= diff;

        if(enrage_Timer < diff)
        {
            if(m_creature->HasAura(SPELL_ENRAGE,0))
                return;

            float x, y, z, o;
            m_creature->GetHomePosition(x, y, z, o);
            if(z < 24 )
            {
                if(!m_creature->IsNonMeleeSpellCasted(false))
                {
                    DoCast(m_creature,SPELL_ENRAGE,true);
                }
            }
            enrage_Timer = 5000;
        }else enrage_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_elder_nadox(Creature *_Creature)
{
    return new boss_elder_nadoxAI(_Creature);
}
#define SPELL_SPRINT            56354
struct TRINITY_DLL_DECL mob_ahnkahar_nerubianAI : public ScriptedAI
{
    mob_ahnkahar_nerubianAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
        Reset();
    }

    ScriptedInstance *pInstance;
    uint32 sprint_Timer;

    void Reset()
    {
        if(m_creature->GetEntry() == 30176)
            DoCast(m_creature,SPELL_GUARDIAN_AURA,true);
        sprint_Timer = 10000;
    }
    void EnterCombat(Unit *who){}
    void UpdateAI(const uint32 diff)
    {
        if(m_creature->GetEntry() == 30176)
            m_creature->RemoveAurasDueToSpell(SPELL_GUARDIAN_AURA);

        if(pInstance)
        {
            if(pInstance->GetData(DATA_ELDER_NADOX_EVENT) != IN_PROGRESS)
            {
                m_creature->DealDamage(m_creature,m_creature->GetHealth());
                m_creature->RemoveCorpse();
            }
        }

        if(!UpdateVictim())
            return;

        if(sprint_Timer < diff)
        {
            DoCast(m_creature,SPELL_SPRINT);
            sprint_Timer = 25000;
        }else sprint_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_ahnkahar_nerubian(Creature *_Creature)
{
    return new mob_ahnkahar_nerubianAI(_Creature);
}

void AddSC_boss_elder_nadox()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_elder_nadox";
    newscript->GetAI = &GetAI_boss_elder_nadox;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_ahnkahar_nerubian";
    newscript->GetAI = &GetAI_mob_ahnkahar_nerubian;
    newscript->RegisterSelf();
}
