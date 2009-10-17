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

#ifndef _SHORTBOX_H
#define _SHORTBOX_H

#include <G3D/Vector3.h>
#include <G3D/AABox.h>
#include <G3D/Triangle.h>
#include <G3D/Ray.h>

#include "ShortVector.h"

/**
This is a box and a triangle Class using ShortVectors. Each vector has 16 bit an a fixed point 12.4 representation.
*/

namespace VMAP
{

    class ShortBox
    {
        private:
            ShortVector iV1;
            ShortVector iV2;
        public:
            ShortBox() {}
            inline const ShortVector& getLo() const { return(iV1); }
            inline const ShortVector& getHi() const { return(iV2); }
            inline void setLo(const ShortVector& pV){ iV1 = pV; }
            inline void setHi(const ShortVector& pV){ iV2 = pV; }
            inline void setLo(const G3D::Vector3& pV){ iV1 = ShortVector(pV); }
            inline void setHi(const G3D::Vector3& pV){ iV2 = ShortVector(pV); }

            inline bool operator==(const ShortBox& b) const
            {
                return ((iV1 == b.iV1) && (iV2 == b.iV2));
            }

            inline bool operator!=(const ShortBox& b) const
            {
                return !((iV1 == b.iV1) && (iV2 == b.iV2));
            }
    };

    //=====================================================================
#ifdef _DEBUG_VMAPS
#ifndef gBoxArray
    extern G3D::Vector3 p1,p2,p3,p4,p5,p6,p7;
    extern G3D::Array<G3D::AABox>gBoxArray;
    extern G3D::Array<G3D::Triangle>gTriArray;
    extern int gCount1, gCount2, gCount3, gCount4;
    extern bool myfound;
#endif
#endif

    static const G3D::Vector3 dummyZeroPosition = G3D::Vector3(0,0,0);

    class TriangleBox
    {
        private:
            ShortVector _vertex[3];
            //ShortBox iBox;
        public:
            inline TriangleBox() { }
            inline TriangleBox(const ShortVector& pV1, const ShortVector& pV2, const ShortVector& pV3)
            {
                _vertex[0] = pV1;
                _vertex[1] = pV2;
                _vertex[2] = pV3;

            }
            inline const ShortVector& vertex (int n) const
            {
                return(_vertex[n]);
            }

            inline const ShortBox getBounds()const
            {
                ShortBox box;

                ShortVector lo = _vertex[0];
                ShortVector hi = lo;

                for (int i = 1; i < 3; ++i)
                {
                    lo = lo.min(_vertex[i]);
                    hi = hi.max(_vertex[i]);
                }
                box.setLo(lo);
                box.setHi(hi);
                return(box);
            }
            inline const G3D::Vector3& getBasePosition() { return(dummyZeroPosition); }

            inline const G3D::AABox getAABoxBounds() const { ShortBox box = getBounds(); return(G3D::AABox(box.getLo().getVector3(), box.getHi().getVector3())); }

            inline bool operator==(const TriangleBox& t) const
            {
                return ((_vertex[0] == t._vertex[0]) && (_vertex[1] == t._vertex[1]) &&(_vertex[2] == t._vertex[2]));
            }

            inline bool operator!=(const TriangleBox& t) const
            {
                return !((_vertex[0] == t._vertex[0]) && (_vertex[1] == t._vertex[1]) &&(_vertex[2] == t._vertex[2]));
            }

            inline void intersect(const G3D::Ray& pRay, float& pMaxDist, bool /*pStopAtFirstHitDummy*/, G3D::Vector3& /*pOutLocationDummy*/, G3D::Vector3& /*pOutNormalDummy*/) const
            {
                static const double epsilon = 0.00001;
                G3D::Triangle testT(vertex(0).getVector3(),vertex(1).getVector3(),vertex(2).getVector3());
                float t = pRay.intersectionTime(testT);
                if ((t < pMaxDist) || t < (pMaxDist + epsilon))
                    pMaxDist = t;
                else
                {
                    testT = G3D::Triangle(vertex(2).getVector3(),vertex(1).getVector3(),vertex(0).getVector3());

#ifdef _DEBUG_VMAPS
                    {
                        G3D::Triangle myt(testT.vertex(0)+p6, testT.vertex(1)+p6,testT.vertex(2)+p6);
                        gTriArray.push_back(myt);
                    }
#endif
                    t = pRay.intersectionTime(testT);
                    if ((t < pMaxDist) || t < (pMaxDist + epsilon))
                        pMaxDist = t;
                }
            }
    };

}
#endif

