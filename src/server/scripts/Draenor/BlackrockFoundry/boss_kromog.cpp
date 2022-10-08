#include "boss_kromog.h"

/// Kromog <Legend of the Mountain> - 77692
class boss_kromog : public CreatureScript
{
    public:
        boss_kromog() : CreatureScript("boss_kromog") { }

        enum eTalks
        {
            TalkAggro,
            TalkAbility,
            TalkThunderingBlows,
            TalkSlay,
            TalkFrenzy,
            TalkDeath,
            TalkRipplingSmash,
            TalkGraspingEarth
        };

        enum eSpells
        {
            /// Misc
            StoneBreathChannel          = 156852,
            WarpedArmor                 = 156766,
            Slam                        = 156704,
            Frenzy                      = 156861,
            FistsOfStone                = 162348,
            ThunderingBlows             = 157054,
            ReverberationsAreaTrigger   = 157246,
            ShatteredEarthDamage        = 161893,
            KromogBonusLoot             = 177535,
            /// Rippling Smash
            RipplingSmashSearcher       = 161049,
            RipplingSmashCast           = 157592,
            /// Rune of Grasping Earth
            RuneOfGraspingEarthCast     = 157060,
            RuneOfGraspingEarthVehicle  = 157212
        };

        enum eEvents
        {
            EventCheckMeleePlayers = 1,
            EventBerserker,
            EventStoneBreath,
            EventWarpedArmor,
            EventSlam,
            EventRipplingSmash,
            EventGraspingEarth,
            EventThunderingBlows,
            EventCrushingEarth,
            EventReverberation,
            EventShatteredEarth
        };

        enum eTimers
        {
            TimerFirstCheckMeleePlayers = 5 * TimeConstants::IN_MILLISECONDS,
            TimerCheckMeleePlayers      = 500,
            TimerBerserker              = 540 * TimeConstants::IN_MILLISECONDS,
            TimerAbilityTalk            = 40,
            TimerStoneBreath            = 9 * TimeConstants::IN_MILLISECONDS,
            TimerStoneBreathAgain       = 24 * TimeConstants::IN_MILLISECONDS,
            TimerStoneBreathSecLFR      = 28 * TimeConstants::IN_MILLISECONDS,
            TimerStoneBreathSecond      = 31 * TimeConstants::IN_MILLISECONDS,
            TimerWarpedArmor            = 14 * TimeConstants::IN_MILLISECONDS,
            TimerWarpedArmorFrenzied    = 10 * TimeConstants::IN_MILLISECONDS + 200,
            TimerSlam                   = 18 * TimeConstants::IN_MILLISECONDS,
            TimerSlamAgain              = 23 * TimeConstants::IN_MILLISECONDS,
            TimerRipplingSmash          = 23 * TimeConstants::IN_MILLISECONDS + 500,
            TimerRipplingSmashFrenzied  = 18 * TimeConstants::IN_MILLISECONDS + 200,
            TimerRipplingSmashAgain     = 21 * TimeConstants::IN_MILLISECONDS,
            TimerRipplingSmashSec       = 35 * TimeConstants::IN_MILLISECONDS,
            TimerGraspingEarth          = 50 * TimeConstants::IN_MILLISECONDS,
            TimerGraspingEarthAgain     = 112 * TimeConstants::IN_MILLISECONDS,
            TimerThunderingBlows        = 12 * TimeConstants::IN_MILLISECONDS,
            TimerThunderingBlowsDelay   = 31 * TimeConstants::IN_MILLISECONDS,
            TimerCrushingEarth          = 25 * TimeConstants::IN_MILLISECONDS,
            TimerCrushingEarthAgain     = 16 * TimeConstants::IN_MILLISECONDS,
            TimerAttackTime             = 2 * TimeConstants::IN_MILLISECONDS,
            TimerAttackTimeFrenzied     = 1 * TimeConstants::IN_MILLISECONDS + 600
        };

        enum eActions
        {
            ActionRipplingSmash,
            ActionCrushingEarth
        };

        enum eCreatures
        {
            RipplingSmashTrigger    = 78055,
            GraspingEarthTrigger    = 77893,
            RuneOfCrushingEarth     = 77844,
            StoneWallRight          = 79806,
            StoneWallLeft           = 77842,
            ReverberationTrigger    = 77929
        };

        struct boss_kromogAI : public BossAI
        {
            boss_kromogAI(Creature* p_Creature) : BossAI(p_Creature, eFoundryDatas::DataKromog)
            {
                m_Instance  = p_Creature->GetInstanceScript();

                m_CheckZTimer = 1 * TimeConstants::IN_MILLISECONDS;
            }

            InstanceScript* m_Instance;

            EventMap m_Events;

            std::set<ObjectGuid> m_RipplingSmashTriggers;
            std::set<ObjectGuid> m_GraspingEarthTriggers;

            int32 m_FrenzyHealthPct;

            uint32 m_AbilityTalkTime;

            bool m_CrushingEarthBoom;

            uint32 m_CheckZTimer;

            bool CanRespawn()
            {
                return false;
            }

            void OnCalculateAttackDistance(float& p_AttackDistance)
            {
                p_AttackDistance = 10.0f;
            }

            void Reset() override
            {
               // ClearDelayedOperations();

                summons.DespawnAll();

                _Reset();

                me->RemoveAllAreaTriggers();

              //  me->DespawnCreaturesInArea({ eCreatures::StoneWallRight, eCreatures::StoneWallLeft });
              //  me->DespawnAreaTriggersInArea( eSpells::ReverberationsAreaTrigger );

                m_Events.Reset();

                me->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));

                me->RemoveAura(eFoundrySpells::Berserker);
                me->RemoveAura(eSpells::Frenzy);
                me->RemoveAura(eSpells::FistsOfStone);

                me->setAttackTimer(WeaponAttackType::BASE_ATTACK, eTimers::TimerAttackTime);

                if (m_RipplingSmashTriggers.empty())
                {
                   // AddTimedDelayedOperation(2 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                  //  {
                        std::list<Creature*> l_Triggers;
                        me->GetCreatureListWithEntryInGrid(l_Triggers, eCreatures::RipplingSmashTrigger, 15.0f);

                        for (Creature* l_Trigger : l_Triggers)
                            m_RipplingSmashTriggers.insert(l_Trigger->GetGUID());
                  //  });
                }

                if (m_RipplingSmashTriggers.empty())
                {
                    //AddTimedDelayedOperation(2 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                   // {
                        std::list<Creature*> l_Triggers;
                        me->GetCreatureListWithEntryInGrid(l_Triggers, eCreatures::GraspingEarthTrigger, 80.0f);

                        for (Creature* l_Trigger : l_Triggers)
                            m_GraspingEarthTriggers.insert(l_Trigger->GetGUID());
                  //  });
                }

                for (ObjectGuid l_Guid : m_GraspingEarthTriggers)
                {
                    if (Creature* l_Trigger = ObjectAccessor::GetCreature(*me, l_Guid))
                    {
                        l_Trigger->DespawnOrUnsummon();
                        l_Trigger->Respawn();
                    }
                }

                m_FrenzyHealthPct   = 30;
                m_AbilityTalkTime   = 0;
                m_CrushingEarthBoom = false;
            }

            void KilledUnit(Unit* p_Who) override
            {
                if (p_Who->GetTypeId() != TYPEID_PLAYER)
                    return;

                Talk(eTalks::TalkSlay);
            }

            void EnterCombat(Unit* /*p_Attacker*/) override
            {
                _EnterCombat();

                Talk(eTalks::TalkAggro);

                me->CastSpell(me, eSpells::FistsOfStone, true);

                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me, 1);

                m_Events.ScheduleEvent(eEvents::EventCheckMeleePlayers, eTimers::TimerFirstCheckMeleePlayers);
                m_Events.ScheduleEvent(eEvents::EventBerserker, eTimers::TimerBerserker);
                m_Events.ScheduleEvent(eEvents::EventStoneBreath, eTimers::TimerStoneBreath);
                m_Events.ScheduleEvent(eEvents::EventWarpedArmor, eTimers::TimerWarpedArmor);
                m_Events.ScheduleEvent(eEvents::EventSlam, eTimers::TimerSlam);
                m_Events.ScheduleEvent(eEvents::EventRipplingSmash, eTimers::TimerRipplingSmash);
                m_Events.ScheduleEvent(eEvents::EventGraspingEarth, eTimers::TimerGraspingEarth);
                m_Events.ScheduleEvent(eEvents::EventCrushingEarth, eTimers::TimerCrushingEarth);
            }

            void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER)
            {
                if (m_Instance != nullptr)
                {
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::WarpedArmor);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::RuneOfGraspingEarthVehicle);
                }

                CreatureAI::EnterEvadeMode();

                Reset();
            }

            void JustDied(Unit* /*p_Killer*/) override
            {
                me->RemoveAllAreaTriggers();

                summons.DespawnAll();

              //  me->DespawnCreaturesInArea({ eCreatures::StoneWallRight, eCreatures::StoneWallLeft });
               // me->DespawnAreaTriggersInArea( eSpells::ReverberationsAreaTrigger );

                Talk(eTalks::TalkDeath);

                _JustDied();

                if (m_Instance != nullptr)
                {
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::WarpedArmor);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::RuneOfGraspingEarthVehicle);

                    /// Allow loots and bonus loots to be enabled/disabled with a simple reload
                   // if (sObjectMgr->IsDisabledEncounter(m_Instance->GetEncounterIDForBoss(me), GetDifficulty()))
                        me->AddLootRecipient(nullptr);
                   // else
                        CastSpellToPlayers(me->GetMap(), me, eSpells::KromogBonusLoot, true);
                }
            }

            void SpellHitTarget(Unit* p_Target, SpellInfo const* p_SpellInfo) override
            {
                if (p_Target == nullptr)
                    return;

                switch (p_SpellInfo->Id)
                {
                    case eSpells::RipplingSmashSearcher:
                    {
                        me->SetFacingTo(me->GetAngle(p_Target));

                        ObjectGuid l_Guid = p_Target->GetGUID();
                       // AddTimedDelayedOperation(50, [this, l_Guid]() -> void
                       // {
                            if (Unit* l_Target = ObjectAccessor::GetUnit(*me, l_Guid))
                            {
                                if (Creature* l_Trigger = GetRipplingSmashTrigger(l_Target))
                                {
                                    Talk(eTalks::TalkRipplingSmash/*, l_Trigger->GetGUID()*/);
                                    me->CastSpell(l_Trigger, eSpells::RipplingSmashCast, false);
                                }
                            }
                       // });

                        break;
                    }
                    case eSpells::RipplingSmashCast:
                    {
                        if (Creature* l_Trigger = p_Target->ToCreature())
                        {
                            if (l_Trigger->IsAIEnabled)
                                l_Trigger->AI()->DoAction(eActions::ActionRipplingSmash);
                        }

                        break;
                    }
                    default:
                        break;
                }
            }

            void DamageTaken(Unit* /*p_Attacker*/, uint32& p_Damage) override
            {
                if (me->HealthBelowPctDamaged(m_FrenzyHealthPct, p_Damage) && !me->HasAura(eSpells::Frenzy))
                {
                    m_FrenzyHealthPct = 0;

                    me->CastSpell(me, eSpells::Frenzy, true);

                    me->setAttackTimer(WeaponAttackType::BASE_ATTACK, eTimers::TimerAttackTimeFrenzied);

                    Talk(eTalks::TalkFrenzy);
                }
            }

            void UpdateAI(uint32 p_Diff) override
            {
               // UpdateOperations(p_Diff);
                CheckPositionZForPlayers(p_Diff);

                if (!UpdateVictim())
                    return;

                m_Events.Update(p_Diff);

                if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                    return;

                switch (m_Events.ExecuteEvent())
                {
                    case eEvents::EventCheckMeleePlayers:
                    {
                        Map::PlayerList const& l_PlayerList = me->GetMap()->GetPlayers();
                        if (l_PlayerList.isEmpty())
                        {
                            EnterEvadeMode();
                            break;
                        }

                        if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO))
                        {
                            if (!l_Target->IsWithinMeleeRange(me))
                                me->CastSpell(me, eSpells::StoneBreathChannel, false);
                        }

                        m_Events.ScheduleEvent(eEvents::EventCheckMeleePlayers, eTimers::TimerCheckMeleePlayers);
                        break;
                    }
                    case eEvents::EventBerserker:
                    {
                        me->CastSpell(me, eFoundrySpells::Berserker, true);
                        break;
                    }
                    case eEvents::EventStoneBreath:
                    {
                        if (m_AbilityTalkTime <= uint32(time(nullptr)))
                        {
                            Talk(eTalks::TalkAbility);
                            m_AbilityTalkTime = uint32(time(nullptr)) + eTimers::TimerAbilityTalk;
                        }

                        me->CastSpell(me, eSpells::StoneBreathChannel, false);
                        m_Events.ScheduleEvent(eEvents::EventStoneBreath, eTimers::TimerStoneBreathAgain);
                        break;
                    }
                    case eEvents::EventWarpedArmor:
                    {
                        if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO))
                            me->CastSpell(l_Target, eSpells::WarpedArmor, true);
                        m_Events.ScheduleEvent(eEvents::EventWarpedArmor, m_FrenzyHealthPct == 0 ? TimerWarpedArmorFrenzied : eTimers::TimerWarpedArmor);
                        break;
                    }
                    case eEvents::EventSlam:
                    {
                        if (m_AbilityTalkTime <= uint32(time(nullptr)))
                        {
                            Talk(eTalks::TalkAbility);
                            m_AbilityTalkTime = uint32(time(nullptr)) + eTimers::TimerAbilityTalk;
                        }

                        me->CastSpell(me, eSpells::Slam, false);

                        /// Reverberations and Shattered Earth will immediately follow Slam and Rippling Smash.
                        m_Events.ScheduleEvent(eEvents::EventReverberation, 1);
                        m_Events.ScheduleEvent(eEvents::EventShatteredEarth, 1);
                        m_Events.ScheduleEvent(eEvents::EventSlam, eTimers::TimerSlamAgain);
                        break;
                    }
                    case eEvents::EventRipplingSmash:
                    {
                        me->CastSpell(me, eSpells::RipplingSmashSearcher, true);

                        /// Reverberations and Shattered Earth will immediately follow Slam and Rippling Smash.
                        m_Events.ScheduleEvent(eEvents::EventReverberation, 1);
                        m_Events.ScheduleEvent(eEvents::EventShatteredEarth, 1);
                        m_Events.ScheduleEvent(eEvents::EventRipplingSmash, m_FrenzyHealthPct == 0 ? eTimers::TimerRipplingSmashFrenzied : eTimers::TimerRipplingSmashAgain);
                        break;
                    }
                    case eEvents::EventGraspingEarth:
                    {
                        /// Thundering Blows Icon Thundering Blows is an ability that Kromog always uses shortly after using Rune of Grasping Earth Icon Rune of Grasping Earth.
                        m_Events.ScheduleEvent(eEvents::EventThunderingBlows, eTimers::TimerThunderingBlows);

                        /// Those two events have specific timer after Grasping Earth
                        m_Events.RescheduleEvent(eEvents::EventStoneBreath,/* IsLFR() ? eTimers::TimerStoneBreathSecLFR :*/ eTimers::TimerStoneBreathSecond);
                        m_Events.RescheduleEvent(eEvents::EventRipplingSmash, eTimers::TimerRipplingSmashSec);

                        /// Delay those events to proc after Thundering Blows
                        m_Events.DelayEvents(eEvents::EventCheckMeleePlayers, eTimers::TimerThunderingBlowsDelay);
                        m_Events.DelayEvents(eEvents::EventSlam, eTimers::TimerThunderingBlowsDelay);
                        m_Events.DelayEvents(eEvents::EventWarpedArmor, eTimers::TimerThunderingBlowsDelay);
                        m_Events.DelayEvents(eEvents::EventCrushingEarth, eTimers::TimerThunderingBlowsDelay);

                        me->SetFacingTo(2.92434f);
                        me->AddUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));

                        for (Position const l_SpawnPos : g_GraspingEarthSpawnPos)
                            me->SummonCreature(eCreatures::GraspingEarthTrigger, l_SpawnPos);

                       // AddTimedDelayedOperation(50, [this]() -> void
                       // {
                            Talk(eTalks::TalkGraspingEarth);

                            me->CastSpell(me, eSpells::RuneOfGraspingEarthCast, false);
                       // });

                        m_Events.ScheduleEvent(eEvents::EventGraspingEarth, eTimers::TimerGraspingEarthAgain);
                        break;
                    }
                    case eEvents::EventThunderingBlows:
                    {
                        Talk(eTalks::TalkThunderingBlows);
                        me->CastSpell(me, eSpells::ThunderingBlows, false);

                       // AddTimedDelayedOperation(7 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                       // {
                            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));
                      //  });

                        break;
                    }
                    case eEvents::EventCrushingEarth:
                    {
                        if (m_AbilityTalkTime <= uint32(time(nullptr)))
                        {
                            Talk(eTalks::TalkAbility);
                            m_AbilityTalkTime = uint32(time(nullptr)) + eTimers::TimerAbilityTalk;
                        }

                        if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, -20.0f, true))
                            me->SummonCreature(eCreatures::RuneOfCrushingEarth, *l_Target);
                        else if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, -10.0f, true))
                            me->SummonCreature(eCreatures::RuneOfCrushingEarth, *l_Target);
                        else if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, -5.0f, true))
                            me->SummonCreature(eCreatures::RuneOfCrushingEarth, *l_Target);
                        else if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 2, 0.0f, true))
                            me->SummonCreature(eCreatures::RuneOfCrushingEarth, *l_Target);

                        /// When the second rune is summoned, it triggers both of them to crush
                        if (m_CrushingEarthBoom)
                        {
                            m_CrushingEarthBoom = false;

                           // AddTimedDelayedOperation(5 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                           // {
                                std::list<Creature*> l_CrushingEarthList;
                                me->GetCreatureListWithEntryInGrid(l_CrushingEarthList, eCreatures::RuneOfCrushingEarth, 50.0f);

                                for (Creature* l_Rune : l_CrushingEarthList)
                                {
                                    if (l_Rune->IsAIEnabled)
                                        l_Rune->AI()->DoAction(eActions::ActionCrushingEarth);
                                }
                          //  });
                        }
                        else
                            m_CrushingEarthBoom = true;

                        m_Events.ScheduleEvent(eEvents::EventCrushingEarth, eTimers::TimerCrushingEarthAgain);
                        break;
                    }
                    case eEvents::EventReverberation:
                    {
                        float l_BaseX = me->m_positionX;
                        float l_BaseY = me->m_positionY;
                       // float l_BaseO = me->m_orientation;

                        for (uint8 l_I = 0; l_I < eFoundryDatas::MaxReverberationSpawns; ++l_I)
                        {
                            float l_Range       = frand(25.0f, 35.0f);
                           // float l_Orientation = l_BaseO + frand(-(M_PI / 2.0f), M_PI / 2.0f);

                            float l_X = l_BaseX + l_Range/* * cos(l_Orientation)*/;
                            float l_Y = l_BaseY + l_Range/* * sin(l_Orientation)*/;
                            float l_Z = 105.0833f;  ///< Floor of the room

                            me->SummonCreature(eCreatures::ReverberationTrigger, { l_X, l_Y, l_Z/*, l_Orientation */});
                        }

                        break;
                    }
                    case eEvents::EventShatteredEarth:
                    {
                        me->CastSpell(me, eSpells::ShatteredEarthDamage, true);
                        break;
                    }
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }

            void CheckPositionZForPlayers(uint32 const p_Diff)
            {
                if (!m_CheckZTimer)
                    return;

                if (m_CheckZTimer <= p_Diff)
                {
                    Map::PlayerList const& l_PlayerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator l_Iter = l_PlayerList.begin(); l_Iter != l_PlayerList.end(); ++l_Iter)
                    {
                        if (Player* l_Player = l_Iter->GetSource())
                        {
                            if (l_Player->GetDistance(me) <= g_AllowedDist && l_Player->GetPositionZ() <= g_FloorZ)
                                l_Player->Kill(l_Player);
                        }
                    }

                    m_CheckZTimer = 1 * TimeConstants::IN_MILLISECONDS;
                }
                else
                    m_CheckZTimer -= p_Diff;
            }

            Creature* GetRipplingSmashTrigger(Unit* p_Target) const
            {
                float l_Distance    = 50000.0f;
                Creature* l_Trigger = nullptr;

                for (ObjectGuid l_Guid : m_RipplingSmashTriggers)
                {
                    if (Creature* l_Iter = ObjectAccessor::GetCreature(*me, l_Guid))
                    {
                        if (l_Iter->GetDistance(p_Target) < l_Distance)
                        {
                            l_Distance  = l_Iter->GetDistance(p_Target);
                            l_Trigger   = l_Iter;
                        }
                    }
                }

                return l_Trigger;
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new boss_kromogAI(p_Creature);
        }
};

/// Rippling Smash - 78055
class npc_foundry_rippling_smash : public CreatureScript
{
    public:
        npc_foundry_rippling_smash() : CreatureScript("npc_foundry_rippling_smash") { }

        enum eSpell
        {
            RipplingSmashAreaTrigger = 161437
        };

        enum eAction
        {
            ActionRipplingSmash
        };

        enum eVisual
        {
            RipplingSmashVisual = 38917
        };

        struct npc_foundry_rippling_smashAI : public ScriptedAI
        {
            npc_foundry_rippling_smashAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

            void DoAction(int32 p_Action)
            {
                if (p_Action == eAction::ActionRipplingSmash)
                {
                    me->CastSpell(me, eSpell::RipplingSmashAreaTrigger, true);

                   // AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                  //  {
                    float l_X = me->m_positionX + 2.0f;// *cos(me->m_orientation);
                    float l_Y = me->m_positionY + 2.0f;// *sin(me->m_orientation);
                        float l_Z = 105.055f;

                        me->SendPlaySpellVisual({ l_X, l_Y, l_Z },0.0f, eVisual::RipplingSmashVisual, 0.f,0.f, 5.0f,  true);
                   // });
                }
            }

            void UpdateAI(uint32  p_Diff) override 
            { 
                //UpdateOperations(p_Diff);
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_rippling_smashAI(p_Creature);
        }
};

/// Grasping Earth - 77893
class npc_foundry_grasping_earth : public CreatureScript
{
    public:
        npc_foundry_grasping_earth() : CreatureScript("npc_foundry_grasping_earth") { }

        enum eSpells
        {
            GraspingEarthSpawnVisual    = 160957,
            RuneOfGraspingEarthTrigger  = 157056,
            RuneOfGraspingEarthSpawn    = 157061,
            RuneOfGraspingEarthSelect   = 157059,
            RuneOfGraspingEarthVehicle  = 157212
        };

        struct npc_foundry_grasping_earthAI : public ScriptedAI
        {
            npc_foundry_grasping_earthAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

            bool m_Activated;
            bool m_PlayerGrasped;

            void Reset() override
            {
                //me->DisableEvadeMode();

                m_Activated = false;
                m_PlayerGrasped = false;

                me->CastSpell(me, eSpells::GraspingEarthSpawnVisual, true);

                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UnitFlags::UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE));
                me->AddUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));// | UnitFlags2::UNIT_FLAG2_UNK6 | UnitFlags2::UNIT_FLAG2_UNK11);

                me->ApplySpellImmune(0, SpellImmunity::IMMUNITY_MECHANIC, Mechanics::MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, SpellImmunity::IMMUNITY_MECHANIC, Mechanics::MECHANIC_FEAR, true);

                me->ApplySpellImmune(0, SpellImmunity::IMMUNITY_EFFECT, SpellEffectName::SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, SpellImmunity::IMMUNITY_EFFECT, SpellEffectName::SPELL_EFFECT_KNOCK_BACK_DEST, true);
            }

            void SpellHit(Unit* /*p_Attacker*/, SpellInfo const* p_SpellInfo) override
            {
                switch (p_SpellInfo->Id)
                {
                    case eSpells::RuneOfGraspingEarthTrigger:
                    {
                        m_Activated = true;

                        //AddTimedDelayedOperation(50, [this]() -> void
                       // {
                            me->CastSpell(me, eSpells::RuneOfGraspingEarthSpawn, false);
                      //  });

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
                    case eSpells::RuneOfGraspingEarthSelect:
                    {
                        m_PlayerGrasped = true;
                        p_Target->CastSpell(me, eSpells::RuneOfGraspingEarthVehicle, true);
                        break;
                    }
                    default:
                        break;
                }
            }

            void OnSpellCasted(SpellInfo const* p_SpellInfo)
            {
                if (p_SpellInfo->Id == eSpells::RuneOfGraspingEarthSpawn)
                {
                  //  AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                  //  {
                        me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UnitFlags::UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE));

                      //  me->ForceValuesUpdateAtIndex(UnitFields::UNIT_FIELD_DISPLAYID);

                        me->CastSpell(me, eSpells::RuneOfGraspingEarthSelect, true);
                  //  });

                  //  AddTimedDelayedOperation(2 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                  //  {
                        if (!m_PlayerGrasped)
                            me->Kill(me);
                  //  });
                }
            }

            void JustDied(Unit* p_Killer) override
            {
                if (InstanceScript* l_Instance = me->GetInstanceScript())
                {
                    if (p_Killer != me)
                        l_Instance->SetData(eFoundryDatas::GraspingEarthTime, (uint32)time(nullptr));
                }

                me->DespawnOrUnsummon(5 * TimeConstants::IN_MILLISECONDS);
            }

            void UpdateAI(uint32 p_Diff) override
            {
               // UpdateOperations(p_Diff);
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_grasping_earthAI(p_Creature);
        }
};

/// Rune of Crushing Earth - 77844
class npc_foundry_rune_of_crushing_earth : public CreatureScript
{
    public:
        npc_foundry_rune_of_crushing_earth() : CreatureScript("npc_foundry_rune_of_crushing_earth") { }

        enum eSpells
        {
            StoneWallRuneVisual         = 156946,
            StoneWallMissileRight       = 156969,
            StoneWallMissileLeft        = 156970,
            StoneWallAreaTriggerRight1  = 157008,
            StoneWallAreaTriggerLeft1   = 157012,
            StoneWallAreaTriggerRight2  = 157010,
            StoneWallAreaTriggerLeft2   = 157011,
            RuneOfCrushingEarthDamage   = 161923
        };

        enum eCreatures
        {
            StoneWallRight  = 79806,
            StoneWallLeft   = 77842
        };

        enum eAction
        {
            ActionCrushingEarth = 1
        };

        struct npc_foundry_rune_of_crushing_earthAI : public ScriptedAI
        {
            npc_foundry_rune_of_crushing_earthAI(Creature* p_Creature) : ScriptedAI(p_Creature)
            {
              //  m_StoneWallRight    = 0;
              //  m_StoneWallLeft     = 0;
            }

            ObjectGuid m_StoneWallRight;
            ObjectGuid m_StoneWallLeft;

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL | UnitFlags::UNIT_FLAG_NOT_SELECTABLE | UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_IMMUNE_TO_PC));
                me->AddUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));

                me->CastSpell(me, eSpells::StoneWallRuneVisual, true);

                uint32 l_Time = 1 * TimeConstants::IN_MILLISECONDS;
              //  AddTimedDelayedOperation(l_Time, [this]() -> void
               // {
                    me->CastSpell(me, eSpells::StoneWallMissileRight, true);
                    me->CastSpell(me, eSpells::StoneWallMissileLeft, true);
               // });

                l_Time += 500;
               // AddTimedDelayedOperation(l_Time, [this]() -> void
               // {
                    me->CastSpell(me, eSpells::StoneWallAreaTriggerRight1, true);
                    me->CastSpell(me, eSpells::StoneWallAreaTriggerLeft1, true);
               // });

                l_Time += 500;
               // AddTimedDelayedOperation(l_Time, [this]() -> void
              //  {
                    me->CastSpell(me, eSpells::StoneWallAreaTriggerRight2, true);
                    me->CastSpell(me, eSpells::StoneWallAreaTriggerLeft2, true);
               // });
            }

            void JustSummoned(Creature* p_Summon) override
            {
                switch (p_Summon->GetEntry())
                {
                    case eCreatures::StoneWallRight:
                    {
                        m_StoneWallRight = p_Summon->GetGUID();
                        break;
                    }
                    case eCreatures::StoneWallLeft:
                    {
                        m_StoneWallLeft = p_Summon->GetGUID();
                        break;
                    }
                    default:
                        break;
                }

                p_Summon->SetFacingTo(p_Summon->GetAngle(me));
            }

            void DoAction(int32 p_Action)
            {
                if (p_Action == eAction::ActionCrushingEarth)
                {
                    if (Creature* l_Right = ObjectAccessor::GetCreature(*me, m_StoneWallRight))
                    {
                        l_Right->RemoveUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));
                        l_Right->CastSpell(l_Right, eSpells::RuneOfCrushingEarthDamage, true);
                        l_Right->EnterVehicle(me, 0);
                    }

                    if (Creature* l_Left = ObjectAccessor::GetCreature(*me, m_StoneWallLeft))
                    {
                        l_Left->RemoveUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));
                        l_Left->CastSpell(l_Left, eSpells::RuneOfCrushingEarthDamage, true);
                        l_Left->EnterVehicle(me, 1);
                    }

                    me->RemoveAllAreaTriggers();
                    me->DespawnOrUnsummon(2 * TimeConstants::IN_MILLISECONDS);
                }
            }

            void PassengerBoarded(Unit* p_Passenger, int8 /*p_SeatID*/, bool p_Apply) override
            {
                if (p_Apply)
                {
                    if (Creature* l_StoneWall = p_Passenger->ToCreature())
                    {
                        if (l_StoneWall->IsAIEnabled)
                            l_StoneWall->AI()->DoAction(eAction::ActionCrushingEarth);
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
            return new npc_foundry_rune_of_crushing_earthAI(p_Creature);
        }
};

/// Stone Wall (right) - 79806
/// Stone Wall (left) - 77842
class npc_foundry_stone_wall : public CreatureScript
{
    public:
        npc_foundry_stone_wall() : CreatureScript("npc_foundry_stone_wall") { }

        enum eSpells
        {
            GraspingEarthInvisibleTransform = 161163,
            StoneWallRockHandVisual         = 161146
        };

        enum eAction
        {
            ActionCrushingEarth = 1
        };

        struct npc_foundry_stone_wallAI : public ScriptedAI
        {
            npc_foundry_stone_wallAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

            void Reset() override
            {
               // me->DisableEvadeMode();

                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL | UnitFlags::UNIT_FLAG_NOT_SELECTABLE | UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_IMMUNE_TO_PC));
                me->AddUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));

                me->CastSpell(me, eSpells::GraspingEarthInvisibleTransform, true);
                me->CastSpell(me, eSpells::StoneWallRockHandVisual, true);
            }

            void DoAction(int32 p_Action)
            {
                if (p_Action == eAction::ActionCrushingEarth)
                {
                    me->RemoveAura(eSpells::StoneWallRockHandVisual);
                    me->DespawnOrUnsummon(1 * TimeConstants::IN_MILLISECONDS);
                }
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_stone_wallAI(p_Creature);
        }
};

/// Reverberation - 77929
class npc_foundry_reverberation : public CreatureScript
{
    public:
        npc_foundry_reverberation() : CreatureScript("npc_foundry_reverberation") { }

        enum eSpells
        {
            ReverberationsSpawnVisual   = 157250,
            ReverberationsAreaTrigger   = 157246
        };

        enum eMove
        {
            MoveOnce = 1
        };

        struct npc_foundry_reverberationAI : public ScriptedAI
        {
            npc_foundry_reverberationAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

            void Reset() override
            {
              //  me->DisableEvadeMode();

                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_IMMUNE_TO_PC));

               // me->SetUInt32Value(UnitFields::UNIT_FIELD_SCALE_DURATION, 2 * TimeConstants::IN_MILLISECONDS);

               // AddTimedDelayedOperation(50, [this]() -> void
                //{
               //     me->SetFloatValue(ObjectFields::OBJECT_FIELD_SCALE_X, 1.0f);
                //});

                me->CastSpell(me, eSpells::ReverberationsSpawnVisual, true);

               // AddTimedDelayedOperation(2 * TimeConstants::IN_MILLISECONDS, [this]() -> void
              //  {
                    me->CastSpell(me, eSpells::ReverberationsAreaTrigger, true);
              //  });

               // AddTimedDelayedOperation(3 * TimeConstants::IN_MILLISECONDS, [this]() -> void
              //  {
                    float l_X = me->m_positionX + 60.0f;// *cos(me->m_orientation);
                float l_Y = me->m_positionY + 60.0f ;// *sin(me->m_orientation);
                    float l_Z = me->m_positionZ;

                    me->GetMotionMaster()->MovePoint(eMove::MoveOnce, { l_X, l_Y, l_Z/*, me->m_orientation*/ });
              //  });
            }

            void MovementInform(uint32 p_Type, uint32 p_ID) override
            {
                if (p_Type != MovementGeneratorType::POINT_MOTION_TYPE)
                    return;

                if (p_ID != eMove::MoveOnce)
                    return;

                me->DespawnOrUnsummon();
            }

            void UpdateAI(uint32 p_Diff) override
            {
               // UpdateOperations(p_Diff);
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_reverberationAI(p_Creature);
        }
};

/// Slam - 156704
class spell_foundry_slam : public SpellScriptLoader
{
    public:
        spell_foundry_slam() : SpellScriptLoader("spell_foundry_slam") { }

        class spell_foundry_slam_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_foundry_slam_SpellScript);

            void HandleDamage(SpellEffIndex /*p_EffIndex*/)
            {
                if (Unit* l_Boss = GetCaster())
                {
                    if (GetHitUnit() == nullptr)
                        return;

                    if (Player* l_Player = GetHitUnit()->ToPlayer())
                    {
                        /// Kromog strikes the ground beneath his primary target, dealing up to X Physical damage to all players, reduced based on their distance from the impact point.
                        /// Damages will be reduced by 1.6% per yard between player and boss, with a cap at 60 yards.
                        float l_ReducedDamage = 1.6f;

                        /// Melee players should take reduced damage for this spell, I don't know why or how much, but it seems it's a custom calculation for them
                      //  if (l_Player->IsMeleeDamageDealer())
                            AddPct(l_ReducedDamage, 50.0f);

                      //  float l_Damage      = (float)GetSpell()->GetDamage();
                      //  float l_Distance    = std::min(l_Player->IsMeleeDamageDealer() ? 40.0f : 60.0f, l_Player->GetDistance(*l_Boss));
                      //  float l_NewDamages  = std::max(1.0f, l_Damage - (l_Damage * l_Distance * l_ReducedDamage / 100.0f));

                      //  GetSpell()->SetDamage((uint32)l_NewDamages);
                    }
                }
            }

            void Register() override
            {
                OnEffectLaunchTarget += SpellEffectFn(spell_foundry_slam_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_foundry_slam_SpellScript();
        }
};

/// Fists of Stone - 162348
class spell_foundry_fists_of_stone : public SpellScriptLoader
{
    public:
        spell_foundry_fists_of_stone() : SpellScriptLoader("spell_foundry_fists_of_stone") { }

        enum eSpell
        {
            FistsOfStoneProc = 162349
        };

        class spell_foundry_fists_of_stone_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_foundry_fists_of_stone_AuraScript);

            void OnProc(AuraEffect const* /*p_AurEff*/, ProcEventInfo& p_EventInfo)
            {
                PreventDefaultAction();

                if (p_EventInfo.GetDamageInfo()->GetSpellInfo() != nullptr)
                    return;

                if (Creature* l_Kromog = GetTarget()->ToCreature())
                {
                   // if (l_Kromog->HasSpellCooldown(eSpell::FistsOfStoneProc))
                   //     return;

                    if (Unit* l_Target = p_EventInfo.GetActionTarget())
                    {
                        l_Kromog->CastSpell(l_Target, eSpell::FistsOfStoneProc, true);
                        //l_Kromog->_AddCreatureSpellCooldown(eSpell::FistsOfStoneProc, 4 * TimeConstants::IN_MILLISECONDS);
                    }
                }
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_foundry_fists_of_stone_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_foundry_fists_of_stone_AuraScript();
        }
};

/// Rune of Grasping Earth (Searcher) - 157056
class spell_foundry_rune_of_grasping_earth : public SpellScriptLoader
{
    public:
        spell_foundry_rune_of_grasping_earth() : SpellScriptLoader("spell_foundry_rune_of_grasping_earth") { }

        class spell_foundry_rune_of_grasping_earth_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_foundry_rune_of_grasping_earth_SpellScript);

            void CorrectTargets(std::list<WorldObject*>& p_Targets)
            {
                if (p_Targets.empty())
                    return;

                p_Targets.remove_if([this](WorldObject* p_Object) -> bool
                {
                    if (p_Object == nullptr || p_Object->GetTypeId() != TypeID::TYPEID_UNIT)
                        return true;

                    if (Creature* l_Trigger = p_Object->ToCreature())
                    {
                        if (npc_foundry_grasping_earth::npc_foundry_grasping_earthAI* l_AI = CAST_AI(npc_foundry_grasping_earth::npc_foundry_grasping_earthAI, l_Trigger->GetAI()))
                        {
                            if (l_AI->m_Activated)
                                return true;
                        }
                        else
                            return true;
                    }
                    else
                        return true;

                    return false;
                });
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_foundry_rune_of_grasping_earth_SpellScript::CorrectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_foundry_rune_of_grasping_earth_SpellScript();
        }
};

/// Rune of Crushing Earth (damage) - 161923
class spell_foundry_rune_of_crushing_earth : public SpellScriptLoader
{
    public:
        spell_foundry_rune_of_crushing_earth() : SpellScriptLoader("spell_foundry_rune_of_crushing_earth") { }

        class spell_foundry_rune_of_crushing_earth_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_foundry_rune_of_crushing_earth_SpellScript);

            enum eSpell
            {
                TargetRestrict = 20616
            };

            void CorrectTargets(std::list<WorldObject*>& p_Targets)
            {
                if (p_Targets.empty())
                    return;

                SpellTargetRestrictionsEntry const* l_Restriction = sSpellTargetRestrictionsStore.LookupEntry(eSpell::TargetRestrict);
                if (l_Restriction == nullptr)
                    return;

                Unit* l_Caster = GetCaster();
                if (l_Caster == nullptr)
                    return;

                float l_Radius = GetSpellInfo()->GetEffect(SpellEffIndex::EFFECT_0)->CalcRadius(l_Caster);
                p_Targets.remove_if([l_Radius, l_Caster, l_Restriction](WorldObject* p_Object) -> bool
                {
                    if (p_Object == nullptr)
                        return true;

                    if (!p_Object->IsInAxe(l_Caster, l_Restriction->Width, l_Radius))
                        return true;

                    if (!p_Object->isInFront(l_Caster))
                        return true;

                    return false;
                });
            }

            void Register() override
            {
            //    OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_foundry_rune_of_crushing_earth_SpellScript::CorrectTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_ENEMY_FRONT);
            //    OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_foundry_rune_of_crushing_earth_SpellScript::CorrectTargets, EFFECT_1, TARGET_UNIT_CASTER_AREA_ENEMY_FRONT);
            //    OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_foundry_rune_of_crushing_earth_SpellScript::CorrectTargets, EFFECT_2, TARGET_UNIT_CASTER_AREA_ENEMY_FRONT);   
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_foundry_rune_of_crushing_earth_SpellScript();
        }
};

/// Rune of Grasping Earth (DoT) - 157059
class spell_foundry_rune_of_grasping_earth_dot : public SpellScriptLoader
{
    public:
        spell_foundry_rune_of_grasping_earth_dot() : SpellScriptLoader("spell_foundry_rune_of_grasping_earth_dot") { }

        class spell_foundry_rune_of_grasping_earth_dot_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_foundry_rune_of_grasping_earth_dot_AuraScript);

            void OnTick(AuraEffect const* p_AurEff)
            {
                /// Fists of stone grasp at players, inflicting 12168 to 12792 Nature damage per second, but shielding them from Physical damage and holding them to the ground.
                /// The damage increases over time.
                int32 l_Amount = p_AurEff->GetAmount();

                AddPct(l_Amount, 4);

                p_AurEff->GetBase()->GetEffect(SpellEffIndex::EFFECT_1)->ChangeAmount(l_Amount);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_foundry_rune_of_grasping_earth_dot_AuraScript::OnTick, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_foundry_rune_of_grasping_earth_dot_AuraScript();
        }
};

/// Rippling Smash - 161437
class areatrigger_foundry_rippling_smash : public AreaTriggerEntityScript
{
    public:
        areatrigger_foundry_rippling_smash() : AreaTriggerEntityScript("areatrigger_foundry_rippling_smash") { }

        enum eSpell
        {
            RipplingSmashDamage = 157659
        };

        std::set<ObjectGuid> m_AffectedTargets;

        void OnSetCreatePosition(AreaTrigger* /*p_AreaTrigger*/, Unit* p_Caster, Position& /*p_SourcePosition*/, Position& p_DestinationPosition, std::list<Position>& /*p_PathToLinearDestination*/)
        {
            float l_Orientation = p_Caster->GetOrientation();

            p_DestinationPosition.m_positionX = p_Caster->GetPositionX() + 60.0f * cos(l_Orientation);
            p_DestinationPosition.m_positionY = p_Caster->GetPositionY() + 60.0f * sin(l_Orientation);
        }

        void OnUpdate(AreaTrigger* p_AreaTrigger, uint32 /*p_Time*/)
        {
            if (Unit* l_Caster = p_AreaTrigger->GetCaster())
            {
                float l_Radius = 30.0f;
                std::list<Unit*> l_TargetList;

                Trinity::AnyUnfriendlyUnitInObjectRangeCheck l_Check(p_AreaTrigger, l_Caster, l_Radius);
                Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> l_Searcher(p_AreaTrigger, l_TargetList, l_Check);
             //   p_AreaTrigger->VisitNearbyObject(l_Radius, l_Searcher);

                for (Unit* l_Unit : l_TargetList)
                {
                    if (m_AffectedTargets.find(l_Unit->GetGUID()) != m_AffectedTargets.end())
                        continue;

                    if (!IsInBox(l_Unit, *p_AreaTrigger))
                        continue;

                    m_AffectedTargets.insert(l_Unit->GetGUID());
                    l_Unit->CastSpell(l_Unit, eSpell::RipplingSmashDamage, true, nullptr, nullptr, l_Caster->GetGUID());
                }
            }
        }

        bool IsInBox(Unit* p_Target, Position const p_Pos) const
        {
            float l_SizeX = 4.0f;
            float l_SizeY = 21.5f;

            float l_MinX = p_Pos.m_positionX - (l_SizeX / 2.0f);
            float l_MaxX = p_Pos.m_positionX + (l_SizeX / 2.0f);
            float l_MinY = p_Pos.m_positionY - (l_SizeY / 2.0f);
            float l_MaxY = p_Pos.m_positionY + (l_SizeY / 2.0f);

            if (p_Target->m_positionX >= l_MinX && p_Target->m_positionX <= l_MaxX &&
                p_Target->m_positionY >= l_MinY && p_Target->m_positionY <= l_MaxY)
                return true;

            return false;
        }
        /*
        AreaTriggerEntityScript* GetAI()
        {
            return nullptr;
        }*/
};

/// Reverberations - 157246
class areatrigger_foundry_reverberations : public AreaTriggerEntityScript
{
    public:
        areatrigger_foundry_reverberations() : AreaTriggerEntityScript("areatrigger_foundry_reverberations") { }

        enum eSpell
        {
            ReverberationsDamage = 157247
        };

        void OnUpdate(AreaTrigger* p_AreaTrigger, uint32 /*p_Time*/) 
        {
            if (Unit* l_Caster = p_AreaTrigger->GetCaster())
            {
                float l_Radius = 1.0f;
                std::list<Unit*> l_TargetList;

                Trinity::AnyUnfriendlyUnitInObjectRangeCheck l_Check(p_AreaTrigger, l_Caster, l_Radius);
                Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> l_Searcher(p_AreaTrigger, l_TargetList, l_Check);
              //  p_AreaTrigger->VisitNearbyObject(l_Radius, l_Searcher);

                for (Unit* l_Unit : l_TargetList)
                {
                    l_Unit->CastSpell(l_Unit, eSpell::ReverberationsDamage, true, nullptr, nullptr, l_Caster->GetGUID());

                    if (l_Caster->GetTypeId() == TypeID::TYPEID_UNIT)
                    {
                        l_Caster->ToCreature()->DespawnOrUnsummon();
                        p_AreaTrigger->SetDuration(0);
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

void AddSC_boss_kromog()
{
    /// Boss
    new boss_kromog();/// Kromog <Legend of the Mountain> - 77692

    /// Creatures
    new npc_foundry_rippling_smash();/// Rippling Smash - 78055
    new npc_foundry_grasping_earth();/// Grasping Earth - 77893
    new npc_foundry_rune_of_crushing_earth();/// Rune of Crushing Earth - 77844
    new npc_foundry_stone_wall();/// Stone Wall (right) - 79806- 77842
    new npc_foundry_reverberation();/// Reverberation - 77929

    /// Spells
    new spell_foundry_slam();/// Slam - 156704
    new spell_foundry_fists_of_stone();/// Fists of Stone - 162348
    new spell_foundry_rune_of_grasping_earth(); /// Rune of Grasping Earth (Searcher) - 157056
    new spell_foundry_rune_of_crushing_earth();/// Rune of Crushing Earth (damage) - 161923
    new spell_foundry_rune_of_grasping_earth_dot();/// Rune of Grasping Earth (DoT) - 157059

    /// AreaTriggers
    new areatrigger_foundry_rippling_smash();/// Rippling Smash - 161437
    new areatrigger_foundry_reverberations();/// Reverberations - 157246
}
