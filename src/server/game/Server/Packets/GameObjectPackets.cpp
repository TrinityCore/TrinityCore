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

#include "GameObjectPackets.h"

void WorldPackets::GameObject::GameObjUse::Read()
{
    _worldPacket >> Guid;
}

void WorldPackets::GameObject::GameObjReportUse::Read()
{
    _worldPacket >> Guid;
}

WorldPacket const* WorldPackets::GameObject::GameObjectDespawn::Write()
{
    _worldPacket << ObjectGUID;
    return &_worldPacket;
}

WorldPacket const* WorldPackets::GameObject::PageText::Write()
{
    _worldPacket << GameObjectGUID;
    return &_worldPacket;
}

WorldPacket const* WorldPackets::GameObject::GameObjectActivateAnimKit::Write()
{
    _worldPacket << ObjectGUID;
    _worldPacket << uint32(AnimKitID);
    _worldPacket.WriteBit(Maintain);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const * WorldPackets::GameObject::DestructibleBuildingDamage::Write()
{
    _worldPacket << Target;
    _worldPacket << Owner;
    _worldPacket << Caster;
    _worldPacket << int32(Damage);
    _worldPacket << int32(SpellID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::GameObject::GameObjectCustomAnim::Write()
{
    _worldPacket << ObjectGUID;
    _worldPacket << uint32(CustomAnim);
    _worldPacket.WriteBit(PlayAsDespawn);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::GameObject::GameObjectUIAction::Write()
{
    _worldPacket << ObjectGUID;
    _worldPacket << int32(UILink);

    return &_worldPacket;
}
