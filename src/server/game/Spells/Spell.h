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
#include "ObjectGuid.h"
#include "Position.h"
#include "SharedDefines.h"
#include <memory>

namespace WorldPackets
{
    namespace Spells
    {
        struct SpellTargetData;
        struct SpellAmmo;
        struct SpellCastData;
    }
}

class Aura;
class AuraEffect;
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
class WorldPacket;
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
#define MAX_SPELL_RANGE_TOLERANCE 3.0f
#define TRAJECTORY_MISSILE_SIZE 3.0f

enum SpellCastFlags
{
    CAST_FLAG_NONE               = 0x00000000,
    CAST_FLAG_PENDING            = 0x00000001,              // aoe combat log?
    CAST_FLAG_UNKNOWN_2          = 0x00000002,
    CAST_FLAG_UNKNOWN_3          = 0x00000004,
    CAST_FLAG_UNKNOWN_4          = 0x00000008,              // ignore AOE visual
    CAST_FLAG_UNKNOWN_5          = 0x00000010,
    CAST_FLAG_AMMO               = 0x00000020,              // Projectiles visual
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
    CAST_FLAG_UNKNOWN_31         = 0x40000000,
    CAST_FLAG_UNKNOWN_32         = 0x80000000
};

enum SpellRangeFlag
{
    SPELL_RANGE_DEFAULT             = 0,
    SPELL_RANGE_MELEE               = 1,     //melee
    SPELL_RANGE_RANGED              = 2      //hunter range and ranged weapon
};

enum SpellFinishReason : uint8
{
    SPELL_FINISHED_SUCCESSFUL_CAST      = 0, // spell has sucessfully launched
    SPELL_FINISHED_CANCELED             = 1, // spell has been canceled (interrupts)
    SPELL_FINISHED_CHANNELING_COMPLETE  = 2  // spell channeling has been finished
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

class TC_GAME_API SpellCastTargets
{
    public:
        SpellCastTargets();
        ~SpellCastTargets();

        void Read(ByteBuffer& data, Unit* caster);
        void Write(WorldPackets::Spells::SpellTargetData& data);

        uint32 GetTargetMask() const { return m_targetMask; }
        void SetTargetMask(uint32 newMask) { m_targetMask = newMask; }

        void SetTargetFlag(SpellCastTargetFlags flag) { m_targetMask |= flag; }

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

        float GetElevation() const { return m_elevation; }
        void SetElevation(float elevation) { m_elevation = elevation; }
        float GetSpeed() const { return m_speed; }
        void SetSpeed(float speed) { m_speed = speed; }

        float GetDist2d() const { return m_src._position.GetExactDist2d(&m_dst._position); }
        float GetSpeedXY() const { return m_speed * std::cos(m_elevation); }
        float GetSpeedZ() const { return m_speed * std::sin(m_elevation); }

        void Update(WorldObject* caster);

    private:
        uint32 m_targetMask;

        // objects (can be used at spell creating and after Update at casting)
        WorldObject* m_objectTarget;
        Item* m_itemTarget;

        // object GUID/etc, can be used always
        ObjectGuid m_objectTargetGUID;
        ObjectGuid m_itemTargetGUID;
        uint32 m_itemTargetEntry;

        SpellDestination m_src;
        SpellDestination m_dst;

        float m_elevation, m_speed;
        std::string m_strTarget;
};

struct SpellValue
{
    explicit  SpellValue(SpellInfo const* proto);
    int32     EffectBasePoints[MAX_SPELL_EFFECTS];
    uint32    MaxAffectedTargets;
    float     RadiusMod;
    uint8     AuraStackAmount;
    float     CriticalChance;
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
        void EffectPull();
        void EffectSchoolDMG();
        void EffectEnvironmentalDMG();
        void EffectInstaKill();
        void EffectDummy();
        void EffectTeleportUnits();
        void EffectApplyAura();
        void EffectSendEvent();
        void EffectPowerBurn();
        void EffectPowerDrain();
        void EffectHeal();
        void EffectBind();
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
        void EffectAddHonor();
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
        void EffectAddComboPoints();
        void EffectDuel();
        void EffectStuck();
        void EffectSummonPlayer();
        void EffectActivateObject();
        void EffectApplyGlyph();
        void EffectEnchantHeldItem();
        void EffectSummonObject();
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
        void EffectKillCreditPersonal();
        void EffectKillCredit();
        void EffectQuestFail();
        void EffectQuestStart();
        void EffectRedirectThreat();
        void EffectGameObjectDamage();
        void EffectGameObjectRepair();
        void EffectGameObjectSetDestructionState();
        void EffectActivateRune();
        void EffectCreateTamedPet();
        void EffectDiscoverTaxi();
        void EffectTitanGrip();
        void EffectEnchantItemPrismatic();
        void EffectPlayMusic();
        void EffectSpecCount();
        void EffectActivateSpec();
        void EffectPlaySound();
        void EffectRemoveAura();
        void EffectCastButtons();
        void EffectRechargeManaGem();

        typedef std::unordered_set<Aura*> UsedSpellMods;

        Spell(WorldObject* caster, SpellInfo const* info, TriggerCastFlags triggerFlags, ObjectGuid originalCasterGUID = ObjectGuid::Empty);
        ~Spell();

        void InitExplicitTargets(SpellCastTargets const& targets);
        void SelectExplicitTargets();

        void SelectSpellTargets();
        void SelectEffectImplicitTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, uint32& processedEffectMask);
        void SelectImplicitChannelTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType);
        void SelectImplicitNearbyTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, uint32 effMask);
        void SelectImplicitConeTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, uint32 effMask);
        void SelectImplicitAreaTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, uint32 effMask);
        void SelectImplicitCasterDestTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType);
        void SelectImplicitTargetDestTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType);
        void SelectImplicitDestDestTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType);
        void SelectImplicitCasterObjectTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType);
        void SelectImplicitTargetObjectTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType);
        void SelectImplicitChainTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, WorldObject* target, uint32 effMask);
        void SelectImplicitTrajTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType);

        void SelectEffectTypeImplicitTargets(SpellEffectInfo const& spellEffectInfo);

        uint32 GetSearcherTypeMask(SpellTargetObjectTypes objType, ConditionContainer* condList);
        template<class SEARCHER> void SearchTargets(SEARCHER& searcher, uint32 containerMask, WorldObject* referer, Position const* pos, float radius);

        WorldObject* SearchNearbyTarget(float range, SpellTargetObjectTypes objectType, SpellTargetCheckTypes selectionType, ConditionContainer* condList = nullptr);
        void SearchAreaTargets(std::list<WorldObject*>& targets, float range, Position const* position, WorldObject* referer, SpellTargetObjectTypes objectType, SpellTargetCheckTypes selectionType, ConditionContainer* condList);
        void SearchChainTargets(std::list<WorldObject*>& targets, uint32 chainTargets, WorldObject* target, SpellTargetObjectTypes objectType, SpellTargetCheckTypes selectType, ConditionContainer* condList, bool isChainHeal);

        GameObject* SearchSpellFocus();

        SpellCastResult prepare(SpellCastTargets const& targets, AuraEffect const* triggeredByAura = nullptr);
        void cancel();
        void update(uint32 difftime);
        void cast(bool skipCheck = false);
        void finish(bool ok = true);
        void TakePower();
        void TakeAmmo();

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
        SpellCastResult CheckRuneCost(uint32 runeCostID) const;
        SpellCastResult CheckCasterAuras(uint32* param1) const;

        bool CheckSpellCancelsAuraEffect(AuraType auraType, uint32* param1) const;
        bool CheckSpellCancelsCharm(uint32* param1) const;
        bool CheckSpellCancelsStun(uint32* param1) const;
        bool CheckSpellCancelsSilence(uint32* param1) const;
        bool CheckSpellCancelsPacify(uint32* param1) const;
        bool CheckSpellCancelsFear(uint32* param1) const;
        bool CheckSpellCancelsConfuse(uint32* param1) const;

        int32 CalculateDamage(SpellEffectInfo const& spellEffectInfo) const;

        void Delayed();
        void DelayedChannel();
        uint32 getState() const { return m_spellState; }
        void setState(uint32 state) { m_spellState = state; }

        void DoCreateItem(uint32 itemId);
        void UpdateSpellCastDataTargets(WorldPackets::Spells::SpellCastData& data);
        void UpdateSpellCastDataAmmo(WorldPackets::Spells::SpellAmmo& data);

        bool CheckEffectTarget(Unit const* target, SpellEffectInfo const& spellEffectInfo, Position const* losPosition) const;
        bool CanAutoCast(Unit* target);
        void CheckSrc();
        void CheckDst();

        static void WriteCastResultInfo(WorldPacket& data, Player* caster, SpellInfo const* spellInfo, uint8 castCount, SpellCastResult result, SpellCustomErrors customError, uint32* param1 = nullptr, uint32* param2 = nullptr);
        static void SendCastResult(Player* caster, SpellInfo const* spellInfo, uint8 castCount, SpellCastResult result, SpellCustomErrors customError = SPELL_CUSTOM_ERROR_NONE, uint32* param1 = nullptr, uint32* param2 = nullptr);
        void SendCastResult(SpellCastResult result, uint32* param1 = nullptr, uint32* param2 = nullptr) const;
        void SendPetCastResult(SpellCastResult result);
        void SendMountResult(MountResult result);
        void SendSpellStart();
        void SendSpellGo();
        void SendSpellCooldown();
        void SendLogExecute();
        void ExecuteLogEffectTakeTargetPower(uint8 effIndex, Unit* target, uint32 powerType, uint32 powerTaken, float gainMultiplier);
        void ExecuteLogEffectExtraAttacks(uint8 effIndex, Unit* victim, uint32 attCount);
        void ExecuteLogEffectInterruptCast(uint8 effIndex, Unit* victim, uint32 spellId);
        void ExecuteLogEffectDurabilityDamage(uint8 effIndex, Unit* victim, int32 itemId, int32 slot);
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

        void HandleEffects(Unit* pUnitTarget, Item* pItemTarget, GameObject* pGoTarget, Corpse* pCorpseTarget, SpellEffectInfo const& spellEffectInfo, SpellEffectHandleMode mode);
        void HandleThreatSpells();

        SpellInfo const* const m_spellInfo;
        Item* m_CastItem;
        ObjectGuid m_castItemGUID;
        uint32 m_castItemEntry;
        uint8 m_cast_count;
        uint32 m_glyphIndex;
        SpellCastTargets m_targets;

        void AddComboPointGain(Unit* target, int8 amount)
        {
            if (target != m_comboTarget)
            {
                m_comboTarget = target;
                m_comboPointGain = amount;
            }
            else
                m_comboPointGain += amount;
        }
        Unit* m_comboTarget;
        int8 m_comboPointGain;
        SpellCustomErrors m_customError;

        UsedSpellMods m_appliedMods;

        int32 GetCastTime() const { return m_casttime; }
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

        bool IsTriggeredByAura(SpellInfo const* auraSpellInfo) const { return (auraSpellInfo == m_triggeredByAuraSpell); }

        bool IsDeletable() const { return !m_referencedFromCurrentSpell && !m_executedCurrently; }
        void SetReferencedFromCurrent(bool yes) { m_referencedFromCurrentSpell = yes; }
        bool IsInterruptable() const { return !m_executedCurrently; }
        void SetExecutedCurrently(bool yes) {m_executedCurrently = yes;}
        uint64 GetDelayStart() const { return m_delayStart; }
        void SetDelayStart(uint64 m_time) { m_delayStart = m_time; }
        uint64 GetDelayMoment() const { return m_delayMoment; }
        uint64 CalculateDelayMomentForDst() const;
        void RecalculateDelayMomentForDst();
        uint8 GetRuneState() const { return m_runesState; }
        void SetRuneState(uint8 value) { m_runesState = value; }

        bool IsNeedSendToClient() const;

        CurrentSpellTypes GetCurrentContainer() const;

        WorldObject* GetCaster() const { return m_caster; }
        Unit* GetOriginalCaster() const { return m_originalCaster; }
        SpellInfo const* GetSpellInfo() const { return m_spellInfo; }
        int32 GetPowerCost() const { return m_powerCost; }

        bool UpdatePointers();                              // must be used at call Spell code after time delay (non triggered spell cast/update spell call/etc)

        void CleanupTargetList();

        void SetSpellValue(SpellValueMod mod, int32 value);

        Spell** m_selfContainer;                            // pointer to our spell container (if applicable)

        std::string GetDebugInfo() const;
        void CallScriptOnResistAbsorbCalculateHandlers(DamageInfo const& damageInfo, uint32& resistAmount, int32& absorbAmount);

    protected:
        bool HasGlobalCooldown() const;
        void TriggerGlobalCooldown();
        void CancelGlobalCooldown();
        void _cast(bool skipCheck = false);

        void SendLoot(ObjectGuid guid, LootType loottype);
        std::pair<float, float> GetMinMaxRange(bool strict) const;

        WorldObject* const m_caster;

        SpellValue* const m_spellValue;

        ObjectGuid m_originalCasterGUID;                    // real source of cast (aura caster/etc), used for spell targets selection
                                                            // e.g. damage around area spell trigered by victim aura and damage enemies of aura caster
        Unit* m_originalCaster;                             // cached pointer for m_originalCaster, updated at Spell::UpdatePointers()

        // Spell data
        SpellSchoolMask m_spellSchoolMask;                  // Spell school (can be overwrite for some spells (wand shoot for example)
        WeaponAttackType m_attackType;                      // For weapon based attack
        int32 m_powerCost;                                  // Calculated spell cost initialized only in Spell::prepare
        int32 m_casttime;                                   // Calculated spell cast time initialized only in Spell::prepare
        int32 m_channeledDuration;                          // Calculated channeled spell duration in order to calculate correct pushback.
        bool m_canReflect;                                  // can reflect this spell?
        bool m_autoRepeat;
        uint8 m_runesState;

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
        bool m_immediateHandled;                            // were immediate actions handled? (used by delayed spells only)

        // These vars are used in both delayed spell system and modified immediate spell system
        bool m_referencedFromCurrentSpell;                  // mark as references to prevent deleted and access by dead pointers
        bool m_executedCurrently;                           // mark as executed to prevent deleted and access by dead pointers
        bool m_needComboPoints;
        uint8 m_applyMultiplierMask;
        float m_damageMultipliers[MAX_SPELL_EFFECTS];

        // Current targets, to be used in SpellEffects (MUST BE USED ONLY IN SPELL EFFECTS)
        Unit* unitTarget;
        Item* itemTarget;
        GameObject* gameObjTarget;
        Corpse* m_corpseTarget;
        WorldLocation* destTarget;
        int32 damage;
        SpellMissInfo targetMissInfo;
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
        uint32 m_procAttacker;                // Attacker trigger flags
        uint32 m_procVictim;                  // Victim   trigger flags
        uint32 m_hitMask;
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

            uint8 EffectMask = 0;

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
            bool ScaleAura = false;

            // info set at PreprocessTarget, used by DoTargetSpellHit
            DiminishingGroup DRGroup = DIMINISHING_NONE;
            int32 AuraDuration = 0;
            SpellInfo const* AuraSpellInfo = nullptr;
            int32 AuraBasePoints[MAX_SPELL_EFFECTS] = { };
            bool Positive = true;
            UnitAura* HitAura = nullptr;

        private:
            Unit* _spellHitTarget = nullptr; // changed for example by reflect
            bool _enablePVP = false;         // need to enable PVP at DoDamageAndTriggers?
        };
        std::vector<TargetInfo> m_UniqueTargetInfo;
        uint8 m_channelTargetEffectMask;                        // Mask req. alive targets

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

        void AddUnitTarget(Unit* target, uint32 effectMask, bool checkIfValid = true, bool implicit = true, Position const* losPosition = nullptr);
        void AddGOTarget(GameObject* target, uint32 effectMask);
        void AddItemTarget(Item* item, uint32 effectMask);
        void AddCorpseTarget(Corpse* target, uint32 effectMask);
        void AddDestTarget(SpellDestination const& dest, uint32 effIndex);

        SpellMissInfo PreprocessSpellHit(Unit* unit, bool scaleAura, TargetInfo& targetInfo);
        void DoSpellEffectHit(Unit* unit, SpellEffectInfo const& spellEffectInfo, TargetInfo& targetInfo);

        void DoTriggersOnSpellHit(Unit* unit, uint8 effMask);
        bool UpdateChanneledTargetList();
        bool IsValidDeadOrAliveTarget(Unit const* target) const;
        void HandleLaunchPhase();
        void DoEffectOnLaunchTarget(TargetInfo& targetInfo, float multiplier, SpellEffectInfo const& spellEffectInfo);

        void PrepareTargetProcessing();
        void FinishTargetProcessing();

        // spell execution log
        void InitEffectExecuteData(uint8 effIndex);
        void AssertEffectExecuteData() const;

        // Scripting system
        void LoadScripts();
        void CallScriptBeforeCastHandlers();
        void CallScriptOnCastHandlers();
        void CallScriptAfterCastHandlers();
        SpellCastResult CallScriptCheckCastHandlers();
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

        bool CanExecuteTriggersOnHit(uint8 effMask, SpellInfo const* triggeredByAura = nullptr) const;
        void PrepareTriggersExecutedOnHit();
        typedef std::vector<HitTriggerSpell> HitTriggerSpellList;
        HitTriggerSpellList m_hitTriggerSpells;

        // effect helpers
        void SummonGuardian(SpellEffectInfo const& spellEffectInfo, uint32 entry, SummonPropertiesEntry const* properties, uint32 numSummons);
        void CalculateJumpSpeeds(SpellEffectInfo const& spellEffectInfo, float dist, float& speedXY, float& speedZ);

        SpellCastResult CanOpenLock(SpellEffectInfo const& spellEffectInfo, uint32 lockid, SkillType& skillid, int32& reqSkillValue, int32& skillValue);
        // -------------------------------------------

        uint32 m_spellState;
        int32 m_timer;

        SpellEvent* _spellEvent;
        TriggerCastFlags _triggeredCastFlags;

        // if need this can be replaced by Aura copy
        // we can't store original aura link to prevent access to deleted auras
        // and in same time need aura data and after aura deleting.
        SpellInfo const* m_triggeredByAuraSpell;

        uint8 m_auraScaleMask;
        std::unique_ptr<PathGenerator> m_preGeneratedPath;

        ByteBuffer* m_effectExecuteData[MAX_SPELL_EFFECTS];

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

            WorldObjectSpellTargetCheck(WorldObject* caster, WorldObject* referer, SpellInfo const* spellInfo,
                SpellTargetCheckTypes selectionType, ConditionContainer const* condList);
            ~WorldObjectSpellTargetCheck();

            bool operator()(WorldObject* target) const;
    };

    struct TC_GAME_API WorldObjectSpellNearbyTargetCheck : public WorldObjectSpellTargetCheck
    {
        float _range;
        Position const* _position;
        WorldObjectSpellNearbyTargetCheck(float range, WorldObject* caster, SpellInfo const* spellInfo,
            SpellTargetCheckTypes selectionType, ConditionContainer const* condList);

        bool operator()(WorldObject* target);
    };

    struct TC_GAME_API WorldObjectSpellAreaTargetCheck : public WorldObjectSpellTargetCheck
    {
        float _range;
        Position const* _position;
        WorldObjectSpellAreaTargetCheck(float range, Position const* position, WorldObject* caster,
            WorldObject* referer, SpellInfo const* spellInfo, SpellTargetCheckTypes selectionType, ConditionContainer const* condList);

        bool operator()(WorldObject* target) const;
    };

    struct TC_GAME_API WorldObjectSpellConeTargetCheck : public WorldObjectSpellAreaTargetCheck
    {
        float _coneAngle;
        WorldObjectSpellConeTargetCheck(float coneAngle, float range, WorldObject* caster,
            SpellInfo const* spellInfo, SpellTargetCheckTypes selectionType, ConditionContainer const* condList);

        bool operator()(WorldObject* target) const;
    };

    struct TC_GAME_API WorldObjectSpellTrajTargetCheck : public WorldObjectSpellTargetCheck
    {
        float _range;
        Position const* _position;
        WorldObjectSpellTrajTargetCheck(float range, Position const* position, WorldObject* caster,
            SpellInfo const* spellInfo, SpellTargetCheckTypes selectionType, ConditionContainer const* condList);

        bool operator()(WorldObject* target) const;
    };
}

using SpellEffectHandlerFn = void(Spell::*)();

#endif
