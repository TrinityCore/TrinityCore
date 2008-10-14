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

#ifndef TRINITY_PETAI_H
#define TRINITY_PETAI_H

#include "CreatureAI.h"
#include "Timer.h"

class Creature;

class TRINITY_DLL_DECL PetAI : public CreatureAI
{
    public:

        PetAI(Creature &c);

        void MoveInLineOfSight(Unit *);
        void AttackStart(Unit *);
        void EnterEvadeMode();
        void DamageTaken(Unit *done_by, uint32& /*damage*/) { AttackedBy(done_by); }
        void AttackedBy(Unit*);
        bool IsVisible(Unit *) const;

        void UpdateAI(const uint32);
        void UpdateAllies();
        static int Permissible(const Creature *);

    private:
        bool _isVisible(Unit *) const;
        bool _needToStop(void) const;
        void _stopAttack(void);

        Creature &i_pet;
        uint64 i_victimGuid;
        TimeTracker i_tracker;
        //uint32 i_RepeatAction;
        std::set<uint64> m_AllySet;
        uint32 m_updateAlliesTimer;
};
#endif
