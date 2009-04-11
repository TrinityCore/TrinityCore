/* Script Data Start
SDName: Boss krik_thir
SDAuthor: LordVanMartin
SD%Complete: 
SDComment: 
SDCategory: 
Script Data End */

/*** SQL START *** 
update creature_template set scriptname = 'boss_krik_thir' where entry = '';
*** SQL END ***/
#include "precompiled.h"

//Spells
#define SPELL_SUMMON_SKITTERING_SWARMER               52438 //maybe 52439 //summons NPC 28735
#define SPELL_MIND_FLAY                               52586
#define SPELL_FRENZY                                  53361
#define SPELL_CURSE_OF_FATIGUE                        52592 //Curses all enemies in a 5 radius around the target, dealing 2828 to 3172 Shadow damage, slowing movement speed by 30%, attack speed by 30%, and casting speed by 30%. Lasts 10 sec.

#define SKITTERING_SWARMER                            28735

//Yell
#define SAY_AGGRO                                    -1601011
#define SAY_SLAY_1                                   -1601012
#define SAY_SLAY_2                                   -1601013
#define SAY_SLAY_3                                   -1601014
#define SAY_DEATH                                    -1601015
#define SAY_SEND_GROUP_1                             -1601018
#define SAY_SEND_GROUP_2                             -1601019
#define SAY_SEND_GROUP_3                             -1601020
#define SAY_SWARM_1                                  -1601016
#define SAY_SWARM_2                                  -1601017
#define SAY_PREFIGHT_1                               -1601021
#define SAY_PREFIGHT_2                               -1601022
#define SAY_PREFIGHT_3                               -1601023

struct TRINITY_DLL_DECL boss_krik_thirAI : public ScriptedAI
{
    boss_krik_thirAI(Creature *c) : ScriptedAI(c) {}
    
    void Reset() {}
    
    void Aggro(Unit* who) 
    {
        DoScriptText(SAY_AGGRO, m_creature);
    }

    void UpdateAI(const uint32 diff) 
    {
        if(!UpdateVictim())
            return;
        
        if ((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) >= 10)
        {
            //Frenzy
        }
       
        DoMeleeAttackIfReady();
    }
    void JustDied(Unit* killer)  
    {
        DoScriptText(SAY_DEATH, m_creature);
    }
    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;

        switch(rand()%3)
        {
            case 0: DoScriptText(SAY_SLAY_1, m_creature);break;
            case 1: DoScriptText(SAY_SLAY_2, m_creature);break;
            case 2: DoScriptText(SAY_SLAY_3, m_creature);break;
        }
    }
};

CreatureAI* GetAI_boss_krik_thir(Creature *_Creature)
{
    return new boss_krik_thirAI (_Creature);
}

void AddSC_boss_krik_thir()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_krik_thir";
    newscript->GetAI = GetAI_boss_krik_thir;
    newscript->RegisterSelf();

}
