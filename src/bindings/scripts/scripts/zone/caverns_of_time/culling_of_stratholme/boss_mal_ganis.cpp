/* Script Data Start
SDName: Boss mal_ganis
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = 'boss_mal_ganis' where entry = '';
*** SQL END ***/
#include "precompiled.h"

//Spells
#define SPELL_CARRION_SWARM_N                         52720 //A cresting wave of chaotic magic splashes over enemies in front of the caster, dealing 3230 to 3570 Shadow damage and 380 to 420 Shadow damage every 3 sec. for 15 sec.
#define SPELL_CARRION_SWARM_H                         58852
#define SPELL_MIND_BLAST_N                            52722 //Inflicts 4163 to 4837 Shadow damage to an enemy.
#define SPELL_MIND_BLAST_H                            58850
#define SPELL_SLEEP                                   52721 //Puts an enemy to sleep for up to 10 sec. Any damage caused will awaken the target.
#define SPELL_VAMPIRIC_TOUCH                          52723 //Heals the caster for half the damage dealt by a melee attack.

//Yell Mal'ganis
#define SAY_INTRO_1                                  -1595009
#define SAY_INTRO_2                                  -1595010
#define SAY_OUTRO                                    -1595011
#define SAY_AGGRO                                    -1595012
#define SAY_KILL_1                                   -1595013
#define SAY_KILL_2                                   -1595014
#define SAY_KILL_3                                   -1595015
#define SAY_SLAY_1                                   -1595016
#define SAY_SLAY_2                                   -1595017
#define SAY_SLAY_3                                   -1595018
#define SAY_SLAY_4                                   -1595019
#define SAY_SLEEP_1                                  -1595020
#define SAY_SLEEP_2                                  -1595021
#define SAY_30HEALTH                                 -1595022
#define SAY_15HEALTH                                 -1595023
#define SAY_ESCAPE_SPEECH_1                          -1595024
#define SAY_ESCAPE_SPEECH_2                          -1595025

struct TRINITY_DLL_DECL boss_mal_ganisAI : public ScriptedAI
{
    boss_mal_ganisAI(Creature *c) : ScriptedAI(c) {}

    bool yelled,
         yelled2,
         yelled3;

    void Reset()
    {
         yelled = false;
         yelled2 = false;
         yelled3 = false;
    }

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
    }

    void AttackStart(Unit* who) {}
    void MoveInLineOfSight(Unit* who) {}
    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (!yelled)
        {
            if ((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 30)
            {
                DoScriptText(SAY_30HEALTH, m_creature);
                yelled = true;
            }
        }

        if (!yelled2)
        {
            if ((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 15)
            {
                DoScriptText(SAY_15HEALTH, m_creature);
                yelled2 = true;
            }
        }

        if ((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 1)
        {
            //Handle Escape Event
        }

        DoMeleeAttackIfReady();
    }
    void JustDied(Unit* killer)  {}
    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;

        switch(rand()%4)
        {
            case 0: DoScriptText(SAY_SLAY_1, m_creature);break;
            case 1: DoScriptText(SAY_SLAY_2, m_creature);break;
            case 2: DoScriptText(SAY_SLAY_3, m_creature);break;
            case 3: DoScriptText(SAY_SLAY_4, m_creature);break;
        }
    }
};

CreatureAI* GetAI_boss_mal_ganis(Creature *_Creature)
{
    return new boss_mal_ganisAI (_Creature);
}

void AddSC_boss_mal_ganis()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_mal_ganis";
    newscript->GetAI = &GetAI_boss_mal_ganis;
    newscript->RegisterSelf();
}
