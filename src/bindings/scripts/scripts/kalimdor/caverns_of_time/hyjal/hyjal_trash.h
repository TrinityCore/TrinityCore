
#ifndef SC_HYJAL_TRASH_AI_H
#define SC_HYJAL_TRASH_AI_H

#include "def_hyjal.h"
#include "escort_ai.h"

#define MINRAIDDAMAGE  700000//minimal damage before trash can drop loot and reputation, resets if faction leader dies

struct TRINITY_DLL_DECL hyjal_trashAI : public npc_escortAI
{
    hyjal_trashAI(Creature *c);

    void UpdateAI(const uint32 diff);

    void JustDied(Unit* killer);

    void DamageTaken(Unit *done_by, uint32 &damage);

    public:
        ScriptedInstance* pInstance;
        bool IsEvent;
        uint32 Delay;
        uint32 LastOverronPos;
        bool IsOverrun;
        bool SetupOverrun;
        uint32 OverrunType;
        uint8 faction;
        bool useFlyPath;
        uint32 damageTaken;
        float DummyTarget[3];

    //private:
};
#endif
