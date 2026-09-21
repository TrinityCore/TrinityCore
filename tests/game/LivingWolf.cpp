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


#ifdef AIWORLD_STANDALONE_TEST
#include <cstdlib>
#include <iostream>
#define TEST_CASE(name, tags) static void RunLivingWolfTests()
#define REQUIRE(value) do { if (!(value)) { std::cerr << "Failed at line " << __LINE__ << '\n'; std::exit(1); } ++checks; } while (false)
static unsigned checks = 0;
#else
#include "tc_catch2.h"
#endif

#include "Action/ActionSystem.h"
#include "Agent/WolfBehaviorPolicy.h"
#include <limits>

TEST_CASE("Living wolves choose survival and validate actual meals", "[AIWorld][LivingWolf]")
{
    using namespace WolfBehaviorPolicy;
    REQUIRE(!ShouldFlee(0.10f, false));
    REQUIRE(ShouldFlee(0.71f, false));
    REQUIRE(!ShouldFlee(0.60f, false));
    REQUIRE(ShouldFlee(0.60f, true));
    REQUIRE(!ShouldFlee(0.49f, true));
    REQUIRE(ShouldFlee(std::numeric_limits<float>::quiet_NaN(), false));
    REQUIRE(!WantsHunt(0.0f, 0.0f, false));
    REQUIRE(WantsHunt(0.8f, 0.1f, false));
    REQUIRE(!WantsHunt(0.8f, 0.8f, false));
    REQUIRE(!WantsHunt(0.8f, 0.1f, true));
    REQUIRE(!WantsHunt(std::numeric_limits<float>::quiet_NaN(), 0.1f, false));
    REQUIRE(!Elapsed(999, 1000, FeedDurationMs));
    REQUIRE(!Elapsed(5999, 1000, FeedDurationMs));
    REQUIRE(Elapsed(6000, 1000, FeedDurationMs));
    REQUIRE(!Elapsed(2000, std::numeric_limits<std::uint64_t>::max() - 1, FeedDurationMs));

    ActionSystem system;
    ActionRequest request;
    request.Type = ActionType::Attack;
    request.SourceGoal = GoalType::Defend;
    request.GoalStartedAtMs = 1000;
    request.Target = ActionTargetRef{ ObjectGuid::Create<HighGuid::Player>(1), 0 };
    ActionValidationContext context;
    context.ControlMode = AgentControlMode::AIWorldControlled;
    context.Materialized = true;
    context.Alive = true;
    context.ActiveGoalType = GoalType::Defend;
    context.ActiveGoalStartedAtMs = 1000;
    context.TargetGuid = request.Target->Guid;
    context.DefenseThreatGuid = request.Target->Guid;
    context.TargetResolved = true;
    context.TargetAlive = true;
    context.TargetAttackable = true;
    context.TargetWithinAttackRange = true;
    context.TargetInLineOfSight = true;
    REQUIRE(system.Validate(request, context).Allowed);
    auto rejectDefense = [&](auto change) { auto bad = context; change(bad); REQUIRE(!system.Validate(request, bad).Allowed); };
    rejectDefense([](auto& c) { c.DefenseThreatGuid.Clear(); });
    rejectDefense([](auto& c) { c.ControlMode = AgentControlMode::ObserveOnly; });
    rejectDefense([](auto& c) { c.TargetAlive = false; });
    rejectDefense([](auto& c) { c.HasActiveMovement = true; });
    rejectDefense([](auto& c) { c.TargetResolved = false; });
    rejectDefense([](auto& c) { c.TargetAttackable = false; });
    rejectDefense([](auto& c) { c.TargetMapId = 1; });
    rejectDefense([](auto& c) { c.TargetWithinAttackRange = false; });
    rejectDefense([](auto& c) { c.TargetInLineOfSight = false; });
    rejectDefense([](auto& c) { c.ActiveGoalStartedAtMs = 999; });
    rejectDefense([](auto& c) { c.ActorCurrentVictimGuid = ObjectGuid::Create<HighGuid::Player>(2); });

    // The broader defense contract must not broaden proactive HUNT to players.
    request.SourceGoal = GoalType::Hunt;
    context.ActiveGoalType = GoalType::Hunt;
    REQUIRE(!system.Validate(request, context).Allowed);

    request.Type = ActionType::Eat;
    request.SourceGoal = GoalType::Feed;
    request.Target = ActionTargetRef{ ObjectGuid::Create<HighGuid::Unit>(525, 9), 525 };
    context.ActiveGoalType = GoalType::Feed;
    context.TargetGuid = request.Target->Guid;
    context.TargetEntry = 525;
    context.MealTargetGuid = request.Target->Guid;
    context.TargetAlive = false;
    REQUIRE(system.Validate(request, context).Allowed);
    auto rejectMeal = [&](auto change) { auto bad = context; change(bad); REQUIRE(!system.Validate(request, bad).Allowed); };
    rejectMeal([](auto& c) { c.MealTargetGuid.Clear(); });
    rejectMeal([](auto& c) { c.MealTargetGuid = ObjectGuid::Create<HighGuid::Unit>(525, 10); });
    rejectMeal([](auto& c) { c.TargetAlive = true; });
    rejectMeal([](auto& c) { c.TargetResolved = false; });
    rejectMeal([](auto& c) { c.InCombat = true; });
    rejectMeal([](auto& c) { c.HasActiveMovement = true; });
    rejectMeal([](auto& c) { c.TargetWithinAttackRange = false; });
    rejectMeal([](auto& c) { c.TargetInLineOfSight = false; });
    rejectMeal([](auto& c) { c.TargetMapId = 1; });
    rejectMeal([](auto& c) { c.ControlMode = AgentControlMode::ObserveOnly; });
    rejectMeal([](auto& c) { c.ActiveGoalStartedAtMs = 999; });

    request.Type = ActionType::Rest;
    request.SourceGoal = GoalType::WildlifeRest;
    request.Target.reset();
    context.ActiveGoalType = GoalType::WildlifeRest;
    REQUIRE(!system.Validate(request, context).Allowed);
    context.WildlifeRestAllowed = true;
    REQUIRE(system.Validate(request, context).Allowed);
    context.InCombat = true;
    REQUIRE(!system.Validate(request, context).Allowed);
    context.InCombat = false;
    context.HasActiveMovement = true;
    REQUIRE(!system.Validate(request, context).Allowed);
}

#ifdef AIWORLD_STANDALONE_TEST
int main()
{
    RunLivingWolfTests();
    std::cout << "LivingWolf: " << checks << " checks passed\n";
}
#endif
