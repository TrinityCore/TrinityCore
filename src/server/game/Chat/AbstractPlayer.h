#pragma once

#include <memory>
#include "Common.h"
#include "SharedDefines.h" // For "Team"
#include "ObjectGuid.h"

// 2^n values
enum PlayerExtraFlags
{
    // gm abilities
    PLAYER_EXTRA_GM_ON              = 0x0001,
    PLAYER_EXTRA_GM_ACCEPT_TICKETS  = 0x0002,
    PLAYER_EXTRA_ACCEPT_WHISPERS    = 0x0004,
    PLAYER_EXTRA_TAXICHEAT          = 0x0008,
    PLAYER_EXTRA_GM_INVISIBLE       = 0x0010,
    PLAYER_EXTRA_GM_CHAT            = 0x0020,               // Show GM badge in chat messages
    PLAYER_EXTRA_AUCTION_NEUTRAL    = 0x0040,
    PLAYER_EXTRA_AUCTION_ENEMY      = 0x0080,               // overwrite PLAYER_EXTRA_AUCTION_NEUTRAL

    // other states
    PLAYER_EXTRA_PVP_DEATH          = 0x0100,               // store PvP death status until corpse creating.
    PLAYER_EXTRA_WHISP_RESTRICTION  = 0x0200,
    PLAYER_EXTRA_CITY_PROTECTOR     = 0x0400
};

class MasterPlayer;
class Player;
class PlayerSocial;
class WorldSession;
class Channel;

class AbstractPlayer
{
public:
    virtual ~AbstractPlayer() {}
    virtual ObjectGuid GetObjectGuid() const = 0;
    virtual Team GetTeam() const = 0;
    virtual char const* GetName() const = 0;
    virtual uint32 GetZoneId() const = 0;
    virtual uint32 GetAreaId() const = 0;
    virtual uint8 GetClass() const = 0;
    virtual uint8 GetRace() const = 0;
    virtual uint32 GetLevel() const = 0;
    virtual uint32 GetGuildId() const = 0;
    virtual bool IsAFK() const = 0;
    virtual bool IsDND() const = 0;
    virtual bool IsGameMaster() const = 0;
    virtual uint8 GetChatTag() const = 0;
    virtual WorldSession* GetSession() const = 0;
    virtual PlayerSocial* GetSocial() const = 0;

    virtual void JoinedChannel(Channel *c) = 0;
    virtual void LeftChannel(Channel *c) = 0;

    virtual Player* ToPlayer() const = 0;
    virtual MasterPlayer* ToMasterPlayer() const = 0;
    virtual bool ok() const = 0;
};

template <typename T>
class PlayerWrapper final: public AbstractPlayer
{
public:
    PlayerWrapper(T& pl);
    PlayerWrapper(T* pl);
    PlayerWrapper();
    PlayerWrapper(PlayerWrapper<T> const& other);

    ObjectGuid GetObjectGuid() const override;
    Team GetTeam() const override;
    char const* GetName() const override;
    uint32 GetZoneId() const override;
    uint32 GetAreaId() const override;
    uint8 GetClass() const override;
    uint8 GetRace() const override;
    uint32 GetLevel() const override;
    uint32 GetGuildId() const override;
    bool IsAFK() const override;
    bool IsDND() const override;
    bool IsGameMaster() const override;
    uint8 GetChatTag() const override;
    WorldSession* GetSession() const override;
    PlayerSocial* GetSocial() const override;

    void JoinedChannel(Channel *c) override;
    void LeftChannel(Channel *c) override;

    Player* ToPlayer() const override;
    MasterPlayer* ToMasterPlayer() const override;

    bool ok() const override;
protected:
    T& player;
};

template <>
Player* PlayerWrapper<Player>::ToPlayer() const;
template <>
MasterPlayer* PlayerWrapper<Player>::ToMasterPlayer() const;

template <>
Player* PlayerWrapper<MasterPlayer>::ToPlayer() const;
template <>
MasterPlayer* PlayerWrapper<MasterPlayer>::ToMasterPlayer() const;

typedef std::shared_ptr<AbstractPlayer> PlayerPointer;
