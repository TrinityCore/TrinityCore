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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "instance_bloodmaul.h"
#include "G3D/Vector3.h"
#include "GridNotifiersImpl.h"

namespace Instances { namespace Bloodmaul
{
    static Position const s_FieryBoulderPos1 = { 2298.648f, -218.2934f, 253.099f, 3.068156f };
    static Position const s_FieryBoulderPos2 = { 2297.642f, -211.8681f, 253.099f, 3.068156f };
    static Position const s_FieryBoulderPos3 = { 2297.642f, -204.1632f, 253.099f, 3.068156f };

    static float const s_PositionZ = 213.29f;

    static Position const s_HeatWavePos = { 2312.793f, -211.3021f, 217.0487f, 3.178043f };

    static float const s_MaxPositionX = 2286.39f;
    static float const s_MinPositionX = 2244.11f;
    static float const s_MaxPositionY = -196.27f;
    static float const s_MinPositionY = -226.51f;

    /// Roltall - 75786
    class boss_roltall : public CreatureScript
    {
        public:
            boss_roltall() : CreatureScript("boss_roltall") { }

            enum eSpells
            {
                SpellScorchingAura              = 167738,   ///< Only for Heroic mode

                /// Burning Slag
                SpellBurningSlagDummy           = 152939,   ///< 0.5s cast -> Must trigger 152918 on random player
                SpellBurningSlagMissile         = 152918,   ///< Trigger 152913 on player location -> Create AreaTrigger

                /// Heatwave
                SpellHeatWaveAuraDummy          = 152940,   ///< 1.5s cast -> 8s duration
                SpellHeatWaveAreaTrigger        = 152867,
                SpellHeatWavePeriodicDamage     = 152897,
                SpellHeatWaveVisual             = 152896,

                /// Fiery Boulder
                SpellFieryBoulderCasted         = 153247,
                SpellFieryBoulderRockVisual     = 163733,
                SpellFieryBoulderFireVisual     = 152850,
                SpellFieryBoulderEarthquake     = 153058,   ///< Makes the screen shaking !
                SpellFieryBoulderTriggerVisual  = 152860
            };

            enum eEvents
            {
                EventHeatWave = 1,
                EventHeatWaveEnd,
                EventFieryBoulder,
                EventBurningSlag,
                EventCheckVictimDistance
            };

            enum eDatas
            {
                MaxFieryBoulder = 3,
                MaxBurningSlag  = 6,

                NoBoulderSpawn  = 0x00,
                Boulder1Spawned = 0x01,
                Boulder2Spawned = 0x02,
                Boulder3Spawned = 0x04,
                AllBoulderSpawn = 0x07
            };

            struct boss_roltallAI : public BossAI
            {
                boss_roltallAI(Creature* creature) : BossAI(creature, BossIds::BossRoltall)
                {
                    m_Instance = creature->GetInstanceScript();
                }

                InstanceScript* m_Instance;
                EventMap m_Events;

                uint8 m_FieryBoulderCount;
                uint8 m_FieryBoulderFlags;

                uint8 m_BurningSlagCount;

                void Reset() override
                {
                    m_Events.Reset();

                    _Reset();

                    /// -100% casting speed of players in melee range
                    if (!IsHeroic())
                        me->RemoveAura(eSpells::SpellScorchingAura);
                    else
                        me->AddAura(eSpells::SpellScorchingAura, me);

                    if (m_Instance != nullptr)
                        m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                    m_FieryBoulderCount = 0;
                    m_FieryBoulderFlags = eDatas::NoBoulderSpawn;
                    m_BurningSlagCount  = eDatas::MaxBurningSlag;

                    me->AddUnitState(UnitState::UNIT_STATE_ROOT);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                    //me->RemoveAllAreaTriggers();
                }

                void JustDied(Unit*) override
                {
                    _JustDied();

                    //me->RemoveAllAreaTriggers();

                    if (m_Instance != nullptr)
                        m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);
                }

                void EnterCombat(Unit*) override
                {
                    _EnterCombat();

                    m_Events.ScheduleEvent(eEvents::EventHeatWave, 20 * TimeConstants::IN_MILLISECONDS);
                    m_Events.ScheduleEvent(eEvents::EventFieryBoulder, 7 * TimeConstants::IN_MILLISECONDS);
                    m_Events.ScheduleEvent(eEvents::EventBurningSlag, 28 * TimeConstants::IN_MILLISECONDS);
                    m_Events.ScheduleEvent(eEvents::EventCheckVictimDistance, 2 * TimeConstants::IN_MILLISECONDS);

                    if (m_Instance != nullptr)
                        m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me);
                }

                void SpellHit(Unit*, SpellInfo const* spellInfo) override
                {
                    switch (spellInfo->Id)
                    {
                        case eSpells::SpellFieryBoulderCasted:
                        {
                            if (m_FieryBoulderFlags >= eDatas::AllBoulderSpawn)
                                break;

                            Creature* fieryBoulder = nullptr;
                            float triggerMinY = 0.0f;
                            float triggerMaxY = 0.0f;

                            do
                            {
                                uint8 l_Boulder = urand(0, 2);
                                uint32 l_BoulderEntry = 0;

                                if ((1 << l_Boulder) & eDatas::Boulder1Spawned && !(m_FieryBoulderFlags & eDatas::Boulder1Spawned))
                                {
                                    m_FieryBoulderFlags |= eDatas::Boulder1Spawned;
                                    l_BoulderEntry = MobEntries::FieryBoulder1;

                                    triggerMinY = s_FieryBoulderPos1.GetPositionY() - 1;
                                    triggerMaxY = s_FieryBoulderPos1.GetPositionY() - 1;

                                    fieryBoulder = me->SummonCreature(l_BoulderEntry, s_FieryBoulderPos1);
                                }
                                else if ((1 << l_Boulder) & eDatas::Boulder2Spawned && !(m_FieryBoulderFlags & eDatas::Boulder2Spawned))
                                {
                                    m_FieryBoulderFlags |= eDatas::Boulder2Spawned;
                                    l_BoulderEntry = MobEntries::FieryBoulder2;

                                    triggerMinY = s_FieryBoulderPos2.GetPositionY() - 1;
                                    triggerMaxY = s_FieryBoulderPos2.GetPositionY() - 1;

                                    fieryBoulder = me->SummonCreature(l_BoulderEntry, s_FieryBoulderPos2);
                                }
                                else if ((1 << l_Boulder) & eDatas::Boulder3Spawned && !(m_FieryBoulderFlags & eDatas::Boulder3Spawned))
                                {
                                    m_FieryBoulderFlags |= eDatas::Boulder3Spawned;
                                    l_BoulderEntry = MobEntries::FieryBoulder3;

                                    triggerMinY = s_FieryBoulderPos3.GetPositionY() - 1;
                                    triggerMaxY = s_FieryBoulderPos3.GetPositionY() - 1;

                                    fieryBoulder = me->SummonCreature(l_BoulderEntry, s_FieryBoulderPos3);
                                }
                            }
                            while (fieryBoulder == nullptr);  ///< Is this safe ?

                            std::list<Creature*> triggerList;
                            me->GetCreatureListWithEntryInGrid(triggerList, 68553, 10.0f);

                            for (Creature* creature : triggerList)
                            {
                                if (creature->GetPositionY() > triggerMinY &&
                                    creature->GetPositionY() < triggerMaxY)
                                {
                                    creature->AddAura(eSpells::SpellFieryBoulderTriggerVisual, creature);
                                    break;
                                }
                            }

                            if (fieryBoulder != nullptr)
                            {
                                fieryBoulder->CastSpell(fieryBoulder, eSpells::SpellFieryBoulderRockVisual, true);
                                fieryBoulder->CastSpell(fieryBoulder, eSpells::SpellFieryBoulderFireVisual, true);
                                fieryBoulder->CastSpell(fieryBoulder, eSpells::SpellFieryBoulderEarthquake, true);
                            }
                            break;
                        }
                        case eSpells::SpellHeatWaveAuraDummy:
                        {
                            if (Creature* lavaHeatTrigger = me->FindNearestCreature(MobEntries::LavaHeatTrigger, 20.0f))
                            {
                                lavaHeatTrigger->CastSpell(lavaHeatTrigger, eSpells::SpellHeatWaveAreaTrigger, true);
                                lavaHeatTrigger->CastSpell(lavaHeatTrigger, eSpells::SpellHeatWaveVisual, true);  ///< Heat wind visual
                                lavaHeatTrigger->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN);
                            }

                            me->SetFacingTo(me->GetHomePosition().GetOrientation());
                            me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN);
                            m_Events.ScheduleEvent(eEvents::EventHeatWaveEnd, 8 * TimeConstants::IN_MILLISECONDS);
                            break;
                        }
                        case eSpells::SpellBurningSlagDummy:
                        {
                            G3D::Vector3 l_SpawnPos = GetBurningSlagSpawnPos();
                            me->CastSpell(l_SpawnPos.x, l_SpawnPos.y, l_SpawnPos.z, eSpells::SpellBurningSlagMissile, true);
                            --m_BurningSlagCount;
                            break;
                        }
                        default:
                            break;
                    }
                }

                void EnterEvadeMode(EvadeReason /*why*/) override
                {
                    /// Don't need classic EvadeMode, Roltall can't move
                    _EnterEvadeMode();
                    Reset();
                }

                void UpdateAI(uint32 const diff) override
                {
                    if (!UpdateVictim())
                        return;

                    m_Events.Update(diff);

                    if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                        return;

                    switch (m_Events.ExecuteEvent())
                    {
                        case eEvents::EventHeatWave:
                            me->CastSpell(me, eSpells::SpellHeatWaveAuraDummy, false);
                            m_Events.ScheduleEvent(eEvents::EventHeatWave, 40 * TimeConstants::IN_MILLISECONDS);
                            break;
                        case eEvents::EventHeatWaveEnd:
                            me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN);
                            break;
                        case eEvents::EventFieryBoulder:
                        {
                            if (!m_FieryBoulderCount)
                                m_FieryBoulderFlags = eDatas::NoBoulderSpawn;

                            me->CastSpell(me, eSpells::SpellFieryBoulderCasted, false);
                            ++m_FieryBoulderCount;

                            if (m_FieryBoulderCount < eDatas::MaxFieryBoulder)
                                m_Events.ScheduleEvent(eEvents::EventFieryBoulder, 100);
                            else
                            {
                                m_FieryBoulderCount = 0;
                                m_Events.ScheduleEvent(eEvents::EventFieryBoulder, 30 * TimeConstants::IN_MILLISECONDS);
                            }

                            break;
                        }
                        case eEvents::EventBurningSlag:
                        {
                            if (!m_BurningSlagCount)
                            {
                                m_BurningSlagCount = eDatas::MaxBurningSlag;
                                m_Events.ScheduleEvent(eEvents::EventBurningSlag, 28 * TimeConstants::IN_MILLISECONDS);
                            }
                            else
                            {
                                me->CastSpell(me, eSpells::SpellBurningSlagDummy, false);
                                m_Events.ScheduleEvent(eEvents::EventBurningSlag, 550);
                            }
                            break;
                        }
                        case eEvents::EventCheckVictimDistance:
                        {
                            if (me->GetVictim() && me->GetVictim()->GetDistance(me) > 50.0f)
                                EnterEvadeMode(EVADE_REASON_BOUNDARY);

                            m_Events.ScheduleEvent(eEvents::EventCheckVictimDistance, 2 * TimeConstants::IN_MILLISECONDS);
                            break;
                        }
                        default:
                            break;
                    }

                    DoMeleeAttackIfReady();
                }

                G3D::Vector3 GetBurningSlagSpawnPos()
                {
                    float posX = frand(s_MinPositionX, s_MaxPositionX);
                    float posY = frand(s_MinPositionY, s_MaxPositionY);
                    return G3D::Vector3(posX, posY, s_PositionZ);
                }
            };

            CreatureAI* GetAI(Creature* creature) const override
            {
                return new boss_roltallAI(creature);
            }
    };

    /// FieryBoulder - 75853, 75854, 75828
    class npc_fiery_boulder : public CreatureScript
    {
        public:
            npc_fiery_boulder() : CreatureScript("npc_fiery_boulder") { }

            enum eSpells
            {
                SpellFieryBoulderDamage = 152742,   ///< Damage impact
                SpellFieryBoulderStun   = 152843,   ///< And deal damage on the trajectory
                SpellAlphaFadeOut       = 141608
            };

            enum eEvents
            {
                EventDealDamage = 1,
                EventMovePoint
            };

            enum eMoves
            {
                FirstMove = 1,
                SecondMove  ///< Only in heroic
            };

            struct npc_fiery_boulderAI : public ScriptedAI
            {
                npc_fiery_boulderAI(Creature* creature) : ScriptedAI(creature) { }

                EventMap m_Events;

                void Reset() override
                {
                    me->SetReactState(ReactStates::REACT_PASSIVE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);

                    m_Events.ScheduleEvent(eEvents::EventMovePoint, 2 * TimeConstants::IN_MILLISECONDS);
                }

                void MovementInform(uint32 type, uint32 id) override
                {
                    if (type != MovementGeneratorType::POINT_MOTION_TYPE)
                        return;

                    bool l_Despawn = false;

                    if (IsHeroic())
                    {
                        if (id == eMoves::FirstMove)  ///< Only in Heroic
                        {
                            float l_X = me->GetPositionX() + ((65.0f) * cos(me->GetOrientation() + M_PI));
                            float l_Y = me->GetPositionY() + ((65.0f) * sin(me->GetOrientation() + M_PI));

                            me->GetMotionMaster()->Clear();
                            me->GetMotionMaster()->MovePoint(eMoves::SecondMove, l_X, l_Y, s_PositionZ);
                        }
                        else if (id == eMoves::SecondMove)
                            l_Despawn = true;
                    }
                    else if (id == eMoves::FirstMove)
                        l_Despawn = true;

                    if (l_Despawn)
                    {
                        me->CastSpell(me, eSpells::SpellAlphaFadeOut, true);    ///< This makes ModelID disappear
                        me->DespawnOrUnsummon(200);
                        m_Events.CancelEvent(eEvents::EventDealDamage);
                    }
                }

                void UpdateAI(uint32 const diff) override
                {
                    m_Events.Update(diff);

                    switch (m_Events.ExecuteEvent())
                    {
                        case eEvents::EventDealDamage:
                        {
                            std::list<Player*> playerList;
                            me->GetPlayerListInGrid(playerList, 5.0f);

                            for (Player* player : playerList)
                                if (!player->HasAura(eSpells::SpellFieryBoulderStun))
                                    me->CastSpell(player, eSpells::SpellFieryBoulderStun, true);

                            m_Events.ScheduleEvent(eEvents::EventDealDamage, 500);
                            break;
                        }
                        case eEvents::EventMovePoint:
                        {
                            me->m_positionZ = s_PositionZ;
                            me->CastSpell(me, eSpells::SpellFieryBoulderDamage, true);

                            float l_X = me->GetPositionX() + ((55.0f) * cos(me->GetOrientation()));
                            float l_Y = me->GetPositionY() + ((55.0f) * sin(me->GetOrientation()));

                            me->GetMotionMaster()->Clear();
                            me->GetMotionMaster()->MovePoint(eMoves::FirstMove, l_X, l_Y, s_PositionZ);
                            m_Events.ScheduleEvent(eEvents::EventDealDamage, 500);
                            break;
                        }
                        default:
                            break;
                    }
                }
            };

            CreatureAI* GetAI(Creature* creature) const override
            {
                return new npc_fiery_boulderAI(creature);
            }
    };

    /// Scorching Aura - 167738
    class spell_roltall_scorching_aura : public SpellScriptLoader
    {
        public:
            spell_roltall_scorching_aura() : SpellScriptLoader("spell_roltall_scorching_aura") { }

            class spell_roltall_scorching_aura_AuraScript : public AuraScript
            {
                PrepareAuraScript(spell_roltall_scorching_aura_AuraScript);

                enum eSpells
                {
                    ScorchingAuraDebuff = 167739
                };

                void OnUpdate(uint32)
                {
                    if (Unit* caster = GetCaster())
                    {
                        std::list<Unit*> targetList;
                        GetCaster()->GetAttackableUnitListInRange(targetList, 15.0f);

                        for (Unit* unit : targetList)
                            caster->AddAura(eSpells::ScorchingAuraDebuff, unit);
                    }
                }

                void Register() override
                {
                    OnAuraUpdate += AuraUpdateFn(spell_roltall_scorching_aura_AuraScript::OnUpdate);
                }
            };

            AuraScript* GetAuraScript() const override
            {
                return new spell_roltall_scorching_aura_AuraScript();
            }
    };

    /// Heat Wave - 152867
    class areatrigger_roltall_heat_wave : public AreaTriggerAI
    {
        public:
            areatrigger_roltall_heat_wave(AreaTrigger* areaTrigger) : AreaTriggerAI(areaTrigger) { }

            enum eSpells
            {
                SpellPeriodicDamage = 152897
            };

            void OnUnitEnter(Unit* unit) override
            {
                if (Unit* caster = at->GetCaster())
                {
                    if (Player* player = unit->ToPlayer())
                    {
                        if (!player->HasMovementForce(at->GetGUID()))
                            player->ApplyMovementForce(at->GetGUID(), -7.0f, s_HeatWavePos);

                        if (!player->HasAura(eSpells::SpellPeriodicDamage))
                            caster->CastSpell(player, eSpells::SpellPeriodicDamage, true);
                    }
                }
            }

            void OnUnitExit(Unit* unit) override
            {
                if (Player* player = unit->ToPlayer())
                {
                    player->RemoveMovementForce(at->GetGUID());

                    if (player->HasAura(eSpells::SpellPeriodicDamage))
                        player->RemoveAurasDueToSpell(eSpells::SpellPeriodicDamage);
                }
            }
    };

    /// Burning Slag - 152913
    class areatrigger_roltall_burning_slag : public AreaTriggerAI
    {
        public:
            areatrigger_roltall_burning_slag(AreaTrigger* areaTrigger) : AreaTriggerAI(areaTrigger) { }

            enum eSpells
            {
                SpellPeriodicDamage = 153227
            };

            void OnUpdate(uint32) override
            {
                if (Unit* caster = at->GetCaster())
                {
                    std::list<Unit*> targetList;
                    caster->GetAttackableUnitListInRange(targetList, 4.0f);

                    for (Unit* unit : targetList)
                    {
                        if (unit->GetDistance(at) > 4.0f)
                            continue;

                        caster->CastSpell(unit, eSpells::SpellPeriodicDamage, true);
                    }
                }
            }
    };
}
} ///< namespace Instances

void AddSC_boss_roltall()
{
    new Instances::Bloodmaul::boss_roltall();
    new Instances::Bloodmaul::npc_fiery_boulder();
    new Instances::Bloodmaul::spell_roltall_scorching_aura();
    RegisterAreaTriggerAI(Instances::Bloodmaul::areatrigger_roltall_heat_wave);
    RegisterAreaTriggerAI(Instances::Bloodmaul::areatrigger_roltall_burning_slag);
}
