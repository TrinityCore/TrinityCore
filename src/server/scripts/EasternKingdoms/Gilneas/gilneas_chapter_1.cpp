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
            static constexpr uint32 TalkFrightened = 1;
            static constexpr uint32 MoveToNearStalker = 2;
            static constexpr uint32 MoveToFarStalker = 3;
            static constexpr uint32 FrightenedDespawn = 4;
        }
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
    }

// 34981 - Frightened Citizen
// 35836 - Frightened Citizen
struct npc_frightened_citizen : public ScriptedAI
{
    npc_frightened_citizen(Creature* creature) : ScriptedAI(creature) {}

    void IsSummonedBy(WorldObject* /*summoner*/) override
    {
        me->SetReactState(REACT_PASSIVE);

        if (Creature* stalkerNear = me->FindNearestCreature(Creatures::EvacuationStalkerFirst, 20.0f))
            me->GetMotionMaster()->MovePoint(Points::PointStalkerFirst, stalkerNear->GetPosition(), true);
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        switch (id)
        {
            case Points::PointStalkerFirst:
                _events.ScheduleEvent(Events::EvacuateTheMerchantSquare::TalkFrightened, 1s);
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

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case Events::EvacuateTheMerchantSquare::TalkFrightened:
                    if (TempSummon* summon = me->ToTempSummon())
                    {
                        if (Unit* summoner = summon->GetSummonerUnit())
                        {
                            if (Player* player = summoner->ToPlayer())
                            {
                                player->KilledMonsterCredit(Creatures::EvacuationStalkerFirst);
                                Talk(Texts::FrightenedCitizen::SayFrightenedCitizenRescue, summoner);
                            }
                        }
                    }
                    _events.ScheduleEvent(Events::EvacuateTheMerchantSquare::MoveToNearStalker, 2s);
                    break;
                case Events::EvacuateTheMerchantSquare::MoveToNearStalker:
                    if (Creature* stalker = me->FindNearestCreature(Creatures::EvacuationStalkerFar, 50.0f))
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
};

// 67869 - Knocking
class spell_gilneas_knocking : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo(
        {
            uint32(spellInfo->GetEffect(EFFECT_1).CalcValue()),
            uint32(spellInfo->GetEffect(EFFECT_2).CalcValue())
        });
    }

    void HandleEffect()
    {
        GetCaster()->CastSpell(GetCaster(), GetEffectInfo(RAND(EFFECT_1, EFFECT_2)).CalcValue(), true);
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

    // Spells
    RegisterSpellScript(spell_gilneas_knocking);
}
