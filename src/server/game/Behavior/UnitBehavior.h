/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TRINITY_UNITBEHAVIOR_H
#define TRINITY_UNITBEHAVIOR_H

#include "Duration.h"

class Unit;

class TC_GAME_API UnitBehavior
{
    private:
        void LookForAutoEngage();
        void UpdatePrimaryTargetFromThreat();
        void UpdateAutoAttackState();

    public:
        UnitBehavior(Unit* owner);
        
        void Engage();
        void Update();

        bool ShouldAutoEngage() const { return true; }
        bool ShouldAutoAttack() const { return true; }
        bool ShouldTargetFromThreat() const { return true; }
        bool ShouldEvadeWithoutTargets() const { return true; }

        void SetPrimaryTarget(Unit* target) { _primaryTarget = target; }
        Unit* GetPrimaryTarget() const { return _primaryTarget; }
    
    private:
        Unit* const _owner;
        Unit* _primaryTarget = nullptr;
}

#endif
