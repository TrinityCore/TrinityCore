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

#ifndef TRINITY_UNITAI_H
#define TRINITY_UNITAI_H

#include "Platform/Define.h"

class Unit;
class Player;

class TRINITY_DLL_SPEC UnitAI
{
    protected:
        Unit * const me;
    public:
        explicit UnitAI(Unit *u) : me(u) {}
        virtual void AttackStart(Unit *);
        virtual void UpdateAI(const uint32 diff) = 0;

        virtual void InitializeAI() { Reset(); }

        virtual void Reset() {};

        // Called when unit is charmed
        virtual void OnCharmed(bool apply) = 0;

        // Pass parameters between AI
        virtual void DoAction(const int32 param) {}

        //Do melee swing of current victim if in rnage and ready and not casting
        void DoMeleeAttackIfReady();
};

class TRINITY_DLL_SPEC PlayerAI : public UnitAI
{
    protected:
        Player* const me;
    public:
        explicit PlayerAI(Player *p) : UnitAI((Unit*)p), me(p) {}

        void OnCharmed(bool apply);
};

class TRINITY_DLL_SPEC SimpleCharmedAI : public PlayerAI
{
    public:
        void UpdateAI(const uint32 diff);
};

#endif
