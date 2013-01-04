/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "scholomance.h"
#include "MoveSplineInit.h"
#include "GameObjectAI.h"
#include "Player.h"

enum Says
{
   EMOTE_SUMMONED                     = 0
};

enum Spells
{
    SPELL_SWOOP                       = 18144,
    SPELL_WING_FLAP                   = 12882,
    SPELL_PIERCE_ARMOR                = 6016,
    SPELL_DISARM                      = 8379,

    SPELL_KIRTONOS_TRANSFORM          = 16467, // 9:56 10:14 10:33 10:49 // 10:57 attack stopped? Display id changed 12K hp 7534

    SPELL_SHADOW_BOLT                 = 17228,
    SPELL_CURSE_OR_TONGUES            = 12889,
    SPELL_DONINATE_MIND               = 14515
};

enum Events
{
    EVENT_SWOOP                       = 1,
    EVENT_WING_FLAP                   = 2,
    EVENT_PIERCE_ARMOR                = 3,
    EVENT_DISARM                      = 4,
    EVENT_SHADOW_BOLT                 = 5,
    EVENT_CURSE_OR_TONGUES            = 6,
    EVENT_DONINATE_MIND               = 7,
    EVENT_KIRTONOS_TRANSFORM          = 8
};

enum Points
{
    MAX_KIRTONOS_WAYPOINTS_INTRO   = 14,
    POINT_KIRTONOS_LAND            = 14
};

Position const kirtonosIntroWaypoint[MAX_KIRTONOS_WAYPOINTS_INTRO] =
{
    {316.7087f, 71.26834f, 104.5843f, 0.0f},
    {321.1605f, 72.80973f, 104.6676f, 0.0f},
    {332.3713f, 77.98991f, 105.8621f, 0.0f},
    {333.3254f, 86.60159f, 106.6399f, 0.0f},
    {334.1263f, 101.6836f, 106.8343f, 0.0f},
    {331.0458f, 114.5935f, 106.3621f, 0.0f},
    {329.5439f, 126.7019f, 106.1399f, 0.0f},
    {335.2471f, 136.5460f, 105.7232f, 0.0f},
    {343.2100f, 139.9459f, 107.6399f, 0.0f},
    {364.3288f, 140.9012f, 109.9454f, 0.0f},
    {362.6760f, 115.6384f, 110.3065f, 0.0f},
    {341.7896f, 91.94390f, 107.1676f, 0.0f},
    {313.4945f, 93.45945f, 104.0565f, 0.0f},
    {306.3839f, 93.61675f, 104.0565f, 0.0f},
};

class boss_kirtonos_the_herald : public CreatureScript
{
    public: boss_kirtonos_the_herald() : CreatureScript("boss_kirtonos_the_herald") { }

        struct boss_kirtonos_the_heraldAI : public BossAI
        {
            boss_kirtonos_the_heraldAI(Creature* creature) : BossAI(creature, TYPE_KIRTONOS) { }

            void Reset()
            {
                _combatPhase = 0;
                _summonPhase = 0;
                _summonTimer = 0;
                if (GameObject* gate = me->GetMap()->GetGameObject(instance->GetData64(GO_GATE_KIRTONOS)))
                    gate->SetGoState(GO_STATE_ACTIVE);
                _Reset();
            }

            void EnterCombat(Unit* /*who*/)
            {
                events.ScheduleEvent(EVENT_SWOOP, urand(7000, 8000));                 // Phase 1 10:04 10:19
                events.ScheduleEvent(EVENT_WING_FLAP, urand(14000, 15000));           // Phase 1 10:11 10:24
                events.ScheduleEvent(EVENT_PIERCE_ARMOR, urand(17000, 18000));        // Phase 1 10:14
                events.ScheduleEvent(EVENT_DISARM, urand(21000, 22000));              // Phase 1 10:18 10:29

                events.ScheduleEvent(EVENT_SHADOW_BOLT, urand(42200, 47700));         // Phase 2 10:38
                events.ScheduleEvent(EVENT_CURSE_OR_TONGUES, urand(53200, 56000));    // Phase 2
                events.ScheduleEvent(EVENT_DONINATE_MIND, urand(34000, 40000));       // Phase 2
                events.ScheduleEvent(EVENT_KIRTONOS_TRANSFORM, urand(18000, 20000));  // Phase 2
                _EnterCombat();
            }

            void KilledUnit(Unit* /*victim*/)
            {

            }

            void JustDied(Unit* /*killer*/)
            {
                if (GameObject* gate = me->GetMap()->GetGameObject(instance->GetData64(GO_GATE_KIRTONOS)))
                    gate->SetGoState(GO_STATE_ACTIVE);
                if (GameObject* brazier = me->GetMap()->GetGameObject(instance->GetData64(GO_BRAZIER_OF_THE_HERALD)))
                {
                    brazier->ResetDoorOrButton();
                    brazier->SetGoState(GO_STATE_READY);
                }
                _JustDied();
            }

            void EnterEvadeMode()
            {
                if (GameObject* gate = me->GetMap()->GetGameObject(instance->GetData64(GO_GATE_KIRTONOS)))
                    gate->SetGoState(GO_STATE_ACTIVE);
                if (GameObject* brazier = me->GetMap()->GetGameObject(instance->GetData64(GO_BRAZIER_OF_THE_HERALD)))
                {
                    brazier->ResetDoorOrButton();
                    brazier->SetGoState(GO_STATE_READY);
                }
                me->DespawnOrUnsummon(5000);
            }

            void DamageTaken(Unit* /*killer*/, uint32 &damage)
            {

            }

            void IsSummonedBy(Unit* summoner)
            {
                me->SetDisableGravity(true);
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                _summonPhase = 1;
                _summonTimer = 1;
                _currentPoint = 0;
            }

            void JustSummoned(Creature* summon)
            {
                BossAI::JustSummoned(summon);
            }

            void MovementInform(uint32 movementType, uint32 pointId)
            {
                if (movementType != POINT_MOTION_TYPE)
                    return;

                _currentPoint = pointId + 1;
            }

            void UpdateAI(uint32 const diff)
            {
                if (_summonPhase)
                {
                    if (_summonTimer <= diff)
                    {
                        switch (_summonPhase)
                        {
                            case 1:
                                if (_currentPoint < POINT_KIRTONOS_LAND)
                                    me->GetMotionMaster()->MovePoint(_currentPoint, kirtonosIntroWaypoint[_currentPoint]);
                                else
                                {
                                    _summonTimer = 1000;
                                    _summonPhase = 2;
                                }
                                break;
                            case 2:
                                me->GetMotionMaster()->MovePoint(0, 299.4884f, 92.76137f, 105.6335f);
                                _summonTimer = 1000;
                                _summonPhase = 3;
                                break;
                            case 3:
                                if (GameObject* gate = me->GetMap()->GetGameObject(instance->GetData64(GO_GATE_KIRTONOS)))
                                    gate->SetGoState(GO_STATE_READY);
                                me->SetFacingTo(0.01745329f);
                                _summonTimer = 3000;
                                _summonPhase = 4;
                                break;
                            case 4:
                                if (GameObject* brazier = me->GetMap()->GetGameObject(instance->GetData64(GO_BRAZIER_OF_THE_HERALD)))
                                    brazier->SetGoState(GO_STATE_READY);
                                me->SetDisableGravity(false);
                                DoCast(me, SPELL_KIRTONOS_TRANSFORM);
                                _summonTimer = 1000;
                                _summonPhase = 5;
                                break;
                            case 5:
                                me->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                                me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, uint32(11365));
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                                me->SetReactState(REACT_AGGRESSIVE);
                                _summonTimer = 0;
                                _summonPhase = 0;
                            break;
                        }
                    }
                    else
                    _summonTimer -= diff;
                }

            if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SWOOP:
                            DoCast(me, SPELL_SWOOP);
                            events.ScheduleEvent(EVENT_SWOOP, urand(15000, 16000));
                            break;
                        case EVENT_WING_FLAP:
                            DoCast(me, SPELL_WING_FLAP);
                            events.ScheduleEvent(EVENT_WING_FLAP, urand(13000, 14000));
                            break;
                        case EVENT_PIERCE_ARMOR:
                            DoCastVictim(SPELL_PIERCE_ARMOR, true);
                            events.ScheduleEvent(EVENT_PIERCE_ARMOR, urand(16000, 17000));
                            break;
                        case EVENT_DISARM:
                            DoCastVictim(SPELL_DISARM, true);
                            events.ScheduleEvent(EVENT_DISARM, urand(11000, 12000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            uint8 _combatPhase;
            uint8 _summonPhase;
            uint32 _summonTimer;
            uint32 _currentPoint;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_kirtonos_the_heraldAI(creature);
        }
};

/*######
## go_brazier_of_the_herald
######*/

enum Brazier_Of_The_Herald
{
    NPC_KIRTONOS  = 10506,
};

class go_brazier_of_the_herald : public GameObjectScript
{
public:
    go_brazier_of_the_herald() : GameObjectScript("go_brazier_of_the_herald") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        go->UseDoorOrButton();
        go->PlayDirectSound(557,0);
        player->SummonCreature(NPC_KIRTONOS, 315.028f, 70.53845f, 102.1496f, 0.3859715f, TEMPSUMMON_DEAD_DESPAWN, 900000);
        return true;
    }
};

void AddSC_boss_kirtonos_the_herald()
{
    new boss_kirtonos_the_herald();
    new go_brazier_of_the_herald;
}
