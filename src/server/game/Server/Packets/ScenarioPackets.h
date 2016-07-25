/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#ifndef ScenarioPackets_h__
#define ScenarioPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"
#include "WorldSession.h"

namespace WorldPackets
{
    namespace Scenario
    {
        struct CriteriaProgress
        {
            uint32 Id = 0;
			uint64 Quantity = 0;
			ObjectGuid Player;
			time_t Date = time_t(0);
            uint32 TimeStart = 0;
            uint32 TimeCreate = 0;
			uint32 Flags = 0;
        };
		
		struct BonusObjectiveData
		{
		    int32 Id = 0;
			bool ObjectiveCompleted = false;
        };
		
        class ScenarioState final : public WorldPackets::ServerPacket
        {
            public:
                ScenarioState() : ServerPacket(SMSG_SCENARIO_STATE) { }

                WorldPacket const* Write() override;

                int32 ScenarioId = 0;
				int32 CurrentStep = -1;
				int32 DifficultyId = 0;
				int32 WaveCurrent = 0;
				int32 WaveMax = 0;
				int32 TimerDuration = 0;
                std::vector<CriteriaProgress> CriteriaProgress;
                std::vector<BonusObjectiveData> BonusObjectiveData;
				bool ScenarioCompleted = false;
        };

        class ScenarioProgressUpdate final : public WorldPackets::ServerPacket
        {
            public:
                ScenarioProgressUpdate() : ServerPacket(SMSG_SCENARIO_PROGRESS_UPDATE) { }

                WorldPacket const* Write() override;

                CriteriaProgress criteriaProgress;
        };

        class ScenarioCompleted final : public WorldPackets::ServerPacket
        {
            public:
                ScenarioCompleted(uint32 scenarioId) : ScenarioId(scenarioId), ServerPacket(SMSG_SCENARIO_COMPLETED, 4) { }

                WorldPacket const* Write() override;

                uint32 ScenarioId = 0;
        };

        class ScenarioBoot final : public WorldPackets::ServerPacket
        {
            public:
                ScenarioBoot() : ServerPacket(SMSG_SCENARIO_BOOT, 0) { }

                WorldPacket const* Write() override { return &_worldPacket; }
        };
    }
}

#endif // ScenarioPackets_h__
