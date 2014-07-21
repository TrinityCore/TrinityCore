/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "../../Northrend/Ulduar/Ulduar/ulduar.h"
#include "Unit.h"
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
    SAY_BERSERK                                 = 14,
};

#define EMOTE_LEVIATHAN                         "Leviathan MK II begins to cast Plasma Blast!"

enum Spells
{
    // Leviathan MK II
    SPELL_MINES_SPAWN                           = 65347,
    SPELL_PROXIMITY_MINES                       = 63027,
    SPELL_PLASMA_BLAST                          = 62997,
    SPELL_SHOCK_BLAST                           = 63631,
    SPELL_EXPLOSION                             = 66351,
    SPELL_NAPALM_SHELL                          = 63666,

    // VX-001
    SPELL_RAPID_BURST                           = 63382,
    SPELL_RAPID_BURST_LEFT_10                   = 63387,
    SPELL_RAPID_BURST_RIGHT_10                  = 64019,
    SPELL_RAPID_BURST_LEFT_25                   = 64531,
    SPELL_RAPID_BURST_RIGHT_25                  = 64532,
    SPELL_ROCKET_STRIKE                         = 63036,
    SPELL_ROCKET_STRIKE_AURA                    = 64064,
    SPELL_ROCKET_STRIKE_DMG                     = 63041,
    SPELL_SPINNING_UP                           = 63414,
    SPELL_HEAT_WAVE                             = 63677,
    SPELL_HAND_PULSE                            = 64348,

    // Aerial Command Unit
    SPELL_PLASMA_BALL                           = 63689,
    SPELL_MAGNETIC_CORE                         = 64436,
    SPELL_MAGNETIC_CORE_VISUAL                  = 64438,
    SPELL_BOOM_BOT                              = 63801,
    SPELL_MAGNETIC_FIELD                        = 64668,
    SPELL_HOVER                                 = 57764, // Set Hover position
    SPELL_BERSERK                               = 47008,

    // Hard Mode
    SPELL_SELF_DESTRUCTION                      = 64610,
    SPELL_SELF_DESTRUCTION_VISUAL               = 64613,
    SPELL_EMERGENCY_MODE                        = 64582,
    SPELL_FLAME_SUPPRESSANT                     = 64570,
    SPELL_FLAME_SUPPRESSANT_VX001               = 65192,
    SPELL_SUMMON_FLAMES_INITIAL                 = 64563,
    SPELL_FLAME                                 = 64561,
    SPELL_FROST_BOMB                            = 64623,
    SPELL_FROST_BOMB_VISUAL                     = 64624,
    SPELL_FROST_BOMB_EXPLOSION_10               = 64626,
    SPELL_FROST_BOMB_EXPLOSION_25               = 65333,
    SPELL_WATER_SPRAY                           = 64619,
    SPELL_DEAFENING_SIREN                       = 64616,

    // NPCs
    SPELL_BOMB_BOT                              = 63801, // should be 63767
    SPELL_NOT_SO_FRIENDLY_FIRE                  = 65040
};

enum Events
{
    // Leviathan MK II
    EVENT_PROXIMITY_MINE = 1,
    EVENT_NAPALM_SHELL,
    EVENT_PLASMA_BLAST,
    EVENT_SHOCK_BLAST,
    EVENT_FLAME_SUPPRESSANT,

    // VX-001
    EVENT_RAPID_BURST,
    EVENT_LASER_BARRAGE,
    EVENT_LASER_BARRAGE_END,
    EVENT_ROCKET_STRIKE,
    EVENT_HEAT_WAVE,
    EVENT_HAND_PULSE,
    EVENT_FROST_BOMB,
    EVENT_FLAME_SUPPRESSANT_VX001,

    // Aerial Command Unit
    EVENT_PLASMA_BALL,
    EVENT_REACTIVATE_AERIAL,
    EVENT_SUMMON_BOTS
};

enum Phases
{
    PHASE_NULL,
    PHASE_INTRO,
    PHASE_COMBAT,
    PHASE_LEVIATHAN_SOLO,
    PHASE_LEVIATHAN_ASSEMBLED,
    PHASE_VX001_ACTIVATION,
    PHASE_VX001_SOLO,
    PHASE_VX001_ASSEMBLED,
    PHASE_AERIAL_ACTIVATION,
    PHASE_AERIAL_SOLO,
    PHASE_AERIAL_ASSEMBLED,
    PHASE_V0L7R0N_ACTIVATION,
};

enum Actions
{
    DO_START_ENCOUNTER = 1,
    DO_ACTIVATE_VX001,
    DO_START_VX001,
    DO_ACTIVATE_AERIAL,
    DO_START_AERIAL,
    DO_DISABLE_AERIAL,
    DO_ACTIVATE_V0L7R0N,
    DO_LEVIATHAN_ASSEMBLED,
    DO_VX001_ASSEMBLED,
    DO_AERIAL_ASSEMBLED,
    DO_ACTIVATE_DEATH_TIMER,
    DO_ENTER_ENRAGE,
    DO_ACTIVATE_HARD_MODE,
    DO_INCREASE_FLAME_COUNT,
    DO_DECREASE_FLAME_COUNT,
    DATA_GET_HARD_MODE,
    DATA_FLAME_COUNT,
    DATA_SET_US_UP_THE_BOMB_BOT,
    DATA_SET_US_UP_THE_BOMB_ROCKET,
    DATA_SET_US_UP_THE_BOMB_MINE,
};

enum Npcs
{
    NPC_ROCKET                                  = 34050,
    NPC_BURST_TARGET                            = 34211,
    NPC_JUNK_BOT                                = 33855,
    NPC_ASSAULT_BOT                             = 34057,
    NPC_BOOM_BOT                                = 33836,
    NPC_EMERGENCY_BOT                           = 34147,
    NPC_FLAMES_INITIAL                          = 34363,
    NPC_FLAME_SPREAD                            = 34121,
    NPC_FROST_BOMB                              = 34149,
    NPC_MKII_TURRET                             = 34071,
    NPC_PROXIMITY_MINE                          = 34362
};

enum MimironChests
{
    CACHE_OF_INNOVATION_10                      = 194789,
    CACHE_OF_INNOVATION_HARDMODE_10             = 194957,
    CACHE_OF_INNOVATION_25                      = 194956,
    CACHE_OF_INNOVATION_HARDMODE_25             = 194958
};

Position const SummonPos[9] =
{
    {2703.93f, 2569.32f, 364.397f, 0},
    {2715.33f, 2569.23f, 364.397f, 0},
    {2726.85f, 2569.28f, 364.397f, 0},
    {2765.24f, 2534.38f, 364.397f, 0},
    {2759.54f, 2544.30f, 364.397f, 0},
    {2753.82f, 2554.22f, 364.397f, 0},
    {2764.95f, 2604.11f, 364.397f, 0},
    {2759.19f, 2594.26f, 364.397f, 0},
    {2753.56f, 2584.30f, 364.397f, 0}
};

#define FLAME_CAP 200 // find a good (blizzlike!) value

/*---------------------------------------------*
 *                   Mimiron                   *
 *---------------------------------------------*/

class TW_boss_mimiron : public CreatureScript
{
    public:
        TW_boss_mimiron() : CreatureScript("TW_boss_mimiron") { }

        struct TW_boss_mimironAI : public BossAI
        {
            TW_boss_mimironAI(Creature* creature) : BossAI(creature, BOSS_MIMIRON)
            {
                me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_ROCKET_STRIKE_DMG, true);
                me->SetReactState(REACT_PASSIVE);
                HasBeenInCombat = false;
            }

            void DespawnCreatures(uint32 entry, float distance)
            {
                std::list<Creature*> creatures;
                GetCreatureListWithEntryInGrid(creatures, me, entry, distance);

                if (creatures.empty())
                    return;

                for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                    (*iter)->DespawnOrUnsummon();
            }

            void Reset()
            {
                if (me->getFaction() == 35)
                    return;

                _Reset();
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_USE_STANDING);
                me->SetVisible(true);
                me->ExitVehicle();
                me->GetMotionMaster()->MoveTargetedHome();

                instance->SetData(DATA_MIMIRON_ELEVATOR, GO_STATE_ACTIVE);

                _phase = PHASE_NULL;
                _step = 0;
                _phaseTimer = -1;
                _botTimer = 0;
                _flameCount = 0;
                _mimironHardMode = false;
                _checkBotAlive = true;
                _enraged = false;
                _checkTargetTimer = 7000;
                rocketCriteria = true;
                mineCriteria = true;
                botCriteria = true;

                DespawnCreatures(NPC_FLAMES_INITIAL, 100.0f);
                DespawnCreatures(NPC_PROXIMITY_MINE, 100.0f);
                DespawnCreatures(NPC_ROCKET, 100.0f);
                DespawnCreatures(NPC_JUNK_BOT, 100.0f);
                DespawnCreatures(NPC_ASSAULT_BOT, 100.0f);
                DespawnCreatures(NPC_BOOM_BOT, 100.0f);
                DespawnCreatures(NPC_EMERGENCY_BOT, 100.0f);

                for (uint8 data = DATA_LEVIATHAN_MK_II; data <= DATA_AERIAL_UNIT; ++data)
                if (Creature* creature = ObjectAccessor::GetCreature(*me, instance->GetData64(data)))
                        if (creature->IsAlive())
                        {
                            creature->ExitVehicle();
                            creature->AI()->EnterEvadeMode();
                        }

                if (GameObject* go = me->FindNearestGameObject(GO_BIG_RED_BUTTON, 200))
                {
                    go->SetGoState(GO_STATE_READY);
                    go->SetLootState(GO_JUST_DEACTIVATED);
                    go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                }

                if (HasBeenInCombat)
                {
                    HasBeenInCombat = false;
                    instance->SetBossState(BOSS_MIMIRON, FAIL);
                }
            }

            void EndEncounter()
            {
                Talk(SAY_V07TRON_DEATH, me);

                me->setFaction(35);

                if (instance)
                {
                    instance->SetBossState(BOSS_MIMIRON, DONE);

                    if (_mimironHardMode)
                        me->SummonGameObject(RAID_MODE<uint32>(CACHE_OF_INNOVATION_HARDMODE_10, CACHE_OF_INNOVATION_HARDMODE_25), 2744.65f, 2569.46f,
                        364.314f, 3.14159f, 0, 0, 0.7f, 0.7f, 604800);
                    else
                        me->SummonGameObject(RAID_MODE<uint32>(CACHE_OF_INNOVATION_10, CACHE_OF_INNOVATION_25), 2744.65f, 2569.46f, 364.314f, 3.14159f,
                        0, 0, 0.7f, 0.7f, 604800);

                    instance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE, NPC_LEVIATHAN_MKII, 1);
                }

                EnterEvadeMode();
                me->DespawnOrUnsummon(5000);
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
                _phase = PHASE_INTRO;
                _flameTimer = 5000;
                _enrageTimer = _mimironHardMode ? 10*60*1000 : 15*60*1000; // Enrage in 10 (hard mode) or 15 min
                JumpToNextStep(100);

                HasBeenInCombat = true;

                if (GameObject* go = me->FindNearestGameObject(GO_BIG_RED_BUTTON, 200))
                    go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
            }

            void JumpToNextStep(uint32 timer)
            {
                _phaseTimer = timer;
                ++_step;
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                // prevent mimiron staying infight with leviathan introduced in rev #b40bf69
                // TODO: find out why this happens
                if (_checkTargetTimer < diff)
                {
                    if (!SelectTarget(SELECT_TARGET_RANDOM, 0, 200.0f, true))
                    {
                        EnterEvadeMode();
                        return;
                    }
                    _checkTargetTimer = 7000;
                }
                else
                    _checkTargetTimer -= diff;

                if (_enrageTimer <= diff && !_enraged)
                {
                    Talk(SAY_BERSERK, me);
                    for (uint8 data = DATA_LEVIATHAN_MK_II; data <= DATA_AERIAL_UNIT; ++data)
                    if (Creature* creature = ObjectAccessor::GetCreature(*me, instance->GetData64(data)))
                            creature->AI()->DoAction(DO_ENTER_ENRAGE);

                    _enraged = true;

                    if (_mimironHardMode)
                    {
                        DoCast(me, SPELL_SELF_DESTRUCTION, true);
                        DoCast(me, SPELL_SELF_DESTRUCTION_VISUAL, true);
                    }
                }
                else
                    _enrageTimer -= diff;

                if (_mimironHardMode)
                    if (_flameTimer <= diff)
                    {
                        for (uint8 i = 0; i < 3; ++i)
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                DoCast(target, SPELL_SUMMON_FLAMES_INITIAL, true);

                        _flameTimer = 30000;
                    }
                    else
                        _flameTimer -= diff;

                // All sections need to die within 15 seconds, else they respawn
                if (_checkBotAlive)
                    _botTimer = 0;
                else
                {
                    _botTimer += diff;
                    if (_botTimer > 15000) // spell 64383
                    {
                        if (Creature* Leviathan = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_LEVIATHAN_MK_II)))
                            Leviathan->AI()->DoAction(DO_LEVIATHAN_ASSEMBLED);
                        if (Creature* VX_001 = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_VX_001)))
                            VX_001->AI()->DoAction(DO_VX001_ASSEMBLED);
                        if (Creature* AerialUnit = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_AERIAL_UNIT)))
                            AerialUnit->AI()->DoAction(DO_AERIAL_ASSEMBLED);

                        _checkBotAlive = true;
                    }
                    else
                    {
                        Creature* Leviathan = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_LEVIATHAN_MK_II));
                        Creature* VX_001 = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_VX_001));
                        Creature* AerialUnit = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_AERIAL_UNIT));
                        if (Leviathan && VX_001 && AerialUnit)
                        {
                            if (Leviathan->getStandState() == UNIT_STAND_STATE_DEAD &&
                                VX_001->getStandState() == UNIT_STAND_STATE_DEAD &&
                                AerialUnit->getStandState() == UNIT_STAND_STATE_DEAD)
                            {
                                Leviathan->DespawnOrUnsummon(5*MINUTE*IN_MILLISECONDS);
                                VX_001->DisappearAndDie();
                                AerialUnit->DisappearAndDie();
                                me->Kill(Leviathan);
                                DespawnCreatures(NPC_FLAMES_INITIAL, 100.0f);
                                DespawnCreatures(NPC_PROXIMITY_MINE, 100.0f);
                                DespawnCreatures(NPC_ROCKET, 100);
                                me->ExitVehicle();
                                EndEncounter();
                                _checkBotAlive = true;
                            }
                        }
                    }
                }

                if (_phase == PHASE_INTRO)
                {
                    if (_phaseTimer <= diff)
                    {
                        switch (_step)
                        {
                            case 1:
                                Talk(_mimironHardMode ? SAY_HARDMODE_ON : SAY_AGGRO, me);
                                JumpToNextStep(10000);
                                break;
                            case 2:
                                if (instance)
                                {
                                    if (Creature* Leviathan = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_LEVIATHAN_MK_II)))
                                        me->EnterVehicle(Leviathan, 4);
                                }
                                JumpToNextStep(2000);
                                break;
                            case 3:
                                me->ChangeSeat(2);
                                JumpToNextStep(2000);
                                break;
                            case 4:
                                me->ChangeSeat(5);
                                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_STAND);
                                JumpToNextStep(2500);
                                break;
                            case 5:
                                Talk(SAY_MKII_ACTIVATE, me);
                                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_TALK);
                                JumpToNextStep(6000);
                                break;
                            case 6:
                                me->ChangeSeat(6);
                                JumpToNextStep(2000);
                                break;
                            case 7:
                                if (instance)
                                {
                                    if (Creature* Leviathan = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_LEVIATHAN_MK_II)))
                                    {
                                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_STAND);
                                        Leviathan->AI()->DoAction(DO_START_ENCOUNTER);
                                        _phase = PHASE_COMBAT;
                                    }
                                }
                                break;
                            default:
                                break;
                        }
                    }
                    else
                        _phaseTimer -= diff;
                }

                if (_phase == PHASE_VX001_ACTIVATION)
                {
                    if (_phaseTimer <= diff)
                    {
                        switch (_step)
                        {
                            case 1:
                                Talk(SAY_MKII_DEATH, me);
                                JumpToNextStep(10000);
                                break;
                            case 2:
                                me->ChangeSeat(1);
                                JumpToNextStep(2000);
                                break;
                            case 3:
                                if (instance)
                                    instance->SetData(DATA_MIMIRON_ELEVATOR, GO_STATE_READY);
                                JumpToNextStep(5000);
                                break;
                            case 4:
                                if (instance)
                                {
                                    if (Creature* VX_001 = me->SummonCreature(NPC_VX_001, 2744.65f, 2569.46f, 364.397f, 3.14159f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000))
                                    {
                                        instance->SetData(DATA_MIMIRON_ELEVATOR, GO_STATE_ACTIVE_ALTERNATIVE);
                                        VX_001->SetVisible(true);
                                        for (uint8 n = 5; n < 7; ++n)
                                        {
                                            if (Creature* Rocket = me->SummonCreature(NPC_ROCKET, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_MANUAL_DESPAWN))
                                            {
                                                Rocket->setFaction(14);
                                                Rocket->SetReactState(REACT_PASSIVE);
                                                Rocket->EnterVehicle(VX_001, n);
                                            }
                                        }
                                    }
                                }
                                JumpToNextStep(8000);
                                break;
                            case 5:
                                if (instance)
                                {
                                    if (Creature* VX_001 = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_VX_001)))
                                        me->EnterVehicle(VX_001, 0);
                                }
                                JumpToNextStep(3500);
                                break;
                            case 6:
                                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_TALK);
                                Talk(SAY_VX001_ACTIVATE, me);
                                JumpToNextStep(10000);
                                break;
                            case 7:
                                me->ChangeSeat(1);
                                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_SIT);
                                JumpToNextStep(2000);
                                break;
                            case 8:
                                if (instance)
                                {
                                    if (Creature* VX_001 = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_VX_001)))
                                        VX_001->HandleEmoteCommand(EMOTE_ONESHOT_EMERGE);
                                }
                                JumpToNextStep(3500);
                                break;
                            case 9:
                                if (instance)
                                if (Creature* VX_001 = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_VX_001)))
                                    {
                                        VX_001->AddAura(SPELL_HOVER, VX_001); // Hover
                                        VX_001->AI()->DoAction(DO_START_VX001);
                                        _phase = PHASE_COMBAT;
                                    }
                                break;
                            default:
                                break;
                        }
                    }
                    else
                        _phaseTimer -= diff;
                }

                if (_phase == PHASE_AERIAL_ACTIVATION)
                {
                    if (_phaseTimer <= diff)
                    {
                        switch (_step)
                        {
                            case 1:
                                me->ChangeSeat(4);
                                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_STAND);
                                JumpToNextStep(2500);
                                break;
                            case 2:
                                Talk(SAY_VX001_DEATH, me);
                                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_TALK);
                                JumpToNextStep(5000);
                                break;
                            case 3:
                                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_STAND);
                                if (instance)
                                {
                                    if (Creature* AerialUnit = me->SummonCreature(NPC_AERIAL_COMMAND_UNIT, 2744.65f, 2569.46f, 380, 3.14159f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000))
                                        AerialUnit->SetVisible(true);
                                }
                                JumpToNextStep(5000);
                                break;
                            case 4:
                                me->ExitVehicle();
                                //me->GetMotionMaster()->MoveJump(2745.06f, 2569.36f, 379.90f, 10, 15);
                                if (Creature* AerialUnit = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_AERIAL_UNIT)))
                                     me->EnterVehicle(AerialUnit, 0);
                                JumpToNextStep(2000);
                                break;
                            case 5:
                                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_TALK);
                                Talk(SAY_AERIAL_ACTIVATE, me);
                                JumpToNextStep(8000);
                                break;
                            case 6:
                                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_STAND);
                                //me->SetVisible(false);
                                if (instance)
                                {
                                    if (Creature* AerialUnit = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_AERIAL_UNIT)))
                                    {
                                        AerialUnit->AI()->DoAction(DO_START_AERIAL);
                                        _phase = PHASE_COMBAT;
                                    }
                                }
                                break;
                            default:
                                break;
                        }
                    }
                    else
                        _phaseTimer -= diff;
                }

                if (_phase == PHASE_V0L7R0N_ACTIVATION)
                {
                    if (_phaseTimer <= diff)
                    {
                        switch (_step)
                        {
                            case 1:
                                if (instance)
                                {
                                    //me->SetVisible(true);
                                    if (Creature* Leviathan = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_LEVIATHAN_MK_II)))
                                       Leviathan->GetMotionMaster()->MovePoint(0, 2744.65f, 2569.46f, 364.397f);
                                    if (Creature* VX_001 = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_VX_001)))
                                    {
                                        me->EnterVehicle(VX_001, 1);
                                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_STAND);
                                        Talk(SAY_AERIAL_DEATH, me);
                                    }
                                }
                                JumpToNextStep(5000);
                                break;
                            case 2:
                                if (instance)
                                if (Creature* VX_001 = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_VX_001)))
                                if (Creature* Leviathan = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_LEVIATHAN_MK_II)))
                                        {
                                            VX_001->SetStandState(UNIT_STAND_STATE_STAND);
                                            VX_001->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_CUSTOM_SPELL_01);
                                            VX_001->EnterVehicle(Leviathan, 7);
                                        }
                                JumpToNextStep(2000);
                                break;
                            case 3:
                                if (instance)
                                if (Creature* VX_001 = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_VX_001)))
                                if (Creature* AerialUnit = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_AERIAL_UNIT)))
                                        {
                                            AerialUnit->SetDisableGravity(false);
                                            AerialUnit->EnterVehicle(VX_001, 3);
                                            Talk(SAY_V07TRON_ACTIVATE, me);
                                        }
                                JumpToNextStep(10000);
                                break;
                            case 4:
                                if (instance)
                                {
                                    if (Creature* Leviathan = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_LEVIATHAN_MK_II)))
                                        Leviathan->AI()->DoAction(DO_LEVIATHAN_ASSEMBLED);
                                    if (Creature* VX_001 = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_VX_001)))
                                        VX_001->AI()->DoAction(DO_VX001_ASSEMBLED);
                                    if (Creature* AerialUnit = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_AERIAL_UNIT)))
                                        AerialUnit->AI()->DoAction(DO_AERIAL_ASSEMBLED);
                                    _phase = PHASE_COMBAT;
                                }
                                break;
                            default:
                                break;
                        }
                    }
                    else
                        _phaseTimer -= diff;
                }
            }

            uint32 GetData(uint32 type) const
            {
                switch (type)
                {
                    case DATA_GET_HARD_MODE:
                        return _mimironHardMode ? 1 : 0;
                    case DATA_FLAME_COUNT:
                        return _flameCount;
                    case DATA_SET_US_UP_THE_BOMB_MINE:
                        return mineCriteria;
                    case DATA_SET_US_UP_THE_BOMB_ROCKET:
                        return rocketCriteria;
                    case DATA_SET_US_UP_THE_BOMB_BOT:
                        return botCriteria;
                    default:
                        return 0;
                }
            }

            void SetData(uint32 uiType, uint32 uiData) override
            {
                switch (uiType)
                {
                    case DATA_SET_US_UP_THE_BOMB_MINE:
                        mineCriteria = uiData;
                        break;
                    case DATA_SET_US_UP_THE_BOMB_ROCKET:
                        rocketCriteria = uiData;
                        break;
                    case DATA_SET_US_UP_THE_BOMB_BOT:
                        botCriteria = uiData;
                        break;
                    default:
                        break;
                }
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case DO_ACTIVATE_VX001:
                        _phase = PHASE_VX001_ACTIVATION;
                        _step = 0;
                        _phaseTimer = -1;
                        JumpToNextStep(100);
                        break;
                    case DO_ACTIVATE_AERIAL:
                        _phase = PHASE_AERIAL_ACTIVATION;
                        _step = 0;
                        _phaseTimer = -1;
                        JumpToNextStep(5000);
                        break;
                    case DO_ACTIVATE_V0L7R0N:
                        me->SetVisible(true);
                        _phase = PHASE_V0L7R0N_ACTIVATION;
                        _step = 0;
                        _phaseTimer = -1;
                        JumpToNextStep(1000);
                        break;
                    case DO_ACTIVATE_DEATH_TIMER:
                        _checkBotAlive = false;
                        break;
                    case DO_ACTIVATE_HARD_MODE:
                        _mimironHardMode = true;
                        DoZoneInCombat();
                        break;
                    case DO_INCREASE_FLAME_COUNT:
                        ++_flameCount;
                        break;
                    case DO_DECREASE_FLAME_COUNT:
                        if (_flameCount)
                            --_flameCount;
                        break;
                }
            }

        private:
            Phases _phase;
            uint32 _phaseTimer;
            uint32 _step;
            uint32 _enrageTimer;
            uint32 _flameTimer;
            uint32 _flameCount;
            uint32 _botTimer;
            uint32 _checkTargetTimer;
            bool _mimironHardMode;
            bool _checkBotAlive;
            bool _enraged;
            bool rocketCriteria;
            bool mineCriteria;
            bool botCriteria;
            bool HasBeenInCombat;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new TW_boss_mimironAI(creature);
        }
};


/*---------------------------------------------*
 *              Leviathan MK II                *
 *---------------------------------------------*/

class TW_boss_leviathan_mk : public CreatureScript
{
public:
    TW_boss_leviathan_mk() : CreatureScript("TW_boss_leviathan_mk") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new TW_boss_leviathan_mkAI(creature);
    }

    struct TW_boss_leviathan_mkAI : public BossAI
    {
        TW_boss_leviathan_mkAI(Creature* creature) : BossAI(creature, BOSS_MIMIRON), phase(PHASE_NULL)
        {
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_ROCKET_STRIKE_DMG, true);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        Phases phase;
        bool MimironHardMode;

        void Reset()
        {
            events.Reset();
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
            me->SetStandState(UNIT_STAND_STATE_STAND);
            me->SetReactState(REACT_PASSIVE);
            me->RemoveAllAurasExceptType(SPELL_AURA_CONTROL_VEHICLE);
            phase = PHASE_NULL;
            events.SetPhase(PHASE_NULL);
            MimironHardMode = false;
        }

        void KilledUnit(Unit* who)
        {
            if (Creature* Mimiron = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_MIMIRON)))
            {
                if (phase == PHASE_LEVIATHAN_SOLO)
                    Talk(SAY_MKII_SLAY, Mimiron);
                else
                    Talk(SAY_V07TRON_SLAY, Mimiron);
            }
            if (who->GetTypeId() == TYPEID_PLAYER)
                me->GetInstanceScript()->SetData(DATA_CRITERIA_MIMIRON, 1);
        }

        void DamageTaken(Unit* /*who*/, uint32 &damage)
        {
            if (phase == PHASE_LEVIATHAN_SOLO)
                if (damage >= me->GetHealth())
                {
                    damage = 0;
                    me->InterruptNonMeleeSpells(true);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    me->RemoveAllAurasExceptType(SPELL_AURA_CONTROL_VEHICLE);
                    me->SetHealth(me->GetMaxHealth());
                    events.SetPhase(PHASE_NULL);
                    phase = PHASE_NULL;
                    if (Creature* Mimiron = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_MIMIRON)))
                        Mimiron->AI()->DoAction(DO_ACTIVATE_VX001);
                    if (Creature* turret = me->GetVehicleKit()->GetPassenger(3)->ToCreature())
                        turret->Kill(turret, false);
                    me->SetSpeed(MOVE_RUN, 1.5f, true);
                    me->GetMotionMaster()->MovePoint(0, 2790.11f, 2595.83f, 364.32f);
                }

            if (phase == PHASE_LEVIATHAN_ASSEMBLED)
                if (damage >= me->GetHealth())
                {
                    damage = 0;
                    me->InterruptNonMeleeSpells(true);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    me->RemoveAllAurasExceptType(SPELL_AURA_CONTROL_VEHICLE);
                    me->SetHealth(me->GetMaxHealth());
                    me->SetStandState(UNIT_STAND_STATE_DEAD);
                    events.SetPhase(PHASE_NULL);
                    phase = PHASE_NULL;
                    if (Creature* Mimiron = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_MIMIRON)))
                        Mimiron->AI()->DoAction(DO_ACTIVATE_DEATH_TIMER);
                }
        }

        void EnterCombat(Unit* /*who*/)
        {
            if (Creature* Mimiron = ObjectAccessor::GetCreature(*me, instance ? instance->GetData64(BOSS_MIMIRON) : 0))
                MimironHardMode = Mimiron->AI()->GetData(DATA_GET_HARD_MODE) == 1;

            if (MimironHardMode)
            {
                DoCast(me, SPELL_EMERGENCY_MODE, true);
                events.ScheduleEvent(EVENT_FLAME_SUPPRESSANT, 60000, 0, PHASE_LEVIATHAN_SOLO);
            }

            if (Creature* turret = me->GetVehicleKit()->GetPassenger(3)->ToCreature())
            {
                turret->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
                turret->SetReactState(REACT_AGGRESSIVE);
                turret->AI()->DoZoneInCombat();
            }

            events.ScheduleEvent(EVENT_PROXIMITY_MINE, 1000);
            events.ScheduleEvent(EVENT_PLASMA_BLAST, 10000, 0, PHASE_LEVIATHAN_SOLO);
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
                case DO_START_ENCOUNTER:
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_IMMUNE_TO_PC);
                    me->SetReactState(REACT_AGGRESSIVE);
                    phase = PHASE_LEVIATHAN_SOLO;
                    events.SetPhase(PHASE_LEVIATHAN_SOLO);
                    DoZoneInCombat();
                    break;
                case DO_LEVIATHAN_ASSEMBLED:
                    if (MimironHardMode)
                        DoCast(me, SPELL_EMERGENCY_MODE, true);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->SetHealth(int32(me->GetMaxHealth() / 2));
                    me->SetSpeed(MOVE_RUN, 1.0f, true);
                    me->SetStandState(UNIT_STAND_STATE_STAND);
                    phase = PHASE_LEVIATHAN_ASSEMBLED;
                    events.SetPhase(PHASE_LEVIATHAN_ASSEMBLED);
                    events.RescheduleEvent(EVENT_PROXIMITY_MINE, 1000);
                    events.RescheduleEvent(EVENT_SHOCK_BLAST, 30000);
                    break;
                case DO_ENTER_ENRAGE:
                    DoCast(me, SPELL_BERSERK, true);
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING) || me->HasUnitState(UNIT_STATE_STUNNED))
                return;

            if (phase == PHASE_LEVIATHAN_SOLO || phase == PHASE_LEVIATHAN_ASSEMBLED)
            {
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_PROXIMITY_MINE:
                            for (int i = 0; i < 10; ++i)
                                DoCast(SPELL_MINES_SPAWN);
                            DoCast(SPELL_PROXIMITY_MINES);
                            events.RescheduleEvent(EVENT_PROXIMITY_MINE, 35000);
                            break;
                        case EVENT_PLASMA_BLAST:
                            me->MonsterTextEmote(EMOTE_LEVIATHAN, 0, true);
                            DoCast(SPELL_PLASMA_BLAST);
                            events.RescheduleEvent(EVENT_PLASMA_BLAST, urand(30000, 35000), 0, PHASE_LEVIATHAN_SOLO);
                            events.RescheduleEvent(EVENT_SHOCK_BLAST, urand(6000, 10000));
                            return;
                        case EVENT_SHOCK_BLAST:
                            DoCastAOE(SPELL_SHOCK_BLAST);
                            events.RescheduleEvent(EVENT_SHOCK_BLAST, 35000);
                            return;
                        case EVENT_FLAME_SUPPRESSANT:
                            DoCastAOE(SPELL_FLAME_SUPPRESSANT);
                            events.CancelEvent(EVENT_FLAME_SUPPRESSANT);
                            break;
                    }
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

class TW_boss_leviathan_mk_turret : public CreatureScript
{
    public:
        TW_boss_leviathan_mk_turret() : CreatureScript("TW_boss_leviathan_mk_turret") { }

        struct TW_boss_leviathan_mk_turretAI : public ScriptedAI
        {
            TW_boss_leviathan_mk_turretAI(Creature* c) : ScriptedAI(c)
            {
                me->SetReactState(REACT_PASSIVE);
                _NapalmShell = urand(8000, 12000);
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    me->GetInstanceScript()->SetData(DATA_CRITERIA_MIMIRON, 1);
            }

            // try to prefer ranged targets
            Unit* GetNapalmShellTarget()
            {
                Map* map = me->GetMap();
                if (map && map->IsDungeon())
                {
                    std::list<Player*> playerList;
                    Map::PlayerList const& Players = map->GetPlayers();
                    for (Map::PlayerList::const_iterator itr = Players.begin(); itr != Players.end(); ++itr)
                    {
                        if (Player* player = itr->GetSource())
                        {
                            if (player->isDead() || player->IsGameMaster())
                                continue;

                            float Distance = player->GetDistance(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
                            if (Distance < 15.0f || Distance > 100.0f)
                                continue;

                            playerList.push_back(player);
                        }
                    }

                    if (playerList.empty())
                        return NULL;

                    return Trinity::Containers::SelectRandomContainerElement(playerList);
                }
                else
                    return NULL;
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (_NapalmShell <= diff)
                {
                    Unit* shellTarget = GetNapalmShellTarget();
                    if (!shellTarget)
                        shellTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true);
                    if (shellTarget)
                        DoCast(shellTarget, SPELL_NAPALM_SHELL);
                    _NapalmShell = urand(8000, 12000);
                }
                else
                    _NapalmShell -= diff;
            }

        private:
            uint32 _NapalmShell;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new TW_boss_leviathan_mk_turretAI(creature);
        }
};

class TW_npc_proximity_mine : public CreatureScript
{
public:
    TW_npc_proximity_mine() : CreatureScript("TW_npc_proximity_mine") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new TW_npc_proximity_mineAI(creature);
    }

    struct TW_npc_proximity_mineAI : public ScriptedAI
    {
        TW_npc_proximity_mineAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC);
           me->AddUnitState(UNIT_STATE_ROOT);
           uiBoomTimer = 35000;
           Boom = false;
        }

        uint32 uiBoomTimer;
        bool Boom;

        void MoveInLineOfSight(Unit* who)
        {
            if (!Boom && me->IsWithinDistInMap(who, 0.5f) && who->ToPlayer() && !who->ToPlayer()->IsGameMaster())
            {
                DoCast(SPELL_EXPLOSION);
                me->DespawnOrUnsummon(1000);
                Boom = true;
            }
        }

        void SpellHitTarget(Unit* target, SpellInfo const* spell) override
        {
            if (target->GetTypeId() == TYPEID_PLAYER && spell->Id == SPELL_EXPLOSION)
                if (Creature* Mimiron = me->FindNearestCreature(NPC_MIMIRON, 200.0f))
                    Mimiron->AI()->SetData(DATA_SET_US_UP_THE_BOMB_MINE, false);
        }
        
        void KilledUnit(Unit* who) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                me->GetInstanceScript()->SetData(DATA_CRITERIA_MIMIRON, 1);
        }

        void UpdateAI(uint32 diff) override
        {
            if (uiBoomTimer <= diff)
            {
                if (!Boom)
                {
                    DoCast(SPELL_EXPLOSION);
                    me->DespawnOrUnsummon(1000);
                    Boom = true;
                }
            }
            else uiBoomTimer -= diff;
        }
    };
};

/*---------------------------------------------*
 *                    VX-001                   *
 *---------------------------------------------*/

class TW_boss_vx_001 : public CreatureScript
{
public:
    TW_boss_vx_001() : CreatureScript("TW_boss_vx_001") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new TW_boss_vx_001AI(creature);
    }

    struct TW_boss_vx_001AI : public BossAI
    {
        TW_boss_vx_001AI(Creature* creature) : BossAI(creature, BOSS_MIMIRON), phase(PHASE_NULL)
        {
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_ROCKET_STRIKE_DMG, true);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        Phases phase;
        bool MimironHardMode;

        bool spinning;
        bool direction;
        uint32 spinTimer;

        void Reset()
        {
            spinning = false;
            direction = false;
            spinTimer = 250;

            events.Reset();
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_DISABLE_MOVE);
            //me->SetReactState(REACT_PASSIVE);
            me->SetStandState(UNIT_STAND_STATE_STAND);
            //me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_STAND);
            me->SetVisible(false);
            me->RemoveAllAurasExceptType(SPELL_AURA_CONTROL_VEHICLE);
            phase = PHASE_NULL;
            events.SetPhase(PHASE_NULL);
            MimironHardMode = false;

            // TODO: remove when Spinning Up is fixed properly
            me->ApplySpellImmune(0, IMMUNITY_ID, 48181, true);
            me->ApplySpellImmune(0, IMMUNITY_ID, 59161, true);
            me->ApplySpellImmune(0, IMMUNITY_ID, 59163, true);
            me->ApplySpellImmune(0, IMMUNITY_ID, 59164, true);
        }

        void KilledUnit(Unit* who)
        {
            if (!(rand()%5))
                if (instance)
                if (Creature* Mimiron = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_MIMIRON)))
                    {
                        if (phase == PHASE_VX001_SOLO)
                            Talk(SAY_VX001_SLAY, Mimiron);
                        else
                            Talk(SAY_V07TRON_SLAY, Mimiron);
                    }

                    if (who->GetTypeId() == TYPEID_PLAYER)
                        me->GetInstanceScript()->SetData(DATA_CRITERIA_MIMIRON, 1);
        }

        void EnterCombat(Unit* /*who*/)
        {
            if (Creature* Mimiron = ObjectAccessor::GetCreature(*me, instance ? instance->GetData64(BOSS_MIMIRON) : 0))
                MimironHardMode = Mimiron->AI()->GetData(DATA_GET_HARD_MODE) == 1;

            if (MimironHardMode)
            {
                DoCast(me, SPELL_EMERGENCY_MODE, true);
                events.ScheduleEvent(EVENT_FROST_BOMB, 15000);
                events.ScheduleEvent(EVENT_FLAME_SUPPRESSANT_VX001, 1000, 0, PHASE_VX001_SOLO);
            }

            events.ScheduleEvent(EVENT_RAPID_BURST, 2500, 0, PHASE_VX001_SOLO);
            events.ScheduleEvent(EVENT_LASER_BARRAGE, urand(35000, 40000));
            events.ScheduleEvent(EVENT_ROCKET_STRIKE, 20000);
            events.ScheduleEvent(EVENT_HEAT_WAVE, urand(8000, 10000), 0, PHASE_VX001_SOLO);
            events.ScheduleEvent(EVENT_HAND_PULSE, 10000, 0, PHASE_VX001_ASSEMBLED);
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
                case DO_START_VX001:
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_IMMUNE_TO_PC);
                    phase = PHASE_VX001_SOLO;
                    events.SetPhase(PHASE_VX001_SOLO);
                    DoZoneInCombat();
                    break;
                case DO_VX001_ASSEMBLED:
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
                    me->SetHealth(int32(me->GetMaxHealth() / 2));
                    me->SetStandState(UNIT_STAND_STATE_STAND);
                    phase = PHASE_VX001_ASSEMBLED;
                    events.SetPhase(PHASE_VX001_ASSEMBLED);
                    
                    if (Creature* Rocket = me->SummonCreature(NPC_ROCKET, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        Rocket->setFaction(14);
                        Rocket->SetReactState(REACT_PASSIVE);
                        Rocket->EnterVehicle(me, 6);
                    }

                    events.RescheduleEvent(EVENT_LASER_BARRAGE, urand(35000, 40000));
                    events.RescheduleEvent(EVENT_ROCKET_STRIKE, 20000);
                    events.RescheduleEvent(EVENT_HAND_PULSE, 15000, 0, PHASE_VX001_ASSEMBLED);
                    if (MimironHardMode)
                    {
                        DoCast(me, SPELL_EMERGENCY_MODE, true);
                        events.RescheduleEvent(EVENT_FROST_BOMB, 15000);
                    }
                    break;
                case DO_ENTER_ENRAGE:
                    DoCast(me, SPELL_BERSERK, true);
                    break;
            }
        }

        void DamageTaken(Unit* /*who*/, uint32 &damage)
        {
            if (phase == PHASE_VX001_SOLO)
                if (damage >= me->GetHealth())
                {
                    damage = 0;
                    spinning = false;
                    me->InterruptNonMeleeSpells(true);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
                    me->AttackStop();
                    me->GetMotionMaster()->Initialize();
                    me->RemoveAllAurasExceptType(SPELL_AURA_CONTROL_VEHICLE);
                    me->SetHealth(me->GetMaxHealth());
                    me->SetStandState(UNIT_STAND_STATE_DEAD);
                    phase = PHASE_NULL;
                    events.SetPhase(PHASE_NULL);
                    if (Creature* Mimiron = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_MIMIRON)))
                        Mimiron->AI()->DoAction(DO_ACTIVATE_AERIAL);
                }

            if (phase == PHASE_VX001_ASSEMBLED)
                if (damage >= me->GetHealth())
                {
                    damage = 0;
                    spinning = false;
                    me->InterruptNonMeleeSpells(true);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
                    me->AttackStop();
                    me->RemoveAllAurasExceptType(SPELL_AURA_CONTROL_VEHICLE);
                    me->SetHealth(me->GetMaxHealth());
                    me->SetStandState(UNIT_STAND_STATE_DEAD);
                    events.SetPhase(PHASE_NULL);
                    phase = PHASE_NULL;
                    if (Creature* Mimiron = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_MIMIRON)))
                        Mimiron->AI()->DoAction(DO_ACTIVATE_DEATH_TIMER);
                }
        }

        void SpellHitTarget(Unit* target, SpellInfo const* spell)
        {
            if (spell->Id == SPELL_FROST_BOMB)
                me->SummonCreature(NPC_FROST_BOMB, *target, TEMPSUMMON_TIMED_DESPAWN, 11000);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (spinning)
            {
                if (spinTimer <= diff)
                {
                    float orient = me->GetOrientation();
                    orient += direction ? M_PI/60 : -M_PI/60;

                    if (Creature* leviathan = me->GetVehicleCreatureBase())
                    {
                        leviathan->SetFacingTo(orient);
                        me->SetOrientation(orient);
                    }
                    else
                        me->SetFacingTo(orient);

                    float x, y;
                    me->GetNearPoint2D(x, y, 10.0f, me->GetOrientation());
                    if (Creature* temp = me->SummonCreature(NPC_BURST_TARGET, x, y, me->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN, 500))
                        me->SetTarget(temp->GetGUID());

                    spinTimer = 250;
                }
                else
                    spinTimer -= diff;
            }

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (phase == PHASE_VX001_SOLO || phase == PHASE_VX001_ASSEMBLED)
            {
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_RAPID_BURST:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                if (Creature* BurstTarget = me->SummonCreature(NPC_BURST_TARGET, *target, TEMPSUMMON_TIMED_DESPAWN, 3100))
                                    DoCast(BurstTarget, SPELL_RAPID_BURST);
                            events.RescheduleEvent(EVENT_RAPID_BURST, 5000, 0, PHASE_VX001_SOLO);
                            break;
                        case EVENT_LASER_BARRAGE:
                            me->SetReactState(REACT_PASSIVE);
                            if (Creature* leviathan = me->GetVehicleCreatureBase())
                            {
                                float orient = float(2*M_PI * rand_norm());
                                leviathan->CastSpell(leviathan, 14821, true); // temporary
                                leviathan->SetFacingTo(orient);
                                me->SetOrientation(orient);
                            }
                            direction = urand(0, 1);
                            spinning = true;
                            DoCast(SPELL_SPINNING_UP);
                            events.DelayEvents(15000);
                            events.RescheduleEvent(EVENT_LASER_BARRAGE, 60000);
                            events.RescheduleEvent(EVENT_LASER_BARRAGE_END, 14000);
                            break;
                        case EVENT_LASER_BARRAGE_END:
                            me->SetReactState(REACT_AGGRESSIVE);
                            if (me->GetVictim())
                                AttackStart(me->GetVictim());
                            spinning = false;
                            break;
                        case EVENT_ROCKET_STRIKE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                if (Unit* missile = me->GetVehicleKit()->GetPassenger(5))
                                    missile->CastSpell(target, SPELL_ROCKET_STRIKE, true);
                            if (phase == PHASE_VX001_ASSEMBLED)
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                    if (Unit* missile = me->GetVehicleKit()->GetPassenger(6))
                                        missile->CastSpell(target, SPELL_ROCKET_STRIKE, true);
                            events.RescheduleEvent(EVENT_ROCKET_STRIKE, urand(20000, 25000));
                            break;
                        case EVENT_HEAT_WAVE:
                            DoCastAOE(SPELL_HEAT_WAVE);
                            events.RescheduleEvent(EVENT_HEAT_WAVE, 10000, 0, PHASE_VX001_SOLO);
                            break;
                        case EVENT_HAND_PULSE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                DoCast(target, SPELL_HAND_PULSE);
                            events.RescheduleEvent(EVENT_HAND_PULSE, urand(3000, 4000));
                            break;
                        case EVENT_FROST_BOMB:
                            if (me->FindNearestCreature(NPC_FLAME_SPREAD, 100.0f))
                            {
                                me->CastCustomSpell(SPELL_FROST_BOMB, SPELLVALUE_MAX_TARGETS, 1, NULL);
                                events.RescheduleEvent(EVENT_FROST_BOMB, 45000);
                            }
                            else
                                events.RescheduleEvent(EVENT_FROST_BOMB, 5000);
                            break;
                        case EVENT_FLAME_SUPPRESSANT_VX001:
                            DoCastAOE(SPELL_FLAME_SUPPRESSANT_VX001);
                            events.RescheduleEvent(EVENT_FLAME_SUPPRESSANT_VX001, 10000, 0, PHASE_VX001_SOLO);
                            break;
                    }
                }
            }
        }
    };
};

class TW_npc_rocket_strike : public CreatureScript
{
public:
    TW_npc_rocket_strike() : CreatureScript("TW_npc_rocket_strike") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new TW_npc_rocket_strikeAI(creature);
    }

    struct TW_npc_rocket_strikeAI : public ScriptedAI
    {
        TW_npc_rocket_strikeAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);
            me->DespawnOrUnsummon(10000);
            DoCast(me, SPELL_ROCKET_STRIKE_AURA);
        }
        
        void KilledUnit(Unit* who) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                me->GetInstanceScript()->SetData(DATA_CRITERIA_MIMIRON, 1);
        }

        void SpellHitTarget(Unit* target, SpellInfo const* spell) override
        {
            if (target->GetTypeId() == TYPEID_PLAYER && spell->Id == SPELL_ROCKET_STRIKE_DMG)
                if (Creature* Mimiron = me->FindNearestCreature(NPC_MIMIRON, 200.0f))
                    Mimiron->AI()->SetData(DATA_SET_US_UP_THE_BOMB_ROCKET, false);
        }
    };
};

class TW_spell_rapid_burst : public SpellScriptLoader
{
    public:
        TW_spell_rapid_burst() : SpellScriptLoader("TW_spell_rapid_burst") { }

        class spell_rapid_burst_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_rapid_burst_AuraScript);

            void HandleDummyTick(AuraEffect const* aurEff)
            {
                if (!GetTarget())
                    return;

                if (Unit* caster = GetCaster())
                {
                    switch (caster->GetMap()->GetDifficulty())
                    {
                        case RAID_DIFFICULTY_10MAN_NORMAL:
                            caster->CastSpell(GetTarget(), RAND(SPELL_RAPID_BURST_LEFT_10, SPELL_RAPID_BURST_RIGHT_10), true, NULL, aurEff);
                            break;
                        case RAID_DIFFICULTY_25MAN_NORMAL:
                            caster->CastSpell(GetTarget(), RAND(SPELL_RAPID_BURST_LEFT_25, SPELL_RAPID_BURST_RIGHT_25), true, NULL, aurEff);
                            break;
                        default:
                            break;
                    }
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_rapid_burst_AuraScript::HandleDummyTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_rapid_burst_AuraScript();
        }
};

/*---------------------------------------------*
 *             Aerial Command Unit             *
 *---------------------------------------------*/

class TW_boss_aerial_unit : public CreatureScript
{
public:
    TW_boss_aerial_unit() : CreatureScript("TW_boss_aerial_unit") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new TW_boss_aerial_unitAI(creature);
    }

    struct TW_boss_aerial_unitAI : public BossAI
    {
        TW_boss_aerial_unitAI(Creature* creature) : BossAI(creature, BOSS_MIMIRON), phase(PHASE_NULL)
        {
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_ROCKET_STRIKE_DMG, true);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        Phases phase;
        bool MimironHardMode;
        uint8 spawnedAdds;

        void Reset()
        {
            events.Reset();
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_DISABLE_MOVE);
            me->SetReactState(REACT_PASSIVE);
            me->SetStandState(UNIT_STAND_STATE_STAND);
            me->SetVisible(false);
            me->RemoveAllAurasExceptType(SPELL_AURA_CONTROL_VEHICLE);
            me->SetDisableGravity(true);
            phase = PHASE_NULL;
            events.SetPhase(PHASE_NULL);
            summons.DespawnAll();
            spawnedAdds = 0;
            MimironHardMode = false;
        }

        void KilledUnit(Unit* who)
        {
            if (Creature* Mimiron = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_MIMIRON)))
            {
                if (phase == PHASE_AERIAL_SOLO)
                    Talk(SAY_AERIAL_SLAY, Mimiron);
                else
                    Talk(SAY_V07TRON_SLAY, Mimiron);
            }

            if (who->GetTypeId() == TYPEID_PLAYER)
                me->GetInstanceScript()->SetData(DATA_CRITERIA_MIMIRON, 1);
        }

        void EnterCombat(Unit* /*who*/)
        {
            if (Creature* Mimiron = ObjectAccessor::GetCreature(*me, instance ? instance->GetData64(BOSS_MIMIRON) : 0))
                MimironHardMode = Mimiron->AI()->GetData(DATA_GET_HARD_MODE) == 1;

            if (MimironHardMode)
                DoCast(me, SPELL_EMERGENCY_MODE, true);

            events.ScheduleEvent(EVENT_PLASMA_BALL, 1000);
            events.ScheduleEvent(EVENT_SUMMON_BOTS, 10000, 0, PHASE_AERIAL_SOLO);
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
                case DO_START_AERIAL:
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_IMMUNE_TO_PC);
                    me->SetReactState(REACT_AGGRESSIVE);
                    phase = PHASE_AERIAL_SOLO;
                    events.SetPhase(PHASE_AERIAL_SOLO);
                    DoZoneInCombat();
                    break;
                case DO_DISABLE_AERIAL:
                    if (phase == PHASE_AERIAL_SOLO)
                    {
                        me->CastStop();
                        me->SetReactState(REACT_PASSIVE);
                        me->GetMotionMaster()->Clear(true);
                        DoCast(me, SPELL_MAGNETIC_CORE);
                        DoCast(me, SPELL_MAGNETIC_CORE_VISUAL);
                        me->NearTeleportTo(me->GetPositionX(), me->GetPositionY(), 368.965f, 0.0f);
                        events.RescheduleEvent(EVENT_PLASMA_BALL, 22000, 0, PHASE_AERIAL_SOLO);
                        events.RescheduleEvent(EVENT_SUMMON_BOTS, 24000, 0, PHASE_AERIAL_SOLO);
                        events.ScheduleEvent(EVENT_REACTIVATE_AERIAL, 20000, 0, PHASE_AERIAL_SOLO);
                    }
                    break;
                case DO_AERIAL_ASSEMBLED:
                    if (MimironHardMode)
                        DoCast(me, SPELL_EMERGENCY_MODE, true);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->SetHealth(int32(me->GetMaxHealth() / 2));
                    me->SetStandState(UNIT_STAND_STATE_STAND);
                    phase = PHASE_AERIAL_ASSEMBLED;
                    events.SetPhase(PHASE_AERIAL_ASSEMBLED);
                    events.RescheduleEvent(EVENT_PLASMA_BALL, 2000);
                    break;
                case DO_ENTER_ENRAGE:
                    DoCast(me, SPELL_BERSERK, true);
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

            if (phase == PHASE_AERIAL_SOLO || phase == PHASE_AERIAL_ASSEMBLED)
            {
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_PLASMA_BALL:
                            if (phase == PHASE_AERIAL_SOLO && me->GetVictim())
                            {
                                float x = me->GetVictim()->GetPositionX();
                                float y = me->GetVictim()->GetPositionY();
                                float z = me->GetVictim()->GetPositionZ();
                                if (me->IsWithinDist3d(x, y, z, 30))
                                {
                                    me->GetMotionMaster()->Initialize();
                                    DoCastVictim(SPELL_PLASMA_BALL);
                                }
                                else me->GetMotionMaster()->MovePoint(0, x, y, 380.04f);
                            }
                            else if (phase == PHASE_AERIAL_ASSEMBLED && me->GetVictim())
                            {
                                if (me->GetVictim()->IsWithinDist3d(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 30))
                                    DoCastVictim(SPELL_PLASMA_BALL);
                                else if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0))
                                    DoCast(target, SPELL_PLASMA_BALL);
                            }
                            events.RescheduleEvent(EVENT_PLASMA_BALL, 2000);
                            break;
                        case EVENT_REACTIVATE_AERIAL:
                            me->RemoveAurasDueToSpell(SPELL_MAGNETIC_CORE_VISUAL);
                            me->NearTeleportTo(me->GetPositionX(), me->GetPositionY(), 380.04f, 3.14159f, false);
                            me->SetReactState(REACT_AGGRESSIVE);
                            events.CancelEvent(EVENT_REACTIVATE_AERIAL);
                            break;
                        case EVENT_SUMMON_BOTS:
                            if (phase == PHASE_AERIAL_SOLO)
                            {
                                spawnAdd();
                                events.RescheduleEvent(EVENT_SUMMON_BOTS, 10000, 0, PHASE_AERIAL_SOLO);
                            }
                            break;
                    }
                }
            }
        }

        void spawnAdd()
        {
            switch (spawnedAdds)
            {
                case 0:
                    for (uint8 n = 0; n < 2; n++)
                        me->SummonCreature(NPC_JUNK_BOT, SummonPos[rand()%9], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                    break;
                case 1:
                    me->SummonCreature(NPC_ASSAULT_BOT, SummonPos[rand()%9], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000);
                    if (MimironHardMode)
                        for (uint8 i = 0; i < 2; ++i)
                            me->SummonCreature(NPC_EMERGENCY_BOT, SummonPos[rand()%9], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                    break;
                case 2:
                    me->SummonCreature(NPC_BOOM_BOT, 2744.65f, 2569.46f, 364.397f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                    break;
            }

            ++spawnedAdds;
            if (spawnedAdds > 2)
                spawnedAdds = 0;
        }

        void JustSummoned(Creature* summon)
        {
            summons.Summon(summon);

            if (summon->GetEntry() == NPC_EMERGENCY_BOT)
                return;

            summon->AI()->DoZoneInCombat();
            if (MimironHardMode)
                summon->CastSpell(summon, SPELL_EMERGENCY_MODE, true);
        }

        void DamageTaken(Unit* /*who*/, uint32 &damage)
        {
            if (phase == PHASE_AERIAL_SOLO)
                if (damage >= me->GetHealth())
                {
                    damage = 0;
                    me->InterruptNonMeleeSpells(true);
                    me->GetMotionMaster()->Clear(true);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
                    me->SetReactState(REACT_PASSIVE);
                    me->AttackStop();
                    me->RemoveAllAurasExceptType(SPELL_AURA_CONTROL_VEHICLE);
                    me->SetHealth(me->GetMaxHealth());
                    events.CancelEvent(EVENT_SUMMON_BOTS);
                    phase = PHASE_NULL;
                    events.SetPhase(PHASE_NULL);
                    if (Creature* Mimiron = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_MIMIRON)))
                        Mimiron->AI()->DoAction(DO_ACTIVATE_V0L7R0N);
                }

            if (phase == PHASE_AERIAL_ASSEMBLED)
                if (damage >= me->GetHealth())
                {
                    damage = 0;
                    me->InterruptNonMeleeSpells(true);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    me->RemoveAllAurasExceptType(SPELL_AURA_CONTROL_VEHICLE);
                    me->SetHealth(me->GetMaxHealth());
                    me->SetStandState(UNIT_STAND_STATE_DEAD);
                    events.SetPhase(PHASE_NULL);
                    phase = PHASE_NULL;
                    if (Creature* Mimiron = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_MIMIRON)))
                        Mimiron->AI()->DoAction(DO_ACTIVATE_DEATH_TIMER);
                }
        }
    };
};

class TW_npc_magnetic_core : public CreatureScript
{
    public:
        TW_npc_magnetic_core() : CreatureScript("TW_npc_magnetic_core") { }

        struct TW_npc_magnetic_coreAI : public ScriptedAI
        {
            TW_npc_magnetic_coreAI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);
                me->DespawnOrUnsummon(21000);
                if (Creature* AerialUnit = me->FindNearestCreature(NPC_AERIAL_COMMAND_UNIT, 100.0f, true))
                {
                    AerialUnit->AI()->DoAction(DO_DISABLE_AERIAL);
                    me->GetMotionMaster()->MoveFall();
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new TW_npc_magnetic_coreAI(creature);
        }
};

class TW_npc_assault_bot : public CreatureScript
{
    public:
        TW_npc_assault_bot() : CreatureScript("TW_npc_assault_bot") { }

        struct TW_npc_assault_botAI : public ScriptedAI
        {
            TW_npc_assault_botAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset()
            {
                _fieldTimer = urand(4000, 6000);
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    me->GetInstanceScript()->SetData(DATA_CRITERIA_MIMIRON, 1);      
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (_fieldTimer <= diff)
                {
                    DoCastVictim(SPELL_MAGNETIC_FIELD);
                    _fieldTimer = urand(15000, 20000);
                }
                else
                    _fieldTimer -= diff;

                DoMeleeAttackIfReady();
            }

            void SpellHit(Unit* /*caster*/, SpellInfo const* spell)
            {
                // Achievement Not-So-Friendly Fire
                if (spell->Id == SPELL_ROCKET_STRIKE_DMG)
                    DoCastAOE(SPELL_NOT_SO_FRIENDLY_FIRE);
            }

        private:
            uint32 _fieldTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new TW_npc_assault_botAI(creature);
        }
};

class TW_npc_emergency_bot : public CreatureScript
{
    public:
        TW_npc_emergency_bot() : CreatureScript("TW_npc_emergency_bot") { }

        struct TW_npc_emergency_botAI : public ScriptedAI
        {
            TW_npc_emergency_botAI(Creature* creature) : ScriptedAI(creature)
            {
                me->setFaction(14);
                me->SetReactState(REACT_PASSIVE);
                me->GetMotionMaster()->MoveRandom(15);
                _sprayTimer = 5000;

                if (Is25ManRaid())
                    DoCast(me, SPELL_DEAFENING_SIREN, true);
            }

            void UpdateAI(uint32 diff) override
            {
                if (_sprayTimer <= diff)
                {
                    DoCast(SPELL_WATER_SPRAY);
                    _sprayTimer = 10000;
                }
                else _sprayTimer -= diff;
            }

        private:
            uint32 _sprayTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new TW_npc_emergency_botAI(creature);
        }
};

class TW_npc_mimiron_bomb_bot : public CreatureScript
{
    public:
        TW_npc_mimiron_bomb_bot() : CreatureScript("TW_npc_mimiron_bomb_bot") { }

        struct TW_npc_mimiron_bomb_botAI : public ScriptedAI
        {
            TW_npc_mimiron_bomb_botAI(Creature* creature) : ScriptedAI(creature) { }

            Unit* SelectPlayerTargetInRange(float range)
            {
                Player* target = NULL;
                Trinity::AnyPlayerInObjectRangeCheck u_check(me, range, true);
                Trinity::PlayerSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(me, target, u_check);
                me->VisitNearbyObject(range, searcher);
                return target;
            }

            void Reset()
            {
                _despawn = false;
                if (Unit* target = SelectPlayerTargetInRange(500.0f))
                {
                    me->AddThreat(target, 999999.0f);
                    AttackStart(target);
                }
            }

            void JustDied(Unit* /*killer*/)
            {
                DoCast(me, SPELL_BOMB_BOT, true);
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    me->GetInstanceScript()->SetData(DATA_CRITERIA_MIMIRON, 1);
            }

            void SpellHitTarget(Unit* target, SpellInfo const* spell) override
            {
                if (target->GetTypeId() == TYPEID_PLAYER && spell->Id == SPELL_BOMB_BOT)
                    if (Creature* Mimiron = me->FindNearestCreature(NPC_MIMIRON, 200.0f))
                        Mimiron->AI()->SetData(DATA_SET_US_UP_THE_BOMB_BOT, false);
            }

            void UpdateAI(uint32 /*diff*/)
            {
                if (!UpdateVictim())
                    return;

                if (!_despawn && me->IsWithinMeleeRange(me->GetVictim()))
                {
                    _despawn = true;
                    DoCast(me, SPELL_BOMB_BOT, true);
                    me->DespawnOrUnsummon(500);
                }
            }

        private:
            bool _despawn;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new TW_npc_mimiron_bomb_botAI(creature);
        }
};

/*---------------------------------------------*
 *           DO NOT PUSH THIS BUTTON!          *
 *---------------------------------------------*/

class TW_go_not_push_button : public GameObjectScript
{
public:
    TW_go_not_push_button() : GameObjectScript("TW_go_not_push_button") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        InstanceScript* _instance = go->GetInstanceScript();

        if (!_instance)
            return false;

        if ((_instance->GetBossState(BOSS_MIMIRON) != IN_PROGRESS || _instance->GetBossState(BOSS_MIMIRON) != DONE) && player)
        if (Creature* mimiron = ObjectAccessor::GetCreature((*player), _instance->GetData64(BOSS_MIMIRON)))
                mimiron->AI()->DoAction(DO_ACTIVATE_HARD_MODE);

        go->UseDoorOrButton();

        return true;
    }
};

class TW_npc_mimiron_flame_trigger : public CreatureScript
{
    public:
        TW_npc_mimiron_flame_trigger() : CreatureScript("TW_npc_mimiron_flame_trigger") { }

        struct TW_npc_mimiron_flame_triggerAI : public ScriptedAI
        {
            TW_npc_mimiron_flame_triggerAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
                _flameTimer = 2000;
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
                me->SetInCombatWithZone();
            }

            void SpellHit(Unit* /*caster*/, SpellInfo const* spell)
            {
                switch (spell->Id)
                {
                    case SPELL_FLAME_SUPPRESSANT:
                    case SPELL_FLAME_SUPPRESSANT_VX001:
                    case SPELL_FROST_BOMB_EXPLOSION_10:
                    case SPELL_FROST_BOMB_EXPLOSION_25:
                    case SPELL_WATER_SPRAY:
                        _flameTimer = 1000;
                        me->DespawnOrUnsummon(500);
                        break;
                    default:
                        break;
                }
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    me->GetInstanceScript()->SetData(DATA_CRITERIA_MIMIRON, 1);
            }

            void JustSummoned(Creature* /*summon*/)
            {
                if (Creature* mimiron = ObjectAccessor::GetCreature(*me, _instance ? _instance->GetData64(BOSS_MIMIRON) : 0))
                    mimiron->AI()->DoAction(DO_INCREASE_FLAME_COUNT);
            }

            void UpdateAI(uint32 diff) override
            {
                if (_flameTimer <= diff)
                {
                    // check if flame cap is reached
                    if (Creature* mimiron = ObjectAccessor::GetCreature(*me, _instance ? _instance->GetData64(BOSS_MIMIRON) : 0))
                        if (mimiron->AI()->GetData(DATA_FLAME_COUNT) >= FLAME_CAP)
                        {
                            me->DespawnOrUnsummon();
                            return;
                        }

                    DoZoneInCombat(me, 100.0f);

                    if (Player* nearest = me->SelectNearestPlayer(100.0f))
                    {
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MoveFollow(nearest, 0.0f, 0.0f);
                    }

                    me->SummonCreature(NPC_FLAME_SPREAD, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
                    _flameTimer = 4000;
                }
                else
                    _flameTimer -= diff;
            }

        private:
            InstanceScript* _instance;
            uint32 _flameTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new TW_npc_mimiron_flame_triggerAI(creature);
        }
};

class TW_npc_mimiron_flame_spread : public CreatureScript
{
    public:
        TW_npc_mimiron_flame_spread() : CreatureScript("TW_npc_mimiron_flame_spread") { }

        struct TW_npc_mimiron_flame_spreadAI : public ScriptedAI
        {
            TW_npc_mimiron_flame_spreadAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED | UNIT_FLAG_DISABLE_MOVE);
                me->SetReactState(REACT_PASSIVE);
                DoCast(me, SPELL_FLAME, true);
            }

            void SpellHit(Unit* /*caster*/, SpellInfo const* spell)
            {
                switch (spell->Id)
                {
                    case SPELL_FLAME_SUPPRESSANT:
                    case SPELL_FLAME_SUPPRESSANT_VX001:
                    case SPELL_FROST_BOMB_EXPLOSION_10:
                    case SPELL_FROST_BOMB_EXPLOSION_25:
                    case SPELL_WATER_SPRAY:
                        if (Creature* mimiron = ObjectAccessor::GetCreature(*me, _instance ? _instance->GetData64(BOSS_MIMIRON) : 0))
                            mimiron->AI()->DoAction(DO_DECREASE_FLAME_COUNT);
                        me->DespawnOrUnsummon(500);
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 /*diff*/)
            {
                if (_instance && _instance->GetBossState(BOSS_MIMIRON) != IN_PROGRESS)
                    me->DespawnOrUnsummon();
            }

        private:
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new TW_npc_mimiron_flame_spreadAI(creature);
        }
};

class TW_npc_frost_bomb : public CreatureScript
{
    public:
        TW_npc_frost_bomb() : CreatureScript("TW_npc_frost_bomb") { }

        struct TW_npc_frost_bombAI : public ScriptedAI
        {
            TW_npc_frost_bombAI(Creature* creature) : ScriptedAI(creature)
            {
                me->AddUnitState(UNIT_STATE_ROOT);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_NOT_SELECTABLE);
                DoCast(me, SPELL_FROST_BOMB_VISUAL, true);
                _frostTimer = 10000;
            }

            void UpdateAI(uint32 diff) override
            {
                if (_frostTimer <= diff)
                {
                    DoCast(me, RAID_MODE(SPELL_FROST_BOMB_EXPLOSION_10, SPELL_FROST_BOMB_EXPLOSION_25), true);
                    _frostTimer = 10000;
                }
                else _frostTimer -= diff;
            }

        private:
            uint32 _frostTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new TW_npc_frost_bombAI(creature);
        }
};

class TW_achievement_firefighter : public AchievementCriteriaScript
{
    public:
        TW_achievement_firefighter() : AchievementCriteriaScript("TW_achievement_firefighter")
        {
        }

        bool OnCheck(Player* player, Unit* /*target*/)
        {
            if (!player)
                return false;

            if (InstanceScript* instance = player->GetInstanceScript())
                if (Creature* mimiron = ObjectAccessor::GetCreature(*player, instance->GetData64(BOSS_MIMIRON)))
                    if (mimiron->AI()->GetData(DATA_GET_HARD_MODE))
                        return true;

            return false;
        }
};

class TW_achievement_set_us_up_the_bomb : public AchievementCriteriaScript
{
    public:
        uint32 spell_id;

        TW_achievement_set_us_up_the_bomb(const char* name, uint32 spell_entry) : AchievementCriteriaScript(name)
        {
            spell_id = spell_entry;
        }

        bool OnCheck(Player* player, Unit* /*target*/) override
        {
            if (!player)
                return false;

            if (InstanceScript* instance = player->GetInstanceScript())
                if (Creature* mimiron = ObjectAccessor::GetCreature(*player, instance->GetData64(BOSS_MIMIRON)))
                {
                    if (spell_id == SPELL_BOMB_BOT && mimiron->AI()->GetData(DATA_SET_US_UP_THE_BOMB_BOT))
                        return true;

                    if (spell_id == SPELL_ROCKET_STRIKE_DMG && mimiron->AI()->GetData(DATA_SET_US_UP_THE_BOMB_ROCKET))
                        return true;

                    if (spell_id == SPELL_EXPLOSION && mimiron->AI()->GetData(DATA_SET_US_UP_THE_BOMB_MINE))
                        return true;
                }


            return false;
        }
};

class TW_go_call_tram : public GameObjectScript
{
public:
    TW_go_call_tram() : GameObjectScript("TW_go_call_tram") { }

    bool OnGossipHello(Player* /*pPlayer*/, GameObject* pGo)
    {
        InstanceScript* pInstance = pGo->GetInstanceScript();

        if (!pInstance)
            return false;

        switch (pGo->GetEntry())
        {
            case 194914:
            case 194438:
                pInstance->SetData(DATA_CALL_TRAM, 0);
                break;
            case 194912:
            case 194437:
                pInstance->SetData(DATA_CALL_TRAM, 1);
                break;
        }
        return true;
    }
};

void AddSC_TW_boss_mimiron()
{
    new TW_boss_mimiron();
    new TW_boss_leviathan_mk();
    new TW_boss_leviathan_mk_turret();
    new TW_npc_proximity_mine();
    new TW_boss_vx_001();
    new TW_npc_rocket_strike();
    new TW_spell_rapid_burst();
    new TW_boss_aerial_unit();
    new TW_npc_magnetic_core();
    new TW_npc_assault_bot();
    new TW_npc_emergency_bot();
    new TW_npc_mimiron_bomb_bot();
    new TW_go_not_push_button();
    new TW_npc_mimiron_flame_trigger();
    new TW_npc_mimiron_flame_spread();
    new TW_npc_frost_bomb();
    new TW_achievement_firefighter();
    new TW_go_call_tram();
    new TW_achievement_set_us_up_the_bomb("TW_achievement_set_us_up_the_bomb_bot", SPELL_BOMB_BOT);
    new TW_achievement_set_us_up_the_bomb("TW_achievement_set_us_up_the_bomb_rocket", SPELL_ROCKET_STRIKE_DMG);
    new TW_achievement_set_us_up_the_bomb("TW_achievement_set_us_up_the_bomb_mine", SPELL_EXPLOSION);
}
