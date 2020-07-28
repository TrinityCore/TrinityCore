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

#include "WardenMac.h"
#include "ByteBuffer.h"
#include "Common.h"
#include "GameTime.h"
#include "Log.h"
#include "Opcodes.h"
#include "Player.h"
#include "SessionKeyGenerator.h"
#include "Util.h"
#include "WardenModuleMac.h"
#include "WorldPacket.h"
#include "WorldSession.h"

#include <openssl/md5.h>

WardenMac::WardenMac() : Warden() { }

WardenMac::~WardenMac() { }

void WardenMac::Init(WorldSession* pClient, SessionKey const& K)
{
    _session = pClient;
    // Generate Warden Key
    SessionKeyGenerator<Trinity::Crypto::SHA1> WK(K);
    WK.Generate(_inputKey, 16);
    WK.Generate(_outputKey, 16);
    /*
    Seed: 4D808D2C77D905C41A6380EC08586AFE (0x05 packet)
    Hash: <?> (0x04 packet)
    Module MD5: 0DBBF209A27B1E279A9FEC5C168A15F7
    New Client Key: <?>
    New Cerver Key: <?>
    */
    uint8 mod_seed[16] = { 0x4D, 0x80, 0x8D, 0x2C, 0x77, 0xD9, 0x05, 0xC4, 0x1A, 0x63, 0x80, 0xEC, 0x08, 0x58, 0x6A, 0xFE };

    memcpy(_seed, mod_seed, 16);

    _inputCrypto.Init(_inputKey);
    _outputCrypto.Init(_outputKey);
    TC_LOG_DEBUG("warden", "Server side warden for client %u initializing...", pClient->GetAccountId());
    TC_LOG_DEBUG("warden", "C->S Key: %s", ByteArrayToHexStr(_inputKey, 16).c_str());
    TC_LOG_DEBUG("warden", "S->C Key: %s", ByteArrayToHexStr(_outputKey, 16).c_str());
    TC_LOG_DEBUG("warden", "  Seed: %s", ByteArrayToHexStr(_seed, 16).c_str());
    TC_LOG_DEBUG("warden", "Loading Module...");

    _module = GetModuleForClient();

    TC_LOG_DEBUG("warden", "Module Key: %s", ByteArrayToHexStr(_module->Key, 16).c_str());
    TC_LOG_DEBUG("warden", "Module ID: %s", ByteArrayToHexStr(_module->Id, 16).c_str());
    RequestModule();
}

ClientWardenModule* WardenMac::GetModuleForClient()
{
    ClientWardenModule *mod = new ClientWardenModule;

    uint32 len = sizeof(Module_0DBBF209A27B1E279A9FEC5C168A15F7_Data);

    // data assign
    mod->CompressedSize = len;
    mod->CompressedData = new uint8[len];
    memcpy(mod->CompressedData, Module_0DBBF209A27B1E279A9FEC5C168A15F7_Data, len);
    memcpy(mod->Key, Module_0DBBF209A27B1E279A9FEC5C168A15F7_Key, 16);

    // md5 hash
    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx, mod->CompressedData, len);
    MD5_Final((uint8*)&mod->Id, &ctx);

    return mod;
}

void WardenMac::InitializeModule()
{
    TC_LOG_DEBUG("warden", "Initialize module");
}

void WardenMac::RequestHash()
{
    TC_LOG_DEBUG("warden", "Request hash");

    // Create packet structure
    WardenHashRequest Request;
    Request.Command = WARDEN_SMSG_HASH_REQUEST;
    memcpy(Request.Seed, _seed, 16);

    // Encrypt with warden RC4 key.
    EncryptData((uint8*)&Request, sizeof(WardenHashRequest));

    WorldPacket pkt(SMSG_WARDEN_DATA, sizeof(WardenHashRequest));
    pkt.append((uint8*)&Request, sizeof(WardenHashRequest));
    _session->SendPacket(&pkt);
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

    Trinity::Crypto::SHA1 sha1;
    sha1.UpdateData((uint8*)keyIn, 16);
    sha1.Finalize();

    //const uint8 validHash[20] = { 0x56, 0x8C, 0x05, 0x4C, 0x78, 0x1A, 0x97, 0x2A, 0x60, 0x37, 0xA2, 0x29, 0x0C, 0x22, 0xB5, 0x25, 0x71, 0xA0, 0x6F, 0x4E };

    // Verify key
    if (memcmp(buff.contents() + 1, sha1.GetDigest().data(), 20) != 0)
    {
        TC_LOG_WARN("warden", "%s failed hash reply. Action: %s", _session->GetPlayerInfo().c_str(), Penalty().c_str());
        return;
    }

    TC_LOG_DEBUG("warden", "Request hash reply: succeed");

    // client 7F96EEFDA5B63D20A4DF8E00CBF48304
    //const uint8 client_key[16] = { 0x7F, 0x96, 0xEE, 0xFD, 0xA5, 0xB6, 0x3D, 0x20, 0xA4, 0xDF, 0x8E, 0x00, 0xCB, 0xF4, 0x83, 0x04 };

    // server C2B7ADEDFCCCA9C2BFB3F85602BA809B
    //const uint8 server_key[16] = { 0xC2, 0xB7, 0xAD, 0xED, 0xFC, 0xCC, 0xA9, 0xC2, 0xBF, 0xB3, 0xF8, 0x56, 0x02, 0xBA, 0x80, 0x9B };

    // change keys here
    memcpy(_inputKey, keyIn, 16);
    memcpy(_outputKey, keyOut, 16);

    _inputCrypto.Init(_inputKey);
    _outputCrypto.Init(_outputKey);

    _initialized = true;

    _previousTimestamp = GameTime::GetGameTimeMS();
}

void WardenMac::RequestData()
{
    TC_LOG_DEBUG("warden", "Request data");

    ByteBuffer buff;
    buff << uint8(WARDEN_SMSG_CHEAT_CHECKS_REQUEST);

    std::string str = "Test string!";

    buff << uint8(str.size());
    buff.append(str.c_str(), str.size());

    buff.hexlike();

    // Encrypt with warden RC4 key.
    EncryptData(buff.contents(), buff.size());

    WorldPacket pkt(SMSG_WARDEN_DATA, buff.size());
    pkt.append(buff);
    _session->SendPacket(&pkt);

    _dataSent = true;
}

void WardenMac::HandleData(ByteBuffer &buff)
{
    TC_LOG_DEBUG("warden", "Handle data");

    _dataSent = false;
    _clientResponseTimer = 0;

    //uint16 Length;
    //buff >> Length;
    //uint32 Checksum;
    //buff >> Checksum;

    //if (!IsValidCheckSum(Checksum, buff.contents() + buff.rpos(), Length))
    //{
    //    buff.rpos(buff.wpos());
    //    if (sWorld->getBoolConfig(CONFIG_BOOL_WARDEN_KICK))
    //        Client->KickPlayer();
    //    return;
    //}

    //bool found = false;

    std::string str = "Test string!";

    Trinity::Crypto::SHA1 sha1;
    sha1.UpdateData(str);
    uint32 magic = 0xFEEDFACE;                              // unsure
    sha1.UpdateData((uint8*)&magic, 4);
    sha1.Finalize();

    std::array<uint8, Trinity::Crypto::SHA1::DIGEST_LENGTH> sha1Hash;
    buff.read(sha1Hash.data(), sha1Hash.size());

    if (sha1Hash != sha1.GetDigest())
    {
        TC_LOG_DEBUG("warden", "Handle data failed: SHA1 hash is wrong!");
        //found = true;
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
        TC_LOG_DEBUG("warden", "Handle data failed: MD5 hash is wrong!");
        //found = true;
    }

    _session->KickPlayer();
}
