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

#include "WardenKeyGen.h"
#include "Common.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "Log.h"
#include "Opcodes.h"
#include "ByteBuffer.h"
#include <openssl/md5.h>
#include "World.h"
#include "Player.h"
#include "Util.h"
#include "WardenMac.h"

WardenMac::WardenMac() : Warden() { }

WardenMac::~WardenMac() { }

void WardenMac::Init(WorldSession* pClient, BigNumber* K)
{
    m_session = pClient;
    // Generate Warden Key
    auto kBytes = K->AsByteArray();
    SHA1Randx WK(kBytes.data(), kBytes.size());
    WK.Generate(m_inputKey, 16);
    WK.Generate(m_outputKey, 16);

    m_selectedModule = sWardenMgr->GetRandomWardenModule(false);

    uint8 mod_seed[16] = { 0x4D, 0x80, 0x8D, 0x2C, 0x77, 0xD9, 0x05, 0xC4, 0x1A, 0x63, 0x80, 0xEC, 0x08, 0x58, 0x6A, 0xFE };

    memcpy(m_seed, mod_seed, 16);

    m_inputCrypto.Init(m_inputKey);
    m_outputCrypto.Init(m_outputKey);
    sLog.outWardenDebug("Server side Mac warden for client %u (build %u) initializing...", pClient->GetAccountId(), m_session->GetGameBuild());
    sLog.outWardenDebug("C->S Key: %s", ByteArrayToHexStr(m_inputKey, 16).c_str());
    sLog.outWardenDebug("S->C Key: %s", ByteArrayToHexStr(m_outputKey, 16).c_str());
    sLog.outWardenDebug("  Seed: %s", ByteArrayToHexStr(m_seed, 16).c_str());
    sLog.outWardenDebug("Loading Module...");

    m_module = GetModuleForClient();

    sLog.outWardenDebug("Module Key: %s", ByteArrayToHexStr(m_module->Key, 16).c_str());
    sLog.outWardenDebug("Module ID: %s", ByteArrayToHexStr(m_module->Id, 16).c_str());
    RequestModule();
}

ClientWardenModule* WardenMac::GetModuleForClient()
{
    ClientWardenModule *mod = new ClientWardenModule;

    uint32 len = m_selectedModule->binaryData.size();

    // data assign
    mod->CompressedSize = len;
    mod->CompressedData = new uint8[len];
    memcpy(mod->CompressedData, m_selectedModule->binaryData.data(), len);
    memcpy(mod->Key, m_selectedModule->moduleKey.data(), 16);

    // md5 hash
    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx, mod->CompressedData, len);
    MD5_Final((uint8*)&mod->Id, &ctx);

    return mod;
}

void WardenMac::InitializeModule()
{
    sLog.outWardenDebug("Initialize module");
    Warden::InitializeModule();
}

struct keyData {
    union
    {
        struct
        {
            uint8 bytes[16];
        } bytes;

        struct
        {
            int ints[4];
        } ints;
    };
};

void WardenMac::HandleHashResult(ByteBuffer &buff)
{

    // test
    int keyIn[4];

    keyData mod_seed = { { { { 0x4D, 0x80, 0x8D, 0x2C, 0x77, 0xD9, 0x05, 0xC4, 0x1A, 0x63, 0x80, 0xEC, 0x08, 0x58, 0x6A, 0xFE } } } };

    for (int i = 0; i < 4; ++i)
    {
        keyIn[i] = mod_seed.ints.ints[i];
    }

    int keyOut[4];
    int keyIn1, keyIn2;
    keyOut[0] = keyIn[0];
    keyIn[0] ^= 0xDEADBEEFu;
    keyIn1 = keyIn[1];
    keyIn[1] -= 0x35014542u;
    keyIn2 = keyIn[2];
    keyIn[2] += 0x5313F22u;
    keyIn[3] *= 0x1337F00Du;
    keyOut[1] = keyIn1 - 0x6A028A84;
    keyOut[2] = keyIn2 + 0xA627E44;
    keyOut[3] = 0x1337F00D * keyIn[3];
    // end test

    buff.rpos(buff.wpos());

    Sha1Hash sha1;
    sha1.UpdateData((uint8*)keyIn, 16);
    sha1.Finalize();

    //const uint8 validHash[20] = { 0x56, 0x8C, 0x05, 0x4C, 0x78, 0x1A, 0x97, 0x2A, 0x60, 0x37, 0xA2, 0x29, 0x0C, 0x22, 0xB5, 0x25, 0x71, 0xA0, 0x6F, 0x4E };

    // Verify key
    if (memcmp(buff.contents() + 1, sha1.GetDigest(), 20) != 0)
    {
        ApplyPenalty("failed hash reply");
        return;
    }

    sLog.outWardenDebug("Request hash reply: succeed");

    // client 7F96EEFDA5B63D20A4DF8E00CBF48304
    //const uint8 client_key[16] = { 0x7F, 0x96, 0xEE, 0xFD, 0xA5, 0xB6, 0x3D, 0x20, 0xA4, 0xDF, 0x8E, 0x00, 0xCB, 0xF4, 0x83, 0x04 };

    // server C2B7ADEDFCCCA9C2BFB3F85602BA809B
    //const uint8 server_key[16] = { 0xC2, 0xB7, 0xAD, 0xED, 0xFC, 0xCC, 0xA9, 0xC2, 0xBF, 0xB3, 0xF8, 0x56, 0x02, 0xBA, 0x80, 0x9B };

    // change keys here
    memcpy(m_inputKey, keyIn, 16);
    memcpy(m_outputKey, keyOut, 16);

    m_inputCrypto.Init(m_inputKey);
    m_outputCrypto.Init(m_outputKey);

    m_previousTimestamp = WorldTimer::getMSTime();
}

void WardenMac::RequestData()
{
    sLog.outWardenDebug("Request data");

    ByteBuffer buff;
    buff << uint8(WARDEN_SMSG_CHEAT_CHECKS_REQUEST);

    std::string str = "Test string!";

    buff << uint8(str.size());
    buff.append(str.c_str(), str.size());

    buff.hexlike();

    // Encrypt with warden RC4 key.
    EncryptData(const_cast<uint8*>(buff.contents()), buff.size());

    WorldPacket pkt(SMSG_WARDEN_DATA, buff.size());
    pkt.append(buff);
    m_session->SendPacket(&pkt);

    Warden::RequestData();
}

void WardenMac::HandleData(ByteBuffer &buff)
{
    sLog.outWardenDebug("Handle data");

    bool found = false;
    std::string reason;

    std::string str = "Test string!";

    Sha1Hash sha1;
    sha1.UpdateData(str);
    uint32 magic = 0xFEEDFACE;                              // unsure
    sha1.UpdateData((uint8*)&magic, 4);
    sha1.Finalize();

    uint8 sha1Hash[20];
    buff.read(sha1Hash, 20);

    if (memcmp(sha1Hash, sha1.GetDigest(), 20) != 0)
    {
        reason = "sent wrong SHA1 hash";
        found = true;
    }

    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx, str.c_str(), str.size());
    uint8 ourMD5Hash[16];
    MD5_Final(ourMD5Hash, &ctx);

    uint8 theirsMD5Hash[16];
    buff.read(theirsMD5Hash, 16);

    if (memcmp(ourMD5Hash, theirsMD5Hash, 16) != 0)
    {
        reason = "sent wrong MD5 hash";
        found = true;
    }

    if (found)
        ApplyPenalty(reason);
    else
        sLog.outWardenDebug("SHA1 and MD5 hash verified. Handle data passed.");

    Warden::HandleData(buff);
}
