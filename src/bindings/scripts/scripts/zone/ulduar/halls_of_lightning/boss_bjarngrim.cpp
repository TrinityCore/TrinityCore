/* Script Data Start
SDName: Boss bjarngrim
SDAuthor: LordVanMartin
SD%Complete: 
SDComment: 
SDCategory: 
Script Data End */

/*** SQL START *** 
update creature_template set scriptname = '' where entry = '';
*** SQL END ***/
#include "precompiled.h"

//AURAS AND STANCES
#define BUFF_BATTLE_AURA                            41106
#define SPELL_BATTLE_STANCE                         53792
#define BUFF_BERSEKER_AURA                          41107
#define SPELL_BERSEKER_STANCE                       53791
#define BUFF_DEFENSIVE_AURA                         41105
#define SPELL_DEFENSIVE_STANCE                      53790

//OTHER SPELLS
#define SPELL_CHARGE_UP                             52098
#define SPELL_CLEAVE                                15284
#define SPELL_INTERCEPT                             58769
#define SPELL_IRONFORM                              52022
#define SPELL_KNOCK_AWAY                            52029
#define SPELL_MORTAL_STRIKE                         15708
#define SPELL_SLAM                                  52026
#define SPELL_SPELL_REFLECTION                      36096
#define SPELL_WHIRLWIND                             52027

//Yell
#define SAY_AGGRO                                -1602000
#define SAY_SLAY_1                               -1602001
#define SAY_SLAY_2                               -1602002
#define SAY_SLAY_3                               -1602003
#define SAY_DEATH                                -1602004
#define SAY_BATTLE_STANCE                        -1602005
#define SAY_BERSEKER_STANCE                      -1602006
#define SAY_DEFENSIVE_STANCE                     -1602007

struct TRINITY_DLL_DECL boss_bjarngrimAI : public ScriptedAI
{
    boss_bjarngrimAI(Creature *c) : ScriptedAI(c) {}

    uint32 whirlwind;
    
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

CreatureAI* GetAI_boss_bjarngrim(Creature *_Creature)
{
    return new boss_bjarngrimAI (_Creature);
}

void AddSC_boss_bjarngrim()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_bjarngrim";
    newscript->GetAI = GetAI_boss_bjarngrim;
    newscript->RegisterSelf();
}
