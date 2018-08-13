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
#include "GameObject.h"
#include "GridNotifiers.h"
#include "shadowmoon_burial_grounds.h"

enum eSadanaSpells
{
    SpellDaggerFallDummy                    = 153240,
    SpellDaggerFallSummon                   = 153200,
    SpellDaggerAlttitudeVisual              = 153225,
    SpellDaggerAura                         = 153236,
    SpellDaggerAuraFunctioning              = 153216,
    SpellDaggerExplosion                    = 153373,
    SpellDaggerFallTriggerMissile           = 153370,
    SpellDaggerFallGroundMarker             = 173073,
    SpellDaggerFallDamage                   = 153224,

    SpellDarkCommunion                      = 153153,
    SpellDarkCommunionBuff                  = 153164,

    SpellDeathSpikeProcTriggerSpell         = 153079,
    SpellDeathSpikeDamage                   = 153089,
    SpellDeathSpikeFull                     = 162696,

    SpellWhispersOfTheDarkStarDamage        = 153093,
    SpellWhisperOfTheDarkStarTriggerSpell   = 153094,

    SpellDarkEclipsePeriodicDummy           = 164685,
    SpellDarkEclipseDamage                  = 164686,
    SpellDarkEclipseAreatrirger             = 164704,
    SpellDarkEclipseDummy                   = 164705,
    SpellDarkEclipseDummy02                 = 164706,
    SpellDarkEclipsePeriodicTrigger         = 164710,
    SpellDarkElcipseUnknownPeriodicDummy    = 164974,
    SpellLunaryPurtiyBuff                   = 162652,
    //SpellLunarPurityAreaTrigger           = 162620,

    SpellLunarPurityAreaTrigger             = 164974,
    SpellLunarPurityDamageModification      = 162652,

    SpellShadowRitual                       = 152158,
    SpellLunarRitual                        = 164693,
    SpellShadowRuneVisual                   = 152684,
    SpellShadowRuneVisual01                 = 152691,
    SpellShadowRuneVisual02                 = 152695,

    SpellLunarRuneVisual                    = 164693,
    SpellLunarRuneVisual01                  = 164695,
    SpellLunarRuneVisual02                  = 164696,

    SpellTenebreuxViolet                    = 152311,

    SpellCosmeticStrangulateState           = 78037
};

enum eSadanaEvents
{
    EventDaggerFall = 1,
    EventDaggerFallMovement,
    EventDaggerFallActivation,
    EventDarkCommunion,
    EventDeathSpike,
    EventWhisperOfTheDarkStar,
    EventDarkEclipse,
    EventDarkEclipseFinish,
    EventLunarPurity,
    EventDefiledSpirtMovement
};

enum eSadanaTalks
{
    TalkAggro = 1, ///< Anscestors of the Shadowmoon.. shine in the darkness! Lend me your strength! [43539]
    TalkDeath,     ///< The dead shall rise again.. [43540]
    TalkIntro,     ///< Rivers of the damned.. rise! RISE in the name of Darkness... RISE in the name of NERZ'UL!.. the Shadowmoon beckons [43541]
    TalkKill01,    ///< Another spirit for the army! [43542]
    TalkKill02,    ///< Embrace the eternal darkness! [43543]
    TalkSpell01,   ///< For Nerz'ul! [43544]
    TalkSpell02,   ///< Mmm.. mmm.. YES! the perfect Sacrifice! [43545]
    TalkSpell03,   ///< Your souls will belong to me! [43546]
    TalkSpell04,   ///< Restless spirits.. heed my command! [43547]
};

enum eSadanaActions
{
    ActionActivateDefiledSpirit = 1, 
    ActionMoveDefiledSpirits,
    ActionActivateLunarTriggersActivate, 
    ActionActivateLunarTriggersDeactivate
};

enum eSadanaCreatures
{
    CreatureDaggerFall                   = 75981,
    CreatureEclipseTrigger               = 76052,
    CreatureDefiledSpiritSadanaEncounter = 75966,
    CreatureShadowRune                   = 75778
};
   
enum eSadanaMovements
{
    MovementDaggerFallReachedAlttitude = 1
};

#define DaggerFallAltitude 268.028f
#define DaggerGroundAltitude 261.308f
#define HostileFaction 16
#define FriendlyFaction 35

Position const g_PositionCircles[8] = 
{
    {1805.502f, -16.298f, 261.308f, 4.011894f},
    {1809.695f, -26.531f, 261.308f, 3.086692f},
    {1805.346f, -37.156f, 261.308f, 2.155996f},
    {1795.560f, -40.853f, 261.308f, 1.508042f},
    {1785.818f, -37.061f, 261.308f, 0.640176f},
    {1781.712f, -26.524f, 261.308f, 6.263623f},
    {1786.218f, -16.460f, 261.308f, 5.482167f},
    {1795.574f, -12.252f, 261.308f, 4.767466f}
};

Position const g_PositionDefiledSpiritsMovement[8] =
{
    {1817.100f, -26.563f, 276.406f, 4.329479f},
    {1817.556f, -49.306f, 300.783f, 2.829369f},
    {1794.627f, -57.390f, 289.405f, 2.762329f},
    {1773.798f, -52.632f, 278.439f, 1.855194f},
    {1787.415f, -34.515f, 289.940f, 0.099829f},
    {1819.107f, -6.276f, 273.476f,  4.141892f},
    {1789.199f, -9.896f, 270.591f,  3.336035f},
    {1797.886f, -20.040f, 281.501f, 5.166008f}
};

static void DespawnCreaturesInArea(uint32 p_Entry, WorldObject* p_Object)
{
    std::list<Creature*> creaturesList;
    GetCreatureListWithEntryInGrid(creaturesList, p_Object, p_Entry, 2000.0f);

    if (creaturesList.empty())
        return;

    for (std::list<Creature*>::iterator iter = creaturesList.begin(); iter != creaturesList.end(); ++iter)
        (*iter)->DespawnOrUnsummon();
}

uint32 l_LunarRuneEntries[3] = { eSadanaSpells::SpellLunarRuneVisual, eSadanaSpells::SpellLunarRuneVisual01, eSadanaSpells::SpellLunarRuneVisual02 };
uint32 l_ShadowRuneEntries[3] = { eSadanaSpells::SpellShadowRuneVisual, eSadanaSpells::SpellShadowRuneVisual01, eSadanaSpells::SpellShadowRuneVisual02 };

/// Sadana Bloodyfury - 75509 [Boss]
class boss_sadana_bloodfury : public CreatureScript
{
public:

    boss_sadana_bloodfury() : CreatureScript("boss_sadana_bloodfury") { }

    struct boss_sadana_bloodfuryAI : public BossAI
    {
        boss_sadana_bloodfuryAI(Creature* creature) : BossAI(creature, eShadowmoonBurialGroundsDatas::DataBossSadana)
        {
            m_Instance = me->GetInstanceScript();

            HandleDoorCombatActivation();
            SummonPathsDefiledSpirits();

            me->GetScheduler().Schedule(40s, [this](TaskContext /*context*/)
            {
                Talk(eSadanaTalks::TalkIntro);
            });
        }

        InstanceScript* m_Instance;
        ObjectGuid m_CommunionGuid;
        bool m_CommunionInRange;
        bool m_CommunionInAction;

        void Reset() override
        {
            _Reset();
            events.Reset();

            m_CommunionInRange = false;
            m_CommunionInAction = false;
            m_CommunionGuid = ObjectGuid::Empty;

            /// Activate shadow runes;
            std::list<Creature*> l_ListShadowrunes;
            me->GetCreatureListWithEntryInGrid(l_ListShadowrunes, eSadanaCreatures::CreatureShadowRune, 200.0f);

            if (!l_ListShadowrunes.empty())
            {
                for (auto itr : l_ListShadowrunes)
                {
                    if (itr->IsAIEnabled)
                        itr->GetAI()->Reset();
                }
            }

            /// Delete all ground markers nearby.
            std::list<AreaTrigger*> l_listAreaTriggers;
            me->GetAreatriggerListInRange(l_listAreaTriggers, 300.0f);

            if (!l_listAreaTriggers.empty())
            {
                for (auto itr : l_listAreaTriggers)
                {
                    if (itr->GetSpellId() != eSadanaSpells::SpellDaggerFallGroundMarker)
                        continue;

                    itr->SetDuration(500);
                }
            }

            me->CastSpell(me, eSadanaSpells::SpellShadowRitual);

            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_IMMUNE_TO_PC 
                | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
        }

        void JustReachedHome() override
        {
            _JustReachedHome();
            summons.DespawnAll();

            DespawnCreaturesInArea(eSadanaCreatures::CreatureDefiledSpiritSadanaEncounter, me);
            DespawnCreaturesInArea(eSadanaCreatures::CreatureDaggerFall, me);
            DespawnCreaturesInArea(eSadanaCreatures::CreatureShadowRune, me);
            DespawnCreaturesInArea(eSadanaCreatures::CreatureEclipseTrigger, me);

            if (m_Instance != nullptr)
            {
                m_Instance->SetBossState(eShadowmoonBurialGroundsDatas::DataBossSadana, EncounterState::FAIL);
            }

            HandleDoorCombatActivation();
        }

        void JustSummoned(Creature* summon) override
        {
            if (summon)
            {
                switch (summon->GetEntry())
                {
                    case eSadanaCreatures::CreatureShadowRune:
                        summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                        summon->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN);
                        break;
                    case eSadanaCreatures::CreatureEclipseTrigger:
                        summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                        summon->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN);
                        break;             
                }
            }
        }

        void HandleDoorCombatActivation()
        {
            if (m_Instance != nullptr)
            {
                if (GameObject* l_SadanaDoor = m_Instance->instance->GetGameObject(m_Instance->GetGuidData(eShadowmoonBurialGroundsDatas::DataSadanaFightDoor)))
                {
                    // Activate
                    l_SadanaDoor->SetLootState(GO_READY);
                    l_SadanaDoor->UseDoorOrButton(10 * TimeConstants::IN_MILLISECONDS, false, me);
                }
            }
        }

        void HandleDoorEncounterFinishActivation()
        {
            if (m_Instance != nullptr)
            {
                if (GameObject* l_SadanaFightDoor = m_Instance->instance->GetGameObject(m_Instance->GetGuidData(eShadowmoonBurialGroundsDatas::DataStoneDoorSadana)))
                {
                    // Activate
                    l_SadanaFightDoor->SetLootState(GO_READY);
                    l_SadanaFightDoor->UseDoorOrButton(10 * TimeConstants::IN_MILLISECONDS, false, me);
                }
            }
        }

        void SummonPathsDefiledSpirits()
        {
            for (uint8 l_i = 0; l_i <= 30; l_i++)
            {
                Position position = me->GetRandomNearPosition(40.0f);
                position.m_positionZ = frand(261.391f, 284.058f);

                me->SummonCreature(eShadowmoonBurialGroundsCreatures::CreatureDefliedSpirit01, position, TempSummonType::TEMPSUMMON_MANUAL_DESPAWN);
            }
        }

        void SummonEclipseTriggers()
        {
            for (uint8 l_i = 0; l_i <= 7; l_i++)
            {
                me->SummonCreature(eSadanaCreatures::CreatureEclipseTrigger, g_PositionCircles[l_i], TempSummonType::TEMPSUMMON_MANUAL_DESPAWN);
            }
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();

            me->RemoveAura(eSadanaSpells::SpellShadowRitual);

            SummonEclipseTriggers();

            Talk(eSadanaTalks::TalkAggro);

            if (m_Instance != nullptr)
            {
                m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me);
                m_Instance->SetBossState(eShadowmoonBurialGroundsDatas::DataBossSadana, EncounterState::IN_PROGRESS);

                DoZoneInCombat();
            }

            HandleDoorCombatActivation();

            events.ScheduleEvent(eSadanaEvents::EventDeathSpike, 8 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eSadanaEvents::EventDaggerFall, 12 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eSadanaEvents::EventWhisperOfTheDarkStar, 20 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eSadanaEvents::EventDarkCommunion, 37 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eSadanaEvents::EventDarkEclipse, 60 * TimeConstants::IN_MILLISECONDS);
        }

        void KilledUnit(Unit* who) override
        {
            if (who->GetTypeId() == TypeID::TYPEID_PLAYER)
            {
                if (roll_chance_i(50))
                    Talk(eSadanaTalks::TalkKill01);
                else
                    Talk(eSadanaTalks::TalkKill02);
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();

            Talk(eSadanaTalks::TalkDeath);
            summons.DespawnAll();

            HandleDoorCombatActivation();
            HandleDoorEncounterFinishActivation();

            DespawnCreaturesInArea(eSadanaCreatures::CreatureDaggerFall, me);
            DespawnCreaturesInArea(eSadanaCreatures::CreatureDefiledSpiritSadanaEncounter, me);

            if (m_Instance != nullptr)
            {
                m_Instance->SetBossState(eShadowmoonBurialGroundsDatas::DataBossSadana, EncounterState::DONE);
            }

            if (Creature* l_WorldTrigger = me->FindNearestCreature(eShadowmoonBurialGroundsCreatures::CreatureWorldTriggerSadanaRp, 200.0f, true))
            {
                if (Creature* l_WeepingSoul = me->SummonCreature(eShadowmoonBurialGroundsCreatures::CreatureWeepingSpirit, l_WorldTrigger->GetPositionX(), l_WorldTrigger->GetPositionY(), l_WorldTrigger->GetPositionZ(), l_WorldTrigger->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 15 * TimeConstants::IN_MILLISECONDS))
                {
                    if (l_WeepingSoul->IsAIEnabled)
                        l_WeepingSoul->AI()->Talk(eShadowmoonBurialGroundsTalks::TalkUnknown01);
                }
            }
        }

        void UpdateAI(uint32 const diff) override
        {     
            if (!UpdateVictim())
                return;

            events.Update(diff);

            /// Dark Communion - (needs to be above then unit_state_casting so it can still work with the cast itself)
            if (!m_CommunionGuid.IsEmpty() && m_CommunionInRange)
            {
                if (Creature* creature = ObjectAccessor::GetCreature(*me, m_CommunionGuid))
                {
                    creature->UpdatePosition(creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), true);
           
                    if (me->IsWithinDistInMap(creature, 4.0f))
                    {           
                        m_CommunionInRange = false;

                        creature->DespawnOrUnsummon();
                        me->CastSpell(me, eSadanaSpells::SpellDarkCommunionBuff, false);
                    }
                }
            }

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;

            if (m_CommunionInAction) /// During communion phase other spells should be disabled.
                return;

            switch (events.ExecuteEvent())
            {
                case eSadanaEvents::EventDaggerFall:
                {             
                    /// Delete all ground markers nearby.
                    std::list<AreaTrigger*> l_listAreaTriggers;
                    me->GetAreatriggerListInRange(l_listAreaTriggers, 300.0f);

                    if (!l_listAreaTriggers.empty())
                    {
                        for (auto itr : l_listAreaTriggers)
                        {
                            if (itr->GetSpellId() != eSadanaSpells::SpellDaggerFallGroundMarker)
                                continue;

                            itr->SetDuration(500);
                        }
                    }
              
                    for (uint8 l_I = 0; l_I < 2; l_I++)
                    {
                        if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 100.0f, true, -eSadanaSpells::SpellDaggerFallGroundMarker))
                        {
                            me->SummonCreature(eSadanaCreatures::CreatureDaggerFall, target->GetPositionX(), target->GetPositionY(), DaggerFallAltitude, target->GetOrientation(), TempSummonType::TEMPSUMMON_MANUAL_DESPAWN);
                            target->CastSpell(target, eSadanaSpells::SpellDaggerFallGroundMarker);     
                        }
                    }

                    events.ScheduleEvent(eSadanaEvents::EventDaggerFall, 20 * TimeConstants::IN_MILLISECONDS);
                    break;
                }
                case eSadanaEvents::EventWhisperOfTheDarkStar:
                    me->CastSpell(me, eSadanaSpells::SpellWhisperOfTheDarkStarTriggerSpell);

                    events.ScheduleEvent(eSadanaEvents::EventWhisperOfTheDarkStar, 30 * TimeConstants::IN_MILLISECONDS);
                    break;
                case eSadanaEvents::EventDarkCommunion:
                    if (Creature* l_NearestDefiledSpirit = me->FindNearestCreature(eShadowmoonBurialGroundsCreatures::CreatureDefliedSpirit01, 100.0f, true))
                    {
                        m_CommunionGuid = ObjectGuid::Empty;

                        l_NearestDefiledSpirit->AddAura(eSadanaSpells::SpellCosmeticStrangulateState, l_NearestDefiledSpirit);
                        me->CastSpell(l_NearestDefiledSpirit, eSadanaSpells::SpellDarkCommunion);
                        m_CommunionGuid = l_NearestDefiledSpirit->GetGUID();

                        m_CommunionInRange = true;
                        m_CommunionInAction = true;
                    }

                    events.ScheduleEvent(eSadanaEvents::EventDarkCommunion, 45 * TimeConstants::IN_MILLISECONDS);
                    break;
                case eSadanaEvents::EventDeathSpike:
                    me->CastSpell(me, eSadanaSpells::SpellDeathSpikeFull);

                    events.ScheduleEvent(eSadanaEvents::EventDeathSpike, 15 * TimeConstants::IN_MILLISECONDS);
                    break;
                case eSadanaEvents::EventDarkEclipse:
                {
                    me->NearTeleportTo(1795.788f, -26.7637f, 261.3088f, 4.629905f); // To the Middle.
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                    me->SetReactState(ReactStates::REACT_PASSIVE);

                    /// Activate shadow runes;
                    std::list<Creature*> l_ListShadowrunes;
                    me->GetCreatureListWithEntryInGrid(l_ListShadowrunes, eSadanaCreatures::CreatureShadowRune, 200.0f);

                    if (!l_ListShadowrunes.empty())
                    {
                        std::list<Creature*>::const_iterator l_it = l_ListShadowrunes.begin();
                        std::advance(l_it, urand(0, l_ListShadowrunes.size() - 6));

                        if ((*l_it)->IsAIEnabled)
                            (*l_it)->GetAI()->DoAction(eSadanaActions::ActionActivateLunarTriggersActivate);
                    }

                    /// Eclipse triggers = functional: adds the friendly buff upon standing on the rune itself and getting immuned to the eclipse damage within seconds.
                    std::list<Creature*> l_ListTriggersLunars;
                    me->GetCreatureListWithEntryInGrid(l_ListTriggersLunars, eSadanaCreatures::CreatureEclipseTrigger, 200.0f);

                    if (!l_ListTriggersLunars.empty())
                    {
                        for (auto itr : l_ListTriggersLunars)
                        {
                            if (itr->IsAIEnabled)
                                itr->GetAI()->DoAction(eSadanaActions::ActionActivateLunarTriggersActivate);
                        }
                    }

                    DoCast(eSadanaSpells::SpellDarkEclipsePeriodicDummy);
                    events.ScheduleEvent(eSadanaEvents::EventDarkEclipse, 60 * TimeConstants::IN_MILLISECONDS);
                    events.ScheduleEvent(eSadanaEvents::EventDarkEclipseFinish, 17 * TimeConstants::IN_MILLISECONDS);
                    break;
                }
                case eSadanaEvents::EventDarkEclipseFinish:
                {
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_IMMUNE_TO_PC);
                    me->SetReactState(ReactStates::REACT_AGGRESSIVE);

                    // Activate shadow runes - cosmetic;
                    std::list<Creature*> l_ListTriggersRunes;
                    me->GetCreatureListWithEntryInGrid(l_ListTriggersRunes, eSadanaCreatures::CreatureShadowRune, 100.0f);

                    if (!l_ListTriggersRunes.empty())
                    {
                        for (auto itr : l_ListTriggersRunes)
                        {
                            if (itr->IsAIEnabled)
                                itr->GetAI()->DoAction(eSadanaActions::ActionActivateLunarTriggersDeactivate);
                        }
                    }

                    // Eclipse triggers = functional: adds the friendly buff upon standing on the rune itself and getting immuned to the eclipse damage within seconds.
                    std::list<Creature*> l_ListTriggersLunars;
                    me->GetCreatureListWithEntryInGrid(l_ListTriggersLunars, eSadanaCreatures::CreatureEclipseTrigger, 100.0f);

                    if (!l_ListTriggersLunars.empty())
                    {
                        for (auto itr : l_ListTriggersLunars)
                        {
                            if (itr->IsAIEnabled)
                                itr->GetAI()->DoAction(eSadanaActions::ActionActivateLunarTriggersDeactivate);
                        }
                    }
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
        return new boss_sadana_bloodfuryAI(creature);
    }
};

/// Defiled Spirit - 75966 [The spirits that flies around in circles, responsible for dark communion spell]
class shadowmoon_burial_grounds_creature_defiled_spirit : public CreatureScript
{
public:

    shadowmoon_burial_grounds_creature_defiled_spirit() : CreatureScript("shadowmoon_burial_grounds_creature_defiled_spirit") {}

    struct shadowmoon_burial_grounds_creaturesAI : public ScriptedAI
    {
        shadowmoon_burial_grounds_creaturesAI(Creature* creature) : ScriptedAI(creature)
        {
            m_Instance = creature->GetInstanceScript();
        }

        InstanceScript* m_Instance;
        uint8 m_MovementIndentifier;
        bool m_StartEvent;
        bool m_Activation;

        void Reset() override
        {
            events.Reset();

            m_MovementIndentifier = 0;
            m_Activation = false;

            me->SetSpeed(UnitMoveType::MOVE_FLIGHT, frand(0.3f, 1.2f));

            me->setFaction(HostileFaction);
            me->SetReactState(ReactStates::REACT_PASSIVE);
            me->CastSpell(me, eSadanaSpells::SpellTenebreuxViolet);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_IMMUNE_TO_PC);

            me->SetDisableGravity(true);
            me->SetCanFly(true);

            Position position = g_PositionDefiledSpiritsMovement[m_MovementIndentifier];
            position.m_positionX += frand(2.0f, 8.0f);
            position.m_positionY += frand(2.0f, 10.0f);
            position.m_positionZ += frand(2.0f, 8.0f);

            me->GetMotionMaster()->MoveTakeoff(m_MovementIndentifier, position);
        }

        void DoAction(int32 const action) override
        {
            switch (action)
            {
                case eSadanaActions::ActionActivateDefiledSpirit:
                {
                    if (m_Activation)
                        return;

                    events.Reset();

                    m_Activation = true;
                    me->StopMoving();

                    me->SetSpeed(UnitMoveType::MOVE_RUN, 0.2f);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);

                    /// Reset handling - encounter.
                    if (Creature * l_Sadana = m_Instance->instance->GetCreature(m_Instance->GetGuidData(eShadowmoonBurialGroundsDatas::DataBossSadana)))
                    {
                        me->GetMotionMaster()->MoveFollow(l_Sadana, 0, 0, MovementSlot::MOTION_SLOT_ACTIVE);
                    }
                    break;
                }
            }
        }

        void MovementInform(uint32 /*type*/, uint32 id) override
        {
            if (id == m_MovementIndentifier && me->IsInWorld())
            {
                /// Movement handler.
                m_MovementIndentifier++;

                if (m_MovementIndentifier >= 8)
                    m_MovementIndentifier = 0;

                Position position = g_PositionDefiledSpiritsMovement[m_MovementIndentifier];
                position.m_positionX += frand(2.0f, 8.0f);
                position.m_positionY += frand(2.0f, 10.0f);
                position.m_positionZ += frand(2.0f, 8.0f);
                me->GetMotionMaster()->MoveTakeoff(m_MovementIndentifier, position);
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (m_Instance != nullptr)
            {
                /// Reset handling - encounter.
                if (Creature * l_Sadana = m_Instance->instance->GetCreature(m_Instance->GetGuidData(eShadowmoonBurialGroundsDatas::DataBossSadana)))
                {
                    if (l_Sadana->IsAIEnabled)
                    {
                        if (boss_sadana_bloodfury::boss_sadana_bloodfuryAI* l_LinkAI = CAST_AI(boss_sadana_bloodfury::boss_sadana_bloodfuryAI, l_Sadana->GetAI()))
                        {
                            l_LinkAI->m_CommunionGuid = ObjectGuid::Empty;
                            l_LinkAI->m_CommunionInRange = false;

                            me->DespawnOrUnsummon(500);
                            l_Sadana->SetReactState(ReactStates::REACT_AGGRESSIVE);
                            l_Sadana->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                            l_Sadana->CastStop();
                        }
                    }
                }
            }
        }

        void UpdateAI(uint32 const diff) override
        {
            if (m_Activation) // Creature is activated;
                return;

            events.Update(diff);

            switch (events.ExecuteEvent())
            {
                case eSadanaEvents::EventDefiledSpirtMovement + 1:
                    me->GetMotionMaster()->MoveTargetedHome();
                    break;
                default:
                    break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new shadowmoon_burial_grounds_creaturesAI(creature);
    }
};

/// Falling Dagger - 75981 [Falling dagger]
class shadowmoon_burial_grounds_creature_falling_dagger : public CreatureScript
{
public:

    shadowmoon_burial_grounds_creature_falling_dagger() : CreatureScript("shadowmoon_burial_grounds_creature_falling_dagger") {}

    struct shadowmoon_burial_grounds_creaturesAI : public ScriptedAI
    {
        shadowmoon_burial_grounds_creaturesAI(Creature* creature) : ScriptedAI(creature)
        {
            m_Instance = creature->GetInstanceScript();
            m_CanDamage = false;
        }

        EventMap m_Events;
        InstanceScript* m_Instance;
        bool m_StartEvent;
        bool m_CanDamage;

        void Reset() override
        {
            events.Reset();

            me->setFaction(HostileFaction);
            me->SetReactState(ReactStates::REACT_PASSIVE);          
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_IMMUNE_TO_PC);
            me->SetFlag(UNIT_FIELD_LEVEL, UNIT_FLAG2_DISABLE_TURN);
            me->CastSpell(me, eSadanaSpells::SpellDaggerAuraFunctioning);

            me->SetDisableGravity(true);
            me->SetCanFly(true);

            events.ScheduleEvent(eSadanaEvents::EventDaggerFallMovement, 4 * TimeConstants::IN_MILLISECONDS);
        }

        void MovementInform(uint32 /*type*/, uint32 id) override
        {
            switch (id)
            {
                case eSadanaMovements::MovementDaggerFallReachedAlttitude: /// Damage starts ticking once dagger is in player's alttitude.
                    events.ScheduleEvent(eSadanaEvents::EventDaggerFallActivation, 1 * TimeConstants::IN_MILLISECONDS);
                    break;
            }
        }

        void UpdateAI(uint32 const diff) override
        {
            events.Update(diff);

            switch (events.ExecuteEvent())
            {
                case eSadanaEvents::EventDaggerFallActivation:               
                    m_CanDamage = true;

                    me->CastSpell(me, eSadanaSpells::SpellDaggerAlttitudeVisual); /// The visual when the daggerfall reaches the ground

                    events.ScheduleEvent(eSadanaEvents::EventDaggerFall, 1 * TimeConstants::IN_MILLISECONDS); /// Activates hardcoded damage intervals
                    break;
                case eSadanaEvents::EventDaggerFallMovement:
                {
                    me->SetSpeed(UnitMoveType::MOVE_RUN, 2.0f);
                    Position takeOffPosition = me->GetPosition();
                    takeOffPosition.m_positionZ = DaggerGroundAltitude;
                    me->GetMotionMaster()->MoveTakeoff(eSadanaMovements::MovementDaggerFallReachedAlttitude, takeOffPosition);
                    break;
                }
                case eSadanaEvents::EventDaggerFall: /// Responsible for damage ticking, disabling the automatic damage from spelldbc
                    DoCastAOE(eSadanaSpells::SpellDaggerFallDamage);

                    events.ScheduleEvent(eSadanaEvents::EventDaggerFall, 1 * TimeConstants::IN_MILLISECONDS);
                    break;
                default:
                    break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new shadowmoon_burial_grounds_creaturesAI(creature);
    }
};

/// Shadow Rune - 75778 [Responsible for the cosmetic shadow runes changing to lunars when eclipse starts]
class shadowmoon_burial_grounds_creature_shadow_rune : public CreatureScript
{
public:

    shadowmoon_burial_grounds_creature_shadow_rune() : CreatureScript("shadowmoon_burial_grounds_creature_shadow_rune") {}

    struct shadowmoon_burial_grounds_creaturesAI : public Scripted_NoMovementAI
    {
        shadowmoon_burial_grounds_creaturesAI(Creature* creature) : Scripted_NoMovementAI(creature)
        {
            m_Instance = creature->GetInstanceScript();
            m_HasBeenActivated = false;
        }

        EventMap m_Events;
        InstanceScript* m_Instance;
        bool m_HasBeenActivated;

        void Reset() override
        {
            events.Reset();

            me->RemoveAllAuras();

            switch (urand(0, 2))
            {
                case 0:
                    me->CastSpell(me, eSadanaSpells::SpellShadowRuneVisual);
                    break;
                case 1:
                    me->CastSpell(me, eSadanaSpells::SpellShadowRuneVisual01);
                    break;
                case 2:
                    me->CastSpell(me, eSadanaSpells::SpellShadowRuneVisual02);
                    break;
            }

            me->setFaction(FriendlyFaction);
            me->SetReactState(ReactStates::REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
            me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN);
        }

        void DoAction(int32 const action) override
        {
            switch (action)
            {
                case eSadanaActions::ActionActivateLunarTriggersActivate:
                {
                    switch (urand(0, 2))
                    {
                        case 0:
                            me->CastSpell(me, eSadanaSpells::SpellLunarRuneVisual);
                            break;
                        case 1:
                            me->CastSpell(me, eSadanaSpells::SpellLunarRuneVisual01);
                            break;
                        case 2:
                            me->CastSpell(me, eSadanaSpells::SpellLunarRuneVisual02);
                            break;
                    }

                    for (uint32 l_I = 0; l_I < 4; l_I++)
                        me->RemoveAura(l_ShadowRuneEntries[l_I]);

                    m_HasBeenActivated = true;

                    me->CastSpell(me, eSadanaSpells::SpellLunarPurityAreaTrigger);
                    break;
                }
                case eSadanaActions::ActionActivateLunarTriggersDeactivate:
                {
                    if (!m_HasBeenActivated)
                        return;

                    switch (urand(0, 2))
                    {
                        case 0:
                            me->CastSpell(me, eSadanaSpells::SpellShadowRuneVisual);
                            break;
                        case 1:
                            me->CastSpell(me, eSadanaSpells::SpellShadowRuneVisual01);
                            break;
                        case 2:
                            me->CastSpell(me, eSadanaSpells::SpellShadowRuneVisual02);
                            break;
                    }

                    for (uint32 l_I = 0; l_I < 4; l_I++)
                        me->RemoveAura(l_LunarRuneEntries[l_I]);

                    me->RemoveAura(eSadanaSpells::SpellLunarRitual);
                    m_HasBeenActivated = false;
                    break;
                }
                default:
                    break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new shadowmoon_burial_grounds_creaturesAI(creature);
    }
};

/// Eclipse Trigger - 76052 [Responsible for the eclipse trigger, searching targets when activated to grant them a buff
class shadowmoon_burial_grounds_creature_eclipse_trigger : public CreatureScript
{
public:

    shadowmoon_burial_grounds_creature_eclipse_trigger() : CreatureScript("shadowmoon_burial_grounds_creature_eclipse_trigger") {}

    struct shadowmoon_burial_grounds_creaturesAI : public Scripted_NoMovementAI
    {
        shadowmoon_burial_grounds_creaturesAI(Creature* creature) : Scripted_NoMovementAI(creature)
        {
            m_Instance = creature->GetInstanceScript();
        }

        InstanceScript* m_Instance;
        bool m_ReadyForAction;
        uint32 m_ActionDiff;

        void Reset() override
        {
            events.Reset();
            m_ReadyForAction = false;
            m_ActionDiff = 2 * TimeConstants::IN_MILLISECONDS;

            me->setFaction(FriendlyFaction);
            me->SetReactState(ReactStates::REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
            me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN);
        }

        void DoAction(int32 const action) override
        {
            switch (action)
            {
                case eSadanaActions::ActionActivateLunarTriggersActivate:
                    m_ReadyForAction = true;
                    break;
                case eSadanaActions::ActionActivateLunarTriggersDeactivate:
                    m_ReadyForAction = false;
                    break;
            }
        }

        void UpdateAI(uint32 const diff) override
        {
            events.Update(diff);

            // Lunar Purity
            if (m_ReadyForAction)
            {
                if (m_ActionDiff <= diff)
                {
                    std::list<Player*> playerList;
                    me->GetPlayerListInGrid(playerList, 1.2f);

                    if (playerList.empty())
                        return;

                    for (auto itr : playerList)
                    {
                        itr->CastSpell(itr, eSadanaSpells::SpellLunarPurityDamageModification); 
                    }

                    m_ActionDiff = 2 * TimeConstants::IN_MILLISECONDS;
                }
                else
                    m_ActionDiff -= diff;
            }
        }

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new shadowmoon_burial_grounds_creaturesAI(creature);
    }
};

/// Shadow Burn - 153224 [Ticking damage spell from daggerfall proc]
class spell_shadowmoon_burial_grounds_shadow_burn : public SpellScriptLoader 
{
public:

    spell_shadowmoon_burial_grounds_shadow_burn() : SpellScriptLoader("spell_shadowmoon_burial_grounds_shadow_burn") { }

    class spell_shadowmoon_burial_grounds_shadow_burn_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_shadowmoon_burial_grounds_shadow_burn_SpellScript);

        SpellCastResult CheckCaster()
        {
            if (!GetCaster())
                return SpellCastResult::SPELL_FAILED_DONT_REPORT;
       
            if (GetCaster()->GetPositionZ() > 262.0f)
                return SpellCastResult::SPELL_FAILED_DONT_REPORT;
            else
                return SpellCastResult::SPELL_CAST_OK;        
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_shadowmoon_burial_grounds_shadow_burn_SpellScript::CheckCaster);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_shadowmoon_burial_grounds_shadow_burn_SpellScript;
    }
};

/// Dark Communion - 153153  [ Responisble for making the ghost stop moving, and start following the boss ]
class spell_shadowmoon_burial_grounds_dark_communion : public SpellScriptLoader
{
public:

    spell_shadowmoon_burial_grounds_dark_communion() : SpellScriptLoader("spell_shadowmoon_burial_grounds_dark_communion") { }

    class spell_shadowmoon_burial_grounds_dark_communion_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_shadowmoon_burial_grounds_dark_communion_AuraScript);

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (!GetTarget())
                return;

            if (!GetCaster())
                return;

            if (GetTarget()->IsAIEnabled)
            {
                GetTarget()->GetAI()->DoAction(eSadanaActions::ActionActivateDefiledSpirit);
            }
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (Unit* target = GetTarget())
                {
                    if (target->GetTypeId() == TypeID::TYPEID_PLAYER)
                        return;

                    target->ToCreature()->DespawnOrUnsummon();

                    if (InstanceScript* l_Instance = caster->GetInstanceScript())
                    {
                        if (Creature* l_Sadana = l_Instance->instance->GetCreature(l_Instance->GetGuidData(eShadowmoonBurialGroundsDatas::DataBossSadana)))
                        {
                            if (l_Sadana->IsAIEnabled)
                            {
                                if (boss_sadana_bloodfury::boss_sadana_bloodfuryAI* linkAI = CAST_AI(boss_sadana_bloodfury::boss_sadana_bloodfuryAI, l_Sadana->GetAI()))
                                {
                                    if (linkAI && linkAI->m_CommunionInAction)
                                    {
                                        linkAI->m_CommunionInAction = false;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        void Register() override
        {
            AfterEffectApply += AuraEffectApplyFn(spell_shadowmoon_burial_grounds_dark_communion_AuraScript::OnApply, SpellEffIndex::EFFECT_0, AuraType::SPELL_AURA_DUMMY, AuraEffectHandleModes::AURA_EFFECT_HANDLE_REAL);
            AfterEffectRemove += AuraEffectRemoveFn(spell_shadowmoon_burial_grounds_dark_communion_AuraScript::OnRemove, SpellEffIndex::EFFECT_0, AuraType::SPELL_AURA_DUMMY, AuraEffectHandleModes::AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_shadowmoon_burial_grounds_dark_communion_AuraScript();
    }
};

/// Dark Eclipse - 164685  [Handles the trigger deactivation, and somethign with the damage]
class spell_shadowmoon_burial_grounds_dark_eclipse : public SpellScriptLoader
{
public:

    spell_shadowmoon_burial_grounds_dark_eclipse() : SpellScriptLoader("spell_shadowmoon_burial_grounds_dark_eclipse") { }

    class spell_shadowmoon_burial_grounds_dark_eclipse_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_shadowmoon_burial_grounds_dark_eclipse_AuraScript);

        bool Load() override
        {
            if (!GetSpellInfo())
                return false;

            /*SpellInfo* l_Spell = const_cast<SpellInfo*>(GetSpellInfo());
            l_Spell->GetEffect(0)->Amplitude = 4 * TimeConstants::IN_MILLISECONDS;*/
            return true;
        }

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (!GetCaster())
                return;

            GetCaster()->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
        }

        void HandlePeriodic(AuraEffect const* /*aurEff*/)
        {
            PreventDefaultAction();

            if (GetCaster())
            {
                if (!GetSpellInfo())
                    return;

                /*SpellInfo* l_Spell = const_cast<SpellInfo*>(GetSpellInfo());
                l_Spell->GetEffect(0)->Amplitude = 600;*/

                GetCaster()->CastSpell(GetCaster(), eSadanaSpells::SpellDarkEclipseDamage);
            }
        }

        void Register() override
        {
            AfterEffectApply += AuraEffectApplyFn(spell_shadowmoon_burial_grounds_dark_eclipse_AuraScript::OnApply,           SpellEffIndex::EFFECT_0, AuraType::SPELL_AURA_PERIODIC_DUMMY, AuraEffectHandleModes::AURA_EFFECT_HANDLE_REAL);       
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_shadowmoon_burial_grounds_dark_eclipse_AuraScript::HandlePeriodic, SpellEffIndex::EFFECT_0, AuraType::SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_shadowmoon_burial_grounds_dark_eclipse_AuraScript();
    }

    class spell_shadowmoon_burial_grounds_dark_eclipse_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_shadowmoon_burial_grounds_dark_eclipse_SpellScript);

        void CorrectTargets(std::list<WorldObject*>& targets)
        {
            if (targets.empty())
                return;

            targets.remove_if(Trinity::ObjectTypeIdCheck(TYPEID_PLAYER, false));
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_shadowmoon_burial_grounds_dark_eclipse_SpellScript::CorrectTargets, SpellEffIndex::EFFECT_0, Targets::TARGET_UNIT_NEARBY_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_shadowmoon_burial_grounds_dark_eclipse_SpellScript();
    }
};

/// Dark Eclipse damage - 164686 [Makes every damage coming from eclipse set to 0 if you have the eclipse immunity from standing in the lunars]
class spell_shadowmoon_burial_grounds_dark_eclipse_damage : public SpellScriptLoader
{
public:

    spell_shadowmoon_burial_grounds_dark_eclipse_damage() : SpellScriptLoader("spell_shadowmoon_burial_grounds_dark_eclipse_damage") { }

    class spell_shadowmoon_burial_grounds_dark_eclipse_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_shadowmoon_burial_grounds_dark_eclipse_damage_SpellScript);

        void HandleDamage(SpellEffIndex /*effIndex*/)
        {
            if (!GetCaster() || !GetHitUnit())
                return;

            if (GetCaster()->HasAura(eSadanaSpells::SpellLunaryPurtiyBuff))
                SetHitDamage(0);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_shadowmoon_burial_grounds_dark_eclipse_damage_SpellScript::HandleDamage, SpellEffIndex::EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_shadowmoon_burial_grounds_dark_eclipse_damage_SpellScript();
    }
};


void AddSC_sadana()
{
    new boss_sadana_bloodfury();
    new shadowmoon_burial_grounds_creature_defiled_spirit();
    new shadowmoon_burial_grounds_creature_falling_dagger();
    new shadowmoon_burial_grounds_creature_shadow_rune();
    new shadowmoon_burial_grounds_creature_eclipse_trigger();
    new spell_shadowmoon_burial_grounds_dark_communion();
    new spell_shadowmoon_burial_grounds_dark_eclipse();
    new spell_shadowmoon_burial_grounds_dark_eclipse_damage();
    new spell_shadowmoon_burial_grounds_shadow_burn();
}
