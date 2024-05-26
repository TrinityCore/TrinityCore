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

#include "isle_of_conquest.h"
#include "ScriptMgr.h"
#include "Battleground.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "Vehicle.h"
#include "WorldStateMgr.h"

// TO-DO: This should be done with SmartAI, but yet it does not correctly support vehicles's AIs.
//        Even adding ReactState Passive we still have issues using SmartAI.

struct npc_four_car_garage : public NullCreatureAI
{
    npc_four_car_garage(Creature* creature) : NullCreatureAI(creature) { }

    void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
    {
        if (apply)
        {
            uint32 spellId = 0;

            switch (me->GetEntry())
            {
                case NPC_DEMOLISHER:
                    spellId = SPELL_DRIVING_CREDIT_DEMOLISHER;
                    break;
                case NPC_GLAIVE_THROWER_A:
                case NPC_GLAIVE_THROWER_H:
                    spellId = SPELL_DRIVING_CREDIT_GLAIVE;
                    break;
                case NPC_SIEGE_ENGINE_H:
                case NPC_SIEGE_ENGINE_A:
                    spellId = SPELL_DRIVING_CREDIT_SIEGE;
                    break;
                case NPC_CATAPULT:
                    spellId = SPELL_DRIVING_CREDIT_CATAPULT;
                    break;
                default:
                    return;
            }

            me->CastSpell(who, spellId, true);
        }
    }
};

enum Events
{
    EVENT_TALK  = 1,
    EVENT_DESPAWN
};

enum Texts
{
    SAY_ONBOARD = 0
};

struct npc_ioc_gunship_captain : public ScriptedAI
{
    npc_ioc_gunship_captain(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        DoCast(me, SPELL_SIMPLE_TELEPORT);
        _events.ScheduleEvent(EVENT_TALK, 3s);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);
        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_TALK:
                    _events.ScheduleEvent(EVENT_DESPAWN, 1s);
                    Talk(SAY_ONBOARD);
                    DoCast(me, SPELL_TELEPORT_VISUAL_ONLY);
                    break;
                case EVENT_DESPAWN:
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

struct npc_ioc_siege_engine : public ScriptedAI
{
    npc_ioc_siege_engine(Creature* creature) : ScriptedAI(creature) { }

    static constexpr uint32 SPELL_DAMAGED = 67323;
    static constexpr uint32 VEHICLE_REC_ID = 514;
    static constexpr int32 ACTION_REPAIRED = 1;

    void JustAppeared() override
    {
        me->RemoveVehicleKit(false);
        DoCastSelf(SPELL_DAMAGED);
    }

    void DoAction(int32 actionId) override
    {
        // there should be some moving involved first
        if (actionId == ACTION_REPAIRED)
        {
            me->CreateVehicleKit(VEHICLE_REC_ID, me->GetEntry(), false);
            me->GetVehicleKit()->InstallAllAccessories(false);
        }
    }
};

struct go_ioc_capturable_object : public GameObjectAI
{
    go_ioc_capturable_object(GameObject* go) : GameObjectAI(go) { }

    bool OnGossipHello(Player* player) override
    {
        if (me->GetGoState() != GO_STATE_READY || me->HasFlag(GO_FLAG_NOT_SELECTABLE))
            return true;

        if (ZoneScript* zonescript = me->GetZoneScript())
        {
            zonescript->DoAction(ACTION_IOC_INTERACT_CAPTURABLE_OBJECT, player, me);
            return false;
        }

        return true;
    }
};

struct go_ioc_contested_object : public go_ioc_capturable_object
{
    go_ioc_contested_object(GameObject* go) : go_ioc_capturable_object(go) { }

    void Reset() override
    {
        go_ioc_capturable_object::Reset();
        _scheduler.Schedule(1min, [&](TaskContext)
        {
            if (ZoneScript* zonescript = me->GetZoneScript())
                zonescript->DoAction(ACTION_IOC_CAPTURE_CAPTURABLE_OBJECT, me, me);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 67323 - Damaged
class spell_ioc_damaged : public AuraScript
{
    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        if (Creature const* creatureTarget = GetTarget()->ToCreature())
            if (UnitAI* ai = creatureTarget->GetAI())
                ai->DoAction(npc_ioc_siege_engine::ACTION_REPAIRED);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_ioc_damaged::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 66630 - Alliance Gunship Portal
// 66637 - Horde Gunship Portal
class spell_ioc_gunship_portal : public SpellScript
{
    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Player* caster = GetCaster()->ToPlayer();
        Optional<ObjectGuid> transportGuid;
        if (TransportBase const* transport = GetHitCreature()->GetTransport())
            transportGuid = transport->GetTransportGUID();

        caster->TeleportTo({ .Location = WorldLocation(GetHitCreature()->GetMapId(), GetHitCreature()->GetTransOffset()), .TransportGuid = transportGuid });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_ioc_gunship_portal::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 66656 - Parachute
class spell_ioc_parachute_ic : public AuraScript
{
    void HandleTriggerSpell(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        if (Player* target = GetTarget()->ToPlayer())
            if (target->m_movementInfo.GetFallTime() > 2000 && !target->GetTransport())
                target->CastSpell(target, SPELL_PARACHUTE_IC, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_ioc_parachute_ic::HandleTriggerSpell, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class StartLaunchEvent : public BasicEvent
{
    public:
        StartLaunchEvent(Position const& pos, ObjectGuid const& guid) : _pos(pos), _guid(guid)
        {
        }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            Player* player = ObjectAccessor::FindPlayer(_guid);
            if (!player || !player->GetVehicle())
                return true;

            player->AddAura(SPELL_LAUNCH_NO_FALLING_DAMAGE, player); // prevents falling damage
            float speedZ = 10.0f;
            float dist = player->GetExactDist2d(&_pos);

            player->ExitVehicle();
            player->GetMotionMaster()->MoveJump(_pos, dist, speedZ, EVENT_JUMP, true);
            return true;
        }

    private:
        Position _pos;
        ObjectGuid _guid;
};

// 66218 - Launch
class spell_ioc_launch : public SpellScript
{
    void Launch()
    {
        if (!GetCaster()->ToCreature() || !GetExplTargetDest())
            return;

        GetCaster()->ToCreature()->m_Events.AddEvent(new StartLaunchEvent(*GetExplTargetDest(), ASSERT_NOTNULL(GetHitPlayer())->GetGUID()), GetCaster()->ToCreature()->m_Events.CalculateTime(2500ms));
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_ioc_launch::Launch);
    }
};

enum SeaforiumBombSpells
{
    SPELL_SEAFORIUM_BLAST       = 66676,
    SPELL_HUGE_SEAFORIUM_BLAST  = 66672,
    SPELL_A_BOMB_INABLE_CREDIT  = 68366,
    SPELL_A_BOMB_INATION_CREDIT = 68367
};

// 66672 - Huge Seaforium Blast
// 66676 - Seaforium Blast
class spell_ioc_seaforium_blast_credit : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_A_BOMB_INABLE_CREDIT, SPELL_A_BOMB_INATION_CREDIT });
    }

    void HandleAchievementCredit(SpellEffIndex /*effIndex*/)
    {
        uint32 _creditSpell = 0;
        Unit* caster = GetOriginalCaster();
        if (!caster)
            return;

        if (GetSpellInfo()->Id == SPELL_SEAFORIUM_BLAST)
            _creditSpell = SPELL_A_BOMB_INABLE_CREDIT;
        else if (GetSpellInfo()->Id == SPELL_HUGE_SEAFORIUM_BLAST)
            _creditSpell = SPELL_A_BOMB_INATION_CREDIT;

        if (GetHitGObj() && GetHitGObj()->IsDestructibleBuilding())
            caster->CastSpell(caster, _creditSpell, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_ioc_seaforium_blast_credit::HandleAchievementCredit, EFFECT_1, SPELL_EFFECT_GAMEOBJECT_DAMAGE);
    }
};

class at_ioc_exploit : public AreaTriggerScript
{
public:
    at_ioc_exploit() : AreaTriggerScript("at_ioc_exploit") { }

    bool OnExit(Player* player, AreaTriggerEntry const* /*trigger*/) override
    {
        if (Battleground* battleground = player->GetBattleground())
            if (battleground->GetStatus() == STATUS_WAIT_JOIN)
                battleground->TeleportPlayerToExploitLocation(player);

        return true;
    }
};

class at_ioc_backdoor_job : public AreaTriggerScript
{
public:
    static constexpr uint32 AT_HORDE_KEEP = 5535;
    static constexpr uint32 AT_ALLIANCE_KEEP = 5536;

    at_ioc_backdoor_job() : AreaTriggerScript("at_ioc_backdoor_job") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* trigger) override
    {
        /// @hack: this spell should be cast by npc 22515 (World Trigger) and not by the player
        if (player->GetBGTeam() == HORDE && trigger->ID == AT_ALLIANCE_KEEP)
        {
            bool keepClosed = sWorldStateMgr->GetValue(BG_IC_GATE_EAST_A_WS_CLOSED, player->GetMap()) == 1
                && sWorldStateMgr->GetValue(BG_IC_GATE_WEST_A_WS_CLOSED, player->GetMap()) == 1
                && sWorldStateMgr->GetValue(BG_IC_GATE_FRONT_A_WS_CLOSED, player->GetMap()) == 1;

            if (keepClosed)
                player->CastSpell(player, SPELL_BACK_DOOR_JOB_ACHIEVEMENT, true);
        }
        else if (player->GetBGTeam() == ALLIANCE && trigger->ID == AT_HORDE_KEEP)
        {
            bool keepClosed = sWorldStateMgr->GetValue(BG_IC_GATE_EAST_H_WS_CLOSED, player->GetMap()) == 1
                && sWorldStateMgr->GetValue(BG_IC_GATE_WEST_H_WS_CLOSED, player->GetMap()) == 1
                && sWorldStateMgr->GetValue(BG_IC_GATE_FRONT_H_WS_CLOSED, player->GetMap()) == 1;

            if (keepClosed)
                player->CastSpell(player, SPELL_BACK_DOOR_JOB_ACHIEVEMENT, true);
        }

        return true;
    }
};

void AddSC_isle_of_conquest()
{
    RegisterCreatureAI(npc_four_car_garage);
    RegisterCreatureAI(npc_ioc_gunship_captain);
    RegisterCreatureAI(npc_ioc_siege_engine);
    RegisterGameObjectAI(go_ioc_capturable_object);
    RegisterGameObjectAI(go_ioc_contested_object);
    RegisterSpellScript(spell_ioc_damaged);
    RegisterSpellScript(spell_ioc_gunship_portal);
    RegisterSpellScript(spell_ioc_parachute_ic);
    RegisterSpellScript(spell_ioc_launch);
    RegisterSpellScript(spell_ioc_seaforium_blast_credit);
    new at_ioc_exploit();
    new at_ioc_backdoor_job();
}
