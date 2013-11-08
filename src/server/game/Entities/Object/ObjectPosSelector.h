/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef _OBJECT_POS_SELECTOR_H
#define _OBJECT_POS_SELECTOR_H

#include<Common.h>

#include<map>

enum UsedPosType { USED_POS_PLUS, USED_POS_MINUS };

inline UsedPosType operator ~(UsedPosType uptype)
{
    return uptype==USED_POS_PLUS ? USED_POS_MINUS : USED_POS_PLUS;
}

struct ObjectPosSelector
{
    struct UsedPos
    {
        UsedPos(float sign_, float size_, float dist_) : sign(sign_), size(size_), dist(dist_) { }

        float sign;

        float size;                                         // size of point
        float dist;                                         // dist to central point (including central point size)
    };

    typedef std::multimap<float, UsedPos> UsedPosList;       // abs(angle)->Node

    ObjectPosSelector(float x, float y, float size, float dist);

    void AddUsedPos(float size, float angle, float dist);
    void InitializeAngle();

    bool FirstAngle(float& angle);
    bool NextAngle(float& angle);
    bool NextUsedAngle(float& angle);

    bool NextPosibleAngle(float& angle);

    bool CheckAngle(UsedPosList::value_type const& nextUsedPos, float sign, float angle ) const
    {
        float angle_step2  = GetAngle(nextUsedPos.second);

        float next_angle = nextUsedPos.first;
        if (nextUsedPos.second.sign * sign < 0)              // last node from diff. list (-pi+alpha)
            next_angle = 2*M_PI-next_angle;                 // move to positive

        return fabs(angle)+angle_step2 <= next_angle;
    }

    bool CheckOriginal() const
    {
        return (m_UsedPosLists[USED_POS_PLUS].empty() || CheckAngle(*m_UsedPosLists[USED_POS_PLUS].begin(), 1.0f, 0)) &&
            (m_UsedPosLists[USED_POS_MINUS].empty() || CheckAngle(*m_UsedPosLists[USED_POS_MINUS].begin(), -1.0f, 0));
    }

    bool IsNonBalanced() const { return m_UsedPosLists[USED_POS_PLUS].empty() != m_UsedPosLists[USED_POS_MINUS].empty(); }

    bool NextAngleFor(UsedPosList::value_type const& usedPos, float sign, UsedPosType uptype, float &angle)
    {
        float angle_step  = GetAngle(usedPos.second);

        // next possible angle
        angle  = usedPos.first * usedPos.second.sign + angle_step * sign;

        UsedPosList::value_type const* nextNode = nextUsedPos(uptype);
        if (nextNode)
        {
            // if next node permit use selected angle, then do it
            if (!CheckAngle(*nextNode, sign, angle))
            {
                m_smallStepOk[uptype] = false;
                return false;
            }
        }

        // possible more points
        m_smallStepOk[uptype] = true;
        m_smallStepAngle[uptype] = angle;
        m_smallStepNextUsedPos[uptype] = nextNode;

        return true;
    }

    bool NextSmallStepAngle(float sign, UsedPosType uptype, float &angle)
    {
        // next possible angle
        angle  = m_smallStepAngle[uptype] + m_anglestep * sign;

        if (fabs(angle) > M_PI)
        {
            m_smallStepOk[uptype] = false;
            return false;
        }

        if (m_smallStepNextUsedPos[uptype])
        {
            if (fabs(angle) >= m_smallStepNextUsedPos[uptype]->first)
            {
                m_smallStepOk[uptype] = false;
                return false;
            }

            // if next node permit use selected angle, then do it
            if (!CheckAngle(*m_smallStepNextUsedPos[uptype], sign, angle))
            {
                m_smallStepOk[uptype] = false;
                return false;
            }
        }

        // possible more points
        m_smallStepAngle[uptype] = angle;
        return true;
    }

    // next used post for m_nextUsedPos[uptype]
    UsedPosList::value_type const* nextUsedPos(UsedPosType uptype);

    // angle from used pos to next possible free pos
    float GetAngle(UsedPos const& usedPos) const { return acos(m_dist/(usedPos.dist+usedPos.size+m_size)); }

    float m_center_x;
    float m_center_y;
    float m_size;                                           // size of object in center
    float m_dist;                                           // distance for searching pos (including central object size)
    float m_anglestep;

    UsedPosList m_UsedPosLists[2];
    UsedPosList::const_iterator m_nextUsedPos[2];

    // field for small step from first after next used pos until next pos
    float m_smallStepAngle[2];
    bool  m_smallStepOk[2];
    UsedPosList::value_type const* m_smallStepNextUsedPos[2];
};
#endif
