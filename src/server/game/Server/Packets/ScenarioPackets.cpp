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

#include "ScenarioPackets.h"
#include "AchievementPackets.h"
#include "QueryPackets.h"

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Scenario::BonusObjectiveData const& bonusObjective)
{
    data << int32(bonusObjective.Id);
    data << uint8(bonusObjective.ObjectiveCompleted);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Scenario::UnkScenarioStateData const& unkData)
{
    data << uint32(unkData.Unk1);
    data << uint8(unkData.Unk2);
    return data;
}

WorldPacket const* WorldPackets::Scenario::ScenarioState::Write()
{
    _worldPacket << uint32(ScenarioId);
    _worldPacket << int32(CurrentStep);
    _worldPacket << int32(DifficultyId);
    _worldPacket << int32(WaveCurrent);
    _worldPacket << int32(WaveMax);
    _worldPacket << int32(TimerDuration);
    _worldPacket << uint32(CriteriaProgress.size());
    _worldPacket << uint32(BonusObjectiveData.size());
    _worldPacket << uint32(TraversedSteps.size());
    _worldPacket << uint32(UnkData.size());

    for (uint32 i = 0; i < TraversedSteps.size(); ++i)
        _worldPacket << uint32(TraversedSteps[i]);

    _worldPacket.WriteBit(ScenarioCompleted);
    _worldPacket.FlushBits();

   for (WorldPackets::Achievement::CriteriaProgress const& progress : CriteriaProgress)
       _worldPacket << progress;

   for (WorldPackets::Scenario::BonusObjectiveData const& bonusObjective : BonusObjectiveData)
       _worldPacket << bonusObjective;

   for (WorldPackets::Scenario::UnkScenarioStateData const& unkData : UnkData)
       _worldPacket << unkData;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Scenario::ScenarioProgressUpdate::Write()
{
    _worldPacket << CriteriaProgress;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Scenario::ScenarioCompleted::Write()
{
    _worldPacket << ScenarioId;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Scenario::ScenarioBoot::Write()
{
    _worldPacket << int32(ScenarioId);
    _worldPacket << int32(Unk1);
    _worldPacket.WriteBit(Unk2);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

void WorldPackets::Scenario::QueryScenarioPOI::Read()
{
    MissingScenarioPOIs.resize(_worldPacket.read<uint32>());
    for (int32& scenarioPOI : MissingScenarioPOIs)
        _worldPacket >> scenarioPOI;
}

WorldPacket const* WorldPackets::Scenario::ScenarioPOIs::Write()
{
    _worldPacket << int32(ScenarioPOIDataStats.size());

    for (Query::ScenarioPOIData const& scenarioPOIData : ScenarioPOIDataStats)
    {
        _worldPacket << int32(scenarioPOIData.CriteriaTreeID);

        _worldPacket << int32(scenarioPOIData.ScenarioPOIs.size());
        for (ScenarioPOI const* scenarioPOI : scenarioPOIData.ScenarioPOIs)
        {
            _worldPacket << int32(scenarioPOI->BlobIndex);
            _worldPacket << int32(scenarioPOI->MapID);
            _worldPacket << int32(scenarioPOI->WorldMapAreaID);
            _worldPacket << int32(scenarioPOI->Floor);
            _worldPacket << int32(scenarioPOI->Priority);
            _worldPacket << int32(scenarioPOI->Flags);
            _worldPacket << int32(scenarioPOI->WorldEffectID);
            _worldPacket << int32(scenarioPOI->PlayerConditionID);

            _worldPacket << int32(scenarioPOI->Points.size());
            for (ScenarioPOIPoint const& scenarioPOIBlobPoint : scenarioPOI->Points)
            {
                _worldPacket << int32(scenarioPOIBlobPoint.X);
                _worldPacket << int32(scenarioPOIBlobPoint.Y);
            }
        }
    }

    return &_worldPacket;
}
