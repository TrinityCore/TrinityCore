#include "grimrail_depot.h"
#include "MoveSplineInit.h"
#include "Vehicle.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "GameObject.h"

enum eSkylordTorvaTalks
{
	TalkAggro = 1,        ///< Rakun, lets give'em hell! [45878]
	TalkDeath,            ///< You ... Can't ... [45879]
	TalkGeneralEvent01,   ///< Another one! [45880]
	TalkGeneralEvent02,   ///< Light'em up!  [45881]
	TalkGeneralEvenet03,  ///< Show them what you're made of! [45882]
	TalkIntro,            ///< No body stops the iron Horde, No body [45883]
	TalkKill01,           ///< Hell shockin' [45884]
	TalkKill02            ///< Haaa [45885]
};

enum eSkylordTorvaActions
{
    ActionCombatStartDragonFlight = 1,
    ActionCombatStopDragonFlight
};

enum eSkylordTorvaCreatures
{
    CreatureTriggerDiffusedEnergy = 324235,
};

enum eSkylordTorvaMovements
{
    MovementTorvaStartShootingLightning = 1,
    MovementTorvaHomePosition,
    MovementFlyPoint,
};

Position const g_TorvaFirstPosition = {1647.38f, 1956.70f, 121.945f};
Position const g_TorvaHomePosition  = {1647.00f, 2000.29f, 107.789f};

Position const g_DrakePointA = {1646.42f, 1909.48f, 134.486f};
Position const g_DrakePointB = {1636.19f, 2079.83f, 137.453f};

#define g_DrakeDisplay 55447
#define g_TovraDisplay 55630
float g_DrakeOrientationWhileFlightIntro = float(1.524283);

/// SkyLord Torva - 80005
class boss_skylord_torva : public CreatureScript
{
    public:

	boss_skylord_torva() : CreatureScript("boss_skylord_torva") { }

	struct boss_skylord_torvaAI : public BossAI
	{
		boss_skylord_torvaAI(Creature* p_Creature) : BossAI(p_Creature, GrimrailDepotData::DataSkyLordTovra)
		{
            m_Count = 0;
            m_First = false;
            m_Intro = false;
			m_Instance = me->GetInstanceScript();  
		}

		enum eSkylordTorvaSpells
		{
			SpellDiffusedEnergyDummy             = 161558,
			SpellDiffusedEnergyAura              = 161588,
			SpellDiffusedEnergyAreaTrigger       = 161589,
			SpellFreezingSnareAreaTrigger        = 162059,
			SpellFreezingSnareDummy              = 162062,
			SpellFreezingSnareDamage             = 162065,
			SpellFreezingSnare                   = 162066,
			SpellFreezingSnareTriggerMissile     = 162080,
			SpellSpinningSpearDummy              = 162055,
			SpellSpinningSpearDamage             = 162057,
			SpellSpinningSpearAreaTrigger        = 162058,
			SpellFarSight                        = 166364,
			SpellHealingRain                     = 166387,
			SpellHealingRainDummy                = 166388,
			SpellStormShieldAura                 = 166335,
			SpellStormShieldDamage               = 166336,
			SpellThunderZoneAura                 = 166340,
			SpellThunderZoneDummy                = 166346,
			SpellArcaneBlitzAura                 = 166397,
			SpellArcaneBlitzTriggerMissileA      = 166398,
			SpellArcaneBlitzTriggerMissileB      = 166399,
			SpellArcaneBlitzDamage               = 166404,
			SpellScoutingAHead                   = 166350,
            SpellSlagBlast                       = 167036,
            SpellFly                             = 161778,
		};

		enum eSkylordTorvaEvents
		{
			EventDiffusedEnergy = 1,
			EventFreezingSnare,
			EventSpinningSpear,
			EventArcaneBlitz,
			EventScoutingAHead,
			EventFarSight,
			EventHealingRain,
			EventStormShield,
			EventThunderZone 
		};

        InstanceScript* m_Instance;
        uint32 m_Count;
        bool m_First;
        bool m_Intro;

        void Reset() override
        {
            events.Reset();

            if (!m_First)
            {
                m_Count = 0;
                m_First = true;
                ClearDelayedOperations();
                me->SetDisplayId(InvisibleDisplay);
                me->SetReactState(ReactStates::REACT_PASSIVE);
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC));
            }

            HandleDoorCombatActivation();

            if (m_Intro)
            {
                if (m_Instance != nullptr)
                {
                    /// Removes all diffused lightning and Traps
                    std::list<AreaTrigger*> l_AreatriggersList;
                    me->GetAreaTriggerListWithSpellIDInRange(l_AreatriggersList, eSkylordTorvaSpells::SpellDiffusedEnergyAreaTrigger, 200.0f);
                    me->GetAreaTriggerListWithSpellIDInRange(l_AreatriggersList, eSkylordTorvaSpells::SpellFreezingSnareAreaTrigger, 200.0f);
                    if (!l_AreatriggersList.empty())
                    {
                        for (AreaTrigger* l_Itr : l_AreatriggersList)
                        {
                            if (!l_Itr)
                                continue;

                            l_Itr->Remove();
                        }
                    }

                    if (Creature* l_Dragon = m_Instance->instance->GetCreature(m_Instance->GetGuidData(GrimrailDepotData::DataSkyLordTovraDragon)))
                    {
                        if (l_Dragon->IsAIEnabled)
                            l_Dragon->GetAI()->DoAction(eSkylordTorvaActions::ActionCombatStopDragonFlight);

                        if (Vehicle* l_Vehicle = l_Dragon->GetVehicle())
                            l_Vehicle->RemoveAllPassengers();
                    }
                }
            }
        }

        void HandleDoorCombatActivation()
        {
            if (m_Instance != nullptr)
            {
                if (GameObject* l_SkylordTovraDoor = m_Instance->instance->GetGameObject(m_Instance->GetGuidData(GrimrailDepotData::DataSpikedGateSkylordTovraDoor)))
                {
                    /// Activate
                    l_SkylordTovraDoor->SetLootState(LootState::GO_READY);
                    l_SkylordTovraDoor->UseDoorOrButton(10 * TimeConstants::IN_MILLISECONDS, false, me);
                }
            }
        }

        void EnterCombat(Unit* p_Who) override
        {
            if (m_Instance != nullptr)
                m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me);

            HandleDoorCombatActivation();

            if (m_Instance != nullptr)
            {
                if (Creature* l_Dragon = m_Instance->instance->GetCreature(m_Instance->GetGuidData(GrimrailDepotData::DataSkyLordTovraDragon)))
                {
                    if (l_Dragon->IsAIEnabled)
                        l_Dragon->GetAI()->DoAction(eSkylordTorvaActions::ActionCombatStartDragonFlight);

                    if (Vehicle* l_Vehicle = l_Dragon->GetVehicle())
                        l_Vehicle->RemoveAllPassengers(); 
                }
            }

            _EnterCombat();
            Talk(eSkylordTorvaTalks::TalkAggro);

            events.ScheduleEvent(eSkylordTorvaEvents::EventFreezingSnare, 8 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eSkylordTorvaEvents::EventSpinningSpear, 12* TimeConstants::IN_MILLISECONDS);
        }

        void DoAction(int32 const p_Action) override
        {
            switch (p_Action)
            {
            case GrimrailDepotActions::ActionCount:
                if (m_Intro)
                    return;

                m_Count++;
                if (m_Count >= 3)
                {
                    Talk(eSkylordTorvaTalks::TalkIntro);

                    if (m_Instance)
                    {
                        m_Intro = true;
                        me->SetDisplayId(g_TovraDisplay);
                        me->SetHomePosition(g_TorvaHomePosition);
                        me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC));
                        if (Creature* l_Dragon = m_Instance->instance->GetCreature(m_Instance->GetGuidData(GrimrailDepotData::DataSkyLordTovraDragon)))
                        {
                            l_Dragon->SetDisplayId(g_DrakeDisplay);                         
                            l_Dragon->SetHomePosition(g_TorvaHomePosition);
                            l_Dragon->RemoveUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));
                            l_Dragon->GetMotionMaster()->MovePoint(eSkylordTorvaMovements::MovementTorvaStartShootingLightning, g_TorvaFirstPosition);
                        }
                    }
                }
                break;
            default:
                break;
            }
        }

        void KilledUnit(Unit* p_Who) override
        {
            if (p_Who && p_Who->GetTypeId() == TypeID::TYPEID_PLAYER)
            {
                if (roll_chance_i(50))
                    Talk(eSkylordTorvaTalks::TalkKill01);
                else
                    Talk(eSkylordTorvaTalks::TalkKill02);
            }
        }

        void JustDied(Unit* /*p_Killer*/) override
        {
            _JustDied();
            Talk(eSkylordTorvaTalks::TalkDeath);

            AddTimedDelayedOperation(4 * TimeConstants::IN_MILLISECONDS, [this]() -> void
            {
                enum GrimrailDepotScenes
                {
                    SceneEscapeTheTrain = 1345
                };

                if (InstanceScript* m_Instance = me->GetInstanceScript())
                {
                  //  m_Instance->CompleteScenario(); toca añadir la funcion
                    m_Instance->DoPlaySceneOnPlayers(GrimrailDepotScenes::SceneEscapeTheTrain);
                    if (Creature* l_Dragon = m_Instance->instance->GetCreature(m_Instance->GetGuidData(GrimrailDepotData::DataSkyLordTovraDragon)))
                        l_Dragon->DespawnOrUnsummon();
                }
            });
        }

        void UpdateAI(uint32 const p_Diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(p_Diff);
            UpdateOperations(p_Diff);

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
            case eSkylordTorvaEvents::EventSpinningSpear:
                if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 150.0f, true))
                    me->CastSpell(l_Target->GetPositionX(), l_Target->GetPositionY(), me->GetPositionZ(), eSkylordTorvaSpells::SpellSpinningSpearAreaTrigger, true); 

                events.ScheduleEvent(eSkylordTorvaEvents::EventSpinningSpear, 12 * TimeConstants::IN_MILLISECONDS);
                break;
            case eSkylordTorvaEvents::EventFreezingSnare:
  
                l_Position = me->GetRandomNearPosition(4.0f);
                me->CastSpell(l_Position.GetPositionX(), l_Position.GetPositionY(), l_Position.GetPositionZ(), eSkylordTorvaSpells::SpellFreezingSnareTriggerMissile, false);

                events.ScheduleEvent(eSkylordTorvaEvents::EventFreezingSnare, 8 * TimeConstants::IN_MILLISECONDS);
                break;
            default:
                break;
            }

            DoMeleeAttackIfReady();
        }
        Position l_Position;
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new boss_skylord_torvaAI(p_Creature);
    }
};

/// SkyLord Torva - 80005
class grimrail_depot_skylord_tovra_creature_rkuna : public CreatureScript
{
    public:

    grimrail_depot_skylord_tovra_creature_rkuna() : CreatureScript("grimrail_depot_skylord_tovra_creature_rkuna") { }

    struct grimrail_depot_skylord_tovra_creature_rkunaAI : public ScriptedAI
    {
        grimrail_depot_skylord_tovra_creature_rkunaAI(Creature* p_Creature) : ScriptedAI(p_Creature)
        {
            m_Count = 0;
            m_First = false;
            m_Instance = me->GetInstanceScript();          
        }

        enum eSkylordTorvaSpells
        {
            SpellDiffusedEnergyDummy = 161558,
            SpellDiffusedEnergyAura = 161588,
            SpellDiffusedEnergyAreaTrigger = 161589,
            SpellFreezingSnareAreaTrigger = 162059,
            SpellFreezingSnareDummy = 162062,
            SpellFreezingSnareDamage = 162065,
            SpellFreezingSnare = 162066,
            SpellFreezingSnareTriggerMissile = 162080,
            SpellSpinningSpearDummy = 162055,
            SpellSpinningSpearDamage = 162057,
            SpellSpinningSpearAreaTrigger = 162058,
            SpellFarSight = 166364,
            SpellHealingRain = 166387,
            SpellHealingRainDummy = 166388,
            SpellStormShieldAura = 166335,
            SpellStormShieldDamage = 166336,
            SpellThunderZoneAura = 166340,
            SpellThunderZoneDummy = 166346,
            SpellArcaneBlitzAura = 166397,
            SpellArcaneBlitzTriggerMissileA = 166398,
            SpellArcaneBlitzTriggerMissileB = 166399,
            SpellArcaneBlitzDamage = 166404,
            SpellScoutingAHead = 166350,
            SpellSlagBlast = 167036,
            SpellFly = 161778,
        };

        enum eSkylordTorvaEvents
        {
            EventDiffusedEnergy = 1,
            EventInstallAccessories
        };

        enum eSkylordTorvaOneShotAnimKit
        {
            AnimKitFly = 3901
        };

        InstanceScript* m_Instance;
        uint32 m_Count;
        Vehicle* m_Vehicle;
        bool m_First;
        bool m_Flight;
        bool m_Cosmetic;

        void Reset() override
        {
            events.Reset();
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            if (!m_First)
            {
                m_First = true;   
                me->SetFaction(HostileFaction);
                me->SetDisplayId(InvisibleDisplay);
                me->SetReactState(ReactStates::REACT_PASSIVE);
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC));
            }

            m_Flight = true;
            m_Cosmetic = false;
            ClearDelayedOperations();
            me->CastSpell(me, eSkylordTorvaSpells::SpellFly);
            me->SetSpeed(UnitMoveType::MOVE_FLIGHT, 2.5f);
            me->SetAIAnimKitId(eSkylordTorvaOneShotAnimKit::AnimKitFly);

            m_Vehicle = me->GetVehicle();
           // events.ScheduleEvent(eSkylordTorvaEvents::EventInstallAccessories, 2 * TimeConstants::IN_MILLISECONDS);
        }

        void DoAction(int32 const p_Action) override
        {
            switch (p_Action)
            {
            case eSkylordTorvaActions::ActionCombatStartDragonFlight:
                if (m_Flight)
                {
                    m_Flight = false;
                    me->GetMotionMaster()->MoveTakeoff(eSkylordTorvaMovements::MovementFlyPoint, g_DrakePointA);
                }
                else
                {
                    m_Flight = true;
                    me->GetMotionMaster()->MoveTakeoff(eSkylordTorvaMovements::MovementFlyPoint, g_DrakePointB);
                }

                break;
            case eSkylordTorvaActions::ActionCombatStopDragonFlight:
                events.Reset();
                me->CastStop();
                m_Flight = true;
                me->SetDisplayId(g_DrakeDisplay);        
                me->GetMotionMaster()->Clear(true);
                me->GetMotionMaster()->MoveTakeoff(0, me->GetHomePosition());
                break;
            default:
                break;
            }
        }

        void MovementInform(uint32 /*p_Type*/, uint32 p_Id) override
        {
            switch (p_Id)
            {
            case eSkylordTorvaMovements::MovementFlyPoint:
                events.Reset();
                me->SetAIAnimKitId(eSkylordTorvaOneShotAnimKit::AnimKitFly);
                events.ScheduleEvent(eSkylordTorvaEvents::EventDiffusedEnergy, 3 * TimeConstants::IN_MILLISECONDS);
                break;
            case eSkylordTorvaMovements::MovementTorvaStartShootingLightning:
                me->CastSpell(me, eSkylordTorvaSpells::SpellDiffusedEnergyDummy);
                me->SetFacingTo(g_DrakeOrientationWhileFlightIntro);
             
                AddTimedDelayedOperation(4 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    me->SetHomePosition(1647.00f, 2000.29f, 107.789f, 1.54f);
                    me->GetMotionMaster()->MovePoint(eSkylordTorvaMovements::MovementTorvaHomePosition, 1647.00f, 2000.29f, 107.789f);
                });
                break;
            case eSkylordTorvaMovements::MovementTorvaHomePosition:
                if (m_Instance != nullptr)
                {
                    if (Creature* l_SkylordTorva = m_Instance->instance->GetCreature(m_Instance->GetGuidData(GrimrailDepotData::DataSkyLordTovra)))
                    {
                        l_SkylordTorva->SetFaction(HostileFaction);
                        l_SkylordTorva->SetReactState(ReactStates::REACT_AGGRESSIVE);
                        l_SkylordTorva->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC));

                        if (me->GetVehicleKit())
                        me->GetVehicleKit()->RemoveAllPassengers();
                    }
                }
                break;
              default:
                break;
            }
        }

        void MoveInLineOfSight(Unit* p_Unit) override
        {
            if (p_Unit && p_Unit->GetTypeId() == TypeID::TYPEID_PLAYER && p_Unit->IsWithinDistInMap(p_Unit, 40.0f) && !m_First && m_Count >= 5)
            {
                m_First = true;
                me->GetMotionMaster()->MovePoint(0, g_TorvaFirstPosition);
            }
        }

        void KilledUnit(Unit* p_Who) override
        {
            if (p_Who && p_Who->GetTypeId() == TypeID::TYPEID_PLAYER)
            {
                if (roll_chance_i(50))
                    Talk(eSkylordTorvaTalks::TalkKill01);
                else
                    Talk(eSkylordTorvaTalks::TalkKill02);
            }
        }

        void UpdateAI(uint32 const p_Diff) override
        {
            UpdateOperations(p_Diff);
            events.Update(p_Diff);

            switch (events.ExecuteEvent())
            {
            case eSkylordTorvaEvents::EventDiffusedEnergy:
                events.Reset();

                if (m_Flight)
                {
                    m_Flight = false;
                    me->GetMotionMaster()->MoveTakeoff(eSkylordTorvaMovements::MovementFlyPoint, g_DrakePointA);
                }
                else
                {
                    m_Flight = true;
                    me->GetMotionMaster()->MoveTakeoff(eSkylordTorvaMovements::MovementFlyPoint, g_DrakePointB);
                }

                AddTimedDelayedOperation(5 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    enum eDiffusedEnergy
                    {
                        SpellDiffusedEnergyDummy = 161558,
                        SpellDiffusedEnergyAura = 161588,
                        SpellDiffusedEnergyAreaTrigger = 161589,
                        SpellThunderZoneDummy = 166346
                    };

                    me->CastSpell(me, eDiffusedEnergy::SpellDiffusedEnergyDummy);
                    me->CastSpell(me, eDiffusedEnergy::SpellThunderZoneDummy);

                    std::list<Creature*> l_ListCreatures;
                    me->GetCreatureListWithEntryInGrid(l_ListCreatures, eSkylordTorvaCreatures::CreatureTriggerDiffusedEnergy, 400.0f);
                    if (!l_ListCreatures.empty())
                    {
                        for (uint8 l_I = 0; l_I < urand(5, 7); l_I++)
                        {
                            std::list<Creature*>::const_iterator l_Itr = l_ListCreatures.begin();
                            std::advance(l_Itr, urand(0, l_ListCreatures.size() - 1));

                            me->CastSpell((*l_Itr), eDiffusedEnergy::SpellDiffusedEnergyAreaTrigger);
                        }
                    }
                });
                break;
            default:
                break;
            }
        }

    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new grimrail_depot_skylord_tovra_creature_rkunaAI(p_Creature);
    }
};
/*
/// Diffused Energy - 161558
class grimrail_depot_skylord_tovra_spell_diffused_lightning : public SpellScriptLoader
{
    public:

    grimrail_depot_skylord_tovra_spell_diffused_lightning() : SpellScriptLoader("grimrail_depot_skylord_tovra_spell_diffused_lightning") { }

    class grimrail_depot_skylord_tovra_spell_diffused_lightning_SpellScript : public SpellScript
    {
        PrepareSpellScript(grimrail_depot_skylord_tovra_spell_diffused_lightning_SpellScript);

        enum eSkylordTorvaSpells
        {
            SpellDiffusedEnergyDummy = 161558,
            SpellDiffusedEnergyAura = 161588,
            SpellDiffusedEnergyAreaTrigger = 161589,
        };

        void HandleDummy(SpellEffIndex p_EffIndex)
        {
            if (Unit* l_Caster = GetCaster())
            {
                int8 l_Count = 0;

                std::list<Creature*> l_CreaturesDiffusedEnergyTriggers;
                GetCaster()->GetCreatureListWithEntryInGrid(l_CreaturesDiffusedEnergyTriggers, eSkylordTorvaCreatures::CreatureTriggerDiffusedEnergy, 200.0f);
                if (!l_CreaturesDiffusedEnergyTriggers.empty())
                {
                    for (Creature* l_Itr : l_CreaturesDiffusedEnergyTriggers)
                    {
                        if (l_Count > 4)
                            continue;

                        if (!l_Itr)
                            continue;

                        l_Count++;
                        l_Itr->CastSpell(l_Itr, eSkylordTorvaSpells::SpellDiffusedEnergyAreaTrigger);
                    }
                }
            }
        }

        void Register()
        {
            OnEffectLaunch += SpellEffectFn(grimrail_depot_skylord_tovra_spell_diffused_lightning_SpellScript::HandleDummy, SpellEffIndex::EFFECT_0, SpellEffects::SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new grimrail_depot_skylord_tovra_spell_diffused_lightning_SpellScript();
    }
};
*/

/// Thunder Zone - 166346   
class grimrail_depot_skylord_tovra_spell_thunder_zone : public SpellScriptLoader
{
    public:

    grimrail_depot_skylord_tovra_spell_thunder_zone() : SpellScriptLoader("grimrail_depot_skylord_tovra_spell_thunder_zone") { }

    class grimrail_depot_skylord_tovra_spell_thunder_zone_SpellScript : public SpellScript
    {
        PrepareSpellScript(grimrail_depot_skylord_tovra_spell_thunder_zone_SpellScript);

        enum eThunderZoneSpells
        {
            SpellThunderZoneAura = 166340
        };

        void HandleDummy(SpellEffIndex p_EffIndex)
        {
            if (Unit* l_Caster = GetCaster())
            {
                if (InstanceScript* l_Instance = l_Caster->GetInstanceScript())
                    l_Instance->DoAddAuraOnPlayers(eThunderZoneSpells::SpellThunderZoneAura);
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(grimrail_depot_skylord_tovra_spell_thunder_zone_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new grimrail_depot_skylord_tovra_spell_thunder_zone_SpellScript();
    }
};

/// Diffused Energy - 161589 AT 2324
class grimrail_depot_skylord_tovra_at_diffused_energy : public AreaTriggerEntityScript
{
    public:

    grimrail_depot_skylord_tovra_at_diffused_energy() : AreaTriggerEntityScript("grimrail_depot_skylord_tovra_at_diffused_energy") { }

    enum eSpell
    {
        SpellDiffusedEnergyAura = 161588
    };   

    struct grimrail_depot_skylord_tovra_at_diffused_energy_AI : public AreaTriggerAI
    {
        explicit grimrail_depot_skylord_tovra_at_diffused_energy_AI(AreaTrigger* at) : AreaTriggerAI(at)  {  }

        std::set<ObjectGuid> m_AffectedPlayers;

        void OnUpdate(uint32 diff) override
        {
            if (Unit* caster = at->GetCaster())
            {
                std::list<Creature*> l_TargetList;
                float l_Radius = 2.0f;

                l_TargetList = caster->FindAllUnfriendlyCreaturesInRange(l_Radius);

                if (l_TargetList.empty())
                    return;

                for (Creature* l_Iter : l_TargetList)
                {
                    if (!l_Iter)
                        continue;

                    l_Iter->CastSpell(l_Iter, eSpell::SpellDiffusedEnergyAura, true);
                }
            }
        }

    };

    AreaTriggerAI* GetAI(AreaTrigger* at) const override
    {
        return new grimrail_depot_skylord_tovra_at_diffused_energy_AI(at);
    }
};

/// Spinning Spear - 162058 AT 2358
class grimrail_depot_skylord_tovra_at_spinning_spear : public AreaTriggerEntityScript
{
    public:

    grimrail_depot_skylord_tovra_at_spinning_spear() : AreaTriggerEntityScript("grimrail_depot_skylord_tovra_at_spinning_spear") { }

    enum eSpell
    {
        SpellSpinningSpearDamage = 162057
    };

    struct grimrail_depot_skylord_tovra_at_spinning_spear_AI : public AreaTriggerAI
    {
        explicit grimrail_depot_skylord_tovra_at_spinning_spear_AI(AreaTrigger* at) : AreaTriggerAI(at) { }

        std::set<ObjectGuid> m_AffectedPlayers;
        uint32 l_Diff = 500;

        void OnUpdate(uint32 diff) override
        {
            if (Unit* caster = at->GetCaster())
            {
                std::list<Creature*> l_TargetList;
                float l_Radius = 3.0f;

                if (l_Diff <= diff)
                {
                    l_TargetList = caster->FindAllUnfriendlyCreaturesInRange(l_Radius);

                    if (l_TargetList.empty())
                        return;

                    for (Creature* l_Iter : l_TargetList)
                    {
                        if (!l_Iter)
                            continue;

                        l_Iter->CastSpell(l_Iter, eSpell::SpellSpinningSpearDamage, true);
                    }

                    l_Diff = 1 * TimeConstants::IN_MILLISECONDS;
                }
                else
                    l_Diff -= diff;
            }
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* at) const override
    {
        return new grimrail_depot_skylord_tovra_at_spinning_spear_AI(at);
    }
};

/// Freezing Snare - 162059 AT 2360
class grimrail_depot_skylord_torva_at_freezing_snare : public AreaTriggerEntityScript
{
    public:

    grimrail_depot_skylord_torva_at_freezing_snare() : AreaTriggerEntityScript("grimrail_depot_skylord_torva_at_freezing_snare") { }

    enum eSpell
    {
        SpellFreezingSnareAreaTrigger = 162059,
        SpellFreezingSnareDummy = 162062,
        SpellFreezingSnareDamage = 162065,
        SpellFreezingSnare = 162066,
        SpellFreezingSnareTriggerMissile = 162080,
    };

    struct grimrail_depot_skylord_torva_at_freezing_snare_AI : public AreaTriggerAI
    {
        explicit grimrail_depot_skylord_torva_at_freezing_snare_AI(AreaTrigger* at) : AreaTriggerAI(at) {  }

        std::set<ObjectGuid> m_AffectedPlayers;
        uint32 l_Diff = 1 * TimeConstants::IN_MILLISECONDS;

        void OnUpdate(uint32 diff) override
        {
            if (Unit* caster = at->GetCaster())
            {
                std::list<Unit*> l_TargetList;
                float l_Radius = 2.0f;

                if (l_Diff <= diff)
                {
                    if (Player* l_Player = at->SelectNearestPlayer(l_Radius))
                    {
                        caster->CastSpell(l_Player, eSpell::SpellFreezingSnareDamage);
                        caster->GetScheduler().Schedule(Milliseconds(5000), [this](TaskContext context)
                        {
                            if (at->IsInWorld())
                                at->Remove();
                        });                      
                    }

                    l_Diff = 1 * TimeConstants::IN_MILLISECONDS;
                }
                else
                    l_Diff -= diff;
            }
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* at) const override
    {
        return new grimrail_depot_skylord_torva_at_freezing_snare_AI(at);
    }
};

void AddSC_boss_skylord_tovra()
{
    new boss_skylord_torva();                                       /// 80005
    new grimrail_depot_skylord_tovra_creature_rkuna();              /// 80004
///    new grimrail_depot_skylord_tovra_spell_diffused_lightning();    /// 161558
    new grimrail_depot_skylord_tovra_spell_thunder_zone();          ///166346 
    new grimrail_depot_skylord_tovra_at_diffused_energy();          /// 161589
    new grimrail_depot_skylord_tovra_at_spinning_spear();           /// 162058
    new grimrail_depot_skylord_torva_at_freezing_snare();           /// 162059
}
