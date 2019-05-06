/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "Optional.h"
#include <vector>

class Unit;

class TC_GAME_API SplineChainMovementGenerator : public MovementGenerator
{
    public:
        explicit SplineChainMovementGenerator(uint32 id, std::vector<SplineChainLink> const& chain, bool walk = false);
        explicit SplineChainMovementGenerator(SplineChainResumeInfo const& info);

        void Initialize(Unit*) override;
        void Reset(Unit*) override;
        bool Update(Unit*, uint32) override;
        void Deactivate(Unit*) override;
        void Finalize(Unit*, bool, bool) override;
        MovementGeneratorType GetMovementGeneratorType() const override;

        // Builds info that can later be used to resume this spline chain movement at the current position
        static void GetResumeInfo(SplineChainResumeInfo& info, Unit const* owner, Optional<uint32> id = {});
        // Leaving the object method public for people that know what they're doing to use
        // But really, 99% of the time you should be using the static one instead
        SplineChainResumeInfo GetResumeInfo(Unit const* owner) const;
        uint32 GetId() const { return _id; }

    private:
        void SendSplineFor(Unit* owner, uint32 index, uint32& duration);
        uint32 SendPathSpline(Unit* owner, Movement::PointsArray const& path) const;

        uint32 const _id;
        std::vector<SplineChainLink> const& _chain;
        uint8 const _chainSize;
        bool const _walk;
        uint8 _nextIndex;
        uint8 _nextFirstWP; // only used for resuming
        uint32 _msToNext;
};

#endif
