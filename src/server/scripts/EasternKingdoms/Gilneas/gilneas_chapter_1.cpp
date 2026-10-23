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

#include "ScriptMgr.h"
#include "CreatureAIImpl.h"
#include "MotionMaster.h"
#include "MoveSplineInit.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "PhasingHandler.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

namespace Scripts::EasternKingdoms::Gilneas::Chapter1
{
    namespace Creatures
    {
        static constexpr uint32 EvacuationStalkerFirst = 35830;
        static constexpr uint32 EvacuationStalkerNear = 35010;
        static constexpr uint32 EvacuationStalkerFar = 35011;
    }

    namespace Events
    {
        namespace EvacuateTheMerchantSquare
        {
            static constexpr uint32 MoveToNearStalker = 2;
            static constexpr uint32 MoveToFarStalker = 3;
            static constexpr uint32 FrightenedDespawn = 4;
            static constexpr uint32 WorgenLeaveHouse = 5;
            static constexpr uint32 WorgenHunt = 6;
        }
    }

    namespace Spells
    {
        static constexpr uint32 EnrageHaste = 56646;
    }

    namespace Texts
    {
        namespace FrightenedCitizen
        {
            static constexpr uint32 SayFrightenedCitizenRescue = 0;
        }
    }

    namespace Points
    {
        static constexpr uint32 PointStalkerFirst = 1;
        static constexpr uint32 PointStalkerNear = 2;
        static constexpr uint32 PointStalkerFar = 3;
        static constexpr uint32 PointDoorExit = 4;
    }

// The knock summons land on the door's trigger 35374 inside the house, and there is no
// navmesh route out through the door frame. Retail creates the citizen with a fixed spline
// out of the house (the same for every summon at the same door) ending on the door's First
// marker 35830; the Rampaging Worgen leaves the same way. The five west-side doors were not
// observed and go straight from the trigger to the marker in front of them.
struct EvacuationDoor
{
    Position Trigger;
    std::vector<Position> Exit;
    bool HasNearMarker; // the citizen runs on to a Near marker 35010 before the Far marker 35011
};

static std::array<EvacuationDoor, 14> const EvacuationDoors =
{{
    { { -1573.93f, 1381.87f, 36.99f }, { { -1571.10f, 1383.26f, 36.99f }, { -1570.84f, 1384.08f, 37.00f }, { -1570.27f, 1384.89f, 37.00f }, { -1569.99f, 1386.06f, 36.36f }, { -1569.60f, 1387.68f, 36.41f } }, true },
    { { -1566.31f, 1413.51f, 36.64f }, { { -1565.56f, 1413.15f, 36.64f }, { -1564.25f, 1410.68f, 36.64f }, { -1562.61f, 1410.14f, 36.64f }, { -1561.41f, 1410.00f, 36.05f }, { -1561.02f, 1409.96f, 36.03f }, { -1559.24f, 1409.76f, 35.97f } }, true },
    { { -1533.91f, 1447.53f, 36.64f }, { { -1534.16f, 1447.38f, 36.64f }, { -1536.50f, 1445.92f, 36.64f }, { -1537.03f, 1444.28f, 36.64f }, { -1537.21f, 1443.08f, 36.00f }, { -1537.43f, 1441.55f, 35.98f }, { -1537.60f, 1440.43f, 35.97f } }, false },
    { { -1516.33f, 1375.24f, 36.53f }, { { -1516.12f, 1374.76f, 36.53f }, { -1515.00f, 1372.10f, 36.53f }, { -1513.36f, 1371.57f, 36.53f }, { -1512.19f, 1371.46f, 35.99f }, { -1511.78f, 1371.42f, 36.00f }, { -1508.22f, 1371.37f, 36.00f }, { -1506.77f, 1371.35f, 35.56f } }, false },
    { { -1490.54f, 1367.53f, 36.53f }, { { -1491.98f, 1369.91f, 36.53f }, { -1492.25f, 1370.35f, 36.53f } }, true },
    { { -1459.78f, 1447.69f, 36.64f }, { { -1460.54f, 1447.27f, 36.64f }, { -1462.97f, 1445.92f, 36.64f }, { -1463.50f, 1444.28f, 36.64f }, { -1463.67f, 1443.09f, 36.00f }, { -1463.85f, 1441.79f, 35.98f }, { -1463.95f, 1441.07f, 35.98f } }, true },
    { { -1425.08f, 1409.70f, 36.78f }, { { -1422.31f, 1411.31f, 36.79f }, { -1421.92f, 1412.21f, 36.79f }, { -1421.58f, 1412.98f, 36.79f }, { -1421.45f, 1414.15f, 36.00f }, { -1421.33f, 1415.59f, 36.00f }, { -1421.35f, 1416.15f, 35.56f }, { -1421.13f, 1417.47f, 35.56f } }, true },
    { { -1423.91f, 1432.49f, 36.41f }, { { -1424.02f, 1432.78f, 36.41f }, { -1425.08f, 1435.50f, 36.41f }, { -1426.72f, 1435.39f, 36.42f }, { -1427.91f, 1435.30f, 35.80f }, { -1428.31f, 1435.28f, 35.76f }, { -1428.84f, 1435.50f, 35.77f }, { -1431.40f, 1436.61f, 35.91f }, { -1432.41f, 1437.04f, 35.85f } }, true },
    { { -1391.25f, 1399.27f, 36.41f }, { { -1392.84f, 1402.06f, 36.41f }, { -1393.74f, 1402.46f, 36.42f }, { -1394.52f, 1402.79f, 36.42f }, { -1395.29f, 1402.92f, 36.11f }, { -1395.95f, 1403.03f, 35.92f }, { -1396.41f, 1403.11f, 35.95f }, { -1397.94f, 1403.38f, 35.95f } }, true },
    // west side, not observed: straight out to the First marker
    { { -1545.37f, 1306.57f, 36.50f }, { { -1551.71f, 1308.93f, 35.96f } }, false },
    { { -1587.82f, 1356.02f, 36.61f }, { { -1583.44f, 1363.10f, 35.74f } }, false },
    { { -1531.89f, 1318.65f, 36.66f }, { { -1530.54f, 1326.66f, 35.64f } }, false },
    { { -1579.76f, 1339.98f, 36.61f }, { { -1571.86f, 1335.84f, 35.70f } }, false },
    { { -1489.31f, 1330.34f, 36.57f }, { { -1487.21f, 1338.23f, 35.64f } }, false }
}};

EvacuationDoor const* FindEvacuationDoor(Position const& pos)
{
    for (EvacuationDoor const& door : EvacuationDoors)
        if (door.Trigger.GetExactDist2dSq(pos) < 2.0f * 2.0f)
            return &door;
    return nullptr;
}

void LaunchDoorExit(Creature* creature, EvacuationDoor const& door)
{
    Movement::PointsArray path;
    path.reserve(door.Exit.size() + 1);
    path.emplace_back(creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ()); // replaced by the current position on launch
    for (Position const& point : door.Exit)
        path.emplace_back(point.GetPositionX(), point.GetPositionY(), point.GetPositionZ());

    creature->GetMotionMaster()->LaunchMoveSpline([path = std::move(path)](Movement::MoveSplineInit& init)
    {
        init.MovebyPath(path);
        init.SetWalk(false);
    }, Points::PointDoorExit, MOTION_PRIORITY_NORMAL, EFFECT_MOTION_TYPE);
}

// 34981 - Frightened Citizen
// 35836 - Frightened Citizen
struct npc_frightened_citizen : public ScriptedAI
{
    npc_frightened_citizen(Creature* creature) : ScriptedAI(creature), _door(nullptr) {}

    void IsSummonedBy(WorldObject* /*summoner*/) override
    {
        me->SetReactState(REACT_PASSIVE);

        _door = FindEvacuationDoor(me->GetPosition());
        if (_door)
            LaunchDoorExit(me, *_door);
        else if (Creature* stalkerNear = me->FindNearestCreature(Creatures::EvacuationStalkerFirst, 20.0f))
            me->GetMotionMaster()->MovePoint(Points::PointStalkerFirst, stalkerNear->GetPosition(), true);
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == EFFECT_MOTION_TYPE && id == Points::PointDoorExit)
        {
            OnArrivedAtFirstStalker();
            return;
        }

        if (type != POINT_MOTION_TYPE)
            return;

        switch (id)
        {
            case Points::PointStalkerFirst:
                OnArrivedAtFirstStalker();
                break;
            case Points::PointStalkerNear:
                _events.ScheduleEvent(Events::EvacuateTheMerchantSquare::MoveToFarStalker, 1ms);
                break;
            case Points::PointStalkerFar:
                _events.ScheduleEvent(Events::EvacuateTheMerchantSquare::FrightenedDespawn, 1ms);
                break;
            default:
                break;
        }
    }

    // Retail says the line (and its talk / cower emote) on arrival, then gives the credit and runs on 1.2 s later
    void OnArrivedAtFirstStalker()
    {
        Talk(Texts::FrightenedCitizen::SayFrightenedCitizenRescue, GetSummoner());
        _events.ScheduleEvent(Events::EvacuateTheMerchantSquare::MoveToNearStalker, 1200ms);
    }

    Unit* GetSummoner() const
    {
        if (TempSummon const* summon = me->ToTempSummon())
            return summon->GetSummonerUnit();
        return nullptr;
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case Events::EvacuateTheMerchantSquare::MoveToNearStalker:
                    if (Unit* summoner = GetSummoner())
                        if (Player* player = summoner->ToPlayer())
                            player->KilledMonsterCredit(Creatures::EvacuationStalkerFirst);

                    // 2 of the 9 observed doors have no Near marker: those citizens run straight to the Far one
                    if (_door && !_door->HasNearMarker)
                        _events.ScheduleEvent(Events::EvacuateTheMerchantSquare::MoveToFarStalker, 1ms);
                    else if (Creature* stalker = me->FindNearestCreature(Creatures::EvacuationStalkerFar, 50.0f))
                        me->GetMotionMaster()->MovePoint(Points::PointStalkerFar, stalker->GetPosition(), true);
                    else if (Creature* stalker = me->FindNearestCreature(Creatures::EvacuationStalkerNear, 100.0f))
                        me->GetMotionMaster()->MovePoint(Points::PointStalkerNear, stalker->GetPosition(), true);
                    break;
                case Events::EvacuateTheMerchantSquare::MoveToFarStalker:
                    if (Creature* stalker = me->FindNearestCreature(Creatures::EvacuationStalkerFar, 500.0f))
                        me->GetMotionMaster()->MovePoint(Points::PointStalkerFar, stalker->GetPosition(), true);
                    break;
                case Events::EvacuateTheMerchantSquare::FrightenedDespawn:
                    me->DespawnOrUnsummon();
                    break;
                default:
                    break;
            }
        }
    }
private:
    EventMap _events;
    EvacuationDoor const* _door;
};

// 35660 - Rampaging Worgen
struct npc_rampaging_worgen_evacuation : public ScriptedAI
{
    npc_rampaging_worgen_evacuation(Creature* creature) : ScriptedAI(creature), _door(nullptr), _enraged(false) {}

    void IsSummonedBy(WorldObject* summoner) override
    {
        _summonerGUID = summoner->GetGUID();
        _door = FindEvacuationDoor(me->GetPosition());

        // Waits inside the house, untouchable, while the citizen runs out
        me->SetImmuneToAll(true);
        me->SetReactState(REACT_PASSIVE);
        _events.ScheduleEvent(Events::EvacuateTheMerchantSquare::WorgenLeaveHouse, 2400ms);
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != EFFECT_MOTION_TYPE || id != Points::PointDoorExit)
            return;

        // Do not evade back into the house
        me->SetHomePosition(me->GetPosition());
        _events.ScheduleEvent(Events::EvacuateTheMerchantSquare::WorgenHunt, 500ms);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_enraged && me->HealthBelowPctDamaged(30, damage))
        {
            _enraged = true;
            DoCastSelf(Spells::EnrageHaste);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case Events::EvacuateTheMerchantSquare::WorgenLeaveHouse:
                    if (_door)
                        LaunchDoorExit(me, *_door);
                    else
                        _events.ScheduleEvent(Events::EvacuateTheMerchantSquare::WorgenHunt, 1ms);
                    break;
                case Events::EvacuateTheMerchantSquare::WorgenHunt:
                    me->SetImmuneToAll(false);
                    me->SetReactState(REACT_AGGRESSIVE);
                    if (Unit* summoner = ObjectAccessor::GetUnit(*me, _summonerGUID))
                        AttackStart(summoner);
                    break;
                default:
                    break;
            }
        }

        UpdateVictim();
    }

private:
    EventMap _events;
    ObjectGuid _summonerGUID;
    EvacuationDoor const* _door;
    bool _enraged;
};

// 67869 - Knocking
class spell_gilneas_knocking : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo(
        {
            uint32(spellInfo->GetEffect(EFFECT_1).CalcValueAsInt()),
            uint32(spellInfo->GetEffect(EFFECT_2).CalcValueAsInt())
        });
    }

    void HandleEffect()
    {
        GetCaster()->CastSpell(GetCaster(), GetEffectInfo(RAND(EFFECT_1, EFFECT_2)).CalcValueAsInt(), true);
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_gilneas_knocking::HandleEffect);
    }
};
}

void AddSC_gilneas_chapter_1()
{
    using namespace Scripts::EasternKingdoms::Gilneas::Chapter1;

    // Creatures
    RegisterCreatureAI(npc_frightened_citizen);
    RegisterCreatureAI(npc_rampaging_worgen_evacuation);

    // Spells
    RegisterSpellScript(spell_gilneas_knocking);
}
