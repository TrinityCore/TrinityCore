/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef RestMgr_h__
#define RestMgr_h__

#include "Define.h"
#include <ctime>

class Player;

enum RestTypes : uint8
{
    REST_TYPE_XP    = 0,
    REST_TYPE_HONOR = 1,
    REST_TYPE_MAX
};

enum PlayerRestInfoOffsets : uint8
{
    REST_STATE_XP       = 0,
    REST_RESTED_XP      = 1,
    REST_STATE_HONOR    = 2,
    REST_RESTED_HONOR   = 3,

    MAX_REST_INFO
};

enum PlayerRestState : uint8
{
    REST_STATE_RESTED           = 0x01,
    REST_STATE_NOT_RAF_LINKED   = 0x02,
    REST_STATE_RAF_LINKED       = 0x06
};

enum RestFlag : uint32
{
    REST_FLAG_IN_TAVERN         = 0x1,
    REST_FLAG_IN_CITY           = 0x2,
    REST_FLAG_IN_FACTION_AREA   = 0x4 // used with AREA_FLAG_REST_ZONE_*
};

class TC_GAME_API RestMgr
{
    friend class Player;
public:
    explicit RestMgr(Player* player);
    ~RestMgr() { }

    float GetRestBonus(RestTypes restType) const { return _restBonus[restType]; }

    void SetRestBonus(RestTypes restType, float restBonus);
    void AddRestBonus(RestTypes restType, float restBonus);

    bool HasRestFlag(RestFlag restFlag) const { return (_restFlagMask & restFlag) != 0; }
    void SetRestFlag(RestFlag restFlag, uint32 triggerId = 0);
    void RemoveRestFlag(RestFlag restFlag);

    uint32 GetRestBonusFor(RestTypes restType, uint32 xp);
    uint32 GetInnTriggerID() const { return _innAreaTriggerId; }

    void Update(time_t now);

protected:
    void LoadRestBonus(RestTypes restType, PlayerRestState state, float restBonus);
    float CalcExtraPerSec(RestTypes restType, float bubble) const;

private:
    Player* _player;
    time_t _restTime;
    uint32 _innAreaTriggerId;
    float _restBonus[REST_TYPE_MAX];
    uint32 _restFlagMask;
};

#endif // RestMgr_h__
