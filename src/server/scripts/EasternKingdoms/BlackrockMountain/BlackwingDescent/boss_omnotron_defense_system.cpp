/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "Player.h"
#include "blackwing_descent.h"

enum Spells
{
    // Omnotron
    SPELL_CONTROLLER_RECHARGE                   = 78696,
    SPELL_RECHARGING_ELECTRON                   = 78697,
    SPELL_RECHARGING_MAGMATRON                  = 78698,
    SPELL_RECHARGING_ARCANOTRON                 = 78699,
    SPELL_RECHARGING_TOXITRON                   = 78700,

    // Omnotron Defense System
    SPELL_INACTIVE                              = 78726,
    SPELL_POWERED_DOWN                          = 82265,
    SPELL_SHARED_HEALTH                         = 79920,
    SPELL_ACTIVATED                             = 78740,
    SPELL_SHUTTING_DOWN                         = 78746,
    SPELL_INVISIBILITY_AND_STEALTH_DETECTION    = 67236,

    // Electron
    SPELL_ELECTRICAL_DISCHARGE_TRIGGER          = 95499,
    SPELL_ELECTRICAL_DISCHARGE                  = 79879,
    SPELL_UNSTABLE_SHIELD                       = 79900,
    SPELL_STATIC_SHOCK                          = 79912,

    // Magmatron
    SPELL_INCINERATION_SECURITY_MEASURE         = 79023,
    SPELL_ACQUIRING_TARGET                      = 79499,
    SPELL_BARRIER                               = 79582,
    SPELL_BACKDRAFT                             = 79617,

    // Toxitron
    SPELL_CHEMICAL_BOMB                         = 80157,
    SPELL_POISON_PROTOCOL                       = 80053,
    SPELL_POISON_SOAKED_SHELL                   = 79835,

    // Arcanotron
    SPELL_POWER_GENERATOR                       = 79624,


    // Poison Bomb
    SPELL_FIXATE_DUMMY                          = 80094,
    SPELL_QUIETE_SUICIDE                        = 3617,
    SPELL_POISON_BOMB_DAMAGE                    = 80092,
    SPELL_POISON_BOMB_SUMMON_PUDDLE             = 80089
};

#define SPELL_LIGHTNING_CONDUCTOR   RAID_MODE<uint32>(79888, 91431, 91432, 91433)
#define SPELL_SOAKED_IN_POISON      RAID_MODE<uint32>(80011, 91504, 91505, 91506)

enum Texts
{
    // Omnotron
    SAY_ACTIVATE_ELECTRON   = 0,
    SAY_ACTIVATE_TOXITRON   = 1,
    SAY_ACTIVATE_MAGMATRON  = 2,
    SAY_ACTIVATE_ARCANOTRON = 3,

    SAY_SHIELD_ELECTRON     = 4,
    SAY_SHIELD_TOXITRON     = 5,
    SAY_SHIELD_ARCANOTRON   = 6,
    SAY_SHIELD_MAGMATRON    = 7,
    SAY_ACQUIRING_TARGET    = 8,
    SAY_POWERING_DOWN       = 9,

    // Omnotron Defense System
    SAY_ANNOUNCE_ABILITY_1  = 0,
    SAY_ANNOUNCE_ABILITY_2  = 1,
};

enum Events
{
    // Omnotron
    EVENT_LINK_GOLEM_HEALTH = 1,
    EVENT_POWER_UP_FIRST_GOLEM,
    EVENT_TALK_ACTIVATED_GOLEM,

    // Omnotron Defense System

    // Electron
    EVENT_LIGHTNING_CONDUCTOR,
    EVENT_ELECTRICAL_DISCHARGE,
    EVENT_UNSTABLE_SHIELD,

    // Magmatron
    EVENT_INCINERATION_SECURITY_MEASURE,
    EVENT_ACQUIRING_TARGET,
    EVENT_BARRIER,

    // Toxitron
    EVENT_CHEMICAL_BOMB,
    EVENT_POISON_PROTOCOL,
    EVENT_POISON_SOAKED_SHELL,

    // Arcanotron
    EVENT_POWER_GENERATOR,
};

enum Actions
{
    // Omnotron
    ACTION_GOLEM_ACTIVATED      = 0,
    ACTION_START_ENCOUNTER      = 1,
    ACTION_STOP_ENCOUNTER       = 2,
    ACTION_FINISH_ENCOUNTER     = 3,
    ACTION_SAY_ACQUIRING_TARGET = 4,

    // Omnotron Defense System
    ACTION_ACTIVATE_GOLEM       = 0,
    ACTION_DEACTIVATE_GOLEM     = 1
};

enum Data
{
    DATA_NEXT_GOLEM_IN_QUEUE    = 0,
    DATA_SAY_GOLEM_SHIELD       = 0
};

Position const FirstGolemPatrolStartPoint = { -324.665f, -398.085f, 213.8214f };

enum MovePoints
{
    POINT_START_WAYPOINTS = 1
};

enum SummonGroups
{
    SUMMON_GROUP_GOLEMS = 0
};

struct GolemInfo
{
    uint8 ActivateTextId;
    uint8 ShieldTextId;
};

std::unordered_map<uint32, GolemInfo> _golemInfoMap =
{
    { NPC_ELECTRON,     { SAY_ACTIVATE_ELECTRON,    SAY_SHIELD_ELECTRON     } },
    { NPC_MAGMATRON,    { SAY_ACTIVATE_MAGMATRON,   SAY_SHIELD_MAGMATRON    } },
    { NPC_ARCANOTRON,   { SAY_ACTIVATE_ARCANOTRON,  SAY_SHIELD_ARCANOTRON   } },
    { NPC_TOXITRON,     { SAY_ACTIVATE_TOXITRON,    SAY_SHIELD_TOXITRON     } }
};

struct boss_omnotron_defense_system : public BossAI
{
    boss_omnotron_defense_system(Creature* creature) : BossAI(creature, DATA_OMNOTRON_DEFENSE_SYSTEM)
    {
        Initialize();
    }

    void Initialize()
    {
        me->SetReactState(REACT_PASSIVE);
        _activatedGolemEntry = 0;
    }

    void Reset() override
    {
        Initialize();
        if (instance->GetBossState(DATA_OMNOTRON_DEFENSE_SYSTEM) == DONE)
            return;

        _Reset();
        me->SummonCreatureGroup(SUMMON_GROUP_GOLEMS);
        events.ScheduleEvent(EVENT_LINK_GOLEM_HEALTH, 5s);
        events.ScheduleEvent(EVENT_POWER_UP_FIRST_GOLEM, 10s);
    }

    void JustEngagedWith(Unit* target) override
    {
        target->HandleEmoteCommand(0);
    }

    void JustSummoned(Creature* summon) override
    {
        switch (summon->GetEntry())
        {
            case NPC_ELECTRON:
            case NPC_MAGMATRON:
            case NPC_TOXITRON:
            case NPC_ARCANOTRON:
                _golemGuidVector.push_back(summon->GetGUID());
                break;
            default:
                summons.Summon(summon);
                break;
        }
    }

    ObjectGuid GetGUID(int32 type) const override
    {
        switch (type)
        {
            case DATA_NEXT_GOLEM_IN_QUEUE:
                return _nextGolemGUID;
            default:
                return ObjectGuid::Empty;
        }

        return ObjectGuid::Empty;
    }

    void SetGUID(ObjectGuid const& guid, int32 type) override
    {
        if (type == DATA_SAY_GOLEM_SHIELD)
            if (Creature* golem = ObjectAccessor::GetCreature(*me, guid))
                Talk(_golemInfoMap[golem->GetEntry()].ShieldTextId);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_GOLEM_ACTIVATED:
                if (instance->GetBossState(DATA_OMNOTRON_DEFENSE_SYSTEM) == IN_PROGRESS)
                {
                    if (Creature* golem = ObjectAccessor::GetCreature(*me, _nextGolemGUID))
                    {
                        _activatedGolemEntry = golem->GetEntry();
                        events.ScheduleEvent(EVENT_TALK_ACTIVATED_GOLEM, 1s + 500ms);
                        golem->CastSpell(golem, SPELL_INVISIBILITY_AND_STEALTH_DETECTION, true);
                        golem->CastSpell(golem, SPELL_ACTIVATED);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, golem, 1);
                    }

                    SelectNextGolemGUID();
                    DoCastSelf(SPELL_CONTROLLER_RECHARGE, true);
                }
                break;
            case ACTION_START_ENCOUNTER:
                instance->SetBossState(DATA_OMNOTRON_DEFENSE_SYSTEM, IN_PROGRESS);

                for (ObjectGuid guid : _golemGuidVector)
                    if (Creature* golem = ObjectAccessor::GetCreature(*me, guid))
                        golem->AI()->DoZoneInCombat();

                // Since we blocked the first action call with our first golem we call it right away now to continue the cycle
                DoAction(ACTION_GOLEM_ACTIVATED);
                break;
            case ACTION_STOP_ENCOUNTER:
                for (ObjectGuid guid : _golemGuidVector)
                {
                    if (Creature* golem = ObjectAccessor::GetCreature(*me, guid))
                    {
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, golem);
                        golem->DespawnOrUnsummon();
                    }
                }
  
                instance->SetBossState(DATA_OMNOTRON_DEFENSE_SYSTEM, FAIL);
                RemoveDebuffsFromRaid();
                summons.DespawnAll();
                _DespawnAtEvade();
                break;
            case ACTION_FINISH_ENCOUNTER:
                if (instance->GetBossState(DATA_OMNOTRON_DEFENSE_SYSTEM) != DONE)
                {
                    Talk(SAY_POWERING_DOWN);
                    _JustDied();
                    for (ObjectGuid guid : _golemGuidVector)
                        if (Creature* golem = ObjectAccessor::GetCreature(*me, guid))
                            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, golem);
                    RemoveDebuffsFromRaid();
                }
                break;
            case ACTION_SAY_ACQUIRING_TARGET:
                Talk(SAY_ACQUIRING_TARGET);
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
                case EVENT_LINK_GOLEM_HEALTH:
                    for (ObjectGuid guid : _golemGuidVector)
                        if (Creature* golem = ObjectAccessor::GetCreature(*me, guid))
                            golem->CastSpell(golem, SPELL_SHARED_HEALTH, true);
                    break;
                case EVENT_POWER_UP_FIRST_GOLEM:
                    // Randomize our golem order for each encounter
                    Trinity::Containers::RandomShuffle(_golemGuidVector);
                    SelectNextGolemGUID();
                    DoCastSelf(SPELL_CONTROLLER_RECHARGE);
                    break;
                case EVENT_TALK_ACTIVATED_GOLEM:
                    Talk(_golemInfoMap[_activatedGolemEntry].ActivateTextId);
                    break;
                default:
                    break;
            }
        }
    }

private:
    GuidVector _golemGuidVector;
    ObjectGuid _nextGolemGUID;
    uint32 _activatedGolemEntry;

    // Selects the ObjectGuid for the next Golem
    void SelectNextGolemGUID()
    {
        _nextGolemGUID = _golemGuidVector.front();
        _golemGuidVector.erase(_golemGuidVector.begin());
        _golemGuidVector.push_back(_nextGolemGUID);
    }

    void RemoveDebuffsFromRaid()
    {
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_LIGHTNING_CONDUCTOR);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SOAKED_IN_POISON);
    }
};

struct npc_omnotron_electron : public ScriptedAI
{
    npc_omnotron_electron(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript())
    {
        Initialize();
    }

    void Initialize()
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetNoCallAssistance(true);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        if (_instance->GetBossState(DATA_OMNOTRON_DEFENSE_SYSTEM) != IN_PROGRESS)
        {
            if (Creature* omnotron = _instance->GetCreature(DATA_OMNOTRON_DEFENSE_SYSTEM))
                omnotron->AI()->DoAction(ACTION_START_ENCOUNTER);
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();

        if (Creature* omnotron = _instance->GetCreature(DATA_OMNOTRON_DEFENSE_SYSTEM))
            omnotron->AI()->DoAction(ACTION_STOP_ENCOUNTER);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* omnotron = _instance->GetCreature(DATA_OMNOTRON_DEFENSE_SYSTEM))
            omnotron->AI()->DoAction(ACTION_FINISH_ENCOUNTER);

        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (pointId == POINT_START_WAYPOINTS)
        {
            me->GetMotionMaster()->MovePath(BOSS_OMNOTRON * 100, true);
            me->SetWalk(true);
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_ACTIVATE_GOLEM:
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveAurasDueToSpell(SPELL_INACTIVE);
                me->RemoveAurasDueToSpell(SPELL_POWERED_DOWN);

                if (_instance->GetBossState(DATA_OMNOTRON_DEFENSE_SYSTEM) != IN_PROGRESS)
                {
                    me->SetWalk(true);
                    me->GetMotionMaster()->MovePoint(POINT_START_WAYPOINTS, FirstGolemPatrolStartPoint);
                }
                else
                    DoZoneInCombat();

                // Golem is online, time to inform the controller about it
                if (Creature* omnotron = _instance->GetCreature(DATA_OMNOTRON_DEFENSE_SYSTEM))
                    omnotron->AI()->DoAction(ACTION_GOLEM_ACTIVATED);
                break;
            case ACTION_DEACTIVATE_GOLEM:
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                _events.Reset();
                break;
            default:
                break;
        }
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spell)
    {
        if (spell->Id == SPELL_ACTIVATED)
        {
            _events.ScheduleEvent(EVENT_LIGHTNING_CONDUCTOR, 16s);
            _events.ScheduleEvent(EVENT_ELECTRICAL_DISCHARGE, 6s);
            _events.ScheduleEvent(EVENT_UNSTABLE_SHIELD, IsHeroic() ? 40s : 50s);
        }
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
                case EVENT_LIGHTNING_CONDUCTOR:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true, 0))
                    {
                        Talk(SAY_ANNOUNCE_ABILITY_1, target);
                        DoCast(target, SPELL_LIGHTNING_CONDUCTOR);
                        _events.Repeat(21s);
                    }
                    break;
                case EVENT_ELECTRICAL_DISCHARGE:
                    DoCastAOE(SPELL_ELECTRICAL_DISCHARGE);
                    _events.Repeat(6s);
                    break;
                case EVENT_UNSTABLE_SHIELD:
                    DoCastSelf(SPELL_UNSTABLE_SHIELD);
                    Talk(SAY_ANNOUNCE_ABILITY_2);
                    if (Creature* omnotron = _instance->GetCreature(DATA_OMNOTRON_DEFENSE_SYSTEM))
                        omnotron->AI()->SetGUID(me->GetGUID(), DATA_SAY_GOLEM_SHIELD);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    InstanceScript* _instance;
};

struct npc_omnotron_magmatron : public ScriptedAI
{
    npc_omnotron_magmatron(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript())
    {
        Initialize();
    }

    void Initialize()
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetNoCallAssistance(true);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        if (_instance->GetBossState(DATA_OMNOTRON_DEFENSE_SYSTEM) != IN_PROGRESS)
        {
            if (Creature* omnotron = _instance->GetCreature(DATA_OMNOTRON_DEFENSE_SYSTEM))
                omnotron->AI()->DoAction(ACTION_START_ENCOUNTER);
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();

        if (Creature* omnotron = _instance->GetCreature(DATA_OMNOTRON_DEFENSE_SYSTEM))
            omnotron->AI()->DoAction(ACTION_STOP_ENCOUNTER);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* omnotron = _instance->GetCreature(DATA_OMNOTRON_DEFENSE_SYSTEM))
            omnotron->AI()->DoAction(ACTION_FINISH_ENCOUNTER);

        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (pointId == POINT_START_WAYPOINTS)
        {
            me->GetMotionMaster()->MovePath(BOSS_OMNOTRON * 100, true);
            me->SetWalk(true);
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_ACTIVATE_GOLEM:
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveAurasDueToSpell(SPELL_INACTIVE);
                me->RemoveAurasDueToSpell(SPELL_POWERED_DOWN);

                if (_instance->GetBossState(DATA_OMNOTRON_DEFENSE_SYSTEM) != IN_PROGRESS)
                {
                    me->SetWalk(true);
                    me->GetMotionMaster()->MovePoint(POINT_START_WAYPOINTS, FirstGolemPatrolStartPoint);
                }
                else
                    DoZoneInCombat();

                // Golem is online, time to inform the controller about it
                if (Creature* omnotron = _instance->GetCreature(DATA_OMNOTRON_DEFENSE_SYSTEM))
                    omnotron->AI()->DoAction(ACTION_GOLEM_ACTIVATED);
                break;
            case ACTION_DEACTIVATE_GOLEM:
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                _events.Reset();
                break;
            default:
                break;
        }
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spell)
    {
        if (spell->Id == SPELL_ACTIVATED)
        {
            _events.ScheduleEvent(EVENT_INCINERATION_SECURITY_MEASURE, 10s + 500ms);
            _events.ScheduleEvent(EVENT_ACQUIRING_TARGET, 21s);
            _events.ScheduleEvent(EVENT_BARRIER, IsHeroic() ? 40s : 50s);
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_ACQUIRING_TARGET && target)
        {
            Talk(SAY_ANNOUNCE_ABILITY_1, target);
            if (Creature* omnotron = _instance->GetCreature(DATA_OMNOTRON_DEFENSE_SYSTEM))
                omnotron->AI()->DoAction(ACTION_SAY_ACQUIRING_TARGET);
        }
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
                case EVENT_INCINERATION_SECURITY_MEASURE:
                    DoCastAOE(SPELL_INCINERATION_SECURITY_MEASURE);
                    _events.Repeat(26s + 500ms);
                    break;
                case EVENT_ACQUIRING_TARGET:
                    DoCastAOE(SPELL_ACQUIRING_TARGET, true);
                    _events.Repeat(26s);
                    break;
                case EVENT_BARRIER:
                    DoCastSelf(SPELL_BARRIER);
                    if (Creature* omnotron = _instance->GetCreature(DATA_OMNOTRON_DEFENSE_SYSTEM))
                        omnotron->AI()->SetGUID(me->GetGUID(), DATA_SAY_GOLEM_SHIELD);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    InstanceScript* _instance;
};

struct npc_omnotron_toxitron : public ScriptedAI
{
    npc_omnotron_toxitron(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript())
    {
        Initialize();
    }

    void Initialize()
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetNoCallAssistance(true);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        if (_instance->GetBossState(DATA_OMNOTRON_DEFENSE_SYSTEM) != IN_PROGRESS)
        {
            if (Creature* omnotron = _instance->GetCreature(DATA_OMNOTRON_DEFENSE_SYSTEM))
                omnotron->AI()->DoAction(ACTION_START_ENCOUNTER);
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();

        if (Creature* omnotron = _instance->GetCreature(DATA_OMNOTRON_DEFENSE_SYSTEM))
            omnotron->AI()->DoAction(ACTION_STOP_ENCOUNTER);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* omnotron = _instance->GetCreature(DATA_OMNOTRON_DEFENSE_SYSTEM))
            omnotron->AI()->DoAction(ACTION_FINISH_ENCOUNTER);

        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (pointId == POINT_START_WAYPOINTS)
        {
            me->GetMotionMaster()->MovePath(BOSS_OMNOTRON * 100, true);
            me->SetWalk(true);
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_ACTIVATE_GOLEM:
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveAurasDueToSpell(SPELL_INACTIVE);
                me->RemoveAurasDueToSpell(SPELL_POWERED_DOWN);

                if (_instance->GetBossState(DATA_OMNOTRON_DEFENSE_SYSTEM) != IN_PROGRESS)
                {
                    me->SetWalk(true);
                    me->GetMotionMaster()->MovePoint(POINT_START_WAYPOINTS, FirstGolemPatrolStartPoint);
                }
                else
                    DoZoneInCombat();

                // Golem is online, time to inform the controller about it
                if (Creature* omnotron = _instance->GetCreature(DATA_OMNOTRON_DEFENSE_SYSTEM))
                    omnotron->AI()->DoAction(ACTION_GOLEM_ACTIVATED);
                break;
            case ACTION_DEACTIVATE_GOLEM:
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                _events.Reset();
                break;
            default:
                break;
        }
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spell)
    {
        if (spell->Id == SPELL_ACTIVATED)
        {
            _events.ScheduleEvent(EVENT_CHEMICAL_BOMB, 27s);
            _events.ScheduleEvent(EVENT_POISON_PROTOCOL, 16s);
            _events.ScheduleEvent(EVENT_POISON_SOAKED_SHELL, IsHeroic() ? 30s : 40s);
        }
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
                case EVENT_CHEMICAL_BOMB:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true, 0))
                        DoCast(target, SPELL_CHEMICAL_BOMB);
                    _events.Repeat(30s);
                    break;
                case EVENT_POISON_PROTOCOL:
                    DoCastSelf(SPELL_POISON_PROTOCOL);
                    break;
                case EVENT_POISON_SOAKED_SHELL:
                    DoCastSelf(SPELL_POISON_SOAKED_SHELL);
                    Talk(SAY_ANNOUNCE_ABILITY_1);
                    if (Creature* omnotron = _instance->GetCreature(DATA_OMNOTRON_DEFENSE_SYSTEM))
                        omnotron->AI()->SetGUID(me->GetGUID(), DATA_SAY_GOLEM_SHIELD);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    InstanceScript* _instance;
};

struct npc_omnotron_arcanotron : public ScriptedAI
{
    npc_omnotron_arcanotron(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript())
    {
        Initialize();
    }

    void Initialize()
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetNoCallAssistance(true);
        me->MakeInterruptable(false);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        if (_instance->GetBossState(DATA_OMNOTRON_DEFENSE_SYSTEM) != IN_PROGRESS)
        {
            if (Creature* omnotron = _instance->GetCreature(DATA_OMNOTRON_DEFENSE_SYSTEM))
                omnotron->AI()->DoAction(ACTION_START_ENCOUNTER);
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();

        if (Creature* omnotron = _instance->GetCreature(DATA_OMNOTRON_DEFENSE_SYSTEM))
            omnotron->AI()->DoAction(ACTION_STOP_ENCOUNTER);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* omnotron = _instance->GetCreature(DATA_OMNOTRON_DEFENSE_SYSTEM))
            omnotron->AI()->DoAction(ACTION_FINISH_ENCOUNTER);

        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (pointId == POINT_START_WAYPOINTS)
        {
            me->GetMotionMaster()->MovePath(BOSS_OMNOTRON * 100, true);
            me->SetWalk(true);
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_ACTIVATE_GOLEM:
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveAurasDueToSpell(SPELL_INACTIVE);
                me->RemoveAurasDueToSpell(SPELL_POWERED_DOWN);

                if (_instance->GetBossState(DATA_OMNOTRON_DEFENSE_SYSTEM) != IN_PROGRESS)
                {
                    me->SetWalk(true);
                    me->GetMotionMaster()->MovePoint(POINT_START_WAYPOINTS, FirstGolemPatrolStartPoint);
                }
                else
                    DoZoneInCombat();

                // Golem is online, time to inform the controller about it
                if (Creature* omnotron = _instance->GetCreature(DATA_OMNOTRON_DEFENSE_SYSTEM))
                    omnotron->AI()->DoAction(ACTION_GOLEM_ACTIVATED);
                break;
            case ACTION_DEACTIVATE_GOLEM:
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                _events.Reset();
                break;
            default:
                break;
        }
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spell)
    {
        if (spell->Id == SPELL_ACTIVATED)
        {
            _events.ScheduleEvent(EVENT_POWER_GENERATOR, 16s);

        }
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
                case EVENT_POWER_GENERATOR:
                    DoCastAOE(SPELL_POWER_GENERATOR);
                    _events.Repeat(20s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    InstanceScript* _instance;
};

class DistanceCheck
{
    public:
        DistanceCheck(Unit* caster) : _caster(caster) { }

        bool operator()(WorldObject* object)
        {
            if (Unit* unit = object->ToUnit())
                return !unit->IsWithinMeleeRange(_caster);

            return true;
        }
    private:
        Unit* _caster;
};

struct npc_omnotron_poison_bomb : public ScriptedAI
{
    npc_omnotron_poison_bomb(Creature* creature) : ScriptedAI(creature) { }

    void IsSummonedBy(Unit* summoner) override
    {
        DoZoneInCombat();

        // Blizzard has a AOE target spell for this but for some reason they doesn't use it so we wont do so as well.
        std::list<Unit*> targets;
        SelectTargetList(targets, 25, SELECT_TARGET_RANDOM, 100.0f, true);

        if (targets.empty())
            return;

        std::list<Unit*> targetsCopy = targets;
        targets.remove_if(DistanceCheck(summoner));

        if (targets.empty())
            targets = targetsCopy;

        Trinity::Containers::RandomResize(targets, 1);

        if (Unit* target = targets.front())
        {
            DoCast(target, SPELL_FIXATE_DUMMY, true);
            me->AddThreat(target, 500000.0f);
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->DespawnOrUnsummon(2s + 500ms);
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_QUIETE_SUICIDE)
        {
            DoCastSelf(SPELL_POISON_BOMB_DAMAGE, true);
            DoCastSelf(SPELL_POISON_BOMB_SUMMON_PUDDLE, true);
        }
    }
};

class GuidCheck
{
    public:
        GuidCheck(ObjectGuid golemGUID) : _golemGUID(golemGUID)  { }

        bool operator()(WorldObject* object)
        {
            return object->GetGUID() != _golemGUID;
        }
    private:
        ObjectGuid _golemGUID;
};

class spell_omnotron_controller_recharge : public SpellScript
{
    PrepareSpellScript(spell_omnotron_controller_recharge);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_RECHARGING_ELECTRON,
                SPELL_RECHARGING_MAGMATRON,
                SPELL_RECHARGING_TOXITRON,
                SPELL_RECHARGING_ARCANOTRON
            });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        InstanceScript* instance = GetCaster()->GetInstanceScript();
        if (!instance)
            return;

        Creature* omnotron = instance->GetCreature(DATA_OMNOTRON_DEFENSE_SYSTEM);
        if (!omnotron)
            return;

        ObjectGuid golemGuid = omnotron->AI()->GetGUID(DATA_NEXT_GOLEM_IN_QUEUE);
        targets.remove_if(GuidCheck(golemGuid));
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
        {
            uint32 rechargingSpellId = 0;
            switch (GetHitUnit()->GetEntry())
            {
                case NPC_ELECTRON:
                    rechargingSpellId = SPELL_RECHARGING_ELECTRON;
                    break;
                case NPC_MAGMATRON:
                    rechargingSpellId = SPELL_RECHARGING_MAGMATRON;
                    break;
                case NPC_TOXITRON:
                    rechargingSpellId = SPELL_RECHARGING_TOXITRON;
                    break;
                case NPC_ARCANOTRON:
                    rechargingSpellId = SPELL_RECHARGING_ARCANOTRON;
                    break;
                default:
                    break;
            }

            if (rechargingSpellId)
                caster->CastSpell(caster, rechargingSpellId);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_omnotron_controller_recharge::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_omnotron_controller_recharge::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_omnotron_recharging : public AuraScript
{
    PrepareAuraScript(spell_omnotron_recharging);

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
            if (Creature* golem = GetTarget()->ToCreature())
                if (golem->IsAIEnabled)
                    golem->AI()->DoAction(ACTION_ACTIVATE_GOLEM);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_omnotron_recharging::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_ENERGIZE, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_omnotron_activated : public AuraScript
{
    PrepareAuraScript(spell_omnotron_activated);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHUTTING_DOWN });
    }

    void HandleTick(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        if (Unit* caster = GetCaster())
            if (caster->GetVictim())
            if (caster->GetVictim())
                caster->CastSpell(GetCaster()->GetVictim(), GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, TriggerCastFlags(TRIGGERED_FULL_MASK & ~TRIGGERED_IGNORE_POWER_AND_REAGENT_COST));
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_SHUTTING_DOWN);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_omnotron_activated::HandleTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_omnotron_activated::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_omnotron_inactive : public SpellScript
{
    PrepareSpellScript(spell_omnotron_inactive);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_RECHARGING_ELECTRON });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        target->CastSpell(target, SPELL_POWERED_DOWN, true);
        if (Creature* golem = target->ToCreature())
            if (golem->IsAIEnabled)
                golem->AI()->DoAction(ACTION_DEACTIVATE_GOLEM);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_omnotron_inactive::HandleScriptEffect, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_omnotron_electrical_discharge_trigger : public SpellScript
{
    PrepareSpellScript(spell_omnotron_electrical_discharge_trigger);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_omnotron_electrical_discharge_trigger::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_omnotron_electrical_discharge_trigger::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_omnotron_electrical_discharge : public SpellScript
{
    PrepareSpellScript(spell_omnotron_electrical_discharge);

    bool Load() override
    {
        _chainTargetCount = 0;
        return true;
    }

    void HandleDamageBonus(SpellEffIndex /*effIndex*/)
    {
        int32 damage = GetHitDamage();
        AddPct(damage, _chainTargetCount * 20);
        _chainTargetCount++;
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_omnotron_electrical_discharge::HandleDamageBonus, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
private:
    uint8 _chainTargetCount;
};

class spell_omnotron_unstable_shield : public AuraScript
{
    PrepareAuraScript(spell_omnotron_unstable_shield);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_STATIC_SHOCK
            });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        return eventInfo.GetDamageInfo();
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        Unit* caster = GetTarget();
        Unit* target = eventInfo.GetDamageInfo()->GetAttacker();
        if (!target)
            return;

        caster->CastSpell(target, SPELL_STATIC_SHOCK, true, nullptr, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_omnotron_unstable_shield::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_omnotron_unstable_shield::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

class spell_omnotron_aquiring_target : public SpellScript
{
    PrepareSpellScript(spell_omnotron_aquiring_target);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
        {
            caster->StopMoving();
            caster->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints, true);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_omnotron_aquiring_target::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_omnotron_aquiring_target::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_omnotron_acquiring_target_periodic : public AuraScript
{
    PrepareAuraScript(spell_omnotron_acquiring_target_periodic);

    void HandleTick(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget(), GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_omnotron_acquiring_target_periodic::HandleTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_omnotron_barrier : public AuraScript
{
    PrepareAuraScript(spell_omnotron_barrier);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BACKDRAFT });
    }

    void HandleAbsorbRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_ENEMY_SPELL)
            if (Unit* caster = GetCaster())
                caster->CastSpell(caster, SPELL_BACKDRAFT, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_omnotron_barrier::HandleAbsorbRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_omnotron_defense_system()
{
    RegisterBlackwingDescentCreatureAI(boss_omnotron_defense_system);
    RegisterBlackwingDescentCreatureAI(npc_omnotron_electron);
    RegisterBlackwingDescentCreatureAI(npc_omnotron_magmatron);
    RegisterBlackwingDescentCreatureAI(npc_omnotron_toxitron);
    RegisterBlackwingDescentCreatureAI(npc_omnotron_arcanotron);
    RegisterBlackwingDescentCreatureAI(npc_omnotron_poison_bomb);
    RegisterSpellScript(spell_omnotron_controller_recharge);
    RegisterAuraScript(spell_omnotron_recharging);
    RegisterAuraScript(spell_omnotron_activated);
    RegisterSpellScript(spell_omnotron_inactive);
    RegisterSpellScript(spell_omnotron_electrical_discharge);
    RegisterSpellScript(spell_omnotron_electrical_discharge_trigger);
    RegisterAuraScript(spell_omnotron_unstable_shield);
    RegisterSpellScript(spell_omnotron_aquiring_target);
    RegisterAuraScript(spell_omnotron_acquiring_target_periodic);
    RegisterAuraScript(spell_omnotron_barrier);
}
