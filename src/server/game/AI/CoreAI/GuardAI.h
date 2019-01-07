/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef TRINITY_GUARDAI_H
#define TRINITY_GUARDAI_H

#include "ScriptedCreature.h"

class Creature;

class TC_GAME_API GuardAI : public ScriptedAI
{
    public:
        explicit GuardAI(Creature* creature);

        static int Permissible(Creature const* creature);
        void UpdateAI(uint32 diff) override;
        bool CanSeeAlways(WorldObject const* obj) override;

        void EnterEvadeMode(EvadeReason /*why*/) override;
        void JustDied(Unit* killer) override;
};
#endif
