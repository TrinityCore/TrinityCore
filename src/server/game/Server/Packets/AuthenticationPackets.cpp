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

#include "AuthenticationPackets.h"
#include "BigNumber.h"
#include "CharacterTemplateDataStore.h"
#include "Ed25519.h"
#include "HMAC.h"
#include "ObjectMgr.h"
#include "RSA.h"

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Auth::VirtualRealmNameInfo const& virtualRealmInfo)
{
    data.WriteBit(virtualRealmInfo.IsLocal);
    data.WriteBit(virtualRealmInfo.IsInternalRealm);
    data.WriteBits(virtualRealmInfo.RealmNameActual.length(), 8);
    data.WriteBits(virtualRealmInfo.RealmNameNormalized.length(), 8);
    data.FlushBits();

    data.WriteString(virtualRealmInfo.RealmNameActual);
    data.WriteString(virtualRealmInfo.RealmNameNormalized);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Auth::VirtualRealmInfo const& virtualRealmInfo)
{
    data << uint32(virtualRealmInfo.RealmAddress);
    data << virtualRealmInfo.RealmNameInfo;

    return data;
}

bool WorldPackets::Auth::EarlyProcessClientPacket::ReadNoThrow()
{
    try
    {
        Read();
        return true;
    }
    catch (ByteBufferException const& /*ex*/)
    {
    }

    return false;
}

void WorldPackets::Auth::Ping::Read()
{
    _worldPacket >> Serial;
    _worldPacket >> Latency;
}

const WorldPacket* WorldPackets::Auth::Pong::Write()
{
    _worldPacket << uint32(Serial);
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Auth::AuthChallenge::Write()
{
    _worldPacket.append(DosChallenge.data(), DosChallenge.size());
    _worldPacket.append(Challenge.data(), Challenge.size());
    _worldPacket << uint8(DosZeroBits);
    return &_worldPacket;
}

void WorldPackets::Auth::AuthSession::Read()
{
    uint32 realmJoinTicketSize;

    _worldPacket >> DosResponse;
    _worldPacket >> RegionID;
    _worldPacket >> BattlegroupID;
    _worldPacket >> RealmID;
    _worldPacket.read(LocalChallenge.data(), LocalChallenge.size());
    _worldPacket.read(Digest.data(), Digest.size());
    UseIPv6 = _worldPacket.ReadBit();
    _worldPacket >> realmJoinTicketSize;
    if (realmJoinTicketSize)
    {
        RealmJoinTicket.resize(std::min(realmJoinTicketSize, uint32(_worldPacket.size() - _worldPacket.rpos())));
        _worldPacket.read(reinterpret_cast<uint8*>(&RealmJoinTicket[0]), RealmJoinTicket.size());
    }
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Auth::AuthWaitInfo const& waitInfo)
{
    data << uint32(waitInfo.WaitCount);
    data << uint32(waitInfo.WaitTime);
    data << uint32(waitInfo.AllowedFactionGroupForCharacterCreate);
    data.WriteBit(waitInfo.HasFCM);
    data.WriteBit(waitInfo.CanCreateOnlyIfExisting);
    data.FlushBits();

    return data;
}

WorldPacket const* WorldPackets::Auth::AuthResponse::Write()
{
    _worldPacket << uint32(Result);
    _worldPacket.WriteBit(SuccessInfo.has_value());
    _worldPacket.WriteBit(WaitInfo.has_value());
    _worldPacket.FlushBits();

    if (SuccessInfo)
    {
        _worldPacket << uint32(SuccessInfo->VirtualRealmAddress);
        _worldPacket << uint32(SuccessInfo->VirtualRealms.size());
        _worldPacket << uint32(SuccessInfo->TimeRested);
        _worldPacket << uint8(SuccessInfo->ActiveExpansionLevel);
        _worldPacket << uint8(SuccessInfo->AccountExpansionLevel);
        _worldPacket << uint32(SuccessInfo->TimeSecondsUntilPCKick);
        _worldPacket << uint32(SuccessInfo->AvailableClasses->size());
        _worldPacket << uint32(SuccessInfo->Templates.size());
        _worldPacket << uint32(SuccessInfo->CurrencyID);
        _worldPacket << SuccessInfo->Time;

        for (RaceClassAvailability const& raceClassAvailability : *SuccessInfo->AvailableClasses)
        {
            _worldPacket << uint8(raceClassAvailability.RaceID);
            _worldPacket << uint32(raceClassAvailability.Classes.size());

            for (ClassAvailability const& classAvailability : raceClassAvailability.Classes)
            {
                _worldPacket << uint8(classAvailability.ClassID);
                _worldPacket << uint8(classAvailability.ActiveExpansionLevel);
                _worldPacket << uint8(classAvailability.AccountExpansionLevel);
                _worldPacket << uint8(classAvailability.MinActiveExpansionLevel);
            }
        }

        _worldPacket.WriteBit(SuccessInfo->IsExpansionTrial);
        _worldPacket.WriteBit(SuccessInfo->ForceCharacterTemplate);
        _worldPacket.WriteBit(SuccessInfo->NumPlayersHorde.has_value());
        _worldPacket.WriteBit(SuccessInfo->NumPlayersAlliance.has_value());
        _worldPacket.WriteBit(SuccessInfo->ExpansionTrialExpiration.has_value());
        _worldPacket.WriteBit(SuccessInfo->NewBuildKeys.has_value());
        _worldPacket.FlushBits();

        {
            _worldPacket << uint32(SuccessInfo->GameTimeInfo.BillingPlan);
            _worldPacket << uint32(SuccessInfo->GameTimeInfo.TimeRemain);
            _worldPacket << uint32(SuccessInfo->GameTimeInfo.Unknown735);
            // 3x same bit is not a mistake - preserves legacy client behavior of BillingPlanFlags::SESSION_IGR
            _worldPacket.WriteBit(SuccessInfo->GameTimeInfo.InGameRoom); // inGameRoom check in function checking which lua event to fire when remaining time is near end - BILLING_NAG_DIALOG vs IGR_BILLING_NAG_DIALOG
            _worldPacket.WriteBit(SuccessInfo->GameTimeInfo.InGameRoom); // inGameRoom lua return from Script_GetBillingPlan
            _worldPacket.WriteBit(SuccessInfo->GameTimeInfo.InGameRoom); // not used anywhere in the client
            _worldPacket.FlushBits();
        }

        if (SuccessInfo->NumPlayersHorde)
            _worldPacket << uint16(*SuccessInfo->NumPlayersHorde);

        if (SuccessInfo->NumPlayersAlliance)
            _worldPacket << uint16(*SuccessInfo->NumPlayersAlliance);

        if (SuccessInfo->ExpansionTrialExpiration)
            _worldPacket << *SuccessInfo->ExpansionTrialExpiration;

        if (SuccessInfo->NewBuildKeys)
        {
            for (std::size_t i = 0; i < 16; ++i)
            {
                _worldPacket << SuccessInfo->NewBuildKeys->NewBuildKey[i];
                _worldPacket << SuccessInfo->NewBuildKeys->SomeKey[i];
            }
        }

        for (VirtualRealmInfo const& virtualRealm : SuccessInfo->VirtualRealms)
            _worldPacket << virtualRealm;

        for (CharacterTemplate const* characterTemplate : SuccessInfo->Templates)
        {
            _worldPacket << uint32(characterTemplate->TemplateSetId);
            _worldPacket << uint32(characterTemplate->Classes.size());
            for (CharacterTemplateClass const& templateClass : characterTemplate->Classes)
            {
                _worldPacket << uint8(templateClass.ClassID);
                _worldPacket << uint8(templateClass.FactionGroup);
            }

            _worldPacket.WriteBits(characterTemplate->Name.length(), 7);
            _worldPacket.WriteBits(characterTemplate->Description.length(), 10);
            _worldPacket.FlushBits();

            _worldPacket.WriteString(characterTemplate->Name);
            _worldPacket.WriteString(characterTemplate->Description);
        }
    }

    if (WaitInfo)
        _worldPacket << *WaitInfo;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Auth::WaitQueueUpdate::Write()
{
    _worldPacket << WaitInfo;

    return &_worldPacket;
}

namespace
{
std::string const RSAPrivateKey = R"(-----BEGIN RSA PRIVATE KEY-----
MIIEpAIBAAKCAQEA7rPc1NPDtFRRzmZbyzK48PeSU8YZ8gyFL4omqXpFn2DE683q
f41Z2FeyYHsJTJtouMft7x6ADeZrN1tTkOsYEw1/Q2SD2pjmrMIwooKlxsvH+4af
n6kCagNJxTj7wMhVzMDOJZG+hc/R0TfOzIPS6jCAB3uAn51EVCIpvoba20jFqfkT
NpUjdvEO3IQNlAISqJfzOxTuqm+YBSdOH6Ngpana2BffM8viE1SLGLDKubuIZAbf
dabXYQC7sFoOetR3CE0V4hCDsASqnot3qQaJXQhdD7gua8HLZM9uXNtPWGUIUfsN
SBpvtj0fC93+Gx3wv7Ana/WOvMdAAf+nC4DWXwIDAQABAoIBACKa5q/gB2Y0Nyvi
APrDXrZoXclRVd+WWxSaRaKaPE+vuryovI9DUbwgcpa0H5QAj70CFwdsd4oMVozO
6519x56zfTiq8MaXFhIDkQNuR1Q7pMFdMfT2jogJ8/7olO7M3EtzxC8EIwfJKhTX
r15M2h3jbBwplmsNZKOB1GVvrXjOm1KtOZ4CTTM0WrPaLVDT9ax8pykjmFw16vGP
j/R5Dky9VpabtfZOu/AEW259XDEiQgTrB4Eg+S4GJjHqAzPZBmMy/xhlDK4oMXef
qXScfD4w0RxuuCFr6lxLPZz0S35BK1kIWmIkuv+9eQuI4Hr1CyVwch4fkfvrp84x
8tvAFnkCgYEA87NZaG9a8/Mob6GgY4BVLHJVOSzzFdNyMA+4LfSbtzgON2RSZyeD
0JpDowwXssw5XOyUUctj2cLLdlMCpDfdzk4F/PEakloDJWpason3lmur0/5Oq3T9
3+fnNUl4d3UOs1jcJ1yGQ/BfrTyRTcEoZx8Mu9mJ4ituVkKuLeG5vX0CgYEA+r/w
QBJS6kDyQPj1k/SMClUhWhyADwDod03hHTQHc9BleJyjXmVy+/pWhN7aELhjgLbf
o/Gm3aKJjCxS4qBmqUKwAvGoSVux1Bo2ZjcfF7sX9BXBOlFTG+bPVCZUoaksTyXN
g7GsA1frKkWWkgQuOeK3o/p9IZoBl93vEgcTGgsCgYEAv5ucCIjFMllUybCCsrkM
Ps4GQ9YbqmV9ulwhq8BPTlc8lkDCqWhgM3uXAnNXjrUTxQQd+dG4yFZoMrhBs2xZ
cQPXoXDQO5GaN6jPduETUamGiD/DCvwJQCrNlxAVL5dR36FWN3x/9JriHwsoE8Jz
SeEX2frIdpM/RYNX/6sipuECgYEA+rwFRDxOdvm8hGWuQ2WMxyQ7Nn07PEV/LxVM
HkSRkyh23vVakyDEqty3uSOSUJfgv6ud07TnU8ac3fLQatdT8LrDgB4fVkN/fYU8
kldaGwO1vxgl4OfDQCo7dXzisciViwtVBvQZ+jnm6J0vJBFUHAPt9+WZTIlQQIjm
71LtseMCgYBSAhs6lshtz+ujR3fmc4QqJVGqeXvEBPAVm6yYoKYRLwVs/rFv3WLN
LOwwBQ6lz7P9RqYYB5wVlaRvEhb9+lCve/xVcxMeZ5GkOBPxVygYV9l/wNdE25Nz
OHYtKG3GK3GEcFDwZU2LPHq21EroUAdtRfbrJ4KW2yc8igtXKxTBYw==
-----END RSA PRIVATE KEY-----
)";

std::array<uint8, 32> constexpr EnterEncryptedModePrivateKey =
{
    0x08, 0xBD, 0xC7, 0xA3, 0xCC, 0xC3, 0x4F, 0x3F,
    0x6A, 0x0B, 0xFF, 0xCF, 0x31, 0xC1, 0xB6, 0x97,
    0x69, 0x1E, 0x72, 0x9A, 0x0A, 0xAB, 0x2C, 0x77,
    0xC3, 0x6F, 0x8A, 0xE7, 0x5A, 0x9A, 0xA7, 0xC9
};

std::unique_ptr<Trinity::Crypto::RsaSignature> ConnectToRSA;
std::unique_ptr<Trinity::Crypto::Ed25519> EnterEncryptedModeSigner;
}

bool WorldPackets::Auth::ConnectTo::InitializeEncryption()
{
    std::unique_ptr<Trinity::Crypto::RsaSignature> rsa = std::make_unique<Trinity::Crypto::RsaSignature>();
    if (!rsa->LoadKeyFromString(RSAPrivateKey))
        return false;

    ConnectToRSA = std::move(rsa);
    return true;
}

void WorldPackets::Auth::ConnectTo::ShutdownEncryption()
{
    ConnectToRSA.reset();
}

WorldPackets::Auth::ConnectTo::ConnectTo() : ServerPacket(SMSG_CONNECT_TO, 256 + 1 + 16 + 2 + 4 + 1 + 8)
{
}

WorldPacket const* WorldPackets::Auth::ConnectTo::Write()
{
    ByteBuffer whereBuffer;
    whereBuffer << uint8(Payload.Where.Type);
    switch (Payload.Where.Type)
    {
        case IPv4:
            whereBuffer.append(Payload.Where.Address.V4.data(), Payload.Where.Address.V4.size());
            break;
        case IPv6:
            whereBuffer.append(Payload.Where.Address.V6.data(), Payload.Where.Address.V6.size());
            break;
        case NamedSocket:
            whereBuffer << Payload.Where.Address.Name.data();
            break;
        default:
            break;
    }

    ByteBuffer signBuffer;
    signBuffer.append(whereBuffer);
    signBuffer << uint32(Payload.Where.Type);
    signBuffer << uint16(Payload.Port);

    Trinity::Crypto::RsaSignature rsa(*ConnectToRSA);
    Trinity::Crypto::RsaSignature::SHA256 digestGenerator;
    std::vector<uint8> signature;
    rsa.Sign(signBuffer.contents(), signBuffer.size(), digestGenerator, signature);

    _worldPacket.append(signature.data(), signature.size());
    _worldPacket.append(whereBuffer);
    _worldPacket << uint16(Payload.Port);
    _worldPacket << uint32(Serial);
    _worldPacket << uint8(Con);
    _worldPacket << uint64(Key);

    return &_worldPacket;
}

void WorldPackets::Auth::AuthContinuedSession::Read()
{
    _worldPacket >> DosResponse;
    _worldPacket >> Key;
    _worldPacket.read(LocalChallenge.data(), LocalChallenge.size());
    _worldPacket.read(Digest.data(), Digest.size());
}

void WorldPackets::Auth::ConnectToFailed::Read()
{
    _worldPacket >> As<uint32>(Serial);
    _worldPacket >> Con;
}

bool WorldPackets::Auth::EnterEncryptedMode::InitializeEncryption()
{
    std::unique_ptr<Trinity::Crypto::Ed25519> ed25519 = std::make_unique<Trinity::Crypto::Ed25519>();
    if (!ed25519->LoadFromByteArray(EnterEncryptedModePrivateKey))
        return false;

    EnterEncryptedModeSigner = std::move(ed25519);
    return true;
}

void WorldPackets::Auth::EnterEncryptedMode::ShutdownEncryption()
{
    EnterEncryptedModeSigner.reset();
}

std::array<uint8, 16> constexpr EnableEncryptionSeed = { 0x90, 0x9C, 0xD0, 0x50, 0x5A, 0x2C, 0x14, 0xDD, 0x5C, 0x2C, 0xC0, 0x64, 0x14, 0xF3, 0xFE, 0xC9 };
std::array<uint8, 16> constexpr EnableEncryptionContext = { 0xA7, 0x1F, 0xB6, 0x9B, 0xC9, 0x7C, 0xDD, 0x96, 0xE9, 0xBB, 0xB8, 0x21, 0x39, 0x8D, 0x5A, 0xD4 };

WorldPacket const* WorldPackets::Auth::EnterEncryptedMode::Write()
{
    std::array<uint8, 32> toSign = Trinity::Crypto::HMAC_SHA256::GetDigestOf(EncryptionKey,
        std::array<uint8, 1>{uint8(Enabled ? 1 : 0)},
        EnableEncryptionSeed);

    Trinity::Crypto::Ed25519 ed25519(*EnterEncryptedModeSigner);
    std::vector<uint8> signature;

    ed25519.SignWithContext(toSign, { EnableEncryptionContext.begin(), EnableEncryptionContext.end() }, signature);

    _worldPacket.append(signature.data(), signature.size());
    _worldPacket.WriteBit(Enabled);
    _worldPacket.FlushBits();

    return &_worldPacket;
}
