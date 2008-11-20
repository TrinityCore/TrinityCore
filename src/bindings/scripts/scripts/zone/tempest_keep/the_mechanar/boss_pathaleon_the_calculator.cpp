/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss Pathaleon the Calculator
SD%Complete: 50
SDComment: Event missing. Script for himself 99% blizzlike.
SDCategory: Tempest Keep, The Mechanar
EndScriptData */

#include "precompiled.h"

// Spells to be casted
#define SPELL_SUMMON_NETHER_WRAITH    35287   //Spell not working. Summon is working but Pets dont attack and wrong HP.
#define SPELL_MANA_TAP                36021
#define SPELL_ARCANE_TORRENT          36022
#define SPELL_DOMINATION              35280
#define H_SPELL_ARCANE_EXPLOSION      34791  //Spell not right.
#define SPELL_ENRAGE                  36992

// Add Spells
#define SPELL_DETONATION              35058
#define SPELL_ARCANE_MISSILES         35034

// On Domination
#define SAY_SPELL_DOMINATION_1    "I'm looking for a team player... "
#define SOUND_SPELL_DOMINATION_1  11197
#define SAY_SPELL_DOMINATION_2    "You work for me now!"
#define SOUND_SPELL_DOMINATION_2  11198

// On Summon
#define SAY_SUMMON_1          "Time to supplement my work force."
#define SOUND_SAY_SUMMON_1    11196 

// On Enrage
#define SAY_ENRAGE_1          "A minor inconvenience."
#define SOUND_SAY_ENRAGE_1    11199 

// On Aggro
#define SAY_AGGRO_1          "We are on a strict timetable. You will not interfere!"
#define SOUND_SAY_AGGRO_1    11193 

//On Kill Unit
#define SAY_SLAY_1           "Looks like you lose"
#define SOUND_SLAY_1         11195

// On Death
#define SAY_DEATH_1          "The project will... continue."
#define SOUND_DEATH_1        11200  


struct TRINITY_DLL_DECL boss_pathaleon_the_calculatorAI : public ScriptedAI
{    
    boss_pathaleon_the_calculatorAI(Creature *c) : ScriptedAI(c)
    {         
        HeroicMode = m_creature->GetMap()->IsHeroic();
        Reset();
    }

    uint32 Summon_Timer;    
    uint32 ManaTap_Timer;
    uint32 ArcaneTorrent_Timer;      
    uint32 Domination_Timer; 
    uint32 ArcaneExplosion_Timer;   
    bool HeroicMode;
    bool Enraged;

    uint32 Counter;
    Creature* Wraith;

    void Reset()    
    {         
        Summon_Timer = 30000;        
        ManaTap_Timer = 12000 + rand()%8000;
        ArcaneTorrent_Timer = 16000 + rand()%9000;
        Domination_Timer = 25000 + rand()%15000;
        ArcaneExplosion_Timer = 8000 + rand()%5000;
        
        Enraged = false;

        Counter = 0;

    }     
    void Aggro(Unit *who)    
    {       
        DoYell(SAY_AGGRO_1,LANG_UNIVERSAL,NULL);        
        DoPlaySoundToSet(m_creature, SOUND_SAY_AGGRO_1);     
    }     

    // On Killed Unit    
    void KilledUnit(Unit* victim)    
    {

        DoYell(SAY_SLAY_1, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature,SOUND_SLAY_1);

    }   

    // On Death    
    void JustDied(Unit* Killer)    
    {        
        DoYell(SAY_DEATH_1,LANG_UNIVERSAL,NULL);        
        DoPlaySoundToSet(m_creature, SOUND_DEATH_1);    
    }

    void UpdateAI(const uint32 diff)    
    {       
        //Return since we have no target        
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )            
            return;         
       
        if(Summon_Timer < diff)        
        {      

            Unit* target = NULL;   

            for(int i = 0; i < 3;i++)
            {   
            target = SelectUnit(SELECT_TARGET_RANDOM,0);
            Wraith = m_creature->SummonCreature(21062,m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(),0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
            if (target)
            Wraith->AI()->AttackStart(target);
            }

            DoYell(SAY_SUMMON_1,LANG_UNIVERSAL,NULL);        
            DoPlaySoundToSet(m_creature, SOUND_SAY_SUMMON_1); 
 
            Summon_Timer = 30000 + rand()%15000;         
        }else Summon_Timer -= diff;         
       
        if(ManaTap_Timer < diff)        
        {            
            //time to cast            
            DoCast(m_creature->getVictim(),SPELL_MANA_TAP);             

            //Cast again on time            
            ManaTap_Timer = 14000 + rand()%8000;                
        }else ManaTap_Timer -= diff;  
        
        if(ArcaneTorrent_Timer < diff)        
        {            
            //time to cast            
            DoCast(m_creature->getVictim(),SPELL_ARCANE_TORRENT);             

            //Cast again on time            
            ArcaneTorrent_Timer = 12000 + rand()%6000;                
        }else ArcaneTorrent_Timer -= diff;  
        
        if(Domination_Timer < diff)        
        {            
            //time to cast        
            switch(rand()%2)
            {
            case 0:
                DoYell(SAY_SPELL_DOMINATION_1, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_SPELL_DOMINATION_1);
            break;

            case 1:
                DoYell(SAY_SPELL_DOMINATION_2, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_SPELL_DOMINATION_2);
            break;
            }
        
            Unit* target = NULL;
            target = SelectUnit(SELECT_TARGET_RANDOM,1);
            if (target) DoCast(target,SPELL_DOMINATION);             

            //Cast again on time            
            Domination_Timer = 25000 + rand()%5000;               
        }else Domination_Timer -= diff;          
     
        //Only casting if Heroic Mode is used
        if (HeroicMode)
        {
            if(ArcaneExplosion_Timer < diff)        
            {            
                //time to cast            
                DoCast(m_creature->getVictim(),H_SPELL_ARCANE_EXPLOSION);             

                //Cast again on time            
                ArcaneExplosion_Timer = 10000 + rand()%4000;                
            }else ArcaneExplosion_Timer -= diff;
        }
        
        if (!Enraged && m_creature->GetHealth()*100 / m_creature->GetMaxHealth() < 21)
        {

            DoCast(m_creature, SPELL_ENRAGE);
            DoYell(SAY_ENRAGE_1, LANG_UNIVERSAL, NULL);
            DoPlaySoundToSet(m_creature,SOUND_SAY_ENRAGE_1);
            Enraged = true;

        }

        DoMeleeAttackIfReady();
    } 
};   
CreatureAI* GetAI_boss_pathaleon_the_calculator(Creature *_Creature)
{    
    return new boss_pathaleon_the_calculatorAI (_Creature);
} 

struct TRINITY_DLL_DECL mob_nether_wraithAI : public ScriptedAI
{
    mob_nether_wraithAI(Creature *c) : ScriptedAI(c) {Reset();}

    ScriptedInstance *pInstance;

    uint32 ArcaneMissiles_Timer;
    uint32 Detonation_Timer;
    uint32 Die_Timer;
    bool Detonation;

    void Reset()
    {   
        ArcaneMissiles_Timer = 1000 + rand()%3000;
        Detonation_Timer = 20000;
        Die_Timer = 2200;
        Detonation = false;

    }

    void Aggro(Unit* who)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        Unit* target = NULL;

        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        if(ArcaneMissiles_Timer < diff)
        {

            Unit* target = NULL;
            target = SelectUnit(SELECT_TARGET_RANDOM,1);
            if (!target)
            target = m_creature->getVictim();
            if (target)
            {
            DoCast(target,SPELL_ARCANE_MISSILES);
            }

            ArcaneMissiles_Timer = 5000 + rand()%5000;
        }else ArcaneMissiles_Timer -=diff;

        if (!Detonation)
        {
            if(Detonation_Timer < diff)        
            {            
                //time to cast            
                DoCast(m_creature,SPELL_DETONATION);    
                Detonation = true;         
        
            }else Detonation_Timer -= diff;  

        }

        if (Detonation)
        {
            if (Die_Timer < diff)
            {
                m_creature->setDeathState(JUST_DIED);
                m_creature->RemoveCorpse();
            }else Die_Timer -= diff;
        }


        DoMeleeAttackIfReady();
    }

};
CreatureAI* GetAI_mob_nether_wraith(Creature *_Creature)
{
    return new mob_nether_wraithAI (_Creature);
}

void AddSC_boss_pathaleon_the_calculator()
{    
    Script *newscript;    
    newscript = new Script;    
    newscript->Name="boss_pathaleon_the_calculator";    
    newscript->GetAI = GetAI_boss_pathaleon_the_calculator;    
    newscript->RegisterSelf();

    newscript = new Script;    
    newscript->Name="mob_nether_wraith";    
    newscript->GetAI = GetAI_mob_nether_wraith;    
    newscript->RegisterSelf();
}
