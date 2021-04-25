/*
 * This file is part of tswow (https://github.com/tswow/).
 * Copyright (C) 2020 tswow <https://github.com/tswow/>
 * 
 * This program is free software: you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation, version 3.
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
#pragma once

#include "TSMain.h"
#include "TSString.h"
#include "TSArray.h"
#include "TSWorldObject.h"
#include "TSClasses.h"

class TC_GAME_API TSUnit : public TSWorldObject {
public:
    Unit* unit;
    TSUnit(Unit* unit);
    TSUnit();
    TSUnit* operator->() { return this;}
    bool IsNull() { return unit == nullptr; }
    bool Attack(TSUnit who, bool meleeAttack);
    bool AttackStop();
    bool IsStandState();
    bool IsMounted();
    bool IsRooted();
    bool IsFullHealth();
    bool IsInAccessiblePlaceFor(TSCreature creature);
    bool IsAuctioneer();
    bool IsGuildMaster();
    bool IsInnkeeper();
    bool IsTrainer();
    bool IsGossip();
    bool IsTaxi();
    bool IsSpiritHealer();
    bool IsSpiritGuide();
    bool IsTabardDesigner();
    bool IsServiceProvider();
    bool IsSpiritService();
    bool IsAlive();
    bool IsDead();
    bool IsDying();
    bool IsBanker();
    bool IsVendor();
    bool IsBattleMaster();
    bool IsCharmed();
    bool IsArmorer();
    bool IsAttackingPlayer();
    bool IsPvPFlagged();
    bool IsOnVehicle();
    bool IsInCombat();
    bool IsUnderWater();
    bool IsInWater();
    bool IsStopped();
    bool IsQuestGiver();
    bool HealthBelowPct(int32 pct);
    bool HealthAbovePct(int32 pct);
    bool HasAura(uint32 spell);
    bool IsCasting();
    bool HasUnitState(uint32 state);
    TSUnit  GetOwner();
    uint64 GetOwnerGUID();
    uint32 GetMountId();
    uint64 GetCreatorGUID();
    uint64 GetCharmerGUID();
    uint64 GetCharmGUID();
    uint64 GetPetGUID(uint32 slot = 0);
    uint64 GetControllerGUID();
    uint64 GetControllerGUIDS();
    float GetStat(uint32 stat);
    uint32 GetBaseSpellPower(uint32 spellschool);
    TSUnit  GetVictim();
    TSSpell  GetCurrentSpell(uint32 type);
    uint8 GetStandState();
    uint32 GetDisplayId();
    uint32 GetNativeDisplayId();
    uint8 GetLevel();
    uint32 GetHealth();
    uint32 PowerSelectorHelper(TSUnit unit, int powerType = -1);
    uint32 GetPower(int type);
    uint32 GetMaxPower(int type);
    float GetPowerPct(int type);
    uint32 GetPowerType();
    uint32 GetMaxHealth();
    float GetHealthPct();
    uint8 GetGender();
    uint32 GetRace();
    uint32 GetClass();
    uint32 GetRaceMask();
    uint32 GetClassMask();
    uint32 GetCreatureType();
    TSString GetClassAsString(uint8 locale);
    TSString GetRaceAsString(uint8 locale);
    uint32 GetFaction();
    TSAura  GetAura(uint32 spellID);
    TSArray<TSUnit> GetFriendlyUnitsInRange(float range);
    TSArray<TSUnit> GetUnfriendlyUnitsInRange(float range);
    TSVehicle  GetVehicleKit();
    TSVehicle GetVehicle();
    uint64 GetCritterGUID();
    float GetSpeed(uint32 type);
    uint32 GetMovementType();
    void SetOwnerGUID(uint64 guid);
    void SetPvP(bool apply);
    void SetSheath(uint32 sheathed);
    void SetName(TSString name);
    void SetSpeed(uint32 type, float rate, bool forced);
    void SetFaction(uint32 factionId);
    void SetLevel(uint8 newlevel);
    void SetHealth(uint32 amt);
    void SetMaxHealth(uint32 amt);
    void SetPower(uint32 amt, int type);
    void ModifyPower(int32 amt, int type);
    void SetMaxPower(int type, uint32 amt);
    void SetPowerType(uint32 type);
    void SetDisplayId(uint32 model);
    void SetNativeDisplayId(uint32 model);
    void SetFacing(float o);
    void SetFacingToObject(TSWorldObject obj);
    void SetCreatorGUID(uint64 guid);
    void SetPetGUID(uint64 guid);
    void SetWaterWalk(bool enable);
    void SetStandState(uint8 state);
    void SetFFA(bool apply);
    void SetSanctuary(bool apply);
    void SetCritterGUID(uint64 guid);
    void SetRooted(bool apply);
    void SetConfused(bool apply);
    void SetFeared(bool apply);
    void ClearThreatList(bool apply, bool x);
    void Mount(uint32 displayId);
    void Dismount();
    void PerformEmote(uint32 emoteId);
    void EmoteState(uint32 emoteId);
    int32 CountPctFromCurHealth(int32 health);
    int32 CountPctFromMaxHealth(int32 health);
    void SendChatMessageToPlayer(uint8 type, uint32 lang, TSString msg, TSPlayer target);
    void MoveStop();
    void MoveExpire(bool reset);
    void MoveClear(bool reset);
    void MoveIdle();
    void MoveRandom(float radius);
    void MoveHome();
    void MoveFollow(TSUnit target, float dist, float angle);
    void MoveChase(TSUnit target, float dist, float angle);
    void MoveConfused();
    void MoveFleeing(TSUnit target, uint32 time);
    void MoveTo(uint32 id, float x, float y, float z, bool genPath);
    void MoveJump(float x, float y, float z, float zSpeed, float maxHeight, uint32 id);
    void SendUnitWhisper(TSString msg, uint32 lang, TSPlayer receiver, bool bossWhisper);
    void SendUnitEmote(TSString msg, TSUnit receiver, bool bossEmote);
    void SendUnitSay(TSString msg, uint32 language);
    void SendUnitYell(TSString msg, uint32 language);
    void DeMorph();
    void CastSpell(TSUnit target, uint32 spell, bool triggered);
    void CastCustomSpell(TSUnit target, uint32 spell, bool triggered, int32 bp0, int32 bp1, int32 bp2, TSItem castItem, uint64 originalCaster);
    void CastSpellAoF(float _x, float _y, float _z, uint32 spell, bool triggered);
    void ClearInCombat();
    void StopSpellCast(uint32 spellId);
    void InterruptSpell(int spellType, bool delayed);
    TSAura AddAura(uint32 spell, TSUnit target);
    void RemoveAura(uint32 spellId);
    void RemoveAllAuras();
    void AddUnitState(uint32 state);
    void ClearUnitState(uint32 state);
    void NearTeleport(float x, float y, float z, float o);
    void DealDamage(TSUnit target, uint32 damage, bool durabilityloss, uint32 school, uint32 spell);
    void DealHeal(TSUnit target, uint32 spell, uint32 amount, bool critical);
    void Kill(TSUnit target, bool durLoss);
    void AddThreat(TSUnit victim, float threat, uint32 spell = 0, uint32 schoolMask = 0, bool ignoreModifiers = true, bool ignoreRedirects = true, bool raw = false);
    void ScaleThreat(TSUnit victim, float scale, bool raw = false);

    uint32 GetResistance(uint32 school);
    uint32 GetArmor();
    void SetResistance(uint32 school, int32 val);
    void SetArmor(int32 val);
};
