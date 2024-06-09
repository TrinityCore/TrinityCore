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

#ifndef __SPELL_H
#define __SPELL_H

#include "ConditionMgr.h"
#include "DBCEnums.h"
#include "Duration.h"
#include "ModelIgnoreFlags.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include "Position.h"
#include "SharedDefines.h"
#include "SpellDefines.h"
#include "UniqueTrackablePtr.h"
#include <memory>

namespace WorldPackets::Spells
{
struct SpellCastData;
struct SpellHealPrediction;
}

class Aura;
class AuraEffect;
class BasicEvent;
class Corpse;
class DamageInfo;
class DynamicObject;
class DynObjAura;
class GameObject;
class Item;
class Object;
class PathGenerator;
class Player;
class SpellEffectInfo;
class SpellEvent;
class SpellImplicitTargetInfo;
class SpellInfo;
class SpellScript;
class Unit;
class UnitAura;
class WorldObject;
struct SpellPowerCost;
struct SummonPropertiesEntry;
enum AuraType : uint32;
enum CurrentSpellTypes : uint8;
enum LootType : uint8;
enum ProcFlagsHit : uint32;
enum ProcFlagsSpellType : uint32;
enum SpellTargetCheckTypes : uint8;
enum SpellTargetObjectTypes : uint8;
enum SpellValueMod : uint8;
enum TriggerCastFlags : uint32;
enum WeaponAttackType : uint8;

namespace Trinity
{
enum class WorldObjectSpellAreaTargetSearchReason;

template <class Check>
struct WorldObjectListSearcher;
}

#define SPELL_CHANNEL_UPDATE_INTERVAL (1 * IN_MILLISECONDS)
#define MAX_SPELL_RANGE_TOLERANCE 3.0f
#define TRAJECTORY_MISSILE_SIZE 3.0f
#define AOE_DAMAGE_TARGET_CAP SI64LIT(20)
#define SPELL_EMPOWER_HOLD_TIME_AT_MAX (1 * IN_MILLISECONDS)
#define SPELL_EMPOWER_HARDCODED_GCD 359115u

enum SpellCastFlags : uint32
{
    CAST_FLAG_NONE                  = 0x00000000,
    CAST_FLAG_PENDING               = 0x00000001,           // aoe combat log?
    CAST_FLAG_HAS_TRAJECTORY        = 0x00000002,
    CAST_FLAG_UNKNOWN_3             = 0x00000004,
    CAST_FLAG_UNKNOWN_4             = 0x00000008,           // ignore AOE visual
    CAST_FLAG_UNKNOWN_5             = 0x00000010,
    CAST_FLAG_PROJECTILE            = 0x00000020,
    CAST_FLAG_UNKNOWN_7             = 0x00000040,
    CAST_FLAG_UNKNOWN_8             = 0x00000080,
    CAST_FLAG_UNKNOWN_9             = 0x00000100,
    CAST_FLAG_UNKNOWN_10            = 0x00000200,
    CAST_FLAG_UNKNOWN_11            = 0x00000400,
    CAST_FLAG_POWER_LEFT_SELF       = 0x00000800,
    CAST_FLAG_UNKNOWN_13            = 0x00001000,
    CAST_FLAG_UNKNOWN_14            = 0x00002000,
    CAST_FLAG_UNKNOWN_15            = 0x00004000,
    CAST_FLAG_UNKNOWN_16            = 0x00008000,
    CAST_FLAG_UNKNOWN_17            = 0x00010000,
    CAST_FLAG_ADJUST_MISSILE        = 0x00020000,
    CAST_FLAG_NO_GCD                = 0x00040000,           // no GCD for spell casts from charm/summon (vehicle spells is an example)
    CAST_FLAG_VISUAL_CHAIN          = 0x00080000,
    CAST_FLAG_UNKNOWN_21            = 0x00100000,
    CAST_FLAG_RUNE_LIST             = 0x00200000,
    CAST_FLAG_UNKNOWN_23            = 0x00400000,
    CAST_FLAG_UNKNOWN_24            = 0x00800000,
    CAST_FLAG_UNKNOWN_25            = 0x01000000,
    CAST_FLAG_UNKNOWN_26            = 0x02000000,
    CAST_FLAG_IMMUNITY              = 0x04000000,
    CAST_FLAG_UNKNOWN_28            = 0x08000000,
    CAST_FLAG_UNKNOWN_29            = 0x10000000,
    CAST_FLAG_UNKNOWN_30            = 0x20000000,
    CAST_FLAG_HEAL_PREDICTION       = 0x40000000,
    CAST_FLAG_TRIGGER_PET_COOLDOWN  = 0x80000000            // causes the cooldown to be stored in pets SpellHistory on client
};

enum SpellCastFlagsEx : uint32
{
    CAST_FLAG_EX_NONE                               = 0x00000,
    CAST_FLAG_EX_TRIGGER_COOLDOWN_ON_SPELL_START    = 0x00001,
    CAST_FLAG_EX_UNKNOWN_2                          = 0x00002,
    CAST_FLAG_EX_DONT_CONSUME_CHARGES               = 0x00004,
    CAST_FLAG_EX_UNKNOWN_4                          = 0x00008,
    CAST_FLAG_EX_DELAY_STARTING_COOLDOWNS           = 0x00010,  // makes client start cooldown after precalculated delay instead of immediately after SPELL_GO (used by empower spells)
    CAST_FLAG_EX_UNKNOWN_6                          = 0x00020,
    CAST_FLAG_EX_UNKNOWN_7                          = 0x00040,
    CAST_FLAG_EX_UNKNOWN_8                          = 0x00080,
    CAST_FLAG_EX_IGNORE_PET_COOLDOWN                = 0x00100,  // makes client not automatically start cooldown for pets after SPELL_GO
    CAST_FLAG_EX_IGNORE_COOLDOWN                    = 0x00200,  // makes client not automatically start cooldown after SPELL_GO
    CAST_FLAG_EX_UNKNOWN_11                         = 0x00400,
    CAST_FLAG_EX_UNKNOWN_12                         = 0x00800,
    CAST_FLAG_EX_UNKNOWN_13                         = 0x01000,
    CAST_FLAG_EX_UNKNOWN_14                         = 0x02000,
    CAST_FLAG_EX_UNKNOWN_15                         = 0x04000,
    CAST_FLAG_EX_USE_TOY_SPELL                      = 0x08000,  // Starts cooldown on toy
    CAST_FLAG_EX_UNKNOWN_17                         = 0x10000,
    CAST_FLAG_EX_UNKNOWN_18                         = 0x20000,
    CAST_FLAG_EX_UNKNOWN_19                         = 0x40000,
    CAST_FLAG_EX_UNKNOWN_20                         = 0x80000
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

enum SpellHealPredictionType : uint8
{
    SPELL_HEAL_PREDICTION_TARGET            = 0,
    SPELL_HEAL_PREDICTION_TARGET_AND_CASTER = 1,
    SPELL_HEAL_PREDICTION_TARGET_AND_BEACON = 2,
    SPELL_HEAL_PREDICTION_TARGET_PARTY      = 3,
};

enum SpellRangeFlag
{
    SPELL_RANGE_DEFAULT             = 0,
    SPELL_RANGE_MELEE               = 1,     //melee
    SPELL_RANGE_RANGED              = 2      //hunter range and ranged weapon
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

struct SpellLogEffect
{
    int32 Effect = 0;

    Optional<std::vector<SpellLogEffectPowerDrainParams>> PowerDrainTargets;
    Optional<std::vector<SpellLogEffectExtraAttacksParams>> ExtraAttacksTargets;
    Optional<std::vector<SpellLogEffectDurabilityDamageParams>> DurabilityDamageTargets;
    Optional<std::vector<SpellLogEffectGenericVictimParams>> GenericVictimTargets;
    Optional<std::vector<SpellLogEffectTradeSkillItemParams>> TradeSkillTargets;
    Optional<std::vector<SpellLogEffectFeedPetParams>> FeedPetTargets;
};

struct SpellValue
{
    explicit  SpellValue(SpellInfo const* proto, WorldObject const* caster);
    int32     EffectBasePoints[MAX_SPELL_EFFECTS];
    uint32    CustomBasePointsMask;
    uint32    MaxAffectedTargets;
    float     RadiusMod;
    int32     AuraStackAmount;
    float     DurationMul;
    float     CriticalChance;
    Optional<int32> Duration;
    Optional<int32> ParentSpellTargetCount;
    Optional<int32> ParentSpellTargetIndex;
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
    friend class SpellScript;
    public:

        void EffectNULL();
        void EffectUnused();
        void EffectDistract();
        void EffectSchoolDMG();
        void EffectEnvironmentalDMG();
        void EffectInstaKill();
        void EffectDummy();
        void EffectTeleportUnits();
        void EffectTeleportUnitsWithVisualLoadingScreen();
        void EffectApplyAura();
        void EffectSendEvent();
        void EffectPowerBurn();
        void EffectPowerDrain();
        void EffectHeal();
        void EffectBind();
        void EffectTeleportToReturnPoint();
        void EffectIncreaseCurrencyCap();
        void EffectHealthLeech();
        void EffectQuestComplete();
        void EffectCreateItem();
        void EffectCreateItem2();
        void EffectCreateRandomItem();
        void EffectPersistentAA();
        void EffectEnergize();
        void EffectOpenLock();
        void EffectSummonChangeItem();
        void EffectProficiency();
        void EffectSummonType();
        void EffectLearnSpell();
        void EffectDispel();
        void EffectDualWield();
        void EffectPickPocket();
        void EffectAddFarsight();
        void EffectUntrainTalents();
        void EffectHealMechanical();
        void EffectJump();
        void EffectJumpDest();
        void EffectLeapBack();
        void EffectQuestClear();
        void EffectTeleUnitsFaceCaster();
        void EffectLearnSkill();
        void EffectPlayMovie();
        void EffectTradeSkill();
        void EffectEnchantItemPerm();
        void EffectEnchantItemTmp();
        void EffectTameCreature();
        void EffectSummonPet();
        void EffectLearnPetSpell();
        void EffectWeaponDmg();
        void EffectForceCast();
        void EffectTriggerSpell();
        void EffectTriggerMissileSpell();
        void EffectThreat();
        void EffectHealMaxHealth();
        void EffectInterruptCast();
        void EffectSummonObjectWild();
        void EffectScriptEffect();
        void EffectSanctuary();
        void EffectDuel();
        void EffectStuck();
        void EffectSummonPlayer();
        void EffectActivateObject();
        void EffectApplyGlyph();
        void EffectEnchantHeldItem();
        void EffectSummonObject();
        void EffectChangeRaidMarker();
        void EffectResurrect();
        void EffectParry();
        void EffectBlock();
        void EffectLeap();
        void EffectTransmitted();
        void EffectDisEnchant();
        void EffectInebriate();
        void EffectFeedPet();
        void EffectDismissPet();
        void EffectReputation();
        void EffectForceDeselect();
        void EffectSelfResurrect();
        void EffectSkinning();
        void EffectCharge();
        void EffectChargeDest();
        void EffectProspecting();
        void EffectMilling();
        void EffectRenamePet();
        void EffectSendTaxi();
        void EffectKnockBack();
        void EffectPullTowards();
        void EffectPullTowardsDest();
        void EffectDispelMechanic();
        void EffectResurrectPet();
        void EffectDestroyAllTotems();
        void EffectDurabilityDamage();
        void EffectSkill();
        void EffectTaunt();
        void EffectDurabilityDamagePCT();
        void EffectModifyThreatPercent();
        void EffectResurrectNew();
        void EffectAddExtraAttacks();
        void EffectSpiritHeal();
        void EffectSkinPlayerCorpse();
        void EffectStealBeneficialBuff();
        void EffectUnlearnSpecialization();
        void EffectHealPct();
        void EffectEnergizePct();
        void EffectTriggerRitualOfSummoning();
        void EffectSummonRaFFriend();
        void EffectUnlockGuildVaultTab();
        void EffectKillCreditPersonal();
        void EffectKillCredit();
        void EffectQuestFail();
        void EffectQuestStart();
        void EffectRedirectThreat();
        void EffectGameObjectDamage();
        void EffectGameObjectRepair();
        void EffectGameObjectSetDestructionState();
        void EffectCreateTamedPet();
        void EffectDiscoverTaxi();
        void EffectTitanGrip();
        void EffectEnchantItemPrismatic();
        void EffectPlayMusic();
        void EffectActivateSpec();
        void EffectPlaySound();
        void EffectRemoveAura();
        void EffectDamageFromMaxHealthPCT();
        void EffectCastButtons();
        void EffectRechargeItem();
        void EffectGiveCurrency();
        void EffectSummonPersonalGameObject();
        void EffectResurrectWithAura();
        void EffectCreateAreaTrigger();
        void EffectRemoveTalent();
        void EffectDestroyItem();
        void EffectLearnGarrisonBuilding();
        void EffectRemoveAuraBySpellLabel();
        void EffectCreateGarrison();
        void EffectCreateConversation();
        void EffectCancelConversation();
        void EffectAddGarrisonFollower();
        void EffectActivateGarrisonBuilding();
        void EffectGrantBattlePetLevel();
        void EffectGiveExperience();
        void EffectGiveRestedExperience();
        void EffectHealBattlePetPct();
        void EffectEnableBattlePets();
        void EffectChangeBattlePetQuality();
        void EffectLaunchQuestChoice();
        void EffectUncageBattlePet();
        void EffectCreateHeirloomItem();
        void EffectUpgradeHeirloom();
        void EffectApplyEnchantIllusion();
        void EffectUpdatePlayerPhase();
        void EffectUpdateZoneAurasAndPhases();
        void EffectGiveArtifactPower();
        void EffectGiveArtifactPowerNoBonus();
        void EffectPlaySceneScriptPackage();
        void EffectCreateSceneObject();
        void EffectCreatePrivateSceneObject();
        void EffectPlayScene();
        void EffectGiveHonor();
        void EffectJumpCharge();
        void EffectLearnTransmogSet();
        void EffectRespecAzeriteEmpoweredItem();
        void EffectLearnAzeriteEssencePower();
        void EffectCreatePrivateConversation();
        void EffectSendChatMessage();
        void EffectGrantBattlePetExperience();
        void EffectLearnTransmogIllusion();
        void EffectModifyAuraStacks();
        void EffectModifyCooldown();
        void EffectModifyCooldowns();
        void EffectModifyCooldownsByCategory();
        void EffectModifySpellCharges();
        void EffectCreateTraitTreeConfig();
        void EffectChangeActiveCombatTraitConfig();
        void EffectTeleportGraveyard();

        typedef std::unordered_set<Aura*> UsedSpellMods;

        Spell(WorldObject* caster, SpellInfo const* info, TriggerCastFlags triggerFlags, ObjectGuid originalCasterGUID = ObjectGuid::Empty, ObjectGuid originalCastId = ObjectGuid::Empty);
        ~Spell();

        void InitExplicitTargets(SpellCastTargets const& targets);
        void SelectExplicitTargets();

        void SelectSpellTargets();
        void SelectEffectImplicitTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, SpellTargetIndex targetIndex, uint32& processedEffectMask);
        void SelectImplicitChannelTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType);
        void SelectImplicitNearbyTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, SpellTargetIndex targetIndex, uint32 effMask);
        void SelectImplicitConeTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, SpellTargetIndex targetIndex, uint32 effMask);
        void SelectImplicitAreaTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, SpellTargetIndex targetIndex, uint32 effMask);
        void SelectImplicitCasterDestTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, SpellTargetIndex targetIndex);
        void SelectImplicitTargetDestTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, SpellTargetIndex targetIndex);
        void SelectImplicitDestDestTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, SpellTargetIndex targetIndex);
        void SelectImplicitCasterObjectTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType);
        void SelectImplicitTargetObjectTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType);
        void SelectImplicitChainTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, WorldObject* target, uint32 effMask);
        void SelectImplicitTrajTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType);
        void SelectImplicitLineTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, SpellTargetIndex targetIndex, uint32 effMask);

        void SelectEffectTypeImplicitTargets(SpellEffectInfo const& spellEffectInfo);

        static uint32 GetSearcherTypeMask(SpellInfo const* spellInfo, SpellEffectInfo const& spellEffectInfo, SpellTargetObjectTypes objType, ConditionContainer const* condList);
        template<class SEARCHER> static void SearchTargets(SEARCHER& searcher, uint32 containerMask, WorldObject* referer, Position const* pos, float radius);

        WorldObject* SearchNearbyTarget(SpellEffectInfo const& spellEffectInfo, float range, SpellTargetObjectTypes objectType, SpellTargetCheckTypes selectionType, ConditionContainer const* condList = nullptr);
        void SearchAreaTargets(std::list<WorldObject*>& targets, SpellEffectInfo const& spellEffectInfo, float range, Position const* position, WorldObject* referer,
            SpellTargetObjectTypes objectType, SpellTargetCheckTypes selectionType, ConditionContainer const* condList,
            Trinity::WorldObjectSpellAreaTargetSearchReason searchReason);
        void SearchChainTargets(std::list<WorldObject*>& targets, uint32 chainTargets, WorldObject* target, SpellTargetObjectTypes objectType,
            SpellTargetCheckTypes selectType, SpellEffectInfo const& spellEffectInfo, bool isChainHeal);

        GameObject* SearchSpellFocus();

        SpellCastResult prepare(SpellCastTargets const& targets, AuraEffect const* triggeredByAura = nullptr);
        void cancel();
        void update(uint32 difftime);
        void cast(bool skipCheck = false);
        void finish(SpellCastResult result = SPELL_CAST_OK);
        void TakePower();
        void RefundPower();

        void TakeRunePower(bool didHit);
        void RefundRunePower();
        void TakeReagents();
        void TakeCastItem();

        SpellCastResult CheckCast(bool strict, int32* param1 = nullptr, int32* param2 = nullptr);
        SpellCastResult CheckPetCast(Unit* target);

        // handlers
        void handle_immediate();
        uint64 handle_delayed(uint64 t_offset);
        // handler helpers
        void _handle_immediate_phase();
        void _handle_finish_phase();

        SpellCastResult CheckItems(int32* param1, int32* param2) const;
        SpellCastResult CheckRange(bool strict) const;
        SpellCastResult CheckPower() const;
        SpellCastResult CheckRuneCost() const;
        SpellCastResult CheckCasterAuras(int32* param1) const;
        SpellCastResult CheckArenaAndRatedBattlegroundCastRules();
        SpellCastResult CheckMovement() const;

        bool CheckSpellCancelsAuraEffect(AuraType auraType, int32* param1) const;
        bool CheckSpellCancelsCharm(int32* param1) const;
        bool CheckSpellCancelsStun(int32* param1) const;
        bool CheckSpellCancelsSilence(int32* param1) const;
        bool CheckSpellCancelsPacify(int32* param1) const;
        bool CheckSpellCancelsFear(int32* param1) const;
        bool CheckSpellCancelsConfuse(int32* param1) const;
        bool CheckSpellCancelsNoActions(int32* param1) const;

        int32 CalculateDamage(SpellEffectInfo const& spellEffectInfo, Unit const* target, float* var = nullptr) const;

        void Delayed();
        void DelayedChannel();
        uint32 getState() const { return m_spellState; }
        void setState(uint32 state) { m_spellState = state; }

        void DoCreateItem(uint32 itemId, ItemContext context = ItemContext::NONE, std::vector<int32> const* bonusListIDs = nullptr);

        bool CheckEffectTarget(Unit const* target, SpellEffectInfo const& spellEffectInfo, Position const* losPosition) const;
        bool CheckEffectTarget(GameObject const* target, SpellEffectInfo const& spellEffectInfo) const;
        bool CheckEffectTarget(Item const* target, SpellEffectInfo const& spellEffectInfo) const;
        bool CanAutoCast(Unit* target);
        void CheckSrc();
        void CheckDst();

        static void SendCastResult(Player* caster, SpellInfo const* spellInfo, SpellCastVisual spellVisual, ObjectGuid cast_count, SpellCastResult result, SpellCustomErrors customError = SPELL_CUSTOM_ERROR_NONE, int32* param1 = nullptr, int32* param2 = nullptr);
        void SendCastResult(SpellCastResult result, int32* param1 = nullptr, int32* param2 = nullptr) const;
        void SendPetCastResult(SpellCastResult result, int32* param1 = nullptr, int32* param2 = nullptr) const;
        void SendMountResult(MountResult result);
        void SendSpellStart();
        void SendSpellGo();
        void SendSpellCooldown();
        void SendSpellExecuteLog();
        SpellLogEffect& GetExecuteLogEffect(SpellEffectName effect);
        template<typename T>
        std::vector<T>& GetExecuteLogEffectTargets(SpellEffectName effect, Optional<std::vector<T>> SpellLogEffect::* member)
        {
            Optional<std::vector<T>>& opt = GetExecuteLogEffect(effect).*member;
            if (!opt)
                opt.emplace();

            return *opt;
        }
        void ExecuteLogEffectTakeTargetPower(SpellEffectName effect, Unit* target, uint32 powerType, uint32 points, float amplitude);
        void ExecuteLogEffectExtraAttacks(SpellEffectName effect, Unit* victim, uint32 numAttacks);
        void ExecuteLogEffectDurabilityDamage(SpellEffectName effect, Unit* victim, int32 itemId, int32 amount);
        void ExecuteLogEffectOpenLock(SpellEffectName effect, Object* obj);
        void ExecuteLogEffectCreateItem(SpellEffectName effect, uint32 entry);
        void ExecuteLogEffectDestroyItem(SpellEffectName effect, uint32 entry);
        void ExecuteLogEffectSummonObject(SpellEffectName effect, WorldObject* obj);
        void ExecuteLogEffectUnsummonObject(SpellEffectName effect, WorldObject* obj);
        void ExecuteLogEffectResurrect(SpellEffectName effect, Unit* target);
        void SendSpellInterruptLog(Unit* victim, uint32 spellId);
        void SendInterrupted(uint8 result);
        void SendChannelUpdate(uint32 time, Optional<SpellCastResult> result = {});
        void SendChannelStart(uint32 duration);
        void SendResurrectRequest(Player* target);

        void HandleEffects(Unit* pUnitTarget, Item* pItemTarget, GameObject* pGoTarget, Corpse* pCorpseTarget, SpellEffectInfo const& spellEffectInfo, SpellEffectHandleMode mode);
        void HandleThreatSpells();
        static Spell const* ExtractSpellFromEvent(BasicEvent* event);

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
        std::any m_customArg;
        SpellCastVisual m_SpellVisual;
        SpellCastTargets m_targets;
        SpellCustomErrors m_customError;

        UsedSpellMods m_appliedMods;

        Optional<Scripting::v2::ActionResultSetter<SpellCastResult>> m_scriptResult;
        bool m_scriptWaitsForSpellHit = false;

        int32 GetCastTime() const { return m_casttime; }
        int32 GetRemainingCastTime() const { return m_timer; }
        bool IsAutoRepeat() const { return m_autoRepeat; }
        void SetAutoRepeat(bool rep) { m_autoRepeat = rep; }
        void ReSetTimer() { m_timer = m_casttime > 0 ? m_casttime : 0; }
        bool IsTriggered() const;
        bool IsIgnoringCooldowns() const;
        bool IsFocusDisabled() const;
        bool IsProcDisabled() const;
        bool IsChannelActive() const;
        bool IsAutoActionResetSpell() const;
        bool IsPositive() const;

        bool IsEmpowerSpell() const { return m_empower != nullptr; }
        void SetEmpowerReleasedByClient(bool release);
        bool CanReleaseEmpowerSpell() const;

        bool IsTriggeredByAura(SpellInfo const* auraSpellInfo) const { return (auraSpellInfo == m_triggeredByAuraSpell); }

        int32 GetProcChainLength() const { return m_procChainLength; }

        bool IsDeletable() const { return !m_referencedFromCurrentSpell && !m_executedCurrently; }
        void SetReferencedFromCurrent(bool yes) { m_referencedFromCurrentSpell = yes; }
        bool IsInterruptable() const { return !m_executedCurrently; }
        void SetExecutedCurrently(bool yes) {m_executedCurrently = yes;}
        uint64 GetDelayStart() const { return m_delayStart; }
        void SetDelayStart(uint64 m_time) { m_delayStart = m_time; }
        uint64 GetDelayMoment() const { return m_delayMoment; }
        uint64 CalculateDelayMomentForDst(float launchDelay) const;
        void RecalculateDelayMomentForDst();
        void UpdateDelayMomentForDst(uint64 hitDelay);
        void UpdateDelayMomentForUnitTarget(Unit* unit, uint64 hitDelay);
        uint8 GetRuneState() const { return m_runesState; }
        void SetRuneState(uint8 value) { m_runesState = value; }

        bool IsNeedSendToClient() const;

        CurrentSpellTypes GetCurrentContainer() const;

        WorldObject* GetCaster() const { return m_caster; }
        ObjectGuid GetOriginalCasterGUID() const { return m_originalCasterGUID; }
        Unit* GetOriginalCaster() const { return m_originalCaster; }
        SpellInfo const* GetSpellInfo() const { return m_spellInfo; }
        Difficulty GetCastDifficulty() const;
        std::vector<SpellPowerCost> const& GetPowerCost() const { return m_powerCost; }
        bool HasPowerTypeCost(Powers power) const;
        Optional<int32> GetPowerTypeCostAmount(Powers power) const;

        bool UpdatePointers();                              // must be used at call Spell code after time delay (non triggered spell cast/update spell call/etc)

        void CleanupTargetList();

        void SetSpellValue(SpellValueMod mod, int32 value);

        Spell** m_selfContainer;                            // pointer to our spell container (if applicable)

        SpellInfo const* GetTriggeredByAuraSpell() const { return m_triggeredByAuraSpell; }

        int32 GetTimer() const { return m_timer; }

        int64 GetUnitTargetCountForEffect(SpellEffIndex effect) const;
        int64 GetGameObjectTargetCountForEffect(SpellEffIndex effect) const;
        int64 GetItemTargetCountForEffect(SpellEffIndex effect) const;
        int64 GetCorpseTargetCountForEffect(SpellEffIndex effect) const;

        std::string GetDebugInfo() const;

        Trinity::unique_weak_ptr<Spell> GetWeakPtr() const;

        void CallScriptOnResistAbsorbCalculateHandlers(DamageInfo const& damageInfo, uint32& resistAmount, int32& absorbAmount);

        bool IsWithinLOS(WorldObject const* source, WorldObject const* target, bool targetAsSourceLocation, VMAP::ModelIgnoreFlags ignoreFlags) const;
        bool IsWithinLOS(WorldObject const* source, Position const& target, VMAP::ModelIgnoreFlags ignoreFlags) const;
        void MovePosition(Position& pos, WorldObject const* from, float dist, float angle) const;

    protected:
        bool HasGlobalCooldown() const;
        void TriggerGlobalCooldown();
        void CancelGlobalCooldown();
        void _cast(bool skipCheck = false);

        std::pair<float, float> GetMinMaxRange(bool strict) const;

        WorldObject* const m_caster;

        SpellValue* const m_spellValue;

        ObjectGuid m_originalCasterGUID;                    // real source of cast (aura caster/etc), used for spell targets selection
                                                            // e.g. damage around area spell trigered by victim aura and damage enemies of aura caster
        Unit* m_originalCaster;                             // cached pointer for m_originalCaster, updated at Spell::UpdatePointers()

        // Spell data
        SpellSchoolMask m_spellSchoolMask;                  // Spell school (can be overwrite for some spells (wand shoot for example)
        WeaponAttackType m_attackType;                      // For weapon based attack

        std::vector<SpellPowerCost> m_powerCost;            // Calculated spell cost initialized only in Spell::prepare
        int32 m_casttime;                                   // Calculated spell cast time initialized only in Spell::prepare
        int32 m_channeledDuration;                          // Calculated channeled spell duration in order to calculate correct pushback.
        bool m_canReflect;                                  // can reflect this spell?
        bool m_autoRepeat;
        uint8 m_runesState;

        struct EmpowerData
        {
            Milliseconds MinHoldTime = 0ms;
            std::vector<Milliseconds> StageDurations;
            int32 CompletedStages = 0;
            bool IsReleasedByClient = false;
            bool IsReleased = false;
        };
        std::unique_ptr<EmpowerData> m_empower;

        uint8 m_delayAtDamageCount;
        bool IsDelayableNoMore()
        {
            if (m_delayAtDamageCount >= 2)
                return true;

            ++m_delayAtDamageCount;
            return false;
        }

        // Delayed spells system
        uint64 m_delayStart;                                // time of spell delay start, filled by event handler, zero = just started
        uint64 m_delayMoment;                               // moment of next delay call, used internally
        bool m_launchHandled;                               // were launch actions handled
        bool m_immediateHandled;                            // were immediate actions handled? (used by delayed spells only)

        // These vars are used in both delayed spell system and modified immediate spell system
        bool m_referencedFromCurrentSpell;                  // mark as references to prevent deleted and access by dead pointers
        bool m_executedCurrently;                           // mark as executed to prevent deleted and access by dead pointers
        uint32 m_applyMultiplierMask;
        float m_damageMultipliers[MAX_SPELL_EFFECTS];

        // Current targets, to be used in SpellEffects (MUST BE USED ONLY IN SPELL EFFECTS)
        Unit* unitTarget;
        Item* itemTarget;
        GameObject* gameObjTarget;
        Corpse* m_corpseTarget;
        WorldLocation* destTarget;
        int32 damage;
        SpellMissInfo targetMissInfo;
        float variance;
        SpellEffectHandleMode effectHandleMode;
        SpellEffectInfo const* effectInfo;
        // used in effects handlers
        Unit* GetUnitCasterForEffectHandlers() const;
        UnitAura* _spellAura;
        DynObjAura* _dynObjAura;

        // -------------------------------------------
        GameObject* focusObject;

        // Damage and healing in effects need just calculate
        int32 m_damage;           // Damage  in effects count here
        int32 m_healing;          // Healing in effects count here

        // ******************************************
        // Spell trigger system
        // ******************************************
        ProcFlagsInit m_procAttacker;         // Attacker trigger flags
        ProcFlagsInit m_procVictim;           // Victim   trigger flags
        ProcFlagsHit m_hitMask;
        ProcFlagsSpellType m_procSpellType;   // for finish procs
        void prepareDataForTriggerSystem();

        // *****************************************
        // Spell target subsystem
        // *****************************************
        // Targets store structures and data
        struct TargetInfoBase
        {
            virtual void PreprocessTarget(Spell* /*spell*/) { }
            virtual void DoTargetSpellHit(Spell* spell, SpellEffectInfo const& spellEffectInfo) = 0;
            virtual void DoDamageAndTriggers(Spell* /*spell*/) { }

            uint32 EffectMask = 0;

        protected:
            TargetInfoBase() { }
            virtual ~TargetInfoBase() { }
        };

        struct TargetInfo : public TargetInfoBase
        {
            void PreprocessTarget(Spell* spell) override;
            void DoTargetSpellHit(Spell* spell, SpellEffectInfo const& spellEffectInfo) override;
            void DoDamageAndTriggers(Spell* spell) override;

            ObjectGuid TargetGUID;
            uint64 TimeDelay = 0ULL;
            int32 Damage = 0;
            int32 Healing = 0;

            SpellMissInfo MissCondition = SPELL_MISS_NONE;
            SpellMissInfo ReflectResult = SPELL_MISS_NONE;

            bool IsAlive = false;
            bool IsCrit = false;

            // info set at PreprocessTarget, used by DoTargetSpellHit
            DiminishingGroup DRGroup = DIMINISHING_NONE;
            int32 AuraDuration = 0;
            int32 AuraBasePoints[MAX_SPELL_EFFECTS] = { };
            bool Positive = true;
            UnitAura* HitAura = nullptr;

        private:
            Unit* _spellHitTarget = nullptr; // changed for example by reflect
            bool _enablePVP = false;         // need to enable PVP at DoDamageAndTriggers?
        };
        std::vector<TargetInfo> m_UniqueTargetInfo;
        uint32 m_channelTargetEffectMask;                       // Mask req. alive targets

        struct GOTargetInfo : public TargetInfoBase
        {
            void DoTargetSpellHit(Spell* spell, SpellEffectInfo const& spellEffectInfo) override;

            ObjectGuid TargetGUID;
            uint64 TimeDelay = 0ULL;
        };
        std::vector<GOTargetInfo> m_UniqueGOTargetInfo;

        struct ItemTargetInfo : public TargetInfoBase
        {
            void DoTargetSpellHit(Spell* spell, SpellEffectInfo const& spellEffectInfo) override;

            Item* TargetItem = nullptr;
        };
        std::vector<ItemTargetInfo> m_UniqueItemInfo;

        struct CorpseTargetInfo : public TargetInfoBase
        {
            void DoTargetSpellHit(Spell* spell, SpellEffectInfo const& spellEffectInfo) override;

            ObjectGuid TargetGUID;
            uint64 TimeDelay = 0ULL;
        };
        std::vector<CorpseTargetInfo> m_UniqueCorpseTargetInfo;

        template <class Container>
        void DoProcessTargetContainer(Container& targetContainer);

        SpellDestination m_destTargets[MAX_SPELL_EFFECTS];

        int32 GetUnitTargetIndexForEffect(ObjectGuid const& target, SpellEffIndex effect) const;

        void AddUnitTarget(Unit* target, uint32 effectMask, bool checkIfValid = true, bool implicit = true, Position const* losPosition = nullptr);
        void AddGOTarget(GameObject* target, uint32 effectMask);
        void AddItemTarget(Item* item, uint32 effectMask);
        void AddCorpseTarget(Corpse* target, uint32 effectMask);
        void AddDestTarget(SpellDestination const& dest, uint32 effIndex);

        void PreprocessSpellLaunch(TargetInfo& targetInfo);
        SpellMissInfo PreprocessSpellHit(Unit* unit, TargetInfo& targetInfo);
        void DoSpellEffectHit(Unit* unit, SpellEffectInfo const& spellEffectInfo, TargetInfo& targetInfo);

        void DoTriggersOnSpellHit(Unit* unit);
        bool UpdateChanneledTargetList();
        bool IsValidDeadOrAliveTarget(Unit const* target) const;
        void HandleLaunchPhase();
        void DoEffectOnLaunchTarget(TargetInfo& targetInfo, float multiplier, SpellEffectInfo const& spellEffectInfo);
        void ResetCombatTimers();

        void PrepareTargetProcessing();
        void FinishTargetProcessing();

        // Scripting system
        void LoadScripts();
        void CallScriptOnPrecastHandler();
        void CallScriptBeforeCastHandlers();
        void CallScriptOnCastHandlers();
        void CallScriptAfterCastHandlers();
        SpellCastResult CallScriptCheckCastHandlers();
        int32 CallScriptCalcCastTimeHandlers(int32 originalCastTime);
        bool CallScriptEffectHandlers(SpellEffIndex effIndex, SpellEffectHandleMode mode);
        void CallScriptSuccessfulDispel(SpellEffIndex effIndex);
        void CallScriptBeforeHitHandlers(SpellMissInfo missInfo);
        void CallScriptOnHitHandlers();
        void CallScriptAfterHitHandlers();
    public:
        void CallScriptCalcCritChanceHandlers(Unit const* victim, float& chance);
        void CallScriptCalcDamageHandlers(Unit* victim, int32& damage, int32& flatMod, float& pctMod);
        void CallScriptCalcHealingHandlers(Unit* victim, int32& healing, int32& flatMod, float& pctMod);
    protected:
        void CallScriptObjectAreaTargetSelectHandlers(std::list<WorldObject*>& targets, SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType);
        void CallScriptObjectTargetSelectHandlers(WorldObject*& target, SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType);
        void CallScriptDestinationTargetSelectHandlers(SpellDestination& target, SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType);
        void CallScriptEmpowerStageCompletedHandlers(int32 completedStagesCount);
        void CallScriptEmpowerCompletedHandlers(int32 completedStagesCount);
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

        bool CanExecuteTriggersOnHit(Unit* unit, SpellInfo const* triggeredByAura = nullptr) const;
        void PrepareTriggersExecutedOnHit();
        typedef std::vector<HitTriggerSpell> HitTriggerSpellList;
        HitTriggerSpellList m_hitTriggerSpells;

        // effect helpers
        void SummonGuardian(SpellEffectInfo const* effect, uint32 entry, SummonPropertiesEntry const* properties, uint32 numSummons, ObjectGuid privateObjectOwner);
        void CalculateJumpSpeeds(SpellEffectInfo const* effInfo, float dist, float& speedXY, float& speedZ);

        void UpdateSpellCastDataTargets(WorldPackets::Spells::SpellCastData& data);
        int32 GetSpellCastDataAmmo();
        void UpdateSpellHealPrediction(WorldPackets::Spells::SpellHealPrediction& healPrediction, bool withPeriodic);

        SpellCastResult CanOpenLock(SpellEffectInfo const& effect, uint32 lockid, SkillType& skillid, int32& reqSkillValue, int32& skillValue);
        // -------------------------------------------

        uint32 m_spellState;
        int32 m_timer;

        SpellEvent* _spellEvent;
        TriggerCastFlags _triggeredCastFlags;

        // if need this can be replaced by Aura copy
        // we can't store original aura link to prevent access to deleted auras
        // and in same time need aura data and after aura deleting.
        SpellInfo const* m_triggeredByAuraSpell;
        int32 m_procChainLength;

        std::unique_ptr<PathGenerator> m_preGeneratedPath;

        std::vector<SpellLogEffect> _executeLogEffects;

        Spell(Spell const& right) = delete;
        Spell& operator=(Spell const& right) = delete;
};

namespace Trinity
{
    struct TC_GAME_API WorldObjectSpellTargetCheck
    {
    protected:
        WorldObject* _caster;
        WorldObject* _referer;
        SpellInfo const* _spellInfo;
        SpellTargetCheckTypes _targetSelectionType;
        std::unique_ptr<ConditionSourceInfo> _condSrcInfo;
        ConditionContainer const* _condList;
        SpellTargetObjectTypes _objectType;

        WorldObjectSpellTargetCheck(WorldObject* caster, WorldObject* referer, SpellInfo const* spellInfo,
            SpellTargetCheckTypes selectionType, ConditionContainer const* condList, SpellTargetObjectTypes objectType);
        ~WorldObjectSpellTargetCheck();

        bool operator()(WorldObject* target) const;
    };

    struct TC_GAME_API WorldObjectSpellNearbyTargetCheck : public WorldObjectSpellTargetCheck
    {
        float _range;
        Position const* _position;
        WorldObjectSpellNearbyTargetCheck(float range, WorldObject* caster, SpellInfo const* spellInfo,
            SpellTargetCheckTypes selectionType, ConditionContainer const* condList, SpellTargetObjectTypes objectType);

        bool operator()(WorldObject* target);
    };

    enum class WorldObjectSpellAreaTargetSearchReason
    {
        Area,
        Chain
    };

    struct TC_GAME_API WorldObjectSpellAreaTargetCheck : public WorldObjectSpellTargetCheck
    {
        float _range;
        Position const* _position;
        WorldObjectSpellAreaTargetSearchReason _searchReason;
        WorldObjectSpellAreaTargetCheck(float range, Position const* position, WorldObject* caster,
            WorldObject* referer, SpellInfo const* spellInfo, SpellTargetCheckTypes selectionType, ConditionContainer const* condList, SpellTargetObjectTypes objectType,
            WorldObjectSpellAreaTargetSearchReason searchReason = WorldObjectSpellAreaTargetSearchReason::Area);

        bool operator()(WorldObject* target) const;
    };

    struct TC_GAME_API WorldObjectSpellConeTargetCheck : public WorldObjectSpellAreaTargetCheck
    {
        Position _coneSrc;
        float _coneAngle;
        float _lineWidth;
        WorldObjectSpellConeTargetCheck(Position const& coneSrc, float coneAngle, float lineWidth, float range, WorldObject* caster,
            SpellInfo const* spellInfo, SpellTargetCheckTypes selectionType, ConditionContainer const* condList, SpellTargetObjectTypes objectType);

        bool operator()(WorldObject* target) const;
    };

    struct TC_GAME_API WorldObjectSpellTrajTargetCheck : public WorldObjectSpellTargetCheck
    {
        float _range;
        Position const* _position;
        WorldObjectSpellTrajTargetCheck(float range, Position const* position, WorldObject* caster,
            SpellInfo const* spellInfo, SpellTargetCheckTypes selectionType, ConditionContainer const* condList, SpellTargetObjectTypes objectType);

        bool operator()(WorldObject* target) const;
    };

    struct TC_GAME_API WorldObjectSpellLineTargetCheck : public WorldObjectSpellAreaTargetCheck
    {
        Position _position;
        float _lineWidth;
        WorldObjectSpellLineTargetCheck(Position const* srcPosition, Position const* dstPosition, float lineWidth, float range, WorldObject* caster,
            SpellInfo const* spellInfo, SpellTargetCheckTypes selectionType, ConditionContainer const* condList, SpellTargetObjectTypes objectType);

        bool operator()(WorldObject* target) const;
    };

    TC_GAME_API void SelectRandomInjuredTargets(std::list<WorldObject*>& targets, size_t maxTargets, bool prioritizePlayers, Unit const* prioritizeGroupMembersOf = nullptr);
}

extern template void Spell::SearchTargets<Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellAreaTargetCheck>>(Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellAreaTargetCheck>& searcher, uint32 containerMask, WorldObject* referer, Position const* pos, float radius);

using SpellEffectHandlerFn = void(Spell::*)();

#endif
