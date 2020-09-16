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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "PassiveAI.h"
#include "Player.h"
#include "SpellMgr.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "MotionMaster.h"
#include "TemporarySummon.h"
#include "blackwing_descent.h"

enum Spells
{
    // Omnotron
    SPELL_COUNCIL_ENERGY_DRAIN                  = 78725,
    SPELL_CONTROLLER_RECHARGE                   = 78696,
    SPELL_RECHARGING_ELECTRON                   = 78697,
    SPELL_RECHARGING_MAGMATRON                  = 78698,
    SPELL_RECHARGING_ARCANOTRON                 = 78699,
    SPELL_RECHARGING_TOXITRON                   = 78700,

    // Omnotron Defense System
    SPELL_INACTIVE                              = 78726,
    SPELL_POWERED_DOWN                          = 82265,
    SPELL_SHARED_HEALTH                         = 79920,
    SPELL_SHUTTING_DOWN                         = 78746,
    SPELL_INVISIBILITY_AND_STEALTH_DETECTION    = 67236,

    // Electron
    SPELL_ELECTRICAL_DISCHARGE_TRIGGER          = 95499,
    SPELL_ELECTRICAL_DISCHARGE                  = 79879,
    SPELL_UNSTABLE_SHIELD                       = 79900,
    SPELL_STATIC_SHOCK                          = 79912,
    SPELL_LIGHTNING_CONDUCTOR_10N               = 79888,

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
    SPELL_POWER_CONVERSION                      = 79729,

    // Poison Bomb
    SPELL_FIXATE_DUMMY                          = 80094,
    SPELL_QUIETE_SUICIDE                        = 3617,
    SPELL_POISON_BOMB_DAMAGE                    = 80092,
    SPELL_POISON_BOMB_SUMMON_PUDDLE             = 80089,

    // Power Generator
    SPELL_OVERCHARGED_POWER_GENERATOR           = 91857,
    SPELL_GROW_STACKER                          = 91861,
    SPELL_ARCANE_BLOWBACK                       = 91880,
    SPELL_POWER_GENERATOR_NORMAL                = 79628,

    // Lord Victor Nefarius
    SPELL_SHADOW_INFUSION                       = 92048,
    SPELL_SHADOW_TELEPORT                       = 91823,
    SPELL_SHADOW_TELEPORT_BACK                  = 91854,
    SPELL_GRIP_OF_DEATH                         = 91849,
    SPELL_SHADOW_CONDUCTOR                      = 92053,
    SPELL_ENCASING_SHADOWS                      = 92023,
    SPELL_OVERCHARGE                            = 91881
};

#define SPELL_LIGHTNING_CONDUCTOR   RAID_MODE<uint32>(79888, 91431, 91432, 91433)
#define SPELL_SOAKED_IN_POISON      RAID_MODE<uint32>(80011, 91504, 91505, 91506)
#define SPELL_ARCANE_ANNIHILATION   RAID_MODE<uint32>(79710, 91540, 91541, 91542)
#define SPELL_ACTIVATED             RAID_MODE<uint32>(78740, 95016, 95017, 95018)

enum Texts
{
    // Omnotron
    SAY_ACTIVATE_ELECTRON               = 0,
    SAY_ACTIVATE_TOXITRON               = 1,
    SAY_ACTIVATE_MAGMATRON              = 2,
    SAY_ACTIVATE_ARCANOTRON             = 3,
    SAY_SHIELD_ELECTRON                 = 4,
    SAY_SHIELD_TOXITRON                 = 5,
    SAY_SHIELD_ARCANOTRON               = 6,
    SAY_SHIELD_MAGMATRON                = 7,
    SAY_ACQUIRING_TARGET                = 8,
    SAY_POWERING_DOWN                   = 9,

    // Omnotron Defense System
    SAY_ANNOUNCE_ABILITY_1              = 0,
    SAY_ANNOUNCE_ABILITY_2              = 1,

    // Lord Victor Nefarius
    SAY_INTRO_HEROIC                    = 0,
    SAY_MANIPULATE_LIGHTNING_CONDUCTOR  = 1,
    SAY_PULL_INTO_CHEMICAL_CLOUD        = 2,
    SAY_ROOT_PLAYER_IN_PLACE            = 3,
    SAY_OVERCHARGE_POWER_GENERATOR      = 4
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
    EVENT_ARCANE_ANNIHILATION,
    EVENT_POWER_CONVERSION,

    // Lord Victor Nefarius
    EVENT_TALK_INTRO,
    EVENT_TELEPORT_INTO_CHEMICAL_CLOUD,
    EVENT_GRIP_OF_DEATH,
    EVENT_TALK_PULL_PLAYERS_INTO_CHEMICAL_CLOUD,
    EVENT_TELEPORT_BACK,
    EVENT_TALK_MANIPULATE_LIGHTNING_CONDUCTOR,
    EVENT_ENCASING_SHADOWS,
    EVENT_TALK_ROOT_PLAYER,
    EVENT_OVERCHARGE,
    EVENT_TALK_OVERCHARGE_POWER_GENERATOR,
    EVENT_CLEAR_ABILITY_COOLDOWN
};

enum Actions
{
    // Omnotron
    ACTION_GOLEM_ACTIVATED                  = 0,
    ACTION_START_ENCOUNTER                  = 1,
    ACTION_STOP_ENCOUNTER                   = 2,
    ACTION_FINISH_ENCOUNTER                 = 3,
    ACTION_SAY_ACQUIRING_TARGET             = 4,

    // Omnotron Defense System
    ACTION_ACTIVATE_GOLEM                   = 0,
    ACTION_DEACTIVATE_GOLEM                 = 1,

    // Magmatron
    ACTION_FAIL_STATIC_SHOCK_CRITERIA       = 2,
    ACTION_FAIL_POISON_BOMB_CRITERIA        = 3,
    ACTION_FAIL_ARCANE_ANNIHILATOR_CRITERIA = 4,
    ACTION_FAIL_FLAMETHROWER_CRITERIA       = 5,

    // Lord Victor Nefarius
    ACTION_CAST_SHADOW_INFUSION             = 0,
    ACTION_CAST_ENCASING_SHADOWS            = 1
};

enum Data
{
    // Omnotron
    DATA_NEXT_GOLEM_IN_QUEUE                = 0,
    DATA_SAY_GOLEM_SHIELD                   = 0,

    // Magmatron
    DATA_FAILED_CRITERIA_MASK               = 0
};

Position const FirstGolemPatrolStartPoint           = { -324.665f,  -398.085f,  213.8214f };
Position const LordVictorNefariusSummonPosition     = { -302.9167f, -350.4167f, 220.5673f, 4.537856f };

enum MovePoints
{
    POINT_START_WAYPOINTS = 1
};

enum SummonGroups
{
    SUMMON_GROUP_GOLEMS = 0
};

enum FailedAchievementCriteriaMask
{
    FAILED_CRITERIA_NONE                = 0x0,
    FAILED_CRITERIA_STATIC_SHOCK        = 0x1,
    FAILED_CRITERIA_POISON_BOMB         = 0x2,
    FAILED_CRITERIA_ARCANE_ANNIHILATOR  = 0x4,
    FAILED_CRITERIA_FLAMETHROWER        = 0x8
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
                if (IsHeroic())
                    DoSummon(NPC_LORD_VICTOR_NEFARIUS_OMNOTRON, LordVictorNefariusSummonPosition, 0, TEMPSUMMON_MANUAL_DESPAWN);

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
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SHADOW_CONDUCTOR);
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

    void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_ACTIVATED)
        {
            _events.ScheduleEvent(EVENT_LIGHTNING_CONDUCTOR, 16s);
            _events.ScheduleEvent(EVENT_ELECTRICAL_DISCHARGE, 6s);
            _events.ScheduleEvent(EVENT_UNSTABLE_SHIELD, IsHeroic() ? 40s : 50s);
        }
    }

    void SpellHitTarget(Unit* /*target*/, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_LIGHTNING_CONDUCTOR)
            if (IsHeroic())
                if (Creature* nefarius = _instance->GetCreature(DATA_LORD_VICTOR_NEFARIUS_OMNOTRON))
                    nefarius->AI()->DoAction(ACTION_CAST_SHADOW_INFUSION);
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
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
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
        _failedCriteriaMask = 0;
        me->SetReactState(REACT_PASSIVE);
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

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_FAILED_CRITERIA_MASK)
            return _failedCriteriaMask;

        return 0;
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
            case ACTION_FAIL_STATIC_SHOCK_CRITERIA:
                _failedCriteriaMask |= FAILED_CRITERIA_STATIC_SHOCK;
                break;
            case ACTION_FAIL_POISON_BOMB_CRITERIA:
                _failedCriteriaMask |= FAILED_CRITERIA_POISON_BOMB;
                break;
            case ACTION_FAIL_ARCANE_ANNIHILATOR_CRITERIA:
                _failedCriteriaMask |= FAILED_CRITERIA_ARCANE_ANNIHILATOR;
                break;
            case ACTION_FAIL_FLAMETHROWER_CRITERIA:
                _failedCriteriaMask |= FAILED_CRITERIA_FLAMETHROWER;
                break;
            default:
                break;
        }
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
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

            if (Creature* nefarius = _instance->GetCreature(DATA_LORD_VICTOR_NEFARIUS_OMNOTRON))
                nefarius->AI()->DoAction(ACTION_CAST_ENCASING_SHADOWS);
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
    uint32 _failedCriteriaMask;
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

    void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
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
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                        DoCast(target, SPELL_CHEMICAL_BOMB);
                    _events.Repeat(30s);
                    break;
                case EVENT_POISON_PROTOCOL:
                    me->StopMoving();
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
                me->MakeInterruptable(false);
                _events.Reset();
                break;
            default:
                break;
        }
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_ACTIVATED)
        {
            _events.ScheduleEvent(EVENT_POWER_GENERATOR, 16s);
            _events.ScheduleEvent(EVENT_ARCANE_ANNIHILATION, 3s + 300ms);
            _events.ScheduleEvent(EVENT_POWER_CONVERSION, IsHeroic() ? 40s : 50s);
        }
    }

    void OnSpellCastFinished(SpellInfo const* spell, SpellFinishReason /*reason*/) override
    {
        if (spell->Id == SPELL_ARCANE_ANNIHILATION)
            me->MakeInterruptable(false);
    }

    void SpellHitTarget(Unit* /*target*/, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_ARCANE_ANNIHILATION)
            if (Creature* magmatron = _instance->GetCreature(DATA_MAGMATRON))
                magmatron->AI()->DoAction(ACTION_FAIL_ARCANE_ANNIHILATOR_CRITERIA);
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
                case EVENT_ARCANE_ANNIHILATION:
                    me->MakeInterruptable(true);
                    if (!Is25ManRaid())
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                            DoCast(target, SPELL_ARCANE_ANNIHILATION);
                    }
                    else
                        DoCastAOE(SPELL_ARCANE_ANNIHILATION);
                    _events.Repeat(6s, 7s);
                    break;
                case EVENT_POWER_CONVERSION:
                    DoCastSelf(SPELL_POWER_CONVERSION);
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

struct npc_lord_victor_nefarius_omnotron : public PassiveAI
{
    npc_lord_victor_nefarius_omnotron(Creature* creature) : PassiveAI(creature), _instance(me->GetInstanceScript()), _abilitiesOnCooldown(false) { }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        _events.ScheduleEvent(EVENT_TALK_INTRO, 4s + 700ms);
    }

    void JustSummoned(Creature* summon) override
    {
        if (summon->GetEntry() != NPC_POWER_GENERATOR && summon->GetEntry() != NPC_CHEMICAL_CLOUD)
            return;

        TempSummon* summoned = summon->ToTempSummon();
        if (!summoned)
            return;

        // Lord Victor Nefarius only manipulates the abilities of longest active golem at a time
        if (!_abilitiesOnCooldown)
        {
            switch (summon->GetEntry())
            {
                case NPC_CHEMICAL_CLOUD:
                    _events.ScheduleEvent(EVENT_TELEPORT_INTO_CHEMICAL_CLOUD, 2s);
                    _abilitiesOnCooldown = true;
                    _events.ScheduleEvent(EVENT_CLEAR_ABILITY_COOLDOWN, 30s);
                    break;
                case NPC_POWER_GENERATOR:
                    _events.ScheduleEvent(EVENT_OVERCHARGE, 10s);
                    _abilitiesOnCooldown = true;
                    _events.ScheduleEvent(EVENT_CLEAR_ABILITY_COOLDOWN, 30s);
                    break;
                default:
                    break;
            }
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_CAST_SHADOW_INFUSION:
                if (Creature* electron = _instance->GetCreature(DATA_ELECTRON))
                {
                    if (!_abilitiesOnCooldown)
                    {
                        DoCastAOE(SPELL_SHADOW_INFUSION);
                        _events.ScheduleEvent(EVENT_TALK_MANIPULATE_LIGHTNING_CONDUCTOR, 6s);
                        _abilitiesOnCooldown = true;
                        _events.ScheduleEvent(EVENT_CLEAR_ABILITY_COOLDOWN, 30s);
                    }
                }
                break;
            case ACTION_CAST_ENCASING_SHADOWS:
                if (Creature* magmatron = _instance->GetCreature(DATA_MAGMATRON))
                {
                    if (!_abilitiesOnCooldown)
                    {
                        _events.ScheduleEvent(EVENT_ENCASING_SHADOWS, 300ms);
                        _abilitiesOnCooldown = true;
                        _events.ScheduleEvent(EVENT_CLEAR_ABILITY_COOLDOWN, 30s);
                    }
                }
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_TALK_INTRO:
                    Talk(SAY_INTRO_HEROIC);
                    break;
                case EVENT_TELEPORT_INTO_CHEMICAL_CLOUD:
                    DoCastSelf(SPELL_SHADOW_TELEPORT);
                    _events.ScheduleEvent(EVENT_GRIP_OF_DEATH, 100ms);
                    break;
                case EVENT_GRIP_OF_DEATH:
                    DoCastAOE(SPELL_GRIP_OF_DEATH);
                    _events.ScheduleEvent(EVENT_TALK_PULL_PLAYERS_INTO_CHEMICAL_CLOUD, 2s);
                    break;
                case EVENT_TALK_PULL_PLAYERS_INTO_CHEMICAL_CLOUD:
                    Talk(SAY_PULL_INTO_CHEMICAL_CLOUD);
                    _events.ScheduleEvent(EVENT_TELEPORT_BACK, 1s + 300ms);
                    break;
                case EVENT_TELEPORT_BACK:
                    DoCastSelf(SPELL_SHADOW_TELEPORT_BACK);
                    break;
                case EVENT_TALK_MANIPULATE_LIGHTNING_CONDUCTOR:
                    Talk(SAY_MANIPULATE_LIGHTNING_CONDUCTOR);
                    break;
                case EVENT_ENCASING_SHADOWS:
                    DoCastAOE(SPELL_ENCASING_SHADOWS);
                    _events.ScheduleEvent(EVENT_TALK_ROOT_PLAYER, 5s);
                    break;
                case EVENT_TALK_ROOT_PLAYER:
                    Talk(SAY_ROOT_PLAYER_IN_PLACE);
                    break;
                case EVENT_OVERCHARGE:
                    DoCastAOE(SPELL_OVERCHARGE);
                    _events.ScheduleEvent(EVENT_TALK_OVERCHARGE_POWER_GENERATOR, 5s + 400ms);
                    break;
                case EVENT_TALK_OVERCHARGE_POWER_GENERATOR:
                    Talk(SAY_OVERCHARGE_POWER_GENERATOR);
                    break;
                case EVENT_CLEAR_ABILITY_COOLDOWN:
                    _abilitiesOnCooldown = false;
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    InstanceScript* _instance;
    bool _abilitiesOnCooldown;
};

class DistanceCheck
{
    public:
        DistanceCheck(Unit* caster) : _caster(caster) { }

        bool operator()(WorldObject* object)
        {
            return (object->GetExactDist2d(_caster) < 10.0f);
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
        SelectTargetList(targets, 25, SELECT_TARGET_RANDOM, 0, 100.0f, true);

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
            me->ClearUnitState(UNIT_STATE_CASTING);
            AddThreat(target, 500000.0f);
            me->GetThreatManager().FixateTarget(target);
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
            if (InstanceScript* instance = me->GetInstanceScript())
                if (Creature* magmatron = instance->GetCreature(DATA_MAGMATRON))
                    magmatron->AI()->DoAction(ACTION_FAIL_POISON_BOMB_CRITERIA);

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
        OnObjectAreaTargetSelect.Register(&spell_omnotron_controller_recharge::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget.Register(&spell_omnotron_controller_recharge::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_omnotron_recharging : public AuraScript
{
    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode().HasFlag(AuraRemoveFlags::Expired))
            if (Creature* golem = GetTarget()->ToCreature())
                if (golem->IsAIEnabled)
                    golem->AI()->DoAction(ACTION_ACTIVATE_GOLEM);
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_omnotron_recharging::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_ENERGIZE, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_omnotron_activated : public AuraScript
{
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
        OnEffectPeriodic.Register(&spell_omnotron_activated::HandleTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        AfterEffectRemove.Register(&spell_omnotron_activated::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_omnotron_inactive : public SpellScript
{
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
        OnEffectHitTarget.Register(&spell_omnotron_inactive::HandleScriptEffect, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_omnotron_electrical_discharge_trigger : public SpellScript
{
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
        OnObjectAreaTargetSelect.Register(&spell_omnotron_electrical_discharge_trigger::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget.Register(&spell_omnotron_electrical_discharge_trigger::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_omnotron_electrical_discharge : public SpellScript
{
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
        OnEffectHitTarget.Register(&spell_omnotron_electrical_discharge::HandleDamageBonus, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
private:
    uint8 _chainTargetCount;
};

class spell_omnotron_unstable_shield : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_STATIC_SHOCK });
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

        caster->CastSpell(target, SPELL_STATIC_SHOCK, aurEff);

        if (InstanceScript* instance = caster->GetInstanceScript())
            if (Creature* magmatron = instance->GetCreature(DATA_MAGMATRON))
                magmatron->AI()->DoAction(ACTION_FAIL_STATIC_SHOCK_CRITERIA);
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_omnotron_unstable_shield::CheckProc);
        OnEffectProc.Register(&spell_omnotron_unstable_shield::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

class spell_omnotron_aquiring_target : public SpellScript
{
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
        OnObjectAreaTargetSelect.Register(&spell_omnotron_aquiring_target::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget.Register(&spell_omnotron_aquiring_target::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_omnotron_acquiring_target_periodic : public AuraScript
{
    void HandleTick(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget(), GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_omnotron_acquiring_target_periodic::HandleTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_omnotron_barrier : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BACKDRAFT });
    }

    void HandleAbsorbRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode().HasFlag(AuraRemoveFlags::ByEnemySpell))
            if (Unit* caster = GetCaster())
                caster->CastSpell(caster, SPELL_BACKDRAFT, true);
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_omnotron_barrier::HandleAbsorbRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_omnotron_shadow_infusion : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_SHADOW_CONDUCTOR,
                SPELL_LIGHTNING_CONDUCTOR_10N
            });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        target->RemoveAurasDueToSpell(sSpellMgr->GetSpellIdForDifficulty(SPELL_LIGHTNING_CONDUCTOR_10N, target));
        target->CastSpell(target, SPELL_SHADOW_CONDUCTOR, true);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_omnotron_shadow_infusion::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_omnotron_shadow_conductor : public SpellScript
{
    void ChangeDamage(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        if (!caster || !target)
            return;

        float distanceMultiplier = std::max(caster->GetExactDist2d(target) * 0.5f, 1.0f);
        SetEffectValue(int32(6000 * distanceMultiplier));
    }

    void Register() override
    {
        OnEffectLaunchTarget.Register(&spell_omnotron_shadow_conductor::ChangeDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

class spell_omnotron_overcharge : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_POWER_GENERATOR_NORMAL,
                SPELL_OVERCHARGED_POWER_GENERATOR,
                SPELL_GROW_STACKER,
                SPELL_ARCANE_BLOWBACK
            });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Creature* target = GetHitCreature();
        if (!target)
            return;

        target->RemoveAurasDueToSpell(sSpellMgr->GetSpellIdForDifficulty(SPELL_POWER_GENERATOR_NORMAL, target));
        target->CastSpell(target, SPELL_OVERCHARGED_POWER_GENERATOR, true);
        target->CastSpell(target, SPELL_GROW_STACKER);
        target->m_Events.AddEventAtOffset([target]()
        {
            target->RemoveAllAuras();
            target->CastSpell(target, SPELL_ARCANE_BLOWBACK);
            target->DespawnOrUnsummon(1s);
        }, 8s);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_omnotron_overcharge::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_omnotron_overcharged_power_generator : public AuraScript
{
    void HandlePeriodic(AuraEffect const* aurEff)
    {
        PreventDefaultAction();
        if (Unit* target = GetTarget())
        {
            uint32 triggerSpell = GetSpellInfo()->Effects[EFFECT_0].TriggerSpell;
            int32 radius = target->GetObjectScale() * 10000;
            target->CastSpell(nullptr, triggerSpell,  CastSpellExtraArgs(aurEff).SetOriginalCaster(target->GetGUID()).AddSpellMod(SPELLVALUE_RADIUS_MOD, radius));
        }
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_omnotron_overcharged_power_generator::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_omnotron_flamethrower : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.size() >= 2)
            if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                if (Creature* magmatron = instance->GetCreature(DATA_MAGMATRON))
                    magmatron->AI()->DoAction(ACTION_FAIL_FLAMETHROWER_CRITERIA);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_omnotron_flamethrower::FilterTargets, EFFECT_0, TARGET_UNIT_CONE_ENEMY_104);
    }
};

class achievement_achieve_a_tron_static_shock : public AchievementCriteriaScript
{
    public:
        achievement_achieve_a_tron_static_shock() : AchievementCriteriaScript("achievement_achieve_a_tron_static_shock") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (target && target->IsAIEnabled)
                return !(target->GetAI()->GetData(DATA_FAILED_CRITERIA_MASK) & FAILED_CRITERIA_STATIC_SHOCK);

            return false;
        }
};

class achievement_achieve_a_tron_poison_bomb : public AchievementCriteriaScript
{
    public:
        achievement_achieve_a_tron_poison_bomb() : AchievementCriteriaScript("achievement_achieve_a_tron_poison_bomb") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (target && target->IsAIEnabled)
                return !(target->GetAI()->GetData(DATA_FAILED_CRITERIA_MASK) & FAILED_CRITERIA_POISON_BOMB);

            return false;
        }
};

class achievement_achieve_a_tron_arcane_annihilator : public AchievementCriteriaScript
{
    public:
        achievement_achieve_a_tron_arcane_annihilator() : AchievementCriteriaScript("achievement_achieve_a_tron_arcane_annihilator") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (target && target->IsAIEnabled)
                return !(target->GetAI()->GetData(DATA_FAILED_CRITERIA_MASK) & FAILED_CRITERIA_ARCANE_ANNIHILATOR);

            return false;
        }
};

class achievement_achieve_a_tron_flamethrower : public AchievementCriteriaScript
{
    public:
        achievement_achieve_a_tron_flamethrower() : AchievementCriteriaScript("achievement_achieve_a_tron_flamethrower") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (target && target->IsAIEnabled)
                return !(target->GetAI()->GetData(DATA_FAILED_CRITERIA_MASK) & FAILED_CRITERIA_FLAMETHROWER);

            return false;
        }
};

void AddSC_boss_omnotron_defense_system()
{
    RegisterBlackwingDescentCreatureAI(boss_omnotron_defense_system);
    RegisterBlackwingDescentCreatureAI(npc_omnotron_electron);
    RegisterBlackwingDescentCreatureAI(npc_omnotron_magmatron);
    RegisterBlackwingDescentCreatureAI(npc_omnotron_toxitron);
    RegisterBlackwingDescentCreatureAI(npc_omnotron_arcanotron);
    RegisterBlackwingDescentCreatureAI(npc_lord_victor_nefarius_omnotron);
    RegisterBlackwingDescentCreatureAI(npc_omnotron_poison_bomb);
    RegisterSpellScript(spell_omnotron_controller_recharge);
    RegisterSpellScript(spell_omnotron_recharging);
    RegisterSpellScript(spell_omnotron_activated);
    RegisterSpellScript(spell_omnotron_inactive);
    RegisterSpellScript(spell_omnotron_electrical_discharge);
    RegisterSpellScript(spell_omnotron_electrical_discharge_trigger);
    RegisterSpellScript(spell_omnotron_unstable_shield);
    RegisterSpellScript(spell_omnotron_aquiring_target);
    RegisterSpellScript(spell_omnotron_acquiring_target_periodic);
    RegisterSpellScript(spell_omnotron_barrier);
    RegisterSpellScript(spell_omnotron_shadow_infusion);
    RegisterSpellScript(spell_omnotron_shadow_conductor);
    RegisterSpellScript(spell_omnotron_overcharge);
    RegisterSpellScript(spell_omnotron_overcharged_power_generator);
    RegisterSpellScript(spell_omnotron_flamethrower);
    new achievement_achieve_a_tron_static_shock;
    new achievement_achieve_a_tron_poison_bomb;
    new achievement_achieve_a_tron_arcane_annihilator;
    new achievement_achieve_a_tron_flamethrower;
}
