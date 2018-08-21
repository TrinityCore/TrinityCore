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
#include "throne_of_the_tides.h"
#include "GameObject.h"
#include "MoveSpline.h"
#include "ObjectMgr.h"
#include "PassiveAI.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "Vehicle.h"

enum Texts
{
    // Neptulon
    SAY_INTRO_1                     = 0,    
    SAY_INTRO_2                     = 1,
    SAY_PURIFY_WATERS_1             = 2,
    SAY_PURIFY_WATERS_2             = 3,
    SAY_OZUMAT_RETURNED             = 4,
    SAY_STUNNED                     = 5,
    SAY_WATERS_CLEANSED_1           = 6,
    SAY_WATERS_CLEANSED_2           = 7,
    SAY_ANNOUNCE_OZUMAT_VULNERABLE  = 8
};

enum Spells
{
    // Neptulon
    SPELL_PURIFY                        = 76952,
    SPELL_PURE_WATER                    = 84037,
    SPELL_TIDAL_SURGE_1                 = 76133,
    SPELL_TIDAL_SURGE_2                 = 76155,
    SPELL_CLEAR_TIDAL_SURGE             = 83909,

    // Ozumat
    SPELL_OZUMAT_GLOBE_IMPACT_PERIODIC  = 83126,
    SPELL_OZUMAT_RIDE_AURA              = 83119,
    SPELL_BLIGHT_OF_OZUMAT              = 83585,
    SPELL_BLIGHT_OF_OZUMAT_CHANNEL      = 83672,
    SPELL_SUMMON_BLIGHT_OF_OZUMAT       = 83606,
    SPELL_SUMMON_CHEST_VISUAL           = 84074,
    SPELL_GRAB_NEPTULON                 = 94170,
    SPELL_THRONE_OF_TIDES_COMPLETE      = 95673,

    // Phase 1 Adds
    SPELL_CHARGE_TO_WINDOW              = 83240,

    // Vicious Mindlasher
    SPELL_SHADOW_BOLT                   = 83914,
    SPELL_BRAIN_SPIKE                   = 83915,
    SPELL_VEIL_OF_SHADOW                = 83926,

    // Unyielding Behemoth
    SPELL_SHADOW_BLAST                  = 83929,
    SPELL_SHADOW_BLAST_RIDE_VEHICLE     = 83975,
    SPELL_SHADOW_BLAST_VISUAL           = 83977,
    SPELL_SHADOW_BLAST_MISSILE          = 83931,
    SPELL_SHRINK                        = 83976,
    SPELL_BLIGHT_SPRAY                  = 83985,

    // Faceless Sapper
    SPELL_WATER_EXPLOSION_DOWN          = 83479,
    SPELL_ENTANGLING_GRASP              = 83463,

    // World Trigger (Friendly + Invis Man)
    SPELL_SUMMON_MURLOC_ADD_PERIODIC    = 83357,
    SPELL_SUMMON_CASTER_ADD_PERIODIC    = 83440,
    SPELL_SUMMON_KITE_ADD_PERIODIC      = 83649,
    SPELL_SUMMON_LT_ADD_EFFECT          = 83436
};

enum Events
{
    // Neptulon
    EVENT_TALK_INTRO = 1,
    EVENT_PURIFY,
    EVENT_APPLY_CASTER_PERIODIC,
    EVENT_CAST_LT_EFFECT,
    EVENT_TALK_PURIFY_2,
    EVENT_SUMMON_OZUMAT,
    EVENT_TALK_OZUMAT_RETURNED,
    EVENT_SUMMON_FACELESS_SAPPERS,
    EVENT_TALK_STUNNED,
    EVENT_APPLY_KITE_PERIODIC,
    EVENT_TIDAL_SURGE_1,
    EVENT_TIDAL_SURGE_2,
    EVENT_MAKE_OZUMAT_ATTACKABLE,
    EVENT_PURE_WATER,

    // Ozumat
    EVENT_GLOBE_IMPACT,
    EVENT_BLIGHT_OF_OZUMAT,
    EVENT_CHANGE_SEAT,
    EVENT_SWIM_AWAY,
    EVENT_COMPLETE_ENCOUNTER,

    // Vicious Mindlasher
    EVENT_BRAIN_SPIKE,
    EVENT_VEIL_OF_SHADOW,

    // Unyielding Behemoth
    EVENT_BLIGHT_SPRAY,
    EVENT_SHADOW_BLAST,
    EVENT_SHADOW_BLAST_VISUAL,
    EVENT_DISABLE_HOVER_ANIM,
    EVENT_FINISH_SHADOW_BLAST
};

enum Actions
{
    ACTION_FACELESS_DIED        = 0,
    // ACTION_CORAL_GARDEN_ENTERED = 1,
    ACTION_COMPLETE_ENCOUNTER   = 2
};

enum MovePoints
{
    POINT_NONE = 0
};

enum GossipMenu
{
    GOSSIP_OPTION_START_ENCOUNTER = 0
};

enum VehicleSeats
{
    SEAT_0 = 0,
    SEAT_1 = 1
};

class ChargeToWindowEvent : public BasicEvent
{
    public:
        ChargeToWindowEvent(Creature* owner) :  _owner(owner) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _owner->CastSpell(_owner, SPELL_CHARGE_TO_WINDOW);
            return true;
        }

    private:
        Creature* _owner;
};

class EntanglingGraspEvent : public BasicEvent
{
    public:
        EntanglingGraspEvent(Creature* owner) :  _owner(owner) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _owner->CastSpell(_owner, SPELL_ENTANGLING_GRASP);
            return true;
        }

    private:
        Creature* _owner;
};

class AttackNeptulonEvent : public BasicEvent
{
    public:
        AttackNeptulonEvent(Creature* owner) :  _owner(owner) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            if (InstanceScript* instance = _owner->GetInstanceScript())
            {
                if (Creature* neptulon = instance->GetCreature(DATA_NEPTULON))
                {
                    _owner->SetReactState(REACT_AGGRESSIVE);
                    if (_owner->IsAIEnabled)
                    {
                        if (_owner->GetEntry() == NPC_UNYIELDING_BEHEMOTH
                            || _owner->GetEntry() == NPC_VICIOUS_MINDLASHER
                            || _owner->GetEntry() == NPC_BLIGHT_BEAST)
                            _owner->AI()->DoZoneInCombat();
                        else
                            _owner->AI()->AttackStart(neptulon);
                    }
                }
            }
            return true;
        }
    private:
        Creature* _owner;
};

Position const OzumatCombatTriggerPos   = { -153.333f, 982.807f, 229.5483f, 2.792527f };
Position const WorldTriggerFriendlyPos  = { -147.439f, 981.911f, 230.3853f, 0.0f };
Position const OzumatPos                = { -64.0677f, 845.455f, 310.6913f, 2.181662f };
Position const AddSpawnerPosLeft        = { -65.9722f, 1031.8f,  257.2863f };
Position const WindowChargePos1         = { -95.2135f, 1014.13f, 253.908f };
Position const WindowChargePos2         = { -127.332f, 930.429f, 253.371f };
Position const GroundJumpPos1           = { -122.5607f, 1001.56f, 230.2997f };
Position const GroundJumpPos2           = { -137.7711f, 952.5314f, 231.0441f };
Position const OzumatVehicleEscapePos   = { 69.08652f, 746.204f, 423.8753f };
Position const NeptulonsCachePos        = { -157.986f, 982.238f, 229.131f, 2.984498f };
QuaternionData const NeptulonsCacheRot  = QuaternionData(0.0f, 0.0f, 0.9969168f, 0.07846643f);

Position const OzumatAddSpawnerPositions[] =
{
    { -103.066f, 910.313f, 263.1674f, 2.164208f },
    { -65.9722f, 1031.8f,  257.2863f, 3.926991f }
};

Position const FacelessSapperPositions[] =
{
    { -168.227f, 963.314f, 306.8248f, 0.4886922f },
    { -125.307f, 1004.49f, 306.9727f, 3.892084f },
    { -166.064f, 1005.38f, 307.5078f, 5.393067f }
};

struct boss_ozumat : public BossAI
{
    boss_ozumat(Creature* creature) : BossAI(creature, DATA_OZUMAT)
    {
        Initialize();
    }

    void Initialize()
    {
        _dead = false;
        me->SetReactState(REACT_PASSIVE);
    }

    void Reset() override
    {
        events.ScheduleEvent(EVENT_GLOBE_IMPACT, 2s + 500ms);
        events.ScheduleEvent(EVENT_BLIGHT_OF_OZUMAT, 3s + 500ms);
    }

    void DamageTaken(Unit* /*attacker*/, uint32 &damage) override
    {
        if (damage >= me->GetHealth())
        {
            damage = me->GetHealth() - 1;
            if (!_dead)
            {
                me->InterruptNonMeleeSpells(false);
                DoCastSelf(SPELL_GRAB_NEPTULON);
                if (Creature* neptulon = instance->GetCreature(DATA_NEPTULON))
                    neptulon->AI()->DoAction(ACTION_COMPLETE_ENCOUNTER);

                if (GameObject* cache = me->SummonGameObject(IsHeroic() ? GO_NEPTULONS_CACHE_HEROIC : GO_NEPTULONS_CACHE_NORMAL, NeptulonsCachePos, NeptulonsCacheRot, WEEK, GO_SUMMON_TIMED_DESPAWN))
                    cache->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);

                events.ScheduleEvent(EVENT_CHANGE_SEAT, 3s + 500ms);
                _dead = true;
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_GLOBE_IMPACT:
                    DoCastSelf(SPELL_OZUMAT_GLOBE_IMPACT_PERIODIC);
                    if (Creature* vehicle = instance->GetCreature(DATA_OZUMAT_VEHICLE))
                        DoCast(vehicle, SPELL_OZUMAT_RIDE_AURA);
                    break;
                case EVENT_BLIGHT_OF_OZUMAT:
                    DoZoneInCombat();
                    DoCastSelf(SPELL_BLIGHT_OF_OZUMAT);
                    break;
                case EVENT_CHANGE_SEAT:
                    DoCastAOE(SPELL_SUMMON_CHEST_VISUAL);
                    if (Creature* vehicle = instance->GetCreature(DATA_OZUMAT_VEHICLE))
                        me->EnterVehicle(vehicle, SEAT_1);

                    events.ScheduleEvent(EVENT_SWIM_AWAY, 1s);
                    break;
                case EVENT_SWIM_AWAY:
                    if (Creature* vehicle = me->GetVehicleCreatureBase())
                        vehicle->GetMotionMaster()->MovePoint(0, OzumatVehicleEscapePos, false);
                    events.ScheduleEvent(EVENT_COMPLETE_ENCOUNTER, 5s);
                    break;
                case EVENT_COMPLETE_ENCOUNTER:
                    DoCastAOE(SPELL_CLEAR_TIDAL_SURGE, true);
                    if (Creature* neptulon = instance->GetCreature(DATA_NEPTULON))
                    {
                        instance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_THRONE_OF_TIDES_COMPLETE, 0, me);
                        instance->SetBossState(DATA_OZUMAT, DONE);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, neptulon);

                        if (IsHeroic())
                            instance->instance->PermBindAllPlayers();

                        neptulon->DespawnOrUnsummon();

                        if (Player* player = me->SelectNearestPlayer(500.0f))
                            player->RewardPlayerAndGroupAtKill(me, false);

                        me->DespawnOrUnsummon();
                    }
                    break;
                default:
                    break;
            }
        }
    }
private:
    bool _dead;
};

struct npc_ozumat_neptulon : public ScriptedAI
{
    npc_ozumat_neptulon(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript()), _summons(me)
    {
        Initialize();
    }

    void Initialize()
    {
        _deadAddsCount = 0;
        _friendlyTriggerGUID = ObjectGuid::Empty;
    }

    void AttackStart(Unit* /*who*/) override { }

    void Reset() override
    {
        Initialize();
        _instance->SetBossState(DATA_OZUMAT, NOT_STARTED);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        if (why != EVADE_REASON_OTHER)
            return;

        _EnterEvadeMode();
        _summons.DespawnAll();
        _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _instance->SetBossState(DATA_OZUMAT, FAIL);
        DoCastAOE(SPELL_CLEAR_TIDAL_SURGE);
        me->DespawnOrUnsummon(0, 30s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _summons.DespawnAll();
        _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _instance->SetBossState(DATA_OZUMAT, FAIL);
        DoCastAOE(SPELL_CLEAR_TIDAL_SURGE);
        me->DespawnOrUnsummon(0, 30s);
    }

    bool GossipSelect(Player* /*player*/, uint32 /*menuId*/, uint32 gossipListId) override
    {
        if (gossipListId == GOSSIP_OPTION_START_ENCOUNTER)
        {
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            me->SetFacingTo(0.1396263f);

            _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
            _instance->SetBossState(DATA_OZUMAT, IN_PROGRESS);

            DoSummon(NPC_OZUMAT_COMBAT_TRIGGER, OzumatCombatTriggerPos);

            for (uint8 i = 0; i < 2; i++)
                DoSummon(NPC_OZUMAT_ADD_SPAWNER, OzumatAddSpawnerPositions[i]);

            if (Creature* friendlyTrigger = DoSummon(NPC_WORLD_TRIGGER_FRIENDLY, WorldTriggerFriendlyPos))
            {
                _friendlyTriggerGUID = friendlyTrigger->GetGUID();
                friendlyTrigger->CastSpell(friendlyTrigger, SPELL_SUMMON_MURLOC_ADD_PERIODIC);
            }

            _events.CancelEvent(EVENT_TALK_INTRO);
            _events.ScheduleEvent(EVENT_PURIFY, 1s);
            _events.ScheduleEvent(EVENT_CAST_LT_EFFECT, 20s, 22s);
            _events.ScheduleEvent(EVENT_APPLY_CASTER_PERIODIC, 5s);
        }

        return false;
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_CORAL_GARDEN_ENTERED:
                Talk(SAY_INTRO_1);
                _events.ScheduleEvent(EVENT_TALK_INTRO, 7s);
                break;
            case ACTION_FACELESS_DIED:
                _deadAddsCount++;
                if (_deadAddsCount == 4)
                {
                    _events.ScheduleEvent(EVENT_SUMMON_OZUMAT, 3s);
                    _events.ScheduleEvent(EVENT_TALK_OZUMAT_RETURNED, 200ms);
                    _events.ScheduleEvent(EVENT_SUMMON_FACELESS_SAPPERS, 4s + 500ms);
                    _events.ScheduleEvent(EVENT_APPLY_KITE_PERIODIC, 9s);
                }
                break;
            case ACTION_COMPLETE_ENCOUNTER:
                for (ObjectGuid guid : _summons)
                    if (Creature* summon = ObjectAccessor::GetCreature(*me, guid))
                        if (summon->GetEntry() != BOSS_OZUMAT)
                            summon->DespawnOrUnsummon();

                _events.Reset();
                break;
            default:
                break;
        }
        
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        if (summon->GetEntry() == NPC_FACELESS_SAPPER)
        {
            _deadAddsCount++;
            if (_deadAddsCount == 7)
            {
                if (Creature* friendlyTrigger = ObjectAccessor::GetCreature(*me, _friendlyTriggerGUID))
                    friendlyTrigger->RemoveAllAuras();

                if (Creature* ozumat = _instance->GetCreature(DATA_OZUMAT))
                    ozumat->RemoveAurasDueToSpell(SPELL_BLIGHT_OF_OZUMAT);

                _summons.DespawnEntry(NPC_OZUMAT_ADD_SPAWNER);
                _events.ScheduleEvent(EVENT_TIDAL_SURGE_1, 2s + 500ms);
            }
        }
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_ENTANGLING_GRASP)
        {
            me->RemoveAurasDueToSpell(SPELL_PURIFY);
            _events.RescheduleEvent(EVENT_TALK_STUNNED, 3s);
        }
    }

    void JustSummoned(Creature* summon) override
    {
        _summons.Summon(summon);

        switch (summon->GetEntry())
        {
            case NPC_DEEP_MURLOC_INVADER:
            case NPC_VICIOUS_MINDLASHER:
            case NPC_UNYIELDING_BEHEMOTH:
                summon->SetReactState(REACT_PASSIVE);
                summon->SetDisableGravity(true);
                summon->SendSetPlayHoverAnim(true);
                summon->SetCorpseDelay(4);
                summon->m_Events.AddEvent(new ChargeToWindowEvent(summon), summon->m_Events.CalculateTime(2 * IN_MILLISECONDS));
                break;
            case NPC_BLIGHT_BEAST:
                summon->SetReactState(REACT_PASSIVE);
                summon->SetDisableGravity(true);
                summon->SendSetPlayHoverAnim(true);
                summon->SetCorpseDelay(4);
                summon->m_Events.AddEvent(new ChargeToWindowEvent(summon), summon->m_Events.CalculateTime(2400));
                break;
            case NPC_FACELESS_SAPPER:
                summon->CastSpell(summon, SPELL_WATER_EXPLOSION_DOWN);
                summon->SetReactState(REACT_PASSIVE);
                summon->SetCorpseDelay(4);
                summon->GetMotionMaster()->MoveFall();
                summon->m_Events.AddEvent(new EntanglingGraspEvent(summon), summon->m_Events.CalculateTime(3 * IN_MILLISECONDS));
                break;
            case NPC_OZUMAT_COMBAT_TRIGGER:
                summon->SetReactState(REACT_PASSIVE);
                summon->SetCombatPulseDelay(1);
                summon->AI()->DoZoneInCombat();
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
                case EVENT_TALK_INTRO:
                    Talk(SAY_INTRO_2);
                    break;
                case EVENT_PURIFY:
                    Talk(SAY_PURIFY_WATERS_1);
                    DoCastSelf(SPELL_PURIFY);
                    _events.ScheduleEvent(EVENT_TALK_PURIFY_2, 46s);
                    break;
                case EVENT_APPLY_CASTER_PERIODIC:
                    if (Creature* friendlyTrigger = ObjectAccessor::GetCreature(*me, _friendlyTriggerGUID))
                        friendlyTrigger->CastSpell(friendlyTrigger, SPELL_SUMMON_CASTER_ADD_PERIODIC);
                    break;
                case EVENT_CAST_LT_EFFECT:
                    if (Creature* friendlyTrigger = ObjectAccessor::GetCreature(*me, _friendlyTriggerGUID))
                        friendlyTrigger->CastSpell(friendlyTrigger, SPELL_SUMMON_LT_ADD_EFFECT);
                    break;
                case EVENT_TALK_PURIFY_2:
                    Talk(SAY_PURIFY_WATERS_2);
                    break;
                case EVENT_SUMMON_OZUMAT:
                    DoSummon(BOSS_OZUMAT, OzumatPos);
                    break;
                case EVENT_TALK_OZUMAT_RETURNED:
                    Talk(SAY_OZUMAT_RETURNED);
                    break;
                case EVENT_SUMMON_FACELESS_SAPPERS:
                    for (uint8 i = 0; i < 3; i++)
                        DoSummon(NPC_FACELESS_SAPPER, FacelessSapperPositions[i]);
                    break;
                case EVENT_TALK_STUNNED:
                    Talk(SAY_STUNNED);
                    break;
                case EVENT_APPLY_KITE_PERIODIC:
                    if (Creature* friendlyTrigger = ObjectAccessor::GetCreature(*me, _friendlyTriggerGUID))
                        friendlyTrigger->CastSpell(friendlyTrigger, SPELL_SUMMON_KITE_ADD_PERIODIC);
                    break;
                case EVENT_TIDAL_SURGE_1:
                    if (Creature* ozumat = _instance->GetCreature(DATA_OZUMAT))
                    {
                        ozumat->CastSpell(ozumat, SPELL_SUMMON_BLIGHT_OF_OZUMAT);
                        ozumat->CastSpell(ozumat, SPELL_BLIGHT_OF_OZUMAT_CHANNEL);
                    }

                    Talk(SAY_WATERS_CLEANSED_1);
                    DoCastAOE(SPELL_TIDAL_SURGE_1);
                    _events.ScheduleEvent(EVENT_TIDAL_SURGE_2, 3s + 200ms);
                    break;
                case EVENT_TIDAL_SURGE_2:
                    _instance->DoCastSpellOnPlayers(SPELL_TIDAL_SURGE_2);
                    _events.ScheduleEvent(EVENT_MAKE_OZUMAT_ATTACKABLE, 5s + 500ms);
                    break;
                case EVENT_MAKE_OZUMAT_ATTACKABLE:
                    Talk(SAY_WATERS_CLEANSED_2);
                    Talk(SAY_ANNOUNCE_OZUMAT_VULNERABLE);
                    DoCastAOE(SPELL_PURE_WATER);
                    _events.ScheduleEvent(EVENT_PURE_WATER, 2s + 500ms);
                    break;
                case EVENT_PURE_WATER:
                    DoCastAOE(SPELL_PURE_WATER);
                    _events.Repeat(2s + 500ms);
                    break;
                default:
                    break;
            }
        }
    }

private:
    InstanceScript* _instance;
    SummonList _summons;
    EventMap _events;
    ObjectGuid _friendlyTriggerGUID;
    uint8 _deadAddsCount;
};

struct npc_ozumat_vicious_mindlasher : public ScriptedAI
{
    npc_ozumat_vicious_mindlasher(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript()) { }

    void AttackStart(Unit* who) override
    {
        if (!who)
            return;

        AttackStartCaster(who, 20.0f);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_BRAIN_SPIKE, 44s, 45s);
        _events.ScheduleEvent(SPELL_VEIL_OF_SHADOW, 8s, 9s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* neptulon = _instance->GetCreature(DATA_NEPTULON))
            neptulon->AI()->DoAction(ACTION_FACELESS_DIED);
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
                case EVENT_BRAIN_SPIKE:
                    DoCastAOE(SPELL_BRAIN_SPIKE);
                    break;
                case SPELL_VEIL_OF_SHADOW:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true, 0))
                        DoCast(target, SPELL_VEIL_OF_SHADOW);
                    break;
                default:
                    break;
            }
        }

        DoSpellAttackIfReady(SPELL_SHADOW_BOLT);
    }

private:
    InstanceScript* _instance;
    EventMap _events;

};

struct npc_ozumat_unyielding_behemoth : public ScriptedAI
{
    npc_ozumat_unyielding_behemoth(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript()) { }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_SHADOW_BLAST, 10s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* neptulon = _instance->GetCreature(DATA_NEPTULON))
            neptulon->AI()->DoAction(ACTION_FACELESS_DIED);
    }

    void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
    {
        if (!who || !apply)
            return;

        who->CastSpell(who, SPELL_SHRINK);
    }

    void JustSummoned(Creature* summon) override
    {
        if (summon->GetEntry() == NPC_UNYIELDING_BEHEMOTH_LEAP_VEHICLE)
        {
            me->AttackStop();
            me->SetReactState(REACT_PASSIVE);
            me->SetDisableGravity(true);
            me->SendSetPlayHoverAnim(true);
            DoCast(summon, SPELL_SHADOW_BLAST_RIDE_VEHICLE);
            _events.ScheduleEvent(EVENT_DISABLE_HOVER_ANIM, 400ms);
            _events.ScheduleEvent(EVENT_SHADOW_BLAST_VISUAL, 1s + 200ms);
            _events.ScheduleEvent(EVENT_FINISH_SHADOW_BLAST, 6s);
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_SHADOW_BLAST_VISUAL)
            target->RemoveAurasDueToSpell(SPELL_SHRINK);
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
                case EVENT_BLIGHT_SPRAY:
                    DoCastVictim(SPELL_BLIGHT_SPRAY);
                    break;
                case EVENT_SHADOW_BLAST:
                    DoCastAOE(SPELL_SHADOW_BLAST);
                    break;
                case EVENT_DISABLE_HOVER_ANIM:
                    me->SendSetPlayHoverAnim(false);
                    break;
                case EVENT_SHADOW_BLAST_VISUAL:
                    DoCastAOE(SPELL_SHADOW_BLAST_VISUAL);
                    break;
                case EVENT_FINISH_SHADOW_BLAST:
                    me->SetDisableGravity(false);
                    me->SendSetPlayHoverAnim(false);
                    me->SetReactState(REACT_AGGRESSIVE);
                    if (Unit* victim = me->GetVictim())
                        AttackStart(victim);

                    _events.ScheduleEvent(EVENT_BLIGHT_SPRAY, 100ms);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    InstanceScript* _instance;
    EventMap _events;
};

class spell_ozumat_charge_to_window : public SpellScript
{
    PrepareSpellScript(spell_ozumat_charge_to_window);

    void SetDest(SpellDestination& dest)
    {
        if (Unit* caster = GetCaster())
        {
            if (caster->GetDistance(AddSpawnerPosLeft) < 1.0f)
                dest.Relocate(WindowChargePos1);
            else
                dest.Relocate(WindowChargePos2);
        }
    }

    void Register()
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_ozumat_charge_to_window::SetDest, EFFECT_0, TARGET_DEST_NEARBY_ENTRY);
    }
};

class spell_ozumat_jump_to_ground : public SpellScript
{
    PrepareSpellScript(spell_ozumat_jump_to_ground);

    void SetDest(SpellDestination& dest)
    {
        if (Unit* caster = GetCaster())
        {
            if (caster->GetDistance(WindowChargePos1) < 1.0f)
                dest.Relocate(GroundJumpPos1);
            else
                dest.Relocate(GroundJumpPos2);
        }
    }

    void DisableHoverEffects()
    {
        if (Unit* caster = GetCaster())
        {
            caster->SetDisableGravity(false);
            caster->SendSetPlayHoverAnim(false);
        }
    }

    void PrepareNeptulonAttack()
    {
        if (Unit* caster = GetCaster())
        {
            if (Creature* creature = caster->ToCreature())
            {
                if (int32 travelTime = creature->movespline->Duration())
                    creature->m_Events.AddEvent(new AttackNeptulonEvent(creature), creature->m_Events.CalculateTime(travelTime + 500));
            }
        }
    }

    void Register()
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_ozumat_jump_to_ground::SetDest, EFFECT_0, TARGET_DEST_NEARBY_ENTRY);
        BeforeCast += SpellCastFn(spell_ozumat_jump_to_ground::DisableHoverEffects);
        AfterCast += SpellCastFn(spell_ozumat_jump_to_ground::PrepareNeptulonAttack);
    }
};

class spell_ozumat_shadow_blast : public SpellScript
{
    PrepareSpellScript(spell_ozumat_shadow_blast);

    void SetDest(SpellDestination& dest)
    {
        dest.RelocateOffset({ 0.0f, 0.0f, 5.0f, 0.0f });
    }

    void Register()
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_ozumat_shadow_blast::SetDest, EFFECT_0, TARGET_DEST_CASTER);
    }
};

class spell_ozumat_shadow_blast_AuraScript : public AuraScript
{
    PrepareAuraScript(spell_ozumat_shadow_blast_AuraScript);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHADOW_BLAST_MISSILE });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* target = GetTarget())
        {
            target->SendSetPlayHoverAnim(true);
            target->CastSpell(target, SPELL_SHADOW_BLAST_MISSILE);

            if (Vehicle* vehicle = target->GetVehicleKit())
                if (Unit* dummy = vehicle->GetPassenger(SEAT_0))
                    dummy->CastSpell(dummy, SPELL_SHRINK);
        }
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_ozumat_shadow_blast_AuraScript::AfterRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_ozumat_shadow_blast_missile : public SpellScript
{
    PrepareSpellScript(spell_ozumat_shadow_blast_missile);

    void SetDest(SpellDestination& dest)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        // Calculation is correct, core needs to support vertical only splines....
        Position pos = GetCaster()->GetPosition();
        pos.m_positionZ = caster->GetMap()->GetHeight(caster->GetPhaseShift(), pos);
        dest.Relocate(pos);
    }

    void Register()
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_ozumat_shadow_blast_missile::SetDest, EFFECT_0, TARGET_DEST_CASTER);
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_ozumat_shadow_blast_missile::SetDest, EFFECT_1, TARGET_DEST_CASTER);
    }
};

class spell_ozumat_blight_of_ozumat : public SpellScript
{
    PrepareSpellScript(spell_ozumat_blight_of_ozumat);

    void HandleHit(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_ozumat_blight_of_ozumat::HandleHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_boss_ozumat()
{
    RegisterThroneOfTheTidesCreatureAI(boss_ozumat);
    RegisterThroneOfTheTidesCreatureAI(npc_ozumat_neptulon);
    RegisterThroneOfTheTidesCreatureAI(npc_ozumat_vicious_mindlasher);
    RegisterThroneOfTheTidesCreatureAI(npc_ozumat_unyielding_behemoth);
    RegisterSpellScript(spell_ozumat_charge_to_window);
    RegisterSpellScript(spell_ozumat_jump_to_ground);
    RegisterSpellAndAuraScriptPair(spell_ozumat_shadow_blast, spell_ozumat_shadow_blast_AuraScript);
    RegisterSpellScript(spell_ozumat_shadow_blast_missile);
    RegisterSpellScript(spell_ozumat_blight_of_ozumat);
}
