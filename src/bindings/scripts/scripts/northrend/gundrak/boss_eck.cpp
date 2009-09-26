/* Script Data Start
SDName: Boss Eck the Ferocious
SDAuthor: LordVanMartin
SD%Complete:
SDComment: Only appears in Heroic mode
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = '' where entry = '';
*** SQL END ***/
#include "precompiled.h"
#include "def_gundrak.h"

#define SPELL_ECK_BERSERK                       55816 //Eck goes berserk, increasing his attack speed by 150% and all damage he deals by 500%.
#define SPELL_ECK_BITE                          55813 //Eck bites down hard, inflicting 150% of his normal damage to an enemy.
#define SPELL_ECK_SPIT                          55814 //Eck spits toxic bile at enemies in a cone in front of him, inflicting 2970 Nature damage and draining 220 mana every 1 sec for 3 sec.
#define SPELL_ECK_SPRING_1                      55815 //Eck leaps at a distant target.  --> Drops aggro and charges a random player. Tank can simply taunt him back.
#define SPELL_ECK_SPRING_2                      55837 //Eck leaps at a distant target.

struct TRINITY_DLL_DECL boss_eckAI : public ScriptedAI
{
    boss_eckAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiBerserkTimer;
    
    ScriptedInstance* pInstance;

    void Reset()
    {
        //Source Deadly Boss Mod
        uiBerserkTimer = 120000; //2min
        
        if (pInstance)
            pInstance->SetData(DATA_ECK_THE_FEROCIOUS_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit* who)
    {
        if (pInstance)
            pInstance->SetData(DATA_ECK_THE_FEROCIOUS_EVENT, IN_PROGRESS);
    }
    
    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (uiBerserkTimer < diff)
        {
            DoCast(m_creature,SPELL_ECK_BERSERK);
            uiBerserkTimer = 120000;
        }else uiBerserkTimer -= diff;

        DoMeleeAttackIfReady();
    }
    
    void JustDied(Unit* killer)  
    {
        if (pInstance)
            pInstance->SetData(DATA_ECK_THE_FEROCIOUS_EVENT, DONE);
    }
};

CreatureAI* GetAI_boss_eck(Creature* pCreature)
{
    return new boss_eckAI (pCreature);
}

void AddSC_boss_eck()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_eck";
    newscript->GetAI = &GetAI_boss_eck;
    newscript->RegisterSelf();
}
