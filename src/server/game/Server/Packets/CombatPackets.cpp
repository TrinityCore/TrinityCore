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

#include "CombatPackets.h"
#include "Unit.h"

void WorldPackets::Combat::AttackSwing::Read()
{
    _worldPacket >> Victim;
}

WorldPacket const* WorldPackets::Combat::AttackStart::Write()
{
    _worldPacket << Attacker;
    _worldPacket << Victim;

    return &_worldPacket;
}

WorldPackets::Combat::SAttackStop::SAttackStop(Unit const* attacker, Unit const* victim) : ServerPacket(SMSG_ATTACK_STOP, 8 + 8 + 4)
{
    Attacker = attacker->GetPackGUID();
    if (victim)
    {
        Victim = victim->GetPackGUID();
        NowDead = victim->isDead();
    }
}

WorldPacket const* WorldPackets::Combat::SAttackStop::Write()
{
    _worldPacket << Attacker;
    _worldPacket << Victim;
    _worldPacket << uint32(NowDead);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Combat::CancelAutoRepeat::Write()
{
    _worldPacket << Guid;

    return &_worldPacket;
}

void WorldPackets::Combat::SetSheathed::Read()
{
    _worldPacket >> CurrentSheathState;
}
