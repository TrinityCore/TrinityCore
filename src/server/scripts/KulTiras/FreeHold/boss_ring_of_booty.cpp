/*
 * Copyright (C) 2022 BfaCore Reforged
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "Vehicle.h"
#include "freehold.h"

enum RingOfBootySpells
{
    ///Lightning
    Grabbing = 257831,
    Slippery = 257949,
    Greasy = 257829,
    GreasyDummy = 257950,
    ///Ludwig Von Tortollan 
    ShellBounce = 257904,
    ShellBounceDmg = 257902,
    ///Trothak
    RiderShark = 256410,
    RightSharkRiding = 256368,
    LeftSharkRiding = 256402,
    RipperPunch = 256363,
    SharkTornado = 256405,
    SharkTossJump = 256424,
    SharkTossDmg = 256477,
    FlailingShark = 256551,
    RearmCharge1 = 256489,
    RearmCharge2 = 256494,
    RearmDmg = 256706,
    HammerSharkAura = 256918,
    SawtoothSharkAura = 256923,

    ///Heroic Difficulty
    FlailingSharks = 256551,
    ThrowChumMissile = 272534,
    ThrowChum = 272548,
    BloodyMess = 272554
};

enum RingOfBootyEvents
{
    EventsMoveNextPosition = 1,
    EventsShellBounce,
    EventsRipperPunch,
    EventsSharkTornado,
    EventsSharkToss,
    EventsRearm,
    EventsThrowChum,
    EventsCheckPlayers,
    EventsCheckReset
};

enum RingOfBootyPoint
{
    MovementPointLightningCenter = 1,
    MovementPointLightningChange,
    MovementPointLightningDespawn,
    MovementPointTrothakFirstPoint,
    MovementPointFight,
};

enum RingOfBootyAction
{
    ActionFirstGukGuk = 0,
    ActionFirstGurgthock,
    ActionSecondGukGuk,
    ActionSecondGurgthock,
    ActionStartArena,
    ActionJumpPig,
    ActionSecondEvent,
    ActionThirdEvent,
    ActionStartMoveTrothak,
    ActionFinishFight
};

enum TalkGukguk
{
    TalkFirstGukGuk = 0,
    TalkSecondGukGuk
};

enum TalkGurgthock
{
    TalkFirstGurgthock = 0,
    TalkSecondGurgthock,
    TalkThirdGurgthock,
    TalkFourGurgthock,
    TalkCatchThePig,
    TalkEnterTortolan,
    TalkKillTortolan,
    TalkLastFight
};

enum TalkDavey
{
    TalkStartAnnouncer = 0,
};

Position midleArenaPos{ -1813.17f, -491.82f, 34.96f, 1.57f };
Position despawnPos{ -1811.06f, -439.22f, 35.92f };
Position const TrothakMovePos[3] =
{
    { -1830.87f, -432.38f, 40.13f, 5.94f },
    { -1811.71f, -438.00f, 36.05f, 4.66f },
    { -1812.53f, -473.63f, 35.35f, 4.72f }
};

///ToDo Fire for Trothak when enter to the arena

/// 130090 - Guk Guk
struct npc_gukguk : public ScriptedAI
{
    npc_gukguk(Creature* creature) : ScriptedAI(creature)
    {
        m_Instance = me->GetInstanceScript();
    }

    void DoAction(int32 const action) override
    {
        switch (action)
        {
        case RingOfBootyAction::ActionFirstGukGuk:
            Talk(TalkGukguk::TalkFirstGukGuk);

            AddTimedDelayedOperation(4000, [this]() -> void
                {
                    if (Creature* gurgthock = m_Instance->instance->GetCreature(m_Instance->GetGuidData(FreeholdCreature::NpcGurgthock)))
                        gurgthock->AI()->DoAction(RingOfBootyAction::ActionFirstGurgthock);
                });
            break;
        case RingOfBootyAction::ActionSecondGukGuk:
            Talk(TalkGukguk::TalkSecondGukGuk);

            AddTimedDelayedOperation(4000, [this]() -> void
                {
                    if (Creature* gurgthock = m_Instance->instance->GetCreature(m_Instance->GetGuidData(FreeholdCreature::NpcGurgthock)))
                        gurgthock->AI()->DoAction(RingOfBootyAction::ActionSecondGurgthock);
                });
            break;
        case RingOfBootyAction::ActionFinishFight:
        {
            instance->SetBossState(FreeholdData::DataRingOfBooty, DONE);
            break;
        }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateOperations(diff);
    }

private:

    InstanceScript* m_Instance;
};

/// 130086 - Davey "Two Eyes"
struct npc_davey : public ScriptedAI
{
    npc_davey(Creature* creature) : ScriptedAI(creature)
    {
        m_Instance = me->GetInstanceScript();
    }

    void Reset() override
    {
        eventStarted = false;
        events.Reset();
        me->SetWalk(true);
        events.ScheduleEvent(RingOfBootyEvents::EventsCheckPlayers, 1000);
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        switch (pointId)
        {
        case RingOfBootyPoint::MovementPointFight:
        {
            me->DespawnOrUnsummon();
            break;
        }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateOperations(diff);
        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case RingOfBootyEvents::EventsCheckPlayers:
            {
                if (eventStarted)
                    return;

                std::list<Player*> listPlayer;
                me->GetPlayerListInGrid(listPlayer, 20.0f);
                if (!listPlayer.empty())
                {
                    eventStarted = true;
                    Talk(TalkDavey::TalkStartAnnouncer);
                    me->GetMotionMaster()->MovePoint(RingOfBootyPoint::MovementPointFight, TrothakMovePos[1]);
                    AddTimedDelayedOperation(10 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                    {
                        if (Creature* gukguk = m_Instance->instance->GetCreature(m_Instance->GetGuidData(FreeholdCreature::NpcGukguk)))
                            gukguk->AI()->DoAction(RingOfBootyAction::ActionFirstGukGuk);
                    });
                }
                events.Repeat(1000);
                break;
            }
            }
        }
    }

private:
    bool eventStarted;
    InstanceScript* m_Instance;
};

/// 129350 - Gurgthock
struct npc_gurgthock : public ScriptedAI
{
    npc_gurgthock(Creature* creature) : ScriptedAI(creature)
    {
        m_Instance = me->GetInstanceScript();
    }

    void Reset() override
    {
        events.Reset();
        resetFight = true;
        if (instance->GetBossState(FreeholdData::DataRingOfBooty) != DONE)
        {
            if (Creature* lightning = m_Instance->instance->GetCreature(m_Instance->GetGuidData(FreeholdCreature::NpcLightning)))
                lightning->Respawn(true);
            if (Creature* davey = m_Instance->instance->GetCreature(m_Instance->GetGuidData(FreeholdCreature::NpcDavey)))
                davey->Respawn(true);
            if (Creature* tortolan = m_Instance->instance->GetCreature(m_Instance->GetGuidData(FreeholdCreature::NpcLudwigVonTortollan)))
                tortolan->Respawn(true);
        }
    }

    void DoAction(int32 const action) override
    {
        switch (action)
        {
        case RingOfBootyAction::ActionFirstGurgthock:
            Talk(TalkGurgthock::TalkFirstGurgthock);

            AddTimedDelayedOperation(4000, [this]() -> void
                {
                    if (Creature* gukguk = m_Instance->instance->GetCreature(m_Instance->GetGuidData(FreeholdCreature::NpcGukguk)))
                        gukguk->AI()->DoAction(RingOfBootyAction::ActionSecondGukGuk);
                });
            break;
        case RingOfBootyAction::ActionSecondGurgthock:
            Talk(TalkGurgthock::TalkSecondGurgthock);

            AddTimedDelayedOperation(10000, [this]() -> void
                {
                    Talk(TalkGurgthock::TalkThirdGurgthock);
                });
            AddTimedDelayedOperation(15000, [this]() -> void
                {
                    Talk(TalkGurgthock::TalkFourGurgthock);
                    instance->SetBossState(FreeholdData::DataRingOfBooty, IN_PROGRESS);
                    events.ScheduleEvent(RingOfBootyEvents::EventsCheckReset, 1000);

                    if (Creature* pig = m_Instance->instance->GetCreature(m_Instance->GetGuidData(FreeholdCreature::NpcLightning)))
                        pig->AI()->DoAction(RingOfBootyAction::ActionJumpPig);
                });
            break;
        case RingOfBootyAction::ActionSecondEvent:
        {
            Talk(TalkGurgthock::TalkCatchThePig);
            AddTimedDelayedOperation(6000, [this]() -> void
                {
                    Talk(TalkGurgthock::TalkEnterTortolan);
                });
            AddTimedDelayedOperation(10000, [this]() -> void
                {
                    if (Creature* tortolan = m_Instance->instance->GetCreature(m_Instance->GetGuidData(FreeholdCreature::NpcLudwigVonTortollan)))
                        tortolan->AI()->DoAction(RingOfBootyAction::ActionJumpPig);
                });

            break;
        }
        case RingOfBootyAction::ActionThirdEvent:
        {
            Talk(TalkGurgthock::TalkKillTortolan);
            if (Creature* trothak = me->SummonCreature(FreeholdCreature::NpcTrothak, TrothakMovePos[0], TEMPSUMMON_MANUAL_DESPAWN))
                trothak->GetMotionMaster()->MovePoint(RingOfBootyPoint::MovementPointTrothakFirstPoint, TrothakMovePos[1]);

            AddTimedDelayedOperation(6000, [this]() -> void
                {
                    Talk(TalkGurgthock::TalkLastFight);
                });
            break;
        }
        }

    }

    void UpdateAI(uint32 diff) override
    {
        UpdateOperations(diff);

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case RingOfBootyEvents::EventsCheckReset:
                if (instance->GetBossState(FreeholdData::DataRingOfBooty) != IN_PROGRESS)
                    return;

                Map::PlayerList const& PlayerList = me->GetMap()->GetPlayers();
                if (!PlayerList.isEmpty())
                {
                    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    {
                        Player* player = i->GetSource();
                        if (player->IsAlive())
                        {
                            resetFight = false;
                            break;
                        }
                        else
                            resetFight = true;
                    }
                }

                if (resetFight)
                {
                    if (Creature* tortolan = m_Instance->instance->GetCreature(m_Instance->GetGuidData(FreeholdCreature::NpcLudwigVonTortollan)))
                        tortolan->AI()->EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
                    me->DespawnCreaturesInArea(FreeholdCreature::NpcLightning);
                    me->DespawnCreaturesInArea(FreeholdCreature::NpcTrothak);
                    Reset();
                    return;
                }
                events.Repeat(1000);
                break;
            }
        }
    }

private:
    InstanceScript* m_Instance;
    bool resetFight;
};

/// 130099 - Lightning
struct npc_lightning : public ScriptedAI
{
    npc_lightning(Creature* creature) : ScriptedAI(creature)
    {
        m_Instance = me->GetInstanceScript();
    }

    void Reset() override
    {
        events.Reset();
        countClick = 0;
        waitNextClick = false;
        me->SetReactState(REACT_PASSIVE);
        me->RemoveAllAuras();
    }

    void DoAction(int32 const action) override
    {
        if (action == RingOfBootyAction::ActionJumpPig)
            me->GetMotionMaster()->MoveJump(midleArenaPos, 10.0f, 20.0f, RingOfBootyPoint::MovementPointLightningCenter);
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
            return;

        switch (pointId)
        {
        case RingOfBootyPoint::MovementPointLightningCenter:
        {
            home = me->GetPosition();
            me->CastSpell(me, RingOfBootySpells::Greasy, true);
            me->CastSpell(me, RingOfBootySpells::GreasyDummy, true);
            events.ScheduleEvent(RingOfBootyEvents::EventsMoveNextPosition, 500);
            break;
        }
        case RingOfBootyPoint::MovementPointLightningChange:
        {
            waitNextClick = false;
            events.ScheduleEvent(RingOfBootyEvents::EventsMoveNextPosition, 500);
            break;
        }
        case RingOfBootyPoint::MovementPointLightningDespawn:
        {
            me->DespawnOrUnsummon();
            break;
        }
        }
    }

    void SpellHit(Unit* caster, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == RingOfBootySpells::Grabbing)
        {
            if (!waitNextClick)
            {
                waitNextClick = true;
                countClick++;
                caster->CastSpell(caster, RingOfBootySpells::Slippery, true);

                if (countClick >= 5)
                {
                    events.Reset();
                    me->GetMotionMaster()->Clear();
                    me->RemoveAllAuras();
                    AddTimedDelayedOperation(2000, [this]() -> void
                        {
                            me->GetMotionMaster()->MovePoint(RingOfBootyPoint::MovementPointLightningDespawn, despawnPos);
                            if (Creature* gutgthock = m_Instance->instance->GetCreature(m_Instance->GetGuidData(FreeholdCreature::NpcGurgthock)))
                                gutgthock->AI()->DoAction(RingOfBootyAction::ActionSecondEvent);
                        });
                }
            }
        }
    }

    void OnSpellClick(Unit* clicker, bool& /*result*/) override
    {
        clicker->CastSpell(me, RingOfBootySpells::Grabbing, false);
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateOperations(diff);
        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case RingOfBootyEvents::EventsMoveNextPosition:
            {
                me->GetMotionMaster()->MovePoint(RingOfBootyPoint::MovementPointLightningChange, GetRandomPositionOnCircle(me, home));
                break;
            }
            }
        }
    }

private:

    /// uniformly distribute on the circle
    static Position GetRandomPositionOnCircle(Unit* unit, Position const& center)
    {
        double angle = rand_norm() * 2.0 * M_PI;
        float randomRadius = frand(15.0f, 30.0f);
        float x = center.GetPositionX() + std::sin(angle) * randomRadius;
        float y = center.GetPositionY() + std::cos(angle) * randomRadius;
        float z = center.GetPositionZ();
        unit->UpdateAllowedPositionZ(x, y, z);
        return Position(x, y, z);
    }

    Position home;
    uint8 countClick;
    bool waitNextClick;
    InstanceScript* m_Instance;
};

/// 129699 - Ludwig Von Tortollan
struct npc_ludwig_von_tortollan : public ScriptedAI
{
    npc_ludwig_von_tortollan(Creature* creature) : ScriptedAI(creature)
    {
        m_Instance = me->GetInstanceScript();
    }

    void Reset() override
    {
        events.Reset();
        me->SetFaction(FreeHoldFaction::FactionFriendly);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        me->AttackStop();
        me->CastStop();
        me->InterruptNonMeleeSpells(true);
        me->SetReactState(ReactStates::REACT_PASSIVE);
        me->DeleteThreatList();
        me->GetMotionMaster()->Clear();
        me->GetMotionMaster()->MoveTargetedHome();
    }

    void JustReachedHome() override
    {
        Reset();
    }

    void DoAction(int32 const action) override
    {
        if (action == RingOfBootyAction::ActionJumpPig)
            me->GetMotionMaster()->MoveJump(midleArenaPos, 10.0f, 20.0f, RingOfBootyPoint::MovementPointLightningCenter);
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
            return;

        switch (pointId)
        {
        case RingOfBootyPoint::MovementPointLightningCenter:
        {
            me->SetFaction(FreeHoldFaction::FactionEnemy);
            me->SetReactState(REACT_AGGRESSIVE);
            DoZoneInCombat();

            events.ScheduleEvent(RingOfBootyEvents::EventsShellBounce, 5000);
            break;
        }
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* gutgthock = m_Instance->instance->GetCreature(m_Instance->GetGuidData(FreeholdCreature::NpcGurgthock)))
            gutgthock->AI()->DoAction(RingOfBootyAction::ActionThirdEvent);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case RingOfBootyEvents::EventsShellBounce:
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                    me->CastSpell(target, RingOfBootySpells::ShellBounce, false);
                events.Repeat(8000);
                break;
            }
            }
        }

        DoMeleeAttackIfReady();
    }
private:
    InstanceScript* m_Instance;
};

///126969 Trothak
struct boss_trothak : public BossAI
{
    boss_trothak(Creature* creature) : BossAI(creature, FreeholdData::DataRingOfBooty)
    {
        m_Instance = me->GetInstanceScript();
    }

    void Reset() override
    {
        _Reset();
        // sharkGUID.Clear();
        affectedPlayer.clear();
        rearm = false;
        checkTimer = 500;
        me->SetWalk(true);
        me->SetFaction(FreeHoldFaction::FactionFriendly);

        // // fix if you die in this scenario
        if (instance->GetBossState(FreeholdData::DataRingOfBooty) != DONE)
        {
            events.Reset();

            if (Creature* lightning = m_Instance->instance->GetCreature(m_Instance->GetGuidData(FreeholdCreature::NpcLightning)))
            {
                if (lightning->isDead())
                {
                    lightning->Respawn(true);
                    lightning->GetMotionMaster()->MoveTargetedHome();
                }
            }
            if (Creature* davey = m_Instance->instance->GetCreature(m_Instance->GetGuidData(FreeholdCreature::NpcDavey)))
            {
                if (davey->isDead())
                {
                    davey->Respawn(true);
                    davey->GetMotionMaster()->MoveTargetedHome();
                }
            }
            if (Creature* tortolan = m_Instance->instance->GetCreature(m_Instance->GetGuidData(FreeholdCreature::NpcLudwigVonTortollan)))
            {
                if (tortolan->isDead())
                {
                    tortolan->Respawn(true);
                    tortolan->GetMotionMaster()->MoveTargetedHome();
                }
            }

        }

        // temporary
        // if (Creature* hammer = me->SummonCreature(FreeholdCreature::NpcHammerShark, me->GetPosition()))
        // {
        //     hammer->CastSpell(hammer, RingOfBootySpells::RightSharkRiding, true);
        //     hammer->CastSpell(me, RingOfBootySpells::RiderShark, true);
        //     hammer->CastSpell(hammer, RingOfBootySpells::HammerSharkAura, true);
        // }

        // if (Creature* sawtooth = me->SummonCreature(FreeholdCreature::NpcSawtoothShark, me->GetPosition()))
        // {
        //     sawtooth->CastSpell(sawtooth, RingOfBootySpells::LeftSharkRiding, true);
        //     sawtooth->CastSpell(me, RingOfBootySpells::RiderShark, true);
        //     sawtooth->CastSpell(sawtooth, RingOfBootySpells::SawtoothSharkAura, true);
        // }
    }

    void JustReachedHome() override
    {
        _JustReachedHome();
        instance->SetBossState(FreeholdData::DataRingOfBooty, FAIL);
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        switch (pointId)
        {
        case RingOfBootyPoint::MovementPointTrothakFirstPoint:
            ///Launch Fire Spell or Scene???
            me->GetMotionMaster()->MovePoint(RingOfBootyPoint::MovementPointFight, TrothakMovePos[2]);
            break;
        case RingOfBootyPoint::MovementPointFight:
        {
            me->SetWalk(false);
            me->SetFaction(FreeHoldFaction::FactionEnemy);
            me->SetReactState(REACT_AGGRESSIVE);
            DoZoneInCombat();

            events.ScheduleEvent(RingOfBootyEvents::EventsRipperPunch, 3000);
            events.ScheduleEvent(RingOfBootyEvents::EventsSharkTornado, 10000);
            events.ScheduleEvent(RingOfBootyEvents::EventsSharkToss, 8000);
            if (IsHeroic())
                events.ScheduleEvent(RingOfBootyEvents::EventsThrowChum, 8000);
            break;
        }
        case EVENT_CHARGE:///SPELL_EFFECT_CHARGE_DEST use this id to movement  Inform
        {
            rearm = false;
            if (Creature* shark = ObjectAccessor::GetCreature(*me, sharkGUID))
                shark->EnterVehicle(me);

            break;
        }
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        // does not start, end the script
        // if (Creature* gukguk = m_Instance->instance->GetCreature(m_Instance->GetGuidData(FreeholdCreature::NpcGukguk)))
        //     gukguk->AI()->DoAction(RingOfBootyAction::ActionFinishFight);

        instance->SetBossState(FreeholdData::DataRingOfBooty, DONE);
    }

    void UpdateAI(uint32 diff) override
    {
        if (rearm)
        {
            if (checkTimer <= diff)
            {
                std::list<Player*> listPlayer;
                me->GetPlayerListInGrid(listPlayer, 50.0f);
                if (!listPlayer.empty())
                {
                    if (!affectedPlayer.empty())
                    {
                        for (Player* l_Itr : affectedPlayer)
                            listPlayer.remove(l_Itr);
                    }

                    if (!listPlayer.empty())
                    {
                        for (Player* l_Itr : listPlayer)
                        {
                            if (!l_Itr)
                                continue;

                            if (l_Itr->GetDistance(me) <= 3.0f)
                            {
                                affectedPlayer.push_back(l_Itr);
                                me->CastSpell(l_Itr, RingOfBootySpells::RearmDmg, true);
                            }
                        }
                    }
                }

                checkTimer = 500;
            }
            else
                checkTimer -= diff;
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
            case RingOfBootyEvents::EventsRipperPunch:
            {
                if (Unit* target = me->GetVictim())
                    me->CastSpell(target, RingOfBootySpells::RipperPunch, false);

                events.Repeat(15000);
                break;
            }
            case RingOfBootyEvents::EventsSharkTornado:
            {
                me->CastSpell(me, RingOfBootySpells::SharkTornado, false);
                events.Repeat(15000);
                break;
            }
            case RingOfBootyEvents::EventsSharkToss:
            {
                sharkGUID.Clear();
                if (me->IsVehicle())
                {
                    if (Vehicle* vehicle = me->GetVehicle())
                    {
                        uint8 passengerSeat = urand(0, 1);
                        if (Unit* shark = vehicle->GetPassenger(passengerSeat))
                        {
                            if (shark->IsCreature())
                            {
                                shark->ExitVehicle();
                                shark->ToCreature()->SetReactState(REACT_PASSIVE);
                                sharkGUID = shark->GetGUID();
                                if (shark->GetEntry() == FreeholdCreature::NpcHammerShark)
                                    shark->AddAura(RingOfBootySpells::HammerSharkAura, shark);
                                else
                                    shark->AddAura(RingOfBootySpells::SawtoothSharkAura, shark);

                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                                    shark->CastSpell(target, RingOfBootySpells::SharkTossJump, false);
                            }
                        }
                    }
                }
                events.ScheduleEvent(RingOfBootyEvents::EventsRearm, 15000);
                break;
            }
            case RingOfBootyEvents::EventsRearm:
            {
                if (Creature* shark = ObjectAccessor::GetCreature(*me, sharkGUID))
                {
                    rearm = true;
                    affectedPlayer.clear();
                    shark->StopMoving();
                    shark->GetMotionMaster()->Clear();
                    me->AttackStop();
                    me->CastStop();
                    me->SetReactState(REACT_PASSIVE);
                    me->GetMotionMaster()->MoveCharge(shark->GetPositionX(), shark->GetPositionY(), shark->GetPositionZ(), 30.0f);
                }
                events.ScheduleEvent(RingOfBootyEvents::EventsSharkToss, 10000);
                break;
            }
            case RingOfBootyEvents::EventsThrowChum:
            {
                me->CastSpell(me, RingOfBootySpells::ThrowChumMissile, true);
                events.Repeat(10000);
                break;
            }
            }
        }

        DoMeleeAttackIfReady();
    }
private:
    InstanceScript* m_Instance;
    ObjectGuid sharkGUID;
    bool rearm;
    uint32 checkTimer;
    std::list<Player*> affectedPlayer;
};

///129448, 129359 Hammer Shark and Sawtooth Shark
struct npc_shark_trothak : public ScriptedAI
{
    npc_shark_trothak(Creature* creature) : ScriptedAI(creature)
    {
        if (IsHeroic())
            checkAreatriggerTimer = 500;

        delayShark = false;
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
            return;

        switch (pointId)
        {
        case EVENT_CHARGE:///SPELL_EFFECT_CHARGE_DEST use this id to movement  Inform
            if (delayShark)
            {
                delayShark = false;
                AddTimedDelayedOperation(1500, [this]() -> void
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0, 0, true))
                            me->CastSpell(target, RingOfBootySpells::FlailingShark, false);
                    });
            }
            else
                if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0, 0, true))
                    me->CastSpell(target, RingOfBootySpells::FlailingShark, false);
            break;
        case EVENT_JUMP:///SPELL_EFFECT_JUMP_DEST use this id to movement  Inform
            if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0, 0, true))
                me->CastSpell(target, RingOfBootySpells::FlailingShark, false);
            break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateOperations(diff);
        if (checkAreatriggerTimer)
        {
            if (!me->IsOnVehicle())
            {
                if (checkAreatriggerTimer <= diff)
                {
                    std::list<AreaTrigger*> AreaTriggerList;
                    me->GetAreaTriggerListWithSpellIDInRange(AreaTriggerList, RingOfBootySpells::ThrowChum, 50.0f);
                    for (auto at : AreaTriggerList)
                        if (me->GetDistance(at) < 3.0f)
                        {
                            delayShark = true;
                            at->Remove();
                        }


                    checkAreatriggerTimer = 500;
                }
                else
                    checkAreatriggerTimer -= diff;
            }
        }
    }

private:
    bool delayShark;
    uint32 checkAreatriggerTimer;
};

///Spell 257905 Shell Bounce Areatriger ID 12070
struct at_shell_bounce : AreaTriggerAI
{
    at_shell_bounce(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnCreate() override
    {
        float rotation;
        float range;

        std::list<Player*> listPlayer;
        GetPlayerListInGrid(listPlayer, at, 100.0f);
        if (!listPlayer.empty())
        {
            if (Player* target = Trinity::Containers::SelectRandomContainerElement(listPlayer))
            {
                rotation = at->GetAngle(target);
                range = frand(10.0f, 30.0f);
            }
        }

        Position dest =
        {
            at->GetPositionX() + (range * cos(rotation)),
            at->GetPositionY() + (range * cos(rotation)),
            at->m_positionZ + 1.0f
        };

        at->SetDestination(dest, 12000);
    }

    void OnInitialize() override
    {
        at->SetPeriodicProcTimer(500);
    }

    void OnPeriodicProc() override
    {
        if (Unit* caster = at->GetCaster())
        {
            GuidUnorderedSet const& insideUnits = at->GetInsideUnits();

            for (ObjectGuid guid : insideUnits)
                if (Player* player = ObjectAccessor::GetPlayer(*caster, guid))
                    player->CastSpell(player, RingOfBootySpells::ShellBounceDmg, true);

            /// Walls
            float posX = at->GetPositionX() + 1.0f * cos(at->GetOrientation());
            float posY = at->GetPositionY() + 1.0f * sin(at->GetOrientation());

            if (!at->IsWithinLOS(posX, posY, at->GetPositionZ()))
            {
                float rotation = at->GetOrientation();
                float range = frand(10.0f, 30.0f);

                Position dest =
                {
                    at->GetPositionX() + (range * cos(rotation + float(M_PI))),
                    at->GetPositionY() + (range * cos(rotation + float(M_PI))),
                    at->m_positionZ
                };

                at->SetDestination(dest, 12000);
            }
        }
    }

    void OnDestinationReached() override
    {
        float rotation = at->GetOrientation();
        float range = frand(10.0f, 30.0f);

        Position dest =
        {
            at->GetPositionX() + (range * cos(rotation + float(M_PI))),
            at->GetPositionY() + (range * cos(rotation + float(M_PI))),
            at->m_positionZ
        };

        at->SetDestination(dest, 12000);
    }
};

///Spell 256494  Rearm Areatriger ID 11954
struct at_rearm_trothak : AreaTriggerAI
{
    at_rearm_trothak(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnInitialize() override
    {
        at->SetPeriodicProcTimer(500);
    }

    void OnPeriodicProc() override
    {
        if (Unit* caster = at->GetCaster())
        {
            GuidUnorderedSet const& insideUnits = at->GetInsideUnits();

            for (ObjectGuid guid : insideUnits)
                if (Player* player = ObjectAccessor::GetPlayer(*caster, guid))
                    caster->CastSpell(player, RingOfBootySpells::RearmDmg, true);
        }
    }
};

///Spell 272548  Rearm Areatriger ID 13654
struct at_bloody_mess : AreaTriggerAI
{
    at_bloody_mess(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit)
    {
        if (Player* player = unit->ToPlayer())
            if (!player->HasAura(RingOfBootySpells::BloodyMess))
                player->CastSpell(player, RingOfBootySpells::BloodyMess, true);
    }

    void OnUnitExit(Unit* unit)
    {
        unit->RemoveAurasDueToSpell(RingOfBootySpells::BloodyMess);
    }
};

void AddSC_boss_ring_of_booty()
{
    ///Creature
    RegisterCreatureAI(npc_gukguk);
    RegisterCreatureAI(npc_gurgthock);
    RegisterCreatureAI(npc_davey);
    RegisterCreatureAI(npc_lightning);
    RegisterCreatureAI(npc_ludwig_von_tortollan);
    RegisterCreatureAI(boss_trothak);
    RegisterCreatureAI(npc_shark_trothak);
    ///Areatrigger
    RegisterAreaTriggerAI(at_shell_bounce);
    RegisterAreaTriggerAI(at_rearm_trothak);
    RegisterAreaTriggerAI(at_bloody_mess);
}