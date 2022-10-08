#include "blackrock_foundry.h"

Position const g_CinderWolfSpawnPos = { 131.1977f, 3788.002f, 101.8597f, 0.0f };

/// Flamebender Ka'graz <Shaman of the Burning Blade> - 76814
class boss_flamebender_kagraz : public CreatureScript
{
    public:
        boss_flamebender_kagraz() : CreatureScript("boss_flamebender_kagraz") { }

        enum eTalks
        {
            TalkAggro,
            TalkAknorDeath,
            TalkFirestorm,
            TalkCinderWolves,
            TalkBerserk,
            TalkSlay,
            TalkWipe,
            TalkDeath,
            TalkCinderWolvesWarn,
            TalkFirestormWarn
        };

        enum eSpells
        {
            /// Misc
            PrefightCosmeticBossAura    = 156237,
            AllowMoltenTorrentCast      = 155912,
            CharringBreathDamage        = 155074,
            Singe                       = 155049,
            FirestormMoltenBolt         = 163630,
            FlamebenderKagrazBonusLoot  = 177534,
            /// Lava Slash
            LavaSlashSearcher           = 154914,
            LavaSlashMissile            = 155297,   ///< Triggers 155318 - AoE damage - Summons 76996
            LavaSlashMissileTriggered   = 155318,
            LavaSlashAreaTrigger        = 154915,
            /// Summon Enchanted Armaments
            EnchantedArmamentsSearcher  = 163644,
            EnchantedArmamentsDummy     = 156725,
            /// Molten Torrent
            MoltenTorrentAura           = 154932,
            /// Summon Cinder Wolves
            SummonCinderWolves          = 155776,
            /// Blazing Radiance
            BlazingRadianceSearcher     = 155382,
            BlazingRadianceAura         = 155277,
            /// Firestorm
            FirestormSelfAura           = 155564,
            FirestormPeriodicTrigger    = 155493,
            Flamefury                   = 163273,
            RisingFlames                = 163284
        };

        enum eEvents
        {
            EventLavaSlash = 1,
            EventSummonEnchantedArmament,
            EventMoltenTorrent,
            EventCinderWolves,
            EventBlazingRadiance,
            EventFirestorm,
            EventBerserker
        };

        enum eTimers
        {
            TimerEnergize               = 1 * TimeConstants::IN_MILLISECONDS + 200,
            TimerLavaSlash              = 11 * TimeConstants::IN_MILLISECONDS,
            TimerLavaSlashAgain         = 14 * TimeConstants::IN_MILLISECONDS + 500,
            TimerEnchantedArmament      = 7 * TimeConstants::IN_MILLISECONDS,
            TimerEnchantedArmamentAgain = 60 * TimeConstants::IN_MILLISECONDS,
            TimerMoltenTorrentAgain     = 14 * TimeConstants::IN_MILLISECONDS + 500,
            TimerBlazingRadianceAgain   = 12 * TimeConstants::IN_MILLISECONDS,
            TimerBerserker              = 420 * TimeConstants::IN_MILLISECONDS
        };

        enum eCosmeticEvents
        {
            EventPeriodicEnergize = 1
        };

        enum eActions
        {
            /// Me
            ActionAknorDied,
            ActionMagmaMonsoon,
            ActionFirestorm,
            /// Others
            ActionMoltenTorrent = 0
        };

        enum eCreatures
        {
            FlamebenderKagrazTrigger    = 76996,
            EnchantedArmament           = 77709,
            OverheatedCinderWolf        = 78912
        };

        enum eVisuals
        {
            LavaStalkerVisual   = 36855,
            MoltenTorrentVisual = 36912
        };

        struct boss_flamebender_kagrazAI : public BossAI
        {
            boss_flamebender_kagrazAI(Creature* p_Creature) : BossAI(p_Creature, eFoundryDatas::DataFlamebenderKagraz)
            {
                m_Instance  = p_Creature->GetInstanceScript();
            }

            InstanceScript* m_Instance;

            EventMap m_Events;
            EventMap m_CosmeticEvents;

            ObjectGuid m_LavaSlashTarget;

            bool m_Firestorm;

            bool CanRespawn()
            {
                return false;
            }

            void Reset() override
            {
              //  ClearDelayedOperations();

                summons.DespawnAll();

               // me->DespawnCreaturesInArea(eFoundryCreatures::CinderWolf, 200.0f);
               // me->DespawnCreaturesInArea(eCreatures::OverheatedCinderWolf, 200.0f);

               // me->DespawnAreaTriggersInArea(eSpells::FirestormMoltenBolt, 200.0f);

                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG2_REGENERATE_POWER));

                _Reset();

                me->RemoveAllAreaTriggers();

                me->RemoveAura(eFoundrySpells::Berserker);

                me->CastSpell(me, eSpells::AllowMoltenTorrentCast, true);
                me->CastSpell(me, eSpells::PrefightCosmeticBossAura, false);

                //me->setPowerType(Powers::POWER_ENERGY);
                me->SetMaxPower(Powers::POWER_ENERGY, 100);
                me->SetPower(Powers::POWER_ENERGY, 0);

                m_Events.Reset();
                m_CosmeticEvents.Reset();

                if (m_Instance)
                {
                    if (Creature* l_Aknor = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::AknorSteelbringer)))
                    {
                        l_Aknor->DespawnOrUnsummon();
                        l_Aknor->Respawn();

                        ObjectGuid l_Guid = l_Aknor->GetGUID();
                        //AddTimedDelayedOperation(100, [this, l_Guid]() -> void
                        //{
                            if (Creature* l_Aknor = ObjectAccessor::GetCreature(*me, l_Guid))
                                l_Aknor->GetMotionMaster()->MoveTargetedHome();
                        //});
                    }
                }

               // m_LavaSlashTarget = 0;

                m_Firestorm = false;
            }

            void KilledUnit(Unit* p_Who) override
            {
                if (p_Who->GetTypeId() != TYPEID_PLAYER)
                    return;

                Talk(eTalks::TalkSlay);
            }

            void EnterCombat(Unit* p_Attacker) override
            {
                me->InterruptNonMeleeSpells(true);

                _EnterCombat();

                Talk(eTalks::TalkAggro);

                if (m_Instance != nullptr)
                {
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me, 1);

                    if (Creature* l_MoltenStalker = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::MoltenTorrentStalker)))
                    {
                        if (l_MoltenStalker->IsAIEnabled)
                            l_MoltenStalker->AI()->EnterCombat(p_Attacker);
                    }
                }

                AttackStart(p_Attacker);

                m_CosmeticEvents.ScheduleEvent(eCosmeticEvents::EventPeriodicEnergize, eTimers::TimerEnergize);

                m_Events.ScheduleEvent(eEvents::EventLavaSlash, eTimers::TimerLavaSlash);
                m_Events.ScheduleEvent(eEvents::EventSummonEnchantedArmament, eTimers::TimerEnchantedArmament);

               // if (IsMythic())
                    m_Events.ScheduleEvent(eEvents::EventBerserker, eTimers::TimerBerserker);
            }

            void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER)
            {
                m_Firestorm = false;

                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));
                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));

                me->ClearUnitState(UnitState::UNIT_STATE_ROOT);

              //  ClearDelayedOperations();

                Talk(eTalks::TalkWipe);

                if (m_Instance != nullptr)
                {
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::MoltenTorrentAura);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::BlazingRadianceAura);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::CharringBreathDamage);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::RisingFlames);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::Singe);

                    if (Creature* l_MoltenStalker = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::MoltenTorrentStalker)))
                    {
                        if (l_MoltenStalker->IsAIEnabled)
                            l_MoltenStalker->AI()->EnterEvadeMode();
                    }

                    if (Creature* l_LavaStalker = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::LavaStalker)))
                    {
                        if (l_LavaStalker->IsAIEnabled)
                            l_LavaStalker->AI()->Reset();
                    }
                }

                CreatureAI::EnterEvadeMode();
            }

            void JustDied(Unit* /*p_Killer*/) override
            {
                Talk(eTalks::TalkDeath);

                me->RemoveAllAreaTriggers();

                summons.DespawnAll();

                me->DespawnCreaturesInArea(eFoundryCreatures::CinderWolf, 200.0f);
                me->DespawnCreaturesInArea(eCreatures::OverheatedCinderWolf, 200.0f);

                _JustDied();

                if (m_Instance != nullptr)
                {
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::MoltenTorrentAura);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::BlazingRadianceAura);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::CharringBreathDamage);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::RisingFlames);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::Singe);

                    /// Allow loots and bonus loots to be enabled/disabled with a simple reload
                   // if (sObjectMgr->IsDisabledEncounter(m_Instance->GetEncounterIDForBoss(me), GetDifficulty()))
                      //  me->SetLootRecipient(nullptr);
                  //  else
                        CastSpellToPlayers(me->GetMap(), me, eSpells::FlamebenderKagrazBonusLoot, true);

                    if (Creature* l_Aknor = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::AknorSteelbringer)))
                    {
                        l_Aknor->SetFaction(eFoundryDatas::FriendlyFaction);
                        l_Aknor->CombatStop();
                        l_Aknor->RemoveAllAuras();
                       // l_Aknor->SetUInt32Value(UnitFields::UNIT_FIELD_STATE_ANIM_ID, Anim::ANIM_KNEEL_LOOP);

                        m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, l_Aknor);
                    }
                }
            }

            void JustSummoned(Creature* p_Summon) override
            {
                summons.Summon(p_Summon);

                if (p_Summon->GetEntry() == eCreatures::FlamebenderKagrazTrigger && p_Summon->IsAIEnabled)
                    p_Summon->AI()->SetGUID(m_LavaSlashTarget, 0);
            }

            void SpellHitTarget(Unit* p_Target, SpellInfo const* p_SpellInfo) override
            {
                if (p_Target == nullptr)
                    return;

                switch (p_SpellInfo->Id)
                {
                    case eSpells::EnchantedArmamentsSearcher:
                    {
                        me->CastSpell(p_Target, eSpells::EnchantedArmamentsDummy, true);
                        break;
                    }
                    case eSpells::EnchantedArmamentsDummy:
                    {
                        if (Creature* l_Old = p_Target->ToCreature())
                            l_Old->DespawnOrUnsummon(1 * TimeConstants::IN_MILLISECONDS);

                        if (Creature* l_Armament = me->SummonCreature(eCreatures::EnchantedArmament, *p_Target))
                        {
                            if (l_Armament->IsAIEnabled)
                            {
                               // if (Player* l_Target = SelectRangedTarget(true, -eSpells::MoltenTorrentAura))
                                //    l_Armament->AI()->SetGUID(l_Target->GetGUID(), 0);
                            }
                        }

                        break;
                    }
                    case eSpells::MoltenTorrentAura:
                    {
                        if (m_Instance != nullptr)
                        {
                            if (Creature* l_LavaStalker = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::LavaStalker)))
                            {
                                if (Creature* l_MoltenTorrent = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::MoltenTorrentStalker)))
                                {
                                  //  G3D::Vector3 l_Source(l_LavaStalker->m_positionX, l_LavaStalker->m_positionY, l_LavaStalker->m_positionZ);
                                  //  G3D::Vector3 l_Dest(l_MoltenTorrent->m_positionX, l_MoltenTorrent->m_positionY, l_MoltenTorrent->m_positionZ);
                                  //  G3D::Vector3 l_Orientation(0.0f, 0.0f, 0.0f);

                                    //l_LavaStalker->PlayOrphanSpellVisual(l_Source, l_Orientation, l_Dest, eVisuals::LavaStalkerVisual, 5.0f);

                                  //  l_MoltenTorrent->SendPlaySpellVisual(eVisuals::MoltenTorrentVisual, nullptr, 1.0f, 0.0f, *me, false, true);

                                    if (l_MoltenTorrent->IsAIEnabled)
                                    {
                                        l_MoltenTorrent->AI()->SetGUID(p_Target->GetGUID(), 0);
                                        l_MoltenTorrent->AI()->DoAction(eActions::ActionMoltenTorrent);
                                    }
                                }
                            }
                        }

                        break;
                    }
                    case eSpells::BlazingRadianceSearcher:
                    {
                        me->CastSpell(p_Target, eSpells::BlazingRadianceAura, true);
                        break;
                    }
                    default:
                        break;
                }
            }

            void SpellHitDest(SpellDestination const* p_Dest, SpellInfo const* p_SpellInfo)
            {
                if (p_Dest == nullptr)
                    return;

                switch (p_SpellInfo->Id)
                {
                    case eSpells::LavaSlashMissileTriggered:
                    {
                        Position* l_Dest    = new Position(p_Dest->_position);
                        Position* l_Src     = new Position(*me);
                        Creature* l_Me      = me;

                       // AddTimedDelayedOperation(50, [l_Me, l_Dest, l_Src]() -> void
                       // {
                            uint8 l_Dist = (uint8)l_Src->GetExactDist2d(l_Dest);
                            for (uint8 l_I = 0; l_I < l_Dist; ++l_I)
                            {
                                Position l_Target;

                                float l_O = l_Src->GetAngle(l_Dest);
                                float l_X = l_Src->m_positionX + (l_I * cos(l_O));
                                float l_Y = l_Src->m_positionY + (l_I * sin(l_O));
                                float l_Z = l_Src->m_positionZ;

                               // l_Target.m_positionX    = l_X;
                               // l_Target.m_positionY    = l_Y;
                               // l_Target.m_positionZ    = l_Z;
                               // l_Target.m_orientation  = l_O;

                                l_Me->CastSpell(l_Target.m_positionX = l_X, l_Target.m_positionY = l_Y, l_Target.m_positionZ = l_Z, eSpells::LavaSlashAreaTrigger, true);
                            }
                            
                            delete l_Dest;
                            delete l_Src;
                       // });

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
                    case eActions::ActionAknorDied:
                    {
                        Talk(eTalks::TalkAknorDeath);

                        if (m_Instance)
                            m_Instance->SetData(eFoundryDatas::AknorDied, 1);

                        break;
                    }
                    case eActions::ActionMagmaMonsoon:
                    {
                        me->SetPower(Powers::POWER_ENERGY, 0);

                        me->CastSpell(me, eSpells::Flamefury, true);

                        if (Creature* l_MoltenStalker = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::MoltenTorrentStalker)))
                        {
                            if (l_MoltenStalker->IsAIEnabled)
                                l_MoltenStalker->AI()->DoAction(eActions::ActionMagmaMonsoon);
                        }

                        break;
                    }
                    default:
                        break;
                }
            }

            void RegeneratePower(Powers /*p_Power*/, int32& p_Value)
            {
                /// Flamebender Ka'graz only regens by script
                p_Value = 0;
            }

            void SetPower(Powers p_Power, int32 p_NewValue)
            {
                int32 l_OldValue = me->GetPower(p_Power);

                /// Flamebender Ka'graz gains energy over time allowing her to access even more powerful abilities.
                /// She gains abilities at 25, 50, 75, and 100 Molten Energy.
                if (p_NewValue >= 100)
                    m_Events.ScheduleEvent(eEvents::EventFirestorm, 1);
                else if (p_NewValue >= 75 && l_OldValue < 75)
                    m_Events.ScheduleEvent(eEvents::EventBlazingRadiance, 1);
                else if (p_NewValue >= 50 && l_OldValue < 50)
                    m_Events.ScheduleEvent(eEvents::EventCinderWolves, 1);
                else if (p_NewValue >= 25 && l_OldValue < 25)
                    m_Events.ScheduleEvent(eEvents::EventMoltenTorrent, 1);
            }

            void UpdateAI(uint32 p_Diff) override
            {
              //  UpdateOperations(p_Diff);

                m_CosmeticEvents.Update(p_Diff);

                switch (m_CosmeticEvents.ExecuteEvent())
                {
                    case eCosmeticEvents::EventPeriodicEnergize:
                    {
                        me->ModifyPower(Powers::POWER_ENERGY, 1);

                        m_CosmeticEvents.ScheduleEvent(eCosmeticEvents::EventPeriodicEnergize, eTimers::TimerEnergize);
                        break;
                    }
                    default:
                        break;
                }

                if (me->GetDistance(me->GetHomePosition()) >= 70.0f)
                {
                    EnterEvadeMode();
                    return;
                }

                if (!UpdateVictim() || m_Firestorm)
                    return;

                m_Events.Update(p_Diff);

                if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                    return;

                switch (m_Events.ExecuteEvent())
                {
                    case eEvents::EventLavaSlash:
                    {
                        //if (Player* l_Target = SelectRangedTarget(true, -eSpells::MoltenTorrentAura))
                        //{
                            me->CastSpell(me, eSpells::LavaSlashMissile, false);

                           // m_LavaSlashTarget = l_Target != nullptr ? l_Target->GetGUID() : 0;
                       // }

                        m_Events.ScheduleEvent(eEvents::EventLavaSlash, eTimers::TimerLavaSlashAgain);
                        break;
                    }
                    case eEvents::EventSummonEnchantedArmament:
                    {
                        /// Find a spawned Enchanted Armament
                        me->CastSpell(me, eSpells::EnchantedArmamentsSearcher, true);
                        m_Events.ScheduleEvent(eEvents::EventSummonEnchantedArmament, eTimers::TimerEnchantedArmamentAgain);
                        break;
                    }
                    case eEvents::EventMoltenTorrent:
                    {
                        if (me->GetPower(Powers::POWER_ENERGY) < 25)
                            break;

                        //if (Player* l_Target = SelectRangedTarget())
                            me->CastSpell(me, eSpells::MoltenTorrentAura, false);

                        m_Events.ScheduleEvent(eEvents::EventMoltenTorrent, eTimers::TimerMoltenTorrentAgain);
                        break;
                    }
                    case eEvents::EventCinderWolves:
                    {
                        Talk(eTalks::TalkCinderWolves);
                        Talk(eTalks::TalkCinderWolvesWarn);

                        me->CastSpell(me, eSpells::SummonCinderWolves, false);
                        break;
                    }
                    case eEvents::EventBlazingRadiance:
                    {
                        if (me->GetPower(Powers::POWER_ENERGY) < 75)
                            break;

                        me->CastSpell(me, eSpells::BlazingRadianceSearcher, false);
                        m_Events.ScheduleEvent(eEvents::EventBlazingRadiance, eTimers::TimerBlazingRadianceAgain);
                        break;
                    }
                    case eEvents::EventFirestorm:
                    {
                        m_Firestorm = true;

                        Talk(eTalks::TalkFirestorm);
                        Talk(eTalks::TalkFirestormWarn);

                        std::list<Creature*> l_CinderWolves;
                        GetCreatureListWithEntryInGrid(l_CinderWolves,me, eFoundryCreatures::CinderWolf, 200.0f);
                        GetCreatureListWithEntryInGrid(l_CinderWolves,me, eCreatures::OverheatedCinderWolf, 200.0f);

                        for (Creature* l_Wolf : l_CinderWolves)
                        {
                            if (l_Wolf->IsAIEnabled)
                                l_Wolf->AI()->DoAction(eActions::ActionFirestorm);
                        }

                        me->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));
                        me->AddUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));

                        me->AddUnitState(UnitState::UNIT_STATE_ROOT);

                        me->StopMoving();

                        me->CastSpell(me, eSpells::FirestormSelfAura, true);

                        uint32 l_Timer = 2 * TimeConstants::IN_MILLISECONDS;
                      //  AddTimedDelayedOperation(l_Timer, [this]() -> void
                      //  {
                            me->CastSpell(me, eSpells::FirestormPeriodicTrigger, false);

                            if (Creature* l_LavaStalker = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::LavaStalker)))
                            {
                                if (l_LavaStalker->IsAIEnabled)
                                    l_LavaStalker->AI()->DoAction(eActions::ActionMagmaMonsoon);
                            }
                      //  });

                        l_Timer += 12 * TimeConstants::IN_MILLISECONDS;
                       // AddTimedDelayedOperation(l_Timer, [this]() -> void
                       // {
                            m_Firestorm = false;

                            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));
                            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));

                            me->ClearUnitState(UnitState::UNIT_STATE_ROOT);

                            if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO))
                                AttackStart(l_Target);
                       // });

                        m_Events.DelayEvents(eEvents::EventLavaSlash, l_Timer);

                        m_Events.CancelEvent(eEvents::EventMoltenTorrent);
                        m_Events.CancelEvent(eEvents::EventBlazingRadiance);
                        break;
                    }
                    case eEvents::EventBerserker:
                    {
                        me->CastSpell(me, eFoundrySpells::Berserker, true);
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
            return new boss_flamebender_kagrazAI(p_Creature);
        }
};

/// Aknor Steelbringer - 77337
class npc_foundry_aknor_steelbringer : public CreatureScript
{
    public:
        npc_foundry_aknor_steelbringer() : CreatureScript("npc_foundry_aknor_steelbringer") { }

        enum eSpells
        {
            DevastatingSlam         = 156018,
            /// Drop the Hammer
            DropTheHammerSearcher   = 156038,
            DropTheHammerJump       = 156039,
            DropTheHammerAoE        = 156040
        };

        enum eEvents
        {
            EventDevastatingSlam = 1,
            EventDropTheHammer
        };

        enum eTimers
        {
            TimerDevastatingSlam        = 6 * TimeConstants::IN_MILLISECONDS,
            TimerDevastatingSlamAgain   = 8 * TimeConstants::IN_MILLISECONDS,
            TimerDropTheHammer          = 10 * TimeConstants::IN_MILLISECONDS,
            TimerDropTheHammerAgain     = 8 * TimeConstants::IN_MILLISECONDS
        };

        enum eActions
        {
            AknorDied,
            DropTheHammer
        };

        struct npc_foundry_aknor_steelbringerAI : public ScriptedAI
        {
            npc_foundry_aknor_steelbringerAI(Creature* p_Creature) : ScriptedAI(p_Creature)
            {
                m_Instance = p_Creature->GetInstanceScript();
            }

            InstanceScript* m_Instance;

            EventMap m_Events;

            ObjectGuid m_HammerTarget;

            void Reset() override
            {
                m_Events.Reset();

              //  m_HammerTarget = 0;
            }

            void EnterCombat(Unit* p_Attacker) override
            {
                if (m_Instance != nullptr)
                {
                    if (Creature* l_Kagraz = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::BossFlamebenderKagraz)))
                    {
                        if (l_Kagraz->IsAIEnabled && !l_Kagraz->IsInCombat())
                            l_Kagraz->AI()->AttackStart(p_Attacker);
                    }

                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me, 2);
                }

                m_Events.ScheduleEvent(eEvents::EventDevastatingSlam, eTimers::TimerDevastatingSlam);
                m_Events.ScheduleEvent(eEvents::EventDropTheHammer, eTimers::TimerDropTheHammer);
            }

            void DoAction(int32 p_Action)
            {
                if (p_Action == eActions::DropTheHammer)
                {
                    if (Unit* l_Target = ObjectAccessor::GetUnit(*me, m_HammerTarget))
                        me->CastSpell(l_Target, eSpells::DropTheHammerJump, true);
                }
            }

            void MovementInform(uint32 /*p_Type*/, uint32 p_ID) override
            {
                if (p_ID == eSpells::DropTheHammerJump)
                    me->CastSpell(me, eSpells::DropTheHammerAoE, false);
            }

            void SpellHitTarget(Unit* p_Target, SpellInfo const* p_SpellInfo) override
            {
                if (p_Target == nullptr)
                    return;

                switch (p_SpellInfo->Id)
                {
                    case eSpells::DropTheHammerSearcher:
                    {
                        m_HammerTarget = p_Target->GetGUID();
                        break;
                    }
                    default:
                        break;
                }
            }

            void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER)
            {
                me->InterruptNonMeleeSpells(true);

                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                CreatureAI::EnterEvadeMode();
            }

            void JustDied(Unit* /*p_Killer*/) override
            {
                if (m_Instance == nullptr)
                    return;

                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                if (Creature* l_Kagraz = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eFoundryCreatures::BossFlamebenderKagraz)))
                {
                    if (l_Kagraz->IsAIEnabled)
                        l_Kagraz->AI()->DoAction(eActions::AknorDied);
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
                    case eEvents::EventDevastatingSlam:
                    {
                        me->CastSpell(me, eSpells::DevastatingSlam, false);
                        m_Events.ScheduleEvent(eEvents::EventDevastatingSlam, eTimers::TimerDevastatingSlamAgain);
                        break;
                    }
                    case eEvents::EventDropTheHammer:
                    {
                        me->CastSpell(me, eSpells::DropTheHammerSearcher, true);
                        m_Events.ScheduleEvent(eEvents::EventDropTheHammer, eTimers::TimerDropTheHammerAgain);
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
            return new npc_foundry_aknor_steelbringerAI(p_Creature);
        }
};

/// Flamebender Ka'graz Trigger - 76996
class npc_foundry_flamebender_kagraz_trigger : public CreatureScript
{
    public:
        npc_foundry_flamebender_kagraz_trigger() : CreatureScript("npc_foundry_flamebender_kagraz_trigger") { }

        enum eSpells
        {
            LavaSlashSearcherSecond     = 155357,
            LavaSlashMissile            = 155297,
            LavaSlashMissileTriggered   = 155318,
            LavaSlashAreaTrigger        = 154915
        };

        enum eCreature
        {
            FlamebenderKagrazTrigger = 76996
        };

        struct npc_foundry_flamebender_kagraz_triggerAI : public ScriptedAI
        {
            npc_foundry_flamebender_kagraz_triggerAI(Creature* p_Creature) : ScriptedAI(p_Creature)
            {
               // m_LavaSlashTarget = 0;
            }

            ObjectGuid m_LavaSlashTarget;

            std::queue<ObjectGuid> m_LavaSlashTargets;

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->AddUnitState(UnitState::UNIT_STATE_ROOT);

                me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_NOT_SELECTABLE));
            }

            void SetGUID(ObjectGuid p_Guid, int32 /*p_ID*/)
            {
                m_LavaSlashTarget = p_Guid;

                me->CastSpell(me, eSpells::LavaSlashSearcherSecond, true);
            }

            void JustSummoned(Creature* p_Summon) override { p_Summon->DespawnOrUnsummon(); }

            void SpellHitTarget(Unit* p_Target, SpellInfo const* p_SpellInfo) override
            {
                if (p_Target == nullptr)
                    return;

                switch (p_SpellInfo->Id)
                {
                    case eSpells::LavaSlashSearcherSecond:
                    {
                        if (p_Target->GetGUID() == m_LavaSlashTarget)
                            break;

                        m_LavaSlashTargets.push(p_Target->GetGUID());

                        me->CastSpell(p_Target, eSpells::LavaSlashMissile, true);
                        break;
                    }
                    default:
                        break;
                }
            }

            void SpellHitDest(SpellDestination const* p_Dest, SpellInfo const* p_SpellInfo)
            {
                if (p_Dest == nullptr)
                    return;

                switch (p_SpellInfo->Id)
                {
                    case eSpells::LavaSlashMissileTriggered:
                    {
                        Position l_Dest = p_Dest->_position;
                        Position l_Src  = *me;

                        //AddTimedDelayedOperation(50, [this, l_Dest, l_Src]() -> void
                       // {
                            if (Creature* l_Kagraz = me->FindNearestCreature(eFoundryCreatures::BossFlamebenderKagraz, 100.0f))
                            {
                                uint8 l_Dist = (uint8)l_Src.GetExactDist2d(&l_Dest);
                                for (uint8 l_I = 0; l_I < l_Dist; ++l_I)
                                {
                                    Position l_Target;

                                    float l_O = l_Src.GetAngle(&l_Dest);
                                    float l_X = l_Src.m_positionX + (l_I * cos(l_O));
                                    float l_Y = l_Src.m_positionY + (l_I * sin(l_O));
                                    float l_Z = l_Src.m_positionZ;

                                   // l_Target.m_positionX    = l_X;
                                   // l_Target.m_positionY    = l_Y;
                                   // l_Target.m_positionZ    = l_Z;
                                    //l_Target.m_orientation  = l_O;

                                    l_Kagraz->CastSpell(l_Target.m_positionX = l_X, l_Target.m_positionY = l_Y, l_Target.m_positionZ = l_Z, eSpells::LavaSlashAreaTrigger, true);
                                }
                            }
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
            return new npc_foundry_flamebender_kagraz_triggerAI(p_Creature);
        }
};

/// Enchanted Armament - 77709
class npc_foundry_kagraz_enchanted_armament : public CreatureScript
{
    public:
        npc_foundry_kagraz_enchanted_armament() : CreatureScript("npc_foundry_kagraz_enchanted_armament") { }

        enum eSpells
        {
            EnchantArmamentJump = 163153,
            UnquenchableFlame   = 156689
        };

        enum eVisual
        {
            AnimID = 6250
        };

        struct npc_foundry_kagraz_enchanted_armamentAI : public ScriptedAI
        {
            npc_foundry_kagraz_enchanted_armamentAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

            void Reset() override
            {
                me->SetAIAnimKitId(eVisual::AnimID);

                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_NOT_SELECTABLE));
            }

            void MovementInform(uint32 p_Type, uint32 p_ID) override
            {
                if (p_Type != MovementGeneratorType::EFFECT_MOTION_TYPE)
                    return;

                if (p_ID == eSpells::EnchantArmamentJump)
                {
                    me->SetAIAnimKitId(0);

                    me->AddUnitState(UnitState::UNIT_STATE_ROOT);

                    me->CastSpell(me, eSpells::UnquenchableFlame, false);
                }
            }

            void SetGUID(ObjectGuid p_Guid, int32 /*p_ID*/=0)
            {
              //  AddTimedDelayedOperation(50, [this, p_Guid]() -> void
               // {
                  //  if (Player* l_Player = l_Target.m_positionZ = l_Z::GetPlayer(*me, p_Guid))
                        me->CastSpell(me, eSpells::EnchantArmamentJump, true);
               // });
            }

            void DamageTaken(Unit* /*p_Attacker*/, uint32& p_Damage) override
            {
                p_Damage = 0;
            }

            void UpdateAI(uint32 p_Diff) override
            {
              //  UpdateOperations(p_Diff);
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_kagraz_enchanted_armamentAI(p_Creature);
        }
};

/// Lava Stalker - 77043
class npc_foundry_lava_stalker : public CreatureScript
{
    public:
        npc_foundry_lava_stalker() : CreatureScript("npc_foundry_lava_stalker") { }

        enum eSpells
        {
            SummonCinderWolves  = 155776,
            FirestormV2Periodic = 168996
        };

        enum eActions
        {
            ActionOverheated,
            ActionFixated,
            ActionFillStalkers,
            ActionMagmaMonsoon = 1
        };

        enum eCreature
        {
            FirestormStalker = 80947
        };

        struct npc_foundry_lava_stalkerAI : public ScriptedAI
        {
            npc_foundry_lava_stalkerAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

            std::list<ObjectGuid> m_FirestormStalkers;
            std::queue<ObjectGuid> m_FirestormStalkersQueue;

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UnitFlags::UNIT_FLAG_REMOVE_CLIENT_CONTROL | UnitFlags::UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE));

                me->RemoveAura(eSpells::FirestormV2Periodic);

                me->RemoveAllAreaTriggers();

               // AddTimedDelayedOperation(2 * TimeConstants::IN_MILLISECONDS, [this]() -> void
               // {
                    if (m_FirestormStalkers.empty() || m_FirestormStalkersQueue.empty())
                    {
                        m_FirestormStalkers.clear();

                        while (!m_FirestormStalkersQueue.empty())
                            m_FirestormStalkersQueue.pop();

                        std::list<Creature*> l_StalkerList;
                        me->GetCreatureListWithEntryInGrid(l_StalkerList, eCreature::FirestormStalker, 100.0f);

                        for (Creature* l_Stalker : l_StalkerList)
                        {
                            m_FirestormStalkers.push_back(l_Stalker->GetGUID());
                            m_FirestormStalkersQueue.push(l_Stalker->GetGUID());
                        }
                    }
              //  });
            }

            void SpellHit(Unit* p_Attacker, SpellInfo const* p_SpellInfo) override
            {
                if (p_SpellInfo->Id == eSpells::SummonCinderWolves && p_Attacker != nullptr)
                {
                    ObjectGuid l_TargetGUID = p_Attacker->GetVictim() != nullptr ? p_Attacker->GetVictim()->GetGUID():GetGUID(0);
                   // AddTimedDelayedOperation(2 * TimeConstants::IN_MILLISECONDS, [this, l_TargetGUID]() -> void
                   // {
                        Creature* l_Frist   = nullptr;
                        Creature* l_Second  = nullptr;

                        for (uint8 l_I = 0; l_I < 2; ++l_I)
                        {
                            if (Creature* l_Wolf = me->SummonCreature(eFoundryCreatures::CinderWolf, g_CinderWolfSpawnPos))
                            {
                                if (l_I == 0)
                                    l_Frist = l_Wolf;
                                else
                                    l_Second = l_Wolf;

                                if (l_Wolf->IsAIEnabled)
                                {
                                    if (Unit* l_Target = ObjectAccessor::GetUnit(*me, l_TargetGUID))
                                        l_Wolf->AI()->AttackStart(l_Target);

                                    l_Wolf->AI()->DoAction(l_I == 0 ? eActions::ActionOverheated : eActions::ActionFixated);
                                }
                            }
                        }

                        if (l_Frist->IsAIEnabled && l_Second->IsAIEnabled)
                        {
                            l_Frist->AI()->SetGUID(l_Second->GetGUID(), 0);
                            l_Second->AI()->SetGUID(l_Frist->GetGUID(), 0);
                        }
                   // });
                }
            }

            void DoAction(int32 p_Action)
            {
                switch (p_Action)
                {
                    case eActions::ActionMagmaMonsoon:
                    {
                        me->CastSpell(me, eSpells::FirestormV2Periodic, true);
                        break;
                    }
                    case eActions::ActionFillStalkers:
                    {
                        /// Order doesn't matter
                        for (ObjectGuid l_Guid : m_FirestormStalkers)
                            m_FirestormStalkersQueue.push(l_Guid);

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

            ObjectGuid GetNextStalkerGUID()
            {
                if (m_FirestormStalkersQueue.empty())
                    return ObjectGuid::Empty;

                ObjectGuid l_Guid = m_FirestormStalkersQueue.front();

                m_FirestormStalkersQueue.pop();

                return l_Guid;
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_lava_stalkerAI(p_Creature);
        }
};

/// Molten Torrent Stalker - 77253
class npc_foundry_molten_torrent_stalker : public CreatureScript
{
    public:
        npc_foundry_molten_torrent_stalker() : CreatureScript("npc_foundry_molten_torrent_stalker") { }

        enum eSpells
        {
            PrefightCosmeticsStalker    = 156255,
            MoltenTorrentAreaTrigger    = 155847,
            MoltenTorrentVisual         = 155890,
            FirestormV2Periodic         = 163641,
            FirestormV2PickStalker      = 163634,
            FirestormV2Targeting        = 163632,
            FirestormV2Missile          = 163636
        };

        enum eActions
        {
            ActionMoltenTorrent,
            ActionMagmaMonsoon
        };

        struct npc_foundry_molten_torrent_stalkerAI : public ScriptedAI
        {
            npc_foundry_molten_torrent_stalkerAI(Creature* p_Creature) : ScriptedAI(p_Creature)
            {
               // m_MoltenTorrentTarget = 0;
            }

            ObjectGuid m_MoltenTorrentTarget;

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL | UnitFlags::UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE));

                me->CastSpell(me, eSpells::PrefightCosmeticsStalker, true);

                me->RemoveAura(eSpells::FirestormV2Periodic);

                me->RemoveAllAreaTriggers();
            }

            void EnterCombat(Unit* /*p_Attacker*/) override
            {
                me->RemoveAura(eSpells::PrefightCosmeticsStalker);
            }

            void AreaTriggerDespawned(AreaTrigger* /*p_AreaTrigger*/)
            {
                if (Unit* l_Target = ObjectAccessor::GetUnit(*me, m_MoltenTorrentTarget))
                    me->CastSpell(l_Target, eSpells::MoltenTorrentVisual, true);
            }

            void SpellHitTarget(Unit* p_Target, SpellInfo const* p_SpellInfo) override
            {
                if (p_Target == nullptr)
                    return;

                switch (p_SpellInfo->Id)
                {
                    case eSpells::FirestormV2Targeting:
                    {
                        me->CastSpell(p_Target, eSpells::FirestormV2Missile, true);
                        break;
                    }
                    default:
                        break;
                }
            }

            void SpellHit(Unit* /*p_Attacker*/, SpellInfo const* p_SpellInfo) override
            {
                switch (p_SpellInfo->Id)
                {
                    case eSpells::FirestormV2PickStalker:
                    {
                        me->CastSpell(me, eSpells::FirestormV2Targeting, true);
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
                    case eActions::ActionMoltenTorrent:
                    {
                        me->CastSpell(me, eSpells::MoltenTorrentAreaTrigger, true);
                        break;
                    }
                    case eActions::ActionMagmaMonsoon:
                    {
                        me->CastSpell(me, eSpells::FirestormV2Periodic, true);
                        break;
                    }
                    default:
                        break;
                }
            }

            void SetGUID(ObjectGuid p_Guid, int32 /*p_ID*/) override
            {
                m_MoltenTorrentTarget = p_Guid;
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_molten_torrent_stalkerAI(p_Creature);
        }
};

/// Firestorm Stalker - 80947
class npc_foundry_firestorm_stalker : public CreatureScript
{
    public:
        npc_foundry_firestorm_stalker() : CreatureScript("npc_foundry_firestorm_stalker") { }

        enum eSpells
        {
            FirestormV2PickStalker      = 163634,
            FirestormV2Targeting        = 163632,
            FirestormV2Missile          = 163636,
            FirestormAreatrigger        = 163630
        };

        struct npc_foundry_firestorm_stalkerAI : public ScriptedAI
        {
            npc_foundry_firestorm_stalkerAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

            void SpellHitTarget(Unit* p_Target, SpellInfo const* p_SpellInfo) override
            {
                if (p_Target == nullptr)
                    return;

                switch (p_SpellInfo->Id)
                {
                    case eSpells::FirestormV2Targeting:
                    {
                       // if (AreaTrigger* l_AT = me->FindNearestAreaTrigger(eSpells::FirestormAreatrigger, 0.5f))
                         //   l_AT->SetDuration(0);
                       // else
                         //   break;

                        me->CastSpell(p_Target, eSpells::FirestormV2Missile, true);
                        break;
                    }
                    default:
                        break;
                }
            }

            void SpellHit(Unit* /*p_Attacker*/, SpellInfo const* p_SpellInfo) override
            {
                switch (p_SpellInfo->Id)
                {
                    case eSpells::FirestormV2PickStalker:
                    {
                        me->CastSpell(me, eSpells::FirestormV2Targeting, true);
                        break;
                    }
                    default:
                        break;
                }
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_firestorm_stalkerAI(p_Creature);
        }
};

/// Cinder Wolf - 76794
class npc_foundry_cinder_wolf : public CreatureScript
{
    public:
        npc_foundry_cinder_wolf() : CreatureScript("npc_foundry_cinder_wolf") { }

        enum eSpells
        {
            ReduceCriticalChance    = 64481,
            JumpOutOfLava           = 155571,
            FieryLink               = 154961,
            Downed                  = 155068,
            Rekindle                = 155064,
            OverheatedAura          = 154950,
            CharringBreathJump      = 155745,
            CharringBreathDamage    = 155074,
            Fixate                  = 154952,
            Disabled                = 156538,
            Firestorm               = 155704
        };

        enum eEvent
        {
            EventCharringBreath = 1
        };

        enum eActions
        {
            ActionOverheated,
            ActionFixated,
            ActionFirestorm,
            ActionFixatedAgain
        };

        enum eEntry
        {
            OverheatedCinderWolf = 78912
        };

        struct npc_foundry_cinder_wolfAI : public ScriptedAI
        {
            npc_foundry_cinder_wolfAI(Creature* p_Creature) : ScriptedAI(p_Creature)
            {
                m_Instance      = p_Creature->GetInstanceScript();
                m_Initialized   = false;
                m_Rekindle      = false;
                m_CurrAction    = eActions::ActionOverheated;
              //  m_Target        = 0;
              //  m_OtherWolf     = 0;
            }

            InstanceScript* m_Instance;

            bool m_Initialized;
            bool m_Rekindle;

            EventMap m_Events;

            eActions m_CurrAction;

            ObjectGuid m_Target;
            ObjectGuid m_OtherWolf;

            void Reset() override
            {
                me->ApplySpellImmune(0, SpellImmunity::IMMUNITY_EFFECT, SpellEffectName::SPELL_EFFECT_INTERRUPT_CAST, true);
                me->ApplySpellImmune(0, SpellImmunity::IMMUNITY_EFFECT, SpellEffectName::SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, SpellImmunity::IMMUNITY_EFFECT, SpellEffectName::SPELL_EFFECT_KNOCK_BACK_DEST, true);

                me->ApplySpellImmune(0, SpellImmunity::IMMUNITY_STATE, AuraType::SPELL_AURA_MOD_CONFUSE, true);
                me->ApplySpellImmune(0, SpellImmunity::IMMUNITY_STATE, AuraType::SPELL_AURA_MOD_STUN, true);

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

                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_DISARMED));

                me->AddUnitState(UnitState::UNIT_STATE_IGNORE_PATHFINDING);

                m_Events.Reset();

                me->CastSpell(me, eSpells::ReduceCriticalChance, true);

               // AddTimedDelayedOperation(100, [this]() -> void
               // {
                    float l_O = frand(3.7f, 5.6f);

                    me->SetFacingTo(l_O);
              //  });

              //  AddTimedDelayedOperation(200, [this]() -> void
              //  {
                    float l_Radius  = 19.0f;
                   // float l_O       = me->GetOrientation();

                    float l_X, l_Y, l_Z;

                    l_X = me->GetPositionX() + (l_Radius * cos(l_O));
                    l_Y = me->GetPositionY() + (l_Radius * sin(l_O));
                    l_Z = 105.64f;

                    me->CastSpell( l_X, l_Y, l_Z , eSpells::JumpOutOfLava, true);
              //  });

               // AddTimedDelayedOperation(300, [this]() -> void
               // {
                    if (me->HasAura(eSpells::FieryLink))
                        return;

                    if (Creature* l_Other = ObjectAccessor::GetCreature(*me, m_OtherWolf))
                    {
                        me->CastSpell(l_Other, eSpells::FieryLink, true);

                        m_Initialized = true;

                        if (npc_foundry_cinder_wolf::npc_foundry_cinder_wolfAI* l_AI = CAST_AI(npc_foundry_cinder_wolf::npc_foundry_cinder_wolfAI, l_Other->GetAI()))
                            l_AI->m_Initialized = true;
                    }

                //});
            }

            void EnterCombat(Unit* /*p_Attacker*/) override
            {
                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me, 2);
            }

            void DamageTaken(Unit* /*p_Attacker*/, uint32& p_Damage) override
            {
                if (m_Rekindle)
                {
                    p_Damage = 0;
                    return;
                }

                if (p_Damage >= me->GetHealth())
                {
                    if (Creature* l_Other = ObjectAccessor::GetCreature(*me, m_OtherWolf))
                    {
                        if (npc_foundry_cinder_wolf::npc_foundry_cinder_wolfAI* l_AI = CAST_AI(npc_foundry_cinder_wolf::npc_foundry_cinder_wolfAI, l_Other->GetAI()))
                        {
                            /// Other Cinder Wolf is already in Rekindle state, then kill both of them
                            if (l_AI->m_Rekindle)
                            {
                                l_AI->me->CastSpell(l_AI->me, eSpells::Disabled, true);
                                me->CastSpell(me, eSpells::Disabled, true);

                                l_AI->me->AttackStop();
                                me->AttackStop();

                                l_AI->me->SetReactState(ReactStates::REACT_PASSIVE);
                                me->SetReactState(ReactStates::REACT_PASSIVE);

                                l_AI->me->DespawnOrUnsummon(200);
                                me->DespawnOrUnsummon(200);

                                p_Damage = 0;
                                return;
                            }
                        }

                        /// Found!
                        m_Rekindle = true;
                        p_Damage = 0;

                        me->SetHealth(1);

                        ///ClearDelayedOperations();

                        me->CastSpell(me, eSpells::Downed, true);
                        me->CastSpell(me, eSpells::Rekindle, false);
                    }
                }
            }

            void JustDied(Unit* /*p_Killer*/) override
            {
                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                me->DespawnOrUnsummon(5 * TimeConstants::IN_MILLISECONDS);
            }

            /// In case of unexpected reset
            void JustDespawned()
            {
                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void SpellHitTarget(Unit* p_Target, SpellInfo const* p_SpellInfo) override
            {
                if (p_Target == nullptr)
                    return;

                switch (p_SpellInfo->Id)
                {
                    case eSpells::Rekindle:
                    {
                        me->RemoveAura(eSpells::Downed);

                        m_Rekindle = false;

                        if (m_CurrAction == eActions::ActionFixated)
                            DoAction(m_CurrAction);

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
                    default:
                        break;
                }
            }

            void MovementInform(uint32 p_Type, uint32 p_ID) override
            {
                if (p_Type != MovementGeneratorType::EFFECT_MOTION_TYPE)
                    return;

                if (p_ID == eSpells::CharringBreathJump && m_CurrAction == eActions::ActionFixated)
                    me->CastSpell(me, eSpells::Fixate, true);
            }

            void DoAction(int32 p_Action)
            {
                if (m_Initialized)
                  //  ClearDelayedOperations();

                switch (p_Action)
                {
                    case eActions::ActionOverheated:
                    {
                       // m_Target        = 0;
                        m_CurrAction    = eActions::ActionOverheated;

                        me->SetEntry(eEntry::OverheatedCinderWolf);

                        me->ApplySpellImmune(0, SpellImmunity::IMMUNITY_STATE, AuraType::SPELL_AURA_MOD_TAUNT, false);
                        me->ApplySpellImmune(0, SpellImmunity::IMMUNITY_EFFECT, SpellEffectName::SPELL_EFFECT_ATTACK_ME, false);

                      //  AddTimedDelayedOperation(m_Initialized ? 50 : 400, [this]() -> void
                      //  {
                            me->CastSpell(me, eSpells::OverheatedAura, true);

                            m_Events.ScheduleEvent(eEvent::EventCharringBreath, 7 * TimeConstants::IN_MILLISECONDS);

                            if (Creature* l_Other = ObjectAccessor::GetCreature(*me, m_OtherWolf))
                            {
                               // me->ClearAllUnitState();
                               // l_Other->ClearAllUnitState();

                                me->InterruptNonMeleeSpells(true);
                                l_Other->InterruptNonMeleeSpells(true);

                                //Position l_Dest = *l_Other;
                               // Position l_Src  = *me;

                                l_Other->CastSpell(me, eSpells::CharringBreathJump, true);
                                me->CastSpell(l_Other, eSpells::CharringBreathJump, true);
                            }
                      //  });

                        break;
                    }
                    case eActions::ActionFixated:
                    {
                       // m_Target        = 0;
                        m_CurrAction    = eActions::ActionFixated;

                        me->ApplySpellImmune(0, SpellImmunity::IMMUNITY_STATE, AuraType::SPELL_AURA_MOD_TAUNT, true);
                        me->ApplySpellImmune(0, SpellImmunity::IMMUNITY_EFFECT, SpellEffectName::SPELL_EFFECT_ATTACK_ME, true);

                        m_Events.CancelEvent(eEvent::EventCharringBreath);
                        break;
                    }
                    case eActions::ActionFirestorm:
                    {
                      //  AddTimedDelayedOperation(2 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                       // {
                            me->CastSpell(me, eSpells::Firestorm, true);
                       // });

                        break;
                    }
                    case eActions::ActionFixatedAgain:
                    {
                      //  m_Target = 0;

                        me->CastSpell(me, eSpells::Fixate, true);
                        break;
                    }
                    default:
                        break;
                }
            }

            void SetGUID(ObjectGuid p_Guid, int32 /*p_ID*/) 
            {
                m_OtherWolf = p_Guid;
            }

            void UpdateAI(uint32 p_Diff) override
            {
               // UpdateOperations(p_Diff);

                if (!UpdateVictim())
                    return;

                m_Events.Update(p_Diff);

                if (me->HasUnitState(UnitState::UNIT_STATE_CASTING) || me->HasUnitState(UnitState::UNIT_STATE_STUNNED))
                    return;

                if (Player* l_Target = ObjectAccessor::GetPlayer(*me, m_Target))
                {
                    if (!l_Target->IsAlive())
                    {
                        //m_Target = 0;
                        me->CastSpell(me, eSpells::Fixate, true);
                        return;
                    }

                    if (!me->IsWithinMeleeRange(l_Target))
                        me->GetMotionMaster()->MovePoint(0, *l_Target);
                }

                if (m_Events.ExecuteEvent() == eEvent::EventCharringBreath && m_CurrAction == eActions::ActionOverheated)
                {
                    if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO))
                        me->SetFacingTo(me->GetAngle(l_Target));

                   // AddTimedDelayedOperation(50, [this]() -> void
                  //  {
                        me->CastSpell(me, eSpells::CharringBreathDamage, true);
                   // });

                    m_Events.ScheduleEvent(eEvent::EventCharringBreath, 7 * TimeConstants::IN_MILLISECONDS);
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* p_Creature) const override
        {
            return new npc_foundry_cinder_wolfAI(p_Creature);
        }
};

/// Drop the Hammer (aura) - 156038
class spell_foundry_drop_the_hammer_aura : public SpellScriptLoader
{
    public:
        spell_foundry_drop_the_hammer_aura() : SpellScriptLoader("spell_foundry_drop_the_hammer_aura") { }

        class spell_foundry_drop_the_hammer_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_foundry_drop_the_hammer_aura_AuraScript);

            enum eSpell
            {
                BodySlam = 155747
            };

            enum eAction
            {
                DropTheHammer = 1
            };

            void OnRemove(AuraEffect const* /*p_AurEff*/, AuraEffectHandleModes /*p_Mode*/)
            {
                AuraRemoveMode l_RemoveMode = GetTargetApplication()->GetRemoveMode();
                if (l_RemoveMode != AuraRemoveMode::AURA_REMOVE_BY_EXPIRE || GetCaster() == nullptr)
                    return;

                if (Creature* l_Aknor = GetCaster()->ToCreature())
                {
                    if (l_Aknor->IsAIEnabled)
                        l_Aknor->AI()->DoAction(eAction::DropTheHammer);
                }
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_foundry_drop_the_hammer_aura_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_foundry_drop_the_hammer_aura_AuraScript();
        }
};

/// Molten Torrent (aura) - 154932
class spell_foundry_molten_torrent_aura : public SpellScriptLoader
{
    public:
        spell_foundry_molten_torrent_aura() : SpellScriptLoader("spell_foundry_molten_torrent_aura") { }

        class spell_foundry_molten_torrent_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_foundry_molten_torrent_aura_AuraScript);

            enum eSpell
            {
                MoltenTorrentAoE = 154938
            };

            void OnRemove(AuraEffect const* /*p_AurEff*/, AuraEffectHandleModes /*p_Mode*/)
            {
                AuraRemoveMode l_RemoveMode = GetTargetApplication()->GetRemoveMode();
                if (l_RemoveMode != AuraRemoveMode::AURA_REMOVE_BY_EXPIRE)
                    return;

                if (Unit* l_Target = GetTarget())
                {
                    if (Unit* l_Caster = GetCaster())
                        l_Target->CastSpell(l_Target, eSpell::MoltenTorrentAoE, true, nullptr, nullptr, l_Caster->GetGUID());
                }
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_foundry_molten_torrent_aura_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_foundry_molten_torrent_aura_AuraScript();
        }
};

/// Allow Molten Torrent Cast - 155912
class spell_foundry_allow_molten_torrent_cast : public SpellScriptLoader
{
    public:
        spell_foundry_allow_molten_torrent_cast() : SpellScriptLoader("spell_foundry_allow_molten_torrent_cast") { }

        class spell_foundry_allow_molten_torrent_cast_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_foundry_allow_molten_torrent_cast_AuraScript);

            void OnRemove(AuraEffect const* /*p_AurEff*/, AuraEffectHandleModes /*p_Mode*/)
            {
                AuraRemoveMode l_RemoveMode = GetTargetApplication()->GetRemoveMode();
                if (l_RemoveMode != AuraRemoveMode::AURA_REMOVE_BY_EXPIRE || GetTarget() == nullptr)
                    return;

                if (Creature* l_Wolf = GetTarget()->ToCreature())
                {
                    if (l_Wolf->IsAIEnabled)
                    {
                        if (boss_flamebender_kagraz::boss_flamebender_kagrazAI* l_AI = CAST_AI(boss_flamebender_kagraz::boss_flamebender_kagrazAI, l_Wolf->GetAI()))
                        {
                          //  l_AI->AddTimedDelayedOperation(50, [this, l_AI]() -> void
                           // {
                              //  l_AI->me->CastSpell(l_AI->me, GetSpellInfo()->Id, true);
                          //  });
                        }
                    }
                }
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_foundry_allow_molten_torrent_cast_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_foundry_allow_molten_torrent_cast_AuraScript();
        }
};

/// Fiery Link - 154961
class spell_foundry_fiery_link : public SpellScriptLoader
{
    public:
        spell_foundry_fiery_link() : SpellScriptLoader("spell_foundry_fiery_link") { }

        class spell_foundry_fiery_link_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_foundry_fiery_link_AuraScript);

            enum eSpell
            {
                Singe = 155049
            };

            void OnTick(AuraEffect const* /*p_AurEff*/)
            {
                if (Unit* l_Caster = GetCaster())
                {
                    if (Unit* l_Target = GetTarget())
                    {
                        float l_Radius = l_Caster->GetDistance(l_Target);

                        std::list<Player*> l_PlayerList;
                        l_Caster->GetPlayerListInGrid(l_PlayerList, l_Radius);

                        for (Player* l_Player : l_PlayerList)
                        {
                            if (!l_Player->IsInBetween(l_Caster, l_Target, 1.0f))
                                continue;

                            l_Caster->CastSpell(l_Player, eSpell::Singe, true);
                        }
                    }
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_foundry_fiery_link_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_foundry_fiery_link_AuraScript();
        }
};

/// Overheated - 154950
class spell_foundry_overheated : public SpellScriptLoader
{
    public:
        spell_foundry_overheated() : SpellScriptLoader("spell_foundry_overheated") { }

        class spell_foundry_overheated_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_foundry_overheated_AuraScript);

            enum eActions
            {
                ActionOverheated,
                ActionFixated
            };

            void OnRemove(AuraEffect const* /*p_AurEff*/, AuraEffectHandleModes /*p_Mode*/)
            {
                AuraRemoveMode l_RemoveMode = GetTargetApplication()->GetRemoveMode();
                if (l_RemoveMode != AuraRemoveMode::AURA_REMOVE_BY_EXPIRE || GetTarget() == nullptr)
                    return;

                if (Creature* l_Target = GetTarget()->ToCreature())
                {
                    if (l_Target->IsAIEnabled)
                    {
                        l_Target->SetEntry(eFoundryCreatures::CinderWolf);
                        l_Target->AI()->DoAction(eActions::ActionFixated);

                        if (npc_foundry_cinder_wolf::npc_foundry_cinder_wolfAI* l_AI = CAST_AI(npc_foundry_cinder_wolf::npc_foundry_cinder_wolfAI, l_Target->GetAI()))
                        {
                            if (Creature* l_Other = ObjectAccessor::GetCreature(*l_Target, l_AI->m_OtherWolf))
                            {
                                if (l_Other->IsAIEnabled)
                                    l_Other->AI()->DoAction(eActions::ActionOverheated);
                            }
                        }
                    }
                }
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_foundry_overheated_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_foundry_overheated_AuraScript();
        }
};

/// Fixate - 154952
class spell_foundry_fixate : public SpellScriptLoader
{
    public:
        spell_foundry_fixate() : SpellScriptLoader("spell_foundry_fixate") { }

        class spell_foundry_fixate_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_foundry_fixate_SpellScript);

            enum eSpell
            {
                FirestormAreatrigger = 163630
            };

            void CorrectTargets(std::list<WorldObject*>& p_Targets)
            {
                p_Targets.clear();

                if (Creature* l_Wolf = GetCaster()->ToCreature())
                {
                    if (npc_foundry_cinder_wolf::npc_foundry_cinder_wolfAI* l_AI = CAST_AI(npc_foundry_cinder_wolf::npc_foundry_cinder_wolfAI, l_Wolf->GetAI()))
                    {
                       // if (Player* l_Target = l_AI->SelectRangedTarget())
                           // p_Targets.push_back(l_Target);
                    }
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_foundry_fixate_SpellScript::CorrectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_foundry_fixate_SpellScript();
        }

        class spell_foundry_fixate_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_foundry_fixate_AuraScript);

            enum eAction
            {
                ActionFixatedAgain = 3
            };

            void OnRemove(AuraEffect const* /*p_AurEff*/, AuraEffectHandleModes /*p_Mode*/)
            {
                AuraRemoveMode l_RemoveMode = GetTargetApplication()->GetRemoveMode();
                if (l_RemoveMode != AuraRemoveMode::AURA_REMOVE_BY_EXPIRE || GetCaster() == nullptr)
                    return;

                if (Creature* l_Caster = GetCaster()->ToCreature())
                {
                    if (l_Caster->IsAIEnabled)
                        l_Caster->AI()->DoAction(eAction::ActionFixatedAgain);
                }
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_foundry_fixate_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_foundry_fixate_AuraScript();
        }
};

/// Firestorm (aura) - 155493
class spell_foundry_firestorm_aura : public SpellScriptLoader
{
    public:
        spell_foundry_firestorm_aura() : SpellScriptLoader("spell_foundry_firestorm_aura") { }

        class spell_foundry_firestorm_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_foundry_firestorm_aura_AuraScript);

            enum eAction
            {
                ActionMagmaMonsoon = 1
            };

            void OnRemove(AuraEffect const* /*p_AurEff*/, AuraEffectHandleModes /*p_Mode*/)
            {
                AuraRemoveMode l_RemoveMode = GetTargetApplication()->GetRemoveMode();
                if (l_RemoveMode != AuraRemoveMode::AURA_REMOVE_BY_EXPIRE || GetTarget() == nullptr)
                    return;

                if (Creature* l_Target = GetTarget()->ToCreature())
                {
                    if (boss_flamebender_kagraz::boss_flamebender_kagrazAI* l_AI = CAST_AI(boss_flamebender_kagraz::boss_flamebender_kagrazAI, l_Target->GetAI()))
                    {
                       // l_AI->AddTimedDelayedOperation(2 * TimeConstants::IN_MILLISECONDS, [l_AI]() -> void
                       // {
                            l_AI->DoAction(eAction::ActionMagmaMonsoon);
                        //});
                    }
                }
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_foundry_firestorm_aura_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_foundry_firestorm_aura_AuraScript();
        }
};

/// Firestorm V2 Periodic (Lava Stalker) - 168996
class spell_foundry_firestorm_v2_periodic_lava_stalker : public SpellScriptLoader
{
    public:
        spell_foundry_firestorm_v2_periodic_lava_stalker() : SpellScriptLoader("spell_foundry_firestorm_v2_periodic_lava_stalker") { }

        class spell_foundry_firestorm_v2_periodic_lava_stalker_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_foundry_firestorm_v2_periodic_lava_stalker_AuraScript);

            enum eSpell
            {
                FirestormAreatrigger = 163630
            };

            enum eAction
            {
                ActionFillStalkers = 2
            };

            void OnTick(AuraEffect const* /*p_AurEff*/)
            {
                if (GetCaster() == nullptr)
                    return;

                if (Creature* l_Caster = GetCaster()->ToCreature())
                {
                    if (!l_Caster->IsAIEnabled)
                        return;

                    if (npc_foundry_lava_stalker::npc_foundry_lava_stalkerAI* l_AI = CAST_AI(npc_foundry_lava_stalker::npc_foundry_lava_stalkerAI, l_Caster->GetAI()))
                    {
                        if (Creature* l_Stalker = ObjectAccessor::GetCreature(*l_Caster, l_AI->GetNextStalkerGUID()))
                            l_Caster->CastSpell(l_Stalker, eSpell::FirestormAreatrigger, true);
                    }
                }
            }

            void AfterRemove(AuraEffect const* /*p_AurEff*/, AuraEffectHandleModes /*p_Mode*/)
            {
                if (GetCaster() == nullptr)
                    return;

                if (Creature* l_Caster = GetCaster()->ToCreature())
                {
                    if (l_Caster->IsAIEnabled)
                        l_Caster->AI()->DoAction(eAction::ActionFillStalkers);
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_foundry_firestorm_v2_periodic_lava_stalker_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_foundry_firestorm_v2_periodic_lava_stalker_AuraScript::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_foundry_firestorm_v2_periodic_lava_stalker_AuraScript();
        }
};

/// Firestorm V2 - Pick Stalker to Fire - 163634
class spell_foundry_firestorm_v2_pick_stalker_to_fire : public SpellScriptLoader
{
    public:
        spell_foundry_firestorm_v2_pick_stalker_to_fire() : SpellScriptLoader("spell_foundry_firestorm_v2_pick_stalker_to_fire") { }

        class spell_foundry_firestorm_v2_pick_stalker_to_fire_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_foundry_firestorm_v2_pick_stalker_to_fire_SpellScript);

            enum eSpell
            {
                FirestormAreatrigger = 163630
            };

            void CorrectTargets(std::list<WorldObject*>& p_Targets)
            {
                if (p_Targets.empty())
                    return;

                p_Targets.remove_if([this](WorldObject* p_Object) -> bool
                {
                    if (p_Object == nullptr || p_Object->ToUnit() == nullptr)
                        return true;

                    if (!p_Object->ToUnit()->HasAura(eSpell::FirestormAreatrigger))
                        return true;

                    return false;
                });
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_foundry_firestorm_v2_pick_stalker_to_fire_SpellScript::CorrectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_foundry_firestorm_v2_pick_stalker_to_fire_SpellScript();
        }
};

/// Unquenchable Flame - 156689
class spell_foundry_unquenchable_flame_periodic : public SpellScriptLoader
{
    public:
        spell_foundry_unquenchable_flame_periodic() : SpellScriptLoader("spell_foundry_unquenchable_flame_periodic") { }

        class spell_foundry_unquenchable_flame_periodic_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_foundry_unquenchable_flame_periodic_AuraScript);

            enum eSpell
            {
                UnquenchableFlameAoE = 156713
            };

            void OnTick(AuraEffect const* /*p_AurEff*/)
            {
                if (Unit* l_Caster = GetCaster())
                    l_Caster->CastSpell(l_Caster, eSpell::UnquenchableFlameAoE, false);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_foundry_unquenchable_flame_periodic_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_foundry_unquenchable_flame_periodic_AuraScript();
        }
};

/// Blazing Radiance - 155382
class spell_foundry_blazing_radiance : public SpellScriptLoader
{
    public:
        spell_foundry_blazing_radiance() : SpellScriptLoader("spell_foundry_blazing_radiance") { }

        class spell_foundry_blazing_radiance_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_foundry_blazing_radiance_SpellScript);

            void CorrectTargets(std::list<WorldObject*>& p_Targets)
            {
                if (p_Targets.empty())
                    return;

                p_Targets.remove_if([this](WorldObject* p_Object) -> bool
                {
                    if (p_Object == nullptr || !p_Object->IsPlayer())
                        return true;

                    Player* l_Player = p_Object->ToPlayer();
                  //  if (l_Player->GetRoleForGroup() == Roles::ROLE_TANK)
                    //    return true;

                    return false;
                });
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_foundry_blazing_radiance_SpellScript::CorrectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_foundry_blazing_radiance_SpellScript();
        }
};

/// Lava Slash - 154915
class areatrigger_foundry_lava_slash_pool : public AreaTriggerEntityScript
{
    public:
        areatrigger_foundry_lava_slash_pool() : AreaTriggerEntityScript("areatrigger_foundry_lava_slash_pool") { }

        enum eSpell
        {
            LavaSlashDoT = 155314
        };

        std::set<ObjectGuid> m_AffectedPlayers;

        void OnUpdate(AreaTrigger* p_AreaTrigger, uint32 /*p_Time*/) 
        {
            if (Unit* l_Caster = p_AreaTrigger->GetCaster())
            {
                std::list<Unit*> l_TargetList;
                float l_Radius = 0.5f;

                Trinity::AnyUnfriendlyUnitInObjectRangeCheck l_Check(p_AreaTrigger, l_Caster, l_Radius);
                Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> l_Searcher(p_AreaTrigger, l_TargetList, l_Check);
               // p_AreaTrigger->VisitNearbyObject(l_Radius, l_Searcher);

                std::set<ObjectGuid> l_Targets;

                for (Unit* l_Iter : l_TargetList)
                {
                    l_Targets.insert(l_Iter->GetGUID());

                    if (!l_Iter->HasAura(eSpell::LavaSlashDoT))
                    {
                        m_AffectedPlayers.insert(l_Iter->GetGUID());
                        l_Iter->CastSpell(l_Iter, eSpell::LavaSlashDoT, true);
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
                        l_Unit->RemoveAura(eSpell::LavaSlashDoT);

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
                        l_Unit->RemoveAura(eSpell::LavaSlashDoT);
                }
            }
        }
        /*
        AreaTriggerEntityScript* GetAI()
        {
            return nullptr;
        }*/
};

/// Molten Torrent - 155847
class areatrigger_foundry_molten_torrent_ball : public AreaTriggerEntityScript
{
    public:
        areatrigger_foundry_molten_torrent_ball() : AreaTriggerEntityScript("areatrigger_foundry_molten_torrent_ball") { }

        enum eVisuals
        {
            OverrideScaleCurve = 32516
        };

        void OnCreate(AreaTrigger* p_AreaTrigger) 
        {
         //   p_AreaTrigger->SetUInt32Value(AreaTriggerFields::AREATRIGGER_OVERRIDE_SCALE_CURVE, eVisuals::OverrideScaleCurve);
        }
        /*
        AreaTriggerEntityScript* GetAI()
        {
            return nullptr;
        }*/
};

void AddSC_boss_flamebender_kagraz()
{
    /// Boss
    new boss_flamebender_kagraz();/// Flamebender Ka'graz <Shaman of the Burning Blade> - 76814

    /// Creatures
    new npc_foundry_aknor_steelbringer();/// Aknor Steelbringer - 77337
    new npc_foundry_flamebender_kagraz_trigger();/// Flamebender Ka'graz Trigger - 76996
    new npc_foundry_kagraz_enchanted_armament();/// Enchanted Armament - 77709
    new npc_foundry_lava_stalker();/// Lava Stalker - 77043
    new npc_foundry_cinder_wolf();/// Cinder Wolf - 76794
    new npc_foundry_molten_torrent_stalker();/// Molten Torrent Stalker - 77253
    new npc_foundry_firestorm_stalker();/// Firestorm Stalker - 80947

    /// Spells
    new spell_foundry_drop_the_hammer_aura();/// Drop the Hammer (aura) - 156038
    new spell_foundry_molten_torrent_aura();/// Molten Torrent (aura) - 154932
    new spell_foundry_fiery_link();/// Fiery Link - 154961
    new spell_foundry_overheated();/// Overheated - 154950
    new spell_foundry_fixate();/// Fixate - 154952
    new spell_foundry_firestorm_aura();/// Firestorm (aura) - 155493
    new spell_foundry_firestorm_v2_periodic_lava_stalker();/// Firestorm V2 Periodic (Lava Stalker) - 168996
    new spell_foundry_firestorm_v2_pick_stalker_to_fire();/// Firestorm V2 - Pick Stalker to Fire - 163634
    new spell_foundry_unquenchable_flame_periodic();/// Unquenchable Flame - 156689
    new spell_foundry_blazing_radiance();/// Blazing Radiance - 155382

    /// AreaTriggers
    new areatrigger_foundry_lava_slash_pool();/// Lava Slash - 154915
    new areatrigger_foundry_molten_torrent_ball();/// Molten Torrent - 155847
}
