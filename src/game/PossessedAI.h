/*
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
 *
 * Thanks to the original authors: MaNGOS <http://www.mangosproject.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef MANGOS_POSSESSEDAI_H
#define MANGOS_POSSESSEDAI_H

#include "CreatureAI.h"

class Creature;

class TRINITY_DLL_DECL PossessedAI : public CreatureAI
{
    public:
        PossessedAI(Creature *c) : i_pet(*c), i_victimGuid(0) {}

        // Possessed creatures shouldn't aggro by themselves
        void MoveInLineOfSight(Unit *) {}
        void AttackStart(Unit *);
        void EnterEvadeMode() {}
        void JustDied(Unit*);
        void KilledUnit(Unit* victim);
        bool IsVisible(Unit * u) const { return _isVisible(u); }

        void UpdateAI(const uint32);
        // Never permit this to be used, it must always be initialized with Creature::InitPossessedAI()
        static int Permissible(const Creature *) { return PERMIT_BASE_NO; }

    private:
        bool _isVisible(Unit *) const;
        bool _needToStop(void) const;
        void _stopAttack(void);

        Creature &i_pet;
        uint64 i_victimGuid;
};
#endif
