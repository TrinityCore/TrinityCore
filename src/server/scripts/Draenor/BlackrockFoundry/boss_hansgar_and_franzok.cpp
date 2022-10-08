#include "boss_hansgar_and_franzok.h"

/// Hans'gar - 76973
class boss_hansgar : public CreatureScript
{
    public:
        boss_hansgar() : CreatureScript("boss_hansgar") { }

        enum eTalks
        {
            Intro1,
            Intro2,
            Intro3,
            Aggro,
            CripplingSuplex,
            ActivateAssemblyLine,
            ReturningFromControls,
            Slay,
            Death,
            BodySlam
        };

        enum eSpells
        {
            /// Misc
            PumpedUp                = 155665,
            TacticalRetreat         = 156220,
            TacticalRetreatOther    = 156883,
            BoundByBlood            = 161029,
            ShatteredVertebrae      = 157139,
            AftershockDoT           = 157853,
            NotReady                = 158656,
            ScorchingBurnsDoT       = 155818,
            SearingPlatesDoT        = 161570,
            HansgarAndFranzokBonus  = 177533,
            /// Body Slam
            JumpSlamSearcher        = 157922,
            JumpSlamCast            = 157923,
            BodySlamTriggered       = 154785,
            BodySlamRedArrowAura    = 156892,
            BodySlamOut             = 155747,
            /// Crippling Suplex
            CripplingSuplexThrow    = 156938,
            CripplingSuplexScript   = 156546,   ///< This triggers 156547
            CripplingSuplexJump     = 156547,   ///< Force player to enter boss
            CripplingSuplexSwitch   = 156609
        };

        enum eEvents
        {
            EventBodySlam = 1
        };

        enum eCosmeticEvents
        {
            EventCosmeticStampingPresses = 1
        };

        enum eActions
        {
            ActionIntro,
            ActionIntroFinished,
            ActionSearingPlate
        };

        enum eGameObject
        {
            SmartStampCollision = 231082
        };

        struct boss_hansgarAI : public BossAI
        {
            boss_hansgarAI(Creature* p_Creature) : BossAI(p_Creature, eFoundryDatas::DataHansgarAndFranzok), m_Vehicle(p_Creature->GetVehicleKit())
            {
                m_Instance  = p_Creature->GetInstanceScript();
                m_IntroDone = false;

                m_SwitchStatePct.resize(eStates::MaxSwitchStates);
                m_SwitchStatePct = { 85, 70, 55, 40, 25, 15, 0 };

                m_TankHealths.resize(eDatas::DataMaxTankHealths);
            }

            InstanceScript* m_Instance;
            Vehicle* m_Vehicle;

            EventMap m_Events;
            EventMap m_CosmeticEvents;

            bool m_IntroDone;

            StampingPressList m_StampingPresses;
            std::list<ObjectGuid> m_SmartStampCollisions;

            std::set<ObjectGuid> m_IntroTrashs;

            uint8 m_State;
            std::vector<int32> m_SwitchStatePct;

            uint8 m_BodySlamJumps;
            ObjectGuid m_BodySlamTarget;

            uint32 m_DisabledBelt;

            ObjectGuid m_ExitTankGuid;
            std::vector<uint32> m_TankHealths;

            bool CanRespawn()
            {
                return false;
            }

            void Reset() override
            {
               // ClearDelayedOperations();

                m_Events.Reset();
                m_CosmeticEvents.Reset();

                _Reset();

                me->RemoveAllAreaTriggers();

                if (!m_IntroDone)
                {
                    m_StampingPresses.clear();

                    m_CosmeticEvents.ScheduleEvent(eCosmeticEvents::EventCosmeticStampingPresses, 1 * TimeConstants::IN_MILLISECONDS);

                   // AddTimedDelayedOperation(2 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                   // {
                        std::list<Creature*> l_TrashList;

                        me->GetCreatureListWithEntryInGrid(l_TrashList, eCreatures::BlackrockEnforcer, 50.0f);
                        me->GetCreatureListWithEntryInGrid(l_TrashList, eCreatures::BlackrockForgeSpecialist, 50.0f);

                        for (Creature* l_Trash : l_TrashList)
                        {
                            l_Trash->Respawn();
                            m_IntroTrashs.insert(l_Trash->GetGUID());
                        }
                   // });
                }

                me->CastSpell(me, eSpells::PumpedUp, true);

                me->SetReactState(ReactStates::REACT_AGGRESSIVE);

                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE));
                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));

                m_State = 0;

                m_BodySlamJumps = 0;
                m_BodySlamTarget = ObjectGuid::Empty;

                m_DisabledBelt = 0;

                m_ExitTankGuid = ObjectGuid::Empty;

               // me->setPowerType(Powers::POWER_ENERGY);
                me->SetMaxPower(Powers::POWER_ENERGY, 100);
                me->SetPower(Powers::POWER_ENERGY, 0);

                ResetArea();
            }

            void KilledUnit(Unit* p_Who) override
            {
                if (p_Who->GetTypeId() != TYPEID_PLAYER)
                    return;

                Talk(eTalks::Slay);
            }

            void EnterCombat(Unit* p_Attacker) override
            {
                _EnterCombat();

                StartBrothers(me, p_Attacker, m_Instance);
                Talk(eTalks::Aggro);

                if (Creature* l_Other = me->FindNearestCreature(eFoundryCreatures::BossFranzok, 150.0f))
                    me->AddAura(eSpells::BoundByBlood, l_Other);

                m_Events.ScheduleEvent(eEvents::EventBodySlam, 20 * TimeConstants::IN_MILLISECONDS + 500);
            }

            void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER)
            {
                m_Vehicle->RemoveAllPassengers();

                if (m_Instance != nullptr)
                {
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::ShatteredVertebrae);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::AftershockDoT);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::ScorchingBurnsDoT);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::SearingPlatesDoT);
                }

                CreatureAI::EnterEvadeMode();

                RespawnBrothers(me, m_Instance);
            }

            void JustDied(Unit* p_Killer) override
            {
                me->RemoveAllAreaTriggers();

                summons.DespawnAll();

                EndSearingPlatesEvent();

                _JustDied();

                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE));

                if (m_Instance != nullptr)
                {
                    if (Creature* l_Brother = GetBrother(me, m_Instance))
                    {
                        if (l_Brother->IsAlive())
                            p_Killer->Kill(l_Brother);
                    }
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::ShatteredVertebrae);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::AftershockDoT);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::ScorchingBurnsDoT);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::SearingPlatesDoT);

                    /// Allow loots and bonus loots to be enabled/disabled with a simple reload
                   // if (sObjectMgr->IsDisabledEncounter(m_Instance->GetEncounterIDForBoss(me), GetDifficulty()))
                        me->AddLootRecipient(nullptr);
                   // else
                        CastSpellToPlayers(me->GetMap(), me, eSpells::HansgarAndFranzokBonus, true);
                }
            }

            void OnSpellCasted(SpellInfo const* p_SpellInfo)
            {
                switch (p_SpellInfo->Id)
                {
                    case eSpells::JumpSlamCast:
                    case eSpells::BodySlamOut:
                    {
                        if (Unit* l_Target = ObjectAccessor::GetUnit(*me, m_BodySlamTarget))
                        {
                            me->GetMotionMaster()->Clear();
                            me->GetMotionMaster()->MoveJump(*l_Target, 30.0f, 10.0f, p_SpellInfo->Id);
                        }

                        break;
                    }
                    case eSpells::TacticalRetreat:
                    {
                        m_Events.ScheduleEvent(eEvents::EventBodySlam, 3 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case eSpells::CripplingSuplexThrow:
                    {
                        if (Unit* l_Passenger = m_Vehicle->GetPassenger(0))
                        {
                            if (Unit* l_Tank = ObjectAccessor::GetUnit(*me, m_ExitTankGuid))
                                l_Passenger->ExitVehicle(l_Tank);
                        }

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
                    case eSpells::JumpSlamSearcher:
                    {
                        /// Red arrow on affected target
                        me->SendPlaySpellVisual(Position(),0.0f,uint32 (eVisuals::BodySlamVisual),0.f,0.f ,20.0f);
                        me->CastSpell(p_Target, eSpells::JumpSlamCast, false);

                        me->SetFacingTo(me->GetAngle(p_Target));

                        m_BodySlamTarget = p_Target->GetGUID();
                        break;
                    }
                    case eSpells::CripplingSuplexScript:
                    {
                        p_Target->CastSpell(me, eSpells::CripplingSuplexJump, true);
                        break;
                    }
                    default:
                        break;
                }
            }

            void DamageTaken(Unit* /*p_Attacker*/, uint32& p_Damage) override
            {
                if (me->HasAura(eSpells::NotReady))
                    return;

                if (me->HealthBelowPctDamaged(m_SwitchStatePct[m_State], p_Damage))
                {
                    ++m_State;

                    switch (m_State)
                    {
                        /// Handle "phase" switch
                        case eStates::HansgarOut1:
                        case eStates::HansgarOut2:
                        {
                            me->InterruptNonMeleeSpells(true);

                          //  m_BodySlamTarget = 0;
                            m_BodySlamJumps  = 0;

                            if (m_Instance != nullptr)
                                m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::BodySlamRedArrowAura);

                            me->AddUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));

                            me->AttackStop();

                            me->GetMotionMaster()->Clear();
                            me->SetReactState(ReactStates::REACT_PASSIVE);

                            if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(l_Target, eSpells::CripplingSuplexScript, true);

                            m_Events.CancelEvent(eEvents::EventBodySlam);

                            uint32 l_Time = 4 * TimeConstants::IN_MILLISECONDS;
                          //  AddTimedDelayedOperation(l_Time, [this]() -> void
                          //  {
                                /// Force player to cast 156611 and enter other boss
                                me->CastSpell(me, eSpells::CripplingSuplexSwitch, true);
                          //  });

                            l_Time += 3 * TimeConstants::IN_MILLISECONDS;
                            //AddTimedDelayedOperation(l_Time, [this]() -> void
                           // {
                                me->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE));

                                me->CastSpell(me, eSpells::NotReady, true);

                                me->GetMotionMaster()->Clear();
                                me->CastSpell(88.03299f, 3467.769f, 138.4438f, eSpells::TacticalRetreat, true);

                                Talk(eTalks::ActivateAssemblyLine);
                           // });

                            StartSearingPlatesEvent();
                            break;
                        }
                        case eStates::BothInArena2:
                        {
                            EndOutPhaseEvent();
                            break;
                        }
                        case eStates::BothInArenaFinal:
                        {
                            EndOutPhaseEvent();
                            StartSearingPlatesEvent();
                            break;
                        }
                        default:
                            break;
                    }
                }
            }

            void PassengerBoarded(Unit* p_Passenger, int8 /*p_SeatID*/, bool p_Apply) override
            {
                /// Handle Crippling Suplex
                if (p_Apply && (m_State == eStates::FranzokOut))
                {
                    //me->AddAura(VEHICLE_SPELL_RIDE_HARDCODED, p_Passenger);

                    m_TankHealths[eDatas::DataMainTankHealth] = p_Passenger->GetMaxHealth();

                   // AddTimedDelayedOperation(3 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                   // {
                        if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO, 0, 0.0f, true, -VEHICLE_SPELL_RIDE_HARDCODED))
                        {
                            m_ExitTankGuid = l_Target->GetGUID();
                            m_TankHealths[eDatas::DataOffTankHealth] = l_Target->GetMaxHealth();

                            //me->CastSpell(l_Target, eSpells::CripplingSuplexThrow, false);
                        }
                   // });
                }
                //else if (!p_Apply)
                p_Passenger->RemoveAura(VEHICLE_SPELL_RIDE_HARDCODED);
            }

            void DoAction(int32 p_Action)
            {
                switch (p_Action)
                {
                    case eActions::ActionIntro:
                    {
                        if (m_IntroDone)
                            break;

                        m_IntroDone = true;

                        m_CosmeticEvents.CancelEvent(eCosmeticEvents::EventCosmeticStampingPresses);

                        DeactivatePress();

                        uint32 l_Time = 5 * TimeConstants::IN_MILLISECONDS;
                      //  AddTimedDelayedOperation(l_Time, [this]() -> void
                      //  {
                            ActivatePress(eFoundryGameObjects::StampingPress09, true);
                            ActivatePress(eFoundryGameObjects::StampingPress11, true);

                            m_SmartStampCollisions.clear();

                            for (uint8 l_I = 0; l_I < 4; ++l_I)
                            {
                                if (GameObject* l_Collision = me->SummonGameObject(eGameObject::SmartStampCollision, g_SmartStampCollisionPos[l_I], QuaternionData ( 0.0f, 0.0f, 0.0f, 0.0f), 0))
                                    m_SmartStampCollisions.push_back(l_Collision->GetGUID());
                            }
                       // });

                        l_Time += 4 * TimeConstants::IN_MILLISECONDS;
                       // AddTimedDelayedOperation(l_Time, [this]() -> void
                       // {
                            Talk(eTalks::Intro1);
                       // });

                        l_Time += 11 * TimeConstants::IN_MILLISECONDS;
                       // AddTimedDelayedOperation(l_Time, [this]() -> void
                       // {
                            Talk(eTalks::Intro2);
                      //  });

                        l_Time += 10 * TimeConstants::IN_MILLISECONDS;
                       // AddTimedDelayedOperation(l_Time, [this]() -> void
                       // {
                            Talk(eTalks::Intro3);

                            for (ObjectGuid l_Guid : m_IntroTrashs)
                            {
                                if (Creature* l_Trash = ObjectAccessor::GetCreature(*me, l_Guid))
                                {
                                    l_Trash->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));

                                    float l_O = l_Trash->GetOrientation();
                                    float l_X = l_Trash->GetPositionX() + (10.0f * cos(l_O));
                                    float l_Y = l_Trash->GetPositionY() + (10.0f * sin(l_O));
                                    float l_Z = 130.5f;

                                    l_Trash->GetMotionMaster()->MoveJump(l_X, l_Y, l_Z, 30.0f, 10.0f,0.f);
                                    l_Trash->SetReactState(ReactStates::REACT_AGGRESSIVE);

                                    Position const l_Pos = { l_X, l_Y, l_Z, l_O };

                                    l_Trash->SetHomePosition(l_Pos);
                                }
                            }
                       // });

                        break;
                    }
                    default:
                        break;
                }
            }

            void MovementInform(uint32 /*p_Type*/, uint32 p_ID) override
            {
                switch (p_ID)
                {
                    case eSpells::JumpSlamCast:
                    case eSpells::BodySlamOut:
                    {
                        me->CastSpell(me, eSpells::BodySlamTriggered, true);

                        if (m_BodySlamJumps)
                            --m_BodySlamJumps;

                        if (m_BodySlamJumps)
                            me->CastSpell(me, eSpells::JumpSlamSearcher, true);

                        if (m_State == eStates::BothInArena2 || m_State == eStates::BothInArenaFinal)
                            me->SetReactState(ReactStates::REACT_AGGRESSIVE);

                        me->RemoveAura(eSpells::NotReady);

                        if (p_ID == eSpells::BodySlamOut && me->HasReactState(ReactStates::REACT_PASSIVE))
                        {
                            me->CastSpell(me, eSpells::NotReady, true);

                           // AddTimedDelayedOperation(2 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                            //{
                                me->GetMotionMaster()->Clear();
                                me->CastSpell(85.60069f, 3517.861f, 138.235f, eSpells::TacticalRetreatOther, true);
                           // });
                        }
                        else
                        {
                          //  AddTimedDelayedOperation(50, [this]() -> void
                           // {
                                if (Unit* l_Target = me->GetVictim())
                                    me->GetMotionMaster()->MoveChase(l_Target);
                           // });
                        }

                        break;
                    }
                    case eSpells::TacticalRetreat:
                    case eSpells::TacticalRetreatOther:
                    {
                        me->RemoveAura(eSpells::NotReady);
                        break;
                    }
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 p_ID)const
            {
                switch (p_ID)
                {
                    case eDatas::DataMainTankHealth:
                        return m_TankHealths[eDatas::DataMainTankHealth];
                    case eDatas::DataOffTankHealth:
                        return m_TankHealths[eDatas::DataOffTankHealth];
                    default:
                        break;
                }

                return 0;
            }

            void SetGUID(ObjectGuid p_Guid, int32 /*p_ID*/) 
            {
                if (m_IntroTrashs.find(p_Guid) != m_IntroTrashs.end())
                    m_IntroTrashs.erase(p_Guid);

                if (m_IntroTrashs.empty())
                {
                    for (ObjectGuid l_Guid : m_SmartStampCollisions)
                    {
                        if (GameObject* l_Collision = ObjectAccessor::GetGameObject(*me, l_Guid))
                            l_Collision->Delete();
                    }

                    m_SmartStampCollisions.clear();

                    DeactivatePress();

                    if (m_Instance != nullptr)
                    {
                        if (Creature* l_Franzok = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::BossFranzok)))
                        {
                            if (l_Franzok->IsAIEnabled)
                                l_Franzok->AI()->DoAction(eActions::ActionIntroFinished);
                        }
                    }

                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MoveJump(g_HansgarJumpPosIn, 30.0f, 10.0f);

                   // AddTimedDelayedOperation(3 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                    //{
                        me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));

                        me->SetHomePosition(*me);
                   // });
                }
            }

            void RegeneratePower(Powers /*p_Power*/, int32& p_Value)
            {
                /// Hans'gar only regens by script
                p_Value = 0;
            }

            void UpdateAI(uint32 p_Diff) override
            {
              //  UpdateOperations(p_Diff);

                m_CosmeticEvents.Update(p_Diff);

                switch (m_CosmeticEvents.ExecuteEvent())
                {
                    case eCosmeticEvents::EventCosmeticStampingPresses:
                    {
                        if (m_StampingPresses.empty())
                        {
                            std::list<Creature*> l_StampingPresses;
                            me->GetCreatureListWithEntryInGrid(l_StampingPresses, eCreatures::MobStampingPresses, 150.0f);

                            for (Creature* l_Press : l_StampingPresses)
                            {
                               // if (GameObject* l_StampingPress = l_Press->FindNearestGameObject(2.0f))
                                  //  m_StampingPresses.push_back(StampingPressData(l_Press->GetGUID(), l_StampingPress->GetGUID()));
                            }

                            /// Shouldn't happens
                            if (m_StampingPresses.empty() || (int)m_StampingPresses.size() < eDatas::MaxStampingPresses)
                                break;
                        }

                        std::vector<uint32> l_Entries;

                        if (urand(0, 1))
                        {
                            l_Entries = { eFoundryGameObjects::StampingPress01, eFoundryGameObjects::StampingPress03, eFoundryGameObjects::StampingPress05, eFoundryGameObjects::StampingPress07,
                                          eFoundryGameObjects::StampingPress09, eFoundryGameObjects::StampingPress11, eFoundryGameObjects::StampingPress13, eFoundryGameObjects::StampingPress15,
                                          eFoundryGameObjects::StampingPress17, eFoundryGameObjects::StampingPress19 };
                        }
                        else
                        {
                            l_Entries = { eFoundryGameObjects::StampingPress02, eFoundryGameObjects::StampingPress04, eFoundryGameObjects::StampingPress06, eFoundryGameObjects::StampingPress08,
                                          eFoundryGameObjects::StampingPress10, eFoundryGameObjects::StampingPress12, eFoundryGameObjects::StampingPress14, eFoundryGameObjects::StampingPress16,
                                          eFoundryGameObjects::StampingPress18, eFoundryGameObjects::StampingPress20 };
                        }

                        for (uint32 l_Entry : l_Entries)
                            ActivatePress(l_Entry);

                        m_CosmeticEvents.ScheduleEvent(eCosmeticEvents::EventCosmeticStampingPresses, 10 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    default:
                        break;
                }

                if (!UpdateVictim())
                    return;

                m_Events.Update(p_Diff);

                if (me->HasUnitState(UnitState::UNIT_STATE_CASTING) || m_BodySlamJumps)
                    return;

                switch (m_Events.ExecuteEvent())
                {
                    case eEvents::EventBodySlam:
                    {
                        int32 l_Power = me->GetPower(Powers::POWER_RAGE);

                        if (l_Power >= 75)
                            m_BodySlamJumps = 5;
                        else if (l_Power >= 50)
                            m_BodySlamJumps = 4;
                        else if (l_Power >= 25)
                            m_BodySlamJumps = 3;
                        else
                            m_BodySlamJumps = 2;

                        /// When Hans'gar is out, jumps only once
                        if (me->GetReactState() == ReactStates::REACT_PASSIVE)
                        {
                            m_BodySlamJumps = 1;

                            if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM))
                            {
                                m_BodySlamTarget = l_Target->GetGUID();

                                me->SetFacingTo(me->GetAngle(l_Target));
                                me->CastSpell(l_Target, eSpells::BodySlamRedArrowAura, true);
                            }
                        }
                        else
                            me->CastSpell(me, eSpells::JumpSlamSearcher, true);

                        me->CastSpell(me, eSpells::NotReady, true);

                        m_Events.ScheduleEvent(eEvents::EventBodySlam, 25 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    default:
                        break;
                }

                if (me->GetReactState() == ReactStates::REACT_AGGRESSIVE)
                    DoMeleeAttackIfReady();
            }

            void ActivatePress(uint32 p_Entry, bool p_Maintain = false)
            {
                for (StampingPressData l_StampingPress : m_StampingPresses)
                {
                    if (GameObject* l_Press = ObjectAccessor::GetGameObject(*me, l_StampingPress.StampingPress))
                    {
                        if (l_Press->GetEntry() != p_Entry)
                            continue;

                        /// Floor anim + down anim
                      //  l_Press->m_Events.AddEvent(new StampingPressActivation(l_StampingPress.StampingPress, eVisuals::AnimStamp1, true),
                           // l_Press->m_Events.CalculateTime(1));

                        if (p_Maintain)
                            return;

                        /// Stamp + up anim
                       // l_Press->m_Events.AddEvent(new StampingPressActivation(l_StampingPress.StampingPress, eVisuals::AnimStamp2, true),
                           // l_Press->m_Events.CalculateTime(3 * TimeConstants::IN_MILLISECONDS));

                        /// Stay up
                       // l_Press->m_Events.AddEvent(new StampingPressActivation(l_StampingPress.StampingPress, eVisuals::AnimStamp3, true),
                          //  l_Press->m_Events.CalculateTime(5 * TimeConstants::IN_MILLISECONDS));
                    }
                }
            }

            void DeactivatePress(uint32 p_Entry = 0)
            {
                for (StampingPressData l_StampingPress : m_StampingPresses)
                {
                    if (GameObject* l_Press = ObjectAccessor::GetGameObject(*me, l_StampingPress.StampingPress))
                    {
                        if (p_Entry && l_Press->GetEntry() != p_Entry)
                            continue;

                       // l_Press->m_Events.KillAllEvents(false);

                      //  l_Press->m_Events.AddEvent(new StampingPressActivation(l_StampingPress.StampingPress, eVisuals::AnimStamp3, true),
                          //  l_Press->m_Events.CalculateTime(1));
                    }
                }
            }

            void StartSearingPlatesEvent()
            {
                for (uint32 l_Entry = eFoundryGameObjects::ConveyorBelt002; l_Entry <= eFoundryGameObjects::ConveyorBelt005; ++l_Entry)
                {
                    //if (GameObject* l_ConveyorBelt = me->FindNearestGameObject(l_Entry, 100.0f))
                       // l_ConveyorBelt->SendGameObjectActivateAnimKit(eFoundryVisuals::ConveyorsStart);
                }

                /// The searing plates come in waves, and there are two different ways in which the searing plates can be laid out.
                bool l_NonAligned =IsHeroic() ? urand(0, 1) : true;
                if (l_NonAligned)
                {
                    /// One way is that 5 searing plates enter the room, each located on one of the 5 belts, but these plates are not aligned with one another.
                    /// This means that players can use one of the gaps between the plates to avoid taking damage.
                    /// This pattern seems to start always with the second belt -> 5th - 1st - 2nd - 3rd - 4th
                    /// Then it moves to the left -> 1st - 2nd - 3rd - 4th - 5th ... 2nd - 3rd - 4th - 5th - 1st ...

                    uint8 l_Index = 1;
                    uint32 l_Time = 4 * TimeConstants::IN_MILLISECONDS;

                    std::list<Creature*> l_BurnList;
                    me->GetCreatureListWithEntryInGrid(l_BurnList, eCreatures::ScorchingBurns, 200.0f);

                    if (l_BurnList.empty())
                        return;

                    /// Start all cycles three times in advance, it should be enough
                    for (uint8 l_J = 0; l_J < 3; ++l_J)
                    {
                        for (uint8 l_I = 0; l_I < eDatas::MaxConveyorBelts; ++l_I)
                        {
                            for (uint32 l_BeltEntry : g_SearingPlatesCycles[l_I])
                            {
                                if (GameObject* l_Belt = me->FindNearestGameObject(l_BeltEntry, 100.0f))
                                {
                                    std::list<Creature*> l_TempList = l_BurnList;

                                    auto l_BurnsDatas = g_ConveyorBeltBurns.find(l_BeltEntry);

                                    l_TempList.remove_if([this, l_BurnsDatas](Creature* p_Creature) -> bool
                                    {
                                        if (p_Creature == nullptr)
                                            return true;

                                        if (p_Creature->GetPositionY() != l_BurnsDatas->second)
                                        {
                                            Position l_Pos = *p_Creature;
                                            l_Pos.m_positionX = g_ScorchingBurnsXPos;
                                            l_Pos.m_positionY = l_BurnsDatas->second;

                                           // if (!p_Creature->IsNearPosition(&l_Pos, 2.0f))
                                              //  return true;
                                        }

                                        return false;
                                    });

                                    if (l_TempList.empty())
                                        continue;

                                    if (Creature* l_Burns = l_TempList.front())
                                    {
                                        if (l_Burns->IsAIEnabled)
                                        {
                                            l_Burns->AI()->SetData(eDatas::DataBeltEntry, l_BeltEntry);
                                            l_Burns->AI()->SetData(eDatas::DataSpawnTimer, l_Time * l_Index);
                                        }
                                    }
                                }

                                ++l_Index;
                            }
                        }
                    }
                }
                else
                {
                    /// This seems to be possible only during Mythic encounter
                    /// Another way is that 4 searing plates enter the room, each located on one of the 5 belts.
                    /// These 4 plates are perfectly aligned, but the 5th conveyor belt has no plate and thus provides a large gap through which players can move.
                    /// With each wave, the gap moves to a different conveyor belt, but the gaps are always located on adjacent belts.
                    /// Sometimes, however, when the gap is located on a belt that is at the edge of the room, the next gap can be on belt that is on the opposite edge.

                    /*if (!m_DisabledBelt)
                        m_DisabledBelt = urand(eFoundryGameObjects::ConveyorBelt002, eFoundryGameObjects::ConveyorBelt005);
                    else
                    {
                        if (m_DisabledBelt > eFoundryGameObjects::ConveyorBelt002 && m_DisabledBelt < eFoundryGameObjects::ConveyorBelt005)
                            m_DisabledBelt += (urand(0, 1) ? -1 : 1);
                        else
                        {
                            if (m_DisabledBelt == eFoundryGameObjects::ConveyorBelt002)
                                m_DisabledBelt = (urand(0, 1) ? eFoundryGameObjects::ConveyorBelt001 : eFoundryGameObjects::ConveyorBelt005);
                            else ///< m_DisabledBelt == eFoundryGameObjects::ConveyorBelt005
                                m_DisabledBelt = (urand(0, 1) ? eFoundryGameObjects::ConveyorBelt002 : eFoundryGameObjects::ConveyorBelt004);
                        }
                    }

                    for (auto l_Datas : g_ConveyorBeltPos)
                    {
                        if (l_Datas.first == m_DisabledBelt)
                            continue;

                        auto l_BurnsDatas = g_ConveyorBeltBurns.find(l_Datas.first);
                        if (l_BurnsDatas == g_ConveyorBeltBurns.end())
                            continue;

                        float l_PressY = l_Datas.second;
                        float l_BurnsY = l_BurnsDatas->second;
                    }*/
                }
            }

            void EndSearingPlatesEvent()
            {
                for (uint32 l_Entry = eFoundryGameObjects::ConveyorBelt002; l_Entry <= eFoundryGameObjects::ConveyorBelt005; ++l_Entry)
                {
                   // if (GameObject* l_ConveyorBelt = me->FindNearestGameObject(l_Entry, 100.0f))
                       // l_ConveyorBelt->SendGameObjectActivateAnimKit(eFoundryVisuals::ConveyorsStop);
                }

                std::list<Creature*> l_BurnList;
                me->GetCreatureListWithEntryInGrid(l_BurnList, eCreatures::ScorchingBurns, 200.0f);

                if (l_BurnList.empty())
                    return;

                /// Clear all pending cycles
                for (uint8 l_I = 0; l_I < eDatas::MaxConveyorBelts; ++l_I)
                {
                    for (uint32 l_BeltEntry : g_SearingPlatesCycles[l_I])
                    {
                        if (GameObject* l_Belt = me->FindNearestGameObject(l_BeltEntry, 100.0f))
                        {
                            std::list<Creature*> l_TempList = l_BurnList;

                            auto l_BurnsDatas = g_ConveyorBeltBurns.find(l_BeltEntry);

                            l_TempList.remove_if([this, l_BurnsDatas](Creature* p_Creature) -> bool
                            {
                                if (p_Creature == nullptr)
                                    return true;

                                if (p_Creature->GetPositionY() != l_BurnsDatas->second)
                                {
                                    Position l_Pos = *p_Creature;
                                    l_Pos.m_positionX = g_ScorchingBurnsXPos;
                                    l_Pos.m_positionY = l_BurnsDatas->second;

                                   // if (!p_Creature->IsNearPosition(&l_Pos, 2.0f))
                                   //     return true;
                                }

                                return false;
                            });

                            if (l_TempList.empty())
                                continue;

                            if (Creature* l_Burns = l_TempList.front())
                            {
                                if (l_Burns->IsAIEnabled)
                                    l_Burns->AI()->Reset();
                            }
                        }
                    }
                }
            }

            void EndOutPhaseEvent()
            {
                Talk(eTalks::ReturningFromControls);

                m_Events.CancelEvent(eEvents::EventBodySlam);

                me->CastSpell(me, eSpells::NotReady, true);

                if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO))
                {
                    me->CastSpell(l_Target, eSpells::BodySlamRedArrowAura, true);
                    m_BodySlamTarget = l_Target->GetGUID();

                    float l_O = me->GetAngle(l_Target);
                   // AddTimedDelayedOperation(50, [this, l_O]() -> void
                  //  {
                        me->SetFacingTo(l_O);
                  //  });
                }

                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE));
                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));

                EndSearingPlatesEvent();
            }

            void ResetArea()
            {
                DespawnCreaturesInArea(eCreatures::ForgeOverdrive, me);

                for (uint32 l_Entry = eFoundryGameObjects::ConveyorBelt002; l_Entry <= eFoundryGameObjects::ConveyorBelt005; ++l_Entry)
                {
                    //if (GameObject* l_ConveyorBelt = me->FindNearestGameObject(l_Entry, 100.0f))
                      //  l_ConveyorBelt->SendGameObjectActivateAnimKit(eFoundryVisuals::ConveyorsStop);
                }

                std::list<Creature*> l_BurnList;
                me->GetCreatureListWithEntryInGrid(l_BurnList, eCreatures::ScorchingBurns, 200.0f);

                if (l_BurnList.empty())
                    return;

                /// Clear all pending cycles
                for (uint8 l_I = 0; l_I < eDatas::MaxConveyorBelts; ++l_I)
                {
                    for (uint32 l_BeltEntry : g_SearingPlatesCycles[l_I])
                    {
                        if (GameObject* l_Belt = me->FindNearestGameObject(l_BeltEntry, 100.0f))
                        {
                            std::list<Creature*> l_TempList = l_BurnList;

                            auto l_BurnsDatas = g_ConveyorBeltBurns.find(l_BeltEntry);

                            l_TempList.remove_if([this, l_BurnsDatas](Creature* p_Creature) -> bool
                            {
                                if (p_Creature == nullptr)
                                    return true;

                                if (p_Creature->GetPositionY() != l_BurnsDatas->second)
                                {
                                    Position l_Pos = *p_Creature;
                                    l_Pos.m_positionX = g_ScorchingBurnsXPos;
                                    l_Pos.m_positionY = l_BurnsDatas->second;

                                   // if (!p_Creature->IsNearPosition(&l_Pos, 2.0f))
                                   //     return true;
                                }

                                return false;
                            });

                            if (l_TempList.empty())
                                continue;

                            if (Creature* l_Burns = l_TempList.front())
                            {
                                if (l_Burns->IsAIEnabled)
                                    l_Burns->AI()->Reset();
                            }
                        }
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new boss_hansgarAI(p_Creature);
        }
};

/// Franzok - 76974
class boss_franzok : public CreatureScript
{
    public:
        boss_franzok() : CreatureScript("boss_franzok") { }

        enum eTalks
        {
            Intro1,
            Intro2,
            Intro3,
            Aggro,
            ActivateAssemblyLine,
            ReturningFromControls,
            Slay,
            Wipe,
            Death,
            DisruptingRoar,
            BodySlam
        };

        enum eSpells
        {
            /// Misc
            PumpedUp                = 155665,
            BoundByBlood            = 161030,
            NotReady                = 158656,
            TacticalRetreat         = 156220,
            TacticalRetreatOther    = 156883,
            /// Disrupting Roar
            SpellDisruptingRoar     = 160838,
            /// Skullcracker
            Skullcracker            = 153470,
            /// Crippling Suplex
            CripplingSuplexThrow    = 156938,
            CripplingSuplexScript   = 156546,   ///< This triggers 156547
            CripplingSuplexJump     = 156547,   ///< Force player to enter boss
            CripplingSuplexSwitch   = 156612,
            /// Body Slam (When out)
            BodySlamTriggered       = 154785,
            BodySlamRedArrowAura    = 156892,
            BodySlamOut             = 155747
        };

        enum eEvents
        {
            EventDisruptingRoar = 1,
            EventSkullcracker,
            EventBodySlam
        };

        enum eCosmeticEvents
        {
        };

        enum eActions
        {
            ActionIntro,
            ActionIntroFinished,
            ActionStamp,
            ActionCancelStamp
        };

        struct boss_franzokAI : public BossAI
        {
            boss_franzokAI(Creature* p_Creature) : BossAI(p_Creature, eFoundryDatas::DataHansgarAndFranzok), m_Vehicle(p_Creature->GetVehicleKit())
            {
                m_Instance  = p_Creature->GetInstanceScript();
                m_IntroDone = false;

                m_TankHealths.resize(eDatas::DataMaxTankHealths);

                m_SwitchStatePct.resize(eStates::MaxSwitchStates);
                m_SwitchStatePct = { 85, 70, 55, 40, 25, 15, 0 };
            }

            InstanceScript* m_Instance;
            Vehicle* m_Vehicle;

            EventMap m_Events;
            EventMap m_CosmeticEvents;

            bool m_IntroDone;

            ObjectGuid m_ExitTankGuid;
            std::vector<uint32> m_TankHealths;

            uint8 m_State;
            std::vector<int32> m_SwitchStatePct;

            ObjectGuid m_BodySlamTarget;

            StampingPressList m_StampingPresses;

            bool CanRespawn() 
            {
                return false;
            }

            void Reset() override
            {
               // ClearDelayedOperations();

                m_Events.Reset();
                m_CosmeticEvents.Reset();

                _Reset();

                me->RemoveAllAreaTriggers();

                me->CastSpell(me, eSpells::PumpedUp, true);

               // me->setPowerType(Powers::POWER_ENERGY);
                me->SetMaxPower(Powers::POWER_ENERGY, 100);
                me->SetPower(Powers::POWER_ENERGY, 0);

                me->SetReactState(ReactStates::REACT_AGGRESSIVE);

                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE));
                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));

                m_ExitTankGuid = ObjectGuid::Empty;

                m_State = 0;

                m_BodySlamTarget = ObjectGuid::Empty;

                if (m_StampingPresses.empty())
                {
                   // AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                   // {
                        std::list<Creature*> l_StampingPresses;
                        me->GetCreatureListWithEntryInGrid(l_StampingPresses, eCreatures::MobStampingPresses, 150.0f);

                        for (Creature* l_Press : l_StampingPresses)
                        {
                           // if (GameObject* l_StampingPress = l_Press->FindNearestGameObject(2.0f))
                               // m_StampingPresses.push_back(StampingPressData(l_Press->GetGUID(), l_StampingPress->GetGUID()));
                        }
                  //  });
                }
                else
                    DeactivatePress();
            }

            void KilledUnit(Unit* p_Who) override
            {
                if (p_Who->GetTypeId() != TYPEID_PLAYER)
                    return;

                Talk(eTalks::Slay);
            }

            void EnterCombat(Unit* p_Attacker) override
            {
                _EnterCombat();

                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me, 1);

                StartBrothers(me, p_Attacker, m_Instance);

                Talk(eTalks::Aggro);

                m_Events.ScheduleEvent(eEvents::EventDisruptingRoar, 45 * TimeConstants::IN_MILLISECONDS);
                m_Events.ScheduleEvent(eEvents::EventSkullcracker, 20 * TimeConstants::IN_MILLISECONDS);

                if (Creature* l_Other = me->FindNearestCreature(eFoundryCreatures::BossHansgar, 150.0f))
                    me->AddAura(eSpells::BoundByBlood, l_Other);
            }

            void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER)
            {
                m_Vehicle->RemoveAllPassengers();

                CreatureAI::EnterEvadeMode();

                RespawnBrothers(me, m_Instance);

                Talk(eTalks::Wipe);
            }

            void JustReachedHome() override
            {
                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void JustDied(Unit* p_Killer) override
            {
                me->RemoveAllAreaTriggers();

                summons.DespawnAll();

                EndStampingPressesEvent();

                _JustDied();

                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE));

                if (m_Instance != nullptr)
                {
                    if (Creature* l_Brother = GetBrother(me, m_Instance))
                    {
                        if (l_Brother->IsAlive())
                            p_Killer->Kill(l_Brother);
                    }

                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);
                }
            }

            void OnSpellCasted(SpellInfo const* p_SpellInfo)
            {
                switch (p_SpellInfo->Id)
                {
                    case eSpells::CripplingSuplexThrow:
                    {
                        if (Unit* l_Passenger = m_Vehicle->GetPassenger(0))
                        {
                            if (Unit* l_Tank = ObjectAccessor::GetUnit(*me, m_ExitTankGuid))
                                l_Passenger->ExitVehicle(l_Tank);
                        }

                        break;
                    }
                    case eSpells::BodySlamOut:
                    {
                        if (Unit* l_Target = ObjectAccessor::GetUnit(*me, m_BodySlamTarget))
                        {
                            me->GetMotionMaster()->Clear();
                            me->GetMotionMaster()->MoveJump(*l_Target, 30.0f, 10.0f, p_SpellInfo->Id);
                        }

                        break;
                    }
                    case eSpells::TacticalRetreat:
                    {
                        m_Events.ScheduleEvent(eEvents::EventBodySlam, 3 * TimeConstants::IN_MILLISECONDS);
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
                    case eSpells::CripplingSuplexScript:
                    {
                        p_Target->CastSpell(me, eSpells::CripplingSuplexJump, true);
                        break;
                    }
                    default:
                        break;
                }
            }

            void DamageTaken(Unit* /*p_Attacker*/, uint32& p_Damage) override
            {
                if (me->HasAura(eSpells::NotReady))
                    return;

                if (me->HealthBelowPctDamaged(m_SwitchStatePct[m_State], p_Damage))
                {
                    ++m_State;

                    switch (m_State)
                    {
                        case eStates::FranzokOut:
                        {
                            me->InterruptNonMeleeSpells(true);

                            me->AddUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));
  
                            me->AttackStop();

                            me->GetMotionMaster()->Clear();
                            me->SetReactState(ReactStates::REACT_PASSIVE);

                            if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(l_Target, eSpells::CripplingSuplexScript, true);

                            m_Events.CancelEvent(eEvents::EventDisruptingRoar);
                            m_Events.CancelEvent(eEvents::EventSkullcracker);

                            uint32 l_Time = 4 * TimeConstants::IN_MILLISECONDS;
                           // AddTimedDelayedOperation(l_Time, [this]() -> void
                           // {
                                /// Force player to cast 156613 and enter other boss
                                me->CastSpell(me, eSpells::CripplingSuplexSwitch, true);
                           // });

                            l_Time += 3 * TimeConstants::IN_MILLISECONDS;
                          //  AddTimedDelayedOperation(l_Time, [this]() -> void
                          //  {
                                me->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE));

                                me->CastSpell(me, eSpells::NotReady, true);

                                me->GetMotionMaster()->Clear();
                                me->CastSpell(88.03299f, 3467.769f, 138.4438f, eSpells::TacticalRetreat, true);

                                Talk(eTalks::ActivateAssemblyLine);
                          //  });

                            StartStampingPressesEvent();
                            break;
                        }
                        case eStates::BothInArena3:
                        {
                            Talk(eTalks::ReturningFromControls);

                            m_Events.CancelEvent(eEvents::EventBodySlam);

                            m_Events.ScheduleEvent(eEvents::EventDisruptingRoar, 45 * TimeConstants::IN_MILLISECONDS);
                            m_Events.ScheduleEvent(eEvents::EventSkullcracker, 20 * TimeConstants::IN_MILLISECONDS);

                            me->CastSpell(me, eSpells::NotReady, true);

                            if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO))
                            {
                                me->CastSpell(l_Target, eSpells::BodySlamRedArrowAura, true);
                                m_BodySlamTarget = l_Target->GetGUID();

                                float l_O = me->GetAngle(l_Target);
                                //AddTimedDelayedOperation(50, [this, l_O]() -> void
                               // {
                                    me->SetFacingTo(l_O);
                               // });
                            }

                            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE));
                            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));

                            EndStampingPressesEvent();
                            break;
                        }
                        case eStates::BothInArenaFinal:
                        {
                            StartStampingPressesEvent();
                            break;
                        }
                        default:
                            break;
                    }
                }
            }

            void PassengerBoarded(Unit* p_Passenger, int8 /*p_SeatID*/, bool p_Apply) override
            {
                /// Handle Crippling Suplex
                if (p_Apply && (m_State == eStates::HansgarOut1 || m_State == eStates::HansgarOut2))
                {
                    //me->AddAura(VEHICLE_SPELL_RIDE_HARDCODED, p_Passenger);

                    m_TankHealths[eDatas::DataMainTankHealth] = p_Passenger->GetMaxHealth();

                   // AddTimedDelayedOperation(3 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                   // {
                        if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO, 0, 0.0f, true, -VEHICLE_SPELL_RIDE_HARDCODED))
                        {
                            m_ExitTankGuid = l_Target->GetGUID();
                            m_TankHealths[eDatas::DataOffTankHealth] = l_Target->GetMaxHealth();

                            //me->CastSpell(l_Target, eSpells::CripplingSuplexThrow, false);
                        }
                   // });
                }
                //else if (!p_Apply)
                    p_Passenger->RemoveAura(VEHICLE_SPELL_RIDE_HARDCODED);
            }

            void DoAction(int32 p_Action)
            {
                switch (p_Action)
                {
                    case eActions::ActionIntro:
                    {
                        if (m_IntroDone)
                            break;

                        m_IntroDone = true;

                        uint32 l_Time = 14 * TimeConstants::IN_MILLISECONDS;
                      //  AddTimedDelayedOperation(l_Time, [this]() -> void
                       // {
                            Talk(eTalks::Intro1);
                       // });

                        l_Time += 11 * TimeConstants::IN_MILLISECONDS;
                       // AddTimedDelayedOperation(l_Time, [this]() -> void
                      //  {
                            Talk(eTalks::Intro2);
                      //  });

                        l_Time += 11 * TimeConstants::IN_MILLISECONDS;
                      //  AddTimedDelayedOperation(l_Time, [this]() -> void
                      //  {
                            Talk(eTalks::Intro3);
                      //  });

                        break;
                    }
                    case eActions::ActionIntroFinished:
                    {
                        me->GetMotionMaster()->MoveJump(g_FranzokJumpPosIn, 30.0f, 10.0f);

                      //  AddTimedDelayedOperation(3 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                      //  {
                            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));

                            me->SetHomePosition(*me);
                      //  });

                        break;
                    }
                    default:
                        break;
                }
            }

            void MovementInform(uint32 /*p_Type*/, uint32 p_ID) override
            {
                switch (p_ID)
                {
                    case eSpells::BodySlamOut:
                    {
                        me->CastSpell(me, eSpells::BodySlamTriggered, true);

                        if (m_State == eStates::BothInArena3)
                            me->SetReactState(ReactStates::REACT_AGGRESSIVE);

                        me->RemoveAura(eSpells::NotReady);

                        if (p_ID == eSpells::BodySlamOut && me->HasReactState(ReactStates::REACT_PASSIVE))
                        {
                            me->CastSpell(me, eSpells::NotReady, true);

                          //  AddTimedDelayedOperation(2 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                          //  {
                                me->GetMotionMaster()->Clear();
                                me->CastSpell(85.60069f, 3517.861f, 138.235f, eSpells::TacticalRetreatOther, true);
                           // });
                        }
                        else
                        {
                           // AddTimedDelayedOperation(50, [this]() -> void
                           // {
                                if (Unit* l_Target = me->GetVictim())
                                    me->GetMotionMaster()->MoveChase(l_Target);
                           // });
                        }

                        break;
                    }
                    case eSpells::TacticalRetreat:
                    case eSpells::TacticalRetreatOther:
                    {
                        me->RemoveAura(eSpells::NotReady);
                        break;
                    }
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 p_ID)const
            {
                switch (p_ID)
                {
                    case eDatas::DataMainTankHealth:
                        return m_TankHealths[eDatas::DataMainTankHealth];
                    case eDatas::DataOffTankHealth:
                        return m_TankHealths[eDatas::DataOffTankHealth];
                    default:
                        break;
                }

                return 0;
            }

            void RegeneratePower(Powers /*p_Power*/, int32& p_Value)
            {
                /// Hans'gar only regens by script
                p_Value = 0;
            }

            void OnCalculateCastingTime(SpellInfo const* p_SpellInfo, int32& p_CastingTime) 
            {
                if (p_SpellInfo->Id == eSpells::SpellDisruptingRoar)
                {
                    int32 l_Rage = me->GetPower(Powers::POWER_RAGE);

                    if (l_Rage >= 75)
                        p_CastingTime = 500 + 1 * TimeConstants::IN_MILLISECONDS;
                    else if (l_Rage >= 50)
                        p_CastingTime = 2 * TimeConstants::IN_MILLISECONDS;
                    else if (l_Rage >= 25)
                        p_CastingTime = 500 + 2 * TimeConstants::IN_MILLISECONDS;
                    else
                        p_CastingTime = 3 * TimeConstants::IN_MILLISECONDS;
                }
            }

            void UpdateAI(uint32 p_Diff) override
            {
               // UpdateOperations(p_Diff);

                if (!UpdateVictim())
                    return;

                m_Events.Update(p_Diff);

                if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                    return;

                switch (m_Events.ExecuteEvent())
                {
                    case eEvents::EventDisruptingRoar:
                    {
                        Talk(eTalks::DisruptingRoar);
                        me->CastSpell(me, eSpells::SpellDisruptingRoar, false);
                        m_Events.ScheduleEvent(eEvents::EventDisruptingRoar, 46 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case eEvents::EventSkullcracker:
                    {
                        CustomSpellValues l_Values;

                        int32 l_Count = 0;
                        int32 l_Rage = me->GetPower(Powers::POWER_RAGE);

                        if (l_Rage >= 75)
                            l_Count = 5;
                        else if (l_Rage >= 50)
                            l_Count = 4;
                        else if (l_Rage >= 25)
                            l_Count = 3;
                        else
                            l_Count = 2;

                        l_Values.AddSpellMod(SpellValueMod::SPELLVALUE_MAX_TARGETS, l_Count);

                       // if (Unit* l_Target = SelectRangedTarget())
//                            me->CastCustomSpell(eSpells::Skullcracker, l_Values, false);

                        m_Events.ScheduleEvent(eEvents::EventSkullcracker, 21 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case eEvents::EventBodySlam:
                    {
                        if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM))
                        {
                            m_BodySlamTarget = l_Target->GetGUID();

                            me->SetFacingTo(me->GetAngle(l_Target));
                            me->CastSpell(l_Target, eSpells::BodySlamRedArrowAura, true);
                        }

                        me->CastSpell(me, eSpells::NotReady, true);

                        m_Events.ScheduleEvent(eEvents::EventBodySlam, 25 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    default:
                        break;
                }

                if (me->GetReactState() == ReactStates::REACT_AGGRESSIVE)
                    DoMeleeAttackIfReady();
            }

            void StartStampingPressesEvent()
            {
                for (uint32 l_Entry = eFoundryGameObjects::ConveyorBelt002; l_Entry <= eFoundryGameObjects::ConveyorBelt005; ++l_Entry)
                {
                   // if (GameObject* l_ConveyorBelt = me->FindNearestGameObject(l_Entry, 100.0f))
                       // l_ConveyorBelt->SendGameObjectActivateAnimKit(eFoundryVisuals::ConveyorsStart);
                }

                uint32 l_Time = 0;

                for (uint8 l_I = 0; l_I < eDatas::MaxPatternActivation; ++l_I)
                {
                    for (StampingPressPattern l_Pattern : g_PatternActivation[l_I])
                    {
                        for (uint32 l_Entry : l_Pattern)
                            ActivatePress(l_Entry, l_Time);

                        l_Time += 5 * TimeConstants::IN_MILLISECONDS;
                    }
                }

                std::list<Creature*> l_BurnList;
                me->GetCreatureListWithEntryInGrid(l_BurnList, eCreatures::ScorchingBurns, 200.0f);

                if (l_BurnList.empty())
                    return;

                /// Activate movement forces
                for (uint8 l_I = 0; l_I < eDatas::MaxConveyorBelts; ++l_I)
                {
                    for (uint32 l_BeltEntry : g_SearingPlatesCycles[l_I])
                    {
                        if (GameObject* l_Belt = me->FindNearestGameObject(l_BeltEntry, 100.0f))
                        {
                            std::list<Creature*> l_TempList = l_BurnList;

                            auto l_BurnsDatas = g_ConveyorBeltBurns.find(l_BeltEntry);

                            l_TempList.remove_if([this, l_BurnsDatas](Creature* p_Creature) -> bool
                            {
                                if (p_Creature == nullptr)
                                    return true;

                                if (p_Creature->GetPositionY() != l_BurnsDatas->second)
                                {
                                    Position l_Pos = *p_Creature;
                                    l_Pos.m_positionX = g_ScorchingBurnsXPos;
                                    l_Pos.m_positionY = l_BurnsDatas->second;

                                   // if (!p_Creature->IsNearPosition(&l_Pos, 2.0f))
                                    //    return true;
                                }

                                return false;
                            });

                            if (l_TempList.empty())
                                continue;

                            if (Creature* l_Burns = l_TempList.front())
                            {
                                if (l_Burns->IsAIEnabled)
                                    l_Burns->AI()->SetData(eDatas::DataBeltEntry, l_BeltEntry);
                            }
                        }
                    }
                }
            }

            void EndStampingPressesEvent()
            {
                for (uint32 l_Entry = eFoundryGameObjects::ConveyorBelt002; l_Entry <= eFoundryGameObjects::ConveyorBelt005; ++l_Entry)
                {
                   // if (GameObject* l_ConveyorBelt = me->FindNearestGameObject(l_Entry, 100.0f))
                       // l_ConveyorBelt->SendGameObjectActivateAnimKit(eFoundryVisuals::ConveyorsStop);
                }

                DeactivatePress();

                std::list<Creature*> l_BurnList;
                me->GetCreatureListWithEntryInGrid(l_BurnList, eCreatures::ScorchingBurns, 200.0f);

                if (l_BurnList.empty())
                    return;

                /// End movement forces
                for (uint8 l_I = 0; l_I < eDatas::MaxConveyorBelts; ++l_I)
                {
                    for (uint32 l_BeltEntry : g_SearingPlatesCycles[l_I])
                    {
                        if (GameObject* l_Belt = me->FindNearestGameObject(l_BeltEntry, 100.0f))
                        {
                            std::list<Creature*> l_TempList = l_BurnList;

                            auto l_BurnsDatas = g_ConveyorBeltBurns.find(l_BeltEntry);

                            l_TempList.remove_if([this, l_BurnsDatas](Creature* p_Creature) -> bool
                            {
                                if (p_Creature == nullptr)
                                    return true;

                                if (p_Creature->GetPositionY() != l_BurnsDatas->second)
                                {
                                    Position l_Pos = *p_Creature;
                                    l_Pos.m_positionX = g_ScorchingBurnsXPos;
                                    l_Pos.m_positionY = l_BurnsDatas->second;

                                   // if (!p_Creature->IsNearPosition(&l_Pos, 2.0f))
                                   //     return true;
                                }

                                return false;
                            });

                            if (l_TempList.empty())
                                continue;

                            if (Creature* l_Burns = l_TempList.front())
                            {
                                if (l_Burns->IsAIEnabled)
                                    l_Burns->AI()->Reset();
                            }
                        }
                    }
                }
            }

            void ActivatePress(uint32 p_Entry, uint32 p_BaseTime = 0)
            {
                for (StampingPressData l_StampingPress : m_StampingPresses)
                {
                    if (GameObject* l_Press = ObjectAccessor::GetGameObject(*me, l_StampingPress.StampingPress))
                    {
                        if (l_Press->GetEntry() != p_Entry)
                            continue;

                        /// Floor anim + down anim
                       // l_Press->m_Events.AddEvent(new StampingPressActivation(l_StampingPress.StampingPress, eVisuals::AnimStamp1, true),
                           // l_Press->m_Events.CalculateTime(p_BaseTime + 1));

                        /// Handle Pulverized damages
                        if (Creature* l_StampingPresses = ObjectAccessor::GetCreature(*me, l_StampingPress.StampingPresses))
                        {
                            if (l_StampingPresses->IsAIEnabled)
                            {
                                l_StampingPresses->AI()->SetData(eDatas::DataStampTimer, p_BaseTime + 2 * TimeConstants::IN_MILLISECONDS + 200);
                                l_StampingPresses->AI()->DoAction(eActions::ActionStamp);
                            }
                        }

                        /// Stamp + up anim
                       // l_Press->m_Events.AddEvent(new StampingPressActivation(l_StampingPress.StampingPress, eVisuals::AnimStamp2, true),
                           // l_Press->m_Events.CalculateTime(p_BaseTime + 3 * TimeConstants::IN_MILLISECONDS));

                        /// Stay up
                       // l_Press->m_Events.AddEvent(new StampingPressActivation(l_StampingPress.StampingPress, eVisuals::AnimStamp3, true),
                          //  l_Press->m_Events.CalculateTime(p_BaseTime + 5 * TimeConstants::IN_MILLISECONDS));
                    }
                }
            }

            void DeactivatePress(uint32 p_Entry = 0)
            {
                for (StampingPressData l_StampingPress : m_StampingPresses)
                {
                    if (GameObject* l_Press = ObjectAccessor::GetGameObject(*me, l_StampingPress.StampingPress))
                    {
                        if (p_Entry && l_Press->GetEntry() != p_Entry)
                            continue;

                        if (Creature* l_StampingPresses = ObjectAccessor::GetCreature(*me, l_StampingPress.StampingPresses))
                        {
                            if (l_StampingPresses->IsAIEnabled)
                                l_StampingPresses->AI()->DoAction(eActions::ActionCancelStamp);
                        }

                       // l_Press->m_Events.KillAllEvents(false);

                      //  l_Press->m_Events.AddEvent(new StampingPressActivation(l_StampingPress.StampingPress, eVisuals::AnimStamp3, true),
                        //    l_Press->m_Events.CalculateTime(1));
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new boss_franzokAI(p_Creature);
        }
};

/// Forge Overdrive - 77258
class npc_foundry_forge_overdrive : public CreatureScript
{
    public:
        npc_foundry_forge_overdrive() : CreatureScript("npc_foundry_forge_overdrive") { }

        enum eSpells
        {
            SearingPlatesAT     = 155994,
            SearingPlatesDoT    = 161570
        };

        enum eMove
        {
            MoveDespawn = 1
        };

        struct npc_foundry_forge_overdriveAI : public ScriptedAI
        {
            npc_foundry_forge_overdriveAI(Creature* p_Creature) : ScriptedAI(p_Creature)
            {
                m_BeltEntry = 0;

                p_Creature->AddUnitMovementFlag(MovementFlags::MOVEMENTFLAG_DISABLE_COLLISION);

                p_Creature->SetReactState(ReactStates::REACT_PASSIVE);
            }

            uint32 m_BeltEntry;

            std::set<ObjectGuid> m_AffectedPlayers;

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->CastSpell(me, eSpells::SearingPlatesAT, true);

                //AddTimedDelayedOperation(100, [this]() -> void
               // {
                    if (g_ForgeOverdriveDestPos.find(m_BeltEntry) != g_ForgeOverdriveDestPos.end())
                    {
                        Position const l_DestPos = g_ForgeOverdriveDestPos[m_BeltEntry];

                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MovePoint(eMove::MoveDespawn, l_DestPos);
                    }
               // });

                m_AffectedPlayers.clear();
            }
            
            void DamageTaken(Unit* /*p_Attacker*/, uint32& p_Damage) override
            {
                p_Damage = 0;
            }

            void MovementInform(uint32 p_Type, uint32 p_ID) override
            {
                if (p_Type != MovementGeneratorType::POINT_MOTION_TYPE)
                    return;

                if (p_ID == eMove::MoveDespawn)
                {
                    me->RemoveAllAuras();
                    me->DespawnOrUnsummon();
                }
            }

            void JustDespawned()
            {
                for (ObjectGuid l_Guid : m_AffectedPlayers)
                {
                    if (Player* l_Player = ObjectAccessor::GetPlayer(*me, l_Guid))
                    {
                        if (l_Player->HasAura(eSpells::SearingPlatesDoT, me->GetGUID()))
                            l_Player->RemoveAura(eSpells::SearingPlatesDoT, me->GetGUID());
                    }
                }
            }

            void UpdateAI(uint32 p_Diff) override
            {
               // UpdateOperations(p_Diff);

                float l_CheckX = 4.5f;
                float l_CheckY = 7.5f;

                std::set<ObjectGuid> l_Targets;

                Map::PlayerList const& l_PlayerList = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator l_Iter = l_PlayerList.begin(); l_Iter != l_PlayerList.end(); ++l_Iter)
                {
                    if (Player* l_Player = l_Iter->GetSource())
                    {
                        if (l_Player->GetPositionX() <= (me->GetPositionX() + l_CheckX) && l_Player->GetPositionX() >= (me->GetPositionX() - l_CheckX) &&
                            l_Player->GetPositionY() <= (me->GetPositionY() + l_CheckY) && l_Player->GetPositionY() >= (me->GetPositionY() - l_CheckY))
                            l_Targets.insert(l_Player->GetGUID());
                    }
                }

                for (std::set<ObjectGuid>::iterator l_Iter = m_AffectedPlayers.begin(); l_Iter != m_AffectedPlayers.end();)
                {
                    if (l_Targets.find((*l_Iter)) == l_Targets.end())
                    {
                        if (Player* l_Player = ObjectAccessor::GetPlayer(*me, (*l_Iter)))
                        {
                            if (l_Player->HasAura(eSpells::SearingPlatesDoT, me->GetGUID()))
                                l_Player->RemoveAura(eSpells::SearingPlatesDoT, me->GetGUID());
                        }

                        l_Iter = m_AffectedPlayers.erase(l_Iter);
                    }
                    else
                        ++l_Iter;
                }

                for (ObjectGuid l_Guid : l_Targets)
                {
                    if (Player* l_Player = ObjectAccessor::GetPlayer(*me, l_Guid))
                    {
                        if (!l_Player->HasAura(eSpells::SearingPlatesDoT, me->GetGUID()))
                        {
                            me->CastSpell(l_Player, eSpells::SearingPlatesDoT, true);

                            m_AffectedPlayers.insert(l_Guid);
                        }
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_forge_overdriveAI(p_Creature);
        }
};

/// Scorching Burns - 78823
class npc_foundry_scorching_burns : public CreatureScript
{
    public:
        npc_foundry_scorching_burns() : CreatureScript("npc_foundry_scorching_burns") { }

        enum eSpells
        {
            ScorchingBurnsAT    = 159182,
            ScorchingBurnsDoT   = 155818
        };

        enum eEvents
        {
        };

        enum eAction
        {
            ActionSearingPlate = 2
        };

        enum eCreature
        {
            ForgeOverdrive = 77258
        };

        enum eDatas
        {
            DataBeltEntry,
            DataSpawnTimer
        };

        struct npc_foundry_scorching_burnsAI : public ScriptedAI
        {
            npc_foundry_scorching_burnsAI(Creature* p_Creature) : ScriptedAI(p_Creature), summons(p_Creature){ }

            EventMap m_Events;
            SummonList summons;
            uint32 m_BeltEntry;

            std::set<ObjectGuid> m_AffectedPlayers;

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);

                m_Events.Reset();

                summons.DespawnAll();

                for (ObjectGuid l_Guid : m_AffectedPlayers)
                {
                   // if (Player* l_Player = Player::GetPlayer(*me, l_Guid))
                        //l_Player->SendApplyMovementForce(me->GetGUID(), false, Position());
                }

                m_AffectedPlayers.clear();

                m_BeltEntry = 0;

              //  ClearDelayedOperations();
            }

            void DamageTaken(Unit* /*p_Attacker*/, uint32& p_Damage) override
            {
                p_Damage = 0;
            }

            void SetData(uint32 p_ID, uint32 p_Value) override
            {
                switch (p_ID)
                {
                    case eDatas::DataBeltEntry:
                    {
                        m_BeltEntry = p_Value;
                        break;
                    }
                    case eDatas::DataSpawnTimer:
                    {
                        //AddTimedDelayedOperation(p_Value, [this]() -> void
                       // {
                            DoAction(eAction::ActionSearingPlate);
                      //  });

                        break;
                    }
                    default:
                        break;
                }
            }

            void DoAction(int32 p_Action)
            {
                switch (p_Action)
                {
                    case eAction::ActionSearingPlate:
                    {
                        me->CastSpell(me, eSpells::ScorchingBurnsAT, false);

                        if (g_ForgeOverdriveSpawnPos.find(m_BeltEntry) != g_ForgeOverdriveSpawnPos.end())
                        {
                            Position const l_SpawnPos = g_ForgeOverdriveSpawnPos[m_BeltEntry];

                            if (Creature* l_ForgeOverdrive = me->SummonCreature(eCreature::ForgeOverdrive, l_SpawnPos))
                            {
                                using ForgeOverdriveAIPtr   = npc_foundry_forge_overdrive::npc_foundry_forge_overdriveAI*;
                                using ForgeOverdriveAI      = npc_foundry_forge_overdrive::npc_foundry_forge_overdriveAI;

                                if (ForgeOverdriveAIPtr l_AI = CAST_AI(ForgeOverdriveAI, l_ForgeOverdrive->GetAI()))
                                    l_AI->m_BeltEntry = m_BeltEntry;
                            }
                        }

                        break;
                    }
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 p_Diff) override
            {
               // UpdateOperations(p_Diff);

                if (me->HasAura(eSpells::ScorchingBurnsAT))
                {
                    float l_DistCheck = 13.0f;

                    std::list<Player*> l_PlayerList;
                    me->GetPlayerListInGrid(l_PlayerList, 30.0f);

                    for (Player* l_Player : l_PlayerList)
                    {
                        if (l_Player->GetDistance(me) <= l_DistCheck)
                        {
                            if (!l_Player->HasAura(eSpells::ScorchingBurnsDoT, me->GetGUID()))
                                me->CastSpell(l_Player, eSpells::ScorchingBurnsDoT, true);
                        }
                        else if (l_Player->FindNearestCreature(me->GetEntry(), l_DistCheck) == nullptr)
                        {
                            if (l_Player->HasAura(eSpells::ScorchingBurnsDoT, me->GetGUID()))
                                l_Player->RemoveAura(eSpells::ScorchingBurnsDoT, me->GetGUID());
                        }
                    }
                }

                if (g_ConveyorForceMovesDirection.find(m_BeltEntry) != g_ConveyorForceMovesDirection.end())
                {
                    float l_MaxDist = 84.0f;

                    std::set<ObjectGuid> l_Targets;

                    Map::PlayerList const& l_PlayerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator l_Iter = l_PlayerList.begin(); l_Iter != l_PlayerList.end(); ++l_Iter)
                    {
                        if (Player* l_Player = l_Iter->GetSource())
                        {
                            if (l_Player->GetDistance(me) >= l_MaxDist)
                                continue;

                            if (l_Player->GetPositionY() <= me->GetPositionY() + 6.5f &&
                                l_Player->GetPositionY() >= me->GetPositionY() - 6.5f)
                                l_Targets.insert(l_Player->GetGUID());
                        }
                    }

                    for (std::set<ObjectGuid>::iterator l_Iter = m_AffectedPlayers.begin(); l_Iter != m_AffectedPlayers.end();)
                    {
                        if (l_Targets.find((*l_Iter)) == l_Targets.end())
                        {
                           // if (Player* l_Player = ObjectAccessor::GetPlayer(*me, (*l_Iter)))
                               // l_Player->SendApplyMovementForce(me->GetGUID(), false, Position());

                            l_Iter = m_AffectedPlayers.erase(l_Iter);
                        }
                        else
                            ++l_Iter;
                    }

                    for (ObjectGuid l_Guid : l_Targets)
                    {
                        if (Player* l_Player = ObjectAccessor::GetPlayer(*me, l_Guid))
                        {
                           // if (!l_Player->HasMovementForce(me->GetGUID()))
                           // {
                            //    l_Player->SendApplyMovementForce(me->GetGUID(), true, g_ConveyorForceMovesDirection[m_BeltEntry], 6.0f, 0, G3D::Vector3(-6.0f, 0.0f, 0.0f));

                                m_AffectedPlayers.insert(l_Guid);
                           // }
                        }
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_scorching_burnsAI(p_Creature);
        }
};

/// Stamping Presses - 78358
class npc_foundry_stamping_presses : public CreatureScript
{
    public:
        npc_foundry_stamping_presses() : CreatureScript("npc_foundry_stamping_presses") { }

        enum eSpell
        {
            PulverizedDamage = 158140
        };

        enum eActions
        {
            ActionStamp = 2,
            ActionCancelStamp
        };

        enum eData
        {
            DataStampTimer = 3
        };

        struct npc_foundry_stamping_pressesAI : public ScriptedAI
        {
            npc_foundry_stamping_pressesAI(Creature* p_Creature) : ScriptedAI(p_Creature)
            {
                m_StampTimer = 0;
            }

            uint32 m_StampTimer;

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);
            }

            void DamageTaken(Unit* /*p_Attacker*/, uint32& p_Damage) override
            {
                p_Damage = 0;
            }

            void SetData(uint32 p_ID, uint32 p_Value) override
            {
                if (p_ID == eData::DataStampTimer)
                    m_StampTimer = p_Value;
            }

            void DoAction(int32 p_Action)
            {
                switch (p_Action)
                {
                    case eActions::ActionStamp:
                    {
                      //  AddTimedDelayedOperation(m_StampTimer, [this]() -> void
                      //  {
                            float l_CheckX = 5.0f;
                            float l_CheckY = 7.5f;

                            std::set<ObjectGuid> l_Targets;

                            Map::PlayerList const& l_PlayerList = me->GetMap()->GetPlayers();
                            for (Map::PlayerList::const_iterator l_Iter = l_PlayerList.begin(); l_Iter != l_PlayerList.end(); ++l_Iter)
                            {
                                if (Player* l_Player = l_Iter->GetSource())
                                {
                                    if (l_Player->GetPositionX() <= (me->GetPositionX() + l_CheckX) && l_Player->GetPositionX() >= (me->GetPositionX() - l_CheckX) &&
                                        l_Player->GetPositionY() <= (me->GetPositionY() + l_CheckY) && l_Player->GetPositionY() >= (me->GetPositionY() - l_CheckY))
                                        l_Targets.insert(l_Player->GetGUID());
                                }
                            }

                            /// Achievement disabled
                            if (!l_Targets.empty())
                            {
                                if (InstanceScript* l_Instance = me->GetInstanceScript())
                                    l_Instance->SetData(eFoundryDatas::PlayerStamped, 1);
                            }

                            for (ObjectGuid l_Guid : l_Targets)
                            {
                                if (Player* l_Player = ObjectAccessor::GetPlayer(*me, l_Guid))
                                    me->CastSpell(l_Player, eSpell::PulverizedDamage, true);
                            }

                            m_StampTimer = 0;
                       // });

                        break;
                    }
                    case eActions::ActionCancelStamp:
                    {
                       // ClearDelayedOperations();
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
            return new npc_foundry_stamping_pressesAI(p_Creature);
        }
};

/// Pumped Up - 155665
class spell_foundry_pumped_up : public SpellScriptLoader
{
    public:
        spell_foundry_pumped_up() : SpellScriptLoader("spell_foundry_pumped_up") { }

        class spell_foundry_pumped_up_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_foundry_pumped_up_AuraScript);

            void OnTick(AuraEffect const* /*p_AurEff*/)
            {
                if (Unit* l_Target = GetTarget())
                {
                    if (AuraEffect* l_AurEff = l_Target->GetAuraEffect(GetSpellInfo()->Id, EFFECT_0))
                    {
                        int32 l_Pct = 100 - (int32)l_Target->GetHealthPct();

                        l_Target->SetPower(Powers::POWER_ENERGY, l_Pct);
                        l_AurEff->ChangeAmount(l_Pct);
                    }
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_foundry_pumped_up_AuraScript::OnTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_foundry_pumped_up_AuraScript();
        }
};

/// Crippling Suplex - 156938
class spell_foundry_crippling_suplex : public SpellScriptLoader
{
    public:
        spell_foundry_crippling_suplex() : SpellScriptLoader("spell_foundry_crippling_suplex") { }

        enum eDatas
        {
            DataMainTankHealth,
            DataOffTankHealth   ///< ExplicitTarget of Crippling Suplex
        };

        class spell_foundry_crippling_suplex_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_foundry_crippling_suplex_SpellScript);

            void HandleDamage(SpellEffIndex /*p_EffIndex*/)
            {
                if (GetCaster() == nullptr)
                    return;

                if (Creature* l_Boss = GetCaster()->ToCreature())
                {
                    if (Unit* l_MainTarget = GetExplTargetUnit())
                    {
                        if (Unit* l_Target = GetHitUnit())
                        {
                            int32 l_Damage = 0;

                            if (l_MainTarget != l_Target)
                                l_Damage = l_Boss->IsAIEnabled ? l_Boss->AI()->GetData(eDatas::DataMainTankHealth) : 0;
                            else
                                l_Damage = l_Boss->IsAIEnabled ? l_Boss->AI()->GetData(eDatas::DataOffTankHealth) : 0;

                            if (l_Damage)
                                SetHitDamage(l_Damage);
                        }
                    }
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_foundry_crippling_suplex_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_foundry_crippling_suplex_SpellScript();
        }
};

/// Body Slam (Red Arrow) - 156892
class spell_foundry_body_slam_red_arrow : public SpellScriptLoader
{
    public:
        spell_foundry_body_slam_red_arrow() : SpellScriptLoader("spell_foundry_body_slam_red_arrow") { }

        class spell_foundry_body_slam_red_arrow_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_foundry_body_slam_red_arrow_AuraScript);

            enum eSpell
            {
                BodySlam = 155747
            };

            void OnRemove(AuraEffect const* /*p_AurEff*/, AuraEffectHandleModes /*p_Mode*/)
            {
                AuraRemoveMode l_RemoveMode = GetTargetApplication()->GetRemoveMode();
                if (l_RemoveMode != AuraRemoveMode::AURA_REMOVE_BY_EXPIRE)
                    return;

                if (Unit* l_Caster = GetCaster())
                {
                    if (Unit* l_Target = GetTarget())
                        l_Caster->CastSpell(l_Target, eSpell::BodySlam, true);
                }
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_foundry_body_slam_red_arrow_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_foundry_body_slam_red_arrow_AuraScript();
        }
};

void AddSC_boss_hansgar_and_franzok()
{
    /// Bosses
    new boss_hansgar();/// Hans'gar - 76973
    new boss_franzok();/// Franzok - 76974

    /// Creatures
    new npc_foundry_forge_overdrive();/// Forge Overdrive - 77258
    new npc_foundry_scorching_burns();/// Scorching Burns - 78823
    new npc_foundry_stamping_presses();/// Stamping Presses - 78358

    /// Spells
    new spell_foundry_pumped_up();/// Pumped Up - 155665
    new spell_foundry_crippling_suplex();/// Crippling Suplex - 156938
    new spell_foundry_body_slam_red_arrow();/// Body Slam (Red Arrow) - 156892
}
