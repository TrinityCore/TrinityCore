/*
* Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
*
* Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
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

#ifndef _TREENODE_H
#define _TREENODE_H

#include "ShortVector.h"
#include "ShortBox.h"
#include "NodeValueAccess.h"
#include "VMapTools.h"

#include <G3D/Vector3.h>
#include <G3D/AABox.h>

namespace VMAP
{
    /**
    This Class is mainly taken from G3D/AABSPTree.h and modified to match our data structure.
    It is the node within our static BSP-Trees.
    It does not use pointers but indexes to access the values and other nodes.
    */

    //=====================================================

    class TreeNode
    {
    private:
        /** Location along the specified axis */
        float iSplitLocation;
        // Offest or the clients
        int iChilds[2];
        //Position within the TriangleBox array
        unsigned int iStartPosition;
        G3D::Vector3::Axis iSplitAxis;
        G3D::AABox iBounds;
        unsigned short iNumberOfValues;
    public:
        TreeNode() {}
        TreeNode(unsigned short pNValues, unsigned int pStartPosition)
        {
            iChilds[0] = -1;
            iChilds[1] = -1;
            iStartPosition = pStartPosition;
            iNumberOfValues = pNValues;
        }

        bool hasChilds() const { return(iChilds[0] >= 0 || iChilds[1] >= 0); }

        TreeNode const* getChild(TreeNode const* pValueArray, int pNo) const;
        // pChildNo = 0 or 1
        inline void setChildPos(int pChildNo, int pChildPosInTreeNodeArray) { iChilds[pChildNo] = pChildPosInTreeNodeArray; }

        inline G3D::Vector3::Axis getSplitAxis() const { return(iSplitAxis); }

        inline void setSplitAxis(G3D::Vector3::Axis a) { iSplitAxis = a; }
        inline void setSplitLocation(float l) { iSplitLocation = l; }

        inline void setBounds(const G3D::AABox& pBox) { iBounds = pBox; }

        inline void setBounds(const G3D::Vector3& lo, const G3D::Vector3& hi) { iBounds.set(lo,hi); }

        inline void getBounds(G3D::AABox& pBox) const { pBox.set(iBounds.low(),iBounds.high()); }

        inline float getSplitLocation() const { return(iSplitLocation); }

        inline unsigned short getNValues() const { return (iNumberOfValues); }

        inline unsigned int getStartPosition() const { return(iStartPosition); }

        inline bool operator==(const TreeNode& n) const
        {
            return ((iSplitLocation == n.iSplitLocation) &&
                (iChilds[0] == n.iChilds[0]) && (iChilds[1] == n.iChilds[1]) &&
                (iStartPosition == n.iStartPosition) &&
                (iSplitAxis == n.iSplitAxis) &&
                (iBounds == n.iBounds) &&
                (iNumberOfValues == n.iNumberOfValues));
        }

        inline bool operator!=(const TreeNode& n) const
        {
            return !((iSplitLocation == n.iSplitLocation) &&
                (iChilds[0] == n.iChilds[0]) && (iChilds[1] == n.iChilds[1]) &&
                (iStartPosition == n.iStartPosition) &&
                (iSplitAxis == n.iSplitAxis) &&
                (iBounds == n.iBounds) &&
                (iNumberOfValues == n.iNumberOfValues));
        }

        /** Returns true if the ray intersects this node */
        bool intersects(const G3D::Ray& ray, float distance) const {
            // See if the ray will ever hit this node or its children
            G3D::Vector3 location;
            bool alreadyInsideBounds = false;
            bool rayWillHitBounds =
                MyCollisionDetection::collisionLocationForMovingPointFixedAABox(
                ray.origin, ray.direction, iBounds, location, alreadyInsideBounds);

            bool canHitThisNode = (alreadyInsideBounds ||
                (rayWillHitBounds && ((location - ray.origin).squaredLength() < (distance*distance))));

            return canHitThisNode;
        }

        template<typename RayCallback, typename TNode, typename TValue>
        void intersectRay(
            const G3D::Ray& ray,
            RayCallback& intersectCallback,
            float& distance,
            const NodeValueAccess<TNode, TValue>& pNodeValueAccess,
            bool pStopAtFirstHit,
            bool intersectCallbackIsFast) const {
                float enterDistance = distance;
                if (! intersects(ray, distance)) {
                    // The ray doesn't hit this node, so it can't hit the children of the node.
                    return;
                }

                // Test for intersection against every object at this node.
                for (unsigned int v = iStartPosition; v < (iNumberOfValues+iStartPosition); ++v) {
                    const TValue& nodeValue = pNodeValueAccess.getValue(v);
                    bool canHitThisObject = true;
                    if (! intersectCallbackIsFast) {
                        // See if
                        G3D::Vector3 location;
                        const G3D::AABox& bounds = nodeValue.getAABoxBounds();
                        bool alreadyInsideBounds = false;
                        bool rayWillHitBounds =
                            MyCollisionDetection::collisionLocationForMovingPointFixedAABox(
                            ray.origin, ray.direction, bounds, location, alreadyInsideBounds);

                        canHitThisObject = (alreadyInsideBounds ||
                            (rayWillHitBounds && ((location - ray.origin).squaredLength() < (distance*distance))));
                    }

                    if (canHitThisObject) {
                        // It is possible that this ray hits this object.  Look for the intersection using the
                        // callback.
                        intersectCallback(ray, &nodeValue, pStopAtFirstHit, distance);
                    }
                    if(pStopAtFirstHit && distance < enterDistance)
                        return;
                }

                // There are three cases to consider next:
                //
                //  1. the ray can start on one side of the splitting plane and never enter the other,
                //  2. the ray can start on one side and enter the other, and
                //  3. the ray can travel exactly down the splitting plane

                enum {NONE = -1};
                int firstChild = NONE;
                int secondChild = NONE;

                if (ray.origin[iSplitAxis] < iSplitLocation) {

                    // The ray starts on the small side
                    firstChild = 0;

                    if (ray.direction[iSplitAxis] > 0) {
                        // The ray will eventually reach the other side
                        secondChild = 1;
                    }

                } else if (ray.origin[iSplitAxis] > iSplitLocation) {

                    // The ray starts on the large side
                    firstChild = 1;

                    if (ray.direction[iSplitAxis] < 0) {
                        secondChild = 0;
                    }
                } else {
                    // The ray starts on the splitting plane
                    if (ray.direction[iSplitAxis] < 0) {
                        // ...and goes to the small side
                        firstChild = 0;
                    } else if (ray.direction[iSplitAxis] > 0) {
                        // ...and goes to the large side
                        firstChild = 1;
                    }
                }

                // Test on the side closer to the ray origin.
                if ((firstChild != NONE) && iChilds[firstChild]>0) {
                    getChild(pNodeValueAccess.getNodePtr() , firstChild)->intersectRay(ray, intersectCallback, distance, pNodeValueAccess, pStopAtFirstHit,intersectCallbackIsFast);
                    if(pStopAtFirstHit && distance < enterDistance)
                        return;
                }
                if (ray.direction[iSplitAxis] != 0) {
                    // See if there was an intersection before hitting the splitting plane.
                    // If so, there is no need to look on the far side and recursion terminates.
                    float distanceToSplittingPlane = (iSplitLocation - ray.origin[iSplitAxis]) / ray.direction[iSplitAxis];
                    if (distanceToSplittingPlane > distance) {
                        // We aren't going to hit anything else before hitting the splitting plane,
                        // so don't bother looking on the far side of the splitting plane at the other
                        // child.
                        return;
                    }
                }
                // Test on the side farther from the ray origin.
                if ((secondChild != NONE) && iChilds[secondChild]>0) {
                    getChild(pNodeValueAccess.getNodePtr() , secondChild)->intersectRay(ray, intersectCallback, distance, pNodeValueAccess, pStopAtFirstHit,intersectCallbackIsFast);
                }
        }
    };
}
#endif

