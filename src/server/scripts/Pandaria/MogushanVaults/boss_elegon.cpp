/*
 * Copyright 2021 FuzionCore Project
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
    SPELL_ELEGON_OVERCHARGED        = 117877,
    SPELL_ELEGON_OVERCHARGED_2      = 117878,

    // Phase 1
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
    SPELL_ENERGY_CONDUIT            = 116663,

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
    SPELL_CATASTROPHIC_ANOMALY      = 127341,

    SPELL_ELEGON_BONUS              = 132192
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
    EVENT_COSMICSPARK_ATTACK        = 15
};

enum elegonActions
{
    ACTION_RESET_DRAWING_POWER      = 1,
    ACTION_SPAWN_ENERGY_CHARGES     = 2,
    ACTION_DESPAWN_ENERGY_CHARGES   = 3,
    ACTION_EMPYREAL_FOCUS_KILLED    = 4,
    ACTION_WIPE                     = 5
};

enum eMovementPoints
{
    POINT_EMPYEREAN_FOCUS   = 1
};

enum empyrealFocusActions
{
    ACTION_ACTIVATE_EMPYREAL_FOCUS  = 1,
    ACTION_RESET_EMPYREAL_FOCUS     = 2
};

enum empyrealFocusEvents
{
    EVENT_ACTIVATE_EMPYREAL_FOCUS   = 1,
    EVENT_APPEAR_WALL_OF_LIGHTNING  = 2
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
    TALK_SLAY           = 12
};

// Set values in reset of mob_empyreal_focus
ObjectGuid empyrealFocus[6] =
{
    ObjectGuid::Empty, // South-West
    ObjectGuid::Empty, // North-West
    ObjectGuid::Empty, // South
    ObjectGuid::Empty, // North
    ObjectGuid::Empty, // South-East
    ObjectGuid::Empty, // North-East
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

enum infiniteActions
{
    ACTION_INFINITE_GO_DOWN         = 0,
    ACTION_INFINITE_ACTIVATION_WEST = 1,
    ACTION_INFINITE_ACTIVATION      = 2,
    ACTION_INFINITE_ACTIVATION_EAST = 3,
    ACTION_INFINITE_FLASH_SPAWN     = 4,
    ACTION_INFINITE_SPAWN_PLATFORM  = 5,
    ACTION_INFINITE_SPAWN_BOSS      = 6,
    ACTION_INFINITE_LOOT            = 7
};

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
                creature->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_IMMUNE_TO_PC|UNIT_FLAG_UNK_15));
            }

            InstanceScript* pInstance;

            uint8 phase;
            uint8 phase2WaveCount;
            float nextPhase1EndingHealthPct;
            uint8 successfulDrawingPower;
            uint8 energyChargeCounter;
            uint8 empyrealFocusKilled;

            void Reset() override
            {
                if (Creature* cho = GetClosestCreatureWithEntry(me, NPC_LOREWALKER_CHO, 100.0f, true))
                    cho->AI()->Talk(26);

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

                summons.DespawnAll();

                if (pInstance)
                {
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TOUCH_OF_THE_TITANS);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TOUCH_OF_TITANS_VISUAL);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ELEGON_OVERCHARGED);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ELEGON_OVERCHARGED_2);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_CLOSED_CIRCUIT);
                    pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

                    for (int i = 0; i < 6; i++)
                    {
                        if (Unit* focus = ObjectAccessor::GetUnit(*me, empyrealFocus[i]))
                            if (focus->GetAI())
                                focus->GetAI()->DoAction(ACTION_RESET_EMPYREAL_FOCUS);
                    }
                }
            }

            void EnterCombat(Unit* /*p_Attacker*/) override
            {
                if (!pInstance->CheckRequiredBosses(DATA_ELEGON))
                {
                    EnterEvadeMode(EVADE_REASON_OTHER);
                    return;
                }

                if (Creature* cho = GetClosestCreatureWithEntry(me, NPC_LOREWALKER_CHO, 100.0f, true))
                {
                    cho->AI()->Talk(27);
                    cho->AI()->DoAction(ACTION_CONTINUE_ESCORT);
                }

                if (pInstance)
                {
                    pInstance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                    pInstance->SetBossState(DATA_ELEGON, IN_PROGRESS);
                }

                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_IMMUNE_TO_PC|UNIT_FLAG_UNK_15));
                me->RemoveAurasDueToSpell(SPELL_APPARITION_VISUAL);
                me->SetReactState(REACT_AGGRESSIVE);

                Talk(TALK_AGGRO);

                events.ScheduleEvent(EVENT_CHECK_MELEE,             2500);
                events.ScheduleEvent(EVENT_CELESTIAL_BREATH,        10000);
                events.ScheduleEvent(EVENT_MATERIALIZE_PROTECTOR,   urand(35000, 40000));
                events.ScheduleEvent(EVENT_ENRAGE_HARD,             570000); // 9min30
            }

            void AttackStart(Unit* target) override
            {
                if (!target)
                    return;

                if (me->Attack(target, true))
                    DoStartNoMovement(target);
            }

            void DoAction(const int32 action) override
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
                                        if (Creature* northWest = pInstance->instance->GetCreature(empyrealFocus[1]))
                                        {
                                            energyCharge->CastSpell(northWest, SPELL_CORE_BEAM, true);
                                            energyCharge->SetTarget(northWest->GetGUID());
                                            energyCharge->GetMotionMaster()->MovePoint(POINT_EMPYEREAN_FOCUS, empyrealFocusPosition[i]);
                                        }

                                        break;
                                    }
                                    case 1:
                                    {
                                        if (Creature* north = pInstance->instance->GetCreature(empyrealFocus[3]))
                                        {
                                            energyCharge->CastSpell(north, SPELL_CORE_BEAM, true);
                                            energyCharge->SetTarget(north->GetGUID());
                                            energyCharge->GetMotionMaster()->MovePoint(POINT_EMPYEREAN_FOCUS, empyrealFocusPosition[i]);
                                        }

                                        break;
                                    }
                                    case 2:
                                    {
                                        if (Creature* northEast = pInstance->instance->GetCreature(empyrealFocus[5]))
                                        {
                                            energyCharge->CastSpell(northEast, SPELL_CORE_BEAM, true);
                                            energyCharge->SetTarget(northEast->GetGUID());
                                            energyCharge->GetMotionMaster()->MovePoint(POINT_EMPYEREAN_FOCUS, empyrealFocusPosition[i]);
                                        }

                                        break;
                                    }
                                    case 3:
                                    {
                                        if (Creature* southEast = pInstance->instance->GetCreature(empyrealFocus[4]))
                                        {
                                            energyCharge->CastSpell(southEast, SPELL_CORE_BEAM, true);
                                            energyCharge->SetTarget(southEast->GetGUID());
                                            energyCharge->GetMotionMaster()->MovePoint(POINT_EMPYEREAN_FOCUS, empyrealFocusPosition[i]);
                                        }

                                        break;
                                    }
                                    case 4:
                                    {
                                        if (Creature* south = pInstance->instance->GetCreature(empyrealFocus[2]))
                                        {
                                            energyCharge->CastSpell(south, SPELL_CORE_BEAM, true);
                                            energyCharge->SetTarget(south->GetGUID());
                                            energyCharge->GetMotionMaster()->MovePoint(POINT_EMPYEREAN_FOCUS, empyrealFocusPosition[i]);
                                        }

                                        break;
                                    }
                                    case 5:
                                    {
                                        if (Creature* southWest = pInstance->instance->GetCreature(empyrealFocus[0]))
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
                    case ACTION_WIPE:
                    {
                        // Events & summons
                        events.Reset();
                        summons.DespawnAll();

                        // Areatriggers, auras, reset full life, and passive
                        me->RemoveAllAreaTriggers();
                        me->RemoveAllAuras();
                        me->SetFullHealth();
                        me->SetReactState(REACT_PASSIVE);

                        if (pInstance)
                        {
                            // Encounter failed
                            pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                            pInstance->SetBossState(DATA_ELEGON, FAIL);

                            // Remove auras on players
                            pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TOUCH_OF_THE_TITANS);
                            pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TOUCH_OF_TITANS_VISUAL);
                            pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ELEGON_OVERCHARGED);
                            pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ELEGON_OVERCHARGED_2);
                            pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_CLOSED_CIRCUIT);
                        }
                        // Set invisible and unselectable
                        me->SetDisplayId(11686);
                        me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_IMMUNE_TO_PC|UNIT_FLAG_UNK_15));

                        me->RemoveAurasDueToSpell(SPELL_UNSTABLE_ENERGY);
                        me->RemoveAurasDueToSpell(SPELL_PHASE_SHIFTED);
                        me->RemoveAurasDueToSpell(SPELL_OVERLOADED);
                        me->RemoveAurasDueToSpell(SPELL_RADIATING_ENERGIES_VISUAL);

                        // Reset vars
                        phase                     = PHASE_1;
                        phase2WaveCount           = 0;
                        successfulDrawingPower    = 0;
                        energyChargeCounter       = 0;
                        empyrealFocusKilled       = 0;

                        // Reset Empyreal focuses
                        for (int i = 0; i < 6; i++)
                        {
                            if (Unit* focus = ObjectAccessor::GetUnit(*me, empyrealFocus[i]))
                                if (focus->GetAI())
                                    focus->GetAI()->DoAction(ACTION_RESET_EMPYREAL_FOCUS);
                        }

                        // Reset Game objects
                        if (GameObject* titanDisk = pInstance->GetGameObject(GOB_ENERGY_TITAN_DISK))
                            titanDisk->SetGoState(GO_STATE_ACTIVE);

                        if (GameObject* energyPlatform = pInstance->GetGameObject(GOB_ENERGY_PLATFORM))
                            energyPlatform->SetGoState(GO_STATE_ACTIVE);

                        if (GameObject* titanCircle = GetClosestGameObjectWithEntry(me, GOB_ENERGY_TITAN_CIRCLE_1, 100.0f))
                            titanCircle->SetGoState(GO_STATE_ACTIVE);

                        if (GameObject* titanCircle = GetClosestGameObjectWithEntry(me, GOB_ENERGY_TITAN_CIRCLE_2, 100.0f))
                            titanCircle->SetGoState(GO_STATE_ACTIVE);

                        if (GameObject* titanCircle = GetClosestGameObjectWithEntry(me, GOB_ENERGY_TITAN_CIRCLE_3, 100.0f))
                            titanCircle->SetGoState(GO_STATE_ACTIVE);

                        for (uint32 entry = GOB_MOGU_RUNE_FIRST; entry < GOB_MOGU_RUNE_END + 1; entry++)
                            if (GameObject* moguRune = GetClosestGameObjectWithEntry(me, entry, 200.0f))
                                moguRune->SetGoState(GO_STATE_ACTIVE);

                        // Reset Cho
                        if (pInstance)
                            if (Creature* Cho = GetClosestCreatureWithEntry(me, NPC_LOREWALKER_CHO, 300.0f))
                                Cho->Respawn(true);

                        break;
                    }
                    default:
                        break;
                }
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);

                if (summon->GetEntry() == NPC_ENERGY_CHARGE)
                    energyChargeCounter++;
            }

            void SummonedCreatureDespawn(Creature* summon) override
            {
                summons.Despawn(summon);

                if (summon->GetEntry() == NPC_ENERGY_CHARGE && energyChargeCounter > 0)
                    energyChargeCounter--;
            }

            void KilledUnit(Unit* who) override
            {
                if (who->IsPlayer())
                    Talk(TALK_SLAY);
            }

            void SpellHit(Unit* caster, const SpellInfo* spell) override
            {
                if (me->GetDistance(caster) > 38.5f)
                    caster->SendSpellMiss(me, spell->Id, SPELL_MISS_MISS);
            }

            void DamageTaken(Unit* /*p_Attacker*/, uint32& damage) override
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

            void JustDied(Unit* /*p_Killer*/) override
            {
                if (pInstance)
                    pInstance->SetBossState(DATA_ELEGON, DONE);

                _JustDied();

                if (Creature* cho = GetClosestCreatureWithEntry(me, NPC_LOREWALKER_CHO, 200.0f, true))
                {
                    cho->AI()->Talk(28);
                    cho->AI()->DoAction(ACTION_CONTINUE_ESCORT);
                }

                if (pInstance)
                {
                    pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TOUCH_OF_THE_TITANS);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TOUCH_OF_TITANS_VISUAL);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ELEGON_OVERCHARGED);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ELEGON_OVERCHARGED_2);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_CLOSED_CIRCUIT);

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

                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MoveLand(2, middlePos);

                me->RemoveAurasDueToSpell(SPELL_RADIATING_ENERGIES_VISUAL);
                me->RemoveAurasDueToSpell(SPELL_ELEGON_OVERCHARGED);
                me->RemoveAurasDueToSpell(SPELL_TOUCH_OF_THE_TITANS);
                Talk(TALK_DEATH);

                if (Creature* infiniteEnergy = pInstance->GetCreature(NPC_INFINITE_ENERGY))
                    infiniteEnergy->AI()->DoAction(ACTION_INFINITE_LOOT);

                if (GameObject* door = pInstance->GetGameObject(GOB_ELEGON_DOOR_ENTRANCE))
                    if (door->GetGoState() == GO_STATE_READY)
                        door->SetGoState(GO_STATE_ACTIVE);

                Map::PlayerList const& l_PlrList = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator l_Itr = l_PlrList.begin(); l_Itr != l_PlrList.end(); ++l_Itr)
                {
                    if (Player* l_Player = l_Itr->GetSource())
                        me->CastSpell(l_Player, SPELL_ELEGON_BONUS, true);
                }

                /*if (IsLFR())
                {
                    Player* l_Player = l_PlrList.begin()->GetSource();
                    if (l_Player && l_Player->GetGroup())
                        sLFGMgr->AutomaticLootAssignation(me, l_Player->GetGroup());
                }*/
            }

            void MoveInLineOfSight(Unit* who) override
            {
                if (!who || who->GetTypeId() != TYPEID_PLAYER)
                    return;

                if (who->HasAura(SPELL_TOUCH_OF_THE_TITANS) || who->HasAura(SPELL_TOUCH_OF_TITANS_VISUAL) || who->HasAura(SPELL_ELEGON_OVERCHARGED))
                    return;
            }

            void UpdateAI(const uint32 diff) override
            {
                if (pInstance)
                {
                    if (pInstance->IsWipe())
                    {
                        DoAction(ACTION_WIPE);
                        return;
                    }
                }

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

                        if (!me->IsWithinMeleeRange(me->GetVictim()))
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
                                if (GameObject* energyPlatform = pInstance->GetGameObject(GOB_ENERGY_PLATFORM))
                                    energyPlatform->SetGoState(GO_STATE_ACTIVE);

                                if (GameObject* titanCircle = GetClosestGameObjectWithEntry(me, GOB_ENERGY_TITAN_CIRCLE_1, 100.0f))
                                    titanCircle->SetGoState(GO_STATE_ACTIVE);

                                if (GameObject* titanCircle = GetClosestGameObjectWithEntry(me, GOB_ENERGY_TITAN_CIRCLE_2, 100.0f))
                                    titanCircle->SetGoState(GO_STATE_ACTIVE);

                                if (GameObject* titanCircle = GetClosestGameObjectWithEntry(me, GOB_ENERGY_TITAN_CIRCLE_3, 100.0f))
                                    titanCircle->SetGoState(GO_STATE_ACTIVE);

                                for (uint32 entry = GOB_MOGU_RUNE_FIRST; entry < GOB_MOGU_RUNE_END + 1; entry++)
                                    if (GameObject* moguRune = GetClosestGameObjectWithEntry(me, entry, 200.0f))
                                        moguRune->SetGoState(GO_STATE_ACTIVE);
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
                                if (GameObject* energyPlatform = pInstance->GetGameObject(GOB_ENERGY_PLATFORM))
                                    energyPlatform->SetGoState(GO_STATE_READY);

                                if (GameObject* titanCircle = GetClosestGameObjectWithEntry(me, GOB_ENERGY_TITAN_CIRCLE_1, 100.0f))
                                    titanCircle->SetGoState(GO_STATE_READY);

                                if (GameObject* titanCircle = GetClosestGameObjectWithEntry(me, GOB_ENERGY_TITAN_CIRCLE_2, 100.0f))
                                    titanCircle->SetGoState(GO_STATE_READY);

                                if (GameObject* titanCircle = GetClosestGameObjectWithEntry(me, GOB_ENERGY_TITAN_CIRCLE_3, 100.0f))
                                    titanCircle->SetGoState(GO_STATE_READY);

                                for (uint32 entry = GOB_MOGU_RUNE_FIRST; entry < GOB_MOGU_RUNE_END + 1; ++entry)
                                    if (GameObject* moguRune = GetClosestGameObjectWithEntry(me, entry, 200.0f))
                                        moguRune->SetGoState(GO_STATE_READY);
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

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_elegonAI(creature);
        }
};

// Empyreal Focus - 60776
class mob_empyreal_focus : public CreatureScript
{
    public:
        mob_empyreal_focus() : CreatureScript("mob_empyreal_focus") { }

        CreatureAI* GetAI(Creature* creature) const override
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

            void Reset() override
            {
                events.Reset();

                activationDone = false;

                me->SetReactState(REACT_PASSIVE);
                me->AddAura(SPELL_FOCUS_INACTIVE, me);
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));

                Position pos = me->GetPosition();

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
                                empyrealFocus[1] = me->GetGUID();
                                break;
                            case 1:
                                empyrealFocus[3] = me->GetGUID();
                                break;
                            case 2:
                                empyrealFocus[5] = me->GetGUID();
                                break;
                            case 3:
                                empyrealFocus[4] = me->GetGUID();
                                break;
                            case 4:
                                empyrealFocus[2] = me->GetGUID();
                                break;
                            case 5:
                                empyrealFocus[0] = me->GetGUID();
                                break;
                        }

                        break;
                    }
                }
            }

            void DoAction(const int32 action) override
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
                            if (Creature* elegon = pInstance->GetCreature(NPC_ELEGON))
                                elegon->AI()->DoAction(ACTION_DESPAWN_ENERGY_CHARGES);

                        activationDone = true;

                        for (int i = 0; i < 6; i++)
                        {
                            if (Unit* focus = ObjectAccessor::GetUnit(*me, empyrealFocus[i]))
                                if (focus->GetAI())
                                    focus->GetAI()->DoAction(ACTION_ACTIVATE_EMPYREAL_FOCUS);
                        }

                        break;
                    }
                    case ACTION_RESET_EMPYREAL_FOCUS:
                    {
                        me->RemoveAurasDueToSpell(SPELL_FOCUS_ACTIVATE_STATE);
                        me->RemoveAurasDueToSpell(SPELL_FOCUS_LIGHT_WALL_VISUAL);
                        me->RemoveAurasDueToSpell(SPELL_FOCUS_LIGHT_CASTBAR);

                        me->SetHealth(me->GetMaxHealth());

                        if (AreaTrigger* lightningWall = me->GetAreaTrigger(SPELL_FOCUS_LIGHT_AREATRIGGER))
                            lightningWall->SetDuration(0);

                        me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                        activationDone = false;
                        break;
                    }
                    default:
                        break;
                }
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (me->GetHealth() < damage)
                {
                    damage = 0;

                    activationDone = false;
                    me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                    me->RemoveAurasDueToSpell(SPELL_FOCUS_ACTIVATE_STATE);
                    me->RemoveAurasDueToSpell(SPELL_FOCUS_LIGHT_WALL_VISUAL);
                    me->RemoveAurasDueToSpell(SPELL_FOCUS_LIGHT_CASTBAR);

                    me->SetHealth(me->GetMaxHealth());

                    if (AreaTrigger* lightningWall = me->GetAreaTrigger(SPELL_FOCUS_LIGHT_AREATRIGGER))
                        lightningWall->SetDuration(0);

                    if (pInstance)
                    {
                        if (Creature* elegon = pInstance->GetCreature(NPC_ELEGON))
                        {
                            me->CastSpell(elegon, SPELL_OVERLOADED_MISSILE, false);
                            elegon->AI()->DoAction(ACTION_EMPYREAL_FOCUS_KILLED);
                        }
                    }
                }
            }

            void UpdateAI(const uint32 diff) override
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
                        me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
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

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_celestial_protectorAI(creature);
        }

        struct mob_celestial_protectorAI : public ScriptedAI
        {
            mob_celestial_protectorAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            EventMap events;
            bool stabilityFluxCasted;
            bool totalAnnihilationCasted;
            InstanceScript* pInstance;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_ARCING_ENERGY, 10000);
                events.ScheduleEvent(EVENT_CHECK_UNIT_ON_PLATFORM, 1000);

                stabilityFluxCasted     = false;
                totalAnnihilationCasted = false;

                if (Player* player = me->SelectNearestPlayer())
                    AttackStart(player);
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
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
                        if (pInstance->instance->IsHeroic())
                            me->CastSpell(me, SPELL_DESTABILIZING_ENERGIES, false);
                        totalAnnihilationCasted = true;
                        events.ScheduleEvent(EVENT_KILLED , 4500);
                    }
                }
            }

            void UpdateAI(const uint32 diff) override
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

        CreatureAI* GetAI(Creature* creature) const override
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

            void Reset() override
            {
                events.Reset();

                if (Unit* player = SelectTarget(SELECT_TARGET_NEAREST))
                    AttackStart(player);

                events.ScheduleEvent(EVENT_CHECK_UNIT_ON_PLATFORM, 1000);
                events.ScheduleEvent(EVENT_ICE_TRAP, 10000);
                events.ScheduleEvent(EVENT_COSMICSPARK_ATTACK, 1000);
            }

            void UpdateAI(const uint32 diff) override
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CHECK_UNIT_ON_PLATFORM:
                        {
                            if (me->GetDistance(middlePos) <= 38.5f)
                                me->CastSpell(me, SPELL_TOUCH_OF_THE_TITANS, true);
                            else
                                me->RemoveAurasDueToSpell(SPELL_TOUCH_OF_THE_TITANS);
                            events.ScheduleEvent(EVENT_CHECK_UNIT_ON_PLATFORM, 1000);
                            break;
                        }
                        case EVENT_ICE_TRAP:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_ICE_TRAP, false);
                            events.ScheduleEvent(EVENT_ICE_TRAP,      60000);
                            break;
                        }
                        case EVENT_COSMICSPARK_ATTACK:
                        {
                            if (!me->GetVictim() || !me->GetVictim()->IsAlive())
                            {
                                std::list<Player*> playerList;
                                GetPlayerListInGrid(playerList, me, 200.0f);

                                Player* target;
                                bool selected = false;

                                if (!playerList.empty())
                                {
                                    std::list<Player*>::iterator itr;
                                    itr = playerList.begin();

                                    do
                                    {
                                        if (urand(0, 1))
                                        {
                                            target = *itr;
                                            selected = true;
                                        }

                                        ++itr;
                                        if (itr == playerList.end())
                                            itr = playerList.begin();

                                    } while (!selected);
                                }
                                else
                                    break;

                                AttackStart(target);
                            }
                            events.ScheduleEvent(EVENT_COSMICSPARK_ATTACK, 1000);
                            break;
                        }
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
    ACTION_ENERGIZE_EMPYREAL_FOCUS  = 1
};

// Energy Charge - 60913
class mob_energy_charge : public CreatureScript
{
    public:
        mob_energy_charge() : CreatureScript("mob_energy_charge") { }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_energy_chargeAI(creature);
        }

        struct mob_energy_chargeAI : public ScriptedAI
        {
            mob_energy_chargeAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset() override
            {
                me->SetReactState(REACT_PASSIVE);
                me->AddAura(SPELL_CORE_CHECKER, me);
            }

            void JustDied(Unit* /*p_Killer*/) override
            {
                me->CastSpell(me, SPELL_DISCHARGE, true);
            }

            void MovementInform(uint32 /*type*/, uint32 id) override
            {
                switch (id)
                {
                    case POINT_EMPYEREAN_FOCUS:
                    {
                        if (Unit* focus = ObjectAccessor::GetUnit(*me, me->GetTarget()))
                        {
                            Position pos = focus->GetPosition();

                            me->GetMotionMaster()->MovePoint(POINT_EMPYEREAN_FOCUS, pos);
                        }

                        break;
                    }
                    default:
                        break;
                }
            }

            void DoAction(const int32 action) override
            {
                switch (action)
                {
                    case ACTION_ENERGIZE_EMPYREAL_FOCUS:
                    {
                        if (Unit* focus = ObjectAccessor::GetUnit(*me, me->GetTarget()))
                        {
                            if (focus->GetAI())
                                focus->GetAI()->DoAction(ACTION_ACTIVATE_EMPYREAL_FOCUS);
                        }

                        me->RemoveAurasDueToSpell(SPELL_CORE_CHECKER);
                        me->DespawnOrUnsummon();

                        break;
                    }
                    default:
                        break;
                }
            }
        };
};

enum infiniteEvents
{
    EVENT_ACTIVATION_WEST   = 1,
    EVENT_ACTIVATION        = 2,
    EVENT_ACTIVATION_EAST   = 3,
    EVENT_FLASH_SPAWN       = 4,
    EVENT_BOSS_ACTIVATION   = 5,
    EVENT_BOSS_INTRO_2      = 6,
    EVENT_CHECK_AURAS       = 7
};

// Infinite Energy - 65293
class mob_infinite_energy : public CreatureScript
{
    public:
        mob_infinite_energy() : CreatureScript("mob_infinite_energy"){ }

        CreatureAI* GetAI(Creature* creature) const override
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

            void Reset() override
            {
                events.Reset();
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE));
            }

            void DoAction(const int32 action) override
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
                            Creature* southWest = pInstance->instance->GetCreature(empyrealFocus[0]);
                            Creature* northWest = pInstance->instance->GetCreature(empyrealFocus[1]);

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
                            Creature* south = pInstance->instance->GetCreature(empyrealFocus[2]);
                            Creature* north = pInstance->instance->GetCreature(empyrealFocus[3]);

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
                            Creature* southEast = pInstance->instance->GetCreature(empyrealFocus[4]);
                            Creature* northEast = pInstance->instance->GetCreature(empyrealFocus[5]);

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
                            if (GameObject* energyPlatform = pInstance->GetGameObject(GOB_ENERGY_PLATFORM))
                                energyPlatform->SetGoState(GO_STATE_READY);

                            if (GameObject* titanCircle = GetClosestGameObjectWithEntry(me, GOB_ENERGY_TITAN_CIRCLE_1, 100.0f))
                                titanCircle->SetGoState(GO_STATE_READY);

                            if (GameObject* titanCircle = GetClosestGameObjectWithEntry(me, GOB_ENERGY_TITAN_CIRCLE_2, 100.0f))
                                titanCircle->SetGoState(GO_STATE_READY);

                            if (GameObject* titanCircle = GetClosestGameObjectWithEntry(me, GOB_ENERGY_TITAN_CIRCLE_3, 100.0f))
                                titanCircle->SetGoState(GO_STATE_READY);

                            for (uint32 entry = GOB_MOGU_RUNE_FIRST; entry < GOB_MOGU_RUNE_END + 1; ++entry)
                                if (GameObject* moguRune = GetClosestGameObjectWithEntry(me, entry, 200.0f))
                                    moguRune->SetGoState(GO_STATE_READY);

                            events.ScheduleEvent(EVENT_CHECK_AURAS, 500);
                        }
                        break;
                    }
                    case ACTION_INFINITE_SPAWN_BOSS:
                    {
                        if (pInstance)
                        {
                            if (Creature* elegon = pInstance->GetCreature(NPC_ELEGON))
                            {
                                elegon->RestoreDisplayId();
                                elegon->AI()->Talk(TALK_INTRO);
                                events.ScheduleEvent(EVENT_BOSS_INTRO_2,    5000);
                                events.ScheduleEvent(EVENT_BOSS_ACTIVATION, 8000);
                            }
                        }
                        break;
                    }
                    case ACTION_INFINITE_LOOT:
                    {
                        if (IsLFR())
                            break;

                        // Loots chest
                        if (IsHeroic())
                            me->SummonGameObject(GOB_ELEGON_CHEST_HEROIC, middlePos.GetPositionX(), middlePos.GetPositionY(), middlePos.GetPositionZ(), 0.0f, QuaternionData(), 0);
                        else
                            me->SummonGameObject(GOB_ELEGON_CHEST, middlePos.GetPositionX(), middlePos.GetPositionY(), middlePos.GetPositionZ(), 0.0f, QuaternionData(), 0);
                        break;
                    }
                    default:
                        break;
                }
            }

            void UpdateAI(const uint32 diff) override
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
                            if (Creature* elegon = pInstance->GetCreature(NPC_ELEGON))
                                elegon->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_IMMUNE_TO_PC|UNIT_FLAG_UNK_15));
                        break;
                    }
                    case EVENT_BOSS_INTRO_2:
                    {
                        if (pInstance)
                            if (Creature* elegon = pInstance->GetCreature(NPC_ELEGON))
                                elegon->AI()->Talk(TALK_INTRO_2);
                        break;
                    }
                    case EVENT_CHECK_AURAS:
                    {
                        std::list<Player*> playerList;
                        GetPlayerListInGrid(playerList, me, 60.0f);

                        for (auto player : playerList)
                        {
                            // Removing auras if player outside of vortex
                            if ((player->HasAura(SPELL_ELEGON_OVERCHARGED_2) || player->HasAura(SPELL_TOUCH_OF_THE_TITANS)) && me->GetDistance(player) > 38.5f)
                            {
                                player->RemoveAura(SPELL_ELEGON_OVERCHARGED_2);
                                player->RemoveAura(SPELL_TOUCH_OF_THE_TITANS);
                            }
                            // Applying auras if player on vortex
                            else if (me->GetDistance(player) <= 38.5f)
                            {
                                if (!player->HasAura(SPELL_ELEGON_OVERCHARGED))
                                    me->AddAura(SPELL_ELEGON_OVERCHARGED, player);

                                if (!player->HasAura(SPELL_TOUCH_OF_THE_TITANS))
                                {
                                    me->AddAura(SPELL_TOUCH_OF_TITANS_VISUAL, player);
                                    me->AddAura(SPELL_TOUCH_OF_THE_TITANS, player);
                                }
                            }
                        }

                        events.ScheduleEvent(EVENT_CHECK_AURAS, 500);
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

        void OnGameObjectStateChanged(GameObject* go, uint32 /*state*/) override
        {
            std::list<Player*> playerList;
            go->GetPlayerListInGrid(playerList, 10.0f);

            if (!playerList.empty())
            {
                for (auto player: playerList)
                {
                    if (InstanceScript* pInstance = player->GetInstanceScript())
                    {
                        if (Creature* infiniteEnergy = pInstance->GetCreature(NPC_INFINITE_ENERGY))
                            infiniteEnergy->AI()->DoAction(ACTION_INFINITE_GO_DOWN);

                        if (GameObject* titanDisk = pInstance->GetGameObject(GOB_ENERGY_TITAN_DISK))
                            titanDisk->SetGoState(GO_STATE_READY);

                        return;
                    }
                }
            }
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

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_spawn_flash_1_periodic_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
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

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_spawn_flash_2_periodic_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
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

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_spawn_flash_3_periodic_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
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

            void OnTick(AuraEffect const* /*p_AurEff*/)
            {
                if (!GetTarget())
                    return;

                if (Player* player = GetTarget()->ToPlayer())
                {
                    if (player->GetDistance(middlePos) > 38.5f)
                    {
                        player->RemoveAurasDueToSpell(SPELL_TOUCH_OF_THE_TITANS);
                        player->RemoveAurasDueToSpell(SPELL_TOUCH_OF_TITANS_VISUAL);
                        player->RemoveAurasDueToSpell(SPELL_ELEGON_OVERCHARGED);
                        player->RemoveAurasDueToSpell(SPELL_ELEGON_OVERCHARGED_2);
                    }
                }
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* target = GetTarget())
                {
                    target->RemoveAurasDueToSpell(SPELL_TOUCH_OF_THE_TITANS);
                    target->RemoveAurasDueToSpell(SPELL_TOUCH_OF_TITANS_VISUAL);
                    target->RemoveAurasDueToSpell(SPELL_ELEGON_OVERCHARGED);
                    target->RemoveAurasDueToSpell(SPELL_ELEGON_OVERCHARGED_2);
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_touch_of_titans_AuraScript::OnTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
                OnEffectRemove += AuraEffectRemoveFn(spell_touch_of_titans_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
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

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_radiating_energies_SpellScript::CorrectRange, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const override
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

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_draw_power_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
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

            void OnTick(AuraEffect const* /*p_AurEff*/)
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

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_core_checker_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
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
                        SpellInfo const* m_spellInfo = sSpellMgr->GetSpellInfo(SPELL_GRASPING_ENERGY_GRIP, DIFFICULTY_NONE);
                        if (!m_spellInfo)
                            return;

                        // Init dest coordinates
                        float x, y, z;
                        elegon->GetPosition(x, y, z);

                        float dist = target->GetExactDist2d(x, y);

                        float speedZ, speedXY;
                        if (m_spellInfo->GetEffect(0)->MiscValue)
                            speedZ = float(m_spellInfo->GetEffect(0)->MiscValue)/10;
                        else if (m_spellInfo->GetEffect(0)->MiscValueB)
                            speedZ = float(m_spellInfo->GetEffect(0)->MiscValueB)/10;
                        else
                            speedZ = 10.0f;

                        speedXY = dist * 10.0f / speedZ;

                        target->GetMotionMaster()->MoveJump(Position(x, y, z), speedXY, speedZ);
                    }
                }
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_grasping_energy_tendrils_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_grasping_energy_tendrils_SpellScript();
        }
};

// Destabilizing Energies - 132222
class spell_destabilizing_energies : public SpellScriptLoader
{
    public:
        spell_destabilizing_energies() : SpellScriptLoader("spell_destabilizing_energies") { }

        class spell_destabilizing_energies_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_destabilizing_energies_AuraScript);

            void Apply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                {
                    std::list<Player*> targetList;
                    GetPlayerListInGrid(targetList, caster, 200.0f);
                    for (auto target : targetList)
                        caster->AddAura(SPELL_DESTABILIZING_ENERGIES, target);
                }
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_destabilizing_energies_AuraScript::Apply, EFFECT_2, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_destabilizing_energies_AuraScript();
        }
};

// Total Annihilation - 127911
class spell_total_annihilation : public SpellScriptLoader
{
    public:
        spell_total_annihilation() : SpellScriptLoader("spell_total_annihilation") { }

        class spell_total_annihilation_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_total_annihilation_SpellScript);

            uint32 targetCount;

            bool Load() override
            {
                targetCount = 1;
                return true;
            }

            void CheckTargets()
            {
                if (Unit* caster = GetCaster())
                {
                    if (!caster->GetInstanceScript()->instance->IsHeroic())
                        return;

                    uint8 diffic = caster->GetMap()->GetDifficultyID();

                    if ((!targetCount &&  diffic == DIFFICULTY_10_N) || (targetCount < 3 && diffic == DIFFICULTY_25_N))
                        caster->CastSpell(caster, SPELL_CATASTROPHIC_ANOMALY, false);
                }
            }

            void Register() override
            {
                AfterCast += SpellCastFn(spell_total_annihilation_SpellScript::CheckTargets);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_total_annihilation_SpellScript();
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

            void OnTick(AuraEffect const* /*p_AurEff*/)
            {
                if (Unit* elegon = GetTarget())
                    elegon->CastSpell(elegon, SPELL_UNSTABLE_ENERGY_DAMAGE, true);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_unstable_energy_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_unstable_energy_AuraScript();
        }
};

/// Created by spell 116546
class at_draw_power : public AreaTriggerAI
{
public:
    at_draw_power(AreaTrigger* areaTrigger) : AreaTriggerAI(areaTrigger) { }

    void OnUpdate(uint32 /*p_Time*/) override
    {
        std::list<Unit*> l_TargetList;
        float l_Radius = 30.0f;
        Unit* l_Caster = at->GetCaster();

        if (!l_Caster)
            return;

        l_Caster->GetAttackableUnitListInRange(l_TargetList, l_Radius);

        for (Unit* l_Unit : l_TargetList)
        {
            if (l_Unit->IsInAxe(l_Caster, at, 2.0f))
            {
                if (l_Unit->HasAura(SPELL_ENERGY_CONDUIT))
                    l_Caster->AddAura(SPELL_ENERGY_CONDUIT, l_Unit);
            }
            else
                l_Unit->RemoveAurasDueToSpell(SPELL_ENERGY_CONDUIT);
        }
    }
};

void AddSC_boss_elegon()
{
    new boss_elegon();                      ///< 60410
    new mob_empyreal_focus();               ///< 60776
    new mob_celestial_protector();          ///< 60793
    new mob_cosmic_spark();                 ///< 62618
    new mob_energy_charge();                ///< 60913
    new mob_infinite_energy();              ///< 65293
    new go_celestial_control_console();     ///< 211650
    new spell_spawn_flash_1_periodic();     ///< 127785
    new spell_spawn_flash_2_periodic();     ///< 127783
    new spell_spawn_flash_3_periodic();     ///< 127781
    new spell_touch_of_titans();            ///< 117874
    new spell_radiating_energies();         ///< 118313 - 122741
    new spell_draw_power();                 ///< 119360 - 124967
    new spell_core_checker();               ///< 118024
    new spell_grasping_energy_tendrils();   ///< 127362
    new spell_destabilizing_energies();     ///< 132222
    new spell_total_annihilation();         ///< 127911
    new spell_unstable_energy();            ///< 116994
    RegisterAreaTriggerAI(at_draw_power);                    ///< 116546
}
