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

#ifndef TRINITY_NULLCREATUREAI_H
#define TRINITY_NULLCREATUREAI_H

#include "CreatureAI.h"
#include "CreatureAIImpl.h"

class TRINITY_DLL_DECL PassiveAI : public CreatureAI
{
    public:
        explicit PassiveAI(Creature *c) : CreatureAI(c) {}

        void MoveInLineOfSight(Unit *) {}
        void AttackStart(Unit *) {}
        void UpdateAI(const uint32);

        static int Permissible(const Creature *) { return PERMIT_BASE_IDLE;  }
};

class TRINITY_DLL_DECL PossessedAI : public CreatureAI
{
    public:
        explicit PossessedAI(Creature *c) : CreatureAI(c) {}

        void MoveInLineOfSight(Unit *) {}
        void AttackStart(Unit *target);
        void UpdateAI(const uint32);
        void EnterEvadeMode() {}

        void JustDied(Unit*);
        void KilledUnit(Unit* victim);

        static int Permissible(const Creature *) { return PERMIT_BASE_IDLE;  }
};

class TRINITY_DLL_DECL NullCreatureAI : public CreatureAI
{
    public:
        explicit NullCreatureAI(Creature *c) : CreatureAI(c) {}

        void MoveInLineOfSight(Unit *) {}
        void AttackStart(Unit *) {}
        void UpdateAI(const uint32) {}
        void EnterEvadeMode() {}
        void OnCharmed(bool apply) {}

        static int Permissible(const Creature *) { return PERMIT_BASE_IDLE;  }
};

class TRINITY_DLL_DECL CritterAI : public PassiveAI
{
    public:
        explicit CritterAI(Creature *c) : PassiveAI(c) {}

        void DamageTaken(Unit *done_by, uint32 & /*damage*/);
        void EnterEvadeMode();
};

class TRINITY_DLL_DECL TriggerAI : public NullCreatureAI
{
    public:
        explicit TriggerAI(Creature *c) : NullCreatureAI(c), casted(false) {}
        void UpdateAI(const uint32);
    private:
        bool casted;
};

#endif

