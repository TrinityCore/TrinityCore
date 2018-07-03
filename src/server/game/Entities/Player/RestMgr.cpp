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

#include "RestMgr.h"
#include "Log.h"
#include "Player.h"
#include "Random.h"
#include "World.h"
#include "WorldSession.h"

RestMgr::RestMgr(Player* player) : _player(player), _restTime(0), _innAreaTriggerId(0), _restFlagMask(0)
{
    for (uint8 i = REST_TYPE_XP; i < REST_TYPE_MAX; i++)
        _restBonus[i] = 0;
}

void RestMgr::SetRestBonus(RestTypes restType, float restBonus)
{
    uint8 rest_rested_offset;
    uint8 rest_state_offset;
    uint16 next_level_xp_field;
    bool affectedByRaF = false;

    switch (restType)
    {
        case REST_TYPE_XP:
            // Reset restBonus (XP only) for max level players
            if (_player->getLevel() >= sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
                restBonus = 0;

            rest_rested_offset = REST_RESTED_XP;
            rest_state_offset = REST_STATE_XP;
            next_level_xp_field = PLAYER_NEXT_LEVEL_XP;
            affectedByRaF = true;
            break;
        case REST_TYPE_HONOR:
            // Reset restBonus (Honor only) for players with max honor level.
            if (_player->IsMaxHonorLevelAndPrestige())
                restBonus = 0;

            rest_rested_offset = REST_RESTED_HONOR;
            rest_state_offset = REST_STATE_HONOR;
            next_level_xp_field = PLAYER_FIELD_HONOR_NEXT_LEVEL;
            break;
        default:
            return;
    }

    if (restBonus < 0)
        restBonus = 0;

    float rest_bonus_max = float(_player->GetUInt32Value(next_level_xp_field)) * 1.5f / 2;

    if (restBonus > rest_bonus_max)
        _restBonus[restType] = rest_bonus_max;
    else
        _restBonus[restType] = restBonus;

    // update data for client
    if (affectedByRaF && _player->GetsRecruitAFriendBonus(true) && (_player->GetSession()->IsARecruiter() || _player->GetSession()->GetRecruiterId() != 0))
        _player->SetUInt32Value(PLAYER_FIELD_REST_INFO + rest_state_offset, REST_STATE_RAF_LINKED);
    else
    {
        if (_restBonus[restType] > 10)
            _player->SetUInt32Value(PLAYER_FIELD_REST_INFO + rest_state_offset, REST_STATE_RESTED);
        else if (_restBonus[restType] <= 1)
            _player->SetUInt32Value(PLAYER_FIELD_REST_INFO + rest_state_offset, REST_STATE_NOT_RAF_LINKED);
    }

    // RestTickUpdate
    _player->SetUInt32Value(PLAYER_FIELD_REST_INFO + rest_rested_offset, uint32(_restBonus[restType]));
}

void RestMgr::AddRestBonus(RestTypes restType, float restBonus)
{
    // Don't add extra rest bonus to max level players. Note: Might need different condition in next expansion for honor XP (PLAYER_LEVEL_MIN_HONOR perhaps).
    if (_player->getLevel() >= sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
        restBonus = 0;

    float totalRestBonus = GetRestBonus(restType) + restBonus;
    SetRestBonus(restType, totalRestBonus);
}

void RestMgr::SetRestFlag(RestFlag restFlag, uint32 triggerID)
{
    uint32 oldRestMask = _restFlagMask;
    _restFlagMask |= restFlag;

    if (!oldRestMask && _restFlagMask) // only set flag/time on the first rest state
    {
        _restTime = time(nullptr);
        _player->SetFlag(PLAYER_FLAGS, PLAYER_FLAGS_RESTING);
    }

    if (triggerID)
        _innAreaTriggerId = triggerID;
}

void RestMgr::RemoveRestFlag(RestFlag restFlag)
{
    uint32 oldRestMask = _restFlagMask;
    _restFlagMask &= ~restFlag;

    if (oldRestMask && !_restFlagMask) // only remove flag/time on the last rest state remove
    {
        _restTime = 0;
        _player->RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_RESTING);
    }
}

uint32 RestMgr::GetRestBonusFor(RestTypes restType, uint32 xp)
{
    uint32 rested_bonus = uint32(GetRestBonus(restType)); // xp for each rested bonus

    if (rested_bonus > xp) // max rested_bonus == xp or (r+x) = 200% xp
        rested_bonus = xp;

    SetRestBonus(restType, GetRestBonus(restType) - rested_bonus);

    TC_LOG_DEBUG("entities.player", "RestMgr::GetRestBonus: Player '%s' (%s) gain %u xp (+%u Rested Bonus). Rested points=%f", _player->GetGUID().ToString().c_str(), _player->GetName().c_str(), xp + rested_bonus, rested_bonus, GetRestBonus(restType));
    return rested_bonus;
}

void RestMgr::Update(time_t now)
{
    if (roll_chance_i(3) && _restTime > 0) // freeze update
    {
        time_t timeDiff = now - _restTime;
        if (timeDiff >= 10)
        {
            _restTime = now;

            float bubble = 0.125f * sWorld->getRate(RATE_REST_INGAME);
            AddRestBonus(REST_TYPE_XP, timeDiff * CalcExtraPerSec(REST_TYPE_XP, bubble));
        }
    }
}

void RestMgr::LoadRestBonus(RestTypes restType, PlayerRestState state, float restBonus)
{
    _restBonus[restType] = restBonus;
    _player->SetUInt32Value(PLAYER_FIELD_REST_INFO + restType * 2, state);
    _player->SetUInt32Value(PLAYER_FIELD_REST_INFO + restType * 2 + 1, uint32(restBonus));
}

float RestMgr::CalcExtraPerSec(RestTypes restType, float bubble) const
{
    switch (restType)
    {
        case REST_TYPE_HONOR:
            return float(_player->GetUInt32Value(PLAYER_FIELD_HONOR_NEXT_LEVEL)) / 72000.0f * bubble;
        case REST_TYPE_XP:
            return float(_player->GetUInt32Value(PLAYER_NEXT_LEVEL_XP)) / 72000.0f * bubble;
        default:
            return 0.0f;
    }
}
