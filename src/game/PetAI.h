/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
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
class Spell;

class TRINITY_DLL_DECL PetAI : public CreatureAI
{
    public:

        explicit PetAI(Creature *c);

        void EnterEvadeMode();
        void JustDied(Unit* who) { _stopAttack(); }

        void UpdateAI(const uint32);
        static int Permissible(const Creature *);

    private:
        bool _isVisible(Unit *) const;
        bool _needToStop(void) const;
        void _stopAttack(void);

        void UpdateAllies();

        TimeTracker i_tracker;
        bool inCombat;
        std::set<uint64> m_AllySet;
        uint32 m_updateAlliesTimer;

        typedef std::pair<Unit*, Spell*> TargetSpellPair;
        std::vector<TargetSpellPair> m_targetSpellStore;
};
#endif

