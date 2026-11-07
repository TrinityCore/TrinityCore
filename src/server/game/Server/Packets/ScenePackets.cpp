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
#include "PacketOperators.h"

namespace WorldPackets::Scenes
{
WorldPacket const* PlayScene::Write()
{
    _worldPacket << int32(SceneID);
    _worldPacket << uint32(PlaybackFlags);
    _worldPacket << uint32(SceneInstanceID);
    _worldPacket << int32(SceneScriptPackageID);
    _worldPacket << TransportGUID;
    _worldPacket << Location;
    _worldPacket << int32(MovieID);
    _worldPacket << Bits<1>(Encrypted);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* CancelScene::Write()
{
    _worldPacket << int32(SceneInstanceID);

    return &_worldPacket;
}

void SceneTriggerEvent::Read()
{
    _worldPacket >> SizedString::BitsSize<6>(Event);
    _worldPacket >> SceneInstanceID;

    _worldPacket >> SizedString::Data(Event);
}

void ScenePlaybackComplete::Read()
{
    _worldPacket >> SceneInstanceID;
    _worldPacket >> TimePassed;
}

void ScenePlaybackCanceled::Read()
{
    _worldPacket >> SceneInstanceID;
    _worldPacket >> TimePassed;
}
}
