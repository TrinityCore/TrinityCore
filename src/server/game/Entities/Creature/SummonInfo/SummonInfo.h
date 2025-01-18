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

    explicit SummonInfo(Creature* summonedCreature, SummonInfoArgs const& args);

    // Initializes additional settings based on the provided SummonProperties ID.
    void InitializeSummonProperties(uint32 summonPropertiesId);
    // Returns the creature that is tied to this SummonInfo instance.
    Creature* GetSummonedCreature() const;
    // Returns the Unit summoner, or nullptr if no summoner has been provided or if the summoner is not a Unit.
    Unit* GetUnitSummoner() const;
    // Returns the GameObject summoner, or nullptr if no summoner has been provided or if the summoner is not a GameObject.
    GameObject* GetGameObjectSummoner() const;

    // Returns the remaining time until the summon expires. Nullopt when no duration was set which implies that the summon is permanent.
    Optional<Milliseconds> GetRemainingDuration() const;
    // Returns the health amount that will override the default max health calculation. Nullopt when no amount is provided.
    Optional<uint64> GetMaxHealth() const;
    // Returns the ID of the spell that has been used to summon the creature. Nullopt when the creature has not been summoned by a spell (scripted summons/ other APIs).
    Optional<uint32> GetSummonSpellId() const;
    // Returns the FactionTemplate ID of the summon that is overriding the default ID of the creature. Nullopt when the faction has not been overriden.
    Optional<uint32> GetFactionId() const;

    // Returns true when the summon will despawn when the summoner logs out. This also includes despawning and teleporting between map instances.
    bool DespawnsOnSummonerLogout() const;
    // Marks the summon to despawn when the summoner logs out. This also includes despawning and teleporting between map instaces.
    void SetDespawnOnSummonerLogout(bool set);
    // Returns true when the summon will despawn when its summoner has died.
    bool DespawnsOnSummonerDeath() const;
    // Marks the summon to despawn when the summoner has died.
    void SetDespawnOnSummonerDeath(bool set);
    // Returns true when the summon will despawn after its duration has expired. If not set, the summon will just die.
    bool DespawnsWhenExpired() const;
    // Marks the summon to despawn after its duration has expired. If disabled, the summon will just die.
    void SetDespawnWhenExpired(bool set);

private:
    Creature* _summonedCreature;
    Optional<ObjectGuid> _summonerGUID;
    Optional<Milliseconds> _remainingDuration;  // NYI
    Optional<uint64> _maxHealth;                // NYI
    Optional<uint32> _summonSpellId;            // NYI
    Optional<uint32> _factionId;                // NYI
    bool _despawnOnSummonerLogout;              // NYI
    bool _despawnOnSummonerDeath;               // NYI
    bool _despawnWhenExpired;                   // NYI
};

#endif
