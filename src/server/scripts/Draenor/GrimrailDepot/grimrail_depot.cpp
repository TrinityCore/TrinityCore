#include "grimrail_depot.h"
#include "Vehicle.h"
#include "GameObject.h"
#include "SceneMgr.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "GridNotifiers.h"

enum eMovementInformed
{
    MovementInformedDashSecondCut = 1,
    MovementInformedDashFinish
};

enum eAction
{
    ActionActivateDashEffect = 1,
    ActionActivateEffect
};

void HandleDoorSpawningOnGrimrailTrain(Unit* p_Victim, InstanceScript* p_InstanceScript)
{
    if (p_InstanceScript != nullptr)
    {
        switch (p_InstanceScript->GetData(GrimrailDepotData::DataIronWroughtGateOnTrainDoorNumber))
        {
        case 1: /// Door 1
            if (p_InstanceScript->GetData(GrimrailDepotData::DataIronWroughtGateOnTrainCount) < 3)
                p_InstanceScript->SetData(p_InstanceScript->GetData(GrimrailDepotData::DataIronWroughtGateOnTrainCount), p_InstanceScript->GetData(GrimrailDepotData::DataIronWroughtGateOnTrainCount) + 1);
            else if (GameObject* l_IronWroughtGate = p_InstanceScript->instance->GetGameObject(p_InstanceScript->GetGuidData(GrimrailDepotData::DataIronWroughtGate01OnTrain)))
            {
                l_IronWroughtGate->SetLootState(LootState::GO_READY);
                l_IronWroughtGate->UseDoorOrButton(10 * TimeConstants::IN_MILLISECONDS, false, p_Victim);
            }
            break;
        case 2: /// Door 1
            if (p_InstanceScript->GetData(GrimrailDepotData::DataIronWroughtGateOnTrainCount) < 5)
                p_InstanceScript->SetData(p_InstanceScript->GetData(GrimrailDepotData::DataIronWroughtGateOnTrainCount), p_InstanceScript->GetData(GrimrailDepotData::DataIronWroughtGateOnTrainCount) + 1);
            else if (GameObject* l_IronWroughtGate = p_InstanceScript->instance->GetGameObject(p_InstanceScript->GetGuidData(GrimrailDepotData::DataIronWroughtGate02OnTrain)))
            {
                l_IronWroughtGate->SetLootState(LootState::GO_READY);
                l_IronWroughtGate->UseDoorOrButton(10 * TimeConstants::IN_MILLISECONDS, false, p_Victim);
            }
            break;
        default:
            break;
        }
    }
}

/// Assault Cannon - 79548
class grimrail_depot_mob_assault_cannon : public CreatureScript
{
    public:

    grimrail_depot_mob_assault_cannon() : CreatureScript("grimrail_depot_mob_assault_cannon") { }

    struct grimrail_depot_mob_assault_cannonAI : public ScriptedAI
    {
        grimrail_depot_mob_assault_cannonAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

        enum eAssaultCannonEvents
        {
            EventOverHeatedBlast = 1,
            EventReloading,
            EventSuppressiveFire
        };

        enum eAssaultCannonSpells
        {
            SpellOverHeatedBlast = 167589,
            SpellReloading = 160680,
            SpellSuppressiveFire = 160681
        };

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* p_Attacker) override
        {
        }

        void UpdateAI(uint32 const p_Diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(p_Diff);

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;
/*
            switch (events.ExecuteEvent())
            {
            default:
                break;
            }
*/
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new grimrail_depot_mob_assault_cannonAI(p_Creature);
    }
};

/// Grimrail Bombadier - 81407
class grimrail_depot_mob_grimrail_bombadier : public CreatureScript
{
    public:

    grimrail_depot_mob_grimrail_bombadier() : CreatureScript("grimrail_depot_mob_grimrail_bombadier") { }

    struct grimrail_depot_mob_grimrail_bombadierAI : public ScriptedAI
    {
        grimrail_depot_mob_grimrail_bombadierAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

        enum eGrimrailBombadierEvents
        {
            EventBlackrockBombs = 1,
            EventDoubleSlash = 2,
            EventHermoragingWounds = 3
        };

        enum eGrimrailBombadierSpells
        {
            SpellBlackrockBombDummy = 164183,
            SpellBlackrockBombTriggerMissile = 164187,
            SpellBlackrockBombDamage = 164188,
            SpellBlackrockSummon = 168112,
            SpellDoubleSlash = 164218,
            SpellHermoragingWounds = 164241
        };

        void Reset() override
        {
            events.Reset();
            SetCombatMovement(false);
            events.ScheduleEvent(eGrimrailBombadierEvents::EventBlackrockBombs, 3 * TimeConstants::IN_MILLISECONDS);
        }

        void EnterCombat(Unit* p_Attacker) override
        {         
            events.ScheduleEvent(eGrimrailBombadierEvents::EventDoubleSlash, 6 * TimeConstants::IN_MILLISECONDS);
        }

        void UpdateAI(uint32 const p_Diff) override
        {
            events.Update(p_Diff);

            if (events.ExecuteEvent() == eGrimrailBombadierEvents::EventBlackrockBombs)
            {
                std::list<Creature*> l_ListBlackrockBombsTriggers;
                me->GetCreatureListWithEntryInGrid(l_ListBlackrockBombsTriggers, GrimrailDepotCreatures::CreatureBlackrockBombsTriggers, 60.0f);
                if (!l_ListBlackrockBombsTriggers.empty())
                {
                    for (Creature* l_Itr : l_ListBlackrockBombsTriggers)
                    {
                        if (!l_Itr)
                            continue;

                        std::list<Creature*>::const_iterator l_It = l_ListBlackrockBombsTriggers.begin();
                        std::advance(l_It, urand(0, l_ListBlackrockBombsTriggers.size() - 1));

                        me->CastSpell((*l_It), eGrimrailBombadierSpells::SpellBlackrockBombTriggerMissile);
                    }
                }

                events.ScheduleEvent(eGrimrailBombadierEvents::EventBlackrockBombs, 10 * TimeConstants::IN_MILLISECONDS);
            }

            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
            case eGrimrailBombadierEvents::EventBlackrockBombs:
                if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_FARTHEST, 0, 15.0f, true))
                    me->CastSpell(l_Target, eGrimrailBombadierSpells::SpellBlackrockBombTriggerMissile);
                else
                {
                    Position l_Position;
                    l_Position = me->GetRandomNearPosition(30.0f);
                    me->CastSpell(l_Position.GetPositionX(), l_Position.GetPositionY(), l_Position.GetPositionZ(), eGrimrailBombadierSpells::SpellBlackrockBombTriggerMissile, false);
                }

                events.ScheduleEvent(eGrimrailBombadierEvents::EventBlackrockBombs, 5 * TimeConstants::IN_MILLISECONDS);
                break;
            case eGrimrailBombadierEvents::EventDoubleSlash:
                if (Unit* l_Victim = me->GetVictim())
                    me->CastSpell(l_Victim, eGrimrailBombadierSpells::SpellDoubleSlash);

                events.ScheduleEvent(eGrimrailBombadierEvents::EventDoubleSlash, 7 * TimeConstants::IN_MILLISECONDS);
                break;
            default:
                break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new grimrail_depot_mob_grimrail_bombadierAI(p_Creature);
    }
};

/// Grimrail Laborer - 81235
class grimrail_depot_mob_grimrail_laborer : public CreatureScript
{
    public:

    grimrail_depot_mob_grimrail_laborer() : CreatureScript("grimrail_depot_mob_grimrail_laborer") { }

    struct grimrail_depot_mob_grimrail_laborerAI : public ScriptedAI
    {
        grimrail_depot_mob_grimrail_laborerAI(Creature* p_Creature) : ScriptedAI(p_Creature) 
        { 
            m_Instance = p_Creature->GetInstanceScript();
        }

        enum eGrimrailLaborerEvents
        {
            EventHaymaker = 1,
        };

        enum eGrimrailLaborerSpells
        {
            SpellHaymaker = 170099
        };

        InstanceScript* m_Instance;

        void Reset() override
        {
            events.Reset();
        }

        void JustDied(Unit* p_Killer) override
        {
            if (m_Instance != nullptr)
            {
                if (Creature* l_Tovra = m_Instance->instance->GetCreature(m_Instance->GetGuidData(GrimrailDepotData::DataSkyLordTovra)))
                {
                    if (me->IsWithinDistInMap(l_Tovra, 80.0f))
                    {
                        if (l_Tovra->IsAIEnabled)
                            l_Tovra->GetAI()->DoAction(GrimrailDepotActions::ActionCount);
                    }
                }
            }
        }

        void EnterCombat(Unit* p_Attacker) override
        {
            events.ScheduleEvent(eGrimrailLaborerEvents::EventHaymaker, 6 * TimeConstants::IN_MILLISECONDS);
        }

        void UpdateAI(uint32 const p_Diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(p_Diff);

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
            case eGrimrailLaborerEvents::EventHaymaker:
                if (Unit* l_Target = me->GetVictim())
                    events.ScheduleEvent(eGrimrailLaborerEvents::EventHaymaker, 8 * TimeConstants::IN_MILLISECONDS);
                break;
            default:
                break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new grimrail_depot_mob_grimrail_laborerAI(p_Creature);
    }
};

/// Grimrail Overseer - 81212
class grimrail_depot_mob_grimrail_overseer : public CreatureScript
{
    public:

    grimrail_depot_mob_grimrail_overseer() : CreatureScript("grimrail_depot_mob_grimrail_overseer") { }

    struct grimrail_depot_mob_grimrail_overseerAI : public ScriptedAI
    {
        grimrail_depot_mob_grimrail_overseerAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

        enum eGrimrailOverseerEvents
        {
            EventDash = 1,
            EventHewingSwipe
        };

        enum eGrimrailOverseerSpells
        {
            SpellDashDummy = 164168,
            SpellDashCharge = 164170,
            SpellDashDamage = 164171,
            SpellHewingSwipe = 164163,
            SpellMadDashAura = 169225,
        };

        bool m_DashEffect;

        void Reset() override
        {
            events.Reset();
            m_DashEffect = false;
        }

        void EnterCombat(Unit* p_Attacker) override
        {
            events.ScheduleEvent(eGrimrailOverseerEvents::EventDash, 15 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eGrimrailOverseerEvents::EventHewingSwipe, 6 * TimeConstants::IN_MILLISECONDS);
        }

        void MovementInform(uint32 /*p_Type*/, uint32 p_Id) override
        {
            switch (p_Id)
            {
            case eMovementInformed::MovementInformedDashSecondCut:
            {
                Position l_Position;
                l_Position = me->GetFirstCollisionPosition(2.0f, 0.0f);
                me->GetMotionMaster()->MoveCharge(&l_Position, 24.0f, eMovementInformed::MovementInformedDashFinish);
            }
            break;
            case eMovementInformed::MovementInformedDashFinish:
                m_DashEffect = false;
                break;
            default:
                break;
            }
        }

        void DoAction(int32 const p_Action) override
        {
            switch (p_Action)
            {
            case eAction::ActionActivateDashEffect:
                m_DashEffect = true;
                break;
            default:
                break;
            }
        }

        void UpdateAI(uint32 const p_Diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(p_Diff);

            if (m_DashEffect) /// Handles dash damage.
            {
                std::list<Player*> l_ListPlayers;
                me->GetPlayerListInGrid(l_ListPlayers, 1.2f);
                if (!l_ListPlayers.empty())
                {
                    for (Player* l_Itr : l_ListPlayers)
                    {
                        l_Itr->CastSpell(l_Itr, eGrimrailOverseerSpells::SpellDashDamage, true);
                    }
                }
            }

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING) || m_DashEffect)
                return;

            switch (events.ExecuteEvent())
            {
            case eGrimrailOverseerEvents::EventDash:
                if (Unit * l_Random = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
                {
                    me->CastSpell(l_Random, eGrimrailOverseerSpells::SpellDashDummy);
                    me->CastSpell(l_Random, eGrimrailOverseerSpells::SpellMadDashAura);
                }

                events.ScheduleEvent(eGrimrailOverseerEvents::EventDash, 15 * TimeConstants::IN_MILLISECONDS);
                break;
            case eGrimrailOverseerEvents::EventHewingSwipe:
                if (Unit* l_Target = me->GetVictim())
                    me->CastSpell(l_Target, eGrimrailOverseerSpells::SpellHewingSwipe);
                events.ScheduleEvent(eGrimrailOverseerEvents::EventHewingSwipe, 6 * TimeConstants::IN_MILLISECONDS);
                break;
            default:
                break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new grimrail_depot_mob_grimrail_overseerAI(p_Creature);
    }
};

/// Grimrail Scout <Blackfuse Company> - 82590
class grimrail_depot_mob_grimrail_scout : public CreatureScript
{
    public:

    grimrail_depot_mob_grimrail_scout() : CreatureScript("grimrail_depot_mob_grimrail_scout") { }

    struct grimrail_depot_mob_grimrail_scoutAI : public ScriptedAI
    {
        grimrail_depot_mob_grimrail_scoutAI(Creature* p_Creature) : ScriptedAI(p_Creature)
        { 
            m_Instance = p_Creature->GetInstanceScript();
        }

        enum eGrimrailScoutEvents
        {
            EventArcaneBlitz = 1,
            EventScoutingAHead = 2
        };

        enum eGrimrailScoutSpells
        {
            SpellArcaneBlitzAura = 166397,
            SpellArcaneBlitzTriggerMissileA = 166398,
            SpellArcaneBlitzTriggerMissileB = 166399,
            SpellArcaneBlitzDamage = 166404,
            SpellScoutingAHead = 166350,
        };

        InstanceScript* m_Instance;

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* p_Attacker) override
        {
            events.ScheduleEvent(eGrimrailScoutEvents::EventArcaneBlitz, 0 * TimeConstants::IN_MILLISECONDS);
        }

        void JustDied(Unit* p_Killer) override
        {
            if (m_Instance != nullptr)
            {
                if (Creature* l_Tovra = m_Instance->instance->GetCreature(m_Instance->GetGuidData(GrimrailDepotData::DataSkyLordTovra)))
                {
                    if (me->IsWithinDistInMap(l_Tovra, 80.0f))
                    {
                        if (l_Tovra->IsAIEnabled)
                            l_Tovra->GetAI()->DoAction(GrimrailDepotActions::ActionCount);
                    }
                }
            }
        }

        void UpdateAI(uint32 const p_Diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(p_Diff);

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
            case eGrimrailScoutEvents::EventArcaneBlitz:
                if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 100.0f, true))
                     me->CastSpell(me, eGrimrailScoutSpells::SpellArcaneBlitzAura);

                events.ScheduleEvent(eGrimrailScoutEvents::EventArcaneBlitz, 0 * TimeConstants::IN_MILLISECONDS);
                break;
            default:
                break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new grimrail_depot_mob_grimrail_scoutAI(p_Creature);
    }
};

/// Grimrail Technician <Blackfuse Company> - 81236
class grimrail_depot_mob_grimrail_technician : public CreatureScript
{
    public:

    grimrail_depot_mob_grimrail_technician() : CreatureScript("grimrail_depot_mob_grimrail_technician") { }

    struct grimrail_depot_mob_grimrail_technicianAI : public ScriptedAI
    {
        grimrail_depot_mob_grimrail_technicianAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

        enum eGrimrailTechnicianEvents
        {
            Event50kVolts = 1,
            EventActivating
        };

        enum eGrimrailTechnicianSpells
        {
            Spell50kVolts = 164192,
            SpellActivating = 163966
        };

        enum eGrimrailTechnicianMovementInformed
        {
            MovementInformedMoveToActivate = 1
        };

        enum eGrimrailTechnicianActions
        {
            ActionActivate = 1
        };

        ObjectGuid l_TargetGuid;

        void Reset() override
        {
            events.Reset();
            l_TargetGuid = ObjectGuid::Empty;
            ClearDelayedOperations();
        }

        void EnterCombat(Unit* p_Attacker) override
        {
            events.ScheduleEvent(eGrimrailTechnicianEvents::Event50kVolts, 8 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eGrimrailTechnicianEvents::EventActivating, 20 * TimeConstants::IN_MILLISECONDS);
        }

        void DoAction(int32 const p_Action) override
        {
            switch (p_Action)
            {
            case eGrimrailTechnicianActions::ActionActivate:
                {
                    enum eActivatingSpells
                    {
                        SpellActivating = 163966
                    };

                    if (l_TargetGuid != ObjectGuid::Empty)
                    {
                        if (me->IsAIEnabled)
                        {
                            if (Creature* l_Target = ObjectAccessor::GetCreature(*me, l_TargetGuid))
                                me->CastSpell(l_Target, eActivatingSpells::SpellActivating);
                        }
                    }
                    break;
                }
            default:
                break;
            }
        }

        void UpdateAI(uint32 const p_Diff) override
        {
            if (!UpdateVictim())
                return;

            UpdateOperations(p_Diff);
            events.Update(p_Diff);

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;

            if (l_TargetGuid != ObjectGuid::Empty)
                return;

            switch (events.ExecuteEvent())
            {
            case eGrimrailTechnicianEvents::Event50kVolts:
                if (Unit * l_Random = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 100.0f, true))
                    me->CastSpell(l_Random, eGrimrailTechnicianSpells::Spell50kVolts);
                events.ScheduleEvent(eGrimrailTechnicianEvents::Event50kVolts, 15 * TimeConstants::IN_MILLISECONDS);
                break;
            case eGrimrailTechnicianEvents::EventActivating:
            {
                std::list<Creature*> l_ListCreatureStar;
                me->GetCreatureListWithEntryInGrid(l_ListCreatureStar, GrimrailDepotCreatures::CreatureStarMkIII, 15.0f);
                if (!l_ListCreatureStar.empty())
                {
                    std::list<Creature*>::const_iterator l_It = l_ListCreatureStar.begin();
                    std::advance(l_It, urand(0, l_ListCreatureStar.size() - 1));
                    l_TargetGuid = (*l_It)->GetGUID();

                    AddTimedDelayedOperation(3 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                    {
                        if (me->IsAIEnabled)
                            me->GetAI()->DoAction(eGrimrailTechnicianActions::ActionActivate);
                    });

                    AddTimedDelayedOperation(6 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                    {
                        me->SetReactState(ReactStates::REACT_AGGRESSIVE);
                    });

                    me->SetReactState(ReactStates::REACT_PASSIVE);
                    me->GetMotionMaster()->MovePoint(eGrimrailTechnicianMovementInformed::MovementInformedMoveToActivate, (*l_It)->GetPositionX() - 4.2f, (*l_It)->GetPositionY() - 4.2f, (*l_It)->GetPositionZ());
                }
              
                events.ScheduleEvent(eGrimrailTechnicianEvents::EventActivating, 20 * TimeConstants::IN_MILLISECONDS);
                break;
            }
            default:
                break;
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new grimrail_depot_mob_grimrail_technicianAI(p_Creature);
    }
};

/// Iron Star - 73059
class grimrail_depot_iron_star : public CreatureScript
{
    public:

    grimrail_depot_iron_star() : CreatureScript("grimrail_depot_iron_star") { }

    struct grimrail_depot_iron_starAI : public ScriptedAI
    {
        grimrail_depot_iron_starAI(Creature* p_Creature) : ScriptedAI(p_Creature)
        {
            m_Instance = p_Creature->GetInstanceScript();
        }

        enum eIronStarMkIIISpells
        {
            IronStarMkIII = 163971,
            IronStarMkIIICharge = 163979
        };

        enum eIronStarMkIIIEvents
        {
            IronStarMkIIIChargeEvent = 1
        };

        InstanceScript* m_Instance;

        void Reset() override
        {
            me->SetFaction(FriendlyFaction);
            me->SetReactState(ReactStates::REACT_PASSIVE);
            me->SetSpeed(UnitMoveType::MOVE_RUN, 3.8f);
            me->AddUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
        }

        void DoAction(const int32 p_Action) override
        {
            switch (p_Action)
            {
            case eAction::ActionActivateEffect:
            {
                me->CastSpell(me, eIronStarMkIIISpells::IronStarMkIIICharge);
                events.ScheduleEvent(eIronStarMkIIIEvents::IronStarMkIIIChargeEvent, 2 * TimeConstants::IN_MILLISECONDS);
                break;
            }
            default:
                break;
            }
        }

        void UpdateAI(const uint32 p_Diff) override
        {
            events.Update(p_Diff);

            switch (events.ExecuteEvent())
            {
                case eIronStarMkIIIEvents::IronStarMkIIIChargeEvent:
                    me->CastSpell(me, eIronStarMkIIISpells::IronStarMkIII);
                    me->DespawnOrUnsummon(3 * TimeConstants::IN_MILLISECONDS);
                    break;
                default:
                    break;
            }
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new grimrail_depot_iron_starAI(p_Creature);
    }
};


/// Grom'kar Capitan - 82597
class grimrail_depot_mob_gromkar_capitan : public CreatureScript
{
    public:

    grimrail_depot_mob_gromkar_capitan() : CreatureScript("grimrail_depot_mob_gromkar_capitan") { }

    struct grimrail_depot_mob_gromkar_capitanAI : public ScriptedAI
    {
        grimrail_depot_mob_gromkar_capitanAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

        enum eGromkarCapitanEvents
        {
            EventRecklessSlash = 1
        };

        enum eGromkarCapitanSpells
        {
            SpellRecklessSlash = 166380
        };

        void Reset() override
        {
            events.Reset();
        }

        void JustDied(Unit* p_Killer) override
        {
            if (InstanceScript* m_Instance =me->GetInstanceScript())
            {
                if (Creature* l_Tovra = m_Instance->instance->GetCreature(m_Instance->GetGuidData(GrimrailDepotData::DataSkyLordTovra)))
                {
                    if (me->IsWithinDistInMap(l_Tovra, 80.0f))
                    {
                        if (l_Tovra->IsAIEnabled)
                            l_Tovra->GetAI()->DoAction(GrimrailDepotActions::ActionCount);
                    }
                }
            }
        }

        void EnterCombat(Unit* p_Attacker) override
        {
            events.ScheduleEvent(eGromkarCapitanEvents::EventRecklessSlash, 0 * TimeConstants::IN_MILLISECONDS);
        }

        void UpdateAI(const uint32 p_Diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(p_Diff);

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
                case eGromkarCapitanEvents::EventRecklessSlash:
                    events.ScheduleEvent(eGromkarCapitanEvents::EventRecklessSlash, 0 * TimeConstants::IN_MILLISECONDS);
                    break;
                default:
                    break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new grimrail_depot_mob_gromkar_capitanAI(p_Creature);
    }
};

/// Grom'kar Cinderseer - 88163		
class grimrail_depot_mob_gromkar_cinderseer : public CreatureScript
{
    public:

    grimrail_depot_mob_gromkar_cinderseer() : CreatureScript("grimrail_depot_mob_gromkar_cinderseer") { }

    struct grimrail_depot_mob_gromkar_cinderseerAI : public ScriptedAI
    {
        grimrail_depot_mob_gromkar_cinderseerAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

        enum eGromkarCinderseerEvents
        {
            EventFlametongue = 1,
            EventLavaWreath = 2
        };

        enum eGromkarCinderseerSpells
        {
            SpellFlametongueDummy = 176031,
            SpellFlametongueTriggerMissile = 176032,
            SpellFlametongueAura = 176033,
            SpellFlameTongueAreatrigger = 176034,
            SpellFlametongue = 176039,
            SpellLavaWreath = 176027,
            SpellLavaWreathDummy = 176025
        };

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* p_Attacker) override
        {
            events.ScheduleEvent(eGromkarCinderseerEvents::EventFlametongue, 10 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eGromkarCinderseerEvents::EventLavaWreath, 15 * TimeConstants::IN_MILLISECONDS);
        }

        void UpdateAI(uint32 const p_Diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(p_Diff);

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
            case eGromkarCinderseerEvents::EventFlametongue:
                if (Unit* l_Victim = me->GetVictim())
                    me->CastSpell(l_Victim, eGromkarCinderseerSpells::SpellFlametongueTriggerMissile);
                events.ScheduleEvent(eGromkarCinderseerEvents::EventFlametongue, 20 * TimeConstants::IN_MILLISECONDS);
                break;
            case eGromkarCinderseerEvents::EventLavaWreath:
                if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 20.0f, true))
                    me->CastSpell(l_Target, eGromkarCinderseerSpells::SpellLavaWreathDummy);
                events.ScheduleEvent(eGromkarCinderseerEvents::EventLavaWreath, 30 * TimeConstants::IN_MILLISECONDS);
                break;
            default:
                break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new grimrail_depot_mob_gromkar_cinderseerAI(p_Creature);
    }
};

/// Grom'kar Far Seer - 82579
class grimrail_depot_mob_gromkar_farseer : public CreatureScript
{
    public:

    grimrail_depot_mob_gromkar_farseer() : CreatureScript("grimrail_depot_mob_gromkar_farseer") { }

    struct grimrail_depot_mob_gromkar_farseerAI : public ScriptedAI
    {
        grimrail_depot_mob_gromkar_farseerAI(Creature* p_Creature) : ScriptedAI(p_Creature)
        { 
            m_Instance = p_Creature->GetInstanceScript();
        }

        enum eGromkarFarSeerEvents
        {
            EventFarSight = 1,
            EventHealingRain = 2,
            EventStormShield = 3,
            EventThunderZone = 4
        };

        enum eGromkarFarSeerSpells
        {
            SpellFarSight = 166364,
            SpellHealingRain = 166387,
            SpellHealingRainDummy = 166388,
            SpellStormShieldAura = 166335,
            SpellStormShieldDamage = 166336,
            SpellThunderZoneAura = 166340,
            SpellThunderZoneDummy = 166346
        };

        InstanceScript* m_Instance;

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* p_Attacker) override
        {
            events.ScheduleEvent(eGromkarFarSeerEvents::EventStormShield, 8 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eGromkarFarSeerEvents::EventThunderZone, 15 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eGromkarFarSeerEvents::EventHealingRain, 20 * TimeConstants::IN_MILLISECONDS);
        }

        void JustDied(Unit* p_Killer) override
        {
            if (m_Instance != nullptr)
            {
                if (Creature* l_Tovra = m_Instance->instance->GetCreature(m_Instance->GetGuidData(GrimrailDepotData::DataSkyLordTovra)))
                {
                    if (me->IsWithinDistInMap(l_Tovra, 80.0f))
                    {
                        if (l_Tovra->IsAIEnabled)
                            l_Tovra->GetAI()->DoAction(GrimrailDepotActions::ActionCount);
                    }
                }
            }
        }

        void UpdateAI(uint32 const p_Diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(p_Diff);

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
            case eGromkarFarSeerEvents::EventStormShield:
                me->CastSpell(me, eGromkarFarSeerSpells::SpellStormShieldAura);
                events.ScheduleEvent(eGromkarFarSeerEvents::EventStormShield, 16 * TimeConstants::IN_MILLISECONDS);
                break;
            case eGromkarFarSeerEvents::EventHealingRain:
            {
                me->CastSpell(me, eGromkarFarSeerSpells::SpellHealingRainDummy);
                events.ScheduleEvent(eGromkarFarSeerEvents::EventHealingRain, 0 * TimeConstants::IN_MILLISECONDS);
                break;
            }
            case eGromkarFarSeerEvents::EventThunderZone:
                events.ScheduleEvent(eGromkarFarSeerEvents::EventThunderZone, 0 * TimeConstants::IN_MILLISECONDS);
                break;
            default:
                break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new grimrail_depot_mob_gromkar_farseerAI(p_Creature);
    }
};

/// Grom'kar Gunner - 77483
class grimrail_depot_mob_gromkar_gunner : public CreatureScript
{
public:

    grimrail_depot_mob_gromkar_gunner() : CreatureScript("grimrail_depot_mob_gromkar_gunner") { }

    struct grimrail_depot_mob_gromkar_gunnerAI : public ScriptedAI
    {
        grimrail_depot_mob_gromkar_gunnerAI(Creature* p_Creature) : ScriptedAI(p_Creature)
        {
            m_Instance = p_Creature->GetInstanceScript();
        }

        enum eGromkarGunnerEvents
        {
            EventShrapnelBlast = 1
        };

        enum eGromkarGunnerSpells
        {
            SpellShrapnelBlast = 160943
        };

        InstanceScript* m_Instance;

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* p_Attacker) override
        {
            events.ScheduleEvent(eGromkarGunnerEvents::EventShrapnelBlast, 1 * TimeConstants::IN_MILLISECONDS);
        }

        void UpdateAI(uint32 const p_Diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(p_Diff);

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
            case eGromkarGunnerEvents::EventShrapnelBlast:
                if (Unit* l_Target = me->GetVictim())
                    me->CastSpell(l_Target, eGromkarGunnerSpells::SpellShrapnelBlast);

                events.ScheduleEvent(eGromkarGunnerEvents::EventShrapnelBlast, 4 * TimeConstants::IN_MILLISECONDS);
                break;
            default:
                break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new grimrail_depot_mob_gromkar_gunnerAI(p_Creature);
    }
};

/// Grom'kar Hulk - 80938
class grimrail_depot_mob_gromkar_hulk : public CreatureScript
{
public:

    grimrail_depot_mob_gromkar_hulk() : CreatureScript("grimrail_depot_mob_gromkar_hulk") { }

    struct grimrail_depot_mob_gromkar_hulkAI : public ScriptedAI
    {
        grimrail_depot_mob_gromkar_hulkAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

        enum eGromkarHulkEvents
        {
            EventGettingAngry = 1
        };

        enum eGromkarHulkSpells
        {
            SpellGettingAngry = 176023,
            SpellGettingAngryProc = 176024
        };

        void Reset() override
        {
            events.Reset();
            me->CastSpell(me, eGromkarHulkSpells::SpellGettingAngry);
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new grimrail_depot_mob_gromkar_hulkAI(p_Creature);
    }
};

/// Board to Grimrail - 86013
class grimrail_depot_mob_board_to_grimrail : public CreatureScript
{
public:

    grimrail_depot_mob_board_to_grimrail() : CreatureScript("grimrail_depot_mob_board_to_grimrail") { }

    bool OnGossipHello(Player * p_Player, Creature * p_Creature) override
    {
        /// Cut scene and teleport.
        p_Player->GetSceneMgr().PlayScene(GrimrailDepotScenes::SceneBoardToGrimrail);
        p_Player->NearTeleportTo(g_PositionGrimrailTrainTeleport);
        return true;
    }

    struct grimrail_depot_mob_board_to_grimrailAI : public ScriptedAI
    {
        grimrail_depot_mob_board_to_grimrailAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

        enum eBoardToGrimrailSpells
        {
            SpellChainCosmetic = 159086
        };

        void Reset() override
        {
            events.Reset();
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            me->SetReactState(ReactStates::REACT_PASSIVE);
            me->CastSpell(me, eBoardToGrimrailSpells::SpellChainCosmetic);
            SetCombatMovement(false);
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new grimrail_depot_mob_board_to_grimrailAI(p_Creature);
    }
};

/// Dash - 164168  
class grimrail_depot_spell_dash_dummy : public SpellScriptLoader
{
public:

    grimrail_depot_spell_dash_dummy() : SpellScriptLoader("grimrail_depot_spell_dash_dummy") { }

    class grimrail_depot_spell_dash_dummy_SpellScript : public SpellScript
    {
        PrepareSpellScript(grimrail_depot_spell_dash_dummy_SpellScript);

        void HandleDummy(SpellEffIndex /*p_EffIndex*/)
        {
            if (Unit* l_Caster = GetCaster())
            {
                if (Unit* l_Target = GetExplTargetUnit())
                    l_Caster->GetMotionMaster()->MoveCharge(l_Target, 24.0f, eMovementInformed::MovementInformedDashSecondCut);

                if (l_Caster->IsAIEnabled)
                    l_Caster->GetAI()->DoAction(eAction::ActionActivateDashEffect);
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(grimrail_depot_spell_dash_dummy_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new grimrail_depot_spell_dash_dummy_SpellScript();
    }
};

/*
/// Thunder Zone - 166346   
class grimrail_depot_thunder_zone : public SpellScriptLoader
{
    public:

    grimrail_depot_thunder_zone() : SpellScriptLoader("grimrail_depot_thunder_zone") { }

    class grimrail_depot_thunder_zone_SpellScript : public SpellScript
    {
        PrepareSpellScript(grimrail_depot_thunder_zone_SpellScript);

        void HandleDummy(SpellEffIndex p_EffIndex)
        {
            if (Unit* l_Caster = GetCaster())
            {

            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(grimrail_depot_thunder_zone_SpellScript::HandleDummy, SpellEffIndex::EFFECT_0, SpellEffects::SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new grimrail_depot_thunder_zone_SpellScript();
    }
};
*/

/// Activating - 163966 
class grimrail_depot_spell_activating : public SpellScriptLoader
{
public:
    grimrail_depot_spell_activating() : SpellScriptLoader("grimrail_depot_spell_activating") { }

    enum eSpell
    {
        HeavyHandedProc = 156138
    };

    class grimrail_depot_spell_activating_AuraScript : public AuraScript
    {
        PrepareAuraScript(grimrail_depot_spell_activating_AuraScript);

        void OnProc(AuraEffect const* p_AurEff, ProcEventInfo& p_EventInfo)
        {
            PreventDefaultAction();

            if (GetTarget())
            {
                if (GetTarget()->IsAIEnabled)
                    GetTarget()->GetAI()->DoAction(eAction::ActionActivateEffect);
            }
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(grimrail_depot_spell_activating_AuraScript::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new grimrail_depot_spell_activating_AuraScript();
    }
};

/// Shrapnel Blast - 166676
class grimrail_depot_spell_sharpnel_blast : public SpellScriptLoader
{
    public:

    grimrail_depot_spell_sharpnel_blast() : SpellScriptLoader("grimrail_depot_spell_sharpnel_blast") { }

    enum eSpells
    {
        SpellIgnite = 176147
    };

    class grimrail_depot_spell_sharpnel_blast_SpellScript : public SpellScript
    {
        PrepareSpellScript(grimrail_depot_spell_sharpnel_blast_SpellScript);

        void HandleDamage(SpellEffIndex p_EffIndex)
        {
            if (Unit* l_Caster = GetCaster())
            {
                if (Unit* l_Target = GetHitUnit())
                {
                    if (!l_Caster->IsWithinLOSInMap(l_Target))
                        l_Target->CastSpell(l_Target, eSpells::SpellIgnite, true);
                    else
                        SetHitDamage(0);
                }
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(grimrail_depot_spell_sharpnel_blast_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new grimrail_depot_spell_sharpnel_blast_SpellScript();
    }
};

/// Arcane Blitz - 166397 
class grimrail_depot_spell_arcane_blitz : public SpellScriptLoader
{
    public:

    grimrail_depot_spell_arcane_blitz() : SpellScriptLoader("grimrail_depot_spell_arcane_blitz") { }

    class grimrail_depot_spell_arcane_blitz_AuraScript : public AuraScript
    {
        PrepareAuraScript(grimrail_depot_spell_arcane_blitz_AuraScript);

        enum eWardenChainAuras
        {
            SpellArcaneBlitzTriggerMissile = 166398
        };

        void HandlePeriodic(AuraEffect const* p_AurEff)
        {
            if (Unit* l_Target = GetTarget())
                l_Target->AddAura(eWardenChainAuras::SpellArcaneBlitzTriggerMissile, l_Target);
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(grimrail_depot_spell_arcane_blitz_AuraScript::HandlePeriodic, SpellEffIndex::EFFECT_0, AuraType::SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new grimrail_depot_spell_arcane_blitz_AuraScript();
    }
};

/// Flametongue - 176033    176033 AT 3434
class grimrail_depot_at_flametongue : public AreaTriggerEntityScript
{
    public:

        grimrail_depot_at_flametongue() : AreaTriggerEntityScript("grimrail_depot_at_flametongue") { }

    enum eBurningArrowSpells
    {
        SpellFlameTongueAura = 176033
    };

    struct grimrail_depot_at_flametongue_AI : public AreaTriggerAI
    {
        explicit grimrail_depot_at_flametongue_AI(AreaTrigger* at) : AreaTriggerAI(at)
        {
            m_Targets.clear();
        }

        std::list<ObjectGuid> m_Targets;
        uint32 m_Timer = 2 * TimeConstants::IN_MILLISECONDS;

        void OnRemove() override
        {
            if (m_Targets.empty())
                return;

            for (ObjectGuid l_Guid : m_Targets)
            {
                Unit* l_Target = ObjectAccessor::GetUnit(*at, l_Guid);
                if (l_Target && l_Target->HasAura(eBurningArrowSpells::SpellFlameTongueAura))
                    l_Target->RemoveAura(eBurningArrowSpells::SpellFlameTongueAura);
            }
        }

        void OnUpdate(uint32 diff) override
        {
            if (m_Timer <= diff)
            {
                std::list<Player*> l_PlayerList;

                l_PlayerList = at->SelectNearestPlayers(2.0f);

                if (l_PlayerList.empty())
                    return;

                for (auto l_Itr : l_PlayerList)
                {
                    if (!l_Itr->HasAura(eBurningArrowSpells::SpellFlameTongueAura))
                    {
                        l_Itr->CastSpell(l_Itr, eBurningArrowSpells::SpellFlameTongueAura, true);
                        m_Targets.push_back(l_Itr->GetGUID());
                    }
                }

                m_Timer = 1 * TimeConstants::IN_MILLISECONDS;
            }
            else
                m_Timer -= diff;
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* at) const override
    {
        return new grimrail_depot_at_flametongue_AI(at);
    }
};

/// Healing Rain - 166387  AT 1697
class grimrail_depot_at_healing_rain : public AreaTriggerEntityScript
{
    public:

        grimrail_depot_at_healing_rain() : AreaTriggerEntityScript("grimrail_depot_at_healing_rain") { }

    enum eSpell
    {
        SpellHealingRainHeal = 142924,
    };

    struct grimrail_depot_at_healing_rain_AI : public AreaTriggerAI
    {
        explicit grimrail_depot_at_healing_rain_AI(AreaTrigger* at) : AreaTriggerAI(at) {   }

        std::set<ObjectGuid> m_AffectedPlayers;
        uint32 l_Diff = 3 * TimeConstants::IN_MILLISECONDS;

        void OnUpdate(uint32 diff) override
        {
            if (Unit* caster = at->GetCaster())
            {
                std::list<Unit*> templist;
                float l_Radius = 3.0f;

                if (l_Diff <= diff)
                {                 
                    Trinity::AnyFriendlyUnitInObjectRangeCheck checker(caster, caster, l_Radius);
                    Trinity::UnitListSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> searcher(caster, templist, checker);
                    Cell::VisitAllObjects(caster, searcher, l_Radius);

                    if (!templist.empty())
                    {
                        for (Unit* l_Itr : templist)
                        {
                            if (!l_Itr)
                                continue;

                            caster->CastSpell(l_Itr, eSpell::SpellHealingRainHeal);
                        }
                    }

                    l_Diff = 3 * TimeConstants::IN_MILLISECONDS;
                }
                else
                    l_Diff -= diff;
            }
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* at) const override
    {
        return new grimrail_depot_at_healing_rain_AI(at);
    }
};

/// Thunder Zone - 166341  AT 2739
class grimrail_depot_at_thunder_zone : public AreaTriggerEntityScript
{
public:

    grimrail_depot_at_thunder_zone() : AreaTriggerEntityScript("grimrail_depot_at_thunder_zone") { }

    enum eSpell
    {
       SpellThunderZoneDot = 166340
    };

    struct grimrail_depot_at_thunder_zone_AI : public AreaTriggerAI
    {
        explicit grimrail_depot_at_thunder_zone_AI(AreaTrigger* at) : AreaTriggerAI(at)  {      }

        std::set<ObjectGuid> m_AffectedPlayers;
        uint32 l_Diff = 3 * TimeConstants::IN_MILLISECONDS;

        void OnUpdate(uint32 diff) override
        {
            if (Unit* caster = at->GetCaster())
            {
                std::list<Unit*> l_TargetList;
                float l_Radius = 2.0f;

                if (l_Diff <= diff)
                {
                    Trinity::AnyFriendlyUnitInObjectRangeCheck checker(caster, caster, l_Radius);
                    Trinity::UnitListSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> searcher(caster, l_TargetList, checker);
                    Cell::VisitAllObjects(caster, searcher, l_Radius);

                    if (!l_TargetList.empty())
                    {
                        for (Unit* l_Itr : l_TargetList)
                        {
                            if (!l_Itr)
                                continue;

                            caster->CastSpell(l_Itr, eSpell::SpellThunderZoneDot);
                        }
                    }

                    l_Diff = 3 * TimeConstants::IN_MILLISECONDS;
                }
                else
                    l_Diff -= diff;
            }
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* at) const override
    {
        return new grimrail_depot_at_thunder_zone_AI(at);
    }
};

void AddSC_grimrail_depot()
{
    new grimrail_depot_mob_assault_cannon();          /// 79548
    new grimrail_depot_mob_grimrail_bombadier();      /// 81407
    new grimrail_depot_mob_grimrail_laborer();        /// 81235
    new grimrail_depot_mob_grimrail_overseer();       /// 81212
    new grimrail_depot_mob_gromkar_gunner();          /// 77483
    new grimrail_depot_mob_grimrail_scout();          /// 82590
    new grimrail_depot_mob_grimrail_technician();     /// 81236
    new grimrail_depot_mob_gromkar_capitan();         /// 82597
    new grimrail_depot_mob_gromkar_cinderseer();      /// 88163
    new grimrail_depot_mob_gromkar_farseer();         /// 82579
    new grimrail_depot_mob_gromkar_hulk();            /// 80938
    new grimrail_depot_spell_dash_dummy();            /// 164168
    new grimrail_depot_spell_sharpnel_blast();		  /// 166676
    new grimrail_depot_spell_arcane_blitz();          /// 166397 
    new grimrail_depot_spell_activating();            /// 163966
    new grimrail_depot_at_flametongue();              /// [176033] 176034 AT 3434
    new grimrail_depot_at_healing_rain();             /// 166387  AT 1697
    new grimrail_depot_at_thunder_zone();             /// 166341  AT 2739
}
