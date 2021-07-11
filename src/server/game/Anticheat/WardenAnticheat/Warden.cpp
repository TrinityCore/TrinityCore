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

#include "Common.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "Player.h"
#include "Log.h"
#include "Opcodes.h"
#include "ByteBuffer.h"
#include <openssl/sha.h>
#include "World.h"
#include "Util.h"
#include "Warden.h"
#include "AccountMgr.h"
#include "Language.h"
#include "Anticheat.h"

Warden::Warden() : m_session(nullptr), m_inputCrypto(16), m_outputCrypto(16), m_checkTimer(10000/*10 sec*/), m_clientResponseTimer(0),
                   m_state(WardenState::STATE_INITIAL), m_module(nullptr)
{
    memset(m_inputKey, 0, sizeof(m_inputKey));
    memset(m_outputKey, 0, sizeof(m_outputKey));
    memset(m_seed, 0, sizeof(m_seed));
    m_previousTimestamp = WorldTimer::getMSTime();
}

Warden::~Warden()
{
    delete[] m_module->CompressedData;
    delete m_module;
    m_module = nullptr;
}

void Warden::InitializeModule()
{
    SetNewState(WardenState::STATE_INITIALIZE_MODULE);
}

void Warden::RequestHash()
{
    sLog.outWardenDebug("Requesting hash");

    // Create packet structure
    WardenHashRequest Request;
    Request.Command = WARDEN_SMSG_HASH_REQUEST;
    memcpy(Request.Seed, m_seed, 16);

    // Encrypt with warden RC4 key.
    EncryptData((uint8*)&Request, sizeof(WardenHashRequest));

    WorldPacket pkt(SMSG_WARDEN_DATA, sizeof(WardenHashRequest));
    pkt.append((uint8*)&Request, sizeof(WardenHashRequest));
    m_session->SendPacket(&pkt);

    SetNewState(WardenState::STATE_REQUESTED_HASH);
}

void Warden::SendModuleToClient()
{
    sLog.outWardenDebug("Sending module to client");

    // Create packet structure
    WardenModuleTransfer packet;

    uint32 sizeLeft = m_module->CompressedSize;
    uint32 pos = 0;
    uint16 burstSize;
    while (sizeLeft > 0)
    {
        burstSize = sizeLeft < 500 ? sizeLeft : 500;
        packet.Command = WARDEN_SMSG_MODULE_CACHE;
        packet.DataSize = burstSize;
        memcpy(packet.Data, &m_module->CompressedData[pos], burstSize);
        sizeLeft -= burstSize;
        pos += burstSize;

        EncryptData((uint8*)&packet, burstSize + 3);
        WorldPacket pkt1(SMSG_WARDEN_DATA, burstSize + 3);
        pkt1.append((uint8*)&packet, burstSize + 3);
        m_session->SendPacket(&pkt1);
    }

    SetNewState(WardenState::STATE_SENT_MODULE);
}

void Warden::RequestModule()
{
    sLog.outWardenDebug("Requesting module");

    // Create packet structure
    WardenModuleUse request;
    request.Command = WARDEN_SMSG_MODULE_USE;

    memcpy(request.ModuleId, m_module->Id, 16);
    memcpy(request.ModuleKey, m_module->Key, 16);
    request.Size = m_module->CompressedSize;

    // Encrypt with warden RC4 key.
    EncryptData((uint8*)&request, sizeof(WardenModuleUse));

    WorldPacket pkt(SMSG_WARDEN_DATA, sizeof(WardenModuleUse));
    pkt.append((uint8*)&request, sizeof(WardenModuleUse));
    m_session->SendPacket(&pkt);

    SetNewState(WardenState::STATE_REQUESTED_MODULE);
}

void Warden::Update()
{
    uint32 currentTimestamp = WorldTimer::getMSTime();
    uint32 diff = currentTimestamp - m_previousTimestamp;
    m_previousTimestamp = currentTimestamp;

    switch (m_state)
    {
        case WardenState::STATE_INITIAL:
            break;
        case WardenState::STATE_REQUESTED_MODULE:
        case WardenState::STATE_SENT_MODULE:
        case WardenState::STATE_REQUESTED_HASH:
        case WardenState::STATE_REQUESTED_DATA:
        {
            uint32 maxClientResponseDelay = sWorld.getConfig(CONFIG_UINT32_AC_WARDEN_CLIENT_RESPONSE_DELAY);

            if (maxClientResponseDelay > 0)
            {
                // Kick player if client response delays more than set in config
                if (m_clientResponseTimer > maxClientResponseDelay * IN_MILLISECONDS)
                {
                    sLog.outWarden("Account %u (latency: %u, IP: %s) exceeded Warden module response delay on state %s for more than %s - disconnecting client",
                                   m_session->GetAccountId(), m_session->GetLatency(), m_session->GetRemoteAddress().c_str(), WardenState::to_string(m_state), secsToTimeString(maxClientResponseDelay, true).c_str());
                    m_session->KickPlayer();
                }
                else
                {
                    m_clientResponseTimer += diff;
                }

            }
        }
        break;
        case WardenState::STATE_INITIALIZE_MODULE:
        case WardenState::STATE_RESTING:
        {
            if (diff >= m_checkTimer)
            {
                RequestData();
            }
            else
            {
                m_checkTimer -= diff;
            }
        }
        break;
        default:
            sLog.outWarden("Unimplemented warden state!");
            break;
    }
}

void Warden::DecryptData(uint8* buffer, uint32 length)
{
    m_inputCrypto.UpdateData(length, buffer);
}

void Warden::EncryptData(uint8* buffer, uint32 length)
{
    m_outputCrypto.UpdateData(length, buffer);
}

void Warden::SetNewState(WardenState::Value state)
{
    // if we pass all initial checks, allow change
    if (state < WardenState::STATE_REQUESTED_DATA)
    {
        if (state < m_state)
        {
            sLog.outWarden("Jump from %s to %s which is lower by initialization routine", WardenState::to_string(m_state), WardenState::to_string(state));
            return;
        }
    }

    m_state = state;

    // Reset timers
    // Set hold off timer, minimum timer should at least be 1 second
    uint32 holdOff = sWorld.getConfig(CONFIG_UINT32_AC_WARDEN_CLIENT_CHECK_HOLDOFF);
    m_checkTimer = (holdOff < 1 ? 1 : holdOff) * IN_MILLISECONDS;

    m_clientResponseTimer = 0;
}

bool Warden::IsValidCheckSum(uint32 checksum, const uint8* data, const uint16 length)
{
    uint32 newChecksum = BuildChecksum(data, length);

    if (checksum != newChecksum)
    {
        sLog.outWardenDebug("CHECKSUM IS NOT VALID");
        return false;
    }
    else
    {
        sLog.outWardenDebug("CHECKSUM IS VALID");
        return true;
    }
}

struct keyData {
    union
    {
        struct
        {
            uint8 bytes[20];
        } bytes;

        struct
        {
            uint32 ints[5];
        } ints;
    };
};

uint32 Warden::BuildChecksum(const uint8* data, uint32 length)
{
    keyData hash;
    SHA1(data, length, hash.bytes.bytes);
    uint32 checkSum = 0;
    for (uint8 i = 0; i < 5; ++i)
        checkSum = checkSum ^ hash.ints.ints[i];

    return checkSum;
}

void Warden::ApplyPenalty(std::string message, WardenCheck* check)
{
    WardenActions action;

    if (check)
        action = check->Action;
    else
        action = WardenActions(sWorld.getConfig(CONFIG_UINT32_AC_WARDEN_DEFAULT_PENALTY));

    std::string playerName = m_session->GetPlayerName();
    std::string accountName = std::to_string(m_session->GetAccountId());
    sAccountMgr.GetName(m_session->GetAccountId(), accountName);

    switch (action)
    {
        case WARDEN_ACTION_KICK:
            m_session->KickPlayer();
            break;
        case WARDEN_ACTION_BAN:
            {
                std::stringstream duration;
                std::stringstream banReason;
                banReason << "Warden Anticheat Violation";
                // Check can be NULL, for example if the client sent a wrong signature in the warden packet (CHECKSUM FAIL)
                if (check)
                    banReason << ": " << (check->Comment.empty() ? std::string("Undocumented Check") : check->Comment) << " (CheckId: " << check->CheckId << ")";

                sWorld.BanAccount(BAN_ACCOUNT, accountName, sWorld.getConfig(CONFIG_UINT32_AC_WARDEN_CLIENT_BAN_DURATION), banReason.str(), "Warden");
            }
        default:
            break;
    }

    // Append names to message.
    message = "Player " + playerName + " (Account " + accountName + ") " + message;

    sLog.outWarden(message.c_str());
    sWorld.SendGMText(LANG_GM_ANNOUNCE_COLOR, "WardenAnticheat", message.c_str());
}

void Warden::HandleWardenDataOpcode(WorldPacket& recvData)
{
    if (recvData.empty())
        return;

    DecryptData(const_cast<uint8*>(recvData.contents()), recvData.size());
    uint8 opcode;
    recvData >> opcode;
    sLog.outWardenDebug("Got packet, opcode %02X, size %u", opcode, uint32(recvData.size()));
    recvData.hexlike();

    switch (opcode)
    {
        case WARDEN_CMSG_MODULE_MISSING:
            SendModuleToClient();
            break;
        case WARDEN_CMSG_MODULE_OK:
            RequestHash();
            break;
        case WARDEN_CMSG_CHEAT_CHECKS_RESULT:
            HandleData(recvData);
            break;
        case WARDEN_CMSG_MEM_CHECKS_RESULT:
            sLog.outWarden("NYI WARDEN_CMSG_MEM_CHECKS_RESULT received!");
            break;
        case WARDEN_CMSG_HASH_RESULT:
            HandleHashResult(recvData);
            InitializeModule();
            break;
        case WARDEN_CMSG_MODULE_FAILED:
            ApplyPenalty("sent module failed opcode", nullptr);
            break;
        default:
            sLog.outWarden("Got unknown warden opcode %02X of size %u.", opcode, uint32(recvData.size() - 1));
            break;
    }
}

void Warden::RequestData()
{
    SetNewState(WardenState::STATE_REQUESTED_DATA);
}

void Warden::HandleData(ByteBuffer& /*buff*/)
{
    SetNewState(WardenState::STATE_RESTING);
}

void Warden::LogPositiveToDB(WardenCheck* check)
{
    if (!check || !m_session)
        return;

    if (uint32(check->Action) < sWorld.getConfig(CONFIG_UINT32_AC_WARDEN_DB_LOGLEVEL))
        return;

    static SqlStatementID insWardenPositive;

    SqlStatement stmt = LogsDatabase.CreateStatement(insWardenPositive, "INSERT INTO `logs_warden` (`check`, `action`, `account`, `guid`, `map`, `position_x`, `position_y`, `position_z`) VALUES (?, ?, ?, ?, ?, ?, ?, ?)");

    stmt.addUInt16(check->CheckId);
    stmt.addInt8(check->Action);
    stmt.addUInt32(m_session->GetAccountId());
    if (Player* pl = m_session->GetPlayer())
    {
        stmt.addUInt64(pl->GetObjectGuid().GetRawValue());
        stmt.addUInt32(pl->GetMapId());
        stmt.addFloat(pl->GetPositionX());
        stmt.addFloat(pl->GetPositionY());
        stmt.addFloat(pl->GetPositionZ());
    }
    else
    {
        stmt.addUInt64(0);
        stmt.addUInt32(0xFFFFFFFF);
        stmt.addFloat(0.0f);
        stmt.addFloat(0.0f);
        stmt.addFloat(0.0f);
    }
    stmt.Execute();
}
