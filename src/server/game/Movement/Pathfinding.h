
#ifndef _PATHFINDING_H_
#define _PATHFINDING_H_

#include "PathGenerator.h"

#define FAR_MAX_PATH_LENGTH 32768
#define FAR_MAX_POINT_PATH_LENGTH   32768

class Unit;

struct PathParameter
{
    bool findOK;
    uint32 sessionID;
    ObjectGuid unitGUID;
    Map* pMap;
    Map* pBaseMap;
    uint32 mapID;
    uint32 instID;
    TypeID typeID;
    bool canFly;
    bool canSwim;
    bool canWalk;
    bool isInWater;
    bool isUnderWater;
    std::set<uint32> phaseMask;
    bool hasAuraType;

    float posX;
    float posY;
    float posZ;

    float targetPosX;
    float targetPosY;
    float targetPosZ;

    float offset;

    std::vector<G3D::Vector3> finishPaths;
    G3D::Vector3 destPosition;

    PathParameter(uint32 seID, Unit const* owner)
    {
        findOK = false;
        sessionID = seID;
        unitGUID = owner->GetGUID();
        pMap = owner->GetMap();
        mapID = owner->GetMapId();
        
        pBaseMap = (Map*)owner->GetMap();//pBaseMap = (Map*)owner->GetBaseMap();//org

        instID = owner->GetInstanceId();
        typeID = owner->GetTypeId();

        canFly = false;
        canSwim = false;
        canWalk = true;
        if (typeID == TypeID::TYPEID_UNIT)
        {
            canFly = owner->ToCreature()->CanFly();
            canSwim = owner->ToCreature()->CanSwim();
            canWalk = owner->ToCreature()->CanWalk();
        }
        isInWater = owner->IsInWater();
        isUnderWater = owner->IsUnderWater();
        phaseMask = owner->GetPhases();
        
        hasAuraType = owner->HasAuraType(SPELL_AURA_WATER_WALK);

        posX = owner->GetPositionX();
        posY = owner->GetPositionY();
        posZ = owner->GetPositionZ();

        offset = 0;
    }

    void TrimOldPathpoint(Position& /*pos*/)
    {
        if (finishPaths.size() <= 1)
            return;
        finishPaths.erase(finishPaths.begin());
        if (finishPaths.size() == 1)
        {
            G3D::Vector3 oncePosition = *(finishPaths.begin());
            finishPaths.push_back(oncePosition);
        }
    }
    //void TrimOldPathpoint(Position& pos)
    //{
    //	if (finishPaths.size() <= 2)
    //		return;
    //	G3D::Vector3 refer;
    //	refer.x = pos.GetPositionX();
    //	refer.y = pos.GetPositionY();
    //	refer.z = pos.GetPositionZ();
    //	float gap = 9999999;
    //	uint32 popCount = 0;
    //	for (G3D::Vector3& point : finishPaths)
    //	{
    //		float distance = (refer - point).length();
    //		if (distance < gap)
    //		{
    //			gap = distance;
    //			++popCount;
    //		}
    //		else
    //			break;
    //	}
    //	while (popCount > 0 && finishPaths.size() > 2)
    //	{
    //		--popCount;
    //		finishPaths.erase(finishPaths.begin());
    //	}
    //}
};

class Pathfinding
{
public:
    Pathfinding(PathParameter* pathParam, dtNavMesh const* pNavMesh, dtNavMeshQuery const* pNavMeshQuery);
    ~Pathfinding();

    bool CalculatePath(float destX, float destY, float destZ, bool forceDest = false, bool straightLine = false);

    // option setters - use optional
    void SetUseStraightPath(bool useStraightPath) { _useStraightPath = useStraightPath; }
    void SetPathLengthLimit(float distance) { _pointPathLimit = std::min<uint32>(uint32(distance / SMOOTH_PATH_STEP_SIZE), FAR_MAX_POINT_PATH_LENGTH); }

    // result getters
    G3D::Vector3 const& GetStartPosition() const { return _startPosition; }
    G3D::Vector3 const& GetEndPosition() const { return _endPosition; }
    G3D::Vector3 const& GetActualEndPosition() const { return _actualEndPosition; }

    Movement::PointsArray const& GetPath() const { return _pathPoints; }

    PathType GetPathType() const { return _type; }
    void UpdateAllowedPositionZ(float x, float y, float& z) const;

private:

    dtPolyRef _pathPolyRefs[FAR_MAX_PATH_LENGTH];   // array of detour polygon references
    uint32 _polyLength;                         // number of polygons in the path

    Movement::PointsArray _pathPoints;  // our actual (x,y,z) path to the target
    PathType _type;                     // tells what kind of path this is

    bool _useStraightPath;  // type of path will be generated
    bool _forceDestination; // when set, we will always arrive at given point
    uint32 _pointPathLimit; // limit point path size; min(this, MAX_POINT_PATH_LENGTH)
    bool _straightLine;     // use raycast if true for a straight line path

    G3D::Vector3 _startPosition;        // {x, y, z} of current location
    G3D::Vector3 _endPosition;          // {x, y, z} of the destination
    G3D::Vector3 _actualEndPosition;    // {x, y, z} of the closest possible point to given destination

    PathParameter* _pathParameter;
    dtNavMesh const* _navMesh;              // the nav mesh
    dtNavMeshQuery const* _navMeshQuery;    // the nav mesh query used to find the path

    dtQueryFilter _filter;  // use single filter for all movements, update it when needed

    void SetStartPosition(G3D::Vector3 const& point) { _startPosition = point; }
    void SetEndPosition(G3D::Vector3 const& point) { _actualEndPosition = point; _endPosition = point; }
    void SetActualEndPosition(G3D::Vector3 const& point) { _actualEndPosition = point; }
    void NormalizePath();

    void Clear()
    {
        _polyLength = 0;
        _pathPoints.clear();
    }

    bool InRange(G3D::Vector3 const& p1, G3D::Vector3 const& p2, float r, float h) const;
    float Dist3DSqr(G3D::Vector3 const& p1, G3D::Vector3 const& p2) const;
    bool InRangeYZX(float const* v1, float const* v2, float r, float h) const;

    dtPolyRef GetPathPolyByPosition(dtPolyRef const* polyPath, uint32 polyPathSize, float const* Point, float* Distance = NULL) const;
    dtPolyRef GetPolyByLocation(float const* Point, float* Distance) const;
    bool HaveTile(G3D::Vector3 const& p) const;

    void BuildPolyPath(G3D::Vector3 const& startPos, G3D::Vector3 const& endPos);
    void BuildPointPath(float const* startPoint, float const* endPoint);
    void BuildShortcut();

    NavTerrainFlag GetNavTerrain(float x, float y, float z);
    void CreateFilter();
    void UpdateFilter();

    // smooth path aux functions
    uint32 FixupCorridor(dtPolyRef* path, uint32 npath, uint32 maxPath, dtPolyRef const* visited, uint32 nvisited);
    bool GetSteerTarget(float const* startPos, float const* endPos, float minTargetDist, dtPolyRef const* path, uint32 pathSize, float* steerPos,
        unsigned char& steerPosFlag, dtPolyRef& steerPosRef);
    dtStatus FindSmoothPath(float const* startPos, float const* endPos,
        dtPolyRef const* polyPath, uint32 polyPathSize,
        float* smoothPath, int* smoothPathSize, uint32 smoothPathMaxSize);
};

#endif // _PATHFINDING_H_
