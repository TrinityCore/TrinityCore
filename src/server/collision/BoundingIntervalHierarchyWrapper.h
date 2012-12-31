/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2010 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _BIH_WRAP
#define _BIH_WRAP

#include "G3D/Table.h"
#include "G3D/Array.h"
#include "G3D/Set.h"
#include "BoundingIntervalHierarchy.h"


template<class T, class BoundsFunc = BoundsTrait<T> >
class BIHWrap
{
    template<class RayCallback>
    struct MDLCallback
    {
        const T* const* objects;
        RayCallback& _callback;

        MDLCallback(RayCallback& callback, const T* const* objects_array ) : objects(objects_array), _callback(callback) {}

        bool operator() (const Ray& ray, uint32 Idx, float& MaxDist, bool /*stopAtFirst*/)
        {
            if (const T* obj = objects[Idx])
                return _callback(ray, *obj, MaxDist/*, stopAtFirst*/);
            return false;
        }

        void operator() (const Vector3& p, uint32 Idx)
        {
            if (const T* obj = objects[Idx])
                _callback(p, *obj);
        }
    };

    typedef G3D::Array<const T*> ObjArray;

    BIH m_tree;
    ObjArray m_objects;
    G3D::Table<const T*, uint32> m_obj2Idx;
    G3D::Set<const T*> m_objects_to_push;
    int unbalanced_times;

public:
    BIHWrap() : unbalanced_times(0) {}

    void insert(const T& obj)
    {
        ++unbalanced_times;
        m_objects_to_push.insert(&obj);
    }

    void remove(const T& obj)
    {
        ++unbalanced_times;
        uint32 Idx = 0;
        const T * temp;
        if (m_obj2Idx.getRemove(&obj, temp, Idx))
            m_objects[Idx] = NULL;
        else
            m_objects_to_push.remove(&obj);
    }

    void balance()
    {
        if (unbalanced_times == 0)
            return;

        unbalanced_times = 0;
        m_objects.fastClear();
        m_obj2Idx.getKeys(m_objects);
        m_objects_to_push.getMembers(m_objects);

        m_tree.build(m_objects, BoundsFunc::getBounds2);
    }

    template<typename RayCallback>
    void intersectRay(const Ray& ray, RayCallback& intersectCallback, float& maxDist) const
    {
        MDLCallback<RayCallback> temp_cb(intersectCallback, m_objects.getCArray());
        m_tree.intersectRay(ray, temp_cb, maxDist, true);
    }

    template<typename IsectCallback>
    void intersectPoint(const Vector3& point, IsectCallback& intersectCallback) const
    {
        MDLCallback<IsectCallback> callback(intersectCallback, m_objects.getCArray());
        m_tree.intersectPoint(point, callback);
    }
};

#endif // _BIH_WRAP
