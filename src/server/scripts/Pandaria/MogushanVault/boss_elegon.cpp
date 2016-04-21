/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

// TODO IMPORTANT : 127005 passage de la distance de l'effet 0 à 40.0f

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "mogu_shan_vault.h"

enum eElegonPhase
{
    PHASE_1                         = 1,
    PHASE_2                         = 2,
    PHASE_3                         = 3,
    PHASE_FINAL                     = 4
};

enum eSpells
{
    // Elegon
    SPELL_APPARITION_VISUAL         = 127808,

    // Platform
    SPELL_TOUCH_OF_THE_TITANS       = 130287,
    SPELL_TOUCH_OF_TITANS_VISUAL    = 117874,
    SPELL_OVERCHARGED               = 117877,

    // Phase 1
    SPELL_VORTEX_VISIBILITY         = 118983, // In Heroic, handle the visibility interference
    SPELL_CELESTIAL_BREATH          = 117960,
    SPELL_MATERIALIZE_PROTECTOR     = 117954,
    SPELL_GRASPING_ENERGY_TENDRILS  = 127362,
    SPELL_GRASPING_ENERGY_GRIP      = 129724,
    SPELL_RADIATING_ENERGIES        = 118310,
    SPELL_RADIATING_ENERGIES_VISUAL = 118992,
    SPELL_RADIATING_OUTSIDE_VORTEX  = 118313,
    SPELL_RADIATING_INSIDE_VORTEX   = 122741,

    // Phase 2
    SPELL_FOCUS_POWER               = 119358,
    SPELL_DRAW_POWER_SHORT          = 119360,
    SPELL_DRAW_POWER_LONG           = 124967,
    SPELL_DRAW_POWER_SUMMONS        = 118018,
    SPELL_DRAW_POWER_DEBUFF         = 119387,

    // Phase 3
    SPELL_UNSTABLE_ENERGY           = 116994,
    SPELL_UNSTABLE_ENERGY_DAMAGE    = 116997,
    SPELL_PHASE_SHIFTED             = 118921,
    SPELL_OVERLOADED_MISSILE        = 116989,
    SPELL_OVERLOADED                = 117204,
    SPELL_ENERGY_CASCADE            = 122199,

    // Empyreal Focus
    SPELL_FOCUS_INACTIVE            = 127303,
    SPELL_FOCUS_ACTIVE              = 127305,
    SPELL_FOCUS_ACTIVATION_VISUAL   = 118794,
    SPELL_FOCUS_ACTIVATE_STATE      = 127305,
    SPELL_FOCUS_LIGHT_AREATRIGGER   = 116546,
    SPELL_FOCUS_LIGHT_CASTBAR       = 116598,
    SPELL_FOCUS_LIGHT_WALL_VISUAL   = 116604,

    // Celestial Protector
    SPELL_TOTAL_ANNIHILATION        = 129711,
    SPELL_TOTAL_ANNIHILATION_DAMAGE = 117914,
    SPELL_ARCING_ENERGY             = 117945,
    SPELL_STABILITY_FLUX            = 117911,
    SPELL_ECLIPSE_NO_PHASE          = 117885,
    SPELL_ECLIPSE_PHASE             = 117886,
    SPELL_CLOSED_CIRCUIT            = 117949,

    // Cosmic Spark
    SPELL_ICE_TRAP                  = 135382,

    // Energy Charge
    SPELL_CORE_CHECKER              = 118024,
    SPELL_CORE_BEAM                 = 118430,
    SPELL_DISCHARGE                 = 118299,
    SPELL_HIGH_ENERGY               = 118118,

    // Infinite Energy (Intro)
    SPELL_SPAWN_FLASH_1_PERIODIC    = 127785,
    SPELL_SPAWN_FLASH_2_PERIODIC    = 127783,
    SPELL_SPAWN_FLASH_3_PERIODIC    = 127781,

    // Heroic
    SPELL_DESTABILIZING_ENERGIES    = 132222,
    SPELL_DESTABILIZED              = 132226,
    SPELL_CATASTROPHIC_ANOMALY      = 127341
};

enum eEvents
{
    // Elegon
    EVENT_CHECK_UNIT_ON_PLATFORM    = 1,
    EVENT_CHECK_MELEE               = 2,
    EVENT_CELESTIAL_BREATH          = 3,
    EVENT_MATERIALIZE_PROTECTOR     = 4,

    EVENT_FOCUS_POWER               = 5,
    EVENT_DRAW_POWER                = 6,

    // Celestial Protector
    EVENT_ARCING_ENERGY             = 5,
    EVENT_TOUCH_OF_THE_TITANS       = 6,
    EVENT_KILLED                    = 7,

    // Cosmic Spark
    EVENT_ICE_TRAP                  = 8,

    EVENT_ENRAGE_HARD               = 9,
    EVENT_DESPAWN_PLATFORM          = 10,
    EVENT_AFTER_DESPAWN_PLATFORM    = 11,
    EVENT_END_OF_PHASE_3            = 12,
    EVENT_RADIATING_ENERGIES        = 13,
    EVENT_LAUNCH_COSMIC_SPARK       = 14,
};

enum elegonActions
{
    ACTION_RESET_DRAWING_POWER      = 1,
    ACTION_SPAWN_ENERGY_CHARGES     = 2,
    ACTION_DESPAWN_ENERGY_CHARGES   = 3,
    ACTION_EMPYREAL_FOCUS_KILLED    = 4,
};

enum eMovementPoints
{
    POINT_EMPYEREAN_FOCUS   = 1,
};

enum eElegonGameObjects
{
    GAMEOBJECT_CACHE_OF_PURE_ENERGY = 214383
};

enum empyrealFocusActions
{
    ACTION_ACTIVATE_EMPYREAL_FOCUS  = 1,
    ACTION_RESET_EMPYREAL_FOCUS     = 2,
};

enum empyrealFocusEvents
{
    EVENT_ACTIVATE_EMPYREAL_FOCUS   = 1,
    EVENT_APPEAR_WALL_OF_LIGHTNING  = 2,
};

enum eTalk
{
    TALK_INTRO          = 0,
    TALK_INTRO_2        = 1,
    TALK_AGGRO          = 2,
    TALK_DEATH          = 3,
    TALK_A_TO_B_1       = 4,
    TALK_A_TO_B_2       = 5,
    TALK_B_TO_C_1       = 6,
    TALK_C_TO_A_1       = 7,
    TALK_C_TO_A_2       = 8,
    TALK_C_TO_A_3       = 9,
    TALK_ENRAGE_HARD    = 10,
    TALK_ENRAGE_SOFT    = 11,
    TALK_SLAY           = 12,
};

// Set values in reset of mob_empyreal_focus
uint64 empyrealFocus[6] =
{
    0, // South-West
    0, // North-West
    0, // South
    0, // North
    0, // South-East
    0  // North-East
};

Position middlePos         = { 4023.15f, 1907.60f, 358.872f, 0.0f };
Position infiniteEnergyPos = { 4023.45f, 1907.60f, 365.0f, 0.0f };

Position energyChargePos[6] =
{
    { 4029.58f, 1914.03f, 360.83f, 0.788954f }, // North-West
    { 4032.21f, 1907.66f, 360.83f, 0.002521f }, // North
    { 4029.58f, 1901.30f, 360.83f, 5.497790f }, // North-East
    { 4016.85f, 1901.30f, 360.83f, 3.923430f }, // South-East
    { 4014.21f, 1907.66f, 360.83f, 3.139080f }, // South
    { 4016.85f, 1914.03f, 360.83f, 2.356190f }  // South-West
};

Position empyrealFocusPosition[6] =
{
    { 4054.24f, 1938.86f, 358.872f, 0.785398f }, // North-West
    { 4067.13f, 1907.75f, 358.872f, 0.000000f }, // North
    { 4054.24f, 1876.64f, 358.872f, 5.49779f },  // North-East
    { 3992.02f, 1876.64f, 358.872f, 3.92699f },  // South-East
    { 3979.13f, 1907.75f, 358.872f, 3.14159f },  // South
    { 3992.02f, 1938.86f, 358.872f, 2.35619f }   // South-West
};

static const Position _summonCacheOfPureEnergyPosition = { 4023.117f, 1857.279f, 359.788f, 1.578647f };

// Elegon - 60410
class boss_elegon : public CreatureScript
{
    public:
        boss_elegon() : CreatureScript("boss_elegon") {}

        struct boss_elegonAI : public BossAI
        {
            boss_elegonAI(Creature* creature) : BossAI(creature, DATA_ELEGON)
            {
                pInstance = creature->GetInstanceScript();
                creature->SetDisplayId(11686);
                creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_IMMUNE_TO_PC|UNIT_FLAG_UNK_15);
            }

            InstanceScript* pInstance;

            uint8 phase;
            uint8 phase2WaveCount;
            float nextPhase1EndingHealthPct;
            uint8 successfulDrawingPower;
            uint8 energyChargeCounter;
            uint8 empyrealFocusKilled;

            void Reset()
            {
                _Reset();

                me->AddAura(SPELL_APPARITION_VISUAL, me);

                me->RemoveAurasDueToSpell(SPELL_UNSTABLE_ENERGY);
                me->RemoveAurasDueToSpell(SPELL_PHASE_SHIFTED);
                me->RemoveAurasDueToSpell(SPELL_OVERLOADED);
                me->RemoveAurasDueToSpell(SPELL_RADIATING_ENERGIES_VISUAL);

                phase                     = PHASE_1;
                phase2WaveCount           = 0;
                nextPhase1EndingHealthPct = 85.0f;
                successfulDrawingPower    = 0;
                energyChargeCounter       = 0;
                empyrealFocusKilled       = 0;

                events.ScheduleEvent(EVENT_CHECK_MELEE,             2500);
                events.ScheduleEvent(EVENT_CELESTIAL_BREATH,        10000);
                events.ScheduleEvent(EVENT_MATERIALIZE_PROTECTOR,   urand(35000, 40000));
                events.ScheduleEvent(EVENT_ENRAGE_HARD,             570000); // 9min30

                summons.DespawnAll();

                if (pInstance)
                {
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TOUCH_OF_THE_TITANS);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TOUCH_OF_TITANS_VISUAL);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_OVERCHARGED);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_CLOSED_CIRCUIT);
                    pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

                  /*  for (int i = 0; i < 6; i++)
                    {
                        if (Unit* focus = ObjectAccessor::Find((ObjectGuid)empyrealFocus[i]))
                            if (focus->GetAI())
                                focus->GetAI()->DoAction(ACTION_RESET_EMPYREAL_FOCUS);
                    }*/
                }
            }

            void JustReachedHome()
            {
                _JustReachedHome();

                if (pInstance)
                    pInstance->SetBossState(DATA_ELEGON, FAIL);
            }

            void EnterCombat(Unit* attacker)
            {
                if (pInstance)
                {
                    pInstance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                    pInstance->SetBossState(DATA_ELEGON, IN_PROGRESS);
                }

                me->AddAura(SPELL_VORTEX_VISIBILITY, me);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_IMMUNE_TO_PC|UNIT_FLAG_UNK_15);
                me->RemoveAurasDueToSpell(SPELL_APPARITION_VISUAL);

                Talk(TALK_AGGRO);
            }

            void AttackStart(Unit* target)
            {
                if (!target)
                    return;

                if (me->Attack(target, true))
                    DoStartNoMovement(target);
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case ACTION_RESET_DRAWING_POWER:
                    {
                        successfulDrawingPower = 0;
                        break;
                    }
                    case ACTION_SPAWN_ENERGY_CHARGES:
                    {
                        for (int i = 0; i < 6; i++)
                        {
                            if (Creature* energyCharge = me->SummonCreature(NPC_ENERGY_CHARGE, energyChargePos[i], TEMPSUMMON_CORPSE_DESPAWN))
                            {
                                // Increase speed by 20% for each successful draw power
                                for (int j = 0; j < (successfulDrawingPower - 1); j++)
                                    me->AddAura(SPELL_HIGH_ENERGY, energyCharge);

                                switch (i)
                                {
                                    case 0:
                                    {
                                        if (Creature* northWest = pInstance->instance->GetCreature(instance->GetObjectGuid(empyrealFocus[1])))
                                        {
                                            energyCharge->CastSpell(northWest, SPELL_CORE_BEAM, true);
                                            energyCharge->SetTarget(northWest->GetGUID());
                                            energyCharge->GetMotionMaster()->MovePoint(POINT_EMPYEREAN_FOCUS, empyrealFocusPosition[i]);
                                        }

                                        break;
                                    }
                                    case 1:
                                    {
                                        if (Creature* north = pInstance->instance->GetCreature(instance->GetObjectGuid(empyrealFocus[3])))
                                        {
                                            energyCharge->CastSpell(north, SPELL_CORE_BEAM, true);
                                            energyCharge->SetTarget(north->GetGUID());
                                            energyCharge->GetMotionMaster()->MovePoint(POINT_EMPYEREAN_FOCUS, empyrealFocusPosition[i]);
                                        }

                                        break;
                                    }
                                    case 2:
                                    {
                                        if (Creature* northEast = pInstance->instance->GetCreature(instance->GetObjectGuid(empyrealFocus[5])))
                                        {
                                            energyCharge->CastSpell(northEast, SPELL_CORE_BEAM, true);
                                            energyCharge->SetTarget(northEast->GetGUID());
                                            energyCharge->GetMotionMaster()->MovePoint(POINT_EMPYEREAN_FOCUS, empyrealFocusPosition[i]);
                                        }

                                        break;
                                    }
                                    case 3:
                                    {
                                        if (Creature* southEast = pInstance->instance->GetCreature(instance->GetObjectGuid(empyrealFocus[4])))
                                        {
                                            energyCharge->CastSpell(southEast, SPELL_CORE_BEAM, true);
                                            energyCharge->SetTarget(southEast->GetGUID());
                                            energyCharge->GetMotionMaster()->MovePoint(POINT_EMPYEREAN_FOCUS, empyrealFocusPosition[i]);
                                        }

                                        break;
                                    }
                                    case 4:
                                    {
                                        if (Creature* south = pInstance->instance->GetCreature(instance->GetObjectGuid(empyrealFocus[2])))
                                        {
                                            energyCharge->CastSpell(south, SPELL_CORE_BEAM, true);
                                            energyCharge->SetTarget(south->GetGUID());
                                            energyCharge->GetMotionMaster()->MovePoint(POINT_EMPYEREAN_FOCUS, empyrealFocusPosition[i]);
                                        }

                                        break;
                                    }
                                    case 5:
                                    {
                                        if (Creature* southWest = pInstance->instance->GetCreature(instance->GetObjectGuid(empyrealFocus[0])))
                                        {
                                            energyCharge->CastSpell(southWest, SPELL_CORE_BEAM, true);
                                            energyCharge->SetTarget(southWest->GetGUID());
                                            energyCharge->GetMotionMaster()->MovePoint(POINT_EMPYEREAN_FOCUS, empyrealFocusPosition[i]);
                                        }

                                        break;
                                    }
                                    default:
                                        break;
                                }
                            }
                        }

                        break;
                    }
                    case ACTION_DESPAWN_ENERGY_CHARGES:
                    {
                        std::list<Creature*> energyChargesList;
                        GetCreatureListWithEntryInGrid(energyChargesList, me, NPC_ENERGY_CHARGE, 100.0f);

                        if (phase == PHASE_2)
                        {
                            Talk(TALK_C_TO_A_1);
                            events.ScheduleEvent(EVENT_DESPAWN_PLATFORM, 6000);
                            events.ScheduleEvent(EVENT_LAUNCH_COSMIC_SPARK, 6000);
                        }

                        me->AddAura(SPELL_UNSTABLE_ENERGY, me);
                        me->AddAura(SPELL_PHASE_SHIFTED, me);

                        phase = PHASE_3;

                        for (auto itr : energyChargesList)
                            itr->DespawnOrUnsummon(50);

                        break;
                    }
                    case ACTION_EMPYREAL_FOCUS_KILLED:
                    {
                        empyrealFocusKilled++;

                        if (empyrealFocusKilled < 6)
                            break;

                        empyrealFocusKilled = 0;

                        events.ScheduleEvent(EVENT_END_OF_PHASE_3, 6000);

                        Talk(TALK_A_TO_B_1);

                        break;
                    }
                    default:
                        break;
                }
            }

            void JustSummoned(Creature* summon)
            {
                summons.Summon(summon);

                if (summon->GetEntry() == NPC_ENERGY_CHARGE)
                    energyChargeCounter++;
            }

            void SummonedCreatureDespawn(Creature* summon)
            {
                summons.Despawn(summon);

                if (summon->GetEntry() == NPC_ENERGY_CHARGE && energyChargeCounter > 0)
                    energyChargeCounter--;
            }

            void KilledUnit(Unit* who)
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(TALK_SLAY);
            }

            void DamageTaken(Unit* attacker, uint32& damage)
            {
                if (phase == PHASE_1 && me->HealthBelowPctDamaged(nextPhase1EndingHealthPct, damage))
                {
                    phase = PHASE_2;
                    phase2WaveCount = 0;

                    Talk(TALK_B_TO_C_1);

                    if (nextPhase1EndingHealthPct == 85.0f)
                        nextPhase1EndingHealthPct = 50.0f;
                    else if (nextPhase1EndingHealthPct == 50.0f)
                    {
                        events.ScheduleEvent(EVENT_RADIATING_ENERGIES, 1000);
                        nextPhase1EndingHealthPct = 0.0f;
                    }

                    events.ScheduleEvent(EVENT_CHECK_MELEE,            2500);
                    events.ScheduleEvent(EVENT_DRAW_POWER,             1000);
                }
                else if (damage > me->GetHealth())
                    me->RemoveUnitMovementFlag(MOVEMENTFLAG_DISABLE_GRAVITY|MOVEMENTFLAG_FLYING|MOVEMENTFLAG_CAN_FLY);
            }

            void JustDied(Unit* killer)
            {
                _JustDied();

                if (pInstance)
                {
                    pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                    pInstance->SetBossState(DATA_ELEGON, DONE);
                    me->RemoveAurasDueToSpell(SPELL_VORTEX_VISIBILITY);

                    Map::PlayerList const& playerList = pInstance->instance->GetPlayers();
                    if (!playerList.isEmpty())
                    {
                        for (Map::PlayerList::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                        {
                            if (Player* player = itr->GetSource())
                            {
                                if (player->IsGameMaster())
                                    continue;

                                if (player->IsAlive())
                                {
                                    player->CombatStop();
                                    player->CombatStopWithPets(true);
                                }
                            }
                        }
                    }
                }
                
		float ori = _summonCacheOfPureEnergyPosition.GetOrientation();
                GameObject *pChest = killer->SummonGameObject(GAMEOBJECT_CACHE_OF_PURE_ENERGY, _summonCacheOfPureEnergyPosition.GetPositionX(), _summonCacheOfPureEnergyPosition.GetPositionY(), _summonCacheOfPureEnergyPosition.GetPositionZ(),
                                        ori, 0.0f, 0.0f, std::cos(ori/2), std::sin(ori/2), 300);

                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MoveLand(2, middlePos);

                me->RemoveAurasDueToSpell(SPELL_RADIATING_ENERGIES_VISUAL);
                Talk(TALK_DEATH);
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (!who || who->GetTypeId() != TYPEID_PLAYER)
                    return;

                if (who->HasAura(SPELL_TOUCH_OF_THE_TITANS) || who->HasAura(SPELL_TOUCH_OF_TITANS_VISUAL) || who->HasAura(SPELL_OVERCHARGED))
                    return;

                if (me->IsWithinDistInMap(who, 38.5f))
                {
                    if (Player* player = who->ToPlayer())
                    {
                        if (player->IsGameMaster())
                            return;

                        if (player->IsAlive())
                        {
                            player->CastSpell(player, SPELL_TOUCH_OF_THE_TITANS, true);
                            player->AddAura(SPELL_TOUCH_OF_TITANS_VISUAL, player);
                            player->CastSpell(player, SPELL_OVERCHARGED, true);
                        }
                    }
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                switch (events.ExecuteEvent())
                {
                    // Phase 1
                    case EVENT_CHECK_MELEE:
                    {
                        if (phase != PHASE_1)
                            break;

                        if (!me->IsWithinMeleeRange(me->GetVictim(), 10.0f))
                            me->CastSpell(me, SPELL_GRASPING_ENERGY_TENDRILS, false);

                        events.ScheduleEvent(EVENT_CHECK_MELEE, 2500);
                        break;
                    }
                    case EVENT_CELESTIAL_BREATH:
                    {
                        if (phase == PHASE_1)
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_CELESTIAL_BREATH, false);

                        events.ScheduleEvent(EVENT_CELESTIAL_BREATH, 10000);
                        break;
                    }
                    case EVENT_MATERIALIZE_PROTECTOR:
                    {
                        if (phase == PHASE_1 && nextPhase1EndingHealthPct > 0.0f)
                            me->CastSpell(me, SPELL_MATERIALIZE_PROTECTOR, false);

                        events.ScheduleEvent(EVENT_MATERIALIZE_PROTECTOR, urand(35000, 40000));
                        break;
                    }
                    case EVENT_RADIATING_ENERGIES:
                    {
                        if (me->HasAura(SPELL_RADIATING_ENERGIES))
                            break;

                        if (phase == PHASE_1)
                        {
                            me->CastSpell(me, SPELL_RADIATING_ENERGIES, true);
                            me->CastSpell(me, SPELL_RADIATING_ENERGIES_VISUAL, true);
                            Talk(TALK_ENRAGE_SOFT);
                        }

                        events.ScheduleEvent(EVENT_RADIATING_ENERGIES, 1000);
                        break;
                    }
                    // Phase 2
                    case EVENT_DRAW_POWER:
                    {
                        if (phase == PHASE_2)
                        {
                            if (!successfulDrawingPower)
                                me->CastSpell(me, SPELL_DRAW_POWER_LONG, false);
                            else
                                me->CastSpell(me, SPELL_DRAW_POWER_SHORT, false);

                            successfulDrawingPower++;
                        }

                        events.ScheduleEvent(EVENT_FOCUS_POWER, 100); // We don't decount when casting
                        break;
                    }
                    case EVENT_FOCUS_POWER:
                    {
                        if (phase == PHASE_2)
                            if (energyChargeCounter)
                                me->CastSpell(me, SPELL_FOCUS_POWER, false);

                        events.ScheduleEvent(EVENT_DRAW_POWER, 100); // We don't decount when casting
                        break;
                    }
                    // Phase 3
                    case EVENT_DESPAWN_PLATFORM:
                    {
                        if (phase == PHASE_3)
                        {
                            Talk(TALK_C_TO_A_2);

                            if (pInstance)
                            {
                                if (GameObject* energyPlatform = pInstance->GetGameObject(pInstance->GetData64(GOB_ENERGY_PLATFORM)))
                                    energyPlatform->SetGoState(GO_STATE_ACTIVE);

                                std::list<GameObject*> titanCircles1;
                                std::list<GameObject*> titanCircles2;
                                std::list<GameObject*> titanCircles3;
                                GetGameObjectListWithEntryInGrid(titanCircles1, me, GOB_ENERGY_TITAN_CIRCLE_1, 100.0f);
                                GetGameObjectListWithEntryInGrid(titanCircles2, me, GOB_ENERGY_TITAN_CIRCLE_2, 100.0f);
                                GetGameObjectListWithEntryInGrid(titanCircles3, me, GOB_ENERGY_TITAN_CIRCLE_3, 100.0f);
                                me->RemoveAurasDueToSpell(SPELL_VORTEX_VISIBILITY);

                                for (auto titanCircle : titanCircles1)
                                    titanCircle->SetGoState(GO_STATE_ACTIVE);
                                for (auto titanCircle : titanCircles2)
                                    titanCircle->SetGoState(GO_STATE_ACTIVE);
                                for (auto titanCircle : titanCircles3)
                                    titanCircle->SetGoState(GO_STATE_ACTIVE);

                                std::list<GameObject*> moguRune;

                                for (uint32 entry = GOB_MOGU_RUNE_FIRST; entry < GOB_MOGU_RUNE_END; entry++)
                                {
                                    GetGameObjectListWithEntryInGrid(moguRune, me, entry, 500.0f);

                                    for (auto itr : moguRune)
                                        itr->SetGoState(GO_STATE_ACTIVE);

                                    moguRune.clear();
                                }
                            }
                        }

                        events.ScheduleEvent(EVENT_AFTER_DESPAWN_PLATFORM, 2000);

                        break;
                    }
                    case EVENT_AFTER_DESPAWN_PLATFORM:
                    {
                        if (phase == PHASE_3)
                            Talk(TALK_C_TO_A_3);

                        break;
                    }
                    case EVENT_END_OF_PHASE_3:
                    {
                        if (phase == PHASE_3)
                        {
                            Talk(TALK_A_TO_B_2);

                            if (pInstance)
                            {
                                if (GameObject* energyPlatform = pInstance->GetGameObject(pInstance->GetData64(GOB_ENERGY_PLATFORM)))
                                    energyPlatform->SetGoState(GO_STATE_READY);

                                std::list<GameObject*> titanCircles1;
                                std::list<GameObject*> titanCircles2;
                                std::list<GameObject*> titanCircles3;
                                GetGameObjectListWithEntryInGrid(titanCircles1, me, GOB_ENERGY_TITAN_CIRCLE_1, 100.0f);
                                GetGameObjectListWithEntryInGrid(titanCircles2, me, GOB_ENERGY_TITAN_CIRCLE_2, 100.0f);
                                GetGameObjectListWithEntryInGrid(titanCircles3, me, GOB_ENERGY_TITAN_CIRCLE_3, 100.0f);

                                for (auto titanCircle : titanCircles1)
                                    titanCircle->SetGoState(GO_STATE_READY);
                                for (auto titanCircle : titanCircles2)
                                    titanCircle->SetGoState(GO_STATE_READY);
                                for (auto titanCircle : titanCircles3)
                                    titanCircle->SetGoState(GO_STATE_READY);

                                std::list<GameObject*> moguRune;
                                me->AddAura(SPELL_VORTEX_VISIBILITY, me);

                                for (uint32 entry = GOB_MOGU_RUNE_FIRST; entry < GOB_MOGU_RUNE_END; entry++)
                                {
                                    GetGameObjectListWithEntryInGrid(moguRune, me, entry, 500.0f);

                                    for (auto itr : moguRune)
                                        itr->SetGoState(GO_STATE_READY);

                                    moguRune.clear();
                                }
                            }

                            phase = PHASE_1;

                            me->RemoveAurasDueToSpell(SPELL_UNSTABLE_ENERGY);
                            me->RemoveAurasDueToSpell(SPELL_PHASE_SHIFTED);
                            me->RemoveAurasDueToSpell(SPELL_OVERLOADED);
                        }

                        events.ScheduleEvent(EVENT_CHECK_MELEE, 5000);

                        break;
                    }
                    case EVENT_LAUNCH_COSMIC_SPARK:
                    {
                        if (phase == PHASE_3)
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_ENERGY_CASCADE, false);

                        events.ScheduleEvent(EVENT_LAUNCH_COSMIC_SPARK, 5000);
                        break;
                    }
                    // Others
                    case EVENT_ENRAGE_HARD:
                    {
                        me->CastSpell(me, SPELL_BERSERK, true);
                        Talk(TALK_ENRAGE_HARD);
                        break;
                    }
                    default:
                        break;
                }

                if (phase == PHASE_1)
                    DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_elegonAI(creature);
        }
};

// Empyreal Focus - 60776
class mob_empyreal_focus : public CreatureScript
{
    public:
        mob_empyreal_focus() : CreatureScript("mob_empyreal_focus") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_empyreal_focusAI(creature);
        }

        struct mob_empyreal_focusAI : public ScriptedAI
        {
            mob_empyreal_focusAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            EventMap events;
            bool activationDone;
            InstanceScript* pInstance;

            void Reset()
            {
                events.Reset();

                activationDone = false;

                me->SetReactState(REACT_PASSIVE);
                me->AddAura(SPELL_FOCUS_INACTIVE, me);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);

                Position pos;
                pos = me->GetPosition();

                for (int i = 0; i < 6; i++)
                {
                    if (pos.GetPositionX() - empyrealFocusPosition[i].GetPositionX() <= 4.0f &&
                        pos.GetPositionX() - empyrealFocusPosition[i].GetPositionX() >= -4.0f &&
                        pos.GetPositionY() - empyrealFocusPosition[i].GetPositionY() <= 4.0f &&
                        pos.GetPositionY() - empyrealFocusPosition[i].GetPositionY() >= -4.0f)
                    {
                        switch (i)
                        {
                            case 0:
                                empyrealFocus[1] = me->GetGUID().GetEntry();
                                break;
                            case 1:
                                empyrealFocus[3] = me->GetGUID().GetEntry();
                                break;
                            case 2:
                                empyrealFocus[5] = me->GetGUID().GetEntry();
                                break;
                            case 3:
                                empyrealFocus[4] = me->GetGUID().GetEntry();
                                break;
                            case 4:
                                empyrealFocus[2] = me->GetGUID().GetEntry();
                                break;
                            case 5:
                                empyrealFocus[0] = me->GetGUID().GetEntry();
                                break;
                        }

                        break;
                    }
                }
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case ACTION_ACTIVATE_EMPYREAL_FOCUS:
                    {
                        if (activationDone)
                            break;

                        events.ScheduleEvent(EVENT_ACTIVATE_EMPYREAL_FOCUS, 3000);

                        me->CastSpell(me, SPELL_FOCUS_ACTIVATION_VISUAL, true);

                        if (pInstance && !activationDone)
                            if (Creature* elegon = pInstance->GetCreature(pInstance->GetData64(NPC_ELEGON)))
                                elegon->AI()->DoAction(ACTION_DESPAWN_ENERGY_CHARGES);

                        activationDone = true;

                        /*for (int i = 0; i < 6; i++)
                        {
                            if (Unit* focus = ObjectAccessor::FindUnit(empyrealFocus[i]))
                                if (focus->GetAI())
                                    focus->GetAI()->DoAction(ACTION_ACTIVATE_EMPYREAL_FOCUS);
                        }*/

                        break;
                    }
                    case ACTION_RESET_EMPYREAL_FOCUS:
                    {
                        me->RemoveAurasDueToSpell(SPELL_FOCUS_ACTIVATE_STATE);
                        me->RemoveAurasDueToSpell(SPELL_FOCUS_LIGHT_WALL_VISUAL);
                        me->RemoveAurasDueToSpell(SPELL_FOCUS_LIGHT_CASTBAR);

                        me->SetHealth(me->GetMaxHealth());

                        //if (AreaTrigger* lightningWall = me->GetAreaTrigger(SPELL_FOCUS_LIGHT_AREATRIGGER))
                        //    lightningWall->Expire();

                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        activationDone = false;
                        break;
                    }
                    default:
                        break;
                }
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage)
            {
                if (me->GetHealth() < damage)
                {
                    damage = 0;

                    activationDone = false;
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    me->RemoveAurasDueToSpell(SPELL_FOCUS_ACTIVATE_STATE);
                    me->RemoveAurasDueToSpell(SPELL_FOCUS_LIGHT_WALL_VISUAL);
                    me->RemoveAurasDueToSpell(SPELL_FOCUS_LIGHT_CASTBAR);

                    me->SetHealth(me->GetMaxHealth());

                    /*if (AreaTrigger* lightningWall = me->GetAreaTrigger(SPELL_FOCUS_LIGHT_AREATRIGGER))
                        lightningWall->Expire();*/

                    if (pInstance)
                    {
                        if (Creature* elegon = pInstance->GetCreature(pInstance->GetData64(NPC_ELEGON)))
                        {
                            me->CastSpell(elegon, SPELL_OVERLOADED_MISSILE, false);
                            elegon->AI()->DoAction(ACTION_EMPYREAL_FOCUS_KILLED);
                        }
                    }
                }
            }

            void UpdateAI(uint32 diff)
            {
                events.Update(diff);

                switch (events.ExecuteEvent())
                {
                    case EVENT_ACTIVATE_EMPYREAL_FOCUS:
                        me->CastSpell(me, SPELL_FOCUS_ACTIVATE_STATE, true);
                        events.ScheduleEvent(EVENT_APPEAR_WALL_OF_LIGHTNING, 3000);
                        break;
                    case EVENT_APPEAR_WALL_OF_LIGHTNING:
                        me->CastSpell(me, SPELL_FOCUS_LIGHT_AREATRIGGER, true);
                        me->CastSpell(me, SPELL_FOCUS_LIGHT_CASTBAR, true);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        break;
                    default:
                        break;
                }
            }
        };
};

// Celestial Protector - 60793
class mob_celestial_protector : public CreatureScript
{
    public:
        mob_celestial_protector() : CreatureScript("mob_celestial_protector") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_celestial_protectorAI(creature);
        }

        struct mob_celestial_protectorAI : public ScriptedAI
        {
            mob_celestial_protectorAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;
            bool stabilityFluxCasted;
            bool totalAnnihilationCasted;

            void Reset()
            {
                events.Reset();

                events.ScheduleEvent(EVENT_ARCING_ENERGY, 10000);
                events.ScheduleEvent(EVENT_CHECK_UNIT_ON_PLATFORM, 1000);

                stabilityFluxCasted     = false;
                totalAnnihilationCasted = false;

                if (Player* player = me->SelectNearestPlayer())
                    AttackStart(player);
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage)
            {
                if (!stabilityFluxCasted)
                {
                    if (me->HealthBelowPctDamaged(25, damage))
                    {
                        me->CastSpell(me, SPELL_STABILITY_FLUX, false);
                        stabilityFluxCasted = true;
                    }
                }

                if (me->GetHealth() < damage)
                {
                    damage = 0;
                    
                    if (!totalAnnihilationCasted)
                    {
                        me->CastSpell(me, SPELL_TOTAL_ANNIHILATION, false);
                        totalAnnihilationCasted = true;
                        events.ScheduleEvent(EVENT_KILLED , 4500);
                    }
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;
                
                events.Update(diff);
                
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CHECK_UNIT_ON_PLATFORM:
                        {
                            if (me->GetDistance(middlePos) <= 36.0f)
                            {
                                if (me->GetHealthPct() > 25.0f)
                                {
                                    me->AddAura(SPELL_ECLIPSE_PHASE, me);
                                    me->RemoveAurasDueToSpell(SPELL_ECLIPSE_NO_PHASE);
                                }
                                else
                                {
                                    me->RemoveAurasDueToSpell(SPELL_ECLIPSE_NO_PHASE);
                                    me->RemoveAurasDueToSpell(SPELL_ECLIPSE_PHASE);
                                }

                                me->CastSpell(me, SPELL_TOUCH_OF_THE_TITANS, true);
                            }
                            else
                            {
                                if (me->GetHealthPct() > 25.0f)
                                {
                                    me->AddAura(SPELL_ECLIPSE_NO_PHASE, me);
                                    me->RemoveAurasDueToSpell(SPELL_ECLIPSE_PHASE);
                                }
                                else
                                {
                                    me->RemoveAurasDueToSpell(SPELL_ECLIPSE_NO_PHASE);
                                    me->RemoveAurasDueToSpell(SPELL_ECLIPSE_PHASE);
                                }

                                me->RemoveAurasDueToSpell(SPELL_TOUCH_OF_THE_TITANS);
                            }
                            events.ScheduleEvent(EVENT_CHECK_UNIT_ON_PLATFORM, 1000);
                            break;
                        }
                        case EVENT_ARCING_ENERGY:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_ARCING_ENERGY, false);
                            events.ScheduleEvent(EVENT_ARCING_ENERGY,      30000);
                            break;
                        }
                        case EVENT_KILLED:
                            me->Kill(me);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

// Cosmic Spark - 62618
class mob_cosmic_spark : public CreatureScript
{
    public:
        mob_cosmic_spark() : CreatureScript("mob_cosmic_spark") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_cosmic_sparkAI(creature);
        }

        struct mob_cosmic_sparkAI : public ScriptedAI
        {
            mob_cosmic_sparkAI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetReactState(REACT_AGGRESSIVE);
            }

            EventMap events;

            void Reset()
            {
                events.Reset();
                
                events.ScheduleEvent(EVENT_CHECK_UNIT_ON_PLATFORM, 1000);
                events.ScheduleEvent(EVENT_ICE_TRAP, 10000);

                if (Player* player = me->SelectNearestPlayer())
                    AttackStart(player);
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;
                
                events.Update(diff);
                
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CHECK_UNIT_ON_PLATFORM:
                            if (me->GetDistance(middlePos) <= 36.0f)
                                me->CastSpell(me, SPELL_TOUCH_OF_THE_TITANS, true);
                            else
                                me->RemoveAurasDueToSpell(SPELL_TOUCH_OF_THE_TITANS);
                            events.ScheduleEvent(EVENT_CHECK_UNIT_ON_PLATFORM, 1000);
                            break;
                        case EVENT_ICE_TRAP:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_ICE_TRAP, false);
                            events.ScheduleEvent(EVENT_ICE_TRAP,      60000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

enum energyChargeActions
{
    ACTION_ENERGIZE_EMPYREAL_FOCUS  = 1,
};

// Energy Charge - 60913
class mob_energy_charge : public CreatureScript
{
    public:
        mob_energy_charge() : CreatureScript("mob_energy_charge") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_energy_chargeAI(creature);
        }

        struct mob_energy_chargeAI : public ScriptedAI
        {
            mob_energy_chargeAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset()
            {
                me->SetReactState(REACT_PASSIVE);
                me->AddAura(SPELL_CORE_CHECKER, me);
            }

            void JustDied(Unit* killer)
            {
                me->CastSpell(me, SPELL_DISCHARGE, true);
            }

            void MovementInform(uint32 type, uint32 id)
            {
                switch (id)
                {
                    /*case POINT_EMPYEREAN_FOCUS:
                    {
                        if (Unit* focus = ObjectAccessor::FindUnit(me->GetUInt64Value(UNIT_FIELD_TARGET)))
                        {
                            Position pos;
                            focus->GetPosition();

                            me->GetMotionMaster()->MovePoint(POINT_EMPYEREAN_FOCUS, pos);
                        }

                        break;
                    }*/
                    default:
                        break;
                }
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    /*case ACTION_ENERGIZE_EMPYREAL_FOCUS:
                    {
                        if (Unit* focus = ObjectAccessor::FindUnit(me->GetUInt64Value(UNIT_FIELD_TARGET)))
                            if (focus->GetAI())
                                focus->GetAI()->DoAction(ACTION_ACTIVATE_EMPYREAL_FOCUS);

                        me->RemoveAurasDueToSpell(SPELL_CORE_CHECKER);
                        me->DespawnOrUnsummon();

                        break;
                    }*/
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff)
            {
            }
        };
};

enum infiniteActions
{
    ACTION_INFINITE_GO_DOWN         = 0,
    ACTION_INFINITE_ACTIVATION_WEST = 1,
    ACTION_INFINITE_ACTIVATION      = 2,
    ACTION_INFINITE_ACTIVATION_EAST = 3,
    ACTION_INFINITE_FLASH_SPAWN     = 4,
    ACTION_INFINITE_SPAWN_PLATFORM  = 5,
    ACTION_INFINITE_SPAWN_BOSS      = 6,
};

enum infiniteEvents
{
    EVENT_ACTIVATION_WEST   = 1,
    EVENT_ACTIVATION        = 2,
    EVENT_ACTIVATION_EAST   = 3,
    EVENT_FLASH_SPAWN       = 4,
    EVENT_BOSS_ACTIVATION   = 5,
    EVENT_BOSS_INTRO_2      = 6,
};

// Infinite Energy - 65293
class mob_infinite_energy : public CreatureScript
{
    public:
        mob_infinite_energy() : CreatureScript("mob_infinite_energy"){ }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_infinite_energyAI(creature);
        }

        struct mob_infinite_energyAI : public ScriptedAI
        {
            mob_infinite_energyAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            EventMap events;

            void Reset()
            {
                events.Reset();
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case ACTION_INFINITE_GO_DOWN:
                    {
                        me->GetMotionMaster()->MovePoint(0, infiniteEnergyPos);
                        events.ScheduleEvent(EVENT_ACTIVATION_WEST, 3000);
                        break;
                    }
                    case ACTION_INFINITE_ACTIVATION_WEST:
                    {
                        if (pInstance)
                        {
                            Creature* southWest = pInstance->GetCreature(empyrealFocus[0]);
                            Creature* northWest = pInstance->GetCreature(empyrealFocus[1]);

                            if (southWest && northWest)
                            {
                                southWest->RemoveAurasDueToSpell(SPELL_FOCUS_INACTIVE);
                                northWest->RemoveAurasDueToSpell(SPELL_FOCUS_INACTIVE);
                            }
                        }

                        events.ScheduleEvent(EVENT_ACTIVATION, 1000);
                        break;
                    }
                    case ACTION_INFINITE_ACTIVATION:
                    {
                        if (pInstance)
                        {
                            Creature* south = pInstance->instance->GetCreature(pInstance->GetObjectGuid(empyrealFocus[2]));
                            Creature* north = pInstance->instance->GetCreature(pInstance->GetObjectGuid(empyrealFocus[3]));

                            if (south && north)
                            {
                                south->RemoveAurasDueToSpell(SPELL_FOCUS_INACTIVE);
                                north->RemoveAurasDueToSpell(SPELL_FOCUS_INACTIVE);
                            }
                        }

                        events.ScheduleEvent(EVENT_ACTIVATION_EAST, 1000);
                        break;
                    }
                    case ACTION_INFINITE_ACTIVATION_EAST:
                    {
                        if (pInstance)
                        {
                            Creature* southEast = pInstance->instance->GetCreature(pInstance->GetObjectGuid(empyrealFocus[4]));
                            Creature* northEast = pInstance->instance->GetCreature(pInstance->GetObjectGuid(empyrealFocus[5]));

                            if (southEast && northEast)
                            {
                                southEast->RemoveAurasDueToSpell(SPELL_FOCUS_INACTIVE);
                                northEast->RemoveAurasDueToSpell(SPELL_FOCUS_INACTIVE);
                            }
                        }

                        events.ScheduleEvent(EVENT_FLASH_SPAWN, 1000);
                        break;
                    }
                    case ACTION_INFINITE_FLASH_SPAWN:
                    {
                        me->CastSpell(me, SPELL_SPAWN_FLASH_1_PERIODIC, true);
                        break;
                    }
                    case ACTION_INFINITE_SPAWN_PLATFORM:
                    {
                        if (pInstance)
                        {
                            if (GameObject* energyPlatform = pInstance->instance->GetGameObject(pInstance->GetObjectGuid(pInstance->GetData64(GOB_ENERGY_PLATFORM))))
                                energyPlatform->SetGoState(GO_STATE_READY);

                            std::list<GameObject*> titanCircles1;
                            std::list<GameObject*> titanCircles2;
                            std::list<GameObject*> titanCircles3;
                            GetGameObjectListWithEntryInGrid(titanCircles1, me, GOB_ENERGY_TITAN_CIRCLE_1, 100.0f);
                            GetGameObjectListWithEntryInGrid(titanCircles2, me, GOB_ENERGY_TITAN_CIRCLE_2, 100.0f);
                            GetGameObjectListWithEntryInGrid(titanCircles3, me, GOB_ENERGY_TITAN_CIRCLE_3, 100.0f);

                            for (auto titanCircle : titanCircles1)
                                titanCircle->SetGoState(GO_STATE_READY);
                            for (auto titanCircle : titanCircles2)
                                titanCircle->SetGoState(GO_STATE_READY);
                            for (auto titanCircle : titanCircles3)
                                titanCircle->SetGoState(GO_STATE_READY);

                            std::list<GameObject*> moguRune;

                            for (uint32 entry = GOB_MOGU_RUNE_FIRST; entry < GOB_MOGU_RUNE_END; entry++)
                            {
                                GetGameObjectListWithEntryInGrid(moguRune, me, entry, 500.0f);

                                for (auto itr : moguRune)
                                    itr->SetGoState(GO_STATE_READY);

                                moguRune.clear();
                            }
                        }
                        break;
                    }
                    case ACTION_INFINITE_SPAWN_BOSS:
                    {
                        if (pInstance)
                        {
                            if (Creature* elegon = pInstance->instance->GetCreature(pInstance->GetObjectGuid(pInstance->GetData64(NPC_ELEGON))))
                            {
                                elegon->RestoreDisplayId();
                                elegon->AI()->Talk(TALK_INTRO);
                                events.ScheduleEvent(EVENT_BOSS_INTRO_2,    5000);
                                events.ScheduleEvent(EVENT_BOSS_ACTIVATION, 8000);
                            }
                        }
                        break;
                    }
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff)
            {
                events.Update(diff);

                switch (events.ExecuteEvent())
                {
                    case EVENT_ACTIVATION_WEST:
                    {
                        me->AI()->DoAction(ACTION_INFINITE_ACTIVATION_WEST);
                        break;
                    }
                    case EVENT_ACTIVATION:
                    {
                        me->AI()->DoAction(ACTION_INFINITE_ACTIVATION);
                        break;
                    }
                    case EVENT_ACTIVATION_EAST:
                    {
                        me->AI()->DoAction(ACTION_INFINITE_ACTIVATION_EAST);
                        break;
                    }
                    case EVENT_FLASH_SPAWN:
                    {
                        me->AI()->DoAction(ACTION_INFINITE_FLASH_SPAWN);
                        break;
                    }
                    case EVENT_BOSS_ACTIVATION:
                    {
                        if (pInstance)
                            if (Creature* elegon = pInstance->instance->GetCreature(pInstance->GetObjectGuid(pInstance->GetData64(NPC_ELEGON))))
                                elegon->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_IMMUNE_TO_PC|UNIT_FLAG_UNK_15);

                        break;
                    }
                    case EVENT_BOSS_INTRO_2:
                    {
                        if (pInstance)
                            if (Creature* elegon = pInstance->instance->GetCreature(pInstance->GetObjectGuid(pInstance->GetData64(NPC_ELEGON))))
                                elegon->AI()->Talk(TALK_INTRO_2);

                        break;
                    }
                    default:
                        break;
                }
            }
        };
};

// Celestial Control Console - 211650
class go_celestial_control_console : public GameObjectScript
{
    public:
        go_celestial_control_console() : GameObjectScript("go_celestial_control_console") { }

        bool OnGossipHello(Player* player, GameObject* go)
        {
            if (InstanceScript* pInstance = player->GetInstanceScript())
            {
                if (Creature* infiniteEnergy = pInstance->instance->GetCreature(pInstance->GetObjectGuid(pInstance->GetData64(NPC_INFINITE_ENERGY))))
                    infiniteEnergy->AI()->DoAction(ACTION_INFINITE_GO_DOWN);

                if (GameObject* titanDisk = pInstance->instance->GetGameObject(pInstance->GetObjectGuid(pInstance->GetData64(GOB_ENERGY_TITAN_DISK))))
                    titanDisk->SetGoState(GO_STATE_READY);

                go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
            }

            return false;
        }
};

// Spawn Flash 1 Periodic - 127785
class spell_spawn_flash_1_periodic : public SpellScriptLoader
{
    public:
        spell_spawn_flash_1_periodic() : SpellScriptLoader("spell_spawn_flash_1_periodic") { }

        class spell_spawn_flash_1_periodic_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_spawn_flash_1_periodic_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* target = GetTarget())
                {
                    target->CastSpell(target, SPELL_SPAWN_FLASH_2_PERIODIC, true);
                    target->SetDisplayId(11686); // Invisible
                }
            }

            void Register()
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_spawn_flash_1_periodic_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_spawn_flash_1_periodic_AuraScript();
        }
};

// Spawn Flash 2 Periodic - 127783
class spell_spawn_flash_2_periodic : public SpellScriptLoader
{
    public:
        spell_spawn_flash_2_periodic() : SpellScriptLoader("spell_spawn_flash_2_periodic") { }

        class spell_spawn_flash_2_periodic_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_spawn_flash_2_periodic_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* target = GetTarget())
                {
                    target->CastSpell(target, SPELL_SPAWN_FLASH_3_PERIODIC, true);

                    if (target->GetAI())
                        target->GetAI()->DoAction(ACTION_INFINITE_SPAWN_PLATFORM);
                }
            }

            void Register()
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_spawn_flash_2_periodic_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_spawn_flash_2_periodic_AuraScript();
        }
};

// Spawn Flash 3 Periodic - 127781
class spell_spawn_flash_3_periodic : public SpellScriptLoader
{
    public:
        spell_spawn_flash_3_periodic() : SpellScriptLoader("spell_spawn_flash_3_periodic") { }

        class spell_spawn_flash_3_periodic_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_spawn_flash_3_periodic_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* target = GetTarget())
                    if (target->GetAI())
                        target->GetAI()->DoAction(ACTION_INFINITE_SPAWN_BOSS);
            }

            void Register()
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_spawn_flash_3_periodic_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_spawn_flash_3_periodic_AuraScript();
        }
};

// Touch of Titans - 117874
class spell_touch_of_titans : public SpellScriptLoader
{
    public:
        spell_touch_of_titans() : SpellScriptLoader("spell_touch_of_titans") { }

        class spell_touch_of_titans_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_touch_of_titans_AuraScript);

            void OnTick(AuraEffect const* aurEff)
            {
                if (!GetTarget())
                    return;

                if (Player* player = GetTarget()->ToPlayer())
                {
                    if (player->GetDistance(middlePos) > 36.0f)
                    {
                        player->RemoveAurasDueToSpell(SPELL_TOUCH_OF_THE_TITANS);
                        player->RemoveAurasDueToSpell(SPELL_TOUCH_OF_TITANS_VISUAL);
                        player->RemoveAurasDueToSpell(SPELL_OVERCHARGED);
                    }
                }
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* target = GetTarget())
                {
                    target->RemoveAurasDueToSpell(SPELL_TOUCH_OF_THE_TITANS);
                    target->RemoveAurasDueToSpell(SPELL_TOUCH_OF_TITANS_VISUAL);
                    target->RemoveAurasDueToSpell(SPELL_OVERCHARGED);
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_touch_of_titans_AuraScript::OnTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
                OnEffectRemove += AuraEffectRemoveFn(spell_touch_of_titans_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_touch_of_titans_AuraScript();
        }
};

// Radiating Energies - 118313 (outside) or Radiating Energies - 122741 (inside)
class spell_radiating_energies : public SpellScriptLoader
{
    public:
        spell_radiating_energies() : SpellScriptLoader("spell_radiating_energies") { }

        class spell_radiating_energies_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_radiating_energies_SpellScript);

            void CorrectRange(std::list<WorldObject*>& targets)
            {
                targets.clear();

                float MaxDist = GetSpellInfo()->Id == SPELL_RADIATING_INSIDE_VORTEX ? 36.0f : 200.0f;
                float MinDist = GetSpellInfo()->Id == SPELL_RADIATING_OUTSIDE_VORTEX ? 36.0f : 0.0f;

                Map::PlayerList const& players = GetCaster()->GetMap()->GetPlayers();
                if (!players.isEmpty())
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        if (Player* player = itr->GetSource())
                            if (player->GetExactDist2d(GetCaster()->GetPositionX(), GetCaster()->GetPositionY()) <= MaxDist &&
                                player->GetExactDist2d(GetCaster()->GetPositionX(), GetCaster()->GetPositionY()) >= MinDist)
                                targets.push_back(player);
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_radiating_energies_SpellScript::CorrectRange, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_radiating_energies_SpellScript();
        }
};

// Draw Power - 119360 and Draw Power - 124967
class spell_draw_power : public SpellScriptLoader
{
    public:
        spell_draw_power() : SpellScriptLoader("spell_draw_power") { }

        class spell_draw_power_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_draw_power_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* elegon = GetCaster())
                {
                    elegon->GetAI()->DoAction(ACTION_SPAWN_ENERGY_CHARGES);
                    elegon->AddAura(SPELL_DRAW_POWER_DEBUFF, elegon);
                }
            }

            void Register()
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_draw_power_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_draw_power_AuraScript();
        }
};

// Core Checker - 118024
class spell_core_checker : public SpellScriptLoader
{
    public:
        spell_core_checker() : SpellScriptLoader("spell_core_checker") { }

        class spell_core_checker_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_core_checker_AuraScript);

            void OnTick(AuraEffect const* aurEff)
            {
                if (Unit* energyCharge = GetTarget())
                {
                    std::list<Creature*> focus;
                    GetCreatureListWithEntryInGrid(focus, energyCharge, NPC_EMPYREAL_FOCUS, 1.0f);

                    if (!focus.empty())
                        if (energyCharge->GetAI())
                            energyCharge->GetAI()->DoAction(ACTION_ENERGIZE_EMPYREAL_FOCUS);
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_core_checker_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_core_checker_AuraScript();
        }
};

// Grasping Energy Tendrils - 127362
class spell_grasping_energy_tendrils : public SpellScriptLoader
{
    public:
        spell_grasping_energy_tendrils() : SpellScriptLoader("spell_grasping_energy_tendrils") { }

        class spell_grasping_energy_tendrils_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_grasping_energy_tendrils_SpellScript);

            void HandleOnHit()
            {
                if (Unit* elegon = GetCaster())
                {
                    if (Unit* target = GetHitUnit())
                    {
                        SpellInfo const* m_spellInfo = sSpellMgr->GetSpellInfo(SPELL_GRASPING_ENERGY_GRIP);
                        if (!m_spellInfo)
                            return;

                        // Init dest coordinates
                        float x, y, z;
                        elegon->GetPosition(x, y, z);

                        float dist = target->GetExactDist2d(x, y);

                        float speedZ, speedXY;
                        if (m_spellInfo->GetEffect(EFFECT_0)->MiscValue)
                            speedZ = float(m_spellInfo->GetEffect(EFFECT_0)->MiscValue)/10;
                        else if (m_spellInfo->GetEffect(EFFECT_0)->MiscValueB)
                            speedZ = float(m_spellInfo->GetEffect(EFFECT_0)->MiscValueB)/10;
                        else
                            speedZ = 10.0f;

                        speedXY = dist * 10.0f / speedZ;

                        target->GetMotionMaster()->MoveJump(x, y, z, speedXY, speedZ);
                    }
                }
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_grasping_energy_tendrils_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_grasping_energy_tendrils_SpellScript();
        }
};

// Unstable Energy - 116994
class spell_unstable_energy : public SpellScriptLoader
{
    public:
        spell_unstable_energy() : SpellScriptLoader("spell_unstable_energy") { }

        class spell_unstable_energy_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_unstable_energy_AuraScript);

            void OnTick(AuraEffect const* aurEff)
            {
                if (Unit* elegon = GetTarget())
                    elegon->CastSpell(elegon, SPELL_UNSTABLE_ENERGY_DAMAGE, true);
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_unstable_energy_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_unstable_energy_AuraScript();
        }
};

// SPELL_TOTAL_ANNIHILATION - 129711
class spell_total_annihilation : public SpellScriptLoader
{
    public:
        spell_total_annihilation() : SpellScriptLoader("spell_total_annihilation") { }

        class spell_total_annihilation_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_total_annihilation_SpellScript);

            void CheckIfAnyTarget(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    if (Unit* caster = GetCaster())
                        if (InstanceScript* pInstance = caster->GetInstanceScript())
                            if (Creature* elegon = pInstance->instance->GetCreature(pInstance->GetObjectGuid(pInstance->GetData64(NPC_ELEGON))))
                                elegon->CastSpell(caster, SPELL_CATASTROPHIC_ANOMALY, false);
            }

            void HandleOnCast()
            {
                if (Unit* caster = GetCaster())
                    if (caster->GetMap())
                        if (caster->GetMap()->IsHeroic()) // In Non-Heroic the spell trigger it by default
                            caster->CastSpell(caster, SPELL_TOTAL_ANNIHILATION_DAMAGE, true);
            }

            void HandleOnHit()
            {
                if (Unit* caster = GetCaster())
                {
                    if (caster->GetMap())
                        if (!caster->GetMap()->IsHeroic()) // In Non-Heroic the spell must not do it
                            return;

                    if (Unit* target = GetHitUnit())
                    {
                        if (target->HasAura(SPELL_DESTABILIZED))
                        {
                            target->RemoveAurasDueToSpell(SPELL_DESTABILIZING_ENERGIES);
                            caster->RemoveAurasDueToSpell(SPELL_DESTABILIZED);
                            caster->Kill(target);
                        }
                        else
                        {
                            caster->AddAura(SPELL_DESTABILIZING_ENERGIES, target);
                            caster->AddAura(SPELL_DESTABILIZED, target);
                        }
                    }
                }
            }

            void Register()
            {
                OnCast += SpellCastFn(spell_total_annihilation_SpellScript::HandleOnCast);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_total_annihilation_SpellScript::CheckIfAnyTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnHit += SpellHitFn(spell_total_annihilation_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_total_annihilation_SpellScript();
        }
};

// SPELL_DESTABILIZING_ENERGIES - 132222
class spell_destabilizing_energies : public SpellScriptLoader
{
    public:
        spell_destabilizing_energies() : SpellScriptLoader("spell_destabilizing_energies") { }

        class spell_destabilizing_energies_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_destabilizing_energies_AuraScript);

            void OnTick(AuraEffect const* aurEff)
            {
                if (Unit* player = GetTarget())
                    if (player->GetHealthPct() >= 80.0f)
                        player->RemoveAura(GetAura());
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_destabilizing_energies_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_destabilizing_energies_AuraScript();
        }
};

void AddSC_boss_elegon()
{
    new boss_elegon();
    new mob_empyreal_focus();
    new mob_celestial_protector();
    new mob_cosmic_spark();
    new mob_energy_charge();
    new mob_infinite_energy();
    new go_celestial_control_console();
    new spell_spawn_flash_1_periodic();
    new spell_spawn_flash_2_periodic();
    new spell_spawn_flash_3_periodic();
    new spell_touch_of_titans();
    new spell_radiating_energies();
    new spell_draw_power();
    new spell_core_checker();
    new spell_grasping_energy_tendrils();
    new spell_unstable_energy();
    new spell_destabilizing_energies();
    new spell_total_annihilation();
}
