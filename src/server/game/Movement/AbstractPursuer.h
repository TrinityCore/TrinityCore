/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#ifndef TRINITY_ABSTRACTPURSUER_H
#define TRINITY_ABSTRACTPURSUER_H

#include "SharedDefines.h"

class Unit;

struct AbstractPursuer
{
    public:
        AbstractPursuer(PursuingType type, Unit* target = nullptr);
        ~AbstractPursuer() { SetTarget(_type, nullptr); }

        void SetTarget(PursuingType type, Unit* target);
        Unit* GetTarget() const { return _target; }
    
    private:
        Unit* _target = nullptr;
        PursuingType _type;
};

#endif // TRINITY_ABSTRACTPURSUER_H
