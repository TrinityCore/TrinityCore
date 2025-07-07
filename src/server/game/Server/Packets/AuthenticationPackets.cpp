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
#include "PacketOperators.h"
#include "RSA.h"

namespace WorldPackets::Auth
{
ByteBuffer& operator<<(ByteBuffer& data, VirtualRealmNameInfo const& virtualRealmInfo)
{
    data << WorldPackets::Bits<1>(virtualRealmInfo.IsLocal);
    data << WorldPackets::Bits<1>(virtualRealmInfo.IsInternalRealm);
    data << WorldPackets::SizedString::BitsSize<8>(virtualRealmInfo.RealmNameActual);
    data << WorldPackets::SizedString::BitsSize<8>(virtualRealmInfo.RealmNameNormalized);
    data.FlushBits();

    data << SizedString::Data(virtualRealmInfo.RealmNameActual);
    data << SizedString::Data(virtualRealmInfo.RealmNameNormalized);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, VirtualRealmInfo const& virtualRealmInfo)
{
    data << uint32(virtualRealmInfo.RealmAddress);
    data << virtualRealmInfo.RealmNameInfo;

    return data;
}

void Ping::Read()
{
    _worldPacket >> Serial;
    _worldPacket >> Latency;
}

WorldPacket const* Pong::Write()
{
    _worldPacket << uint32(Serial);
    return &_worldPacket;
}

WorldPacket const* AuthChallenge::Write()
{
    _worldPacket.append(DosChallenge.data(), DosChallenge.size());
    _worldPacket.append(Challenge.data(), Challenge.size());
    _worldPacket << uint8(DosZeroBits);
    return &_worldPacket;
}

void AuthSession::Read()
{
    uint32 realmJoinTicketSize;

    _worldPacket >> DosResponse;
    _worldPacket >> RegionID;
    _worldPacket >> BattlegroupID;
    _worldPacket >> RealmID;
    _worldPacket.read(LocalChallenge.data(), LocalChallenge.size());
    _worldPacket.read(Digest.data(), Digest.size());
    _worldPacket >> Bits<1>(UseIPv6);
    _worldPacket >> realmJoinTicketSize;
    if (realmJoinTicketSize)
    {
        RealmJoinTicket.resize(std::min(realmJoinTicketSize, uint32(_worldPacket.size() - _worldPacket.rpos())));
        _worldPacket.read(RealmJoinTicket.data(), RealmJoinTicket.size());
    }
}

ByteBuffer& operator<<(ByteBuffer& data, GameTime const& gameTime)
{
    data << uint32(gameTime.BillingType);
    data << uint32(gameTime.MinutesRemaining);
    data << uint32(gameTime.RealBillingType);
    data << Bits<1>(gameTime.IsInIGR);
    data << Bits<1>(gameTime.IsPaidForByIGR);
    data << Bits<1>(gameTime.IsCAISEnabled);
    data.FlushBits();

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, BaseBuildKey const& buildKey)
{
    for (std::size_t i = 0; i < 16; ++i)
    {
        data << buildKey.BuildKey[i];
        data << buildKey.ConfigKey[i];
    }

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, AuthSuccessInfo const& successInfo)
{
    data << uint32(successInfo.VirtualRealmAddress);
    data << Size<uint32>(successInfo.VirtualRealms);
    data << uint32(successInfo.TimeRested);
    data << uint8(successInfo.ActiveExpansionLevel);
    data << uint8(successInfo.AccountExpansionLevel);
    data << uint32(successInfo.TimeSecondsUntilPCKick);
    data << Size<uint32>(*successInfo.AvailableClasses);
    data << Size<uint32>(successInfo.Templates);
    data << uint32(successInfo.CurrencyID);
    data << successInfo.Time;

    for (RaceClassAvailability const& raceClassAvailability : *successInfo.AvailableClasses)
    {
        data << uint8(raceClassAvailability.RaceID);
        data << Size<uint32>(raceClassAvailability.Classes);

        for (ClassAvailability const& classAvailability : raceClassAvailability.Classes)
        {
            data << uint8(classAvailability.ClassID);
            data << uint8(classAvailability.ActiveExpansionLevel);
            data << uint8(classAvailability.AccountExpansionLevel);
            data << uint8(classAvailability.MinActiveExpansionLevel);
        }
    }

    data << Bits<1>(successInfo.IsExpansionTrial);
    data << Bits<1>(successInfo.ForceCharacterTemplate);
    data << OptionalInit(successInfo.NumPlayersHorde);
    data << OptionalInit(successInfo.NumPlayersAlliance);
    data << OptionalInit(successInfo.ExpansionTrialExpiration);
    data << OptionalInit(successInfo.CurrentBuild);
    data.FlushBits();

    data << successInfo.GameTimeInfo;

    if (successInfo.NumPlayersHorde)
        data << uint16(*successInfo.NumPlayersHorde);

    if (successInfo.NumPlayersAlliance)
        data << uint16(*successInfo.NumPlayersAlliance);

    if (successInfo.ExpansionTrialExpiration)
        data << *successInfo.ExpansionTrialExpiration;

    if (successInfo.CurrentBuild)
        data << *successInfo.CurrentBuild;

    for (VirtualRealmInfo const& virtualRealm : successInfo.VirtualRealms)
        data << virtualRealm;

    for (CharacterTemplate const* characterTemplate : successInfo.Templates)
    {
        data << uint32(characterTemplate->TemplateSetId);
        data << Size<uint32>(characterTemplate->Classes);
        for (CharacterTemplateClass const& templateClass : characterTemplate->Classes)
        {
            data << uint8(templateClass.ClassID);
            data << uint8(templateClass.FactionGroup);
        }

        data << SizedString::BitsSize<7>(characterTemplate->Name);
        data << SizedString::BitsSize<10>(characterTemplate->Description);
        data.FlushBits();

        data << SizedString::Data(characterTemplate->Name);
        data << SizedString::Data(characterTemplate->Description);
    }

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, AuthWaitInfo const& waitInfo)
{
    data << uint32(waitInfo.WaitCount);
    data << uint32(waitInfo.WaitTime);
    data << uint8(waitInfo.AllowedFactionGroupForCharacterCreate);
    data << WorldPackets::Bits<1>(waitInfo.HasFCM);
    data << WorldPackets::Bits<1>(waitInfo.CanCreateOnlyIfExisting);
    data.FlushBits();

    return data;
}

WorldPacket const* AuthResponse::Write()
{
    _worldPacket << uint32(Result);
    _worldPacket << OptionalInit(SuccessInfo);
    _worldPacket << OptionalInit(WaitInfo);
    _worldPacket.FlushBits();

    if (SuccessInfo)
        _worldPacket << *SuccessInfo;

    if (WaitInfo)
        _worldPacket << *WaitInfo;

    return &_worldPacket;
}

WorldPacket const* WaitQueueUpdate::Write()
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

bool ConnectTo::InitializeEncryption()
{
    std::unique_ptr<Trinity::Crypto::RsaSignature> rsa = std::make_unique<Trinity::Crypto::RsaSignature>();
    if (!rsa->LoadKeyFromString(RSAPrivateKey))
        return false;

    ConnectToRSA = std::move(rsa);
    return true;
}

void ConnectTo::ShutdownEncryption()
{
    ConnectToRSA.reset();
}

WorldPacket const* ConnectTo::Write()
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
    rsa.Sign(signBuffer.data(), signBuffer.size(), digestGenerator, signature);

    _worldPacket.append(signature.data(), signature.size());
    _worldPacket.append(whereBuffer);
    _worldPacket << uint16(Payload.Port);
    _worldPacket << uint32(Serial);
    _worldPacket << uint8(Con);
    _worldPacket << uint64(Key);

    return &_worldPacket;
}

void AuthContinuedSession::Read()
{
    _worldPacket >> DosResponse;
    _worldPacket >> Key;
    _worldPacket.read(LocalChallenge.data(), LocalChallenge.size());
    _worldPacket.read(Digest.data(), Digest.size());
}

void ConnectToFailed::Read()
{
    _worldPacket >> Con;
    _worldPacket >> As<uint32>(Serial);
}

bool EnterEncryptedMode::InitializeEncryption()
{
    std::unique_ptr<Trinity::Crypto::Ed25519> ed25519 = std::make_unique<Trinity::Crypto::Ed25519>();
    if (!ed25519->LoadFromByteArray(EnterEncryptedModePrivateKey))
        return false;

    EnterEncryptedModeSigner = std::move(ed25519);
    return true;
}

void EnterEncryptedMode::ShutdownEncryption()
{
    EnterEncryptedModeSigner.reset();
}

std::array<uint8, 32> constexpr EnableEncryptionSeed = { 0x66, 0xBE, 0x29, 0x79, 0xEF, 0xF2, 0xD5, 0xB5, 0x61, 0x53, 0xF6, 0x5F, 0x45, 0xAE, 0x81, 0xCB,
    0x32, 0xEC, 0x94, 0xEC, 0x75, 0xB3, 0x5F, 0x44, 0x6A, 0x63, 0x43, 0x67, 0x17, 0x20, 0x44, 0x34 };
std::array<uint8, 16> constexpr EnableEncryptionContext = { 0xA7, 0x1F, 0xB6, 0x9B, 0xC9, 0x7C, 0xDD, 0x96, 0xE9, 0xBB, 0xB8, 0x21, 0x39, 0x8D, 0x5A, 0xD4 };

WorldPacket const* EnterEncryptedMode::Write()
{
    std::array<uint8, 64> toSign = Trinity::Crypto::HMAC_SHA512::GetDigestOf(EncryptionKey,
        std::array<uint8, 1>{uint8(Enabled ? 1 : 0)},
        EnableEncryptionSeed);

    Trinity::Crypto::Ed25519 ed25519(*EnterEncryptedModeSigner);
    std::vector<uint8> signature;

    ed25519.SignWithContext(toSign, { EnableEncryptionContext.begin(), EnableEncryptionContext.end() }, signature);

    _worldPacket << int32(RegionGroup);
    _worldPacket.append(signature.data(), signature.size());
    _worldPacket << Bits<1>(Enabled);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

void QueuedMessagesEnd::Read()
{
    _worldPacket >> Timestamp;
}
}
