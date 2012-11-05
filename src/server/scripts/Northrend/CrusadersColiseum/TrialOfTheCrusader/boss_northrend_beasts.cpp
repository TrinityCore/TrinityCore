/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
    ACTION_ENABLE_FIRE_BOMB = 1,
    ACTION_DISABLE_FIRE_BOMB
};

class boss_gormok : public CreatureScript
{
    enum Events
    {
        EVENT_IMPALE                = 1,
        EVENT_STAGGERING_STOMP,
        EVENT_THROW
    };

    public:
        boss_gormok() : CreatureScript("boss_gormok") { }

        struct boss_gormokAI : public BossAI
        {
            boss_gormokAI(Creature* creature) : BossAI(creature, BOSS_BEASTS)
            {
            }

            void Reset()
            {
                events.ScheduleEvent(EVENT_IMPALE, urand(8*IN_MILLISECONDS, 10*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_STAGGERING_STOMP, 15*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_THROW, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS));

                summons.DespawnAll();
            }

            void EnterEvadeMode()
            {
                instance->DoUseDoorOrButton(instance->GetData64(GO_MAIN_GATE_DOOR));
                ScriptedAI::EnterEvadeMode();
            }

            void MovementInform(uint32 type, uint32 pointId)
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

            void JustDied(Unit* /*killer*/)
            {
                if (instance)
                    instance->SetData(TYPE_NORTHREND_BEASTS, GORMOK_DONE);
            }

            void JustReachedHome()
            {
                if (instance)
                {
                    instance->DoUseDoorOrButton(instance->GetData64(GO_MAIN_GATE_DOOR));
                    instance->SetData(TYPE_NORTHREND_BEASTS, FAIL);
                }
                me->DespawnOrUnsummon();
            }

            void EnterCombat(Unit* /*who*/)
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

            void DamageTaken(Unit* /*who*/, uint32& damage)
            {
                // despawn the remaining passengers on death
                if (damage >= me->GetHealth())
                    for (uint8 i = 0; i < MAX_SNOBOLDS; ++i)
                        if (Unit* pSnobold = me->GetVehicleKit()->GetPassenger(i))
                            pSnobold->ToCreature()->DespawnOrUnsummon();
            }

            void UpdateAI(uint32 const diff)
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

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_gormokAI(creature);
        }
};

class mob_snobold_vassal : public CreatureScript
{
    enum MyEvents
    {
        EVENT_FIRE_BOMB = 1,
        EVENT_BATTER,
        EVENT_HEAD_CRACK
    };

    public:
        mob_snobold_vassal() : CreatureScript("mob_snobold_vassal") { }

        struct mob_snobold_vassalAI : public ScriptedAI
        {
            mob_snobold_vassalAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
                if (instance)
                    instance->SetData(DATA_SNOBOLD_COUNT, INCREASE);
            }

            void Reset()
            {
                events.ScheduleEvent(EVENT_BATTER, 5*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_HEAD_CRACK, 25*IN_MILLISECONDS);

                m_uiTargetGUID = 0;
                m_bTargetDied = false;

                if (instance)
                    m_uiBossGUID = instance->GetData64(NPC_GORMOK);
                //Workaround for Snobold
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            }

            void EnterEvadeMode()
            {
                ScriptedAI::EnterEvadeMode();
            }

            void EnterCombat(Unit* who)
            {
                m_uiTargetGUID = who->GetGUID();
                me->TauntApply(who);
                DoCast(who, SPELL_SNOBOLLED);
            }

            void DamageTaken(Unit* pDoneBy, uint32 &uiDamage)
            {
                if (pDoneBy->GetGUID() == m_uiTargetGUID)
                    uiDamage = 0;
            }

            void MovementInform(uint32 type, uint32 pointId)
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                switch (pointId)
                {
                    case 0:
                        if (m_bTargetDied)
                            me->DespawnOrUnsummon();
                        break;
                    default:
                        break;
                }
            }

            void JustDied(Unit* /*killer*/)
            {
                if (Unit* target = Unit::GetPlayer(*me, m_uiTargetGUID))
                    if (target->isAlive())
                        target->RemoveAurasDueToSpell(SPELL_SNOBOLLED);
                if (instance)
                    instance->SetData(DATA_SNOBOLD_COUNT, DECREASE);
            }

            void DoAction(int32 const action)
            {
                switch (action)
                {
                    case ACTION_ENABLE_FIRE_BOMB:
                        events.ScheduleEvent(EVENT_FIRE_BOMB, urand(5*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                        break;
                    case ACTION_DISABLE_FIRE_BOMB:
                        events.CancelEvent(EVENT_FIRE_BOMB);
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim() || m_bTargetDied)
                    return;

                if (Unit* target = Unit::GetPlayer(*me, m_uiTargetGUID))
                {
                    if (!target->isAlive())
                    {
                        if (instance)
                        {
                            Unit* gormok = ObjectAccessor::GetCreature(*me, instance->GetData64(NPC_GORMOK));
                            if (gormok && gormok->isAlive())
                            {
                                SetCombatMovement(false);
                                m_bTargetDied = true;

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
                                m_uiTargetGUID = target2->GetGUID();
                                me->GetMotionMaster()->MoveJump(target2->GetPositionX(), target2->GetPositionY(), target2->GetPositionZ(), 15.0f, 15.0f);
                            }
                        }
                    }
                }

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FIRE_BOMB:
                            if (me->GetVehicleBase())
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, -me->GetVehicleBase()->GetCombatReach(), true))
                                    me->CastSpell(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), SPELL_FIRE_BOMB, true);
                            events.ScheduleEvent(EVENT_FIRE_BOMB, 20*IN_MILLISECONDS);
                            return;
                        case EVENT_HEAD_CRACK:
                            // commented out while SPELL_SNOBOLLED gets fixed
                            //if (Unit* target = Unit::GetPlayer(*me, m_uiTargetGUID))
                            DoCastVictim(SPELL_HEAD_CRACK);
                            events.ScheduleEvent(EVENT_HEAD_CRACK, 30*IN_MILLISECONDS);
                            return;
                        case EVENT_BATTER:
                            // commented out while SPELL_SNOBOLLED gets fixed
                            //if (Unit* target = Unit::GetPlayer(*me, m_uiTargetGUID))
                            DoCastVictim(SPELL_BATTER);
                            events.ScheduleEvent(EVENT_BATTER, 10*IN_MILLISECONDS);
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
                EventMap events;
                InstanceScript* instance;
                uint64 m_uiBossGUID;
                uint64 m_uiTargetGUID;
                bool   m_bTargetDied;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_snobold_vassalAI(creature);
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
                instanceScript = creature->GetInstanceScript();
            }

            void Reset()
            {
                DoCast(me, SPELL_FIRE_BOMB_DOT, true);
                SetCombatMovement(false);
                me->SetReactState(REACT_PASSIVE);
                me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
            }

            void UpdateAI(uint32 const /*diff*/)
            {
                if (instanceScript->GetData(TYPE_NORTHREND_BEASTS) != GORMOK_IN_PROGRESS)
                    me->DespawnOrUnsummon();
            }

            private:
                InstanceScript* instanceScript;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_firebombAI(creature);
        }
};

struct boss_jormungarAI : public BossAI
{
    enum Phases
    {
        PHASE_MOBILE            = 0,
        PHASE_STATIONARY,
        PHASE_SUBMERGED
    };

    enum
    {
        EVENT_BITE = 1,
        EVENT_SPEW,
        EVENT_SLIME_POOL,
        EVENT_SPIT,
        EVENT_SPRAY,
        EVENT_SWEEP,
        EVENT_SUBMERGE,
        EVENT_EMERGE,
        EVENT_SUMMON_ACIDMAW
    };

    boss_jormungarAI(Creature* creature) : BossAI(creature, BOSS_BEASTS)
    {
    }

    void Reset()
    {
        enraged = false;

        events.ScheduleEvent(EVENT_SPIT, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS), PHASE_STATIONARY);
        events.ScheduleEvent(EVENT_SPRAY, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS), PHASE_STATIONARY);
        events.ScheduleEvent(EVENT_SWEEP, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS), PHASE_STATIONARY);
        events.ScheduleEvent(EVENT_BITE, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS), PHASE_MOBILE);
        events.ScheduleEvent(EVENT_SPEW, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS), PHASE_MOBILE);
        events.ScheduleEvent(EVENT_SLIME_POOL, 15*IN_MILLISECONDS, PHASE_MOBILE);
    }

    void JustDied(Unit* /*killer*/)
    {
        if (instance)
        {
            if (Creature* otherWorm = Unit::GetCreature(*me, instance->GetData64(otherWormEntry)))
            {
                if (!otherWorm->isAlive())
                {
                    instance->SetData(TYPE_NORTHREND_BEASTS, SNAKES_DONE);

                    me->DespawnOrUnsummon();
                    otherWorm->DespawnOrUnsummon();
                }
                else
                    instance->SetData(TYPE_NORTHREND_BEASTS, SNAKES_SPECIAL);
            }
        }
    }

    void JustReachedHome()
    {
        // prevent losing 2 attempts at once on heroics
        if (instance && instance->GetData(TYPE_NORTHREND_BEASTS) != FAIL)
            instance->SetData(TYPE_NORTHREND_BEASTS, FAIL);

        me->DespawnOrUnsummon();
    }

    void KilledUnit(Unit* who)
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            if (instance)
                instance->SetData(DATA_TRIBUTE_TO_IMMORTALITY_ELEGIBLE, 0);
    }

    void EnterCombat(Unit* /*who*/)
    {
        _EnterCombat();
        me->SetInCombatWithZone();
        if (instance)
            instance->SetData(TYPE_NORTHREND_BEASTS, SNAKES_IN_PROGRESS);
    }

    void UpdateAI(uint32 const diff)
    {
        if (!UpdateVictim())
            return;

        if (!enraged && instance && instance->GetData(TYPE_NORTHREND_BEASTS) == SNAKES_SPECIAL)
        {
            me->RemoveAurasDueToSpell(SPELL_SUBMERGE_0);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            DoCast(SPELL_ENRAGE);
            enraged = true;
            Talk(EMOTE_ENRAGE);
        }

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        switch (phase)
        {
            case PHASE_SUBMERGED:
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_EMERGE:
                            Emerge();
                            return;
                        default:
                            return;
                    }
                }
            case PHASE_MOBILE:
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SUBMERGE:
                            Submerge();
                            return;
                        case EVENT_BITE:
                            DoCastVictim(biteSpell);
                            events.ScheduleEvent(EVENT_BITE, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS), 0, PHASE_MOBILE);
                            return;
                        case EVENT_SPEW:
                            DoCastAOE(spewSpell);
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
                        default:
                            return;
                    }
                }
                DoMeleeAttackIfReady();
                return;
            case PHASE_STATIONARY:
            {
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SUBMERGE:
                            Submerge();
                            return;
                        case EVENT_SPRAY:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(target, spraySpell);
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
                DoSpellAttackIfReady(spitSpell);
                return;
            }
            default:
                break;
        }
    }


    void Submerge()
    {
        DoCast(me, SPELL_SUBMERGE_0);
        me->RemoveAurasDueToSpell(SPELL_EMERGE_0);
        me->SetInCombatWithZone();
        phase = PHASE_SUBMERGED;
        events.ScheduleEvent(EVENT_EMERGE, 5*IN_MILLISECONDS, 0, PHASE_SUBMERGED);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
        me->GetMotionMaster()->MovePoint(0, ToCCommonLoc[1].GetPositionX()+ frand(-40.0f, 40.0f), ToCCommonLoc[1].GetPositionY() + frand(-40.0f, 40.0f), ToCCommonLoc[1].GetPositionZ());
        wasMobile = !wasMobile;
    }

    void Emerge()
    {
        DoCast(me, SPELL_EMERGE_0);
        me->SetDisplayId(modelMobile);
        me->RemoveAurasDueToSpell(SPELL_SUBMERGE_0);
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
        me->GetMotionMaster()->Clear();

        // if the worm was mobile before submerging, make him stationary now
        if (wasMobile)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            SetCombatMovement(false);
            me->SetDisplayId(modelStationary);
            phase = PHASE_STATIONARY;
            events.DelayEvents(45*IN_MILLISECONDS, 2);
            events.ScheduleEvent(EVENT_SUBMERGE, 45*IN_MILLISECONDS, 0, PHASE_STATIONARY);
            events.ScheduleEvent(EVENT_SPIT, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS), PHASE_STATIONARY);
            events.ScheduleEvent(EVENT_SPRAY, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS), PHASE_STATIONARY);
            events.ScheduleEvent(EVENT_SWEEP, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS), PHASE_STATIONARY);
        }
        else
        {
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            SetCombatMovement(true);
            me->GetMotionMaster()->MoveChase(me->getVictim());
            me->SetDisplayId(modelMobile);
            phase = PHASE_MOBILE;
            events.DelayEvents(45*IN_MILLISECONDS, 1);
            events.ScheduleEvent(EVENT_SUBMERGE, 45*IN_MILLISECONDS, 0, PHASE_MOBILE);
            events.ScheduleEvent(EVENT_BITE, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS), PHASE_MOBILE);
            events.ScheduleEvent(EVENT_SPEW, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS), PHASE_MOBILE);
            events.ScheduleEvent(EVENT_SLIME_POOL, 15*IN_MILLISECONDS, PHASE_MOBILE);
        }
    }

    protected:
        uint32 otherWormEntry;
        uint32 modelStationary;
        uint32 modelMobile;

        uint32 biteSpell;
        uint32 spewSpell;
        uint32 spitSpell;
        uint32 spraySpell;

        Phases phase;
        bool enraged;
        bool wasMobile;
};

class boss_acidmaw : public CreatureScript
{
    public:
        boss_acidmaw() : CreatureScript("boss_acidmaw") { }

        struct boss_acidmawAI : public boss_jormungarAI
        {
            boss_acidmawAI(Creature* creature) : boss_jormungarAI(creature) { }

            void Reset()
            {
                boss_jormungarAI::Reset();
                biteSpell = SPELL_PARALYTIC_BITE;
                spewSpell = SPELL_ACID_SPEW;
                spitSpell = SPELL_ACID_SPIT;
                spraySpell = SPELL_PARALYTIC_SPRAY;
                modelStationary = MODEL_ACIDMAW_STATIONARY;
                modelMobile = MODEL_ACIDMAW_MOBILE;
                otherWormEntry = NPC_DREADSCALE;

                wasMobile = true;
                Emerge();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_acidmawAI(creature);
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
                instanceScript = creature->GetInstanceScript();
            }

            void Reset()
            {
                boss_jormungarAI::Reset();
                biteSpell = SPELL_BURNING_BITE;
                spewSpell = SPELL_MOLTEN_SPEW;
                spitSpell = SPELL_FIRE_SPIT;
                spraySpell = SPELL_BURNING_SPRAY;
                modelStationary = MODEL_DREADSCALE_STATIONARY;
                modelMobile = MODEL_DREADSCALE_MOBILE;
                otherWormEntry = NPC_ACIDMAW;

                phase = PHASE_MOBILE;
                events.ScheduleEvent(EVENT_SUMMON_ACIDMAW, 3*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SUBMERGE, 45*IN_MILLISECONDS, 0, PHASE_MOBILE);
                wasMobile = false;
            }

            void MovementInform(uint32 type, uint32 pointId)
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                switch (pointId)
                {
                    case 0:
                        instanceScript->DoUseDoorOrButton(instanceScript->GetData64(GO_MAIN_GATE_DOOR));
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->SetInCombatWithZone();
                        break;
                    default:
                        break;
                }
            }

            void EnterEvadeMode()
            {
                instanceScript->DoUseDoorOrButton(instanceScript->GetData64(GO_MAIN_GATE_DOOR));
                boss_jormungarAI::EnterEvadeMode();
            }

            void JustReachedHome()
            {
                if (instanceScript)
                    instanceScript->DoUseDoorOrButton(instanceScript->GetData64(GO_MAIN_GATE_DOOR));

                boss_jormungarAI::JustReachedHome();
            }
            private:
                InstanceScript* instanceScript;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_dreadscaleAI(creature);
        }
};

class mob_slime_pool : public CreatureScript
{
    public:
        mob_slime_pool() : CreatureScript("mob_slime_pool") { }

        struct mob_slime_poolAI : public ScriptedAI
        {
            mob_slime_poolAI(Creature* creature) : ScriptedAI(creature)
            {
                instanceScript = creature->GetInstanceScript();
            }

            void Reset()
            {
                casted = false;
                me->SetReactState(REACT_PASSIVE);
            }

            void UpdateAI(uint32 const /*diff*/)
            {
                if (!casted)
                {
                    casted = true;
                    DoCast(me, SPELL_SLIME_POOL_EFFECT);
                }

                if (instanceScript->GetData(TYPE_NORTHREND_BEASTS) != SNAKES_IN_PROGRESS && instanceScript->GetData(TYPE_NORTHREND_BEASTS) != SNAKES_SPECIAL)
                    me->DespawnOrUnsummon();
            }
            private:
                InstanceScript* instanceScript;
                bool casted;

        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_slime_poolAI(creature);
        }
};

class spell_gormok_fire_bomb : public SpellScriptLoader
{
    public:
        spell_gormok_fire_bomb() : SpellScriptLoader("spell_gormok_fire_bomb") {}

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

            void Register()
            {
                OnEffectHit += SpellEffectFn(spell_gormok_fire_bomb_SpellScript::TriggerFireBomb, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_gormok_fire_bomb_SpellScript();
        }
};

class boss_icehowl : public CreatureScript
{
    enum
    {
        EVENT_FEROCIOUS_BUTT = 1,
        EVENT_MASSIVE_CRASH,
        EVENT_WHIRL,
        EVENT_ARCTIC_BREATH,
        EVENT_TRAMPLE
    };

    public:
        boss_icehowl() : CreatureScript("boss_icehowl") { }

        struct boss_icehowlAI : public BossAI
        {
            boss_icehowlAI(Creature* creature) : BossAI(creature, BOSS_BEASTS)
            {
            }

            void Reset()
            {
                events.ScheduleEvent(EVENT_FEROCIOUS_BUTT, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_ARCTIC_BREATH, urand(15*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_WHIRL, urand(15*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_MASSIVE_CRASH, 30*IN_MILLISECONDS);
                m_bMovementStarted = false;
                m_bMovementFinish = false;
                m_bTrampleCasted = false;
                m_uiTrampleTargetGUID = 0;
                m_fTrampleTargetX = 0;
                m_fTrampleTargetY = 0;
                m_fTrampleTargetZ = 0;
                m_uiStage = 0;
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                if (instance)
                    instance->SetData(TYPE_NORTHREND_BEASTS, ICEHOWL_DONE);
            }

            void MovementInform(uint32 type, uint32 pointId)
            {
                if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                    return;

                switch (pointId)
                {
                    case 0:
                        if (m_uiStage != 0)
                        {
                            if (me->GetDistance2d(ToCCommonLoc[1].GetPositionX(), ToCCommonLoc[1].GetPositionY()) < 6.0f)
                                // Middle of the room
                                m_uiStage = 1;
                            else
                            {
                                // Landed from Hop backwards (start trample)
                                if (Unit::GetPlayer(*me, m_uiTrampleTargetGUID))
                                    m_uiStage = 4;
                                else
                                    m_uiStage = 6;
                            }
                        }
                        break;
                    case 1: // Finish trample
                        m_bMovementFinish = true;
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

            void EnterEvadeMode()
            {
                instance->DoUseDoorOrButton(instance->GetData64(GO_MAIN_GATE_DOOR));
                ScriptedAI::EnterEvadeMode();
            }

            void JustReachedHome()
            {
                if (instance)
                {
                    instance->DoUseDoorOrButton(instance->GetData64(GO_MAIN_GATE_DOOR));
                    instance->SetData(TYPE_NORTHREND_BEASTS, FAIL);
                }
                me->DespawnOrUnsummon();
            }

            void KilledUnit(Unit* who)
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                {
                    if (instance)
                        instance->SetData(DATA_TRIBUTE_TO_IMMORTALITY_ELEGIBLE, 0);
                }
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                if (instance)
                    instance->SetData(TYPE_NORTHREND_BEASTS, ICEHOWL_IN_PROGRESS);
            }

            void SpellHitTarget(Unit* target, SpellInfo const* spell)
            {
                if (spell->Id == SPELL_TRAMPLE && target->GetTypeId() == TYPEID_PLAYER)
                {
                    if (!m_bTrampleCasted)
                    {
                        DoCast(me, SPELL_FROTHING_RAGE, true);
                        m_bTrampleCasted = true;
                    }
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                switch (m_uiStage)
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
                                    me->GetMotionMaster()->MoveJump(ToCCommonLoc[1].GetPositionX(), ToCCommonLoc[1].GetPositionY(), ToCCommonLoc[1].GetPositionZ(), 20.0f, 20.0f); // 1: Middle of the room
                                    SetCombatMovement(false);
                                    me->AttackStop();
                                    m_uiStage = 7; //Invalid (Do nothing more than move)
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
                        m_uiStage = 2;
                        break;
                    case 2:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        {
                            me->StopMoving();
                            me->AttackStop();
                            m_uiTrampleTargetGUID = target->GetGUID();
                            me->SetTarget(m_uiTrampleTargetGUID);
                            m_bTrampleCasted = false;
                            SetCombatMovement(false);
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE);
                            me->GetMotionMaster()->Clear();
                            me->GetMotionMaster()->MoveIdle();
                            events.ScheduleEvent(EVENT_TRAMPLE, 4*IN_MILLISECONDS);
                            m_uiStage = 3;
                        }
                        else
                            m_uiStage = 6;
                        break;
                    case 3:
                        while (uint32 eventId = events.ExecuteEvent())
                        {
                            switch (eventId)
                            {
                                case EVENT_TRAMPLE:
                                {
                                    if (Unit* target = Unit::GetPlayer(*me, m_uiTrampleTargetGUID))
                                    {
                                        me->StopMoving();
                                        me->AttackStop();
                                        m_bTrampleCasted = false;
                                        m_bMovementStarted = true;
                                        m_fTrampleTargetX = target->GetPositionX();
                                        m_fTrampleTargetY = target->GetPositionY();
                                        m_fTrampleTargetZ = target->GetPositionZ();
                                        // 2: Hop Backwards
                                        me->GetMotionMaster()->MoveJump(2*me->GetPositionX() - m_fTrampleTargetX, 2*me->GetPositionY() - m_fTrampleTargetY, me->GetPositionZ(), 30.0f, 20.0f);
                                        m_uiStage = 7; //Invalid (Do nothing more than move)
                                    }
                                    else
                                        m_uiStage = 6;
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
                        Talk(EMOTE_TRAMPLE_START, m_uiTrampleTargetGUID);
                        me->GetMotionMaster()->MoveCharge(m_fTrampleTargetX, m_fTrampleTargetY, m_fTrampleTargetZ, 42, 1);
                        me->SetTarget(0);
                        m_uiStage = 5;
                        break;
                    case 5:
                        if (m_bMovementFinish)
                        {
                            DoCastAOE(SPELL_TRAMPLE);
                            m_bMovementFinish = false;
                            m_uiStage = 6;
                            return;
                        }
                        if (events.ExecuteEvent() == EVENT_TRAMPLE)
                        {
                            Map::PlayerList const &lPlayers = me->GetMap()->GetPlayers();
                            for (Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
                            {
                                if (Unit* player = itr->getSource())
                                {
                                    if (player->isAlive() && player->IsWithinDistInMap(me, 6.0f))
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
                        if (!m_bTrampleCasted)
                        {
                            DoCast(me, SPELL_STAGGERED_DAZE);
                            Talk(EMOTE_TRAMPLE_CRASH);
                        }
                        else
                        {
                            DoCast(me, SPELL_FROTHING_RAGE, true);
                            Talk(EMOTE_TRAMPLE_FAIL);
                        }
                        m_bMovementStarted = false;
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_DISABLE_MOVE);
                        SetCombatMovement(true);
                        me->GetMotionMaster()->MovementExpired();
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MoveChase(me->getVictim());
                        AttackStart(me->getVictim());
                        events.ScheduleEvent(EVENT_MASSIVE_CRASH, 40*IN_MILLISECONDS);
                        events.ScheduleEvent(EVENT_ARCTIC_BREATH, urand(15*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                        m_uiStage = 0;
                        break;
                    default:
                        break;
                }
            }

            private:
                float  m_fTrampleTargetX, m_fTrampleTargetY, m_fTrampleTargetZ;
                uint64 m_uiTrampleTargetGUID;
                bool   m_bMovementStarted;
                bool   m_bMovementFinish;
                bool   m_bTrampleCasted;
                uint8  m_uiStage;
                Unit*  target;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_icehowlAI(creature);
        }
};

void AddSC_boss_northrend_beasts()
{
    new boss_gormok();
    new mob_snobold_vassal();
    new npc_firebomb();
    new spell_gormok_fire_bomb();

    new boss_acidmaw();
    new boss_dreadscale();
    new mob_slime_pool();

    new boss_icehowl();
}
