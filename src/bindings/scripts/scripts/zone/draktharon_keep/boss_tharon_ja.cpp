/* Script Data Start
SDName: Boss tharon_ja
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = 'boss_tharon_ja' where entry = '';
*** SQL END ***/
#include "precompiled.h"

//Spells
#define SPELL_COURSE_OF_LIFE                          49527
#define SPELL_DECAY_FLESH                             49356 //casted at end of pahase 1, starts phase 2
#define SPELL_EYE_BEAM_N                              49544
#define SPELL_LIGHTNING_BREATH_N                      49537
#define SPELL_POISON_CLOUD_N                          49548
#define SPELL_RAIN_OF_FIRE_N                          49518
#define SPELL_RETURN_FLESH                            53463 //Channeled spell ending phase two and returning to phase 1. This ability will stun the party for 6 seconds.
#define SPELL_SHADOW_VOLLEY_N                         49528

//Spells Heroic
#define SPELL_COURSE_OF_LIFE_H                        59972
#define SPELL_EYE_BEAM_H                              59965
#define SPELL_LIGHTNING_BREATH_H                      59963
#define SPELL_POISON_CLOUD_H                          59969
#define SPELL_RAIN_OF_FIRE_H                          59971
#define SPELL_SHADOW_VOLLEY_H                         59973

//Players skills durring Phase2
#define PLAYER_PHASE2_SLAYING_STRIKE                  50799
#define PLAYER_PHASE2_TAUNT                           49613
#define PLAYER_PHASE2_BONE_ARMOR                      49609
#define PLAYER_PHASE2_TOUCH_OF_LIFE                   49617
//Phase 1 all abilities except Eye beam
//Phase 2 turns players to skeletons with new abilities, boss grows skin

//Yell
#define SAY_AGGRO                                   1600011
#define SAY_KILL_1                                  1600012
#define SAY_KILL_2                                  1600013
#define SAY_FLESH_1                                 1600014
#define SAY_FLESH_2                                 1600015
#define SAY_SKELETON_1                              1600016
#define SAY_SKELETON_2                              1600017
#define SAY_DEATH                                   1600018

struct TRINITY_DLL_DECL boss_tharon_jaAI : public ScriptedAI
{
    boss_tharon_jaAI(Creature *c) : ScriptedAI(c) {}

    void Reset() {}
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

        DoMeleeAttackIfReady();
    }
    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH,m_creature);
    }
};

CreatureAI* GetAI_boss_tharon_ja(Creature* pCreature)
{
    return new boss_tharon_jaAI (pCreature);
}

void AddSC_boss_tharon_ja()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_tharon_ja";
    newscript->GetAI = &GetAI_boss_tharon_ja;
    newscript->RegisterSelf();
}
