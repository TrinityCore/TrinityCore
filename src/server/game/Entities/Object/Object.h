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

#ifndef _OBJECT_H
#define _OBJECT_H

#include "Common.h"
#include "Duration.h"
#include "GridReference.h"
#include "GridRefManager.h"
#include "ModelIgnoreFlags.h"
#include "MovementInfo.h"
#include "ObjectDefines.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include "PhaseShift.h"
#include "Position.h"
#include "SharedDefines.h"
#include "SpellDefines.h"
#include "UpdateFields.h"
#include <list>
#include <unordered_map>

class AreaTrigger;
class Conversation;
class Corpse;
class Creature;
class CreatureAI;
class DynamicObject;
class GameObject;
class InstanceScript;
class Map;
class Object;
class Player;
class Scenario;
class TempSummon;
class Transport;
class Unit;
class UpdateData;
class WorldObject;
class WorldPacket;
class ZoneScript;
struct PositionFullTerrainStatus;
struct QuaternionData;

typedef std::unordered_map<Player*, UpdateData> UpdateDataMapType;

struct CreateObjectBits
{
    bool NoBirthAnim : 1;
    bool EnablePortals : 1;
    bool PlayHoverAnim : 1;
    bool MovementUpdate : 1;
    bool MovementTransport : 1;
    bool Stationary : 1;
    bool CombatVictim : 1;
    bool ServerTime : 1;
    bool Vehicle : 1;
    bool AnimKit : 1;
    bool Rotation : 1;
    bool AreaTrigger : 1;
    bool GameObject : 1;
    bool SmoothPhasing : 1;
    bool ThisIsYou : 1;
    bool SceneObject : 1;
    bool ActivePlayer : 1;
    bool Conversation : 1;

    void Clear()
    {
        memset(this, 0, sizeof(CreateObjectBits));
    }
};

namespace UF
{
    template<typename T>
    inline bool SetUpdateFieldValue(UpdateFieldSetter<T>& setter, typename UpdateFieldSetter<T>::value_type&& value)
    {
        return setter.SetValue(std::move(value));
    }

    template<typename T>
    inline typename DynamicUpdateFieldSetter<T>::insert_result AddDynamicUpdateFieldValue(DynamicUpdateFieldSetter<T>& setter)
    {
        return setter.AddValue();
    }

    template<typename T>
    inline typename DynamicUpdateFieldSetter<T>::insert_result InsertDynamicUpdateFieldValue(DynamicUpdateFieldSetter<T>& setter, uint32 index)
    {
        return setter.InsertValue(index);
    }

    template<typename T>
    inline void RemoveDynamicUpdateFieldValue(DynamicUpdateFieldSetter<T>& setter, uint32 index)
    {
        setter.RemoveValue(index);
    }

    template<typename T>
    inline void ClearDynamicUpdateFieldValues(DynamicUpdateFieldSetter<T>& setter)
    {
        setter.Clear();
    }

    template<typename T>
    inline void RemoveOptionalUpdateFieldValue(OptionalUpdateFieldSetter<T>& setter)
    {
        setter.RemoveValue();
    }
}

float const DEFAULT_COLLISION_HEIGHT = 2.03128f; // Most common value in dbc

class TC_GAME_API Object
{
    public:
        virtual ~Object();

        bool IsInWorld() const { return m_inWorld; }

        virtual void AddToWorld();
        virtual void RemoveFromWorld();

        ObjectGuid const& GetGUID() const { return m_guid; }
        uint32 GetEntry() const { return m_objectData->EntryID; }
        void SetEntry(uint32 entry) { SetUpdateFieldValue(m_values.ModifyValue(&Object::m_objectData).ModifyValue(&UF::ObjectData::EntryID), entry); }

        float GetObjectScale() const { return m_objectData->Scale; }
        virtual void SetObjectScale(float scale) { SetUpdateFieldValue(m_values.ModifyValue(&Object::m_objectData).ModifyValue(&UF::ObjectData::Scale), scale); }

        uint32 GetDynamicFlags() const { return m_objectData->DynamicFlags; }
        bool HasDynamicFlag(uint32 flag) const { return (*m_objectData->DynamicFlags & flag) != 0; }
        void AddDynamicFlag(uint32 flag) { SetUpdateFieldFlagValue(m_values.ModifyValue(&Object::m_objectData).ModifyValue(&UF::ObjectData::DynamicFlags), flag); }
        void RemoveDynamicFlag(uint32 flag) { RemoveUpdateFieldFlagValue(m_values.ModifyValue(&Object::m_objectData).ModifyValue(&UF::ObjectData::DynamicFlags), flag); }
        void SetDynamicFlags(uint32 flag) { SetUpdateFieldValue(m_values.ModifyValue(&Object::m_objectData).ModifyValue(&UF::ObjectData::DynamicFlags), flag); }

        TypeID GetTypeId() const { return m_objectTypeId; }
        bool isType(uint16 mask) const { return (mask & m_objectType) != 0; }

        virtual void BuildCreateUpdateBlockForPlayer(UpdateData* data, Player* target) const;
        void SendUpdateToPlayer(Player* player);

        void BuildValuesUpdateBlockForPlayer(UpdateData* data, Player const* target) const;
        void BuildValuesUpdateBlockForPlayerWithFlag(UpdateData* data, UF::UpdateFieldFlag flags, Player const* target) const;
        void BuildDestroyUpdateBlock(UpdateData* data) const;
        void BuildOutOfRangeUpdateBlock(UpdateData* data) const;
        ByteBuffer PrepareValuesUpdateBuffer() const;

        virtual void DestroyForPlayer(Player* target) const;

        virtual void ClearUpdateMask(bool remove);

        virtual std::string GetNameForLocaleIdx(LocaleConstant locale) const = 0;

        virtual bool hasQuest(uint32 /* quest_id */) const { return false; }
        virtual bool hasInvolvedQuest(uint32 /* quest_id */) const { return false; }
        void SetIsNewObject(bool enable) { m_isNewObject = enable; }
        virtual void BuildUpdate(UpdateDataMapType&) { }
        void BuildFieldsUpdate(Player*, UpdateDataMapType &) const;

        inline bool IsPlayer() const { return GetTypeId() == TYPEID_PLAYER; }
        Player* ToPlayer() { if (IsPlayer()) return reinterpret_cast<Player*>(this); else return nullptr; }
        Player const* ToPlayer() const { if (IsPlayer()) return reinterpret_cast<Player const*>(this); else return nullptr; }

        inline bool IsCreature() const { return GetTypeId() == TYPEID_UNIT; }
        Creature* ToCreature() { if (IsCreature()) return reinterpret_cast<Creature*>(this); else return nullptr; }
        Creature const* ToCreature() const { if (IsCreature()) return reinterpret_cast<Creature const*>(this); else return nullptr; }

        inline bool IsUnit() const { return isType(TYPEMASK_UNIT); }
        Unit* ToUnit() { if (IsUnit()) return reinterpret_cast<Unit*>(this); else return nullptr; }
        Unit const* ToUnit() const { if (IsUnit()) return reinterpret_cast<Unit const*>(this); else return nullptr; }

        inline bool IsGameObject() const { return GetTypeId() == TYPEID_GAMEOBJECT; }
        GameObject* ToGameObject() { if (IsGameObject()) return reinterpret_cast<GameObject*>(this); else return nullptr; }
        GameObject const* ToGameObject() const { if (IsGameObject()) return reinterpret_cast<GameObject const*>(this); else return nullptr; }

        inline bool IsCorpse() const { return GetTypeId() == TYPEID_CORPSE; }
        Corpse* ToCorpse() { if (IsCorpse()) return reinterpret_cast<Corpse*>(this); else return nullptr; }
        Corpse const* ToCorpse() const { if (IsCorpse()) return reinterpret_cast<Corpse const*>(this); else return nullptr; }

        inline bool IsDynObject() const { return GetTypeId() == TYPEID_DYNAMICOBJECT; }
        DynamicObject* ToDynObject() { if (IsDynObject()) return reinterpret_cast<DynamicObject*>(this); else return nullptr; }
        DynamicObject const* ToDynObject() const { if (IsDynObject()) return reinterpret_cast<DynamicObject const*>(this); else return nullptr; }

        inline bool IsAreaTrigger() const { return GetTypeId() == TYPEID_AREATRIGGER; }
        AreaTrigger* ToAreaTrigger() { if (IsAreaTrigger()) return reinterpret_cast<AreaTrigger*>(this); else return nullptr; }
        AreaTrigger const* ToAreaTrigger() const { if (IsAreaTrigger()) return reinterpret_cast<AreaTrigger const*>(this); else return nullptr; }

        inline bool IsConversation() const { return GetTypeId() == TYPEID_CONVERSATION; }
        Conversation* ToConversation() { if (GetTypeId() == TYPEID_CONVERSATION) return reinterpret_cast<Conversation*>(this); else return nullptr; }
        Conversation const* ToConversation() const { if (GetTypeId() == TYPEID_CONVERSATION) return reinterpret_cast<Conversation const*>(this); else return nullptr; }

        UF::UpdateFieldHolder m_values;
        UF::UpdateField<UF::ObjectData, 0, TYPEID_OBJECT> m_objectData;

        template<typename T>
        void ForceUpdateFieldChange(UF::UpdateFieldSetter<T> const& /*setter*/)
        {
            AddToObjectUpdateIfNeeded();
        }

    protected:
        Object();

        void _Create(ObjectGuid const& guid);

        template<typename T>
        void SetUpdateFieldValue(UF::UpdateFieldSetter<T> setter, typename UF::UpdateFieldSetter<T>::value_type value)
        {
            if (UF::SetUpdateFieldValue(setter, std::move(value)))
                AddToObjectUpdateIfNeeded();
        }

        template<typename T>
        void SetUpdateFieldFlagValue(UF::UpdateFieldSetter<T> setter, typename UF::UpdateFieldSetter<T>::value_type flag)
        {
            static_assert(std::is_integral<T>::value, "SetUpdateFieldFlagValue must be used with integral types");
            SetUpdateFieldValue(setter, setter.GetValue() | flag);
        }

        template<typename T>
        void RemoveUpdateFieldFlagValue(UF::UpdateFieldSetter<T> setter, typename UF::UpdateFieldSetter<T>::value_type flag)
        {
            static_assert(std::is_integral<T>::value, "RemoveUpdateFieldFlagValue must be used with integral types");
            SetUpdateFieldValue(setter, setter.GetValue() & ~flag);
        }

        template<typename T>
        typename UF::DynamicUpdateFieldSetter<T>::insert_result AddDynamicUpdateFieldValue(UF::DynamicUpdateFieldSetter<T> setter)
        {
            AddToObjectUpdateIfNeeded();
            return UF::AddDynamicUpdateFieldValue(setter);
        }

        template<typename T>
        typename UF::DynamicUpdateFieldSetter<T>::insert_result InsertDynamicUpdateFieldValue(UF::DynamicUpdateFieldSetter<T> setter, uint32 index)
        {
            AddToObjectUpdateIfNeeded();
            return UF::InsertDynamicUpdateFieldValue(setter, index);
        }

        template<typename T>
        void RemoveDynamicUpdateFieldValue(UF::DynamicUpdateFieldSetter<T> setter, uint32 index)
        {
            AddToObjectUpdateIfNeeded();
            UF::RemoveDynamicUpdateFieldValue(setter, index);
        }

        template<typename T>
        void ClearDynamicUpdateFieldValues(UF::DynamicUpdateFieldSetter<T> setter)
        {
            AddToObjectUpdateIfNeeded();
            UF::ClearDynamicUpdateFieldValues(setter);
        }

        template<typename T>
        void RemoveOptionalUpdateFieldValue(UF::OptionalUpdateFieldSetter<T> setter)
        {
            AddToObjectUpdateIfNeeded();
            UF::RemoveOptionalUpdateFieldValue(setter);
        }

        // stat system helpers
        template<typename T>
        void SetUpdateFieldStatValue(UF::UpdateFieldSetter<T> setter, typename UF::UpdateFieldSetter<T>::value_type value)
        {
            static_assert(std::is_arithmetic<T>::value, "SetUpdateFieldStatValue must be used with arithmetic types");
            SetUpdateFieldValue(setter, std::max(value, T(0)));
        }

        template<typename T>
        void ApplyModUpdateFieldValue(UF::UpdateFieldSetter<T> setter, typename UF::UpdateFieldSetter<T>::value_type mod, bool apply)
        {
            static_assert(std::is_arithmetic<T>::value, "SetUpdateFieldStatValue must be used with arithmetic types");

            T value = setter.GetValue();
            if (apply)
                value += mod;
            else
                value -= mod;

            SetUpdateFieldValue(setter, value);
        }

        template<typename T>
        void ApplyPercentModUpdateFieldValue(UF::UpdateFieldSetter<T> setter, float percent, bool apply)
        {
            static_assert(std::is_arithmetic<T>::value, "SetUpdateFieldStatValue must be used with arithmetic types");

            T value = setter.GetValue();

            // don't want to include Util.h here
            //ApplyPercentModFloatVar(value, percent, apply);
            if (percent == -100.0f)
                percent = -99.99f;
            value *= (apply ? (100.0f + percent) / 100.0f : 100.0f / (100.0f + percent));

            SetUpdateFieldValue(setter, value);
        }

        template<typename Action>
        void DoWithSuppressingObjectUpdates(Action&& action)
        {
            bool wasUpdatedBeforeAction = m_objectUpdated;
            action();
            if (m_objectUpdated && !wasUpdatedBeforeAction)
            {
                RemoveFromObjectUpdate();
                m_objectUpdated = false;
            }
        }

        void BuildMovementUpdate(ByteBuffer* data, CreateObjectBits flags) const;
        virtual UF::UpdateFieldFlag GetUpdateFieldFlagsFor(Player const* target) const;
        virtual void BuildValuesCreate(ByteBuffer* data, Player const* target) const = 0;
        virtual void BuildValuesUpdate(ByteBuffer* data, Player const* target) const = 0;

    public:
        virtual void BuildValuesUpdateWithFlag(ByteBuffer* data, UF::UpdateFieldFlag flags, Player const* target) const;

    protected:
        uint16 m_objectType;

        TypeID m_objectTypeId;
        CreateObjectBits m_updateFlag;

        virtual void AddToObjectUpdate() = 0;
        virtual void RemoveFromObjectUpdate() = 0;
        void AddToObjectUpdateIfNeeded();

        bool m_objectUpdated;

    private:
        ObjectGuid m_guid;
        bool m_inWorld;
        bool m_isNewObject;

        Object(Object const& right) = delete;
        Object& operator=(Object const& right) = delete;
};

template<class T>
class GridObject
{
    public:
        virtual ~GridObject() { }

        bool IsInGrid() const { return _gridRef.isValid(); }
        void AddToGrid(GridRefManager<T>& m) { ASSERT(!IsInGrid()); _gridRef.link(&m, (T*)this); }
        void RemoveFromGrid() { ASSERT(IsInGrid()); _gridRef.unlink(); }
    private:
        GridReference<T> _gridRef;
};

template <class T_VALUES, class T_FLAGS, class FLAG_TYPE, size_t ARRAY_SIZE>
class FlaggedValuesArray32
{
    public:
        FlaggedValuesArray32()
        {
            for (uint32 i = 0; i < ARRAY_SIZE; ++i)
                m_values[i] = T_VALUES(0);
            m_flags = 0;
        }

        T_FLAGS  GetFlags() const { return m_flags; }
        bool     HasFlag(FLAG_TYPE flag) const { return m_flags & (1 << flag); }
        void     AddFlag(FLAG_TYPE flag) { m_flags |= (1 << flag); }
        void     DelFlag(FLAG_TYPE flag) { m_flags &= ~(1 << flag); }

        T_VALUES GetValue(FLAG_TYPE flag) const { return m_values[flag]; }
        void     SetValue(FLAG_TYPE flag, T_VALUES value) { m_values[flag] = value; }
        void     AddValue(FLAG_TYPE flag, T_VALUES value) { m_values[flag] += value; }

    private:
        T_VALUES m_values[ARRAY_SIZE];
        T_FLAGS m_flags;
};

class TC_GAME_API WorldObject : public Object, public WorldLocation
{
    protected:
        explicit WorldObject(bool isWorldObject); //note: here it means if it is in grid object list or world object list
    public:
        virtual ~WorldObject();

        virtual void Update (uint32 /*time_diff*/) { }

        void AddToWorld() override;
        void RemoveFromWorld() override;

        void GetNearPoint2D(float &x, float &y, float distance, float absAngle) const;
        void GetNearPoint(WorldObject const* searcher, float &x, float &y, float &z, float searcher_size, float distance2d, float absAngle) const;
        void GetClosePoint(float &x, float &y, float &z, float size, float distance2d = 0, float angle = 0) const;
        void MovePosition(Position &pos, float dist, float angle);
        Position GetNearPosition(float dist, float angle);
        void MovePositionToFirstCollision(Position &pos, float dist, float angle);
        Position GetFirstCollisionPosition(float dist, float angle);
        Position GetRandomNearPosition(float radius);
        void GetContactPoint(WorldObject const* obj, float &x, float &y, float &z, float distance2d = CONTACT_DISTANCE) const;

        virtual float GetCombatReach() const { return 0.0f; } // overridden (only) in Unit
        void UpdateGroundPositionZ(float x, float y, float &z) const;
        void UpdateAllowedPositionZ(float x, float y, float &z) const;

        void GetRandomPoint(Position const& srcPos, float distance, float& rand_x, float& rand_y, float& rand_z) const;
        Position GetRandomPoint(Position const& srcPos, float distance) const;

        uint32 GetInstanceId() const { return m_InstanceId; }

        bool IsInPhase(WorldObject const* obj) const
        {
            return GetPhaseShift().CanSee(obj->GetPhaseShift());
        }
        static bool InSamePhase(WorldObject const* a, WorldObject const* b)
        {
            return a && b && a->IsInPhase(b);
        }

        PhaseShift& GetPhaseShift() { return _phaseShift; }
        PhaseShift const& GetPhaseShift() const { return _phaseShift; }
        PhaseShift& GetSuppressedPhaseShift() { return _suppressedPhaseShift; }
        PhaseShift const& GetSuppressedPhaseShift() const { return _suppressedPhaseShift; }
        int32 GetDBPhase() const { return _dbPhase; }

        // if negative it is used as PhaseGroupId
        void SetDBPhase(int32 p) { _dbPhase = p; }

        uint32 GetZoneId() const { return m_zoneId; }
        uint32 GetAreaId() const { return m_areaId; }
        void GetZoneAndAreaId(uint32& zoneid, uint32& areaid) const { zoneid = m_zoneId, areaid = m_areaId; }
        bool IsOutdoors() const { return m_outdoors; }
        bool IsInWorldPvpZone() const;

        InstanceScript* GetInstanceScript() const;

        std::string const& GetName() const { return m_name; }
        void SetName(std::string newname) { m_name = std::move(newname); }

        std::string GetNameForLocaleIdx(LocaleConstant /*locale*/) const override { return m_name; }

        float GetDistance(WorldObject const* obj) const;
        float GetDistance(Position const& pos) const;
        float GetDistance(float x, float y, float z) const;
        float GetDistance2d(WorldObject const* obj) const;
        float GetDistance2d(float x, float y) const;
        float GetDistanceZ(WorldObject const* obj) const;

        bool IsSelfOrInSameMap(WorldObject const* obj) const;
        bool IsInMap(WorldObject const* obj) const;
        bool IsWithinDist3d(float x, float y, float z, float dist) const;
        bool IsWithinDist3d(Position const* pos, float dist) const;
        bool IsWithinDist2d(float x, float y, float dist) const;
        bool IsWithinDist2d(Position const* pos, float dist) const;
        // use only if you will sure about placing both object at same map
        bool IsWithinDist(WorldObject const* obj, float dist2compare, bool is3D = true) const;
        bool IsWithinDistInMap(WorldObject const* obj, float dist2compare, bool is3D = true, bool incOwnRadius = true, bool incTargetRadius = true) const;
        bool IsWithinLOS(float x, float y, float z, LineOfSightChecks checks = LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags ignoreFlags = VMAP::ModelIgnoreFlags::Nothing) const;
        bool IsWithinLOSInMap(WorldObject const* obj, LineOfSightChecks checks = LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags ignoreFlags = VMAP::ModelIgnoreFlags::Nothing) const;
        Position GetHitSpherePointFor(Position const& dest) const;
        void GetHitSpherePointFor(Position const& dest, float& x, float& y, float& z) const;
        bool GetDistanceOrder(WorldObject const* obj1, WorldObject const* obj2, bool is3D = true) const;
        bool IsInRange(WorldObject const* obj, float minRange, float maxRange, bool is3D = true) const;
        bool IsInRange2d(float x, float y, float minRange, float maxRange) const;
        bool IsInRange3d(float x, float y, float z, float minRange, float maxRange) const;
        bool isInFront(WorldObject const* target, float arc = float(M_PI)) const;
        bool isInBack(WorldObject const* target, float arc = float(M_PI)) const;

        bool IsInBetween(Position const& pos1, Position const& pos2, float size = 0) const;
        bool IsInBetween(WorldObject const* obj1, WorldObject const* obj2, float size = 0) const { return obj1 && obj2 && IsInBetween(obj1->GetPosition(), obj2->GetPosition(), size); }

        virtual void CleanupsBeforeDelete(bool finalCleanup = true);  // used in destructor or explicitly before mass creature delete to remove cross-references to already deleted units

        virtual void SendMessageToSet(WorldPacket const* data, bool self) const;
        virtual void SendMessageToSetInRange(WorldPacket const* data, float dist, bool self) const;
        virtual void SendMessageToSet(WorldPacket const* data, Player const* skipped_rcvr) const;

        virtual uint8 GetLevelForTarget(WorldObject const* /*target*/) const { return 1; }

        void PlayDistanceSound(uint32 soundId, Player* target = nullptr);
        void PlayDirectSound(uint32 soundId, Player* target = nullptr, uint32 broadcastTextId = 0);
        void PlayDirectMusic(uint32 musicId, Player* target = nullptr);

        virtual void SaveRespawnTime(uint32 /*forceDelay*/ = 0, bool /*saveToDB*/ = true) { }
        void AddObjectToRemoveList();

        float GetGridActivationRange() const;
        float GetVisibilityRange() const;
        float GetSightRange(WorldObject const* target = nullptr) const;
        bool CanSeeOrDetect(WorldObject const* obj, bool ignoreStealth = false, bool distanceCheck = false, bool checkAlert = false) const;

        FlaggedValuesArray32<int32, uint32, StealthType, TOTAL_STEALTH_TYPES> m_stealth;
        FlaggedValuesArray32<int32, uint32, StealthType, TOTAL_STEALTH_TYPES> m_stealthDetect;

        FlaggedValuesArray32<int32, uint32, InvisibilityType, TOTAL_INVISIBILITY_TYPES> m_invisibility;
        FlaggedValuesArray32<int32, uint32, InvisibilityType, TOTAL_INVISIBILITY_TYPES> m_invisibilityDetect;

        FlaggedValuesArray32<int32, uint32, ServerSideVisibilityType, TOTAL_SERVERSIDE_VISIBILITY_TYPES> m_serverSideVisibility;
        FlaggedValuesArray32<int32, uint32, ServerSideVisibilityType, TOTAL_SERVERSIDE_VISIBILITY_TYPES> m_serverSideVisibilityDetect;

        virtual void SetMap(Map* map);
        virtual void ResetMap();
        Map* GetMap() const { ASSERT(m_currMap); return m_currMap; }
        Map* FindMap() const { return m_currMap; }
        //used to check all object's GetMap() calls when object is not in world!

        void SetZoneScript();
        ZoneScript* GetZoneScript() const { return m_zoneScript; }

        Scenario* GetScenario() const;

        TempSummon* SummonCreature(uint32 entry, Position const& pos, TempSummonType despawnType = TEMPSUMMON_MANUAL_DESPAWN, uint32 despawnTime = 0, uint32 vehId = 0, ObjectGuid privateObjectOwner = ObjectGuid::Empty);
        TempSummon* SummonCreature(uint32 entry, Position const& pos, TempSummonType despawnType, Milliseconds const& despawnTime, uint32 vehId = 0, ObjectGuid privateObjectOwner = ObjectGuid::Empty) { return SummonCreature(entry, pos, despawnType, uint32(despawnTime.count()), vehId, privateObjectOwner); }
        TempSummon* SummonCreature(uint32 entry, float x, float y, float z, float o = 0, TempSummonType despawnType = TEMPSUMMON_MANUAL_DESPAWN, uint32 despawnTime = 0, ObjectGuid privateObjectOwner = ObjectGuid::Empty);
        GameObject* SummonGameObject(uint32 entry, Position const& pos, QuaternionData const& rot, uint32 respawnTime /* s */, GOSummonType summonType = GO_SUMMON_TIMED_OR_CORPSE_DESPAWN);
        GameObject* SummonGameObject(uint32 entry, float x, float y, float z, float ang, QuaternionData const& rot, uint32 respawnTime /* s */);
        Creature*   SummonTrigger(float x, float y, float z, float ang, uint32 dur, CreatureAI* (*GetAI)(Creature*) = nullptr);
        void SummonCreatureGroup(uint8 group, std::list<TempSummon*>* list = nullptr);

        Creature*   FindNearestCreature(uint32 entry, float range, bool alive = true) const;
        GameObject* FindNearestGameObject(uint32 entry, float range) const;
        GameObject* FindNearestGameObjectOfType(GameobjectTypes type, float range) const;
        Player* SelectNearestPlayer(float distance) const;

        template <typename Container>
        void GetGameObjectListWithEntryInGrid(Container& gameObjectContainer, uint32 entry, float maxSearchRange = 250.0f) const;

        template <typename Container>
        void GetCreatureListWithEntryInGrid(Container& creatureContainer, uint32 entry, float maxSearchRange = 250.0f) const;

        template <typename Container>
        void GetPlayerListInGrid(Container& playerContainer, float maxSearchRange) const;

        void DestroyForNearbyPlayers();
        virtual void UpdateObjectVisibility(bool forced = true);
        virtual void UpdateObjectVisibilityOnCreate() { UpdateObjectVisibility(true); }
        void UpdatePositionData();

        void BuildUpdate(UpdateDataMapType&) override;
        void AddToObjectUpdate() override;
        void RemoveFromObjectUpdate() override;

        //relocation and visibility system functions
        void AddToNotify(uint16 f) { m_notifyflags |= f;}
        bool isNeedNotify(uint16 f) const { return (m_notifyflags & f) != 0; }
        uint16 GetNotifyFlags() const { return m_notifyflags; }
        void ResetAllNotifies() { m_notifyflags = 0; }

        bool isActiveObject() const { return m_isActive; }
        void setActive(bool isActiveObject);
        bool IsFarVisible() const { return m_isFarVisible; }
        void SetFarVisible(bool on);
        bool IsVisibilityOverridden() const { return m_visibilityDistanceOverride.is_initialized(); }
        void SetVisibilityDistanceOverride(VisibilityDistanceType type);
        void SetWorldObject(bool apply);
        bool IsPermanentWorldObject() const { return m_isWorldObject; }
        bool IsWorldObject() const;

        uint32  LastUsedScriptID;

        // Transports
        Transport* GetTransport() const { return m_transport; }
        float GetTransOffsetX() const { return m_movementInfo.transport.pos.GetPositionX(); }
        float GetTransOffsetY() const { return m_movementInfo.transport.pos.GetPositionY(); }
        float GetTransOffsetZ() const { return m_movementInfo.transport.pos.GetPositionZ(); }
        float GetTransOffsetO() const { return m_movementInfo.transport.pos.GetOrientation(); }
        Position const& GetTransOffset() const { return m_movementInfo.transport.pos; }
        uint32 GetTransTime()   const { return m_movementInfo.transport.time; }
        int8 GetTransSeat()     const { return m_movementInfo.transport.seat; }
        virtual ObjectGuid GetTransGUID() const;
        void SetTransport(Transport* t) { m_transport = t; }

        MovementInfo m_movementInfo;

        virtual float GetStationaryX() const { return GetPositionX(); }
        virtual float GetStationaryY() const { return GetPositionY(); }
        virtual float GetStationaryZ() const { return GetPositionZ(); }
        virtual float GetStationaryO() const { return GetOrientation(); }

        float GetFloorZ() const;
        virtual float GetCollisionHeight() const { return 0.0f; }

        float GetMapWaterOrGroundLevel(float x, float y, float z, float* ground = nullptr) const;
        float GetMapHeight(float x, float y, float z, bool vmap = true, float distanceToSearch = 50.0f) const; // DEFAULT_HEIGHT_SEARCH in map.h

        virtual uint16 GetAIAnimKitId() const { return 0; }
        virtual uint16 GetMovementAnimKitId() const { return 0; }
        virtual uint16 GetMeleeAnimKitId() const { return 0; }

        // Watcher
        bool IsPrivateObject() const { return !_privateObjectOwner.IsEmpty(); }
        ObjectGuid GetPrivateObjectOwner() const { return _privateObjectOwner; }
        void SetPrivateObjectOwner(ObjectGuid const& owner) { _privateObjectOwner = owner; }
        bool CheckPrivateObjectOwnerVisibility(WorldObject const* seer) const;

    protected:
        std::string m_name;
        bool m_isActive;
        bool m_isFarVisible;
        Optional<float> m_visibilityDistanceOverride;
        const bool m_isWorldObject;
        ZoneScript* m_zoneScript;

        // transports
        Transport* m_transport;

        virtual void ProcessPositionDataChanged(PositionFullTerrainStatus const& data);
        uint32 m_zoneId;
        uint32 m_areaId;
        float m_staticFloorZ;
        bool m_outdoors;

        //these functions are used mostly for Relocate() and Corpse/Player specific stuff...
        //use them ONLY in LoadFromDB()/Create() funcs and nowhere else!
        //mapId/instanceId should be set in SetMap() function!
        void SetLocationMapId(uint32 _mapId) { m_mapId = _mapId; }
        void SetLocationInstanceId(uint32 _instanceId) { m_InstanceId = _instanceId; }

        virtual bool IsNeverVisibleFor(WorldObject const* /*seer*/) const { return !IsInWorld(); }
        virtual bool IsAlwaysVisibleFor(WorldObject const* /*seer*/) const { return false; }
        virtual bool IsInvisibleDueToDespawn() const { return false; }
        //difference from IsAlwaysVisibleFor: 1. after distance check; 2. use owner or charmer as seer
        virtual bool IsAlwaysDetectableFor(WorldObject const* /*seer*/) const { return false; }
    private:
        Map* m_currMap;                                   // current object's Map location

        //uint32 m_mapId;                                 // object at map with map_id
        uint32 m_InstanceId;                              // in map copy with instance id
        PhaseShift _phaseShift;
        PhaseShift _suppressedPhaseShift;                 // contains phases for current area but not applied due to conditions
        int32 _dbPhase;

        uint16 m_notifyflags;

        ObjectGuid _privateObjectOwner;

        virtual bool _IsWithinDist(WorldObject const* obj, float dist2compare, bool is3D, bool incOwnRadius = true, bool incTargetRadius = true) const;

        bool CanNeverSee(WorldObject const* obj) const;
        virtual bool CanAlwaysSee(WorldObject const* /*obj*/) const { return false; }
        bool CanDetect(WorldObject const* obj, bool ignoreStealth, bool checkAlert = false) const;
        bool CanDetectInvisibilityOf(WorldObject const* obj) const;
        bool CanDetectStealthOf(WorldObject const* obj, bool checkAlert = false) const;
};

namespace Trinity
{
    // Binary predicate to sort WorldObjects based on the distance to a reference WorldObject
    class ObjectDistanceOrderPred
    {
        public:
            ObjectDistanceOrderPred(WorldObject const* refObj, bool ascending = true) : _refObj(refObj), _ascending(ascending) { }

            bool operator()(WorldObject const* left, WorldObject const* right) const
            {
                return _refObj->GetDistanceOrder(left, right) == _ascending;
            }

        private:
            WorldObject const* _refObj;
            bool _ascending;
    };
}

#endif
