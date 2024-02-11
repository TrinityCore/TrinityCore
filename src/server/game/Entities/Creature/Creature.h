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

#ifndef TRINITYCORE_CREATURE_H
#define TRINITYCORE_CREATURE_H

#include "Unit.h"
#include "Common.h"
#include "CreatureData.h"
#include "DatabaseEnvFwd.h"
#include "Duration.h"
#include "GridObject.h"
#include "MapObject.h"
#include <list>

class CreatureAI;
class CreatureGroup;
class Quest;
class Player;
class SpellInfo;
class WorldSession;
struct Loot;

enum MovementGeneratorType : uint8;

struct VendorItemCount
{
    VendorItemCount(uint32 _item, uint32 _count);

    uint32 itemId;
    uint32 count;
    time_t lastIncrementTime;
};

typedef std::list<VendorItemCount> VendorItemCounts;

// max different by z coordinate for creature aggro reaction
#define CREATURE_Z_ATTACK_RANGE 3

#define MAX_VENDOR_ITEMS 150                                // Limitation in 4.x.x item count in SMSG_LIST_INVENTORY

enum class VendorInventoryReason : uint8
{
    None    = 0,
    Empty   = 1
};

static constexpr uint8 WILD_BATTLE_PET_DEFAULT_LEVEL = 1;
static constexpr size_t CREATURE_TAPPERS_SOFT_CAP = 5;

//used for handling non-repeatable random texts
typedef std::vector<uint8> CreatureTextRepeatIds;
typedef std::unordered_map<uint8, CreatureTextRepeatIds> CreatureTextRepeatGroup;

class TC_GAME_API Creature : public Unit, public GridObject<Creature>, public MapObject
{
    public:
        explicit Creature(bool isWorldObject = false);
        ~Creature();

        void AddToWorld() override;
        void RemoveFromWorld() override;

        float GetNativeObjectScale() const override;
        void SetObjectScale(float scale) override;
        void SetDisplayId(uint32 displayId, bool setNative = false) override;
        void SetDisplayFromModel(uint32 modelIdx);

        void DisappearAndDie() { ForcedDespawn(0); }

        bool Create(ObjectGuid::LowType guidlow, Map* map, uint32 entry, Position const& pos, CreatureData const* data, uint32 vehId, bool dynamic = false);

        static Creature* CreateCreature(uint32 entry, Map* map, Position const& pos, uint32 vehId = 0);
        static Creature* CreateCreatureFromDB(ObjectGuid::LowType spawnId, Map* map, bool addToMap = true, bool allowDuplicate = false);

        bool LoadCreaturesAddon();
        void LoadCreaturesSparringHealth();
        void SelectLevel();
        void UpdateLevelDependantStats();
        void SelectWildBattlePetLevel();
        void LoadEquipment(int8 id = 1, bool force = false);
        void SetSpawnHealth();
        void LoadTemplateRoot();
        bool IsTemplateRooted() const { return _staticFlags.HasFlag(CREATURE_STATIC_FLAG_SESSILE); }
        void SetTemplateRooted(bool rooted);

        ObjectGuid::LowType GetSpawnId() const { return m_spawnId; }

        void Update(uint32 time) override;                         // overwrited Unit::Update
        void GetRespawnPosition(float &x, float &y, float &z, float* ori = nullptr, float* dist = nullptr) const;
        bool IsSpawnedOnTransport() const { return m_creatureData && m_creatureData->mapId != GetMapId(); }

        void SetCorpseDelay(uint32 delay, bool ignoreCorpseDecayRatio = false)
        {
            m_corpseDelay = delay;
            if (ignoreCorpseDecayRatio)
                m_ignoreCorpseDecayRatio = true;
        }
        uint32 GetCorpseDelay() const { return m_corpseDelay; }
        bool IsRacialLeader() const { return GetCreatureTemplate()->RacialLeader; }
        bool IsCivilian() const { return (GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_CIVILIAN) != 0; }
        bool IsTrigger() const { return (GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_TRIGGER) != 0; }
        bool IsGuard() const { return (GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_GUARD) != 0; }

        void InitializeMovementFlags();
        void UpdateMovementFlags();

        CreatureMovementData const& GetMovementTemplate() const;
        bool CanWalk() const { return GetMovementTemplate().IsGroundAllowed(); }
        bool CanSwim() const override;
        bool CanEnterWater() const override;
        bool CanFly()  const override { return GetMovementTemplate().IsFlightAllowed() || IsFlying(); }
        bool CanHover() const { return GetMovementTemplate().Ground == CreatureGroundMovementType::Hover || IsHovering(); }

        MovementGeneratorType GetDefaultMovementType() const override { return m_defaultMovementType; }
        void SetDefaultMovementType(MovementGeneratorType mgt) { m_defaultMovementType = mgt; }

        CreatureClassifications GetCreatureClassification() const { return GetCreatureTemplate()->Classification; }
        bool HasClassification(CreatureClassifications classification) const { return GetCreatureTemplate()->Classification == classification; }

        bool IsDungeonBoss() const { return (GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_DUNGEON_BOSS) != 0; }
        bool IsAffectedByDiminishingReturns() const override { return Unit::IsAffectedByDiminishingReturns() || (GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_ALL_DIMINISH) != 0; }

        Unit* SelectVictim();

        void SetReactState(ReactStates st) { m_reactState = st; }
        ReactStates GetReactState() const { return m_reactState; }
        bool HasReactState(ReactStates state) const { return (m_reactState == state); }
        void InitializeReactState();

        using Unit::IsImmuneToAll;
        using Unit::SetImmuneToAll;
        void SetImmuneToAll(bool apply) override { Unit::SetImmuneToAll(apply, HasReactState(REACT_PASSIVE)); }
        using Unit::IsImmuneToPC;
        using Unit::SetImmuneToPC;
        void SetImmuneToPC(bool apply) override { Unit::SetImmuneToPC(apply, HasReactState(REACT_PASSIVE)); }
        using Unit::IsImmuneToNPC;
        using Unit::SetImmuneToNPC;
        void SetImmuneToNPC(bool apply) override { Unit::SetImmuneToNPC(apply, HasReactState(REACT_PASSIVE)); }

        void SetUnkillable(bool unkillable) { _staticFlags.ApplyFlag(CREATURE_STATIC_FLAG_UNKILLABLE, unkillable); }

        /// @todo Rename these properly
        bool isCanInteractWithBattleMaster(Player* player, bool msg) const;
        bool CanResetTalents(Player* player) const;
        bool CanCreatureAttack(Unit const* victim, bool force = true) const;
        void LoadTemplateImmunities(int32 creatureImmunitiesId);
        bool IsImmunedToSpellEffect(SpellInfo const* spellInfo, SpellEffectInfo const& spellEffectInfo, WorldObject const* caster, bool requireImmunityPurgesEffectAttribute = false) const override;
        bool IsElite() const;
        bool isWorldBoss() const;

        bool HasScalableLevels() const;
        void ApplyLevelScaling();
        uint8 GetLevelForTarget(WorldObject const* target) const override;

        uint64 GetMaxHealthByLevel(uint8 level) const;
        float GetHealthMultiplierForTarget(WorldObject const* target) const override;

        float GetBaseDamageForLevel(uint8 level) const;
        float GetDamageMultiplierForTarget(WorldObject const* target) const override;

        float GetBaseArmorForLevel(uint8 level) const;
        float GetArmorMultiplierForTarget(WorldObject const* target) const override;

        bool IsInEvadeMode() const { return HasUnitState(UNIT_STATE_EVADE); }
        bool IsEvadingAttacks() const { return IsInEvadeMode() || CanNotReachTarget(); }

        bool AIM_Destroy();
        bool AIM_Create(CreatureAI* ai = nullptr);
        bool AIM_Initialize(CreatureAI* ai = nullptr);
        void Motion_Initialize();

        CreatureAI* AI() const { return reinterpret_cast<CreatureAI*>(GetAI()); }

        SpellSchoolMask GetMeleeDamageSchoolMask(WeaponAttackType /*attackType*/ = BASE_ATTACK) const override { return m_meleeDamageSchoolMask; }
        void SetMeleeDamageSchool(SpellSchools school) { m_meleeDamageSchoolMask = SpellSchoolMask(1 << school); }
        bool CanMelee() const { return !_staticFlags.HasFlag(CREATURE_STATIC_FLAG_NO_MELEE); }
        void SetCanMelee(bool canMelee) { _staticFlags.ApplyFlag(CREATURE_STATIC_FLAG_NO_MELEE, !canMelee); }
        bool CanIgnoreLineOfSightWhenCastingOnMe() const { return _staticFlags.HasFlag(CREATURE_STATIC_FLAG_4_IGNORE_LOS_WHEN_CASTING_ON_ME); }

        bool HasSpell(uint32 spellID) const override;

        bool UpdateEntry(uint32 entry, CreatureData const* data = nullptr, bool updateLevel = true);

        int32 GetCreatePowerValue(Powers power) const override;
        bool UpdateStats(Stats stat) override;
        bool UpdateAllStats() override;
        void UpdateArmor() override;
        void UpdateMaxHealth() override;
        void UpdateMaxPower(Powers power) override;
        uint32 GetPowerIndex(Powers power) const override;
        void UpdateAttackPowerAndDamage(bool ranged = false) override;
        void CalculateMinMaxDamage(WeaponAttackType attType, bool normalized, bool addTotalPct, float& minDamage, float& maxDamage) const override;

        void SetCanDualWield(bool value) override;
        int8 GetOriginalEquipmentId() const { return m_originalEquipmentId; }
        uint8 GetCurrentEquipmentId() const { return m_equipmentId; }
        void SetCurrentEquipmentId(uint8 id) { m_equipmentId = id; }

        float GetSpellDamageMod(CreatureClassifications classification) const;

        VendorItemData const* GetVendorItems() const;
        uint32 GetVendorItemCurrentCount(VendorItem const* vItem);
        uint32 UpdateVendorItemCurrentCount(VendorItem const* vItem, uint32 used_count);

        CreatureTemplate const* GetCreatureTemplate() const { return m_creatureInfo; }
        CreatureData const* GetCreatureData() const { return m_creatureData; }
        CreatureDifficulty const* GetCreatureDifficulty() const { return m_creatureDifficulty; }
        CreatureAddon const* GetCreatureAddon() const;

        std::string const& GetAIName() const;
        std::string GetScriptName() const;
        uint32 GetScriptId() const;
        bool HasStringId(std::string_view id) const;
        void SetScriptStringId(std::string id);
        std::array<std::string_view, 3> const& GetStringIds() const { return m_stringIds; }

        // override WorldObject function for proper name localization
        std::string GetNameForLocaleIdx(LocaleConstant locale) const override;

        void setDeathState(DeathState s) override;                   // override virtual Unit::setDeathState

        bool LoadFromDB(ObjectGuid::LowType spawnId, Map* map, bool addToMap, bool allowDuplicate);
        void SaveToDB();
                                                            // overriden in Pet
        virtual void SaveToDB(uint32 mapid, std::vector<Difficulty> const& spawnDifficulties);
        static bool DeleteFromDB(ObjectGuid::LowType spawnId);

        bool CanHaveLoot() const { return !_staticFlags.HasFlag(CREATURE_STATIC_FLAG_NO_LOOT); }
        void SetCanHaveLoot(bool canHaveLoot) { _staticFlags.ApplyFlag(CREATURE_STATIC_FLAG_NO_LOOT, !canHaveLoot); }
        uint32 GetLootId() const;
        void SetLootId(Optional<uint32> lootId);
        std::unique_ptr<Loot> m_loot;
        std::unordered_map<ObjectGuid, std::unique_ptr<Loot>> m_personalLoot;
        void StartPickPocketRefillTimer();
        void ResetPickPocketRefillTimer() { _pickpocketLootRestore = 0; }
        bool CanGeneratePickPocketLoot() const;
        GuidUnorderedSet const& GetTapList() const { return m_tapList; }
        void SetTapList(GuidUnorderedSet tapList) { m_tapList = std::move(tapList); }
        bool hasLootRecipient() const { return !m_tapList.empty(); }
        bool IsTapListNotClearedOnEvade() const { return m_dontClearTapListOnEvade; }
        void SetDontClearTapListOnEvade(bool dontClear);
        bool isTappedBy(Player const* player) const;                          // return true if the creature is tapped by the player or a member of his party.
        Loot* GetLootForPlayer(Player const* player) const override;
        bool IsFullyLooted() const;
        bool IsSkinnedBy(Player const* player) const;

        void SetTappedBy(Unit const* unit, bool withGroup = true);
        void AllLootRemovedFromCorpse();

        uint16 GetLootMode() const { return m_LootMode; }
        bool HasLootMode(uint16 lootMode) const { return (m_LootMode & lootMode) != 0; }
        void SetLootMode(uint16 lootMode) { m_LootMode = lootMode; }
        void AddLootMode(uint16 lootMode) { m_LootMode |= lootMode; }
        void RemoveLootMode(uint16 lootMode) { m_LootMode &= ~lootMode; }
        void ResetLootMode() { m_LootMode = LOOT_MODE_DEFAULT; }

        uint32 m_spells[MAX_CREATURE_SPELLS];

        bool CanStartAttack(Unit const* u, bool force) const;
        float GetAttackDistance(Unit const* player) const;
        float GetAggroRange(Unit const* target) const;

        void SendAIReaction(AiReaction reactionType);

        Unit* SelectNearestTarget(float dist = 0, bool playerOnly = false) const;
        Unit* SelectNearestTargetInAttackDistance(float dist = 0) const;
        Unit* SelectNearestHostileUnitInAggroRange(bool useLOS = false, bool ignoreCivilians = false) const;

        void DoFleeToGetAssistance();
        void CallForHelp(float fRadius);
        void CallAssistance();
        void SetNoCallAssistance(bool val) { m_AlreadyCallAssistance = val; }
        void SetNoSearchAssistance(bool val) { m_AlreadySearchedAssistance = val; }
        bool HasSearchedAssistance() const { return m_AlreadySearchedAssistance; }
        bool CanAssistTo(Unit const* u, Unit const* enemy, bool checkfaction = true) const;
        bool _IsTargetAcceptable(Unit const* target) const;
        bool CanIgnoreFeignDeath() const { return (GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_IGNORE_FEIGN_DEATH) != 0; }

        void RemoveCorpse(bool setSpawnTime = true, bool destroyForNearbyPlayers = true);

        void DespawnOrUnsummon(Milliseconds timeToDespawn = 0s, Seconds forceRespawnTime = 0s);

        time_t const& GetRespawnTime() const { return m_respawnTime; }
        time_t GetRespawnTimeEx() const;
        void SetRespawnTime(uint32 respawn);
        void Respawn(bool force = false);
        void SaveRespawnTime(uint32 forceDelay = 0);

        uint32 GetRespawnDelay() const { return m_respawnDelay; }
        void SetRespawnDelay(uint32 delay) { m_respawnDelay = delay; }

        float GetWanderDistance() const { return m_wanderDistance; }
        void SetWanderDistance(float dist) { m_wanderDistance = dist; }

        void DoImmediateBoundaryCheck() { m_boundaryCheckTime = 0; }
        uint32 GetCombatPulseDelay() const { return m_combatPulseDelay; }
        void SetCombatPulseDelay(uint32 delay) // (secs) interval at which the creature pulses the entire zone into combat (only works in dungeons)
        {
            m_combatPulseDelay = delay;
            if (m_combatPulseTime == 0 || m_combatPulseTime > delay)
                m_combatPulseTime = delay;
        }

        void SendZoneUnderAttackMessage(Player* attacker);

        bool hasQuest(uint32 quest_id) const override;
        bool hasInvolvedQuest(uint32 quest_id)  const override;

        bool CanRegenerateHealth() const { return !_staticFlags.HasFlag(CREATURE_STATIC_FLAG_5_NO_HEALTH_REGEN) && _regenerateHealth; }
        void SetRegenerateHealth(bool value) { _staticFlags.ApplyFlag(CREATURE_STATIC_FLAG_5_NO_HEALTH_REGEN, !value); }
        virtual uint8 GetPetAutoSpellSize() const;
        virtual uint32 GetPetAutoSpellOnPos(uint8 pos) const;
        float GetPetChaseDistance() const;

        void SetCannotReachTarget(bool cannotReach);
        bool CanNotReachTarget() const { return m_cannotReachTarget; }

        void SetHomePosition(float x, float y, float z, float o) { m_homePosition.Relocate(x, y, z, o); }
        void SetHomePosition(Position const& pos) { m_homePosition.Relocate(pos); }
        void GetHomePosition(float& x, float& y, float& z, float& ori) const { m_homePosition.GetPosition(x, y, z, ori); }
        Position const& GetHomePosition() const { return m_homePosition; }

        void SetTransportHomePosition(float x, float y, float z, float o) { m_transportHomePosition.Relocate(x, y, z, o); }
        void SetTransportHomePosition(Position const& pos) { m_transportHomePosition.Relocate(pos); }
        void GetTransportHomePosition(float& x, float& y, float& z, float& ori) const { m_transportHomePosition.GetPosition(x, y, z, ori); }
        Position const& GetTransportHomePosition() const { return m_transportHomePosition; }

        uint32 GetWaypointPathId() const { return _waypointPathId; }
        void LoadPath(uint32 pathid) { _waypointPathId = pathid; }

        // nodeId, pathId
        std::pair<uint32, uint32> GetCurrentWaypointInfo() const { return _currentWaypointNodeInfo; }
        void UpdateCurrentWaypointInfo(uint32 nodeId, uint32 pathId) { _currentWaypointNodeInfo = { nodeId, pathId }; }

        bool IsReturningHome() const;

        void SearchFormation();
        CreatureGroup* GetFormation() { return m_formation; }
        void SetFormation(CreatureGroup* formation) { m_formation = formation; }
        bool IsFormationLeader() const;
        void SignalFormationMovement();
        bool IsFormationLeaderMoveAllowed() const;

        void SetDisableReputationGain(bool disable) { DisableReputationGain = disable; }
        bool IsReputationGainDisabled() const { return DisableReputationGain; }
        void LowerPlayerDamageReq(uint64 unDamage);
        void ResetPlayerDamageReq() { m_PlayerDamageReq = GetHealth() / 2; }
        uint64 m_PlayerDamageReq;

        uint32 GetOriginalEntry() const { return m_originalEntry; }
        void SetOriginalEntry(uint32 entry) { m_originalEntry = entry; }

        // There's many places not ready for dynamic spawns. This allows them to live on for now.
        void SetRespawnCompatibilityMode(bool mode = true) { m_respawnCompatibilityMode = mode; }
        bool GetRespawnCompatibilityMode() const { return m_respawnCompatibilityMode; }

        static float GetDamageMod(CreatureClassifications classification);

        float m_SightDistance, m_CombatDistance;

        bool m_isTempWorldObject; //true when possessed

        // Handling caster facing during spellcast
        void SetTarget(ObjectGuid const& guid) override;
        void DoNotReacquireSpellFocusTarget();
        void SetSpellFocus(Spell const* focusSpell, WorldObject const* target);
        bool HasSpellFocus(Spell const* focusSpell = nullptr) const override;
        void ReleaseSpellFocus(Spell const* focusSpell = nullptr, bool withDelay = true);

        bool IsMovementPreventedByCasting() const override;

        // Part of Evade mechanics
        time_t GetLastDamagedTime() const { return _lastDamagedTime; }
        void SetLastDamagedTime(time_t val) { _lastDamagedTime = val; }

        CreatureTextRepeatIds GetTextRepeatGroup(uint8 textGroup);
        void SetTextRepeatId(uint8 textGroup, uint8 id);
        void ClearTextRepeatGroup(uint8 textGroup);
        bool IsEscorted() const;

        bool CanGiveExperience() const;
        void SetCanGiveExperience(bool xpEnabled) { _staticFlags.ApplyFlag(CREATURE_STATIC_FLAG_NO_XP, !xpEnabled); }

        bool IsEngaged() const override;
        void AtEngage(Unit* target) override;
        void AtDisengage() override;

        void OverrideSparringHealthPct(std::vector<float> const& healthPct);
        float GetSparringHealthPct() const { return _sparringHealthPct; }
        uint32 CalculateDamageForSparring(Unit* attacker, uint32 damage);
        bool ShouldFakeDamageFrom(Unit* attacker);

        bool HasCanSwimFlagOutOfCombat() const
        {
            return !_isMissingCanSwimFlagOutOfCombat;
        }
        void RefreshCanSwimFlag(bool recheck = false);

        std::string GetDebugInfo() const override;

        void ExitVehicle(Position const* exitPosition = nullptr) override;

        bool HasFlag(CreatureStaticFlags flag) const { return _staticFlags.HasFlag(flag); }
        bool HasFlag(CreatureStaticFlags2 flag) const { return _staticFlags.HasFlag(flag); }
        bool HasFlag(CreatureStaticFlags3 flag) const { return _staticFlags.HasFlag(flag); }
        bool HasFlag(CreatureStaticFlags4 flag) const { return _staticFlags.HasFlag(flag); }
        bool HasFlag(CreatureStaticFlags5 flag) const { return _staticFlags.HasFlag(flag); }
        bool HasFlag(CreatureStaticFlags6 flag) const { return _staticFlags.HasFlag(flag); }
        bool HasFlag(CreatureStaticFlags7 flag) const { return _staticFlags.HasFlag(flag); }
        bool HasFlag(CreatureStaticFlags8 flag) const { return _staticFlags.HasFlag(flag); }

        uint32 GetGossipMenuId() const;
        void SetGossipMenuId(uint32 gossipMenuId);

        uint32 GetTrainerId() const;
        void SetTrainerId(Optional<uint32> trainerId);

        void SummonGraveyardTeleporter();

        void InitializeInteractSpellId();
        void SetInteractSpellId(int32 interactSpellId) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::InteractSpellID), interactSpellId); }

    protected:
        bool CreateFromProto(ObjectGuid::LowType guidlow, uint32 entry, CreatureData const* data = nullptr, uint32 vehId = 0);
        bool InitEntry(uint32 entry, CreatureData const* data = nullptr);

        // vendor items
        VendorItemCounts m_vendorItemCounts;

        static float GetHealthMod(CreatureClassifications classification);

        GuidUnorderedSet m_tapList;
        bool m_dontClearTapListOnEvade;

        /// Timers
        time_t _pickpocketLootRestore;
        time_t m_corpseRemoveTime;                          // (msecs)timer for death or corpse disappearance
        time_t m_respawnTime;                               // (secs) time of next respawn
        uint32 m_respawnDelay;                              // (secs) delay between corpse disappearance and respawning
        uint32 m_corpseDelay;                               // (secs) delay between death and corpse disappearance
        bool m_ignoreCorpseDecayRatio;
        float m_wanderDistance;
        uint32 m_boundaryCheckTime;                         // (msecs) remaining time for next evade boundary check
        uint32 m_combatPulseTime;                           // (msecs) remaining time for next zone-in-combat pulse
        uint32 m_combatPulseDelay;                          // (secs) how often the creature puts the entire zone in combat (only works in dungeons)

        ReactStates m_reactState;                           // for AI, not charmInfo
        void RegenerateHealth();
        void Regenerate(Powers power);
        MovementGeneratorType m_defaultMovementType;
        ObjectGuid::LowType m_spawnId;                               ///< For new or temporary creatures is 0 for saved it is lowguid
        uint8 m_equipmentId;
        int8 m_originalEquipmentId; // can be -1

        bool m_AlreadyCallAssistance;
        bool m_AlreadySearchedAssistance;
        bool m_cannotReachTarget;
        uint32 m_cannotReachTimer;

        SpellSchoolMask m_meleeDamageSchoolMask;
        uint32 m_originalEntry;

        Position m_homePosition;
        Position m_transportHomePosition;

        bool DisableReputationGain;

        CreatureTemplate const* m_creatureInfo;
        CreatureData const* m_creatureData;
        CreatureDifficulty const* m_creatureDifficulty;
        std::array<std::string_view, 3> m_stringIds;
        Optional<std::string> m_scriptStringId;

        Optional<uint32> m_lootId;
        uint16 m_LootMode;                                  // Bitmask (default: LOOT_MODE_DEFAULT) that determines what loot will be lootable

        bool IsInvisibleDueToDespawn(WorldObject const* seer) const override;
        bool CanAlwaysSee(WorldObject const* obj) const override;

    private:
        void ForcedDespawn(uint32 timeMSToDespawn = 0, Seconds forceRespawnTimer = 0s);
        bool CheckNoGrayAggroConfig(uint32 playerLevel, uint32 creatureLevel) const; // No aggro from gray creatures

        // Waypoint path
        uint32 _waypointPathId;
        std::pair<uint32/*nodeId*/, uint32/*pathId*/> _currentWaypointNodeInfo;

        // Formation var
        CreatureGroup* m_formation;
        bool m_triggerJustAppeared;
        bool m_respawnCompatibilityMode;

        /* Spell focus system */
        void ReacquireSpellFocusTarget();
        struct
        {
            ::Spell const* Spell = nullptr;
            uint32 Delay = 0;         // ms until the creature's target should snap back (0 = no snapback scheduled)
            ObjectGuid Target;        // the creature's "real" target while casting
            float Orientation = 0.0f; // the creature's "real" orientation while casting
        } _spellFocusInfo;

        time_t _lastDamagedTime; // Part of Evade mechanics
        CreatureTextRepeatGroup m_textRepeat;

        void ApplyAllStaticFlags(CreatureStaticFlagsHolder const& flags);

        CreatureStaticFlagsHolder _staticFlags;

        // Regenerate health
        bool _regenerateHealth; // Set on creation

        bool _isMissingCanSwimFlagOutOfCombat;

        int32 _creatureImmunitiesId;
        uint32 _gossipMenuId;
        Optional<uint32> _trainerId;
        float _sparringHealthPct;
};

class TC_GAME_API AssistDelayEvent : public BasicEvent
{
    public:
        AssistDelayEvent(ObjectGuid victim, Unit& owner) : BasicEvent(), m_victim(victim), m_owner(owner) { }

        bool Execute(uint64 e_time, uint32 p_time) override;
        void AddAssistant(ObjectGuid guid) { m_assistants.push_back(guid); }
    private:
        AssistDelayEvent();

        ObjectGuid        m_victim;
        GuidList          m_assistants;
        Unit&             m_owner;
};

class TC_GAME_API ForcedDespawnDelayEvent : public BasicEvent
{
    public:
        ForcedDespawnDelayEvent(Creature& owner, Seconds respawnTimer) : BasicEvent(), m_owner(owner), m_respawnTimer(respawnTimer) { }
        bool Execute(uint64 e_time, uint32 p_time) override;

    private:
        Creature& m_owner;
        Seconds const m_respawnTimer;
};

#endif
