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
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "trial_of_the_crusader.h"
#include "Vehicle.h"

enum Yells
{
    // Gormok
    EMOTE_SNOBOLLED         = 0,

    // Acidmaw & Dreadscale
    EMOTE_ENRAGE            = 0,
    SAY_SPECIAL             = 1,

    // Icehowl
    EMOTE_TRAMPLE_ROAR     = 0,
    EMOTE_TRAMPLE_FAIL     = 1,
    EMOTE_TRAMPLE_ENRAGE   = 2
};

enum Model
{
    MODEL_ACIDMAW_STATIONARY     = 29815,
    MODEL_ACIDMAW_MOBILE         = 29816,
    MODEL_DREADSCALE_STATIONARY  = 26935,
    MODEL_DREADSCALE_MOBILE      = 24564
};

enum BossSpells
{
    // Gormok
    SPELL_IMPALE                = 66331,
    SPELL_STAGGERING_STOMP      = 66330,
    SPELL_TANKING_GORMOK        = 66415, // No idea what it does (SERVERSIDE spell)

    // Snobold
    SPELL_RISING_ANGER          = 66636,
    SPELL_SNOBOLLED             = 66406,
    SPELL_BATTER                = 66408,
    SPELL_FIRE_BOMB             = 66313,
    SPELL_HEAD_CRACK            = 66407,
    SPELL_JUMP_TO_HAND          = 66342,
    SPELL_RIDE_PLAYER           = 66245,
    SPELL_FIRE_BOMB_AURA        = 66318,

    // Acidmaw & Dreadscale Generic
    SPELL_SWEEP                 = 66794,
    SUMMON_SLIME_POOL           = 66883,
    SPELL_EMERGE                = 66947,
    SPELL_SUBMERGE              = 66948,
    SPELL_SUBMERGE_2            = 66936,
    SPELL_ENRAGE                = 68335,
    SPELL_GROUND_VISUAL_0       = 66969,
    SPELL_GROUND_VISUAL_1       = 68302,
    SPELL_HATE_TO_ZERO          = 63984,
    // Acidmaw
    SPELL_ACID_SPIT             = 66880,
    SPELL_PARALYTIC_SPRAY       = 66901,
    SPELL_PARALYTIC_BITE        = 66824,
    SPELL_ACID_SPEW             = 66818,
    SPELL_PARALYSIS             = 66830,
    SPELL_PARALYTIC_TOXIN       = 66823,
    // Dreadscale
    SPELL_BURNING_BITE          = 66879,
    SPELL_MOLTEN_SPEW           = 66821,
    SPELL_FIRE_SPIT             = 66796,
    SPELL_BURNING_SPRAY         = 66902,
    SPELL_BURNING_BILE          = 66869,

    // Slime Pool
    SPELL_SLIME_POOL_EFFECT     = 66882,
    SPELL_PACIFY_SELF           = 19951,

    // Icehowl
    SPELL_FEROCIOUS_BUTT        = 66770,
    SPELL_MASSIVE_CRASH         = 66683,
    SPELL_WHIRL                 = 67345,
    SPELL_ARCTIC_BREATH         = 66688,
    SPELL_TRAMPLE               = 66734,
    SPELL_FROTHING_RAGE         = 66759,
    SPELL_STAGGERED_DAZE        = 66758,
    SPELL_FURIOUS_CHARGE_SUMMON = 66729,
    SPELL_ROAR                  = 66736,
    SPELL_JUMP_BACK             = 66733,
    SPELL_SURGE_OF_ADRENALINE   = 68667,
    SPELL_BERSERK               = 26662
};

enum MyActions
{
    ACTION_ENABLE_FIRE_BOMB = 1,
    ACTION_DISABLE_FIRE_BOMB,
    ACTION_ACTIVE_SNOBOLD,
    ACTION_ENRAGE,
    ACTION_TRAMPLE_FAIL,
    ACTION_GORMOK_DEAD,
    ACTION_JORMUNGARS_DEAD
};

enum Events
{
    // Gormok
    EVENT_ENGAGE = 1,
    EVENT_IMPALE,
    EVENT_STAGGERING_STOMP,
    EVENT_THROW,

    // Snobold
    EVENT_FIRE_BOMB,
    EVENT_BATTER,
    EVENT_HEAD_CRACK,
    EVENT_SNOBOLLED,
    EVENT_CHECK_MOUNT,

    // Beasts Combat Stalker
    EVENT_BERSERK,
    EVENT_START_ICEHOWL,
    EVENT_START_JORGMUNGARS,

    // Acidmaw & Dreadscale
    EVENT_BITE,
    EVENT_SPEW,
    EVENT_SLIME_POOL,
    EVENT_SPRAY,
    EVENT_SWEEP,
    EVENT_SUBMERGE,
    EVENT_EMERGE,
    EVENT_SUMMON_ACIDMAW,

    // Icehowl
    EVENT_FEROCIOUS_BUTT,
    EVENT_MASSIVE_CRASH,
    EVENT_WHIRL,
    EVENT_ARCTIC_BREATH,
    EVENT_SELECT_CHARGE_TARGET,
    EVENT_ROAR_EMOTE,
    EVENT_ICEHOWL_ROAR,
    EVENT_JUMP_BACK,
    EVENT_TRAMPLE
};

enum Phases
{
    PHASE_EVENT = 1,
    PHASE_COMBAT,
    PHASE_MOBILE,
    PHASE_STATIONARY,
    PHASE_SUBMERGED,
    PHASE_CHARGE
};

enum NorthrendBeastsPoint
{
    POINT_INITIAL_MOVEMENT = 1,
    POINT_MIDDLE,
    POINT_ICEHOWL_CHARGE
};

enum Misc
{
    DATA_NEW_TARGET         = 1,
    GORMOK_HAND_SEAT        = 4,
    MAX_SNOBOLDS            = 4,
    SPLINE_INITIAL_MOVEMENT = 1
};

Position const CombatStalkerPosition = { 563.8941f, 137.3333f, 405.8467f };

class SnobolledTargetSelector
{
public:
    SnobolledTargetSelector() { }

    bool operator()(Unit* unit) const
    {
        return unit->GetTypeId() == TYPEID_PLAYER && !unit->HasAura(SPELL_RIDE_PLAYER) && !unit->HasAura(SPELL_SNOBOLLED);
    }
};

struct boss_northrend_beastsAI : public BossAI
{
    boss_northrend_beastsAI(Creature* creature, uint32 bossId) : BossAI(creature, bossId)
    {
        SetBoundary(instance->GetBossBoundary(DATA_NORTHREND_BEASTS));
    }

    void Reset() override
    {
        events.Reset();
        events.SetPhase(PHASE_EVENT);
        summons.DespawnAll();
        me->SetReactState(REACT_PASSIVE);
        me->SetCombatPulseDelay(0);
        HandleInitialMovement();
    }

    void HandleInitialMovement()
    {
        switch (me->GetEntry())
        {
            case NPC_GORMOK:
            case NPC_DREADSCALE:
                me->GetMotionMaster()->MoveAlongSplineChain(POINT_INITIAL_MOVEMENT, SPLINE_INITIAL_MOVEMENT, false);
                break;
            case NPC_ICEHOWL:
                me->GetMotionMaster()->MoveAlongSplineChain(POINT_INITIAL_MOVEMENT, SPLINE_INITIAL_MOVEMENT, true);
                break;
            default:
                break;
        }
    }

    void HandleWithHeroicEvents()
    {
        if (Creature* combatStalker = instance->GetCreature(DATA_BEASTS_COMBAT_STALKER))
        {
            if (me->GetEntry() == NPC_GORMOK)
                combatStalker->AI()->DoAction(ACTION_START_JORMUNGARS);
            else if (me->GetEntry() == NPC_DREADSCALE)
                combatStalker->AI()->DoAction(ACTION_START_ICEHOWL);
        }
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        me->SetCombatPulseDelay(5);
        me->setActive(true);
        ScheduleTasks();
        HandleInstanceProgress();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        if (IsHeroic())
            HandleWithHeroicEvents();
    }

    void HandleInstanceProgress()
    {
        switch (me->GetEntry())
        {
            case NPC_GORMOK:
                instance->SetData(TYPE_NORTHREND_BEASTS, GORMOK_IN_PROGRESS);
                break;
            case NPC_ACIDMAW:
            case NPC_DREADSCALE:
                if (instance->GetData(TYPE_NORTHREND_BEASTS) != SNAKES_IN_PROGRESS)
                    instance->SetData(TYPE_NORTHREND_BEASTS, SNAKES_IN_PROGRESS);
                break;
            case NPC_ICEHOWL:
                instance->SetData(TYPE_NORTHREND_BEASTS, ICEHOWL_IN_PROGRESS);
                break;
            default:
                break;
        }
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        ScriptedAI::EnterEvadeMode(why);
        instance->SetData(DATA_DESPAWN_SNOBOLDS, 0);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        // prevent losing 2 attempts at once on heroics
        if (instance->GetData(TYPE_NORTHREND_BEASTS) != FAIL)
            instance->SetData(TYPE_NORTHREND_BEASTS, FAIL);
        if (Creature* combatStalker = instance->GetCreature(DATA_BEASTS_COMBAT_STALKER))
            combatStalker->DespawnOrUnsummon();
        summons.DespawnAll();
        me->DespawnOrUnsummon();
    }

    void JustDied(Unit* /*killer*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        if (me->GetEntry() == NPC_GORMOK)
        {
            instance->SetData(TYPE_NORTHREND_BEASTS, GORMOK_DONE);
            if (Creature* combatStalker = instance->GetCreature(DATA_BEASTS_COMBAT_STALKER))
                combatStalker->AI()->DoAction(ACTION_GORMOK_DEAD);
        }
        else
            instance->SetData(TYPE_NORTHREND_BEASTS, ICEHOWL_DONE);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && !events.IsInPhase(PHASE_EVENT))
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            ExecuteEvent(eventId);
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
};

struct boss_gormok : public boss_northrend_beastsAI
{
    boss_gormok(Creature* creature) : boss_northrend_beastsAI(creature, DATA_GORMOK_THE_IMPALER) { }

    void ScheduleTasks() override
    {
        events.ScheduleEvent(EVENT_IMPALE, 10s);
        events.ScheduleEvent(EVENT_STAGGERING_STOMP, 15s);
        events.ScheduleEvent(EVENT_THROW, 20s);
    }

    void PassengerBoarded(Unit* who, int8 seatId, bool apply) override
    {
        if (apply && seatId == GORMOK_HAND_SEAT)
            who->CastSpell(who, SPELL_RISING_ANGER, true);
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type == SPLINE_CHAIN_MOTION_TYPE && pointId == POINT_INITIAL_MOVEMENT)
            events.ScheduleEvent(EVENT_ENGAGE, 7s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_ENGAGE:
                instance->DoUseDoorOrButton(instance->GetGuidData(DATA_MAIN_GATE));
                me->SetImmuneToPC(false);
                me->SetReactState(REACT_AGGRESSIVE);
                // Npc that should keep raid in combat while boss change
                if (Creature* combatStalker = me->SummonCreature(NPC_BEASTS_COMBAT_STALKER, CombatStalkerPosition))
                {
                    DoZoneInCombat(combatStalker);
                    combatStalker->SetCombatPulseDelay(5);
                }
                DoZoneInCombat();
                events.SetPhase(PHASE_COMBAT);
                DoCastSelf(SPELL_TANKING_GORMOK, true);
                break;
            case EVENT_IMPALE:
                DoCastVictim(SPELL_IMPALE);
                events.Repeat(10s);
                break;
            case EVENT_STAGGERING_STOMP:
                DoCastVictim(SPELL_STAGGERING_STOMP);
                events.Repeat(22s);
                break;
            case EVENT_THROW:
                for (uint8 i = 0; i < MAX_SNOBOLDS; ++i)
                {
                    if (Unit* snobold = me->GetVehicleKit()->GetPassenger(i))
                    {
                        snobold->ExitVehicle();
                        snobold->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        snobold->GetAI()->DoAction(ACTION_DISABLE_FIRE_BOMB);
                        snobold->CastSpell(me, SPELL_JUMP_TO_HAND, true);
                        break;
                    }
                }
                events.Repeat(20s);
                break;
            default:
                break;
        }
    }
};

struct npc_snobold_vassal : public ScriptedAI
{
    npc_snobold_vassal(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()), _mountedOnPlayer(false), _gormokDead(false)
    {
        _instance->SetData(DATA_SNOBOLD_COUNT, INCREASE);
        SetCombatMovement(false);
    }

    bool CanAIAttack(Unit const* who) const override
    {
        if (_mountedOnPlayer && who->GetGUID() != _targetGUID)
            return false;

        return ScriptedAI::CanAIAttack(who);
    }

    void AttackStart(Unit* victim) override
    {
        Creature* gormok = _instance->GetCreature(DATA_GORMOK_THE_IMPALER);
        if (!_mountedOnPlayer && (!gormok || !gormok->IsAlive()))
            AttackStartCaster(victim, 30.0f);
        else
            ScriptedAI::AttackStart(victim);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_CHECK_MOUNT, 3s);
        _events.ScheduleEvent(EVENT_FIRE_BOMB, 12s, 25s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _instance->SetData(DATA_SNOBOLD_COUNT, DECREASE);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_ENABLE_FIRE_BOMB:
                _events.ScheduleEvent(EVENT_FIRE_BOMB, 12s, 25s);
                break;
            case ACTION_DISABLE_FIRE_BOMB:
                _events.CancelEvent(EVENT_FIRE_BOMB);
                break;
            case ACTION_ACTIVE_SNOBOLD:
                _mountedOnPlayer = true;
                break;
            default:
                break;
        }
    }

    void SetGUID(ObjectGuid const& guid, int32 id) override
    {
        if (id == DATA_NEW_TARGET)
            if (Unit* target = ObjectAccessor::GetPlayer(*me, guid))
            {
                _targetGUID = guid;
                AttackStart(target);
                _events.ScheduleEvent(EVENT_BATTER, 5s);
                _events.ScheduleEvent(EVENT_SNOBOLLED, 1s);
                _events.ScheduleEvent(EVENT_HEAD_CRACK, 1s);
            }
    }

    void MountOnBoss()
    {
        Unit* gormok = _instance->GetCreature(DATA_GORMOK_THE_IMPALER);
        if (gormok && gormok->IsAlive())
        {
            me->AttackStop();
            _targetGUID.Clear();
            _mountedOnPlayer = false;
            _events.CancelEvent(EVENT_BATTER);
            _events.CancelEvent(EVENT_HEAD_CRACK);

            for (uint8 i = 0; i < MAX_SNOBOLDS; i++)
            {
                if (!gormok->GetVehicleKit()->GetPassenger(i))
                {
                    me->EnterVehicle(gormok, i);
                    DoAction(ACTION_ENABLE_FIRE_BOMB);
                    break;
                }
            }
        }
        else
        {
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            _events.CancelEvent(EVENT_CHECK_MOUNT);
            _events.CancelEvent(EVENT_FIRE_BOMB);
            me->AttackStop();
            SetCombatMovement(true);
            _gormokDead = true;
            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true))
            {
                AttackStart(target);
                me->GetMotionMaster()->MoveChase(target);
                _events.ScheduleEvent(EVENT_BATTER, 5s);
                _events.ScheduleEvent(EVENT_HEAD_CRACK, 1s);
            }
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
                case EVENT_FIRE_BOMB:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true))
                        me->CastSpell(target, SPELL_FIRE_BOMB);
                    _events.Repeat(20s, 30s);
                    break;
                case EVENT_HEAD_CRACK:
                    if (Unit* target = me->GetVehicleBase())
                        DoCast(target, SPELL_HEAD_CRACK);
                    else
                        DoCastVictim(SPELL_HEAD_CRACK);
                    _events.Repeat(30s);
                    break;
                case EVENT_BATTER:
                    if (Unit* target = me->GetVehicleBase())
                        DoCast(target, SPELL_BATTER);
                    else
                        DoCastVictim(SPELL_BATTER);
                    _events.Repeat(10s, 15s);
                    break;
                case EVENT_SNOBOLLED:
                    DoCastSelf(SPELL_SNOBOLLED);
                    break;
                case EVENT_CHECK_MOUNT:
                    if (!me->GetVehicleBase())
                        MountOnBoss();
                    _events.Repeat(3s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        // do melee attack only if is in player back or if gormok is dead.
        if (_mountedOnPlayer || _gormokDead)
            DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    InstanceScript* _instance;
    ObjectGuid _targetGUID;
    bool _mountedOnPlayer;
    bool _gormokDead;
};

struct npc_fire_bomb : public ScriptedAI
{
    npc_fire_bomb(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        DoCastSelf(SPELL_FIRE_BOMB_AURA);
    }
};

struct npc_beasts_combat_stalker : public ScriptedAI
{
    npc_beasts_combat_stalker(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        _events.ScheduleEvent(EVENT_BERSERK, IsHeroic() ? 9min : 15min);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_START_JORMUNGARS:
                _events.ScheduleEvent(EVENT_START_JORGMUNGARS, 2min + 30s);
                break;
            case ACTION_GORMOK_DEAD:
                _events.CancelEvent(EVENT_START_JORGMUNGARS);
                break;
            case ACTION_START_ICEHOWL:
                _events.ScheduleEvent(EVENT_START_ICEHOWL, 2min + 30s);
                break;
            case ACTION_JORMUNGARS_DEAD:
                _events.CancelEvent(EVENT_START_ICEHOWL);
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
                case EVENT_BERSERK:
                    if (Creature* gormok = _instance->GetCreature(DATA_GORMOK_THE_IMPALER))
                        gormok->CastSpell(gormok, SPELL_BERSERK, true);

                    if (Creature* dreadscale = _instance->GetCreature(DATA_DREADSCALE))
                        dreadscale->CastSpell(dreadscale, SPELL_BERSERK, true);

                    if (Creature* acidmaw = _instance->GetCreature(DATA_ACIDMAW))
                        acidmaw->CastSpell(acidmaw, SPELL_BERSERK, true);

                    if (Creature* icehowl = _instance->GetCreature(DATA_ICEHOWL))
                        icehowl->CastSpell(icehowl, SPELL_BERSERK, true);
                    break;
                case EVENT_START_JORGMUNGARS:
                    if (Creature* tirion = _instance->GetCreature(DATA_FORDRING))
                        tirion->AI()->DoAction(ACTION_START_JORMUNGARS);
                    break;
                case EVENT_START_ICEHOWL:
                    if (Creature* tirion = _instance->GetCreature(DATA_FORDRING))
                        tirion->AI()->DoAction(ACTION_START_ICEHOWL);
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

struct boss_jormungarAI : public boss_northrend_beastsAI
{
    boss_jormungarAI(Creature* creature, uint32 bossId) : boss_northrend_beastsAI(creature, bossId)
    {
        Initialize();
    }

    void Initialize()
    {
        otherWormEntry = 0;
        modelStationary = 0;
        modelMobile = 0;
        biteSpell = 0;
        spewSpell = 0;
        spitSpell = 0;
        spraySpell = 0;
        wasMobile = false;
    }

    void Reset() override
    {
        Initialize();
        boss_northrend_beastsAI::Reset();
    }

    void JustSummoned(Creature* summoned) override
    {
        if (summoned->GetEntry() == NPC_ACIDMAW)
            BossAI::JustSummoned(summoned);
        else
            summons.Summon(summoned);
    }

    void ScheduleTasks() override
    {
        if (events.IsInPhase(PHASE_STATIONARY))
        {
            events.ScheduleEvent(EVENT_SPRAY, me->GetEntry() == NPC_DREADSCALE ? 17s : 9s, 0, PHASE_STATIONARY);
            events.ScheduleEvent(EVENT_SWEEP, 16s, 0, PHASE_STATIONARY);
        }
        else
        {
            events.ScheduleEvent(EVENT_BITE, 5s, 0, PHASE_MOBILE);
            events.ScheduleEvent(EVENT_SPEW, 10s, 0, PHASE_MOBILE);
            events.ScheduleEvent(EVENT_SLIME_POOL, 14s, 0, PHASE_MOBILE);
        }

        events.ScheduleEvent(EVENT_SUBMERGE, 45s);
    }

    uint32 GetOtherWormData(uint32 wormEntry)
    {
        return wormEntry == NPC_ACIDMAW ? DATA_ACIDMAW : DATA_DREADSCALE;
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* otherWorm = instance->GetCreature(GetOtherWormData(otherWormEntry)))
        {
            if (!otherWorm->IsAlive())
            {
                instance->SetData(TYPE_NORTHREND_BEASTS, SNAKES_DONE);
                me->DespawnOrUnsummon();
                otherWorm->DespawnOrUnsummon();
                if (Creature* combatStalker = instance->GetCreature(DATA_BEASTS_COMBAT_STALKER))
                    combatStalker->AI()->DoAction(ACTION_JORMUNGARS_DEAD);
            }
            else
            {
                instance->SetData(TYPE_NORTHREND_BEASTS, SNAKES_SPECIAL);
                otherWorm->AI()->DoAction(ACTION_ENRAGE);
            }
        }
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_ENRAGE)
        {
            DoCastSelf(SPELL_ENRAGE, true);
            Talk(EMOTE_ENRAGE);
            if (events.IsInPhase(PHASE_SUBMERGED))
                events.RescheduleEvent(EVENT_EMERGE, 1ms);
        }
    }

    void Submerge()
    {
        me->SetReactState(REACT_PASSIVE);
        me->AttackStop();

        if (wasMobile)
        {
            me->HandleEmoteCommand(EMOTE_ONESHOT_SUBMERGE);
            DoCastSelf(SPELL_SUBMERGE);
            me->SetSpeedRate(MOVE_RUN, 8.0f);
            DoCastSelf(SPELL_GROUND_VISUAL_0, true);
            events.SetPhase(PHASE_SUBMERGED);
            events.ScheduleEvent(EVENT_EMERGE, 5s, 0, PHASE_SUBMERGED);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
        }
        else
        {
            me->HandleEmoteCommand(EMOTE_ONESHOT_SUBMERGE);
            DoCastSelf(SPELL_SUBMERGE_2);
            me->RemoveAurasDueToSpell(SPELL_GROUND_VISUAL_1);
            me->SetSpeedRate(MOVE_RUN, 1.1111f);
            DoCastSelf(SPELL_GROUND_VISUAL_0, true);
            events.SetPhase(PHASE_SUBMERGED);
            me->SetControlled(false, UNIT_STATE_ROOT);
            events.ScheduleEvent(EVENT_EMERGE, 6s, 0, PHASE_SUBMERGED);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
        }
        me->GetMotionMaster()->MovePoint(0, ToCCommonLoc[1].GetPositionX() + frand(-40.0f, 40.0f), ToCCommonLoc[1].GetPositionY() + frand(-40.0f, 40.0f), ToCCommonLoc[1].GetPositionZ() + me->GetCollisionHeight());
    }

    void Emerge()
    {
        me->UpdateSpeed(MOVE_RUN);
        uint32 submergeSpell = wasMobile ? SPELL_SUBMERGE : SPELL_SUBMERGE_2;
        me->RemoveAurasDueToSpell(submergeSpell);
        me->RemoveAurasDueToSpell(SPELL_GROUND_VISUAL_0);
        DoCastSelf(SPELL_EMERGE);
        DoCastAOE(SPELL_HATE_TO_ZERO, true);
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
        me->SetReactState(REACT_AGGRESSIVE);
        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
            AttackStart(target);

        // if the worm was mobile before submerging, make him stationary now
        if (wasMobile)
        {
            me->SetControlled(true, UNIT_STATE_ROOT);
            me->SetDisplayId(modelStationary);
            DoCastSelf(SPELL_GROUND_VISUAL_1, true);
            events.SetPhase(PHASE_STATIONARY);
        }
        else
        {
            if (Unit* target = me->GetVictim())
                me->GetMotionMaster()->MoveChase(target);
            me->SetDisplayId(modelMobile);
            events.SetPhase(PHASE_MOBILE);
        }
        wasMobile = !wasMobile;
        ScheduleTasks();
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_ENGAGE:
                if (me->GetEntry() == NPC_DREADSCALE)
                {
                    instance->DoCloseDoorOrButton(instance->GetGuidData(DATA_MAIN_GATE));
                    me->SetImmuneToPC(false);
                    events.SetPhase(PHASE_MOBILE);
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoZoneInCombat();
                    events.ScheduleEvent(EVENT_SUMMON_ACIDMAW, 1ms);
                }
                else
                {
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoZoneInCombat();
                }
                break;
            case EVENT_EMERGE:
                Emerge();
                break;
            case EVENT_SUBMERGE:
                Submerge();
                break;
            case EVENT_BITE:
                DoCastVictim(biteSpell);
                events.Repeat(15s);
                break;
            case EVENT_SPEW:
                DoCastAOE(spewSpell);
                events.Repeat(21s);
                break;
            case EVENT_SLIME_POOL:
                DoCastSelf(SUMMON_SLIME_POOL);
                events.Repeat(12s);
                break;
            case EVENT_SUMMON_ACIDMAW:
                me->SummonCreature(NPC_ACIDMAW, ToCCommonLoc[9]);
                break;
            case EVENT_SPRAY:
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, 0.0f, true))
                    DoCast(target, spraySpell);
                events.Repeat(21s);
                break;
            case EVENT_SWEEP:
                DoCastAOE(SPELL_SWEEP);
                events.Repeat(17s);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && !events.IsInPhase(PHASE_EVENT))
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            ExecuteEvent(eventId);
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        if (events.IsInPhase(PHASE_MOBILE))
            DoMeleeAttackIfReady();
        else
            DoCastVictim(spitSpell);
    }

    protected:
        uint32 otherWormEntry;
        uint32 modelStationary;
        uint32 modelMobile;
        uint32 biteSpell;
        uint32 spewSpell;
        uint32 spitSpell;
        uint32 spraySpell;
        bool wasMobile;
};

struct boss_dreadscale : public boss_jormungarAI
{
    boss_dreadscale(Creature* creature) : boss_jormungarAI(creature, DATA_DREADSCALE) { }

    void Reset() override
    {
        boss_northrend_beastsAI::Reset();
        biteSpell = SPELL_BURNING_BITE;
        spewSpell = SPELL_MOLTEN_SPEW;
        spitSpell = SPELL_FIRE_SPIT;
        spraySpell = SPELL_BURNING_SPRAY;
        modelStationary = MODEL_DREADSCALE_STATIONARY;
        modelMobile = MODEL_DREADSCALE_MOBILE;
        otherWormEntry = NPC_ACIDMAW;
        wasMobile = true;
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type == SPLINE_CHAIN_MOTION_TYPE && pointId == POINT_INITIAL_MOVEMENT)
            events.ScheduleEvent(EVENT_ENGAGE, 3s);
    }
};

struct boss_acidmaw : public boss_jormungarAI
{
    boss_acidmaw(Creature* creature) : boss_jormungarAI(creature, DATA_ACIDMAW) { }

    void Reset() override
    {
        boss_northrend_beastsAI::Reset();
        biteSpell = SPELL_PARALYTIC_BITE;
        spewSpell = SPELL_ACID_SPEW;
        spitSpell = SPELL_ACID_SPIT;
        spraySpell = SPELL_PARALYTIC_SPRAY;
        modelStationary = MODEL_ACIDMAW_STATIONARY;
        modelMobile = MODEL_ACIDMAW_MOBILE;
        otherWormEntry = NPC_DREADSCALE;
        events.SetPhase(PHASE_STATIONARY);
        wasMobile = false;
        me->SetControlled(true, UNIT_STATE_ROOT);
        DoCastSelf(SPELL_GROUND_VISUAL_1, true);
        events.ScheduleEvent(EVENT_ENGAGE, 3s);
    }
};

struct npc_jormungars_slime_pool : public ScriptedAI
{
    npc_jormungars_slime_pool(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->m_Events.AddEventAtOffset([this]()
        {
            DoCastSelf(SPELL_SLIME_POOL_EFFECT, true);
            DoCastSelf(SPELL_PACIFY_SELF, true);
        }, 1s);
    }
};

struct boss_icehowl : public boss_northrend_beastsAI
{
    boss_icehowl(Creature* creature) : boss_northrend_beastsAI(creature, DATA_ICEHOWL) { }

    void ScheduleTasks() override
    {
        events.ScheduleEvent(EVENT_FEROCIOUS_BUTT, 8s, 0, PHASE_COMBAT);
        events.ScheduleEvent(EVENT_ARCTIC_BREATH, 20s, 0, PHASE_COMBAT);
        events.ScheduleEvent(EVENT_WHIRL, 15s, 0, PHASE_COMBAT);
        events.ScheduleEvent(EVENT_MASSIVE_CRASH, 35s, 0, PHASE_COMBAT);
    }

    void RescheduleTasks()
    {
        events.ScheduleEvent(EVENT_FEROCIOUS_BUTT, 8s, 0, PHASE_COMBAT);
        events.ScheduleEvent(EVENT_ARCTIC_BREATH, 20s, 0, PHASE_COMBAT);
        events.ScheduleEvent(EVENT_WHIRL, 15s, 0, PHASE_COMBAT);
        events.ScheduleEvent(EVENT_MASSIVE_CRASH, 45s, 0, PHASE_COMBAT);
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE && type != SPLINE_CHAIN_MOTION_TYPE)
            return;

        switch (pointId)
        {
            case POINT_INITIAL_MOVEMENT:
                events.ScheduleEvent(EVENT_ENGAGE, 3s);
                break;
            case POINT_MIDDLE:
                DoCastSelf(SPELL_MASSIVE_CRASH);
                events.ScheduleEvent(EVENT_SELECT_CHARGE_TARGET, 4s);
                break;
            case POINT_ICEHOWL_CHARGE:
                events.Reset();
                events.SetPhase(PHASE_COMBAT);
                RescheduleTasks();
                me->SetReactState(REACT_AGGRESSIVE);
                DoCastSelf(SPELL_TRAMPLE);
                break;
            default:
                break;
        }
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_ENRAGE)
        {
            DoCastSelf(SPELL_FROTHING_RAGE, true);
            Talk(EMOTE_TRAMPLE_ENRAGE);
        }
        else if (action == ACTION_TRAMPLE_FAIL)
        {
            DoCastSelf(SPELL_STAGGERED_DAZE, true);
            Talk(EMOTE_TRAMPLE_FAIL);
            events.DelayEvents(15s);
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_ENGAGE:
                instance->DoCloseDoorOrButton(instance->GetGuidData(DATA_MAIN_GATE));
                me->SetImmuneToPC(false);
                events.SetPhase(PHASE_COMBAT);
                me->SetReactState(REACT_AGGRESSIVE);
                DoZoneInCombat();
                break;
            case EVENT_MASSIVE_CRASH:
                me->SetReactState(REACT_PASSIVE);
                me->AttackStop();
                events.SetPhase(PHASE_CHARGE);
                me->GetMotionMaster()->MoveJump(ToCCommonLoc[1], 20.0f, 20.0f, POINT_MIDDLE);
                break;
            case EVENT_SELECT_CHARGE_TARGET:
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true))
                {
                    DoCast(target, SPELL_FURIOUS_CHARGE_SUMMON, true);
                    me->SetTarget(target->GetGUID());
                    Talk(EMOTE_TRAMPLE_ROAR, target);
                    events.ScheduleEvent(EVENT_ICEHOWL_ROAR, 1s);
                }
                break;
            case EVENT_ICEHOWL_ROAR:
                if (Creature* stalker = instance->GetCreature(DATA_FURIOUS_CHARGE))
                    DoCast(stalker, SPELL_ROAR);
                events.ScheduleEvent(EVENT_JUMP_BACK, 3s, 0, PHASE_CHARGE);
                break;
            case EVENT_JUMP_BACK:
                if (Creature* stalker = instance->GetCreature(DATA_FURIOUS_CHARGE))
                    DoCast(stalker, SPELL_JUMP_BACK);
                events.ScheduleEvent(EVENT_TRAMPLE, 2s, 0, PHASE_CHARGE);
                break;
            case EVENT_TRAMPLE:
                if (Creature* stalker = instance->GetCreature(DATA_FURIOUS_CHARGE))
                    me->GetMotionMaster()->MoveCharge(stalker->GetPositionX(), stalker->GetPositionY(), stalker->GetPositionZ(), 42.0f, POINT_ICEHOWL_CHARGE);
                me->SetTarget(ObjectGuid::Empty);
                break;
            case EVENT_FEROCIOUS_BUTT:
                DoCastVictim(SPELL_FEROCIOUS_BUTT);
                events.Repeat(20s);
                break;
            case EVENT_ARCTIC_BREATH:
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true))
                    DoCast(target, SPELL_ARCTIC_BREATH);
                events.Repeat(24s);
                break;
            case EVENT_WHIRL:
                DoCastSelf(SPELL_WHIRL);
                events.Repeat(16s);
                break;
            default:
                break;
        }
    }
};

// 66342 - Jump to Hand
class spell_gormok_jump_to_hand : public AuraScript
{
    PrepareAuraScript(spell_gormok_jump_to_hand);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_RIDE_PLAYER });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster || caster->GetEntry() != NPC_SNOBOLD_VASSAL)
            return;

        if (Creature* gormok = GetTarget()->ToCreature())
            if (Unit* target = gormok->AI()->SelectTarget(SelectTargetMethod::Random, 0, SnobolledTargetSelector()))
            {
                gormok->AI()->Talk(EMOTE_SNOBOLLED);
                caster->GetAI()->DoAction(ACTION_ACTIVE_SNOBOLD);
                caster->CastSpell(target, SPELL_RIDE_PLAYER, true);
            }
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_gormok_jump_to_hand::OnRemove, EFFECT_0, SPELL_AURA_CONTROL_VEHICLE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 66245 - Ride Vehicle
class spell_gormok_ride_player : public AuraScript
{
    PrepareAuraScript(spell_gormok_ride_player);

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (target->GetTypeId() != TYPEID_PLAYER || !target->IsInWorld())
            return;

        if (Unit *caster = GetCaster())
            if (caster->IsAIEnabled())
                caster->GetAI()->SetGUID(target->GetGUID(), DATA_NEW_TARGET);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_gormok_ride_player::OnApply, EFFECT_0, SPELL_AURA_CONTROL_VEHICLE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 66406 - Snobolled!
class spell_gormok_snobolled : public AuraScript
{
    PrepareAuraScript(spell_gormok_snobolled);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_RIDE_PLAYER });
    }

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        if (!GetTarget()->HasAura(SPELL_RIDE_PLAYER))
            Remove();
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_gormok_snobolled::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 66823, 67618, 67619, 67620 - Paralytic Toxin
class spell_jormungars_paralytic_toxin : public AuraScript
{
    PrepareAuraScript(spell_jormungars_paralytic_toxin);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_PARALYSIS });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (caster && caster->GetEntry() == NPC_ACIDMAW)
            if (Creature* acidmaw = caster->ToCreature())
                acidmaw->AI()->Talk(SAY_SPECIAL, GetTarget());
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_PARALYSIS);
    }

    void CalculateAmount(AuraEffect const* aurEff, int32& amount, bool& canBeRecalculated)
    {
        if (!canBeRecalculated)
            amount = aurEff->GetAmount();

        canBeRecalculated = false;
    }

    void HandleDummy(AuraEffect const* /*aurEff*/)
    {
        if (AuraEffect* slowEff = GetEffect(EFFECT_0))
        {
            int32 newAmount = slowEff->GetAmount() - 10;
            if (newAmount < -100)
                newAmount = -100;
            slowEff->ChangeAmount(newAmount);

            if (newAmount == -100 && !GetTarget()->HasAura(SPELL_PARALYSIS))
                GetTarget()->CastSpell(GetTarget(), SPELL_PARALYSIS, CastSpellExtraArgs(slowEff).SetOriginalCaster(GetCasterGUID()));
        }
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_jormungars_paralytic_toxin::OnApply, EFFECT_0, SPELL_AURA_MOD_DECREASE_SPEED, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_jormungars_paralytic_toxin::OnRemove, EFFECT_0, SPELL_AURA_MOD_DECREASE_SPEED, AURA_EFFECT_HANDLE_REAL);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_jormungars_paralytic_toxin::CalculateAmount, EFFECT_0, SPELL_AURA_MOD_DECREASE_SPEED);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_jormungars_paralytic_toxin::HandleDummy, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 66870, 67621, 67622, 67623 - Burning Bile
class spell_jormungars_burning_bile : public SpellScript
{
    PrepareSpellScript(spell_jormungars_burning_bile);

    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        GetHitUnit()->RemoveAurasByType(SPELL_AURA_MOD_DECREASE_SPEED);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_jormungars_burning_bile::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 66882 - Slime Pool
class spell_jormungars_slime_pool : public AuraScript
{
    PrepareAuraScript(spell_jormungars_slime_pool);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->Effects[EFFECT_0].TriggerSpell });
    }

    void PeriodicTick(AuraEffect const* aurEff)
    {
        PreventDefaultAction();

        int32 const radius = static_cast<int32>(((aurEff->GetTickNumber() / 60.f) * 0.9f + 0.1f) * 10000.f * 2.f / 3.f);
        CastSpellExtraArgs args(aurEff);
        args.AddSpellMod(SPELLVALUE_RADIUS_MOD, radius);
        GetTarget()->CastSpell(nullptr, GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell, args);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_jormungars_slime_pool::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

/* 66869 - Burning Bile
   66823 - Paralytic Toxin */
class spell_jormungars_snakes_spray : public SpellScriptLoader
{
public:
    spell_jormungars_snakes_spray(char const* name, uint32 spellId) : SpellScriptLoader(name), _spellId(spellId) { }

    class spell_jormungars_snakes_spray_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_jormungars_snakes_spray_SpellScript);

    public:
        spell_jormungars_snakes_spray_SpellScript(uint32 spellId) : SpellScript(), _spellId(spellId) { }

    private:
        bool Validate(SpellInfo const* /*spell*/) override
        {
            return ValidateSpellInfo({ _spellId });
        }

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            GetCaster()->CastSpell(GetHitUnit(), _spellId, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_jormungars_snakes_spray_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
        uint32 _spellId;
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_jormungars_snakes_spray_SpellScript(_spellId);
    }

private:
    uint32 _spellId;
};

// 66830 - Paralysis
class spell_jormungars_paralysis : public AuraScript
{
    PrepareAuraScript(spell_jormungars_paralysis);

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            if (InstanceScript* instance = caster->GetInstanceScript())
                if (instance->GetBossState(DATA_NORTHREND_BEASTS) == IN_PROGRESS)
                    return;

        Remove();
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_jormungars_paralysis::OnApply, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

// 66688 - Arctic Breath
class spell_icehowl_arctic_breath : public SpellScript
{
    PrepareSpellScript(spell_icehowl_arctic_breath);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ static_cast<uint32>(spellInfo->Effects[EFFECT_0].CalcValue()) });
    }

    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        uint32 spellId = GetSpellInfo()->Effects[effIndex].CalcValue();
        GetCaster()->CastSpell(GetHitUnit(), spellId, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_icehowl_arctic_breath::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 66734 - Trample
class spell_icehowl_trample : public SpellScript
{
    PrepareSpellScript(spell_icehowl_trample);

    void CheckTargets(std::list<WorldObject*>& targets)
    {
        Creature* caster = GetCaster()->ToCreature();
        if (!caster || !caster->IsAIEnabled())
            return;

        if (targets.empty())
            caster->AI()->DoAction(ACTION_TRAMPLE_FAIL);
        else
            caster->AI()->DoAction(ACTION_ENRAGE);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_icehowl_trample::CheckTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// 66683 - Massive Crash
class spell_icehowl_massive_crash : public AuraScript
{
    PrepareAuraScript(spell_icehowl_massive_crash);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_SURGE_OF_ADRENALINE });
    }

    void HandleSpeed(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Player* target = GetTarget()->ToPlayer())
            if (target->GetRaidDifficulty() == RAID_DIFFICULTY_10MAN_HEROIC || target->GetRaidDifficulty() == RAID_DIFFICULTY_25MAN_HEROIC)
                target->CastSpell(target, SPELL_SURGE_OF_ADRENALINE, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_icehowl_massive_crash::HandleSpeed, EFFECT_2, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_northrend_beasts()
{
    RegisterTrialOfTheCrusaderCreatureAI(boss_gormok);
    RegisterTrialOfTheCrusaderCreatureAI(npc_snobold_vassal);
    RegisterTrialOfTheCrusaderCreatureAI(npc_beasts_combat_stalker);
    RegisterTrialOfTheCrusaderCreatureAI(boss_acidmaw);
    RegisterTrialOfTheCrusaderCreatureAI(boss_dreadscale);
    RegisterTrialOfTheCrusaderCreatureAI(npc_jormungars_slime_pool);
    RegisterTrialOfTheCrusaderCreatureAI(boss_icehowl);
    RegisterTrialOfTheCrusaderCreatureAI(npc_fire_bomb);

    RegisterSpellScript(spell_gormok_jump_to_hand);
    RegisterSpellScript(spell_gormok_ride_player);
    RegisterSpellScript(spell_gormok_snobolled);
    RegisterSpellScript(spell_jormungars_paralytic_toxin);
    RegisterSpellScript(spell_jormungars_burning_bile);
    RegisterSpellScript(spell_jormungars_slime_pool);
    new spell_jormungars_snakes_spray("spell_jormungars_burning_spray", SPELL_BURNING_BILE);
    new spell_jormungars_snakes_spray("spell_jormungars_paralytic_spray", SPELL_PARALYTIC_TOXIN);
    RegisterSpellScript(spell_jormungars_paralysis);
    RegisterSpellScript(spell_icehowl_arctic_breath);
    RegisterSpellScript(spell_icehowl_trample);
    RegisterSpellScript(spell_icehowl_massive_crash);
}
