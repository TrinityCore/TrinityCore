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

#ifndef ANTICHEAT_H
#define ANTICHEAT_H

#include "Common.h"
#include "AbstractPlayer.h"
#include "UnitDefines.h"

enum WardenActions
{
    WARDEN_ACTION_LOG,
    WARDEN_ACTION_KICK,
    WARDEN_ACTION_BAN,
    WARDEN_ACTION_MAX
};

enum CheatAction
{
    CHEAT_ACTION_NONE             = 0x00,
    CHEAT_ACTION_LOG              = 0x01,
    CHEAT_ACTION_REPORT_GMS       = 0x02,
    CHEAT_ACTION_GLOBAL_ANNOUNNCE = 0x04,
    CHEAT_ACTION_KICK             = 0x08,
    CHEAT_ACTION_BAN_ACCOUNT      = 0x10,
    CHEAT_ACTION_BAN_IP_ACCOUNT   = 0x20,
    CHEAT_ACTION_MUTE_PUB_CHANS   = 0x40, // Mutes the account from public channels
    CHEAT_MAX_ACTIONS,
};

class Unit;
class Player;
class MovementInfo;
class BigNumber;
class WorldPacket;
class WorldSession;
class ChatHandler;
class Warden;
class MovementAnticheat;
class AccountPersistentData;
struct AreaEntry;

class AntispamInterface
{
public:
    virtual ~AntispamInterface() {}

    virtual void loadData() {}
    virtual void loadConfig() {}

    virtual std::string normalizeMessage(std::string const& msg, uint32 mask = 0) { return msg; }
    virtual bool filterMessage(std::string const& msg) { return 0; }

    virtual void addMessage(std::string const& msg, uint32 type, PlayerPointer from, PlayerPointer to) {}

    virtual bool isMuted(uint32 accountId, bool checkChatType = false, uint32 chatType = 0) const { return false; }
    virtual void mute(uint32 accountId) {}
    virtual void unmute(uint32 accountId) {}
    virtual void showMuted(WorldSession* session) {}
};

#ifdef USE_ANTICHEAT
#include "WardenAnticheat/Warden.h"
#include "MovementAnticheat/MovementAnticheat.h"
#else
class Warden
{
public:
    Warden() = default;
    ~Warden() = default;
    void HandleWardenDataOpcode(WorldPacket& recv_data) {}
    void Update() {}
    WorldSession* GetSession() { return nullptr; }
};

class MovementAnticheat
{
public:
    MovementAnticheat() = default;
    ~MovementAnticheat() = default;

    void Init() {}
    void InitNewPlayer(Player* pPlayer) {}
    void ResetJumpCounters() {}

    bool IsInKnockBack() const { return false; }

    uint32 Update(uint32 diff, std::stringstream& reason) { return CHEAT_ACTION_NONE; }
    uint32 Finalize(std::stringstream& reason) { return CHEAT_ACTION_NONE; }
    void AddCheats(uint32 cheats, uint32 count = 1) {}
    void HandleCommand(ChatHandler* handler) const {}
    void OnKnockBack(Player* pPlayer, float speedxy, float speedz, float cos, float sin) {}

    void OnUnreachable(Unit* attacker) {}
    void OnExplore(AreaEntry const* pArea) {}
    void OnTransport(Player* plMover, ObjectGuid transportGuid) {}
    void OnWrongAckData() {};
    void OnFailedToAckChange() {};

    /*
    pPlayer - player who is being moved (not necessarily same as this session's player)
    movementInfo - new movement info that was just received
    opcode - the packet we are checking
    */
    bool HandlePositionTests(Player* pPlayer, MovementInfo& movementInfo, uint16 opcode) { return true; }
    bool HandleFlagTests(Player* pPlayer, MovementInfo& movementInfo, uint16 opcode) { return true; }
};
#endif

class AnticheatManager
{
public:
#ifdef USE_ANTICHEAT
    void LoadAnticheatData();

    Warden * CreateWardenFor(WorldSession* client, BigNumber* K);
    MovementAnticheat* CreateAnticheatFor(Player* player);
#else
    void LoadAnticheatData() {}

    Warden* CreateWardenFor(WorldSession* client, BigNumber* K)
    {
        return new Warden();
    }
    MovementAnticheat* CreateAnticheatFor(Player* player)
    {
        return new MovementAnticheat();
    }
#endif

    // Antispam wrappers
    AntispamInterface* GetAntispam() const { return nullptr; }
    bool CanWhisper(AccountPersistentData const& data, MasterPlayer* player) { return true; }

    static AnticheatManager* instance();
};

AnticheatManager* GetAnticheatLib();

#define sAnticheatMgr (GetAnticheatLib())

#endif // ANTICHEAT_H