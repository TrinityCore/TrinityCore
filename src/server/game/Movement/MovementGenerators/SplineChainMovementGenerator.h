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

#ifndef TRINITY_SPLINECHAINMOVEMENTGENERATOR_H
#define TRINITY_SPLINECHAINMOVEMENTGENERATOR_H

#include "SplineChain.h"
#include "MovementGenerator.h"

class TC_GAME_API SplineChainMovementGenerator : public MovementGenerator
{
    public:
        explicit SplineChainMovementGenerator(uint32 id, std::vector<SplineChainLink> const& chain, bool walk = false) : _id(id), _chain(chain), _chainSize(chain.size()), _walk(walk), finished(false), _nextIndex(0), _nextFirstWP(0), _msToNext(0) { }
        explicit SplineChainMovementGenerator(SplineChainResumeInfo const& info) : _id(info.PointID), _chain(*info.Chain), _chainSize(info.Chain->size()), _walk(info.IsWalkMode), finished(info.SplineIndex >= info.Chain->size()), _nextIndex(info.SplineIndex), _nextFirstWP(info.PointIndex), _msToNext(info.TimeToNext) { }
        void Initialize(Unit* me) override;
        void Finalize(Unit* me) override;
        void Reset(Unit* /*me*/) override { };
        bool Update(Unit* me, uint32 diff) override;
        MovementGeneratorType GetMovementGeneratorType() const override { return SPLINE_CHAIN_MOTION_TYPE; }
        // Builds info that can later be used to resume this spline chain movement at the current position
        static void GetResumeInfo(Unit const* me, SplineChainResumeInfo& info);
        // Leaving the object method public for people that know what they're doing to use
        // But really, 99% of the time you should be using the static one instead
        SplineChainResumeInfo GetResumeInfo(Unit const* me) const;

    private:
        void SendSplineFor(Unit* me, uint32 index, uint32& toNext);
        uint32 SendPathSpline(Unit* me, float velocity, Movement::PointsArray const& wp) const;
        uint32 const _id;
        std::vector<SplineChainLink> const& _chain;
        uint8 const _chainSize;
        bool const _walk;
        bool finished;
        uint8 _nextIndex;
        uint8 _nextFirstWP; // only used for resuming
        uint32 _msToNext;
};

#endif
