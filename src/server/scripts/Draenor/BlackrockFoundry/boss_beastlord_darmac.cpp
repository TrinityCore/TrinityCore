# include "boss_beastlord_darmac.h"

/// Beastlord Darmac <The Iron Claw> - 76865
class boss_beastlord_darmac : public CreatureScript
{
    public:
        boss_beastlord_darmac() : CreatureScript("boss_beastlord_darmac") { }

        enum eTalks
        {
            TalkAggro,
            TalkMountCruelfang,
            TalkCruelfangsSwiftness,
            TalkMountIroncrusher,
            TalkIroncrushersRage,
            TalkMountDreadwing,
            TalkDreadwingsFlame,
            TalkMountFaultline,
            TalkFaultlineDetermination,
            TalkRendAndTear,
            TalkTantrum,
            TalkSuperheatedShrapnel,
            TalkSlay,
            TalkDeath,
            TalkSuperheatedShrapnelWarn,
            TalkTantrumWarn
        };

        enum eSpells
        {
            /// Misc
            BeastlordDarmacBonus    = 177536,
            TargetVehicle           = 155702,
            RideVehicle             = 155700,
            CrushArmor              = 155236,
            PinnedDownDamage        = 154960,
            RendAndTearTriggered2   = 155061,
            InfernoBreathDebuff     = 154989,
            FuryOfTheElekk          = 155460,
            CunningOfTheWolf        = 155458,
            SpiritOfTheRylak        = 155459,
            TantrumPeriodic         = 155520,
            SearedFleshDebuff       = 155030,
            ConflagrationDebuff     = 154981,
            /// Pin Down
            PinDownSearcher         = 155365,
            PinDownMissile          = 154951,
            /// Call the Pack
            CallThePackCast         = 154975,
            /// Rend and Tear
            RendAndTearSearcher     = 155515,
            RendAndTearJump         = 162279,
            RendAndTearTriggered    = 162283,
            RendAndTearJumpSecond   = 162285,
            /// Superheated Shrapnel
            FaceRandomNonTank       = 155603,
            SuperheatedShrapnel     = 155497,
            SuperheatedShrapnelDoT  = 155499
        };

        enum eEvents
        {
            /// Stage One: Ferocious Feet
            EventBerserker = 1,
            EventCallThePack,
            EventPinDown,
            /// Stage Two: Back of the Beast
            /// Ironcrusher
            EventTantrum,
            /// Dreadwing
            EventSuperheatedShrapnel,
            /// Cruelfang
            EventRendAndTear
            /// Faultline (Mythic only)
            /// Stage Three: Spiritual Successor
        };

        enum eTimers
        {
            TimerBerserker                      = 12 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS,
            TimerCallThePack                    = 8 * TimeConstants::IN_MILLISECONDS,
            TimerCallThePackLFR                 = 18 * TimeConstants::IN_MILLISECONDS,
            TimerCallThePackCooldown            = 30 * TimeConstants::IN_MILLISECONDS,
            TimerCallThePackLFRCooldown         = 40 * TimeConstants::IN_MILLISECONDS,
            TimerPinDown                        = 9 * TimeConstants::IN_MILLISECONDS + 500,
            TimerPinDownCooldown                = 19 * TimeConstants::IN_MILLISECONDS + 700,
            TimerTantrum                        = 22 * TimeConstants::IN_MILLISECONDS,
            TimerTantrumCooldown                = 23 * TimeConstants::IN_MILLISECONDS,
            TimerRendAndTear                    = 20 * TimeConstants::IN_MILLISECONDS,
            TimerRendAndTearCooldown            = 12 * TimeConstants::IN_MILLISECONDS,
            TimerSuperheatedShrapnel            = 12 * TimeConstants::IN_MILLISECONDS,
            TimerSuperheatedShrapnelCooldown    = 25 * TimeConstants::IN_MILLISECONDS
        };

        enum eActions
        {
            ActionCallThePack,
            ActionIroncrusherKilled,
            ActionCruelfangKilled,
            ActionDreadwingKilled
        };

        enum eCreatures
        {
            HitchingPost    = 79914,
            PackBeast       = 77128
        };

        enum eVisuals
        {
            EmoteUse    = 69,
            EmoteYes    = 273
        };

        enum eMoves
        {
            MoveIronCrusher = 50,
            MoveCruelfang,
            MoveDreadwing
        };

        enum eStates
        {
            StateNone,
            StateFirstMount,
            StateSecondMount,
            StateThirdMount,
            StateNoneSecond
        };

        struct boss_beastlord_darmacAI : public BossAI
        {
            boss_beastlord_darmacAI(Creature* p_Creature) : BossAI(p_Creature, eFoundryDatas::DataBeastlordDarmac)
            {
                m_Instance  = p_Creature->GetInstanceScript();
            }

            InstanceScript* m_Instance;

            EventMap m_Events;

            uint8 m_CosmeticMove;

            int32 m_SwitchStatePct;
            uint8 m_State;

            bool m_RendAndTear;
            bool m_Tantrum;

            uint32 m_MountID;

            bool CanRespawn()
            {
                if (m_Instance == nullptr)
                    return false;
                else
                    return true;
            }

            void Reset() override
            {
               // ClearDelayedOperations();

                summons.DespawnAll();

                _Reset();

                me->RemoveAllAreaTriggers();

                m_Events.Reset();

                me->SetReactState(ReactStates::REACT_AGGRESSIVE);
                me->RemoveUnitFlag(UnitFlags(UnitFlags2::UNIT_FLAG2_DISABLE_TURN));
                me->ClearUnitState(UnitState::UNIT_STATE_CANNOT_TURN);

                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));

                me->RemoveAura(eFoundrySpells::Berserker);

                me->RemoveAura(eSpells::FuryOfTheElekk);
                me->RemoveAura(eSpells::CunningOfTheWolf);
                me->RemoveAura(eSpells::SpiritOfTheRylak);

                m_CosmeticMove = eMoves::MoveIronCrusher;

                m_SwitchStatePct    = 85;
                m_State             = eStates::StateNone;

                m_RendAndTear       = false;
                m_Tantrum           = false;

                m_MountID           = 0;

                uint32 l_Time = 100;
               // AddTimedDelayedOperation(l_Time, [this]() -> void
               // {
                   // me->SetUInt32Value(UnitFields::UNIT_NPC_EMOTESTATE, 0);
              //  });

                l_Time += 9 * TimeConstants::IN_MILLISECONDS;
              //  AddTimedDelayedOperation(l_Time, [this]() -> void
               // {
                    me->HandleEmoteCommand(eVisuals::EmoteYes);
               // });

                l_Time += 1 * TimeConstants::IN_MILLISECONDS;
               // AddTimedDelayedOperation(l_Time, [this]() -> void
               // {
                    me->SetWalk(true);
                    me->GetMotionMaster()->MovePoint(m_CosmeticMove + 1, g_DarmacCosmeticMoves[m_CosmeticMove - eMoves::MoveIronCrusher]);
               // });

                ResetBeasts();
            }

            void KilledUnit(Unit* p_Who) override
            {
                if (p_Who->GetTypeId() != TYPEID_PLAYER)
                    return;

                Talk(eTalks::TalkSlay);
            }

            void EnterCombat(Unit* p_Attacker) override
            {
              //  ClearDelayedOperations();

                me->SetWalk(false);
                me->StopMoving();

                ObjectGuid l_Guid = p_Attacker->GetGUID();
              //  AddTimedDelayedOperation(50, [this, l_Guid]() -> void
               // {
                    if (Unit* l_Attacker = ObjectAccessor::GetUnit(*me, l_Guid))
                    {
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MoveChase(l_Attacker);
                    }
              //  });

            //    me->SetUInt32Value(UnitFields::UNIT_NPC_EMOTESTATE, 0);

                _EnterCombat();

                Talk(eTalks::TalkAggro);

                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me, 1);

                m_Events.ScheduleEvent(eEvents::EventBerserker, eTimers::TimerBerserker);
                m_Events.ScheduleEvent(eEvents::EventCallThePack,eTimers::TimerCallThePackLFR);
                m_Events.ScheduleEvent(eEvents::EventPinDown, eTimers::TimerPinDown);
            }

            void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER)
            {
                std::vector<uint32> l_Beasts = { eFoundryCreatures::BossIroncrusher, eFoundryCreatures::BossDreadwing, eFoundryCreatures::BossCruelfang };

                for (uint32 l_Entry : l_Beasts)
                {
                    if (Creature* l_Beast = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(l_Entry)))
                    {
                        if (Vehicle* l_Vehicle = l_Beast->GetVehicleKit())
                            l_Vehicle->RemoveAllPassengers();
                    }
                }

               // me->DespawnCreaturesInArea( eCreatures::PackBeast );

                if (m_Instance != nullptr)
                {
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::CrushArmor);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::PinnedDownDamage);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::RendAndTearTriggered);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::RendAndTearTriggered2);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::InfernoBreathDebuff);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::SuperheatedShrapnelDoT);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::SearedFleshDebuff);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::ConflagrationDebuff);
                }

                CreatureAI::EnterEvadeMode();
            }

            void JustDied(Unit* /*p_Killer*/) override
            {
                me->RemoveAllAreaTriggers();

                me->InterruptNonMeleeSpells(true);

                summons.DespawnAll();

               // me->DespawnCreaturesInArea( eCreatures::PackBeast );

                _JustDied();

                Talk(eTalks::TalkDeath);

                if (m_Instance != nullptr)
                {
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::CrushArmor);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::PinnedDownDamage);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::RendAndTearTriggered);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::RendAndTearTriggered2);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::InfernoBreathDebuff);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::SuperheatedShrapnelDoT);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::SearedFleshDebuff);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::ConflagrationDebuff);

                    /// Allow loots and bonus loots to be enabled/disabled with a simple reload
                    //if (sObjectMgr->IsDisabledEncounter(m_Instance->GetEncounterIDForBoss(me), GetDifficulty()))
                      //  me->SetLootRecipient(nullptr);
                   // else
                        CastSpellToPlayers(me->GetMap(), me, eSpells::BeastlordDarmacBonus, true);
                }
            }

            void JustSummoned(Creature* p_Summon) override
            {
                BossAI::JustSummoned(p_Summon);

                if (!me->IsInCombat())
                    p_Summon->DespawnOrUnsummon();
            }

            void MovementInform(uint32 p_Type, uint32 p_ID) override
            {
                if (p_Type != MovementGeneratorType::POINT_MOTION_TYPE &&
                    p_Type != MovementGeneratorType::EFFECT_MOTION_TYPE)
                    return;

                switch (p_ID)
                {
                    case eMoves::MoveIronCrusher:
                    case eMoves::MoveCruelfang:
                    {
                        if (me->IsInCombat())
                            return;

                        ++m_CosmeticMove;
                        break;
                    }
                    case eMoves::MoveDreadwing:
                    {
                        if (me->IsInCombat())
                            return;

                        m_CosmeticMove = eMoves::MoveIronCrusher;
                        break;
                    }
                    case eSpells::RendAndTearJump:
                    {
                        me->CastSpell(me, eSpells::RendAndTearTriggered, true);

                       // AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                        //{
                            if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(l_Target, eSpells::RendAndTearJumpSecond, true);
                       // });

                        return;
                    }
                    case eSpells::RendAndTearJumpSecond:
                    {
                        me->CastSpell(me, eSpells::RendAndTearTriggered, true);

                       // AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                       // {
                            m_RendAndTear = false;
                       // });

                        return;
                    }
                    case eFoundryCreatures::BossIroncrusher:
                    {
                       // AddTimedDelayedOperation(50, [this]() -> void
                       // {
                            if (m_Instance == nullptr)
                                return;

                            if (Creature* l_Target = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(m_MountID)))
                                me->SetFacingTo(me->GetAngle(l_Target));

                            me->AddUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));
                      //  });

                       // AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                       // {
                            Talk(eTalks::TalkMountIroncrusher);
                      //  });

                      //  AddTimedDelayedOperation(2 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                       // {
                            if (m_Instance == nullptr)
                                return;

                            if (Creature* l_Target = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(m_MountID)))
                                me->CastSpell(l_Target, eSpells::RideVehicle, true);

                            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));

                            me->SetReactState(ReactStates::REACT_AGGRESSIVE);
                      //  });

                        return;
                    }
                    case eFoundryCreatures::BossDreadwing:
                    {
                       // AddTimedDelayedOperation(50, [this]() -> void
                       // {
                            if (m_Instance == nullptr)
                                return;

                            if (Creature* l_Target = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(m_MountID)))
                                me->SetFacingTo(me->GetAngle(l_Target));

                            me->AddUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));
                       // });

                      //  AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                       // {
                            Talk(eTalks::TalkMountDreadwing);
                       // });

                       // AddTimedDelayedOperation(2 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                        //{
                            if (m_Instance == nullptr)
                                return;

                            if (Creature* l_Target = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(m_MountID)))
                                me->CastSpell(l_Target, eSpells::RideVehicle, true);

                            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));

                            me->SetReactState(ReactStates::REACT_AGGRESSIVE);
                       // });

                        return;
                    }
                    case eFoundryCreatures::BossCruelfang:
                    {
                       // AddTimedDelayedOperation(50, [this]() -> void
                        //{
                            if (m_Instance == nullptr)
                                return;

                            if (Creature* l_Target = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(m_MountID)))
                                me->SetFacingTo(me->GetAngle(l_Target));

                            me->AddUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));
                       // });

                      //  AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                       // {
                            Talk(eTalks::TalkMountCruelfang);
                     //   });

                       // AddTimedDelayedOperation(2 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                       // {
                            if (m_Instance == nullptr)
                                return;

                            if (Creature* l_Target = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(m_MountID)))
                                me->CastSpell(l_Target, eSpells::RideVehicle, true);

                            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));

                            me->SetReactState(ReactStates::REACT_AGGRESSIVE);
                     //   });

                        return;
                    }
                    /* Mythic only
                    case eFoundryCreatures::BossFaultline:
                    {
                        return;
                    }
                    */
                    default:
                        return;
                }

                uint32 l_Time = 100;
               // AddTimedDelayedOperation(100, [this]() -> void
                //{
                 //   me->SetUInt32Value(UnitFields::UNIT_NPC_EMOTESTATE, eVisuals::EmoteUse);
                //});

                l_Time += 9 * TimeConstants::IN_MILLISECONDS;
                //AddTimedDelayedOperation(l_Time, [this]() -> void
                //{
                //    me->SetUInt32Value(UnitFields::UNIT_NPC_EMOTESTATE, 0);
                //});

                l_Time += 100;
               // AddTimedDelayedOperation(l_Time, [this]() -> void
               // {
                    me->HandleEmoteCommand(eVisuals::EmoteYes);
              //  });

                l_Time += 1 * TimeConstants::IN_MILLISECONDS;
               // AddTimedDelayedOperation(l_Time, [this]() -> void
               // {
                    me->SetWalk(true);
                    me->GetMotionMaster()->MovePoint(m_CosmeticMove, g_DarmacCosmeticMoves[m_CosmeticMove - eMoves::MoveIronCrusher]);
               // });
            }

            void DoAction(int32 p_Action)
            {
                m_Events.DelayEvents(7 * TimeConstants::IN_MILLISECONDS);

                uint32 l_Time = 2 * TimeConstants::IN_MILLISECONDS;
                //AddTimedDelayedOperation(l_Time, [this]() -> void
               // {
                    if (m_Instance == nullptr)
                        return;

                    if (Creature* l_Target = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(m_MountID)))
                        me->SetFacingTo(me->GetAngle(l_Target));

                    me->AddUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));
               // });

                l_Time += 50;
               // AddTimedDelayedOperation(l_Time, [this]() -> void
               // {
                    me->SetStandState(UnitStandStateType::UNIT_STAND_STATE_KNEEL);
               // });

                l_Time += 2 * TimeConstants::IN_MILLISECONDS;
               // AddTimedDelayedOperation(l_Time, [this, p_Action]() -> void
               // {
                    switch (p_Action)
                    {
                        case eActions::ActionIroncrusherKilled:
                        {
                            Talk(eTalks::TalkIroncrushersRage);

                            me->CastSpell(me, eSpells::FuryOfTheElekk, true);

                            if (me->HasAura(eSpells::CunningOfTheWolf))
                                m_Events.ScheduleEvent(eEvents::EventRendAndTear, eTimers::TimerRendAndTear);

                            if (me->HasAura(eSpells::SpiritOfTheRylak))
                                m_Events.ScheduleEvent(eEvents::EventSuperheatedShrapnel, eTimers::TimerSuperheatedShrapnel);

                            m_Events.ScheduleEvent(eEvents::EventTantrum, eTimers::TimerTantrum);
                            break;
                        }
                        case eActions::ActionCruelfangKilled:
                        {
                            Talk(eTalks::TalkCruelfangsSwiftness);

                            me->CastSpell(me, eSpells::CunningOfTheWolf, true);

                            if (me->HasAura(eSpells::FuryOfTheElekk))
                                m_Events.ScheduleEvent(eEvents::EventTantrum, eTimers::TimerTantrum);

                            if (me->HasAura(eSpells::SpiritOfTheRylak))
                                m_Events.ScheduleEvent(eEvents::EventSuperheatedShrapnel, eTimers::TimerSuperheatedShrapnel);

                            m_Events.ScheduleEvent(eEvents::EventRendAndTear, eTimers::TimerRendAndTear);
                            break;
                        }
                        case eActions::ActionDreadwingKilled:
                        {
                            Talk(eTalks::TalkDreadwingsFlame);

                            me->CastSpell(me, eSpells::SpiritOfTheRylak, true);

                            if (me->HasAura(eSpells::CunningOfTheWolf))
                                m_Events.ScheduleEvent(eEvents::EventRendAndTear, eTimers::TimerRendAndTear);

                            if (me->HasAura(eSpells::FuryOfTheElekk))
                                m_Events.ScheduleEvent(eEvents::EventTantrum, eTimers::TimerTantrum);

                            m_Events.ScheduleEvent(eEvents::EventSuperheatedShrapnel, eTimers::TimerSuperheatedShrapnel);
                            break;
                        }
                        default:
                            break;
                    }
              //  });

                l_Time += 2 * TimeConstants::IN_MILLISECONDS;
               // AddTimedDelayedOperation(l_Time, [this]() -> void
               // {
                    me->SetStandState(UnitStandStateType::UNIT_STAND_STATE_STAND);

                    me->HandleEmoteCommand(Emote::EMOTE_ONESHOT_ROAR);

                    if (Unit* l_Target = me->GetVictim())
                    {
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MoveChase(l_Target);
                    }
              //  });
            }

            void SpellHitTarget(Unit* p_Target, SpellInfo const* p_SpellInfo) override
            {
                if (p_Target == nullptr)
                    return;

                switch (p_SpellInfo->Id)
                {
                    case eSpells::PinDownSearcher:
                    {
                        me->CastSpell(p_Target, eSpells::PinDownMissile, true);
                        break;
                    }
                    case eSpells::TargetVehicle:
                    {
                        m_MountID = p_Target->GetEntry();

                        if (m_Instance != nullptr)
                        {
                            switch (m_MountID)
                            {
                                case eFoundryCreatures::BossDreadwing:
                                {
                                    m_Instance->SetData(eFoundryDatas::DarmacBeastMountedFirst, eFoundryDatas::DataDreadwingFirst);
                                    break;
                                }
                                case eFoundryCreatures::BossIroncrusher:
                                {
                                    m_Instance->SetData(eFoundryDatas::DarmacBeastMountedFirst, eFoundryDatas::DataIronCrusherFirst);
                                    break;
                                }
                                case eFoundryCreatures::BossCruelfang:
                                {
                                    m_Instance->SetData(eFoundryDatas::DarmacBeastMountedFirst, eFoundryDatas::DataCruelfangFirst);
                                    break;
                                }
                                default:
                                    break;
                            }
                        }

                        /// Delay events for cosmetic moves
                        m_Events.DelayEvents(3 * TimeConstants::IN_MILLISECONDS);

                        float l_Orientation = me->GetAngle(p_Target);
                        float l_Radius      = me->GetDistance(p_Target) - 1.5f;

                        float l_X           = me->m_positionX + l_Radius * cos(l_Orientation);
                        float l_Y           = me->m_positionY + l_Radius * sin(l_Orientation);

                        /// This prevent players to cancel moves by taunting
                        me->SetReactState(ReactStates::REACT_PASSIVE);

                        me->AttackStop();

                        me->StopMoving();

                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MovePoint(m_MountID, { l_X, l_Y, me->m_positionZ, l_Orientation });
                        break;
                    }
                    case eSpells::RendAndTearSearcher:
                    {
                        m_RendAndTear = true;

                        me->CastSpell(p_Target, eSpells::RendAndTearJump, true);
                        break;
                    }
                    case eSpells::FaceRandomNonTank:
                    {
                        me->SetFacingTo(me->GetAngle(p_Target));

                        me->SetReactState(ReactStates::REACT_PASSIVE);
                        me->AddUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));
                        me->AddUnitState(UnitState::UNIT_STATE_CANNOT_TURN);

                       // AddTimedDelayedOperation(50, [this]() -> void
                       // {
                            me->CastSpell(me, eSpells::SuperheatedShrapnel, false);
                       // });

                      //  AddTimedDelayedOperation(6 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                       // {
                            me->SetReactState(ReactStates::REACT_AGGRESSIVE);
                            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));
                            me->ClearUnitState(UnitState::UNIT_STATE_CANNOT_TURN);
                       // });

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
                    case eSpells::CallThePackCast:
                    {
                        if (m_Instance == nullptr)
                            break;

                        if (Creature* l_Trigger = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::ThunderlordPackPens)))
                        {
                            if (l_Trigger->IsAIEnabled)
                                l_Trigger->AI()->DoAction(eActions::ActionCallThePack);
                        }

                        break;
                    }
                    default:
                        break;
                }
            }

            void OnExitVehicle(Unit* /*p_Vehicle*/, Position& p_ExitPos)
            {
                float l_X = me->m_positionX - 2.5f /** cos(me->m_orientation)*/;
                float l_Y = me->m_positionY - 2.5f /** cos(me->m_orientation)*/;

                p_ExitPos = { l_X, l_Y, me->m_positionZ};
            }

            void DamageTaken(Unit* /*p_Attacker*/, uint32& p_Damage) override
            {
                if (m_SwitchStatePct <= 0)
                    return;

                if (me->HealthBelowPctDamaged(m_SwitchStatePct, p_Damage))
                {
                    /// Darmac will choose a Prime Beast to mount at 85%, 65%, and 45% health
                    switch (++m_State)
                    {
                        case eStates::StateFirstMount:
                        {
                            m_SwitchStatePct = 65;
                            break;
                        }
                        case eStates::StateSecondMount:
                        {
                            m_SwitchStatePct = 45;
                            break;
                        }
                        case eStates::StateThirdMount:
                        {
                            m_SwitchStatePct = 0;
                            break;
                        }
                        default:
                            break;
                    }

                    /// Choose nearest beast
                    me->CastSpell(me, eSpells::TargetVehicle, true);

                    m_Events.CancelEvent(eEvents::EventTantrum);
                    m_Events.CancelEvent(eEvents::EventRendAndTear);
                }
            }

            void UpdateAI(uint32 p_Diff) override
            {
                //UpdateOperations(p_Diff);

                if (me->GetDistance(me->GetHomePosition()) >= 75.0f)
                {
                    EnterEvadeMode();
                    return;
                }

                if (!UpdateVictim() || m_RendAndTear)
                    return;

                m_Events.Update(p_Diff);

                if (me->HasUnitState(UnitState::UNIT_STATE_CASTING) || m_Tantrum)
                    return;

                switch (m_Events.ExecuteEvent())
                {
                    case eEvents::EventBerserker:
                    {
                        me->CastSpell(me, eFoundrySpells::Berserker, true);
                        break;
                    }
                    case eEvents::EventCallThePack:
                    {
                        me->CastSpell(me, eSpells::CallThePackCast, false);

                        /// Call the Pack can be casted while walking
                        me->ClearUnitState(UnitState::UNIT_STATE_CASTING);

                        m_Events.ScheduleEvent(eEvents::EventCallThePack, eTimers::TimerCallThePackCooldown);
                        break;
                    }
                    case eEvents::EventPinDown:
                    {
                        me->CastSpell(me, eSpells::PinDownSearcher, true);
                        m_Events.ScheduleEvent(eEvents::EventPinDown, eTimers::TimerPinDownCooldown);
                        break;
                    }
                    case eEvents::EventTantrum:
                    {
                        Talk(eTalks::TalkTantrumWarn);
                        Talk(eTalks::TalkTantrum);

                        me->CastSpell(me, eSpells::TantrumPeriodic, false);

                        m_Tantrum = true;

                      //  AddTimedDelayedOperation(5 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                       // {
                            m_Tantrum = false;
                      //  });

                        m_Events.ScheduleEvent(eEvents::EventTantrum, eTimers::TimerTantrumCooldown);
                        break;
                    }
                    case eEvents::EventSuperheatedShrapnel:
                    {
                        Talk(eTalks::TalkSuperheatedShrapnelWarn);
                        Talk(eTalks::TalkSuperheatedShrapnel);

                        me->CastSpell(me, eSpells::FaceRandomNonTank, true);

                        m_Events.ScheduleEvent(eEvents::EventSuperheatedShrapnel, eTimers::TimerSuperheatedShrapnelCooldown);
                        break;
                    }
                    case eEvents::EventRendAndTear:
                    {
                        Talk(eTalks::TalkRendAndTear);

                        me->CastSpell(me, eSpells::RendAndTearSearcher, true);

                        m_Events.ScheduleEvent(eEvents::EventRendAndTear, eTimers::TimerRendAndTearCooldown);
                        break;
                    }
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }

            void ResetBeasts()
            {
                if (m_Instance == nullptr)
                    return;

                std::vector<uint32> l_Beasts = { eFoundryCreatures::BossIroncrusher, eFoundryCreatures::BossDreadwing, eFoundryCreatures::BossCruelfang };

                for (uint32 l_Entry : l_Beasts)
                {
                    if (Creature* l_Beast = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(l_Entry)))
                    {
                        if (l_Beast->isDead())
                        {
                            l_Beast->DespawnOrUnsummon();
                            l_Beast->Respawn();

                            ObjectGuid l_Guid = l_Beast->GetGUID();
                           // AddTimedDelayedOperation(100, [this, l_Guid]() -> void
                          //  {
                                if (Creature* l_Creature = ObjectAccessor::GetCreature(*me, l_Guid))
                                    l_Creature->GetMotionMaster()->MoveTargetedHome();
                           // });
                        }
                        else if (l_Beast->IsAIEnabled)
                            l_Beast->AI()->EnterEvadeMode();
                    }
                }

               // AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                //{
                    std::list<Creature*> l_Hitchings;
                    me->GetCreatureListWithEntryInGrid(l_Hitchings, eCreatures::HitchingPost, 100.0f);

                    for (Creature* l_Iter : l_Hitchings)
                    {
                        if (l_Iter->IsAIEnabled)
                            l_Iter->AI()->Reset();
                    }
               // });
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new boss_beastlord_darmacAI(p_Creature);
        }
};

/// Cruelfang - 76884
class npc_foundry_cruelfang : public CreatureScript
{
    public:
        npc_foundry_cruelfang() : CreatureScript("npc_foundry_cruelfang") { }

        enum eSpells
        {
            HitchingPostChain       = 161300,
            CruelfangsSwiftness     = 161294,
            RendAndTearSearcher     = 155385,
            RendAndTearTriggered    = 155061,
            RendAndTearJump         = 155060,
            RendAndTearJumpSecond   = 155567,
            SavageHowlDamage        = 155198,
            SavageHowlEnrage        = 155208
        };

        enum eEvents
        {
            EventRendAndTear = 1,
            EventRendAndTearSec,
            EventSavageHowl
        };

        enum eTimers
        {
            TimerRendAndTear            = 13 * TimeConstants::IN_MILLISECONDS,
            TimerRendAndTearCooldown    = 12 * TimeConstants::IN_MILLISECONDS,
            TimerSavageHowl             = 17 * TimeConstants::IN_MILLISECONDS,
            TimerSavageHowlCooldown     = 26 * TimeConstants::IN_MILLISECONDS
        };

        enum eAction
        {
            ActionCruelfangKilled = 2
        };

        struct npc_foundry_cruelfangAI : public ScriptedAI
        {
            npc_foundry_cruelfangAI(Creature* p_Creature) : ScriptedAI(p_Creature)
            {
                m_Instance = p_Creature->GetInstanceScript();
            }

            EventMap m_Events;
            EventMap m_CosmeticEvents;

            InstanceScript* m_Instance;

            bool m_IsEvadeMode;
            bool m_RendAndTear;

            void Reset() override
            {
                me->CastSpell(me, eSpells::CruelfangsSwiftness, true);

                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_NOT_SELECTABLE));

                m_Events.Reset();
                m_CosmeticEvents.Reset();

                m_IsEvadeMode = false;
                m_RendAndTear = false;
            }

            void EnterCombat(Unit* /*p_Attacker*/) override
            {
                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me, 4);

                m_Events.ScheduleEvent(eEvents::EventRendAndTear, eTimers::TimerRendAndTear);
                m_Events.ScheduleEvent(eEvents::EventSavageHowl, eTimers::TimerSavageHowl);
            }

            void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER)
            {
                m_IsEvadeMode = true;

                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                if (Vehicle* l_Vehicle = me->GetVehicleKit())
                    l_Vehicle->RemoveAllPassengers();

                CreatureAI::EnterEvadeMode();

                m_IsEvadeMode = false;
            }

            void JustDied(Unit* /*p_Killer*/) override
            {
                if (m_Instance != nullptr)
                {
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                    if (Creature* l_Darmac = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::BossBeastlordDarmac)))
                    {
                        if (l_Darmac->IsAIEnabled)
                            l_Darmac->AI()->DoAction(eAction::ActionCruelfangKilled);
                    }
                }

                me->DespawnOrUnsummon(10 * TimeConstants::IN_MILLISECONDS);
            }

            void MovementInform(uint32 p_Type, uint32 p_ID) override
            {
                if (p_Type != MovementGeneratorType::EFFECT_MOTION_TYPE)
                    return;

                switch (p_ID)
                {
                    case eSpells::RendAndTearJump:
                    {
                        me->CastSpell(me, eSpells::RendAndTearTriggered, true);

                        m_CosmeticEvents.ScheduleEvent(eEvents::EventRendAndTearSec, 1 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case eSpells::RendAndTearJumpSecond:
                    {
                        me->CastSpell(me, eSpells::RendAndTearTriggered, true);

                       // AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                       // {
                            m_RendAndTear = false;
                       // });

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

                if (p_SpellInfo->Id == eSpells::RendAndTearSearcher)
                {
                    m_RendAndTear = true;

                    me->CastSpell(p_Target, eSpells::RendAndTearJump, true);
                }
            }

            void OnSpellCasted(SpellInfo const* p_SpellInfo)
            {
                if (p_SpellInfo->Id == eSpells::SavageHowlDamage)
                {
                    std::list<Unit*> l_Allies;

                    Trinity::AnyFriendlyUnitInObjectRangeCheck l_Check(me, me, 15.0f);
                    Trinity::UnitListSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> l_Searcher(me, l_Allies, l_Check);
                   // me->VisitNearbyObject(15.0f, l_Searcher);

                    for (Unit* l_Iter : l_Allies)
                    {
                        if (me->IsValidAssistTarget(l_Iter))
                            l_Iter->CastSpell(l_Iter, eSpells::SavageHowlEnrage, true);
                    }
                }
            }

            void PassengerBoarded(Unit* p_Passenger, int8 /*p_SeatID*/, bool p_Apply) override
            {
                if (p_Apply)
                {
                    me->RemoveAura(eSpells::HitchingPostChain);

                    me->ToCreature()->SetReactState(ReactStates::REACT_AGGRESSIVE);

                    me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_NOT_SELECTABLE));

                    p_Passenger->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_NOT_SELECTABLE));

                    if (m_Instance != nullptr)
                        m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, p_Passenger);

                    if (Unit* l_Target = p_Passenger->GetVictim())
                        AttackStart(l_Target);
                }
                else
                {
                    p_Passenger->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_NOT_SELECTABLE));

                    if (m_Instance != nullptr)
                        m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, p_Passenger);

                    if (m_IsEvadeMode && p_Passenger->ToCreature() && p_Passenger->IsAIEnabled)
                        p_Passenger->ToCreature()->AI()->EnterEvadeMode();
                }
            }

            void UpdateAI(uint32 p_Diff) override
            {
                //UpdateOperations(p_Diff);

                m_CosmeticEvents.Update(p_Diff);

                if (m_CosmeticEvents.ExecuteEvent() == eEvents::EventRendAndTearSec)
                {
                    if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(l_Target, eSpells::RendAndTearJumpSecond, true);
                }

                if (!UpdateVictim() || m_RendAndTear)
                    return;

                m_Events.Update(p_Diff);

                if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                    return;

                switch (m_Events.ExecuteEvent())
                {
                    case eEvents::EventRendAndTear:
                    {
                        me->CastSpell(me, eSpells::RendAndTearSearcher, true);

                        m_Events.ScheduleEvent(eEvents::EventRendAndTear, eTimers::TimerRendAndTearCooldown);
                        break;
                    }
                    case eEvents::EventSavageHowl:
                    {
                        me->CastSpell(me, eSpells::SavageHowlDamage, false);
                        m_Events.ScheduleEvent(eEvents::EventSavageHowl, eTimers::TimerSavageHowlCooldown);
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
            return new npc_foundry_cruelfangAI(p_Creature);
        }
};

/// Dreadwing - 76874
class npc_foundry_dreadwing : public CreatureScript
{
    public:
        npc_foundry_dreadwing() : CreatureScript("npc_foundry_dreadwing") { }

        enum eSpells
        {
            HitchingPostChain   = 161300,
            SearingFangs        = 155028,
            DreadwingsFlame     = 161291,
            /// Inferno Breath
            FaceRandomNonTank   = 155423,
            InfernoBreath       = 154988,
            /// Conflagration
            ConflagrationSearch = 155399,
            ConflagrationProc   = 154981
        };

        enum eEvents
        {
            EventInfernoBreath = 1,
            EventConflagration
        };

        enum eTimers
        {
            TimerInfernoBreath          = 5 * TimeConstants::IN_MILLISECONDS,
            TimerInfernoBreathCooldown  = 20 * TimeConstants::IN_MILLISECONDS,
            TimerConflagration          = 12 * TimeConstants::IN_MILLISECONDS,
            TimerConflagrationCooldown  = 20 * TimeConstants::IN_MILLISECONDS
        };

        enum eAction
        {
            ActionDreadwingKilled = 3
        };

        enum eTalk
        {
            TalkInfernoBreathWarn
        };

        struct npc_foundry_dreadwingAI : public ScriptedAI
        {
            npc_foundry_dreadwingAI(Creature* p_Creature) : ScriptedAI(p_Creature)
            {
                m_Instance = p_Creature->GetInstanceScript();
            }

            EventMap m_Events;

            InstanceScript* m_Instance;

            bool m_IsEvadeMode;

            void Reset() override
            {
                me->CastSpell(me, eSpells::SearingFangs, true);
                me->CastSpell(me, eSpells::DreadwingsFlame, true);

                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_NOT_SELECTABLE));

                me->RemoveAllAreaTriggers();

                m_Events.Reset();

                m_IsEvadeMode = false;
            }

            void EnterCombat(Unit* /*p_Attacker*/) override
            {
                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me, 4);

                m_Events.ScheduleEvent(eEvents::EventInfernoBreath, eTimers::TimerInfernoBreath);
                m_Events.ScheduleEvent(eEvents::EventConflagration, eTimers::TimerConflagration);
            }

            void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER)
            {
                m_IsEvadeMode = true;

                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                if (Vehicle* l_Vehicle = me->GetVehicleKit())
                    l_Vehicle->RemoveAllPassengers();

                CreatureAI::EnterEvadeMode();

                m_IsEvadeMode = false;
            }

            void JustDied(Unit* /*p_Killer*/) override
            {
                if (m_Instance != nullptr)
                {
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                    if (Creature* l_Darmac = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::BossBeastlordDarmac)))
                    {
                        if (l_Darmac->IsAIEnabled)
                            l_Darmac->AI()->DoAction(eAction::ActionDreadwingKilled);
                    }
                }

                me->DespawnOrUnsummon(10 * TimeConstants::IN_MILLISECONDS);
            }

            void PassengerBoarded(Unit* p_Passenger, int8 /*p_SeatID*/, bool p_Apply) override
            {
                if (p_Apply)
                {
                    me->RemoveAura(eSpells::HitchingPostChain);

                    me->ToCreature()->SetReactState(ReactStates::REACT_AGGRESSIVE);

                    me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_NOT_SELECTABLE));

                    p_Passenger->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_NOT_SELECTABLE));

                    if (m_Instance != nullptr)
                        m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, p_Passenger);

                    if (Unit* l_Target = p_Passenger->GetVictim())
                        AttackStart(l_Target);
                }
                else
                {
                    p_Passenger->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_NOT_SELECTABLE));

                    if (m_Instance != nullptr)
                        m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, p_Passenger);

                    if (m_IsEvadeMode && p_Passenger->ToCreature() && p_Passenger->IsAIEnabled)
                        p_Passenger->ToCreature()->AI()->EnterEvadeMode();
                }
            }

            void SpellHitTarget(Unit* p_Target, SpellInfo const* p_SpellInfo) override
            {
                if (p_Target == nullptr)
                    return;

                switch (p_SpellInfo->Id)
                {
                    case eSpells::FaceRandomNonTank:
                    {
                        me->SetFacingTo(me->GetAngle(p_Target));

                        me->SetReactState(ReactStates::REACT_PASSIVE);
                        me->AddUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));
                        me->AddUnitState(UnitState::UNIT_STATE_CANNOT_TURN);

                      //  AddTimedDelayedOperation(50, [this]() -> void
                        //{
                            me->CastSpell(me, eSpells::InfernoBreath, false);
                       // });

                       // AddTimedDelayedOperation(6 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                      //  {
                            me->SetReactState(ReactStates::REACT_AGGRESSIVE);
                            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));
                            me->ClearUnitState(UnitState::UNIT_STATE_CANNOT_TURN);
                      //  });

                        break;
                    }
                    case eSpells::ConflagrationSearch:
                    {
                        me->CastSpell(p_Target, eSpells::ConflagrationProc, true);
                        break;
                    }
                    default:
                        break;
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
                    case eEvents::EventInfernoBreath:
                    {
                        me->CastSpell(me, eSpells::FaceRandomNonTank, true);
                        m_Events.ScheduleEvent(eEvents::EventInfernoBreath, eTimers::TimerInfernoBreathCooldown);
                        break;
                    }
                    case eEvents::EventConflagration:
                    {
                        me->CastSpell(me, eSpells::ConflagrationSearch, true);
                        m_Events.ScheduleEvent(eEvents::EventConflagration, eTimers::TimerConflagrationCooldown);
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
            return new npc_foundry_dreadwingAI(p_Creature);
        }
};

/// Ironcrusher - 76945
class npc_foundry_ironcrusher : public CreatureScript
{
    public:
        npc_foundry_ironcrusher() : CreatureScript("npc_foundry_ironcrusher") { }

        enum eSpells
        {
            HitchingPostChain   = 161300,
            IroncrushersRage    = 161293,
            TantrumPeriodic     = 155221,
            StampedeSearcher    = 155416,
            StampedeCharge      = 155248,
            StampedeDamage      = 155247,
            StampedeTriggered   = 155531,
            CrushArmor          = 155236
        };

        enum eEvents
        {
            EventStampede = 1,
            EventTantrum,
            EventCrushArmor
        };

        enum eTimers
        {
            TimerStampede           = 15 * TimeConstants::IN_MILLISECONDS,
            TimerStampedeCooldown   = 20 * TimeConstants::IN_MILLISECONDS,
            TimerTantrum            = 25 * TimeConstants::IN_MILLISECONDS,
            TimerTantrumCooldown    = 23 * TimeConstants::IN_MILLISECONDS,
            TimerCrushArmor         = 8 * TimeConstants::IN_MILLISECONDS
        };

        enum eTalk
        {
            TalkTantrumWarning
        };

        enum eAction
        {
            ActionIroncrusherKilled = 1
        };

        struct npc_foundry_ironcrusherAI : public ScriptedAI
        {
            npc_foundry_ironcrusherAI(Creature* p_Creature) : ScriptedAI(p_Creature)
            {
                m_Instance = p_Creature->GetInstanceScript();
            }

            EventMap m_Events;

            InstanceScript* m_Instance;

            bool m_IsEvadeMode;
            bool m_Stampede;
            bool m_Tantrum;

            void Reset() override
            {
                me->CastSpell(me, eSpells::IroncrushersRage, true);

                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_NOT_SELECTABLE));

                m_Events.Reset();

                m_IsEvadeMode   = false;
                m_Stampede      = false;
                m_Tantrum       = false;
            }

            void EnterCombat(Unit* /*p_Attacker*/) override
            {
                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me, 4);

                m_Events.ScheduleEvent(eEvents::EventStampede, eTimers::TimerStampede);
                m_Events.ScheduleEvent(eEvents::EventTantrum, eTimers::TimerTantrum);
                m_Events.ScheduleEvent(eEvents::EventCrushArmor, eTimers::TimerCrushArmor);
            }

            void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER)
            {
                m_IsEvadeMode = true;

                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                if (Vehicle* l_Vehicle = me->GetVehicleKit())
                    l_Vehicle->RemoveAllPassengers();

                CreatureAI::EnterEvadeMode();

                m_IsEvadeMode = false;
            }

            void JustDied(Unit* /*p_Killer*/) override
            {
                if (m_Instance != nullptr)
                {
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                    if (Creature* l_Darmac = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::BossBeastlordDarmac)))
                    {
                        if (l_Darmac->IsAIEnabled)
                            l_Darmac->AI()->DoAction(eAction::ActionIroncrusherKilled);
                    }
                }

                me->DespawnOrUnsummon(10 * TimeConstants::IN_MILLISECONDS);
            }

            void PassengerBoarded(Unit* p_Passenger, int8 /*p_SeatID*/, bool p_Apply) override
            {
                if (p_Apply)
                {
                    me->RemoveAura(eSpells::HitchingPostChain);

                    me->ToCreature()->SetReactState(ReactStates::REACT_AGGRESSIVE);

                    me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_NOT_SELECTABLE));

                    p_Passenger->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_NOT_SELECTABLE));

                    if (m_Instance != nullptr)
                        m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, p_Passenger);

                    if (Unit* l_Target = p_Passenger->GetVictim())
                        AttackStart(l_Target);
                }
                else
                {
                    p_Passenger->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_NOT_SELECTABLE));

                    if (m_Instance != nullptr)
                        m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, p_Passenger);

                    if (m_IsEvadeMode && p_Passenger->ToCreature() && p_Passenger->IsAIEnabled)
                        p_Passenger->ToCreature()->AI()->EnterEvadeMode();
                }
            }

            void MovementInform(uint32 p_Type, uint32 p_ID) override
            {
                if (p_Type != MovementGeneratorType::POINT_MOTION_TYPE)
                    return;

                /// ...and stomps again.
                if (p_ID == eSpells::StampedeCharge)
                {
                    me->CastSpell(me, eSpells::StampedeTriggered, true);

                   // AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                   // {
                        m_Stampede = false;
                   // });
                }
            }

            void SpellHitTarget(Unit* p_Target, SpellInfo const* p_SpellInfo) override
            {
                if (p_Target == nullptr)
                    return;

                if (p_SpellInfo->Id == eSpells::StampedeSearcher)
                {
                    me->CastSpell(p_Target, eSpells::StampedeCharge, true);

                    m_Stampede = true;
                }
            }

            void UpdateAI(uint32 p_Diff) override
            {
               // UpdateOperations(p_Diff);

                if (!UpdateVictim() || m_Stampede)
                    return;

                m_Events.Update(p_Diff);

                if (me->HasUnitState(UnitState::UNIT_STATE_CASTING) || m_Tantrum)
                    return;

                switch (m_Events.ExecuteEvent())
                {
                    case eEvents::EventStampede:
                    {
                        /// Stomps the ground,...
                        me->CastSpell(me, eSpells::StampedeDamage, true);
                        /// ...charges to a distant enemy,...
                        me->CastSpell(me, eSpells::StampedeSearcher, true);

                        m_Events.ScheduleEvent(eEvents::EventStampede, eTimers::TimerStampedeCooldown);
                        break;
                    }
                    case eEvents::EventTantrum:
                    {
                        Talk(eTalk::TalkTantrumWarning);

                        /// Inflicts 23452 to 25922 Nature damage every 1 sec. for 5 sec.
                        me->CastSpell(me, eSpells::TantrumPeriodic, false);

                        m_Tantrum = true;

                        //AddTimedDelayedOperation(5 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                        //{
                            m_Tantrum = false;
                        //});

                        m_Events.ScheduleEvent(eEvents::EventTantrum, eTimers::TimerTantrumCooldown);
                        break;
                    }
                    case eEvents::EventCrushArmor:
                    {
                        if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO))
                            me->CastSpell(l_Target, eSpells::CrushArmor, true);

                        m_Events.ScheduleEvent(eEvents::EventCrushArmor, eTimers::TimerCrushArmor);
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
            return new npc_foundry_ironcrusherAI(p_Creature);
        }
};

/// Hitching Post - 79914
class npc_foundry_hitching_post : public CreatureScript
{
    public:
        npc_foundry_hitching_post() : CreatureScript("npc_foundry_hitching_post") { }

        enum eSpell
        {
            HitchingPostChain = 161300
        };

        struct npc_foundry_hitching_postAI : public ScriptedAI
        {
            npc_foundry_hitching_postAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);

               // AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void
               // {
                    me->CastSpell(me, eSpell::HitchingPostChain, false);
               // });
            }

            void UpdateAI(uint32 p_Diff) override
            {
                //UpdateOperations(p_Diff);
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_hitching_postAI(p_Creature);
        }
};

/// Heavy Spear - 76796
class npc_foundry_heavy_spear : public CreatureScript
{
    public:
        npc_foundry_heavy_spear() : CreatureScript("npc_foundry_heavy_spear") { }

        enum eSpells
        {
            PinDownVisualAura   = 155376,
            PinnedDownDamage    = 154960,
            FlameInfusion       = 155604,
            SeekingEmbersSearch = 155610,
            SeekingEmbersProc   = 155611
        };

        struct npc_foundry_heavy_spearAI : public ScriptedAI
        {
            npc_foundry_heavy_spearAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

            std::set<ObjectGuid> m_AffectedTargets;

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->AddUnitState(UnitState::UNIT_STATE_ROOT);

                me->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));
                me->AddUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));

                if (InstanceScript* l_Instance = me->GetInstanceScript())
                {
                    /// Summoning spell has a delay, prevent auras from being applied after death/reset
                    if (l_Instance->GetBossState(eFoundryDatas::DataBeastlordDarmac) == EncounterState::IN_PROGRESS)
                    {
                        me->CastSpell(me, eSpells::PinDownVisualAura, true);
                        me->CastSpell(me, eSpells::PinnedDownDamage, true);
                    }
                }
            }

            void SpellHitTarget(Unit* p_Target, SpellInfo const* p_SpellInfo) override
            {
                if (p_Target == nullptr)
                    return;

                switch (p_SpellInfo->Id)
                {
                    case eSpells::PinnedDownDamage:
                    {
                        m_AffectedTargets.insert(p_Target->GetGUID());
                        break;
                    }
                    case eSpells::SeekingEmbersSearch:
                    {
                        me->CastSpell(p_Target, eSpells::SeekingEmbersProc, true);
                        break;
                    }
                    default:
                        break;
                }
            }

            void JustDied(Unit* /*p_Killer*/) override
            {
                for (std::set<ObjectGuid>::iterator l_Guid = m_AffectedTargets.begin(); l_Guid != m_AffectedTargets.end();)
                {
                    if (Player* l_Player = ObjectAccessor::GetPlayer(*me, (*l_Guid)))
                    {
                        l_Guid = m_AffectedTargets.erase(l_Guid);
                        l_Player->RemoveAura(eSpells::PinnedDownDamage, me->GetGUID());
                    }
                    else
                        ++l_Guid;
                }
            }

            void JustDespawned()
            {
                for (std::set<ObjectGuid>::iterator l_Guid = m_AffectedTargets.begin(); l_Guid != m_AffectedTargets.end();)
                {
                    if (Player* l_Player = ObjectAccessor::GetPlayer(*me, (*l_Guid)))
                    {
                        l_Guid = m_AffectedTargets.erase(l_Guid);
                        l_Player->RemoveAura(eSpells::PinnedDownDamage, me->GetGUID());
                    }
                    else
                        ++l_Guid;
                }
            }

            void SpellHit(Unit* /*p_Attacker*/, SpellInfo const* p_SpellInfo) override
            {
                if (p_SpellInfo->Id == eSpells::FlameInfusion)
                    me->CastSpell(me, eSpells::SeekingEmbersSearch, true);
            }

            void UpdateAI(uint32 p_Diff) override
            {
                //UpdateOperations(p_Diff);
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_heavy_spearAI(p_Creature);
        }
};

/// Thunderlord Pack Pens - 77631
class npc_foundry_thunderlord_pack_pens : public CreatureScript
{
    public:
        npc_foundry_thunderlord_pack_pens() : CreatureScript("npc_foundry_thunderlord_pack_pens") { }

        enum eSpell
        {
            CallThePackSummon = 155668
        };

        enum eAction
        {
            ActionCallThePack
        };

        enum eData
        {
            CallThePackCount = 7
        };

        struct npc_foundry_thunderlord_pack_pensAI : public ScriptedAI
        {
            npc_foundry_thunderlord_pack_pensAI(Creature* p_Creature) : ScriptedAI(p_Creature)
            {
                m_Instance = p_Creature->GetInstanceScript();
            }

            InstanceScript* m_Instance;

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);
            }

            void DoAction(int32 p_Action) override
            {
                if (p_Action == eAction::ActionCallThePack && m_Instance != nullptr)
                {
                    if (GameObject* l_Door = ObjectAccessor::GetGameObject(*me, m_Instance->GetGuidData(eFoundryGameObjects::BeastsEnclosureDoor)))
                        l_Door->SetGoState(GOState::GO_STATE_ACTIVE);

                    for (uint8 l_I = 0; l_I < eData::CallThePackCount; ++l_I)
                        me->CastSpell(me, eSpell::CallThePackSummon, true);

                   // AddTimedDelayedOperation(3 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                   // {
                        if (GameObject* l_Door = ObjectAccessor::GetGameObject(*me, m_Instance->GetGuidData(eFoundryGameObjects::BeastsEnclosureDoor)))
                            l_Door->SetGoState(GOState::GO_STATE_READY);
                   // });
                }
            }

            void JustSummoned(Creature* p_Summon) override
            {
                if (m_Instance == nullptr)
                    return;

                if (Creature* l_Darmac = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::BossBeastlordDarmac)))
                {
                    if (Unit* l_Target = l_Darmac->GetVictim())
                    {
                        if (p_Summon->IsAIEnabled)
                            p_Summon->AI()->AttackStart(l_Target);
                    }
                }
            }

            void UpdateAI(uint32 p_Diff) override
            {
               // UpdateOperations(p_Diff);
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_thunderlord_pack_pensAI(p_Creature);
        }
};

/// Pack Beast - 77128
class npc_foundry_pack_beast : public CreatureScript
{
    public:
        npc_foundry_pack_beast() : CreatureScript("npc_foundry_pack_beast") { }

        enum eSpells
        {
            FlameInfusionTriggered      = 155650,
            FlameInfusionAreaTrigger    = 155653
        };

        struct npc_foundry_pack_beastAI : public ScriptedAI
        {
            npc_foundry_pack_beastAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

            void JustDied(Unit* /*p_Killer*/) override
            {
                /// Pack beasts despawns after 5 seconds if Dreadwing's alive, if not, 30 seconds.
                if (me->HasAura(eSpells::FlameInfusionTriggered))
                    me->CastSpell(me, eSpells::FlameInfusionAreaTrigger, true);
                else
                    me->DespawnOrUnsummon(5 * TimeConstants::IN_MILLISECONDS);
            }

            void AreaTriggerDespawned(AreaTrigger* p_AreaTrigger)
            {
                if (p_AreaTrigger->GetSpellId() == eSpells::FlameInfusionAreaTrigger)
                    me->DespawnOrUnsummon(50);
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_pack_beastAI(p_Creature);
        }
};

/// Hitching Post Chain - 161300
class spell_foundry_hitching_post_chain : public SpellScriptLoader
{
    public:
        spell_foundry_hitching_post_chain() : SpellScriptLoader("spell_foundry_hitching_post_chain") { }

        class spell_foundry_hitching_post_chain_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_foundry_hitching_post_chain_SpellScript);

            void CorrectTargets(std::list<WorldObject*>& p_Targets)
            {
                if (p_Targets.empty())
                    return;

                p_Targets.remove_if([this](WorldObject* p_Object) -> bool
                {
                    if (p_Object == nullptr || p_Object->IsPlayer())
                        return true;

                    if (p_Object->GetEntry() != eFoundryCreatures::BossIroncrusher &&
                        p_Object->GetEntry() != eFoundryCreatures::BossDreadwing &&
                        p_Object->GetEntry() != eFoundryCreatures::BossCruelfang)
                        return true;

                    return false;
                });

                if (p_Targets.empty())
                    return;

                p_Targets.sort(Trinity::ObjectDistanceOrderPred(GetCaster()));

                if (p_Targets.size() > 1)
                {
                    WorldObject* l_Target = p_Targets.front();
                    p_Targets.clear();
                    p_Targets.push_back(l_Target);
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_foundry_hitching_post_chain_SpellScript::CorrectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_foundry_hitching_post_chain_SpellScript();
        }
};

/// Pin Down (searcher) - 155365
/// Stampede (searcher) - 155416
/// Rend and Tear (Cruelfang's searcher) - 155385
/// Rend and Tear (Beastlord Darmac's searcher) - 155515
/// Face Random Non-Tank - 155423
/// Face Random Non-Tank - 155603
class spell_foundry_ranged_targets_searcher : public SpellScriptLoader
{
    public:
        spell_foundry_ranged_targets_searcher() : SpellScriptLoader("spell_foundry_ranged_targets_searcher") { }

        class spell_foundry_ranged_targets_searcher_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_foundry_ranged_targets_searcher_SpellScript);

            void CorrectTargets(std::list<WorldObject*>& p_Targets)
            {
                if (p_Targets.empty())
                    return;

                Unit* l_Caster = GetCaster();
                p_Targets.remove_if([l_Caster](WorldObject* p_Object) -> bool
                {
                    if (p_Object == nullptr || !p_Object->IsPlayer())
                        return true;

                    //if (!p_Object->ToPlayer()->IsRangedDamageDealer(l_Caster->ToCreature()))
                       // return true;

                    return false;
                });
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_foundry_ranged_targets_searcher_SpellScript::CorrectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_foundry_ranged_targets_searcher_SpellScript();
        }
};

/// Target Vehicle - 155702
class spell_foundry_target_vehicle : public SpellScriptLoader
{
    public:
        spell_foundry_target_vehicle() : SpellScriptLoader("spell_foundry_target_vehicle") { }

        class spell_foundry_target_vehicle_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_foundry_target_vehicle_SpellScript);

            void CorrectTargets(std::list<WorldObject*>& p_Targets)
            {
                p_Targets.clear();

                Unit* l_Caster = GetCaster();
                if (l_Caster == nullptr)
                    return;

                WorldObject* l_NearestBeast = nullptr;
                float l_Distance            = 100000.0f;

                if (InstanceScript* l_Instance = l_Caster->GetInstanceScript())
                {
                    if (Creature* l_Ironcrusher = ObjectAccessor::GetCreature(*l_Caster, l_Instance->GetGuidData(eFoundryCreatures::BossIroncrusher)))
                    {
                        if (l_Ironcrusher->IsAlive() && l_Caster->GetDistance(l_Ironcrusher) < l_Distance)
                        {
                            l_Distance      = l_Caster->GetDistance(l_Ironcrusher);
                            l_NearestBeast  = l_Ironcrusher;
                        }
                    }

                    if (Creature* l_Dreadwing = ObjectAccessor::GetCreature(*l_Caster, l_Instance->GetGuidData(eFoundryCreatures::BossDreadwing)))
                    {
                        if (l_Dreadwing->IsAlive() && l_Caster->GetDistance(l_Dreadwing) < l_Distance)
                        {
                            l_Distance      = l_Caster->GetDistance(l_Dreadwing);
                            l_NearestBeast  = l_Dreadwing;
                        }
                    }

                    if (Creature* l_Cruelfang = ObjectAccessor::GetCreature(*l_Caster, l_Instance->GetGuidData(eFoundryCreatures::BossCruelfang)))
                    {
                        if (l_Cruelfang->IsAlive() && l_Caster->GetDistance(l_Cruelfang) < l_Distance)
                        {
                            l_Distance      = l_Caster->GetDistance(l_Cruelfang);
                            l_NearestBeast  = l_Cruelfang;
                        }
                    }
                }

                if (l_NearestBeast == nullptr)
                    return;

                p_Targets.push_back(l_NearestBeast);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_foundry_target_vehicle_SpellScript::CorrectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_foundry_target_vehicle_SpellScript();
        }
};

/// Infusion of Flames! - 173974
class spell_foundry_infusion_of_flames : public SpellScriptLoader
{
    public:
        spell_foundry_infusion_of_flames() : SpellScriptLoader("spell_foundry_infusion_of_flames") { }

        class spell_foundry_infusion_of_flames_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_foundry_infusion_of_flames_SpellScript);

            enum eCreatures
            {
                HeavySpear  = 76796,
                PackBeast   = 77128
            };

            void CorrectTargets(std::list<WorldObject*>& p_Targets)
            {
                if (p_Targets.empty())
                    return;

                p_Targets.remove_if([this](WorldObject* p_Object) -> bool
                {
                    if (p_Object == nullptr)
                        return true;

                    if (p_Object->GetEntry() != eCreatures::HeavySpear &&
                        p_Object->GetEntry() != eCreatures::PackBeast)
                        return true;

                    return false;
                });
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_foundry_infusion_of_flames_SpellScript::CorrectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_foundry_infusion_of_flames_SpellScript::CorrectTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_foundry_infusion_of_flames_SpellScript();
        }
};

/// Inferno Breath - 155026
class areatrigger_foundry_inferno_breath : public AreaTriggerEntityScript
{
    public:
        areatrigger_foundry_inferno_breath() : AreaTriggerEntityScript("areatrigger_foundry_inferno_breath") { }

        enum eSpell
        {
            InfernoPyre = 156824
        };

        std::set<ObjectGuid> m_AffectedPlayers;

        void OnUpdate(AreaTrigger* p_AreaTrigger, uint32 /*p_Time*/)
        {
            if (Unit* l_Caster = p_AreaTrigger->GetCaster())
            {
                std::list<Unit*> l_TargetList;
                float l_Radius = 1.5f;

                Trinity::AnyUnfriendlyUnitInObjectRangeCheck l_Check(p_AreaTrigger, l_Caster, l_Radius);
                Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> l_Searcher(p_AreaTrigger, l_TargetList, l_Check);
               // p_AreaTrigger->VisitNearbyObject(l_Radius, l_Searcher);

                std::set<ObjectGuid> l_Targets;

                for (Unit* l_Iter : l_TargetList)
                {
                    l_Targets.insert(l_Iter->GetGUID());

                    if (!l_Iter->HasAura(eSpell::InfernoPyre))
                    {
                        m_AffectedPlayers.insert(l_Iter->GetGUID());
                        l_Caster->CastSpell(l_Iter, eSpell::InfernoPyre, true);
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
                        l_Unit->RemoveAura(eSpell::InfernoPyre);

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
                        l_Unit->RemoveAura(eSpell::InfernoPyre);
                }
            }
        }
        /*
        AreaTriggerEntityScript* GetAI()
        {
            return nullptr;
        }*/
};

/// Superheated Shrapnel - 155503
class areatrigger_foundry_superheated_shrapnel : public AreaTriggerEntityScript
{
    public:
        areatrigger_foundry_superheated_shrapnel() : AreaTriggerEntityScript("areatrigger_foundry_superheated_shrapnel") { }

        enum eSpell
        {
            SuperheatedScrap = 156823
        };

        std::set<ObjectGuid> m_AffectedPlayers;

        void OnUpdate(AreaTrigger* p_AreaTrigger, uint32 /*p_Time*/)
        {
            if (Unit* l_Caster = p_AreaTrigger->GetCaster())
            {
                std::list<Unit*> l_TargetList;
                float l_Radius = 1.5f;

                Trinity::AnyUnfriendlyUnitInObjectRangeCheck l_Check(p_AreaTrigger, l_Caster, l_Radius);
                Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> l_Searcher(p_AreaTrigger, l_TargetList, l_Check);
               // p_AreaTrigger->VisitNearbyObject(l_Radius, l_Searcher);

                std::set<ObjectGuid> l_Targets;

                for (Unit* l_Iter : l_TargetList)
                {
                    l_Targets.insert(l_Iter->GetGUID());

                    if (!l_Iter->HasAura(eSpell::SuperheatedScrap))
                    {
                        m_AffectedPlayers.insert(l_Iter->GetGUID());
                        l_Caster->CastSpell(l_Iter, eSpell::SuperheatedScrap, true);
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
                        l_Unit->RemoveAura(eSpell::SuperheatedScrap);

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
                        l_Unit->RemoveAura(eSpell::SuperheatedScrap);
                }
            }
        }
        /*
        AreaTriggerEntityScript* GetAI() const
        {
            return nullptr;
        }*/
};

/// Flame Infusion - 155653
class areatrigger_foundry_flame_infusion : public AreaTriggerEntityScript
{
    public:
        areatrigger_foundry_flame_infusion() : AreaTriggerEntityScript("areatrigger_foundry_flame_infusion") { }

        enum eSpell
        {
            FlameInfusionDoT = 155657
        };

        std::set<ObjectGuid> m_AffectedPlayers;

        void OnUpdate(AreaTrigger* p_AreaTrigger, uint32 /*p_Time*/)
        {
            if (Unit* l_Caster = p_AreaTrigger->GetCaster())
            {
                std::list<Unit*> l_TargetList;
                float l_Radius = 1.5f;

                Trinity::AnyUnfriendlyUnitInObjectRangeCheck l_Check(p_AreaTrigger, l_Caster, l_Radius);
                Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> l_Searcher(p_AreaTrigger, l_TargetList, l_Check);
               // p_AreaTrigger->VisitNearbyObject(l_Radius, l_Searcher);

                std::set<ObjectGuid> l_Targets;

                for (Unit* l_Iter : l_TargetList)
                {
                    l_Targets.insert(l_Iter->GetGUID());

                    if (!l_Iter->HasAura(eSpell::FlameInfusionDoT, l_Caster->GetGUID()))
                    {
                        m_AffectedPlayers.insert(l_Iter->GetGUID());
                        l_Caster->CastSpell(l_Iter, eSpell::FlameInfusionDoT, true);
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
                        l_Unit->RemoveAura(eSpell::FlameInfusionDoT, l_Caster->GetGUID());

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
                        l_Unit->RemoveAura(eSpell::FlameInfusionDoT, l_Caster->GetGUID());
                }
            }
        }
        /*
        AreaTriggerEntityScript* GetAI() const
        {
            return nullptr;
        }*/
};

void AddSC_boss_beastlord_darmac()
{
    /// Boss
    new boss_beastlord_darmac();/// Beastlord Darmac <The Iron Claw> - 76865

    /// Creatures
    new npc_foundry_cruelfang();/// Cruelfang - 76884
    new npc_foundry_dreadwing();/// Dreadwing - 76874
    new npc_foundry_ironcrusher();/// Ironcrusher - 76945
    new npc_foundry_hitching_post();/// Hitching Post - 79914
    new npc_foundry_heavy_spear();/// Heavy Spear - 76796
    new npc_foundry_thunderlord_pack_pens();/// Thunderlord Pack Pens - 77631
    new npc_foundry_pack_beast();/// Pack Beast - 77128

    /// Spells
    new spell_foundry_hitching_post_chain();/// Hitching Post Chain - 161300
    new spell_foundry_ranged_targets_searcher();/// Pin Down (searcher) - 155365- 155416 - 155385 - 155515 - 155423- 155603
    new spell_foundry_target_vehicle();/// Target Vehicle - 155702
    new spell_foundry_infusion_of_flames();/// Infusion of Flames! - 173974

    /// AreaTriggers
    new areatrigger_foundry_inferno_breath();/// Inferno Breath - 155026
    new areatrigger_foundry_superheated_shrapnel();/// Superheated Shrapnel - 155503
    new areatrigger_foundry_flame_infusion();/// Flame Infusion - 155653
}
