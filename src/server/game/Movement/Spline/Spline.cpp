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

#include "Spline.h"
#include <sstream>
#include <G3D/Matrix4.h>

namespace Movement{

SplineBase::EvaluationMethtod SplineBase::evaluators[SplineBase::ModesEnd] =
{
    &SplineBase::EvaluateLinear,
    &SplineBase::EvaluateCatmullRom,
    &SplineBase::EvaluateBezier3,
    &SplineBase::UninitializedSplineEvaluationMethod,
};

SplineBase::EvaluationMethtod SplineBase::derivative_evaluators[SplineBase::ModesEnd] =
{
    &SplineBase::EvaluateDerivativeLinear,
    &SplineBase::EvaluateDerivativeCatmullRom,
    &SplineBase::EvaluateDerivativeBezier3,
    &SplineBase::UninitializedSplineEvaluationMethod,
};

SplineBase::SegLenghtMethtod SplineBase::seglengths[SplineBase::ModesEnd] =
{
    &SplineBase::SegLengthLinear,
    &SplineBase::SegLengthCatmullRom,
    &SplineBase::SegLengthBezier3,
    &SplineBase::UninitializedSplineSegLenghtMethod,
};

SplineBase::InitMethtod SplineBase::initializers[SplineBase::ModesEnd] =
{
    //&SplineBase::InitLinear,
    &SplineBase::InitCatmullRom,    // we should use catmullrom initializer even for linear mode! (client's internal structure limitation)
    &SplineBase::InitCatmullRom,
    &SplineBase::InitBezier3,
    &SplineBase::UninitializedSplineInitMethod,
};

///////////

using G3D::Matrix4;
static const Matrix4 s_catmullRomCoeffs(
    -0.5f, 1.5f, -1.5f, 0.5f,
    1.f, -2.5f, 2.f, -0.5f,
    -0.5f, 0.f,  0.5f, 0.f,
    0.f,  1.f,  0.f,  0.f);

static const Matrix4 s_Bezier3Coeffs(
    -1.f,  3.f, -3.f, 1.f,
    3.f, -6.f,  3.f, 0.f,
    -3.f,  3.f,  0.f, 0.f,
    1.f,  0.f,  0.f, 0.f);

/*  classic view:
inline void C_Evaluate(const Vector3 *vertice, float t, const float (&matrix)[4][4], Vector3 &position)
{
    Vector3 tvec(t*t*t, t*t, t);
    int i = 0;
    double c;
    double x = 0, y = 0, z = 0;
    while ( i < 4 )
    {
        c = matrix[0][i]*tvec.x + matrix[1][i]*tvec.y + matrix[2][i]*tvec.z + matrix[3][i];

        x += c * vertice->x;
        y += c * vertice->y;
        z += c * vertice->z;

        ++i;
        ++vertice;
    }

    position.x = x;
    position.y = y;
    position.z = z;
}*/

inline void C_Evaluate(Vector3 const* vertice, float t, Matrix4 const& matr, Vector3 &result)
{
    Vector4 tvec(t*t*t, t*t, t, 1.f);
    Vector4 weights(tvec * matr);

    result = vertice[0] * weights[0] + vertice[1] * weights[1]
           + vertice[2] * weights[2] + vertice[3] * weights[3];
}

inline void C_Evaluate_Derivative(Vector3 const* vertice, float t, Matrix4 const& matr, Vector3 &result)
{
    Vector4 tvec(3.f*t*t, 2.f*t, 1.f, 0.f);
    Vector4 weights(tvec * matr);

    result = vertice[0] * weights[0] + vertice[1] * weights[1]
           + vertice[2] * weights[2] + vertice[3] * weights[3];
}

void SplineBase::EvaluateLinear(index_type index, float u, Vector3& result) const
{
    ASSERT(index >= index_lo && index < index_hi);
    result = points[index] + (points[index+1] - points[index]) * u;
}

void SplineBase::EvaluateCatmullRom( index_type index, float t, Vector3& result) const
{
    ASSERT(index >= index_lo && index < index_hi);
    C_Evaluate(&points[index - 1], t, s_catmullRomCoeffs, result);
}

void SplineBase::EvaluateBezier3(index_type index, float t, Vector3& result) const
{
    index *= 3u;
    ASSERT(index >= index_lo && index < index_hi);
    C_Evaluate(&points[index], t, s_Bezier3Coeffs, result);
}

void SplineBase::EvaluateDerivativeLinear(index_type index, float, Vector3& result) const
{
    ASSERT(index >= index_lo && index < index_hi);
    result = points[index+1] - points[index];
}

void SplineBase::EvaluateDerivativeCatmullRom(index_type index, float t, Vector3& result) const
{
    ASSERT(index >= index_lo && index < index_hi);
    C_Evaluate_Derivative(&points[index - 1], t, s_catmullRomCoeffs, result);
}

void SplineBase::EvaluateDerivativeBezier3(index_type index, float t, Vector3& result) const
{
    index *= 3u;
    ASSERT(index >= index_lo && index < index_hi);
    C_Evaluate_Derivative(&points[index], t, s_Bezier3Coeffs, result);
}

float SplineBase::SegLengthLinear(index_type index) const
{
    ASSERT(index >= index_lo && index < index_hi);
    return (points[index] - points[index+1]).length();
}

float SplineBase::SegLengthCatmullRom(index_type index) const
{
    ASSERT(index >= index_lo && index < index_hi);

    Vector3 curPos, nextPos;
    const Vector3 * p = &points[index - 1];
    curPos = nextPos = p[1];

    index_type i = 1;
    float length = 0;
    while (i <= STEPS_PER_SEGMENT)
    {
        C_Evaluate(p, float(i) / float(STEPS_PER_SEGMENT), s_catmullRomCoeffs, nextPos);
        length += (nextPos - curPos).length();
        curPos = nextPos;
        ++i;
    }
    return length;
}

float SplineBase::SegLengthBezier3(index_type index) const
{
    index *= 3u;
    ASSERT(index >= index_lo && index < index_hi);

    Vector3 curPos, nextPos;
    const Vector3 * p = &points[index];

    C_Evaluate(p, 0.f, s_Bezier3Coeffs, nextPos);
    curPos = nextPos;

    index_type i = 1;
    float length = 0;
    while (i <= STEPS_PER_SEGMENT)
    {
        C_Evaluate(p, float(i) / float(STEPS_PER_SEGMENT), s_Bezier3Coeffs, nextPos);
        length += (nextPos - curPos).length();
        curPos = nextPos;
        ++i;
    }
    return length;
}

void SplineBase::init_spline(const Vector3 * controls, index_type count, EvaluationMode m, float orientation)
{
    m_mode = m;
    cyclic = false;
    initialOrientation = orientation;

    (this->*initializers[m_mode])(controls, count, 0);
}

void SplineBase::init_cyclic_spline(const Vector3 * controls, index_type count, EvaluationMode m, index_type cyclic_point, float orientation)
{
    m_mode = m;
    cyclic = true;
    initialOrientation = orientation;

    (this->*initializers[m_mode])(controls, count, cyclic_point);
}

void SplineBase::InitLinear(Vector3 const* controls, index_type count, index_type cyclic_point)
{
    ASSERT(count >= 2);
    const int real_size = count + 1;

    points.resize(real_size);

    memcpy(&points[0], controls, sizeof(Vector3) * count);

    // first and last two indexes are space for special 'virtual points'
    // these points are required for proper C_Evaluate and C_Evaluate_Derivative methtod work
    if (cyclic)
        points[count] = controls[cyclic_point];
    else
        points[count] = controls[count-1];

    index_lo = 0;
    index_hi = cyclic ? count : (count - 1);
}

void SplineBase::InitCatmullRom(Vector3 const* controls, index_type count, index_type cyclic_point)
{
    const int real_size = count + (cyclic ? (1+2) : (1+1));

    points.resize(real_size);

    int lo_index = 1;
    int high_index = lo_index + count - 1;

    memcpy(&points[lo_index], controls, sizeof(Vector3) * count);

    // first and last two indexes are space for special 'virtual points'
    // these points are required for proper C_Evaluate and C_Evaluate_Derivative methtod work
    if (cyclic)
    {
        if (cyclic_point == 0)
            points[0] = controls[count-1];
        else
            points[0] = controls[0] - G3D::Vector3{ std::cos(initialOrientation), std::sin(initialOrientation), 0.0f };

        points[high_index+1] = controls[cyclic_point];
        points[high_index+2] = controls[cyclic_point+1];
    }
    else
    {
        points[0] = controls[0] - G3D::Vector3{ std::cos(initialOrientation), std::sin(initialOrientation), 0.0f };
        points[high_index+1] = controls[count-1];
    }

    index_lo = lo_index;
    index_hi = high_index + (cyclic ? 1 : 0);
}

void SplineBase::InitBezier3(Vector3 const* controls, index_type count, index_type /*cyclic_point*/)
{
    index_type c = count / 3u * 3u;
    index_type t = c / 3u;

    points.resize(c);
    memcpy(&points[0], controls, sizeof(Vector3) * c);

    index_lo = 0;
    index_hi = t-1;
    //mov_assert(points.size() % 3 == 0);
}

void SplineBase::clear()
{
    index_lo = 0;
    index_hi = 0;
    points.clear();
}

std::string SplineBase::ToString() const
{
    std::stringstream str;
    const char * mode_str[ModesEnd] = {"Linear", "CatmullRom", "Bezier3", "Uninitialized"};

    index_type count = this->points.size();
    str << "mode: " << mode_str[mode()] << std::endl;
    str << "points count: " << count << std::endl;
    for (index_type i = 0; i < count; ++i)
        str << "point " << i << " : " << points[i].toString() << std::endl;

    return str.str();
}

}
