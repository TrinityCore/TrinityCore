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
#include "DBCStores.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "MoveSplineInit.h"
#include "PassiveAI.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "ulduar.h"

enum Texts
{
    SAY_BRANN_ALGALON_INTRO_1       = 0,
    SAY_BRANN_ALGALON_INTRO_2       = 1,
    SAY_BRANN_ALGALON_OUTRO         = 2,

    SAY_ALGALON_INTRO_1             = 0,
    SAY_ALGALON_INTRO_2             = 1,
    SAY_ALGALON_INTRO_3             = 2,
    SAY_ALGALON_START_TIMER         = 3,
    SAY_ALGALON_AGGRO               = 4,
    SAY_ALGALON_COLLAPSING_STAR     = 5,
    EMOTE_ALGALON_COLLAPSING_STAR   = 6,
    SAY_ALGALON_BIG_BANG            = 7,
    EMOTE_ALGALON_BIG_BANG          = 8,
    SAY_ALGALON_ASCEND              = 9,
    EMOTE_ALGALON_COSMIC_SMASH      = 10,
    SAY_ALGALON_PHASE_TWO           = 11,
    SAY_ALGALON_OUTRO_1             = 12,
    SAY_ALGALON_OUTRO_2             = 13,
    SAY_ALGALON_OUTRO_3             = 14,
    SAY_ALGALON_OUTRO_4             = 15,
    SAY_ALGALON_OUTRO_5             = 16,
    SAY_ALGALON_DESPAWN_1           = 17,
    SAY_ALGALON_DESPAWN_2           = 18,
    SAY_ALGALON_DESPAWN_3           = 19,
    SAY_ALGALON_KILL                = 20,

    // Direct Sound
    ENGAGE_MUSIC_ID                 = 15878
};

enum Spells
{
    // Algalon the Observer
    SPELL_ARRIVAL                       = 64997,
    SPELL_RIDE_THE_LIGHTNING            = 64986,
    SPELL_SUMMON_AZEROTH                = 64994,
    SPELL_REORIGINATION                 = 64996,
    SPELL_SUPERMASSIVE_FAIL             = 65311,
    SPELL_QUANTUM_STRIKE                = 64395,
    SPELL_PHASE_PUNCH                   = 64412,
    SPELL_BIG_BANG                      = 64443,
    SPELL_ASCEND_TO_THE_HEAVENS         = 64487,
    SPELL_COSMIC_SMASH                  = 62301,
    SPELL_COSMIC_SMASH_TRIGGERED        = 62304,
    SPELL_COSMIC_SMASH_VISUAL_STATE     = 62300,
    SPELL_SELF_STUN                     = 65256,
    SPELL_KILL_CREDIT                   = 65184,
    SPELL_TELEPORT                      = 62940,

    // Algalon Stalker
    SPELL_TRIGGER_3_ADDS                = 62266,    // Triggers Living Constellation

    // Living Constellation
    SPELL_ARCANE_BARRAGE                = 64599,
    SPELL_DESPAWN_BLACK_HOLE            = 64391,

    // Collapsing Star
    SPELL_COLLAPSE                      = 62018,
    SPELL_BLACK_HOLE_SPAWN_VISUAL       = 62003,
    SPELL_SUMMON_BLACK_HOLE             = 62189,

    // Black Hole
    SPELL_BLACK_HOLE_TRIGGER            = 62185,
    SPELL_CONSTELLATION_PHASE_TRIGGER   = 65508,
    SPELL_CONSTELLATION_PHASE_EFFECT    = 65509,
    SPELL_BLACK_HOLE_EXPLOSION          = 64122,
    SPELL_SUMMON_VOID_ZONE_VISUAL       = 64470,
    SPELL_VOID_ZONE_VISUAL              = 64469,
    SPELL_BLACK_HOLE_CREDIT             = 65312,
    SPELL_BLACK_HOLE_DOT                = 62169,

    // Worm Hole
    SPELL_WORM_HOLE_TRIGGER             = 65251,
    SPELL_SUMMON_UNLEASHED_DARK_MATTER  = 64450
};

uint32 const PhasePunchAlphaId[5] = {64435, 64434, 64428, 64421, 64417};

enum Events
{
    // Celestial Planetarium Access
    EVENT_DESPAWN_CONSOLE = 1,

    // Brann Bronzebeard
    EVENT_BRANN_MOVE_INTRO,
    EVENT_BRANN_SAY_INTRO_1,
    EVENT_SUMMON_ALGALON,
    EVENT_BRANN_OUTRO_1,
    EVENT_BRANN_OUTRO_2,

    // Algalon the Observer
    EVENT_INTRO_1,
    EVENT_INTRO_2,
    EVENT_SUMMON_AZEROTH,
    EVENT_INTRO_3,
    EVENT_INTRO_FINISH,
    EVENT_START_COMBAT,
    EVENT_INTRO_TIMER_DONE,
    EVENT_QUANTUM_STRIKE,
    EVENT_PHASE_PUNCH,
    EVENT_SUMMON_COLLAPSING_STAR,
    EVENT_BIG_BANG,
    EVENT_RESUME_UPDATING,
    EVENT_ASCEND_TO_THE_HEAVENS,
    EVENT_EVADE,
    EVENT_COSMIC_SMASH,
    EVENT_UNLOCK_YELL,
    EVENT_OUTRO_START,
    EVENT_OUTRO_1,
    EVENT_OUTRO_2,
    EVENT_OUTRO_3,
    EVENT_OUTRO_4,
    EVENT_OUTRO_5,
    EVENT_OUTRO_6,
    EVENT_OUTRO_7,
    EVENT_OUTRO_8,
    EVENT_OUTRO_9,
    EVENT_OUTRO_10,
    EVENT_OUTRO_11,
    EVENT_DESPAWN_ALGALON_1,
    EVENT_DESPAWN_ALGALON_2,
    EVENT_DESPAWN_ALGALON_3,

    // Living Constellation
    EVENT_ARCANE_BARRAGE
};

enum Actions
{
    ACTION_START_INTRO = 0,
    ACTION_ACTIVATE_STAR,
    ACTION_BIG_BANG,
    ACTION_ASCEND,
    ACTION_OUTRO,
    ACTION_INTRO_2,
};

enum EncounterPhases
{
    PHASE_NORMAL = 0,
    PHASE_ROLE_PLAY,
    PHASE_BIG_BANG
};

enum AchievmentInfo
{
    EVENT_ID_SUPERMASSIVE_START = 21697,
    DATA_HAS_FED_ON_TEARS       = 30043005
};

enum AlgalonSplineMovements
{
    SPLINE_INITIAL_MOVE    = 1,
    SPLINE_ALGALON_ROOM    = 2,
    SPLINE_OUTRO_1         = 3,
    SPLINE_OUTRO_2         = 4,
    SPLINE_DESPAWN_INTRO_1 = 5
};

enum AlgalonMovePoints
{
    POINT_INITIAL_MOVE = 1,
    POINT_ALGALON_ROOM,
    POINT_DESPAWN,
    POINT_ALGALON_OUTRO
};

#define LIVING_CONSTELLATION_COUNT 11
Position const ConstellationPos[LIVING_CONSTELLATION_COUNT] =
{
    {1625.208f, -267.2771f, 446.4296f, 5.044002f},
    {1658.279f, -262.5490f, 441.9073f, 4.188790f},
    {1678.677f, -276.3280f, 427.7531f, 3.979351f},
    {1593.389f, -299.4325f, 432.4636f, 6.073746f},
    {1685.613f, -300.1219f, 443.2366f, 3.385939f},
    {1591.706f, -263.8201f, 441.4153f, 5.253441f},
    {1668.317f, -324.7676f, 457.9394f, 3.211406f},
    {1592.242f, -325.5323f, 446.9508f, 0.226893f},
    {1635.821f, -363.3442f, 424.3459f, 1.466077f},
    {1672.188f, -357.2484f, 436.7337f, 2.338741f},
    {1615.800f, -348.0065f, 442.9586f, 1.134464f}
};

#define COLLAPSING_STAR_COUNT 4
Position const CollapsingStarPos[COLLAPSING_STAR_COUNT] =
{
    {1649.438f, -319.8127f, 418.3941f, 1.082104f},
    {1647.005f, -288.6790f, 417.3955f, 3.490659f},
    {1622.451f, -321.1563f, 417.6188f, 4.677482f},
    {1615.060f, -291.6816f, 417.7796f, 3.490659f}
};

Position const BrannIntroSpawnPos = { 1677.363f, -162.3514f, 427.332f, 3.191144f };
Position const AlgalonSummonPos = { 1632.531f, -304.8516f, 450.1123f, 1.530165f };
Position const AlgalonLandPos = { 1632.668f, -302.7656f, 417.3211f, 1.530165f };
Position const AlgalonOutroPos = {1633.64f, -317.78f, 417.3211f, 0.0f};
Position const BrannOutroPos = { 1631.989f, -221.5439f, 418.4091f, 4.714909f };

class ActivateLivingConstellation : public BasicEvent
{
    public:
        ActivateLivingConstellation(Unit* owner) : _owner(owner), _instance(owner->GetInstanceScript()) { }

        bool Execute(uint64 execTime, uint32 /*diff*/) override
        {
            if (!_instance || _instance->GetBossState(BOSS_ALGALON) != IN_PROGRESS)
                return true;    // delete event

            _owner->CastSpell(nullptr, SPELL_TRIGGER_3_ADDS, TRIGGERED_FULL_MASK);
            _owner->m_Events.AddEvent(this, execTime + urand(45000, 50000));
            return false;
        }

    private:
        Unit* _owner;
        InstanceScript* _instance;
};

class CosmicSmashDamageEvent : public BasicEvent
{
    public:
        CosmicSmashDamageEvent(Unit* caster) : _caster(caster) { }

        bool Execute(uint64 /*execTime*/, uint32 /*diff*/) override
        {
            _caster->CastSpell(nullptr, SPELL_COSMIC_SMASH_TRIGGERED, TRIGGERED_FULL_MASK);
            return true;
        }

    private:
        Unit* _caster;
};

class SummonUnleashedDarkMatter : public BasicEvent
{
    public:
        SummonUnleashedDarkMatter(Unit* caster) : _caster(caster) { }

        bool Execute(uint64 execTime, uint32 /*diff*/) override
        {
            _caster->CastSpell(nullptr, SPELL_SUMMON_UNLEASHED_DARK_MATTER, TRIGGERED_FULL_MASK);
            _caster->m_Events.AddEvent(this, execTime + 30000);
            return false;
        }

    private:
        Unit* _caster;
};

struct boss_algalon_the_observer : public BossAI
{
    boss_algalon_the_observer(Creature* creature) : BossAI(creature, BOSS_ALGALON)
    {
        Initialize();
        _firstPull = true;
        _fedOnTears = false;
    }

    void Initialize()
    {
        _phaseTwo = false;
        _fightWon = false;
        _hasYelled = false;
    }

    void Reset() override
    {
        _Reset();
        me->SetReactState(REACT_PASSIVE);
        Initialize();
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_START_INTRO:
            {
                me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_INSTANTLY_APPEAR_MODEL);
                me->SetDisableGravity(true);
                DoCastSelf(SPELL_ARRIVAL, true);
                DoCastSelf(SPELL_RIDE_THE_LIGHTNING, true);
                me->SetHomePosition(AlgalonLandPos);

                Movement::MoveSplineInit init(me);
                init.MoveTo(AlgalonLandPos.GetPositionX(), AlgalonLandPos.GetPositionY(), AlgalonLandPos.GetPositionZ(), false);
                init.SetOrientationFixed(true);
                me->GetMotionMaster()->LaunchMoveSpline(std::move(init), 0, MOTION_PRIORITY_NORMAL, POINT_MOTION_TYPE);

                events.Reset();
                events.SetPhase(PHASE_ROLE_PLAY);
                events.ScheduleEvent(EVENT_INTRO_1, 3s + 500ms, 0, PHASE_ROLE_PLAY);
                break;
            }
            case ACTION_ASCEND:
                events.SetPhase(PHASE_BIG_BANG);
                events.CancelEvent(EVENT_RESUME_UPDATING);
                events.ScheduleEvent(EVENT_ASCEND_TO_THE_HEAVENS, 1s + 500ms);
                break;
            case EVENT_DESPAWN_ALGALON:
                events.Reset();
                events.SetPhase(PHASE_ROLE_PLAY);
                if (me->IsInCombat())
                    events.ScheduleEvent(EVENT_ASCEND_TO_THE_HEAVENS, 1);
                events.ScheduleEvent(EVENT_DESPAWN_ALGALON_1, 5s);
                events.ScheduleEvent(EVENT_DESPAWN_ALGALON_2, 17s);
                events.ScheduleEvent(EVENT_DESPAWN_ALGALON_3, 26s);
                me->DespawnOrUnsummon(34s);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetImmuneToNPC(true);
                break;
            case ACTION_INIT_ALGALON:
                _firstPull = false;
                me->SetImmuneToPC(false);
                break;
            default:
                break;
        }
    }

    uint32 GetData(uint32 type) const override
    {
        return type == DATA_HAS_FED_ON_TEARS ? _fedOnTears : 1;
    }

    void JustEngagedWith(Unit* who) override
    {
        uint32 introDelay = 0;
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        me->SetImmuneToNPC(true);
        events.Reset();
        events.SetPhase(PHASE_ROLE_PLAY);

        if (!_firstPull)
        {
            Talk(SAY_ALGALON_AGGRO);
            me->PlayDirectMusic(ENGAGE_MUSIC_ID);
            BossAI::JustEngagedWith(who);
            introDelay = 8000;
        }
        else
        {
            _firstPull = false;
            Talk(SAY_ALGALON_START_TIMER);
            me->InterruptNonMeleeSpells(false);
            me->setActive(true);
            me->SetFarVisible(true);
            DoZoneInCombat();
            introDelay = 26500;
            summons.DespawnEntry(NPC_AZEROTH);
            instance->SetData(EVENT_DESPAWN_ALGALON, 0);
            events.ScheduleEvent(EVENT_START_COMBAT, 16s);
        }

        events.ScheduleEvent(EVENT_INTRO_TIMER_DONE, introDelay);
        events.ScheduleEvent(EVENT_QUANTUM_STRIKE, 3500 + introDelay);
        events.ScheduleEvent(EVENT_PHASE_PUNCH, 15500 + introDelay);
        events.ScheduleEvent(EVENT_SUMMON_COLLAPSING_STAR, 18000 + introDelay);
        events.ScheduleEvent(EVENT_BIG_BANG, 90000 + introDelay);
        events.ScheduleEvent(EVENT_ASCEND_TO_THE_HEAVENS, 360000 + introDelay);
        events.ScheduleEvent(EVENT_COSMIC_SMASH, 25000 + introDelay);

        std::list<Creature*> stalkers;
        me->GetCreatureListWithEntryInGrid(stalkers, NPC_ALGALON_STALKER, 200.0f);
        for (std::list<Creature*>::iterator itr = stalkers.begin(); itr != stalkers.end(); ++itr)
            (*itr)->m_Events.KillAllEvents(true);
    }

    void MovementInform(uint32 movementType, uint32 pointId) override
    {
        if (movementType != POINT_MOTION_TYPE)
            return;

        if (pointId == POINT_ALGALON_OUTRO)
        {
            me->SetFacingTo(1.605703f);
            events.ScheduleEvent(EVENT_OUTRO_3, 1s);
        }
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);
        switch (summon->GetEntry())
        {
            case NPC_COLLAPSING_STAR:
                summon->SetReactState(REACT_PASSIVE);
                summon->GetMotionMaster()->MoveRandom(20.0f);
                summon->CastSpell(summon, SPELL_COLLAPSE, TRIGGERED_FULL_MASK);
                break;
            case NPC_ALGALON_VOID_ZONE_VISUAL_STALKER:
                summon->CastSpell(summon, SPELL_VOID_ZONE_VISUAL, TRIGGERED_FULL_MASK);
                break;
            case NPC_ALGALON_STALKER_ASTEROID_TARGET_01:
                summon->CastSpell(summon, SPELL_COSMIC_SMASH_VISUAL_STATE, TRIGGERED_FULL_MASK);
                break;
            case NPC_ALGALON_STALKER_ASTEROID_TARGET_02:
                summon->m_Events.AddEventAtOffset(new CosmicSmashDamageEvent(summon), 3s + 250ms);
                break;
            case NPC_WORM_HOLE:
                summon->SetReactState(REACT_PASSIVE);
                summon->CastSpell(summon, SPELL_WORM_HOLE_TRIGGER, TRIGGERED_FULL_MASK);
                summon->CastSpell(summon, SPELL_SUMMON_VOID_ZONE_VISUAL, TRIGGERED_FULL_MASK);
                break;
            case NPC_UNLEASHED_DARK_MATTER:
                DoZoneInCombat(summon);
                break;
            default:
                break;
        }
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        instance->SetBossState(BOSS_ALGALON, FAIL);
        BossAI::EnterEvadeMode(why);
        me->SetImmuneToPC(false);
        me->SetSheath(SHEATH_STATE_UNARMED);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (_fightWon)
        {
            damage = 0;
            return;
        }

        if (!_phaseTwo && me->HealthBelowPctDamaged(20, damage))
        {
            _phaseTwo = true;
            Talk(SAY_ALGALON_PHASE_TWO);
            summons.DespawnEntry(NPC_LIVING_CONSTELLATION);
            summons.DespawnEntry(NPC_COLLAPSING_STAR);
            summons.DespawnEntry(NPC_BLACK_HOLE);
            summons.DespawnEntry(NPC_ALGALON_VOID_ZONE_VISUAL_STALKER);
            events.CancelEvent(EVENT_SUMMON_COLLAPSING_STAR);
            std::list<Creature*> stalkers;
            me->GetCreatureListWithEntryInGrid(stalkers, NPC_ALGALON_STALKER, 200.0f);
            for (std::list<Creature*>::iterator itr = stalkers.begin(); itr != stalkers.end(); ++itr)
                (*itr)->m_Events.KillAllEvents(true);
            for (uint8 i = 0; i < COLLAPSING_STAR_COUNT; ++i)
                if (Creature* wormHole = DoSummon(NPC_WORM_HOLE, CollapsingStarPos[i], TEMPSUMMON_MANUAL_DESPAWN))
                    wormHole->m_Events.AddEventAtOffset(new SummonUnleashedDarkMatter(wormHole), i >= 2 ? 8s : 6s);
        }
        else if ((int32(me->GetHealth()) - int32(damage)) < CalculatePct<int32>(int32(me->GetMaxHealth()), 2.5f) && !_fightWon)
        {
            _fightWon = true;
            damage = 0;
            events.SetPhase(PHASE_ROLE_PLAY);
            me->SetReactState(REACT_PASSIVE);
            me->AttackStop();
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            DoCastSelf(SPELL_SELF_STUN);
            events.Reset();
            summons.DespawnAll();
            events.ScheduleEvent(EVENT_OUTRO_START, 1s + 500ms);
            events.ScheduleEvent(EVENT_OUTRO_1, 7s);
        }
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
        {
            _fedOnTears = true;
            if (!_hasYelled)
            {
                _hasYelled = true;
                events.ScheduleEvent(EVENT_UNLOCK_YELL, 1s);
                Talk(SAY_ALGALON_KILL);
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!(events.IsInPhase(PHASE_ROLE_PLAY) || events.IsInPhase(PHASE_BIG_BANG) || _fightWon) && !UpdateVictim())
            return;

        events.Update(diff);

        if (!events.IsInPhase(PHASE_ROLE_PLAY))
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_INTRO_1:
                    me->RemoveAurasDueToSpell(SPELL_RIDE_THE_LIGHTNING);
                    Talk(SAY_ALGALON_INTRO_1);
                    events.ScheduleEvent(EVENT_SUMMON_AZEROTH, 6s, 0, PHASE_ROLE_PLAY);
                    break;
                case EVENT_SUMMON_AZEROTH:
                    DoCastAOE(SPELL_SUMMON_AZEROTH, true);
                    if (Creature* azeroth = instance->GetCreature(DATA_AZEROTH))
                        if (TempSummon* summon = azeroth->ToTempSummon())
                            summon->SetTempSummonType(TEMPSUMMON_MANUAL_DESPAWN);
                    events.ScheduleEvent(EVENT_INTRO_2, 4s, 0, PHASE_ROLE_PLAY);
                    break;
                case EVENT_INTRO_2:
                    me->SetDisableGravity(false);
                    Talk(SAY_ALGALON_INTRO_2);
                    DoCastAOE(SPELL_REORIGINATION, true);
                    events.ScheduleEvent(EVENT_INTRO_3, 8s + 500ms, 0, PHASE_ROLE_PLAY);
                    break;
                case EVENT_INTRO_3:
                    Talk(SAY_ALGALON_INTRO_3);
                    events.ScheduleEvent(EVENT_INTRO_FINISH, 11s + 500ms, 0, PHASE_ROLE_PLAY);
                    break;
                case EVENT_INTRO_FINISH:
                    events.Reset();
                    me->SetImmuneToPC(false);
                    if (Creature* brann = instance->GetCreature(DATA_BRANN_BRONZEBEARD_ALG))
                        brann->AI()->DoAction(ACTION_INTRO_2);
                    break;
                case EVENT_START_COMBAT:
                    Talk(SAY_ALGALON_AGGRO);
                    me->PlayDirectMusic(ENGAGE_MUSIC_ID);
                    instance->SetBossState(BOSS_ALGALON, IN_PROGRESS);
                    break;
                case EVENT_INTRO_TIMER_DONE:
                {
                    events.SetPhase(PHASE_NORMAL);
                    me->SetSheath(SHEATH_STATE_MELEE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->SetImmuneToNPC(false);
                    me->SetReactState(REACT_DEFENSIVE);
                    DoCastAOE(SPELL_SUPERMASSIVE_FAIL, true);
                    //! Workaround for Creature::_IsTargetAcceptable returning false
                    //! for creatures that start combat in REACT_PASSIVE and UNIT_FLAG_NOT_SELECTABLE
                    //! causing them to immediately evade
                    if (!me->GetThreatManager().IsThreatListEmpty())
                        AttackStart(me->GetThreatManager().GetCurrentVictim());
                    for (uint8 i = 0; i < LIVING_CONSTELLATION_COUNT; ++i)
                        if (Creature* summon = DoSummon(NPC_LIVING_CONSTELLATION, ConstellationPos[i], 0, TEMPSUMMON_DEAD_DESPAWN))
                            summon->SetReactState(REACT_PASSIVE);

                    std::list<Creature*> stalkers;
                    me->GetCreatureListWithEntryInGrid(stalkers, NPC_ALGALON_STALKER, 200.0f);
                    if (!stalkers.empty())
                    {
                        Unit* stalker = Trinity::Containers::SelectRandomContainerElement(stalkers);
                        stalker->m_Events.AddEventAtOffset(new ActivateLivingConstellation(stalker), 45s, 50s);
                    }
                    break;
                }
                case EVENT_QUANTUM_STRIKE:
                    DoCastVictim(SPELL_QUANTUM_STRIKE);
                    events.Repeat(3s, 5s);
                    break;
                case EVENT_PHASE_PUNCH:
                    DoCastVictim(SPELL_PHASE_PUNCH);
                    events.Repeat(15s + 500ms);
                    break;
                case EVENT_SUMMON_COLLAPSING_STAR:
                    Talk(SAY_ALGALON_COLLAPSING_STAR);
                    Talk(EMOTE_ALGALON_COLLAPSING_STAR);
                    for (uint8 i = 0; i < COLLAPSING_STAR_COUNT; ++i)
                        me->SummonCreature(NPC_COLLAPSING_STAR, CollapsingStarPos[i], TEMPSUMMON_CORPSE_DESPAWN);
                    events.Repeat(1min);
                    break;
                case EVENT_BIG_BANG:
                {
                    Talk(SAY_ALGALON_BIG_BANG);
                    Talk(EMOTE_ALGALON_BIG_BANG);
                    events.SetPhase(PHASE_BIG_BANG);
                    std::list<Creature*> constellations;
                    me->GetCreatureListWithEntryInGrid(constellations, NPC_LIVING_CONSTELLATION, 200.0f);
                    for (std::list<Creature*>::iterator itr = constellations.begin(); itr != constellations.end(); ++itr)
                        (*itr)->AI()->DoAction(ACTION_BIG_BANG);
                    DoCastAOE(SPELL_BIG_BANG);
                    events.Repeat(1min + 30s + 500ms);
                    events.ScheduleEvent(EVENT_RESUME_UPDATING, 9s + 500ms);
                    break;
                }
                case EVENT_RESUME_UPDATING:
                    events.SetPhase(PHASE_NORMAL);
                    break;
                case EVENT_ASCEND_TO_THE_HEAVENS:
                    Talk(SAY_ALGALON_ASCEND);
                    DoCastAOE(SPELL_ASCEND_TO_THE_HEAVENS);
                    events.ScheduleEvent(EVENT_EVADE, 2s + 500ms);
                    break;
                case EVENT_EVADE:
                    EnterEvadeMode(EVADE_REASON_OTHER);
                    break;
                case EVENT_COSMIC_SMASH:
                    Talk(EMOTE_ALGALON_COSMIC_SMASH);
                    DoCastAOE(SPELL_COSMIC_SMASH);
                    events.Repeat(25s + 500ms);
                    break;
                case EVENT_UNLOCK_YELL:
                    _hasYelled = false;
                    break;
                case EVENT_OUTRO_START:
                    instance->SetBossState(BOSS_ALGALON, DONE);
                    break;
                case EVENT_OUTRO_1:
                    me->RemoveAllAuras();
                    ResetThreatList();
                    me->SetFaction(FACTION_FRIENDLY);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_RENAME);
                    events.ScheduleEvent(EVENT_OUTRO_2, 2s);
                    break;
                case EVENT_OUTRO_2:
                    me->SetRegenerateHealth(false);
                    me->CombatStop();
                    me->GetMotionMaster()->MovePoint(POINT_ALGALON_OUTRO, AlgalonOutroPos);
                    break;
                case EVENT_OUTRO_3:
                    DoCastAOE(SPELL_KILL_CREDIT);
                    events.ScheduleEvent(EVENT_OUTRO_4, 1s + 400ms);
                    events.ScheduleEvent(EVENT_OUTRO_5, 4s + 500ms);
                    break;
                case EVENT_OUTRO_4:
                    DoCastAOE(SPELL_SUPERMASSIVE_FAIL);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    break;
                case EVENT_OUTRO_5:
                    if (Creature* brann = me->SummonCreature(NPC_BRANN_BRONZBEARD_ALG, BrannOutroPos))
                        brann->AI()->DoAction(ACTION_OUTRO);
                    events.ScheduleEvent(EVENT_OUTRO_6, 10s);
                    break;
                case EVENT_OUTRO_6:
                    Talk(SAY_ALGALON_OUTRO_1);
                    me->SetStandState(UNIT_STAND_STATE_KNEEL);
                    events.ScheduleEvent(EVENT_OUTRO_7, 39s);
                    break;
                case EVENT_OUTRO_7:
                    Talk(SAY_ALGALON_OUTRO_2);
                    events.ScheduleEvent(EVENT_OUTRO_8, 18s);
                    break;
                case EVENT_OUTRO_8:
                    Talk(SAY_ALGALON_OUTRO_3);
                    events.ScheduleEvent(EVENT_OUTRO_9, 12s);
                    break;
                case EVENT_OUTRO_9:
                    Talk(SAY_ALGALON_OUTRO_4);
                    events.ScheduleEvent(EVENT_OUTRO_10, 24s);
                    break;
                case EVENT_OUTRO_10:
                    Talk(SAY_ALGALON_OUTRO_5);
                    events.ScheduleEvent(EVENT_OUTRO_11, 15s);
                    break;
                case EVENT_OUTRO_11:
                    me->SetStandState(UNIT_STAND_STATE_STAND);
                    DoCastSelf(SPELL_TELEPORT);
                    me->DespawnOrUnsummon(1s + 200ms);
                    break;
                case EVENT_DESPAWN_ALGALON_1:
                    Talk(SAY_ALGALON_DESPAWN_1);
                    break;
                case EVENT_DESPAWN_ALGALON_2:
                    Talk(SAY_ALGALON_DESPAWN_2);
                    break;
                case EVENT_DESPAWN_ALGALON_3:
                    Talk(SAY_ALGALON_DESPAWN_3);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING) && !events.IsInPhase(PHASE_ROLE_PLAY))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    bool _firstPull;
    bool _fedOnTears;
    bool _phaseTwo;
    bool _fightWon;
    bool _hasYelled;
};

struct npc_living_constellation : public CreatureAI
{
    npc_living_constellation(Creature* creature) : CreatureAI(creature), _instance(creature->GetInstanceScript())
    {
        Initialize();
    }

    void Initialize()
    {
        _isActive = false;
    }

    void Reset() override
    {
        _events.Reset();
        _events.ScheduleEvent(EVENT_ARCANE_BARRAGE, 2s + 500ms);
        Initialize();
    }

    uint32 GetData(uint32 /*type*/) const override
    {
        return _isActive ? 1 : 0;
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_ACTIVATE_STAR:
                if (Creature* algalon = _instance->GetCreature(BOSS_ALGALON))
                {
                    if (Unit* target = algalon->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(algalon)))
                    {
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        AttackStart(target);
                        DoZoneInCombat();
                        _isActive = true;
                    }
                }
                break;
            case ACTION_BIG_BANG:
                _events.SetPhase(PHASE_BIG_BANG);
                _events.DelayEvents(9s + 500ms);
                _events.ScheduleEvent(EVENT_RESUME_UPDATING, 9s + 500ms);
                break;
            default:
                break;
        }
    }

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        if (spell->Id != SPELL_CONSTELLATION_PHASE_EFFECT || caster->GetTypeId() != TYPEID_UNIT)
            return;

        _instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, EVENT_ID_SUPERMASSIVE_START);
        caster->CastSpell(nullptr, SPELL_BLACK_HOLE_CREDIT, TRIGGERED_FULL_MASK);
        DoCast(caster, SPELL_DESPAWN_BLACK_HOLE, TRIGGERED_FULL_MASK);
        me->DespawnOrUnsummon(500ms);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!(_events.IsInPhase(PHASE_ROLE_PLAY) || _events.IsInPhase(PHASE_BIG_BANG)) && !UpdateVictim())
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ARCANE_BARRAGE:
                {
                    DoCastAOE(SPELL_ARCANE_BARRAGE, { SPELLVALUE_MAX_TARGETS, 1 });
                    me->ClearUnitState(UNIT_STATE_CASTING);
                    _events.Repeat(4s, 5s);
                    break;
                }
                case EVENT_RESUME_UPDATING:
                    _events.SetPhase(PHASE_NORMAL);
                    break;
            }
        }
    }

private:
    EventMap _events;
    bool _isActive;
    InstanceScript* _instance;
};

struct npc_black_hole : public ScriptedAI
{
    npc_black_hole(Creature* creature) : ScriptedAI(creature), _summons(creature) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        DoCastAOE(SPELL_BLACK_HOLE_TRIGGER, TRIGGERED_FULL_MASK);
        DoCastSelf(SPELL_CONSTELLATION_PHASE_TRIGGER, TRIGGERED_FULL_MASK);
        DoCastAOE(SPELL_BLACK_HOLE_EXPLOSION, TRIGGERED_FULL_MASK);
        DoCastSelf(SPELL_SUMMON_VOID_ZONE_VISUAL, TRIGGERED_FULL_MASK);
    }

    void JustSummoned(Creature* summon) override
    {
        _summons.Summon(summon);
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_DESPAWN_BLACK_HOLE)
        {
            _summons.DespawnAll();
            me->DespawnOrUnsummon(1);
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override { }

private:
    SummonList _summons;
};

struct npc_collapsing_star : public PassiveAI
{
    npc_collapsing_star(Creature* creature) : PassiveAI(creature), _dying(false), _instance(creature->GetInstanceScript()) { }

    void JustSummoned(Creature* summon) override
    {
        if (summon->GetEntry() != NPC_BLACK_HOLE)
            return;

        if (Creature* algalon = _instance->GetCreature(BOSS_ALGALON))
            algalon->AI()->JustSummoned(summon);

        me->DespawnOrUnsummon(1);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (_dying)
        {
            damage = 0;
            return;
        }

        if (damage >= me->GetHealth())
        {
            _dying = true;
            damage = 0;
            DoCastSelf(SPELL_BLACK_HOLE_SPAWN_VISUAL, true);
            DoCastSelf(SPELL_SUMMON_BLACK_HOLE, true);
        }
    }

private:
    bool _dying;
    InstanceScript* _instance;
};

struct npc_brann_bronzebeard_algalon : public CreatureAI
{
    npc_brann_bronzebeard_algalon(Creature* creature) : CreatureAI(creature) { }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_START_INTRO:
                _events.Reset();
                me->GetMotionMaster()->MoveAlongSplineChain(POINT_INITIAL_MOVE, SPLINE_INITIAL_MOVE, false);
                break;
            case ACTION_OUTRO:
                me->GetMotionMaster()->MoveAlongSplineChain(0, SPLINE_OUTRO_1, false);
                _events.ScheduleEvent(EVENT_BRANN_OUTRO_1, 1min + 32s + 200ms);
                _events.ScheduleEvent(EVENT_BRANN_OUTRO_2, 2min);
                break;
            case ACTION_INTRO_2:
                Talk(SAY_BRANN_ALGALON_INTRO_2);
                me->GetMotionMaster()->MoveAlongSplineChain(POINT_DESPAWN, SPLINE_DESPAWN_INTRO_1, true);
                break;
            default:
                break;
        }
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE && type != SPLINE_CHAIN_MOTION_TYPE)
            return;

        switch (pointId)
        {
            case POINT_INITIAL_MOVE:
                _events.ScheduleEvent(EVENT_BRANN_MOVE_INTRO, 4s);
                break;
            case POINT_ALGALON_ROOM:
                me->SetFacingTo(4.714909f);
                _events.ScheduleEvent(EVENT_BRANN_SAY_INTRO_1, 500ms);
                break;
            case POINT_DESPAWN:
                me->DespawnOrUnsummon();
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (_events.Empty())
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_BRANN_MOVE_INTRO:
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_ALGALON_ROOM, SPLINE_ALGALON_ROOM, true);
                    break;
                case EVENT_BRANN_SAY_INTRO_1:
                    Talk(SAY_BRANN_ALGALON_INTRO_1);
                    _events.ScheduleEvent(EVENT_SUMMON_ALGALON, 8s + 300ms);
                    break;
                case EVENT_SUMMON_ALGALON:
                    if (Creature* algalon = me->GetMap()->SummonCreature(NPC_ALGALON, AlgalonSummonPos))
                        algalon->AI()->DoAction(ACTION_START_INTRO);
                    break;
                case EVENT_BRANN_OUTRO_1:
                    Talk(SAY_BRANN_ALGALON_OUTRO);
                    break;
                case EVENT_BRANN_OUTRO_2:
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_DESPAWN, SPLINE_OUTRO_2, false);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

struct go_celestial_planetarium_access : public GameObjectAI
{
    go_celestial_planetarium_access(GameObject* go) : GameObjectAI(go), _instance(go->GetInstanceScript()) { }

    bool OnReportUse(Player* player) override
    {
        if (me->HasFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE))
            return true;

        bool hasKey = true;
        if (LockEntry const* lock = sLockStore.LookupEntry(me->GetGOInfo()->goober.lockId))
        {
            hasKey = false;
            for (uint8 i = 0; i < MAX_LOCK_CASE; ++i)
            {
                if (!lock->Index[i])
                    continue;

                if (player->HasItemCount(lock->Index[i]))
                {
                    hasKey = true;
                    break;
                }
            }
        }

        if (!hasKey)
            return false;

        // Start Algalon event
        me->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
        _events.ScheduleEvent(EVENT_DESPAWN_CONSOLE, 5s);
        if (Creature* brann = me->SummonCreature(NPC_BRANN_BRONZBEARD_ALG, BrannIntroSpawnPos))
            brann->AI()->DoAction(ACTION_START_INTRO);

        _instance->SetData(DATA_ALGALON_SUMMON_STATE, 1);
        if (GameObject* sigil = _instance->GetGameObject(DATA_SIGILDOOR_01))
            sigil->SetGoState(GO_STATE_ACTIVE);

        if (GameObject* sigil = _instance->GetGameObject(DATA_SIGILDOOR_02))
            sigil->SetGoState(GO_STATE_ACTIVE);

        return false;
    }

    void UpdateAI(uint32 diff) override
    {
        if (_events.Empty())
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_DESPAWN_CONSOLE:
                    me->Delete();
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

//  64412 - Phase Punch
class spell_algalon_phase_punch : public AuraScript
{
    PrepareAuraScript(spell_algalon_phase_punch);

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        if (GetStackAmount() != 1)
            GetTarget()->RemoveAurasDueToSpell(PhasePunchAlphaId[GetStackAmount() - 2]);
        GetTarget()->CastSpell(GetTarget(), PhasePunchAlphaId[GetStackAmount() - 1], TRIGGERED_FULL_MASK);
        if (GetStackAmount() == 5)
            Remove(AURA_REMOVE_BY_DEFAULT);
    }

    void OnRemove(AuraEffect const*, AuraEffectHandleModes)
    {
        if (GetStackAmount() != 5)
            GetTarget()->RemoveAurasDueToSpell(PhasePunchAlphaId[GetStackAmount() - 1]);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_algalon_phase_punch::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        OnEffectRemove += AuraEffectRemoveFn(spell_algalon_phase_punch::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

//  65508 - Constellation Phase Trigger
class spell_algalon_phase_constellation : public AuraScript
{
    PrepareAuraScript(spell_algalon_phase_constellation);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->Effects[EFFECT_0].TriggerSpell });
    }

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        PreventDefaultAction();
        CastSpellExtraArgs args(aurEff);
        args.AddSpellMod(SPELLVALUE_MAX_TARGETS, 1);
        // Phase Effect should only 1 target. Avoid 1 black hole despawn multiple Living Constellation
        GetTarget()->CastSpell(nullptr, GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, args);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_algalon_phase_constellation::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 62266 - Trigger 3 Adds
class spell_algalon_trigger_3_adds : public SpellScript
{
    PrepareSpellScript(spell_algalon_trigger_3_adds);

    void SelectTarget(std::list<WorldObject*>& targets)
    {
        // Remove Living Constellation already actived
        targets.remove_if([](WorldObject* target) -> bool
        {
            return target->ToUnit() && target->ToUnit()->GetAI() && target->ToUnit()->GetAI()->GetData(0);
        });
    }

    void HandleDummy(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        if (Creature* target = GetHitCreature())
            target->AI()->DoAction(ACTION_ACTIVATE_STAR);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_algalon_trigger_3_adds::SelectTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_algalon_trigger_3_adds::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

//  62018 - Collapse
class spell_algalon_collapse : public AuraScript
{
    PrepareAuraScript(spell_algalon_collapse);

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        Unit::DealDamage(GetTarget(), GetTarget(), GetTarget()->CountPctFromMaxHealth(1), nullptr, NODAMAGE);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_algalon_collapse::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 64443, 64584 - Big Bang
class spell_algalon_big_bang : public SpellScript
{
    PrepareSpellScript(spell_algalon_big_bang);

    bool Load() override
    {
        _targetCount = 0;
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    void CountTargets(std::list<WorldObject*>& targets)
    {
        _targetCount = targets.size();
    }

    void CheckTargets()
    {
        if (!_targetCount)
            GetCaster()->GetAI()->DoAction(ACTION_ASCEND);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_algalon_big_bang::CountTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        AfterCast += SpellCastFn(spell_algalon_big_bang::CheckTargets);
    }
private:
    uint32 _targetCount = 0;
};

// 64445 - Remove Player from Phase
class spell_algalon_remove_phase : public AuraScript
{
    PrepareAuraScript(spell_algalon_remove_phase);

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        GetTarget()->RemoveAurasByType(SPELL_AURA_PHASE);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_algalon_remove_phase::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 62295 - Cosmic Smash
class spell_algalon_cosmic_smash : public SpellScript
{
    PrepareSpellScript(spell_algalon_cosmic_smash);

    void ModDestHeight(SpellDestination& dest)
    {
        // Meteor should spawn below the platform
        Position const offset = { 0.0f, 0.0f, -36.1325f, 0.0f };
        dest.RelocateOffset(offset);
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_algalon_cosmic_smash::ModDestHeight, EFFECT_0, TARGET_DEST_CASTER_SUMMON);
    }
};

// 62311, 64596 - Cosmic Smash
class spell_algalon_cosmic_smash_damage : public SpellScript
{
    PrepareSpellScript(spell_algalon_cosmic_smash_damage);

    void RecalculateDamage()
    {
        if (!GetExplTargetDest() || !GetHitUnit())
            return;

        float distance = GetHitUnit()->GetDistance2d(GetExplTargetDest()->GetPositionX(), GetExplTargetDest()->GetPositionY());
        if (distance > 6.0f)
            SetHitDamage(int32(float(GetHitDamage()) / distance) * 2);
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_algalon_cosmic_smash_damage::RecalculateDamage);
    }
};

// 65311 - Supermassive Fail
class spell_algalon_supermassive_fail : public SpellScript
{
    PrepareSpellScript(spell_algalon_supermassive_fail);

    void RecalculateDamage()
    {
        if (Player* player = GetHitPlayer())
            player->ResetAchievementCriteria(ACHIEVEMENT_CRITERIA_CONDITION_NO_SPELL_HIT, GetSpellInfo()->Id, true);
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_algalon_supermassive_fail::RecalculateDamage);
    }
};

// 62168 - Black Hole (Phase Shifts)
// 65250 - Worm Hole (Phase Shifts)
// 64417 - Phase Punch (Phase Shifts)
class spell_algalon_black_hole_phase_shifts : public AuraScript
{
    PrepareAuraScript(spell_algalon_black_hole_phase_shifts);

    bool Load() override
    {
        return GetUnitOwner()->GetTypeId() == TYPEID_PLAYER;
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BLACK_HOLE_DOT });
    }

    void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_BLACK_HOLE_DOT, true);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_algalon_black_hole_phase_shifts::HandleEffectApply, EFFECT_0, SPELL_AURA_PHASE, AURA_EFFECT_HANDLE_REAL);
    }
};

class achievement_he_feeds_on_your_tears : public AchievementCriteriaScript
{
    public:
        achievement_he_feeds_on_your_tears() : AchievementCriteriaScript("achievement_he_feeds_on_your_tears") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            return !target->GetAI()->GetData(DATA_HAS_FED_ON_TEARS);
        }
};

void AddSC_boss_algalon_the_observer()
{
    RegisterUlduarCreatureAI(boss_algalon_the_observer);
    RegisterUlduarCreatureAI(npc_living_constellation);
    RegisterUlduarCreatureAI(npc_black_hole);
    RegisterUlduarCreatureAI(npc_collapsing_star);
    RegisterUlduarCreatureAI(npc_brann_bronzebeard_algalon);
    RegisterGameObjectAI(go_celestial_planetarium_access);
    RegisterAuraScript(spell_algalon_phase_punch);
    RegisterAuraScript(spell_algalon_phase_constellation);
    RegisterSpellScript(spell_algalon_trigger_3_adds);
    RegisterAuraScript(spell_algalon_collapse);
    RegisterSpellScript(spell_algalon_big_bang);
    RegisterAuraScript(spell_algalon_remove_phase);
    RegisterSpellScript(spell_algalon_cosmic_smash);
    RegisterSpellScript(spell_algalon_cosmic_smash_damage);
    RegisterSpellScript(spell_algalon_supermassive_fail);
    RegisterAuraScript(spell_algalon_black_hole_phase_shifts);
    new achievement_he_feeds_on_your_tears();
}
