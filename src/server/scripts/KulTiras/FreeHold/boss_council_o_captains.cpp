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

 //Missing scripts

#include "freehold.h"
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

enum CouncilCaptainSpells
{
    UnderOneBanner = 257821, ///Cast if you fight with the 3 boss
    BilgeRatBrew = 281357, ///This will get players drunk for 1 minute
    ///Captain Raoul Fight
    BlackoutBarrel = 258338,
    BlackoutBarrelVehicleAura = 258875,
    BarrelSmash = 256589,
    ///Captain Eudora Fight
    PowderShot = 256979,
    Grapeshot = 258381,
    GrapeShotFire = 258352,
    ///Captain Jolly Fight
    CuttingSurgeCast = 267522,
    CuttingSurge = 267523,
    WhirlpoolofBlades = 272397,
    WhirlpoolofBladesMissile = 267533,
    ///Allied Captain Buff
    ChainShot = 272902, /// Casted by Captain Eudora if she is Allied
    TappedKeg = 272884, /// Casted by Captain Raoul if he is Allied
    TappedKegBuff = 272900,
    TradeWindsVigor = 281329, /// Casted by Captain Jolly if he is Allied
    ///Heroic Mode
    ConfidenceBoostingFreeholdBrew = 265086, ///On Heroic difficulty, the nearby bartender Rummy Mancomb will throw beverages 
    InvigoratingFreeholdBrew = 264715, ///to the location of a randomly selected boss. These beverages will apply a buff 
    CausticFreeholdBrew = 265171  ///to any boss or player that stands within them.
};

uint32 HeroicSpell[3]{ ConfidenceBoostingFreeholdBrew, InvigoratingFreeholdBrew, CausticFreeholdBrew };

enum CouncilCaptainEvents
{
    ///Raoul Enemy Events
    EventBlackoutBarrel,
    EventBarrelSmash,
    ///Eudora Enemy Events
    EventPowderShot,
    EventGrapeshotJump,
    EventGrapeshotFire,
    ///Jolly Enemy Events
    EventCuttingSurge,
    EventWhirlpoolofBlades,
    ///Allied Buff
    EventAlliedBuff,
    ///Heroic Difficulty
    EventLaunchBrew,
    ///Check Player
    EventCheckPlayers ///Is necesary because whit a captain friendly never end the fight
};

enum CouncilCaptainAction
{
    ActionResetRummy,
    ActionStartLaunchBrew
};

enum CouncilCaptainMovementPoint
{
    JumpPoint,
};

enum TextEudora
{
    TalkDeadEudora = 0,
    TalkAggroEudora,
};

enum TextJolly
{
    TalkWhirpoolBlade = 0,
    TalkCuttingSurge,
    TalkDeadJolly,
    TalkAggroJolly,
};

enum TextRaoul
{
    TalkAggroRaoul = 0
};

enum Actions
{
    ACTION_COUNT_DEATHS = 1,
};


///ToDo Script the event with the other 2 boss when become allied, need sniff and info about how they become allied, only did Raoul Allied
///This work like Cache of Madness in Zulgurub a different allied by week, is good did that by GameEvent

Position const CouncilTributePos = { -1784.44f, -684.403f, 38.517f,	3.15363f };

struct npc_captains_controller : public ScriptedAI
{
    npc_captains_controller(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
        m_Instance = creature->GetInstanceScript();

        SetCombatMovement(false);
    }

    void Initialize()
    {
        summonChest = false;
        captainsDeathCount = 0;
    }

    InstanceScript* m_Instance;

    uint8 captainsDeathCount;
    bool summonChest;

    void InitializeAI() override
    {
        me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
        me->AddUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
        me->AddUnitState(UNIT_STATE_STUNNED);

        ScriptedAI::InitializeAI();
    }

    void Reset() override
    {
        Initialize();
    }
    
     void DoAction(int32 action)
    {
        switch (action)
        {
        case ACTION_COUNT_DEATHS:
            ++captainsDeathCount;
            break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (instance)
        {
            if (captainsDeathCount > 2 && instance->GetBossState(FreeholdData::DataCounciloCaptains) != DONE)
            {
                if (!summonChest)
                {
                    Map::PlayerList const& PlayerList = me->GetMap()->GetPlayers();
                    if (!PlayerList.isEmpty())
                    {
                        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                        {
                            Player* player = i->GetSource();
                            player->SummonGameObject(FreeholdGameObject::GoCouncilTribute, CouncilTributePos, QuaternionData(), 0);
                            summonChest = true;
                            break;
                        }
                    }
                }
                instance->SetBossState(FreeholdData::DataCounciloCaptains, DONE);
            }
        }
    }
};

/// 126845 Captain Jolly, 126848 Captain Eudora, 126847 Captain Raoul
struct boss_council_captain : public BossAI
{
    boss_council_captain(Creature* creature) : BossAI(creature, FreeholdData::DataCounciloCaptains)
    {
        m_Instance = creature->GetInstanceScript();
        captainRaoulActivated = false;
        reset = false;
    }

    InstanceScript* m_Instance;

    void Reset() override
    {
        reset = false;
        grapershotcount = 0;
        resetFight = true;
        evadeModeActivated = false;
        me->ResetLootMode();
        events.Reset();
        summons.DespawnAll();
        me->RemoveAllAreaTriggers();
        me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
        me->AddUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
        if (instance)
        {
            instance->SetBossState(FreeholdData::DataCounciloCaptains, NOT_STARTED);
        }

        if (Creature* jolly = m_Instance->instance->GetCreature(m_Instance->GetGuidData(FreeholdCreature::NpcCaptainJolly)))
        {
            if (Creature* raoul = m_Instance->instance->GetCreature(m_Instance->GetGuidData(FreeholdCreature::NpcCaptainRaoul)))
            {
                if (Creature* eudora = m_Instance->instance->GetCreature(m_Instance->GetGuidData(FreeholdCreature::NpcCaptainEudora)))
                {
                    if (jolly->isDead())
                    {
                        jolly->Respawn();
                        jolly->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
                        jolly->GetMotionMaster()->MoveTargetedHome();
                    }
                    if (raoul->isDead())
                    {
                        raoul->Respawn();
                        raoul->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
                        raoul->GetMotionMaster()->MoveTargetedHome();
                    }
                    if (eudora->isDead())
                    {
                        eudora->Respawn();
                        eudora->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
                        eudora->GetMotionMaster()->MoveTargetedHome();
                    }
                }
            }
        }

        me->SetReactState(REACT_DEFENSIVE);
        me->SetFaction(FreeHoldFaction::FactionEnemy);

        AddTimedDelayedOperation(3 * TimeConstants::IN_MILLISECONDS, [this]() -> void
            {
                if (captainRaoulActivated && me->GetEntry() == FreeholdCreature::NpcCaptainRaoul)
                {
                    me->SetFaction(FreeHoldFaction::FactionFriendlyFake);
                    me->RemoveAura(CouncilCaptainSpells::UnderOneBanner);
                }

                checkFaction();
                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
            });
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        ///Avoid enter two time here
        if (evadeModeActivated || !reset)
            return;

        evadeModeActivated = true;
        me->AttackStop();
        me->CastStop();
        me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
        me->InterruptNonMeleeSpells(true);
        me->SetReactState(ReactStates::REACT_PASSIVE);
        me->DeleteThreatList();
        me->GetMotionMaster()->Clear();
        me->GetMotionMaster()->MoveTargetedHome();

        // Reset the controller
        if (Creature* capControl = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DataCaptainsController)))
            ENSURE_AI(npc_captains_controller, capControl->AI())->Reset();
    }

    void JustReachedHome() override
    {
        _JustReachedHome();
        instance->SetBossState(FreeholdData::DataCounciloCaptains, FAIL);
        Reset();
    }

    void EnterCombat(Unit* who) override
    {
        if (instance)
        {
            // bosses do not respawn, check only on enter combat
            if (!instance->CheckRequiredBosses(me->GetEntry()))
            {
                EnterEvadeMode(EVADE_REASON_SEQUENCE_BREAK);
                return;
            }
            instance->SetBossState(FreeholdData::DataCounciloCaptains, IN_PROGRESS);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        }
        me->setActive(true);
        CaptainEnterCombat();
        reset = true;

        switch (me->GetEntry())
        {
        case FreeholdCreature::NpcCaptainJolly:
        {
            Talk(TextJolly::TalkAggroJolly);
            if (me->getFaction() == FreeHoldFaction::FactionEnemy)
            {
                events.ScheduleEvent(CouncilCaptainEvents::EventCuttingSurge, urand(3000, 5000));
                events.ScheduleEvent(CouncilCaptainEvents::EventWhirlpoolofBlades, 8000);
            }
            else
                events.ScheduleEvent(CouncilCaptainEvents::EventAlliedBuff, 8000);
            break;
        }
        case FreeholdCreature::NpcCaptainEudora:
        {
            Talk(TextEudora::TalkAggroEudora);
            if (me->getFaction() == FreeHoldFaction::FactionEnemy)
            {
                events.ScheduleEvent(CouncilCaptainEvents::EventPowderShot, urand(3000, 5000));
                events.ScheduleEvent(CouncilCaptainEvents::EventGrapeshotJump, 8000);
            }
            else
                events.ScheduleEvent(CouncilCaptainEvents::EventAlliedBuff, 8000);
            break;
        }
        case FreeholdCreature::NpcCaptainRaoul:
        {
            Talk(TextRaoul::TalkAggroRaoul);
            if (me->getFaction() == FreeHoldFaction::FactionEnemy)
            {
                events.ScheduleEvent(CouncilCaptainEvents::EventBlackoutBarrel, urand(3000, 5000));
                events.ScheduleEvent(CouncilCaptainEvents::EventBarrelSmash, 8000);
            }
            else
                events.ScheduleEvent(CouncilCaptainEvents::EventAlliedBuff, 8000);
            break;
        }
        }

        events.ScheduleEvent(CouncilCaptainEvents::EventCheckPlayers, 1000);

        checkFaction();
    }

    void DoAction(int32 const action) override
    {
        if (action == FreeholdAction::ActionSelectCaptainRaoul)
        {
            if (me->GetEntry() == FreeholdCreature::NpcCaptainRaoul)
            {
                me->SetFaction(FreeHoldFaction::FactionFriendlyFake);
                checkFaction();
                captainRaoulActivated = true;
            }
        }
    }
    
     Creature* GetController()
    {
        return me->FindNearestCreature(NpcCaptainsController, 500.0f);
    }

    void JustDied(Unit* killer) override
    {
        switch (me->GetEntry())
        {
        case FreeholdCreature::NpcCaptainJolly:
        {
            Talk(TextJolly::TalkDeadJolly);
            break;
        }
        case FreeholdCreature::NpcCaptainEudora:
        {
            Talk(TextEudora::TalkDeadEudora);
            break;
        }
        }
        
        if (Creature* controller = GetController())
        {
            controller->AI()->DoAction(ACTION_COUNT_DEATHS);
        }
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != EFFECT_MOTION_TYPE) ///Jump Effect
            return;

        switch (pointId)
        {
        case CouncilCaptainMovementPoint::JumpPoint:
        {
            events.ScheduleEvent(CouncilCaptainEvents::EventGrapeshotFire, 500);
            break;
        }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (instance->GetBossState(FreeholdData::DataSkycapKragg) == DONE)
        {
            me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
            me->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
        }

        UpdateOperations(diff);
        if (!UpdateVictim() && me->getFaction() == FreeHoldFaction::FactionEnemy)
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case CouncilCaptainEvents::EventBlackoutBarrel:
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
                    me->CastSpell(target, CouncilCaptainSpells::BlackoutBarrel, false);

                events.Repeat(8000);
                break;
            }
            case CouncilCaptainEvents::EventBarrelSmash:
            {
                me->CastSpell(me, CouncilCaptainSpells::BarrelSmash, false);

                events.Repeat(8000);
                break;
            }
            case CouncilCaptainEvents::EventPowderShot:
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                    me->CastSpell(target, CouncilCaptainSpells::PowderShot, false);

                events.Repeat(8000);
                break;
            }
            case CouncilCaptainEvents::EventGrapeshotJump:
            {
                me->StopMoving();
                me->AttackStop();
                me->CastStop();
                me->SetReactState(REACT_PASSIVE);
                me->GetMotionMaster()->MoveJump(GetRandomPositionAround(), 10.0f, 10.0f, CouncilCaptainMovementPoint::JumpPoint);
                break;
            }
            case CouncilCaptainEvents::EventGrapeshotFire:
            {
                grapershotcount++;
                if (grapershotcount < 6) ///Aprox 5 shoots
                {
                    events.CancelEvent(CouncilCaptainEvents::EventGrapeshotJump);
                    events.CancelEvent(CouncilCaptainEvents::EventPowderShot);
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                    {
                        me->SetFacingToObject(target);
                        me->CastSpell(target, CouncilCaptainSpells::GrapeShotFire, false);
                    }

                    events.Repeat(1500);
                }
                else
                {
                    me->SetReactState(REACT_AGGRESSIVE);
                    grapershotcount = 0;
                    events.ScheduleEvent(CouncilCaptainEvents::EventPowderShot, urand(3000, 5000));
                    events.ScheduleEvent(CouncilCaptainEvents::EventGrapeshotJump, 15000);
                }
                break;
            }
            case CouncilCaptainEvents::EventCuttingSurge:
            {
                Talk(TextJolly::TalkCuttingSurge);
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                    me->CastSpell(target, CouncilCaptainSpells::CuttingSurgeCast, false);

                events.Repeat(15000);
                break;
            }
            case CouncilCaptainEvents::EventWhirlpoolofBlades:
            {
                Talk(TextJolly::TalkWhirpoolBlade);
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                    me->CastSpell(target, CouncilCaptainSpells::WhirlpoolofBladesMissile, false);

                events.Repeat(15000);
                break;
            }
            case CouncilCaptainEvents::EventCheckPlayers:
            {
                Map::PlayerList const& PlayerList = me->GetMap()->GetPlayers();
                if (!PlayerList.isEmpty())
                {
                    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    {
                        Player* player = i->GetSource();
                        if (player->IsAlive() && player->IsInCombat())
                        {
                            resetFight = false;
                            break;
                        }
                        else
                            resetFight = true;
                    }
                }

                if (resetFight)
                    if (Creature* jolly = m_Instance->instance->GetCreature(m_Instance->GetGuidData(FreeholdCreature::NpcCaptainJolly)))
                    {
                        if (Creature* raoul = m_Instance->instance->GetCreature(m_Instance->GetGuidData(FreeholdCreature::NpcCaptainRaoul)))
                        {
                            if (Creature* eudora = m_Instance->instance->GetCreature(m_Instance->GetGuidData(FreeholdCreature::NpcCaptainEudora)))
                            {
                                jolly->AI()->EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
                                raoul->AI()->EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
                                eudora->AI()->EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
                            }
                        }
                    }

                events.Repeat(1000);
                break;
            }
            case CouncilCaptainEvents::EventAlliedBuff:
            {
                switch (me->GetEntry())
                {
                case FreeholdCreature::NpcCaptainJolly:
                {
                    me->CastSpell(me, CouncilCaptainSpells::TradeWindsVigor, false);
                    break;
                }
                case FreeholdCreature::NpcCaptainEudora:
                {
                    if (urand(0, 1) == 1)
                    {
                        if (Creature* raoul = m_Instance->instance->GetCreature(m_Instance->GetGuidData(FreeholdCreature::NpcCaptainRaoul)))
                        {
                            me->CastSpell(raoul, CouncilCaptainSpells::ChainShot, false);
                        }
                    }
                    else if (Creature* jolly = m_Instance->instance->GetCreature(m_Instance->GetGuidData(FreeholdCreature::NpcCaptainJolly)))
                    {
                        me->CastSpell(jolly, CouncilCaptainSpells::ChainShot, false);
                    }
                    break;
                }
                case FreeholdCreature::NpcCaptainRaoul:
                {
                    me->CastSpell(me, CouncilCaptainSpells::TappedKeg, false);
                    break;
                }
                }
                events.Repeat(15000);
                break;
            }
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    bool captainRaoulActivated;
    bool resetFight;
    bool evadeModeActivated;
    bool reset;
    uint8 grapershotcount;

    void checkFaction()
    {
        if (Creature* jolly = m_Instance->instance->GetCreature(m_Instance->GetGuidData(FreeholdCreature::NpcCaptainJolly)))
        {
            if (Creature* raoul = m_Instance->instance->GetCreature(m_Instance->GetGuidData(FreeholdCreature::NpcCaptainRaoul)))
            {
                if (Creature* eudora = m_Instance->instance->GetCreature(m_Instance->GetGuidData(FreeholdCreature::NpcCaptainEudora)))
                {
                    if (jolly->getFaction() == FreeHoldFaction::FactionEnemy && raoul->getFaction() == FreeHoldFaction::FactionEnemy && eudora->getFaction() == FreeHoldFaction::FactionEnemy)
                    {
                        me->CastSpell(me, CouncilCaptainSpells::UnderOneBanner, true);
                    }
                    else
                    {
                        jolly->RemoveAura(CouncilCaptainSpells::UnderOneBanner);
                        raoul->RemoveAura(CouncilCaptainSpells::UnderOneBanner);
                        eudora->RemoveAura(CouncilCaptainSpells::UnderOneBanner);
                    }
                }
            }
        }
    }

    void CaptainEnterCombat()
    {
        if (Creature* jolly = m_Instance->instance->GetCreature(m_Instance->GetGuidData(FreeholdCreature::NpcCaptainJolly)))
        {
            if (Creature* raoul = m_Instance->instance->GetCreature(m_Instance->GetGuidData(FreeholdCreature::NpcCaptainRaoul)))
            {
                if (Creature* eudora = m_Instance->instance->GetCreature(m_Instance->GetGuidData(FreeholdCreature::NpcCaptainEudora)))
                {
                    if (!jolly->IsInCombat())
                        jolly->SetInCombatWithZone();
                    if (!raoul->IsInCombat())
                        raoul->SetInCombatWithZone();
                    if (!eudora->IsInCombat())
                        eudora->SetInCombatWithZone();

                    jolly->SetReactState(REACT_AGGRESSIVE);
                    raoul->SetReactState(REACT_AGGRESSIVE);
                    eudora->SetReactState(REACT_AGGRESSIVE);

                    if (raoul->getFaction() == FreeHoldFaction::FactionFriendlyFake)
                    {
                        if (urand(0, 1) == 1)
                            raoul->AI()->AttackStart(jolly);
                        else
                            raoul->AI()->AttackStart(eudora);
                    }
                    else if (jolly->getFaction() == FreeHoldFaction::FactionFriendlyFake)
                    {
                        if (urand(0, 1) == 1)
                            jolly->AI()->AttackStart(raoul);
                        else
                            jolly->AI()->AttackStart(eudora);
                    }
                    else if (raoul->getFaction() == FreeHoldFaction::FactionFriendlyFake)
                    {
                        captainRaoulActivated = true;

                        if (urand(0, 1) == 1)
                            raoul->AI()->AttackStart(jolly);
                        else
                            raoul->AI()->AttackStart(eudora);
                    }
                }
            }
        }
    }

    Position GetRandomPositionAround()
    {
        float distMin = 18.0f;
        float distMax = 20.0f;
        double angle = rand_norm() * 2.0 * M_PI;
        float x = me->GetPositionX() + (float)(frand(distMin, distMax) * std::sin(angle));
        float y = me->GetPositionY() + (float)(frand(distMin, distMax) * std::cos(angle));
        float z = me->GetPositionZ();
        me->UpdateAllowedPositionZ(x, y, z);
        return { x, y, z };
    }
};

/// 133219 - Npc Rummy Mancomb
struct npc_rummy_mancomb : public ScriptedAI
{
    npc_rummy_mancomb(Creature* creature) : ScriptedAI(creature) { }

    void Reset()
    {
        me->SetReactState(REACT_PASSIVE);
        me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
    }

    void DoAction(int32 const action) override
    {
        switch (action)
        {
        case CouncilCaptainAction::ActionStartLaunchBrew:
        {
            events.ScheduleEvent(CouncilCaptainEvents::EventLaunchBrew, 8000);
            break;
        }
        case CouncilCaptainAction::ActionResetRummy:
        {
            me->SetReactState(REACT_PASSIVE);
            me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
            events.Reset();
            me->DeleteThreatList();
            break;
        }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case CouncilCaptainEvents::EventLaunchBrew:
            {
                std::list<Unit*> targetList;
                Trinity::AnyUnitInObjectRangeCheck check(me, 50.0f);
                Trinity::UnitListSearcher<Trinity::AnyUnitInObjectRangeCheck> searcher(me, targetList, check);
                Cell::VisitGridObjects(me, searcher, 50.0f);

                if (targetList.empty())
                    return;

                targetList.remove_if([this](Unit* unit) -> bool
                    {
                        if (!unit)
                            return true;

                        if (unit->GetEntry() == FreeholdCreature::NpcCaptainRaoul || unit->GetEntry() == FreeholdCreature::NpcCaptainEudora || unit->GetEntry() == FreeholdCreature::NpcCaptainJolly)
                            return false;

                        return true;
                    });

                if (Unit* target = Trinity::Containers::SelectRandomContainerElement(targetList))
                    me->CastSpell(target, HeroicSpell[urand(0, 2)], true);

                events.Repeat(5000);
                break;
            }
            }
        }
    }
};

/// 130896 - Blackout Barrel
struct npc_blackout_barrel : public ScriptedAI
{
    npc_blackout_barrel(Creature* creature) : ScriptedAI(creature) { }

    void IsSummonedBy(Unit* summoner) override
    {
        me->SetReactState(REACT_PASSIVE);
        AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void
            {
                me->CastSpell(me, CouncilCaptainSpells::BlackoutBarrelVehicleAura, true);
            });
    }

    void UpdateAI(uint32 const diff) override
    {
        UpdateOperations(diff);
    }
};

///258875 Blackout Barrel
class spell_blackout_vehicle : public SpellScript
{
    PrepareSpellScript(spell_blackout_vehicle);


    void FilterTargetsNoTanks(std::list<WorldObject*>& unitList)
    {
        unitList.remove_if([](WorldObject* object) -> bool
            {
                if (!object->ToPlayer())
                    return true;

                if (object->ToPlayer()->GetRoleForGroup() == Roles::ROLE_TANK)
                    return true;

                return false;
            });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_blackout_vehicle::FilterTargetsNoTanks, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_blackout_vehicle::FilterTargetsNoTanks, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_blackout_vehicle::FilterTargetsNoTanks, EFFECT_2, TARGET_UNIT_SRC_AREA_ENEMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_blackout_vehicle::FilterTargetsNoTanks, EFFECT_3, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

///281329 Trade Wind's Vigor
class spell_trade_winds_vigor : public SpellScript
{
    PrepareSpellScript(spell_trade_winds_vigor);


    void FilterTargets(std::list<WorldObject*>& unitList)
    {
        unitList.remove_if([](WorldObject* object) -> bool
            {
                if (!object->ToPlayer())
                    return true;

                return false;
            });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_trade_winds_vigor::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

///Spell 272884 Vile Bombardment Areatriger ID 13674
struct at_tapped_keg : AreaTriggerAI
{
    at_tapped_keg(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit)
    {
        if (Player* player = unit->ToPlayer())
            if (!player->HasAura(CouncilCaptainSpells::TappedKegBuff))
                player->CastSpell(player, CouncilCaptainSpells::TappedKegBuff, true);
    }

    void OnUnitExit(Unit* unit)
    {
        unit->RemoveAurasDueToSpell(CouncilCaptainSpells::TappedKegBuff);
    }
};

///Spell 272377  Whirlpool of Blades Areatriger ID 13632
struct at_whirlpool_of_blades : AreaTriggerAI
{
    at_whirlpool_of_blades(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnInitialize() override
    {
        at->SetPeriodicProcTimer(1000);
    }

    void OnPeriodicProc() override
    {
        if (Unit* caster = at->GetCaster())
        {
            GuidUnorderedSet const& insideUnits = at->GetInsideUnits();

            for (ObjectGuid guid : insideUnits)
                if (Player* player = ObjectAccessor::GetPlayer(*caster, guid))
                    player->CastSpell(player, CouncilCaptainSpells::WhirlpoolofBlades, true);
        }
    }
};

void AddSC_boss_council_o_captains()
{
    ///Creature
    RegisterCreatureAI(boss_council_captain);
    RegisterCreatureAI(npc_rummy_mancomb);
    RegisterCreatureAI(npc_blackout_barrel);
    RegisterCreatureAI(npc_captains_controller);
    ///Spell
    RegisterSpellScript(spell_blackout_vehicle);
    RegisterSpellScript(spell_trade_winds_vigor);
    ///Areatrigger
    RegisterAreaTriggerAI(at_tapped_keg);
    RegisterAreaTriggerAI(at_whirlpool_of_blades);
}
