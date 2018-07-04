/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef __SPELL_H
#define __SPELL_H

#include "ConditionMgr.h"
#include "DBCEnums.h"
#include "ObjectGuid.h"
#include "Position.h"
#include "SharedDefines.h"
#include <memory>

namespace WorldPackets
{
    namespace Spells
    {
        struct SpellCastRequest;
        struct SpellTargetData;
        struct SpellAmmo;
        struct SpellCastData;
    }
}

class Aura;
class AuraEffect;
class Corpse;
class DynamicObject;
class GameObject;
class Item;
class Object;
class PathGenerator;
class Player;
class SpellEffectInfo;
class SpellImplicitTargetInfo;
class SpellInfo;
class SpellScript;
class Unit;
class WorldObject;
struct SpellPowerCost;
struct SummonPropertiesEntry;
enum AuraType : uint32;
enum CurrentSpellTypes : uint8;
enum LootType : uint8;
enum SpellCastTargetFlags : uint32;
enum SpellTargetCheckTypes : uint8;
enum SpellTargetObjectTypes : uint8;
enum SpellValueMod : uint8;
enum TriggerCastFlags : uint32;
enum WeaponAttackType : uint8;

#define SPELL_CHANNEL_UPDATE_INTERVAL (1 * IN_MILLISECONDS)

enum SpellCastFlags
{
    CAST_FLAG_NONE               = 0x00000000,
    CAST_FLAG_PENDING            = 0x00000001,              // aoe combat log?
    CAST_FLAG_HAS_TRAJECTORY     = 0x00000002,
    CAST_FLAG_UNKNOWN_3          = 0x00000004,
    CAST_FLAG_UNKNOWN_4          = 0x00000008,              // ignore AOE visual
    CAST_FLAG_UNKNOWN_5          = 0x00000010,
    CAST_FLAG_PROJECTILE         = 0x00000020,
    CAST_FLAG_UNKNOWN_7          = 0x00000040,
    CAST_FLAG_UNKNOWN_8          = 0x00000080,
    CAST_FLAG_UNKNOWN_9          = 0x00000100,
    CAST_FLAG_UNKNOWN_10         = 0x00000200,
    CAST_FLAG_UNKNOWN_11         = 0x00000400,
    CAST_FLAG_POWER_LEFT_SELF    = 0x00000800,
    CAST_FLAG_UNKNOWN_13         = 0x00001000,
    CAST_FLAG_UNKNOWN_14         = 0x00002000,
    CAST_FLAG_UNKNOWN_15         = 0x00004000,
    CAST_FLAG_UNKNOWN_16         = 0x00008000,
    CAST_FLAG_UNKNOWN_17         = 0x00010000,
    CAST_FLAG_ADJUST_MISSILE     = 0x00020000,
    CAST_FLAG_NO_GCD             = 0x00040000,              // no GCD for spell casts from charm/summon (vehicle spells is an example)
    CAST_FLAG_VISUAL_CHAIN       = 0x00080000,
    CAST_FLAG_UNKNOWN_21         = 0x00100000,
    CAST_FLAG_RUNE_LIST          = 0x00200000,
    CAST_FLAG_UNKNOWN_23         = 0x00400000,
    CAST_FLAG_UNKNOWN_24         = 0x00800000,
    CAST_FLAG_UNKNOWN_25         = 0x01000000,
    CAST_FLAG_UNKNOWN_26         = 0x02000000,
    CAST_FLAG_IMMUNITY           = 0x04000000,
    CAST_FLAG_UNKNOWN_28         = 0x08000000,
    CAST_FLAG_UNKNOWN_29         = 0x10000000,
    CAST_FLAG_UNKNOWN_30         = 0x20000000,
    CAST_FLAG_HEAL_PREDICTION    = 0x40000000,
    CAST_FLAG_UNKNOWN_32         = 0x80000000
};

enum SpellCastFlagsEx
{
    CAST_FLAG_EX_NONE            = 0x00000,
    CAST_FLAG_EX_UNKNOWN_1       = 0x00001,
    CAST_FLAG_EX_UNKNOWN_2       = 0x00002,
    CAST_FLAG_EX_UNKNOWN_3       = 0x00004,
    CAST_FLAG_EX_UNKNOWN_4       = 0x00008,
    CAST_FLAG_EX_UNKNOWN_5       = 0x00010,
    CAST_FLAG_EX_UNKNOWN_6       = 0x00020,
    CAST_FLAG_EX_UNKNOWN_7       = 0x00040,
    CAST_FLAG_EX_UNKNOWN_8       = 0x00080,
    CAST_FLAG_EX_UNKNOWN_9       = 0x00100,
    CAST_FLAG_EX_UNKNOWN_10      = 0x00200,
    CAST_FLAG_EX_UNKNOWN_11      = 0x00400,
    CAST_FLAG_EX_UNKNOWN_12      = 0x00800,
    CAST_FLAG_EX_UNKNOWN_13      = 0x01000,
    CAST_FLAG_EX_UNKNOWN_14      = 0x02000,
    CAST_FLAG_EX_UNKNOWN_15      = 0x04000,
    CAST_FLAG_EX_USE_TOY_SPELL   = 0x08000, // Starts cooldown on toy
    CAST_FLAG_EX_UNKNOWN_17      = 0x10000,
    CAST_FLAG_EX_UNKNOWN_18      = 0x20000,
    CAST_FLAG_EX_UNKNOWN_19      = 0x40000,
    CAST_FLAG_EX_UNKNOWN_20      = 0x80000
};

enum SpellCastSource : uint8
{
    SPELL_CAST_SOURCE_PLAYER = 2,
    SPELL_CAST_SOURCE_NORMAL = 3,
    SPELL_CAST_SOURCE_ITEM = 4,
    SPELL_CAST_SOURCE_PASSIVE = 7,
    SPELL_CAST_SOURCE_PET = 9,
    SPELL_CAST_SOURCE_AURA = 13,
    SPELL_CAST_SOURCE_SPELL = 16,
};

enum SpellRangeFlag
{
    SPELL_RANGE_DEFAULT             = 0,
    SPELL_RANGE_MELEE               = 1,     //melee
    SPELL_RANGE_RANGED              = 2      //hunter range and ranged weapon
};

struct TC_GAME_API SpellDestination
{
    SpellDestination();
    SpellDestination(float x, float y, float z, float orientation = 0.0f, uint32 mapId = MAPID_INVALID);
    SpellDestination(Position const& pos);
    SpellDestination(WorldObject const& wObj);

    void Relocate(Position const& pos);
    void RelocateOffset(Position const& offset);

    WorldLocation _position;
    ObjectGuid _transportGUID;
    Position _transportOffset;
};


struct SpellLogEffectPowerDrainParams
{
    ObjectGuid Victim;
    uint32 Points       = 0;
    uint32 PowerType    = 0;
    float Amplitude     = 0;
};

struct SpellLogEffectExtraAttacksParams
{
    ObjectGuid Victim;
    uint32 NumAttacks   = 0;
};

struct SpellLogEffectDurabilityDamageParams
{
    ObjectGuid Victim;
    int32 ItemID        = 0;
    int32 Amount        = 0;
};

struct SpellLogEffectGenericVictimParams
{
    ObjectGuid Victim;
};

struct SpellLogEffectTradeSkillItemParams
{
    int32 ItemID        = 0;
};

struct SpellLogEffectFeedPetParams
{
    int32 ItemID        = 0;
};

class TC_GAME_API SpellCastTargets
{
    public:
        SpellCastTargets();
        SpellCastTargets(Unit* caster, WorldPackets::Spells::SpellCastRequest const& spellCastRequest);
        ~SpellCastTargets();

        void Write(WorldPackets::Spells::SpellTargetData& data);

        uint32 GetTargetMask() const { return m_targetMask; }
        void SetTargetMask(uint32 newMask) { m_targetMask = newMask; }

        void SetTargetFlag(SpellCastTargetFlags flag) { m_targetMask |= flag; }

        ObjectGuid GetOrigUnitTargetGUID() const;
        void SetOrigUnitTarget(Unit* target);

        ObjectGuid GetUnitTargetGUID() const;
        Unit* GetUnitTarget() const;
        void SetUnitTarget(Unit* target);

        ObjectGuid GetGOTargetGUID() const;
        GameObject* GetGOTarget() const;
        void SetGOTarget(GameObject* target);

        ObjectGuid GetCorpseTargetGUID() const;
        Corpse* GetCorpseTarget() const;

        WorldObject* GetObjectTarget() const;
        ObjectGuid GetObjectTargetGUID() const;
        void RemoveObjectTarget();

        ObjectGuid GetItemTargetGUID() const { return m_itemTargetGUID; }
        Item* GetItemTarget() const { return m_itemTarget; }
        uint32 GetItemTargetEntry() const { return m_itemTargetEntry; }
        void SetItemTarget(Item* item);
        void SetTradeItemTarget(Player* caster);
        void UpdateTradeSlotItem();

        SpellDestination const* GetSrc() const;
        Position const* GetSrcPos() const;
        void SetSrc(float x, float y, float z);
        void SetSrc(Position const& pos);
        void SetSrc(WorldObject const& wObj);
        void ModSrc(Position const& pos);
        void RemoveSrc();

        SpellDestination const* GetDst() const;
        WorldLocation const* GetDstPos() const;
        void SetDst(float x, float y, float z, float orientation, uint32 mapId = MAPID_INVALID);
        void SetDst(Position const& pos);
        void SetDst(WorldObject const& wObj);
        void SetDst(SpellDestination const& spellDest);
        void SetDst(SpellCastTargets const& spellTargets);
        void ModDst(Position const& pos);
        void ModDst(SpellDestination const& spellDest);
        void RemoveDst();

        bool HasSrc() const;
        bool HasDst() const;
        bool HasTraj() const { return m_speed != 0; }

        float GetPitch() const { return m_pitch; }
        void SetPitch(float pitch) { m_pitch = pitch; }
        float GetSpeed() const { return m_speed; }
        void SetSpeed(float speed) { m_speed = speed; }

        float GetDist2d() const { return m_src._position.GetExactDist2d(&m_dst._position); }
        float GetSpeedXY() const { return m_speed * std::cos(m_pitch); }
        float GetSpeedZ() const { return m_speed * std::sin(m_pitch); }

        void Update(Unit* caster);
        void OutDebug() const;
        std::string GetTargetString() const { return m_strTarget; }

    private:
        uint32 m_targetMask;

        // objects (can be used at spell creating and after Update at casting)
        WorldObject* m_objectTarget;
        Item* m_itemTarget;

        // object GUID/etc, can be used always
        ObjectGuid m_origObjectTargetGUID;
        ObjectGuid m_objectTargetGUID;
        ObjectGuid m_itemTargetGUID;
        uint32 m_itemTargetEntry;

        SpellDestination m_src;
        SpellDestination m_dst;

        float m_pitch, m_speed;
        std::string m_strTarget;
};

struct SpellValue
{
    explicit  SpellValue(Difficulty diff, SpellInfo const* proto);
    int32     EffectBasePoints[MAX_SPELL_EFFECTS];
    uint32    MaxAffectedTargets;
    float     RadiusMod;
    uint8     AuraStackAmount;
};

enum SpellState
{
    SPELL_STATE_NULL      = 0,
    SPELL_STATE_PREPARING = 1,
    SPELL_STATE_CASTING   = 2,
    SPELL_STATE_FINISHED  = 3,
    SPELL_STATE_IDLE      = 4,
    SPELL_STATE_DELAYED   = 5
};

enum SpellEffectHandleMode
{
    SPELL_EFFECT_HANDLE_LAUNCH,
    SPELL_EFFECT_HANDLE_LAUNCH_TARGET,
    SPELL_EFFECT_HANDLE_HIT,
    SPELL_EFFECT_HANDLE_HIT_TARGET
};

typedef std::vector<std::pair<uint32, ObjectGuid>> DispelList;

static const uint32 SPELL_INTERRUPT_NONPLAYER = 32747;

class TC_GAME_API Spell
{
    friend void SetUnitCurrentCastSpell(Unit* unit, Spell* spell);
    friend class SpellScript;
    public:

        void EffectNULL(SpellEffIndex effIndex);
        void EffectUnused(SpellEffIndex effIndex);
        void EffectDistract(SpellEffIndex effIndex);
        void EffectPull(SpellEffIndex effIndex);
        void EffectSchoolDMG(SpellEffIndex effIndex);
        void EffectEnvironmentalDMG(SpellEffIndex effIndex);
        void EffectInstaKill(SpellEffIndex effIndex);
        void EffectDummy(SpellEffIndex effIndex);
        void EffectTeleportUnits(SpellEffIndex effIndex);
        void EffectApplyAura(SpellEffIndex effIndex);
        void EffectSendEvent(SpellEffIndex effIndex);
        void EffectPowerBurn(SpellEffIndex effIndex);
        void EffectPowerDrain(SpellEffIndex effIndex);
        void EffectHeal(SpellEffIndex effIndex);
        void EffectBind(SpellEffIndex effIndex);
        void EffectHealthLeech(SpellEffIndex effIndex);
        void EffectQuestComplete(SpellEffIndex effIndex);
        void EffectCreateItem(SpellEffIndex effIndex);
        void EffectCreateItem2(SpellEffIndex effIndex);
        void EffectCreateRandomItem(SpellEffIndex effIndex);
        void EffectPersistentAA(SpellEffIndex effIndex);
        void EffectEnergize(SpellEffIndex effIndex);
        void EffectOpenLock(SpellEffIndex effIndex);
        void EffectSummonChangeItem(SpellEffIndex effIndex);
        void EffectProficiency(SpellEffIndex effIndex);
        void EffectApplyAreaAura(SpellEffIndex effIndex);
        void EffectSummonType(SpellEffIndex effIndex);
        void EffectLearnSpell(SpellEffIndex effIndex);
        void EffectDispel(SpellEffIndex effIndex);
        void EffectDualWield(SpellEffIndex effIndex);
        void EffectPickPocket(SpellEffIndex effIndex);
        void EffectAddFarsight(SpellEffIndex effIndex);
        void EffectUntrainTalents(SpellEffIndex effIndex);
        void EffectHealMechanical(SpellEffIndex effIndex);
        void EffectJump(SpellEffIndex effIndex);
        void EffectJumpDest(SpellEffIndex effIndex);
        void EffectLeapBack(SpellEffIndex effIndex);
        void EffectQuestClear(SpellEffIndex effIndex);
        void EffectTeleUnitsFaceCaster(SpellEffIndex effIndex);
        void EffectLearnSkill(SpellEffIndex effIndex);
        void EffectPlayMovie(SpellEffIndex effIndex);
        void EffectTradeSkill(SpellEffIndex effIndex);
        void EffectEnchantItemPerm(SpellEffIndex effIndex);
        void EffectEnchantItemTmp(SpellEffIndex effIndex);
        void EffectTameCreature(SpellEffIndex effIndex);
        void EffectSummonPet(SpellEffIndex effIndex);
        void EffectLearnPetSpell(SpellEffIndex effIndex);
        void EffectWeaponDmg(SpellEffIndex effIndex);
        void EffectForceCast(SpellEffIndex effIndex);
        void EffectTriggerSpell(SpellEffIndex effIndex);
        void EffectTriggerMissileSpell(SpellEffIndex effIndex);
        void EffectThreat(SpellEffIndex effIndex);
        void EffectHealMaxHealth(SpellEffIndex effIndex);
        void EffectInterruptCast(SpellEffIndex effIndex);
        void EffectSummonObjectWild(SpellEffIndex effIndex);
        void EffectScriptEffect(SpellEffIndex effIndex);
        void EffectSanctuary(SpellEffIndex effIndex);
        void EffectAddComboPoints(SpellEffIndex effIndex);
        void EffectDuel(SpellEffIndex effIndex);
        void EffectStuck(SpellEffIndex effIndex);
        void EffectSummonPlayer(SpellEffIndex effIndex);
        void EffectActivateObject(SpellEffIndex effIndex);
        void EffectApplyGlyph(SpellEffIndex effIndex);
        void EffectEnchantHeldItem(SpellEffIndex effIndex);
        void EffectSummonObject(SpellEffIndex effIndex);
        void EffectChangeRaidMarker(SpellEffIndex effIndex);
        void EffectResurrect(SpellEffIndex effIndex);
        void EffectParry(SpellEffIndex effIndex);
        void EffectBlock(SpellEffIndex effIndex);
        void EffectLeap(SpellEffIndex effIndex);
        void EffectTransmitted(SpellEffIndex effIndex);
        void EffectDisEnchant(SpellEffIndex effIndex);
        void EffectInebriate(SpellEffIndex effIndex);
        void EffectFeedPet(SpellEffIndex effIndex);
        void EffectDismissPet(SpellEffIndex effIndex);
        void EffectReputation(SpellEffIndex effIndex);
        void EffectForceDeselect(SpellEffIndex effIndex);
        void EffectSelfResurrect(SpellEffIndex effIndex);
        void EffectSkinning(SpellEffIndex effIndex);
        void EffectCharge(SpellEffIndex effIndex);
        void EffectChargeDest(SpellEffIndex effIndex);
        void EffectProspecting(SpellEffIndex effIndex);
        void EffectMilling(SpellEffIndex effIndex);
        void EffectRenamePet(SpellEffIndex effIndex);
        void EffectSendTaxi(SpellEffIndex effIndex);
        void EffectKnockBack(SpellEffIndex effIndex);
        void EffectPullTowards(SpellEffIndex effIndex);
        void EffectDispelMechanic(SpellEffIndex effIndex);
        void EffectResurrectPet(SpellEffIndex effIndex);
        void EffectDestroyAllTotems(SpellEffIndex effIndex);
        void EffectDurabilityDamage(SpellEffIndex effIndex);
        void EffectSkill(SpellEffIndex effIndex);
        void EffectTaunt(SpellEffIndex effIndex);
        void EffectDurabilityDamagePCT(SpellEffIndex effIndex);
        void EffectModifyThreatPercent(SpellEffIndex effIndex);
        void EffectResurrectNew(SpellEffIndex effIndex);
        void EffectAddExtraAttacks(SpellEffIndex effIndex);
        void EffectSpiritHeal(SpellEffIndex effIndex);
        void EffectSkinPlayerCorpse(SpellEffIndex effIndex);
        void EffectStealBeneficialBuff(SpellEffIndex effIndex);
        void EffectUnlearnSpecialization(SpellEffIndex effIndex);
        void EffectHealPct(SpellEffIndex effIndex);
        void EffectEnergizePct(SpellEffIndex effIndex);
        void EffectTriggerRitualOfSummoning(SpellEffIndex effIndex);
        void EffectSummonRaFFriend(SpellEffIndex effIndex);
        void EffectUnlockGuildVaultTab(SpellEffIndex effIndex);
        void EffectKillCreditPersonal(SpellEffIndex effIndex);
        void EffectKillCredit(SpellEffIndex effIndex);
        void EffectQuestFail(SpellEffIndex effIndex);
        void EffectQuestStart(SpellEffIndex effIndex);
        void EffectRedirectThreat(SpellEffIndex effIndex);
        void EffectGameObjectDamage(SpellEffIndex effIndex);
        void EffectGameObjectRepair(SpellEffIndex effIndex);
        void EffectGameObjectSetDestructionState(SpellEffIndex effIndex);
        void EffectActivateRune(SpellEffIndex effIndex);
        void EffectCreateTamedPet(SpellEffIndex effIndex);
        void EffectDiscoverTaxi(SpellEffIndex effIndex);
        void EffectTitanGrip(SpellEffIndex effIndex);
        void EffectEnchantItemPrismatic(SpellEffIndex effIndex);
        void EffectPlayMusic(SpellEffIndex effIndex);
        void EffectActivateSpec(SpellEffIndex effIndex);
        void EffectPlaySound(SpellEffIndex effIndex);
        void EffectRemoveAura(SpellEffIndex effIndex);
        void EffectDamageFromMaxHealthPCT(SpellEffIndex effIndex);
        void EffectCastButtons(SpellEffIndex effIndex);
        void EffectRechargeItem(SpellEffIndex effIndex);
        void EffectGiveCurrency(SpellEffIndex effIndex);
        void EffectResurrectWithAura(SpellEffIndex effIndex);
        void EffectCreateAreaTrigger(SpellEffIndex effIndex);
        void EffectRemoveTalent(SpellEffIndex effIndex);
        void EffectDestroyItem(SpellEffIndex effIndex);
        void EffectLearnGarrisonBuilding(SpellEffIndex effIndex);
        void EffectCreateGarrison(SpellEffIndex effIndex);
        void EffectCreateConversation(SpellEffIndex effIndex);
        void EffectAddGarrisonFollower(SpellEffIndex effIndex);
        void EffectActivateGarrisonBuilding(SpellEffIndex effIndex);
        void EffectHealBattlePetPct(SpellEffIndex effIndex);
        void EffectEnableBattlePets(SpellEffIndex effIndex);
        void EffectLaunchQuestChoice(SpellEffIndex effIndex);
        void EffectUncageBattlePet(SpellEffIndex effIndex);
        void EffectCreateHeirloomItem(SpellEffIndex effIndex);
        void EffectUpgradeHeirloom(SpellEffIndex effIndex);
        void EffectApplyEnchantIllusion(SpellEffIndex effIndex);
        void EffectUpdatePlayerPhase(SpellEffIndex effIndex);
        void EffectUpdateZoneAurasAndPhases(SpellEffIndex effIndex);
        void EffectGiveArtifactPower(SpellEffIndex effIndex);
        void EffectGiveArtifactPowerNoBonus(SpellEffIndex effIndex);
        void EffectPlayScene(SpellEffIndex effIndex);
        void EffectGiveHonor(SpellEffIndex effIndex);
        void EffectLearnTransmogSet(SpellEffIndex effIndex);

        typedef std::unordered_set<Aura*> UsedSpellMods;

        Spell(Unit* caster, SpellInfo const* info, TriggerCastFlags triggerFlags, ObjectGuid originalCasterGUID = ObjectGuid::Empty, bool skipCheck = false);
        ~Spell();

        void InitExplicitTargets(SpellCastTargets const& targets);
        void SelectExplicitTargets();

        void SelectSpellTargets();
        void SelectEffectImplicitTargets(SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType, uint32& processedEffectMask);
        void SelectImplicitChannelTargets(SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType);
        void SelectImplicitNearbyTargets(SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType, uint32 effMask);
        void SelectImplicitConeTargets(SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType, uint32 effMask);
        void SelectImplicitAreaTargets(SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType, uint32 effMask);
        void SelectImplicitCasterDestTargets(SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType);
        void SelectImplicitTargetDestTargets(SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType);
        void SelectImplicitDestDestTargets(SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType);
        void SelectImplicitCasterObjectTargets(SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType);
        void SelectImplicitTargetObjectTargets(SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType);
        void SelectImplicitChainTargets(SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType, WorldObject* target, uint32 effMask);
        void SelectImplicitTrajTargets(SpellEffIndex effIndex);

        void SelectEffectTypeImplicitTargets(uint32 effIndex);

        uint32 GetSearcherTypeMask(SpellTargetObjectTypes objType, ConditionContainer* condList);
        template<class SEARCHER> void SearchTargets(SEARCHER& searcher, uint32 containerMask, Unit* referer, Position const* pos, float radius);

        WorldObject* SearchNearbyTarget(float range, SpellTargetObjectTypes objectType, SpellTargetCheckTypes selectionType, ConditionContainer* condList = NULL);
        void SearchAreaTargets(std::list<WorldObject*>& targets, float range, Position const* position, Unit* referer, SpellTargetObjectTypes objectType, SpellTargetCheckTypes selectionType, ConditionContainer* condList);
        void SearchChainTargets(std::list<WorldObject*>& targets, uint32 chainTargets, WorldObject* target, SpellTargetObjectTypes objectType, SpellTargetCheckTypes selectType, ConditionContainer* condList, bool isChainHeal);

        GameObject* SearchSpellFocus();

        void prepare(SpellCastTargets const* targets, AuraEffect const* triggeredByAura = NULL);
        void cancel();
        void update(uint32 difftime);
        void cast(bool skipCheck = false);
        void finish(bool ok = true);
        void TakePower();

        void TakeRunePower(bool didHit);
        void TakeReagents();
        void TakeCastItem();

        SpellCastResult CheckCast(bool strict, uint32* param1 = nullptr, uint32* param2 = nullptr);
        SpellCastResult CheckPetCast(Unit* target);

        // handlers
        void handle_immediate();
        uint64 handle_delayed(uint64 t_offset);
        // handler helpers
        void _handle_immediate_phase();
        void _handle_finish_phase();

        SpellCastResult CheckItems(uint32* param1, uint32* param2) const;
        SpellCastResult CheckRange(bool strict) const;
        SpellCastResult CheckPower() const;
        SpellCastResult CheckRuneCost() const;
        SpellCastResult CheckCasterAuras(uint32* param1) const;
        SpellCastResult CheckArenaAndRatedBattlegroundCastRules();

        bool CheckSpellCancelsAuraEffect(AuraType auraType, uint32* param1) const;
        bool CheckSpellCancelsCharm(uint32* param1) const;
        bool CheckSpellCancelsStun(uint32* param1) const;
        bool CheckSpellCancelsSilence(uint32* param1) const;
        bool CheckSpellCancelsPacify(uint32* param1) const;
        bool CheckSpellCancelsFear(uint32* param1) const;
        bool CheckSpellCancelsConfuse(uint32* param1) const;

        int32 CalculateDamage(uint8 i, Unit const* target, float* var = nullptr) const;

        bool HaveTargetsForEffect(uint8 effect) const;
        void Delayed();
        void DelayedChannel();
        uint32 getState() const { return m_spellState; }
        void setState(uint32 state) { m_spellState = state; }

        void DoCreateItem(uint32 i, uint32 itemtype, uint8 context = 0, std::vector<int32> const& bonusListIDs = std::vector<int32>());

        bool CheckEffectTarget(Unit const* target, SpellEffectInfo const* effect, Position const* losPosition) const;
        bool CheckEffectTarget(GameObject const* target, SpellEffectInfo const* effect) const;
        bool CheckEffectTarget(Item const* target, SpellEffectInfo const* effect) const;
        bool CanAutoCast(Unit* target);
        void CheckSrc();
        void CheckDst();

        static void SendCastResult(Player* caster, SpellInfo const* spellInfo, uint32 spellVisual, ObjectGuid cast_count, SpellCastResult result, SpellCustomErrors customError = SPELL_CUSTOM_ERROR_NONE, uint32* param1 = nullptr, uint32* param2 = nullptr);
        void SendCastResult(SpellCastResult result, uint32* param1 = nullptr, uint32* param2 = nullptr) const;
        void SendPetCastResult(SpellCastResult result, uint32* param1 = nullptr, uint32* param2 = nullptr) const;
        void SendSpellStart();
        void SendSpellGo();
        void SendSpellCooldown();
        void SendSpellExecuteLog();
        void ExecuteLogEffectTakeTargetPower(uint8 effIndex, Unit* target, uint32 powerType, uint32 points, float amplitude);
        void ExecuteLogEffectExtraAttacks(uint8 effIndex, Unit* victim, uint32 numAttacks);
        void ExecuteLogEffectInterruptCast(uint8 effIndex, Unit* victim, uint32 spellId);
        void ExecuteLogEffectDurabilityDamage(uint8 effIndex, Unit* victim, int32 itemId, int32 amount);
        void ExecuteLogEffectOpenLock(uint8 effIndex, Object* obj);
        void ExecuteLogEffectCreateItem(uint8 effIndex, uint32 entry);
        void ExecuteLogEffectDestroyItem(uint8 effIndex, uint32 entry);
        void ExecuteLogEffectSummonObject(uint8 effIndex, WorldObject* obj);
        void ExecuteLogEffectUnsummonObject(uint8 effIndex, WorldObject* obj);
        void ExecuteLogEffectResurrect(uint8 effIndex, Unit* target);
        void SendInterrupted(uint8 result);
        void SendChannelUpdate(uint32 time);
        void SendChannelStart(uint32 duration);
        void SendResurrectRequest(Player* target);

        void HandleEffects(Unit* pUnitTarget, Item* pItemTarget, GameObject* pGOTarget, uint32 i, SpellEffectHandleMode mode);
        void HandleThreatSpells();

        SpellInfo const* const m_spellInfo;
        Item* m_CastItem;
        ObjectGuid m_castItemGUID;
        uint32 m_castItemEntry;
        int32 m_castItemLevel;
        ObjectGuid m_castId;
        ObjectGuid m_originalCastId;
        bool m_fromClient;
        uint32 m_castFlagsEx;
        union
        {
            // Alternate names for this value
            uint32 TalentId;

            // SPELL_EFFECT_APPLY_GLYPH
            uint32 SpellId;

            // SPELL_EFFECT_TALENT_SPEC_SELECT
            uint32 SpecializationId;

            // SPELL_EFFECT_SET_FOLLOWER_QUALITY
            // SPELL_EFFECT_INCREASE_FOLLOWER_ITEM_LEVEL
            // SPELL_EFFECT_INCREASE_FOLLOWER_EXPERIENCE
            // SPELL_EFFECT_RANDOMIZE_FOLLOWER_ABILITIES
            // SPELL_EFFECT_LEARN_FOLLOWER_ABILITY
            struct
            {
                uint32 Id;
                uint32 AbilityId;   // only SPELL_EFFECT_LEARN_FOLLOWER_ABILITY
            } GarrFollower;

            // SPELL_EFFECT_FINISH_GARRISON_MISSION
            uint32 GarrMissionId;

            // SPELL_EFFECT_UPGRADE_HEIRLOOM
            uint32 ItemId;

            struct
            {
                uint32 Data[2];
            } Raw;
        } m_misc;
        uint32 m_SpellVisual;
        SpellCastTargets m_targets;
        int8 m_comboPointGain;
        SpellCustomErrors m_customError;

        UsedSpellMods m_appliedMods;

        int32 GetCastTime() const { return m_casttime; }
        bool IsAutoRepeat() const { return m_autoRepeat; }
        void SetAutoRepeat(bool rep) { m_autoRepeat = rep; }
        void ReSetTimer() { m_timer = m_casttime > 0 ? m_casttime : 0; }
        bool IsTriggered() const;
        bool IsIgnoringCooldowns() const;
        bool IsProcDisabled() const;
        bool IsChannelActive() const;
        bool IsAutoActionResetSpell() const;

        bool IsTriggeredByAura(SpellInfo const* auraSpellInfo) const { return (auraSpellInfo == m_triggeredByAuraSpell); }

        bool IsDeletable() const { return !m_referencedFromCurrentSpell && !m_executedCurrently; }
        void SetReferencedFromCurrent(bool yes) { m_referencedFromCurrentSpell = yes; }
        bool IsInterruptable() const { return !m_executedCurrently; }
        void SetExecutedCurrently(bool yes) {m_executedCurrently = yes;}
        uint64 GetDelayStart() const { return m_delayStart; }
        void SetDelayStart(uint64 m_time) { m_delayStart = m_time; }
        uint64 GetDelayMoment() const { return m_delayMoment; }

        bool IsNeedSendToClient() const;

        CurrentSpellTypes GetCurrentContainer() const;

        Unit* GetCaster() const { return m_caster; }
        Unit* GetOriginalCaster() const { return m_originalCaster; }
        SpellInfo const* GetSpellInfo() const { return m_spellInfo; }
        std::vector<SpellPowerCost> const& GetPowerCost() const { return m_powerCost; }

        bool UpdatePointers();                              // must be used at call Spell code after time delay (non triggered spell cast/update spell call/etc)

        void CleanupTargetList();

        void SetSpellValue(SpellValueMod mod, int32 value);

        std::vector<SpellEffectInfo const*> const& GetEffects() const { return _effects; }
        SpellEffectInfo const* GetEffect(uint32 index) const
        {
            if (index >= _effects.size())
                return nullptr;

            return _effects[index];
        }

        bool HasEffect(SpellEffectName effect) const;

        Spell** m_selfContainer;                            // pointer to our spell container (if applicable)

        SpellInfo const* GetTriggeredByAuraSpell() const { return m_triggeredByAuraSpell; }

        int32 GetTimer() const { return m_timer; }

    protected:
        bool HasGlobalCooldown() const;
        void TriggerGlobalCooldown();
        void CancelGlobalCooldown();

        void SendLoot(ObjectGuid guid, LootType loottype);
        std::pair<float, float> GetMinMaxRange(bool strict) const;

        Unit* const m_caster;

        SpellValue* const m_spellValue;

        ObjectGuid m_originalCasterGUID;                    // real source of cast (aura caster/etc), used for spell targets selection
                                                            // e.g. damage around area spell trigered by victim aura and damage enemies of aura caster
        Unit* m_originalCaster;                             // cached pointer for m_originalCaster, updated at Spell::UpdatePointers()

        //Spell data
        SpellSchoolMask m_spellSchoolMask;                  // Spell school (can be overwrite for some spells (wand shoot for example)
        WeaponAttackType m_attackType;                      // For weapon based attack

        std::vector<SpellPowerCost> m_powerCost;       // Calculated spell cost initialized only in Spell::prepare
        int32 m_casttime;                                   // Calculated spell cast time initialized only in Spell::prepare
        int32 m_channeledDuration;                          // Calculated channeled spell duration in order to calculate correct pushback.
        bool m_canReflect;                                  // can reflect this spell?
        bool m_autoRepeat;
        uint8 m_runesState;

        uint8 m_delayAtDamageCount;
        bool isDelayableNoMore()
        {
            if (m_delayAtDamageCount >= 2)
                return true;

            m_delayAtDamageCount++;
            return false;
        }

        // Delayed spells system
        uint64 m_delayStart;                                // time of spell delay start, filled by event handler, zero = just started
        uint64 m_delayMoment;                               // moment of next delay call, used internally
        bool m_immediateHandled;                            // were immediate actions handled? (used by delayed spells only)

        // These vars are used in both delayed spell system and modified immediate spell system
        bool m_referencedFromCurrentSpell;                  // mark as references to prevent deleted and access by dead pointers
        bool m_executedCurrently;                           // mark as executed to prevent deleted and access by dead pointers
        bool m_needComboPoints;
        uint32 m_applyMultiplierMask;
        float m_damageMultipliers[MAX_SPELL_EFFECTS];

        // Current targets, to be used in SpellEffects (MUST BE USED ONLY IN SPELL EFFECTS)
        Unit* unitTarget;
        Item* itemTarget;
        GameObject* gameObjTarget;
        WorldLocation* destTarget;
        int32 damage;
        SpellMissInfo targetMissInfo;
        float variance;
        SpellEffectHandleMode effectHandleMode;
        SpellEffectInfo const* effectInfo;
        // used in effects handlers
        Aura* m_spellAura;

        // -------------------------------------------
        GameObject* focusObject;

        // Damage and healing in effects need just calculate
        int32 m_damage;           // Damage  in effects count here
        int32 m_healing;          // Healing in effects count here

        // ******************************************
        // Spell trigger system
        // ******************************************
        uint32 m_procAttacker;                // Attacker trigger flags
        uint32 m_procVictim;                  // Victim   trigger flags
        uint32 m_hitMask;
        void   prepareDataForTriggerSystem();

        // *****************************************
        // Spell target subsystem
        // *****************************************
        // Targets store structures and data
        struct TargetInfo
        {
            ObjectGuid targetGUID;
            uint64 timeDelay;
            int32  damage;

            SpellMissInfo missCondition;
            SpellMissInfo reflectResult;

            uint32 effectMask;
            bool   processed;
            bool   alive;
            bool   crit;
            bool   scaleAura;
        };
        std::vector<TargetInfo> m_UniqueTargetInfo;
        uint32 m_channelTargetEffectMask;                        // Mask req. alive targets

        struct GOTargetInfo
        {
            ObjectGuid targetGUID;
            uint64 timeDelay;
            uint32 effectMask;
            bool   processed;
        };
        std::vector<GOTargetInfo> m_UniqueGOTargetInfo;

        struct ItemTargetInfo
        {
            Item  *item;
            uint32 effectMask;
        };
        std::vector<ItemTargetInfo> m_UniqueItemInfo;

        SpellDestination m_destTargets[MAX_SPELL_EFFECTS];

        void AddUnitTarget(Unit* target, uint32 effectMask, bool checkIfValid = true, bool implicit = true, Position const* losPosition = nullptr);
        void AddGOTarget(GameObject* target, uint32 effectMask);
        void AddItemTarget(Item* item, uint32 effectMask);
        void AddDestTarget(SpellDestination const& dest, uint32 effIndex);

        void DoAllEffectOnTarget(TargetInfo* target);
        SpellMissInfo DoSpellHitOnUnit(Unit* unit, uint32 effectMask, bool scaleAura);
        void DoTriggersOnSpellHit(Unit* unit, uint32 effMask);
        void DoAllEffectOnTarget(GOTargetInfo* target);
        void DoAllEffectOnTarget(ItemTargetInfo* target);
        bool UpdateChanneledTargetList();
        bool IsValidDeadOrAliveTarget(Unit const* target) const;
        void HandleLaunchPhase();
        void DoAllEffectOnLaunchTarget(TargetInfo& targetInfo, float* multiplier);

        void PrepareTargetProcessing();
        void FinishTargetProcessing();

        // Scripting system
        void LoadScripts();
        void CallScriptBeforeCastHandlers();
        void CallScriptOnCastHandlers();
        void CallScriptAfterCastHandlers();
        SpellCastResult CallScriptCheckCastHandlers();
        void PrepareScriptHitHandlers();
        bool CallScriptEffectHandlers(SpellEffIndex effIndex, SpellEffectHandleMode mode);
        void CallScriptSuccessfulDispel(SpellEffIndex effIndex);
        void CallScriptBeforeHitHandlers(SpellMissInfo missInfo);
        void CallScriptOnHitHandlers();
        void CallScriptAfterHitHandlers();
        void CallScriptObjectAreaTargetSelectHandlers(std::list<WorldObject*>& targets, SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType);
        void CallScriptObjectTargetSelectHandlers(WorldObject*& target, SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType);
        void CallScriptDestinationTargetSelectHandlers(SpellDestination& target, SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType);
        bool CheckScriptEffectImplicitTargets(uint32 effIndex, uint32 effIndexToCheck);
        std::vector<SpellScript*> m_loadedScripts;

        struct HitTriggerSpell
        {
            HitTriggerSpell(SpellInfo const* spellInfo, SpellInfo const* auraSpellInfo, int32 procChance) :
                triggeredSpell(spellInfo), triggeredByAura(auraSpellInfo), chance(procChance) { }

            SpellInfo const* triggeredSpell;
            SpellInfo const* triggeredByAura;
            // uint8 triggeredByEffIdx          This might be needed at a later stage - No need known for now
            int32 chance;
        };

        bool CanExecuteTriggersOnHit(uint32 effMask, SpellInfo const* triggeredByAura = nullptr) const;
        void PrepareTriggersExecutedOnHit();
        typedef std::vector<HitTriggerSpell> HitTriggerSpellList;
        HitTriggerSpellList m_hitTriggerSpells;

        // effect helpers
        void SummonGuardian(uint32 i, uint32 entry, SummonPropertiesEntry const* properties, uint32 numSummons);
        void CalculateJumpSpeeds(SpellEffectInfo const* effInfo, float dist, float& speedxy, float& speedz);

        void UpdateSpellCastDataTargets(WorldPackets::Spells::SpellCastData& data);
        void UpdateSpellCastDataAmmo(WorldPackets::Spells::SpellAmmo& data);

        SpellCastResult CanOpenLock(uint32 effIndex, uint32 lockid, SkillType& skillid, int32& reqSkillValue, int32& skillValue);
        // -------------------------------------------

        uint32 m_spellState;
        int32 m_timer;

        TriggerCastFlags _triggeredCastFlags;

        // if need this can be replaced by Aura copy
        // we can't store original aura link to prevent access to deleted auras
        // and in same time need aura data and after aura deleting.
        SpellInfo const* m_triggeredByAuraSpell;

        bool m_skipCheck;
        uint32 m_auraScaleMask;
        std::unique_ptr<PathGenerator> m_preGeneratedPath;

        std::vector<SpellLogEffectPowerDrainParams> _powerDrainTargets[MAX_SPELL_EFFECTS];
        std::vector<SpellLogEffectExtraAttacksParams> _extraAttacksTargets[MAX_SPELL_EFFECTS];
        std::vector<SpellLogEffectDurabilityDamageParams> _durabilityDamageTargets[MAX_SPELL_EFFECTS];
        std::vector<SpellLogEffectGenericVictimParams> _genericVictimTargets[MAX_SPELL_EFFECTS];
        std::vector<SpellLogEffectTradeSkillItemParams> _tradeSkillTargets[MAX_SPELL_EFFECTS];
        std::vector<SpellLogEffectFeedPetParams> _feedPetTargets[MAX_SPELL_EFFECTS];

        Spell(Spell const& right) = delete;
        Spell& operator=(Spell const& right) = delete;

        std::vector<SpellEffectInfo const*> _effects;
};

namespace Trinity
{
    struct TC_GAME_API WorldObjectSpellTargetCheck
    {
        Unit* _caster;
        Unit* _referer;
        SpellInfo const* _spellInfo;
        SpellTargetCheckTypes _targetSelectionType;
        ConditionSourceInfo* _condSrcInfo;
        ConditionContainer* _condList;

        WorldObjectSpellTargetCheck(Unit* caster, Unit* referer, SpellInfo const* spellInfo,
            SpellTargetCheckTypes selectionType, ConditionContainer* condList);
        ~WorldObjectSpellTargetCheck();
        bool operator()(WorldObject* target);
    };

    struct TC_GAME_API WorldObjectSpellNearbyTargetCheck : public WorldObjectSpellTargetCheck
    {
        float _range;
        Position const* _position;
        WorldObjectSpellNearbyTargetCheck(float range, Unit* caster, SpellInfo const* spellInfo,
            SpellTargetCheckTypes selectionType, ConditionContainer* condList);
        bool operator()(WorldObject* target);
    };

    struct TC_GAME_API WorldObjectSpellAreaTargetCheck : public WorldObjectSpellTargetCheck
    {
        float _range;
        Position const* _position;
        WorldObjectSpellAreaTargetCheck(float range, Position const* position, Unit* caster,
            Unit* referer, SpellInfo const* spellInfo, SpellTargetCheckTypes selectionType, ConditionContainer* condList);
        bool operator()(WorldObject* target);
    };

    struct TC_GAME_API WorldObjectSpellConeTargetCheck : public WorldObjectSpellAreaTargetCheck
    {
        float _coneAngle;
        WorldObjectSpellConeTargetCheck(float coneAngle, float range, Unit* caster,
            SpellInfo const* spellInfo, SpellTargetCheckTypes selectionType, ConditionContainer* condList);
        bool operator()(WorldObject* target);
    };

    struct TC_GAME_API WorldObjectSpellTrajTargetCheck : public WorldObjectSpellAreaTargetCheck
    {
        WorldObjectSpellTrajTargetCheck(float range, Position const* position, Unit* caster, SpellInfo const* spellInfo);
        bool operator()(WorldObject* target);
    };
}

typedef void(Spell::*pEffect)(SpellEffIndex effIndex);
#endif
