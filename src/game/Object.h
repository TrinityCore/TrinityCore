/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
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
#include "ByteBuffer.h"
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
#define MAX_VISIBILITY_DISTANCE  (5*SIZE_OF_GRID_CELL/2.0f) // max distance for visible object show, limited by active zone for player based at cell size (active zone = 5x5 cells)
#define DEFAULT_VISIBILITY_DISTANCE (SIZE_OF_GRID_CELL)     // default visible distance

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
    TYPEMASK_AIGROUP        = 0x0100,
    TYPEMASK_AREATRIGGER    = 0x0200,
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
    TYPEID_CORPSE        = 7,
    TYPEID_AIGROUP       = 8,
    TYPEID_AREATRIGGER   = 9
};
#define MAX_TYPEID         10

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

typedef UNORDERED_MAP<Player*, UpdateData> UpdateDataMapType;

struct WorldLocation
{
    uint32 mapid;
    float x;
    float y;
    float z;
    float o;
    explicit WorldLocation(uint32 _mapid = 0, float _x = 0, float _y = 0, float _z = 0, float _o = 0)
        : mapid(_mapid), x(_x), y(_y), z(_z), o(_o) {}
    WorldLocation(WorldLocation const &loc)
        : mapid(loc.mapid), x(loc.x), y(loc.y), z(loc.z), o(loc.o) {}
};

class TRINITY_DLL_SPEC Object
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

        uint8 GetTypeId() const { return m_objectTypeId; }
        bool isType(uint16 mask) const { return (mask & m_objectType); }

        virtual void BuildCreateUpdateBlockForPlayer( UpdateData *data, Player *target ) const;
        void SendUpdateToPlayer(Player* player);

        void BuildValuesUpdateBlockForPlayer( UpdateData *data, Player *target ) const;
        void BuildOutOfRangeUpdateBlock( UpdateData *data ) const;
        void BuildMovementUpdateBlock( UpdateData * data, uint32 flags = 0 ) const;
        void BuildUpdate(UpdateDataMapType &);

        virtual void DestroyForPlayer( Player *target ) const;

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

        uint8 GetUInt16Value( uint16 index, uint8 offset) const
        {
            ASSERT( index < m_valuesCount || PrintIndexError( index , false) );
            ASSERT( offset < 2 );
            return *(((uint16*)&m_uint32Values[ index ])+offset);
        }

        void SetInt32Value(  uint16 index,        int32  value );
        void SetUInt32Value( uint16 index,       uint32  value );
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
            ASSERT( index < m_valuesCount || PrintIndexError( index , false ) );
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
        void SendUpdateObjectToAllExcept(Player* exceptPlayer);

        bool LoadValues(const char* data);

        uint16 GetValuesCount() const { return m_valuesCount; }

        virtual bool hasQuest(uint32 /* quest_id */) const { return false; }
        virtual bool hasInvolvedQuest(uint32 /* quest_id */) const { return false; }

        // FG: some hacky helpers
        void ForceValuesUpdateAtIndex(uint32);

    protected:

        Object ( );

        void _InitValues();
        void _Create (uint32 guidlow, uint32 entry, HighGuid guidhigh);

        virtual void _SetUpdateBits(UpdateMask *updateMask, Player *target) const;

        virtual void _SetCreateBits(UpdateMask *updateMask, Player *target) const;
        void _BuildMovementUpdate(ByteBuffer * data, uint8 flags, uint32 flags2 ) const;
        void _BuildValuesUpdate(uint8 updatetype, ByteBuffer *data, UpdateMask *updateMask, Player *target ) const;

        uint16 m_objectType;

        uint8 m_objectTypeId;
        uint8 m_updateFlag;

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

class TRINITY_DLL_SPEC WorldObject : public Object
{
    public:
        virtual ~WorldObject ( ) {}

        virtual void Update ( uint32 /*time_diff*/ ) { }

        void _Create( uint32 guidlow, HighGuid guidhigh, uint32 mapid, uint32 phaseMask);

        void Relocate(WorldObject *obj)
        {
            m_positionX = obj->GetPositionX();
            m_positionY = obj->GetPositionY();
            m_positionZ = obj->GetPositionZ();
            m_orientation = obj->GetOrientation();
        }

        void Relocate(float x, float y, float z, float orientation)
        {
            m_positionX = x;
            m_positionY = y;
            m_positionZ = z;
            m_orientation = orientation;
        }

        void Relocate(float x, float y, float z)
        {
            m_positionX = x;
            m_positionY = y;
            m_positionZ = z;
        }

        void Relocate(WorldLocation const & loc)
        {
            SetMapId(loc.mapid);
            Relocate(loc.x, loc.y, loc.z, loc.o);
        }

        void SetOrientation(float orientation) { m_orientation = orientation; }

        float GetPositionX( ) const { return m_positionX; }
        float GetPositionY( ) const { return m_positionY; }
        float GetPositionZ( ) const { return m_positionZ; }
        void GetPosition( float &x, float &y, float &z ) const
            { x = m_positionX; y = m_positionY; z = m_positionZ; }
        void GetPosition( WorldLocation &loc ) const
            { loc.mapid = GetMapId(); GetPosition(loc.x, loc.y, loc.z); loc.o = GetOrientation(); }
        float GetOrientation( ) const { return m_orientation; }
        void GetNearPoint2D( float &x, float &y, float distance, float absAngle) const;
        void GetNearPoint( WorldObject const* searcher, float &x, float &y, float &z, float searcher_size, float distance2d,float absAngle) const;
        void GetClosePoint(float &x, float &y, float &z, float size, float distance2d = 0, float angle = 0) const
        {
            // angle calculated from current orientation
            GetNearPoint(NULL,x,y,z,size,distance2d,GetOrientation() + angle);
        }
        void GetGroundPoint(float &x, float &y, float &z, float dist, float angle);
        void GetGroundPointAroundUnit(float &x, float &y, float &z, float dist, float angle)
        {
            GetPosition(x, y, z);
            GetGroundPoint(x, y, z, dist, angle);
        }
        void GetContactPoint( const WorldObject* obj, float &x, float &y, float &z, float distance2d = CONTACT_DISTANCE) const
        {
            // angle to face `obj` to `this` using distance includes size of `obj`
            GetNearPoint(obj,x,y,z,obj->GetObjectSize(),distance2d,GetAngle( obj ));
        }

        float GetObjectSize() const
        {
            return ( m_valuesCount > UNIT_FIELD_BOUNDINGRADIUS ) ? m_floatValues[UNIT_FIELD_BOUNDINGRADIUS] : DEFAULT_WORLD_OBJECT_SIZE;
        }
        bool IsPositionValid() const;
        void UpdateGroundPositionZ(float x, float y, float &z) const;

        void GetRandomPoint( float x, float y, float z, float distance, float &rand_x, float &rand_y, float &rand_z ) const;

        void SetMapId(uint32 newMap) { m_mapId = newMap; }
        uint32 GetMapId() const { return m_mapId; }

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

        float GetDistance( const WorldObject* obj ) const;
        float GetDistance(const float x, const float y, const float z) const;
        float GetDistanceSq(const float &x, const float &y, const float &z) const;
        float GetDistance2d(const WorldObject* obj) const;
        float GetDistance2d(const float x, const float y) const;
        float GetExactDistance2d(const float x, const float y) const;
        float GetDistanceZ(const WorldObject* obj) const;
        bool IsInMap(const WorldObject* obj) const
        {
            return IsInWorld() && obj->IsInWorld() && GetMapId()==obj->GetMapId() &&
                GetInstanceId()==obj->GetInstanceId() && InSamePhase(obj);
        }
        bool IsWithinDistInMap(const WorldObject* obj, const float dist2compare, const bool is3D = true) const;
        bool IsWithinLOS(const float x, const float y, const float z ) const;
        bool IsWithinLOSInMap(const WorldObject* obj) const;

        float GetAngle( const WorldObject* obj ) const;
        float GetAngle( const float x, const float y ) const;
        void GetSinCos(const float x, const float y, float &vsin, float &vcos);
        bool HasInArc( const float arcangle, const WorldObject* obj ) const;

        virtual void SendMessageToSet(WorldPacket *data, bool self, bool to_possessor = true);
        virtual void SendMessageToSetInRange(WorldPacket *data, float dist, bool self, bool to_possessor = true);
        void BuildHeartBeatMsg( WorldPacket *data ) const;
        void BuildTeleportAckMsg( WorldPacket *data, float x, float y, float z, float ang) const;

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

        uint32 GetInstanceId() const { return m_InstanceId; }
        void SetInstanceId(uint32 val) { m_InstanceId = val; }

        void AddObjectToRemoveList();

        // main visibility check function in normal case (ignore grey zone distance check)
        bool isVisibleFor(Player const* u) const { return isVisibleForInState(u,false); }

        // low level function for visibility change code, must be define in all main world object subclasses
        virtual bool isVisibleForInState(Player const* u, bool inVisibleList) const = 0;

        // Low Level Packets
        void SendPlaySound(uint32 Sound, bool OnlySelf);

        Map      * GetMap() const;
        Map      * FindMap() const;
        Map const* GetBaseMap() const;
        TempSummon* SummonCreature(uint32 id, float x, float y, float z, float ang,TempSummonType spwtype,uint32 despwtime);
        Vehicle*    SummonVehicle(uint32 entry, float x, float y, float z, float ang);
        GameObject* SummonGameObject(uint32 entry, float x, float y, float z, float ang, float rotation0, float rotation1, float rotation2, float rotation3, uint32 respawnTime);
        Creature*   SummonTrigger(float x, float y, float z, float ang, uint32 dur, CreatureAI* (*GetAI)(Creature*) = NULL);
        bool isActiveObject() const { return m_isActive; }
        void setActive(bool isActiveObject);
        void SetWorldObject(bool apply);
        template<class NOTIFIER> void VisitNearbyObject(const float &radius, NOTIFIER &notifier) const { GetMap()->VisitAll(GetPositionX(), GetPositionY(), radius, notifier); }
        template<class NOTIFIER> void VisitNearbyGridObject(const float &radius, NOTIFIER &notifier) const { GetMap()->VisitGrid(GetPositionX(), GetPositionY(), radius, notifier); }
        template<class NOTIFIER> void VisitNearbyWorldObject(const float &radius, NOTIFIER &notifier) const { GetMap()->VisitWorld(GetPositionX(), GetPositionY(), radius, notifier); }
        bool IsTempWorldObject;

    protected:
        explicit WorldObject();
        std::string m_name;
        bool m_isActive;

    private:
        uint32 m_mapId;                                     // object at map with map_id
        uint32 m_InstanceId;                                // in map copy with instance id
        uint32 m_phaseMask;                                 // in area phase state

        float m_positionX;
        float m_positionY;
        float m_positionZ;
        float m_orientation;
};
#endif

