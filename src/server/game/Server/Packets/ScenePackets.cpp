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

#include "ScenePackets.h"

WorldPacket const* WorldPackets::Scenes::PlayScene::Write()
{
    _worldPacket << int32(SceneID);
    _worldPacket << uint32(PlaybackFlags);
    _worldPacket << uint32(SceneInstanceID);
    _worldPacket << int32(SceneScriptPackageID);
    _worldPacket << TransportGUID;
    _worldPacket << Location.PositionXYZOStream();
    _worldPacket.WriteBit(Encrypted);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Scenes::CancelScene::Write()
{
    _worldPacket << int32(SceneInstanceID);

    return &_worldPacket;
}

void WorldPackets::Scenes::SceneTriggerEvent::Read()
{
    uint32 len = _worldPacket.ReadBits(6);
    _worldPacket >> SceneInstanceID;
    Event = _worldPacket.ReadString(len);
}

void WorldPackets::Scenes::ScenePlaybackComplete::Read()
{
    _worldPacket >> SceneInstanceID;
    _worldPacket >> TimePassed;
}

void WorldPackets::Scenes::ScenePlaybackCanceled::Read()
{
    _worldPacket >> SceneInstanceID;
    _worldPacket >> TimePassed;
}
