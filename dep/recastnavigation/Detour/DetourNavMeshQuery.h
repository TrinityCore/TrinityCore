//
// Copyright (c) 2009-2010 Mikko Mononen memon@inside.org
//
// This software is provided 'as-is', without any express or implied
// warranty.  In no event will the authors be held liable for any damages
// arising from the use of this software.
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
//

#ifndef DETOURNAVMESHQUERY_H
#define DETOURNAVMESHQUERY_H

#include "DetourNavMesh.h"


// Define DT_VIRTUAL_QUERYFILTER if you wish to derive a custom filter from dtQueryFilter.
// On certain platforms indirect or virtual function call is expensive. The default
// setting is to use non-virtual functions, the actualy implementations of the functions
// are declared as inline for maximum speed. 

//#define DT_VIRTUAL_QUERYFILTER 1

// Class for polygon filtering and cost calculation during query operations.
// - It is possible to derive a custom query filter from dtQueryFilter by overriding
//   the virtual functions passFilter() and getCost().
// - Both functions should be as fast as possible. Use cached local copy of data
//   instead of accessing your own objects where possible.
// - You do not need to adhere to the flags and cost logic provided by the default
//   implementation.
// - In order for the A* to work properly, the cost should be proportional to
//   the travel distance. Using cost modifier less than 1.0 is likely to lead
//   to problems during pathfinding.
class dtQueryFilter
{
	float m_areaCost[DT_MAX_AREAS];		// Array storing cost per area type, used by default implementation.
	unsigned short m_includeFlags;		// Include poly flags, used by default implementation.
	unsigned short m_excludeFlags;		// Exclude poly flags, used by default implementation.
	
public:
	dtQueryFilter();
	
	// Returns true if the polygon is can visited.
	// Params:
	//  ref - (in) reference to the polygon test.
	//  tile - (in) pointer to the tile of the polygon test.
	//  poly - (in) pointer to the polygon test.
#ifdef DT_VIRTUAL_QUERYFILTER
	virtual bool passFilter(const dtPolyRef ref,
							const dtMeshTile* tile,
							const dtPoly* poly) const;
#else
	bool passFilter(const dtPolyRef ref,
					const dtMeshTile* tile,
					const dtPoly* poly) const;
#endif

	// Returns cost to travel from 'pa' to 'pb'.'
	// The segment is fully contained inside 'cur'.
	// 'pa' lies on the edge between 'prev' and 'cur', 
	// 'pb' lies on the edge between 'cur' and 'next'.
	// Params:
	//  pa - (in) segment start position.
	//  pb - (in) segment end position.
	//  prevRef, prevTile, prevPoly - (in) data describing the previous polygon, can be null.
	//  curRef, curTile, curPoly - (in) data describing the current polygon.
	//  nextRef, nextTile, nextPoly - (in) data describing the next polygon, can be null.
#ifdef DT_VIRTUAL_QUERYFILTER
	virtual float getCost(const float* pa, const float* pb,
						  const dtPolyRef prevRef, const dtMeshTile* prevTile, const dtPoly* prevPoly,
						  const dtPolyRef curRef, const dtMeshTile* curTile, const dtPoly* curPoly,
						  const dtPolyRef nextRef, const dtMeshTile* nextTile, const dtPoly* nextPoly) const;
#else
	float getCost(const float* pa, const float* pb,
				  const dtPolyRef prevRef, const dtMeshTile* prevTile, const dtPoly* prevPoly,
				  const dtPolyRef curRef, const dtMeshTile* curTile, const dtPoly* curPoly,
				  const dtPolyRef nextRef, const dtMeshTile* nextTile, const dtPoly* nextPoly) const;
#endif
	
	// Getters and setters for the default implementation data.
	inline float getAreaCost(const int i) const { return m_areaCost[i]; }
	inline void setAreaCost(const int i, const float cost) { m_areaCost[i] = cost; } 

	inline unsigned short getIncludeFlags() const { return m_includeFlags; }
	inline void setIncludeFlags(const unsigned short flags) { m_includeFlags = flags; }

	inline unsigned short getExcludeFlags() const { return m_excludeFlags; }
	inline void setExcludeFlags(const unsigned short flags) { m_excludeFlags = flags; }	
};

class dtNavMeshQuery
{
public:
	dtNavMeshQuery();
	~dtNavMeshQuery();
	
	// Initializes the nav mesh query.
	// Params:
	//  nav - (in) pointer to navigation mesh data.
	//  maxNodes - (in) Maximum number of search nodes to use (max 65536).
	// Returns: True if succeed, else false.
	dtStatus init(const dtNavMesh* nav, const int maxNodes);
	
	// Finds the nearest navigation polygon around the center location.
	// Params:
	//	center[3] - (in) The center of the search box.
	//	extents[3] - (in) The extents of the search box.
	//  filter - (in) path polygon filter.
	//  nearestRef - (out) Reference to the nearest polygon.
	//  nearestPt[3] - (out, opt) The nearest point on found polygon, null if not needed.
	// Returns: Reference identifier for the polygon, or 0 if no polygons found.
	dtStatus findNearestPoly(const float* center, const float* extents,
							 const dtQueryFilter* filter,
							 dtPolyRef* nearestRef, float* nearestPt) const;
	
	// Returns polygons which overlap the query box.
	// Params:
	//	center[3] - (in) the center of the search box.
	//	extents[3] - (in) the extents of the search box.
	//  filter - (in) path polygon filter.
	//	polys - (out) array holding the search result.
	//  polyCount - (out) Number of polygons in search result array.
	//	maxPolys - (in) The max number of polygons the polys array can hold.
	dtStatus queryPolygons(const float* center, const float* extents,
						   const dtQueryFilter* filter,
						   dtPolyRef* polys, int* polyCount, const int maxPolys) const;
	
	// Finds path from start polygon to end polygon.
	// If target polygon canno be reached through the navigation graph,
	// the last node on the array is nearest node to the end polygon.
	// Start end end positions are needed to calculate more accurate
	// traversal cost at start end end polygons.
	// Params:
	//	startRef - (in) ref to path start polygon.
	//	endRef - (in) ref to path end polygon.
	//	startPos[3] - (in) Path start location.
	//	endPos[3] - (in) Path end location.
	//  filter - (in) path polygon filter.
	//	path - (out) array holding the search result.
	//  pathCount - (out) Number of polygons in search result array.
	//	maxPath - (in) The max number of polygons the path array can hold. Must be at least 1.
	dtStatus findPath(dtPolyRef startRef, dtPolyRef endRef,
					  const float* startPos, const float* endPos,
					  const dtQueryFilter* filter,
					  dtPolyRef* path, int* pathCount, const int maxPath) const;
	
	// Intializes sliced path find query.
	// Note 1: calling any other dtNavMeshQuery method before calling findPathEnd()
	// may results in corrupted data!
	// Note 2: The pointer to filter is store, and used in subsequent
	// calls to updateSlicedFindPath().
	// Params:
	//	startRef - (in) ref to path start polygon.
	//	endRef - (in) ref to path end polygon.
	//	startPos[3] - (in) Path start location.
	//	endPos[3] - (in) Path end location.
	//  filter - (in) path polygon filter.
	dtStatus initSlicedFindPath(dtPolyRef startRef, dtPolyRef endRef,
								const float* startPos, const float* endPos,
								const dtQueryFilter* filter);

	// Updates sliced path find query.
	// Params:
	//  maxIter - (in) max number of iterations to update.
	// Returns: Path query state.
	dtStatus updateSlicedFindPath(const int maxIter);

	// Finalizes sliced path find query and returns found path.
	//	path - (out) array holding the search result.
	//  pathCount - (out) Number of polygons in search result array.
	//	maxPath - (in) The max number of polygons the path array can hold.
	dtStatus finalizeSlicedFindPath(dtPolyRef* path, int* pathCount, const int maxPath);
	
	// Finalizes partial sliced path find query and returns path to the furthest
	// polygon on the existing path that was visited during the search.
	//	existing - (out) Array of polygons in the existing path.
	//  existingSize - (out) Number of polygons in existing path array.
	//	path - (out) array holding the search result.
	//  pathCount - (out) Number of polygons in search result array.
	//	maxPath - (in) The max number of polygons the path array can hold.
	dtStatus finalizeSlicedFindPathPartial(const dtPolyRef* existing, const int existingSize,
										   dtPolyRef* path, int* pathCount, const int maxPath);
	
	// Finds a straight path from start to end locations within the corridor
	// described by the path polygons.
	// Start and end locations will be clamped on the corridor.
	// The returned polygon references are point to polygon which was entered when
	// a path point was added. For the end point, zero will be returned. This allows
	// to match for example off-mesh link points to their representative polygons.
	// Params:
	//	startPos[3] - (in) Path start location.
	//	endPo[3] - (in) Path end location.
	//	path - (in) Array of connected polygons describing the corridor.
	//	pathSize - (in) Number of polygons in path array.
	//	straightPath - (out) Points describing the straight path.
	//  straightPathFlags - (out, opt) Flags describing each point type, see dtStraightPathFlags.
	//  straightPathRefs - (out, opt) References to polygons at point locations.
	//  straightPathCount - (out) Number of points in the path.
	//	maxStraightPath - (in) The max number of points the straight path array can hold. Must be at least 1.
	dtStatus findStraightPath(const float* startPos, const float* endPos,
							  const dtPolyRef* path, const int pathSize,
							  float* straightPath, unsigned char* straightPathFlags, dtPolyRef* straightPathRefs,
							  int* straightPathCount, const int maxStraightPath) const;
	
	// Moves from startPos to endPos constrained to the navmesh.
	// If the endPos is reachable, the resultPos will be endPos,
	// or else the resultPos will be the nearest point in navmesh.
	// Note: The resulting point is not projected to the ground, use getPolyHeight() to get height.
	// Note: The algorithm is optimized for small delta movement and small number of polygons. 
	// Params:
	//  startRef - (in) ref to the polygon where startPos lies.
	//  startPos[3] - (in) start position of the mover.
	//  endPos[3] - (in) desired end position of the mover.
	//  filter - (in) path polygon filter.
	//  resultPos[3] - (out) new position of the mover.
	//  visited - (out) array of visited polygons.
	//  visitedCount - (out) Number of entries in the visited array.
	//  maxVisitedSize - (in) max number of polygons in the visited array.
	dtStatus moveAlongSurface(dtPolyRef startRef, const float* startPos, const float* endPos,
							  const dtQueryFilter* filter,
							  float* resultPos, dtPolyRef* visited, int* visitedCount, const int maxVisitedSize) const;
	
	// Casts 'walkability' ray along the navmesh surface from startPos towards the endPos.
	// Params:
	//	startRef - (in) ref to the polygon where the start lies.
	//	startPos[3] - (in) start position of the query.
	//	endPos[3] - (in) end position of the query.
	//	t - (out) hit parameter along the segment, FLT_MAX if no hit.
	//	hitNormal[3] - (out) normal of the nearest hit.
	//  filter - (in) path polygon filter.
	//  path - (out,opt) visited path polygons.
	//  pathCount - (out,opt) Number of polygons visited.
	//  maxPath - (in) max number of polygons in the path array.
	dtStatus raycast(dtPolyRef startRef, const float* startPos, const float* endPos,
					 const dtQueryFilter* filter,
					 float* t, float* hitNormal, dtPolyRef* path, int* pathCount, const int maxPath) const;
	
	// Returns distance to nearest wall from the specified location.
	// Params:
	//	startRef - (in) ref to the polygon where the center lies.
	//	centerPos[3] - (in) center if the query circle.
	//	maxRadius - (in) max search radius.
	//  filter - (in) path polygon filter.
	//  hitDist - (out) distance to nearest wall from the test location.
	//	hitPos[3] - (out) location of the nearest hit.
	//	hitNormal[3] - (out) normal of the nearest hit.
	dtStatus findDistanceToWall(dtPolyRef startRef, const float* centerPos, const float maxRadius,
								const dtQueryFilter* filter,
								float* hitDist, float* hitPos, float* hitNormal) const;
	
	// Finds polygons found along the navigation graph which touch the specified circle.
	// Params:
	//	startRef - (in) ref to the polygon where the search starts.
	//	centerPos[3] - (in) center if the query circle.
	//	radius - (in) radius of the query circle.
	//  filter - (in) path polygon filter.
	//	resultRef - (out, opt) refs to the polygons touched by the circle.
	//	resultParent - (out, opt) parent of each result polygon.
	//	resultCost - (out, opt) search cost at each result polygon.
	//  resultCount - (out, opt) Number of results.
	//	maxResult - (int) maximum capacity of search results.
	dtStatus findPolysAroundCircle(dtPolyRef startRef, const float* centerPos, const float radius,
								   const dtQueryFilter* filter,
								   dtPolyRef* resultRef, dtPolyRef* resultParent, float* resultCost,
								   int* resultCount, const int maxResult) const;
	
	// Finds polygons found along the navigation graph which touch the convex polygon shape.
	// Params:
	//	startRef - (in) ref to the polygon where the search starts.
	//	verts[3*n] - (in) vertices describing convex polygon shape (CCW).
	//	nverts - (in) number of vertices in the polygon.
	//  filter - (in) path polygon filter.
	//	resultRef - (out, opt) refs to the polygons touched by the circle.
	//	resultParent - (out, opt) parent of each result polygon.
	//	resultCost - (out, opt) search cost at each result polygon.
	//  resultCount - (out) number of results.
	//	maxResult - (int) maximum capacity of search results.
	dtStatus findPolysAroundShape(dtPolyRef startRef, const float* verts, const int nverts,
								  const dtQueryFilter* filter,
								  dtPolyRef* resultRef, dtPolyRef* resultParent, float* resultCost,
								  int* resultCount, const int maxResult) const;
	
	// Finds non-overlapping local neighbourhood around center location.
	// Note: The algorithm is optimized for small query radius and small number of polygons. 
	// Params:
	//	startRef - (in) ref to the polygon where the search starts.
	//	centerPos[3] - (in) center if the query circle.
	//	radius - (in) radius of the query circle.
	//  filter - (in) path polygon filter.
	//	resultRef - (out) refs to the polygons touched by the circle.
	//	resultParent - (out, opt) parent of each result polygon.
	//  resultCount - (out) number of results.
	//	maxResult - (int) maximum capacity of search results.
	dtStatus findLocalNeighbourhood(dtPolyRef startRef, const float* centerPos, const float radius,
									const dtQueryFilter* filter,
									dtPolyRef* resultRef, dtPolyRef* resultParent,
									int* resultCount, const int maxResult) const;
	
	// Returns wall segments of specified polygon.
	// Params:
	//  ref - (in) ref to the polygon.
	//  filter - (in) path polygon filter.
	//  segments[6*maxSegments] - (out) wall segments (2 endpoints per segment).
	//  segmentCount - (out) number of wall segments.
	//  maxSegments - (in) max number of segments that can be stored in 'segments'.
	dtStatus getPolyWallSegments(dtPolyRef ref, const dtQueryFilter* filter,
								 float* segments, int* segmentCount, const int maxSegments) const;
	
	// Returns closest point on navigation polygon.
	// Uses detail polygons to find the closest point to the navigation polygon surface. 
	// Params:
	//	ref - (in) ref to the polygon.
	//	pos[3] - (in) the point to check.
	//	closest[3] - (out) closest point.
	// Returns: true if closest point found.
	dtStatus closestPointOnPoly(dtPolyRef ref, const float* pos, float* closest) const;
	
	// Returns closest point on navigation polygon boundary.
	// Uses the navigation polygon boundary to snap the point to poly boundary
	// if it is outside the polygon. Much faster than closestPointToPoly. Does not affect height.
	// Params:
	//	ref - (in) ref to the polygon.
	//	pos[3] - (in) the point to check.
	//	closest[3] - (out) closest point.
	// Returns: true if closest point found.
	dtStatus closestPointOnPolyBoundary(dtPolyRef ref, const float* pos, float* closest) const;
	
	// Returns start and end location of an off-mesh link polygon.
	// Params:
	//	prevRef - (in) ref to the polygon before the link (used to select direction).
	//	polyRef - (in) ref to the off-mesh link polygon.
	//	startPos[3] - (out) start point of the link.
	//	endPos[3] - (out) end point of the link.
	// Returns: true if link is found.
	dtStatus getOffMeshConnectionPolyEndPoints(dtPolyRef prevRef, dtPolyRef polyRef, float* startPos, float* endPos) const;
	
	// Returns height of the polygon at specified location.
	// Params:
	//	ref - (in) ref to the polygon.
	//	pos[3] - (in) the point where to locate the height.
	//	height - (out) height at the location.
	// Returns: true if over polygon.
	dtStatus getPolyHeight(dtPolyRef ref, const float* pos, float* height) const;
		
	// Returns true if poly reference ins in closed list.
	bool isInClosedList(dtPolyRef ref) const;
	
	class dtNodePool* getNodePool() const { return m_nodePool; }
	
private:
	
	// Returns neighbour tile based on side. 
	dtMeshTile* getNeighbourTileAt(int x, int y, int side) const;

	// Queries polygons within a tile.
	int queryPolygonsInTile(const dtMeshTile* tile, const float* qmin, const float* qmax, const dtQueryFilter* filter,
							dtPolyRef* polys, const int maxPolys) const;
	// Find nearest polygon within a tile.
	dtPolyRef findNearestPolyInTile(const dtMeshTile* tile, const float* center, const float* extents,
									const dtQueryFilter* filter, float* nearestPt) const;
	// Returns closest point on polygon.
	dtStatus closestPointOnPolyInTile(const dtMeshTile* tile, const dtPoly* poly, const float* pos, float* closest) const;
	
	// Returns portal points between two polygons.
	dtStatus getPortalPoints(dtPolyRef from, dtPolyRef to, float* left, float* right,
							 unsigned char& fromType, unsigned char& toType) const;
	dtStatus getPortalPoints(dtPolyRef from, const dtPoly* fromPoly, const dtMeshTile* fromTile,
							 dtPolyRef to, const dtPoly* toPoly, const dtMeshTile* toTile,
							 float* left, float* right) const;
	
	// Returns edge mid point between two polygons.
	dtStatus getEdgeMidPoint(dtPolyRef from, dtPolyRef to, float* mid) const;
	dtStatus getEdgeMidPoint(dtPolyRef from, const dtPoly* fromPoly, const dtMeshTile* fromTile,
							 dtPolyRef to, const dtPoly* toPoly, const dtMeshTile* toTile,
							 float* mid) const;
	
	const dtNavMesh* m_nav;				// Pointer to navmesh data.

	struct dtQueryData
	{
		dtStatus status;
		struct dtNode* lastBestNode;
		float lastBestNodeCost;
		dtPolyRef startRef, endRef;
		float startPos[3], endPos[3];
		const dtQueryFilter* filter;
	};
	dtQueryData m_query;				// Sliced query state.

	class dtNodePool* m_tinyNodePool;	// Pointer to small node pool.
	class dtNodePool* m_nodePool;		// Pointer to node pool.
	class dtNodeQueue* m_openList;		// Pointer to open list queue.
};

// Helper function to allocate navmesh query class using Detour allocator.
dtNavMeshQuery* dtAllocNavMeshQuery();
void dtFreeNavMeshQuery(dtNavMeshQuery* query);

#endif // DETOURNAVMESHQUERY_H
