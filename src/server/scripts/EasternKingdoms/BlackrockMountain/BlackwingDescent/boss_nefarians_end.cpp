/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "CommonPredicates.h"
#include "GameObjectAI.h"
#include "GossipDef.h"
#include "GridNotifiers.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "PassiveAI.h"
#include "PhasingHandler.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "Transport.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "TemporarySummon.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "blackwing_descent.h"

enum Spells
{
    // Nefarian
    SPELL_INTRO_2_STALKER_TRANSFORM                     = 78750,
    SPELL_INTRO_3_SHRINK_AURA                           = 78753,
    SPELL_INTRO_4_LIFT_OFF_ANIM_KIT                     = 78692,
    SPELL_INTRO_5A_START_FIGHT_PROC                     = 78730,
    SPELL_ELECTRICAL_CHARGE_NEFARIAN                    = 95793,
    SPELL_SHADOW_OF_COWARDICE                           = 79355,
    SPELL_CHILDREN_OF_DEATHWING_NEFARIAN                = 80787,
    SPELL_HAIL_OF_BONES                                 = 78679,
    SPELL_NEFARIAN_PHASE_2_HEALTH_AURA                  = 81582,
    SPELL_SHADOWFLAME_BARRAGE                           = 78621,
    SPELL_BRUSHFIRE_PRE_START_PERIODIC                  = 94630,
    SPELL_BRUSHFIRE_START                               = 79813,
    SPELL_DOMINION_DUMMY                                = 94211,
    SPELL_DOMINION_OVERRIDE_ACTION_BAR                  = 79318,
    SPELL_EXPLOSIVE_CINDERS                             = 79339,
    SPELL_EXPLOSIVE_CINDERS_EXPLOSION                   = 79347,
    SPELL_BERSERK                                       = 26662,

    // Onyxia
    SPELL_PERMANENT_FEIGN_DEATH_1                       = 29266,
    SPELL_ONYXIA_START_FIGHT_1_PERIODIC                 = 81516,
    SPELL_ELECTRICAL_CHARGE_ONYXIA                      = 78949,
    SPELL_ELECTRICAL_OVERLOAD                           = 78999,
    SPELL_LIGHTNING_DISCHARGE                           = 78090,
    SPELL_LIGHTNING_DISCHARGE_VISUAL_LEFT_1             = 81435,
    SPELL_LIGHTNING_DISCHARGE_VISUAL_LEFT_2             = 81436,
    SPELL_LIGHTNING_DISCHARGE_VISUAL_RIGHT_1            = 81437,
    SPELL_LIGHTNING_DISCHARGE_VISUAL_RIGHT_2            = 81438,
    SPELL_LIGHTNING_DISCHARGE_CONE_BACK                 = 77833,
    SPELL_LIGHTNING_DISCHARGE_CONE_FRONT                = 77836,
    SPELL_LIGHTNING_DISCHARGE_DAMAGE                    = 77943,
    SPELL_CHILDREN_OF_DEATHWING_ONYXIA                  = 80785,

    // Nefarian and Onyxia
    SPELL_TAIL_LASH                                     = 77827,
    SPELL_SHADOWFLAME_BREATH                            = 77826,
    SPELL_SHADOW_OF_COWARDICE_DAMAGE                    = 79353,
    SPELL_SHADOW_OF_COWARDICE_DUMMY                     = 80963,

    // Nefarian's Lightning Machine
    SPELL_ELECTROCUTE                                   = 81198,
    SPELL_ELECTROCUTE_DAMAGE                            = 81272,

    // Animated Bone Warrior
    SPELL_FULL_POWER_NO_REGEN                           = 78120,
    SPELL_ANIMATE_BONES                                 = 78122,
    SPELL_PERMANENT_FEIGN_DEATH_2                       = 70628,
    SPELL_CLEAR_ALL_DEBUFFS                             = 34098,
    SPELL_EMPOWER                                       = 79330,

    // Chromatic Prototype
    SPELL_JUMP_DOWN_TO_PLATFORM                         = 79205,
    SPELL_READY_UNARMED                                 = 94610,
    SPELL_DUMMY_NUKE                                    = 80776,
    SPELL_BLAST_NOVA                                    = 80734,

    // Invisible Stalker (Cataclysm Boss, Ignore Combat, Floating)
    SPELL_INTRO_1_TRANSFORM_VISUAL                      = 78205,
    SPELL_CHAINS_A_STEEL                                = 81159,
    SPELL_CHAINS_B_STEEL                                = 81174,
    SPELL_CHAINS_C_STEEL                                = 81176,
    SPELL_CHAINS_A_LIGHTNING                            = 81158,
    SPELL_CHAINS_B_LIGHTNING                            = 81175,
    SPELL_CHAINS_C_LIGHTNING                            = 81177,

    // Controller Stalker
    SPELL_PET_HACK_1                                    = 95278, // Todo: we don't need this (yet). This is going to disable pathfinding for pets.

    // Shadowblase Flashpoint / Shadowblaze
    SPELL_BRUSHFIRE_FLASHPOINT_CONTROL                  = 79392,
    SPELL_BRUSHFIRE_GROWTH                              = 79393,
    SPELL_BRUSHFIRE_BURN_AURA                           = 79396,
    SPELL_BRUSHFIRE_SUMMON                              = 79405,
    SPELL_BRUSHFIRE_CHECK_VALID_LOCATION                = 79401,

    // Dominion Stalker
    SPELL_DOMINION_DETERMINE_FARTHEST_PORTAL_STALKER    = 81664,
    SPELL_DOMINION_PORTAL_TRIGGER                       = 81752,
    SPELL_DOMINION_PORTAL_BEAM                          = 81709,

    // Players
    SPELL_DOMINION_IMMUNITY                             = 95900,
    SPELL_SUMMON_DOMINION_STALKER_NORTH                 = 81665,
    SPELL_SUMMON_DOMINION_STALKER_EAST                  = 81745,
    SPELL_SUMMON_DOMINION_STALKER_SOUTH                 = 81746,
    SPELL_SUMMON_DOMINION_STALKER_WEST                  = 81747,
    SPELL_STOLEN_POWER                                  = 80627,
    SPELL_INSTAKILL_SELF                                = 29878
};

static constexpr uint8 const DominionStalkerSpellCount = 4;
uint32 const DominionStalkerSummonSpells[DominionStalkerSpellCount] =
{
    SPELL_SUMMON_DOMINION_STALKER_NORTH,
    SPELL_SUMMON_DOMINION_STALKER_EAST,
    SPELL_SUMMON_DOMINION_STALKER_SOUTH,
    SPELL_SUMMON_DOMINION_STALKER_WEST
};

enum Texts
{
    // Nefarian
    SAY_ANNOUNCE_AIR_CRACKLES   = 0,
    SAY_HAIL_OF_BONES           = 1,
    SAY_ONYXIA_DIED             = 2,
    SAY_MOLTEN_LAVA             = 3,
    SAY_LAND_PHASE_THREE        = 4,
    SAY_SHADOWBLAZE_SPARK       = 5,
    SAY_SLAY                    = 6,
    SAY_DEATH                   = 7,
    SAY_DOMINION                = 8,

    // Onyxia
    SAY_ANNOUNCE_WARNING_1      = 0,
    SAY_ANNOUNCE_WARNING_2      = 1,

    // Lord Victor Nefarius
    SAY_INTRO_1                 = 0,
    SAY_INTRO_2                 = 1,
    SAY_INTRO_3                 = 2
};

enum Events
{
    // Nefarian
    EVENT_CHAIN_ONYXIA = 1,
    EVENT_REMOVE_TRANSFORM_AURA,
    EVENT_LIFT_OFF,
    EVENT_ANNOUNCE_AIR_CRACKLES,
    EVENT_MAKE_ATTACKABLE,
    EVENT_FLY_CYCLIC_PATH,
    EVENT_PREPARE_LANDING,
    EVENT_LAND_PHASE_ONE,
    EVENT_LANDED,
    EVENT_ENGAGE_PLAYERS,
    EVENT_SAY_ONYXIA_DEAD,
    EVENT_MOVE_TO_CENTER,
    EVENT_LIFTOFF_PHASE_TWO,
    EVENT_SUMMON_CHROMATIC_PROTOTYPES,
    EVENT_LOWER_ELEVATOR,
    EVENT_ELEVATOR_LOWERED,
    EVENT_SHADOWFLAME_BARRAGE,
    EVENT_SAY_PHASE_TWO,
    EVENT_ENTER_PHASE_THREE,
    EVENT_SAY_PHASE_THREE,
    EVENT_LAND_PHASE_THREE,
    EVENT_ELECTROCUTE,
    EVENT_DOMINION,
    EVENT_EXPLOSIVE_CINDERS,
    EVENT_BERSERK,

    // Onyxia
    EVENT_LIGHTNING_DISCHARGE,
    EVENT_ELECTRICAL_CHARGE,
    EVENT_SHADOW_OF_CORWARDICE,

    // Nefarian and Onyxia
    EVENT_TAIL_LASH,
    EVENT_SHADOWFLAME_BREATH,

    // Lord Victor Nefarius
    EVENT_TALK_INTRO_2,
    EVENT_TALK_INTRO_3,
    EVENT_CAST_TRANSFORM_VISUAL,
    EVENT_RAISE_ELEVATOR,

    // Chromatic Prototype
    EVENT_JUMP_DOWN_TO_PLATFORM,
    EVENT_READY_PROTOTYPE,
    EVENT_DUMMY_NUKE,
    EVENT_BLAST_NOVA,
    EVENT_DISENGAGE_PLAYERS,
};

enum Phases
{
    PHASE_ONE   = 1,
    PHASE_TWO   = 2,
    PHASE_THREE = 3
};

enum Actions
{
    // Lord Victor Nefarius
    ACTION_START_INTRO              = 1,

    // Nefarian
    ACTION_ONYXIA_ENGAGED           = 1,
    ACTION_ONYXIA_DIED              = 2,

    // Onyxia
    ACTION_REANIMATED               = 1,
    ACTION_UPDATE_ELECTRICAL_CHARGE = 2,
    ACTION_NEFARIAN_LANDED          = 3,

    // Chromatic Prototype
    ACTION_DISENGAGE_PLAYERS        = 1,

    // Shadowblaze Flashpoint / Shadowblaze
    ACTION_DESPAWN_FLAMES           = 1,
    ACTION_SPREAD_FLAMES            = 2
};

enum TransportStopFrames
{
    TRANSPORT_STOP_FRAME_LOWERED    = 0,
    TRANSPORT_STOP_FRAME_RAISED     = 1
};

enum SummonGroups
{
    SUMMON_GROUP_ELEVATOR           = 0,
    SUMMON_GROUP_CONTROLLER_STALKER = 1
};

enum MovePoints
{
    // Nefarian
    POINT_NONE              = 0,
    POINT_LIFTOFF           = 1,
    POINT_PREPARE_LANDING   = 2,
    POINT_LAND              = 3,
    POINT_ELEVATOR_CENTER   = 4,

    // Chromatic Prototype
    POINT_JUMP_DOWN         = 1
};

enum EncounterFrames
{
    FRAME_INDEX_CHROMATIC_PROTOTYPE = 1,
    FRAME_INDEX_ONYXIA              = 2,
    FRAME_INDEX_NEFARIAN            = 3
};

struct OnyxiaChainData
{
    Position ComparisonPosition;
    uint32 ChainSpellId;
    uint32 LightningSpellId;
};

static OnyxiaChainData OnyxiaChainInfo[] =
{
    { { -141.3331f, -224.6247f }, SPELL_CHAINS_A_STEEL, SPELL_CHAINS_A_LIGHTNING },
    { { -90.35625f, -253.4714f }, SPELL_CHAINS_B_STEEL, SPELL_CHAINS_B_LIGHTNING },
    { { -90.22045f, -195.6071f }, SPELL_CHAINS_C_STEEL, SPELL_CHAINS_C_LIGHTNING }
};

enum Misc
{
    SOUND_ID_ROAR           = 7274,
    WS_ACHIEVEMENT_CRITERIA = 5652
};

Position const NefarianSummonPosition                           = { -166.655f,    -224.602f,    40.48163f, 0.0f };
Position const NefarianLiftOffPosition                          = { -162.076f,    -224.604f,    57.9262f   };
Position const NefarianElevatorPrepareLandPositionPhaseOne      = { -107.255753f, -223.944778f, 17.38522f  };
Position const NefarianElevatorLandPhaseOnePosition             = { -106.899124f, -225.162415f, 6.488089f  };
Position const NefarianElevatorCenterPosition                   = { -106.209747f, -224.530594f, 6.488089f  };
Position const NefarianElevatorLiftOffPosition                  = { -107.205688f, -224.597412f, 35.630280f };
Position const NefarianElevatorPrepareLandPositionPhaseThree    = { -107.238045f, -224.599579f, 17.629690f };
Position const NefarianElevatorLandPhaseThreePosition           = { -107.238045f, -224.599579f, 6.488089f  };

static constexpr uint32 const CyclicPathPoints = 17;
Position const NefarianCyclicPath[CyclicPathPoints] =
{
    { -162.076f,  -224.604f,  57.9262f  },
    { -169.3941f, -250.8021f, 91.78177f },
    { -154.9757f, -272.2014f, 92.11506f },
    { -132.934f,  -286.8906f, 92.25407f },
    { -106.7951f, -292.2639f, 93.06911f },
    { -81.66319f, -287.3004f, 93.81921f },
    { -59.42708f, -272.5538f, 94.29151f },
    { -44.60417f, -251.0191f, 94.40255f },
    { -39.86979f, -225.0208f, 93.93014f },
    { -44.62847f, -198.8733f, 94.15247f },
    { -59.65799f, -176.8993f, 94.81911f },
    { -81.1875f,  -162.474f,  94.70798f },
    { -107.0816f, -157.3715f, 94.20808f },
    { -132.8073f, -162.3507f, 93.4026f  },
    { -154.6771f, -177.1233f, 92.95815f },
    { -169.151f,  -199.1771f, 92.23587f },
    { -174.6406f, -225.2222f, 92.31927f }
};

static constexpr uint32 const CyclicRespawnPathPoints = 17;
Position const NefarianCyclicRespawnPath[CyclicRespawnPathPoints] =
{
    { -184.1267f, -224.5573f, 97.70717f },
    { -169.3941f, -250.8021f, 91.78177f },
    { -154.9757f, -272.2014f, 92.11506f },
    { -132.934f,  -286.8906f, 92.25407f },
    { -106.7951f, -292.2639f, 93.06911f },
    { -81.66319f, -287.3004f, 93.81921f },
    { -59.42708f, -272.5538f, 94.29151f },
    { -44.60417f, -251.0191f, 94.40255f },
    { -39.86979f, -225.0208f, 93.93014f },
    { -44.62847f, -198.8733f, 94.15247f },
    { -59.65799f, -176.8993f, 94.81911f },
    { -81.1875f,  -162.474f,  94.70798f },
    { -107.0816f, -157.3715f, 94.20808f },
    { -132.8073f, -162.3507f, 93.4026f  },
    { -154.6771f, -177.1233f, 92.95815f },
    { -169.151f,  -199.1771f, 92.23587f },
    { -174.6406f, -225.2222f, 92.31927f }
};

static constexpr uint8 const MaxChromaticPrototypes = 3;
Position const ChromaticPrototypeSummonPositions[MaxChromaticPrototypes]
{
    { -183.972f,  -225.163f,  43.17013f, 0.05235988f },
    { -63.20486f, -135.6719f, 65.17735f, 4.29351f },
    { -62.87326f, -312.467f,  65.01746f, 2.007129f }
};

Position const ChromaticPrototypeMovePositions[MaxChromaticPrototypes]
{
    { -164.7852f, -224.4054f, 40.39833f },
    { -73.10334f, -156.7224f, 65.5925f  },
    { -72.80968f, -292.0725f, 65.65186f }
};

Position const ChromaticPrototypeJumpPositions[MaxChromaticPrototypes]
{
    { 40.50549f, -0.06254366f, 9.92507f },
    { -20.47418f, -34.21686f, 9.925069f },
    { -20.44454f,  34.39596f, 9.925069f }
};

struct boss_nefarians_end : public BossAI
{
    boss_nefarians_end(Creature* creature) : BossAI(creature, DATA_NEFARIANS_END),
        _elevatorLowered(false), _encounterReset(instance->GetData(DATA_NEFARIANS_END_INTRO_DONE)),
        _nextElectrocuteHealthPercentage(90), _deadChromaticPrototypes(0)
    {
        me->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING); // Remove this little workarround when mmaps for transports have arrived.
        me->SetReactState(REACT_PASSIVE);
    }

    void JustEngagedWith(Unit* who) override
    {
        // Attacking Nefarian while Onyxia is not engaged is not suposed to trigger anything
        if (instance->GetBossState(DATA_NEFARIANS_END) != IN_PROGRESS)
        {
            me->GetThreatManager().ClearAllThreat();
            me->CombatStop();
            return;
        }
        BossAI::JustEngagedWith(who);
    }

    void JustAppeared() override
    {
        events.SetPhase(PHASE_ONE);
        if (!_encounterReset)
        {
            events.ScheduleEvent(EVENT_CHAIN_ONYXIA, 1s, 0, PHASE_ONE);
            events.ScheduleEvent(EVENT_REMOVE_TRANSFORM_AURA, 26s + 700ms, 0, PHASE_ONE);
            me->SendSetPlayHoverAnim(false);
            DoCastSelf(SPELL_INTRO_2_STALKER_TRANSFORM);
            DoCastSelf(SPELL_INTRO_3_SHRINK_AURA);
        }
        else
        {
            me->AddUnitMovementFlag(MOVEMENTFLAG_DISABLE_GRAVITY);
            me->SetAnimationTier(AnimationTier::Fly);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE);
            me->GetMotionMaster()->MoveCyclicPath(NefarianCyclicRespawnPath, CyclicRespawnPathPoints, false, true, 14.0f);
            DoCastSelf(SPELL_INTRO_5A_START_FIGHT_PROC);
            SetupTransportSpawns(SUMMON_GROUP_CONTROLLER_STALKER);

        }
        SetupTransportSpawns(SUMMON_GROUP_ELEVATOR);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        if (events.IsInPhase(PHASE_TWO) && !_elevatorLowered)
            instance->SetData(DATA_RESET_ELEVATOR, events.GetTimeUntilEvent(EVENT_ELEVATOR_LOWERED));
        else if (Transport* transport = GetElevator())
            transport->SetTransportState(GO_STATE_TRANSPORT_STOPPED, TRANSPORT_STOP_FRAME_RAISED);

        if (Creature* onyxia = instance->GetCreature(DATA_ONYXIA))
            if (onyxia->IsAlive())
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, onyxia);

        for (ObjectGuid summon : summons)
        {
            if (Creature* creature = instance->instance->GetCreature(summon))
                if (creature->GetEntry() == NPC_CHROMATIC_PROTOTYPE && creature->IsAlive())
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, creature);
        }

        summons.DespawnAll();
        instance->SetData(DATA_NEFARIAN_ACHIEVEMENT_STATE, 1);
        instance->SetBossState(DATA_NEFARIANS_END, FAIL);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_EXPLOSIVE_CINDERS);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DOMINION_OVERRIDE_ACTION_BAR);
        me->DespawnOrUnsummon();
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_EXPLOSIVE_CINDERS);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DOMINION_OVERRIDE_ACTION_BAR);
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);
        // keeping the summon list clean because we have to deal with many tempoary summons
        summons.RemoveNotExisting();

        switch (summon->GetEntry())
        {
            case NPC_DOMINION_STALKER:
                summon->CastSpell(summon, SPELL_DOMINION_DETERMINE_FARTHEST_PORTAL_STALKER);
                break;
            default:
                break;
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
            return;

        switch (id)
        {
            case POINT_LIFTOFF:
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC);
                DoCastSelf(SPELL_INTRO_5A_START_FIGHT_PROC);
                me->GetMotionMaster()->MoveCyclicPath(NefarianCyclicPath, CyclicPathPoints, false, true, 14.0f);

                if (Creature* machine = instance->GetCreature(DATA_NEFARIANS_LIGHTNING_MACHINE))
                    machine->CastSpell(machine, SPELL_ELECTROCUTE);

                if (Creature* onyxia = instance->GetCreature(DATA_ONYXIA))
                    if (onyxia->IsAIEnabled)
                        onyxia->AI()->DoAction(ACTION_REANIMATED);

                SetupTransportSpawns(SUMMON_GROUP_CONTROLLER_STALKER);

                for (ObjectGuid guid : summons)
                {
                    if (Creature* stalker = instance->instance->GetCreature(guid))
                    {
                        if (stalker->GetEntry() == NPC_INVISIBLE_STALKER_CATACLYSM_BOSS)
                        {
                            for (OnyxiaChainData const& data : OnyxiaChainInfo)
                            {
                                if (stalker->GetExactDist2d(data.ComparisonPosition) < 1.0f)
                                {
                                    stalker->InterruptNonMeleeSpells(true);
                                    stalker->CastSpell(stalker, data.LightningSpellId);
                                }
                            }
                        }
                    }
                }
                break;
            case POINT_PREPARE_LANDING:
                if (events.IsInPhase(PHASE_ONE))
                    events.ScheduleEvent(EVENT_LAND_PHASE_ONE, 200ms, 0, PHASE_ONE);
                else if (events.IsInPhase(PHASE_THREE))
                    events.ScheduleEvent(EVENT_LAND_PHASE_THREE, 200ms, 0, PHASE_THREE);
                break;
            case POINT_LAND:
                events.ScheduleEvent(EVENT_LANDED, 400ms);
                break;
            case POINT_ELEVATOR_CENTER:
                events.ScheduleEvent(EVENT_LIFTOFF_PHASE_TWO, 1s, 0, PHASE_TWO);
                break;
            default:
                break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        // Do not allow Nefarian to die before he raised the platform again
        if (damage >= me->GetHealth() && !events.IsInPhase(PHASE_THREE))
            damage = 0;

        if (damage >= me->GetHealth())
            return;

        if (me->HealthBelowPctDamaged(_nextElectrocuteHealthPercentage, damage))
        {
            Talk(SAY_ANNOUNCE_AIR_CRACKLES);
            events.ScheduleEvent(EVENT_ELECTROCUTE, 5s);
            _nextElectrocuteHealthPercentage -= 10;
        }
    }

    void OnSpellCastFinished(SpellInfo const* spell, SpellFinishReason reason) override
    {
        if (reason != SPELL_FINISHED_SUCCESSFUL_CAST)
            return;

        switch (spell->Id)
        {
            case SPELL_BRUSHFIRE_START:
                Talk(SAY_SHADOWBLAZE_SPARK);
                break;
            case SPELL_DOMINION_OVERRIDE_ACTION_BAR:
                Talk(SAY_DOMINION);
                break;
            default:
                break;
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_ONYXIA_ENGAGED:
                Talk(SAY_HAIL_OF_BONES);
                DoCastSelf(SPELL_ELECTRICAL_CHARGE_NEFARIAN);
                DoCastSelf(SPELL_HAIL_OF_BONES);
                events.ScheduleEvent(EVENT_PREPARE_LANDING, 24s, 0, PHASE_ONE);
                events.ScheduleEvent(EVENT_BERSERK, 10min + 30s);
                break;
            case ACTION_ONYXIA_DIED:
                events.ScheduleEvent(EVENT_SAY_ONYXIA_DEAD, 1ms, 0, PHASE_ONE);
                break;
            default:
                break;
        }
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        switch (summon->GetEntry())
        {
            case NPC_CHROMATIC_PROTOTYPE:
                // Nefarian enters phase three when the first Chromatic Prototype has died on heroic difficulty
                if (IsHeroic())
                    events.ScheduleEvent(EVENT_ENTER_PHASE_THREE, 1ms, 0, PHASE_TWO);
                else
                {
                    _deadChromaticPrototypes++;
                    if (_deadChromaticPrototypes == 3)
                        events.ScheduleEvent(EVENT_ENTER_PHASE_THREE, 1ms, 0, PHASE_TWO);
                }
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && !events.IsInPhase(PHASE_ONE))
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CHAIN_ONYXIA:
                    for (ObjectGuid guid : summons)
                    {
                        if (Creature* stalker = ObjectAccessor::GetCreature(*me, guid))
                            if (stalker->GetEntry() == NPC_INVISIBLE_STALKER_CATACLYSM_BOSS)
                                for (OnyxiaChainData const& data : OnyxiaChainInfo)
                                    if (stalker->GetExactDist2d(data.ComparisonPosition) < 1.0f)
                                        stalker->CastSpell(stalker, data.ChainSpellId);
                    }
                    break;
                case EVENT_REMOVE_TRANSFORM_AURA:
                    me->RemoveAurasDueToSpell(SPELL_INTRO_2_STALKER_TRANSFORM);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->SetDisableGravity(true);
                    me->SendSetPlayHoverAnim(true);
                    events.ScheduleEvent(EVENT_LIFT_OFF, 2s, 0, PHASE_ONE);
                    break;
                case EVENT_LIFT_OFF:
                    DoCastSelf(SPELL_INTRO_4_LIFT_OFF_ANIM_KIT);
                    me->RemoveAurasDueToSpell(SPELL_INTRO_3_SHRINK_AURA);
                    events.ScheduleEvent(EVENT_ANNOUNCE_AIR_CRACKLES, 8s + 500ms, 0, PHASE_ONE);
                    break;
                case EVENT_ANNOUNCE_AIR_CRACKLES:
                    Talk(SAY_ANNOUNCE_AIR_CRACKLES);
                    me->GetMotionMaster()->MovePoint(POINT_LIFTOFF, NefarianLiftOffPosition, false);
                    break;
                case EVENT_PREPARE_LANDING:
                {
                    Position pos = events.IsInPhase(PHASE_ONE) ? NefarianElevatorPrepareLandPositionPhaseOne : NefarianElevatorPrepareLandPositionPhaseThree;
                    me->GetMotionMaster()->MovePoint(POINT_PREPARE_LANDING, pos, false);
                    break;
                }
                case EVENT_LAND_PHASE_ONE:
                    if (Transport* transport = GetElevator())
                        transport->AddPassenger(me);

                    me->GetMotionMaster()->MoveLand(POINT_LAND, NefarianElevatorLandPhaseOnePosition);
                    break;
                case EVENT_LANDED:
                    me->SetDisableGravity(false);
                    me->SendSetPlayHoverAnim(false);

                    if (events.IsInPhase(PHASE_ONE))
                    {
                        DoCastSelf(SPELL_SHADOW_OF_COWARDICE);
                        DoZoneInCombat();
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, FRAME_INDEX_NEFARIAN);
                        events.ScheduleEvent(EVENT_ENGAGE_PLAYERS, 2s, 0, PHASE_ONE);
                        if (Creature* onyxia = instance->GetCreature(DATA_ONYXIA))
                            if (onyxia->IsAIEnabled)
                                onyxia->AI()->DoAction(ACTION_NEFARIAN_LANDED);
                    }
                    else if (events.IsInPhase(PHASE_THREE))
                        events.ScheduleEvent(EVENT_ENGAGE_PLAYERS, 2s, 0, PHASE_THREE);
                    break;
                case EVENT_ENGAGE_PLAYERS:
                    me->SetReactState(REACT_AGGRESSIVE);

                    if (events.IsInPhase(PHASE_ONE))
                    {
                        DoCastSelf(SPELL_CHILDREN_OF_DEATHWING_NEFARIAN);
                        if (Creature* onyxia = instance->GetCreature(DATA_ONYXIA))
                            onyxia->CastSpell(onyxia, SPELL_CHILDREN_OF_DEATHWING_ONYXIA, true);

                        events.ScheduleEvent(EVENT_TAIL_LASH, 18s, 0, PHASE_ONE);
                        events.ScheduleEvent(EVENT_SHADOWFLAME_BREATH, 9s, 10s, 0, PHASE_ONE);

                        if (IsHeroic())
                            events.ScheduleEvent(EVENT_DOMINION, 13s, 0, PHASE_ONE);
                    }
                    else if (events.IsInPhase(PHASE_THREE))
                    {
                        DoCastSelf(SPELL_SHADOW_OF_COWARDICE);
                        DoCastSelf(SPELL_BRUSHFIRE_PRE_START_PERIODIC);
                        events.ScheduleEvent(EVENT_SHADOWFLAME_BREATH, 9s, 0, PHASE_THREE);
                        events.ScheduleEvent(EVENT_TAIL_LASH, 1s, 0, PHASE_THREE);
                    }
                    break;
                case EVENT_TAIL_LASH:
                    DoCastSelf(SPELL_TAIL_LASH);
                    if (events.IsInPhase(PHASE_ONE))
                        events.Repeat(5s);
                    else if (events.IsInPhase(PHASE_THREE))
                        events.Repeat(15s, 22s);
                    break;
                case EVENT_SHADOWFLAME_BREATH:
                    DoCastVictim(SPELL_SHADOWFLAME_BREATH);

                    if (events.IsInPhase(PHASE_ONE))
                        events.Repeat(9s, 14s);
                    else if (events.IsInPhase(PHASE_THREE))
                        events.Repeat(17s, 22s);
                    break;
                case EVENT_SAY_ONYXIA_DEAD:
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    me->RemoveAurasDueToSpell(SPELL_CHILDREN_OF_DEATHWING_NEFARIAN);
                    me->RemoveAurasDueToSpell(SPELL_ELECTRICAL_CHARGE_NEFARIAN);
                    me->RemoveAurasDueToSpell(SPELL_SHADOW_OF_COWARDICE);
                    Talk(SAY_ONYXIA_DIED);
                    events.SetPhase(PHASE_TWO);
                    events.ScheduleEvent(EVENT_MOVE_TO_CENTER, 2s, 0, PHASE_TWO);
                    break;
                case EVENT_MOVE_TO_CENTER:
                    me->GetMotionMaster()->MovePoint(POINT_ELEVATOR_CENTER, NefarianElevatorCenterPosition);
                    break;
                case EVENT_LIFTOFF_PHASE_TWO:
                    DoCastSelf(SPELL_NEFARIAN_PHASE_2_HEALTH_AURA);
                    me->SetDisableGravity(true);
                    me->SendSetPlayHoverAnim(true);
                    me->GetMotionMaster()->MovePoint(POINT_NONE, NefarianElevatorLiftOffPosition);
                    events.ScheduleEvent(EVENT_SUMMON_CHROMATIC_PROTOTYPES, 400ms, 0, PHASE_TWO);
                    events.ScheduleEvent(EVENT_LOWER_ELEVATOR, 800ms, 0, PHASE_TWO);
                    events.ScheduleEvent(EVENT_SAY_PHASE_TWO, 4s + 800ms, 0, PHASE_TWO);
                    events.ScheduleEvent(EVENT_ENTER_PHASE_THREE, 2min + 30s, 0, PHASE_TWO);
                    events.ScheduleEvent(EVENT_SHADOWFLAME_BARRAGE, 2s + 500ms, 0, PHASE_TWO);

                    if (IsHeroic())
                        events.ScheduleEvent(EVENT_EXPLOSIVE_CINDERS, 2s, 0, PHASE_TWO);
                    break;
                case EVENT_SUMMON_CHROMATIC_PROTOTYPES:
                    for (uint8 i = 0; i < MaxChromaticPrototypes; i++)
                    {
                        if (Creature* prototype = DoSummon(NPC_CHROMATIC_PROTOTYPE, ChromaticPrototypeSummonPositions[i], 4000))
                        {
                            Position point = ChromaticPrototypeMovePositions[i];
                            prototype->m_Events.AddEventAtOffset([prototype, point]()
                            {
                                prototype->GetMotionMaster()->MovePoint(POINT_JUMP_DOWN, point);
                            }, 800ms);
                        }
                    }
                    break;
                case EVENT_LOWER_ELEVATOR:
                    if (Transport* transport = GetElevator())
                        transport->SetTransportState(GO_STATE_TRANSPORT_ACTIVE);
                    events.ScheduleEvent(EVENT_ELEVATOR_LOWERED, 9s, 0, PHASE_TWO);
                    break;
                case EVENT_ELEVATOR_LOWERED:
                    _elevatorLowered = true;
                    break;
                case EVENT_SHADOWFLAME_BARRAGE:
                    DoCastAOE(SPELL_SHADOWFLAME_BARRAGE);
                    events.Repeat(2s + 500ms);
                    break;
                case EVENT_SAY_PHASE_TWO:
                    Talk(SAY_MOLTEN_LAVA);
                    break;
                case EVENT_ENTER_PHASE_THREE:
                    if (!_elevatorLowered)
                    {
                        events.Repeat(1s);
                        break;
                    }
                    EnterPhaseThree();
                    break;
                case EVENT_SAY_PHASE_THREE:
                    Talk(SAY_LAND_PHASE_THREE);
                    break;
                case EVENT_LAND_PHASE_THREE:
                    if (me->GetHealthPct() > 50.f)
                        instance->SetData(DATA_NEFARIAN_ACHIEVEMENT_STATE, 0);

                    me->RemoveAurasDueToSpell(SPELL_NEFARIAN_PHASE_2_HEALTH_AURA);
                    me->SendSetPlayHoverAnim(true);
                    me->GetMotionMaster()->MoveLand(POINT_LAND, NefarianElevatorLandPhaseThreePosition);
                    break;
                case EVENT_ELECTROCUTE:
                    if (Creature* machine = instance->GetCreature(DATA_NEFARIANS_LIGHTNING_MACHINE))
                    {
                        machine->CastSpell(machine, SPELL_ELECTROCUTE);
                        machine->CastSpell(machine, SPELL_ELECTROCUTE_DAMAGE);
                    }

                    if (Creature* onyxia = instance->GetCreature(DATA_ONYXIA))
                        if (Aura* charge = onyxia->GetAura(SPELL_ELECTRICAL_CHARGE_ONYXIA))
                            charge->ModStackAmount(17, AuraRemoveFlags::ByDefault | AuraRemoveFlags::DontResetPeriodicTimer);
                    break;
                case EVENT_DOMINION:
                    DoCastAOE(SPELL_DOMINION_DUMMY);
                    events.Repeat(15s);
                    break;
                case EVENT_EXPLOSIVE_CINDERS:
                    DoCastAOE(SPELL_EXPLOSIVE_CINDERS);
                    events.Repeat(15s);
                    break;
                case EVENT_BERSERK:
                    DoCastSelf(SPELL_BERSERK, true);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    /*
        This is a clusterfuck but required to make spawning on transports work properly. If we don't add creatures to transports before they are
        being sent out via update_object the passenger visual will not work so we wont see the passengers move with the transport. This will take care
        of it for now.
    */
    void SetupTransportSpawns(uint32 summonGroupId)
    {
        GameObject* elevator = instance->GetGameObject(DATA_BLACKWING_ELEVATOR_ONYXIA);
        if (!elevator)
            return;

        Transport* transport = elevator->ToTransport();
        if (!transport)
            return;

        std::vector<TempSummonData> const* data = sObjectMgr->GetSummonGroup(me->GetEntry(), SUMMONER_TYPE_CREATURE, summonGroupId);
        if (!data)
            return;

        Map* map = me->GetMap();
        for (std::vector<TempSummonData>::const_iterator itr = data->begin(); itr != data->end(); itr++)
        {

            TempSummon* summon = new TempSummon(nullptr, me, false);
            if (!summon->Create(map->GenerateLowGuid<HighGuid::Unit>(), map, itr->entry, itr->pos, nullptr, 0, true))
            {
                delete summon;
                continue;
            }

            Position pos = itr->pos;
            float x, y, z, o;
            pos.GetPosition(x, y, z, o);

            // Keeping the current transport position in mind for example if we spawn the units after a reset above the lava
            if (summonGroupId == SUMMON_GROUP_ELEVATOR)
            {
                z += std::abs(transport->GetPositionZ() - transport->GetGameObjectData()->spawnPoint.GetPositionZ());
                pos.m_positionZ = z;
            }

            transport->CalculatePassengerOffset(x, y, z, &o);

            transport->AddPassenger(summon);
            summon->m_movementInfo.transport.pos.Relocate({ x, y, z, o });
            summon->Relocate(pos);
            summon->SetHomePosition(pos);
            summon->SetTransportHomePosition({ x, y, z, o });

            PhasingHandler::InheritPhaseShift(summon, me);

            map->AddToMap(summon->ToCreature());
            summon->InitSummon();
        }
    }

    void EnterPhaseThree()
    {
        if (events.IsInPhase(PHASE_THREE))
            return;

        events.SetPhase(PHASE_THREE);
        events.ScheduleEvent(EVENT_SAY_PHASE_THREE, 14s + 700ms);
        events.ScheduleEvent(EVENT_PREPARE_LANDING, 15s + 500ms, 0, PHASE_THREE);
        if (Transport* elevator = GetElevator())
            elevator->SetTransportState(GO_STATE_TRANSPORT_STOPPED, TRANSPORT_STOP_FRAME_RAISED);

        for (ObjectGuid guid : summons)
        {
            if (Creature* creature = ObjectAccessor::GetCreature(*me, guid))
                if (creature->GetEntry() == NPC_CHROMATIC_PROTOTYPE &&  creature->IsAlive() && creature->IsAIEnabled)
                    creature->AI()->DoAction(ACTION_DISENGAGE_PLAYERS);
        }
    }

    Transport* GetElevator()
    {
        GameObject* elevator = instance->GetGameObject(DATA_BLACKWING_ELEVATOR_ONYXIA);
        if (!elevator || !elevator->ToTransport())
            return nullptr;

        return elevator->ToTransport();
    }

    bool _elevatorLowered;
    bool _encounterReset;
    uint8 _nextElectrocuteHealthPercentage;
    uint8 _deadChromaticPrototypes;
};

struct npc_nefarians_end_onyxia : public ScriptedAI
{
    npc_nefarians_end_onyxia(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript()), _allowDeath(false), _chargeWarningLevel(0)
    {
        me->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING); // Remove this little workarround when mmaps for transports have arrived.
    }

    void JustAppeared() override
    {
        if (_instance->GetData(DATA_NEFARIANS_END_INTRO_DONE))
            DoAction(ACTION_REANIMATED);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        if (_instance->GetBossState(DATA_NEFARIANS_END) != IN_PROGRESS)
            _instance->SetBossState(DATA_NEFARIANS_END, IN_PROGRESS);

        _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, FRAME_INDEX_ONYXIA);

        if (Creature* nefarian = _instance->GetCreature(DATA_NEFARIANS_END))
            nefarian->AI()->DoAction(ACTION_ONYXIA_ENGAGED);

        me->RemoveAurasDueToSpell(SPELL_ONYXIA_START_FIGHT_1_PERIODIC);
        DoCastSelf(SPELL_ELECTRICAL_CHARGE_ONYXIA);
        _events.ScheduleEvent(EVENT_TAIL_LASH, 20s);
        _events.ScheduleEvent(EVENT_SHADOWFLAME_BREATH, 11s, 12s);
        _events.ScheduleEvent(EVENT_LIGHTNING_DISCHARGE, 22s);

        if (Creature* controller = _instance->GetCreature(DATA_CONTROLLER_STALKER))
        {
            if (controller->IsAIEnabled)
                controller->AI()->DoZoneInCombat();

            controller->CastSpell(controller, SPELL_PET_HACK_1);
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        if (Creature* nefarian = _instance->GetCreature(DATA_NEFARIANS_END))
            nefarian->AI()->EnterEvadeMode();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        if (Creature* nefarian = _instance->GetCreature(DATA_NEFARIANS_END))
            nefarian->AI()->DoAction(ACTION_ONYXIA_DIED);

        me->DespawnOrUnsummon(19s);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_REANIMATED:
                me->RemoveAurasDueToSpell(SPELL_PERMANENT_FEIGN_DEATH_1);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                me->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                me->PlayDirectSound(SOUND_ID_ROAR);
                me->SetReactState(REACT_AGGRESSIVE);
                DoCastSelf(SPELL_ONYXIA_START_FIGHT_1_PERIODIC);
                break;
            case ACTION_UPDATE_ELECTRICAL_CHARGE:
                if (Aura* chargeAura = me->GetAura(SPELL_ELECTRICAL_CHARGE_ONYXIA))
                {
                    uint8 stacks = chargeAura->GetStackAmount();
                    if (stacks == chargeAura->GetSpellInfo()->StackAmount)
                    {
                        DoCastAOE(SPELL_ELECTRICAL_OVERLOAD);
                        stacks = 1;
                        _chargeWarningLevel = 0;
                        chargeAura->SetStackAmount(stacks);
                    }

                    if (stacks >= 50 && _chargeWarningLevel == 0)
                    {
                        Talk(SAY_ANNOUNCE_WARNING_1);
                        _chargeWarningLevel = 1;
                    }
                    else if (stacks >= 80 && _chargeWarningLevel != 2)
                    {
                        Talk(SAY_ANNOUNCE_WARNING_2);
                        _chargeWarningLevel = 2;
                    }

                    me->SetPower(POWER_ALTERNATE_POWER, stacks - 1);
                }
                break;
            case ACTION_NEFARIAN_LANDED:
                _allowDeath = true;
                break;
            default:
                break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        // Onyxia may not die before Nefarian has landed
        if (damage >= me->GetHealth() && !_allowDeath)
            damage = me->GetHealth() - 1;
    }

    void OnSpellCastFinished(SpellInfo const* spell, SpellFinishReason /*reason*/) override
    {
        switch (spell->Id)
        {
            case SPELL_LIGHTNING_DISCHARGE_CONE_FRONT:
                DoCastAOE(SPELL_LIGHTNING_DISCHARGE_DAMAGE);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_TAIL_LASH:
                    DoCastSelf(SPELL_TAIL_LASH);
                    _events.Repeat(17s, 18s);
                    break;
                case EVENT_SHADOWFLAME_BREATH:
                    DoCastVictim(SPELL_SHADOWFLAME_BREATH);
                    _events.Repeat(13s, 17s);
                    break;
                case EVENT_LIGHTNING_DISCHARGE:
                    DoCastSelf(SPELL_LIGHTNING_DISCHARGE);
                    _events.Repeat(22s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    InstanceScript* _instance;
    EventMap _events;
    bool _allowDeath;
    uint8 _chargeWarningLevel;
};

struct npc_nefarians_end_lord_victor_nefarius : public PassiveAI
{
    npc_nefarians_end_lord_victor_nefarius(Creature* creature) : PassiveAI(creature), _instance(me->GetInstanceScript()), _started(false){ }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_START_INTRO:
                if (!_started)
                {
                    Talk(SAY_INTRO_1);
                    DoSummon(BOSS_NEFARIAN, NefarianSummonPosition, 0, TEMPSUMMON_MANUAL_DESPAWN);
                    _events.ScheduleEvent(EVENT_TALK_INTRO_2, 22s);
                    _events.ScheduleEvent(EVENT_RAISE_ELEVATOR, 20s + 500ms);
                    _events.ScheduleEvent(EVENT_CAST_TRANSFORM_VISUAL, 26s + 700ms);
                    _started = true;
                }
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_TALK_INTRO_2:
                    Talk(SAY_INTRO_2);
                    _events.ScheduleEvent(EVENT_TALK_INTRO_3, 11s);
                    break;
                case EVENT_TALK_INTRO_3:
                    Talk(SAY_INTRO_3);
                    _instance->SetData(DATA_NEFARIANS_END_INTRO_DONE, 1);
                    me->DespawnOrUnsummon();
                    break;
                case EVENT_RAISE_ELEVATOR:
                    if (GameObject* elevator = _instance->GetGameObject(DATA_BLACKWING_ELEVATOR_ONYXIA))
                        if (Transport* transport = elevator->ToTransport())
                            transport->SetTransportState(GO_STATE_TRANSPORT_STOPPED, TRANSPORT_STOP_FRAME_RAISED);
                    break;
                case EVENT_CAST_TRANSFORM_VISUAL:
                    if (Creature* stalker = me->FindNearestCreature(NPC_INVISIBLE_STALKER_CATACLYSM_BOSS, 1.0f))
                    {
                        stalker->CastSpell(stalker, SPELL_INTRO_1_TRANSFORM_VISUAL);
                        stalker->DespawnOrUnsummon(2s + 400ms);
                    }
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    InstanceScript* _instance;
    bool _started;
};

struct npc_nefarians_end_animated_bone_warrior : public ScriptedAI
{
    npc_nefarians_end_animated_bone_warrior(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript())
    {
        me->SetReactState(REACT_PASSIVE);
        me->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING); // tempfix until mmaps for transports have arrived
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_FULL_POWER_NO_REGEN);
        DoCastSelf(SPELL_ANIMATE_BONES);

        if (GameObject* elevator = _instance->GetGameObject(DATA_BLACKWING_ELEVATOR_ONYXIA))
            if (Transport* transport = elevator->ToTransport())
                transport->AddPassenger(me);

        me->UpdatePositionData();

        me->m_Events.AddEventAtOffset([this]()
        {
            me->SetReactState(REACT_AGGRESSIVE);
            if (me->IsAIEnabled)
                DoZoneInCombat();
        }, 800ms);
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->DespawnOrUnsummon(4s);
    }

    void UpdateAI(uint32 /*diff*/) override
    {
        // Prevent any victim update while we are in feign death state
        if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE))
            return;

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
private:
    InstanceScript* _instance;
};

struct npc_nefarians_end_chromatic_prototype : public PassiveAI
{
    npc_nefarians_end_chromatic_prototype(Creature* creature) : PassiveAI(creature), _instance(me->GetInstanceScript()) { }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        switch (id)
        {
            case POINT_JUMP_DOWN:
                _events.ScheduleEvent(EVENT_JUMP_DOWN_TO_PLATFORM, 1s + 200ms);
                break;
            default:
                break;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_DISENGAGE_PLAYERS:
                me->InterruptNonMeleeSpells(true);
                me->SetHomePosition(me->GetPosition());
                me->GetThreatManager().ClearAllThreat();
                me->CombatStop();
                _events.Reset();
                _events.ScheduleEvent(EVENT_DISENGAGE_PLAYERS, 3s + 700ms);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_JUMP_DOWN_TO_PLATFORM:
                    if (GameObject* elevator = _instance->GetGameObject(DATA_BLACKWING_ELEVATOR_ONYXIA))
                    {
                        if (Transport* transport = elevator->ToTransport())
                        {
                            transport->AddPassenger(me);
                            DoCastAOE(SPELL_JUMP_DOWN_TO_PLATFORM);
                        }
                    }
                    _events.ScheduleEvent(EVENT_READY_PROTOTYPE, 5s);
                    break;
                case EVENT_READY_PROTOTYPE:
                    DoZoneInCombat();
                    _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, FRAME_INDEX_CHROMATIC_PROTOTYPE);
                    DoCastSelf(SPELL_READY_UNARMED);
                    for (uint8 i = 0; i < 3; i++) // no idea what Blizzard was thinking here...
                        DoCastSelf(SPELL_DUMMY_NUKE);

                    _events.ScheduleEvent(EVENT_DUMMY_NUKE, 1s);
                    _events.ScheduleEvent(EVENT_BLAST_NOVA, 3s + 500ms);
                    break;
                case EVENT_DUMMY_NUKE:
                    DoCastSelf(SPELL_DUMMY_NUKE);
                    _events.Repeat(1s);
                    break;
                case EVENT_BLAST_NOVA:
                    DoCastAOE(SPELL_BLAST_NOVA);
                    _events.Repeat(13s);
                    break;
                case EVENT_DISENGAGE_PLAYERS:
                    _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                    me->DespawnOrUnsummon(5s);
                    break;
                default:
                    break;
            }
        }
    }

private:
    InstanceScript* _instance;
    EventMap _events;
};

struct npc_nefarians_end_shadowblaze : public NullCreatureAI
{
    npc_nefarians_end_shadowblaze(Creature* creature) : NullCreatureAI(creature), _summonedByController(false), _instance(me->GetInstanceScript()) { }

    void JustAppeared() override
    {
        if (me->GetEntry() == NPC_SHADOWBLAZE_FLASHPOINT)
            DoCastSelf(SPELL_BRUSHFIRE_FLASHPOINT_CONTROL);
        else
            DoCastSelf(SPELL_BRUSHFIRE_CHECK_VALID_LOCATION);

        DoCastSelf(SPELL_BRUSHFIRE_BURN_AURA);
        DoCastSelf(SPELL_BRUSHFIRE_GROWTH);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        if (summoner->GetEntry() == NPC_SHADOWBLAZE_FLASHPOINT)
            _summonedByController = true;

        if (Creature* nefarian = _instance->GetCreature(DATA_NEFARIANS_END))
            if (nefarian->IsAIEnabled)
                nefarian->AI()->JustSummoned(me);
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
            case SPELL_BRUSHFIRE_CHECK_VALID_LOCATION:
                _controllerStalkerPosition = target->GetPosition();
                break;
            default:
                break;
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_SPREAD_FLAMES:
            {
                float z = me->GetPositionZ();
                if (z >= 13.f) // tempfix to avoid flames spawn in the air when a controller gets spawned on a pillar
                    z = 8.472f;

                if (!_summonedByController && me->GetEntry() != NPC_SHADOWBLAZE_FLASHPOINT)
                {
                    // Select a destination that will serve as our offset selection helper
                    float angle = me->GetAngle(_controllerStalkerPosition) - float(M_PI / 2.5f);
                    float compareX = me->GetPositionX() + std::cos(angle) * 20.f;
                    float compareY = me->GetPositionY() + std::sin(angle) * 20.f;
                    Position comparePos = Position(compareX, compareY);

                    Position summonPos = me->GetPosition();
                    // Select the closest nearby location for summoning
                    float offsets[3] = { -5.f, 0.f, 5.f };

                    for (uint8 i = 0; i < 3; i++)
                    {
                        float x = me->GetPositionX() + offsets[i];
                        for (uint8 u = 0; u < 3; u++)
                        {
                            float y = me->GetPositionY() + offsets[u];
                            if (Position(x, y).GetExactDist2d(comparePos) < summonPos.GetExactDist2d(comparePos))
                                summonPos = Position(x, y);
                        }
                    }

                    me->CastSpell({ summonPos.GetPositionX(), summonPos.GetPositionY(), z, 0.f }, SPELL_BRUSHFIRE_SUMMON, true);
                }
                else
                {
                    if (me->GetEntry() == NPC_SHADOWBLAZE_FLASHPOINT)
                    {
                        me->CastSpell({ me->GetPositionX() - 5.f, me->GetPositionY(), z, 0.f }, SPELL_BRUSHFIRE_SUMMON, true);
                        me->CastSpell({ me->GetPositionX(), me->GetPositionY() + 5.f, z, 0.f }, SPELL_BRUSHFIRE_SUMMON, true);
                    }
                    else if (_summonedByController)
                    {
                        for (uint8 i = 0; i < 2; i++)
                        {
                            float x = me->GetPositionX() + 5.f;
                            float y = me->GetPositionY() + 5.f;
                            me->CastSpell({ x, y, z, 0.f }, SPELL_BRUSHFIRE_SUMMON, true);
                        }
                    }
                }
                break;
            }
            default:
                break;
        }
    }

private:
    Position _controllerStalkerPosition;
    bool _summonedByController;
    InstanceScript* _instance;
};

class spell_nefarians_end_electrical_charge : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ELECTRICAL_CHARGE_ONYXIA });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Creature* target = GetTarget()->ToCreature();
        InstanceScript* instance = GetTarget()->GetInstanceScript();
        if (!target || !instance)
            return;

        switch (target->GetEntry())
        {
            case BOSS_NEFARIAN:
                if (target->GetReactState() == REACT_AGGRESSIVE)
                {
                    if (Creature* onyxia = instance->GetCreature(DATA_ONYXIA))
                    {
                        if (Aura* charge = onyxia->GetAura(SPELL_ELECTRICAL_CHARGE_ONYXIA))
                            charge->ModStackAmount(1, AuraRemoveFlags::Expired | AuraRemoveFlags::DontResetPeriodicTimer);
                    }
                }
                break;
            case NPC_ONYXIA:
                ModStackAmount(1);
                if (target->IsAIEnabled)
                    target->AI()->DoAction(ACTION_UPDATE_ELECTRICAL_CHARGE);
                break;
            default:
                break;
        }
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_nefarians_end_electrical_charge::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class spell_nefarians_end_lightning_discharge_triggered_periodic_aura : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_LIGHTNING_DISCHARGE_VISUAL_LEFT_1,
                SPELL_LIGHTNING_DISCHARGE_VISUAL_LEFT_2,
                SPELL_LIGHTNING_DISCHARGE_VISUAL_RIGHT_1,
                SPELL_LIGHTNING_DISCHARGE_VISUAL_RIGHT_2,
                SPELL_LIGHTNING_DISCHARGE_CONE_BACK
            });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        for (uint8 i = 0; i < 4; i++)
        {
            target->CastSpell(target, SPELL_LIGHTNING_DISCHARGE_VISUAL_LEFT_1, true);
            target->CastSpell(target, SPELL_LIGHTNING_DISCHARGE_VISUAL_LEFT_2, true);
            target->CastSpell(target, SPELL_LIGHTNING_DISCHARGE_VISUAL_RIGHT_1, true);
            target->CastSpell(target, SPELL_LIGHTNING_DISCHARGE_VISUAL_RIGHT_2, true);
        }

        target->CastSpell(target, SPELL_LIGHTNING_DISCHARGE_CONE_BACK, true);
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_nefarians_end_lightning_discharge_triggered_periodic_aura::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_nefarians_end_lightning_discharge_cone : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_LIGHTNING_DISCHARGE_DAMAGE });
    }

    void HandleImmunity(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!caster || !target)
            return;

        uint32 spellId = sSpellMgr->GetSpellIdForDifficulty(SPELL_LIGHTNING_DISCHARGE_DAMAGE, caster);
        target->ApplySpellImmune(0, IMMUNITY_ID, spellId, true);

        target->m_Events.AddEventAtOffset([spellId, target]()
        {
            target->ApplySpellImmune(0, IMMUNITY_ID, spellId, false);
        }, 500ms);
    }

    void Register() override
    {
        OnEffectLaunchTarget.Register(&spell_nefarians_end_lightning_discharge_cone::HandleImmunity, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_nefarians_end_lightning_discharge_damage : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        SpellInfo const* spell = GetSpellInfo();
        Unit* caster = GetCaster();

        targets.remove_if([spell, caster](WorldObject const* obj)->bool
        {
            Unit const* target = obj->ToUnit();
            return !target || target->IsImmunedToSpell(spell, caster);
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_nefarians_end_lightning_discharge_damage::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_nefarians_end_children_of_deathwing : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CHILDREN_OF_DEATHWING_NEFARIAN });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        uint32 type = GetSpellInfo()->Id == SPELL_CHILDREN_OF_DEATHWING_NEFARIAN ? DATA_ONYXIA : DATA_NEFARIANS_END;
        if (InstanceScript* instance = target->GetInstanceScript())
            if (Creature* sibling = instance->GetCreature(type))
                if (target->GetExactDist2d(sibling) <= 50.f)
                    target->CastSpell(target, GetSpellInfo()->Effects[EFFECT_0].BasePoints, true);
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_nefarians_end_children_of_deathwing::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class spell_nefarians_end_animate_bones : public AuraScript
{
    void HandlePeriodicTick(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(GetTarget(), GetSpellInfo()->Effects[EFFECT_1].TriggerSpell, TriggerCastFlags(TRIGGERED_FULL_MASK & ~TRIGGERED_IGNORE_POWER_AND_REAGENT_COST));
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_nefarians_end_animate_bones::HandlePeriodicTick, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_nefarians_end_animate_bones_dummy : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PERMANENT_FEIGN_DEATH_2,
                SPELL_CLEAR_ALL_DEBUFFS,
                SPELL_EMPOWER
            });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Creature* target = GetHitCreature();
        if (!target || target->GetPower(POWER_ENERGY) > 1)
            return;

        target->RemoveAurasDueToSpell(SPELL_FULL_POWER_NO_REGEN);
        target->RemoveAurasDueToSpell(SPELL_ANIMATE_BONES);
        target->RemoveAurasDueToSpell(sSpellMgr->GetSpellIdForDifficulty(SPELL_EMPOWER, target));
        target->CastSpell(target, SPELL_CLEAR_ALL_DEBUFFS, true);
        target->AttackStop();
        target->GetThreatManager().ClearAllThreat();
        target->SetReactState(REACT_PASSIVE);
        target->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        target->CastSpell(target, SPELL_PERMANENT_FEIGN_DEATH_2);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_nefarians_end_animate_bones_dummy::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_nefarians_end_shadowflame_breath : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PERMANENT_FEIGN_DEATH_2,
                SPELL_FULL_POWER_NO_REGEN
            });
    }

    void HandleHit(SpellEffIndex effIndex)
    {
        Creature* target = GetHitCreature();
        if (!target)
            return;

        if (target->HasAura(SPELL_PERMANENT_FEIGN_DEATH_2))
        {
            target->SetReactState(REACT_AGGRESSIVE);
            if (target->IsAIEnabled)
                target->AI()->DoZoneInCombat();

            target->RemoveAurasDueToSpell(SPELL_PERMANENT_FEIGN_DEATH_2);
            target->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        target->CastSpell(target, SPELL_FULL_POWER_NO_REGEN);
        target->CastSpell(target, GetSpellInfo()->Effects[effIndex].BasePoints);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_nefarians_end_shadowflame_breath::HandleHit, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_nefarians_end_jump_down_to_platform : public SpellScript
{
    void SetDest(SpellDestination& dest)
    {
        Position positions[MaxChromaticPrototypes];

        InstanceScript* instance = GetCaster()->GetInstanceScript();
        if (!instance)
            return;

        GameObject* elevator = instance->GetGameObject(DATA_BLACKWING_ELEVATOR_ONYXIA);
        if (!elevator || !elevator->ToTransport())
            return;

        Transport* transport = elevator->ToTransport();

        // Transform sniffed transport destinations into map coordinates so we can use them for real time transport position based offsets
        for (uint8 i = 0; i < MaxChromaticPrototypes; i++)
        {
            positions[i] = ChromaticPrototypeJumpPositions[i];
            transport->CalculatePassengerPosition(positions[i].m_positionX, positions[i].m_positionY, positions[i].m_positionZ);
        }

        // Pick the closest jump destination
        Position pos = positions[0];
        for (uint8 i = 1; i < MaxChromaticPrototypes; i++)
            if (GetCaster()->GetExactDist2d(positions[i]) < GetCaster()->GetExactDist2d(pos))
                pos = positions[i];

        dest.Relocate(pos);
    }

    void Register()
    {
        OnDestinationTargetSelect.Register(&spell_nefarians_end_jump_down_to_platform::SetDest, EFFECT_0, TARGET_DEST_NEARBY_ENTRY);
    }
};

class spell_nefarians_end_shadow_of_cowardice : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHADOW_OF_COWARDICE_DAMAGE });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        Unit* target = GetHitUnit();
        if (target->GetTransport() && target->GetTransOffsetZ() > 9.5f)
            caster->CastSpell(target, SPELL_SHADOW_OF_COWARDICE_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_nefarians_end_shadow_of_cowardice::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_nefarians_end_onyxia_start_fight_2_effect : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHADOW_OF_COWARDICE_DAMAGE });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject const* target)->bool
        {
            return !target->GetTransGUID();
        });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();

        if (Creature* caster = GetCaster()->ToCreature())
        {
            if (caster->IsAIEnabled && !caster->IsInCombat())
                caster->AI()->DoZoneInCombat();

            if (target->GetTransOffsetZ() > 9.5f)
                caster->CastSpell(target, SPELL_SHADOW_OF_COWARDICE_DAMAGE, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_nefarians_end_onyxia_start_fight_2_effect::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnObjectAreaTargetSelect.Register(&spell_nefarians_end_onyxia_start_fight_2_effect::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_nefarians_end_empowering_strikes : public AuraScript
{
    void HandlePeriodicTick(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(GetTarget(), GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, TriggerCastFlags(TRIGGERED_FULL_MASK & ~TRIGGERED_IGNORE_CASTER_AURAS));
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_nefarians_end_empowering_strikes::HandlePeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_nefarians_end_brushfire_pre_start_periodic : public AuraScript
{
    bool Load() override
    {
        _nextTriggerTickNumber = 1;
        return true;
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BRUSHFIRE_START });
    }

    void HandlePeriodicTick(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        _ticksSinceLastTrigger++;
        if (_ticksSinceLastTrigger == _nextTriggerTickNumber)
        {
            target->CastSpell(target, SPELL_BRUSHFIRE_START, true);
            _ticksSinceLastTrigger = 0;

            if (_nextTriggerTickNumber == 1)
                _nextTriggerTickNumber = 6;
            else
                _nextTriggerTickNumber = std::max<uint32>(2, _nextTriggerTickNumber - 1);
        }
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_nefarians_end_brushfire_pre_start_periodic::HandlePeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }

private:
    uint8 _nextTriggerTickNumber = 0;
    uint8 _ticksSinceLastTrigger = 0;
};

class spell_nefarians_end_brushfire_start : public SpellScript
{
    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints, true);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_nefarians_end_brushfire_start::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_nefarians_end_brushfire_growth : public AuraScript
{
    void HandlePeriodicTick(AuraEffect const* /*aurEff*/)
    {
        if (Creature* creature = GetTarget()->ToCreature())
            if (creature->IsAIEnabled)
                creature->AI()->DoAction(ACTION_SPREAD_FLAMES);
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_nefarians_end_brushfire_growth::HandlePeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class spell_nefarians_end_shadowblaze : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PERMANENT_FEIGN_DEATH_2,
                SPELL_FULL_POWER_NO_REGEN,
                SPELL_CLEAR_ALL_DEBUFFS
            });
    }

    void HandleHit(SpellEffIndex effIndex)
    {
        Creature* target = GetHitCreature();
        if (!target)
            return;

        if (target->HasAura(SPELL_PERMANENT_FEIGN_DEATH_2))
        {
            target->SetReactState(REACT_AGGRESSIVE);
            if (target->IsAIEnabled)
                target->AI()->DoZoneInCombat();

            target->RemoveAurasDueToSpell(SPELL_PERMANENT_FEIGN_DEATH_2);
            target->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        target->CastSpell(target, SPELL_CLEAR_ALL_DEBUFFS, true);
        target->CastSpell(target, SPELL_FULL_POWER_NO_REGEN);
        target->CastSpell(target, GetSpellInfo()->Effects[effIndex].BasePoints);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_nefarians_end_shadowblaze::HandleHit, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_nefarians_end_dominion_dummy : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DOMINION_OVERRIDE_ACTION_BAR });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Unit* caster = GetCaster();
        uint8 size = caster->GetMap()->Is25ManRaid() ? 2 : 5;
        if (!targets.empty())
            caster->CastSpell(caster, SPELL_DOMINION_OVERRIDE_ACTION_BAR, CastSpellExtraArgs(true).AddSpellMod(SPELLVALUE_MAX_TARGETS, size));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_nefarians_end_dominion_dummy::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_nefarians_end_dominion : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_SUMMON_DOMINION_STALKER_NORTH,
                SPELL_SUMMON_DOMINION_STALKER_SOUTH,
                SPELL_SUMMON_DOMINION_STALKER_EAST,
                SPELL_SUMMON_DOMINION_STALKER_WEST,
                SPELL_DOMINION_IMMUNITY
            });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        for (uint8 i = 0; i < DominionStalkerSpellCount; i++)
            target->CastSpell(target, DominionStalkerSummonSpells[i], true);

        target->CastSpell(target, SPELL_DOMINION_IMMUNITY, true);
        target->SetByteFlag(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_PVP_FLAG, UNIT_BYTE2_FLAG_UNK1);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->RemoveAurasDueToSpell(SPELL_DOMINION_IMMUNITY);
        target->RemoveByteFlag(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_PVP_FLAG, UNIT_BYTE2_FLAG_UNK1);
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_nefarians_end_dominion::AfterApply, EFFECT_0, SPELL_AURA_OVERRIDE_SPELLS, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove.Register(&spell_nefarians_end_dominion::AfterRemove, EFFECT_0, SPELL_AURA_OVERRIDE_SPELLS, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_nefarians_end_determine_farthest_portal_stalker : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DOMINION_PORTAL_TRIGGER });
    }

    void HandlePeriodicTick(AuraEffect const* /*aurEff*/)
    {
        TempSummon* target = GetTarget()->ToTempSummon();
        if (!target)
            return;

        bool farthest = true;

        // This is very ugly and should be changed asap when we have a clean way to select all summoned units of a player
        std::list<Creature*> portalStalkers;
        Unit* summoner = target->GetSummoner();
        target->GetCreatureListWithEntryInGrid(portalStalkers, NPC_DOMINION_STALKER, 100.f);

        // Iterating through all stalkers of a player and select his furthest stalker
        for (Creature* stalker : portalStalkers)
        {
            TempSummon* summon = stalker->ToTempSummon();
            if (!summon || summon->GetSummonerGUID() != target->GetSummonerGUID() || summon == target)
                continue;

            if (summon->GetExactDist2d(summoner) > target->GetExactDist2d(summoner))
                farthest = false;
        }

        if (farthest)
        {
            target->CastSpell(target, SPELL_DOMINION_PORTAL_TRIGGER);
            Remove();
        }
        else
            target->DespawnOrUnsummon();
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_nefarians_end_determine_farthest_portal_stalker::HandlePeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class spell_nefarians_end_dominion_portal_trigger : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DOMINION_PORTAL_BEAM,
                SPELL_INSTAKILL_SELF
            });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        if (Unit* caster = GetCaster())
        {
            caster->CastSpell(caster, SPELL_DOMINION_PORTAL_BEAM);

            Movement::MoveSplineInit init(target);
            init.SetWalk(true);
            init.SetVelocity(3.5f);
            init.MoveTo(caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ(), false); // Todo: enable pathfinding when mmaps for transports have arrived
            target->m_Events.AddEventAtOffset([target, caster]()
            {
                if (target->HasAura(SPELL_DOMINION_OVERRIDE_ACTION_BAR))
                    target->CastSpell(target, SPELL_INSTAKILL_SELF, true);

                if (Creature* creature = caster->ToCreature())
                    creature->DespawnOrUnsummon();
            }, Milliseconds(init.Launch()));
        }
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_nefarians_end_dominion_portal_trigger::HandleHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_nefarians_end_free_your_mind : public AuraScript
{
    void AfterRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->RemoveAurasDueToSpell(aurEff->GetAmount());
        target->StopMoving();
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_nefarians_end_free_your_mind::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_nefarians_end_siphon_power : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_STOLEN_POWER });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_STOLEN_POWER);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_nefarians_end_siphon_power::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_nefarians_end_explosive_cinders : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_EXPLOSIVE_CINDERS_EXPLOSION });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode().HasFlag(AuraRemoveFlags::Expired))
            GetTarget()->CastSpell(GetTarget(), SPELL_EXPLOSIVE_CINDERS_EXPLOSION, true);
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_nefarians_end_explosive_cinders::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

struct go_nefarians_end_orb_of_culmination : public GameObjectAI
{
    go_nefarians_end_orb_of_culmination(GameObject* go) : GameObjectAI(go), _instance(me->GetInstanceScript()) { }

    bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
    {
        if (Creature* stalker = _instance->GetCreature(DATA_INVISIBLE_STALKER))
            stalker->RemoveAllAuras();

        if (Creature* nefarius = _instance->GetCreature(DATA_LORD_VICTOR_NEFARIUS_NEFARIANS_END))
            if (nefarius->IsAIEnabled)
                nefarius->AI()->DoAction(ACTION_START_INTRO);

        player->PlayerTalkClass->SendCloseGossip();
        me->DespawnOrUnsummon();

        return false;
    }

private:
    InstanceScript* _instance;
};

class achievement_keeping_it_in_the_family : public AchievementCriteriaScript
{
public:
    achievement_keeping_it_in_the_family() : AchievementCriteriaScript("achievement_keeping_it_in_the_family") { }

    bool OnCheck(Player* /*source*/, Unit* target) override
    {
        InstanceScript* instance = target->GetInstanceScript();
        if (!instance)
            return false;

        return instance->GetData(DATA_NEFARIAN_ACHIEVEMENT_STATE);
    }
};

void AddSC_boss_nefarians_end()
{
    RegisterBlackwingDescentCreatureAI(boss_nefarians_end);
    RegisterBlackwingDescentCreatureAI(npc_nefarians_end_onyxia);
    RegisterBlackwingDescentCreatureAI(npc_nefarians_end_lord_victor_nefarius);
    RegisterBlackwingDescentCreatureAI(npc_nefarians_end_animated_bone_warrior);
    RegisterBlackwingDescentCreatureAI(npc_nefarians_end_chromatic_prototype);
    RegisterBlackwingDescentCreatureAI(npc_nefarians_end_shadowblaze);
    RegisterSpellScript(spell_nefarians_end_electrical_charge);
    RegisterSpellScript(spell_nefarians_end_lightning_discharge_triggered_periodic_aura);
    RegisterSpellScript(spell_nefarians_end_lightning_discharge_cone);
    RegisterSpellScript(spell_nefarians_end_lightning_discharge_damage);
    RegisterSpellScript(spell_nefarians_end_children_of_deathwing);
    RegisterSpellScript(spell_nefarians_end_animate_bones);
    RegisterSpellScript(spell_nefarians_end_animate_bones_dummy);
    RegisterSpellScript(spell_nefarians_end_shadowflame_breath);
    RegisterSpellScript(spell_nefarians_end_jump_down_to_platform);
    RegisterSpellScript(spell_nefarians_end_shadow_of_cowardice);
    RegisterSpellScript(spell_nefarians_end_onyxia_start_fight_2_effect);
    RegisterSpellScript(spell_nefarians_end_empowering_strikes);
    RegisterSpellScript(spell_nefarians_end_brushfire_pre_start_periodic);
    RegisterSpellScript(spell_nefarians_end_brushfire_start);
    RegisterSpellScript(spell_nefarians_end_brushfire_growth);
    RegisterSpellScript(spell_nefarians_end_shadowblaze);
    RegisterSpellScript(spell_nefarians_end_dominion_dummy);
    RegisterSpellScript(spell_nefarians_end_dominion);
    RegisterSpellScript(spell_nefarians_end_determine_farthest_portal_stalker);
    RegisterSpellScript(spell_nefarians_end_dominion_portal_trigger);
    RegisterSpellScript(spell_nefarians_end_free_your_mind);
    RegisterSpellScript(spell_nefarians_end_siphon_power);
    RegisterSpellScript(spell_nefarians_end_explosive_cinders);
    RegisterGameObjectAI(go_nefarians_end_orb_of_culmination);
    new achievement_keeping_it_in_the_family();
}
