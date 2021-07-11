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

#ifndef _OBJECT_H
#define _OBJECT_H

#include "Common.h"
#include "ByteBuffer.h"
#include "UpdateFields.h"
#include "UpdateData.h"
#include "ObjectGuid.h"
#include "SharedDefines.h"
#include "ObjectDefines.h"
#include "DBCEnums.h"
#include "Util.h"
#include "Timer.h"
#include "Camera.h"
#include "Cell.h"

#include <string>

class WorldPacket;
class UpdateData;
class Corpse;
class Creature;
class Pet;
class Player;
class Unit;
class GameObject;
class SpellCaster;
class Map;
class UpdateMask;
class InstanceData;
class TerrainInfo;
class ZoneScript;
class GenericTransport;
struct FactionTemplateEntry;

typedef std::unordered_map<Player*, UpdateData> UpdateDataMapType;

//use this class to measure time between world update ticks
//essential for units updating their spells after cells become active
class WorldUpdateCounter
{
    public:
        WorldUpdateCounter() : m_tmStart(0) {}

        uint32 timeElapsed()
        {
            if (!m_tmStart)
                m_tmStart = WorldTimer::tickPrevTime();

            return WorldTimer::getMSTimeDiff(m_tmStart, WorldTimer::tickTime());
        }
        uint32 timeElapsed(uint32 now) const
        {
            if (!m_tmStart)
                return 0;
            return WorldTimer::getMSTimeDiff(m_tmStart, now);
        }

        void Reset() { m_tmStart = WorldTimer::tickTime(); }
        void ResetTo(uint32 lastUpdate) {  m_tmStart = lastUpdate; }
    private:
        uint32 m_tmStart;
};

// [-ZERO] Need check and update
// used in most movement packets (send and received)
enum MovementFlags
{
    MOVEFLAG_NONE               = 0x00000000,
    MOVEFLAG_FORWARD            = 0x00000001,
    MOVEFLAG_BACKWARD           = 0x00000002,
    MOVEFLAG_STRAFE_LEFT        = 0x00000004,
    MOVEFLAG_STRAFE_RIGHT       = 0x00000008,
    MOVEFLAG_TURN_LEFT          = 0x00000010,
    MOVEFLAG_TURN_RIGHT         = 0x00000020,
    MOVEFLAG_PITCH_UP           = 0x00000040,
    MOVEFLAG_PITCH_DOWN         = 0x00000080,
    MOVEFLAG_WALK_MODE          = 0x00000100,               // Walking
    //MOVEFLAG_ONTRANSPORT        = 0x00000200, // ??
    MOVEFLAG_LEVITATING         = 0x00000400, // ?? Semble ne pas fonctionner
    MOVEFLAG_FIXED_Z            = 0x00000800, // Hauteur fixee. Sauter => Defiler sur toute la map
    MOVEFLAG_ROOT               = 0x00001000, // Fix Nostalrius
    MOVEFLAG_JUMPING            = 0x00002000,
    MOVEFLAG_FALLINGFAR         = 0x00004000,
    // Fin TC
    MOVEFLAG_SWIMMING           = 0x00200000, // Ok
    MOVEFLAG_SPLINE_ENABLED     = 0x00400000, // Ok
    // 0x00800000 = 'MOVEMENTFLAG_DESCENDING' pour TrinityCore
    MOVEFLAG_CAN_FLY            = 0x00800000,               // [-ZERO] is it really need and correct value
    MOVEFLAG_FLYING             = 0x01000000,               // [-ZERO] is it really need and correct value

    MOVEFLAG_ONTRANSPORT        = 0x02000000,               // Used for flying on some creatures
    MOVEFLAG_SPLINE_ELEVATION   = 0x04000000,               // used for flight paths

    MOVEFLAG_WATERWALKING       = 0x10000000,               // prevent unit from falling through water
    MOVEFLAG_SAFE_FALL          = 0x20000000,               // active rogue safe fall spell (passive)
    MOVEFLAG_HOVER              = 0x40000000,
    MOVEFLAG_INTERNAL           = 0x80000000,

    // Can not be present with MOVEFLAG_ROOT (otherwise client freeze)
    MOVEFLAG_MASK_MOVING        =
        MOVEFLAG_FORWARD | MOVEFLAG_BACKWARD | MOVEFLAG_STRAFE_LEFT | MOVEFLAG_STRAFE_RIGHT |
        MOVEFLAG_PITCH_UP | MOVEFLAG_PITCH_DOWN | MOVEFLAG_JUMPING | MOVEFLAG_FALLINGFAR |
        MOVEFLAG_SPLINE_ELEVATION,
    MOVEFLAG_MASK_MOVING_OR_TURN= MOVEFLAG_MASK_MOVING | MOVEFLAG_TURN_LEFT | MOVEFLAG_TURN_RIGHT,

    // MovementFlags mask that only contains flags for x/z translations
    // this is to avoid that a jumping character that stands still triggers melee-leeway
    MOVEFLAG_MASK_XZ = MOVEFLAG_FORWARD | MOVEFLAG_BACKWARD | MOVEFLAG_STRAFE_LEFT | MOVEFLAG_STRAFE_RIGHT
};

// used in SMSG_MONSTER_MOVE
enum SplineFlags
{
    // Valeurs correctes et testees pour la 1.12.1
    SPLINEFLAG_NONE           = 0x00000000,
    SPLINEFLAG_WALKMODE       = 0x00000100,
    SPLINEFLAG_FLYING         = 0x00000200,

    SPLINEFLAG_SPLINE         = 0x00002000,               // spline n*(float x,y,z)
};

class MovementInfo
{
    public:
        MovementInfo() : moveFlags(MOVEFLAG_NONE), stime(0), ctime(0),
            t_time(0), s_pitch(0.0f), fallTime(0), splineElevation(0.0f) {}

        // Read/Write methods
        void Read(ByteBuffer &data);
        void Write(ByteBuffer &data) const;
        void CorrectData(Unit* mover = nullptr);

        // Movement flags manipulations
        void AddMovementFlag(int f) { moveFlags |= f; }
        void RemoveMovementFlag(int f) { moveFlags &= ~f; }
        bool HasMovementFlag(int f) const { return moveFlags & f; }
        MovementFlags GetMovementFlags() const { return MovementFlags(moveFlags); }
        void SetMovementFlags(MovementFlags f) { moveFlags = f; }

        // Position manipulations
        Position const& GetPos() const { return pos; }
        void SetTransportData(ObjectGuid guid, float x, float y, float z, float o, uint32 time)
        {
            t_guid = guid;
            t_pos.x = x;
            t_pos.y = y;
            t_pos.z = z;
            t_pos.o = o;
            t_time = time;
        }
        void ClearTransportData()
        {
            t_guid = ObjectGuid();
            t_pos.x = 0.0f;
            t_pos.y = 0.0f;
            t_pos.z = 0.0f;
            t_pos.o = 0.0f;
            t_time = 0;
        }
        ObjectGuid const& GetTransportGuid() const { return t_guid; }
        Position const& GetTransportPos() const { return t_pos; }
        Position& GetTransportPos() { return t_pos; }
        uint32 GetTransportTime() const { return t_time; }
        uint32 GetFallTime() const { return fallTime; }
        void ChangeOrientation(float o) { pos.o = o; }
        void ChangePosition(float x, float y, float z, float o) { pos.x = x; pos.y = y; pos.z = z; pos.o = o; }
        void UpdateTime(uint32 _time) { stime = _time; }

        struct JumpInfo
        {
            JumpInfo() : velocity(0.f), sinAngle(0.f), cosAngle(0.f), xyspeed(0.f), startClientTime(0) {}
            float   velocity, sinAngle, cosAngle, xyspeed;
            Position start;
            uint32 startClientTime;
        };

        JumpInfo const& GetJumpInfo() const { return jump; }
    //private:
        // common
        uint32  moveFlags;                                  // see enum MovementFlags
        uint32  stime; // Server time
        uint32  ctime; // Client time
        Position pos;
        // transport
        ObjectGuid t_guid;
        Position t_pos;
        uint32  t_time;
        // swimming and unknown
        float   s_pitch;
        // last fall time
        uint32  fallTime;
        // jumping
        JumpInfo jump;
        // spline
        float splineElevation;
};

inline ByteBuffer& operator<< (ByteBuffer& buf, MovementInfo const& mi)
{
    mi.Write(buf);
    return buf;
}

inline ByteBuffer& operator>> (ByteBuffer& buf, MovementInfo& mi)
{
    mi.Read(buf);
    return buf;
}

enum ObjectDelayedAction
{
    OBJECT_DELAYED_MARK_CLIENT_UPDATE       = 0x1,
    OBJECT_DELAYED_ADD_TO_RELOCATED_LIST    = 0x2,
    OBJECT_DELAYED_ADD_TO_REMOVE_LIST       = 0x4,
};

typedef void(*CreatureAiSetter) (Creature* pCreature);

class Object
{
    public:
        virtual ~Object();

        void SetIsNewObject(bool state) { m_isNewObject = state; }
        bool const& IsInWorld() const { return m_inWorld; }
        virtual void AddToWorld()
        {
            if (m_inWorld)
                return;

            m_inWorld = true;

            // synchronize values mirror with values array (changes will send in updatecreate opcode any way
            ClearUpdateMask(false);                         // false - we can't have update data in update queue before adding to world
        }
        virtual void RemoveFromWorld()
        {
            // if we remove from world then sending changes not required
            ClearUpdateMask(true);
            m_inWorld = false;
        }

        ObjectGuid const& GetObjectGuid() const { return GetGuidValue(OBJECT_FIELD_GUID); }
        uint64 const& GetGUID() const { return GetUInt64Value(OBJECT_FIELD_GUID); } // Conserve par Nostalrius
        uint32 GetGUIDLow() const { return GetObjectGuid().GetCounter(); }
        PackedGuid const& GetPackGUID() const { return m_PackGUID; }
        std::string GetGuidStr() const { return GetObjectGuid().GetString(); }

        uint32 GetEntry() const { return GetUInt32Value(OBJECT_FIELD_ENTRY); }
        void SetEntry(uint32 entry) { SetUInt32Value(OBJECT_FIELD_ENTRY, entry); }

        float GetObjectScale() const
        {
            return m_floatValues[OBJECT_FIELD_SCALE_X] ? m_floatValues[OBJECT_FIELD_SCALE_X] : DEFAULT_OBJECT_SCALE;
        }

        void SetObjectScale(float newScale);

        uint8 GetTypeId() const { return m_objectTypeId; }
        uint8 GetTypeMask() const { return m_objectType; }
        bool isType(TypeMask mask) const { return (mask & m_objectType); }

        virtual void BuildCreateUpdateBlockForPlayer(UpdateData& data, Player* target) const;
        void SendCreateUpdateToPlayer(Player* player);

        // must be overwrite in appropriate subclasses (WorldObject, Item currently), or will crash
        virtual void AddToClientUpdateList();
        virtual void RemoveFromClientUpdateList();
        virtual void BuildUpdateData(UpdateDataMapType& update_players);
        void MarkForClientUpdate();
        void SendForcedObjectUpdate();
        void AddDelayedAction(ObjectDelayedAction e) { _delayedActions |= e; }
        void ExecuteDelayedActions();

        void BuildValuesUpdateBlockForPlayer(UpdateData& data, Player* target) const;
        void BuildValuesUpdateBlockForPlayer(UpdateData& data, UpdateMask& updateMask, Player* target) const;
        void BuildOutOfRangeUpdateBlock(UpdateData& data) const;
        void BuildMovementUpdateBlock(UpdateData& data, uint8 flags = 0) const;

        void BuildMovementUpdate(ByteBuffer* data, uint8 updateFlags) const;
        void BuildValuesUpdate(uint8 updatetype, ByteBuffer* data, UpdateMask* updateMask, Player* target) const;
        void BuildUpdateDataForPlayer(Player* pl, UpdateDataMapType& update_players);

        void SendOutOfRangeUpdateToPlayer(Player* player);

        virtual void DestroyForPlayer(Player* target) const;

        int32 const& GetInt32Value(uint16 index) const
        {
            MANGOS_ASSERT(index < m_valuesCount || PrintIndexError(index , false));
            return m_int32Values[ index ];
        }

        uint32 const& GetUInt32Value(uint16 index) const
        {
            MANGOS_ASSERT(index < m_valuesCount || PrintIndexError(index , false));
            return m_uint32Values[ index ];
        }

        uint64 const& GetUInt64Value(uint16 index) const
        {
            MANGOS_ASSERT(index + 1 < m_valuesCount || PrintIndexError(index , false));
            return *((uint64*)&(m_uint32Values[ index ]));
        }

        float const& GetFloatValue(uint16 index) const
        {
            MANGOS_ASSERT(index < m_valuesCount || PrintIndexError(index , false));
            return m_floatValues[ index ];
        }

        uint8 GetByteValue(uint16 index, uint8 offset) const
        {
            MANGOS_ASSERT(index < m_valuesCount || PrintIndexError(index , false));
            MANGOS_ASSERT(offset < 4);
            return *(((uint8*)&m_uint32Values[ index ])+offset);
        }

        uint16 GetUInt16Value(uint16 index, uint8 offset) const
        {
            MANGOS_ASSERT(index < m_valuesCount || PrintIndexError(index , false));
            MANGOS_ASSERT(offset < 2);
            return *(((uint16*)&m_uint32Values[ index ])+offset);
        }

        ObjectGuid const& GetGuidValue(uint16 index) const { return *reinterpret_cast<ObjectGuid const*>(&GetUInt64Value(index)); }

        void SetInt32Value(uint16 index, int32  value);
        void SetUInt32Value(uint16 index, uint32  value);
        void SetUInt64Value(uint16 index, uint64 const& value);
        void SetFloatValue(uint16 index, float   value);
        void SetByteValue(uint16 index, uint8 offset, uint8 value);
        void SetUInt16Value(uint16 index, uint8 offset, uint16 value);
        void SetInt16Value(uint16 index, uint8 offset, int16 value) { SetUInt16Value(index,offset,(uint16)value); }
        void SetGuidValue(uint16 index, ObjectGuid const& value) { SetUInt64Value(index, value.GetRawValue()); }
        void SetStatFloatValue(uint16 index, float value);
        void SetStatInt32Value(uint16 index, int32 value);

        void ApplyModUInt32Value(uint16 index, int32 val, bool apply);
        void ApplyModInt32Value(uint16 index, int32 val, bool apply);
        void ApplyModPositiveFloatValue(uint16 index, float val, bool apply);
        void ApplyModSignedFloatValue(uint16 index, float val, bool apply);

        void ForceValuesUpdateAtIndex(uint16 index);
        void MarkUpdateFieldsWithFlagForUpdate(UpdateMask& updateMask, uint16 flag);

        void ApplyPercentModFloatValue(uint16 index, float val, bool apply)
        {
            val = val != -100.0f ? val : -99.9f ;
            SetFloatValue(index, GetFloatValue(index) * (apply?(100.0f+val)/100.0f : 100.0f / (100.0f+val)));
        }

        void SetFlag(uint16 index, uint32 newFlag);
        void RemoveFlag(uint16 index, uint32 oldFlag);

        void ToggleFlag(uint16 index, uint32 flag)
        {
            if (HasFlag(index, flag))
                RemoveFlag(index, flag);
            else
                SetFlag(index, flag);
        }

        bool HasFlag(uint16 index, uint32 flag) const
        {
            MANGOS_ASSERT(index < m_valuesCount || PrintIndexError(index , false));
            return (m_uint32Values[ index ] & flag) != 0;
        }

        void ApplyModFlag(uint16 index, uint32 flag, bool apply)
        {
            if (apply)
                SetFlag(index, flag);
            else
                RemoveFlag(index, flag);
        }

        void SetByteFlag(uint16 index, uint8 offset, uint8 newFlag);
        void RemoveByteFlag(uint16 index, uint8 offset, uint8 newFlag);

        void ToggleByteFlag(uint16 index, uint8 offset, uint8 flag)
        {
            if (HasByteFlag(index, offset, flag))
                RemoveByteFlag(index, offset, flag);
            else
                SetByteFlag(index, offset, flag);
        }

        bool HasByteFlag(uint16 index, uint8 offset, uint8 flag) const
        {
            MANGOS_ASSERT(index < m_valuesCount || PrintIndexError(index , false));
            MANGOS_ASSERT(offset < 4);
            return (((uint8*)&m_uint32Values[index])[offset] & flag) != 0;
        }

        void ApplyModByteFlag(uint16 index, uint8 offset, uint32 flag, bool apply)
        {
            if (apply)
                SetByteFlag(index, offset, flag);
            else
                RemoveByteFlag(index, offset, flag);
        }

        void SetShortFlag(uint16 index, bool highpart, uint16 newFlag);
        void RemoveShortFlag(uint16 index, bool highpart, uint16 oldFlag);

        void ToggleShortFlag(uint16 index, bool highpart, uint8 flag)
        {
            if (HasShortFlag(index, highpart, flag))
                RemoveShortFlag(index, highpart, flag);
            else
                SetShortFlag(index, highpart, flag);
        }

        bool HasShortFlag(uint16 index, bool highpart, uint8 flag) const
        {
            MANGOS_ASSERT(index < m_valuesCount || PrintIndexError(index , false));
            return (((uint16*)&m_uint32Values[index])[highpart ? 1 : 0] & flag) != 0;
        }

        void ApplyModShortFlag(uint16 index, bool highpart, uint32 flag, bool apply)
        {
            if (apply)
                SetShortFlag(index, highpart, flag);
            else
                RemoveShortFlag(index, highpart, flag);
        }

        void SetFlag64(uint16 index, uint64 newFlag)
        {
            uint64 oldval = GetUInt64Value(index);
            uint64 newval = oldval | newFlag;
            SetUInt64Value(index,newval);
        }

        void RemoveFlag64(uint16 index, uint64 oldFlag)
        {
            uint64 oldval = GetUInt64Value(index);
            uint64 newval = oldval & ~oldFlag;
            SetUInt64Value(index,newval);
        }

        void ToggleFlag64(uint16 index, uint64 flag)
        {
            if (HasFlag64(index, flag))
                RemoveFlag64(index, flag);
            else
                SetFlag64(index, flag);
        }

        bool HasFlag64(uint16 index, uint64 flag) const
        {
            MANGOS_ASSERT(index < m_valuesCount || PrintIndexError(index , false));
            return (GetUInt64Value(index) & flag) != 0;
        }

        void ApplyModFlag64(uint16 index, uint64 flag, bool apply)
        {
            if (apply)
                SetFlag64(index, flag);
            else
                RemoveFlag64(index, flag);
        }

        void ClearUpdateMask(bool remove);

        bool LoadValues(char const* data);

        uint16 GetValuesCount() const { return m_valuesCount; }

        void InitValues() { _InitValues(); }

        // Nostalrius
        bool IsDeleted() const { return _deleted; }

        // Convertions
        inline bool IsWorldObject() const { return isType(TYPEMASK_WORLDOBJECT); }
        WorldObject* ToWorldObject();
        WorldObject const* ToWorldObject() const;

        inline bool IsPlayer() const { return GetTypeId() == TYPEID_PLAYER; }
        Player* ToPlayer();
        Player const* ToPlayer() const;

        inline bool IsCreature() const { return GetTypeId() == TYPEID_UNIT; }
        Creature* ToCreature();
        Creature const* ToCreature() const;

        inline bool IsUnit() const { return isType(TYPEMASK_UNIT); }
        Unit* ToUnit();
        Unit const* ToUnit() const;

        inline bool IsGameObject() const { return GetTypeId() == TYPEID_GAMEOBJECT; }
        GameObject* ToGameObject();
        GameObject const* ToGameObject() const;

        inline bool IsSpellCaster() const { return IsUnit() || IsGameObject(); }
        SpellCaster* ToSpellCaster();
        SpellCaster const* ToSpellCaster() const;

        inline bool IsCorpse() const { return GetTypeId() == TYPEID_CORPSE; }
        Corpse* ToCorpse();
        Corpse const* ToCorpse() const;

        bool IsPet() const;
        Pet* ToPet();
        Pet const* ToPet() const;

        virtual bool HasQuest(uint32 /* quest_id */) const { return false; }
        virtual bool HasInvolvedQuest(uint32 /* quest_id */) const { return false; }
    protected:

        Object ();

        void _InitValues();
        void _Create (uint32 guidlow, uint32 entry, HighGuid guidhigh);

        uint16 GetUpdateFieldFlagsForTarget(Player const* target, uint16 const*& flags) const;
        void _SetCreateBits(UpdateMask& updateMask, Player* target) const;
        void _SetUpdateBits(UpdateMask& updateMask, Player* target) const;
        void _LoadIntoDataField(std::string const& data, uint32 startOffset, uint32 count);

        uint16 m_objectType;
        uint8 m_objectTypeId;
        uint8 m_updateFlag = 0;

        union
        {
            int32* m_int32Values;
            uint32* m_uint32Values;
            float* m_floatValues;
        };

        uint32* m_uint32Values_mirror;

        uint16 m_valuesCount;

        bool m_objectUpdated;
        bool _deleted;          // Object in remove list
        uint32 _delayedActions;

    private:
        bool m_inWorld;
        bool m_isNewObject;

        PackedGuid m_PackGUID;

        // for output helpfull error messages from ASSERTs
        bool PrintIndexError(uint32 index, bool set) const;
        Object(Object const&) = delete;                     // prevent generation copy constructor
        Object& operator=(Object const&) = delete;          // prevent generation assigment operator
};

struct WorldObjectChangeAccumulator;

class WorldObject : public Object
{
    friend struct WorldObjectChangeAccumulator;

    public:

        //class is used to manipulate with WorldUpdateCounter
        //it is needed in order to get time diff between two object's Update() calls
        class UpdateHelper
        {
            public:
                explicit UpdateHelper(WorldObject* obj) : m_obj(obj) {}
                ~UpdateHelper() { }

                void Update(uint32 time_diff)
                {
                    m_obj->Update(m_obj->m_updateTracker.timeElapsed(), time_diff);
                    m_obj->m_updateTracker.Reset();
                }

                void UpdateRealTime(uint32 now, uint32 time_diff)
                {
                    m_obj->Update(m_obj->m_updateTracker.timeElapsed(now), time_diff);
                    m_obj->m_updateTracker.ResetTo(now);
                }

            private:
                UpdateHelper(UpdateHelper const&);
                UpdateHelper& operator=(UpdateHelper const&) = delete;

                WorldObject* const m_obj;
        };

        ~WorldObject () override {}

        virtual void Update(uint32 /*update_diff*/, uint32 /*time_diff*/);

        void _Create(uint32 guidlow, HighGuid guidhigh);

        void Relocate(float x, float y, float z, float orientation);
        void Relocate(float x, float y, float z);

        void SetOrientation(float orientation);

        void SetRawPosition(Position&& pos) { m_position = std::move(pos); }
        Position const& GetPosition() const { return m_position; }
        float GetPositionX() const { return m_position.x; }
        float GetPositionY() const { return m_position.y; }
        float GetPositionZ() const { return m_position.z; }
        virtual void GetSafePosition(float &x, float &y, float &z, GenericTransport* onTransport = nullptr) const { GetPosition(x, y, z, onTransport); }
        void GetPosition(float &x, float &y, float &z, GenericTransport* onTransport = nullptr) const;
        void GetPosition(WorldLocation &loc) const { loc.mapId = m_mapId; GetPosition(loc.x, loc.y, loc.z); loc.o = GetOrientation(); }
        float GetOrientation() const { return m_position.o; }
        void GetNearPoint2D(float &x, float &y, float distance, float absAngle) const
        {
            GetNearPoint2DAroundPosition(GetPositionX(), GetPositionY(), x, y, distance, absAngle);
        }
        void GetNearPoint2DAroundPosition(float ownX, float ownY, float &x, float &y, float distance, float absAngle) const;
        void GetNearPoint(WorldObject const* searcher, float &x, float &y, float &z, float searcher_bounding_radius, float distance2d, float absAngle) const;
        // x, y, z should be initialized to the position you want to search around
        void GetNearPointAroundPosition(WorldObject const* searcher, float &x, float &y, float &z, float searcher_bounding_radius, float distance2d, float absAngle) const;
        void GetClosePoint(float &x, float &y, float &z, float bounding_radius, float distance2d = 0, float angle = 0, WorldObject const* obj = nullptr) const
        {
            // angle calculated from current orientation
            GetNearPoint(obj, x, y, z, bounding_radius, distance2d, GetOrientation() + angle);
        }
        void GetContactPoint(WorldObject const* obj, float &x, float &y, float &z, float distance2d = CONTACT_DISTANCE) const
        {
            // Nostalrius: On est deja au contact !
            if (GetDistance2d(obj) < distance2d)
            {
                obj->GetPosition(x, y, z);
                return;
            }
            // angle to face `obj` to `this` using distance includes size of `obj`
            GetNearPoint(obj, x, y, z, obj->GetObjectBoundingRadius(), distance2d, GetAngle(obj));
        }
        virtual float GetObjectBoundingRadius() const { return DEFAULT_WORLD_OBJECT_SIZE; }
        virtual float GetCombatReach() const { return 0.f; }

        bool IsPositionValid() const;
        void UpdateGroundPositionZ(float x, float y, float &z) const;
        void UpdateAllowedPositionZ(float x, float y, float &z) const;

        // Valeur de retour : false si aucun point correct trouve.
        bool GetRandomPoint(float x, float y, float z, float distance, float &rand_x, float &rand_y, float &rand_z) const;

        uint32 GetMapId() const { return m_mapId; }
        uint32 GetInstanceId() const { return m_InstanceId; }

        uint32 GetZoneId() const;
        uint32 GetAreaId() const;
        void GetZoneAndAreaId(uint32& zoneid, uint32& areaid) const;
        void LoadMapCellsAround(float dist) const;

        InstanceData* GetInstanceData() const;

        char const* GetName() const { return m_name.c_str(); }
        void SetName(std::string const& newname) { m_name=newname; }

        virtual char const* GetNameForLocaleIdx(int32 /*locale_idx*/) const { return GetName(); }
        virtual uint8 GetGender() const { return 0; } // used in chat builder

        virtual uint32 GetDefaultGossipMenuId() const { return 0; }

        float GetCombatDistance(WorldObject const* target) const;
        float GetDistance2dToCenter(WorldObject const* target) const;
        float GetDistance2dToCenter(float x, float y) const;
        float GetDistance2dToCenter(WorldLocation const& position) const { return GetDistance2dToCenter(position.x, position.y); }
        float GetDistance2dToCenter(Position const& position) const { return GetDistance2dToCenter(position.x, position.y); }
        float GetDistance3dToCenter(WorldObject const* target) const;
        float GetDistance3dToCenter(float x, float y, float z) const;
        float GetDistance3dToCenter(WorldLocation const& position) const { return GetDistance3dToCenter(position.x, position.y, position.z); }
        float GetDistance3dToCenter(Position const& position) const { return GetDistance3dToCenter(position.x, position.y, position.z); }
        float GetDistance(WorldObject const* obj) const;
        float GetDistance(float x, float y, float z) const;
        float GetDistance(WorldLocation const& position) const { return GetDistance(position.x, position.y, position.z); }
        float GetDistance(Position const& position) const { return GetDistance(position.x, position.y, position.z); }
        float GetDistance2d(WorldObject const* obj) const;
        float GetDistance2d(float x, float y) const;
        float GetDistance2d(WorldLocation const& position) const { return GetDistance2d(position.x, position.y); }
        float GetDistance2d(Position const& position) const { return GetDistance2d(position.x, position.y); }
        float GetDistanceZ(WorldObject const* obj) const;
        float GetDistanceSqr(float x, float y, float z) const;
        bool IsInMap(WorldObject const* obj) const;
        template <class T>
        bool IsWithinDist3d(T const& position, float dist2compare) const { return IsWithinDist3d(position.x, position.y, position.z, dist2compare); }
        bool IsWithinDist3d(float x, float y, float z, float dist2compare) const;
        template <class T >
        bool IsWithinDist2d(T const& position, float dist2compare) const { return IsWithinDist2d(position.x, position.y, dist2compare); }
        bool IsWithinDist2d(float x, float y, float dist2compare) const;
        bool _IsWithinDist(WorldObject const* obj, float dist2compare, bool is3D, bool useBoundingRadius = true) const;

        // use only if you will sure about placing both object at same map
        bool IsWithinDist(WorldObject const* obj, float dist2compare, bool is3D = true, bool useBoundingRadius = true) const
        {
            return obj && _IsWithinDist(obj, dist2compare, is3D, useBoundingRadius);
        }

        bool IsWithinDistInMap(WorldObject const* obj, float dist2compare, bool is3D = true, bool useBoundingRadius = true) const
        {
            return obj && IsInMap(obj) && _IsWithinDist(obj,dist2compare,is3D, useBoundingRadius);
        }
        bool IsWithinCombatDistInMap(WorldObject const* obj, float dist2compare) const
        {
            return obj && IsInMap(obj) && (GetCombatDistance(obj) <= dist2compare);
        }
        bool IsWithinLOS(float targetX, float targetY, float targetZ, bool checkDynLos = true, float targetHeight = 2.f) const
        {
            return IsWithinLOSAtPosition(GetPositionX(), GetPositionY(), GetPositionZ(), targetX, targetY, targetZ, checkDynLos, targetHeight);
        }
        bool IsWithinLOSAtPosition(float ownX, float ownY, float ownZ, float targetX, float targetY, float targetZ, bool checkDynLos = true, float targetHeight = 2.f) const;
        bool IsWithinLOSInMap(WorldObject const* obj, bool checkDynLos = true) const;
        bool GetDistanceOrder(WorldObject const* obj1, WorldObject const* obj2, bool is3D = true) const;
        bool IsInRange(WorldObject const* obj, float minRange, float maxRange, bool is3D = true) const;
        bool IsInRange2d(float x, float y, float minRange, float maxRange) const;
        bool IsInRange3d(float x, float y, float z, float minRange, float maxRange) const;

        float GetAngle(WorldObject const* obj) const;
        float GetAngle(float const x, float const y) const;
        bool HasInArc(WorldObject const* target, float const arcangle = M_PI, float offset = 0.0f) const;
        bool HasInArc(float const arcangle, float const x, float const y) const;
        bool isInFrontInMap(WorldObject const* target,float distance, float arc = M_PI) const;
        bool isInBackInMap(WorldObject const* target, float distance, float arc = M_PI) const;
        bool isInFront(WorldObject const* target,float distance, float arc = M_PI) const;
        bool isInBack(WorldObject const* target, float distance, float arc = M_PI) const;

        bool CanReachWithMeleeSpellAttack(WorldObject const* pVictim, float flat_mod = 0.0f) const;
        float GetLeewayBonusRange(Unit const* target, bool ability) const;
        static float GetLeewayBonusRangeForTargets(Player const* player, Unit const* target, bool ability);
        float GetLeewayBonusRadius() const;

        // Gestion des positions
        void GetRelativePositions(float fForwardBackward, float fLeftRight, float fUpDown, float &x, float &y, float &z);
        void GetInCirclePositions(float dist, uint32 curr, uint32 total, float &x, float &y, float &z, float &o);
        void GetNearRandomPositions(float distance, float &x, float &y, float &z);
        void GetFirstCollision(float dist, float angle, float &x, float &y, float &z);

        // for use only in LoadHelper, Map::Add Map::CreatureCellRelocation
        Cell const& GetCurrentCell() const { return m_currentCell; }
        void SetCurrentCell(Cell const& cell) { m_currentCell = cell; }

        // Transports / Movement
        GenericTransport* GetTransport() const { return m_transport; }
        virtual void SetTransport(GenericTransport* t) { m_transport = t; }

        float GetTransOffsetX() const { return m_movementInfo.GetTransportPos().x; }
        float GetTransOffsetY() const { return m_movementInfo.GetTransportPos().y; }
        float GetTransOffsetZ() const { return m_movementInfo.GetTransportPos().z; }
        float GetTransOffsetO() const { return m_movementInfo.GetTransportPos().o; }
        uint32 GetTransTime() const { return m_movementInfo.GetTransportTime(); }

        void AddUnitMovementFlag(uint32 f) { m_movementInfo.moveFlags |= f; }
        void RemoveUnitMovementFlag(uint32 f) { m_movementInfo.moveFlags &= ~f; }
        bool HasUnitMovementFlag(uint32 f) const { return (m_movementInfo.moveFlags & f) == f; }
        uint32 GetUnitMovementFlags() const { return m_movementInfo.moveFlags; }
        void SetUnitMovementFlags(uint32 f) { m_movementInfo.moveFlags = f; }

        bool IsLevitating() const { return m_movementInfo.HasMovementFlag(MOVEFLAG_LEVITATING); }
        bool IsFlying() const { return m_movementInfo.HasMovementFlag(MOVEFLAG_FLYING); }
        bool IsWalking() const { return m_movementInfo.HasMovementFlag(MOVEFLAG_WALK_MODE); }
        bool IsWalkingBackward() const { return m_movementInfo.HasMovementFlag(MOVEFLAG_BACKWARD); }
        bool IsMoving() const { return m_movementInfo.HasMovementFlag(MOVEFLAG_MASK_MOVING); }
        bool IsSwimming() const { return m_movementInfo.HasMovementFlag(MOVEFLAG_SWIMMING); }
        bool IsMovingButNotWalking() const { return IsMoving() && !(IsWalking() || IsWalkingBackward()); }

        MovementInfo m_movementInfo;
        GenericTransport* m_transport;

        virtual void CleanupsBeforeDelete();                // used in destructor or explicitly before mass creature delete to remove cross-references to already deleted units

        // Send to players
        virtual void SendMessageToSet(WorldPacket* data, bool self) const;
        // Send to players who have object at client
        void SendObjectMessageToSet(WorldPacket* data, bool self, WorldObject const* except = nullptr) const;
        void SendMovementMessageToSet(WorldPacket data, bool self, WorldObject const* except = nullptr);

        virtual void SendMessageToSetInRange(WorldPacket* data, float dist, bool self) const;
        void SendMessageToSetExcept(WorldPacket* data, Player const* skipped_receiver) const;
        void DirectSendPublicValueUpdate(uint32 index);

        void PlayDistanceSound(uint32 sound_id, Player const* target = nullptr) const;
        void PlayDirectSound(uint32 sound_id, Player const* target = nullptr) const;
        void PlayDirectMusic(uint32 music_id, Player const* target = nullptr) const;

        void PMonsterSay(char const* text, ...) const;
        void PMonsterSay(int32 text, ...) const;
        void PMonsterYell(char const* text, ...) const;
        void PMonsterYell(int32 text, ...) const;

        void MonsterSay(char const* text, uint32 language = 0, Unit const* target = nullptr) const;
        void MonsterYell(char const* text, uint32 language = 0, Unit const* target = nullptr) const;
        void MonsterTextEmote(char const* text, Unit const* target = nullptr, bool IsBossEmote = false) const;
        void MonsterWhisper(char const* text, Unit const* target = nullptr, bool IsBossWhisper = false) const;
        void MonsterSay(int32 textId, uint32 language = 0, Unit const* target = nullptr) const;
        void MonsterYell(int32 textId, uint32 language = 0, Unit const* target = nullptr) const;
        void MonsterTextEmote(int32 textId, Unit const* target = nullptr, bool IsBossEmote = false) const;
        void MonsterWhisper(int32 textId, Unit const* receiver, bool IsBossWhisper = false) const;
        void MonsterYellToZone(int32 textId, uint32 language = 0, Unit const* target = nullptr) const;
        void MonsterScriptToZone(int32 textId, ChatMsg type, uint32 language = 0, Unit const* target = nullptr) const;

        void SendObjectSpawnAnim() const;
        void SendObjectDeSpawnAnim() const;
        
        bool IsControlledByPlayer() const;
        bool IsLikePlayer() const;
        virtual Player* GetAffectingPlayer() const { return nullptr; }
        virtual bool IsCharmerOrOwnerPlayerOrPlayerItself() const { return IsPlayer(); }
        virtual bool IsHostileTo(WorldObject const* target) const = 0;
        virtual bool IsFriendlyTo(WorldObject const* target) const = 0;
        FactionTemplateEntry const* getFactionTemplateEntry() const;
        virtual uint32 GetFactionTemplateId() const = 0;
        virtual ReputationRank GetReactionTo(WorldObject const* target) const;
        ReputationRank static GetFactionReactionTo(FactionTemplateEntry const* factionTemplateEntry, WorldObject const* target);
        bool IsValidAttackTarget(Unit const* target, bool checkAlive = true) const;

        virtual void SaveRespawnTime() {}
        void AddObjectToRemoveList();
        void DeleteLater() { AddDelayedAction(OBJECT_DELAYED_ADD_TO_REMOVE_LIST); }
        virtual void DestroyForNearbyPlayers();

        void UpdateObjectVisibility();
        virtual void UpdateVisibilityAndView();             // update visibility for object and object for all around

        // main visibility check function in normal case (ignore grey zone distance check)
        bool isWithinVisibilityDistanceOf(Unit const* viewer, WorldObject const* viewpoint, bool inVisibleList = false) const;
        bool isVisibleFor(Player const* u, WorldObject const* viewPoint) const;

        // low level function for visibility change code, must be define in all main world object subclasses
        virtual bool IsVisibleForInState(WorldObject const* pDetector, WorldObject const* viewPoint, bool inVisibleList) const = 0;
        virtual bool IsVisibleForOrDetect(WorldObject const* pDetector, WorldObject const* viewPoint, bool detect, bool inVisibleList = false, bool* alert = nullptr) const { return IsVisibleForInState(pDetector, viewPoint, inVisibleList); }

        void SetMap(Map* map);
        Map* GetMap() const;
        Map* FindMap() const { return m_currMap; }

        //used to check all object's GetMap() calls when object is not in world!
        void ResetMap();

        //obtain terrain data for map where this object belong...
        TerrainInfo const* GetTerrain() const;

        void SetZoneScript();
        ZoneScript* GetZoneScript() const { return m_zoneScript; }

        void AddToClientUpdateList() override;
        void RemoveFromClientUpdateList() override;
        void BuildUpdateData(UpdateDataMapType &) override;

        Creature* SummonCreature(uint32 id, float x, float y, float z, float ang,TempSummonType spwtype = TEMPSUMMON_DEAD_DESPAWN,uint32 despwtime = 25000, bool asActiveObject = false, uint32 pacifiedTimer = 0, CreatureAiSetter pFuncAiSetter = nullptr, GenericTransport* pTransport = nullptr);
        GameObject* SummonGameObject(uint32 entry, float x, float y, float z, float ang, float rotation0 = 0.0f, float rotation1 = 0.0f, float rotation2 = 0.0f, float rotation3 = 0.0f, uint32 respawnTime = 25000, bool attach = true);

        Creature* FindNearestCreature(uint32 entry, float range, bool alive = true, Creature const* except = nullptr) const;
        Creature* FindRandomCreature(uint32 entry, float range, bool alive = true, Creature const* except = nullptr) const;
        GameObject* FindNearestGameObject(uint32 entry, float range) const;
        GameObject* FindRandomGameObject(uint32 entry, float range) const;
        Player* FindNearestPlayer(float range) const;
        void GetGameObjectListWithEntryInGrid(std::list<GameObject*>& lList, uint32 uiEntry, float fMaxSearchRange) const;
        void GetCreatureListWithEntryInGrid(std::list<Creature*>& lList, uint32 uiEntry, float fMaxSearchRange) const;
        void GetAlivePlayerListInRange(WorldObject const* pSource, std::list<Player*>& lList, float fMaxSearchRange) const;

        bool isActiveObject() const { return m_isActiveObject || m_viewPoint.hasViewers(); }
        void SetActiveObjectState(bool on);

        ViewPoint& GetViewPoint() { return m_viewPoint; }

        // WorldMask
        uint32 worldMask;
        virtual void SetWorldMask(uint32 newMask);
        uint32 GetWorldMask() const { return worldMask; }
        // Visibilite
        bool CanSeeInWorld(WorldObject const* other)  const;
        bool CanSeeInWorld(uint32 otherPhase)  const;

        // ASSERT print helper
        bool PrintCoordinatesError(float x, float y, float z, char const* descr) const;

        //these functions are used mostly for Relocate() and Corpse/Player specific stuff...
        //use them ONLY in LoadFromDB()/Create() funcs and nowhere else!
        //mapId/instanceId should be set in SetMap() function!
        void SetLocationMapId(uint32 mapId) { m_mapId = mapId; }
        void SetLocationInstanceId(uint32 _instanceId) { m_InstanceId = _instanceId; }

        bool IsWithinLootXPDist(WorldObject const* objToLoot) const;

        float GetVisibilityModifier() const;
        void SetVisibilityModifier(float f);

        uint32 GetCreatureSummonCount() const;
        void DecrementSummonCounter();
        void IncrementSummonCounter();

        uint32 GetCreatureSummonLimit() const;
        void SetCreatureSummonLimit(uint32 limit);

    protected:
        explicit WorldObject();

        std::string m_name;
        ZoneScript* m_zoneScript;
        bool m_isActiveObject;
        // Extra visibility distance for this unit, only used if it is an active object.
        // c.f. GetVisibilityModifier(). Be very conservative using this - a large
        // draw distance can be expensive for updates with lots of players
        float m_visibilityModifier;

        Map* m_currMap;                                     //current object's Map location

        uint32 m_mapId;                                     // object at map with map_id
        uint32 m_InstanceId;                                // in map copy with instance id

        Position m_position;
        Cell m_currentCell;                                 // store current cell where object listed

        ViewPoint m_viewPoint;

        WorldUpdateCounter m_updateTracker;

        uint32 m_summonLimitAlert;                          // Timer to alert GMs if a creature is at the summon limit
};

inline WorldObject* Object::ToWorldObject()
{
    return IsWorldObject() ? static_cast<WorldObject*>(this) : nullptr;
}

inline WorldObject const* Object::ToWorldObject() const
{
    return IsWorldObject() ? static_cast<WorldObject const*>(this) : nullptr;
}

// Helper functions to cast between different Object pointers. Useful when unsure that your object* is valid at all.
inline WorldObject* ToWorldObject(Object* object)
{
    return object && object->IsWorldObject() ? static_cast<WorldObject*>(object) : nullptr;
}

inline WorldObject const* ToWorldObject(Object const* object)
{
    return object && object->IsWorldObject() ? static_cast<WorldObject const*>(object) : nullptr;
}

#endif
