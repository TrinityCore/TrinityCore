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
#include "SpellMgr.h"

Position const g_PolMovePos[3] =
{
    { 4031.884f, 8587.818f, 343.6748f, 4.55423f },
    { 4028.196f, 8568.284f, 341.8094f, 4.51496f },
    { 4012.667f, 8523.617f, 327.2006f, 5.63415f }
};

Position const g_PolJumpPos = { 4043.08f, 8500.94f, 322.226f, 5.63415f };

Position const g_PhemosMovePos[3] =
{
    { 3949.489f, 8484.431f, 343.7032f, 0.31307f },
    { 3974.303f, 8497.139f, 335.4293f, 0.40340f },
    { 4002.597f, 8510.825f, 327.1879f, 5.63415f }
};

Position const g_PhemosJumpPos = { 4028.90f, 8485.51f, 322.226f, 5.63415f };

float const g_GorthenonFloor = 326.0f;

Position const g_CenterPos = { 4062.38f, 8470.91f, 322.226f, 0.0f };

float const g_CircleToCenterDist = 30.0f;
float const g_BlazeDistToCenter = 136.0f;

void RespawnOgrons(Creature* source, InstanceScript* p_Instance)
{
    if (source == nullptr || p_Instance == nullptr)
        return;

    if (Creature* l_Other = p_Instance->GetCreature((source->GetEntry() == eHighmaulCreatures::Phemos) ? eHighmaulCreatures::Pol : eHighmaulCreatures::Phemos))
    {
        l_Other->Respawn();
        l_Other->GetMotionMaster()->MoveTargetedHome();
    }
}

void StartOgrons(Creature* source, Unit* target)
{
    if (source == nullptr || target == nullptr)
        return;

    if (Creature* l_Other = source->FindNearestCreature((source->GetEntry() == eHighmaulCreatures::Phemos) ? eHighmaulCreatures::Pol : eHighmaulCreatures::Phemos, 30.0f))
        l_Other->AI()->AttackStart(target);
}

/// Pol - 78238
class boss_twin_ogron_pol : public CreatureScript
{
    public:
        boss_twin_ogron_pol() : CreatureScript("boss_twin_ogron_pol") { }

        enum eSpells
        {
            WarmingUp               = 173425,
            AggressiveDisposition   = 157951,
            Disposition             = 154172,
            VenomshadeCopyDmgAura   = 154349,
            /// Pulverize
            PulverizeAura           = 158385,
            PulverizeFirstAoE       = 157952,
            PulverizeFirstAoEDmg    = 158336,
            PulverizeSecondAoE      = 158415,
            PulverizeSecondAoEDmg   = 158417,
            PulverizeThirdAoE       = 158419,
            PulverizeThirdAoEDmg    = 158420,
            /// Interrupting Shout
            SpellInterruptingShout  = 158093,
            InterruptingShoutDmg    = 158102,
            /// Shield Charge
            SpellShieldCharge       = 158134,
            ShieldChargeEndingAoE   = 158157,
            InjuredDoT              = 155569,

            ShieldBash              = 143834,

            /// Loot
            TwinOgronBonus          = 177525
        };

        enum eEvents
        {
            EventBerserker = 1,
            EventShieldBash
        };

        enum eActions
        {
            SchedulePulverize   = 1,
            ScheduleInterruptingShout,
            ScheduleShieldCharge
        };

        enum eTalks
        {
            Intro,
            Aggro,
            InterruptingShout,
            ShieldCharge,
            Pulverize,
            Slay,
            ShieldChargeWarn
        };

        enum eMoves
        {
            MoveFirst = 10,
            MoveSecond,
            MoveThird,
            MoveJump,

            MoveShieldCharge = 158134
        };

        enum eVisuals
        {
            PulverizeVisual = 37673,
            PulverizeSecond = 37699,
            PulverizeLast   = 44116,
            BigPulverize    = 37702,
            PulverizeFinal  = 40527
        };

        struct boss_twin_ogron_polAI : public BossAI
        {
            boss_twin_ogron_polAI(Creature* creature) : BossAI(creature, eHighmaulDatas::BossTwinOgron)
            {
                m_Instance  = creature->GetInstanceScript();
            }

            EventMap m_Events;
            InstanceScript* m_Instance;

            bool m_ShieldChargeScheduled;
            bool m_InterruptingShoutScheduled;

            void Reset() override
            {
                m_Events.Reset();

                _Reset();

                me->SetPower(Powers::POWER_ENERGY, 0);
                me->SetMaxPower(Powers::POWER_ENERGY, 100);
                me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_REGENERATE_POWER);

                /// Has two equips, but one handed and shielded
                me->SetCanDualWield(false);

                me->CastSpell(me, eSpells::AggressiveDisposition, true);
                me->CastSpell(me, eSpells::Disposition, true);

                m_ShieldChargeScheduled = false;
                m_InterruptingShoutScheduled = false;

                me->SendCancelSpellVisual(eVisuals::BigPulverize);
                me->SendCancelSpellVisual(eVisuals::PulverizeVisual);
                me->SendCancelSpellVisualKit(eVisuals::PulverizeLast);
            }

            bool CanRespawn() override
            {
                return false;
            }

            void DoAction(int32 const action) override
            {
                switch (action)
                {
                    case eActions::SchedulePulverize:
                    {
                        Talk(eTalks::Pulverize);

                        m_InterruptingShoutScheduled = false;
                        m_ShieldChargeScheduled = false;

                        me->SetPower(Powers::POWER_ENERGY, 0);

                        me->AddUnitState(UnitState::UNIT_STATE_ROOT);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);

                        me->CastSpell(me, eSpells::PulverizeAura, true);

                        AddTimedDelayedOperation(2 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                        {
                            /// The first wave causes rocks to fall at the locations of all raid members, dealing damage in a 3-yard radius.
                            me->CastSpell(me, eSpells::PulverizeFirstAoE, false);
                        });

                        AddTimedDelayedOperation(5 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                        {
                            /// The second wave causes several rocks to fall at random locations, dealing damage in an 8-yard radius.
                            /// Handled in SpellHitTarget
                            me->CastSpell(me, eSpells::PulverizeSecondAoE, false);
                        });

                        AddTimedDelayedOperation(9 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                        {
                            me->SendPlaySpellVisualKit(eVisuals::PulverizeLast, 0, 0);
                            me->CastSpell(me, eSpells::PulverizeThirdAoE, false);
                        });

                        Position pos = me->GetRandomNearPosition(30.0f);

                        /// The third and final wave causes one large rock to fall at a random location, dealing raid-wide damage.
                        /// The damage is higher the closer players are to the landing location.
                        AddTimedDelayedOperation(10 * TimeConstants::IN_MILLISECONDS, [this, pos]() -> void
                        {
                            me->SendPlaySpellVisual(pos, 4.015914f, eVisuals::BigPulverize);
                        });

                        AddTimedDelayedOperation(14500, [this, pos]() -> void
                        {
                            me->SendPlayOrphanSpellVisual(pos, eVisuals::PulverizeFinal, 3.0f);
                        });

                        AddTimedDelayedOperation(15 * TimeConstants::IN_MILLISECONDS, [this, pos]() -> void
                        {
                            me->CastSpell(pos, eSpells::PulverizeThirdAoEDmg, true);
                            me->SendCancelSpellVisual(eVisuals::BigPulverize);

                            me->ClearUnitState(UnitState::UNIT_STATE_ROOT);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                        });

                        break;
                    }
                    case eActions::ScheduleInterruptingShout:
                    {
                        if (m_InterruptingShoutScheduled)
                            break;

                        Talk(eTalks::InterruptingShout);
                        m_InterruptingShoutScheduled = true;
                        me->CastSpell(me, eSpells::SpellInterruptingShout, false);
                        break;
                    }
                    case eActions::ScheduleShieldCharge:
                    {
                        if (m_ShieldChargeScheduled)
                            break;

                        Talk(eTalks::ShieldCharge);
                        Talk(eTalks::ShieldChargeWarn);

                        if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, -10.0f))
                            me->CastSpell(target, eSpells::SpellShieldCharge, false);

                        m_ShieldChargeScheduled = true;
                        break;
                    }
                    default:
                        break;
                }
            }

            void EnterCombat(Unit* attacker) override
            {
                Talk(eTalks::Aggro);

                _EnterCombat();

                me->CastSpell(me, eSpells::WarmingUp, true);

                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me, 1);

                m_Instance->SetBossState(eHighmaulDatas::BossTwinOgron, EncounterState::IN_PROGRESS);

                m_Events.ScheduleEvent(eEvents::EventBerserker, IsMythic() ? 420 * TimeConstants::IN_MILLISECONDS : 480 * TimeConstants::IN_MILLISECONDS);
                m_Events.ScheduleEvent(eEvents::EventShieldBash, 22 * TimeConstants::IN_MILLISECONDS);

                StartOgrons(me, attacker);

                if (Creature* l_Other = me->FindNearestCreature(eHighmaulCreatures::Phemos, 150.0f))
                    me->AddAura(eSpells::VenomshadeCopyDmgAura, l_Other);
            }

            void KilledUnit(Unit* killed) override
            {
                if (killed->GetTypeId() == TypeID::TYPEID_PLAYER)
                    Talk(eTalks::Slay);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();

                if (m_Instance != nullptr)
                {
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::InjuredDoT);

                    instance->DoCastSpellOnPlayers(eSpells::TwinOgronBonus, me);

                    /*if (IsLFR())
                    {
                        Player* player = me->GetMap()->GetPlayers().begin()->GetSource();
                        if (player && player->GetGroup())
                            sLFGMgr->AutomaticLootAssignation(me, player->GetGroup());
                    }*/
                }
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                CreatureAI::EnterEvadeMode();

                if (m_Instance != nullptr)
                {
                    m_Instance->SetBossState(eHighmaulDatas::BossTwinOgron, EncounterState::FAIL);
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::InjuredDoT);

                    RespawnOgrons(me, m_Instance);
                }
            }

            void MovementInform(uint32 /*type*/, uint32 id) override
            {
                switch (id)
                {
                    case eMoves::MoveFirst:
                        me->GetMotionMaster()->MovePoint(eMoves::MoveSecond, g_PolMovePos[1]);
                        break;
                    case eMoves::MoveSecond:
                        me->GetMotionMaster()->MovePoint(eMoves::MoveThird, g_PolMovePos[2]);
                        break;
                    case eMoves::MoveThird:
                        me->SetHomePosition(*me);
                        AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void { me->SetFacingTo(g_PolMovePos[2].GetOrientation()); });
                        break;
                    case eMoves::MoveJump:
                    {
                        me->ClearUnitState(UNIT_STATE_IGNORE_PATHFINDING);
                        me->SetHomePosition(*me);
                        break;
                    }
                    case eMoves::MoveShieldCharge:
                        me->RemoveAura(eSpells::SpellShieldCharge);
                        me->CastSpell(me, eSpells::ShieldChargeEndingAoE, true);
                        break;
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
                    case eSpells::SpellInterruptingShout:
                    {
                        me->CastSpell(target, eSpells::InterruptingShoutDmg, true);
                        break;
                    }
                    case eSpells::PulverizeFirstAoE:
                    {
                        me->CastSpell(target, eSpells::PulverizeFirstAoEDmg, true);
                        break;
                    }
                    case eSpells::PulverizeSecondAoE:
                    {
                        Position pos = *target;
                        me->SendPlaySpellVisual(pos, 2.5f, eVisuals::PulverizeVisual);

                        AddTimedDelayedOperation(2500, [this, pos]() -> void
                        {
                            me->SendPlayOrphanSpellVisual(pos, eVisuals::PulverizeSecond, 3.0f);
                        });

                        AddTimedDelayedOperation(3 * TimeConstants::IN_MILLISECONDS, [this, pos]() -> void
                        {
                            me->CastSpell(pos, eSpells::PulverizeSecondAoEDmg, true);
                        });

                        break;
                    }
                    default:
                        break;
                }
            }

            void RegeneratePower(Powers power, int32& value) override
            {
                /// Pol only regens by script
                if (power == Powers::POWER_ENERGY)
                    value = 0;
            }

            void UpdateAI(uint32 const diff) override
            {
                UpdateOperations(diff);

                if(me->GetDistance(me->GetHomePosition()) >= 250.0f)
                {
                    EnterEvadeMode(EVADE_REASON_BOUNDARY);
                    return;
                }

                if (!UpdateVictim())
                    return;

                if (!me->HasAura(eSpells::WarmingUp))
                    m_Events.Update(diff);

                if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                    return;

                switch (m_Events.ExecuteEvent())
                {
                    case eEvents::EventBerserker:
                    {
                        me->CastSpell(me, eHighmaulSpells::Berserker, true);
                        break;
                    }
                    case eEvents::EventShieldBash:
                    {
                        if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO))
                            me->CastSpell(target, eSpells::ShieldBash, false);
                        m_Events.ScheduleEvent(eEvents::EventShieldBash, 22 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_twin_ogron_polAI(creature);
        }
};

/// Phemos - 78237
class boss_twin_ogron_phemos : public CreatureScript
{
    public:
        boss_twin_ogron_phemos() : CreatureScript("boss_twin_ogron_phemos") { }

        enum eSpells
        {
            /// Misc
            WarmingUp               = 173425,
            AggressiveDisposition   = 157951,
            Disposition             = 154172,
            VenomshadeCopyDmgAura   = 154349,
            DespawnAreaTriggers     = 115905,
            /// Quake
            SpellQuake              = 158200,
            BlazeWeaponVisual       = 158206,
            BlazeFirstSpawn         = 162901,
            /// Enfeebling Roar
            SpellEnfeeblingRoar     = 158057,
            EnfeeblingRoarDebuff    = 158026,
            /// Whirlwind
            SpellWhirlwind          = 157943,
            WeakenedDefenses        = 159709,
            /// ArcaneVolatility
            SpellArcaneVolatilityDu = 163378,
            SpellArcaneVolatilityMi = 163372,

            DoubleSlashMainHand     = 158521,
            DoubleSlashOffHand      = 167198,
            BlazeDoT                = 158241
        };

        enum eEvents
        {
            EventCheckPlayer = 1,
            EventBerserker,
            EventDoubleSlash,
            EventSpawnFirstBlaze,
            EventSpawnSecondBlaze,
            EventsArcaneVolatility
        };

        enum eActions
        {
            ActionMoveHome  = 1,
            ScheduleQuake,
            ScheduleEnfeeblingRoar,
            ScheduleWhirlwind
        };

        enum eCreature
        {
            Conscript   = 82519,
            Brute       = 82400,
            Arcanist    = 82528,
        };

        enum eTalks
        {
            Intro,
            Aggro,
            Whirlwind,
            Quake,
            EnfeeblingRoar,
            Berserk,
            Slay,
            Wipe,
            WhirlwindWarn
        };

        enum eMoves
        {
            MoveFirst = 10,
            MoveSecond,
            MoveThird,
            MoveJump
        };

        enum eVisuals
        {
            QuakeVisualID       = 41369,
            QuakeSpellVisual    = 37816
        };

        enum eMiscs
        {
            EnfeeblingCounter,
            BlazeFirstSpawnCounter  = 3,
            BlazeWaveSpawnCounter   = 6,
            BlazeTotalWaveCount     = 5
        };

        struct boss_twin_ogron_phemosAI : public BossAI
        {
            boss_twin_ogron_phemosAI(Creature* creature) : BossAI(creature, eHighmaulDatas::BossTwinOgron)
            {
                m_Instance  = creature->GetInstanceScript();
                m_Init = false;
                m_HomeChanged = false;
            }

            EventMap m_CosmeticEvents;
            EventMap m_Events;
            InstanceScript* m_Instance;

            std::set<ObjectGuid> m_TrashsMobs;
            bool m_Init;
            bool m_HomeChanged;

            bool m_WhirlwindScheduled;
            bool m_EnfeeblingRoarScheduled;

            std::set<ObjectGuid> m_EnfeeblingRoarTargets;

            Position m_FirstBlazePos;
            uint8 m_FirstWaveCounter;
            Position m_SecondBlazePos;
            uint8 m_SecondWaveCounter;

            void Reset() override
            {
                if (!m_HomeChanged)
                    m_CosmeticEvents.ScheduleEvent(eEvents::EventCheckPlayer, 1 * TimeConstants::IN_MILLISECONDS);

                m_Events.Reset();

                _Reset();

                me->SetMaxPower(Powers::POWER_ENERGY, 100);
                me->SetPower(Powers::POWER_ENERGY, 98);
                me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_REGENERATE_POWER);

                me->CastSpell(me, eSpells::DespawnAreaTriggers, true);
                me->CastSpell(me, eSpells::AggressiveDisposition, true);
                me->CastSpell(me, eSpells::Disposition, true);

                AddTimedDelayedOperation(2 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    if (m_TrashsMobs.empty() && !m_Init)
                    {
                        std::list<Creature*> l_TrashList;
                        me->GetCreatureListInGrid(l_TrashList, 250.0f);

                        if (!l_TrashList.empty())
                        {
                            l_TrashList.remove_if([](Creature* creature) -> bool
                            {
                                if (creature == nullptr || creature->GetPositionZ() > g_GorthenonFloor)
                                    return true;

                                if (!creature->IsAlive())
                                    return true;

                                uint32 entry = creature->GetEntry();

                                if (entry == eCreature::Arcanist || entry == eCreature::Brute || entry == eCreature::Conscript)
                                    return false;

                                return true;
                            });
                        }

                        for (Creature* l_Creature : l_TrashList)
                            m_TrashsMobs.insert(l_Creature->GetGUID());

                        m_Init = true;
                    }
                });

                m_WhirlwindScheduled = false;
                m_EnfeeblingRoarScheduled = false;

                m_EnfeeblingRoarTargets.clear();

                m_FirstBlazePos = Position();
                m_FirstWaveCounter = 0;
                m_SecondBlazePos = Position();
                m_SecondWaveCounter = 0;

                me->SendCancelSpellVisual(eVisuals::QuakeSpellVisual);
                me->SendCancelSpellVisualKit(eVisuals::QuakeVisualID);
            }

            bool CanRespawn() override
            {
                return false;
            }

            void DoAction(int32 const action) override
            {
                switch (action)
                {
                    case eActions::ActionMoveHome:
                    {
                        DoMoveHome();
                        break;
                    }
                    case eActions::ScheduleQuake:
                    {
                        Talk(eTalks::Quake);

                        me->SetPower(Powers::POWER_ENERGY, 0);
                        me->CastSpell(me, eSpells::SpellQuake, false);

                        m_EnfeeblingRoarScheduled = false;
                        m_WhirlwindScheduled = false;

                        float l_O = frand(0.0f, 2.0f * float(M_PI));
                        Position pos =
                        {
                            (g_CenterPos.m_positionX + (g_CircleToCenterDist * cos(l_O))),
                            (g_CenterPos.m_positionY + (g_CircleToCenterDist * sin(l_O))),
                            g_CenterPos.m_positionZ,
                            0.0f
                        };

                        pos.SetOrientation(pos.GetAngle(&g_CenterPos));
                        m_FirstBlazePos = pos;

                        /// Total: 4 waves
                        /// First
                        ++m_FirstWaveCounter;
                        SpawnBlazeWave(pos);
                        /// Second, third and fourth
                        m_CosmeticEvents.ScheduleEvent(eEvents::EventSpawnFirstBlaze, 5 * TimeConstants::IN_MILLISECONDS);

                        me->CastSpell(pos, eSpells::BlazeWeaponVisual, true);
                        me->SendPlaySpellVisualKit(eVisuals::QuakeVisualID, 0, 0);

                        AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this, pos]() -> void
                        {
                            me->SendPlaySpellVisual(pos, 0.75f, eVisuals::QuakeSpellVisual);
                        });

                        l_O += float(M_PI);
                        pos =
                        {
                            (g_CenterPos.m_positionX + (g_CircleToCenterDist * cos(l_O))),
                            (g_CenterPos.m_positionY + (g_CircleToCenterDist * sin(l_O))),
                            g_CenterPos.m_positionZ,
                            0.0f
                        };

                        pos.SetOrientation(pos.GetAngle(&g_CenterPos));

                        m_SecondBlazePos = pos;
                        m_CosmeticEvents.ScheduleEvent(eEvents::EventSpawnSecondBlaze, 1500);

                        AddTimedDelayedOperation(1500, [this, pos]() -> void
                        {
                            me->CastSpell(pos, eSpells::BlazeWeaponVisual, true);
                            me->SendPlaySpellVisualKit(eVisuals::QuakeVisualID, 0, 0);
                        });

                        AddTimedDelayedOperation(2500, [this, pos]() -> void
                        {
                            me->SendPlaySpellVisual(pos, 0.75f, eVisuals::QuakeSpellVisual);
                        });

                        break;
                    }
                    case eActions::ScheduleEnfeeblingRoar:
                    {
                        if (m_EnfeeblingRoarScheduled)
                            break;

                        m_EnfeeblingRoarTargets.clear();
                        Talk(eTalks::EnfeeblingRoar);
                        me->CastSpell(me, eSpells::SpellEnfeeblingRoar, false);
                        m_EnfeeblingRoarScheduled = true;

                        /// Cast time of Enfeebling roar + 100ms timer
                        AddTimedDelayedOperation(3100, [this]() -> void
                        {
                            for (ObjectGuid guid : m_EnfeeblingRoarTargets)
                            {
                                if (Unit* target = ObjectAccessor::GetUnit(*me, guid))
                                    me->CastSpell(target, eSpells::EnfeeblingRoarDebuff, true);
                            }
                        });

                        break;
                    }
                    case eActions::ScheduleWhirlwind:
                    {
                        if (m_WhirlwindScheduled)
                            break;

                        Talk(eTalks::Whirlwind);
                        Talk(eTalks::WhirlwindWarn);
                        me->CastSpell(me, eSpells::SpellWhirlwind, false);
                        m_WhirlwindScheduled = true;
                        break;
                    }
                    default:
                        break;
                }
            }

            void SetGUID(ObjectGuid guid, int32 /*id*/) override
            {
                m_TrashsMobs.erase(guid);
            }

            void EnterCombat(Unit* attacker) override
            {
                Talk(eTalks::Aggro);

                _EnterCombat();

                me->CastSpell(me, eSpells::WarmingUp, true);

                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me, 1);

                m_Instance->SetBossState(eHighmaulDatas::BossTwinOgron, EncounterState::IN_PROGRESS);

                m_Events.ScheduleEvent(eEvents::EventBerserker, IsMythic() ? 420 * TimeConstants::IN_MILLISECONDS : 480 * TimeConstants::IN_MILLISECONDS);
                m_Events.ScheduleEvent(eEvents::EventDoubleSlash, 26 * TimeConstants::IN_MILLISECONDS);

                if(IsMythic())
                    m_Events.ScheduleEvent(eEvents::EventsArcaneVolatility, urand(20, 60) * IN_MILLISECONDS);

                StartOgrons(me, attacker);

                if (Creature* l_Other = me->FindNearestCreature(eHighmaulCreatures::Pol, 150.0f))
                    me->AddAura(eSpells::VenomshadeCopyDmgAura, l_Other);
            }

            void KilledUnit(Unit* killed) override
            {
                if (killed->GetTypeId() == TypeID::TYPEID_PLAYER)
                    Talk(eTalks::Slay);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();

                if (m_Instance != nullptr)
                {
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::WeakenedDefenses);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::EnfeeblingRoarDebuff);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::BlazeDoT);
                }

                me->RemoveAllAreaTriggers();
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                Talk(eTalks::Wipe);

                CreatureAI::EnterEvadeMode();

                if (m_Instance != nullptr)
                {
                    m_Instance->SetBossState(eHighmaulDatas::BossTwinOgron, EncounterState::FAIL);
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::WeakenedDefenses);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::EnfeeblingRoarDebuff);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::BlazeDoT);

                    RespawnOgrons(me, m_Instance);
                }

                me->RemoveAllAreaTriggers();
            }

            void MovementInform(uint32 /*type*/, uint32 id) override
            {
                switch (id)
                {
                    case eMoves::MoveFirst:
                        me->GetMotionMaster()->MovePoint(eMoves::MoveSecond, g_PhemosMovePos[1]);
                        break;
                    case eMoves::MoveSecond:
                        me->GetMotionMaster()->MovePoint(eMoves::MoveThird, g_PhemosMovePos[2]);
                        break;
                    case eMoves::MoveThird:
                    {
                        me->SetHomePosition(*me);
                        m_HomeChanged = true;

                        AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                        {
                            me->SetFacingTo(g_PhemosMovePos[2].GetOrientation());
                        });

                        if (m_TrashsMobs.empty())
                        {
                            AddTimedDelayedOperation(2 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                            {
                                DoMoveHome();
                            });
                        }

                        break;
                    }
                    case eMoves::MoveJump:
                        me->SetHomePosition(*me);
                        me->ClearUnitState(UNIT_STATE_IGNORE_PATHFINDING);
                        break;
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
                    case eSpells::SpellEnfeeblingRoar:
                    {
                        m_EnfeeblingRoarTargets.insert(target->GetGUID());
                        break;
                    }
                    default:
                        break;
                }
            }

            void RegeneratePower(Powers power, int32& value) override
            {
                /// Phemos only regens by script
                if (power == Powers::POWER_ENERGY)
                    value = 0;
            }

            void UpdateAI(uint32 const diff) override
            {
                UpdateOperations(diff);

                if (me->GetDistance(me->GetHomePosition()) >= 250.0f)
                {
                    EnterEvadeMode(EVADE_REASON_BOUNDARY);
                    return;
                }

                m_CosmeticEvents.Update(diff);

                switch (m_CosmeticEvents.ExecuteEvent())
                {
                    case eEvents::EventCheckPlayer:
                    {
                        if (me->SelectNearestPlayer(150.0f))
                            DoFirstMove();
                        else
                            m_CosmeticEvents.ScheduleEvent(eEvents::EventCheckPlayer, 1 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case eEvents::EventSpawnFirstBlaze:
                    {
                        ++m_FirstWaveCounter;
                        SpawnBlazeWave(m_FirstBlazePos);
                        if (m_FirstWaveCounter <= eMiscs::BlazeTotalWaveCount)
                            m_CosmeticEvents.ScheduleEvent(eEvents::EventSpawnFirstBlaze, 5 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case eEvents::EventSpawnSecondBlaze:
                    {
                        ++m_SecondWaveCounter;
                        SpawnBlazeWave(m_SecondBlazePos);
                        if (m_SecondWaveCounter <= eMiscs::BlazeTotalWaveCount)
                            m_CosmeticEvents.ScheduleEvent(eEvents::EventSpawnSecondBlaze, 5 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    default:
                        break;
                }

                if (!UpdateVictim())
                    return;

                if (!me->HasAura(eSpells::WarmingUp))
                    m_Events.Update(diff);

                if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                    return;

                switch (m_Events.ExecuteEvent())
                {
                    case eEvents::EventBerserker:
                    {
                        me->CastSpell(me, eHighmaulSpells::Berserker, true);
                        Talk(eTalks::Berserk);
                        break;
                    }
                    case eEvents::EventDoubleSlash:
                    {
                        if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO))
                        {
                            me->CastSpell(target, eSpells::DoubleSlashMainHand, false);

                            ObjectGuid guid = target->GetGUID();
                            AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this, guid]() -> void
                            {
                                if (Unit* target = ObjectAccessor::GetUnit(*me, guid))
                                    me->CastSpell(target, eSpells::DoubleSlashOffHand, true);
                            });
                        }

                        m_Events.ScheduleEvent(eEvents::EventDoubleSlash, 27 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case EventsArcaneVolatility:
                    {
                        me->CastSpell(me, SpellArcaneVolatilityDu, false);
                        for(uint8 i = 0; i < urand(1, 4); i++)
                            me->CastSpell(me, SpellArcaneVolatilityMi, false);

                        m_Events.ScheduleEvent(eEvents::EventsArcaneVolatility, urand(50, 60) * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }

            uint32 GetData(uint32 id) const override
            {
                if (id == eMiscs::EnfeeblingCounter)
                    return m_EnfeeblingRoarTargets.size();

                return 0;
            }

            void DoFirstMove()
            {
                Talk(eTalks::Intro);
                me->GetMotionMaster()->MovePoint(eMoves::MoveFirst, g_PhemosMovePos[0]);

                if (m_Instance != nullptr)
                {
                    if (Creature* l_Pol = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eHighmaulCreatures::Pol)))
                    {
                        l_Pol->GetMotionMaster()->MovePoint(eMoves::MoveFirst, g_PolMovePos[0]);

                        ObjectGuid guid = l_Pol->GetGUID();
                        AddTimedDelayedOperation(5 * TimeConstants::IN_MILLISECONDS, [this, guid]() -> void
                        {
                            if (Creature* l_Boss = ObjectAccessor::GetCreature(*me, guid))
                            {
                                if (l_Boss->IsAIEnabled)
                                    l_Boss->AI()->Talk(eTalks::Intro);
                            }
                        });
                    }
                }
            }

            void DoMoveHome()
            {
                if (!m_TrashsMobs.empty())
                    return;

                me->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);
                me->GetMotionMaster()->MoveJump(g_PhemosJumpPos, 30.0f, 20.0f, eMoves::MoveJump);

                if (m_Instance != nullptr)
                {
                    if (Creature* l_Pol = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eHighmaulCreatures::Pol)))
                    {
                        l_Pol->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);
                        l_Pol->GetMotionMaster()->MoveJump(g_PolJumpPos, 30.0f, 20.0f, eMoves::MoveJump);
                    }
                }
            }

            void SpawnBlazeWave(Position pos)
            {
                float l_OStep = (pos.GetOrientation() - (float(M_PI) / 2.0f)) + frand(0.0f, (float(M_PI) / 3.0f));

                for (uint8 l_I = 0; l_I < eMiscs::BlazeFirstSpawnCounter; ++l_I)
                {
                    uint32 l_Timer = 0;
                    float orientation = l_OStep;

                    for (uint8 l_J = 0; l_J < eMiscs::BlazeWaveSpawnCounter; ++l_J)
                    {
                        Position l_Dest = pos;
                        l_Dest.m_positionX = pos.m_positionX + (g_BlazeDistToCenter * cos(orientation));
                        l_Dest.m_positionY = pos.m_positionY + (g_BlazeDistToCenter * sin(orientation));

                        if (l_Timer)
                        {
                            AddTimedDelayedOperation(l_Timer, [this, pos, l_Dest]() -> void
                            {
                                me->CastSpell(me, eSpells::BlazeFirstSpawn, true);
                            });
                        }
                        else
                        {
                            me->CastSpell(me, eSpells::BlazeFirstSpawn, true);
                        }

                        /// Is it enough?
                        orientation += 0.05f;

                        l_Timer += 500;
                    }

                    l_OStep += float(M_PI) / 3.0f;
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_twin_ogron_phemosAI(creature);
        }
};

/// Warming Up - 173425
class spell_highmaul_warming_up : public SpellScriptLoader
{
    public:
        spell_highmaul_warming_up() : SpellScriptLoader("spell_highmaul_warming_up") { }

        class spell_highmaul_warming_up_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_warming_up_AuraScript);

            enum eSpell
            {
                Disposition = 157953
            };

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* target = GetTarget())
                    target->CastSpell(target, eSpell::Disposition, true);
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_highmaul_warming_up_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_warming_up_AuraScript();
        }
};

/// Disposition - 157953
class spell_highmaul_disposition : public SpellScriptLoader
{
    public:
        spell_highmaul_disposition() : SpellScriptLoader("spell_highmaul_disposition") { }

        class spell_highmaul_disposition_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_disposition_AuraScript);

            uint8 m_TickCount;

            enum eActions
            {
                /// Phemos
                ScheduleQuake               = 2,
                ScheduleEnfleeblingRoar     = 3,
                ScheduleWhirlwind           = 4,
                /// Pol
                SchedulePulverize           = 1,
                ScheduleInterruptingShout   = 2,
                ScheduleShieldCharge        = 3
            };

            bool Load() override
            {
                m_TickCount = 0;
                return true;
            }

            void OnTick(AuraEffect const* /*aurEff*/)
            {
                if (GetTarget() == nullptr)
                    return;

                if (Creature* l_Boss = GetTarget()->ToCreature())
                {
                    float l_EnergyGain = 1.0f;
                    l_EnergyGain *= 1.0f + (float)l_Boss->GetPower(Powers::POWER_ALTERNATE_POWER) / 100.0f;

                    /// Pol energizes 25% faster than Phemos
                    if (l_Boss->GetEntry() == eHighmaulCreatures::Pol)
                    {
                        ++m_TickCount;
                        l_EnergyGain *= 1.25f;

                        if ((int32)l_EnergyGain == 1 && !(m_TickCount % 2))
                        {
                            m_TickCount = 0;
                            l_EnergyGain += 1.0f;
                        }
                    }

                    l_Boss->EnergizeBySpell(l_Boss, GetSpellInfo()->Id, (int32)l_EnergyGain, Powers::POWER_ENERGY);

                    if (!l_Boss->IsAIEnabled)
                        return;

                    switch (l_Boss->GetEntry())
                    {
                        case eHighmaulCreatures::Phemos:
                        {
                            if (l_Boss->GetPower(Powers::POWER_ENERGY) >= 100)
                                l_Boss->AI()->DoAction(eActions::ScheduleQuake);
                            else if (l_Boss->GetPower(Powers::POWER_ENERGY) >= 66 && l_Boss->GetPower(Powers::POWER_ENERGY) <= 80)
                                l_Boss->AI()->DoAction(eActions::ScheduleEnfleeblingRoar);
                            else if (l_Boss->GetPower(Powers::POWER_ENERGY) >= 33 && l_Boss->GetPower(Powers::POWER_ENERGY) <= 50)
                                l_Boss->AI()->DoAction(eActions::ScheduleWhirlwind);

                            break;
                        }
                        case eHighmaulCreatures::Pol:
                        {
                            if (l_Boss->GetPower(Powers::POWER_ENERGY) >= 100)
                                l_Boss->AI()->DoAction(eActions::SchedulePulverize);
                            else if (l_Boss->GetPower(Powers::POWER_ENERGY) >= 66 && l_Boss->GetPower(Powers::POWER_ENERGY) <= 80)
                                l_Boss->AI()->DoAction(eActions::ScheduleInterruptingShout);
                            else if (l_Boss->GetPower(Powers::POWER_ENERGY) >= 33 && l_Boss->GetPower(Powers::POWER_ENERGY) <= 50)
                                l_Boss->AI()->DoAction(eActions::ScheduleShieldCharge);

                            break;
                        }
                        default:
                            break;
                    }
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_highmaul_disposition_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_disposition_AuraScript();
        }
};

/// Enfeebling Roar - 158026
class spell_highmaul_enfeebling_roar : public SpellScriptLoader
{
    public:
        spell_highmaul_enfeebling_roar() : SpellScriptLoader("spell_highmaul_enfeebling_roar") { }

        enum eMisc
        {
            EnfeeblingCounter
        };

        class spell_highmaul_enfeebling_roar_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_enfeebling_roar_AuraScript);

            void AfterApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (GetCaster() == nullptr)
                    return;

                if (Creature* l_Phemos = GetCaster()->ToCreature())
                {
                    if (!l_Phemos->IsAIEnabled)
                        return;

                    Aura* l_Aura = aurEff->GetBase();
                    if (!l_Aura)
                        return;

                    uint32 l_Count = l_Phemos->AI()->GetData(eMisc::EnfeeblingCounter);
                    if (!l_Count)
                        l_Count = 1;

                    uint32 l_MaxDuration = l_Aura->GetDuration() * 10;
                    int32 l_Amount = aurEff->GetAmount() * 10;

                    l_Aura->SetDuration(l_MaxDuration / l_Count);
                    l_Aura->SetMaxDuration(l_MaxDuration / l_Count);
                    l_Aura->GetEffect(EFFECT_1)->ChangeAmount(l_Amount / l_Count);
                    l_Aura->SetNeedClientUpdateForTargets();
                }
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_highmaul_enfeebling_roar_AuraScript::AfterApply, EFFECT_1, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_enfeebling_roar_AuraScript();
        }

        class spell_highmaul_enfeebling_roar_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_highmaul_enfeebling_roar_SpellScript);

            void HandleDamage(SpellEffIndex /*effIndex*/)
            {
                if (GetCaster() == nullptr)
                    return;

                if (Creature* l_Phemos = GetCaster()->ToCreature())
                {
                    if (!l_Phemos->IsAIEnabled)
                        return;

                    uint32 l_Count = l_Phemos->AI()->GetData(eMisc::EnfeeblingCounter);
                    if (!l_Count)
                        l_Count = 1;

                    int32 l_Damage = GetHitDamage() * 10 / l_Count;
                    SetHitDamage(l_Damage);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_highmaul_enfeebling_roar_SpellScript::HandleDamage, EFFECT_2, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_highmaul_enfeebling_roar_SpellScript();
        }
};

/// Shield Charge - 158134
class spell_highmaul_pol_shield_charge : public SpellScriptLoader
{
    public:
        spell_highmaul_pol_shield_charge() : SpellScriptLoader("spell_highmaul_pol_shield_charge") { }

        class spell_highmaul_pol_shield_charge_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_highmaul_pol_shield_charge_SpellScript);

            WorldLocation m_Location;

            void HandleBeforeCast()
            {
                if (WorldLocation const* l_Loc = GetExplTargetDest())
                    m_Location = *l_Loc;
            }

            void HandleAfterCast()
            {
                if (Unit* caster = GetCaster())
                    caster->GetMotionMaster()->MoveCharge(m_Location.m_positionX, m_Location.m_positionY, m_Location.m_positionZ, SPEED_CHARGE, GetSpellInfo()->Id);
            }

            void Register() override
            {
                BeforeCast += SpellCastFn(spell_highmaul_pol_shield_charge_SpellScript::HandleBeforeCast);
                AfterCast += SpellCastFn(spell_highmaul_pol_shield_charge_SpellScript::HandleAfterCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_highmaul_pol_shield_charge_SpellScript();
        }

        class spell_highmaul_pol_shield_charge_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_pol_shield_charge_AuraScript);

            enum eSpell
            {
                ShieldChargeDamage = 158159
            };

            uint32 m_DamageTimer;

            bool Load() override
            {
                m_DamageTimer = 500;
                return true;
            }

            void OnUpdate(uint32 diff)
            {
                if (m_DamageTimer)
                {
                    if (m_DamageTimer <= diff)
                    {
                        if (Unit* caster = GetCaster())
                        {
                            std::list<Unit*> targetList;
                            float radius = 1.0f;

                            Trinity::AnyUnfriendlyUnitInObjectRangeCheck l_Check(caster, caster, radius);
                            Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> l_Searcher(caster, targetList, l_Check);
                            Cell::VisitAllObjects(caster, l_Searcher, radius);

                            for (Unit* itr : targetList)
                                caster->CastSpell(itr, eSpell::ShieldChargeDamage, true);
                        }

                        m_DamageTimer = 500;
                    }
                    else
                        m_DamageTimer -= diff;
                }
            }

            void Register() override
            {
                OnAuraUpdate += AuraUpdateFn(spell_highmaul_pol_shield_charge_AuraScript::OnUpdate);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_pol_shield_charge_AuraScript();
        }
};

/// Aggressive Disposition - 157951
/// Fierce Disposition - 158016
/// Savage Disposition - 158017
class spell_highmaul_twin_ogron_dispositions : public SpellScriptLoader
{
    public:
        spell_highmaul_twin_ogron_dispositions() : SpellScriptLoader("spell_highmaul_twin_ogron_dispositions") { }

        class spell_highmaul_twin_ogron_dispositions_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_twin_ogron_dispositions_AuraScript);

            enum eSpells
            {
                AggressiveDisposition   = 157951,
                FierceDisposition       = 158016,
                SavageDisposition       = 158017
            };

            uint32 m_CheckTimer;

            bool Load() override
            {
                m_CheckTimer = 200;
                return true;
            }

            void OnUpdate(uint32 diff)
            {
                if (m_CheckTimer)
                {
                    if (m_CheckTimer <= diff)
                    {
                        if (Unit* caster = GetCaster())
                        {
                            uint32 l_Entry = caster->GetEntry() == eHighmaulCreatures::Pol ? eHighmaulCreatures::Phemos : eHighmaulCreatures::Pol;
                            if (Creature* l_Other = caster->FindNearestCreature(l_Entry, 150.0f))
                            {
                                float distance = std::min(caster->GetDistance(l_Other), 100.0f);
                                uint32 l_SpellID = 0;

                                if (distance >= 50.0f)
                                    l_SpellID = eSpells::SavageDisposition;
                                else if (distance >= 20.0f)
                                    l_SpellID = eSpells::FierceDisposition;
                                else
                                    l_SpellID = eSpells::AggressiveDisposition;

                                if ((int32)distance > eHighmaulDatas::DispositionPCT)
                                {
                                    if (InstanceScript* l_Instance = l_Other->GetInstanceScript())
                                        l_Instance->SetData(eHighmaulDatas::TwinOgronAchievement, 1);
                                }

                                if (!caster->HasAura(l_SpellID))
                                    caster->CastSpell(caster, l_SpellID, true);

                                if (!l_Other->HasAura(l_SpellID))
                                    l_Other->CastSpell(l_Other, l_SpellID, true);

                                if (Aura* casterAura = caster->GetAura(l_SpellID))
                                {
                                    if (AuraEffect* l_FirstEff = casterAura->GetEffect(EFFECT_0))
                                        l_FirstEff->ChangeAmount((int32)distance);

                                    if (AuraEffect* l_SecondEff = casterAura->GetEffect(EFFECT_1))
                                        l_SecondEff->ChangeAmount((int32)distance);
                                }

                                if (Aura* l_OtherAura = l_Other->GetAura(l_SpellID))
                                {
                                    if (AuraEffect* l_FirstEff = l_OtherAura->GetEffect(EFFECT_0))
                                        l_FirstEff->ChangeAmount((int32)distance);

                                    if (AuraEffect* l_SecondEff = l_OtherAura->GetEffect(EFFECT_1))
                                        l_SecondEff->ChangeAmount((int32)distance);
                                }

                                caster->SetPower(Powers::POWER_ALTERNATE_POWER, (int32)distance);
                                l_Other->SetPower(Powers::POWER_ALTERNATE_POWER, (int32)distance);
                            }
                        }

                        m_CheckTimer = 200;
                    }
                    else
                        m_CheckTimer -= diff;
                }
            }

            void Register() override
            {
                OnAuraUpdate += AuraUpdateFn(spell_highmaul_twin_ogron_dispositions_AuraScript::OnUpdate);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_twin_ogron_dispositions_AuraScript();
        }
};

/// Pulverize (Wave 3) - 158420
class spell_highmaul_pulverize_third_wave : public SpellScriptLoader
{
    public:
        spell_highmaul_pulverize_third_wave() : SpellScriptLoader("spell_highmaul_pulverize_third_wave") { }

        class spell_highmaul_pulverize_third_wave_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_highmaul_pulverize_third_wave_SpellScript);

            void HandleDamage(SpellEffIndex /*effIndex*/)
            {
                if (WorldLocation const* l_Loc = GetExplTargetDest())
                {
                    if (Unit* target = GetHitUnit())
                    {
                        int32 l_Coeff = (int32)std::min(100.0f, target->GetDistance(*l_Loc));
                        int32 l_Damage = GetHitDamage();
                        SetHitDamage(l_Damage - CalculatePct(l_Damage, l_Coeff));
                    }
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_highmaul_pulverize_third_wave_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_highmaul_pulverize_third_wave_SpellScript();
        }
};

/// Whirlwind - 157943
class spell_highmaul_phemos_whirlwind : public SpellScriptLoader
{
    public:
        spell_highmaul_phemos_whirlwind() : SpellScriptLoader("spell_highmaul_phemos_whirlwind") { }

        class spell_highmaul_phemos_whirlwind_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_phemos_whirlwind_AuraScript);

            enum eSpell
            {
                WeakenedDefenses = 159709
            };

            void OnTick(AuraEffect const* /*aurEff*/)
            {
                if (Unit* caster = GetCaster())
                    caster->CastSpell(caster, eSpell::WeakenedDefenses, true);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_highmaul_phemos_whirlwind_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_phemos_whirlwind_AuraScript();
        }
};

/// Blaze (DoT) - 158241
class spell_highmaul_blaze_dot : public SpellScriptLoader
{
    public:
        spell_highmaul_blaze_dot() : SpellScriptLoader("spell_highmaul_blaze_dot") { }

        class spell_highmaul_blaze_dot_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_blaze_dot_AuraScript);

            enum eSpells
            {
                BlazeFirst  = 162901,
                BlazeSecond = 168374
            };

            void OnTick(AuraEffect const* aurEff)
            {
                if (Unit* target = GetTarget())
                {
                    AreaTrigger* l_AT = target->SelectNearestAreaTrigger(eSpells::BlazeFirst, 1.0f);
                    if (l_AT == nullptr)
                        l_AT = target->SelectNearestAreaTrigger(eSpells::BlazeSecond, 1.0f);

                    if (l_AT == nullptr)
                        return;
                    else
                        aurEff->GetBase()->ModStackAmount(1);
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_highmaul_blaze_dot_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_blaze_dot_AuraScript();
        }
};

/// Blaze - 162901
/// Blaze - 168374
class areatrigger_highmaul_phemos_blaze : public AreaTriggerAI
{
public:
    areatrigger_highmaul_phemos_blaze(AreaTrigger* areaTrigger) : AreaTriggerAI(areaTrigger) { }

    enum eSpell
    {
        BlazeDoT = 158241
    };

    void OnUnitEnter(Unit* unit) override
    {
        if (Unit* caster = at->GetCaster())
            if (!unit->HasAura(eSpell::BlazeDoT))
                caster->CastSpell(unit, eSpell::BlazeDoT, true);
    }
};

void AddSC_boss_twin_ogron()
{
    /// Bosses
    new boss_twin_ogron_pol();
    new boss_twin_ogron_phemos();

    /// Spells
    new spell_highmaul_warming_up();
    new spell_highmaul_disposition();
    new spell_highmaul_enfeebling_roar();
    new spell_highmaul_pol_shield_charge();
    new spell_highmaul_twin_ogron_dispositions();
    new spell_highmaul_pulverize_third_wave();
    new spell_highmaul_phemos_whirlwind();
    new spell_highmaul_blaze_dot();

    /// AreaTrigger
    RegisterAreaTriggerAI(areatrigger_highmaul_phemos_blaze);
}
