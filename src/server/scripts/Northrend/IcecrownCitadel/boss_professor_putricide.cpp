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

#include "icecrown_citadel.h"
#include "Containers.h"
#include "DB2Stores.h"
#include "GridNotifiers.h"
#include "Group.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "Vehicle.h"

enum Say
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
    SAY_DEATH                       = 13
};

enum Spells
{
    // Festergut
    SPELL_RELEASE_GAS_VISUAL                = 69125,
    SPELL_GASEOUS_BLIGHT_LARGE              = 69157,
    SPELL_GASEOUS_BLIGHT_MEDIUM             = 69162,
    SPELL_GASEOUS_BLIGHT_SMALL              = 69164,
    SPELL_MALLEABLE_GOO_H                   = 72296,
    SPELL_MALLEABLE_GOO_SUMMON              = 72299,

    // Professor Putricide
    SPELL_SLIME_PUDDLE_TRIGGER              = 70341,
    SPELL_MALLEABLE_GOO                     = 70852,
    SPELL_UNSTABLE_EXPERIMENT               = 70351,
    SPELL_TEAR_GAS                          = 71617,    // phase transition
    SPELL_TEAR_GAS_TRIGGER_MISSILE          = 71615,
    SPELL_TEAR_GAS_CREATURE                 = 71618,
    SPELL_TEAR_GAS_CANCEL                   = 71620,
    SPELL_TEAR_GAS_PERIODIC_TRIGGER         = 73170,
    SPELL_CREATE_CONCOCTION                 = 71621,
    SPELL_GUZZLE_POTIONS                    = 71893,
    SPELL_OOZE_TANK_PROTECTION              = 71770,    // protects the tank
    SPELL_CHOKING_GAS_BOMB                  = 71255,
    SPELL_OOZE_VARIABLE                     = 70352,
    SPELL_GAS_VARIABLE                      = 70353,
    SPELL_UNBOUND_PLAGUE                    = 70911,
    SPELL_UNBOUND_PLAGUE_SEARCHER           = 70917,
    SPELL_PLAGUE_SICKNESS                   = 70953,
    SPELL_UNBOUND_PLAGUE_PROTECTION         = 70955,
    SPELL_MUTATED_PLAGUE                    = 72451,
    SPELL_MUTATED_PLAGUE_CLEAR              = 72618,

    // Slime Puddle
    SPELL_GROW_STACKER                      = 70345,
    SPELL_GROW                              = 70347,
    SPELL_SLIME_PUDDLE_AURA                 = 70343,

    // Gas Cloud
    SPELL_GASEOUS_BLOAT_PROC                = 70215,
    SPELL_GASEOUS_BLOAT                     = 70672,
    SPELL_GASEOUS_BLOAT_PROTECTION          = 70812,
    SPELL_EXPUNGED_GAS                      = 70701,

    // Volatile Ooze
    SPELL_OOZE_ERUPTION                     = 70492,
    SPELL_VOLATILE_OOZE_ADHESIVE            = 70447,
    SPELL_OOZE_ERUPTION_SEARCH_PERIODIC     = 70457,
    SPELL_VOLATILE_OOZE_PROTECTION          = 70530,

    // Choking Gas Bomb
    SPELL_CHOKING_GAS_BOMB_PERIODIC         = 71259,
    SPELL_CHOKING_GAS_EXPLOSION_TRIGGER     = 71280,

    // Mutated Abomination vehicle
    SPELL_ABOMINATION_VEHICLE_POWER_DRAIN   = 70385,
    SPELL_MUTATED_TRANSFORMATION            = 70311,
    SPELL_MUTATED_TRANSFORMATION_DAMAGE     = 70405,
    SPELL_MUTATED_TRANSFORMATION_NAME       = 72401,

    // Unholy Infusion
    SPELL_UNHOLY_INFUSION_CREDIT            = 71518
};

enum Events
{
    // Festergut
    EVENT_FESTERGUT_DIES        = 1,
    EVENT_FESTERGUT_GOO         = 2,

    // Rotface
    EVENT_ROTFACE_DIES          = 3,
    EVENT_ROTFACE_OOZE_FLOOD    = 5,

    // Professor Putricide
    EVENT_BERSERK               = 6,    // all phases
    EVENT_SLIME_PUDDLE          = 7,    // all phases
    EVENT_UNSTABLE_EXPERIMENT   = 8,    // P1 && P2
    EVENT_TEAR_GAS              = 9,    // phase transition not heroic
    EVENT_RESUME_ATTACK         = 10,
    EVENT_MALLEABLE_GOO         = 11,
    EVENT_CHOKING_GAS_BOMB      = 12,
    EVENT_UNBOUND_PLAGUE        = 13,
    EVENT_MUTATED_PLAGUE        = 14,
    EVENT_PHASE_TRANSITION      = 15
};

enum Phases
{
    PHASE_NONE          = 0,
    PHASE_FESTERGUT     = 1,
    PHASE_ROTFACE       = 2,
    PHASE_COMBAT_1      = 4,
    PHASE_COMBAT_2      = 5,
    PHASE_COMBAT_3      = 6
};

enum Points
{
    POINT_FESTERGUT = 366260,
    POINT_ROTFACE   = 366270,
    POINT_TABLE     = 366780
};

Position const festergutWatchPos = {4324.820f, 3166.03f, 389.3831f, 3.316126f}; //emote 432 (release gas)
Position const rotfaceWatchPos   = {4390.371f, 3164.50f, 389.3890f, 5.497787f}; //emote 432 (release ooze)
Position const tablePos          = {4356.190f, 3262.90f, 389.4820f, 1.483530f};

// used in Rotface encounter
uint32 const oozeFloodSpells[4] = {69782, 69796, 69798, 69801};

enum PutricideData
{
    DATA_EXPERIMENT_STAGE   = 1,
    DATA_PHASE              = 2,
    DATA_ABOMINATION        = 3
};

#define EXPERIMENT_STATE_OOZE   false
#define EXPERIMENT_STATE_GAS    true

class AbominationDespawner
{
    public:
        explicit AbominationDespawner(Unit* owner) : _owner(owner) { }

        bool operator()(ObjectGuid guid)
        {
            if (Unit* summon = ObjectAccessor::GetUnit(*_owner, guid))
            {
                if (summon->GetEntry() == NPC_MUTATED_ABOMINATION_10 || summon->GetEntry() == NPC_MUTATED_ABOMINATION_25)
                {
                    if (Vehicle* veh = summon->GetVehicleKit())
                        veh->RemoveAllPassengers(); // also despawns the vehicle

                    // Found unit is Mutated Abomination, remove it
                    return true;
                }

                // Found unit is not Mutated Abomintaion, leave it
                return false;
            }

            // No unit found, remove from SummonList
            return true;
        }

    private:
        Unit* _owner;
};

struct RotfaceHeightCheck
{
    RotfaceHeightCheck(Creature* rotface) : _rotface(rotface) { }

    bool operator()(Creature* stalker) const
    {
        return stalker->GetPositionZ() < _rotface->GetPositionZ() + 5.0f;
    }

private:
    Creature* _rotface;
};

struct boss_professor_putricide : public BossAI
{
    boss_professor_putricide(Creature* creature) : BossAI(creature, DATA_PROFESSOR_PUTRICIDE),
        _baseSpeed(creature->GetSpeedRate(MOVE_RUN)), _experimentState(EXPERIMENT_STATE_OOZE)
    {
        _phase = PHASE_NONE;
        _oozeFloodStage = 0;
    }

    void Reset() override
    {
        if (!(events.IsInPhase(PHASE_ROTFACE) || events.IsInPhase(PHASE_FESTERGUT)))
            instance->SetBossState(DATA_PROFESSOR_PUTRICIDE, NOT_STARTED);
        instance->SetData(DATA_NAUSEA_ACHIEVEMENT, uint32(true));

        events.Reset();
        summons.DespawnAll();
        SetPhase(PHASE_COMBAT_1);
        _experimentState = EXPERIMENT_STATE_OOZE;
        me->SetReactState(REACT_DEFENSIVE);
        me->SetWalk(false);

        if (instance->GetBossState(DATA_ROTFACE) == DONE && instance->GetBossState(DATA_FESTERGUT) == DONE)
        {
            me->SetUninteractible(false);
            me->SetImmuneToPC(false);
        }
    }

    void JustEngagedWith(Unit* who) override
    {
        if (events.IsInPhase(PHASE_ROTFACE) || events.IsInPhase(PHASE_FESTERGUT))
            return;

        if (!instance->CheckRequiredBosses(DATA_PROFESSOR_PUTRICIDE, who->ToPlayer()))
        {
            EnterEvadeMode();
            instance->DoCastSpellOnPlayers(LIGHT_S_HAMMER_TELEPORT);
            return;
        }

        me->setActive(true);
        events.Reset();
        events.ScheduleEvent(EVENT_BERSERK, 10min);
        events.ScheduleEvent(EVENT_SLIME_PUDDLE, 10s);
        events.ScheduleEvent(EVENT_UNSTABLE_EXPERIMENT, 30s, 35s);
        if (IsHeroic())
            events.ScheduleEvent(EVENT_UNBOUND_PLAGUE, 20s);

        SetPhase(PHASE_COMBAT_1);
        Talk(SAY_AGGRO);
        DoCast(me, SPELL_OOZE_TANK_PROTECTION, true);
        DoZoneInCombat(me);
        instance->SetBossState(DATA_PROFESSOR_PUTRICIDE, IN_PROGRESS);
    }

    void JustReachedHome() override
    {
        _JustReachedHome();
        me->SetWalk(false);
        if (events.IsInPhase(PHASE_COMBAT_1) || events.IsInPhase(PHASE_COMBAT_2) || events.IsInPhase(PHASE_COMBAT_3))
            instance->SetBossState(DATA_PROFESSOR_PUTRICIDE, FAIL);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_KILL);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);

        if (Is25ManRaid() && me->HasAura(SPELL_SHADOWS_FATE))
            DoCastAOE(SPELL_UNHOLY_INFUSION_CREDIT, true);

        DoCast(SPELL_MUTATED_PLAGUE_CLEAR);
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);
        switch (summon->GetEntry())
        {
            case NPC_MALLEABLE_OOZE_STALKER:
                DoCast(summon, SPELL_MALLEABLE_GOO_H);
                return;
            case NPC_GROWING_OOZE_PUDDLE:
                summon->CastSpell(summon, SPELL_GROW_STACKER, true);
                summon->CastSpell(summon, SPELL_SLIME_PUDDLE_AURA, true);
                // blizzard casts this spell 7 times initially (confirmed in sniff)
                for (uint8 i = 0; i < 7; ++i)
                    summon->CastSpell(summon, SPELL_GROW, true);
                break;
            case NPC_GAS_CLOUD:
                // no possible aura seen in sniff adding the aurastate
                summon->ModifyAuraState(AURA_STATE_RAID_ENCOUNTER, true);
                summon->SetReactState(REACT_PASSIVE);
                break;
            case NPC_VOLATILE_OOZE:
                // no possible aura seen in sniff adding the aurastate
                summon->ModifyAuraState(AURA_STATE_VULNERABLE, true);
                summon->SetReactState(REACT_PASSIVE);
                break;
            case NPC_CHOKING_GAS_BOMB:
                summon->CastSpell(summon, SPELL_CHOKING_GAS_BOMB_PERIODIC, true);
                summon->CastSpell(summon, SPELL_CHOKING_GAS_EXPLOSION_TRIGGER, true);
                return;
            case NPC_MUTATED_ABOMINATION_10:
            case NPC_MUTATED_ABOMINATION_25:
                return;
            default:
                break;
        }

        if (me->IsInCombat())
            DoZoneInCombat(summon);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        switch (_phase)
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

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;
        switch (id)
        {
            case POINT_FESTERGUT:
                instance->SetBossState(DATA_FESTERGUT, IN_PROGRESS); // needed here for delayed gate close
                me->SetSpeedRate(MOVE_RUN, _baseSpeed);
                DoAction(ACTION_FESTERGUT_GAS);
                if (Creature* festergut = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_FESTERGUT)))
                    festergut->CastSpell(festergut, SPELL_GASEOUS_BLIGHT_LARGE, CastSpellExtraArgs().SetOriginalCaster(festergut->GetGUID()));
                break;
            case POINT_ROTFACE:
                instance->SetBossState(DATA_ROTFACE, IN_PROGRESS);   // needed here for delayed gate close
                me->SetSpeedRate(MOVE_RUN, _baseSpeed);
                DoAction(ACTION_ROTFACE_OOZE);
                events.ScheduleEvent(EVENT_ROTFACE_OOZE_FLOOD, 25s, 0, PHASE_ROTFACE);
                break;
            case POINT_TABLE:
                // stop attack
                me->GetMotionMaster()->MoveIdle();
                me->SetSpeedRate(MOVE_RUN, _baseSpeed);
                if (GameObject* table = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_PUTRICIDE_TABLE)))
                    me->SetFacingToObject(table);
                // operating on new phase already
                switch (_phase)
                {
                    case PHASE_COMBAT_2:
                    {
                        SpellInfo const* spell = sSpellMgr->GetSpellInfo(SPELL_CREATE_CONCOCTION, GetDifficulty());
                        DoCast(me, SPELL_CREATE_CONCOCTION);
                        events.ScheduleEvent(EVENT_PHASE_TRANSITION, Milliseconds(spell->CalcCastTime()) + 100ms);
                        break;
                    }
                    case PHASE_COMBAT_3:
                    {
                        SpellInfo const* spell = sSpellMgr->GetSpellInfo(SPELL_GUZZLE_POTIONS, GetDifficulty());
                        DoCast(me, SPELL_GUZZLE_POTIONS);
                        events.ScheduleEvent(EVENT_PHASE_TRANSITION, Milliseconds(spell->CalcCastTime()) + 100ms);
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

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_FESTERGUT_COMBAT:
                SetPhase(PHASE_FESTERGUT);
                me->SetSpeedRate(MOVE_RUN, _baseSpeed*2.0f);
                me->GetMotionMaster()->MovePoint(POINT_FESTERGUT, festergutWatchPos);
                me->SetReactState(REACT_PASSIVE);
                EngagementStart(nullptr);
                if (IsHeroic())
                    events.ScheduleEvent(EVENT_FESTERGUT_GOO, 13s, 18s, 0, PHASE_FESTERGUT);
                break;
            case ACTION_FESTERGUT_GAS:
                Talk(SAY_FESTERGUT_GASEOUS_BLIGHT);
                DoCast(me, SPELL_RELEASE_GAS_VISUAL, true);
                break;
            case ACTION_FESTERGUT_DEATH:
                events.ScheduleEvent(EVENT_FESTERGUT_DIES, 4s, 0, PHASE_FESTERGUT);
                break;
            case ACTION_ROTFACE_COMBAT:
                SetPhase(PHASE_ROTFACE);
                me->SetSpeedRate(MOVE_RUN, _baseSpeed*2.0f);
                me->GetMotionMaster()->MovePoint(POINT_ROTFACE, rotfaceWatchPos);
                me->SetReactState(REACT_PASSIVE);
                EngagementStart(nullptr);
                _oozeFloodStage = 0;
                // init random sequence of floods
                if (Creature* rotface = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ROTFACE)))
                {
                    std::list<Creature*> list;
                    GetCreatureListWithEntryInGrid(list, rotface, NPC_PUDDLE_STALKER, 50.0f);
                    list.remove_if(RotfaceHeightCheck(rotface));
                    if (list.size() > 4)
                    {
                        list.sort(Trinity::ObjectDistanceOrderPred(rotface));
                        do
                        {
                            list.pop_back();
                        } while (list.size() > 4);
                    }

                    uint8 i = 0;
                    while (!list.empty())
                    {
                        std::list<Creature*>::iterator itr = list.begin();
                        std::advance(itr, urand(0, list.size()-1));
                        _oozeFloodDummyGUIDs[i++] = (*itr)->GetGUID();
                        list.erase(itr);
                    }
                }
                break;
            case ACTION_ROTFACE_OOZE:
                Talk(SAY_ROTFACE_OOZE_FLOOD);
                if (Creature* dummy = ObjectAccessor::GetCreature(*me, _oozeFloodDummyGUIDs[_oozeFloodStage]))
                    dummy->CastSpell(dummy, oozeFloodSpells[_oozeFloodStage], CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                        .SetOriginalCaster(me->GetGUID())); // cast from self for LoS (with prof's GUID for logs)
                if (++_oozeFloodStage == 4)
                    _oozeFloodStage = 0;
                break;
            case ACTION_ROTFACE_DEATH:
                events.ScheduleEvent(EVENT_ROTFACE_DIES, 4500ms, 0, PHASE_ROTFACE);
                break;
            case ACTION_CHANGE_PHASE:
                me->SetSpeedRate(MOVE_RUN, _baseSpeed*2.0f);
                events.DelayEvents(30s);
                me->AttackStop();
                if (!IsHeroic())
                {
                    DoCast(me, SPELL_TEAR_GAS);
                    events.ScheduleEvent(EVENT_TEAR_GAS, 2500ms);
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
                            for (ThreatReference const* ref : me->GetThreatManager().GetUnsortedThreatList())
                                if (Player* target = ref->GetVictim()->ToPlayer())
                                    targetList.push_back(target);
                        }

                        size_t half = targetList.size()/2;
                        // half gets ooze variable
                        while (half < targetList.size())
                        {
                            std::list<Unit*>::iterator itr = targetList.begin();
                            advance(itr, urand(0, targetList.size() - 1));
                            (*itr)->CastSpell(*itr, SPELL_OOZE_VARIABLE, true);
                            targetList.erase(itr);
                        }
                        // and half gets gas
                        for (std::list<Unit*>::iterator itr = targetList.begin(); itr != targetList.end(); ++itr)
                            (*itr)->CastSpell(*itr, SPELL_GAS_VARIABLE, true);
                    }
                    me->GetMotionMaster()->MovePoint(POINT_TABLE, tablePos);
                }
                switch (_phase)
                {
                    case PHASE_COMBAT_1:
                        SetPhase(PHASE_COMBAT_2);
                        events.ScheduleEvent(EVENT_MALLEABLE_GOO, 21s, 26s);
                        events.ScheduleEvent(EVENT_CHOKING_GAS_BOMB, 35s, 40s);
                        break;
                    case PHASE_COMBAT_2:
                        SetPhase(PHASE_COMBAT_3);
                        events.ScheduleEvent(EVENT_MUTATED_PLAGUE, 25s);
                        events.CancelEvent(EVENT_UNSTABLE_EXPERIMENT);
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }

    uint32 GetData(uint32 type) const override
    {
        switch (type)
        {
            case DATA_EXPERIMENT_STAGE:
                return _experimentState;
            case DATA_PHASE:
                return _phase;
            case DATA_ABOMINATION:
                return uint32(summons.HasEntry(NPC_MUTATED_ABOMINATION_10) || summons.HasEntry(NPC_MUTATED_ABOMINATION_25));
            default:
                break;
        }

        return 0;
    }

    void SetData(uint32 id, uint32 data) override
    {
        if (id == DATA_EXPERIMENT_STAGE)
            _experimentState = data != 0;
    }

    void UpdateAI(uint32 diff) override
    {
        if (!(events.IsInPhase(PHASE_ROTFACE) || events.IsInPhase(PHASE_FESTERGUT)) && !UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
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
                    DoCastAOE(SPELL_MALLEABLE_GOO_SUMMON, CastSpellExtraArgs(true).AddSpellMod(SPELLVALUE_MAX_TARGETS, 1));
                    if (Is25ManRaid())
                        events.ScheduleEvent(EVENT_FESTERGUT_GOO, 10s, 15s, 0, PHASE_FESTERGUT);
                    else
                        events.ScheduleEvent(EVENT_FESTERGUT_GOO, 30s, 35s, 0, PHASE_FESTERGUT);
                    break;
                case EVENT_ROTFACE_DIES:
                    Talk(SAY_ROTFACE_DEATH);
                    EnterEvadeMode();
                    break;
                case EVENT_ROTFACE_OOZE_FLOOD:
                    DoAction(ACTION_ROTFACE_OOZE);
                    events.ScheduleEvent(EVENT_ROTFACE_OOZE_FLOOD, 25s, 0, PHASE_ROTFACE);
                    break;
                case EVENT_BERSERK:
                    Talk(SAY_BERSERK);
                    DoCast(me, SPELL_BERSERK2);
                    break;
                case EVENT_SLIME_PUDDLE:
                {
                    std::list<Unit*> targets;
                    SelectTargetList(targets, 2, SelectTargetMethod::Random, 0, 0.0f, true);
                    if (!targets.empty())
                        for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                            DoCast(*itr, SPELL_SLIME_PUDDLE_TRIGGER);
                    events.ScheduleEvent(EVENT_SLIME_PUDDLE, 35s);
                    break;
                }
                case EVENT_UNSTABLE_EXPERIMENT:
                    Talk(EMOTE_UNSTABLE_EXPERIMENT);
                    DoCast(me, SPELL_UNSTABLE_EXPERIMENT);
                    events.ScheduleEvent(EVENT_UNSTABLE_EXPERIMENT, 35s, 40s);
                    break;
                case EVENT_TEAR_GAS:
                    me->GetMotionMaster()->MovePoint(POINT_TABLE, tablePos);
                    DoCast(me, SPELL_TEAR_GAS_PERIODIC_TRIGGER, true);
                    break;
                case EVENT_RESUME_ATTACK:
                    me->SetReactState(REACT_AGGRESSIVE);
                    AttackStart(me->GetVictim());
                    // remove Tear Gas
                    me->RemoveAurasDueToSpell(SPELL_TEAR_GAS_PERIODIC_TRIGGER);
                    DoCastAOE(SPELL_TEAR_GAS_CANCEL);
                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_GAS_VARIABLE);
                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_OOZE_VARIABLE);
                    break;
                case EVENT_MALLEABLE_GOO:
                    if (Is25ManRaid())
                    {
                        std::list<Unit*> targets;
                        SelectTargetList(targets, 2, SelectTargetMethod::Random, 0, -7.0f, true);
                        if (!targets.empty())
                        {
                            Talk(EMOTE_MALLEABLE_GOO);
                            for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                                DoCast(*itr, SPELL_MALLEABLE_GOO);
                        }
                    }
                    else
                    {
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, -7.0f, true))
                        {
                            Talk(EMOTE_MALLEABLE_GOO);
                            DoCast(target, SPELL_MALLEABLE_GOO);
                        }
                    }
                    events.ScheduleEvent(EVENT_MALLEABLE_GOO, 25s, 30s);
                    break;
                case EVENT_CHOKING_GAS_BOMB:
                    Talk(EMOTE_CHOKING_GAS_BOMB);
                    DoCast(me, SPELL_CHOKING_GAS_BOMB);
                    events.ScheduleEvent(EVENT_CHOKING_GAS_BOMB, 35s, 40s);
                    break;
                case EVENT_UNBOUND_PLAGUE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, NonTankTargetSelector(me)))
                    {
                        DoCast(target, SPELL_UNBOUND_PLAGUE);
                        DoCast(target, SPELL_UNBOUND_PLAGUE_SEARCHER);
                    }
                    events.ScheduleEvent(EVENT_UNBOUND_PLAGUE, 90s);
                    break;
                case EVENT_MUTATED_PLAGUE:
                    DoCastVictim(SPELL_MUTATED_PLAGUE);
                    events.ScheduleEvent(EVENT_MUTATED_PLAGUE, 10s);
                    break;
                case EVENT_PHASE_TRANSITION:
                {
                    switch (_phase)
                    {
                        case PHASE_COMBAT_2:
                            if (Creature* face = me->FindNearestCreature(NPC_TEAR_GAS_TARGET_STALKER, 50.0f))
                                me->SetFacingToObject(face);
                            me->HandleEmoteCommand(EMOTE_ONESHOT_KNEEL);
                            Talk(SAY_TRANSFORM_1);
                            events.ScheduleEvent(EVENT_RESUME_ATTACK, 5500ms, 0, PHASE_COMBAT_2);
                            break;
                        case PHASE_COMBAT_3:
                            if (Creature* face = me->FindNearestCreature(NPC_TEAR_GAS_TARGET_STALKER, 50.0f))
                                me->SetFacingToObject(face);
                            me->HandleEmoteCommand(EMOTE_ONESHOT_KNEEL);
                            Talk(SAY_TRANSFORM_2);
                            summons.DespawnIf(AbominationDespawner(me));
                            events.ScheduleEvent(EVENT_RESUME_ATTACK, 8500ms, 0, PHASE_COMBAT_3);
                            break;
                        default:
                            break;
                    }
                    break;
                }
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    void SetPhase(Phases newPhase)
    {
        _phase = newPhase;
        events.SetPhase(newPhase);
    }

    ObjectGuid _oozeFloodDummyGUIDs[4];
    Phases _phase;          // external of EventMap because event phase gets reset on evade
    float const _baseSpeed;
    uint8 _oozeFloodStage;
    bool _experimentState;
};

class npc_putricide_oozeAI : public ScriptedAI
{
    public:
        npc_putricide_oozeAI(Creature* creature, uint32 auraSpellId, uint32 hitTargetSpellId) : ScriptedAI(creature),
            _auraSpellId(auraSpellId), _hitTargetSpellId(hitTargetSpellId), _newTargetSelectTimer(0), _instance(creature->GetInstanceScript()) { }

        void SpellHitTarget(WorldObject* /*target*/, SpellInfo const* spellInfo) override
        {
            if (!_newTargetSelectTimer && spellInfo->Id == _hitTargetSpellId)
            {
                _newTargetSelectTimer = 1000;
                // go passive until next target selection
                me->SetReactState(REACT_PASSIVE);
            }
        }

        void Reset() override
        {
            if (_instance->GetBossState(DATA_PROFESSOR_PUTRICIDE) != IN_PROGRESS)
                me->DespawnOrUnsummon();

            DoZoneInCombat();
            DoCastAOE(_auraSpellId, true);
        }

        void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
        {
            if (spellInfo->Id == SPELL_TEAR_GAS_CREATURE)
                _newTargetSelectTimer = 1000;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() && !_newTargetSelectTimer)
                return;

            if (!_newTargetSelectTimer && !me->IsNonMeleeSpellCast(false, false, true, false, true))
                _newTargetSelectTimer = 1000;

            if (!_newTargetSelectTimer)
                return;

            if (me->HasAura(SPELL_TEAR_GAS_CREATURE))
                return;

            if (_newTargetSelectTimer <= diff)
            {
                _newTargetSelectTimer = 0;
                CastMainSpell();
            }
            else
                _newTargetSelectTimer -= diff;
        }

        virtual void CastMainSpell() = 0;

    private:
        uint32 _auraSpellId;
        uint32 _hitTargetSpellId;
        uint32 _newTargetSelectTimer;
        InstanceScript* _instance;
};

struct npc_volatile_ooze : public npc_putricide_oozeAI
{
    npc_volatile_ooze(Creature* creature) : npc_putricide_oozeAI(creature, SPELL_OOZE_ERUPTION_SEARCH_PERIODIC, SPELL_OOZE_ERUPTION) { }

    void CastMainSpell() override
    {
        me->CastSpell(me, SPELL_VOLATILE_OOZE_ADHESIVE, false);
    }
};

struct npc_gas_cloud : public npc_putricide_oozeAI
{
    npc_gas_cloud(Creature* creature) : npc_putricide_oozeAI(creature, SPELL_GASEOUS_BLOAT_PROC, SPELL_EXPUNGED_GAS)
    {
        _newTargetSelectTimer = 0;
    }

    void CastMainSpell() override
    {
        CastSpellExtraArgs args;
        args.AddSpellMod(SPELLVALUE_AURA_STACK, 10);
        me->CastSpell(me, SPELL_GASEOUS_BLOAT, args);
    }

private:
    uint32 _newTargetSelectTimer;
};

// 70672, 72455, 72832, 72833 - Gaseous Bloat
class spell_putricide_gaseous_bloat : public AuraScript
{
    void HandleExtraEffect(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        if (Unit* caster = GetCaster())
        {
            target->RemoveAuraFromStack(GetSpellInfo()->Id, GetCasterGUID());
            if (!target->HasAura(GetId()))
            {
                CastSpellExtraArgs args;
                args.AddSpellMod(SPELLVALUE_AURA_STACK, 10);
                caster->CastSpell(caster, SPELL_GASEOUS_BLOAT, args);
            }
        }
    }

    void HandleProc(ProcEventInfo& eventInfo)
    {
        uint32 stack = GetStackAmount();
        Unit* caster = eventInfo.GetActor();

        int32 const mod = caster->GetMap()->Is25ManRaid() ? 1500 : 1250;
        int32 dmg = 0;
        for (uint8 i = 1; i <= stack; ++i)
            dmg += mod * i;

        CastSpellExtraArgs args;
        args.AddSpellBP0(dmg);
        caster->CastSpell(nullptr, SPELL_EXPUNGED_GAS, args);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_putricide_gaseous_bloat::HandleExtraEffect, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        OnProc += AuraProcFn(spell_putricide_gaseous_bloat::HandleProc);
    }
};

// 70447, 72836, 72837, 72838 - Volatile Ooze Adhesive
// 70672, 72455, 72832, 72833 - Gaseous Bloat
class spell_putricide_ooze_channel : public SpellScript
{
    bool Validate(SpellInfo const* spell) override
    {
        return ValidateSpellInfo({ spell->ExcludeTargetAuraSpell });
    }

    // set up initial variables and check if caster is creature
    // this will let use safely use ToCreature() casts in entire script
    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    void SelectTarget(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
        {
            FinishCast(SPELL_FAILED_NO_VALID_TARGETS);
            GetCaster()->ToCreature()->DespawnOrUnsummon(1ms);    // despawn next update
            return;
        }

        WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
        targets.clear();
        targets.push_back(target);
        _target = target;
    }

    void SetTarget(std::list<WorldObject*>& targets)
    {
        targets.clear();
        if (_target)
            targets.push_back(_target);
    }

    void StartAttack()
    {
        GetCaster()->ClearUnitState(UNIT_STATE_CASTING);
        GetCaster()->GetThreatManager().ResetAllThreat();
        GetCaster()->ToCreature()->AI()->AttackStart(GetHitUnit());
        GetCaster()->GetThreatManager().AddThreat(GetHitUnit(), 500000000.0f, nullptr, true, true);    // value seen in sniff
        GetCaster()->GetThreatManager().FixateTarget(GetHitUnit());
        GetCaster()->ToCreature()->SetReactState(REACT_AGGRESSIVE);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_putricide_ooze_channel::SelectTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_putricide_ooze_channel::SetTarget, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_putricide_ooze_channel::SetTarget, EFFECT_2, TARGET_UNIT_SRC_AREA_ENEMY);
        AfterHit += SpellHitFn(spell_putricide_ooze_channel::StartAttack);
    }

    WorldObject* _target = nullptr;
};

class ExactDistanceCheck
{
    public:
        ExactDistanceCheck(Unit* source, float dist) : _source(source), _dist(dist) { }

        bool operator()(WorldObject* unit) const
        {
            return _source->GetExactDist2d(unit) > _dist;
        }

    private:
        Unit* _source;
        float _dist;
};

// 70346, 72456, 72868, 72869 - Slime Puddle
class spell_putricide_slime_puddle : public SpellScript
{
    void ScaleRange(std::list<WorldObject*>& targets)
    {
        targets.remove_if(ExactDistanceCheck(GetCaster(), 2.5f * GetCaster()->GetObjectScale()));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_putricide_slime_puddle::ScaleRange, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_putricide_slime_puddle::ScaleRange, EFFECT_1, TARGET_UNIT_DEST_AREA_ENTRY);
    }
};

// this is here only because on retail you dont actually enter HEROIC mode for ICC
// 72868, 72869 - Slime Puddle
class spell_putricide_slime_puddle_aura : public SpellScript
{
    void ReplaceAura()
    {
        if (Unit* target = GetHitUnit())
            GetCaster()->AddAura(GetCaster()->GetMap()->Is25ManRaid() ? 72456 : 70346, target);
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_putricide_slime_puddle_aura::ReplaceAura);
    }
};

// 70351, 71966, 71967, 71968 - Unstable Experiment
class spell_putricide_unstable_experiment : public SpellScript
{
    void HandleScript(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        if (GetCaster()->GetTypeId() != TYPEID_UNIT)
            return;

        Creature* creature = GetCaster()->ToCreature();

        uint32 stage = creature->AI()->GetData(DATA_EXPERIMENT_STAGE);
        creature->AI()->SetData(DATA_EXPERIMENT_STAGE, stage ^ true);

        Creature* target = nullptr;
        std::list<Creature*> creList;
        GetCreatureListWithEntryInGrid(creList, GetCaster(), NPC_ABOMINATION_WING_MAD_SCIENTIST_STALKER, 200.0f);
        // 2 of them are spawned at green place - weird trick blizz
        for (std::list<Creature*>::iterator itr = creList.begin(); itr != creList.end(); ++itr)
        {
            target = *itr;
            std::list<Creature*> tmp;
            GetCreatureListWithEntryInGrid(tmp, target, NPC_ABOMINATION_WING_MAD_SCIENTIST_STALKER, 10.0f);
            if ((!stage && tmp.size() > 1) || (stage && tmp.size() == 1))
                break;
        }

        GetCaster()->CastSpell(target, uint32(GetEffectInfo(SpellEffIndex(stage)).CalcValue()), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_putricide_unstable_experiment::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 70459 - Ooze Eruption Search Effect
class spell_putricide_ooze_eruption_searcher : public SpellScript
{
    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (GetHitUnit()->HasAura(SPELL_VOLATILE_OOZE_ADHESIVE))
        {
            GetHitUnit()->RemoveAurasDueToSpell(SPELL_VOLATILE_OOZE_ADHESIVE, GetCaster()->GetGUID(), 0, AURA_REMOVE_BY_ENEMY_SPELL);
            GetCaster()->CastSpell(GetHitUnit(), SPELL_OOZE_ERUPTION, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_putricide_ooze_eruption_searcher::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 71770 - Ooze Spell Tank Protection
class spell_putricide_ooze_tank_protection : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } })
            && ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell, spellInfo->GetEffect(EFFECT_1).TriggerSpell });
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        Unit* actionTarget = eventInfo.GetActionTarget();
        actionTarget->CastSpell(nullptr, aurEff->GetSpellEffectInfo().TriggerSpell, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_putricide_ooze_tank_protection::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        OnEffectProc += AuraEffectProcFn(spell_putricide_ooze_tank_protection::HandleProc, EFFECT_1, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 71255 - Choking Gas Bomb
class spell_putricide_choking_gas_bomb : public SpellScript
{
    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        uint32 skipIndex = urand(0, 2);
        for (SpellEffectInfo const& spellEffectInfo : GetSpellInfo()->GetEffects())
        {
            if (spellEffectInfo.EffectIndex == skipIndex)
                continue;

            uint32 spellId = uint32(spellEffectInfo.CalcValue());
            GetCaster()->CastSpell(GetCaster(), spellId, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                .SetOriginalCaster(GetCaster()->GetGUID()));
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_putricide_choking_gas_bomb::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 70920 - Unbound Plague Search Effect
class spell_putricide_unbound_plague : public SpellScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_UNBOUND_PLAGUE, SPELL_UNBOUND_PLAGUE_SEARCHER });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (AuraEffect const* eff = GetCaster()->GetAuraEffect(SPELL_UNBOUND_PLAGUE_SEARCHER, EFFECT_0))
        {
            if (eff->GetTickNumber() < 2)
            {
                targets.clear();
                return;
            }
        }

        targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_UNBOUND_PLAGUE));
        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (!GetHitUnit())
            return;

        InstanceScript* instance = GetCaster()->GetInstanceScript();
        if (!instance)
            return;

        if (!GetHitUnit()->HasAura(SPELL_UNBOUND_PLAGUE))
        {
            if (Creature* professor = ObjectAccessor::GetCreature(*GetCaster(), instance->GetGuidData(DATA_PROFESSOR_PUTRICIDE)))
            {
                if (Aura* oldPlague = GetCaster()->GetAura(SPELL_UNBOUND_PLAGUE, professor->GetGUID()))
                {
                    if (Aura* newPlague = professor->AddAura(SPELL_UNBOUND_PLAGUE, GetHitUnit()))
                    {
                        newPlague->SetMaxDuration(oldPlague->GetMaxDuration());
                        newPlague->SetDuration(oldPlague->GetDuration());
                        oldPlague->Remove();
                        GetCaster()->RemoveAurasDueToSpell(SPELL_UNBOUND_PLAGUE_SEARCHER);
                        GetCaster()->CastSpell(GetCaster(), SPELL_PLAGUE_SICKNESS, true);
                        GetCaster()->CastSpell(GetCaster(), SPELL_UNBOUND_PLAGUE_PROTECTION, true);
                        professor->CastSpell(GetHitUnit(), SPELL_UNBOUND_PLAGUE_SEARCHER, true);
                    }
                }
            }
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_putricide_unbound_plague::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
        OnEffectHitTarget += SpellEffectFn(spell_putricide_unbound_plague::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 70360, 72527 - Eat Ooze
class spell_putricide_eat_ooze : public SpellScript
{
    void SelectTarget(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.sort(Trinity::ObjectDistanceOrderPred(GetCaster()));
        WorldObject* target = targets.front();
        targets.clear();
        targets.push_back(target);
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Creature* target = GetHitCreature();
        if (!target)
            return;

        if (Aura* grow = target->GetAura(uint32(GetEffectValue())))
        {
            if (grow->GetStackAmount() < 3)
            {
                target->RemoveAurasDueToSpell(SPELL_GROW_STACKER);
                target->RemoveAura(grow);
                target->DespawnOrUnsummon(1ms);
            }
            else
                grow->ModStackAmount(-3);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_putricide_eat_ooze::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_putricide_eat_ooze::SelectTarget, EFFECT_0, TARGET_UNIT_DEST_AREA_ENTRY);
    }
};

// 72451, 72463, 72671, 72672 - Mutated Plague
class spell_putricide_mutated_plague : public AuraScript
{
    void HandleTriggerSpell(AuraEffect const* aurEff)
    {
        PreventDefaultAction();
        Unit* caster = GetCaster();
        if (!caster)
            return;

        uint32 triggerSpell = aurEff->GetSpellEffectInfo().TriggerSpell;
        SpellInfo const* spell = sSpellMgr->AssertSpellInfo(triggerSpell, GetCastDifficulty());

        int32 damage = spell->GetEffect(EFFECT_0).CalcValue(caster);
        float multiplier = 2.0f;
        if (GetTarget()->GetMap()->Is25ManRaid())
            multiplier = 3.0f;

        damage *= int32(pow(multiplier, GetStackAmount()));
        damage = int32(damage * 1.5f);

        CastSpellExtraArgs args(aurEff);
        args.OriginalCaster = GetCasterGUID();
        args.AddSpellBP0(damage);
        GetTarget()->CastSpell(GetTarget(), triggerSpell, args);
    }

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        uint32 healSpell = uint32(aurEff->GetSpellEffectInfo().CalcValue());
        SpellInfo const* healSpellInfo = sSpellMgr->GetSpellInfo(healSpell, GetCastDifficulty());

        if (!healSpellInfo)
            return;

        int32 heal = healSpellInfo->GetEffect(EFFECT_0).CalcValue() * GetStackAmount();
        CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
        args.SetOriginalCaster(GetCasterGUID());
        args.AddSpellBP0(heal);
        GetTarget()->CastSpell(GetTarget(), healSpell, args);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_putricide_mutated_plague::HandleTriggerSpell, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_putricide_mutated_plague::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// 70308 - Mutated Transformation (Init)
class spell_putricide_mutation_init : public SpellScript
{
    SpellCastResult CheckRequirementInternal(SpellCustomErrors& extendedError)
    {
        InstanceScript* instance = GetExplTargetUnit()->GetInstanceScript();
        if (!instance)
            return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

        Creature* professor = ObjectAccessor::GetCreature(*GetExplTargetUnit(), instance->GetGuidData(DATA_PROFESSOR_PUTRICIDE));
        if (!professor)
            return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

        if (professor->AI()->GetData(DATA_PHASE) == PHASE_COMBAT_3 || !professor->IsAlive())
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
        if (!GetExplTargetUnit())
            return SPELL_FAILED_BAD_TARGETS;

        if (GetExplTargetUnit()->GetTypeId() != TYPEID_PLAYER)
            return SPELL_FAILED_TARGET_NOT_PLAYER;

        SpellCustomErrors extension = SPELL_CUSTOM_ERROR_NONE;
        SpellCastResult result = CheckRequirementInternal(extension);
        if (result != SPELL_CAST_OK)
        {
            Spell::SendCastResult(GetExplTargetUnit()->ToPlayer(), GetSpellInfo(), GetSpell()->m_SpellVisual, GetSpell()->m_castId, result, extension);
            return result;
        }

        return SPELL_CAST_OK;
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_putricide_mutation_init::CheckRequirement);
    }
};

class spell_putricide_mutation_init_aura : public AuraScript
{
    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        uint32 spellId = 70311;
        if (GetTarget()->GetMap()->Is25ManRaid())
            spellId = 71503;

        GetTarget()->CastSpell(GetTarget(), spellId, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_putricide_mutation_init_aura::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 70405, 72508, 72509, 72510 - Mutated Transformation (Dismiss)
class spell_putricide_mutated_transformation_dismiss : public AuraScript
{
    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Vehicle* veh = GetTarget()->GetVehicleKit())
            veh->RemoveAllPassengers();
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_putricide_mutated_transformation_dismiss::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// 70311, 71503 - Mutated Transformation
class spell_putricide_mutated_transformation : public SpellScript
{
    void HandleSummon(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        Unit* caster = GetOriginalCaster();
        if (!caster)
            return;

        InstanceScript* instance = caster->GetInstanceScript();
        if (!instance)
            return;

        Creature* putricide = ObjectAccessor::GetCreature(*caster, instance->GetGuidData(DATA_PROFESSOR_PUTRICIDE));
        if (!putricide)
            return;

        if (putricide->AI()->GetData(DATA_ABOMINATION))
        {
            if (Player* player = caster->ToPlayer())
                Spell::SendCastResult(player, GetSpellInfo(), GetSpell()->m_SpellVisual, GetSpell()->m_castId, SPELL_FAILED_CUSTOM_ERROR, SPELL_CUSTOM_ERROR_TOO_MANY_ABOMINATIONS);
            return;
        }

        uint32 entry = uint32(GetEffectInfo().MiscValue);
        SummonPropertiesEntry const* properties = sSummonPropertiesStore.LookupEntry(uint32(GetEffectInfo().MiscValueB));
        Milliseconds duration = Milliseconds(GetSpellInfo()->GetDuration());

        Position pos = caster->GetPosition();
        TempSummon* summon = caster->GetMap()->SummonCreature(entry, pos, properties, duration, caster, GetSpellInfo()->Id);
        if (!summon || !summon->IsVehicle())
            return;

        summon->CastSpell(summon, SPELL_ABOMINATION_VEHICLE_POWER_DRAIN, true);
        summon->CastSpell(summon, SPELL_MUTATED_TRANSFORMATION_DAMAGE, true);
        caster->CastSpell(summon, SPELL_MUTATED_TRANSFORMATION_NAME, true);

        caster->EnterVehicle(summon, 0);    // VEHICLE_SPELL_RIDE_HARDCODED is used according to sniff, this is ok
        summon->SetCreatorGUID(caster->GetGUID());
        putricide->AI()->JustSummoned(summon);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_putricide_mutated_transformation::HandleSummon, EFFECT_0, SPELL_EFFECT_SUMMON);
    }
};

// 70402, 72511, 72512, 72513 - Mutated Transformation (Damage)
class spell_putricide_mutated_transformation_dmg : public SpellScript
{
    void FilterTargetsInitial(std::list<WorldObject*>& targets)
    {
        if (Unit* owner = ObjectAccessor::GetUnit(*GetCaster(), GetCaster()->GetCreatorGUID()))
            targets.remove(owner);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_putricide_mutated_transformation_dmg::FilterTargetsInitial, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
    }
};

// 70539, 72457, 72875, 72876 - Regurgitated Ooze
class spell_putricide_regurgitated_ooze : public SpellScript
{
    // the only purpose of this hook is to fail the achievement
    void ExtraEffect(SpellEffIndex /*effIndex*/)
    {
        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
            instance->SetData(DATA_NAUSEA_ACHIEVEMENT, uint32(false));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_putricide_regurgitated_ooze::ExtraEffect, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

// Removes aura with id stored in effect value
// 71620 - Tear Gas Cancel
// 72618 - Mutated Plague Clear
class spell_putricide_clear_aura_effect_value : public SpellScript
{
    void HandleScript(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        Unit* target = GetHitUnit();
        uint32 auraId = GetEffectValue();
        target->RemoveAurasDueToSpell(auraId);
        if (m_scriptSpellId == SPELL_TEAR_GAS_CANCEL && GetSpellInfo()->GetEffects().size() >= EFFECT_1)
        {
            uint32 auraId2 = GetSpellInfo()->GetEffect(EFFECT_1).CalcValue();
            target->RemoveAurasDueToSpell(auraId2);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_putricide_clear_aura_effect_value::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// Stinky and Precious spell, it's here because its used for both (Festergut and Rotface "pets")
// 71123 - Decimate
class spell_stinky_precious_decimate : public SpellScript
{
    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (GetHitUnit()->GetHealthPct() > float(GetEffectValue()))
        {
            uint32 newHealth = GetHitUnit()->GetMaxHealth() * uint32(GetEffectValue()) / 100;
            GetHitUnit()->SetHealth(newHealth);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_stinky_precious_decimate::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 70402, 72511, 72512, 72513 - Mutated Transformation
class spell_abomination_mutated_transformation : public SpellScript
{
    void HandleResistance(DamageInfo const& damageInfo, uint32& resistAmount, int32& /*absorbAmount*/)
    {
        Unit* caster = damageInfo.GetAttacker();;
        Unit* target = damageInfo.GetVictim();
        uint32 damage = damageInfo.GetDamage();
        uint32 resistedDamage = Unit::CalcSpellResistedDamage(caster, target, damage, SPELL_SCHOOL_MASK_SHADOW, nullptr);
        resistedDamage += Unit::CalcSpellResistedDamage(caster, target, damage, SPELL_SCHOOL_MASK_NATURE, nullptr);
        resistAmount = resistedDamage;
    }

    void Register() override
    {
        OnCalculateResistAbsorb += SpellOnResistAbsorbCalculateFn(spell_abomination_mutated_transformation::HandleResistance);
    }
};

// 71278, 72460, 72619, 72620 - Choking Gas
// 71279, 72459, 72621, 72622 - Choking Gas Explosion
class spell_putricide_choking_gas_filter : public SpellScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_OOZE_VARIABLE, SPELL_GAS_VARIABLE });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* obj)
        {
            return obj->ToUnit() && obj->ToUnit()->GetVehicle();
        });
    }

    void HandleDispel(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        target->RemoveAurasDueToSpell(SPELL_OOZE_VARIABLE);
        target->RemoveAurasDueToSpell(SPELL_GAS_VARIABLE);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_putricide_choking_gas_filter::FilterTargets, EFFECT_ALL, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_putricide_choking_gas_filter::HandleDispel, EFFECT_1, SPELL_EFFECT_APPLY_AURA);
    }
};

void AddSC_boss_professor_putricide()
{
    // Creatures
    RegisterIcecrownCitadelCreatureAI(boss_professor_putricide);
    RegisterIcecrownCitadelCreatureAI(npc_volatile_ooze);
    RegisterIcecrownCitadelCreatureAI(npc_gas_cloud);

    // Spells
    RegisterSpellScript(spell_putricide_gaseous_bloat);
    RegisterSpellScript(spell_putricide_ooze_channel);
    RegisterSpellScript(spell_putricide_slime_puddle);
    RegisterSpellScript(spell_putricide_slime_puddle_aura);
    RegisterSpellScript(spell_putricide_unstable_experiment);
    RegisterSpellScript(spell_putricide_ooze_eruption_searcher);
    RegisterSpellScript(spell_putricide_ooze_tank_protection);
    RegisterSpellScript(spell_putricide_choking_gas_bomb);
    RegisterSpellScript(spell_putricide_unbound_plague);
    RegisterSpellScript(spell_putricide_eat_ooze);
    RegisterSpellScript(spell_putricide_mutated_plague);
    RegisterSpellAndAuraScriptPair(spell_putricide_mutation_init, spell_putricide_mutation_init_aura);
    RegisterSpellScript(spell_putricide_mutated_transformation_dismiss);
    RegisterSpellScript(spell_putricide_mutated_transformation);
    RegisterSpellScript(spell_putricide_mutated_transformation_dmg);
    RegisterSpellScript(spell_putricide_regurgitated_ooze);
    RegisterSpellScript(spell_putricide_clear_aura_effect_value);
    RegisterSpellScript(spell_stinky_precious_decimate);
    RegisterSpellScript(spell_abomination_mutated_transformation);
    RegisterSpellScript(spell_putricide_choking_gas_filter);
}
