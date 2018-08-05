/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2016 Firestorm Servers <https://firestorm-servers.com>
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

# include "highmaul.h"

Position const g_MaggotSpawnPos[eHighmaulDatas::MaxMaggotToKill] =
{
    { 3827.051f, 7690.205f, 23.67708f, 0.000f },
    { 3751.507f, 7722.538f, 23.65485f, 4.332f },
    { 3704.671f, 7700.851f, 23.60431f, 3.872f },
    { 3687.367f, 7626.960f, 23.64627f, 1.488f },
    { 3743.118f, 7607.410f, 23.86531f, 5.192f },
    { 3799.805f, 7675.845f, 23.04378f, 3.110f }
};

Position ComputeLocationSelection(Creature* source, float searchRange, float minRadius, float radius)
{
    using Cluster = std::set<Player*>;
    std::list<Player*> targets;

    source->GetPlayerListInGrid(targets, searchRange);

    if (!targets.empty())
    {
        targets.remove_if([source, minRadius](Player* player) -> bool
        {
            if (player == nullptr)
                return true;

            if (player->GetDistance(source) < minRadius)
                return true;

            return false;
        });
    }

    std::map<uint32, Cluster> clusterMap;

    for (Player* player : targets)
    {
        Cluster l_Neighboor;
        for (Player* playerSecond : targets)
        {
            float dist = player->GetDistance(playerSecond);
            if (dist <= radius)
                l_Neighboor.insert(playerSecond);
        }

        clusterMap[player->GetGUID().GetCounter()] = Cluster();
        clusterMap[player->GetGUID().GetCounter()].insert(player);

        for (Player* playerSecond : l_Neighboor)
            clusterMap[player->GetGUID().GetCounter()].insert(playerSecond);
    }

    size_t size = 0;
    for (auto cluster : clusterMap)
    {
        if (cluster.second.size() > size)
            size = cluster.second.size();
    }

    Position pos;
    for (auto cluster : clusterMap)
    {
        if (size && cluster.second.size() == size)
        {
            float l_X = 0.0f;
            float l_Y = 0.0f;

            for (Player* player : cluster.second)
            {
                l_X += player->GetPositionX();
                l_Y += player->GetPositionY();
            }

            l_X /= (uint32)size;
            l_Y /= (uint32)size;

            pos.Relocate(l_X, l_Y, source->GetPositionZ());
            break;
        }
    }

    return pos;
}

Position GetCleaveLocation(Creature* source)
{
    return ComputeLocationSelection(source, 5.0f, 0.0f, 5.0f);
}

Position GetBoundingCleaveLocation(Creature* source)
{
    return ComputeLocationSelection(source, 500.0f, 5.1f, 10.0f);
}

/// The Butcher - 77404
class boss_the_butcher : public CreatureScript
{
    public:
        boss_the_butcher() : CreatureScript("boss_the_butcher") { }

        enum eSpells
        {
            /// Heavy Handed
            HeavyHandedAura     = 156135,
            HeavyHandedProc     = 156138,
            /// The Cleaver
            TheCleaverDmg       = 156143,
            TheCleaverDot       = 156147,
            /// The Tenderizer
            TheTenderizer       = 156151,
            /// Meat Hook
            MeatHook            = 156125,
            MeatHookJump        = 156127,
            /// Bounding Cleave
            BoundingCleaveKnock = 156160,
            BoundingCleaveDummy = 156197,
            BoundingCleaveDmg   = 156172,
            BoundingCleaveCharg = 156171,
            /// Cleave
            SpellCleave         = 156157,
            SpellGushingWounds  = 156152,
            /// Energy management
            Angry5PerTick       = 156720,
            Angry10PerTick      = 160248,
            /// Frenzy (30%)
            SpellFrenzy         = 156598,
            /// Loot
            ButcherBonusLoot    = 177522
        };

        enum eEvents
        {
            EventTenderizer = 1,
            EventCleave,
            EventCleaver,
            EventBerserk,
            EventBoundingCleave,
            EventMeatHook,
            /// Mythic mode only
            EventCadaver
        };

        enum eTalks
        {
            Intro1,
            Intro2,
            Intro3, ///< Didn't see it on video
            Aggro,
            BoundingCleave,
            Frenzy,
            Cleave,
            Berserk,
            Slay,
            Wipe
        };

        enum eCreatures
        {
            NightTwistedCadaver = 82505,
            Maggot              = 80728
        };

        enum eAction
        {
            MaggotKilled
        };

        struct boss_the_butcherAI : public BossAI
        {
            boss_the_butcherAI(Creature* creature) : BossAI(creature, eHighmaulDatas::BossTheButcher)
            {
                m_Instance  = creature->GetInstanceScript();
                m_IntroDone = false;
            }

            EventMap m_Events;
            InstanceScript* m_Instance;

            bool m_IntroDone;

            /// Timers for prevent spamming for few abilities
            uint32 m_CleaveCooldown;

            /// Mythic mode only
            uint8 m_AddCount;

            std::set<uint8> m_MaggotSpawned;

            void Reset() override
            {
                m_Events.Reset();

                _Reset();

                me->RemoveAura(eSpells::SpellFrenzy);
                me->RemoveAura(eHighmaulSpells::Berserker);
                me->RemoveAura(eSpells::Angry5PerTick);
                me->RemoveAura(eSpells::Angry10PerTick);

                me->SetSpeed(UnitMoveType::MOVE_SWIM, me->GetSpeed(UnitMoveType::MOVE_RUN) * 0.5f);

                m_CleaveCooldown = 0;

                m_AddCount = 0;

                me->SetCanDualWield(true);

                /// Wrong flags remove
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISARMED | UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_PREPARATION);

                me->SetPower(Powers::POWER_ENERGY, 0);
                me->SetMaxPower(Powers::POWER_ENERGY, 100);
                me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_REGENERATE_POWER);

                if (m_Instance != nullptr)
                {
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::TheCleaverDot);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::TheTenderizer);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::SpellGushingWounds);
                }

                m_MaggotSpawned.clear();
            }

            void EnterCombat(Unit* /*attacker*/) override
            {
                _EnterCombat();

                me->CastSpell(me, eSpells::Angry5PerTick, true);

                Talk(eTalks::Aggro);

                m_Events.ScheduleEvent(eEvents::EventTenderizer, 6 * TimeConstants::IN_MILLISECONDS);
                m_Events.ScheduleEvent(eEvents::EventCleave, 10 * TimeConstants::IN_MILLISECONDS);
                m_Events.ScheduleEvent(eEvents::EventCleaver, 12 * TimeConstants::IN_MILLISECONDS);

                if (!IsLFR())
                    m_Events.ScheduleEvent(eEvents::EventBerserk, IsMythic() ? 240 * TimeConstants::IN_MILLISECONDS : 300 * TimeConstants::IN_MILLISECONDS);

                /// Meat Hook is an ability that The Butcher uses to pull his tank to him.
                /// We assume that this ability exists to prevent The Butcher from being kited,
                /// but it is not otherwise in use during the fight.
                m_Events.ScheduleEvent(eEvents::EventMeatHook, 5 * TimeConstants::IN_MILLISECONDS);

                /// Mythic mode only
                if (IsMythic())
                {
                    m_AddCount = 0;
                    m_Events.ScheduleEvent(eEvents::EventCadaver, 18 * TimeConstants::IN_MILLISECONDS);
                }

                if (!IsLFR())
                {
                    uint8 l_I = urand(0, (eHighmaulDatas::MaxMaggotToKill - 1));

                    me->SummonCreature(eCreatures::Maggot, g_MaggotSpawnPos[l_I]);
                    m_MaggotSpawned.insert(l_I);
                }
            }

            bool CanRespawn() override
            {
                return false;
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (me->HasAura(eSpells::SpellFrenzy))
                    return;

                if (me->HealthBelowPctDamaged(30, damage))
                {
                    me->CastSpell(me, eSpells::SpellFrenzy, true);

                    me->RemoveAura(eSpells::Angry5PerTick);
                    me->CastSpell(me, eSpells::Angry10PerTick, true);

                    Talk(eTalks::Frenzy);
                }
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                CreatureAI::EnterEvadeMode();

                Talk(eTalks::Wipe);

                if (m_Instance != nullptr)
                    m_Instance->SetBossState(eHighmaulDatas::BossTheButcher, EncounterState::FAIL);
            }

            void RegeneratePower(Powers /*power*/, int32& value) override
            {
                /// The Butcher only regens by script
                value = 0;
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();

                if (m_Instance != nullptr)
                {
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::TheCleaverDot);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::TheTenderizer);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::SpellGushingWounds);

                    instance->DoCastSpellOnPlayers(eSpells::ButcherBonusLoot, me);

                    /*if (IsLFR())
                    {
                        Player* player = me->GetMap()->GetPlayers().begin()->GetSource();
                        if (player && player->GetGroup())
                            sLFGMgr->AutomaticLootAssignation(me, player->GetGroup());
                    }*/
                }
            }

            void KilledUnit(Unit* killed) override
            {
                if (killed->GetTypeId() == TypeID::TYPEID_PLAYER)
                    Talk(eTalks::Slay);
            }

            void SpellMissTarget(Unit* target, SpellInfo const* spellInfo, SpellMissInfo missInfo) override
            {
                if (target == nullptr)
                    return;

                switch (spellInfo->Id)
                {
                    case eSpells::TheCleaverDmg:
                    {
                        /// This attack will not apply its bleed component if it is avoided.
                        if (missInfo == SpellMissInfo::SPELL_MISS_DODGE)
                            break;

                        me->AddAura(eSpells::TheCleaverDot, target);
                        break;
                    }
                    default:
                        break;
                }
            }

            void SpellHitTarget(Unit* target, SpellInfo const* spellInfo) override
            {
                if (target == nullptr)
                    return;

                switch (spellInfo->Id)
                {
                    case eSpells::MeatHook:
                        target->CastSpell(me, eSpells::MeatHookJump, true);
                        break;
                    case eSpells::SpellCleave:
                    case eSpells::BoundingCleaveDmg:
                        me->CastSpell(target, eSpells::SpellGushingWounds, true);
                        break;
                    default:
                        break;
                }
            }

            void OnSpellCasted(SpellInfo const* spellInfo) override
            {
                if (spellInfo->Id == eSpells::BoundingCleaveCharg)
                {
                    AddTimedDelayedOperation(2 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                    {
                        if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO))
                            AttackStart(target);

                        if (Creature* maggot = me->FindNearestCreature(eCreatures::Maggot, 10.0f))
                            me->Kill(maggot);
                    });
                }
            }

            void DoAction(int32 const action) override
            {
                if (action == eAction::MaggotKilled)
                {
                    std::vector<uint8> l_Indexes = { 0, 1, 2, 3, 4, 5 };
                    std::random_shuffle(l_Indexes.begin(), l_Indexes.end());

                    for (uint8 l_I : l_Indexes)
                    {
                        if (m_MaggotSpawned.find(l_I) != m_MaggotSpawned.end())
                            continue;

                        me->SummonCreature(eCreatures::Maggot, g_MaggotSpawnPos[l_I]);
                        m_MaggotSpawned.insert(l_I);
                        break;
                    }

                    if (m_Instance != nullptr)
                        m_Instance->SetData(eHighmaulDatas::ButcherAchievement, 1);
                }
            }

            void UpdateAI(uint32 const diff) override
            {
                if (!m_IntroDone)
                {
                    if (me->SelectNearestPlayer(130.0f) != nullptr)
                    {
                        m_IntroDone = true;
                        AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void { Talk(eTalks::Intro1); });
                        AddTimedDelayedOperation(8 * TimeConstants::IN_MILLISECONDS, [this]() -> void { Talk(eTalks::Intro2); });
                    }
                }

                UpdateOperations(diff);

                if (!UpdateVictim())
                    return;

                ScheduleEnergy(diff);

                m_Events.Update(diff);

                if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                    return;

                switch (m_Events.ExecuteEvent())
                {
                    case eEvents::EventTenderizer:
                    {
                        if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO))
                            me->CastSpell(target, eSpells::TheTenderizer, true);
                        m_Events.ScheduleEvent(eEvents::EventTenderizer, 16 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case eEvents::EventCleave:
                    {
                        if (m_CleaveCooldown <= diff)
                        {
                            m_CleaveCooldown = 20 * TimeConstants::IN_MILLISECONDS;
                            Talk(eTalks::Cleave);
                        }
                        else
                            m_CleaveCooldown -= diff;

                        Position source = GetCleaveLocation(me);
                        me->CastSpell(source, eSpells::SpellCleave, false);

                        AddTimedDelayedOperation(500, [this, source]() -> void
                        {
                            Position target = source;
                            target.m_positionZ += 0.1f;

                            /// Sniffed values
                            G3D::Vector3 orientation(0.0f, 4.035325f, 0.0f);

                            me->SendPlayOrphanSpellVisual(target, 37116, 7.f);

                            if (Creature* maggot = me->FindNearestCreature(eCreatures::Maggot, 5.0f))
                            {
                                if (maggot->IsNearPosition(&target, 5.0f))
                                    me->Kill(maggot);
                            }
                        });

                        m_Events.ScheduleEvent(eEvents::EventCleave, 5 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case eEvents::EventCleaver:
                    {
                        if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO))
                            me->CastSpell(target, eSpells::TheCleaverDmg, true);
                        m_Events.ScheduleEvent(eEvents::EventCleaver, 8 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case eEvents::EventBerserk:
                    {
                        Talk(eTalks::Berserk);
                        me->CastSpell(me, eHighmaulSpells::Berserker, true);
                        break;
                    }
                    case eEvents::EventBoundingCleave:
                    {
                        Talk(eTalks::BoundingCleave);
                        me->CastSpell(me, eSpells::BoundingCleaveKnock, true);
                        /// Charge on players after 8s
                        me->CastSpell(me, eSpells::BoundingCleaveDummy, false);
                        m_Events.DelayEvent(eEvents::EventMeatHook, 20 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case eEvents::EventMeatHook:
                    {
                        if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO))
                            if (!target->IsWithinMeleeRange(me))
                                me->CastSpell(target, eSpells::MeatHook, true);

                        m_Events.ScheduleEvent(eEvents::EventMeatHook, 5 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case eEvents::EventCadaver:
                    {
                        /// Every four waves of adds, The Butcher spawns one add more
                        ++m_AddCount;
                        uint8 l_Count = floor(float(m_AddCount) / 4.0f) + 1;

                        float radius  = 50.0f;
                        float posX    = me->GetHomePosition().m_positionX;
                        float posY    = me->GetHomePosition().m_positionY;
                        float posZ    = me->GetHomePosition().m_positionZ;

                        for (uint8 l_I = 0; l_I < l_Count; ++l_I)
                        {
                            float orientation = frand(0.f, 2.f * float(M_PI));
                            float l_X = posX + (radius * cos(orientation));
                            float l_Y = posY + (radius * sin(orientation));

                            me->SummonCreature(eCreatures::NightTwistedCadaver, l_X, l_Y, posZ);
                        }

                        m_Events.ScheduleEvent(eEvents::EventCadaver, 14 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    default:
                        break;
                }

                //EnterEvadeIfOutOfCombatArea(diff);
                DoMeleeAttackIfReady();
            }

            void ScheduleEnergy(uint32 const /*diff*/)
            {
                /// Bounding Cleave Icon Bounding Cleave is an ability that The Butcher uses when he reaches 100 Energy
                /// (this happens exactly every 60 seconds before The Butcher reaches 30% health, and every 30 seconds after that).
                if (me->GetPower(Powers::POWER_ENERGY) >= 100)
                    m_Events.ScheduleEvent(eEvents::EventBoundingCleave, 50);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_the_butcherAI(creature);
        }
};

/// Night-Twisted Cadaver - 82505
class npc_highmaul_night_twisted_cadaver : public CreatureScript
{
    public:
        npc_highmaul_night_twisted_cadaver() : CreatureScript("npc_highmaul_night_twisted_cadaver") { }

        enum eSpells
        {
            Paleobomb   = 163047,
            PaleVitriol = 163042
        };

        struct npc_highmaul_night_twisted_cadaverAI : public ScriptedAI
        {
            npc_highmaul_night_twisted_cadaverAI(Creature* creature) : ScriptedAI(creature)
            {
                m_Instance = creature->GetInstanceScript();
            }

            InstanceScript* m_Instance;
            bool m_Explode;

            void Reset() override
            {
                m_Explode = false;

                me->SetReactState(ReactStates::REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);

                if (!me->IsSummon())
                    return;

                AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    if (m_Instance == nullptr)
                        return;

                    me->SetWalk(true);

                    if (Creature* butcher = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eHighmaulCreatures::TheButcher)))
                        me->GetMotionMaster()->MoveChase(butcher);
                });
            }

            void UpdateAI(uint32 const diff) override
            {
                if (!me->IsSummon())
                    return;

                ScriptedAI::UpdateAI(diff);

                if (m_Instance == nullptr || m_Explode)
                    return;

                if (Creature* butcher = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eHighmaulCreatures::TheButcher)))
                    me->GetMotionMaster()->MoveChase(butcher);

                if (Creature* butcher = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eHighmaulCreatures::TheButcher)))
                {
                    if (me->GetDistance(butcher) <= 1.0f)
                        ExplodeAndSpawnVitriol();
                }

                if (me->SelectNearestPlayer(1.0f) != nullptr)
                    ExplodeAndSpawnVitriol();
            }

            void ExplodeAndSpawnVitriol()
            {
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MovementExpired(true);

                m_Explode = true;

                me->CastSpell(me, eSpells::Paleobomb, true);
                me->CastSpell(me, eSpells::PaleVitriol, true);

                AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void { me->Kill(me); });
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_highmaul_night_twisted_cadaverAI(creature);
        }
};

/// Maggot - 80728
class npc_highmaumaggot : public CreatureScript
{
    public:
        npc_highmaumaggot() : CreatureScript("npc_highmaumaggot") { }

        enum eAction
        {
            MaggotKilled
        };

        struct npc_highmaumaggotAI : public ScriptedAI
        {
            npc_highmaumaggotAI(Creature* creature) : ScriptedAI(creature)
            {
                m_Instance = creature->GetInstanceScript();
            }

            InstanceScript* m_Instance;

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (m_Instance != nullptr)
                {
                    if (Creature* butcher = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eHighmaulCreatures::TheButcher)))
                    {
                        if (butcher->IsAIEnabled)
                            butcher->AI()->DoAction(eAction::MaggotKilled);
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_highmaumaggotAI(creature);
        }
};

/// Heavy Handed - 156135
class spell_highmaul_heavy_handed : public SpellScriptLoader
{
    public:
        spell_highmaul_heavy_handed() : SpellScriptLoader("spell_highmaul_heavy_handed") { }

        enum eSpell
        {
            HeavyHandedProc = 156138
        };

        class spell_highmaul_heavy_handed_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_heavy_handed_AuraScript);

            void OnProc(AuraEffect const* /*aurEff*/, ProcEventInfo& p_EventInfo)
            {
                PreventDefaultAction();

                if (p_EventInfo.GetDamageInfo()->GetSpellInfo() != nullptr &&
                    p_EventInfo.GetDamageInfo()->GetSpellInfo()->Id == eSpell::HeavyHandedProc)
                    return;

                if (Unit* butcher = GetTarget())
                {
                    if (Unit* target = p_EventInfo.GetActionTarget())
                        butcher->CastSpell(target, eSpell::HeavyHandedProc, true);
                }
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_highmaul_heavy_handed_AuraScript::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_heavy_handed_AuraScript();
        }
};

/// Heavy Handed - 156138
class spell_highmaul_heavy_handed_proc : public SpellScriptLoader
{
    public:
        spell_highmaul_heavy_handed_proc() : SpellScriptLoader("spell_highmaul_heavy_handed_proc") { }

        class spell_highmaul_heavy_handed_proc_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_highmaul_heavy_handed_proc_SpellScript);

            ObjectGuid m_Target;

            bool Load() override
            {
                m_Target = ObjectGuid::Empty;
                return true;
            }

            void HandleBeforeCast()
            {
                if (Unit* target = GetExplTargetUnit())
                    m_Target = target->GetGUID();
            }

            void CorrectTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                Unit* caster = GetCaster();
                if (caster == nullptr)
                    return;

                /// All attacks made by the caster strike the next closest target
                if (targets.size() > 1)
                {
                    targets.remove_if([this](WorldObject* p_Object) -> bool
                    {
                        return !p_Object || p_Object->GetGUID() == m_Target;
                    });

                    if (targets.size() > 1)
                    {
                        targets.sort(Trinity::ObjectDistanceOrderPred(caster));
                        WorldObject* l_Object = targets.front();
                        targets.clear();
                        targets.push_back(l_Object);
                    }
                }
                /// If no target is found, the primary target is struck again.
                else
                {
                    targets.clear();

                    if (Unit* target = ObjectAccessor::GetUnit(*caster, m_Target))
                        targets.push_back(target);
                }
            }

            void Register() override
            {
                BeforeCast += SpellCastFn(spell_highmaul_heavy_handed_proc_SpellScript::HandleBeforeCast);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_highmaul_heavy_handed_proc_SpellScript::CorrectTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_highmaul_heavy_handed_proc_SpellScript();
        }
};

/// Bounding Cleave (Periodic Dummy) - 156197
class spell_highmaul_bounding_cleave_dummy : public SpellScriptLoader
{
    public:
        spell_highmaul_bounding_cleave_dummy() : SpellScriptLoader("spell_highmaul_bounding_cleave_dummy") { }

        enum eSpell
        {
            BoundingCleaveCharge = 156171
        };

        class spell_highmaul_bounding_cleave_dummy_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_bounding_cleave_dummy_AuraScript);

            void OnTick(AuraEffect const* aurEff)
            {
                if (aurEff->GetTickNumber() != 8)
                    return;

                if (GetTarget() == nullptr)
                    return;

                Creature* butcher = GetTarget()->ToCreature();
                if (butcher == nullptr)
                    return;

                Position pos = GetBoundingCleaveLocation(butcher);
                if (pos.m_positionX == 0.0f || pos.m_positionY == 0.0f || pos.m_positionZ == 0.0f)
                    pos = ComputeLocationSelection(butcher, 500.0f, 0.0f, 10.0f);

                butcher->CastSpell(pos, eSpell::BoundingCleaveCharge, true);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_highmaul_bounding_cleave_dummy_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_bounding_cleave_dummy_AuraScript();
        }
};

/// Gushing Wounds - 156152
class spell_highmaul_gushing_wounds : public SpellScriptLoader
{
    public:
        spell_highmaul_gushing_wounds() : SpellScriptLoader("spell_highmaul_gushing_wounds") { }

        class spell_highmaul_gushing_wounds_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_gushing_wounds_AuraScript);

            enum eSpell
            {
                GushingWoundsKill = 156153
            };

            void AfterApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* target = GetTarget())
                {
                    Map* map = target->GetMap();
                    uint8 maxstacks = map->IsMythic() ? 4 : (map->IsHeroic() ? 5 : (map->IsLFR() ? 10 : 6) );
                    if (aurEff->GetBase()->GetStackAmount() >= maxstacks)
                        target->CastSpell(target, eSpell::GushingWoundsKill, true);
                }
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_highmaul_gushing_wounds_AuraScript::AfterApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_gushing_wounds_AuraScript();
        }
};

/// Pale Vitriol - 163042
class areatrigger_highmaul_pale_vitriol : public AreaTriggerAI
{
public:
    areatrigger_highmaul_pale_vitriol(AreaTrigger* areaTrigger) : AreaTriggerAI(areaTrigger) { }

    enum eSpell
    {
        PaleVitriol = 163046
    };

    void OnUpdate(uint32 /*diff*/) override
    {
        if (Unit* caster = at->GetCaster())
        {
            std::list<Unit*> targetList;
            float radius = 4.0f;

            Trinity::AnyUnfriendlyUnitInObjectRangeCheck l_Check(at, caster, radius);
            Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> l_Searcher(at, targetList, l_Check);
            Cell::VisitAllObjects(at, l_Searcher, radius);

            for (Unit* l_Unit : targetList)
                caster->CastSpell(l_Unit, eSpell::PaleVitriol, true);
        }
    }
};

void AddSC_boss_the_butcher()
{
    /// Boss
    new boss_the_butcher();

    /// NPCs
    new npc_highmaul_night_twisted_cadaver();
    new npc_highmaumaggot();

    /// Spells
    new spell_highmaul_heavy_handed();
    new spell_highmaul_heavy_handed_proc();
    new spell_highmaul_bounding_cleave_dummy();
    new spell_highmaul_gushing_wounds();

    /// AreaTrigger
    RegisterAreaTriggerAI(areatrigger_highmaul_pale_vitriol);
}
