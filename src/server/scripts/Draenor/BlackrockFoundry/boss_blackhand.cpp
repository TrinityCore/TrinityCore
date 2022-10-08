#include "boss_blackhand.h"
#include "SpellAuraEffects.h"

/// Blackhand <Warlord of the Blackrock> - 77325
class boss_blackhand : public CreatureScript
{
    public:
        boss_blackhand() : CreatureScript("boss_blackhand") { }

        enum eTalks
        {
            TalkIntro,
            TalkAggro,
            TalkMoltenSlag,
            TalkDemolitionWarn,
            TalkDemolition,
            TalkMarkedForDeathWarn,
            TalkImpalingThrowHit,
            TalkImpalingThrowMiss,
            TalkPhase2,
            TalkSiegemakerWarn,
            TalkSiegemaker,
            TalkEnhancedSiegemaker,
            TalkIronSoldier,
            TalkPhase3,
            TalkImpalingThrowP3,
            TalkSlagEruptionWarn,
            TalkSlagEruption,
            TalkMassiveShatteringSmash,
            TalkSlay,
            TalkBerserker,
            TalkDeath
        };

        enum eSpells
        {
            /// Other
            BurnedAura                      = 156404,
            SlaggedAura                     = 156047,
            SlagBombAreaTrigger             = 156037,
            IncendiaryShotAura              = 156772,
            OverheatedDmgAura               = 156888,
            OverheatedAreaTrigger           = 156859,
            ObscuredAura                    = 156785,
            SlagCraterAreaTrigger           = 156827,
            AshesAura                       = 163324,
            BlackhandBonusLoot              = 177539,
            BlazeAreaTrigger                = 156605,
            /// Combat Spells
            /// Throw Slag Bomb
            ThrowSlagBombScript             = 156991,   ///< Used by AddOns
            ThrowSlagBombMain               = 156030,   ///< Triggers 156031, 156033, 156034 -> 3 summoning spells
            AttachSlagBombMain              = 157000,
            ThrowSlagBombsTank              = 159179,
            SlagEruptionCast                = 156928,
            /// Demolition
            DemolitionCast                  = 156425,
            /// Shattering Smash
            ShatteringSmashScript           = 158053,
            ShatteringSmashCast             = 155992,
            MassiveShatteringSmashCast      = 158054,
            MassiveShatteringSmashCrater    = 176447,
            /// Marked for Death
            MarkedForDeathPeriodic          = 156096,
            ImpalingThrowPlayer             = 156107,
            ImpalingThrowP3                 = 175013,
            ImpalingThrowPile               = 156110,
            ImpalingThrowSiegemaker         = 156111,
            ImpaledAura                     = 156743,
            /// Siegemaker
            SummonIronHordeTank             = 156795,
            /// Phase Switch
            JumpToSecondFloor               = 161347,
            JumpToThirdFloor                = 161348,
            Phase1TransitionSafeFall        = 159160
        };

        enum eEvents
        {
            EventThrowSlagBomb = 1,
            EventDemolition,
            EventShatteringSmash,
            EventMarkedForDeath,
            EventRegenerateEnergy,
            EventSiegemaker,
            EventIronSoldiers,
            EventAttachSlagBombs,
            EventSlagEruption,
            EventMassiveShatteringSmash,
            EventCheckPlayerForIntro,
            EventCheckPlayerZ
        };

        enum eTimers
        {
            TimerThrowSlagBomb      = 6 * TimeConstants::IN_MILLISECONDS,
            TimerThrowSlagBombCD    = 25 * TimeConstants::IN_MILLISECONDS,
            TimerThrowSlagBombP2    = 12 * TimeConstants::IN_MILLISECONDS,
            TimerDemolition         = 15 * TimeConstants::IN_MILLISECONDS + 500,
            TimerDemolitionCD       = 45 * TimeConstants::IN_MILLISECONDS + 500,
            TimerMarkedForDeath     = 36 * TimeConstants::IN_MILLISECONDS,
            TimerMarkedForDeathCD   = 16 * TimeConstants::IN_MILLISECONDS,
            TimerMarkedForDeathP2   = 26 * TimeConstants::IN_MILLISECONDS,
            TimerRegenerateEnergy   = 1 * TimeConstants::IN_MILLISECONDS,
            TimerSiegemaker         = 16 * TimeConstants::IN_MILLISECONDS,
            TimerSiegemakerCD       = 50 * TimeConstants::IN_MILLISECONDS,
            TimerIronSoldiers       = 11 * TimeConstants::IN_MILLISECONDS,
            TimerIronSoldiersCD     = 30 * TimeConstants::IN_MILLISECONDS,
            TimerIronSoldiersReduce = 5 * TimeConstants::IN_MILLISECONDS,
            TimerAttachSlagBombs    = 12 * TimeConstants::IN_MILLISECONDS,
            TimerAttachSlagBombsCD  = 25 * TimeConstants::IN_MILLISECONDS,
            TimerSlagEruption       = 31 * TimeConstants::IN_MILLISECONDS + 500,
            TimerSlagEruptionCD     = 33 * TimeConstants::IN_MILLISECONDS
        };

        enum ePhases
        {
            TheBlackrockForge,
            StorageWarehouse,
            IronCrucible
        };

        enum eActions
        {
        };

        enum eVisuals
        {
            IntroTalkEmote      = 378,
            AnimTargetCrucible  = 7694,
            FloorDestroyed      = 15924
        };

        enum eMoves
        {
            MoveToP2 = eBlackhandDatas::MaxCosmeticMoves,
            MoveTank
        };

        struct boss_blackhandAI : public BossAI
        {
            boss_blackhandAI(Creature* p_Creature) : BossAI(p_Creature, eFoundryDatas::DataBlackhand)
            {
                m_Instance  = p_Creature->GetInstanceScript();
                m_IntroDone = false;
            }

            InstanceScript* m_Instance;

            EventMap m_Events;
            EventMap m_CosmeticEvents;

            bool m_IntroDone;

            uint8 m_MoveID;

            uint8 m_PhaseID;
            uint8 m_RegenCycle;

            ObjectGuid m_SlagWrapGuid;

            bool m_Paused;

            bool m_FirstSideSpawn;
            uint32 m_SoldiersCount;

            uint32 m_SmashedCount;

            bool CanRespawn()
            {
                return false;
            }

            void Reset() override
            {
               // ClearDelayedOperations();

               // me->setPowerType(Powers::POWER_ENERGY);
                me->SetMaxPower(Powers::POWER_ENERGY, 100);
                me->SetPower(Powers::POWER_ENERGY, 33);
                me->SetPower(Powers::POWER_ALTERNATE_POWER, 0);

                me->SetReactState(ReactStates::REACT_AGGRESSIVE);

                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG2_REGENERATE_POWER));

                me->AddUnitState(UnitState::UNIT_STATE_IGNORE_PATHFINDING);

                summons.DespawnAll();

                _Reset();

                me->RemoveAllAreaTriggers();

                m_Events.Reset();
                m_Events.SetPhase(ePhases::TheBlackrockForge);

                me->RemoveAura(eFoundrySpells::Berserker);

                me->SetDisableGravity(true);

               // AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                //{
                    me->SetDisableGravity(false);

                    me->GetMotionMaster()->MoveFall();
                //});

                m_MoveID = 0;

               // AddTimedDelayedOperation(2 * TimeConstants::IN_MILLISECONDS, [this]() -> void
               // {
                    me->SetWalk(true);

                    me->GetMotionMaster()->MovePoint(m_MoveID, g_BlackhandCosmeticMoves[m_MoveID]);
               // });

                m_PhaseID           = ePhases::TheBlackrockForge;
                m_RegenCycle        = 1;
               // m_SlagWrapGuid      = 0;
                m_Paused            = false;
                m_FirstSideSpawn    = false;
                m_SoldiersCount     = 0;
                m_SmashedCount      = 0;

                if (!m_IntroDone)
                    m_CosmeticEvents.ScheduleEvent(eEvents::EventCheckPlayerForIntro, 1 * TimeConstants::IN_MILLISECONDS);
            }

            void KilledUnit(Unit* p_Who) override
            {
                if (!p_Who->IsPlayer())
                    return;

                Talk(eTalks::TalkSlay);
            }

            void EnterCombat(Unit* /*p_Attacker*/) override
            {
                me->SetWalk(false);

               // ClearDelayedOperations();

                me->HandleEmoteCommand(0);

                _EnterCombat();

                if (m_Instance != nullptr)
                {
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me, 1);

                    if (Creature* l_Foundry = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::BlackrockFoundryTrigger)))
                    {
                        if (l_Foundry->IsAIEnabled)
                            l_Foundry->AI()->DoAction(eBlackhandActions::BlackhandEngaged);
                    }
                }

                Talk(eTalks::TalkAggro);

                HandleCrucibles(true);

                PreSummonAdds();

                m_Events.Reset();
                m_Events.SetPhase(ePhases::TheBlackrockForge);

                m_Events.ScheduleEvent(eEvents::EventThrowSlagBomb,     eTimers::TimerThrowSlagBomb,    0, ePhases::TheBlackrockForge);
                m_Events.ScheduleEvent(eEvents::EventDemolition,        eTimers::TimerDemolition,       0, ePhases::TheBlackrockForge);
                m_Events.ScheduleEvent(eEvents::EventMarkedForDeath,    eTimers::TimerMarkedForDeath,   0, ePhases::TheBlackrockForge);

                m_CosmeticEvents.Reset();

                m_CosmeticEvents.ScheduleEvent(eEvents::EventRegenerateEnergy, eTimers::TimerRegenerateEnergy);
            }

            void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER)
            {
                me->NearTeleportTo(me->GetHomePosition());

                HandleCrucibles(false);

                RemoveCombatAurasAndTriggers();

                m_Events.Reset();
                m_CosmeticEvents.Reset();

                if (m_Instance != nullptr)
                {
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                    if (Creature* l_Foundry = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::BlackrockFoundryTrigger)))
                    {
                        if (l_Foundry->IsAIEnabled)
                            l_Foundry->AI()->DoAction(eBlackhandActions::BlackhandDisengaged);
                    }

                    if (Creature* l_AchievStalker = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::AchievementStalker)))
                    {
                        if (l_AchievStalker->IsAIEnabled)
                            l_AchievStalker->AI()->DoAction(eBlackhandActions::BlackhandDisengaged);
                    }
                }

                CreatureAI::EnterEvadeMode();
            }

            void JustDied(Unit* /*p_Killer*/) override
            {
                Talk(eTalks::TalkDeath);

                me->RemoveAllAreaTriggers();

                summons.DespawnAll();

                _JustDied();

                RemoveCombatAurasAndTriggers();

                if (m_Instance != nullptr)
                {
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                    if (Creature* l_Foundry = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::BlackrockFoundryTrigger)))
                    {
                        if (l_Foundry->IsAIEnabled)
                            l_Foundry->AI()->DoAction(eBlackhandActions::BlackhandDisengaged);
                    }

                    /// Allow loots and bonus loots to be enabled/disabled with a simple reload
                    //if (sObjectMgr->IsDisabledEncounter(m_Instance->GetEncounterIDForBoss(me), GetDifficulty()))
                     //   me->SetLootRecipient(nullptr);
                  //  else
                        CastSpellToPlayers(me->GetMap(), me, eSpells::BlackhandBonusLoot, true);
                }
            }

            void SpellHitTarget(Unit* p_Target, SpellInfo const* p_SpellInfo) override
            {
                if (p_Target == nullptr)
                    return;

                switch (p_SpellInfo->Id)
                {
                    case eSpells::ShatteringSmashCast:
                    {
                        me->getThreatManager().modifyThreatPercent(p_Target, -100);
                        break;
                    }
                    case eSpells::ImpalingThrowPlayer:
                    {
                        Talk(eTalks::TalkImpalingThrowHit);
                        me->CastSpell(p_Target, eSpells::ImpaledAura, true);
                        break;
                    }
                    case eSpells::ImpalingThrowP3:
                    {
                        Talk(eTalks::TalkImpalingThrowP3);
                        me->CastSpell(p_Target, eSpells::ImpaledAura, true);
                        break;
                    }
                    case eSpells::ImpalingThrowPile:
                    case eSpells::ImpalingThrowSiegemaker:
                    {
                        Talk(eTalks::TalkImpalingThrowMiss);
                        break;
                    }
                    case eSpells::MarkedForDeathPeriodic:
                    {
                        Talk(eTalks::TalkMarkedForDeathWarn);
                        break;
                    }
                    default:
                        break;
                }
            }

            void SpellMissTarget(Unit* p_Target, SpellInfo const* p_SpellInfo, SpellMissInfo p_MissInfo)
            {
                if (p_Target == nullptr)
                    return;

                /// Impaled should be applied in any case if the player is targeted
                if (p_SpellInfo->Id == eSpells::ImpalingThrowPlayer)
                    me->CastSpell(p_Target, eSpells::ImpaledAura, true);
            }

            void DoAction(int32 p_Action)
            {
                switch (p_Action)
                {
                    case eBlackhandActions::BlackhandIntro:
                    {
                        if (m_IntroDone)
                            break;

                        m_IntroDone = true;

                        Talk(eTalks::TalkIntro);

                        //if (m_Instance != nullptr)
                          //  m_Instance->instance->SetObjectVisibility(500.0f);

                       // AddTimedDelayedOperation(12 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                       // {
                        //    me->SetUInt32Value(UnitFields::UNIT_NPC_EMOTESTATE, 0);
                      //  });

                        break;
                    }
                    default:
                        break;
                }
            }

            void MovementInform(uint32 p_Type, uint32 p_ID) override
            {
                if (p_Type != MovementGeneratorType::POINT_MOTION_TYPE &&
                    p_Type != MovementGeneratorType::EFFECT_MOTION_TYPE)
                    return;

                /// Cosmetic moves handling
                if (p_ID < eBlackhandDatas::MaxCosmeticMoves)
                {
                    for (uint32 l_Entry = eFoundryGameObjects::BlackhandsCrucible01; l_Entry <= eFoundryGameObjects::BlackhandsCrucible05; ++l_Entry)
                    {
                        if (GameObject* l_Crucible = me->FindNearestGameObject(l_Entry, 50.0f))
                        {
                           // AddTimedDelayedOperation(10, [this, l_Entry]() -> void
                           // {
                                if (GameObject* l_Crucible = me->FindNearestGameObject(l_Entry, 50.0f))
                                    me->SetFacingTo(me->GetAngle(l_Crucible));
                            //});

                           // AddTimedDelayedOperation(300, [this]() -> void
                           // {
                                me->PlayOneShotAnimKitId(eVisuals::AnimTargetCrucible);
                            //});

                           // AddTimedDelayedOperation(500, [this, l_Entry]() -> void
                           // {
                                if (GameObject* l_Crucible = me->FindNearestGameObject(l_Entry, 50.0f))
                                    l_Crucible->SetGoState(GOState::GO_STATE_ACTIVE);
                            //});

                            //AddTimedDelayedOperation(4 * TimeConstants::IN_MILLISECONDS, [this, l_Entry, p_ID]() -> void
                          //  {
                                if (GameObject* l_Crucible = me->FindNearestGameObject(l_Entry, 50.0f))
                                    l_Crucible->SetGoState(GOState::GO_STATE_READY);

                                ++m_MoveID;

                                if (m_MoveID == eBlackhandDatas::MaxCosmeticMoves)
                                    m_MoveID = 0;

                                me->GetMotionMaster()->MovePoint(m_MoveID, g_BlackhandCosmeticMoves[m_MoveID]);
                          //  });

                            break;
                        }
                    }
                }
                else
                {
                    switch (p_ID)
                    {
                        case eMoves::MoveToP2:
                        {
                            me->SetReactState(ReactStates::REACT_PASSIVE);
                            me->AttackStop();

                           // me->DespawnCreaturesInArea(eBlackhandCreatures::SlagBomb);
                           // me->DespawnAreaTriggersInArea(eSpells::SlagBombAreaTrigger);

                            if (m_Instance != nullptr)
                            {
                                if (Creature* l_Foundry = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::BlackrockFoundryTrigger)))
                                {
                                    if (l_Foundry->IsAIEnabled)
                                        l_Foundry->AI()->DoAction(eBlackhandActions::BlackhandStartP2);
                                }

                                m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::MarkedForDeathPeriodic);
                                m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::BurnedAura);

                                m_Instance->DoCastSpellOnPlayers(eSpells::Phase1TransitionSafeFall);
                            }

                           // AddTimedDelayedOperation(2 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                            //{
                                me->CastSpell(565.961f, 3497.788f, 604.376f, eSpells::JumpToSecondFloor, true);

                                m_Events.CancelEvent(eEvents::EventThrowSlagBomb);
                                m_Events.CancelEvent(eEvents::EventDemolition);
                                m_Events.CancelEvent(eEvents::EventMarkedForDeath);

                                m_Events.SetPhase(m_PhaseID);

                                m_Events.ScheduleEvent(eEvents::EventThrowSlagBomb,     eTimers::TimerThrowSlagBombP2,  0, ePhases::StorageWarehouse);
                                m_Events.ScheduleEvent(eEvents::EventSiegemaker,        eTimers::TimerSiegemaker,       0, ePhases::StorageWarehouse);
                                m_Events.ScheduleEvent(eEvents::EventMarkedForDeath,    eTimers::TimerMarkedForDeathP2, 0, ePhases::StorageWarehouse);
                                m_Events.ScheduleEvent(eEvents::EventIronSoldiers,      eTimers::TimerIronSoldiers,     0, ePhases::StorageWarehouse);

                                m_CosmeticEvents.CancelEvent(eEvents::EventRegenerateEnergy);

                                me->SetPower(Powers::POWER_ENERGY, 66);

                                m_RegenCycle = 2;
                           // });

                            break;
                        }
                        case eSpells::JumpToSecondFloor:
                        {
                            m_CosmeticEvents.ScheduleEvent(eEvents::EventCheckPlayerZ, 1 * TimeConstants::IN_MILLISECONDS);

                           // AddTimedDelayedOperation(5 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                           // {
                                m_Paused = false;

                                me->SetReactState(ReactStates::REACT_AGGRESSIVE);

                                m_CosmeticEvents.ScheduleEvent(eEvents::EventRegenerateEnergy, eTimers::TimerRegenerateEnergy);

                               // if (Player* l_Tank = SelectMainTank())
                               // {
                                  //  me->GetMotionMaster()->MoveChase(l_Tank);
                                   // AttackStart(l_Tank);
                               // }
                           // });

                            break;
                        }
                        case eSpells::JumpToThirdFloor:
                        {
                           // AddTimedDelayedOperation(5 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                            //{
                                m_Paused = false;

                                me->SetReactState(ReactStates::REACT_AGGRESSIVE);

                                me->SetPower(Powers::POWER_ENERGY, 33);

                                m_CosmeticEvents.Reset();
                                m_CosmeticEvents.ScheduleEvent(eEvents::EventRegenerateEnergy, eTimers::TimerRegenerateEnergy);

                              //  if (Player* l_Tank = SelectMainTank())
                               // {
                                //    me->GetMotionMaster()->MoveChase(l_Tank);
                               //     AttackStart(l_Tank);
                               // }
                           // });

                            break;
                        }
                        case eMoves::MoveTank:
                        default:
                            break;
                    }
                }
            }

            void RegeneratePower(Powers p_Power, int32& p_Value)
            {
                /// Regens manually
                p_Value = 0;
            }

            void SetPower(Powers p_Power, int32 p_Value)
            {
                if (p_Power != Powers::POWER_ENERGY)
                    return;

                if (m_Paused)
                    return;

                if (p_Value >= 100)
                {
                    switch (m_PhaseID)
                    {
                        case ePhases::IronCrucible:
                        {
                            //if (!m_Events.HasEvent(eEvents::EventMassiveShatteringSmash))
                               // m_Events.ScheduleEvent(eEvents::EventMassiveShatteringSmash, 3 * TimeConstants::IN_MILLISECONDS, 0, ePhases::IronCrucible);

                            break;
                        }
                        default:
                        {
                            //if (!m_Events.HasEvent(eEvents::EventShatteringSmash))
                               // m_Events.ScheduleEvent(eEvents::EventShatteringSmash, 1, 0, m_PhaseID);

                            break;
                        }
                    }
                }
            }

            void DamageTaken(Unit* /*p_Attacker*/, uint32& p_Damage) override
            {
                /// Don't handle last phase, it lasts until death
                if (m_PhaseID >= (eBlackhandDatas::MaxPhases - 1))
                    return;

                if (me->HealthBelowPctDamaged(g_BlackhandPhaseSwitchPcts[m_PhaseID], p_Damage))
                {
                    switch (m_PhaseID)
                    {
                        case ePhases::TheBlackrockForge:
                        {
                            Talk(eTalks::TalkPhase2);
                            m_Paused = true;
                            me->GetMotionMaster()->MovePoint(eMoves::MoveToP2, g_StartP2JumpPos);
                            break;
                        }
                        case ePhases::StorageWarehouse:
                        {
                            Talk(eTalks::TalkPhase3);

                            m_Paused = true;

                            m_Events.CancelEvent(eEvents::EventThrowSlagBomb);
                            m_Events.CancelEvent(eEvents::EventSiegemaker);
                            m_Events.CancelEvent(eEvents::EventMarkedForDeath);
                            m_Events.CancelEvent(eEvents::EventIronSoldiers);
                            m_Events.CancelEvent(eEvents::EventShatteringSmash);

                            m_Events.SetPhase(ePhases::IronCrucible);

                            m_Events.ScheduleEvent(eEvents::EventAttachSlagBombs,   eTimers::TimerAttachSlagBombs,  0, ePhases::IronCrucible);
                            m_Events.ScheduleEvent(eEvents::EventMarkedForDeath,    eTimers::TimerMarkedForDeathCD, 0, ePhases::IronCrucible);
                            m_Events.ScheduleEvent(eEvents::EventSlagEruption,      eTimers::TimerSlagEruption,     0, ePhases::IronCrucible);

                            me->SetReactState(ReactStates::REACT_PASSIVE);
                            me->AttackStop();

                            std::vector<uint32> l_Phase3Despawn =
                            {
                                eBlackhandCreatures::SlagBomb,
                                eBlackhandCreatures::IronSoldier,
                                eBlackhandCreatures::Siegemaker,
                                eBlackhandCreatures::BlazeController,
                                eBlackhandCreatures::Blaze
                            };

                            //me->DespawnCreaturesInArea(l_Phase3Despawn);
                           // me->DespawnAreaTriggersInArea({ eSpells::SlagBombAreaTrigger, eSpells::BlazeAreaTrigger });

                            std::list<Creature*> l_TriggerList;
                            me->GetCreatureListWithEntryInGrid(l_TriggerList, eBlackhandCreatures::BlackrockFoundryP2P3Trigger, 200.0f);

                            for (Creature* l_Trigger : l_TriggerList)
                            {
                                if (l_Trigger->IsAIEnabled)
                                    l_Trigger->AI()->DoAction(eBlackhandActions::BlackhandStartP3);
                            }

                            me->CastSpell(565.9606f, 3500.114f, 511.844f, eSpells::JumpToThirdFloor, true);

                            if (GameObject* l_Floor = ObjectAccessor::GetGameObject(*me, m_Instance->GetGuidData(eFoundryGameObjects::BlackhandAPlatform)))
                            {
                                l_Floor->SetDestructibleState(GameObjectDestructibleState::GO_DESTRUCTIBLE_DESTROYED);
                                l_Floor->SetDisplayId(eVisuals::FloorDestroyed);
                            }

                            if (Creature* l_AchievStalker = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::AchievementStalker)))
                            {
                                if (l_AchievStalker->IsAIEnabled)
                                    l_AchievStalker->AI()->DoAction(eBlackhandActions::BlackhandStartP3);
                            }

                            break;
                        }
                        default:
                            break;
                    }

                    ++m_PhaseID;
                }
            }

            bool OnTaunt(Unit* /*p_Taunter*/)
            {
                return !m_Paused;
            }

            void UpdateAI(uint32  p_Diff) override
            {
               // UpdateOperations(p_Diff);

                m_CosmeticEvents.Update(p_Diff);

                switch (m_CosmeticEvents.ExecuteEvent())
                {
                    case eEvents::EventRegenerateEnergy:
                    {
                        int32 l_Power = 0;

                        switch (m_PhaseID)
                        {
                            case ePhases::TheBlackrockForge:
                            {
                                l_Power = g_BlackhandRegenCyclesP1[m_RegenCycle++];

                                if (m_RegenCycle >= eBlackhandDatas::MaxRegenCyclesP1)
                                    m_RegenCycle = 0;

                                break;
                            }
                            case ePhases::StorageWarehouse:
                            {
                                l_Power = g_BlackhandRegenCyclesP2[m_RegenCycle++];

                                if (m_RegenCycle >= eBlackhandDatas::MaxRegenCyclesP2)
                                    m_RegenCycle = 0;

                                break;
                            }
                            case ePhases::IronCrucible:
                            {
                                l_Power = 4;
                                break;
                            }
                            default:
                                break;
                        }

                        me->ModifyPower(Powers::POWER_ENERGY, l_Power);

                        m_CosmeticEvents.ScheduleEvent(eEvents::EventRegenerateEnergy, eTimers::TimerRegenerateEnergy);
                        break;
                    }
                    case eEvents::EventCheckPlayerForIntro:
                    {
                        //if (me->FindNearesPlayer(100.0f) != nullptr)
                            DoAction(eBlackhandActions::BlackhandIntro);

                        if (!m_IntroDone)
                            m_CosmeticEvents.ScheduleEvent(eEvents::EventCheckPlayerForIntro, 1 * TimeConstants::IN_MILLISECONDS);

                        break;
                    }
                    case eEvents::EventCheckPlayerZ:
                    {
                        if (m_PhaseID != ePhases::StorageWarehouse)
                            break;

                        std::list<HostileReference*> l_ThreatList = me->getThreatManager().getThreatList();
                        if (!l_ThreatList.empty())
                        {
                            l_ThreatList.remove_if([this](HostileReference* p_Ref) -> bool
                            {
                                if (p_Ref == nullptr || p_Ref->getTarget() == nullptr || !p_Ref->getTarget()->IsPlayer())
                                    return true;

                                return false;
                            });
                        }

                        for (HostileReference* l_Ref : l_ThreatList)
                        {
                            if (Unit* l_Unit = l_Ref->getTarget())
                            {
                                if (l_Unit->m_positionZ < (g_SecondFloorJumpPos.m_positionZ - 5.0f))
                                    l_Unit->NearTeleportTo(g_SecondFloorJumpPos);
                            }
                        }

                        m_CosmeticEvents.ScheduleEvent(eEvents::EventCheckPlayerZ, 1 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    default:
                        break;
                }

                if (!UpdateVictim())
                    return;

                m_Events.Update(p_Diff);

                if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                    return;

                if (!m_Paused)
                {
                    //if (Player* l_Target = SelectMainTank())
                    //{
                        //if (!me->IsWithinMeleeRange(l_Target))
                       //     me->GetMotionMaster()->MovePoint(eMoves::MoveTank, *l_Target);
                   // }
                }

                switch (m_Events.ExecuteEvent())
                {
                    case eEvents::EventThrowSlagBomb:
                    {
                        me->CastSpell(me, eSpells::ThrowSlagBombScript, true);
                        me->CastSpell(me, eSpells::ThrowSlagBombMain, true);
                        m_Events.ScheduleEvent(eEvents::EventThrowSlagBomb, eTimers::TimerThrowSlagBombCD, 0, m_PhaseID);
                        break;
                    }
                    case eEvents::EventDemolition:
                    {
                        Talk(eTalks::TalkDemolitionWarn);
                        Talk(eTalks::TalkDemolition);
                        me->CastSpell(me, eSpells::DemolitionCast, false);
                        m_Events.ScheduleEvent(eEvents::EventDemolition, eTimers::TimerDemolitionCD, 0, ePhases::TheBlackrockForge);
                        break;
                    }
                    case eEvents::EventShatteringSmash:
                    {
                        me->SetPower(Powers::POWER_ENERGY, 0);

                       // if (Player* l_Tank = SelectMainTank())
                        //{
                        //    me->CastSpell(l_Tank, eSpells::ShatteringSmashScript, true);
                        //    me->CastSpell(l_Tank, eSpells::ShatteringSmashCast, false);
                       // }

                        break;
                    }
                    case eEvents::EventMarkedForDeath:
                    {
                        me->CastSpell(me, eSpells::MarkedForDeathPeriodic, true);
                        m_Events.ScheduleEvent(eEvents::EventMarkedForDeath, eTimers::TimerMarkedForDeathCD, 0, m_PhaseID);
                        break;
                    }
                    case eEvents::EventSiegemaker:
                    {
                        Talk(eTalks::TalkSiegemakerWarn);
                        Talk(eTalks::TalkSiegemaker);
                        me->CastSpell(me, eSpells::SummonIronHordeTank, true);
                        m_Events.ScheduleEvent(eEvents::EventSiegemaker, eTimers::TimerSiegemakerCD, 0, ePhases::StorageWarehouse);
                        break;
                    }
                    case eEvents::EventIronSoldiers:
                    {
                        Talk(eTalks::TalkIronSoldier);

                        std::vector<uint8> l_PosIDs;
                        /// Randomize pattern for each Bombardment phase
                        for (uint8 l_I = 0; l_I < uint8(g_IronSoldierSpawnPos[m_FirstSideSpawn].size()); ++l_I)
                            l_PosIDs.push_back(l_I);

                        //auto l_Seed = std::chrono::system_clock::now().time_since_epoch().count();
                       // std::shuffle(l_PosIDs.begin(), l_PosIDs.end(), std::uint32_t(uint32(l_Seed)));

                        for (uint8 l_I = 0; l_I < eBlackhandDatas::MaxIronSoldiers; ++l_I)
                        {
                            Position const l_Pos = g_IronSoldierSpawnPos[m_FirstSideSpawn][l_PosIDs[l_I]];

                            me->SummonCreature(eBlackhandCreatures::IronSoldier, l_Pos);
                        }

                        uint32 l_Time = eTimers::TimerIronSoldiersCD - (eTimers::TimerIronSoldiersReduce * m_SoldiersCount);

                        m_Events.ScheduleEvent(eEvents::EventIronSoldiers, eTimers::TimerIronSoldiersCD, 0, ePhases::StorageWarehouse);

                        m_FirstSideSpawn = !m_FirstSideSpawn;
                        ++m_SoldiersCount;
                        break;
                    }
                    case eEvents::EventAttachSlagBombs:
                    {
                        me->CastSpell(me, eSpells::ThrowSlagBombScript, true);
                        me->CastSpell(me, eSpells::AttachSlagBombMain, true);

                        //if (Player* l_Tank = SelectMainTank())
                            me->CastSpell(me, eSpells::ThrowSlagBombsTank, true);

                        m_Events.ScheduleEvent(eEvents::EventAttachSlagBombs, eTimers::TimerAttachSlagBombsCD, 0, ePhases::IronCrucible);
                        break;
                    }
                    case eEvents::EventSlagEruption:
                    {
                        Talk(eTalks::TalkSlagEruptionWarn);
                        Talk(eTalks::TalkSlagEruption);
                        me->CastSpell(me, eSpells::SlagEruptionCast, false);
                        m_Events.ScheduleEvent(eEvents::EventSlagEruption, eTimers::TimerSlagEruptionCD, 0, ePhases::IronCrucible);
                        break;
                    }
                    case eEvents::EventMassiveShatteringSmash:
                    {
                        Talk(eTalks::TalkMassiveShatteringSmash);

                        me->SetPower(Powers::POWER_ENERGY, 0);

                        m_SmashedCount = 0;

                       // if (Player* l_Tank = SelectMainTank())
                        //{
                            me->CastSpell(me, eSpells::ShatteringSmashScript, true);
                            me->CastSpell(me, eSpells::MassiveShatteringSmashCast, false);

                           // uint64 l_Guid = l_Tank->GetGUID();
                           // AddTimedDelayedOperation(2 * TimeConstants::IN_MILLISECONDS, [this, l_Guid]() -> void
                          //  {
                                //if (Player* l_Tank = ObjectGuid::GetPlayer(*me, l_Guid))
                                    me->CastSpell(me, eSpells::MassiveShatteringSmashCrater, true);
                          //  });
                       // }

                        break;
                    }
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }

            void HandleCrucibles(bool p_Apply)
            {
                if (m_Instance == nullptr)
                    return;

                for (uint32 l_I = eFoundryGameObjects::BlackhandsCrucible01; l_I <= eFoundryGameObjects::BlackhandsCrucible05; ++l_I)
                {
                    if (GameObject* l_Crucible = ObjectAccessor::GetGameObject(*me, m_Instance->GetGuidData(l_I)))
                        l_Crucible->SetGoState(p_Apply ? GOState::GO_STATE_ACTIVE : GOState::GO_STATE_READY);
                }

                if (p_Apply)
                {
                   // AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                   // {
                        if (GameObject* l_SlagWrap = me->SummonGameObject(eBlackhandObjects::SlagWrap, g_SlagWrapSpawnPos, QuaternionData(0.0f, 0.0f, 0.0f, 0.0f), 0))
                        {
                            m_SlagWrapGuid = l_SlagWrap->GetGUID();

                            l_SlagWrap->SetGoState(GOState::GO_STATE_ACTIVE);
                        }
                   // });
                }
                else
                {
                    if (GameObject* l_IronStar = ObjectAccessor::GetGameObject(*me, m_Instance->GetGuidData(eFoundryGameObjects::HangingIronStar)))
                        l_IronStar->SetGoState(GOState::GO_STATE_READY);

                    if (GameObject* l_Floor = ObjectAccessor::GetGameObject(*me, m_Instance->GetGuidData(eFoundryGameObjects::BlackhandAPlatform)))
                        l_Floor->SetDestructibleState(GameObjectDestructibleState::GO_DESTRUCTIBLE_INTACT);

                    if (GameObject* l_SlagWrap = ObjectAccessor::GetGameObject(*me, m_SlagWrapGuid))
                    {
                        l_SlagWrap->SetGoState(GOState::GO_STATE_READY);

                        ObjectGuid l_Guid = m_SlagWrapGuid;
                       // AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this, l_Guid]() -> void
                       // {
                            if (GameObject* l_SlagWrap = ObjectAccessor::GetGameObject(*me, l_Guid))
                                l_SlagWrap->Delete();
                      //  });
                    }
                }
            }

            void PreSummonAdds()
            {
                /// Siegemakers are spawned at the beginning of the fight
                for (uint8 l_I = 0; l_I < eBlackhandDatas::MaxStoragePortcullis; ++l_I)
                {
                    if (Creature* l_Siegemaker = me->SummonCreature(eBlackhandCreatures::Siegemaker, g_SiegemakerSpawnPos[l_I]))
                    {
                        ObjectGuid l_Guid = l_Siegemaker->GetGUID();
                       // AddTimedDelayedOperation(10, [this, l_I, l_Guid]() -> void
                        //{
                            if (Creature* l_Siegemaker = ObjectAccessor::GetCreature(*me, l_Guid))
                            {
                                if (Creature* l_IronGunner = me->SummonCreature(eBlackhandCreatures::IronGunner, g_SiegemakerSpawnPos[l_I]))
                                    l_IronGunner->EnterVehicle(l_Siegemaker);
                            }
                        //});
                    }
                }
            }

            void RemoveCombatAurasAndTriggers()
            {
                //me->DespawnCreaturesInArea(g_EntriesToDespawn, 300.0f);
               // me->DespawnGameObjectsInArea({ eBlackhandObjects::OreCollision }, 300.0f);
               // me->DespawnAreaTriggersInArea({ eSpells::OverheatedAreaTrigger, eSpells::SlagCraterAreaTrigger }, 300.0f);

                if (m_Instance != nullptr)
                    return;

                m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::BurnedAura);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::SlaggedAura);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::ImpaledAura);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::MarkedForDeathPeriodic);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::IncendiaryShotAura);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::OverheatedDmgAura);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::ObscuredAura);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::MassiveShatteringSmashCast);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::AshesAura);
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new boss_blackhandAI(p_Creature);
        }
};

/// Blackrock Foundry - 77558
class npc_foundry_blackrock_foundry : public CreatureScript
{
    public:
        npc_foundry_blackrock_foundry() : CreatureScript("npc_foundry_blackrock_foundry") { }

        enum eSpells
        {
            MoltenSlagDoT           = 156401,
            SlagBombAreaTrigger     = 156037,
            SlagBombAoE             = 156044,
            StartP2Jumping          = 173389,
            ExplodingIronStarAoE    = 177438,
            CollapsedFloorVisual    = 162125
        };

        enum eVisuals
        {
            FloorDamaged = 15923
        };

        struct npc_foundry_blackrock_foundryAI : public ScriptedAI
        {
            npc_foundry_blackrock_foundryAI(Creature* p_Creature) : ScriptedAI(p_Creature)
            {
                m_Instance = p_Creature->GetInstanceScript();
            }

            InstanceScript* m_Instance;

            uint32 m_ScaleTime;
            uint32 m_MaxScaleTime = (5 * TimeConstants::MINUTE + 33) * TimeConstants::IN_MILLISECONDS;

            std::set<ObjectGuid> m_AffectedPlayers;

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));

                m_ScaleTime = -1;
            }

            void DoAction(int32 p_Action)
            {
                switch (p_Action)
                {
                    case eBlackhandActions::BlackhandEngaged:
                    {
                       // AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                       // {
                            m_ScaleTime = 0;

                            m_AffectedPlayers.clear();
                       // });

                        break;
                    }
                    case eBlackhandActions::BlackhandDisengaged:
                    {
                        for (ObjectGuid l_Guid : m_AffectedPlayers)
                        {
                            if (Unit* l_Unit = ObjectAccessor::GetUnit(*me, l_Guid))
                                l_Unit->RemoveAura(eSpells::MoltenSlagDoT, me->GetGUID());
                        }

                        m_ScaleTime = -1;

                        break;
                    }
                    case eBlackhandActions::BlackhandStartP2:
                    {
                        for (ObjectGuid l_Guid : m_AffectedPlayers)
                        {
                            if (Unit* l_Unit = ObjectAccessor::GetUnit(*me, l_Guid))
                                l_Unit->RemoveAura(eSpells::MoltenSlagDoT, me->GetGUID());
                        }

                        m_ScaleTime = -1;

                        if (m_Instance != nullptr)
                        {
                            if (GameObject* l_IronStar = ObjectAccessor::GetGameObject(*me, m_Instance->GetGuidData(eFoundryGameObjects::HangingIronStar)))
                                l_IronStar->SetGoState(GOState::GO_STATE_ACTIVE);
                        }

                       // AddTimedDelayedOperation(2 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                        //{
                            me->CastSpell(me, eSpells::StartP2Jumping, true);
                            me->CastSpell(me, eSpells::ExplodingIronStarAoE, true);
                            me->CastSpell(me, eSpells::CollapsedFloorVisual, true);

                            if (m_Instance != nullptr)
                            {
                                if (GameObject* l_Floor = ObjectAccessor::GetGameObject(*me, m_Instance->GetGuidData(eFoundryGameObjects::BlackhandAPlatform)))
                                {
                                    l_Floor->SetDestructibleState(GameObjectDestructibleState::GO_DESTRUCTIBLE_DAMAGED);
                                    l_Floor->SetDisplayId(eVisuals::FloorDamaged);
                                }
                            }
                        //});

                        break;
                    }
                    default:
                        break;
                }
            }

            void SpellHitTarget(Unit* p_Target, SpellInfo const* p_SpellInfo) override
            {
                if (p_Target == nullptr)
                    return;

                switch (p_SpellInfo->Id)
                {
                    case eSpells::StartP2Jumping:
                    {
                        p_Target->GetMotionMaster()->MoveJump(g_StartP2JumpPos, 30.0f, 10.0f);
                        break;
                    }
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 p_Diff) override
            {
               // UpdateOperations(p_Diff);

                if (m_ScaleTime != -1)
                {
                    m_ScaleTime += p_Diff;

                    std::list<Unit*> l_TargetList;

                    Trinity::AnyUnfriendlyUnitInObjectRangeCheck l_Check(me, me, 90.0f);
                    Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> l_Searcher(me, l_TargetList, l_Check);
                    //me->VisitNearbyObject(90.0f, l_Searcher);

                    float l_BaseRadius = 54.5f;
                    float l_ProgressPCT = float(m_ScaleTime) * 100.0f / float(m_MaxScaleTime);
                    float l_RealRadius = l_BaseRadius - (l_BaseRadius * (l_ProgressPCT / 100.0f));

                    if (!l_TargetList.empty())
                    {
                        l_TargetList.remove_if([this, l_BaseRadius, l_RealRadius](Unit* p_Unit) -> bool
                        {
                            if (p_Unit == nullptr)
                                return true;

                            if (p_Unit->GetDistance(me) > l_BaseRadius)
                                return true;

                            if (p_Unit->GetDistance(me) < l_RealRadius)
                                return true;

                            return false;
                        });
                    }

                    std::set<ObjectGuid> l_Targets;

                    for (Unit* l_Iter : l_TargetList)
                    {
                        l_Targets.insert(l_Iter->GetGUID());

                        if (!l_Iter->HasAura(eSpells::MoltenSlagDoT, me->GetGUID()))
                        {
                            m_AffectedPlayers.insert(l_Iter->GetGUID());
                            me->CastSpell(l_Iter, eSpells::MoltenSlagDoT, true);
                        }
                    }

                    for (std::set<ObjectGuid>::iterator l_Iter = m_AffectedPlayers.begin(); l_Iter != m_AffectedPlayers.end();)
                    {
                        if (l_Targets.find((*l_Iter)) != l_Targets.end())
                        {
                            ++l_Iter;
                            continue;
                        }

                        if (Unit* l_Unit = ObjectAccessor::GetUnit(*me, (*l_Iter)))
                        {
                            l_Iter = m_AffectedPlayers.erase(l_Iter);
                            l_Unit->RemoveAura(eSpells::MoltenSlagDoT, me->GetGUID());

                            continue;
                        }

                        ++l_Iter;
                    }

                    std::list<AreaTrigger*> l_SlagBombList;
                    //me->GetAreaTriggerListWithSpellIDInRange(l_SlagBombList, eSpells::SlagBombAreaTrigger, 90.0f);

                    for (AreaTrigger* l_SlagBomb : l_SlagBombList)
                    {
                        if (l_SlagBomb->GetDistance(me) > l_BaseRadius)
                            continue;

                        if (l_SlagBomb->GetDistance(me) < l_RealRadius)
                            continue;

                        if (Unit* l_Caster = l_SlagBomb->GetCaster())
                        {
                            l_Caster->CastSpell(l_Caster, eSpells::SlagBombAoE, true);
                            l_SlagBomb->Remove();
                        }
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_blackrock_foundryAI(p_Creature);
        }
};

/// Slag Bomb - 77343
class npc_foundry_slag_bomb : public CreatureScript
{
    public:
        npc_foundry_slag_bomb() : CreatureScript("npc_foundry_slag_bomb") { }

        enum eSpells
        {
            SlagBombVisual  = 156036,
            SlagBombArming  = 156035,
            SlagBombAoE     = 156044,
            SlaggedAura     = 156047
        };

        struct npc_foundry_slag_bombAI : public ScriptedAI
        {
            npc_foundry_slag_bombAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));

                me->CastSpell(me, eSpells::SlagBombVisual, true);
                me->CastSpell(me, eSpells::SlagBombArming, true);
            }

            void SpellHitTarget(Unit* p_Target, SpellInfo const* p_SpellInfo) override
            {
                if (p_Target == nullptr)
                    return;

                if (p_SpellInfo->Id == eSpells::SlagBombAoE)
                    me->CastSpell(p_Target, eSpells::SlaggedAura, true);
            }

            void OnSpellCasted(SpellInfo const* p_SpellInfo)
            {
                if (p_SpellInfo->Id == eSpells::SlagBombAoE)
                    me->DespawnOrUnsummon(200);
            }

            void UpdateAI(uint32  p_Diff) override
            {
               // UpdateOperations(p_Diff);
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_slag_bombAI(p_Creature);
        }
};

/// Ceiling Stalker - 77570
class npc_foundry_ceiling_stalker : public CreatureScript
{
    public:
        npc_foundry_ceiling_stalker() : CreatureScript("npc_foundry_ceiling_stalker") { }

        struct npc_foundry_ceiling_stalkerAI : public ScriptedAI
        {
            npc_foundry_ceiling_stalkerAI(Creature* p_Creature) : ScriptedAI(p_Creature)
            {
                m_Instance = p_Creature->GetInstanceScript();
            }

            InstanceScript* m_Instance;

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));
            }

            void JustSummoned(Creature* p_Summon) override
            {
                if (m_Instance == nullptr)
                    return;

                if (Creature* l_Blackhand = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::BossBlackhand)))
                {
                    if (l_Blackhand->IsAIEnabled)
                        l_Blackhand->AI()->JustSummoned(p_Summon);
                }
            }

            void SummonedCreatureDespawn(Creature* p_Summon) override
            {
                if (m_Instance == nullptr)
                    return;

                if (Creature* l_Blackhand = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::BossBlackhand)))
                {
                    if (l_Blackhand->IsAIEnabled)
                        l_Blackhand->AI()->SummonedCreatureDespawn(p_Summon);
                }
            }

            void UpdateAI(uint32 p_Diff) override
            {
                //UpdateOperations(p_Diff);
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_ceiling_stalkerAI(p_Creature);
        }
};

/// Blackrock Foundry (Demolition stalker) - 77572
class npc_foundry_brf_demolition_stalker : public CreatureScript
{
    public:
        npc_foundry_brf_demolition_stalker() : CreatureScript("npc_foundry_brf_demolition_stalker") { }

        enum eSpell
        {
            DemolitionSmallAura = 156458
        };

        struct npc_foundry_brf_demolition_stalkerAI : public ScriptedAI
        {
            npc_foundry_brf_demolition_stalkerAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));

                me->CastSpell(me, eSpell::DemolitionSmallAura, true);
            }

            void UpdateAI(uint32 p_Diff) override
            {
               // UpdateOperations(p_Diff);
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_brf_demolition_stalkerAI(p_Creature);
        }
};

/// Blackrock Foundry (Massive Demolition stalker) - 77577
class npc_foundry_brf_massive_demolition_stalker : public CreatureScript
{
    public:
        npc_foundry_brf_massive_demolition_stalker() : CreatureScript("npc_foundry_brf_massive_demolition_stalker") { }

        enum eSpell
        {
            MassiveDemolitionAura = 156460
        };

        struct npc_foundry_brf_massive_demolition_stalkerAI : public ScriptedAI
        {
            npc_foundry_brf_massive_demolition_stalkerAI(Creature* p_Creature) : ScriptedAI(p_Creature)
            {
                m_Instance = p_Creature->GetInstanceScript();
            }

            InstanceScript* m_Instance;

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));

                me->CastSpell(me, eSpell::MassiveDemolitionAura, true);
            }

            void JustSummoned(Creature* p_Summon) override
            {
                if (m_Instance == nullptr)
                    return;

                if (Creature* l_Blackhand = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::BossBlackhand)))
                {
                    if (l_Blackhand->IsAIEnabled)
                        l_Blackhand->AI()->JustSummoned(p_Summon);
                }
            }

            void SummonedCreatureDespawn(Creature* p_Summon) override
            {
                if (m_Instance == nullptr)
                    return;

                if (Creature* l_Blackhand = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::BossBlackhand)))
                {
                    if (l_Blackhand->IsAIEnabled)
                        l_Blackhand->AI()->SummonedCreatureDespawn(p_Summon);
                }
            }

            void UpdateAI(uint32 p_Diff) override
            {
               // UpdateOperations(p_Diff);
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_brf_massive_demolition_stalkerAI(p_Creature);
        }
};

/// Rubble Pile - 77405
class npc_foundry_rubble_pile : public CreatureScript
{
    public:
        npc_foundry_rubble_pile() : CreatureScript("npc_foundry_rubble_pile") { }

        enum eSpells
        {
            OreVisualAura       = 156268,
            ImpalingThrowPile   = 156110
        };

        struct npc_foundry_rubble_pileAI : public ScriptedAI
        {
            npc_foundry_rubble_pileAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

            ObjectGuid m_OreCollisionGuid;

            void Reset() override
            {
               // m_OreCollisionGuid = 0;

                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));

                me->CastSpell(me, eSpells::OreVisualAura, true);

               // AddTimedDelayedOperation(100, [this]() -> void
               // {
                    if (GameObject* l_OreCollision = me->FindNearestGameObject(eBlackhandObjects::OreCollision, 1.0f))
                        m_OreCollisionGuid = l_OreCollision->GetGUID();
                //});
            }

            void SpellHit(Unit* p_Attacker, SpellInfo const* p_SpellInfo) override
            {
                if (p_SpellInfo->Id == eSpells::ImpalingThrowPile)
                {
                    if (GameObject* l_OreCollision = ObjectAccessor::GetGameObject(*me, m_OreCollisionGuid))
                        l_OreCollision->Delete();

                    me->DespawnOrUnsummon(50);
                }
            }

            void UpdateAI(uint32 p_Diff) override
            {
                //UpdateOperations(p_Diff);
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_rubble_pileAI(p_Creature);
        }
};

/// Siegemaker - 77342
class npc_foundry_siegemaker : public CreatureScript
{
    public:
        npc_foundry_siegemaker() : CreatureScript("npc_foundry_siegemaker") { }

        enum eSpells
        {
            SummonIronHordeTank     = 156795,
            BlackironPlating        = 156667,
            FixateSearcher          = 156652,
            Fixate                  = 156653,
            BatteringRamPeriodic    = 156643,
            SlagBombForSiegemaker   = 156044,
            EnergizePeriodic        = 157988,
            MortarSearcher          = 156529,
            MortarCast              = 156530,
            OverdriveAura           = 159199,
            SlagBombAreaTrigger     = 156037,
            ImpalingThrowDamaging   = 156111,
            DamagedTankAura         = 156231,
            SlaggedForSiegemaker    = 157322,
            ObscuredAura            = 156785
        };

        enum eMove
        {
            MoveIntoRoom = 1
        };

        struct npc_foundry_siegemakerAI : public ScriptedAI
        {
            npc_foundry_siegemakerAI(Creature* p_Creature) : ScriptedAI(p_Creature), summons(p_Creature)
            {
                m_Instance = p_Creature->GetInstanceScript();
            }

            InstanceScript* m_Instance;
            SummonList summons;
            ObjectGuid m_Target;
            ObjectGuid m_PortCullisGuid;

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);

               // me->setPowerType(Powers::POWER_ENERGY);
                me->SetMaxPower(Powers::POWER_ENERGY, 100);
                me->SetPower(Powers::POWER_ENERGY, 0);

                me->AddUnitState(UnitState::UNIT_STATE_IGNORE_PATHFINDING);

                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG2_REGENERATE_POWER));

                me->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL | UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_NOT_SELECTABLE));
                me->AddUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));

              //  m_Target = 0;
               // m_PortCullisGuid = 0;
            }

            void SpellHit(Unit* p_Caster, SpellInfo const* p_SpellInfo) override
            {
                switch (p_SpellInfo->Id)
                {
                    case eSpells::SummonIronHordeTank:
                    {
                       // if (GameObject* l_Portcullis = me->FindNearestGameObject(20.0f))
                       // {
                           // m_PortCullisGuid = l_Portcullis->GetGUID();

                           // l_Portcullis->SetGoState(GOState::GO_STATE_ACTIVE);
                       // }

                        float l_X = me->m_positionX + 30.0f/* * cos(me->m_orientation)*/;
                        float l_Y = me->m_positionY + 30.0f/* * sin(me->m_orientation)*/;

                        me->SetWalk(false);
                        me->GetMotionMaster()->MovePoint(eMove::MoveIntoRoom, Position(l_X, l_Y, me->m_positionZ,0.f ), false);
                        break;
                    }
                    case eSpells::SlagBombForSiegemaker:
                    case eSpells::ImpalingThrowDamaging:
                    {
                        if (p_SpellInfo->Id == eSpells::ImpalingThrowDamaging)
                            me->CastSpell(me, eSpells::DamagedTankAura, true);

                        me->RemoveAura(eSpells::BlackironPlating);
                        break;
                    }
                    default:
                        break;
                }
            }

            void MovementInform(uint32 p_Type, uint32 p_ID) override
            {
                if (p_Type != MovementGeneratorType::POINT_MOTION_TYPE)
                    return;

                if (p_ID == eMove::MoveIntoRoom)
                {
                    me->ApplySpellImmune(0, SpellImmunity::IMMUNITY_STATE, AuraType::SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, false);

                    me->SetWalk(true);

                    me->CastSpell(me, eSpells::BlackironPlating, true);
                    me->CastSpell(me, eSpells::BatteringRamPeriodic, true);

                    me->SetReactState(ReactStates::REACT_AGGRESSIVE);

                    me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL | UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_NOT_SELECTABLE));
                    me->RemoveUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));

                    if (TempSummon* l_Temp = me->ToTempSummon())
                    {
                        if (Unit* l_Owner = me->ToTempSummon()->GetSummoner())
                            EnterCombat(l_Owner->GetVictim());
                    }

                    //AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                   // {
                        if (GameObject* l_Portcullis = ObjectAccessor::GetGameObject(*me, m_PortCullisGuid))
                            l_Portcullis->SetGoState(GOState::GO_STATE_READY);
                   // });
                }
            }

            void SpellHitTarget(Unit* p_Target, SpellInfo const* p_SpellInfo) override
            {
                if (p_Target == nullptr)
                    return;

                switch (p_SpellInfo->Id)
                {
                    case eSpells::FixateSearcher:
                    {
                        me->CastSpell(p_Target, eSpells::Fixate, true);
                        break;
                    }
                    case eSpells::Fixate:
                    {
                        m_Target = p_Target->GetGUID();

                        DoResetThreat();
                        me->AddThreat(p_Target, 1000000.0f);

                        AttackStart(p_Target);

                        me->ClearUnitState(UnitState::UNIT_STATE_CASTING);
                        break;
                    }
                    case eSpells::MortarSearcher:
                    {
                        me->CastSpell(p_Target, eSpells::MortarCast, false);
                        break;
                    }
                    default:
                        break;
                }
            }

            void OnSpellCasted(SpellInfo const* p_SpellInfo)
            {
                switch (p_SpellInfo->Id)
                {
                    case eSpells::MortarCast:
                    {
                        me->CastSpell(me, eSpells::OverdriveAura, true);
                        break;
                    }
                    default:
                        break;
                }
            }

            void EnterCombat(Unit* /*p_Attacker*/) override
            {
                if (me->GetReactState() == ReactStates::REACT_PASSIVE)
                    return;

                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me, 2);

                DoZoneInCombat(me, 100.0f);

                me->CastSpell(me, eSpells::EnergizePeriodic, true);
                me->CastSpell(me, eSpells::FixateSearcher, true);
            }

            void JustSummoned(Creature* p_Summon) override
            {
                if (p_Summon->GetEntry() == eBlackhandCreatures::IronGunner)
                    summons.Summon(p_Summon);
            }

            void JustDied(Unit* /*p_Killer*/) override
            {
                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void PassengerBoarded(Unit* p_Passenger, int8 p_SeatID, bool p_Apply) override
            {
                if (!p_Apply && p_Passenger->ToCreature())
                    p_Passenger->ToCreature()->DespawnOrUnsummon();
            }

            void SetPower(Powers p_Power, int32 p_Value)
            {
                if (p_Power != Powers::POWER_ENERGY)
                    return;

                if (p_Value >= 100)
                {
                    me->SetPower(Powers::POWER_ENERGY, 0);
                    me->CastSpell(me, eSpells::MortarSearcher, true);
                }
            }

            void RegeneratePower(Powers p_Power, int32& p_Value)
            {
                /// Only regens by script
                p_Value = 0;
            }

            void UpdateAI(uint32 p_Diff) override
            {
               // UpdateOperations(p_Diff);

                std::list<AreaTrigger*> l_SlagBombList;
                //me->GetAreaTriggerListWithSpellIDInRange(l_SlagBombList, eSpells::SlagBombAreaTrigger, 2.0f);

                for (AreaTrigger* l_SlagBomb : l_SlagBombList)
                {
                    if (Unit* l_Caster = l_SlagBomb->GetCaster())
                    {
                        l_Caster->CastSpell(l_Caster, eSpells::SlagBombForSiegemaker, true);
                        l_Caster->CastSpell(l_Caster, eSpells::SlaggedForSiegemaker, true);
                        l_SlagBomb->Remove();
                    }
                }

                if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                    return;

                if (Player* l_Target = ObjectAccessor::GetPlayer(*me, m_Target))
                {
                    if (!l_Target->IsAlive() || l_Target->HasAura(eSpells::ObscuredAura))
                    {
                        m_Target.Clear();
                        me->CastSpell(me, eSpells::Fixate, true);
                        return;
                    }

                    if (!me->IsWithinMeleeRange(l_Target))
                    {
                        me->SetWalk(true);
                        me->GetMotionMaster()->MovePoint(0, *l_Target);
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_siegemakerAI(p_Creature);
        }
};

/// Blaze Controller - 77610
class npc_foundry_blaze_controller : public CreatureScript
{
    public:
        npc_foundry_blaze_controller() : CreatureScript("npc_foundry_blaze_controller") { }

        enum eSpells
        {
            BlazeControlAura    = 156532,
            BlazeGrowthAura     = 156533,
            BlazeAreaTrigger    = 156605
        };

        struct npc_foundry_blaze_controllerAI : public ScriptedAI
        {
            npc_foundry_blaze_controllerAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

            float m_Orientation;
            InstanceScript* m_Instance;

            ObjectGuid m_Controller;

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));
                me->AddUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));

                me->CastSpell(me, eSpells::BlazeControlAura, true);
                me->CastSpell(me, eSpells::BlazeGrowthAura, true);
                me->CastSpell(me, eSpells::BlazeAreaTrigger, true);

                me->DespawnOrUnsummon(60 * TimeConstants::IN_MILLISECONDS);

                m_Orientation = me->GetEntry() == eBlackhandCreatures::BlazeController ? frand(0,float( 2.0f * M_PI)) : float( M_PI / 2.0f);
                m_Controller.Clear();
            }

            void DoAction(int32 p_Action)
            {
                switch (p_Action)
                {
                    case eBlackhandActions::BlackhandSpreadBlaze:
                    {
                        std::list<AreaTrigger*> l_BlazeList;
                       // me->GetAreaTriggerListWithSpellIDInRange(l_BlazeList, eSpells::BlazeAreaTrigger, 12.0f);

                        for (uint8 l_I = 0; l_I < eBlackhandDatas::MaxBlazeSpreadCount; ++l_I)
                        {
                            float l_Range   = 10.0f;
                            float l_X       = me->m_positionX + l_Range * cos(m_Orientation);
                            float l_Y       = me->m_positionY + l_Range * sin(m_Orientation);
                            float l_Z       = me->m_positionZ;

                            Position l_Pos = { l_X, l_Y, l_Z, m_Orientation };

                            /// Don't even process if controller isn't here anymore//???
                            bool l_Okay = !m_Controller ? ObjectAccessor::GetCreature(*me,  m_Controller) != nullptr : true;
                            for (AreaTrigger* l_Blaze : l_BlazeList)
                            {
                                if (!l_Okay)
                                    break;

                                //if (l_Blaze->IsNearPosition(&l_Pos, 1.0f))
                               // {
                                    l_Okay = false;
                                    break;
                               // }
                            }

                            if (l_Okay)
                            {
                                if (Creature* l_Blaze = me->SummonCreature(eBlackhandCreatures::Blaze, l_Pos, TempSummonType::TEMPSUMMON_TIMED_DESPAWN, 60 * TimeConstants::IN_MILLISECONDS))
                                {
                                    if (l_Blaze->IsAIEnabled)
                                        l_Blaze->AI()->SetGUID(!m_Controller ? m_Controller : me->GetGUID());
                                }
                            }

                            m_Orientation += float (M_PI / 2.0f);

                            Position::NormalizeOrientation(m_Orientation);
                        }

                        break;
                    }
                    default:
                        break;
                }
            }

            void SetGUID(ObjectGuid p_Guid, int32 p_ID /*= 0*/)
            {
                m_Controller = p_Guid;
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_blaze_controllerAI(p_Creature);
        }
};

/// Iron Soldier - 77665
class npc_foundry_iron_soldier : public CreatureScript
{
    public:
        npc_foundry_iron_soldier() : CreatureScript("npc_foundry_iron_soldier") { }

        enum eSpells
        {
            ObscuredAura            = 156785,
            ExplosiveRoundPeriodic  = 156698,
            ExplosiveRoundSearcher  = 156730,
            ExplosiveRoundCast      = 156728
        };

        struct npc_foundry_iron_soldierAI : public ScriptedAI
        {
            npc_foundry_iron_soldierAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

            void Reset() override
            {
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));

                me->CastSpell(me, eSpells::ObscuredAura, true);
                me->CastSpell(me, eSpells::ExplosiveRoundPeriodic, true);
            }

            void SpellHitTarget(Unit* p_Target, SpellInfo const* p_SpellInfo) override
            {
                if (p_Target == nullptr)
                    return;

                switch (p_SpellInfo->Id)
                {
                    case eSpells::ExplosiveRoundSearcher:
                    {
                        me->CastSpell(p_Target, eSpells::ExplosiveRoundCast, false);
                        break;
                    }
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 p_Diff) override { }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_iron_soldierAI(p_Creature);
        }
};

/// Blackrock Foundry (Phase 3) - 77628
class npc_foundry_blackrock_foundry_third_phase : public CreatureScript
{
    public:
        npc_foundry_blackrock_foundry_third_phase() : CreatureScript("npc_foundry_blackrock_foundry_third_phase") { }

        enum eSpells
        {
            ShatteredFloorAoE       = 177487,
            StartP3                 = 177489,
            PhaseTransitionSafeFall = 161359,
            OverheatedAreaTrigger   = 156859
        };

        struct npc_foundry_blackrock_foundry_third_phaseAI : public ScriptedAI
        {
            npc_foundry_blackrock_foundry_third_phaseAI(Creature* p_Creature) : ScriptedAI(p_Creature)
            {
                m_IsForThirdPhase = p_Creature->m_positionZ <= m_ThirdPhaseZ;
            }

            bool m_IsForThirdPhase;

            float m_ThirdPhaseZ = 520.0f;

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));
            }

            void DoAction(int32  p_Action) 
            {
                switch (p_Action)
                {
                    case eBlackhandActions::BlackhandStartP3:
                    {
                        if (m_IsForThirdPhase)
                        {
                            me->CastSpell(me, eSpells::OverheatedAreaTrigger, true);
                            break;
                        }

                        me->CastSpell(me, eSpells::ShatteredFloorAoE, true);
                        me->CastSpell(me, eSpells::StartP3, true);
                        break;
                    }
                    default:
                        break;
                }
            }

            void SpellHitTarget(Unit* p_Target, SpellInfo const* p_SpellInfo) override
            {
                if (p_Target == nullptr)
                    return;

                switch (p_SpellInfo->Id)
                {
                    case eSpells::ShatteredFloorAoE:
                    {
                        if (!p_Target->IsPlayer())
                            break;

                        p_Target->CastSpell(p_Target, eSpells::PhaseTransitionSafeFall, true);
                        break;
                    }
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 p_Diff) override
            {
                //UpdateOperations(p_Diff);
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_blackrock_foundry_third_phaseAI(p_Creature);
        }
};

/// Iron Sentry - 77720
class npc_foundry_iron_sentry : public CreatureScript
{
    public:
        npc_foundry_iron_sentry() : CreatureScript("npc_foundry_iron_sentry") { }

        enum eSpells
        {
            LaserDefense    = 156771,
            IncendiaryShot  = 156772
        };

        struct npc_foundry_iron_sentryAI : public ScriptedAI
        {
            npc_foundry_iron_sentryAI(Creature* p_Creature) : ScriptedAI(p_Creature)
            {
                m_Instance = p_Creature->GetInstanceScript();
            }

            InstanceScript* m_Instance;

            float m_BalconyZ = 617.5f;

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));
                me->AddUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));
            }

            void SpellHit(Unit* p_Caster, SpellInfo const* p_SpellInfo) override
            {
                switch (p_SpellInfo->Id)
                {
                    case eSpells::LaserDefense:
                    {
                        if (!p_Caster->IsPlayer() || m_Instance == nullptr)
                            break;

                        if (Creature* l_Blackhand = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::BossBlackhand)))
                            me->CastSpell(p_Caster, eSpells::IncendiaryShot, true, nullptr, nullptr, l_Blackhand->GetGUID());

                        break;
                    }
                    default:
                        break;
                }
            }

            void SpellHitTarget(Unit* p_Target, SpellInfo const* p_SpellInfo) override
            {
                if (p_Target == nullptr || p_Target->m_positionZ < m_BalconyZ)
                    return;

                switch (p_SpellInfo->Id)
                {
                    case eSpells::IncendiaryShot:
                    {
                        p_Target->CastSpell(p_Target, eSpells::LaserDefense, true);
                        break;
                    }
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 p_Diff) override
            {
               // UpdateOperations(p_Diff);
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_iron_sentryAI(p_Creature);
        }
};

/// Slag Hole - 77357
class npc_foundry_slag_hole : public CreatureScript
{
    public:
        npc_foundry_slag_hole() : CreatureScript("npc_foundry_slag_hole") { }

        enum eSpells
        {
            SlagHoleVisual      = 157021,
            SlagEruptionCast    = 156928,
            SlagEruptionVisual  = 157029,
            SlagEruptionAoE     = 156930
        };

        struct npc_foundry_slag_holeAI : public ScriptedAI
        {
            npc_foundry_slag_holeAI(Creature* p_Creature) : ScriptedAI(p_Creature)
            {
                m_Instance = p_Creature->GetInstanceScript();
            }

            InstanceScript* m_Instance;

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));
                me->AddUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));

                me->CastSpell(me, eSpells::SlagHoleVisual, true);
            }

            void SpellHit(Unit* p_Caster, SpellInfo const* p_SpellInfo) override
            {
                if (p_SpellInfo->Id == eSpells::SlagEruptionCast)
                    me->CastSpell(me, eSpells::SlagEruptionVisual, true);
            }

            void DoAction(int32 p_Action)
            {
                switch (p_Action)
                {
                    case eBlackhandActions::BlackhandSlagEruption:
                    {
                        me->CastSpell(me, eSpells::SlagEruptionAoE, true);
                        break;
                    }
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 p_Diff) override { }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_slag_holeAI(p_Creature);
        }
};

/// Slag Crater - 77774
class npc_foundry_slag_crater : public CreatureScript
{
    public:
        npc_foundry_slag_crater() : CreatureScript("npc_foundry_slag_crater") { }

        enum eSpells
        {
            SlagCraterAreaTrigger   = 156827,
            SlagEruptionCast        = 156928,
            HugeSlagEruptionAura    = 157032,
            HugeSlagEruptionAoE     = 156948
        };

        struct npc_foundry_slag_craterAI : public ScriptedAI
        {
            npc_foundry_slag_craterAI(Creature* p_Creature) : ScriptedAI(p_Creature)
            {
                m_Instance = p_Creature->GetInstanceScript();
            }

            InstanceScript* m_Instance;

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));
                me->AddUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));
            }

            void SpellHit(Unit* p_Caster, SpellInfo const* p_SpellInfo) override
            {
                if (p_SpellInfo->Id == eSpells::SlagEruptionCast)
                    me->CastSpell(me, eSpells::HugeSlagEruptionAura, true);
            }

            void DoAction(int32 p_Action)
            {
                switch (p_Action)
                {
                    case eBlackhandActions::BlackhandSlagEruption:
                    {
                        me->CastSpell(me, eSpells::HugeSlagEruptionAoE, true);
                        break;
                    }
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 p_Diff) override { }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_slag_craterAI(p_Creature);
        }
};

/// Achievement Stalker - 80831
class npc_foundry_achievement_stalker : public CreatureScript
{
    public:
        npc_foundry_achievement_stalker() : CreatureScript("npc_foundry_achievement_stalker") { }

        enum eSpells
        {
            FallingAshPeriodic  = 163293,
            FallingAshCast      = 163292,
            FallingAshAT        = 163295
        };

        struct npc_foundry_achievement_stalkerAI : public ScriptedAI
        {
            npc_foundry_achievement_stalkerAI(Creature* p_Creature) : ScriptedAI(p_Creature)
            {
                m_Instance = p_Creature->GetInstanceScript();
            }

            InstanceScript* m_Instance;

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));
                me->AddUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));
            }

            void DoAction(int32 p_Action)
            {
                switch (p_Action)
                {
                    case eBlackhandActions::BlackhandDisengaged:
                    {
                        me->RemoveAllAreaTriggers();
                        me->RemoveAura(eSpells::FallingAshPeriodic);
                        break;
                    }
                    case eBlackhandActions::BlackhandStartP3:
                    {
                        me->CastSpell(me, eSpells::FallingAshPeriodic, true);
                        break;
                    }
                    default:
                        break;
                }
            }

            void OnSpellCasted(SpellInfo const* p_SpellInfo)
            {
                switch (p_SpellInfo->Id)
                {
                    case eSpells::FallingAshCast:
                    {
                        me->CastSpell(me, eSpells::FallingAshAT, true);
                        break;
                    }
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 p_Diff) override { }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_achievement_stalkerAI(p_Creature);
        }
};

/// Demolition - 156497
class spell_foundry_demolition : public SpellScriptLoader
{
    public:
        spell_foundry_demolition() : SpellScriptLoader("spell_foundry_demolition") { }

        class spell_foundry_demolition_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_foundry_demolition_SpellScript);

            void HandleDamage(SpellEffIndex /*p_EffIndex*/)
            {
                if (GetHitUnit() == nullptr)
                    return;

               // if (WorldLocation const* l_Dest = GetExplTargetDest())
               // {
                //    if (Player* l_Player = GetHitUnit()->ToPlayer())
                 //   {
                 //       float l_Damage      = (float)GetSpell()->GetDamage();
                 //       float l_Distance    = std::min(12.0f, l_Player->GetDistance(l_Dest));
                 //       float l_NewDamages  = std::max(1.0f, l_Damage / l_Distance);

                 //       GetSpell()->SetDamage((uint32)l_NewDamages);
                   // }
               // }
            }

            void Register() override
            {
                OnEffectLaunchTarget += SpellEffectFn(spell_foundry_demolition_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_foundry_demolition_SpellScript();
        }
};

/// Massive Demolition - 156479
class spell_foundry_massive_demolition : public SpellScriptLoader
{
    public:
        spell_foundry_massive_demolition() : SpellScriptLoader("spell_foundry_massive_demolition") { }

        class spell_foundry_massive_demolition_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_foundry_massive_demolition_SpellScript);

            void HandleDamage(SpellEffIndex /*p_EffIndex*/)
            {
                if (GetHitUnit() == nullptr)
                    return;

               // if (WorldLocation const* l_Dest = GetExplTargetDest())
               // {
                   // if (Player* l_Player = GetHitUnit()->ToPlayer())
                   // {
                       // float l_Damage      = (float)GetSpell()->GetDamage();
                       // float l_Distance    = std::min(900.0f, std::max(10.0f, l_Player->GetDistance(l_Dest)));
                       // float l_NewDamages  = std::max(1.0f, l_Damage / (l_Distance / 10.0f));

                      //  GetSpell()->SetDamage((uint32)l_NewDamages);
                   // }
               // }
            }

            void Register() override
            {
                OnEffectLaunchTarget += SpellEffectFn(spell_foundry_massive_demolition_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_foundry_massive_demolition_SpellScript();
        }
};

/// Marked for Death - 156096
class spell_foundry_marked_for_death : public SpellScriptLoader
{
    public:
        spell_foundry_marked_for_death() : SpellScriptLoader("spell_foundry_marked_for_death") { }

        class spell_foundry_marked_for_death_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_foundry_marked_for_death_AuraScript);

            enum eSpells
            {
                ImpalingThrowPlayer         = 156107,
                ImpalingThrowPile           = 156110,
                ImpalingThrowSiegemaker     = 156111,
                ImpalingThrowP3             = 175013,
                ImpalingThrowExtraMissile   = 174933
            };

            void OnTick(AuraEffect const* /*p_AurEff*/)
            {
                Unit* l_Caster = GetCaster();
                Unit* l_Target = GetUnitOwner();

                if (l_Caster == nullptr || l_Target == nullptr)
                    return;

                uint8 l_PhaseID = 0;
                if (Creature* l_Blackhand = l_Caster->ToCreature())
                {
                    boss_blackhand::boss_blackhandAI* l_AI = CAST_AI(boss_blackhand::boss_blackhandAI, l_Blackhand->GetAI());
                    if (l_AI != nullptr)
                        l_PhaseID = l_AI->m_PhaseID;
                }

                std::list<Unit*> l_PotentialTargets;

                Trinity::AnyUnitInObjectRangeCheck l_Check(l_Caster, l_Caster->GetDistance(l_Target));
                Trinity::UnitListSearcher<Trinity::AnyUnitInObjectRangeCheck> l_Searcher(l_Caster, l_PotentialTargets, l_Check);
              //  l_Caster->VisitNearbyObject(l_Caster->GetDistance(l_Target), l_Searcher);

                if (!l_PotentialTargets.empty())
                {
                    l_PotentialTargets.remove_if([this, l_Caster, l_Target](Unit* p_Unit) -> bool
                    {
                        if (p_Unit == nullptr)
                            return true;

                        if (!p_Unit->IsPlayer() && p_Unit->GetEntry() != eBlackhandCreatures::RubblePile && p_Unit->GetEntry() != eBlackhandCreatures::Siegemaker)
                            return true;

                        if (!p_Unit->IsInBetween(l_Target, l_Caster, 2.0f))
                            return true;

                        if (p_Unit->HasAura(GetSpellInfo()->Id))
                            return true;

                        return false;
                    });
                }

                if (!l_PotentialTargets.empty())
                {
                    l_PotentialTargets.sort(Trinity::ObjectDistanceOrderPred(l_Caster));

                    if (l_PhaseID < 2)
                        l_Target = l_PotentialTargets.front();
                }

                if (l_PhaseID < 2)
                {
                    if (l_Target->IsPlayer())
                        l_Caster->CastSpell(l_Target, eSpells::ImpalingThrowPlayer, true);
                    else
                    {
                        switch (l_Target->GetEntry())
                        {
                        case eBlackhandCreatures::RubblePile:
                            l_Caster->CastSpell(l_Target, eSpells::ImpalingThrowPile, true);
                            break;
                        case eBlackhandCreatures::Siegemaker:
                            l_Caster->CastSpell(l_Target, eSpells::ImpalingThrowSiegemaker, true);
                            break;
                        default:
                            break;
                        }
                    }
                }
                else
                {
                    l_Caster->CastSpell(l_Target, eSpells::ImpalingThrowP3, true);
                    l_Caster->CastSpell(l_Target, eSpells::ImpalingThrowExtraMissile, true);

                    for (Unit* l_Iter : l_PotentialTargets)
                    {
                        if (l_Iter == l_Target)
                            continue;

                        l_Caster->CastSpell(l_Iter, eSpells::ImpalingThrowP3, true);
                        l_Caster->CastSpell(l_Iter, eSpells::ImpalingThrowExtraMissile, true);
                    }
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_foundry_marked_for_death_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_foundry_marked_for_death_AuraScript();
        }
};

/// Blaze Growth - 156533
class spell_foundry_blaze_growth : public SpellScriptLoader
{
    public:
        spell_foundry_blaze_growth() : SpellScriptLoader("spell_foundry_blaze_growth") { }

        class spell_foundry_blaze_growth_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_foundry_blaze_growth_AuraScript);

            void OnTick(AuraEffect const* /*p_AurEff*/)
            {
                if (Creature* l_Blaze = GetCaster()->ToCreature())
                {
                    if (l_Blaze->IsAIEnabled)
                        l_Blaze->AI()->DoAction(eBlackhandActions::BlackhandSpreadBlaze);
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_foundry_blaze_growth_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_foundry_blaze_growth_AuraScript();
        }
};

/// Energize (triggered) - 157987
class spell_foundry_siegemaker_energize : public SpellScriptLoader
{
    public:
        spell_foundry_siegemaker_energize() : SpellScriptLoader("spell_foundry_siegemaker_energize") { }

        enum eSpell
        {
            OverdriveAura = 159199
        };

        class spell_foundry_siegemaker_energize_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_foundry_siegemaker_energize_SpellScript);

            void HandleEnergize(SpellEffIndex /*p_EffIndex*/)
            {
                if (Unit* l_Caster = GetCaster())
                {
                    uint8 l_StackAmount = 0;
                    if (Aura* l_Aura = l_Caster->GetAura(eSpell::OverdriveAura))
                        l_StackAmount = l_Aura->GetStackAmount();

                    if (l_StackAmount)
                    {
                        if (roll_chance_i(l_StackAmount * 20))
                            l_Caster->EnergizeBySpell(l_Caster, GetSpellInfo()->Id, 1, Powers::POWER_ENERGY);
                    }
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_foundry_siegemaker_energize_SpellScript::HandleEnergize, EFFECT_0, SPELL_EFFECT_ENERGIZE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_foundry_siegemaker_energize_SpellScript();
        }
};

/// Fixate (searcher) - 156652
class spell_foundry_fixate_searcher : public SpellScriptLoader
{
    public:
        spell_foundry_fixate_searcher() : SpellScriptLoader("spell_foundry_fixate_searcher") { }

        class spell_foundry_fixate_searcher_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_foundry_fixate_searcher_SpellScript);

            void CorrectTargets(std::list<WorldObject*>& p_Targets)
            {
                if (p_Targets.empty())
                    return;

                p_Targets.sort(Trinity::ObjectDistanceOrderPred(GetCaster()));

                WorldObject* l_Target = p_Targets.front();

                p_Targets.clear();

                p_Targets.push_back(l_Target);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_foundry_fixate_searcher_SpellScript::CorrectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_foundry_fixate_searcher_SpellScript();
        }
};

/// Throw Slag Bombs - 156031
/// Throw Slag Bombs - 156033
/// Throw Slag Bombs - 156034
class spell_foundry_throw_slag_bombs : public SpellScriptLoader
{
    public:
        spell_foundry_throw_slag_bombs() : SpellScriptLoader("spell_foundry_throw_slag_bombs") { }

        class spell_foundry_throw_slag_bombs_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_foundry_throw_slag_bombs_SpellScript);

            void ChangeSummonPos(SpellEffIndex p_EffIndex)
            {
                if (GetCaster() == nullptr)
                    return;

                if (Creature* l_Boss = GetCaster()->ToCreature())
                {
                    boss_blackhand::boss_blackhandAI* l_AI = CAST_AI(boss_blackhand::boss_blackhandAI, l_Boss->GetAI());
                    if (l_AI == nullptr)
                        return;

                    if (l_AI->m_PhaseID == 0 || l_AI->m_PhaseID == 2)
                        return;

                    SpellInfo const* l_SpellInfo    = GetSpellInfo();
                    WorldLocation l_SummonPos       = *GetExplTargetDest();

                    float l_Angle   = l_SpellInfo->GetEffect(p_EffIndex)->TargetB.CalcDirectionAngle();
                    float l_Dist    = l_SpellInfo->GetEffect(p_EffIndex)->CalcRadius(l_Boss);

                    if (l_SpellInfo->GetEffect(p_EffIndex)->TargetB.GetTarget() == Targets::TARGET_DEST_DEST_RANDOM)
                        l_Dist *= float(rand_norm());

                    Position l_Pos = { l_SummonPos.m_positionX, l_SummonPos.m_positionY, l_SummonPos.m_positionZ,0.f };

                  //  l_Boss->GetNearPoint(l_Pos, 0.0f, l_Dist, l_Angle);

                    float l_FloorZ      = 604.376f;
                    float l_DiffX       = l_SummonPos.m_positionX - l_Pos.m_positionX;
                    float l_DiffY       = l_SummonPos.m_positionY - l_Pos.m_positionY;
                    float l_DiffZ       = l_SummonPos.m_positionZ - l_FloorZ;

                    Position l_Offset   = { -l_DiffX, -l_DiffY, -l_DiffZ, 0.0f };

                    l_SummonPos.RelocateOffset(l_Offset);
                    SetExplTargetDest(l_SummonPos);
                    GetHitDest()->RelocateOffset(l_Offset);
                }
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_foundry_throw_slag_bombs_SpellScript::ChangeSummonPos, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_foundry_throw_slag_bombs_SpellScript();
        }
};

/// Explosive Round (periodic) - 156698
class spell_foundry_explosive_round : public SpellScriptLoader
{
    public:
        spell_foundry_explosive_round() : SpellScriptLoader("spell_foundry_explosive_round") { }

        enum eSpell
        {
            ExplosiveRoundSearcher = 156730
        };

        class spell_foundry_explosive_round_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_foundry_explosive_round_AuraScript);

            void OnTick(AuraEffect const* /*p_AurEff*/)
            {
                if (Unit* l_Caster = GetCaster())
                {
                    if (l_Caster->HasUnitState(UnitState::UNIT_STATE_CASTING))
                        return;

                    l_Caster->CastSpell(l_Caster, eSpell::ExplosiveRoundSearcher, true);
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_foundry_explosive_round_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_foundry_explosive_round_AuraScript();
        }
};

/// Slag Eruption - 156928
class spell_foundry_slag_eruption : public SpellScriptLoader
{
    public:
        spell_foundry_slag_eruption() : SpellScriptLoader("spell_foundry_slag_eruption") { }

        class spell_foundry_slag_eruption_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_foundry_slag_eruption_SpellScript);

            void CorrectTargets(std::list<WorldObject*>& p_Targets)
            {
                if (p_Targets.empty())
                    return;

                p_Targets.remove_if([this](WorldObject* p_Object) -> bool
                {
                    if (p_Object == nullptr)
                        return true;

                    if (p_Object->GetEntry() != eBlackhandCreatures::SlagHole &&
                        p_Object->GetEntry() != eBlackhandCreatures::SlagCrater)
                        return true;

                    return false;
                });
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_foundry_slag_eruption_SpellScript::CorrectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_foundry_slag_eruption_SpellScript();
        }

        class spell_foundry_slag_eruption_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_foundry_slag_eruption_AuraScript);

            void OnTick(AuraEffect const* /*p_AurEff*/)
            {
                if (GetUnitOwner() == nullptr)
                    return;

                if (Creature* l_Slag = GetUnitOwner()->ToCreature())
                {
                    if (l_Slag->IsAIEnabled)
                        l_Slag->AI()->DoAction(eBlackhandActions::BlackhandSlagEruption);
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_foundry_slag_eruption_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_foundry_slag_eruption_AuraScript();
        }
};

/// Attach Slag Bombs - 157000
class spell_foundry_attach_slag_bombs : public SpellScriptLoader
{
    public:
        spell_foundry_attach_slag_bombs() : SpellScriptLoader("spell_foundry_attach_slag_bombs") { }

        class spell_foundry_attach_slag_bombs_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_foundry_attach_slag_bombs_SpellScript);

                void CorrectTargets(std::list<WorldObject*>& p_Targets)
            {
                if (p_Targets.empty())
                    return;

                Unit* l_Caster = GetCaster();
                p_Targets.remove_if([this, l_Caster](WorldObject* p_Object) -> bool
                {
                    if (p_Object == nullptr || !p_Object->IsPlayer())
                        return true;

                    //if (p_Object->ToPlayer()->GetRoleForGroup() == Roles::ROLE_TANK)
                     //   return true;

                    return false;
                });
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_foundry_attach_slag_bombs_SpellScript::CorrectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_foundry_attach_slag_bombs_SpellScript::CorrectTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_foundry_attach_slag_bombs_SpellScript::CorrectTargets, EFFECT_2, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_foundry_attach_slag_bombs_SpellScript();
        }
};

/// Massive Shattering Smash - 158054
class spell_foundry_massive_shattering_smash : public SpellScriptLoader
{
    public:
        spell_foundry_massive_shattering_smash() : SpellScriptLoader("spell_foundry_massive_shattering_smash") { }

        enum eSpell
        {
            Revitalize = 104915
        };

        class spell_foundry_massive_shattering_smash_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_foundry_massive_shattering_smash_SpellScript);

            void CorrectTargets(std::list<WorldObject*>& p_Targets)
            {
                /// If fewer than four targets are damaged by a Massive Shattering Smash
                /// Blackhand will instantly gain 75 Energy, causing the next Massive Shattering Smash to occur more rapidly
                uint32 l_Count = uint32(p_Targets.size());
                Unit* l_Caster = GetCaster();
                if (l_Count < 4)
                {
                    int32 l_BasePoint = 75;

                    l_Caster->CastCustomSpell(l_Caster, eSpell::Revitalize, &l_BasePoint, nullptr, nullptr, true);
                }

                if (Creature* l_Boss = l_Caster->ToCreature())
                {
                    if (!l_Boss->IsAIEnabled)
                        return;

                    boss_blackhand::boss_blackhandAI* l_AI = CAST_AI(boss_blackhand::boss_blackhandAI, l_Boss->GetAI());
                    if (l_AI == nullptr)
                        return;

                    l_AI->m_SmashedCount = l_Count;
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_foundry_massive_shattering_smash_SpellScript::CorrectTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_foundry_massive_shattering_smash_SpellScript();
        }

        class spell_foundry_massive_shattering_smash_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_foundry_massive_shattering_smash_AuraScript);

            void CalculateAmount(AuraEffect const* /*p_AurEff*/, int32& p_Amount, bool& /*p_CanBeRecalculated*/)
            {
                Unit* l_Caster = GetCaster();
                if (l_Caster == nullptr)
                    return;

                uint32 l_Count = 0;
                if (Creature* l_Boss = l_Caster->ToCreature())
                {
                    if (!l_Boss->IsAIEnabled)
                        return;

                    boss_blackhand::boss_blackhandAI* l_AI = CAST_AI(boss_blackhand::boss_blackhandAI, l_Boss->GetAI());
                    if (l_AI == nullptr)
                        return;

                    l_Count = l_AI->m_SmashedCount;
                }

                if (l_Count == 0)
                    return;

                p_Amount /= l_Count;
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_foundry_massive_shattering_smash_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_foundry_massive_shattering_smash_AuraScript();
        }
};

/// Blackhand_A - 230193
class go_foundry_blackhand_platform : public GameObjectScript
{
    public:
        go_foundry_blackhand_platform() : GameObjectScript("go_foundry_blackhand_platform") { }

        struct go_foundry_blackhand_platformAI : public GameObjectAI
        {
            go_foundry_blackhand_platformAI(GameObject* p_GameObject) : GameObjectAI(p_GameObject) { }

            bool ScriptedCollide(float p_X, float p_Y, float p_Z, float* p_OutZ /*= nullptr*/) 
            {
                float const l_Radius    = 70.0f;

                float l_PlatformXCenter = go->m_positionX + 353.0f;
                float l_PlatformYCenter = go->m_positionY - 53.0f;

                float l_PlatformZMin    = go->m_positionZ + 280.0f;
                float l_PlatformZMax    = go->m_positionZ + 300.0f;

                bool l_IsInRadius       = sqrt(std::pow(l_PlatformXCenter - p_X, 2) + std::pow(l_PlatformYCenter - p_Y, 2)) <= l_Radius;
                bool l_IsInHeightRange  = p_Z >= l_PlatformZMin && p_Z <= l_PlatformZMax;

                GameObjectDestructibleState l_State = go->GetDestructibleState();

                if (l_IsInRadius && l_IsInHeightRange && l_State == GameObjectDestructibleState::GO_DESTRUCTIBLE_DAMAGED)
                {
                    float l_ThisFloorHeight     = go->m_positionZ + 283.0f;
                    float l_ThisFloorHeightMin  = go->m_positionZ + 275.0f;

                    if (p_Z >= l_ThisFloorHeightMin)
                    {
                        if (p_OutZ)
                            *p_OutZ = l_ThisFloorHeight;

                        return true;
                    }
                }

                return false;
            }
        };

        GameObjectAI* GetAI(GameObject* p_GameObject) const override
        {
            return new go_foundry_blackhand_platformAI(p_GameObject);
        }
};

/// Slag Bomb - 156037
class areatrigger_foundry_slag_bomb : public AreaTriggerEntityScript
{
    public:
        areatrigger_foundry_slag_bomb() : AreaTriggerEntityScript("areatrigger_foundry_slag_bomb") { }

        enum eSpell
        {
            SlagBombAoE = 156044
        };

        void OnUpdate(AreaTrigger* p_AreaTrigger, uint32 /*p_Time*/) 
        {
            if (Unit* l_Caster = p_AreaTrigger->GetCaster())
            {
                std::list<Unit*> l_TargetList;
                float l_Radius = 2.0f;

                Trinity::AnyUnfriendlyUnitInObjectRangeCheck l_Check(p_AreaTrigger, l_Caster, l_Radius);
                Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> l_Searcher(p_AreaTrigger, l_TargetList, l_Check);
              //  p_AreaTrigger->VisitNearbyObject(l_Radius, l_Searcher);

                for (Unit* l_Iter : l_TargetList)
                {
                    l_Caster->CastSpell(l_Caster, eSpell::SlagBombAoE, true);
                    p_AreaTrigger->Remove();

                    if (Creature* l_SlagBomb = l_Caster->ToCreature())
                    {
                        if (l_SlagBomb->IsAIEnabled)
                            l_SlagBomb->AI()->Talk(0);
                    }

                    break;
                }
            }
        }
        /*
        AreaTriggerEntityScript* GetAI() 
        {
            return nullptr;
        }*/
};

/// Blaze - 156605
class areatrigger_foundry_blaze : public AreaTriggerEntityScript
{
    public:
        areatrigger_foundry_blaze() : AreaTriggerEntityScript("areatrigger_foundry_blaze") { }

        enum eSpell
        {
            Burning = 156604
        };

        std::set<ObjectGuid> m_AffectedPlayers;

        void OnUpdate(AreaTrigger* p_AreaTrigger, uint32 /*p_Time*/)
        {
            if (Unit* l_Caster = p_AreaTrigger->GetCaster())
            {
                std::list<Unit*> l_TargetList;
                float l_Radius = 5.0f;

                Trinity::AnyUnfriendlyUnitInObjectRangeCheck l_Check(l_Caster, l_Caster, l_Radius);
                Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> l_Searcher(l_Caster, l_TargetList, l_Check);
               // l_Caster->VisitNearbyObject(l_Radius, l_Searcher);

                std::set<ObjectGuid> l_Targets;

                for (Unit* l_Iter : l_TargetList)
                {
                    l_Targets.insert(l_Iter->GetGUID());

                    if (!l_Iter->HasAura(eSpell::Burning, l_Caster->GetGUID()))
                    {
                        m_AffectedPlayers.insert(l_Iter->GetGUID());
                        l_Caster->CastSpell(l_Iter, eSpell::Burning, true);
                    }
                }

                for (std::set<ObjectGuid>::iterator l_Iter = m_AffectedPlayers.begin(); l_Iter != m_AffectedPlayers.end();)
                {
                    if (l_Targets.find((*l_Iter)) != l_Targets.end())
                    {
                        ++l_Iter;
                        continue;
                    }

                    if (Unit* l_Unit = ObjectAccessor::GetUnit(*l_Caster, (*l_Iter)))
                    {
                        l_Iter = m_AffectedPlayers.erase(l_Iter);
                        l_Unit->RemoveAura(eSpell::Burning, l_Caster->GetGUID());

                        continue;
                    }

                    ++l_Iter;
                }
            }
        }

        void OnRemove(AreaTrigger* p_AreaTrigger, uint32 /*p_Time*/) 
        {
            if (Unit* l_Caster = p_AreaTrigger->GetCaster())
            {
                for (ObjectGuid l_Guid : m_AffectedPlayers)
                {
                    if (Unit* l_Unit = ObjectAccessor::GetUnit(*l_Caster, l_Guid))
                        l_Unit->RemoveAura(eSpell::Burning, l_Caster->GetGUID());
                }
            }
        }
        /*
        AreaTriggerEntityScript* GetAI()
        {
            return nullptr;
        }*/
};

/// Overheated - 156859
class areatrigger_foundry_overheated : public AreaTriggerEntityScript
{
    public:
        areatrigger_foundry_overheated() : AreaTriggerEntityScript("areatrigger_foundry_overheated")
        {
            m_DamageTimer = 1 * TimeConstants::IN_MILLISECONDS;
        }

        enum eSpell
        {
            OverheatedDmgAura = 156888
        };

        int32 m_DamageTimer;

        std::set<ObjectGuid> m_AffectedPlayers;

        void OnUpdate(AreaTrigger* p_AreaTrigger, uint32 p_Time)
        {
            if (Unit* l_Caster = p_AreaTrigger->GetCaster())
            {
                if (InstanceScript* l_Instance = l_Caster->GetInstanceScript())
                {
                    if (!l_Instance->IsEncounterInProgress())
                    {
                        p_AreaTrigger->Remove();
                        return;
                    }
                }

                std::set<ObjectGuid> l_Targets;

                if (m_DamageTimer)
                {
                    if (m_DamageTimer <= int32(p_Time))
                    {
                        std::list<Unit*> l_TargetList;
                        float l_Radius = 70.0f;

                        Trinity::AnyUnfriendlyUnitInObjectRangeCheck l_Check(l_Caster, l_Caster, l_Radius);
                        Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> l_Searcher(l_Caster, l_TargetList, l_Check);
                        //l_Caster->VisitNearbyObject(l_Radius, l_Searcher);

                        for (Unit* l_Iter : l_TargetList)
                        {
                            l_Targets.insert(l_Iter->GetGUID());

                            if (m_AffectedPlayers.find(l_Iter->GetGUID()) == m_AffectedPlayers.end())
                                m_AffectedPlayers.insert(l_Iter->GetGUID());

                            l_Caster->CastSpell(l_Iter, eSpell::OverheatedDmgAura, true);
                        }

                        m_DamageTimer = 1 * TimeConstants::IN_MILLISECONDS;
                    }
                    else
                        m_DamageTimer -= p_Time;
                }

                for (std::set<ObjectGuid>::iterator l_Iter = m_AffectedPlayers.begin(); l_Iter != m_AffectedPlayers.end();)
                {
                    if (l_Targets.find((*l_Iter)) != l_Targets.end())
                    {
                        ++l_Iter;
                        continue;
                    }

                    if (Unit* l_Unit = ObjectAccessor::GetUnit(*l_Caster, (*l_Iter)))
                    {
                        l_Iter = m_AffectedPlayers.erase(l_Iter);
                        l_Unit->RemoveAura(eSpell::OverheatedDmgAura, l_Caster->GetGUID());

                        continue;
                    }

                    ++l_Iter;
                }
            }
        }

        void OnRemove(AreaTrigger* p_AreaTrigger, uint32 /*p_Time*/)
        {
            if (Unit* l_Caster = p_AreaTrigger->GetCaster())
            {
                for (ObjectGuid l_Guid : m_AffectedPlayers)
                {
                    if (Unit* l_Unit = ObjectAccessor::GetUnit(*l_Caster, l_Guid))
                        l_Unit->RemoveAura(eSpell::OverheatedDmgAura, l_Caster->GetGUID());
                }
            }
        }
        /*
        AreaTriggerEntityScript* GetAI() 
        {
            return nullptr;
        }*/
};

/// Falling Ash - 163295
class areatrigger_foundry_falling_ash : public AreaTriggerEntityScript
{
    public:
        areatrigger_foundry_falling_ash() : AreaTriggerEntityScript("areatrigger_foundry_falling_ash") { }

        bool m_CanUpdate;

        enum eSpell
        {
            AshesAura = 163324
        };

        void OnSetCreatePosition(AreaTrigger* p_AreaTrigger, Unit* p_Caster, Position& p_SourcePosition, Position& p_DestinationPosition, std::list<Position>& /*p_PathToLinearDestination*/)
        {
           // m_CanUpdate = !p_AreaTrigger->GetMap()->IsLFR();

           // p_AreaTrigger->SetTimeToTarget(35 * TimeConstants::IN_MILLISECONDS);

            float l_Range                       = frand(60.0f, 72.0f);
            float l_Orientation                 = frand(0.0f, float (2.0f * M_PI));

            p_SourcePosition                    = *p_Caster;
            p_SourcePosition.m_positionX        = p_SourcePosition.m_positionX + l_Range * cos(l_Orientation);
            p_SourcePosition.m_positionY        = p_SourcePosition.m_positionY + l_Range * sin(l_Orientation);

            p_SourcePosition.m_positionZ        = p_Caster->m_positionZ;

            p_DestinationPosition.m_positionX   = p_SourcePosition.m_positionX;
            p_DestinationPosition.m_positionY   = p_SourcePosition.m_positionY;
            p_DestinationPosition.m_positionZ   = p_SourcePosition.m_positionZ - 90.0f;
        }

        void OnUpdate(AreaTrigger* p_AreaTrigger, uint32 p_Time)
        {
            if (!m_CanUpdate)
                return;

            if (Unit* l_Caster = p_AreaTrigger->GetCaster())
            {
                std::list<Player*> l_TargetList;
                float l_Radius = 1.0f;

                Trinity::AnyPlayerInObjectRangeCheck l_Check(p_AreaTrigger, l_Radius);
                Trinity::PlayerListSearcher<Trinity::AnyPlayerInObjectRangeCheck> l_Searcher(p_AreaTrigger, l_TargetList, l_Check);
              //  p_AreaTrigger->VisitNearbyObject(l_Radius, l_Searcher);

                for (Player* l_Iter : l_TargetList)
                {
                    if (l_Iter->IsGameMaster())
                        continue;

                    l_Iter->CastSpell(l_Iter, eSpell::AshesAura, true);
                    p_AreaTrigger->Remove();

                    if (InstanceScript* l_Instance = l_Iter->GetInstanceScript())
                        l_Instance->SetData(eFoundryDatas::BlackhandAshCollected, l_Iter->GetEntry());

                    break;
                }
            }
        }
        /*
        AreaTriggerEntityScript* GetAI()
        {
            return nullptr;
        }*/
};

/// Blackhand's Crucible Balcony - 10101
class areatrigger_at_foundry_crucible_balcony : public AreaTriggerScript
{
    public:
        areatrigger_at_foundry_crucible_balcony() : AreaTriggerScript("areatrigger_at_foundry_crucible_balcony") { }

        enum eSpells
        {
            IncendiaryShotAura  = 156772,
            LaserDefense        = 156771,
            ObscuredAura        = 156785
        };

        std::map<uint32, float> m_PlayerZChanges;

        void OnEnter(Player* p_Player, AreaTriggerEntry const* /*p_AreaTrigger*/) 
        {
            m_PlayerZChanges[p_Player->GetEntry()] = p_Player->GetPositionZ();

            p_Player->RemoveAura(eSpells::IncendiaryShotAura);
            p_Player->RemoveAura(eSpells::ObscuredAura);
        }

        void OnExit(Player* p_Player, AreaTriggerEntry const* /*p_AreaTrigger*/)
        {
            if (m_PlayerZChanges.find(p_Player->GetEntry()) == m_PlayerZChanges.end())
                return;

            float l_DiffZ = p_Player->m_positionZ - m_PlayerZChanges[p_Player->GetEntry()];
            if (l_DiffZ > 0)
            {
                p_Player->CastSpell(p_Player, eSpells::ObscuredAura, true);
                p_Player->CastSpell(p_Player, eSpells::LaserDefense, true);
            }

            m_PlayerZChanges.erase(p_Player->GetEntry());
        }
};

void AddSC_boss_blackhand()
{
    /// Boss
    new boss_blackhand();/// Blackhand <Warlord of the Blackrock> - 77325

    /// Creatures
    new npc_foundry_blackrock_foundry();/// Blackrock Foundry - 77558
    new npc_foundry_slag_bomb();/// Slag Bomb - 77343
    new npc_foundry_ceiling_stalker();/// Ceiling Stalker - 77570
    new npc_foundry_brf_demolition_stalker();/// Blackrock Foundry (Demolition stalker) - 77572
    new npc_foundry_brf_massive_demolition_stalker();/// Blackrock Foundry (Massive Demolition stalker) - 77577
    new npc_foundry_rubble_pile();/// Rubble Pile - 77405
    new npc_foundry_siegemaker();/// Siegemaker - 77342
    new npc_foundry_blaze_controller();/// Blaze Controller - 77610
    new npc_foundry_iron_soldier();/// Iron Soldier - 77665
    new npc_foundry_blackrock_foundry_third_phase();/// Blackrock Foundry (Phase 3) - 77628
    new npc_foundry_iron_sentry();/// Iron Sentry - 77720
    new npc_foundry_slag_hole();/// Slag Hole - 77357
    new npc_foundry_slag_crater();/// Slag Crater - 77774
    new npc_foundry_achievement_stalker();/// Achievement Stalker - 80831

    /// Spells
    new spell_foundry_demolition();/// Demolition - 156497
    new spell_foundry_massive_demolition();/// Massive Demolition - 156479
    new spell_foundry_marked_for_death();/// Marked for Death - 156096
    new spell_foundry_blaze_growth();/// Blaze Growth - 156533
    new spell_foundry_siegemaker_energize();/// Energize (triggered) - 157987
    new spell_foundry_fixate_searcher();/// Fixate (searcher) - 156652
    new spell_foundry_throw_slag_bombs();/// Throw Slag Bombs - 156031- 156033 - 156034
    new spell_foundry_explosive_round();/// Explosive Round (periodic) - 156698
    new spell_foundry_slag_eruption();/// Slag Eruption - 156928
    new spell_foundry_attach_slag_bombs();/// Attach Slag Bombs - 157000
    new spell_foundry_massive_shattering_smash();/// Massive Shattering Smash - 158054

    /// GameObject
    new go_foundry_blackhand_platform();/// Blackhand_A - 230193

    /// Areatriggers
    new areatrigger_foundry_slag_bomb();/// Slag Bomb - 156037
    new areatrigger_foundry_blaze();/// Blaze - 156605
    new areatrigger_foundry_overheated();/// Overheated - 156859
    new areatrigger_foundry_falling_ash();/// Falling Ash - 163295

    /// Areatrigger (world)
    new areatrigger_at_foundry_crucible_balcony();/// Blackhand's Crucible Balcony - 10101
}
