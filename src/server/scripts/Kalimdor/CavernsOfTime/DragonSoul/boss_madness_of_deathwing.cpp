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

#include "dragon_soul.h"
#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "GameObject.h"
#include "Group.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "SpellMgr.h"
#include "Spell.h"
#include "TemporarySummon.h"
#include "Vehicle.h"

#include <array>

enum Texts
{
    // Deathwing
    SAY_AGGRO                           = 0,
    SAY_ANNOUNCE_ASSAULT_ASPECTS        = 1,
    SAY_ANNOUNCE_ASSAULT_YSERA          = 2,
    SAY_ANNOUNCE_ASSAULT_KALECGOS       = 3,
    SAY_ANNOUNCE_ASSAULT_NOZDORMU       = 4,
    SAY_ANNOUNCE_ASSAULT_ALEXSTRASZA    = 5,
    SAY_ANNOUNCE_CATACLYSM              = 6,
    SAY_ANNOUNCE_HEMORRHAGE             = 7,
    SAY_ANNOUNCE_ELEMENTIUM_BOLT        = 8,
    SAY_ELEMENTIUM_BOLT                 = 9,
    SAY_SLUMP                           = 10,
    SAY_ANNOUNCE_SLUMP                  = 11,

    // Limb Tentacles
    SAY_ANNOUNCE_BLISTERING_TENTACLES   = 0,

    // Dragon Aspects
    SAY_INTRODUCE_ABILITY               = 0,
    SAY_CATACLYSM                       = 1,
    SAY_PHASE_TWO                       = 2,
    SAY_CHARGE_DRAGON_SOUL              = 3,

    // Thrall
    SAY_PRE_FIGHT                       = 0,
    SAY_AID_CHAMPIONS                   = 1
};

enum Spells
{
    // Deathwing
    SPELL_ROOT                                          = 105451,
    SPELL_SHARE_HEALTH_1                                = 109547,
    SPELL_SHARE_HEALTH_2                                = 109548,
    SPELL_TRIGGER_ASPECT_BUFFS                          = 106943,
    SPELL_ASSAULT_ASPECTS                               = 107018,
    SPELL_FACE_TRIGGER                                  = 106513,
    SPELL_FACE_MID_LEFT                                 = 106510,
    SPELL_FACE_MID_RIGHT                                = 106511,
    SPELL_FACE_RIGHT                                    = 106512,
    SPELL_FACE_LEFT                                     = 106509,
    SPELL_SUMMON_TAIL                                   = 106239,
    SPELL_CATACLYSM                                     = 106523,
    SPELL_CATACLYSM_VISUAL                              = 106538,
    SPELL_HEMORRHAGE_SUMMON_TARGET                      = 105853,
    SPELL_REGENERATIVE_BLOOD_PERIODIC                   = 105932,
    SPELL_REGENERATIVE_BLOOD_SCRIPT                     = 105934,
    SPELL_REGENERATIVE_BLOOD_HEAL                       = 105937,
    SPELL_ELEMENTIUM_BOLT                               = 105651,
    SPELL_SLUMP                                         = 106708,
    SPELL_CORRUPTED_BLOOD_STACKER                       = 106843,
    SPELL_SUMMON_ELEMENTIUM_TERROR                      = 106765,
    SPELL_SUMMON_IMPALING_TENTACLE                      = 106775,
    SPELL_SHRAPNEL_PERIODIC                             = 106818,
    SPELL_SLUMP_OUTRO                                   = 110062,
    SPELL_DEATH                                         = 110101,
    SPELL_DEATHWING_KILL_CREDIT                         = 111533,
    SPELL_TIME_ZONE_PHASE_TWO                           = 106761,

    // Limb Tentacle
    SPELL_LIMB_EMERGE_VISUAL                            = 107991,
    SPELL_AGONIZING_PAIN                                = 106548,
    SPELL_TRIGGER_CONCENTRATION                         = 106940,
    SPELL_BURNING_BLOOD                                 = 105401,
    SPELL_SPAWN_BLISTERING_TENTACLES                    = 105551,

    // Mutated Corruption
    SPELL_CRUSH_TARGETING                               = 106382,
    SPELL_CRUSH                                         = 106385,
    SPELL_IMPALE                                        = 106400,

    // Hemorrhage Target
    SPELL_HEMORRHAGE_PERIODIC                           = 105861,

    // Regenerative Blood
    SPELL_DEGENERATIVE_BITE                             = 105842,

    // Elementium Bolt
    SPELL_ELEMENTIUM_METEOR_VISUAL                      = 106242,
    SPELL_ELEMENTIUM_BLAST                              = 105723,
    SPELL_ELEMENTIUM_BLAST_PERIODIC                     = 110628,
    SPELL_ELEMENTIUM_METEOR_TRANSFORM                   = 106991,
    SPELL_ELEMENTIUM_METEOR_TRANSFORM_DEATH             = 110663,

    // Claw Mark
    SPELL_CLAW_MARK                                     = 106273,

    // Elementium Fragment
    SPELL_SHRAPNEL                                      = 106791,

    // Thrall
    SPELL_ASTRAL_RECALL                                 = 108537,
    SPELL_ASTRAL_RECALL_OUTRO                           = 110063,
    SPELL_FIRE_DRAGON_SOUL_ASPECTS                      = 110067,
    SPELL_TRIGGER_ASPECT_YELL                           = 109708,
    SPELL_FIRE_DRAGON_SOUL                              = 109971,
    SPELL_PLAY_MOVIE                                    = 107000,

    // Dragon Aspects
    SPELL_TIME_ZONE                                     = 106919,
    SPELL_TIME_ZONE_MISSILE                             = 105799,
    SPELL_TIME_ZONE_MISSILE_PHASE_TWO                   = 107055,
    SPELL_CAUTERIZE                                     = 105565,
    SPELL_CONCENTRATION_KALECGOS                        = 106644,
    SPELL_CONCENTRATION_YSERA                           = 106643,
    SPELL_CONCENTRATION_ALEXSTRASZA                     = 106641,
    SPELL_CONCENTRATION_NOZDORMU                        = 106642,
    SPELL_CONCENTRATION_KALECGOS_OUTRO                  = 110072,
    SPELL_CONCENTRATION_YSERA_OUTRO                     = 110077,
    SPELL_CONCENTRATION_ALEXSTRASZA_OUTRO               = 110071,
    SPELL_CONCENTRATION_NOZDORMU_OUTRO                  = 110076,
    SPELL_YSERAS_PRESENCE                               = 106456,
    SPELL_THE_DREAMER                                   = 106463,
    SPELL_KALECGOS_PRESENCE                             = 106026,
    SPELL_SPELLWEAVER                                   = 106039,
    SPELL_NOZDORMUS_PRESENCE                            = 105823,
    SPELL_ALEXSTRASZAS_PRESENCE                         = 105825,

    // Cosmetic Limbs
    SPELL_SUMMON_COSMETIC_TENTACLE                      = 108970,

    // Jump Pad
    SPELL_CARRYING_WINDS_JUMP_YSERA_TO_NOZDORMU         = 106673,
    SPELL_CARRYING_WINDS_JUMP_YSERA_TO_KALECGOS         = 106675,
    SPELL_CARRYING_WINDS_JUMP_NOZDORMU_TO_ALEXSTRASZA   = 106669,
    SPELL_CARRYING_WINDS_JUMP_NOZDORMU_TO_YSERA         = 106671,
    SPELL_CARRYING_WINDS_JUMP_KALECGOS_TO_YSERA         = 106677,
    SPELL_CARRYING_WINDS_JUMP_ALEXSTRASZA_TO_NOZDORMU   = 106666,

    // Player
    SPELL_CARRYING_WINDS_DUMMY_YSERA_TO_NOZDORMU        = 106672,
    SPELL_CARRYING_WINDS_DUMMY_YSERA_TO_KALECGOS        = 106674,
    SPELL_CARRYING_WINDS_DUMMY_NOZDORMU_TO_ALEXSTRASZA  = 106668,
    SPELL_CARRYING_WINDS_DUMMY_NOZDORMU_TO_YSERA        = 106670,
    SPELL_CARRYING_WINDS_DUMMY_KALECGOS_TO_YSERA        = 106676,
    SPELL_CARRYING_WINDS_DUMMY_ALEXSTRASZA_TO_NOZDORMU  = 106663
};

#define SPELL_TETANUS               RAID_MODE<uint32>(106730, 109603, 109604, 109605)
#define SPELL_DEGENERATIVE_BITE     RAID_MODE<uint32>(105841, 109625, 109626, 109627)

enum Events
{
    // Deathwing
    EVENT_ASSAULT_ASPECTS = 1,
    EVENT_FACE_PLATFORM,
    EVENT_SEND_ENCOUNTER_FRAME,
    EVENT_SUMMON_TAIL,
    EVENT_CATACLYSM,
    EVENT_HEMORRHAGE,
    EVENT_REGENERATIVE_BLOOD,
    EVENT_ELEMENTIUM_BOLT,
    EVENT_SUMMON_ELEMENTIUM_TERROR,
    EVENT_SUMMON_ELEMENTIUM_FRAGMENTS,
    EVENT_PREPARE_TIME_ZONE,
    EVENT_DISENGAGE,

    // Mutated Corruption
    EVENT_CRUSH_TARGETING,
    EVENT_CRUSH,
    EVENT_IMPALE,

    // Elemetium Bolt
    EVENT_LAUNCH_ELEMENTIUM_BOLT,
    EVENT_ELEMENTUIM_BLAST,

    // Dragon Aspects
    EVENT_TIME_ZONE,
    EVENT_TIME_ZONE_PHASE_TWO,
    EVENT_CAUTERIZE,
    EVENT_TALK_PHASE_TWO,
    EVENT_TALK_CHARGE_DRAGON_SOUL,

    // Thrall
    EVENT_FACE_TOWARDS_DEATHWING,
    EVENT_TALK_AID_CHAMPIONS,
    EVENT_FIRE_DRAGON_SOUL,
    EVENT_PLAY_MOVIE
};

enum Actions
{
    // Deathwing
    ACTION_ASSAULT_PLATFORM         = 0,
    ACTION_LIMB_TENTACLE_DAMAGED    = 1,
    ACTION_DEATH                    = 2,

    // Dragon Aspects
    ACTION_ASSAULTED                = 0,
    ACTION_LIMB_KILLED              = 1,
    ACTION_CATACLYSM_IN_PROGRESS    = 2,
    ACTION_CREATE_TIME_ZONE         = 3,
    ACTION_CAUTERIZE                = 4,
    ACTION_TALK_PHASE_TWO           = 5,
    ACTION_TALK_CHARGE_DRAGON_SOUL  = 6,
    ACTION_CAST_TIME_ZONE           = 7,

    // Elemetium Bolt
    ACTION_LAUNCH_ELEMENTIUM_BOLT   = 0,

    // Thrall
    ACTION_TALK_ASPECT_AID          = 0,
    ACTION_FIRE_DRAGON_SOUL         = 1
};

enum Phases
{
    PHASE_ONE   = 1,
    PHASE_TWO   = 2,
    PHASE_OUTRO = 3
};

enum AreaTriggers
{
    AT_JUMP_YSERA_TO_KALECGOS       = 7114,
    AT_JUMP_KALECGOS_TO_YSERA       = 7115,
    AT_JUMP_YSERA_TO_NOZDORMU       = 7113,
    AT_JUMP_NOZDORMU_TO_YSERA       = 7112,
    AT_JUMP_NOZDORMU_TO_ALEXSTRASZA = 7111,
    AT_JUMP_ALEXSTRASZA_TO_NOZDORMU = 7110,

    AT_LAND_NOZDORMU_TO_ALEXSTRASZA = 7315,
    AT_LAND_ALEXSTRASZA_TO_NOZDORMU = 7316,
    AT_LAND_YSERA_TO_NOZDORMU       = 7317,
    AT_LAND_NOZDORMU_TO_YSERA       = 7318,
    AT_LAND_KALECGOS_TO_YSERA       = 7319,
    AT_LAND_YSERA_TO_KALECGOS       = 7320
};

enum AnimKits
{
    // Deathwing
    ANIM_KIT_EMERGE_DEATHWING           = 1792,

    // Mutated Corruption
    ANIM_KIT_EMERGE_MUTATED_CORRUPTION  = 1703,
    ANIM_KIT_CRUSH                      = 1711,

    // Tail Tentacle
    ANIM_KIT_SUBMERGE                   = 1704
};

enum SpellVisualKits
{
    // Limb Tentacles
    SPELL_VISUAL_KIT_LIMB_EMERGE_1  = 22447,
    SPELL_VISUAL_KIT_LIMB_EMERGE_2  = 22449,
    SPELL_VISUAL_KIT_LIMB_EMERGE_3  = 22446
};

enum EncounterFrames
{
    ENCOUNTER_FRAME_INDEX_DEATHWING             = 1,
    ENCOUNTER_FRAME_INDEX_MUTATED_CORRUPTION    = 1,
    ENCOUNTER_FRAME_INDEX_LIMB_TENTACLE         = 2
};

enum Gossips
{
    // Thrall
    GOSSIP_MENU_START_ENCOUNTER = 13295
};

enum Sounds
{
    // Deathwing
    SOUND_ID_DRAGON_ROAR    = 26348,

    // Thrall
    MUSIC_ID_OUTRO          = 26600
};

enum Data
{
    // Deathwing
    DATA_PLAYERS_ON_PLATFORM    = 0,
    DATA_ASSAULTED_ASPECT       = 1,
    DATA_CURRENT_LIMB           = 2,
    DATA_CURRENT_PLATFORM       = 3,
    DATA_NOZDORMU_AVAILABLE     = 4,
    DATA_ASPECT_FOR_LIMB        = 5,

    // Dragon Aspects
    DATA_FOCUSED_LIMB           = 0
};

enum Seats
{
    // Deathwing
    SEAT_ID_ELEMENTIUM_BOLT = 2,

    // Claw Mark
    SEAT_ID_CLAW_MARK       = 0
};

enum MovePoints
{
    // Elementium Bolt
    POINT_ID_ELEMENTIUM_BOLT_1  = 1,
    POINT_ID_ELEMENTIUM_BOLT_2  = 2,

    // Dragon Aspects
    POINT_ID_CONCENTRATION      = 1
};

enum PhaseGroups
{
    PHASE_GROUP_ENCOUNTER_1 = 374
};

// Using own types to avoid order dependencies in header file
enum DragonAspectForLimb
{
    DRAGON_ASPECT_YSERA        = 0,
    DRAGON_ASPECT_KALECGOS     = 1,
    DRAGON_ASPECT_NOZDORMU     = 2,
    DRAGON_ASPECT_ALEXSTRASZA  = 3,
    MAX_DRAGON_ASPECTS
};

struct LimbTentacleInfo
{
    ObjectGuid TentacleGUID;
    ObjectGuid PlatformGUID;
    bool TentacleEngaged = false;
    bool TentacleKilled = false;
};

typedef std::array<LimbTentacleInfo, MAX_DRAGON_ASPECTS> LimbTentacleData;

Position const DeathwingSummonPositon = { -11903.93f, 11989.14f, -113.204f, 2.164208f };
Position const TailTentacleSummonPosition = { -11857.02f, 11795.57f, -73.95494f, 2.234021f };
Position const ElementiumFragmentSummonPosition = { -12100.54f, 12173.62f, -2.734246f, 5.096362f };
QuaternionData const ElementiumFragmentRotation = { 0.f, 0.f, -0.5591927f, 0.8290377f };

std::array<Position const, MAX_DRAGON_ASPECTS> LimbTentacleSummonPositions =
{
    Position(-12065.03f, 12127.18f, -3.294598f, 2.338741f),
    Position(-12097.79f, 12067.37f, 13.48882f, 2.216568f),
    Position(-12005.8f, 12190.35f, -6.593992f, 2.129302f),
    Position(-11941.15f, 12248.89f, 12.14991f, 1.989675f)
};

std::array<Position const, MAX_DRAGON_ASPECTS> PlatformForAspectReferencePositions =
{
    Position(-12098.29f, 12160.51f),
    Position(-12126.18f, 12076.84f),
    Position(-12036.16f, 12220.41f),
    Position(-11959.66f, 12271.25f)
};

std::array<uint32, MAX_DRAGON_ASPECTS> LimbTentacleEntryForDragonAspect =
{
    NPC_ARM_TENTACLE_1,
    NPC_WING_TENTACLE,
    NPC_ARM_TENTACLE_2,
    NPC_WING_TENTACLE
};

static constexpr uint8 const MaxElemetiumBoltPathPoints = 2;
std::array<Position, MaxElemetiumBoltPathPoints> ElementiumBoltPathYsera =
{
    Position(-12087.66f, 12152.32f, 2.34034f),
    Position(-12103.51f, 12164.05f, 0.3335648f)
};

std::array<Position, MaxElemetiumBoltPathPoints> ElementiumBoltPathNozdormu =
{
    Position(-12025.88f, 12206.73f, -0.640686f),
    Position(-12035.51f, 12223.88f, -3.067535f)
};

std::array<Position, MaxElemetiumBoltPathPoints> ElementiumBoltPathAlexstrasza =
{
    Position(-11956.88f, 12258.96f, 5.361959f),
    Position(-11959.26f, 12278.64f, 4.414875f)
};

std::array<Position, MaxElemetiumBoltPathPoints> ElementiumBoltPathKalecgos =
{
    Position(-12110.38f, 12074.37f, 6.96521f),
    Position(-12138.4f, 12080.39f, 5.359306f)
};

Movement::PointsArray YseraPath =
{
    { -12108.63f, 12175.13f, 61.51709f },
    { -12091.56f, 12151.19f, 61.51709f },
    { -12088.4f, 12130.21f, 70.17785f }
};

Movement::PointsArray KalecgosPath =
{
    { -12089.22f, 12073.72f, 57.31396f },
    { -12042.77f, 12021.11f, 57.31396f },
    { -12059.66f, 11976.04f, 57.31396f }
};

Movement::PointsArray NozdormuPath =
{
    { -12035.02f, 12225.6f, 62.73143f },
    { -12021.92f, 12179.42f, 83.76831f }
};

Movement::PointsArray AlexstraszaPath =
{
    {-11958.91f, 12276.78f, 54.98875f },
    {-11911.33f, 12205.85f, 54.98875f },
    {-11865.57f, 12193.88f, 54.98875f }
};

struct boss_madness_of_deathwing : public BossAI
{
    boss_madness_of_deathwing(Creature* creature) : BossAI(creature, DATA_MADNESS_OF_DEATHWING), _firstAssault(true), _assaultedDragonAspect(0), _aspectForKilledTentacle(0)
    {
        me->SetReactState(REACT_PASSIVE);
        _playersAtAspects = { };
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_ROOT);
        DoZoneInCombat();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        DoSummon(NPC_TAIL_TENTACLE, TailTentacleSummonPosition, 0, TEMPSUMMON_MANUAL_DESPAWN);

        Talk(SAY_AGGRO);
        SetupLimbs();
        DoCastSelf(SPELL_SHARE_HEALTH_1);
        me->PlayOneShotAnimKitId(ANIM_KIT_EMERGE_DEATHWING);

        events.SetPhase(PHASE_ONE);
        events.ScheduleEvent(EVENT_ASSAULT_ASPECTS, 5s, 0, PHASE_ONE);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();

        DespawnLimbs();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        if (Creature* deathwing = GetPhaseTwoDeathwing())
        {
            deathwing->InterruptNonMeleeSpells(true);
            if (!deathwing->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE))
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, deathwing);
        }

        if (Creature* thrall = instance->GetCreature(DATA_THRALL_MADNESS_OF_DEATHWING))
            thrall->DespawnOrUnsummon(0ms, 30s);

        for (ObjectGuid guid : _mutatedCorruptionGUIDs)
            if (Creature* corruption = ObjectAccessor::GetCreature(*me, guid))
                if (corruption->IsAIEnabled)
                    corruption->AI()->EnterEvadeMode();

        for (uint8 i = 0; i < MAX_DRAGON_ASPECTS; i++)
            if (Creature* aspect = GetDragonAspect(i))
                aspect->DespawnOrUnsummon(0ms, 30s);

        summons.DespawnAll();
        _DespawnAtEvade();
    }

    void JustSummoned(Creature* summon) override
    {
        switch (summon->GetEntry())
        {
            case NPC_ARM_TENTACLE_1:
            case NPC_ARM_TENTACLE_2:
            case NPC_WING_TENTACLE:
            case NPC_DEATHWING_MADNESS_OF_DEATHWING:
                break;
            case NPC_MUTATED_CORRUPTION:
                _mutatedCorruptionGUIDs.push_back(summon->GetGUID());
                break;
            case NPC_TAIL_TENTACLE:
                summon->PlayOneShotAnimKitId(ANIM_KIT_EMERGE_MUTATED_CORRUPTION); // no idea what blizz has fucked up here
                summons.Summon(summon);
                break;
            case NPC_HEMORRHAGE_TARGET:
                summon->CastSpell(summon, SPELL_HEMORRHAGE_PERIODIC);
                summons.Summon(summon);
                break;
            case NPC_ELEMENTIUM_BOLT:
                summon->EnterVehicle(me, SEAT_ID_ELEMENTIUM_BOLT);
                summons.Summon(summon);
                break;
            default:
                summons.Summon(summon);
                break;
        }
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        switch (summon->GetEntry())
        {
            case NPC_ARM_TENTACLE_1:
            case NPC_ARM_TENTACLE_2:
            case NPC_WING_TENTACLE:
                LimbTentacleDied(summon);
                break;
            default:
                break;
        }
    }

    void SetData(uint32 type, uint32 data) override
    {
        if (type < DATA_PLAYERS_ON_PLATFORM + MAX_DRAGON_ASPECTS)
        {
            uint8 dragonAspect = std::max<uint8>(0, type - DATA_PLAYERS_ON_PLATFORM);
            _playersAtAspects[dragonAspect] = data;
        }
    }

    uint32 GetData(uint32 type) const override
    {
        switch (type)
        {
            case DATA_ASSAULTED_ASPECT:
                return _assaultedDragonAspect;
            case DATA_NOZDORMU_AVAILABLE:
                return uint8(!_limbData[DRAGON_ASPECT_NOZDORMU].TentacleKilled);
            case DATA_ASPECT_FOR_LIMB:
                return _aspectForKilledTentacle;
            default:
                return 0;
        }

        return 0;
    }

    ObjectGuid GetGUID(int32 type) const override
    {
        switch (type)
        {
            case DATA_CURRENT_LIMB:
                return _limbData[_assaultedDragonAspect].TentacleGUID;
            case DATA_CURRENT_PLATFORM:
                return _limbData[_assaultedDragonAspect].PlatformGUID;
            default:
                return ObjectGuid::Empty;
        }

        return ObjectGuid::Empty;
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        // Deathwing does not really die
        if (damage >= me->GetHealth())
            damage = me->GetHealth() - 1;

        if (!events.IsInPhase(PHASE_OUTRO) && me->HealthBelowPctDamaged(1, damage))
        {
            events.SetPhase(PHASE_OUTRO);
            StartDeathSequence();
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_ASSAULT_PLATFORM:
            {
                int8 preferedAspect = -1;
                int8 lastCheckedPlatform = -1;
                for (uint8 i = 0; i < MAX_DRAGON_ASPECTS; ++i)
                {
                    // Limb has been killed already. Skip Platform.
                    if (_limbData[i].TentacleKilled)
                        continue;

                    if (preferedAspect == -1 || _playersAtAspects[i] > _playersAtAspects[lastCheckedPlatform])
                        preferedAspect = i;

                    lastCheckedPlatform = i;
                }

                // This should never happen but just in case
                if (preferedAspect == -1)
                    return;

                AssaultAspect(preferedAspect);
                break;
            }
            case ACTION_LIMB_TENTACLE_DAMAGED:
                if (!_limbData[DRAGON_ASPECT_ALEXSTRASZA].TentacleKilled)
                    if (Creature* alexstrasza = GetDragonAspect(DRAGON_ASPECT_ALEXSTRASZA))
                        if (alexstrasza->IsAIEnabled)
                            alexstrasza->AI()->DoAction(ACTION_CAUTERIZE);
                break;
            case ACTION_DEATH:
                me->PlayDirectSound(SOUND_ID_DRAGON_ROAR);
                DoCastSelf(SPELL_DEATH);
                events.ScheduleEvent(EVENT_DISENGAGE, 9s, 0, PHASE_OUTRO);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!events.IsInPhase(PHASE_OUTRO))
            if (!UpdateVictim())
                return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ASSAULT_ASPECTS:
                    if (_firstAssault)
                    {
                        DoCastSelf(SPELL_SHARE_HEALTH_1);
                        DoCastAOE(SPELL_TRIGGER_ASPECT_BUFFS);
                        events.ScheduleEvent(EVENT_FACE_PLATFORM, 18s, 0, PHASE_ONE);
                        events.ScheduleEvent(EVENT_SEND_ENCOUNTER_FRAME, 11s, 0, PHASE_ONE);
                        events.ScheduleEvent(EVENT_CATACLYSM, 1min + 55s, 0, PHASE_ONE);
                        events.ScheduleEvent(EVENT_HEMORRHAGE, 1min + 26s, 0, PHASE_ONE);
                        events.ScheduleEvent(EVENT_ELEMENTIUM_BOLT, 41s, 0, PHASE_ONE);
                        _firstAssault = false;
                    }
                    else
                    {
                        events.ScheduleEvent(EVENT_FACE_PLATFORM, 14s, 0, PHASE_ONE);
                        events.ScheduleEvent(EVENT_CATACLYSM, 2min + 13s, 0, PHASE_ONE);
                        events.ScheduleEvent(EVENT_HEMORRHAGE, 1min + 43s, 0, PHASE_ONE);
                        events.ScheduleEvent(EVENT_ELEMENTIUM_BOLT, 58s, 0, PHASE_ONE);
                    }

                    DoCastAOE(SPELL_ASSAULT_ASPECTS);
                    Talk(SAY_ANNOUNCE_ASSAULT_ASPECTS);
                    break;
                case EVENT_FACE_PLATFORM:
                {
                    int32 facingSpellID = 0;
                    switch (_assaultedDragonAspect)
                    {
                        case DRAGON_ASPECT_YSERA:
                            facingSpellID = SPELL_FACE_MID_LEFT;
                            break;
                        case DRAGON_ASPECT_KALECGOS:
                            facingSpellID = SPELL_FACE_LEFT;
                            break;
                        case DRAGON_ASPECT_NOZDORMU:
                            facingSpellID = SPELL_FACE_MID_RIGHT;
                            break;
                        case DRAGON_ASPECT_ALEXSTRASZA:
                            facingSpellID = SPELL_FACE_RIGHT;
                            break;
                        default:
                            break;
                    }

                    me->CastSpell(me, SPELL_FACE_TRIGGER, { SPELLVALUE_BASE_POINT0, facingSpellID });

                    // Nozdormu creates a time zone at the same moment when Deathwing faces a platform
                    if (!_limbData[DRAGON_ASPECT_NOZDORMU].TentacleKilled)
                        if (Creature* nozdormu = GetDragonAspect(DRAGON_ASPECT_NOZDORMU))
                            if (nozdormu->IsAIEnabled)
                                nozdormu->AI()->DoAction(ACTION_CREATE_TIME_ZONE);
                    break;
                }
                case EVENT_SEND_ENCOUNTER_FRAME:
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, ENCOUNTER_FRAME_INDEX_DEATHWING);
                    break;
                case EVENT_SUMMON_TAIL:
                    DoCastSelf(SPELL_SUMMON_TAIL);
                    break;
                case EVENT_CATACLYSM:
                    Talk(SAY_ANNOUNCE_CATACLYSM);
                    DoCastAOE(SPELL_CATACLYSM);
                    if (Creature* aspect = GetDragonAspect(_assaultedDragonAspect))
                        if (aspect->IsAIEnabled)
                            aspect->AI()->DoAction(ACTION_CATACLYSM_IN_PROGRESS);
                    break;
                case EVENT_HEMORRHAGE:
                    Talk(SAY_ANNOUNCE_HEMORRHAGE);
                    DoCastAOE(SPELL_HEMORRHAGE_SUMMON_TARGET);
                    events.ScheduleEvent(EVENT_REGENERATIVE_BLOOD, 2s + 500ms, 0, PHASE_ONE);
                    break;
                case EVENT_REGENERATIVE_BLOOD:
                    DoCastSelf(SPELL_REGENERATIVE_BLOOD_PERIODIC);
                    break;
                case EVENT_ELEMENTIUM_BOLT:
                    Talk(SAY_ANNOUNCE_ELEMENTIUM_BOLT);
                    Talk(SAY_ELEMENTIUM_BOLT);
                    DoCastSelf(SPELL_ELEMENTIUM_BOLT);
                    break;
                case EVENT_SUMMON_ELEMENTIUM_TERROR:
                    if (Creature* deathwing = GetPhaseTwoDeathwing())
                        deathwing->CastSpell(deathwing, SPELL_SUMMON_ELEMENTIUM_TERROR);
                    break;
                case EVENT_SUMMON_ELEMENTIUM_FRAGMENTS:
                    if (Creature* deathwing = GetPhaseTwoDeathwing())
                        deathwing->CastSpell(deathwing, SPELL_SUMMON_IMPALING_TENTACLE);
                    break;
                case EVENT_PREPARE_TIME_ZONE:
                    DoCastSelf(SPELL_TIME_ZONE_PHASE_TWO);
                    if (Creature* nozdormu = GetDragonAspect(DRAGON_ASPECT_NOZDORMU))
                        if (nozdormu->IsAIEnabled)
                            nozdormu->AI()->DoAction(ACTION_CAST_TIME_ZONE);
                    break;
                case EVENT_DISENGAGE:
                    summons.DespawnAll();
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                    me->DespawnOrUnsummon();
                    break;
                default:
                    break;
            }
        }
    }

private:
    bool _firstAssault;
    uint8 _assaultedDragonAspect;
    uint8 _aspectForKilledTentacle;
    LimbTentacleData _limbData;
    std::array<uint8, MAX_DRAGON_ASPECTS> _playersAtAspects;
    GuidVector _mutatedCorruptionGUIDs;

    void SetupLimbs()
    {
        for (uint8 i = 0; i < MAX_DRAGON_ASPECTS; ++i)
        {
            if (Creature* limb = DoSummon(LimbTentacleEntryForDragonAspect[i], LimbTentacleSummonPositions[i], 0, TEMPSUMMON_MANUAL_DESPAWN))
            {
                _limbData[i].TentacleGUID = limb->GetGUID();

                if (Creature* platform = limb->FindNearestCreature(NPC_PLATFORM, 55.f))
                    _limbData[i].PlatformGUID = platform->GetGUID();
            }
        }
    }

    void DespawnLimbs()
    {
        for (uint8 i = 0; i < MAX_DRAGON_ASPECTS; ++i)
        {
            if (Creature* limb = ObjectAccessor::GetCreature(*me, _limbData[i].TentacleGUID))
            {
                if (_limbData[i].TentacleEngaged)
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, limb);

                limb->DespawnOrUnsummon();
            }
        }
    }

    Creature* GetDragonAspect(uint8 aspectId)
    {
        uint32 type = 0;
        switch (aspectId)
        {
            case DRAGON_ASPECT_YSERA:
                type = DATA_YSERA_MADNESS_OF_DEATHWING;
                break;
            case DRAGON_ASPECT_KALECGOS:
                type = DATA_KALECGOS_MADNESS_OF_DEATHWING;
                break;
            case DRAGON_ASPECT_NOZDORMU:
                type = DATA_NOZDORMU_MADNESS_OF_DEATHWING;
                break;
            case DRAGON_ASPECT_ALEXSTRASZA:
                type = DATA_ALEXSTRASZA_MADNESS_OF_DEATHWING;
                break;
            default:
                break;
        }

        return instance->GetCreature(type);
    }

    Creature* GetPhaseTwoDeathwing()
    {
        return instance->GetCreature(DATA_DEATHWING_MADNESS_OF_DEATHWING);
    }

    void AssaultAspect(uint8 aspectId)
    {
        uint8 announcementTextID = 0;
        switch (aspectId)
        {
            case DRAGON_ASPECT_YSERA:
                announcementTextID = SAY_ANNOUNCE_ASSAULT_YSERA;
                break;
            case DRAGON_ASPECT_KALECGOS:
                announcementTextID = SAY_ANNOUNCE_ASSAULT_KALECGOS;
                break;
            case DRAGON_ASPECT_NOZDORMU:
                announcementTextID = SAY_ANNOUNCE_ASSAULT_NOZDORMU;
                break;
            case DRAGON_ASPECT_ALEXSTRASZA:
                announcementTextID = SAY_ANNOUNCE_ASSAULT_ALEXSTRASZA;
                break;
            default:
                break;
        }

        _assaultedDragonAspect = aspectId;
        Talk(announcementTextID);

        if (Creature* aspect = GetDragonAspect(aspectId))
            if (aspect->IsAIEnabled)
                aspect->AI()->DoAction(ACTION_ASSAULTED);

        if (Creature* limb = ObjectAccessor::GetCreature(*me, _limbData[aspectId].TentacleGUID))
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, limb, ENCOUNTER_FRAME_INDEX_LIMB_TENTACLE);
            _limbData[aspectId].TentacleEngaged = true;
        }

        events.ScheduleEvent(EVENT_SUMMON_TAIL, 500ms);
    }

    void LimbTentacleDied(Creature* limb)
    {
        for (uint8 i = 0; i < MAX_DRAGON_ASPECTS; ++i)
        {
            if (limb->GetGUID() != _limbData[i].TentacleGUID)
                continue;

            // Mark tentacle as defeated
            _limbData[i].TentacleKilled = true;
            _aspectForKilledTentacle = i;

            // Trigger concentration
            limb->CastSpell(limb, SPELL_TRIGGER_CONCENTRATION);

            // Send disengage encounter frame packet in case it has been engaged before it got killed
            bool engaged = _limbData[i].TentacleEngaged;
            InstanceScript* ins = instance;
            limb->m_Events.AddEventAtOffset([limb, engaged, ins]()
            {
                if (engaged)
                    ins->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, limb);

                limb->DespawnOrUnsummon();
            }, 3s + 600ms);

            // Despawn time zones
            summons.DespawnEntry(NPC_TIME_ZONE);

            // Clean up auras
            for (uint32 spellId : { SPELL_FACE_LEFT, SPELL_FACE_MID_LEFT, SPELL_FACE_MID_RIGHT, SPELL_FACE_RIGHT, SPELL_REGENERATIVE_BLOOD_PERIODIC })
                me->RemoveAurasDueToSpell(spellId);

            // Cancel pending events
            events.CancelEvent(EVENT_CATACLYSM);
            events.CancelEvent(EVENT_HEMORRHAGE);
            events.CancelEvent(EVENT_ELEMENTIUM_BOLT);
            events.CancelEvent(EVENT_FACE_PLATFORM);

            // Prepare our next assault
            events.ScheduleEvent(EVENT_ASSAULT_ASPECTS, 6s + 500ms, 0, PHASE_ONE);

            // Clean up our summon list to reduce performance impact
            summons.RemoveNotExisting();
        }

        uint8 destroyedLimbs = 0;
        for (uint8 i = 0; i < MAX_DRAGON_ASPECTS; ++i)
            if (_limbData[i].TentacleKilled)
                ++destroyedLimbs;

        if (destroyedLimbs >= 4)
        {
            summons.DespawnEntry(NPC_COSMETIC_TENTACLE);
            me->RemoveAurasDueToSpell(SPELL_AGONIZING_PAIN);
            DoCastSelf(SPELL_SLUMP);
            DoCastAOE(SPELL_TRIGGER_ASPECT_BUFFS);
            Talk(SAY_SLUMP);
            Talk(SAY_ANNOUNCE_SLUMP);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

            if (Creature* deathwing = GetPhaseTwoDeathwing())
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, deathwing, ENCOUNTER_FRAME_INDEX_DEATHWING);
                deathwing->ResetPlayerDamageReq();
                deathwing->CastSpell(deathwing, SPELL_CORRUPTED_BLOOD_STACKER);
                deathwing->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            }

            uint8 aspectID = urand(DRAGON_ASPECT_YSERA, DRAGON_ASPECT_ALEXSTRASZA);
            if (Creature* aspect = GetDragonAspect(aspectID))
                if (aspect->IsAIEnabled)
                    aspect->AI()->DoAction(ACTION_TALK_PHASE_TWO);

            if (Creature* thrall = instance->GetCreature(DATA_THRALL_MADNESS_OF_DEATHWING))
                if (thrall->IsAIEnabled)
                    thrall->AI()->DoAction(ACTION_TALK_ASPECT_AID);

            events.SetPhase(PHASE_TWO);
            events.ScheduleEvent(EVENT_SUMMON_ELEMENTIUM_FRAGMENTS, 11s, 0, PHASE_TWO);
            events.ScheduleEvent(EVENT_PREPARE_TIME_ZONE, 26s, 0, PHASE_TWO);
            events.ScheduleEvent(EVENT_SUMMON_ELEMENTIUM_TERROR, 36s, 0, PHASE_TWO);
        }
    }

    void StartDeathSequence()
    {
        if (Creature* tail = instance->GetCreature(DATA_TAIL_TENTACLE_MADNESS_OF_DEATHWING))
            tail->PlayOneShotAnimKitId(ANIM_KIT_SUBMERGE);

        summons.DespawnEntry(NPC_ELEMENTIUM_FRAGMENT);
        summons.DespawnEntry(NPC_ELEMENTIUM_TERROR);
        summons.DespawnEntry(NPC_TIME_ZONE);
        summons.DespawnEntry(NPC_TAIL_TENTACLE);

        me->RemoveAurasDueToSpell(SPELL_SHRAPNEL_PERIODIC);
        me->PlayDirectSound(SOUND_ID_DRAGON_ROAR);
        DoCastSelf(SPELL_SLUMP_OUTRO);

        instance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_DEATHWING_KILL_CREDIT, 0, me);
        instance->instance->PermBindAllPlayers();
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TETANUS);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DEGENERATIVE_BITE);

        if (Creature* thrall = instance->GetCreature(DATA_THRALL_MADNESS_OF_DEATHWING))
            if (thrall->IsAIEnabled)
                thrall->AI()->DoAction(ACTION_FIRE_DRAGON_SOUL);

        Player* recipient = nullptr;
        if (Creature* deathwing = GetPhaseTwoDeathwing())
        {
            recipient = deathwing->GetLootRecipient();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, deathwing);
            deathwing->DespawnOrUnsummon();
        }

        if (recipient)
        {
            recipient->RewardPlayerAndGroupAtKill(me, false);

            uint32 gameobjectId = 0;
            switch (GetDifficulty())
            {
                case RAID_DIFFICULTY_10MAN_NORMAL:
                    gameobjectId = GO_ELEMENTIUM_FRAGMENT_10_NORMAL;
                    break;
                case RAID_DIFFICULTY_25MAN_NORMAL:
                    gameobjectId = GO_ELEMENTIUM_FRAGMENT_25_NORMAL;
                    if (recipient->GetGroup() && recipient->GetGroup()->isLFRGroup())
                        gameobjectId = GO_ELEMENTIUM_FRAGMENT_25_LFR;
                    break;
                case RAID_DIFFICULTY_10MAN_HEROIC:
                    gameobjectId = GO_ELEMENTIUM_FRAGMENT_10_HEROIC;
                    break;
                case RAID_DIFFICULTY_25MAN_HEROIC:
                    gameobjectId = GO_ELEMENTIUM_FRAGMENT_25_HEROIC;
                    break;
                default:
                    break;
            }

            if (gameobjectId)
                if (GameObject* fragment = me->SummonGameObject(gameobjectId, ElementiumFragmentSummonPosition, ElementiumFragmentRotation, WEEK, GO_SUMMON_TIMED_DESPAWN))
                    PhasingHandler::AddPhaseGroup(fragment, PHASE_GROUP_ENCOUNTER_1, false);
        }

        instance->SetBossState(DATA_MADNESS_OF_DEATHWING, DONE);
    }
};

struct npc_madness_of_deathwing_limb_tentacle : public NullCreatureAI
{
    npc_madness_of_deathwing_limb_tentacle(Creature* creature) : NullCreatureAI(creature), _instance(me->GetInstanceScript()), _summons(me),
        _bleeding(false), _blisteringTentacleCount(0) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_LIMB_EMERGE_VISUAL);
    }

    void JustDied(Unit* /*killer*/) override
    {
        DoCastSelf(SPELL_AGONIZING_PAIN);
        _summons.DespawnAll();
    }

    void JustSummoned(Creature* summon) override
    {
        switch (summon->GetEntry())
        {
            case NPC_BLISTERING_TENTACLE:
                if (Creature* deathwing = _instance->GetCreature(DATA_MADNESS_OF_DEATHWING))
                    deathwing->AI()->JustSummoned(summon);

                summon->CastSpell(me, VEHICLE_SPELL_RIDE_HARDCODED);
                summon->ToTempSummon()->SetTempSummonType(TEMPSUMMON_CORPSE_DESPAWN);
                _summons.Summon(summon);
                break;
            default:
                break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        // Oneshot cases
        if (damage >= me->GetHealth())
            return;

        if (!_bleeding && me->HealthBelowPctDamaged(90, damage))
        {
            DoCastSelf(SPELL_BURNING_BLOOD);
            _bleeding = true;
        }

        uint8 healthPct = 75;
        if (_blisteringTentacleCount == 1)
            healthPct = 50;
        else if (_blisteringTentacleCount == 2)
            healthPct = 25;

        if (me->HealthBelowPctDamaged(healthPct, damage) && _blisteringTentacleCount < 3)
        {
            DoCastSelf(SPELL_SPAWN_BLISTERING_TENTACLES);
            Talk(SAY_ANNOUNCE_BLISTERING_TENTACLES, me);
            ++_blisteringTentacleCount;

            if (Creature* deathwing = _instance->GetCreature(DATA_MADNESS_OF_DEATHWING))
                deathwing->AI()->DoAction(ACTION_LIMB_TENTACLE_DAMAGED);
        }
    }

private:
    InstanceScript* _instance;
    SummonList _summons;
    bool _bleeding;
    uint8 _blisteringTentacleCount;
};

struct npc_madness_of_deathwing_mutated_corruption : public ScriptedAI
{
    npc_madness_of_deathwing_mutated_corruption(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript())
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void InitializeAI() override
    {
        if (Creature* deathwing = _instance->GetCreature(DATA_MADNESS_OF_DEATHWING))
            deathwing->AI()->JustSummoned(me);
    }

    void JustAppeared() override
    {
        me->PlayOneShotAnimKitId(ANIM_KIT_EMERGE_MUTATED_CORRUPTION);
        _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, ENCOUNTER_FRAME_INDEX_MUTATED_CORRUPTION);

        me->m_Events.AddEventAtOffset([this]()
        {
            if (Player* player = me->SelectNearestPlayer(50.f))
                AttackStart(player);
            me->SetReactState(REACT_AGGRESSIVE);
        }, 800ms);

        _events.ScheduleEvent(EVENT_CRUSH_TARGETING, 5s);
        _events.ScheduleEvent(EVENT_IMPALE, 10s + 500ms);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        me->DespawnOrUnsummon();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        me->DespawnOrUnsummon(2s);
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
                case EVENT_CRUSH_TARGETING:
                    DoCastAOE(SPELL_CRUSH_TARGETING);
                    _events.ScheduleEvent(EVENT_CRUSH, 500ms);
                    _events.Repeat(14s);
                    break;
                case EVENT_CRUSH:
                    if (Creature* crush = me->FindNearestCreature(NPC_CRUSH_TARGET, 50.f))
                    {
                        me->SetFacingToObject(crush, true);
                        me->PlayOneShotAnimKitId(ANIM_KIT_CRUSH);
                        DoCastSelf(SPELL_CRUSH);
                    }
                    break;
                case EVENT_IMPALE:
                    DoCastVictim(SPELL_IMPALE);
                    _events.Repeat(36s);
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
};

struct npc_madness_of_deathwing_regenerative_blood : public ScriptedAI
{
    npc_madness_of_deathwing_regenerative_blood(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript()) { }

    void InitializeAI() override
    {
        if (Creature* deathwing = _instance->GetCreature(DATA_MADNESS_OF_DEATHWING))
            deathwing->AI()->JustSummoned(me);
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->DespawnOrUnsummon(4s);
    }

    void JustAppeared() override
    {
        if (Player* player = me->SelectNearestPlayer(50.f))
            AttackStart(player);
    }

private:
    InstanceScript* _instance;
};

struct npc_madness_of_deathwing_elementium_bolt : public NullCreatureAI
{
    npc_madness_of_deathwing_elementium_bolt(Creature* creature) : NullCreatureAI(creature), _instance(me->GetInstanceScript())
    {
        _elementiumBoltPoints = { };
    }

    void JustDied(Unit* /*killer*/) override
    {
        DoCastSelf(SPELL_ELEMENTIUM_METEOR_TRANSFORM_DEATH);
        me->DespawnOrUnsummon(2s);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_LAUNCH_ELEMENTIUM_BOLT:
            {
                uint8 assaultedAspect = 0;
                if (Creature* deathwing = _instance->GetCreature(DATA_MADNESS_OF_DEATHWING))
                    assaultedAspect = deathwing->AI()->GetData(DATA_ASSAULTED_ASPECT);

                switch (assaultedAspect)
                {
                    case DRAGON_ASPECT_YSERA:
                        _elementiumBoltPoints = ElementiumBoltPathYsera;
                        break;
                    case DRAGON_ASPECT_KALECGOS:
                        _elementiumBoltPoints = ElementiumBoltPathKalecgos;
                        break;
                    case DRAGON_ASPECT_NOZDORMU:
                        _elementiumBoltPoints = ElementiumBoltPathNozdormu;
                        break;
                    case DRAGON_ASPECT_ALEXSTRASZA:
                        _elementiumBoltPoints = ElementiumBoltPathAlexstrasza;
                        break;
                    default:
                        break;
                }

                _events.ScheduleEvent(EVENT_LAUNCH_ELEMENTIUM_BOLT, 400ms);
                break;
            }
            default:
                break;
        }
    }

    void JustSummoned(Creature* summon) override
    {
        if (Creature* deathwing = _instance->GetCreature(DATA_MADNESS_OF_DEATHWING))
            deathwing->AI()->JustSummoned(summon);

        me->EnterVehicle(summon, SEAT_ID_CLAW_MARK);
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != EFFECT_MOTION_TYPE)
            return;

        switch (pointId)
        {
            case POINT_ID_ELEMENTIUM_BOLT_1:
                MoveToPosition(POINT_ID_ELEMENTIUM_BOLT_2, _elementiumBoltPoints[1], true);
                break;
            case POINT_ID_ELEMENTIUM_BOLT_2:
                _events.ScheduleEvent(EVENT_ELEMENTUIM_BLAST, 1s);
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
                case EVENT_LAUNCH_ELEMENTIUM_BOLT:
                    DoCastSelf(SPELL_ELEMENTIUM_METEOR_VISUAL);

                    if (Creature* deathwing = _instance->GetCreature(DATA_MADNESS_OF_DEATHWING))
                    {
                        if (deathwing->AI()->GetData(DATA_NOZDORMU_AVAILABLE))
                            MoveToPosition(POINT_ID_ELEMENTIUM_BOLT_1, _elementiumBoltPoints[0]);
                        else
                            MoveToPosition(POINT_ID_ELEMENTIUM_BOLT_2, _elementiumBoltPoints[1]);
                    }
                    break;
                case EVENT_ELEMENTUIM_BLAST:
                    // DoCast helpers block casts because if the casting state but we have to keep the cast intact
                    me->CastSpell(me, SPELL_ELEMENTIUM_BLAST);
                    me->CastSpell(me, SPELL_ELEMENTIUM_BLAST_PERIODIC);
                    me->CastSpell(me, SPELL_ELEMENTIUM_METEOR_TRANSFORM);
                    break;
                default:
                    break;
            }
        }
    }

private:
    InstanceScript* _instance;
    EventMap _events;
    std::array<Position, MaxElemetiumBoltPathPoints> _elementiumBoltPoints;

    void MoveToPosition(uint32 pointId, Position const position, bool timeZoneAvailable = false)
    {
        Movement::MoveSplineInit init(me);
        init.MoveTo(position.GetPositionX(), position.GetPositionY(), position.GetPositionZ(), false);
        init.SetFly();
        if (timeZoneAvailable)
            init.SetVelocity(2.5f);

        me->GetMotionMaster()->LaunchMoveSpline(std::move(init), pointId);
    }
};

struct npc_madness_of_deathwing_thrall : public ScriptedAI
{
    npc_madness_of_deathwing_thrall(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript()) { }

    void Reset() override
    {
        _instance->SetBossState(DATA_MADNESS_OF_DEATHWING, NOT_STARTED);
    }

    bool GossipSelect(Player* /*player*/, uint32 menuId, uint32 /*optionIndex*/) override
    {
        if (_instance->GetBossState(DATA_MADNESS_OF_DEATHWING) == IN_PROGRESS)
            return false;

        if (menuId == GOSSIP_MENU_START_ENCOUNTER)
        {
            DoCastSelf(SPELL_ASTRAL_RECALL);
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            DoSummon(BOSS_MADNESS_OF_DEATHWING, DeathwingSummonPositon, 0, TEMPSUMMON_MANUAL_DESPAWN);
            _events.ScheduleEvent(EVENT_FACE_TOWARDS_DEATHWING, 3s);
        }

        return true;
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_TALK_ASPECT_AID:
                _events.ScheduleEvent(EVENT_TALK_AID_CHAMPIONS, 31s);
                break;
            case ACTION_FIRE_DRAGON_SOUL:
                _events.Reset();
                me->SetDisableGravity(true);
                me->SendSetPlayHoverAnim(true);
                DoCastAOE(SPELL_FIRE_DRAGON_SOUL_ASPECTS);
                DoCastAOE(SPELL_TRIGGER_ASPECT_YELL);
                DoCastSelf(SPELL_ASTRAL_RECALL_OUTRO);
                _events.ScheduleEvent(EVENT_FIRE_DRAGON_SOUL, 2s + 600ms);
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
                case EVENT_FACE_TOWARDS_DEATHWING:
                    if (Creature* deathwing = _instance->GetCreature(DATA_MADNESS_OF_DEATHWING))
                        me->SetFacingToObject(deathwing);
                    break;
                case EVENT_TALK_AID_CHAMPIONS:
                    Talk(SAY_AID_CHAMPIONS);
                    break;
                case EVENT_FIRE_DRAGON_SOUL:
                    DoCastSelf(SPELL_FIRE_DRAGON_SOUL);
                    me->PlayDirectMusic(MUSIC_ID_OUTRO);
                    _events.ScheduleEvent(EVENT_PLAY_MOVIE, 31s);
                    break;
                case EVENT_PLAY_MOVIE:
                    DoCastAOE(SPELL_PLAY_MOVIE);
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    me->SendSetPlayHoverAnim(false);
                    me->SetDisableGravity(false);

                    if (Creature* ysera = _instance->GetCreature(DATA_YSERA_MADNESS_OF_DEATHWING))
                        ysera->DespawnOrUnsummon();

                    if (Creature* kalecgos = _instance->GetCreature(DATA_KALECGOS_MADNESS_OF_DEATHWING))
                        kalecgos->DespawnOrUnsummon();

                    if (Creature* nozdormu = _instance->GetCreature(DATA_NOZDORMU_MADNESS_OF_DEATHWING))
                        nozdormu->DespawnOrUnsummon();

                    if (Creature* alexstrasza = _instance->GetCreature(DATA_ALEXSTRASZA_MADNESS_OF_DEATHWING))
                        alexstrasza->DespawnOrUnsummon();

                    _instance->DoCastSpellOnPlayers(SPELL_CALM_MAELSTROM_SKYBOX);
                    me->DespawnOrUnsummon(100ms);
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

struct npc_madness_of_deathwing_dragon_aspect : public NullCreatureAI
{
    npc_madness_of_deathwing_dragon_aspect(Creature* creature) : NullCreatureAI(creature), _instance(me->GetInstanceScript()), _summons(me) { }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_ASSAULTED:
                Talk(SAY_INTRODUCE_ABILITY);
                break;
            case ACTION_LIMB_KILLED:
                _events.Reset();
                me->InterruptNonMeleeSpells(true);
                ConcentrateOnLimb();
                break;
            case ACTION_CATACLYSM_IN_PROGRESS:
                Talk(SAY_CATACLYSM);
                break;
            case ACTION_CREATE_TIME_ZONE:
                DoCastSelf(SPELL_TIME_ZONE);
                _events.ScheduleEvent(EVENT_TIME_ZONE, 700ms);
                break;
            case ACTION_CAUTERIZE:
                // We're going to use a event here in case of multiple cauterize calls within a short time window
                _events.ScheduleEvent(EVENT_CAUTERIZE, 1ms);
                break;
            case ACTION_TALK_PHASE_TWO:
                _events.ScheduleEvent(EVENT_TALK_PHASE_TWO, 16s);
                break;
            case ACTION_TALK_CHARGE_DRAGON_SOUL:
                Talk(SAY_CHARGE_DRAGON_SOUL);
                break;
            case ACTION_CAST_TIME_ZONE:
                _events.ScheduleEvent(EVENT_TIME_ZONE_PHASE_TWO, 200ms);
                break;
            default:
                break;
        }
    }

    void JustSummoned(Creature* summon) override
    {
        if (Creature* deathwing = _instance->GetCreature(DATA_MADNESS_OF_DEATHWING))
            deathwing->AI()->JustSummoned(summon);
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != EFFECT_MOTION_TYPE)
            return;

        switch (pointId)
        {
            case POINT_ID_CONCENTRATION:
                if (Creature* limb = ObjectAccessor::GetCreature(*me, _focusedLimbGUID))
                    me->SetFacingToObject(limb);
                break;
            default:
                break;
        }
    }

    void SetGUID(ObjectGuid const& guid, int32 type) override
    {
        switch (type)
        {
            case DATA_FOCUSED_LIMB:
                _focusedLimbGUID = guid;
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
                case EVENT_TIME_ZONE:
                    if (Creature* target = me->FindNearestCreature(NPC_TIME_ZONE_TARGET, 300.f))
                        DoCast(target, SPELL_TIME_ZONE_MISSILE);
                    break;
                case EVENT_CAUTERIZE:
                    DoCastSelf(SPELL_CAUTERIZE);
                    break;
                case EVENT_TALK_PHASE_TWO:
                    Talk(SAY_PHASE_TWO);
                    break;
                case EVENT_TIME_ZONE_PHASE_TWO:
                    if (Creature* target = me->FindNearestCreature(NPC_TIME_ZONE_TARGET, 300.f))
                        DoCast(target, SPELL_TIME_ZONE_MISSILE_PHASE_TWO);
                    break;
                default:
                    break;
            }
        }
    }

private:
    InstanceScript* _instance;
    EventMap _events;
    SummonList _summons;
    ObjectGuid _focusedLimbGUID;

    void ConcentrateOnLimb()
    {
        uint32 concentrationSpellID = 0;
        Movement::PointsArray path;

        switch (me->GetEntry())
        {
            case NPC_YSERA_MADNESS_OF_DEATHWING:
                me->RemoveAurasDueToSpell(SPELL_YSERAS_PRESENCE);
                me->RemoveAurasDueToSpell(SPELL_THE_DREAMER);
                concentrationSpellID = SPELL_CONCENTRATION_YSERA;
                path = YseraPath;
                break;
            case NPC_KALECGOS_MADNESS_OF_DEATHWING:
                me->RemoveAurasDueToSpell(SPELL_KALECGOS_PRESENCE);
                me->RemoveAurasDueToSpell(SPELL_SPELLWEAVER);
                concentrationSpellID = SPELL_CONCENTRATION_KALECGOS;
                path = KalecgosPath;
                break;
            case NPC_NOZDORMU_MADNESS_OF_DEATHWING:
                me->RemoveAurasDueToSpell(SPELL_NOZDORMUS_PRESENCE);
                concentrationSpellID = SPELL_CONCENTRATION_NOZDORMU;
                path = NozdormuPath;
                break;
            case NPC_ALEXSTRASZA_MADNESS_OF_DEATHWING:
                me->RemoveAurasDueToSpell(SPELL_ALEXSTRASZAS_PRESENCE);
                concentrationSpellID = SPELL_CONCENTRATION_ALEXSTRASZA;
                path = AlexstraszaPath;
                break;
            default:
                break;
        }

        DoCastSelf(concentrationSpellID);
        path.insert(path.begin(), G3D::Vector3(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ()));

        Movement::MoveSplineInit init(me);
        init.MovebyPath(path);
        init.SetFly();
        init.SetSmooth();
        init.SetUncompressed();
        me->GetMotionMaster()->LaunchMoveSpline(std::move(init), POINT_ID_CONCENTRATION);
    }
};

struct npc_madness_of_deathwing_cosmetic_limb : public NullCreatureAI
{
    npc_madness_of_deathwing_cosmetic_limb(Creature* creature) : NullCreatureAI(creature), _instance(me->GetInstanceScript()) { }

    void JustSummoned(Creature* summon) override
    {
        if (Creature* deathwing = _instance->GetCreature(DATA_MADNESS_OF_DEATHWING))
            deathwing->AI()->JustSummoned(summon);

        summon->CastSpell(me, VEHICLE_SPELL_RIDE_HARDCODED);
    }

private:
    InstanceScript* _instance;
};

struct npc_madness_of_deathwing_elementium_fragment : public ScriptedAI
{
    npc_madness_of_deathwing_elementium_fragment(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript())
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        if (Creature* deathwing = _instance->GetCreature(DATA_MADNESS_OF_DEATHWING))
        {
            deathwing->AI()->JustSummoned(me);
            deathwing->CastSpell(deathwing, SPELL_SHRAPNEL_PERIODIC);
        }

        me->m_Events.AddEventAtOffset([this]()
        {
            me->SetReactState(REACT_AGGRESSIVE);
        }, 2s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->DespawnOrUnsummon(6s);
    }

    void UpdateAI(uint32 /*diff*/) override
    {
        UpdateVictim();
    }

private:
    InstanceScript* _instance;
};

struct npc_madness_of_deathwing_elementium_terror: public ScriptedAI
{
    npc_madness_of_deathwing_elementium_terror(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript()) { }

    void JustAppeared() override
    {
        if (Creature* deathwing = _instance->GetCreature(DATA_MADNESS_OF_DEATHWING))
            deathwing->AI()->JustSummoned(me);

        if (Player* player = me->SelectNearestPlayer(50.f))
            AttackStart(player);
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->DespawnOrUnsummon(3s + 200ms);
    }

private:
    InstanceScript* _instance;
};

class spell_madness_of_deathwing_presence_of_the_aspects : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if([](WorldObject* target)->bool
        {
            if (target->IsPlayer())
                return false;

            if (target->IsCreature())
                if (TempSummon* summon = target->ToUnit()->ToTempSummon())
                    return !summon->GetOwnerOrCreatorGUID().IsPlayer();

            return true;
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_madness_of_deathwing_presence_of_the_aspects::FilterTargets, EFFECT_ALL, TARGET_UNIT_SRC_AREA_ALLY);
    }
};

class spell_madness_of_deathwing_carrying_winds_jump : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), GetEffectValue());
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_madness_of_deathwing_carrying_winds_jump::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_madness_of_deathwing_carrying_winds_triggered : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->RemoveAurasDueToSpell(GetEffectValue());
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_madness_of_deathwing_carrying_winds_triggered::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_madness_of_deathwing_limb_emerge_visual : public SpellScript
{
    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        uint32 visualKitId = RAND(SPELL_VISUAL_KIT_LIMB_EMERGE_1, SPELL_VISUAL_KIT_LIMB_EMERGE_2, SPELL_VISUAL_KIT_LIMB_EMERGE_3);
        GetHitUnit()->SendPlaySpellVisualKit(visualKitId, 0, 0);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_madness_of_deathwing_limb_emerge_visual::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_madness_of_deathwing_agonizing_pain : public SpellScript
{
    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        int32 damage = CalculatePct(target->GetMaxHealth(), GetEffectValue());
        if (!target->HealthBelowPctDamaged(25, damage))
            target->PlayDirectSound(SOUND_ID_DRAGON_ROAR);

        SetHitDamage(damage);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_madness_of_deathwing_agonizing_pain::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

class spell_madness_of_deathwing_assault_aspects : public SpellScript
{
    void CountPlayers(std::list<WorldObject*>& targets)
    {
        std::array<uint8, MAX_DRAGON_ASPECTS> playersOnPlatform = { };

        // First we count our players
        for (WorldObject const* target : targets)
        {
            float closestDistance = 100.f;
            uint8 platform = 0;
            for (uint8 i = 0; i < MAX_DRAGON_ASPECTS; ++i)
            {
                float dist = target->GetExactDist2d(PlatformForAspectReferencePositions[i]);
                if (dist <= closestDistance)
                {
                    closestDistance = dist;
                    platform = i;
                }
            }

            ++playersOnPlatform[platform];
        }

        // All players count, inform Deathwing about the numbers
        if (Creature* caster = GetCaster()->ToCreature())
        {
            if (!caster->IsAIEnabled)
                return;

            for (uint8 i = 0; i < MAX_DRAGON_ASPECTS; ++i)
                caster->AI()->SetData(DATA_PLAYERS_ON_PLATFORM + i, playersOnPlatform[i]);
        }
    }

    void NotifyDeathwing()
    {
        if (Creature* caster = GetCaster()->ToCreature())
            if (caster->IsAIEnabled)
                caster->AI()->DoAction(ACTION_ASSAULT_PLATFORM);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_madness_of_deathwing_assault_aspects::CountPlayers, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        AfterCast.Register(&spell_madness_of_deathwing_assault_aspects::NotifyDeathwing);
    }
};

class spell_madness_of_deathwing_face_trigger : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), GetEffectValue());
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_madness_of_deathwing_face_trigger::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_madness_of_deathwing_summon_tail : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        if (Creature* caster = GetCaster()->ToCreature())
        {
            if (!caster->IsAIEnabled)
                return;

            InstanceScript* instance = caster->GetInstanceScript();
            if (!instance)
                return;

            uint32 aspectId = caster->AI()->GetData(DATA_ASSAULTED_ASPECT);

            targets.remove_if([aspectId](WorldObject const* target)->bool
            {
                return target->GetExactDist2d(PlatformForAspectReferencePositions[aspectId]) >= 50.f;
            });
        }

        if (targets.size() > 1)
            Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_madness_of_deathwing_summon_tail::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

class spell_madness_of_deathwing_crush : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        if (Creature* caster = GetCaster()->ToCreature())
        {
            InstanceScript* instance = caster->GetInstanceScript();
            if (!instance)
                return;

            if (Creature* deathwing = instance->GetCreature(DATA_MADNESS_OF_DEATHWING))
            {
                uint32 aspectId = deathwing->AI()->GetData(DATA_ASSAULTED_ASPECT);
                targets.remove_if([aspectId](WorldObject const* target)->bool
                {
                    return target->GetExactDist2d(PlatformForAspectReferencePositions[aspectId]) >= 50.f;
                });
            }
        }

        if (targets.size() > 1)
            Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_madness_of_deathwing_crush::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_madness_of_deathwing_hemorrhage : public SpellScript
{
    void SetDest(SpellDestination& dest)
    {
        if (Creature* caster = GetCaster()->ToCreature())
            if (caster->IsAIEnabled)
                if (Creature* platform = ObjectAccessor::GetCreature(*caster, caster->AI()->GetGUID(DATA_CURRENT_PLATFORM)))
                    dest.Relocate(platform->GetPosition());
    }

    void Register() override
    {
        OnDestinationTargetSelect.Register(&spell_madness_of_deathwing_hemorrhage::SetDest, EFFECT_0, TARGET_DEST_NEARBY_ENTRY);
    }
};

class spell_madness_of_deathwing_hemorrhage_script : public SpellScript
{
    void SetTarget(WorldObject*& target)
    {
        InstanceScript* instance = GetCaster()->GetInstanceScript();
        if (!instance)
            return;

        if (Creature* deathwing = instance->GetCreature(DATA_MADNESS_OF_DEATHWING))
            if (Creature* limb = ObjectAccessor::GetCreature(*GetCaster(), deathwing->AI()->GetGUID(DATA_CURRENT_LIMB)))
                target = limb;
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            GetHitUnit()->CastSpell(caster, GetEffectValue());
    }

    void Register() override
    {
        OnObjectTargetSelect.Register(&spell_madness_of_deathwing_hemorrhage_script::SetTarget, EFFECT_0, TARGET_UNIT_NEARBY_ENTRY);
        OnEffectHitTarget.Register(&spell_madness_of_deathwing_hemorrhage_script::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_madness_of_deathwing_regenerative_blood_periodic : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_REGENERATIVE_BLOOD_SCRIPT,
            SPELL_REGENERATIVE_BLOOD_HEAL
        });
    }

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        Unit* target = GetTarget();

        _basePoints++;
        if (aurEff->GetTickNumber() == 11 || aurEff->GetTickNumber() == 20)
        {
            _basePoints -= 10;
            target->CastSpell(target, SPELL_REGENERATIVE_BLOOD_HEAL);
        }

        int32 bp = _basePoints * 10;
        target->CastSpell(target, SPELL_REGENERATIVE_BLOOD_SCRIPT, { SPELLVALUE_BASE_POINT0, bp });

        if (aurEff->GetTickNumber() >= 20)
            Remove();
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_madness_of_deathwing_regenerative_blood_periodic::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
private:
    int32 _basePoints = 0;
};

class spell_madness_of_deathwing_regenerative_blood_script : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->SetPower(POWER_ENERGY, GetEffectValue());
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_madness_of_deathwing_regenerative_blood_script::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_madness_of_deathwing_elementium_meteor_script: public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Creature* target = GetHitCreature())
        {
            target->ExitVehicle();
            if (target->IsAIEnabled)
                target->AI()->DoAction(ACTION_LAUNCH_ELEMENTIUM_BOLT);
        }
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_madness_of_deathwing_elementium_meteor_script::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_madness_of_deathwing_elementium_meteor_visual : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Creature* caster = GetCaster()->ToCreature();
        if (!caster)
            return;

        InstanceScript* instance = caster->GetInstanceScript();
        if (!instance)
            return;

        if (Creature* deathwing = instance->GetCreature(DATA_MADNESS_OF_DEATHWING))
        {
            ObjectGuid guid = deathwing->AI()->GetGUID(DATA_CURRENT_PLATFORM);
            targets.remove_if([guid](WorldObject const* target)->bool
            {
                return target->GetGUID() != guid;
            });
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_madness_of_deathwing_elementium_meteor_visual::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

class spell_madness_of_deathwing_burning_blood : public AuraScript
{
    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        Unit* target = GetTarget();
        float lostHealthPct = 100.f - target->GetHealthPct();

        uint8 stackDiff = std::max<int8>(0, uint8(lostHealthPct) - GetStackAmount());
        if (stackDiff)
            target->CastSpell(target, GetSpellInfo()->Id, { SPELLVALUE_AURA_STACK, stackDiff });

        uint32 spellId = sSpellMgr->GetSpellIdForDifficulty(GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, target);
        int32 bp = sSpellMgr->AssertSpellInfo(spellId)->Effects[EFFECT_0].CalcValue() * GetStackAmount();
        target->CastSpell(target, spellId, CastSpellExtraArgs(true).AddSpellBP0(bp));
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_madness_of_deathwing_burning_blood::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_madness_of_deathwing_spawn_blistering_tentacles : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        if (Vehicle* vehicle = target->GetVehicleKit())
            for (uint8 i = 0; i < 6; i++)
                if (vehicle->HasEmptySeat(i))
                    target->CastSpell(target, GetEffectValue());
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_madness_of_deathwing_spawn_blistering_tentacles::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_madness_of_deathwing_time_zone : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Creature* caster = GetCaster()->ToCreature();
        if (!caster)
            return;

        InstanceScript* instance = caster->GetInstanceScript();
        if (!instance)
            return;

        if (Creature* deathwing = instance->GetCreature(DATA_MADNESS_OF_DEATHWING))
        {
            ObjectGuid guid = deathwing->AI()->GetGUID(DATA_CURRENT_PLATFORM);
            targets.remove_if([guid](WorldObject const* target)->bool
            {
                return target->GetGUID() != guid;
            });
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_madness_of_deathwing_time_zone::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

class spell_madness_of_deathwing_trigger_concentration : public SpellScript
{
    bool Load() override
    {
        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
        {
            if (Creature* deathwing = instance->GetCreature(DATA_MADNESS_OF_DEATHWING))
            {
                uint8 aspectId = deathwing->AI()->GetData(DATA_ASPECT_FOR_LIMB);
                uint32 type = 0;
                switch (aspectId)
                {
                    case DRAGON_ASPECT_YSERA:
                        type = DATA_YSERA_MADNESS_OF_DEATHWING;
                        break;
                    case DRAGON_ASPECT_KALECGOS:
                        type = DATA_KALECGOS_MADNESS_OF_DEATHWING;
                        break;
                    case DRAGON_ASPECT_NOZDORMU:
                        type = DATA_NOZDORMU_MADNESS_OF_DEATHWING;
                        break;
                    case DRAGON_ASPECT_ALEXSTRASZA:
                        type = DATA_ALEXSTRASZA_MADNESS_OF_DEATHWING;
                        break;
                    default:
                        break;
                }

                if (Creature const* aspect = instance->GetCreature(type))
                    _aspectGUID = aspect->GetGUID();
            }
        }
        return true;
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Creature* creature = GetHitCreature();
        if (!creature || creature->GetGUID() != _aspectGUID)
            return;

        if (creature->IsAIEnabled)
            creature->AI()->DoAction(ACTION_LIMB_KILLED);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_madness_of_deathwing_trigger_concentration::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
private:
    ObjectGuid _aspectGUID;
};

class spell_madness_of_deathwing_concentration : public AuraScript
{
    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            if (Creature* creature = caster->ToCreature())
                if (creature->IsAIEnabled)
                    creature->AI()->SetGUID(GetTarget()->GetGUID(), DATA_FOCUSED_LIMB);

        GetTarget()->SetAnimationTier(AnimationTier::Fly);
        for (uint8 i = 0; i < 2; ++i)
            GetTarget()->CastSpell(GetTarget(), SPELL_SUMMON_COSMETIC_TENTACLE);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->SetAnimationTier(AnimationTier::Ground);
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_madness_of_deathwing_concentration::AfterApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove.Register(&spell_madness_of_deathwing_concentration::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_madness_of_deathwing_trigger_aspect_buffs : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_YSERAS_PRESENCE,
            SPELL_KALECGOS_PRESENCE,
            SPELL_NOZDORMUS_PRESENCE,
            SPELL_ALEXSTRASZAS_PRESENCE,
            SPELL_THE_DREAMER,
            SPELL_SPELLWEAVER
        });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        uint32 presenceSpellID = 0;

        target->InterruptNonMeleeSpells(true);
        switch (target->GetEntry())
        {
            case NPC_YSERA_MADNESS_OF_DEATHWING:
                presenceSpellID = SPELL_YSERAS_PRESENCE;
                target->CastSpell(target, SPELL_THE_DREAMER);
                break;
            case NPC_KALECGOS_MADNESS_OF_DEATHWING:
                presenceSpellID = SPELL_KALECGOS_PRESENCE;
                target->CastSpell(target, SPELL_SPELLWEAVER);
                break;
            case NPC_NOZDORMU_MADNESS_OF_DEATHWING:
                presenceSpellID = SPELL_NOZDORMUS_PRESENCE;
                break;
            case NPC_ALEXSTRASZA_MADNESS_OF_DEATHWING:
                presenceSpellID = SPELL_ALEXSTRASZAS_PRESENCE;
                break;
            default:
                break;
        }

        if (presenceSpellID)
            target->CastSpell(target, presenceSpellID);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_madness_of_deathwing_trigger_aspect_buffs::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_madness_of_deathwing_share_health : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHARE_HEALTH_2 });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_SHARE_HEALTH_2);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_madness_of_deathwing_share_health::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_madness_of_deathwing_summon_elementium_terror : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        for (uint8 i = 0; i < 2; ++i)
            GetHitUnit()->CastSpell(GetHitUnit(), GetEffectValue());
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_madness_of_deathwing_summon_elementium_terror::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_madness_of_deathwing_summon_impaling_tentacle : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        uint8 summonCount = target->GetMap()->Is25ManRaid() ? 8 : 3;
        for (uint8 i = 0; i < summonCount; ++i)
            target->CastSpell(target, GetEffectValue());
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_madness_of_deathwing_summon_impaling_tentacle::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_madness_of_deathwing_shrapnel : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHRAPNEL });
    }

    void FilterFragments(std::list<WorldObject*>& targets)
    {
        for (WorldObject const* target : targets)
            _fragmentGUIDs.push_back(target->GetGUID());
    }

    void FilterPlayers(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject const* target)->bool
        {
            return !target->IsPlayer();
        });

        for (WorldObject const* target : targets)
            _targetGUIDs.push_back(target->GetGUID());
    }

    void HandleShrapnels()
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (_targetGUIDs.size() > _fragmentGUIDs.size())
            Trinity::Containers::RandomResize(_targetGUIDs, _fragmentGUIDs.size());

        for (uint8 i = 0; i < _targetGUIDs.size(); i++)
        {
            if (Unit* target = ObjectAccessor::GetUnit(*caster, _targetGUIDs[i]))
                if (Creature* fragment = ObjectAccessor::GetCreature(*caster, _fragmentGUIDs[i]))
                    fragment->CastSpell(target, SPELL_SHRAPNEL);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_madness_of_deathwing_shrapnel::FilterFragments, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnObjectAreaTargetSelect.Register(&spell_madness_of_deathwing_shrapnel::FilterPlayers, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
        AfterCast.Register(&spell_madness_of_deathwing_shrapnel::HandleShrapnels);
    }
private:
    GuidVector _targetGUIDs;
    GuidVector _fragmentGUIDs;
};

class spell_madness_of_deathwing_fire_dragon_soul: public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Creature* deathwing = GetHitCreature())
            if (deathwing->IsAIEnabled)
                deathwing->AI()->DoAction(ACTION_DEATH);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_madness_of_deathwing_fire_dragon_soul::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_madness_of_deathwing_fire_dragon_soul_aspects : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_CONCENTRATION_YSERA_OUTRO,
            SPELL_CONCENTRATION_KALECGOS_OUTRO,
            SPELL_CONCENTRATION_NOZDORMU_OUTRO,
            SPELL_CONCENTRATION_ALEXSTRASZA_OUTRO,
            SPELL_YSERAS_PRESENCE,
            SPELL_KALECGOS_PRESENCE,
            SPELL_NOZDORMUS_PRESENCE,
            SPELL_ALEXSTRASZAS_PRESENCE,
            SPELL_THE_DREAMER,
            SPELL_SPELLWEAVER
        });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Creature* target = GetHitCreature();
        if (!target)
            return;

        uint32 concentrationSpellID = 0;
        switch (target->GetEntry())
        {
            case NPC_YSERA_MADNESS_OF_DEATHWING:
                concentrationSpellID = SPELL_CONCENTRATION_YSERA_OUTRO;
                target->RemoveAurasDueToSpell(SPELL_YSERAS_PRESENCE);
                target->RemoveAurasDueToSpell(SPELL_THE_DREAMER);
                break;
            case NPC_KALECGOS_MADNESS_OF_DEATHWING:
                concentrationSpellID = SPELL_CONCENTRATION_KALECGOS_OUTRO;
                target->RemoveAurasDueToSpell(SPELL_KALECGOS_PRESENCE);
                target->RemoveAurasDueToSpell(SPELL_SPELLWEAVER);
                break;
            case NPC_NOZDORMU_MADNESS_OF_DEATHWING:
                concentrationSpellID = SPELL_CONCENTRATION_NOZDORMU_OUTRO;
                target->RemoveAurasDueToSpell(SPELL_NOZDORMUS_PRESENCE);
                break;
            case NPC_ALEXSTRASZA_MADNESS_OF_DEATHWING:
                concentrationSpellID = SPELL_CONCENTRATION_ALEXSTRASZA_OUTRO;
                target->RemoveAurasDueToSpell(SPELL_ALEXSTRASZAS_PRESENCE);
                break;
            default:
                break;
        }

        target->CastSpell(target, concentrationSpellID);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_madness_of_deathwing_fire_dragon_soul_aspects::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_madness_of_deathwing_trigger_aspect_yell : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Creature* target = GetHitCreature();
        if (!target)
            return;

        if (target->IsAIEnabled)
            target->AI()->DoAction(ACTION_TALK_CHARGE_DRAGON_SOUL);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_madness_of_deathwing_trigger_aspect_yell::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget.Register(&spell_madness_of_deathwing_trigger_aspect_yell::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_madness_of_deathwing_corrupted_blood_stacker : public AuraScript
{
    void HandlePeriodic(AuraEffect const* aurEff)
    {
        Unit* target = GetTarget();
        uint8 currentPower = target->GetPower(POWER_ALTERNATE_POWER);
        uint8 targetPower = std::max<int8>(0, 20 - uint8(target->GetHealthPct()));

        // At 15, 10 and 5% health, Deathwing hemorrhages, doubling the current corruption
        if ((targetPower >= 5 && _hemorrHageSteps == 0) || (targetPower >= 10 && _hemorrHageSteps == 1) || (targetPower >= 15 && _hemorrHageSteps == 2))
        {
            target->SetPower(POWER_ALTERNATE_POWER, targetPower * 2);
            ++_hemorrHageSteps;
            return;
        }

        if (!(aurEff->GetTickNumber() % 2))
        {
            // Slowly ramp down to our actual power
            if (currentPower > targetPower)
                targetPower = currentPower - 1;

            target->SetPower(POWER_ALTERNATE_POWER, targetPower);
        }
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_madness_of_deathwing_corrupted_blood_stacker::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
private:
    uint8 _hemorrHageSteps = 0;
};

class spell_madness_of_deathwing_corrupted_blood: public AuraScript
{
    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        if (AuraEffect* bonusEffect = GetEffect(EFFECT_1))
        {
            uint8 stacks = GetTarget()->GetPower(POWER_ALTERNATE_POWER);
            int32 amount = bonusEffect->GetBaseAmount() + (bonusEffect->GetBaseAmount() * stacks);
            bonusEffect->SetAmount(amount);
        }
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_madness_of_deathwing_corrupted_blood::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_madness_of_deathwing_spellweave : public SpellScript
{
    void FilterFragments(std::list<WorldObject*>& targets)
    {
        targets.remove_if([this](WorldObject const* target)->bool
        {
            return target == GetExplTargetUnit();
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_madness_of_deathwing_spellweave::FilterFragments, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
    }
};

class spell_madness_of_deathwing_elementium_blast : public SpellScript
{
    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        int32 damage = GetHitDamage();
        if (!damage)
            return;

        float distance = caster->GetExactDist2d(GetHitUnit());

        // Guessed formular based on sniff data
        damage -= std::max<int32>(0, CalculatePct(damage, distance * 3.5f));
        SetHitDamage(damage);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_madness_of_deathwing_elementium_blast::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

class spell_madness_of_deathwing_cataclysm : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CATACLYSM_VISUAL });
    }

    void HandleVisual()
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_CATACLYSM_VISUAL);
    }

    void Register() override
    {
        AfterCast.Register(&spell_madness_of_deathwing_cataclysm::HandleVisual);
    }
};


class at_madness_of_deathwing_carrying_winds_jump : public AreaTriggerScript
{
public:
    at_madness_of_deathwing_carrying_winds_jump() : AreaTriggerScript("at_madness_of_deathwing_carrying_winds_jump") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* areaTrigger)
    {
        uint32 spellId = 0;
        switch (areaTrigger->ID)
        {
            case AT_JUMP_ALEXSTRASZA_TO_NOZDORMU:
                spellId = SPELL_CARRYING_WINDS_JUMP_ALEXSTRASZA_TO_NOZDORMU;
                break;
            case AT_JUMP_KALECGOS_TO_YSERA:
                spellId = SPELL_CARRYING_WINDS_JUMP_KALECGOS_TO_YSERA;
                break;
            case AT_JUMP_NOZDORMU_TO_ALEXSTRASZA:
                spellId = SPELL_CARRYING_WINDS_JUMP_NOZDORMU_TO_ALEXSTRASZA;
                break;
            case AT_JUMP_NOZDORMU_TO_YSERA:
                spellId = SPELL_CARRYING_WINDS_JUMP_NOZDORMU_TO_YSERA;
                break;
            case AT_JUMP_YSERA_TO_KALECGOS:
                spellId = SPELL_CARRYING_WINDS_JUMP_YSERA_TO_KALECGOS;
                break;
            case AT_JUMP_YSERA_TO_NOZDORMU:
                spellId = SPELL_CARRYING_WINDS_JUMP_YSERA_TO_NOZDORMU;
                break;
            default:
                break;
        }

        if (!spellId)
            return false;

        if (Creature* pad = player->FindNearestCreature(NPC_JUMP_PAD, 30.f))
            pad->CastSpell(player, spellId);

        return true;
    }
};

class at_madness_of_deathwing_carrying_winds_land : public AreaTriggerScript
{
public:
    at_madness_of_deathwing_carrying_winds_land() : AreaTriggerScript("at_madness_of_deathwing_carrying_winds_land") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* areaTrigger)
    {
        uint32 spellId = 0;

        switch (areaTrigger->ID)
        {
            case AT_LAND_ALEXSTRASZA_TO_NOZDORMU:
                spellId = SPELL_CARRYING_WINDS_DUMMY_ALEXSTRASZA_TO_NOZDORMU;
                break;
            case AT_LAND_KALECGOS_TO_YSERA:
                spellId = SPELL_CARRYING_WINDS_DUMMY_KALECGOS_TO_YSERA;
                break;
            case AT_LAND_NOZDORMU_TO_ALEXSTRASZA:
                spellId = SPELL_CARRYING_WINDS_DUMMY_NOZDORMU_TO_ALEXSTRASZA;
                break;
            case AT_LAND_NOZDORMU_TO_YSERA:
                spellId = SPELL_CARRYING_WINDS_DUMMY_NOZDORMU_TO_YSERA;
                break;
            case AT_LAND_YSERA_TO_KALECGOS:
                spellId = SPELL_CARRYING_WINDS_DUMMY_YSERA_TO_KALECGOS;
                break;
            case AT_LAND_YSERA_TO_NOZDORMU:
                spellId = SPELL_CARRYING_WINDS_DUMMY_YSERA_TO_NOZDORMU;
                break;
            default:
                break;
        }

        if (!spellId || !player->HasAura(spellId))
            return false;

        if (SpellInfo const* spell = sSpellMgr->GetSpellInfo(spellId))
            if (uint32 triggerSpellId = spell->Effects[EFFECT_0].TriggerSpell)
                player->CastSpell(player, triggerSpellId, CastSpellExtraArgs(true).AddSpellMod(SPELLVALUE_BASE_POINT1, spellId));

        return true;
    }
};

void AddSC_boss_madness_of_deathwing()
{
    RegisterDragonSoulCreatureAI(boss_madness_of_deathwing);
    RegisterDragonSoulCreatureAI(npc_madness_of_deathwing_limb_tentacle);
    RegisterDragonSoulCreatureAI(npc_madness_of_deathwing_mutated_corruption);
    RegisterDragonSoulCreatureAI(npc_madness_of_deathwing_regenerative_blood);
    RegisterDragonSoulCreatureAI(npc_madness_of_deathwing_elementium_bolt);
    RegisterDragonSoulCreatureAI(npc_madness_of_deathwing_thrall);
    RegisterDragonSoulCreatureAI(npc_madness_of_deathwing_dragon_aspect);
    RegisterDragonSoulCreatureAI(npc_madness_of_deathwing_cosmetic_limb);
    RegisterDragonSoulCreatureAI(npc_madness_of_deathwing_elementium_fragment);
    RegisterDragonSoulCreatureAI(npc_madness_of_deathwing_elementium_terror);
    RegisterSpellScript(spell_madness_of_deathwing_presence_of_the_aspects);
    RegisterSpellScript(spell_madness_of_deathwing_carrying_winds_jump);
    RegisterSpellScript(spell_madness_of_deathwing_carrying_winds_triggered);
    RegisterSpellScript(spell_madness_of_deathwing_limb_emerge_visual);
    RegisterSpellScript(spell_madness_of_deathwing_agonizing_pain);
    RegisterSpellScript(spell_madness_of_deathwing_assault_aspects);
    RegisterSpellScript(spell_madness_of_deathwing_face_trigger);
    RegisterSpellScript(spell_madness_of_deathwing_summon_tail);
    RegisterSpellScript(spell_madness_of_deathwing_crush);
    RegisterSpellScript(spell_madness_of_deathwing_hemorrhage);
    RegisterSpellScript(spell_madness_of_deathwing_hemorrhage_script);
    RegisterSpellScript(spell_madness_of_deathwing_regenerative_blood_script);
    RegisterSpellScript(spell_madness_of_deathwing_regenerative_blood_periodic);
    RegisterSpellScript(spell_madness_of_deathwing_elementium_meteor_script);
    RegisterSpellScript(spell_madness_of_deathwing_elementium_meteor_visual);
    RegisterSpellScript(spell_madness_of_deathwing_burning_blood);
    RegisterSpellScript(spell_madness_of_deathwing_spawn_blistering_tentacles);
    RegisterSpellScript(spell_madness_of_deathwing_time_zone);
    RegisterSpellScript(spell_madness_of_deathwing_trigger_concentration);
    RegisterSpellScript(spell_madness_of_deathwing_concentration);
    RegisterSpellScript(spell_madness_of_deathwing_trigger_aspect_buffs);
    RegisterSpellScript(spell_madness_of_deathwing_share_health);
    RegisterSpellScript(spell_madness_of_deathwing_summon_elementium_terror);
    RegisterSpellScript(spell_madness_of_deathwing_summon_impaling_tentacle);
    RegisterSpellScript(spell_madness_of_deathwing_shrapnel);
    RegisterSpellScript(spell_madness_of_deathwing_fire_dragon_soul);
    RegisterSpellScript(spell_madness_of_deathwing_fire_dragon_soul_aspects);
    RegisterSpellScript(spell_madness_of_deathwing_trigger_aspect_yell);
    RegisterSpellScript(spell_madness_of_deathwing_corrupted_blood_stacker);
    RegisterSpellScript(spell_madness_of_deathwing_corrupted_blood);
    RegisterSpellScript(spell_madness_of_deathwing_spellweave);
    RegisterSpellScript(spell_madness_of_deathwing_elementium_blast);
    RegisterSpellScript(spell_madness_of_deathwing_cataclysm);
    new at_madness_of_deathwing_carrying_winds_jump();
    new at_madness_of_deathwing_carrying_winds_land();
}
