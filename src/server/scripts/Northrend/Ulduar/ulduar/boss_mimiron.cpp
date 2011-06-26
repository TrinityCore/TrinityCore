/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
#include "ulduar.h"
#include "Unit.h"

enum Yells
{
    SAY_AGGRO                                   = -1603240,
    SAY_HARDMODE_ON                             = -1603241,
    SAY_MKII_ACTIVATE                           = -1603242,
    SAY_MKII_SLAY_1                             = -1603243,
    SAY_MKII_SLAY_2                             = -1603244,
    SAY_MKII_DEATH                              = -1603245,
    SAY_VX001_ACTIVATE                          = -1603246,
    SAY_VX001_SLAY_1                            = -1603247,
    SAY_VX001_SLAY_2                            = -1603248,
    SAY_VX001_DEATH                             = -1603249,
    SAY_AERIAL_ACTIVATE                         = -1603250,
    SAY_AERIAL_SLAY_1                           = -1603251,
    SAY_AERIAL_SLAY_2                           = -1603252,
    SAY_AERIAL_DEATH                            = -1603253,
    SAY_V07TRON_ACTIVATE                        = -1603254,
    SAY_V07TRON_SLAY_1                          = -1603255,
    SAY_V07TRON_SLAY_2                          = -1603256,
    SAY_V07TRON_DEATH                           = -1603257,
    SAY_BERSERK                                 = -1603258,
    SAY_YS_HELP                                 = -1603259
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
    SPELL_EMERGENCY_MODE                        = 64582,
    SPELL_FLAME_SUPPRESSANT                     = 64570,
    SPELL_FLAME_SUPPRESSANT_VX001               = 65192,
    SPELL_FLAME                                 = 64561,
    SPELL_FROST_BOMB                            = 64624,
    SPELL_FROST_BOMB_EXPLOSION_10               = 64626,
    SPELL_FROST_BOMB_EXPLOSION_25               = 65333,
    SPELL_WATER_SPRAY                           = 64619,
    SPELL_SIREN                                 = 64616,

    // NPCs
    SPELL_BOMB_BOT                              = 63801  // should be 63767
};

enum Events
{
    // Leviathan MK II
    EVENT_NONE,
    EVENT_PROXIMITY_MINE,
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
    DO_START_ENCOUNTER                          = 1,
    DO_ACTIVATE_VX001                           = 2,
    DO_START_VX001                              = 3,
    DO_ACTIVATE_AERIAL                          = 4,
    DO_START_AERIAL                             = 5,
    DO_DISABLE_AERIAL                           = 6,
    DO_ACTIVATE_V0L7R0N                         = 7,
    DO_LEVIATHAN_ASSEMBLED                      = 8,
    DO_VX001_ASSEMBLED                          = 9,
    DO_AERIAL_ASSEMBLED                         = 10,
    DO_ACTIVATE_DEATH_TIMER                     = 11,
    DO_ENTER_ENRAGE                             = 12,
    DO_ACTIVATE_HARD_MODE                       = 13,
    DO_DESPAWN_SUMMONS                          = 14,
    DATA_GET_HARD_MODE                          = 15
};

enum Npcs
{
    //NPC_VX_001                                  = 33651,
    //NPC_AERIAL_UNIT                             = 33670,
    NPC_ROCKET                                  = 34050,
    NPC_BURST_TARGET                            = 34211,
    NPC_JUNK_BOT                                = 33855,
    NPC_ASSAULT_BOT                             = 34057,
    NPC_BOOM_BOT                                = 33836,
    NPC_EMERGENCY_BOT                           = 34147,
    NPC_FLAME                                   = 34363,
    NPC_FLAME_SPREAD                            = 34121,
    NPC_FROST_BOMB                              = 34149,
    NPC_MKII_TURRET                             = 34071,
};

// Achievements
#define ACHIEVEMENT_FIREFIGHTER                 RAID_MODE(3180, 3189)
#define ACHIEVEMENT_NOT_SO_FRIENDLY_FIRE        RAID_MODE(3138, 2995)
#define ACHIEVEMENT_SET_UP_US_THE_BOMB          RAID_MODE(2989, 3237) // TODO

enum MimironChests
{
    CACHE_OF_INNOVATION_10                      = 194789,
    CACHE_OF_INNOVATION_HARDMODE_10             = 194957,
    CACHE_OF_INNOVATION_25                      = 194956,
    CACHE_OF_INNOVATION_HARDMODE_25             = 194958
};

const Position SummonPos[9] =
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

/*---------------------------------------------*
 *                   Mimiron                   *
 *---------------------------------------------*/

class boss_mimiron : public CreatureScript
{
public:
    boss_mimiron() : CreatureScript("boss_mimiron") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_mimironAI(creature);
    }

    struct boss_mimironAI : public BossAI
    {
        boss_mimironAI(Creature* creature) : BossAI(creature, TYPE_MIMIRON)
        {
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_ROCKET_STRIKE_DMG, true);
            me->SetReactState(REACT_PASSIVE);
        }

        uint32 uiPhase_timer;
        uint32 uiStep;
        uint32 EnrageTimer;
        uint32 FlameTimer;
        uint32 uiBotTimer;
        bool MimironHardMode;
        bool checkBotAlive;
        bool Enraged;

        Phases phase;

        void DespawnCreatures(uint32 entry, float distance, bool discs = false)
        {
            std::list<Creature*> m_pCreatures;
            GetCreatureListWithEntryInGrid(m_pCreatures, me, entry, distance);

            if (m_pCreatures.empty())
                return;

            for(std::list<Creature*>::iterator iter = m_pCreatures.begin(); iter != m_pCreatures.end(); ++iter)
                (*iter)->ForcedDespawn();
        }

        void Reset()
        {
            if (me->getFaction() == 35)
                return;

            _Reset();
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_USESTANDING);
            me->SetVisible(true);
            me->ExitVehicle();
            me->GetMotionMaster()->MoveTargetedHome();

            instance->SetData(DATA_MIMIRON_ELEVATOR, GO_STATE_ACTIVE);

            if (Creature* aerial = me->GetCreature(*me, instance->GetData64(DATA_AERIAL_UNIT)))
                aerial->AI()->DoAction(DO_DESPAWN_SUMMONS);

            for (uint8 data = DATA_LEVIATHAN_MK_II; data <= DATA_AERIAL_UNIT; ++data)
                if (Creature* creature = me->GetCreature(*me, instance->GetData64(data)))
                    if (creature->isAlive())
                    {
                        creature->ExitVehicle();
                        creature->AI()->EnterEvadeMode();
                    }

            phase = PHASE_NULL;
            uiStep = 0;
            uiPhase_timer = -1;
            uiBotTimer = 0;
            MimironHardMode = false;
            checkBotAlive = true;
            Enraged = false;
            DespawnCreatures(34362, 100);
            DespawnCreatures(NPC_ROCKET, 100);

            if (GameObject* go = me->FindNearestGameObject(GO_BIG_RED_BUTTON, 200))
            {
                go->SetGoState(GO_STATE_READY);
                go->SetLootState(GO_JUST_DEACTIVATED);
                go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
            }
        }

        void EndEncounter()
        {
            DoScriptText(SAY_V07TRON_DEATH, me);

            me->setFaction(35);

            if (instance)
            {
                instance->SetBossState(TYPE_MIMIRON, DONE);
                if (MimironHardMode)
                {
                    instance->DoCompleteAchievement(ACHIEVEMENT_FIREFIGHTER);
                    me->SummonGameObject(RAID_MODE(CACHE_OF_INNOVATION_HARDMODE_10, CACHE_OF_INNOVATION_HARDMODE_25), 2744.65f, 2569.46f, 364.314f, 3.14159f, 0, 0, 0.7f, 0.7f, 604800);
                }
                else
                {
                    me->SummonGameObject(RAID_MODE(CACHE_OF_INNOVATION_10, CACHE_OF_INNOVATION_25), 2744.65f, 2569.46f, 364.314f, 3.14159f, 0, 0, 0.7f, 0.7f, 604800);
                }

                instance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE, NPC_LEVIATHAN_MKII, 1);
            }

            EnterEvadeMode();
            me->ForcedDespawn(5000);
        }

        void EnterCombat(Unit * /*who*/)
        {
            _EnterCombat();
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
            phase = PHASE_INTRO;
            FlameTimer = 30000;
            if (MimironHardMode)
                EnrageTimer = 8*60*1000; // Enrage in 8 min
            else
                EnrageTimer = 15*60*1000; // Enrage in 15 min
            JumpToNextStep(100);

            if (GameObject* go = me->FindNearestGameObject(GO_BIG_RED_BUTTON, 200))
                go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
        }

        void JumpToNextStep(uint32 uiTimer)
        {
            uiPhase_timer = uiTimer;
            ++uiStep;
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            _DoAggroPulse(diff);

            if (EnrageTimer <= diff && !Enraged)
            {
                DoScriptText(SAY_BERSERK, me);
                for (uint8 data = DATA_LEVIATHAN_MK_II; data <= DATA_AERIAL_UNIT; ++data)
                    if (Creature* creature = me->GetCreature(*me, instance->GetData64(data)))
                        creature->AI()->DoAction(DO_ENTER_ENRAGE);

                Enraged = true;
            }
            else EnrageTimer -= diff;

            if (MimironHardMode)
                if (FlameTimer <= diff)
                {
                    for (uint8 i = 0; i < 3; ++i)
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            if (Creature* Flame = me->SummonCreature(NPC_FLAME, target->GetPositionX() + irand(-6,6), target->GetPositionY() + irand(-6,6), target->GetPositionZ(), 0, TEMPSUMMON_MANUAL_DESPAWN))
                                Flame->AI()->AttackStart(target);
                    FlameTimer = 30000;
                }
                else FlameTimer -= diff;

            // All sections need to die within 10 seconds, else they respawn
            if (checkBotAlive)
                uiBotTimer = 0;
            else
            {
                uiBotTimer += diff;
                if (uiBotTimer > 10000)
                {
                    if (Creature* Leviathan = me->GetCreature(*me, instance->GetData64(DATA_LEVIATHAN_MK_II)))
                        Leviathan->AI()->DoAction(DO_LEVIATHAN_ASSEMBLED);
                    if (Creature* VX_001 = me->GetCreature(*me, instance->GetData64(DATA_VX_001)))
                        VX_001->AI()->DoAction(DO_VX001_ASSEMBLED);
                    if (Creature* AerialUnit = me->GetCreature(*me, instance->GetData64(DATA_AERIAL_UNIT)))
                        AerialUnit->AI()->DoAction(DO_AERIAL_ASSEMBLED);

                    checkBotAlive = true;
                }
                else
                {
                    if (Creature* Leviathan = me->GetCreature(*me, instance->GetData64(DATA_LEVIATHAN_MK_II)))
                        if (Creature* VX_001 = me->GetCreature(*me, instance->GetData64(DATA_VX_001)))
                            if (Creature* AerialUnit = me->GetCreature(*me, instance->GetData64(DATA_AERIAL_UNIT)))
                                if (Leviathan->getStandState() == UNIT_STAND_STATE_DEAD)
                                    if (VX_001->getStandState() == UNIT_STAND_STATE_DEAD)
                                        if (AerialUnit->getStandState() == UNIT_STAND_STATE_DEAD)
                                        {
                                            Leviathan->DisappearAndDie();
                                            VX_001->DisappearAndDie();
                                            AerialUnit->DisappearAndDie();
                                            DespawnCreatures(NPC_ROCKET, 100);
                                            //me->Kill(me, false);
                                            me->ExitVehicle();
                                            EndEncounter();
                                            checkBotAlive = true;
                                        }
                }
            }

            if (phase == PHASE_INTRO)
            {
                if (uiPhase_timer <= diff)
                {
                    switch (uiStep)
                    {
                        case 1:
                            if (MimironHardMode)
                                DoScriptText(SAY_HARDMODE_ON, me);
                            else
                                DoScriptText(SAY_AGGRO, me);
                            JumpToNextStep(10000);
                            break;
                        case 2:
                            if (instance)
                            {
                                if (Creature* Leviathan = me->GetCreature(*me, instance->GetData64(DATA_LEVIATHAN_MK_II)))
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
                            DoScriptText(SAY_MKII_ACTIVATE, me);
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
                                if (Creature* Leviathan = me->GetCreature(*me, instance->GetData64(DATA_LEVIATHAN_MK_II)))
                                {
                                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_STAND);
                                    Leviathan->AI()->DoAction(DO_START_ENCOUNTER);
                                    phase = PHASE_COMBAT;
                                }
                            }
                            break;
                        default:
                            break;
                    }
                }
                else
                    uiPhase_timer -= diff;
            }

            if (phase == PHASE_VX001_ACTIVATION)
            {
                if (uiPhase_timer <= diff)
                {
                    switch (uiStep)
                    {
                        case 1:
                            DoScriptText(SAY_MKII_DEATH, me);
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
                                    for (uint8 n = 5; n < 7; n++)
                                    {
                                        if (Creature* Rocket = me->SummonCreature(NPC_ROCKET, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_MANUAL_DESPAWN))
                                        {
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
                                if (Creature* VX_001 = me->GetCreature(*me, instance->GetData64(DATA_VX_001)))
                                    me->EnterVehicle(VX_001, 0);
                            }
                            JumpToNextStep(3500);
                            break;
                        case 6:
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_TALK);
                            DoScriptText(SAY_VX001_ACTIVATE, me);
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
                                if (Creature* VX_001 = me->GetCreature(*me, instance->GetData64(DATA_VX_001)))
                                    VX_001->HandleEmoteCommand(EMOTE_ONESHOT_EMERGE);
                            }
                            JumpToNextStep(3500);
                            break;
                        case 9:
                            if (instance)
                                if (Creature* VX_001 = me->GetCreature(*me, instance->GetData64(DATA_VX_001)))
                                {
                                    VX_001->AddAura(SPELL_HOVER, VX_001); // Hover
                                    VX_001->AI()->DoAction(DO_START_VX001);
                                    phase = PHASE_COMBAT;
                                }
                            break;
                        default:
                            break;
                    }
                }
                else
                    uiPhase_timer -= diff;
            }

            if (phase == PHASE_AERIAL_ACTIVATION)
            {
                if (uiPhase_timer <= diff)
                {
                    switch (uiStep)
                    {
                        case 1:
                            me->ChangeSeat(4);
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_STAND);
                            JumpToNextStep(2500);
                            break;
                        case 2:
                            DoScriptText(SAY_VX001_DEATH, me);
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
                            if (Creature* AerialUnit = me->GetCreature(*me, instance->GetData64(DATA_AERIAL_UNIT)))
                                 me->EnterVehicle(AerialUnit, 0);
                            JumpToNextStep(2000);
                            break;
                        case 5:
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_TALK);
                            DoScriptText(SAY_AERIAL_ACTIVATE, me);
                            JumpToNextStep(8000);
                            break;
                        case 6:
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_STAND);
                            //me->SetVisible(false);
                            if (instance)
                            {
                                if (Creature* AerialUnit = me->GetCreature(*me, instance->GetData64(DATA_AERIAL_UNIT)))
                                {
                                    AerialUnit->AI()->DoAction(DO_START_AERIAL);
                                    phase = PHASE_COMBAT;
                                }
                            }
                            break;
                        default:
                            break;
                    }
                }
                else
                    uiPhase_timer -= diff;
            }

            if (phase == PHASE_V0L7R0N_ACTIVATION)
            {
                if (uiPhase_timer <= diff)
                {
                    switch (uiStep)
                    {
                        case 1:
                            if (instance)
                            {
                                //me->SetVisible(true);
                                if (Creature* Leviathan = me->GetCreature(*me, instance->GetData64(DATA_LEVIATHAN_MK_II)))
                                   Leviathan->GetMotionMaster()->MovePoint(0, 2744.65f, 2569.46f, 364.397f);
                                if (Creature* VX_001 = me->GetCreature(*me, instance->GetData64(DATA_VX_001)))
                                {
                                    me->EnterVehicle(VX_001, 1);
                                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_STAND);
                                    DoScriptText(SAY_AERIAL_DEATH, me);
                                }
                            }
                            JumpToNextStep(5000);
                            break;
                        case 2:
                            if (instance)
                                if (Creature* VX_001 = me->GetCreature(*me, instance->GetData64(DATA_VX_001)))
                                    if (Creature* Leviathan = me->GetCreature(*me, instance->GetData64(DATA_LEVIATHAN_MK_II)))
                                    {
                                        VX_001->SetStandState(UNIT_STAND_STATE_STAND);
                                        VX_001->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_CUSTOM_SPELL_01);
                                        VX_001->EnterVehicle(Leviathan, 7);
                                    }
                            JumpToNextStep(2000);
                            break;
                        case 3:
                            if (instance)
                                if (Creature* VX_001 = me->GetCreature(*me, instance->GetData64(DATA_VX_001)))
                                    if (Creature* AerialUnit = me->GetCreature(*me, instance->GetData64(DATA_AERIAL_UNIT)))
                                    {
                                        AerialUnit->SetFlying(false);
                                        AerialUnit->EnterVehicle(VX_001, 3);
                                        DoScriptText(SAY_V07TRON_ACTIVATE, me);
                                    }
                            JumpToNextStep(10000);
                            break;
                        case 4:
                            if (instance)
                            {
                                if (Creature* Leviathan = me->GetCreature(*me, instance->GetData64(DATA_LEVIATHAN_MK_II)))
                                    Leviathan->AI()->DoAction(DO_LEVIATHAN_ASSEMBLED);
                                if (Creature* VX_001 = me->GetCreature(*me, instance->GetData64(DATA_VX_001)))
                                    VX_001->AI()->DoAction(DO_VX001_ASSEMBLED);
                                if (Creature* AerialUnit = me->GetCreature(*me, instance->GetData64(DATA_AERIAL_UNIT)))
                                    AerialUnit->AI()->DoAction(DO_AERIAL_ASSEMBLED);
                                phase = PHASE_COMBAT;
                            }
                            break;
                        default:
                            break;
                    }
                }
                else
                    uiPhase_timer -= diff;
            }
        }

        uint32 GetData(uint32 type)
        {
            if (type == DATA_GET_HARD_MODE)
                return MimironHardMode ? 1 : 0;
            return 0;
        }

        void DoAction(const int32 action)
        {
            switch (action)
            {
                case DO_ACTIVATE_VX001:
                    phase = PHASE_VX001_ACTIVATION;
                    uiStep = 0;
                    uiPhase_timer = -1;
                    JumpToNextStep(100);
                    break;
                case DO_ACTIVATE_AERIAL:
                    phase = PHASE_AERIAL_ACTIVATION;
                    uiStep = 0;
                    uiPhase_timer = -1;
                    JumpToNextStep(5000);
                    break;
                case DO_ACTIVATE_V0L7R0N:
                    me->SetVisible(true);
                    phase = PHASE_V0L7R0N_ACTIVATION;
                    uiStep = 0;
                    uiPhase_timer = -1;
                    JumpToNextStep(1000);
                    break;
                case DO_ACTIVATE_DEATH_TIMER:
                    checkBotAlive = false;
                    break;
                case DO_ACTIVATE_HARD_MODE:
                    MimironHardMode = true;
                    DoZoneInCombat();
                    break;
            }
        }
    };
};


/*---------------------------------------------*
 *              Leviathan MK II                *
 *---------------------------------------------*/

class boss_leviathan_mk : public CreatureScript
{
public:
    boss_leviathan_mk() : CreatureScript("boss_leviathan_mk") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_leviathan_mkAI(creature);
    }

    struct boss_leviathan_mkAI : public BossAI 
    {
        boss_leviathan_mkAI(Creature* creature) : BossAI(creature, TYPE_MIMIRON), phase(PHASE_NULL), vehicle(creature->GetVehicleKit())
        {
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_ROCKET_STRIKE_DMG, true);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        Vehicle* vehicle;
        Phases phase;
        EventMap events;
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

            if (Creature *turret = CAST_CRE(me->GetVehicleKit()->GetPassenger(3)))
            {
                turret->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
                turret->SetReactState(REACT_PASSIVE);
            }
        }

        void KilledUnit(Unit* /*who*/)
        {
            if (!(rand()%5))
                if (instance)
                    if (Creature* Mimiron = me->GetCreature(*me, instance->GetData64(TYPE_MIMIRON)))
                    {
                        if (phase == PHASE_LEVIATHAN_SOLO)
                            DoScriptText(RAND(SAY_MKII_SLAY_1, SAY_MKII_SLAY_2), Mimiron);
                        else
                            DoScriptText(RAND(SAY_V07TRON_SLAY_1, SAY_V07TRON_SLAY_2), Mimiron);
                    }
        }

        void DamageTaken(Unit* /*who*/, uint32 &damage)
        {
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1))
                damage = 0;

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
                    if (Creature* Mimiron = me->GetCreature(*me, instance->GetData64(TYPE_MIMIRON)))
                        Mimiron->AI()->DoAction(DO_ACTIVATE_VX001);
                    if (Creature* turret = CAST_CRE(me->GetVehicleKit()->GetPassenger(3)))
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
                    if (Creature* Mimiron = me->GetCreature(*me, instance->GetData64(TYPE_MIMIRON)))
                        Mimiron->AI()->DoAction(DO_ACTIVATE_DEATH_TIMER);
                }
        }

        void EnterCombat(Unit* /*who*/)
        {
            if (Creature* Mimiron = me->GetCreature(*me, instance ? instance->GetData64(TYPE_MIMIRON) : 0))
                if (Mimiron->AI()->GetData(DATA_GET_HARD_MODE) == 1)
                    MimironHardMode = true;

            if (MimironHardMode)
            {
                DoCast(me, SPELL_EMERGENCY_MODE);
                events.ScheduleEvent(EVENT_FLAME_SUPPRESSANT, 60000, 0, PHASE_LEVIATHAN_SOLO);
            }

            if (Creature* turret = CAST_CRE(me->GetVehicleKit()->GetPassenger(3)))
            {
                turret->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
                turret->SetReactState(REACT_AGGRESSIVE);
                turret->AI()->DoZoneInCombat();
            }

            events.ScheduleEvent(EVENT_PROXIMITY_MINE, 1000);
            events.ScheduleEvent(EVENT_PLASMA_BLAST, 10000, 0, PHASE_LEVIATHAN_SOLO);
        }

        void DoAction(const int32 action)
        {
            switch(action)
            {
                case DO_START_ENCOUNTER:
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_OOC_NOT_ATTACKABLE);
                    me->SetReactState(REACT_AGGRESSIVE);
                    phase = PHASE_LEVIATHAN_SOLO;
                    events.SetPhase(PHASE_LEVIATHAN_SOLO);
                    DoZoneInCombat();
                    break;
                case DO_LEVIATHAN_ASSEMBLED:
                    if (MimironHardMode)
                        DoCast(me, SPELL_EMERGENCY_MODE);
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

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            _DoAggroPulse(diff);
            events.Update(diff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            if (phase == PHASE_LEVIATHAN_SOLO || phase == PHASE_LEVIATHAN_ASSEMBLED)
            {
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        case EVENT_PROXIMITY_MINE:
                            for (int i = 0; i < 10; i++)
                                DoCast(SPELL_MINES_SPAWN);
                            DoCast(SPELL_PROXIMITY_MINES);
                            events.RescheduleEvent(EVENT_PROXIMITY_MINE, 35000);
                            break;
                        case EVENT_PLASMA_BLAST:
                            me->MonsterTextEmote(EMOTE_LEVIATHAN, 0, true);
                            DoCast(SPELL_PLASMA_BLAST);
                            events.RescheduleEvent(EVENT_PLASMA_BLAST, urand(30000, 35000), 0, PHASE_LEVIATHAN_SOLO);
                            events.RescheduleEvent(EVENT_SHOCK_BLAST, urand(6000, 10000));
                            break;
                        case EVENT_SHOCK_BLAST:
                            DoCastAOE(SPELL_SHOCK_BLAST);
                            events.RescheduleEvent(EVENT_SHOCK_BLAST, 35000);
                            break;
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

class boss_leviathan_mk_turret : public CreatureScript
{
    public:
        boss_leviathan_mk_turret() : CreatureScript("boss_leviathan_mk_turret") { }

        struct boss_leviathan_mk_turretAI : public ScriptedAI
        {
            boss_leviathan_mk_turretAI(Creature* c) : ScriptedAI(c) 
            {
                SetImmuneToPushPullEffects(true);
                me->SetReactState(REACT_PASSIVE);
                _NapalmShell = urand(4000, 8000);
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
                        if (Player* player = itr->getSource())
                        {
                            if (player->isDead() || player->isGameMaster())
                                continue;

                            float Distance = player->GetDistance(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
                            if (Distance < 15.0f || Distance > 100.0f)
                                continue;

                            playerList.push_back(player);
                        }
                    }

                    if (playerList.empty())
                        return NULL;

                    std::list<Player*>::const_iterator itr = playerList.begin();
                    std::advance(itr, urand(0, playerList.size() - 1));
                    return *itr;
                }
                else
                    return NULL;
            }
            
            void UpdateAI(uint32 const diff)
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
            return new boss_leviathan_mk_turretAI(creature);
        }
};

class npc_proximity_mine : public CreatureScript
{
public:
    npc_proximity_mine() : CreatureScript("npc_proximity_mine") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_proximity_mineAI(creature);
    }

    struct npc_proximity_mineAI : public Scripted_NoMovementAI
    {
        npc_proximity_mineAI(Creature* creature) : Scripted_NoMovementAI(creature)
        {
           me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);
           uiBoomTimer = 35000;
           Boom = false;
        }

        uint32 uiBoomTimer;
        bool Boom;

        void MoveInLineOfSight(Unit* who)
        {
            if (!Boom && me->IsWithinDistInMap(who, 0.5f) && who->ToPlayer() && !who->ToPlayer()->isGameMaster())
            {
                DoCastAOE(SPELL_EXPLOSION);
                me->ForcedDespawn(1000);
                Boom = true;
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (uiBoomTimer <= diff)
            {
                if (!Boom)
                {
                    DoCastAOE(SPELL_EXPLOSION);
                    me->ForcedDespawn(1000);
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

class boss_vx_001 : public CreatureScript
{
public:
    boss_vx_001() : CreatureScript("boss_vx_001") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_vx_001AI(creature);
    }

    struct boss_vx_001AI : public BossAI
    {
        boss_vx_001AI(Creature* creature) : BossAI(creature, TYPE_MIMIRON), phase(PHASE_NULL)
        {
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_ROCKET_STRIKE_DMG, true);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        Phases phase;
        EventMap events;
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

        void KilledUnit(Unit * /*who*/)
        {
            if (!(rand()%5))
                if (instance)
                    if (Creature* Mimiron = me->GetCreature(*me, instance->GetData64(TYPE_MIMIRON)))
                    {
                        if (phase == PHASE_VX001_SOLO)
                            DoScriptText(RAND(SAY_VX001_SLAY_1, SAY_VX001_SLAY_2), Mimiron);
                        else
                            DoScriptText(RAND(SAY_V07TRON_SLAY_1, SAY_V07TRON_SLAY_2), Mimiron);
                    }
        }

        void EnterCombat(Unit* /*who*/)
        {
            if (Creature* Mimiron = me->GetCreature(*me, instance ? instance->GetData64(TYPE_MIMIRON) : 0))
                if (Mimiron->AI()->GetData(DATA_GET_HARD_MODE) == 1)
                    MimironHardMode = true;

            if (MimironHardMode)
            {
                DoCast(me, SPELL_EMERGENCY_MODE);
                events.ScheduleEvent(EVENT_FROST_BOMB, 15000);
                events.ScheduleEvent(EVENT_FLAME_SUPPRESSANT_VX001, 10000);
            }

            events.ScheduleEvent(EVENT_RAPID_BURST, 2500, 0, PHASE_VX001_SOLO);
            events.ScheduleEvent(EVENT_LASER_BARRAGE, urand(35000, 40000));
            events.ScheduleEvent(EVENT_ROCKET_STRIKE, 20000);
            events.ScheduleEvent(EVENT_HEAT_WAVE, urand(8000, 10000), 0, PHASE_VX001_SOLO);
            events.ScheduleEvent(EVENT_HAND_PULSE, 10000, 0, PHASE_VX001_ASSEMBLED);
        }

        void DoAction(const int32 action)
        {
            switch (action)
            {
                case DO_START_VX001:
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_OOC_NOT_ATTACKABLE);
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
                    events.RescheduleEvent(EVENT_LASER_BARRAGE, urand(35000, 40000));
                    events.RescheduleEvent(EVENT_ROCKET_STRIKE, 20000);
                    events.RescheduleEvent(EVENT_HAND_PULSE, 15000, 0, PHASE_VX001_ASSEMBLED);
                    if (MimironHardMode)
                    {
                        DoCast(me, SPELL_EMERGENCY_MODE);
                        events.RescheduleEvent(EVENT_FROST_BOMB, 15000);
                    }
                    break;
                case DO_ENTER_ENRAGE:
                    DoCast(me, SPELL_BERSERK, true);
                    break;
            }
        }

        void DamageTaken(Unit * /*who*/, uint32 &damage)
        {
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1))
                damage = 0;

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
                    if (Creature* Mimiron = me->GetCreature(*me, instance->GetData64(TYPE_MIMIRON)))
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
                    if (Creature* Mimiron = me->GetCreature(*me, instance->GetData64(TYPE_MIMIRON)))
                        Mimiron->AI()->DoAction(DO_ACTIVATE_DEATH_TIMER);
                }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (spinning)
            {
                if (spinTimer <= diff)
                {
                    if (Creature* leviathan = me->GetVehicleCreatureBase())
                    {
                        float orient = leviathan->GetOrientation();
                        leviathan->SetFacing(orient + (direction ? M_PI/60 : -M_PI/60));
                        me->SetOrientation(orient + (direction ? M_PI/60 : -M_PI/60));
                    }
                    else
                    {
                        float orient = me->GetOrientation();
                        me->SetFacing(orient + (direction ? M_PI/60 : -M_PI/60));
                    }
                    spinTimer = 250;
                }
                else spinTimer -= diff;
            }

            _DoAggroPulse(diff);
            events.Update(diff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
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
                                float orient = leviathan->GetOrientation();
                                leviathan->CastSpell(leviathan, 14821, true); // temporary, to prevent turning
                                leviathan->SetFacing(orient);
                                me->SetOrientation(orient);
                            }
                            direction = urand(0, 1);
                            spinning = true;
                            DoCast(SPELL_SPINNING_UP);
                            events.DelayEvents(14500);
                            events.RescheduleEvent(EVENT_LASER_BARRAGE, 40000);
                            events.RescheduleEvent(EVENT_LASER_BARRAGE_END, 14000);
                            break;
                        case EVENT_LASER_BARRAGE_END:
                            me->SetReactState(REACT_AGGRESSIVE);
                            AttackStart(me->getVictim());
                            spinning = false;
                            break;
                        case EVENT_ROCKET_STRIKE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                if (Creature* missile = CAST_CRE(me->GetVehicleKit()->GetPassenger(5)))
                                    missile->CastSpell(target, SPELL_ROCKET_STRIKE, true);
                            if (phase == PHASE_VX001_ASSEMBLED)
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                    if (Creature* missile = CAST_CRE(me->GetVehicleKit()->GetPassenger(6)))
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
                            me->SummonCreature(NPC_FROST_BOMB, SummonPos[rand()%9], TEMPSUMMON_TIMED_DESPAWN, 11000);
                            events.RescheduleEvent(EVENT_FROST_BOMB, 45000);
                            break;
                        case EVENT_FLAME_SUPPRESSANT_VX001:
                            DoCastAOE(SPELL_FLAME_SUPPRESSANT_VX001);
                            events.RescheduleEvent(EVENT_FLAME_SUPPRESSANT_VX001, 10000);
                            break;
                    }
                }
            }
        }
    };
};

class npc_rocket_strike : public CreatureScript
{
public:
    npc_rocket_strike() : CreatureScript("npc_rocket_strike") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_rocket_strikeAI(creature);
    }

    struct npc_rocket_strikeAI : public Scripted_NoMovementAI
    {
        npc_rocket_strikeAI(Creature* creature) : Scripted_NoMovementAI(creature)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);
            me->ForcedDespawn(10000);
            DoCast(me, SPELL_ROCKET_STRIKE_AURA);
        }
    };
};

class spell_rapid_burst : public SpellScriptLoader
{
    public:
        spell_rapid_burst() : SpellScriptLoader("spell_rapid_burst") { }

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

class boss_aerial_unit : public CreatureScript
{
public:
    boss_aerial_unit() : CreatureScript("boss_aerial_unit") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_aerial_unitAI(creature);
    }

    struct boss_aerial_unitAI : public BossAI
    {
        boss_aerial_unitAI(Creature* creature) : BossAI(creature, TYPE_MIMIRON), phase(PHASE_NULL)
        {
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_ROCKET_STRIKE_DMG, true);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        Phases phase;
        EventMap events;
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
            me->SetFlying(true);
            phase = PHASE_NULL;
            events.SetPhase(PHASE_NULL);
            summons.DespawnAll();
            spawnedAdds = 0;
            MimironHardMode = false;
        }

        void KilledUnit(Unit * /*who*/)
        {
            if (!(rand()%5))
                if (instance)
                    if (Creature* Mimiron = me->GetCreature(*me, instance->GetData64(TYPE_MIMIRON)))
                    {
                        if (phase == PHASE_AERIAL_SOLO)
                            DoScriptText(RAND(SAY_AERIAL_SLAY_1, SAY_AERIAL_SLAY_2), Mimiron);
                        else
                            DoScriptText(RAND(SAY_V07TRON_SLAY_1, SAY_V07TRON_SLAY_2), Mimiron);
                    }
        }

        void EnterCombat(Unit * /*who*/)
        {
            if (Creature* Mimiron = me->GetCreature(*me, instance ? instance->GetData64(TYPE_MIMIRON) : 0))
                if (Mimiron->AI()->GetData(DATA_GET_HARD_MODE) == 1)
                    MimironHardMode = true;

            if (MimironHardMode)
                DoCast(me, SPELL_EMERGENCY_MODE);

            events.ScheduleEvent(EVENT_PLASMA_BALL, 1000);
            events.ScheduleEvent(EVENT_SUMMON_BOTS, 10000, 0, PHASE_AERIAL_SOLO);
        }

        void DoAction(const int32 action)
        {
            switch (action)
            {
                case DO_START_AERIAL:
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_OOC_NOT_ATTACKABLE);
                    me->SetReactState(REACT_AGGRESSIVE);
                    phase = PHASE_AERIAL_SOLO;
                    events.SetPhase(PHASE_AERIAL_SOLO);
                    DoZoneInCombat();
                    break;
                case DO_DISABLE_AERIAL:
                    if (phase != PHASE_AERIAL_SOLO)
                        return;
                    me->CastStop();
                    me->SetReactState(REACT_PASSIVE);
                    me->GetMotionMaster()->Clear(true);
                    DoCast(me, SPELL_MAGNETIC_CORE);
                    DoCast(me, SPELL_MAGNETIC_CORE_VISUAL);
                    if (Creature* MagneticCore = me->GetCreature(*me, instance->GetData64(DATA_MAGNETIC_CORE)))
                        if (MagneticCore->isAlive())
                            me->NearTeleportTo(MagneticCore->GetPositionX(), MagneticCore->GetPositionY(), 368.965f, 0, false);
                    events.RescheduleEvent(EVENT_PLASMA_BALL, 22000, 0, PHASE_AERIAL_SOLO);
                    events.RescheduleEvent(EVENT_SUMMON_BOTS, 24000, 0, PHASE_AERIAL_SOLO);
                    events.ScheduleEvent(EVENT_REACTIVATE_AERIAL, 20000, 0, PHASE_AERIAL_SOLO);
                    break;
                case DO_AERIAL_ASSEMBLED:
                    if (MimironHardMode)
                        DoCast(me, SPELL_EMERGENCY_MODE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->SetHealth(int32(me->GetMaxHealth() / 2));
                    me->SetStandState(UNIT_STAND_STATE_STAND);
                    phase = PHASE_AERIAL_ASSEMBLED;
                    events.SetPhase(PHASE_AERIAL_ASSEMBLED);
                    events.RescheduleEvent(EVENT_PLASMA_BALL, 2000);
                    break;
                case DO_DESPAWN_SUMMONS:
                    summons.DespawnAll();
                    break;
                case DO_ENTER_ENRAGE:
                    DoCast(me, SPELL_BERSERK, true);
                    break;
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            _DoAggroPulse(diff);
            events.Update(diff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            if (phase == PHASE_AERIAL_SOLO || phase == PHASE_AERIAL_ASSEMBLED)
            {
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_PLASMA_BALL:
                            if (phase == PHASE_AERIAL_SOLO && me->getVictim())
                            {
                                float x = me->getVictim()->GetPositionX();
                                float y = me->getVictim()->GetPositionY();
                                float z = me->getVictim()->GetPositionZ();
                                if (me->IsWithinDist3d(x, y, z, 30))
                                {
                                    me->GetMotionMaster()->Initialize();
                                    DoCastVictim(SPELL_PLASMA_BALL);
                                }
                                else me->GetMotionMaster()->MovePoint(0, x, y, 380.04f);
                            }
                            else if (phase == PHASE_AERIAL_ASSEMBLED && me->getVictim())
                            {
                                if (me->getVictim()->IsWithinDist3d(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 30))
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

        void DamageTaken(Unit * /*who*/, uint32 &damage)
        {
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1))
                damage = 0;

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
                    if (Creature* Mimiron = me->GetCreature(*me, instance->GetData64(TYPE_MIMIRON)))
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
                    if (Creature* Mimiron = me->GetCreature(*me, instance->GetData64(TYPE_MIMIRON)))
                        Mimiron->AI()->DoAction(DO_ACTIVATE_DEATH_TIMER);
                }
        }
    };
};

class npc_magnetic_core : public CreatureScript
{
    public:
        npc_magnetic_core() : CreatureScript("npc_magnetic_core") { }

        struct npc_magnetic_coreAI : public Scripted_NoMovementAI
        {
            npc_magnetic_coreAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                DoCast(SPELL_MAGNETIC_CORE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);
                me->ForcedDespawn(21000);
                if (Creature* AerialUnit = me->FindNearestCreature(NPC_AERIAL_COMMAND_UNIT, 20, true))
                    AerialUnit->AI()->DoAction(DO_DISABLE_AERIAL);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_magnetic_coreAI(creature);
        }
};

class npc_assault_bot : public CreatureScript
{
    public:
        npc_assault_bot() : CreatureScript("npc_assault_bot") { }

        struct npc_assault_botAI : public ScriptedAI
        {
            npc_assault_botAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
            }

            void Reset()
            {
                _fieldTimer = urand(4000, 6000);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                if (_fieldTimer <= diff)
                {
                    DoCastVictim(SPELL_MAGNETIC_FIELD);
                    _fieldTimer = urand(15000, 20000);
                }
                else _fieldTimer -= diff;

                DoMeleeAttackIfReady();
            }

            void SpellHit(Unit* /*caster*/, SpellEntry const* spell)
            {
                // Achievement Not-So-Friendly Fire
                if (spell->Id == 63041 && _instance)
                    _instance->DoCompleteAchievement(ACHIEVEMENT_NOT_SO_FRIENDLY_FIRE);
            }

        private:
            InstanceScript* _instance;
            uint32 _fieldTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_assault_botAI(creature);
        }
};

class npc_emergency_bot : public CreatureScript
{
    public:
        npc_emergency_bot() : CreatureScript("npc_emergency_bot") { }

        struct npc_emergency_botAI : public ScriptedAI
        {
            npc_emergency_botAI(Creature* creature) : ScriptedAI(creature)
            {
                me->setFaction(14);
                SetImmuneToPushPullEffects(true);
                me->SetReactState(REACT_PASSIVE);
                me->GetMotionMaster()->MoveRandom(15);
                _sprayTimer = 5000;
            }

            void UpdateAI(uint32 const diff)
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
            return new npc_emergency_botAI(creature);
        }
};

class npc_mimiron_bomb_bot : public CreatureScript
{
    public:
        npc_mimiron_bomb_bot() : CreatureScript("npc_mimiron_bomb_bot") { }

        struct mob_mimiron_bomb_botAI : public ScriptedAI
        {
            mob_mimiron_bomb_botAI(Creature* creature) : ScriptedAI(creature) { }

            Unit* SelectPlayerTargetInRange(float range)
            {
                Player* target = NULL;
                Trinity::AnyPlayerInObjectRangeCheck u_check(me, range);
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

            void UpdateAI(uint32 const /*diff*/)
            {
                if (!UpdateVictim())
                    return;

                if (!_despawn && me->IsWithinMeleeRange(me->getVictim()))
                {
                    _despawn = true;
                    DoCast(me, SPELL_BOMB_BOT, true);
                    me->ForcedDespawn(500);
                }
            }

        private:
            bool _despawn;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_mimiron_bomb_botAI(creature);
        }
};

/*---------------------------------------------*
 *           DO NOT PUSH THIS BUTTON!          *
 *---------------------------------------------*/

class go_not_push_button : public GameObjectScript
{
public:
    go_not_push_button() : GameObjectScript("go_not_push_button") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        InstanceScript* _instance = go->GetInstanceScript();

        if (!_instance)
            return false;

        if ((_instance->GetBossState(TYPE_MIMIRON) != IN_PROGRESS || _instance->GetBossState(TYPE_MIMIRON) != DONE) && player)
            if (Creature* mimiron = player->GetCreature((*player), _instance->GetData64(TYPE_MIMIRON)))
                mimiron->AI()->DoAction(DO_ACTIVATE_HARD_MODE);

        go->UseDoorOrButton();

        return true;
    }
};

class npc_mimiron_flame_trigger : public CreatureScript
{
    public:
        npc_mimiron_flame_trigger() : CreatureScript("npc_mimiron_flame_trigger") { }

        struct npc_mimiron_flame_triggerAI : public ScriptedAI
        {
            npc_mimiron_flame_triggerAI(Creature* creature) : ScriptedAI(creature)
            {
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);
                DoCast(me, SPELL_FLAME, true);
                _flameTimer = 8000;
            }

            void SpellHit(Unit * /*caster*/, const SpellEntry* spell)
            {
                switch (spell->Id)
                {
                    case SPELL_FLAME_SUPPRESSANT:
                    case SPELL_FLAME_SUPPRESSANT_VX001:
                    case SPELL_FROST_BOMB_EXPLOSION_10:
                    case SPELL_FROST_BOMB_EXPLOSION_25:
                    case SPELL_WATER_SPRAY:
                        _flameTimer = 1000;
                        me->ForcedDespawn(500);
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if (_flameTimer <= diff)
                {
                    me->SummonCreature(NPC_FLAME_SPREAD, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
                    _flameTimer = 8000;
                }
                else _flameTimer -= diff;
            }

        private:
            uint32 _flameTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_mimiron_flame_triggerAI(creature);
        }
};

class npc_mimiron_flame_spread : public CreatureScript
{
    public:
        npc_mimiron_flame_spread() : CreatureScript("npc_mimiron_flame_spread") { }

        struct npc_mimiron_flame_spreadAI : public ScriptedAI
        {
            npc_mimiron_flame_spreadAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED | UNIT_FLAG_DISABLE_MOVE);
                me->SetReactState(REACT_PASSIVE);
                DoCast(me, SPELL_FLAME, true);
            }

            void SpellHit(Unit * /*caster*/, const SpellEntry* spell)
            {
                switch (spell->Id)
                {
                    case SPELL_FLAME_SUPPRESSANT:
                    case SPELL_FLAME_SUPPRESSANT_VX001:
                    case SPELL_FROST_BOMB_EXPLOSION_10:
                    case SPELL_FROST_BOMB_EXPLOSION_25:
                    case SPELL_WATER_SPRAY:
                        me->ForcedDespawn(500);
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 const /*diff*/)
            {
                if (_instance && _instance->GetBossState(TYPE_MIMIRON) != IN_PROGRESS)
                    me->ForcedDespawn();
            }

        private:
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_mimiron_flame_spreadAI(creature);
        }
};

class npc_frost_bomb : public CreatureScript
{
    public:
        npc_frost_bomb() : CreatureScript("npc_frost_bomb") { }

        struct npc_frost_bombAI : public Scripted_NoMovementAI
        {
            npc_frost_bombAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);
                DoCast(me, SPELL_FROST_BOMB, true);
                _frostTimer = 10000;
            }

            void UpdateAI(uint32 const diff)
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
            return new npc_frost_bombAI(creature);
        }
};

/*
-- Mimiron Tram
UPDATE `gameobject_template` SET `flags` = 32, `data2` = 3000, `ScriptName` = 'go_call_tram' WHERE `entry` IN (194914, 194912, 194437);
DELETE FROM gameobject WHERE id = '194437';
INSERT INTO `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
('194437','603','1','1','2306.87','274.237','424.288','1.52255','0','0','0.689847','0.723956','300','0','1');
DELETE FROM gameobject_template WHERE entry = '194438';
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `ScriptName`, `WDBVerified`) VALUES
('194438','1','8504','Activate Tram','','','','0','32','1','0','0','0','0','0','0','0','0','3000','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','go_call_tram','11159');
DELETE FROM gameobject WHERE id = '194438';
INSERT INTO `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(194438, 603, 1,1,2306.99, 2589.35, 424.382, 4.71676, 0, 0, 0.705559, -0.708651, 300, 0, 1);

-- Mimiron
UPDATE `creature_template` SET `mechanic_immune_mask` = 650854235, `ScriptName` = 'boss_mimiron' WHERE `entry` = 33350;
-- Leviathan MKII
UPDATE `creature_template` SET `vehicleid` = 370, `mechanic_immune_mask` = 650854235, `ScriptName` = 'boss_leviathan_mk' WHERE `entry` = 33432;
UPDATE `creature_template` SET `minlevel` = 83, `maxlevel` = 83, `mechanic_immune_mask` = 650854235, `flags_extra` = 1 WHERE `entry` = 34106;
UPDATE `creature_template` SET `mechanic_immune_mask` = 650854235, `ScriptName` = 'boss_leviathan_mk_turret' WHERE `entry` = 34071;
DELETE FROM vehicle_template_accessory WHERE entry = 33432;
INSERT INTO vehicle_template_accessory VALUE (33432, 34071, 3, 1, 'Leviathan Mk II turret', 8, 0);
UPDATE creature_template SET ScriptName = 'npc_proximity_mine' WHERE entry = 34362;
DELETE FROM `creature_model_info` WHERE `modelid`=28831;
INSERT INTO `creature_model_info` (`modelid`, `bounding_radius`, `combat_reach`, `gender`, `modelid_other_gender`) VALUES
(28831, 0.5, 7, 2, 0);
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (33432,33651);
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`quest_start`,`quest_start_active`,`quest_end`,`cast_flags`,`aura_required`,`aura_forbidden`,`user_type`) VALUES
(33432,46598,0,0,0,1,0,0,0), -- Leviatan MKII - Ride Vehicle Hardcoded
(33651,46598,0,0,0,1,0,0,0); -- VX 001 - Ride Vehicle Hardcoded

-- VX-001
UPDATE `creature_template` SET `mechanic_immune_mask` = 650854235, `flags_extra` = 1, `vehicleid` = 371, `ScriptName` = 'boss_vx_001' WHERE `entry` = 33651;
UPDATE `creature_template` SET `minlevel` = 83, `maxlevel` = 83, `mechanic_immune_mask` = 650854235, `flags_extra` = 1 WHERE `entry` = 34108;
UPDATE `creature_template` SET `faction_A` = 35, `faction_H` = 35 WHERE `entry` = 34050;
UPDATE `creature_template` SET `unit_flags` = 33686020, `flags_extra` = 2 WHERE `entry` = 34211;
UPDATE `creature_template` SET `ScriptName` = 'npc_rocket_strike' WHERE `entry` = 34047;

-- Aerial Command Unit
UPDATE `creature_template` SET `mechanic_immune_mask` = 650854235, `flags_extra` = 1, `ScriptName` = 'boss_aerial_unit', `vehicleid` = 372 WHERE `entry` = 33670;
UPDATE `creature_template` SET `minlevel` = 83, `maxlevel` = 83, `mechanic_immune_mask` = 650854235, `flags_extra` = 1 WHERE `entry` = 34109;
UPDATE `creature_template` SET `ScriptName` = 'npc_magnetic_core' WHERE `entry` = 34068;
UPDATE `creature_template` SET `ScriptName` = 'npc_assault_bot' WHERE `entry` = 34057;
UPDATE `creature_template` SET `difficulty_entry_1` = 34148, `ScriptName` = 'npc_emergency_bot' WHERE `entry` = 34147;

-- HardMode
UPDATE `gameobject_template` SET `flags` = 32, `ScriptName` = 'go_not_push_button' WHERE `entry` = 194739;
UPDATE `creature_template` SET `difficulty_entry_1` = 34361, `ScriptName` = 'npc_frost_bomb' WHERE `entry` = 34149;
UPDATE `creature_template` SET `speed_walk` = 0.15, `speed_run` = 0.15, `ScriptName` = 'npc_mimiron_flame_trigger' WHERE `entry` = 34363;
UPDATE `creature_template` SET `ScriptName` = 'npc_mimiron_flame_spread' WHERE `entry` = 34121;
UPDATE `creature_template` SET `ScriptName` = 'npc_mimiron_bomb_bot' WHERE `entry` = 33836;

-- CleanUp
DELETE FROM creature WHERE id IN (34071, 33856);
UPDATE `creature_template` SET `flags_extra` = 2 WHERE `entry` = 34143;
*/

void AddSC_boss_mimiron()
{
    new boss_mimiron();
    new boss_leviathan_mk();
    new boss_leviathan_mk_turret();
    new npc_proximity_mine();
    new boss_vx_001();
    new npc_rocket_strike();
    new spell_rapid_burst();
    new boss_aerial_unit();
    new npc_magnetic_core();
    new npc_assault_bot();
    new npc_emergency_bot();
    new npc_mimiron_bomb_bot();
    new go_not_push_button();
    new npc_mimiron_flame_trigger();
    new npc_mimiron_flame_spread();
    new npc_frost_bomb();
}