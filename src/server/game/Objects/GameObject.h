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

#ifndef MANGOSSERVER_GAMEOBJECT_H
#define MANGOSSERVER_GAMEOBJECT_H

#include "Common.h"
#include "SharedDefines.h"
#include "GameObjectDefines.h"
#include "SpellCaster.h"
#include "LootMgr.h"
#include "Util.h"

class Unit;
class GameObjectAI;
class GameObjectModel;
class Transport;
struct TransportAnimation;

struct GameObjectDisplayInfoEntry;

class GameObject : public SpellCaster
{
    public:
        explicit GameObject();
        ~GameObject() override;

        static GameObject* CreateGameObject(uint32 entry);

        void AddToWorld() override;
        void RemoveFromWorld() override;

        virtual bool Create(uint32 guidlow, uint32 name_id, Map* map, float x, float y, float z, float ang, float rotation0, float rotation1, float rotation2, float rotation3, uint32 animprogress, GOState go_state);
        void Update(uint32 update_diff, uint32 p_time) override;
        GameObjectInfo const* GetGOInfo() const;

        bool HasStaticDBSpawnData() const;                  // listed in `gameobject` table and have fixed in DB guid
        uint32 GetDBTableGUIDLow() const { return HasStaticDBSpawnData() ? GetGUIDLow() : 0; }

        void UpdateRotationFields(float rotation2 = 0.0f, float rotation3 = 0.0f);
        QuaternionData const GetLocalRotation() const;

        // overwrite WorldObject function for proper name localization
        char const* GetNameForLocaleIdx(int32 locale_idx) const override;

        void SaveToDB();
        void SaveToDB(uint32 mapid);
        bool LoadFromDB(uint32 guid, Map* map);
        void DeleteFromDB() const;

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_4_2
        void SetOwnerGuid(ObjectGuid ownerGuid)
        {
            m_spawnedByDefault = false;                     // all object with owner is despawned after delay
            SetGuidValue(OBJECT_FIELD_CREATED_BY, ownerGuid);
        }

        ObjectGuid const& GetOwnerGuid() const { return GetGuidValue(OBJECT_FIELD_CREATED_BY); }
#else
        ObjectGuid m_ownerGuid;
        void SetOwnerGuid(ObjectGuid ownerGuid)
        {
            m_spawnedByDefault = false;                     // all object with owner is despawned after delay
            m_ownerGuid = ownerGuid;
        }

        ObjectGuid const& GetOwnerGuid() const { return m_ownerGuid; }
#endif
        Unit* GetOwner() const;
        Player* GetAffectingPlayer() const final;
        bool IsCharmerOrOwnerPlayerOrPlayerItself() const final { return GetOwnerGuid().IsPlayer(); }

        void SetSpellId(uint32 id)
        {
            m_spawnedByDefault = false;                     // all summoned object is despawned after delay
            m_spellId = id;
        }
        uint32 GetSpellId() const { return m_spellId;}

        time_t GetRespawnTime() const { return m_respawnTime; }
        time_t GetRespawnTimeEx() const
        {
            time_t now = time(nullptr);
            if (m_respawnTime > now)
                return m_respawnTime;
            else
                return now;
        }

        void Despawn();
        void JustDespawnedWaitingRespawn();
        void SetRespawnTime(time_t respawn)
        {
            m_respawnTime = respawn > 0 ? time(nullptr) + respawn : 0;
            m_respawnDelayTime = respawn > 0 ? uint32(respawn) : 0;
        }
        void SetRespawnDelay(time_t respawn)
        {
            m_respawnDelayTime = respawn;
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
        uint32 ComputeRespawnDelay() const; // Applies dynamic / random respawn timers if needed.
        void Refresh();
        void Delete();
        void CleanupsBeforeDelete() override;

        // Functions spawn/remove gameobject with DB guid in all loaded map copies (if point grid loaded in map)
        static void AddToRemoveListInMaps(uint32 db_guid, GameObjectData const* data);
        static void SpawnInMaps(uint32 db_guid, GameObjectData const* data);

        void getFishLoot(Loot* loot, Player* loot_owner);
        GameobjectTypes GetGoType() const { return GameobjectTypes(GetUInt32Value(GAMEOBJECT_TYPE_ID)); }
        void SetGoType(GameobjectTypes type) { SetUInt32Value(GAMEOBJECT_TYPE_ID, type); }
        GOState GetGoState() const { return GOState(GetUInt32Value(GAMEOBJECT_STATE)); }
        void SetGoState(GOState state);

#if SUPPORTED_CLIENT_BUILD >= CLIENT_BUILD_1_12_1
        uint32 GetGoArtKit() const { return GetUInt32Value(GAMEOBJECT_ARTKIT); }
        void SetGoArtKit(uint32 artkit) { SetUInt32Value(GAMEOBJECT_ARTKIT, artkit); }
        uint32 GetGoAnimProgress() const { return GetUInt32Value(GAMEOBJECT_ANIMPROGRESS); }
        void SetGoAnimProgress(uint32 animprogress) { SetUInt32Value(GAMEOBJECT_ANIMPROGRESS, animprogress); }
#else
        uint32 GetGoArtKit() const { return 0; }
        void SetGoArtKit(uint32 artkit) { }
        uint32 GetGoAnimProgress() const { return 0; }
        void SetGoAnimProgress(uint32 animprogress) { }
#endif
        uint32 GetDisplayId() const { return GetUInt32Value(GAMEOBJECT_DISPLAYID); }
        void SetDisplayId(uint32 modelId);

        bool HasCustomAnim() const;
        void SendGameObjectCustomAnim(uint32 animId = 0);
        void SendGameObjectReset();

        float GetObjectBoundingRadius() const override;              // overwrite WorldObject version

        void Use(Unit* user);

        LootState getLootState() const { return m_lootState; }
        void SetLootState(LootState s);

        void AddToSkillupList(Player* player);
        bool IsInSkillupList(Player* player) const;
        void ClearSkillupList() { m_SkillupSet.clear(); }
        void ClearAllUsesData()
        {
            ClearSkillupList();
            m_useTimes = 0;
            m_firstUser.Clear();
            m_UniqueUsers.clear();
        }

        // Used for GAMEOBJECT_TYPE_SUMMONING_RITUAL
        ObjectGuid getSummonTarget() const { return m_summonTarget; }
        void SetSummonTarget(ObjectGuid o) { m_summonTarget = o; }
        void FinishRitual();
        void AddUniqueUse(Player* player);
        void RemoveUniqueUse(Player* player);
        bool HasUniqueUser(Player* player);
        uint32 GetUniqueUseCount();

        void AddUse() { ++m_useTimes; }
        uint32 GetUseCount() const { return m_useTimes; }

        void SaveRespawnTime() override;

        Loot        loot;

        bool HasQuest(uint32 quest_id) const override;
        bool HasInvolvedQuest(uint32 quest_id) const override;
        bool ActivateToQuest(Player* pTarget) const;
        uint32 GetDefaultGossipMenuId() const override { return GetGOInfo()->GetGossipMenuId(); }
        void UseDoorOrButton(uint32 time_to_restore = 0, bool alternative = false);
                                                            // 0 = use `gameobject`.`spawntimesecs`
        void ResetDoorOrButton();

        bool IsHostileTo(WorldObject const* target) const override;
        bool IsFriendlyTo(WorldObject const* target) const override;

        void SummonLinkedTrapIfAny();
        void TriggerLinkedGameObject(Unit* target);
        void RespawnLinkedGameObject();
        
        GameObject* LookupFishingHoleAround(float range);

        GridReference<GameObject>& GetGridRef() { return m_gridRef; }

        // Nostalrius
        bool IsUseRequirementMet() const;
        bool PlayerCanUse(Player* pl);
        void SetOwnerGroupId(uint32 groupId) { m_playerGroupId = groupId; }

        // Gestion des GameObjectAI
        void AIM_Initialize();
        GameObjectAI* AI() { return i_AI; }

        void UpdateCollisionState();
        void UpdateModel();                                 // updates model in case displayId were changed
        GameObjectModel* m_model;
        void UpdateModelPosition();

        float GetStationaryX() const { if (GetGOInfo()->type != GAMEOBJECT_TYPE_MO_TRANSPORT) return m_stationaryPosition.x; return 0.f; }
        float GetStationaryY() const { if (GetGOInfo()->type != GAMEOBJECT_TYPE_MO_TRANSPORT) return m_stationaryPosition.y; return 0.f; }
        float GetStationaryZ() const { if (GetGOInfo()->type != GAMEOBJECT_TYPE_MO_TRANSPORT) return m_stationaryPosition.z; return 0.f; }
        float GetStationaryO() const { if (GetGOInfo()->type != GAMEOBJECT_TYPE_MO_TRANSPORT) return m_stationaryPosition.o; return GetOrientation(); }

        GameObjectData const*  GetGOData() const;

        // Transports system
        bool IsTransport() const;
        bool IsMoTransport() const;
        GenericTransport* ToTransport();
        GenericTransport const* ToTransport() const;
        uint64 GetRotation() const { return m_rotation; }

        bool IsVisible() const { return m_visible; }
        void SetVisible(bool b);
        bool IsVisibleForInState(WorldObject const* pDetector, WorldObject const* viewPoint, bool inVisibleList) const override;

        uint32 GetFactionTemplateId() const final { return GetGOInfo()->faction; }
        uint32 GetLevel() const final ;

        bool IsAtInteractDistance(Position const& pos, float radius) const;
        bool IsAtInteractDistance(Player const* player, uint32 maxRange = 0) const;

        SpellEntry const* GetSpellForLock(Player const* player) const;
    protected:
        bool        m_visible;
        uint32      m_spellId;
        time_t      m_respawnTime;                          // (secs) time of next respawn (or despawn if GO have owner()),
        uint32      m_respawnDelayTime;                     // (secs) if 0 then current GO state no dependent from timer
        LootState   m_lootState;
        bool        m_spawnedByDefault;
        time_t      m_cooldownTime;                         // used as internal reaction delay time store (not state change reaction).
                                                            // For traps/goober this: spell casting cooldown, for doors/buttons: reset time.

        typedef std::set<ObjectGuid> GuidsSet;

        GuidsSet m_SkillupSet;                              // players that already have skill-up at GO use

        uint32 m_useTimes;                                  // amount uses/charges triggered

        // collected only for GAMEOBJECT_TYPE_SUMMONING_RITUAL
        ObjectGuid m_firstUser;                             // first GO user, in most used cases owner, but in some cases no, for example non-summoned multi-use GAMEOBJECT_TYPE_SUMMONING_RITUAL
        GuidsSet m_UniqueUsers;                             // all players who use item, some items activated after specific amount unique uses
        std::mutex m_UniqueUsers_lock;
        ObjectGuid m_summonTarget;                          // The player who is being summoned

        uint64 m_rotation;
        GameObjectInfo const* m_goInfo;

        Position m_stationaryPosition;

        GameObjectAI* i_AI;

        uint32 m_playerGroupId;
    private:
        void SwitchDoorOrButton(bool activate, bool alternative = false);

        GridReference<GameObject> m_gridRef;
};

inline GameObject* Object::ToGameObject()
{
    return IsGameObject() ? static_cast<GameObject*>(this) : nullptr;
}

inline GameObject const* Object::ToGameObject() const
{
    return IsGameObject() ? static_cast<GameObject const*>(this) : nullptr;
}

inline GameObject* ToGameObject(Object* object)
{
    return object && object->IsGameObject() ? static_cast<GameObject*>(object) : nullptr;
}

inline GameObject const* ToGameObject(Object const* object)
{
    return object && object->IsGameObject() ? static_cast<GameObject const*>(object) : nullptr;
}

#endif
