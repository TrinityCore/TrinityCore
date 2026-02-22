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

/*
 * Spells SPELL_ROOT_SELF and SPELL_PACIFY_SELF are guessed, based on effects received in packets
 * Phoenix's on-death sequence requires sniff verification, partially based on a movie and MGT version
 * The way Telonicus casts shoot and bomb requires additional research, can't figure out how exactly both are used
 * Shock Barrier reflect damage calculation requires re-check, current formula may be wrong, based almost on nothing
 * What does Script Effect of the Banish spell?
 * Phoenix behavior during Gravity Lapse requires research. While in banish, they don't cast the Burn spell but
   how it is implemented remains unknown. What happens to eggs and invisible phoenixes is unknown
 * Combat timers requires to be revisited, especially in ground phase 5
 * The way we change spells and stages requires additional research, current behavior is not entrirely correct but
   correct approach remains unknown
 * Spell 39254 probably is used to despawn advisors in case of wipe and death, currently we despawn them by despawning spawn groups
 * What does Script Effect of spell 35879?
 * Before some patch, doors were closed when first advisor was engaged, allowing players to kite advisors and Kael'thas through whole
   instance. We close doors when encounter starts
 * Nether Vapor's movement requires research, they send almost no move packets but they move. Currently we force them to move randomly but
   on retail that doesn't look like random movement
 * Visual effect of Pure Nether Beam doesn't stop. Looks like client bug, saw same in WoTLK classic
 * Drowned emote during transition doesn't trigger, not set manually in sniffs (doesn't work if set manually either way). From my observation this boss has
   different bugs in different expansions. Something is fixed in one and is broken in another
 * Critical bug: If Gravity Lapse occurs when player has Arcane Disruption debuff, teleport from Gravity Lapse bugs player's position. As result,
   player's position will kinda stuck. Distance command will always return same position no matter where you are. You will be not able to loot Kael'thas because
   you're kinda far away from the corpse. Even leaving instance through portal in impossible. Teleporting to another map fixes this bug. Currently
   Arcane Disruption is disabled in phase 5 completely
 */

#include "ScriptMgr.h"
#include "Containers.h"
#include "DBCStores.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "the_eye.h"

enum KaelthasTexts
{
    // Kael'thas
    SAY_INTRO                                   = 0,
    SAY_INTRO_CAPERNIAN                         = 1,
    SAY_INTRO_TELONICUS                         = 2,
    SAY_INTRO_THALADRED                         = 3,
    SAY_INTRO_SANGUINAR                         = 4,
    SAY_PHASE_2_WEAPONS                         = 5,
    SAY_PHASE_3_ADVANCE                         = 6,
    SAY_PHASE_4_INTRO_2                         = 7,
    SAY_GRAVITY_LAPSE                           = 8,
    SAY_SUMMON_PHOENIX                          = 9,
    SAY_MIND_CONTROL                            = 10,
    SAY_SLAY                                    = 11,
    SAY_PHASE_5_NUTS                            = 12,
    SAY_DEATH                                   = 13,
    EMOTE_PYROBLAST                             = 14,

    // Thaladred the Darkener
    SAY_THALADRED_AGGRO                         = 0,
    SAY_THALADRED_DEATH                         = 1,
    EMOTE_THALADRED_GAZE                        = 2,

    // Lord Sanguinar
    SAY_SANGUINAR_AGGRO                         = 0,
    SAY_SANGUINAR_DEATH                         = 1,

    // Grand Astromancer Capernian
    SAY_CAPERNIAN_AGGRO                         = 0,
    SAY_CAPERNIAN_DEATH                         = 1,

    // Master Engineer Telonicus
    SAY_TELONICUS_AGGRO                         = 0,
    SAY_TELONICUS_DEATH                         = 1
};

enum KaelthasSpells
{
    // Phase 1
    SPELL_ROOT_SELF                             = 23973,
    SPELL_PACIFY_SELF                           = 19951,

    SPELL_KAEL_SANGUINAR                        = 36687,
    SPELL_KAEL_CAPERNIAN                        = 36688,
    SPELL_KAEL_TELONICUS                        = 36689,
    SPELL_KAEL_PHASE_TWO                        = 36709,

    // Phase 2
    SPELL_SUMMON_WEAPONS                        = 36976,

    // Phase 3
    SPELL_RESSURECTION                          = 36450,

    // Phase 4
    SPELL_FIREBALL                              = 36805,
    SPELL_FLAME_STRIKE                          = 36735,
    SPELL_ARCANE_DISRUPTION                     = 36834,
    SPELL_SUMMON_PHOENIX                        = 36723,
    SPELL_MIND_CONTROL                          = 36797,
    SPELL_SHOCK_BARRIER                         = 36815,
    SPELL_PYROBLAST                             = 36819,

    // Transition
    SPELL_KAEL_GAINING_POWER                    = 36091,
    SPELL_NETHERBEAM_CHANNEL_1                  = 36089,
    SPELL_NETHERBEAM_CHANNEL_2                  = 36090,
    SPELL_KAEL_GROW                             = 36184,
    SPELL_KAEL_EXPLODES_1                       = 36376,
    SPELL_KAEL_EXPLODES_2                       = 36373,
    SPELL_KAEL_EXPLODES_3                       = 36375,
    SPELL_KAEL_EXPLODES_4                       = 36354,
    SPELL_KAEL_EXPLODES                         = 36092,
    SPELL_KAEL_STUNNED                          = 36185,
    SPELL_PURE_NETHER_BEAM_SCRIPT_1             = 36201,
    SPELL_PURE_NETHER_BEAM_SCRIPT_2             = 36290,
    SPELL_PURE_NETHER_BEAM_SCRIPT_3             = 36291,
    SPELL_KAEL_FULL_POWER                       = 36187,

    // Phase 5
    SPELL_GRAVITY_LAPSE                         = 35941,
    SPELL_BANISH                                = 40370,
    SPELL_SUMMON_NETHER_VAPOR                   = 35865,
    SPELL_NETHER_BEAM                           = 35869,

    // Generic spells
    SPELL_REMOVE_WEAPONS                        = 39497,
    SPELL_PERMANENT_FEIGN_DEATH                 = 29266,

    // Thaladred the Darkener
    SPELL_SILENCE                               = 30225,
    SPELL_REND                                  = 36965,
    SPELL_PSYCHIC_BLOW                          = 36966,

    // Lord Sanguinar
    SPELL_BELLOWING_ROAR                        = 44863,

    // Grand Astromancer Capernian
    SPELL_CAPERNIAN_FIREBALL                    = 36971,
    SPELL_CONFLAGRATION                         = 37018,
    SPELL_ARCANE_BURST                          = 36970,

    // Master Engineer Telonicus
    SPELL_SHOOT                                 = 16496,
    SPELL_BOMB                                  = 37036,
    SPELL_REMOTE_TOY                            = 37027,

    // Flame Strike Trigger (Kael)
    SPELL_FLAME_STRIKE_DUMMY                    = 36730,

    // Phoenix
    SPELL_BURN_PERIODIC                         = 36720,
    SPELL_BURN_TRIGGER                          = 36721,
    SPELL_REBIRTH_SPAWN                         = 35369,
    SPELL_EMBER_BLAST                           = 34341,
    SPELL_SUMMON_PHOENIX_EGG                    = 36724,
    SPELL_REBIRTH_RESPAWN                       = 41587,
    SPELL_FULL_HEAL                             = 17683,

    // Nether Vapor
    SPELL_NETHER_VAPOR_DAMAGE                   = 35858,
    SPELL_NETHER_VAPOR_SCRIPT                   = 35879,
    SPELL_NETHER_VAPOR_LIGHTNING                = 45960,

    // Scripts
    // Mind Control
    SPELL_MIND_CONTROL_2                        = 36798,

    // Shock Barrier
    SPELL_SHOCK_BARRIER_DAMAGE                  = 36822,

    // Remote Toy
    SPELL_REMOTE_TOY_STUN                       = 37029,

    // Gravity Lapse
    SPELL_GRAVITY_LAPSE_TELE_FRONT              = 35966,
    SPELL_GRAVITY_LAPSE_TELE_FRONT_RIGHT        = 35967,
    SPELL_GRAVITY_LAPSE_TELE_FRONT_LEFT         = 35968,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_BACK_RIGHT  = 35969,
    SPELL_GRAVITY_LAPSE_TELE_BACK               = 35970,
    SPELL_GRAVITY_LAPSE_TELE_TO_CASTER          = 35971,
    SPELL_GRAVITY_LAPSE_TELE_BACK_LEFT          = 35972,
    SPELL_GRAVITY_LAPSE_TELE_FRONT_LEFT2        = 35973,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_LEFT        = 35974,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_LEFT2       = 35975,
    SPELL_GRAVITY_LAPSE_TELE_FRONT_LEFT3        = 35976,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_BACK_LEFT   = 35977,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_FRONT       = 35978,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_BACK        = 35979,
    SPELL_GRAVITY_LAPSE_TELE_FRONT_RIGHT2       = 35980,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_RIGHT       = 35981,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_FRONT_RIGHT = 35982,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_FRONT2      = 35983,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_FRONT_LEFT  = 35984,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_LEFT3       = 35985,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_BACK_LEFT2  = 35986,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_BACK2       = 35987,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_BACK_RIGHT2 = 35988,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_RIGHT2      = 35989,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_BACK_RIGHT3 = 35990,

    SPELL_GRAVITY_LAPSE_FLIGHT_AURA             = 39432,
    SPELL_GRAVITY_LAPSE_PERIODIC                = 34480,

    SPELL_GRAVITY_LAPSE_KNOCK_BACK              = 35938,

    // Flame Strike
    SPELL_FLAME_STRIKE_DAMAGE                   = 36731,

    // Summon Weapons
    SPELL_SUMMON_WEAPON_A                       = 36958,
    SPELL_SUMMON_WEAPON_B                       = 36959,
    SPELL_SUMMON_WEAPON_C                       = 36960,
    SPELL_SUMMON_WEAPON_D                       = 36961,
    SPELL_SUMMON_WEAPON_E                       = 36962,
    SPELL_SUMMON_WEAPON_F                       = 36963,
    SPELL_SUMMON_WEAPON_G                       = 36964,

    // Remove Enchanted Weapons
    SPELL_REMOVE_WEAPON_A                       = 39498,
    SPELL_REMOVE_WEAPON_B                       = 39499,
    SPELL_REMOVE_WEAPON_C                       = 39500,
    SPELL_REMOVE_WEAPON_D                       = 39501,
    SPELL_REMOVE_WEAPON_E                       = 39502,
    SPELL_REMOVE_WEAPON_F                       = 39503,
    SPELL_REMOVE_WEAPON_G                       = 39504,

    // Kael Gaining Power
    SPELL_NETHERBEAM_1                          = 36364,
    SPELL_NETHERBEAM_2                          = 36370,
    SPELL_NETHERBEAM_3                          = 36371,

    // Pure Nether Beam
    SPELL_PURE_NETHER_BEAM_1                    = 36196,
    SPELL_PURE_NETHER_BEAM_2                    = 36197,
    SPELL_PURE_NETHER_BEAM_3                    = 36198,

    // Summon Nether Vapor
    SPELL_SUMMON_NETHER_VAPOR_1                 = 35861,
    SPELL_SUMMON_NETHER_VAPOR_2                 = 35862,
    SPELL_SUMMON_NETHER_VAPOR_3                 = 35863,
    SPELL_SUMMON_NETHER_VAPOR_4                 = 35864,

    // Nether Beam
    SPELL_NETHER_BEAM_CHAIN                     = 35873
};

enum KaelthasEvents
{
    // Phase 1
    EVENT_START_ENCOUNTER_1                     = 1,
    EVENT_START_ENCOUNTER_2,
    EVENT_START_ENCOUNTER_3,

    // Phase 1, 2, 3: Special
    EVENT_SET_FACING,

    // Phase 2
    EVENT_SUMMON_WEAPONS,

    // Phase 3
    EVENT_REVIVE_ADVISORS_1,
    EVENT_REVIVE_ADVISORS_2,
    EVENT_ENGAGE_COMBAT,

    // Phase 4
    EVENT_FIREBALL,
    EVENT_FLAME_STRIKE,
    EVENT_ARCANE_DISRUPTION,
    EVENT_SUMMON_PHOENIX,
    EVENT_MIND_CONTROL,
    EVENT_SHOCK_BARRIER,
    EVENT_PYROBLAST,

    // Transition
    EVENT_TRANSITION_1,
    EVENT_TRANSITION_2,
    EVENT_TRANSITION_3,
    EVENT_TRANSITION_4,
    EVENT_TRANSITION_5,
    EVENT_TRANSITION_6,
    EVENT_TRANSITION_7,
    EVENT_TRANSITION_8,
    EVENT_TRANSITION_9,
    EVENT_TRANSITION_10,
    EVENT_TRANSITION_11,

    EVENT_EXPLOSION_1,
    EVENT_EXPLOSION_2,
    EVENT_EXPLOSION_3,

    EVENT_PURE_NETHER_BEAM,

    // Phase 5
    EVENT_STAGE_GRAVITY,
    EVENT_STAGE_GROUND,

    EVENT_GRAVITY_LAPSE,
    EVENT_SUMMON_NETHER_VAPOR,
    EVENT_NETHER_BEAM
};

enum KaelthasActions
{
    ACTION_ADVISOR_ENGAGED,
    ACTION_ADVISOR_DEFEATED,
    ACTION_RESET_CONTROLLER,
    ACTION_ENGAGE_COMBAT
};

enum KaelthasAdvisors
{
    ADVISOR_THALADRED                           = 1,
    ADVISOR_SANGUINAR                           = 2,
    ADVISOR_CAPERNIAN                           = 3,
    ADVISOR_TELONICUS                           = 4,
    MAX_DEFEATED_ADVISORS                       = 8
};

enum KaelthasCombatStages
{
    COMBAT_STAGE_PHASE_4,
    COMBAT_STAGE_PHASE_5_INITIAL,
    COMBAT_STAGE_PHASE_5_GRAVITY,
    COMBAT_STAGE_PHASE_5_GROUND
};

enum KaelthasPhases
{
    PHASE_NONE,
    PHASE_1_INTRO,
    PHASE_2_WEAPONS,
    PHASE_3_ADVANCE,
    PHASE_4_ENGAGED,
    PHASE_5_TRUE_POWER
};

enum KaelthasMovementPoints
{
    POINT_TRANSITION_START                      = 0,
    POINT_TRANSITION_UP                         = 1,
    POINT_TRANSITION_DOWN                       = 2
};

enum KaelthasSounds
{
    SOUND_PRECAST_NATURE_LOW                    = 27,
    SOUND_PRECAST_FROST_HIGH                    = 1136,
    SOUND_EXORCISM                              = 3320,
    SOUND_FIRE_WARD_TARGET                      = 10845,
    SOUND_ARCANE_EXPLOSION                      = 6539,
    SOUND_GHOSTLY_STRIKE_IMPACT                 = 6477,
    SOUND_HOLY_BOLT                             = 44
};

enum KaelthasSpellVisualKits
{
    SPELL_VISUAL_KIT_1                          = 7234,
    SPELL_VISUAL_KIT_2                          = 7235
};

enum KaelthasSpawnGroups
{
    SPAWN_GROUP_SANGUINAR                       = 342,
    SPAWN_GROUP_CAPERNIAN                       = 343,
    SPAWN_GROUP_TELONICUS                       = 344,
    SPAWN_GROUP_THALADRED                       = 345
};

static constexpr std::array<uint32, 4> AdvisorsSpawnGroupsData =
{
    SPAWN_GROUP_SANGUINAR,
    SPAWN_GROUP_CAPERNIAN,
    SPAWN_GROUP_TELONICUS,
    SPAWN_GROUP_THALADRED
};

static constexpr std::array<uint32, 7> SummonWeaponsSpells =
{
    SPELL_SUMMON_WEAPON_A,
    SPELL_SUMMON_WEAPON_B,
    SPELL_SUMMON_WEAPON_C,
    SPELL_SUMMON_WEAPON_D,
    SPELL_SUMMON_WEAPON_E,
    SPELL_SUMMON_WEAPON_F,
    SPELL_SUMMON_WEAPON_G
};

static constexpr std::array<uint32, 7> RemoveWeaponsSpells =
{
    SPELL_REMOVE_WEAPON_A,
    SPELL_REMOVE_WEAPON_B,
    SPELL_REMOVE_WEAPON_C,
    SPELL_REMOVE_WEAPON_D,
    SPELL_REMOVE_WEAPON_E,
    SPELL_REMOVE_WEAPON_F,
    SPELL_REMOVE_WEAPON_G
};

static constexpr std::array<uint32, 25> GravityLapseSpells =
{
    SPELL_GRAVITY_LAPSE_TELE_FRONT,
    SPELL_GRAVITY_LAPSE_TELE_FRONT_RIGHT,
    SPELL_GRAVITY_LAPSE_TELE_FRONT_LEFT,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_BACK_RIGHT,
    SPELL_GRAVITY_LAPSE_TELE_BACK,
    SPELL_GRAVITY_LAPSE_TELE_TO_CASTER,
    SPELL_GRAVITY_LAPSE_TELE_BACK_LEFT,
    SPELL_GRAVITY_LAPSE_TELE_FRONT_LEFT2,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_LEFT,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_LEFT2,
    SPELL_GRAVITY_LAPSE_TELE_FRONT_LEFT3,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_BACK_LEFT,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_FRONT,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_BACK,
    SPELL_GRAVITY_LAPSE_TELE_FRONT_RIGHT2,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_RIGHT,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_FRONT_RIGHT,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_FRONT2,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_FRONT_LEFT,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_LEFT3,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_BACK_LEFT2,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_BACK2,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_BACK_RIGHT2,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_RIGHT2,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_BACK_RIGHT3
};

static constexpr std::array<uint32, 4> SummonNetherVaporSpells =
{
    SPELL_SUMMON_NETHER_VAPOR_1,
    SPELL_SUMMON_NETHER_VAPOR_2,
    SPELL_SUMMON_NETHER_VAPOR_3,
    SPELL_SUMMON_NETHER_VAPOR_4
};

Position const TransitionStartPos = { 796.641f, -0.588817f, 48.728474f, 0.0f };
Position const TransitionUpPos    = { 795.007f, -0.471827f, 75.000000f, 0.0f };
Position const TransitionDownPos  = { 792.419f, -0.504778f, 50.050500f, 0.0f };

// 19622 - Kael'thas Sunstrider
struct boss_kaelthas : public BossAI
{
    boss_kaelthas(Creature* creature) : BossAI(creature, DATA_KAELTHAS),
        _phase(PHASE_NONE), _pyroblastCount(0), _isTransitionStarted(false), _isPerformingPyroblast(false) { }

    void JustAppeared() override
    {
        ///! HACK: Boss sometimes regens health since he can't reach target. For now we prevent health regeneration completely. Find a better solution
        me->SetRegenerateHealth(false);

        me->SetReactState(REACT_PASSIVE);

        for (uint32 group : AdvisorsSpawnGroupsData)
            me->GetMap()->SpawnGroupSpawn(group, true);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        if (_phase == PHASE_NONE)
            DoStartEncounter();
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (_phase == PHASE_NONE && me->IsValidAttackTarget(who) && me->IsWithinDistInMap(who, 30.0f) && who->GetTypeId() == TYPEID_PLAYER)
            DoStartEncounter();
    }

    void DoStartEncounter()
    {
        _phase = PHASE_1_INTRO;
        DoZoneInCombat();
        events.ScheduleEvent(EVENT_START_ENCOUNTER_1, 0s);
    }

    void AttackStart(Unit* who) override
    {
        ScriptedAI::AttackStartCaster(who, 35.0f);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_ENGAGE_COMBAT)
            if (_phase == PHASE_3_ADVANCE)
                events.RescheduleEvent(EVENT_ENGAGE_COMBAT, 2500ms);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_KAEL_SANGUINAR:
                Talk(SAY_INTRO_SANGUINAR);
                break;
            case SPELL_KAEL_CAPERNIAN:
                Talk(SAY_INTRO_CAPERNIAN);
                break;
            case SPELL_KAEL_TELONICUS:
                Talk(SAY_INTRO_TELONICUS);
                break;
            case SPELL_KAEL_PHASE_TWO:
                events.ScheduleEvent(EVENT_SUMMON_WEAPONS, 2500ms);
                break;
            case SPELL_NETHERBEAM_CHANNEL_1:
            case SPELL_NETHERBEAM_CHANNEL_2:
                DoCastSelf(SPELL_KAEL_GROW, true);
                break;
            default:
                break;
        }
    }

    void OnSpellStart(SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_GRAVITY_LAPSE)
            Talk(SAY_GRAVITY_LAPSE);
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_MIND_CONTROL:
                Talk(SAY_MIND_CONTROL);
                break;
            case SPELL_SUMMON_PHOENIX:
                Talk(SAY_SUMMON_PHOENIX);
                break;
            case SPELL_SHOCK_BARRIER:
                if (_phase == PHASE_4_ENGAGED)
                {
                    Talk(EMOTE_PYROBLAST);
                    _pyroblastCount = 0;
                    _isPerformingPyroblast = true;
                    specialEvents.ScheduleEvent(EVENT_PYROBLAST, 1s);
                }
                break;
            case SPELL_GRAVITY_LAPSE:
                DoCastSelf(SPELL_BANISH, true);
                break;
            default:
                break;
        }
    }

    void OnSpellFailed(SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_PYROBLAST)
        {
            specialEvents.CancelEvent(EVENT_PYROBLAST);
            _isPerformingPyroblast = false;
        }
    }

    void ScheduleCombatEventsForStage(uint8 stage)
    {
        switch (stage)
        {
            case COMBAT_STAGE_PHASE_4:
                events.CancelEvent(EVENT_SET_FACING);
                events.ScheduleEvent(EVENT_FIREBALL, 0s);
                events.ScheduleEvent(EVENT_FLAME_STRIKE, 30s, 40s);
                events.ScheduleEvent(EVENT_ARCANE_DISRUPTION, 20s, 30s);
                events.ScheduleEvent(EVENT_SUMMON_PHOENIX, 45s, 55s);
                events.ScheduleEvent(EVENT_MIND_CONTROL, 10s, 15s);
                events.ScheduleEvent(EVENT_SHOCK_BARRIER, 60s);
                break;
            case COMBAT_STAGE_PHASE_5_INITIAL:
                events.ScheduleEvent(EVENT_FIREBALL, 0s);
                events.ScheduleEvent(EVENT_STAGE_GRAVITY, 10s);
                break;
            case COMBAT_STAGE_PHASE_5_GRAVITY:
                events.CancelEvent(EVENT_FIREBALL);
                events.CancelEvent(EVENT_FLAME_STRIKE);
                events.CancelEvent(EVENT_ARCANE_DISRUPTION);
                events.CancelEvent(EVENT_SUMMON_PHOENIX);
                events.ScheduleEvent(EVENT_SHOCK_BARRIER, 0s);
                events.ScheduleEvent(EVENT_GRAVITY_LAPSE, 0s);
                events.ScheduleEvent(EVENT_SUMMON_NETHER_VAPOR, 5s);
                events.ScheduleEvent(EVENT_NETHER_BEAM, 8s);
                events.ScheduleEvent(EVENT_STAGE_GROUND, 35s);
                break;
            case COMBAT_STAGE_PHASE_5_GROUND:
                events.CancelEvent(EVENT_SHOCK_BARRIER);
                events.CancelEvent(EVENT_NETHER_BEAM);
                events.ScheduleEvent(EVENT_FIREBALL, 0s);
                events.ScheduleEvent(EVENT_FLAME_STRIKE, 20s, 30s);
                events.ScheduleEvent(EVENT_SUMMON_PHOENIX, 45s, 55s);
                events.ScheduleEvent(EVENT_STAGE_GRAVITY, 55s);
                break;
            default:
                break;
        }
    }

    void MovementInform(uint32 type, uint32 point) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        switch (point)
        {
            case POINT_TRANSITION_START:
                specialEvents.ScheduleEvent(EVENT_TRANSITION_2, 0s);
                break;
            case POINT_TRANSITION_DOWN:
                specialEvents.ScheduleEvent(EVENT_TRANSITION_11, 0s);
                break;
            default:
                break;
        }
    }

    void JustSummoned(Creature* summon) override
    {
        // Do not engage summons, handled manually in each script
        summons.Summon(summon);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (_phase == PHASE_4_ENGAGED && !_isTransitionStarted && me->HealthBelowPctDamaged(50, damage))
        {
            _isTransitionStarted = true;
            specialEvents.ScheduleEvent(EVENT_TRANSITION_1, 0s);
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        DoCastSelf(SPELL_REMOVE_WEAPONS);

        if (GameObject* statue = instance->GetGameObject(DATA_KAEL_STATUE_LEFT))
            statue->ResetDoorOrButton();

        if (GameObject* statue = instance->GetGameObject(DATA_KAEL_STATUE_RIGHT))
            statue->ResetDoorOrButton();

        if (GameObject* window = instance->GetGameObject(DATA_TEMPEST_BRIDGE_WINDOW))
            window->ResetDoorOrButton();

        for (uint32 group : AdvisorsSpawnGroupsData)
            me->GetMap()->SpawnGroupDespawn(group);

        if (Creature* controller = me->FindNearestCreatureWithOptions(250.0f, { .StringId = "KaelthasControllerTrigger" }))
            controller->AI()->DoAction(ACTION_RESET_CONTROLLER);

        summons.DespawnAll();
        _DespawnAtEvade(15s);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        _JustDied();

        for (uint32 group : AdvisorsSpawnGroupsData)
            me->GetMap()->SpawnGroupDespawn(group);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        specialEvents.Update(diff);

        while (uint32 eventId = specialEvents.ExecuteEvent())
        {
            switch (eventId)
            {
                // Phase 4
                case EVENT_PYROBLAST:
                    if (_pyroblastCount < 3)
                    {
                        _pyroblastCount++;
                        DoCastSelf(SPELL_PYROBLAST);
                        specialEvents.Repeat(5s);
                    }
                    else
                        _isPerformingPyroblast = false;
                    break;

                // Transition
                case EVENT_TRANSITION_1:
                    me->AttackStop();
                    me->InterruptNonMeleeSpells(false);
                    me->SetReactState(REACT_PASSIVE);
                    me->GetMotionMaster()->MovePoint(POINT_TRANSITION_START, TransitionStartPos);
                    events.Reset();
                    break;
                case EVENT_TRANSITION_2:
                    me->SetFacingTo(3.176499128341674804f);
                    Talk(SAY_PHASE_5_NUTS);
                    me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    specialEvents.ScheduleEvent(EVENT_TRANSITION_3, 2s);
                    break;
                case EVENT_TRANSITION_3:
                    DoCastSelf(SPELL_KAEL_GAINING_POWER);
                    specialEvents.ScheduleEvent(EVENT_TRANSITION_4, 1s);
                    break;
                case EVENT_TRANSITION_4:
                    me->SetWalk(true);
                    me->SetDisableGravity(true);
                    me->SetHover(true);
                    me->GetMotionMaster()->MovePoint(POINT_TRANSITION_UP, TransitionUpPos);

                    if (Creature* trigger = me->FindNearestCreatureWithOptions(100.0f, { .StringId = "KaelthasNetherbeamChannelTrigger1" }))
                        trigger->CastSpell(trigger, SPELL_NETHERBEAM_CHANNEL_1);

                    if (Creature* trigger = me->FindNearestCreatureWithOptions(100.0f, { .StringId = "KaelthasNetherbeamChannelTrigger2" }))
                        trigger->CastSpell(trigger, SPELL_NETHERBEAM_CHANNEL_2);

                    specialEvents.ScheduleEvent(EVENT_EXPLOSION_1, 3s);
                    specialEvents.ScheduleEvent(EVENT_TRANSITION_5, 3500ms);
                    break;
                case EVENT_TRANSITION_5:
                    if (Creature* trigger = me->FindNearestCreatureWithOptions(100.0f, { .StringId = "KaelthasNetherbeamChannelTrigger3" }))
                        trigger->CastSpell(trigger, SPELL_NETHERBEAM_CHANNEL_1);

                    if (Creature* trigger = me->FindNearestCreatureWithOptions(100.0f, { .StringId = "KaelthasNetherbeamChannelTrigger4" }))
                        trigger->CastSpell(trigger, SPELL_NETHERBEAM_CHANNEL_2);

                    specialEvents.ScheduleEvent(EVENT_TRANSITION_6, 3s);
                    break;
                case EVENT_TRANSITION_6:
                    if (Creature* trigger = me->FindNearestCreatureWithOptions(100.0f, { .StringId = "KaelthasNetherbeamChannelTrigger5" }))
                        trigger->CastSpell(trigger, SPELL_NETHERBEAM_CHANNEL_1);

                    if (Creature* trigger = me->FindNearestCreatureWithOptions(100.0f, { .StringId = "KaelthasNetherbeamChannelTrigger6" }))
                        trigger->CastSpell(trigger, SPELL_NETHERBEAM_CHANNEL_2);

                    specialEvents.ScheduleEvent(EVENT_TRANSITION_7, 8s);
                    break;
                case EVENT_TRANSITION_7:
                    if (GameObject* object = instance->GetGameObject(DATA_TEMPEST_BRIDGE_WINDOW))
                        object->UseDoorOrButton();

                    if (GameObject* object = instance->GetGameObject(DATA_KAEL_STATUE_LEFT))
                        object->UseDoorOrButton();

                    specialEvents.ScheduleEvent(EVENT_TRANSITION_8, 1s);
                    break;
                case EVENT_TRANSITION_8:
                {
                    DoCastSelf(SPELL_KAEL_EXPLODES, true);
                    DoCastSelf(SPELL_KAEL_STUNNED, true);
                    me->RemoveAurasDueToSpell(SPELL_NETHERBEAM_CHANNEL_1);
                    me->RemoveAurasDueToSpell(SPELL_NETHERBEAM_CHANNEL_2);

                    std::vector<Creature*> triggers;
                    GetCreatureListWithOptionsInGrid(triggers, me, 150.0f, { .StringId = "KaelthasExplosionTrigger" });
                    for (Creature* trigger : triggers)
                        trigger->CastSpell(trigger, SPELL_KAEL_EXPLODES_4);

                    if (GameObject* object = instance->GetGameObject(DATA_KAEL_STATUE_RIGHT))
                        object->UseDoorOrButton();

                    specialEvents.ScheduleEvent(EVENT_PURE_NETHER_BEAM, 4s);
                    specialEvents.ScheduleEvent(EVENT_TRANSITION_9, 12500ms);
                    break;
                }
                case EVENT_TRANSITION_9:
                    me->RemoveAurasDueToSpell(SPELL_KAEL_STUNNED);
                    DoCastSelf(SPELL_KAEL_FULL_POWER, true);
                    specialEvents.ScheduleEvent(EVENT_TRANSITION_10, 4s);
                    break;
                case EVENT_TRANSITION_10:
                    me->GetMotionMaster()->MovePoint(POINT_TRANSITION_DOWN, TransitionDownPos);
                    specialEvents.CancelEvent(EVENT_PURE_NETHER_BEAM);
                    break;
                case EVENT_TRANSITION_11:
                    _phase = PHASE_5_TRUE_POWER;
                    me->SetDisableGravity(false);
                    me->SetHover(false);
                    me->RemoveAurasDueToSpell(SPELL_KAEL_FULL_POWER);
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    ScheduleCombatEventsForStage(COMBAT_STAGE_PHASE_5_INITIAL);
                    break;

                // Transition: Explosion
                case EVENT_EXPLOSION_1:
                {
                    std::vector<Creature*> triggers;
                    GetCreatureListWithOptionsInGrid(triggers, me, 150.0f, { .StringId = "KaelthasExplosionTrigger" });
                    for (Creature* trigger : triggers)
                        trigger->CastSpell(trigger, SPELL_KAEL_EXPLODES_1);

                    specialEvents.ScheduleEvent(EVENT_EXPLOSION_2, 4s);
                    break;
                }
                case EVENT_EXPLOSION_2:
                {
                    std::vector<Creature*> triggers;
                    GetCreatureListWithOptionsInGrid(triggers, me, 150.0f, { .StringId = "KaelthasExplosionTrigger" });
                    for (Creature* trigger : triggers)
                        trigger->CastSpell(trigger, SPELL_KAEL_EXPLODES_2);

                    specialEvents.ScheduleEvent(EVENT_EXPLOSION_3, 4s);
                    break;
                }
                case EVENT_EXPLOSION_3:
                {
                    std::vector<Creature*> triggers;
                    GetCreatureListWithOptionsInGrid(triggers, me, 150.0f, { .StringId = "KaelthasExplosionTrigger" });
                    for (Creature* trigger : triggers)
                        trigger->CastSpell(trigger, SPELL_KAEL_EXPLODES_3);
                    break;
                }

                // Transition: Pure Nether Beam
                case EVENT_PURE_NETHER_BEAM:
                {
                    std::vector<Creature*> triggersGroup1;
                    GetCreatureListWithOptionsInGrid(triggersGroup1, me, 150.0f, { .StringId = "KaelthasPureNetherBeamTriggerGroup1" });
                    for (Creature* trigger : triggersGroup1)
                        if (roll_chance_i(30))
                            trigger->CastSpell(trigger, SPELL_PURE_NETHER_BEAM_SCRIPT_1);

                    std::vector<Creature*> triggersGroup2;
                    GetCreatureListWithOptionsInGrid(triggersGroup2, me, 150.0f, { .StringId = "KaelthasPureNetherBeamTriggerGroup2" });
                    for (Creature* trigger : triggersGroup2)
                        if (roll_chance_i(20))
                            trigger->CastSpell(trigger, SPELL_PURE_NETHER_BEAM_SCRIPT_2);

                    std::vector<Creature*> triggersGroup3;
                    GetCreatureListWithOptionsInGrid(triggersGroup3, me, 150.0f, { .StringId = "KaelthasPureNetherBeamTriggerGroup3" });
                    for (Creature* trigger : triggersGroup3)
                        if (roll_chance_i(30))
                            trigger->CastSpell(trigger, SPELL_PURE_NETHER_BEAM_SCRIPT_3);

                    specialEvents.Repeat(400ms);
                    break;
                }
                default:
                    break;
            }
        }

        events.Update(diff);

        if (_isPerformingPyroblast || me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                // Phase 1
                case EVENT_START_ENCOUNTER_1:
                    Talk(SAY_INTRO);
                    me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    events.ScheduleEvent(EVENT_START_ENCOUNTER_2, 25s);
                    break;
                case EVENT_START_ENCOUNTER_2:
                    DoCastSelf(SPELL_ROOT_SELF);
                    DoCastSelf(SPELL_PACIFY_SELF);
                    Talk(SAY_INTRO_THALADRED);
                    events.ScheduleEvent(EVENT_START_ENCOUNTER_3, 6s);
                    break;
                case EVENT_START_ENCOUNTER_3:
                    if (Creature* advisor = instance->GetCreature(DATA_THALADRED))
                        advisor->AI()->DoAction(ACTION_ADVISOR_ENGAGED);
                    events.ScheduleEvent(EVENT_SET_FACING, 0s);
                    break;

                // Phase 1, 2, 3: Special
                case EVENT_SET_FACING:
                    // This is quite tricky event. What is known and verified:
                    // 1. This event starts when first advisor is engaged
                    // 2. Event stops when phase 4 begins
                    // 3. This is not SetTarget since boss constantly sends unit field target with 0 as value
                    // 4. This is pure SetFacingTo
                    // 5. Minimal delay between events is exactly 400ms
                    // 6. Event triggers even if player's position was changed a little (result FaceDirection: 3.00765 > FaceDirection: 3.00557)
                    // What remains unknown or not implemented:
                    // 1. Looks like event doesn't trigger if boss already faces that direction
                    // 2. Is delay between events random or always 400ms?
                    // 3. What happens if target dies remains unknown
                    // 4. Looks like he switches target every x second, we use max threat for now, maybe it's correct
                    if (Unit* target = SelectTarget(SelectTargetMethod::MaxThreat))
                    {
                        me->SetFacingTo(me->GetAbsoluteAngle(target));
                        events.Repeat(400ms);
                    }
                    break;

                // Phase 2
                case EVENT_SUMMON_WEAPONS:
                    _phase = PHASE_2_WEAPONS;
                    Talk(SAY_PHASE_2_WEAPONS);
                    DoCastSelf(SPELL_SUMMON_WEAPONS);
                    events.ScheduleEvent(EVENT_REVIVE_ADVISORS_1, 95s);
                    break;

                // Phase 3
                case EVENT_REVIVE_ADVISORS_1:
                    _phase = PHASE_3_ADVANCE;
                    Talk(SAY_PHASE_3_ADVANCE);
                    events.ScheduleEvent(EVENT_REVIVE_ADVISORS_2, 6s);
                    break;
                case EVENT_REVIVE_ADVISORS_2:
                    DoCastSelf(SPELL_RESSURECTION);
                    events.ScheduleEvent(EVENT_ENGAGE_COMBAT, 180s);
                    break;
                case EVENT_ENGAGE_COMBAT:
                    _phase = PHASE_4_ENGAGED;
                    me->RemoveAurasDueToSpell(SPELL_ROOT_SELF);
                    me->RemoveAurasDueToSpell(SPELL_PACIFY_SELF);
                    me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    me->SetReactState(REACT_AGGRESSIVE);
                    Talk(SAY_PHASE_4_INTRO_2);
                    ResetThreatList();
                    ScheduleCombatEventsForStage(COMBAT_STAGE_PHASE_4);
                    break;

                // Phase 4
                case EVENT_FIREBALL:
                    DoCastVictim(SPELL_FIREBALL);
                    events.Repeat(2400ms);
                    break;
                case EVENT_FLAME_STRIKE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 200.0f, true))
                        DoCast(target, SPELL_FLAME_STRIKE);
                    events.Repeat(30s, 40s);
                    break;
                case EVENT_ARCANE_DISRUPTION:
                    DoCastSelf(SPELL_ARCANE_DISRUPTION);
                    events.Repeat(20s, 30s);
                    break;
                case EVENT_SUMMON_PHOENIX:
                    DoCastSelf(SPELL_SUMMON_PHOENIX);
                    events.Repeat(45s, 55s);
                    break;
                case EVENT_MIND_CONTROL:
                    DoCastSelf(SPELL_MIND_CONTROL);
                    events.Repeat(30s, 45s);
                    break;
                case EVENT_SHOCK_BARRIER:
                    DoCastSelf(SPELL_SHOCK_BARRIER);
                    events.Repeat(_phase == PHASE_4_ENGAGED ? 60s : 7s);
                    break;

                // Phase 5
                case EVENT_STAGE_GRAVITY:
                    ScheduleCombatEventsForStage(COMBAT_STAGE_PHASE_5_GRAVITY);
                    break;
                case EVENT_STAGE_GROUND:
                    ScheduleCombatEventsForStage(COMBAT_STAGE_PHASE_5_GROUND);
                    break;
                case EVENT_GRAVITY_LAPSE:
                    DoCastSelf(SPELL_GRAVITY_LAPSE);
                    break;
                case EVENT_SUMMON_NETHER_VAPOR:
                    DoCastSelf(SPELL_SUMMON_NETHER_VAPOR);
                    break;
                case EVENT_NETHER_BEAM:
                    DoCastSelf(SPELL_NETHER_BEAM);
                    events.Repeat(3600ms);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    uint8 _phase;
    uint8 _pyroblastCount;
    bool _isTransitionStarted;
    bool _isPerformingPyroblast;
    EventMap specialEvents;
};

struct AdvisorBaseAI : public ScriptedAI
{
    AdvisorBaseAI(Creature* creature) : ScriptedAI(creature), HasRessurrected(false), IsFeigningDeath(false) { }

    void InitializeAI() override
    {
        me->SetImmuneToPC(true);

        Scheduler.SetValidator([this]
        {
            return !me->HasUnitState(UNIT_STATE_CASTING);
        });
    }

    void Reset() override
    {
        Scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        ScheduleEvents();
    }

    virtual void ScheduleEvents() = 0;

    void DoAction(int32 action) override
    {
        if (action == ACTION_ADVISOR_ENGAGED)
        {
            me->SetImmuneToPC(false);
            DoZoneInCombat();
        }
    }

    void DoInformController()
    {
        if (Creature* controller = me->FindNearestCreatureWithOptions(250.0f, { .StringId = "KaelthasControllerTrigger" }))
            controller->AI()->DoAction(ACTION_ADVISOR_DEFEATED);
    }

    bool IsEnemyInRange(float distance)
    {
        for (ThreatReference const* ref : me->GetThreatManager().GetUnsortedThreatList())
            if (me->GetDistance2d(ref->GetVictim()) < distance)
                return true;

        return false;
    }

    void DamageTaken(Unit* /*who*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (HasRessurrected)
            return;

        if (damage >= me->GetHealth())
        {
            damage = me->GetHealth() -1;

            if (!IsFeigningDeath)
            {
                IsFeigningDeath = true;

                Scheduler.Schedule(0s, [this](TaskContext /*task*/)
                {
                    Scheduler.CancelAll();

                    DoCastSelf(SPELL_PERMANENT_FEIGN_DEATH);
                    DoInformController();
                    me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    me->SetReactState(REACT_PASSIVE);
                });
            }
        }
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_RESSURECTION)
        {
            Scheduler.Schedule(0s, [this](TaskContext task)
            {
                switch (task.GetRepeatCounter())
                {
                    case 0:
                        me->RemoveAurasDueToSpell(SPELL_PERMANENT_FEIGN_DEATH);
                        me->SetReactState(REACT_PASSIVE);
                        task.Repeat(2500ms);
                        break;
                    case 1:
                        me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                        me->SetReactState(REACT_AGGRESSIVE);
                        ResetThreatList();
                        ScheduleEvents();
                        HasRessurrected = true;
                        IsFeigningDeath = false;
                        break;
                    default:
                        break;
                }
            });
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        DoInformController();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        Scheduler.Update(diff);

        DoMeleeAttackIfReady();
    }

protected:
    TaskScheduler Scheduler;
    bool HasRessurrected;
    bool IsFeigningDeath;
};

// 20064 - Thaladred the Darkener
struct boss_thaladred_the_darkener : public AdvisorBaseAI
{
    boss_thaladred_the_darkener(Creature* creature) : AdvisorBaseAI(creature) { }

    void ScheduleEvents() override
    {
        Scheduler
            .Schedule(2s, 3s, [this](TaskContext task)
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
                {
                    ResetThreatList();
                    AddThreat(target, 1000000.0f);
                    Talk(EMOTE_THALADRED_GAZE, target);
                }
                task.Repeat(8s, 18s);
            })
            .Schedule(0s, [this](TaskContext task)
            {
                if (IsEnemyInRange(10.0f))
                    DoCastSelf(SPELL_SILENCE);
                task.Repeat(5s);
            })
            .Schedule(0s, 5s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_REND);
                task.Repeat(3s, 5s);
            })
            .Schedule(0s, 5s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_PSYCHIC_BLOW);
                task.Repeat(15s, 20s);
            });
    }

    void JustEngagedWith(Unit* who) override
    {
        Talk(SAY_THALADRED_AGGRO);
        AdvisorBaseAI::JustEngagedWith(who);
    }

    void JustDied(Unit* killer) override
    {
        Talk(SAY_THALADRED_DEATH);
        AdvisorBaseAI::JustDied(killer);
    }
};

// 20060 - Lord Sanguinar
struct boss_lord_sanguinar : public AdvisorBaseAI
{
    boss_lord_sanguinar(Creature* creature) : AdvisorBaseAI(creature) { }

    void ScheduleEvents() override
    {
        Scheduler
            .Schedule(0s, 5s, [this](TaskContext task)
            {
                if (IsEnemyInRange(35.0f))
                    DoCastSelf(SPELL_BELLOWING_ROAR);
                task.Repeat(30s, 45s);
            });
    }

    void JustEngagedWith(Unit* who) override
    {
        Talk(SAY_SANGUINAR_AGGRO);
        AdvisorBaseAI::JustEngagedWith(who);
    }

    void JustDied(Unit* killer) override
    {
        Talk(SAY_SANGUINAR_DEATH);
        AdvisorBaseAI::JustDied(killer);
    }
};

// 20062 - Grand Astromancer Capernian
struct boss_grand_astromancer_capernian : public AdvisorBaseAI
{
    boss_grand_astromancer_capernian(Creature* creature) : AdvisorBaseAI(creature) { }

    void ScheduleEvents() override
    {
        Scheduler
            .Schedule(0s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_CAPERNIAN_FIREBALL);
                task.Repeat(2400ms);
            })
            .Schedule(0s, 20s, [this](TaskContext task)
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 30.0f))
                    DoCast(target, SPELL_CONFLAGRATION);
                task.Repeat(15s);
            })
            .Schedule(0s, [this](TaskContext task)
            {
                if (IsEnemyInRange(10.0f))
                    DoCastSelf(SPELL_ARCANE_BURST);
                task.Repeat(1200ms);
            });
    }

    void AttackStart(Unit* who) override
    {
        ScriptedAI::AttackStartCaster(who, 30.0f);
    }

    void JustEngagedWith(Unit* who) override
    {
        Talk(SAY_CAPERNIAN_AGGRO);
        AdvisorBaseAI::JustEngagedWith(who);
    }

    void JustDied(Unit* killer) override
    {
        Talk(SAY_CAPERNIAN_DEATH);
        AdvisorBaseAI::JustDied(killer);
    }
};

// 20063 - Master Engineer Telonicus
struct boss_master_engineer_telonicus : public AdvisorBaseAI
{
    boss_master_engineer_telonicus(Creature* creature) : AdvisorBaseAI(creature) { }

    void ScheduleEvents() override
    {
        Scheduler
            .Schedule(0s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_SHOOT);
                task.Repeat(2400ms);
            })
            .Schedule(0s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_BOMB);
                task.Repeat(3600ms);
            })
            .Schedule(0s, 10s, [this](TaskContext task)
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, false, true, -SPELL_REMOTE_TOY))
                    DoCast(target, SPELL_REMOTE_TOY);
                task.Repeat(15s, 18s);
            });
    }

    void AttackStart(Unit* who) override
    {
        ScriptedAI::AttackStartCaster(who, 30.0f);
    }

    void JustEngagedWith(Unit* who) override
    {
        Talk(SAY_TELONICUS_AGGRO);
        AdvisorBaseAI::JustEngagedWith(who);
    }

    void JustDied(Unit* killer) override
    {
        Talk(SAY_TELONICUS_DEATH);
        AdvisorBaseAI::JustDied(killer);
    }
};

// 22515 - World Trigger
struct npc_kaelthas_controller : public ScriptedAI
{
    npc_kaelthas_controller(Creature* creature) : ScriptedAI(creature),
        _instance(creature->GetInstanceScript()), _defeatedAdvisorCounter(0) { }

    // The reasons why this script exists:
    // 1. We know that specific AIGroup actions autotargets invoker of event and this creature is receiver
    // of Kael'thas' texts in phase 1, 2 and 3, meaning this creature is invoker of those events
    // 2. This creature casts non-serverside spell (Kael Phase Two) that starts phase 2. Other spells are
    // serverside and are guessed but perfectly satisfies our needs
    void Reset() override
    {
        _defeatedAdvisorCounter = 0;
        _scheduler.CancelAll();
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_ADVISOR_DEFEATED:
            {
                ++_defeatedAdvisorCounter;

                switch (_defeatedAdvisorCounter)
                {
                    case ADVISOR_THALADRED:
                        DoCastSelf(SPELL_KAEL_SANGUINAR);
                        _scheduler.Schedule(12500ms, [this](TaskContext /*task*/)
                        {
                            if (Creature* advisor = _instance->GetCreature(DATA_SANGUINAR))
                                advisor->AI()->DoAction(ACTION_ADVISOR_ENGAGED);
                        });
                        break;
                    case ADVISOR_SANGUINAR:
                        DoCastSelf(SPELL_KAEL_CAPERNIAN);
                        _scheduler.Schedule(7s, [this](TaskContext /*task*/)
                        {
                            if (Creature* advisor = _instance->GetCreature(DATA_CAPERNIAN))
                                advisor->AI()->DoAction(ACTION_ADVISOR_ENGAGED);
                        });
                        break;
                    case ADVISOR_CAPERNIAN:
                        DoCastSelf(SPELL_KAEL_TELONICUS);
                        _scheduler.Schedule(8s, [this](TaskContext /*task*/)
                        {
                            if (Creature* advisor = _instance->GetCreature(DATA_TELONICUS))
                                advisor->AI()->DoAction(ACTION_ADVISOR_ENGAGED);
                        });
                        break;
                    case ADVISOR_TELONICUS:
                        DoCastSelf(SPELL_KAEL_PHASE_TWO);
                        break;
                    case MAX_DEFEATED_ADVISORS:
                        if (Creature* kaelthas = _instance->GetCreature(DATA_KAELTHAS))
                            kaelthas->AI()->DoAction(ACTION_ENGAGE_COMBAT);
                        break;
                    default:
                        break;
                }
                break;
            }
            case ACTION_RESET_CONTROLLER:
                Reset();
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    InstanceScript* _instance;
    uint8 _defeatedAdvisorCounter;
    TaskScheduler _scheduler;
};

// 21369 - Flame Strike Trigger (Kael)
struct npc_flame_strike_trigger_kael : public ScriptedAI
{
    npc_flame_strike_trigger_kael(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_FLAME_STRIKE_DUMMY);
        me->DespawnOrUnsummon(15s);
    }
};

// 21362 - Phoenix
struct npc_phoenix_the_eye : public ScriptedAI
{
    npc_phoenix_the_eye(Creature* creature) : ScriptedAI(creature), _isDepleted(false), _summons(me) { }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_BURN_PERIODIC);
        DoCastSelf(SPELL_REBIRTH_SPAWN);

        _scheduler.Schedule(3s, [this](TaskContext /*task*/)
        {
            DoZoneInCombat();
            me->SetReactState(REACT_AGGRESSIVE);
        });
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_BURN_TRIGGER)
            Unit::DealDamage(me, me, me->CountPctFromMaxHealth(5), nullptr, NODAMAGE);
    }

    void JustSummoned(Creature* summon) override
    {
        _summons.Summon(summon);
    }

    void SummonedCreatureDies(Creature* /*summon*/, Unit* /*killer*/) override
    {
        me->DespawnOrUnsummon();
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (damage >= me->GetHealth())
        {
            damage = me->GetHealth() - 1;

            if (!_isDepleted)
            {
                _isDepleted = true;

                me->RemoveAurasDueToSpell(SPELL_BURN_PERIODIC);
                DoCastSelf(SPELL_EMBER_BLAST);
                DoCastSelf(SPELL_SUMMON_PHOENIX_EGG);
                me->SetReactState(REACT_PASSIVE);
                me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                me->SetStandState(UNIT_STAND_STATE_DEAD);

                _scheduler.Schedule(15s, [this](TaskContext task)
                {
                    switch (task.GetRepeatCounter())
                    {
                        case 0:
                            _summons.DespawnAll();
                            me->RemoveAurasDueToSpell(SPELL_EMBER_BLAST);
                            me->RemoveAurasDueToSpell(SPELL_SUMMON_PHOENIX_EGG);
                            task.Repeat(2s);
                            break;
                        case 1:
                            me->SetStandState(UNIT_STAND_STATE_STAND);
                            DoCastSelf(SPELL_REBIRTH_RESPAWN);
                            task.Repeat(3s);
                            break;
                        case 2:
                            _isDepleted = false;
                            DoCastSelf(SPELL_FULL_HEAL);
                            DoCastSelf(SPELL_BURN_PERIODIC);
                            me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                            task.Repeat(2s);
                            break;
                        case 3:
                            me->SetReactState(REACT_AGGRESSIVE);
                            break;
                        default:
                            break;
                    }
                });
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (UpdateVictim())
            DoMeleeAttackIfReady();
    }

private:
    TaskScheduler _scheduler;
    bool _isDepleted;
    SummonList _summons;
};

// 21364 - Phoenix Egg
struct npc_phoenix_egg_the_eye : public ScriptedAI
{
    npc_phoenix_egg_the_eye(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void InitializeAI() override
    {
        me->SetCorpseDelay(5, true);
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        if (Creature* kaelthas = _instance->GetCreature(DATA_KAELTHAS))
            kaelthas->AI()->JustSummoned(me);
    }

private:
    InstanceScript* _instance;
};

// 21002 - Nether Vapor
struct npc_nether_vapor : public ScriptedAI
{
    npc_nether_vapor(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_NETHER_VAPOR_DAMAGE);
        DoCastSelf(SPELL_NETHER_VAPOR_SCRIPT);
        DoCastSelf(SPELL_NETHER_VAPOR_LIGHTNING);
        me->DespawnOrUnsummon(30s);
        me->GetMotionMaster()->MoveRandom(5.0f);
    }
};

// 36797 - Mind Control
class spell_kaelthas_mind_control : public SpellScript
{
    PrepareSpellScript(spell_kaelthas_mind_control);

    bool Load() override
    {
        return GetCaster()->IsUnit();
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove(GetCaster()->GetVictim());
        Trinity::Containers::RandomResize(targets, 3);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_kaelthas_mind_control::FilterTargets, EFFECT_ALL, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_kaelthas_mind_control_aura : public AuraScript
{
    PrepareAuraScript(spell_kaelthas_mind_control_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MIND_CONTROL_2 });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_MIND_CONTROL_2, true);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_MIND_CONTROL_2);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_kaelthas_mind_control_aura::AfterApply, EFFECT_0, SPELL_AURA_AOE_CHARM, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_kaelthas_mind_control_aura::AfterRemove, EFFECT_0, SPELL_AURA_AOE_CHARM, AURA_EFFECT_HANDLE_REAL);
    }
};

// 36815 - Shock Barrier
class spell_kaelthas_shock_barrier : public AuraScript
{
    PrepareAuraScript(spell_kaelthas_shock_barrier);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHOCK_BARRIER_DAMAGE });
    }

    void OnAbsorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
    {
        GetTarget()->CastSpell(dmgInfo.GetAttacker(), SPELL_SHOCK_BARRIER_DAMAGE, CastSpellExtraArgs(aurEff)
            .SetTriggerFlags(TRIGGERED_FULL_MASK)
            .AddSpellMod(SPELLVALUE_BASE_POINT0, absorbAmount / 15));
    }

    void Register() override
    {
        AfterEffectAbsorb += AuraEffectAbsorbFn(spell_kaelthas_shock_barrier::OnAbsorb, EFFECT_0);
    }
};

// 36819 - Pyroblast
class spell_kaelthas_pyroblast : public SpellScript
{
    PrepareSpellScript(spell_kaelthas_pyroblast);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        if (WorldObject* target = GetCaster()->GetVictim())
        {
            targets.clear();
            targets.push_back(target);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_kaelthas_pyroblast::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// 37027 - Remote Toy
class spell_kaelthas_remote_toy : public AuraScript
{
    PrepareAuraScript(spell_kaelthas_remote_toy);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_REMOTE_TOY_STUN });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        if (roll_chance_i(50))
            GetTarget()->CastSpell(GetTarget(), SPELL_REMOTE_TOY_STUN, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_kaelthas_remote_toy::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 35941 - Gravity Lapse
class spell_kaelthas_gravity_lapse : public SpellScript
{
    PrepareSpellScript(spell_kaelthas_gravity_lapse);

public:
    spell_kaelthas_gravity_lapse()
    {
        _targetCount = 0;
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(GravityLapseSpells) && ValidateSpellInfo({ SPELL_GRAVITY_LAPSE_FLIGHT_AURA, SPELL_GRAVITY_LAPSE_PERIODIC });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        caster->CastSpell(target, GravityLapseSpells[std::min(_targetCount, GravityLapseSpells.size())], true);
        target->CastSpell(target, SPELL_GRAVITY_LAPSE_FLIGHT_AURA, true);
        target->CastSpell(target, SPELL_GRAVITY_LAPSE_PERIODIC, true);
        _targetCount++;
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_kaelthas_gravity_lapse::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }

private:
    std::size_t _targetCount;
};

// 34480 - Gravity Lapse
class spell_kaelthas_gravity_lapse_periodic : public AuraScript
{
    PrepareAuraScript(spell_kaelthas_gravity_lapse_periodic);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_GRAVITY_LAPSE_KNOCK_BACK });
    }

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        if (!target->IsFlying() || std::abs(target->GetPositionZ() - target->GetFloorZ()) < 0.5f)
            target->CastSpell(target, SPELL_GRAVITY_LAPSE_KNOCK_BACK, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_kaelthas_gravity_lapse_periodic::OnPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 36730 - Flame Strike
class spell_kaelthas_flame_strike : public AuraScript
{
    PrepareAuraScript(spell_kaelthas_flame_strike);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FLAME_STRIKE_DAMAGE });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_FLAME_STRIKE_DAMAGE);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_kaelthas_flame_strike::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 36976 - Summon Weapons
class spell_kaelthas_summon_weapons : public SpellScript
{
    PrepareSpellScript(spell_kaelthas_summon_weapons);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(SummonWeaponsSpells);
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        for (uint32 spell : SummonWeaponsSpells)
            caster->CastSpell(caster, spell, true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_kaelthas_summon_weapons::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 39497 - Remove Enchanted Weapons
class spell_kaelthas_remove_weapons : public SpellScript
{
    PrepareSpellScript(spell_kaelthas_remove_weapons);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(RemoveWeaponsSpells);
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        for (uint32 spell : RemoveWeaponsSpells)
            target->CastSpell(target, spell, TRIGGERED_FULL_MASK & ~TRIGGERED_IGNORE_POWER_AND_REAGENT_COST);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_kaelthas_remove_weapons::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 36091 - Kael Gaining Power
class spell_kaelthas_gaining_power : public AuraScript
{
    PrepareAuraScript(spell_kaelthas_gaining_power);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_NETHERBEAM_1, SPELL_NETHERBEAM_2, SPELL_NETHERBEAM_3 }) &&
            sSoundEntriesStore.LookupEntry(SOUND_PRECAST_NATURE_LOW) &&
            sSoundEntriesStore.LookupEntry(SOUND_PRECAST_FROST_HIGH);
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->PlayDirectSound(SOUND_PRECAST_NATURE_LOW);
        target->PlayDirectSound(SOUND_PRECAST_FROST_HIGH);
    }

    void OnPeriodic(AuraEffect const* aurEff)
    {
        Unit* target = GetTarget();

        switch (aurEff->GetTickNumber())
        {
            case 1:
                target->CastSpell(target, SPELL_NETHERBEAM_1, true);
                target->PlayDirectSound(SOUND_PRECAST_NATURE_LOW);
                target->PlayDirectSound(SOUND_PRECAST_FROST_HIGH);
                break;
            case 2:
                target->RemoveAurasDueToSpell(SPELL_NETHERBEAM_1);
                target->CastSpell(target, SPELL_NETHERBEAM_2, true);
                target->PlayDirectSound(SOUND_PRECAST_NATURE_LOW);
                target->PlayDirectSound(SOUND_PRECAST_FROST_HIGH);
                break;
            case 3:
                target->RemoveAurasDueToSpell(SPELL_NETHERBEAM_2);
                target->CastSpell(target, SPELL_NETHERBEAM_3, true);
                target->PlayDirectSound(SOUND_PRECAST_NATURE_LOW);
                target->PlayDirectSound(SOUND_PRECAST_FROST_HIGH);
                break;
            default:
                break;
        }
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_kaelthas_gaining_power::AfterApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_kaelthas_gaining_power::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 36092 - Kael Explodes
class spell_kaelthas_explodes : public SpellScript
{
    PrepareSpellScript(spell_kaelthas_explodes);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_KAEL_GAINING_POWER, SPELL_NETHERBEAM_3 }) &&
            sSoundEntriesStore.LookupEntry(SOUND_EXORCISM) &&
            sSoundEntriesStore.LookupEntry(SOUND_FIRE_WARD_TARGET) &&
            sSoundEntriesStore.LookupEntry(SOUND_ARCANE_EXPLOSION);
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        caster->RemoveAurasDueToSpell(SPELL_KAEL_GAINING_POWER);
        caster->RemoveAurasDueToSpell(SPELL_NETHERBEAM_3);
        caster->PlayDirectSound(SOUND_EXORCISM);
        caster->PlayDirectSound(SOUND_FIRE_WARD_TARGET);
        caster->PlayDirectSound(SOUND_ARCANE_EXPLOSION);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_kaelthas_explodes::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 36201, 36290, 36291 - Pure Nether Beam
class spell_kaelthas_pure_nether_beam : public SpellScript
{
    PrepareSpellScript(spell_kaelthas_pure_nether_beam);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PURE_NETHER_BEAM_1, SPELL_PURE_NETHER_BEAM_2, SPELL_PURE_NETHER_BEAM_3 }) &&
            sSoundEntriesStore.LookupEntry(SOUND_GHOSTLY_STRIKE_IMPACT) &&
            sSoundEntriesStore.LookupEntry(SOUND_HOLY_BOLT);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        target->PlayDirectSound(SOUND_GHOSTLY_STRIKE_IMPACT);
        target->PlayDirectSound(SOUND_HOLY_BOLT);
        target->CastSpell(target, RAND(SPELL_PURE_NETHER_BEAM_1, SPELL_PURE_NETHER_BEAM_2, SPELL_PURE_NETHER_BEAM_3));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_kaelthas_pure_nether_beam::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_kaelthas_pure_nether_beam::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 36196, 36197, 36198 - Pure Nether Beam
class spell_kaelthas_pure_nether_beam_visual : public SpellScript
{
    PrepareSpellScript(spell_kaelthas_pure_nether_beam_visual);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_1, 0);
        GetHitUnit()->SendPlaySpellVisualKit(SPELL_VISUAL_KIT_2, 0);
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_kaelthas_pure_nether_beam_visual::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 35865 - Summon Nether Vapor
class spell_kaelthas_summon_nether_vapor : public SpellScript
{
    PrepareSpellScript(spell_kaelthas_summon_nether_vapor);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(SummonNetherVaporSpells);
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        for (uint32 spell : SummonNetherVaporSpells)
            caster->CastSpell(caster, spell, true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_kaelthas_summon_nether_vapor::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 35861, 35862, 35863, 35864 - Summon Nether Vapor
class spell_kaelthas_summon_nether_vapor_effect : public SpellScript
{
    PrepareSpellScript(spell_kaelthas_summon_nether_vapor_effect);

    void SetDest(SpellDestination& dest)
    {
        dest.RelocateOffset({ 0.0f, 0.0f, 5.0f });
    }

    void Register() override
    {
        switch (m_scriptSpellId)
        {
            case SPELL_SUMMON_NETHER_VAPOR_1:
                OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_kaelthas_summon_nether_vapor_effect::SetDest, EFFECT_0, TARGET_DEST_CASTER_FRONT);
                break;
            case SPELL_SUMMON_NETHER_VAPOR_2:
                OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_kaelthas_summon_nether_vapor_effect::SetDest, EFFECT_0, TARGET_DEST_CASTER_LEFT);
                break;
            case SPELL_SUMMON_NETHER_VAPOR_3:
                OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_kaelthas_summon_nether_vapor_effect::SetDest, EFFECT_0, TARGET_DEST_CASTER_RIGHT);
                break;
            case SPELL_SUMMON_NETHER_VAPOR_4:
                OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_kaelthas_summon_nether_vapor_effect::SetDest, EFFECT_0, TARGET_DEST_CASTER_BACK);
                break;
            default:
                break;
        }
    }
};

// 45960 - Nether Vapor Lightning
class spell_kaelthas_nether_vapor_lightning : public AuraScript
{
    PrepareAuraScript(spell_kaelthas_nether_vapor_lightning);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ uint32(spellInfo->GetEffect(EFFECT_0).CalcValue()) });
    }

    void OnPeriodic(AuraEffect const* aurEff)
    {
        GetTarget()->CastSpell(GetTarget()->GetNearPosition(10.0f, frand(0.0f, 2.0f * float(M_PI))), aurEff->GetAmount());
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_kaelthas_nether_vapor_lightning::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 35869 - Nether Beam
class spell_kaelthas_nether_beam : public SpellScript
{
    PrepareSpellScript(spell_kaelthas_nether_beam);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_NETHER_BEAM_CHAIN });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Creature* caster = GetCaster()->ToCreature())
        {
            std::vector<Unit*> targets;
            for (ThreatReference const* ref : caster->GetThreatManager().GetUnsortedThreatList())
                targets.push_back(ref->GetVictim());

            Trinity::Containers::RandomResize(targets, 5);

            for (Unit* target : targets)
                caster->CastSpell(target, SPELL_NETHER_BEAM_CHAIN, true);
        }
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_kaelthas_nether_beam::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_boss_kaelthas()
{
    RegisterTheEyeCreatureAI(boss_kaelthas);
    RegisterTheEyeCreatureAI(boss_thaladred_the_darkener);
    RegisterTheEyeCreatureAI(boss_lord_sanguinar);
    RegisterTheEyeCreatureAI(boss_grand_astromancer_capernian);
    RegisterTheEyeCreatureAI(boss_master_engineer_telonicus);
    RegisterTheEyeCreatureAI(npc_kaelthas_controller);
    RegisterTheEyeCreatureAI(npc_flame_strike_trigger_kael);
    RegisterTheEyeCreatureAI(npc_phoenix_the_eye);
    RegisterTheEyeCreatureAI(npc_phoenix_egg_the_eye);
    RegisterTheEyeCreatureAI(npc_nether_vapor);
    RegisterSpellAndAuraScriptPair(spell_kaelthas_mind_control, spell_kaelthas_mind_control_aura);
    RegisterSpellScript(spell_kaelthas_shock_barrier);
    RegisterSpellScript(spell_kaelthas_pyroblast);
    RegisterSpellScript(spell_kaelthas_remote_toy);
    RegisterSpellScript(spell_kaelthas_gravity_lapse);
    RegisterSpellScript(spell_kaelthas_gravity_lapse_periodic);
    RegisterSpellScript(spell_kaelthas_flame_strike);
    RegisterSpellScript(spell_kaelthas_summon_weapons);
    RegisterSpellScript(spell_kaelthas_remove_weapons);
    RegisterSpellScript(spell_kaelthas_gaining_power);
    RegisterSpellScript(spell_kaelthas_explodes);
    RegisterSpellScript(spell_kaelthas_pure_nether_beam);
    RegisterSpellScript(spell_kaelthas_pure_nether_beam_visual);
    RegisterSpellScript(spell_kaelthas_summon_nether_vapor);
    RegisterSpellScript(spell_kaelthas_summon_nether_vapor_effect);
    RegisterSpellScript(spell_kaelthas_nether_vapor_lightning);
    RegisterSpellScript(spell_kaelthas_nether_beam);
}
