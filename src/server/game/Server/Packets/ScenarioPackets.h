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
#include "AchievementPackets.h"
#include "QueryPackets.h"

namespace WorldPackets
{
    namespace Scenario
    {	
		struct BonusObjectiveData
		{
		    int32 Id = 0;
			bool ObjectiveCompleted = false;
        };
		
        struct UnkScenarioStateData
        {
            uint32 Unk1 = 0;
            bool Unk2 = true;
        };

        class ScenarioState final : public ServerPacket
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
                std::vector<WorldPackets::Achievement::CriteriaProgress> CriteriaProgress;
                std::vector<BonusObjectiveData> BonusObjectiveData;
                std::vector<uint32> TraversedSteps; // Speculated data
                std::vector<UnkScenarioStateData> UnkData;
                bool ScenarioCompleted = false;
        };

        class ScenarioProgressUpdate final : public ServerPacket
        {
            public:
                ScenarioProgressUpdate() : ServerPacket(SMSG_SCENARIO_PROGRESS_UPDATE) { }

                WorldPacket const* Write() override;

                WorldPackets::Achievement::CriteriaProgress CriteriaProgress;
        };

        class ScenarioCompleted final : public ServerPacket
        {
            public:
                ScenarioCompleted(uint32 scenarioId) : ServerPacket(SMSG_SCENARIO_COMPLETED, 4), ScenarioId(scenarioId) { }

                WorldPacket const* Write() override;

                uint32 ScenarioId = 0;
        };

        class ScenarioBoot final : public ServerPacket
        {
            public:
                ScenarioBoot() : ServerPacket(SMSG_SCENARIO_BOOT, 4 + 4 + 1) { }

                WorldPacket const* Write() override;

                int32 ScenarioId = 0;
                // 40 bit section with default 0 values, not really sure what this is or in what order they come but most likely a int32 and a boolean.
                int32 Unk1 = 0;
                bool Unk2 = 0;
        };

        class QueryScenarioPOI final : public ClientPacket
        {
        public:
            QueryScenarioPOI(WorldPacket&& packet) : ClientPacket(CMSG_QUERY_SCENARIO_POI, std::move(packet)) { }

            void Read() override;

            std::vector<int32> MissingScenarioPOIs;
        };

        class ScenarioPOIs final : public ServerPacket
        {
        public:
            ScenarioPOIs() : ServerPacket(SMSG_SCENARIO_POIS) { }

            WorldPacket const* Write() override;

            std::vector<WorldPackets::Query::ScenarioPOIData> ScenarioPOIDataStats;
        };
    }
}

#endif // ScenarioPackets_h__
