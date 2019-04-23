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
#include "Group.h"

Position g_CreepingMossPos[eHighmaulDatas::MaxCreepingMoss] =
{
    { 4096.283f, 7719.135f, 0.2535536f },
    { 4107.993f, 7719.417f, 0.2534866f },
    { 4100.202f, 7735.637f, 0.2534722f },
    { 4095.731f, 7745.500f, 0.2534722f },
    { 4105.304f, 7757.403f, 0.2534722f },
    { 4124.274f, 7726.856f, 0.2535520f },
    { 4114.686f, 7764.564f, 0.2534722f },
    { 4128.087f, 7739.741f, 0.2534592f },
    { 4138.525f, 7750.965f, 0.2534567f },
    { 4148.499f, 7756.370f, 0.2527755f },
    { 4111.810f, 7739.060f, 0.2535081f },
    { 4133.647f, 7758.851f, 0.2534722f },
    { 4126.690f, 7767.401f, 0.2534722f },
    { 4139.254f, 7735.781f, 0.2535115f },
    { 4118.909f, 7753.566f, 0.2534722f },
    { 4151.049f, 7743.521f, 0.6013964f }
};

Position const g_FleshEaterSpawns[eHighmaulDatas::MaxFleshEaterPos] =
{
    { 4178.046f, 7791.621f, -0.3537667f, 3.052145f },
    { 4141.948f, 7720.839f, -1.1697650f, 2.001688f }
};

Position const g_flameThrowerDefaultSpawns[eHighmaulDatas::MaxFleshEaterPos] =
{
    { 4089.879883f, 7758.709961f, 0.336928f, 0.0f },
    { 4085.929932f, 7737.870117f, 0.338542f, 0.0f }
};

G3D::Vector3 g_BeachCenter = { 4104.36f, 7769.18f, 0.254f };

void ResetPlayersPower(Creature* source)
{
    if (source == nullptr)
        return;

    Map::PlayerList const& players = source->GetMap()->GetPlayers();
    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
    {
        if (Player* player = itr->GetSource())
            player->SetPower(Powers::POWER_ALTERNATE_POWER, 0);
    }
}

/// Brackenspore <Walker of the Deep> - 78491
class boss_brackenspore : public CreatureScript
{
    public:
        boss_brackenspore() : CreatureScript("boss_brackenspore") { }

        enum eSpells
        {
            /// Misc
            RotDot                  = 163241,
            CreepingMossPeriodic    = 163347,
            CreepingMossAreaTrigger = 173229,
            FlamethrowerDespawnAT   = 173281,
            BFC9000                 = 164175,
            FlamethrowerAura        = 163663,
            BurningInfusion         = 165223,
            EnergyRegen             = 164248,
            /// Necrotic Breath
            SpellNecroticBreath     = 159219,   ///< Triggers 159220 every second
            /// Infesting Spores
            SpellInfestingSpores    = 159996,   ///< Triggers 163242 every second
            /// Mind Fungus
            SummonMindFungus        = 163141,
            /// Fungal Flesh-Eater
            SummonFungalFleshEater  = 163142,
            /// Spore Shooter
            SporeShooterDummy       = 163594,
            SummonSporeShooter      = 160446,
            /// Living Mushroom
            SummonLivingMushroom    = 160022,
            /// Rejuvenating Mushroom
            RejuvenatingMushDummy   = 177820,
            SummonRejuvenatingMush  = 160021,
            /// Loot
            BrackensporeBonus       = 177524,

            /// Mythic mode only
            SpellCallOfTheTides     = 160425,
            CallOfTheTidesSummonAT  = 160413,
            ExplosiveShroomChannel  = 163794
        };

        enum eEvents
        {
            EventNecroticBreath = 1,
            EventBerserker,
            EventInfestingSpores,
            EventCheckForIntro,
            EventMindFungus,
            EventLivingMushroom,
            EventSporeShooter,
            EventFungalFleshEater,
            EventRejuvenatingMushroom,
            EventSpecialAbility,
            EventScheduleEnergy,
            EventRot
        };

        enum eActions
        {
            DoIntro,
            CreepingMoss,
            InfestingSpores
        };

        enum eCreatures
        {
            /// Cosmetic part
            IronWarmaster       = 86609,
            IronFlameTechnician = 86607,
            MindFungus          = 86611,
            SporeShooter        = 86612,
            WorldTrigger        = 59481,
            /// Fight
            SporeShooterFight   = 79183,
            MindFungusFight     = 79082,
            FungalFleshEater    = 79092,
            LivingMushroom      = 78884,
            RejuvenatingMush    = 78868,
            InvisibleMan        = 64693,
            /// Explosive Shroom
            TriggerA            = 2000006, //targetted by 163777(60ft) 
            TriggerB            = 2000007, //targetted by 163813(60ft)
            TriggerC            = 2000008, //targetted by 163815(60ft)
            TriggerD            = 2000009, //targetted by 163796(40ft)
        };

        enum eTalk
        {
            WarnInfestingSpores
        };

        struct boss_brackensporeAI : public BossAI
        {
            boss_brackensporeAI(Creature* creature) : BossAI(creature, eHighmaulDatas::BossBrackenspore)
            {
                m_Instance  = creature->GetInstanceScript();
                m_IntroDone = false;
            }

            EventMap m_Events;
            InstanceScript* m_Instance;

            EventMap m_CosmeticEvent;
            std::list<ObjectGuid> m_Creatures;

            std::set<ObjectGuid> m_CreepingMoss;

            bool m_IntroDone;

            void Reset() override
            {
                m_Events.Reset();

                _Reset();

                me->RemoveAura(eHighmaulSpells::Berserker);
                me->RemoveAura(eSpells::CreepingMossPeriodic);

                me->SetPower(Powers::POWER_RAGE, 0);
                me->SetMaxPower(Powers::POWER_RAGE, 500);

                me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_REGENERATE_POWER);

                me->RemoveAura(eSpells::EnergyRegen);

                me->RemoveAllAreaTriggers();
                m_CreepingMoss.clear();

                if (m_Instance != nullptr)
                {
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::RotDot);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::FlamethrowerAura);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::BurningInfusion);
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);
                }

                ResetPlayersPower(me);

                if (!m_IntroDone)
                {
                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, 438);

                    AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                    {
                        for (uint8 l_I = 0; l_I < eHighmaulDatas::MaxCreepingMoss; ++l_I)
                            me->CastSpell(g_CreepingMossPos[l_I], eSpells::CreepingMossAreaTrigger, true);
                    });
                }
                else
                {
                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);

                    RespawnFlamethrowers();
                }
            }

            bool CanRespawn() override
            {
                return false;
            }

            void RespawnFlamethrowers()
            {
                me->DespawnCreaturesInArea(eHighmaulCreatures::BFC9000, 200.0f);
                for (Position pos : g_flameThrowerDefaultSpawns)
                {
                    me->SummonCreature(eHighmaulCreatures::BFC9000, pos);
                }
            }

            void JustRegisteredAreaTrigger(AreaTrigger* at) override
            {
                if (at == nullptr)
                    return;

                if (m_CreepingMoss.find(at->GetGUID()) != m_CreepingMoss.end())
                    return;

                m_CreepingMoss.insert(at->GetGUID());
            }

            void JustUnregisteredAreaTrigger(AreaTrigger* at) override
            {
                if (at == nullptr)
                    return;

                if (m_CreepingMoss.find(at->GetGUID()) == m_CreepingMoss.end())
                    return;

                m_CreepingMoss.erase(at->GetGUID());
            }

            void DoAction(int32 const action) override
            {
                switch (action)
                {
                    case eActions::DoIntro:
                    {
                        m_IntroDone = true;

                        std::list<Creature*> l_Warmasters;
                        me->GetCreatureListWithEntryInGrid(l_Warmasters, eCreatures::IronWarmaster, 50.0f);

                        if (!l_Warmasters.empty())
                            l_Warmasters.sort(Trinity::ObjectDistanceOrderPred(me, false));

                        if (Creature* l_IronWar = (*l_Warmasters.begin()))
                        {
                            if (l_IronWar->GetAI())
                                l_IronWar->AI()->DoAction(eActions::DoIntro);

                            l_Warmasters.remove(l_IronWar);
                        }

                        AddTimedDelayedOperation(5 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                        {
                            std::vector<AreaTrigger*> areaTriggers = me->GetAreaTriggers(eSpells::CreepingMossAreaTrigger);

                            for (AreaTrigger* l_AT : areaTriggers)
                            {
                                me->CastSpell(*l_AT, eSpells::FlamethrowerDespawnAT, true);
                                l_AT->SetDuration(10);
                            }

                            RespawnFlamethrowers();

                            std::list<Creature*> l_MindFungus;
                            me->GetCreatureListWithEntryInGrid(l_MindFungus, eCreatures::MindFungus, 100.0f);

                            for (Creature* l_Creature : l_MindFungus)
                            {
                                l_Creature->RemoveAllAreaTriggers();
                                l_Creature->DespawnOrUnsummon();
                            }

                            if (Creature* l_Shooter = me->FindNearestCreature(eCreatures::SporeShooter, 100.0f))
                                l_Shooter->DespawnOrUnsummon();

                            std::list<Creature*> l_IronFlames;
                            me->GetCreatureListWithEntryInGrid(l_IronFlames, eCreatures::IronFlameTechnician, 50.0f);

                            for (Creature* l_Creature : l_IronFlames)
                            {
                                if (l_Creature->IsAIEnabled)
                                    l_Creature->AI()->DoAction(eActions::DoIntro);

                                if (Creature* l_Trigger = l_Creature->FindNearestCreature(eCreatures::WorldTrigger, 100.0f))
                                {
                                    l_Trigger->SetReactState(ReactStates::REACT_PASSIVE);
                                    l_Trigger->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);

                                    l_Creature->InterruptNonMeleeSpells(true);
                                    l_Creature->GetMotionMaster()->MovePoint(0, *l_Trigger);
                                }
                            }
                        });

                        std::list<ObjectGuid> l_WarMasterGuids;
                        for (Creature* itr : l_Warmasters)
                            l_WarMasterGuids.push_back(itr->GetGUID());

                        AddTimedDelayedOperation(8 * TimeConstants::IN_MILLISECONDS, [this, l_WarMasterGuids]() -> void
                        {
                            if (l_WarMasterGuids.empty())
                                return;

                            if (Creature* l_IronWar = ObjectAccessor::GetCreature(*me, (*l_WarMasterGuids.begin())))
                                me->Kill(l_IronWar);

                            Reset();
                        });

                        break;
                    }
                    case eActions::CreepingMoss:
                    {
                        SummonCreepingMoss();
                        break;
                    }
                    case eActions::InfestingSpores:
                    {
                        m_Events.ScheduleEvent(eEvents::EventInfestingSpores, 1);
                        break;
                    }
                    default:
                        break;
                }
            }

            void EnterCombat(Unit* /*attacker*/) override
            {
                _EnterCombat();

                m_Events.ScheduleEvent(eEvents::EventNecroticBreath, 30 * TimeConstants::IN_MILLISECONDS);
                m_Events.ScheduleEvent(eEvents::EventBerserker, 600 * TimeConstants::IN_MILLISECONDS);
                m_Events.ScheduleEvent(eEvents::EventMindFungus, 10 * TimeConstants::IN_MILLISECONDS);
                m_Events.ScheduleEvent(eEvents::EventLivingMushroom, 17 * TimeConstants::IN_MILLISECONDS);
                m_Events.ScheduleEvent(eEvents::EventSporeShooter, 20 * TimeConstants::IN_MILLISECONDS);
                m_Events.ScheduleEvent(eEvents::EventFungalFleshEater, 32 * TimeConstants::IN_MILLISECONDS);
                m_Events.ScheduleEvent(eEvents::EventRejuvenatingMushroom, 80 * TimeConstants::IN_MILLISECONDS);
                m_Events.ScheduleEvent(eEvents::EventRot, 10 * TimeConstants::IN_MILLISECONDS);

                /// Mythic Specials. Shared cd, which special he uses is random.
                if (IsMythic())
                    m_Events.ScheduleEvent(eEvents::EventSpecialAbility, 20 * TimeConstants::IN_MILLISECONDS);

                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me, 1);

                /// Spawn timer for Creeping Moss AreaTrigger
                /// 5s for LFR, 2s for Normal mode, 1.85s for Heroic mode
                /// 1.4s for Mythic mode and 1.75s for others
                me->CastSpell(me, eSpells::CreepingMossPeriodic, true);
                me->CastSpell(me, eSpells::EnergyRegen, true);

                std::list<Creature*> l_CosmeticMobs;
                me->GetCreatureListWithEntryInGrid(l_CosmeticMobs, eHighmaulCreatures::BlackrockGrunt, 800.0f);

                for (Creature* l_Grunt : l_CosmeticMobs)
                    l_Grunt->DespawnOrUnsummon();

                l_CosmeticMobs.clear();
                me->GetCreatureListWithEntryInGrid(l_CosmeticMobs, eCreatures::IronFlameTechnician, 80.0f);

                for (Creature* l_Technician : l_CosmeticMobs)
                    l_Technician->DespawnOrUnsummon();

                l_CosmeticMobs.clear();
                me->GetCreatureListWithEntryInGrid(l_CosmeticMobs, eCreatures::IronWarmaster, 80.0f);

                for (Creature* l_Warmaster : l_CosmeticMobs)
                    l_Warmaster->DespawnOrUnsummon();
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();

                if (m_Instance != nullptr)
                {
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::RotDot);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::FlamethrowerAura);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::BurningInfusion);

                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                    instance->DoCastSpellOnPlayers(eSpells::BrackensporeBonus, me);

                    if (IsLFR())
                    {
                        Map::PlayerList const& playerList = m_Instance->instance->GetPlayers();
                        if (playerList.isEmpty())
                            return;

                        /*for (Map::PlayerList::const_iterator l_Itr = playerList.begin(); l_Itr != playerList.end(); ++l_Itr)
                        {
                            if (Player* player = l_Itr->GetSource())
                            {
                                uint32 l_DungeonID = player->GetGroup() ? sLFGMgr->GetDungeon(player->GetGroup()->GetGUID()) : 0;
                                if (!me || player->IsAtGroupRewardDistance(me))
                                    sLFGMgr->RewardDungeonDoneFor(l_DungeonID, player);
                            }
                        }

                        Player* player = me->GetMap()->GetPlayers().begin()->GetSource();
                        if (player && player->GetGroup())
                            sLFGMgr->AutomaticLootAssignation(me, player->GetGroup());*/
                    }
                }

                ResetPlayersPower(me);

                me->DespawnCreaturesInArea(eHighmaulCreatures::BFC9000, 200.0f);

                me->RemoveAllAreaTriggers();
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                CreatureAI::EnterEvadeMode();

                if (m_Instance != nullptr)
                    m_Instance->SetBossState(eHighmaulDatas::BossBrackenspore, EncounterState::FAIL);
            }

            void SetGUID(ObjectGuid guid, int32 /*id*/) override
            {
                m_Creatures.push_back(guid);
                m_CosmeticEvent.RescheduleEvent(eEvents::EventCheckForIntro, 1000);
            }

            void SpellHitTarget(Unit* target, SpellInfo const* spellInfo) override
            {
                if (target == nullptr)
                    return;

                switch (spellInfo->Id)
                {
                    case eSpells::SummonMindFungus:
                        me->SummonCreature(eCreatures::MindFungusFight, *target, TempSummonType::TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20 * TimeConstants::IN_MILLISECONDS);
                        break;
                    case eSpells::SummonFungalFleshEater:
                        me->SummonCreature(eCreatures::FungalFleshEater, g_FleshEaterSpawns[urand(1, eHighmaulDatas::MaxFleshEaterPos) - 1],
                            TempSummonType::TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20 * TimeConstants::IN_MILLISECONDS);
                        break;
                    case eSpells::SporeShooterDummy:
                    {
                        uint8 l_Count = IsMythic() ? 4 : 2;
                        for (uint8 l_I = 0; l_I < l_Count; ++l_I)
                            me->CastSpell(me, eSpells::SummonSporeShooter, true);
                        break;
                    }
                    case eSpells::RejuvenatingMushDummy:
                        me->CastSpell(target, eSpells::SummonRejuvenatingMush, true);
                        break;
                    case eSpells::SpellCallOfTheTides:
                        target->CastSpell(target, eSpells::CallOfTheTidesSummonAT, true, nullptr, nullptr, target->GetGUID());
                        break;
                    default:
                        break;
                }
            }

            void RegeneratePower(Powers /*power*/, int32& value) override
            {
                /// Brackenspore only regens by script
                value = 0;
            }

            void UpdateAI(uint32 const diff) override
            {
                UpdateOperations(diff);

                m_CosmeticEvent.Update(diff);

                if (m_CosmeticEvent.ExecuteEvent())
                {
                    bool l_CanSchedule = true;
                    for (ObjectGuid guid : m_Creatures)
                    {
                        if (Creature* l_Add = ObjectAccessor::GetCreature(*me, guid))
                        {
                            if (l_Add->IsAlive())
                            {
                                l_CanSchedule = false;
                                break;
                            }
                        }
                    }

                    if (l_CanSchedule)
                        DoAction(eActions::DoIntro);
                    else
                        m_CosmeticEvent.ScheduleEvent(eEvents::EventCheckForIntro, 1000);
                }

                if (!UpdateVictim())
                    return;

                m_Events.Update(diff);

                /// Update moves here, avoid some movements problems after Infesting Spores
                if (me->GetVictim() && !me->IsWithinMeleeRange(me->GetVictim()) && me->HasAura(eSpells::SpellInfestingSpores))
                    me->GetMotionMaster()->MovePoint(0, me->GetVictim()->GetPosition());

                if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                    return;

                switch (m_Events.ExecuteEvent())
                {
                    case eEvents::EventNecroticBreath:
                        me->CastSpell(me, eSpells::SpellNecroticBreath, false);
                        m_Events.ScheduleEvent(eEvents::EventNecroticBreath, 32 * TimeConstants::IN_MILLISECONDS);
                        break;
                    case eEvents::EventBerserker:
                        me->CastSpell(me, eHighmaulSpells::Berserker, true);
                        break;
                    case eEvents::EventInfestingSpores:
                        Talk(eTalk::WarnInfestingSpores);
                        me->RemoveAura(eSpells::EnergyRegen);
                        me->CastSpell(me, eSpells::SpellInfestingSpores, false);
                        m_Events.ScheduleEvent(eEvents::EventScheduleEnergy, 12 * TimeConstants::IN_MILLISECONDS);
                        break;
                    case eEvents::EventMindFungus:
                        me->CastSpell(me, eSpells::SummonMindFungus, true);
                        m_Events.ScheduleEvent(eEvents::EventMindFungus, 30 * TimeConstants::IN_MILLISECONDS);
                        break;
                    case eEvents::EventLivingMushroom:
                        me->CastSpell(me, eSpells::SummonLivingMushroom, true);
                        m_Events.ScheduleEvent(eEvents::EventLivingMushroom, 55 * TimeConstants::IN_MILLISECONDS);
                        break;
                    case eEvents::EventSporeShooter:
                        me->CastSpell(me, eSpells::SporeShooterDummy, true);
                        m_Events.ScheduleEvent(eEvents::EventSporeShooter, 57 * TimeConstants::IN_MILLISECONDS);
                        break;
                    case eEvents::EventFungalFleshEater:
                        me->CastSpell(me, eSpells::SummonFungalFleshEater, true);
                        m_Events.ScheduleEvent(eEvents::EventFungalFleshEater, 120 * TimeConstants::IN_MILLISECONDS);
                        break;
                    case eEvents::EventRejuvenatingMushroom:
                        me->CastSpell(me, eSpells::RejuvenatingMushDummy, true);
                        m_Events.ScheduleEvent(eEvents::EventRejuvenatingMushroom, 130 * TimeConstants::IN_MILLISECONDS);
                        break;
                    case eEvents::EventSpecialAbility:
                        DoSpecialAbility();
                        m_Events.ScheduleEvent(eEvents::EventSpecialAbility, 20 * TimeConstants::IN_MILLISECONDS);
                        break;
                    case eEvents::EventScheduleEnergy:
                        if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO))
                            AttackStart(target);
                        me->CastSpell(me, eSpells::EnergyRegen, true);
                        me->GetMotionMaster()->Clear();
                        break;
                    case eEvents::EventRot:
                        if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO))
                            me->CastSpell(target, eSpells::RotDot, true);
                        m_Events.ScheduleEvent(eEvents::EventRot, 10 * TimeConstants::IN_MILLISECONDS);
                        break;
                    default:
                        break;
                }

                /// If boss is outside the beach, it should resets
                if (me->GetDistance(g_BeachCenter.x, g_BeachCenter.y, g_BeachCenter.z) >= 100.0f)
                {
                    EnterEvadeMode(EVADE_REASON_BOUNDARY);
                    return;
                }

                DoMeleeAttackIfReady();
            }

            void SummonCreepingMoss()
            {
                Map* l_Map = me->GetMap();
                if (l_Map == nullptr)
                    return;

                float orientation = frand(0.0f, 2.0f * float(M_PI));

                /// Use different spawn radius depending on orientation
                float radius = GetSpawnRangeByOrientation(orientation);

                float l_OStep = 2 * float(M_PI) / 30.0f;
                float l_X = g_BeachCenter.x + (radius * cos(orientation));
                float l_Y = g_BeachCenter.y + (radius * sin(orientation));
                float l_Z = l_Map->GetHeight(me->GetPhaseShift(), l_X, l_Y, MAX_HEIGHT);

                /// First of all, verify if we can spawn an AreaTrigger all around the beach center
                /// With a radius of 60-80 yards, it must cover the beach progressively
                {
                    if (me->IsWithinLOS(l_X, l_Y, l_Z) && CheckCreepingMossPosition(l_X, l_Y))
                    {
                        me->CastSpell(l_X, l_Y, l_Z, eSpells::CreepingMossAreaTrigger, true);
                        return;
                    }

                    for (uint8 l_J = 0; l_J < 30; ++l_J)
                    {
                        orientation = Position::NormalizeOrientation(orientation + l_OStep);
                        radius = GetSpawnRangeByOrientation(orientation);

                        l_X = g_BeachCenter.x + (radius * cos(orientation));
                        l_Y = g_BeachCenter.y + (radius * sin(orientation));
                        l_Z = l_Map->GetHeight(me->GetPhaseShift(), l_X, l_Y, MAX_HEIGHT);

                        if (me->IsWithinLOS(l_X, l_Y, l_Z) && CheckCreepingMossPosition(l_X, l_Y))
                        {
                            me->CastSpell(l_X, l_Y, l_Z, eSpells::CreepingMossAreaTrigger, true);
                            return;
                        }
                    }
                }

                float l_MaxRadius = 80.0f;
                float l_Step = 2.0f;

                /// Secondly, check for each less radius (2 yard step) ...
                for (uint8 l_I = 0; l_I < 45; ++l_I)
                {
                    l_MaxRadius -= l_Step;
                    radius = GetSpawnRangeByOrientation(orientation, l_MaxRadius);

                    l_X = g_BeachCenter.x + (radius * cos(orientation));
                    l_Y = g_BeachCenter.y + (radius * sin(orientation));
                    l_Z = l_Map->GetHeight(me->GetPhaseShift(), l_X, l_Y, MAX_HEIGHT);

                    if (me->IsWithinLOS(l_X, l_Y, l_Z) && CheckCreepingMossPosition(l_X, l_Y))
                    {
                        me->CastSpell(l_X, l_Y, l_Z, eSpells::CreepingMossAreaTrigger, true);
                        return;
                    }

                    /// ... and for each orientation (3.33% step)
                    for (uint8 l_J = 0; l_J < 30; ++l_J)
                    {
                        orientation = Position::NormalizeOrientation(orientation + l_OStep);
                        radius = GetSpawnRangeByOrientation(orientation, l_MaxRadius);

                        l_X = g_BeachCenter.x + (radius * cos(orientation));
                        l_Y = g_BeachCenter.y + (radius * sin(orientation));
                        l_Z = l_Map->GetHeight(me->GetPhaseShift(), l_X, l_Y, MAX_HEIGHT);

                        if (me->IsWithinLOS(l_X, l_Y, l_Z) && CheckCreepingMossPosition(l_X, l_Y))
                        {
                            me->CastSpell(l_X, l_Y, l_Z, eSpells::CreepingMossAreaTrigger, true);
                            return;
                        }
                    }
                }
            }

            bool CheckCreepingMossPosition(float p_X, float p_Y) const
            {
                /// No more than one Creeping Moss every 10 yards
                float l_CheckRange = 10.0f;

                for (ObjectGuid itr : m_CreepingMoss)
                {
                    if (AreaTrigger* l_AT = ObjectAccessor::GetAreaTrigger(*me, itr))
                    {
                        if (l_AT->GetDistance2d(p_X, p_Y) < l_CheckRange)
                            return false;
                    }
                }

                return true;
            }

            float GetSpawnRangeByOrientation(float p_Orientation, float p_MaxRadius = 80.0f) const
            {
                if (p_Orientation <= (M_PI / 4.0f))
                    return p_MaxRadius;
                else if (p_Orientation <= (3 * float(M_PI) / 4.0f))
                    return p_MaxRadius - 20.0f;
                else if (p_Orientation <= (5 * float(M_PI) / 4.0f))
                    return p_MaxRadius;
                else if (p_Orientation <= (2 * float(M_PI) - float(M_PI) / 4))
                    return p_MaxRadius - 20.0f;
                else
                    return p_MaxRadius;
            }

            void DoSpecialAbility()
            {
                /// Call of the Tides
                if (roll_chance_i(50))
                    me->CastSpell(me, eSpells::SpellCallOfTheTides, true);
                /// Exploding Fungus
                else
                    me->CastSpell(me, eSpells::ExplosiveShroomChannel, true);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_brackensporeAI(creature);
        }
};

/// Mind Fungus (Cosmetic) - 86611
/// Mind Fungus (For fight) - 79082
class npc_highmaul_mind_fungus : public CreatureScript
{
    public:
        npc_highmaul_mind_fungus() : CreatureScript("npc_highmaul_mind_fungus") { }

        enum eSpells
        {
            MindFungusVisual    = 171862,
            MindFungusAura      = 163138,
            MindFungusAT        = 159489
        };

        struct npc_highmaul_mind_fungusAI : public ScriptedAI
        {
            npc_highmaul_mind_fungusAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                me->CastSpell(me, eSpells::MindFungusVisual, true);
                me->CastSpell(me, eSpells::MindFungusAura, true);
                me->CastSpell(me, eSpells::MindFungusAT, true);

                me->AddUnitState(UnitState::UNIT_STATE_STUNNED);
            }

            void JustDied(Unit* /*killer*/) override
            {
                me->RemoveAura(eSpells::MindFungusVisual);
                me->RemoveAura(eSpells::MindFungusAura);
                me->RemoveAura(eSpells::MindFungusAT);
                me->RemoveAllAreaTriggers();
                me->DespawnOrUnsummon(500);
            }

            void UpdateAI(uint32 const /*diff*/) override { }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_highmaul_mind_fungusAI(creature);
        }
};

/// Spore Shooter (Cosmetic) - 86612
/// Spore Shooter (For fight) - 79183
class npc_highmaul_spore_shooter : public CreatureScript
{
    public:
        npc_highmaul_spore_shooter() : CreatureScript("npc_highmaul_spore_shooter") { }

        enum eSpell
        {
            SporeShot = 173241
        };

        enum eEvent
        {
            EventSporeShot = 1
        };

        struct npc_highmaul_spore_shooterAI : public ScriptedAI
        {
            npc_highmaul_spore_shooterAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap m_Events;

            void Reset() override
            {
                me->AddUnitState(UnitState::UNIT_STATE_ROOT);

                m_Events.Reset();
            }

            void EnterCombat(Unit* /*attacker*/) override
            {
                m_Events.ScheduleEvent(eEvent::EventSporeShot, urand(100, 1500));
            }

            void JustDied(Unit* /*killer*/) override
            {
                me->DespawnOrUnsummon(20 * TimeConstants::IN_MILLISECONDS);
            }

            void UpdateAI(uint32 const diff) override
            {
                if (!UpdateVictim())
                    return;

                m_Events.Update(diff);

                if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                    return;

                if (m_Events.ExecuteEvent() == eEvent::EventSporeShot)
                {
                    me->CastSpell(me, eSpell::SporeShot, false);
                    m_Events.ScheduleEvent(eEvent::EventSporeShot, 4500);
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_highmaul_spore_shooterAI(creature);
        }
};

/// Fungal Flesh-Eater - 79092
class npc_highmaul_fungal_flesh_eater : public CreatureScript
{
    public:
        npc_highmaul_fungal_flesh_eater() : CreatureScript("npc_highmaul_fungal_flesh_eater") { }

        enum eTalk
        {
            Warn
        };

        enum eSpells
        {
            InfestedWaters  = 164644,
            FleshEater      = 159972,
            Decay           = 160013
        };

        enum eEvents
        {
            EventDecay = 1,
            EventFleshEater
        };

        enum eData
        {
            AnimKit = 1718
        };

        struct npc_highmaul_fungal_flesh_eaterAI : public ScriptedAI
        {
            npc_highmaul_fungal_flesh_eaterAI(Creature* creature) : ScriptedAI(creature)
            {
                m_Instance = creature->GetInstanceScript();
            }

            InstanceScript* m_Instance;
            EventMap m_Events;
            bool m_Scheduled;

            void Reset() override
            {
                me->AddUnitState(UnitState::UNIT_STATE_ROOT);

                Talk(eTalk::Warn);

                AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    me->SetObjectScale(1.f);
                    me->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 0.31f);
                    me->SetFloatValue(UNIT_FIELD_COMBATREACH, 7.0f);
                });

                AddTimedDelayedOperation(5 * TimeConstants::IN_MILLISECONDS, [this]() -> void { me->PlayOneShotAnimKitId(eData::AnimKit); });
                AddTimedDelayedOperation(6 * TimeConstants::IN_MILLISECONDS, [this]() -> void { me->ClearUnitState(UnitState::UNIT_STATE_ROOT); });

                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me, 2);

                m_Scheduled = false;
            }

            void DamageDealt(Unit* /*p_Victim*/, uint32& /*damage*/, DamageEffectType /*damageType*/) override
            {
                if (!m_Scheduled)
                {
                    m_Scheduled = true;
                    m_Events.ScheduleEvent(eEvents::EventDecay, 5 * TimeConstants::IN_MILLISECONDS);
                    m_Events.ScheduleEvent(eEvents::EventFleshEater, 1 * TimeConstants::IN_MILLISECONDS);
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void UpdateAI(uint32 const diff) override
            {
                ScriptedAI::UpdateAI(diff);

                if (me->GetPositionZ() <= 0.0f && !me->HasAura(eSpells::InfestedWaters))
                    me->CastSpell(me, eSpells::InfestedWaters, true);
                else if (me->GetPositionZ() > 0.0f && me->HasAura(eSpells::InfestedWaters))
                    me->RemoveAura(eSpells::InfestedWaters);

                if (!UpdateVictim())
                    return;

                m_Events.Update(diff);

                if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                    return;

                switch (m_Events.ExecuteEvent())
                {
                    case eEvents::EventDecay:
                        me->CastSpell(me, eSpells::Decay, false);
                        m_Events.ScheduleEvent(eEvents::EventDecay, 10 * TimeConstants::IN_MILLISECONDS);
                        break;
                    case eEvents::EventFleshEater:
                        me->CastSpell(me, eSpells::FleshEater, true);
                        m_Events.ScheduleEvent(eEvents::EventFleshEater, 10 * TimeConstants::IN_MILLISECONDS);
                        break;
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_highmaul_fungal_flesh_eaterAI(creature);
        }
};

/// Living Mushroom - 78884
class npc_highmaul_living_mushroom : public CreatureScript
{
    public:
        npc_highmaul_living_mushroom() : CreatureScript("npc_highmaul_living_mushroom") { }

        enum eSpells
        {
            LivingMushroomVisual    = 159280,
            LivingMushroomL1Visual  = 164245,
            Withering3Percent       = 160399,
            Withering5Percent       = 163113,
            LivingSpores            = 159291
        };

        struct npc_highmaul_living_mushroomAI : public ScriptedAI
        {
            npc_highmaul_living_mushroomAI(Creature* creature) : ScriptedAI(creature)
            {
                m_Instance = creature->GetInstanceScript();
            }

            InstanceScript* m_Instance;

            void Reset() override
            {
                me->DisableHealthRegen();
                me->SetHealth(me->GetMaxHealth() / 2);
                me->AddUnitState(UnitState::UNIT_STATE_STUNNED);

                me->CastSpell(me, eSpells::LivingMushroomVisual, true);
                me->CastSpell(me, eSpells::LivingMushroomL1Visual, true);

                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me, 3);

                AddTimedDelayedOperation(6 * TimeConstants::IN_MILLISECONDS, [this]() -> void { me->CastSpell(me, eSpells::Withering3Percent, true); });

                AddTimedDelayedOperation(11 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    me->RemoveAura(eSpells::Withering3Percent);
                    me->CastSpell(me, eSpells::Withering5Percent, true);
                });

                AddTimedDelayedOperation(16 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    me->CastSpell(me, eSpells::Withering3Percent, true);
                    me->CastSpell(me, eSpells::Withering5Percent, true);
                });

                AddTimedDelayedOperation(30 * TimeConstants::IN_MILLISECONDS, [this]() -> void { me->DespawnOrUnsummon(); });
            }

            void HealReceived(Unit* /*p_Healer*/, uint32& p_Heal) override
            {
                if ((me->GetHealth() + p_Heal) >= me->GetMaxHealth() && !me->HasAura(eSpells::LivingSpores))
                    me->CastSpell(me, eSpells::LivingSpores, true);
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (attacker != me)
                    damage = 0;
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                me->DespawnOrUnsummon(20 * TimeConstants::IN_MILLISECONDS);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_highmaul_living_mushroomAI(creature);
        }
};

/// Rejuvenating Mushroom - 78868
class npc_highmaul_rejuvenating_mushroom : public CreatureScript
{
    public:
        npc_highmaul_rejuvenating_mushroom() : CreatureScript("npc_highmaul_rejuvenating_mushroom") { }

        enum eSpells
        {
            RejuvenatingMushroomVisual      = 159253,
            RejuvenatingMushroomL1Visual    = 164246,
            Withering3Percent               = 163122,
            Withering5Percent               = 163124,
            RejuvenatingSpores              = 159292
        };

        struct npc_highmaul_rejuvenating_mushroomAI : public ScriptedAI
        {
            npc_highmaul_rejuvenating_mushroomAI(Creature* creature) : ScriptedAI(creature)
            {
                m_Instance = creature->GetInstanceScript();
            }

            InstanceScript* m_Instance;

            void Reset() override
            {
                me->DisableHealthRegen();
                me->SetHealth(me->GetMaxHealth() / 2);
                me->AddUnitState(UnitState::UNIT_STATE_STUNNED);

                me->CastSpell(me, eSpells::RejuvenatingMushroomVisual, true);
                me->CastSpell(me, eSpells::RejuvenatingMushroomL1Visual, true);

                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me, 4);

                AddTimedDelayedOperation(6 * TimeConstants::IN_MILLISECONDS, [this]() -> void { me->CastSpell(me, eSpells::Withering3Percent, true); });

                AddTimedDelayedOperation(11 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    me->RemoveAura(eSpells::Withering3Percent);
                    me->CastSpell(me, eSpells::Withering5Percent, true);
                });

                AddTimedDelayedOperation(16 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    me->CastSpell(me, eSpells::Withering3Percent, true);
                    me->CastSpell(me, eSpells::Withering5Percent, true);
                });

                AddTimedDelayedOperation(30 * TimeConstants::IN_MILLISECONDS, [this]() -> void { me->DespawnOrUnsummon(); });
            }

            void HealReceived(Unit* /*p_Healer*/, uint32& p_Heal) override
            {
                if ((me->GetHealth() + p_Heal) >= me->GetMaxHealth() && !me->HasAura(eSpells::RejuvenatingSpores))
                    me->CastSpell(me, eSpells::RejuvenatingSpores, true);
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (attacker != me)
                    damage = 0;
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                me->DespawnOrUnsummon(20 * TimeConstants::IN_MILLISECONDS);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_highmaul_rejuvenating_mushroomAI(creature);
        }
};

/// BFC9000 - 81403
class npc_highmaul_bfc9000 : public CreatureScript
{
    public:
        npc_highmaul_bfc9000() : CreatureScript("npc_highmaul_bfc9000") { }

        enum eSpells
        {
            Flamethrower    = 163663,
            BFC9000         = 164175
        };

        struct npc_highmaul_bfc9000AI : public ScriptedAI
        {
            npc_highmaul_bfc9000AI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_NPC);
                me->SetFlag(UNIT_NPC_FLAGS, NPCFlags::UNIT_NPC_FLAG_SPELLCLICK);

                me->SetReactState(ReactStates::REACT_PASSIVE);
                me->CastSpell(me, eSpells::BFC9000, true);
            }

            void OnSpellClick(Unit* p_Clicker, bool& /*result*/) override
            {
                if (!me->HasAura(eSpells::BFC9000))
                    return;

                p_Clicker->CastSpell(p_Clicker, eSpells::Flamethrower, true);
                me->RemoveAurasDueToSpell(eSpells::BFC9000);
                me->DespawnOrUnsummon();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_highmaul_bfc9000AI(creature);
        }
};

/// Necrotic Breath - 159220
class spell_highmaul_necrotic_breath : public SpellScriptLoader
{
    public:
        spell_highmaul_necrotic_breath() : SpellScriptLoader("spell_highmaul_necrotic_breath") { }

        class spell_highmaul_necrotic_breath_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_highmaul_necrotic_breath_SpellScript);

            enum eSpell
            {
                TargetRestrict = 20036
            };

            void CorrectTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                SpellTargetRestrictionsEntry const* l_Restriction = sSpellTargetRestrictionsStore.LookupEntry(eSpell::TargetRestrict);
                if (l_Restriction == nullptr)
                    return;

                Unit* caster = GetCaster();
                if (caster == nullptr)
                    return;

                float l_Angle = 2 * float(M_PI) / 360 * l_Restriction->ConeDegrees;
                targets.remove_if([caster, l_Angle](WorldObject* p_Object) -> bool
                {
                    if (p_Object == nullptr)
                        return true;

                    if (!p_Object->isInFront(caster, l_Angle))
                        return true;

                    return false;
                });
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_highmaul_necrotic_breath_SpellScript::CorrectTargets, EFFECT_0, TARGET_UNIT_CONE_ENEMY_24);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_highmaul_necrotic_breath_SpellScript::CorrectTargets, EFFECT_1, TARGET_UNIT_CONE_ENEMY_24);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_highmaul_necrotic_breath_SpellScript();
        }
};

/// Flamethrower (override) - 163663
class spell_highmaul_flamethrower_override : public SpellScriptLoader
{
public:
    spell_highmaul_flamethrower_override() : SpellScriptLoader("spell_highmaul_flamethrower_override") { }

    class spell_highmaul_flamethrower_override_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_highmaul_flamethrower_override_AuraScript);

        enum eSpells
        {
            BFC9000 = 164175
        };

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* target = GetTarget())
                if (InstanceScript* instanceScript = target->GetInstanceScript())
                    if (instanceScript->GetBossState(eHighmaulDatas::BossBrackenspore) == IN_PROGRESS)
                        if (Creature* flameThrower = target->SummonCreature(eHighmaulCreatures::BFC9000, target->GetPosition()))
                            flameThrower->CastSpell(flameThrower, eSpells::BFC9000, true);
        }

        void Register() override
        {
            AfterEffectRemove += AuraEffectRemoveFn(spell_highmaul_flamethrower_override_AuraScript::OnRemove, EFFECT_2, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_highmaul_flamethrower_override_AuraScript();
    }
};

/// Flamethrower (aura) - 163322
class spell_highmaul_flamethrower_aura : public SpellScriptLoader
{
    public:
        spell_highmaul_flamethrower_aura() : SpellScriptLoader("spell_highmaul_flamethrower_aura") { }

        enum eSpells
        {
            FlamethrowerRegen   = 163667,
            PulsingHeat         = 163666
        };

        class spell_highmaul_flamethrower_aura_AuraScript: public AuraScript
        {
            PrepareAuraScript(spell_highmaul_flamethrower_aura_AuraScript);

            void OnTick(AuraEffect const* aurEff)
            {
                if (Unit* target = GetTarget())
                {
                    if (target->GetPower(Powers::POWER_ALTERNATE_POWER) >= 100)
                    {
                        target->CastSpell(target, eSpells::PulsingHeat, true);
                        aurEff->GetBase()->Remove(AuraRemoveMode::AURA_REMOVE_BY_CANCEL);
                    }
                }
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                AuraRemoveMode l_RemoveMode = GetTargetApplication()->GetRemoveMode();
                if (l_RemoveMode == AuraRemoveMode::AURA_REMOVE_BY_CANCEL)
                    return;

                if (Unit* target = GetTarget())
                    target->CastSpell(target, eSpells::FlamethrowerRegen, true);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_highmaul_flamethrower_aura_AuraScript::OnTick, EFFECT_2, SPELL_AURA_OBS_MOD_POWER);
                AfterEffectRemove += AuraEffectRemoveFn(spell_highmaul_flamethrower_aura_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_PACIFY_SILENCE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_flamethrower_aura_AuraScript();
        }

        class spell_highmaul_flamethrower_aura_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_highmaul_flamethrower_aura_SpellScript);

            SpellCastResult CheckPulsingHeat()
            {
                if (Unit* caster = GetCaster())
                {
                    if (caster->HasAura(eSpells::PulsingHeat))
                    {
                        SetCustomCastResultMessage(SpellCustomErrors::SPELL_CUSTOM_ERROR_YOUR_WEAPON_HAS_OVERHEATED);
                        return SpellCastResult::SPELL_FAILED_CUSTOM_ERROR;
                    }
                    else if (caster->HasAura(GetSpellInfo()->Id))
                    {
                        caster->RemoveAura(GetSpellInfo()->Id);
                        return SpellCastResult::SPELL_FAILED_DONT_REPORT;
                    }
                }

                return SpellCastResult::SPELL_CAST_OK;
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_highmaul_flamethrower_aura_SpellScript::CheckPulsingHeat);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_highmaul_flamethrower_aura_SpellScript();
        }
};

/// Flamethrower "Regen" - 163667
class spell_highmaul_flamethrower_regen : public SpellScriptLoader
{
    public:
        spell_highmaul_flamethrower_regen() : SpellScriptLoader("spell_highmaul_flamethrower_regen") { }

        class spell_highmaul_flamethrower_regen_AuraScript: public AuraScript
        {
            PrepareAuraScript(spell_highmaul_flamethrower_regen_AuraScript);

            void OnTick(AuraEffect const* /*aurEff*/)
            {
                if (Unit* target = GetTarget())
                    target->ModifyPower(Powers::POWER_ALTERNATE_POWER, -2);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_highmaul_flamethrower_regen_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_flamethrower_regen_AuraScript();
        }
};

/// Pulsing Heat - 163666
class spell_highmaul_pulsing_heat : public SpellScriptLoader
{
    public:
        spell_highmaul_pulsing_heat() : SpellScriptLoader("spell_highmaul_pulsing_heat") { }

        class spell_highmaul_pulsing_heat_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_pulsing_heat_AuraScript);

            enum eSpell
            {
                FlamethrowerRegen = 163667
            };

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* target = GetTarget())
                    target->CastSpell(target, eSpell::FlamethrowerRegen, true);
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_highmaul_pulsing_heat_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_pulsing_heat_AuraScript();
        }
};

/// Creeping Moss 1 - 163347
class spell_highmaul_creeping_moss : public SpellScriptLoader
{
    public:
        spell_highmaul_creeping_moss() : SpellScriptLoader("spell_highmaul_creeping_moss") { }

        class spell_highmaul_creeping_moss_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_creeping_moss_AuraScript);

            enum eAction
            {
                CreepingMoss = 1
            };

            void OnTick(AuraEffect const* /*aurEff*/)
            {
                if (GetTarget() == nullptr)
                    return;

                if (Creature* target = GetTarget()->ToCreature())
                {
                    if (target->GetAI())
                        target->AI()->DoAction(eAction::CreepingMoss);
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_highmaul_creeping_moss_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_creeping_moss_AuraScript();
        }
};

/// Flamethrower - 163310
class spell_highmaul_flamethrower : public SpellScriptLoader
{
    public:
        spell_highmaul_flamethrower() : SpellScriptLoader("spell_highmaul_flamethrower") { }

        enum eSpells
        {
            CreepingMoss    = 173229,
            BurningInfusion = 165223,
            Flamethrower    = 173281
        };

        class spell_highmaul_flamethrower_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_highmaul_flamethrower_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (Unit* caster = GetCaster())
                {
                    float radius = 10.0f;
                    std::list<AreaTrigger*> l_CreepingMoss;

                    caster->GetAreatriggerListInRange(l_CreepingMoss, radius);

                    if (l_CreepingMoss.empty())
                        return;

                    l_CreepingMoss.remove_if([caster](AreaTrigger* at) -> bool
                    {
                        if (at == nullptr)
                            return true;

                        if (at->GetSpellId() != eSpells::CreepingMoss)
                            return true;

                        if (!caster->isInFront(at))
                            return true;

                        return false;
                    });

                    for (AreaTrigger* l_AT : l_CreepingMoss)
                    {
                        l_AT->SetDuration(1);
                        caster->CastSpell(caster, eSpells::BurningInfusion, true);
                        caster->CastSpell(*l_AT, eSpells::Flamethrower, true);

                        if (Aura* l_Infusion = caster->GetAura(eSpells::BurningInfusion))
                        {
                            if (l_Infusion->GetStackAmount() >= eHighmaulDatas::BurningInfusionNeeded)
                            {
                                if (InstanceScript* l_Instance = caster->GetInstanceScript())
                                    l_Instance->SetData(eHighmaulDatas::BrackensporeAchievement, 1);
                            }
                        }
                    }
                }
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_highmaul_flamethrower_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_highmaul_flamethrower_SpellScript();
        }
};

/// Burning Infusion - 165223
class spell_highmaul_burning_infusion : public SpellScriptLoader
{
    public:
        spell_highmaul_burning_infusion() : SpellScriptLoader("spell_highmaul_burning_infusion") { }

        class spell_highmaul_burning_infusion_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_burning_infusion_AuraScript);

            void OnTick(AuraEffect const* aurEff)
            {
                aurEff->GetBase()->ModStackAmount(-1);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_highmaul_burning_infusion_AuraScript::OnTick, EFFECT_3, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_burning_infusion_AuraScript();
        }
};

/// Energy Regen - 164248
class spell_highmaul_energy_regen : public SpellScriptLoader
{
    public:
        spell_highmaul_energy_regen() : SpellScriptLoader("spell_highmaul_energy_regen") { }

        enum eAction
        {
            InfestingSpores = 2
        };

        class spell_highmaul_energy_regen_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_energy_regen_AuraScript);

            void OnTick(AuraEffect const* /*aurEff*/)
            {
                if (Unit* target = GetTarget())
                {
                    target->EnergizeBySpell(target, GetSpellInfo()->Id, 10, Powers::POWER_RAGE);

                    if (Creature* l_Boss = target->ToCreature())
                    {
                        if (l_Boss->IsAIEnabled && l_Boss->GetPowerPct(Powers::POWER_RAGE) >= 100.0f)
                            l_Boss->AI()->DoAction(eAction::InfestingSpores);
                    }
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_highmaul_energy_regen_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_energy_regen_AuraScript();
        }
};

/// Spore Shot - 173244
class spell_highmaul_spore_shot : public SpellScriptLoader
{
    public:
        spell_highmaul_spore_shot() : SpellScriptLoader("spell_highmaul_spore_shot") { }

        class spell_highmaul_spore_shot_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_highmaul_spore_shot_SpellScript);

            void CorrectTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                targets.remove_if([](WorldObject* p_Object) -> bool
                {
                    if (p_Object == nullptr)
                        return true;

                    /// Should always hit a player if possible
                    if (p_Object->GetTypeId() == TypeID::TYPEID_PLAYER)
                        return false;
                    else if (Creature* l_Creature = p_Object->ToCreature())
                    {
                        if (l_Creature->GetOwner() == nullptr)
                            return true;
                    }

                    return false;
                });
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_highmaul_spore_shot_SpellScript::CorrectTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_highmaul_spore_shot_SpellScript();
        }
};

///  Exploding Fungus (channel) - 163794
class spell_highmaul_exploding_fungus : public SpellScriptLoader
{
public:
    spell_highmaul_exploding_fungus() : SpellScriptLoader("spell_highmaul_exploding_fungus") { }

    class spell_highmaul_exploding_fungus_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_highmaul_exploding_fungus_AuraScript);

        enum eEnums
        {
            ExplosiveShroomA    = 163777,
            ExplosiveShroomB    = 163813,
            ExplosiveShroomC    = 163815,
            ExplosiveShroomD    = 163796,
            ExplosiveShroomDmg  = 163793,

            CastCountABC        = 10,
            CastCountD          = 5
        };

        void OnTick(AuraEffect const* aurEff)
        {
            if (aurEff->GetTickNumber() > 6)
                return;

            if (Unit* caster = GetCaster())
            {
                for (uint8 i = 0; i < CastCountABC; i++)
                {
                    caster->CastSpell(caster, ExplosiveShroomA);
                    caster->CastSpell(caster, ExplosiveShroomB);
                    caster->CastSpell(caster, ExplosiveShroomC);
                }

                for (uint8 i = 0; i < CastCountD; i++)
                {
                    caster->CastSpell(caster, ExplosiveShroomD);
                }
            }
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
            {
                std::list<AreaTrigger*> ATList;
                std::vector<AreaTrigger*> FinalList;
                caster->GetAreaTriggerListWithSpellIDInRange(ATList, ExplosiveShroomA, 500);

                for (auto AT : ATList)
                    FinalList.push_back(AT);

                ATList.clear();
                caster->GetAreaTriggerListWithSpellIDInRange(ATList, ExplosiveShroomB, 500);

                for (auto AT : ATList)
                    FinalList.push_back(AT);

                ATList.clear();
                caster->GetAreaTriggerListWithSpellIDInRange(ATList, ExplosiveShroomC, 500);

                for (auto AT : ATList)
                    FinalList.push_back(AT);

                ATList.clear();
                caster->GetAreaTriggerListWithSpellIDInRange(ATList, ExplosiveShroomD, 500);

                for (auto AT : ATList)
                    FinalList.push_back(AT);

                for (auto AT : FinalList)
                    if (AT)
                    {
                        caster->CastSpell(AT->GetPosition(), ExplosiveShroomDmg, true);
                        AT->RemoveFromWorld();
                    }
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_highmaul_exploding_fungus_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            AfterEffectRemove += AuraEffectRemoveFn(spell_highmaul_exploding_fungus_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_highmaul_exploding_fungus_AuraScript();
    }
};

/// Mind Fungus - 159489
class areatrigger_highmaul_mind_fungus : public AreaTriggerAI
{
public:
    areatrigger_highmaul_mind_fungus(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    enum eSpell
    {
        MindFungus = 163140
    };

    void OnUnitEnter(Unit* unit) override
    {
        if (Unit* caster = at->GetCaster())
            caster->CastSpell(unit, eSpell::MindFungus, true);
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAura(eSpell::MindFungus);
    }
};

/// Spore Shot - 173241
class areatrigger_highmaul_spore_shot : public AreaTriggerAI
{
public:
    areatrigger_highmaul_spore_shot(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger)
    {
        m_Casted = false;
    }

    enum eSpell
    {
        SporeShotDamage = 173244
    };

    bool m_Casted;

    void OnCreate() override
    {
        Unit* caster = at->GetCaster();

        if (caster->IsAIEnabled)
            if (Unit* target = caster->ToCreature()->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 40.f, true))
                at->SetDestination(*target, 5000);
    }

    void OnUpdate(uint32 /*diff*/) override
    {
        if (Unit* caster = at->GetCaster())
        {
            if (at->SelectNearestPlayer(1.0f) != nullptr)
            {
                caster->CastSpell(*at, eSpell::SporeShotDamage, true);
                at->SetDuration(1);
                m_Casted = true;
            }
        }
    }

    void OnRemove() override
    {
        if (Unit* caster = at->GetCaster())
        {
            if (!m_Casted)
                caster->CastSpell(*at, eSpell::SporeShotDamage, true);
        }
    }
};

/// Creeping Moss - 173229
class areatrigger_highmaul_creeping_moss : public AreaTriggerAI
{
public:
    areatrigger_highmaul_creeping_moss(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    enum eSpell
    {
        CreepingMossDamage  = 163590,
        CreepingMossHealing = 165494
    };

    void OnUnitEnter(Unit* unit) override
    {
        if (Unit* caster = at->GetCaster())
        {
            if (unit->IsFriendlyTo(caster))
                unit->CastSpell(unit, eSpell::CreepingMossHealing, true, nullptr, nullptr, caster->GetGUID());
            else
                unit->CastSpell(unit, eSpell::CreepingMossDamage, true, nullptr, nullptr, caster->GetGUID());
        }
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAura(eSpell::CreepingMossDamage);
        unit->RemoveAura(eSpell::CreepingMossHealing);
    }
};

/// Call of the Tides - 160413
class areatrigger_highmaul_call_of_the_tides : public AreaTriggerAI
{
public:
    areatrigger_highmaul_call_of_the_tides(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger)
    { 
        timer = 0;
    }

    enum eSpell
    {
        CallOfTheTidesDamage = 163798
    };

    uint32 timer;
    InstanceScript *instance;

    void OnCreate() override
    {
        Unit* caster = at->GetCaster();
        float orientation = caster->GetOrientation();

        Position pos =
        {
            caster->GetPositionX() + (220.0f * cos(orientation)),
            caster->GetPositionY() + (220.0f * sin(orientation)),
            -10.0f,
            orientation
        };

        at->SetDestination(pos, 5000);
    }

    void OnUpdate(uint32 diff) override
    {
        if (timer <= diff)
        {
            if (instance)
            {
                std::list<Unit*> targetList;

                Trinity::AnyUnitInObjectRangeCheck l_Check(at, 35);
                Trinity::UnitListSearcher<Trinity::AnyUnitInObjectRangeCheck> l_Searcher(at, targetList, l_Check);
                Cell::VisitAllObjects(at, l_Searcher, 35.f);

                targetList.remove_if([this](Unit* unit) -> bool
                {
                    float unitX, unitY, unitZ;

                    unitX = at->GetPositionX() + (unit->GetPositionX() - at->GetPositionX()) * cos(at->GetOrientation()) - (unit->GetPositionY() - at->GetPositionY()) * sin(at->GetOrientation());
                    unitY = at->GetPositionY() + (unit->GetPositionX() - at->GetPositionX()) * sin(at->GetOrientation()) + (unit->GetPositionY() - at->GetPositionY()) * cos(at->GetOrientation());

                    unitZ = unit->GetPositionZ();

                    float minX = at->GetPositionX() - (16.0f);
                    float maxX = at->GetPositionX() + (16.0f);

                    float minY = at->GetPositionY() - (2.0f);
                    float maxY = at->GetPositionY() + (12.0f);

                    float minZ = at->GetPositionZ() - (20.0f);
                    float maxZ = at->GetPositionZ() + (20.0f);

                    if (unitX >= minX && unitX <= maxX &&
                        unitY >= minY && unitY <= maxY &&
                        unitZ >= minZ && unitZ <= maxZ)
                    {
                        return false;
                    }

                    return true;
                });

                for (auto target : targetList)
                    if (Creature* brackenspore = instance->instance->GetCreature(instance->GetGuidData(eHighmaulCreatures::Brackenspore)))
                        target->CastSpell(target, CallOfTheTidesDamage, true, nullptr, nullptr, brackenspore->GetGUID());
            }
                        

            timer = 1 * IN_MILLISECONDS;
        }
        else
            timer -= diff;
    }
};

/// Gorian Strands - 10094
class areatrigger_at_highmaul_infested_waters : public AreaTriggerScript
{
public:
    areatrigger_at_highmaul_infested_waters() : AreaTriggerScript("areatrigger_at_highmaul_infested_waters") { }

    enum eSpell
    {
        InfestedWaters = 164642
    };

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/, bool entered)
    {
        if (entered)
            player->RemoveAura(eSpell::InfestedWaters);
        else
        {
            if (player->GetPositionZ() < 0.0f)
                player->CastSpell(player, eSpell::InfestedWaters, true);
        }

        return false;
    }
};

void AddSC_boss_brackenspore()
{
    /// Boss
    new boss_brackenspore();

    /// NPCs
    new npc_highmaul_mind_fungus();
    new npc_highmaul_spore_shooter();
    new npc_highmaul_fungal_flesh_eater();
    new npc_highmaul_living_mushroom();
    new npc_highmaul_rejuvenating_mushroom();
    new npc_highmaul_bfc9000();

    /// Spells
    new spell_highmaul_necrotic_breath();
    new spell_highmaul_flamethrower_override();
    new spell_highmaul_flamethrower_aura();
    new spell_highmaul_flamethrower_regen();
    new spell_highmaul_pulsing_heat();
    new spell_highmaul_creeping_moss();
    new spell_highmaul_flamethrower();
    new spell_highmaul_burning_infusion();
    new spell_highmaul_energy_regen();
    new spell_highmaul_spore_shot();
    new spell_highmaul_exploding_fungus();

    /// AreaTriggers (Spells)
    RegisterAreaTriggerAI(areatrigger_highmaul_mind_fungus);
    RegisterAreaTriggerAI(areatrigger_highmaul_spore_shot);
    RegisterAreaTriggerAI(areatrigger_highmaul_creeping_moss);
    RegisterAreaTriggerAI(areatrigger_highmaul_call_of_the_tides);

    /// AreaTriggers (Area)
    new areatrigger_at_highmaul_infested_waters();
}
