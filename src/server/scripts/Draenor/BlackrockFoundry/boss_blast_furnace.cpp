#include "boss_blast_furnace.h"

/// Heart of the Mountain - 76806
class boss_heart_of_the_mountain : public CreatureScript
{
    public:
        boss_heart_of_the_mountain() : CreatureScript("boss_heart_of_the_mountain") { }

        enum eTalks
        {
            Phase3Freedom,
            HeatLevelRising,
            WarnBlast,
            TalkMelt,
            Slay,
            Wipe,
            Death,
            BlastWarning,
            BombWarning,
            VolatileFireWarning,
            MeltWarning
        };

        enum eSpells
        {
            /// Misc
            HeartOfTheFurnace   = 155288,
            BlastFurnaceBonus   = 177531,
            BustLoose           = 160823,
            BustLooseSecond     = 160833,
            BlastWaveCosmetic   = 177388,
            Containment         = 155265,
            ContainedDNT        = 177434,
            MeltDoT             = 155223,
            /// Encounter
            Blast               = 155209,
            SlagPoolAreatrigger = 155738,
            Tempered            = 155240,
            Heat                = 155242,
            Melt                = 155225
        };

        enum eEvents
        {
            EventBerserker = 1,
            EventWarnBlast,
            EventBlast,
            EventSlagElemental,
            EventFirecaller,
            EventSpawnSecurityGuard,
            EventHeat,
            EventMelt
        };

        enum eCosmeticEvents
        {
            EventFurnaceEngineer = 1,
            EventSecurityGuard,
            EventBellowsOperator
        };

        enum eActions
        {
            ActionPhase2                = 1,
            ActionBlastIncreased        = 2,
            ActionFreeFury              = 2,
            ActionElementalistKilled    = 3,
            ActionSwitchToPhase2        = 3,
            ActionFuryDead              = 4,
            ActionBellowsOperators      = 3
        };

        enum eVisuals
        {
            OneShotBattleRoar   = 53,
            EmoteContained      = 64
        };

        enum eCreatures
        {
            PrimalElementalist      = 76815,
            Firecaller              = 76821,
            SlagElemental           = 78463,
            BellowsOperator         = 76811,
            CosmBellowsOperator     = 88821,
            /// During fight
            FurnaceEngineerFight    = 76810,
            BellowsOperatorFight    = 76811,
            SecurityGuardFight      = 76812
        };

        enum eDatas
        {
            ElementalistMoveIndex,
            ElementalistKilled
        };

        struct boss_heart_of_the_mountainAI : public BossAI
        {
            boss_heart_of_the_mountainAI(Creature* p_Creature) : BossAI(p_Creature, eFoundryDatas::DataBlastFurnace)
            {
                m_Instance = p_Creature->GetInstanceScript();
            }

            InstanceScript* m_Instance;

            EventMap m_Events;
            EventMap m_CosmeticEvents;

            bool m_Enabled;
            bool m_FightStarted;

            uint8 m_ElementalistMoveIndex;
            uint8 m_ElementalistKilled;

            void Reset() override
            {
                m_Events.Reset();
                m_CosmeticEvents.Reset();

                _Reset();

                me->RemoveAllAreaTriggers();

                me->RemoveAura(eSpells::HeartOfTheFurnace);
                me->RemoveAura(eFoundrySpells::Berserker);
                me->RemoveAura(eSpells::ContainedDNT);

//                me->SetUInt32Value(UnitFields::UNIT_NPC_EMOTESTATE, 0);

                me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
               // me->SetFlag(UnitFields::UNIT_FIELD_FLAGS_2, UnitFlags2::UNIT_FLAG2_DISABLED);

                me->SetPower(Powers::POWER_ALTERNATE_POWER, 0);

                me->SetReactState(ReactStates::REACT_PASSIVE);
                me->AddUnitState(UnitState::UNIT_STATE_STUNNED);

                m_Enabled = false;
                m_FightStarted = false;

                m_ElementalistMoveIndex = 0;
                m_ElementalistKilled = 0;

                if (m_Instance != nullptr)
                {
                    if (GameObject* l_Gate = ObjectAccessor::GetGameObject(*me, m_Instance->GetGuidData(eFoundryGameObjects::FurnaceGate)))
                    {
                        l_Gate->SetGoState(GOState::GO_STATE_READY);
                        l_Gate->RemoveFlag(GO_FLAG_IN_USE);
                    }

                    if (Creature* l_Foreman = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::ForemanFeldspar)))
                    {
                        if (l_Foreman->IsAIEnabled && !l_Foreman->IsAlive())
                        {
                            l_Foreman->Respawn();
                            l_Foreman->AI()->EnterEvadeMode();
                        }
                    }
                }
            }

            void KilledUnit(Unit* p_Who) override
            {
                if (p_Who->GetTypeId() != TYPEID_PLAYER)
                    return;

                Talk(eTalks::Slay);
            }

            void EnterCombat(Unit* p_Attacker) override
            {
                if (m_FightStarted)
                    return;

                m_Events.Reset();
                m_CosmeticEvents.Reset();

                m_FightStarted = true;

                _EnterCombat();

                if (m_Instance != nullptr)
                {
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me, 1);

                    StartEncounter(me, p_Attacker, m_Instance);
                }

                me->CastSpell(me, eSpells::HeartOfTheFurnace, true);

                m_Events.ScheduleEvent(eEvents::EventBerserker, 780 * TimeConstants::IN_MILLISECONDS);
                m_Events.ScheduleEvent(eEvents::EventWarnBlast, GetBlastTimer() - 3 * TimeConstants::IN_MILLISECONDS);
                m_Events.ScheduleEvent(eEvents::EventBlast, GetBlastTimer());

                m_CosmeticEvents.ScheduleEvent(eCosmeticEvents::EventFurnaceEngineer, GetSummoningTimer());
                m_CosmeticEvents.ScheduleEvent(eCosmeticEvents::EventSecurityGuard, GetSummoningTimer());
                m_CosmeticEvents.ScheduleEvent(eCosmeticEvents::EventBellowsOperator, GetSummoningTimer());
            }

            void JustReachedHome() override
            {
                if (m_Enabled)
                    Talk(eTalks::Wipe);

                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER)
            {
                summons.DespawnAll();

                m_Events.Reset();
                m_CosmeticEvents.Reset();

               // me->ClearAllUnitState();

                CreatureAI::EnterEvadeMode();

                if (m_Instance != nullptr)
                {
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me, 1);

                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::Heat);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::Tempered);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::MeltDoT);

                    ResetEncounter(me, m_Instance);
                }

                me->StopMoving();

               // me->ClearAllUnitState();

                me->NearTeleportTo(me->GetHomePosition());

                JustReachedHome();
            }

            void JustDied(Unit* /*p_Killer*/) override
            {
                me->RemoveAllAreaTriggers();

                summons.DespawnAll();

                Talk(eTalks::Death);

                _JustDied();

                if (m_Instance != nullptr)
                {
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::Heat);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::Tempered);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::MeltDoT);

                    /// Allow loots and bonus loots to be enabled/disabled with a simple reload
                   // if (sObjectMgr->IsDisabledEncounter(m_Instance->GetEncounterIDForBoss(me), GetDifficulty()))
                      //  me->SetLootRecipient(nullptr);
                    //else
                        CastSpellToPlayers(me->GetMap(), me, eSpells::BlastFurnaceBonus, true);

                    if (Creature* l_Blackhand = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::BlackhandCosmetic)))
                    {
                        if (l_Blackhand->IsAIEnabled)
                            l_Blackhand->AI()->DoAction(eActions::ActionFuryDead);
                    }
                }
            }

            void OnSpellCasted(SpellInfo const* p_SpellInfo)
            {
                switch (p_SpellInfo->Id)
                {
                    case eSpells::BustLoose:
                    {
                       // AddTimedDelayedOperation(500, [this]() -> void
                      //  {
                           // Position const l_TeleportPos = { 197.707f, 3529.08f, 217.234f, me->GetOrientation() };

                            me->CastSpell(197.707f, 3529.08f, 217.234f, eSpells::BustLooseSecond, true);
                      //  });

                       // AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                       // {
                            Position const l_TeleportPos = { 197.9002f, 3530.093f, 218.234f, me->GetOrientation() };

                            me->NearTeleportTo(l_TeleportPos);

                            if (m_Instance != nullptr)
                            {
                                if (GameObject* l_Gate = ObjectAccessor::GetGameObject(*me, m_Instance->GetGuidData(eFoundryGameObjects::FurnaceGate)))
                                {
                                    l_Gate->SetGoState(GOState::GO_STATE_ACTIVE);
                                    l_Gate->AddFlag(GO_FLAG_IN_USE);
                                }
                            }
                       // });

                      //  AddTimedDelayedOperation(6 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                      //  {
                            me->RemoveAura(eSpells::BustLoose);
                            //me->SetAnimTier(0);
                            me->SetDisableGravity(false);
                            me->SendSetPlayHoverAnim(false);
                            me->HandleEmoteCommand(eVisuals::OneShotBattleRoar);

                            for (uint8 l_I = 0; l_I < eFoundryDatas::MaxPrimalElementalists; ++l_I)
                                me->SummonCreature(eCreatures::PrimalElementalist, g_PrimalElementalistsSpawns[l_I]);

                            me->CastSpell( 197.9002f, 3530.093f, 218.234f, eSpells::SlagPoolAreatrigger, true);
                       // });

                        break;
                    }
                    default:
                        break;
                }
            }

            void SpellHit(Unit* p_Attacker, SpellInfo const* p_SpellInfo) override
            {
                if (p_SpellInfo->Id == eSpells::Containment && !me->HasAura(eSpells::ContainedDNT))
                {
                    /// Primal Elementalist
                    if (p_Attacker != nullptr)
                        p_Attacker->CastSpell(me, eSpells::ContainedDNT, true);

                 //   me->SetUInt32Value(UnitFields::UNIT_NPC_EMOTESTATE, eVisuals::EmoteContained);
                }
            }

            void SpellHitTarget(Unit* p_Target, SpellInfo const* p_SpellInfo) override
            {
                if (p_Target == nullptr)
                    return;

                if (p_SpellInfo->Id == eSpells::Melt)
                    Talk(eTalks::MeltWarning);
            }

            void DoAction(int32 p_Action)
            {
                switch (p_Action)
                {
                    case eActions::ActionFreeFury:
                    {
                        me->CastSpell(me, eSpells::BustLoose, false);

                       // if (!IsLFR())
                            m_Events.ScheduleEvent(eEvents::EventSlagElemental, 13 * TimeConstants::IN_MILLISECONDS);

                        m_Events.ScheduleEvent(eEvents::EventFirecaller, 76 * TimeConstants::IN_MILLISECONDS);
                        m_Events.ScheduleEvent(eEvents::EventSpawnSecurityGuard, 71 * TimeConstants::IN_MILLISECONDS + 500);

                        /// Cancel first phase adds spawning events
                        m_CosmeticEvents.CancelEvent(eCosmeticEvents::EventBellowsOperator);
                        m_CosmeticEvents.CancelEvent(eCosmeticEvents::EventSecurityGuard);
                        m_CosmeticEvents.CancelEvent(eCosmeticEvents::EventFurnaceEngineer);

                        std::list<Creature*> l_OperatorList;
                        me->GetCreatureListWithEntryInGrid(l_OperatorList, eCreatures::BellowsOperator, 150.0f);
                        me->GetCreatureListWithEntryInGrid(l_OperatorList, eCreatures::CosmBellowsOperator, 150.0f);

                        for (Creature* l_Operator : l_OperatorList)
                        {
                            if (l_Operator->IsAIEnabled)
                                l_Operator->AI()->DoAction(eActions::ActionPhase2);
                        }

                        break;
                    }
                    default:
                        break;
                }
            }

            void SetPower(Powers p_Power, int32 p_Value)
            {
                if (p_Power != Powers::POWER_ALTERNATE_POWER || m_Instance == nullptr)
                    return;

                int32 l_OldPower = me->GetPower(p_Power);

                if ((l_OldPower < 75 && p_Value >= 75) ||
                    (l_OldPower < 50 && p_Value >= 50) ||
                    (l_OldPower < 25 && p_Value >= 25))
                {
                    if (Creature* l_Foreman = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::ForemanFeldspar)))
                    {
                        if (l_Foreman->IsAIEnabled)
                            l_Foreman->AI()->DoAction(eActions::ActionBlastIncreased);
                    }
                }
            }

            uint32 GetData(uint32 p_ID) const
            {
                switch (p_ID)
                {
                    case eDatas::ElementalistMoveIndex:
                        return (uint32)m_ElementalistMoveIndex;
                    case eDatas::ElementalistKilled:
                        return (uint32)m_ElementalistKilled;
                    default:
                        break;
                }

                return 0;
            }

            void SetData(uint32 p_ID, uint32 /*p_Value*/) override
            {
                switch (p_ID)
                {
                    case eDatas::ElementalistMoveIndex:
                    {
                        ++m_ElementalistMoveIndex;
                        break;
                    }
                    case eDatas::ElementalistKilled:
                    {
                        ++m_ElementalistKilled;

                        if (m_ElementalistKilled == eFoundryDatas::MaxPrimalElementalists)
                        {
                            me->RemoveAura(eSpells::ContainedDNT);
                        //    me->SetUInt32Value(UnitFields::UNIT_NPC_EMOTESTATE, 0);

                            m_Events.CancelEvent(eEvents::EventFirecaller);
                            m_Events.CancelEvent(eEvents::EventSpawnSecurityGuard);
                            m_Events.CancelEvent(eEvents::EventSlagElemental);

                           // AddTimedDelayedOperation(4 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                           // {
                                me->SetReactState(ReactStates::REACT_AGGRESSIVE);
                                me->ClearUnitState(UnitState::UNIT_STATE_STUNNED);

                                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
                               // me->RemoveFlag(UnitFields::UNIT_FIELD_FLAGS_2, UnitFlags2::UNIT_FLAG2_SELECTION_DISABLED);

                                Talk(eTalks::Phase3Freedom);

                                m_Events.ScheduleEvent(eEvents::EventHeat, 6 * TimeConstants::IN_MILLISECONDS);
                                m_Events.ScheduleEvent(eEvents::EventMelt, 11 * TimeConstants::IN_MILLISECONDS);
                            //});
                        }

                        if (m_Instance != nullptr)
                        {
                            if (Creature* l_Blackhand = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::BlackhandCosmetic)))
                            {
                                if (l_Blackhand->IsAIEnabled)
                                    l_Blackhand->AI()->DoAction(eActions::ActionElementalistKilled);
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
                m_CosmeticEvents.Update(p_Diff);

                switch (m_CosmeticEvents.ExecuteEvent())
                {
                    case eCosmeticEvents::EventFurnaceEngineer:
                    {
                        for (uint8 l_I = 0; l_I < 2; ++l_I)
                        {
                            if (Creature* l_Engineer = me->SummonCreature(eCreatures::FurnaceEngineerFight, g_EncounterAddSpawns[l_I][urand(0, 2)]))
                            {
                                ObjectGuid l_Guid = l_Engineer->GetGUID();
                              //  AddTimedDelayedOperation(50, [this, l_Guid]() -> void
                               // {
                                    if (Creature* l_Engineer = ObjectAccessor::GetCreature(*me, l_Guid))
                                    {
                                        float l_O = l_Engineer->GetAngle(me);
                                        float l_X = l_Engineer->GetPositionX() + 30.0f * cos(l_O);
                                        float l_Y = l_Engineer->GetPositionY() + 30.0f * sin(l_O);

                                        l_Engineer->GetMotionMaster()->MoveJump(l_X, l_Y, me->GetPositionZ() + 9.0f, 10.0f, 30.0f,0.f);
                                    }
                              //  });
                            }
                        }

                        m_CosmeticEvents.ScheduleEvent(eCosmeticEvents::EventFurnaceEngineer, GetSummoningTimer());
                        break;
                    }
                    case eCosmeticEvents::EventSecurityGuard:
                    {
                        for (uint8 l_I = 0; l_I < 2; ++l_I)
                        {
                            if (Creature* l_Guard = me->SummonCreature(eCreatures::SecurityGuardFight, g_EncounterAddSpawns[l_I][urand(0, 2)]))
                            {
                                ObjectGuid l_Guid = l_Guard->GetGUID();
                               // AddTimedDelayedOperation(50, [this, l_Guid]() -> void
                               // {
                                    if (Creature* l_Guard = ObjectAccessor::GetCreature(*me, l_Guid))
                                    {
                                        float l_O = l_Guard->GetAngle(me);
                                        float l_X = l_Guard->GetPositionX() + 30.0f * cos(l_O);
                                        float l_Y = l_Guard->GetPositionY() + 30.0f * sin(l_O);

                                        l_Guard->GetMotionMaster()->MoveJump(l_X, l_Y, me->GetPositionZ() + 9.0f, 10.0f, 30.0f,0.f);
                                    }
                              //  });
                            }
                        }

                        m_CosmeticEvents.ScheduleEvent(eCosmeticEvents::EventSecurityGuard, GetSummoningTimer());
                        break;
                    }
                    case eCosmeticEvents::EventBellowsOperator:
                    {
                        if (m_Instance != nullptr)
                        {
                            if (Creature* l_Foreman = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::ForemanFeldspar)))
                            {
                                if (l_Foreman->IsAIEnabled)
                                    l_Foreman->AI()->DoAction(eActions::ActionBellowsOperators);
                            }
                        }

                        for (uint8 l_I = 0; l_I < 2; ++l_I)
                        {
                            if (Creature* l_Operator = me->SummonCreature(eCreatures::BellowsOperatorFight, g_BellowsOperatorSpawns[l_I]))
                            {
                                ObjectGuid l_Guid = l_Operator->GetGUID();
                              //  AddTimedDelayedOperation(50, [this, l_Guid]() -> void
                               // {
                                    if (Creature* l_Operator = ObjectAccessor::GetCreature(*me, l_Guid))
                                    {
                                        float l_O = l_Operator->GetAngle(me);
                                        float l_X = l_Operator->GetPositionX() + 12.0f * cos(l_O);
                                        float l_Y = l_Operator->GetPositionY() + 12.0f * sin(l_O);

                                        l_Operator->GetMotionMaster()->MoveJump(l_X, l_Y, me->GetPositionZ() + 9.0f, 10.0f, 30.0f, l_O, 1);
                                    }
                                //});
                            }
                        }

                        m_CosmeticEvents.ScheduleEvent(eCosmeticEvents::EventBellowsOperator, GetSummoningTimer());
                        break;
                    }
                    default:
                        break;
                }

              //  UpdateOperations(p_Diff);

                if (!UpdateVictim() || (m_Instance != nullptr/* && m_Instance->IsWipe()*/))
                    return;

                m_Events.Update(p_Diff);

                if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                    return;

                switch (m_Events.ExecuteEvent())
                {
                    case eEvents::EventBerserker:
                    {
                        me->CastSpell(me, eFoundrySpells::Berserker, true);
                        break;
                    }
                    case eEvents::EventWarnBlast:
                    {
                        Talk(eTalks::BlastWarning);
                        m_Events.ScheduleEvent(eEvents::EventWarnBlast, GetBlastTimer());
                        break;
                    }
                    case eEvents::EventBlast:
                    {
                        if (me->HasReactState(ReactStates::REACT_AGGRESSIVE) && urand(0, 1))
                            Talk(eTalks::WarnBlast);

                        me->CastSpell(me, eSpells::Blast, true);
                        m_Events.ScheduleEvent(eEvents::EventBlast, GetBlastTimer());
                        break;
                    }
                    case eEvents::EventSlagElemental:
                    {
                        if (m_Instance != nullptr)
                        {
                            if (Creature* l_Fury = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::HeartOfTheMountain)))
                            {
                                if (Creature* l_Elemental = me->SummonCreature(eCreatures::SlagElemental, g_EncounterAddSpawns[urand(0, 1)][urand(0, 2)]))
                                {
                                    ObjectGuid l_Guid = l_Elemental->GetGUID();
                                    //AddTimedDelayedOperation(50, [this, l_Guid]() -> void
                                   // {
                                        if (Creature* l_Elemental = ObjectAccessor::GetCreature(*me, l_Guid))
                                        {
                                            float l_O = l_Elemental->GetAngle(me);
                                            float l_X = l_Elemental->GetPositionX() + 30.0f * cos(l_O);
                                            float l_Y = l_Elemental->GetPositionY() + 30.0f * sin(l_O);
    
                                            l_Elemental->GetMotionMaster()->MoveJump(l_X, l_Y, me->GetPositionZ(), 10.0f, 30.0f,0.f);
                                        }
                                  //  });
                                }
                            }
                        }

                        m_Events.ScheduleEvent(eEvents::EventSlagElemental, 55 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case eEvents::EventFirecaller:
                    {
                        if (m_Instance != nullptr)
                        {
                            if (Creature* l_Fury = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::HeartOfTheMountain)))
                            {
                                for (uint8 l_I = 0; l_I < 2; ++l_I)
                                {
                                    if (Creature* l_Firecaller = me->SummonCreature(eCreatures::Firecaller, g_EncounterAddSpawns[l_I][urand(0, 2)]))
                                    {
                                        ObjectGuid l_Guid = l_Firecaller->GetGUID();
                                       // AddTimedDelayedOperation(50, [this, l_Guid]() -> void
                                      //  {
                                            if (Creature* l_Firecaller = ObjectAccessor::GetCreature(*me, l_Guid))
                                            {
                                                float l_O = l_Firecaller->GetAngle(me);
                                                float l_X = l_Firecaller->GetPositionX() + 30.0f * cos(l_O);
                                                float l_Y = l_Firecaller->GetPositionY() + 30.0f * sin(l_O);
        
                                                l_Firecaller->GetMotionMaster()->MoveJump(l_X, l_Y, me->GetPositionZ(), 10.0f, 30.0f,0.f);
                                            }
                                      //  });
                                    }
                                }
                            }
                        }

                        m_Events.ScheduleEvent(eEvents::EventFirecaller, 45 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case eEvents::EventSpawnSecurityGuard:
                    {
                        if (m_Instance != nullptr)
                        {
                            if (Creature* l_Fury = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::HeartOfTheMountain)))
                            {
                                if (Creature* l_Guard = me->SummonCreature(eCreatures::SecurityGuardFight, g_SecurityGuardSecondPhaseSpwan))
                                {
                                    ObjectGuid l_Guid = l_Guard->GetGUID();
                                   // AddTimedDelayedOperation(50, [this, l_Guid]() -> void
                                   // {
                                        if (Creature* l_Guard = ObjectAccessor::GetCreature(*me, l_Guid))
                                            l_Guard->GetMotionMaster()->MoveJump(g_SecurityGuardSecondPhaseJump, 10.0f, 30.0f);
                                   // });
                                }
                            }
                        }

                        m_Events.ScheduleEvent(eEvents::EventSpawnSecurityGuard, 40 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case eEvents::EventHeat:
                    {
                        if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO))
                        {
                            /// Tempered will increase its efficacy when Heat is initially applied to you.
                            if (!l_Target->HasAura(eSpells::Heat))
                                me->CastSpell(l_Target, eSpells::Tempered, true);

                            me->CastSpell(l_Target, eSpells::Heat, true);

                            /// Tempered will increase its efficacy when exposed to greater Heat levels than your current Tempered level.
                            if (Aura* l_Heat = l_Target->GetAura(eSpells::Heat))
                            {
                                if (Aura* l_Tempered = l_Target->GetAura(eSpells::Tempered))
                                {
                                    if (l_Heat->GetStackAmount() > l_Tempered->GetStackAmount())
                                        me->CastSpell(l_Target, eSpells::Tempered, true);
                                }
                            }
                        }

                        Talk(eTalks::HeatLevelRising);

                        m_Events.ScheduleEvent(eEvents::EventHeat, 11 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case eEvents::EventMelt:
                    {
                        Talk(eTalks::TalkMelt);
                        me->CastSpell(me, eSpells::Melt, true);
                        m_Events.ScheduleEvent(eEvents::EventMelt, 10 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }

            uint32 GetBlastTimer() const
            {
                /// The time until the next cast of Blast is indicated by The Heart of the Mountain's Energy bar, with Blast being cast whenever it reaches maximum Energy.
                /// In addition to this, The Heart of the Mountain also has a Heat resource, which determines exactly how quickly its Energy regenerates.
                /// The longer The Heart of the Mountain spends inside the Blast Furnace (in other words, the longer your raid spends in Phase One), the higher its Heat will be.
                uint32 l_Time = 0;
                int32 l_Power = me->GetPower(Powers::POWER_ALTERNATE_POWER);

                if (l_Power >= 100)
                    l_Time = 10 * TimeConstants::IN_MILLISECONDS;
                else if (l_Power >= 75)
                    l_Time = 12 * TimeConstants::IN_MILLISECONDS;
                else if (l_Power >= 50)
                    l_Time = 15* TimeConstants::IN_MILLISECONDS;
                else if (l_Power >= 25)
                    l_Time = 20 * TimeConstants::IN_MILLISECONDS;
                else
                    l_Time = 30 * TimeConstants::IN_MILLISECONDS;

                if (AuraEffect* l_BlastAura = me->GetAuraEffect(eSpells::HeartOfTheFurnace, SpellEffIndex::EFFECT_0))
                    l_BlastAura->ChangeAmount(int32(l_Time / TimeConstants::IN_MILLISECONDS));

                return l_Time;
            }

            uint32 GetSummoningTimer() const
            {
                uint32 l_Timer = 0;

                //if (IsLFR())
                    l_Timer = 65 * TimeConstants::IN_MILLISECONDS;
              /*  else*/ if (IsHeroic())
                    l_Timer = 55 * TimeConstants::IN_MILLISECONDS;
               // else if (IsMythic())
                 //   l_Timer = 40 * TimeConstants::IN_MILLISECONDS;
                else
                    l_Timer = 60 * TimeConstants::IN_MILLISECONDS;

                return l_Timer;
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new boss_heart_of_the_mountainAI(p_Creature);
        }
};

/// Foreman Feldspar - 76809
class boss_foreman_feldspar : public CreatureScript
{
    public:
        boss_foreman_feldspar() : CreatureScript("boss_foreman_feldspar") { }

        enum eTalks
        {
            Aggro,
            BellowsOperators,
            FirstHeatDestroyed,
            Ability,
            Slay,
            Wipe,
            Death,
            BlastIncreased,
            RuptureWarning
        };

        enum eCreatures
        {
            /// Before fight
            SecurityGuard   = 88818,
            FurnaceEngineer = 88820,
            BellowsOperator = 88821,
            HeatRegulator   = 76808
        };

        enum eActions
        {
            ActionActivateBellows,
            ActionRegulatorDestroyed,
            ActionBlastIncreased,
            ActionBellowsOperators
        };

        enum eEvents
        {
            EventBerserker = 1,
            EventPyroclasm,
            EventRupture
        };

        enum eSpells
        {
            /// Misc
            Bomb            = 155192,
            BombOverrider   = 174716,
            /// Fight
            Pyroclasm       = 156937,
            Rupture         = 156934,
            RuptureDoT      = 156932,
            HotBlooded      = 158247
        };

        struct boss_foreman_feldsparAI : public BossAI
        {
            boss_foreman_feldsparAI(Creature* p_Creature) : BossAI(p_Creature, eFoundryDatas::DataForemanFeldspar)
            {
                m_Instance      = p_Creature->GetInstanceScript();
                m_InEvadeMode   = false;
            }

            InstanceScript* m_Instance;

            EventMap m_Events;

            std::vector<ObjectGuid> m_GuardiansGuids;

            bool m_FightStarted;

            bool m_RegulatorDestroyed;
            bool m_InEvadeMode;

            void Reset() override
            {
                m_Events.Reset();

                _Reset();

                me->RemoveAllAreaTriggers();

                me->RemoveAura(eFoundrySpells::Berserker);
                me->RemoveAura(eSpells::HotBlooded);

                m_RegulatorDestroyed = false;

                if (m_Instance != nullptr)
                {
                    if (Creature* l_Blackhand = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::BlackhandCosmetic)))
                    {
                        if (l_Blackhand->IsAIEnabled)
                            l_Blackhand->AI()->Reset();
                    }
                }

                if (m_GuardiansGuids.empty())
                {
                   // AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                   // {
                        std::list<Creature*> l_CreatureList;

                        uint32 const l_Entries[4] = { eCreatures::SecurityGuard, eCreatures::FurnaceEngineer, eCreatures::BellowsOperator, eCreatures::HeatRegulator };

                        for (uint8 l_I = 0; l_I < 4; ++l_I)
                        {
                            l_CreatureList.clear();

                            me->GetCreatureListWithEntryInGrid(l_CreatureList, l_Entries[l_I], 150.0f);

                            for (Creature* l_Iter : l_CreatureList)
                                m_GuardiansGuids.push_back(l_Iter->GetGUID());
                        }
                   // });
                }

                m_FightStarted = false;
            }

            void KilledUnit(Unit* p_Who) override
            {
                if (p_Who->GetTypeId() != TYPEID_PLAYER)
                    return;

                Talk(eTalks::Slay);
            }

            void EnterCombat(Unit* p_Attacker) override
            {
                if (m_FightStarted)
                    return;

                m_FightStarted = true;

                me->CastSpell(me, eSpells::HotBlooded, true);

                Talk(eTalks::Aggro);

                std::list<Creature*> l_BellowsOperators;
                me->GetCreatureListWithEntryInGrid(l_BellowsOperators, eCreatures::BellowsOperator, 150.0f);

                for (Creature* l_Operator : l_BellowsOperators)
                {
                    if (l_Operator->IsAIEnabled)
                        l_Operator->AI()->DoAction(eActions::ActionActivateBellows);
                }

                if (m_Instance != nullptr)
                {
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me, 2);

                    CallAddsInCombat(p_Attacker);

                    StartEncounter(me, p_Attacker, m_Instance);
                }

                m_Events.ScheduleEvent(eEvents::EventBerserker, 780 * TimeConstants::IN_MILLISECONDS);
                m_Events.ScheduleEvent(eEvents::EventPyroclasm, 18 * TimeConstants::IN_MILLISECONDS);
                m_Events.ScheduleEvent(eEvents::EventRupture, 26 * TimeConstants::IN_MILLISECONDS);
            }

            void JustDied(Unit* /*p_Killer*/) override
            {
                Talk(eTalks::Death);

                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER)
            {
                if (m_InEvadeMode)
                    return;

                m_InEvadeMode = true;

               // AddTimedDelayedOperation(50, [this]() -> void
               // {
                    me->StopMoving();
                    me->GetMotionMaster()->Clear();
               // });

               // AddTimedDelayedOperation(150, [this]() -> void
              //  {
                    CreatureAI::EnterEvadeMode();

                    if (m_Instance != nullptr)
                        ResetEncounter(me, m_Instance);

                    m_InEvadeMode = false;
               // });
            }

            void JustReachedHome() override
            {
                m_InEvadeMode = false;

                Talk(eTalks::Wipe);

                if (m_Instance != nullptr)
                {
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::RuptureDoT);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::Bomb);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::BombOverrider);
                }

                summons.DespawnAll();

                ResetFirstAdds();
            }

            void DoAction(int32 p_Action) override
            {
                switch (p_Action)
                {
                    case eActions::ActionRegulatorDestroyed:
                    {
                        if (!m_RegulatorDestroyed)
                        {
                            Talk(eTalks::FirstHeatDestroyed);
                            m_RegulatorDestroyed = true;
                        }

                        break;
                    }
                    case eActions::ActionBlastIncreased:
                    {
                        Talk(eTalks::BlastIncreased);
                        break;
                    }
                    case eActions::ActionBellowsOperators:
                    {
                        Talk(eTalks::BellowsOperators);
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
                    case eSpells::Rupture:
                    {
                        Talk(eTalks::RuptureWarning/*, p_Target->GetGUID(), TextRange::TEXT_RANGE_NORMAL*/);
                        break;
                    }
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 p_Diff) override
            {
               // UpdateOperations(p_Diff);

                if (!UpdateVictim() || (m_Instance != nullptr/* && m_Instance->IsWipe()*/))
                    return;

                m_Events.Update(p_Diff);

                if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                    return;

                switch (m_Events.ExecuteEvent())
                {
                    case eEvents::EventBerserker:
                    {
                        me->CastSpell(me, eFoundrySpells::Berserker, true);
                        break;
                    }
                    case eEvents::EventPyroclasm:
                    {
                        Talk(eTalks::Ability);
                        me->CastSpell(me, eSpells::Pyroclasm, false);
                        m_Events.ScheduleEvent(eEvents::EventPyroclasm, 20 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case eEvents::EventRupture:
                    {
                        me->CastSpell(me, eSpells::Rupture, false);
                        m_Events.ScheduleEvent(eEvents::EventRupture, 25 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }

            void ResetFirstAdds()
            {
                for (ObjectGuid l_Guid : m_GuardiansGuids)
                {
                    if (Creature* l_Iter = ObjectAccessor::GetCreature(*me, l_Guid))
                    {
                        if (l_Iter->isDead())
                        {
                            l_Iter->DespawnOrUnsummon();
                            l_Iter->Respawn();

                            ObjectGuid l_Guid = l_Iter->GetGUID();
                           // AddTimedDelayedOperation(100, [this, l_Guid]() -> void
                          //  {
                                if (Creature* l_Creature = ObjectAccessor::GetCreature(*me, l_Guid))
                                    l_Creature->GetMotionMaster()->MoveTargetedHome();
                           // });
                        }
                        else if (l_Iter->IsAIEnabled)
                            l_Iter->AI()->EnterEvadeMode();
                    }
                }
            }

            void CallAddsInCombat(Unit* p_Attacker)
            {
                for (ObjectGuid l_Guid : m_GuardiansGuids)
                {
                    if (Creature* l_Iter = ObjectAccessor::GetCreature(*me, l_Guid))
                    {
                        if (l_Iter->IsAIEnabled && !l_Iter->IsInCombat())
                        {
                            if (l_Iter->GetEntry() != eCreatures::BellowsOperator && l_Iter->GetEntry() != eCreatures::HeatRegulator)
                                l_Iter->AI()->AttackStart(p_Attacker);
                            else
                                l_Iter->SetInCombatWithZone();
                        }
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new boss_foreman_feldsparAI(p_Creature);
        }
};

/// Blackhand (Cosmetic) - 76831
class npc_foundry_blackhand_cosmetic : public CreatureScript
{
    public:
        npc_foundry_blackhand_cosmetic() : CreatureScript("npc_foundry_blackhand_cosmetic") { }

        enum eTalks
        {
            Intro,
            FirstHeatDestroyedBefore,
            FirstHeatDestroyedAfter,
            HeartExposedBefore,
            HeartExposedAfter,
            Phase2,
            ThreeElementalists,
            TwoElementalists,
            OneElementalist,
            Phase3Freedom1,
            Phase3Freedom2,
            HeartDeath,
            KromogKilled,
            MaidensKilled
        };

        enum eActions
        {
            ActionIntro,
            ActionRegulatorDestroyed,
            ActionFreeFury,
            ActionElementalistKilled,
            ActionFuryDead
        };

        struct npc_foundry_blackhand_cosmeticAI : public ScriptedAI
        {
            npc_foundry_blackhand_cosmeticAI(Creature* p_Creature) : ScriptedAI(p_Creature)
            {
                m_Instance = p_Creature->GetInstanceScript();
            }

            InstanceScript* m_Instance;

            bool m_FirstHeatDestroyed;

            uint8 m_ElementalistKilled;

            void Reset() override
            {
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_NPC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE));

                m_FirstHeatDestroyed = false;

                m_ElementalistKilled = 0;
            }

            void DoAction(int32 p_Action)
            {
                switch (p_Action)
                {
                    case eActions::ActionIntro:
                    {
                        Talk(eTalks::Intro);
                        break;
                    }
                    case eActions::ActionRegulatorDestroyed:
                    {
                        if (!m_FirstHeatDestroyed)
                        {
                            m_FirstHeatDestroyed = true;

                            Talk(eTalks::FirstHeatDestroyedBefore);

                            //AddTimedDelayedOperation(6 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                           // {
                                Talk(eTalks::FirstHeatDestroyedAfter);
                           // });
                        }
                        else
                        {
                            if (m_Instance != nullptr)
                            {
                                if (Creature* l_Fury = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::HeartOfTheMountain)))
                                {
                                    if (l_Fury->IsAIEnabled)
                                        l_Fury->AI()->DoAction(eActions::ActionFreeFury);
                                }
                            }

                            Talk(eTalks::HeartExposedBefore);
                            Talk(eTalks::HeartExposedAfter);
                        }

                        break;
                    }
                    case eActions::ActionElementalistKilled:
                    {
                        ++m_ElementalistKilled;
                        Talk(eTalks::Phase2 + m_ElementalistKilled);

                        if (m_ElementalistKilled == eFoundryDatas::MaxPrimalElementalists)
                        {
                           // AddTimedDelayedOperation(11 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                           // {
                                Talk(eTalks::Phase3Freedom2);
                           // });
                        }

                        break;
                    }
                    case eActions::ActionFuryDead:
                    {
                       // AddTimedDelayedOperation(5 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                       // {
                            Talk(eTalks::HeartDeath);
                       // });

                        break;
                    }
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 p_Diff) override
            {
              //  UpdateOperations(p_Diff);
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_blackhand_cosmeticAI(p_Creature);
        }
};

/// Primal Elementalist - 76815
class npc_foundry_primal_elementalist : public CreatureScript
{
    public:
        npc_foundry_primal_elementalist() : CreatureScript("npc_foundry_primal_elementalist") { }

        enum eTalks
        {
            HeartExposed1,
            HeartExposed2,
            HeartExposed3,
            Phase3Freedom
        };

        enum eMoves
        {
            MoveFirst = 1,
            MoveJump
        };

        enum eDatas
        {
            ElementalistMoveIndex,
            ElementalistKilled
        };

        enum eSpells
        {
            /// Cosmetic
            Containment         = 155265,
            DamageShield        = 155176,
            ShieldsDown         = 158345,
            ReactiveEarthShield = 155173
        };

        enum eEvent
        {
            EventReactiveEerthShield = 1
        };

        struct npc_foundry_primal_elementalistAI : public ScriptedAI
        {
            npc_foundry_primal_elementalistAI(Creature* p_Creature) : ScriptedAI(p_Creature), m_CanTalk(false)
            {
                m_Instance = p_Creature->GetInstanceScript();
            }

            InstanceScript* m_Instance;

            EventMap m_Events;

            bool m_CanTalk;

            void Reset() override
            {
                me->AddUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));

                me->SetReactState(ReactStates::REACT_PASSIVE);

               // AddTimedDelayedOperation(100, [this]() -> void
               // {
                    Position const l_MovePos = { 199.236f, 3467.01f, 266.733f, me->GetOrientation() };

                    me->GetMotionMaster()->MovePoint(eMoves::MoveFirst, l_MovePos);
               // });

                //if (!IsLFR())
                    me->CastSpell(me, eSpells::DamageShield, true);

                m_Events.Reset();
            }

            void EnterCombat(Unit* /*p_Attacker*/) override
            {
                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me, 3);
            }

            void JustDied(Unit* /*p_Killer*/) override
            {
                if (m_Instance != nullptr)
                {
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                    m_Instance->SetData(eFoundryDatas::PrimalElementalistTime, (uint32)time(nullptr));

                    if (Creature* l_Fury = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::HeartOfTheMountain)))
                    {
                        if (l_Fury->IsAIEnabled)
                        {
                            l_Fury->AI()->SetData(eDatas::ElementalistKilled, 0);

                            uint32 l_Count = l_Fury->AI()->GetData(eDatas::ElementalistKilled);
                            if (l_Count == eFoundryDatas::MaxPrimalElementalists)
                                Talk(eTalks::Phase3Freedom);
                        }
                    }
                }
            }

            void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER)
            {
                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void MovementInform(uint32 p_Type, uint32 p_ID) override
            {
                if (p_Type != MovementGeneratorType::POINT_MOTION_TYPE && p_Type != MovementGeneratorType::EFFECT_MOTION_TYPE)
                    return;

                switch (p_ID)
                {
                    case eMoves::MoveFirst:
                    {
                        if (m_Instance != nullptr)
                        {
                            if (Creature* l_Fury = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::HeartOfTheMountain)))
                            {
                                uint8 l_MoveI = 0;

                                if (l_Fury->IsAIEnabled)
                                {
                                    l_MoveI = l_Fury->AI()->GetData(eDatas::ElementalistMoveIndex);
                                    l_Fury->AI()->SetData(eDatas::ElementalistMoveIndex, 0);

                                    if (l_MoveI == (eFoundryDatas::MaxPrimalElementalists - 1))
                                        m_CanTalk = true;
                                }

                               // AddTimedDelayedOperation(100, [this, l_MoveI]() -> void
                               // {
                                    me->GetMotionMaster()->MoveJump(g_PrimalElementalistsMoves[l_MoveI], 20.0f, 19.2911f, eMoves::MoveJump);
                               // });
                            }
                        }

                        break;
                    }
                    case eMoves::MoveJump:
                    {
                        //AddTimedDelayedOperation(100, [this]() -> void
                       // {
                            if (m_Instance != nullptr)
                            {
                                if (Creature* l_Fury = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::HeartOfTheMountain)))
                                    me->SetFacingTo(me->GetAngle(l_Fury));
                            }
                        //});

                       // AddTimedDelayedOperation(200, [this]() -> void
                       // {
                            me->CastSpell(me, eSpells::Containment, false);

                            if (m_CanTalk)
                                Talk(eTalks::HeartExposed1);
                      //  });

                        if (m_CanTalk)
                        {
                           // AddTimedDelayedOperation(6 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                         //   {
                                Talk(eTalks::HeartExposed2);
                         //   });

                           // AddTimedDelayedOperation(8 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                           // {
                                Talk(eTalks::HeartExposed3);
                           // });
                        }

                        break;
                    }
                    default:
                        break;
                }
            }

            void OnSpellCasted(SpellInfo const* p_SpellInfo)
            {
                if (p_SpellInfo->Id == eSpells::ShieldsDown)
                    m_Events.ScheduleEvent(eEvent::EventReactiveEerthShield, urand(1 * TimeConstants::IN_MILLISECONDS, 15 * TimeConstants::IN_MILLISECONDS));
            }

            void UpdateAI(uint32 p_Diff) override
            {
               // UpdateOperations(p_Diff);

                m_Events.Update(p_Diff);

                switch (m_Events.ExecuteEvent())
                {
                    case eEvent::EventReactiveEerthShield:
                    {
                        me->CastSpell(me, eSpells::ReactiveEarthShield, true);
                        break;
                    }
                    default:
                        break;
                }
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_primal_elementalistAI(p_Creature);
        }
};

/// Bellows Operator - 88821
/// Bellows Operator (Fight) - 76811
class npc_foundry_bellows_operator : public CreatureScript
{
    public:
        npc_foundry_bellows_operator() : CreatureScript("npc_foundry_bellows_operator") { }

        enum eSpells
        {
            Loading         = 155181,
            DeafeningRoar   = 177756
        };

        enum eEvent
        {
            EventDeafeningRoar = 1
        };

        enum eActions
        {
            ActionActivateBellows,
            ActionPhase2
        };

        enum eCreatures
        {
            OperatorForFight    = 76811,
            Bellows             = 78477
        };

        struct npc_foundry_bellows_operatorAI : public ScriptedAI
        {
            npc_foundry_bellows_operatorAI(Creature* p_Creature) : ScriptedAI(p_Creature), m_SwitchStatePct(50) { }

            EventMap m_Events;

            int32 m_SwitchStatePct;

            void Reset() override
            {
                m_Events.Reset();

                me->RemoveAura(eSpells::Loading);

                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->ApplySpellImmune(0, SpellImmunity::IMMUNITY_EFFECT, SpellEffectName::SPELL_EFFECT_INTERRUPT_CAST, true);
                me->ApplySpellImmune(0, SpellImmunity::IMMUNITY_EFFECT, SpellEffectName::SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, SpellImmunity::IMMUNITY_EFFECT, SpellEffectName::SPELL_EFFECT_KNOCK_BACK_DEST, true);

                me->ApplySpellImmune(0, SpellImmunity::IMMUNITY_MECHANIC, Mechanics::MECHANIC_SILENCE, true);
                me->ApplySpellImmune(0, SpellImmunity::IMMUNITY_MECHANIC, Mechanics::MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, SpellImmunity::IMMUNITY_MECHANIC, Mechanics::MECHANIC_STUN, true);
                me->ApplySpellImmune(0, SpellImmunity::IMMUNITY_MECHANIC, Mechanics::MECHANIC_SLEEP, true);
                me->ApplySpellImmune(0, SpellImmunity::IMMUNITY_MECHANIC, Mechanics::MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, SpellImmunity::IMMUNITY_MECHANIC, Mechanics::MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, SpellImmunity::IMMUNITY_MECHANIC, Mechanics::MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, SpellImmunity::IMMUNITY_MECHANIC, Mechanics::MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, SpellImmunity::IMMUNITY_MECHANIC, Mechanics::MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, SpellImmunity::IMMUNITY_MECHANIC, Mechanics::MECHANIC_FREEZE, true);
            }

            void DoAction(int32 p_Action)
            {
                switch (p_Action)
                {
                    case eActions::ActionActivateBellows:
                    {
                        OnVehicleEntered(nullptr);
                        break;
                    }
                    case eActions::ActionPhase2:
                    {
                        me->ExitVehicle();

                        me->InterruptNonMeleeSpells(true);

                        me->RemoveAura(eSpells::Loading);
                        me->SetReactState(ReactStates::REACT_AGGRESSIVE);

                        if (Player* l_Target = me->SelectNearestPlayer(50.0f))
                            AttackStart(l_Target);

                        m_Events.ScheduleEvent(eEvent::EventDeafeningRoar, urand(5 * TimeConstants::IN_MILLISECONDS, 10 * TimeConstants::IN_MILLISECONDS));
                        break;
                    }
                    default:
                        break;
                }
            }

            void DamageTaken(Unit* p_Attacker, uint32& p_Damage) override
            {
                if (me->GetReactState() == ReactStates::REACT_AGGRESSIVE)
                    return;

                /// In Mythic Difficulty, the Bellows Operators will stop operating the bellows of the furnace and engage players in melee combat after reaching 50% health remaining.
                if (me->HealthBelowPctDamaged(m_SwitchStatePct, p_Damage))
                {
                    me->SetReactState(ReactStates::REACT_AGGRESSIVE);
                    AttackStart(p_Attacker);
                }
            }

            void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER)
            {
                me->RemoveAllAuras();

                me->InterruptNonMeleeSpells(true);

                /// Just in case, to prevent the fail Return to Home
                me->ClearUnitState(UnitState::UNIT_STATE_ROOT);
                me->ClearUnitState(UnitState::UNIT_STATE_DISTRACTED);
                me->ClearUnitState(UnitState::UNIT_STATE_STUNNED);

                CreatureAI::EnterEvadeMode();
            }

            void MovementInform(uint32 p_Type, uint32 p_ID) override
            {
                if (p_Type != MovementGeneratorType::EFFECT_MOTION_TYPE)
                    return;

                if (p_ID == 1)
                {
                    if (Creature* l_Bellows = me->FindNearestCreature(eCreatures::Bellows, 50.0f))
                        me->EnterVehicle(l_Bellows);
                }
            }

            void OnVehicleEntered(Unit* /*p_Vehicle*/) 
            {
                /// @WORKAROUND - Clear ON VEHICLE state to allow healing (Invalid target errors)
                /// Current rule for applying this state is questionable (seatFlags & VEHICLE_SEAT_FLAG_ALLOW_TURNING ???)
               // me->ClearUnitState(UnitState::UNIT_STATE_ONVEHICLE);

                /// @WORKAROUND - Clear ON VEHICLE state to allow healing (Invalid target errors)
                /// Current rule for applying this state is questionable (seatFlags & VEHICLE_SEAT_FLAG_ALLOW_TURNING ???)
               // me->ClearUnitState(UnitState::UNIT_STATE_ONVEHICLE);

              //  AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void
              //  {
                    me->CastSpell(me, eSpells::Loading, false);
                    me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
              //  });
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
                    case eEvent::EventDeafeningRoar:
                    {
                        me->CastSpell(me, eSpells::DeafeningRoar, false);
                        m_Events.ScheduleEvent(eEvent::EventDeafeningRoar, urand(15 * TimeConstants::IN_MILLISECONDS, 25 * TimeConstants::IN_MILLISECONDS));
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
            return new npc_foundry_bellows_operatorAI(p_Creature);
        }
};

/// Heat Regulator - 76808
class npc_foundry_heat_regulator : public CreatureScript
{
    public:
        npc_foundry_heat_regulator() : CreatureScript("npc_foundry_heat_regulator") { }

        enum eAction
        {
            RegulatorDestroyed = 1
        };

        enum eGameObjects
        {
            LeftHeatRegulator   = 237305,
            RightHeatRegulator  = 237304
        };

        struct npc_foundry_heat_regulatorAI : public ScriptedAI
        {
            npc_foundry_heat_regulatorAI(Creature* p_Creature) : ScriptedAI(p_Creature)
            {
                m_Instance = p_Creature->GetInstanceScript();
            }

            InstanceScript* m_Instance;

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->AddUnitState(UnitState::UNIT_STATE_STUNNED);
                me->AddUnitState(UnitState::UNIT_STATE_ROOT);

                GameObject* l_Regulator = me->FindNearestGameObject(eGameObjects::LeftHeatRegulator, 10.0f);
                if (l_Regulator == nullptr)
                    l_Regulator = me->FindNearestGameObject(eGameObjects::RightHeatRegulator, 10.0f);

                if (l_Regulator != nullptr)
                    l_Regulator->SetGoState(GOState::GO_STATE_ACTIVE);
            }

            void EnterCombat(Unit* /*p_Attacker*/) override
            {
                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me, 2);

                /// Must be done at next update
               // AddTimedDelayedOperation(100, [this]() -> void
               // {
                    me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
               // });
            }

            void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER)
            {
                me->ClearUnitState(UnitState::UNIT_STATE_STUNNED);
                me->ClearUnitState(UnitState::UNIT_STATE_ROOT);

                CreatureAI::EnterEvadeMode();

                me->StopMoving();
                me->ClearUnitState(UnitState::UNIT_STATE_EVADE);

                JustReachedHome();
            }

            void JustReachedHome() override
            {
                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void JustDied(Unit* /*p_Killer*/) override
            {
                if (m_Instance == nullptr)
                    return;

                m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                if (Creature* l_Foreman = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::ForemanFeldspar)))
                {
                    if (l_Foreman->IsAIEnabled)
                        l_Foreman->AI()->DoAction(eAction::RegulatorDestroyed);
                }

                if (Creature* l_Blackhand = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::BlackhandCosmetic)))
                {
                    if (l_Blackhand->IsAIEnabled)
                        l_Blackhand->AI()->DoAction(eAction::RegulatorDestroyed);
                }

                GameObject* l_Regulator = me->FindNearestGameObject(eGameObjects::LeftHeatRegulator, 10.0f);
                if (l_Regulator == nullptr)
                    l_Regulator = me->FindNearestGameObject(eGameObjects::RightHeatRegulator, 10.0f);

                if (l_Regulator != nullptr)
                    l_Regulator->SetGoState(GOState::GO_STATE_READY);
            }

            void UpdateAI(uint32 p_Diff) override
            {
               // UpdateOperations(p_Diff);
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_heat_regulatorAI(p_Creature);
        }
};

/// Security Guard - 88818
/// Security Guard (Fight) - 76812
class npc_foundry_security_guard : public CreatureScript
{
    public:
        npc_foundry_security_guard() : CreatureScript("npc_foundry_security_guard") { }

        enum eSpells
        {
            DefenseAura     = 160379,   ///< Only for LFR
            DefenseMissile  = 177773
        };

        enum eEvent
        {
            EventDefense = 1
        };

        enum eCreature
        {
            GuardForFight = 76812
        };

        struct npc_foundry_security_guardAI : public ScriptedAI
        {
            npc_foundry_security_guardAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

            EventMap m_Events;

            void Reset() override
            {
                m_Events.Reset();

                me->RemoveAllAreaTriggers();

                me->RemoveAura(eSpells::DefenseAura);

                me->SetCanDualWield(false);

                if (me->GetEntry() == eCreature::GuardForFight)
                {
                    //AddTimedDelayedOperation(2 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                   // {
                        if (Player* l_Target = me->SelectNearestPlayer(50.0f))
                            AttackStart(l_Target);
                   // });
                }
            }

            void JustDied(Unit* /*p_Killer*/) override
            {
                me->RemoveAllAreaTriggers();
            }

            void EnterCombat(Unit* /*p_Attacker*/) override
            {
                m_Events.ScheduleEvent(eEvent::EventDefense, 5 * TimeConstants::IN_MILLISECONDS);

                if (InstanceScript* l_Instance = me->GetInstanceScript())
                {
                    if (Creature* l_Foreman = ObjectAccessor::GetCreature(*me, l_Instance->GetGuidData(eFoundryCreatures::ForemanFeldspar)))
                    {
                        if (!l_Foreman->IsInCombat())
                            l_Foreman->SetInCombatWithZone();
                    }
                }
            }

            void UpdateAI(uint32 p_Diff) override
            {
              //  UpdateOperations(p_Diff);

                if (!UpdateVictim())
                    return;

                m_Events.Update(p_Diff);

                if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                    return;

                switch (m_Events.ExecuteEvent())
                {
                    case eEvent::EventDefense:
                    {
                       // if (IsLFR())
                            me->CastSpell(me, eSpells::DefenseAura, false);
                       // else
                            me->CastSpell(me, eSpells::DefenseMissile, false);

                        m_Events.ScheduleEvent(eEvent::EventDefense, 40 * TimeConstants::IN_MILLISECONDS);
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
            return new npc_foundry_security_guardAI(p_Creature);
        }
};

/// Furnace Engineer - 88820
/// Furnace Engineer (Fight) - 76810
class npc_foundry_furnace_engineer : public CreatureScript
{
    public:
        npc_foundry_furnace_engineer() : CreatureScript("npc_foundry_furnace_engineer") { }

        enum eSpells
        {
            Electrocution   = 155201,
            Bomb            = 155192,
            DropLitBombs    = 174726
        };

        enum eEvents
        {
            EventElectrocution = 1,
            EventBomb
        };

        enum eTalk
        {
            BombWarning = 8
        };

        enum eCreature
        {
            EngineerForFight = 76810
        };

        struct npc_foundry_furnace_engineerAI : public ScriptedAI
        {
            npc_foundry_furnace_engineerAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

            EventMap m_Events;

            void Reset() override
            {
                m_Events.Reset();

                if (me->GetEntry() == eCreature::EngineerForFight)
                {
                  //  AddTimedDelayedOperation(2 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                   // {
                        if (Player* l_Target = me->SelectNearestPlayer(50.0f))
                            AttackStart(l_Target);
                   // });
                }
            }

            void EnterCombat(Unit* /*p_Attacker*/) override
            {
                m_Events.ScheduleEvent(eEvents::EventElectrocution, 5 * TimeConstants::IN_MILLISECONDS);
                m_Events.ScheduleEvent(eEvents::EventBomb, 10 * TimeConstants::IN_MILLISECONDS);

                if (InstanceScript* l_Instance = me->GetInstanceScript())
                {
                    if (Creature* l_Foreman = ObjectAccessor::GetCreature(*me, l_Instance->GetGuidData(eFoundryCreatures::ForemanFeldspar)))
                    {
                        if (!l_Foreman->IsInCombat())
                            l_Foreman->SetInCombatWithZone();
                    }
                }
            }

            void SpellHitTarget(Unit* p_Target, SpellInfo const* p_SpellInfo) override
            {
                if (p_Target == nullptr)
                    return;

                if (p_SpellInfo->Id == eSpells::Bomb)
                {
                    if (InstanceScript* l_InstanceScript = me->GetInstanceScript())
                    {
                        if (Creature* l_Creature = ObjectAccessor::GetCreature(*me, l_InstanceScript->GetGuidData(eFoundryCreatures::HeartOfTheMountain)))
                        {
                            if (l_Creature->IsAIEnabled)
                                l_Creature->AI()->Talk(eTalk::BombWarning/*, p_Target->GetGUID(), TextRange::TEXT_RANGE_NORMAL*/);
                        }
                    }
                }
            }

            void JustDied(Unit* /*p_Killer*/) override
            {
                me->CastSpell(me, eSpells::DropLitBombs, true);
            }

            void UpdateAI(uint32 p_Diff) override
            {
                if (!UpdateVictim())
                    return;

                m_Events.Update(p_Diff);

                if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                    return;

                switch (m_Events.ExecuteEvent())
                {
                    case eEvents::EventElectrocution:
                    {
                        if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM))
                            me->CastSpell(l_Target, eSpells::Electrocution, false);

                        m_Events.ScheduleEvent(eEvents::EventElectrocution, 10 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case eEvents::EventBomb:
                    {
                        me->CastSpell(me, eSpells::Bomb, false);
                        m_Events.ScheduleEvent(eEvents::EventBomb, 15 * TimeConstants::IN_MILLISECONDS);
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
            return new npc_foundry_furnace_engineerAI(p_Creature);
        }
};

/// Cluster of Lit Bombs - 87339
class npc_foundry_cluster_of_lit_bombs : public CreatureScript
{
    public:
        npc_foundry_cluster_of_lit_bombs() : CreatureScript("npc_foundry_cluster_of_lit_bombs") { }

        enum eSpells
        {
            ClusterOfLitBombs   = 174731,
            BombAoEDespawn      = 155187,
            BombOverrider       = 174716
        };

        struct npc_foundry_cluster_of_lit_bombsAI : public ScriptedAI
        {
            npc_foundry_cluster_of_lit_bombsAI(Creature* p_Creature) : ScriptedAI(p_Creature), m_MustExplode(true) { }

            bool m_MustExplode;

            void Reset() override
            {
                me->CastSpell(me, eSpells::ClusterOfLitBombs, true);

                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->RemoveUnitFlag(UnitFlags(UNIT_NPC_FLAG_SPELLCLICK));

             //   me->SetUInt32Value(UnitFields::UNIT_FIELD_INTERACT_SPELLID, eSpells::BombOverrider);

                uint32 l_DespawnTimer;

                //if (IsMythic())
                    l_DespawnTimer = 8 * TimeConstants::IN_MILLISECONDS;
               /* else*/ if (IsHeroic())
                    l_DespawnTimer = 10 * TimeConstants::IN_MILLISECONDS;
                else
                    l_DespawnTimer = 15 * TimeConstants::IN_MILLISECONDS;

                if (Aura* l_Aura = me->GetAura(eSpells::ClusterOfLitBombs))
                {
                    l_Aura->SetDuration(l_DespawnTimer + 500);
                    l_Aura->SetMaxDuration(l_DespawnTimer + 500);
                }

                me->DespawnOrUnsummon(l_DespawnTimer + 1 * TimeConstants::IN_MILLISECONDS);

               // AddTimedDelayedOperation(l_DespawnTimer, [this]() -> void
               // {
                    me->RemoveUnitFlag(UnitFlags(UNIT_NPC_FLAG_SPELLCLICK));

                   // me->SetUInt32Value(UnitFields::UNIT_FIELD_INTERACT_SPELLID, 0);

                    if (m_MustExplode)
                        me->CastSpell(me, eSpells::BombAoEDespawn, true);
               // });
            }

            void OnSpellClick(Unit* p_Clicker, bool& /*result*/)
            {
                if (p_Clicker->HasAura(eSpells::BombOverrider))
                    return;

                p_Clicker->CastSpell(p_Clicker, eSpells::BombOverrider, true);

                if (Aura* l_Aura = me->GetAura(eSpells::ClusterOfLitBombs))
                {
                    l_Aura->DropCharge();

                    if (Aura* l_Bomb = p_Clicker->GetAura(eSpells::BombOverrider))
                        l_Bomb->SetDuration(l_Aura->GetDuration());
                }

                if (!me->HasAura(eSpells::ClusterOfLitBombs))
                {
                    m_MustExplode = false;

                   // ClearDelayedOperations();

                    me->DespawnOrUnsummon();
                }
            }

            void UpdateAI(uint32 p_Diff) override
            {
               // UpdateOperations(p_Diff);

                ScriptedAI::UpdateAI(p_Diff);
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_cluster_of_lit_bombsAI(p_Creature);
        }
};

/// Slag Elemental - 78463
class npc_foundry_slag_elemental : public CreatureScript
{
    public:
        npc_foundry_slag_elemental() : CreatureScript("npc_foundry_slag_elemental") { }

        enum eSpells
        {
            Burn            = 155200,
            Fixate          = 155196,
            SlagBomb        = 176133,
            DamageShield    = 155176,
            Reanimate       = 155213,
            DropTarget      = 101438,
            ShieldsDown     = 158345
        };

        enum eCreature
        {
            PrimalElementalist = 76815
        };

        enum eEvent
        {
            EventBurn = 1
        };

        struct npc_foundry_slag_elementalAI : public ScriptedAI
        {
            npc_foundry_slag_elementalAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

            EventMap m_Events;

            ObjectGuid m_Target;

            void Reset() override
            {
                m_Events.Reset();

              //  m_Target.Clear();

                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG2_REGENERATE_POWER));

                me->AddUnitState(UnitState::UNIT_STATE_IGNORE_PATHFINDING);
            }

            void EnterCombat(Unit* /*p_Attacker*/) override
            {
              //  AddTimedDelayedOperation(2 * TimeConstants::IN_MILLISECONDS, [this]() -> void
               // {
                    me->CastSpell(me, eSpells::Fixate, true);

                    me->SetPower(Powers::POWER_ENERGY, 0);
                    me->SetMaxPower(Powers::POWER_ENERGY, 100);

                    m_Events.ScheduleEvent(eEvent::EventBurn, 5 * TimeConstants::IN_MILLISECONDS);
              //  });
            }

            void SetPower(Powers p_Power, int32 p_Value) 
            {
                if (p_Power != Powers::POWER_ENERGY)
                    return;

                if (p_Value >= 100)
                {
                   // AddTimedDelayedOperation(50, [this]() -> void
                   // {
                        me->CastSpell(me, eSpells::Reanimate, false);
                   // });
                }
            }

            void RegeneratePower(Powers p_Power, int32& p_Value)
            {
                if (p_Power != Powers::POWER_ENERGY)
                    return;

                p_Value = 0;
            }

            void OnSpellCasted(SpellInfo const* p_SpellInfo)
            {
                switch (p_SpellInfo->Id)
                {
                    case eSpells::Reanimate:
                    {
                        me->RemoveAura(eSpells::SlagBomb);

                        me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_REMOVE_CLIENT_CONTROL));
                        me->RemoveUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));

                        me->SetReactState(ReactStates::REACT_AGGRESSIVE);
                        me->ClearUnitState(UnitState::UNIT_STATE_ROOT);

                       // AddTimedDelayedOperation(3 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                      //  {
                            Reset();

                            me->CastSpell(me, eSpells::Fixate, true);

                            me->SetPower(Powers::POWER_ENERGY, 0);
                            me->SetMaxPower(Powers::POWER_ENERGY, 100);

                            m_Events.ScheduleEvent(eEvent::EventBurn, 5 * TimeConstants::IN_MILLISECONDS);
                      //  });

                        break;
                    }
                    default:
                        break;
                }
            }

            void OnSpellFinished(SpellInfo const* /*p_SpellInfo*/)
            {
                /// This prevent some movements issues
                me->ClearUnitState(UnitState::UNIT_STATE_CASTING);
            }

            void SpellHitTarget(Unit* p_Target, SpellInfo const* p_SpellInfo) override
            {
                if (p_Target == nullptr)
                    return;

                switch (p_SpellInfo->Id)
                {
                    case eSpells::Fixate:
                    {
                        m_Target = p_Target->GetGUID();

                        me->SetInCombatWithZone();

                        me->getThreatManager().clearReferences();
                        me->getThreatManager().addThreat(p_Target, std::numeric_limits<float>::max());

                        me->TauntApply(p_Target);

                        me->ClearUnitState(UnitState::UNIT_STATE_CASTING);

                        me->GetMotionMaster()->Clear(true);
                        me->GetMotionMaster()->MoveChase(p_Target);
                        break;
                    }
                    default:
                        break;
                }
            }

            void DamageTaken(Unit* /*p_Attacker*/, uint32& p_Damage) override
            {
                /// Prevent damage taken after fake death
                if (me->GetReactState() == ReactStates::REACT_PASSIVE)
                {
                    p_Damage = 0;
                    return;
                }

                if (p_Damage >= me->GetHealth() && me->GetReactState() != ReactStates::REACT_PASSIVE)
                {
                    me->SetReactState(ReactStates::REACT_PASSIVE);

                    me->RemoveAllAuras();

                    p_Damage = 0;

                   // m_Target.Clear();

                    me->GetMotionMaster()->Clear();
                    me->StopMoving();

                    me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_REMOVE_CLIENT_CONTROL));
                    me->AddUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));

                    me->AddUnitState(UnitState::UNIT_STATE_ROOT);

                    me->SetHealth(1);

                    me->CastSpell(me, eSpells::DropTarget, true);
                    me->CastSpell(me, eSpells::SlagBomb, false);

                   // AddTimedDelayedOperation(2 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                   // {
                        std::list<Creature*> l_Elementalists;
                        me->GetCreatureListWithEntryInGrid(l_Elementalists, eCreature::PrimalElementalist, 8.0f);

                        for (Creature* l_Creature : l_Elementalists)
                        {
                            /// If shielded, breaks shield
                            if (l_Creature->HasAura(eSpells::DamageShield))
                                l_Creature->RemoveAura(eSpells::DamageShield);
                            /// If not, refresh the vulnerability
                            else if (Aura* l_Aura = l_Creature->GetAura(eSpells::ShieldsDown))
                                l_Aura->RefreshDuration();
                        }
                   // });
                }
            }

            void UpdateAI(uint32 p_Diff) override
            {
               // UpdateOperations(p_Diff);

                if (!UpdateVictim())
                    return;

                m_Events.Update(p_Diff);

                if (me->HasUnitState(UnitState::UNIT_STATE_CASTING) || me->GetReactState() == ReactStates::REACT_PASSIVE)
                    return;

                if (Player* l_Target = ObjectAccessor::GetPlayer(*me, m_Target))
                {
                    if (!l_Target->IsAlive() || me->GetCurrentSpell(CurrentSpellTypes::CURRENT_CHANNELED_SPELL) == nullptr)
                    {
                       // m_Target.Clear();
                        me->CastSpell(me, eSpells::Fixate, true);
                        return;
                    }
                }

                switch (m_Events.ExecuteEvent())
                {
                    case eEvent::EventBurn:
                    {
                        if (Player* l_Target = ObjectAccessor::GetPlayer(*me, m_Target))
                            me->CastSpell(l_Target, eSpells::Burn, TriggerCastFlags::TRIGGERED_IGNORE_CAST_IN_PROGRESS);

                        m_Events.ScheduleEvent(eEvent::EventBurn, 1 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    default:
                        break;
                }
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_slag_elementalAI(p_Creature);
        }
};

/// Firecaller - 76821
class npc_foundry_firecaller : public CreatureScript
{
    public:
        npc_foundry_firecaller() : CreatureScript("npc_foundry_firecaller") { }

        enum eSpells
        {
            /// Others
            Dormant         = 155233,
            /// Fight
            CauterizeWounds = 155186,
            LavaBurst       = 159408,
            VolatileFire    = 176121
        };

        enum eEvents
        {
            EventCauterizeWounds = 1,
            EventLavaBurst,
            EventVolatileFire
        };

        enum eCreature
        {
            SlagElemental = 78463
        };

        enum eTalk
        {
            TalkVolatileFire = 9
        };

        struct npc_foundry_firecallerAI : public ScriptedAI
        {
            npc_foundry_firecallerAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

            EventMap m_Events;

            void Reset() override
            {
                m_Events.Reset();
            }

            void EnterCombat(Unit* /*p_Attacker*/) override
            {
                m_Events.ScheduleEvent(eEvents::EventCauterizeWounds, 15 * TimeConstants::IN_MILLISECONDS);
                m_Events.ScheduleEvent(eEvents::EventLavaBurst, 10 * TimeConstants::IN_MILLISECONDS);
                m_Events.ScheduleEvent(eEvents::EventVolatileFire, 5 * TimeConstants::IN_MILLISECONDS);
            }

            void SpellHitTarget(Unit* p_Target, SpellInfo const* p_SpellInfo) override
            {
                if (p_Target == nullptr)
                    return;

                if (p_SpellInfo->Id == eSpells::VolatileFire)
                {
                    if (InstanceScript* l_Instance = me->GetInstanceScript())
                    {
                        if (Creature* l_Fury = ObjectAccessor::GetCreature(*me, l_Instance->GetGuidData(eFoundryCreatures::HeartOfTheMountain)))
                        {
                            if (l_Fury->IsAIEnabled)
                                l_Fury->AI()->Talk(eTalk::TalkVolatileFire/*, p_Target->GetGUID(), TextRange::TEXT_RANGE_NORMAL*/);
                        }
                    }
                }
            }

            void UpdateAI(uint32 p_Diff) override
            {
                if (!UpdateVictim())
                    return;

                m_Events.Update(p_Diff);

                if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                    return;

                switch (m_Events.ExecuteEvent())
                {
                    case eEvents::EventCauterizeWounds:
                    {
                       // if (Unit* l_Ally = me->SelectNearbyMostInjuredAlly(me, 30.0f, eCreature::SlagElemental))
                            me->CastSpell(me, eSpells::CauterizeWounds, false);

                        m_Events.ScheduleEvent(eEvents::EventCauterizeWounds, 20 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case eEvents::EventLavaBurst:
                    {
                        me->CastSpell(me, eSpells::LavaBurst, false);
                        m_Events.ScheduleEvent(eEvents::EventLavaBurst, 10 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case eEvents::EventVolatileFire:
                    {
                        me->CastSpell(me, eSpells::VolatileFire, false);
                        m_Events.ScheduleEvent(eEvents::EventVolatileFire, 15 * TimeConstants::IN_MILLISECONDS);
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
            return new npc_foundry_firecallerAI(p_Creature);
        }
};

/// Defense - 160379
class spell_foundry_defense_aura : public SpellScriptLoader
{
    public:
        spell_foundry_defense_aura() : SpellScriptLoader("spell_foundry_defense_aura") { }

        class spell_foundry_defense_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_foundry_defense_aura_AuraScript);

            enum eSpells
            {
                DefenseAura = 160379,
                DefenseProc = 160382
            };

            uint32 m_DamageTimer;

            bool Load() override
            {
                m_DamageTimer = 500;
                return true;
            }

            void OnUpdate(uint32 p_Diff)
            {
                if (m_DamageTimer)
                {
                    if (m_DamageTimer <= p_Diff)
                    {
                        if (Unit* l_Caster = GetCaster())
                        {
                            std::list<Unit*> l_TargetList;
                            float l_Radius = 7.0f;

                            Trinity::AnyFriendlyUnitInObjectRangeCheck l_Check(l_Caster, l_Caster, l_Radius);
                            Trinity::UnitListSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> l_Searcher(l_Caster, l_TargetList, l_Check);
                          //  l_Caster->VisitNearbyObject(l_Radius, l_Searcher);

                            for (Unit* l_Iter : l_TargetList)
                            {
                                if (!l_Iter->HasAura(eSpells::DefenseProc))
                                    l_Caster->CastSpell(l_Iter, eSpells::DefenseProc, true);
                            }
                        }

                        m_DamageTimer = 500;
                    }
                    else
                        m_DamageTimer -= p_Diff;
                }
            }

            void Register() override
            {
              //  OnAuraUpdate += AuraUpdateFn(spell_foundry_defense_aura_AuraScript::OnUpdate);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_foundry_defense_aura_AuraScript();
        }
};

/// Bomb (overrider) - 155192
/// Bomb (overrider - second) - 174716
/// Bomb (overrider - when mind controlled) - 159558
class spell_foundry_bomb_overrider : public SpellScriptLoader
{
    public:
        spell_foundry_bomb_overrider() : SpellScriptLoader("spell_foundry_bomb_overrider") { }

        class spell_foundry_bomb_overrider_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_foundry_bomb_overrider_AuraScript);

            enum eSpell
            {
                BombAoE = 155187
            };

            void AfterApply(AuraEffect const* p_AurEff, AuraEffectHandleModes /*p_Mode*/)
            {
                if (Unit* l_Target = GetTarget())
                {
                    Aura* l_Aura = p_AurEff->GetBase();
                    if (l_Target->GetMap()->IsHeroic())
                    {
                        l_Aura->SetDuration(10 * TimeConstants::IN_MILLISECONDS);
                        l_Aura->SetMaxDuration(10 * TimeConstants::IN_MILLISECONDS);
                    }
                    else// if (l_Target->GetMap()->IsMythic())
                    {
                        l_Aura->SetDuration(8 * TimeConstants::IN_MILLISECONDS);
                        l_Aura->SetMaxDuration(8 * TimeConstants::IN_MILLISECONDS);
                    }
                }
            }

            void AfterRemove(AuraEffect const* /*p_AurEff*/, AuraEffectHandleModes /*p_Mode*/)
            {
                if (Unit* l_Target = GetTarget())
                    l_Target->CastSpell(l_Target, eSpell::BombAoE, true);
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_foundry_bomb_overrider_AuraScript::AfterApply, EFFECT_0, SPELL_AURA_OVERRIDE_SPELLS, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_foundry_bomb_overrider_AuraScript::AfterRemove, EFFECT_0, SPELL_AURA_OVERRIDE_SPELLS, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_foundry_bomb_overrider_AuraScript();
        }
};

/// Rupture - 156934
class spell_foundry_rupture_aura : public SpellScriptLoader
{
    public:
        spell_foundry_rupture_aura() : SpellScriptLoader("spell_foundry_rupture_aura") { }

        class spell_foundry_rupture_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_foundry_rupture_aura_AuraScript);

            enum eSpell
            {
                RuptureAreatrigger = 156933
            };

            void AfterRemove(AuraEffect const* /*p_AurEff*/, AuraEffectHandleModes /*p_Mode*/)
            {
                if (Unit* l_Caster = GetCaster())
                {
                    if (Unit* l_Target = GetTarget())
                        l_Caster->CastSpell(l_Target, eSpell::RuptureAreatrigger, true);
                }
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_foundry_rupture_aura_AuraScript::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_foundry_rupture_aura_AuraScript();
        }
};

/// Hot Blooded - 158247
class spell_foundry_hot_blooded_aura : public SpellScriptLoader
{
    public:
        spell_foundry_hot_blooded_aura() : SpellScriptLoader("spell_foundry_hot_blooded_aura") { }

        class spell_foundry_hot_blooded_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_foundry_hot_blooded_aura_AuraScript);

            enum eSpells
            {
                HotBloodedDoT = 158246
            };

            uint32 m_DamageTimer;

            bool Load() override
            {
                m_DamageTimer = 500;
                return true;
            }

            void OnUpdate(uint32 p_Diff)
            {
                if (m_DamageTimer)
                {
                    if (m_DamageTimer <= p_Diff)
                    {
                        if (Unit* l_Caster = GetCaster())
                        {
                            std::list<Unit*> l_TargetList;
                            float l_Radius = 20.0f;

                            Trinity::AnyUnfriendlyUnitInObjectRangeCheck l_Check(l_Caster, l_Caster, l_Radius);
                            Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> l_Searcher(l_Caster, l_TargetList, l_Check);
                           // l_Caster->VisitNearbyObject(l_Radius, l_Searcher);

                            for (Unit* l_Iter : l_TargetList)
                                l_Caster->CastSpell(l_Iter, eSpells::HotBloodedDoT, true);
                        }

                        m_DamageTimer = 500;
                    }
                    else
                        m_DamageTimer -= p_Diff;
                }
            }

            void Register() override
            {
               // OnAuraUpdate += AuraUpdateFn(spell_foundry_hot_blooded_aura_AuraScript::OnUpdate);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_foundry_hot_blooded_aura_AuraScript();
        }
};

/// Damage Shield - 155176
class spell_foundry_damage_shield : public SpellScriptLoader
{
    public:
        spell_foundry_damage_shield() : SpellScriptLoader("spell_foundry_damage_shield") { }

        class spell_foundry_damage_shield_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_foundry_damage_shield_AuraScript);

            enum eSpell
            {
                ShieldsDown = 158345
            };

            void AfterRemove(AuraEffect const* /*p_AurEff*/, AuraEffectHandleModes /*p_Mode*/)
            {
                if (GetTarget() == nullptr)
                    return;

                if (Creature* l_Target = GetTarget()->ToCreature())
                {
                    if (!l_Target->IsAIEnabled)
                        return;

                    if (npc_foundry_primal_elementalist::npc_foundry_primal_elementalistAI* l_AI = CAST_AI(npc_foundry_primal_elementalist::npc_foundry_primal_elementalistAI, l_Target->GetAI()))
                    {
                        ObjectGuid l_Guid = l_Target->GetGUID();
                        //l_AI->AddTimedDelayedOperation(50, [this, l_Guid]() -> void
                       // {
                            if (Unit* l_Target = ObjectAccessor::FindPlayer(l_Guid))
                                l_Target->CastSpell(l_Target, eSpell::ShieldsDown, true);
                       // });
                    }
                }
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_foundry_damage_shield_AuraScript::AfterRemove, EFFECT_0, SPELL_AURA_DAMAGE_IMMUNITY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_foundry_damage_shield_AuraScript();
        }
};

/// Shields Down - 158345
class spell_foundry_shields_down : public SpellScriptLoader
{
    public:
        spell_foundry_shields_down() : SpellScriptLoader("spell_foundry_shields_down") { }

        class spell_foundry_shields_down_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_foundry_shields_down_AuraScript);

            enum eSpell
            {
                DamageShield = 155176
            };

            void AfterApply(AuraEffect const* p_AurEff, AuraEffectHandleModes /*p_Mode*/)
            {
                if (Unit* l_Target = GetTarget())
                {
                    Aura* l_Aura = p_AurEff->GetBase();
                    if (l_Target->GetMap()->IsHeroic())
                    {
                        l_Aura->SetDuration(30 * TimeConstants::IN_MILLISECONDS);
                        l_Aura->SetMaxDuration(30 * TimeConstants::IN_MILLISECONDS);
                    }
                    else //if (l_Target->GetMap()->IsMythic())
                    {
                        l_Aura->SetDuration(20 * TimeConstants::IN_MILLISECONDS);
                        l_Aura->SetMaxDuration(20 * TimeConstants::IN_MILLISECONDS);
                    }
                   // else
                  //  {
                     //   l_Aura->SetDuration(40 * TimeConstants::IN_MILLISECONDS);
                     //   l_Aura->SetMaxDuration(40 * TimeConstants::IN_MILLISECONDS);
                   // }
                }
            }

            void AfterRemove(AuraEffect const* /*p_AurEff*/, AuraEffectHandleModes /*p_Mode*/)
            {
                if (GetTarget() == nullptr)
                    return;

                if (Creature* l_Target = GetTarget()->ToCreature())
                {
                    if (!l_Target->IsAIEnabled)
                        return;

                    if (npc_foundry_primal_elementalist::npc_foundry_primal_elementalistAI* l_AI = CAST_AI(npc_foundry_primal_elementalist::npc_foundry_primal_elementalistAI, l_Target->GetAI()))
                    {
                        ObjectGuid l_Guid = l_Target->GetGUID();
                       // l_AI->AddTimedDelayedOperation(50, [this, l_Guid]() -> void
                       // {
                            if (Unit* l_Target = ObjectAccessor::FindPlayer(l_Guid))
                                l_Target->CastSpell(l_Target, eSpell::DamageShield, true);
                       // });
                    }
                }
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_foundry_shields_down_AuraScript::AfterApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_foundry_shields_down_AuraScript::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_foundry_shields_down_AuraScript();
        }
};

/// Volatile Fire - 176121
class spell_foundry_volatile_fire : public SpellScriptLoader
{
    public:
        spell_foundry_volatile_fire() : SpellScriptLoader("spell_foundry_volatile_fire") { }

        class spell_foundry_volatile_fire_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_foundry_volatile_fire_AuraScript);

            void OnApply(AuraEffect const* p_AurEff, AuraEffectHandleModes /*p_Mode*/)
            {
              //  int32 l_NewDuration = p_AurEff->GetAmplitude();

                if (Aura* l_Base = p_AurEff->GetBase())
                {
               //     l_Base->SetMaxDuration(l_NewDuration);
                //    l_Base->SetDuration(l_NewDuration);
                }
            }

            void OnTick(AuraEffect const* /*p_AurEff*/)
            {
                if (Unit* l_Caster = GetCaster())
                {
                    if (Unit* l_Target = GetTarget())
                    {
                        uint32 l_TriggerID = GetSpellInfo()->GetEffect(EFFECT_0)->TriggerSpell;
                        l_Caster->CastSpell(l_Target, l_TriggerID, true);
                    }
                }
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_foundry_volatile_fire_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_foundry_volatile_fire_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_foundry_volatile_fire_AuraScript();
        }
};

/// Melt - 155225
class spell_foundry_melt_aura : public SpellScriptLoader
{
    public:
        spell_foundry_melt_aura() : SpellScriptLoader("spell_foundry_melt_aura") { }

        class spell_foundry_melt_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_foundry_melt_aura_AuraScript);

            enum eSpell
            {
                MeltAreatrigger = 155224
            };

            void AfterRemove(AuraEffect const* /*p_AurEff*/, AuraEffectHandleModes /*p_Mode*/)
            {
                if (Unit* l_Caster = GetCaster())
                {
                    if (Unit* l_Target = GetTarget())
                        l_Caster->CastSpell(l_Target, eSpell::MeltAreatrigger, true);
                }
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_foundry_melt_aura_AuraScript::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_foundry_melt_aura_AuraScript();
        }
};

/// Heart of the Furnace - 155288
class spell_foundry_heart_of_the_furnace : public SpellScriptLoader
{
    public:
        spell_foundry_heart_of_the_furnace() : SpellScriptLoader("spell_foundry_heart_of_the_furnace") { }

        class spell_foundry_heart_of_the_furnace_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_foundry_heart_of_the_furnace_AuraScript);

            void OnTick(AuraEffect const* p_AurEff)
            {
                if (GetTarget() == nullptr)
                    return;

                if (Creature* l_Boss = GetTarget()->ToCreature())
                {
                    if (boss_heart_of_the_mountain::boss_heart_of_the_mountainAI* l_AI = CAST_AI(boss_heart_of_the_mountain::boss_heart_of_the_mountainAI, l_Boss->GetAI()))
                        p_AurEff->GetBase()->GetEffect(EFFECT_0)->ChangeAmount(l_AI->GetBlastTimer() / TimeConstants::IN_MILLISECONDS);
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_foundry_heart_of_the_furnace_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_foundry_heart_of_the_furnace_AuraScript();
        }
};

/// Deafening Roar - 177756
class spell_foundry_deafening_roar : public SpellScriptLoader
{
    public:
        spell_foundry_deafening_roar() : SpellScriptLoader("spell_foundry_deafening_roar") { }

        class spell_foundry_deafening_roar_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_foundry_deafening_roar_SpellScript);

            enum eSpells
            {
                TargetRestrict  = 24605,

                Bomb            = 155192,
                BombOther       = 174716
            };

            void CorrectTargets(std::list<WorldObject*>& p_Targets)
            {
                if (p_Targets.empty())
                    return;

                SpellTargetRestrictionsEntry const* l_Restriction = sSpellTargetRestrictionsStore.LookupEntry(eSpells::TargetRestrict);
                if (l_Restriction == nullptr)
                    return;

                Unit* l_Caster = GetCaster();
                if (l_Caster == nullptr)
                    return;

                float l_Angle = 2 * M_PI / 360 * l_Restriction->ConeDegrees;
                p_Targets.remove_if([l_Caster, l_Angle](WorldObject* p_Object) -> bool
                {
                    if (p_Object == nullptr)
                        return true;

                    if (!p_Object->isInFront(l_Caster, l_Angle))
                        return true;

                    return false;
                });
            }

            void HandleDamage(SpellEffIndex /*p_EffIndex*/)
            {
                if (Unit* l_Caster = GetCaster())
                {
                    if (Unit* l_Target = GetHitUnit())
                    {
                        l_Target->RemoveAura(eSpells::Bomb);
                        l_Target->RemoveAura(eSpells::BombOther);
                    }
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_foundry_deafening_roar_SpellScript::CorrectTargets, EFFECT_0, TARGET_UNIT_CONE_ENEMY_104);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_foundry_deafening_roar_SpellScript();
        }
};

/// Slag Pool (periodic) - 163532
class spell_foundry_slag_pool_periodic : public SpellScriptLoader
{
    public:
        spell_foundry_slag_pool_periodic() : SpellScriptLoader("spell_foundry_slag_pool_periodic") { }

        class spell_foundry_slag_pool_periodic_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_foundry_slag_pool_periodic_AuraScript);

            void AfterApply(AuraEffect const* p_AurEff, AuraEffectHandleModes /*p_Mode*/)
            {
                if (Unit* l_Target = GetTarget())
                {
                    AuraEffect* l_AuraEffect = p_AurEff->GetBase()->GetEffect(EFFECT_0);
                    if (l_AuraEffect == nullptr)
                        return;

                    //if (l_Target->GetMap()->IsHeroic())
                      //  l_AuraEffect->SetAmplitude(4 * TimeConstants::IN_MILLISECONDS);
                   // else if (l_Target->GetMap()->IsMythic())
                       // l_AuraEffect->SetAmplitude(3 * TimeConstants::IN_MILLISECONDS);
                  //  else
                       // l_AuraEffect->SetAmplitude(5 * TimeConstants::IN_MILLISECONDS);
                }
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_foundry_slag_pool_periodic_AuraScript::AfterApply, EFFECT_0, SPELL_AURA_PERIODIC_ENERGIZE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_foundry_slag_pool_periodic_AuraScript();
        }
};

/// Crucible (Left) - 233757
/// Crucible (Right) - 233758
class go_foundry_crucible : public GameObjectScript
{
    public:
        go_foundry_crucible() : GameObjectScript("go_foundry_crucible") { }

        struct go_foundry_crucibleAI : public GameObjectAI
        {
            go_foundry_crucibleAI(GameObject* p_GameObject) : GameObjectAI(p_GameObject) { }

            EventMap m_Events;

            enum eGameObjects
            {
                CrucibleSecLeft     = 237303,
                CrucibleSecRight    = 237302
            };

            enum eEvent
            {
                EventInit = 1
            };

            void Reset() override
            {
                uint32 l_Time = urand(1 * TimeConstants::IN_MILLISECONDS, 10 * TimeConstants::IN_MILLISECONDS);

                GameObject* l_CrucibleSec = go->FindNearestGameObject(eGameObjects::CrucibleSecLeft, 50.0f);
                if (l_CrucibleSec == nullptr)
                    l_CrucibleSec = go->FindNearestGameObject(eGameObjects::CrucibleSecRight, 50.0f);

                m_Events.ScheduleEvent(eEvent::EventInit, 2 * TimeConstants::IN_MILLISECONDS);

                if (l_CrucibleSec != nullptr)
                {
                    m_Events.Reset();

                    ObjectGuid l_Guid = l_CrucibleSec->GetGUID();
                  //  AddTimedDelayedOperation(l_Time, [this, l_Guid]() -> void
                   // {
                        if (GameObject* l_CrucibleSec =ObjectAccessor::GetGameObject(*go, l_Guid))
                            l_CrucibleSec->SetGoState(GOState::GO_STATE_ACTIVE);
                   // });

                    l_Time += 6 * TimeConstants::IN_MILLISECONDS;

                   // AddTimedDelayedOperation(l_Time, [this, l_Guid]() -> void
                   // {
                        if (GameObject* l_CrucibleSec = ObjectAccessor::GetGameObject(*go, l_Guid))
                            l_CrucibleSec->SetGoState(GOState::GO_STATE_READY);
                   // });

                    l_Time += 5 * TimeConstants::IN_MILLISECONDS;

                   // AddTimedDelayedOperation(l_Time, [this]() -> void
                    //{
                        /// Start animation
                        go->SetGoState(GOState::GO_STATE_ACTIVE);
                   // });

                    l_Time += 5 * TimeConstants::IN_MILLISECONDS;

                   // AddTimedDelayedOperation(l_Time, [this]() -> void
                   // {
                        /// End animation
                        go->SetGoState(GOState::GO_STATE_READY);
                   // });
                }
            }

            void LastOperationCalled() 
            {
                Reset();
            }

            void UpdateAI(uint32 p_Diff) override
            {
                /// Stop animation after Blast Furnace completion
                if (InstanceScript* l_InstanceScript = go->GetInstanceScript())
                {
                    if (l_InstanceScript->GetBossState(eFoundryDatas::DataBlastFurnace) == EncounterState::DONE)
                        return;
                }

               // UpdateOperations(p_Diff);

                m_Events.Update(p_Diff);

                if (m_Events.ExecuteEvent() == eEvent::EventInit)
                    Reset();
            }
        };

        GameObjectAI* GetAI(GameObject* p_GameObject) const override
        {
            return new go_foundry_crucibleAI(p_GameObject);
        }
};

/// Rupture - 156933
class areatrigger_foundry_rupture : public AreaTriggerEntityScript
{
    public:
        areatrigger_foundry_rupture() : AreaTriggerEntityScript("areatrigger_foundry_rupture") { }

        enum eSpell
        {
            RuptureDoT = 156932
        };

        std::set<ObjectGuid> m_AffectedPlayers;

        void OnCreate(AreaTrigger* p_AreaTrigger)
        {
            uint32 l_Duration = (1 * TimeConstants::MINUTE + 30) * TimeConstants::IN_MILLISECONDS;

            p_AreaTrigger->SetDuration(l_Duration);
        }

        void OnUpdate(AreaTrigger* p_AreaTrigger, uint32 /*p_Time*/)
        {
            if (Unit* l_Caster = p_AreaTrigger->GetCaster())
            {
                std::list<Unit*> l_TargetList;
                float l_Radius = 2.5f;

                Trinity::AnyUnfriendlyUnitInObjectRangeCheck l_Check(p_AreaTrigger, l_Caster, l_Radius);
                Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> l_Searcher(p_AreaTrigger, l_TargetList, l_Check);
                //p_AreaTrigger->VisitNearbyObject(l_Radius, l_Searcher);

                std::set<ObjectGuid> l_Targets;

                for (Unit* l_Iter : l_TargetList)
                {
                    l_Targets.insert(l_Iter->GetGUID());

                    if (!l_Iter->HasAura(eSpell::RuptureDoT))
                    {
                        m_AffectedPlayers.insert(l_Iter->GetGUID());
                        l_Iter->CastSpell(l_Iter, eSpell::RuptureDoT, true);
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
                        l_Unit->RemoveAura(eSpell::RuptureDoT);

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
                        l_Unit->RemoveAura(eSpell::RuptureDoT);
                }
            }
        }
        /*
        AreaTriggerEntityScript* GetAI()
        {
            return nullptr;
        }*/
};

/// Slag Pool - 155738

class areatrigger_foundry_slag_pool : public AreaTriggerEntityScript
{
    public:
        areatrigger_foundry_slag_pool() : AreaTriggerEntityScript("areatrigger_foundry_slag_pool") { }

        enum eSpells
        {
            SlagPoolDoTAura     = 155743,
            SlagPoolEnergizer   = 163532
        };

        void OnUpdate(AreaTrigger* p_AreaTrigger, uint32 )
        {
            if (Unit* l_Caster = p_AreaTrigger->GetCaster())
            {
               // AreaTriggerTemplateList  const& l_Templates = p_AreaTrigger->GetTemplates();
                std::vector<G3D::Vector2> l_CheckPoints;

                std::list<Unit*> l_TargetList;
                float l_Radius = 50.0f;

                Trinity::AnyUnfriendlyUnitInObjectRangeCheck l_Check(p_AreaTrigger, l_Caster, l_Radius);
                Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> l_Searcher(p_AreaTrigger, l_TargetList, l_Check);
               // p_AreaTrigger->VisitNearbyObject(l_Radius, l_Searcher);

                float l_X = p_AreaTrigger->GetPositionX();
                float l_Y = p_AreaTrigger->GetPositionY();
                float l_Z = p_AreaTrigger->GetPositionZ();
                float l_O = p_AreaTrigger->GetOrientation();

                Position const l_Pos = { l_X, l_Y, l_Z, 0.0f };

               // for (AreaTriggerTemplate l_Template : l_Templates)
              //  {
                    /// Absolute position according to the current position and the template
                   // float l_AbsX = l_X + l_Template.m_PolygonDatas.m_Vertices[0];
                   // float l_AbsY = l_Y + l_Template.m_PolygonDatas.m_Vertices[1];

                    /// Calculating the distance between the origin and the absolute position, and the angle between them
                   // Position const l_VirtualPos = { l_AbsX, l_AbsY, l_Z, 0.0f };
                   // float l_Dist = l_Pos.GetExactDist2d(&l_VirtualPos);
                   // float l_Angle = l_Pos.GetAngle(&l_VirtualPos);

                    /// Reporting the distance and the angle according to the current orientation
                   // float l_NewX = l_X + l_Dist * cos(l_O - l_Angle + M_PI / 2.0f);
                   // float l_NewY = l_Y + l_Dist * sin(l_O - l_Angle + M_PI / 2.0f);

                    /// Adding the point to the vector
                  //  G3D::Vector2 l_Point = G3D::Vector2(l_NewX, l_NewY);
                  //  l_CheckPoints.push_back(l_Point);
               // }

               // if (p_AreaTrigger->IsInAreaTriggerPolygon(l_CheckPoints, G3D::Vector2(l_Caster->m_positionX, l_Caster->m_positionY)))
               // {
                    if (!l_Caster->HasAura(eSpells::SlagPoolEnergizer))
                        l_Caster->CastSpell(l_Caster, eSpells::SlagPoolEnergizer, true);
              //  }
               // else
               // {
                    if (l_Caster->HasAura(eSpells::SlagPoolEnergizer))
                        l_Caster->RemoveAura(eSpells::SlagPoolEnergizer);
              //  }

                for (Unit* l_Unit : l_TargetList)
                {
                    /// Target not in lightning lines
                  //  if (!p_AreaTrigger->IsInAreaTriggerPolygon(l_CheckPoints, G3D::Vector2(l_Unit->m_positionX, l_Unit->m_positionY)))
                  //  {
                        if (l_Unit->HasAura(eSpells::SlagPoolDoTAura))
                        {
                            l_Unit->RemoveAura(eSpells::SlagPoolDoTAura);
                            continue;
                        }
                  //  }
                   // else
                   // {
                        if (!l_Unit->HasAura(eSpells::SlagPoolDoTAura))
                            l_Caster->CastSpell(l_Unit, eSpells::SlagPoolDoTAura, true);
                   // }
                }
            }
        }

        void OnRemove(AreaTrigger* p_AreaTrigger, uint32 )
        {
            if (Unit* l_Caster = p_AreaTrigger->GetCaster())
            {
                if (l_Caster->HasAura(eSpells::SlagPoolEnergizer))
                    l_Caster->RemoveAura(eSpells::SlagPoolEnergizer);

                std::list<Unit*> l_TargetList;
                float l_Radius = 50.0f;

                Trinity::AnyUnfriendlyUnitInObjectRangeCheck l_Check(p_AreaTrigger, l_Caster, l_Radius);
                Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> l_Searcher(p_AreaTrigger, l_TargetList, l_Check);
               // p_AreaTrigger->VisitNearbyObject(l_Radius, l_Searcher);

                for (Unit* l_Unit : l_TargetList)
                {
                    if (l_Unit->HasAura(eSpells::SlagPoolDoTAura))
                        l_Unit->RemoveAura(eSpells::SlagPoolDoTAura);
                }
            }
        }
        /*
        AreaTriggerEntityScript* GetAI() const override
        {
            return new areatrigger_foundry_slag_pool();
        }*/
};

/// Melt - 155224
class areatrigger_foundry_melt : public AreaTriggerEntityScript
{
    public:
        areatrigger_foundry_melt() : AreaTriggerEntityScript("areatrigger_foundry_melt") { }

        enum eSpell
        {
            MeltDoT = 155223
        };

        std::set<ObjectGuid> m_AffectedPlayers;

        void OnUpdate(AreaTrigger* p_AreaTrigger, uint32 /*p_Time*/)
        {
            if (Unit* l_Caster = p_AreaTrigger->GetCaster())
            {
                std::list<Unit*> l_TargetList;
                float l_Radius = 5.0f;

                Trinity::AnyUnfriendlyUnitInObjectRangeCheck l_Check(p_AreaTrigger, l_Caster, l_Radius);
                Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> l_Searcher(p_AreaTrigger, l_TargetList, l_Check);
               // p_AreaTrigger->VisitNearbyObject(l_Radius, l_Searcher);

                std::set<ObjectGuid> l_Targets;

                for (Unit* l_Iter : l_TargetList)
                {
                    l_Targets.insert(l_Iter->GetGUID());

                    if (!l_Iter->HasAura(eSpell::MeltDoT))
                    {
                        m_AffectedPlayers.insert(l_Iter->GetGUID());
                        l_Iter->CastSpell(l_Iter, eSpell::MeltDoT, true);
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
                        l_Unit->RemoveAura(eSpell::MeltDoT);

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
                        l_Unit->RemoveAura(eSpell::MeltDoT);
                }
            }
        }
        /*
        AreaTriggerEntityScript* GetAI()
        {
            return nullptr;
        }*/
};

/// Defense - 177772
class areatrigger_foundry_defense : public AreaTriggerEntityScript
{
    public:
        areatrigger_foundry_defense() : AreaTriggerEntityScript("areatrigger_foundry_defense") { }

        enum eSpells
        {
            Loading     = 155181,
            DefenseAura = 160382
        };

        enum eCreature
        {
            PrimalElementalist = 76815
        };

        void OnUpdate(AreaTrigger* p_AreaTrigger, uint32 /*p_Time*/)
        {
            if (Unit* l_Caster = p_AreaTrigger->GetCaster())
            {
                std::list<Unit*> l_TargetList;
                float l_Radius = 15.0f;

                Trinity::AnyFriendlyUnitInObjectRangeCheck l_Check(p_AreaTrigger, l_Caster, l_Radius);
                Trinity::UnitListSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> l_Searcher(p_AreaTrigger, l_TargetList, l_Check);
               // p_AreaTrigger->VisitNearbyObject(l_Radius, l_Searcher);

                for (Unit* l_Unit : l_TargetList)
                {
                    /// Note that Primal Elementalists are immune to the damage-reduction portion of Defense.
                    if (l_Unit->GetEntry() == eCreature::PrimalElementalist)
                        continue;

                    /// As long as Regulators are alive, Bellows Operators are not affected by the Security Guards Defense.
                    if (l_Unit->HasAura(eSpells::Loading))
                        continue;

                    if (l_Unit->GetDistance(p_AreaTrigger) <= 3.5f)
                    {
                        if (!l_Unit->HasAura(eSpells::DefenseAura))
                            l_Caster->CastSpell(l_Unit, eSpells::DefenseAura, true);
                    }
                    //else if (!l_Unit->FindNearestAreaTrigger(p_AreaTrigger->GetSpellId(), 3.5f))
                   // {
                        if (l_Unit->HasAura(eSpells::DefenseAura))
                            l_Unit->RemoveAura(eSpells::DefenseAura);
                   // }
                }
            }
        }

        void OnRemove(AreaTrigger* p_AreaTrigger, uint32 /*p_Time*/)
        {
            if (Unit* l_Caster = p_AreaTrigger->GetCaster())
            {
                std::list<Unit*> l_TargetList;
                float l_Radius = 3.5f;

                Trinity::AnyUnfriendlyUnitInObjectRangeCheck l_Check(p_AreaTrigger, l_Caster, l_Radius);
                Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> l_Searcher(p_AreaTrigger, l_TargetList, l_Check);
               // p_AreaTrigger->VisitNearbyObject(l_Radius, l_Searcher);

                for (Unit* l_Unit : l_TargetList)
                {
                   // if (!l_Unit->FindNearestAreaTrigger(p_AreaTrigger->GetSpellId(), l_Radius))
                  //  {
                        if (l_Unit->HasAura(eSpells::DefenseAura))
                            l_Unit->RemoveAura(eSpells::DefenseAura);
                  //  }
                }
            }
        }
        /*
        AreaTriggerEntityScript* GetAI()
        {
            return nullptr;
        }*/
};

void AddSC_boss_blast_furnace()
{
    /// Bosses
    new boss_heart_of_the_mountain();/// Heart of the Mountain - 76806
    new boss_foreman_feldspar();/// Foreman Feldspar - 76809

    /// Creatures
    new npc_foundry_blackhand_cosmetic();/// Blackhand (Cosmetic) - 76831
    new npc_foundry_primal_elementalist();/// Primal Elementalist - 76815
    new npc_foundry_bellows_operator();/// Bellows Operator - 88821 - 76811
    new npc_foundry_heat_regulator();/// Heat Regulator - 76808
    new npc_foundry_security_guard();/// Security Guard - 88818 - 76812
    new npc_foundry_furnace_engineer();/// Furnace Engineer - 88820- 76810
    new npc_foundry_cluster_of_lit_bombs();/// Cluster of Lit Bombs - 87339
    new npc_foundry_slag_elemental();/// Slag Elemental - 78463
    new npc_foundry_firecaller();/// Firecaller - 76821

    /// Spells
    new spell_foundry_defense_aura();/// Defense - 160379
    new spell_foundry_bomb_overrider();/// Bomb (overrider) - 155192- 174716 - 159558
    new spell_foundry_rupture_aura();/// Rupture - 156934
    new spell_foundry_hot_blooded_aura();/// Hot Blooded - 158247
    new spell_foundry_damage_shield();/// Damage Shield - 155176
    new spell_foundry_shields_down();/// Shields Down - 158345
    new spell_foundry_volatile_fire();/// Volatile Fire - 176121
    new spell_foundry_melt_aura();/// Melt - 155225
    new spell_foundry_heart_of_the_furnace();/// Heart of the Furnace - 155288
    new spell_foundry_deafening_roar();/// Deafening Roar - 177756
    new spell_foundry_slag_pool_periodic();/// Slag Pool (periodic) - 163532

    /// GameObject
    new go_foundry_crucible();/// Crucible (Left) - 233757- 233758

    /// AreaTriggers
    new areatrigger_foundry_rupture();/// Rupture - 156933
    new areatrigger_foundry_slag_pool();//??/// Slag Pool - 155738
    new areatrigger_foundry_melt();/// Melt - 155224
    new areatrigger_foundry_defense();/// Defense - 177772
}
