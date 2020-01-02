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

#include "ScenarioPackets.h"
#include "ScenarioMgr.h"

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Scenario::BonusObjectiveData const& bonusObjective)
{
    data << int32(bonusObjective.BonusObjectiveID);
    data.WriteBit(bonusObjective.ObjectiveComplete);
    data.FlushBits();
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Scenario::ScenarioSpellUpdate const& spell)
{
    data << uint32(spell.SpellID);
    data.WriteBit(spell.Usable);
    data.FlushBits();
    return data;
}

WorldPacket const* WorldPackets::Scenario::ScenarioState::Write()
{
    _worldPacket << int32(ScenarioID);
    _worldPacket << int32(CurrentStep);
    _worldPacket << uint32(DifficultyID);
    _worldPacket << uint32(WaveCurrent);
    _worldPacket << uint32(WaveMax);
    _worldPacket << uint32(TimerDuration);
    _worldPacket << uint32(CriteriaProgress.size());
    _worldPacket << uint32(BonusObjectives.size());
    _worldPacket << uint32(PickedSteps.size());
    _worldPacket << uint32(Spells.size());

    for (uint32 i = 0; i < PickedSteps.size(); ++i)
        _worldPacket << uint32(PickedSteps[i]);

    _worldPacket.WriteBit(ScenarioComplete);
    _worldPacket.FlushBits();

   for (WorldPackets::Achievement::CriteriaProgress const& progress : CriteriaProgress)
       _worldPacket << progress;

   for (WorldPackets::Scenario::BonusObjectiveData const& bonusObjective : BonusObjectives)
       _worldPacket << bonusObjective;

   for (WorldPackets::Scenario::ScenarioSpellUpdate const& spell : Spells)
       _worldPacket << spell;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Scenario::ScenarioProgressUpdate::Write()
{
    _worldPacket << CriteriaProgress;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Scenario::ScenarioCompleted::Write()
{
    _worldPacket << uint32(ScenarioID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Scenario::ScenarioBoot::Write()
{
    _worldPacket << int32(ScenarioID);
    _worldPacket << int32(Unk1);
    _worldPacket.WriteBits(Unk2, 2);
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
    _worldPacket << uint32(ScenarioPOIDataStats.size());

    for (ScenarioPOIData const& scenarioPOIData : ScenarioPOIDataStats)
    {
        _worldPacket << int32(scenarioPOIData.CriteriaTreeID);
        _worldPacket << uint32(scenarioPOIData.ScenarioPOIs->size());

        for (ScenarioPOI const& scenarioPOI : *scenarioPOIData.ScenarioPOIs)
        {
            _worldPacket << int32(scenarioPOI.BlobIndex);
            _worldPacket << int32(scenarioPOI.MapID);
            _worldPacket << int32(scenarioPOI.UiMapID);
            _worldPacket << int32(scenarioPOI.Priority);
            _worldPacket << int32(scenarioPOI.Flags);
            _worldPacket << int32(scenarioPOI.WorldEffectID);
            _worldPacket << int32(scenarioPOI.PlayerConditionID);
            _worldPacket << uint32(scenarioPOI.Points.size());

            for (ScenarioPOIPoint const& scenarioPOIBlobPoint : scenarioPOI.Points)
            {
                _worldPacket << int32(scenarioPOIBlobPoint.X);
                _worldPacket << int32(scenarioPOIBlobPoint.Y);
            }
        }
    }

    return &_worldPacket;
}
