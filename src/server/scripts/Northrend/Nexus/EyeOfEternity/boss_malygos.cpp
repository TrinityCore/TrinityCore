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

/* Script Data Start
SDName: Boss malygos
Script Data End */

// TO-DOs:
// Implement a better pathing for Malygos.
// Find sniffed spawn position for chest
// Implement a better way to disappear the gameobjects
// Implement achievements
// Implement scaling for player's drakes (should be done with aura 66668, it is casted - but it is not working as it should)
// Remove hack that re-adds targets to the aggro list after they enter to a vehicle when it works as expected
// Improve whatever can be improved :)

#include "ScriptPCH.h"
#include "eye_of_eternity.h"
#include "ScriptedEscortAI.h"

// not implemented
enum Achievements
{
    ACHIEV_TIMED_START_EVENT                      = 20387,
};

enum Events
{
    // =========== PHASE ONE ===============
    EVENT_ARCANE_BREATH = 1,
    EVENT_ARCANE_STORM  = 2,
    EVENT_VORTEX        = 3,
    EVENT_POWER_SPARKS  = 4,

    // =========== PHASE TWO ===============
    EVENT_SURGE_POWER   = 5, // wowhead is wrong, Surge of Power is casted instead of Arcane Pulse (source sniffs!)
    EVENT_SUMMON_ARCANE = 6,

    // =========== PHASE TWO ===============
    EVENT_SURGE_POWER_PHASE_3 = 7,
    EVENT_STATIC_FIELD = 8,

    // =============== YELLS ===============
    EVENT_YELL_0 = 9,
    EVENT_YELL_1 = 10,
    EVENT_YELL_2 = 11,
    EVENT_YELL_3 = 12,
    EVENT_YELL_4 = 13,
};

enum Phases
{
    PHASE_ONE = 1,
    PHASE_TWO = 2,
    PHASE_THREE = 3
};

enum Spells
{
    SPELL_ARCANE_BREATH = 56272,
    SPELL_ARCANE_STORM  = 57459,
    SPELL_BERSEKER      = 60670,

    SPELL_VORTEX_1 = 56237, // seems that frezze object animation
    SPELL_VORTEX_2 = 55873, // visual effect
    SPELL_VORTEX_3 = 56105, // this spell must handle all the script - casted by the boss and to himself
    //SPELL_VORTEX_4 = 55853, // damage | used to enter to the vehicle - defined in eye_of_eternity.h
    //SPELL_VORTEX_5 = 56263, // damage | used to enter to the vehicle - defined in eye_of_eternity.h
    SPELL_VORTEX_6 = 73040, // teleport - (casted to all raid) | caster 30090 | target player

    SPELL_PORTAL_VISUAL_CLOSED = 55949,
    SPELL_SUMMON_POWER_PARK = 56142,
    SPELL_POWER_SPARK_DEATH = 55852,
    SPELL_POWER_SPARK_MALYGOS = 56152,

    SPELL_SURGE_POWER = 56505, // used in phase 2
    SPELL_SUMMON_ARCANE_BOMB = 56429,
    SPELL_ARCANE_OVERLOAD = 56432,
    SPELL_SUMMOM_RED_DRAGON = 56070,
    SPELL_SURGE_POWER_PHASE_3 = 57407,
    SPELL_STATIC_FIELD = 57430
};

enum Movements
{
    MOVE_VORTEX = 1,
    MOVE_PHASE_TWO,
    MOVE_DEEP_BREATH_ROTATION,
    MOVE_INIT_PHASE_ONE,
    MOVE_CENTER_PLATFORM
};

enum Seats
{
    SEAT_0 = 0,
};

enum Factions
{
    FACTION_FRIENDLY = 35,
    FACTION_HOSTILE = 14
};

enum Actions
{
    ACTION_HOVER_DISK_START_WP_1,
    ACTION_HOVER_DISK_START_WP_2
};

enum MalygosEvents
{
    DATA_SUMMON_DEATHS, // phase 2
    DATA_PHASE
};

#define TEN_MINUTES 600000

enum MalygosSays
{
    SAY_AGGRO_P_ONE,
    SAY_KILLED_PLAYER_P_ONE,
    SAY_END_P_ONE,
    SAY_AGGRO_P_TWO,
    SAY_ANTI_MAGIC_SHELL, // not sure when execute it
    SAY_MAGIC_BLAST,  // not sure when execute it
    SAY_KILLED_PLAYER_P_TWO,
    SAY_END_P_TWO,
    SAY_INTRO_P_THREE,
    SAY_AGGRO_P_THREE,
    SAY_SURGE_POWER,  // not sure when execute it
    SAY_BUFF_SPARK,
    SAY_KILLED_PLAYER_P_THREE,
    SAY_SPELL_CASTING_P_THREE,
    SAY_DEATH
};

#define MAX_HOVER_DISK_WAYPOINTS 18

// Sniffed data (x,y,z)
const Position HoverDiskWaypoints[MAX_HOVER_DISK_WAYPOINTS] =
{
   {782.9821f, 1296.652f, 282.1114f, 0.0f},
   {779.5459f, 1287.228f, 282.1393f, 0.0f},
   {773.0028f, 1279.52f, 282.4164f, 0.0f},
   {764.3626f, 1274.476f, 282.4731f, 0.0f},
   {754.3961f, 1272.639f, 282.4171f, 0.0f},
   {744.4422f, 1274.412f, 282.222f, 0.0f},
   {735.575f, 1279.742f, 281.9674f, 0.0f},
   {729.2788f, 1287.187f, 281.9943f, 0.0f},
   {726.1191f, 1296.688f, 282.2997f, 0.0f},
   {725.9396f, 1306.531f, 282.2448f, 0.0f},
   {729.3045f, 1316.122f, 281.9108f, 0.0f},
   {735.8322f, 1323.633f, 282.1887f, 0.0f},
   {744.4616f, 1328.999f, 281.9948f, 0.0f},
   {754.4739f, 1330.666f, 282.049f, 0.0f},
   {764.074f, 1329.053f, 281.9949f, 0.0f},
   {772.8409f, 1323.951f, 282.077f, 0.0f},
   {779.5085f, 1316.412f, 281.9145f, 0.0f},
   {782.8365f, 1306.778f, 282.3035f, 0.0f},
};

#define GROUND_Z 268

// Source: Sniffs (x,y,z)
#define MALYGOS_MAX_WAYPOINTS 16
const Position MalygosPhaseTwoWaypoints[MALYGOS_MAX_WAYPOINTS] =
{
    {812.7299f, 1391.672f, 283.2763f, 0.0f},
    {848.2912f, 1358.61f, 283.2763f, 0.0f},
    {853.9227f, 1307.911f, 283.2763f, 0.0f},
    {847.1437f, 1265.538f, 283.2763f, 0.0f},
    {839.9229f, 1245.245f, 283.2763f, 0.0f},
    {827.3463f, 1221.818f, 283.2763f, 0.0f},
    {803.2727f, 1203.851f, 283.2763f, 0.0f},
    {772.9372f, 1197.981f, 283.2763f, 0.0f},
    {732.1138f, 1200.647f, 283.2763f, 0.0f},
    {693.8761f, 1217.995f, 283.2763f, 0.0f},
    {664.5038f, 1256.539f, 283.2763f, 0.0f},
    {650.1497f, 1303.485f, 283.2763f, 0.0f},
    {662.9109f, 1350.291f, 283.2763f, 0.0f},
    {677.6391f, 1377.607f, 283.2763f, 0.0f},
    {704.8198f, 1401.162f, 283.2763f, 0.0f},
    {755.2642f, 1417.1f, 283.2763f, 0.0f},
};

#define MAX_SUMMONS_PHASE_TWO 4

#define MAX_MALYGOS_POS 2
const Position MalygosPositions[MAX_MALYGOS_POS] =
{
    {754.544f, 1301.71f, 320.0f, 0.0f},
    {754.39f, 1301.27f, 292.91f, 0.0f},
};

class boss_malygos : public CreatureScript
{
public:
    boss_malygos() : CreatureScript("boss_malygos") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_malygosAI(creature);
    }

    struct boss_malygosAI : public BossAI
    {
        boss_malygosAI(Creature* creature) : BossAI(creature, DATA_MALYGOS_EVENT)
        {
            // If we enter in combat when MovePoint generator is active, it overrwrites our homeposition
            homePosition = creature->GetHomePosition();
        }

        void Reset()
        {

            _Reset();

            bersekerTimer = 0;
            currentPos = 0;

            SetPhase(PHASE_ONE, true);

            delayedMovementTimer = 8000;
            delayedMovement = false;

            summonDeaths = 0;

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

            cannotMove = true;
        }

        uint32 GetData(uint32 data)
        {
            if (data == DATA_SUMMON_DEATHS)
                return summonDeaths;
            else if (data == DATA_PHASE)
                return phase;

            return 0;
        }

        void SetData(uint32 data, uint32 value)
        {
            if (data == DATA_SUMMON_DEATHS && phase == PHASE_TWO)
            {
                summonDeaths = value;

                if (summonDeaths >= MAX_SUMMONS_PHASE_TWO)
                    StartPhaseThree();
            }
        }

        void EnterEvadeMode()
        {
            me->SetHomePosition(homePosition);

            me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);

            BossAI::EnterEvadeMode();

            if (instance)
                instance->SetBossState(DATA_MALYGOS_EVENT, FAIL);
        }

        void SetPhase(uint8 _phase, bool setEvents = false)
        {
            events.Reset();

            events.SetPhase(_phase);
            phase = _phase;

            if (setEvents)
                SetPhaseEvents(_phase);
        }

        void StartPhaseThree()
        {
            if (!instance)
                return;

            SetPhase(PHASE_THREE, true);

            // this despawns Hover Disks
            summons.DespawnAll();
            // players that used Hover Disk are no in the aggro list
            me->SetInCombatWithZone();
            std::list<HostileReference*> &m_threatlist = me->getThreatManager().getThreatList();
            for (std::list<HostileReference*>::const_iterator itr = m_threatlist.begin(); itr!= m_threatlist.end(); ++itr)
            {
                if (Unit* target = (*itr)->getTarget())
                {
                    if (target->GetTypeId() != TYPEID_PLAYER)
                        continue;

                    // The rest is handled in the AI of the vehicle.
                    target->CastSpell(target, SPELL_SUMMOM_RED_DRAGON, true);
                }
            }

            if (GameObject* go = GameObject::GetGameObject(*me, instance->GetData64(DATA_PLATFORM)))
                go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DESTROYED); // In sniffs it has this flag, but i don't know how is applied.

            // pos sniffed
            me->GetMotionMaster()->MoveIdle();
            me->GetMotionMaster()->MovePoint(MOVE_CENTER_PLATFORM, MalygosPositions[0].GetPositionX(), MalygosPositions[0].GetPositionY(), MalygosPositions[0].GetPositionZ());
        }

        void SetPhaseEvents(uint8 _phase)
        {
            switch (_phase)
            {
                case PHASE_ONE:
                    events.ScheduleEvent(EVENT_ARCANE_BREATH, urand(15, 20)*IN_MILLISECONDS, 0, _phase);
                    events.ScheduleEvent(EVENT_ARCANE_STORM, urand(5, 10)*IN_MILLISECONDS, 0, _phase);
                    events.ScheduleEvent(EVENT_VORTEX, urand(30, 40)*IN_MILLISECONDS, 0, _phase);
                    events.ScheduleEvent(EVENT_POWER_SPARKS, urand(30, 35)*IN_MILLISECONDS, 0, _phase);
                    break;
                case PHASE_TWO:
                    events.ScheduleEvent(EVENT_YELL_0, 0, 0, _phase);
                    events.ScheduleEvent(EVENT_YELL_1, 24*IN_MILLISECONDS, 0, _phase);
                    events.ScheduleEvent(EVENT_SURGE_POWER, urand(60, 70)*IN_MILLISECONDS, 0, _phase);
                    events.ScheduleEvent(EVENT_SUMMON_ARCANE, urand(2, 5)*IN_MILLISECONDS, 0, _phase);
                    break;
                case PHASE_THREE:
                    events.ScheduleEvent(EVENT_YELL_2, 0, 0, _phase);
                    events.ScheduleEvent(EVENT_YELL_3, 8*IN_MILLISECONDS, 0, _phase);
                    events.ScheduleEvent(EVENT_YELL_4, 16*IN_MILLISECONDS, 0, _phase);
                    events.ScheduleEvent(EVENT_SURGE_POWER_PHASE_3, urand(7, 16)*IN_MILLISECONDS, 0, _phase);
                    events.ScheduleEvent(EVENT_STATIC_FIELD, urand(20, 30)*IN_MILLISECONDS, 0, _phase);
                    break;
                default:
                    break;
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();

            me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

            Talk(SAY_AGGRO_P_ONE);

            DoCast(SPELL_BERSEKER);
        }

        void KilledUnit(Unit* who)
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            switch (phase)
            {
            case PHASE_ONE:
                Talk(SAY_KILLED_PLAYER_P_ONE);
                break;
            case PHASE_TWO:
                Talk(SAY_KILLED_PLAYER_P_TWO);
                break;
            case PHASE_THREE:
                Talk(SAY_KILLED_PLAYER_P_THREE);
                break;
            }
        }

        void SpellHit(Unit* caster, const SpellInfo* spell)
        {
            if (spell->Id == SPELL_POWER_SPARK_MALYGOS)
            {
                if (Creature* creature = caster->ToCreature())
                    creature->DespawnOrUnsummon();

                Talk(SAY_BUFF_SPARK);
            }
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (!me->isInCombat())
                return;

            if (who->GetEntry() == NPC_POWER_SPARK)
            {
                // not sure about the distance | I think it is better check this here than in the UpdateAI function...
                if (who->GetDistance(me) <= 2.5f)
                    who->CastSpell(me, SPELL_POWER_SPARK_MALYGOS, true);

            }
        }

        void PrepareForVortex()
        {
            me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);

            me->GetMotionMaster()->MovementExpired();
            me->GetMotionMaster()->MovePoint(MOVE_VORTEX, MalygosPositions[1].GetPositionX(), MalygosPositions[1].GetPositionY(), MalygosPositions[1].GetPositionZ());
            // continues in MovementInform function.
        }

        void ExecuteVortex()
        {
            DoCast(me, SPELL_VORTEX_1, true);
            DoCast(me, SPELL_VORTEX_2, true);

            // the vortex execution continues in the dummy effect of this spell (see its script)
            DoCast(me, SPELL_VORTEX_3, true);
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE)
                return;

            switch (id)
            {
                case MOVE_VORTEX:
                    me->GetMotionMaster()->MoveIdle();
                    ExecuteVortex();
                    break;
                case MOVE_DEEP_BREATH_ROTATION:
                    currentPos = currentPos == MALYGOS_MAX_WAYPOINTS - 1 ? 0 : currentPos+1;
                    me->GetMotionMaster()->MovementExpired();
                    me->GetMotionMaster()->MovePoint(MOVE_DEEP_BREATH_ROTATION, MalygosPhaseTwoWaypoints[currentPos]);
                    break;
                case MOVE_INIT_PHASE_ONE:
                    me->SetInCombatWithZone();
                    break;
                case MOVE_CENTER_PLATFORM:
                    cannotMove = false;
                    // malygos will move into center of platform and then he does not chase dragons, he just turns to his current target.
                    me->GetMotionMaster()->MoveIdle();
                    break;
            }
        }

        void StartPhaseTwo()
        {
            SetPhase(PHASE_TWO, true);

            me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);

            me->GetMotionMaster()->MoveIdle();
            me->GetMotionMaster()->MovePoint(MOVE_DEEP_BREATH_ROTATION, MalygosPhaseTwoWaypoints[0]);

            Creature* summon = me->SummonCreature(NPC_HOVER_DISK_CASTER, HoverDiskWaypoints[MAX_HOVER_DISK_WAYPOINTS-1]);
            if (summon && summon->IsAIEnabled)
                summon->AI()->DoAction(ACTION_HOVER_DISK_START_WP_2);
            summon = me->SummonCreature(NPC_HOVER_DISK_CASTER, HoverDiskWaypoints[0]);
            if (summon && summon->IsAIEnabled)
                summon->AI()->DoAction(ACTION_HOVER_DISK_START_WP_1);

            for (uint8 i = 0; i < 2; i++)
            {
                // not sure about its position.
                summon = me->SummonCreature(NPC_HOVER_DISK_MELEE, HoverDiskWaypoints[0]);
                if (summon)
                    summon->SetInCombatWithZone();
            }
        }

        void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (phase == PHASE_THREE)
            {
                if (!cannotMove)
                {
                    // it can change if the player falls from the vehicle.
                    if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() != IDLE_MOTION_TYPE)
                    {
                        me->GetMotionMaster()->MovementExpired();
                        me->GetMotionMaster()->MoveIdle();
                    }
                } else
                {
                    if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() != POINT_MOTION_TYPE)
                    {
                        me->GetMotionMaster()->MovementExpired();
                        me->GetMotionMaster()->MovePoint(MOVE_CENTER_PLATFORM, MalygosPositions[0].GetPositionX(), MalygosPositions[0].GetPositionY(), MalygosPositions[0].GetPositionZ());
                    }
                }
            }

            // we need a better way for pathing
            if (delayedMovement)
            {
                if (delayedMovementTimer <= diff)
                {
                    me->GetMotionMaster()->MovePoint(MOVE_DEEP_BREATH_ROTATION, MalygosPhaseTwoWaypoints[currentPos]);
                    delayedMovementTimer = 8000;
                    delayedMovement = false;
                } delayedMovementTimer -= diff;
            }

            // at 50 % health malygos switch to phase 2
            if (me->GetHealthPct() <= 50.0f && phase == PHASE_ONE)
                StartPhaseTwo();

            // the boss is handling vortex
            if (me->HasAura(SPELL_VORTEX_2))
                return;

            // We can't cast if we are casting already.
            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_YELL_2:
                        Talk(SAY_END_P_TWO);
                        break;
                    case EVENT_YELL_3:
                        Talk(SAY_INTRO_P_THREE);
                        break;
                    case EVENT_YELL_4:
                        Talk(SAY_AGGRO_P_THREE);
                        break;
                    case EVENT_YELL_0:
                        Talk(SAY_END_P_ONE);
                        break;
                    case EVENT_YELL_1:
                        Talk(SAY_AGGRO_P_TWO);
                        break;
                    case EVENT_ARCANE_BREATH:
                        DoCast(me->getVictim(), SPELL_ARCANE_BREATH);
                        events.ScheduleEvent(EVENT_ARCANE_BREATH, urand(35, 60)*IN_MILLISECONDS, 0, PHASE_ONE);
                        break;
                    case EVENT_ARCANE_STORM:
                        DoCast(me->getVictim(), SPELL_ARCANE_STORM);
                        events.ScheduleEvent(EVENT_ARCANE_STORM, urand(5, 10)*IN_MILLISECONDS, 0, PHASE_ONE);
                        break;
                    case EVENT_VORTEX:
                        PrepareForVortex();
                        events.ScheduleEvent(EVENT_VORTEX, urand(60, 80)*IN_MILLISECONDS, 0, PHASE_ONE);
                        break;
                    case EVENT_POWER_SPARKS:
                        instance->SetData(DATA_POWER_SPARKS_HANDLING, 0);
                        events.ScheduleEvent(EVENT_POWER_SPARKS, urand(30, 35)*IN_MILLISECONDS, 0, PHASE_ONE);
                        break;
                    case EVENT_SURGE_POWER:
                        me->GetMotionMaster()->MoveIdle();
                        delayedMovement = true;
                        DoCast(SPELL_SURGE_POWER);
                        events.ScheduleEvent(EVENT_SURGE_POWER, urand(60, 70)*IN_MILLISECONDS, 0, PHASE_TWO);
                        break;
                    case EVENT_SUMMON_ARCANE:
                        DoCast(SPELL_SUMMON_ARCANE_BOMB);
                        events.ScheduleEvent(EVENT_SUMMON_ARCANE, urand(12, 15)*IN_MILLISECONDS, 0, PHASE_TWO);
                        break;
                    case EVENT_SURGE_POWER_PHASE_3:
                        DoCast(GetTargetPhaseThree(), SPELL_SURGE_POWER_PHASE_3);
                        events.ScheduleEvent(EVENT_SURGE_POWER_PHASE_3, urand(7, 16)*IN_MILLISECONDS, 0, PHASE_THREE);
                        break;
                    case EVENT_STATIC_FIELD:
                        DoCast(GetTargetPhaseThree(), SPELL_STATIC_FIELD);
                        events.ScheduleEvent(EVENT_STATIC_FIELD, urand(20, 30)*IN_MILLISECONDS, 0, PHASE_THREE);
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

        Unit* GetTargetPhaseThree()
        {
            Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0);

            // we are a drake
            if (target->GetVehicleKit())
                return target;

            // we are a player using a drake (or at least you should)
            if (target->GetTypeId() == TYPEID_PLAYER)
            {
                if (Unit* base = target->GetVehicleBase())
                    return base;
            }

            // is a player falling from a vehicle?
            return NULL;
        }

        void JustDied(Unit* /*killer*/)
        {
            Talk(SAY_DEATH);
            _JustDied();
        }

    private:
        uint8 phase;
        uint32 bersekerTimer;
        uint8 currentPos; // used for phase 2 rotation...
        bool delayedMovement; // used in phase2.
        uint32 delayedMovementTimer; // used in phase 2
        uint8 summonDeaths;
        Position homePosition; // it can get bugged because core thinks we are pathing
        bool mustTalk;
        bool cannotMove;
    };

};

class spell_malygos_vortex_dummy : public SpellScriptLoader
{
public:
    spell_malygos_vortex_dummy() : SpellScriptLoader("spell_malygos_vortex_dummy") {}

    class spell_malygos_vortex_dummy_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_malygos_vortex_dummy_SpellScript)

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();

            if (!caster)
                return;

            // each player will enter to the trigger vehicle (entry 30090) already spawned (each one can hold up to 5 players, it has 5 seats)
            // the players enter to the vehicles casting SPELL_VORTEX_4 OR SPELL_VORTEX_5
            if (InstanceScript* instance = caster->GetInstanceScript())
                instance->SetData(DATA_VORTEX_HANDLING, 0);

            // the rest of the vortex execution continues when SPELL_VORTEX_2 is removed.
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_malygos_vortex_dummy_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_malygos_vortex_dummy_SpellScript();
    }
};

class spell_malygos_vortex_visual : public SpellScriptLoader
{
    public:
        spell_malygos_vortex_visual() : SpellScriptLoader("spell_malygos_vortex_visual") { }

        class spell_malygos_vortex_visual_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_malygos_vortex_visual_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                {
                    std::list<HostileReference*> &m_threatlist = caster->getThreatManager().getThreatList();
                    for (std::list<HostileReference*>::const_iterator itr = m_threatlist.begin(); itr!= m_threatlist.end(); ++itr)
                    {
                        if (Unit* target = (*itr)->getTarget())
                        {
                            Player* targetPlayer = target->ToPlayer();

                            if (!targetPlayer || targetPlayer->isGameMaster())
                                continue;

                            if (InstanceScript* instance = caster->GetInstanceScript())
                            {
                                // teleport spell - i am not sure but might be it must be casted by each vehicle when its passenger leaves it
                                if (Creature* trigger = caster->GetMap()->GetCreature(instance->GetData64(DATA_TRIGGER)))
                                    trigger->CastSpell(targetPlayer, SPELL_VORTEX_6, true);
                            }
                        }
                    }

                    if (Creature* malygos = caster->ToCreature())
                    {
                        // This is a hack, we have to re add players to the threat list because when they enter to the vehicles they are removed.
                        // Anyway even with this issue, the boss does not enter in evade mode - this prevents iterate an empty list in the next vortex execution.
                        malygos->SetInCombatWithZone();

                        malygos->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);

                        malygos->GetMotionMaster()->MoveChase(caster->getVictim());
                        malygos->RemoveAura(SPELL_VORTEX_1);
                    }
                }

            }

            void Register()
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_malygos_vortex_visual_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_malygos_vortex_visual_AuraScript();
        }
};

class npc_portal_eoe: public CreatureScript
{
public:
    npc_portal_eoe() : CreatureScript("npc_portal_eoe") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_portal_eoeAI(creature);
    }

    struct npc_portal_eoeAI : public ScriptedAI
    {
        npc_portal_eoeAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        void Reset()
        {
            summonTimer = urand(5, 7)*IN_MILLISECONDS;
        }

        void UpdateAI(uint32 const diff)
        {
            if (!me->HasAura(SPELL_PORTAL_VISUAL_CLOSED) &&
                !me->HasAura(SPELL_PORTAL_OPENED))
                DoCast(me, SPELL_PORTAL_VISUAL_CLOSED, true);

            if (instance)
            {
                if (Creature* malygos = Unit::GetCreature(*me, instance->GetData64(DATA_MALYGOS)))
                {
                    if (malygos->AI()->GetData(DATA_PHASE) != PHASE_ONE)
                    {
                        me->RemoveAura(SPELL_PORTAL_OPENED);
                        DoCast(me, SPELL_PORTAL_VISUAL_CLOSED, true);
                    }
                }
            }

            if (!me->HasAura(SPELL_PORTAL_OPENED))
                return;

            if (summonTimer <= diff)
            {
                DoCast(SPELL_SUMMON_POWER_PARK);
                summonTimer = urand(5, 7)*IN_MILLISECONDS;
            } else summonTimer -= diff;
        }

        void JustSummoned(Creature* summon)
        {
            summon->SetInCombatWithZone();
        }

    private:
        uint32 summonTimer;
        InstanceScript* instance;
    };
};


class npc_power_spark: public CreatureScript
{
public:
    npc_power_spark() : CreatureScript("npc_power_spark") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_power_sparkAI(creature);
    }

    struct npc_power_sparkAI : public ScriptedAI
    {
        npc_power_sparkAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();

            MoveToMalygos();
        }

        void EnterEvadeMode()
        {
            me->DespawnOrUnsummon();
        }

        void MoveToMalygos()
        {
            me->GetMotionMaster()->MoveIdle();

            if (instance)
            {
                if (Creature* malygos = Unit::GetCreature(*me, instance->GetData64(DATA_MALYGOS)))
                    me->GetMotionMaster()->MoveFollow(malygos, 0.0f, 0.0f);
            }
        }

        void UpdateAI(uint32 const /*diff*/)
        {
            if (!instance)
                return;

            if (Creature* malygos = Unit::GetCreature(*me, instance->GetData64(DATA_MALYGOS)))
            {
                if (malygos->AI()->GetData(DATA_PHASE) != PHASE_ONE)
                {
                    me->DespawnOrUnsummon();
                    return;
                }

                if (malygos->HasAura(SPELL_VORTEX_1))
                {
                    me->GetMotionMaster()->MoveIdle();
                    return;
                }

                if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() != TARGETED_MOTION_TYPE)
                    me->GetMotionMaster()->MoveFollow(malygos, 0.0f, 0.0f);
            }
        }

        void DamageTaken(Unit* /*done_by*/, uint32& damage)
        {
            if (damage > me->GetMaxHealth())
            {
                damage = 0;
                DoCast(me, SPELL_POWER_SPARK_DEATH, true);
                me->DespawnOrUnsummon(1000);
            }
        }

    private:
        InstanceScript* instance;
    };
};

class npc_hover_disk : public CreatureScript
{
public:
    npc_hover_disk() : CreatureScript("npc_hover_disk") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_hover_diskAI(creature);
    }

    struct npc_hover_diskAI : public npc_escortAI
    {
        npc_hover_diskAI(Creature* creature) : npc_escortAI(creature)
        {
            if (me->GetEntry() == NPC_HOVER_DISK_CASTER)
                me->SetReactState(REACT_PASSIVE);
             else
                me->SetInCombatWithZone();

            instance = creature->GetInstanceScript();
        }

        void PassengerBoarded(Unit* unit, int8 /*seat*/, bool apply)
        {
            if (apply)
            {
                if (unit->GetTypeId() == TYPEID_UNIT)
                {
                    me->setFaction(FACTION_HOSTILE);
                    unit->ToCreature()->SetInCombatWithZone();
                }
            }
            else
            {
                // Error found: This is not called if the passenger is a player

                if (unit->GetTypeId() == TYPEID_UNIT)
                {
                    // This will only be called if the passenger dies
                    if (instance)
                    {
                        if (Creature* malygos = Unit::GetCreature(*me, instance->GetData64(DATA_MALYGOS)))
                            malygos->AI()->SetData(DATA_SUMMON_DEATHS, malygos->AI()->GetData(DATA_SUMMON_DEATHS)+1);
                    }

                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                }

                me->GetMotionMaster()->MoveIdle();

                if (me->GetEntry() == NPC_HOVER_DISK_MELEE)
                {
                    // Hack: Fall ground function can fail (remember the platform is a gameobject), we will teleport the disk to the ground
                    if (me->GetPositionZ() > GROUND_Z)
                        me->NearTeleportTo(me->GetPositionX(), me->GetPositionY(), GROUND_Z, 0);
                    me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
                    me->setFaction(FACTION_FRIENDLY);
                    me->AI()->EnterEvadeMode();
                }
            }
        }

        void EnterEvadeMode()
        {
            // we dont evade
        }

        void DoAction(int32 const action)
        {
            if (me->GetEntry() != NPC_HOVER_DISK_CASTER)
                return;

            switch (action)
            {
                case ACTION_HOVER_DISK_START_WP_1:
                    for (uint8 i = 0; i < MAX_HOVER_DISK_WAYPOINTS; i++)
                        AddWaypoint(i, HoverDiskWaypoints[i].GetPositionX(), HoverDiskWaypoints[i].GetPositionY(), HoverDiskWaypoints[i].GetPositionZ());
                    break;
                case ACTION_HOVER_DISK_START_WP_2:
                    {
                        uint8 count = 0;
                        for (uint8 i = MAX_HOVER_DISK_WAYPOINTS-1; i > 0; i--)
                        {
                            AddWaypoint(count, HoverDiskWaypoints[i].GetPositionX(), HoverDiskWaypoints[i].GetPositionY(), HoverDiskWaypoints[i].GetPositionZ());
                            count++;
                        }
                        break;
                    }
                default:
                    return;
            }

            Start(true, false, 0, 0, false, true);
        }

        void UpdateEscortAI(const uint32 /*diff*/)
        {
            // we dont do melee damage!
        }

        void WaypointReached(uint32 /*i*/)
        {
        }

    private:
        InstanceScript* instance;
    };
};


// The reason of this AI is to make the creature able to enter in combat otherwise the spell casting of SPELL_ARCANE_OVERLOAD fails.
class npc_arcane_overload : public CreatureScript
{
public:
    npc_arcane_overload() : CreatureScript("npc_arcane_overload") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_arcane_overloadAI (creature);
    }

    struct npc_arcane_overloadAI : public ScriptedAI
    {
        npc_arcane_overloadAI(Creature* creature) : ScriptedAI(creature) {}

        void AttackStart(Unit* who)
        {
            DoStartNoMovement(who);
        }

        void Reset()
        {
            DoCast(me, SPELL_ARCANE_OVERLOAD, false);
        }

        void UpdateAI(uint32 const /*diff*/)
        {
            // we dont do melee damage!
        }

    };
};

// SmartAI does not work correctly for this (vehicles)
class npc_wyrmrest_skytalon : public CreatureScript
{
public:
    npc_wyrmrest_skytalon() : CreatureScript("npc_wyrmrest_skytalon") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_wyrmrest_skytalonAI (creature);
    }

    struct npc_wyrmrest_skytalonAI : public NullCreatureAI
    {
        npc_wyrmrest_skytalonAI(Creature* creature) : NullCreatureAI(creature)
        {
            instance = creature->GetInstanceScript();

            timer = 1000;
            entered = false;
        }

        // we can't call this in reset function, it fails.
        void MakePlayerEnter()
        {
            if (!instance)
                return;

            if (Unit* summoner = me->ToTempSummon()->GetSummoner())
            {
                if (Creature* malygos = Unit::GetCreature(*me, instance->GetData64(DATA_MALYGOS)))
                {
                    summoner->CastSpell(me, SPELL_RIDE_RED_DRAGON, true);
                    float victim_threat = malygos->getThreatManager().getThreat(summoner);
                    malygos->getThreatManager().resetAllAggro();
                    malygos->AI()->AttackStart(me);
                    malygos->AddThreat(me, victim_threat);
                }
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!entered)
            {
                if (timer <= diff)
                {
                    MakePlayerEnter();
                    entered = true;
                } else timer -= diff;
            }
        }

    private:
        InstanceScript* instance;
        uint32 timer;
        bool entered;
    };
};

enum AlexstraszaYells
{
    SAY_ONE,
    SAY_TWO,
    SAY_THREE,
    SAY_FOUR
};

class npc_alexstrasza_eoe : public CreatureScript
{
public:
    npc_alexstrasza_eoe() : CreatureScript("npc_alexstrasza_eoe") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_alexstrasza_eoeAI (creature);
    }

    struct npc_alexstrasza_eoeAI : public ScriptedAI
    {
        npc_alexstrasza_eoeAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset()
        {
            events.Reset();

            events.ScheduleEvent(EVENT_YELL_1, 0);
        }

        void UpdateAI(uint32 const /*diff*/)
        {
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_YELL_1:
                        Talk(SAY_ONE);
                        events.ScheduleEvent(EVENT_YELL_2, 4*IN_MILLISECONDS);
                        break;
                    case EVENT_YELL_2:
                        Talk(SAY_TWO);
                        events.ScheduleEvent(EVENT_YELL_3, 4*IN_MILLISECONDS);
                        break;
                    case EVENT_YELL_3:
                        Talk(SAY_THREE);
                        events.ScheduleEvent(EVENT_YELL_4, 7*IN_MILLISECONDS);
                        break;
                    case EVENT_YELL_4:
                        Talk(SAY_FOUR);
                        break;
                }
            }
        }
    private:
        EventMap events;
    };
};

class achievement_denyin_the_scion : public AchievementCriteriaScript
{
    public:
        achievement_denyin_the_scion() : AchievementCriteriaScript("achievement_denyin_the_scion") { }

        bool OnCheck(Player* source, Unit* /*target*/)
        {
            if (Unit* disk = source->GetVehicleBase())
                if (disk->GetEntry() == NPC_HOVER_DISK_CASTER || disk->GetEntry() == NPC_HOVER_DISK_MELEE)
                    return true;
            return false;
        }
};

void AddSC_boss_malygos()
{
    new boss_malygos();
    new npc_portal_eoe();
    new npc_power_spark();
    new npc_hover_disk();
    new npc_arcane_overload();
    new npc_wyrmrest_skytalon();
    new spell_malygos_vortex_dummy();
    new spell_malygos_vortex_visual();
    new npc_alexstrasza_eoe();
    new achievement_denyin_the_scion();
}
