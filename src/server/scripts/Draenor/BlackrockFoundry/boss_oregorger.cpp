#include "boss_oregorger.h"

/// Oregorger <The Devourer> - 77182
class boss_oregorger : public CreatureScript
{
    public:
        boss_oregorger() : CreatureScript("boss_oregorger") { }

        enum eSpells
        {
            /// Misc
            OregorgerBonusLoot          = 177530,
            RollingFuryVisual           = 174183,
            RollingBox                  = 160665,
            WallshakingRoar             = 160662,
            EarthshakingStomp           = 159958,
            CarryingVolatileBlackrock   = 163454,
            /// Phase 1
            /// Acid Maw
            AcidMawDoT                  = 173471,
            /// Retched Blackrock
            RetchedBlackrockMissile     = 156179,
            RetchedBlackrockDoT         = 156203,
            /// Explosive Shard
            ExplosiveShardMissile       = 156390,
            ExplosiveShardAoE           = 156374,
            /// Acid Torrent
            AcidTorrentSearcher         = 156240,
            AcidTorrentTriggered        = 160465,
            AcidTorrentScriptEffect     = 156243,
            AcidTorrentDmgAndDebuff     = 156297,   ///< Main target and 20s debuff
            AcidTorrentAura             = 156300,   ///< 2s aura
            AcidTorrentMissile          = 156309,   ///< Triggers 156324, needs aura
            /// Blackrock Barrage
            BlackrockSpines             = 156834,
            BlackrockBarrageAoE         = 173461,
            BlackrockBarrageTrigger     = 156878,
            /// Phase 2
            RollingFuryAura             = 155898,
            HungerDrivePeriodic         = 165127,
            EarthshakingCollision       = 155897,
            ConsumeBlackrockOre         = 155862,
            /// Spells for Mythic mode
            ExpelUnstableSlagSummon     = 155908,
            UnstableSlagExplosionAT     = 155910,
            ExpelUnstableSlagVisual     = 155916,
            UnstableSlagExplosionDmg    = 155923
        };

        enum eEvents
        {
            EventAcidMaw = 1,
            EventRetchedBlackrock,
            EventExplosiveShard,
            EventAcidTorrent,
            EventBlackrockSpines,
            EventBlackrockBarrage
        };

        enum eCosmeticEvents
        {
            EventCheckTrashs = 1,
            EventCollectOre,
            EventSoftEnrage
        };

        enum eCreatures
        {
            OreCrateCosmetic        = 79504,
            OreCrate                = 77252,
            DarkshardCrystalback    = 78233,
            DarkshardGnasher        = 78978,
            BlackrockOre            = 77261,
            UnstableSlag            = 77299
        };

        enum eDatas
        {
            DataMitigationPct,
            MovementInProgress,
            MovementFinished
        };

        enum eTalks
        {
            BlackrockBarrage,
            Phase2,
            ReturnToPhase1
        };

        enum ePhases
        {
            PhaseFight,
            PhaseRolling
        };

        struct boss_oregorgerAI : public BossAI
        {
            boss_oregorgerAI(Creature* p_Creature) : BossAI(p_Creature, eFoundryDatas::DataOregorger), m_Init(false), m_MoveIndex(0)
            {
                m_Instance = p_Creature->GetInstanceScript();
            }

            EventMap m_Events;
            EventMap m_CosmeticEvents;

            InstanceScript* m_Instance;

            bool m_Init;
            uint8 m_MoveIndex;

            bool m_VolatileOre;

            uint8 m_Phase;

            float m_MitigationPct;

            std::set<ObjectGuid> m_Crates;
            std::set<uint8> m_CratesToActivate;
            std::set<uint8> m_ActivatedCrates;
            uint8 m_ActivatedCratesCount;

            uint8 m_PointID;
            Position m_Destination;
            Position m_NextPos;

            /// Counter for Path Identifier reached
            uint8 m_PathCount;

            std::vector<G3D::Vector2> m_Path;

            std::set<ObjectGuid> m_BlackrockOres;

            ObjectGuid m_AcidTorrentTarget;

            void Reset() override
            {
               // ClearDelayedOperations();

                me->SetSpeed(UnitMoveType::MOVE_RUN, g_BaseRunSpeed);

                m_Events.Reset();
                m_CosmeticEvents.Reset();

                summons.DespawnAll();

                me->RemoveAura(eFoundrySpells::Berserker);
                me->RemoveAura(eSpells::BlackrockSpines);

                me->SetPower(Powers::POWER_MANA, 100);

                me->SetReactState(ReactStates::REACT_AGGRESSIVE);

                me->RemoveAllAreaTriggers();

                _Reset();

                if (!m_Init)
                    m_CosmeticEvents.ScheduleEvent(eCosmeticEvents::EventCheckTrashs, 1 * TimeConstants::IN_MILLISECONDS);
                else
                    me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE));

                m_Crates.clear();

                std::list<Creature*> l_CrateList;
                me->GetCreatureListWithEntryInGrid(l_CrateList, eCreatures::OreCrateCosmetic, 150.0f);

                for (Creature* l_Crate : l_CrateList)
                {
                    m_Crates.insert(l_Crate->GetGUID());
                    l_Crate->Respawn();
                }

                l_CrateList.clear();

                me->GetCreatureListWithEntryInGrid(l_CrateList, eCreatures::OreCrate, 150.0f);

                for (Creature* l_Crate : l_CrateList)
                    l_Crate->DespawnOrUnsummon();

                m_MoveIndex = 0;

                if (GameObject* l_Ore = ObjectAccessor::GetGameObject(*me, m_Instance->GetGuidData(eFoundryGameObjects::VolatileBlackrockOre)))
                {
                    l_Ore->Respawn();
                    l_Ore->AddFlag(GameObjectFlags::GO_FLAG_NOT_SELECTABLE);
                }

                m_VolatileOre = false;

                m_Phase = ePhases::PhaseFight;

                m_MitigationPct = 0.0f;

                m_CratesToActivate.clear();
                m_ActivatedCrates.clear();
                m_ActivatedCratesCount = 0;

                m_PointID = 255;
                m_Destination = Position();
                m_NextPos = Position();

                m_PathCount = 0;

                m_Path.clear();

                m_BlackrockOres.clear();

               // m_AcidTorrentTarget = 0;
                m_AcidTorrentTarget.Clear();
            }

            void JustSummoned(Creature* p_Summon) override
            {
                switch (p_Summon->GetEntry())
                {
                    case eCreatures::OreCrate:
                    {
                        p_Summon->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));
                        break;
                    }
                    case eCreatures::BlackrockOre:
                    {
                        m_BlackrockOres.insert(p_Summon->GetGUID());
                        p_Summon->SetReactState(ReactStates::REACT_PASSIVE);
                        p_Summon->AddUnitState(UnitState::UNIT_STATE_STUNNED);
                        p_Summon->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL | UnitFlags::UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_NOT_SELECTABLE));
                        p_Summon->AddUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));
                        break;
                    }
                    case eCreatures::UnstableSlag:
                    {
                        p_Summon->CastSpell(p_Summon, eSpells::ExpelUnstableSlagVisual, true);
                        break;
                    }
                    default:
                        break;
                }

                BossAI::JustSummoned(p_Summon);
            }

            void SummonedCreatureDespawn(Creature* p_Summon) override
            {
                if (p_Summon->GetEntry() == eCreatures::BlackrockOre)
                    m_BlackrockOres.erase(p_Summon->GetGUID());

                BossAI::SummonedCreatureDespawn(p_Summon);
            }

            bool CanRespawn()
            {
                return false;
            }

            void SetFData(uint32 p_ID, float p_Value)
            {
                switch (p_ID)
                {
                    case eDatas::DataMitigationPct:
                    {
                        m_MitigationPct = p_Value;
                        break;
                    }
                    default:
                        break;
                }
            }

            float GetFData(uint32 p_ID /*= 0*/) 
            {
                switch (p_ID)
                {
                    case eDatas::DataMitigationPct:
                        return m_MitigationPct;
                    default:
                        break;
                }

                return 0.0f;
            }

            void EnterCombat(Unit* /*p_Attacker*/) override
            {
                _EnterCombat();

                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me, 1);

                HandleFirstPhase();
            }

            void SetPower(Powers p_Power, int32 p_Value)
            {
                if (p_Power != Powers::POWER_MANA)
                    return;

                if (!me->IsInCombat())
                    return;

                /// Phase One lasts until Oregorger runs out of Mana, at which point he enters Phase Two.
                if (p_Value == 0 && m_Phase == ePhases::PhaseFight)
                {
                    m_Events.Reset();

                    me->SetSpeed(UnitMoveType::MOVE_RUN, g_P2RunSpeed);

                    Talk(eTalks::Phase2);

                    m_Phase = ePhases::PhaseRolling;

                    if (!m_VolatileOre && m_Instance != nullptr)
                    {
                        m_VolatileOre = true;

                        if (GameObject* l_Ore = ObjectAccessor::GetGameObject(*me, m_Instance->GetGuidData(eFoundryGameObjects::VolatileBlackrockOre)))
                            l_Ore->RemoveFlag(GameObjectFlags::GO_FLAG_NOT_SELECTABLE);
                    }

                  //  AddTimedDelayedOperation(2 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                  //  {
                        me->SetReactState(ReactStates::REACT_PASSIVE);
                        me->AttackStop();

                        std::pair<G3D::Vector2, uint8> l_PointData = GetNearestIntersectionPoint(me, 0.0f);
                        if (l_PointData.first.x != 0.0f && l_PointData.first.y != 0.0f)
                        {
                            me->GetMotionMaster()->Clear();
                           // me->GetMotionMaster()->MovePoint(eDatas::MovementFinished, G3D::Vector3(l_PointData.first, me->GetPositionZ()));

                            m_PointID = l_PointData.second;
                        }
                   // });

                    m_CratesToActivate.clear();

                   // AddTimedDelayedOperation(3 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                   // {
                        if (m_Crates.empty())
                        {
                            me->CastSpell(me, eSpells::WallshakingRoar, true);
                            return;
                        }

                        std::vector<uint8> l_OreCrateSpawns;

                        for (uint8 l_I = 0; l_I < eFoundryDatas::MaxOreCrateSpawns; ++l_I)
                            l_OreCrateSpawns.push_back(l_I);

                        Trinity::Containers::RandomShuffle(l_OreCrateSpawns);

                        /// In LFR difficulty, 16 Ore Crates will spawn, instead of 12, in the first  Rolling Fury phase. The uneaten Ore will remain for future phases.
                        uint8 l_Count = 16;// IsLFR() ? 16 : 12;

                        if ((l_Count + m_ActivatedCratesCount) > (int)eFoundryDatas::MaxOreCrateSpawns)
                            l_Count = (int)eFoundryDatas::MaxOreCrateSpawns - m_ActivatedCratesCount;

                        for (uint8 l_I : l_OreCrateSpawns)
                        {
                            if (m_ActivatedCrates.find(l_I) != m_ActivatedCrates.end())
                                continue;

                            if (l_Count <= 0)
                                break;

                            Creature* l_NearestCrate = nullptr;
                            float l_Dist = 100000.0f;
                            for (ObjectGuid l_Guid : m_Crates)
                            {
                                if (Creature* l_Crate = ObjectAccessor::GetCreature(*me, l_Guid))
                                {
                                    if (l_Crate->GetDistance(g_OreCrateSpawnPos[l_I]) < l_Dist)
                                    {
                                        l_NearestCrate = l_Crate;
                                        l_Dist = me->GetDistance(l_Crate);
                                    }
                                }
                            }

                            if (l_NearestCrate == nullptr)
                                return;

                            m_Crates.erase(l_NearestCrate->GetGUID());

                            //l_NearestCrate->CastSpell(g_OreCrateSpawnPos[l_I], eSpells::RollingBox, true);
                            l_NearestCrate->DespawnOrUnsummon(1 * TimeConstants::IN_MILLISECONDS);

                            --l_Count;
                            m_ActivatedCrates.insert(l_I);
                            m_CratesToActivate.insert(l_I);
                            ++m_ActivatedCratesCount;
                        }

                        me->CastSpell(me, eSpells::WallshakingRoar, true);
                  //  });

                   // AddTimedDelayedOperation(5 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                  //  {
                        for (uint8 l_I : m_CratesToActivate)
                        {
                            if (Creature* l_Crate = me->SummonCreature(eCreatures::OreCrate, g_OreCrateSpawnPos[l_I]))
                            {
                                l_Crate->SetReactState(ReactStates::REACT_PASSIVE);
                                l_Crate->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_NOT_SELECTABLE));
                                l_Crate->AddUnitState(UnitState::UNIT_STATE_STUNNED | UnitState::UNIT_STATE_ROOT);
                                l_Crate->AddUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));
                                l_Crate->ApplySpellImmune(0, SpellImmunity::IMMUNITY_EFFECT, SpellEffectName::SPELL_EFFECT_KNOCK_BACK, true);
                            }
                        }
                   // });

                   // AddTimedDelayedOperation(7 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                   // {
                        SelectPath();
                  //  });

                   // AddTimedDelayedOperation(8 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                   // {
                        me->CastSpell(me, eSpells::RollingFuryAura, true);
                        me->CastSpell(me, eSpells::HungerDrivePeriodic, true);

                        m_CosmeticEvents.ScheduleEvent(eCosmeticEvents::EventCollectOre, 200);

                        if (m_NextPos.m_positionX == 0.0f)
                        {
                            me->GetMotionMaster()->Clear();
                            me->GetMotionMaster()->MovePoint(eDatas::MovementFinished, m_Destination);
                        }
                        else
                        {
                            me->GetMotionMaster()->Clear();
                            me->GetMotionMaster()->MovePoint(eDatas::MovementInProgress, m_NextPos);
                        }
                  //  });
                }
                /// When Oregorger reaches full Mana, Phase One restarts.
                else if (p_Value == 100)
                {
                    me->SetSpeed(UnitMoveType::MOVE_RUN, g_BaseRunSpeed);

                    Talk(eTalks::ReturnToPhase1);

                    m_Phase = ePhases::PhaseFight;

                    me->RemoveAura(eSpells::HungerDrivePeriodic);
                    me->RemoveAura(eSpells::RollingFuryAura);

                    m_CosmeticEvents.CancelEvent(eCosmeticEvents::EventCollectOre);

                  //  AddTimedDelayedOperation(2 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                   // {
                        HandleFirstPhase();

                        me->SetReactState(ReactStates::REACT_AGGRESSIVE);

                        if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO))
                        {
                            me->GetMotionMaster()->Clear();

                            AttackStart(l_Target);
                        }
                 //   });
                }
            }

            void RegeneratePower(Powers /*p_Power*/, int32& p_Value) 
            {
                /// Oregorger only regens by script
                p_Value = 0;
            }

            void JustDied(Unit* /*p_Killer*/) override
            {
                _JustDied();

                m_Events.Reset();
                m_CosmeticEvents.Reset();

                summons.DespawnAll();

                me->RemoveAllAreaTriggers();

                if (m_Instance != nullptr)
                {
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::RetchedBlackrockDoT);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::AcidTorrentDmgAndDebuff);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::AcidMawDoT);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::ExplosiveShardAoE);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::CarryingVolatileBlackrock);

                    /// Allow loots and bonus loots to be enabled/disabled with a simple reload
                  //  if (sObjectMgr->IsDisabledEncounter(m_Instance->GetEncounterIDForBoss(me), GetDifficulty()))
                        me->AddLootRecipient(nullptr);
                  //  else
                        CastSpellToPlayers(me->GetMap(), me, eSpells::OregorgerBonusLoot, true);
                }
            }

            void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER)
            {
                m_Events.Reset();
                m_CosmeticEvents.Reset();

                me->RemoveAllAuras();

                me->RemoveAllAreaTriggers();

                me->InterruptNonMeleeSpells(true);

                /// Just in case, to prevent the fail Return to Home
                me->ClearUnitState(UnitState::UNIT_STATE_ROOT);
                me->ClearUnitState(UnitState::UNIT_STATE_DISTRACTED);
                me->ClearUnitState(UnitState::UNIT_STATE_STUNNED);

                CreatureAI::EnterEvadeMode();

                summons.DespawnAll();

                if (m_Instance != nullptr)
                {
                    m_Instance->SetBossState(eFoundryDatas::DataOregorger, EncounterState::FAIL);

                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::RetchedBlackrockDoT);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::AcidTorrentDmgAndDebuff);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::AcidMawDoT);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::ExplosiveShardAoE);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::CarryingVolatileBlackrock);
                }
            }

            void MovementInform(uint32 p_Type, uint32 p_ID) override
            {
                if (p_Type != MovementGeneratorType::POINT_MOTION_TYPE && p_Type != MovementGeneratorType::EFFECT_MOTION_TYPE)
                    return;

                /// Handle phase 2 movements in a specific way
                if (m_Phase == ePhases::PhaseRolling && me->HasAura(eSpells::RollingFuryAura))
                {
                    switch (p_ID)
                    {
                        case eDatas::MovementInProgress:
                        {
                            ++m_PathCount;

                            m_NextPos.m_positionX = m_Path[m_PathCount].x;
                            m_NextPos.m_positionY = m_Path[m_PathCount].y;
                            m_NextPos.m_positionZ = me->GetPositionZ();

                           // if (m_NextPos.IsNearPosition(&m_Destination, 1.0f))
                          //  {
                               // AddTimedDelayedOperation(50, [this]() -> void
                               // {
                                    me->GetMotionMaster()->MovePoint(eDatas::MovementFinished, m_Destination);
                               // });
                           // }
                          //  else
                           // {
                                //AddTimedDelayedOperation(50, [this]() -> void
                               // {
                                    me->GetMotionMaster()->MovePoint(eDatas::MovementInProgress, m_NextPos);
                                //});
                          //  }

                            break;
                        }
                        case eDatas::MovementFinished:
                        {
                            HandleCollisionPoint();
                            break;
                        }
                        default:
                            break;
                    }

                    return;
                }

                if (!me->IsInCombat())
                {
                    switch (p_Type)
                    {
                        case MovementGeneratorType::POINT_MOTION_TYPE:
                        {
                            if (m_MoveIndex >= eFoundryDatas::MaxOregorgerMovePos)
                            {
                                me->RemoveAura(eSpells::RollingFuryVisual);

                                //AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                              //  {
                                    me->GetMotionMaster()->MoveJump(g_JumpPos, 20.0f, 20.0f);
                              //  });
                            }
                            else
                            {
                              //  AddTimedDelayedOperation(100, [this]() -> void
                               // {
                                    me->GetMotionMaster()->MovePoint(m_MoveIndex, g_MovePos[m_MoveIndex]);
                                    ++m_MoveIndex;
                              //  });
                            }

                            break;
                        }
                        case MovementGeneratorType::EFFECT_MOTION_TYPE:
                        {
                            me->SetHomePosition(*me);
                            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE));

                            me->SetReactState(ReactStates::REACT_AGGRESSIVE);

                            std::list<Creature*> l_CrateList;
                            me->GetCreatureListWithEntryInGrid(l_CrateList, eCreatures::OreCrateCosmetic, 150.0f);

                            m_Crates.clear();

                            for (Creature* l_Crate : l_CrateList)
                                m_Crates.insert(l_Crate->GetGUID());

                            break;
                        }
                        default:
                            break;
                    }
                }
            }

            void OnSpellCasted(SpellInfo const* p_SpellInfo)
            {
                switch (p_SpellInfo->Id)
                {
                    case eSpells::ExplosiveShardMissile:
                    case eSpells::BlackrockBarrageAoE:
                    {
                        me->EnergizeBySpell(me, eSpells::RetchedBlackrockMissile, -5, Powers::POWER_MANA);
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
                    case eSpells::AcidTorrentSearcher:
                    {
                       // m_AcidTorrentTarget = 0;
                        m_AcidTorrentTarget.Clear();

                        me->SetFacingTo(me->GetAngle(p_Target));

                        /// Sprays a cone of acid at a random ranged foe, inflicting 475000 to 525000 Physical damage to the closest player
                        /// and increasing that player's damage taken from Acid Torrent by 475000 to 525000 for 20 sec.
                        /// p_Target is already the clotest player
                        /// Order here is important, debuff the main target to deals damage to him once
                        me->CastSpell(p_Target, eSpells::AcidTorrentDmgAndDebuff, true);

                        m_AcidTorrentTarget = p_Target->GetGUID();

                        /// Cast the cone triggered to add targetting aura to each players in that cone
                        me->CastSpell(p_Target, eSpells::AcidTorrentTriggered, true);

                        /// Add the targetting aura on boss, then cast the AoE spell which will affects only players with the aura
                        me->CastSpell(me, eSpells::AcidTorrentAura, true);

                        /// All other targets take up to 300000 Nature damage, reduced by the closest player's total damage mitigation.
                        me->CastSpell(me, eSpells::AcidTorrentMissile, true);

                        me->SetReactState(ReactStates::REACT_AGGRESSIVE);

                        if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO))
                        {
                            AttackStart(l_Target);

                            me->GetMotionMaster()->Clear();
                            me->GetMotionMaster()->MoveChase(l_Target);
                        }

                        break;
                    }
                    case eSpells::AcidTorrentScriptEffect:
                    {
                        /// Don't damage main target twice
                        if (p_Target->GetGUID() == m_AcidTorrentTarget)
                            break;

                        me->CastSpell(p_Target, eSpells::AcidTorrentAura, true);
                        break;
                    }
                    case eSpells::BlackrockBarrageAoE:
                    {
                        if (p_Target == me)
                            break;

                        me->CastSpell(p_Target, eSpells::BlackrockBarrageTrigger, true);
                        break;
                    }
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 p_Diff) override
            {
               // UpdateOperations(p_Diff);

                m_CosmeticEvents.Update(p_Diff);

                switch (m_CosmeticEvents.ExecuteEvent())
                {
                    case eCosmeticEvents::EventCheckTrashs:
                    {
                        std::list<Creature*> l_CreatureList;
                        me->GetCreatureListWithEntryInGrid(l_CreatureList, eCreatures::DarkshardCrystalback, 150.0f);
                        me->GetCreatureListWithEntryInGrid(l_CreatureList, eCreatures::DarkshardGnasher, 150.0f);

                        bool l_IsEmpty = l_CreatureList.empty();

                        if (!l_IsEmpty)
                        {
                            l_CreatureList.remove_if([this](Creature* p_Creature) -> bool
                            {
                                if (p_Creature == nullptr || !p_Creature->IsAlive())
                                    return true;
    
                                return false;
                            });
                        }
                        
                        l_IsEmpty = l_CreatureList.empty();

                        /// All trashes are dead, launch move
                        if (l_IsEmpty)
                        {
                            m_Init = true;

                            me->CastSpell(me, eSpells::RollingFuryVisual, true);
                            me->SetReactState(ReactStates::REACT_PASSIVE);

                            me->GetMotionMaster()->Clear();
                            me->GetMotionMaster()->MovePoint(m_MoveIndex, g_MovePos[m_MoveIndex]);

                            ++m_MoveIndex;
                        }

                        if (!m_Init)
                            m_CosmeticEvents.ScheduleEvent(eCosmeticEvents::EventCheckTrashs, 1 * TimeConstants::IN_MILLISECONDS);

                        break;
                    }
                    case eCosmeticEvents::EventCollectOre:
                    {
                        if (Creature* l_Ore = me->FindNearestCreature(eCreatures::BlackrockOre, 2.0f))
                        {
                            l_Ore->DespawnOrUnsummon();
                            me->CastSpell(me, eSpells::ConsumeBlackrockOre, true);
                        }

                        if (!me->HasAura(eSpells::HungerDrivePeriodic))
                            break;

                        m_CosmeticEvents.ScheduleEvent(eCosmeticEvents::EventCollectOre, 200);
                        break;
                    }
                    case eCosmeticEvents::EventSoftEnrage:
                    {
                        m_Phase = ePhases::PhaseFight;

                        me->RemoveAura(eSpells::HungerDrivePeriodic);
                        me->RemoveAura(eSpells::RollingFuryAura);

                        m_Events.Reset();
                        m_CosmeticEvents.Reset();

                        me->CastSpell(me, eSpells::EarthshakingStomp, false);
                        m_CosmeticEvents.ScheduleEvent(eCosmeticEvents::EventSoftEnrage, 1 * TimeConstants::IN_MILLISECONDS + 500);
                        break;
                    }
                    default:
                        break;
                }

                if (!UpdateVictim() || m_Phase == ePhases::PhaseRolling)
                    return;

                m_Events.Update(p_Diff);

                if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                    return;

                switch (m_Events.ExecuteEvent())
                {
                    case eEvents::EventAcidMaw:
                    {
                        if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO))
                            me->CastSpell(l_Target, eSpells::AcidMawDoT, true);

                        m_Events.ScheduleEvent(eEvents::EventAcidMaw, 6 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case eEvents::EventRetchedBlackrock:
                    {
                        //if (Unit* l_Target = SelectRangedTarget())
                            me->CastSpell(me, eSpells::RetchedBlackrockMissile, false);

                        m_Events.ScheduleEvent(eEvents::EventRetchedBlackrock, 15 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case eEvents::EventExplosiveShard:
                    {
                       // if (Unit* l_Target = SelectMeleeTarget())
                            me->CastSpell(me, eSpells::ExplosiveShardMissile, true);

                        m_Events.ScheduleEvent(eEvents::EventExplosiveShard, 15 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case eEvents::EventAcidTorrent:
                    {
                        me->SetReactState(ReactStates::REACT_PASSIVE);
                        me->CastSpell(me, eSpells::AcidTorrentSearcher, false);
                        m_Events.ScheduleEvent(eEvents::EventAcidTorrent, 13 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case eEvents::EventBlackrockSpines:
                    {
                        if (Aura* l_Aura = me->AddAura(eSpells::BlackrockSpines, me))
                            l_Aura->ModStackAmount(5);// IsMythic() ? 5 : 3);

                        Talk(eTalks::BlackrockBarrage);
                        m_Events.ScheduleEvent(eEvents::EventBlackrockSpines, 19 * TimeConstants::IN_MILLISECONDS);
                        m_Events.ScheduleEvent(eEvents::EventBlackrockBarrage, 1 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case eEvents::EventBlackrockBarrage:
                    {
                       // if (Aura* l_Aura = me->GetAura(eSpells::BlackrockSpines))
                          //  l_Aura->DropStack();
                       // else
                         //   break;

                        me->CastSpell(me, eSpells::BlackrockBarrageAoE, false);
                        m_Events.ScheduleEvent(eEvents::EventBlackrockBarrage, 2 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }

            void HandleFirstPhase()
            {
                m_Events.ScheduleEvent(eEvents::EventAcidMaw, 3 * TimeConstants::IN_MILLISECONDS);
                m_Events.ScheduleEvent(eEvents::EventRetchedBlackrock, 6 * TimeConstants::IN_MILLISECONDS);
                m_Events.ScheduleEvent(eEvents::EventExplosiveShard, 9 * TimeConstants::IN_MILLISECONDS);
                m_Events.ScheduleEvent(eEvents::EventAcidTorrent, 12 * TimeConstants::IN_MILLISECONDS);
                m_Events.ScheduleEvent(eEvents::EventBlackrockSpines, 14 * TimeConstants::IN_MILLISECONDS);

                if (me->HasAura(eSpells::BlackrockSpines))
                    m_Events.ScheduleEvent(eEvents::EventBlackrockBarrage, 100);

                m_CosmeticEvents.RescheduleEvent(eCosmeticEvents::EventSoftEnrage, 7 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS);
            }

            uint8 GetCollisionOrIntersectionPoint(uint8 p_I, uint8 p_J) const
            {
                for (uint8 l_I = 0; l_I < eFoundryDatas::MaxOregorgerCollisions; ++l_I)
                {
                    if (g_CollisionPoints[l_I].I == p_I && g_CollisionPoints[l_I].J == p_J)
                        return l_I;
                }

                return 255;
            }

            std::pair<G3D::Vector2, uint8> GetNearestIntersectionPoint(Creature* p_Source, float p_MinDist = 1.0f) const
            {
                float l_Dist = 100000.0f;

                G3D::Vector2 l_Point = G3D::Vector2(0.0f, 0.0f);
                uint8 l_PointID = 0;

                Position l_Pos;
                l_Pos.m_positionZ = p_Source->GetPositionZ();

                /// Check position X for each part of X axis
                for (uint8 l_I = 0; l_I < eFoundryDatas::MaxOregorgerPatterns; ++l_I)
                {
                    float l_X = g_OregorgerPatternsX[l_I];

                    /// When X part is found, search for the Y part
                    for (uint8 l_J = 0; l_J < eFoundryDatas::MaxOregorgerPatterns; ++l_J)
                    {
                        uint8 l_CollisionID = GetCollisionOrIntersectionPoint(l_I, l_J);

                        /// Some points must be bypassed, and some others aren't collision or intersection (it's the same here) points
                        if (g_BypassPoints[l_I][l_J] || l_CollisionID == 255)
                            continue;

                        float l_Y = g_OregorgerPatternsY[l_J];

                        /// Y part is found too, then we can calculate the middle position of the square
                        float l_CenterX, l_CenterY;

                        l_CenterX = (l_X + (l_I > 0 ? g_OregorgerPatternsX[l_I - 1] : 0.0f)) / 2.0f;
                        l_CenterY = (l_Y + (l_J > 0 ? g_OregorgerPatternsY[l_J - 1] : 0.0f)) / 2.0f;

                        l_Pos.m_positionX = l_CenterX;
                        l_Pos.m_positionY = l_CenterY;

                        if (p_Source->GetDistance(l_Pos) >= p_MinDist && p_Source->GetDistance(l_Pos) < l_Dist)
                        {
                            l_Dist = p_Source->GetDistance(l_Pos);
                            l_Point = G3D::Vector2(l_CenterX, l_CenterY);
                            l_PointID = l_CollisionID;
                        }
                    }
                }

                return std::make_pair(l_Point, l_PointID);
            }

            uint8 GetRandomCollisionPoint() const
            {
                if (m_PointID == 255)
                    return m_PointID;

                std::pair<uint8, uint8> l_Choices = g_LinkedCollisionPoints[m_PointID];
                uint8 l_ID = 0;

                /////////////////////////////////////////////////////////////////////
                /// Try to choose a point with Blackrock ores to eat
                if (!m_BlackrockOres.empty())
                {
                    std::vector<G3D::Vector2> const l_FirstPath     = g_MovementPaths[m_PointID][l_Choices.first - 1];
                    std::vector<G3D::Vector2> const l_SecondPath    = g_MovementPaths[m_PointID][l_Choices.second - 1];

                    if (l_FirstPath.empty() || l_SecondPath.empty())
                    {
                       // ACE_ASSERT (false && "boss_oregorgerAI::GetRandomCollisionPoint => RollingPath found is empty");
                        return m_PointID;
                    }

                    uint8 l_CenterCount = 0;
                    uint8 l_OutterCount = 0;

                    for (ObjectGuid l_Guid : m_BlackrockOres)
                    {
                        if (Creature* l_Ore = ObjectAccessor::GetCreature(*me, l_Guid))
                        {
                            /// Count the ores
                            if (IsCenterPos(l_Ore->m_positionX, l_Ore->m_positionY))
                                l_CenterCount++;
                            else
                                l_OutterCount++;
                        }
                    }

                    Position l_Position;
                    l_Position.m_positionX = l_FirstPath[l_FirstPath.size() - 1].x;
                    l_Position.m_positionY = l_FirstPath[l_FirstPath.size() - 1].y;
                    l_Position.m_positionZ = me->GetPositionZ();

                    /// If more ores at center than at outer of the room, move to center
                    /// If it's equal, move to center, fastest way
                    /// If first choice is center, second choice will always be outer
                    if (l_CenterCount > l_OutterCount || l_CenterCount == l_OutterCount)
                    {
                        if (IsCenterPos(l_Position.m_positionX, l_Position.m_positionY))
                            l_ID = l_Choices.first;
                        else
                            l_ID = l_Choices.second;
                    }
                    /// If more ores at outer than at center of the room, move to outer
                    else
                    {
                        if (!IsCenterPos(l_Position.m_positionX, l_Position.m_positionY))
                            l_ID = l_Choices.first;
                        else
                            l_ID = l_Choices.second;
                    }
                }
                /// If no ore to eat, choose randomly
                else
                {
                    if (urand(0, 1))
                        l_ID = l_Choices.first;
                    else
                        l_ID = l_Choices.second;
                }
                /////////////////////////////////////////////////////////////////////

                return --l_ID;
            }

            bool IsCenterPos(float p_X, float p_Y) const
            {
                /// We need to know if a specific point is in the center of the room, or not
                /// The rolling direction will change depending on that
                /// If it's the room's center, Oregorger will rolls clockwise
                for (uint8 l_I = 0; l_I < eFoundryDatas::MaxOregorgerPatterns; ++l_I)
                {
                    if (p_X > g_OregorgerPatternsX[l_I])
                        continue;

                    for (uint8 l_J = 0; l_J < eFoundryDatas::MaxOregorgerPatterns; ++l_J)
                    {
                        if (p_Y > g_OregorgerPatternsY[l_J])
                            continue;

                        if (l_I >= 2 && l_I <= 4 && l_J >= 2 && l_J <= 4)
                            return true;
                        else
                            return false;
                    }
                }

                return false;
            }

            void SelectPath()
            {
                /// At this point, Oregorger is at an intersection point
                /// Choose in priority paths with one or more Blackrock Ore to eat
                uint8 l_OldID = m_PointID;

                m_PointID = GetRandomCollisionPoint();

                std::vector<G3D::Vector2> const l_Path = g_MovementPaths[l_OldID][m_PointID];

                if (l_Path.empty())
                {
                   // ACE_ASSERT (false && "boss_oregorgerAI::SelectPath => RollingPath found is empty");
                    return;
                }

                m_PathCount = 0;

                m_Path = l_Path;

                m_Destination.m_positionX = l_Path[l_Path.size() - 1].x;
                m_Destination.m_positionY = l_Path[l_Path.size() - 1].y;
                m_Destination.m_positionZ = me->GetPositionZ();

                /// At center, moves are always on a front lines, directly setup destination
                if (l_Path.size() == 1)
                {
                    m_NextPos = Position();

                    me->SetFacingTo(me->GetAngle(&m_Destination));
                }
                else
                {
                    float l_O = 0.0f;

                    m_NextPos.m_positionX = l_Path[m_PathCount].x;
                    m_NextPos.m_positionY = l_Path[m_PathCount].y;
                    m_NextPos.m_positionZ = me->GetPositionZ();

                    l_O += me->GetAngle(&m_NextPos);

                    me->SetFacingTo(l_O);
                }
            }

            void HandleCollisionPoint()
            {
                me->RemoveAura(eSpells::RollingFuryAura);

                me->CastSpell(me, eSpells::EarthshakingCollision, true);

                /// In Mythic difficulty, these collisions also leave Unstable Slag residue at the location of the collision.
                /// Unstable Slag explodes if another collision occurs at the same location.
               // if (IsMythic())
               // {
                    if (Creature* l_Slag = me->FindNearestCreature(eCreatures::UnstableSlag, 2.0f))
                    {
                        l_Slag->CastSpell(l_Slag, eSpells::UnstableSlagExplosionAT, true);

                        //////////////////////////////////////////////////////////////////////////
                        /// MISSING AREATRIGGER TEMPLATE DATAS FOR MYTHIC
                        //////////////////////////////////////////////////////////////////////////
                    }
                    else
                        me->CastSpell(me, eSpells::ExpelUnstableSlagSummon, true);
              //  }

              //  AddTimedDelayedOperation(2 * TimeConstants::IN_MILLISECONDS, [this]() -> void
               // {
                    SelectPath();
               // });

              //  AddTimedDelayedOperation(4 * TimeConstants::IN_MILLISECONDS, [this]() -> void
              //  {
                    me->CastSpell(me, eSpells::RollingFuryAura, true);

                    if (m_NextPos.m_positionX == 0.0f)
                    {
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MovePoint(eDatas::MovementFinished, m_Destination);
                    }
                    else
                    {
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MovePoint(eDatas::MovementInProgress, m_NextPos);
                    }
               // });
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new boss_oregorgerAI(p_Creature);
        }
};

/// Crate Ore - 77252
class npc_foundry_crate_ore : public CreatureScript
{
    public:
        npc_foundry_crate_ore() : CreatureScript("npc_foundry_crate_ore") { }

        struct npc_foundry_crate_oreAI : public ScriptedAI
        {
            npc_foundry_crate_oreAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

            enum eCreature
            {
                BlackrockOre = 77261
            };

            enum eVisual
            {
                BlackrockOreVisual = 37247
            };

            enum eSpell
            {
                CrateGlow = 160691
            };

            void Reset() override
            {
                me->CastSpell(me, eSpell::CrateGlow, true);
            }

            void JustDied(Unit* /*p_Killer*/) override
            {
                me->RemoveAllAuras();

                me->DespawnOrUnsummon();

                if (InstanceScript* l_Instance = me->GetInstanceScript())
                {
                    if (Creature* l_Oregorger = ObjectAccessor::GetCreature(*me, l_Instance->GetGuidData(eFoundryCreatures::BossOregorger)))
                    {
                        if (Creature* l_Ore = l_Oregorger->SummonCreature(eCreature::BlackrockOre, *me))
                            l_Ore->SendPlaySpellVisual(Position(), 0.0f, eVisual::BlackrockOreVisual,0.0f,0.F,0.F);
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_crate_oreAI(p_Creature);
        }
};

/// Acid Torrent - 156297
class spell_foundry_acid_torrent : public SpellScriptLoader
{
    public:
        spell_foundry_acid_torrent() : SpellScriptLoader("spell_foundry_acid_torrent") { }

        class spell_foundry_acid_torrent_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_foundry_acid_torrent_SpellScript);

            enum eData
            {
                DamageMitigationPct
            };

            uint32 m_Damage;

            bool Load() override
            {
                m_Damage = 0;
                return true;
            }

            void HandleDamage(SpellEffIndex /*p_EffIndex*/)
            {
                m_Damage = GetHitDamage();
            }

            void HandleAfterHit()
            {
                uint32 l_Damage = GetHitDamage();

                if (m_Damage == l_Damage)
                    return;
                else if (m_Damage > l_Damage && m_Damage > 0)
                {
                    float l_Pct = (float)l_Damage / (float)m_Damage;

                    if (Creature* l_Oregorger = GetCaster()->ToCreature())
                    {
                        if (!l_Oregorger->IsAIEnabled)
                            return;

                        l_Oregorger->AI()->SetData(eData::DamageMitigationPct, l_Pct);
                    }
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_foundry_acid_torrent_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
                AfterHit += SpellHitFn(spell_foundry_acid_torrent_SpellScript::HandleAfterHit);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_foundry_acid_torrent_SpellScript();
        }
};

/// Acid Torrent (AoE) - 156324
class spell_foundry_acid_torrent_aoe : public SpellScriptLoader
{
    public:
        spell_foundry_acid_torrent_aoe() : SpellScriptLoader("spell_foundry_acid_torrent_aoe") { }

        class spell_foundry_acid_torrent_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_foundry_acid_torrent_aoe_SpellScript);

            enum eData
            {
                DamageMitigationPct
            };

            void HandleDamage(SpellEffIndex /*p_EffIndex*/)
            {
                if (Creature* l_Oregorger = GetCaster()->ToCreature())
                {
                    if (!l_Oregorger->IsAIEnabled)
                        return;

                    float l_Pct = l_Oregorger->AI()->GetData(eData::DamageMitigationPct);
                    float l_Dmg = (float)GetHitDamage();

                    l_Dmg *= l_Pct;
                    SetHitDamage((int32)l_Dmg);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_foundry_acid_torrent_aoe_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_foundry_acid_torrent_aoe_SpellScript();
        }
};

/// Acid Torrent (Searcher) - 156240
class spell_foundry_acid_torrent_searcher : public SpellScriptLoader
{
    public:
        spell_foundry_acid_torrent_searcher() : SpellScriptLoader("spell_foundry_acid_torrent_searcher") { }

        class spell_foundry_acid_torrent_searcher_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_foundry_acid_torrent_searcher_SpellScript);

            void CorrectTargets(std::list<WorldObject*>& p_Targets)
            {
                if (p_Targets.empty())
                    return;

                Unit* l_Caster = GetCaster();
                if (l_Caster == nullptr)
                    return;

                WorldObject* l_Object = l_Caster->GetVictim();

                p_Targets.clear();
                p_Targets.push_back(l_Object);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_foundry_acid_torrent_searcher_SpellScript::CorrectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_foundry_acid_torrent_searcher_SpellScript();
        }
};

/// Rolling Fury - 155898
class spell_foundry_rolling_fury_aura : public SpellScriptLoader
{
    public:
        spell_foundry_rolling_fury_aura() : SpellScriptLoader("spell_foundry_rolling_fury_aura") { }

        class spell_foundry_rolling_fury_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_foundry_rolling_fury_aura_AuraScript);

            enum eSpell
            {
                RollingFuryDamage = 155900
            };

            enum ePhases
            {
                PhaseRolling = 1
            };

            uint32 m_DamageTimer;

            bool Load() override
            {
                if (Unit* l_Caster = GetCaster())
                {
                    if (Creature* l_Boss = l_Caster->ToCreature())
                    {
                        if (!l_Boss->IsAIEnabled)
                            return false;

                        if (boss_oregorger::boss_oregorgerAI* l_AI = CAST_AI(boss_oregorger::boss_oregorgerAI, l_Boss->GetAI()))
                        {
                            if (l_AI->m_Phase != ePhases::PhaseRolling)
                                return false;
                        }
                        else
                            return false;
                    }
                    else
                        return false;
                }
                else
                    return false;

                m_DamageTimer = 1 * TimeConstants::IN_MILLISECONDS;
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
                            float l_Radius = 0.01f;

                            Trinity::AnyUnfriendlyUnitInObjectRangeCheck l_Check(l_Caster, l_Caster, l_Radius);
                            Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> l_Searcher(l_Caster, l_TargetList, l_Check);
                           // l_Caster->VisitNearbyObject(l_Radius, l_Searcher);

                            for (Unit* l_Iter : l_TargetList)
                                l_Iter->CastSpell(l_Iter, eSpell::RollingFuryDamage, true, nullptr, nullptr, l_Caster->GetGUID());
                        }

                        m_DamageTimer = 1 * TimeConstants::IN_MILLISECONDS;
                    }
                    else
                        m_DamageTimer -= p_Diff;
                }
            }

            void Register() override
            {
             //   OnAuraUpdate += AuraUpdateFn(spell_foundry_rolling_fury_aura_AuraScript::OnUpdate);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_foundry_rolling_fury_aura_AuraScript();
        }
};

/// Harvest Volatile Blackrock - 163453
class spell_foundry_harvest_volatile_blackrock : public SpellScriptLoader
{
    public:
        spell_foundry_harvest_volatile_blackrock() : SpellScriptLoader("spell_foundry_harvest_volatile_blackrock") { }

        class spell_foundry_harvest_volatile_blackrock_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_foundry_harvest_volatile_blackrock_SpellScript);

            enum eSpell
            {
                CarryingVolatileBlackrock = 163454
            };

            void HandleScript(SpellEffIndex /*p_EffIndex*/)
            {
                if (Unit* l_Caster = GetCaster())
                    l_Caster->CastSpell(l_Caster, eSpell::CarryingVolatileBlackrock, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_foundry_harvest_volatile_blackrock_SpellScript::HandleScript, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_foundry_harvest_volatile_blackrock_SpellScript();
        }
};

/// Throw Volatile Ore - 163455
class spell_foundry_throw_volatile_ore : public SpellScriptLoader
{
    public:
        spell_foundry_throw_volatile_ore() : SpellScriptLoader("spell_foundry_throw_volatile_ore") { }

        class spell_foundry_throw_volatile_ore_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_foundry_throw_volatile_ore_SpellScript);

            enum eSpell
            {
                CarryingVolatileBlackrock = 163454
            };

            void HandleAfterCast()
            {
                if (Unit* l_Caster = GetCaster())
                    l_Caster->RemoveAura(eSpell::CarryingVolatileBlackrock);
            }

            void Register() override
            {
                AfterCast += SpellCastFn(spell_foundry_throw_volatile_ore_SpellScript::HandleAfterCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_foundry_throw_volatile_ore_SpellScript();
        }
};

/// Retched Blackrock - 156186
class areatrigger_foundry_retched_blackrock : public AreaTriggerEntityScript
{
    public:
        areatrigger_foundry_retched_blackrock() : AreaTriggerEntityScript("areatrigger_foundry_retched_blackrock") { }

        enum eSpell
        {
            RetchedBlackrockDoT = 156203
        };

        std::set<ObjectGuid> m_AffectedPlayers;

        void OnUpdate(AreaTrigger* p_AreaTrigger, uint32 /*p_Time*/)
        {
            if (Unit* l_Caster = p_AreaTrigger->GetCaster())
            {
                std::list<Unit*> l_TargetList;
                float l_Radius = 6.5f;

                Trinity::AnyUnfriendlyUnitInObjectRangeCheck l_Check(p_AreaTrigger, l_Caster, l_Radius);
                Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> l_Searcher(p_AreaTrigger, l_TargetList, l_Check);
              //  p_AreaTrigger->VisitNearbyObject(l_Radius, l_Searcher);

                std::set<ObjectGuid> l_Targets;

                for (Unit* l_Iter : l_TargetList)
                {
                    l_Targets.insert(l_Iter->GetGUID());

                    if (!l_Iter->HasAura(eSpell::RetchedBlackrockDoT))
                    {
                        m_AffectedPlayers.insert(l_Iter->GetGUID());
                        l_Iter->CastSpell(l_Iter, eSpell::RetchedBlackrockDoT, true);
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
                        l_Unit->RemoveAura(eSpell::RetchedBlackrockDoT);

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
                        l_Unit->RemoveAura(eSpell::RetchedBlackrockDoT);
                }
            }
        }
        /*
        AreaTriggerEntityScript* GetAI()
        {
            return nullptr;
        }*/
};

/// Explosive Shard - 156388
class areatrigger_foundry_explosive_shard : public AreaTriggerEntityScript
{
    public:
        areatrigger_foundry_explosive_shard() : AreaTriggerEntityScript("areatrigger_foundry_explosive_shard") { }

        enum eSpell
        {
            ExplosiveShardAoE = 156374
        };

        void OnRemove(AreaTrigger* p_AreaTrigger, uint32 /*p_Time*/)
        {
           // if (Unit* l_Caster = p_AreaTrigger->GetCaster())
               // l_Caster->CastSpell(*p_AreaTrigger, eSpell::ExplosiveShardAoE, true);
        }
        /*
        AreaTriggerEntityScript* GetAI() 
        {
            return nullptr;
        }*/
};

/// Volatile Blackrock Ore - 237308
class go_foundry_volatile_blackrock_ore : public GameObjectScript
{
    public:
        go_foundry_volatile_blackrock_ore() : GameObjectScript("go_foundry_volatile_blackrock_ore") { }

        enum eSpell
        {
            HarvestVolatileBlackrock = 163453
        };

        struct go_foundry_volatile_blackrock_oreAI : public GameObjectAI
        {
            go_foundry_volatile_blackrock_oreAI(GameObject* p_GameObject) : GameObjectAI(p_GameObject), m_Activated(false) { }

            bool m_Activated;

            bool GossipHello(Player* p_Player , bool /*isUse*/)
            {
                if (!m_Activated)
                {
                    m_Activated = true;
                    p_Player->CastSpell(go, eSpell::HarvestVolatileBlackrock, false);
                }

                return false;
            }

            void OnStateChanged(uint32 /*p_State*/, Unit* /*unit*/)
            {
                if (m_Activated)
                {
                  //  AddTimedDelayedOperation(3 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                  //  {
                        go->AddFlag(GameObjectFlags::GO_FLAG_NOT_SELECTABLE);
                  //  });
                }
            }

            void UpdateAI(uint32 p_Diff) override
            {
              //  UpdateOperations(p_Diff);
            }
        };

        GameObjectAI* GetAI(GameObject* p_GameObject) const override
        {
            return new go_foundry_volatile_blackrock_oreAI(p_GameObject);
        }
};

/// Ore Grinder - 231313
class go_founrdy_ore_grinder : public GameObjectScript
{
    public:
        go_founrdy_ore_grinder() : GameObjectScript("go_founrdy_ore_grinder") { }

        struct go_founrdy_ore_grinderAI : public GameObjectAI
        {
            go_founrdy_ore_grinderAI(GameObject* p_GameObject) : GameObjectAI(p_GameObject) { }

            enum eSpells
            {
                CompleteTheAchievement      = 163569,
                CarryingVolatileBlackrock   = 163454
            };

            bool GossipHello(Player* p_Player, bool /*isUse*/)
            {
                if (p_Player->HasAura(eSpells::CarryingVolatileBlackrock))
                {
                    p_Player->CastSpell(p_Player, eSpells::CompleteTheAchievement, true);

                    if (InstanceScript* l_Instance = p_Player->GetInstanceScript())
                        l_Instance->SetData(eFoundryDatas::VolatileOreGrinded, 1);
                }

                return false;
            }
        };

        GameObjectAI* GetAI(GameObject* p_GameObject) const override
        {
            return new go_founrdy_ore_grinderAI(p_GameObject);
        }
};

void AddSC_boss_oregorger()
{
    /// Boss
    new boss_oregorger();/// Oregorger <The Devourer> - 77182

    /// NPC
    new npc_foundry_crate_ore();/// Crate Ore - 77252

    /// Spells
    new spell_foundry_acid_torrent();/// Acid Torrent - 156297
    new spell_foundry_acid_torrent_aoe();/// Acid Torrent (AoE) - 156324
    new spell_foundry_acid_torrent_searcher();/// Acid Torrent (Searcher) - 156240
    new spell_foundry_rolling_fury_aura();/// Rolling Fury - 155898
    new spell_foundry_harvest_volatile_blackrock();/// Harvest Volatile Blackrock - 163453
    new spell_foundry_throw_volatile_ore();/// Throw Volatile Ore - 163455

    /// AreaTriggers
    new areatrigger_foundry_retched_blackrock();/// Retched Blackrock - 156186
    new areatrigger_foundry_explosive_shard();/// Explosive Shard - 156388

    /// GameObjects
    new go_foundry_volatile_blackrock_ore();/// Volatile Blackrock Ore - 237308
    new go_founrdy_ore_grinder();/// Ore Grinder - 231313
}
