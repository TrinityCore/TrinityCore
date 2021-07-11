/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
 * Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
 * Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef MANGOSSERVER_CREATURE_H
#define MANGOSSERVER_CREATURE_H

#include "Common.h"
#include "SharedDefines.h"
#include "CreatureDefines.h"
#include "Unit.h"
#include "LootMgr.h"
#include "Util.h"

#include <vector>
#include <list>

class SpellEntry;
class CreatureAI;
class Group;
class Quest;
class Player;
class WorldSession;
class CreatureGroup;

struct GameEventCreatureData;

struct CreatureCreatePos
{
    // exactly coordinates used
    CreatureCreatePos(Map* map, float x, float y, float z, float o)
        : m_map(map), m_closeObject(nullptr), m_angle(0.0f), m_dist(0.0f) { m_pos.x = x; m_pos.y = y; m_pos.z = z; m_pos.o = o; }
    // if dist == 0.0f -> exactly object coordinates used, in other case close point to object (CONTACT_DIST can be used as minimal distances)
    CreatureCreatePos(WorldObject* closeObject, float ori, float dist = 0.0f, float angle = 0.0f)
        : m_map(closeObject->GetMap()),
        m_closeObject(closeObject), m_angle(angle), m_dist(dist) { m_pos.o = ori; }

    Map* GetMap() const { return m_map; }
    void SelectFinalPoint(Creature* cr);
    bool Relocate(Creature* cr) const;

    // read only after SelectFinalPoint
    Position m_pos;
private:
    Map* m_map;
    WorldObject* m_closeObject;
    float m_angle;
    float m_dist;
};

class ThreatListProcesser
{
public:
    ThreatListProcesser() {}
    virtual ~ThreatListProcesser() {}
    virtual bool Process(Unit* unit) = 0;
};

class Creature : public Unit
{
    CreatureAI *i_AI;

    public:

        explicit Creature(CreatureSubtype subtype = CREATURE_SUBTYPE_GENERIC);
        ~Creature() override;

        void AddToWorld() override;
        void RemoveFromWorld() override;

        bool Create(uint32 guidlow, CreatureCreatePos& cPos, CreatureInfo const* cinfo, uint32 firstCreatureId, CreatureData const* data = nullptr, GameEventCreatureData const* eventData = nullptr);
        void LoadDefaultAuras(uint32 const* auras, bool reload);
        void LoadCreatureAddon(bool reload = false);

        // CreatureGroups
        CreatureGroup* GetCreatureGroup() const { return m_creatureGroup; }
        void SetCreatureGroup(CreatureGroup* group) { m_creatureGroup = group; }
        void JoinCreatureGroup(Creature* leader, float dist, float angle, uint32 options);
        void LeaveCreatureGroup();
        uint32 GetSpawnFlags() const;

        // Fonctions utilisees par les links, et appelle CreatureAI.
        void OnEnterCombat(Unit* pAttacker, bool notInCombat = false) override;
        void OnLeaveCombat() override;
        void RemoveAurasAtReset();
        // En cas de modification "manuelle" des stats.
        void ResetStats();

        void SelectLevel(CreatureInfo const* cinfo, float percentHealth = 100.0f, float percentMana = 100.0f);
        void LoadEquipment(uint32 equip_entry, bool force=false);

        bool HasStaticDBSpawnData() const;                  // listed in `creature` table and have fixed in DB guid
        uint32 GetDBTableGUIDLow() const;

        char const* GetSubName() const { return GetCreatureInfo()->subname; }

        void Update(uint32 update_diff, uint32 time) override;  // overwrite Unit::Update

        virtual void RegenerateAll(uint32 update_diff, bool skipCombatCheck = false);
        void GetRespawnCoord(float &x, float &y, float &z, float* ori = nullptr, float* dist = nullptr) const;
        uint32 GetEquipmentId() const { return m_equipmentId; }

        void SaveHomePosition() { SetHomePosition(GetPositionX(), GetPositionY(), GetPositionZ(), GetOrientation()); }
        void SetHomePosition(float x, float y, float z, float o);
        void GetHomePosition(float &x, float &y, float &z, float &o);
        Position const& GetHomePosition() { return m_homePosition; }
        float GetHomePositionO() const { return m_homePosition.o; }
        void ResetHomePosition();

        void AddCreatureState(CreatureStateFlag f) { m_creatureStateFlags |= f; }
        bool HasCreatureState(CreatureStateFlag f) const { return m_creatureStateFlags & f; }
        void ClearCreatureState(CreatureStateFlag f) { m_creatureStateFlags &= ~f; }
        bool HasTypeFlag(CreatureTypeFlags flag) const { return GetCreatureInfo()->type_flags & flag; }
        bool HasExtraFlag(CreatureFlagsExtra flag) const { return GetCreatureInfo()->flags_extra & flag; }

        CreatureSubtype GetSubtype() const { return m_subtype; }
        bool IsPet() const { return m_subtype == CREATURE_SUBTYPE_PET; }
        bool IsTotem() const { return m_subtype == CREATURE_SUBTYPE_TOTEM; }
        Totem const* ToTotem() const { return IsTotem() ? reinterpret_cast<Totem const*>(this) : nullptr; }
        Totem* ToTotem() { return IsTotem() ? reinterpret_cast<Totem*>(this) : nullptr; }
        bool IsTemporarySummon() const { return m_subtype == CREATURE_SUBTYPE_TEMPORARY_SUMMON; }
        bool IsCorpse() const { return GetDeathState() ==  CORPSE; }
        bool IsDespawned() const { return GetDeathState() ==  DEAD; }
        void SetCorpseDelay(uint32 delay) { m_corpseDelay = delay; }
        bool IsRacialLeader() const { return GetCreatureInfo()->racial_leader; }
        bool IsCivilian() const { return GetCreatureInfo()->civilian; }
        bool IsTrigger() const { return HasExtraFlag(CREATURE_FLAG_EXTRA_INVISIBLE); }
        bool IsGuard() const { return HasExtraFlag(CREATURE_FLAG_EXTRA_GUARD); }

        // World of Warcraft Client Patch 1.10.0 (2006-03-28)
        // - Area effect spells and abilities will no longer consider totems as
        //   valid targets.
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_9_4
        bool IsImmuneToAoe() const { return IsTotem() || HasExtraFlag(CREATURE_FLAG_EXTRA_IMMUNE_AOE); }
#else
        bool IsImmuneToAoe() const { return HasExtraFlag(CREATURE_FLAG_EXTRA_IMMUNE_AOE); }
#endif

        bool CanWalk() const override { return GetCreatureInfo()->inhabit_type & INHABIT_GROUND; }
        bool CanSwim() const override { return IsPet() || GetCreatureInfo()->inhabit_type & INHABIT_WATER; }
        bool CanFly()  const override { return !IsPet() && GetCreatureInfo()->inhabit_type & INHABIT_AIR; }

        void SetReactState(ReactStates st) { m_reactState = st; }
        ReactStates GetReactState() const { return m_reactState; }
        bool HasReactState(ReactStates state) const { return (m_reactState == state); }
        void InitializeReactState()
        {
            if (IsTotem() || IsTrigger() || GetCreatureType() == CREATURE_TYPE_CRITTER)
                SetReactState(REACT_PASSIVE);
            else
                SetReactState(REACT_AGGRESSIVE);
        }

        bool IsTrainerOf(Player* player, bool msg) const;
        bool CanInteractWithBattleMaster(Player* player, bool msg) const;
        bool CanTrainAndResetTalentsOf(Player* pPlayer) const;

        bool IsOutOfThreatArea(Unit* pVictim) const;
        void FillGuidsListFromThreatList(std::vector<ObjectGuid>& guids, uint32 maxamount = 0);

        bool IsImmuneToSpell(SpellEntry const* spellInfo, bool castOnSelf) const override;
        bool IsImmuneToDamage(SpellSchoolMask meleeSchoolMask, SpellEntry const* spellInfo = nullptr) const override;
        bool IsImmuneToSpellEffect(SpellEntry const* spellInfo, SpellEffectIndex index, bool castOnSelf) const override;

        bool IsElite() const
        {
            if (IsPet())
                return false;

            uint32 rank = GetCreatureInfo()->rank;
            return rank != CREATURE_ELITE_NORMAL && rank != CREATURE_ELITE_RARE;
        }

        bool IsWorldBoss() const
        {
            if (IsPet())
                return false;

            return GetCreatureInfo()->rank == CREATURE_ELITE_WORLDBOSS;
        }

        bool IsInEvadeMode() const;

        bool AIM_Initialize();
        void SetAI(CreatureAI * ai) { i_AI = ai; }

        CreatureAI* AI() { return i_AI; }
        CreatureAI const* AI() const { return i_AI; }
        void SetAInitializeOnRespawn(bool initialize)
        {
            if (initialize)
                AddCreatureState(CSTATE_INIT_AI_ON_RESPAWN);
            else
                ClearCreatureState(CSTATE_INIT_AI_ON_RESPAWN);
        }

        uint32 GetShieldBlockValue() const override
        {
            return GetLevel() / 2 + uint32(GetStat(STAT_STRENGTH) / 20); // dunno mob block value
        }

        SpellSchoolMask GetMeleeDamageSchoolMask() const override { return m_meleeDamageSchoolMask; }
        void SetMeleeDamageSchool(SpellSchools school) { m_meleeDamageSchoolMask = GetSchoolMask(school); }

        bool HasSpell(uint32 spellId) const override;

        bool UpdateEntry(uint32 entry, CreatureData const* data = nullptr, GameEventCreatureData const* eventData = nullptr, bool preserveHPAndPower = true);

        void ApplyGameEventSpells(GameEventCreatureData const* eventData, bool activated);
        bool UpdateStats(Stats stat) override;
        bool UpdateAllStats() override;
        void UpdateResistances(uint32 school) override;
        void UpdateArmor() override;
        void UpdateMaxHealth() override;
        void UpdateMaxPower(Powers power) override;
        void UpdateManaRegen() override;
        void UpdateAttackPowerAndDamage(bool ranged = false) override;
        void UpdateDamagePhysical(WeaponAttackType attType) override;
        uint32 GetCurrentEquipmentId() const { return m_equipmentId; }

        static float _GetHealthMod(int32 rank);             ///< Get custom factor to scale health (default 1, CONFIG_FLOAT_RATE_CREATURE_*_HP)
        static float _GetDamageMod(int32 rank);             ///< Get custom factor to scale damage (default 1, CONFIG_FLOAT_RATE_*_DAMAGE)
        static float _GetSpellDamageMod(int32 rank);        ///< Get custom factor to scale spell damage (default 1, CONFIG_FLOAT_RATE_*_SPELLDAMAGE)

        VendorItemData const* GetVendorItems() const;
        VendorItemData const* GetVendorTemplateItems() const;
        uint32 GetVendorItemCurrentCount(VendorItem const* vItem);
        uint32 UpdateVendorItemCurrentCount(VendorItem const* vItem, uint32 used_count);

        TrainerSpellData const* GetTrainerTemplateSpells() const;
        TrainerSpellData const* GetTrainerSpells() const;

        CreatureInfo const* GetCreatureInfo() const { return m_creatureInfo; }
        CreatureDataAddon const* GetCreatureAddon() const;
        CreatureData const* GetCreatureData() const;

        static uint32 ChooseDisplayId(CreatureInfo const* cinfo, CreatureData const* data = nullptr, CreatureDataAddon const* addon = nullptr, GameEventCreatureData const* eventData = nullptr, float* scale = nullptr);
        static float GetScaleForDisplayId(uint32 displayId);

        std::string GetAIName() const;
        std::string GetScriptName() const;
        uint32 GetScriptId() const;

        // overwrite WorldObject function for proper name localization
        char const* GetNameForLocaleIdx(int32 locale_idx) const override;

        void SetDeathState(DeathState s) override;                   // overwrite virtual Unit::SetDeathState
        bool FallGround();

        bool LoadFromDB(uint32 guid, Map* map);
        void SaveToDB();
                                                            // overwrited in Pet
        virtual void SaveToDB(uint32 mapid);
        virtual void DeleteFromDB();                        // overwrited in Pet
        static void DeleteFromDB(uint32 lowguid, CreatureData const* data);

        Loot loot;
        bool lootForPickPocketed;
        bool lootForBody;
        bool lootForSkin;
        uint32 skinningForOthersTimer; // If == 0, then everyone can skin
        bool lootForCreator = false;

        ObjectGuid GetLootRecipientGuid() const { return m_lootRecipientGuid; }
        uint32 GetLootGroupRecipientId() const { return m_lootGroupRecipientId; }
        Player* GetLootRecipient() const;                   // use group cases as prefered
        Group* GetGroupLootRecipient() const;
        bool HasLootRecipient() const { return m_lootGroupRecipientId || m_lootRecipientGuid; }
        bool IsGroupLootRecipient() const { return m_lootGroupRecipientId; }
        void SetLootRecipient(Unit* unit);
        void AllLootRemovedFromCorpse();
        Player* GetOriginalLootRecipient() const;           // ignore group changes/etc, not for looting
        bool IsTappedBy(Player const* player) const;
        bool IsSkinnableBy(Player const* player) const { return !skinningForOthersTimer || IsTappedBy(player); }

        uint32 m_spells[CREATURE_MAX_SPELLS];

        float GetAttackDistance(Unit const* pl) const;
        float GetDetectionRange() const { return m_detectionDistance; }

        void SendAIReaction(AiReaction reactionType);

        void DoFlee();
        void DoFleeToGetAssistance();
        float GetFleeingSpeed() const;
        void MoveAwayFromTarget(Unit* pTarget, float distance);
        void CallForHelp(float fRadius);
        void CallAssistance();
        void SetNoCallAssistance(bool val)
        { 
            if (val)
                AddCreatureState(CSTATE_ALREADY_CALL_ASSIST);
            else
                ClearCreatureState(CSTATE_ALREADY_CALL_ASSIST);
        }
        void SetNoSearchAssistance(bool val)
        {
            if (val)
                AddCreatureState(CSTATE_ALREADY_SEARCH_ASSIST);
            else
                ClearCreatureState(CSTATE_ALREADY_SEARCH_ASSIST);
        }
        bool HasSearchedAssistance() const { return HasCreatureState(CSTATE_ALREADY_SEARCH_ASSIST); }
        bool CanAssistTo(Unit const* u, Unit const* enemy, bool checkfaction = true) const;
        bool CanInitiateAttack();
        bool CanHaveTarget() const { return !HasExtraFlag(CREATURE_FLAG_EXTRA_NO_TARGET); }

        uint32 GetDefaultMount() { return m_mountId; }
        void SetDefaultMount(uint32 id) { m_mountId = id; }
        
        void SetTauntImmunity(bool immune);

        MovementGeneratorType GetDefaultMovementType() const { return m_defaultMovementType; }
        void SetDefaultMovementType(MovementGeneratorType mgt) { m_defaultMovementType = mgt; }
        void PauseOutOfCombatMovement(uint32 pauseTime = NPC_MOVEMENT_PAUSE_TIME);

        bool IsVisibleInGridForPlayer(Player const* pl) const override;

        void RemoveCorpse();
        bool IsDeadByDefault() const;

        void ForcedDespawn(uint32 timeMSToDespawn = 0);
        void DespawnOrUnsummon(uint32 msTimeToDespawn = 0);

        time_t const& GetRespawnTime() const { return m_respawnTime; }
        time_t GetRespawnTimeEx() const;
        void SetRespawnTime(uint32 respawn) { m_respawnTime = respawn ? time(nullptr) + respawn : 0; }
        void Respawn();
        void SaveRespawnTime() override;
        void ApplyDynamicRespawnDelay(uint32& delay, CreatureData const* data);

        uint32 GetRespawnDelay() const { return m_respawnDelay; }
        void SetRespawnDelay(uint32 delay) { m_respawnDelay = delay; }

        float GetWanderDistance() const { return m_wanderDistance; }
        void SetWanderDistance(float dist) { m_wanderDistance = dist; }

        // Functions spawn/remove creature with DB guid in all loaded map copies (if point grid loaded in map)
        static void AddToRemoveListInMaps(uint32 db_guid, CreatureData const* data);
        static void SpawnInMaps(uint32 db_guid, CreatureData const* data);

        void StartGroupLoot(Group* group, uint32 timer);

        void SendZoneUnderAttackMessage(Player* attacker);

        void SetInCombatWithZone(bool initialPulse = true);
        bool canStartAttack(Unit const* who, bool force) const;
        bool _IsTargetAcceptable(Unit const* target) const;
        bool canCreatureAttack(Unit const* pVictim, bool force) const;

        // Smartlog
        time_t GetCombatTime(bool total) const;
        void ResetCombatTime(bool combat = false);
        void UpdateCombatState(bool combat)
        {
            if (combat)
                AddCreatureState(CSTATE_COMBAT);
            else
                ClearCreatureState(CSTATE_COMBAT);
        }
        // For raid bosses that set the entire raid in combat
        void UpdateCombatWithZoneState(bool combat)
        {
            if (combat)
                AddCreatureState(CSTATE_COMBAT_WITH_ZONE);
            else
                ClearCreatureState(CSTATE_COMBAT_WITH_ZONE);
        }
        void LogDeath(Unit* pKiller) const;
        void LogLongCombat() const;
        void LogScriptInfo(std::ostringstream &data) const;
        // Smartlog end

        Unit* SelectAttackingTarget(AttackingTarget target, uint32 position, uint32 spellId, uint32 selectFlags = SELECT_FLAG_NO_TOTEM) const;
        Unit* SelectAttackingTarget(AttackingTarget target, uint32 position, SpellEntry const* pSpellInfo = nullptr, uint32 selectFlags = SELECT_FLAG_NO_TOTEM) const;

        // AI helpers
        Unit* SelectNearestHostileUnitInAggroRange(bool useLOS, bool ignoreCivilians = false) const;
        Unit* SelectNearestTargetInAttackDistance(float dist) const;
        Creature* FindNearestFriendlyGuard(float range) const;
        void CallNearestGuard(Unit* pEnemy) const;

        // Used by Creature Spells system to always know result of cast
        SpellCastResult TryToCast(Unit* pTarget, uint32 uiSpell, uint32 uiCastFlags, uint8 uiChance);
        SpellCastResult TryToCast(Unit* pTarget, SpellEntry const* pSpellInfo, uint32 uiCastFlags, uint8 uiChance);

        // Unit on which the creature is currently casting a spell. Used to make mobs face their cast target.
        // Client makes creatures always face unit sent in UNIT_FIELD_TARGET, orientation doesn't matter.
        // We send this guid instead when its set, to avoid overwriting the unit field.
        void SetCastingTarget(Unit const* pTarget)
        {
            if (pTarget != GetVictim())
            {
                m_castingTargetGuid = pTarget->GetGUID();
                ForceValuesUpdateAtIndex(UNIT_FIELD_TARGET);
                ForceValuesUpdateAtIndex(UNIT_FIELD_TARGET + 1);
            }
        }
        void ClearCastingTarget()
        {
            if (m_castingTargetGuid)
            {
                m_castingTargetGuid = 0;
                ForceValuesUpdateAtIndex(UNIT_FIELD_TARGET);
                ForceValuesUpdateAtIndex(UNIT_FIELD_TARGET + 1);
            }
        }
        uint64 m_castingTargetGuid;

        // - Victim selection (from aggro list)
        Unit* GetNearestVictimInRange(float min, float max);
        Unit* GetFarthestVictimInRange(float min, float max);
        Unit* GetVictimInRange(float min, float max);
        Unit* GetHostileCasterInRange(float min, float max);
        Unit* GetHostileCaster();

        // - Generic Selection
        void ProcessThreatList(ThreatListProcesser* f);

        // Spell Launch :
        // Return true if target found. 
        bool CastSpellOnFarthestVictim (uint32 spellId, float min = 0.0f, float max = 100.0f, bool triggered = false);
        bool CastSpellOnNearestVictim(uint32 spellId, float min = 0.0f, float max = 100.0f, bool triggered = false);
        bool CastSpellOnHostileCasterInRange(uint32 spellId, float min = 0.0f, float max = 100.0f, bool triggered = false);
        // Set in combat with units on the threatlist of 'pOther'
        void AddThreatsOf(Creature const* pOther);

        bool HasQuest(uint32 quest_id) const override;
        bool HasInvolvedQuest(uint32 quest_id)  const override;

        void SetDefaultGossipMenuId(uint32 menuId) { m_gossipMenuId = menuId; }
        uint32 GetDefaultGossipMenuId() const override { return m_gossipMenuId; }

        GridReference<Creature>& GetGridRef() { return m_gridRef; }
        bool IsRegeneratingHealth() const { return HasCreatureState(CSTATE_REGEN_HEALTH); }
        bool IsRegeneratingMana() const { return HasCreatureState(CSTATE_REGEN_MANA); }
        virtual uint8 GetPetAutoSpellSize() const { return CREATURE_MAX_SPELLS; }
        virtual uint32 GetPetAutoSpellOnPos(uint8 pos) const
        {
            if (pos >= CREATURE_MAX_SPELLS || m_charmInfo->GetCharmSpell(pos)->GetType() != ACT_ENABLED)
                return 0;
            return m_charmInfo->GetCharmSpell(pos)->GetAction();
        }

        void SetCombatStartPosition(float x, float y, float z) { m_combatStartX = x; m_combatStartY = y; m_combatStartZ = z; }
        void GetCombatStartPosition(float &x, float &y, float &z) const
        { x = m_combatStartX; y = m_combatStartY; z = m_combatStartZ; }

        void SetSummonPoint(CreatureCreatePos const& pos) { m_summonPos = pos.m_pos; }
        void GetSummonPoint(float &fX, float &fY, float &fZ, float &fOrient) const { fX = m_summonPos.x; fY = m_summonPos.y; fZ = m_summonPos.z; fOrient = m_summonPos.o; }

        void SetNoXP() { AddUnitState(UNIT_STAT_NO_KILL_REWARD); }

        void SetFactionTemporary(uint32 factionId, uint32 tempFactionFlags = TEMPFACTION_ALL);
        void ClearTemporaryFaction();
        uint32 GetTemporaryFactionFlags() const { return m_temporaryFactionFlags; }
        int32 GetReputationId() const { return m_reputationId; }

        void SendAreaSpiritHealerQueryOpcode(Player* pl);

        void DisappearAndDie();

        // Auto evade timer (if target not reachable)
        // Tested on retail 5.4.0: Creatures evade after 3 seconds (but does not return to home position)
        bool IsEvadeBecauseTargetNotReachable() const { return m_TargetNotReachableTimer > 3000; }
        uint32 m_TargetNotReachableTimer;

        std::shared_ptr<time_t> const& GetLastLeashExtensionTimePtr() const;
        void SetLastLeashExtensionTimePtr(std::shared_ptr<time_t> const& timer);
        void ClearLastLeashExtensionTimePtr();
        time_t GetLastLeashExtensionTime() const;
        void UpdateLeashExtensionTime();

        bool IsTempPacified() const         { return m_pacifiedTimer > 0; }
        void SetTempPacified(uint32 timer)  { if (m_pacifiedTimer < timer) m_pacifiedTimer = timer; }
        uint32 GetTempPacifiedTimer() const { return m_pacifiedTimer; }
        uint32 m_pacifiedTimer;
        uint32 m_manaRegen;

        void RegenerateHealth();
        void RegenerateMana();

        void SetVirtualItem(VirtualItemSlot slot, uint32 item_id);

        void ResetDamageTakenOrigin()
        {
            m_playerDamageTaken     = 0;
            m_nonPlayerDamageTaken   = 0;
        }

        void CountDamageTaken(uint32 damage, bool fromPlayerOrSelf)
        {
            if (fromPlayerOrSelf)
                m_playerDamageTaken += damage;
            else
                m_nonPlayerDamageTaken += damage;
        }

        bool IsLootAllowedDueToDamageOrigin() const
        {
            return 65 * m_playerDamageTaken > 35 * m_nonPlayerDamageTaken;
        }

        float GetXPModifierDueToDamageOrigin() const
        {
            // If players dealt less than 35% of the damage, no XP and no loot - or both=0
            if (!IsLootAllowedDueToDamageOrigin())
                return 0.0f;
            return float(m_playerDamageTaken) / (m_playerDamageTaken + m_nonPlayerDamageTaken);
        }

        bool HasWeapon() const;

        void SetCallForHelpDist(float dist)
        {
            m_callForHelpDist = dist;
        }

        void SetLeashDistance(float dist)
        {
            m_leashDistance = dist;
        }

        void SetDetectionDistance(float dist)
        {
            m_detectionDistance = dist;
        }

        // (msecs)timer used for group loot
        uint32 GetGroupLootTimer() { return m_groupLootTimer; }

        void SetEscortable(bool escortable)
        {
            if (escortable)
                AddCreatureState(CSTATE_ESCORTABLE);
            else
                ClearCreatureState(CSTATE_ESCORTABLE); 
        }
        bool IsEscortable() const { return HasCreatureState(CSTATE_ESCORTABLE); }
        bool CanAssistPlayers() { return HasExtraFlag(CREATURE_FLAG_EXTRA_CAN_ASSIST); }
        bool CanSummonGuards() { return HasExtraFlag(CREATURE_FLAG_EXTRA_SUMMON_GUARD); }
        uint32 GetOriginalEntry() const { return m_originalEntry; }

    protected:
        bool MeetsSelectAttackingRequirement(Unit* pTarget, SpellEntry const* pSpellInfo, uint32 selectFlags) const;

        bool CreateFromProto(uint32 guidlow, CreatureInfo const* cinfo, uint32 firstCreatureId, CreatureData const* data = nullptr, GameEventCreatureData const* eventData = nullptr);
        bool InitEntry(uint32 entry, CreatureData const* data = nullptr, CreatureDataAddon const* addon = nullptr, GameEventCreatureData const* eventData = nullptr);

        uint32 m_groupLootTimer;                            // (msecs)timer used for group loot
        uint32 m_groupLootId;                               // used to find group which is looting corpse
        void StopGroupLoot();

        // vendor items
        VendorItemCounts m_vendorItemCounts;

        uint32 m_lootMoney;
        ObjectGuid m_lootRecipientGuid;                     // player who will have rights for looting if m_lootGroupRecipient==0 or group disbanded
        uint32 m_lootGroupRecipientId;                      // group who will have rights for looting if set and exist

        /// Timers
        uint32 m_corpseDecayTimer;                          // (msecs)timer for death or corpse disappearance
        time_t m_respawnTime;                               // (secs) time of next respawn
        uint32 m_respawnDelay;                              // (secs) delay between corpse disappearance and respawning
        uint32 m_corpseDelay;                               // (secs) delay between death and corpse disappearance
        float m_wanderDistance;

        time_t m_combatStartTime;
        uint32 m_combatResetCount;

        CreatureSubtype m_subtype;                          // set in Creatures subclasses for fast it detect without dynamic_cast use
        MovementGeneratorType m_defaultMovementType;
        uint32 m_equipmentId;
        uint32 m_mountId;                                   // display Id to mount

        bool m_AI_locked;
        uint16 m_creatureStateFlags;
        uint32 m_temporaryFactionFlags;                     // used for real faction changes (not auras etc)
        int32 m_reputationId;                               // Id of the creature's faction in the client reputations list.
        uint32 m_gossipMenuId;

        SpellSchoolMask m_meleeDamageSchoolMask;
        uint32 m_originalEntry;

        CreatureGroup* m_creatureGroup;

        float m_combatStartX;
        float m_combatStartY;
        float m_combatStartZ;

        Position m_homePosition;

        ReactStates m_reactState;

        Position m_summonPos;

        // Shared timer between mobs who assist another.
        // Damaging one extends leash range on all of them.
        mutable std::shared_ptr<time_t> m_lastLeashExtensionTime;

        // Used to compute XP.
        uint32 m_playerDamageTaken;
        uint32 m_nonPlayerDamageTaken;
        
        float m_callForHelpDist;
        float m_leashDistance;
        float m_detectionDistance;

    private:
        GridReference<Creature> m_gridRef;
        CreatureInfo const* m_creatureInfo;
};

inline Creature* Object::ToCreature()
{
    return IsCreature() ? static_cast<Creature*>(this) : nullptr;
}

inline Creature const* Object::ToCreature() const
{
    return IsCreature() ? static_cast<Creature const*>(this) : nullptr;
}

inline Creature* ToCreature(Object* object)
{
    return object && object->IsCreature() ? static_cast<Creature*>(object) : nullptr;
}

inline Creature const* ToCreature(Object const* object)
{
    return object && object->IsCreature() ? static_cast<Creature const*>(object) : nullptr;
}

class AssistDelayEvent : public BasicEvent
{
    public:
        AssistDelayEvent(ObjectGuid victim, Unit& owner, std::list<Creature*> const& assistants);

        bool Execute(uint64 e_time, uint32 p_time) override;
    private:
        AssistDelayEvent();

        ObjectGuid              m_victimGuid;
        std::vector<ObjectGuid> m_assistantGuids;
        Unit&                   m_owner;
};

class ForcedDespawnDelayEvent : public BasicEvent
{
    public:
        explicit ForcedDespawnDelayEvent(Creature& owner) : BasicEvent(), m_owner(owner) { }
        bool Execute(uint64 e_time, uint32 p_time) override;

    private:
        Creature& m_owner;
};

class TargetedEmoteEvent : public BasicEvent
{
public:
    explicit TargetedEmoteEvent(Creature& owner, ObjectGuid const& targetGuid, uint32 emoteId) : BasicEvent(), m_owner(owner), m_targetGuid(targetGuid), m_emoteId(emoteId) { }
    bool Execute(uint64 e_time, uint32 p_time) override;

private:
    Creature& m_owner;
    ObjectGuid m_targetGuid;
    uint32 m_emoteId;
};

class TargetedEmoteCleanupEvent : public BasicEvent
{
public:
    explicit TargetedEmoteCleanupEvent(Creature& owner, float orientation) : BasicEvent(), m_owner(owner), m_orientation(orientation) { }
    bool Execute(uint64 e_time, uint32 p_time) override;

private:
    Creature& m_owner;
    float m_orientation;
};

#endif
