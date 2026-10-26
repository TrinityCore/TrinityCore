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
#include "gilneas.h"
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
#include <G3D/Vector3.h>

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
        if (_door && _door->Exit.empty())
            OnArrivedAtFirstStalker();
        else if (_door)
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

    // The citizen says the line (and its talk / cower emote) on arrival, then gives the credit and runs on 1.2 s later
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

                    // 5 of the 13 doors with an exit have no Near marker: those citizens run straight to the Far one
                    if (_door && _door->Exit.empty())
                        me->DespawnOrUnsummon();
                    else if (_door && !_door->HasNearMarker)
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
                    // shut in behind the same door as the citizen
                    if (_door && _door->Exit.empty())
                        me->DespawnOrUnsummon();
                    else if (_door)
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
