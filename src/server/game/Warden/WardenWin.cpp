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
#include <sstream>

WardenWin::WardenWin() : Warden(), _serverTicks(0)
{
    _memChecks = sWardenCheckMgr->GetAvailableMemoryChecks();
    Trinity::Containers::RandomShuffle(_memChecks);
    _memChecksIt = _memChecks.begin();

    _otherChecks = sWardenCheckMgr->GetAvailableOtherChecks();
    Trinity::Containers::RandomShuffle(_otherChecks);
    _otherChecksIt = _otherChecks.begin();
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
    Request.Function2 = 0x00419D40;                         // 0x00400000 + 0x00419D40 FrameScript::GetText
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

    WorldPacket pkt(SMSG_WARDEN3_DATA, sizeof(WardenInitModuleRequest));
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

    WorldPacket pkt(SMSG_WARDEN3_DATA, sizeof(WardenHashRequest));
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

void WardenWin::RequestChecks()
{
    TC_LOG_DEBUG("warden", "Request data");

    // If all checks were done, fill the todo list again
    if (_memChecksIt == _memChecks.end())
    {
        TC_LOG_DEBUG("warden", "Finished all mem checks, re-shuffling");
        Trinity::Containers::RandomShuffle(_memChecks);
        _memChecksIt = _memChecks.begin();
    }

    if (_otherChecksIt == _otherChecks.end())
    {
        TC_LOG_DEBUG("warden", "Finished all other checks, re-shuffling");
        Trinity::Containers::RandomShuffle(_otherChecks);
        _otherChecksIt = _otherChecks.begin();
    }

    _serverTicks = GameTime::GetGameTimeMS();

    _currentChecks.clear();

    // Build check request
    ByteBuffer buff;
    buff << uint8(WARDEN_SMSG_CHEAT_CHECKS_REQUEST);

    for (uint32 i = 0; i < sWorld->getIntConfig(CONFIG_WARDEN_NUM_MEM_CHECKS); ++i)
    {
        // If todo list is done break loop (will be filled on next Update() run)
        if (_memChecksIt == _memChecks.end())
            break;

        _currentChecks.push_back(*(_memChecksIt++));
    }

    for (uint32 i = 0; i < sWorld->getIntConfig(CONFIG_WARDEN_NUM_OTHER_CHECKS); ++i)
    {
        // If todo list is done break loop (will be filled on next Update() run)
        if (_otherChecksIt == _otherChecks.end())
            break;

        uint16 const id = *(_otherChecksIt++);

        WardenCheck const& check = sWardenCheckMgr->GetCheckDataById(id);
        if (!check.Str.empty())
        {
            buff << uint8(check.Str.size());
            buff.append(check.Str.data(), check.Str.size());
        }
        _currentChecks.push_back(id);
    }

    uint8 xorByte = _inputKey[0];

    // Add TIMING_CHECK
    buff << uint8(0x00);
    buff << uint8(TIMING_CHECK ^ xorByte);

    uint8 index = 1;

    for (uint16 const id : _currentChecks)
    {
        WardenCheck const& check = sWardenCheckMgr->GetCheckDataById(id);

        WardenCheckType const type = check.Type;
        buff << uint8(type ^ xorByte);
        switch (type)
        {
            case MEM_CHECK:
            {
                buff << uint8(0x00);
                buff << uint32(check.Address);
                buff << uint8(check.Length);
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
            case LUA_STR_CHECK:
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

    // Encrypt with warden RC4 key
    EncryptData(buff.contents(), buff.size());

    WorldPacket pkt(SMSG_WARDEN3_DATA, buff.size());
    pkt.append(buff);
    _session->SendPacket(&pkt);

    _dataSent = true;

    std::stringstream stream;
    stream << "Sent check id's: ";
    for (uint16 const id : _currentChecks)
        stream << id << " ";

    TC_LOG_DEBUG("warden", "%s", stream.str().c_str());
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
        WardenCheck const& check = sWardenCheckMgr->GetCheckDataById(id);

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

                std::vector<uint8> response;
                response.resize(check.Length);
                buff.read(response.data(), response.size());
                if (response != sWardenCheckMgr->GetCheckResultById(id))
                {
                    TC_LOG_DEBUG("warden", "RESULT MEM_CHECK fail CheckId %u account Id %u", id, _session->GetAccountId());
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
            case LUA_STR_CHECK:
            {
                uint8 Lua_Result;
                buff >> Lua_Result;

                if (Lua_Result != 0)
                {
                    uint8 luaStrLen = buff.read<uint8>();
                    if (luaStrLen != 0)
                    {
                        std::string str;
                        str.resize(luaStrLen);
                        buff.read(reinterpret_cast<uint8*>(str.data()), luaStrLen);
                        TC_LOG_DEBUG("warden", "Lua string: %s", str.c_str());
                        TC_LOG_DEBUG("warden", "RESULT LUA_STR_CHECK fail, CheckId %u account Id %u", id, _session->GetAccountId());
                        checkFailed = id;
                        continue;
                    }
                }
                TC_LOG_DEBUG("warden", "RESULT LUA_STR_CHECK passed, CheckId %u account Id %u", id, _session->GetAccountId());
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
                if (result != sWardenCheckMgr->GetCheckResultById(id)) // SHA1
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
        WardenCheck const& check = sWardenCheckMgr->GetCheckDataById(checkFailed);
        char const* penalty = ApplyPenalty(&check);
        TC_LOG_WARN("warden", "%s failed Warden check %u (%s). Action: %s", _session->GetPlayerInfo().c_str(), checkFailed, EnumUtils::ToConstant(check.Type), penalty);
    }

    // Set hold off timer, minimum timer should at least be 1 second
    uint32 holdOff = sWorld->getIntConfig(CONFIG_WARDEN_CLIENT_CHECK_HOLDOFF);
    _checkTimer = (holdOff < 1 ? 1 : holdOff) * IN_MILLISECONDS;
}
