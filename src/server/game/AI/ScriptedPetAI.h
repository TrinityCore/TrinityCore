/*
* Copyright (C) 2012-2012 Anathema Engine project <http://valkyrie-wow.com/>
* Copyright (C) 2005-2012 MaNGOS <http://getmangos.com/>
*/

#ifndef SCRIPTED_PETAI_H
#define SCRIPTED_PETAI_H

#include "ScriptedAI.h"

// Using CreatureAI for now. Might change later and use PetAI (need to export for dll first)
class ScriptedPetAI : public CreatureAI
{
public:
    explicit ScriptedPetAI(Creature* pCreature);
    ~ScriptedPetAI() override {}

    void MoveInLineOfSight(Unit* /*pWho*/) override;

    void AttackStart(Unit* /*pWho*/) override;

    void AttackedBy(Unit* /*pAttacker*/) override;

    void KilledUnit(Unit* /*pVictim*/) override {}

    void OwnerKilledUnit(Unit* /*pVictim*/) override {}

    void JustRespawned() override;

    void UpdateAI(uint32 const uiDiff) override;

    virtual void Reset() {}

    virtual void ResetCreature() {}

    virtual void UpdatePetAI(uint32 const uiDiff);      // while in combat

    virtual void UpdatePetOOCAI(uint32 const uiDiff) {} // when not in combat

protected:
    void ResetPetCombat();
};

#endif
