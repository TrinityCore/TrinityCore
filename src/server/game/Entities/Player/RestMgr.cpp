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
    int32 next_level_xp;
    bool affectedByRaF = false;

    switch (restType)
    {
        case REST_TYPE_XP:
            // Reset restBonus (XP only) for max level players
            if (_player->getLevel() >= sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
                restBonus = 0;

            next_level_xp = _player->m_activePlayerData->NextLevelXP;
            affectedByRaF = true;
            break;
        case REST_TYPE_HONOR:
            // Reset restBonus (Honor only) for players with max honor level.
            if (_player->IsMaxHonorLevel())
                restBonus = 0;

            next_level_xp = _player->m_activePlayerData->HonorNextLevel;
            break;
        default:
            return;
    }

    float rest_bonus_max = float(next_level_xp) * 1.5f / 2;

    if (restBonus < 0)
        restBonus = 0;

    if (restBonus > rest_bonus_max)
        restBonus = rest_bonus_max;

    _restBonus[restType] = restBonus;

    uint32 oldBonus = uint32(_restBonus[restType]);
    if (oldBonus == uint32(restBonus))
        return;

    // update data for client
    if (affectedByRaF && _player->GetsRecruitAFriendBonus(true) && (_player->GetSession()->IsARecruiter() || _player->GetSession()->GetRecruiterId() != 0))
        _player->SetRestState(restType, REST_STATE_RAF_LINKED);
    else
    {
        if (_restBonus[restType] > 10)
            _player->SetRestState(restType, REST_STATE_RESTED);
        else if (_restBonus[restType] <= 1)
            _player->SetRestState(restType, REST_STATE_NOT_RAF_LINKED);
    }

    // RestTickUpdate
    _player->SetRestThreshold(restType, uint32(_restBonus[restType]));
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
        _player->AddPlayerFlag(PLAYER_FLAGS_RESTING);
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
        _player->RemovePlayerFlag(PLAYER_FLAGS_RESTING);
    }
}

uint32 RestMgr::GetRestBonusFor(RestTypes restType, uint32 xp)
{
    uint32 rested_bonus = uint32(GetRestBonus(restType)); // xp for each rested bonus

    if (rested_bonus > xp) // max rested_bonus == xp or (r+x) = 200% xp
        rested_bonus = xp;

    uint32 rested_loss = rested_bonus;
    if (restType == REST_TYPE_XP)
        AddPct(rested_loss, _player->GetTotalAuraModifier(SPELL_AURA_MOD_RESTED_XP_CONSUMPTION));

    SetRestBonus(restType, GetRestBonus(restType) - rested_loss);

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
    _player->SetRestState(restType, state);
    _player->SetRestThreshold(restType, uint32(restBonus));
}

float RestMgr::CalcExtraPerSec(RestTypes restType, float bubble) const
{
    switch (restType)
    {
        case REST_TYPE_HONOR:
            return float(_player->m_activePlayerData->HonorNextLevel) / 72000.0f * bubble;
        case REST_TYPE_XP:
            return float(_player->m_activePlayerData->NextLevelXP) / 72000.0f * bubble;
        default:
            return 0.0f;
    }
}
