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

#include "MoveSpline.h"
#include "Log.h"
#include "Creature.h"
#include "DB2Stores.h"

#include <sstream>

namespace Movement{

Location MoveSpline::computePosition(int32 time_point, int32 point_index) const
{
    ASSERT(Initialized());

    float u = 1.0f;
    int32 seg_time = spline.length(point_index, point_index + 1);
    if (seg_time > 0)
        u = (time_point - spline.length(point_index)) / (float)seg_time;

    Location c;
    c.orientation = initialOrientation;
    spline.evaluate_percent(point_index, u, c);

    if (splineflags.Animation)
        ;// MoveSplineFlag::Animation disables falling or parabolic movement
    else if (splineflags.Parabolic)
        computeParabolicElevation(time_point, c.z);
    else if (splineflags.Falling)
        computeFallElevation(time_point, c.z);

    if (splineflags.Done && facing.type != MONSTER_MOVE_NORMAL)
    {
        if (facing.type == MONSTER_MOVE_FACING_ANGLE)
            c.orientation = facing.angle;
        else if (facing.type == MONSTER_MOVE_FACING_SPOT)
            c.orientation = std::atan2(facing.f.y - c.y, facing.f.x - c.x);
        //nothing to do for MoveSplineFlag::Final_Target flag
    }
    else
    {
        if (!splineflags.HasFlag(MoveSplineFlagEnum::OrientationFixed | MoveSplineFlagEnum::Falling | MoveSplineFlagEnum::Unknown_0x8))
        {
            Vector3 hermite;
            spline.evaluate_derivative(point_Idx, u, hermite);
            if (hermite.x != 0.f || hermite.y != 0.f)
                c.orientation = std::atan2(hermite.y, hermite.x);
        }

        if (splineflags.Backward)
            c.orientation = c.orientation - float(M_PI);
    }
    return c;
}

Location MoveSpline::ComputePosition() const
{
    return computePosition(time_passed, point_Idx);
}

Location MoveSpline::ComputePosition(int32 time_offset) const
{
    int32 time_point = time_passed + time_offset;
    if (time_point >= Duration())
        return computePosition(Duration(), spline.last() - 1);
    if (time_point <= 0)
        return computePosition(0, spline.first());

    // find point_index where spline.length(point_index) < time_point < spline.length(point_index + 1)
    int32 point_index = point_Idx;
    while (time_point >= spline.length(point_index + 1))
        ++point_index;

    while (time_point < spline.length(point_index))
        --point_index;

    return computePosition(time_point, point_index);
}

void MoveSpline::computeParabolicElevation(int32 time_point, float& el) const
{
    if (time_point > effect_start_time)
    {
        float t_passedf = MSToSec(time_point - effect_start_time);
        float t_durationf = MSToSec(Duration() - effect_start_time); //client use not modified duration here
        if (spell_effect_extra && spell_effect_extra->ParabolicCurveId)
            t_passedf *= sDB2Manager.GetCurveValueAt(spell_effect_extra->ParabolicCurveId, float(time_point) / Duration());

        // -a*x*x + bx + c:
        //(dur * v3->z_acceleration * dt)/2 - (v3->z_acceleration * dt * dt)/2 + Z;
        el += (t_durationf - t_passedf) * 0.5f * vertical_acceleration * t_passedf;
    }
}

void MoveSpline::computeFallElevation(int32 time_point, float& el) const
{
    float z_now = spline.getPoint(spline.first()).z - Movement::computeFallElevation(MSToSec(time_point), false);
    float final_z = FinalDestination().z;
    el = std::max(z_now, final_z);
}

inline uint32 computeDuration(float length, float velocity)
{
    return SecToMS(length / velocity);
}

struct FallInitializer
{
    FallInitializer(float _start_elevation) : start_elevation(_start_elevation) { }
    float start_elevation;
    inline int32 operator()(Spline<int32>& s, int32 i)
    {
        return Movement::computeFallTime(start_elevation - s.getPoint(i+1).z, false) * 1000.f;
    }
};

enum{
    minimal_duration = 1
};

struct CommonInitializer
{
    CommonInitializer(float _velocity) : velocityInv(1000.f/_velocity), time(minimal_duration) { }
    float velocityInv;
    int32 time;
    inline int32 operator()(Spline<int32>& s, int32 i)
    {
        time += (s.SegLength(i) * velocityInv);
        return time;
    }
};

void MoveSpline::init_spline(MoveSplineInitArgs const& args)
{
    static SplineBase::EvaluationMode const modes[2] = { SplineBase::ModeLinear, SplineBase::ModeCatmullrom };
    if (args.flags.Cyclic)
    {
        uint32 cyclic_point = 0;
        if (splineflags.Enter_Cycle)
            cyclic_point = 1;   // shouldn't be modified, came from client
        spline.init_cyclic_spline(&args.path[0], args.path.size(), modes[args.flags.isSmooth()], cyclic_point, args.initialOrientation);
    }
    else
        spline.init_spline(&args.path[0], args.path.size(), modes[args.flags.isSmooth()], args.initialOrientation);

    // init spline timestamps
    if (splineflags.Falling)
    {
        FallInitializer init(spline.getPoint(spline.first()).z);
        spline.initLengths(init);
    }
    else
    {
        CommonInitializer init(args.velocity);
        spline.initLengths(init);
    }

    /// @todo what to do in such cases? problem is in input data (all points are at same coords)
    if (spline.length() < minimal_duration)
    {
        TC_LOG_ERROR("misc", "MoveSpline::init_spline: zero length spline, wrong input data?");
        spline.set_length(spline.last(), spline.isCyclic() ? 1000 : 1);
    }
    point_Idx = spline.first();
}

void MoveSpline::Initialize(MoveSplineInitArgs const& args)
{
    splineflags = args.flags;
    facing = args.facing;
    m_Id = args.splineId;
    point_Idx_offset = args.path_Idx_offset;
    initialOrientation = args.initialOrientation;

    time_passed = 0;
    vertical_acceleration = 0.f;
    effect_start_time = 0;
    spell_effect_extra = args.spellEffectExtra;
    anim_tier = args.animTier;
    splineIsFacingOnly = args.path.size() == 2 && args.facing.type != MONSTER_MOVE_NORMAL && ((args.path[1] - args.path[0]).length() < 0.1f);

    velocity = args.velocity;

    // Check if its a stop spline
    if (args.flags.Done)
    {
        spline.clear();
        return;
    }

    init_spline(args);

    // init parabolic / animation
    // spline initialized, duration known and i able to compute parabolic acceleration
    if (args.flags.HasFlag(MoveSplineFlagEnum::Parabolic | MoveSplineFlagEnum::Animation | MoveSplineFlagEnum::FadeObject))
    {
        int32 spline_duration = Duration();
        effect_start_time = spline_duration * args.effect_start_time_percent + args.effect_start_time.count();
        if (effect_start_time > spline_duration)
            effect_start_time = spline_duration;

        if (args.flags.Parabolic && effect_start_time < spline_duration)
        {
            if (args.parabolic_amplitude != 0.0f)
            {
                float f_duration = MSToSec(spline_duration - effect_start_time);
                vertical_acceleration = args.parabolic_amplitude * 8.f / (f_duration * f_duration);
            }
            else if (args.vertical_acceleration != 0.0f)
            {
                vertical_acceleration = args.vertical_acceleration;
            }
        }
    }
}

MoveSpline::MoveSpline() : m_Id(0), time_passed(0),
    vertical_acceleration(0.f), initialOrientation(0.f), effect_start_time(0), point_Idx(0), point_Idx_offset(0), velocity(0.f),
    onTransport(false), splineIsFacingOnly(false)
{
    splineflags.Done = true;
}

/// ============================================================================================

bool MoveSplineInitArgs::Validate(Unit const* unit)
{
#define CHECK(exp, verbose) \
    do if (!(exp))\
    {\
        if (unit)\
            TC_LOG_ERROR("misc.movesplineinitargs", "MoveSplineInitArgs::Validate: expression '{}' failed for {}", #exp, verbose);\
        else\
            TC_LOG_ERROR("misc.movesplineinitargs", "MoveSplineInitArgs::Validate: expression '{}' failed for cyclic spline continuation", #exp); \
        return false;\
    } while (0)
    CHECK(path.size() > 1, unit->GetDebugInfo());
    CHECK(velocity >= 0.01f, unit->GetDebugInfo());
    CHECK(effect_start_time_percent >= 0.f && effect_start_time_percent <= 1.f, unit->GetDebugInfo());
    CHECK(_checkPathLengths(), unit->GetGUID());
    if (spellEffectExtra)
    {
        CHECK(!spellEffectExtra->ProgressCurveId || sCurveStore.LookupEntry(spellEffectExtra->ProgressCurveId), unit->GetDebugInfo());
        CHECK(!spellEffectExtra->ParabolicCurveId || sCurveStore.LookupEntry(spellEffectExtra->ParabolicCurveId), unit->GetDebugInfo());
    }
    return true;
#undef CHECK
}

// check path lengths - why are we even starting such short movement?
bool MoveSplineInitArgs::_checkPathLengths()
{
    constexpr float MIN_XY_OFFSET = -(1 << 11) / 4.0f;
    constexpr float MIN_Z_OFFSET = -(1 << 10) / 4.0f;

    // positive values have 1 less bit limit (if the highest bit was set, value would be sign extended into negative when decompressing)
    constexpr float MAX_XY_OFFSET = (1 << 10) / 4.0f;
    constexpr float MAX_Z_OFFSET = (1 << 9) / 4.0f;

    auto isValidPackedXYOffset = [](float coord) -> bool { return coord > MIN_XY_OFFSET && coord < MAX_XY_OFFSET; };
    auto isValidPackedZOffset = [](float coord) -> bool { return coord > MIN_Z_OFFSET && coord < MAX_Z_OFFSET; };

    if (path.size() > 2)
    {
        if ((path[2] - path[1]).length() < 0.1f)
            return false;

        Vector3 middle = (path.front() + path.back()) / 2;
        for (uint32 i = 1; i < path.size() - 1; ++i)
        {
            if ((path[i + 1] - path[i]).length() < 0.1f)
                return false;

            // when compression is enabled, each point coord is packed into 11 bits (10 for Z)
            if (!flags.UncompressedPath)
                if (!isValidPackedXYOffset(middle.x - path[i].x)
                    || !isValidPackedXYOffset(middle.y - path[i].y)
                    || !isValidPackedZOffset(middle.z - path[i].z))
                    flags.UncompressedPath = true;
        }
    }
    return true;
}

MoveSplineInitArgs::MoveSplineInitArgs(size_t path_capacity /*= 16*/) : path_Idx_offset(0), velocity(0.f),
parabolic_amplitude(0.f), vertical_acceleration(0.0f), effect_start_time_percent(0.f), effect_start_time(0ms),
splineId(0), initialOrientation(0.f),
walk(false), HasVelocity(false), TransformForTransport(true)
{
    path.reserve(path_capacity);
}

MoveSplineInitArgs::MoveSplineInitArgs(MoveSplineInitArgs&& args) noexcept = default;

MoveSplineInitArgs::~MoveSplineInitArgs() = default;

/// ============================================================================================

MoveSpline::UpdateResult MoveSpline::_updateState(int32& ms_time_diff)
{
    if (Finalized())
    {
        ms_time_diff = 0;
        return Result_Arrived;
    }

    UpdateResult result = Result_None;

    int32 minimal_diff = std::min(ms_time_diff, segment_time_elapsed());
    ASSERT(minimal_diff >= 0);
    time_passed += minimal_diff;
    ms_time_diff -= minimal_diff;

    if (time_passed >= next_timestamp())
    {
        ++point_Idx;
        if (point_Idx < spline.last())
        {
            result = Result_NextSegment;
        }
        else
        {
            if (spline.isCyclic())
            {
                point_Idx = spline.first();
                time_passed = time_passed % Duration();
                result = Result_NextCycle;

                // Remove first point from the path after one full cycle.
                // That point was the position of the unit prior to entering the cycle and it shouldn't be repeated with continuous cycles.
                if (splineflags.Enter_Cycle)
                {
                    splineflags.Enter_Cycle = false;

                    MoveSplineInitArgs args{ (size_t)spline.getPointCount() };
                    args.path.assign(spline.getPoints().begin() + spline.first() + 1, spline.getPoints().begin() + spline.last());
                    args.facing = facing;
                    args.flags = splineflags;
                    args.path_Idx_offset = point_Idx_offset;
                    // MoveSplineFlag::Parabolic | MoveSplineFlag::Animation not supported currently
                        //args.parabolic_amplitude = ?;
                        //args.time_perc = ?;
                    args.splineId = m_Id;
                    args.initialOrientation = initialOrientation;
                    args.velocity = 1.0f; // Calculated below
                    args.HasVelocity = true;
                    args.TransformForTransport = onTransport;
                    if (args.Validate(nullptr))
                    {
                        // New cycle should preserve previous cycle's duration for some weird reason, even though
                        // the path is really different now. Blizzard is weird. Or this was just a simple oversight.
                        // Since our splines precalculate length with velocity in mind, if we want to find the desired
                        // velocity, we have to make a fake spline, calculate its duration and then compare it to the
                        // desired duration, thus finding out how much the velocity has to be increased for them to match.
                        MoveSpline tempSpline;
                        tempSpline.Initialize(args);
                        args.velocity = (float)tempSpline.Duration() / Duration();

                        if (args.Validate(nullptr))
                            init_spline(args);
                    }
                }
            }
            else
            {
                _Finalize();
                ms_time_diff = 0;
                result = Result_Arrived;
            }
        }
    }

    return result;
}

std::string MoveSpline::ToString() const
{
    std::stringstream str;
    str << "MoveSpline" << std::endl;
    str << "spline Id: " << GetId() << std::endl;
    str << "flags: " << splineflags.ToString() << std::endl;
    if (facing.type == MONSTER_MOVE_FACING_ANGLE)
        str << "facing  angle: " << facing.angle << std::endl;
    else if (facing.type == MONSTER_MOVE_FACING_TARGET)
        str << "facing target: " << facing.target.ToString() << std::endl;
    else if (facing.type == MONSTER_MOVE_FACING_SPOT)
        str << "facing  point: " << facing.f.x << " " << facing.f.y << " " << facing.f.z << std::endl;
    str << "time passed: " << time_passed << std::endl;
    str << "total  time: " << Duration() << std::endl;
    str << "spline point Id: " << point_Idx << std::endl;
    str << "path  point  Id: " << currentPathIdx() << std::endl;
    str << spline.ToString();
    return str.str();
}

void MoveSpline::_Finalize()
{
    splineflags.Done = true;
    point_Idx = spline.last() - 1;
    time_passed = Duration();
}

int32 MoveSpline::currentPathIdx() const
{
    int32 point = point_Idx_offset + point_Idx - spline.first() + (int)Finalized();
    if (isCyclic())
        point = point % (spline.last()-spline.first());
    return point;
}
}
