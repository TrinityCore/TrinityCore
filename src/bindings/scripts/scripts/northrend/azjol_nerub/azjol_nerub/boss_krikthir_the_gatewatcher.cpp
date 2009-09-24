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
SDName: boss_krikthir_the_gatewatcher
SD%Complete: 80 % 
SDComment: Find in the future best timers and the event is not implemented.
SDCategory: Azjol Nerub
EndScriptData */

/*** SQL START ***
update creature_template set scriptname = 'boss_krik_thir' where entry = '';
*** SQL END ***/

#include "precompiled.h"
#include "def_azjol_nerub.h"

enum
{
    SPELL_MIND_FLAY                        =   52586,
    H_SPELL_MIND_FLAY                      =   59367,
    SPELL_CURSE_OF_FATIGUE                 =   52592,
    H_SPELL_CURSE_OF_FATIGUE               =   59368,
    SPELL_FRENZY                           =   28747, //maybe 53361

    MOB_SKITTERING_SWARMER                 =   28735,
    MOB_SKITTERING_SWARMER_CONTROLLER      =   32593,
    MOB_SKITTERING_INFECTIOR               =   28736,

    SPELL_SUMMON_SKITTERING_SWARMER        =   52438, //AOE Effect 140, maybe 52439
    SPELL_SUMMON_SKITTERING_SWARMER_1      =   52439, //Summon 3x 28735

    SAY_AGGRO                              =   -1601000,
    SAY_SLAY_1                             =   -1601001,
    SAY_SLAY_2                             =   -1601002,
    SAY_DEATH                              =   -1601003,
    
    //Not in db
    SAY_SEND_GROUP_1                       =   -1601004,
    SAY_SEND_GROUP_2                       =   -1601005,
    SAY_SEND_GROUP_3                       =   -1601006,
    SAY_SWARM_1                            =   -1601007,
    SAY_SWARM_2                            =   -1601008,
    SAY_PREFIGHT_1                         =   -1601009,
    SAY_PREFIGHT_2                         =   -1601010,
    SAY_PREFIGHT_3                         =   -1601011

};

struct TRINITY_DLL_DECL boss_krik_thirAI : public ScriptedAI
{
    boss_krik_thirAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
        HeroicMode = c->GetMap()->IsHeroic();
    }

    ScriptedInstance* pInstance;
    bool HeroicMode;

    uint32 MindFlayTimer;
    uint32 CurseFatigueTimer;
    uint32 SummonTimer;

    void Reset()
    {
        MindFlayTimer        = 15000;
        CurseFatigueTimer   = 12000;

        if (pInstance)
            pInstance->SetData(DATA_KRIKTHIR_THE_GATEWATCHER_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
        Summon();
        SummonTimer = 15000;

        if (pInstance)
            pInstance->SetData(DATA_KRIKTHIR_THE_GATEWATCHER_EVENT, IN_PROGRESS);
    }

    void Summon()
    {
            m_creature->SummonCreature(MOB_SKITTERING_SWARMER,566.164,682.087,769.079,2.21657,TEMPSUMMON_TIMED_DESPAWN,25000);
            m_creature->SummonCreature(MOB_SKITTERING_SWARMER,566.164,682.087,769.079,2.21657,TEMPSUMMON_TIMED_DESPAWN,25000);
            m_creature->SummonCreature(MOB_SKITTERING_SWARMER,529.042,706.941,777.298,1.0821,TEMPSUMMON_TIMED_DESPAWN,25000);
            m_creature->SummonCreature(MOB_SKITTERING_SWARMER,529.042,706.941,777.298,1.0821,TEMPSUMMON_TIMED_DESPAWN,25000);
            m_creature->SummonCreature(MOB_SKITTERING_SWARMER,489.975,671.239,772.131,0.261799,TEMPSUMMON_TIMED_DESPAWN,25000);
            m_creature->SummonCreature(MOB_SKITTERING_SWARMER,489.975,671.239,772.131,0.261799,TEMPSUMMON_TIMED_DESPAWN,25000);
            m_creature->SummonCreature(MOB_SKITTERING_SWARMER,488.556,692.95,771.764,4.88692,TEMPSUMMON_TIMED_DESPAWN,25000);
            m_creature->SummonCreature(MOB_SKITTERING_SWARMER,488.556,692.95,771.764,4.88692,TEMPSUMMON_TIMED_DESPAWN,25000);
            m_creature->SummonCreature(MOB_SKITTERING_INFECTIOR,553.34,640.387,777.419,1.20428,TEMPSUMMON_TIMED_DESPAWN,25000);
            m_creature->SummonCreature(MOB_SKITTERING_SWARMER,553.34,640.387,777.419,1.20428,TEMPSUMMON_TIMED_DESPAWN,25000);
            m_creature->SummonCreature(MOB_SKITTERING_INFECTIOR,517.486,706.398,777.335,5.35816,TEMPSUMMON_TIMED_DESPAWN,25000);
            m_creature->SummonCreature(MOB_SKITTERING_SWARMER,517.486,706.398,777.335,5.35816,TEMPSUMMON_TIMED_DESPAWN,25000);
            m_creature->SummonCreature(MOB_SKITTERING_INFECTIOR,504.01,637.693,777.479,0.506145,TEMPSUMMON_TIMED_DESPAWN,25000);
            m_creature->SummonCreature(MOB_SKITTERING_SWARMER,504.01,637.693,777.479,0.506145,TEMPSUMMON_TIMED_DESPAWN,25000);
            m_creature->SummonCreature(MOB_SKITTERING_SWARMER,552.625,706.408,777.177,3.4383,TEMPSUMMON_TIMED_DESPAWN,25000);
            m_creature->SummonCreature(MOB_SKITTERING_SWARMER,552.625,706.408,777.177,3.4383,TEMPSUMMON_TIMED_DESPAWN,25000);
           
            
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;
        

        if(SummonTimer < diff)
        {
            Summon();
            SummonTimer = 15000;
        }else SummonTimer -= diff;

        if (MindFlayTimer < diff)
        {
                DoCast(m_creature->getVictim(), HeroicMode ? H_SPELL_MIND_FLAY : SPELL_MIND_FLAY);

                MindFlayTimer = 15000;
            }else MindFlayTimer -= diff;

        if (CurseFatigueTimer < diff)
        {
            //WowWiki say "Curse of Fatigue-Kirk'thir will cast Curse of Fatigue on 2-3 targets periodically. "
            Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0);
            Unit* target_1 = SelectUnit(SELECT_TARGET_RANDOM, 1);

            DoCast(target, HeroicMode ? H_SPELL_CURSE_OF_FATIGUE : SPELL_CURSE_OF_FATIGUE);
            DoCast(target_1, HeroicMode ? H_SPELL_CURSE_OF_FATIGUE : SPELL_CURSE_OF_FATIGUE);

            CurseFatigueTimer = 10000;
        }else CurseFatigueTimer -= diff;

        if (!m_creature->HasAura(SPELL_FRENZY) && m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 10)
        {
            m_creature->CastSpell(m_creature,SPELL_FRENZY,true);
        }

        DoMeleeAttackIfReady();
    }
    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH, m_creature);

        if (pInstance)
            pInstance->SetData(DATA_KRIKTHIR_THE_GATEWATCHER_EVENT, DONE);
    }
    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;

        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2), m_creature);
    }

    void JustSummoned(Creature* summoned)
    {
        summoned->GetMotionMaster()->MovePoint(m_creature->GetEntry(),m_creature->GetPositionX(),m_creature->GetPositionY(),m_creature->GetPositionZ());
        
    }
};

CreatureAI* GetAI_boss_krik_thir(Creature* pCreature)
{
    return new boss_krik_thirAI (pCreature);
}

void AddSC_boss_krik_thir()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_krik_thir";
    newscript->GetAI = &GetAI_boss_krik_thir;
    newscript->RegisterSelf();
}
