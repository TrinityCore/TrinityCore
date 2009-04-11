/* Script Data Start
SDName: Boss anomalus
SDAuthor: LordVanMartin
SD%Complete: 
SDComment: 
SDCategory: 
Script Data End */

/*** SQL START *** 
update creature_template set scriptname = '' where entry = '';
*** SQL END ***/
#include "precompiled.h"

//Spells
#define SPELL_SPARK_1              47751
#define SPELL_SPARK_2              57062
#define SPELL_RIFT_SHIELD          47748
#define SPELL_CHARGE_RIFT          47747
#define SPELL_ARCANE_ATTRACTION    57063
#define SPELL_CREATE_RIFT          47743 //Dummy ---> summons (npc 26918) "Chaotic Rift", which spawns "Crazed Mana Wraith"s  (npc 26746)

#define MOB_CRAZED_MANA_WRAITH     26746
#define NPC_CHAOTIC_RIFT           26918

//Yell
#define SAY_AGGRO               -1576000
#define SAY_KILL                -1576001
#define SAY_DEATH               -1576002
#define SAY_RIFT                -1576003
#define SAY_SHIELD              -1576004

struct TRINITY_DLL_DECL boss_anomalusAI : public ScriptedAI
{
    boss_anomalusAI(Creature *c) : ScriptedAI(c) {}

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
            
            //Source DBM
        if((((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 80) && ((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) > 77))
            || (((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 55) && ((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) > 52))
            || (((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 30) && ((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) > 27)))
        {
                //Summon rift at a random location
        }
                
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
        DoScriptText(SAY_KILL, m_creature);
    }
};

/*######
## Crazed Mana Wraiths
######*/
#define SPELL_ARCANE_MISSILES                                 33833

struct TRINITY_DLL_DECL mob_crazed_mana_wraithAI : public ScriptedAI
{
    mob_crazed_mana_wraithAI(Creature *c) : ScriptedAI(c) {}

    void Reset() {}
    void Aggro(Unit* who) {}
    void UpdateAI(const uint32 diff) 
    {
        //Return since we have no target
        if(!UpdateVictim())
            return;
                
        DoMeleeAttackIfReady();    
    }
    void JustDied(Unit* killer)  {}
};

/*######
## Chaotic Rift
######*/
#define SPELL_CHAOTIC_ENERGY_BURST                      47688
#define SPELL_CHARGED_CHAOTIC_ENERGY_BURST              47737

struct TRINITY_DLL_DECL npc_chaotic_riftAI : public ScriptedAI
{
    npc_chaotic_riftAI(Creature *c) : ScriptedAI(c) {}

    void Reset() {}
    void Aggro(Unit* who) {}
    void UpdateAI(const uint32 diff) 
    {
        //Return since we have no target
        if(!UpdateVictim())
            return;
                
        DoMeleeAttackIfReady();    
    }
    void JustDied(Unit* killer)  {}
};

CreatureAI* GetAI_npc_chaotic_rift(Creature *_Creature)
{
    return new npc_chaotic_riftAI (_Creature);
}

CreatureAI* GetAI_boss_anomalus(Creature *_Creature)
{
    return new boss_anomalusAI (_Creature);
}

CreatureAI* GetAI_mob_crazed_mana_wraith(Creature *_Creature)
{
    return new boss_anomalusAI (_Creature);
}

void AddSC_boss_anomalus()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_anomalus";
    newscript->GetAI = GetAI_boss_anomalus;
    newscript->RegisterSelf();
    
    newscript = new Script;
    newscript->Name="mob_crazed_mana_wraith";
    newscript->GetAI = GetAI_mob_crazed_mana_wraith;
    newscript->RegisterSelf();
    
    newscript = new Script;
    newscript->Name="npc_chaotic_rift";
    newscript->GetAI = GetAI_npc_chaotic_rift;
    newscript->RegisterSelf();
}
