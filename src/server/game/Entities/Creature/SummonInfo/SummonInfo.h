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

#ifndef _SummonInfo_h__
#define _SummonInfo_h__

#include "Define.h"
#include "Duration.h"
#include "ObjectGuid.h"
#include "Optional.h"

class Creature;
class GameObject;
class Unit;

struct SummonInfoArgs;

class TC_GAME_API SummonInfo
{
public:
    SummonInfo(SummonInfo const& right) = delete;
    SummonInfo(SummonInfo&& right) = delete;
    SummonInfo& operator=(SummonInfo const& right) = delete;
    SummonInfo& operator=(SummonInfo&& right) = delete;

    SummonInfo(Creature* summonedCreature, SummonInfoArgs const& args);

    // Returns the creature that is tied to this SummonInfo instance
    Creature* GetSummonedCreature() const;
    // Returns the remaining time until the summon expires. Nullopt when no duration was set which implies that the summon is permanent.
    Optional<Milliseconds> GetRemainingDuration() const;
    // Returns the Unit summoner, or nullptr if no summoner has been provided or if the summoner is not a Unit
    Unit* GetUnitSummoner() const;
    // Returns the GameObject summoner, or nullptr if no summoner has been provided or if the summoner is not a GameObject
    GameObject* GetGameObjectSummoner() const;

    // Returns true when the summon will despawn when the summoner logs out. This also includes despawning and teleporting between map instances.
    bool ShouldDespawnOnSummonerLogout() const;
    // Marks the summon to despawn when the summoner logs out. This also includes despawning and teleporting between map instaces.
    void SetShouldDespawnOnSummonerLogout(bool set);
    // Returns true when the summon will despawn when its summoner has died.
    bool ShouldDespawnOnSummonerDeath() const;
    // Marks the summon to despawn when the summoner has died.
    void SetShouldDespawnOnSummonerDeath(bool set);
    // Returns true when the summon will despawn after its duration has expired. If not set, the summon will just die.
    bool ShouldDespawnWhenExpired() const;
    // Marks the summon to despawn after its duration has expired. If disabled, the summon will just die.
    void SetShouldDespawnWhenExpired(bool set);

private:
    Creature* _summonedCreature;
    Optional<Milliseconds> _remainingDuration; // NYI
    Optional<ObjectGuid> _summonerGUID;
    bool _shouldDespawnOnSummonerLogout; // NYI
    bool _shouldDespawnOnSummonerDeath;  // NYI
    bool _shouldDespawnWhenExpired;      // NYI
};

#endif
