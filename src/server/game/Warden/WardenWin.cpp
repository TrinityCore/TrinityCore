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

#include "WardenWin.h"
#include "Common.h"
#include "ByteBuffer.h"
#include "Containers.h"
#include "CryptoRandom.h"
#include "DatabaseEnv.h"
#include "GameTime.h"
#include "HMAC.h"
#include "Log.h"
#include "Opcodes.h"
#include "Player.h"
#include "Random.h"
#include "SessionKeyGenerator.h"
#include "SmartEnum.h"
#include "Util.h"
#include "WardenModuleWin.h"
#include "WardenCheckMgr.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"

 // GUILD is the shortest string that has no client validation (RAID only sends if in a raid group)
static constexpr char _luaEvalPrefix[] = "local S,T,R=SendAddonMessage,function()";
static constexpr char _luaEvalMidfix[] = " end R=S and T()if R then S('_TW',";
static constexpr char _luaEvalPostfix[] = ",'GUILD')end";

static_assert((sizeof(_luaEvalPrefix)-1 + sizeof(_luaEvalMidfix)-1 + sizeof(_luaEvalPostfix)-1 + WARDEN_MAX_LUA_CHECK_LENGTH) == 255);

WardenWin::WardenWin() : Warden(), _serverTicks(0)
{
    for (WardenCheckCategory category : EnumUtils::Iterate<WardenCheckCategory>())
    {
        auto& [checks, checksIt] = _checks[category];
        checks = sWardenCheckMgr->GetAvailableChecks(category);
        Trinity::Containers::RandomShuffle(checks);
        checksIt = checks.begin();
    }
}

void WardenWin::Init(WorldSession* session, SessionKey const& K)
{
    _session = session;
    // Generate Warden Key
    SessionKeyGenerator<Trinity::Crypto::SHA1> WK(K);
    WK.Generate(_inputKey.data(), _inputKey.size());
    WK.Generate(_outputKey.data(), _outputKey.size());

    _seed = Module.Seed;

    _inputCrypto.Init(_inputKey);
    _outputCrypto.Init(_outputKey);
    TC_LOG_DEBUG("warden", "Server side warden for client %u initializing...", session->GetAccountId());
    TC_LOG_DEBUG("warden", "C->S Key: %s", ByteArrayToHexStr(_inputKey).c_str());
    TC_LOG_DEBUG("warden", "S->C Key: %s", ByteArrayToHexStr(_outputKey).c_str());
    TC_LOG_DEBUG("warden", "  Seed: %s", ByteArrayToHexStr(_seed).c_str());
    TC_LOG_DEBUG("warden", "Loading Module...");

    MakeModuleForClient();

    TC_LOG_DEBUG("warden", "Module Key: %s", ByteArrayToHexStr(_module->Key).c_str());
    TC_LOG_DEBUG("warden", "Module ID: %s", ByteArrayToHexStr(_module->Id).c_str());
    RequestModule();
}

void WardenWin::InitializeModuleForClient(ClientWardenModule& module)
{
    // data assign
    module.CompressedData = Module.Module.data();
    module.CompressedSize = Module.Module.size();
    module.Key = Module.ModuleKey;
}

void WardenWin::InitializeModule()
{
    TC_LOG_DEBUG("warden", "Initialize module");

    // Create packet structure
    WardenInitModuleRequest Request;
    Request.Command1 = WARDEN_SMSG_MODULE_INITIALIZE;
    Request.Size1 = 20;
    Request.Unk1 = 1;
    Request.Unk2 = 0;
    Request.Type = 1;
    Request.String_library1 = 0;
    Request.Function1[0] = 0x00024F80;                      // 0x00400000 + 0x00024F80 SFileOpenFile
    Request.Function1[1] = 0x000218C0;                      // 0x00400000 + 0x000218C0 SFileGetFileSize
    Request.Function1[2] = 0x00022530;                      // 0x00400000 + 0x00022530 SFileReadFile
    Request.Function1[3] = 0x00022910;                      // 0x00400000 + 0x00022910 SFileCloseFile
    Request.CheckSumm1 = BuildChecksum(&Request.Unk1, 20);

    Request.Command2 = WARDEN_SMSG_MODULE_INITIALIZE;
    Request.Size2 = 8;
    Request.Unk3 = 4;
    Request.Unk4 = 0;
    Request.String_library2 = 0;
    Request.Function2 = 0x00419210;                         // 0x00400000 + 0x00419210 FrameScript::Execute
    Request.Function2_set = 1;
    Request.CheckSumm2 = BuildChecksum(&Request.Unk3, 8);

    Request.Command3 = WARDEN_SMSG_MODULE_INITIALIZE;
    Request.Size3 = 8;
    Request.Unk5 = 1;
    Request.Unk6 = 1;
    Request.String_library3 = 0;
    Request.Function3 = 0x0046AE20;                         // 0x00400000 + 0x0046AE20 PerformanceCounter
    Request.Function3_set = 1;
    Request.CheckSumm3 = BuildChecksum(&Request.Unk5, 8);

    EndianConvert(Request.Size1);
    EndianConvert(Request.CheckSumm1);
    EndianConvert(Request.Function1[0]);
    EndianConvert(Request.Function1[1]);
    EndianConvert(Request.Function1[2]);
    EndianConvert(Request.Function1[3]);
    EndianConvert(Request.Size2);
    EndianConvert(Request.CheckSumm2);
    EndianConvert(Request.Function2);
    EndianConvert(Request.Size3);
    EndianConvert(Request.CheckSumm3);
    EndianConvert(Request.Function3);

    // Encrypt with warden RC4 key.
    EncryptData(reinterpret_cast<uint8*>(&Request), sizeof(WardenInitModuleRequest));

    WorldPacket pkt(SMSG_WARDEN_DATA, sizeof(WardenInitModuleRequest));
    pkt.append(reinterpret_cast<uint8*>(&Request), sizeof(WardenInitModuleRequest));
    _session->SendPacket(&pkt);
}

void WardenWin::RequestHash()
{
    TC_LOG_DEBUG("warden", "Request hash");

    // Create packet structure
    WardenHashRequest Request;
    Request.Command = WARDEN_SMSG_HASH_REQUEST;
    Request.Seed = _seed;

    // Encrypt with warden RC4 key.
    EncryptData(reinterpret_cast<uint8*>(&Request), sizeof(WardenHashRequest));

    WorldPacket pkt(SMSG_WARDEN_DATA, sizeof(WardenHashRequest));
    pkt.append(reinterpret_cast<uint8*>(&Request), sizeof(WardenHashRequest));
    _session->SendPacket(&pkt);
}

void WardenWin::HandleHashResult(ByteBuffer &buff)
{
    // Verify key
    Trinity::Crypto::SHA1::Digest response;
    buff.read(response);
    if (response != Module.ClientKeySeedHash)
    {
        char const* penalty = ApplyPenalty(nullptr);
        TC_LOG_WARN("warden", "%s failed hash reply. Action: %s", _session->GetPlayerInfo().c_str(), penalty);
        return;
    }

    TC_LOG_DEBUG("warden", "Request hash reply: succeed");

    // Change keys here
    _inputKey = Module.ClientKeySeed;
    _outputKey = Module.ServerKeySeed;

    _inputCrypto.Init(_inputKey);
    _outputCrypto.Init(_outputKey);

    _initialized = true;
}

static constexpr uint8 GetCheckPacketBaseSize(WardenCheckType type)
{
    switch (type)
    {
        case DRIVER_CHECK: return 1;
        case LUA_EVAL_CHECK: return 1 + sizeof(_luaEvalPrefix)-1 + sizeof(_luaEvalMidfix)-1 + 4 + sizeof(_luaEvalPostfix)-1;
        case MPQ_CHECK: return 1;
        case PAGE_CHECK_A: return (4 + 1);
        case PAGE_CHECK_B: return (4 + 1);
        case MODULE_CHECK: return (4 + Trinity::Crypto::HMAC_SHA1::DIGEST_LENGTH);
        case MEM_CHECK: return (1 + 4 + 1);
        default: return 0;
    }
}

static uint16 GetCheckPacketSize(WardenCheck const& check)
{
    uint16 size = 1 + GetCheckPacketBaseSize(check.Type); // 1 byte check type
    if (!check.Str.empty())
        size += (check.Str.length() + 1); // 1 byte string length
    if (!check.Data.empty())
        size += check.Data.size();
    return size;
}

void WardenWin::RequestChecks()
{
    TC_LOG_DEBUG("warden", "Request data from %s (account %u) - loaded: %u", _session->GetPlayerName().c_str(), _session->GetAccountId(), _session->GetPlayer() && !_session->PlayerLoading());

    // If all checks for a category are done, fill its todo list again
    for (WardenCheckCategory category : EnumUtils::Iterate<WardenCheckCategory>())
    {
        auto& [checks, checksIt] = _checks[category];
        if ((checksIt == checks.end()) && !checks.empty())
        {
            TC_LOG_DEBUG("warden", "Finished all %s checks, re-shuffling", EnumUtils::ToConstant(category));
            Trinity::Containers::RandomShuffle(checks);
            checksIt = checks.begin();
        }
    }

    _serverTicks = GameTime::GetGameTimeMS();
    _currentChecks.clear();

    // Build check request
    ByteBuffer buff;
    buff << uint8(WARDEN_SMSG_CHEAT_CHECKS_REQUEST);

    for (WardenCheckCategory category : EnumUtils::Iterate<WardenCheckCategory>())
    {
        if (IsWardenCategoryInWorldOnly(category) && !_session->GetPlayer())
            continue;

        auto& [checks, checksIt] = _checks[category];
        for (uint32 i = 0, n = sWorld->getIntConfig(GetWardenCategoryCountConfig(category)); i < n; ++i)
        {
            if (checksIt == checks.end()) // all checks were already sent, list will be re-filled on next Update() run
                break;
            _currentChecks.push_back(*(checksIt++));
        }
    }

    Trinity::Containers::RandomShuffle(_currentChecks);

    uint16 expectedSize = 4;
    Trinity::Containers::EraseIf(_currentChecks,
        [&expectedSize](uint16 id)
        {
            uint8 const thisSize = GetCheckPacketSize(sWardenCheckMgr->GetCheckData(id));
            if ((expectedSize + thisSize) > 450) // warden packets are truncated to 512 bytes clientside
                return true;
            expectedSize += thisSize;
            return false;
        }
    );

    for (uint16 const id : _currentChecks)
    {
        WardenCheck const& check = sWardenCheckMgr->GetCheckData(id);
        if (check.Type == LUA_EVAL_CHECK)
        {
            buff << uint8(sizeof(_luaEvalPrefix) - 1 + check.Str.size() + sizeof(_luaEvalMidfix) - 1 + check.IdStr.size() + sizeof(_luaEvalPostfix) - 1);
            buff.append(_luaEvalPrefix, sizeof(_luaEvalPrefix) - 1);
            buff.append(check.Str.data(), check.Str.size());
            buff.append(_luaEvalMidfix, sizeof(_luaEvalMidfix) - 1);
            buff.append(check.IdStr.data(), check.IdStr.size());
            buff.append(_luaEvalPostfix, sizeof(_luaEvalPostfix) - 1);
        }
        else if (!check.Str.empty())
        {
            buff << uint8(check.Str.size());
            buff.append(check.Str.data(), check.Str.size());
        }
    }

    uint8 xorByte = _inputKey[0];

    // Add TIMING_CHECK
    buff << uint8(0x00);
    buff << uint8(TIMING_CHECK ^ xorByte);

    uint8 index = 1;

    for (uint16 const id : _currentChecks)
    {
        WardenCheck const& check = sWardenCheckMgr->GetCheckData(id);

        WardenCheckType const type = check.Type;
        buff << uint8(type ^ xorByte);
        switch (type)
        {
            case MEM_CHECK:
            {
                buff << uint8(0x00);
                buff << uint32(check.Address);
                buff << uint8(sWardenCheckMgr->GetCheckResult(id).size());
                break;
            }
            case PAGE_CHECK_A:
            case PAGE_CHECK_B:
            {
                buff.append(check.Data.data(), check.Data.size());
                buff << uint32(check.Address);
                buff << uint8(check.Length);
                break;
            }
            case MPQ_CHECK:
            case LUA_EVAL_CHECK:
            {
                buff << uint8(index++);
                break;
            }
            case DRIVER_CHECK:
            {
                buff.append(check.Data.data(), check.Data.size());
                buff << uint8(index++);
                break;
            }
            case MODULE_CHECK:
            {
                std::array<uint8, 4> seed = Trinity::Crypto::GetRandomBytes<4>();
                buff.append(seed);
                buff.append(Trinity::Crypto::HMAC_SHA1::GetDigestOf(seed, check.Str));
                break;
            }
            /*case PROC_CHECK:
            {
                buff.append(check->i.AsByteArray(0, false).get(), check->i.GetNumBytes());
                buff << uint8(index++);
                buff << uint8(index++);
                buff << uint32(check->Address);
                buff << uint8(check->Length);
                break;
            }*/
            default:
                break;                                      // Should never happen
        }
    }
    buff << uint8(xorByte);
    buff.hexlike();

    auto idstring = [this]() -> std::string
    {
        std::stringstream stream;
        for (uint16 const id : _currentChecks)
            stream << id << " ";
        return stream.str();
    };

    if (buff.size() == expectedSize)
    {
        TC_LOG_DEBUG("warden", "Finished building warden packet, size is %zu bytes", buff.size());
        TC_LOG_DEBUG("warden", "Sent checks: %s", idstring().c_str());
    }
    else
    {
        TC_LOG_WARN("warden", "Finished building warden packet, size is %zu bytes, but expected %u bytes!", buff.size(), expectedSize);
        TC_LOG_WARN("warden", "Sent checks: %s", idstring().c_str());
    }

    // Encrypt with warden RC4 key
    EncryptData(buff.contents(), buff.size());

    WorldPacket pkt(SMSG_WARDEN_DATA, buff.size());
    pkt.append(buff);
    _session->SendPacket(&pkt);

    _dataSent = true;
}

void WardenWin::HandleCheckResult(ByteBuffer &buff)
{
    TC_LOG_DEBUG("warden", "Handle data");

    _dataSent = false;
    _clientResponseTimer = 0;

    uint16 Length;
    buff >> Length;
    uint32 Checksum;
    buff >> Checksum;

    if (Length != (buff.size() - buff.rpos()))
    {
        buff.rfinish();
        char const* penalty = ApplyPenalty(nullptr);
        TC_LOG_WARN("warden", "%s sends manipulated warden packet. Action: %s", _session->GetPlayerInfo().c_str(), penalty);
        return;
    }

    if (!IsValidCheckSum(Checksum, buff.contents() + buff.rpos(), Length))
    {
        buff.rfinish();
        char const* penalty = ApplyPenalty(nullptr);
        TC_LOG_WARN("warden", "%s failed checksum. Action: %s", _session->GetPlayerInfo().c_str(), penalty);
        return;
    }

    // TIMING_CHECK
    {
        uint8 result;
        buff >> result;
        /// @todo test it.
        if (result == 0x00)
        {
            char const* penalty = ApplyPenalty(nullptr);
            TC_LOG_WARN("warden", "%s failed timing check. Action: %s", _session->GetPlayerInfo().c_str(), penalty);
            return;
        }

        uint32 newClientTicks;
        buff >> newClientTicks;

        uint32 ticksNow = GameTime::GetGameTimeMS();
        uint32 ourTicks = newClientTicks + (ticksNow - _serverTicks);

        TC_LOG_DEBUG("warden", "Server tick count now:    %u", ticksNow);
        TC_LOG_DEBUG("warden", "Server tick count at req: %u", _serverTicks);
        TC_LOG_DEBUG("warden", "Client ticks in response: %u", newClientTicks);
        TC_LOG_DEBUG("warden", "Round trip response time: %u ms", ourTicks - newClientTicks);
    }

    uint16 checkFailed = 0;
    for (uint16 const id : _currentChecks)
    {
        WardenCheck const& check = sWardenCheckMgr->GetCheckData(id);

        switch (check.Type)
        {
            case MEM_CHECK:
            {
                uint8 Mem_Result;
                buff >> Mem_Result;

                if (Mem_Result != 0)
                {
                    TC_LOG_DEBUG("warden", "RESULT MEM_CHECK not 0x00, CheckId %u account Id %u", id, _session->GetAccountId());
                    checkFailed = id;
                    continue;
                }

                WardenCheckResult const& expected = sWardenCheckMgr->GetCheckResult(id);

                std::vector<uint8> response;
                response.resize(expected.size());
                buff.read(response.data(), response.size());

                if (response != expected)
                {
                    TC_LOG_DEBUG("warden", "RESULT MEM_CHECK fail CheckId %u account Id %u", id, _session->GetAccountId());
                    TC_LOG_DEBUG("warden", "Expected: %s", ByteArrayToHexStr(expected).c_str());
                    TC_LOG_DEBUG("warden", "Got:      %s", ByteArrayToHexStr(response).c_str());
                    checkFailed = id;
                    continue;
                }

                TC_LOG_DEBUG("warden", "RESULT MEM_CHECK passed CheckId %u account Id %u", id, _session->GetAccountId());
                break;
            }
            case PAGE_CHECK_A:
            case PAGE_CHECK_B:
            case DRIVER_CHECK:
            case MODULE_CHECK:
            {
                if (buff.read<uint8>() != 0xE9)
                {
                    TC_LOG_DEBUG("warden", "RESULT %s fail, CheckId %u account Id %u", EnumUtils::ToConstant(check.Type), id, _session->GetAccountId());
                    checkFailed = id;
                    continue;
                }

                TC_LOG_DEBUG("warden", "RESULT %s passed CheckId %u account Id %u", EnumUtils::ToConstant(check.Type), id, _session->GetAccountId());
                break;
            }
            case LUA_EVAL_CHECK:
            {
                uint8 const result = buff.read<uint8>();
                if (result == 0)
                    buff.read_skip(buff.read<uint8>()); // discard attached string

                TC_LOG_DEBUG("warden", "LUA_EVAL_CHECK CheckId %u account Id %u got in-warden dummy response (%u)", id, _session->GetAccountId(), result);
                break;
            }
            case MPQ_CHECK:
            {
                uint8 Mpq_Result;
                buff >> Mpq_Result;

                if (Mpq_Result != 0)
                {
                    TC_LOG_DEBUG("warden", "RESULT MPQ_CHECK not 0x00 account id %u", _session->GetAccountId());
                    checkFailed = id;
                    continue;
                }

                std::vector<uint8> result;
                result.resize(Trinity::Crypto::SHA1::DIGEST_LENGTH);
                buff.read(result.data(), result.size());
                if (result != sWardenCheckMgr->GetCheckResult(id)) // SHA1
                {
                    TC_LOG_DEBUG("warden", "RESULT MPQ_CHECK fail, CheckId %u account Id %u", id, _session->GetAccountId());
                    checkFailed = id;
                    continue;
                }

                TC_LOG_DEBUG("warden", "RESULT MPQ_CHECK passed, CheckId %u account Id %u", id, _session->GetAccountId());
                break;
            }
            default:                                        // Should never happen
                break;
        }
    }

    if (checkFailed > 0)
    {
        WardenCheck const& check = sWardenCheckMgr->GetCheckData(checkFailed);
        char const* penalty = ApplyPenalty(&check);
        TC_LOG_WARN("warden", "%s failed Warden check %u (%s). Action: %s", _session->GetPlayerInfo().c_str(), checkFailed, EnumUtils::ToConstant(check.Type), penalty);
    }

    // Set hold off timer, minimum timer should at least be 1 second
    uint32 holdOff = sWorld->getIntConfig(CONFIG_WARDEN_CLIENT_CHECK_HOLDOFF);
    _checkTimer = (holdOff < 1 ? 1 : holdOff) * IN_MILLISECONDS;
}

size_t WardenWin::DEBUG_ForceSpecificChecks(std::vector<uint16> const& checks)
{
    std::array<std::vector<uint16>::iterator, NUM_CHECK_CATEGORIES> swapPositions;
    for (WardenCheckCategory category : EnumUtils::Iterate<WardenCheckCategory>())
        swapPositions[category] = _checks[category].first.begin();

    size_t n = 0;
    for (uint16 check : checks)
    {
        for (WardenCheckCategory category : EnumUtils::Iterate<WardenCheckCategory>())
        {
            std::vector<uint16>& checks = _checks[category].first;
            std::vector<uint16>::iterator& swapPos = swapPositions[category];
            if (auto it = std::find(swapPos, checks.end(), check); it != checks.end())
            {
                std::iter_swap(swapPos, it);
                ++swapPos;
                ++n;
                break;
            }
        }
    }

    for (WardenCheckCategory category : EnumUtils::Iterate<WardenCheckCategory>())
        _checks[category].second = _checks[category].first.begin();

    return n;
}
