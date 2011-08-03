/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "GridDefines.h"
#include "SharedDefines.h"
#include "ObjectMgr.h"
#include "SpellInfo.h"

class Unit;
class Player;
class GameObject;
class DynamicObject;
class WorldObject;
class Aura;
class SpellScript;
class ByteBuffer;

#define SPELL_CHANNEL_UPDATE_INTERVAL (1 * IN_MILLISECONDS)

enum SpellCastTargetFlags
{
    TARGET_FLAG_SELF            = 0x00000000,
    TARGET_FLAG_UNUSED_1        = 0x00000001,               // not used
    TARGET_FLAG_UNIT            = 0x00000002,               // pguid
    TARGET_FLAG_UNIT_RAID       = 0x00000004,               // not sent, used to validate target (if raid member)
    TARGET_FLAG_UNIT_PARTY      = 0x00000008,               // not sent, used to validate target (if party member)
    TARGET_FLAG_ITEM            = 0x00000010,               // pguid
    TARGET_FLAG_SOURCE_LOCATION = 0x00000020,               // pguid, 3 float
    TARGET_FLAG_DEST_LOCATION   = 0x00000040,               // pguid, 3 float
    TARGET_FLAG_UNIT_ENEMY      = 0x00000080,               // not sent, used to validate target (if enemy)
    TARGET_FLAG_UNIT_ALLY       = 0x00000100,               // not sent, used to validate target (if ally)
    TARGET_FLAG_CORPSE_ENEMY    = 0x00000200,               // pguid
    TARGET_FLAG_UNIT_DEAD       = 0x00000400,               // not sent, used to validate target (if dead creature)
    TARGET_FLAG_GAMEOBJECT      = 0x00000800,               // pguid, used with TARGET_GAMEOBJECT
    TARGET_FLAG_TRADE_ITEM      = 0x00001000,               // pguid
    TARGET_FLAG_STRING          = 0x00002000,               // string
    TARGET_FLAG_GAMEOBJECT_ITEM = 0x00004000,               // not sent, used with TARGET_GAMEOBJECT_ITEM
    TARGET_FLAG_CORPSE_ALLY     = 0x00008000,               // pguid
    TARGET_FLAG_UNIT_MINIPET    = 0x00010000,               // pguid, used to validate target (if non combat pet)
    TARGET_FLAG_GLYPH_SLOT      = 0x00020000,               // used in glyph spells
    TARGET_FLAG_UNK19           = 0x00040000,               // sometimes appears with DEST_TARGET spells (may appear or not for a given spell)
    TARGET_FLAG_UNUSED20        = 0x00080000,               // uint32 counter, loop { vec3 - screen position (?), guid }, not used so far
    TARGET_FLAG_UNIT_PASSENGER  = 0x00100000,               // guessed, used to validate target (if vehicle passenger)
};
#define MAX_TARGET_FLAGS 21

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
    CAST_FLAG_UNKNOWN_18         = 0x00020000,
    CAST_FLAG_UNKNOWN_19         = 0x00040000,
    CAST_FLAG_UNKNOWN_20         = 0x00080000,
    CAST_FLAG_UNKNOWN_21         = 0x00100000,
    CAST_FLAG_RUNE_LIST          = 0x00200000,
    CAST_FLAG_UNKNOWN_23         = 0x00400000,
    CAST_FLAG_UNKNOWN_24         = 0x00800000,
    CAST_FLAG_UNKNOWN_25         = 0x01000000,
    CAST_FLAG_UNKNOWN_26         = 0x02000000,
    CAST_FLAG_UNKNOWN_27         = 0x04000000,
    CAST_FLAG_UNKNOWN_28         = 0x08000000,
    CAST_FLAG_UNKNOWN_29         = 0x10000000,
    CAST_FLAG_UNKNOWN_30         = 0x20000000,
    CAST_FLAG_UNKNOWN_31         = 0x40000000,
    CAST_FLAG_UNKNOWN_32         = 0x80000000,
};

enum SpellRangeFlag
{
    SPELL_RANGE_DEFAULT             = 0,
    SPELL_RANGE_MELEE               = 1,     //melee
    SPELL_RANGE_RANGED              = 2,     //hunter range and ranged weapon
};

enum SpellNotifyPushType
{
    PUSH_NONE           = 0,
    PUSH_IN_FRONT,
    PUSH_IN_BACK,
    PUSH_IN_LINE,
    PUSH_IN_THIN_LINE,
    PUSH_SRC_CENTER,
    PUSH_DST_CENTER,
    PUSH_CASTER_CENTER, //this is never used in grid search
    PUSH_CHAIN,
};

class SpellCastTargets
{
    public:
        SpellCastTargets();
        ~SpellCastTargets();

        SpellCastTargets& operator=(const SpellCastTargets &target);

        void Read(ByteBuffer& data, Unit* caster);
        void Write(ByteBuffer& data);

        uint32 GetTargetMask() const { return m_targetMask; }
        void SetTargetMask(uint32 newMask) { m_targetMask = newMask; }

        uint64 GetUnitTargetGUID() const { return m_unitTargetGUID; }
        Unit* GetUnitTarget() const { return m_unitTarget; }
        void SetUnitTarget(Unit* target);

        Position const* GetSrc() const;
        void SetSrc(float x, float y, float z);
        void SetSrc(Position const& pos);
        void SetSrc(WorldObject const& wObj);
        void ModSrc(Position const& pos);

        WorldLocation const* GetDst() const;
        void SetDst(float x, float y, float z, float orientation, uint32 mapId = MAPID_INVALID);
        void SetDst(Position const& pos);
        void SetDst(WorldObject const& wObj);
        void SetDst(SpellCastTargets const& spellTargets);
        void ModDst(Position const& pos);

        uint64 GetGOTargetGUID() const { return m_GOTargetGUID; }
        GameObject* GetGOTarget() const { return m_GOTarget; }
        void SetGOTarget(GameObject* target);

        uint64 GetCorpseTargetGUID() const { return m_CorpseTargetGUID; }
        void SetCorpseTarget(Corpse* corpse);

        uint64 GetItemTargetGUID() const { return m_itemTargetGUID; }
        Item* GetItemTarget() const { return m_itemTarget; }
        uint32 GetItemTargetEntry() const { return m_itemTargetEntry; }
        void SetItemTarget(Item* item);
        void SetTradeItemTarget(Player* caster);
        void UpdateTradeSlotItem();

        bool IsEmpty() const { return m_GOTargetGUID == 0 && m_unitTargetGUID == 0 && m_itemTarget == 0 && m_CorpseTargetGUID == 0; }
        bool HasSrc() const { return GetTargetMask() & TARGET_FLAG_SOURCE_LOCATION; }
        bool HasDst() const { return GetTargetMask() & TARGET_FLAG_DEST_LOCATION; }
        bool HasTraj() const { return m_speed != 0; }

        float GetElevation() const { return m_elevation; }
        void SetElevation(float elevation) { m_elevation = elevation; }
        float GetSpeed() const { return m_speed; }
        void SetSpeed(float speed) { m_speed = speed; }

        float GetDist2d() const { return m_srcPos.GetExactDist2d(&m_dstPos); }
        float GetSpeedXY() const { return m_speed * cos(m_elevation); }
        float GetSpeedZ() const { return m_speed * sin(m_elevation); }

        void Update(Unit* caster);
        void OutDebug() const;

    private:
        uint32 m_targetMask;

        // objects (can be used at spell creating and after Update at casting
        Unit* m_unitTarget;
        GameObject* m_GOTarget;
        Item* m_itemTarget;

        // object GUID/etc, can be used always
        uint64 m_unitTargetGUID;
        uint64 m_GOTargetGUID;
        uint64 m_CorpseTargetGUID;
        uint64 m_itemTargetGUID;
        uint32 m_itemTargetEntry;

        uint64 m_srcTransGUID;
        Position m_srcTransOffset;
        Position m_srcPos;

        uint64 m_dstTransGUID;
        Position m_dstTransOffset;
        WorldLocation m_dstPos;

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

enum SpellTargets
{
    SPELL_TARGETS_NONE      = 0,
    SPELL_TARGETS_ALLY,
    SPELL_TARGETS_ENEMY,
    SPELL_TARGETS_ENTRY,
    SPELL_TARGETS_CHAINHEAL,
    SPELL_TARGETS_ANY,
    SPELL_TARGETS_GO
};

namespace Trinity
{
    struct SpellNotifierCreatureAndPlayer;
}

class Spell
{
    friend struct Trinity::SpellNotifierCreatureAndPlayer;
    friend void Unit::SetCurrentCastedSpell(Spell* pSpell);
    friend class SpellScript;
    public:

        void EffectNULL(SpellEffIndex effIndex);
        void EffectUnused(SpellEffIndex effIndex);
        void EffectDistract(SpellEffIndex effIndex);
        void EffectPull(SpellEffIndex effIndex);
        void EffectSchoolDMG(SpellEffIndex effIndex);
        void EffectEnvirinmentalDMG(SpellEffIndex effIndex);
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
        void EffectAddHonor(SpellEffIndex effIndex);
        void EffectTradeSkill(SpellEffIndex effIndex);
        void EffectEnchantItemPerm(SpellEffIndex effIndex);
        void EffectEnchantItemTmp(SpellEffIndex effIndex);
        void EffectTameCreature(SpellEffIndex effIndex);
        void EffectSummonPet(SpellEffIndex effIndex);
        void EffectLearnPetSpell(SpellEffIndex effIndex);
        void EffectWeaponDmg(SpellEffIndex effIndex);
        void EffectForceCast(SpellEffIndex effIndex);
        void EffectForceCastWithValue(SpellEffIndex effIndex);
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
        void EffectSummonCritter(SpellEffIndex effIndex);
        void EffectKnockBack(SpellEffIndex effIndex);
        void EffectPullTowards(SpellEffIndex effIndex);
        void EffectDispelMechanic(SpellEffIndex effIndex);
        void EffectSummonDeadPet(SpellEffIndex effIndex);
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
        void EffectTriggerSpellWithValue(SpellEffIndex effIndex);
        void EffectTriggerRitualOfSummoning(SpellEffIndex effIndex);
        void EffectSummonRaFFriend(SpellEffIndex effIndex);
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
        void EffectSpecCount(SpellEffIndex effIndex);
        void EffectActivateSpec(SpellEffIndex effIndex);
        void EffectPlayerNotification(SpellEffIndex effIndex);
        void EffectRemoveAura(SpellEffIndex effIndex);
        void EffectCastButtons(SpellEffIndex effIndex);
        void EffectRechargeManaGem(SpellEffIndex effIndex);

        typedef std::set<Aura*> UsedSpellMods;

        Spell(Unit* caster, SpellInfo const *info, TriggerCastFlags triggerFlags, uint64 originalCasterGUID = 0, bool skipCheck = false);
        ~Spell();

        void prepare(SpellCastTargets const* targets, AuraEffect const* triggeredByAura = NULL);
        void cancel();
        void update(uint32 difftime);
        void cast(bool skipCheck = false);
        void finish(bool ok = true);
        void TakePower();
        void TakeAmmo();

        void TakeRunePower(bool didHit);
        void TakeReagents();
        void TakeCastItem();

        SpellCastResult CheckCast(bool strict);
        SpellCastResult CheckPetCast(Unit* target);

        // handlers
        void handle_immediate();
        uint64 handle_delayed(uint64 t_offset);
        // handler helpers
        void _handle_immediate_phase();
        void _handle_finish_phase();

        SpellCastResult CheckItems();
        SpellCastResult CheckRange(bool strict);
        SpellCastResult CheckPower();
        SpellCastResult CheckRuneCost(uint32 runeCostID);
        SpellCastResult CheckCasterAuras() const;

        int32 CalculateDamage(uint8 i, Unit* target) { return m_caster->CalculateSpellDamage(target, m_spellInfo, i, &m_spellValue->EffectBasePoints[i]); }

        bool HaveTargetsForEffect(uint8 effect) const;
        void Delayed();
        void DelayedChannel();
        uint32 getState() const { return m_spellState; }
        void setState(uint32 state) { m_spellState = state; }

        void DoCreateItem(uint32 i, uint32 itemtype);
        void WriteSpellGoTargets(WorldPacket * data);
        void WriteAmmoToPacket(WorldPacket * data);

        void SelectSpellTargets();
        void SelectEffectTargets(uint32 i, SpellImplicitTargetInfo const& cur);
        void SelectTrajTargets();

        template<typename T> WorldObject* FindCorpseUsing();

        bool CheckTarget(Unit* target, uint32 eff);
        bool CanAutoCast(Unit* target);
        void CheckSrc() { if (!m_targets.HasSrc()) m_targets.SetSrc(*m_caster); }
        void CheckDst() { if (!m_targets.HasDst()) m_targets.SetDst(*m_caster); }

        static void SendCastResult(Player* caster, SpellInfo const* spellInfo, uint8 cast_count, SpellCastResult result, SpellCustomErrors customError = SPELL_CUSTOM_ERROR_NONE);
        void SendCastResult(SpellCastResult result);
        void SendSpellStart();
        void SendSpellGo();
        void SendSpellCooldown();
        void SendLogExecute();
        void ExecuteLogEffectTakeTargetPower(uint8 effIndex, Unit* target, uint32 powerType, uint32 powerTaken, float gainMultiplier);
        void ExecuteLogEffectExtraAttacks(uint8 effIndex, Unit* victim, uint32 attCount);
        void ExecuteLogEffectInterruptCast(uint8 effIndex, Unit* victim, uint32 spellId);
        void ExecuteLogEffectDurabilityDamage(uint8 effIndex, Unit* victim, uint32 itemslot, uint32 damage);
        void ExecuteLogEffectOpenLock(uint8 effIndex, Object * obj);
        void ExecuteLogEffectCreateItem(uint8 effIndex, uint32 entry);
        void ExecuteLogEffectDestroyItem(uint8 effIndex, uint32 entry);
        void ExecuteLogEffectSummonObject(uint8 effIndex, WorldObject * obj);
        void ExecuteLogEffectUnsummonObject(uint8 effIndex, WorldObject * obj);
        void ExecuteLogEffectResurrect(uint8 effIndex, Unit* target);
        void SendInterrupted(uint8 result);
        void SendChannelUpdate(uint32 time);
        void SendChannelStart(uint32 duration);
        void SendResurrectRequest(Player* target);

        void HandleEffects(Unit *pUnitTarget, Item *pItemTarget, GameObject *pGOTarget, uint32 i);
        void HandleThreatSpells();

        SpellInfo const* const m_spellInfo;
        Item* m_CastItem;
        uint64 m_castItemGUID;
        uint8 m_cast_count;
        uint32 m_glyphIndex;
        uint32 m_preCastSpell;
        SpellCastTargets m_targets;
        int8 m_comboPointGain;
        SpellCustomErrors m_customError;

        UsedSpellMods m_appliedMods;

        int32 CalcCastTime() const { return m_casttime; }
        bool IsAutoRepeat() const { return m_autoRepeat; }
        void SetAutoRepeat(bool rep) { m_autoRepeat = rep; }
        void ReSetTimer() { m_timer = m_casttime > 0 ? m_casttime : 0; }
        bool IsNextMeleeSwingSpell() const;
        bool IsTriggered() const {return _triggeredCastFlags & TRIGGERED_FULL_MASK;};
        bool IsChannelActive() const { return m_caster->GetUInt32Value(UNIT_CHANNEL_SPELL) != 0; }
        bool IsAutoActionResetSpell() const;

        bool IsDeletable() const { return !m_referencedFromCurrentSpell && !m_executedCurrently; }
        void SetReferencedFromCurrent(bool yes) { m_referencedFromCurrentSpell = yes; }
        bool IsInterruptable() const { return !m_executedCurrently; }
        void SetExecutedCurrently(bool yes) {m_executedCurrently = yes;}
        uint64 GetDelayStart() const { return m_delayStart; }
        void SetDelayStart(uint64 m_time) { m_delayStart = m_time; }
        uint64 GetDelayMoment() const { return m_delayMoment; }

        bool IsNeedSendToClient() const;

        CurrentSpellTypes GetCurrentContainer();

        Unit* GetCaster() const { return m_caster; }
        Unit* GetOriginalCaster() const { return m_originalCaster; }
        SpellInfo const* GetSpellInfo() const { return m_spellInfo; }
        int32 GetPowerCost() const { return m_powerCost; }

        void UpdatePointers();                              // must be used at call Spell code after time delay (non triggered spell cast/update spell call/etc)

        bool CheckTargetCreatureType(Unit* target) const;

        void CleanupTargetList();

        void SetSpellValue(SpellValueMod mod, int32 value);
    protected:
        bool HasGlobalCooldown();
        void TriggerGlobalCooldown();
        void CancelGlobalCooldown();

        void SendLoot(uint64 guid, LootType loottype);

        Unit* const m_caster;

        SpellValue * const m_spellValue;

        uint64 m_originalCasterGUID;                        // real source of cast (aura caster/etc), used for spell targets selection
                                                            // e.g. damage around area spell trigered by victim aura and damage enemies of aura caster
        Unit* m_originalCaster;                             // cached pointer for m_originalCaster, updated at Spell::UpdatePointers()

        Spell** m_selfContainer;                            // pointer to our spell container (if applicable)

        //Spell data
        SpellSchoolMask m_spellSchoolMask;                  // Spell school (can be overwrite for some spells (wand shoot for example)
        WeaponAttackType m_attackType;                      // For weapon based attack
        int32 m_powerCost;                                  // Calculated spell cost initialized only in Spell::prepare
        int32 m_casttime;                                   // Calculated spell cast time initialized only in Spell::prepare
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
        uint8 m_applyMultiplierMask;
        float m_damageMultipliers[3];

        // Current targets, to be used in SpellEffects (MUST BE USED ONLY IN SPELL EFFECTS)
        Unit* unitTarget;
        Item* itemTarget;
        GameObject* gameObjTarget;
        int32 damage;
        // used in effects handlers
        Aura * m_spellAura;

        // this is set in Spell Hit, but used in Apply Aura handler
        DiminishingLevels m_diminishLevel;
        DiminishingGroup m_diminishGroup;

        // -------------------------------------------
        GameObject* focusObject;

        // Damage and healing in effects need just calculate
        int32 m_damage;           // Damge   in effects count here
        int32 m_healing;          // Healing in effects count here

        // ******************************************
        // Spell trigger system
        // ******************************************
        uint32 m_procAttacker;                // Attacker trigger flags
        uint32 m_procVictim;                  // Victim   trigger flags
        uint32 m_procEx;
        void   prepareDataForTriggerSystem(AuraEffect const* triggeredByAura);

        // *****************************************
        // Spell target subsystem
        // *****************************************
        // Targets store structures and data
        struct TargetInfo
        {
            uint64 targetGUID;
            uint64 timeDelay;
            SpellMissInfo missCondition:8;
            SpellMissInfo reflectResult:8;
            uint8  effectMask:8;
            bool   processed:1;
            bool   alive:1;
            bool   crit:1;
            bool   scaleAura:1;
            int32  damage;
        };
        std::list<TargetInfo> m_UniqueTargetInfo;
        uint8 m_channelTargetEffectMask;                        // Mask req. alive targets

        struct GOTargetInfo
        {
            uint64 targetGUID;
            uint64 timeDelay;
            uint8  effectMask:8;
            bool   processed:1;
        };
        std::list<GOTargetInfo> m_UniqueGOTargetInfo;

        struct ItemTargetInfo
        {
            Item  *item;
            uint8 effectMask;
        };
        std::list<ItemTargetInfo> m_UniqueItemInfo;

        void AddUnitTarget(Unit* target, uint32 effIndex);
        void AddUnitTarget(uint64 unitGUID, uint32 effIndex);
        void AddGOTarget(GameObject* target, uint32 effIndex);
        void AddGOTarget(uint64 goGUID, uint32 effIndex);
        void AddItemTarget(Item* target, uint32 effIndex);
        void DoAllEffectOnTarget(TargetInfo *target);
        SpellMissInfo DoSpellHitOnUnit(Unit *unit, uint32 effectMask, bool scaleAura);
        void DoTriggersOnSpellHit(Unit *unit, uint8 effMask);
        void DoAllEffectOnTarget(GOTargetInfo *target);
        void DoAllEffectOnTarget(ItemTargetInfo *target);
        bool UpdateChanneledTargetList();
        void SearchAreaTarget(std::list<Unit*> &unitList, float radius, SpellNotifyPushType type, SpellTargets TargetType, uint32 entry = 0);
        void SearchGOAreaTarget(std::list<GameObject*> &gobjectList, float radius, SpellNotifyPushType type, SpellTargets TargetType, uint32 entry = 0);
        void SearchChainTarget(std::list<Unit*> &unitList, float radius, uint32 unMaxTargets, SpellTargets TargetType);
        WorldObject* SearchNearbyTarget(float range, SpellTargets TargetType, SpellEffIndex effIndex);
        bool IsValidSingleTargetEffect(Unit const* target, Targets type) const;
        bool IsValidSingleTargetSpell(Unit const* target) const;
        bool IsValidDeadOrAliveTarget(Unit const* target) const;
        void CalculateDamageDoneForAllTargets();
        int32 CalculateDamageDone(Unit *unit, const uint32 effectMask, float *multiplier);
        void SpellDamageSchoolDmg(SpellEffIndex effIndex);
        void SpellDamageWeaponDmg(SpellEffIndex effIndex);
        void SpellDamageHeal(SpellEffIndex effIndex);

        void PrepareTargetProcessing();
        void FinishTargetProcessing();

        // spell execution log
        void InitEffectExecuteData(uint8 effIndex);
        void CleanupEffectExecuteData();
        void CheckEffectExecuteData();

        // Scripting system
        void LoadScripts();
        SpellCastResult CallScriptCheckCastHandlers();
        void PrepareScriptHitHandlers();
        bool CallScriptEffectHandlers(SpellEffIndex effIndex);
        void CallScriptBeforeHitHandlers();
        void CallScriptOnHitHandlers();
        void CallScriptAfterHitHandlers();
        void CallScriptAfterUnitTargetSelectHandlers(std::list<Unit*>& unitTargets, SpellEffIndex effIndex);
        std::list<SpellScript *> m_loadedScripts;

        bool CanExecuteTriggersOnHit(uint8 effMask) const;
        void PrepareTriggersExecutedOnHit();
        typedef std::list< std::pair<SpellInfo const*, int32> > HitTriggerSpells;
        HitTriggerSpells m_hitTriggerSpells;

        // effect helpers
        void GetSummonPosition(uint32 i, Position &pos, float radius = 0.0f, uint32 count = 0);
        void SummonGuardian(uint32 i, uint32 entry, SummonPropertiesEntry const *properties);
        void CalculateJumpSpeeds(uint8 i, float dist, float & speedxy, float & speedz);

        SpellCastResult CanOpenLock(uint32 effIndex, uint32 lockid, SkillType& skillid, int32& reqSkillValue, int32& skillValue);
        // -------------------------------------------

        uint32 m_spellState;
        uint32 m_timer;

        TriggerCastFlags _triggeredCastFlags;

        // if need this can be replaced by Aura copy
        // we can't store original aura link to prevent access to deleted auras
        // and in same time need aura data and after aura deleting.
        SpellInfo const* m_triggeredByAuraSpell;

        bool m_skipCheck;
        uint32 m_effectMask;
        uint8 m_auraScaleMask;

        ByteBuffer * m_effectExecuteData[MAX_SPELL_EFFECTS];

#ifdef MAP_BASED_RAND_GEN
        int32 irand(int32 min, int32 max)       { return int32 (m_caster->GetMap()->mtRand.randInt(max - min)) + min; }
        uint32 urand(uint32 min, uint32 max)    { return m_caster->GetMap()->mtRand.randInt(max - min) + min; }
        int32 rand32()                          { return m_caster->GetMap()->mtRand.randInt(); }
        double rand_norm()                      { return m_caster->GetMap()->mtRand.randExc(); }
        double rand_chance()                    { return m_caster->GetMap()->mtRand.randExc(100.0); }
#endif
};

namespace Trinity
{
    struct SpellNotifierCreatureAndPlayer
    {
        std::list<Unit*> *i_data;
        SpellNotifyPushType i_push_type;
        float i_radius;
        SpellTargets i_TargetType;
        const Unit* const i_source;
        uint32 i_entry;
        const Position * const i_pos;
        bool i_requireDeadTarget;
        SpellInfo const* i_spellProto;

        SpellNotifierCreatureAndPlayer(Unit *source, std::list<Unit*> &data, float radius, SpellNotifyPushType type,
            SpellTargets TargetType = SPELL_TARGETS_ENEMY, const Position *pos = NULL, uint32 entry = 0, SpellInfo const* spellProto = NULL)
            : i_data(&data), i_push_type(type), i_radius(radius), i_TargetType(TargetType),
            i_source(source), i_entry(entry), i_pos(pos), i_spellProto(spellProto)
        {
            ASSERT(i_source);
        }

        template<class T> inline void Visit(GridRefManager<T>& m)
        {
            i_requireDeadTarget = i_spellProto ? bool(i_spellProto->AttributesEx3 & SPELL_ATTR3_REQUIRE_DEAD_TARGET) : false;

            for (typename GridRefManager<T>::iterator itr = m.begin(); itr != m.end(); ++itr)
            {
                Unit* target = (Unit*)itr->getSource();

                if (!i_source->canSeeOrDetect(target, true))
                    continue;

                switch (i_TargetType)
                {
                    case SPELL_TARGETS_ENEMY:
                        if (target->isTotem())
                            continue;
                        if (!target->isAttackableByAOE(i_spellProto))
                            continue;
                        if (i_source->IsControlledByPlayer())
                        {
                            if (i_source->IsFriendlyTo(target))
                                continue;
                        }
                        else
                        {
                            if (!i_source->IsHostileTo(target))
                                continue;
                        }
                        break;
                    case SPELL_TARGETS_ALLY:
                        if (target->isTotem())
                            continue;
                        if (!i_source->IsFriendlyTo(target))
                            continue;
                        if (target->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE))
                            continue;
                        if (target->GetTypeId() == TYPEID_PLAYER && target->ToPlayer()->isGameMaster())
                            continue;
                        if (target->isAlive() == i_requireDeadTarget)
                            continue;
                        break;
                    case SPELL_TARGETS_ENTRY:
                        if (target->GetEntry()!= i_entry)
                            continue;
                        break;
                    case SPELL_TARGETS_ANY:
                    default:
                        break;
                }

                switch(i_push_type)
                {
                    case PUSH_SRC_CENTER:
                    case PUSH_DST_CENTER:
                    case PUSH_CHAIN:
                    default:
                        if (target->IsWithinDist3d(i_pos, i_radius))
                            i_data->push_back(target);
                        break;
                    case PUSH_IN_FRONT:
                        if (i_source->isInFront(target, i_radius, static_cast<float>(M_PI/2)))
                            i_data->push_back(target);
                        break;
                    case PUSH_IN_BACK:
                        if (i_source->isInBack(target, i_radius, static_cast<float>(M_PI/2)))
                            i_data->push_back(target);
                        break;
                    case PUSH_IN_LINE:
                        if (i_source->HasInLine(target, i_radius, i_source->GetObjectSize()))
                            i_data->push_back(target);
                        break;
                    case PUSH_IN_THIN_LINE: // only traj
                        if (i_pos->HasInLine(target, i_radius, 0))
                            i_data->push_back(target);
                        break;
                }
            }
        }

        #ifdef _WIN32
        template<> inline void Visit(CorpseMapType &) {}
        template<> inline void Visit(GameObjectMapType &) {}
        template<> inline void Visit(DynamicObjectMapType &) {}
        #endif
    };

    #ifndef _WIN32
    template<> inline void SpellNotifierCreatureAndPlayer::Visit(CorpseMapType&) {}
    template<> inline void SpellNotifierCreatureAndPlayer::Visit(GameObjectMapType&) {}
    template<> inline void SpellNotifierCreatureAndPlayer::Visit(DynamicObjectMapType&) {}
    #endif
}

typedef void(Spell::*pEffect)(SpellEffIndex effIndex);

class SpellEvent : public BasicEvent
{
    public:
        SpellEvent(Spell* spell);
        virtual ~SpellEvent();

        virtual bool Execute(uint64 e_time, uint32 p_time);
        virtual void Abort(uint64 e_time);
        virtual bool IsDeletable() const;
    protected:
        Spell* m_Spell;
};
#endif
