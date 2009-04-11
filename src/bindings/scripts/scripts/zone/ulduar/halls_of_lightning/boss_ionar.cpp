/* Script Data Start
SDName: Boss ionar
SDAuthor: LordVanMartin
SD%Complete: 
SDComment: 
SDCategory: 
Script Data End */

/*** SQL START *** 
update creature_template set scriptname = 'boss_ionar' where entry = '';
*** SQL END ***/
#include "precompiled.h"

//Spells
#define SPELL_BALL_LIGHTNING                      52780
#define SPELL_BALL_LIGHTNING_2                    59800 
#define SPELL_DISPERSE                            52770 //Disperse into Sparks of Ionar.
#define SPELL_STATIC_OVERLOAD                     52658 //Effect    Apply Aura: Periodic Trigger Interval: 2 seconds Spell 52659    
#define SPELL_STATIC_OVERLOAD_2                   52658 //Effect    Apply Aura: Periodic Trigger Interval: 2 seconds Spell 59796

//Spark of Ionar spells
#define NPC_SPARK_OF_IONAR                        28962 //invulnerable
#define SPELL_ARCING_BURN                         52617
#define SPELL_ARCING_BURN_2                       59834

//Yell
#define SAY_AGGRO                              -1602008
#define SAY_SLAY_1                             -1602009
#define SAY_SLAY_2                             -1602010
#define SAY_SLAY_3                             -1602011
#define SAY_DEATH                              -1602012
#define SAY_SPLIT_1                            -1602013
#define SAY_SPLIT_2                            -1602014

//he does "morph" every about 25% into 4 sparks of ionar that chase people around, they r slow and easily avoidable.

struct TRINITY_DLL_DECL boss_ionarAI : public ScriptedAI
{
    boss_ionarAI(Creature *c) : ScriptedAI(c) {}
    
    void Reset() {}
    void Aggro(Unit* who) 
    {
        DoScriptText(SAY_AGGRO, m_creature);
    }
    void AttackStart(Unit* who) {}
    void MoveInLineOfSight(Unit* who) {}
    void UpdateAI(const uint32 diff) 
    {
        //Return since we have no target
        if(!UpdateVictim())
            return;
                
        DoMeleeAttackIfReady();    
    }
    void JustDied(Unit* killer)  
    {
        DoScriptText(SAY_DEATH, m_creature);
    }
    void KilledUnit(Unit *victim)
    {
        if(victim == m_creature)
            return;
        switch(rand()%3)
        {
            case 0: DoScriptText(SAY_SLAY_1, m_creature);break;
            case 1: DoScriptText(SAY_SLAY_2, m_creature);break;
            case 2: DoScriptText(SAY_SLAY_3, m_creature);break;
        }
    }
};

struct TRINITY_DLL_DECL npc_spark_of_ionarAI : public ScriptedAI
{
    npc_spark_of_ionarAI(Creature *c) : ScriptedAI(c) {}

    void Reset() {}
    void Aggro(Unit* who) {}
    void AttackStart(Unit* who) {}
    void MoveInLineOfSight(Unit* who) {}
    void UpdateAI(const uint32 diff) 
    {
        //Return since we have no target
        if(!UpdateVictim())
            return;
                
        DoMeleeAttackIfReady();    
    }
    void JustDied(Unit* killer)  {}
};

CreatureAI* GetAI_npc_spark_of_ionar(Creature *_Creature)
{
    return new npc_spark_of_ionarAI (_Creature);
}
CreatureAI* GetAI_boss_ionar(Creature *_Creature)
{
    return new boss_ionarAI (_Creature);
}

void AddSC_boss_ionar()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_ionar";
    newscript->GetAI = GetAI_boss_ionar;
    newscript->RegisterSelf();
    
    newscript = new Script;
    newscript->Name="spark_of_ionar";
    newscript->GetAI = GetAI_npc_spark_of_ionar;
    newscript->RegisterSelf();
}
