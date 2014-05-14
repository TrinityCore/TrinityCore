/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

// Known bugs:
// Gormok - Snobolled (creature at back)

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "trial_of_the_crusader.h"
#include "Vehicle.h"
#include "Player.h"
#include "SpellScript.h"

enum Yells
{
    // Gormok
    EMOTE_SNOBOLLED         = 0,

    // Acidmaw & Dreadscale
    EMOTE_ENRAGE            = 0,

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
    SPELL_RISING_ANGER      = 66636,
    //Snobold
    SPELL_SNOBOLLED         = 66406,
    SPELL_BATTER            = 66408,
    SPELL_FIRE_BOMB         = 66313,
    SPELL_FIRE_BOMB_1       = 66317,
    SPELL_FIRE_BOMB_DOT     = 66318,
    SPELL_HEAD_CRACK        = 66407,

    //Acidmaw & Dreadscale
    SPELL_ACID_SPIT         = 66880,
    SPELL_PARALYTIC_SPRAY   = 66901,
    SPELL_ACID_SPEW         = 66819,
    SPELL_PARALYTIC_BITE    = 66824,
    SPELL_SWEEP_0           = 66794,
    SUMMON_SLIME_POOL       = 66883,
    SPELL_FIRE_SPIT         = 66796,
    SPELL_MOLTEN_SPEW       = 66821,
    SPELL_BURNING_BITE      = 66879,
    SPELL_BURNING_SPRAY     = 66902,
    SPELL_SWEEP_1           = 67646,
    SPELL_EMERGE_0          = 66947,
    SPELL_SUBMERGE_0        = 66948,
    SPELL_ENRAGE            = 68335,
    SPELL_SLIME_POOL_EFFECT = 66882, //In 60s it diameter grows from 10y to 40y (r=r+0.25 per second)

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
    ACTION_DISABLE_FIRE_BOMB    = 2
};

enum Events
{
    // Gormok
    EVENT_IMPALE                = 1,
    EVENT_STAGGERING_STOMP      = 2,
    EVENT_THROW                 = 3,

    // Snobold
    EVENT_FIRE_BOMB             = 4,
    EVENT_BATTER                = 5,
    EVENT_HEAD_CRACK            = 6,

    // Acidmaw & Dreadscale
    EVENT_BITE                  = 7,
    EVENT_SPEW                  = 8,
    EVENT_SLIME_POOL            = 9,
    EVENT_SPIT                  = 10,
    EVENT_SPRAY                 = 11,
    EVENT_SWEEP                 = 12,
    EVENT_SUBMERGE              = 13,
    EVENT_EMERGE                = 14,
    EVENT_SUMMON_ACIDMAW        = 15,

    // Icehowl
    EVENT_FEROCIOUS_BUTT        = 16,
    EVENT_MASSIVE_CRASH         = 17,
    EVENT_WHIRL                 = 18,
    EVENT_ARCTIC_BREATH         = 19,
    EVENT_TRAMPLE               = 20
};

enum Phases
{
    PHASE_MOBILE            = 1,
    PHASE_STATIONARY        = 2,
    PHASE_SUBMERGED         = 3
};

class boss_gormok : public CreatureScript
{
    public:
        boss_gormok() : CreatureScript("boss_gormok") { }

        struct boss_gormokAI : public BossAI
        {
            boss_gormokAI(Creature* creature) : BossAI(creature, BOSS_BEASTS)
            {
            }

            void Reset() override
            {
                events.ScheduleEvent(EVENT_IMPALE, urand(8*IN_MILLISECONDS, 10*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_STAGGERING_STOMP, 15*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_THROW, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS));

                summons.DespawnAll();
            }

            void EnterEvadeMode() override
            {
                instance->DoUseDoorOrButton(instance->GetData64(GO_MAIN_GATE_DOOR));
                ScriptedAI::EnterEvadeMode();
            }

            void MovementInform(uint32 type, uint32 pointId) override
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                switch (pointId)
                {
                    case 0:
                        instance->DoUseDoorOrButton(instance->GetData64(GO_MAIN_GATE_DOOR));
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
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
                instance->DoUseDoorOrButton(instance->GetData64(GO_MAIN_GATE_DOOR));
                instance->SetData(TYPE_NORTHREND_BEASTS, FAIL);

                me->DespawnOrUnsummon();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                me->SetInCombatWithZone();
                instance->SetData(TYPE_NORTHREND_BEASTS, GORMOK_IN_PROGRESS);

                for (uint8 i = 0; i < MAX_SNOBOLDS; i++)
                {
                    if (Creature* pSnobold = DoSpawnCreature(NPC_SNOBOLD_VASSAL, 0, 0, 0, 0, TEMPSUMMON_CORPSE_DESPAWN, 0))
                    {
                        pSnobold->EnterVehicle(me, i);
                        pSnobold->SetInCombatWithZone();
                        pSnobold->AI()->DoAction(ACTION_ENABLE_FIRE_BOMB);
                    }
                }
            }

            void DamageTaken(Unit* /*who*/, uint32& damage) override
            {
                // despawn the remaining passengers on death
                if (damage >= me->GetHealth())
                    for (uint8 i = 0; i < MAX_SNOBOLDS; ++i)
                        if (Unit* pSnobold = me->GetVehicleKit()->GetPassenger(i))
                            pSnobold->ToCreature()->DespawnOrUnsummon();
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
                            events.ScheduleEvent(EVENT_IMPALE, urand(8*IN_MILLISECONDS, 10*IN_MILLISECONDS));
                            return;
                        case EVENT_STAGGERING_STOMP:
                            DoCastVictim(SPELL_STAGGERING_STOMP);
                            events.ScheduleEvent(EVENT_STAGGERING_STOMP, 15*IN_MILLISECONDS);
                            return;
                        case EVENT_THROW:
                            for (uint8 i = 0; i < MAX_SNOBOLDS; ++i)
                            {
                                if (Unit* pSnobold = me->GetVehicleKit()->GetPassenger(i))
                                {
                                    pSnobold->ExitVehicle();
                                    pSnobold->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                                    pSnobold->ToCreature()->SetReactState(REACT_AGGRESSIVE);
                                    pSnobold->ToCreature()->AI()->DoAction(ACTION_DISABLE_FIRE_BOMB);
                                    pSnobold->CastSpell(me, SPELL_RISING_ANGER, true);
                                    Talk(EMOTE_SNOBOLLED);
                                    break;
                                }
                            }
                            events.ScheduleEvent(EVENT_THROW, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                            return;
                        default:
                            return;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<boss_gormokAI>(creature);
        }
};

class npc_snobold_vassal : public CreatureScript
{
    public:
        npc_snobold_vassal() : CreatureScript("npc_snobold_vassal") { }

        struct npc_snobold_vassalAI : public ScriptedAI
        {
            npc_snobold_vassalAI(Creature* creature) : ScriptedAI(creature)
            {
                _targetGUID = 0;
                _targetDied = false;
                _instance = creature->GetInstanceScript();
                _instance->SetData(DATA_SNOBOLD_COUNT, INCREASE);
            }

            void Reset() override
            {
                _events.ScheduleEvent(EVENT_BATTER, 5*IN_MILLISECONDS);
                _events.ScheduleEvent(EVENT_HEAD_CRACK, 25*IN_MILLISECONDS);

                _targetGUID = 0;
                _targetDied = false;

                //Workaround for Snobold
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            }

            void EnterEvadeMode() override
            {
                ScriptedAI::EnterEvadeMode();
            }

            void EnterCombat(Unit* who) override
            {
                _targetGUID = who->GetGUID();
                me->TauntApply(who);
                DoCast(who, SPELL_SNOBOLLED);
            }

            void DamageTaken(Unit* pDoneBy, uint32 &uiDamage) override
            {
                if (pDoneBy->GetGUID() == _targetGUID)
                    uiDamage = 0;
            }

            void MovementInform(uint32 type, uint32 pointId) override
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                switch (pointId)
                {
                    case 0:
                        if (_targetDied)
                            me->DespawnOrUnsummon();
                        break;
                    default:
                        break;
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (Unit* target = ObjectAccessor::GetPlayer(*me, _targetGUID))
                    if (target->IsAlive())
                        target->RemoveAurasDueToSpell(SPELL_SNOBOLLED);
                _instance->SetData(DATA_SNOBOLD_COUNT, DECREASE);
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_ENABLE_FIRE_BOMB:
                        _events.ScheduleEvent(EVENT_FIRE_BOMB, urand(5*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                        break;
                    case ACTION_DISABLE_FIRE_BOMB:
                        _events.CancelEvent(EVENT_FIRE_BOMB);
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() || _targetDied)
                    return;

                if (Unit* target = ObjectAccessor::GetPlayer(*me, _targetGUID))
                {
                    if (!target->IsAlive())
                    {
                        Unit* gormok = ObjectAccessor::GetCreature(*me, _instance->GetData64(NPC_GORMOK));
                        if (gormok && gormok->IsAlive())
                        {
                            SetCombatMovement(false);
                            _targetDied = true;

                            // looping through Gormoks seats
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
                        else if (Unit* target2 = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        {
                            _targetGUID = target2->GetGUID();
                            me->GetMotionMaster()->MoveJump(target2->GetPositionX(), target2->GetPositionY(), target2->GetPositionZ(), 15.0f, 15.0f);
                        }
                    }
                }

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
                                    me->CastSpell(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), SPELL_FIRE_BOMB, true);
                            _events.ScheduleEvent(EVENT_FIRE_BOMB, 20*IN_MILLISECONDS);
                            return;
                        case EVENT_HEAD_CRACK:
                            // commented out while SPELL_SNOBOLLED gets fixed
                            //if (Unit* target = ObjectAccessor::GetPlayer(*me, m_uiTargetGUID))
                            DoCastVictim(SPELL_HEAD_CRACK);
                            _events.ScheduleEvent(EVENT_HEAD_CRACK, 30*IN_MILLISECONDS);
                            return;
                        case EVENT_BATTER:
                            // commented out while SPELL_SNOBOLLED gets fixed
                            //if (Unit* target = ObjectAccessor::GetPlayer(*me, m_uiTargetGUID))
                            DoCastVictim(SPELL_BATTER);
                            _events.ScheduleEvent(EVENT_BATTER, 10*IN_MILLISECONDS);
                            return;
                        default:
                            return;
                    }
                }

                // do melee attack only when not on Gormoks back
                if (!me->GetVehicleBase())
                    DoMeleeAttackIfReady();
            }
            private:
                EventMap _events;
                InstanceScript* _instance;
                uint64 _targetGUID;
                bool   _targetDied;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<npc_snobold_vassalAI>(creature);
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
            return GetInstanceAI<npc_firebombAI>(creature);
        }
};

struct boss_jormungarAI : public BossAI
{
    boss_jormungarAI(Creature* creature) : BossAI(creature, BOSS_BEASTS)
    {
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
        if (Creature* otherWorm = Unit::GetCreature(*me, instance->GetData64(OtherWormEntry)))
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

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            instance->SetData(DATA_TRIBUTE_TO_IMMORTALITY_ELIGIBLE, 0);
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
            me->RemoveAurasDueToSpell(SPELL_SUBMERGE_0);
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
                        acidmaw->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        acidmaw->SetReactState(REACT_AGGRESSIVE);
                        acidmaw->SetInCombatWithZone();
                        acidmaw->CastSpell(acidmaw, SPELL_EMERGE_0);
                    }
                    return;
                case EVENT_SPRAY:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        DoCast(target, SpraySpell);
                    events.ScheduleEvent(EVENT_SPRAY, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS), 0, PHASE_STATIONARY);
                    return;
                case EVENT_SWEEP:
                    DoCastAOE(SPELL_SWEEP_0);
                    events.ScheduleEvent(EVENT_SWEEP, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS), 0, PHASE_STATIONARY);
                    return;
                default:
                    return;
            }
        }
        if (events.IsInPhase(PHASE_MOBILE))
            DoMeleeAttackIfReady();
        if (events.IsInPhase(PHASE_STATIONARY))
            DoSpellAttackIfReady(SpitSpell);
    }

    void Submerge()
    {
        DoCast(me, SPELL_SUBMERGE_0);
        me->RemoveAurasDueToSpell(SPELL_EMERGE_0);
        me->SetInCombatWithZone();
        events.SetPhase(PHASE_SUBMERGED);
        events.ScheduleEvent(EVENT_EMERGE, 5*IN_MILLISECONDS, 0, PHASE_SUBMERGED);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
        me->GetMotionMaster()->MovePoint(0, ToCCommonLoc[1].GetPositionX()+ frand(-40.0f, 40.0f), ToCCommonLoc[1].GetPositionY() + frand(-40.0f, 40.0f), ToCCommonLoc[1].GetPositionZ());
        WasMobile = !WasMobile;
    }

    void Emerge()
    {
        DoCast(me, SPELL_EMERGE_0);
        me->SetDisplayId(ModelMobile);
        me->RemoveAurasDueToSpell(SPELL_SUBMERGE_0);
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
        me->GetMotionMaster()->Clear();

        // if the worm was mobile before submerging, make him stationary now
        if (WasMobile)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            SetCombatMovement(false);
            me->SetDisplayId(ModelStationary);
            events.SetPhase(PHASE_STATIONARY);
            events.ScheduleEvent(EVENT_SUBMERGE, 45*IN_MILLISECONDS, 0, PHASE_STATIONARY);
            events.ScheduleEvent(EVENT_SPIT, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS), 0, PHASE_STATIONARY);
            events.ScheduleEvent(EVENT_SPRAY, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS), 0, PHASE_STATIONARY);
            events.ScheduleEvent(EVENT_SWEEP, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS), 0, PHASE_STATIONARY);
        }
        else
        {
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            SetCombatMovement(true);
            me->GetMotionMaster()->MoveChase(me->GetVictim());
            me->SetDisplayId(ModelMobile);
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
            return GetInstanceAI<boss_acidmawAI>(creature);
        }
};

class boss_dreadscale : public CreatureScript
{
    public:
        boss_dreadscale() : CreatureScript("boss_dreadscale") { }

        struct boss_dreadscaleAI : public boss_jormungarAI
        {
            boss_dreadscaleAI(Creature* creature) : boss_jormungarAI(creature)
            {
            }

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
                        instance->DoUseDoorOrButton(instance->GetData64(GO_MAIN_GATE_DOOR));
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->SetInCombatWithZone();
                        break;
                    default:
                        break;
                }
            }

            void EnterEvadeMode() override
            {
                instance->DoUseDoorOrButton(instance->GetData64(GO_MAIN_GATE_DOOR));
                boss_jormungarAI::EnterEvadeMode();
            }

            void JustReachedHome() override
            {
                instance->DoUseDoorOrButton(instance->GetData64(GO_MAIN_GATE_DOOR));

                boss_jormungarAI::JustReachedHome();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<boss_dreadscaleAI>(creature);
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
                _instance = creature->GetInstanceScript();
            }

            void Reset() override
            {
                _cast = false;
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
            return GetInstanceAI<npc_slime_poolAI>(creature);
        }
};

class spell_gormok_fire_bomb : public SpellScriptLoader
{
    public:
        spell_gormok_fire_bomb() : SpellScriptLoader("spell_gormok_fire_bomb") { }

        class spell_gormok_fire_bomb_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_gormok_fire_bomb_SpellScript)

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
            }

            void Reset() override
            {
                events.ScheduleEvent(EVENT_FEROCIOUS_BUTT, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_ARCTIC_BREATH, urand(15*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_WHIRL, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_MASSIVE_CRASH, 30*IN_MILLISECONDS);
                _movementStarted = false;
                _movementFinish = false;
                _trampleCast = false;
                _trampleTargetGUID = 0;
                _trampleTargetX = 0;
                _trampleTargetY = 0;
                _trampleTargetZ = 0;
                _stage = 0;
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
                        instance->DoUseDoorOrButton(instance->GetData64(GO_MAIN_GATE_DOOR));
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->SetInCombatWithZone();
                        break;
                    default:
                        break;
                }
            }

            void EnterEvadeMode() override
            {
                instance->DoUseDoorOrButton(instance->GetData64(GO_MAIN_GATE_DOOR));
                ScriptedAI::EnterEvadeMode();
            }

            void JustReachedHome() override
            {
                instance->DoUseDoorOrButton(instance->GetData64(GO_MAIN_GATE_DOOR));
                instance->SetData(TYPE_NORTHREND_BEASTS, FAIL);
                me->DespawnOrUnsummon();
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                {
                    instance->SetData(DATA_TRIBUTE_TO_IMMORTALITY_ELIGIBLE, 0);
                }
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
                                    me->GetMotionMaster()->MoveJump(ToCCommonLoc[1].GetPositionX(), ToCCommonLoc[1].GetPositionY(), ToCCommonLoc[1].GetPositionZ(), 20.0f, 20.0f, 0); // 1: Middle of the room
                                    SetCombatMovement(false);
                                    me->AttackStop();
                                    _stage = 7; //Invalid (Do nothing more than move)
                                    return;
                                default:
                                    break;
                            }
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
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE);
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
                                        me->GetMotionMaster()->MoveJump(2*me->GetPositionX() - _trampleTargetX, 2*me->GetPositionY() - _trampleTargetY, me->GetPositionZ(), 30.0f, 20.0f, 0);
                                        _stage = 7; //Invalid (Do nothing more than move)
                                    }
                                    else
                                        _stage = 6;
                                    break;
                                }
                                default:
                                    break;
                            }
                        }
                        break;
                    case 4:
                        me->StopMoving();
                        me->AttackStop();
                        if (Player* target = ObjectAccessor::GetPlayer(*me, _trampleTargetGUID))
                            Talk(EMOTE_TRAMPLE_START, target);
                        me->GetMotionMaster()->MoveCharge(_trampleTargetX, _trampleTargetY, _trampleTargetZ, 42, 1);
                        me->SetTarget(0);
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
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE);
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
                uint64 _trampleTargetGUID;
                bool   _movementStarted;
                bool   _movementFinish;
                bool   _trampleCast;
                uint8  _stage;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<boss_icehowlAI>(creature);
        }
};

void AddSC_boss_northrend_beasts()
{
    new boss_gormok();
    new npc_snobold_vassal();
    new npc_firebomb();
    new spell_gormok_fire_bomb();

    new boss_acidmaw();
    new boss_dreadscale();
    new npc_slime_pool();

    new boss_icehowl();
}
