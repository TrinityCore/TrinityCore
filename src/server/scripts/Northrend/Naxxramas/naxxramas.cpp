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
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "ScriptedCreature.h"
#include "PassiveAI.h"
#include "TemporarySummon.h"
#include "naxxramas.h"

/*
    According to sniffs there are multiple spawn groups (5 to be precise) since Living Poisons with the same initial spline
    destination are only getting spawned in 31 seconds intervals. For the sake of readability we will stick
    with one and increase the interval.

    Here are some values:
    - The "Frogger" spawner spawns the same group in 31 second intervals. Since we are lazy and wanna keep the values readable
      we stick with one timer set at 6s.
    - The slime moves with a spline velocity of 2.5f which equals the walk speed of it.
    - If a slime explodes it will despawn 8.5s after its death.
    - If a slime reaches its final spline destination it will despawn after 500 milliseconds -+ 100 depending on Blizzard's packet interval
*/

enum NaxxEvents
{
    EVENT_SUMMON_LIVING_POISON = 1
};

struct LivingPoisonData
{
    Position SpawnPos;
    Position FirstSplineDest;
    Position SecondSplineDest;
    Milliseconds NextSplineTimer;
};

std::array<LivingPoisonData, 3> const LivingPoisons = {
    {
        {
            { 3175.399f, -3134.5156f, 293.37762f, 4.4535513f },
            { 3167.0532f, -3150.3875f, 294.0628f },
            { 3158.178f, -3163.7876f, 293.3122f },
            5s + 500ms
        },
        {
            { 3154.5203f, -3125.6458f, 293.44492f, 4.6543846f },
            { 3149.712f, -3142.9995f, 294.0628f },
            { 3145.9402f, -3158.5762f, 293.32156f },
            6s
        },
        {
            { 3128.609f, -3119.2295f, 293.42194f, 4.7248187f },
            { 3128.868f, -3140.0342f, 294.0628f },
            { 3129.5356f, -3156.7466f, 293.32394f },
            7s
        }
    }
};

struct npc_frogger_trigger_naxx : public NullCreatureAI
{
    npc_frogger_trigger_naxx(Creature* creature) : NullCreatureAI(creature) { }

    void Reset() override
    {
        _events.ScheduleEvent(EVENT_SUMMON_LIVING_POISON, 0s);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SUMMON_LIVING_POISON:
                    for (LivingPoisonData const& poisonData : LivingPoisons)
                    {
                        if (Creature* slime = DoSummon(NPC_LIVING_POISON, poisonData.SpawnPos, 8s + 500ms, TEMPSUMMON_CORPSE_TIMED_DESPAWN))
                        {
                            LaunchSpline(slime, poisonData.FirstSplineDest);
                            slime->m_Events.AddEventAtOffset([poisonData, slime]()
                            {
                                if (slime->isDead())
                                    return;

                                LaunchSpline(slime, poisonData.SecondSplineDest);
                                if (!slime->movespline->Finalized())
                                    slime->DespawnOrUnsummon(Milliseconds(slime->movespline->Duration()) + 500ms);
                            }, poisonData.NextSplineTimer);
                        }
                    }
                    _events.Repeat(6s);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;

    static void LaunchSpline(Creature* slime, Position const& dest)
    {
        std::function<void(Movement::MoveSplineInit&)> initializer = [dest = dest](Movement::MoveSplineInit& init)
        {
            init.MoveTo(dest.GetPositionX(), dest.GetPositionY(), dest.GetPositionZ());
            init.SetWalk(true);
        };
        slime->GetMotionMaster()->LaunchMoveSpline(std::move(initializer));
    }
};

void AddSC_naxxramas()
{
    RegisterNaxxramasCreatureAI(npc_frogger_trigger_naxx);
}
