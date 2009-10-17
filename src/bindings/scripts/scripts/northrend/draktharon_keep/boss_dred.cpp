/* Script Data Start
SDName: Boss dred
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = '' where entry = '';
*** SQL END ***/
#include "precompiled.h"
#include "def_drak_tharon_keep.h"

enum Spells
{
    SPELL_BELLOWING_ROAR                     = 44863, // fears the group, can be resisted/dispelled
    SPELL_GRIEVOUS_BITE                      = 48920,
    SPELL_MANGLING_SLASH                     = 48873, //casted on the current tank, adds debuf
    SPELL_FEARSOME_ROAR                      = 48849,
    H_SPELL_FEARSOME_ROAR                    = 48849, //Not stacking, debuff
    SPELL_PIERCING_SLASH                     = 48878, //debuff -->Armor reduced by 75%
    SPELL_RAPTOR_CALL                        = 59416 //dummy
};

struct TRINITY_DLL_DECL boss_dredAI : public ScriptedAI
{
    boss_dredAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }
    
    ScriptedInstance* pInstance;

    void Reset()
    {
        if (pInstance)
            pInstance->SetData(DATA_DRED_EVENT,NOT_STARTED);
    }
    
    void EnterCombat(Unit* who)
    {
        if (pInstance)
            pInstance->SetData(DATA_DRED_EVENT,IN_PROGRESS);
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
            pInstance->SetData(DATA_DRED_EVENT,DONE);
    }
};

CreatureAI* GetAI_boss_dred(Creature* pCreature)
{
    return new boss_dredAI (pCreature);
}

void AddSC_boss_dred()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_dred";
    newscript->GetAI = &GetAI_boss_dred;
    newscript->RegisterSelf();
}
