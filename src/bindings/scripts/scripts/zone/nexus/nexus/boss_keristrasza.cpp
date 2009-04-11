/* Script Data Start
SDName: Boss keristrasza
SDAuthor: LordVanMartin
SD%Complete: 
SDComment: 
SDCategory: 
Script Data End */

/*** SQL START *** 
update creature_template set scriptname = 'boss_maiden_of_grief' where entry = '';
*** SQL END ***/
#include "precompiled.h"

//Spells
#define SPELL_TAIL_SWEEP                                50155
#define SPELL_CRYSTAL_CHAINS                            50997
#define SPELL_ENRAGE                                    8599
#define SPELL_CRYSTALFIRE_BREATH_1                      48096
#define SPELL_CRYSTALFIRE_BREATH_2                      57091
#define SPELL_CRYSTALIZE                                48179
#define SPELL_INTENSE_COLD                              48095 //stackable debuff

//Yell
#define SAY_AGGRO                                    -1576005
#define SAY_SLAY                                     -1576006
#define SAY_ENRAGE                                   -1576007
#define SAY_DEATH                                    -1576008
#define SAY_CRYSTAL_NOVA                             -1576009

struct TRINITY_DLL_DECL boss_keristraszaAI : public ScriptedAI
{
    boss_keristraszaAI(Creature *c) : ScriptedAI(c) {}
           
    bool enraged;
    
    void Reset() 
    {
        enraged = false;
    }
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

        if ((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) == 10)
        {
            if(!enraged)
            {
                DoScriptText(SAY_ENRAGE, m_creature);
                DoCast(m_creature, SPELL_ENRAGE);
                enraged = true;
            }
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
    newscript->GetAI = GetAI_boss_keristrasza;
    newscript->RegisterSelf();
}
