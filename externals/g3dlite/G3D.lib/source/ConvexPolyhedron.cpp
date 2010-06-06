/**
  @file ConvexPolyhedron.cpp
  
  @author Morgan McGuire, morgan@graphics3d.com

  @created 2001-11-11
  @edited  2006-01-10
 
  Copyright 2000-2006, Morgan McGuire.
  All rights reserved.
 */

#include "G3D/platform.h"
#include "G3D/ConvexPolyhedron.h"
#include "G3D/debug.h"

namespace G3D {

ConvexPolygon::ConvexPolygon(const Array<Vector3>& __vertex) : _vertex(__vertex) {
    // Intentionally empty
}


bool ConvexPolygon::isEmpty() const {
    return (_vertex.length() == 0) || (getArea() <= fuzzyEpsilon);
}


float ConvexPolygon::getArea() const {

    if (_vertex.length() < 3) {
        return 0;
    }

    float sum = 0;

    int length = _vertex.length();
    // Split into triangle fan, compute individual area
    for (int v = 2; v < length; v++) {
        int i0 = 0;
        int i1 = v - 1;
        int i2 = v;

        sum += (_vertex[i1] - _vertex[i0]).cross(_vertex[i2] - _vertex[i0]).magnitude() / 2; 
    }

    return sum;
}

void ConvexPolygon::cut(const Plane& plane, ConvexPolygon &above, ConvexPolygon &below) {
    DirectedEdge edge;
    cut(plane, above, below, edge);
}

void ConvexPolygon::cut(const Plane& plane, ConvexPolygon &above, ConvexPolygon &below, DirectedEdge &newEdge) {
    above._vertex.resize(0);
    below._vertex.resize(0);

    if (isEmpty()) {
        //debugPrintf("Empty\n");
        return;
    }

    int v = 0;
    int length = _vertex.length();


    Vector3 polyNormal = normal();
    Vector3 planeNormal= plane.normal();

    // See if the polygon is *in* the plane.
    if (planeNormal.fuzzyEq(polyNormal) || planeNormal.fuzzyEq(-polyNormal)) {
        // Polygon is parallel to the plane.  It must be either above,
        // below, or in the plane.

        double a, b, c, d;
        Vector3 pt = _vertex[0];

        plane.getEquation(a,b,c,d);
        float r = (float)(a * pt.x + b * pt.y + c * pt.z + d);

        if (fuzzyGe(r, 0)) {
            // The polygon is entirely in the plane.
            //debugPrintf("Entirely above\n");
            above = *this;
            return;
        } else {
            //debugPrintf("Entirely below (1)\n");
            below = *this;
            return;
        }
    }


    // Number of edges crossing the plane.  Used for 
    // debug assertions.
    int count = 0;

    // True when the last _vertex we looked at was above the plane
    bool lastAbove = plane.halfSpaceContains(_vertex[v]);

    if (lastAbove) {
        above._vertex.append(_vertex[v]);
    } else {
        below._vertex.append(_vertex[v]);
    }

    for (v = 1; v < length; v++) {
        bool isAbove = plane.halfSpaceContains(_vertex[v]);
    
        if (lastAbove ^ isAbove) {
            // Switched sides.
            // Create an interpolated point that lies
            // in the plane, between the two points.
            Line line = Line::fromTwoPoints(_vertex[v - 1], _vertex[v]);
            Vector3 interp = line.intersection(plane);
            
            if (! interp.isFinite()) {

                // Since the polygon is not in the plane (we checked above), 
                // it must be the case that this edge (and only this edge)
                // is in the plane.  This only happens when the polygon is
                // entirely below the plane except for one edge.  This edge
                // forms a degenerate polygon, so just treat the whole polygon
                // as below the plane.
                below = *this;
                above._vertex.resize(0);
                //debugPrintf("Entirely below\n");
                return;
            }                

            above._vertex.append(interp);
            below._vertex.append(interp);
            if (lastAbove) {
                newEdge.stop = interp;
            } else {
                newEdge.start = interp;
            }
            count++;
        }

        lastAbove = isAbove;
        if (lastAbove) {
            above._vertex.append(_vertex[v]);
        } else {
            below._vertex.append(_vertex[v]);
        }
    }

    // Loop back to the first point, seeing if an interpolated point is
    // needed.
    bool isAbove = plane.halfSpaceContains(_vertex[0]);
    if (lastAbove ^ isAbove) {
        Line line = Line::fromTwoPoints(_vertex[length - 1], _vertex[0]);
        Vector3 interp = line.intersection(plane);
        if (! interp.isFinite()) {
            // Since the polygon is not in the plane (we checked above), 
            // it must be the case that this edge (and only this edge)
            // is in the plane.  This only happens when the polygon is
            // entirely below the plane except for one edge.  This edge
            // forms a degenerate polygon, so just treat the whole polygon
            // as below the plane.
            below = *this;
            above._vertex.resize(0);
            //debugPrintf("Entirely below\n");
            return;
        }                

        above._vertex.append(interp);
        below._vertex.append(interp);
        debugAssertM(count < 2, "Convex polygons may only intersect planes at two edges.");
        if (lastAbove) {
            newEdge.stop = interp;
        } else {
            newEdge.start = interp;
        }
        count++;
    }

    debugAssertM((count == 2) || (count == 0), "Convex polygons may only intersect planes at two edges.");
}

ConvexPolygon ConvexPolygon::inverse() const {
    ConvexPolygon result;
    int length = _vertex.length();
    result._vertex.resize(length);
    
    for (int v = 0; v < length; v++) {
        result._vertex[v] = _vertex[length - v - 1];
    }

    return result;
}

void ConvexPolygon::removeDuplicateVertices(){
	// Any valid polygon should have 3 or more vertices, but why take chances?
	if(_vertex.size() >= 2){

		// Remove duplicate vertices.
		for(int i=0;i<_vertex.size()-1;++i){
			if(_vertex[i].fuzzyEq(_vertex[i+1])){
				_vertex.remove(i+1);
				--i; // Don't move forward.
			}
		}
		
		// Check the last vertex against the first.
		if(_vertex[_vertex.size()-1].fuzzyEq(_vertex[0])){
			_vertex.pop();
		}
	}
}

//////////////////////////////////////////////////////////////////////////////

ConvexPolyhedron::ConvexPolyhedron(const Array<ConvexPolygon>& _face) : face(_face) {
    // Intentionally empty
}

float ConvexPolyhedron::getVolume() const {

    if (face.length() < 4) {
        return 0;
    }

    // The volume of any pyramid is 1/3 * h * base area.
    // Discussion at: http://nrich.maths.org/mathsf/journalf/oct01/art1/

    float sum = 0;

    // Choose the first _vertex of the first face as the origin.
    // This lets us skip one face, too, and avoids negative heights.
    Vector3 v0 = face[0]._vertex[0];
    for (int f = 1; f < face.length(); f++) {        
        const ConvexPolygon& poly = face[f];
        
        float height = (poly._vertex[0] - v0).dot(poly.normal());
        float base   = poly.getArea();

        sum += height * base;
    }

    return sum / 3;
}

bool ConvexPolyhedron::isEmpty() const {
    return (face.length() == 0) || (getVolume() <= fuzzyEpsilon);
}

void ConvexPolyhedron::cut(const Plane& plane, ConvexPolyhedron &above, ConvexPolyhedron &below) {
    above.face.resize(0);
    below.face.resize(0);

    Array<DirectedEdge> edge;

    int f;
    
    // See if the plane cuts this polyhedron at all.  Detect when
    // the polyhedron is entirely to one side or the other.
    //{
        int numAbove = 0, numIn = 0, numBelow = 0;
        bool ruledOut = false;
        double d;
        Vector3 abc;
        plane.getEquation(abc, d);

        // This number has to be fairly large to prevent precision problems down
        // the road.
        const float eps = 0.005f;
        for (f = face.length() - 1; (f >= 0) && (!ruledOut); f--) {
            const ConvexPolygon& poly = face[f];
            for (int v = poly._vertex.length() - 1; (v >= 0) && (!ruledOut); v--) { 
                double r = abc.dot(poly._vertex[v]) + d;
                if (r > eps) {
                    numAbove++;
                } else if (r < -eps) {
                    numBelow++;
                } else {
                    numIn++;
                }

                ruledOut = (numAbove != 0) && (numBelow !=0);
            }
        }

        if (numBelow == 0) {
            above = *this;
            return;
        } else if (numAbove == 0) {
            below = *this;
            return;
        }
    //}

    // Clip each polygon, collecting split edges.
    for (f = face.length() - 1; f >= 0; f--) {
        ConvexPolygon a, b;
        DirectedEdge e;
        face[f].cut(plane, a, b, e);

        bool aEmpty = a.isEmpty();
        bool bEmpty = b.isEmpty();

        //debugPrintf("\n");
        if (! aEmpty) {
            //debugPrintf(" Above %f\n", a.getArea());
            above.face.append(a);
        }

        if (! bEmpty) {
            //debugPrintf(" Below %f\n", b.getArea());
            below.face.append(b);
        }

        if (! aEmpty && ! bEmpty) {
            //debugPrintf(" == Split\n");
            edge.append(e);
        } else {
            // Might be the case that the polygon is entirely on 
            // one side of the plane yet there is an edge we need
            // because it touches the plane.
            // 
            // Extract the non-empty _vertex list and examine it.
            // If we find exactly one edge in the plane, add that edge.
            const Array<Vector3>& _vertex = (aEmpty ? b._vertex : a._vertex);
            int L = _vertex.length();
            int count = 0;
            for (int v = 0; v < L; v++) {
                if (plane.fuzzyContains(_vertex[v]) && plane.fuzzyContains(_vertex[(v + 1) % L])) {
                    e.start = _vertex[v];
                    e.stop = _vertex[(v + 1) % L];
                    count++;
                }
            }

            if (count == 1) {
                edge.append(e);
            }
        }
    }

    if (above.face.length() == 1) {
        // Only one face above means that this entire 
        // polyhedron is below the plane.  Move that face over.
        below.face.append(above.face[0]);
        above.face.resize(0);
    } else if (below.face.length() == 1) {
        // This shouldn't happen, but it arises in practice
        // from numerical imprecision.
        above.face.append(below.face[0]);
        below.face.resize(0);
    }

    if ((above.face.length() > 0) && (below.face.length() > 0)) {
        // The polyhedron was actually cut; create a cap polygon
        ConvexPolygon cap;

        // Collect the final polgyon by sorting the edges
        int numVertices = edge.length();
/*debugPrintf("\n");
for (int xx=0; xx < numVertices; xx++) {
    std::string s1 = edge[xx].start.toString();
    std::string s2 = edge[xx].stop.toString();
    debugPrintf("%s -> %s\n", s1.c_str(), s2.c_str());
}
*/

        // Need at least three points to make a polygon
        debugAssert(numVertices >= 3);

        Vector3 last_vertex = edge.last().stop;
        cap._vertex.append(last_vertex);

        // Search for the next _vertex.  Because of accumulating
        // numerical error, we have to find the closest match, not 
        // just the one we expect.
        for (int v = numVertices - 1; v >= 0; v--) {
            // matching edge index
            int index = 0;
            int num = edge.length();
            double distance = (edge[index].start - last_vertex).squaredMagnitude();
            for (int e = 1; e < num; e++) {
                double d = (edge[e].start - last_vertex).squaredMagnitude();

                if (d < distance) {
                    // This is the new closest one
                    index = e;
                    distance = d;
                }
            }

            // Don't tolerate ridiculous error.
            debugAssertM(distance < 0.02, "Edge missing while closing polygon.");

            last_vertex = edge[index].stop;
            cap._vertex.append(last_vertex);
        }
        
        //debugPrintf("\n");
        //debugPrintf("Cap (both) %f\n", cap.getArea());
        above.face.append(cap);
        below.face.append(cap.inverse());
    }

    // Make sure we put enough faces on each polyhedra
    debugAssert((above.face.length() == 0) || (above.face.length() >= 4));   
    debugAssert((below.face.length() == 0) || (below.face.length() >= 4));
}

///////////////////////////////////////////////

ConvexPolygon2D::ConvexPolygon2D(const Array<Vector2>& pts, bool reverse) : m_vertex(pts) {
    if (reverse) {
        m_vertex.reverse();
    }
}


bool ConvexPolygon2D::contains(const Vector2& p, bool reverse) const {
    // Compute the signed area of each polygon from p to an edge.  
    // If the area is non-negative for all polygons then p is inside 
    // the polygon.  (To adapt this algorithm for a concave polygon,
    // the *sum* of the areas must be non-negative).

    float r = reverse ? -1 : 1;

    for (int i0 = 0; i0 < m_vertex.size(); ++i0) {
        int i1 = (i0 + 1) % m_vertex.size();
        const Vector2& v0 = m_vertex[i0];
        const Vector2& v1 = m_vertex[i1];

        Vector2 e0 = v0 - p;
        Vector2 e1 = v1 - p;

        // Area = (1/2) cross product, negated to be ccw in
        // a 2D space; we neglect the 1/2
        float area = -(e0.x * e1.y - e0.y * e1.x);

        if (area * r < 0) {
            return false;
        }
    }

    return true;
}


}

