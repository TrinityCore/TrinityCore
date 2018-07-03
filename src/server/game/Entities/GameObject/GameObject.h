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

#ifndef TRINITYCORE_GAMEOBJECT_H
#define TRINITYCORE_GAMEOBJECT_H

#include "Object.h"
#include "DatabaseEnvFwd.h"
#include "GameObjectData.h"
#include "Loot.h"
#include "MapObject.h"
#include "SharedDefines.h"

class GameObjectAI;
class GameObjectModel;
class Group;
class OPvPCapturePoint;
class Transport;
class Unit;
struct TransportAnimation;
enum TriggerCastFlags : uint32;

union GameObjectValue
{
    //11 GAMEOBJECT_TYPE_TRANSPORT
    struct
    {
        uint32 PathProgress;
        TransportAnimation const* AnimationInfo;
        uint32 CurrentSeg;
        std::vector<uint32>* StopFrames;
        uint32 StateUpdateTimer;
    } Transport;
    //25 GAMEOBJECT_TYPE_FISHINGHOLE
    struct
    {
        uint32 MaxOpens;
    } FishingHole;
    //29 GAMEOBJECT_TYPE_CONTROL_ZONE
    struct
    {
        OPvPCapturePoint *OPvPObj;
    } ControlZone;
    //33 GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING
    struct
    {
        uint32 Health;
        uint32 MaxHealth;
    } Building;
};

// For containers:  [GO_NOT_READY]->GO_READY (close)->GO_ACTIVATED (open) ->GO_JUST_DEACTIVATED->GO_READY        -> ...
// For bobber:      GO_NOT_READY  ->GO_READY (close)->GO_ACTIVATED (open) ->GO_JUST_DEACTIVATED-><deleted>
// For door(closed):[GO_NOT_READY]->GO_READY (close)->GO_ACTIVATED (open) ->GO_JUST_DEACTIVATED->GO_READY(close) -> ...
// For door(open):  [GO_NOT_READY]->GO_READY (open) ->GO_ACTIVATED (close)->GO_JUST_DEACTIVATED->GO_READY(open)  -> ...
enum LootState
{
    GO_NOT_READY = 0,
    GO_READY,                                               // can be ready but despawned, and then not possible activate until spawn
    GO_ACTIVATED,
    GO_JUST_DEACTIVATED
};

// 5 sec for bobber catch
#define FISHING_BOBBER_READY_TIME 5

class TC_GAME_API GameObject : public WorldObject, public GridObject<GameObject>, public MapObject
{
    public:
        explicit GameObject();
        ~GameObject();

        void BuildValuesUpdate(uint8 updatetype, ByteBuffer* data, Player* target) const override;

        void AddToWorld() override;
        void RemoveFromWorld() override;
        void CleanupsBeforeDelete(bool finalCleanup = true) override;

    private:
        bool Create(uint32 entry, Map* map, Position const& pos, QuaternionData const& rotation, uint32 animProgress, GOState goState, uint32 artKit);
    public:
        static GameObject* CreateGameObject(uint32 entry, Map* map, Position const& pos, QuaternionData const& rotation, uint32 animProgress, GOState goState, uint32 artKit = 0);
        static GameObject* CreateGameObjectFromDB(ObjectGuid::LowType spawnId, Map* map, bool addToMap = true);

        void Update(uint32 p_time) override;
        GameObjectTemplate const* GetGOInfo() const { return m_goInfo; }
        GameObjectTemplateAddon const* GetTemplateAddon() const { return m_goTemplateAddon; }
        GameObjectData const* GetGOData() const { return m_goData; }
        GameObjectValue const* GetGOValue() const { return &m_goValue; }

        bool IsTransport() const;
        bool IsDynTransport() const;
        bool IsDestructibleBuilding() const;

        ObjectGuid::LowType GetSpawnId() const { return m_spawnId; }

         // z_rot, y_rot, x_rot - rotation angles around z, y and x axes
        void SetWorldRotationAngles(float z_rot, float y_rot, float x_rot);
        void SetWorldRotation(float qx, float qy, float qz, float qw);
        void SetParentRotation(QuaternionData const& rotation);      // transforms(rotates) transport's path
        int64 GetPackedWorldRotation() const { return m_packedRotation; }

        // overwrite WorldObject function for proper name localization
        std::string const& GetNameForLocaleIdx(LocaleConstant locale_idx) const override;

        void SaveToDB();
        void SaveToDB(uint32 mapid, uint64 spawnMask);
        bool LoadFromDB(ObjectGuid::LowType spawnId, Map* map) { return LoadGameObjectFromDB(spawnId, map, false); }
    private:
        bool LoadGameObjectFromDB(ObjectGuid::LowType spawnId, Map* map, bool addToMap);
    public:
        void DeleteFromDB();

        void SetOwnerGUID(ObjectGuid owner)
        {
            // Owner already found and different than expected owner - remove object from old owner
            if (!owner.IsEmpty() && !GetOwnerGUID().IsEmpty() && GetOwnerGUID() != owner)
            {
                ABORT();
            }
            m_spawnedByDefault = false;                     // all object with owner is despawned after delay
            SetGuidValue(GAMEOBJECT_FIELD_CREATED_BY, owner);
        }
        ObjectGuid GetOwnerGUID() const { return GetGuidValue(GAMEOBJECT_FIELD_CREATED_BY); }
        Unit* GetOwner() const;

        void SetSpellId(uint32 id)
        {
            m_spawnedByDefault = false;                     // all summoned object is despawned after delay
            m_spellId = id;
        }
        uint32 GetSpellId() const { return m_spellId;}

        time_t GetRespawnTime() const { return m_respawnTime; }
        time_t GetRespawnTimeEx() const
        {
            time_t now = time(NULL);
            if (m_respawnTime > now)
                return m_respawnTime;
            else
                return now;
        }

        void SetRespawnTime(int32 respawn)
        {
            m_respawnTime = respawn > 0 ? time(NULL) + respawn : 0;
            m_respawnDelayTime = respawn > 0 ? respawn : 0;
        }
        void Respawn();
        bool isSpawned() const
        {
            return m_respawnDelayTime == 0 ||
                (m_respawnTime > 0 && !m_spawnedByDefault) ||
                (m_respawnTime == 0 && m_spawnedByDefault);
        }
        bool isSpawnedByDefault() const { return m_spawnedByDefault; }
        void SetSpawnedByDefault(bool b) { m_spawnedByDefault = b; }
        uint32 GetRespawnDelay() const { return m_respawnDelayTime; }
        void Refresh();
        void Delete();
        void SendGameObjectDespawn();
        void getFishLoot(Loot* loot, Player* loot_owner);
        void getFishLootJunk(Loot* loot, Player* loot_owner);
        GameobjectTypes GetGoType() const { return GameobjectTypes(GetByteValue(GAMEOBJECT_BYTES_1, 1)); }
        void SetGoType(GameobjectTypes type) { SetByteValue(GAMEOBJECT_BYTES_1, 1, type); }
        GOState GetGoState() const { return GOState(GetByteValue(GAMEOBJECT_BYTES_1, 0)); }
        void SetGoState(GOState state);
        virtual uint32 GetTransportPeriod() const;
        void SetTransportState(GOState state, uint32 stopFrame = 0);
        uint8 GetGoArtKit() const { return GetByteValue(GAMEOBJECT_BYTES_1, 2); }
        void SetGoArtKit(uint8 artkit);
        uint8 GetGoAnimProgress() const { return GetByteValue(GAMEOBJECT_BYTES_1, 3); }
        void SetGoAnimProgress(uint8 animprogress) { SetByteValue(GAMEOBJECT_BYTES_1, 3, animprogress); }
        static void SetGoArtKit(uint8 artkit, GameObject* go, ObjectGuid::LowType lowguid = UI64LIT(0));

        void EnableCollision(bool enable);

        void Use(Unit* user);

        LootState getLootState() const { return m_lootState; }
        // Note: unit is only used when s = GO_ACTIVATED
        void SetLootState(LootState s, Unit* unit = NULL);

        uint16 GetLootMode() const { return m_LootMode; }
        bool HasLootMode(uint16 lootMode) const { return (m_LootMode & lootMode) != 0; }
        void SetLootMode(uint16 lootMode) { m_LootMode = lootMode; }
        void AddLootMode(uint16 lootMode) { m_LootMode |= lootMode; }
        void RemoveLootMode(uint16 lootMode) { m_LootMode &= ~lootMode; }
        void ResetLootMode() { m_LootMode = LOOT_MODE_DEFAULT; }

        void AddToSkillupList(ObjectGuid const& PlayerGuidLow) { m_SkillupList.insert(PlayerGuidLow); }
        bool IsInSkillupList(ObjectGuid const& playerGuid) const
        {
            return m_SkillupList.count(playerGuid) > 0;
        }
        void ClearSkillupList() { m_SkillupList.clear(); }

        void AddUniqueUse(Player* player);
        void AddUse() { ++m_usetimes; }

        uint32 GetUseCount() const { return m_usetimes; }
        uint32 GetUniqueUseCount() const { return uint32(m_unique_users.size()); }

        void SaveRespawnTime() override;

        Loot        loot;

        Player* GetLootRecipient() const;
        Group* GetLootRecipientGroup() const;
        void SetLootRecipient(Unit* unit, Group* group = nullptr);
        bool IsLootAllowedFor(Player const* player) const;
        bool HasLootRecipient() const { return !m_lootRecipient.IsEmpty() || !m_lootRecipientGroup.IsEmpty(); }
        uint32 m_groupLootTimer;                            // (msecs)timer used for group loot
        ObjectGuid lootingGroupLowGUID;                     // used to find group which is looting

        GameObject* GetLinkedTrap();
        void SetLinkedTrap(GameObject* linkedTrap) { m_linkedTrap = linkedTrap->GetGUID(); }

        bool hasQuest(uint32 quest_id) const override;
        bool hasInvolvedQuest(uint32 quest_id) const override;
        bool ActivateToQuest(Player* target) const;
        void UseDoorOrButton(uint32 time_to_restore = 0, bool alternative = false, Unit* user = NULL);
                                                            // 0 = use `gameobject`.`spawntimesecs`
        void ResetDoorOrButton();

        void TriggeringLinkedGameObject(uint32 trapEntry, Unit* target);

        bool IsNeverVisibleFor(WorldObject const* seer) const override;
        bool IsAlwaysVisibleFor(WorldObject const* seer) const override;
        bool IsInvisibleDueToDespawn() const override;

        uint8 GetLevelForTarget(WorldObject const* target) const override;

        GameObject* LookupFishingHoleAround(float range);

        void CastSpell(Unit* target, uint32 spell, bool triggered = true);
        void CastSpell(Unit* target, uint32 spell, TriggerCastFlags triggered);
        void SendCustomAnim(uint32 anim);
        bool IsInRange(float x, float y, float z, float radius) const;

        void ModifyHealth(int32 change, Unit* attackerOrHealer = NULL, uint32 spellId = 0);
        // sets GameObject type 33 destruction flags and optionally default health for that state
        void SetDestructibleState(GameObjectDestructibleState state, Player* eventInvoker = NULL, bool setHealth = false);
        GameObjectDestructibleState GetDestructibleState() const
        {
            if (HasFlag(GAMEOBJECT_FLAGS, GO_FLAG_DESTROYED))
                return GO_DESTRUCTIBLE_DESTROYED;
            if (HasFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED))
                return GO_DESTRUCTIBLE_DAMAGED;
            return GO_DESTRUCTIBLE_INTACT;
        }

        void EventInform(uint32 eventId, WorldObject* invoker = NULL);

        virtual uint32 GetScriptId() const;
        GameObjectAI* AI() const { return m_AI; }

        std::string GetAIName() const;
        void SetDisplayId(uint32 displayid);
        uint32 GetDisplayId() const { return GetUInt32Value(GAMEOBJECT_DISPLAYID); }
        uint8 GetNameSetId() const;

        uint32 GetFaction() const { return GetUInt32Value(GAMEOBJECT_FACTION); }
        void SetFaction(uint32 faction) { SetUInt32Value(GAMEOBJECT_FACTION, faction); }

        GameObjectModel* m_model;
        void GetRespawnPosition(float &x, float &y, float &z, float* ori = NULL) const;

        Transport* ToTransport() { if (GetGOInfo()->type == GAMEOBJECT_TYPE_MAP_OBJ_TRANSPORT) return reinterpret_cast<Transport*>(this); else return NULL; }
        Transport const* ToTransport() const { if (GetGOInfo()->type == GAMEOBJECT_TYPE_MAP_OBJ_TRANSPORT) return reinterpret_cast<Transport const*>(this); else return NULL; }

        float GetStationaryX() const override { return m_stationaryPosition.GetPositionX(); }
        float GetStationaryY() const override { return m_stationaryPosition.GetPositionY(); }
        float GetStationaryZ() const override { return m_stationaryPosition.GetPositionZ(); }
        float GetStationaryO() const override { return m_stationaryPosition.GetOrientation(); }
        void RelocateStationaryPosition(float x, float y, float z, float o) { m_stationaryPosition.Relocate(x, y, z, o); }

        float GetInteractionDistance() const;

        void UpdateModelPosition();

        uint16 GetAIAnimKitId() const override { return _animKitId; }
        void SetAnimKitId(uint16 animKitId, bool oneshot);

        uint32 GetWorldEffectID() const { return _worldEffectID; }
        void SetWorldEffectID(uint32 worldEffectID) { _worldEffectID = worldEffectID; }

        void AIM_Destroy();
        bool AIM_Initialize();

    protected:
        GameObjectModel* CreateModel();
        void UpdateModel();                                 // updates model in case displayId were changed
        uint32      m_spellId;
        time_t      m_respawnTime;                          // (secs) time of next respawn (or despawn if GO have owner()),
        uint32      m_respawnDelayTime;                     // (secs) if 0 then current GO state no dependent from timer
        LootState   m_lootState;
        ObjectGuid  m_lootStateUnitGUID;                    // GUID of the unit passed with SetLootState(LootState, Unit*)
        bool        m_spawnedByDefault;
        time_t      m_cooldownTime;                         // used as internal reaction delay time store (not state change reaction).
                                                            // For traps this: spell casting cooldown, for doors/buttons: reset time.
        GOState     m_prevGoState;                          // What state to set whenever resetting

        GuidSet m_SkillupList;

        ObjectGuid m_ritualOwnerGUID;                       // used for GAMEOBJECT_TYPE_RITUAL where GO is not summoned (no owner)
        GuidSet m_unique_users;
        uint32 m_usetimes;

        typedef std::map<uint32, ObjectGuid> ChairSlotAndUser;
        ChairSlotAndUser ChairListSlots;

        ObjectGuid::LowType m_spawnId;                               ///< For new or temporary gameobjects is 0 for saved it is lowguid
        GameObjectTemplate const* m_goInfo;
        GameObjectTemplateAddon const* m_goTemplateAddon;
        GameObjectData const* m_goData;
        GameObjectValue m_goValue;

        int64 m_packedRotation;
        QuaternionData m_worldRotation;
        Position m_stationaryPosition;

        ObjectGuid m_lootRecipient;
        ObjectGuid m_lootRecipientGroup;
        uint16 m_LootMode;                                  // bitmask, default LOOT_MODE_DEFAULT, determines what loot will be lootable

        ObjectGuid m_linkedTrap;

    private:
        void RemoveFromOwner();
        void SwitchDoorOrButton(bool activate, bool alternative = false);
        void UpdatePackedRotation();

        //! Object distance/size - overridden from Object::_IsWithinDist. Needs to take in account proper GO size.
        bool _IsWithinDist(WorldObject const* obj, float dist2compare, bool /*is3D*/) const override
        {
            //! Following check does check 3d distance
            return IsInRange(obj->GetPositionX(), obj->GetPositionY(), obj->GetPositionZ(), dist2compare);
        }

        GameObjectAI* m_AI;
        uint16 _animKitId;
        uint32 _worldEffectID;
};
#endif
