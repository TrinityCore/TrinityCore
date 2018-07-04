/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2006-2010 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
#include "SpellScript.h"
#include "SpellAuraEffects.h"
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
    EMOTE_TRAMPLE_START     = 0,
    EMOTE_TRAMPLE_CRASH     = 1,
    EMOTE_TRAMPLE_FAIL      = 2
};

enum Equipment
{
    EQUIP_MAIN           = 50760,
    EQUIP_OFFHAND        = 48040,
    EQUIP_RANGED         = 47267,
    EQUIP_DONE           = EQUIP_NO_CHANGE
};

enum Model
{
    MODEL_ACIDMAW_STATIONARY     = 29815,
    MODEL_ACIDMAW_MOBILE         = 29816,
    MODEL_DREADSCALE_STATIONARY  = 26935,
    MODEL_DREADSCALE_MOBILE      = 24564
};

enum BeastSummons
{
    NPC_SNOBOLD_VASSAL   = 34800,
    NPC_FIRE_BOMB        = 34854,
    NPC_SLIME_POOL       = 35176,
    MAX_SNOBOLDS         = 4
};

enum BossSpells
{
    //Gormok
    SPELL_IMPALE            = 66331,
    SPELL_STAGGERING_STOMP  = 67648,
    //Snobold
    SPELL_RISING_ANGER      = 66636,
    SPELL_SNOBOLLED         = 66406,
    SPELL_BATTER            = 66408,
    SPELL_FIRE_BOMB         = 66313,
    SPELL_FIRE_BOMB_1       = 66317,
    SPELL_FIRE_BOMB_DOT     = 66318,
    SPELL_HEAD_CRACK        = 66407,
    SPELL_JUMP_TO_HAND      = 66342,
    SPELL_RIDE_PLAYER       = 66245,

    //Acidmaw & Dreadscale Generic
    SPELL_SWEEP             = 66794,
    SUMMON_SLIME_POOL       = 66883,
    SPELL_EMERGE            = 66947,
    SPELL_SUBMERGE          = 66948,
    SPELL_ENRAGE            = 68335,
    SPELL_SLIME_POOL_EFFECT = 66882, //In 60s it diameter grows from 10y to 40y (r=r+0.25 per second)
    SPELL_GROUND_VISUAL_0   = 66969,
    SPELL_GROUND_VISUAL_1   = 68302,
    SPELL_HATE_TO_ZERO      = 63984,
    //Acidmaw
    SPELL_ACID_SPIT         = 66880,
    SPELL_PARALYTIC_SPRAY   = 66901,
    SPELL_PARALYTIC_BITE    = 66824, //Paralytic Toxin
    SPELL_ACID_SPEW         = 66818,
    SPELL_PARALYSIS         = 66830,
    SPELL_PARALYTIC_TOXIN   = 66823,
    //Dreadscale
    SPELL_BURNING_BITE      = 66879, // Burning Bile
    SPELL_MOLTEN_SPEW       = 66821,
    SPELL_FIRE_SPIT         = 66796,
    SPELL_BURNING_SPRAY     = 66902,
    SPELL_BURNING_BILE      = 66869,

    //Icehowl
    SPELL_FEROCIOUS_BUTT    = 66770,
    SPELL_MASSIVE_CRASH     = 66683,
    SPELL_WHIRL             = 67345,
    SPELL_ARCTIC_BREATH     = 66689,
    SPELL_TRAMPLE           = 66734,
    SPELL_FROTHING_RAGE     = 66759,
    SPELL_STAGGERED_DAZE    = 66758
};

enum MyActions
{
    ACTION_ENABLE_FIRE_BOMB     = 1,
    ACTION_DISABLE_FIRE_BOMB    = 2,
    ACTION_ACTIVE_SNOBOLD       = 3
};

enum Events
{
    // Gormok
    EVENT_IMPALE                = 1,
    EVENT_STAGGERING_STOMP,
    EVENT_THROW,

    // Snobold
    EVENT_FIRE_BOMB,
    EVENT_BATTER,
    EVENT_HEAD_CRACK,
    EVENT_SNOBOLLED,
    EVENT_CHECK_MOUNT,

    // Acidmaw & Dreadscale
    EVENT_BITE,
    EVENT_SPEW,
    EVENT_SLIME_POOL,
    EVENT_SPIT,
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
    EVENT_TRAMPLE
};

enum Phases
{
    PHASE_MOBILE            = 1,
    PHASE_STATIONARY        = 2,
    PHASE_SUBMERGED         = 3
};

enum GormokMisc
{
    DATA_NEW_TARGET         =   1,
    GORMOK_HAND_SEAT        =   4,
    PLAYER_VEHICLE_ID       = 444,
};

class boss_gormok : public CreatureScript
{
    public:
        boss_gormok() : CreatureScript("boss_gormok") { }

        struct boss_gormokAI : public BossAI
        {
            boss_gormokAI(Creature* creature) : BossAI(creature, BOSS_BEASTS) { }

            void Reset() override
            {
                events.ScheduleEvent(EVENT_IMPALE, Seconds(8), Seconds(10));
                events.ScheduleEvent(EVENT_STAGGERING_STOMP, Seconds(15));
                events.ScheduleEvent(EVENT_THROW, Seconds(15), Seconds(30));

                summons.DespawnAll();
            }

            void EnterEvadeMode(EvadeReason why) override
            {
                instance->DoUseDoorOrButton(instance->GetGuidData(GO_MAIN_GATE_DOOR));
                ScriptedAI::EnterEvadeMode(why);
            }

            void MovementInform(uint32 type, uint32 pointId) override
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                switch (pointId)
                {
                    case 0:
                        instance->DoUseDoorOrButton(instance->GetGuidData(GO_MAIN_GATE_DOOR));
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC);
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->SetInCombatWithZone();
                        break;
                    default:
                        break;
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                instance->SetData(TYPE_NORTHREND_BEASTS, GORMOK_DONE);
            }

            void JustReachedHome() override
            {
                instance->DoUseDoorOrButton(instance->GetGuidData(GO_MAIN_GATE_DOOR));
                instance->SetData(TYPE_NORTHREND_BEASTS, FAIL);

                me->DespawnOrUnsummon();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                instance->SetData(TYPE_NORTHREND_BEASTS, GORMOK_IN_PROGRESS);
            }

            void DamageTaken(Unit* /*who*/, uint32& damage) override
            {
                // despawn the remaining passengers on death
                if (damage >= me->GetHealth())
                    for (uint8 i = 0; i < MAX_SNOBOLDS; ++i)
                        if (Unit* snobold = me->GetVehicleKit()->GetPassenger(i))
                            snobold->ToCreature()->DespawnOrUnsummon();
            }

            void PassengerBoarded(Unit* who, int8 seatId, bool apply) override
            {
                if (apply && seatId == GORMOK_HAND_SEAT)
                    who->CastSpell(me, SPELL_RISING_ANGER, true);
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
                        case EVENT_IMPALE:
                            DoCastVictim(SPELL_IMPALE);
                            events.Repeat(Seconds(8), Seconds(10));
                            break;
                        case EVENT_STAGGERING_STOMP:
                            DoCastVictim(SPELL_STAGGERING_STOMP);
                            events.Repeat(Seconds(15));
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
                            events.Repeat(Seconds(15), Seconds(30));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTrialOfTheCrusaderAI<boss_gormokAI>(creature);
        }
};

class SnobolledTargetSelector : public std::unary_function<Unit*, bool>
{
public:
    SnobolledTargetSelector(Unit const* /*unit*/) { }

    bool operator()(Unit* unit) const
    {
        if (unit->GetTypeId() != TYPEID_PLAYER)
            return false;

        if (unit->HasAura(SPELL_RIDE_PLAYER) || unit->HasAura(SPELL_SNOBOLLED))
            return false;

        return true;
    }
};

class npc_snobold_vassal : public CreatureScript
{
    public:
        npc_snobold_vassal() : CreatureScript("npc_snobold_vassal") { }

        struct npc_snobold_vassalAI : public ScriptedAI
        {
            npc_snobold_vassalAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()), _isActive(false)
            {
                _instance->SetData(DATA_SNOBOLD_COUNT, INCREASE);
                SetCombatMovement(false);
            }

            void Reset() override
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                me->SetInCombatWithZone();
                _events.ScheduleEvent(EVENT_CHECK_MOUNT, Seconds(1));
                _events.ScheduleEvent(EVENT_FIRE_BOMB, Seconds(5), Seconds(30));
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (Unit* target = ObjectAccessor::GetPlayer(*me, _targetGUID))
                    target->RemoveAurasDueToSpell(SPELL_SNOBOLLED);
                _instance->SetData(DATA_SNOBOLD_COUNT, DECREASE);
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_ENABLE_FIRE_BOMB:
                        _events.ScheduleEvent(EVENT_FIRE_BOMB, Seconds(5), Seconds(30));
                        break;
                    case ACTION_DISABLE_FIRE_BOMB:
                        _events.CancelEvent(EVENT_FIRE_BOMB);
                        break;
                    case ACTION_ACTIVE_SNOBOLD:
                        _isActive = true;
                        break;
                    default:
                        break;
                }
            }

            void SetGUID(ObjectGuid guid, int32 id) override
            {
                if (id == DATA_NEW_TARGET)
                    if (Unit* target = ObjectAccessor::GetPlayer(*me, guid))
                    {
                        _targetGUID = guid;
                        AttackStart(target);
                        _events.ScheduleEvent(EVENT_BATTER, Seconds(5));
                        _events.ScheduleEvent(EVENT_HEAD_CRACK, Seconds(25));
                        _events.ScheduleEvent(EVENT_SNOBOLLED, Milliseconds(500));
                    }
            }

            void AttackStart(Unit* who) override
            {
                //Snobold only melee attack players that is your vehicle
                if (!_isActive || who->GetGUID() != _targetGUID)
                    return;

                ScriptedAI::AttackStart(who);
            }

            void MountOnBoss()
            {
                Unit* gormok = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(NPC_GORMOK));
                if (gormok && gormok->IsAlive())
                {
                    me->AttackStop();
                    _targetGUID.Clear();
                    _isActive = false;
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
                //Without Boss, snobolds should jump in another players
                else if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, SnobolledTargetSelector(me)))
                    me->CastSpell(target, SPELL_RIDE_PLAYER, true);
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FIRE_BOMB:
                            if (me->GetVehicleBase())
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, -me->GetVehicleBase()->GetCombatReach(), true))
                                    me->CastSpell(target, SPELL_FIRE_BOMB);
                            _events.Repeat(Seconds(20));
                            break;
                        case EVENT_HEAD_CRACK:
                            DoCast(me->GetVehicleBase(), SPELL_HEAD_CRACK);
                            _events.Repeat(Seconds(30));
                            break;
                        case EVENT_BATTER:
                            DoCast(me->GetVehicleBase(), SPELL_BATTER);
                            _events.Repeat(Seconds(10));
                            break;
                        case EVENT_SNOBOLLED:
                            DoCastAOE(SPELL_SNOBOLLED);
                            break;
                        case EVENT_CHECK_MOUNT:
                            if (!me->GetVehicleBase())
                                MountOnBoss();
                            _events.Repeat(Seconds(1));
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                if (!UpdateVictim())
                    return;

                // do melee attack only if is in player back.
                if (_isActive)
                    DoMeleeAttackIfReady();
            }

            private:
                EventMap _events;
                InstanceScript* _instance;
                ObjectGuid _targetGUID;
                bool _isActive;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTrialOfTheCrusaderAI<npc_snobold_vassalAI>(creature);
        }
};

class npc_firebomb : public CreatureScript
{
    public:
        npc_firebomb() : CreatureScript("npc_firebomb") { }

        struct npc_firebombAI : public ScriptedAI
        {
            npc_firebombAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
            }

            void Reset() override
            {
                DoCast(me, SPELL_FIRE_BOMB_DOT, true);
                SetCombatMovement(false);
                me->SetReactState(REACT_PASSIVE);
                me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
            }

            void UpdateAI(uint32 /*diff*/) override
            {
                if (_instance->GetData(TYPE_NORTHREND_BEASTS) != GORMOK_IN_PROGRESS)
                    me->DespawnOrUnsummon();
            }

            private:
                InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTrialOfTheCrusaderAI<npc_firebombAI>(creature);
        }
};

struct boss_jormungarAI : public BossAI
{
    boss_jormungarAI(Creature* creature) : BossAI(creature, BOSS_BEASTS)
    {
        OtherWormEntry = 0;
        ModelStationary = 0;
        ModelMobile = 0;

        BiteSpell = 0;
        SpewSpell = 0;
        SpitSpell = 0;
        SpraySpell = 0;

        Phase = PHASE_MOBILE;
        Enraged = false;
        WasMobile = false;
    }

    void Reset() override
    {
        Enraged = false;

        events.ScheduleEvent(EVENT_SPIT, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS), 0, PHASE_STATIONARY);
        events.ScheduleEvent(EVENT_SPRAY, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS), 0, PHASE_STATIONARY);
        events.ScheduleEvent(EVENT_SWEEP, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS), 0, PHASE_STATIONARY);
        events.ScheduleEvent(EVENT_BITE, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS), 0, PHASE_MOBILE);
        events.ScheduleEvent(EVENT_SPEW, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS), 0, PHASE_MOBILE);
        events.ScheduleEvent(EVENT_SLIME_POOL, 15*IN_MILLISECONDS, 0, PHASE_MOBILE);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* otherWorm = ObjectAccessor::GetCreature(*me, instance->GetGuidData(OtherWormEntry)))
        {
            if (!otherWorm->IsAlive())
            {
                instance->SetData(TYPE_NORTHREND_BEASTS, SNAKES_DONE);

                me->DespawnOrUnsummon();
                otherWorm->DespawnOrUnsummon();
            }
            else
                instance->SetData(TYPE_NORTHREND_BEASTS, SNAKES_SPECIAL);
        }
    }

    void JustReachedHome() override
    {
        // prevent losing 2 attempts at once on heroics
        if (instance->GetData(TYPE_NORTHREND_BEASTS) != FAIL)
            instance->SetData(TYPE_NORTHREND_BEASTS, FAIL);

        me->DespawnOrUnsummon();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        me->SetInCombatWithZone();
        instance->SetData(TYPE_NORTHREND_BEASTS, SNAKES_IN_PROGRESS);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (!Enraged && instance->GetData(TYPE_NORTHREND_BEASTS) == SNAKES_SPECIAL)
        {
            me->RemoveAurasDueToSpell(SPELL_SUBMERGE);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            DoCast(SPELL_ENRAGE);
            Enraged = true;
            Talk(EMOTE_ENRAGE);
        }

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_EMERGE:
                    Emerge();
                    return;
                case EVENT_SUBMERGE:
                    Submerge();
                    return;
                case EVENT_BITE:
                    DoCastVictim(BiteSpell);
                    events.ScheduleEvent(EVENT_BITE, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS), 0, PHASE_MOBILE);
                    return;
                case EVENT_SPEW:
                    DoCastAOE(SpewSpell);
                    events.ScheduleEvent(EVENT_SPEW, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS), 0, PHASE_MOBILE);
                    return;
                case EVENT_SLIME_POOL:
                    DoCast(me, SUMMON_SLIME_POOL);
                    events.ScheduleEvent(EVENT_SLIME_POOL, 30*IN_MILLISECONDS, 0, PHASE_MOBILE);
                    return;
                case EVENT_SUMMON_ACIDMAW:
                    if (Creature* acidmaw = me->SummonCreature(NPC_ACIDMAW, ToCCommonLoc[9].GetPositionX(), ToCCommonLoc[9].GetPositionY(), ToCCommonLoc[9].GetPositionZ(), 5, TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        acidmaw->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC);
                        acidmaw->SetReactState(REACT_AGGRESSIVE);
                        acidmaw->SetInCombatWithZone();
                        acidmaw->CastSpell(acidmaw, SPELL_EMERGE);
                        acidmaw->CastSpell(acidmaw, SPELL_GROUND_VISUAL_1, true);
                    }
                    return;
                case EVENT_SPRAY:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        DoCast(target, SpraySpell);
                    events.ScheduleEvent(EVENT_SPRAY, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS), 0, PHASE_STATIONARY);
                    return;
                case EVENT_SWEEP:
                    DoCastAOE(SPELL_SWEEP);
                    events.ScheduleEvent(EVENT_SWEEP, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS), 0, PHASE_STATIONARY);
                    return;
                default:
                    return;
            }
        }
        if (events.IsInPhase(PHASE_MOBILE))
            DoMeleeAttackIfReady();
        if (events.IsInPhase(PHASE_STATIONARY))
            DoCastVictim(SpitSpell);
    }

    void Submerge()
    {
        DoCast(me, SPELL_SUBMERGE);
        DoCast(me, SPELL_GROUND_VISUAL_0, true);
        me->RemoveAurasDueToSpell(SPELL_EMERGE);
        me->SetInCombatWithZone();
        events.SetPhase(PHASE_SUBMERGED);
        events.ScheduleEvent(EVENT_EMERGE, 5*IN_MILLISECONDS, 0, PHASE_SUBMERGED);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
        me->GetMotionMaster()->MovePoint(0, ToCCommonLoc[1].GetPositionX()+ frand(-40.0f, 40.0f), ToCCommonLoc[1].GetPositionY() + frand(-40.0f, 40.0f), ToCCommonLoc[1].GetPositionZ());
        WasMobile = !WasMobile;
    }

    void Emerge()
    {
        DoCast(me, SPELL_EMERGE);
        DoCastAOE(SPELL_HATE_TO_ZERO, true);
        me->SetDisplayId(ModelMobile);
        me->RemoveAurasDueToSpell(SPELL_SUBMERGE);
        me->RemoveAurasDueToSpell(SPELL_GROUND_VISUAL_0);
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);

        // if the worm was mobile before submerging, make him stationary now
        if (WasMobile)
        {
            me->SetControlled(true, UNIT_STATE_ROOT);
            SetCombatMovement(false);
            me->SetDisplayId(ModelStationary);
            me->CastSpell(me, SPELL_GROUND_VISUAL_1, true);
            events.SetPhase(PHASE_STATIONARY);
            events.ScheduleEvent(EVENT_SUBMERGE, 45*IN_MILLISECONDS, 0, PHASE_STATIONARY);
            events.ScheduleEvent(EVENT_SPIT, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS), 0, PHASE_STATIONARY);
            events.ScheduleEvent(EVENT_SPRAY, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS), 0, PHASE_STATIONARY);
            events.ScheduleEvent(EVENT_SWEEP, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS), 0, PHASE_STATIONARY);
        }
        else
        {
            me->SetControlled(false, UNIT_STATE_ROOT);
            SetCombatMovement(true);
            me->GetMotionMaster()->MoveChase(me->GetVictim());
            me->SetDisplayId(ModelMobile);
            me->RemoveAurasDueToSpell(SPELL_GROUND_VISUAL_1);
            events.SetPhase(PHASE_MOBILE);
            events.ScheduleEvent(EVENT_SUBMERGE, 45*IN_MILLISECONDS, 0, PHASE_MOBILE);
            events.ScheduleEvent(EVENT_BITE, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS), 0, PHASE_MOBILE);
            events.ScheduleEvent(EVENT_SPEW, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS), 0, PHASE_MOBILE);
            events.ScheduleEvent(EVENT_SLIME_POOL, 15*IN_MILLISECONDS, 0, PHASE_MOBILE);
        }
    }

    protected:
        uint32 OtherWormEntry;
        uint32 ModelStationary;
        uint32 ModelMobile;

        uint32 BiteSpell;
        uint32 SpewSpell;
        uint32 SpitSpell;
        uint32 SpraySpell;

        Phases Phase;
        bool Enraged;
        bool WasMobile;
};

class boss_acidmaw : public CreatureScript
{
    public:
        boss_acidmaw() : CreatureScript("boss_acidmaw") { }

        struct boss_acidmawAI : public boss_jormungarAI
        {
            boss_acidmawAI(Creature* creature) : boss_jormungarAI(creature) { }

            void Reset() override
            {
                boss_jormungarAI::Reset();
                BiteSpell = SPELL_PARALYTIC_BITE;
                SpewSpell = SPELL_ACID_SPEW;
                SpitSpell = SPELL_ACID_SPIT;
                SpraySpell = SPELL_PARALYTIC_SPRAY;
                ModelStationary = MODEL_ACIDMAW_STATIONARY;
                ModelMobile = MODEL_ACIDMAW_MOBILE;
                OtherWormEntry = NPC_DREADSCALE;

                WasMobile = true;
                Emerge();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTrialOfTheCrusaderAI<boss_acidmawAI>(creature);
        }
};

class boss_dreadscale : public CreatureScript
{
    public:
        boss_dreadscale() : CreatureScript("boss_dreadscale") { }

        struct boss_dreadscaleAI : public boss_jormungarAI
        {
            boss_dreadscaleAI(Creature* creature) : boss_jormungarAI(creature) { }

            void Reset() override
            {
                boss_jormungarAI::Reset();
                BiteSpell = SPELL_BURNING_BITE;
                SpewSpell = SPELL_MOLTEN_SPEW;
                SpitSpell = SPELL_FIRE_SPIT;
                SpraySpell = SPELL_BURNING_SPRAY;
                ModelStationary = MODEL_DREADSCALE_STATIONARY;
                ModelMobile = MODEL_DREADSCALE_MOBILE;
                OtherWormEntry = NPC_ACIDMAW;

                events.SetPhase(PHASE_MOBILE);
                events.ScheduleEvent(EVENT_SUMMON_ACIDMAW, 3*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SUBMERGE, 45*IN_MILLISECONDS, 0, PHASE_MOBILE);
                WasMobile = false;
            }

            void MovementInform(uint32 type, uint32 pointId) override
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                switch (pointId)
                {
                    case 0:
                        instance->DoCloseDoorOrButton(instance->GetGuidData(GO_MAIN_GATE_DOOR));
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC);
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->SetInCombatWithZone();
                        break;
                    default:
                        break;
                }
            }

            void EnterEvadeMode(EvadeReason why) override
            {
                instance->DoUseDoorOrButton(instance->GetGuidData(GO_MAIN_GATE_DOOR));
                boss_jormungarAI::EnterEvadeMode(why);
            }

            void JustReachedHome() override
            {
                instance->DoUseDoorOrButton(instance->GetGuidData(GO_MAIN_GATE_DOOR));

                boss_jormungarAI::JustReachedHome();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTrialOfTheCrusaderAI<boss_dreadscaleAI>(creature);
        }
};

class npc_slime_pool : public CreatureScript
{
    public:
        npc_slime_pool() : CreatureScript("npc_slime_pool") { }

        struct npc_slime_poolAI : public ScriptedAI
        {
            npc_slime_poolAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
                _instance = creature->GetInstanceScript();
            }

            void Initialize()
            {
                _cast = false;
            }

            void Reset() override
            {
                Initialize();
                me->SetReactState(REACT_PASSIVE);
            }

            void UpdateAI(uint32 /*diff*/) override
            {
                if (!_cast)
                {
                    _cast = true;
                    DoCast(me, SPELL_SLIME_POOL_EFFECT);
                }

                if (_instance->GetData(TYPE_NORTHREND_BEASTS) != SNAKES_IN_PROGRESS && _instance->GetData(TYPE_NORTHREND_BEASTS) != SNAKES_SPECIAL)
                    me->DespawnOrUnsummon();
            }
            private:
                InstanceScript* _instance;
                bool _cast;

        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTrialOfTheCrusaderAI<npc_slime_poolAI>(creature);
        }
};

class spell_gormok_fire_bomb : public SpellScriptLoader
{
    public:
        spell_gormok_fire_bomb() : SpellScriptLoader("spell_gormok_fire_bomb") { }

        class spell_gormok_fire_bomb_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_gormok_fire_bomb_SpellScript);

            void TriggerFireBomb(SpellEffIndex /*effIndex*/)
            {
                if (const WorldLocation* pos = GetExplTargetDest())
                {
                    if (Unit* caster = GetCaster())
                        caster->SummonCreature(NPC_FIRE_BOMB, pos->GetPositionX(), pos->GetPositionY(), pos->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 30*IN_MILLISECONDS);
                }
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_gormok_fire_bomb_SpellScript::TriggerFireBomb, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_gormok_fire_bomb_SpellScript();
        }
};

class boss_icehowl : public CreatureScript
{
    public:
        boss_icehowl() : CreatureScript("boss_icehowl") { }

        struct boss_icehowlAI : public BossAI
        {
            boss_icehowlAI(Creature* creature) : BossAI(creature, BOSS_BEASTS)
            {
                Initialize();
            }

            void Initialize()
            {
                _movementStarted = false;
                _movementFinish = false;
                _trampleCast = false;
                _trampleTargetGUID.Clear();
                _trampleTargetX = 0;
                _trampleTargetY = 0;
                _trampleTargetZ = 0;
                _stage = 0;
            }

            void Reset() override
            {
                events.ScheduleEvent(EVENT_FEROCIOUS_BUTT, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_ARCTIC_BREATH, urand(15*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_WHIRL, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_MASSIVE_CRASH, 30*IN_MILLISECONDS);
                Initialize();
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                instance->SetData(TYPE_NORTHREND_BEASTS, ICEHOWL_DONE);
            }

            void MovementInform(uint32 type, uint32 pointId) override
            {
                if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                    return;

                switch (pointId)
                {
                    case 0:
                        if (_stage != 0)
                        {
                            if (me->GetDistance2d(ToCCommonLoc[1].GetPositionX(), ToCCommonLoc[1].GetPositionY()) < 6.0f)
                                // Middle of the room
                                _stage = 1;
                            else
                            {
                                // Landed from Hop backwards (start trample)
                                if (ObjectAccessor::GetPlayer(*me, _trampleTargetGUID))
                                    _stage = 4;
                                else
                                    _stage = 6;
                            }
                        }
                        break;
                    case 1: // Finish trample
                        _movementFinish = true;
                        break;
                    case 2:
                        instance->DoUseDoorOrButton(instance->GetGuidData(GO_MAIN_GATE_DOOR));
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC);
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->SetInCombatWithZone();
                        break;
                    default:
                        break;
                }
            }

            void EnterEvadeMode(EvadeReason why) override
            {
                instance->DoUseDoorOrButton(instance->GetGuidData(GO_MAIN_GATE_DOOR));
                ScriptedAI::EnterEvadeMode(why);
            }

            void JustReachedHome() override
            {
                instance->DoUseDoorOrButton(instance->GetGuidData(GO_MAIN_GATE_DOOR));
                instance->SetData(TYPE_NORTHREND_BEASTS, FAIL);
                me->DespawnOrUnsummon();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                instance->SetData(TYPE_NORTHREND_BEASTS, ICEHOWL_IN_PROGRESS);
            }

            void SpellHitTarget(Unit* target, SpellInfo const* spell) override
            {
                if (spell->Id == SPELL_TRAMPLE && target->GetTypeId() == TYPEID_PLAYER)
                {
                    if (!_trampleCast)
                    {
                        DoCast(me, SPELL_FROTHING_RAGE, true);
                        _trampleCast = true;
                    }
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                switch (_stage)
                {
                    case 0:
                    {
                        while (uint32 eventId = events.ExecuteEvent())
                        {
                            switch (eventId)
                            {
                                case EVENT_FEROCIOUS_BUTT:
                                    DoCastVictim(SPELL_FEROCIOUS_BUTT);
                                    events.ScheduleEvent(EVENT_FEROCIOUS_BUTT, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                                    return;
                                case EVENT_ARCTIC_BREATH:
                                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                        DoCast(target, SPELL_ARCTIC_BREATH);
                                    return;
                                case EVENT_WHIRL:
                                    DoCastAOE(SPELL_WHIRL);
                                    events.ScheduleEvent(EVENT_WHIRL, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                                    return;
                                case EVENT_MASSIVE_CRASH:
                                    me->GetMotionMaster()->MoveJump(ToCCommonLoc[1], 20.0f, 20.0f, 0); // 1: Middle of the room
                                    SetCombatMovement(false);
                                    me->AttackStop();
                                    _stage = 7; //Invalid (Do nothing more than move)
                                    return;
                                default:
                                    break;
                            }

                            if (me->HasUnitState(UNIT_STATE_CASTING))
                                return;
                        }
                        DoMeleeAttackIfReady();
                        break;
                    }
                    case 1:
                        DoCastAOE(SPELL_MASSIVE_CRASH);
                        me->StopMoving();
                        me->AttackStop();
                        _stage = 2;
                        break;
                    case 2:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        {
                            me->StopMoving();
                            me->AttackStop();
                            _trampleTargetGUID = target->GetGUID();
                            me->SetTarget(_trampleTargetGUID);
                            _trampleCast = false;
                            SetCombatMovement(false);
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            me->SetControlled(true, UNIT_STATE_ROOT);
                            me->GetMotionMaster()->Clear();
                            me->GetMotionMaster()->MoveIdle();
                            events.ScheduleEvent(EVENT_TRAMPLE, 4*IN_MILLISECONDS);
                            _stage = 3;
                        }
                        else
                            _stage = 6;
                        break;
                    case 3:
                        while (uint32 eventId = events.ExecuteEvent())
                        {
                            switch (eventId)
                            {
                                case EVENT_TRAMPLE:
                                {
                                    if (Unit* target = ObjectAccessor::GetPlayer(*me, _trampleTargetGUID))
                                    {
                                        me->StopMoving();
                                        me->AttackStop();
                                        _trampleCast = false;
                                        _movementStarted = true;
                                        _trampleTargetX = target->GetPositionX();
                                        _trampleTargetY = target->GetPositionY();
                                        _trampleTargetZ = target->GetPositionZ();
                                        // 2: Hop Backwards
                                        me->GetMotionMaster()->MoveJump(2*me->GetPositionX() - _trampleTargetX, 2*me->GetPositionY() - _trampleTargetY, me->GetPositionZ(), me->GetOrientation(), 30.0f, 20.0f, 0);
                                        me->SetControlled(false, UNIT_STATE_ROOT);
                                        _stage = 7; //Invalid (Do nothing more than move)
                                    }
                                    else
                                        _stage = 6;
                                    break;
                                }
                                default:
                                    break;
                            }

                            if (me->HasUnitState(UNIT_STATE_CASTING))
                                return;
                        }
                        break;
                    case 4:
                        me->StopMoving();
                        me->AttackStop();
                        if (Player* target = ObjectAccessor::GetPlayer(*me, _trampleTargetGUID))
                            Talk(EMOTE_TRAMPLE_START, target);
                        me->GetMotionMaster()->MoveCharge(_trampleTargetX, _trampleTargetY, _trampleTargetZ, 42, 1);
                        me->SetTarget(ObjectGuid::Empty);
                        _stage = 5;
                        break;
                    case 5:
                        if (_movementFinish)
                        {
                            DoCastAOE(SPELL_TRAMPLE);
                            _movementFinish = false;
                            _stage = 6;
                            return;
                        }
                        if (events.ExecuteEvent() == EVENT_TRAMPLE)
                        {
                            Map::PlayerList const &lPlayers = me->GetMap()->GetPlayers();
                            for (Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
                            {
                                if (Unit* player = itr->GetSource())
                                {
                                    if (player->IsAlive() && player->IsWithinDistInMap(me, 6.0f))
                                    {
                                        DoCastAOE(SPELL_TRAMPLE);
                                        events.ScheduleEvent(EVENT_TRAMPLE, 4*IN_MILLISECONDS);
                                        break;
                                    }
                                }
                            }
                        }
                        break;
                    case 6:
                        if (!_trampleCast)
                        {
                            DoCast(me, SPELL_STAGGERED_DAZE);
                            Talk(EMOTE_TRAMPLE_CRASH);
                        }
                        else
                        {
                            DoCast(me, SPELL_FROTHING_RAGE, true);
                            Talk(EMOTE_TRAMPLE_FAIL);
                        }
                        _movementStarted = false;
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        SetCombatMovement(true);
                        me->GetMotionMaster()->MovementExpired();
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MoveChase(me->GetVictim());
                        AttackStart(me->GetVictim());
                        events.ScheduleEvent(EVENT_MASSIVE_CRASH, 40*IN_MILLISECONDS);
                        events.ScheduleEvent(EVENT_ARCTIC_BREATH, urand(15*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                        _stage = 0;
                        break;
                    default:
                        break;
                }
            }

            private:
                float  _trampleTargetX, _trampleTargetY, _trampleTargetZ;
                ObjectGuid _trampleTargetGUID;
                bool   _movementStarted;
                bool   _movementFinish;
                bool   _trampleCast;
                uint8  _stage;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTrialOfTheCrusaderAI<boss_icehowlAI>(creature);
        }
};

class spell_gormok_jump_to_hand : public SpellScriptLoader
{
public:
    spell_gormok_jump_to_hand() : SpellScriptLoader("spell_gormok_jump_to_hand") { }

    class spell_gormok_jump_to_hand_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_gormok_jump_to_hand_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_RIDE_PLAYER });
        }

        bool Load() override
        {
            if (GetCaster() && GetCaster()->GetEntry() == NPC_SNOBOLD_VASSAL)
                return true;
            return false;
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (CreatureAI* gormokAI = GetTarget()->ToCreature()->AI())
                {
                    if (Unit* target = gormokAI->SelectTarget(SELECT_TARGET_RANDOM, 0, SnobolledTargetSelector(GetTarget())))
                    {
                        gormokAI->Talk(EMOTE_SNOBOLLED);
                        caster->GetAI()->DoAction(ACTION_ACTIVE_SNOBOLD);
                        caster->CastSpell(target, SPELL_RIDE_PLAYER, true);
                    }
                }
            }
        }

        void Register() override
        {
            AfterEffectRemove += AuraEffectRemoveFn(spell_gormok_jump_to_hand_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_CONTROL_VEHICLE, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_gormok_jump_to_hand_AuraScript();
    }
};

class spell_gormok_ride_player : public SpellScriptLoader
{
public:
    spell_gormok_ride_player() : SpellScriptLoader("spell_gormok_ride_player") { }

    class spell_gormok_ride_player_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_gormok_ride_player_AuraScript);

        bool Load() override
        {
            if (GetCaster() && GetCaster()->GetEntry() == NPC_SNOBOLD_VASSAL)
                return true;
            return false;
        }

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* target = GetTarget();
            if (target->GetTypeId() != TYPEID_PLAYER || !target->IsInWorld())
                return;

            if (!target->CreateVehicleKit(PLAYER_VEHICLE_ID, 0))
                return;

            if (Unit *caster = GetCaster())
                caster->GetAI()->SetGUID(target->GetGUID(), DATA_NEW_TARGET);
        }

        void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            GetTarget()->RemoveVehicleKit();
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_gormok_ride_player_AuraScript::OnApply, EFFECT_0, SPELL_AURA_CONTROL_VEHICLE, AURA_EFFECT_HANDLE_REAL);
            AfterEffectRemove += AuraEffectRemoveFn(spell_gormok_ride_player_AuraScript::AfterRemove, EFFECT_0, SPELL_AURA_CONTROL_VEHICLE, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_gormok_ride_player_AuraScript();
    }
};

class spell_gormok_snobolled : public SpellScriptLoader
{
public:
    spell_gormok_snobolled() : SpellScriptLoader("spell_gormok_snobolled") { }

    class spell_gormok_snobolled_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_gormok_snobolled_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
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
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_gormok_snobolled_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_gormok_snobolled_AuraScript();
    }
};

class spell_jormungars_paralytic_toxin : public SpellScriptLoader
{
public:
    spell_jormungars_paralytic_toxin() : SpellScriptLoader("spell_jormungars_paralytic_toxin") { }

    class spell_jormungars_paralytic_toxin_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_jormungars_paralytic_toxin_AuraScript);

        bool Validate(SpellInfo const* /*spell*/) override
        {
            return ValidateSpellInfo({ SPELL_PARALYSIS });
        }

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            if (caster && caster->GetEntry() == NPC_ACIDMAW)
            {
                if (Creature* acidMaw = caster->ToCreature())
                    acidMaw->AI()->Talk(SAY_SPECIAL, GetTarget());
            }
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

                if (newAmount <= -100 && !GetTarget()->HasAura(SPELL_PARALYSIS))
                    GetTarget()->CastSpell(GetTarget(), SPELL_PARALYSIS, true, NULL, slowEff, GetCasterGUID());
            }
        }

        void Register() override
        {
            AfterEffectApply += AuraEffectApplyFn(spell_jormungars_paralytic_toxin_AuraScript::OnApply, EFFECT_0, SPELL_AURA_MOD_DECREASE_SPEED, AURA_EFFECT_HANDLE_REAL);
            AfterEffectRemove += AuraEffectRemoveFn(spell_jormungars_paralytic_toxin_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_DECREASE_SPEED, AURA_EFFECT_HANDLE_REAL);
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_jormungars_paralytic_toxin_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_MOD_DECREASE_SPEED);
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_jormungars_paralytic_toxin_AuraScript::HandleDummy, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_jormungars_paralytic_toxin_AuraScript();
    }
};

class spell_jormungars_snakes_spray : public SpellScriptLoader
{
public:
    spell_jormungars_snakes_spray(const char* name, uint32 spellId) : SpellScriptLoader(name), _spellId(spellId) { }

    class spell_jormungars_snakes_spray_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_jormungars_snakes_spray_SpellScript);

    public:
        spell_jormungars_snakes_spray_SpellScript(uint32 spellId) : SpellScript(), _spellId(spellId) { }

        bool Validate(SpellInfo const* /*spell*/) override
        {
            return ValidateSpellInfo({ _spellId });
        }

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            if (Player* target = GetHitPlayer())
                GetCaster()->CastSpell(target, _spellId, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_jormungars_snakes_spray_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }

    private:
        uint32 _spellId;
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_jormungars_snakes_spray_SpellScript(_spellId);
    }

private:
    uint32 _spellId;
};

class spell_jormungars_paralysis : public SpellScriptLoader
{
public:
    spell_jormungars_paralysis() : SpellScriptLoader("spell_jormungars_paralysis") { }

    class spell_jormungars_paralysis_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_jormungars_paralysis_AuraScript);

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
                if (InstanceScript* instance = caster->GetInstanceScript())
                    if (instance->GetData(TYPE_NORTHREND_BEASTS) == SNAKES_IN_PROGRESS || instance->GetData(TYPE_NORTHREND_BEASTS) == SNAKES_SPECIAL)
                        return;

            Remove();
        }

        void Register() override
        {
            AfterEffectApply += AuraEffectApplyFn(spell_jormungars_paralysis_AuraScript::OnApply, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_jormungars_paralysis_AuraScript();
    }
};

void AddSC_boss_northrend_beasts()
{
    new boss_gormok();
    new npc_snobold_vassal();
    new npc_firebomb();
    new spell_gormok_fire_bomb();
    new spell_gormok_jump_to_hand();
    new spell_gormok_ride_player();
    new spell_gormok_snobolled();

    new boss_acidmaw();
    new boss_dreadscale();
    new npc_slime_pool();
    new spell_jormungars_paralytic_toxin();
    new spell_jormungars_snakes_spray("spell_jormungars_burning_spray", SPELL_BURNING_BILE);
    new spell_jormungars_snakes_spray("spell_jormungars_paralytic_spray", SPELL_PARALYTIC_TOXIN);
    new spell_jormungars_paralysis();

    new boss_icehowl();
}
