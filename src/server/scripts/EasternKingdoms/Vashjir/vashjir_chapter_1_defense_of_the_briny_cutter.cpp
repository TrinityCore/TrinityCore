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

#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

namespace Scripts::EasternKingdoms::Vashjir::Chapter1
{
namespace Creatures
{
    static constexpr uint32 DrowningSoldierAlliance = 39663;
}
namespace Spells
{
    static constexpr uint32 BlowBubble = 74151;
    static constexpr uint32 BubbleSelf = 74416;
}
namespace Events
{
    namespace PayItForward
    {
        static constexpr uint32 BubbleSelf = 1;
        static constexpr uint32 MoveToNear = 2;
        static constexpr uint32 MoveToShip = 3;
        static constexpr uint32 EnterShip = 4;
        static constexpr uint32 ShipFinish = 5;
    }
}
namespace Points
{
    static constexpr uint32 PointShipFar = 1;
    static constexpr uint32 PointShipNear = 2;
    static constexpr uint32 PointShipEnter = 3;
    static constexpr uint32 PointShipFinish = 4;
}

// 39663 - Drowning Soldier
struct npc_vashjir_drowning_soldier : public ScriptedAI
{
    npc_vashjir_drowning_soldier(Creature* creature) : ScriptedAI(creature) {}

    void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == Spells::BlowBubble)
        {
            DoCastSelf(Spells::BubbleSelf);
            if (Player* player = caster->ToPlayer())
                player->KilledMonsterCredit(Creatures::DrowningSoldierAlliance);
        }

        if (spellInfo->Id == Spells::BubbleSelf)
        {
            _events.ScheduleEvent(Events::PayItForward::BubbleSelf, 1s);
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        switch (id)
        {
            case Points::PointShipFar:
                _events.ScheduleEvent(Events::PayItForward::MoveToNear, 1ms);
                break;
            case Points::PointShipNear:
                _events.ScheduleEvent(Events::PayItForward::MoveToShip, 1ms);
                break;
            case Points::PointShipEnter:
                _events.ScheduleEvent(Events::PayItForward::EnterShip, 1ms);
                break;
            case Points::PointShipFinish:
                _events.ScheduleEvent(Events::PayItForward::ShipFinish, 1ms);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case Events::PayItForward::BubbleSelf:
                    if (Creature* stalker = me->FindNearestCreatureWithOptions(100.0f, { .StringId = "ShipFar" }))
                    me->GetMotionMaster()->MovePoint(Points::PointShipFar, stalker->GetPosition(), true);
                    break;
                case Events::PayItForward::MoveToNear:
                    if (Creature* stalker = me->FindNearestCreatureWithOptions(100.0f, { .StringId = "ShipNear" }))
                        me->GetMotionMaster()->MovePoint(Points::PointShipNear, stalker->GetPosition(), true);
                    break;
                case Events::PayItForward::MoveToShip:
                    if (Creature* stalker = me->FindNearestCreatureWithOptions(100.0f, { .StringId = "ShipEnter" }))
                        me->GetMotionMaster()->MovePoint(Points::PointShipEnter, stalker->GetPosition(), true);
                    break;
                case Events::PayItForward::EnterShip:
                    if (Creature* stalker = me->FindNearestCreatureWithOptions(100.0f, { .StringId = "ShipFinish" }))
                        me->GetMotionMaster()->MovePoint(Points::PointShipFinish, stalker->GetPosition(), true);
                    break;
                case Events::PayItForward::ShipFinish:
                    me->DespawnOrUnsummon(2s);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};
}

void AddSC_vashjir_chapter_1_defense_of_the_briny_cutter()
{
    using namespace Scripts::EasternKingdoms::Vashjir::Chapter1;

    // Creature
    RegisterCreatureAI(npc_vashjir_drowning_soldier);
}
