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

#include "highmaul.h"
#include "Vehicle.h"

Position const g_TrashsSpawnPos = { 3427.1f, 7530.21f, 55.3383f, 0.965533f };
Position const g_VulgorMovePos = { 3449.81f, 7557.01f, 55.304f, 0.8995f };

Position const g_SorcererPos[2] =
{
    { 3452.08f, 7550.25f, 55.304f, 0.8995f },
    { 3441.68f, 7558.45f, 55.304f, 0.8995f }
};

Position const g_SorcererSecondPos[2] =
{
    { 3445.23f, 7575.57f, 55.30f, 0.235625f },
    { 3468.69f, 7557.72f, 55.30f, 1.708251f }
};

Position const g_ArenaStandsPos = { 3507.99f, 7629.20f, 65.43f, 2.466646f };

Position const g_HighmaulSweeperMoves[eHighmaulDatas::HighmaulSweeperCount][eHighmaulDatas::HighmaulSweeperMovesCount] =
{
    /// Right of Mar'gok
    {
        { 3448.05f, 7517.22f, 65.45f, 6.157836f },
        { 3465.95f, 7520.59f, 65.15f, 0.196663f },
        { 3487.64f, 7532.83f, 65.44f, 0.554020f },
        { 3503.33f, 7548.39f, 65.44f, 0.777640f },
        { 3513.44f, 7564.58f, 65.44f, 1.017186f },
        { 3521.71f, 7590.66f, 65.09f, 1.241025f },
        { 3521.19f, 7607.86f, 65.44f, 1.598777f },
        { 3514.75f, 7623.96f, 65.44f, 1.932571f },
        { 3507.99f, 7629.20f, 65.43f, 2.466646f }
    },
    /// Left of Mar'gok
    {
        { 3411.12f, 7546.78f, 65.44f, 1.558138f },
        { 3410.64f, 7564.97f, 65.01f, 1.559507f },
        { 3418.62f, 7590.24f, 65.45f, 1.241420f },
        { 3429.80f, 7608.05f, 65.44f, 1.025436f },
        { 3444.61f, 7621.95f, 65.42f, 0.774108f },
        { 3464.96f, 7634.39f, 65.44f, 0.538489f },
        { 3483.57f, 7637.60f, 65.44f, 0.157571f },
        { 3500.82f, 7634.95f, 65.44f, 6.122672f },
        { 3507.86f, 7629.08f, 65.41f, 5.608234f }
    }
};

Position const g_SweeperJumpPos[eHighmaulDatas::HighmaulSweeperCount][2] =
{
    /// Right of Mar'gok
    {
        { 3476.025f, 7551.327f, 55.2557f, float(M_PI) },
        { 3498.104f, 7575.722f, 55.2557f, float(M_PI) }
    },
    /// Left of Mar'gok
    {
        { 3436.589f, 7581.993f, 55.2557f, float(M_PI) },
        { 3457.199f, 7607.632f, 55.2557f, float(M_PI) }
    }
};

Position const g_DrunkenBileslingerSpawns[2] =
{
    { 3499.293f, 7642.336f, 67.58533f, 4.473204f },
    { 3512.144f, 7574.136f, 63.50087f, 2.765742f }
};

uint32 const g_CrowdEmotes[8] =
{
    Emote::EMOTE_ONESHOT_CHEER,     Emote::EMOTE_ONESHOT_EXCLAMATION,   Emote::EMOTE_ONESHOT_RUDE,  Emote::EMOTE_ONESHOT_ROAR,
    Emote::EMOTE_ONESHOT_CHICKEN,   Emote::EMOTE_ONESHOT_SHOUT,         Emote::EMOTE_ONESHOT_POINT, Emote::EMOTE_ONESHOT_SALUTE
};

Position const g_NewInstancePortalPos = { 3441.737f, 7547.819f, 55.30566f, 0.8291928f };

float const g_InArenaZ = 60.0f;
float const g_ArenaFloor = 55.30f;

void ResetAllPlayersFavor(Creature* source)
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

void GrantFavorToAllPlayers(Creature* source, int32 value, uint32 p_SpellID)
{
    if (source == nullptr)
        return;

    Map::PlayerList const& players = source->GetMap()->GetPlayers();
    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
    {
        if (Player* player = itr->GetSource())
            player->EnergizeBySpell(player, p_SpellID, value, Powers::POWER_ALTERNATE_POWER);
    }
}

/// Kargath Bladefist <Warlord of the Shattered Hand> - 78714
class boss_kargath_bladefist : public CreatureScript
{
    public:
        boss_kargath_bladefist() : CreatureScript("boss_kargath_bladefist") { }

        enum eTalks
        {
            Intro1,
            Intro2,
            Aggro,
            BerserkerRush,
            ChainHurl,
            Impale,
            Berserk,
            FlamePillar,
            Slay,
            Death,

            MargokNearDeath = 2
        };

        enum eActions
        {
            VulgorDied = 2,
            KargathLastTalk,
            InterruptByPillar,
            SpawnIronBombers,
            SpawnDrukenBileslinger,
            EndOfChainHurl,
            FreeRavenous = 0
        };

        enum eMoves
        {
            MoveFrontGate = 1,
            MoveChargeOnPlayer,
            JumpInArena
        };

        enum eCosmeticEvents
        {
            OrientationForFight = 1,
            EventEndOfArenasStands,
            EventEndOfChainHurl
        };

        enum eDatas
        {
            MorphWithWeapon = 54674,
            MorphAmputation = 55201,
            AnimKitImpale   = 5846,
            AnimInterrupt   = 5838
        };

        enum eSpells
        {
            /// Cosmetic
            BladeFistAmputation     = 167593,
            KargathDiesCrowdSound   = 166861,
            KargathChantingSound    = 168278,
            InThePit                = 161423,
            KargathBonusLoot        = 177521,

            /// Fight
            /// Impale
            SpellImpale             = 159113,
            SpellImpaleMorph        = 160728,
            OpenWounds              = 159178,
            /// Blade Dance
            SpellBladeDance         = 159250,
            SpellBladeDanceHit      = 159212,
            SpellBladeDanceCharge   = 159265,
            /// Fire Pillars
            FirePillarTargetSelect  = 159705,
            FirePillarSelector      = 159712,
            TriggerCosmeticAura     = 160519,   ///< Fire aura when breaked by Fire Pillar
            /// Berserker Rush
            BerserkerRushSearcher   = 163180,
            SpellBerserkerRush      = 158986,
            BerserkerRushIncreasing = 159028,   ///< Increase speed and damage done every 2s
            BerserkerRushDamageTick = 159001,   ///< Triggers damaging spell 159002 every 2s
            BerserkerRushDamage     = 159002,
            /// Chain Hurl
            ChainHurlJumpAndKnock   = 160061,
            Chain                   = 159531,
            Obscured                = 160131,
            ChainHurlStunAura       = 159947,

            /// In Mythic difficulty, the raid must perform well to gain favor that is tracked by Roar of the Crowd.
            /// If the raid gains enough favor from Roar of the Crowd, the raid is granted increased damage dealing.
            SpellRoarOfTheCrowd     = 163302,   ///< Enable Alt Power
            CrowdFavorite25         = 163366,   ///< Mod damage PCT done, and mod pet damage PCT done
            CrowdFavorite50         = 163368,   ///< Mod damage PCT done, and mod pet damage PCT done
            CrowdFavorite75         = 163369,   ///< Mod damage PCT done, and mod pet damage PCT done
            CrowdFavorite100        = 163370    ///< Mod damage PCT done, and mod pet damage PCT done
        };

        enum eEvents
        {
            EventImpale = 1,
            EventBladeDance,
            EventOpenGrates,
            EventBerserkerRush,
            EventChainHurl,
            EventBerserker,
            EventSpawnIronBombers,
            EventFreeTiger,
        };

        enum eCreatures
        {
            KargathBladefist    = 78846,    ///< Used for Blade Dance
            ChainHurlVehicle    = 79134,
            FirePillar          = 78757,
            RavenousBloodmaw    = 79296,
            BladefistTarget     = 83738,
            AreaTriggerForCrowd = 79260,
            IronGrunt1          = 84946,
            IronGrunt2          = 79068,
            OgreGrunt1          = 84948,
            OgreGrunt2          = 84958
        };

        struct boss_kargath_bladefistAI : public BossAI
        {
            boss_kargath_bladefistAI(Creature* creature) : BossAI(creature, eHighmaulDatas::BossKargathBladefist), m_Vehicle(creature->GetVehicleKit())
            {
                m_Instance = creature->GetInstanceScript();
                creature->SetReactState(ReactStates::REACT_PASSIVE);

                m_InArena = false;
            }

            EventMap m_Events;
            EventMap m_CosmeticEvents;
            InstanceScript* m_Instance;
            Vehicle* m_Vehicle;

            ObjectGuid m_BerserkerRushTarget;
            ObjectGuid m_ChainHurlGuid;

            bool m_ChainHurl;
            bool m_NearDeath;
            bool m_InEvadeMode;
            bool m_InArena;

            /// Some guids related to fight adds
            std::vector<ObjectGuid> m_BeginningAdds;
            std::vector<ObjectGuid> m_ArenaSweepers;
            std::vector<ObjectGuid> m_IronGruntsInArena;

            void Reset() override
            {
                m_Events.Reset();

                _Reset();

                me->RemoveAura(eSpells::BladeFistAmputation);
                me->RemoveAura(eHighmaulSpells::PlayChogallScene);
                me->RemoveAura(eSpells::FirePillarTargetSelect);
                me->RemoveAura(eHighmaulSpells::Berserker);

                me->SetDisplayId(eDatas::MorphWithWeapon);

                me->SetReactState(ReactStates::REACT_AGGRESSIVE);
                me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN);
                me->ClearUnitState(UnitState::UNIT_STATE_CANNOT_TURN);

                if (m_InArena)
                {
                    me->SetReactState(ReactStates::REACT_AGGRESSIVE);

                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                }

                m_BerserkerRushTarget = ObjectGuid::Empty;
                m_ChainHurlGuid = ObjectGuid::Empty;

                m_ChainHurl     = false;
                m_NearDeath     = false;
                m_InEvadeMode   = false;

                ResetAllPlayersFavor(me);

                summons.DespawnAll();

                if (m_BeginningAdds.empty())
                {
                    AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                    {
                        std::list<Creature*> l_AddList;

                        me->GetCreatureListWithEntryInGridAppend(l_AddList, eCreatures::RavenousBloodmaw, 150.0f);
                        me->GetCreatureListWithEntryInGridAppend(l_AddList, eCreatures::IronGrunt1, 150.0f);
                        me->GetCreatureListWithEntryInGridAppend(l_AddList, eCreatures::IronGrunt2, 150.0f);
                        me->GetCreatureListWithEntryInGridAppend(l_AddList, eCreatures::OgreGrunt1, 150.0f);
                        me->GetCreatureListWithEntryInGridAppend(l_AddList, eCreatures::OgreGrunt2, 150.0f);

                        for (Creature* itr : l_AddList)
                            m_BeginningAdds.push_back(itr->GetGUID());
                    });
                }

                if (m_ArenaSweepers.empty())
                {
                    AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                    {
                        std::list<Creature*> l_SweeperList;
                        me->GetCreatureListWithEntryInGrid(l_SweeperList, eHighmaulCreatures::HighmaulSweeper, 150.0f);

                        for (Creature* itr : l_SweeperList)
                            m_ArenaSweepers.push_back(itr->GetGUID());
                    });
                }

                if (m_IronGruntsInArena.empty())
                {
                    AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                    {
                        std::list<Creature*> l_IronGrunts;
                        me->GetCreatureListWithEntryInGrid(l_IronGrunts, eCreatures::IronGrunt1, 150.0f);

                        for (Creature* itr : l_IronGrunts)
                            m_IronGruntsInArena.push_back(itr->GetGUID());
                    });
                }
            }

            bool CanRespawn() override
            {
                return false;
            }

            void KilledUnit(Unit* p_Who) override
            {
                if (p_Who->IsPlayer())
                    Talk(eTalks::Slay);
            }

            void EnterCombat(Unit* /*attacker*/) override
            {
                me->ClearUnitState(UnitState::UNIT_STATE_ROOT);
                me->ClearUnitState(UnitState::UNIT_STATE_DISTRACTED);
                me->ClearUnitState(UnitState::UNIT_STATE_STUNNED);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);

                _EnterCombat();

                Talk(eTalks::Aggro);
                m_ChainHurl = false;
                me->ClearUnitState(UnitState::UNIT_STATE_CASTING);
                m_BerserkerRushTarget = ObjectGuid::Empty;

                m_Events.ScheduleEvent(eEvents::EventImpale, 35000);
                m_Events.ScheduleEvent(eEvents::EventBladeDance, 3000);

                if (!IsLFR())
                    m_Events.ScheduleEvent(eEvents::EventOpenGrates, 4000);

                m_Events.ScheduleEvent(eEvents::EventBerserkerRush, 48000);
                m_Events.ScheduleEvent(eEvents::EventChainHurl, 91000);
                m_Events.ScheduleEvent(eEvents::EventBerserker, 600000);
                m_Events.ScheduleEvent(eEvents::EventSpawnIronBombers, 60000);

                if (IsMythic())
                    m_Events.ScheduleEvent(eEvents::EventFreeTiger, 110000);

                me->CastSpell(me, eSpells::FirePillarTargetSelect, true);

                if (m_Instance)
                {
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me);

                    if (IsMythic())
                        instance->DoCastSpellOnPlayers(eSpells::SpellRoarOfTheCrowd);
                }
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (m_NearDeath || m_Instance == nullptr)
                    return;

                if (me->HealthBelowPctDamaged(10, damage))
                {
                    m_NearDeath = true;

                    if (Creature* l_Margok = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eHighmaulCreatures::MargokCosmetic)))
                        l_Margok->AI()->Talk(eTalks::MargokNearDeath);
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();

                Talk(eTalks::Death);

                me->CastSpell(me, eSpells::BladeFistAmputation, true);
                me->CastSpell(me, eSpells::KargathDiesCrowdSound, true);
                me->CastSpell(me, eHighmaulSpells::PlayChogallScene, true);

                me->SetDisplayId(eDatas::MorphAmputation);

                /// prevent the "unable to loot" after been killed
                if(me->GetPositionZ() > 58.0f)
                    me->NearTeleportTo(me->GetPositionX(), me->GetPositionY(), 55.3f, me->GetOrientation());

                if (m_Instance)
                {
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::Chain);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::Obscured);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::OpenWounds);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::SpellRoarOfTheCrowd);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::CrowdFavorite25);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::CrowdFavorite50);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::CrowdFavorite75);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::CrowdFavorite100);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::InThePit);

                    /*if (sObjectMgr->IsDisabledEncounter(m_Instance->GetEncounterIDForBoss(me), GetDifficulty()))
                        me->SetLootRecipient(nullptr);
                    else*/
                        instance->DoCastSpellOnPlayers(eSpells::KargathBonusLoot, me);

                    ResetAllPlayersFavor(me);

                    std::list<Creature*> l_GorianList;
                    me->GetCreatureListWithEntryInGrid(l_GorianList, eHighmaulCreatures::GorianEnforcer, 300.0f);

                    for (Creature* l_Gorian : l_GorianList)
                        l_Gorian->SendPlaySpellVisualKit(52881, 4, 3600000);

                    for (uint8 l_I = eHighmaulDatas::RaidGrate001; l_I < eHighmaulDatas::MaxRaidGrates; ++l_I)
                    {
                        if (GameObject* l_RaidGrate = ObjectAccessor::GetGameObject(*me, m_Instance->GetGuidData(eHighmaulGameobjects::RaidGrate1 + l_I)))
                            l_RaidGrate->SetGoState(GOState::GO_STATE_READY);
                    }

                    me->SummonGameObject(eHighmaulGameobjects::InstancePortal2, g_NewInstancePortalPos, QuaternionData(0.0f, 0.0f, 0.0f, 1.0f), -1);
                }
            }

            void JustSummoned(Creature* p_Summon) override
            {
                if (p_Summon->GetEntry() == eCreatures::BladefistTarget)
                {
                    me->Kill(p_Summon);
                    p_Summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                }

                summons.Summon(p_Summon);
            }

            void DoAction(int32 const action) override
            {
                switch (action)
                {
                    case eActions::VulgorDied:
                    {
                        me->GetMotionMaster()->MoveJump(eHighmaulLocs::ArenaCenter, 30.0f, 20.0f, eMoves::JumpInArena);
                        m_InArena = true;
                        Talk(eTalks::Intro1);
                        break;
                    }
                    case eActions::KargathLastTalk:
                    {
                        Talk(eTalks::Intro2);
                        break;
                    }
                    case eActions::InterruptByPillar:
                    {
                        if (m_InEvadeMode)
                            break;

                        Talk(eTalks::FlamePillar);

                        me->CastSpell(me, eSpells::TriggerCosmeticAura, true);

                        if (Player* target = ObjectAccessor::GetPlayer(*me, m_BerserkerRushTarget))
                            EndBerserkerRush(target, false);

                        me->SetReactState(ReactStates::REACT_PASSIVE);
                        me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN);
                        me->AddUnitState(UnitState::UNIT_STATE_CANNOT_TURN);

                        AddTimedDelayedOperation(100, [this]() -> void
                        {
                            if (Creature* l_Pillar = me->FindNearestCreature(eCreatures::FirePillar, 10.0f))
                            {
                                me->SetFacingTo(me->GetAngle(l_Pillar));
                                l_Pillar->AI()->DoAction(1);
                            }

                            /// Breaks Pillar visual
                            me->SetControlled(true, UnitState::UNIT_STATE_ROOT);
                        });

                        AddTimedDelayedOperation(200, [this]() -> void
                        {
                            me->PlayOneShotAnimKitId(eDatas::AnimInterrupt);
                        });

                        if (m_Instance != nullptr)
                            m_Instance->SetData(eHighmaulDatas::KargathAchievement, 1);

                        AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                        {
                            if (Unit* l_NewTarget = me->getThreatManager().getHostilTarget())
                                AttackStart(l_NewTarget);
                            me->ClearUnitState(UNIT_STATE_STUNNED);
                            me->ClearUnitState(UNIT_STATE_CONFUSED);
                        });

                        break;
                    }
                    case eActions::SpawnIronBombers:
                    {
                        SpawnIronBombers(5);
                        break;
                    }
                    case eActions::SpawnDrukenBileslinger:
                    {
                        SpawnDrunkenBileslingers();
                        break;
                    }
                    case eActions::EndOfChainHurl:
                    {
                        if (me->HasUnitState(UnitState::UNIT_STATE_ROOT))
                            me->SetControlled(false, UnitState::UNIT_STATE_ROOT);

                        if (Unit* l_NewTarget = me->getThreatManager().getHostilTarget())
                            AttackStart(l_NewTarget);

                        m_ChainHurl = false;
                        break;
                    }
                    default:
                        break;
                }
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                m_InEvadeMode = true;

                me->RemoveAllAuras();
                me->CastSpell(me, eSpells::TriggerCosmeticAura, true);

                me->InterruptNonMeleeSpells(true);

                /// Just in case, to prevent the fail Return to Home
                me->ClearUnitState(UnitState::UNIT_STATE_ROOT);
                me->ClearUnitState(UnitState::UNIT_STATE_DISTRACTED);
                me->ClearUnitState(UnitState::UNIT_STATE_STUNNED);

                me->SetReactState(ReactStates::REACT_AGGRESSIVE);

                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);

                DeactivatePillars();
                ResetAdds();

                if (Unit* l_ChainHurl = ObjectAccessor::GetUnit(*me, m_ChainHurlGuid))
                {
                    if (Vehicle* l_Vehicle = l_ChainHurl->GetVehicleKit())
                        l_Vehicle->RemoveAllPassengers();
                }

                CreatureAI::EnterEvadeMode();

                if (m_Instance != nullptr)
                {
                    for (uint8 l_I = eHighmaulDatas::RaidGrate001; l_I < eHighmaulDatas::MaxRaidGrates; ++l_I)
                    {
                        if (GameObject* l_RaidGrate = ObjectAccessor::GetGameObject(*me, m_Instance->GetGuidData(eHighmaulGameobjects::RaidGrate1 + l_I)))
                            l_RaidGrate->SetGoState(GOState::GO_STATE_READY);
                    }

                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::Chain);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::Obscured);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::OpenWounds);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::SpellRoarOfTheCrowd);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::CrowdFavorite25);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::CrowdFavorite50);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::CrowdFavorite75);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::CrowdFavorite100);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::InThePit);

                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                    m_Instance->SetBossState(eHighmaulDatas::BossKargathBladefist, EncounterState::FAIL);
                }

                m_InEvadeMode = false;
            }

            void JustReachedHome() override
            {
                Reset();
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type != MovementGeneratorType::POINT_MOTION_TYPE)
                    return;

                switch (id)
                {
                    case eMoves::MoveFrontGate:
                        me->SetFacingTo(0.855371f);
                        me->SetReactState(ReactStates::REACT_AGGRESSIVE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                        me->SetWalk(false);
                        m_CosmeticEvents.ScheduleEvent(eCosmeticEvents::OrientationForFight, 500);
                        me->CastSpell(me, eSpells::KargathChantingSound, true);
                        break;
                    case eMoves::JumpInArena:
                        m_CosmeticEvents.ScheduleEvent(eCosmeticEvents::OrientationForFight, 500);
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
                    case eSpells::SpellImpale:
                    {
                        if (m_Vehicle == nullptr)
                            break;

                        target->EnterVehicle(me, 0);

                        /// @WORKAROUND - Clear ON VEHICLE state to allow healing (Invalid target errors)
                        /// Current rule for applying this state is questionable (seatFlags & VEHICLE_SEAT_FLAG_ALLOW_TURNING ???)
                        //target->ClearUnitState(UnitState::UNIT_STATE_ONVEHICLE);

                        /// This should prevent Kargath to send player under map after Impale
                        if (Creature* l_ATForCrowd = me->FindNearestCreature(eCreatures::AreaTriggerForCrowd, 100.0f))
                            me->SetFacingTo(me->GetAngle(l_ATForCrowd));
                        break;
                    }
                    case eSpells::SpellBladeDanceHit:
                    {
                        Position pos = target->GetPosition();

                        if (Creature* l_Trigger = me->SummonCreature(eCreatures::KargathBladefist, pos, TempSummonType::TEMPSUMMON_TIMED_DESPAWN, 5000))
                            me->CastSpell(l_Trigger, eSpells::SpellBladeDanceCharge, true);

                        break;
                    }
                    case eSpells::BerserkerRushSearcher:
                    {
                        me->CastSpell(target, eSpells::SpellBerserkerRush, false);
                        break;
                    }
                    case eSpells::SpellBerserkerRush:
                    {
                        m_BerserkerRushTarget = target->GetGUID();

                        me->getThreatManager().addThreat(target, std::numeric_limits<float>::max());
                        me->TauntApply(target);
                        me->SetReactState(ReactStates::REACT_PASSIVE);

                        /// Remove casting state, it prevent the moves
                        me->ClearUnitState(UnitState::UNIT_STATE_CASTING);

                        me->GetMotionMaster()->Clear(true);
                        me->GetMotionMaster()->MoveChase(target);

                        me->CastSpell(me, eSpells::BerserkerRushIncreasing, true);
                        me->CastSpell(me, eSpells::BerserkerRushDamageTick, true);
                        break;
                    }
                    case eSpells::ChainHurlStunAura:
                    {
                        DoModifyThreatPercent(target, -99);
                        break;
                    }
                    case eSpells::BerserkerRushDamage:
                    {
                        if (target->IsAlive() || !IsMythic() || !target->IsPlayer())
                            break;

                        GrantFavorToAllPlayers(me, -25, eSpells::BerserkerRushDamage);
                        break;
                    }
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 const diff) override
            {
                UpdateOperations(diff);

                m_CosmeticEvents.Update(diff);

                switch (m_CosmeticEvents.ExecuteEvent())
                {
                    case eCosmeticEvents::OrientationForFight:
                    {
                        me->SetFacingTo(0.90f);
                        me->SetOrientation(0.90f);
                        me->SetHomePosition(me->GetPosition());
                        break;
                    }
                    case eCosmeticEvents::EventEndOfArenasStands:
                    {
                        for (ObjectGuid guid : m_ArenaSweepers)
                        {
                            if (Creature* l_Sweeper = ObjectAccessor::GetCreature(*me, guid))
                            {
                                if (l_Sweeper->IsAIEnabled)
                                    l_Sweeper->AI()->DoAction(0);
                            }
                        }

                        break;
                    }
                    case eCosmeticEvents::EventEndOfChainHurl:
                    {
                        DoAction(eActions::EndOfChainHurl);
                        break;
                    }
                    default:
                        break;
                }

                /// Update Berserker Rush move
                if (me->HasAura(eSpells::BerserkerRushIncreasing) && !m_BerserkerRushTarget.IsEmpty())
                {
                    if (Player* target = ObjectAccessor::GetPlayer(*me, m_BerserkerRushTarget))
                    {
                        if (!target->IsAlive())
                        {
                            EndBerserkerRush(target);
                            return;
                        }
                    }
                }

                if (!UpdateVictim())
                    return;

                m_Events.Update(diff);

                if (m_ChainHurl || me->HasUnitState(UnitState::UNIT_STATE_CASTING) || !m_BerserkerRushTarget.IsEmpty())
                    return;

                switch (m_Events.ExecuteEvent())
                {
                    case eEvents::EventImpale:
                    {
                        Talk(eTalks::Impale);

                        if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO))
                            me->CastSpell(target, eSpells::SpellImpale, false);

                        me->CastSpell(me, eSpells::SpellImpaleMorph, true);
                        me->PlayOneShotAnimKitId(eDatas::AnimKitImpale);
                        m_Events.ScheduleEvent(eEvents::EventImpale, 43500);
                        break;
                    }
                    case eEvents::EventBladeDance:
                    {
                        me->CastSpell(me, eSpells::SpellBladeDance, true);
                        m_Events.ScheduleEvent(eEvents::EventBladeDance, 20000);
                        break;
                    }
                    case eEvents::EventOpenGrates:
                    {
                        if (m_Instance == nullptr)
                            break;

                        for (uint8 l_I = eHighmaulDatas::RaidGrate001; l_I < eHighmaulDatas::MaxRaidGrates; ++l_I)
                        {
                            if (GameObject* l_RaidGrate = ObjectAccessor::GetGameObject(*me, m_Instance->GetGuidData(eHighmaulGameobjects::RaidGrate1 + l_I)))
                                l_RaidGrate->SetGoState(GOState::GO_STATE_ACTIVE);
                        }

                        break;
                    }
                    case eEvents::EventBerserkerRush:
                    {
                        me->CastSpell(me, eSpells::BerserkerRushSearcher, true);
                        Talk(eTalks::BerserkerRush);
                        m_Events.ScheduleEvent(eEvents::EventBerserkerRush, 45000);
                        break;
                    }
                    case eEvents::EventChainHurl:
                    {
                        /// Respawn Iron Grunts for Arenas Stands fighting
                        for (ObjectGuid guid : m_IronGruntsInArena)
                        {
                            if (Creature* l_IronGrunt = ObjectAccessor::GetCreature(*me, guid))
                            {
                                if (l_IronGrunt->isDead())
                                {
                                    l_IronGrunt->DespawnOrUnsummon();
                                    l_IronGrunt->Respawn();

                                    ObjectGuid guid = l_IronGrunt->GetGUID();
                                    AddTimedDelayedOperation(50, [this, guid]() -> void
                                    {
                                        if (Creature* l_Creature = ObjectAccessor::GetCreature(*me, guid))
                                            l_Creature->GetMotionMaster()->MoveTargetedHome();
                                    });
                                }
                            }
                        }

                        m_ChainHurl = true;
                        Talk(eTalks::ChainHurl);

                        me->StopMoving();
                        me->GetMotionMaster()->Clear();
                        me->CastSpell(eHighmaulLocs::ArenaCenter, eSpells::ChainHurlJumpAndKnock, true);

                        m_Events.ScheduleEvent(eEvents::EventChainHurl, 106000);
                        m_CosmeticEvents.ScheduleEvent(eCosmeticEvents::EventEndOfArenasStands, 45000);

                        Position pos = me->GetPosition();

                        if (Creature* l_ChainHurl = me->SummonCreature(eCreatures::ChainHurlVehicle, pos, TempSummonType::TEMPSUMMON_TIMED_DESPAWN, 18000))
                        {
                            m_ChainHurlGuid = l_ChainHurl->GetGUID();
                            l_ChainHurl->EnterVehicle(me, 1);
                        }

                        m_Events.DelayEvent(eEvents::EventImpale, 18000);
                        m_Events.DelayEvent(eEvents::EventBerserkerRush, 18000);
                        m_CosmeticEvents.ScheduleEvent(eCosmeticEvents::EventEndOfChainHurl, 14000);
                        break;
                    }
                    case eEvents::EventBerserker:
                    {
                        me->CastSpell(me, eHighmaulSpells::Berserker, true);
                        Talk(eTalks::Berserk);
                        break;
                    }
                    case eEvents::EventSpawnIronBombers:
                    {
                        SpawnIronBombers(5);
                        break;
                    }
                    case eEvents::EventFreeTiger:
                    {
                        if (!IsMythic())
                            break;

                        std::list<Creature*> l_TigerList;
                        me->GetCreatureListWithEntryInGrid(l_TigerList, eCreatures::RavenousBloodmaw, 300.0f);

                        if (l_TigerList.empty())
                            break;

                        l_TigerList.remove_if([](Creature* creature) -> bool
                        {
                            return !creature || !creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        });

                        if (l_TigerList.empty())
                            break;

                        Trinity::Containers::RandomResize(l_TigerList, 1);

                        for (Creature* l_Ravenous : l_TigerList)
                        {
                            if (l_Ravenous->IsAIEnabled)
                                l_Ravenous->AI()->DoAction(eActions::FreeRavenous);

                            for (uint8 l_I = eHighmaulDatas::RaidGrate001; l_I < eHighmaulDatas::MaxRaidGrates; ++l_I)
                            {
                                if (GameObject* l_RaidGrate = me->FindNearestGameObject(eHighmaulGameobjects::RaidGrate1 + l_I, 5.0f))
                                    l_RaidGrate->SetGoState(GOState::GO_STATE_READY);
                            }
                        }

                        m_Events.ScheduleEvent(eEvents::EventFreeTiger, 110000);
                        break;
                    }
                    default:
                        break;
                }

                //EnterEvadeIfOutOfCombatArea(diff);
                DoMeleeAttackIfReady();
            }

            void PassengerBoarded(Unit* p_Passenger, int8 /*p_SeatID*/, bool p_Apply) override
            {
                if (p_Apply || p_Passenger == nullptr || p_Passenger->GetEntry() != eCreatures::BladefistTarget)
                    return;

                me->Kill(p_Passenger);
            }

            void DeactivatePillars()
            {
                std::list<Creature*> l_Pillars;
                me->GetCreatureListWithEntryInGrid(l_Pillars, eCreatures::FirePillar, 300.0f);

                for (Creature* l_Pillar : l_Pillars)
                {
                    if (l_Pillar->IsAIEnabled)
                    {
                        l_Pillar->AI()->DoAction(0);
                        l_Pillar->AI()->Reset();
                    }
                }
            }

            void SpawnIronBombers(uint8 p_Count)
            {
                if (!me->IsInCombat())
                    return;

                std::list<Creature*> l_SpawnerList;
                me->GetCreatureListWithEntryInGrid(l_SpawnerList, eHighmaulCreatures::IronBomberSpawner, 300.0f);

                if (l_SpawnerList.empty())
                    return;

                l_SpawnerList.remove_if([](Creature* creature) -> bool
                {
                    /// Don't spawn two Iron Bombers at the same position
                    if (Creature* l_IronBomber = creature->FindNearestCreature(eHighmaulCreatures::IronBomber, 3.0f))
                    {
                        if (l_IronBomber->IsAlive())
                            return true;
                        else
                            l_IronBomber->DespawnOrUnsummon();
                    }

                    if (creature->GetOwner() != nullptr)
                        return true;

                    return false;
                });

                if (l_SpawnerList.size() > p_Count)
                    Trinity::Containers::RandomResize(l_SpawnerList, p_Count);

                for (Creature* l_Spawner : l_SpawnerList)
                    me->SummonCreature(eHighmaulCreatures::IronBomber, l_Spawner->GetPosition());
            }

            void SpawnDrunkenBileslingers()
            {
                if (!me->IsInCombat())
                    return;

                std::list<Creature*> l_DrunkenList;
                me->GetCreatureListWithEntryInGrid(l_DrunkenList, eHighmaulCreatures::DrunkenBileslinger, 300.0f);

                if (l_DrunkenList.empty())
                {
                    me->SummonCreature(eHighmaulCreatures::DrunkenBileslinger, g_DrunkenBileslingerSpawns[0]);
                    me->SummonCreature(eHighmaulCreatures::DrunkenBileslinger, g_DrunkenBileslingerSpawns[1]);
                }
                else
                {
                    for (Creature* l_Drunken : l_DrunkenList)
                        l_Drunken->DespawnOrUnsummon();

                    me->SummonCreature(eHighmaulCreatures::DrunkenBileslinger, g_DrunkenBileslingerSpawns[0]);
                    me->SummonCreature(eHighmaulCreatures::DrunkenBileslinger, g_DrunkenBileslingerSpawns[1]);
                }
            }

            void ResetAdds()
            {
                for (ObjectGuid guid : m_BeginningAdds)
                {
                    if (Creature* itr = ObjectAccessor::GetCreature(*me, guid))
                    {
                        if (itr->isDead())
                        {
                            itr->DespawnOrUnsummon();
                            itr->Respawn();

                            ObjectGuid guid = itr->GetGUID();
                            AddTimedDelayedOperation(100, [this, guid]() -> void
                            {
                                if (Creature* l_Creature = ObjectAccessor::GetCreature(*me, guid))
                                    l_Creature->GetMotionMaster()->MoveTargetedHome();
                            });
                        }
                        else if (itr->IsAIEnabled)
                            itr->AI()->EnterEvadeMode();
                    }
                }
            }

            void EndBerserkerRush(Unit* target, bool p_NewTarget = true)
            {
                if (target == nullptr)
                    return;

                m_BerserkerRushTarget = ObjectGuid::Empty;

                me->RemoveAura(eSpells::BerserkerRushDamageTick);
                me->InterruptNonMeleeSpells(true, eSpells::SpellBerserkerRush);

                me->SetReactState(ReactStates::REACT_AGGRESSIVE);

                me->getThreatManager().modifyThreatPercent(target, -100);
                me->getThreatManager().setDirty(true);

                me->GetMotionMaster()->Clear();

                if (p_NewTarget)
                {
                    if (Unit* l_NewTarget = me->getThreatManager().getHostilTarget())
                        AttackStart(l_NewTarget);
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_kargath_bladefistAI(creature);
        }
};

/// Vul'gor <The Shadow of Highmaul> - 80048
class npc_highmaul_vulgor : public CreatureScript
{
    public:
        npc_highmaul_vulgor() : CreatureScript("npc_highmaul_vulgor") { }

        enum eActions
        {
            StartIntro,
            ContinueIntro,
            VulgorDied
        };

        enum eMove
        {
            MoveInArena
        };

        enum eTalks
        {
            Aggro,
            Slay,
            Spell
        };

        enum eSpells
        {
            SpellCleave         = 161712,
            SpellEarthBreaker   = 162271,
            EarthBreakerSearch  = 163933,

            VulgorDieCrowdSound = 166860
        };

        enum eEvents
        {
            EventCleave = 1,
            EventEarthBreaker
        };

        struct npc_highmaul_vulgorAI : public ScriptedAI
        {
            npc_highmaul_vulgorAI(Creature* creature) : ScriptedAI(creature), m_Summons(creature)
            {
                m_Instance          = creature->GetInstanceScript();
                m_HealthPct         = 30;
                m_IntroContinued    = false;
            }

            InstanceScript* m_Instance;
            int32 m_HealthPct;
            bool m_IntroContinued;

            ObjectGuid m_SorcererGuids[2];

            EventMap m_Events;
            SummonList m_Summons;

            void Reset() override
            {
                if (Creature* l_FirstSorcerer = ObjectAccessor::GetCreature(*me, m_SorcererGuids[0]))
                {
                    l_FirstSorcerer->Respawn();
                    l_FirstSorcerer->GetMotionMaster()->Clear();
                    l_FirstSorcerer->GetMotionMaster()->MoveTargetedHome();
                }

                if (Creature* l_SecondSorcerer = ObjectAccessor::GetCreature(*me, m_SorcererGuids[1]))
                {
                    l_SecondSorcerer->Respawn();
                    l_SecondSorcerer->GetMotionMaster()->Clear();
                    l_SecondSorcerer->GetMotionMaster()->MoveTargetedHome();
                }

                m_Events.Reset();

                m_Summons.DespawnAll();

                me->SetReactState(ReactStates::REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NON_ATTACKABLE);
                me->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);
            }

            void EnterCombat(Unit* /*attacker*/) override
            {
                Talk(eTalks::Aggro);

                m_Events.ScheduleEvent(eEvents::EventCleave, 5000);
                m_Events.ScheduleEvent(eEvents::EventEarthBreaker, 8000);
            }

            void KilledUnit(Unit* killed) override
            {
                if (killed->GetTypeId() == TypeID::TYPEID_PLAYER)
                    Talk(eTalks::Slay);
            }

            void JustSummoned(Creature* p_Summon) override
            {
                m_Summons.Summon(p_Summon);
            }

            void SpellHitTarget(Unit* target, SpellInfo const* spellInfo) override
            {
                if (target == nullptr)
                    return;

                if (spellInfo->Id == eSpells::EarthBreakerSearch)
                {
                    me->SetFacingTo(me->GetAngle(target));
                    me->CastSpell(target, eSpells::SpellEarthBreaker, false);
                }
            }

            void DoAction(int32 const action) override
            {
                if (action == eActions::StartIntro)
                {
                    std::list<Creature*> l_BladespireSorcerers;
                    me->GetCreatureListWithEntryInGrid(l_BladespireSorcerers, eHighmaulCreatures::BladespireSorcerer, 15.0f);

                    if (l_BladespireSorcerers.size() == 2)
                    {
                        uint8 l_Count = 0;
                        for (Creature* l_Sorcerer : l_BladespireSorcerers)
                        {
                            l_Sorcerer->SetWalk(false);
                            l_Sorcerer->GetMotionMaster()->MovePoint(eMove::MoveInArena, g_SorcererPos[l_Count]);
                            m_SorcererGuids[l_Count] = l_Sorcerer->GetGUID();

                            ++l_Count;
                        }
                    }

                    me->SetWalk(false);
                    me->GetMotionMaster()->MovePoint(eMove::MoveInArena, g_VulgorMovePos);
                }
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (m_Instance == nullptr || type != MovementGeneratorType::POINT_MOTION_TYPE)
                    return;

                switch (id)
                {
                    case eMove::MoveInArena:
                    {
                        me->SetWalk(false);
                        me->SetHomePosition(g_VulgorMovePos);
                        me->SetReactState(ReactStates::REACT_AGGRESSIVE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NON_ATTACKABLE);

                        //me->HandleEmoteCommand(Emote::EMOTE_ONESHOT_BATTLEROAR);

                        AddTimedDelayedOperation(4 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                        {
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, Emote::EMOTE_STATE_READY1H);
                        });

                        break;
                    }
                    default:
                        break;
                }
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (m_IntroContinued || m_Instance == nullptr)
                    return;

                if (me->HealthBelowPctDamaged(m_HealthPct, damage))
                {
                    m_IntroContinued = true;

                    if (Creature* l_Jhorn = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eHighmaulCreatures::JhornTheMad)))
                        l_Jhorn->AI()->DoAction(eActions::ContinueIntro);

                    if (Creature* l_Thoktar = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eHighmaulCreatures::ThoktarIronskull)))
                        l_Thoktar->AI()->DoAction(eActions::ContinueIntro);

                    if (m_Instance != nullptr)
                    {
                        if (GameObject* l_InnerGate = ObjectAccessor::GetGameObject(*me, m_Instance->GetGuidData(eHighmaulGameobjects::GateArenaInner)))
                            l_InnerGate->SetGoState(GOState::GO_STATE_ACTIVE);
                    }

                    AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                    {
                        /// Spawn new trash mobs
                        for (uint8 l_I = 0; l_I < 2; ++l_I)
                        {
                            if (Creature* l_Sorcerer = me->SummonCreature(eHighmaulCreatures::BladespireSorcerer, g_TrashsSpawnPos))
                                l_Sorcerer->GetMotionMaster()->MovePoint(eMove::MoveInArena, g_SorcererSecondPos[l_I]);
                        }
                    });

                    AddTimedDelayedOperation(5 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                    {
                        if (m_Instance != nullptr)
                        {
                            if (GameObject* l_InnerGate = ObjectAccessor::GetGameObject(*me, m_Instance->GetGuidData(eHighmaulGameobjects::GateArenaInner)))
                                l_InnerGate->SetGoState(GOState::GO_STATE_READY);
                        }
                    });
                }
            }

            void JustReachedHome() override
            {
                me->GetMotionMaster()->MovePoint(0, g_VulgorMovePos);

                m_IntroContinued = false;
            }

            void JustDied(Unit* /*killer*/) override
            {
                m_Summons.DespawnAll();

                if (m_Instance != nullptr)
                {
                    if (Creature* l_Jhorn = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eHighmaulCreatures::JhornTheMad)))
                        l_Jhorn->AI()->DoAction(eActions::VulgorDied);

                    if (Creature* l_Thoktar = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eHighmaulCreatures::ThoktarIronskull)))
                        l_Thoktar->AI()->DoAction(eActions::VulgorDied);

                    Creature* l_MargokCosmetic = m_Instance->GetCreature(eHighmaulCreatures::MargokCosmetic);

                    if (!l_MargokCosmetic)
                        l_MargokCosmetic = me->SummonCreature(eHighmaulCreatures::MargokCosmetic, 3397.446289f, 7493.029297f, 73.664780f, 0.928363f);

                    if (l_MargokCosmetic)
                        l_MargokCosmetic->AI()->DoAction(eActions::VulgorDied);
                }

                me->CastSpell(me, eSpells::VulgorDieCrowdSound, true);
            }

            void UpdateAI(uint32 const diff) override
            {
                UpdateOperations(diff);

                if (!UpdateVictim())
                    return;

                m_Events.Update(diff);

                if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                    return;

                switch (m_Events.ExecuteEvent())
                {
                    case eEvents::EventCleave:
                        if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO))
                            me->CastSpell(target, eSpells::SpellCleave, true);
                        m_Events.ScheduleEvent(eEvents::EventCleave, 19000);
                        break;
                    case eEvents::EventEarthBreaker:
                        me->CastSpell(me, eSpells::EarthBreakerSearch, true);
                        m_Events.ScheduleEvent(eEvents::EventEarthBreaker, 15000);
                        break;
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_highmaul_vulgorAI(creature);
        }
};

/// Bladespire Sorcerer - 80071
class npc_highmaul_bladespire_sorcerer : public CreatureScript
{
    public:
        npc_highmaul_bladespire_sorcerer() : CreatureScript("npc_highmaul_bladespire_sorcerer") { }

        enum eMove
        {
            MoveInArena
        };

        enum eSpells
        {
            SpellMoltenBombSearcher = 161630,
            SpellMoltenBomb         = 161631,
            SpellFlameBoltSearcher  = 162369,
            SpellFlameBolt          = 162351,
            SpellSearingArmor       = 162231,
            SpellSearingArmorAura   = 177705
        };

        enum eEvents
        {
            EventMoltenBomb = 1,
            EventFlameBolt,
            EventSearingArmor
        };

        struct npc_highmaul_bladespire_sorcererAI : public ScriptedAI
        {
            npc_highmaul_bladespire_sorcererAI(Creature* creature) : ScriptedAI(creature)
            {
                creature->SetReactState(ReactStates::REACT_PASSIVE);
                creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
            }

            EventMap m_Events;
            Position m_Position;

            void Reset() override
            {
                m_Events.Reset();

                me->RemoveAllAreaTriggers();
                me->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type != MovementGeneratorType::POINT_MOTION_TYPE)
                    return;

                switch (id)
                {
                    case eMove::MoveInArena:
                    {
                        me->SetWalk(false);
                        me->SetReactState(ReactStates::REACT_AGGRESSIVE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, Emote::EMOTE_STATE_READY2H);
                        m_Position = me->GetPosition();
                        break;
                    }
                    default:
                        break;
                }
            }

            void EnterCombat(Unit* /*attacker*/) override
            {
                m_Events.ScheduleEvent(eEvents::EventMoltenBomb, 5000);
                m_Events.ScheduleEvent(eEvents::EventFlameBolt, 2000);
                m_Events.ScheduleEvent(eEvents::EventSearingArmor, 8000);
            }

            void SpellHitTarget(Unit* target, SpellInfo const* spellInfo) override
            {
                if (target == nullptr)
                    return;

                switch (spellInfo->Id)
                {
                    case eSpells::SpellMoltenBombSearcher:
                        me->CastSpell(target, eSpells::SpellMoltenBomb, true);
                        break;
                    case eSpells::SpellFlameBoltSearcher:
                        me->CastSpell(target, eSpells::SpellFlameBolt, false);
                        break;
                    case eSpells::SpellSearingArmor:
                        me->ClearUnitState(UnitState::UNIT_STATE_CASTING);
                        me->CastSpell(target, eSpells::SpellSearingArmorAura, true);
                        break;
                    default:
                        break;
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                me->RemoveAllAreaTriggers();
            }

            void JustReachedHome() override
            {
                me->GetMotionMaster()->MovePoint(0, m_Position);
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
                    case eEvents::EventMoltenBomb:
                        me->CastSpell(me, eSpells::SpellMoltenBombSearcher, false);
                        m_Events.ScheduleEvent(eEvents::EventMoltenBomb, 15000);
                        break;
                    case eEvents::EventFlameBolt:
                        me->CastSpell(me, eSpells::SpellFlameBoltSearcher, true);
                        m_Events.ScheduleEvent(eEvents::EventFlameBolt, 10000);
                        break;
                    case eEvents::EventSearingArmor:
                        me->CastSpell(me, eSpells::SpellSearingArmor, true);
                        me->ClearUnitState(UnitState::UNIT_STATE_CASTING);
                        break;
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_highmaul_bladespire_sorcererAI(creature);
        }
};

/// Smoldering Stoneguard - 80051
class npc_highmaul_somldering_stoneguard : public CreatureScript
{
    public:
        npc_highmaul_somldering_stoneguard() : CreatureScript("npc_highmaul_somldering_stoneguard") { }

        enum eSpell
        {
            SpellCleave = 161703
        };

        enum eEvent
        {
            EventCleave = 1
        };

        struct npc_highmaul_somldering_stoneguardAI : public ScriptedAI
        {
            npc_highmaul_somldering_stoneguardAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap m_Events;

            void Reset() override
            {
                m_Events.Reset();
            }

            void EnterCombat(Unit* /*attacker*/) override
            {
                m_Events.ScheduleEvent(eEvent::EventCleave, 2000);
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
                    case eEvent::EventCleave:
                        if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO))
                            me->CastSpell(target, eSpell::SpellCleave, false);
                        m_Events.ScheduleEvent(eEvent::EventCleave, 10000);
                        break;
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_highmaul_somldering_stoneguardAI(creature);
        }
};

/// Fire Pillar - 78757
class npc_highmaul_fire_pillar : public CreatureScript
{
    public:
        npc_highmaul_fire_pillar() : CreatureScript("npc_highmaul_fire_pillar") { }

        enum eSpells
        {
            FirePillarSelector      = 159712,
            FirePillarActivated     = 159706,
            FirePillarKnockback     = 158994,
            FirePillarSteamTimer    = 163967,

            FlameJet                = 159202,   ///< AreaTrigger
            KargathTrigger          = 159070,
            KargathTrigger2         = 159073,

            /// Only for Mythic mode
            FlameGoutPeriodic       = 162574,   ///< Trigger 162576 (searcher) every 5s
            FlameGoutSearcher       = 162576,
            FlameGoutMissile        = 162577
        };

        enum eData
        {
            AnimKit1    = 6295,
            AnimKit2    = 6296,
            AnimKit3    = 6297,
            AnimKit4    = 6308
        };

        enum eActions
        {
            DeactivatePillar,
            DeactivatePillarOther
        };

        struct npc_highmaul_fire_pillarAI : public ScriptedAI
        {
            npc_highmaul_fire_pillarAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC);
                me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN);

                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_LOOTING | UNIT_FLAG_TAXI_FLIGHT);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT | UNIT_FLAG_PLAYER_CONTROLLED);

                me->RemoveAura(eSpells::FlameGoutPeriodic);

                ClearDelayedOperations();
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                damage = 0;
                return;
            }

            void SpellHit(Unit* p_Caster, SpellInfo const* spellInfo) override
            {
                if (p_Caster == nullptr)
                    return;

                switch (spellInfo->Id)
                {
                    case eSpells::FirePillarSelector:
                    {
                        me->CastSpell(me, eSpells::FirePillarSteamTimer, true);
                        me->CastSpell(me, eSpells::FirePillarActivated, true);
                        me->CastSpell(me, eSpells::FirePillarKnockback, true, nullptr, nullptr, p_Caster->GetGUID());

                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT);
                        me->PlayOneShotAnimKitId(eData::AnimKit1);
                        AddTimedDelayedOperation(3 * TimeConstants::IN_MILLISECONDS, [this]() -> void { me->SetAIAnimKitId(eData::AnimKit2); });
                        AddTimedDelayedOperation(3 * TimeConstants::IN_MILLISECONDS, [this]() -> void { me->CastSpell(me, eSpells::FlameJet, true); });

                        if (me->GetMap()->IsMythic())
                            me->CastSpell(me, eSpells::FlameGoutPeriodic, true);

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
                    case eSpells::FlameGoutSearcher:
                        me->CastSpell(target, eSpells::FlameGoutMissile, true);
                        break;
                    default:
                        break;
                }
            }

            void DoAction(int32 const action) override
            {
                switch (action)
                {
                    case eActions::DeactivatePillar:
                    {
                        DeactivatePillar();
                        break;
                    }
                    case eActions::DeactivatePillarOther:
                    {
                        AddTimedDelayedOperation(3 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                        {
                            DeactivatePillar();

                            if (Creature* l_Kargath = me->FindNearestCreature(eHighmaulCreatures::KargathBladefist, 15.0f))
                            {
                                l_Kargath->SetControlled(false, UnitState::UNIT_STATE_ROOT);
                                l_Kargath->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
                                l_Kargath->SetReactState(ReactStates::REACT_AGGRESSIVE);
                                l_Kargath->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN);
                                l_Kargath->ClearUnitState(UnitState::UNIT_STATE_CANNOT_TURN);
                            }
                        });

                        break;
                    }
                    default:
                        break;
                }
            }

            void DeactivatePillar()
            {
                /// Deactivate Pillar
                me->RemoveAllAreaTriggers();
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT);
                me->RemoveAllAuras();
                me->SetAIAnimKitId(0);
                me->PlayOneShotAnimKitId(eData::AnimKit3);
                me->RemoveAura(eSpells::FlameGoutPeriodic);
            }

            void UpdateAI(uint32 const diff) override
            {
                UpdateOperations(diff);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_highmaul_fire_pillarAI(creature);
        }
};

/// Ravenous Bloodmaw - 79296
class npc_highmaul_ravenous_bloodmaw : public CreatureScript
{
    public:
        npc_highmaul_ravenous_bloodmaw() : CreatureScript("npc_highmaul_ravenous_bloodmaw") { }

        enum eSpells
        {
            SpellMaul       = 161218,
            OnTheHunt       = 162497,
            SpellInflamed   = 163130,
            InThePitAura    = 161423
        };

        enum eActions
        {
            FreeRavenous,
            InterruptRavenous
        };

        enum eEvent
        {
            CheckPlayer = 1
        };

        struct npc_highmaul_ravenous_bloodmawAI : public ScriptedAI
        {
            npc_highmaul_ravenous_bloodmawAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap m_Events;

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);

                m_Events.Reset();
                m_Events.ScheduleEvent(eEvent::CheckPlayer, 500);

                me->RemoveAura(eSpells::SpellInflamed);
            }

            void SpellHitTarget(Unit* target, SpellInfo const* spellInfo) override
            {
                if (target == nullptr)
                    return;

                switch (spellInfo->Id)
                {
                    case eSpells::OnTheHunt:
                    {
                        me->ClearUnitState(UnitState::UNIT_STATE_CASTING);

                        me->SetInCombatWithZone();

                        me->getThreatManager().clearReferences();
                        me->getThreatManager().addThreat(target, std::numeric_limits<float>::max());

                        me->SetReactState(ReactStates::REACT_AGGRESSIVE);
                        me->TauntApply(target);
                        me->SetReactState(ReactStates::REACT_PASSIVE);

                        me->SetSpeed(UnitMoveType::MOVE_RUN, 0.5f);

                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);

                        me->GetMotionMaster()->Clear(true);
                        me->GetMotionMaster()->MoveChase(target);
                        break;
                    }
                    default:
                        break;
                }
            }

            void DoAction(int32 const action) override
            {
                switch (action)
                {
                    case eActions::FreeRavenous:
                    {
                        if (!IsMythic())
                            break;

                        m_Events.CancelEvent(eEvent::CheckPlayer);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);

                        float l_X = me->GetPositionX() + (9.0f * cos(me->GetOrientation()));
                        float l_Y = me->GetPositionY() + (9.0f * sin(me->GetOrientation()));

                        me->GetMotionMaster()->MoveJump(l_X, l_Y, g_ArenaFloor, 15.0f, 25.0f, me->GetOrientation());

                        AddTimedDelayedOperation(2 * TimeConstants::IN_MILLISECONDS, [this]() -> void { me->CastSpell(me, eSpells::OnTheHunt, false); });
                        break;
                    }
                    case eActions::InterruptRavenous:
                    {
                        if (me->HasAura(eSpells::SpellInflamed))
                            break;

                        me->GetMotionMaster()->Clear();

                        me->CastSpell(me, eSpells::SpellInflamed, true);

                        /*AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                        {
                            Position pos;
                            float l_X = me->GetPositionX() + (7.0f * cos(me->GetOrientation()));
                            float l_Y = me->GetPositionY() + (7.0f * sin(me->GetOrientation()));

                            pos.m_positionX = l_X;
                            pos.m_positionY = l_Y;

                            /// Creating the circle path from the center
                            me->GetMotionMaster()->Clear();
                            me->SetWalk(false);
                            me->SetSpeed(UnitMoveType::MOVE_RUN, 2.0f);

                            Movement::MoveSplineInit l_Init(me);
                            FillCirclePath(pos, 7.0f, me->GetPositionZ(), l_Init.Path(), true);
                            l_Init.SetWalk(true);
                            l_Init.SetCyclic();
                            l_Init.Launch();
                        });*/

                        GrantFavorToAllPlayers(me, 10, eSpells::SpellInflamed);
                        break;
                    }
                    default:
                        break;
                }
            }

            void MovementInform(uint32 type, uint32 /*id*/) override
            {
                if (type != MovementGeneratorType::CHASE_MOTION_TYPE)
                    return;

                if (Unit* target = me->GetVictim())
                {
                    me->AddAura(eSpells::InThePitAura, target);
                    me->CastSpell(target, eSpells::SpellMaul, true);
                    target->RemoveAura(eSpells::InThePitAura);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                }
            }

            void KilledUnit(Unit* /*killed*/) override
            {
                if (!IsMythic())
                    return;

                me->SetInCombatWithZone();

                /// Hunt another player only if the first one's dead, or at the end of the channel
                me->CastSpell(me, eSpells::OnTheHunt, false);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                ClearDelayedOperations();

                me->InterruptNonMeleeSpells(true);
                me->SetReactState(ReactStates::REACT_PASSIVE);
                CreatureAI::EnterEvadeMode();
            }

            void JustDied(Unit*) override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);
            }

            void UpdateAI(uint32 const diff) override
            {
                UpdateOperations(diff);

                m_Events.Update(diff);

                if (me->HasUnitState(UnitState::UNIT_STATE_CASTING) || me->HasUnitState(UnitState::UNIT_STATE_CHASE))
                    return;

                if (m_Events.ExecuteEvent() == eEvent::CheckPlayer)
                {
                    std::list<Player*> l_PlrList;
                    me->GetPlayerListInGrid(l_PlrList, 10.0f);

                    for (Player* player : l_PlrList)
                    {
                        if (!player->IsAlive() || player->GetPositionZ() > 50.0f)
                            continue;

                        me->AddAura(eSpells::InThePitAura, player);
                        me->CastSpell(player, eSpells::SpellMaul, true);
                        player->RemoveAura(eSpells::InThePitAura);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                        break;
                    }

                    m_Events.ScheduleEvent(eEvent::CheckPlayer, 500);
                }
            }

            void FillCirclePath(Position const& p_Center, float radius, float p_Z, Movement::PointsArray& p_Path, bool p_Clockwise)
            {
                float l_Step = p_Clockwise ? -M_PI / 8.0f : float(M_PI) / 8.0f;
                float l_Angle = p_Center.GetAngle(me->GetPositionX(), me->GetPositionY());

                for (uint8 itr = 0; itr < 16; l_Angle += l_Step, ++itr)
                {
                    G3D::Vector3 l_Point;
                    l_Point.x = p_Center.GetPositionX() + radius * cosf(l_Angle);
                    l_Point.y = p_Center.GetPositionY() + radius * sinf(l_Angle);
                    l_Point.z = p_Z;
                    p_Path.push_back(l_Point);
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_highmaul_ravenous_bloodmawAI(creature);
        }
};

/// Kargath Bladefist (trigger) - 78846
class npc_highmaul_kargath_bladefist_trigger : public CreatureScript
{
    public:
        npc_highmaul_kargath_bladefist_trigger() : CreatureScript("npc_highmaul_kargath_bladefist_trigger") { }

        enum eSpells
        {
            BladeDanceDmg           = 159217,
            BladeDanceCharge        = 159265,
            SpellBladeDanceFadeOut  = 159209
        };

        enum eDatas
        {
            MorphWithWeapon = 54674,
            MorphInvisible  = 11686,
            AnimKit1        = 5865,
            AnimKit2        = 5864,
            AnimKit3        = 5863,
            AnimKit4        = 5861
        };

        struct npc_highmaul_kargath_bladefist_triggerAI : public ScriptedAI
        {
            npc_highmaul_kargath_bladefist_triggerAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC);
            }

            void SpellHit(Unit* p_Caster, SpellInfo const* spellInfo) override
            {
                if (p_Caster == nullptr)
                    return;

                if (spellInfo->Id == eSpells::BladeDanceCharge)
                {
                    me->SetDisplayId(eDatas::MorphWithWeapon);
                    me->CastSpell(me, eSpells::BladeDanceDmg, true, nullptr, nullptr, p_Caster->GetGUID());
                    me->CastSpell(p_Caster, eSpells::BladeDanceCharge, true);

                    uint32 const l_AnimKits[4] = { eDatas::AnimKit1, eDatas::AnimKit2, eDatas::AnimKit3, eDatas::AnimKit4 };
                    me->PlayOneShotAnimKitId(l_AnimKits[urand(0, 3)]);

                    AddTimedDelayedOperation(100, [this]() -> void { me->CastSpell(me, eSpells::SpellBladeDanceFadeOut, true); });
                    AddTimedDelayedOperation(500, [this]() -> void { me->SetDisplayId(eDatas::MorphInvisible); });
                    AddTimedDelayedOperation(600, [this]() -> void { me->DespawnOrUnsummon(); });
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_highmaul_kargath_bladefist_triggerAI(creature);
        }
};

/// Drunken Bileslinger - 78954
class npc_highmaul_drunken_bileslinger : public CreatureScript
{
    public:
        npc_highmaul_drunken_bileslinger() : CreatureScript("npc_highmaul_drunken_bileslinger") { }

        enum eSpells
        {
            KegPackCosmetic     = 160213,

            MaulingBrewSearch   = 159410,
            MaulingBrew         = 159414,
            VileBreath          = 160521,

            /// Only in Mythic difficulty
            Heckle              = 163408    ///< Reduces the favor within Roar of the Crowd.
        };

        enum eEvents
        {
            EventMaulingBrew = 1,
            EventVileBreath,
            EventHeckle
        };

        struct npc_highmaul_drunken_bileslingerAI : public ScriptedAI
        {
            npc_highmaul_drunken_bileslingerAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap m_ClassicEvent;
            EventMap m_FightEvent;

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->CastSpell(me, eSpells::KegPackCosmetic, true);

                m_ClassicEvent.Reset();
                m_ClassicEvent.ScheduleEvent(eEvents::EventMaulingBrew, urand(3000, 5000));

                m_FightEvent.Reset();
            }

            void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
            {
                if (me->HasReactState(ReactStates::REACT_PASSIVE))
                {
                    m_ClassicEvent.Reset();
                    me->SetReactState(ReactStates::REACT_AGGRESSIVE);
                    m_FightEvent.ScheduleEvent(eEvents::EventVileBreath, 3000);
                    m_FightEvent.ScheduleEvent(eEvents::EventHeckle, 6000);
                }
            }

            void SpellHitTarget(Unit* target, SpellInfo const* spellInfo) override
            {
                if (target == nullptr)
                    return;

                if (spellInfo->Id == eSpells::MaulingBrewSearch)
                    me->CastSpell(target, eSpells::MaulingBrew, true);
            }

            void JustDied(Unit* /*killer*/) override
            {
                me->RemoveAllAreaTriggers();
                me->DespawnOrUnsummon(5000);
            }

            void UpdateAI(uint32 const diff) override
            {
                m_ClassicEvent.Update(diff);

                if (m_ClassicEvent.ExecuteEvent() == eEvents::EventMaulingBrew)
                {
                    me->CastSpell(me, eSpells::MaulingBrewSearch, false);
                    m_ClassicEvent.ScheduleEvent(eEvents::EventMaulingBrew, urand(15000, 25000));
                }

                if (!UpdateVictim())
                    return;

                m_FightEvent.Update(diff);

                if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                    return;

                switch (m_FightEvent.ExecuteEvent())
                {
                    case eEvents::EventVileBreath:
                        me->CastSpell(me, eSpells::VileBreath, false);
                        m_FightEvent.ScheduleEvent(eEvents::EventVileBreath, 10000);
                        break;
                    case eEvents::EventHeckle:
                        me->CastSpell(me, eSpells::Heckle, false);
                        m_FightEvent.ScheduleEvent(eEvents::EventHeckle, 10000);
                        break;
                    default:
                        break;
                }

                DoMeleeAttackIfReady();

                /// Arena's trash mobs shouldn't enter into the arena
                if (me->GetPositionZ() <= g_InArenaZ)
                    EnterEvadeMode();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_highmaul_drunken_bileslingerAI(creature);
        }
};

/// Iron Bomber - 78926
class npc_highmaul_iron_bomber : public CreatureScript
{
    public:
        npc_highmaul_iron_bomber() : CreatureScript("npc_highmaul_iron_bomber") { }

        enum eSpells
        {
            BombPackCosmetic    = 160249,

            SpellIronBomb       = 159386,
            FireBomb            = 160953,

            /// Only for Mythic difficulty
            Heckle              = 163408    ///< Reduces the favor within Roar of the Crowd.
        };

        enum eEvents
        {
            EventIronBomb = 1,
            EventHeckle
        };

        enum eDatas
        {
            MorphDead   = 61562,
            IronBomb    = 79712
        };

        enum eTalk
        {
            Bomb
        };

        struct npc_highmaul_iron_bomberAI : public ScriptedAI
        {
            npc_highmaul_iron_bomberAI(Creature* creature) : ScriptedAI(creature) { }

            bool m_HasBomb;
            EventMap m_Events;
            EventMap m_FightEvents;

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->CastSpell(me, eSpells::BombPackCosmetic, true);

                m_HasBomb = false;

                m_Events.Reset();
                m_Events.ScheduleEvent(eEvents::EventIronBomb, urand(3000, 6000));
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (me->HasReactState(ReactStates::REACT_PASSIVE))
                {
                    m_Events.Reset();
                    me->SetReactState(ReactStates::REACT_AGGRESSIVE);
                    m_FightEvents.ScheduleEvent(eEvents::EventHeckle, 6000);
                }

                if (m_HasBomb)
                    return;

                if (me->HealthBelowPctDamaged(50, damage))
                {
                    m_HasBomb = true;
                    if (Creature* l_IronBomb = me->SummonCreature(eDatas::IronBomb, me->GetPosition()))
                        l_IronBomb->EnterVehicle(me, 0);

                    Talk(eTalk::Bomb);
                }
            }

            void PassengerBoarded(Unit* p_Passenger, int8 /*p_Seat*/, bool p_Apply) override
            {
                if (p_Apply || p_Passenger->ToCreature() == nullptr)
                    return;

                p_Passenger->CastSpell(p_Passenger, eSpells::FireBomb, true);
                p_Passenger->ToCreature()->SetReactState(ReactStates::REACT_PASSIVE);
            }

            void JustDied(Unit* /*killer*/) override
            {
                me->SetDisplayId(eDatas::MorphDead);
                me->DespawnOrUnsummon(5000);
            }

            void UpdateAI(uint32 const diff) override
            {
                /// Iron Bombs are out of combat
                m_Events.Update(diff);

                if (m_Events.ExecuteEvent() == eEvents::EventIronBomb)
                {
                    me->CastSpell(me, eSpells::SpellIronBomb, TRIGGERED_IGNORE_CASTER_MOUNTED_OR_ON_VEHICLE);
                    m_Events.ScheduleEvent(eEvents::EventIronBomb, urand(5000, 9000));
                }

                if (!UpdateVictim())
                    return;

                if (m_FightEvents.ExecuteEvent() == eEvents::EventHeckle)
                {
                    me->CastSpell(me, eSpells::Heckle, false);
                    m_FightEvents.ScheduleEvent(eEvents::EventHeckle, 6000);
                }

                DoMeleeAttackIfReady();

                /// Arena's trash mobs shouldn't enter into the arena
                if (me->GetPositionZ() <= g_InArenaZ)
                    EnterEvadeMode();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_highmaul_iron_bomberAI(creature);
        }
};

/// Iron Grunt (Cosmetic only) - 84946
class npc_highmaul_iron_grunt : public CreatureScript
{
    public:
        npc_highmaul_iron_grunt() : CreatureScript("npc_highmaul_iron_grunt") { }

        struct npc_highmaul_iron_gruntAI : public ScriptedAI
        {
            npc_highmaul_iron_gruntAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);

                AddTimedDelayedOperation(3 * TimeConstants::IN_MILLISECONDS, [this]() -> void { me->HandleEmoteCommand(g_CrowdEmotes[urand(0, 7)]); });
            }

            void LastOperationCalled() override
            {
                AddTimedDelayedOperation(3 * TimeConstants::IN_MILLISECONDS, [this]() -> void { me->HandleEmoteCommand(g_CrowdEmotes[urand(0, 7)]); });
            }

            void UpdateAI(uint32 const diff) override
            {
                UpdateOperations(diff);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_highmaul_iron_gruntAI(creature);
        }
};

/// Iron Grunt - 79068
class npc_highmaul_iron_grunt_second : public CreatureScript
{
    public:
        npc_highmaul_iron_grunt_second() : CreatureScript("npc_highmaul_iron_grunt_second") { }

        enum eSpells
        {
            Grapple             = 159188,
            CrowdMinionKilled   = 163392
        };

        enum eEvent
        {
            EventGrapple = 1
        };

        struct npc_highmaul_iron_grunt_secondAI : public ScriptedAI
        {
            npc_highmaul_iron_grunt_secondAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap m_Events;

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);

                AddTimedDelayedOperation(3 * TimeConstants::IN_MILLISECONDS, [this]() -> void { me->HandleEmoteCommand(g_CrowdEmotes[urand(0, 7)]); });

                m_Events.Reset();
            }

            void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
            {
                if (me->HasReactState(ReactStates::REACT_PASSIVE))
                {
                    me->SetReactState(ReactStates::REACT_AGGRESSIVE);

                    m_Events.Reset();

                    m_Events.ScheduleEvent(eEvent::EventGrapple, 3000);
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                /// In Mythic difficulty, killing Iron Grunts grants favor for Roar of the Crowd.
                if (Map* l_Map = me->GetMap())
                {
                    if (l_Map->IsMythic())
                        instance->DoCastSpellOnPlayers(eSpells::CrowdMinionKilled);
                }
            }

            void LastOperationCalled() override
            {
                AddTimedDelayedOperation(3 * TimeConstants::IN_MILLISECONDS, [this]() -> void { me->HandleEmoteCommand(g_CrowdEmotes[urand(0, 7)]); });
            }

            void UpdateAI(uint32 const diff) override
            {
                ScriptedAI::UpdateAI(diff);

                if (!UpdateVictim())
                    return;

                m_Events.Update(diff);

                if (m_Events.ExecuteEvent() == eEvent::EventGrapple)
                {
                    if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, eSpells::Grapple, true);
                    m_Events.ScheduleEvent(eEvent::EventGrapple, 6000);
                }

                DoMeleeAttackIfReady();

                /// Arena's trash mobs shouldn't enter into the arena
                if (me->GetPositionZ() <= g_InArenaZ)
                    EnterEvadeMode();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_highmaul_iron_grunt_secondAI(creature);
        }
};

/// Ogre Grunt - 84958
class npc_highmaul_ogre_grunt : public CreatureScript
{
    public:
        npc_highmaul_ogre_grunt() : CreatureScript("npc_highmaul_ogre_grunt") { }

        struct npc_highmaul_ogre_gruntAI : public ScriptedAI
        {
            npc_highmaul_ogre_gruntAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);

                AddTimedDelayedOperation(3 * TimeConstants::IN_MILLISECONDS, [this]() -> void { me->HandleEmoteCommand(g_CrowdEmotes[urand(0, 7)]); });
            }

            void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
            {
                if (me->HasReactState(ReactStates::REACT_PASSIVE))
                    me->SetReactState(ReactStates::REACT_AGGRESSIVE);
            }

            void JustDied(Unit* /*killer*/) override
            {
                /// In Mythic difficulty, killing Iron Grunts grants favor for Roar of the Crowd.
            }

            void LastOperationCalled() override
            {
                AddTimedDelayedOperation(3 * TimeConstants::IN_MILLISECONDS, [this]() -> void { me->HandleEmoteCommand(g_CrowdEmotes[urand(0, 7)]); });
            }

            void UpdateAI(uint32 const diff) override
            {
                ScriptedAI::UpdateAI(diff);

                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();

                /// Arena's trash mobs shouldn't enter into the arena
                if (me->GetPositionZ() <= g_InArenaZ)
                    EnterEvadeMode();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_highmaul_ogre_gruntAI(creature);
        }
};

/// Ogre Grunt - 84948
class npc_highmaul_ogre_grunt_second : public CreatureScript
{
    public:
        npc_highmaul_ogre_grunt_second() : CreatureScript("npc_highmaul_ogre_grunt_second") { }

        struct npc_highmaul_ogre_grunt_secondAI : public ScriptedAI
        {
            npc_highmaul_ogre_grunt_secondAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);

                AddTimedDelayedOperation(3 * TimeConstants::IN_MILLISECONDS, [this]() -> void { me->HandleEmoteCommand(g_CrowdEmotes[urand(0, 7)]); });
            }

            void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
            {
                if (me->HasReactState(ReactStates::REACT_PASSIVE))
                    me->SetReactState(ReactStates::REACT_AGGRESSIVE);
            }

            void JustDied(Unit* /*killer*/) override
            {
                /// In Mythic difficulty, killing Iron Grunts grants favor for Roar of the Crowd.
            }

            void LastOperationCalled() override
            {
                AddTimedDelayedOperation(3 * TimeConstants::IN_MILLISECONDS, [this]() -> void { me->HandleEmoteCommand(g_CrowdEmotes[urand(0, 7)]); });
            }

            void UpdateAI(uint32 const diff) override
            {
                ScriptedAI::UpdateAI(diff);

                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();

                /// Arena's trash mobs shouldn't enter into the arena
                if (me->GetPositionZ() <= g_InArenaZ)
                    EnterEvadeMode();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_highmaul_ogre_grunt_secondAI(creature);
        }
};

/// Highmaul Sweeper - 88874
class npc_highmaul_highmaul_sweeper : public CreatureScript
{
    public:
        npc_highmaul_highmaul_sweeper() : CreatureScript("npc_highmaul_highmaul_sweeper") { }

        enum eSpells
        {
            ArenaSweeper        = 177776,
            MonstersBrawl       = 177815,
            ArenaSweeperImpact  = 177802
        };

        enum eActions
        {
            KickOutPlayers,

            SpawnIronBombers = 5,
            SpawnDrukenBileslinger
        };

        enum eSweeperType
        {
            TypeRight,
            TypeLeft
        };

        struct npc_highmaul_highmaul_sweeperAI : public ScriptedAI
        {
            npc_highmaul_highmaul_sweeperAI(Creature* creature) : ScriptedAI(creature)
            {
                m_Instance  = creature->GetInstanceScript();
            }

            InstanceScript* m_Instance;

            uint8 m_MoveID;
            uint8 m_SweeperType;
            bool m_ComeBack;

            void Reset() override
            {
                m_MoveID        = 0;
                m_SweeperType   = me->GetOrientation() >= 6.0f ? eSweeperType::TypeRight : eSweeperType::TypeLeft;
                m_ComeBack      = false;

                me->SetReactState(ReactStates::REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                me->SetSpeed(UnitMoveType::MOVE_RUN, 2.0f);
            }

            void DoAction(int32 const action) override
            {
                if (action == eActions::KickOutPlayers)
                {
                    me->CastSpell(me, eSpells::ArenaSweeper, true);
                    me->GetMotionMaster()->MovePoint(m_MoveID, g_HighmaulSweeperMoves[m_SweeperType][m_MoveID]);
                }
            }

            void MovementInform(uint32 type, uint32 /*id*/) override
            {
                if (type != MovementGeneratorType::POINT_MOTION_TYPE)
                    return;

                if (m_MoveID < (eHighmaulDatas::HighmaulSweeperMovesCount - 1) && !m_ComeBack)
                {
                    ++m_MoveID;
                    me->GetMotionMaster()->MovePoint(m_MoveID, g_HighmaulSweeperMoves[m_SweeperType][m_MoveID]);
                }
                else if (m_MoveID == (eHighmaulDatas::HighmaulSweeperMovesCount - 1))
                {
                    m_ComeBack = true;
                    --m_MoveID;
                    me->GetMotionMaster()->MovePoint(m_MoveID, g_HighmaulSweeperMoves[m_SweeperType][m_MoveID]);
                }
                else if (m_MoveID == 0 && m_ComeBack)
                {
                    /// End of move
                    m_ComeBack = false;
                    me->RemoveAura(eSpells::ArenaSweeper);
                    AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this]() -> void { me->SetFacingTo(me->GetHomePosition().GetOrientation()); });

                    /// Just needed once
                    if (m_SweeperType)
                    {
                        if (Creature* l_Kargath = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eHighmaulCreatures::KargathBladefist)))
                        {
                            l_Kargath->AI()->DoAction(eActions::SpawnIronBombers);
                            l_Kargath->AI()->DoAction(eActions::SpawnDrukenBileslinger);
                        }
                    }
                }
                else if (m_ComeBack && m_MoveID > 0)
                {
                    --m_MoveID;
                    me->GetMotionMaster()->MovePoint(m_MoveID, g_HighmaulSweeperMoves[m_SweeperType][m_MoveID]);
                }
            }

            void SpellHitTarget(Unit* target, SpellInfo const* spellInfo) override
            {
                if (target == nullptr)
                    return;

                if (spellInfo->Id == eSpells::MonstersBrawl)
                {
                    me->CastSpell(target, eSpells::ArenaSweeperImpact, true);

                    Position l_FirstPos = g_SweeperJumpPos[m_SweeperType][0];
                    Position l_SecondPos = g_SweeperJumpPos[m_SweeperType][1];

                    if (me->GetDistance(l_FirstPos) > me->GetDistance(l_SecondPos))
                        target->GetMotionMaster()->MoveJump(l_SecondPos, 15.0f, 25.0f, target->GetOrientation());
                    else
                        target->GetMotionMaster()->MoveJump(l_FirstPos, 15.0f, 25.0f, target->GetOrientation());
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_highmaul_highmaul_sweeperAI(creature);
        }
};

/// Chain Hurl Vehicle - 79134
class npc_highmaul_chain_hurl_vehicle : public CreatureScript
{
    public:
        npc_highmaul_chain_hurl_vehicle() : CreatureScript("npc_highmaul_chain_hurl_vehicle") { }

        enum eSpells
        {
            ChainHurlJumpDest   = 159995,
            Obscured            = 160131,
            Chain               = 159531,
            FlameJetDoT         = 159311
        };

        enum eAction
        {
            EndOfChainHurl = 7
        };

        struct npc_highmaul_chain_hurl_vehicleAI : public ScriptedAI
        {
            npc_highmaul_chain_hurl_vehicleAI(Creature* creature) : ScriptedAI(creature)
            {
                m_Instance = creature->GetInstanceScript();
            }

            InstanceScript* m_Instance;

            float m_Angle;
            bool m_Rotate;

            void Reset() override
            {
                m_Angle = 0.0f;
                m_Rotate = false;
            }

            void PassengerBoarded(Unit* p_Passenger, int8 /*p_SeatID*/, bool p_Apply) override
            {
                if (p_Apply || p_Passenger == nullptr || p_Passenger->GetTypeId() != TypeID::TYPEID_PLAYER)
                {
                    if (!m_Rotate && p_Apply)
                        m_Rotate = true;

                    if (p_Apply && p_Passenger != nullptr)
                        p_Passenger->RemoveAura(eSpells::FlameJetDoT);

                    return;
                }

                ObjectGuid guid = p_Passenger->GetGUID();
                AddTimedDelayedOperation(1 * TimeConstants::IN_MILLISECONDS, [this, guid]() -> void
                {
                    if (Unit* l_Passenger = ObjectAccessor::GetUnit(*me, guid))
                        l_Passenger->CastSpell(g_ArenaStandsPos, eSpells::ChainHurlJumpDest, true);
                });

                p_Passenger->RemoveAura(eSpells::Chain);
                p_Passenger->AddAura(eSpells::Obscured, p_Passenger);

                m_Rotate = false;
                m_Angle = 0.0f;
                me->SetFacingTo(m_Angle);
                me->SetOrientation(m_Angle);
            }

            void UpdateAI(uint32 const diff) override
            {
                ScriptedAI::UpdateAI(diff);

                if (!m_Rotate)
                    return;

                m_Angle += (2.0f * float(M_PI)) / 10.0f;

                if (m_Angle > (2.0f * float(M_PI)))
                    m_Angle = 0.0f;

                me->SetFacingTo(m_Angle);
                me->SetOrientation(m_Angle);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_highmaul_chain_hurl_vehicleAI(creature);
        }
};

/// Area Trigger for Crowd - 79260
class npc_highmauareaTrigger_for_crowd : public CreatureScript
{
    public:
        npc_highmauareaTrigger_for_crowd() : CreatureScript("npc_highmauareaTrigger_for_crowd") { }

        enum eActions
        {
            StartIntro,
            VulgorDied = 2
        };

        enum eSpells
        {
            ElevatorSoundTrigger    = 166694,
            Obscured                = 160131
        };

        enum eEvent
        {
            InitObscured = 1
        };

        enum eCreatures
        {
            IronGrunt1  = 84946,
            IronGrunt2  = 79068,
            OgreGrunt1  = 84948,
            OgreGrunt2  = 84958
        };

        struct npc_highmauareaTrigger_for_crowdAI : public ScriptedAI
        {
            npc_highmauareaTrigger_for_crowdAI(Creature* creature) : ScriptedAI(creature)
            {
                m_IntroStarted  = false;
                m_Instance      = creature->GetInstanceScript();
                m_CheckTimer    = 1000;
            }

            bool m_IntroStarted;
            InstanceScript* m_Instance;

            uint32 m_CheckTimer;

            EventMap m_Events;

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC);

                m_Events.Reset();
                m_Events.ScheduleEvent(eEvent::InitObscured, 2000);
            }

            void UpdateAI(uint32 const diff) override
            {
                ScheduleIntro(diff);

                m_Events.Update(diff);

                if (m_Events.ExecuteEvent() == eEvent::InitObscured)
                {
                    std::list<Creature*> l_CreatureList;
                    me->GetCreatureListInGrid(l_CreatureList, 300.0f);

                    if (l_CreatureList.empty())
                        return;

                    l_CreatureList.remove_if([this](Creature* creature) -> bool
                    {
                        if (creature->GetEntry() != eHighmaulCreatures::DrunkenBileslinger &&
                            creature->GetEntry() != eHighmaulCreatures::IronBomber &&
                            creature->GetEntry() != eCreatures::IronGrunt1 &&
                            creature->GetEntry() != eCreatures::IronGrunt2 &&
                            creature->GetEntry() != eCreatures::OgreGrunt1 &&
                            creature->GetEntry() != eCreatures::OgreGrunt2)
                            return true;

                        if (creature->HasAura(eSpells::Obscured, me->GetGUID()))
                            return true;

                        return false;
                    });

                    for (Creature* l_Creature : l_CreatureList)
                        me->CastSpell(l_Creature, eSpells::Obscured, true);

                    m_Events.ScheduleEvent(eEvent::InitObscured, 3000);
                }
            }

            void ScheduleIntro(uint32 const diff)
            {
                if (!m_CheckTimer || m_IntroStarted)
                    return;

                if (m_CheckTimer <= diff)
                {
                    if (me->SelectNearestPlayer(10.0f) != nullptr)
                    {
                        m_IntroStarted = true;

                        me->CastSpell(me, eSpells::ElevatorSoundTrigger, true);

                        if (Creature* l_Vulgor = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eHighmaulCreatures::Vulgor)))
                        {
                            if (l_Vulgor->IsAlive())
                            {
                                if (Creature* l_Jhorn = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eHighmaulCreatures::JhornTheMad)))
                                    l_Jhorn->AI()->DoAction(eActions::StartIntro);

                                if (Creature* l_Thoktar = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eHighmaulCreatures::ThoktarIronskull)))
                                    l_Thoktar->AI()->DoAction(eActions::StartIntro);
                            }
                            /// Handle the case if Vul'gor already died
                            else
                            {
                                if (Creature* l_Jhorn = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eHighmaulCreatures::JhornTheMad)))
                                    l_Jhorn->AI()->DoAction(eActions::VulgorDied);

                                if (Creature* l_Thoktar = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eHighmaulCreatures::ThoktarIronskull)))
                                    l_Thoktar->AI()->DoAction(eActions::VulgorDied);

                                Creature* l_MargokCosmetic = m_Instance->GetCreature(eHighmaulCreatures::MargokCosmetic);

                                if (!l_MargokCosmetic)
                                    l_MargokCosmetic = me->SummonCreature(eHighmaulCreatures::MargokCosmetic, 3397.446289f, 7493.029297f, 73.664780f, 0.928363f);

                                if (l_MargokCosmetic)
                                    l_MargokCosmetic->AI()->DoAction(eActions::VulgorDied);

                                if (Creature* l_Gharg = ObjectAccessor::GetCreature(*me, m_Instance->GetGuidData(eHighmaulCreatures::GhargArenaMaster)))
                                    l_Gharg->AI()->DoAction(eActions::StartIntro);
                            }
                        }
                    }
                    else
                        m_CheckTimer = 1000;
                }
                else
                    m_CheckTimer -= diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_highmauareaTrigger_for_crowdAI(creature);
        }
};

/// Earth Breaker - 162271
class spell_highmaul_earth_breaker : public SpellScriptLoader
{
    public:
        spell_highmaul_earth_breaker() : SpellScriptLoader("spell_highmaul_earth_breaker") { }

        class spell_highmaul_earth_breaker_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_highmaul_earth_breaker_SpellScript);

            enum eDatas
            {
                TargetRestrict  = 20675,
                EarthMissile    = 162472,
                SmolderingStone = 80051
            };

            void CorrectTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                SpellTargetRestrictionsEntry const* l_Restriction = sSpellTargetRestrictionsStore.LookupEntry(eDatas::TargetRestrict);
                if (l_Restriction == nullptr)
                    return;

                Unit* caster = GetCaster();
                if (caster == nullptr)
                    return;

                float radius = GetSpellInfo()->GetEffect(1)->CalcRadius(caster);
                targets.remove_if([radius, caster, l_Restriction](WorldObject* p_Object) -> bool
                {
                    if (p_Object == nullptr)
                        return true;

                    if (!p_Object->IsInAxe(caster, l_Restriction->Width, radius))
                        return true;

                    return false;
                });
            }

            void HandleBeforeCast()
            {
                if (Unit* caster = GetCaster())
                {
                    float radius = 30.0f;
                    float l_O = caster->GetOrientation();
                    float l_X = caster->GetPositionX() + (radius * cos(l_O));
                    float l_Y = caster->GetPositionY() + (radius * sin(l_O));
                    float l_Z = caster->GetPositionZ();
                    caster->CastSpell(l_X, l_Y, l_Z, eDatas::EarthMissile, true);
                    caster->SummonCreature(eDatas::SmolderingStone, l_X, l_Y, l_Z, l_O, TempSummonType::TEMPSUMMON_TIMED_DESPAWN, 45000);
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_highmaul_earth_breaker_SpellScript::CorrectTargets, EFFECT_1, TARGET_UNIT_CASTER_AREA_ENEMY_FRONT);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_highmaul_earth_breaker_SpellScript::CorrectTargets, EFFECT_2, TARGET_UNIT_CASTER_AREA_ENEMY_FRONT);
                BeforeCast += SpellCastFn(spell_highmaul_earth_breaker_SpellScript::HandleBeforeCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_highmaul_earth_breaker_SpellScript();
        }
};

/// Impale - 159113
class spell_highmaul_impale : public SpellScriptLoader
{
    public:
        spell_highmaul_impale() : SpellScriptLoader("spell_highmaul_impale") { }

        enum eSpell
        {
            OpenWounds = 159178
        };

        enum eCreature
        {
            AreaTriggerForCrowd = 79260
        };

        class spell_highmaul_impale_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_impale_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                Unit* caster = GetCaster();
                if (target == nullptr || caster == nullptr)
                    return;

                AuraRemoveMode l_RemoveMode = GetTargetApplication()->GetRemoveMode();
                if (l_RemoveMode != AuraRemoveMode::AURA_REMOVE_BY_DEATH)
                    caster->CastSpell(target, eSpell::OpenWounds, true);

                if (Creature* l_Trigger = target->FindNearestCreature(eCreature::AreaTriggerForCrowd, 50.0f))
                {
                    if (target->GetDistance(l_Trigger) >= 10.0f)
                    {
                        float l_O = target->GetAngle(l_Trigger);
                        float l_X = target->GetPositionX() + 5.0f * cos(l_O);
                        float l_Y = target->GetPositionY() + 5.0f * sin(l_O);
                        float l_Z = caster->GetPositionZ();

                        Position const pos = { l_X, l_Y, l_Z, l_O };
                        target->ExitVehicle(&pos);
                        return;
                    }
                }

                target->ExitVehicle();
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_highmaul_impale_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_impale_AuraScript();
        }
};

/// Fire Pillar Steam Timer - 163967
class spell_highmaul_fire_pillar_steam_timer : public SpellScriptLoader
{
    public:
        spell_highmaul_fire_pillar_steam_timer() : SpellScriptLoader("spell_highmaul_fire_pillar_steam_timer") { }

        enum eSpell
        {
            FirePillarSteamCosmetic = 163970
        };

        class spell_highmaul_fire_pillar_steam_timer_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_fire_pillar_steam_timer_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                if (target == nullptr)
                    return;

                target->CastSpell(target, eSpell::FirePillarSteamCosmetic, true);
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_highmaul_fire_pillar_steam_timer_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_fire_pillar_steam_timer_AuraScript();
        }
};

/// Fire Pillar Activated - 159706
class spell_highmaul_fire_pillar_activated : public SpellScriptLoader
{
    public:
        spell_highmaul_fire_pillar_activated() : SpellScriptLoader("spell_highmaul_fire_pillar_activated") { }

        class spell_highmaul_fire_pillar_activated_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_fire_pillar_activated_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                if (target == nullptr)
                    return;

                if (Creature* l_Pillar = target->ToCreature())
                {
                    if (l_Pillar->IsAIEnabled)
                        l_Pillar->AI()->DoAction(0);
                }
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_highmaul_fire_pillar_activated_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_fire_pillar_activated_AuraScript();
        }
};

/// Fire Pillar (Flame gout searcher) - 162576
class spell_highmaul_fire_pillar_gout_searcher : public SpellScriptLoader
{
public:
    spell_highmaul_fire_pillar_gout_searcher() : SpellScriptLoader("spell_highmaul_fire_pillar_gout_searcher") { }

    class spell_highmaul_fire_pillar_gout_searcher_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_highmaul_fire_pillar_gout_searcher_SpellScript);

        enum eSpells
        {
            Obscured = 160131
        };

        void CorrectTargets(std::list<WorldObject*>& targets)
        {
            targets.remove_if(Trinity::UnitAuraCheck(true, eSpells::Obscured));

            if (!targets.empty())
            {
                targets.remove_if([](WorldObject* p_Object) -> bool
                {
                    return !p_Object || !p_Object->IsPlayer() || p_Object->GetPositionZ() >= 62.4f;
                });
            }

            if (targets.size() > 5)
                Trinity::Containers::RandomResize(targets, 5);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_highmaul_fire_pillar_gout_searcher_SpellScript::CorrectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_highmaul_fire_pillar_gout_searcher_SpellScript();
    }
};

/// Berserker Rush - 159028
class spell_highmaul_berserker_rush : public SpellScriptLoader
{
    public:
        spell_highmaul_berserker_rush() : SpellScriptLoader("spell_highmaul_berserker_rush") { }

        enum eAction
        {
            InterruptByPillar = 4
        };

        enum eSpell
        {
            BerserkerRushIncrease = 159029
        };

        class spell_highmaul_berserker_rush_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_berserker_rush_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                if (target == nullptr)
                    return;

                AuraRemoveMode l_RemoveMode = GetTargetApplication()->GetRemoveMode();

                if (Creature* l_Kargath = target->ToCreature())
                {
                    if (l_Kargath->IsAIEnabled && l_RemoveMode != AuraRemoveMode::AURA_REMOVE_BY_EXPIRE)
                        l_Kargath->AI()->DoAction(eAction::InterruptByPillar);
                    else if (l_Kargath->IsAIEnabled)
                    {
                        if (boss_kargath_bladefist::boss_kargath_bladefistAI* l_AI = CAST_AI(boss_kargath_bladefist::boss_kargath_bladefistAI, l_Kargath->GetAI()))
                        {
                            if (Unit* l_Victim = ObjectAccessor::GetUnit(*l_Kargath, l_AI->m_BerserkerRushTarget))
                                l_AI->EndBerserkerRush(l_Victim);
                        }
                    }

                    l_Kargath->RemoveAura(eSpell::BerserkerRushIncrease);
                }
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_highmaul_berserker_rush_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_berserker_rush_AuraScript();
        }
};

/// Chain Hurl - 159947
class spell_highmaul_chain_hurl : public SpellScriptLoader
{
    public:
        spell_highmaul_chain_hurl() : SpellScriptLoader("spell_highmaul_chain_hurl") { }

        enum eDatas
        {
            MaxAffectedTargets  = 5,
            SpellObscured       = 160131,
            OpenWounds          = 159178,
            MaxLFRHealer        = 1,
            MaxLFRDamagers      = 3,
            MaxLFRTank          = 1
        };

        class spell_highmaul_chain_hurl_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_highmaul_chain_hurl_SpellScript);

            uint8 m_Count;
            ObjectGuid m_Targets[eDatas::MaxAffectedTargets];

            bool Load() override
            {
                m_Count = 0;

                for (uint8 l_I = 0; l_I < eDatas::MaxAffectedTargets; ++l_I)
                    m_Targets[l_I] = ObjectGuid::Empty;

                return true;
            }

            bool TargetsAlreadySelected() const
            {
                bool l_Return = false;
                for (uint8 l_I = 0; l_I < m_Count; ++l_I)
                {
                    if (!m_Targets[l_I])
                        return false;

                    l_Return = true;
                }

                return l_Return;
            }

            void ProcessLFRTargetting(std::list<WorldObject*>& targets, std::list<Player*> playerList)
            {
                std::list<Player*> l_TanksList      = playerList;
                std::list<Player*> l_HealersList    = playerList;
                std::list<Player*> l_DamagersList   = playerList;

                uint8 l_OpenWoundsStacks = 0;
                l_TanksList.remove_if([&l_OpenWoundsStacks](Player* player) -> bool
                {
                    if (player->GetRoleForGroup() != Roles::ROLE_TANK)
                        return true;

                    if (player->HasAura(eDatas::SpellObscured))
                        return true;

                    if (Aura* l_OpenWounds = player->GetAura(eDatas::OpenWounds))
                    {
                        if (l_OpenWounds->GetStackAmount() > l_OpenWoundsStacks)
                            l_OpenWoundsStacks = l_OpenWounds->GetStackAmount();
                    }

                    return false;
                });

                if (!l_TanksList.empty())
                {
                    l_TanksList.remove_if([l_OpenWoundsStacks](Player* player) -> bool
                    {
                        if (player->GetRoleForGroup() != Roles::ROLE_TANK)
                            return true;

                        if (player->HasAura(eDatas::SpellObscured))
                            return true;

                        if (Aura* l_OpenWounds = player->GetAura(eDatas::OpenWounds))
                        {
                            if (l_OpenWounds->GetStackAmount() != l_OpenWoundsStacks)
                                return true;
                        }

                        return false;
                    });
                }

                /// Just in case of all tanks have the same amount of Open Wounds
                if (!l_TanksList.empty() && l_TanksList.size() > eDatas::MaxLFRTank)
                    Trinity::Containers::RandomResize(l_TanksList, eDatas::MaxLFRTank);

                l_HealersList.remove_if([](Player* player) -> bool
                {
                    if (player->GetRoleForGroup() != Roles::ROLE_HEALER)
                        return true;

                    if (player->HasAura(eDatas::SpellObscured))
                        return true;

                    return false;
                });

                if (!l_HealersList.empty() && l_HealersList.size() > eDatas::MaxLFRHealer)
                    Trinity::Containers::RandomResize(l_HealersList, eDatas::MaxLFRHealer);

                l_DamagersList.remove_if([](Player* player) -> bool
                {
                    if (player->GetRoleForGroup() != Roles::ROLE_DAMAGE)
                        return true;

                    if (player->HasAura(eDatas::SpellObscured))
                        return true;

                    return false;
                });

                if (!l_DamagersList.empty() && l_DamagersList.size() > eDatas::MaxLFRDamagers)
                    Trinity::Containers::RandomResize(l_DamagersList, eDatas::MaxLFRDamagers);

                m_Count = 0;

                for (Player* player : l_TanksList)
                {
                    targets.push_back(player);
                    m_Targets[m_Count] = player->GetGUID();
                    ++m_Count;
                }

                for (Player* player : l_HealersList)
                {
                    targets.push_back(player);
                    m_Targets[m_Count] = player->GetGUID();
                    ++m_Count;
                }

                for (Player* player : l_DamagersList)
                {
                    targets.push_back(player);
                    m_Targets[m_Count] = player->GetGUID();
                    ++m_Count;
                }
            }

            void CorrectTargets(std::list<WorldObject*>& targets)
            {
                targets.clear();

                Unit* caster = GetCaster();
                if (caster == nullptr)
                    return;

                if (TargetsAlreadySelected())
                {
                    for (uint8 l_I = 0; l_I < m_Count; ++l_I)
                    {
                        /// Spell has SPELL_ATTR3_ONLY_TARGET_PLAYERS
                        if (WorldObject* l_Object = ObjectAccessor::GetPlayer(*caster, m_Targets[l_I]))
                            targets.push_back(l_Object);
                    }

                    return;
                }

                std::list<Player*> playerList;
                caster->GetPlayerListInGrid(playerList, 300.0f);

                if (playerList.empty())
                    return;

                playerList.remove_if(Trinity::UnitAuraCheck(true, eDatas::SpellObscured));

                if (playerList.empty())
                    return;

                /// In Looking for Raid difficulty, Kargath automatically tosses the tank with the highest amount of Open Wounds stacks,
                /// One random healer, and three random DPS into the crowd.
                if (caster->GetMap() && caster->GetMap()->IsLFR())
                    ProcessLFRTargetting(targets, playerList);
                /// Kargath uses his chain to lash the 5 closest enemies and toss them into the arena's stands.
                else
                {
                    playerList.sort(Trinity::ObjectDistanceOrderPred(caster));

                    m_Count = 0;
                    for (Player* player : playerList)
                    {
                        if (m_Count >= eDatas::MaxAffectedTargets)
                            break;

                        m_Targets[m_Count] = player->GetGUID();
                        targets.push_back(player);
                        ++m_Count;
                    }
                }

                if (targets.size() > eDatas::MaxAffectedTargets)
                    Trinity::Containers::RandomResize(targets, eDatas::MaxAffectedTargets);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_highmaul_chain_hurl_SpellScript::CorrectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_highmaul_chain_hurl_SpellScript::CorrectTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_highmaul_chain_hurl_SpellScript::CorrectTargets, EFFECT_2, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_highmaul_chain_hurl_SpellScript();
        }
};

/// Vile Breath - 160521
class spell_highmaul_vile_breath : public SpellScriptLoader
{
    public:
        spell_highmaul_vile_breath() : SpellScriptLoader("spell_highmaul_vile_breath") { }

        class spell_highmaul_vile_breath_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_highmaul_vile_breath_SpellScript);

            enum eSpell
            {
                TargetRestrict = 20321
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
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_highmaul_vile_breath_SpellScript::CorrectTargets, EFFECT_0, TARGET_UNIT_CONE_ENTRY_110);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_highmaul_vile_breath_SpellScript();
        }
};

/// Obscured - 160131
class spell_highmaul_obscured : public SpellScriptLoader
{
    public:
        spell_highmaul_obscured() : SpellScriptLoader("spell_highmaul_obscured") { }

        class spell_highmaul_obscured_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_obscured_AuraScript);

            uint32 m_UpdateTimer;

            bool Load() override
            {
                m_UpdateTimer = 8000;
                return true;
            }

            void OnUpdate(uint32 diff)
            {
                if (m_UpdateTimer)
                {
                    if (m_UpdateTimer > diff)
                    {
                        m_UpdateTimer -= diff;
                        return;
                    }
                    else
                        m_UpdateTimer = 0;
                }

                if (Unit* target = GetUnitOwner())
                {
                    /// Target is not in Arena's stands anymore
                    if (target->GetPositionZ() <= g_InArenaZ)
                        GetAura()->Remove();
                }
            }

            void Register() override
            {
                OnAuraUpdate += AuraUpdateFn(spell_highmaul_obscured_AuraScript::OnUpdate);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_obscured_AuraScript();
        }
};

/// Crowd Minion Killed - 163392
class spell_highmaul_crowd_minion_killed : public SpellScriptLoader
{
    public:
        spell_highmaul_crowd_minion_killed() : SpellScriptLoader("spell_highmaul_crowd_minion_killed") { }

        class spell_highmaul_crowd_minion_killed_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_highmaul_crowd_minion_killed_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (Unit* caster = GetCaster())
                    caster->EnergizeBySpell(caster, GetSpellInfo()->Id, 1, Powers::POWER_ALTERNATE_POWER);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_highmaul_crowd_minion_killed_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_highmaul_crowd_minion_killed_SpellScript();
        }
};

/// Roar of the Crowd - 163302
class spell_highmaul_roar_of_the_crowd : public SpellScriptLoader
{
    public:
        spell_highmaul_roar_of_the_crowd() : SpellScriptLoader("spell_highmaul_roar_of_the_crowd") { }

        enum eSpells
        {
            CrowdFavorite25     = 163366,   ///< Mod damage PCT done, and mod pet damage PCT done
            CrowdFavorite50     = 163368,   ///< Mod damage PCT done, and mod pet damage PCT done
            CrowdFavorite75     = 163369,   ///< Mod damage PCT done, and mod pet damage PCT done
            CrowdFavorite100    = 163370    ///< Mod damage PCT done, and mod pet damage PCT done
        };

        enum eDatas
        {
            Favor25     = 25,
            Favor50     = 50,
            Favor75     = 75,
            Favor100    = 100
        };

        class spell_highmaul_roar_of_the_crowd_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_roar_of_the_crowd_AuraScript);

            void OnTick(AuraEffect const* /*aurEff*/)
            {
                if (Unit* caster = GetCaster())
                {
                    int32 l_Favor = caster->GetPower(Powers::POWER_ALTERNATE_POWER);

                    /// 0 ... 24
                    if (l_Favor < eDatas::Favor25)
                    {
                        caster->RemoveAura(eSpells::CrowdFavorite25);
                        caster->RemoveAura(eSpells::CrowdFavorite50);
                        caster->RemoveAura(eSpells::CrowdFavorite75);
                        caster->RemoveAura(eSpells::CrowdFavorite100);
                    }
                    /// 25 ... 49
                    else if (l_Favor < eDatas::Favor50)
                        caster->CastSpell(caster, eSpells::CrowdFavorite25, true);
                    /// 50 ... 74
                    else if (l_Favor < eDatas::Favor75)
                        caster->CastSpell(caster, eSpells::CrowdFavorite50, true);
                    /// 75 ... 99
                    else if (l_Favor < eDatas::Favor100)
                        caster->CastSpell(caster, eSpells::CrowdFavorite75, true);
                    /// 100
                    else
                        caster->CastSpell(caster, eSpells::CrowdFavorite100, true);
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_highmaul_roar_of_the_crowd_AuraScript::OnTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_roar_of_the_crowd_AuraScript();
        }
};

/// Inflamed - 163130
class spell_highmaul_inflamed : public SpellScriptLoader
{
    public:
        spell_highmaul_inflamed() : SpellScriptLoader("spell_highmaul_inflamed") { }

        enum eSpell
        {
            OnTheHunt = 162497
        };

        class spell_highmaul_inflamed_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_inflamed_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                if (target == nullptr)
                    return;

                if (Creature* l_Ravenous = target->ToCreature())
                {
                    l_Ravenous->GetMotionMaster()->Clear();
                    l_Ravenous->CastSpell(l_Ravenous, eSpell::OnTheHunt, false);
                }
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_highmaul_inflamed_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_inflamed_AuraScript();
        }
};

/// Heckle - 163408
class spell_highmaul_heckle : public SpellScriptLoader
{
    public:
        spell_highmaul_heckle() : SpellScriptLoader("spell_highmaul_heckle") { }

        class spell_highmaul_heckle_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_highmaul_heckle_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (Creature* caster = GetCaster()->ToCreature())
                    GrantFavorToAllPlayers(caster, -2, GetSpellInfo()->Id);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_highmaul_heckle_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_highmaul_heckle_SpellScript();
        }
};

/// Berserker Rush - 159001
class spell_highmaul_berserker_rush_periodic : public SpellScriptLoader
{
    public:
        spell_highmaul_berserker_rush_periodic() : SpellScriptLoader("spell_highmaul_berserker_rush_periodic") { }

        class spell_highmaul_berserker_rush_periodic_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_berserker_rush_periodic_AuraScript);

            void OnTick(AuraEffect const* aurEff)
            {
                if (Creature* caster = GetTarget()->ToCreature())
                {
                    if (!caster->GetMap()->IsMythic())
                        return;

                    /// Grants one point of Favor every second
                    if (aurEff->GetTickNumber() % 2)
                        GrantFavorToAllPlayers(caster, 1, GetSpellInfo()->Id);
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_highmaul_berserker_rush_periodic_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_berserker_rush_periodic_AuraScript();
        }
};

/// Blade Dance (periodic triggered) - 159212
class spell_highmaul_blade_dance : public SpellScriptLoader
{
    public:
        spell_highmaul_blade_dance() : SpellScriptLoader("spell_highmaul_blade_dance") { }

        enum eSpell
        {
            Obscured = 160131
        };

        class spell_highmaul_blade_dance_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_highmaul_blade_dance_SpellScript);

            void CorrectTargets(std::list<WorldObject*>& targets)
            {
                Unit* caster = GetCaster();
                if (caster == nullptr)
                    return;

                targets.clear();

                std::list<Player*> playerList;
                caster->GetPlayerListInGrid(playerList, 300.0f);

                if (playerList.empty())
                    return;

                playerList.remove_if([](Player* player) -> bool
                {
                    if (player->GetRoleForGroup() == Roles::ROLE_TANK)
                        return true;

                    if (player->HasAura(eSpell::Obscured))
                        return true;

                    return false;
                });

                if (playerList.empty())
                    return;

                std::list<Player*> l_SnapShot;

                playerList.remove_if([caster, &l_SnapShot](Player* player) -> bool
                {
                    if (caster->GetDistance(player) <= 10.0f)
                    {
                        l_SnapShot.push_back(player);
                        return true;
                    }

                    return false;
                });

                if (playerList.empty() && !l_SnapShot.empty())
                    playerList = l_SnapShot;

                Trinity::Containers::RandomResize(playerList, 1);
                targets.push_back(playerList.front());
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_highmaul_blade_dance_SpellScript::CorrectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_highmaul_blade_dance_SpellScript();
        }
};

/// Berserker Rush - 163180
/// Mauling Brew - 159410
/// Iron Bomb - 159386
class spell_highmaul_correct_searchers : public SpellScriptLoader
{
    public:
        spell_highmaul_correct_searchers() : SpellScriptLoader("spell_highmaul_correct_searchers") { }

        enum eSpells
        {
            Obscured        = 160131,
            IronBomb        = 159386,
            BerserkerRush   = 163180
        };

        class spell_highmaul_correct_searchers_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_highmaul_correct_searchers_SpellScript);

            void CorrectTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(Trinity::UnitAuraCheck(true, eSpells::Obscured));

                if (GetSpellInfo()->Id == eSpells::BerserkerRush && !targets.empty())
                {
                    Unit* caster = GetCaster();

                    targets.remove_if([](WorldObject* p_Object) -> bool
                    {
                        if (p_Object == nullptr || !p_Object->IsPlayer())
                            return true;

                        if (Player* player = p_Object->ToPlayer())
                        {
                            /*if (!player->IsRangedDamageDealer())
                                return true;*/

                            if (player->GetPositionZ() >= 63.4f)
                                return true;
                        }

                        return false;
                    });

                    /// Kargath will target one of the three furthest targets and chase them till he either kills the player.
                    if (caster->GetMap()->IsMythic())
                    {
                        targets.sort(Trinity::DistanceCompareOrderPred(caster, false));

                        uint8 l_Count = 0;
                        std::list<WorldObject*> l_NewTargets;

                        for (WorldObject* itr : targets)
                        {
                            if (l_Count >= 3)
                                break;

                            l_NewTargets.push_back(itr);
                            ++l_Count;
                        }

                        targets.clear();

                        if (!l_NewTargets.empty())
                            Trinity::Containers::RandomResize(l_NewTargets, l_Count);

                        if (!l_NewTargets.empty())
                            targets.push_back(l_NewTargets.front());
                    }
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_highmaul_correct_searchers_SpellScript::CorrectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);

                if (m_scriptSpellId == eSpells::IronBomb)
                    OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_highmaul_correct_searchers_SpellScript::CorrectTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_highmaul_correct_searchers_SpellScript();
        }
};

/// Molten Bomb - 161634
class areatrigger_highmaul_molten_bomb : public AreaTriggerAI
{
public:
    areatrigger_highmaul_molten_bomb(AreaTrigger* areaTrigger) : AreaTriggerAI(areaTrigger) { }

    enum eSpell
    {
        MoltenBomb = 161635
    };

    std::set<ObjectGuid> m_AffectedPlayers;

    void OnUpdate(uint32 /*diff*/) override
    {
        if (Unit* caster = at->GetCaster())
        {
            std::list<Unit*> targetList;
            float radius = 3.0f;

            Trinity::AnyUnfriendlyUnitInObjectRangeCheck l_Check(at, caster, radius);
            Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> l_Searcher(at, targetList, l_Check);
            Cell::VisitAllObjects(at, l_Searcher, radius);

            std::set<ObjectGuid> targets;

            for (Unit* itr : targetList)
            {
                targets.insert(itr->GetGUID());

                if (!itr->HasAura(eSpell::MoltenBomb, caster->GetGUID()))
                {
                    m_AffectedPlayers.insert(itr->GetGUID());
                    itr->CastSpell(itr, eSpell::MoltenBomb, true);
                }
            }

            for (std::set<ObjectGuid>::iterator itr = m_AffectedPlayers.begin(); itr != m_AffectedPlayers.end();)
            {
                if (targets.find((*itr)) != targets.end())
                {
                    ++itr;
                    continue;
                }

                if (Unit* l_Unit = ObjectAccessor::GetUnit(*caster, (*itr)))
                {
                    itr = m_AffectedPlayers.erase(itr);
                    l_Unit->RemoveAura(eSpell::MoltenBomb, caster->GetGUID());

                    continue;
                }

                ++itr;
            }
        }
    }

    void OnRemove() override
    {
        if (Unit* caster = at->GetCaster())
        {
            for (ObjectGuid guid : m_AffectedPlayers)
            {
                if (Unit* l_Unit = ObjectAccessor::GetUnit(*caster, guid))
                    l_Unit->RemoveAura(eSpell::MoltenBomb, caster->GetGUID());
            }
        }
    }
};



/// Flame Jet - 159202
class areatrigger_highmaul_flame_jet : public AreaTriggerAI
{
public:
    areatrigger_highmaul_flame_jet(AreaTrigger* areaTrigger) : AreaTriggerAI(areaTrigger) { }

    enum eSpells
    {
        FlameJet            = 159311,
        BerserkerRushAura   = 159028,
        Obscured            = 160131
    };

    enum eCreature
    {
        RavenousBloodmaw = 79296
    };

    enum eAction
    {
        InterruptRavenous = 1
    };

    void OnUnitEnter(Unit* unit) override
    {
        if (at->GetCaster() == unit)
            return;

        /// Don't add DoT on targets in vehicle (Chain Hurl or Impale)
        if (!unit->IsOnVehicle() && unit->GetEntry() != eHighmaulCreatures::KargathBladefist)
            at->GetCaster()->CastSpell(unit, eSpells::FlameJet, true);

        if (unit->GetEntry() == eHighmaulCreatures::KargathBladefist)
        {
            if (unit->HasAura(eSpells::BerserkerRushAura))
                unit->RemoveAura(eSpells::BerserkerRushAura, unit->GetGUID(), 0, AuraRemoveMode::AURA_REMOVE_BY_ENEMY_SPELL);
        }

        if (unit->GetEntry() == eCreature::RavenousBloodmaw)
        {
            if (unit->IsAIEnabled)
                unit->ToCreature()->AI()->DoAction(eAction::InterruptRavenous);
        }
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAura(eSpells::FlameJet);
    }

    void OnUpdate(uint32 /*diff*/) override
    {
        std::unordered_set<ObjectGuid> insideUnits = at->GetInsideUnits();

        for (ObjectGuid insideUnit : insideUnits)
        {
            if (Unit* l_Unit = ObjectAccessor::GetUnit(*at->GetCaster(), insideUnit))
                if (l_Unit->IsOnVehicle() || l_Unit->HasAura(eSpells::Obscured))
                    if (l_Unit->HasAura(eSpells::FlameJet))
                        l_Unit->RemoveAura(eSpells::FlameJet);
        }
    }
};

/// Mauling Brew - 159412
class areatrigger_highmaul_mauling_brew : public AreaTriggerAI
{
public:
    areatrigger_highmaul_mauling_brew(AreaTrigger* areaTrigger) : AreaTriggerAI(areaTrigger) { }

    enum eSpells
    {
        MaulingBrew = 159413
    };

    void OnUpdate(uint32 /*diff*/) override
    {
        if (Unit* caster = at->GetCaster())
        {
            std::list<Unit*> targetList;
            float radius = 3.0f;

            Trinity::AnyUnfriendlyUnitInObjectRangeCheck l_Check(at, caster, radius);
            Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> l_Searcher(at, targetList, l_Check);
            Cell::VisitAllObjects(at, l_Searcher, radius);

            for (Unit* l_Unit : targetList)
            {
                if (l_Unit->IsOnVehicle())
                    continue;

                caster->CastSpell(l_Unit, eSpells::MaulingBrew, true);
            }
        }
    }
};

/// Mauling Brew - 159410
class spell_kargath_mauling_brew : public SpellScriptLoader
{
public:
    spell_kargath_mauling_brew() : SpellScriptLoader("spell_kargath_mauling_brew") { }

    class spell_kargath_mauling_brew_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_kargath_mauling_brew_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
                if (Unit* target = GetExplTargetUnit())
                    caster->CastSpell(target, GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_kargath_mauling_brew_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_kargath_mauling_brew_SpellScript();
    }
};

class spell_chain_hurl_tempfix : public SpellScriptLoader
{
public:
    spell_chain_hurl_tempfix() : SpellScriptLoader("spell_chain_hurl_tempfix") { }

    class spell_chain_hurl_tempfix_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_chain_hurl_tempfix_AuraScript);

        enum eSpells
        {
            ChainHurlJumpDest   = 159995,
            Obscured            = 160131,
            Chain               = 159531,
            FlameJetDoT         = 159311
        };

        bool Load()
        {
            return true;
        }

        void ApplyEffect(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            PreventDefaultAction();

            Unit* caster = GetCaster();

            if (!caster)
                return;

            caster->CastSpell(g_ArenaStandsPos, eSpells::ChainHurlJumpDest, true);
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(spell_chain_hurl_tempfix_AuraScript::ApplyEffect, EFFECT_0, SPELL_AURA_CONTROL_VEHICLE, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_chain_hurl_tempfix_AuraScript();
    }
};

void AddSC_boss_kargath_bladefist()
{
    /// Boss
    new boss_kargath_bladefist();

    /// NPCs
    new npc_highmaul_vulgor();
    new npc_highmaul_bladespire_sorcerer();
    new npc_highmaul_somldering_stoneguard();
    new npc_highmaul_fire_pillar();
    new npc_highmaul_ravenous_bloodmaw();
    new npc_highmaul_kargath_bladefist_trigger();
    new npc_highmaul_drunken_bileslinger();
    new npc_highmaul_iron_bomber();
    new npc_highmaul_iron_grunt();
    new npc_highmaul_iron_grunt_second();
    new npc_highmaul_ogre_grunt();
    new npc_highmaul_ogre_grunt_second();
    new npc_highmaul_highmaul_sweeper();
    new npc_highmaul_chain_hurl_vehicle();
    new npc_highmauareaTrigger_for_crowd();

    /// Spells
    new spell_highmaul_earth_breaker();
    new spell_highmaul_impale();
    new spell_highmaul_fire_pillar_steam_timer();
    new spell_highmaul_fire_pillar_activated();
    new spell_highmaul_fire_pillar_gout_searcher();
    new spell_highmaul_berserker_rush();
    new spell_highmaul_chain_hurl();
    new spell_highmaul_vile_breath();
    new spell_highmaul_obscured();
    new spell_highmaul_crowd_minion_killed();
    new spell_highmaul_roar_of_the_crowd();
    new spell_highmaul_inflamed();
    new spell_highmaul_heckle();
    new spell_highmaul_berserker_rush_periodic();
    new spell_highmaul_blade_dance();
    new spell_highmaul_correct_searchers();
    new spell_kargath_mauling_brew();
    new spell_chain_hurl_tempfix();

    /// AreaTriggers
    RegisterAreaTriggerAI(areatrigger_highmaul_molten_bomb);
    RegisterAreaTriggerAI(areatrigger_highmaul_flame_jet);
    RegisterAreaTriggerAI(areatrigger_highmaul_mauling_brew);
}
