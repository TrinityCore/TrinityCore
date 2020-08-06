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

enum Events
{
    EVENT_SUMMON_LIVING_POISON = 1
};

constexpr uint8 const MaxLivingPoisons = 3;
std::array<Position, MaxLivingPoisons> LivingPoisonSpawnPositions =
{
    Position(3175.399f, -3134.5156f, 293.37762f, 4.4535513f),
    Position(3154.5203f, -3125.6458f, 293.44492f, 4.6543846f),
    Position(3128.609f,  -3119.2295f, 293.42194f, 4.7248187f)
};

std::array<Position, MaxLivingPoisons> LivingPoisonInitialSplineDestinations =
{
    Position(3167.0532f, -3150.3875f, 294.0628f),
    Position(3149.712f, -3142.9995f, 294.0628f),
    Position(3128.868f, -3140.0342f, 294.0628f)
};

std::array<Position, MaxLivingPoisons> LivingPoisonSecondSplineDestinations =
{
    Position(3158.178f,  -3163.7876f, 293.3122f),
    Position(3145.9402f, -3158.5762f, 293.32156f),
    Position(3129.5356f, -3156.7466f, 293.32394f)
};

std::array<Milliseconds, MaxLivingPoisons> LivingPoisonNextSplineTimer =
{
    5s + 500ms,
    6s,
    7s
};

struct npc_frogger_trigger_naxx : public NullCreatureAI
{
    npc_frogger_trigger_naxx(Creature* creature) : NullCreatureAI(creature) { }

    void Reset() override
    {
        _events.ScheduleEvent(EVENT_SUMMON_LIVING_POISON, 1ms);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SUMMON_LIVING_POISON:
                    for (uint8 i = 0; i < MaxLivingPoisons; ++i)
                    {
                        if (Creature* slime = DoSummon(NPC_LIVING_POISON, LivingPoisonSpawnPositions[i], 8500/*8s + 500ms*/, TEMPSUMMON_CORPSE_TIMED_DESPAWN))
                        {
                            LaunchSpline(slime, LivingPoisonInitialSplineDestinations[i]);
                            slime->m_Events.AddEventAtOffset([i, slime, this]()
                            {
                                if (slime->isDead())
                                    return;

                                LaunchSpline(slime, LivingPoisonSecondSplineDestinations[i]);
                                if (!slime->movespline->Finalized())
                                    slime->DespawnOrUnsummon(Milliseconds(slime->movespline->Duration()) + 500ms);

                            }, LivingPoisonNextSplineTimer[i]);
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

    void LaunchSpline(Creature* slime, Position const dest)
    {
        Movement::MoveSplineInit init(slime);
        init.MoveTo(dest.GetPositionX(), dest.GetPositionY(), dest.GetPositionZ());
        init.SetWalk(true);
        slime->GetMotionMaster()->LaunchMoveSpline(std::move(init));
    }
};

void AddSC_naxxramas()
{
    RegisterNaxxramasCreatureAI(npc_frogger_trigger_naxx);
}
