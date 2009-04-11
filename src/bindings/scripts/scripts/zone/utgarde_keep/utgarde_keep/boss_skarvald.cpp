/* Script Data Start
SDName: Boss skarvald
SDAuthor: LordVanMartin
SD%Complete: 
SDComment: 
SDCategory: 
Script Data End */

/*** SQL START *** 
update creature_template set scriptname = 'boss_skarvald' where entry = '';
*** SQL END ***/
#include "precompiled.h"

//Spells
#define SPELL_CHARGE                                 43651 //randomly charges anyone but tank WoWradio video 14s afer aggro, and then every 5s change target
#define SPELL_ENRAGE                                 48193
#define SPELL_STONE_STRIKE                           48583
#define SPELL_DALRON_GHOST                           48612 //When Dalron dies

//Yells
#define SAY_AGGRO                                 -1574010
#define SAY_KILL                                  -1574011
#define SAY_DEATH_1                               -1574012
#define SAY_DEATH_2                               -1574013
#define SAY_RAISES                                -1574014

struct TRINITY_DLL_DECL boss_skarvaldAI : public ScriptedAI
{
    boss_skarvaldAI(Creature *c) : ScriptedAI(c) {}

    uint32 kiled;
    uint64 Dalronn;
    
    void Reset() 
	{
		Dalronn = 0;
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

        if (Dalronn)
        {
            Creature* Dalronn_m = (Unit::GetCreature((*m_creature), Dalronn));
            if (Dalronn_m)
            {
                if (!Dalronn_m->isAlive())
				{
					DoCast(Dalronn_m,SPELL_DALRON_GHOST);
					DoScriptText(SAY_RAISES, m_creature);
				}
            }
        }
			
        DoMeleeAttackIfReady();    
    }
    void JustDied(Unit* killer) 
    {
        kiled++;
        //On first death resurected instatly by Dalron as a ghost, having the same abilities as when alive and is unatackable
        //If Dalron dies first,  Skarvald resurects him and says "SAY_RAISES"
        if(kiled ==2)
            DoScriptText(SAY_DEATH_2,m_creature);
        else
            DoScriptText(SAY_DEATH_1,m_creature);
    }
    void KilledUnit(Unit *victim)
    {
        if(victim == m_creature)
            return;
        DoScriptText(SAY_KILL, m_creature);
    }
};

CreatureAI* GetAI_boss_skarvald(Creature *_Creature)
{
    return new boss_skarvaldAI (_Creature);
}

void AddSC_boss_skarvald()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_skarvald";
    newscript->GetAI = GetAI_boss_skarvald;
    newscript->RegisterSelf();
}
