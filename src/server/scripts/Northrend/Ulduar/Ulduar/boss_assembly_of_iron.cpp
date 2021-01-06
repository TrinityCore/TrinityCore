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
#include "AreaBoundary.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "Spell.h"
#include "TemporarySummon.h"
#include "ulduar.h"

enum Spells
{
    // General
    SPELL_SUPERCHARGE                           = 61920,
    SPELL_BERSERK                               = 62535,
    SPELL_KILL_CREDIT                           = 65195, // Serverside spell

    // Steelbreaker
    SPELL_HIGH_VOLTAGE                          = 61890,
    SPELL_STATIC_DISRUPTION                     = 61911,
    SPELL_STATIC_DISRUPTION_TRIGGERED           = 61912,
    SPELL_ELECTRICAL_CHARGE                     = 61902,
    SPELL_FUSION_PUNCH                          = 61903,
    SPELL_OVERWHELMING_POWER                    = 64637,

    // Runemaster Molgeim
    SPELL_RUNE_OF_POWER_PRE_FIGHT               = 61975,
    SPELL_RUNE_OF_POWER                         = 61973,
    SPELL_SHIELD_OF_RUNES                       = 62274,
    SPELL_SHIELD_OF_RUNES_BUFF                  = 62277,
    SPELL_RUNE_OF_DEATH                         = 62269,
    SPELL_RUNE_OF_SUMMONING                     = 62273,
    SPELL_RUNE_OF_SUMMONING_SUMMON              = 62020,

    // Stormcaller Brundir
    SPELL_LIGHTNING_CHANNEL_PRE_FIGHT_VISUAL    = 61942,
    SPELL_CHAIN_LIGHTNING                       = 61879,
    SPELL_LIGHTNING_WHIRL                       = 61915,
    SPELL_LIGHTNING_TENDRILS                    = 61887,
    SPELL_LIGHTNING_TENDRILS_VISUAL             = 61883,
    SPELL_STORMSHIELD                           = 64187,
    SPELL_RANDOM_AGGRO_PERIODIC                 = 61906,

    // Lightning Elemental
    SPELL_LIGHTNING_ELEMENTAL_PASSIVE           = 62052
};

// Needed for OnSpellCastFinished hook in Stormcaller Brundir's script
#define SPELL_OVERLOAD RAID_MODE<uint32>(61869, 63481)

enum Events
{
    // Steelbreaker
    EVENT_FUSION_PUNCH = 1,
    EVENT_STATIC_DISRUPTION,
    EVENT_OVERWHELMING_POWER,

    // Runemaster Molgeim
    EVENT_RUNE_OF_POWER_INTRO,
    EVENT_RUNE_OF_POWER,
    EVENT_SHIELD_OF_RUNES,
    EVENT_RUNE_OF_DEATH,
    EVENT_RUNE_OF_SUMMONING,

    // Stormcaller Brundir
    EVENT_MOVE_INTRO,
    EVENT_CHAIN_LIGHTNING,
    EVENT_OVERLOAD,
    EVENT_LIGHTNING_WHIRL,
    EVENT_LIGHTNING_TENDRILS,
    EVENT_FLIGHT,
    EVENT_LAND
};

enum Phases : uint8
{
    PHASE_INTRO = 1,
    PHASE_ONE   = 2,
    PHASE_TWO   = 3,
    PHASE_THREE = 4
};

enum Actions
{
    ACTION_SUPERCHARGE = 1,
    ACTION_ADD_CHARGE,
    ACTION_BERSERK_TRIGGERED
};

enum Texts
{
    // Steelbreaker
    SAY_STEELBREAKER_AGGRO              = 0,
    SAY_STEELBREAKER_SLAY               = 1,
    SAY_STEELBREAKER_POWER              = 2,
    SAY_STEELBREAKER_DEATH              = 3,
    SAY_STEELBREAKER_ENCOUNTER_DEFEATED = 4,
    SAY_STEELBREAKER_BERSERK            = 5,

    // Runemaster Molgeim
    SAY_MOLGEIM_AGGRO                   = 0,
    SAY_MOLGEIM_SLAY                    = 1,
    SAY_MOLGEIM_RUNE_DEATH              = 2,
    SAY_MOLGEIM_SUMMON                  = 3,
    SAY_MOLGEIM_DEATH                   = 4,
    SAY_MOLGEIM_ENCOUNTER_DEFEATED      = 5,
    SAY_MOLGEIM_BERSERK                 = 6,

    // Stormcaller Brundir
    SAY_BRUNDIR_AGGRO                   = 0,
    SAY_BRUNDIR_SLAY                    = 1,
    SAY_BRUNDIR_SPECIAL                 = 2,
    SAY_BRUNDIR_FLIGHT                  = 3,
    SAY_BRUNDIR_DEATH                   = 4,
    SAY_BRUNDIR_ENCOUNTER_DEFEATED      = 5,
    SAY_BRUNDIR_BERSERK                 = 6,
    EMOTE_BRUNDIR_OVERLOAD              = 7
};

enum MovePoints
{
    POINT_ID_MOVE_INTRO = 1,
    POINT_ID_FLIGHT_START,
    POINT_ID_LAND
};

enum Misc
{
    NPC_WORLD_TRIGGER   = 22515,
    DATA_PHASE_3        = 1
};

std::array<Position, 8> BrundirIntroWaypoints =
{
    Position(1563.3f,  120.467f, 427.3189f),
    Position(1567.86f, 129.128f, 427.3189f),
    Position(1567.87f, 111.979f, 427.3189f),
    Position(1576.02f, 107.71f, 427.3189f),
    Position(1576.19f, 133.968f, 427.3189f),
    Position(1584.52f, 111.742f, 427.3189f),
    Position(1584.58f, 129.175f, 427.3189f),
    Position(1588.82f, 120.42f, 427.3189f)
};

CircleBoundary const AssemblyBoundary({ 1587.2f, 121.0f }, 90.0f);
CreatureBoundary const ArenaBoundaries = { &AssemblyBoundary };

namespace AOIEncounterHelper
{
    void CleanupAuras(Creature const* creature, InstanceScript* instance)
    {
        instance->DoRemoveAurasDueToSpellOnPlayers(sSpellMgr->GetSpellIdForDifficulty(SPELL_FUSION_PUNCH, creature));
        instance->DoRemoveAurasDueToSpellOnPlayers(sSpellMgr->GetSpellIdForDifficulty(SPELL_OVERWHELMING_POWER, creature));
        instance->DoRemoveAurasDueToSpellOnPlayers(sSpellMgr->GetSpellIdForDifficulty(SPELL_STATIC_DISRUPTION_TRIGGERED, creature));
    }
}

struct boss_steelbreaker : public ScriptedAI
{
    boss_steelbreaker(Creature* creature) : ScriptedAI(creature), _instance(nullptr) { }

    void InitializeAI() override
    {
        // For dynamic linking compatability
        _instance = me->GetInstanceScript();
        SetBoundary(&ArenaBoundaries);
    }

    void JustEngagedWith(Unit* who) override
    {
        if (_instance->GetBossState(DATA_ASSEMBLY_OF_IRON) != IN_PROGRESS)
        {
            _instance->SetBossState(DATA_ASSEMBLY_OF_IRON, IN_PROGRESS);
            Talk(SAY_STEELBREAKER_AGGRO, who);
        }

        DoZoneInCombat();

        for (uint32 type : { DATA_RUNEMASTER_MOLGEIM, DATA_STORMCALLER_BRUNDIR })
            if (Creature* golem = _instance->GetCreature(type))
                DoZoneInCombat(golem);

        DoCastSelf(SPELL_HIGH_VOLTAGE);
        DoCastSelf(SPELL_BERSERK);
        _events.SetPhase(PHASE_ONE);
        _events.ScheduleEvent(EVENT_FUSION_PUNCH, 15s);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        AOIEncounterHelper::CleanupAuras(me, _instance);
        _instance->SetBossState(DATA_ASSEMBLY_OF_IRON, FAIL);
    }

    void KilledUnit(Unit* who) override
    {
        if (who->IsPlayer())
        {
            Talk(SAY_STEELBREAKER_SLAY, who);
            DoAction(ACTION_ADD_CHARGE);
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (_events.IsInPhase(PHASE_THREE))
        {
            AOIEncounterHelper::CleanupAuras(me, _instance);
            _instance->SetBossState(DATA_ASSEMBLY_OF_IRON, DONE);
            DoCastAOE(SPELL_KILL_CREDIT, true);
            Talk(SAY_STEELBREAKER_ENCOUNTER_DEFEATED);
        }
        else
        {
            me->SetLootRecipient(nullptr);
            Talk(SAY_STEELBREAKER_DEATH);
            DoCastAOE(SPELL_SUPERCHARGE);
        }
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_PHASE_3)
            return uint8(_events.IsInPhase(PHASE_THREE));

        return 0;
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_SUPERCHARGE:
                _events.SetPhase(!_events.IsInPhase(PHASE_TWO) ? PHASE_TWO : PHASE_THREE);
                _events.RescheduleEvent(EVENT_FUSION_PUNCH, 13s, 22s);

                if (_events.IsInPhase(PHASE_TWO) || _events.IsInPhase(PHASE_THREE))
                    _events.RescheduleEvent(EVENT_STATIC_DISRUPTION, 20s, 40s);

                if (_events.IsInPhase(PHASE_THREE))
                    _events.RescheduleEvent(EVENT_OVERWHELMING_POWER, 2s, 5s);
                break;
            case ACTION_ADD_CHARGE:
                if (_events.IsInPhase(PHASE_THREE))
                    DoCastSelf(SPELL_ELECTRICAL_CHARGE, true);
                break;
            case ACTION_BERSERK_TRIGGERED:
                Talk(SAY_STEELBREAKER_BERSERK);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() || !CheckInRoom())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING) || me->HasSpellFocus())
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_FUSION_PUNCH:
                    DoCastVictim(SPELL_FUSION_PUNCH);
                    _events.Repeat(13s, 22s);
                    break;
                case EVENT_STATIC_DISRUPTION:
                {
                    // Steelbreaker prefers ranged targets above melee targets but falls back to melee targets if no ranged target is available
                    Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, -10.f, true);
                    if (!target)
                        target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.f, true);

                    DoCast(target, SPELL_STATIC_DISRUPTION);
                    _events.Repeat(20s, 40s);
                    break;
                }
                case EVENT_OVERWHELMING_POWER:
                    Talk(SAY_STEELBREAKER_POWER);
                    DoCastVictim(SPELL_OVERWHELMING_POWER);
                    _events.Repeat(RAID_MODE(60s, 35s));
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
    EventMap _events;
    InstanceScript* _instance;
};

struct boss_runemaster_molgeim : public ScriptedAI
{
    boss_runemaster_molgeim(Creature* creature) : ScriptedAI(creature), _instance(nullptr), _summons(me) { }

    void InitializeAI() override
    {
        // For dynamic linking compatability
        _instance = me->GetInstanceScript();
        SetBoundary(&ArenaBoundaries);
    }

    void JustAppeared() override
    {
        _events.SetPhase(PHASE_INTRO);
        _events.ScheduleEvent(EVENT_RUNE_OF_POWER_INTRO, 300ms, 0, PHASE_INTRO);
    }

    void JustEngagedWith(Unit* who) override
    {
        if (_instance->GetBossState(DATA_ASSEMBLY_OF_IRON) != IN_PROGRESS)
        {
            _instance->SetBossState(DATA_ASSEMBLY_OF_IRON, IN_PROGRESS);
            Talk(SAY_MOLGEIM_AGGRO, who);
        }

        DoZoneInCombat();
        me->InterruptNonMeleeSpells(true);

        for (uint32 type : { DATA_STEELBREAKER, DATA_STORMCALLER_BRUNDIR })
            if (Creature* golem = _instance->GetCreature(type))
                DoZoneInCombat(golem);

        DoCastSelf(SPELL_BERSERK);

        _events.SetPhase(PHASE_ONE);
        _events.ScheduleEvent(EVENT_RUNE_OF_POWER, 28s);
        _events.ScheduleEvent(EVENT_SHIELD_OF_RUNES, 45s);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        AOIEncounterHelper::CleanupAuras(me, _instance);
        _summons.DespawnAll();
        _instance->SetBossState(DATA_ASSEMBLY_OF_IRON, FAIL);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (_events.IsInPhase(PHASE_THREE))
        {
            AOIEncounterHelper::CleanupAuras(me, _instance);
            _summons.DespawnAll();
            me->RemoveAllDynObjects();
            _instance->SetBossState(DATA_ASSEMBLY_OF_IRON, DONE);
            DoCastAOE(SPELL_KILL_CREDIT, true);
            Talk(SAY_MOLGEIM_ENCOUNTER_DEFEATED);
        }
        else
        {
            me->SetLootRecipient(nullptr);
            Talk(SAY_MOLGEIM_DEATH);
            DoCastAOE(SPELL_SUPERCHARGE);
        }
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_MOLGEIM_SLAY);
    }

    void JustSummoned(Creature* summon) override
    {
        _summons.Summon(summon);
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_PHASE_3)
            return uint8(_events.IsInPhase(PHASE_THREE));

        return 0;
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_SUPERCHARGE:
                _events.SetPhase(!_events.IsInPhase(PHASE_TWO) ? PHASE_TWO : PHASE_THREE);
                if (_events.IsInPhase(PHASE_TWO))
                    _events.ScheduleEvent(EVENT_RUNE_OF_DEATH, 37s);
                else if (_events.IsInPhase(PHASE_THREE))
                    _events.ScheduleEvent(EVENT_RUNE_OF_SUMMONING, 13s);
                break;
            case ACTION_BERSERK_TRIGGERED:
                Talk(SAY_MOLGEIM_BERSERK);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if ((!UpdateVictim() || !CheckInRoom()) && !_events.IsInPhase(PHASE_INTRO))
            return;

        _events.Update(diff);

        if ((me->HasUnitState(UNIT_STATE_CASTING) || me->HasSpellFocus()) && !_events.IsInPhase(PHASE_INTRO))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_RUNE_OF_POWER_INTRO:
                    DoCastSelf(SPELL_RUNE_OF_POWER_PRE_FIGHT);
                    _events.Repeat(11s);
                    break;
                case EVENT_RUNE_OF_POWER:
                {
                    std::vector<Creature*> aliveBosses = { me };
                    if (Creature* steelbreaker = _instance->GetCreature(DATA_STEELBREAKER))
                        if (steelbreaker->IsAlive())
                            aliveBosses.push_back(steelbreaker);

                    if (Creature* brundir = _instance->GetCreature(DATA_STORMCALLER_BRUNDIR))
                        if (brundir->IsAlive())
                            aliveBosses.push_back(brundir);

                    if (Creature* target = Trinity::Containers::SelectRandomContainerElement(aliveBosses))
                        DoCast(target, SPELL_RUNE_OF_POWER);

                    _events.Repeat(32s, 47s);
                    break;
                }
                case EVENT_SHIELD_OF_RUNES:
                    DoCastSelf(SPELL_SHIELD_OF_RUNES);
                    _events.Repeat(32s, 48s);
                    break;
                case EVENT_RUNE_OF_DEATH:
                    Talk(SAY_MOLGEIM_RUNE_DEATH);
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, SPELL_RUNE_OF_DEATH);
                    _events.Repeat(47s, 54s);
                    break;
                case EVENT_RUNE_OF_SUMMONING:
                    Talk(SAY_MOLGEIM_SUMMON);
                    _summons.RemoveNotExisting(); // Keeping the summon list clean
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, SPELL_RUNE_OF_SUMMONING);
                    _events.Repeat(23s, 33s);
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
    EventMap _events;
    InstanceScript* _instance;
    SummonList _summons;
};

struct boss_stormcaller_brundir : public ScriptedAI
{
    boss_stormcaller_brundir(Creature* creature) : ScriptedAI(creature), _instance(nullptr), _summons(me) { }

    void InitializeAI() override
    {
        // For dynamic linking compatability
        _instance = me->GetInstanceScript();
        SetBoundary(&ArenaBoundaries);
    }

    void JustAppeared() override
    {
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, false);  // Should be interruptable unless overridden by spell (Overload)
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, false);       // Reset immumity, Brundir should be stunnable by default
        _events.SetPhase(PHASE_INTRO);
        _events.ScheduleEvent(EVENT_MOVE_INTRO, 300ms, 0, PHASE_INTRO);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        AOIEncounterHelper::CleanupAuras(me, _instance);
        _instance->SetBossState(DATA_ASSEMBLY_OF_IRON, FAIL);
    }

    void JustEngagedWith(Unit* who) override
    {
        me->GetMotionMaster()->Initialize();

        if (_instance->GetBossState(DATA_ASSEMBLY_OF_IRON) != IN_PROGRESS)
        {
            _instance->SetBossState(DATA_ASSEMBLY_OF_IRON, IN_PROGRESS);
            Talk(SAY_BRUNDIR_AGGRO, who);
        }

        DoZoneInCombat();
        me->InterruptNonMeleeSpells(true);

        for (uint32 type : { DATA_STEELBREAKER, DATA_RUNEMASTER_MOLGEIM })
            if (Creature* golem = _instance->GetCreature(type))
                DoZoneInCombat(golem);

        DoCastSelf(SPELL_BERSERK);

        _events.SetPhase(PHASE_ONE);
        _events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 1ms); 
        _events.ScheduleEvent(EVENT_OVERLOAD, 42s, 1min);
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_PHASE_3)
            return uint8(_events.IsInPhase(PHASE_THREE));

        return 0;
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (_events.IsInPhase(PHASE_THREE))
        {
            AOIEncounterHelper::CleanupAuras(me, _instance);
            _instance->SetBossState(DATA_ASSEMBLY_OF_IRON, DONE);
            DoCastAOE(SPELL_KILL_CREDIT, true);
            Talk(SAY_BRUNDIR_ENCOUNTER_DEFEATED);
        }
        else
        {
            me->SetLootRecipient(nullptr);
            Talk(SAY_BRUNDIR_DEATH);
            DoCastAOE(SPELL_SUPERCHARGE);
        }
    }

    void KilledUnit(Unit* who) override
    {
        if (who->IsPlayer())
            Talk(SAY_BRUNDIR_SLAY);
    }

    void JustSummoned(Creature* summon) override
    {
        _summons.Summon(summon);
    }

    void OnSpellCastFinished(SpellInfo const* spell, SpellFinishReason reason) override
    {
        if (spell->Id == SPELL_OVERLOAD && (reason == SPELL_FINISHED_CHANNELING_COMPLETE || reason == SPELL_FINISHED_CANCELED))
            _summons.DespawnAll();
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_SUPERCHARGE:
                _events.SetPhase(!_events.IsInPhase(PHASE_TWO) ? PHASE_TWO : PHASE_THREE);
                if (_events.IsInPhase(PHASE_TWO) || _events.IsInPhase(PHASE_THREE))
                    _events.RescheduleEvent(EVENT_LIGHTNING_WHIRL, 13s, 15s);

                if (_events.IsInPhase(PHASE_THREE))
                {
                    me->InterruptNonMeleeSpells(true);
                    DoCastSelf(SPELL_STORMSHIELD);
                    me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true); // Apply immumity to stuns
                    _events.ScheduleEvent(EVENT_LIGHTNING_TENDRILS, 48s, 50s);
                }
                break;
            case ACTION_BERSERK_TRIGGERED:
                Talk(SAY_BRUNDIR_BERSERK);
                break;
            default:
                break;
        }
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != EFFECT_MOTION_TYPE && type != POINT_MOTION_TYPE)
            return;

        switch (pointId)
        {
            case POINT_ID_MOVE_INTRO:
                DoCastSelf(SPELL_LIGHTNING_CHANNEL_PRE_FIGHT_VISUAL);
                _events.ScheduleEvent(EVENT_MOVE_INTRO, 4s + 500ms, 0, PHASE_INTRO);
                break;
            case POINT_ID_FLIGHT_START:
                me->SetHover(true);
                break;
            case POINT_ID_LAND:
                me->SetHover(false);
                me->RemoveAurasDueToSpell(sSpellMgr->GetSpellIdForDifficulty(SPELL_LIGHTNING_TENDRILS, me));
                me->RemoveAurasDueToSpell(SPELL_LIGHTNING_TENDRILS_VISUAL);
                ResetThreatList();
                me->SetReactState(REACT_AGGRESSIVE);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if ((!UpdateVictim() || !CheckInRoom()) && !_events.IsInPhase(PHASE_INTRO))
            return;

        _events.Update(diff);

        if ((me->HasUnitState(UNIT_STATE_CASTING) || me->HasSpellFocus()) && !_events.IsInPhase(PHASE_INTRO))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_MOVE_INTRO:
                {
                    me->ReleaseSpellFocus(me->GetCurrentSpell(CURRENT_CHANNELED_SPELL), false);
                    me->InterruptNonMeleeSpells(true);
                    // Generate new random waypoints if we run out of them.
                    if (_potentialWaypoints.empty())
                    {
                        std::copy(BrundirIntroWaypoints.begin(), BrundirIntroWaypoints.end(), std::back_inserter(_potentialWaypoints));
                        Trinity::Containers::RandomShuffle(_potentialWaypoints);
                    }

                    Position const dest = _potentialWaypoints.front();
                    _potentialWaypoints.erase(_potentialWaypoints.begin());

                    me->GetMotionMaster()->MovePoint(POINT_ID_MOVE_INTRO, dest);
                    break;
                }
                case EVENT_CHAIN_LIGHTNING:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, SPELL_CHAIN_LIGHTNING);
                    _events.Repeat(6s, 8s);
                    break;
                case EVENT_OVERLOAD:
                    Talk(EMOTE_BRUNDIR_OVERLOAD);
                    Talk(SAY_BRUNDIR_SPECIAL);
                    DoCast(SPELL_OVERLOAD);
                    _events.Repeat(42s, 1min);
                    break;
                case EVENT_LIGHTNING_WHIRL:
                    DoCastSelf(SPELL_LIGHTNING_WHIRL);
                    _events.Repeat(15s, 20s);
                    break;
                case EVENT_LIGHTNING_TENDRILS:
                {
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    me->StopMoving();

                    Talk(SAY_BRUNDIR_FLIGHT);
                    DoCastSelf(SPELL_LIGHTNING_TENDRILS);
                    DoCastSelf(SPELL_LIGHTNING_TENDRILS_VISUAL);

                    me->GetMotionMaster()->MoveTakeoff(POINT_ID_FLIGHT_START, { me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 10.f }, 7.5f);
                    _events.DelayEvents(29s);
                    _events.ScheduleEvent(EVENT_FLIGHT, 2s + 500ms);
                    _events.ScheduleEvent(EVENT_LAND, 23s);
                    _events.Repeat(88s);
                    break;
                }
                case EVENT_FLIGHT:
                    DoCastSelf(SPELL_RANDOM_AGGRO_PERIODIC);
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                case EVENT_LAND:
                    me->RemoveAurasDueToSpell(SPELL_RANDOM_AGGRO_PERIODIC);
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    me->GetMotionMaster()->MoveLand(POINT_ID_LAND, { me->GetPositionX(), me->GetPositionY(), me->GetFloorZ() }, 3.75f);
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
    EventMap _events;
    InstanceScript* _instance;
    SummonList _summons;
    std::vector<Position> _potentialWaypoints;
};

struct npc_assembly_lightning_elemental : public ScriptedAI
{
    npc_assembly_lightning_elemental(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        if (InstanceScript* instance = me->GetInstanceScript())
            if (Creature* molgeim = instance->GetCreature(DATA_RUNEMASTER_MOLGEIM))
                if (molgeim->IsAIEnabled)
                    molgeim->AI()->JustSummoned(me);
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_LIGHTNING_ELEMENTAL_PASSIVE);

        if (Unit* target = me->SelectNearestTarget(100.f, true))
            me->EngageWithTarget(target);
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->DespawnOrUnsummon(2s);
    }
};

class spell_assembly_shield_of_runes : public AuraScript
{
    void AfterRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            if (GetTargetApplication()->GetRemoveMode().HasFlag(AuraRemoveFlags::ByEnemySpell) && aurEff->GetAmount() <= 0)
                caster->CastSpell(caster, SPELL_SHIELD_OF_RUNES_BUFF, false);
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_assembly_shield_of_runes::AfterRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_assembly_meltdown : public SpellScript
{
    void HandleInstaKill(SpellEffIndex /*effIndex*/)
    {
        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
            if (Creature* steelbreaker = instance->GetCreature(DATA_STEELBREAKER))
                if (steelbreaker->IsAIEnabled)
                    steelbreaker->AI()->DoAction(ACTION_ADD_CHARGE);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_assembly_meltdown::HandleInstaKill, EFFECT_1, SPELL_EFFECT_INSTAKILL);
    }
};

class spell_assembly_rune_of_summoning : public AuraScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_RUNE_OF_SUMMONING_SUMMON });
    }

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(GetTarget(), SPELL_RUNE_OF_SUMMONING_SUMMON, { aurEff, GetTarget()->IsSummon() ? GetTarget()->ToTempSummon()->GetSummonerGUID() : ObjectGuid::Empty });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (TempSummon* summ = GetTarget()->ToTempSummon())
            summ->DespawnOrUnsummon(1);
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_assembly_rune_of_summoning::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        OnEffectRemove.Register(&spell_assembly_rune_of_summoning::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_assembly_random_aggro_periodic : public AuraScript
{
    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        GetTarget()->GetThreatManager().ResetAllThreat();
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_assembly_random_aggro_periodic::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class spell_assembly_supercharge : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([&](WorldObject const* target)
        {
            Unit const* unitTarget = target->ToUnit();
            return (!unitTarget || unitTarget == GetCaster() || unitTarget->isDead());
        });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Creature* target = GetHitCreature())
            if (target->IsAIEnabled)
                target->AI()->DoAction(ACTION_SUPERCHARGE);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_assembly_supercharge::FilterTargets, EFFECT_ALL, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget.Register(&spell_assembly_supercharge::HandleScriptEffect, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_assembly_berserk : public AuraScript
{
    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        if (Creature* target = GetTarget()->ToCreature())
            if (target->IsAIEnabled)
                target->AI()->DoAction(ACTION_BERSERK_TRIGGERED);
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_assembly_berserk::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_assembly_lightning_tendrils_visual : public SpellScript
{
    void SetDest(SpellDestination& dest)
    {
        Position oldDest = dest._position;
        oldDest.m_positionZ = GetCaster()->GetFloorZ();

        // The caster is hovering high in the air so default target selections do not work.
        float dist = GetSpellInfo()->Effects[EFFECT_0].CalcRadius(GetCaster()) * float(rand_norm());
        float angle = frand(0.f, float(M_PI * 2));
        oldDest.m_positionX += std::cos(angle) * dist;
        oldDest.m_positionY += std::sin(angle) * dist;
        dest.Relocate(oldDest);
    }

    void Register()
    {
        OnDestinationTargetSelect.Register(&spell_assembly_lightning_tendrils_visual::SetDest, EFFECT_0, TARGET_DEST_CASTER_RANDOM);
    }
};

class achievement_assembly_i_choose_you : public AchievementCriteriaScript
{
    public:
        achievement_assembly_i_choose_you() : AchievementCriteriaScript("achievement_assembly_i_choose_you") { }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            return target && target->GetAI()->GetData(DATA_PHASE_3);
        }
};

void AddSC_boss_assembly_of_iron()
{
    RegisterUlduarCreatureAI(boss_steelbreaker);
    RegisterUlduarCreatureAI(boss_runemaster_molgeim);
    RegisterUlduarCreatureAI(boss_stormcaller_brundir);
    RegisterUlduarCreatureAI(npc_assembly_lightning_elemental);
    RegisterSpellScript(spell_assembly_shield_of_runes);
    RegisterSpellScript(spell_assembly_meltdown);
    RegisterSpellScript(spell_assembly_rune_of_summoning);
    RegisterSpellScript(spell_assembly_random_aggro_periodic);
    RegisterSpellScript(spell_assembly_supercharge);
    RegisterSpellScript(spell_assembly_berserk);
    RegisterSpellScript(spell_assembly_lightning_tendrils_visual);
    new achievement_assembly_i_choose_you();
}
