/*
* Copyright (C) 2017-2018 Light's Hope <https://lightshope.org>
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef EVENT_PETAI_H
#define EVENT_PETAI_H

#include "CreatureEventAI.h"

// To be used by non-controllable pets (no pet bar) that require scripting.
// Like Guardian pets for example. If the creature has EventAI assigned,
// but is a pet, it will automatically be reassigned PetEventAI instead.

class PetEventAI : public CreatureEventAI
{
public:
    explicit PetEventAI(Creature* pCreature);
    ~PetEventAI() {}

    void MoveInLineOfSight(Unit* /*pWho*/) override;

    void AttackStart(Unit* /*pWho*/) override;

    void AttackedBy(Unit* /*pAttacker*/) override;

    void UpdateAI(uint32 const uiDiff) override;

    virtual void OwnerAttackedBy(Unit* /*attacker*/) override;

    virtual void OwnerAttacked(Unit* /*target*/) override;

    void MovementInform(uint32 type, uint32 id) override;

    static int Permissible(Creature const*);
private:
    bool FindTargetForAttack();
};

#endif
