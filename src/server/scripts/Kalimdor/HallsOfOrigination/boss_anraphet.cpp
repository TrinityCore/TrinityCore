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
#include "Containers.h"
#include "GridNotifiers.h"
#include "halls_of_origination.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

enum Texts
{
    ANRAPHET_SAY_INTRO              = 0,
    ANRAPHET_SAY_AGGRO              = 1,
    ANRAPHET_SAY_OMEGA_STANCE       = 2,
    ANRAPHET_SAY_KILL               = 3,
    ANRAPHET_SAY_DEATH              = 4,

    BRANN_SAY_DOOR_INTRO            = 0,  // Right, let's go! Just need to input the final entry sequence into the door mechanism... and...
    BRANN_SAY_UNLOCK_DOOR           = 1,  // That did the trick! The control room should be right behind this... oh... wow...
    BRANN_SAY_TROGGS                = 2,  // What? This isn't the control room! There's another entire defense mechanism in place, and the blasted Rock Troggs broke into here somehow. Troggs. Why did it have to be Troggs!
    BRANN_SAY_THINK                 = 3,  // Ok, let me think a moment.
    BRANN_SAY_MIRRORS               = 4,  // Mirrors pointing all over the place.
    BRANN_SAY_ELEMENTALS            = 5,  // Four platforms with huge elementals.
    BRANN_SAY_GET_IT                = 6,  // I got it! I saw a tablet that mentioned this chamber. This is the Vault of Lights! Ok, simple enough. I need you adventurers to take out each of the four elementals to trigger the opening sequence for the far door!
    BRANN_1_ELEMENTAL_DEAD          = 7,  // One down!
    BRANN_2_ELEMENTAL_DEAD          = 8,  // Another one down! Just look at those light beams! They seem to be connecting to the far door!
    BRANN_3_ELEMENTAL_DEAD          = 9,  // One more elemental to go! The door is almost open!
    BRANN_4_ELEMENTAL_DEAD          = 10, // That''s it, you''ve done it! The vault door is opening! Now we can... oh, no!
    BRANN_SAY_ANRAPHET_DIED         = 11, // We''ve done it! The control room is breached!
    BRANN_SAY_MOMENT                = 12 // Here we go! Now this should only take a moment...
};

enum Events
{
    EVENT_BRANN_MOVE_INTRO          = 1,
    EVENT_BRANN_UNLOCK_DOOR         = 2,
    EVENT_BRANN_THINK               = 3,
    EVENT_BRANN_SET_ORIENTATION_1   = 4,
    EVENT_BRANN_SET_ORIENTATION_2   = 5,
    EVENT_BRANN_SET_ORIENTATION_3   = 6,
    EVENT_BRANN_SAY_ELEMENTALS      = 7,
    EVENT_BRANN_SAY_GET_IT          = 8,
    EVENT_BRANN_SET_ORIENTATION_4   = 9,

    EVENT_ANRAPHET_APPEAR           = 10,
    EVENT_ANRAPHET_ACTIVATE         = 11,
    EVENT_ANRAPHET_DESTROY          = 12,
    EVENT_ANRAPHET_READY            = 13,
    EVENT_ANRAPHET_NEMESIS_STRIKE   = 14,
    EVENT_ANRAPHET_ALPHA_BEAMS      = 15,
    EVENT_ANRAPHET_OMEGA_STANCE     = 16,
    EVENT_ANRAPHET_CRUMBLING_RUIN   = 17,
    EVENT_ANRAPHET_ACTIVATE_OMEGA   = 18
};

enum Spells
{
    SPELL_DESTRUCTION_PROTOCOL          = 77437,

    SPELL_ALPHA_BEAMS                   = 76184,
    SPELL_ALPHA_BEAMS_BACK_CAST         = 76912,

    SPELL_CRUMBLING_RUIN                = 75609,

    SPELL_NEMESIS_STRIKE                = 75604,

    SPELL_OMEGA_STANCE_SUMMON           = 77106,
    SPELL_OMEGA_STANCE                  = 75622,
    SPELL_OMEGA_STANCE_SPIDER_TRIGGER   = 77121,
};

enum Phases
{
    PHASE_INTRO         = 1,
    PHASE_COMBAT        = 2,

    PHASE_MASK_COMBAT   = (1 << PHASE_COMBAT),
};

enum Points
{
    POINT_ANRAPHET_ACTIVATE     = 0,
    MAX_BRANN_WAYPOINTS_INTRO   = 17
};

enum GossipMenuIds
{
    GOSSIP_MENU_START_INTRO = 11339,
};

Position const AnraphetActivatePos = {-193.656f, 366.689f, 75.91001f, 3.138207f};

Position const BrannIntroWaypoint[MAX_BRANN_WAYPOINTS_INTRO] =
{
    {-429.583f,  367.019f,  89.79282f, 0.0f},
    {-409.9531f, 367.0469f, 89.81111f, 0.0f},
    {-397.8246f, 366.967f,  86.37722f, 0.0f},
    {-383.7813f, 366.8229f, 82.07919f, 0.0f},
    {-368.2604f, 366.7448f, 77.0984f,  0.0f},
    {-353.6458f, 366.4896f, 75.92504f, 0.0f},
    {-309.0608f, 366.7205f, 75.91345f, 0.0f},
    {-276.3303f, 367.0f,    75.92413f, 0.0f},
    {-246.5104f, 366.6389f, 75.87791f, 0.0f},
    {-202.0417f, 366.7517f, 75.92508f, 0.0f},
    {-187.6024f, 366.7656f, 76.23077f, 0.0f},
    {-155.0938f, 366.783f,  86.45834f, 0.0f},
    {-143.5694f, 366.8177f, 89.73354f, 0.0f},
    {-128.5608f, 366.8629f, 89.74199f, 0.0f},
    {-103.559f,  366.5938f, 89.79725f, 0.0f},
    {-71.58507f, 367.0278f, 89.77069f, 0.0f},
    {-35.04861f, 366.6563f, 89.77447f, 0.0f},
};

struct boss_anraphet : public BossAI
{
    boss_anraphet(Creature* creature) : BossAI(creature, BOSS_ANRAPHET) { }

    void ScheduleCombatEvents()
    {
        events.ScheduleEvent(EVENT_ANRAPHET_NEMESIS_STRIKE, 8s, 0, PHASE_COMBAT);
        events.ScheduleEvent(EVENT_ANRAPHET_ALPHA_BEAMS, 10s, 0, PHASE_COMBAT);
        events.ScheduleEvent(EVENT_ANRAPHET_OMEGA_STANCE, 35s, 0, PHASE_COMBAT);
    }

    void Reset() override
    {
        _Reset();
        me->SetWalk(false);
        events.SetPhase(PHASE_INTRO);
        if (instance->GetData(DATA_DEAD_ELEMENTALS) == 4)
        {
            // Set to combat automatically, Brann's event won't repeat
            me->SetUninteractible(false);
            events.SetPhase(PHASE_COMBAT);
            ScheduleCombatEvents();
            me->SetHomePosition(AnraphetActivatePos);
        }
    }

    void JustEngagedWith(Unit* who) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        Talk(ANRAPHET_SAY_AGGRO);
        BossAI::JustEngagedWith(who);
    }

    void JustDied(Unit* /*killer*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        Talk(ANRAPHET_SAY_DEATH);

        if (Creature* brann = instance->GetCreature(DATA_BRANN_BRONZEBEARD))
            brann->AI()->DoAction(ACTION_ANRAPHET_DIED);

        _JustDied();
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(ANRAPHET_SAY_KILL);
    }

    void JustReachedHome() override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _JustReachedHome();
        instance->SetBossState(BOSS_ANRAPHET, FAIL);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_ANRAPHET_INTRO)
            events.ScheduleEvent(EVENT_ANRAPHET_APPEAR, 6s, 0, PHASE_INTRO);
    }

    void MovementInform(uint32 type, uint32 point) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (point == POINT_ANRAPHET_ACTIVATE)
        {
            events.ScheduleEvent(EVENT_ANRAPHET_ACTIVATE, 1500ms, 0, PHASE_INTRO);
            me->SetHomePosition(AnraphetActivatePos);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if ((events.GetPhaseMask() & PHASE_MASK_COMBAT) && (!UpdateVictim() || !CheckInRoom()))
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ANRAPHET_APPEAR:
                    me->SetWalk(true);
                    me->GetMotionMaster()->MovePoint(POINT_ANRAPHET_ACTIVATE, AnraphetActivatePos);
                    break;
                case EVENT_ANRAPHET_ACTIVATE:
                    me->SetWalk(false);
                    Talk(ANRAPHET_SAY_INTRO);
                    events.ScheduleEvent(EVENT_ANRAPHET_DESTROY, 17500ms, 0, PHASE_INTRO);
                    return;
                case EVENT_ANRAPHET_DESTROY:
                    DoCastAOE(SPELL_DESTRUCTION_PROTOCOL);
                    events.ScheduleEvent(EVENT_ANRAPHET_READY, 6s, 0, PHASE_INTRO);
                    break;
                case EVENT_ANRAPHET_READY:
                    me->SetUninteractible(false);
                    events.SetPhase(PHASE_COMBAT);
                    ScheduleCombatEvents();
                    break;
                case EVENT_ANRAPHET_NEMESIS_STRIKE:
                    DoCastVictim(SPELL_NEMESIS_STRIKE);
                    events.ScheduleEvent(EVENT_ANRAPHET_NEMESIS_STRIKE, 21500ms, 0, PHASE_COMBAT);
                    break;
                case EVENT_ANRAPHET_ALPHA_BEAMS:
                    DoCast(me, SPELL_ALPHA_BEAMS);
                    events.ScheduleEvent(EVENT_ANRAPHET_CRUMBLING_RUIN, 12500ms, 0, PHASE_COMBAT);
                    events.ScheduleEvent(EVENT_ANRAPHET_ALPHA_BEAMS, 40s, 45s, 0, PHASE_COMBAT);
                    break;
                case EVENT_ANRAPHET_OMEGA_STANCE:
                    DoCast(me, SPELL_OMEGA_STANCE_SUMMON);
                    DoCast(me, SPELL_OMEGA_STANCE);
                    Talk(ANRAPHET_SAY_OMEGA_STANCE);
                    events.ScheduleEvent(EVENT_ANRAPHET_OMEGA_STANCE, 45s, 50s, 0, PHASE_COMBAT);
                    events.ScheduleEvent(EVENT_ANRAPHET_CRUMBLING_RUIN, 13s, 0, PHASE_COMBAT);
                    break;
                case EVENT_ANRAPHET_CRUMBLING_RUIN:
                    DoCast(me, SPELL_CRUMBLING_RUIN);
                    break;
            }
        }

        if (events.GetPhaseMask() & PHASE_MASK_COMBAT)
            DoMeleeAttackIfReady();
    }
};

struct npc_omega_stance : public ScriptedAI
{
    npc_omega_stance(Creature* creature) : ScriptedAI(creature) { }

    void IsSummonedBy(WorldObject* /*who*/) override
    {
        DoCast(me, SPELL_OMEGA_STANCE_SPIDER_TRIGGER, true);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override { }
};

struct npc_alpha_beam : public ScriptedAI
{
    npc_alpha_beam(Creature* creature) : ScriptedAI(creature), _instance(nullptr) { }

    void InitializeAI() override
    {
        _instance = me->GetInstanceScript();
    }

    void IsSummonedBy(WorldObject* /*summoner*/) override
    {
        if (Creature* anraphet = _instance->GetCreature(BOSS_ANRAPHET))
            anraphet->CastSpell(me, SPELL_ALPHA_BEAMS_BACK_CAST);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override { } // Never evade

private:
    InstanceScript* _instance;
};

struct npc_brann_bronzebeard_anraphet : public CreatureAI
{
    npc_brann_bronzebeard_anraphet(Creature* creature) : CreatureAI(creature), _currentPoint(0), _instance(nullptr) { }

    void InitializeAI() override
    {
        _instance = me->GetInstanceScript();
    }

    bool OnGossipSelect(Player* /*player*/, uint32 menuId, uint32 action) override
    {
        if (_instance->GetBossState(BOSS_VAULT_OF_LIGHTS) == DONE)
            return true;

        if (menuId == GOSSIP_MENU_START_INTRO && !action)
        {
            _instance->SetBossState(BOSS_VAULT_OF_LIGHTS, IN_PROGRESS);
            _currentPoint = 0;
            events.Reset();
            me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
            me->SetWalk(true);
            Talk(BRANN_SAY_DOOR_INTRO);
            events.ScheduleEvent(EVENT_BRANN_UNLOCK_DOOR, 7500ms);
        }
        return false;
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_ELEMENTAL_DIED:
            {
                uint32 dead = _instance->GetData(DATA_DEAD_ELEMENTALS);
                Talk(BRANN_1_ELEMENTAL_DEAD + dead - 1);
                if (dead == 4)
                {
                    _instance->DoCastSpellOnPlayers(SPELL_VAULT_OF_LIGHTS_CREDIT);
                    if (Creature* anraphet = _instance->GetCreature(BOSS_ANRAPHET))
                        anraphet->AI()->DoAction(ACTION_ANRAPHET_INTRO);
                }
                break;
            }
            case ACTION_ANRAPHET_DIED:
                me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                events.ScheduleEvent(EVENT_BRANN_MOVE_INTRO, 1s);
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
                case EVENT_BRANN_MOVE_INTRO:
                    if (_currentPoint < MAX_BRANN_WAYPOINTS_INTRO)
                        me->GetMotionMaster()->MovePoint(_currentPoint, BrannIntroWaypoint[_currentPoint]);
                    break;
                case EVENT_BRANN_UNLOCK_DOOR:
                    Talk(BRANN_SAY_UNLOCK_DOOR);
                    _instance->SetBossState(BOSS_VAULT_OF_LIGHTS, DONE);
                    _instance->TriggerGameEvent(ACHIEV_VAULT_OF_LIGHTS_EVENT);
                    events.ScheduleEvent(EVENT_BRANN_MOVE_INTRO, 3500ms);
                    break;
                case EVENT_BRANN_THINK:
                    Talk(BRANN_SAY_THINK);
                    events.ScheduleEvent(EVENT_BRANN_SET_ORIENTATION_1, 6s);
                    break;
                case EVENT_BRANN_SET_ORIENTATION_1:
                    me->SetFacingTo(5.445427f);
                    Talk(BRANN_SAY_MIRRORS);
                    events.ScheduleEvent(EVENT_BRANN_SET_ORIENTATION_2, 1s);
                    break;
                case EVENT_BRANN_SET_ORIENTATION_2:
                    me->SetFacingTo(0.6283185f);
                    events.ScheduleEvent(EVENT_BRANN_SET_ORIENTATION_3, 2500ms);
                    break;
                case EVENT_BRANN_SET_ORIENTATION_3:
                    me->SetFacingTo(0.01745329f);
                    events.ScheduleEvent(EVENT_BRANN_SAY_ELEMENTALS, 200ms);
                    break;
                case EVENT_BRANN_SAY_ELEMENTALS:
                    Talk(BRANN_SAY_ELEMENTALS);
                    events.ScheduleEvent(EVENT_BRANN_SAY_GET_IT, 3500ms);
                    break;
                case EVENT_BRANN_SAY_GET_IT:
                    Talk(BRANN_SAY_GET_IT);
                    me->SetNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                    break;
                case EVENT_BRANN_SET_ORIENTATION_4:
                    me->SetFacingTo(3.141593f);
                    break;
            }
        }
    }

    void MovementInform(uint32 movementType, uint32 pointId) override
    {
        if (movementType != POINT_MOTION_TYPE)
            return;

        _currentPoint = pointId + 1;
        Milliseconds delay = 1ms;

        switch (pointId)
        {
            case 0:
                Talk(BRANN_SAY_TROGGS);
                events.ScheduleEvent(EVENT_BRANN_THINK, 15s);
                return;
            case 1:
                Talk(BRANN_SAY_ANRAPHET_DIED);
                delay = 1s;
                break;
            case 14:
                Talk(BRANN_SAY_MOMENT);
                delay = 2200ms;
                break;
            case 16:
                events.ScheduleEvent(EVENT_BRANN_SET_ORIENTATION_4, 6s);
                return;
            default:
                break;
        }

        events.ScheduleEvent(EVENT_BRANN_MOVE_INTRO, delay);
    }

protected:
    EventMap events;
    uint32 _currentPoint;
    InstanceScript* _instance;
};

class spell_anraphet_alpha_beams : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_anraphet_alpha_beams::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// 77106 - Omega Stance (Summon)
class spell_anraphet_omega_stance_summon : public SpellScript
{
    void SetDest(SpellDestination& dest)
    {
        dest.RelocateOffset({ 0.0f, 0.0f, 30.0f, 0.0f });
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_anraphet_omega_stance_summon::SetDest, EFFECT_0, TARGET_DEST_DEST);
    }
};

void AddSC_boss_anraphet()
{
    RegisterHallsOfOriginationCreatureAI(boss_anraphet);
    RegisterHallsOfOriginationCreatureAI(npc_brann_bronzebeard_anraphet);
    RegisterHallsOfOriginationCreatureAI(npc_alpha_beam);
    RegisterHallsOfOriginationCreatureAI(npc_omega_stance);
    RegisterSpellScript(spell_anraphet_alpha_beams);
    RegisterSpellScript(spell_anraphet_omega_stance_summon);
}
