/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef TRINITYSERVER_MOVESPLINEINIT_H
#define TRINITYSERVER_MOVESPLINEINIT_H

#include "MoveSplineInitArgs.h"
#include "PathGenerator.h"

class Unit;

namespace Movement
{
    enum AnimType
    {
        ToGround    = 0, // 460 = ToGround, index of AnimationData.dbc
        FlyToFly    = 1, // 461 = FlyToFly?
        ToFly       = 2, // 458 = ToFly
        FlyToGround = 3  // 463 = FlyToGround
    };

    // Transforms coordinates from global to transport offsets
    class TransportPathTransform
    {
    public:
        TransportPathTransform(Unit* owner, bool transformForTransport)
            : _owner(owner), _transformForTransport(transformForTransport) { }
        Vector3 operator()(Vector3 input);

    private:
        Unit* _owner;
        bool _transformForTransport;
    };

    /*  Initializes and launches spline movement
     */
    class MoveSplineInit
    {
    public:

        explicit MoveSplineInit(Unit* m);

        /*  Final pass of initialization that launches spline movement.
         */
        int32 Launch();

        /*  Final pass of initialization that stops movement.
         */
        void Stop();

        /* Adds movement by parabolic trajectory
         * @param amplitude  - the maximum height of parabola, value could be negative and positive
         * @param start_time - delay between movement starting time and beginning to move by parabolic trajectory
         * can't be combined with final animation
         */
        void SetParabolic(float amplitude, float start_time);
        /* Plays animation after movement done
         * can't be combined with parabolic movement
         */
        void SetAnimation(AnimType anim);

        /* Adds final facing animation
         * sets unit's facing to specified point/angle after all path done
         * you can have only one final facing: previous will be overriden
         */
        void SetFacing(float angle);
        void SetFacing(Vector3 const& point);
        void SetFacing(const Unit* target);

        /* Initializes movement by path
         * @param path - array of points, shouldn't be empty
         * @param pointId - Id of fisrt point of the path. Example: when third path point will be done it will notify that pointId + 3 done
         */
        void MovebyPath(const PointsArray& path, int32 pointId = 0);

        /* Initializes simple A to B motion, A is current unit's position, B is destination
         */
        void MoveTo(const Vector3& destination, bool generatePath = true, bool forceDestination = false);
        void MoveTo(float x, float y, float z, bool generatePath = true, bool forceDestination = false);

        /* Sets Id of fisrt point of the path. When N-th path point will be done ILisener will notify that pointId + N done
         * Needed for waypoint movement where path splitten into parts
         */
        void SetFirstPointId(int32 pointId) { args.path_Idx_offset = pointId; }

        /* Enables CatmullRom spline interpolation mode(makes path smooth)
         * if not enabled linear spline mode will be choosen. Disabled by default
         */
        void SetSmooth();

        /* Waypoints in packets will be sent without compression
         */
        void SetUncompressed();

        /* Enables flying animation. Disabled by default
         */
        void SetFly();

        /* Enables walk mode. Disabled by default
         */
        void SetWalk(bool enable);

        /* Makes movement cyclic. Disabled by default
         */
        void SetCyclic();

        /* Enables falling mode. Disabled by default
         */
        void SetFall();

        /* Enters transport. Disabled by default
         */
        void SetTransportEnter();

        /* Exits transport. Disabled by default
         */
        void SetTransportExit();

        /* Inverses unit model orientation. Disabled by default
         */
        void SetOrientationInversed();

        /* Fixes unit's model rotation. Disabled by default
         */
        void SetOrientationFixed(bool enable);

        /* Sets the velocity (in case you want to have custom movement velocity)
         * if no set, speed will be selected based on unit's speeds and current movement mode
         * Has no effect if falling mode enabled
         * velocity shouldn't be negative
         */
        void SetVelocity(float velocity);

        PointsArray& Path() { return args.path; }

        /* Disables transport coordinate transformations for cases where raw offsets are available
        */
        void DisableTransportPathTransformations();
    protected:

        MoveSplineInitArgs args;
        Unit*  unit;
    };

    inline void MoveSplineInit::SetFly() { args.flags.EnableFlying(); }
    inline void MoveSplineInit::SetWalk(bool enable) { args.flags.walkmode = enable; }
    inline void MoveSplineInit::SetSmooth() { args.flags.EnableCatmullRom(); }
    inline void MoveSplineInit::SetUncompressed() { args.flags.uncompressedPath = true; }
    inline void MoveSplineInit::SetCyclic() { args.flags.cyclic = true; }
    inline void MoveSplineInit::SetVelocity(float vel) { args.velocity = vel; args.HasVelocity = true; }
    inline void MoveSplineInit::SetOrientationInversed() { args.flags.orientationInversed = true;}
    inline void MoveSplineInit::SetTransportEnter() { args.flags.EnableTransportEnter(); }
    inline void MoveSplineInit::SetTransportExit() { args.flags.EnableTransportExit(); }
    inline void MoveSplineInit::SetOrientationFixed(bool enable) { args.flags.orientationFixed = enable; }

    inline void MoveSplineInit::MovebyPath(const PointsArray& controls, int32 path_offset)
    {
        args.path_Idx_offset = path_offset;
        args.path.resize(controls.size());
        std::transform(controls.begin(), controls.end(), args.path.begin(), TransportPathTransform(unit, args.TransformForTransport));
    }

    inline void MoveSplineInit::MoveTo(float x, float y, float z, bool generatePath, bool forceDestination)
    {
        MoveTo(G3D::Vector3(x, y, z), generatePath, forceDestination);
    }

    inline void MoveSplineInit::SetParabolic(float amplitude, float time_shift)
    {
        args.time_perc = time_shift;
        args.parabolic_amplitude = amplitude;
        args.flags.EnableParabolic();
    }

    inline void MoveSplineInit::SetAnimation(AnimType anim)
    {
        args.time_perc = 0.f;
        args.flags.EnableAnimation((uint8)anim);
    }

    inline void MoveSplineInit::SetFacing(Vector3 const& spot)
    {
        TransportPathTransform transform(unit, args.TransformForTransport);
        Vector3 finalSpot = transform(spot);
        args.facing.f.x = finalSpot.x;
        args.facing.f.y = finalSpot.y;
        args.facing.f.z = finalSpot.z;
        args.flags.EnableFacingPoint();
    }

    inline void MoveSplineInit::DisableTransportPathTransformations() { args.TransformForTransport = false; }
}
#endif // TRINITYSERVER_MOVESPLINEINIT_H
