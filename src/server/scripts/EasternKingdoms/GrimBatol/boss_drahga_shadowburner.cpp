/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2010-2011 Project Trinity <http://www.projecttrinity.org/>
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
#include "grim_batol.h"
#include "Vehicle.h"

enum Yells
{
    SAY_AGGRO     = 0,
    SAY_SUMMON    = 1,
    SAY_SUMMON2   = 2,
    SAY_JUMP_DOWN = 3,
    SAY_DEAD      = 4,
    SAY_VALIONA   = 5,
    SAY_KILL      = 6,
    SAY_KILL1     = 7
};

enum Spells
{
    // Drahgas Spells
    SPELL_BURNING_SHADOWBOLT    = 75245,
    SPELL_BURNING_SHADOWBOLT_H    = 90915,

    SPELL_INVOCATION_OF_FLAME    = 75218, // Summons Trigger at Random Location
    SPELL_INVOCATION_TRIGGER    = 75222, // Summons & Visual is casted by the Trigger

    SPELL_TWILIGHT_PROTECTION    = 76303,

    // Valionas Spells
    SPELL_VALIONAS_FLAME        = 75321,
    SPELL_SHREDDING_SWIPE        = 75271,
    SPELL_SEEPING_TWILIGHT        = 75318, // wowhead says 75317 but this spell gives the visual aura
    SPELL_DEVOURING_FLAMES_H    = 90950,
    SPELL_TWILIGHT_SHIFT        = 75328,

    // Invoked Flame Spirits Spells
    SPELL_AURA_NOVA                = 75235,
    SPELL_CONCENTRATE_FIRE_AURA    = 82850,

    SPELL_SUPERNOVA                = 75238,
    SPELL_SUPERNOVA_H              = 90972,
};

enum Phase
{
    PHASE_CASTER_PHASE             = 1,
    PHASE_DRAGON_PHASE             = 2,
    PHASE_FINAL_PHASE              = 3,
    PHASE_NON                      = 4,
};

enum Events
{
    EVENT_BURNING_SHADOWBOLT          = 1,
    EVENT_SUMMON_INVOKED_FLAME_SPIRIT = 2,
    EVENT_VALIONAS_FLAME              = 3,
    EVENT_SHREDDING_SWIPE             = 4,
    EVENT_SEEPING_TWILIGHT            = 5,
    EVENT_DEVOURING_FLAMES            = 6,
    EVENT_DRAGAH_ENTER_VEHICLE        = 7,
};

enum Actions
{
    ACTION_DRAGAH_CALLS_VALIONA_FOR_HELP  = 1,
    ACTION_VALIONA_SHOULD_FLY_AWAY        = 2,
    ACTION_DRAGAH_IS_ON_THE_GROUND           = 3,
};

enum Points
{
    POINT_VALIONA_FLY_IN_THE_AIR          = 1,
    POINT_VALIONA_LAND                    = 2,
    POINT_VALIONA_FLY_AWAY                = 3,
    POINT_VALIONA_IS_AWAY                 = 4,
    POINT_DRAHGA_GO_TO_THE_LAVA           = 5,
};

Position const position[5] =
{
    {-400.613f, -671.578f, 265.896f, 0.102f},    // Drahga Point from who he jump down
    {-388.189f, -668.078f, 280.316f, 3.470f},    // Valionas Way to the Platform
    {-435.54f, -695.072f, 280.316f, 3.4010f},
    {-435.54f, -695.072f, 268.687f, 3.4010f},    // Valiona first land Position
    {-375.742f, -519.749f, 300.663f, 0.0f}        // Valionas End Position
};

class boss_drahga_shadowburner : public CreatureScript
{
public:
    boss_drahga_shadowburner() : CreatureScript("boss_drahga_shadowburner") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_drahga_shadowburnerAI (creature);
    }

    struct boss_drahga_shadowburnerAI : public ScriptedAI
    {
        boss_drahga_shadowburnerAI(Creature* creature) : ScriptedAI(creature), summons(creature)
        {
            pInstance = creature->GetInstanceScript();
        }

        void Reset() override
        {
            valionaGUID = ObjectGuid::Empty;
            phase = PHASE_NON;
            summons.DespawnAll();
            DespawnFlameSpirit();
            if (pInstance)
                pInstance->SetData(DATA_DRAHGA_SHADOWBURNER_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*pWho*/) override
        {
            phase = PHASE_CASTER_PHASE;
            me->SetReactState(REACT_AGGRESSIVE);
            Talk(0);
            me->GetMotionMaster()->Clear();
            me->GetMotionMaster()->MoveChase(me->GetVictim());
            events.ScheduleEvent(EVENT_BURNING_SHADOWBOLT, 4000);
            events.ScheduleEvent(EVENT_SUMMON_INVOKED_FLAME_SPIRIT, 10000);
        }

        void DespawnFlameSpirit()
        {
            std::list<Creature*> cList;
            me->GetCreatureListWithEntryInGrid(cList, NPC_INVOKED_FLAMING_SPIRIT, 200.0f);
            if(!cList.empty())
                for(std::list<Creature*>::const_iterator itr = cList.begin(); itr != cList.end(); ++itr)
                    (*itr)->DespawnOrUnsummon();
        }

        void JustSummoned(Creature* summon) override
        {
            if(summon->GetEntry() == NPC_INVOCATION_OF_THE_FLAME_STALKER)
            {
                summon->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_NOT_SELECTABLE);
                summon->AI()->DoCast(SPELL_INVOCATION_TRIGGER);
            }
            summon->SetInCombatWithZone();
        }

        void JustDied(Unit* /*victim*/) override
        {
            events.Reset();
            summons.DespawnAll();
            DespawnFlameSpirit();
            Talk(2);
            if (pInstance)
                pInstance->SetData(DATA_DRAHGA_SHADOWBURNER_EVENT, DONE);
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == POINT_MOTION_TYPE)
            {
                switch (id)
                {
                    case POINT_DRAHGA_GO_TO_THE_LAVA:
                        Talk(1);
                        if (Creature *valiona = ObjectAccessor::GetCreature(*me,  valionaGUID))
                        {
                            valiona->GetAI()->DoAction(ACTION_DRAGAH_CALLS_VALIONA_FOR_HELP);
                            me->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 1, valiona, false);
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        }
                        events.ScheduleEvent(EVENT_DRAGAH_ENTER_VEHICLE,2000);
                        break;
                     default:
                         break;
                }
            }
        }

        void DoAction(const int32 action) override
        {
            switch(action)
            {
               case ACTION_DRAGAH_IS_ON_THE_GROUND:
                   me->SetReactState(REACT_AGGRESSIVE);
                   //                   me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                   events.ScheduleEvent(EVENT_BURNING_SHADOWBOLT, 4000);
                   events.ScheduleEvent(EVENT_SUMMON_INVOKED_FLAME_SPIRIT, 10000);
                   break;
                case ACTION_VALIONA_SHOULD_FLY_AWAY:
                    phase = PHASE_FINAL_PHASE;
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->RemoveAllAuras();
                    valionaGUID = ObjectGuid::Empty;
                    break;
                default:
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (phase == PHASE_CASTER_PHASE && !HealthAbovePct(30))
            {
                phase = PHASE_DRAGON_PHASE;
                me->SetSpeed(MOVE_RUN, 1.5f);
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->RemoveAllAuras(); // He should not die when he is jumping down...
                DoCast(me, SPELL_TWILIGHT_PROTECTION, true);
                events.Reset(); // He Should not cast while he is flying
                me->GetMotionMaster()->MovePoint(POINT_DRAHGA_GO_TO_THE_LAVA, position[0]);
                if (Creature *valiona = me->SummonCreature(NPC_VALIONA, -375.33f, -667.291f, 250.0f, 3.29545f, TEMPSUMMON_CORPSE_DESPAWN))
                    valionaGUID = valiona->GetGUID();
            }

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_BURNING_SHADOWBOLT:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, RAID_MODE(SPELL_BURNING_SHADOWBOLT,SPELL_BURNING_SHADOWBOLT_H));
                        events.ScheduleEvent(EVENT_BURNING_SHADOWBOLT,4000);
                        break;
                    case EVENT_SUMMON_INVOKED_FLAME_SPIRIT:
                        Talk(2);
                        DoCast(SPELL_INVOCATION_OF_FLAME);
                        events.ScheduleEvent(EVENT_SUMMON_INVOKED_FLAME_SPIRIT,20000);
                        break;
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

    private:
        InstanceScript* pInstance;
        Phase phase;
        EventMap events;
        SummonList summons;

        ObjectGuid valionaGUID;
    };
};

class mob_valiona_gb : public CreatureScript
{
public:
    mob_valiona_gb() : CreatureScript("mob_valiona_gb") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_valiona_gbAI (creature);
    }

    struct mob_valiona_gbAI : public ScriptedAI
    {
        mob_valiona_gbAI(Creature* creature) : ScriptedAI(creature), summons(creature)
        {
            pInstance = creature->GetInstanceScript();
        }

        void Reset() override
        {
            SetCombatMovement(false);
            me->SetSpeed(MOVE_WALK, 3.0f);
            me->SetCanFly(true);
            events.Reset();
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            dragahGUID = ObjectGuid::Empty;
        }

        void EnterCombat(Unit* /*pWho*/) override { }

        void DamageTaken(Unit* /*done_by*/, uint32& /*damage*/) override
        {
            if (!HealthAbovePct(20))
            {
                me->GetVehicleKit()->RemoveAllPassengers();
                if (Creature *dragah = ObjectAccessor::GetCreature(*me, dragahGUID))
                    dragah->AI()->DoAction(ACTION_VALIONA_SHOULD_FLY_AWAY);
                DoAction(ACTION_VALIONA_SHOULD_FLY_AWAY);
            }
        }

        void JustSummoned(Creature* summon) override
        {
            summon->setActive(true);
            if(summon->GetEntry() == NPC_SEEPING_TWILIGHT_TRIGGER)
            {
                summon->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_NOT_SELECTABLE);
                summon->GetAI()->DoCast(SPELL_SEEPING_TWILIGHT);
            }
            if(me->IsInCombat())
                summon->AI()->DoZoneInCombat();
        }

        void IsSummonedBy(Unit* summoner) override
        {
            dragahGUID = summoner->GetGUID();
            me->SetReactState(REACT_PASSIVE);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() || me-> HasUnitState(UNIT_STATE_CASTING))
                return;
            events.Update(diff);
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_VALIONAS_FLAME:
                        if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, SPELL_VALIONAS_FLAME);
                        events.Repeat(urand(15000,25000));
                        break;
                    case EVENT_SHREDDING_SWIPE:
                        if(me->GetVictim())
                            DoCastVictim(SPELL_SHREDDING_SWIPE);
                        events.Repeat(urand(21000,30000));
                        break;
                    case EVENT_DEVOURING_FLAMES:
                        DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0), SPELL_DEVOURING_FLAMES_H);
                        events.Repeat(urand(30000,35000));
                        break;
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

        void DoAction(const int32 action) override
        {
            switch(action)
            {
                case ACTION_DRAGAH_CALLS_VALIONA_FOR_HELP:
                    DoZoneInCombat();
                    Talk(0);
                    currentWaypoint = 1;
                    me->GetMotionMaster()->MovePoint(POINT_VALIONA_FLY_IN_THE_AIR, position[1]);
                    break;
                case ACTION_VALIONA_SHOULD_FLY_AWAY:
                    SetCombatMovement(false);
                    events.Reset();
                    me->RemoveAllAuras();
                    DoCast(me, SPELL_TWILIGHT_SHIFT, true);
                    me->SetReactState(REACT_PASSIVE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    me->SetCanFly(true);
                    me->GetMotionMaster()->MovePoint(POINT_VALIONA_FLY_AWAY, position[1]);
                    break;
                default:
                    break;
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            switch (id)
            {
                case POINT_VALIONA_FLY_IN_THE_AIR:
                    currentWaypoint++;
                    if (currentWaypoint < 3)
                        me->GetMotionMaster()->MovePoint(POINT_VALIONA_FLY_IN_THE_AIR, position[currentWaypoint]);
                    else
                        me->GetMotionMaster()->MovePoint(POINT_VALIONA_LAND, position[3]);
                    break;
                case POINT_VALIONA_LAND:
                    SetCombatMovement(true);
                    me->SetReactState(REACT_AGGRESSIVE);
                    if (Creature *dragah = ObjectAccessor::GetCreature(*me, dragahGUID))
                        dragah->GetAI()->DoAction(ACTION_DRAGAH_IS_ON_THE_GROUND);
                    me->SetSpeed(MOVE_WALK, 1.0f);
                    me->SetCanFly(false);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MoveChase(me->GetVictim());
                    events.ScheduleEvent(EVENT_VALIONAS_FLAME, urand(4000,7000));
                    events.ScheduleEvent(EVENT_SHREDDING_SWIPE, urand(10000,13000));
                    if (IsHeroic())
                        events.ScheduleEvent(EVENT_DEVOURING_FLAMES, urand(15000,17000));
                    break;
                case POINT_VALIONA_FLY_AWAY:
                    DespawnCreatures(NPC_SEEPING_TWILIGHT_TRIGGER,500.0f);
                    me->GetMotionMaster()->MovePoint(POINT_VALIONA_IS_AWAY, position[4]);
                    break;
                case POINT_VALIONA_IS_AWAY:
                    me->DespawnOrUnsummon();
                    break;
                default:
                    break;
            }
        }

    private:

        void DespawnCreatures(uint32 entry, float distance)
        {
            std::list<Creature*> creatures;
            GetCreatureListWithEntryInGrid(creatures, me, entry, distance);

            if (creatures.empty())
                return;

            for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                (*iter)->DespawnOrUnsummon();
        }

        InstanceScript* pInstance;
        EventMap events;
        uint8 currentWaypoint;
        SummonList summons;
        ObjectGuid dragahGUID;
    };
};

class mob_invoked_flame_spirit : public CreatureScript
{
public:
    mob_invoked_flame_spirit() : CreatureScript("mob_invoked_flame_spirit") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_invoked_flame_spiritAI (creature);
    }

    struct mob_invoked_flame_spiritAI : public ScriptedAI
    {
        mob_invoked_flame_spiritAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            targetGUID = ObjectGuid::Empty;
            checkTargetTimer = 1000;
        }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            DoZoneInCombat();
            if (Player* player = me->SelectNearestPlayer(100))
            {
                me->SetReactState(REACT_PASSIVE);
                me->CastSpell(player, SPELL_CONCENTRATE_FIRE_AURA, true);
                me->ClearUnitState(UNIT_STATE_CASTING);
                me->GetMotionMaster()->MoveFollow(player, 0.0f, 0.0f);
                targetGUID = player->GetGUID();
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return ;
            if (checkTargetTimer <= diff)
            {
                if (Player *player = ObjectAccessor::GetPlayer(*me, targetGUID))
                    if (me->GetDistance(player) < 1.0f)
                    {
                        me->RemoveAura(SPELL_CONCENTRATE_FIRE_AURA);
                        DoCastVictim(RAID_MODE(SPELL_SUPERNOVA,    SPELL_SUPERNOVA_H));
                        me->DespawnOrUnsummon();
                    }
                checkTargetTimer = 1000;
            }
            else checkTargetTimer -= diff;
        }

    private :
        ObjectGuid targetGUID;
        uint32 checkTargetTimer;
    };
};

void AddSC_boss_drahga_shadowburner()
{
    new boss_drahga_shadowburner();
    new mob_valiona_gb();
    new mob_invoked_flame_spirit();
}
