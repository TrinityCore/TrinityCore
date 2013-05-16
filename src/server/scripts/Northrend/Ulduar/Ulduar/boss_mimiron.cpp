/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "SpellScript.h"
#include "ulduar.h"
#include "Unit.h"
#include "Vehicle.h"
#include "VehicleDefines.h"

#define EMOTE_LEVIATHAN                         "Leviathan MK II begins to cast Plasma Blast!"
bool MimironHardMode;

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

enum Spells
{
    SPELL_JETPACK                               = 63341,
    SPELL_EMERGENCY_MODE                        = 64582,
    SPELL_SELF_REPAIR                           = 64383,
    SPELL_MAGNETIC_CORE                         = 64444,
    // Leviathan MK II
    SPELL_FLAME_SUPPRESSANT_MK                  = 64570,
    SPELL_NAPALM_SHELL                          = 63666,
    SPELL_PLASMA_BLAST                          = 62977,
    SPELL_PROXIMITY_MINES                       = 63027,
    SPELL_SHOCK_BLAST                           = 63631,
    // VX 001
    SPELL_FLAME_SUPPRESSANT_VX                  = 65192,
    SPELL_FROSTBOMB                             = 64623,
    SPELL_HAND_PULSE                            = 64348,
    SPELL_SPINNING_UP                           = 63414,
    SPELL_RAPID_BURST                           = 63387,
    SPELL_P3WX2_LASER_BARRAGE                   = 63293,
    SPELL_ROCKET_STRIKE                         = 63041,
    SPELL_HEAT_WAVE                             = 63677,
    SPELL_HOVER                                 = 57764,
    // Aerial Command Unit
    SPELL_PLASMA_BALL                           = 63689,
    // Additonal spells
    SPELL_MAGNETIC_FIELD                        = 64668,
    SPELL_DEAFENING_SIREN                       = 64616,
    SPELL_WATER_SPRAY                           = 64619,
    SPELL_FROST_BOMB_HARD_MODE                  = 64627,
    SPELL_EXPLOSION                             = 66351,
    SPELL_DISARM                                = 1842,
    SPELL_RIDE_VEHICLE                          = 46598,
    SPELL_TRIGGER_MISSILE                       = 65347,
    SPELL_ROCKET_STRIKE_DMG                     = 63041,
    SPELL_BERSERK                               = 47008,
    SPELL_FLAME_SUPPRESSANT                     = 64570,
    SPELL_MINES_SPAWN                           = 65347,
    SPELL_FLAME                                 = 64561,
    SPELL_FLAME_SUPPRESSANT_VX001               = 65192,
    SPELL_FROST_BOMB_EXPLOSION_10               = 64626,
    SPELL_FROST_BOMB_EXPLOSION_25               = 65333,
};

enum Npcs
{
//    NPC_VX_001                                  = 33651,
    NPC_AERIAL_UNIT                             = 33670,
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

enum Events
{
    // Intro
    EVENT_INTRO_1,
    EVENT_INTRO_2,
    EVENT_INTRO_3,
    EVENT_INTRO_4,
    EVENT_INTRO_5,
    EVENT_INTRO_6,
    EVENT_INTRO_7,
    EVENT_VX001_1,
    EVENT_VX001_2,
    EVENT_VX001_3,
    EVENT_VX001_4,
    EVENT_VX001_5,
    EVENT_VX001_6,
    EVENT_VX001_7,
    EVENT_VX001_8,
    EVENT_VX001_9,
    // Misc
    EVENT_ENRAGE,
    EVENT_FLAME,
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
    // Aerial Command Unit
    EVENT_PLASMA_BALL,
    EVENT_REACTIVATE_AERIAL,
    EVENT_SUMMON_BOTS
};

enum Seats
{
    SEAT_TURRET    = 3,
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

enum eActions
{
    DO_START_ENCOUNTER                         = 1,
    DO_ACTIVATE_VX001                          = 2,
    DO_START_VX001                             = 3,
    DO_ACTIVATE_AERIAL                         = 4,
    DO_START_AERIAL                            = 5,
    DO_DISABLE_AERIAL                          = 6,
    DO_ACTIVATE_V0L7R0N                        = 7,
    DO_LEVIATHAN_ASSEMBLED                     = 8,
    DO_VX001_ASSEMBLED                         = 9,
    DO_AERIAL_ASSEMBLED                        = 10,
    DO_ACTIVATE_DEATH_TIMER                    = 11,
    DO_ENTER_ENRAGE                            = 12,
    DO_ACTIVATE_HARD_MODE                      = 13,
    DO_DESPAWN_SUMMONS                         = 14
};

enum Npc
{
    NPC_EMERGENCE_FIRE_BOT                      = 34147,
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

class boss_mimiron : public CreatureScript
{
    public:
        boss_mimiron() : CreatureScript("boss_mimiron") { }

        struct boss_mimironAI : public BossAI
        {
            boss_mimironAI(Creature* creature) : BossAI(creature, BOSS_MIMIRON)
            {
                me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_ROCKET_STRIKE_DMG, true);
                MimironHardMode = false;
                me->SetReactState(REACT_PASSIVE);
            }

            void DespawnCreatures(uint32 entry, float distance, bool discs = false)
            {
                std::list<Creature*> Creatures;
                GetCreatureListWithEntryInGrid(Creatures, me, entry, distance);

                if (Creatures.empty())
                    return;

                for(std::list<Creature*>::iterator iter = Creatures.begin(); iter != Creatures.end(); ++iter)
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

                if (Creature* aerial = me->GetCreature(*me, instance->GetData64(DATA_AERIAL_UNIT)))
                    aerial->AI()->DoAction(DO_DESPAWN_SUMMONS);

                for (uint8 data = DATA_LEVIATHAN_MK_II; data <= DATA_AERIAL_UNIT; ++data)
                    if (Creature* creature = me->GetCreature(*me, instance->GetData64(data)))
                        if (creature->isAlive())
                        {
                            creature->ExitVehicle();
                            creature->AI()->EnterEvadeMode();
                        }

                events.SetPhase(PHASE_NULL);
                phase = PHASE_NULL;
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
                    go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                }
            }

            void EnterCombat(Unit * /*who*/)
            {
                _EnterCombat();
                instance->SetBossState(BOSS_MIMIRON, IN_PROGRESS);
                if (MimironHardMode)
                    TalkToMap(SAY_HARDMODE_ON);
                else
                    TalkToMap(SAY_AGGRO);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
                events.SetPhase(PHASE_INTRO);
                phase = PHASE_INTRO;
                events.ScheduleEvent(EVENT_INTRO_2, 10000, 0, PHASE_INTRO);

                if (MimironHardMode)
                {
                    events.ScheduleEvent(EVENT_ENRAGE, 480000);
                    events.ScheduleEvent(EVENT_FLAME, 30000);
                }
                else
                {
                    events.ScheduleEvent(EVENT_ENRAGE, 900000);
                }

                if (GameObject* go = me->FindNearestGameObject(GO_BIG_RED_BUTTON, 200))
                    go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
            }

            void EndEncounter()
            {
                TalkToMap(SAY_V07TRON_DEATH);
                DespawnCreatures(34362, 100);
                me->setFaction(35);

                if (instance)
                {
                    instance->SetBossState(BOSS_MIMIRON, DONE);
                    if (MimironHardMode)
                    {
                        DespawnCreatures(NPC_FLAME_SPREAD, 100);
                        DespawnCreatures(NPC_FLAME, 100);
                    }
                    instance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE, NPC_LEVIATHAN_MKII, 1);
                }

                EnterEvadeMode();
                me->DespawnOrUnsummon(5000);
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case DO_ACTIVATE_VX001:
                        events.SetPhase(PHASE_VX001_ACTIVATION);
                        phase = PHASE_VX001_ACTIVATION;
                        events.ScheduleEvent(EVENT_VX001_1, 200, 0, PHASE_VX001_ACTIVATION);
                        break;
                    case DO_ACTIVATE_AERIAL:
                        phase = PHASE_AERIAL_ACTIVATION;
                        //JumpToNextStep(5000);
                        break;
                    case DO_ACTIVATE_V0L7R0N:
                        me->SetVisible(true);
                        phase = PHASE_V0L7R0N_ACTIVATION;
                        //JumpToNextStep(1000);
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

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_INTRO_2:
                            if (instance)
                                if (Creature* Leviathan = me->GetCreature(*me, instance->GetData64(DATA_LEVIATHAN_MK_II)))
                                    me->EnterVehicle(Leviathan, 4);
                            events.ScheduleEvent(EVENT_INTRO_3, 2000, 0, PHASE_INTRO);
                            break;
                        case EVENT_INTRO_3:
                            me->ChangeSeat(2);
                            events.ScheduleEvent(EVENT_INTRO_4, 2000, 0, PHASE_INTRO);
                            break;
                        case EVENT_INTRO_4:
                            me->ChangeSeat(5);
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_STAND);
                            events.ScheduleEvent(EVENT_INTRO_5, 2500, 0, PHASE_INTRO);
                            break;
                        case EVENT_INTRO_5:
                            TalkToMap(SAY_MKII_ACTIVATE);
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_TALK);
                            events.ScheduleEvent(EVENT_INTRO_6, 6000, 0, PHASE_INTRO);
                            break;
                        case EVENT_INTRO_6:
                            me->ChangeSeat(6);
                            events.ScheduleEvent(EVENT_INTRO_7, 2000, 0, PHASE_INTRO);
                            break;
                        case EVENT_INTRO_7:
                            if (instance)
                                 if (Creature* Leviathan = me->GetCreature(*me, instance->GetData64(DATA_LEVIATHAN_MK_II)))
                                 {
                                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_STAND);
                                    Leviathan->AI()->DoAction(DO_START_ENCOUNTER);
                                    events.SetPhase(PHASE_COMBAT);
                                 }
                            break;
                        case EVENT_VX001_1:
                            TalkToMap(SAY_MKII_DEATH);
                            events.ScheduleEvent(EVENT_VX001_2, 10000, 0, PHASE_VX001_ACTIVATION);
                            break;
                        case EVENT_VX001_2:
                            me->ChangeSeat(1);
                            events.ScheduleEvent(EVENT_VX001_3, 2000, 0, PHASE_VX001_ACTIVATION);
                        case EVENT_VX001_3:
                            if (instance)
                                instance->SetData(DATA_MIMIRON_ELEVATOR, GO_STATE_READY);
                            events.ScheduleEvent(EVENT_VX001_4, 5000, 0, PHASE_VX001_ACTIVATION);
                            break;
                        case EVENT_VX001_4:
                            if (instance)
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
                            events.ScheduleEvent(EVENT_VX001_5, 8000, 0, PHASE_VX001_ACTIVATION);
                            break;
                        case EVENT_VX001_5:
                            if (instance)
                                if (Creature* VX_001 = me->GetCreature(*me, instance->GetData64(DATA_VX_001)))
                                    me->EnterVehicle(VX_001, 0);
                            events.ScheduleEvent(EVENT_VX001_6, 3500, 0, PHASE_VX001_ACTIVATION);
                            break;
                        case EVENT_VX001_6:
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_TALK);
                            TalkToMap(SAY_VX001_ACTIVATE);
                            events.ScheduleEvent(EVENT_VX001_7, 10000, 0, PHASE_VX001_ACTIVATION);
                            break;
                        case EVENT_VX001_7:
                            me->ChangeSeat(1);
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_SIT);
                            events.ScheduleEvent(EVENT_VX001_7, 2000, 0, PHASE_VX001_ACTIVATION);
                            break;
                        case EVENT_VX001_8:
                            if (instance)
                                if (Creature* VX_001 = me->GetCreature(*me, instance->GetData64(DATA_VX_001)))
                                    VX_001->HandleEmoteCommand(EMOTE_ONESHOT_EMERGE);
                            events.ScheduleEvent(EVENT_VX001_9, 3500, 0, PHASE_VX001_ACTIVATION);
                            break;
                        case EVENT_VX001_9:
                            if (instance)
                                if (Creature* VX_001 = me->GetCreature(*me, instance->GetData64(DATA_VX_001)))
                                {
                                    VX_001->AddAura(SPELL_HOVER, VX_001); // Hover
                                    VX_001->AI()->DoAction(DO_START_VX001);
                                    events.SetPhase(PHASE_COMBAT);
                                }
                            break;
                        case EVENT_ENRAGE:
                            TalkToMap(SAY_BERSERK);
                            for (uint8 data = DATA_LEVIATHAN_MK_II; data <= DATA_AERIAL_UNIT; ++data)
                                 if (Creature* creature = me->GetCreature(*me, instance->GetData64(data)))
                                     creature->AI()->DoAction(DO_ENTER_ENRAGE);
                            Enraged = true;
                            break;
                        case EVENT_FLAME:
                            for (uint8 i = 0; i < 3; ++i)
                                 if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                     if (Creature* Flame = me->SummonCreature(NPC_FLAME, target->GetPositionX() + irand(-6,6), target->GetPositionY() + irand(-6,6), target->GetPositionZ(), 0, TEMPSUMMON_MANUAL_DESPAWN))
                                         Flame->AI()->AttackStart(target);
                            events.ScheduleEvent(EVENT_FLAME, 30000);		
                            break;
                    }
                }
            }

        private:
            uint32 EnrageTimer;
            uint32 FlameTimer;
            uint32 uiBotTimer;
            bool checkBotAlive;
            bool Enraged;
            Phases phase;
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_mimironAI (creature);
        }
};

class boss_leviathan_mk : public CreatureScript
{
public:
    boss_leviathan_mk() : CreatureScript("boss_leviathan_mk") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return GetUlduarAI<boss_leviathan_mkAI>(creature);
    }

    struct boss_leviathan_mkAI : public ScriptedAI 
    {
        boss_leviathan_mkAI(Creature* creature) : ScriptedAI(creature), phase(PHASE_NULL), vehicle(creature->GetVehicleKit())
        {
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_ROCKET_STRIKE_DMG, true);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            ASSERT(vehicle);
        }

        Phases phase;
        Vehicle* vehicle;
        EventMap events;
        InstanceScript* instance;

        void Reset()
        {
            events.Reset();
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
            me->SetStandState(UNIT_STAND_STATE_STAND);
            me->SetReactState(REACT_PASSIVE);
            me->RemoveAllAurasExceptType(SPELL_AURA_CONTROL_VEHICLE);
            phase = PHASE_NULL;
            events.SetPhase(PHASE_NULL);
            if (Unit* turret = me->GetVehicleKit()->GetPassenger(SEAT_TURRET))
            {
                turret->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
            }
        }

        void KilledUnit(Unit* /*who*/)
        {
            if (phase == PHASE_LEVIATHAN_SOLO)
                TalkToMap(SAY_MKII_SLAY);
            else
                TalkToMap(SAY_V07TRON_SLAY);
        }

        void DamageTaken(Unit* /*who*/, uint32 &damage)
        {
            if (phase == PHASE_NULL)
                damage = 0;

            if (phase == PHASE_LEVIATHAN_SOLO)
                if (damage >= me->GetHealth())
                {
                    damage = 0;
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    //me->RemoveAllAurasExceptType(SPELL_AURA_CONTROL_VEHICLE);
                    me->SetHealth(me->GetMaxHealth());
                    events.SetPhase(PHASE_NULL);
                    phase = PHASE_NULL;
                    if (Creature* Mimiron = me->GetCreature(*me, instance->GetData64(BOSS_MIMIRON)))
                        Mimiron->AI()->DoAction(DO_ACTIVATE_VX001);
                    me->SetSpeed(MOVE_RUN, 1.5f, true);
                    me->GetMotionMaster()->MovePoint(0, 2790.11f, 2595.83f, 364.32f);
                }

            if (phase == PHASE_LEVIATHAN_ASSEMBLED)
                if (damage >= me->GetHealth())
                {
                    damage = 0;
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    me->RemoveAllAurasExceptType(SPELL_AURA_CONTROL_VEHICLE);
                    me->SetHealth(me->GetMaxHealth());
                    me->SetStandState(UNIT_STAND_STATE_DEAD);
                    events.SetPhase(PHASE_NULL);
                    phase = PHASE_NULL;
                    if (Creature* Mimiron = me->GetCreature(*me, instance->GetData64(BOSS_MIMIRON)))
                        Mimiron->AI()->DoAction(DO_ACTIVATE_DEATH_TIMER);
                }
        }

        void EnterCombat(Unit* who)
        {
            if (MimironHardMode)
            {
                DoCast(me, SPELL_EMERGENCY_MODE);
                events.ScheduleEvent(EVENT_FLAME_SUPPRESSANT, 60000, 0, PHASE_LEVIATHAN_SOLO);
            }

            if (Unit* turret = me->GetVehicleKit()->GetPassenger(SEAT_TURRET))
            {
                turret->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
            }

            events.ScheduleEvent(EVENT_PROXIMITY_MINE, 1000);
            events.ScheduleEvent(EVENT_PLASMA_BLAST, 10000, 0, PHASE_LEVIATHAN_SOLO);
        }

        void DoAction(int32 action)
        {
            switch(action)
            {
                case DO_START_ENCOUNTER:
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_NON_ATTACKABLE);
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

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
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

    CreatureAI* GetAI(Creature* creature) const
    {
        return GetUlduarAI<boss_leviathan_mk_turretAI>(creature);
    }

    struct boss_leviathan_mk_turretAI : public ScriptedAI
    {
        boss_leviathan_mk_turretAI(Creature* creature) : ScriptedAI(creature) 
        {
            me->SetReactState(REACT_PASSIVE);
            uiNapalmShell = urand(4000, 8000);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        uint32 uiNapalmShell;
        
        void Reset()
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
            me->SetStandState(UNIT_STAND_STATE_STAND);
            me->SetReactState(REACT_PASSIVE);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (uiNapalmShell <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, -12.0f))
                    DoCast(target, SPELL_NAPALM_SHELL);
                uiNapalmShell = urand(8000, 12000);
            }
            else uiNapalmShell -= diff;
        }
    };
};

class spell_ulduar_proximity_mines : public SpellScriptLoader
{
    public:
        spell_ulduar_proximity_mines() : SpellScriptLoader("spell_ulduar_proximity_mines") { }

        class spell_ulduar_proximity_minesSpellScript : public SpellScript
        {
            PrepareSpellScript(spell_ulduar_proximity_minesSpellScript)

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                for (uint8 i = 0; i < 10; ++i)
                    GetCaster()->CastSpell(GetCaster(), SPELL_TRIGGER_MISSILE, true);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_ulduar_proximity_minesSpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_ulduar_proximity_minesSpellScript();
        }
};

class go_not_push_button : public GameObjectScript
{
public:
    go_not_push_button() : GameObjectScript("go_not_push_button") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        InstanceScript* _instance = go->GetInstanceScript();

        if (!_instance)
            return false;

        if ((_instance->GetBossState(BOSS_MIMIRON) != IN_PROGRESS || _instance->GetBossState(BOSS_MIMIRON) != DONE) && player)
            if (Creature* mimiron = player->GetCreature((*player), _instance->GetData64(BOSS_MIMIRON)))
                mimiron->AI()->DoAction(DO_ACTIVATE_HARD_MODE);

        go->UseDoorOrButton();

        return true;
    }
};

class npc_mimiron_flame_trigger : public CreatureScript
{
public:
    npc_mimiron_flame_trigger() : CreatureScript("npc_mimiron_flame_trigger") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_mimiron_flame_triggerAI(creature);
    }

    struct npc_mimiron_flame_triggerAI : public ScriptedAI
    {
        npc_mimiron_flame_triggerAI(Creature* creature) : ScriptedAI(creature)
        {
            //me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);
            DoCast(me, SPELL_FLAME, true);
            FlameTimer = 8000;
        }

        uint32 FlameTimer;

        void SpellHit(Unit* caster, SpellInfo const* spell)
        {
            switch (spell->Id)
            {
                case SPELL_FLAME_SUPPRESSANT:
                case SPELL_FLAME_SUPPRESSANT_VX001:
                case SPELL_FROST_BOMB_EXPLOSION_10:
                case SPELL_FROST_BOMB_EXPLOSION_25:
                case SPELL_WATER_SPRAY:
                    FlameTimer = 1000;
                    me->DespawnOrUnsummon(500);
                    break;
                default:
                    break;
            }
        }

        void UpdateAI(uint32 diff)
        {
            if (FlameTimer <= diff)
            {
                me->SummonCreature(NPC_FLAME_SPREAD, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
                FlameTimer = 8000;
            }
            else FlameTimer -= diff;
        }
    };
};

class npc_mimiron_flame_spread : public CreatureScript
{
public:
    npc_mimiron_flame_spread() : CreatureScript("npc_mimiron_flame_spread") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_mimiron_flame_spreadAI(creature);
    }

    struct npc_mimiron_flame_spreadAI : public ScriptedAI
    {
        npc_mimiron_flame_spreadAI(Creature* creature) : ScriptedAI(creature)
        {
            _instance = creature->GetInstanceScript();
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED | UNIT_FLAG_DISABLE_MOVE);
            me->SetReactState(REACT_PASSIVE);
            DoCast(me, SPELL_FLAME, true);
        }

        InstanceScript* _instance;

        void SpellHit(Unit* caster, SpellInfo const* spell)
        {
            switch (spell->Id)
            {
                case SPELL_FLAME_SUPPRESSANT:
                case SPELL_FLAME_SUPPRESSANT_VX001:
                case SPELL_FROST_BOMB_EXPLOSION_10:
                case SPELL_FROST_BOMB_EXPLOSION_25:
                case SPELL_WATER_SPRAY:
                    me->DespawnOrUnsummon(500);
                    break;
                default:
                    break;
            }
        }

        void UpdateAI(uint32 uiDiff)
        {
            if (_instance && _instance->GetBossState(BOSS_MIMIRON) != IN_PROGRESS)
                me->DespawnOrUnsummon();
        }
    };
};

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
        boss_vx_001AI(Creature* creature) : BossAI(creature, BOSS_MIMIRON), phase(PHASE_NULL)
        {
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_ROCKET_STRIKE_DMG, true);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        Phases phase;
        EventMap events;

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
            me->SetReactState(REACT_PASSIVE);
            me->SetStandState(UNIT_STAND_STATE_STAND);
            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_STAND);
            me->SetVisible(false);
            me->RemoveAllAurasExceptType(SPELL_AURA_CONTROL_VEHICLE);
            phase = PHASE_NULL;
            events.SetPhase(PHASE_NULL);
        }

        void KilledUnit(Unit * /*who*/)
        {
            if (!(rand()%5))
                if (instance)
                    if (Creature* Mimiron = me->GetCreature(*me, instance->GetData64(BOSS_MIMIRON)))
                    {
                        if (phase == PHASE_VX001_SOLO)
                            TalkToMap(SAY_VX001_SLAY);
                        else
                            TalkToMap(SAY_V07TRON_SLAY);
                    }
        }

        void EnterCombat(Unit * /*who*/)
        {
            if (MimironHardMode)
            {
                DoCast(me, SPELL_EMERGENCY_MODE);
                events.ScheduleEvent(EVENT_FROST_BOMB, 15000);
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
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
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
            if (phase == PHASE_NULL)
                damage = 0;

            if (phase == PHASE_VX001_SOLO)
                if (damage >= me->GetHealth())
                {
                    damage = 0;
                    spinning = false;
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
                    me->AttackStop();
                    me->GetMotionMaster()->Initialize();
                    me->RemoveAllAurasExceptType(SPELL_AURA_CONTROL_VEHICLE);
                    me->SetHealth(me->GetMaxHealth());
                    me->SetStandState(UNIT_STAND_STATE_DEAD);
                    phase = PHASE_NULL;
                    events.SetPhase(PHASE_NULL);
                    if (Creature* Mimiron = me->GetCreature(*me, instance->GetData64(BOSS_MIMIRON)))
                        Mimiron->AI()->DoAction(DO_ACTIVATE_AERIAL);
                }

            if (phase == PHASE_VX001_ASSEMBLED)
                if (damage >= me->GetHealth())
                {
                    damage = 0;
                    spinning = false;
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
                    me->AttackStop();
                    me->RemoveAllAurasExceptType(SPELL_AURA_CONTROL_VEHICLE);
                    me->SetHealth(me->GetMaxHealth());
                    me->SetStandState(UNIT_STAND_STATE_DEAD);
                    events.SetPhase(PHASE_NULL);
                    phase = PHASE_NULL;
                    if (Creature* Mimiron = me->GetCreature(*me, instance->GetData64(BOSS_MIMIRON)))
                        Mimiron->AI()->DoAction(DO_ACTIVATE_DEATH_TIMER);
                }
        }

        void UpdateAI(uint32 diff)
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
                        leviathan->SetFacingTo(orient + (direction ? M_PI/60 : -M_PI/60));
                        me->SetOrientation(orient + (direction ? M_PI/60 : -M_PI/60));
                    }
                    else
                    {
                        float orient = me->GetOrientation();
                        me->SetFacingTo(orient + (direction ? M_PI/60 : -M_PI/60));
                    }
                    spinTimer = 250;
                }
                else spinTimer -= diff;
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
                                float orient = leviathan->GetOrientation();
                                leviathan->CastSpell(leviathan, 14821, true);
                                leviathan->SetFacingTo(orient);
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
                            events.RescheduleEvent(EVENT_HAND_PULSE, urand(4000, 5000));
                            break;
                        case EVENT_FROST_BOMB:
                            me->SummonCreature(NPC_FROST_BOMB, SummonPos[rand()%9], TEMPSUMMON_TIMED_DESPAWN, 11000);
                            events.RescheduleEvent(EVENT_FROST_BOMB, 45000);
                            break;
                    }
                }
            }
        }
    };
};

void AddSC_boss_mimiron()
{
    new boss_mimiron();
    new boss_leviathan_mk();
    new boss_leviathan_mk_turret();
    new go_not_push_button();
    new npc_mimiron_flame_trigger();
    new npc_mimiron_flame_spread();
    new spell_ulduar_proximity_mines();
}
