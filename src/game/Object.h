/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef _OBJECT_H
#define _OBJECT_H

#include "Common.h"
#include "UpdateFields.h"
#include "UpdateData.h"
#include "GameSystem/GridReference.h"
#include "ObjectDefines.h"
#include "GridDefines.h"
#include "Map.h"

#include <set>
#include <string>

#define CONTACT_DISTANCE            0.5f
#define INTERACTION_DISTANCE        5.0f
#define ATTACK_DISTANCE             5.0f
#define MAX_VISIBILITY_DISTANCE 333.0f // max distance for visible object show, limited in 333 yards
#define DEFAULT_VISIBILITY_DISTANCE 90.0f // default visible distance, 90 yards on continents
#define DEFAULT_VISIBILITY_INSTANCE 120.0f // default visible distance in instances, 120 yards
#define DEFAULT_VISIBILITY_BGARENAS 180.0f // default visible distance in BG/Arenas, 180 yards

#define DEFAULT_WORLD_OBJECT_SIZE   0.388999998569489f      // player size, also currently used (correctly?) for any non Unit world objects
#define DEFAULT_COMBAT_REACH        1.5f
#define MIN_MELEE_REACH             2.0f
#define NOMINAL_MELEE_RANGE         5.0f
#define MELEE_RANGE                 (NOMINAL_MELEE_RANGE - MIN_MELEE_REACH * 2) //center to center for players

enum TypeMask
{
    TYPEMASK_OBJECT         = 0x0001,
    TYPEMASK_ITEM           = 0x0002,
    TYPEMASK_CONTAINER      = 0x0006,                       // TYPEMASK_ITEM | 0x0004
    TYPEMASK_UNIT           = 0x0008,   //creature or player
    TYPEMASK_PLAYER         = 0x0010,
    TYPEMASK_GAMEOBJECT     = 0x0020,
    TYPEMASK_DYNAMICOBJECT  = 0x0040,
    TYPEMASK_CORPSE         = 0x0080,
    TYPEMASK_SEER           = TYPEMASK_UNIT | TYPEMASK_DYNAMICOBJECT
};

enum TypeID
{
    TYPEID_OBJECT        = 0,
    TYPEID_ITEM          = 1,
    TYPEID_CONTAINER     = 2,
    TYPEID_UNIT          = 3,
    TYPEID_PLAYER        = 4,
    TYPEID_GAMEOBJECT    = 5,
    TYPEID_DYNAMICOBJECT = 6,
    TYPEID_CORPSE        = 7
};

#define NUM_CLIENT_OBJECT_TYPES             8

uint32 GuidHigh2TypeId(uint32 guid_hi);

enum TempSummonType
{
    TEMPSUMMON_TIMED_OR_DEAD_DESPAWN       = 1,             // despawns after a specified time OR when the creature disappears
    TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN     = 2,             // despawns after a specified time OR when the creature dies
    TEMPSUMMON_TIMED_DESPAWN               = 3,             // despawns after a specified time
    TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT = 4,             // despawns after a specified time after the creature is out of combat
    TEMPSUMMON_CORPSE_DESPAWN              = 5,             // despawns instantly after death
    TEMPSUMMON_CORPSE_TIMED_DESPAWN        = 6,             // despawns after a specified time after death
    TEMPSUMMON_DEAD_DESPAWN                = 7,             // despawns when the creature disappears
    TEMPSUMMON_MANUAL_DESPAWN              = 8              // despawns when UnSummon() is called
};

enum PhaseMasks
{
    PHASEMASK_NORMAL   = 0x00000001,
    PHASEMASK_ANYWHERE = 0xFFFFFFFF
};

enum NotifyFlags
{
    NOTIFY_NONE                     = 0x00,
    NOTIFY_AI_RELOCATION            = 0x01,
    NOTIFY_VISIBILITY_CHANGED       = 0x02,
    NOTIFY_ALL                      = 0xFF
};

class WorldPacket;
class UpdateData;
class ByteBuffer;
class WorldSession;
class Creature;
class Player;
class UpdateMask;
class InstanceData;
class GameObject;
class TempSummon;
class Vehicle;
class CreatureAI;
class ZoneScript;
class Unit;

typedef UNORDERED_MAP<Player*, UpdateData> UpdateDataMapType;

class Object
{
    public:
        virtual ~Object ( );

        const bool IsInWorld() const { return m_inWorld; }
        virtual void AddToWorld()
        {
            if(m_inWorld)
                return;

            assert(m_uint32Values);

            m_inWorld = true;

            // synchronize values mirror with values array (changes will send in updatecreate opcode any way
            ClearUpdateMask(true);
        }
        virtual void RemoveFromWorld()
        {
            if(!m_inWorld)
                return;

            m_inWorld = false;

            // if we remove from world then sending changes not required
            ClearUpdateMask(true);
        }

        const uint64& GetGUID() const { return GetUInt64Value(0); }
        uint32 GetGUIDLow() const { return GUID_LOPART(GetUInt64Value(0)); }
        uint32 GetGUIDMid() const { return GUID_ENPART(GetUInt64Value(0)); }
        uint32 GetGUIDHigh() const { return GUID_HIPART(GetUInt64Value(0)); }
        const ByteBuffer& GetPackGUID() const { return m_PackGUID; }
        uint32 GetEntry() const { return GetUInt32Value(OBJECT_FIELD_ENTRY); }
        void SetEntry(uint32 entry) { SetUInt32Value(OBJECT_FIELD_ENTRY, entry); }

        TypeID GetTypeId() const { return m_objectTypeId; }
        bool isType(uint16 mask) const { return (mask & m_objectType); }

        virtual void BuildCreateUpdateBlockForPlayer( UpdateData *data, Player *target ) const;
        void SendUpdateToPlayer(Player* player);

        void BuildValuesUpdateBlockForPlayer( UpdateData *data, Player *target ) const;
        void BuildOutOfRangeUpdateBlock( UpdateData *data ) const;
        void BuildMovementUpdateBlock( UpdateData * data, uint32 flags = 0 ) const;

        virtual void DestroyForPlayer( Player *target, bool anim = false ) const;

        const int32& GetInt32Value( uint16 index ) const
        {
            ASSERT( index < m_valuesCount || PrintIndexError( index , false) );
            return m_int32Values[ index ];
        }

        const uint32& GetUInt32Value( uint16 index ) const
        {
            ASSERT( index < m_valuesCount || PrintIndexError( index , false) );
            return m_uint32Values[ index ];
        }

        const uint64& GetUInt64Value( uint16 index ) const
        {
            ASSERT( index + 1 < m_valuesCount || PrintIndexError( index , false) );
            return *((uint64*)&(m_uint32Values[ index ]));
        }

        const float& GetFloatValue( uint16 index ) const
        {
            ASSERT( index < m_valuesCount || PrintIndexError( index , false ) );
            return m_floatValues[ index ];
        }

        uint8 GetByteValue( uint16 index, uint8 offset) const
        {
            ASSERT( index < m_valuesCount || PrintIndexError( index , false) );
            ASSERT( offset < 4 );
            return *(((uint8*)&m_uint32Values[ index ])+offset);
        }

        uint16 GetUInt16Value( uint16 index, uint8 offset) const
        {
            ASSERT( index < m_valuesCount || PrintIndexError( index , false) );
            ASSERT( offset < 2 );
            return *(((uint16*)&m_uint32Values[ index ])+offset);
        }

        void SetInt32Value(  uint16 index,        int32  value );
        void SetUInt32Value( uint16 index,       uint32  value );
        void UpdateUInt32Value( uint16 index,       uint32  value );
        void SetUInt64Value( uint16 index, const uint64 &value );
        void SetFloatValue(  uint16 index,       float   value );
        void SetByteValue(   uint16 index, uint8 offset, uint8 value );
        void SetUInt16Value( uint16 index, uint8 offset, uint16 value );
        void SetInt16Value(  uint16 index, uint8 offset, int16 value ) { SetUInt16Value(index,offset,(uint16)value); }
        void SetStatFloatValue( uint16 index, float value);
        void SetStatInt32Value( uint16 index, int32 value);

        bool AddUInt64Value( uint16 index, const uint64 &value );
        bool RemoveUInt64Value( uint16 index, const uint64 &value );

        void ApplyModUInt32Value(uint16 index, int32 val, bool apply);
        void ApplyModInt32Value(uint16 index, int32 val, bool apply);
        void ApplyModUInt64Value(uint16 index, int32 val, bool apply);
        void ApplyModPositiveFloatValue( uint16 index, float val, bool apply);
        void ApplyModSignedFloatValue( uint16 index, float val, bool apply);

        void ApplyPercentModFloatValue(uint16 index, float val, bool apply)
        {
            val = val != -100.0f ? val : -99.9f ;
            SetFloatValue(index, GetFloatValue(index) * (apply?(100.0f+val)/100.0f : 100.0f / (100.0f+val)) );
        }

        void SetFlag( uint16 index, uint32 newFlag );
        void RemoveFlag( uint16 index, uint32 oldFlag );

        void ToggleFlag( uint16 index, uint32 flag)
        {
            if(HasFlag(index, flag))
                RemoveFlag(index, flag);
            else
                SetFlag(index, flag);
        }

        bool HasFlag( uint16 index, uint32 flag ) const
        {
            if( index >= m_valuesCount && !PrintIndexError( index , false ) ) return false;
            return (m_uint32Values[ index ] & flag) != 0;
        }

        void SetByteFlag( uint16 index, uint8 offset, uint8 newFlag );
        void RemoveByteFlag( uint16 index, uint8 offset, uint8 newFlag );

        void ToggleFlag( uint16 index, uint8 offset, uint8 flag )
        {
            if(HasByteFlag(index, offset, flag))
                RemoveByteFlag(index, offset, flag);
            else
                SetByteFlag(index, offset, flag);
        }

        bool HasByteFlag( uint16 index, uint8 offset, uint8 flag ) const
        {
            ASSERT( index < m_valuesCount || PrintIndexError( index , false ) );
            ASSERT( offset < 4 );
            return (((uint8*)&m_uint32Values[index])[offset] & flag) != 0;
        }

        void ApplyModFlag( uint16 index, uint32 flag, bool apply)
        {
            if(apply) SetFlag(index,flag); else RemoveFlag(index,flag);
        }

        void SetFlag64( uint16 index, uint64 newFlag )
        {
            uint64 oldval = GetUInt64Value(index);
            uint64 newval = oldval | newFlag;
            SetUInt64Value(index,newval);
        }

        void RemoveFlag64( uint16 index, uint64 oldFlag )
        {
            uint64 oldval = GetUInt64Value(index);
            uint64 newval = oldval & ~oldFlag;
            SetUInt64Value(index,newval);
        }

        void ToggleFlag64( uint16 index, uint64 flag)
        {
            if(HasFlag64(index, flag))
                RemoveFlag64(index, flag);
            else
                SetFlag64(index, flag);
        }

        bool HasFlag64( uint16 index, uint64 flag ) const
        {
            ASSERT( index < m_valuesCount || PrintIndexError( index , false ) );
            return (GetUInt64Value( index ) & flag) != 0;
        }

        void ApplyModFlag64( uint16 index, uint64 flag, bool apply)
        {
            if(apply) SetFlag64(index,flag); else RemoveFlag64(index,flag);
        }

        void ClearUpdateMask(bool remove);

        bool LoadValues(const char* data);

        uint16 GetValuesCount() const { return m_valuesCount; }

        virtual bool hasQuest(uint32 /* quest_id */) const { return false; }
        virtual bool hasInvolvedQuest(uint32 /* quest_id */) const { return false; }
        virtual void BuildUpdate(UpdateDataMapType& ) {}
        void BuildFieldsUpdate(Player *, UpdateDataMapType &) const;

        // FG: some hacky helpers
        void ForceValuesUpdateAtIndex(uint32);

	Player* ToPlayer(){ if(GetTypeId() == TYPEID_PLAYER)  return reinterpret_cast<Player*>(this); else return NULL;  }
	const Player* ToPlayer() const { if(GetTypeId() == TYPEID_PLAYER)  return (const Player*)((Player*)this); else return NULL;  }
	Creature* ToCreature(){ if(GetTypeId() == TYPEID_UNIT) return reinterpret_cast<Creature*>(this); else return NULL; }
	const Creature* ToCreature() const {if(GetTypeId() == TYPEID_UNIT) return (const Creature*)((Creature*)this); else return NULL; }

    protected:

        Object ( );

        void _InitValues();
        void _Create (uint32 guidlow, uint32 entry, HighGuid guidhigh);

        virtual void _SetUpdateBits(UpdateMask *updateMask, Player *target) const;

        virtual void _SetCreateBits(UpdateMask *updateMask, Player *target) const;
        void _BuildMovementUpdate(ByteBuffer * data, uint16 flags) const;
        void _BuildValuesUpdate(uint8 updatetype, ByteBuffer *data, UpdateMask *updateMask, Player *target ) const;

        uint16 m_objectType;

        TypeID m_objectTypeId;
        uint16 m_updateFlag;

        union
        {
            int32  *m_int32Values;
            uint32 *m_uint32Values;
            float  *m_floatValues;
        };

        uint32 *m_uint32Values_mirror;

        uint16 m_valuesCount;

        bool m_objectUpdated;

    private:
        bool m_inWorld;

        ByteBuffer m_PackGUID;

        // for output helpfull error messages from asserts
        bool PrintIndexError(uint32 index, bool set) const;
        Object(const Object&);                              // prevent generation copy constructor
        Object& operator=(Object const&);                   // prevent generation assigment operator
};

struct Position
{
    float m_positionX;
    float m_positionY;
    float m_positionZ;
    float m_orientation;

    void Relocate(float x, float y)
        { m_positionX = x; m_positionY = y;}
    void Relocate(float x, float y, float z)
        { m_positionX = x; m_positionY = y; m_positionZ = z; }
    void Relocate(float x, float y, float z, float orientation)
        { m_positionX = x; m_positionY = y; m_positionZ = z; m_orientation = orientation; }
    void Relocate(const Position &pos)
        { m_positionX = pos.m_positionX; m_positionY = pos.m_positionY; m_positionZ = pos.m_positionZ; m_orientation = pos.m_orientation; }
    void Relocate(const Position *pos)
        { m_positionX = pos->m_positionX; m_positionY = pos->m_positionY; m_positionZ = pos->m_positionZ; m_orientation = pos->m_orientation; }
    void SetOrientation(float orientation)
        { m_orientation = orientation; }

    float GetPositionX() const { return m_positionX; }
    float GetPositionY() const { return m_positionY; }
    float GetPositionZ() const { return m_positionZ; }
    float GetOrientation() const { return m_orientation; }

    void GetPosition(float &x, float &y) const
        { x = m_positionX; y = m_positionY; }
    void GetPosition(float &x, float &y, float &z) const
        { x = m_positionX; y = m_positionY; z = m_positionZ; }
    void GetPosition(float &x, float &y, float &z, float &o) const
        { x = m_positionX; y = m_positionY; z = m_positionZ; o = m_orientation; }
    void GetPosition(Position *pos) const
    { 
        if (pos) 
            pos->Relocate(m_positionX, m_positionY, m_positionZ, m_orientation); 
    }

    bool IsPositionValid() const;

    float GetExactDist2dSq(float x, float y) const
        { float dx = m_positionX - x; float dy = m_positionY - y; return dx*dx + dy*dy; }
    float GetExactDist2d(const float x, const float y) const
        { return sqrt(GetExactDist2dSq(x, y)); }
    float GetExactDist2dSq(const Position *pos) const
        { float dx = m_positionX - pos->m_positionX; float dy = m_positionY - pos->m_positionY; return dx*dx + dy*dy; }
    float GetExactDist2d(const Position *pos) const
        { return sqrt(GetExactDist2dSq(pos)); }
    float GetExactDistSq(float x, float y, float z) const
        { float dz = m_positionZ - z; return GetExactDist2dSq(x, y) + dz*dz; }
    float GetExactDist(float x, float y, float z) const
        { return sqrt(GetExactDistSq(x, y, z)); }
    float GetExactDistSq(const Position *pos) const
        { float dx = m_positionX - pos->m_positionX; float dy = m_positionY - pos->m_positionY; float dz = m_positionZ - pos->m_positionZ; return dx*dx + dy*dy + dz*dz; }
    float GetExactDist(const Position *pos) const
        { return sqrt(GetExactDistSq(pos)); }

    float GetAngle(const Position *pos) const;
    float GetAngle(float x, float y) const;
    float GetRelativeAngle(const Position *pos) const 
        { return GetAngle(pos) - m_orientation; }
    float GetRelativeAngle(float x, float y) const { return GetAngle(x, y) - m_orientation; }
    void GetSinCos(float x, float y, float &vsin, float &vcos) const;

    bool IsInDist2d(float x, float y, float dist) const
        { return GetExactDist2dSq(x, y) < dist * dist; }
    bool IsInDist2d(const Position *pos, float dist) const
        { return GetExactDist2dSq(pos) < dist * dist; }
    bool IsInDist(float x, float y, float z, float dist) const
        { return GetExactDistSq(x, y, z) < dist * dist; }
    bool IsInDist(const Position *pos, float dist) const
        { return GetExactDistSq(pos) < dist * dist; }
    bool HasInArc(float arcangle, const Position *pos) const;
    bool HasInLine(const Unit *target, float distance, float width) const;
};

#define MAPID_INVALID 0xFFFFFFFF

class WorldLocation : public Position
{
    public:
        explicit WorldLocation(uint32 _mapid = MAPID_INVALID, float _x = 0, float _y = 0, float _z = 0, float _o = 0)
            : m_mapId(_mapid) { Relocate(_x, _y, _z, _o); }
        WorldLocation(const WorldLocation &loc) { WorldRelocate(loc); }

        void WorldRelocate(const WorldLocation &loc)
            { m_mapId = loc.GetMapId(); Relocate(loc); }
        uint32 GetMapId() const { return m_mapId; }

        uint32 m_mapId;
};

template<class T>
class GridObject
{
    public:
        GridReference<T> &GetGridRef() { return m_gridRef; }
    protected:
        GridReference<T> m_gridRef;
};

class WorldObject : public Object, public WorldLocation
{
    public:
        virtual ~WorldObject();

        virtual void Update ( uint32 /*time_diff*/ ) { }

        void _Create( uint32 guidlow, HighGuid guidhigh, uint32 phaseMask);

        void GetNearPoint2D( float &x, float &y, float distance, float absAngle) const;
        void GetNearPoint( WorldObject const* searcher, float &x, float &y, float &z, float searcher_size, float distance2d,float absAngle) const;
        void GetClosePoint(float &x, float &y, float &z, float size, float distance2d = 0, float angle = 0) const
        {
            // angle calculated from current orientation
            GetNearPoint(NULL,x,y,z,size,distance2d,GetOrientation() + angle);
        }
        void MovePosition(Position &pos, float dist, float angle);
        void GetNearPosition(Position &pos, float dist, float angle)
        {
            GetPosition(&pos);
            MovePosition(pos, dist, angle);
        }
        void GetRandomNearPosition(Position &pos, float radius)
        {
            GetPosition(&pos);
            MovePosition(pos, radius * rand_norm(), rand_norm() * 2 * M_PI);
        }

        void GetContactPoint( const WorldObject* obj, float &x, float &y, float &z, float distance2d = CONTACT_DISTANCE) const
        {
            // angle to face `obj` to `this` using distance includes size of `obj`
            GetNearPoint(obj,x,y,z,obj->GetObjectSize(),distance2d,GetAngle( obj ));
        }

        float GetObjectSize() const
        {
            return ( m_valuesCount > UNIT_FIELD_COMBATREACH ) ? m_floatValues[UNIT_FIELD_COMBATREACH] : DEFAULT_WORLD_OBJECT_SIZE;
        }
        void UpdateGroundPositionZ(float x, float y, float &z) const;

        void GetRandomPoint(const Position &srcPos, float distance, float &rand_x, float &rand_y, float &rand_z) const;
        void GetRandomPoint(const Position &srcPos, float distance, Position &pos) const
        {
            float x, y, z;
            GetRandomPoint(srcPos, distance, x, y, z);
            pos.Relocate(x, y, z, GetOrientation());
        }

        uint32 GetInstanceId() const { return m_InstanceId; }

        virtual void SetPhaseMask(uint32 newPhaseMask, bool update);
        uint32 GetPhaseMask() const { return m_phaseMask; }
        bool InSamePhase(WorldObject const* obj) const { return InSamePhase(obj->GetPhaseMask()); }
        bool InSamePhase(uint32 phasemask) const { return (GetPhaseMask() & phasemask); }

        uint32 GetZoneId() const;
        uint32 GetAreaId() const;
        void GetZoneAndAreaId(uint32& zoneid, uint32& areaid) const;

        InstanceData* GetInstanceData();

        const char* GetName() const { return m_name.c_str(); }
        void SetName(const std::string& newname) { m_name=newname; }

        virtual const char* GetNameForLocaleIdx(int32 /*locale_idx*/) const { return GetName(); }

        float GetDistance(const WorldObject *obj) const
        { 
            float d = GetExactDist(obj) - GetObjectSize() - obj->GetObjectSize();
            return d > 0.0f ? d : 0.0f;
        }
        float GetDistance(const Position &pos) const
        { 
            float d = GetExactDist(&pos) - GetObjectSize();
            return d > 0.0f ? d : 0.0f;
        }
        float GetDistance(float x, float y, float z) const
        { 
            float d = GetExactDist(x, y, z) - GetObjectSize();
            return d > 0.0f ? d : 0.0f;
        }
        float GetDistance2d(const WorldObject* obj) const
        { 
            float d = GetExactDist2d(obj) - GetObjectSize() - obj->GetObjectSize();
            return d > 0.0f ? d : 0.0f;
        }
        float GetDistance2d(float x, float y) const
        { 
            float d = GetExactDist2d(x, y) - GetObjectSize();
            return d > 0.0f ? d : 0.0f;
        }
        float GetDistanceZ(const WorldObject* obj) const;

        bool IsInMap(const WorldObject* obj) const
        {
            if (obj)
                return IsInWorld() && obj->IsInWorld() && (GetMap() == obj->GetMap()) && InSamePhase(obj);
            else
                return false;
        }
        bool IsWithinDist3d(float x, float y, float z, float dist) const
            { return IsInDist(x, y, z, dist + GetObjectSize()); }
        bool IsWithinDist3d(const Position *pos, float dist) const
            { return IsInDist(pos, dist + GetObjectSize()); }
        bool IsWithinDist2d(float x, float y, float dist) const
            { return IsInDist2d(x, y, dist + GetObjectSize()); }
        bool IsWithinDist2d(const Position *pos, float dist) const
            { return IsInDist2d(pos, dist + GetObjectSize()); }
        bool _IsWithinDist(WorldObject const* obj, float dist2compare, bool is3D) const;
        // use only if you will sure about placing both object at same map
        bool IsWithinDist(WorldObject const* obj, float dist2compare, bool is3D = true) const
        {
            return obj && _IsWithinDist(obj,dist2compare,is3D);
        }
        bool IsWithinDistInMap(WorldObject const* obj, float dist2compare, bool is3D = true) const
        {
            return obj && IsInMap(obj) && _IsWithinDist(obj,dist2compare,is3D);
        }
        bool IsWithinLOS(float x, float y, float z) const;
        bool IsWithinLOSInMap(const WorldObject* obj) const;
        bool GetDistanceOrder(WorldObject const* obj1, WorldObject const* obj2, bool is3D = true) const;
        bool IsInRange(WorldObject const* obj, float minRange, float maxRange, bool is3D = true) const;
        bool IsInRange2d(float x, float y, float minRange, float maxRange) const;
        bool IsInRange3d(float x, float y, float z, float minRange, float maxRange) const;
        bool isInFront(WorldObject const* target,float distance, float arc = M_PI) const;
        bool isInBack(WorldObject const* target, float distance, float arc = M_PI) const;

        bool IsInBetween(const WorldObject *obj1, const WorldObject *obj2, float size = 0) const;

        virtual void CleanupsBeforeDelete(bool finalCleanup = true);  // used in destructor or explicitly before mass creature delete to remove cross-references to already deleted units

        virtual void SendMessageToSet(WorldPacket *data, bool self);
        virtual void SendMessageToSetInRange(WorldPacket *data, float dist, bool self);

        void MonsterSay(const char* text, uint32 language, uint64 TargetGuid);
        void MonsterYell(const char* text, uint32 language, uint64 TargetGuid);
        void MonsterTextEmote(const char* text, uint64 TargetGuid, bool IsBossEmote = false);
        void MonsterWhisper(const char* text, uint64 receiver, bool IsBossWhisper = false);
        void MonsterSay(int32 textId, uint32 language, uint64 TargetGuid);
        void MonsterYell(int32 textId, uint32 language, uint64 TargetGuid);
        void MonsterTextEmote(int32 textId, uint64 TargetGuid, bool IsBossEmote = false);
        void MonsterWhisper(int32 textId, uint64 receiver, bool IsBossWhisper = false);
        void MonsterYellToZone(int32 textId, uint32 language, uint64 TargetGuid);
        void BuildMonsterChat(WorldPacket *data, uint8 msgtype, char const* text, uint32 language, char const* name, uint64 TargetGuid) const;

        void PlayDistanceSound(uint32 sound_id, Player* target = NULL);
        void PlayDirectSound(uint32 sound_id, Player* target = NULL);

        void SendObjectDeSpawnAnim(uint64 guid);

        virtual void SaveRespawnTime() {}
        void AddObjectToRemoveList();

        // main visibility check function in normal case (ignore grey zone distance check)
        bool isVisibleFor(Player const* u) const { return isVisibleForInState(u,false); }

        // low level function for visibility change code, must be define in all main world object subclasses
        virtual bool isVisibleForInState(Player const* u, bool inVisibleList) const = 0;

        // Low Level Packets
        void SendPlaySound(uint32 Sound, bool OnlySelf);

        virtual void SetMap(Map * map);
        virtual void ResetMap();
        Map * GetMap() const { ASSERT(m_currMap); return m_currMap; }
        Map * FindMap() const { return m_currMap; }
        //used to check all object's GetMap() calls when object is not in world!

        //this function should be removed in nearest time...
        Map const* GetBaseMap() const;

        void SetZoneScript();
        ZoneScript * GetZoneScript() const { return m_zoneScript; }

        TempSummon* SummonCreature(uint32 id, const Position &pos, TempSummonType spwtype = TEMPSUMMON_MANUAL_DESPAWN, uint32 despwtime = 0, uint32 vehId = 0) const;
        TempSummon* SummonCreature(uint32 id, float x, float y, float z, float ang = 0, TempSummonType spwtype = TEMPSUMMON_MANUAL_DESPAWN, uint32 despwtime = 0)
        {
            if(!x && !y && !z)
            {
                GetClosePoint(x, y, z, GetObjectSize());
                ang = GetOrientation();
            }
            Position pos = {x, y, z, ang};
            return SummonCreature(id, pos, spwtype, despwtime, 0);
        }
        GameObject* SummonGameObject(uint32 entry, float x, float y, float z, float ang, float rotation0, float rotation1, float rotation2, float rotation3, uint32 respawnTime);
        Creature*   SummonTrigger(float x, float y, float z, float ang, uint32 dur, CreatureAI* (*GetAI)(Creature*) = NULL);

        Creature*   FindNearestCreature(uint32 entry, float range, bool alive = true);
        GameObject* FindNearestGameObject(uint32 entry, float range);

        void GetGameObjectListWithEntryInGrid(std::list<GameObject*>& lList, uint32 uiEntry, float fMaxSearchRange);
        void GetCreatureListWithEntryInGrid(std::list<Creature*>& lList, uint32 uiEntry, float fMaxSearchRange);

        void DestroyForNearbyPlayers();
        virtual void UpdateObjectVisibility(bool forced = true);
        void BuildUpdate(UpdateDataMapType& );

        //relocation and visibility system functions
        void AddToNotify(uint16 f) { m_notifyflags |= f;}
        bool isNeedNotify(uint16 f) const { return m_notifyflags & f;}
        uint16 GetNotifyFlags() const { return m_notifyflags; }
        bool NotifyExecuted(uint16 f) const { return m_executed_notifies & f;}
        void SetNotified(uint16 f) { m_executed_notifies |= f;}
        void ResetAllNotifies() { m_notifyflags = 0; m_executed_notifies = 0; }

        bool isActiveObject() const { return m_isActive; }
        void setActive(bool isActiveObject);
        void SetWorldObject(bool apply);
        template<class NOTIFIER> void VisitNearbyObject(const float &radius, NOTIFIER &notifier) const { GetMap()->VisitAll(GetPositionX(), GetPositionY(), radius, notifier); }
        template<class NOTIFIER> void VisitNearbyGridObject(const float &radius, NOTIFIER &notifier) const { GetMap()->VisitGrid(GetPositionX(), GetPositionY(), radius, notifier); }
        template<class NOTIFIER> void VisitNearbyWorldObject(const float &radius, NOTIFIER &notifier) const { GetMap()->VisitWorld(GetPositionX(), GetPositionY(), radius, notifier); }

#ifdef MAP_BASED_RAND_GEN
        int32 irand(int32 min, int32 max) const     { return int32 (GetMap()->mtRand.randInt(max - min)) + min; }
        uint32 urand(uint32 min, uint32 max) const  { return GetMap()->mtRand.randInt(max - min) + min;}
        int32 rand32() const                        { return GetMap()->mtRand.randInt();}
        double rand_norm() const                    { return GetMap()->mtRand.randExc();}
        double rand_chance() const                  { return GetMap()->mtRand.randExc(100.0);}
#endif

        bool m_isWorldObject;
    protected:
        explicit WorldObject();
        std::string m_name;
        bool m_isActive;
        ZoneScript *m_zoneScript;

        //these functions are used mostly for Relocate() and Corpse/Player specific stuff...
        //use them ONLY in LoadFromDB()/Create() funcs and nowhere else!
        //mapId/instanceId should be set in SetMap() function!
        void SetLocationMapId(uint32 _mapId) { m_mapId = _mapId; }
        void SetLocationInstanceId(uint32 _instanceId) { m_InstanceId = _instanceId; }

    private:
        Map * m_currMap;                                    //current object's Map location

        //uint32 m_mapId;                                     // object at map with map_id
        uint32 m_InstanceId;                                // in map copy with instance id
        uint32 m_phaseMask;                                 // in area phase state

        uint16 m_notifyflags;
        uint16 m_executed_notifies;
};
#endif
