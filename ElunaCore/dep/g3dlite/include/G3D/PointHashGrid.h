/**
   @file PointHashGrid.h

   @maintainer Morgan McGuire, http://graphics.cs.williams.edu
   @created 2008-07-01
   @edited  2009-05-28

   Copyright 2000-2010, Morgan McGuire.
   All rights reserved.
*/
#ifndef G3D_PointHashGrid_h
#define G3D_PointHashGrid_h

#include "G3D/platform.h"
#include "G3D/EqualsTrait.h"
#include "G3D/HashTrait.h"
#include "G3D/Vector3.h"
#include "G3D/Vector3int32.h"
#include "G3D/Array.h"
#include "G3D/Table.h"
#include "G3D/AABox.h"
#include "G3D/Sphere.h"
#include "G3D/SmallArray.h"

namespace G3D {

/** 
    Storage of data in a sparse 3D grid of point-based data.  The
    space cost for <I>n</I> elements is O(<I>n</I>).  For data with
    approximately uniform density (with respect to the radius hint),
    the time cost of searching for neighbors is O(1).

    <i>Value</i> must be supported by a G3D::PositionTrait and
    G3D::EqualsTrait.  Overloads are provided for
    common G3D classes like G3D::Vector3.  For example:

   <pre>
    class EqualsFunc {
    public:
        static bool equals(const Data& p, const Data& q) {
            return p == q;
        }
    };
    
    class PosFunc {
    public:
        static void getPosition(const Data& d, Vector3& pos) {
            pos = d.location;
        }
    };

    PointHashGrid<Data, Data::PosFunc, Data::EqualsFunc> grid;
   </pre>

   If the Value class defines operator==, the Equalsfunc is optional:

   <pre>
    PointHashGrid<Data, Data::PosFunc> grid;
   </pre>

*/
template<class Value,
         class PosFunc    = PositionTrait<Value>, 
         class EqualsFunc = EqualsTrait<Value> >
class PointHashGrid {
private:

#   define expectedCellSize (3)

#   define ThisType PointHashGrid<Value, PosFunc, EqualsFunc>

    /** A value annotated with precomputed position and hash code.*/
    class Entry {
    public:
        Vector3			 position;
        Value			 value;
    };

    /** One cell of the grid. */
    typedef SmallArray<Entry, expectedCellSize> Cell;
    typedef Table<Vector3int32, Cell >          CellTable;

    /** The cube of +/-1 along each dimension. Initialized by initOffsetArray.*/
    Vector3int32        m_offsetArray[3*3*3];

    /** Incremented every time the data structure is mutated. 
        Used by the iterators to determine if the data structure
        has changed since iteration began. */
    int                 m_epoch;

    /** Extent of a cell along one dimension. */
    float               m_cellWidth;

    /** 1.0 / cell width */
    float               m_invCellWidth;

    /** Conservative bounds; the actual data may be smaller. */
    AABox               m_bounds;

    /** Number of elements. */
    int                 m_size;

    /** Non-empty cells indexed by grid position. Actual 3D position is 
        <code>position * m_cellWidth</code>*/
    CellTable           m_data;

    MemoryManager::Ref  m_memoryManager;

    /** Intentionally unimplemented: prevent copy construction. */
    PointHashGrid(const ThisType&);


    /** Intentionally unimplemented: prevent assignment. */
    PointHashGrid& operator=(const ThisType&);


    /** Locate the cell and index within that cell containing v. Called by
        remove() and contains(). */
    bool find(const Value&    v, 
              Vector3int32&   foundCellCoord, 
              Cell*&          foundCell, 
              int&            index) {
        
        Vector3 pos;
        PosFunc::getPosition(v, pos);

        Vector3int32 cellCoord;
        getCellCoord(pos, cellCoord);
        for (int i = 0; i < 27; ++i) {
            Vector3int32 c = cellCoord + m_offsetArray[i];
            Cell* cell = m_data.getPointer(c);
            if (cell != NULL) {
                // The cell exists
                for (int j = 0; j < cell->size(); ++j) {
                    if (EqualsFunc::equals((*cell)[j].value, v)) {
                        foundCell = cell;
                        index = j;
                        foundCellCoord = c;
                        return true;
                    }
                }
            }            
        }

        // Not found
        return false;        
    }

    /** Given a real-space position, returns the cell coord 
        containing it.*/
    inline void getCellCoord(const Vector3& pos, Vector3int32& cellCoord) const {
        for (int a = 0; a < 3; ++a) {
            cellCoord[a] = iFloor(pos[a] * m_invCellWidth);
        }
    }

    /** Initializes m_offsetArray. */
    void initOffsetArray() {
        int i = 0;
        Vector3int32 d;
        for (d.x = -1; d.x <= +1; ++d.x) {
            for (d.y = -1; d.y <= +1; ++d.y) {
                for (d.z = -1; d.z <= +1; ++d.z) {
                    m_offsetArray[i] = d;
                    ++i;
                }
            }
        }
        
        // Put (0, 0, 0) first, so that contains() is most likely to find
        // the value quickly.
        i = (1 * 3 + 1) * 3 + 1;
        debugAssert(m_offsetArray[i] == Vector3int32(0,0,0));
        Vector3int32 temp = m_offsetArray[0];
        m_offsetArray[0] = m_offsetArray[i];
        m_offsetArray[i] = temp;
    }

public:

    /** 
        @param radiusHint the radius that will typically be used with 
        beginSphereIntersection and beginBoxIntersection. If two <i>Value</i>s are equal,
        their positions must be within this radius as well.
    */
    PointHashGrid(float radiusHint, const MemoryManager::Ref& m = MemoryManager::create()) : m_size(0), m_memoryManager(m) {
        initOffsetArray();
        m_data.clearAndSetMemoryManager(m_memoryManager);

        debugAssertM(radiusHint > 0, "Cell radius must be positive");
        m_cellWidth = radiusHint;
        m_invCellWidth = 1.0f / m_cellWidth;
    }

    /**
       If radiusHint is negative, it is automatically chosen to put 
       about 5 values in each grid cell (which means about 27 * 5 
       values for each beginIntersection call).
    */
    PointHashGrid(const Array<Value>& init, float radiusHint = -1.0f, const MemoryManager::Ref& m = MemoryManager::create()) : m_size(0), m_memoryManager(m) {		
        initOffsetArray();
        m_data.clearAndSetMemoryManager(m_memoryManager);

        Vector3 lo(Vector3::inf());
        Vector3 hi(-lo);

        // Compute bounds
        Array<Entry> entry(init.size());
        for (int i = 0; i < entry.size(); ++i) {
            const Value& value = init[i];
            Vector3 pos;

            entry[i].value     = value;
            entry[i].hashCode  = m_hashFunc(value);
            PosFunc::getPosition(value, entry[i].position);

            lo = lo.min(pos);
            hi = hi.max(pos);
        }

        m_bounds = AABox(lo, hi);

        if (radiusHint <= 0) {
            // Compute a good cell width based on the bounds.
            //
            //   N        numPerCell
            // -----   =  ---------
            // volume        r^3

            float numPerCell = 5;
            radiusHint = 
                (float)pow(numPerCell * m_bounds.volume() / init.size(), 1.0 / 3.0);

            if (radiusHint == 0) {
                // Volume must have been zero because all points were colocated.
                radiusHint = 0.1f;
            }
        }

        insert(init);
    }

    /** Returns the number of elements. */
    inline int size() const {
        return m_size;
    }

    /** Returns a conservative bounding box around the contents. This is 
        conservative because it is not updated when elements are removed. */
    const AABox& conservativeBoxBounds() const {
        return m_bounds;
    }

    /** Insert @a v at position @a p given by <code>getPosition(v, p)</code>.  
        Multiple elements that are equal may be inserted; all copies will be
        in the data structure. */
    void insert(const Value& v) {
        Vector3 pos;
        PosFunc::getPosition(v, pos);
        Vector3int32 cellCoord;
        getCellCoord(pos, cellCoord);

        // See if the cell already exists
        Cell& cell = m_data.getCreate(cellCoord);

        if (cell.size() == 0) {
            // Use the same memory manager as for the whole class
            cell.clearAndSetMemoryManager(m_memoryManager);
        }

        Entry& entry    = cell.next();
        entry.value     = v;
        entry.position  = pos;

        // Update the bounds
        if (size() == 0) {
            m_bounds = AABox(pos);
        } else {
            m_bounds.merge(pos);
        }

        ++m_size;
        ++m_epoch;
    }


    /** Inserts all elements of the array. */
    void insert(const Array<Value>& v) {
        for (int i = 0; i < v.size(); ++i) {
            insert(v[i]);
        }
    }


    /** If there are multiple copies of an element, you must
        delete them multiple times.

        @param shrinkIfNecessary If <b>true</b>, deallocate underlying data 
        structures as they are emptied.  False increases performace at 
        the cost of memory overhead for dynamic structures.
        
        @return true if the element was found.
    */
    bool remove(const Value& v, bool shrinkIfNecessary = true) {
        Cell* cell = NULL;
        int   index = 0;
        Vector3int32 cellCoord;

        if (find(v, cellCoord, cell, index)) {
            cell->fastRemove(index, shrinkIfNecessary);
            --m_size;
            ++m_epoch;

            if ((cell->size() == 0) && shrinkIfNecessary) {
                // Remove the cell itself

                // Drop our pointer, which is about to dangle
                cell = NULL;
                bool success = m_data.remove(cellCoord);
                debugAssertM(success, "Data structure corrupt: "
                             "tried to remove a cell that doesn't exist.");
            }

            return true;

        } else {
            return false;
        }
    }

    /** Removes all elements of @v. */
    void remove(const Array<Value>& v, bool shrink = true) {
        for (int i = 0; i < v.size(); ++i) {
            remove(v[i], shrink);
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    class Iterator {
    private:
        friend class ThisType;

        bool                                    m_isEnd;

        const ThisType*                         m_grid;
        
        typename CellTable::Iterator            m_tableIterator;

        /** Index within m_tableIterator->value of the current value. */
        int                                     m_arrayIndex;

        const int                               m_epoch;

        /** End iterator. Note that the m_tableIterator is initialized to the end iterator
            of a temporary value!  This is ok because we'll never look at the value of the 
            m_tableIterator, since we're initializing the "end" Iterator.*/
        Iterator() : m_isEnd(true), m_grid(NULL), m_tableIterator(CellTable().end()), 
                     m_arrayIndex(0), m_epoch(0) {}

        Iterator(const ThisType* grid) : 
            m_isEnd(grid->size() == 0),
            m_grid(grid),
            m_tableIterator( grid->m_data.begin() ),
            m_arrayIndex(0),
            m_epoch(grid->m_epoch) { }

    private:

        const Value& value() const {
            debugAssert(! m_isEnd);
            debugAssertM(m_tableIterator->value.size() > m_arrayIndex, 
                         "No more elements");
            return m_tableIterator->value[m_arrayIndex].value;
        }

    public:

        inline bool operator!=(const Iterator& other) const {
            if (other.m_isEnd && m_isEnd) {
                return false;
            } else {
                return (m_isEnd         != other.m_isEnd) ||
                    (m_tableIterator != other.m_tableIterator) || 
                    (m_arrayIndex    != other.m_arrayIndex);
            }
        }

        bool hasMore() const {
            return ! m_isEnd;
        }

        bool operator==(const Iterator& other) const {
            return !(*this != other);
        }

        /** Preincrement */
        Iterator& operator++() {
            debugAssert(! m_isEnd);
            debugAssertM(m_epoch == m_grid->m_epoch, 
                         "It is illegal to mutate the HashGrid "
                         "while iterating through it.");

            ++m_arrayIndex;

            if (m_arrayIndex >= m_tableIterator->value.size()) {
                // Move on to the next cell
                ++m_tableIterator;
                m_arrayIndex = 0;

                // Check to see if we're at the end
                m_isEnd = (m_tableIterator == m_grid->m_data.end());
            }

            return *this;
        }

        /** Post increment (slower) */
        Iterator operator++(int) {
            debugAssert(! m_isEnd);
            Iterator old = *this;
            ++(*this);
            return old;
        }

        const Value& operator*()  const { return  value(); }
        const Value* operator->() const { return &value(); }
        operator Value*()         const { return &value(); }
    }; // Iterator


    /** Iterate through all members.  It is an error to mutate the HashGrid 
        while iterating through it. Each member can be accessed by "dereferencing"
        the iterator:
        
        <pre>
        for (Grid::Iterator i = grid.begin(); i != grid.end(), ++i) {
        const Value& = *i;
        ...
        }
        </pre>
    */
    Iterator begin() const {
        return Iterator(this);
    }

    const Iterator& end() const {
        static const Iterator it;
        return it;
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    // Forward declaration required by older gcc versions for friend declaration in BoxIterator
    class SphereIterator;
    class BoxIterator {
    private:
        friend class ThisType;
        friend class SphereIterator;

        bool                                    m_isEnd;

        const ThisType*                         m_grid;

        /** Lower bound on the boxes covered, inclusive. */
        Vector3int32                            m_lo;

        /** Upper bound on the boxes covered, inclusive.*/
        Vector3int32                            m_hi;
        
        /** If true, test values against m_box before returning them.*/
        bool                                    m_exact;

        /** The underlying box in 3D space */
        AABox                                   m_box;

        /** The iterator winds through the 3D grid between m_lo and (m_lo + m_extent) in
            Z,Y,X-major order.  This is the index keeping track of how
            far it has come */
        Vector3int32                            m_current;
        
        /** The current cell. */
        Cell*                                   m_cell;

        /** Index within m_cell of the current value */
        int                                     m_arrayIndex;

        const int                               m_epoch;
      

        /** Called from advance() */
        void advanceCell() {
            do {
                ++m_current.x;
                if (m_current.x > m_hi.x) {
                    m_current.x = m_lo.x;
                    ++m_current.y;
                    if (m_current.y > m_hi.y) {
                        m_current.y = m_lo.y;
                        ++m_current.z;
                        if (m_current.z > m_hi.z) {
                            m_isEnd = true;
                            return;
                        }
                    }
                }

                // Pick up the new cell
                m_cell = m_grid->m_data.getPointer(m_current);
                // Keep advancing if the cell does not exist
            } while ((m_cell == NULL) || (m_cell->size() == 0));
        }

        /** Advance to the next value */
        void advance() {
            debugAssert(! m_isEnd);

            do {
                ++m_arrayIndex;
                bool inConstructor = (m_cell == NULL);
                if (inConstructor || m_arrayIndex >= m_cell->size()) {
                    advanceCell();
                    m_arrayIndex = 0;

                    if (m_isEnd) {
                        // Ran out of values
                        return;
                    }
                    debugAssert(m_cell != NULL);
                }

                // Advance until we have a value that can be returned, either
                // because we don't care about exactness or because it is 
                // guaranteed to be within the box.
            } while (m_exact && ! m_box.contains(position()));
        }


        /** End iterator */
        BoxIterator() : m_isEnd(true), m_grid(NULL), m_exact(true), m_current(0,0,0), m_cell(NULL), m_arrayIndex(0), m_epoch(0) {}

        /** Begin iterator */
        BoxIterator(const ThisType* grid, bool exact, const AABox& box) : 
            m_isEnd(false),
            m_grid(grid),
            m_exact(exact),
            m_box(box),
            m_current(-1, 0 ,0),
            m_cell(NULL),
            m_arrayIndex(0),
            m_epoch(grid->m_epoch) { 

            m_grid->getCellCoord(box.low(), m_lo);
            m_grid->getCellCoord(box.high(), m_hi);
            
            // Get to the first value
            m_current = m_lo;
            // Back up one so that advancing takes us to the first
            --m_current.x;
            advance();
        }

        const Value& value() const {
            debugAssert(! m_isEnd);
            return (*m_cell)[m_arrayIndex].value;
        }

        /** Used by SphereIterator::advance() */
        const Vector3& position() const {
            debugAssert(! m_isEnd);
            return (*m_cell)[m_arrayIndex].position;
        }

        // Intentionally unimplemented
        BoxIterator& operator=(const BoxIterator&);

    public:

        inline bool operator!=(const BoxIterator& other) const {
            if (other.m_isEnd && m_isEnd) {
                return false;
            } else {
                return (m_isEnd         != other.m_isEnd) ||
                    (m_cell          != other.m_cell) || 
                    (m_arrayIndex    != other.m_arrayIndex);
            }
        }

        bool operator==(const BoxIterator& other) const {
            return !(*this != other);
        }

        /** Preincrement */
        BoxIterator& operator++() {
            debugAssert(! m_isEnd);
            debugAssertM(m_epoch == m_grid->m_epoch, 
                         "It is illegal to mutate the HashGrid "
                         "while iterating through it.");

            advance();

            return *this;
        }

        /** Post increment (slower) */
        BoxIterator operator++(int) {
            Iterator old = *this;
            ++(*this);
            return old;
        }

        const Value& operator*()  const { return  value(); }
        const Value* operator->() const { return &value(); }
        operator Value*()         const { return &value(); }

        bool hasMore() const {
            return ! m_isEnd;
        }
    }; // BoxIterator

    /** 
        Finds all values whose positions are within @a box.  It is an error to 
        mutate the PointHashGrid while iterating through it.

        @param exact If false, the iterator will execute more quickly but will likely return some
        values that lie outside the box. Set exact = false if you are going to test the 
        results against the yourself box anyway.
    */
    BoxIterator beginBoxIntersection(const AABox& box, bool exact = true) const {
        return BoxIterator(this, exact, box);
    }

    const BoxIterator& endBoxIntersection() const {
        static const BoxIterator it;
        return it;
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    
    class SphereIterator {
    private:

        friend class ThisType;

        bool                m_isEnd;
        Sphere              m_sphere;
        BoxIterator         m_boxIterator;

        SphereIterator() : m_isEnd(true) {}

        void advance() {
            if (! m_boxIterator.hasMore()) {
                m_isEnd = true;
                return;
            }

            while (! m_sphere.contains(m_boxIterator.position())) {
                ++m_boxIterator;
                
                if (! m_boxIterator.hasMore()) {
                    m_isEnd = true;
                    return;
                }
            } 
        }

        static AABox getBoundingBox(const Sphere& s) {
            AABox box;
            s.getBounds(box);
            return box;
        }

        SphereIterator(const ThisType* grid, const Sphere& sphere) : 
            m_isEnd(false),
            m_sphere(sphere),
            m_boxIterator(grid, false, getBoundingBox(sphere)) {
			
            // Find the first element that is actually in the sphere,
            // not just the box.
            advance();
        }

        const Value& value() const {			
            return *m_boxIterator;
        }

        // TODO: if the sphere is very big compared to radius, check each
        // cell's box to see if the cell itself is actually inside the sphere
        // before iterating through it, since there may be many boxes outside the sphere.

        // Intentionally unimplemented
        SphereIterator& operator=(const SphereIterator&);
    public:

        inline bool operator!=(const SphereIterator& other) const {
            if (other.m_isEnd && m_isEnd) {
                return false;
            } else {
                return 
                    (m_isEnd         != other.m_isEnd) ||
                    (m_sphere        != other.m_sphere) ||
                    (m_boxIterator   != other.m_boxIterator);
            }
        }

        bool operator==(const SphereIterator& other) const {
            return !(*this != other);
        }

	

        /** Preincrement */
        SphereIterator& operator++() {
            debugAssert(! m_isEnd);

            ++m_boxIterator;
            advance();

            return *this;
        }

        /** Post increment (slower) */
        SphereIterator operator++(int) {
            Iterator old = *this;
            ++(*this);
            return old;
        }

        const Value& operator*()  const { return  value(); }
        const Value* operator->() const { return &value(); }
        operator Value*()         const { return &value(); }

        bool hasMore() const {
            return ! m_isEnd;
        }
    }; // SphereIterator

    /** 
        Finds all values whose positions are within @a sphere.  It is an error
        to mutate the HashGrid while iterating through it.
    */
    SphereIterator beginSphereIntersection(const Sphere& sphere) const {
        return SphereIterator(this, sphere);
    }

    const SphereIterator& endSphereIntersection() const {
        static const SphereIterator it;
        return it;
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    /**
       Dereference to access the bounds() and size() [element count] of the underlying
       cell objet.

       Example:
       <pre>
       for(PointHashGrid<Vector3>::CellIterator iter = grid.beginCells(); iter != grid.endCells(); ++iter) {	
       entriesFound += iter->size();
       }
       </pre>
    */
    class CellIterator {
    private:
        friend class ThisType;

        bool                                    m_isEnd;
        const ThisType*                         m_grid;
        typename CellTable::Iterator            m_tableIterator;
        const int                               m_epoch;


        Cell& cell() {
            return m_tableIterator->value;
        }

    public:
        
        class CellObject {
            friend class CellIterator;
        private:
            const CellIterator* m_parent;

            CellObject() : m_parent(NULL) {}

        public:

            /** Returns the bounds on this cell */
            AABox bounds() const {
                const Vector3int32& k = m_parent->m_tableIterator->key;
                return AABox(Vector3(k) * m_parent->m_cellWidth, 
                             Vector3(k + Vector3int32(1, 1, 1)) * m_parent->m_cellWidth);
            }

            /** Number of elements inside this cell */
            int size() const {
                debugAssert(! m_parent->m_isEnd);
                return m_parent->m_tableIterator->value.size();
            }
        };

    private:
        /** Used to make the indirection work.*/
        CellObject m_indirection;

        /** End iterator. Note that the m_tableIterator is initialized to the end iterator
            of a temporary value!  This is ok because we'll never look at the value of the 
            m_tableIterator, since we're initializing the "end" Iterator.*/
        CellIterator() : 
            m_isEnd(true),
            m_grid(NULL),
            m_tableIterator( CellTable().end() ),
            m_epoch(0) {}
        
        CellIterator(const ThisType* grid) : 
            m_isEnd(false),
            m_grid(grid),
            m_tableIterator( grid->m_data.begin()),
            m_epoch(grid->m_epoch) {
            m_indirection.m_parent = this;
            m_isEnd = ! m_tableIterator.hasMore();
        }
        
        // Intentionally unimplemented
        CellIterator& operator=(const CellIterator&);

    public:

        const CellObject& operator*()  const { return  m_indirection; }
        const CellObject* operator->() const { return &m_indirection; }
        operator CellObject*()         const { return &m_indirection; }

        inline bool operator!=(const CellIterator& other) const {
            // != is called more often than == during iteration
            return !(
                     (m_isEnd && other.m_isEnd) ||
                     ((m_isEnd == other.m_isEnd) && 
                      (m_tableIterator != other.m_tableIterator)));
        }

        bool operator==(const CellIterator& other) const {
            return !(*this != other);
        }

        /** Preincrement */
        CellIterator& operator++() {
            debugAssertM(m_epoch == m_grid->m_epoch, 
                         "It is illegal to mutate the HashGrid while "
                         "iterating through it.");
            ++m_tableIterator;
            m_isEnd = ! m_tableIterator.hasMore();
            return *this;
        }

        /** Post increment (slower) */
        CellIterator operator++(int) {
            Iterator old = *this;
            ++(*this);
            return old;
        }

        bool hasMore() const {
            return ! m_isEnd;
        }
    }; // CellIterator

    /** Iterates through the non-empty cells.  This is intended primarily for
        debugging and visualizing the data structure.*/
    CellIterator beginCells() const {
        return CellIterator(this);
    }

    const CellIterator& endCells() const {
        static const CellIterator it;
        return it;
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    /** Returns true if there is a value that is exactly equal to @a v. This will 
        check all neighboring cells to avoid roundoff error at cell boundaries. 
    */
    bool contains(const Value& v) const {
        Cell* cell = NULL;
        int   index = 0;
        Vector3int32 cellCoord;
        return const_cast<ThisType*>(this)->find(v, cellCoord, cell, index);
    }

    /** Calls delete on all of the values, which are assumed to be pointers. 
        This is a helper to avoid requiring you to iterate through the data 
        structure, removing and deleting each one. Clears the PointHashGrid at the
        end.
		
        Using objects (instead of pointers) or reference counted pointers is 
        recommended over using pointers and this deleteAll method.*/
    void deleteAll() {
        for (Iterator it = begin(); it.hasMore(); ++it) {
            delete *it;
        }
        clear();
    }

    void clearAndSetMemoryManager(const MemoryManager::Ref& m) {
        ++m_epoch;
        m_size = 0;
        m_bounds = AABox();

        m_data.clearAndSetMemoryManager(m);
        m_memoryManager = m;
    }

    /** Removes all data. 
        @param shrink If true, underlying structures are deallocated as
        they are freed.*/
    void clear(bool shrink = true) {
        m_size = 0;
        m_bounds = AABox();
        if (! shrink) {
            // Remove all data
            for (CellIterator it = beginCells(); it.hasMore(); ++it) {
                it.cell().clear(true);
            }
        } else {
            m_data.clear();
        }
        ++m_epoch;
    }

    int debugGetDeepestBucketSize() const {
        return m_data.debugGetDeepestBucketSize();
    }

    float debugGetAverageBucketSize() const {
        return m_data.debugGetAverageBucketSize();
    }
#undef ThisType 
};

} // G3D
#endif
