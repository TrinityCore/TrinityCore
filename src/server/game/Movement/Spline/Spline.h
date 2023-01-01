/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#ifndef TRINITYSERVER_SPLINE_H
#define TRINITYSERVER_SPLINE_H

#include "MovementTypedefs.h"
#include "Errors.h"
#include <G3D/Vector3.h>
#include <limits>
#include <vector>

namespace Movement {

class SplineBase
{
public:
    typedef int index_type;
    typedef std::vector<Vector3> ControlArray;

    enum EvaluationMode
    {
        ModeLinear,
        ModeCatmullrom,
        ModeBezier3_Unused,
        UninitializedMode,
        ModesEnd
    };

protected:
    ControlArray points;

    index_type index_lo;
    index_type index_hi;

    uint8 m_mode;
    bool cyclic;
    float initialOrientation;

    // could be modified, affects segment length evaluation precision
    // lesser value saves more performance in cost of lover precision
    // minimal value is 1
    // client's value is 20, blizzs use 2-3 steps to compute length
    index_type stepsPerSegment = 3;

protected:
    void EvaluateLinear(index_type, float, Vector3&) const;
    void EvaluateCatmullRom(index_type, float, Vector3&) const;
    void EvaluateBezier3(index_type, float, Vector3&) const;
    typedef void (SplineBase::*EvaluationMethtod)(index_type, float, Vector3&) const;
    static EvaluationMethtod evaluators[ModesEnd];

    void EvaluateDerivativeLinear(index_type, float, Vector3&) const;
    void EvaluateDerivativeCatmullRom(index_type, float, Vector3&) const;
    void EvaluateDerivativeBezier3(index_type, float, Vector3&) const;
    static EvaluationMethtod derivative_evaluators[ModesEnd];

    float SegLengthLinear(index_type) const;
    float SegLengthCatmullRom(index_type) const;
    float SegLengthBezier3(index_type) const;
    typedef float (SplineBase::*SegLenghtMethtod)(index_type) const;
    static SegLenghtMethtod seglengths[ModesEnd];

    void InitLinear(Vector3 const*, index_type, index_type);
    void InitCatmullRom(Vector3 const*, index_type, index_type);
    void InitBezier3(Vector3 const*, index_type, index_type);
    typedef void (SplineBase::*InitMethtod)(Vector3 const*, index_type, index_type);
    static InitMethtod initializers[ModesEnd];

    void UninitializedSplineEvaluationMethod(index_type, float, Vector3&) const { ABORT(); }
    float UninitializedSplineSegLenghtMethod(index_type) const { ABORT(); return 0.0f; }
    void UninitializedSplineInitMethod(Vector3 const*, index_type, index_type) { ABORT(); }

public:

    explicit SplineBase();
    SplineBase(SplineBase const& right) = delete;
    SplineBase(SplineBase&& right) = delete;
    SplineBase& operator=(SplineBase const& right) = delete;
    SplineBase& operator=(SplineBase&& right) = delete;
    virtual ~SplineBase();

    /** Caclulates the position for given segment Idx, and percent of segment length t
        @param t - percent of segment length, assumes that t in range [0, 1]
        @param Idx - spline segment index, should be in range [first, last)
     */
    void evaluate_percent(index_type Idx, float u, Vector3& c) const {(this->*evaluators[m_mode])(Idx, u, c);}

    /** Caclulates derivation in index Idx, and percent of segment length t
        @param Idx - spline segment index, should be in range [first, last)
        @param t  - percent of spline segment length, assumes that t in range [0, 1]
     */
    void evaluate_derivative(index_type Idx, float u, Vector3& hermite) const {(this->*derivative_evaluators[m_mode])(Idx, u, hermite);}

    /**  Bounds for spline indexes. All indexes should be in range [first, last). */
    index_type first() const { return index_lo;}
    index_type last()  const { return index_hi;}

    bool empty() const { return index_lo == index_hi;}
    EvaluationMode mode() const { return (EvaluationMode)m_mode;}
    bool isCyclic() const { return cyclic;}

    ControlArray const& getPoints() const { return points; }
    index_type getPointCount() const { return index_type(points.size());}
    Vector3 const& getPoint(index_type i) const { return points[i]; }

    /** Initializes spline. Don't call other methods while spline not initialized. */
    void init_spline(const Vector3 * controls, index_type count, EvaluationMode m, float orientation = 0.0f);
    void init_cyclic_spline(const Vector3 * controls, index_type count, EvaluationMode m, index_type cyclic_point, float orientation = 0.0f);

    /** As i can see there are a lot of ways how spline can be initialized
        would be no harm to have some custom initializers. */
    template<class Init>
    void init_spline_custom(Init& initializer)
    {
        initializer(m_mode, cyclic, points, index_lo, index_hi);
    }

    virtual void clear();

    /** Calculates distance between [i; i+1] points, assumes that index i is in bounds. */
    float SegLength(index_type i) const { return (this->*seglengths[m_mode])(i);}

    void set_steps_per_segment(index_type newStepsPerSegment) { stepsPerSegment = newStepsPerSegment; }

    std::string ToString() const;
};

template<typename length_type>
class Spline : public SplineBase
{
public:
    typedef length_type LengthType;
    typedef std::vector<length_type> LengthArray;
protected:

    LengthArray lengths;

    index_type computeIndexInBounds(length_type length) const;
public:

    explicit Spline(){ }

    /** Calculates the position for given t
        @param t - percent of spline's length, assumes that t in range [0, 1]. */
    void evaluate_percent(float t, Vector3 & c) const;

    using SplineBase::evaluate_percent;

    /** Calculates derivation for given t
        @param t - percent of spline's length, assumes that t in range [0, 1]. */
    void evaluate_derivative(float t, Vector3& hermite) const;

    using SplineBase::evaluate_derivative;

    // Assumes that t in range [0, 1]
    index_type computeIndexInBounds(float t) const;
    void computeIndex(float t, index_type& out_idx, float& out_u) const;

    /**  Initializes lengths with SplineBase::SegLength method. */
    void initLengths();

    /** Initializes lengths in some custom way
        Note that value returned by cacher must be greater or equal to previous value. */
    template<class T>
    void initLengths(T& cacher)
    {
        index_type i = index_lo;
        lengths.resize(index_hi+1);
        length_type prev_length = 0, new_length = 0;
        while (i < index_hi)
        {
            new_length = cacher(*this, i);
            // length overflowed, assign to max positive value
            if (new_length < 0)
                new_length = std::numeric_limits<length_type>::max();
            lengths[++i] = new_length;

            ASSERT(prev_length <= new_length);
            prev_length = new_length;
        }
    }

    /** Returns length of the whole spline. */
    length_type length() const
    {
        if (lengths.empty())
            return 0;
        return lengths[index_hi];
    }
    /** Returns length between given nodes. */
    length_type length(index_type first, index_type last) const { return lengths[last]-lengths[first];}
    length_type length(index_type Idx) const { return lengths[Idx];}

    void set_length(index_type i, length_type length) { lengths[i] = length;}
    void clear() override;
};

}

#include "SplineImpl.h"

#endif // TRINITYSERVER_SPLINE_H
