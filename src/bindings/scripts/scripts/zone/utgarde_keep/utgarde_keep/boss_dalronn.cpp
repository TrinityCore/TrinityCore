/* Script Data Start
SDName: Boss dalronn
SDAuthor: LordVanMartin
SD%Complete: 
SDComment: 
SDCategory: 
Script Data End */

/*** SQL START *** 
update creature_template set scriptname = 'boss_dalronn' where entry = '';
*** SQL END ***/
#include "precompiled.h"

//Spells
#define SPELL_DEBILITATE                            43650
#define SPELL_SHADOWBOLT                            43649
#define SPELL_SHADOWBOLT_2                          59575
#define SPELL_SUMMON_SKELETONS                      52611  //Trigger Spell: 52612, summons NPC (28878)
#define SPELL_SKARVALD_GHOST                        48613 //When Skarvald dies

//Yell
#define SAY_AGGRO                                -1574005
#define SAY_KILL                                 -1574006
#define SAY_DEATH_1                              -1574007
#define SAY_DEATH_2                              -1574008
#define SAY_RAISES                               -1574009

struct TRINITY_DLL_DECL boss_dalronnAI : public ScriptedAI
{
    boss_dalronnAI(Creature *c) : ScriptedAI(c) {}
    
    uint32 killed;
    uint64 Skarvald;
    
    void Reset() 
	{
		Skarvald = 0;
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
		
        if (Skarvald)
        {
            Creature* Skravald_m = (Unit::GetCreature((*m_creature), Skarvald));
            if (Skravald_m)
            {
                if (!Skravald_m->isAlive())
				{
					DoCast(Skravald_m,SPELL_SKARVALD_GHOST);
					DoScriptText(SAY_RAISES, m_creature);
				}
            }
        }
                
        DoMeleeAttackIfReady();    
    }
    void JustDied(Unit* killer) 
    {
        killed++;
        //On first death resurected instatly by Skarvald as a ghost, having the same abilities as when alive and is unatackable
        //If Skarvald dies first,  Dalron resurects him and says "SAY_RAISES"
        if(killed ==2)
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

CreatureAI* GetAI_boss_dalronn(Creature *_Creature)
{
    return new boss_dalronnAI (_Creature);
}

void AddSC_boss_dalronn()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_dalronn";
    newscript->GetAI = GetAI_boss_dalronn;
    newscript->RegisterSelf();
}
