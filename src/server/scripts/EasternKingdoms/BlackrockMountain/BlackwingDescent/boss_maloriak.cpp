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
#include "CommonPredicates.h"
#include "DBCStores.h"
#include "GridNotifiers.h"
#include "PassiveAI.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "TemporarySummon.h"
#include "MapInstanced.h"
#include "blackwing_descent.h"

enum Spells
{
    // Maloriak
    SPELL_ARCANE_STORM                  = 77896,
    SPELL_REMEDY                        = 77912,
    SPELL_THROW_RED_BOTTLE              = 77925,
    SPELL_THROW_BLUE_BOTTLE             = 77932,
    SPELL_THROW_GREEN_BOTTLE            = 77937,
    SPELL_DRINK_RED_BOTTLE              = 88699,
    SPELL_DRINK_BLUE_BOTTLE             = 88700,
    SPELL_DRINK_BLACK_BOTTLE            = 92828,
    SPELL_FIRE_IMBUED                   = 78896,
    SPELL_FROST_IMBUED                  = 78895,
    SPELL_SHADOW_IMBUED                 = 92716,
    SPELL_SLIME_IMBUED                  = 92917,
    SPELL_THROW_RED_BOTTLE_TRIGGERED    = 77928,
    SPELL_THROW_BLUE_BOTTLE_TRIGGERED   = 77934,
    SPELL_THROW_GREEN_BOTTLE_TRIGGERED  = 77938,
    SPELL_RELEASE_ABERRATIONS           = 77569,
    SPELL_RELEASE_ALL_MINIONS           = 77991,
    SPELL_SCORCHING_BLAST               = 77679,
    SPELL_BITING_CHILL                  = 77760,
    SPELL_FLASH_FREEZE_TARGETING        = 97693,
    SPELL_DRINK_ALL_BOTTLES             = 95662,
    SPELL_UNSTABLE_MIX                  = 95663,
    SPELL_MAGMA_JETS_SCRIPT_EFFECT      = 93022,
    SPELL_MAGMA_JETS_SUMMON             = 78194,
    SPELL_ACID_NOVA                     = 78225,
    SPELL_ABSOLUTE_ZERO                 = 78223,
    SPELL_ENGULFING_DARKNESS            = 92754,
    SPELL_VILE_SWILL                    = 92720,
    SPELL_VILE_SWILL_SUMMON             = 92724,

    // Cauldron Trigger
    SPELL_DEBILITATING_SLIME_CAST       = 77602,
    SPELL_DEBILITATING_SLIME_KNOCKBACK  = 77948,
    SPELL_DEBILITATING_SLIME_DEBUFF     = 77615,

    // Flash Freeze
    SPELL_FLASH_FREEZE_VISUAL           = 77712,
    SPELL_SHATTER                       = 77715,

    // Experiments
    SPELL_DROWNED_STATE                 = 77564,
    SPELL_GROWTH_CATALYST               = 77987,

    // Magma Jet
    SPELL_MAGMA_JETS_SUMMON_FIRE        = 78094,
    SPELL_MAGMA_JETS_ERUPTION           = 78095,

    // Absolute Zero
    SPELL_ABSOLUTE_ZERO_TRANSFORM       = 78201,
    SPELL_ABSOLUTE_ZERO_EXPLOSION       = 78208,

    // Lord Victor Nefarius
    SPELL_TELEPORT_VISUAL_ONLY          = 41232,
    SPELL_THROW_BLACK_BOTTLE            = 92831,
    SPELL_THROW_BLACK_BOTTLE_TRIGGERED  = 92837,
    SPELL_MASTER_ADVENTURER_AWARD       = 89798,

    // Vile Swill
    SPELL_DARK_SLUDGE                   = 92929,

    // Player
    SPELL_FLASH_FREEZE_SUMMON           = 77711,
    SPELL_FLASH_FREEZE_DUMMY            = 77716,
    SPELL_FLASH_FREEZE_STUN_NORMAL      = 77699

};

#define SPELL_FLASH_FREEZE_STUN RAID_MODE<uint32>(77699, 92978, 92979, 92980)
#define SPELL_CONSUMING_FLAMES RAID_MODE<uint32>(77786, 92971, 92972, 92973)

enum Events
{
    // Maloriak
    EVENT_ARCANE_STORM = 1,
    EVENT_REMEDY,
    EVENT_RELEASE_ABERRATIONS,
    EVENT_FACE_TO_CAULDRON,
    EVENT_THROW_VIAL,
    EVENT_MOVE_TO_CAULDRON,
    EVENT_DRINK_BOTTLE,
    EVENT_IMBUED_BUFF,
    EVENT_EXPLODE_CAULDRON,
    EVENT_ATTACK_PLAYERS,
    EVENT_CONSUMING_FLAMES,
    EVENT_SCORCHING_BLAST,
    EVENT_BITING_CHILL,
    EVENT_FLASH_FREEZE,
    EVENT_ENTER_PHASE_TWO,
    EVENT_DRINK_ALL_BOTTLES,
    EVENT_UNSTABLE_MIX,
    EVENT_MAGMA_JETS,
    EVENT_ACID_NOVA,
    EVENT_ABSOLUTE_ZERO,
    EVENT_MOVE_AWAY_FROM_CAULDRON,
    EVENT_ENGULFING_DARKNESS,
    EVENT_VILE_SWILL,

    // Experiments
    EVENT_LEAP_OUT_OF_CHAMBER,

    // Lord Victor Nefarius
    EVENT_MOCK_MALORIAK,
    EVENT_THROW_BLACK_BOTTLE,
    EVENT_LAND,
    EVENT_SAY_MALORIAK_DEAD,
    EVENT_MASTER_ADVENTURER_AWARD,
    EVENT_TELEPORT_AWAY,

    // Vile Swill
    EVENT_DARK_SLUDGE
};

enum Phases
{
    PHASE_ONE = 1,
    PHASE_TWO = 2
};

enum Actions
{
    // Maloriak
    ACTION_SCHEDULE_EVENTS_FOR_PHASE    = 1,

    // Experiments
    ACTION_RELEASE_EXPERIMENT           = 1,

    // Lord Victor Nefarius
    ACTION_THROW_BLACK_BOTTLE           = 1,
    ACTION_MALORIAK_DEAD                = 2
};

enum MovePoints
{
    // Maloriak
    POINT_NONE      = 0,
    POINT_CAULDRON  = 1,

    // Experiments
    POINT_GROUND    = 1,

    // Lord Victor Nefarius
    POINT_LAND      = 1
};

enum Texts
{
    // Maloriak
    SAY_AGGRO               = 0,
    SAY_RED_VIAL            = 1,
    SAY_ANNOUNCE_RED_VIAL   = 2,
    SAY_BLUE_VIAL           = 3,
    SAY_ANNOUNCE_BLUE_VIAL  = 4,
    SAY_GREEN_VIAL          = 5,
    SAY_ANNOUNCE_GREEN_VIAL = 6,
    SAY_RELEASE_ABERRATIONS = 7,
    SAY_RELEASE_ALL_MINIONS = 8,
    SAY_SLAY                = 9,
    SAY_DEATH               = 10,

    // Lord Victor Nefarius
    SAY_MOCK_MALORIAK       = 0,
    SAY_THROW_BLACK_BOTTLE  = 1,
    SAY_ANNOUNCE_BLACK_VIAL = 2,
    SAY_MALORIAK_DEAD       = 3
};

enum Vials
{
    VIAL_RED    = 0,
    VIAL_BLUE   = 1,
    VIAL_GREEN  = 2,
    VIAL_BLACK  = 3
};

enum GameObjectCustomAnim
{
    CUSTOM_ANIM_RED_CAULDRON    = 0,
    CUSTOM_ANIM_BLUE_CAULDRON   = 1,
    CUSTOM_ANIM_GREEN_CAULDRON  = 2,
    CUSTOM_ANIM_BLACK_CAULDRON  = 3
};

Position const CauldronMovePosition             = { -106.6782f, -475.4438f, 73.45684f };
Position const LordVictorNefariusSummonPosition = { -105.9514f, -494.0278f, 89.33157f, 1.605703f };
Position const LordVictorNefariusLandPosition   = { -105.9514f, -494.0278f, 73.44659f };

struct VialData
{
    uint8 SayTextId;
    uint8 AnnounceTextId;
    uint32 ThrowSpellId;
    uint32 DrinkSpellId;
    uint32 ImbuedSpellId;
};

enum Misc
{
    SUMMON_GROUP_EXPERIMENTS            = 0,
    SPAWN_GROUP_GROWTH_CHAMBERS         = 401,
    AI_ANIM_KIT_ID_LORD_VICTOR_NEFARIUS = 1173,
    TITLE_ADVENTURER_AWARD              = 188
};

std::unordered_map<uint8, VialData> vialData =
{
    { VIAL_RED,    { SAY_RED_VIAL,      SAY_ANNOUNCE_RED_VIAL,      SPELL_THROW_RED_BOTTLE,     SPELL_DRINK_RED_BOTTLE,    SPELL_FIRE_IMBUED   }},
    { VIAL_BLUE,   { SAY_BLUE_VIAL,     SAY_ANNOUNCE_BLUE_VIAL,     SPELL_THROW_BLUE_BOTTLE,    SPELL_DRINK_BLUE_BOTTLE,   SPELL_FROST_IMBUED  }},
    { VIAL_GREEN,  { SAY_GREEN_VIAL,    SAY_ANNOUNCE_GREEN_VIAL,    SPELL_THROW_GREEN_BOTTLE,   0,                         SPELL_SLIME_IMBUED  }},
    { VIAL_BLACK,  { 0,                 0,                          0,                          SPELL_DRINK_BLACK_BOTTLE,  SPELL_SHADOW_IMBUED  }},
};

struct boss_maloriak : public BossAI
{
    boss_maloriak(Creature* creature) : BossAI(creature, DATA_MALORIAK),
        _currentVial(0), _usedVialsCount(0), _vialsPerCycle(IsHeroic() ? 3 : 2), _releasedAberrationsCount(0) { }

    void Reset() override
    {
        _Reset();
        me->MakeInterruptable(false);
    }

    void JustAppeared() override
    {
        instance->instance->SpawnGroupSpawn(SPAWN_GROUP_GROWTH_CHAMBERS, true);
        me->SummonCreatureGroup(SUMMON_GROUP_EXPERIMENTS);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        events.SetPhase(PHASE_ONE);
        events.ScheduleEvent(EVENT_FACE_TO_CAULDRON, 15s + 500ms, 0, PHASE_ONE);

        if (IsHeroic())
            DoSummon(NPC_LORD_VICTOR_NEFARIUS_MALORIAK, LordVictorNefariusSummonPosition, 0, TEMPSUMMON_MANUAL_DESPAWN);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        if (Creature* nefarius = instance->GetCreature(DATA_LORD_VICTOR_NEFARIUS_MALORIAK))
            nefarius->DespawnOrUnsummon();
        CleanupEncounter();
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        CleanupEncounter();
        _JustDied();

        if (Creature * nefarius = instance->GetCreature(DATA_LORD_VICTOR_NEFARIUS_MALORIAK))
            if (nefarius->IsAIEnabled)
                nefarius->AI()->DoAction(ACTION_MALORIAK_DEAD);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY, victim);
    }

    void JustSummoned(Creature* summon) override
    {
        switch (summon->GetEntry())
        {
            case NPC_LORD_VICTOR_NEFARIUS_MALORIAK:
                break;
            case NPC_ABSOLUTE_ZERO:
                summon->GetMotionMaster()->MoveRandom(10.0f);
                summon->CastSpell(summon, SPELL_ABSOLUTE_ZERO_TRANSFORM);
                summons.Summon(summon);
                break;
            default:
                summons.Summon(summon);
                break;
        }
    }

    void OnSpellCastFinished(SpellInfo const* spell, SpellFinishReason reason) override
    {
        switch (spell->Id)
        {
            case SPELL_ARCANE_STORM:
                if (reason == SPELL_FINISHED_CHANNELING_COMPLETE || reason == SPELL_FINISHED_CANCELED)
                {
                    me->MakeInterruptable(false);
                    me->m_Events.KillAllEvents(true);
                }
                break;
            case SPELL_RELEASE_ABERRATIONS:
                me->MakeInterruptable(false);
                if (reason == SPELL_FINISHED_SUCCESSFUL_CAST)
                {
                    Talk(SAY_RELEASE_ABERRATIONS);
                    ++_releasedAberrationsCount;
                }
                break;
            default:
                break;
        }
    }

    void MovementInform(uint32 motionType, uint32 pointId) override
    {
        if (motionType != POINT_MOTION_TYPE && motionType != EFFECT_MOTION_TYPE)
            return;

        switch (pointId)
        {
            case POINT_CAULDRON:
                events.ScheduleEvent(EVENT_DRINK_BOTTLE, 1s + 500ms);
                break;
            default:
                break;
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_SCHEDULE_EVENTS_FOR_PHASE:
                if (_currentVial != VIAL_BLACK)
                    events.ScheduleEvent(EVENT_ATTACK_PLAYERS, _currentVial != VIAL_GREEN ? 1ms : 4s);
                events.ScheduleEvent(EVENT_FACE_TO_CAULDRON, _currentVial == VIAL_BLACK ? 1min + 30s : 40s, 0, PHASE_ONE);

                switch (_currentVial)
                {
                    case VIAL_RED:
                        events.ScheduleEvent(EVENT_ARCANE_STORM, 15s + 500ms, 0, PHASE_ONE);
                        events.ScheduleEvent(EVENT_REMEDY, 20s + 500ms, 0, PHASE_ONE);
                        events.ScheduleEvent(EVENT_RELEASE_ABERRATIONS, 11s, 0, PHASE_ONE);
                        events.ScheduleEvent(EVENT_CONSUMING_FLAMES, 7s, 8s, 0, PHASE_ONE);
                        events.ScheduleEvent(EVENT_SCORCHING_BLAST, 19s, 22s, 0, PHASE_ONE);
                        break;
                    case VIAL_BLUE:
                        events.ScheduleEvent(EVENT_ARCANE_STORM, 6s, 0, PHASE_ONE);
                        events.ScheduleEvent(EVENT_REMEDY, 21s + 500ms, 0, PHASE_ONE);
                        events.ScheduleEvent(EVENT_RELEASE_ABERRATIONS, 14s + 500ms, 0, PHASE_ONE);
                        events.ScheduleEvent(EVENT_BITING_CHILL, 13s, 14s, 0, PHASE_ONE);
                        events.ScheduleEvent(EVENT_FLASH_FREEZE, 17s, 0, PHASE_ONE);
                        break;
                    case VIAL_GREEN:
                        if (Creature* cauldron = instance->GetCreature(DATA_CAULDRON_TRIGGER))
                            cauldron->CastSpell(cauldron, SPELL_DEBILITATING_SLIME_DEBUFF);

                        events.ScheduleEvent(EVENT_ARCANE_STORM, 5s, 0, PHASE_ONE);
                        events.ScheduleEvent(EVENT_REMEDY, 7s + 500ms, 0, PHASE_ONE);
                        events.ScheduleEvent(EVENT_RELEASE_ABERRATIONS, 9s, 0, PHASE_ONE);
                        break;
                    case VIAL_BLACK:
                        me->GetMotionMaster()->MovePoint(POINT_NONE, me->GetHomePosition());
                        events.ScheduleEvent(EVENT_VILE_SWILL, 2s, 0, PHASE_ONE);
                        events.ScheduleEvent(EVENT_ENGULFING_DARKNESS, 8s, 0, PHASE_ONE);
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthBelowPctDamaged(25, damage) && !events.IsInPhase(PHASE_TWO))
        {
            events.SetPhase(PHASE_TWO);
            events.ScheduleEvent(EVENT_ENTER_PHASE_TWO, 1ms, 0, PHASE_TWO);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ARCANE_STORM:
                {
                    me->MakeInterruptable(true);
                    DoCastSelf(SPELL_ARCANE_STORM);
                    Creature* maloriak = me;
                    me->m_Events.AddEventAtOffset([maloriak]() { maloriak->MakeInterruptable(false); }, 6s + 500ms);
                    events.Repeat(15s + 500ms, 17s);
                    break;
                }
                case EVENT_REMEDY:
                    DoCastSelf(SPELL_REMEDY);
                    events.Repeat(24s);
                    break;
                case EVENT_RELEASE_ABERRATIONS:
                    if (_releasedAberrationsCount < 6)
                    {
                        me->MakeInterruptable(true);
                        DoCastAOE(SPELL_RELEASE_ABERRATIONS);
                        events.Repeat(17s, 18s);
                    }
                    break;
                case EVENT_FACE_TO_CAULDRON:
                    events.Reset();
                    if (Creature* cauldron = instance->GetCreature(DATA_CAULDRON_TRIGGER))
                    {
                        me->AttackStop();
                        me->SetReactState(REACT_PASSIVE);
                        me->ClearUnitState(UNIT_STATE_ROOT);
                        me->SetFacingToObject(cauldron);

                        if (!_usedVialsCount && IsHeroic())
                            _currentVial = VIAL_BLACK;
                        else
                        {
                            if ((_currentVial == VIAL_BLACK || _currentVial == VIAL_GREEN) && _usedVialsCount < _vialsPerCycle)
                                _currentVial = urand(VIAL_RED, VIAL_BLUE);
                            else if (_usedVialsCount == _vialsPerCycle)
                                _currentVial = VIAL_GREEN;
                            else
                                _currentVial = _currentVial == VIAL_BLUE ? VIAL_RED : VIAL_BLUE;
                        }

                        if (_currentVial != VIAL_BLACK)
                            Talk(vialData[_currentVial].SayTextId);
                        else if (Creature * nefarius = instance->GetCreature(DATA_LORD_VICTOR_NEFARIUS_MALORIAK))
                            if (nefarius->IsAIEnabled)
                                nefarius->AI()->DoAction(ACTION_THROW_BLACK_BOTTLE);

                        _usedVialsCount = _usedVialsCount < _vialsPerCycle ? _usedVialsCount + 1 : 0;
                        events.ScheduleEvent(EVENT_THROW_VIAL, 1s + 300ms, 0, PHASE_ONE);
                    }
                    break;
                case EVENT_THROW_VIAL:
                    if (_currentVial != VIAL_BLACK)
                    {
                        DoCastSelf(vialData[_currentVial].ThrowSpellId);
                        Talk(vialData[_currentVial].AnnounceTextId);
                    }
                    events.ScheduleEvent(EVENT_MOVE_TO_CAULDRON, 1s);
                    break;
                case EVENT_MOVE_TO_CAULDRON:
                    me->GetMotionMaster()->MovePoint(POINT_CAULDRON, CauldronMovePosition);
                    break;
                case EVENT_DRINK_BOTTLE:
                    DoCastSelf(vialData[_currentVial].DrinkSpellId);
                    events.ScheduleEvent(EVENT_IMBUED_BUFF, 2s + 500ms);

                    if (_currentVial == VIAL_GREEN)
                        events.ScheduleEvent(EVENT_EXPLODE_CAULDRON, 1s);
                    break;
                case EVENT_IMBUED_BUFF:
                    DoCastSelf(vialData[_currentVial].ImbuedSpellId);
                    DoAction(ACTION_SCHEDULE_EVENTS_FOR_PHASE);
                    break;
                case EVENT_EXPLODE_CAULDRON:
                    if (Creature* cauldron = instance->GetCreature(DATA_CAULDRON_TRIGGER))
                    {
                        cauldron->CastSpell(cauldron, SPELL_DEBILITATING_SLIME_CAST);
                        cauldron->CastSpell(cauldron, SPELL_DEBILITATING_SLIME_KNOCKBACK);
                    }
                    break;
                case EVENT_ATTACK_PLAYERS:
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                case EVENT_CONSUMING_FLAMES:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
                        DoCast(target, SPELL_CONSUMING_FLAMES);
                    events.Repeat(14s + 500ms);
                    break;
                case EVENT_SCORCHING_BLAST:
                    DoCastVictim(SPELL_SCORCHING_BLAST);
                    events.Repeat(17s);
                    break;
                case EVENT_BITING_CHILL:
                   if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
                        DoCast(target, SPELL_BITING_CHILL);
                    events.Repeat(11s);
                    break;
                case EVENT_FLASH_FREEZE:
                    DoCastAOE(SPELL_FLASH_FREEZE_TARGETING);
                    events.Repeat(19s);
                    break;
                case EVENT_ENTER_PHASE_TWO:
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    Talk(SAY_RELEASE_ALL_MINIONS);
                    DoCastSelf(SPELL_RELEASE_ALL_MINIONS);
                    events.ScheduleEvent(EVENT_DRINK_ALL_BOTTLES, 5s, 0, PHASE_TWO);
                    break;
                case EVENT_DRINK_ALL_BOTTLES:
                    for (uint8 i = 0; i < VIAL_BLACK; i++)
                        me->RemoveAurasDueToSpell(vialData[i].ImbuedSpellId);

                    DoCastSelf(SPELL_DRINK_ALL_BOTTLES);
                    events.ScheduleEvent(EVENT_UNSTABLE_MIX, 2s + 300ms, 0, PHASE_TWO);
                    break;
                case EVENT_UNSTABLE_MIX:
                    DoCastSelf(SPELL_UNSTABLE_MIX);
                    me->ClearUnitState(UNIT_STATE_ROOT);
                    me->SetReactState(REACT_AGGRESSIVE);
                    events.ScheduleEvent(EVENT_MAGMA_JETS, 3s + 500ms, 0, PHASE_TWO);
                    events.ScheduleEvent(EVENT_ACID_NOVA, 8s + 400ms, 0, PHASE_TWO);
                    events.ScheduleEvent(EVENT_ABSOLUTE_ZERO, 8s + 400ms, 0, PHASE_TWO);
                    break;
                case EVENT_MAGMA_JETS:
                    DoCastAOE(SPELL_MAGMA_JETS_SCRIPT_EFFECT);
                    events.Repeat(6s);
                    break;
                case EVENT_ACID_NOVA:
                    DoCastAOE(SPELL_ACID_NOVA);
                    events.Repeat(20s);
                    break;
                case EVENT_ABSOLUTE_ZERO:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
                        DoCast(target, SPELL_ABSOLUTE_ZERO);
                    events.Repeat(7s);
                    break;
                case EVENT_ENGULFING_DARKNESS:
                    if (me->GetReactState() == REACT_PASSIVE)
                    {
                        me->AddUnitState(UNIT_STATE_ROOT);
                        me->SetReactState(REACT_AGGRESSIVE);
                    }
                    DoCastSelf(SPELL_ENGULFING_DARKNESS);
                    events.Repeat(12s + 500ms);
                    break;
                case EVENT_VILE_SWILL:
                    DoCastSelf(SPELL_VILE_SWILL);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
private:
    uint8 _currentVial;
    uint8 _usedVialsCount;
    uint8 _vialsPerCycle;
    uint8 _releasedAberrationsCount;

    void CleanupEncounter()
    {
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_FLASH_FREEZE_STUN);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BITING_CHILL);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_CONSUMING_FLAMES);
        instance->instance->SpawnGroupDespawn(SPAWN_GROUP_GROWTH_CHAMBERS);
        summons.DespawnAll();
    }
};

struct npc_maloriak_flash_freeze : public NullCreatureAI
{
    npc_maloriak_flash_freeze(Creature* creature) : NullCreatureAI(creature) { }

    void JustAppeared() override
    {
        me->ApplySpellImmune(0, IMMUNITY_ID, sSpellMgr->GetSpellIdForDifficulty(SPELL_GROWTH_CATALYST, me), true);
        DoCastSelf(SPELL_FLASH_FREEZE_VISUAL);
        Creature* creature = me;
        me->m_Events.AddEventAtOffset([creature]() { creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE); }, 1s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (TempSummon* summon = me->ToTempSummon())
            if (Unit* owner = summon->GetSummoner())
                owner->CastSpell(owner, SPELL_FLASH_FREEZE_DUMMY, true);

        DoCastAOE(SPELL_SHATTER, true);
        me->DespawnOrUnsummon(4s);
    }
};

struct npc_maloriak_experiment : public ScriptedAI
{
    npc_maloriak_experiment(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        me->SetReactState(REACT_PASSIVE);
        me->AddUnitMovementFlag(MOVEMENTFLAG_DISABLE_GRAVITY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->DespawnOrUnsummon(5s);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_RELEASE_EXPERIMENT:
            {
                me->RemoveAurasDueToSpell(SPELL_DROWNED_STATE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                // The chambers have super weird spawn points so FindNearestGameObject wont work here.
                std::list<GameObject*> gameObjectList;
                uint32 entry = me->GetEntry() == NPC_ABERRATION ? GO_GROWTH_CHAMBER : GO_LARGE_GROWTH_CHAMBER;
                me->GetGameObjectListWithEntryInGrid(gameObjectList, entry, 2.0f);
                float z = me->GetPositionZ();

                if (me->GetEntry() == NPC_ABERRATION)
                {
                    gameObjectList.remove_if([z](GameObject const* go)
                    {
                        if (go->GetPositionZ() > z)
                            return true;

                        if (std::abs(go->GetPositionZ() - z) > 7.0f)
                            return true;

                        return false;
                    });
                }

                if (gameObjectList.empty())
                    break;

                for (GameObject* chamber : gameObjectList)
                {
                    chamber->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                    chamber->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                }

                _events.ScheduleEvent(EVENT_LEAP_OUT_OF_CHAMBER, 1s + 700ms);
                break;
            }
            default:
                break;
        }
    }

    void MovementInform(uint32 motionType, uint32 pointId) override
    {
        if (motionType != EFFECT_MOTION_TYPE)
            return;

        switch (pointId)
        {
            case POINT_GROUND:
                me->SetDisableGravity(false);
                me->SendSetPlayHoverAnim(false);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                me->SetReactState(REACT_AGGRESSIVE);
                DoZoneInCombat();
                DoCastSelf(SPELL_GROWTH_CATALYST);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        // No return here. Maloriak handles the despawn.
        UpdateVictim();

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_LEAP_OUT_OF_CHAMBER:
                {
                    Position pos = me->GetPosition();
                    pos.m_positionX += cos(me->GetOrientation()) * 11.64f;
                    pos.m_positionY += sin(me->GetOrientation()) * 11.64f;
                    pos.m_positionZ = me->GetMapHeight(pos.GetPositionX(), pos.GetPositionY(), me->GetPositionZ());
                    me->GetMotionMaster()->MoveJump(pos, 21.0f, 15.0f, POINT_GROUND);
                    break;
                }
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
private:
    EventMap _events;
};

struct npc_maloriak_magma_jet : public NullCreatureAI
{
    npc_maloriak_magma_jet(Creature* creature) : NullCreatureAI(creature) { }

    void JustSummoned(Creature* summon) override
    {
        summon->CastSpell(summon, SPELL_MAGMA_JETS_ERUPTION);
        summon->DespawnOrUnsummon(30s);
    }
};

struct npc_maloriak_lord_victor_nefarius : public NullCreatureAI
{
    npc_maloriak_lord_victor_nefarius(Creature* creature) : NullCreatureAI(creature) { }

    void JustAppeared() override
    {
        me->SetHover(true);
        DoCastSelf(SPELL_TELEPORT_VISUAL_ONLY);
        _events.ScheduleEvent(EVENT_MOCK_MALORIAK, 7s + 200ms);
    }

    void MovementInform(uint32 motionType, uint32 pointId) override
    {
        if (motionType != POINT_MOTION_TYPE && motionType != EFFECT_MOTION_TYPE)
            return;

        switch (pointId)
        {
            case POINT_LAND:
                me->SetDisableGravity(false);
                me->SetHover(false);
                _events.ScheduleEvent(EVENT_SAY_MALORIAK_DEAD, 2s);
                break;
            default:
                break;
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_THROW_BLACK_BOTTLE:
                Talk(SAY_THROW_BLACK_BOTTLE);
                _events.ScheduleEvent(EVENT_THROW_BLACK_BOTTLE, 2s + 400ms);
                break;
            case ACTION_MALORIAK_DEAD:
                me->SetAIAnimKitId(AI_ANIM_KIT_ID_LORD_VICTOR_NEFARIUS);
                _events.Reset();
                _events.ScheduleEvent(EVENT_LAND, 3s);
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
                case EVENT_MOCK_MALORIAK:
                    Talk(SAY_MOCK_MALORIAK);
                    break;
                case EVENT_THROW_BLACK_BOTTLE:
                    Talk(SAY_ANNOUNCE_BLACK_VIAL);
                    DoCastAOE(SPELL_THROW_BLACK_BOTTLE, true);
                    break;
                case EVENT_LAND:
                    me->GetMotionMaster()->MoveLand(POINT_LAND, LordVictorNefariusLandPosition);
                    break;
                case EVENT_SAY_MALORIAK_DEAD:
                    Talk(SAY_MALORIAK_DEAD);
                    _events.ScheduleEvent(EVENT_MASTER_ADVENTURER_AWARD, 7s);
                    break;
                case EVENT_MASTER_ADVENTURER_AWARD:
                    DoCastAOE(SPELL_MASTER_ADVENTURER_AWARD);
                    _events.ScheduleEvent(EVENT_TELEPORT_AWAY, 2s + 500ms);
                    break;
                case EVENT_TELEPORT_AWAY:
                    DoCastSelf(SPELL_TELEPORT_VISUAL_ONLY);
                    me->DespawnOrUnsummon(1s + 200ms);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

struct npc_maloriak_vile_swill : public ScriptedAI
{
    npc_maloriak_vile_swill(Creature* creature) : ScriptedAI(creature) {  }

    void JustAppeared() override
    {
        DoZoneInCombat();
        me->ApplySpellImmune(0, IMMUNITY_ID, sSpellMgr->GetSpellIdForDifficulty(SPELL_GROWTH_CATALYST, me), true);
        _events.ScheduleEvent(EVENT_DARK_SLUDGE, 6s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->DespawnOrUnsummon(5s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_DARK_SLUDGE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
                        DoCast(target, SPELL_DARK_SLUDGE);
                    _events.Repeat(6s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
private:
    EventMap _events;
};

class spell_maloriak_throw_bottle : public SpellScript
{
    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints, true);
    }

    void Register() override
    {
        OnEffectLaunchTarget.Register(&spell_maloriak_throw_bottle::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_maloriak_throw_bottle_triggered : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_THROW_RED_BOTTLE_TRIGGERED,
                SPELL_THROW_BLUE_BOTTLE_TRIGGERED,
                SPELL_THROW_GREEN_BOTTLE_TRIGGERED,
                SPELL_THROW_BLACK_BOTTLE_TRIGGERED
            });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        InstanceScript* instance = GetHitUnit()->GetInstanceScript();
        if (!instance)
            return;

        if (GameObject* cauldron = instance->GetGameObject(DATA_CAULDRON))
        {
            switch (GetSpellInfo()->Id)
            {
                case SPELL_THROW_RED_BOTTLE_TRIGGERED:
                    cauldron->SendCustomAnim(CUSTOM_ANIM_RED_CAULDRON);
                    break;
                case SPELL_THROW_BLUE_BOTTLE_TRIGGERED:
                    cauldron->SendCustomAnim(CUSTOM_ANIM_BLUE_CAULDRON);
                    break;
                case SPELL_THROW_GREEN_BOTTLE_TRIGGERED:
                    cauldron->SendCustomAnim(CUSTOM_ANIM_GREEN_CAULDRON);
                    break;
                case SPELL_THROW_BLACK_BOTTLE_TRIGGERED:
                    cauldron->SendCustomAnim(CUSTOM_ANIM_BLACK_CAULDRON);
                    break;
                default:
                    break;
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_maloriak_throw_bottle_triggered::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_maloriak_consuming_flames: public AuraScript
{
    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (!eventInfo.GetSpellInfo() || eventInfo.GetSpellInfo()->DmgClass != SPELL_DAMAGE_CLASS_MAGIC || eventInfo.GetSpellInfo()->Id == GetId())
            return false;

        return eventInfo.GetDamageInfo();
    }

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        AuraEffect* effect = GetEffect(EFFECT_0);
        effect->SetAmount(effect->GetAmount() + CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), 50));
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_maloriak_consuming_flames::HandleProc, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

class spell_maloriak_flash_freeze_targeting : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FLASH_FREEZE_SUMMON });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.size() <= 1)
            return;

        targets.remove_if(Trinity::Predicates::IsVictimOf(GetCaster()));

        if (targets.empty())
            return;

        targets.remove_if([](WorldObject* obj)
        {
            Unit const* target = obj->ToUnit();
            if (!target)
                return true;

            for (Unit* attacker : target->getAttackers())
                if (attacker->GetEntry() == NPC_ABERRATION && attacker->GetVictim() == target)
                    return true;

            return false;
        });

        if (!targets.empty())
            Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
        {
            caster->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints, true);
            GetHitUnit()->CastSpell(GetHitUnit(), SPELL_FLASH_FREEZE_SUMMON, true);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_maloriak_flash_freeze_targeting::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget.Register(&spell_maloriak_flash_freeze_targeting::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_maloriak_flash_freeze_dummy : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FLASH_FREEZE_STUN_NORMAL });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Unit* caster = GetCaster();
        if (targets.empty())
        {
            caster->RemoveAurasDueToSpell(sSpellMgr->GetSpellIdForDifficulty(SPELL_FLASH_FREEZE_STUN_NORMAL, caster));
            return;
        }

        targets.remove_if([caster](WorldObject* obj)
        {
            Unit* target = obj->ToUnit();
            if (!target)
                return true;

            return target->isDead() || !target->ToTempSummon() || target->ToTempSummon()->GetSummoner() != caster;
        });

       if (targets.empty())
           caster->RemoveAurasDueToSpell(sSpellMgr->GetSpellIdForDifficulty(SPELL_FLASH_FREEZE_STUN_NORMAL, caster));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_maloriak_flash_freeze_dummy::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

class spell_maloriak_release_experiments : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_RELEASE_ABERRATIONS,
                SPELL_RELEASE_ALL_MINIONS
            });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(Trinity::UnitAuraCheck(false, SPELL_DROWNED_STATE));

        if (!targets.empty() && GetSpellInfo()->Id == SPELL_RELEASE_ABERRATIONS)
            Trinity::Containers::RandomResize(targets, 3);
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        if (Creature* target = GetHitCreature())
            if (target->IsAIEnabled)
                target->AI()->DoAction(ACTION_RELEASE_EXPERIMENT);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_maloriak_release_experiments::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget.Register(&spell_maloriak_release_experiments::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
        if (m_scriptSpellId == SPELL_RELEASE_ALL_MINIONS)
        {
            OnObjectAreaTargetSelect.Register(&spell_maloriak_release_experiments::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
            OnEffectHitTarget.Register(&spell_maloriak_release_experiments::HandleDummyEffect, EFFECT_1, SPELL_EFFECT_DUMMY);
        }
    }
};

class spell_maloriak_magma_jets_script : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGMA_JETS_SUMMON });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        Unit* target = GetHitUnit();

        if (target == caster->GetVictim())
        {
            caster->SetOrientation(caster->GetAngle(target));
            caster->SetFacingToObject(target); // update orientation immediately
            caster->CastSpell(target, SPELL_MAGMA_JETS_SUMMON);
        }
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_maloriak_magma_jets_script::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_maloriak_magma_jets_periodic : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGMA_JETS_SUMMON_FIRE });
    }

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        PreventDefaultAction();
        Unit* target = GetTarget();

        uint8 ticks = aurEff->GetTickNumber();
        float dist = 3.0f * ticks;
        float x = target->GetPositionX() + cos(target->GetOrientation()) * dist;
        float y = target->GetPositionY() + sin(target->GetOrientation()) * dist;
        float z = target->GetMapHeight(x, y, target->GetPositionZ() + 5.0f);
        if (target->IsWithinLOS(x, y, z))
            target->CastSpell({ x, y, z }, SPELL_MAGMA_JETS_SUMMON_FIRE, true);
        else
            Remove();
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_maloriak_magma_jets_periodic::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_maloriak_absolute_zero : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ABSOLUTE_ZERO_EXPLOSION });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Unit* caster = GetCaster();
        caster->RemoveAllAuras();
        caster->CastSpell(caster, SPELL_ABSOLUTE_ZERO_EXPLOSION);
        if (Creature * creature = caster->ToCreature())
            creature->DespawnOrUnsummon(3s);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_maloriak_absolute_zero::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_maloriak_vile_swill: public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_VILE_SWILL_SUMMON });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        Unit* target = GetTarget();
        Position const destination = target->GetRandomPoint(target->GetPosition(), 11.0f);
        target->CastSpell({ destination.GetPositionX(), destination.GetPositionY(), destination.GetPositionZ() }, SPELL_VILE_SWILL_SUMMON, true);
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_maloriak_vile_swill::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_maloriak_vile_swill_summon: public AuraScript
{
    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        int32 summonSpellId = GetSpellInfo()->Effects[EFFECT_0].TriggerSpell;
        Creature* target = GetTarget()->ToCreature();
        if (!target)
            return;

        target->m_Events.AddEventAtOffset([target, summonSpellId]()
        {
            target->CastSpell(target, summonSpellId, true);
            target->SetObjectScale(0.1f);
            target->m_Events.AddEventAtOffset([target]()
            {
                target->RemoveAllAuras();
                target->DespawnOrUnsummon(4s + 300ms);
            }, 1s + 200ms);
        }, 2s);
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_maloriak_vile_swill_summon::AfterApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_maloriak_master_adventurer_award : public AuraScript
{
    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Player* player = GetTarget()->ToPlayer();
        if (!player)
            return;

        CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(TITLE_ADVENTURER_AWARD);
        if (!titleInfo)
            return;

        player->SetTitle(titleInfo);
        player->SetUInt32Value(PLAYER_CHOSEN_TITLE, titleInfo->Mask_ID);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Player* player = GetTarget()->ToPlayer();
        if (!player)
            return;

        CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(TITLE_ADVENTURER_AWARD);
        if (!titleInfo)
            return;

        player->SetTitle(titleInfo, true);

        if (!player->HasTitle(player->GetInt32Value(PLAYER_CHOSEN_TITLE)))
            player->SetUInt32Value(PLAYER_CHOSEN_TITLE, 0);
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_maloriak_master_adventurer_award::HandleApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove.Register(&spell_maloriak_master_adventurer_award::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_maloriak()
{
    RegisterBlackwingDescentCreatureAI(boss_maloriak);
    RegisterBlackwingDescentCreatureAI(npc_maloriak_flash_freeze);
    RegisterBlackwingDescentCreatureAI(npc_maloriak_experiment);
    RegisterBlackwingDescentCreatureAI(npc_maloriak_magma_jet);
    RegisterBlackwingDescentCreatureAI(npc_maloriak_lord_victor_nefarius);
    RegisterBlackwingDescentCreatureAI(npc_maloriak_vile_swill);
    RegisterSpellScript(spell_maloriak_throw_bottle);
    RegisterSpellScript(spell_maloriak_throw_bottle_triggered);
    RegisterSpellScript(spell_maloriak_consuming_flames);
    RegisterSpellScript(spell_maloriak_flash_freeze_targeting);
    RegisterSpellScript(spell_maloriak_flash_freeze_dummy);
    RegisterSpellScript(spell_maloriak_release_experiments);
    RegisterSpellScript(spell_maloriak_magma_jets_script);
    RegisterSpellScript(spell_maloriak_magma_jets_periodic);
    RegisterSpellScript(spell_maloriak_absolute_zero);
    RegisterSpellScript(spell_maloriak_vile_swill);
    RegisterSpellScript(spell_maloriak_vile_swill_summon);
    RegisterSpellScript(spell_maloriak_master_adventurer_award);
}
