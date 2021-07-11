/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "Auth/HMACSHA1.h"
#include "WardenKeyGen.h"
#include "Common.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "Log.h"
#include "Opcodes.h"
#include "ByteBuffer.h"
#include <openssl/md5.h>
#include "Database/DatabaseEnv.h"
#include "World.h"
#include "Player.h"
#include "Util.h"
#include "WardenWin.h"
#include "WardenMgr.h"
#include "Anticheat.h"

WardenWin::WardenWin() : Warden(), _serverTicks(0) {}

WardenWin::~WardenWin() { }

void WardenWin::Init(WorldSession* session, BigNumber* k)
{
    m_session = session;

    // Generate Warden Key
    auto kBytes = k->AsByteArray();
    SHA1Randx WK(kBytes.data(), kBytes.size());
    WK.Generate(m_inputKey, 16);
    WK.Generate(m_outputKey, 16);

    m_selectedModule = sWardenMgr->GetRandomWardenModule(true);
    
    memcpy(m_seed, m_selectedModule->challengeData[0].seed, 16);

    m_inputCrypto.Init(m_inputKey);
    m_outputCrypto.Init(m_outputKey);
    sLog.outWardenDebug("Server side warden for client %u (build %u) initializing...", session->GetAccountId(), m_session->GetGameBuild());
    sLog.outWardenDebug("C->S Key: %s", ByteArrayToHexStr(m_inputKey, 16).c_str());
    sLog.outWardenDebug("S->C Key: %s", ByteArrayToHexStr(m_outputKey, 16).c_str());
    sLog.outWardenDebug("  Seed: %s", ByteArrayToHexStr(m_seed, 16).c_str());
    sLog.outWardenDebug("Loading Module...");

    m_module = GetModuleForClient();

    sLog.outWardenDebug("Module Key: %s", ByteArrayToHexStr(m_module->Key, 16).c_str());
    sLog.outWardenDebug("Module ID: %s", ByteArrayToHexStr(m_module->Id, 16).c_str());
    RequestModule();
}

ClientWardenModule* WardenWin::GetModuleForClient()
{
    ClientWardenModule *mod = new ClientWardenModule;

    uint32 length = m_selectedModule->binaryData.size();

    // data assign
    mod->CompressedSize = length;
    mod->CompressedData = new uint8[length];
    memcpy(mod->CompressedData, m_selectedModule->binaryData.data(), length);
    memcpy(mod->Key, m_selectedModule->moduleKey.data(), 16);
    memcpy(mod->Id, m_selectedModule->binaryHash.data(), m_selectedModule->binaryHash.size());

    return mod;
}

void WardenWin::InitializeModule()
{
    sLog.outWardenDebug("Initialize module");

    // Create packet structure
    WardenInitModuleRequest Request;
    Request.Command1 = WARDEN_SMSG_MODULE_INITIALIZE;
    Request.Size1 = 20;
    Request.CheckSumm1 = BuildChecksum(&Request.Unk1, 20);
    Request.Unk1 = 1;
    Request.Unk2 = 0;
    Request.Type = 1;
    Request.String_library1 = 0;
    Request.Function1[0] = 0x002485F0;                      // 0x00400000 + 0x002485F0 SFileOpenFile
    Request.Function1[1] = 0x002487F0;                      // 0x00400000 + 0x002487F0 SFileGetFileSize
    Request.Function1[2] = 0x00248460;                      // 0x00400000 + 0x00248460 SFileReadFile
    Request.Function1[3] = 0x00248730;                      // 0x00400000 + 0x00248730 SFileCloseFile

    Request.Command2 = WARDEN_SMSG_MODULE_INITIALIZE;
    Request.Size2 = 8;
    Request.CheckSumm2 = BuildChecksum(&Request.Unk2, 8);
    Request.Unk3 = 4;
    Request.Unk4 = 0;
    Request.String_library2 = 0;
    Request.Function2 = 0x00419D40;                         // 0x00400000 + 0x00419D40 FrameScript::GetText
    Request.Function2_set = 1;

    Request.Command3 = WARDEN_SMSG_MODULE_INITIALIZE;
    Request.Size3 = 8;
    Request.CheckSumm3 = BuildChecksum(&Request.Unk5, 8);
    Request.Unk5 = 1;
    Request.Unk6 = 1;
    Request.String_library3 = 0;
    Request.Function3 = 0x0046AE20;                         // 0x00400000 + 0x0046AE20 PerformanceCounter
    Request.Function3_set = 1;

    // Encrypt with warden RC4 key.
    EncryptData((uint8*)&Request, sizeof(WardenInitModuleRequest));

    WorldPacket pkt(SMSG_WARDEN_DATA, sizeof(WardenInitModuleRequest));
    pkt.append((uint8*)&Request, sizeof(WardenInitModuleRequest));
    m_session->SendPacket(&pkt);

    Warden::InitializeModule();
}

void WardenWin::HandleHashResult(ByteBuffer &buff)
{
    buff.rpos(buff.wpos());

    // Verify key
    if (memcmp(buff.contents() + 1, m_selectedModule->challengeData[0].reply, sizeof(m_selectedModule->challengeData[0].reply)) != 0)
    {
        ApplyPenalty("failed hash reply");
        return;
    }

    sLog.outWardenDebug("Request hash reply: succeed");

    // Change keys here
    memcpy(m_inputKey, m_selectedModule->challengeData[0].clientKey, 16);
    memcpy(m_outputKey, m_selectedModule->challengeData[0].serverKey, 16);

    m_inputCrypto.Init(m_inputKey);
    m_outputCrypto.Init(m_outputKey);

    m_previousTimestamp = WorldTimer::getMSTime();
}

void WardenWin::RequestData()
{
    sLog.outWardenDebug("Request data");

    uint16 build = m_session->GetGameBuild();
    uint16 id = 0;
    WardenCheck* wd = nullptr;

    // If all checks were done, fill the todo list again
    if (_memChecksTodo.empty())
        sWardenMgr->GetWardenCheckIds(true, build, _memChecksTodo);

    if (_otherChecksTodo.empty())
        sWardenMgr->GetWardenCheckIds(false, build, _otherChecksTodo);

    _serverTicks = WorldTimer::getMSTime();

    _currentChecks.clear();

    // Build check request
    for (uint16 i = 0; i < sWorld.getConfig(CONFIG_UINT32_AC_WARDEN_NUM_MEM_CHECKS); ++i)
    {
        // If todo list is done break loop (will be filled on next Update() run)
        if (_memChecksTodo.empty())
            break;

        // Get check id from the end and remove it from todo
        id = _memChecksTodo.back();
        _memChecksTodo.pop_back();

        // Add the id to the list sent in this cycle
        _currentChecks.push_back(id);
    }

    ByteBuffer buff;
    buff << uint8(WARDEN_SMSG_CHEAT_CHECKS_REQUEST);

    for (uint16 i = 0; i < sWorld.getConfig(CONFIG_UINT32_AC_WARDEN_NUM_OTHER_CHECKS); ++i)
    {
        // If todo list is done break loop (will be filled on next Update() run)
        if (_otherChecksTodo.empty())
            break;

        // Get check id from the end and remove it from todo
        id = _otherChecksTodo.back();
        _otherChecksTodo.pop_back();

        // Add the id to the list sent in this cycle
        _currentChecks.push_back(id);

        // if we are here, the function is guaranteed to not return NULL
        // but ... who knows
        wd = sWardenMgr->GetWardenDataById(build, id);
        if (wd)
        {
            switch (wd->Type)
            {
                case MPQ_CHECK:
                case LUA_STR_CHECK:
                case DRIVER_CHECK:
                    buff << uint8(wd->Str.size());
                    buff.append(wd->Str.c_str(), wd->Str.size());
                    break;
                default:
                    break;
            }
        }
    }

    uint8 xorByte = m_inputKey[0];

    // Add TIMING_CHECK
    buff << uint8(0x00);
    buff << uint8(m_selectedModule->scanTypes[TIMING_CHECK] ^ xorByte);
    
    uint8 index = 1;

    for (std::list<uint16>::iterator itr = _currentChecks.begin(); itr != _currentChecks.end(); ++itr)
    {
        wd = sWardenMgr->GetWardenDataById(build, *itr);
        
        uint8 scanOpcode = m_selectedModule->scanTypes[wd->Type];
        buff << uint8(scanOpcode ^ xorByte);
        switch (wd->Type)
        {
            case MEM_CHECK:
            {
                buff << uint8(0x00);
                buff << uint32(wd->Address);
                buff << uint8(wd->Length);
                break;
            }
            case PAGE_CHECK_A:
            case PAGE_CHECK_B:
            {
                buff.append(wd->Data.AsByteArray(0, false).data(), wd->Data.GetNumBytes());
                buff << uint32(wd->Address);
                buff << uint8(wd->Length);
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
                buff.append(wd->Data.AsByteArray(0, false).data(), wd->Data.GetNumBytes());
                buff << uint8(index++);
                break;
            }
            case MODULE_CHECK:
            {
                uint32 seed = static_cast<uint32>(rand32());
                buff << uint32(seed);
                HMACSHA1 hmac(4, (uint8*)&seed);
                hmac.UpdateData(wd->Str);
                hmac.Finalize();
                buff.append(hmac.GetDigest(), hmac.GetLength());
                break;
            }
            /*case PROC_CHECK:
            {
                auto data = wd->Data.AsByteArray(0, false);
                buff.append(data);
                buff << uint8(index++);
                buff << uint8(index++);
                buff << uint32(wd->Address);
                buff << uint8(wd->Length);
                break;
            }*/
            default:
                break;                                      // Should never happen
        }
    }
    buff << uint8(xorByte);
    buff.hexlike();

    // Encrypt with warden RC4 key
    EncryptData((uint8*)buff.contents(), buff.size());

    WorldPacket pkt(SMSG_WARDEN_DATA, buff.size());
    pkt.append(buff);
    m_session->SendPacket(&pkt);

    std::stringstream stream;
    stream << "Sent check id's: ";
    for (std::list<uint16>::iterator itr = _currentChecks.begin(); itr != _currentChecks.end(); ++itr)
        stream << *itr << " ";

    sLog.outWardenDebug("%s", stream.str().c_str());

    Warden::RequestData();
}

void WardenWin::HandleData(ByteBuffer &buff)
{
    sLog.outWardenDebug("Handle data");

    uint16 Length;
    buff >> Length;
    uint32 Checksum;
    buff >> Checksum;

    if (!IsValidCheckSum(Checksum, buff.contents() + buff.rpos(), Length))
    {
        buff.rpos(buff.wpos());
        ApplyPenalty("failed checksum test");
        return;
    }

    // TIMING_CHECK
    {
        uint8 result;
        buff >> result;
        /// @todo test it.
        if (result == 0x00)
        {
            ApplyPenalty("failed timing check");
            return;
        }

        uint32 newClientTicks;
        buff >> newClientTicks;

        uint32 ticksNow = WorldTimer::getMSTime();
        uint32 ourTicks = newClientTicks + (ticksNow - _serverTicks);

        sLog.outWardenDebug("ServerTicks %u, RequestTicks %u, ClientTicks %u", ticksNow, _serverTicks, newClientTicks);  // Now, At request, At response
        sLog.outWardenDebug("Waittime %u", ourTicks - newClientTicks);

    }

    WardenCheckResult* rs;
    WardenCheck *rd;
    uint8 type;
    uint16 checkFailed = 0;

    for (std::list<uint16>::iterator itr = _currentChecks.begin(); itr != _currentChecks.end(); ++itr)
    {
        rd = sWardenMgr->GetWardenDataById(m_session->GetGameBuild(), *itr);
        rs = sWardenMgr->GetWardenResultById(m_session->GetGameBuild(), *itr);

        type = rd->Type;
        switch (type)
        {
            case MEM_CHECK:
            {
                uint8 Mem_Result;
                buff >> Mem_Result;

                if (Mem_Result != 0)
                {
                    sLog.outWardenDebug("RESULT MEM_CHECK not 0x00, CheckId %u account Id %u", *itr, m_session->GetAccountId());
                    checkFailed = *itr;
                    continue;
                }
                if (memcmp(buff.contents() + buff.rpos(), rs->Result.AsByteArray(0, false).data(), rd->Length) != 0)
                {
                    sLog.outWardenDebug("RESULT MEM_CHECK fail CheckId %u account Id %u", *itr, m_session->GetAccountId());
                    checkFailed = *itr;
                    buff.rpos(buff.rpos() + rd->Length);
                    continue;
                }

                buff.rpos(buff.rpos() + rd->Length);
                sLog.outWardenDebug("RESULT MEM_CHECK passed CheckId %u account Id %u", *itr, m_session->GetAccountId());
                break;
            }
            case PAGE_CHECK_A:
            case PAGE_CHECK_B:
            case DRIVER_CHECK:
            case MODULE_CHECK:
            {
                const uint8 byte = 0xE9;
                if (memcmp(buff.contents() + buff.rpos(), &byte, sizeof(uint8)) != 0)
                {
                    if (type == PAGE_CHECK_A || type == PAGE_CHECK_B)
                        sLog.outWardenDebug("RESULT PAGE_CHECK fail, CheckId %u account Id %u", *itr, m_session->GetAccountId());
                    if (type == MODULE_CHECK)
                        sLog.outWardenDebug("RESULT MODULE_CHECK fail, CheckId %u account Id %u", *itr, m_session->GetAccountId());
                    if (type == DRIVER_CHECK)
                        sLog.outWardenDebug("RESULT DRIVER_CHECK fail, CheckId %u account Id %u", *itr, m_session->GetAccountId());
                    checkFailed = *itr;
                    buff.rpos(buff.rpos() + 1);
                    continue;
                }

                buff.rpos(buff.rpos() + 1);
                if (type == PAGE_CHECK_A || type == PAGE_CHECK_B)
                    sLog.outWardenDebug("RESULT PAGE_CHECK passed CheckId %u account Id %u", *itr, m_session->GetAccountId());
                else if (type == MODULE_CHECK)
                    sLog.outWardenDebug("RESULT MODULE_CHECK passed CheckId %u account Id %u", *itr, m_session->GetAccountId());
                else if (type == DRIVER_CHECK)
                    sLog.outWardenDebug("RESULT DRIVER_CHECK passed CheckId %u account Id %u", *itr, m_session->GetAccountId());
                break;
            }
            case LUA_STR_CHECK:
            {
                uint8 Lua_Result;
                buff >> Lua_Result;

                if (Lua_Result != 0)
                {
                    sLog.outWardenDebug("RESULT LUA_STR_CHECK fail, CheckId %u account Id %u", *itr, m_session->GetAccountId());
                    checkFailed = *itr;
                    continue;
                }

                uint8 luaStrLen;
                buff >> luaStrLen;

                if (luaStrLen != 0)
                {
                    char *str = new char[luaStrLen + 1];
                    memcpy(str, buff.contents() + buff.rpos(), luaStrLen);
                    str[luaStrLen] = '\0'; // null terminator
                    sLog.outWardenDebug("Lua string: %s", str);
                    delete[] str;
                }
                buff.rpos(buff.rpos() + luaStrLen);         // Skip string
                sLog.outWardenDebug("RESULT LUA_STR_CHECK passed, CheckId %u account Id %u", *itr, m_session->GetAccountId());
                break;
            }
            case MPQ_CHECK:
            {
                uint8 Mpq_Result;
                buff >> Mpq_Result;

                if (Mpq_Result != 0)
                {
                    sLog.outWardenDebug("RESULT MPQ_CHECK not 0x00 account id %u", m_session->GetAccountId());
                    checkFailed = *itr;
                    continue;
                }

                if (memcmp(buff.contents() + buff.rpos(), rs->Result.AsByteArray(0, false).data(), 20) != 0) // SHA1
                {
                    sLog.outWardenDebug("RESULT MPQ_CHECK fail, CheckId %u account Id %u", *itr, m_session->GetAccountId());
                    checkFailed = *itr;
                    buff.rpos(buff.rpos() + 20);            // 20 bytes SHA1
                    continue;
                }

                buff.rpos(buff.rpos() + 20);                // 20 bytes SHA1
                sLog.outWardenDebug("RESULT MPQ_CHECK passed, CheckId %u account Id %u", *itr, m_session->GetAccountId());
                break;
            }
            default:                                        // Should never happen
                break;
        }
    }

    if (checkFailed > 0)
    {
        WardenCheck* check = sWardenMgr->GetWardenDataById(m_session->GetGameBuild(), checkFailed);   //note it IS NOT NULL here
        ApplyPenalty(std::string("failed Warden check ") + std::to_string(checkFailed), check);
        LogPositiveToDB(check);
    }

    Warden::HandleData(buff);
}
