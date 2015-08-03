/**
  @file KDTree.h
  
  @maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
  @created 2004-01-11
  @edited  2009-12-28

  Copyright 2000-2009, Morgan McGuire.
  All rights reserved.  
  */

#ifndef G3D_KDTree_h
#define G3D_KDTree_h

#include "G3D/platform.h"
#include "G3D/Array.h"
#include "G3D/Table.h"
#include "G3D/Vector2.h"
#include "G3D/Vector3.h"
#include "G3D/Vector4.h"
#include "G3D/AABox.h"
#include "G3D/Sphere.h"
#include "G3D/Box.h"
#include "G3D/Triangle.h"
#include "G3D/Ray.h"
#include "G3D/Frustum.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"
#include "G3D/CollisionDetection.h"
#include "G3D/BoundsTrait.h"
#include <algorithm>

// If defined, in debug mode the tree is checked for consistency
// as a way of detecting corruption due to implementation bugs
// #define VERIFY_TREE

template<> struct BoundsTrait<class G3D::Vector2> {
    static void getBounds(const G3D::Vector2& v, G3D::AABox& out) { out = G3D::AABox(G3D::Vector3(v, 0)); }
};

template<> struct BoundsTrait<class G3D::Vector3> {
    static void getBounds(const G3D::Vector3& v, G3D::AABox& out) { out = G3D::AABox(v); }
};

template<> struct BoundsTrait<class G3D::Vector4> {
    static void getBounds(const G3D::Vector4& v, G3D::AABox& out) { out = G3D::AABox(v.xyz()); }
};

template<> struct BoundsTrait<class G3D::AABox> {
    static void getBounds(const G3D::AABox& v, G3D::AABox& out) { out = v; }
};

template<> struct BoundsTrait<class G3D::Sphere> {
    static void getBounds(const G3D::Sphere& s, G3D::AABox& out) { s.getBounds(out); }
};

template<> struct BoundsTrait<class G3D::Box> {
    static void getBounds(const G3D::Box& b, G3D::AABox& out) { b.getBounds(out); }
};

template<> struct BoundsTrait<class G3D::Vector2*> {
    static void getBounds(const G3D::Vector2*& v, G3D::AABox& out) { out = G3D::AABox(G3D::Vector3(*v, 0)); }
};

template<> struct BoundsTrait<class G3D::Vector3*> {
    static void getBounds(const G3D::Vector3*& v, G3D::AABox& out) { out = G3D::AABox(*v); }
};

template<> struct BoundsTrait<class G3D::Vector4*> {
    static void getBounds(const G3D::Vector4*& v, G3D::AABox& out) { out = G3D::AABox(v->xyz()); }
};

template<> struct BoundsTrait<class G3D::AABox*> {
    static void getBounds(const G3D::AABox*& v, G3D::AABox& out) { out = *v; }
};

template<> struct BoundsTrait<class G3D::Sphere*> {
    static void getBounds(const G3D::Sphere*& s, G3D::AABox& out) { s->getBounds(out); }
};

template<> struct BoundsTrait<class G3D::Box*> {
    static void getBounds(const G3D::Box*& b, G3D::AABox& out) { b->getBounds(out); }
};


template<> struct BoundsTrait<class G3D::Triangle*> {
    static void getBounds(const G3D::Triangle*& t, G3D::AABox& out) { t->getBounds(out); }
};

namespace G3D {
    namespace _internal {

    /**
     Wraps a pointer value so that it can be treated as the instance itself;
     convenient for inserting pointers into a Table but using the 
     object equality instead of pointer equality.
    */
    template<class Type>
    class Indirector {
    public:
        Type*         handle;

        inline Indirector(Type* h) : handle(h) {}

        inline Indirector() : handle(NULL) {}

        /** Returns true iff the values referenced by the handles are equivalent. */
        inline bool operator==(const Indirector& m) const {
            return *handle == *(m.handle);
        }

        inline bool operator==(const Type& m) const {
            return *handle == m;
        }

        inline size_t hashCode() const {
            return handle->hashCode();
        }
    };
 } // namespace internal
} // namespace G3D

template <class Handle> struct HashTrait<typename G3D::_internal::Indirector<Handle> > {
    static size_t hashCode(const G3D::_internal::Indirector<Handle>& key) { return key.hashCode(); }
};

namespace G3D {

/**
 A set that supports spatial queries using a KD tree (axis-aligned
 BSP tree) for speed.

 KDTree allows you to quickly find objects in 3D that lie within
 a box or along a ray. For large sets of objects it is much faster
 than testing each object for a collision.

 KDTree is as powerful as but more general than a Quad Tree, Oct
 Tree, or regular KD tree that cycles through axes, but less general than an unconstrained BSP tree
 (which is much slower to create).
 
 Internally, objects
 are arranged into a tree according to their 
 axis-aligned bounds.  This increases the cost of insertion to
 O(log n) but allows fast overlap queries.

 <B>Template Parameters</B>
 <DT>The template parameter <I>T</I> must be one for which
 the following functions are all overloaded:

 <pre>
  T::T(); // public constructor of no arguments
  template <> struct HashTrait<T> { static size_t hashCode(int key); };
  template<> struct BoundsTrait<T> { static void getBounds(const T& obj, G3D::AABox& out); };
 </pre>

 G3D provides these for common classes like G3D::Vector3 and G3D::Sphere.
 If you use a custom class, or a pointer to a custom class, you will need
 to define those functions.

 <B>Moving %Set Members</B>
 <DT>It is important that objects do not move without updating the
 KDTree.  If the axis-aligned bounds of an object are about
 to change, KDTree::remove it before they change and 
 KDTree::insert it again afterward.  For objects
 where the hashCode and == operator are invariant with respect 
 to the 3D position,
 you can use the KDTree::update method as a shortcut to
 insert/remove an object in one step after it has moved.
 

 Note: Do not mutate any value once it has been inserted into KDTree. Values
 are copied interally. All KDTree iterators convert to pointers to constant
 values to reinforce this.

 If you want to mutate the objects you intend to store in a KDTree
 simply insert <I>pointers</I> to your objects instead of the objects
 themselves, and ensure that the above operations are defined. (And
 actually, because values are copied, if your values are large you may
 want to insert pointers anyway, to save space and make the balance
 operation faster.)

 <B>Dimensions</B>
 Although designed as a 3D-data structure, you can use the KDTree
 for data distributed along 2 or 1 axes by simply returning bounds
 that are always zero along one or more dimensions.

*/
template< class T, 
          class BoundsFunc = BoundsTrait<T>, 
          class HashFunc   = HashTrait<T>, 
          class EqualsFunc = EqualsTrait<T> > 
class KDTree {
protected:
#define TreeType KDTree<T, BoundsFunc, HashFunc, EqualsFunc>

    /** Wrapper for a value that includes a cache of its bounds. 
        Except for the test value used in a set-query operation, there
        is only ever one instance of the handle associated with any 
        value and the memberTable and Nodes maintain pointers to that
        heap-allocated value.
     */
    class Handle {
    public:
        /** The bounds of each object are constrained to AABox::large */
        AABox               bounds;

        /** Center of bounds.  We cache this value to avoid recomputing it
            during the median sort, and because MSVC 6 std::sort goes into
            an infinite loop if we compute the midpoint on the fly (possibly
            a floating point roundoff issue, where B<A and A<B both are true).*/
        Vector3             center;

        T                   value;

        Handle() {}

        inline Handle(const T& v) : value(v) {
            BoundsFunc::getBounds(v, bounds);
            bounds = bounds.intersect(AABox::large());
            center = bounds.center();
        }

        inline bool operator==(const Handle& other) const {
            return EqualsFunc::equals(value, other.value);
        }

        inline size_t hashCode() const {
            return HashFunc::hashCode(value);
        }
    };

    /** Returns the bounds of the sub array. Used by makeNode. */
    static AABox computeBounds(
        const Array<Handle*>& point, 
        int                   beginIndex,
        int                   endIndex) {
    
        Vector3 lo = Vector3::inf();
        Vector3 hi = -lo;

        debugAssertM(beginIndex <= endIndex, "No points");
        for (int p = beginIndex; p <= endIndex; ++p) {
            // This code is written with the vector min and max expanded
            // because otherwise it compiles incorrectly with -O3 on
            // gcc 3.4 

            const Vector3& pLo = point[p]->bounds.low();
            const Vector3& pHi = point[p]->bounds.high();
            for (int a = 0; a < 3; ++a) {
                lo[a] = G3D::min(lo[a], pLo[a]);
                hi[a] = G3D::max(hi[a], pHi[a]);
            }
        }

        return AABox(lo, hi);
    }

    /** Compares centers */
    class CenterComparator {
    public:
        Vector3::Axis sortAxis;

        CenterComparator(Vector3::Axis a) : sortAxis(a) {}

        inline int operator()(Handle* A, const Handle* B) const {
            float a = A->center[sortAxis];
            float b = B->center[sortAxis];

            if (a < b) {
                return 1;
            } else if (a > b) {
                return -1;
            } else {
                return 0;
            }
        }
    };


    /** Compares bounds for strict >, <, or overlap*/
    class BoundsComparator {
    public:
        Vector3::Axis sortAxis;

        BoundsComparator(Vector3::Axis a) : sortAxis(a) {}

        inline int operator()(Handle* A, const Handle* B) const {
            const AABox& a = A->bounds;
            const AABox& b = B->bounds;

            if (a.high()[sortAxis] < b.low()[sortAxis]) {
                return 1;
            } else if (a.low()[sortAxis] > b.high()[sortAxis]) {
                return -1;
            } else {
                return 0;
            }
        }
    };


    /** Compares bounds to the sort location */
    class Comparator {
    public:
        Vector3::Axis sortAxis;
        float sortLocation;

        Comparator(Vector3::Axis a, float l) : sortAxis(a), sortLocation(l) {}

        inline int operator()(Handle* ignore, const Handle* handle) const {
            (void)ignore;
            const AABox& box = handle->bounds;
            debugAssert(ignore == NULL);

            if (box.high()[sortAxis] < sortLocation) {
                // Box is strictly below the sort location
                return -1;
            } else if (box.low()[sortAxis] > sortLocation) {
                // Box is strictly above the sort location
                return 1;
            } else {
                // Box overlaps the sort location
                return 0;
            }
        }
    };

    // Using System::malloc with this class provided no speed improvement.
    class Node {
    public:

        /** Spatial bounds on all values at this node and its children, based purely on
            the parent's splitting planes.  May be infinite. */
        AABox               splitBounds;

        Vector3::Axis       splitAxis;

        /** Location along the specified axis */
        float               splitLocation;
 
        /** child[0] contains all values strictly 
            smaller than splitLocation along splitAxis.

            child[1] contains all values strictly
            larger.

            Both may be NULL if there are not enough
            values to bother recursing.
        */
        Node*               child[2];

        /** Array of values at this node (i.e., values
            straddling the split plane + all values if
            this is a leaf node). 

            This is an array of pointers because that minimizes
            data movement during tree building, which accounts 
            for about 15% of the time cost of tree building.
          */
        Array<Handle*>      valueArray;

        /** For each object in the value array, a copy of its bounds. 
            Packing these into an array at the node level
            instead putting them in the valueArray improves
            cache coherence, which is about a 3x performance
            increase when performing intersection computations.
          */
        Array<AABox>        boundsArray;

        /** Creates node with NULL children */
        Node() {
            splitAxis     = Vector3::X_AXIS;
            splitLocation = 0;
            splitBounds   = AABox(-Vector3::inf(), Vector3::inf());
            for (int i = 0; i < 2; ++i) {
                child[i] = NULL;
            }
        }

        /**
         Doesn't clone children.
         */
        Node(const Node& other) : valueArray(other.valueArray), boundsArray(other.boundsArray) {
            splitAxis       = other.splitAxis;
            splitLocation   = other.splitLocation;
            splitBounds     = other.splitBounds;            
            for (int i = 0; i < 2; ++i) {
                child[i] = NULL;
            }
        }

        /** Copies the specified subarray of pt into point, NULLs the children.
            Assumes a second pass will set splitBounds. */
        Node(const Array<Handle*>& pt) : valueArray(pt) {
            splitAxis     = Vector3::X_AXIS;
            splitLocation = 0;
            for (int i = 0; i < 2; ++i) {
                child[i] = NULL;
            }

            boundsArray.resize(valueArray.size());
            for (int i = 0; i < valueArray.size(); ++i) {
                boundsArray[i] = valueArray[i]->bounds;
            }
        }

        /** Deletes the children (but not the values) */
        ~Node() {
            for (int i = 0; i < 2; ++i) {
                delete child[i];
            }
        }

        /** Returns true if this node is a leaf (no children) */
        inline bool isLeaf() const {
            return (child[0] == NULL) && (child[1] == NULL);
        }


        /**
         Recursively appends all handles and children's handles
         to the array.
         */
        void getHandles(Array<Handle*>& handleArray) const {
            handleArray.append(valueArray);
            for (int i = 0; i < 2; ++i) {
                if (child[i] != NULL) {
                    child[i]->getHandles(handleArray);
                }
            }
        }

        void verifyNode(const Vector3& lo, const Vector3& hi) {
            //        debugPrintf("Verifying: split %d @ %f [%f, %f, %f], [%f, %f, %f]\n",
            //                splitAxis, splitLocation, lo.x, lo.y, lo.z, hi.x, hi.y, hi.z);
            
            debugAssertM(lo == splitBounds.low(),
                         format("lo = %s, splitBounds.lo = %s",
                                lo.toString().c_str(), splitBounds.low().toString().c_str()));
            debugAssert(hi == splitBounds.high());
            
            for (int i = 0; i < valueArray.length(); ++i) {
                const AABox& b = valueArray[i]->bounds;
                debugAssert(b == boundsArray[i]);
                (void)b;
                
                for(int axis = 0; axis < 3; ++axis) {
                    debugAssert(b.low()[axis] <= b.high()[axis]);
                    debugAssert(b.low()[axis] >= lo[axis]);
                    debugAssert(b.high()[axis] <= hi[axis]);
                }
            }
            
            if (child[0] || child[1]) {
                debugAssert(lo[splitAxis] < splitLocation);
                debugAssert(hi[splitAxis] > splitLocation);
            }
            
            Vector3 newLo = lo;
            newLo[splitAxis] = splitLocation;
            Vector3 newHi = hi;
            newHi[splitAxis] = splitLocation;
            
            if (child[0] != NULL) {
                child[0]->verifyNode(lo, newHi);
            }
            
            if (child[1] != NULL) {
                child[1]->verifyNode(newLo, hi);
            }
        }
        

        /**
          Stores the locations of the splitting planes (the structure but not the content)
          so that the tree can be quickly rebuilt from a previous configuration without 
          calling balance.
         */
        static void serializeStructure(const Node* n, BinaryOutput& bo) {
            if (n == NULL) {
                bo.writeUInt8(0);
            } else {
                bo.writeUInt8(1);
                n->splitBounds.serialize(bo);
                serialize(n->splitAxis, bo);
                bo.writeFloat32(n->splitLocation);
                for (int c = 0; c < 2; ++c) {
                    serializeStructure(n->child[c], bo);
                }
            }
        }

        /** Clears the member table */
        static Node* deserializeStructure(BinaryInput& bi) {
            if (bi.readUInt8() == 0) {
                return NULL;
            } else {
                Node* n = new Node();
                n->splitBounds.deserialize(bi);
                deserialize(n->splitAxis, bi);
                n->splitLocation = bi.readFloat32();
                for (int c = 0; c < 2; ++c) {
                    n->child[c] = deserializeStructure(bi);
                }
                return n;
            }
        }

        /** Returns the deepest node that completely contains bounds. */
        Node* findDeepestContainingNode(const AABox& bounds) {

            // See which side of the splitting plane the bounds are on
            if (bounds.high()[splitAxis] < splitLocation) {
                // Bounds are on the low side.  Recurse into the child
                // if it exists.
                if (child[0] != NULL) {
                    return child[0]->findDeepestContainingNode(bounds);
                }
            } else if (bounds.low()[splitAxis] > splitLocation) {
                // Bounds are on the high side, recurse into the child
                // if it exists.
                if (child[1] != NULL) {
                    return child[1]->findDeepestContainingNode(bounds);
                }
            }

            // There was no containing child, so this node is the
            // deepest containing node.
            return this;
        }


        /** Appends all members that intersect the box. 
            If useSphere is true, members that pass the box test
            face a second test against the sphere. */
        void getIntersectingMembers(
            const AABox&        box,
            const Sphere&       sphere,
            Array<T*>&          members,
            bool                useSphere) const {

            // Test all values at this node
            for (int v = 0; v < boundsArray.size(); ++v) {
                const AABox& bounds = boundsArray[v];
                if (bounds.intersects(box) &&
                    (! useSphere || bounds.intersects(sphere))) {
                    members.append(& (valueArray[v]->value));
                }
            }

            // If the left child overlaps the box, recurse into it
            if ((child[0] != NULL) && (box.low()[splitAxis] < splitLocation)) {
                child[0]->getIntersectingMembers(box, sphere, members, useSphere);
            }

            // If the right child overlaps the box, recurse into it
            if ((child[1] != NULL) && (box.high()[splitAxis] > splitLocation)) {
                child[1]->getIntersectingMembers(box, sphere, members, useSphere);
            }
        }

        /**
         Recurse through the tree, assigning splitBounds fields.
         */
        void assignSplitBounds(const AABox& myBounds) {
            splitBounds = myBounds;

            AABox childBounds[2];
            myBounds.split(splitAxis, splitLocation, childBounds[0], childBounds[1]);

#           if defined(G3D_DEBUG) && defined(VERIFY_TREE)
                // Verify the split
                for (int v = 0; v < boundsArray.size(); ++v) {
                    const AABox& bounds = boundsArray[v];
                    debugAssert(myBounds.contains(bounds));
                }
#           endif

            for (int c = 0; c < 2; ++c) {
                if (child[c]) {
                    child[c]->assignSplitBounds(childBounds[c]);
                }
            }
        }

        /** Returns true if the ray intersects this node */
        bool intersects(const Ray& ray, float distance) const {
            // See if the ray will ever hit this node or its children
            Vector3 location;
            bool alreadyInsideBounds = false;
            bool rayWillHitBounds = 
                CollisionDetection::collisionLocationForMovingPointFixedAABox(
                    ray.origin(), ray.direction(), splitBounds, location, alreadyInsideBounds);
           
            bool canHitThisNode = (alreadyInsideBounds ||                
                (rayWillHitBounds && ((location - ray.origin()).squaredLength() < square(distance))));

            return canHitThisNode;
        }

        template<typename RayCallback>
        void intersectRay(
            const Ray& ray, 
            RayCallback& intersectCallback, 
            float& distance,
            bool intersectCallbackIsFast) const {
            
            if (! intersects(ray, distance)) {
                // The ray doesn't hit this node, so it can't hit the children of the node.
                return;
            }

            // Test for intersection against every object at this node.
            for (int v = 0; v < valueArray.size(); ++v) {        
                bool canHitThisObject = true;

                if (! intersectCallbackIsFast) {
                    // See if
                    Vector3 location;
                    const AABox& bounds = boundsArray[v];
                    bool alreadyInsideBounds = false;
                    bool rayWillHitBounds = 
                        CollisionDetection::collisionLocationForMovingPointFixedAABox(
                            ray.origin(), ray.direction(), bounds, location, alreadyInsideBounds);

                    canHitThisObject = (alreadyInsideBounds ||                
                        (rayWillHitBounds && ((location - ray.origin()).squaredLength() < square(distance))));
                }

                if (canHitThisObject) {
                    // It is possible that this ray hits this object.  Look for the intersection using the
                    // callback.
                    const T& value = valueArray[v]->value;
                    intersectCallback(ray, value, distance);
                }
            }

            // There are three cases to consider next:
            // 
            //  1. the ray can start on one side of the splitting plane and never enter the other,
            //  2. the ray can start on one side and enter the other, and
            //  3. the ray can travel exactly down the splitting plane

            enum {NONE = -1};
            int firstChild = NONE;
            int secondChild = NONE;

            if (ray.origin()[splitAxis] < splitLocation) {
                
                // The ray starts on the small side
                firstChild = 0;

                if (ray.direction()[splitAxis] > 0) {
                    // The ray will eventually reach the other side
                    secondChild = 1;
                }

            } else if (ray.origin()[splitAxis] > splitLocation) {

                // The ray starts on the large side
                firstChild = 1;

                if (ray.direction()[splitAxis] < 0) {
                    secondChild = 0;
                }
            } else {
                // The ray starts on the splitting plane
                if (ray.direction()[splitAxis] < 0) {
                    // ...and goes to the small side
                    firstChild = 0;
                } else if (ray.direction()[splitAxis] > 0) {
                    // ...and goes to the large side
                    firstChild = 1;
                }
            }

            // Test on the side closer to the ray origin.
            if ((firstChild != NONE) && child[firstChild]) {
                child[firstChild]->intersectRay(ray, intersectCallback, distance, intersectCallbackIsFast);
            }

            if (ray.direction()[splitAxis] != 0) {
                // See if there was an intersection before hitting the splitting plane.  
                // If so, there is no need to look on the far side and recursion terminates.
                float distanceToSplittingPlane = (splitLocation - ray.origin()[splitAxis]) / ray.direction()[splitAxis];
                if (distanceToSplittingPlane > distance) {
                    // We aren't going to hit anything else before hitting the splitting plane,
                    // so don't bother looking on the far side of the splitting plane at the other
                    // child.
                    return;
                }
            }

            // Test on the side farther from the ray origin.
            if ((secondChild != NONE) && child[secondChild]) {
                child[secondChild]->intersectRay(ray, intersectCallback, distance, intersectCallbackIsFast);
            }

        }
    };


    /**
     Recursively subdivides the subarray.
    
     Clears the source array as soon as it is no longer needed.

     Call assignSplitBounds() on the root node after making a tree.
     */
    Node* makeNode(
        Array<Handle*>& source, 
        int valuesPerNode, 
        int numMeanSplits,
        Array<Handle*>& temp)  {

        Node* node = NULL;
        
        if (source.size() <= valuesPerNode) {
            // Make a new leaf node
            node = new Node(source);
            
            // Set the pointers in the memberTable
            for (int i = 0; i < source.size(); ++i) {
                memberTable.set(Member(source[i]), node);
            }
            source.clear();
            
        } else {
            // Make a new internal node
            node = new Node();
            
            const AABox& bounds = computeBounds(source, 0, source.size() - 1);
            const Vector3& extent = bounds.high() - bounds.low();
            
            Vector3::Axis splitAxis = extent.primaryAxis();
            
            float splitLocation;

            // Arrays for holding the children
            Array<Handle*> lt, gt;
                
            if (numMeanSplits <= 0) {

                source.medianPartition(lt, node->valueArray, gt, temp, CenterComparator(splitAxis));

                // Choose the split location to be the center of whatever fell in the center
                splitLocation = node->valueArray[0]->center[splitAxis];

                // Some of the elements in the lt or gt array might really overlap the split location.
                // Move them as needed.
                for (int i = 0; i < lt.size(); ++i) {
                    const AABox& bounds = lt[i]->bounds;
                    if ((bounds.low()[splitAxis] <= splitLocation) && (bounds.high()[splitAxis] >= splitLocation)) {
                        node->valueArray.append(lt[i]);
                        // Remove this element and process the new one that
                        // is swapped in in its place.
                        lt.fastRemove(i); --i;
                    }
                }

                for (int i = 0; i < gt.size(); ++i) {
                    const AABox& bounds = gt[i]->bounds;
                    if ((bounds.low()[splitAxis] <= splitLocation) && (bounds.high()[splitAxis] >= splitLocation)) {
                        node->valueArray.append(gt[i]);
                        // Remove this element and process the new one that
                        // is swapped in in its place.
                        gt.fastRemove(i); --i;
                    }
                }            

                if ((node->valueArray.size() > (source.size() / 2)) &&
                    (source.size() > 6)) {
                    // This was a bad partition; we ended up putting the splitting plane right in the middle of most of the 
                    // objects.  We could try to split on a different axis, or use a different partition (e.g., the extents mean, 
                    // or geometric mean).  This implementation falls back on the extents mean, since that case is already handled 
                    // below.
                    numMeanSplits = 1;
                }
            }

            // Note: numMeanSplits may have been increased by the code in the previous case above in order to
            // force a re-partition.

            if (numMeanSplits > 0) {
                // Split along the mean
                splitLocation = 
                    bounds.high()[splitAxis] * 0.5f + 
                    bounds.low()[splitAxis] * 0.5f;
                
                debugAssertM(isFinite(splitLocation),
                            "Internal error: split location must be finite.");

                source.partition(NULL, lt, node->valueArray, gt, Comparator(splitAxis, splitLocation));

                // The Comparator ensures that elements are strictly on the correct side of the split
            }


#           if defined(G3D_DEBUG) && defined(VERIFY_TREE)
                debugAssert(lt.size() + node->valueArray.size() + gt.size() == source.size());
                // Verify that all objects ended up on the correct side of the split.
                // (i.e., make sure that the Array partition was correct) 
                for (int i = 0; i < lt.size(); ++i) {
                    const AABox& bounds  = lt[i]->bounds;
                    debugAssert(bounds.high()[splitAxis] < splitLocation);
                }

                for (int i = 0; i < gt.size(); ++i) {
                    const AABox& bounds  = gt[i]->bounds;
                    debugAssert(bounds.low()[splitAxis] > splitLocation);
                }

                for (int i = 0; i < node->valueArray.size(); ++i) {
                    const AABox& bounds  = node->valueArray[i]->bounds;
                    debugAssert(bounds.high()[splitAxis] >= splitLocation);
                    debugAssert(bounds.low()[splitAxis] <= splitLocation);
                }
#           endif

            // The source array is no longer needed
            source.clear();

            node->splitAxis = splitAxis;
            node->splitLocation = splitLocation;

            // Update the bounds array and member table
            node->boundsArray.resize(node->valueArray.size());
            for (int i = 0; i < node->valueArray.size(); ++i) {
                Handle* v = node->valueArray[i];
                node->boundsArray[i] = v->bounds;
                memberTable.set(Member(v), node);
            }

            if (lt.size() > 0) {            
                node->child[0] = makeNode(lt, valuesPerNode, numMeanSplits - 1, temp);
            }
            
            if (gt.size() > 0) {
                node->child[1] = makeNode(gt, valuesPerNode, numMeanSplits - 1, temp);
            }
            
        }
        
        return node;
    }

    /**
     Recursively clone the passed in node tree, setting
     pointers for members in the memberTable as appropriate.
     called by the assignment operator.
     */
    Node* cloneTree(Node* src) {
        Node* dst = new Node(*src);

        // Make back pointers
        for (int i = 0; i < dst->valueArray.size(); ++i) {
            memberTable.set(Member(dst->valueArray[i]), dst);
        }

        // Clone children
        for (int i = 0; i < 2; ++i) {
            if (src->child[i] != NULL) {
                dst->child[i] = cloneTree(src->child[i]);
            }
        }

        return dst;
    }

   /**
    Wrapper for a Handle; used to create a memberTable that acts like Table<Handle, Node*> but
    stores only Handle* internally to avoid memory copies.
    */
    typedef _internal::Indirector<Handle> Member;

    typedef Table<Member, Node*> MemberTable;

    /** Maps members to the node containing them */
    MemberTable             memberTable;

    Node*                   root;

public:

    /** To construct a balanced tree, insert the elements and then call
      KDTree::balance(). */
    KDTree() : root(NULL) {}


    KDTree(const KDTree& src) : root(NULL) {
        *this = src;
    }


    KDTree& operator=(const KDTree& src) {
        delete root;
        // Clone tree takes care of filling out the memberTable.
        root = cloneTree(src.root);
        return *this;
    }


    ~KDTree() {
        clear();
    }

    /**
     Throws out all elements of the set.
     */
    void clear() {
        typedef typename Table<_internal::Indirector<Handle>, Node*>::Iterator It;
  
        // Delete all handles stored in the member table
        It cur = memberTable.begin();
        It end = memberTable.end();
        while (cur != end) {
            delete cur->key.handle;
            cur->key.handle = NULL;
            ++cur;
        }
        memberTable.clear();

        // Delete the tree structure itself
        delete root;
        root = NULL;
    }

    int size() const {
        return memberTable.size();
    }

    /**
     Inserts an object into the set if it is not
     already present.  O(log n) time.  Does not
     cause the tree to be balanced.
     */
    void insert(const T& value) {
        if (contains(value)) {
            // Already in the set
            return;
        }

        Handle* h = new Handle(value);

        if (root == NULL) {
            // This is the first node; create a root node
            root = new Node();
        }

        Node* node = root->findDeepestContainingNode(h->bounds);

        // Insert into the node
        node->valueArray.append(h);
        node->boundsArray.append(h->bounds);
        
        // Insert into the node table
        Member m(h);
        memberTable.set(m, node);
    }

    /** Inserts each elements in the array in turn.  If the tree
        begins empty (no structure and no elements), this is faster
        than inserting each element in turn.  You still need to balance
        the tree at the end.*/
    void insert(const Array<T>& valueArray) {
        if (root == NULL) {
            // Optimized case for an empty tree; don't bother
            // searching or reallocating the root node's valueArray
            // as we incrementally insert.
            root = new Node();
            root->valueArray.resize(valueArray.size());
            root->boundsArray.resize(root->valueArray.size());
            for (int i = 0; i < valueArray.size(); ++i) {
                // Insert in opposite order so that we have the exact same
                // data structure as if we inserted each (i.e., order is reversed
                // from array).
                Handle* h = new Handle(valueArray[i]);
                int j = valueArray.size() - i - 1;
                root->valueArray[j] = h;
                root->boundsArray[j] = h->bounds;
                memberTable.set(Member(h), root);
            }

        } else {
            // Insert at appropriate tree depth.
            for (int i = 0; i < valueArray.size(); ++i) {
                insert(valueArray[i]);
            }
        }
    }


    /**
     Returns true if this object is in the set, otherwise
     returns false.  O(1) time.
     */
    bool contains(const T& value) {
        // Temporarily create a handle and member
        Handle h(value);
        return memberTable.containsKey(Member(&h));
    }


    /**
     Removes an object from the set in O(1) time.
     It is an error to remove members that are not already
     present.  May unbalance the tree.  
     
     Removing an element never causes a node (split plane) to be removed...
     nodes are only changed when the tree is rebalanced.  This behavior
     is desirable because it allows the split planes to be serialized,
     and then deserialized into an empty tree which can be repopulated.
    */
    void remove(const T& value) {
        debugAssertM(contains(value),
            "Tried to remove an element from a "
            "KDTree that was not present");

        // Get the list of elements at the node
        Handle h(value);
        Member m(&h);

        Array<Handle*>& list = memberTable[m]->valueArray;

        Handle* ptr = NULL;

        // Find the element and remove it
        for (int i = list.length() - 1; i >= 0; --i) {
            if (list[i]->value == value) {
                // This was the element.  Grab the pointer so that
                // we can delete it below
                ptr = list[i];

                // Remove the handle from the node
                list.fastRemove(i);

                // Remove the corresponding bounds
                memberTable[m]->boundsArray.fastRemove(i);
                break;
            }
        }

        // Remove the member
        memberTable.remove(m);

        // Delete the handle data structure
        delete ptr;
        ptr = NULL;
    }


    /**
     If the element is in the set, it is removed.
     The element is then inserted.

     This is useful when the == and hashCode methods
     on <I>T</I> are independent of the bounds.  In
     that case, you may call update(v) to insert an
     element for the first time and call update(v)
     again every time it moves to keep the tree 
     up to date.
     */
    void update(const T& value) {
        if (contains(value)) {
            remove(value);
        }
        insert(value);
    }


    /**
     Rebalances the tree (slow).  Call when objects
     have moved substantially from their original positions
     (which unbalances the tree and causes the spatial
     queries to be slow).
     
     @param valuesPerNode Maximum number of elements to put at
     a node.

     @param numMeanSplits numMeanSplits = 0 gives a 
     fully axis aligned BSP-tree, where the balance operation attempts to balance
     the tree so that every splitting plane has an equal number of left
     and right children (i.e. it is a <B>median</B> split along that axis).  
     This tends to maximize average performance.  

     You can override this behavior by
     setting a number of <B>mean</B> (average) splits.  numMeanSplits = MAX_INT
     creates a full oct-tree, which tends to optimize peak performance at the expense of
     average performance.  It tends to have better clustering behavior when
     members are not uniformly distributed.
     */
    void balance(int valuesPerNode = 5, int numMeanSplits = 3) {
        if (root == NULL) {
            // Tree is empty
            return;
        }

        // Get all handles and delete the old tree structure
        Node* oldRoot = root;
        for (int c = 0; c < 2; ++c) {
            if (root->child[c] != NULL) {
                root->child[c]->getHandles(root->valueArray);

                // Delete the child; this will delete all structure below it
                delete root->child[c];
                root->child[c] = NULL;
            }
        }

        Array<Handle*> temp;
        // Make a new root.  Work with a copy of the value array because 
        // makeNode clears the source array as it progresses
        Array<Handle*> copy(oldRoot->valueArray);
        root = makeNode(copy, valuesPerNode, numMeanSplits, temp);

        // Throw away the old root node
        delete oldRoot;
        oldRoot = NULL;

        // Walk the tree, assigning splitBounds.  We start with unbounded
        // space.  This will override the current member table.
        const AABox& LARGE = AABox::large();
        root->assignSplitBounds(LARGE);

#       ifdef _DEBUG
        {
            // Ensure that the balanced tree is still correct
            root->verifyNode(LARGE.low(), LARGE.high());
        }
#       endif
    }


    /** Clear, set the contents to the values in the array, and then balance */
    void setContents(const Array<T>& array, int valuesPerNode = 5, int numMeanSplits = 3) {
        clear();
        insert(array);
        balance(valuesPerNode, numMeanSplits);
    }


protected:

    /**
     @param parentMask The mask that this node returned from culledBy.
     */
    static void getIntersectingMembers(
        const Array<Plane>&         plane,
        Array<T*>&                  members,
        Node*                       node,
        uint32                      parentMask) {

        int dummy;

        if (parentMask == 0) {
            // None of these planes can cull anything
            for (int v = node->valueArray.size() - 1; v >= 0; --v) {
                members.append(& (node->valueArray[v]->value));
            }

            // Iterate through child nodes
            for (int c = 0; c < 2; ++c) {
                if (node->child[c]) {
                    getIntersectingMembers(plane, members, node->child[c], 0);
                }
            }
        } else {

            // Test values at this node against remaining planes
            for (int v = node->boundsArray.size() - 1; v >= 0; --v) {
                if (! node->boundsArray[v].culledBy(plane, dummy, parentMask)) {
                    members.append(&(node->valueArray[v]->value));
                }
            }

            uint32 childMask  = 0xFFFFFF;

            // Iterate through child nodes
            for (int c = 0; c < 2; ++c) {
                if (node->child[c] &&
                    ! node->child[c]->splitBounds.culledBy(plane, dummy, parentMask, childMask)) {
                    // This node was not culled
                    getIntersectingMembers(plane, members, node->child[c], childMask);
                }
            }
        }
    }

public:

    /**
     Returns all members inside the set of planes.  
      @param members The results are appended to this array.
     */
    void getIntersectingMembers(const Array<Plane>& plane, Array<T*>& members) const {
        if (root == NULL) {
            return;
        }

        getIntersectingMembers(plane, members, root, 0xFFFFFF);
    }

    void getIntersectingMembers(const Array<Plane>& plane, Array<T>& members) const {
        Array<T*> temp;
        getIntersectingMembers(plane, temp, root, 0xFFFFFF);
        for (int i = 0; i < temp.size(); ++i) {
            members.append(*temp[i]);
        }
    }

    /**
     Typically used to find all visible
     objects inside the view frustum (see also Camera::getClipPlanes)... i.e. all objects
     <B>not</B> culled by frustum.

     Example:
      <PRE>
        Array<Object*>  visible;
        tree.getIntersectingMembers(camera.frustum(), visible);
        // ... Draw all objects in the visible array.
      </PRE>
      @param members The results are appended to this array.
      */
    void getIntersectingMembers(const Frustum& frustum, Array<T*>& members) const {
        Array<Plane> plane;
        
        for (int i = 0; i < frustum.faceArray.size(); ++i) {
            plane.append(frustum.faceArray[i].plane);
        }

        getIntersectingMembers(plane, members);
    }

    void getIntersectingMembers(const Frustum& frustum, Array<T>& members) const {
        Array<T*> temp;
        getIntersectingMembers(frustum, temp);
        for (int i = 0; i < temp.size(); ++i) {
            members.append(*temp[i]);
        }
    }

    /**
     C++ STL style iterator variable.  See beginBoxIntersection().
     The iterator overloads the -> (dereference) operator, so this
     acts like a pointer to the current member.
     */
    // This iterator turns Node::getIntersectingMembers into a
    // coroutine.  It first translates that method from recursive to
    // stack based, then captures the system state (analogous to a Scheme
    // continuation) after each element is appended to the member array,
    // and allowing the computation to be restarted.
    class BoxIntersectionIterator {
    private:
        friend class TreeType;

        /** True if this is the "end" iterator instance */
        bool            isEnd;

        /** The box that we're testing against. */
        AABox           box;

        /** Node that we're currently looking at.  Undefined if isEnd
            is true. */
        Node*           node;

        /** Nodes waiting to be processed */
        // We could use backpointers within the tree and careful
        // state management to avoid ever storing the stack-- but
        // it is much easier this way and only inefficient if the
        // caller uses post increment (which they shouldn't!).
        Array<Node*>    stack;

        /** The next index of current->valueArray to return. 
            Undefined when isEnd is true.*/
        int             nextValueArrayIndex;

        BoxIntersectionIterator() : isEnd(true) {}
        
        BoxIntersectionIterator(const AABox& b, const Node* root) : 
           isEnd(root == NULL), box(b), 
           node(const_cast<Node*>(root)), nextValueArrayIndex(-1) {

           // We intentionally start at the "-1" index of the current
           // node so we can use the preincrement operator to move
           // ourselves to element 0 instead of repeating all of the
           // code from the preincrement method.  Note that this might
           // cause us to become the "end" instance.
           ++(*this);
        }

    public:

        inline bool operator!=(const BoxIntersectionIterator& other) const {
            return ! (*this == other);
        }

        bool operator==(const BoxIntersectionIterator& other) const {
            if (isEnd) {
                return other.isEnd;
            } else if (other.isEnd) {
                return false;
            } else {
                // Two non-end iterators; see if they match.  This is kind of 
                // silly; users shouldn't call == on iterators in general unless
                // one of them is the end iterator.
                if ((box != other.box) || (node != other.node) || 
                    (nextValueArrayIndex != other.nextValueArrayIndex) ||
                    (stack.length() != other.stack.length())) {
                    return false;
                }

                // See if the stacks are the same
                for (int i = 0; i < stack.length(); ++i) {
                    if (stack[i] != other.stack[i]) {
                        return false;
                    }
                }

                // We failed to find a difference; they must be the same
                return true;
            }
        }

        /**
         Pre increment.
         */
        BoxIntersectionIterator& operator++() {
            ++nextValueArrayIndex;

            bool foundIntersection = false;
            while (! isEnd && ! foundIntersection) {

                // Search for the next node if we've exhausted this one
                while ((! isEnd) &&  (nextValueArrayIndex >= node->valueArray.length())) {
                    // If we entered this loop, then the iterator has exhausted the elements at 
                    // node (possibly because it just switched to a child node with no members).
                    // This loop continues until it finds a node with members or reaches
                    // the end of the whole intersection search.
                    
                    // If the right child overlaps the box, push it onto the stack for
                    // processing.
                    if ((node->child[1] != NULL) &&
                        (box.high()[node->splitAxis] > node->splitLocation)) {
                        stack.push(node->child[1]);
                    }
                    
                    // If the left child overlaps the box, push it onto the stack for
                    // processing.
                    if ((node->child[0] != NULL) &&
                        (box.low()[node->splitAxis] < node->splitLocation)) {
                        stack.push(node->child[0]);
                    }
                    
                    if (stack.length() > 0) {
                        // Go on to the next node (which may be either one of the ones we 
                        // just pushed, or one from farther back the tree).
                        node = stack.pop();
                        nextValueArrayIndex = 0;
                    } else {
                        // That was the last node; we're done iterating
                        isEnd = true;
                    }
                }
                
                // Search for the next intersection at this node until we run out of children
                while (! isEnd && ! foundIntersection && (nextValueArrayIndex < node->valueArray.length())) {
                    if (box.intersects(node->boundsArray[nextValueArrayIndex])) {
                        foundIntersection = true;
                    } else {
                        ++nextValueArrayIndex;
                        // If we exhaust this node, we'll loop around the master loop 
                        // to find a new node.
                    }
                }
            }

            return *this;
        }

    private:
        /**
         Post increment (much slower than preincrement!).
         Intentionally overloaded to preclude accidentally slow code.
         */
        BoxIntersectionIterator operator++(int);
        /*{
            BoxIntersectionIterator old = *this;
            ++this;
            return old;
        }*/

    public:

        /** Overloaded dereference operator so the iterator can masquerade as a pointer
            to a member */
        const T& operator*() const {
            alwaysAssertM(! isEnd, "Can't dereference the end element of an iterator");
            return node->valueArray[nextValueArrayIndex]->value;
        }

        /** Overloaded dereference operator so the iterator can masquerade as a pointer
            to a member */
        T const * operator->() const {
            alwaysAssertM(! isEnd, "Can't dereference the end element of an iterator");
            return &(stack.last()->valueArray[nextValueArrayIndex]->value);
        }

        /** Overloaded cast operator so the iterator can masquerade as a pointer
            to a member */
        operator T*() const {
            alwaysAssertM(! isEnd, "Can't dereference the end element of an iterator");
            return &(stack.last()->valueArray[nextValueArrayIndex]->value);
        }
    };


    /**
     Iterates through the members that intersect the box
     */
    BoxIntersectionIterator beginBoxIntersection(const AABox& box) const {
        return BoxIntersectionIterator(box, root);
    }

    BoxIntersectionIterator endBoxIntersection() const {
        // The "end" iterator instance
        return BoxIntersectionIterator();
    }

    /**
     Appends all members whose bounds intersect the box.
     See also KDTree::beginBoxIntersection.
     */
    void getIntersectingMembers(const AABox& box, Array<T*>& members) const {
        if (root == NULL) {
            return;
        }
        root->getIntersectingMembers(box, Sphere(Vector3::zero(), 0), members, false);
    }

    void getIntersectingMembers(const AABox& box, Array<T>& members) const {
        Array<T*> temp;
        getIntersectingMembers(box, temp);
        for (int i = 0; i < temp.size(); ++i) {
            members.append(*temp[i]);
        }
    }


    /**
     Invoke a callback for every member along a ray until the closest intersection is found.

     @param intersectCallback Either a function or an instance of a class with an overloaded operator() of the form:
     <pre>
         void callback(const Ray& ray, const T& object, float& distance).
     </pre>
     If the ray hits the object before travelling distance <code>distance</code>, updates
     <code>distance</code> with the new distance to the intersection, otherwise leaves it
     unmodified.  A common example is:
     \htmlonly
     <pre>
     class Entity {
     public:
         void intersect(const Ray& ray, float& maxDist, Vector3& outLocation, Vector3& outNormal) {
             float d = maxDist;

             // ... search for intersection distance d

             if ((d > 0) && (d < maxDist)) {
                 // Intersection occured
                 maxDist = d;
                 outLocation = ...;
                 outNormal = ...;
             }
         }
     };

     // Finds the surface normal and location of the first intersection with the scene
     class Intersection {
     public:
         Entity*     closestEntity;
         Vector3     hitLocation;
         Vector3     hitNormal;

         void operator()(const Ray& ray, const Entity* entity, float& distance) {
             entity->intersect(ray, distance, hitLocation, hitNormal);
         }
     };

     KDTree<Entity*> scene;

     Intersection intersection;
     float distance = finf();
     scene.intersectRay(camera.worldRay(x, y), intersection, distance);
     </pre>
     \endhtmlonly

     @param distance When the method is invoked, this is the maximum
     distance that the tree should search for an intersection.  On
     return, this is set to the distance to the first intersection
     encountered.

     @param intersectCallbackIsFast If false, each object's bounds are
      tested before the intersectCallback is invoked.  If the
      intersect callback runs at the same speed or faster than
      AABox-ray intersection, set this to true.
     */
    template<typename RayCallback>
    void intersectRay(
        const Ray& ray, 
        RayCallback& intersectCallback, 
        float& distance,
        bool intersectCallbackIsFast = false) const {
        
        root->intersectRay(ray, intersectCallback, distance, intersectCallbackIsFast);
    }


    /**
      @brief Finds all members whose bounding boxes intersect the sphere.  The actual
      elements may not intersect the sphere.

      @param members The results are appended to this array.
     */
    void getIntersectingMembers(const Sphere& sphere, Array<T*>& members) const {
        if (root == NULL) {
            return;
        }

        AABox box;
        sphere.getBounds(box);
        root->getIntersectingMembers(box, sphere, members, true);
    }

    void getIntersectingMembers(const Sphere& sphere, Array<T>& members) const {
        Array<T*> temp;
        getIntersectingMembers(sphere, temp);
        for (int i = 0; i < temp.size(); ++i) {
            members.append(*temp[i]);
        }
    }

    /**
      Stores the locations of the splitting planes (the structure but not the content)
      so that the tree can be quickly rebuilt from a previous configuration without 
      calling balance.
     */
    void serializeStructure(BinaryOutput& bo) const {
        Node::serializeStructure(root, bo);
    }

    /** Clears the member table */
    void deserializeStructure(BinaryInput& bi) {
        clear();
        root = Node::deserializeStructure(bi);
    }

    /**
     Returns an array of all members of the set.  See also KDTree::begin.
     */
    void getMembers(Array<T>& members) const {
        Array<Member> temp;
        memberTable.getKeys(temp);
        for (int i = 0; i < temp.size(); ++i) {
            members.append(*(temp.handle));
        }
    }


    /** If a value that is EqualsFunc to @a value is present, returns a pointer to the 
        version stored in the data structure, otherwise returns NULL.
     */
    const T* getPointer(const T& value) const {
        // Temporarily create a handle and member
        Handle h(value);
        const Member* member = memberTable.getKeyPointer(Member(&h));
        if (member == NULL) {
            // Not found
            return NULL;
        } else {
            return &(member->handle->value);
        }
    }


    /**
     C++ STL style iterator variable.  See begin().
     Overloads the -> (dereference) operator, so this acts like a pointer
     to the current member.
    */
    class Iterator {
    private:
        friend class TreeType;

        // Note: this is a Table iterator, we are currently defining
        // Set iterator
        typename Table<Member, Node*>::Iterator it;

        Iterator(const typename Table<Member, Node*>::Iterator& it) : it(it) {}

    public:

        inline bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }

        bool operator==(const Iterator& other) const {
            return it == other.it;
        }

        /**
         Pre increment.
         */
        Iterator& operator++() {
            ++it;
            return *this;
        }

    private:
        /**
         Post increment (slower than preincrement).  Intentionally unimplemented to prevent slow code.
         */
        Iterator operator++(int);/* {
            Iterator old = *this;
            ++(*this);
            return old;
        }*/
    public:

        const T& operator*() const {
            return it->key.handle->value;
        }

        T* operator->() const {
            return &(it->key.handle->value);
        }

        operator T*() const {
            return &(it->key.handle->value);
        }
    };


    /**
     C++ STL style iterator method.  Returns the first member.  
     Use preincrement (++entry) to get to the next element (iteration
     order is arbitrary).  
     Do not modify the set while iterating.
     */
    Iterator begin() const {
        return Iterator(memberTable.begin());
    }


    /**
     C++ STL style iterator method.  Returns one after the last iterator
     element.
     */
    Iterator end() const {
        return Iterator(memberTable.end());
    }
#undef TreeType
};


}

#endif
