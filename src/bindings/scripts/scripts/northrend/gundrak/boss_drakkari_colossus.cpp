/* Script Data Start
SDName: Boss Drakkari Colossus
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = '' where entry = '';
*** SQL END ***/
#include "precompiled.h"
#include "def_gundrak.h"

//Spells
#define SPELL_EMERGE                                          54850 //to phase2, Colossus unatackable, Elemental emerges
#define SPELL_EMERGE_2                                        54851
#define SPELL_MIGHTY_BLOW                                     54719

struct TRINITY_DLL_DECL boss_drakkari_colossusAI : public ScriptedAI
{
    boss_drakkari_colossusAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }
    
    ScriptedInstance* pInstance;

    void Reset()
    {
        if (pInstance)
            pInstance->SetData(DATA_DRAKKARI_COLOSSUS_EVENT, NOT_STARTED);
    }
    
    void EnterCombat(Unit* who)
    {
        if (pInstance)
            pInstance->SetData(DATA_DRAKKARI_COLOSSUS_EVENT, IN_PROGRESS);
    }
    
    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;
        
        DoMeleeAttackIfReady();
    }
    
    void JustDied(Unit* killer) 
    {
        if (pInstance)
            pInstance->SetData(DATA_DRAKKARI_COLOSSUS_EVENT, DONE);
    }
};

CreatureAI* GetAI_boss_drakkari_colossus(Creature* pCreature)
{
    return new boss_drakkari_colossusAI (pCreature);
}

void AddSC_boss_drakkari_colossus()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_drakkari_colossus";
    newscript->GetAI = &GetAI_boss_drakkari_colossus;
    newscript->RegisterSelf();
}
