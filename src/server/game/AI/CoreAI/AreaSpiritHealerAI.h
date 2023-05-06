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

#ifndef AreaSpiritHealer_h__
#define AreaSpiritHealer_h__

#include "PassiveAI.h"
#include "TaskScheduler.h"

class Creature;

class TC_GAME_API AreaSpiritHealerAI : public NullCreatureAI
{
public:
    explicit AreaSpiritHealerAI(Creature* creature);
    explicit AreaSpiritHealerAI(Creature* creature, uint32 scriptId);

    static int32 Permissible(Creature const* creature);

    void SummonGraveyardTeleporter();
    void ScheduleSpiritHealChannel();

    void JustAppeared() override;
    void OnChannelFinished(SpellInfo const* spell) override;
    void OnDespawn() override;
    void UpdateAI(uint32 diff) override;

private:
    TaskScheduler _scheduler;
};

#endif
