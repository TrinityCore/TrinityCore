/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef TRINITYCORE_CREATURE_H
#define TRINITYCORE_CREATURE_H

#include "Unit.h"
#include "Common.h"
#include "CreatureData.h"
#include "DatabaseEnvFwd.h"
#include "Duration.h"
#include "Loot.h"
#include "MapObject.h"

#include <list>

class CreatureAI;
class CreatureGroup;
class Group;
class Quest;
class Player;
class SpellInfo;
class WorldSession;
enum MovementGeneratorType : uint8;

struct VendorItemCount
{
    VendorItemCount(uint32 _item, uint32 _count)
        : itemId(_item), count(_count), lastIncrementTime(time(NULL)) { }

    uint32 itemId;
    uint32 count;
    time_t lastIncrementTime;
};

typedef std::list<VendorItemCount> VendorItemCounts;

// max different by z coordinate for creature aggro reaction
#define CREATURE_Z_ATTACK_RANGE 3

#define MAX_VENDOR_ITEMS 150                                // Limitation in 4.x.x item count in SMSG_LIST_INVENTORY

//used for handling non-repeatable random texts
typedef std::vector<uint8> CreatureTextRepeatIds;
typedef std::unordered_map<uint8, CreatureTextRepeatIds> CreatureTextRepeatGroup;

class TC_GAME_API Creature : public Unit, public GridObject<Creature>, public MapObject
{
    public:
        explicit Creature(bool isWorldObject = false);
        virtual ~Creature();

        void AddToWorld() override;
        void RemoveFromWorld() override;

        void SetObjectScale(float scale) override;
        void SetDisplayId(uint32 displayId, float displayScale = 1.f) override;
        void SetDisplayFromModel(uint32 modelIdx);

        void DisappearAndDie();

        bool Create(ObjectGuid::LowType guidlow, Map* map, uint32 entry, float x, float y, float z, float ang, CreatureData const* data, uint32 vehId);

        static Creature* CreateCreature(uint32 entry, Map* map, Position const& pos, uint32 vehId = 0);
        static Creature* CreateCreatureFromDB(ObjectGuid::LowType spawnId, Map* map, bool addToMap = true, bool allowDuplicate = false);

        bool LoadCreaturesAddon();
        void SelectLevel();
        void UpdateLevelDependantStats();
        void LoadEquipment(int8 id = 1, bool force = false);
        void SetSpawnHealth();

        ObjectGuid::LowType GetSpawnId() const { return m_spawnId; }

        void Update(uint32 time) override;                         // overwrited Unit::Update
        void GetRespawnPosition(float &x, float &y, float &z, float* ori = nullptr, float* dist =nullptr) const;

        void SetCorpseDelay(uint32 delay) { m_corpseDelay = delay; }
        uint32 GetCorpseDelay() const { return m_corpseDelay; }
        bool IsRacialLeader() const { return GetCreatureTemplate()->RacialLeader; }
        bool IsCivilian() const { return (GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_CIVILIAN) != 0; }
        bool IsTrigger() const { return (GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_TRIGGER) != 0; }
        bool IsGuard() const { return (GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_GUARD) != 0; }
        bool CanWalk() const { return (GetCreatureTemplate()->InhabitType & INHABIT_GROUND) != 0; }
        bool CanSwim() const override { return (GetCreatureTemplate()->InhabitType & INHABIT_WATER) != 0 || IsPet(); }
        bool CanFly()  const override { return (GetCreatureTemplate()->InhabitType & INHABIT_AIR) != 0; }

        void SetReactState(ReactStates st) { m_reactState = st; }
        ReactStates GetReactState() const { return m_reactState; }
        bool HasReactState(ReactStates state) const { return (m_reactState == state); }
        void InitializeReactState();

        /// @todo Rename these properly
        bool isCanInteractWithBattleMaster(Player* player, bool msg) const;
        bool CanResetTalents(Player* player) const;
        bool CanCreatureAttack(Unit const* victim, bool force = true) const;
        bool IsImmunedToSpell(SpellInfo const* spellInfo, Unit* caster) const override;
        bool IsImmunedToSpellEffect(SpellInfo const* spellInfo, uint32 index, Unit* caster) const override;
        bool isElite() const;
        bool isWorldBoss() const;

        bool IsDungeonBoss() const;

        bool HasScalableLevels() const;
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
        void AI_InitializeAndEnable();
        bool AIM_Initialize(CreatureAI* ai = nullptr);
        void Motion_Initialize();

        CreatureAI* AI() const { return reinterpret_cast<CreatureAI*>(i_AI); }

        SpellSchoolMask GetMeleeDamageSchoolMask() const override { return m_meleeDamageSchoolMask; }
        void SetMeleeDamageSchool(SpellSchools school) { m_meleeDamageSchoolMask = SpellSchoolMask(1 << school); }

        bool HasSpell(uint32 spellID) const override;

        bool UpdateEntry(uint32 entry, CreatureData const* data = nullptr, bool updateLevel = true);

        void UpdateMovementFlags();

        bool UpdateStats(Stats stat) override;
        bool UpdateAllStats() override;
        void UpdateArmor() override;
        void UpdateMaxHealth() override;
        void UpdateMaxPower(Powers power) override;
        uint32 GetPowerIndex(Powers power) const override;
        void UpdateAttackPowerAndDamage(bool ranged = false) override;
        void CalculateMinMaxDamage(WeaponAttackType attType, bool normalized, bool addTotalPct, float& minDamage, float& maxDamage) override;

        void SetCanDualWield(bool value) override;
        int8 GetOriginalEquipmentId() const { return m_originalEquipmentId; }
        uint8 GetCurrentEquipmentId() const { return m_equipmentId; }
        void SetCurrentEquipmentId(uint8 id) { m_equipmentId = id; }

        float GetSpellDamageMod(int32 Rank) const;

        VendorItemData const* GetVendorItems() const;
        uint32 GetVendorItemCurrentCount(VendorItem const* vItem);
        uint32 UpdateVendorItemCurrentCount(VendorItem const* vItem, uint32 used_count);

        CreatureTemplate const* GetCreatureTemplate() const { return m_creatureInfo; }
        CreatureData const* GetCreatureData() const { return m_creatureData; }
        CreatureAddon const* GetCreatureAddon() const;

        std::string GetAIName() const;
        std::string GetScriptName() const;
        uint32 GetScriptId() const;

        // override WorldObject function for proper name localization
        std::string const& GetNameForLocaleIdx(LocaleConstant locale_idx) const override;

        void setDeathState(DeathState s) override;                   // override virtual Unit::setDeathState

        bool LoadFromDB(ObjectGuid::LowType spawnId, Map* map) { return LoadCreatureFromDB(spawnId, map, false, false); }
    private:
        bool LoadCreatureFromDB(ObjectGuid::LowType spawnId, Map* map, bool addToMap, bool allowDuplicate);
    public:
        void SaveToDB();
                                                            // overriden in Pet
        virtual void SaveToDB(uint32 mapid, std::vector<Difficulty> const& spawnDifficulties);
        virtual void DeleteFromDB();                        // overriden in Pet

        Loot loot;
        void StartPickPocketRefillTimer();
        void ResetPickPocketRefillTimer() { _pickpocketLootRestore = 0; }
        bool CanGeneratePickPocketLoot() const { return _pickpocketLootRestore <= time(NULL); }
        void SetSkinner(ObjectGuid guid) { _skinner = guid; }
        ObjectGuid GetSkinner() const { return _skinner; } // Returns the player who skinned this creature
        Player* GetLootRecipient() const;
        Group* GetLootRecipientGroup() const;
        bool hasLootRecipient() const { return !m_lootRecipient.IsEmpty() || !m_lootRecipientGroup.IsEmpty(); }
        bool isTappedBy(Player const* player) const;                          // return true if the creature is tapped by the player or a member of his party.

        void SetLootRecipient (Unit* unit);
        void AllLootRemovedFromCorpse();

        uint16 GetLootMode() const { return m_LootMode; }
        bool HasLootMode(uint16 lootMode) { return (m_LootMode & lootMode) != 0; }
        void SetLootMode(uint16 lootMode) { m_LootMode = lootMode; }
        void AddLootMode(uint16 lootMode) { m_LootMode |= lootMode; }
        void RemoveLootMode(uint16 lootMode) { m_LootMode &= ~lootMode; }
        void ResetLootMode() { m_LootMode = LOOT_MODE_DEFAULT; }

        SpellInfo const* reachWithSpellAttack(Unit* victim);
        SpellInfo const* reachWithSpellCure(Unit* victim);

        uint32 m_spells[MAX_CREATURE_SPELLS];

        bool CanStartAttack(Unit const* u, bool force) const;
        float GetAttackDistance(Unit const* player) const;
        float GetAggroRange(Unit const* target) const;

        void SendAIReaction(AiReaction reactionType);

        Unit* SelectNearestTarget(float dist = 0, bool playerOnly = false) const;
        Unit* SelectNearestTargetInAttackDistance(float dist = 0) const;
        Player* SelectNearestPlayer(float distance = 0) const;
        Unit* SelectNearestHostileUnitInAggroRange(bool useLOS = false) const;

        void DoFleeToGetAssistance();
        void CallForHelp(float fRadius);
        void CallAssistance();
        void SetNoCallAssistance(bool val) { m_AlreadyCallAssistance = val; }
        void SetNoSearchAssistance(bool val) { m_AlreadySearchedAssistance = val; }
        bool HasSearchedAssistance() const { return m_AlreadySearchedAssistance; }
        bool CanAssistTo(const Unit* u, const Unit* enemy, bool checkfaction = true) const;
        bool _IsTargetAcceptable(const Unit* target) const;

        MovementGeneratorType GetDefaultMovementType() const { return m_defaultMovementType; }
        void SetDefaultMovementType(MovementGeneratorType mgt) { m_defaultMovementType = mgt; }

        void RemoveCorpse(bool setSpawnTime = true);

        void DespawnOrUnsummon(uint32 msTimeToDespawn = 0, Seconds const& forceRespawnTime = Seconds(0));
        void DespawnOrUnsummon(Milliseconds const& time, Seconds const& forceRespawnTime = Seconds(0)) { DespawnOrUnsummon(uint32(time.count()), forceRespawnTime); }

        time_t const& GetRespawnTime() const { return m_respawnTime; }
        time_t GetRespawnTimeEx() const;
        void SetRespawnTime(uint32 respawn) { m_respawnTime = respawn ? time(NULL) + respawn : 0; }
        void Respawn(bool force = false);
        void SaveRespawnTime() override;

        uint32 GetRespawnDelay() const { return m_respawnDelay; }
        void SetRespawnDelay(uint32 delay) { m_respawnDelay = delay; }

        float GetRespawnRadius() const { return m_respawnradius; }
        void SetRespawnRadius(float dist) { m_respawnradius = dist; }

        void DoImmediateBoundaryCheck() { m_boundaryCheckTime = 0; }
        uint32 GetCombatPulseDelay() const { return m_combatPulseDelay; }
        void SetCombatPulseDelay(uint32 delay) // (secs) interval at which the creature pulses the entire zone into combat (only works in dungeons)
        {
            m_combatPulseDelay = delay;
            if (m_combatPulseTime == 0 || m_combatPulseTime > delay)
                m_combatPulseTime = delay;
        }

        uint32 m_groupLootTimer;                            // (msecs)timer used for group loot
        ObjectGuid lootingGroupLowGUID;                     // used to find group which is looting corpse

        void SendZoneUnderAttackMessage(Player* attacker);

        void SetInCombatWithZone();

        bool hasQuest(uint32 quest_id) const override;
        bool hasInvolvedQuest(uint32 quest_id)  const override;

        bool isRegeneratingHealth() { return m_regenHealth; }
        void setRegeneratingHealth(bool regenHealth) { m_regenHealth = regenHealth; }
        virtual uint8 GetPetAutoSpellSize() const { return MAX_SPELL_CHARM; }
        virtual uint32 GetPetAutoSpellOnPos(uint8 pos) const;
        float GetPetChaseDistance() const;

        void SetCannotReachTarget(bool cannotReach) { if (cannotReach == m_cannotReachTarget) return; m_cannotReachTarget = cannotReach; m_cannotReachTimer = 0; }
        bool CanNotReachTarget() const { return m_cannotReachTarget; }

        void SetPosition(float x, float y, float z, float o);
        void SetPosition(const Position &pos) { SetPosition(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation()); }

        void SetHomePosition(float x, float y, float z, float o) { m_homePosition.Relocate(x, y, z, o); }
        void SetHomePosition(const Position &pos) { m_homePosition.Relocate(pos); }
        void GetHomePosition(float& x, float& y, float& z, float& ori) const { m_homePosition.GetPosition(x, y, z, ori); }
        Position const& GetHomePosition() const { return m_homePosition; }

        void SetTransportHomePosition(float x, float y, float z, float o) { m_transportHomePosition.Relocate(x, y, z, o); }
        void SetTransportHomePosition(const Position &pos) { m_transportHomePosition.Relocate(pos); }
        void GetTransportHomePosition(float& x, float& y, float& z, float& ori) const { m_transportHomePosition.GetPosition(x, y, z, ori); }
        Position const& GetTransportHomePosition() const { return m_transportHomePosition; }

        uint32 GetWaypointPath() const { return m_path_id; }
        void LoadPath(uint32 pathid) { m_path_id = pathid; }

        uint32 GetCurrentWaypointID() const { return m_waypointID; }
        void UpdateWaypointID(uint32 wpID) { m_waypointID = wpID; }

        void SearchFormation();
        CreatureGroup* GetFormation() { return m_formation; }
        void SetFormation(CreatureGroup* formation) { m_formation = formation; }

        Unit* SelectVictim();

        void SetDisableReputationGain(bool disable) { DisableReputationGain = disable; }
        bool IsReputationGainDisabled() const { return DisableReputationGain; }
        bool IsDamageEnoughForLootingAndReward() const { return (m_creatureInfo->flags_extra & CREATURE_FLAG_EXTRA_NO_PLAYER_DAMAGE_REQ) || (m_PlayerDamageReq == 0); }
        void LowerPlayerDamageReq(uint64 unDamage);
        void ResetPlayerDamageReq() { m_PlayerDamageReq = GetHealth() / 2; }
        uint64 m_PlayerDamageReq;

        uint32 GetOriginalEntry() const { return m_originalEntry; }
        void SetOriginalEntry(uint32 entry) { m_originalEntry = entry; }

        static float _GetDamageMod(int32 Rank);

        float m_SightDistance, m_CombatDistance;

        bool m_isTempWorldObject; //true when possessed

        // Handling caster facing during spellcast
        void SetTarget(ObjectGuid const& guid) override;
        void MustReacquireTarget() { m_shouldReacquireTarget = true; } // flags the Creature for forced (client displayed) target reacquisition in the next ::Update call
        void DoNotReacquireTarget() { m_shouldReacquireTarget = false; m_suppressedTarget = ObjectGuid::Empty; m_suppressedOrientation = 0.0f; }
        void FocusTarget(Spell const* focusSpell, WorldObject const* target);
        bool IsFocusing(Spell const* focusSpell = nullptr, bool withDelay = false);
        void ReleaseFocus(Spell const* focusSpell = nullptr, bool withDelay = true);

        CreatureTextRepeatIds GetTextRepeatGroup(uint8 textGroup);
        void SetTextRepeatId(uint8 textGroup, uint8 id);
        void ClearTextRepeatGroup(uint8 textGroup);

        bool CanGiveExperience() const;

    protected:
        bool CreateFromProto(ObjectGuid::LowType guidlow, uint32 entry, CreatureData const* data = nullptr, uint32 vehId = 0);
        bool InitEntry(uint32 entry, CreatureData const* data = nullptr);

        // vendor items
        VendorItemCounts m_vendorItemCounts;

        static float _GetHealthMod(int32 Rank);

        ObjectGuid m_lootRecipient;
        ObjectGuid m_lootRecipientGroup;
        ObjectGuid _skinner;

        /// Timers
        time_t _pickpocketLootRestore;
        time_t m_corpseRemoveTime;                          // (msecs)timer for death or corpse disappearance
        time_t m_respawnTime;                               // (secs) time of next respawn
        uint32 m_respawnDelay;                              // (secs) delay between corpse disappearance and respawning
        uint32 m_corpseDelay;                               // (secs) delay between death and corpse disappearance
        float m_respawnradius;
        uint32 m_boundaryCheckTime;                         // (msecs) remaining time for next evade boundary check
        uint32 m_combatPulseTime;                           // (msecs) remaining time for next zone-in-combat pulse
        uint32 m_combatPulseDelay;                          // (secs) how often the creature puts the entire zone in combat (only works in dungeons)

        ReactStates m_reactState;                           // for AI, not charmInfo
        void RegenerateMana();
        void RegenerateHealth();
        void Regenerate(Powers power);
        MovementGeneratorType m_defaultMovementType;
        ObjectGuid::LowType m_spawnId;                               ///< For new or temporary creatures is 0 for saved it is lowguid
        uint8 m_equipmentId;
        int8 m_originalEquipmentId; // can be -1

        bool m_AlreadyCallAssistance;
        bool m_AlreadySearchedAssistance;
        bool m_regenHealth;
        bool m_cannotReachTarget;
        uint32 m_cannotReachTimer;
        bool m_AI_locked;

        SpellSchoolMask m_meleeDamageSchoolMask;
        uint32 m_originalEntry;

        Position m_homePosition;
        Position m_transportHomePosition;

        bool DisableReputationGain;

        CreatureTemplate const* m_creatureInfo;                 // Can differ from sObjectMgr->GetCreatureTemplate(GetEntry()) in difficulty mode > 0
        CreatureData const* m_creatureData;

        uint16 m_LootMode;                                  // Bitmask (default: LOOT_MODE_DEFAULT) that determines what loot will be lootable

        bool IsInvisibleDueToDespawn() const override;
        bool CanAlwaysSee(WorldObject const* obj) const override;

    private:
        void ForcedDespawn(uint32 timeMSToDespawn = 0, Seconds const& forceRespawnTimer = Seconds(0));
        bool CheckNoGrayAggroConfig(uint32 playerLevel, uint32 creatureLevel) const; // No aggro from gray creatures

        //WaypointMovementGenerator vars
        uint32 m_waypointID;
        uint32 m_path_id;

        //Formation var
        CreatureGroup* m_formation;
        bool m_TriggerJustRespawned;

        /* Spell focus system */
        Spell const* m_focusSpell;   // Locks the target during spell cast for proper facing
        uint32 m_focusDelay;
        bool m_shouldReacquireTarget;
        ObjectGuid m_suppressedTarget; // Stores the creature's "real" target while casting
        float m_suppressedOrientation; // Stores the creature's "real" orientation while casting

        CreatureTextRepeatGroup m_textRepeat;
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
        ForcedDespawnDelayEvent(Creature& owner, Seconds const& respawnTimer) : BasicEvent(), m_owner(owner), m_respawnTimer(respawnTimer) { }
        bool Execute(uint64 e_time, uint32 p_time) override;

    private:
        Creature& m_owner;
        Seconds const m_respawnTimer;
};

#endif
