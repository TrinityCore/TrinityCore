/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

namespace Movement
{
template<typename length_type> void Spline<length_type>::evaluate_percent( float t, Vector3 & c ) const
{
    index_type Index;
    float u;
    computeIndex(t, Index, u);
    evaluate_percent(Index, u, c);
}

template<typename length_type> void Spline<length_type>::evaluate_derivative(float t, Vector3& hermite) const
{
    index_type Index;
    float u;
    computeIndex(t, Index, u);
    evaluate_derivative(Index, u, hermite);
}

template<typename length_type> SplineBase::index_type Spline<length_type>::computeIndexInBounds(length_type length_) const
{
// Temporary disabled: causes infinite loop with t = 1.f
/*
    index_type hi = index_hi;
    index_type lo = index_lo;

    index_type i = lo + (float)(hi - lo) * t;

    while ((lengths[i] > length) || (lengths[i + 1] <= length))
    {
        if (lengths[i] > length)
            hi = i - 1; // too big
        else if (lengths[i + 1] <= length)
            lo = i + 1; // too small

        i = (hi + lo) / 2;
    }*/

    index_type i = index_lo;
    index_type N = index_hi;
    while (i+1 < N && lengths[i+1] < length_)
        ++i;

    return i;
}

template<typename length_type> void Spline<length_type>::computeIndex(float t, index_type& index, float& u) const
{
    ASSERT(t >= 0.f && t <= 1.f);
    length_type length_ = t * length();
    index = computeIndexInBounds(length_);
    ASSERT(index < index_hi);
    u = (length_ - length(index)) / (float)length(index, index+1);
}

template<typename length_type> SplineBase::index_type Spline<length_type>::computeIndexInBounds( float t ) const
{
    ASSERT(t >= 0.f && t <= 1.f);
    return computeIndexInBounds(t * length());
}

template<typename length_type> void Spline<length_type>::initLengths()
{
    index_type i = index_lo;
    length_type length = 0;
    lengths.resize(index_hi+1);
    while (i < index_hi)
    {
        length += SegLength(i);
        lengths[++i] = length;
    }
}

template<typename length_type> void Spline<length_type>::clear()
{
    SplineBase::clear();
    lengths.clear();
}

}
