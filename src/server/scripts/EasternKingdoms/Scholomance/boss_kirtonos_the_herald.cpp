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
    SPELL_KIRTONOS_TRANSFORM          = 16467,
    SPELL_SHADOW_BOLT                 = 17228,
    SPELL_CURSE_OF_TONGUES            = 12889,
    SPELL_DOMINATE_MIND               = 14515
};

enum Events
{
    INTRO_1                           = 1,
    INTRO_2                           = 2,
    INTRO_3                           = 3,
    INTRO_4                           = 4,
    INTRO_5                           = 5,
    INTRO_6                           = 6,
    EVENT_SWOOP                       = 7,
    EVENT_WING_FLAP                   = 8,
    EVENT_PIERCE_ARMOR                = 9,
    EVENT_DISARM                      = 10,
    EVENT_SHADOW_BOLT                 = 11,
    EVENT_CURSE_OF_TONGUES            = 12,
    EVENT_DOMINATE_MIND               = 13,
    EVENT_KIRTONOS_TRANSFORM          = 14
};

enum eMisc
{
    WEAPON_KIRTONOS_STAFF             = 11365,
    POINT_KIRTONOS_LAND               = 13,
    KIRTONOS_PATH                     = 105061
};

Position const PosMove[2] =
{
    { 299.4884f, 92.76137f, 105.6335f },
    { 314.8673f, 90.30210f, 101.6459f }
};

class boss_kirtonos_the_herald : public CreatureScript
{
    public: boss_kirtonos_the_herald() : CreatureScript("boss_kirtonos_the_herald") { }

        struct boss_kirtonos_the_heraldAI : public BossAI
        {
            boss_kirtonos_the_heraldAI(Creature* creature) : BossAI(creature, DATA_KIRTONOS) { }

            void Reset()
            {
                _Reset();
            }

            void EnterCombat(Unit* /*who*/)
            {
                events.ScheduleEvent(EVENT_SWOOP, urand(8000, 8000));
                events.ScheduleEvent(EVENT_WING_FLAP, urand(15000, 15000));
                events.ScheduleEvent(EVENT_PIERCE_ARMOR, urand(18000, 18000));
                events.ScheduleEvent(EVENT_DISARM, urand(22000, 22000));
                events.ScheduleEvent(EVENT_SHADOW_BOLT, urand(42000, 42000));
                events.ScheduleEvent(EVENT_CURSE_OF_TONGUES, urand(53000, 53000));
                events.ScheduleEvent(EVENT_DOMINATE_MIND, urand(34000, 48000));
                events.ScheduleEvent(EVENT_KIRTONOS_TRANSFORM, urand(20000, 20000));
                _EnterCombat();
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

            void IsSummonedBy(Unit* /*summoner*/)
            {
                events.ScheduleEvent(INTRO_1, 500);
                me->SetDisableGravity(true);
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                Talk(EMOTE_SUMMONED);
            }

            void JustSummoned(Creature* summon)
            {
                BossAI::JustSummoned(summon);
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type == WAYPOINT_MOTION_TYPE && id == POINT_KIRTONOS_LAND)
                {
                    events.ScheduleEvent(INTRO_2, 1500);
                }
            }

            void UpdateAI(uint32 const diff)
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent() && !UpdateVictim())
                {
                    switch (eventId)
                    {
                        case INTRO_1:
                            me->GetMotionMaster()->MovePath(KIRTONOS_PATH, false);
                            break;
                        case INTRO_2:
                            me->GetMotionMaster()->MovePoint(0, PosMove[0]);
                            events.ScheduleEvent(INTRO_3, 1000);
                            break;
                        case INTRO_3:
                            if (GameObject* gate = me->GetMap()->GetGameObject(instance->GetData64(GO_GATE_KIRTONOS)))
                                gate->SetGoState(GO_STATE_READY);
                            me->SetFacingTo(0.01745329f);
                            events.ScheduleEvent(INTRO_4, 3000);
                            break;
                        case INTRO_4:
                            if (GameObject* brazier = me->GetMap()->GetGameObject(instance->GetData64(GO_BRAZIER_OF_THE_HERALD)))
                                brazier->SetGoState(GO_STATE_READY);
                            me->SetWalk(true);
                            me->SetDisableGravity(false);
                            DoCast(me, SPELL_KIRTONOS_TRANSFORM);
                            me->SetCanFly(false);
                            events.ScheduleEvent(INTRO_5, 1000);
                            break;
                        case INTRO_5:
                            me->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                            me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, uint32(WEAPON_KIRTONOS_STAFF));
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                            me->SetReactState(REACT_AGGRESSIVE);
                            events.ScheduleEvent(INTRO_6, 5000);
                            break;
                        case INTRO_6:
                            me->GetMotionMaster()->MovePoint(0, PosMove[1]);
                            break;
                        default:
                            break;
                    }
                }

                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SWOOP:
                            DoCast(me, SPELL_SWOOP);
                            events.ScheduleEvent(EVENT_SWOOP, 15000);
                            break;
                        case EVENT_WING_FLAP:
                            DoCast(me, SPELL_WING_FLAP);
                            events.ScheduleEvent(EVENT_WING_FLAP, 13000);
                            break;
                        case EVENT_PIERCE_ARMOR:
                            DoCastVictim(SPELL_PIERCE_ARMOR, true);
                            events.ScheduleEvent(EVENT_PIERCE_ARMOR, 12000);
                            break;
                        case EVENT_DISARM:
                            DoCastVictim(SPELL_DISARM, true);
                            events.ScheduleEvent(EVENT_DISARM, 11000);
                            break;
                        case EVENT_SHADOW_BOLT:
                            DoCastVictim(SPELL_SHADOW_BOLT, true);
                            events.ScheduleEvent(EVENT_SHADOW_BOLT, 42000);
                            break;
                        case EVENT_CURSE_OF_TONGUES:
                            DoCastVictim(SPELL_CURSE_OF_TONGUES, true);
                            events.ScheduleEvent(EVENT_CURSE_OF_TONGUES, 35000);
                            break;
                        case EVENT_DOMINATE_MIND:
                            DoCastVictim(SPELL_DOMINATE_MIND, true);
                            events.ScheduleEvent(EVENT_DOMINATE_MIND, urand(44000, 48000));
                            break;
                        case EVENT_KIRTONOS_TRANSFORM:
                            if (me->HasAura(SPELL_KIRTONOS_TRANSFORM))
                            {
                                me->RemoveAura(SPELL_KIRTONOS_TRANSFORM);
                                me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, uint32(0));
                                me->SetCanFly(false);
                            }
                            else
                            {
                                DoCast(me, SPELL_KIRTONOS_TRANSFORM);
                                me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, uint32(WEAPON_KIRTONOS_STAFF));
                                me->SetCanFly(true);
                            }
                            events.ScheduleEvent(EVENT_KIRTONOS_TRANSFORM, urand(16000, 18000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
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
    SOUND_SCREECH = 557
};

Position const PosSummon[1] =
{
    { 315.028f, 70.53845f, 102.1496f, 0.3859715f }
};

class go_brazier_of_the_herald : public GameObjectScript
{
    public:
        go_brazier_of_the_herald() : GameObjectScript("go_brazier_of_the_herald") { }

        bool OnGossipHello(Player* player, GameObject* go)
        {
            go->UseDoorOrButton();
            go->PlayDirectSound(SOUND_SCREECH, 0);
            player->SummonCreature(NPC_KIRTONOS, PosSummon[0], TEMPSUMMON_DEAD_DESPAWN, 900000);
            return true;
        }
};

void AddSC_boss_kirtonos_the_herald()
{
    new boss_kirtonos_the_herald();
    new go_brazier_of_the_herald;
}
