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

#include "ScriptMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "GridNotifiers.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "ulduar.h"
#include "Vehicle.h"

enum Yells
{
    SAY_AGGRO                                   = 0,
    SAY_HARDMODE_ON                             = 1,
    SAY_MKII_ACTIVATE                           = 2,
    SAY_MKII_SLAY                               = 3,
    SAY_MKII_DEATH                              = 4,
    SAY_VX001_ACTIVATE                          = 5,
    SAY_VX001_SLAY                              = 6,
    SAY_VX001_DEATH                             = 7,
    SAY_AERIAL_ACTIVATE                         = 8,
    SAY_AERIAL_SLAY                             = 9,
    SAY_AERIAL_DEATH                            = 10,
    SAY_V07TRON_ACTIVATE                        = 11,
    SAY_V07TRON_SLAY                            = 12,
    SAY_V07TRON_DEATH                           = 13,
    SAY_BERSERK                                 = 14
};

enum ComputerYells
{
    SAY_SELF_DESTRUCT_INITIATED                 = 0,
    SAY_SELF_DESTRUCT_TERMINATED                = 1,
    SAY_SELF_DESTRUCT_10                        = 2,
    SAY_SELF_DESTRUCT_9                         = 3,
    SAY_SELF_DESTRUCT_8                         = 4,
    SAY_SELF_DESTRUCT_7                         = 5,
    SAY_SELF_DESTRUCT_6                         = 6,
    SAY_SELF_DESTRUCT_5                         = 7,
    SAY_SELF_DESTRUCT_4                         = 8,
    SAY_SELF_DESTRUCT_3                         = 9,
    SAY_SELF_DESTRUCT_2                         = 10,
    SAY_SELF_DESTRUCT_1                         = 11,
    SAY_SELF_DESTRUCT_FINALIZED                 = 12
};

enum Spells
{
    // Mimiron
    SPELL_WELD                                  = 63339, // Idle aura.
    SPELL_SEAT_1                                = 52391, // Cast on all vehicles, Cycled on MKII
    SPELL_SEAT_2                                = 63313, // Cast on MKII and VX-001, Cycled on MKII
    SPELL_SEAT_3                                = 63314, // Cast on MKII, Cycled on MKII
    SPELL_SEAT_5                                = 63316, // Cast on MKII and VX-001, Cycled on MKII
    SPELL_SEAT_6                                = 63344, // Cast on MKII
    SPELL_SEAT_7                                = 63345, // Cast on MKII
    SPELL_JETPACK                               = 63341,
    SPELL_DESPAWN_ASSAULT_BOTS                  = 64463, // only despawns assault bots... no equivalent spell for the other adds...
    SPELL_TELEPORT_VISUAL                       = 41232,
    SPELL_SLEEP_VISUAL_1                        = 64393,
    SPELL_SLEEP_VISUAL_2                        = 64394,

    // Leviathan MK II
    SPELL_FLAME_SUPPRESSANT_MK                  = 64570,
    SPELL_NAPALM_SHELL                          = 63666,
    SPELL_FORCE_CAST_NAPALM_SHELL               = 64539,
    SPELL_PLASMA_BLAST                          = 62997,
    SPELL_SCRIPT_EFFECT_PLASMA_BLAST            = 64542,
    SPELL_SHOCK_BLAST                           = 63631,
    SPELL_SHOCK_BLAST_AURA                      = 63632, // Deprecated? It is never cast.

    // VX-001
    SPELL_FLAME_SUPPRESSANT_VX                  = 65192,
    SPELL_SPINNING_UP                           = 63414,
    SPELL_HEAT_WAVE_AURA                        = 63679,
    SPELL_HAND_PULSE_LEFT                       = 64348,
    SPELL_HAND_PULSE_RIGHT                      = 64352,
    SPELL_MOUNT_MKII                            = 64387,
    SPELL_TORSO_DISABLED                        = 64120,

    // Aerial Command Unit
    SPELL_PLASMA_BALL_P1                        = 63689,
    SPELL_PLASMA_BALL_P2                        = 65647,
    SPELL_MOUNT_VX_001                          = 64388,

    // Proximity Mines
    SPELL_PROXIMITY_MINES                       = 63027, // Cast by Leviathan MK II
    SPELL_PROXIMITY_MINE_EXPLOSION              = 66351,
    SPELL_PROXIMITY_MINE_TRIGGER                = 65346,
    SPELL_PROXIMITY_MINE_PERIODIC_TRIGGER       = 65345,
    SPELL_PERIODIC_PROXIMITY_AURA               = 65345,
    SPELL_SUMMON_PROXIMITY_MINE                 = 65347,

    // Rapid Burst
    SPELL_RAPID_BURST_LEFT                      = 63387,
    SPELL_RAPID_BURST_RIGHT                     = 64019,
    SPELL_RAPID_BURST                           = 63382, // Cast by VX-001
    SPELL_RAPID_BURST_TARGET_ME                 = 64841, // Cast by Burst Target
    SPELL_SUMMON_BURST_TARGET                   = 64840, // Cast by VX-001

    // Rocket Strike
    SPELL_SUMMON_ROCKET_STRIKE                  = 63036,
    SPELL_SCRIPT_EFFECT_ROCKET_STRIKE           = 63681, // Cast by Rocket (Mimiron Visual)
    SPELL_ROCKET_STRIKE                         = 64064, // Added in creature_template_addon
    SPELL_ROCKET_STRIKE_SINGLE                  = 64402, // Cast by VX-001
    SPELL_ROCKET_STRIKE_BOTH                    = 65034, // Cast by VX-001

    // Flames
    SPELL_FLAMES_PERIODIC_TRIGGER               = 64561, // Added in creature_template_addon
    SPELL_SUMMON_FLAMES_SPREAD_TRIGGER          = 64562,
    SPELL_SUMMON_FLAMES_INITIAL                 = 64563,
    SPELL_SUMMON_FLAMES_SPREAD                  = 64564,
    SPELL_FLAMES                                = 64566,
    SPELL_SCRIPT_EFFECT_SUMMON_FLAMES_INITIAL   = 64567,

    // Frost Bomb
    SPELL_SCRIPT_EFFECT_FROST_BOMB              = 64623, // Cast by VX-001
    SPELL_FROST_BOMB_LINKED                     = 64624, // Added in creature_template_addon
    SPELL_FROST_BOMB_DUMMY                      = 64625,
    SPELL_SUMMON_FROST_BOMB                     = 64627, // Cast by VX-001
    SPELL_FROST_BOMB_EXPLOSION                  = 64626,
    SPELL_CLEAR_FIRES                           = 65354,

    // Bots
    SPELL_SUMMON_FIRE_BOT                       = 64622,
    SPELL_SUMMON_FIRE_BOT_DUMMY                 = 64621,
    SPELL_SUMMON_FIRE_BOT_TRIGGER               = 64620, // Cast by Areal Command Unit
    SPELL_DEAFENING_SIREN                       = 64616, // Added in creature_template_addon
    SPELL_FIRE_SEARCH_AURA                      = 64617, // Added in creature_template_addon
    SPELL_FIRE_SEARCH                           = 64618,
    SPELL_WATER_SPRAY                           = 64619,

    SPELL_SUMMON_JUNK_BOT                       = 63819,
    SPELL_SUMMON_JUNK_BOT_TRIGGER               = 63820, // Cast by Areal Command Unit
    SPELL_SUMMON_JUNK_BOT_DUMMY                 = 64398,

    SPELL_SUMMON_ASSAULT_BOT_TRIGGER            = 64425, // Cast by Areal Command Unit
    SPELL_SUMMON_ASSAULT_BOT_DUMMY              = 64426,
    SPELL_SUMMON_ASSAULT_BOT                    = 64427,
    SPELL_MAGNETIC_FIELD                        = 64668,

    SPELL_SUMMON_BOMB_BOT                       = 63811, // Cast by Areal Command Unit
    SPELL_BOMB_BOT_AURA                         = 63767, // Added in creature_template_addon

    // Miscellaneous
    SPELL_SELF_DESTRUCTION_AURA                 = 64610,
    SPELL_SELF_DESTRUCTION_VISUAL               = 64613,
    SPELL_NOT_SO_FRIENDLY_FIRE                  = 65040,
    SPELL_ELEVATOR_KNOCKBACK                    = 65096, // Cast by worldtrigger.
    SPELL_VEHICLE_DAMAGED                       = 63415,
    SPELL_EMERGENCY_MODE                        = 64582, // mkii, vx001, aerial, assault, junk
    SPELL_EMERGENCY_MODE_TURRET                 = 65101, // Cast by Leviathan MK II, only hits Leviathan MK II turret
    SPELL_SELF_REPAIR                           = 64383,
    SPELL_MAGNETIC_CORE                         = 64436,
    SPELL_MAGNETIC_CORE_VISUAL                  = 64438,
    SPELL_HALF_HEAL                             = 64188,
    SPELL_CLEAR_ALL_DEBUFFS                     = 34098, /// @todo: make use of this spell...
    SPELL_FREEZE_ANIM_STUN                      = 63354, // used to prevent mkii from doing stuff?..
    SPELL_FREEZE_ANIM                           = 16245  // Idle aura. Freezes animation.
};

enum Data
{
    DATA_SETUP_MINE,
    DATA_SETUP_BOMB,
    DATA_SETUP_ROCKET,
    DATA_NOT_SO_FRIENDLY_FIRE,
    DATA_FIREFIGHTER,
    DATA_WATERSPRAY,
    DATA_MOVE_NEW
};

enum Events
{
    // Leviathan MK II
    EVENT_PROXIMITY_MINE = 1,
    EVENT_NAPALM_SHELL,
    EVENT_PLASMA_BLAST,
    EVENT_SHOCK_BLAST,
    EVENT_FLAME_SUPPRESSANT_MK,
    EVENT_MOVE_POINT_2,
    EVENT_MOVE_POINT_3,
    EVENT_MOVE_POINT_5,

    // VX-001
    EVENT_RAPID_BURST,
    EVENT_SPINNING_UP,
    EVENT_ROCKET_STRIKE,
    EVENT_HAND_PULSE,
    EVENT_FROST_BOMB,
    EVENT_FLAME_SUPPRESSANT_VX,
    EVENT_RELOAD,

    // Aerial Command Unit
    EVENT_SUMMON_FIRE_BOTS,
    EVENT_SUMMON_JUNK_BOT,
    EVENT_SUMMON_ASSAULT_BOT,
    EVENT_SUMMON_BOMB_BOT,

    // Mimiron
    EVENT_SUMMON_FLAMES,
    EVENT_INTRO_1,
    EVENT_INTRO_2,
    EVENT_INTRO_3,

    EVENT_VX001_ACTIVATION_1,
    EVENT_VX001_ACTIVATION_2,
    EVENT_VX001_ACTIVATION_3,
    EVENT_VX001_ACTIVATION_4,
    EVENT_VX001_ACTIVATION_5,
    EVENT_VX001_ACTIVATION_6,
    EVENT_VX001_ACTIVATION_7,
    EVENT_VX001_ACTIVATION_8,
    EVENT_VX001_ACTIVATION_9,

    EVENT_AERIAL_ACTIVATION_1,
    EVENT_AERIAL_ACTIVATION_2,
    EVENT_AERIAL_ACTIVATION_3,
    EVENT_AERIAL_ACTIVATION_4,
    EVENT_AERIAL_ACTIVATION_5,
    EVENT_AERIAL_ACTIVATION_6,

    EVENT_VOL7RON_ACTIVATION_1,
    EVENT_VOL7RON_ACTIVATION_2,
    EVENT_VOL7RON_ACTIVATION_3,
    EVENT_VOL7RON_ACTIVATION_4,
    EVENT_VOL7RON_ACTIVATION_5,
    EVENT_VOL7RON_ACTIVATION_6,
    EVENT_VOL7RON_ACTIVATION_7,

    EVENT_OUTTRO_1,
    EVENT_OUTTRO_2,
    EVENT_OUTTRO_3,

    // Computer
    EVENT_SELF_DESTRUCT_10,
    EVENT_SELF_DESTRUCT_9,
    EVENT_SELF_DESTRUCT_8,
    EVENT_SELF_DESTRUCT_7,
    EVENT_SELF_DESTRUCT_6,
    EVENT_SELF_DESTRUCT_5,
    EVENT_SELF_DESTRUCT_4,
    EVENT_SELF_DESTRUCT_3,
    EVENT_SELF_DESTRUCT_2,
    EVENT_SELF_DESTRUCT_1,
    EVENT_SELF_DESTRUCT_FINALIZED,

    // Misc
    EVENT_MAGNETIC_FIELD,
    EVENT_SPREAD_FLAMES,
    EVENT_FROST_BOMB_EXPLOSION,
    EVENT_FROST_BOMB_CLEAR_FIRES,
    EVENT_PROXIMITY_MINE_ARM,
    EVENT_PROXIMITY_MINE_DETONATION,
    EVENT_SEARCH_FLAMES,
    EVENT_WATER_SPRAY
};

enum Actions
{
    DO_START_MKII,
    DO_HARDMODE_MKII,

    DO_ACTIVATE_VX001,
    DO_START_VX001,
    DO_HARDMODE_VX001,

    DO_ACTIVATE_AERIAL,
    DO_START_AERIAL,
    DO_HARDMODE_AERIAL,
    DO_DISABLE_AERIAL,
    DO_ENABLE_AERIAL,

    DO_ACTIVATE_V0L7R0N_1,
    DO_ACTIVATE_V0L7R0N_2,
    DO_ASSEMBLED_COMBAT, // All 3 parts use this action, its done on purpose.

    DO_ACTIVATE_HARD_MODE,
    DO_ACTIVATE_COMPUTER,
    DO_DEACTIVATE_COMPUTER,
    DO_ACTIVATE_SELF_DESTRUCT,

    DO_ENCOUNTER_DONE
};

enum Phases
{
    PHASE_LEVIATHAN_MK_II = 1,
    PHASE_VX_001,
    PHASE_AERIAL_COMMAND_UNIT,
    PHASE_VOL7RON
};

enum Waypoints
{
    WP_MKII_P1_IDLE = 1,
    WP_MKII_P4_POS_1,
    WP_MKII_P4_POS_2,
    WP_MKII_P4_POS_3,
    WP_MKII_P4_POS_4,
    WP_MKII_P4_POS_5,
    WP_AERIAL_P4_POS
};

enum SeatIds : int8
{
    MKII_SEAT_CANNON  = 3,
    ROCKET_SEAT_LEFT  = 5,
    ROCKET_SEAT_RIGHT = 6
};

uint32 const RepairSpells[4] =
{
    SPELL_SEAT_1,
    SPELL_SEAT_2,
    SPELL_SEAT_3,
    SPELL_SEAT_5
};

Position const VehicleRelocation[] =
{
    { 0.0f, 0.0f, 0.0f},
    { 2792.070f, 2596.320f, 364.3136f }, // WP_MKII_P1_IDLE
    { 2765.945f, 2571.095f, 364.0636f }, // WP_MKII_P4_POS_1
    { 2768.195f, 2573.095f, 364.0636f }, // WP_MKII_P4_POS_2
    { 2763.820f, 2568.870f, 364.3136f }, // WP_MKII_P4_POS_3
    { 2761.215f, 2568.875f, 364.0636f }, // WP_MKII_P4_POS_4
    { 2744.610f, 2569.380f, 364.3136f }, // WP_MKII_P4_POS_5
    { 2744.62f,  2569.41f,  382.0f, 3.054326f }  // WP_AERIAL_P4_POS
};

Position const VX001SummonPos = { 2744.431f, 2569.385f, 364.3968f, 3.141593f };
Position const ACUSummonPos   = { 2744.650f, 2569.460f, 380.0000f, 3.141593f };

static bool IsEncounterFinished(Unit* who)
{
    InstanceScript* instance = who->GetInstanceScript();

    Creature* mkii = ObjectAccessor::GetCreature(*who, instance->GetGuidData(DATA_LEVIATHAN_MK_II));
    Creature* vx001 = ObjectAccessor::GetCreature(*who, instance->GetGuidData(DATA_VX_001));
    Creature* aerial = ObjectAccessor::GetCreature(*who, instance->GetGuidData(DATA_AERIAL_COMMAND_UNIT));
    if (!mkii || !vx001 || !aerial)
        return false;

    if (mkii->GetStandState() == UNIT_STAND_STATE_DEAD &&
        vx001->GetStandState() == UNIT_STAND_STATE_DEAD &&
        aerial->GetStandState() == UNIT_STAND_STATE_DEAD)
    {
        Unit::Kill(who, mkii);
        Unit::Kill(who, vx001);
        Unit::Kill(who, aerial);
        mkii->DespawnOrUnsummon(120000);
        vx001->DespawnOrUnsummon(120000);
        aerial->DespawnOrUnsummon(120000);
        if (Creature* mimiron = instance->GetCreature(BOSS_MIMIRON))
            mimiron->AI()->JustDied(who);
        return true;
    }
    return false;
}

class boss_mimiron : public CreatureScript
{
    public:
        boss_mimiron() : CreatureScript("boss_mimiron") { }

        struct boss_mimironAI : public BossAI
        {
            boss_mimironAI(Creature* creature) : BossAI(creature, BOSS_MIMIRON)
            {
                me->SetReactState(REACT_PASSIVE);
                _fireFighter = false;
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case DO_ACTIVATE_VX001:
                        events.ScheduleEvent(EVENT_VX001_ACTIVATION_1, 1000);
                        break;
                    case DO_ACTIVATE_AERIAL:
                        events.ScheduleEvent(EVENT_AERIAL_ACTIVATION_1, 5000);
                        break;
                    case DO_ACTIVATE_V0L7R0N_1:
                        Talk(SAY_AERIAL_DEATH);
                        if (Creature* mkii = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_LEVIATHAN_MK_II)))
                            mkii->GetMotionMaster()->MovePoint(WP_MKII_P4_POS_1, VehicleRelocation[WP_MKII_P4_POS_1]);
                        break;
                    case DO_ACTIVATE_V0L7R0N_2:
                        events.ScheduleEvent(EVENT_VOL7RON_ACTIVATION_1, 1000);
                        break;
                    case DO_ACTIVATE_HARD_MODE:
                        _fireFighter = true;
                        DoZoneInCombat(me);
                        break;
                    default:
                        break;
                }
            }

            void JustEngagedWith(Unit* who) override
            {
                if (!me->GetVehicleBase())
                    return;

                BossAI::JustEngagedWith(who);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->RemoveAurasDueToSpell(SPELL_WELD);
                DoCast(me->GetVehicleBase(), SPELL_SEAT_6);

                if (GameObject* button = instance->GetGameObject(DATA_MIMIRON_BUTTON))
                    button->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);

                if (_fireFighter)
                    events.ScheduleEvent(EVENT_SUMMON_FLAMES, 3s);
                events.ScheduleEvent(EVENT_INTRO_1, 1500);
            }

            void JustDied(Unit* /*killer*/) override
            {
                instance->SetBossState(BOSS_MIMIRON, DONE);
                events.Reset();
                me->CombatStop(true);
                me->SetDisableGravity(false);
                DoCast(me, SPELL_SLEEP_VISUAL_1);
                DoCastAOE(SPELL_DESPAWN_ASSAULT_BOTS);
                me->ExitVehicle();
                // ExitVehicle() offset position is not implemented, so we make up for that with MoveJump()...
                me->GetMotionMaster()->MoveJump(me->GetPositionX() + (10.f * std::cos(me->GetOrientation())), me->GetPositionY() + (10.f * std::sin(me->GetOrientation())), me->GetPositionZ(), me->GetOrientation(), 10.f, 5.f);
                events.ScheduleEvent(EVENT_OUTTRO_1, 7000);
            }

            void Reset() override
            {
                if (instance->GetBossState(BOSS_MIMIRON) == DONE) // Mimiron will attempt to reset because he is not dead and will be set to friendly before despawning.
                    return;

                if (Creature* aerial = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_AERIAL_COMMAND_UNIT)))
                    aerial->AI()->EnterEvadeMode();

                _Reset();
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

                if (GameObject* elevator = instance->GetGameObject(DATA_MIMIRON_ELEVATOR))
                    elevator->SetGoState(GO_STATE_ACTIVE);

                if (_fireFighter)
                    if (Creature* computer = instance->GetCreature(DATA_COMPUTER))
                        computer->AI()->DoAction(DO_DEACTIVATE_COMPUTER);

                if (GameObject* button = instance->GetGameObject(DATA_MIMIRON_BUTTON))
                {
                    button->SetGoState(GO_STATE_READY);
                    button->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                }

                _fireFighter = false;
                DoCast(me, SPELL_WELD);

                if (Unit* mkii = ObjectAccessor::GetUnit(*me, instance->GetGuidData(DATA_LEVIATHAN_MK_II)))
                    DoCast(mkii, SPELL_SEAT_3);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() && instance->GetBossState(BOSS_MIMIRON) != DONE)
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SUMMON_FLAMES:
                            if (Creature* worldtrigger = instance->GetCreature(DATA_MIMIRON_WORLD_TRIGGER))
                                worldtrigger->CastSpell(nullptr, SPELL_SCRIPT_EFFECT_SUMMON_FLAMES_INITIAL, CastSpellExtraArgs(me->GetGUID()).AddSpellMod(SPELLVALUE_MAX_TARGETS, 3));
                            events.RescheduleEvent(EVENT_SUMMON_FLAMES, 28000);
                            break;
                        case EVENT_INTRO_1:
                            Talk(_fireFighter ? SAY_HARDMODE_ON : SAY_MKII_ACTIVATE);
                            events.ScheduleEvent(EVENT_INTRO_2, 5000);
                            break;
                        case EVENT_INTRO_2:
                            if (Unit* mkii = me->GetVehicleBase())
                            {
                                DoCast(mkii, SPELL_SEAT_7);
                                mkii->RemoveAurasDueToSpell(SPELL_FREEZE_ANIM);
                                mkii->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                            }
                            events.ScheduleEvent(EVENT_INTRO_3, 2000);
                            break;
                        case EVENT_INTRO_3:
                            if (Creature* mkii = me->GetVehicleCreatureBase())
                                mkii->AI()->DoAction(_fireFighter ? DO_HARDMODE_MKII : DO_START_MKII);
                            break;
                        case EVENT_VX001_ACTIVATION_1:
                            if (Unit* mkii = me->GetVehicleBase())
                                mkii->SetFacingTo(3.686f); // fix magic number
                            events.ScheduleEvent(EVENT_VX001_ACTIVATION_2, 1000);
                            break;
                        case EVENT_VX001_ACTIVATION_2:
                            if (Unit* mkii = me->GetVehicleBase())
                                DoCast(mkii, SPELL_SEAT_6);
                            events.ScheduleEvent(EVENT_VX001_ACTIVATION_3, 1000);
                            break;
                        case EVENT_VX001_ACTIVATION_3:
                            Talk(SAY_MKII_DEATH);
                            events.ScheduleEvent(EVENT_VX001_ACTIVATION_4, 5000);
                            break;
                        case EVENT_VX001_ACTIVATION_4:
                            if (GameObject* elevator = instance->GetGameObject(DATA_MIMIRON_ELEVATOR))
                                elevator->SetGoState(GO_STATE_READY);
                            if (Creature* worldtrigger = instance->GetCreature(DATA_MIMIRON_WORLD_TRIGGER))
                                worldtrigger->CastSpell(worldtrigger, SPELL_ELEVATOR_KNOCKBACK);
                            events.ScheduleEvent(EVENT_VX001_ACTIVATION_5, 6000);
                            break;
                        case EVENT_VX001_ACTIVATION_5:
                            if (GameObject* elevator = instance->GetGameObject(DATA_MIMIRON_ELEVATOR))
                                elevator->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                            if (Creature* vx001 = me->SummonCreature(NPC_VX_001, VX001SummonPos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 120000))
                                vx001->CastSpell(vx001, SPELL_FREEZE_ANIM);
                            events.ScheduleEvent(EVENT_VX001_ACTIVATION_6, 19000);
                            break;
                        case EVENT_VX001_ACTIVATION_6:
                            if (Unit* vx001 = ObjectAccessor::GetUnit(*me, instance->GetGuidData(DATA_VX_001)))
                                DoCast(vx001, SPELL_SEAT_1);
                            events.ScheduleEvent(EVENT_VX001_ACTIVATION_7, 3500);
                            break;
                        case EVENT_VX001_ACTIVATION_7:
                            Talk(SAY_VX001_ACTIVATE);
                            events.ScheduleEvent(EVENT_VX001_ACTIVATION_8, 4000);
                            break;
                        case EVENT_VX001_ACTIVATION_8:
                            if (Unit* vx001 = me->GetVehicleBase())
                                DoCast(vx001, SPELL_SEAT_2);
                            events.ScheduleEvent(EVENT_VX001_ACTIVATION_9, 3000);
                            break;
                        case EVENT_VX001_ACTIVATION_9:
                            if (Creature* vx001 = me->GetVehicleCreatureBase())
                                vx001->AI()->DoAction(_fireFighter ? DO_HARDMODE_VX001 : DO_START_VX001);
                            break;
                        case EVENT_AERIAL_ACTIVATION_1:
                            if (Unit* mkii = me->GetVehicleBase())
                                DoCast(mkii, SPELL_SEAT_5);
                            events.ScheduleEvent(EVENT_AERIAL_ACTIVATION_2, 2500);
                            break;
                        case EVENT_AERIAL_ACTIVATION_2:
                            Talk(SAY_VX001_DEATH);
                            events.ScheduleEvent(EVENT_AERIAL_ACTIVATION_3, 5000);
                            break;
                        case EVENT_AERIAL_ACTIVATION_3:
                            me->SummonCreature(NPC_AERIAL_COMMAND_UNIT, ACUSummonPos, TEMPSUMMON_MANUAL_DESPAWN);
                            events.ScheduleEvent(EVENT_AERIAL_ACTIVATION_4, 5000);
                            break;
                        case EVENT_AERIAL_ACTIVATION_4:
                            if (Unit* aerial = ObjectAccessor::GetUnit(*me, instance->GetGuidData(DATA_AERIAL_COMMAND_UNIT)))
                                me->CastSpell(aerial, SPELL_SEAT_1);
                            events.ScheduleEvent(EVENT_AERIAL_ACTIVATION_5, 2000);
                            break;
                        case EVENT_AERIAL_ACTIVATION_5:
                            Talk(SAY_AERIAL_ACTIVATE);
                            events.ScheduleEvent(EVENT_AERIAL_ACTIVATION_6, 8000);
                            break;
                        case EVENT_AERIAL_ACTIVATION_6:
                            if (Creature* acu = me->GetVehicleCreatureBase())
                                acu->AI()->DoAction(_fireFighter? DO_HARDMODE_AERIAL : DO_START_AERIAL);
                            break;
                        case EVENT_VOL7RON_ACTIVATION_1:
                            if (Creature* mkii = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_LEVIATHAN_MK_II)))
                                mkii->SetFacingTo(float(M_PI));
                            events.ScheduleEvent(EVENT_VOL7RON_ACTIVATION_2, 1000);
                            break;
                        case EVENT_VOL7RON_ACTIVATION_2:
                            if (Creature* mkii = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_LEVIATHAN_MK_II)))
                            {
                                if (Creature* vx001 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_VX_001)))
                                {
                                    vx001->RemoveAurasDueToSpell(SPELL_TORSO_DISABLED);
                                    vx001->CastSpell(mkii, SPELL_MOUNT_MKII);
                                }
                            }
                            events.ScheduleEvent(EVENT_VOL7RON_ACTIVATION_3, 4500);
                            break;
                        case EVENT_VOL7RON_ACTIVATION_3:
                            if (Creature* mkii = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_LEVIATHAN_MK_II)))
                                mkii->GetMotionMaster()->MovePoint(WP_MKII_P4_POS_4, VehicleRelocation[WP_MKII_P4_POS_4]);
                            events.ScheduleEvent(EVENT_VOL7RON_ACTIVATION_4, 5000);
                            break;
                        case EVENT_VOL7RON_ACTIVATION_4:
                            if (Creature* vx001 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_VX_001)))
                            {
                                if (Creature* aerial = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_AERIAL_COMMAND_UNIT)))
                                {
                                    aerial->SetByteValue(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_ANIM_TIER, 0);
                                    aerial->CastSpell(vx001, SPELL_MOUNT_VX_001);
                                    aerial->CastSpell(aerial, SPELL_HALF_HEAL);
                                }
                            }
                            events.ScheduleEvent(EVENT_VOL7RON_ACTIVATION_5, 4000);
                            break;
                        case EVENT_VOL7RON_ACTIVATION_5:
                            Talk(SAY_V07TRON_ACTIVATE);
                            events.ScheduleEvent(EVENT_VOL7RON_ACTIVATION_6, 3000);
                            break;
                        case EVENT_VOL7RON_ACTIVATION_6:
                            if (Creature* vx001 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_VX_001)))
                                DoCast(vx001, SPELL_SEAT_2);
                            events.ScheduleEvent(EVENT_VOL7RON_ACTIVATION_7, 5000);
                            break;
                        case EVENT_VOL7RON_ACTIVATION_7:
                            for (uint8 data = DATA_LEVIATHAN_MK_II; data <= DATA_AERIAL_COMMAND_UNIT; ++data)
                                if (Creature* mimironVehicle = ObjectAccessor::GetCreature(*me, instance->GetGuidData(data)))
                                    mimironVehicle->AI()->DoAction(DO_ASSEMBLED_COMBAT);
                            break;
                        case EVENT_OUTTRO_1:
                            me->RemoveAurasDueToSpell(SPELL_SLEEP_VISUAL_1);
                            DoCast(me, SPELL_SLEEP_VISUAL_2);
                            me->SetFaction(FACTION_FRIENDLY);
                            events.ScheduleEvent(EVENT_OUTTRO_2, 3000);
                            break;
                        case EVENT_OUTTRO_2:
                            Talk(SAY_V07TRON_DEATH);
                            if (_fireFighter)
                            {
                                if (Creature* computer = instance->GetCreature(DATA_COMPUTER))
                                    computer->AI()->DoAction(DO_DEACTIVATE_COMPUTER);
                                me->SummonGameObject(RAID_MODE(GO_CACHE_OF_INNOVATION_FIREFIGHTER, GO_CACHE_OF_INNOVATION_FIREFIGHTER_HERO), 2744.040f, 2569.352f, 364.3135f, 3.124123f, QuaternionData(0.f, 0.f, 0.9999619f, 0.008734641f), 604800);
                            }
                            else
                                me->SummonGameObject(RAID_MODE(GO_CACHE_OF_INNOVATION, GO_CACHE_OF_INNOVATION_HERO), 2744.040f, 2569.352f, 364.3135f, 3.124123f, QuaternionData(0.f, 0.f, 0.9999619f, 0.008734641f), 604800);
                            events.ScheduleEvent(EVENT_OUTTRO_3, 11000);
                            break;
                        case EVENT_OUTTRO_3:
                            DoCast(me, SPELL_TELEPORT_VISUAL);
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            me->DespawnOrUnsummon(1000); // sniffs say 6 sec after, but it doesnt matter.
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }
            }

        private:
            bool _fireFighter;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<boss_mimironAI>(creature);
        }
};

class boss_leviathan_mk_ii : public CreatureScript
{
    public:
        boss_leviathan_mk_ii() : CreatureScript("boss_leviathan_mk_ii") { }

        struct boss_leviathan_mk_iiAI : public BossAI
        {
            boss_leviathan_mk_iiAI(Creature* creature) : BossAI(creature, BOSS_MIMIRON)
            {
                _fireFighter = false;
                _setupMine = true;
                _setupBomb = true;
                _setupRocket = true;
            }

            void DamageTaken(Unit* who, uint32 &damage) override
            {
                if (damage >= me->GetHealth())
                {
                    damage = me->GetHealth() - 1; // Let creature fall to 1 hp, but do not let it die or damage itself with SetHealth().
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    DoCast(me, SPELL_VEHICLE_DAMAGED, true);
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    me->RemoveAllAurasExceptType(SPELL_AURA_CONTROL_VEHICLE, SPELL_AURA_MOD_INCREASE_HEALTH_PERCENT);

                    if (events.IsInPhase(PHASE_LEVIATHAN_MK_II))
                    {
                        me->CastStop();
                        if (Unit* turret = me->GetVehicleKit()->GetPassenger(MKII_SEAT_CANNON))
                            turret->KillSelf();

                        me->SetSpeedRate(MOVE_RUN, 1.5f);
                        me->GetMotionMaster()->MovePoint(WP_MKII_P1_IDLE, VehicleRelocation[WP_MKII_P1_IDLE]);
                    }
                    else if (events.IsInPhase(PHASE_VOL7RON))
                    {
                        me->SetStandState(UNIT_STAND_STATE_DEAD);

                        Unit* ref = who ? who : me;
                        if (IsEncounterFinished(ref))
                            return;

                        me->CastStop();
                        DoCast(me, SPELL_SELF_REPAIR);
                    }
                    events.Reset();
                }
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case DO_HARDMODE_MKII:
                        _fireFighter = true;
                        DoCast(me, SPELL_EMERGENCY_MODE);
                        DoCastAOE(SPELL_EMERGENCY_MODE_TURRET);
                        events.ScheduleEvent(EVENT_FLAME_SUPPRESSANT_MK, 1min, 0, PHASE_LEVIATHAN_MK_II);
                        /* fallthrough */
                    case DO_START_MKII:
                        me->SetReactState(REACT_AGGRESSIVE);
                        events.SetPhase(PHASE_LEVIATHAN_MK_II);

                        events.ScheduleEvent(EVENT_NAPALM_SHELL, 3s, 0, PHASE_LEVIATHAN_MK_II);
                        events.ScheduleEvent(EVENT_PLASMA_BLAST, 15s, 0, PHASE_LEVIATHAN_MK_II);
                        events.ScheduleEvent(EVENT_PROXIMITY_MINE, 5s);
                        events.ScheduleEvent(EVENT_SHOCK_BLAST, 18s);
                        break;
                    case DO_ASSEMBLED_COMBAT:
                        me->SetStandState(UNIT_STAND_STATE_STAND);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        me->SetReactState(REACT_AGGRESSIVE);

                        events.SetPhase(PHASE_VOL7RON);
                        events.ScheduleEvent(EVENT_PROXIMITY_MINE, 15000);
                        events.ScheduleEvent(EVENT_SHOCK_BLAST, 45000);
                        break;
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_SETUP_MINE:
                        return _setupMine;
                    case DATA_SETUP_BOMB:
                        return _setupBomb;
                    case DATA_SETUP_ROCKET:
                        return _setupRocket;
                    case DATA_FIREFIGHTER:
                        return _fireFighter;
                    default:
                        return 0;
                }
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    if (Creature* mimiron = instance->GetCreature(BOSS_MIMIRON))
                        mimiron->AI()->Talk(events.IsInPhase(PHASE_LEVIATHAN_MK_II) ? SAY_MKII_SLAY : SAY_V07TRON_SLAY);
            }

            void MovementInform(uint32 type, uint32 point) override
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                switch (point)
                {
                    case WP_MKII_P1_IDLE:
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        DoCast(me, SPELL_HALF_HEAL);

                        if (Creature* mimiron = instance->GetCreature(BOSS_MIMIRON))
                            mimiron->AI()->DoAction(DO_ACTIVATE_VX001);
                        break;
                    case WP_MKII_P4_POS_1:
                        events.ScheduleEvent(EVENT_MOVE_POINT_2, 1);
                        break;
                    case WP_MKII_P4_POS_2:
                        events.ScheduleEvent(EVENT_MOVE_POINT_3, 1);
                        break;
                    case WP_MKII_P4_POS_3:
                        if (Creature* mimiron = instance->GetCreature(BOSS_MIMIRON))
                            mimiron->AI()->DoAction(DO_ACTIVATE_V0L7R0N_2);
                        break;
                    case WP_MKII_P4_POS_4:
                        events.ScheduleEvent(EVENT_MOVE_POINT_5, 1);
                        break;
                    default:
                        break;
                }
            }

            void Reset() override
            {
                _Reset();
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_PASSIVE);
                _fireFighter = false;
                _setupMine = true;
                _setupBomb = true;
                _setupRocket = true;
                DoCast(me, SPELL_FREEZE_ANIM);
            }

            void SetData(uint32 id, uint32 data) override
            {
                switch (id)
                {
                    case DATA_SETUP_MINE:
                        _setupMine = data != 0;
                        break;
                    case DATA_SETUP_BOMB:
                        _setupBomb = data != 0;
                        break;
                    case DATA_SETUP_ROCKET:
                        _setupRocket = data != 0;
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_PROXIMITY_MINE:
                            DoCastAOE(SPELL_PROXIMITY_MINES);
                            events.RescheduleEvent(EVENT_PROXIMITY_MINE, 35000);
                            break;
                        case EVENT_PLASMA_BLAST:
                            DoCastVictim(SPELL_SCRIPT_EFFECT_PLASMA_BLAST);
                            events.RescheduleEvent(EVENT_PLASMA_BLAST, urand(30000, 45000), 0, PHASE_LEVIATHAN_MK_II);

                            if (events.GetTimeUntilEvent(EVENT_NAPALM_SHELL) < 9000)
                                events.RescheduleEvent(EVENT_NAPALM_SHELL, 9000, 0, PHASE_LEVIATHAN_MK_II); // The actual spell is cast by the turret, we should not let it interrupt itself.
                            break;
                        case EVENT_SHOCK_BLAST:
                            DoCastAOE(SPELL_SHOCK_BLAST);
                            events.RescheduleEvent(EVENT_SHOCK_BLAST, urand(34000, 36000));
                            break;
                        case EVENT_FLAME_SUPPRESSANT_MK:
                            DoCastAOE(SPELL_FLAME_SUPPRESSANT_MK);
                            events.RescheduleEvent(EVENT_FLAME_SUPPRESSANT_MK, 60000, 0, PHASE_LEVIATHAN_MK_II);
                            break;
                        case EVENT_NAPALM_SHELL:
                            DoCastAOE(SPELL_FORCE_CAST_NAPALM_SHELL);
                            events.RescheduleEvent(EVENT_NAPALM_SHELL, urand(6000, 15000), 0, PHASE_LEVIATHAN_MK_II);

                            if (events.GetTimeUntilEvent(EVENT_PLASMA_BLAST) < 2000)
                                events.RescheduleEvent(EVENT_PLASMA_BLAST, 2000, 0, PHASE_LEVIATHAN_MK_II);  // The actual spell is cast by the turret, we should not let it interrupt itself.
                            break;
                        case EVENT_MOVE_POINT_2:
                            me->GetMotionMaster()->MovePoint(WP_MKII_P4_POS_2, VehicleRelocation[WP_MKII_P4_POS_2]);
                            break;
                        case EVENT_MOVE_POINT_3:
                            me->GetMotionMaster()->MovePoint(WP_MKII_P4_POS_3, VehicleRelocation[WP_MKII_P4_POS_3]);
                            break;
                        case EVENT_MOVE_POINT_5:
                            me->GetMotionMaster()->MovePoint(WP_MKII_P4_POS_5, VehicleRelocation[WP_MKII_P4_POS_5]);
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
            bool _fireFighter;
            bool _setupMine;
            bool _setupBomb;
            bool _setupRocket;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<boss_leviathan_mk_iiAI>(creature);
        }
};

class boss_vx_001 : public CreatureScript
{
    public:
        boss_vx_001() : CreatureScript("boss_vx_001") { }

        struct boss_vx_001AI : public BossAI
        {
            boss_vx_001AI(Creature* creature) : BossAI(creature, BOSS_MIMIRON)
            {
                me->SetDisableGravity(true); // This is the unfold visual state of VX-001, it has to be set on create as it requires an objectupdate if set later.
                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_SPECIAL_UNARMED); // This is a hack to force the yet to be unfolded visual state.
                me->SetReactState(REACT_PASSIVE);
                _fireFighter = false;
            }

            void DamageTaken(Unit* who, uint32 &damage) override
            {
                if (damage >= me->GetHealth())
                {
                    damage = me->GetHealth() - 1; // Let creature fall to 1 hp, but do not let it die or damage itself with SetHealth().
                    me->AttackStop();
                    DoCast(me, SPELL_VEHICLE_DAMAGED, true);
                    me->RemoveAllAurasExceptType(SPELL_AURA_CONTROL_VEHICLE, SPELL_AURA_MOD_INCREASE_HEALTH_PERCENT);

                    if (events.IsInPhase(PHASE_VX_001))
                    {
                        me->CastStop();
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE); // | UNIT_FLAG_NOT_SELECTABLE);
                        DoCast(me, SPELL_HALF_HEAL); // has no effect, wat
                        DoCast(me, SPELL_TORSO_DISABLED);
                        if (Creature* mimiron = instance->GetCreature(BOSS_MIMIRON))
                            mimiron->AI()->DoAction(DO_ACTIVATE_AERIAL);
                    }
                    else if (events.IsInPhase(PHASE_VOL7RON))
                    {
                        me->SetStandState(UNIT_STAND_STATE_DEAD);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

                        Unit* ref = who ? who : me;
                        if (IsEncounterFinished(ref))
                            return;

                        me->CastStop();
                        DoCast(me, SPELL_SELF_REPAIR);
                    }
                    events.Reset();
                }
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case DO_HARDMODE_VX001:
                        _fireFighter = true;
                        DoCast(me, SPELL_EMERGENCY_MODE);
                        events.ScheduleEvent(EVENT_FROST_BOMB, 1s);
                        events.ScheduleEvent(EVENT_FLAME_SUPPRESSANT_VX, 6s);
                        /* fallthrough */
                    case DO_START_VX001:
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        me->SetImmuneToPC(false);
                        me->RemoveAurasDueToSpell(SPELL_FREEZE_ANIM);
                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE); // Remove emotestate.
                        //me->SetUInt32Value(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_ANIM_TIER, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER); Blizzard handles hover animation like this it seems.
                        DoCast(me, SPELL_HEAT_WAVE_AURA);

                        events.SetPhase(PHASE_VX_001);
                        events.ScheduleEvent(EVENT_ROCKET_STRIKE, 20s);
                        events.ScheduleEvent(EVENT_SPINNING_UP, 30s, 35s);
                        events.ScheduleEvent(EVENT_RAPID_BURST, 500, 0, PHASE_VX_001);
                        break;
                    case DO_ASSEMBLED_COMBAT:
                        me->SetStandState(UNIT_STAND_STATE_STAND);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);

                        events.SetPhase(PHASE_VOL7RON);
                        events.ScheduleEvent(EVENT_ROCKET_STRIKE, 20s);
                        events.ScheduleEvent(EVENT_SPINNING_UP, 30s, 35s);
                        events.ScheduleEvent(EVENT_HAND_PULSE, 500, 0, PHASE_VOL7RON);
                        if (_fireFighter)
                            events.ScheduleEvent(EVENT_FROST_BOMB, 1s);
                        break;
                    default:
                        break;
                }
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                summons.DespawnAll();
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);
                if (summon->GetEntry() == NPC_BURST_TARGET)
                    summon->CastSpell(me, SPELL_RAPID_BURST_TARGET_ME);
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    if (Creature* mimiron = instance->GetCreature(BOSS_MIMIRON))
                        mimiron->AI()->Talk(events.IsInPhase(PHASE_VX_001) ? SAY_VX001_SLAY : SAY_V07TRON_SLAY);
            }

            void SpellHit(Unit* caster, SpellInfo const* /*spellProto*/) override
            {
                if (caster->GetEntry() == NPC_BURST_TARGET && !me->HasUnitState(UNIT_STATE_CASTING))
                    DoCast(caster, SPELL_RAPID_BURST);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                // Handle rotation during SPELL_SPINNING_UP, SPELL_P3WX2_LASER_BARRAGE, SPELL_RAPID_BURST, and SPELL_HAND_PULSE_LEFT/RIGHT
                if (me->HasUnitState(UNIT_STATE_CASTING))
                {
                    if (Creature* channelTarget = ObjectAccessor::GetCreature(*me, me->GetChannelObjectGuid()))
                        me->SetFacingToObject(channelTarget);
                    return;
                }

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_RAPID_BURST:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 120, true))
                                DoCast(target, SPELL_SUMMON_BURST_TARGET);
                            events.RescheduleEvent(EVENT_RAPID_BURST, 3000, 0, PHASE_VX_001);
                            break;
                        case EVENT_ROCKET_STRIKE:
                            DoCastAOE(events.IsInPhase(PHASE_VX_001) ? SPELL_ROCKET_STRIKE_SINGLE : SPELL_ROCKET_STRIKE_BOTH);
                            events.ScheduleEvent(EVENT_RELOAD, 10s);
                            events.RescheduleEvent(EVENT_ROCKET_STRIKE, urand(20000, 25000));
                            break;
                        case EVENT_RELOAD:
                            for (int8 seat = ROCKET_SEAT_LEFT; seat <= ROCKET_SEAT_RIGHT; ++seat)
                                if (Unit* rocket = me->GetVehicleKit()->GetPassenger(seat))
                                    rocket->SetDisplayId(rocket->GetNativeDisplayId());
                            break;
                        case EVENT_HAND_PULSE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 120, true))
                                DoCast(target, RAND(SPELL_HAND_PULSE_LEFT, SPELL_HAND_PULSE_RIGHT));
                            events.RescheduleEvent(EVENT_HAND_PULSE, urand(1500, 3000), 0, PHASE_VOL7RON);
                            break;
                        case EVENT_FROST_BOMB:
                            DoCastAOE(SPELL_SCRIPT_EFFECT_FROST_BOMB);
                            events.RescheduleEvent(EVENT_FROST_BOMB, 45000);
                            break;
                        case EVENT_SPINNING_UP:
                            DoCastAOE(SPELL_SPINNING_UP);
                            events.DelayEvents(14000);
                            events.RescheduleEvent(EVENT_SPINNING_UP, urand(55000, 65000));
                            break;
                        case EVENT_FLAME_SUPPRESSANT_VX:
                            DoCastAOE(SPELL_FLAME_SUPPRESSANT_VX);
                            events.RescheduleEvent(EVENT_FLAME_SUPPRESSANT_VX, urand(10000, 12000), 0, PHASE_VX_001);
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }
            }

        private:
            bool _fireFighter;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<boss_vx_001AI>(creature);
        }
};

class boss_aerial_command_unit : public CreatureScript
{
    public:
        boss_aerial_command_unit() : CreatureScript("boss_aerial_command_unit") { }

        struct boss_aerial_command_unitAI : public BossAI
        {
            boss_aerial_command_unitAI(Creature* creature) : BossAI(creature, BOSS_MIMIRON)
            {
                me->SetReactState(REACT_PASSIVE);
                me->SetDisableGravity(true);
                fireFigther = false;
            }

            void DamageTaken(Unit* who, uint32 &damage) override
            {
                if (damage >= me->GetHealth())
                {
                    damage = me->GetHealth() - 1; // Let creature fall to 1 hp, but do not let it die or damage itself with SetHealth().
                    me->SetReactState(REACT_PASSIVE);
                    me->AttackStop();
                    me->SetByteValue(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_ANIM_TIER, UNIT_BYTE1_FLAG_HOVER | UNIT_BYTE1_FLAG_ALWAYS_STAND);
                    me->SetHover(false);
                    me->SetDisableGravity(true);

                    DoCastSelf(SPELL_VEHICLE_DAMAGED, true);

                    if (events.IsInPhase(PHASE_AERIAL_COMMAND_UNIT))
                    {
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MovePoint(WP_AERIAL_P4_POS, VehicleRelocation[WP_AERIAL_P4_POS]);
                    }
                    else if (events.IsInPhase(PHASE_VOL7RON))
                    {
                        me->SetStandState(UNIT_STAND_STATE_DEAD);

                        Unit* ref = who ? who : me;
                        if (IsEncounterFinished(ref))
                            return;

                        me->CastStop();
                        DoCast(me, SPELL_SELF_REPAIR);
                    }
                    events.Reset();
                }
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case DO_HARDMODE_AERIAL:
                        fireFigther = true;
                        DoCast(me, SPELL_EMERGENCY_MODE);
                        events.ScheduleEvent(EVENT_SUMMON_FIRE_BOTS, 1s, 0, PHASE_AERIAL_COMMAND_UNIT);
                        /* fallthrough */
                    case DO_START_AERIAL:
                        me->SetByteValue(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_ANIM_TIER, UNIT_BYTE1_FLAG_HOVER);
                        me->SetDisableGravity(false);
                        me->SetHover(true);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        me->SetImmuneToPC(false);
                        me->SetReactState(REACT_AGGRESSIVE);

                        events.SetPhase(PHASE_AERIAL_COMMAND_UNIT);
                        events.ScheduleEvent(EVENT_SUMMON_JUNK_BOT, 5s, 0, PHASE_AERIAL_COMMAND_UNIT);
                        events.ScheduleEvent(EVENT_SUMMON_ASSAULT_BOT, 9s, 0, PHASE_AERIAL_COMMAND_UNIT);
                        events.ScheduleEvent(EVENT_SUMMON_BOMB_BOT, 9s, 0, PHASE_AERIAL_COMMAND_UNIT);
                        break;
                    case DO_DISABLE_AERIAL:
                        me->CastStop();
                        me->SetReactState(REACT_PASSIVE);
                        me->AttackStop();
                        me->GetMotionMaster()->MoveFall();
                        events.DelayEvents(23000);
                        break;
                    case DO_ENABLE_AERIAL:
                        me->SetReactState(REACT_AGGRESSIVE);
                        break;
                    case DO_ASSEMBLED_COMBAT:
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->SetStandState(UNIT_STAND_STATE_STAND);
                        events.SetPhase(PHASE_VOL7RON);
                        break;
                    default:
                        break;
                }
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                summons.DespawnAll();
            }

            void JustSummoned(Creature* summon) override
            {
                if (fireFigther && (summon->GetEntry() == NPC_ASSAULT_BOT || summon->GetEntry() == NPC_JUNK_BOT))
                    summon->CastSpell(summon, SPELL_EMERGENCY_MODE);
                BossAI::JustSummoned(summon);
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    if (Creature* mimiron = instance->GetCreature(BOSS_MIMIRON))
                        mimiron->AI()->Talk(events.IsInPhase(PHASE_AERIAL_COMMAND_UNIT) ? SAY_AERIAL_SLAY : SAY_V07TRON_SLAY);
            }

            void MovementInform(uint32 type, uint32 point) override
            {
                if (type == POINT_MOTION_TYPE && point == WP_AERIAL_P4_POS)
                {
                    me->SetFacingTo(VehicleRelocation[WP_AERIAL_P4_POS].GetOrientation());
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    DoCastSelf(SPELL_CLEAR_ALL_DEBUFFS);

                    if (Creature* mimiron = instance->GetCreature(BOSS_MIMIRON))
                        mimiron->AI()->DoAction(DO_ACTIVATE_V0L7R0N_1);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SUMMON_FIRE_BOTS:
                            DoCastAOE(SPELL_SUMMON_FIRE_BOT_TRIGGER, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_MAX_TARGETS, 3));
                            events.RescheduleEvent(EVENT_SUMMON_FIRE_BOTS, 45000, 0, PHASE_AERIAL_COMMAND_UNIT);
                            break;
                        case EVENT_SUMMON_JUNK_BOT:
                            DoCastAOE(SPELL_SUMMON_JUNK_BOT_TRIGGER, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_MAX_TARGETS, 1));
                            events.RescheduleEvent(EVENT_SUMMON_JUNK_BOT, urand(11000, 12000), 0, PHASE_AERIAL_COMMAND_UNIT);
                            break;
                        case EVENT_SUMMON_ASSAULT_BOT:
                            DoCastAOE(SPELL_SUMMON_ASSAULT_BOT_TRIGGER, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_MAX_TARGETS, 1));
                            events.RescheduleEvent(EVENT_SUMMON_ASSAULT_BOT, 30000, 0, PHASE_AERIAL_COMMAND_UNIT);
                            break;
                        case EVENT_SUMMON_BOMB_BOT:
                            DoCast(me, SPELL_SUMMON_BOMB_BOT);
                            events.RescheduleEvent(EVENT_SUMMON_BOMB_BOT, urand(15000, 20000), 0, PHASE_AERIAL_COMMAND_UNIT);
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }
                DoSpellAttackIfReady(events.IsInPhase(PHASE_AERIAL_COMMAND_UNIT) ? SPELL_PLASMA_BALL_P1 : SPELL_PLASMA_BALL_P2);
            }

        private:
            bool fireFigther;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<boss_aerial_command_unitAI>(creature);
        }
};

class npc_mimiron_assault_bot : public CreatureScript
{
    public:
        npc_mimiron_assault_bot() : CreatureScript("npc_mimiron_assault_bot") { }

        struct npc_mimiron_assault_botAI : public ScriptedAI
        {
            npc_mimiron_assault_botAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                events.ScheduleEvent(EVENT_MAGNETIC_FIELD, 14s);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_ROOT))
                {
                    if (Unit* newTarget = SelectTarget(SELECT_TARGET_MINDISTANCE, 0, 30.0f, true))
                    {
                        me->GetThreatManager().ResetAllThreat();
                        AttackStart(newTarget);
                    }
                }

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_MAGNETIC_FIELD:
                            DoCastVictim(SPELL_MAGNETIC_FIELD);
                            events.RescheduleEvent(EVENT_MAGNETIC_FIELD, 30000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<npc_mimiron_assault_botAI>(creature);
        }
};

class npc_mimiron_emergency_fire_bot : public CreatureScript
{
    public:
        npc_mimiron_emergency_fire_bot() : CreatureScript("npc_mimiron_emergency_fire_bot") { }

        struct npc_mimiron_emergency_fire_botAI : public ScriptedAI
        {
            npc_mimiron_emergency_fire_botAI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetReactState(REACT_PASSIVE);
                isWaterSprayReady = true;
                moveNew = true;
            }

            uint32 GetData(uint32 id) const override
            {
                if (id == DATA_WATERSPRAY)
                    return isWaterSprayReady;
                if (id == DATA_MOVE_NEW)
                    return moveNew;
                return 0;
            }

            void SetData(uint32 id, uint32 data) override
            {
                if (id == DATA_WATERSPRAY)
                    isWaterSprayReady = false;
                else if (id == DATA_MOVE_NEW)
                    moveNew = data ? true : false;
            }

            void Reset() override
            {
                events.ScheduleEvent(EVENT_WATER_SPRAY, 7s);
                isWaterSprayReady = true;
                moveNew = true;
            }

            void UpdateAI(uint32 diff) override
            {
                if (!isWaterSprayReady)
                    events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_WATER_SPRAY:
                            isWaterSprayReady = true;
                            events.RescheduleEvent(EVENT_WATER_SPRAY, 7s, 9s);
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            EventMap events;
            bool isWaterSprayReady;
            bool moveNew;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<npc_mimiron_emergency_fire_botAI>(creature);
        }
};

class npc_mimiron_computer : public CreatureScript
{
    public:
        npc_mimiron_computer() : CreatureScript("npc_mimiron_computer") { }

        struct npc_mimiron_computerAI : public ScriptedAI
        {
            npc_mimiron_computerAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = me->GetInstanceScript();
                me->SetReactState(REACT_PASSIVE);
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case DO_ACTIVATE_COMPUTER:
                        Talk(SAY_SELF_DESTRUCT_INITIATED);
                        events.ScheduleEvent(EVENT_SELF_DESTRUCT_10, 3000);
                        break;
                    case DO_DEACTIVATE_COMPUTER:
                        Talk(SAY_SELF_DESTRUCT_TERMINATED);
                        me->RemoveAurasDueToSpell(SPELL_SELF_DESTRUCTION_AURA);
                        me->RemoveAurasDueToSpell(SPELL_SELF_DESTRUCTION_VISUAL);
                        events.Reset();
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SELF_DESTRUCT_10:
                            Talk(SAY_SELF_DESTRUCT_10);
                            if (Creature* mimiron = instance->GetCreature(BOSS_MIMIRON))
                                mimiron->AI()->DoAction(DO_ACTIVATE_HARD_MODE);
                            events.ScheduleEvent(EVENT_SELF_DESTRUCT_9, 60000);
                            break;
                        case EVENT_SELF_DESTRUCT_9:
                            Talk(SAY_SELF_DESTRUCT_9);
                            events.ScheduleEvent(EVENT_SELF_DESTRUCT_8, 60000);
                            break;
                        case EVENT_SELF_DESTRUCT_8:
                            Talk(SAY_SELF_DESTRUCT_8);
                            events.ScheduleEvent(EVENT_SELF_DESTRUCT_7, 60000);
                            break;
                        case EVENT_SELF_DESTRUCT_7:
                            Talk(SAY_SELF_DESTRUCT_7);
                            events.ScheduleEvent(EVENT_SELF_DESTRUCT_6, 60000);
                            break;
                        case EVENT_SELF_DESTRUCT_6:
                            Talk(SAY_SELF_DESTRUCT_6);
                            events.ScheduleEvent(EVENT_SELF_DESTRUCT_5, 60000);
                            break;
                        case EVENT_SELF_DESTRUCT_5:
                            Talk(SAY_SELF_DESTRUCT_5);
                            events.ScheduleEvent(EVENT_SELF_DESTRUCT_4, 60000);
                            break;
                        case EVENT_SELF_DESTRUCT_4:
                            Talk(SAY_SELF_DESTRUCT_4);
                            events.ScheduleEvent(EVENT_SELF_DESTRUCT_3, 60000);
                            break;
                        case EVENT_SELF_DESTRUCT_3:
                            Talk(SAY_SELF_DESTRUCT_3);
                            events.ScheduleEvent(EVENT_SELF_DESTRUCT_2, 60000);
                            break;
                        case EVENT_SELF_DESTRUCT_2:
                            Talk(SAY_SELF_DESTRUCT_2);
                            events.ScheduleEvent(EVENT_SELF_DESTRUCT_1, 60000);
                            break;
                        case EVENT_SELF_DESTRUCT_1:
                            Talk(SAY_SELF_DESTRUCT_1);
                            events.ScheduleEvent(EVENT_SELF_DESTRUCT_FINALIZED, 1min);
                            break;
                        case EVENT_SELF_DESTRUCT_FINALIZED:
                            Talk(SAY_SELF_DESTRUCT_FINALIZED);
                            if (Creature* mimiron = instance->GetCreature(BOSS_MIMIRON))
                                mimiron->AI()->DoAction(DO_ACTIVATE_SELF_DESTRUCT);
                            DoCast(me, SPELL_SELF_DESTRUCTION_AURA);
                            DoCast(me, SPELL_SELF_DESTRUCTION_VISUAL);
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            InstanceScript* instance;
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<npc_mimiron_computerAI>(creature);
        }
};

class npc_mimiron_flames : public CreatureScript
{
    public:
        npc_mimiron_flames() : CreatureScript("npc_mimiron_flames") { }

        struct npc_mimiron_flamesAI : public ScriptedAI
        {
            npc_mimiron_flamesAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = me->GetInstanceScript();
            }

            void Reset() override // Reset is possibly more suitable for this case.
            {
                events.ScheduleEvent(EVENT_SPREAD_FLAMES, 4s);
            }

            void UpdateAI(uint32 diff) override
            {
                if (instance->GetBossState(BOSS_MIMIRON) != IN_PROGRESS)
                    me->DespawnOrUnsummon();

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SPREAD_FLAMES:
                            DoCastAOE(SPELL_SUMMON_FLAMES_SPREAD_TRIGGER);
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            InstanceScript* instance;
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<npc_mimiron_flamesAI>(creature);
        }
};

class npc_mimiron_frost_bomb : public CreatureScript
{
    public:
        npc_mimiron_frost_bomb() : CreatureScript("npc_mimiron_frost_bomb") { }

        struct npc_mimiron_frost_bombAI : public ScriptedAI
        {
            npc_mimiron_frost_bombAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset() override
            {
                events.ScheduleEvent(EVENT_FROST_BOMB_EXPLOSION, 10s);
            }

            void UpdateAI(uint32 diff) override
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FROST_BOMB_EXPLOSION:
                            DoCastAOE(SPELL_FROST_BOMB_EXPLOSION);
                            events.ScheduleEvent(EVENT_FROST_BOMB_CLEAR_FIRES, 3s);
                            break;
                        case EVENT_FROST_BOMB_CLEAR_FIRES:
                            DoCastAOE(SPELL_CLEAR_FIRES);
                            me->DespawnOrUnsummon(3000);
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<npc_mimiron_frost_bombAI>(creature);
        }
};

class npc_mimiron_proximity_mine : public CreatureScript
{
    public:
        npc_mimiron_proximity_mine() : CreatureScript("npc_mimiron_proximity_mine") { }

        struct npc_mimiron_proximity_mineAI : public ScriptedAI
        {
            npc_mimiron_proximity_mineAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset() override
            {
                events.ScheduleEvent(EVENT_PROXIMITY_MINE_ARM, 1500ms);
            }

            void UpdateAI(uint32 diff) override
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_PROXIMITY_MINE_ARM:
                            DoCast(me, SPELL_PROXIMITY_MINE_PERIODIC_TRIGGER);
                            events.ScheduleEvent(EVENT_PROXIMITY_MINE_DETONATION, 33500);
                            break;
                        case EVENT_PROXIMITY_MINE_DETONATION:
                            if (me->HasAura(SPELL_PROXIMITY_MINE_PERIODIC_TRIGGER))
                                DoCastAOE(SPELL_PROXIMITY_MINE_EXPLOSION);
                            me->DespawnOrUnsummon(1000);
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<npc_mimiron_proximity_mineAI>(creature);
        }
};

struct npc_mimiron_magnetic_core : public ScriptedAI
{
    npc_mimiron_magnetic_core(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        DoCastAOE(SPELL_MAGNETIC_CORE, true);
    }
};

class go_mimiron_hardmode_button : public GameObjectScript
{
    public:
        go_mimiron_hardmode_button() : GameObjectScript("go_mimiron_hardmode_button") { }

        struct go_mimiron_hardmode_buttonAI : public GameObjectAI
        {
            go_mimiron_hardmode_buttonAI(GameObject* go) : GameObjectAI(go), instance(go->GetInstanceScript()) { }

            InstanceScript* instance;

            bool GossipHello(Player* /*player*/) override
            {
                if (me->HasFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE))
                    return true;

                if (Creature* computer = instance->GetCreature(DATA_COMPUTER))
                    computer->AI()->DoAction(DO_ACTIVATE_COMPUTER);

                me->SetGoState(GO_STATE_ACTIVE);
                me->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                return true;
            }
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return GetUlduarAI<go_mimiron_hardmode_buttonAI>(go);
        }
};

// 63801 - Bomb Bot
class spell_mimiron_bomb_bot : public SpellScriptLoader
{
    public:
        spell_mimiron_bomb_bot() : SpellScriptLoader("spell_mimiron_bomb_bot") { }

        class spell_mimiron_bomb_bot_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_bomb_bot_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (GetHitPlayer())
                    if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                        if (Creature* mkii = ObjectAccessor::GetCreature(*GetCaster(), instance->GetGuidData(DATA_LEVIATHAN_MK_II)))
                            mkii->AI()->SetData(DATA_SETUP_BOMB, 0);
            }

            void HandleDespawn(SpellEffIndex /*effIndex*/)
            {
                if (Creature* target = GetHitCreature())
                {
                    target->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);
                    target->DespawnOrUnsummon(1000);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_bomb_bot_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_bomb_bot_SpellScript::HandleDespawn, EFFECT_1, SPELL_EFFECT_APPLY_AURA);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_bomb_bot_SpellScript();
        }
};

// 65192 - Flame Suppressant, 65224 - Clear Fires, 65354 - Clear Fires, 64619 - Water Spray
class spell_mimiron_clear_fires : public SpellScriptLoader
{
    public:
        spell_mimiron_clear_fires() : SpellScriptLoader("spell_mimiron_clear_fires") { }

        class spell_mimiron_clear_fires_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_clear_fires_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (GetHitCreature())
                    GetHitCreature()->DespawnOrUnsummon();
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_clear_fires_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_clear_fires_SpellScript();
        }
};

// 64463 - Despawn Assault Bots
class spell_mimiron_despawn_assault_bots : public SpellScriptLoader
{
    public:
        spell_mimiron_despawn_assault_bots() : SpellScriptLoader("spell_mimiron_despawn_assault_bots") { }

        class spell_mimiron_despawn_assault_bots_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_despawn_assault_bots_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (GetHitCreature())
                    GetHitCreature()->DespawnOrUnsummon();
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_despawn_assault_bots_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_despawn_assault_bots_SpellScript();
        }
};

// 64618 - Fire Search
class spell_mimiron_fire_search : public SpellScriptLoader
{
    public:
        spell_mimiron_fire_search() : SpellScriptLoader("spell_mimiron_fire_search") { }

        class spell_mimiron_fire_search_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_fire_search_SpellScript);

        public:
            spell_mimiron_fire_search_SpellScript()
            {
                _noTarget = false;
            }

        private:
            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_WATER_SPRAY });
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                _noTarget = targets.empty();
                if (_noTarget)
                    return;

                WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
                targets.clear();
                targets.push_back(target);
            }

            void HandleAftercast()
            {
                if (_noTarget)
                    GetCaster()->GetMotionMaster()->MoveRandom(15.0f);
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();

                if (UnitAI* ai = caster->GetAI())
                {
                    if (caster->GetDistance2d(GetHitUnit()) <= 15.0f && ai->GetData(DATA_WATERSPRAY))
                    {
                        caster->CastSpell(GetHitUnit(), SPELL_WATER_SPRAY, true);
                        ai->SetData(DATA_WATERSPRAY, 0);
                        ai->SetData(DATA_MOVE_NEW, 1);
                    }
                    else if (caster->GetAI()->GetData(DATA_MOVE_NEW))
                    {
                        caster->GetMotionMaster()->MoveChase(GetHitUnit());
                        ai->SetData(DATA_MOVE_NEW, 0);
                    }
                }
            }

            void Register() override
            {
                AfterCast += SpellCastFn(spell_mimiron_fire_search_SpellScript::HandleAftercast);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mimiron_fire_search_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_fire_search_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }

        private:
            bool _noTarget;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_fire_search_SpellScript();
        }
};

// 64444 - Magnetic Core Summon
class spell_mimiron_magnetic_core_summon : public SpellScript
{
    PrepareSpellScript(spell_mimiron_magnetic_core_summon);

    void ModDest(SpellDestination& dest)
    {
        Unit* caster = GetCaster();
        Position pos = caster->GetPosition();
        float z = caster->GetMap()->GetHeight(pos);
        pos.m_positionZ = z;
        dest.Relocate(pos);
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_mimiron_magnetic_core_summon::ModDest, EFFECT_0, TARGET_DEST_NEARBY_ENTRY);
    }
};

// 64436 - Magnetic Core
class spell_mimiron_magnetic_core : public SpellScriptLoader
{
    public:
        spell_mimiron_magnetic_core() : SpellScriptLoader("spell_mimiron_magnetic_core") { }

        class spell_mimiron_magnetic_core_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_magnetic_core_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if([](WorldObject* obj) { return obj->ToUnit() && (obj->ToUnit()->GetVehicleBase() || obj->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE)); });
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mimiron_magnetic_core_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_magnetic_core_SpellScript();
        }

        class spell_mimiron_magnetic_core_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mimiron_magnetic_core_AuraScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_MAGNETIC_CORE_VISUAL });
            }

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Creature* target = GetTarget()->ToCreature())
                {
                    target->AI()->DoAction(DO_DISABLE_AERIAL);
                    target->CastSpell(target, SPELL_MAGNETIC_CORE_VISUAL, true);
                }
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Creature* target = GetTarget()->ToCreature())
                {
                    target->AI()->DoAction(DO_ENABLE_AERIAL);
                    target->RemoveAurasDueToSpell(SPELL_MAGNETIC_CORE_VISUAL);
                }
            }

            void OnRemoveSelf(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (TempSummon* summ = GetTarget()->ToTempSummon())
                    summ->DespawnOrUnsummon();
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_mimiron_magnetic_core_AuraScript::OnApply, EFFECT_1, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_mimiron_magnetic_core_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_mimiron_magnetic_core_AuraScript::OnRemoveSelf, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mimiron_magnetic_core_AuraScript();
        }
};

// 63667 - Napalm Shell
class spell_mimiron_napalm_shell : public SpellScriptLoader
{
    public:
        spell_mimiron_napalm_shell() : SpellScriptLoader("spell_mimiron_napalm_shell") { }

        class spell_mimiron_napalm_shell_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_napalm_shell_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_NAPALM_SHELL });
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);

                targets.remove_if(Trinity::AllWorldObjectsInRange(GetCaster(), 15.0f));

                if (!targets.empty())
                    target = Trinity::Containers::SelectRandomContainerElement(targets);

                targets.clear();
                targets.push_back(target);
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->CastSpell(GetHitUnit(), SPELL_NAPALM_SHELL);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mimiron_napalm_shell_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_napalm_shell_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_napalm_shell_SpellScript();
        }
};

// 63274 - P3Wx2 Laser Barrage -- HACK! Core will currently not set UNIT_FIELD_CHANNEL_OBJECT automatially if the spell targets more than a single target.
class spell_mimiron_p3wx2_laser_barrage : public SpellScriptLoader
{
    public:
        spell_mimiron_p3wx2_laser_barrage() : SpellScriptLoader("spell_mimiron_p3wx2_laser_barrage") { }

        class spell_mimiron_p3wx2_laser_barrage_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_p3wx2_laser_barrage_SpellScript);

            void OnHit(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->SetChannelObjectGuid(GetHitUnit()->GetGUID());
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_p3wx2_laser_barrage_SpellScript::OnHit, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_p3wx2_laser_barrage_SpellScript();
        }
};

// 64542 - Plasma Blast
class spell_mimiron_plasma_blast : public SpellScriptLoader
{
    public:
        spell_mimiron_plasma_blast() : SpellScriptLoader("spell_mimiron_plasma_blast") { }

        class spell_mimiron_plasma_blast_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_plasma_blast_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_PLASMA_BLAST });
            }

            bool Load() override
            {
                return GetCaster()->GetVehicleKit() != nullptr;
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (Unit* caster = GetCaster()->GetVehicleKit()->GetPassenger(3))
                    caster->CastSpell(GetHitUnit(), SPELL_PLASMA_BLAST);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_plasma_blast_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_plasma_blast_SpellScript();
        }
};

// 66351 - Explosion
class spell_mimiron_proximity_explosion : public SpellScriptLoader
{
    public:
        spell_mimiron_proximity_explosion() : SpellScriptLoader("spell_mimiron_proximity_explosion") { }

        class spell_mimiron_proximity_explosion_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_proximity_explosion_SpellScript);

            void OnHit(SpellEffIndex /*effIndex*/)
            {
                if (GetHitPlayer())
                    if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                        if (Creature* mkII = ObjectAccessor::GetCreature(*GetCaster(), instance->GetGuidData(DATA_LEVIATHAN_MK_II)))
                            mkII->AI()->SetData(DATA_SETUP_MINE, 0);
            }

            void HandleAura(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->RemoveAurasDueToSpell(SPELL_PROXIMITY_MINE_PERIODIC_TRIGGER);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_proximity_explosion_SpellScript::OnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_proximity_explosion_SpellScript::HandleAura, EFFECT_1, SPELL_EFFECT_APPLY_AURA);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_proximity_explosion_SpellScript();
        }
};

// 63027 - Proximity Mines
class spell_mimiron_proximity_mines : public SpellScriptLoader
{
    public:
        spell_mimiron_proximity_mines() : SpellScriptLoader("spell_mimiron_proximity_mines") { }

        class spell_mimiron_proximity_mines_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_proximity_mines_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_SUMMON_PROXIMITY_MINE });
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                for (uint8 i = 0; i < 10; ++i)
                    GetCaster()->CastSpell(GetCaster(), SPELL_SUMMON_PROXIMITY_MINE, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_proximity_mines_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_proximity_mines_SpellScript();
        }
};

// 65346 - Proximity Mine
class spell_mimiron_proximity_trigger : public SpellScriptLoader
{
    public:
        spell_mimiron_proximity_trigger() : SpellScriptLoader("spell_mimiron_proximity_trigger") { }

        class spell_mimiron_proximity_trigger_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_proximity_trigger_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_PROXIMITY_MINE_EXPLOSION });
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove(GetExplTargetWorldObject());

                if (targets.empty())
                    FinishCast(SPELL_FAILED_NO_VALID_TARGETS);
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->CastSpell(nullptr, SPELL_PROXIMITY_MINE_EXPLOSION, true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mimiron_proximity_trigger_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnEffectHit += SpellEffectFn(spell_mimiron_proximity_trigger_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_proximity_trigger_SpellScript();
        }
};

// 63382 - Rapid Burst
class spell_mimiron_rapid_burst : public SpellScriptLoader
{
    public:
        spell_mimiron_rapid_burst() : SpellScriptLoader("spell_mimiron_rapid_burst") { }

        class spell_mimiron_rapid_burst_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mimiron_rapid_burst_AuraScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_RAPID_BURST_LEFT, SPELL_RAPID_BURST_RIGHT });
            }

            void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (TempSummon* summ = GetTarget()->ToTempSummon())
                    summ->DespawnOrUnsummon();
            }

            void HandleDummyTick(AuraEffect const* aurEff)
            {
                if (GetCaster())
                    GetCaster()->CastSpell(GetTarget(), aurEff->GetTickNumber() % 2 == 0 ? SPELL_RAPID_BURST_RIGHT : SPELL_RAPID_BURST_LEFT, aurEff);
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectApplyFn(spell_mimiron_rapid_burst_AuraScript::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_mimiron_rapid_burst_AuraScript::HandleDummyTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mimiron_rapid_burst_AuraScript();
        }
};

// 64402 - Rocket Strike, 65034 - Rocket Strike
class spell_mimiron_rocket_strike : public SpellScriptLoader
{
    public:
        spell_mimiron_rocket_strike() : SpellScriptLoader("spell_mimiron_rocket_strike") { }

        class spell_mimiron_rocket_strike_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_rocket_strike_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_SCRIPT_EFFECT_ROCKET_STRIKE });
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                if (m_scriptSpellId == SPELL_ROCKET_STRIKE_SINGLE && GetCaster()->IsVehicle())
                    if (WorldObject* target = GetCaster()->GetVehicleKit()->GetPassenger(RAND(ROCKET_SEAT_LEFT, ROCKET_SEAT_RIGHT)))
                    {
                        targets.clear();
                        targets.push_back(target);
                    }
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                GetHitUnit()->CastSpell(nullptr, SPELL_SCRIPT_EFFECT_ROCKET_STRIKE, GetCaster()->GetGUID());
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mimiron_rocket_strike_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_rocket_strike_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_rocket_strike_SpellScript();
        }
};

// 63041 - Rocket Strike
class spell_mimiron_rocket_strike_damage : public SpellScriptLoader
{
    public:
        spell_mimiron_rocket_strike_damage() : SpellScriptLoader("spell_mimiron_rocket_strike_damage") { }

        class spell_mimiron_rocket_strike_damage_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_rocket_strike_damage_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_NOT_SO_FRIENDLY_FIRE });
            }

            void HandleAfterCast()
            {
                if (TempSummon* summ = GetCaster()->ToTempSummon())
                    summ->DespawnOrUnsummon();
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (GetHitPlayer())
                    if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                        if (Creature* mkii = ObjectAccessor::GetCreature(*GetCaster(), instance->GetGuidData(DATA_LEVIATHAN_MK_II)))
                            mkii->AI()->SetData(DATA_SETUP_ROCKET, 0);
            }

            void HandleFriendlyFire(SpellEffIndex /*effIndex*/)
            {
                GetHitUnit()->CastSpell(nullptr, SPELL_NOT_SO_FRIENDLY_FIRE, true);
            }

            void Register() override
            {
                AfterCast += SpellCastFn(spell_mimiron_rocket_strike_damage_SpellScript::HandleAfterCast);
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_rocket_strike_damage_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_rocket_strike_damage_SpellScript::HandleFriendlyFire, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_rocket_strike_damage_SpellScript();
        }
};

// 63681 - Rocket Strike
class spell_mimiron_rocket_strike_target_select : public SpellScriptLoader
{
    public:
        spell_mimiron_rocket_strike_target_select() : SpellScriptLoader("spell_mimiron_rocket_strike_target_select") { }

        class spell_mimiron_rocket_strike_target_select_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_rocket_strike_target_select_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_SUMMON_ROCKET_STRIKE });
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);

                targets.remove_if(Trinity::AllWorldObjectsInRange(GetCaster(), 15.0f));

                if (!targets.empty())
                    target = Trinity::Containers::SelectRandomContainerElement(targets);

                targets.clear();
                targets.push_back(target);
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                    GetCaster()->CastSpell(GetHitUnit(), SPELL_SUMMON_ROCKET_STRIKE, instance->GetGuidData(DATA_VX_001));
                GetCaster()->SetDisplayId(11686);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mimiron_rocket_strike_target_select_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_rocket_strike_target_select_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_rocket_strike_target_select_SpellScript();
        }
};

// 64383 - Self Repair
class spell_mimiron_self_repair : public SpellScriptLoader
{
    public:
        spell_mimiron_self_repair() : SpellScriptLoader("spell_mimiron_self_repair") { }

        class spell_mimiron_self_repair_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_self_repair_SpellScript);

            void HandleScript()
            {
                if (GetCaster()->GetAI())
                    GetCaster()->GetAI()->DoAction(DO_ASSEMBLED_COMBAT);
            }

            void Register() override
            {
                AfterHit += SpellHitFn(spell_mimiron_self_repair_SpellScript::HandleScript);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_self_repair_SpellScript();
        }
};

// 63414 - Spinning Up -- HACK! Core will currently not set UNIT_FIELD_CHANNEL_OBJECT automatially if the spell targets more than a single target.
// eff0 will hit both caster and target due to hack in spellmgr.cpp, it is necessary because caster will interrupt itself if aura is not active on caster.
class spell_mimiron_spinning_up : public SpellScriptLoader
{
    public:
        spell_mimiron_spinning_up() : SpellScriptLoader("spell_mimiron_spinning_up") { }

        class spell_mimiron_spinning_up_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_spinning_up_SpellScript);

            void OnHit(SpellEffIndex /*effIndex*/)
            {
                if (GetHitUnit() != GetCaster())
                    GetCaster()->SetChannelObjectGuid(GetHitUnit()->GetGUID());
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_spinning_up_SpellScript::OnHit, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_spinning_up_SpellScript();
        }
};

// 64426 - Summon Scrap Bot
class spell_mimiron_summon_assault_bot : public SpellScriptLoader
{
    public:
        spell_mimiron_summon_assault_bot() : SpellScriptLoader("spell_mimiron_summon_assault_bot") { }

        class spell_mimiron_summon_assault_bot_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mimiron_summon_assault_bot_AuraScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_SUMMON_ASSAULT_BOT });
            }

            void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                    if (InstanceScript* instance = caster->GetInstanceScript())
                        if (instance->GetBossState(BOSS_MIMIRON) == IN_PROGRESS)
                            caster->CastSpell(caster, SPELL_SUMMON_ASSAULT_BOT, { aurEff, instance->GetGuidData(DATA_AERIAL_COMMAND_UNIT) });
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_mimiron_summon_assault_bot_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mimiron_summon_assault_bot_AuraScript();
        }
};

// 64425 - Summon Scrap Bot Trigger
class spell_mimiron_summon_assault_bot_target : public SpellScriptLoader
{
    public:
        spell_mimiron_summon_assault_bot_target() : SpellScriptLoader("spell_mimiron_summon_assault_bot_target") { }

        class spell_mimiron_summon_assault_bot_target_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_summon_assault_bot_target_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_SUMMON_ASSAULT_BOT_DUMMY });
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                GetHitUnit()->CastSpell(GetHitUnit(), SPELL_SUMMON_ASSAULT_BOT_DUMMY, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_summon_assault_bot_target_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_summon_assault_bot_target_SpellScript();
        }
};

// 64621 - Summon Fire Bot
class spell_mimiron_summon_fire_bot : public SpellScriptLoader
{
    public:
        spell_mimiron_summon_fire_bot() : SpellScriptLoader("spell_mimiron_summon_fire_bot") { }

        class spell_mimiron_summon_fire_bot_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mimiron_summon_fire_bot_AuraScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_SUMMON_FIRE_BOT });
            }

            void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                    if (InstanceScript* instance = caster->GetInstanceScript())
                        if (instance->GetBossState(BOSS_MIMIRON) == IN_PROGRESS)
                            caster->CastSpell(caster, SPELL_SUMMON_FIRE_BOT, { aurEff, instance->GetGuidData(DATA_AERIAL_COMMAND_UNIT) });
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_mimiron_summon_fire_bot_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mimiron_summon_fire_bot_AuraScript();
        }
};

// 64620 - Summon Fire Bot Trigger
class spell_mimiron_summon_fire_bot_target : public SpellScriptLoader
{
    public:
        spell_mimiron_summon_fire_bot_target() : SpellScriptLoader("spell_mimiron_summon_fire_bot_target") { }

        class spell_mimiron_summon_fire_bot_target_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_summon_fire_bot_target_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_SUMMON_FIRE_BOT_DUMMY });
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                GetHitUnit()->CastSpell(GetHitUnit(), SPELL_SUMMON_FIRE_BOT_DUMMY, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_summon_fire_bot_target_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_summon_fire_bot_target_SpellScript();
        }
};

// 64562 - Summon Flames Spread Trigger
class spell_mimiron_summon_flames_spread : public SpellScriptLoader
{
    public:
        spell_mimiron_summon_flames_spread() : SpellScriptLoader("spell_mimiron_summon_flames_spread") { }

        class spell_mimiron_summon_flames_spread_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_summon_flames_spread_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                // Flames must chase the closest player
                WorldObject* target = targets.front();

                for (std::list<WorldObject*>::const_iterator iter = targets.begin(); iter != targets.end(); ++iter)
                    if (GetCaster()->GetDistance2d(*iter) < GetCaster()->GetDistance2d(target))
                        target = *iter;

                targets.clear();
                targets.push_back(target);
            }

            void OnHit(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->SetInFront(GetHitUnit());
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mimiron_summon_flames_spread_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_summon_flames_spread_SpellScript::OnHit, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_summon_flames_spread_SpellScript();
        }

        class spell_mimiron_summon_flames_spread_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mimiron_summon_flames_spread_AuraScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_SUMMON_FLAMES_SPREAD });
            }

            void HandleTick(AuraEffect const* /*aurEff*/)
            {
                PreventDefaultAction();
                if (Unit* caster = GetCaster())
                    if (caster->HasAura(SPELL_FLAMES_PERIODIC_TRIGGER))
                        caster->CastSpell(GetTarget(), SPELL_SUMMON_FLAMES_SPREAD, true);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_mimiron_summon_flames_spread_AuraScript::HandleTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mimiron_summon_flames_spread_AuraScript();
        }
};

// 64623 - Frost Bomb
class spell_mimiron_summon_frost_bomb_target : public SpellScriptLoader
{
    public:
        spell_mimiron_summon_frost_bomb_target() : SpellScriptLoader("spell_mimiron_summon_frost_bomb_target") { }

        class spell_mimiron_summon_frost_bomb_target_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_summon_frost_bomb_target_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_SUMMON_FROST_BOMB });
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                targets.remove_if(Trinity::AllWorldObjectsInRange(GetCaster(), 15.0f));

                if (targets.empty())
                    return;

                WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);

                targets.clear();
                targets.push_back(target);
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->CastSpell(GetHitUnit(), SPELL_SUMMON_FROST_BOMB, true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mimiron_summon_frost_bomb_target_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_summon_frost_bomb_target_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_summon_frost_bomb_target_SpellScript();
        }
};

// 64398 - Summon Scrap Bot
class spell_mimiron_summon_junk_bot : public SpellScriptLoader
{
    public:
        spell_mimiron_summon_junk_bot() : SpellScriptLoader("spell_mimiron_summon_junk_bot") { }

        class spell_mimiron_summon_junk_bot_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mimiron_summon_junk_bot_AuraScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_SUMMON_JUNK_BOT });
            }

            void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                    if (InstanceScript* instance = caster->GetInstanceScript())
                        if (instance->GetBossState(BOSS_MIMIRON) == IN_PROGRESS)
                            caster->CastSpell(caster, SPELL_SUMMON_JUNK_BOT, { aurEff, instance->GetGuidData(DATA_AERIAL_COMMAND_UNIT) });
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_mimiron_summon_junk_bot_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mimiron_summon_junk_bot_AuraScript();
        }
};

// 63820 - Summon Scrap Bot Trigger
class spell_mimiron_summon_junk_bot_target : public SpellScriptLoader
{
    public:
        spell_mimiron_summon_junk_bot_target() : SpellScriptLoader("spell_mimiron_summon_junk_bot_target") { }

        class spell_mimiron_summon_junk_bot_target_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mimiron_summon_junk_bot_target_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_SUMMON_JUNK_BOT_DUMMY });
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                GetHitUnit()->CastSpell(GetHitUnit(), SPELL_SUMMON_JUNK_BOT_DUMMY, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_mimiron_summon_junk_bot_target_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mimiron_summon_junk_bot_target_SpellScript();
        }
};

// 63339 - Weld
class spell_mimiron_weld : public SpellScriptLoader
{
    public:
        spell_mimiron_weld() : SpellScriptLoader("spell_mimiron_weld") { }

        class spell_mimiron_weld_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mimiron_weld_AuraScript);

            void HandleTick(AuraEffect const* aurEff)
            {
                Unit* caster = GetTarget();
                if (Unit* vehicle = caster->GetVehicleBase())
                {
                    if (aurEff->GetTickNumber() % 5 == 0)
                        caster->CastSpell(vehicle, RepairSpells[urand(0, 3)]);
                    caster->SetFacingToObject(vehicle);
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_mimiron_weld_AuraScript::HandleTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mimiron_weld_AuraScript();
        }
};

class achievement_setup_boom : public AchievementCriteriaScript
{
    public:
        achievement_setup_boom() : AchievementCriteriaScript("achievement_setup_boom") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            return target && target->GetAI()->GetData(DATA_SETUP_BOMB);
        }
};

class achievement_setup_mine : public AchievementCriteriaScript
{
    public:
        achievement_setup_mine() : AchievementCriteriaScript("achievement_setup_mine") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            return target && target->GetAI()->GetData(DATA_SETUP_MINE);
        }
};

class achievement_setup_rocket : public AchievementCriteriaScript
{
    public:
        achievement_setup_rocket() : AchievementCriteriaScript("achievement_setup_rocket") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            return target && target->GetAI()->GetData(DATA_SETUP_ROCKET);
        }
};

class achievement_firefighter : public AchievementCriteriaScript
{
    public:
        achievement_firefighter() : AchievementCriteriaScript("achievement_firefighter") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            return target && target->GetAI()->GetData(DATA_FIREFIGHTER);
        }
};

void AddSC_boss_mimiron()
{
    new boss_aerial_command_unit();
    new boss_leviathan_mk_ii();
    new boss_mimiron();
    new boss_vx_001();

    new npc_mimiron_assault_bot();
    new npc_mimiron_emergency_fire_bot();
    new npc_mimiron_computer();
    new npc_mimiron_flames();
    new npc_mimiron_frost_bomb();
    new npc_mimiron_proximity_mine();
    RegisterUlduarCreatureAI(npc_mimiron_magnetic_core);

    new go_mimiron_hardmode_button();

    new spell_mimiron_bomb_bot();
    new spell_mimiron_clear_fires();
    new spell_mimiron_despawn_assault_bots();
    new spell_mimiron_fire_search();
    RegisterSpellScript(spell_mimiron_magnetic_core_summon);
    new spell_mimiron_magnetic_core();
    new spell_mimiron_napalm_shell();
    new spell_mimiron_p3wx2_laser_barrage();
    new spell_mimiron_plasma_blast();
    new spell_mimiron_proximity_explosion();
    new spell_mimiron_proximity_mines();
    new spell_mimiron_proximity_trigger();
    new spell_mimiron_rapid_burst();
    new spell_mimiron_rocket_strike();
    new spell_mimiron_rocket_strike_damage();
    new spell_mimiron_rocket_strike_target_select();
    new spell_mimiron_self_repair();
    new spell_mimiron_spinning_up();
    new spell_mimiron_summon_assault_bot();
    new spell_mimiron_summon_assault_bot_target();
    new spell_mimiron_summon_fire_bot();
    new spell_mimiron_summon_fire_bot_target();
    new spell_mimiron_summon_flames_spread();
    new spell_mimiron_summon_frost_bomb_target();
    new spell_mimiron_summon_junk_bot();
    new spell_mimiron_summon_junk_bot_target();
    new spell_mimiron_weld();

    new achievement_setup_boom();
    new achievement_setup_mine();
    new achievement_setup_rocket();
    new achievement_firefighter();
}
