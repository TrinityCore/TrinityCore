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
#include "CreatureGroups.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "GridNotifiers.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "Transport.h"
#include "halls_of_origination.h"

enum SunTouchedServant
{
    // Texts
    SAY_EMOTE_DISPERSE         = 0,

    // Spells
    SPELL_SEARING_FLAMES        = 74101,
    SPELL_DISPERSE_SERVANT      = 88097,
    SPELL_DISPERSE_SPRITE       = 88100,
    SPELL_FLAME_DISPERSION      = 76160,
    SPELL_PYROGENICS_SPRITE     = 76158,
    SPELL_PYROGENICS_SPRITELING = 76159,

    // Events
    EVENT_SEARING_FLAMES        = 1
};

struct npc_sun_touched_servant : public ScriptedAI
{
    npc_sun_touched_servant(Creature* creature) : ScriptedAI(creature), _dispersed(false) { }

    void JustAppeared() override
    {
        if (me->GetEntry() == NPC_SUN_TOUCHED_SERVANT)
            return;

        DoCastSelf(me->GetEntry() == NPC_SUN_TOUCHED_SPRITE ? SPELL_PYROGENICS_SPRITE : SPELL_PYROGENICS_SPRITELING);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_SEARING_FLAMES, 5s, 7s);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        ScriptedAI::EnterEvadeMode(why);
        _events.Reset();
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->GetEntry() == NPC_SUN_TOUCHED_SPRITELING)
            return;

        if (!_dispersed && me->HealthBelowPctDamaged(1, damage))
        {
            _dispersed = true;
            DoCastSelf(me->GetEntry() == NPC_SUN_TOUCHED_SERVANT ? SPELL_DISPERSE_SERVANT : SPELL_DISPERSE_SPRITE);
            Talk(SAY_EMOTE_DISPERSE);
        }

        if (damage >= me->GetHealth())
            damage = me->GetHealth() - 1;
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SEARING_FLAMES:
                    DoCastVictim(SPELL_SEARING_FLAMES);
                    _events.Repeat(8s, 14s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    bool _dispersed;
};

enum AggroStalker
{
    // Spells
    SPELL_SUBMERGE  = 76084,
    SPELL_EMERGE    = 75764
};

struct npc_hoo_aggro_stalker_base : public ScriptedAI
{
    npc_hoo_aggro_stalker_base(Creature* creature, uint8 summonGroupId) : ScriptedAI(creature), _summonGroupId(summonGroupId) { }

    void InitializeAI() override
    {
        // Trigger creatures are passive by default but we need an aggressive one here.
        me->SetReactState(REACT_AGGRESSIVE);
    }

    void JustAppeared() override
    {
        me->SummonCreatureGroup(_summonGroupId);
    }

    void AttackStart(Unit* /*who*/) override {  }

    void JustEngagedWith(Unit* who) override
    {
        for (ObjectGuid const& guid : _summonGUIDs)
        {
            if (Creature* summon = ObjectAccessor::GetCreature(*me, guid))
            {
                summon->EngageWithTarget(who);
                if (summon->HasAura(SPELL_SUBMERGE))
                {
                    summon->RemoveAurasDueToSpell(SPELL_SUBMERGE);
                    summon->CastSpell(summon, SPELL_EMERGE);
                }
            }
        }
    }

    void JustSummoned(Creature* summon) override
    {
        _summonGUIDs.insert(summon->GetGUID());
        summon->CastSpell(summon, SPELL_SUBMERGE, true); // The spell has a cast time but we need them submerged immediately
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        _summonGUIDs.erase(summon->GetGUID());

        // Group has been defeated, despawn aggro stalker.
        if (_summonGUIDs.empty())
            me->DespawnOrUnsummon();
    }

private:
    uint8 _summonGroupId;
    GuidSet _summonGUIDs;
};

struct npc_hoo_aggro_stalker_1 : public npc_hoo_aggro_stalker_base { npc_hoo_aggro_stalker_1(Creature* creature) : npc_hoo_aggro_stalker_base(creature, 0) { } };
struct npc_hoo_aggro_stalker_2 : public npc_hoo_aggro_stalker_base { npc_hoo_aggro_stalker_2(Creature* creature) : npc_hoo_aggro_stalker_base(creature, 1) { } };
struct npc_hoo_aggro_stalker_3 : public npc_hoo_aggro_stalker_base { npc_hoo_aggro_stalker_3(Creature* creature) : npc_hoo_aggro_stalker_base(creature, 2) { } };

enum BrannBronzebeard
{
    // Spells
    SPELL_KILL_CREDIT               = 92439,

    // Gossip Menu
    GOSSIP_MENU_NO_TIME_TO_WASTE    = 11339,
    GOSSIP_MENU_DESTROY_ELEMENTAL   = 11348,
    GOSSIP_MENU_OCH_ITS_NOT_EASY    = 12512,
    GOSSIP_OPTION_WE_ARE_READY      = 0,

    // Texts
    SAY_DOOR_INTRO                  = 0,
    SAY_INTRO_1                     = 1,
    SAY_INTRO_2                     = 2,
    SAY_INTRO_3                     = 3,
    SAY_INTRO_4                     = 4,
    SAY_INTRO_5                     = 5,
    SAY_INTRO_6                     = 6,
    SAY_INTRO_7                     = 7,
    SAY_WARDEN_DIED_1               = 8,
    SAY_WARDEN_DIED_2               = 9,
    SAY_WARDEN_DIED_3               = 10,
    SAY_ANRAPHET_INTRO              = 11,
    SAY_OUTRO_1                     = 12,
    SAY_OUTRO_2                     = 13,

    // Events
    EVENT_ENABLE_AREA_TRIGGER_TALK  = 1,
    EVENT_INTRO_1,
    EVENT_USE_STANDING_EMOTE,
    EVENT_INTRO_2,
    EVENT_WALK_INTO_VAULT,
    EVENT_INTRO_3,
    EVENT_EXCLAMATION_EMOTE,
    EVENT_INTRO_4,
    EVENT_INTRO_5,
    EVENT_TURN_LEFT,
    EVENT_INTRO_6,
    EVENT_INTRO_7,
    EVENT_POINT_EMOTE,
    EVENT_ADD_GOSSIP_FLAG,
    EVENT_ANRAPHET_INTRO,
    EVENT_OUTRO_1,
    EVENT_OUTRO_2,
    EVENT_FINISH_OUTRO,

    // Actions
    ACTION_INTRO_AREA_TRIGGER       = 0,

    // Move Points
    POINT_VAULT_OF_LIGHTS_INTRO     = 0,
    POINT_VAULT_OF_LIGHTS_OUTRO_1   = 12,
    POINT_VAULT_OF_LIGHTS_OUTRO_2   = 14

};

Position const BrannVaultOfLightIntroPos = { -429.583f,  367.019f,   89.792816f };
Position const BrannVaultOfLightOutroPos = { -71.58507f, 367.02777f, 89.77716f  };

struct npc_hoo_brann_bronzebeard : public CreatureAI
{
    npc_hoo_brann_bronzebeard(Creature* creature) : CreatureAI(creature), _allowAreaTriggerText(true), _deadWarden(0), _instance(nullptr) { }

    void InitializeAI() override
    {
        _instance = me->GetInstanceScript();
    }

    bool GossipHello(Player* player) override
    {
        uint32 gossipMenuId = GOSSIP_MENU_NO_TIME_TO_WASTE;

        if (_instance->GetData(DATA_VAULT_OF_LIGHTS) == NOT_STARTED)
            AddGossipItemFor(player, gossipMenuId, GOSSIP_OPTION_WE_ARE_READY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
        else if (_instance->GetData(DATA_VAULT_OF_LIGHTS) != DONE)
            gossipMenuId = GOSSIP_MENU_DESTROY_ELEMENTAL;
        else
            gossipMenuId = GOSSIP_MENU_OCH_ITS_NOT_EASY;

        SendGossipMenuFor(player, player->GetGossipTextId(gossipMenuId, me), me->GetGUID());
        return true;
    }

    bool GossipSelect(Player* /*player*/, uint32 /*menuId*/, uint32 /*gossipListId*/) override
    {
        if (_instance->GetData(DATA_VAULT_OF_LIGHTS) != NOT_STARTED || !me->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP))
            return false;

        me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER);
        me->setActive(true);
        _allowAreaTriggerText = false;
        _events.CancelEvent(EVENT_ENABLE_AREA_TRIGGER_TALK);
        _events.ScheduleEvent(EVENT_INTRO_1, 2s);

        return true;
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_INTRO_AREA_TRIGGER:
                if (_allowAreaTriggerText && _instance->GetData(DATA_VAULT_OF_LIGHTS) == NOT_STARTED)
                {
                    _allowAreaTriggerText = false;
                    Talk(SAY_DOOR_INTRO);
                    _events.ScheduleEvent(EVENT_ENABLE_AREA_TRIGGER_TALK, 45s);
                }
                break;
            case ACTION_ANRAPHET_DIED:
                me->setActive(true);
                me->RemoveFlag(UNIT_NPC_FLAGS,  UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER);
                _events.ScheduleEvent(EVENT_OUTRO_1, 5s);
                break;
            default:
                break;
        }
    }

    void SetData(uint32 type, uint32 /*value*/) override
    {
        switch (type)
        {
            case DATA_WARDEN_1_DIED:
            case DATA_WARDEN_2_DIED:
            case DATA_WARDEN_3_DIED:
            case DATA_WARDEN_4_DIED:
                if (_deadWarden < 3)
                    Talk(SAY_WARDEN_DIED_1 + _deadWarden);
                else
                {
                    _instance->SetData(DATA_VAULT_OF_LIGHTS, DONE);
                    _events.ScheduleEvent(EVENT_ANRAPHET_INTRO, 13s);
                }
                ++_deadWarden;
                break;
            default:
                break;
        }
    }

    void MovementInform(uint32 motionType, uint32 pointId) override
    {
        if (motionType == POINT_MOTION_TYPE && pointId ==  POINT_VAULT_OF_LIGHTS_INTRO)
            _events.ScheduleEvent(EVENT_INTRO_3, 500ms);
        else if (motionType == WAYPOINT_MOTION_TYPE)
        {
            if (pointId == POINT_VAULT_OF_LIGHTS_OUTRO_1)
                _events.ScheduleEvent(EVENT_OUTRO_2, 1s);
            else if (pointId == POINT_VAULT_OF_LIGHTS_OUTRO_2)
            {
                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_USE_STANDING);
                _events.ScheduleEvent(EVENT_FINISH_OUTRO, 6s);
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ENABLE_AREA_TRIGGER_TALK:
                    _allowAreaTriggerText = true;
                    break;
                case EVENT_INTRO_1:
                    Talk(SAY_INTRO_1);
                    _events.ScheduleEvent(EVENT_USE_STANDING_EMOTE, 4s);
                    _events.ScheduleEvent(EVENT_INTRO_2, 7s + 400ms);
                    break;
                case EVENT_USE_STANDING_EMOTE:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_USE_STANDING);
                    break;
                case EVENT_INTRO_2:
                    Talk(SAY_INTRO_2);
                    _instance->SetData(DATA_VAULT_OF_LIGHTS, IN_PROGRESS);
                    _events.ScheduleEvent(EVENT_WALK_INTO_VAULT, 3s + 600ms);
                    break;
                case EVENT_WALK_INTO_VAULT:
                    me->GetMotionMaster()->MovePoint(POINT_VAULT_OF_LIGHTS_INTRO, BrannVaultOfLightIntroPos, true, 2.5f);
                    break;
                case EVENT_INTRO_3:
                    Talk(SAY_INTRO_3);
                    _events.ScheduleEvent(EVENT_EXCLAMATION_EMOTE, 10s);
                    _events.ScheduleEvent(EVENT_INTRO_4, 15s);
                    break;
                case EVENT_EXCLAMATION_EMOTE:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                    break;
                case EVENT_INTRO_4:
                    Talk(SAY_INTRO_4);
                    _events.ScheduleEvent(EVENT_INTRO_5, 6s);
                    break;
                case EVENT_INTRO_5:
                    Talk(SAY_INTRO_5);
                    me->SetFacingTo(5.445427417755126953f);
                    _events.ScheduleEvent(EVENT_TURN_LEFT, 1s + 200ms);
                    break;
                case EVENT_TURN_LEFT:
                    me->SetFacingTo(0.628318548202514648f);
                    _events.ScheduleEvent(EVENT_INTRO_6, 2s + 200ms);
                    break;
                case EVENT_INTRO_6:
                    me->SetFacingTo(0.01745329238474369f);
                    Talk(SAY_INTRO_6);
                    _events.ScheduleEvent(EVENT_INTRO_7, 4s);
                    break;
                case EVENT_INTRO_7:
                    Talk(SAY_INTRO_7);
                    _events.ScheduleEvent(EVENT_POINT_EMOTE, 12s);
                    break;
                case EVENT_POINT_EMOTE:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_POINT);
                    _events.ScheduleEvent(EVENT_ADD_GOSSIP_FLAG, 4s);
                    break;
                case EVENT_ADD_GOSSIP_FLAG:
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER);
                    me->setActive(false);
                    break;
                case EVENT_ANRAPHET_INTRO:
                    Talk(SAY_ANRAPHET_INTRO);
                    break;
                case EVENT_OUTRO_1:
                    Talk(SAY_OUTRO_1);
                    me->GetMotionMaster()->MovePath(me->GetEntry() * 100, false);
                    break;
                case EVENT_OUTRO_2:
                    DoCastAOE(SPELL_KILL_CREDIT);
                    Talk(SAY_OUTRO_2);
                    me->GetMotionMaster()->MovePoint(1, BrannVaultOfLightOutroPos);
                    break;
                case EVENT_FINISH_OUTRO:
                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER);
                    me->SetFacingTo(3.141592741012573242f);
                    me->setActive(false);
                    break;
                default:
                    break;
            }
        }
    }
private:
    bool _allowAreaTriggerText;

    uint8 _deadWarden;
    InstanceScript* _instance;
    EventMap _events;
};

enum VaultOfLightsWarden
{
    // Flame Warden
    SPELL_LAVA_ERUPTION             = 77273,
    SPELL_RAGING_INFERNO            = 77241,

    EVENT_LAVA_ERUPTION             = 1,
    EVENT_RAGING_INFERNO,

    // Air Warden
    SPELL_WHIRLING_WINDS            = 77316,
    SPELL_WHIRLING_WINDS_PERIODIC   = 77321,
    SPELL_WIND_SHEAR                = 77334,

    EVENT_WHIRLING_WINDS            = 1,
    EVENT_WIND_SHEAR,

    // Earth Warden
    SPELL_ROCKWAVE                  = 77234,
    SPELL_IMPALE                    = 77235,

    EVENT_ROCKWAVE                  = 1,
    EVENT_IMPALE,

    // Water Warden
    SPELL_AQUA_BOMB                 = 77349,
    SPELL_BUBBLE_BOUND              = 77335,
    SPELL_AUTO_GROW                 = 77354,
    SPELL_AQUA_BOMB_PERIODIC        = 77350,
    SPELL_BUBBLE_BOUND_SCRIPT       = 77339,
    SPELL_BUBBLE_BOUND_INSTAKILL    = 77341,
    SPELL_BUBBLE_BOUND_PERIODIC     = 77336,

    EVENT_BUBBLE_BOUND              = 1
};

struct npc_hoo_vaults_of_light_warden : public ScriptedAI
{
    npc_hoo_vaults_of_light_warden(Creature* creature) : ScriptedAI(creature), _instance(nullptr), _wardenNumber(0) { }

    void InitializeAI() override
    {
        _instance = me->GetInstanceScript();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _events.Reset();
        if (_instance)
            _instance->SetData(DATA_WARDEN_1_DIED + _wardenNumber, DONE);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        ScriptedAI::EnterEvadeMode(why);
        _events.Reset();
    }

    void SetData(uint32 type, uint32 value) override
    {
        if (type == DATA_WARDEN_NUMBER)
            _wardenNumber = value;
    }

public:
    InstanceScript* _instance;
    EventMap _events;

private:
    uint8 _wardenNumber;
};

struct npc_hoo_flame_warden : public npc_hoo_vaults_of_light_warden
{
    npc_hoo_flame_warden(Creature* creature) : npc_hoo_vaults_of_light_warden(creature) { }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_LAVA_ERUPTION, 2s);
        _events.ScheduleEvent(EVENT_RAGING_INFERNO, 5s + 600ms);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_LAVA_ERUPTION:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 45.f, true, false))
                        DoCast(target, SPELL_LAVA_ERUPTION);
                    else
                        DoCastVictim(SPELL_LAVA_ERUPTION);
                    _events.Repeat(_events.GetTimeUntilEvent(EVENT_RAGING_INFERNO) > (10 * IN_MILLISECONDS) ? 6s : 12s);
                    break;
                case EVENT_RAGING_INFERNO:
                    DoCastSelf(SPELL_RAGING_INFERNO);
                    _events.Repeat(18s);
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

struct npc_hoo_air_warden : public npc_hoo_vaults_of_light_warden
{
    npc_hoo_air_warden(Creature* creature) : npc_hoo_vaults_of_light_warden(creature) { }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_WHIRLING_WINDS, 4s + 800ms);
        _events.ScheduleEvent(EVENT_WIND_SHEAR, 5s + 600ms);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_WHIRLING_WINDS:
                    DoCastSelf(SPELL_WHIRLING_WINDS);
                    _events.Repeat(12s);
                    _events.ScheduleEvent(EVENT_WIND_SHEAR, 1s + 200ms, 2s + 400ms);
                    break;
                case EVENT_WIND_SHEAR:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.f, true, false))
                        DoCast(target, SPELL_WIND_SHEAR);
                    else
                        DoCastVictim(SPELL_WIND_SHEAR);
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

struct npc_hoo_earth_warden : public npc_hoo_vaults_of_light_warden
{
    npc_hoo_earth_warden(Creature* creature) : npc_hoo_vaults_of_light_warden(creature) { }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_ROCKWAVE, 6s);
        _events.ScheduleEvent(EVENT_IMPALE, 10s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ROCKWAVE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.f, true, false))
                        DoCast(target, SPELL_ROCKWAVE);
                    else
                        DoCastVictim(SPELL_ROCKWAVE);
                    _events.Repeat(13s);
                    break;
                case EVENT_IMPALE:
                    DoCastVictim(SPELL_IMPALE);
                    _events.Repeat(20s); // Todo: validate. This timer has been taken from DBM as no sniffs of mine had a repeating cast
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

struct npc_hoo_water_warden : public npc_hoo_vaults_of_light_warden
{
    npc_hoo_water_warden(Creature* creature) : npc_hoo_vaults_of_light_warden(creature) { }

    void JustEngagedWith(Unit* /*who*/) override
    {
        DoCastSelf(SPELL_AQUA_BOMB);
        _events.ScheduleEvent(EVENT_BUBBLE_BOUND, 10s);
    }

    void JustSummoned(Creature* summon) override
    {
        summon->CastSpell(summon, SPELL_AUTO_GROW);
        summon->CastSpell(summon, SPELL_AQUA_BOMB_PERIODIC);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_BUBBLE_BOUND:
                    DoCastAOE(SPELL_BUBBLE_BOUND, CastSpellExtraArgs().AddSpellMod(SPELLVALUE_MAX_TARGETS, 1));
                    _events.Repeat(16s);
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

struct npc_hoo_whirling_winds : public ScriptedAI
{
    npc_hoo_whirling_winds(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetReactState(REACT_AGGRESSIVE);
        me->SetDisplayId(me->GetCreatureTemplate()->Modelid1);
    }

    void AttackStart(Unit* who) override
    {
        AttackStartCaster(who, 0.01f);
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_WHIRLING_WINDS_PERIODIC);
        DoZoneInCombat();
    }

    void UpdateAI(uint32 /*diff*/) override
    {
        UpdateVictim();
    }
};

struct npc_hoo_aqua_bubble : public NullCreatureAI
{
    npc_hoo_aqua_bubble(Creature* creature) : NullCreatureAI(creature) { }

    void JustDied(Unit* /*killer*/) override
    {
        DoCastSelf(SPELL_BUBBLE_BOUND_SCRIPT, true);
        me->DespawnOrUnsummon(2s);
    }
};

// The Maker's Lift
enum ElevatorMisc
{
    GOSSIP_MENU_HOO_LIFT                    = 12646,
    GOSSIP_NPC_TEXT_CHOOSE_A_DESTINATION    = 17791,
    GOSSIP_OPTION_FIRST_FLOOR               = 0,
    GOSSIP_OPTION_HOO_LIFT_SECOND_FLOOR     = 1,
    GOSSIP_OPTION_HOO_LIFT_THIRD_FLOOR      = 2
};

// 207669 - The Maker's Lift Controller
struct go_hoo_the_makers_lift_controller : public GameObjectAI
{
    go_hoo_the_makers_lift_controller(GameObject* go) : GameObjectAI(go) { }

    bool GossipHello(Player* player) override
    {
        InstanceScript* instance = player->GetInstanceScript();
        if (!instance)
            return false;

        // Build menu.
        // First floor: Option available from start.
        AddGossipItemFor(player, GOSSIP_MENU_HOO_LIFT, GOSSIP_OPTION_FIRST_FLOOR, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 0);

        // Second floor: Anraphet must be defeated first.
        if (instance->GetBossState(DATA_ANRAPHET) == DONE || instance->GetBossState(DATA_EARTHRAGER_PTAH) == DONE)
            AddGossipItemFor(player, GOSSIP_MENU_HOO_LIFT, GOSSIP_OPTION_HOO_LIFT_SECOND_FLOOR, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        // Third floor: Constructs of The Four Seats must be defeated first.
        if (instance->GetBossState(DATA_ISISET) == DONE && instance->GetBossState(DATA_AMMUNAE) == DONE &&
            instance->GetBossState(DATA_SETESH) == DONE && instance->GetBossState(DATA_RAJH) == DONE)
            AddGossipItemFor(player, GOSSIP_MENU_HOO_LIFT, GOSSIP_OPTION_HOO_LIFT_THIRD_FLOOR, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

        SendGossipMenuFor(player, GOSSIP_NPC_TEXT_CHOOSE_A_DESTINATION, me->GetGUID());
        return true;
    }

    bool GossipSelect(Player* player, uint32 /*sender*/, uint32 action) override
    {
        ClearGossipMenuFor(player);
        player->PlayerTalkClass->SendCloseGossip();

        InstanceScript* instance = player->GetInstanceScript();
        if (!instance)
            return true;

        // Handle elevator: gossip item index => stopFrame (floor index).
        Transport* elevator = ObjectAccessor::GetTransportOnMap(*me, instance->GetGuidData(DATA_LIFT_OF_THE_MAKERS));
        if (!elevator)
            return true;

        if (action == 0 && elevator->GetGoState() >= GO_STATE_TRANSPORT_ACTIVE + 2)
            elevator->SetTransportState(GO_STATE_TRANSPORT_ACTIVE);
        else
            elevator->SetTransportState(GO_STATE_TRANSPORT_STOPPED, action);

        return true;
    }
};

class spell_hoo_flame_ring_visual : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if([](WorldObject const* target)->bool
        {
            Unit const* unit = target->ToUnit();
            return !unit || unit->GetEntry() != NPC_SUN_TOUCHED_SERVANT;
        });

        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_hoo_flame_ring_visual::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
        OnEffectHitTarget.Register(&spell_hoo_flame_ring_visual::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_hoo_disperse : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FLAME_DISPERSION });
    }

    void HandleDeath(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->CastSpell(target, SPELL_FLAME_DISPERSION);
        target->KillSelf(); // There is no suicide spell being shown in sniffs
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_hoo_disperse::HandleDeath, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_hoo_submerge : public AuraScript
{
    void HandleFlagsAfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        if (target->IsCreature())
            target->ToCreature()->SetReactState(REACT_PASSIVE);
    }

    void HandleFlagsAfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        GetTarget()->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        if (target->IsCreature())
            target->ToCreature()->SetReactState(REACT_AGGRESSIVE);
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_hoo_submerge::HandleFlagsAfterApply, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove.Register(&spell_hoo_submerge::HandleFlagsAfterRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_hoo_bubble_bound: public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BUBBLE_BOUND_PERIODIC });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if([](WorldObject const* target)
        {
            Unit const* unit = target->ToUnit();
            return (!unit || unit->HasAura(sSpellMgr->GetSpellIdForDifficulty(SPELL_BUBBLE_BOUND_PERIODIC, unit)));
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_hoo_bubble_bound::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_hoo_bubble_bound_periodic : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BUBBLE_BOUND_INSTAKILL });
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode().HasFlag(AuraRemoveFlags::ByDeath | AuraRemoveFlags::ByDefault))
            GetTarget()->CastSpell(GetTarget(), SPELL_BUBBLE_BOUND_INSTAKILL, true);
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_hoo_bubble_bound_periodic::HandleRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_hoo_bubble_bound_script : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BUBBLE_BOUND_PERIODIC });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        TempSummon* summon = GetHitUnit()->ToTempSummon();
        if (!summon)
            return;

        if (Unit* summoner = summon->GetSummoner())
            summoner->RemoveAurasDueToSpell(sSpellMgr->GetSpellIdForDifficulty(SPELL_BUBBLE_BOUND_PERIODIC, summon), ObjectGuid::Empty, 0, AuraRemoveFlags::ByCancel);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_hoo_bubble_bound_script::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 5811 Brann's AreaTrigger
class at_hoo_brann_idle_emote : public AreaTriggerScript
{
public:
    at_hoo_brann_idle_emote() : AreaTriggerScript("at_hoo_brann_idle_emote") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
    {
        if (InstanceScript* instance = player->GetInstanceScript())
            if (Creature* brann = instance->GetCreature(DATA_BRANN_0))
                if (brann->IsAIEnabled)
                    brann->AI()->DoAction(ACTION_INTRO_AREA_TRIGGER);
        return true;
    }
};

void AddSC_halls_of_origination()
{
    RegisterHallsOfOriginationCreatureAI(npc_sun_touched_servant);
    RegisterHallsOfOriginationCreatureAI(npc_hoo_aggro_stalker_1);
    RegisterHallsOfOriginationCreatureAI(npc_hoo_aggro_stalker_2);
    RegisterHallsOfOriginationCreatureAI(npc_hoo_aggro_stalker_3);
    RegisterHallsOfOriginationCreatureAI(npc_hoo_brann_bronzebeard);
    RegisterHallsOfOriginationCreatureAI(npc_hoo_flame_warden);
    RegisterHallsOfOriginationCreatureAI(npc_hoo_air_warden);
    RegisterHallsOfOriginationCreatureAI(npc_hoo_earth_warden);
    RegisterHallsOfOriginationCreatureAI(npc_hoo_water_warden);
    RegisterHallsOfOriginationCreatureAI(npc_hoo_whirling_winds);
    RegisterHallsOfOriginationCreatureAI(npc_hoo_aqua_bubble);
    RegisterGameObjectAI(go_hoo_the_makers_lift_controller);
    RegisterSpellScript(spell_hoo_flame_ring_visual);
    RegisterSpellScript(spell_hoo_disperse);
    RegisterSpellScript(spell_hoo_submerge);
    RegisterSpellScript(spell_hoo_bubble_bound);
    RegisterSpellScript(spell_hoo_bubble_bound_periodic);
    RegisterSpellScript(spell_hoo_bubble_bound_script);
    new at_hoo_brann_idle_emote();
}
