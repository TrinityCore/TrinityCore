/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "CreatureTextMgr.h"

Position const g_GorianReaverPos = { 4026.755f, 8584.76f, 572.6546f, 3.138298f };

/// For position Z periodical check
float const g_MinAllowedZ = 560.0f;

Position const g_CenterPos = { 3917.63f, 8590.89f, 565.341f, 0.0f };

Position const g_VolatileAnomalyPos[eHighmaulDatas::MaxIntervalles] =
{
    { 3885.65f, 8557.80f, 565.34f, 0.747137f }, ///< Rune of Fortification
    { 3890.47f, 8628.17f, 565.34f, 5.375480f }  ///< Rune of Replication
};

Position const g_ChogallEventsPos[] =
{
    { 3986.499023f, 8590.89f,   568.160156f,    3.1415627f },   ///< Cho'gall spawn pos
    { 3953.253662f, 8590.89f,   565.339722f,    3.1415627f },   ///< Cho'gall end pos
    { 3917.63f,     8590.89f,   575.341f,       0.0f },         ///< Mar'gok levitating pos
    { 3921.533203f, 8664.4102f, 565.555603f,    4.554723f },     ///< Adds Spawn right
    { 3912.581543f, 8517.3955f, 565.555603f,    1.523083f },     ///< Adds Spawn left
};

/*
@TODO:
- Ajouter le MM pour les NPCs (les getdata des ePhases)
- faire des fonctions pour les d?placements vers les runes (gain de place dans le code), faire des tableaux pour les positions/dialogues/... index?s sur l'id de la rune
- visuel des runes activ?es sur le SLG generic : 
    d?placement   : visu : 174026
    reproduction  : visu du socl : 174044
    fortification : visual du socle : 174043
    nullification : visuel du socle : 178559
- spawn rune of nullification on chogall encounter (id:233125)
- check la vie des adds +boss en MM
- test Infinite Darkness shield - 165102
*/

/// Imperator Mar'gok <Sorcerer King> - 77428
class boss_imperator_margok : public CreatureScript
{
    public:
        boss_imperator_margok() : CreatureScript("boss_imperator_margok") { }

        enum eSpells
        {
            /// Cosmetic
            CosmeticSitThrone                       = 88648,
            TeleportOffThrone                       = 166090,
            TeleportToDisplacement                  = 164336,
            TeleportToFortification                 = 164751,
            TeleportToReplication                   = 164810,
            EncounterEvent                          = 181089,   ///< Sniffed, don't know why, related to phases switch ?
            TransitionVisualPhase2                  = 176576,
            TransitionVisualPhase3                  = 176578,
            TransitionVisualPhase4                  = 176579,
            TransitionVisualPeriodic                = 176580,
            PowerOfDisplacement                     = 158013,
            PowerOfFortification                    = 158012,
            PowerOfReplication                      = 157964,
            DisplacementTransform                   = 174020,
            FortificationTransform                  = 174022,
            DisplacementTransform2                  = 174023,
            ArcaneProtection                        = 174057,
            AwakenRunestone                         = 157278,
            FortificationBaseVisual                 = 174043,
            FortificationAchievement                = 143809,
            FortificationRuneActive                 = 166429,
            ReplicationBaseVisual                   = 174044,
            ReplicationAchievement                  = 166391,
            ReplicationRuneActive                   = 174085,
            SummonRuneVisual                        = 160351,
            SummonWarmage                           = 160366,
            VolatileAnomalies                       = 157265,
            ImperatorMargokBonus                    = 177528,
            /// Mark of Chaos
            MarkOfChaosAura                         = 158605,
            MarkOfChaosCosmetic                     = 164161,
            MarkOfChaosDisplacementAura             = 164176,
            MarkOfChaosFortificationAura            = 164178,
            FetterMarkOfChaosRootAura               = 158619,
            MarkOfChaosReplicationAura              = 164191,
            OrbsOfChaosDummyAura                    = 160447,
            /// AcceleratedAssault
            AcceleratedAssault                      = 159515,
            /// Arcane Aberration
            SummonArcaneAberrationCast              = 156471,
            SummonArcaneAberrationCosmetic          = 164318,   ///< Sniffed, but I don't know why
            SummonDisplacingArcaneAberration        = 164299,
            SummonFortifiedArcaneAberration         = 164301,
            SummonReplicatingArcaneAberration       = 164303,
            /// Destructive Resonance
            DestructiveResonanceDebuff              = 159200,
            DestructiveResonanceSearcher            = 156467,
            DestructiveResonanceCosmetic            = 164074,   ///< Sniffed, but I don't know why
            DestructiveResonanceSummon              = 156734,
            DestructiveResonanceDisplacementSearch  = 164075,
            DestructiveResonanceFortificationSearch = 164076,
            DestructiveResonanceReplicationSearch   = 164077,
            /// Arcane Wrath
            ArcaneWrathSearcher                     = 156238,
            ArcaneWrathCosmetic                     = 163968,   ///< Sniffed, but I don't know why
            ArcaneWrathBranded                      = 156225,
            ArcaneWrathDisplacementSearcher         = 163988,
            ArcaneWrathBrandedDisplacement          = 164004,
            ArcaneWrathFortificationSearcher        = 163989,
            ArcaneWrathBrandedFortification         = 164005,
            ArcaneWrathReplicationSearcher          = 163990,
            ArcaneWrathBrandedReplication           = 164006,
            /// Force Nova
            ForceNovaCasting                        = 157349,   ///< CastTime
            ForceNovaScriptEffect                   = 164227,   ///< Sniffed, but I don't know why
            ForceNovaDummy                          = 157320,   ///< Visual effect of the nova
            ForceNovaDoT                            = 157353,
            ForceNovaKnockBack                      = 157325,
            ForceNovaDisplacement                   = 164232,   ///< CastTime
            ForceNovaDisplacementDummy              = 164252,   ///< Visual effect of the nova
            ForceNovaAreaTrigger                    = 157327,   ///< Triggers knock back too
            ForceNovaFortificationCasting           = 164235,   ///< Cast Time
            ForceNovaFortifiedPeriodicAura          = 157323,   ///< 8s periodic for Phase 3
            ForceNovaFortificationDummy             = 164253,
            ForceNovaReplicationCasting             = 164240,   ///< CastTime
            ForceNovaReplicationDummy               = 164254,   ///< Visual effect
            /// Misc
            SpellGrowingShadowsAT                   = 176525,
            SpellGrowingShadowsDmg                  = 176533
        };

        enum eEvents
        {
            EventMarkOfChaos = 1,
            EventForceNova,
            EventArcaneWrath,
            EventDestructiveResonance,
            EventArcaneAberration,
            EventBerserk
        };

        enum eCosmeticEvents
        {
            EventSummonWarmages = 1,
            EventCheckPlayerZ,
            EventCheckRuneCosmetic
        };

        enum eActions
        {
            ActionIntro,
            ActionFinishIntro,
            ActionCancelAllEvents
        };

        enum eCreatures
        {
            SorcererKingVisualPoint = 89081,
            NpcRuneOfDisplacement   = 77429,
            SLGGenericMoPLargeAoI   = 68553,
            WarmageSummonStalker    = 77682,
            GorianWarmage           = 78121,
            VolatileAnomaly         = 78077,
            GorianReaver            = 78549,
            ArcaneRemnant           = 79388,
            NpcNightTwistedFaithful = 78641,
            NpcGlimpseOfMadness     = 82242
        };

        enum eTalks
        {
            Intro1,
            Intro2,
            Intro3,
            Aggro,
            ForceNova,
            MarkOfChaos,
            ArcaneWrath,
            ArcaneAberration,
            TalkRuneOfDisplacement,
            TalkRuneOfFortification1,
            TalkRuneOfFortification2,
            TalkRuneOfFortification3,
            TalkRuneOfFortification4,
            TalkRuneOfFortification5,
            TalkRuneOfReplication1,
            TalkRuneOfReplication2,
            TalkRuneOfReplication3,
            TalkRuneOfReplication4,
            Slay,
            Berserk,
            Death,
            Branded,
            ///< Mythic
            TalkChoGallTreason = 23,
        };

        enum eAnimKit
        {
            AnimKitFlyingRune = 6420
        };

        enum eMoves
        {
            MoveUp = 1,
            MoveDown
        };

        enum eDatas
        {
            /// Values datas
            BrandedStacks,
            PhaseID,
            OrbOfChaosAngle,
            /// Misc
            MaxVisualPoint  = 8,
            MaxNovaPhase3   = 3
        };

        enum ePhases
        {
            MightOfTheCrown = 1,    ///< Phase 1: Might of the Crown
            RuneOfDisplacement,     ///< Phase 2: Rune of Displacement
            DormantRunestones,      ///< Intermission: Dormant Runestones
            RuneOfFortification,    ///< Phase 3: Rune of Fortification
            LineageOfPower,         ///< Intermission: Lineage of Power
            RuneOfReplication,      ///< Phase 4: Rune of Replication

            MythicPhase1,           ///< Phase 1: Rune of Displacement + Rune of Replication, all spells are displayed as the "Rune of Displacement" ones
            MythicTransition1,      ///< Intermission: Dormant Runestones (same as NM/HM), Rune of Displacement effects activated active
            MythicPhase2,           ///< Phase 2: Rune of Displacement + Rune of Fortification, all spells are displayed as the "Rune of Fortification" ones
            MythicTransition2,      ///< Intermission: Lineage of Power (same as NM/HM), Rune of Fortification active
            MythicPhase3,           ///< Phase 3: Rune of Replication + Rune of Fortification, all spells are displayed as the "Rune of Replication" ones
            MythicPhase4ChoGall,    ///< Phase 4: Cho'gall event

            MaxPhase                = 7,
            MythicMaxPhase          = 13,
        };

        struct boss_imperator_margokAI : public BossAI
        {
            boss_imperator_margokAI(Creature* creature) : BossAI(creature, eHighmaulDatas::BossImperatorMargok), m_Vehicle(creature->GetVehicleKit())
            {
                m_Instance = creature->GetInstanceScript();

                g_SwitchPhasePcts[ePhases::MightOfTheCrown - 1]     = 85;   ///< Phase One lasts from 100 % to 85 % of Mar'gok's health.
                g_SwitchPhasePcts[ePhases::RuneOfDisplacement - 1]  = 55;   ///< Phase Two lasts from 85 % to 55 % of Mar'gok's health.
                g_SwitchPhasePcts[ePhases::DormantRunestones - 1]   = -1;   ///< The First Transition Phase lasts for 1 minute after the end of Phase Two.
                g_SwitchPhasePcts[ePhases::RuneOfFortification - 1] = 25;   ///< Phase Three lasts from 55 % of Mar'gok's health(end of the First Transition Phase) to 25 % of Mar'gok's health.
                g_SwitchPhasePcts[ePhases::LineageOfPower - 1]      = -1;   ///< The Second transition Phase lasts for 1 minute after the end of Phase Three.
                g_SwitchPhasePcts[ePhases::RuneOfReplication - 1]   = 0;    ///< Phase Four lasts from 25 % of Mar'gok's health(end of the Second Transition Phase) to Mar'gok's death.

                g_SwitchPhasePcts[ePhases::MythicPhase1 - 1]        = 66;   ///< Phase One lasts from 100 % to 66 % of Mar'gok's health.
                g_SwitchPhasePcts[ePhases::MythicTransition1 - 1]   = -1;   ///< The First Transition Phase lasts for 1 minute after the end of Phase Two.
                g_SwitchPhasePcts[ePhases::MythicPhase2 - 1]        = 33;   ///< Phase One lasts from 66 % to 33 % of Mar'gok's health.
                g_SwitchPhasePcts[ePhases::MythicTransition2 - 1]   = -1;   ///< The Second transition Phase lasts for 1 minute after the end of Phase Two.
                g_SwitchPhasePcts[ePhases::MythicPhase3 - 1]        =  5;   ///< Phase Three lasts from 33 % of Mar'gok's health(end of the First Transition Phase) to 5 % of Mar'gok's health.
                g_SwitchPhasePcts[ePhases::MythicPhase4ChoGall - 1] = -1;   ///< Phase Four lasts from 100 % of Cho'gall's health(end of the First Transition Phase) to 0 % of Cho'gall's health.
            }

            EventMap m_Events;
            EventMap m_CosmeticEvents;

            bool m_InCombat;

            uint8 m_Phase;
            uint8 g_SwitchPhasePcts[ePhases::MythicMaxPhase - 1];

            ObjectGuid m_MeleeTargetGuid;

            bool m_IsInNova;
            uint32 m_NovaTime;
            Position m_NovaPos;

            /// Force Nova datas for Phase 3: Rune of Fortification
            uint8 m_NovaCount;
            bool m_IsInNovaPhase3[eDatas::MaxNovaPhase3];
            uint32 m_NovaTimePhase3[eDatas::MaxNovaPhase3];
            Position m_NovaPosPhase3[eDatas::MaxNovaPhase3];

            uint8 m_OrbCount;

            Vehicle* m_Vehicle;
            InstanceScript* m_Instance;

            ObjectGuid m_NullificationRuneSummoned;

            void Reset() override
            {
                m_Events.Reset();
                m_CosmeticEvents.Reset();

                summons.DespawnAll();

                m_InCombat = false;

                m_Phase = IsMythic() ? ePhases::MythicPhase1 : ePhases::MightOfTheCrown;
                m_Events.SetPhase(m_Phase);

                m_MeleeTargetGuid = ObjectGuid::Empty;

                m_IsInNova  = false;
                m_NovaTime  = 0;
                m_NovaPos   = Position();
                m_NovaCount = 0;

                for (uint8 l_I = 0; l_I < eDatas::MaxNovaPhase3; ++l_I)
                {
                    m_IsInNovaPhase3[l_I] = false;
                    m_NovaTimePhase3[l_I] = 0;
                    m_NovaPosPhase3[l_I]  = Position();
                }

                m_OrbCount = 0;

                me->RemoveAura(eSpells::AcceleratedAssault);
                me->RemoveAura(eHighmaulSpells::Berserker);
                me->RemoveAura(eHighmaulSpells::PermanentFeignDeath);

                _Reset();

                AddTimedDelayedOperation(200, [this]() -> void
                {
                    me->CastSpell(me, eSpells::CosmeticSitThrone, true);

                    for (uint8 l_I = 0; l_I < eDatas::MaxVisualPoint; ++l_I)
                    {
                        if (Creature* l_Creature = me->SummonCreature(eCreatures::SorcererKingVisualPoint, *me))
                            l_Creature->EnterVehicle(me);
                    }
                });

                ResetRunes();
                DespawnAdds();

                me->RemoveUnitFlag2(UNIT_FLAG2_FEIGN_DEATH);
                me->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);

                m_CosmeticEvents.CancelEvent(EventCheckRuneCosmetic);
                m_CosmeticEvents.ScheduleEvent(EventCheckRuneCosmetic, 0);
            }

            void JustReachedHome() override
            {
                m_Events.Reset();
                m_Phase = IsMythic() ? ePhases::MythicPhase1 : ePhases::MightOfTheCrown;
            }

            bool CanRespawn() override
            {
                return false;
            }

            void JustSummoned(Creature* p_Summon) override
            {
                if (p_Summon->GetEntry() == eHighmaulCreatures::Chogall)
                {
                    p_Summon->AI()->DoAction(1); ///< Cho'gall intro
                    return; ///< don't add this unit to Margok summons lists
                }

                BossAI::JustSummoned(p_Summon);
            }

            void DoAction(int32 const action) override
            {
                switch (action)
                {
                    case eActions::ActionIntro:
                    {
                        AddTimedDelayedOperation(7 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                        {
                            Talk(eTalks::Intro1);
                        });

                        AddTimedDelayedOperation(20 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                        {
                            Talk(eTalks::Intro2);
                        });

                        break;
                    }
                    case eActions::ActionFinishIntro:
                    {
                        Talk(eTalks::Intro3);
                        break;
                    }
                    case eActions::ActionCancelAllEvents:
                    {
                        m_Events.Reset();
                        break;
                    }
                    case 100:
                    {
                        m_Phase = ePhases::MythicPhase4ChoGall;

                        if (IsMythic())
                            if (TempSummon* chogall = me->SummonCreature(eHighmaulCreatures::Chogall, g_ChogallEventsPos[0]))
                                chogall->AI()->DoAction(1); ///< Start Cho'gall event
                        break;
                    }
                    default:
                        break;
                }
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type != MovementGeneratorType::POINT_MOTION_TYPE)
                    return;

                switch (id)
                {
                    // Moves used for drainning runes
                    case eMoves::MoveUp:
                    {
                        if (Creature* l_Rune = me->FindNearestCreature(eCreatures::NpcRuneOfDisplacement, 40.0f))
                            l_Rune->CastSpell(l_Rune, eSpells::TransitionVisualPeriodic, true);

                        break;
                    }
                    case eMoves::MoveDown:
                    {
                        AddTimedDelayedOperation(200, [this]() -> void
                        {
                            me->RemoveUnitFlag2(UNIT_FLAG2_DISABLE_TURN);

                            me->SetAIAnimKitId(0);
                            //me->SetAnimTier(0);
                            me->SetDisableGravity(false);
                            me->SendSetPlayHoverAnim(false);
                            me->SetReactState(ReactStates::REACT_AGGRESSIVE);

                            me->RemoveAura(eSpells::TransitionVisualPhase2);
                            me->RemoveAura(eSpells::TransitionVisualPhase3);
                            me->RemoveAura(eSpells::TransitionVisualPhase4);

                            if (Creature* l_Rune = me->FindNearestCreature(eCreatures::NpcRuneOfDisplacement, 40.0f))
                            {
                                l_Rune->RemoveAura(eSpells::TransitionVisualPeriodic);

                                if (IsMythic())
                                {
                                    switch (m_Phase)
                                    {
                                    case ePhases::MythicTransition1:
                                    {
                                        l_Rune->CastSpell(l_Rune, eSpells::FortificationRuneActive, true);
                                        break;
                                    }
                                    case ePhases::MythicTransition2:
                                    {
                                        l_Rune->CastSpell(l_Rune, eSpells::ReplicationRuneActive, true);
                                        break;
                                    }
                                    default:
                                        break;
                                    }
                                }
                                else
                                {
                                    switch (m_Phase)
                                    {
                                    case ePhases::DormantRunestones:
                                    {
                                        l_Rune->CastSpell(l_Rune, eSpells::FortificationRuneActive, true);
                                        break;
                                    }
                                    case ePhases::LineageOfPower:
                                    {
                                        l_Rune->CastSpell(l_Rune, eSpells::ReplicationRuneActive, true);
                                        break;
                                    }
                                    default:
                                        break;
                                    }
                                }
                            }

                            if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO))
                                AttackStart(target);
                        });

                        break;
                    }
                    default:
                        break;
                }
            }

            void EnterCombat(Unit* /*attacker*/) override
            {
                _EnterCombat();

                Talk(eTalks::Aggro);

                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me, 1);

                if (IsMythic())
                {
                    //Add runes effects
                    me->CastSpell(me, eSpells::PowerOfDisplacement, true);
                    me->CastSpell(me, eSpells::PowerOfReplication, true);
                }

                m_Events.ScheduleEvent(eEvents::EventForceNova, 45 * TimeConstants::IN_MILLISECONDS);
                m_Events.ScheduleEvent(eEvents::EventArcaneWrath, 6 * TimeConstants::IN_MILLISECONDS);
                m_Events.ScheduleEvent(eEvents::EventDestructiveResonance, 15 * TimeConstants::IN_MILLISECONDS);
                m_Events.ScheduleEvent(eEvents::EventMarkOfChaos, 34 * TimeConstants::IN_MILLISECONDS);
                m_Events.ScheduleEvent(eEvents::EventArcaneAberration, 25 * TimeConstants::IN_MILLISECONDS);

                if (IsLFR() || IsMythic())
                    m_Events.ScheduleEvent(eEvents::EventBerserk, 900 * TimeConstants::IN_MILLISECONDS);

                m_CosmeticEvents.ScheduleEvent(eCosmeticEvents::EventCheckPlayerZ, 1 * TimeConstants::IN_MILLISECONDS);
                m_CosmeticEvents.CancelEvent(EventCheckRuneCosmetic);
                m_CosmeticEvents.ScheduleEvent(EventCheckRuneCosmetic, 0);
            }

            void DamageDealt(Unit* p_Victim, uint32& /*damage*/, DamageEffectType damageType) override
            {
                /// Accelerated Assault Icon Accelerated Assault is a stacking buff that Mar'gok applies to himself each time he performs consecutive attacks against the same target.
                /// Each stack of the buff increases Mar'gok's attack speed by 8%.
                if (damageType != DamageEffectType::DIRECT_DAMAGE)
                    return;

                /// This is a new target, reset stacks
                if (p_Victim->GetGUID() != m_MeleeTargetGuid)
                {
                    me->RemoveAura(eSpells::AcceleratedAssault);
                    m_MeleeTargetGuid = p_Victim->GetGUID();
                }
                /// Still same target, continue stacking
                else
                    me->CastSpell(me, eSpells::AcceleratedAssault, true);
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (m_Phase == ePhases::MythicPhase4ChoGall || me->IsInEvadeMode())
                {
                    damage = 0;
                    return;
                }

                /// -1 means transition phase, 0 means last phase, until Mar'gok's death
                if (g_SwitchPhasePcts[m_Phase - 1] == 255 || !g_SwitchPhasePcts[m_Phase - 1])
                    return;

                if (me->HealthBelowPctDamaged(g_SwitchPhasePcts[m_Phase - 1], damage))
                {
                    ++m_Phase;

                    switch (m_Phase)
                    {
                    case ePhases::RuneOfDisplacement:
                    {
                        if (!IsMythic()) ScheduleSecondPhase();
                        break;
                    }
                    case ePhases::DormantRunestones:
                    {
                        if (!IsMythic()) ScheduleFirstTransitionPhase();
                        break;
                    }
                    case ePhases::LineageOfPower:
                    {
                        if (!IsMythic()) ScheduleSecondTransitionPhase();
                        break;
                    }
                    case ePhases::MythicTransition1:
                    {
                        if (IsMythic()) MythicScheduleFirstTransitionPhase();
                        break;
                    }
                    case ePhases::MythicTransition2:
                    {
                        if (IsMythic()) MythicScheduleSecondTransitionPhase();
                        break;
                    }
                    case ePhases::MythicPhase4ChoGall:
                    {
                        if (IsMythic())
                            if(TempSummon* chogall = me->SummonCreature(eHighmaulCreatures::Chogall, g_ChogallEventsPos[0]))
                                chogall->AI()->DoAction(1); ///< Start Cho'gall event

                        break;
                    }
                    default:
                        break;
                    }

                    m_Events.SetPhase(m_Phase);
                }
            }

            void KilledUnit(Unit* killed) override
            {
                if (killed->GetTypeId() == TypeID::TYPEID_PLAYER)
                    Talk(eTalks::Slay);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();

                m_Events.Reset();
                m_CosmeticEvents.Reset();

                if (!IsMythic())
                    Talk(eTalks::Death);

                ResetRunes();
                DespawnAdds();

                summons.DespawnAll();

                if (m_Instance != nullptr)
                {
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                    me->RemoveAllAreaTriggers();
                    std::list<AreaTrigger*> AreaTriggerList;
                    me->GetAreaTriggerListWithSpellIDInRange(AreaTriggerList, SpellGrowingShadowsAT, 300);
                    for (auto itr : AreaTriggerList)
                        itr->Remove();

                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::MarkOfChaosAura);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::MarkOfChaosDisplacementAura);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::MarkOfChaosFortificationAura);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::MarkOfChaosReplicationAura);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::DestructiveResonanceDebuff);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::ArcaneWrathBranded);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::ArcaneWrathBrandedDisplacement);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::ArcaneWrathBrandedFortification);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::ArcaneWrathBrandedReplication);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::FetterMarkOfChaosRootAura);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::OrbsOfChaosDummyAura);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::SpellGrowingShadowsDmg);

                    if(!IsMythic())
                        instance->DoCastSpellOnPlayers(eSpells::ImperatorMargokBonus, me);

                    ///< Only Cho'gall can loot in mythic mode
                    if (IsMythic())
                        me->ResetLootRecipients();
                }
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                ClearDelayedOperations();

                me->SetAIAnimKitId(0);
                //me->SetAnimTier(0);
                me->SetDisableGravity(false);
                me->SendSetPlayHoverAnim(false);
                me->SetReactState(ReactStates::REACT_AGGRESSIVE);

                me->RemoveAllAuras();

                me->InterruptNonMeleeSpells(true);

                /// Just in case, to prevent the fail Return to Home
                me->ClearUnitState(UnitState::UNIT_STATE_ROOT);
                me->ClearUnitState(UnitState::UNIT_STATE_DISTRACTED);
                me->ClearUnitState(UnitState::UNIT_STATE_STUNNED);

                me->RemoveUnitFlag2(UNIT_FLAG2_FEIGN_DEATH);

                m_Phase = IsMythic() ? ePhases::MythicPhase1 : ePhases::MightOfTheCrown;
                CreatureAI::EnterEvadeMode();

                summons.DespawnAll();
                if (Creature *chogall = me->FindNearestCreature(eHighmaulCreatures::Chogall, 500))
                    chogall->DespawnOrUnsummon();
                if (Creature *chogall = me->FindNearestCreature(eHighmaulCreatures::Chogall, 500, false))
                    chogall->DespawnOrUnsummon();

                std::list<Creature*> NightList;
                me->GetCreatureListWithEntryInGrid(NightList, NpcNightTwistedFaithful, 300.0f);

                for (Creature* itr : NightList)
                    itr->DespawnOrUnsummon();

                me->GetCreatureListWithEntryInGrid(NightList, NpcGlimpseOfMadness, 300.0f);

                for (Creature* itr : NightList)
                    itr->DespawnOrUnsummon();

                me->GetCreatureListWithEntryInGrid(NightList, WORLD_TRIGGER, 300.0f);
                
                for (Creature* itr : NightList)
                    itr->DespawnOrUnsummon();
                
                me->RemoveAllAreaTriggers();
                std::list<AreaTrigger*> AreaTriggerList;
                me->GetAreaTriggerListWithSpellIDInRange(AreaTriggerList, SpellGrowingShadowsAT, 300);
                for (auto itr : AreaTriggerList)
                    itr->Remove();

                if (m_Instance != nullptr)
                {
                    m_Instance->SetBossState(eHighmaulDatas::BossImperatorMargok, EncounterState::FAIL);

                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::MarkOfChaosAura);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::MarkOfChaosDisplacementAura);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::MarkOfChaosFortificationAura);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::MarkOfChaosReplicationAura);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::DestructiveResonanceDebuff);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::ArcaneWrathBranded);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::ArcaneWrathBrandedDisplacement);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::ArcaneWrathBrandedFortification);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::ArcaneWrathBrandedReplication);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::FetterMarkOfChaosRootAura);
                    m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::OrbsOfChaosDummyAura);
                }

                m_CosmeticEvents.CancelEvent(EventCheckRuneCosmetic);
                m_CosmeticEvents.ScheduleEvent(EventCheckRuneCosmetic, 0);
            }

            uint32 GetData(uint32 id) const override
            {
                switch (id)
                {
                    //@todo: check where this is used : maybe in cosmetic spell where he drains the rune, don't forget to add mythic phases
                    case eDatas::PhaseID:
                        return m_Phase;
                    case eDatas::OrbOfChaosAngle:
                        return m_OrbCount;
                    default:
                        break;
                }

                return 0;
            }

            void SetData(uint32 id, uint32 value) override
            {
                switch (id)
                {
                    case eDatas::OrbOfChaosAngle:
                    {
                        m_OrbCount = value;
                        break;
                    }
                    default:
                        break;
                }
            }

            void JustUnregisteredAreaTrigger(AreaTrigger* at) override
            {
                if (at->GetSpellId() == eSpells::ForceNovaAreaTrigger)
                {
                    if (m_Instance)
                        m_Instance->DoRemoveForcedMovementsOnPlayers(at->GetGUID());
                }
            }

            void OnSpellCasted(SpellInfo const* spellInfo) override
            {
                switch (spellInfo->Id)
                {
                    case eSpells::DestructiveResonanceSearcher:
                    case eSpells::DestructiveResonanceDisplacementSearch:
                    case eSpells::DestructiveResonanceFortificationSearch:
                    case eSpells::DestructiveResonanceReplicationSearch:
                    {
                        Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 2, -10.0f, true);
                        if (target == nullptr || me->GetDistance(target) >= 100.0f)
                            target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 2, 60.0f, true);

                        if (target == nullptr)
                            target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 60.0f, true);

                        if (target != nullptr)
                            me->CastSpell(*target, eSpells::DestructiveResonanceSummon, true);

                        break;
                    }
                    case eSpells::ArcaneWrathSearcher:
                    {
                        if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 2, 60.0f))
                            me->CastSpell(target, eSpells::ArcaneWrathBranded, true);
                        else if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 60.0f))
                            me->CastSpell(target, eSpells::ArcaneWrathBranded, true);

                        break;
                    }
                    case eSpells::ArcaneWrathDisplacementSearcher:
                    {
                        if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 2, 60.0f))
                            me->CastSpell(target, eSpells::ArcaneWrathBrandedDisplacement, true);
                        else if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 60.0f))
                            me->CastSpell(target, eSpells::ArcaneWrathBrandedDisplacement, true);

                        break;
                    }
                    case eSpells::ForceNovaCasting:
                    {
                        /// This spell should knock back players in melee range
                        me->CastSpell(me, eSpells::ForceNovaKnockBack, true);
                        me->CastSpell(me, eSpells::ForceNovaDummy, true);

                        m_IsInNova = true;
                        m_NovaTime = 0;
                        m_NovaPos = *me;

                        /// Force Nova has a radius of 100 yards and moves with a speed of 7 yards per second
                        uint32 l_Time = float(100.0f / 7.0f) * float(TimeConstants::IN_MILLISECONDS);
                        AddTimedDelayedOperation(l_Time, [this]() -> void
                        {
                            m_IsInNova = false;
                            m_NovaTime = 0;
                            m_NovaPos = Position();

                            if (m_Instance)
                                m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::ForceNovaDoT);
                        });

                        break;
                    }
                    case eSpells::ForceNovaDisplacement:
                    {
                        /// This spell should knock back players in melee range
                        me->CastSpell(me, eSpells::ForceNovaAreaTrigger, true);
                        me->CastSpell(me, eSpells::ForceNovaDisplacementDummy, true);

                        m_IsInNova = true;
                        m_NovaTime = 0;
                        m_NovaPos = *me;

                        /// Force Nova has a radius of 100 yards and moves with a speed of 7 yards per second
                        uint32 l_Time = float(100.0f / 7.0f) * float(TimeConstants::IN_MILLISECONDS);
                        AddTimedDelayedOperation(l_Time, [this]() -> void
                        {
                            m_IsInNova = false;
                            m_NovaTime = 0;
                            m_NovaPos = Position();

                            if (m_Instance)
                                m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::ForceNovaDoT);
                        });

                        break;
                    }
                    case eSpells::ForceNovaFortificationCasting:
                    {
                        me->CastSpell(me, eSpells::ForceNovaFortifiedPeriodicAura, true);
                        break;
                    }
                    case eSpells::ForceNovaFortificationDummy:
                    {
                        me->CastSpell(me, eSpells::ForceNovaKnockBack, true);

                        m_IsInNovaPhase3[m_NovaCount] = true;
                        m_NovaTimePhase3[m_NovaCount] = 0;
                        m_NovaPosPhase3[m_NovaCount] = *me;

                        /// Force Nova has a radius of 100 yards and moves with a speed of 7 yards per second
                        uint32 l_Time = float(100.0f / 7.0f) * float(TimeConstants::IN_MILLISECONDS);
                        /// Must save the current value
                        uint8 l_Count = m_NovaCount;
                        AddTimedDelayedOperation(l_Time, [this, l_Count]() -> void
                        {
                            m_IsInNovaPhase3[l_Count] = false;
                            m_NovaTimePhase3[l_Count] = 0;
                            m_NovaPosPhase3[l_Count] = Position();

                            if (m_Instance && l_Count >= (eDatas::MaxNovaPhase3 - 1))
                            {
                                m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::ForceNovaDoT);
                                m_NovaCount = 0;
                            }
                        });

                        ++m_NovaCount;
                        break;
                    }
                    case eSpells::ForceNovaReplicationCasting:
                    {
                        /// This spell should knock back players in melee range
                        me->CastSpell(me, eSpells::ForceNovaKnockBack, true);
                        me->CastSpell(me, eSpells::ForceNovaReplicationDummy, true);

                        m_IsInNova = true;
                        m_NovaTime = 0;
                        m_NovaPos = *me;

                        /// Force Nova has a radius of 100 yards and moves with a speed of 7 yards per second
                        uint32 l_Time = float(100.0f / 7.0f) * float(TimeConstants::IN_MILLISECONDS);
                        AddTimedDelayedOperation(l_Time, [this]() -> void
                        {
                            m_IsInNova = false;
                            m_NovaTime = 0;
                            m_NovaPos = Position();

                            if (m_Instance)
                                m_Instance->DoRemoveAurasDueToSpellOnPlayers(eSpells::ForceNovaDoT);
                        });

                        break;
                    }
                    case eSpells::AwakenRunestone:
                    {
                        std::list<Creature*> l_TriggerList;
                        me->GetCreatureListWithEntryInGrid(l_TriggerList, eHighmaulGameobjects::SLGGenericMoPLargeAoI, 30.0f);

                        /// Should have only two triggers, the base one and the large one
                        for (Creature* l_Trigger : l_TriggerList)
                        {
                            switch (m_Phase)
                            {
                                case ePhases::DormantRunestones:
                                {
                                    /// Small gaze for base visual
                                    if (l_Trigger->HasAura(eSpells::FortificationBaseVisual))
                                        continue;

                                    /// Big gaze for large visual during activation
                                    l_Trigger->CastSpell(l_Trigger, eSpells::FortificationAchievement, true);
                                    l_Trigger->CastSpell(l_Trigger, eSpells::VolatileAnomalies, true);
                                    break;
                                }
                                case ePhases::LineageOfPower:
                                {
                                    /// Small gaze for base visual
                                    if (l_Trigger->HasAura(eSpells::ReplicationBaseVisual))
                                        continue;

                                    /// Big gaze for large visual during activation
                                    l_Trigger->CastSpell(l_Trigger, eSpells::ReplicationAchievement, true);
                                    l_Trigger->CastSpell(l_Trigger, eSpells::VolatileAnomalies, true);
                                    break;
                                }
                                case ePhases::MythicTransition1:
                                {
                                    if (!IsMythic())
                                        break;

                                    /// Small gaze for base visual
                                    if (l_Trigger->HasAura(eSpells::FortificationBaseVisual))
                                        continue;

                                    /// Big gaze for large visual during activation
                                    l_Trigger->CastSpell(l_Trigger, eSpells::FortificationAchievement, true);
                                    l_Trigger->CastSpell(l_Trigger, eSpells::VolatileAnomalies, true);

                                    break;
                                }
                                case ePhases::MythicTransition2:
                                {
                                    if (!IsMythic())
                                        break;

                                    /// Small gaze for base visual
                                    if (l_Trigger->HasAura(eSpells::ReplicationBaseVisual))
                                        continue;

                                    /// Big gaze for large visual during activation
                                    l_Trigger->CastSpell(l_Trigger, eSpells::ReplicationAchievement, true);
                                    l_Trigger->CastSpell(l_Trigger, eSpells::VolatileAnomalies, true);

                                    break;
                                }
                                default:
                                    break;
                            }

                            break;
                        }

                        break;
                    }
                    case eSpells::ArcaneWrathFortificationSearcher:
                    {
                        if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 2, 60.0f))
                            me->CastSpell(target, eSpells::ArcaneWrathBrandedFortification, true);
                        else if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 60.0f))
                            me->CastSpell(target, eSpells::ArcaneWrathBrandedFortification, true);

                        break;
                    }
                    case eSpells::ArcaneWrathReplicationSearcher:
                    {
                        if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 2, 60.0f))
                            me->CastSpell(target, eSpells::ArcaneWrathBrandedReplication, true);
                        else if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 60.0f))
                            me->CastSpell(target, eSpells::ArcaneWrathBrandedReplication, true);

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
                    case eSpells::ArcaneWrathBranded:
                    case eSpells::ArcaneWrathBrandedDisplacement:
                    case eSpells::ArcaneWrathBrandedFortification:
                    case eSpells::ArcaneWrathBrandedReplication:
                    {
                        Talk(eTalks::Branded, target);
                        break;
                    }
                    case eSpells::MarkOfChaosDisplacementAura:
                    {
                        /// In addition to Mark of Chaos' normal effects, the target is teleported to a random location.
                        if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 2, -10.0f))
                            target->NearTeleportTo(*target);
                        if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, -10.0f))
                            target->NearTeleportTo(*target);

                        if (IsMythic())
                        {
                            m_OrbCount = 0;
                            me->CastSpell(target, eSpells::OrbsOfChaosDummyAura, true);
                        }

                        break;
                    }
                    case eSpells::MarkOfChaosFortificationAura:
                    {
                        if (IsMythic())
                        {
                            if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 2, -10.0f))
                                target->NearTeleportTo(*target);
                            if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, -10.0f))
                                target->NearTeleportTo(*target);
                        }

                        me->CastSpell(target, eSpells::FetterMarkOfChaosRootAura, true);
                        break;
                    }
                    case eSpells::MarkOfChaosReplicationAura:
                    {
                        m_OrbCount = 0;
                        me->CastSpell(target, eSpells::OrbsOfChaosDummyAura, true);

                        if (IsMythic())
                            me->CastSpell(target, eSpells::FetterMarkOfChaosRootAura, true);

                        break;
                    }
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 const diff) override
            {
                UpdateOperations(diff);

                if (!m_InCombat)
                {
                    if (Player* player = me->SelectNearestPlayer(20.0f))
                    {
                        me->CastSpell(me, eSpells::TeleportOffThrone, true);
                        m_InCombat = true;

                        ObjectGuid guid = player->GetGUID();
                        AddTimedDelayedOperation(500, [this, guid]() -> void
                        {
                            if (Player* player = ObjectAccessor::GetPlayer(*me, guid))
                                AttackStart(player);
                        });
                    }
                }

                if (m_IsInNova || (m_NovaCount > 0 && m_IsInNovaPhase3[m_NovaCount - 1]))
                    UpdateNovaTargets(diff);

                m_CosmeticEvents.Update(diff);

                switch (m_CosmeticEvents.ExecuteEvent())
                {
                    case eCosmeticEvents::EventSummonWarmages:
                    {
                        std::list<Creature*> l_TriggerList;
                        me->GetCreatureListWithEntryInGrid(l_TriggerList, eCreatures::WarmageSummonStalker, 150.0f);

                        for (Creature* l_Stalker : l_TriggerList)
                            l_Stalker->CastSpell(l_Stalker, eSpells::SummonWarmage, true);

                        break;
                    }
                    case eCosmeticEvents::EventCheckPlayerZ:
                    {
                        std::list<HostileReference*> l_ThreatList = me->getThreatManager().getThreatList();
                        for (HostileReference* l_Ref : l_ThreatList)
                        {
                            if (Player* player = ObjectAccessor::GetPlayer(*me, l_Ref->getUnitGuid()))
                            {
                                if (player->GetPositionZ() <= g_MinAllowedZ)
                                    player->NearTeleportTo(g_CenterPos);
                            }
                        }

                        m_CosmeticEvents.ScheduleEvent(eCosmeticEvents::EventCheckPlayerZ, 1 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case eCosmeticEvents::EventCheckRuneCosmetic:
                    {
                        //m_NullificationRuneSummoned
                        //

                        switch (m_Phase)
                        {
                        case MightOfTheCrown:        // clear all visuals
                            break;
                        case RuneOfDisplacement:     // active displacement
                            break;
                        case RuneOfFortification:    // active Fortification
                            break;
                        case RuneOfReplication:      // active Replication
                            break;

                        case MythicPhase1:           // active Displacement + Replication, clear the others
                            break;
                        case MythicPhase2:           // active  Displacement +  Fortification, remove Replication
                            break;
                        case MythicPhase3:           // all actives
                            break;
                        case MythicPhase4ChoGall:    // summon rune + nullification
                        default:
                            break;
                        }

                        // check nullification spawn, remove if different of MythicPhase4ChoGall

                        m_CosmeticEvents.ScheduleEvent(eCosmeticEvents::EventCheckRuneCosmetic, 2 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    default:
                        break;
                }

                if (!UpdateVictim())
                    return;

                m_Events.Update(diff);

                if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                    return;

                switch (m_Events.ExecuteEvent())
                {
                    /// ALL DIFFICULTIES
                    case eEvents::EventMarkOfChaos:
                    {
                        if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO))
                        {
                            switch (m_Phase)
                            {
                            case ePhases::MightOfTheCrown:      ///< NM/HN Phase 1
                                me->CastSpell(target, eSpells::MarkOfChaosAura, false);
                                break;
                            case ePhases::RuneOfDisplacement:   ///< NM/HN Phase 2
                            case ePhases::MythicPhase1:         ///< MM Phase 1: Rune of Displacement + Rune of Replication, all spells are displayed as the "Rune of Displacement" ones
                                me->CastSpell(target, eSpells::MarkOfChaosDisplacementAura, false);
                                break;
                            case ePhases::RuneOfFortification:  ///< NM/HN Phase 3
                            case ePhases::MythicPhase2:         ///< MM Phase 2: Rune of Displacement + Rune of Fortification, all spells are displayed as the "Rune of Fortification" ones
                                me->CastSpell(target, eSpells::MarkOfChaosFortificationAura, false);
                                break;
                            case ePhases::RuneOfReplication:    ///< NM/HN Phase 4
                            case ePhases::MythicPhase3:         ///< MM Phase 3: Rune of Replication + Rune of Fortification, all spells are displayed as the "Rune of Replication" ones
                            case ePhases::MythicPhase4ChoGall:  ///< MM Phase 4
                                me->CastSpell(target, eSpells::MarkOfChaosReplicationAura, false);
                                break;
                            }

                            me->CastSpell(target, eSpells::MarkOfChaosCosmetic, true);
                        }

                        if (m_Phase != ePhases::MythicPhase4ChoGall) Talk(eTalks::MarkOfChaos);
                        m_Events.ScheduleEvent(eEvents::EventMarkOfChaos, 51 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case eEvents::EventForceNova:
                    {
                        switch (m_Phase)
                        {
                        case ePhases::MightOfTheCrown:      ///< NM/HN Phase 1
                            me->CastSpell(me, eSpells::ForceNovaCasting, false);
                            break;
                        case ePhases::RuneOfDisplacement:   ///< NM/HN Phase 2
                        case ePhases::MythicPhase1:         ///< MM Phase 1: Rune of Displacement + Rune of Replication, all spells are displayed as the "Rune of Displacement" ones
                            me->CastSpell(me, eSpells::ForceNovaDisplacement, false);
                            break;
                        case ePhases::RuneOfFortification:  ///< NM/HN Phase 3
                        case ePhases::MythicPhase2:         ///< MM Phase 2: Rune of Displacement + Rune of Fortification, all spells are displayed as the "Rune of Fortification" ones
                            me->CastSpell(me, eSpells::ForceNovaFortificationCasting, false);
                            break;
                        case ePhases::RuneOfReplication:    ///< NM/HN Phase 4
                        case ePhases::MythicPhase3:         ///< MM Phase 3: Rune of Replication + Rune of Fortification, all spells are displayed as the "Rune of Replication" ones
                        case ePhases::MythicPhase4ChoGall:  ///< MM Phase 4
                            me->CastSpell(me, eSpells::ForceNovaReplicationCasting, false);
                            break;
                        }

                        me->CastSpell(me, eSpells::ForceNovaScriptEffect, true);

                        if (m_Phase != ePhases::MythicPhase4ChoGall) Talk(eTalks::ForceNova);
                        m_Events.ScheduleEvent(eEvents::EventForceNova, 45 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case eEvents::EventArcaneWrath:
                    {
                        switch (m_Phase)
                        {
                        case ePhases::MightOfTheCrown:      ///< NM/HN Phase 1
                            me->CastSpell(me, eSpells::ArcaneWrathSearcher, false);
                            break;
                        case ePhases::RuneOfDisplacement:   ///< NM/HN Phase 2
                        case ePhases::MythicPhase1:         ///< MM Phase 1: Rune of Displacement + Rune of Replication, all spells are displayed as the "Rune of Displacement" ones
                            me->CastSpell(me, eSpells::ArcaneWrathDisplacementSearcher, false);
                            break;
                        case ePhases::RuneOfFortification:  ///< NM/HN Phase 3
                        case ePhases::MythicPhase2:         ///< MM Phase 2: Rune of Displacement + Rune of Fortification, all spells are displayed as the "Rune of Fortification" ones
                            me->CastSpell(me, eSpells::ArcaneWrathFortificationSearcher, false);
                            break;
                        case ePhases::RuneOfReplication:    ///< NM/HN Phase 4
                        case ePhases::MythicPhase3:         ///< MM Phase 3: Rune of Replication + Rune of Fortification, all spells are displayed as the "Rune of Replication" ones
                        case ePhases::MythicPhase4ChoGall:  ///< MM Phase 4
                            me->CastSpell(me, eSpells::ArcaneWrathReplicationSearcher, false);
                            break;
                        }

                        me->CastSpell(me, eSpells::ArcaneWrathCosmetic, true);

                        if (m_Phase != ePhases::MythicPhase4ChoGall) Talk(eTalks::ArcaneWrath);
                        m_Events.ScheduleEvent(eEvents::EventArcaneWrath, 50 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case eEvents::EventDestructiveResonance:
                    {
                        switch (m_Phase)
                        {
                        case ePhases::MightOfTheCrown:      ///< NM/HN Phase 1
                            me->CastSpell(me, eSpells::DestructiveResonanceSearcher, false);
                            break;
                        case ePhases::RuneOfDisplacement:   ///< NM/HN Phase 2
                        case ePhases::MythicPhase1:         ///< MM Phase 1: Rune of Displacement + Rune of Replication, all spells are displayed as the "Rune of Displacement" ones
                            me->CastSpell(me, eSpells::DestructiveResonanceDisplacementSearch, false);
                            break;
                        case ePhases::RuneOfFortification:  ///< NM/HN Phase 3
                        case ePhases::MythicPhase2:         ///< MM Phase 2: Rune of Displacement + Rune of Fortification, all spells are displayed as the "Rune of Fortification" ones
                            me->CastSpell(me, eSpells::DestructiveResonanceFortificationSearch, false);
                            break;
                        case ePhases::RuneOfReplication:    ///< NM/HN Phase 4
                        case ePhases::MythicPhase3:         ///< MM Phase 3: Rune of Replication + Rune of Fortification, all spells are displayed as the "Rune of Replication" ones
                        case ePhases::MythicPhase4ChoGall:  ///< MM Phase 4
                            me->CastSpell(me, eSpells::DestructiveResonanceReplicationSearch, false);
                            break;
                        }
                        
                        me->CastSpell(me, eSpells::DestructiveResonanceCosmetic, true);
                        m_Events.ScheduleEvent(eEvents::EventDestructiveResonance, 15 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case eEvents::EventArcaneAberration:
                    {
                        switch (m_Phase)
                        {
                        case ePhases::MightOfTheCrown:      ///< NM/HN Phase 1
                            me->CastSpell(me, eSpells::SummonArcaneAberrationCast, false);
                            break;
                        case ePhases::RuneOfDisplacement:   ///< NM/HN Phase 2
                        case ePhases::MythicPhase1:         ///< MM Phase 1: Rune of Displacement + Rune of Replication, all spells are displayed as the "Rune of Displacement" ones
                            me->CastSpell(me, eSpells::SummonDisplacingArcaneAberration, false);
                            break;
                        case ePhases::RuneOfFortification:  ///< NM/HN Phase 3
                        case ePhases::MythicPhase2:         ///< MM Phase 2: Rune of Displacement + Rune of Fortification, all spells are displayed as the "Rune of Fortification" ones
                            me->CastSpell(me, eSpells::SummonFortifiedArcaneAberration, false);
                            break;
                        case ePhases::MythicPhase3:         ///< MM Phase 3: Rune of Replication + Rune of Fortification, all spells are displayed as the "Rune of Replication" ones
                        case ePhases::RuneOfReplication:    ///< NM/HN Phase 4
                        case ePhases::MythicPhase4ChoGall:  ///< MM Phase 4
                            me->CastSpell(me, eSpells::SummonReplicatingArcaneAberration, false);
                            break;
                        }
                        
                        me->CastSpell(me, eSpells::SummonArcaneAberrationCosmetic, true);

                        if (m_Phase != ePhases::MythicPhase4ChoGall) Talk(eTalks::ArcaneAberration);
                        m_Events.ScheduleEvent(eEvents::EventArcaneAberration, 45 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    /// LFR + MYTHIC
                    case eEvents::EventBerserk:
                    {
                        if (me->HasAura(eHighmaulSpells::PermanentFeignDeath) || m_Phase == ePhases::MythicPhase4ChoGall)
                            break;

                        Talk(eTalks::Berserk);
                        me->CastSpell(me, eHighmaulSpells::Berserker, true);
                        break;
                    }
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }

            void UpdateNovaTargets(uint32 const diff)
            {
                /// Used for Phase 1 & Phase 2
                //@todo: add mythic case if needed, it depend where m_IsInNova value is changed
                if (m_IsInNova)
                {
                    m_NovaTime += diff;

                    float l_YardsPerMs = 7.0f / (float)TimeConstants::IN_MILLISECONDS;
                    /// Base min radius is 10 yards, which is increased depending on time passed
                    float l_MinRadius = 8.0f;
                    float l_InnerRange = 6.0f;

                    l_MinRadius += (l_YardsPerMs * m_NovaTime);

                    ObjectGuid l_TriggerGuid = ObjectGuid::Empty;
                    AreaTrigger* l_Trigger = me->GetAreaTrigger(eSpells::ForceNovaAreaTrigger);
                    if (l_Trigger != nullptr)
                        l_TriggerGuid = l_Trigger->GetGUID();

                    std::list<HostileReference*> l_ThreatList = me->getThreatManager().getThreatList();
                    for (HostileReference* l_Ref : l_ThreatList)
                    {
                        if (Player* player = ObjectAccessor::GetPlayer(*me, l_Ref->getUnitGuid()))
                        {
                            if (player->GetDistance(m_NovaPos) >= (l_MinRadius - l_InnerRange) &&
                                player->GetDistance(m_NovaPos) <= l_MinRadius)
                            {
                                if (!player->HasAura(eSpells::ForceNovaDoT))
                                    me->CastSpell(player, eSpells::ForceNovaDoT, true);

                                /// In addition to Force Nova's normal effects, it now also pushes players away as the nova moves outwards.
                                if ((m_Phase == ePhases::RuneOfDisplacement || m_Phase == ePhases::MythicPhase1 || m_Phase == ePhases::MythicPhase2)
                                    && !l_TriggerGuid.IsEmpty() && l_Trigger)
                                {
                                    if (!player->HasMovementForce(l_TriggerGuid))
                                        player->ApplyMovementForce(l_TriggerGuid, *l_Trigger, -5.5f, 0);
                                }
                            }
                            else
                            {
                                if (player->HasAura(eSpells::ForceNovaDoT))
                                    player->RemoveAura(eSpells::ForceNovaDoT);

                                /// In addition to Force Nova's normal effects, it now also pushes players away as the nova moves outwards.
                                if ((m_Phase == ePhases::RuneOfDisplacement || m_Phase == ePhases::MythicPhase1 || m_Phase == ePhases::MythicPhase2)
                                    && !l_TriggerGuid.IsEmpty())
                                {
                                    if (player->HasMovementForce(l_TriggerGuid))
                                        player->RemoveMovementForce(l_TriggerGuid);
                                }
                            }
                        }
                    }
                }
                /// Phase 3 + MM phases with fortification activated
                else
                {
                    std::set<ObjectGuid> l_AffectedPlayers;

                    for (uint8 l_I = 0; l_I < eDatas::MaxNovaPhase3; ++l_I)
                    {
                        if (m_IsInNovaPhase3[l_I])
                        {
                            m_NovaTimePhase3[l_I] += diff;

                            float l_YardsPerMs = 7.0f / (float)TimeConstants::IN_MILLISECONDS;
                            /// Base min radius is 10 yards, which is increased depending on time passed
                            float l_MinRadius = 8.0f;
                            float l_InnerRange = 6.0f;

                            l_MinRadius += (l_YardsPerMs * m_NovaTimePhase3[l_I]);

                            std::list<HostileReference*> l_ThreatList = me->getThreatManager().getThreatList();
                            for (HostileReference* l_Ref : l_ThreatList)
                            {
                                if (Player* player = ObjectAccessor::GetPlayer(*me, l_Ref->getUnitGuid()))
                                {
                                    if (player->GetDistance(m_NovaPosPhase3[l_I]) >= (l_MinRadius - l_InnerRange) &&
                                        player->GetDistance(m_NovaPosPhase3[l_I]) <= l_MinRadius)
                                        l_AffectedPlayers.insert(player->GetGUID());
                                }
                            }
                        }
                    }

                    std::list<HostileReference*> l_ThreatList = me->getThreatManager().getThreatList();
                    for (HostileReference* l_Ref : l_ThreatList)
                    {
                        if (Player* player = ObjectAccessor::GetPlayer(*me, l_Ref->getUnitGuid()))
                        {
                            if (l_AffectedPlayers.find(player->GetGUID()) != l_AffectedPlayers.end())
                            {
                                if (!player->HasAura(eSpells::ForceNovaDoT))
                                    me->CastSpell(player, eSpells::ForceNovaDoT, true);
                            }
                            else
                            {
                                if (player->HasAura(eSpells::ForceNovaDoT))
                                    player->RemoveAura(eSpells::ForceNovaDoT);
                            }
                        }
                    }
                }
            }

            void ScheduleSecondPhase()
            {
                me->AttackStop();
                me->SetReactState(ReactStates::REACT_PASSIVE);
                me->AddUnitFlag2(UNIT_FLAG2_DISABLE_TURN);

                Talk(eTalks::TalkRuneOfDisplacement);

                me->CastSpell(me, eSpells::EncounterEvent, true);
                me->CastSpell(me, eSpells::TeleportToDisplacement, true);

                AddTimedDelayedOperation(3 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    me->CastSpell(me, eSpells::TransitionVisualPhase2, true);
                    me->SetAIAnimKitId(eAnimKit::AnimKitFlyingRune);

                    //me->SetAnimTier(3);
                    me->SetDisableGravity(true);
                    me->SendSetPlayHoverAnim(true);

                    Position pos = *me;
                    pos.m_positionZ += 16.0f;
                    me->GetMotionMaster()->MovePoint(eMoves::MoveUp, pos);
                    m_Events.DelayEvents(9 * IN_MILLISECONDS);
                });

                AddTimedDelayedOperation(11 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    me->CastSpell(me, eSpells::PowerOfDisplacement, true);
                    me->CastSpell(me, eSpells::DisplacementTransform, true);

                    Position pos = *me;
                    pos.m_positionZ -= 16.0f;
                    me->GetMotionMaster()->MovePoint(eMoves::MoveDown, pos);
                });
            }

            void ScheduleFirstTransitionPhase()
            {
                me->AttackStop();
                me->SetReactState(ReactStates::REACT_PASSIVE);
                me->AddUnitFlag2(UNIT_FLAG2_DISABLE_TURN);

                me->CastSpell(me, eSpells::EncounterEvent, true);
                me->CastSpell(me, eSpells::TeleportToFortification, true);

                Talk(eTalks::TalkRuneOfFortification1);

                AddTimedDelayedOperation(7 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    me->CastSpell(me, eSpells::ArcaneProtection, true);
                    me->CastSpell(me, eSpells::TransitionVisualPhase3, true);

                    me->SetAIAnimKitId(eAnimKit::AnimKitFlyingRune);

                    //me->SetAnimTier(3);
                    me->SetDisableGravity(true);
                    me->SendSetPlayHoverAnim(true);

                    Position pos = *me;
                    pos.m_positionZ += 16.0f;
                    me->GetMotionMaster()->MovePoint(eMoves::MoveUp, pos);
                    m_Events.DelayEvents(60 * IN_MILLISECONDS);
                });

                AddTimedDelayedOperation(10 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    Talk(eTalks::TalkRuneOfFortification2);

                    me->CastSpell(me, eSpells::AwakenRunestone, false);

                    std::list<Creature*> l_TriggerList;
                    me->GetCreatureListWithEntryInGrid(l_TriggerList, eCreatures::WarmageSummonStalker, 150.0f);

                    for (Creature* l_Stalker : l_TriggerList)
                        l_Stalker->CastSpell(l_Stalker, eSpells::SummonRuneVisual, true);

                    m_CosmeticEvents.ScheduleEvent(eCosmeticEvents::EventSummonWarmages, 1 * TimeConstants::IN_MILLISECONDS);
                });

                AddTimedDelayedOperation(25 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    Talk(eTalks::TalkRuneOfFortification3);
                });

                AddTimedDelayedOperation(56 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    Talk(eTalks::TalkRuneOfFortification4);
                });

                AddTimedDelayedOperation(70 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    me->RemoveAura(eSpells::AwakenRunestone);

                    me->RemoveAura(eSpells::DisplacementTransform);
                    me->CastSpell(me, eSpells::FortificationTransform, true);

                    me->RemoveAura(eSpells::PowerOfDisplacement);
                    me->CastSpell(me, eSpells::PowerOfFortification, true);

                    Position pos = *me;
                    pos.m_positionZ -= 16.0f;
                    me->GetMotionMaster()->MovePoint(eMoves::MoveDown, pos);
                });

                AddTimedDelayedOperation(75 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    Talk(eTalks::TalkRuneOfFortification5);

                    ++m_Phase;

                    m_Events.SetPhase(m_Phase);
                });
            }

            void ScheduleSecondTransitionPhase()
            {
                me->AttackStop();
                me->SetReactState(ReactStates::REACT_PASSIVE);
                me->AddUnitFlag2(UNIT_FLAG2_DISABLE_TURN);

                me->CastSpell(me, eSpells::EncounterEvent, true);
                me->CastSpell(me, eSpells::TeleportToReplication, true);

                Talk(eTalks::TalkRuneOfReplication1);

                AddTimedDelayedOperation(7 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    me->CastSpell(me, eSpells::ArcaneProtection, true);
                    me->CastSpell(me, eSpells::TransitionVisualPhase4, true);

                    me->SetAIAnimKitId(eAnimKit::AnimKitFlyingRune);

                    //me->SetAnimTier(3);
                    me->SetDisableGravity(true);
                    me->SendSetPlayHoverAnim(true);

                    Position pos = *me;
                    pos.m_positionZ += 16.0f;
                    me->GetMotionMaster()->MovePoint(eMoves::MoveUp, pos);
                    m_Events.DelayEvents(60 * IN_MILLISECONDS);
                });

                AddTimedDelayedOperation(10 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    Talk(eTalks::TalkRuneOfReplication2);

                    me->CastSpell(me, eSpells::AwakenRunestone, false);

                    std::list<Creature*> l_TriggerList;
                    me->GetCreatureListWithEntryInGrid(l_TriggerList, eCreatures::WarmageSummonStalker, 150.0f);

                    for (Creature* l_Stalker : l_TriggerList)
                        l_Stalker->CastSpell(l_Stalker, eSpells::SummonRuneVisual, true);

                    m_CosmeticEvents.ScheduleEvent(eCosmeticEvents::EventSummonWarmages, 1 * TimeConstants::IN_MILLISECONDS);

                    me->SummonCreature(eCreatures::GorianReaver, g_GorianReaverPos);
                });

                AddTimedDelayedOperation(41 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    Talk(eTalks::TalkRuneOfReplication3);
                });

                AddTimedDelayedOperation(70 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    me->RemoveAura(eSpells::AwakenRunestone);

                    me->RemoveAura(eSpells::FortificationTransform);
                    me->RemoveAura(eSpells::ArcaneProtection);
                    me->CastSpell(me, eSpells::DisplacementTransform2, true);

                    me->RemoveAura(eSpells::PowerOfFortification);
                    me->CastSpell(me, eSpells::PowerOfReplication, true);

                    Position pos = *me;
                    pos.m_positionZ -= 16.0f;
                    me->GetMotionMaster()->MovePoint(eMoves::MoveDown, pos);
                });

                AddTimedDelayedOperation(75 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    Talk(eTalks::TalkRuneOfReplication4);

                    ++m_Phase;

                    m_Events.SetPhase(m_Phase);
                });
            }

            void MythicScheduleFirstTransitionPhase()
            {
                // activate fortification rune
                me->AttackStop();
                me->SetReactState(ReactStates::REACT_PASSIVE);
                me->AddUnitFlag2(UNIT_FLAG2_DISABLE_TURN);
                m_Events.DelayEvents(75 * IN_MILLISECONDS);

                me->CastSpell(me, eSpells::EncounterEvent, true);
                me->CastSpell(me, eSpells::TeleportToFortification, true);

                Talk(eTalks::TalkRuneOfFortification1);

                AddTimedDelayedOperation(7 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    me->CastSpell(me, eSpells::ArcaneProtection, true);
                    me->CastSpell(me, eSpells::TransitionVisualPhase3, true);
                    me->RemoveAura(eSpells::PowerOfReplication);

                    me->SetAIAnimKitId(eAnimKit::AnimKitFlyingRune);

                    //me->SetAnimTier(3);
                    me->SetDisableGravity(true);
                    me->SendSetPlayHoverAnim(true);

                    Position pos = *me;
                    pos.m_positionZ += 16.0f;
                    me->GetMotionMaster()->MovePoint(eMoves::MoveUp, pos);
                });

                AddTimedDelayedOperation(10 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    Talk(eTalks::TalkRuneOfFortification2);

                    me->CastSpell(me, eSpells::AwakenRunestone, false);

                    std::list<Creature*> l_TriggerList;
                    me->GetCreatureListWithEntryInGrid(l_TriggerList, eCreatures::WarmageSummonStalker, 150.0f);

                    for (Creature* l_Stalker : l_TriggerList)
                        l_Stalker->CastSpell(l_Stalker, eSpells::SummonRuneVisual, true);

                    m_CosmeticEvents.ScheduleEvent(eCosmeticEvents::EventSummonWarmages, 1 * TimeConstants::IN_MILLISECONDS);
                });

                AddTimedDelayedOperation(25 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    Talk(eTalks::TalkRuneOfFortification3);
                });

                AddTimedDelayedOperation(56 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    Talk(eTalks::TalkRuneOfFortification4);
                });

                AddTimedDelayedOperation(70 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    me->RemoveAura(eSpells::AwakenRunestone);

                    me->RemoveAura(eSpells::DisplacementTransform);
                    me->CastSpell(me, eSpells::FortificationTransform, true);

                    me->CastSpell(me, eSpells::PowerOfFortification, true);

                    Position pos = *me;
                    pos.m_positionZ -= 16.0f;
                    me->GetMotionMaster()->MovePoint(eMoves::MoveDown, pos);
                });

                AddTimedDelayedOperation(75 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    Talk(eTalks::TalkRuneOfFortification5);

                    ++m_Phase;

                    m_Events.SetPhase(m_Phase);
                });
            }

            void MythicScheduleSecondTransitionPhase()
            {
                // activate replication rune
                m_Events.DelayEvents(75 * IN_MILLISECONDS);
                me->AttackStop();
                me->SetReactState(ReactStates::REACT_PASSIVE);
                me->AddUnitFlag2(UNIT_FLAG2_DISABLE_TURN);

                me->CastSpell(me, eSpells::EncounterEvent, true);
                me->CastSpell(me, eSpells::TeleportToReplication, true);

                Talk(eTalks::TalkRuneOfReplication1);

                AddTimedDelayedOperation(7 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    me->CastSpell(me, eSpells::ArcaneProtection, true);
                    me->CastSpell(me, eSpells::TransitionVisualPhase4, true);
                    me->RemoveAura(eSpells::PowerOfDisplacement);

                    me->SetAIAnimKitId(eAnimKit::AnimKitFlyingRune);

                    //me->SetAnimTier(3);
                    me->SetDisableGravity(true);
                    me->SendSetPlayHoverAnim(true);

                    Position pos = *me;
                    pos.m_positionZ += 16.0f;
                    me->GetMotionMaster()->MovePoint(eMoves::MoveUp, pos);
                });

                AddTimedDelayedOperation(10 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    Talk(eTalks::TalkRuneOfReplication2);

                    me->CastSpell(me, eSpells::AwakenRunestone, false);

                    std::list<Creature*> l_TriggerList;
                    me->GetCreatureListWithEntryInGrid(l_TriggerList, eCreatures::WarmageSummonStalker, 150.0f);

                    for (Creature* l_Stalker : l_TriggerList)
                        l_Stalker->CastSpell(l_Stalker, eSpells::SummonRuneVisual, true);

                    m_CosmeticEvents.ScheduleEvent(eCosmeticEvents::EventSummonWarmages, 1 * TimeConstants::IN_MILLISECONDS);

                    me->SummonCreature(eCreatures::GorianReaver, g_GorianReaverPos);
                });

                AddTimedDelayedOperation(41 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    Talk(eTalks::TalkRuneOfReplication3);
                });

                AddTimedDelayedOperation(70 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    me->RemoveAura(eSpells::AwakenRunestone);

                    me->RemoveAura(eSpells::FortificationTransform);
                    me->RemoveAura(eSpells::ArcaneProtection);
                    me->CastSpell(me, eSpells::DisplacementTransform2, true);

                    me->CastSpell(me, eSpells::PowerOfReplication, true);

                    Position pos = *me;
                    pos.m_positionZ -= 16.0f;
                    me->GetMotionMaster()->MovePoint(eMoves::MoveDown, pos);
                });

                AddTimedDelayedOperation(75 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    Talk(eTalks::TalkRuneOfReplication4);

                    ++m_Phase;

                    m_Events.SetPhase(m_Phase);
                });
            }

            void ResetRunes()
            {
                std::list<Creature*> l_TriggerList;
                me->GetCreatureListWithEntryInGrid(l_TriggerList, eHighmaulGameobjects::SLGGenericMoPLargeAoI, 200.0f);

                for (Creature* l_Trigger : l_TriggerList)
                {
                    l_Trigger->RemoveAura(eSpells::FortificationAchievement);
                    l_Trigger->RemoveAura(eSpells::ReplicationAchievement);
                    l_Trigger->RemoveAura(eSpells::VolatileAnomalies);
                }

                l_TriggerList.clear();

                me->GetCreatureListWithEntryInGrid(l_TriggerList, eCreatures::NpcRuneOfDisplacement, 200.0f);

                for (Creature* l_Trigger : l_TriggerList)
                {
                    l_Trigger->RemoveAura(eSpells::FortificationRuneActive);
                    l_Trigger->RemoveAura(eSpells::ReplicationRuneActive);
                }
            }

            void DespawnAdds()
            {
                std::list<Creature*> l_CreatureList;
                me->GetCreatureListWithEntryInGrid(l_CreatureList, eCreatures::GorianWarmage, 200.0f);

                for (Creature* itr : l_CreatureList)
                    itr->DespawnOrUnsummon();

                l_CreatureList.clear();
                me->GetCreatureListWithEntryInGrid(l_CreatureList, eCreatures::VolatileAnomaly, 200.0f);

                for (Creature* itr : l_CreatureList)
                    itr->DespawnOrUnsummon();

                l_CreatureList.clear();
                me->GetCreatureListWithEntryInGrid(l_CreatureList, eCreatures::ArcaneRemnant, 200.0f);

                for (Creature* itr : l_CreatureList)
                    itr->DespawnOrUnsummon();

                l_CreatureList.clear();
                me->GetCreatureListWithEntryInGrid(l_CreatureList, NpcNightTwistedFaithful, 300.0f);

                for (Creature* itr : l_CreatureList)
                    itr->DespawnOrUnsummon();

                l_CreatureList.clear();
                me->GetCreatureListWithEntryInGrid(l_CreatureList, WORLD_TRIGGER, 300.0f);

                for (Creature* itr : l_CreatureList)
                    itr->DespawnOrUnsummon();

                l_CreatureList.clear();
                me->GetCreatureListWithEntryInGrid(l_CreatureList, NpcGlimpseOfMadness, 300.0f);

                for (Creature* itr : l_CreatureList)
                    itr->DespawnOrUnsummon();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_imperator_margokAI(creature);
        }
};

/// Cho'gall <Shadow Council> - 78623 (Mythic Only)
class boss_highmaul_cho_gall : public CreatureScript
{
public:
    boss_highmaul_cho_gall() : CreatureScript("boss_highmaul_cho_gall") { }

    enum eSpells
    {
        ///< Cosmetic
        SpellCosmeticVoidOmni       = 169882,
        SpellVoidBubble             = 167081,
        TransitionVisualMissileP1   = 176581,
        TransitionVisualMissileP2   = 176582,
        TransitionVisualMissileP3   = 176583,
        TransitionVisualMissileP4   = 176584,
        ImperatorMargokBonus        = 177528,
        ///< Dark Star
        SpellDarkStarAT             = 178607,
        SpellDarkStarAOE            = 178609,
        ///< Infinite Darkness
        SpellInfiniteDarkness       = 165102,
        ///< Enveloping Night
        SpellEnvelopingNightDummy   = 165876,
        ///< Glimpse of Madness
        SpellGlimpseOfMadnessSearch = 165243,
        SpellGlimpseOfMadnessSpawn  = 165647,
        SpellGlimpseOfMadnessClone  = 165486,   ///< should spawn npc:82242 and clone caster from it 
        SpellGlimpseOfMadnessDummy  = 165664,   ///< unused? infinite aura, maybe for not targetting affected players
        ///< Edge of the void
        SpellEdgeOfTheVoidPeriodic  = 165178,
        SpellEdgeOfTheVoidSearcher  = 166128,
        SpellEdgeOfTheVoidMissile   = 165181
    };

    enum eEvents
    {
        EventSpawnIntroAdds = 1,    // ~25 npc(78641) join the fight during cosmetic intro (30-40sec) with 2 ability
        EventDrainPower,            // cosmetic one

        EventDarkStar,              // bubulle qui pop ? l'emplac d'un joueur et explose 5sec apr?s
        EventGlimpseOfMadness,      // Cho'gall uses every 25 seconds. He creates a shadow copy of a random raid member, which persists until the end of the fight. These copies are stationary and they cannot be attacked, but they spam Gaze of the Abyss Icon Gaze of the Abyss on the closest raid member within a certain radius (we are not sure of the size of the radius, but it appears to be around 10 yards).
        EventInfiniteDarkness,      // aura on 1-3 players every 60secs, trigger entropy mechanics
        EventEnvelopingNight,       // explode every shadow copy if they can (the copy had to miss at least one time gaze of the abyss), the explosion deal damage to the whole raid
        EventSpawnNightTwistedFaithful, // npc(78641) spawn every 30sec during the fight (2x5 in 2 sides of the room)
        EventEdgeOfTheVoid          // enrage
    };

    enum eActions
    {
        ActionStartEvent    = 1,
    };

    enum eMoves
    {
        IntroPos = 1,
    };

    enum eTalks
    {
        Intro1,                 // "You know nothing of the power you meddle with, Mar'gok. (It calls to us. We know! Its power will be ours!)"
        Intro2,                 // "Your reign has come to an end, the infinite night begins. (Darkness comes!)"
        Intro3,                 // engage? : "We have waited long for this moment. The true power of the Stones shall be realized at last! (None shall survive! We shall be the unmaking! Destroy them! Wash over this world!)"
        TalkGlimpseofMadness,   // "Gaze into the abyss! (It sees you! It knows...)"
        TalkEnvelopingNight,    // "Your world will be swallowed in darkness! (All will hear his call!)"
        TalkInfiniteDarkness,   // "Death comes! (We know it well.)"
        TalkDarkStar,           // "The end draws closer! (This is our purpose!)"
        Berserk,                // "The night consumes us! (We have won! All will be as foretold!)"
        Slay,                   // "Embrace the end." "Give in to darkness."
        Death,                  // "He comes... (You can never escape...)"

        TalkMarGokDeath = 20,
        TalkMarGokChoGallTreason = 23
    };

    enum eCreatures
    {
        NpcRuneOfDisplacement   = 77429,
        NpcNightTwistedFaithful = 78641,
        NpcGlimpseOfMadness     = 82242
    };

    struct boss_highmaul_cho_gallAI : public ScriptedAI
    {
        boss_highmaul_cho_gallAI(Creature* creature) : ScriptedAI(creature)
        {
            m_Instance = creature->GetInstanceScript();
        }

        InstanceScript* m_Instance;

        EventMap m_Events;
        EventMap m_CosmeticEvents;

        bool m_IntroDone;
        uint8 m_IntroSpawned;
        uint8 m_AddsSpawned;
        uint32 m_DrainTicks;

        void Reset() override
        {
            m_Events.Reset();
            m_CosmeticEvents.Reset();
            m_IntroDone = false;
            me->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);
        }

        void DoAction(int32 const action) override
        {
            switch (action)
            {
                case eActions::ActionStartEvent:
                {
                    if (m_IntroDone)
                        return;

                    m_IntroDone = true;
                    m_IntroSpawned = 0;
                    m_DrainTicks = 0;

                    me->SetWalk(true);
                    me->SetReactState(ReactStates::REACT_PASSIVE);
                    me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_NPC));
                    me->AddUnitFlag2(UNIT_FLAG2_DISABLE_TURN);
                    me->GetMotionMaster()->MovePoint(IntroPos, g_ChogallEventsPos[1]);
                    Talk(eTalks::Intro1);

                    //Launch adds
                    m_CosmeticEvents.ScheduleEvent(eEvents::EventSpawnIntroAdds, 0);
                    break;
                }
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != MovementGeneratorType::POINT_MOTION_TYPE)
                return;

            switch (id)
            {
            case IntroPos:

                if (m_Instance == nullptr)
                    return;

                me->SetWalk(false);
                me->CastSpell(me, SpellCosmeticVoidOmni, true);

                if (Creature* margok = m_Instance->instance->GetCreature(m_Instance->GetGuidData(eHighmaulCreatures::ImperatorMargok)))
                {
                    // Ensnares Mar'gok
                    margok->CastSpell(margok, eSpells::SpellVoidBubble, true);

                    margok->SetAIAnimKitId(/*AnimKitFlyingRune*/ 6420);
                    //margok->SetAnimTier(3);
                    margok->SetDisableGravity(true);
                    margok->SendSetPlayHoverAnim(true);

                    margok->GetMotionMaster()->MoveJump(g_ChogallEventsPos[2], 15, 10, 42);

                    margok->AI()->Talk(TalkMarGokChoGallTreason);
                }

                AddTimedDelayedOperation(3000 /* timer for mar'gok talk*/, [this]() -> void
                {
                    if (Creature* margok = m_Instance->instance->GetCreature(m_Instance->GetGuidData(eHighmaulCreatures::ImperatorMargok)))
                    {
                        margok->SetFacingToObject(me);
                        margok->AddUnitFlag2(UNIT_FLAG2_DISABLE_TURN);
                    }
                });

                // Cho'gall reply + drain power
                AddTimedDelayedOperation(7500 /* timer for mar'gok talk*/, [this]() -> void
                {
                    Talk(eTalks::Intro2);
                    m_CosmeticEvents.ScheduleEvent(eEvents::EventDrainPower, 0);
                });

                AddTimedDelayedOperation(7500 + 11000 /* timer for drawing the power out*/, [this]() -> void
                {
                    //mar'gok "dies"
                    if (Creature* margok = m_Instance->instance->GetCreature(m_Instance->GetGuidData(eHighmaulCreatures::ImperatorMargok)))
                    {
                        margok->RemoveAura(eSpells::SpellVoidBubble);
                        margok->RemoveUnitFlag2(UNIT_FLAG2_DISABLE_TURN);

                        margok->SetAIAnimKitId(0);
                        //margok->SetAnimTier(0);
                        margok->SetDisableGravity(false);
                        margok->SendSetPlayHoverAnim(false);

                        margok->AddUnitFlag2(UNIT_FLAG2_FEIGN_DEATH);
                        margok->CastSpell(margok, eHighmaulSpells::PermanentFeignDeath, true);
                        margok->GetMotionMaster()->MoveFall();
                        margok->AI()->DoAction(2);  ///< Cancel all events
                        margok->AI()->Talk(TalkMarGokDeath);
                        m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, margok, 1);
                    }

                    me->RemoveAura(eSpells::SpellCosmeticVoidOmni);
                });
                
                AddTimedDelayedOperation(7500 + 11000 + 2000 /* 1-3seconds after the event */, [this]() -> void
                {
                    //cho'gall aggro
                    me->SetReactState(ReactStates::REACT_AGGRESSIVE);
                    me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_NPC));
                    me->RemoveUnitFlag2(UNIT_FLAG2_DISABLE_TURN);
                    me->AddUnitFlag(UNIT_FLAG_PVP_ATTACKABLE);
                    if (Player* victim = me->SelectNearestPlayer(300))
                    {
                        me->GetMotionMaster()->Clear();
                        me->Attack(victim, true);
                        me->GetMotionMaster()->MoveChase(victim);
                    }
                });
                
                break;
            }
        }

        void EnterCombat(Unit* /*attacker*/) override
        {
            Talk(eTalks::Intro3);

            if (m_Instance != nullptr)
                m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me, 1);

            m_CosmeticEvents.ScheduleEvent(eEvents::EventSpawnNightTwistedFaithful, urand(20, 30) * TimeConstants::IN_MILLISECONDS); /// 30sec cd

            m_Events.ScheduleEvent(eEvents::EventDarkStar, 29 * TimeConstants::IN_MILLISECONDS); /// 60sec cd
            m_Events.ScheduleEvent(eEvents::EventGlimpseOfMadness, 20 * TimeConstants::IN_MILLISECONDS); /// 25sec cd
            m_Events.ScheduleEvent(eEvents::EventInfiniteDarkness, urand(8 * TimeConstants::IN_MILLISECONDS, 12 * TimeConstants::IN_MILLISECONDS)); /// 60sec cd
            m_Events.ScheduleEvent(eEvents::EventEnvelopingNight, 55 * TimeConstants::IN_MILLISECONDS); /// 60sec cd
            m_Events.ScheduleEvent(eEvents::EventEdgeOfTheVoid, 5 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS);

            m_AddsSpawned = 0;
        }

        void JustDied(Unit* killer) override
        {
            m_Events.Reset();
            m_CosmeticEvents.Reset();

            Talk(eTalks::Death);

            summons.DespawnAll();

            if (m_Instance != nullptr)
            {
                m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);
                if (Creature* margok = m_Instance->instance->GetCreature(m_Instance->GetGuidData(eHighmaulCreatures::ImperatorMargok)))
                    killer->Kill(margok);

                me->RemoveAllAreaTriggers();

                instance->DoCastSpellOnPlayers(eSpells::ImperatorMargokBonus, me);
            }
        }

        void JustUnregisteredAreaTrigger(AreaTrigger* at) override
        {
            if (at->GetSpellId() == eSpells::SpellDarkStarAT)
                me->CastSpell(at->GetPosition(), eSpells::SpellDarkStarAOE, true);
        }

        void SpellHitTarget(Unit* target, SpellInfo const* spellInfo) override
        {
            if (target == nullptr)
                return;

            switch (spellInfo->Id)
            {
                case eSpells::SpellEdgeOfTheVoidSearcher:
                {
                    me->CastSpell(target->GetPosition(), eSpells::SpellEdgeOfTheVoidMissile, false);
                    for (uint8 i = 0; i < 5; i++)
                    {
                        float dist = frand(0, 70.f);
                        float ang = frand(0, 2.f * float(M_PI));
                        Position pos = { g_CenterPos.m_positionX + dist * cos(ang), g_CenterPos.m_positionY + dist * sin(ang), g_CenterPos.m_positionZ, 0.f };

                        if (!Trinity::IsValidMapCoord(pos.m_positionX, pos.m_positionY))
                            continue;

                        me->CastSpell(pos, eSpells::SpellEdgeOfTheVoidMissile, false);
                    }
                    break;
                }
            }
        }

        void UpdateAI(uint32 const diff) override
        {
            UpdateOperations(diff);

            m_CosmeticEvents.Update(diff);

            switch (m_CosmeticEvents.ExecuteEvent())
            {
                case eEvents::EventSpawnIntroAdds:
                {
                    ///< 45 secs to spawn 25 adds 
                    m_IntroSpawned++;
                    
                    Position pos = g_ChogallEventsPos[urand(3, 4)];

                    if (TempSummon* add = me->SummonCreature(NpcNightTwistedFaithful, pos, TEMPSUMMON_DEAD_DESPAWN))
                        if (Player* player = add->SelectNearestPlayer(200))
                        {
                            add->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);
                            add->Attack(player, true);
                            add->GetMotionMaster()->MoveChase(player);
                        }

                    if (m_IntroSpawned < 25)
                        m_CosmeticEvents.ScheduleEvent(EventSpawnIntroAdds, 500);   ///< less than 45secs
                    break;
                }
                case eEvents::EventDrainPower:
                {
                    ///< 7500 ms to drain the power
                    m_DrainTicks++;

                    std::list<Creature*> RunesList;
                    me->GetCreatureListWithEntryInGrid(RunesList, eCreatures::NpcRuneOfDisplacement, 300);

                    if (Creature* margok = m_Instance->instance->GetCreature(m_Instance->GetGuidData(eHighmaulCreatures::ImperatorMargok)))
                    {
                        if (m_DrainTicks < 25)
                            for (auto rune : RunesList)
                            {
                                if (rune->GetGUID().GetCounter() == 10672866)
                                    for (uint8 l_I = 0; l_I < 4; ++l_I)
                                        rune->CastSpell(margok, eSpells::TransitionVisualMissileP1, true);
                                else if (rune->GetGUID().GetCounter() == 10672872)
                                    for (uint8 l_I = 0; l_I < 5; ++l_I)
                                        rune->CastSpell(margok, eSpells::TransitionVisualMissileP2, true);
                                else if (rune->GetGUID().GetCounter() == 10672873)
                                    for (uint8 l_I = 0; l_I < 5; ++l_I)
                                        rune->CastSpell(margok, eSpells::TransitionVisualMissileP3, true);
                                else if (rune->GetGUID().GetCounter() == 10672854)
                                    for (uint8 l_I = 0; l_I < 6; ++l_I)
                                        rune->CastSpell(margok, eSpells::TransitionVisualMissileP4, true);
                            }

                        if(m_DrainTicks >= 15)
                            for (uint8 l_I = 0; l_I < 5; ++l_I)
                                margok->CastSpell(me, RAND(TransitionVisualMissileP1, TransitionVisualMissileP2, TransitionVisualMissileP3, TransitionVisualMissileP4), true);
                    }

                    if (m_DrainTicks <= 30)
                        m_CosmeticEvents.ScheduleEvent(EventDrainPower, 250);
                    break;
                }
                case eEvents::EventSpawnNightTwistedFaithful:
                {
                    ///< 10npcs must spawn in 3 seconds
                    if (m_AddsSpawned < 10)
                    {
                        m_AddsSpawned++;

                        Position pos = g_ChogallEventsPos[RAND(0, 3, 4)];

                        if (TempSummon* add = me->SummonCreature(NpcNightTwistedFaithful, pos, TEMPSUMMON_DEAD_DESPAWN))
                            if (Player* player = add->SelectNearestPlayer(200))
                            {
                                add->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);
                                add->Attack(player, true);
                                add->GetMotionMaster()->MoveChase(player);
                            }

                        m_CosmeticEvents.ScheduleEvent(EventSpawnNightTwistedFaithful, 300);
                        return;
                    }

                    m_CosmeticEvents.ScheduleEvent(EventSpawnNightTwistedFaithful, 30 * TimeConstants::IN_MILLISECONDS);
                    m_AddsSpawned = 0;
                    break;
                }
            }

            if (!UpdateVictim())
                return;

            m_Events.Update(diff);

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;

            switch (m_Events.ExecuteEvent())
            {
                case eEvents::EventDarkStar:
                {
                    if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 200.0f, true))
                        me->CastSpell(target, eSpells::SpellDarkStarAT, false);

                    m_Events.ScheduleEvent(eEvents::EventDarkStar, 60 * TimeConstants::IN_MILLISECONDS);
                    break;
                }
                case eEvents::EventGlimpseOfMadness:
                {
                    me->CastSpell(me, SpellGlimpseOfMadnessSearch, false);
                    m_Events.ScheduleEvent(eEvents::EventGlimpseOfMadness, 25 * TimeConstants::IN_MILLISECONDS);
                    break;
                }
                case eEvents::EventInfiniteDarkness:
                {
                    me->CastSpell(me, eSpells::SpellInfiniteDarkness, false);
                    m_Events.ScheduleEvent(eEvents::EventInfiniteDarkness, 60 * TimeConstants::IN_MILLISECONDS);
                    break;
                }
                case eEvents::EventEnvelopingNight:
                {
                    me->CastSpell(me, eSpells::SpellEnvelopingNightDummy, false);
                    m_Events.ScheduleEvent(eEvents::EventEnvelopingNight, 60 * TimeConstants::IN_MILLISECONDS);
                    break;
                }
                case eEvents::EventEdgeOfTheVoid:
                {
                    Talk(eTalks::Berserk);
                    me->CastSpell(me, eSpells::SpellEdgeOfTheVoidPeriodic, false);

                    me->GetScheduler().Schedule(13s, [](TaskContext context)
                    {
                        GetContextUnit()->CastSpell(GetContextUnit(), eHighmaulSpells::Berserker, true);
                    });

                    AddTimedDelayedOperation(15000, [this]() -> void
                    {
                        Position pos;
                        //g_CenterPos
                        for (uint8 i = 0; i < 100; ++i)
                        {
                            pos = { g_CenterPos.m_positionX + i * 0.70f * cos((float(M_PI) * i) / 10.f), g_CenterPos.m_positionY + i * 0.70f * sin((float(M_PI) * i) / 10.f), g_CenterPos.m_positionZ, 0 };
                            pos.m_positionZ = me->GetMap()->GetHeight(me->GetPhaseShift(), pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), true, MAX_HEIGHT);
                            me->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), eSpells::SpellEdgeOfTheVoidMissile, true);
                        }

                        for (uint8 i = 0; i < 100; ++i)
                        {
                            pos = { g_CenterPos.m_positionX + (i * 0.70f + 5.f) * cos((float(M_PI) * (i + .5f)) / 10.f), g_CenterPos.m_positionY + (i * 0.70f + 5.f) * sin((float(M_PI) * (i + .5f)) / 10.f), g_CenterPos.m_positionZ, 0.f };
                            pos.m_positionZ = me->GetMap()->GetHeight(me->GetPhaseShift(), pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), true, MAX_HEIGHT);
                            me->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), eSpells::SpellEdgeOfTheVoidMissile, true);
                        }
                    });
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_highmaul_cho_gallAI(creature);
    }
};

/// Rune of Displacement - 77429
class npc_highmaul_rune_of_displacement : public CreatureScript
{
    public:
        npc_highmaul_rune_of_displacement() : CreatureScript("npc_highmaul_rune_of_displacement") { }

        struct npc_highmaul_rune_of_displacementAI : public ScriptedAI
        {
            npc_highmaul_rune_of_displacementAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override { }

            void UpdateAI(uint32 const /*diff*/) override { }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_highmaul_rune_of_displacementAI(creature);
        }
};

/// Arcane Aberration - 77809
/// Displacing Arcane Aberration - 77879 - MM: Displacing + Replication
/// Fortified Arcane Aberration - 77878 - MM: Displacing + Fortified
/// Replicating Arcane Aberration - 77877 - MM: Replication + Fortified
class npc_highmaul_arcane_aberration : public CreatureScript
{
    public:
        npc_highmaul_arcane_aberration() : CreatureScript("npc_highmaul_arcane_aberration") { }

        enum eSpells
        {
            /// Phase 1
            CollapsingEntityAura    = 158703,
            CollapsingEntityTrigger = 158705,
            ReverseDeath            = 157099,
            /// Phase 2
            DisplacerCharge         = 157254,
            ImpactfulPulse          = 160367,
            /// Phase  3
            Fortified               = 157252,
            /// Phase 4
            Replicator              = 157249,
            Replicate               = 160341
        };

        enum eCreatures
        {
            ClassicArcaneAberration     = 77809,
            DisplacingArcaneAberration  = 77879,
            FortifiedArcaneAberration   = 77878,
            ReplicatingArcaneAberration = 77877
        };

        enum eVisuals
        {
            ClassicAberration       = 42489,
            DisplacingAberration    = 45790,
            FortifiedAberration     = 45791,
            ReplicatingAberration   = 45792
        };

        enum eData
        {
            MaxRemnants = 7
        };

        struct npc_highmaul_arcane_aberrationAI : public ScriptedAI
        {
            npc_highmaul_arcane_aberrationAI(Creature* creature) : ScriptedAI(creature)
            {
                m_Instance = creature->GetInstanceScript();
            }

            InstanceScript* m_Instance;

            void Reset() override
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->CastSpell(me, eSpells::CollapsingEntityAura, true);
                me->CastSpell(me, eSpells::ReverseDeath, true);

                switch (me->GetEntry())
                {
                    case eCreatures::DisplacingArcaneAberration:
                    {
                        me->CastSpell(me, eSpells::DisplacerCharge, true);
                        if(me->GetMap()->IsMythic()) me->CastSpell(me, eSpells::Replicator, true);
                        break;
                    }
                    case eCreatures::FortifiedArcaneAberration:
                    {
                        /// The Arcane Aberrations are now Fortified Icon Fortified, having 75% more health
                        /// And being immune to all crowd-control effects.
                        me->CastSpell(me, eSpells::Fortified, true);
                        if (me->GetMap()->IsMythic()) me->CastSpell(me, eSpells::DisplacerCharge, true);
                        break;
                    }
                    case eCreatures::ReplicatingArcaneAberration:
                    {
                        me->CastSpell(me, eSpells::Replicator, true);
                        if (me->GetMap()->IsMythic()) me->CastSpell(me, eSpells::Fortified, true);
                        break;
                    }
                    default:
                        break;
                }

                AddTimedDelayedOperation(3 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    me->SetReactState(ReactStates::REACT_AGGRESSIVE);

                    if (Player* player = me->SelectNearestPlayer(50.0f))
                        AttackStart(player);
                });
            }

            void OnSpellCasted(SpellInfo const* spellInfo) override
            {
                /// I don't know why, but it's sent twice on retail servers ///wired: maybe for sending mixed visualkit in case of two activated runes
                if (spellInfo->Id == eSpells::CollapsingEntityTrigger)
                {
                    switch (me->GetEntry())
                    {
                        case eCreatures::ClassicArcaneAberration:
                        {
                            me->SendPlaySpellVisualKit(eVisuals::ClassicAberration, 0, 20000);
                            me->SendPlaySpellVisualKit(eVisuals::ClassicAberration, 0, 20000);
                            break;
                        }
                        case eCreatures::DisplacingArcaneAberration:
                        {
                            me->SendPlaySpellVisualKit(eVisuals::DisplacingAberration, 0, 20000);
                            if (me->GetMap()->IsMythic())
                                me->SendPlaySpellVisualKit(eVisuals::ReplicatingAberration, 0, 20000);
                            else me->SendPlaySpellVisualKit(eVisuals::DisplacingAberration, 0, 20000);
                            break;
                        }
                        case eCreatures::FortifiedArcaneAberration:
                        {
                            me->SendPlaySpellVisualKit(eVisuals::FortifiedAberration, 0, 20000);
                            if (me->GetMap()->IsMythic())
                                me->SendPlaySpellVisualKit(eVisuals::DisplacingAberration, 0, 20000);
                            else me->SendPlaySpellVisualKit(eVisuals::FortifiedAberration, 0, 20000);
                            break;
                        }
                        case eCreatures::ReplicatingArcaneAberration:
                        {
                            me->SendPlaySpellVisualKit(eVisuals::ReplicatingAberration, 0, 20000);
                            if (me->GetMap()->IsMythic())
                                me->SendPlaySpellVisualKit(eVisuals::FortifiedAberration, 0, 20000);
                            else me->SendPlaySpellVisualKit(eVisuals::ReplicatingAberration, 0, 20000);
                            break;
                        }
                        default:
                            break;
                    }
                }
            }

            void EnterCombat(Unit* /*attacker*/) override
            {
                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me, 2);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                switch (me->GetEntry())
                {
                    case eCreatures::DisplacingArcaneAberration:
                    {
                        me->CastSpell(me, eSpells::ImpactfulPulse, true);

                        if (me->GetMap()->IsMythic())
                            for (uint8 l_I = 0; l_I < eData::MaxRemnants; ++l_I)
                                me->CastSpell(me, eSpells::Replicate, true);

                        break;
                    }
                    case eCreatures::ReplicatingArcaneAberration:
                    {
                        /// Upon death, Replicating Arcane Aberrations split into 7 Arcane Remnants.
                        for (uint8 l_I = 0; l_I < eData::MaxRemnants; ++l_I)
                            me->CastSpell(me, eSpells::Replicate, true);

                        break;
                    }
                    case eCreatures::FortifiedArcaneAberration:
                    {
                        if (me->GetMap()->IsMythic())
                            me->CastSpell(me, eSpells::ImpactfulPulse, true);

                        break;
                    }
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 const diff) override
            {
                ScriptedAI::UpdateAI(diff);

                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_highmaul_arcane_aberrationAI(creature);
        }
};

/// Destructive Resonance - 77637
class npc_highmaul_destructive_resonance : public CreatureScript
{
    public:
        npc_highmaul_destructive_resonance() : CreatureScript("npc_highmaul_destructive_resonance") { }

        enum eSpells
        {
            /// Destructive Resonance
            DestructiveResonanceAura                = 156639,
            BaseMineVisualAura                      = 156961,
            DestructiveResonanceDebuff              = 159200,
            DestructiveResonanceDamage              = 156673,
            /// Destructive Resonance: Displacement
            DestructiveResonanceDisplacementAura    = 164086,
            DisplacementMineVisualAura              = 156959,
            DisplacementVisualAura                  = 156983,
            DestructiveResonanceGrowScaleAura       = 156941,
            /// Destructive Resonance: Fortification
            DestructiveResonanceFortificationAura   = 164088,
            FortificationMineVisualAura             = 156958,
            FortificationVisualAura                 = 156982,
            /// Destructive Resonance: Replication
            DestructiveResonanceReplicationAura     = 164096,
            ReplicationMineVisualAura               = 156957,
            ReplicationVisualAura                   = 156977,
            DestructiveResonanceReplicating         = 156799
        };

        enum eVisuals
        {
            DestructiveResonanceDespawn             = 41168,
            DestructiveResonanceDisplacementDespawn = 45691,
            DestructiveResonanceFortificationDesp   = 45692,
            DestructiveResonanceReplicationDespawn  = 45693
        };

        enum eDatas
        {
            PhaseID = 1,
            /// Misc
            ReplicationDupliCount = 2
        };

        enum ePhases
        {
            MightOfTheCrown = 1,    ///< Phase 1: Might of the Crown
            RuneOfDisplacement,     ///< Phase 2: Rune of Displacement
            DormantRunestones,      ///< Intermission: Dormant Runestones
            RuneOfFortification,    ///< Phase 3: Rune of Fortification
            LineageOfPower,         ///< Intermission: Lineage of Power
            RuneOfReplication,      ///< Phase 4: Rune of Replication

            MythicPhase1,           ///< Phase 1: *Rune of Displacement + *Rune of Replication
            MythicTransition1,      ///< Intermission: Dormant Runestones (same as NM/HM), Rune of Displacement effects activated active
            MythicPhase2,           ///< Phase 2: Rune of Displacement + *Rune of Fortification
            MythicTransition2,      ///< Intermission: Lineage of Power (same as NM/HM), Rune of Fortification active
            MythicPhase3,           ///< Phase 3: *Rune of Replication + *Rune of Fortification
            MythicPhase4ChoGall,    ///< Phase 4: **Cho'gall event
        };

        enum eTalk
        {
            DestructiveResonance
        };

        struct npc_highmaul_destructive_resonanceAI : public ScriptedAI
        {
            npc_highmaul_destructive_resonanceAI(Creature* creature) : ScriptedAI(creature)
            {
                m_CanExplode = false;

                if (InstanceScript* l_Script = creature->GetInstanceScript())
                {
                    if (Creature* l_Margok = ObjectAccessor::GetCreature(*creature, l_Script->GetGuidData(eHighmaulCreatures::ImperatorMargok)))
                    {
                        if (l_Margok->IsAIEnabled)
                            m_Phase = l_Margok->AI()->GetData(eDatas::PhaseID);
                    }
                }
            }

            bool m_CanExplode;

            uint32 m_SpawnTime;

            uint8 m_Phase;

            void Reset() override
            {
                me->AddUnitState(UnitState::UNIT_STATE_ROOT);

                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE));
                me->AddUnitFlag2(UNIT_FLAG2_DISABLE_TURN);

                switch (m_Phase)
                {
                    case ePhases::MightOfTheCrown:
                    {
                        me->CastSpell(me, eSpells::DestructiveResonanceAura, true);

                        AddTimedDelayedOperation(3 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                        {
                            me->RemoveAura(eSpells::DestructiveResonanceAura);

                            me->CastSpell(me, eSpells::BaseMineVisualAura, true);

                            m_CanExplode = true;
                        });

                        break;
                    }
                    case ePhases::MythicPhase1:
                    case ePhases::RuneOfDisplacement:
                    {
                        me->CastSpell(me, eSpells::DestructiveResonanceDisplacementAura, true);

                        AddTimedDelayedOperation(3 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                        {
                            me->RemoveAura(eSpells::DestructiveResonanceDisplacementAura);

                            me->CastSpell(me, eSpells::DisplacementMineVisualAura, true);
                            me->CastSpell(me, eSpells::DisplacementVisualAura, true);

                            me->CastSpell(me, eSpells::DestructiveResonanceGrowScaleAura, true);
                            me->SetScaleDuration(30 * TimeConstants::IN_MILLISECONDS);

                            m_CanExplode = true;
                        });

                        break;
                    }
                    case ePhases::RuneOfFortification:
                    {
                        me->CastSpell(me, eSpells::DestructiveResonanceFortificationAura, true);

                        AddTimedDelayedOperation(3 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                        {
                            me->RemoveAura(eSpells::DestructiveResonanceFortificationAura);

                            me->CastSpell(me, eSpells::FortificationMineVisualAura, true);
                            me->CastSpell(me, eSpells::FortificationVisualAura, true);

                            m_CanExplode = true;
                        });

                        /// The mines caused by Destructive Resonance: Fortification Icon Destructive Resonance: Fortification now last 2 minutes, up from 1 minute.
                        AddTimedDelayedOperation(120 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                        {
                            Despawn();
                        });

                        return;
                    }
                    case ePhases::RuneOfReplication:
                    {
                        me->CastSpell(me, eSpells::DestructiveResonanceReplicationAura, true);

                        AddTimedDelayedOperation(3 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                        {
                            me->RemoveAura(eSpells::DestructiveResonanceReplicationAura);

                            me->CastSpell(me, eSpells::ReplicationMineVisualAura, true);
                            me->CastSpell(me, eSpells::ReplicationVisualAura, true);

                            m_CanExplode = true;
                        });

                        break;
                    }
                    case ePhases::MythicPhase2:
                    {
                        me->CastSpell(me, eSpells::DestructiveResonanceFortificationAura, true);

                        AddTimedDelayedOperation(3 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                        {
                            me->RemoveAura(eSpells::DestructiveResonanceFortificationAura);

                            me->CastSpell(me, eSpells::FortificationMineVisualAura, true);
                            me->CastSpell(me, eSpells::FortificationVisualAura, true);

                            me->CastSpell(me, eSpells::DestructiveResonanceGrowScaleAura, true);
                            me->SetScaleDuration(30 * TimeConstants::IN_MILLISECONDS);

                            m_CanExplode = true;
                        });

                        AddTimedDelayedOperation(120 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                        {
                            Despawn();
                        });

                        return;
                    }
                    case ePhases::MythicPhase4ChoGall:
                    case ePhases::MythicPhase3:
                    {
                        me->CastSpell(me, eSpells::DestructiveResonanceReplicationAura, true);

                        AddTimedDelayedOperation(3 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                        {
                            me->RemoveAura(eSpells::DestructiveResonanceReplicationAura);

                            me->CastSpell(me, eSpells::ReplicationMineVisualAura, true);
                            me->CastSpell(me, eSpells::ReplicationVisualAura, true);

                            m_CanExplode = true;
                        });

                        AddTimedDelayedOperation(120 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                        {
                            Despawn();
                        });

                        return;
                    }
                    default:
                        break;
                }

                m_SpawnTime = 0;

                /// At the end of the 1 minute, the mine despawns harmlessly.
                AddTimedDelayedOperation(60 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    Despawn();
                });
            }

            void UpdateAI(uint32 const diff) override
            {
                m_SpawnTime += diff;

                ScriptedAI::UpdateAI(diff);

                if (!m_CanExplode)
                    return;

                float radius = 3.0f;

                if (m_Phase == ePhases::RuneOfDisplacement || m_Phase == ePhases::MythicPhase1 || m_Phase == ePhases::MythicPhase2)
                    AddPct(radius, float((float)m_SpawnTime / float(30 * TimeConstants::IN_MILLISECONDS) * 100.0f));

                if (radius > 6.0f)
                    radius = 6.0f;

                if (Player* player = me->SelectNearestPlayer(radius))
                {
                    me->CastSpell(player, eSpells::DestructiveResonanceDebuff, true);
                    me->CastSpell(player, eSpells::DestructiveResonanceDamage, true);

                    switch (m_Phase)
                    {
                        case ePhases::MightOfTheCrown:
                        {
                            me->SendPlaySpellVisualKit(eVisuals::DestructiveResonanceDespawn, 0, 20000);
                            break;
                        }
                        case ePhases::RuneOfDisplacement:
                        case ePhases::MythicPhase1:
                        case ePhases::MythicPhase2:
                        {
                            me->SendPlaySpellVisualKit(eVisuals::DestructiveResonanceDisplacementDespawn, 0, 20000);
                            break;
                        }
                        case ePhases::RuneOfFortification:
                        {
                            me->SendPlaySpellVisualKit(eVisuals::DestructiveResonanceFortificationDesp, 0, 20000);
                            break;
                        }
                        case ePhases::RuneOfReplication:
                        {
                            me->SendPlaySpellVisualKit(eVisuals::DestructiveResonanceReplicationDespawn, 0, 20000);
                            break;
                        }
                        default:
                            break;
                    }

                    Talk(eTalk::DestructiveResonance, player);

                    Despawn();

                    m_CanExplode = false;
                }
            }

            void Despawn()
            {
                me->RemoveAllAuras();
                me->DespawnOrUnsummon();

                /// In addition to Destructive Resonance's normal effects, two additional Destructive Resonances are created nearby when it detonates or expires.
                if (m_Phase == ePhases::RuneOfReplication || m_Phase == ePhases::MythicPhase1 || m_Phase == ePhases::MythicPhase3 || m_Phase == ePhases::MythicPhase4ChoGall)
                {
                    if (InstanceScript* l_InstanceScript = me->GetInstanceScript())
                    {
                        if (Creature* l_Margok = ObjectAccessor::GetCreature(*me, l_InstanceScript->GetGuidData(eHighmaulCreatures::ImperatorMargok)))
                        {
                            float radius = 8.0f;
                            Position pos = *me;

                            for (uint8 l_I = 0; l_I < eDatas::ReplicationDupliCount; ++l_I)
                            {
                                float l_O = frand(0, 2.f * float(M_PI));
                                float l_X = pos.m_positionX + (radius * cos(l_O));
                                float l_Y = pos.m_positionY + (radius * sin(l_O));

                                l_Margok->CastSpell(l_X, l_Y, pos.m_positionZ, eSpells::DestructiveResonanceReplicating, true);
                            }
                        }
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_highmaul_destructive_resonanceAI(creature);
        }
};

/// Destructive Resonance (Replication) - 77681
class npc_highmaul_destructive_resonance_replication : public CreatureScript
{
    public:
        npc_highmaul_destructive_resonance_replication() : CreatureScript("npc_highmaul_destructive_resonance_replication") { }

        enum eSpells
        {
            DestructiveResonanceDebuff              = 159200,
            DestructiveResonanceDamage              = 156673,
            /// Destructive Resonance: Replication
            DestructiveResonanceReplicationAura     = 164096,
            ReplicationMineVisualAura               = 156957,
            ReplicationVisualAura                   = 156977,
            DestructiveResonanceReplicating         = 156799
        };

        enum eVisual
        {
            DestructiveResonanceReplicationDespawn = 45693
        };

        enum eTalk
        {
            DestructiveResonance
        };

        struct npc_highmaul_destructive_resonance_replicationAI : public ScriptedAI
        {
            npc_highmaul_destructive_resonance_replicationAI(Creature* creature) : ScriptedAI(creature)
            {
                m_CanExplode = false;
            }

            bool m_CanExplode;

            void Reset() override
            {
                me->AddUnitState(UnitState::UNIT_STATE_ROOT);

                me->SetReactState(ReactStates::REACT_PASSIVE);

                me->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE));
                me->AddUnitFlag2(UNIT_FLAG2_DISABLE_TURN);

                me->CastSpell(me, eSpells::DestructiveResonanceReplicationAura, true);

                AddTimedDelayedOperation(3 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    me->RemoveAura(eSpells::DestructiveResonanceReplicationAura);

                    me->CastSpell(me, eSpells::ReplicationMineVisualAura, true);
                    me->CastSpell(me, eSpells::ReplicationVisualAura, true);

                    m_CanExplode = true;
                });
            }

            void UpdateAI(uint32 const diff) override
            {
                ScriptedAI::UpdateAI(diff);

                if (!m_CanExplode)
                    return;

                float radius = 3.0f;

                if (Player* player = me->SelectNearestPlayer(radius))
                {
                    me->CastSpell(player, eSpells::DestructiveResonanceDebuff, true);
                    me->CastSpell(player, eSpells::DestructiveResonanceDamage, true);

                    me->SendPlaySpellVisualKit(eVisual::DestructiveResonanceReplicationDespawn, 0, 10000);

                    Talk(eTalk::DestructiveResonance, player);

                    Despawn();

                    m_CanExplode = false;
                }
            }

            void Despawn()
            {
                me->RemoveAllAuras();
                me->DespawnOrUnsummon();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_highmaul_destructive_resonance_replicationAI(creature);
        }
};

/// Gorian Warmage - 78121
class npc_highmaul_gorian_warmage : public CreatureScript
{
    public:
        npc_highmaul_gorian_warmage() : CreatureScript("npc_highmaul_gorian_warmage") { }

        enum eSpells
        {
            /// Passive ability that buffs all allies within 25 yards, increasing their damage done by 50% and their attack and casting speed by 50%
            DominanceAura               = 174126,
            Fixate                      = 157763,
            Slow                        = 157801,
            NetherBlast                 = 157769,
            /// Misc
            FortificationAchievement    = 143809,
            PowerOfFortification        = 155040,
            ReplicationAchievement      = 166391,
            PowerOfReplication          = 166389
        };

        enum eEvents
        {
            EventFixate = 1,
            EventSlow,
            EventNetherBlast
        };

        enum eCosmeticEvent
        {
            EventCheckRune = 1
        };

        struct npc_highmaul_gorian_warmageAI : public ScriptedAI
        {
            npc_highmaul_gorian_warmageAI(Creature* creature) : ScriptedAI(creature)
            {
                m_Instance = creature->GetInstanceScript();
            }

            InstanceScript* m_Instance;

            EventMap m_Events;
            EventMap m_CosmeticEvents;

            ObjectGuid m_FixateTarget;

            void Reset() override
            {
                me->AddUnitState(UnitState::UNIT_STATE_ROOT);

                m_FixateTarget = ObjectGuid::Empty;

                me->CastSpell(me, eSpells::DominanceAura, true);

                if (Player* target = me->SelectNearestPlayer(50.0f))
                    AttackStart(target);
            }

            void EnterCombat(Unit* /*attacker*/) override
            {
                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me, 2);

                m_Events.Reset();

                m_CosmeticEvents.Reset();

                m_Events.ScheduleEvent(eEvents::EventFixate, 3 * TimeConstants::IN_MILLISECONDS);
                m_Events.ScheduleEvent(eEvents::EventSlow, 5 * TimeConstants::IN_MILLISECONDS);

                m_CosmeticEvents.ScheduleEvent(eCosmeticEvent::EventCheckRune, 1 * TimeConstants::IN_MILLISECONDS);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (m_Instance != nullptr)
                {
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);

                    if (me->HasAura(eSpells::PowerOfFortification) && me->HasAura(eSpells::PowerOfReplication))
                        m_Instance->SetData(eHighmaulDatas::ImperatorAchievement, 1);
                }
            }

            void UpdateAI(uint32 const diff) override
            {
                m_CosmeticEvents.Update(diff);

                if (m_CosmeticEvents.ExecuteEvent() == eCosmeticEvent::EventCheckRune)
                {
                    std::list<Creature*> l_TriggerList;
                    me->GetCreatureListWithEntryInGrid(l_TriggerList, eHighmaulGameobjects::SLGGenericMoPLargeAoI, 15.0f);

                    for (Creature* l_Trigger : l_TriggerList)
                    {
                        if (l_Trigger->HasAura(eSpells::FortificationAchievement))
                            me->CastSpell(me, eSpells::PowerOfFortification, true);
                        else if (l_Trigger->HasAura(eSpells::ReplicationAchievement))
                            me->CastSpell(me, eSpells::PowerOfReplication, true);
                    }

                    /// Don't need to do that again if the Warmage already has the two auras
                    if (!me->HasAura(eSpells::PowerOfFortification) || !me->HasAura(eSpells::PowerOfReplication))
                        m_CosmeticEvents.ScheduleEvent(eCosmeticEvent::EventCheckRune, 1 * TimeConstants::IN_MILLISECONDS);
                }

                if (!UpdateVictim())
                    return;

                m_Events.Update(diff);

                if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                    return;

                switch (m_Events.ExecuteEvent())
                {
                    case eEvents::EventFixate:
                    {
                        if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 0.0f, true, -eSpells::Fixate))
                        {
                            m_FixateTarget = target->GetGUID();
                            me->CastSpell(target, eSpells::Fixate, true);
                        }

                        m_Events.ScheduleEvent(eEvents::EventNetherBlast, 100);
                        m_Events.ScheduleEvent(eEvents::EventFixate, 15 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case eEvents::EventSlow:
                    {
                        me->CastSpell(me, eSpells::Slow, true);
                        m_Events.ScheduleEvent(eEvents::EventSlow, 17 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case eEvents::EventNetherBlast:
                    {
                        if (Unit* target = ObjectAccessor::GetPlayer(*me, m_FixateTarget))
                            me->CastSpell(target, eSpells::NetherBlast, false);

                        m_Events.ScheduleEvent(eEvents::EventNetherBlast, 200);
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
            return new npc_highmaul_gorian_warmageAI(creature);
        }
};

/// Volatile Anomaly - 78077
class npc_highmaul_volatile_anomaly : public CreatureScript
{
    public:
        npc_highmaul_volatile_anomaly() : CreatureScript("npc_highmaul_volatile_anomaly") { }

        enum eSpells
        {
            Destabilize     = 157657,
            AlphaFadeOut    = 141608
        };

        enum eVisual
        {
            AnimKit = 5709
        };

        struct npc_highmaul_volatile_anomalyAI : public ScriptedAI
        {
            npc_highmaul_volatile_anomalyAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                if (Player* target = me->SelectNearestPlayer(100.0f))
                    AttackStart(target);
            }

            void JustDied(Unit* /*killer*/) override
            {
                me->SetAIAnimKitId(eVisual::AnimKit);

                me->CastSpell(me, eSpells::Destabilize, true);
                me->CastSpell(me, eSpells::AlphaFadeOut, true);
            }

            void UpdateAI(uint32 const diff) override
            {
                ScriptedAI::UpdateAI(diff);

                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_highmaul_volatile_anomalyAI(creature);
        }
};

/// Gorian Reaver - 78549
class npc_highmaul_gorian_reaver : public CreatureScript
{
    public:
        npc_highmaul_gorian_reaver() : CreatureScript("npc_highmaul_gorian_reaver") { }

        enum eSpells
        {
            DevastatingShockwave    = 158547,
            CrushArmor              = 158553,
            KickToTheFace           = 158563
        };

        enum eEvents
        {
            EventCrushArmor = 1,
            EventKickToTheFace,
            EventDevastatingShockwave
        };

        struct npc_highmaul_gorian_reaverAI : public ScriptedAI
        {
            npc_highmaul_gorian_reaverAI(Creature* creature) : ScriptedAI(creature)
            {
                m_Instance = creature->GetInstanceScript();
            }

            InstanceScript* m_Instance;

            EventMap m_Events;

            void Reset() override
            {
                if (Player* target = me->SelectNearestPlayer(200.0f))
                    AttackStart(target);
            }

            void EnterCombat(Unit* /*attacker*/) override
            {
                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me, 2);

                m_Events.Reset();

                m_Events.ScheduleEvent(eEvents::EventCrushArmor, 22 * TimeConstants::IN_MILLISECONDS);
                m_Events.ScheduleEvent(eEvents::EventKickToTheFace, 41 * TimeConstants::IN_MILLISECONDS);
                m_Events.ScheduleEvent(eEvents::EventDevastatingShockwave, 12 * TimeConstants::IN_MILLISECONDS);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (m_Instance != nullptr)
                    m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);
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
                    case eEvents::EventCrushArmor:
                    {
                        if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO))
                            me->CastSpell(target, eSpells::CrushArmor, true);

                        m_Events.ScheduleEvent(eEvents::EventCrushArmor, 11 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case eEvents::EventKickToTheFace:
                    {
                        if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO))
                        {
                            me->CastSpell(target, eSpells::KickToTheFace, true);
                            me->getThreatManager().modifyThreatPercent(target, -100);
                        }

                        m_Events.ScheduleEvent(eEvents::EventKickToTheFace, 25 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    case eEvents::EventDevastatingShockwave:
                    {
                        me->CastSpell(me, eSpells::DevastatingShockwave, true);
                        m_Events.ScheduleEvent(eEvents::EventDevastatingShockwave, 12 * TimeConstants::IN_MILLISECONDS);
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
            return new npc_highmaul_gorian_reaverAI(creature);
        }
};

/// Arcane Remnant - 79388
class npc_highmaul_arcane_remnant : public CreatureScript
{
    public:
        npc_highmaul_arcane_remnant() : CreatureScript("npc_highmaul_arcane_remnant") { }

        enum eSpell
        {
            ReverseDeath = 157099
        };

        struct npc_highmaul_arcane_remnantAI : public ScriptedAI
        {
            npc_highmaul_arcane_remnantAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                me->CastSpell(me, eSpell::ReverseDeath, true);

                AddTimedDelayedOperation(3 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                    if (Player* target = me->SelectNearestPlayer(50.0f))
                        AttackStart(target);
                });
            }

            void UpdateAI(uint32 const diff) override
            {
                ScriptedAI::UpdateAI(diff);

                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_highmaul_arcane_remnantAI(creature);
        }
};

/// Glimpse of Madness - 82242
class npc_highmaul_glimpse_of_madness : public CreatureScript
{
public:
    npc_highmaul_glimpse_of_madness() : CreatureScript("npc_highmaul_glimpse_of_madness") { }

    enum eSpell
    {
        GazeOfTheAbyssCast          = 165595,   //stack aura on multiple casters
        SpellEnvelopingNightDummy   = 165876,
        SpellEnvelopingNightDmg     = 165846,
        SpellEyesofheAbyss          = 176537
    };

    struct npc_highmaul_glimpse_of_madnessAI : public CreatureAI
    {
        npc_highmaul_glimpse_of_madnessAI(Creature* creature) : CreatureAI(creature) { }

        bool m_CanExplode;
        ObjectGuid m_LastNearestTargetGUID;

        void Reset() override
        {
            m_CanExplode = false;
            m_LastNearestTargetGUID = ObjectGuid::Empty;
        }

        void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
        {
            if (spell->Id == SpellEnvelopingNightDummy && m_CanExplode)
            {
                me->CastSpell(me, SpellEnvelopingNightDmg, true);
                me->DisappearAndDie();
            }
        }

        void SpellMissTarget(Unit* /*target*/, SpellInfo const* /*spellInfo*/, SpellMissInfo /*missInfo*/) override
        {
            m_CanExplode = true;
        }

        void DamageTaken(Unit* attacker, uint32& damage) override
        {
            if(attacker->IsPlayer() || attacker->IsControlledByPlayer())
                damage = 0;

            return;
        }

        void UpdateAI(uint32 const /*diff*/) override
        {
            if (Player *victim = me->SelectNearestPlayer(12))
            {
                if (m_LastNearestTargetGUID != victim->GetGUID())
                {
                    if (victim->HasAura(SpellEyesofheAbyss))
                        victim->RemoveAurasDueToSpell(SpellEyesofheAbyss);

                    if (!m_LastNearestTargetGUID.IsEmpty())
                        if (ObjectAccessor::GetPlayer(*me, m_LastNearestTargetGUID) != nullptr)
                            if (victim->HasAura(SpellEyesofheAbyss, me->GetGUID()))
                                victim->RemoveAurasDueToSpell(SpellEyesofheAbyss, me->GetGUID());

                    me->CastSpell(victim, SpellEyesofheAbyss, true);
                    m_LastNearestTargetGUID = victim->GetGUID();
                }
                else if (!m_LastNearestTargetGUID.IsEmpty())
                {
                    if (ObjectAccessor::GetPlayer(*me, m_LastNearestTargetGUID) != nullptr)
                        if (victim->HasAura(SpellEyesofheAbyss, me->GetGUID()))
                            victim->RemoveAurasDueToSpell(SpellEyesofheAbyss, me->GetGUID());
                }
            }

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;

            if (Player *victim = me->SelectNearestPlayer(12))
                me->CastSpell(victim, GazeOfTheAbyssCast);
            else m_CanExplode = true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_highmaul_glimpse_of_madnessAI(creature);
    }
};

/// Night-Twisted Faithful - 78641
class npc_highmaul_night_twisted_faithful : public CreatureScript
{
public:
    npc_highmaul_night_twisted_faithful() : CreatureScript("npc_highmaul_night_twisted_faithful") { }

    enum eSpell
    {
        SpellGrowingShadowsAT   = 176525,
        SpellDarkFrenzyAura     = 175607
    };

    struct npc_highmaul_night_twisted_faithfulAI : public CreatureAI
    {
        npc_highmaul_night_twisted_faithfulAI(Creature* creature) : CreatureAI(creature) { }

        uint32 m_AuraTimer;

        void Reset() override
        {
            m_AuraTimer = 5000;
        }

        void JustDied(Unit* /*killer*/) override
        {
            if(TempSummon* trigger = me->SummonCreature(WORLD_TRIGGER, me->GetPosition()))
                trigger->CastSpell(trigger, eSpell::SpellGrowingShadowsAT);
        }

        void UpdateAI(uint32 const diff) override
        {
            if (m_AuraTimer < diff)
            {
                me->CastSpell(me, eSpell::SpellDarkFrenzyAura);
                m_AuraTimer = 5000;
            }
            else
                m_AuraTimer -= diff;

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_highmaul_night_twisted_faithfulAI(creature);
    }
};

/// Mark of Chaos - 158605
/// Mark of Chaos: Displacement - 164176 - MM: Displacing + Replication
/// Mark of Chaos: Fortification - 164178 - MM: Displacing + Fortified
/// Mark of Chaos: Replication - 164191 - MM: Replication + Fortified
class spell_highmaul_mark_of_chaos : public SpellScriptLoader
{
    public:
        spell_highmaul_mark_of_chaos() : SpellScriptLoader("spell_highmaul_mark_of_chaos") { }

        enum eSpells
        {
            MarkOfChaosAoE              = 158609,
            FetterMarkOfChaosRootAura   = 158619
        };

        class spell_highmaul_mark_of_chaos_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_mark_of_chaos_AuraScript);

            void AfterAuraRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                AuraRemoveMode l_RemoveMode = GetTargetApplication()->GetRemoveMode();
                if (l_RemoveMode == AuraRemoveMode::AURA_REMOVE_BY_DEFAULT)
                    return;

                if (Unit* target = GetTarget())
                {
                    target->CastSpell(target, eSpells::MarkOfChaosAoE, true);
                    target->RemoveAura(eSpells::FetterMarkOfChaosRootAura);
                }
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_highmaul_mark_of_chaos_AuraScript::AfterAuraRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_mark_of_chaos_AuraScript();
        }
};

/// Destructive Resonance - 174116
class spell_highmaul_destructive_resonance : public SpellScriptLoader
{
    public:
        spell_highmaul_destructive_resonance() : SpellScriptLoader("spell_highmaul_destructive_resonance") { }

        class spell_highmaul_destructive_resonance_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_destructive_resonance_AuraScript);

            void OnProc(AuraEffect const* /*aurEff*/, ProcEventInfo& p_EventInfo)
            {
                PreventDefaultAction();

                if (!p_EventInfo.GetDamageInfo())
                    return;

                SpellInfo const* l_ProcSpell = p_EventInfo.GetDamageInfo()->GetSpellInfo();
                if (l_ProcSpell == nullptr)
                    return;

                if (!(l_ProcSpell->SchoolMask & SPELL_SCHOOL_MASK_ARCANE))
                    return;

                /// Moreover, the player who triggers a Destructive Resonance mine is stunned for 1.5 seconds each time he take Arcane damage.
                if (Unit* target = GetTarget())
                {
                    uint32 l_SpellID = GetSpellInfo()->GetEffect(EFFECT_0)->TriggerSpell;
                    target->CastSpell(target, l_SpellID, true);
                }
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_highmaul_destructive_resonance_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_destructive_resonance_AuraScript();
        }
};

/// Branded - 156225
class spell_highmaul_branded : public SpellScriptLoader
{
    public:
        spell_highmaul_branded() : SpellScriptLoader("spell_highmaul_branded") { }

        enum eSpells
        {
            ArcaneWrathDamage = 156239
        };

        enum eData
        {
            BrandedStacks
        };

        enum eTalk
        {
            Branded = 21
        };

        class spell_highmaul_branded_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_branded_AuraScript);

            void AfterAuraRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                AuraRemoveMode l_RemoveMode = GetTargetApplication()->GetRemoveMode();
                if (l_RemoveMode == AuraRemoveMode::AURA_REMOVE_BY_DEFAULT || GetCaster() == nullptr)
                    return;

                /// Caster is Mar'gok
                if (Creature* l_Margok = GetCaster()->ToCreature())
                {
                    if (!l_Margok->IsAIEnabled)
                        return;

                    if (Unit* target = GetTarget())
                    {
                        ObjectGuid guid = target->GetGUID();

                        uint32 l_SpellID = GetSpellInfo()->Id;
                        uint8 l_Stacks = aurEff->GetBase()->GetStackAmount();
                        l_Margok->GetScheduler().Schedule(1s, [l_SpellID, l_Stacks, guid](TaskContext context)
                        {
                            uint8 l_StacksCopy = l_Stacks;

                            if (Creature* l_Margok = GetContextCreature())
                            {
                                if (Unit* target = ObjectAccessor::GetUnit(*l_Margok, guid))
                                {
                                    CustomSpellValues l_Values;
                                    l_Values.AddSpellMod(SpellValueMod::SPELLVALUE_AURA_STACK, l_StacksCopy);

                                    l_Margok->CastCustomSpell(eSpells::ArcaneWrathDamage, l_Values, target, TRIGGERED_FULL_MASK);

                                    /// When Branded expires it inflicts Arcane damage to the wearer and jumps to their closest ally within 200 yards.
                                    /// Each time Arcane Wrath jumps, its damage increases by 25% and range decreases by 50%.
                                    float l_JumpRange = 200.0f;
                                    for (uint8 l_I = 0; l_I < l_Stacks; ++l_I)
                                        l_JumpRange -= CalculatePct(l_JumpRange, 50.0f);

                                    if (Player* l_OtherPlayer = target->SelectNearestPlayer(l_JumpRange))
                                    {
                                        /// Increase jump count
                                        ++l_StacksCopy;

                                        if (Aura* l_Aura = l_Margok->AddAura(l_SpellID, l_OtherPlayer))
                                        {
                                            l_Aura->SetStackAmount(l_StacksCopy);
                                            l_Margok->AI()->Talk(eTalk::Branded, l_OtherPlayer);
                                        }
                                    }
                                }
                            }
                        });
                    }
                }
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_highmaul_branded_AuraScript::AfterAuraRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_branded_AuraScript();
        }
};

/// Branded: Displacement - 164004 - MM: Displacing + Replication
class spell_highmaul_branded_displacement : public SpellScriptLoader
{
    public:
        spell_highmaul_branded_displacement() : SpellScriptLoader("spell_highmaul_branded_displacement") { }

        enum eSpells
        {
            ArcaneWrathDamage   = 156239,
            ArcaneWrathZoneVisu = 160369,
            ArcaneWrathTeleport = 160370
        };

        enum eData
        {
            BrandedStacks
        };

        enum eTalk
        {
            Branded = 21
        };

        class spell_highmaul_branded_displacement_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_branded_displacement_AuraScript);

            Position m_MarkPos;

            void OnAuraApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* target = GetTarget())
                {
                    /// Visual area during 4s to see where you can go without being teleported
                    target->CastSpell(target, eSpells::ArcaneWrathZoneVisu, true);
                    m_MarkPos = *target;
                }
            }

            void OnTick(AuraEffect const* /*aurEff*/)
            {
                if (Unit* target = GetTarget())
                {
                    /// In addition to Arcane Wrath's normal effects, Branded Players are unable to move more than 10 yards from the location they were marked.
                    /// Attempting to leave the marked area will teleport the player back to the location they were originally marked.
                    if (target->GetDistance(m_MarkPos) > 10.0f)
                        target->CastSpell(m_MarkPos, eSpells::ArcaneWrathTeleport, true);
                }
            }

            void AfterAuraRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                AuraRemoveMode l_RemoveMode = GetTargetApplication()->GetRemoveMode();
                if (l_RemoveMode == AuraRemoveMode::AURA_REMOVE_BY_DEFAULT || GetCaster() == nullptr)
                    return;

                /// Caster is Mar'gok
                if (Creature* l_Margok = GetCaster()->ToCreature())
                {
                    if (!l_Margok->IsAIEnabled)
                        return;

                    if (Unit* target = GetTarget())
                    {
                        ObjectGuid guid = target->GetGUID();

                        uint32 l_SpellID = GetSpellInfo()->Id;
                        uint8 l_Stacks = aurEff->GetBase()->GetStackAmount();
                        l_Margok->GetScheduler().Schedule(1s, [l_SpellID, l_Stacks, guid](TaskContext context)
                        {
                            uint8 l_StackCopy = l_Stacks;

                            if (Creature* l_Margok = GetContextCreature())
                            {
                                if (Unit* target = ObjectAccessor::GetUnit(*l_Margok, guid))
                                {
                                    CustomSpellValues l_Values;
                                    l_Values.AddSpellMod(SpellValueMod::SPELLVALUE_AURA_STACK, l_StackCopy);

                                    l_Margok->CastCustomSpell(eSpells::ArcaneWrathDamage, l_Values, target, TRIGGERED_FULL_MASK);

                                    /// When Branded expires it inflicts Arcane damage to the wearer and jumps to their closest ally within 200 yards.
                                    /// Each time Arcane Wrath jumps, its damage increases by 25% and range decreases by 50%.
                                    float l_JumpRange = 200.0f;
                                    for (uint8 l_I = 0; l_I < l_StackCopy; ++l_I)
                                        l_JumpRange -= CalculatePct(l_JumpRange, 50.0f);

                                    if (Player* l_OtherPlayer = target->SelectNearestPlayer(l_JumpRange))
                                    {
                                        /// Increase jump count
                                        ++l_StackCopy;

                                        if (Aura* l_Aura = l_Margok->AddAura(l_SpellID, l_OtherPlayer))
                                        {
                                            l_Aura->SetStackAmount(l_StackCopy);
                                            l_Margok->AI()->Talk(eTalk::Branded, l_OtherPlayer);
                                        }
                                    }
                                }
                            }
                        });
                    }
                }
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_highmaul_branded_displacement_AuraScript::OnAuraApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_highmaul_branded_displacement_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_highmaul_branded_displacement_AuraScript::AfterAuraRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_branded_displacement_AuraScript();
        }
};

/// Branded: Fortification - 164005 - MM: Displacing + Fortified
class spell_highmaul_branded_fortification : public SpellScriptLoader
{
    public:
        spell_highmaul_branded_fortification() : SpellScriptLoader("spell_highmaul_branded_fortification") { }

        enum eSpells
        {
            ArcaneWrathDamage = 156239
        };

        enum eData
        {
            BrandedStacks
        };

        enum eTalk
        {
            Branded = 21
        };

        class spell_highmaul_branded_fortification_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_branded_fortification_AuraScript);

            void AfterAuraRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                AuraRemoveMode l_RemoveMode = GetTargetApplication()->GetRemoveMode();
                if (l_RemoveMode == AuraRemoveMode::AURA_REMOVE_BY_DEFAULT || GetCaster() == nullptr)
                    return;

                /// Caster is Mar'gok
                if (Creature* l_Margok = GetCaster()->ToCreature())
                {
                    if (!l_Margok->IsAIEnabled)
                        return;

                    if (Unit* target = GetTarget())
                    {
                        ObjectGuid guid = target->GetGUID();

                        uint32 l_SpellID = GetSpellInfo()->Id;
                        uint8 l_Stacks = aurEff->GetBase()->GetStackAmount();
                        l_Margok->GetScheduler().Schedule(1s, [l_SpellID, l_Stacks, guid](TaskContext context)
                        {
                            uint8 l_StacksCopy = l_Stacks;

                            if (Creature* l_Margok = GetContextCreature())
                            {
                                if (Unit* target = ObjectAccessor::GetUnit(*l_Margok, guid))
                                {
                                    CustomSpellValues l_Values;
                                    l_Values.AddSpellMod(SpellValueMod::SPELLVALUE_AURA_STACK, l_StacksCopy);

                                    l_Margok->CastCustomSpell(eSpells::ArcaneWrathDamage, l_Values, target, TRIGGERED_FULL_MASK);

                                    /// When Branded expires it inflicts Arcane damage to the wearer and jumps to their closest ally within 200 yards.
                                    /// Each time Arcane Wrath jumps, its damage increases by 25% and range decreases by 25%.
                                    float l_JumpRange = 200.0f;
                                    for (uint8 l_I = 0; l_I < l_StacksCopy; ++l_I)
                                        l_JumpRange -= CalculatePct(l_JumpRange, 25.0f);

                                    if (Player* l_OtherPlayer = target->SelectNearestPlayer(l_JumpRange))
                                    {
                                        /// Increase jump count
                                        ++l_StacksCopy;

                                        if (Aura* l_Aura = l_Margok->AddAura(l_SpellID, l_OtherPlayer))
                                        {
                                            l_Aura->SetStackAmount(l_StacksCopy);
                                            l_Margok->AI()->Talk(eTalk::Branded, l_OtherPlayer);
                                        }
                                    }
                                }
                            }
                        });
                    }
                }
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_highmaul_branded_fortification_AuraScript::AfterAuraRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_branded_fortification_AuraScript();
        }
};

/// Branded: Replication - 164006 - MM: Replication + Fortified
class spell_highmaul_branded_replication : public SpellScriptLoader
{
    public:
        spell_highmaul_branded_replication() : SpellScriptLoader("spell_highmaul_branded_replication") { }

        enum eSpells
        {
            ArcaneWrathDamage = 156239
        };

        enum eData
        {
            BrandedStacks
        };

        enum eTalk
        {
            Branded = 21
        };

        class spell_highmaul_branded_replication_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_branded_replication_AuraScript);

            void AfterAuraRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                AuraRemoveMode l_RemoveMode = GetTargetApplication()->GetRemoveMode();
                if (l_RemoveMode == AuraRemoveMode::AURA_REMOVE_BY_DEFAULT || GetCaster() == nullptr)
                    return;

                /// Caster is Mar'gok
                if (Creature* l_Margok = GetCaster()->ToCreature())
                {
                    if (!l_Margok->IsAIEnabled)
                        return;

                    if (Unit* target = GetTarget())
                    {
                        ObjectGuid guid = target->GetGUID();

                        uint32 l_SpellID = GetSpellInfo()->Id;
                        uint8 l_Stacks = aurEff->GetBase()->GetStackAmount();
                        l_Margok->GetScheduler().Schedule(1s, [l_SpellID, l_Stacks, guid](TaskContext context)
                        {
                            uint8 l_StacksCopy = l_Stacks;

                            if (Creature* l_Margok = GetContextCreature())
                            {
                                if (Unit* target = ObjectAccessor::GetUnit(*l_Margok, guid))
                                {
                                    CustomSpellValues l_Values;
                                    l_Values.AddSpellMod(SpellValueMod::SPELLVALUE_AURA_STACK, l_StacksCopy);

                                    l_Margok->CastCustomSpell(eSpells::ArcaneWrathDamage, l_Values, target, TRIGGERED_FULL_MASK);

                                    /// When Branded expires it inflicts Arcane damage to the wearer and jumps to their closest ally within 200 yards.
                                    /// Each time Arcane Wrath jumps, its damage increases by 25% and range decreases by 25%.
                                    float l_JumpRange = 200.0f;
                                    for (uint8 l_I = 0; l_I < l_StacksCopy; ++l_I)
                                        l_JumpRange -= CalculatePct(l_JumpRange, 25.0f);

                                    /// In addition to Arcane Wrath's normal effects, a second player will be Branded the first time Arcane Wrath jumps.
                                    if (l_StacksCopy <= 1)
                                    {
                                        std::list<Player*> l_PlrList;
                                        target->GetPlayerListInGrid(l_PlrList, l_JumpRange);

                                        if (l_PlrList.size() > 2)
                                        {
                                            l_PlrList.sort(Trinity::ObjectDistanceOrderPred(target));
                                            Trinity::Containers::RandomResize(l_PlrList, 2);
                                        }

                                        /// Increase jump count
                                        ++l_StacksCopy;

                                        for (Player* player : l_PlrList)
                                        {
                                            if (Aura* l_Aura = l_Margok->AddAura(l_SpellID, player))
                                            {
                                                l_Aura->SetStackAmount(l_StacksCopy);
                                                l_Margok->AI()->Talk(eTalk::Branded, player);
                                            }
                                        }

                                        return;
                                    }

                                    std::list<Player*> l_PlrList;
                                    target->GetPlayerListInGrid(l_PlrList, l_JumpRange);

                                    /// It cannot jumps twice on the same player at the same time
                                    if (!l_PlrList.empty())
                                        l_PlrList.remove_if(Trinity::UnitAuraCheck(true, l_SpellID));

                                    if (!l_PlrList.empty())
                                    {
                                        l_PlrList.sort(Trinity::ObjectDistanceOrderPred(target));

                                        if (Player* l_OtherPlayer = l_PlrList.front())
                                        {
                                            /// Increase jump count
                                            ++l_StacksCopy;

                                            if (Aura* l_Aura = l_Margok->AddAura(l_SpellID, l_OtherPlayer))
                                            {
                                                l_Aura->SetStackAmount(l_StacksCopy);
                                                l_Margok->AI()->Talk(eTalk::Branded, l_OtherPlayer);
                                            }
                                        }
                                    }
                                }
                            }
                        });
                    }
                }
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_highmaul_branded_replication_AuraScript::AfterAuraRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_branded_replication_AuraScript();
        }
};

/// Arcane Wrath (damage) - 156239
class spell_highmaul_arcane_wrath_damage : public SpellScriptLoader
{
    public:
        spell_highmaul_arcane_wrath_damage() : SpellScriptLoader("spell_highmaul_arcane_wrath_damage") { }

        class spell_highmaul_arcane_wrath_damage_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_highmaul_arcane_wrath_damage_SpellScript);

            void HandleDamage()
            {
                /// When Branded expires it inflicts Arcane damage to the wearer and jumps to their closest ally within 200 yards.
                /// Each time Arcane Wrath jumps, its damage increases by 25% and range decreases by 50%.
                int32 l_Damage = GetHitDamage();
                uint8 l_Stacks = 1;// GetSpell()->GetSpellValue(SpellValueMod::SPELLVALUE_AURA_STACK);
                AddPct(l_Damage, int32(25 * l_Stacks));

                SetHitDamage(l_Damage);
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_highmaul_arcane_wrath_damage_SpellScript::HandleDamage);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_highmaul_arcane_wrath_damage_SpellScript();
        }
};

/// Transition Visuals - 176580
class spell_highmaul_transition_visuals : public SpellScriptLoader
{
    public:
        spell_highmaul_transition_visuals() : SpellScriptLoader("spell_highmaul_transition_visuals") { }

        enum eSpells
        {
            TransitionVisualMissileP1   = 176581,
            TransitionVisualMissileP2   = 176582,
            TransitionVisualMissileP3   = 176583
        };

        enum eDatas
        {
            PhaseID         = 1,
            MissileCountP1  = 6,
            MissileCountP2  = 3,
            MissileCountP3  = 2
        };

        enum ePhases
        {
            RuneOfDisplacement  = 2,    ///< Phase 2: Rune of Displacement
            DormantRunestones   = 3,    ///< Intermission: Dormant Runestones
            LineageOfPower      = 5,    ///< Intermission: Lineage of Power

            MythicTransition1   = 8,    ///< Intermission: Dormant Runestones (same as NM/HM), Rune of Displacement effects activated active
            MythicTransition2   = 10,   ///< Intermission: Lineage of Power (same as NM/HM), Rune of Fortification active

        };

        class spell_highmaul_transition_visuals_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_transition_visuals_AuraScript);

            void OnTick(AuraEffect const* /*aurEff*/)
            {
                if (Unit* target = GetTarget())
                {
                    if (Creature* l_Margok = target->FindNearestCreature(eHighmaulCreatures::ImperatorMargok, 40.0f))
                    {
                        if (!l_Margok->IsAIEnabled)
                            return;

                        uint8 l_Phase = l_Margok->AI()->GetData(eDatas::PhaseID);

                        switch (l_Phase)
                        {
                            case ePhases::RuneOfDisplacement:
                            {
                                for (uint8 l_I = 0; l_I < eDatas::MissileCountP1; ++l_I)
                                    target->CastSpell(l_Margok, eSpells::TransitionVisualMissileP1, true);

                                break;
                            }
                            case ePhases::MythicTransition1:
                            case ePhases::DormantRunestones:
                            {
                                for (uint8 l_I = 0; l_I < eDatas::MissileCountP2; ++l_I)
                                    target->CastSpell(l_Margok, eSpells::TransitionVisualMissileP2, true);

                                break;
                            }
                            case ePhases::MythicTransition2:
                            case ePhases::LineageOfPower:
                            {
                                for (uint8 l_I = 0; l_I < eDatas::MissileCountP3; ++l_I)
                                    target->CastSpell(l_Margok, eSpells::TransitionVisualMissileP3, true);

                                break;
                            }
                            default:
                                break;
                        }
                    }
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_highmaul_transition_visuals_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_transition_visuals_AuraScript();
        }
};

/// Dominance Aura - 174126
class spell_highmaul_dominance_aura : public SpellScriptLoader
{
    public:
        spell_highmaul_dominance_aura() : SpellScriptLoader("spell_highmaul_dominance_aura") { }

        class spell_highmaul_dominance_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_dominance_aura_AuraScript);

            enum eSpell
            {
                DominanceAuraBuff = 174128
            };

            enum eData
            {
                InvisDisplay = 11686
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
                            std::list<Unit*> targetList;
                            float radius = 40.0f;

                            Trinity::AnyFriendlyUnitInObjectRangeCheck l_Check(caster, caster, radius);
                            Trinity::UnitListSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> l_Searcher(caster, targetList, l_Check);
                            Cell::VisitAllObjects(caster, l_Searcher, radius);

                            targetList.remove(caster);

                            for (Unit* itr : targetList)
                            {
                                if (itr->GetDisplayId() == eData::InvisDisplay)
                                    continue;

                                if (itr->GetDistance(caster) <= 25.0f)
                                {
                                    if (!itr->HasAura(eSpell::DominanceAuraBuff))
                                        caster->CastSpell(itr, eSpell::DominanceAuraBuff, true);
                                }
                                else
                                {
                                    if (itr->HasAura(eSpell::DominanceAuraBuff))
                                        itr->RemoveAura(eSpell::DominanceAuraBuff);
                                }
                            }
                        }

                        m_CheckTimer = 500;
                    }
                    else
                        m_CheckTimer -= diff;
                }
            }

            void Register() override
            {
                OnAuraUpdate += AuraUpdateFn(spell_highmaul_dominance_aura_AuraScript::OnUpdate);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_dominance_aura_AuraScript();
        }
};

/// Force Nova: Fortified - 157323
class spell_highmaul_force_nova_fortified : public SpellScriptLoader
{
    public:
        spell_highmaul_force_nova_fortified() : SpellScriptLoader("spell_highmaul_force_nova_fortified") { }

        enum eSpell
        {
            ForceNovaFortificationDummy = 164253
        };

        class spell_highmaul_force_nova_fortified_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_force_nova_fortified_AuraScript);

            void OnTick(AuraEffect const* /*aurEff*/)
            {
                if (Unit* target = GetTarget())
                    target->CastSpell(target, eSpell::ForceNovaFortificationDummy, true);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_highmaul_force_nova_fortified_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_force_nova_fortified_AuraScript();
        }
};

/// Devastating Shockwave - 158547
class spell_highmaul_devastating_shockwave : public SpellScriptLoader
{
    public:
        spell_highmaul_devastating_shockwave() : SpellScriptLoader("spell_highmaul_devastating_shockwave") { }

        class spell_highmaul_devastating_shockwave_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_highmaul_devastating_shockwave_SpellScript);

            enum eSpell
            {
                TargetRestrict = 19856
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
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_highmaul_devastating_shockwave_SpellScript::CorrectTargets, EFFECT_0, TARGET_UNIT_CONE_ENEMY_104);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_highmaul_devastating_shockwave_SpellScript();
        }
};

/// Force Nova (DoT) - 157353
class spell_highmaul_force_nova_dot : public SpellScriptLoader
{
    public:
        spell_highmaul_force_nova_dot() : SpellScriptLoader("spell_highmaul_force_nova_dot") { }

        enum eSpell
        {
            ForceNovaReplicationAoEDamage = 157357  ///< Damaging spell for allies
        };

        enum eData
        {
            PhaseID = 1
        };

        enum ePhase
        {
            RuneOfReplication = 6,
            MythicPhase1 = 7,
            MythicPhase3 = 11,
            MythicPhase4ChoGall = 12,    
        };

        class spell_highmaul_force_nova_dot_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_force_nova_dot_AuraScript);

            void OnTick(AuraEffect const* /*aurEff*/)
            {
                if (Unit* target = GetTarget())
                {
                    if (Creature* l_Margok = target->FindNearestCreature(eHighmaulCreatures::ImperatorMargok, 40.0f))
                    {
                        if (!l_Margok->IsAIEnabled)
                            return;

                        uint8 l_Phase = l_Margok->AI()->GetData(eData::PhaseID);
                        if (l_Phase == ePhase::RuneOfReplication || l_Phase == ePhase::MythicPhase1 || 
                            l_Phase == ePhase::MythicPhase3 || l_Phase == ePhase::MythicPhase4ChoGall)
                            target->CastSpell(target, eSpell::ForceNovaReplicationAoEDamage, true);
                    }
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_highmaul_force_nova_dot_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_force_nova_dot_AuraScript();
        }
};

/// Orbs of Chaos (Dummy aura) - 160447
class spell_highmaul_orbs_of_chaos_aura : public SpellScriptLoader
{
    public:
        spell_highmaul_orbs_of_chaos_aura() : SpellScriptLoader("spell_highmaul_orbs_of_chaos_aura") { }

        enum eSpells
        {
            OrbsOfChaosSummoning = 158639
        };

        enum eTalk
        {
            OrbsOfChaos = 22
        };

        enum eData
        {
            OrbOfChaosAngle = 2
        };

        class spell_highmaul_orbs_of_chaos_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_orbs_of_chaos_aura_AuraScript);

            void AfterAuraRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                AuraRemoveMode l_RemoveMode = GetTargetApplication()->GetRemoveMode();
                if (l_RemoveMode == AuraRemoveMode::AURA_REMOVE_BY_DEFAULT)
                    return;

                if (Unit* target = GetTarget())
                {
                    target->CastSpell(target, eSpells::OrbsOfChaosSummoning, true);

                    if (Creature* l_Margok = target->FindNearestCreature(eHighmaulCreatures::ImperatorMargok, 300.0f))
                    {
                        if (!l_Margok->IsAIEnabled)
                            return;

                        l_Margok->AI()->SetData(eData::OrbOfChaosAngle, 0);
                        l_Margok->AI()->Talk(eTalk::OrbsOfChaos, target);

                        ObjectGuid guid = target->GetGUID();
                        l_Margok->GetScheduler().Schedule(2s, [guid](TaskContext context)
                        {
                            if (Unit* target = ObjectAccessor::GetUnit(*GetContextUnit(), guid))
                                target->CastSpell(target, eSpells::OrbsOfChaosSummoning, true);
                        });
                }
                }
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_highmaul_orbs_of_chaos_aura_AuraScript::AfterAuraRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_orbs_of_chaos_aura_AuraScript();
        }
};

/// Volatile Anomalies - 157265
class spell_highmaul_volatile_anomalies : public SpellScriptLoader
{
    public:
        spell_highmaul_volatile_anomalies() : SpellScriptLoader("spell_highmaul_volatile_anomalies") { }

        enum eData
        {
            PhaseID = 1
        };

        enum eSpells
        {
            VolatileAnomalies1  = 158512,
            VolatileAnomalies2  = 159158,
            VolatileAnomalies3  = 159159
        };

        enum ePhases
        {
            MightOfTheCrown     = 1,    ///< Phase 1: Might of the Crown
            DormantRunestones   = 3,    ///< Intermission: Dormant Runestones
            LineageOfPower      = 5,    ///< Intermission: Lineage of Power

            MythicTransition1   = 8,    ///< Intermission: Dormant Runestones (same as NM/HM), Rune of Displacement effects activated active
            MythicTransition2   = 10,   ///< Intermission: Lineage of Power (same as NM/HM), Rune of Fortification active
        };

        class spell_highmaul_volatile_anomalies_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_highmaul_volatile_anomalies_AuraScript);

            void OnTick(AuraEffect const* /*aurEff*/)
            {
                if (Unit* target = GetTarget())
                {
                    if (Creature* l_Margok = target->FindNearestCreature(eHighmaulCreatures::ImperatorMargok, 150.0f))
                    {
                        if (!l_Margok->IsAIEnabled)
                            return;

                        switch (l_Margok->AI()->GetData(eData::PhaseID))
                        {
                            case ePhases::MythicTransition1:
                            case ePhases::DormantRunestones:
                            {
                                target->CastSpell(g_VolatileAnomalyPos[0], eSpells::VolatileAnomalies1, true);
                                target->CastSpell(g_VolatileAnomalyPos[0], eSpells::VolatileAnomalies2, true);
                                target->CastSpell(g_VolatileAnomalyPos[0], eSpells::VolatileAnomalies3, true);
                                break;
                            }
                            case ePhases::LineageOfPower:
                            case ePhases::MythicTransition2:
                            {
                                target->CastSpell(g_VolatileAnomalyPos[1], eSpells::VolatileAnomalies1, true);
                                target->CastSpell(g_VolatileAnomalyPos[1], eSpells::VolatileAnomalies2, true);
                                target->CastSpell(g_VolatileAnomalyPos[1], eSpells::VolatileAnomalies3, true);
                                break;
                            }
                            default:
                                break;
                        }
                    }
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_highmaul_volatile_anomalies_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_highmaul_volatile_anomalies_AuraScript();
        }
};

///< Glimpse of Madness - 165647
class spell_highmaul_glimpse_of_madness : public SpellScriptLoader
{
public:
    spell_highmaul_glimpse_of_madness() : SpellScriptLoader("spell_highmaul_glimpse_of_madness") { }

    class spell_highmaul_glimpse_of_madness_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_highmaul_glimpse_of_madness_SpellScript);

        enum eEnums
        {
            SpellGlimpseOfMadnessClone = 165486,
            NpcGlimpseOfMadness = 82242
        };

        void SummonClone(SpellEffIndex /*effIndex*/)
        {
            if (GetHitDest() == nullptr)
                return;

            if (Unit* caster = GetCaster())
                if (TempSummon *clone = caster->SummonCreature(NpcGlimpseOfMadness, GetHitDest()->GetPosition()))
                    caster->CastSpell(clone, SpellGlimpseOfMadnessClone, true);
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_highmaul_glimpse_of_madness_SpellScript::SummonClone, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_highmaul_glimpse_of_madness_SpellScript();
    }
};

/// Gaze of the Abyss - 165595
class spell_highmaul_gaze_of_the_abyss : public SpellScriptLoader
{
public:
    spell_highmaul_gaze_of_the_abyss() : SpellScriptLoader("spell_highmaul_gaze_of_the_abyss") { }

    enum eSpells
    {
        GazeoftheAbyssDmg = 178543
    };

    class spell_highmaul_gaze_of_the_abyss_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_highmaul_gaze_of_the_abyss_AuraScript);

        void AfterAuraRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit *victim = GetTarget())
                victim->CastSpell(victim, GazeoftheAbyssDmg, true);
        }

        void Register() override
        {
            AfterEffectRemove += AuraEffectRemoveFn(spell_highmaul_gaze_of_the_abyss_AuraScript::AfterAuraRemove, EFFECT_1, SPELL_AURA_MOD_MECHANIC_DAMAGE_TAKEN_PERCENT, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_highmaul_gaze_of_the_abyss_AuraScript();
    }
};

///< Infinite Darkness - 165102
class spell_highmaul_infinite_darkness : public SpellScriptLoader
{
public:
    spell_highmaul_infinite_darkness() : SpellScriptLoader("spell_highmaul_infinite_darkness") { }

    enum eSpells
    {
        SpellEntropy = 165116
    };

    class spell_highmaul_infinite_darkness_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_highmaul_infinite_darkness_AuraScript);

        bool Load() override
        { 
            m_HealAbsorbAmount = 0;
            return true;
        }

        uint32 m_HealAbsorbAmount;

        void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
        {
            amount = 500000000;
        }

        void OnAbsorb(AuraEffect* /*aurEff*/, DamageInfo& /*dmgInfo*/, uint32& absorbAmount)
        {
            m_HealAbsorbAmount += absorbAmount;
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            PreventDefaultAction();

            if (Unit* victim = GetTarget())
            {
                if (AuraEffect* auraeff = GetTarget()->GetAuraEffect(GetSpellInfo()->GetEffect(EFFECT_0)->TriggerSpell, EFFECT_0))
                    auraeff->SetAmount(0);

                std::list<Player*> playersAlly;
                victim->GetPlayerListInGrid(playersAlly, 250.f);

                int32 finalShieldAmount = m_HealAbsorbAmount / playersAlly.size();

                for (Player* ally : playersAlly)
                    victim->CastCustomSpell(ally, SpellEntropy, &finalShieldAmount, nullptr, nullptr, true);
            }
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_highmaul_infinite_darkness_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_HEAL_ABSORB);
            AfterEffectAbsorb += AuraEffectAbsorbFn(spell_highmaul_infinite_darkness_AuraScript::OnAbsorb, EFFECT_0);
            OnEffectRemove += AuraEffectRemoveFn(spell_highmaul_infinite_darkness_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_SCHOOL_HEAL_ABSORB, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_highmaul_infinite_darkness_AuraScript();
    }
};

/// Orb of Chaos - 158639
class areatrigger_highmaul_orb_of_chaos : public AreaTriggerAI
{
    public:
        areatrigger_highmaul_orb_of_chaos(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger)
        {
            m_DamageTimer = 0;
        }

        enum eSpell
        {
            OrbOfChaosDamage = 158648
        };

        enum eData
        {
            OrbOfChaosAngle = 2
        };

        uint32 m_DamageTimer;

        void OnCreate() override
        {
            Position p_DestinationPosition = at->GetPosition();
            m_DamageTimer = 1 * TimeConstants::IN_MILLISECONDS;

            if (InstanceScript* l_InstanceScript = at->GetCaster()->GetInstanceScript())
            {
                if (Creature* l_Margok = ObjectAccessor::GetCreature(*at->GetCaster(), l_InstanceScript->GetGuidData(eHighmaulCreatures::ImperatorMargok)))
                {
                    if (!l_Margok->IsAIEnabled)
                        return;

                    float l_Angle = 0.0f;

                    if (Creature* l_Prison = at->GetCaster()->FindNearestCreature(eHighmaulCreatures::KingPrison, 150.0f))
                        l_Angle = at->GetCaster()->GetAngle(l_Prison);

                    uint8 l_Count       = l_Margok->AI()->GetData(eData::OrbOfChaosAngle);
                    float l_AddedVal    = 2 * float(M_PI) / 8.0f;

                    l_Angle = l_Angle + (l_Count * l_AddedVal);

                    if (l_Count >= 7)
                        l_Margok->AI()->SetData(eData::OrbOfChaosAngle, 0);
                    else
                        l_Margok->AI()->SetData(eData::OrbOfChaosAngle, ++l_Count);

                    float radius = 250.0f;
                    p_DestinationPosition.m_positionX = p_DestinationPosition.m_positionX + (radius * cos(l_Angle));
                    p_DestinationPosition.m_positionY = p_DestinationPosition.m_positionY + (radius * sin(l_Angle));
                }
            }

            at->SetDestination(p_DestinationPosition, 30 * TimeConstants::IN_MILLISECONDS);
        }

        void OnUpdate(uint32 diff) override
        {
            if (m_DamageTimer)
            {
                if (m_DamageTimer <= diff)
                {
                    std::list<Player*> targetList;
                    float radius = 1.5f;

                    Trinity::AnyPlayerInObjectRangeCheck l_Check(at, radius);
                    Trinity::PlayerListSearcher<Trinity::AnyPlayerInObjectRangeCheck> l_Searcher(at, targetList, l_Check);
                    Cell::VisitAllObjects(at, l_Searcher, radius);

                    for (Player* player : targetList)
                        player->CastSpell(player, eSpell::OrbOfChaosDamage, true);

                    m_DamageTimer = 200;
                }
                else
                    m_DamageTimer -= diff;
            }
        }
};

/// Growing Shadows - 176525
class areatrigger_highmaul_growing_shadows : public AreaTriggerAI
{
public:
    areatrigger_highmaul_growing_shadows(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    enum eSpell
    {
        SpellGrowingShadowsDmg = 176533
    };

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->HasAura(SpellGrowingShadowsDmg) && (unit->GetTypeId() == TYPEID_PLAYER || unit->IsCharmedOwnedByPlayerOrPlayer()) && unit->IsAlive())
            unit->AddAura(SpellGrowingShadowsDmg, unit);
    }

    void OnUnitExit(Unit* unit) override
    {
        if (unit->HasAura(SpellGrowingShadowsDmg))
            unit->RemoveAura(SpellGrowingShadowsDmg);
    }

    void OnRemove() override
    {
        for (auto guid : at->GetInsideUnits())
            if (Unit* target = ObjectAccessor::GetUnit(*at, guid))
                target->RemoveAurasDueToSpell(SpellGrowingShadowsDmg);
    }
};

void AddSC_boss_imperator_margok()
{
    /// Boss
    new boss_imperator_margok();
    new boss_highmaul_cho_gall();

    /// NPCs
    new npc_highmaul_rune_of_displacement();
    new npc_highmaul_arcane_aberration();
    new npc_highmaul_destructive_resonance();
    new npc_highmaul_destructive_resonance_replication();
    new npc_highmaul_gorian_warmage();
    new npc_highmaul_volatile_anomaly();
    new npc_highmaul_gorian_reaver();
    new npc_highmaul_arcane_remnant();
    new npc_highmaul_glimpse_of_madness();
    new npc_highmaul_night_twisted_faithful();

    /// Spells
    new spell_highmaul_mark_of_chaos();
    new spell_highmaul_destructive_resonance();
    new spell_highmaul_branded();
    new spell_highmaul_branded_displacement();
    new spell_highmaul_branded_fortification();
    new spell_highmaul_branded_replication();
    new spell_highmaul_arcane_wrath_damage();
    new spell_highmaul_transition_visuals();
    new spell_highmaul_dominance_aura();
    new spell_highmaul_force_nova_fortified();
    new spell_highmaul_devastating_shockwave();
    new spell_highmaul_force_nova_dot();
    new spell_highmaul_orbs_of_chaos_aura();
    new spell_highmaul_volatile_anomalies();
    new spell_highmaul_glimpse_of_madness();
    new spell_highmaul_gaze_of_the_abyss();
    new spell_highmaul_infinite_darkness();

    /// AreaTrigger
    RegisterAreaTriggerAI(areatrigger_highmaul_orb_of_chaos);
    RegisterAreaTriggerAI(areatrigger_highmaul_growing_shadows);
}
