/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
 * Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
 * Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
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

#ifndef MANGOS_PETAI_H
#define MANGOS_PETAI_H

#include "CreatureAI.h"

class Creature;
class Spell;

enum ePetSelectTargetReason : uint8
{
    PSTR_FAIL_DEFAULT,
    PSTR_FAIL_NOT_ENABLED,
    PSTR_FAIL_PASSIVE,
    PSTR_FAIL_NO_OWNER,
    PSTR_FAIL_RETURNING,
    PSTR_SUCCESS_OWNER_ATTACKER,
    PSTR_SUCCESS_AGGRO_RANGE,
};

class PetAI : public CreatureAI
{
    public:

        explicit PetAI(Creature* c);

        void MoveInLineOfSight(Unit*) {}
        void EnterEvadeMode() {}

        void KilledUnit(Unit* /*victim*/);
        void AttackStart(Unit* target);
        void MovementInform(uint32 moveType, uint32 data);
        void OwnerAttackedBy(Unit* attacker);
        void OwnerAttacked(Unit* target);
        void AttackedBy(Unit* attacker);

        void UpdateAI(uint32 const);
        static int Permissible(Creature const*);

    private:
        bool _needToStop() const;
        void _stopAttack();

        void UpdateAllies();

        bool hasMelee;
        std::set<uint64> m_AllySet;
        uint32 m_updateAlliesTimer;

        std::pair<Unit*, ePetSelectTargetReason> SelectNextTarget(bool allowAutoSelect) const;
        void HandleReturnMovement();
        void DoAttack(Unit* target, bool chase);
        bool CanAttack(Unit* target);
        void ClearCharmInfoFlags();
};
#endif
