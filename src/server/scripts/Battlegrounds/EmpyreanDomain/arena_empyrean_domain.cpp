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

#include "AreaTrigger.h"
#include "Battleground.h"
#include "BattlegroundScript.h"
#include "Creature.h"
#include "GameObject.h"
#include "GenericMovementGenerator.h"
#include "Map.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptActions.h"
#include "ScriptMgr.h"
#include "TaskScheduler.h"

#include <G3D/Vector3.h>

namespace EmpyreanDomain
{
    namespace AreaTriggers
    {
        static constexpr uint32 FlyDownAreaTrigger = 11990000; // TODO CHANGE ME ON PR MERGE
    }

    namespace Creatures
    {
        static constexpr uint32 InvisibleStalker = 169468;
        static constexpr uint32 Guard = 169472;
    }

    namespace GameObjects
    {
        static constexpr uint32 CollisionWall = 352927;
    }

    namespace Points
    {
        static constexpr Position Guard01Dest = { -1177.7396f, 665.9167f, 7266.0874f };
        static constexpr Position Guard02Dest = { -1323.2205f, 794.5243f, 7266.0874f };
        static constexpr Position Guard03Dest = { -1314.2778f, 800.59375f, 7266.283f };
        static constexpr Position Guard04Dest = { -1186.4219f, 657.78125f, 7266.283f };

        static const Movement::PointsArray PurplePath =
        {
            G3D::Vector3(-1317.3438f, 796.5417f, 7269.4243f),
            G3D::Vector3(-1300.9236f, 780.2049f, 7265.0225f),
            G3D::Vector3(-1279.941f, 759.81946f, 7250.053f)
        };

        static const Movement::PointsArray GoldPath =
        {
            G3D::Vector3(-1186.2604f, 668.684f, 7271.891f),
            G3D::Vector3(-1199.6632f, 680.2934f, 7260.527f),
            G3D::Vector3(-1209.1146f, 688.5243f, 7251.5713f)
        };
    }

    namespace Spells
    {
        static constexpr uint32 BastionArenaPvpReactionTrigger = 329820;
        static constexpr uint32 WindDrift = 329804;
        static constexpr uint32 WingsCosmetic = 329819;
        static constexpr uint32 ArenaStartingAreaMarker = 228212;
    }

    namespace StringIds
    {
        static constexpr std::string_view Guard01 = "empyrean_domain_guard_01"sv;
        static constexpr std::string_view Guard02 = "empyrean_domain_guard_02"sv;
        static constexpr std::string_view Guard03 = "empyrean_domain_guard_03"sv;
        static constexpr std::string_view Guard04 = "empyrean_domain_guard_04"sv;
    }

    class PlayerMoveDownEvent : public BasicEvent
    {
    public:
        explicit PlayerMoveDownEvent(Player* player, std::shared_ptr<Scripting::v2::ActionResult<MovementStopReason>> const& action) : _player(player), _action(action) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            if (!_action->IsReady())
            {
                _player->m_Events.AddEventAtOffset(this, 500ms);
                return false;
            }

            _player->RemoveAurasDueToSpell(Spells::WingsCosmetic);
            return true;
        }

    private:
        Player* _player;
        std::shared_ptr<Scripting::v2::ActionResult<MovementStopReason>> _action;
    };
}

struct arena_empyrean_domain : ArenaScript
{
    explicit arena_empyrean_domain(BattlegroundMap* map) : ArenaScript(map) { }

    void OnStart() override
    {
        for (ObjectGuid const& guid : _wallGUIDs)
            if (GameObject* door = battlegroundMap->GetGameObject(guid))
                door->Delete();

        for (ObjectGuid const& guid : _guardGUIDs)
        {
            if (Creature* guard = battlegroundMap->GetCreature(guid))
            {
                if (guard->HasStringId(EmpyreanDomain::StringIds::Guard01))
                    guard->GetMotionMaster()->MovePoint(1, EmpyreanDomain::Points::Guard01Dest);
                else if (guard->HasStringId(EmpyreanDomain::StringIds::Guard02))
                    guard->GetMotionMaster()->MovePoint(1, EmpyreanDomain::Points::Guard02Dest);
                else if (guard->HasStringId(EmpyreanDomain::StringIds::Guard03))
                    guard->GetMotionMaster()->MovePoint(1, EmpyreanDomain::Points::Guard03Dest);
                else if (guard->HasStringId(EmpyreanDomain::StringIds::Guard04))
                    guard->GetMotionMaster()->MovePoint(1, EmpyreanDomain::Points::Guard04Dest);
            }
        }

        for (ObjectGuid const& guid : _stalkerGUIDs)
            if (Creature* stalker = battlegroundMap->GetCreature(guid))
                stalker->CastSpell(nullptr, EmpyreanDomain::Spells::WindDrift);

        _scheduler.Schedule(5s, [&](TaskContext context)
        {
            battlegroundMap->DoOnPlayers([&](Player* player)
            {
                if (player->HasAura(EmpyreanDomain::Spells::WingsCosmetic))
                    return;

                if (!player->HasAura(EmpyreanDomain::Spells::ArenaStartingAreaMarker))
                    return;

                MovePlayerDown(player);
            });

            context.Repeat();
        });

        for (ObjectGuid const& guid : _flyDownAreaTriggerGUIDs)
            if (AreaTrigger const* areaTrigger = battlegroundMap->GetAreaTrigger(guid))
                for (ObjectGuid const& insideUnitGuid : areaTrigger->GetInsideUnits())
                    if (insideUnitGuid.IsPlayer())
                        if (Player* player = battlegroundMap->GetPlayer(insideUnitGuid))
                            MovePlayerDown(player);
    }

    void OnUpdate(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void OnGameObjectCreate(GameObject* gameobject) override
    {
        switch (gameobject->GetEntry())
        {
            case EmpyreanDomain::GameObjects::CollisionWall:
                _wallGUIDs.emplace_back(gameobject->GetGUID());
                break;
            default:
                break;
        }
    }

    void OnCreatureCreate(Creature* creature) override
    {
        switch (creature->GetEntry())
        {
            case EmpyreanDomain::Creatures::Guard:
                _guardGUIDs.emplace_back(creature->GetGUID());
                break;
            case EmpyreanDomain::Creatures::InvisibleStalker:
                _stalkerGUIDs.emplace_back(creature->GetGUID());
                break;
            default:
                break;
        }
    }

    void OnAreaTriggerCreate(AreaTrigger* areaTrigger) override
    {
        if (!areaTrigger->IsStaticSpawn())
            return;

        switch (areaTrigger->GetEntry())
        {
            case EmpyreanDomain::AreaTriggers::FlyDownAreaTrigger:
                _flyDownAreaTriggerGUIDs.emplace_back(areaTrigger->GetGUID());
                break;
            default:
                break;
        }
    }

    void OnPlayerJoined(Player* player, bool /*inBattleground*/) override
    {
        player->CastSpell(nullptr, EmpyreanDomain::Spells::BastionArenaPvpReactionTrigger, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
        });
    }

    static void MovePlayerDown(Player* player)
    {
        if (!player)
            return;

        player->CastSpell(nullptr, EmpyreanDomain::Spells::WingsCosmetic, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
        });

        Movement::PointsArray path;
        if (player->GetBGTeam() == ALLIANCE)
            path = EmpyreanDomain::Points::PurplePath;
        else
            path = EmpyreanDomain::Points::GoldPath;

        std::function<void(Movement::MoveSplineInit&)> initializer = [=](Movement::MoveSplineInit& init)
        {
            init.MovebyPath(path);
            init.SetWalk(false);
            init.SetFly();
            init.SetUncompressed();
            init.SetSmooth();
            init.SetVelocity(17.5f);
        };

        std::shared_ptr<Scripting::v2::ActionResult<MovementStopReason>> waitEvent = std::make_shared<Scripting::v2::ActionResult<MovementStopReason>>();
        Scripting::v2::ActionResultSetter<MovementStopReason> actionResultSetter = Scripting::v2::ActionResult<MovementStopReason>::GetResultSetter(waitEvent);
        player->GetMotionMaster()->LaunchMoveSpline(std::move(initializer), 1, MOTION_PRIORITY_NORMAL, EFFECT_MOTION_TYPE, std::move(actionResultSetter));

        player->m_Events.AddEventAtOffset(new EmpyreanDomain::PlayerMoveDownEvent(player, waitEvent), 500ms);
    }

private:
    GuidVector _wallGUIDs;
    GuidVector _guardGUIDs;
    GuidVector _stalkerGUIDs;
    GuidVector _flyDownAreaTriggerGUIDs;

    TaskScheduler _scheduler;
};

void AddSC_arena_empyrean_domain()
{
    RegisterBattlegroundMapScript(arena_empyrean_domain, 2373);
}
