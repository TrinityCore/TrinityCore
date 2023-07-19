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

#ifndef TRINITYCORE_TRAIT_PACKETS_H
#define TRINITYCORE_TRAIT_PACKETS_H

#include "Packet.h"
#include "TraitPacketsCommon.h"

namespace WorldPackets::Traits
{
class TraitsCommitConfig final : public ClientPacket
{
public:
    explicit TraitsCommitConfig(WorldPacket&& packet) : ClientPacket(CMSG_TRAITS_COMMIT_CONFIG, std::move(packet)) { }

    void Read() override;

    TraitConfig Config;
    int32 SavedConfigID = 0;
    int32 SavedLocalIdentifier = 0;
};

class TraitConfigCommitFailed final : public ServerPacket
{
public:
    TraitConfigCommitFailed(int32 configId = 0, int32 spellId = 0, int32 reason = 0) : ServerPacket(SMSG_TRAIT_CONFIG_COMMIT_FAILED, 4 + 4 + 1),
        ConfigID(configId), SpellID(spellId), Reason(reason) { }

    WorldPacket const* Write() override;

    int32 ConfigID;
    int32 SpellID;
    int32 Reason;
};

class ClassTalentsRequestNewConfig final : public ClientPacket
{
public:
    explicit ClassTalentsRequestNewConfig(WorldPacket&& packet) : ClientPacket(CMSG_CLASS_TALENTS_REQUEST_NEW_CONFIG, std::move(packet)) { }

    void Read() override;

    TraitConfig Config;
};

class ClassTalentsRenameConfig final : public ClientPacket
{
public:
    explicit ClassTalentsRenameConfig(WorldPacket&& packet) : ClientPacket(CMSG_CLASS_TALENTS_RENAME_CONFIG, std::move(packet)) { }

    void Read() override;

    int32 ConfigID = 0;
    String<259> Name;
};

class ClassTalentsDeleteConfig final : public ClientPacket
{
public:
    explicit ClassTalentsDeleteConfig(WorldPacket&& packet) : ClientPacket(CMSG_CLASS_TALENTS_DELETE_CONFIG, std::move(packet)) { }

    void Read() override;

    int32 ConfigID = 0;
};

class ClassTalentsSetStarterBuildActive final : public ClientPacket
{
public:
    explicit ClassTalentsSetStarterBuildActive(WorldPacket&& packet) : ClientPacket(CMSG_CLASS_TALENTS_SET_STARTER_BUILD_ACTIVE, std::move(packet)) { }

    void Read() override;

    int32 ConfigID = 0;
    bool Active = false;
};

class ClassTalentsSetUsesSharedActionBars final : public ClientPacket
{
public:
    explicit ClassTalentsSetUsesSharedActionBars(WorldPacket&& packet) : ClientPacket(CMSG_CLASS_TALENTS_SET_USES_SHARED_ACTION_BARS, std::move(packet)) { }

    void Read() override;

    int32 ConfigID = 0;
    bool UsesShared = false;
    bool IsLastSelectedSavedConfig = false;
};
}

#endif // TRINITYCORE_TRAIT_PACKETS_H
