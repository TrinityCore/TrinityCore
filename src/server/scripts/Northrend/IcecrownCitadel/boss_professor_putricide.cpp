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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Group.h"
#include "Spell.h"
#include "icecrown_citadel.h"

enum ScriptTexts
{
    // Festergut
    SAY_FESTERGUT_GASEOUS_BLIGHT    = 0,
    SAY_FESTERGUT_DEATH             = 1,

    // Rotface
    SAY_ROTFACE_OOZE_FLOOD          = 2,
    SAY_ROTFACE_DEATH               = 3,

    // Professor Putricide
    SAY_AGGRO                       = 4,
    EMOTE_UNSTABLE_EXPERIMENT       = 5,
    SAY_PHASE_TRANSITION_HEROIC     = 6,
    SAY_TRANSFORM_1                 = 7,
    SAY_TRANSFORM_2                 = 8,    // always used for phase2 change, DO NOT GROUP WITH SAY_TRANSFORM_1
    EMOTE_MALLEABLE_GOO             = 9,
    EMOTE_CHOKING_GAS_BOMB          = 10,
    SAY_KILL                        = 11,
    SAY_BERSERK                     = 12,
    SAY_DEATH                       = 13,
};

enum Spells
{
    // Festergut
    SPELL_RELEASE_GAS_VISUAL            = 69125,
    SPELL_GASEOUS_BLIGHT_LARGE          = 69157,
    SPELL_GASEOUS_BLIGHT_MEDIUM         = 69162,
    SPELL_GASEOUS_BLIGHT_SMALL          = 69164,
    SPELL_MALLABLE_GOO_H                = 70852,

    // Rotface
    SPELL_VILE_GAS_H                    = 69240,

    // Professor Putricide
    SPELL_SLIME_PUDDLE_TRIGGER          = 70341,
    SPELL_MALLEABLE_GOO                 = 70852,
    SPELL_UNSTABLE_EXPERIMENT           = 70351,
    SPELL_TEAR_GAS                      = 71617,    // phase transition
    SPELL_TEAR_GAS_AURA_1               = 71615,
    SPELL_TEAR_GAS_AURA_2               = 71618,
    SPELL_CREATE_CONCOCTION             = 71621,
    SPELL_GUZZLE_POTIONS                = 71893,
    SPELL_OOZE_TANK_PROTECTION          = 71770,    // protects the tank
    SPELL_CHOKING_GAS_BOMB              = 71255,
    SPELL_OOZE_VARIABLE                 = 70352,
    SPELL_GAS_VARIABLE                  = 70353,
    SPELL_UNBOUND_PLAGUE                = 70911,
    SPELL_UNBOUND_PLAGUE_SEARCHER       = 70917,
    SPELL_PLAGUE_SICKNESS               = 70953,
    SPELL_UNBOUND_PLAGUE_PROTECTION     = 70955,
    SPELL_MUTATED_PLAGUE                = 72451,

    // Slime Puddle
    SPELL_GROW_STACKER                  = 70345,
    SPELL_SLIME_PUDDLE_AURA             = 70343,

    // Gas Cloud
    SPELL_GASEOUS_BLOAT_PROC            = 70215,
    SPELL_GASEOUS_BLOAT                 = 70672,
    SPELL_GASEOUS_BLOAT_PROTECTION      = 70812,

    // Volatile Ooze
    SPELL_OOZE_ERUPTION                 = 70492,
    SPELL_VOLATILE_OOZE_ADHESIVE        = 70447,
    SPELL_OOZE_ERUPTION_SEARCH_PERIODIC = 70457,
    SPELL_VOLATILE_OOZE_PROTECTION      = 70530,

    // Choking Gas Bomb
    SPELL_CHOKING_GAS_BOMB_PERIODIC     = 71259,
    SPELL_CHOKING_GAS_EXPLOSION_TRIGGER = 71280,

    // Mutated Abomination vehicle
    SPELL_ABOMINATION_VEHICLE_POWER_DRAIN = 70385,
    SPELL_MUTATED_TRANSFORMATION          = 70311,
    SPELL_MUTATED_TRANSFORMATION_DAMAGE   = 70405,
    SPELL_MUTATED_TRANSFORMATION_NAME     = 72401,
    SPELL_GROW_ABOMINATION                = 70347
};

#define SPELL_GASEOUS_BLOAT_HELPER RAID_MODE<uint32>(70672,72455,72832,72833)

enum Events
{
    // Festergut
    EVENT_FESTERGUT_DIES        = 1,
    EVENT_FESTERGUT_GOO         = 2,

    // Rotface
    EVENT_ROTFACE_DIES          = 3,
    EVENT_ROTFACE_VILE_GAS      = 4,

    // Professor Putricide
    EVENT_BERSERK               = 6,    // all phases
    EVENT_SLIME_PUDDLE          = 7,    // P1 && P2
    EVENT_UNSTABLE_EXPERIMENT   = 8,    // P1 && P2
    EVENT_TEAR_GAS              = 9,    // phase transition not heroic
    EVENT_RESUME_ATTACK         = 10,
    EVENT_MALLEABLE_GOO         = 11,
    EVENT_CHOKING_GAS_BOMB      = 12,
    EVENT_UNBOUND_PLAGUE        = 13,
    EVENT_MUTATED_PLAGUE        = 14,
    EVENT_PHASE_TRANSITION      = 15,
};

enum Phases
{
    PHASE_NONE          = 0,
    PHASE_FESTERGUT     = 1,
    PHASE_ROTFACE       = 2,
    PHASE_COMBAT_1      = 4,
    PHASE_COMBAT_2      = 5,
    PHASE_COMBAT_3      = 6,

    PHASE_MASK_COMBAT   = (1 << PHASE_COMBAT_1) | (1 << PHASE_COMBAT_2) | (1 << PHASE_COMBAT_3),
    PHASE_MASK_NOT_SELF = (1 << PHASE_FESTERGUT) | (1 << PHASE_ROTFACE),
};

enum Points
{
    POINT_FESTERGUT = 366260,
    POINT_ROTFACE   = 366270,
    POINT_TABLE     = 366780,
};

static const Position festergutWatchPos = {4324.820f, 3166.03f, 389.3831f, 3.316126f}; //emote 432 (release gas)
static const Position rotfaceWatchPos   = {4390.371f, 3164.50f, 389.3890f, 5.497787f}; //emote 432 (release ooze)
static const Position tablePos          = {4356.190f, 3262.90f, 389.4820f, 1.483530f};

static const uint32 oozeFloodSpells[4] = {69782, 69796, 69798, 69801};

enum PutricideData
{
    DATA_EXPERIMENT_STAGE   = 1,
    DATA_PHASE              = 2,
    DATA_ABOMINATION        = 3,
};

#define EXPERIMENT_STATE_OOZE   false
#define EXPERIMENT_STATE_GAS    true

class DeactivateValveEvent : public BasicEvent
{
    public:
        DeactivateValveEvent(uint32 valveData, InstanceScript* is): uiValveType(valveData), instance(is) { }

        bool Execute(uint64 /*eventTime*/, uint32 /*updateTime*/)
        {
            instance->SetData(uiValveType, FAIL);
            return true;
        }
    private:
        uint32 uiValveType;
        InstanceScript *instance;
};
class ActivateValveEvent : public BasicEvent
{
    public:
        ActivateValveEvent(uint32 valveData, InstanceScript* is, Unit *unit): uiValveType(valveData), instance(is), activator(unit) { }

        bool Execute(uint64 /*eventTime*/, uint32 /*updateTime*/)
        {
            instance->SetData(uiValveType, IN_PROGRESS);
            activator->m_Events.AddEvent(new DeactivateValveEvent(uiValveType, instance), activator->m_Events.CalculateTime(3000));
            return true;
        }
    private:
        Unit *activator;
        uint32 uiValveType;
        InstanceScript *instance;
};
class ActivateProfessorDoor : public BasicEvent
{
    public:
        ActivateProfessorDoor(InstanceScript* is, uint32 valveType, uint32 valveData): instance(is), uiValveType(valveType), uiValveData(valveData) { }

        bool Execute(uint64 /*eventTime*/, uint32 /*updateTime*/)
        {
            instance->SetData(uiValveType, uiValveData);
            return true;
        }
    private:
        uint32 uiValveType;
        uint32 uiValveData;
        InstanceScript *instance;
};
class go_icc_plagueworks_valve : public GameObjectScript
{
    public:
        go_icc_plagueworks_valve() : GameObjectScript("go_icc_plagueworks_valve") { }

        bool OnGossipHello(Player* player, GameObject* go)
        {
            InstanceScript* instance = go->GetInstanceScript(); 
            if(!instance)
                return false;
            if (instance->IsEncounterInProgress())
                return false;
            if (go->GetGoState() == GO_STATE_ACTIVE)
                return false;
            if (instance->GetData(DATA_ROTFACE_EVENT) != DONE || instance->GetData(DATA_FESTERGUT_EVENT) != DONE)
                return false;
            if (go->GetEntry() == GO_OOZE_VALVE)
            {
                if (Creature *pPutricide = go->GetMap()->GetCreature(instance->GetData64(GUID_PROFESSOR_PUTRICIDE)))
                    pPutricide->m_Events.AddEvent(new DeactivateValveEvent(DATA_OOZE_VALVE_ACTIVATED, instance), pPutricide->m_Events.CalculateTime(3000));
                instance->SetData(DATA_OOZE_VALVE_ACTIVATED, IN_PROGRESS);
            }
            else
            {
                if (Creature *pPutricide = go->GetMap()->GetCreature(instance->GetData64(GUID_PROFESSOR_PUTRICIDE)))
                    pPutricide->m_Events.AddEvent(new DeactivateValveEvent(DATA_GAS_VALVE_ACTIVATED, instance), pPutricide->m_Events.CalculateTime(3000));
                instance->SetData(DATA_GAS_VALVE_ACTIVATED, IN_PROGRESS);
            }
            //Prevent future usage of this valve
            go->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
            return true;
        }

};


class StartMovementEvent : public BasicEvent
{
    public:
        StartMovementEvent(Creature& owner) : BasicEvent(), m_owner(owner) { }
        bool Execute(uint64 /*eventTime*/, uint32 /*diff*/)
        {
            m_owner.GetMotionMaster()->MoveChase(m_owner.getVictim());
            return true;
        }

    private:
        Creature& m_owner;
};

class boss_professor_putricide : public CreatureScript
{
    public:
        boss_professor_putricide() : CreatureScript("boss_professor_putricide") { }

        struct boss_professor_putricideAI : public BossAI
        {
            boss_professor_putricideAI(Creature* creature) : BossAI(creature, GUID_PROFESSOR_PUTRICIDE),
                baseSpeed(creature->GetSpeedRate(MOVE_RUN)), experimentState(EXPERIMENT_STATE_OOZE)
            {
                phase = PHASE_NONE;
            }

            void InitializeAI()
            {
                if (!instance || static_cast<InstanceMap*>(me->GetMap())->GetScriptId() != GetScriptId(ICCScriptName))
                    me->IsAIEnabled = false;
                else if (!me->isDead())
                    Reset();
            }
            void Cleanup()
            {
                UnsummonSpecificCreaturesNearby(me, NPC_CHOKING_GAS_BOMB, 80.0f);
                UnsummonSpecificCreaturesNearby(me, NPC_GROWING_OOZE_PUDDLE, 80.0f);
                UnsummonSpecificCreaturesNearby(me, NPC_GAS_CLOUD, 80.0f);
                UnsummonSpecificCreaturesNearby(me, NPC_VOLATILE_OOZE, 80.0f);
                UnsummonSpecificCreaturesNearby(me, NPC_TEAR_GAS_TARGET_STALKER, 80.0f);
            }
            void Reset()
            {
                instance->SetData(DATA_NAUSEA_ACHIEVEMENT, uint32(true));

                events.Reset();
                summons.DespawnAll();
                _SetPhase(PHASE_COMBAT_1);
                experimentState = EXPERIMENT_STATE_OOZE;
                me->SetReactState(REACT_DEFENSIVE);
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == POINT_MOTION_TYPE)
                    me->GetMotionMaster()->MovementExpired();
                if (GameObject* table = ObjectAccessor::GetGameObject(*me, instance->GetData64(GUID_PUTRICIDE_TABLE)))
                    table->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                if (instance->GetData(DATA_ROTFACE_EVENT) == DONE && instance->GetData(DATA_FESTERGUT_EVENT) == DONE)
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);

            }

            void EnterCombat(Unit* who)
            {
                if (events.GetPhaseMask() & PHASE_MASK_NOT_SELF)
                    return;

                if (!(events.GetPhaseMask() & PHASE_MASK_NOT_SELF) && //!instance->CheckRequiredBosses(GUID_PROFESSOR_PUTRICIDE, who->ToPlayer())
                    (instance->GetData(DATA_FESTERGUT_EVENT) != DONE || instance->GetData(DATA_ROTFACE_EVENT) != DONE)
                    )
                {
                    instance->DoCastSpellOnPlayers(SPELL_TELEPORT_ICC_LIGHT_S_HAMMER);
                    EnterEvadeMode();
                    return;
                }

                _SetPhase(PHASE_COMBAT_1);
                Talk(SAY_AGGRO);
                DoCast(me, SPELL_OOZE_TANK_PROTECTION, true);
                DoZoneInCombat(me);

                events.Reset();
                events.ScheduleEvent(EVENT_BERSERK, 600000);
                events.ScheduleEvent(EVENT_SLIME_PUDDLE, 10000);
                events.ScheduleEvent(EVENT_UNSTABLE_EXPERIMENT, 30000);
                if (IsHeroic())
                    events.ScheduleEvent(EVENT_UNBOUND_PLAGUE, 20000);

                instance->SetBossState(GUID_PROFESSOR_PUTRICIDE, IN_PROGRESS);
                instance->SetData(DATA_PROFESSOR_PUTRICIDE_EVENT, IN_PROGRESS);
                if (GameObject* table = ObjectAccessor::GetGameObject(*me, instance->GetData64(GUID_PUTRICIDE_TABLE)))
                    table->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
            }

            void JustReachedHome()
            {
                Cleanup();
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                if (events.GetPhaseMask() & PHASE_MASK_COMBAT)
                {
                    instance->SetBossState(GUID_PROFESSOR_PUTRICIDE, FAIL);
                    instance->SetData(DATA_PROFESSOR_PUTRICIDE_EVENT, FAIL);
                }
                if (GameObject* table = ObjectAccessor::GetGameObject(*me, instance->GetData64(GUID_PUTRICIDE_TABLE)))
                    table->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MUTATED_PLAGUE);
                Cleanup();
            }

            void KilledUnit(Unit* victim)
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void JustDied(Unit* /*killer*/)
            {
                Talk(SAY_DEATH);
                instance->SetBossState(GUID_PROFESSOR_PUTRICIDE, DONE);
                instance->SetData(DATA_PROFESSOR_PUTRICIDE_EVENT, DONE);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MUTATED_PLAGUE);
                Cleanup();
            }
            void SummonAddDueToUnstableExperiment(uint32 entry, WorldObject *target)
            {
                DoSummon(entry, target);
            }
            void JustSummoned(Creature* summon)
            {
                summons.Summon(summon);
                switch (summon->GetEntry())
                {
                    case NPC_GROWING_OOZE_PUDDLE:
                        summon->CastSpell(summon, SPELL_GROW_STACKER, true);
                        summon->CastSpell(summon, SPELL_SLIME_PUDDLE_AURA, true);
                        break;
                    case NPC_GAS_CLOUD:
                        // no possible aura seen in sniff adding the aurastate
                        summon->SetFlag(UNIT_FIELD_AURASTATE, 1 << (AURA_STATE_UNKNOWN22-1));
                        summon->CastSpell(summon, SPELL_GASEOUS_BLOAT_PROC, true);
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true, -SPELL_GASEOUS_BLOAT_PROTECTION))
                        {
                            summon->AI()->AttackStart(target);
                            summon->CastCustomSpell(SPELL_GASEOUS_BLOAT, SPELLVALUE_MAX_TARGETS, 1, target, false);
                            summon->ClearUnitState(UNIT_STAT_CASTING);
                            summon->GetMotionMaster()->MoveIdle();
                            summon->m_Events.AddEvent(new StartMovementEvent(*summon), summon->m_Events.CalculateTime(3500));
                            //Slow down them a little bit
                            summon->SetSpeed(MOVE_RUN, summon->GetSpeedRate(MOVE_RUN) * 0.8f);
                            summon->SetSpeed(MOVE_WALK, summon->GetSpeedRate(MOVE_WALK) * 0.8f);
                        }
                        return;
                    case NPC_VOLATILE_OOZE:
                        // no possible aura seen in sniff adding the aurastate
                        summon->SetFlag(UNIT_FIELD_AURASTATE, 1 << (AURA_STATE_UNKNOWN19-1));
                        summon->CastSpell(summon, SPELL_OOZE_ERUPTION_SEARCH_PERIODIC, true);
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true, -SPELL_VOLATILE_OOZE_PROTECTION))
                        {
                            summon->AI()->AttackStart(target);
                            summon->CastCustomSpell(SPELL_VOLATILE_OOZE_ADHESIVE, SPELLVALUE_MAX_TARGETS, 1, target, false);
                            summon->ClearUnitState(UNIT_STAT_CASTING);
                            summon->GetMotionMaster()->MoveIdle();
                            summon->m_Events.AddEvent(new StartMovementEvent(*summon), summon->m_Events.CalculateTime(3500));
                            //Slow down them a little bit
                            summon->SetSpeed(MOVE_RUN, summon->GetSpeedRate(MOVE_RUN) * 0.8f);
                            summon->SetSpeed(MOVE_WALK, summon->GetSpeedRate(MOVE_WALK) * 0.8f);
                        }
                        return;
                    case NPC_CHOKING_GAS_BOMB:
                        summon->CastSpell(summon, SPELL_CHOKING_GAS_BOMB_PERIODIC, true);
                        summon->CastSpell(summon, SPELL_CHOKING_GAS_EXPLOSION_TRIGGER, true);
                        return;
                    default:
                        break;
                }
                if (me->isInCombat())
                    DoZoneInCombat(summon);
            }

            void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/)
            {
                switch (phase)
                {
                    case PHASE_COMBAT_1:
                        if (HealthAbovePct(80))
                            return;
                        me->SetReactState(REACT_PASSIVE);
                        DoAction(ACTION_CHANGE_PHASE);
                        break;
                    case PHASE_COMBAT_2:
                        if (HealthAbovePct(35))
                            return;
                        me->SetReactState(REACT_PASSIVE);
                        DoAction(ACTION_CHANGE_PHASE);
                        break;
                    default:
                        break;
                }
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type != POINT_MOTION_TYPE)
                    return;
                switch (id)
                {
                    case POINT_FESTERGUT:
                        instance->SetBossState(DATA_FESTERGUT_EVENT, IN_PROGRESS); // needed here for delayed gate close
                        instance->SetData(DATA_FESTERGUT_EVENT, IN_PROGRESS);
                        me->SetSpeed(MOVE_RUN, baseSpeed, true);
                        //DoAction(ACTION_FESTERGUT_GAS);
                        //if (Creature* festergut = Unit::GetCreature(*me, instance->GetData64(GUID_FESTERGUT)))
                        //    festergut->CastSpell(festergut, SPELL_GASEOUS_BLIGHT_LARGE, false, NULL, NULL, festergut->GetGUID());
                        break;
                    case POINT_ROTFACE:
                        instance->SetBossState(DATA_ROTFACE_EVENT, IN_PROGRESS);   // needed here for delayed gate close
                        instance->SetData(DATA_ROTFACE_EVENT, IN_PROGRESS);
                        me->SetSpeed(MOVE_RUN, baseSpeed, true);
                        break;
                    case POINT_TABLE:
                        // stop attack
                        me->GetMotionMaster()->MoveIdle();
                        me->SetSpeed(MOVE_RUN, baseSpeed, true);
                        if (GameObject* table = ObjectAccessor::GetGameObject(*me, instance->GetData64(GUID_PUTRICIDE_TABLE)))
                            me->SetFacingToObject(table);
                        // operating on new phase already
                        switch (phase)
                        {
                            case PHASE_COMBAT_2:
                            {
                                SpellEntry const* spell = sSpellStore.LookupEntry(SPELL_CREATE_CONCOCTION);
                                spell = sSpellMgr->GetSpellForDifficultyFromSpell(spell, me);
                                DoCast(me, SPELL_CREATE_CONCOCTION);
                                events.ScheduleEvent(EVENT_PHASE_TRANSITION, GetSpellCastTime(spell)+100);
                                break;
                            }
                            case PHASE_COMBAT_3:
                            {
                                SpellEntry const* spell = sSpellStore.LookupEntry(SPELL_GUZZLE_POTIONS);
                                spell = sSpellMgr->GetSpellForDifficultyFromSpell(spell, me);
                                DoCast(me, SPELL_GUZZLE_POTIONS);
                                events.ScheduleEvent(EVENT_PHASE_TRANSITION, GetSpellCastTime(spell)+100);
                                break;
                            }
                            default:
                                break;
                        }
                        break;
                    default:
                        break;
                }
            }

            void DoAction(const int32 action)
            {
                switch (action)
                {
                    case ACTION_FESTERGUT_COMBAT:
                        _SetPhase(PHASE_FESTERGUT);
                        me->SetSpeed(MOVE_RUN, baseSpeed*2.0f, true);
                        me->GetMotionMaster()->MovePoint(POINT_FESTERGUT, festergutWatchPos);
                        me->SetReactState(REACT_PASSIVE);
                        if (IsHeroic())
                        {
                            DoZoneInCombat(me);
                            events.ScheduleEvent(EVENT_FESTERGUT_GOO, urand(15000, 20000), 0, PHASE_FESTERGUT);
                        }
                        break;
                    case ACTION_FESTERGUT_GAS:
                        Talk(SAY_FESTERGUT_GASEOUS_BLIGHT);
                        DoCast(me, SPELL_RELEASE_GAS_VISUAL, true);
                        break;
                    case ACTION_FESTERGUT_DEATH:
                        events.ScheduleEvent(EVENT_FESTERGUT_DIES, 4000, 0, PHASE_FESTERGUT);
                        break;
                    case ACTION_ROTFACE_COMBAT:
                    {
                        _SetPhase(PHASE_ROTFACE);
                        me->SetSpeed(MOVE_RUN, baseSpeed*2.0f, true);
                        me->GetMotionMaster()->MovePoint(POINT_ROTFACE, rotfaceWatchPos);
                        me->SetReactState(REACT_PASSIVE);
                        oozeFloodStage = 0;
                        if (IsHeroic())
                        {
                            DoZoneInCombat(me);
                            events.ScheduleEvent(EVENT_ROTFACE_VILE_GAS, urand(15000, 20000), 0, PHASE_ROTFACE);
                        }
                        break;
                    }
                        break;
                    case ACTION_ROTFACE_DEATH:
                        events.ScheduleEvent(EVENT_ROTFACE_DIES, 4500, 0, PHASE_ROTFACE);
                        break;
                    case ACTION_CHANGE_PHASE:
                        me->SetSpeed(MOVE_RUN, baseSpeed*2.0f, true);
                        events.DelayEvents(30000);
                        me->AttackStop();
                        if (!IsHeroic())
                        {
                            DoCast(me, SPELL_TEAR_GAS);
                            events.ScheduleEvent(EVENT_TEAR_GAS, 2500);
                        }
                        else
                        {
                            Talk(SAY_PHASE_TRANSITION_HEROIC);
                            DoCast(me, SPELL_UNSTABLE_EXPERIMENT, true);
                            DoCast(me, SPELL_UNSTABLE_EXPERIMENT, true);
                            // cast variables
                            if (Is25ManRaid())
                            {
                                std::list<Unit*> targetList;
                                {
                                    const std::list<HostileReference*>& threatlist = me->getThreatManager().getThreatList();
                                    for (std::list<HostileReference*>::const_iterator itr = threatlist.begin(); itr != threatlist.end(); ++itr)
                                        if ((*itr)->getTarget()->GetTypeId() == TYPEID_PLAYER)
                                            targetList.push_back((*itr)->getTarget());
                                }

                                size_t half = targetList.size()/2;
                                // half gets ooze variable
                                while (half < targetList.size())
                                {
                                    std::list<Unit*>::iterator itr = targetList.begin();
                                    advance(itr, urand(0, targetList.size()-1));
                                    DoCast(*itr, SPELL_OOZE_VARIABLE);
                                    targetList.erase(itr);
                                }
                                // and half gets gas
                                for (std::list<Unit*>::iterator itr = targetList.begin(); itr != targetList.end(); ++itr)
                                    DoCast(*itr, SPELL_GAS_VARIABLE);
                            }
                            me->GetMotionMaster()->MovePoint(POINT_TABLE, tablePos);
                        }
                        switch (phase)
                        {
                            case PHASE_COMBAT_1:
                                _SetPhase(PHASE_COMBAT_2);
                                events.ScheduleEvent(EVENT_MALLEABLE_GOO, urand(21000, 26000));
                                events.ScheduleEvent(EVENT_CHOKING_GAS_BOMB, urand(35000, 40000));
                                break;
                            case PHASE_COMBAT_2:
                                _SetPhase(PHASE_COMBAT_3);
                                events.ScheduleEvent(EVENT_MUTATED_PLAGUE, 25000);
                                events.CancelEvent(EVENT_UNSTABLE_EXPERIMENT);
                                events.CancelEvent(EVENT_SLIME_PUDDLE);
                                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MUTATED_TRANSFORMATION);
                                instance->DoRemoveAurasDueToSpellOnPlayers(71503);  // SPELL_MUTATED_TRANSFORMATION2
                                if (GameObject* table = ObjectAccessor::GetGameObject(*me, instance->GetData64(GUID_PUTRICIDE_TABLE)))
                                    table->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                                break;
                            default:
                                break;
                        }
                        break;
                    case ACTION_ACTIVATE_ORANGE_DOOR:
                        me->m_Events.AddEvent(new ActivateProfessorDoor(instance, DATA_GAS_VALVE_ACTIVATED, DONE), me->m_Events.CalculateTime(8000));
                        break;
                    case ACTION_ACTIVATE_GREEN_DOOR:
                        me->m_Events.AddEvent(new ActivateProfessorDoor(instance, DATA_OOZE_VALVE_ACTIVATED, DONE), me->m_Events.CalculateTime(8000));
                        break;
                    case ACTION_OPEN_DOORS:
                        me->m_Events.AddEvent(new ActivateProfessorDoor(instance, DATA_OOZE_VALVE_ACTIVATED, SPECIAL), me->m_Events.CalculateTime(5000));
                        break;
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 type)
            {
                switch (type)
                {
                    case DATA_EXPERIMENT_STAGE:
                    {
                        // ALSO MODIFIES!
                        uint32 ret = uint32(experimentState);
                        experimentState ^= true;
                        return ret;
                    }
                    case DATA_PHASE:
                        return phase;
                    case DATA_ABOMINATION:
                        summons.RemoveNotExisting();    
                        return summons.HasEntry(NPC_MUTATED_ABOMINATION_10) || summons.HasEntry(NPC_MUTATED_ABOMINATION_25);
                    default:
                        break;
                }
                return 0;
            }

            void UpdateAI(const uint32 diff)
            {
                if ((!UpdateVictim() && !(events.GetPhaseMask() & PHASE_MASK_NOT_SELF)) || !CheckInRoom())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FESTERGUT_DIES:
                            Talk(SAY_FESTERGUT_DEATH);
                            EnterEvadeMode();
                            break;
                        case EVENT_FESTERGUT_GOO:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                                DoCast(target, SPELL_MALLABLE_GOO_H, true); // triggered, to skip LoS check
                            events.ScheduleEvent(EVENT_FESTERGUT_GOO, urand(15000, 20000), 0, PHASE_FESTERGUT);
                            break;
                        case EVENT_ROTFACE_DIES:
                            Talk(SAY_ROTFACE_DEATH);
                            EnterEvadeMode();
                            break;
                        case EVENT_ROTFACE_VILE_GAS:
                        if (Creature* rotface = Unit::GetCreature(*me, instance->GetData64(GUID_ROTFACE)))
                            if (rotface->isAlive())
                            {
                                std::list<Unit*> targetList;
                                uint32 minTargets = RAID_MODE<uint32>(3, 8, 3, 8);
                                rotface->AI()->SelectTargetList(targetList, minTargets, SELECT_TARGET_RANDOM, -5.0f, true);
                                Unit* target;
                                if (targetList.size() >= minTargets)
                                {
                                    std::list<Unit*>::iterator itr = targetList.begin();
                                    advance(itr, urand(0, targetList.size()-1));;
                                    target = *itr;
                                }
                                else
                                    target = rotface->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 200.0f, true);
                                if (target)
                                    DoCast(target, SPELL_VILE_GAS_H, true); // triggered, to skip LoS check
                            }
                            events.ScheduleEvent(EVENT_ROTFACE_VILE_GAS, urand(15000, 20000), 0, PHASE_ROTFACE);
                            break;
                        case EVENT_BERSERK:
                            Talk(SAY_BERSERK);
                            DoCast(me, SPELL_BERSERK2);
                            break;
                        case EVENT_SLIME_PUDDLE:
                        {
                            std::list<Unit*> targets;
                            SelectTargetList(targets, 2, SELECT_TARGET_RANDOM, 0.0f, true);
                            if (!targets.empty())
                                for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                                    DoCast(*itr, SPELL_SLIME_PUDDLE_TRIGGER);
                            events.ScheduleEvent(EVENT_SLIME_PUDDLE, 35000);
                            break;
                        }
                        case EVENT_UNSTABLE_EXPERIMENT:
                            Talk(EMOTE_UNSTABLE_EXPERIMENT);
                            DoCast(me, SPELL_UNSTABLE_EXPERIMENT);
                            events.ScheduleEvent(EVENT_UNSTABLE_EXPERIMENT, urand(35000, 40000));
                            break;
                        case EVENT_TEAR_GAS:
                            me->GetMotionMaster()->MovePoint(POINT_TABLE, tablePos);
                            break;
                        case EVENT_RESUME_ATTACK:
                            me->SetReactState(REACT_DEFENSIVE);
                            AttackStart(me->getVictim());
                            // remove Tear Gas
                            for (std::list<uint64>::const_iterator itr = summons.begin(); itr != summons.end(); ++itr)
                            {
                                Creature *minion = Unit::GetCreature(*me, *itr);
                                if (minion && minion->isAlive() )
                                { 
                                    minion->RemoveAurasDueToSpell(SPELL_TEAR_GAS_AURA_1);
                                    minion->RemoveAurasDueToSpell(SPELL_TEAR_GAS_AURA_2);
                                }
                            }
                            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TEAR_GAS_AURA_1);
                            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TEAR_GAS_AURA_2);
                            break;
                        case EVENT_MALLEABLE_GOO:
                            if (Is25ManRaid())
                            {
                                std::list<Unit*> targets;
                                SelectTargetList(targets, 2, SELECT_TARGET_RANDOM, -7.0f, true);
                                if (!targets.empty())
                                {
                                    Talk(EMOTE_MALLEABLE_GOO);
                                    for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                                        DoCast(*itr, SPELL_MALLEABLE_GOO);
                                }
                            }
                            else
                            {
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, -7.0f, true))
                                {
                                    Talk(EMOTE_MALLEABLE_GOO);
                                    DoCast(target, SPELL_MALLEABLE_GOO);
                                }
                            }
                            events.ScheduleEvent(EVENT_MALLEABLE_GOO, urand(25000, 30000));
                            break;
                        case EVENT_CHOKING_GAS_BOMB:
                            Talk(EMOTE_CHOKING_GAS_BOMB);
                            DoCast(me, SPELL_CHOKING_GAS_BOMB);
                            events.ScheduleEvent(EVENT_CHOKING_GAS_BOMB, urand(35000, 40000));
                            break;
                        case EVENT_UNBOUND_PLAGUE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                            {
                                me->CastCustomSpell(SPELL_UNBOUND_PLAGUE, SPELLVALUE_BASE_POINT0, 775, target);
                                DoCast(target, SPELL_UNBOUND_PLAGUE_SEARCHER);
                            }
                            events.ScheduleEvent(EVENT_UNBOUND_PLAGUE, 90000);
                            break;
                        case EVENT_MUTATED_PLAGUE:
                            DoCastVictim(SPELL_MUTATED_PLAGUE);
                            events.ScheduleEvent(EVENT_MUTATED_PLAGUE, urand(10000, 12000));
                            break;
                        case EVENT_PHASE_TRANSITION:
                        {
                            switch (phase)
                            {
                                case PHASE_COMBAT_2:
                                    if (Creature* face = me->FindNearestCreature(NPC_TEAR_GAS_TARGET_STALKER, 50.0f))
                                        me->SetFacingToObject(face);
                                    me->HandleEmoteCommand(EMOTE_ONESHOT_KNEEL);
                                    Talk(SAY_TRANSFORM_1);
                                    events.ScheduleEvent(EVENT_RESUME_ATTACK, 5500, 0, PHASE_COMBAT_2);
                                    break;
                                case PHASE_COMBAT_3:
                                    if (Creature* face = me->FindNearestCreature(NPC_TEAR_GAS_TARGET_STALKER, 50.0f))
                                        me->SetFacingToObject(face);
                                    me->HandleEmoteCommand(EMOTE_ONESHOT_KNEEL);
                                    Talk(SAY_TRANSFORM_2);
                                    events.ScheduleEvent(EVENT_RESUME_ATTACK, 8500, 0, PHASE_COMBAT_3);
                                    break;
                                default:
                                    break;
                            }
                        }
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            void _SetPhase(Phases newPhase)
            {
                phase = newPhase;
                events.SetPhase(newPhase);
            }

            uint64 oozeFloodDummy[4];
            Phases phase;          // external of EventMap because event phase gets reset on evade
            const float baseSpeed;
            uint8 oozeFloodStage;
            bool experimentState;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_professor_putricideAI(creature);
        }
};

class npc_volatile_ooze : public CreatureScript
{
    public:
        npc_volatile_ooze() : CreatureScript("npc_volatile_ooze") { }

        struct npc_volatile_oozeAI : public ScriptedAI
        {
            npc_volatile_oozeAI(Creature* creature) : ScriptedAI(creature)
            {
                newTargetSelectTimer = 0;
            }

            void SpellHitTarget(Unit* /*target*/, SpellEntry const* spell)
            {
                SpellEntry const* explode = sSpellStore.LookupEntry(SPELL_OOZE_ERUPTION);
                explode = sSpellMgr->GetSpellForDifficultyFromSpell(explode, me);
                if (explode->Id == spell->Id)
                {
                    newTargetSelectTimer = 5000;
                    DoStartNoMovement(me);
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (!newTargetSelectTimer)
                    return;

                if (newTargetSelectTimer <= diff)
                {
                    newTargetSelectTimer = 0;
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true, -SPELL_VOLATILE_OOZE_PROTECTION))
                    {
                        AttackStart(target);
                        me->CastCustomSpell(SPELL_VOLATILE_OOZE_ADHESIVE, SPELLVALUE_MAX_TARGETS, 1, target, false);
                    }
                    else
                        me->DespawnOrUnsummon();
                }
                else
                    newTargetSelectTimer -= diff;
            }

        private:
            // no need to use EventMap for just one event
            uint32 newTargetSelectTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_volatile_oozeAI(creature);
        }
};

class spell_putricide_gaseous_bloat : public SpellScriptLoader
{
    public:
        spell_putricide_gaseous_bloat() : SpellScriptLoader("spell_putricide_gaseous_bloat") { }

        class spell_putricide_gaseous_bloat_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_putricide_gaseous_bloat_SpellScript);

            void ModAuraStack()
            {
                if (Aura* aur = GetHitAura())
                    aur->SetStackAmount(10);
            }

            void Register()
            {
                AfterHit += SpellHitFn(spell_putricide_gaseous_bloat_SpellScript::ModAuraStack);
            }
        };

        class spell_putricide_gaseous_bloat_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_putricide_gaseous_bloat_AuraScript);

            void HandleExtraEffect(AuraEffect const* /*aurEff*/)
            {
                 GetTarget()->RemoveAuraFromStack(GetSpellProto()->Id, GetCasterGUID());
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_putricide_gaseous_bloat_AuraScript::HandleExtraEffect, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_putricide_gaseous_bloat_SpellScript();
        }

        AuraScript* GetAuraScript() const
        {
            return new spell_putricide_gaseous_bloat_AuraScript();
        }
};

class spell_putricide_expunged_gas : public SpellScriptLoader
{
    public:
        spell_putricide_expunged_gas() : SpellScriptLoader("spell_putricide_expunged_gas") { }

        class spell_putricide_expunged_gas_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_putricide_expunged_gas_SpellScript);

            void CalcDamage(SpellEffIndex /*effIndex*/)
            {
                if (GetCaster()->GetTypeId() != TYPEID_UNIT)
                    return;

                InstanceScript* instance = GetCaster()->GetInstanceScript();
                if (!instance)
                    return;

                Creature* professor = Unit::GetCreature(*GetCaster(), instance->GetData64(GUID_PROFESSOR_PUTRICIDE));
                if (!professor)
                    return;

                int32 dmg = 0;
                ScriptedAI* professorAI = CAST_AI(ScriptedAI, professor->AI());
                if (Aura* gasBloat = GetTargetUnit()->GetAura(professorAI->SPELL_GASEOUS_BLOAT_HELPER))
                {
                    uint32 stack = gasBloat->GetStackAmount();
                    const int32 mod = professorAI->Is25ManRaid() ? 1500 : 1250;
                    for (uint8 i = 1; i < stack; ++i)
                        dmg += mod * stack;
                }
                else
                    GetCaster()->ToCreature()->DespawnOrUnsummon();

                SetHitDamage(dmg);
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_putricide_expunged_gas_SpellScript::CalcDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_putricide_expunged_gas_SpellScript();
        }
};

class spell_putricide_slime_puddle : public SpellScriptLoader
{
    public:
        spell_putricide_slime_puddle() : SpellScriptLoader("spell_putricide_slime_puddle") { }

        class spell_putricide_slime_puddle_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_putricide_slime_puddle_AuraScript);

            void HandleTriggerSpell(AuraEffect const* aurEff)
            {
                PreventDefaultAction();
                if (Unit* caster = GetCaster())
                {
                    int32 radiusMod = 4;
                    //if (Aura* size = caster->GetAura(SPELL_GROW_ABOMINATION))
                    //{
                    //    radiusMod += size->GetStackAmount();
                    //    size->SetStackAmount(1);
                    //    size->Remove();
                    //}
                    if(Aura *pAura = caster->GetAura(SPELL_GROW_STACKER))
                        if (pAura->GetStackAmount() > 20)
                            pAura->SetStackAmount(20);
                    uint32 triggerSpellId = GetSpellProto()->EffectTriggerSpell[aurEff->GetEffIndex()];
                    caster->CastCustomSpell(triggerSpellId, SPELLVALUE_RADIUS_MOD, radiusMod*100, caster, true);
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_putricide_slime_puddle_AuraScript::HandleTriggerSpell, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_putricide_slime_puddle_AuraScript();
        }
};

class spell_putricide_unstable_experiment : public SpellScriptLoader
{
    public:
        spell_putricide_unstable_experiment() : SpellScriptLoader("spell_putricide_unstable_experiment") { }

        class spell_putricide_unstable_experiment_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_putricide_unstable_experiment_SpellScript);

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                if (GetCaster()->GetTypeId() != TYPEID_UNIT)
                    return;

                uint32 stage = GetCaster()->ToCreature()->AI()->GetData(DATA_EXPERIMENT_STAGE);
                Creature* target = NULL;
                std::list<Creature*> creList;
                GetCreatureListWithEntryInGrid(creList, GetCaster(), NPC_ABOMINATION_WING_MAD_SCIENTIST_STALKER, 100.0f);
                // 2 of them are spawned at green place - weird trick blizz
                for (std::list<Creature*>::iterator itr = creList.begin(); itr != creList.end(); ++itr)
                {
                    target = *itr;
                    std::list<Creature*> tmp;
                    GetCreatureListWithEntryInGrid(tmp, target, NPC_ABOMINATION_WING_MAD_SCIENTIST_STALKER, 1.0f);
                    if ((!stage && tmp.size() > 1) || (stage && tmp.size() == 1))
                        break;
                }

                GetCaster()->CastSpell(target, uint32(GetSpellInfo()->EffectBasePoints[stage]+1), true, NULL, NULL, GetCaster()->GetGUID());
                ((boss_professor_putricide::boss_professor_putricideAI*)GetCaster()->ToCreature()->AI())->SummonAddDueToUnstableExperiment(stage ? NPC_VOLATILE_OOZE : NPC_GAS_CLOUD, target);
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_putricide_unstable_experiment_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_putricide_unstable_experiment_SpellScript();
        }
};

class spell_putricide_ooze_summon : public SpellScriptLoader
{
    public:
        spell_putricide_ooze_summon() : SpellScriptLoader("spell_putricide_ooze_summon") { }

        class spell_putricide_ooze_summon_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_putricide_ooze_summon_AuraScript);

            void HandleTriggerSpell(AuraEffect const* aurEff)
            {
                PreventDefaultAction();
                if (Unit* caster = GetCaster())
                {
                    uint32 triggerSpellId = GetSpellProto()->EffectTriggerSpell[aurEff->GetEffIndex()];
                    float x, y, z;
                    GetTarget()->GetPosition(x, y, z);
                    z = GetTarget()->GetMap()->GetHeight(x, y, z, true, 25.0f);
                    x += 10.0f * cosf(caster->GetOrientation());
                    y += 10.0f * sinf(caster->GetOrientation());
                    caster->CastSpell(x, y, z, triggerSpellId, true, NULL, NULL, GetCasterGUID(), caster);
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_putricide_ooze_summon_AuraScript::HandleTriggerSpell, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_putricide_ooze_summon_AuraScript();
        }
};

class spell_putricide_ooze_eruption_searcher : public SpellScriptLoader
{
    public:
        spell_putricide_ooze_eruption_searcher() : SpellScriptLoader("spell_putricide_ooze_eruption_searcher") { }

        class spell_putricide_ooze_eruption_searcher_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_putricide_ooze_eruption_searcher_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                SpellEntry const* adhesive = sSpellStore.LookupEntry(SPELL_VOLATILE_OOZE_ADHESIVE);
                adhesive = sSpellMgr->GetSpellForDifficultyFromSpell(adhesive, GetCaster());
                if (GetHitUnit()->HasAura(adhesive->Id))
                {
                    GetCaster()->CastSpell(GetHitUnit(), SPELL_OOZE_ERUPTION, true);
                    GetHitUnit()->RemoveAurasDueToSpell(adhesive->Id, GetCaster()->GetGUID());
                }
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_putricide_ooze_eruption_searcher_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_putricide_ooze_eruption_searcher_SpellScript();
        }
};

class spell_putricide_choking_gas_bomb : public SpellScriptLoader
{
    public:
        spell_putricide_choking_gas_bomb() : SpellScriptLoader("spell_putricide_choking_gas_bomb") { }

        class spell_putricide_choking_gas_bomb_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_putricide_choking_gas_bomb_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                uint32 skipIndex = urand(0, 2);
                for (uint32 i = 0; i < 3; ++i)
                {
                    if (i == skipIndex)
                        continue;

                    uint32 spellId = uint32(SpellMgr::CalculateSpellEffectAmount(GetSpellInfo(), uint8(i)));
                    GetCaster()->CastSpell(GetCaster(), spellId, true, NULL, NULL, GetCaster()->GetGUID());
                }
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_putricide_choking_gas_bomb_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_putricide_choking_gas_bomb_SpellScript();
        }
};

class spell_putricide_unbound_plague : public SpellScriptLoader
{
    public:
        spell_putricide_unbound_plague() : SpellScriptLoader("spell_putricide_unbound_plague") { }

        class spell_putricide_unbound_plague_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_putricide_unbound_plague_SpellScript);

            bool Validate(SpellEntry const* /*spell*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_UNBOUND_PLAGUE))
                    return false;
                if (!sSpellStore.LookupEntry(SPELL_UNBOUND_PLAGUE_SEARCHER))
                    return false;
                return true;
            }
            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (!GetHitUnit())
                    return;

                SpellEntry const* plague = sSpellStore.LookupEntry(SPELL_UNBOUND_PLAGUE);
                SpellEntry const* searcher = sSpellStore.LookupEntry(SPELL_UNBOUND_PLAGUE_SEARCHER);
                Creature* professor = NULL;
                if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                {
                    professor = Unit::GetCreature(*GetCaster(), instance->GetData64(GUID_PROFESSOR_PUTRICIDE));
                    if (professor)
                    {
                        plague = sSpellMgr->GetSpellForDifficultyFromSpell(plague, professor);
                        searcher = sSpellMgr->GetSpellForDifficultyFromSpell(searcher, professor);
                    }
                }

                if (!GetHitUnit()->HasAura(plague->Id))
                {
                    if (professor)
                        if (Aura* oldPlague = GetCaster()->GetAura(plague->Id, professor->GetGUID()))
                            if (Aura* newPlague = professor->AddAura(plague->Id, GetHitUnit()))
                            {
                                newPlague->SetMaxDuration(oldPlague->GetDuration());
                                newPlague->SetDuration(oldPlague->GetDuration());
                                oldPlague->Remove();
                                GetCaster()->RemoveAurasDueToSpell(searcher->Id);
                                GetCaster()->CastSpell(GetCaster(), SPELL_PLAGUE_SICKNESS, true);
                                GetCaster()->CastSpell(GetCaster(), SPELL_UNBOUND_PLAGUE_PROTECTION, true);
                                professor->CastSpell(GetHitUnit(), SPELL_UNBOUND_PLAGUE_SEARCHER, true);
                            }
                }
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_putricide_unbound_plague_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_putricide_unbound_plague_SpellScript();
        }
};

class spell_putricide_eat_ooze : public SpellScriptLoader
{
    public:
        spell_putricide_eat_ooze() : SpellScriptLoader("spell_putricide_eat_ooze") { }

        class spell_putricide_eat_ooze_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_putricide_eat_ooze_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (Creature* target = GetCaster()->FindNearestCreature(NPC_GROWING_OOZE_PUDDLE, 15.0f))
                {
                    if (Aura* grow = target->GetAura(uint32(GetEffectValue())))
                    {
                        if (grow->GetStackAmount() > 8)
                            grow->ModStackAmount(-4);
                        else if (grow->GetStackAmount() > 4)
                            grow->SetStackAmount(4);
                        else if (grow->GetStackAmount() > 2)
                            grow->SetStackAmount(2);
                        else
                        {
                            target->RemoveAurasDueToSpell(SPELL_GROW_STACKER);
                            target->RemoveAura(grow);
                            target->DespawnOrUnsummon();
                        }
                    }
                    //Remove Abomination's Grow effect
                    GetCaster()->RemoveAurasDueToSpell(70347);
                    GetCaster()->RemoveAurasDueToSpell(70344);
                    GetCaster()->RemoveAurasDueToSpell(70343);
                }
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_putricide_eat_ooze_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_putricide_eat_ooze_SpellScript();
        }
};

class spell_putricide_mutated_plague : public SpellScriptLoader
{
    public:
        spell_putricide_mutated_plague() : SpellScriptLoader("spell_putricide_mutated_plague") { }

        class spell_putricide_mutated_plague_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_putricide_mutated_plague_AuraScript);

            void HandleTriggerSpell(AuraEffect const* aurEff)
            {
                PreventDefaultAction();
                Unit* caster = GetCaster();
                if (!caster)
                    return;

                uint32 triggerSpell = GetSpellProto()->EffectTriggerSpell[aurEff->GetEffIndex()];
                SpellEntry const* spell = sSpellStore.LookupEntry(triggerSpell);
                spell = sSpellMgr->GetSpellForDifficultyFromSpell(spell, caster);

                int32 damage = SpellMgr::CalculateSpellEffectAmount(spell, 0, caster);
                float multiplier = 2.0f;
                if (GetTarget()->GetMap()->GetSpawnMode() & 1)
                    multiplier = 3.0f;

                damage *= int32(pow(multiplier, GetStackAmount()));
                damage = int32(damage * 1.5f);

                GetTarget()->CastCustomSpell(triggerSpell, SPELLVALUE_BASE_POINT0, damage, GetTarget(), true, NULL, aurEff, GetCasterGUID());
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_STACK)
                    return;
                uint32 healSpell = uint32(SpellMgr::CalculateSpellEffectAmount(GetSpellProto(), 0));
                GetTarget()->CastSpell(GetTarget(), healSpell, true, NULL, NULL, GetCasterGUID());
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_putricide_mutated_plague_AuraScript::HandleTriggerSpell, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
                OnEffectRemove += AuraEffectRemoveFn(spell_putricide_mutated_plague_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_putricide_mutated_plague_AuraScript();
        }
};

class spell_putricide_mutation_init : public SpellScriptLoader
{
    public:
        spell_putricide_mutation_init() : SpellScriptLoader("spell_putricide_mutation_init") { }


        class spell_putricide_mutation_init_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_putricide_mutation_init_SpellScript);

            SpellCastResult CheckRequirementInternal(SpellCustomErrors& extendedError)
            {
                InstanceScript* instance = GetTargetUnit()->GetInstanceScript();
                if (!instance)
                    return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

                Creature* professor = ObjectAccessor::GetCreature(*GetTargetUnit(), instance->GetData64(GUID_PROFESSOR_PUTRICIDE));
                if (!professor)

                    return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

                if (professor->AI()->GetData(DATA_PHASE) == PHASE_COMBAT_3 || !professor->isAlive())
                {
                    extendedError = SPELL_CUSTOM_ERROR_ALL_POTIONS_USED;
                    return SPELL_FAILED_CUSTOM_ERROR;
                }

                if (professor->AI()->GetData(DATA_ABOMINATION))
                {
                    extendedError = SPELL_CUSTOM_ERROR_TOO_MANY_ABOMINATIONS;
                    return SPELL_FAILED_CUSTOM_ERROR;
                }

                return SPELL_CAST_OK;
            }

            SpellCastResult CheckRequirement()
            {
                if (!GetTargetUnit())
                    return SPELL_FAILED_BAD_TARGETS;

                if (GetTargetUnit()->GetTypeId() != TYPEID_PLAYER)
                    return SPELL_FAILED_TARGET_NOT_PLAYER;

                SpellCustomErrors extension = SPELL_CUSTOM_ERROR_NONE;
                SpellCastResult result = CheckRequirementInternal(extension);
                if (result != SPELL_CAST_OK)
                {
                    Spell::SendCastResult(GetTargetUnit()->ToPlayer(), GetSpellInfo(), 0, result, extension);
                    return result;
                }

                return SPELL_CAST_OK;
            }

            void Register()
            {
                OnCheckCast += SpellCheckCastFn(spell_putricide_mutation_init_SpellScript::CheckRequirement);
            }
        };

        class spell_putricide_mutation_init_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_putricide_mutation_init_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (InstanceScript* instance = GetTarget()->GetInstanceScript())
                    if (GameObject* table = ObjectAccessor::GetGameObject(*GetTarget(), instance->GetData64(GUID_PUTRICIDE_TABLE)))
                        table->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                uint32 spellId = 70311;
                if (GetTarget()->GetMap()->GetSpawnMode() & 1)
                    spellId = 71503;

                GetTarget()->CastSpell(GetTarget(), spellId, true);
            }

            void Register()
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_putricide_mutation_init_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        SpellScript* GetSpellScript() const
        {    
            return new spell_putricide_mutation_init_SpellScript();
        }

        AuraScript* GetAuraScript() const
        {
            return new spell_putricide_mutation_init_AuraScript();
        }
};

class spell_putricide_mutated_transformation_dismiss : public SpellScriptLoader
{
    public:
        spell_putricide_mutated_transformation_dismiss() : SpellScriptLoader("spell_putricide_mutated_transformation_dismiss") { }

        class spell_putricide_mutated_transformation_dismiss_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_putricide_mutated_transformation_dismiss_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Vehicle* veh = GetTarget()->GetVehicleKit())
                    veh->RemoveAllPassengers();
                if (InstanceScript* instance = GetTarget()->GetInstanceScript())
                {
                    if (GameObject* table = ObjectAccessor::GetGameObject(*GetTarget(), instance->GetData64(GUID_PUTRICIDE_TABLE)))
                        table->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                }
            }

            void Register()
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_putricide_mutated_transformation_dismiss_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_putricide_mutated_transformation_dismiss_AuraScript();
        }
};

class spell_putricide_mutated_transformation : public SpellScriptLoader
{
    public:
        spell_putricide_mutated_transformation() : SpellScriptLoader("spell_putricide_mutated_transformation") { }

        class spell_putricide_mutated_transformation_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_putricide_mutated_transformation_SpellScript);

            void HandleSummon(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                Unit* caster = GetOriginalCaster();
                if (!caster)
                    return;

                InstanceScript* instance = GetTargetUnit()->GetInstanceScript();
                if (!instance)
                    return;

                Creature* putricide = ObjectAccessor::GetCreature(*GetTargetUnit(), instance->GetData64(GUID_PROFESSOR_PUTRICIDE));
                if (!putricide)
                    return;

                if (putricide->AI()->GetData(DATA_ABOMINATION))
                {
                    if (Player* plrCaster = caster->ToPlayer())
                        Spell::SendCastResult(plrCaster, GetSpellInfo(), 0, SPELL_FAILED_CUSTOM_ERROR, SPELL_CUSTOM_ERROR_TOO_MANY_ABOMINATIONS);
                    return;
                }

                uint32 entry = uint32(GetSpellInfo()->EffectMiscValue[effIndex]);
                SummonPropertiesEntry const* properties = sSummonPropertiesStore.LookupEntry(uint32(GetSpellInfo()->EffectMiscValueB[effIndex]));
                uint32 duration = uint32(GetSpellDuration(GetSpellInfo()));

                Position pos;
                caster->GetPosition(&pos);
                TempSummon* summon = caster->GetMap()->SummonCreature(entry, pos, properties, duration, caster);
                if (!summon || !summon->IsVehicle())
                    return;
                //Disallow abomination's growth
                summon->ApplySpellImmune(SPELL_GROW_ABOMINATION, IMMUNITY_ID, SPELL_GROW_ABOMINATION, true);
                caster->CastSpell(summon, SPELL_MUTATED_TRANSFORMATION_NAME, true);
                summon->CastSpell(summon, SPELL_ABOMINATION_VEHICLE_POWER_DRAIN, true);
                summon->CastSpell(summon, SPELL_MUTATED_TRANSFORMATION_DAMAGE, true);
                caster->EnterVehicle(summon, 0);

                summon->SetUInt32Value(UNIT_CREATED_BY_SPELL, GetSpellInfo()->Id);
                summon->SetCreatorGUID(caster->GetGUID());

                putricide->AI()->JustSummoned(summon);
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_putricide_mutated_transformation_SpellScript::HandleSummon, EFFECT_0, SPELL_EFFECT_SUMMON);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_putricide_mutated_transformation_SpellScript();
        }
};


class spell_putricide_regurgitated_ooze : public SpellScriptLoader
{
    public:
        spell_putricide_regurgitated_ooze() : SpellScriptLoader("spell_putricide_regurgitated_ooze") { }

        class spell_putricide_regurgitated_ooze_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_putricide_regurgitated_ooze_SpellScript);

            // the only purpose of this hook is to fail the achievement
            void ExtraEffect(SpellEffIndex /*effIndex*/)
            {
                if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                    instance->SetData(DATA_NAUSEA_ACHIEVEMENT, uint32(false));
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_putricide_regurgitated_ooze_SpellScript::ExtraEffect, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_putricide_regurgitated_ooze_SpellScript();
        }
};

// Stinky and Precious spell, it's here because its used for both (Festergut and Rotface "pets")
class spell_stinky_precious_decimate : public SpellScriptLoader
{
    public:
        spell_stinky_precious_decimate() : SpellScriptLoader("spell_stinky_precious_decimate") { }

        class spell_stinky_precious_decimate_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_stinky_precious_decimate_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (GetHitUnit()->GetHealthPct() > float(GetEffectValue()))
                {
                    uint32 newHealth = GetHitUnit()->GetMaxHealth() * uint32(GetEffectValue()) / 100;
                    if (GetHitUnit()->GetMaxHealth() >= newHealth)
                        GetHitUnit()->SetHealth(newHealth);
                }
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_stinky_precious_decimate_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_stinky_precious_decimate_SpellScript();
        }
};
class npc_blighted_abomination : public CreatureScript
{
    enum eEvents
    {
        EVENT_CLEAVE = 1,
        EVENT_PLAGUE_CLOUD,
        EVENT_SCOURGE_HOOK
    };
    enum eSpells
    {
        SPELL_CLEAVE        = 40504,
        SPELL_PLAGUE_CLOUD    = 71150,
        SPELL_SCOURGE_HOOK    = 71140
    };

public:
    npc_blighted_abomination() : CreatureScript("npc_blighted_abomination") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_blighted_abominationAI (pCreature);
    }

    struct npc_blighted_abominationAI : public ScriptedAI
    {
        npc_blighted_abominationAI(Creature *c) : ScriptedAI(c)
        {
            instance = me->GetInstanceScript();
        }

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.Reset();
            events.ScheduleEvent(EVENT_SCOURGE_HOOK, 1000);
            events.ScheduleEvent(EVENT_CLEAVE, 15000);
            events.ScheduleEvent(EVENT_PLAGUE_CLOUD, 15000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;
            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;
            events.Update(diff);
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CLEAVE: 
                    {
                        DoCast(me->getVictim(), SPELL_CLEAVE);
                        events.ScheduleEvent(EVENT_CLEAVE, 8000);
                        break;
                    }
                    case EVENT_PLAGUE_CLOUD:  
                    {
                        DoCast(SPELL_PLAGUE_CLOUD);
                        events.ScheduleEvent(EVENT_PLAGUE_CLOUD, 20000);
                        break;
                    }
                    case EVENT_SCOURGE_HOOK:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, -8.0f, true))
                            DoCast(target, SPELL_SCOURGE_HOOK);
                        events.ScheduleEvent(EVENT_SCOURGE_HOOK, 20000);
                        break;
                    }
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    private:
        InstanceScript *instance;
        EventMap events;
    };

};

class npc_plague_scientist : public CreatureScript
{
    enum eEvents
    {
        EVENT_COMBOBULATING_SPRAY = 1,
        EVENT_PLAGUE_BLAST,
        EVENT_PLAGUE_STREAM 
    };
    enum eSpells
    {
        SPELL_COMBOBULATING_SPRAY  = 71103,
        SPELL_PLAGUE_BLAST         = 73079,
        SPELL_PLAGUE_STREAM        = 69871
    };

public:
    npc_plague_scientist() : CreatureScript("npc_plague_scientist") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_plague_scientistAI (pCreature);
    }

    struct npc_plague_scientistAI : public ScriptedAI
    {
        npc_plague_scientistAI(Creature *c) : ScriptedAI(c)
        {
            instance = me->GetInstanceScript();
        }

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.Reset();
            events.ScheduleEvent(EVENT_COMBOBULATING_SPRAY, 1000);
            events.ScheduleEvent(EVENT_PLAGUE_BLAST, 100);
            events.ScheduleEvent(EVENT_PLAGUE_STREAM, 15000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;
            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;
            events.Update(diff);
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_COMBOBULATING_SPRAY: 
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, -5.0f, true))
                            DoCast(target, SPELL_COMBOBULATING_SPRAY);
                        events.ScheduleEvent(EVENT_COMBOBULATING_SPRAY, 40000);
                        break;
                    }
                    case EVENT_PLAGUE_BLAST:  
                    {
                        DoCast(me->getVictim(), SPELL_PLAGUE_BLAST);
                        events.ScheduleEvent(EVENT_PLAGUE_BLAST, 11000);
                        break;
                    }
                    case EVENT_PLAGUE_STREAM:
                    {
                        DoCast(SPELL_PLAGUE_STREAM);
                        events.ScheduleEvent(EVENT_PLAGUE_STREAM, 40000);
                        break;
                    }
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
        private:
            InstanceScript *instance;
            EventMap events;
    };
};

class npc_decaying_colossus : public CreatureScript
{
    enum eEvents
    {
        EVENT_MASSIVE_STOMP = 1,
        
    };
    enum eSpells
    {
        SPELL_MASSIVE_STOMP_10  = 71114,
        SPELL_MASSIVE_STOMP_25  = 71115,
    };

public:
    npc_decaying_colossus() : CreatureScript("npc_decaying_colossus") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_decaying_colossusAI (pCreature);
    }

    struct npc_decaying_colossusAI : public ScriptedAI
    {
        npc_decaying_colossusAI(Creature *c) : ScriptedAI(c)
        {
            instance = me->GetInstanceScript();
        }

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.Reset();
            events.ScheduleEvent(EVENT_MASSIVE_STOMP, 1000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;
            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;
            events.Update(diff);
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_MASSIVE_STOMP: 
                    {
                        DoCast(RAID_MODE(SPELL_MASSIVE_STOMP_10, SPELL_MASSIVE_STOMP_25, SPELL_MASSIVE_STOMP_10, SPELL_MASSIVE_STOMP_25));
                        events.ScheduleEvent(EVENT_MASSIVE_STOMP, 20000);
                        break;
                    }
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
        private:
            InstanceScript *instance;
            EventMap events;
    };
};

class npc_pustulating_horror : public CreatureScript 
{
    enum eEvents
    {
        EVENT_BUBBLING_PUS = 1, 
    };
    enum eSpells
    {
        SPELL_BUBBLING_PUS_10  = 71089,
        SPELL_BUBBLING_PUS_25  = 71090,
        SPELL_BLIGHT_BOMB       = 71088,
    };

public:
    npc_pustulating_horror() : CreatureScript("npc_pustulating_horror") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_pustulating_horrorAI (pCreature);
    }

    struct npc_pustulating_horrorAI : public ScriptedAI
    {
        npc_pustulating_horrorAI(Creature *c) : ScriptedAI(c)
        {
            instance = me->GetInstanceScript();
        }

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.Reset();
            events.ScheduleEvent(EVENT_BUBBLING_PUS, 1000);
        }

        void DamageTaken(Unit* , uint32& )
        {
            if(HealthBelowPct(15))
                DoCast(me, SPELL_BLIGHT_BOMB);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;
            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;
            events.Update(diff);
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_BUBBLING_PUS: 
                    {
                        DoCast(RAID_MODE(SPELL_BUBBLING_PUS_10, SPELL_BUBBLING_PUS_25, SPELL_BUBBLING_PUS_10, SPELL_BUBBLING_PUS_25));
                        events.ScheduleEvent(EVENT_BUBBLING_PUS, 20000);
                        break;
                    }
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
        private:
            InstanceScript *instance;
            EventMap events;
    };
};
 
void AddSC_boss_professor_putricide()
{
    new boss_professor_putricide();
    new npc_volatile_ooze();
    new spell_putricide_gaseous_bloat();
    new spell_putricide_expunged_gas();
    new spell_putricide_slime_puddle();
    new spell_putricide_unstable_experiment();
    new spell_putricide_ooze_summon();
    new spell_putricide_ooze_eruption_searcher();
    new spell_putricide_choking_gas_bomb();
    new spell_putricide_unbound_plague();
    new spell_putricide_eat_ooze();
    new spell_putricide_mutated_plague();
    new spell_putricide_mutation_init();
    new spell_putricide_mutated_transformation_dismiss();
    new spell_putricide_mutated_transformation();
    new spell_putricide_regurgitated_ooze();
    new spell_stinky_precious_decimate();
    new go_icc_plagueworks_valve();
    new npc_blighted_abomination();
    new npc_plague_scientist();
    new npc_decaying_colossus();
    new npc_pustulating_horror();
}
