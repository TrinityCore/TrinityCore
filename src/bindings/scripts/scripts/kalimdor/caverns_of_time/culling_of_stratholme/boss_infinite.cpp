#include "precompiled.h"
#include "def_culling_of_stratholme.h"

enum Spells
{
    SPELL_CORRUPTING_BLIGHT           = 60588,
    SPELL_VOID_STRIKE                 = 60590
};

struct TRINITY_DLL_DECL boss_infiniteAI : public ScriptedAI
{
    boss_infiniteAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }
    
    ScriptedInstance* pInstance;

    void Reset()
    {
        if (pInstance)
            pInstance->SetData(DATA_INFINITE_EVENT, NOT_STARTED);
    }
    
    void EnterCombat(Unit* who)
    {
        if (pInstance)
            pInstance->SetData(DATA_INFINITE_EVENT, IN_PROGRESS);
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
        if (pInstance)
            pInstance->SetData(DATA_INFINITE_EVENT, DONE);
    }
};

CreatureAI* GetAI_boss_infinite(Creature* pCreature)
{
    return new boss_infiniteAI (pCreature);
}

void AddSC_infinite_epoch()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_infinite";
    newscript->GetAI = &GetAI_boss_infinite;
    newscript->RegisterSelf();
}