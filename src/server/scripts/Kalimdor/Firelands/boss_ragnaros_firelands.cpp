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

#include "firelands.h"
#include "DynamicObject.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MoveSpline.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

#include "boost/container/flat_set.hpp"

enum Spells
{
    // Ragnaros
    SPELL_BASE_VISUAL                           = 98860,
    SPELL_BURNING_WOUND                         = 99401,
    SPELL_WRATH_OF_RAGNAROS_AOE                 = 98259,
    SPELL_HAND_OF_RAGNAROS                      = 98237,
    SPELL_MAGMA_TRAP_AOE                        = 98159,
    SPELL_MAGMA_BLAST                           = 98313,
    SPELL_SULFURAS_SMASH_AOE                    = 98703,
    SPELL_SULFURAS_SMASH_SUMMON                 = 98706,
    SPELL_SULFURAS_SMASH                        = 98710,
    SPELL_SPLITTING_BLOW                        = 98951,
    SPELL_SUBMERGE                              = 100051,
    SPELL_MOLTEN_SEED                           = 98333,
    SPELL_ENGULFING_FLAMES                      = 99171,
    SPELL_ENGULFING_FLAMES_FAR                  = 99236,
    SPELL_ENGULFING_FLAMES_FAR_VISUAL           = 99218,
    SPELL_ENGULFING_FLAMES_MIDDLE               = 99235,
    SPELL_ENGULFING_FLAMES_MIDDLE_VISUAL        = 99217,
    SPELL_ENGULFING_FLAMES_NEAR                 = 99172,
    SPELL_ENGULFING_FLAMES_NEAR_VISUAL          = 99216,
    SPELL_LIVING_METEOR                         = 99267,
    SPELL_ACHIEVEMENT_CHECK                     = 101091,
    SPELL_AWARD_REPUTATION_BOSS_KILL            = 101620,
    SPELL_HEART_OF_RAGNAROS                     = 101253, // @todo: handle
    SPELL_RAGNAROS_KILL_CREDIT                  = 102237, // Serverside Spell
    SPELL_SUMMON_CHEST                          = 101095,
    SPELL_DEATH                                 = 99430,
    SPELL_BURNING_BLAST                         = 99400,
    SPELL_LEGS_SUBMERGE                         = 100312,
    SPELL_LEGS_HEAL                             = 100346,
    SPELL_TRANSFORM                             = 100420,
    SPELL_SUPERHEATED                           = 100593,
    SPELL_DREADFLAME_SUMMON_CONTROLLER          = 100679,
    SPELL_DREADFLAME_PERIODIC                   = 100691,
    SPELL_DREADFLAME_MISSILE                    = 100675,
    SPELL_BREADTH_OF_FROST_TRIGGER              = 100472,
    SPELL_ENTRAPPING_ROOTS                      = 100645,
    SPELL_EMPOWER_SULFURAS                      = 100604,

    // Magma Trap
    SPELL_MAGMA_TRAP_VISUAL                     = 98179,
    SPELL_MAGMA_TRAP_PERIODIC_AURA              = 98172,
    SPELL_MAGMA_TRAP_VULNERABILITY              = 100238,
    SPELL_MAGMA_TRAP_ERUPTION                   = 100107,

    // Sulfuras Smash
    SPELL_LAVA_WAVE_N                           = 98874,
    SPELL_LAVA_WAVE_W                           = 98876,
    SPELL_LAVA_WAVE_E                           = 98875,
    SPELL_LAVA_POOL                             = 98712,
    SPELL_SCORCHED_GROUND                       = 100119,

    // Lava Wave
    SPELL_LAVA_WAVE                             = 98873,

    // Son of Flame
    SPELL_HIT_ME                                = 100446,
    SPELL_BURNING_SPEED                         = 98473,
    SPELL_BURNING_SPEED_AURA                    = 99414,
    SPELL_SUPERNOVA                             = 99112,
    SPELL_QUITE_SUICIDE                         = 3617, // Serverside spell

    // Splitting Blow
    SPELL_INVOKE_SONS                           = 99050,

    // Sulfuras, Hand of Ragnaros
    SPELL_SULFURAS                              = 100456,

    // Molten Elemental
    SPELL_INVIS_PRE_VISUAL_2                    = 100153,
    SPELL_MOLTEN_SEED_AOE                       = 98497,
    SPELL_MOLTEN_SEED_VISUAL                    = 98520,
    SPELL_MOLTEN_POWER                          = 100158,
    SPELL_MOLTEN_INFERNO                        = 100253,
    SPELL_AGGRO_DEMON_CREATOR                   = 100142,
    SPELL_REDUCE_CRITICAL_STRIKE_CHANCE_100_PCT = 64481,

    // Lava Scion
    SPELL_BLAZING_HEAT                          = 100459,
    SPELL_BLAZING_HEAT_SUMMON                   = 99129,

    // Blazing Heat
    SPELL_BLAZING_HEAT_AURA                     = 99128,

    // Living Meteor
    SPELL_LIVING_METEOR_DAMAGE_REDUCTION        = 100904,
    SPELL_COMBUSTIBLE                           = 99296,
    SPELL_LIVING_METEOR_TARGET_SEARCHER         = 99269,
    SPELL_LIVING_METEOR_SPEED_STACKER           = 100278,
    SPELL_LIVING_METEOR_SPEED_AURA              = 100277,
    SPELL_FIXATE                                = 99849,
    SPELL_COMBUSTION                            = 99303,
    SPELL_METEOR_IMPACT                         = 99287,
    SPELL_TRIGGERED_LIVING_METEOR               = 100910,

    // Archdruid Hamuul Runetotem
    SPELL_TRANSFORM_HAMUUL                      = 100311,
    SPELL_DRAW_OUT_FIRELORD_HAMUUL              = 100344,
    SPELL_ENTRAPPING_ROOTS_CAST                 = 100646,

    // Malfurion Stormrage
    SPELL_TRANSFORM_MALFURION                   = 100310,
    SPELL_DRAW_OUT_FIRELORD_MALFURION           = 100342,
    SPELL_CLOUDBURST                            = 100751,

    // Cenarius
    SPELL_DRAW_OUT_FIRELORD_CENARIUS            = 100345,
    SPELL_BREADTH_OF_FROST_CAST                 = 100479,
    SPELL_BREADTH_OF_FROST_AURA                 = 100503,

    // Dreadflame
    SPELL_DREADFLAME_CONTROL_AURA_1             = 100695,
    SPELL_DREADFLAME_CONTROL_AURA_2             = 100696,
    SPELL_DREADFLAME_CONTROL_AURA_3             = 100965,
    SPELL_DREADFLAME_CONTROL_AURA_4             = 100905,
    SPELL_DREADFLAME_AREA_DUMMY_AURA            = 100692,
    SPELL_DREADFLAME_DAMAGE                     = 100941,
    SPELL_DELUGE_TRIGGERED                      = 100757,

    // Cloudburst
    SPELL_CLOUDBURST_VISUAL                     = 100758,
    SPELL_DELUGE                                = 100713,

    // Magma
    SPELL_KNOCKBACK_PERIODIC                    = 99908
};

#define SPELL_SUBMERGE_AURA         RAID_MODE<uint32>(98982, 100295, 100296, 100297)
#define SPELL_WORLD_IN_FLAMES       RAID_MODE<uint32>(100171, 100190)
#define SPELL_INVIS_PRE_VISUAL_1    RAID_MODE<uint32>(98983, 100133, 100134, 100135)

enum Texts
{
    // Ragnaros
    SAY_EMERGE                          = 0,
    SAY_AGGRO                           = 1,
    SAY_WRATH_OF_RAGNAROS               = 2,
    SAY_ANNOUNCE_MAGMA_TRAP             = 3,
    SAY_ANNOUNCE_SULFURAS_SMASH         = 4,
    SAY_ANNOUNCE_SPLITTING_BLOW         = 5,
    SAY_SPLITTING_BLOW                  = 6,
    SAY_INVOKE_SONS_OF_FLAME            = 7,
    SAY_PICK_UP_SULFURAS                = 8,
    SAY_ANNOUNCE_WORLD_IN_FLAMES        = 9,
    SAY_ANNOUNCE_ENGULFING_FLAMES       = 10,
    SAY_ANNOUNCE_EMERGE                 = 11,
    SAY_DEFEATED                        = 12, // Normal difficulty only
    SAY_SUBMERGE_HEROIC                 = 13,
    SAY_EMERGE_HEROIC                   = 14,
    SAY_BREAK_FREE                      = 15,
    SAY_ANNOUNCE_EMPOWER_SULFURAS       = 16,
    SAY_ANNOUNCE_DREADFLAME             = 17,
    SAY_SLAY                            = 18,
    SAY_DEATH                           = 19,

    // Lava Scion
    SAY_ANNOUNCE_BLAZING_HEAT           = 0,

    // Cenarius
    SAY_PREPARE_TO_DRAW_RAGNAROS_OUT    = 0,

    // Malfurion Stormrage
    SAY_RAGNAROS_BOUND                  = 0,

    // Archdruids
    SAY_OUTRO_1                         = 1,
    SAY_OUTRO_2                         = 2,
    SAY_OUTRO_3                         = 3
};

enum Events
{
    // Ragnaros
    EVENT_EMERGE = 1,
    EVENT_BASE_VISUAL,
    EVENT_FINISH_ARRIVAL,
    EVENT_WRATH_OF_RAGNAROS,
    EVENT_HAND_OF_RAGNAROS,
    EVENT_MAGMA_TRAP,
    EVENT_SULFURAS_SMASH,
    EVENT_SET_AGGRESSIVE_REACT_STATE,
    EVENT_SPLITTING_BLOW,
    EVENT_MOLTEN_SEED,
    EVENT_ENGULFING_FLAMES,
    EVENT_ANNOUNCE_END_OF_INTERMISSION,
    EVENT_FINISH_INTERMISSION,
    EVENT_LIVING_METEOR,
    EVENT_LEGS_HEAL,
    EVENT_FACE_HOME,
    EVENT_EMERGE_HEROIC,
    EVENT_TALK_EMERGE_HEROIC,
    EVENT_BREAK_FREE,
    EVENT_SUPERHEATED,
    EVENT_ENTRAPPING_ROOTS,
    EVENT_EMPOWER_SULFURAS,
    EVENT_DREADFLAME,
    EVENT_BREADTH_OF_FROST,

    // Son of Flame
    EVENT_MOVE_TOWARDS_SULFURAS,

    // Lava Scion
    EVENT_BLAZING_HEAT,

    // Living Meteor
    EVENT_FIXATE,
    EVENT_COMBUSTIBLE,
    EVENT_RESUME_CHASE_MOVEMENT,

    // Archdruids
    EVENT_DRAW_OUT_FIRELORD,
    EVENT_OUTRO_1,
    EVENT_OUTRO_2,
    EVENT_OUTRO_3,

    // Cenarius
    EVENT_TALK_PREPARE_TO_DRAW_RAGNAROS_OUT,

    // Malfurion Stormrage
    EVENT_SAY_RAGNAROS_BOUND,
    EVENT_CLOUDBURST,
};

enum Actions
{
    // Ragnaros
    ACTION_INVOKE_SONS_OF_FLAME_TRIGGERED   = 0,
    ACTION_SON_OF_FLAME_DIED                = 1,
    ACTION_ARCHDRUIDS_ARRIVED               = 2,

    // Son of Flame
    ACTION_INVOKE_SON                       = 0,

    // Lava Scion
    ACTION_DISENGAGE                        = 0,

    // Living Meteor
    ACTION_COMBUSTION_TRIGGERED             = 0,
    ACTION_IMPACT_TRIGGERED                 = 1,

    // Dreadflame
    ACTION_SPREAD_DREADFLAMES               = 0,

    // Archdruids
    ACTION_RAGNAROS_KILLED                  = 0,
};

enum Phases
{
    PHASE_INTRO             = 1,
    PHASE_ONE               = 2,
    PHASE_INTERMISSION_1    = 3,
    PHASE_TWO               = 4,
    PHASE_INTERMISSION_2    = 5,
    PHASE_THREE             = 6,
    PHASE_FOUR              = 7
};

enum AnimKits
{
    // Ragnaros
    ANIM_KIT_ID_EMERGE              = 1467,
    ANIM_KIT_ID_TALK                = 1468,
    ANIM_KIT_ID_PICK_UP_SULFURAS    = 1465,
    ANIM_KIT_ID_EMERGE_HEROIC       = 1522,
    ANIM_KIT_ID_BREAK_FREE          = 1486,

    // Son of Flame
    ANIM_KIT_ID_INVOKE              = 1370,

    // Malfurion Stormrage
    ANIM_KIT_ID_YELL                = 1523
};

enum Data
{
    // Ragnaros
    DATA_CURRENT_SPLITTING_BLOW_TARGET          = 0,
    DATA_CAST_DREADFLAMES                       = 0,

    // Dreadflame
    DATA_DREADFLAME_POSTION_INFO_INDEX          = 0,
    DATA_OCCUPY_DREADFLAME_POSITION_INFO_INDEX  = 0,
    DATA_RELEASE_DREADFLAME_POSITION_INFO_INDEX = 1
};

enum MovePoints
{
    // Son of Flame
    POINT_ID_TRIGGER_SUPERNOVA = 1,

    // Archdruids
    POINT_ID_ENTER_PLATFORM     = 0,
    POINT_ID_LAND               = 1
};

enum SummonGroups
{
    // Ragnaros
    SUMMON_GROUP_ID_LAVA_SCIONS = 0,
    SUMMON_GROUP_ID_ARCHDRUIDS  = 1
};

enum VirtualItemSlotIds
{
    ITEM_SLOT_ID_EMPOWERED_SULFURAS = 71036,
    ITEM_SLOT_ID_DEFAULT_SULFURAS   = 69804
};

enum Misc
{
    INVALID_DREADFLAME_POSITION_INFO_INDEX = 1000
};

static std::vector<Position> SonOfFlameSpawnPositions =
{
    { 1014.3245849609375f,  -88.8020858764648437f, 55.5272216796875f,     1.919862151145935058f },
    { 1055.3316650390625f,  -105.013893127441406f, 55.43525314331054687f, 2.408554315567016601f },
    { 1035.048583984375f,   -98.7586822509765625f, 55.58205032348632812f, 2.234021425247192382f },
    { 1074.8663330078125f,  -100.788192749023437f, 55.42414093017578125f, 2.600540637969970703f },
    { 1013.45831298828125f, -68.0850677490234375f, 55.42096710205078125f, 2.513274192810058593f },
    { 1074.8524169921875f,  -12.3159723281860351f, 55.4241180419921875f,  3.700098037719726562f },
    { 1061.34033203125f,    -16.7413196563720703f, 55.56818771362304687f, 3.769911050796508789f },
    { 1051.49658203125f,    -113.729156494140625f, 55.44934844970703125f, 2.39110112190246582f  },
    { 1051.7603759765625f,  0.128472223877906799f, 55.44715118408203125f, 4.031710624694824218f },
    { 998.89410400390625f,  -69.0763931274414062f, 55.557647705078125f,   1.256637096405029296f },
    { 1065.2569580078125f,  -6.94618082046508789f, 55.56818389892578125f, 3.839724302291870117f },
    { 1030.37158203125f,    -23.6371536254882812f, 55.44153594970703125f, 4.049163818359375f    },
    { 1068.1510009765625f,  -101.392356872558593f, 55.56827926635742187f, 2.565634012222290039f },
    { 1055.5555419921875f,  -8.875f,               55.43347930908203125f, 3.874630928039550781f },
    { 1067.6927490234375f,  -13.4114580154418945f, 55.53647994995117187f, 3.700098037719726562f },
    { 1060.94970703125f,    -98.1336822509765625f, 55.56827545166015625f, 2.513274192810058593f },
    { 1029.8038330078125f,  -90.6909713745117187f, 55.57508087158203125f, 2.234021425247192382f }
};

struct EngulfingFlamesSpellIds
{
    EngulfingFlamesSpellIds(uint32 visualSpellId, uint32 castSpellId) : VisualSpellID(visualSpellId), CastSpellID(castSpellId) { }

    uint32 VisualSpellID;
    uint32 CastSpellID;
};

static std::array<EngulfingFlamesSpellIds, 3> EngulfingFlamesData =
{
    EngulfingFlamesSpellIds(SPELL_ENGULFING_FLAMES_NEAR_VISUAL, SPELL_ENGULFING_FLAMES_NEAR),
    EngulfingFlamesSpellIds(SPELL_ENGULFING_FLAMES_MIDDLE_VISUAL, SPELL_ENGULFING_FLAMES_MIDDLE),
    EngulfingFlamesSpellIds(SPELL_ENGULFING_FLAMES_FAR_VISUAL, SPELL_ENGULFING_FLAMES_FAR)
};

struct boss_ragnaros_firelands : public BossAI
{
    boss_ragnaros_firelands(Creature* creature) : BossAI(creature, DATA_RAGNAROS),
        _defeatedSonsOfFlame(0), _defeated(IsHeroic()), _canBeKilled(false)
    {
        me->setActive(true); // ensure that the AI is being updated while Ragnaros is doing his arrival events
    }

    void InitializeAI() override
    {
        BossAI::InitializeAI();
        me->SetDisableGravity(true);
        me->SetControlled(true, UNIT_STATE_ROOT);
    }

    void JustAppeared() override
    {
        instance->SetBossState(DATA_RAGNAROS, NOT_STARTED);
        instance->instance->SpawnGroupSpawn(SPAWN_GROUP_ID_RAGNAROS_STALKERS, true);
        events.SetPhase(PHASE_INTRO);
        events.ScheduleEvent(EVENT_EMERGE, 200ms); // Oneshot Anim Kits only work properly when Ragnaros has been sent out via UpdateObject, so we have to delay the packet a bit.
        events.ScheduleEvent(EVENT_BASE_VISUAL, 2s);
        events.ScheduleEvent(EVENT_FINISH_ARRIVAL, 7s);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        Talk(SAY_AGGRO, who);
        DoCastSelf(SPELL_BURNING_WOUND);
        events.SetPhase(PHASE_ONE);
        events.ScheduleEvent(EVENT_WRATH_OF_RAGNAROS, 6s, 0, PHASE_ONE);
        events.ScheduleEvent(EVENT_HAND_OF_RAGNAROS, 26s, 0, PHASE_ONE);
        events.ScheduleEvent(EVENT_MAGMA_TRAP, 16s, 0, PHASE_ONE);
        events.ScheduleEvent(EVENT_SULFURAS_SMASH, 31s, 0, PHASE_ONE);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        EndEncounter(false);
    }

    void JustDied(Unit* /*killer*/) override
    {
        EndEncounter(true);
    }

    void KilledUnit(Unit* who) override
    {
        Talk(SAY_SLAY, who);
    }

    void JustSummoned(Creature* summon) override
    {
        summons.RemoveNotExisting(); // Might be a bit excessive but probably better than risking giant loops on resets or completions

        switch (summon->GetEntry())
        {
            case NPC_ARCHDRUID_HAMUUL_RUNETOTEM:
            case NPC_MALFURION_STORMRAGE:
            case NPC_CENARIUS:
                _archdruidGUIDs.push_back(summon->GetGUID());
                break;
            default:
                summons.Summon(summon);
                break;
        }

        switch (summon->GetEntry())
        {
            case NPC_MAGMA_TRAP:
                summon->CastSpell(nullptr, SPELL_MAGMA_TRAP_VISUAL);
                summon->m_Events.AddEventAtOffset([summon]() { summon->CastSpell(nullptr, SPELL_MAGMA_TRAP_PERIODIC_AURA); }, 1s);
                break;
            case NPC_SULFURAS_SMASH_1:
                Talk(SAY_ANNOUNCE_SULFURAS_SMASH, summon);
                me->AttackStop();
                me->SetReactState(REACT_PASSIVE);
                me->SetFacingToObject(summon);
                me->SetOrientationTowards(summon); // we need an immediately updated orientation for the next cast
                DoCastSelf(SPELL_SULFURAS_SMASH_SUMMON);

                // Sulfuras Smash delays the execution of Wrath of Ragnaros by 5,5s
                if (events.IsInPhase(PHASE_ONE))
                    events.RescheduleEvent(EVENT_WRATH_OF_RAGNAROS, Milliseconds(events.GetTimeUntilEvent(EVENT_WRATH_OF_RAGNAROS)) + 5s + 500ms, 0, PHASE_ONE);
                break;
            case NPC_SULFURAS_SMASH_2:
                if (summon->IsSummon())
                {
                    // For some reason, the npc dies instead of despawning right away according to sniffs. Let's do this as well.
                    summon->ToTempSummon()->SetTempSummonType(TEMPSUMMON_MANUAL_DESPAWN);
                    summon->m_Events.AddEventAtOffset([summon]() { summon->KillSelf(); }, 10s);
                    summon->SetCorpseDelay(15);
                }
                DoCastSelf(SPELL_SULFURAS_SMASH);
                events.ScheduleEvent(EVENT_SET_AGGRESSIVE_REACT_STATE, 5s + 500ms);
                for (uint32 spellId : { SPELL_LAVA_WAVE_N, SPELL_LAVA_WAVE_W, SPELL_LAVA_WAVE_E, SPELL_LAVA_POOL })
                    summon->CastSpell(nullptr, spellId);
                break;
            case NPC_LAVA_WAVE:
                if (summon->IsSummon())
                {
                    // For some reason, the npc dies instead of despawning right away according to sniffs. Let's do this as well.
                    summon->ToTempSummon()->SetTempSummonType(TEMPSUMMON_MANUAL_DESPAWN);
                    summon->m_Events.AddEventAtOffset([summon]() { summon->KillSelf(); }, 10s);
                    summon->SetCorpseDelay(2);
                }
                break;
            case NPC_SULFURAS_HAND_OF_RAGNAROS:
                summon->CastSpell(nullptr, SPELL_SULFURAS);
                break;
            case NPC_MOLTEN_ELEMENTAL:
                summon->SetCorpseDelay(2);
                summon->CastSpell(nullptr, SPELL_INVIS_PRE_VISUAL_2);
                summon->CastSpell(nullptr, SPELL_MOLTEN_SEED_AOE);
                break;
            case NPC_BLAZING_HEAT:
                summon->CastSpell(nullptr, SPELL_BLAZING_HEAT_AURA);
                break;
            case NPC_ARCHDRUID_HAMUUL_RUNETOTEM:
            case NPC_MALFURION_STORMRAGE:
            case NPC_CENARIUS:
                if (!me->GetMap()->IsGridLoaded(summon->GetPositionX(), summon->GetPositionY()))
                    me->GetMap()->LoadGrid(summon->GetPositionX(), summon->GetPositionY());
                summon->setActive(true);
                summon->GetMotionMaster()->MovePath(summon->GetEntry() * 100, false);
                break;
            case NPC_ENTRAPPING_ROOTS:
                if (Creature* hamuul = instance->GetCreature(DATA_ARCHDRUID_HAMUUL_RUNETOTEM))
                    hamuul->CastSpell(summon, SPELL_ENTRAPPING_ROOTS_CAST);
                break;
            case NPC_DREADFLAME:
                for (uint32 spellId : { SPELL_DREADFLAME_CONTROL_AURA_1, SPELL_DREADFLAME_CONTROL_AURA_2, SPELL_DREADFLAME_CONTROL_AURA_3, SPELL_DREADFLAME_CONTROL_AURA_4 })
                    summon->CastSpell(nullptr, spellId, true);
                break;
            case NPC_BREADTH_OF_FROST:
                if (Creature* cenarius = instance->GetCreature(DATA_CENARIUS))
                    cenarius->CastSpell(summon, SPELL_BREADTH_OF_FROST_CAST);
                break;
            default:
                break;
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_INVOKE_SONS_OF_FLAME_TRIGGERED:
                Talk(SAY_INVOKE_SONS_OF_FLAME);
                events.ScheduleEvent(EVENT_ANNOUNCE_END_OF_INTERMISSION, 42s, 0, events.IsInPhase(PHASE_INTERMISSION_1) ? PHASE_INTERMISSION_1 : PHASE_INTERMISSION_2);
                if (events.IsInPhase(PHASE_INTERMISSION_2))
                    me->SummonCreatureGroup(SUMMON_GROUP_ID_LAVA_SCIONS);
                break;
            case ACTION_SON_OF_FLAME_DIED:
                ++_defeatedSonsOfFlame;
                if (_defeatedSonsOfFlame >= 8)
                {
                    events.CancelEvent(EVENT_ANNOUNCE_END_OF_INTERMISSION);
                    events.ScheduleEvent(EVENT_FINISH_INTERMISSION, 1s + 500ms, 0, events.IsInPhase(PHASE_INTERMISSION_1) ? PHASE_INTERMISSION_1 : PHASE_INTERMISSION_2);
                }
                break;
            case ACTION_ARCHDRUIDS_ARRIVED:
                Talk(SAY_SUBMERGE_HEROIC);
                me->AttackStop();
                me->SetReactState(REACT_PASSIVE);
                DoCastSelf(SPELL_LEGS_SUBMERGE);
                events.ScheduleEvent(EVENT_LEGS_HEAL, 5s + 500ms, 0, PHASE_FOUR);
                break;
            default:
                break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthBelowPctDamaged(70, damage) && events.IsInPhase(PHASE_ONE))
        {
            events.CancelEvent(EVENT_SET_AGGRESSIVE_REACT_STATE);
            events.SetPhase(PHASE_INTERMISSION_1);
            events.ScheduleEvent(EVENT_SPLITTING_BLOW, 1ms, 0, PHASE_INTERMISSION_1);
        }
        else if (me->HealthBelowPctDamaged(40, damage) && events.IsInPhase(PHASE_TWO))
        {
            events.CancelEvent(EVENT_SET_AGGRESSIVE_REACT_STATE);
            events.SetPhase(PHASE_INTERMISSION_2);
            events.ScheduleEvent(EVENT_SPLITTING_BLOW, 1ms, 0, PHASE_INTERMISSION_2);
        }
        else if (!IsHeroic() && !_defeated && me->HealthBelowPctDamaged(10, damage) && events.IsInPhase(PHASE_THREE))
        {
            EndEncounter(true);
            _defeated = true;
        }
        else if (IsHeroic() && me->HealthBelowPctDamaged(10, damage) && events.IsInPhase(PHASE_THREE))
        {
            events.SetPhase(PHASE_FOUR);
            me->SummonCreatureGroup(SUMMON_GROUP_ID_ARCHDRUIDS);
        }

        if (damage >= me->GetHealth() && !_canBeKilled)
            damage = me->GetHealth() - 1;
    }

    ObjectGuid GetGUID(int32 type /*= 0*/) const override
    {
        switch (type)
        {
            case DATA_CURRENT_SPLITTING_BLOW_TARGET:
                return _splittingBlowTargetGUID;
            default:
                return ObjectGuid::Empty;
        }
        return ObjectGuid::Empty;
    }

    void SetData(uint32 type, uint32 value) override
    {
        switch (type)
        {
            case DATA_CAST_DREADFLAMES:
            {
                if (Creature* dreadflame = instance->GetCreature(DATA_DREADFLAME_CONTROLLER))
                {
                    if (CreatureAI* ai = dreadflame->AI())
                    {
                        bool hasBeenCasted = false;
                        for (uint8 i = 0; i < value; ++i)
                        {
                            uint16 index = ai->GetData(DATA_DREADFLAME_POSTION_INFO_INDEX);
                            if (index != INVALID_DREADFLAME_POSITION_INFO_INDEX)
                            {
                                me->CastSpell(DreadflamePositionInfoData[index].Dest, SPELL_DREADFLAME_MISSILE, true);
                                ai->SetData(DATA_OCCUPY_DREADFLAME_POSITION_INFO_INDEX, index);
                                hasBeenCasted = true;
                            }
                            else
                                break;
                        }

                        if (hasBeenCasted)
                            Talk(SAY_ANNOUNCE_DREADFLAME);
                    }
                }
                break;
            }
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && !events.IsInPhase(PHASE_INTRO))
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_EMERGE:
                    me->PlayOneShotAnimKitId(ANIM_KIT_ID_EMERGE);
                    break;
                case EVENT_BASE_VISUAL:
                    DoCastSelf(SPELL_BASE_VISUAL);
                    break;
                case EVENT_FINISH_ARRIVAL:
                    DoCastSelf(SPELL_BURNING_WOUND);
                    if (instance->GetData(DATA_FIRST_RAGNAROS_SPAWN))
                    {
                        Talk(SAY_EMERGE);
                        me->PlayOneShotAnimKitId(ANIM_KIT_ID_TALK);
                        instance->SetData(DATA_FIRST_RAGNAROS_SPAWN, 0);
                    }
                    me->setActive(false);
                    break;
                case EVENT_WRATH_OF_RAGNAROS:
                    DoCastAOE(SPELL_WRATH_OF_RAGNAROS_AOE, CastSpellExtraArgs().AddSpellMod(SPELLVALUE_MAX_TARGETS, Is25ManRaid() ? 3 : 1));
                    Talk(SAY_WRATH_OF_RAGNAROS);
                    events.Repeat(30s);
                    break;
                case EVENT_HAND_OF_RAGNAROS:
                    DoCastAOE(SPELL_HAND_OF_RAGNAROS);
                    events.Repeat(26s);
                    break;
                case EVENT_MAGMA_TRAP:
                    Talk(SAY_ANNOUNCE_MAGMA_TRAP);
                    DoCastAOE(SPELL_MAGMA_TRAP_AOE, CastSpellExtraArgs().AddSpellMod(SPELLVALUE_MAX_TARGETS, 1));
                    events.Repeat(26s);
                    break;
                case EVENT_SULFURAS_SMASH:
                    // Delay cases
                    if (events.IsInPhase(PHASE_THREE) && Milliseconds(events.GetTimeUntilEvent(EVENT_SULFURAS_SMASH)) < 2s)
                        events.Repeat(2s);
                    if (me->HasAura(SPELL_WORLD_IN_FLAMES))
                        events.Repeat(1s);

                    DoCastAOE(SPELL_SULFURAS_SMASH_AOE, CastSpellExtraArgs().AddSpellMod(SPELLVALUE_MAX_TARGETS, 1));
                    events.Repeat(events.IsInPhase(PHASE_TWO) ? 40s : 30s);
                    break;
                case EVENT_SET_AGGRESSIVE_REACT_STATE:
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                case EVENT_SPLITTING_BLOW:
                    _splittingBlowTargetGUID = instance->GetGuidData(DATA_RANDOM_SPLITTING_BLOW_GUID);
                    if (_splittingBlowTargetGUID.IsEmpty()) // encounter broke. Phase transition wont work. Reset encounter
                    {
                        EnterEvadeMode(EVADE_REASON_OTHER);
                        break;
                    }

                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    if (Creature* splittingBlow = ObjectAccessor::GetCreature(*me, _splittingBlowTargetGUID))
                    {
                        // We are gong to summon 8 Sons of Flame at 8 random locations.
                        // However, we have to ensure that their spawn location has a certain distance to the splitting blow target.
                        std::vector<Position> sonOfFlamesPositions = SonOfFlameSpawnPositions;
                        for (std::vector<Position>::const_iterator itr = sonOfFlamesPositions.begin(); itr != sonOfFlamesPositions.end();)
                        {
                            if ((*itr).GetExactDist(splittingBlow) <= 30.f)
                                itr = sonOfFlamesPositions.erase(itr);
                            else
                                ++itr;
                        }

                        if (sonOfFlamesPositions.size() > 8)
                            Trinity::Containers::RandomResize(sonOfFlamesPositions, 8);
                        else if (sonOfFlamesPositions.size() < 8)
                        {
                            // There are too few Sons of Flame spawn positions available. Reset encounter
                            EnterEvadeMode(EVADE_REASON_OTHER);
                            break;
                        }

                        for (Position const& pos : sonOfFlamesPositions)
                            DoSummon(NPC_SON_OF_FLAME, pos, 0, TEMPSUMMON_MANUAL_DESPAWN);

                        _defeatedSonsOfFlame = 0;
                        Talk(SAY_ANNOUNCE_SPLITTING_BLOW);
                        Talk(SAY_SPLITTING_BLOW);
                        DoCastSelf(SPELL_SUBMERGE);
                        me->SetFacingToObject(splittingBlow);
                        me->SetOrientationTowards(splittingBlow);
                        DoCastSelf(SPELL_SPLITTING_BLOW);
                    }
                    break;
                case EVENT_MOLTEN_SEED:
                    DoCastAOE(SPELL_MOLTEN_SEED, CastSpellExtraArgs().AddSpellMod(SPELLVALUE_MAX_TARGETS, Is25ManRaid() ? 20 : 10));
                    events.Repeat(1min);
                    break;
                case EVENT_ENGULFING_FLAMES:
                    DoCastAOE(IsHeroic() ? SPELL_WORLD_IN_FLAMES : static_cast<uint32>(SPELL_ENGULFING_FLAMES), CastSpellExtraArgs().AddSpellBP0(urand(0, 2)));
                    Talk(IsHeroic() ? SAY_ANNOUNCE_WORLD_IN_FLAMES : SAY_ANNOUNCE_ENGULFING_FLAMES);
                    events.Repeat(events.IsInPhase(PHASE_TWO) ? 1min : 30s);
                    break;
                case EVENT_ANNOUNCE_END_OF_INTERMISSION:
                    Talk(SAY_ANNOUNCE_EMERGE);
                    events.ScheduleEvent(EVENT_FINISH_INTERMISSION, IsHeroic() ? 20s : 5s, 0, events.IsInPhase(PHASE_INTERMISSION_1) ? PHASE_INTERMISSION_1 : PHASE_INTERMISSION_2);
                    break;
                case EVENT_FINISH_INTERMISSION:
                    FinishIntermissionPhase();
                    break;
                case EVENT_LIVING_METEOR:
                    // Living Meteor delays Sulfuras Smash by 2 seconds
                    events.RescheduleEvent(EVENT_SULFURAS_SMASH, Milliseconds(events.GetTimeUntilEvent(EVENT_SULFURAS_SMASH)) + 2s, 0, PHASE_THREE);

                    DoCastAOE(SPELL_LIVING_METEOR, CastSpellExtraArgs().AddSpellMod(SPELLVALUE_MAX_TARGETS, 1));
                    events.Repeat(1min);
                    break;
                case EVENT_LEGS_HEAL:
                {
                    DoCastSelf(SPELL_LEGS_HEAL);
                    DoCastSelf(SPELL_TRANSFORM);
                    me->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING); // @todo: remove this once mmaps for gameobjects are supported
                    Position dest = me->GetPosition();
                    dest.m_positionZ = 56.f;
                    me->NearTeleportTo(dest);
                    events.ScheduleEvent(EVENT_FACE_HOME, 8s, 0, PHASE_FOUR);
                    break;
                }
                case EVENT_FACE_HOME:
                    me->SetFacingTo(me->GetHomePosition().GetOrientation());
                    events.ScheduleEvent(EVENT_EMERGE_HEROIC, 500ms, 0, PHASE_FOUR);
                    break;
                case EVENT_EMERGE_HEROIC:
                    if (GameObject* platform = instance->GetGameObject(DATA_RAGNAROS_PLATFORM))
                        platform->SetDestructibleState(GO_DESTRUCTIBLE_DAMAGED);
                    me->RemoveAurasDueToSpell(SPELL_LEGS_SUBMERGE);
                    me->SendSetPlayHoverAnim(true);
                    me->SetAnimationTier(AnimationTier::Fly, false);
                    me->SetControlled(false, UNIT_STATE_ROOT);
                    me->PlayOneShotAnimKitId(ANIM_KIT_ID_EMERGE_HEROIC);
                    instance->SetData(DATA_MAGMA_KNOCKBACK, 0);
                    events.ScheduleEvent(EVENT_TALK_EMERGE_HEROIC, 3s, 0, PHASE_FOUR);
                    break;
                case EVENT_TALK_EMERGE_HEROIC:
                    Talk(SAY_EMERGE_HEROIC);
                    me->PlayOneShotAnimKitId(ANIM_KIT_ID_TALK);
                    me->RemoveAurasDueToSpell(SPELL_DRAW_OUT_FIRELORD_CENARIUS);
                    me->RemoveAurasDueToSpell(SPELL_DRAW_OUT_FIRELORD_MALFURION);
                    me->RemoveAurasDueToSpell(SPELL_DRAW_OUT_FIRELORD_HAMUUL);
                    events.ScheduleEvent(EVENT_BREAK_FREE, 10s, 0, PHASE_FOUR);
                    break;
                case EVENT_BREAK_FREE:
                    if (GameObject* platform = instance->GetGameObject(DATA_RAGNAROS_PLATFORM))
                    {
                        platform->SetDestructibleState(GO_DESTRUCTIBLE_DESTROYED);
                        platform->EnableCollision(true); // we have to keep VMaps active for the platform
                    }

                    Talk(SAY_BREAK_FREE);
                    DoCastSelf(SPELL_DREADFLAME_SUMMON_CONTROLLER);
                    me->PlayOneShotAnimKitId(ANIM_KIT_ID_BREAK_FREE);
                    me->SendSetPlayHoverAnim(false);
                    me->SetAnimationTier(AnimationTier::Ground, false);
                    me->SetDisableGravity(false);
                    _canBeKilled = true;
                    events.ScheduleEvent(EVENT_SET_AGGRESSIVE_REACT_STATE, 5s, 0, PHASE_FOUR);
                    events.ScheduleEvent(EVENT_SUPERHEATED, 5s, 0, PHASE_FOUR);
                    events.ScheduleEvent(EVENT_ENTRAPPING_ROOTS, 41s, 0, PHASE_FOUR);
                    events.ScheduleEvent(EVENT_DREADFLAME, 16s, 0, PHASE_FOUR);
                    events.ScheduleEvent(EVENT_BREADTH_OF_FROST, 6s, 0, PHASE_FOUR);
                    break;
                case EVENT_SUPERHEATED:
                    DoCastSelf(SPELL_SUPERHEATED);
                    break;
                case EVENT_ENTRAPPING_ROOTS:
                    DoCastAOE(SPELL_ENTRAPPING_ROOTS);
                    events.ScheduleEvent(EVENT_EMPOWER_SULFURAS, 15s, 0, PHASE_FOUR);
                    events.Repeat(55s);
                    break;
                case EVENT_EMPOWER_SULFURAS:
                    if (!me->HasUnitState(UNIT_STATE_STUNNED))
                    {
                        Talk(SAY_ANNOUNCE_EMPOWER_SULFURAS);
                        DoCastSelf(SPELL_EMPOWER_SULFURAS);
                    }
                    break;
                case EVENT_DREADFLAME:
                    DoCastSelf(SPELL_DREADFLAME_PERIODIC);
                    break;
                case EVENT_BREADTH_OF_FROST:
                    DoCastAOE(SPELL_BREADTH_OF_FROST_TRIGGER);
                    events.Repeat(46s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        if (me->GetVictim() && me->GetVictim()->IsWithinMeleeRange(me))
            DoMeleeAttackIfReady();
        else if (!events.IsInPhase(PHASE_FOUR))
            DoSpellAttackIfReady(SPELL_MAGMA_BLAST);
    }
private:
    GuidVector _archdruidGUIDs;
    ObjectGuid _splittingBlowTargetGUID;
    uint8 _defeatedSonsOfFlame;
    bool _defeated;
    bool _canBeKilled;

    void FinishIntermissionPhase()
    {
        uint8 nextPhase = events.IsInPhase(PHASE_INTERMISSION_1) ? PHASE_TWO : PHASE_THREE;

        if (Creature* sulfuras = instance->GetCreature(DATA_SULFURAS_HAND_OF_RAGNAROS))
            sulfuras->DespawnOrUnsummon(3s);

        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        me->RemoveAurasDueToSpell(SPELL_SUBMERGE_AURA);
        Talk(SAY_PICK_UP_SULFURAS);
        DoCastSelf(SPELL_BASE_VISUAL);
        me->PlayOneShotAnimKitId(ANIM_KIT_ID_PICK_UP_SULFURAS);
        events.SetPhase(nextPhase);
        events.ScheduleEvent(EVENT_SET_AGGRESSIVE_REACT_STATE, 5s, 0, nextPhase);

        if (nextPhase == PHASE_TWO)
        {
            events.ScheduleEvent(EVENT_SULFURAS_SMASH, 5s + 500ms, 0, PHASE_TWO);
            events.ScheduleEvent(EVENT_MOLTEN_SEED, 15s, 0, PHASE_TWO);
            events.ScheduleEvent(EVENT_ENGULFING_FLAMES, 40s, 0, PHASE_TWO);
        }
        else if (nextPhase == PHASE_THREE)
        {
            events.ScheduleEvent(EVENT_SULFURAS_SMASH, 15s, 0, PHASE_THREE);
            events.ScheduleEvent(EVENT_ENGULFING_FLAMES, 30s, 0, PHASE_THREE);
            events.ScheduleEvent(EVENT_LIVING_METEOR, 45s, 0, PHASE_THREE);
        }
    }

    void EndEncounter(bool victorious)
    {
        EntryCheckPredicate pred(NPC_LAVA_SCION);
        summons.DoAction(ACTION_DISENGAGE, pred);
        summons.DespawnAll();
        me->InterruptNonMeleeSpells(true);
        instance->instance->SpawnGroupDespawn(SPAWN_GROUP_ID_RAGNAROS_STALKERS);
        events.Reset();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DELUGE);

        if (victorious)
        {
            DoCastAOE(SPELL_ACHIEVEMENT_CHECK);
            DoCastAOE(SPELL_AWARD_REPUTATION_BOSS_KILL);
            //DoCastAOE(SPELL_HEART_OF_RAGNAROS);

            if (!IsHeroic())
            {
                Talk(SAY_DEFEATED);
                DoCastSelf(SPELL_SUMMON_CHEST);
                DoCastSelf(SPELL_DEATH);
                instance->instance->PermBindAllPlayers();
            }
            else
            {
                Talk(SAY_DEATH);
                for (ObjectGuid const& guid : _archdruidGUIDs)
                    if (Creature* archdruid = ObjectAccessor::GetCreature(*me, guid))
                        if (CreatureAI* ai = archdruid->AI())
                            ai->DoAction(ACTION_RAGNAROS_KILLED);
            }

            // We should probably create a serverside spell for that but since we do not have sniff data due to being serverside, we're sticking with that for now.
            instance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_RAGNAROS_KILL_CREDIT, 0, me);
            instance->UpdateEncounterStateForSpellCast(SPELL_RAGNAROS_KILL_CREDIT, me);

            instance->instance->SetSpawnGroupInactive(SPAWN_GROUP_ID_RAGNAROS);
            instance->SetBossState(DATA_RAGNAROS, DONE);
        }
        else
        {
            if (GameObject* platform = instance->GetGameObject(DATA_RAGNAROS_PLATFORM))
                platform->SetDestructibleState(GO_DESTRUCTIBLE_INTACT);

            if (IsHeroic())
                for (ObjectGuid const& guid : _archdruidGUIDs)
                    if (Creature* archdruid = ObjectAccessor::GetCreature(*me, guid))
                        archdruid->DespawnOrUnsummon();

            _DespawnAtEvade();
        }
    }
};

struct npc_ragnaros_son_of_flame : public ScriptedAI
{
    npc_ragnaros_son_of_flame(Creature* creature) : ScriptedAI(creature), _instance(nullptr)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void InitializeAI() override
    {
        _instance = me->GetInstanceScript();
    }

    void JustAppeared() override
    {
        me->SetDisableGravity(true);
        me->SetControlled(true, UNIT_STATE_ROOT);
        me->SetCorpseDelay(2);
        DoCastSelf(SPELL_HIT_ME);
        DoCastSelf(SPELL_INVIS_PRE_VISUAL_1);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* ragnaros = _instance->GetCreature(DATA_RAGNAROS))
            if (CreatureAI* ai = ragnaros->AI())
                ai->DoAction(ACTION_SON_OF_FLAME_DIED);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_INVOKE_SON:
                me->RemoveAurasDueToSpell(SPELL_INVIS_PRE_VISUAL_1);
                me->CastSpell(nullptr, SPELL_BURNING_SPEED);
                me->SetDisableGravity(false);
                me->SetControlled(false, UNIT_STATE_ROOT);
                me->PlayOneShotAnimKitId(ANIM_KIT_ID_INVOKE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                if (Creature const* sulfuras = _instance->GetCreature(DATA_SULFURAS_HAND_OF_RAGNAROS))
                {
                    _destination = sulfuras->GetPosition();
                    _events.ScheduleEvent(EVENT_MOVE_TOWARDS_SULFURAS, 2s + 500ms);
                }
                break;
            default:
                break;
        }
    }

    void MovementInform(uint32 motionType, uint32 id) override
    {
        if (motionType != POINT_MOTION_TYPE)
            return;

        switch (id)
        {
            case POINT_ID_TRIGGER_SUPERNOVA:
                if (!me->HasUnitState(UNIT_STATE_NOT_MOVE))
                {
                    DoCastSelf(SPELL_SUPERNOVA);
                    DoCastSelf(SPELL_QUITE_SUICIDE);
                }
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!me->IsAlive())
            return;

        ScriptedAI::UpdateAI(diff);

        _events.Update(diff);
        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_MOVE_TOWARDS_SULFURAS:
                    if (me->movespline->Finalized() && !me->HasUnitState(UNIT_STATE_NOT_MOVE))
                    {
                        float dist = me->GetExactDist(_destination);
                        if (dist > 4.4f)
                            dist -= 4.4f;
                        else
                        {
                            DoCastSelf(SPELL_SUPERNOVA);
                            DoCastSelf(SPELL_QUITE_SUICIDE);
                            break;
                        }

                        float angle = me->GetAngle(_destination);
                        Position dest = me->GetPosition();
                        dest.m_positionX += std::cos(angle) * dist;
                        dest.m_positionY += std::sin(angle) * dist;

                        me->GetMotionMaster()->MovePoint(POINT_ID_TRIGGER_SUPERNOVA, dest, false);
                    }
                    _events.Repeat(1s);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    InstanceScript* _instance;
    Position _destination;
};

struct npc_ragnaros_lava_scion : public ScriptedAI
{
    npc_ragnaros_lava_scion(Creature* creature) : ScriptedAI(creature), _instance(nullptr) { }

    void InitializeAI() override
    {
        _instance = me->GetInstanceScript();
    }

    void JustAppeared() override
    {
        DoZoneInCombat();
    }

    void JustEngagedWith(Unit* who) override
    {
        ScriptedAI::JustEngagedWith(who);
        _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        _events.ScheduleEvent(EVENT_BLAZING_HEAT, 15s);
    }

    void JustDied(Unit* who) override
    {
        ScriptedAI::JustDied(who);
        _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _events.Reset();
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_DISENGAGE:
                _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                break;
            default:
                break;
        }
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
                case EVENT_BLAZING_HEAT:
                    DoCastAOE(SPELL_BLAZING_HEAT, CastSpellExtraArgs().AddSpellMod(SPELLVALUE_MAX_TARGETS, 1));
                    _events.Repeat(23s);
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

struct npc_ragnaros_living_meteor : public ScriptedAI
{
    npc_ragnaros_living_meteor(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_LIVING_METEOR_DAMAGE_REDUCTION);
        DoZoneInCombat();
        _events.ScheduleEvent(EVENT_COMBUSTIBLE, 2s + 500ms);
        _events.ScheduleEvent(EVENT_FIXATE, 3s);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_COMBUSTION_TRIGGERED:
            case ACTION_IMPACT_TRIGGERED:
                me->AttackStop();
                me->SetReactState(REACT_PASSIVE);
                _events.ScheduleEvent(EVENT_FIXATE, 400ms);
                _events.ScheduleEvent(EVENT_COMBUSTIBLE, action == ACTION_COMBUSTION_TRIGGERED ? 7s : 4s);
                _events.ScheduleEvent(EVENT_RESUME_CHASE_MOVEMENT, action == ACTION_COMBUSTION_TRIGGERED ? 2s : 4s);
                break;
            default:
                break;
        }
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
                case EVENT_FIXATE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.f, true, true))
                        DoCast(target, SPELL_FIXATE);
                    break;
                case EVENT_COMBUSTIBLE:
                    DoCastSelf(SPELL_COMBUSTIBLE, true);
                    break;
                case EVENT_RESUME_CHASE_MOVEMENT:
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

struct npc_ragnaros_archdruid : public NullCreatureAI
{
    npc_ragnaros_archdruid(Creature* creature) : NullCreatureAI(creature), _instance(nullptr) { }

    void InitializeAI() override
    {
        _instance = me->GetInstanceScript();
    }

    void MovementInform(uint32 motionType, uint32 pointId) override
    {
        if (motionType != WAYPOINT_MOTION_TYPE && motionType != POINT_MOTION_TYPE)
            return;

        if (motionType == WAYPOINT_MOTION_TYPE)
        {
            switch (pointId)
            {
                case POINT_ID_ENTER_PLATFORM:
                {
                    if (me->GetEntry() == NPC_ARCHDRUID_HAMUUL_RUNETOTEM || me->GetEntry() == NPC_MALFURION_STORMRAGE)
                    {
                        Position dest = me->GetPosition();
                        dest.m_positionZ = me->GetFloorZ();
                        me->GetMotionMaster()->MovePoint(POINT_ID_LAND, dest, false, 2.5f);
                    }
                    else
                    {
                        if (Creature* ragnaros = _instance->GetCreature(DATA_RAGNAROS))
                            if (CreatureAI* ai = ragnaros->AI())
                                ai->DoAction(ACTION_ARCHDRUIDS_ARRIVED);

                        _events.ScheduleEvent(EVENT_TALK_PREPARE_TO_DRAW_RAGNAROS_OUT, 3s + 600ms);
                    }

                    Milliseconds drawOutTimer = 7s;
                    if (me->GetEntry() == NPC_MALFURION_STORMRAGE)
                        drawOutTimer += 1s;
                    else if (me->GetEntry() == NPC_CENARIUS)
                        drawOutTimer += 2s;

                    _events.ScheduleEvent(EVENT_DRAW_OUT_FIRELORD, drawOutTimer);
                    break;
                }
                default:
                    break;
            }
        }
        else
        {
            switch (pointId)
            {
                case POINT_ID_LAND:
                    me->SetDisableGravity(false);
                    me->SetHover(false);
                    DoCastSelf(me->GetEntry() == NPC_ARCHDRUID_HAMUUL_RUNETOTEM ? SPELL_TRANSFORM_HAMUUL : SPELL_TRANSFORM_MALFURION);
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
            case ACTION_RAGNAROS_KILLED:
                switch (me->GetEntry())
                {
                    case NPC_MALFURION_STORMRAGE:
                        _events.ScheduleEvent(EVENT_OUTRO_1, 5s + 500ms);
                        _events.ScheduleEvent(EVENT_OUTRO_2, 12s + 500ms);
                        break;
                    case NPC_ARCHDRUID_HAMUUL_RUNETOTEM:
                        _events.ScheduleEvent(EVENT_OUTRO_1, 32s);
                        break;
                    case NPC_CENARIUS:
                        _events.ScheduleEvent(EVENT_OUTRO_1, 9s);
                        _events.ScheduleEvent(EVENT_OUTRO_2, 18s + 500ms);
                        _events.ScheduleEvent(EVENT_OUTRO_3, 45s + 500ms);
                        break;
                    default:
                        break;
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
                case EVENT_TALK_PREPARE_TO_DRAW_RAGNAROS_OUT:
                    Talk(SAY_PREPARE_TO_DRAW_RAGNAROS_OUT);
                    break;
                case EVENT_DRAW_OUT_FIRELORD:
                {
                    uint32 spellId = SPELL_DRAW_OUT_FIRELORD_HAMUUL;
                    if (me->GetEntry() == NPC_MALFURION_STORMRAGE)
                        spellId = SPELL_DRAW_OUT_FIRELORD_MALFURION;
                    else if (me->GetEntry() == NPC_CENARIUS)
                        spellId = SPELL_DRAW_OUT_FIRELORD_CENARIUS;

                    DoCastAOE(spellId);

                    if (me->GetEntry() == NPC_MALFURION_STORMRAGE)
                    {
                        _events.ScheduleEvent(EVENT_SAY_RAGNAROS_BOUND, 14s);
                        _events.ScheduleEvent(EVENT_CLOUDBURST, 27s);
                    }
                    break;
                }
                case EVENT_SAY_RAGNAROS_BOUND:
                    me->PlayOneShotAnimKitId(ANIM_KIT_ID_YELL);
                    Talk(SAY_RAGNAROS_BOUND);
                    break;
                case EVENT_CLOUDBURST:
                    DoCastAOE(SPELL_CLOUDBURST, CastSpellExtraArgs().AddSpellMod(SPELLVALUE_MAX_TARGETS, 1));
                    break;
                case EVENT_OUTRO_1:
                    if (me->GetEntry() == NPC_MALFURION_STORMRAGE)
                        me->PlayOneShotAnimKitId(ANIM_KIT_ID_YELL);
                    Talk(SAY_OUTRO_1);
                    break;
                case EVENT_OUTRO_2:
                    if (me->GetEntry() == NPC_MALFURION_STORMRAGE)
                        me->PlayOneShotAnimKitId(ANIM_KIT_ID_YELL);
                    Talk(SAY_OUTRO_2);
                    break;
                case EVENT_OUTRO_3:
                    Talk(SAY_OUTRO_3);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    InstanceScript* _instance;
};

struct npc_ragnaros_dreadflame : public NullCreatureAI
{
    npc_ragnaros_dreadflame(Creature* creature) : NullCreatureAI(creature) { }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_SPREAD_DREADFLAMES:
            {
                if (_occupiedDreadflameIndexes.empty())
                    break;

                boost::container::flat_set<uint16> availableSpreadLocations;

                for (uint16 index : _occupiedDreadflameIndexes)
                    for (int8 offset : { -1, 31, 1, -31 })
                        if (IsLocationAvailable(index + offset))
                            availableSpreadLocations.insert(index + offset);

                if (availableSpreadLocations.empty())
                    break;

                Trinity::Containers::RandomResize(availableSpreadLocations, std::ceil(_occupiedDreadflameIndexes.size() / 2));

                _newlyStoredDreadflameIndexes.clear();
                for (uint16 index : availableSpreadLocations)
                {
                    me->CastSpell(DreadflamePositionInfoData[index].Dest, SPELL_DREADFLAME_AREA_DUMMY_AURA);
                    OccupyDreadflameIndex(index);
                }

                break;
            }
            default:
                break;
        }
    }

    void SetData(uint32 type, uint32 value) override
    {
        switch (type)
        {
            case DATA_OCCUPY_DREADFLAME_POSITION_INFO_INDEX:
                OccupyDreadflameIndex(value);
                break;
            case DATA_RELEASE_DREADFLAME_POSITION_INFO_INDEX:
                _occupiedDreadflameIndexes.erase(value);
                _newlyStoredDreadflameIndexes.erase(value);
                break;
            default:
                break;
        }
    }

    uint32 GetData(uint32 type) const override
    {
        switch (type)
        {
            case DATA_DREADFLAME_POSTION_INFO_INDEX:
            {
                bool noIndexesAvailable = true;
                DreadflamePositionInfoArray::const_iterator itr = Trinity::Containers::SelectRandomWeightedContainerElement(DreadflamePositionInfoData, [&](DreadflamePositionInfo const& info)
                {
                    if (!info.OnPlatform || _occupiedDreadflameIndexes.find(info.Index) != _occupiedDreadflameIndexes.end())
                        return 0.f;

                    noIndexesAvailable = false;
                    return 1.f;
                });

                if (noIndexesAvailable || itr == DreadflamePositionInfoData.end())
                    return INVALID_DREADFLAME_POSITION_INFO_INDEX;

                return itr->Index;
            }
            default:
                return 0;
        }

        return 0;
    }

private:
    std::unordered_set<uint16> _occupiedDreadflameIndexes;
    std::unordered_set<uint16> _newlyStoredDreadflameIndexes;

    bool IsLocationAvailable(int16 index)
    {
        // Index is out of range
        if (index < 0 || index > int16(DreadflamePositionInfoData.size() - 1))
            return false;

        // Location is not on the platform
        if (!DreadflamePositionInfoData[index].OnPlatform)
            return false;

        // Index has been occupied just prior to this spread tick. Skip spreading that flame
        if (_newlyStoredDreadflameIndexes.find(index) != _newlyStoredDreadflameIndexes.end())
            return false;

        return _occupiedDreadflameIndexes.find(index) == _occupiedDreadflameIndexes.end();
    }

    void OccupyDreadflameIndex(uint16 index)
    {
        _occupiedDreadflameIndexes.insert(index);
        _newlyStoredDreadflameIndexes.insert(index);
    }
};

struct npc_ragnaros_cloudburst : public NullCreatureAI
{
    npc_ragnaros_cloudburst(Creature* creature) : NullCreatureAI(creature), _allowedSpellClicks(0) { }

    void InitializeAI() override
    {
        _allowedSpellClicks = me->GetMap()->Is25ManRaid() ? 3 : 1;
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK); // we have to assign the spellclick flag manually since we do not use npc_spellclick_spells for strict click number control
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_CLOUDBURST_VISUAL);
    }

    void OnSpellClick(Unit* clicker, bool& result) override
    {
        if (!_allowedSpellClicks)
            result = false;
        else
        {
            --_allowedSpellClicks;
            clicker->CastSpell(nullptr, SPELL_DELUGE);

            if (!_allowedSpellClicks)
                me->DespawnOrUnsummon();
        }
    }

private:
    uint8 _allowedSpellClicks;
};

class spell_ragnaros_wrath_of_ragnaros : public SpellScript
{
    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(GetHitUnit(), static_cast<uint32>(GetEffectValue()));
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_ragnaros_wrath_of_ragnaros::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_ragnaros_magma_trap : public SpellScript
{
    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(GetHitUnit(), static_cast<uint32>(GetEffectValue()));
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_ragnaros_magma_trap::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_ragnaros_magma_trap_periodic : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGMA_TRAP_ERUPTION, SPELL_MAGMA_TRAP_VULNERABILITY });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        _triggerDetonation = !targets.empty();
    }

    void HandleDetonation()
    {
        if (!_triggerDetonation)
            return;

        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(nullptr, SPELL_MAGMA_TRAP_ERUPTION);

        if (caster->GetMap()->IsHeroic())
            caster->CastSpell(nullptr, SPELL_MAGMA_TRAP_VULNERABILITY);

        caster->RemoveAllAuras();

        if (caster->IsCreature())
            caster->ToCreature()->DespawnOrUnsummon(4s);

        _triggerDetonation = false;
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_ragnaros_magma_trap_periodic::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        AfterCast.Register(&spell_ragnaros_magma_trap_periodic::HandleDetonation);
    }
private:
    bool _triggerDetonation = false;
};

class spell_ragnaros_magma_trap_missile: public SpellScript
{
    void SetTargetDest(SpellDestination& target)
    {
        Position dest = target._position;
        dest.m_positionZ = GetCaster()->GetMapHeight(dest.GetPositionX(), dest.GetPositionY(), GetCaster()->GetPositionZ() + 10.f);
        target.Relocate(dest);
    }

    void Register() override
    {
        OnDestinationTargetSelect.Register(&spell_ragnaros_magma_trap_missile::SetTargetDest, EFFECT_0, TARGET_DEST_TARGET_ANY);
    }
};

class spell_ragnaros_sulfuras_smash : public SpellScript
{
    bool Load() override
    {
        _instance = GetCaster()->GetInstanceScript();
        return true;
    }

    void HandleDummyEffect1(SpellEffIndex /*effIndex*/)
    {
        if (!_instance)
            return;

        Creature* smash = _instance->GetCreature(DATA_SULFURAS_SMASH);
        if (!smash)
            return;

        Unit* target = GetHitUnit();
        target->CastSpell(nullptr, SPELL_LAVA_WAVE);

        Position dest = target->GetPosition();
        dest.SetOrientation(Position::NormalizeOrientation(dest.GetAngle(smash) + float(M_PI)));
        dest.m_positionX += std::cos(dest.GetOrientation()) * 80.f;
        dest.m_positionY += std::sin(dest.GetOrientation()) * 80.f;
        target->GetMotionMaster()->MovePoint(0, dest, false);
    }

    void HandleDummyEffect2(SpellEffIndex /*effIndex*/)
    {
        Creature* target = GetHitCreature();
        if (!target)
            return;

        target->RemoveAllAuras();
        target->CastSpell(nullptr, SPELL_SCORCHED_GROUND);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_ragnaros_sulfuras_smash::HandleDummyEffect1, EFFECT_1, SPELL_EFFECT_DUMMY);
        OnEffectHitTarget.Register(&spell_ragnaros_sulfuras_smash::HandleDummyEffect2, EFFECT_2, SPELL_EFFECT_DUMMY);
    }
private:
    InstanceScript* _instance = nullptr;
};

class spell_ragnaros_splitting_blow: public SpellScript
{
    void SetTargetDest(SpellDestination& target)
    {
        if (Creature* caster = GetCaster()->ToCreature())
            if (CreatureAI* ai = caster->AI())
                if (ObjectGuid guid = ai->GetGUID(DATA_CURRENT_SPLITTING_BLOW_TARGET))
                    if (Creature* splittingBlow = ObjectAccessor::GetCreature(*caster, guid))
                        target.Relocate(splittingBlow->GetPosition());
    }

    void Register() override
    {
        OnDestinationTargetSelect.Register(&spell_ragnaros_splitting_blow::SetTargetDest, EFFECT_0, TARGET_DEST_NEARBY_ENTRY);
    }
};

class spell_ragnaros_splitting_blow_script: public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        Unit* target = GetHitUnit();
        target->CastSpell(nullptr, static_cast<uint32>(GetEffectValue()));
        target->CastSpell(nullptr, static_cast<uint32>(GetSpellInfo()->Effects[EFFECT_1].BasePoints));

        if (Creature* creature = caster->ToCreature())
            if (CreatureAI* ai = creature->AI())
                ai->DoAction(ACTION_INVOKE_SONS_OF_FLAME_TRIGGERED);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_ragnaros_splitting_blow_script::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_ragnaros_invoke_sons: public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_INVOKE_SONS });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), SPELL_INVOKE_SONS);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_ragnaros_invoke_sons::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_ragnaros_invoke_sons_script: public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Creature* creature = GetHitCreature())
            if (CreatureAI* ai = creature->AI())
                ai->DoAction(ACTION_INVOKE_SON);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_ragnaros_invoke_sons_script::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_ragnaros_submerge: public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BASE_VISUAL });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        target->RemoveAurasDueToSpell(SPELL_BASE_VISUAL);
        target->RemoveAppliedAuras([target](AuraApplication const* aurApp)->bool
        {
            return aurApp->GetBase()->GetCasterGUID() != target->GetGUID();
        });
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_ragnaros_submerge::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_ragnaros_submerge_AuraScript : public AuraScript
{
    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_ragnaros_submerge_AuraScript::HandleApply, EFFECT_0, m_scriptSpellId == SPELL_LEGS_SUBMERGE ? SPELL_AURA_DUMMY : SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove.Register(&spell_ragnaros_submerge_AuraScript::HandleRemove, EFFECT_0, m_scriptSpellId == SPELL_LEGS_SUBMERGE ? SPELL_AURA_DUMMY : SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_ragnaros_burning_speed : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BURNING_SPEED_AURA });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        uint8 stacks = ceilf(target->GetHealthPct() / 10);

        if (Aura* burningSpeed = target->GetAura(SPELL_BURNING_SPEED_AURA, target->GetGUID()))
            burningSpeed->SetStackAmount(stacks);
        else
            target->CastSpell(nullptr, SPELL_BURNING_SPEED_AURA, CastSpellExtraArgs().AddSpellMod(SPELLVALUE_AURA_STACK, stacks));
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_ragnaros_burning_speed::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class spell_ragnaros_molten_seed: public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Unit const* caster = GetCaster();
        targets.sort(Trinity::ObjectDistanceOrderPred(caster, true));
        targets.resize(1);
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            GetHitUnit()->CastSpell(caster, static_cast<uint32>(GetEffectValue()));
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_ragnaros_molten_seed::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        OnObjectAreaTargetSelect.Register(&spell_ragnaros_molten_seed::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

class spell_ragnaros_molten_seed_dummy: public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MOLTEN_SEED_VISUAL });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(nullptr, SPELL_MOLTEN_SEED_VISUAL);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_ragnaros_molten_seed_dummy::HandleDummyEffect, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

class spell_ragnaros_molten_seed_visual : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_MOLTEN_POWER,
            SPELL_MOLTEN_INFERNO,
            SPELL_AGGRO_DEMON_CREATOR,
            SPELL_REDUCE_CRITICAL_STRIKE_CHANCE_100_PCT,
            SPELL_INVIS_PRE_VISUAL_2
        });
    }

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        if (aurEff->GetTickNumber() == uint32(aurEff->GetTotalTicks()))
            GetTarget()->CastSpell(nullptr, SPELL_MOLTEN_POWER);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->RemoveAurasDueToSpell(SPELL_INVIS_PRE_VISUAL_2);
        target->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
        target->CastSpell(nullptr, SPELL_MOLTEN_INFERNO);

        if (Creature* creature = target->ToCreature())
        {
            target->m_Events.AddEventAtOffset([creature]()
            {
                creature->CastSpell(nullptr, SPELL_AGGRO_DEMON_CREATOR);
                creature->CastSpell(nullptr, SPELL_REDUCE_CRITICAL_STRIKE_CHANCE_100_PCT);
            }, 1s);
        }
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_ragnaros_molten_seed_visual::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        AfterEffectRemove.Register(&spell_ragnaros_molten_seed_visual::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_ragnaros_engulfing_flames: public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        target->CastSpell(nullptr, EngulfingFlamesData[GetEffectValue()].VisualSpellID);
        target->CastSpell(nullptr, EngulfingFlamesData[GetEffectValue()].CastSpellID);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_ragnaros_engulfing_flames::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_ragnaros_world_in_flames : public AuraScript
{
    bool Load() override
    {
        _previouslyNukedSegment = urand(0, 2);
        return true;
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();

        uint8 segmentToNuke = urand(0, EngulfingFlamesData.size() - 1);
        if (segmentToNuke == _previouslyNukedSegment)
            segmentToNuke = uint16(segmentToNuke + 1) % EngulfingFlamesData.size();

        GetTarget()->CastSpell(nullptr, SPELL_ENGULFING_FLAMES, CastSpellExtraArgs().AddSpellBP0(segmentToNuke));
        _previouslyNukedSegment = segmentToNuke;
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_ragnaros_world_in_flames::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
private:
    uint8 _previouslyNukedSegment = 0;
};

class spell_ragnaros_molten_inferno: public SpellScript
{
    void HandleDamageFalloff(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        // Calculation is based on sniff research
        uint32 damage = GetHitDamage();
        float distanceDamageMod = caster->GetExactDist2d(GetHitUnit()) / 5.f;
        if (distanceDamageMod < 1.f)
            return;

        damage /= distanceDamageMod;
        SetHitDamage(damage);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_ragnaros_molten_inferno::HandleDamageFalloff, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

class spell_ragnaros_blazing_heat: public SpellScript
{
    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), static_cast<uint32>(GetEffectValue()));
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_ragnaros_blazing_heat::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_ragnaros_blazing_heat_script: public SpellScript
{
    bool Load() override
    {
        return GetCaster()->IsCreature();
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (CreatureAI* ai = caster->ToCreature()->AI())
            ai->Talk(SAY_ANNOUNCE_BLAZING_HEAT, GetHitUnit());
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_ragnaros_blazing_heat_script::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_ragnaros_blazing_heat_aoe : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BLAZING_HEAT_SUMMON });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        _triggerSummon = targets.empty();
    }

    void HandleSummon()
    {
        if (!_triggerSummon)
            return;

        if (Unit* caster = GetCaster())
            caster->CastSpell(caster->GetPosition(), SPELL_BLAZING_HEAT_SUMMON, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_ragnaros_blazing_heat_aoe::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        AfterCast.Register(&spell_ragnaros_blazing_heat_aoe::HandleSummon);
    }
private:
    bool _triggerSummon = false;
};

class spell_ragnaros_living_meteor: public SpellScript
{
    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(GetHitUnit(), static_cast<uint32>(GetEffectValue()));
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_ragnaros_living_meteor::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_ragnaros_living_meteor_aoe: public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_METEOR_IMPACT,
                SPELL_TRIGGERED_LIVING_METEOR,
                SPELL_COMBUSTIBLE
            });
    }

    void HandleImpact()
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(nullptr, SPELL_METEOR_IMPACT);
        caster->CastSpell(nullptr, SPELL_TRIGGERED_LIVING_METEOR);
        caster->RemoveAurasDueToSpell(sSpellMgr->GetSpellIdForDifficulty(SPELL_COMBUSTIBLE , caster));

        if (Creature* creature = caster->ToCreature())
            if (CreatureAI* ai = creature->AI())
                ai->DoAction(ACTION_IMPACT_TRIGGERED);
    }

    void Register() override
    {
        AfterHit.Register(&spell_ragnaros_living_meteor_aoe::HandleImpact);
    }
};

class spell_ragnaros_fixate : public AuraScript
{
    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            caster->GetThreatManager().FixateTarget(GetTarget());
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            caster->GetThreatManager().ClearFixate();
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_ragnaros_fixate::HandleApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove.Register(&spell_ragnaros_fixate::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_ragnaros_combustible : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_COMBUSTION,
                SPELL_LIVING_METEOR_TARGET_SEARCHER,
                SPELL_LIVING_METEOR_SPEED_STACKER,
                SPELL_LIVING_METEOR_SPEED_AURA
            });
    }

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->CastSpell(nullptr, SPELL_LIVING_METEOR_TARGET_SEARCHER, true);
        target->CastSpell(nullptr, SPELL_LIVING_METEOR_SPEED_STACKER, true);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->RemoveAurasDueToSpell(sSpellMgr->GetSpellIdForDifficulty(SPELL_LIVING_METEOR_TARGET_SEARCHER, target));
        target->RemoveAurasDueToSpell(sSpellMgr->GetSpellIdForDifficulty(SPELL_LIVING_METEOR_SPEED_STACKER, target));
        target->RemoveAurasDueToSpell(sSpellMgr->GetSpellIdForDifficulty(SPELL_LIVING_METEOR_SPEED_AURA, target));
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        return eventInfo.GetActor();
    }

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(eventInfo.GetActor(), SPELL_COMBUSTION);

        if (Creature* creature = GetTarget()->ToCreature())
            if (CreatureAI* ai = creature->AI())
                ai->DoAction(ACTION_COMBUSTION_TRIGGERED);
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_ragnaros_combustible::HandleApply, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove.Register(&spell_ragnaros_combustible::HandleRemove, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        DoCheckProc.Register(&spell_ragnaros_combustible::CheckProc);
        OnEffectProc.Register(&spell_ragnaros_combustible::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

class spell_ragnaros_death : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Creature* creature = GetHitCreature();
        if (!creature)
            return;

        creature->RemoveAppliedAuras([creature](AuraApplication const* aurApp)->bool
        {
            return aurApp->GetBase()->GetCasterGUID() != creature->GetGUID();
        });

        creature->AttackStop();
        creature->SetReactState(REACT_PASSIVE);
        creature->SetFacingTo(3.533860683441162109f);
        creature->RemoveAurasDueToSpell(SPELL_BASE_VISUAL);
        creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        creature->DespawnOrUnsummon(4s);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_ragnaros_death::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_ragnaros_burning_wound : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BURNING_BLAST });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        Unit* target = GetTarget();
        int32 basePoints = sSpellMgr->AssertSpellInfo(SPELL_BURNING_BLAST)->Effects[EFFECT_0].CalcValue(target);
        AddPct(basePoints, GetStackAmount() * 10.f);

        target->CastSpell(eventInfo.GetProcTarget(), SPELL_BURNING_BLAST, CastSpellExtraArgs(aurEff).AddSpellBP0(basePoints));
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_ragnaros_burning_wound::HandleProc, EFFECT_1, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

class spell_ragnaros_empowered_sulfuras: public AuraScript
{

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, ITEM_SLOT_ID_EMPOWERED_SULFURAS);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, ITEM_SLOT_ID_DEFAULT_SULFURAS);
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_ragnaros_empowered_sulfuras::HandleApply, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove.Register(&spell_ragnaros_empowered_sulfuras::HandleRemove, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_ragnaros_empower_sulfuras : public SpellScript
{
    void HandleAfterCast()
    {
        GetCaster()->CastSpell(nullptr, GetSpellInfo()->Effects[EFFECT_1].BasePoints);
    }

    void Register() override
    {
        AfterCast.Register(&spell_ragnaros_empower_sulfuras::HandleAfterCast);
    }
};

class spell_ragnaros_empower_sulfuras_periodic : public AuraScript
{
    void HandlePeriodic(AuraEffect const* aurEff)
    {
        if (roll_chance_f(75.f))
            return;

        GetTarget()->CastSpell(nullptr, GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell);
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_ragnaros_empower_sulfuras_periodic::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class spell_ragnaros_entrapping_roots: public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(nullptr, static_cast<uint32>(GetEffectValue()));
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_ragnaros_entrapping_roots::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_ragnaros_entrapping_roots_aura: public SpellScript
{
    void HandleAuraRemoval(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->RemoveAllAuras();
        if (Creature* creature = caster->ToCreature())
            creature->DespawnOrUnsummon(2s + 500ms);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_ragnaros_entrapping_roots_aura::HandleAuraRemoval, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

class spell_ragnaros_cloudburst: public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), static_cast<uint32>(GetEffectValue()));
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_ragnaros_cloudburst::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_ragnaros_dreadflame : public AuraScript
{
    void HandlePeriodic(AuraEffect const* aurEff)
    {
        Unit* target = GetTarget();

        _ticksUntilNextCast -= 1;
        if (_ticksUntilNextCast == 0)
        {
            InstanceScript* instance = target->GetInstanceScript();
            if (!instance)
                return;

            uint8 const castCount = target->GetMap()->Is25ManRaid() ? 5 : 2;
            if (Creature* creature = GetTarget()->ToCreature())
                if (CreatureAI* ai = creature->AI())
                    ai->SetData(DATA_CAST_DREADFLAMES, castCount);

            _ticksUntilNextCast = GetNextCastTickAmount(aurEff->GetTickNumber());
        }
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_ragnaros_dreadflame::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }

private:
    uint8 _ticksUntilNextCast = 1;

    uint8 GetNextCastTickAmount(uint32 tickNumber)
    {
        uint8 const baseValue = 9;
        uint8 const offset = std::min<uint32>(floor(tickNumber / 2), baseValue - 1);

        return baseValue - offset;
    }
};

class spell_ragnaros_dreadflame_control_aura_damage : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DREADFLAME_DAMAGE,
                SPELL_DREADFLAME_AREA_DUMMY_AURA
            });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject const* target)
        {
            Unit const* unitTarget = target->ToUnit();
            return (!unitTarget || !unitTarget->HasAura(SPELL_DREADFLAME_AREA_DUMMY_AURA));
        });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), SPELL_DREADFLAME_DAMAGE, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_ragnaros_dreadflame_control_aura_damage::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget.Register(&spell_ragnaros_dreadflame_control_aura_damage::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_ragnaros_dreadflame_control_aura_spawn : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DREADFLAME_AREA_DUMMY_AURA });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        Creature* creature = GetHitCreature();
        if (!creature)
            return;

        if (Unit* caster = GetCaster())
            caster->CastSpell(creature, SPELL_DREADFLAME_AREA_DUMMY_AURA, true);

        creature->DespawnOrUnsummon();
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_ragnaros_dreadflame_control_aura_spawn::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_ragnaros_dreadflame_control_aura_spread : public AuraScript
{
    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        if (Creature* creature = GetTarget()->ToCreature())
            if (CreatureAI* ai = creature->AI())
                ai->DoAction(ACTION_SPREAD_DREADFLAMES);
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_ragnaros_dreadflame_control_aura_spread::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class spell_ragnaros_dreadflame_control_aura_deluge : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DELUGE_TRIGGERED,
                SPELL_DREADFLAME_AREA_DUMMY_AURA
            });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (Aura const* aura = GetHitUnit()->GetAura(SPELL_DREADFLAME_AREA_DUMMY_AURA))
        {
            if (DynamicObject* dynObject = aura->GetDynobjOwner())
            {
                Position const& gridOriginPos = DreadflamePositionInfoData[0].Dest;
                float diffX = dynObject->GetPositionX() - gridOriginPos.GetPositionX();
                float diffY = dynObject->GetPositionY() - gridOriginPos.GetPositionY();

                uint16 index = static_cast<uint16>((diffX / 5.f) * 31 + (diffY / 5.f));
                if (Creature* creature = caster->ToCreature())
                    if (CreatureAI* ai = creature->AI())
                        ai->SetData(DATA_RELEASE_DREADFLAME_POSITION_INFO_INDEX, index);

                caster->CastSpell(dynObject->GetPosition(), SPELL_DELUGE_TRIGGERED);
                caster->RemoveAurasDueToSpell(SPELL_DREADFLAME_AREA_DUMMY_AURA, dynObject->GetGUID());
                dynObject->Remove(); // @todo: this should be handled by the deluge spell effect 177 but until then, we cancel it manually.
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_ragnaros_dreadflame_control_aura_deluge::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_ragnaros_breadth_of_frost_trigger: public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(nullptr, static_cast<uint32>(GetEffectValue()));
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_ragnaros_breadth_of_frost_trigger::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_ragnaros_breadth_of_frost: public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        target->RemoveAurasDueToSpell(sSpellMgr->GetSpellIdForDifficulty(static_cast<uint32>(GetEffectValue()), target));
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_ragnaros_breadth_of_frost::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_ragnaros_superheated : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BREADTH_OF_FROST_AURA });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject const* target)
        {
            return (!target->IsUnit() || target->ToUnit()->HasAura(SPELL_BREADTH_OF_FROST_AURA));
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_ragnaros_superheated::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnObjectAreaTargetSelect.Register(&spell_ragnaros_superheated::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

void AddSC_boss_ragnaros_firelands()
{
    RegisterFirelandsCreatureAI(boss_ragnaros_firelands);
    RegisterFirelandsCreatureAI(npc_ragnaros_son_of_flame);
    RegisterFirelandsCreatureAI(npc_ragnaros_lava_scion);
    RegisterFirelandsCreatureAI(npc_ragnaros_living_meteor);
    RegisterFirelandsCreatureAI(npc_ragnaros_archdruid);
    RegisterFirelandsCreatureAI(npc_ragnaros_dreadflame);
    RegisterFirelandsCreatureAI(npc_ragnaros_cloudburst);
    RegisterSpellScript(spell_ragnaros_wrath_of_ragnaros);
    RegisterSpellScript(spell_ragnaros_magma_trap);
    RegisterSpellScript(spell_ragnaros_magma_trap_periodic);
    RegisterSpellScript(spell_ragnaros_magma_trap_missile);
    RegisterSpellScript(spell_ragnaros_sulfuras_smash);
    RegisterSpellScript(spell_ragnaros_splitting_blow);
    RegisterSpellScript(spell_ragnaros_splitting_blow_script);
    RegisterSpellScript(spell_ragnaros_invoke_sons);
    RegisterSpellScript(spell_ragnaros_invoke_sons_script);
    RegisterSpellAndAuraScriptPair(spell_ragnaros_submerge, spell_ragnaros_submerge_AuraScript);
    RegisterSpellScript(spell_ragnaros_burning_speed);
    RegisterSpellScript(spell_ragnaros_molten_seed);
    RegisterSpellScript(spell_ragnaros_molten_seed_dummy);
    RegisterSpellScript(spell_ragnaros_molten_seed_visual);
    RegisterSpellScript(spell_ragnaros_engulfing_flames);
    RegisterSpellScript(spell_ragnaros_world_in_flames);
    RegisterSpellScript(spell_ragnaros_molten_inferno);
    RegisterSpellScript(spell_ragnaros_blazing_heat);
    RegisterSpellScript(spell_ragnaros_blazing_heat_script);
    RegisterSpellScript(spell_ragnaros_blazing_heat_aoe);
    RegisterSpellScript(spell_ragnaros_living_meteor);
    RegisterSpellScript(spell_ragnaros_living_meteor_aoe);
    RegisterSpellScript(spell_ragnaros_fixate);
    RegisterSpellScript(spell_ragnaros_combustible);
    RegisterSpellScript(spell_ragnaros_death);
    RegisterSpellScript(spell_ragnaros_burning_wound);
    RegisterSpellScript(spell_ragnaros_empowered_sulfuras);
    RegisterSpellScript(spell_ragnaros_empower_sulfuras);
    RegisterSpellScript(spell_ragnaros_empower_sulfuras_periodic);
    RegisterSpellScript(spell_ragnaros_entrapping_roots);
    RegisterSpellScript(spell_ragnaros_entrapping_roots_aura);
    RegisterSpellScript(spell_ragnaros_cloudburst);
    RegisterSpellScript(spell_ragnaros_dreadflame);
    RegisterSpellScript(spell_ragnaros_dreadflame_control_aura_damage);
    RegisterSpellScript(spell_ragnaros_dreadflame_control_aura_spawn);
    RegisterSpellScript(spell_ragnaros_dreadflame_control_aura_spread);
    RegisterSpellScript(spell_ragnaros_dreadflame_control_aura_deluge);
    RegisterSpellScript(spell_ragnaros_breadth_of_frost_trigger);
    RegisterSpellScript(spell_ragnaros_breadth_of_frost);
    RegisterSpellScript(spell_ragnaros_superheated);
}
