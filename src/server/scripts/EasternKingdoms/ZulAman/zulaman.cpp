/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "CreatureTextMgr.h"
#include "ScriptedEscortAI.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellScript.h"
#include "zulaman.h"

enum VoljinTexts
{
    // Vol'jin
    SAY_INTRO_1         = 0,
    SAY_INTRO_2         = 1,
    SAY_INTRO_3         = 2,
    SAY_INTRO_4         = 3,
    SAY_FAIL_GONG_EVENT = 4,

    // Hex Lord Malacrass
    SAY_HEXLOR_INTRO    = 0
};

enum VoljinSpells
{
    // Vol'jin
    SPELL_BANGING_THE_GONG  = 45225
};

enum VoljinEvents
{
    EVENT_DISMOUNT_VOLJIN = 1,
    EVENT_REMOVE_GOSSIP_FLAG,
    EVENT_SAY_FOLLOW_ME,
    EVENT_MOVE_TO_GONG_1,
    EVENT_MOVE_TO_GONG_2,
    EVENT_FACE_TO_GONG,
    EVENT_SAY_GONG_INSTRUCTIONS,
    EVENT_BANGING_THE_GONG,
    EVENT_MAKE_GONG_SELECTABLE,
    EVENT_FAIL_GONG_EVENT,
    EVENT_MOVE_TO_ROOM_CENTER,
    EVENT_MOVE_HOME,
    EVENT_FACE_HOME,
    EVENT_RESET_NPC_FLAGS,
    EVENT_MOVE_TO_CENTER,
    EVENT_MAKE_GONG_UNSELECTABLE,
    EVENT_TALK_TO_AMANI,
    EVENT_OPEN_MASSIVE_GATE,
    EVENT_TALK_WARN_PLAYERS,
    EVENT_START_SPEED_RUN
};

enum VoljinMovePoints
{
    POINT_HOME          = 1,
    POINT_INTRO_1       = 2,
    POINT_INTRO_2       = 3,
    POINT_INTRO_3       = 4
};

enum VoljinMisc
{
    ITEM_DISPLAY_ID_MACE    = 5301,
    MOUNT_DISPLAY_ID_RAPTOR = 29261
};

Position const VoljinIntroWaypoint[4] =
{
    { 117.7349f, 1662.77f,  42.02156f, 0.0f },
    { 132.14f,   1645.143f, 42.02158f, 0.0f },
    { 121.8901f, 1639.118f, 42.23253f, 0.0f },
    { 122.618f,  1639.546f, 42.11659f, 0.0f }
};

Position const VoljinIntroPosition1 = { 117.7349f, 1662.77f,  42.02156f };
Position const VoljinIntroPosition2 = { 132.14f,   1645.143f, 42.02158f };
Position const VoljinIntroPosition3 = { 122.6202f, 1639.547f, 42.16251f };
Position const VoljinHomePosition   = { 121.0399f, 1672.196f, 42.02157f };

struct npc_zulaman_voljin : public ScriptedAI
{
    npc_zulaman_voljin(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript())
    {
        Initialize();
    }

    void Initialize()
    {
        _restarted = false;
        _started = false;
        _actionTriggered = false;
        me->SetDisplayId(me->GetCreatureTemplate()->Modelid1);

        if (_instance->GetData(DATA_ZULAMAN_SPEEDRUN_STATE) != NOT_STARTED)
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
    }

    bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
    {
        if (_started)
            return true;

        _playerGUID = player->GetGUID();

        me->SetWalk(true);

        if (!_restarted)
        {
            _events.ScheduleEvent(EVENT_DISMOUNT_VOLJIN, 1s);
            _events.ScheduleEvent(EVENT_REMOVE_GOSSIP_FLAG, 3s);
            _events.ScheduleEvent(EVENT_SAY_FOLLOW_ME, 4s);

        }
        else
        {
            _events.ScheduleEvent(EVENT_REMOVE_GOSSIP_FLAG, 1s + 400ms);
            _events.ScheduleEvent(EVENT_SAY_FOLLOW_ME, 2s + 400ms);
        }

        player->PlayerTalkClass->SendCloseGossip();
        _started = true;

        return true;
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_OPEN_MASSIVE_GATES:
                if (!_actionTriggered)
                {
                    _events.CancelEvent(EVENT_FAIL_GONG_EVENT);
                    _events.ScheduleEvent(EVENT_MOVE_TO_CENTER, 1s);
                    _actionTriggered = true;
                }
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
                case EVENT_DISMOUNT_VOLJIN:
                    me->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, 0);
                    break;
                case EVENT_REMOVE_GOSSIP_FLAG:
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    break;
                case EVENT_SAY_FOLLOW_ME:
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                        Talk(SAY_INTRO_1, player);
                    _events.ScheduleEvent(EVENT_MOVE_TO_GONG_1, 1s);
                    break;
                case EVENT_MOVE_TO_GONG_1:
                    me->GetMotionMaster()->MovePoint(POINT_INTRO_1, VoljinIntroPosition1);
                    break;
                case EVENT_MOVE_TO_GONG_2:
                    me->GetMotionMaster()->MovePoint(POINT_INTRO_2, VoljinIntroPosition2);
                    break;
                case EVENT_FACE_TO_GONG:
                    if (GameObject* gong = _instance->GetGameObject(DATA_STRANGE_GONG))
                        me->SetFacingToObject(gong);
                    _events.ScheduleEvent(EVENT_SAY_GONG_INSTRUCTIONS, 1s + 400ms);
                    break;
                case EVENT_SAY_GONG_INSTRUCTIONS:
                    Talk(SAY_INTRO_2);
                    _events.ScheduleEvent(EVENT_BANGING_THE_GONG, 2s + 100ms);
                    break;
                case EVENT_BANGING_THE_GONG:
                    DoCastSelf(SPELL_BANGING_THE_GONG);
                    me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, ITEM_DISPLAY_ID_MACE);
                    _events.ScheduleEvent(EVENT_MAKE_GONG_SELECTABLE, 400ms);
                    _events.ScheduleEvent(EVENT_FAIL_GONG_EVENT, 1min + 3s);
                    break;
                case EVENT_MAKE_GONG_SELECTABLE:
                    if (GameObject* gong = _instance->GetGameObject(DATA_STRANGE_GONG))
                        gong->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                    break;
                case EVENT_FAIL_GONG_EVENT:
                    if (GameObject* gong = _instance->GetGameObject(DATA_STRANGE_GONG))
                        gong->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);

                    me->RemoveAurasDueToSpell(SPELL_BANGING_THE_GONG);
                    me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, 0);
                    Talk(SAY_FAIL_GONG_EVENT);
                    _events.ScheduleEvent(EVENT_MOVE_HOME, 2s + 200ms);
                    break;
                case EVENT_MOVE_HOME:
                    me->GetMotionMaster()->MovePoint(POINT_HOME, VoljinHomePosition);
                    break;
                case EVENT_FACE_HOME:
                    me->SetFacingTo(4.782202f);
                    if (!_actionTriggered)
                    {
                        _started = false;
                        _restarted = true;
                        _events.ScheduleEvent(EVENT_RESET_NPC_FLAGS, 400ms);
                    }
                    else
                        me->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, MOUNT_DISPLAY_ID_RAPTOR);
                    break;
                case EVENT_RESET_NPC_FLAGS:
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER);
                    break;
                case EVENT_MOVE_TO_CENTER:
                    _instance->SetData(DATA_TRIGGER_AMANISHI_GUARDIANS, IN_PROGRESS);
                    me->RemoveAurasDueToSpell(SPELL_BANGING_THE_GONG);
                    me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, 0);
                    me->GetMotionMaster()->MovePoint(POINT_INTRO_3, VoljinIntroPosition3);
                    _events.ScheduleEvent(EVENT_MAKE_GONG_UNSELECTABLE, 400ms);
                    break;
                case EVENT_MAKE_GONG_UNSELECTABLE:
                    if (GameObject* gong = _instance->GetGameObject(DATA_STRANGE_GONG))
                        gong->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                    break;
                case EVENT_TALK_TO_AMANI:
                    me->SetFacingTo(4.747295f);
                    Talk(SAY_INTRO_3);
                    _events.ScheduleEvent(EVENT_OPEN_MASSIVE_GATE, 5s + 400ms);
                    _events.ScheduleEvent(EVENT_TALK_WARN_PLAYERS, 9s);
                    break;
                case EVENT_OPEN_MASSIVE_GATE:
                    if (GameObject* gate = _instance->GetGameObject(DATA_MASSIVE_GATE))
                        gate->SetGoState(GO_STATE_ACTIVE);
                    break;
                case EVENT_TALK_WARN_PLAYERS:
                    Talk(SAY_INTRO_4);
                    _events.ScheduleEvent(EVENT_MOVE_HOME, 4s + 500ms);
                    _events.ScheduleEvent(EVENT_START_SPEED_RUN, 12s);
                    break;
                case EVENT_START_SPEED_RUN:
                    _instance->SetData(DATA_ZULAMAN_SPEEDRUN_STATE, IN_PROGRESS);
                    break;
                default:
                    break;
            }
        }
    }

    void MovementInform(uint32 movementType, uint32 pointId) override
    {
        if (movementType != POINT_MOTION_TYPE)
            return;

        switch (pointId)
        {
            case POINT_HOME:
                _events.ScheduleEvent(EVENT_FACE_HOME, 1ms);
                break;
            case POINT_INTRO_1:
                _events.ScheduleEvent(EVENT_MOVE_TO_GONG_2, 1ms);
                break;
            case POINT_INTRO_2:
                _events.ScheduleEvent(EVENT_FACE_TO_GONG, 800ms);
                break;
            case POINT_INTRO_3:
                _events.ScheduleEvent(EVENT_TALK_TO_AMANI, 1ms);
                break;
            default:
                break;
        }
    }

private:
    InstanceScript* _instance;
    EventMap _events;
    ObjectGuid _playerGUID;
    bool _restarted;
    bool _started;
    bool _actionTriggered;
};

Position const AmanishiGuardianPos1 = { 107.7912f, 1586.498f, 43.58794f };
Position const AmanishiGuardianPos2 = { 131.8407f, 1590.247f, 43.61382f };

enum AmanishiGuardianTexts
{
    SAY_ALERT   = 0,
    SAY_ENRAGE  = 1
};

enum AmanishiGuardianEvents
{
    EVENT_MOVE_TO_GATE = 1,
    EVENT_FACE_TO_ENTRANCE,
    EVENT_SAY_ALERT,
    EVENT_MAKE_ATTACKABLE,
    EVENT_REND
};

enum AmanishiGuardianMovePoints
{
    POINT_MASSIVE_GATE = 1
};

enum AmanishiGuardianSpells
{
    SPELL_REND      = 43246,
    SPELL_ENRAGE    = 8599
};

enum AmanishiGuardianMisc
{
    ITEM_DISPLAY_ID_SPEAR = 13631
};

struct npc_zulaman_amanishi_guardian : public ScriptedAI
{
    npc_zulaman_amanishi_guardian(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        _enraged = false;
        _firstGuardian = me->GetHomePosition().GetExactDist2d(AmanishiGuardianPos1) < 10.0f;
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_REND, 5s, 7s);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        me->GetMotionMaster()->MoveTargetedHome();
        _EnterEvadeMode();
        _events.Reset();
        Initialize();
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_ALERT_AMANISHI_GUARDIANS:
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                if (_firstGuardian)
                    _events.ScheduleEvent(EVENT_MOVE_TO_GATE, 19s + 200ms);
                else
                {
                    me->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, ITEM_DISPLAY_ID_SPEAR);
                    _events.ScheduleEvent(EVENT_MOVE_TO_GATE, 16s + 500ms);
                }
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && me->IsInCombat())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_MOVE_TO_GATE:
                    if (_firstGuardian)
                        me->GetMotionMaster()->MovePoint(POINT_MASSIVE_GATE, AmanishiGuardianPos1);
                    else
                        me->GetMotionMaster()->MovePoint(POINT_MASSIVE_GATE, AmanishiGuardianPos2);
                    break;
                case EVENT_MAKE_ATTACKABLE:
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                    break;
                case EVENT_FACE_TO_ENTRANCE:
                    if (_firstGuardian)
                        me->SetFacingTo(1.047198f);
                    else
                    {
                        me->SetFacingTo(2.024582f);
                        _events.ScheduleEvent(EVENT_SAY_ALERT, 1s + 400ms);
                    }
                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY1H);
                    break;
                case EVENT_SAY_ALERT:
                    Talk(SAY_ALERT);
                    break;
                case EVENT_REND:
                    DoCastVictim(SPELL_REND);
                    _events.Repeat(5s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

    void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
    {
        if (me->HealthBelowPct(50) && !_enraged)
        {
            DoCastSelf(SPELL_ENRAGE);
            Talk(SAY_ENRAGE);
            _enraged = true;
        }
    }

    void MovementInform(uint32 movementType, uint32 pointId) override
    {
        if (movementType != POINT_MOTION_TYPE)
            return;

        switch (pointId)
        {
            case POINT_MASSIVE_GATE:
                if (_firstGuardian)
                {
                    _events.ScheduleEvent(EVENT_FACE_TO_ENTRANCE, 1ms);
                    _events.ScheduleEvent(EVENT_MAKE_ATTACKABLE, 1ms);
                }
                else
                {
                    _events.ScheduleEvent(EVENT_FACE_TO_ENTRANCE, 1ms);
                    _events.ScheduleEvent(EVENT_MAKE_ATTACKABLE, 4s + 800ms);
                }
                break;
            default:
                break;
        }
    }

private:
    EventMap _events;
    bool _enraged;
    bool _firstGuardian;
};

// 45226 - Banging the Gong
class spell_banging_the_gong : public SpellScript
{
    PrepareSpellScript(spell_banging_the_gong);

    void Activate(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        GetHitGObj()->SendCustomAnim(0);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_banging_the_gong::Activate, EFFECT_1, SPELL_EFFECT_ACTIVATE_OBJECT);
    }
};

void AddSC_zulaman()
{
    RegisterZulAamanCreatureAI(npc_zulaman_voljin);
    RegisterZulAamanCreatureAI(npc_zulaman_amanishi_guardian);
    RegisterSpellScript(spell_banging_the_gong);
}
