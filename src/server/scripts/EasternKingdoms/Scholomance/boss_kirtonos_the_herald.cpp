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
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "MoveSplineInit.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "scholomance.h"
#include "ScriptedCreature.h"

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

enum Misc
{
    WEAPON_KIRTONOS_STAFF             = 11365,
    POINT_KIRTONOS_LAND               = 13,
    KIRTONOS_PATH                     = 105061
};

Position const PosMove[2] =
{
    { 299.4884f, 92.76137f, 105.6335f, 0.0f },
    { 314.8673f, 90.30210f, 101.6459f, 0.0f }
};

class boss_kirtonos_the_herald : public CreatureScript
{
    public: boss_kirtonos_the_herald() : CreatureScript("boss_kirtonos_the_herald") { }

        struct boss_kirtonos_the_heraldAI : public BossAI
        {
            boss_kirtonos_the_heraldAI(Creature* creature) : BossAI(creature, DATA_KIRTONOS) { }

            void Reset() override
            {
                _Reset();
            }

            void JustEngagedWith(Unit* who) override
            {
                events.ScheduleEvent(EVENT_SWOOP, 8s, 8s);
                events.ScheduleEvent(EVENT_WING_FLAP, 15s, 15s);
                events.ScheduleEvent(EVENT_PIERCE_ARMOR, 18s, 18s);
                events.ScheduleEvent(EVENT_DISARM, 22s, 22s);
                events.ScheduleEvent(EVENT_SHADOW_BOLT, 42s, 42s);
                events.ScheduleEvent(EVENT_CURSE_OF_TONGUES, 53s, 53s);
                events.ScheduleEvent(EVENT_DOMINATE_MIND, 34s, 48s);
                events.ScheduleEvent(EVENT_KIRTONOS_TRANSFORM, 20s, 20s);
                BossAI::JustEngagedWith(who);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (GameObject* gate = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(GO_GATE_KIRTONOS)))
                    gate->SetGoState(GO_STATE_ACTIVE);
                if (GameObject* brazier = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(GO_BRAZIER_OF_THE_HERALD)))
                {
                    brazier->ResetDoorOrButton();
                    brazier->SetGoState(GO_STATE_READY);
                }
                _JustDied();
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                if (GameObject* gate = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(GO_GATE_KIRTONOS)))
                    gate->SetGoState(GO_STATE_ACTIVE);
                if (GameObject* brazier = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(GO_BRAZIER_OF_THE_HERALD)))
                {
                    brazier->ResetDoorOrButton();
                    brazier->SetGoState(GO_STATE_READY);
                }
                me->DespawnOrUnsummon(5s);
            }

            void IsSummonedBy(WorldObject* /*summoner*/) override
            {
                events.ScheduleEvent(INTRO_1, 500ms);
                me->SetDisableGravity(true);
                me->SetReactState(REACT_PASSIVE);
                me->SetUnitFlag(UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_UNINTERACTIBLE);
                Talk(EMOTE_SUMMONED);
            }

            void JustSummoned(Creature* summon) override
            {
                BossAI::JustSummoned(summon);
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type == WAYPOINT_MOTION_TYPE && id == POINT_KIRTONOS_LAND)
                    events.ScheduleEvent(INTRO_2, 1500ms);
            }

            void UpdateAI(uint32 diff) override
            {
                events.Update(diff);

                if (!UpdateVictim())
                {
                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case INTRO_1:
                                me->GetMotionMaster()->MovePath(KIRTONOS_PATH, false);
                                break;
                            case INTRO_2:
                                me->GetMotionMaster()->MovePoint(0, PosMove[0]);
                                events.ScheduleEvent(INTRO_3, 1s);
                                break;
                            case INTRO_3:
                                if (GameObject* gate = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(GO_GATE_KIRTONOS)))
                                    gate->SetGoState(GO_STATE_READY);
                                me->SetFacingTo(0.01745329f);
                                events.ScheduleEvent(INTRO_4, 3s);
                                break;
                            case INTRO_4:
                                if (GameObject* brazier = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(GO_BRAZIER_OF_THE_HERALD)))
                                    brazier->SetGoState(GO_STATE_READY);
                                me->SetWalk(true);
                                me->SetDisableGravity(false);
                                DoCast(me, SPELL_KIRTONOS_TRANSFORM);
                                me->SetCanFly(false);
                                events.ScheduleEvent(INTRO_5, 1s);
                                break;
                            case INTRO_5:
                                me->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                                me->SetVirtualItem(0, uint32(WEAPON_KIRTONOS_STAFF));
                                me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_UNINTERACTIBLE);
                                me->SetReactState(REACT_AGGRESSIVE);
                                events.ScheduleEvent(INTRO_6, 5s);
                                break;
                            case INTRO_6:
                                me->GetMotionMaster()->MovePoint(0, PosMove[1]);
                                break;
                            default:
                                break;
                        }
                    }

                    return;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SWOOP:
                            DoCast(me, SPELL_SWOOP);
                            events.ScheduleEvent(EVENT_SWOOP, 15s);
                            break;
                        case EVENT_WING_FLAP:
                            DoCast(me, SPELL_WING_FLAP);
                            events.ScheduleEvent(EVENT_WING_FLAP, 13s);
                            break;
                        case EVENT_PIERCE_ARMOR:
                            DoCastVictim(SPELL_PIERCE_ARMOR, true);
                            events.ScheduleEvent(EVENT_PIERCE_ARMOR, 12s);
                            break;
                        case EVENT_DISARM:
                            DoCastVictim(SPELL_DISARM, true);
                            events.ScheduleEvent(EVENT_DISARM, 11s);
                            break;
                        case EVENT_SHADOW_BOLT:
                            DoCastVictim(SPELL_SHADOW_BOLT, true);
                            events.ScheduleEvent(EVENT_SHADOW_BOLT, 42s);
                            break;
                        case EVENT_CURSE_OF_TONGUES:
                            DoCastVictim(SPELL_CURSE_OF_TONGUES, true);
                            events.ScheduleEvent(EVENT_CURSE_OF_TONGUES, 35s);
                            break;
                        case EVENT_DOMINATE_MIND:
                            DoCastVictim(SPELL_DOMINATE_MIND, true);
                            events.ScheduleEvent(EVENT_DOMINATE_MIND, 44s, 48s);
                            break;
                        case EVENT_KIRTONOS_TRANSFORM:
                            if (me->HasAura(SPELL_KIRTONOS_TRANSFORM))
                            {
                                me->RemoveAura(SPELL_KIRTONOS_TRANSFORM);
                                me->SetVirtualItem(0, uint32(0));
                                me->SetCanFly(false);
                            }
                            else
                            {
                                DoCast(me, SPELL_KIRTONOS_TRANSFORM);
                                me->SetVirtualItem(0, uint32(WEAPON_KIRTONOS_STAFF));
                                me->SetCanFly(true);
                            }
                            events.ScheduleEvent(EVENT_KIRTONOS_TRANSFORM, 16s, 18s);
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetScholomanceAI<boss_kirtonos_the_heraldAI>(creature);
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

        struct go_brazier_of_the_heraldAI : public GameObjectAI
        {
            go_brazier_of_the_heraldAI(GameObject* go) : GameObjectAI(go) { }

            bool OnGossipHello(Player* player) override
            {
                me->UseDoorOrButton();
                me->PlayDirectSound(SOUND_SCREECH, 0);
                player->SummonCreature(NPC_KIRTONOS, PosSummon[0], TEMPSUMMON_DEAD_DESPAWN, 15min);
                return true;
            }
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return GetScholomanceAI<go_brazier_of_the_heraldAI>(go);
        }
};

void AddSC_boss_kirtonos_the_herald()
{
    new boss_kirtonos_the_herald();
    new go_brazier_of_the_herald;
}
