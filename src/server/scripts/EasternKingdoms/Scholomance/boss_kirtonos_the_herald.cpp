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

/*
 * Timers requires to be revisited
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

enum KirtonosTexts
{
    EMOTE_SUMMONED                    = 0
};

enum KirtonosSpells
{
    SPELL_SWOOP                       = 18144,
    SPELL_WING_FLAP                   = 12882,
    SPELL_PIERCE_ARMOR                = 6016,
    SPELL_DISARM                      = 8379,
    SPELL_SHADOW_BOLT_VOLLEY          = 17228,
    SPELL_CURSE_OF_TONGUES            = 12889,
    SPELL_DOMINATE_MIND               = 14515,
    SPELL_KIRTONOS_TRANSFORM          = 16467
};

enum KirtonosEvents
{
    EVENT_SWOOP                       = 1,
    EVENT_WING_FLAP,
    EVENT_PIERCE_ARMOR,
    EVENT_DISARM,
    EVENT_SHADOW_BOLT_VOLLEY,
    EVENT_CURSE_OF_TONGUES,
    EVENT_DOMINATE_MIND,
    EVENT_KIRTONOS_TRANSFORM,

    EVENT_INTRO_1,
    EVENT_INTRO_2,
    EVENT_INTRO_3,
    EVENT_INTRO_4,
    EVENT_INTRO_5
};

enum KirtonosMisc
{
    EQUIP_ID_STAFF                    = 11365,
    POINT_LANDING                     = 13,
    POINT_STAIRS_UP                   = 0,
    POINT_STAIRS_DOWN                 = 1,
    PATH_INTRO                        = 840488,
    NPC_KIRTONOS                      = 10506,
    SOUND_SCREECH                     = 557
};

Position const SpawnPosition = { 315.0280f, 70.53845f, 102.1496f, 0.3859715f };
Position const MovePosition1 = { 299.4884f, 92.76137f, 105.6335f, 0.0f };
Position const MovePosition2 = { 314.8673f, 90.30210f, 101.6459f, 0.0f };

// 10506 - Kirtonos the Herald
struct boss_kirtonos_the_herald : public BossAI
{
    boss_kirtonos_the_herald(Creature* creature) : BossAI(creature, DATA_KIRTONOS) { }

    void JustAppeared() override
    {
        events.ScheduleEvent(EVENT_INTRO_1, 0s);
        me->SetDisableGravity(true);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        // Abilities he uses doesn't depend on form
        events.ScheduleEvent(EVENT_SWOOP, 15s, 20s);
        events.ScheduleEvent(EVENT_WING_FLAP, 10s, 20s);
        events.ScheduleEvent(EVENT_PIERCE_ARMOR, 10s, 30s);
        events.ScheduleEvent(EVENT_DISARM, 10s, 25s);
        events.ScheduleEvent(EVENT_SHADOW_BOLT_VOLLEY, 40s, 50s);
        events.ScheduleEvent(EVENT_CURSE_OF_TONGUES, 50s, 60s);
        events.ScheduleEvent(EVENT_DOMINATE_MIND, 60s);
        events.ScheduleEvent(EVENT_KIRTONOS_TRANSFORM, 18s);
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type == WAYPOINT_MOTION_TYPE && pointId == POINT_LANDING)
            events.ScheduleEvent(EVENT_INTRO_2, 0s);

        if (type == POINT_MOTION_TYPE && pointId == POINT_STAIRS_UP)
            events.ScheduleEvent(EVENT_INTRO_3, 2s);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        if (GameObject* gate = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(GO_GATE_KIRTONOS)))
            gate->SetGoState(GO_STATE_ACTIVE);

        me->DespawnOrUnsummon();
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (GameObject* gate = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(GO_GATE_KIRTONOS)))
            gate->SetGoState(GO_STATE_ACTIVE);

        _JustDied();
    }

    void UpdateIntroEvents(uint32 diff)
    {
        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_INTRO_1:
                    Talk(EMOTE_SUMMONED);
                    me->GetMotionMaster()->MovePath(PATH_INTRO, false);
                    break;
                case EVENT_INTRO_2:
                    me->GetMotionMaster()->MovePoint(POINT_STAIRS_UP, MovePosition1, true, 0.01745329f);
                    if (GameObject* gate = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(GO_GATE_KIRTONOS)))
                        gate->SetGoState(GO_STATE_READY);
                    break;
                case EVENT_INTRO_3:
                    me->SetDisableGravity(false);
                    DoCastSelf(SPELL_KIRTONOS_TRANSFORM);
                    events.ScheduleEvent(EVENT_INTRO_4, 1s);
                    break;
                case EVENT_INTRO_4:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                    SetEquipmentSlots(false, EQUIP_ID_STAFF);
                    me->SetImmuneToAll(false);
                    if (GameObject* brazier = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(GO_BRAZIER_OF_THE_HERALD)))
                        brazier->SetGoState(GO_STATE_READY);
                    events.ScheduleEvent(EVENT_INTRO_5, 5s);
                    break;
                case EVENT_INTRO_5:
                    me->SetWalk(true);
                    me->GetMotionMaster()->MovePoint(POINT_STAIRS_DOWN, MovePosition2);
                    break;
                default:
                    break;
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
        {
            UpdateIntroEvents(diff);
            return;
        }

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SWOOP:
                    DoCastSelf(SPELL_SWOOP);
                    events.Repeat(10s, 15s);
                    break;
                case EVENT_WING_FLAP:
                    DoCastSelf(SPELL_WING_FLAP);
                    events.Repeat(15s);
                    break;
                case EVENT_PIERCE_ARMOR:
                    DoCastVictim(SPELL_PIERCE_ARMOR);
                    events.Repeat(45s, 60s);
                    break;
                case EVENT_DISARM:
                    DoCastVictim(SPELL_DISARM);
                    events.Repeat(10s, 20s);
                    break;
                case EVENT_SHADOW_BOLT_VOLLEY:
                    DoCastSelf(SPELL_SHADOW_BOLT_VOLLEY);
                    events.Repeat(3s, 7s);
                    break;
                case EVENT_CURSE_OF_TONGUES:
                    DoCastSelf(SPELL_CURSE_OF_TONGUES);
                    events.Repeat(30s, 50s);
                    break;
                case EVENT_DOMINATE_MIND:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1))
                        DoCast(target, SPELL_DOMINATE_MIND);
                    events.Repeat(30s, 50s);
                    break;
                case EVENT_KIRTONOS_TRANSFORM:
                    if (me->HasAura(SPELL_KIRTONOS_TRANSFORM))
                    {
                        // This is how it works...
                        DoCastSelf(SPELL_KIRTONOS_TRANSFORM);
                        me->RemoveAura(SPELL_KIRTONOS_TRANSFORM);
                        SetEquipmentSlots(true);
                    }
                    else
                    {
                        DoCastSelf(SPELL_KIRTONOS_TRANSFORM);
                        SetEquipmentSlots(false, EQUIP_ID_STAFF);
                    }
                    events.Repeat(20s, 30s);
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

// 175564 - Brazier of the Herald
struct go_brazier_of_the_herald : public GameObjectAI
{
    go_brazier_of_the_herald(GameObject* go) : GameObjectAI(go) { }

    bool OnGossipHello(Player* player) override
    {
        me->UseDoorOrButton();
        me->PlayDirectSound(SOUND_SCREECH);
        player->SummonCreature(NPC_KIRTONOS, SpawnPosition, TEMPSUMMON_MANUAL_DESPAWN);
        return true;
    }
};

void AddSC_boss_kirtonos_the_herald()
{
    RegisterScholomanceCreatureAI(boss_kirtonos_the_herald);
    RegisterScholomanceGameObjectAI(go_brazier_of_the_herald);
}
