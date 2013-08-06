/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "drak_tharon_keep.h"

enum Spells
{
    SPELL_INFECTED_WOUND                          = 49637,
    SPELL_CRUSH                                   = 49639,
    SPELL_CORPSE_EXPLODE                          = 49555,
    SPELL_CONSUME                                 = 49380,
    SPELL_CONSUME_AURA                            = 49381,
    SPELL_CONSUME_AURA_H                          = 59805
};

enum Yells
{
    SAY_AGGRO                                     = 0,
    SAY_KILL                                      = 1,
    SAY_CONSUME                                   = 2,
    SAY_EXPLODE                                   = 3,
    SAY_DEATH                                     = 4
};

enum Creatures
{
    NPC_DRAKKARI_INVADER_1                        = 27753,
    NPC_DRAKKARI_INVADER_2                        = 27709,
    MOUNT_DRAKKARI_BAT_DISPLAY                    = 26751
};

enum Misc
{
    DATA_CONSUMPTION_JUNCTION                     = 1
};

enum Events
{
    EVENT_CONSUME                                 = 1,
    EVENT_CRUSH,
    EVENT_INFECTED_WOUND,
    EVENT_CORPSE_EXPLODE,
    EVENT_SPAWN
};

Position const Spawn[3] = 
{
    { -212.266f, -654.887f, 54.3783f, 3.12414f },
    { -213.252f, -666.073f, 53.4409f, 3.01942f },
    { -213.076f, -679.635f, 53.1535f, 2.96706f }
};

Position Landing  = { -253.614f, -662.637f, 27.8484f, 3.32733f };

class boss_trollgore : public CreatureScript
{
public:
    boss_trollgore() : CreatureScript("boss_trollgore") { }

    struct boss_trollgoreAI : public BossAI
    {
        boss_trollgoreAI(Creature* creature) : BossAI(creature, DATA_TROLLGORE), Summons(me) { }

        void Reset() OVERRIDE
        {
            _Reset();
            me->RemoveAura(DUNGEON_MODE(SPELL_CONSUME_AURA, SPELL_CONSUME_AURA_H));
            consumptionJunction = true;
            Summons.DespawnAll();
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            Talk(SAY_AGGRO);
            _EnterCombat();

            events.ScheduleEvent(EVENT_CONSUME, 15000);
            events.ScheduleEvent(EVENT_CRUSH, urand(1000, 5000));
            events.ScheduleEvent(EVENT_INFECTED_WOUND, urand(10000, 60000));
            events.ScheduleEvent(EVENT_CORPSE_EXPLODE, 3000);
            events.ScheduleEvent(EVENT_SPAWN, urand(30000, 40000));
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_CONSUME:
                        Talk(SAY_CONSUME);
                        DoCast(SPELL_CONSUME);
                        me->AddAura(DUNGEON_MODE(SPELL_CONSUME_AURA, SPELL_CONSUME_AURA_H), me);
                        events.ScheduleEvent(EVENT_CONSUME, 15000);
                        break;
                    case EVENT_CRUSH:
                        DoCastVictim(SPELL_CRUSH);
                        events.ScheduleEvent(EVENT_CRUSH, urand(10000, 15000));
                        break;
                    case EVENT_INFECTED_WOUND:
                        DoCastVictim(SPELL_INFECTED_WOUND);
                        events.ScheduleEvent(EVENT_INFECTED_WOUND, urand(25000, 35000));
                        break;
                    case EVENT_CORPSE_EXPLODE:
                        Talk(SAY_EXPLODE);
                        DoCast(SPELL_CORPSE_EXPLODE);
                        events.ScheduleEvent(EVENT_CORPSE_EXPLODE, urand(15000, 19000));
                        break;
                    case EVENT_SPAWN:
                        for (uint8 i = 0; i < 3; ++i)
                        {
                            Unit* target = DoSummon(RAND(NPC_DRAKKARI_INVADER_1, NPC_DRAKKARI_INVADER_2), Spawn[i], 0, TEMPSUMMON_DEAD_DESPAWN);
                            target->Mount(MOUNT_DRAKKARI_BAT_DISPLAY);
                            target->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_IMMUNE_TO_PC);
                            target->GetMotionMaster()->MovePoint(0, Landing);
                        }
                        events.ScheduleEvent(EVENT_SPAWN, urand(30000, 40000));
                        break;
                    default:
                        break;
                }
            }

            if (consumptionJunction)
            {
                Aura* ConsumeAura = me->GetAura(DUNGEON_MODE(SPELL_CONSUME_AURA, SPELL_CONSUME_AURA_H));
                if (ConsumeAura && ConsumeAura->GetStackAmount() > 9)
                    consumptionJunction = false;
            }

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            Talk(SAY_DEATH);
            Summons.DespawnAll();
            _JustDied();
        }

        uint32 GetData(uint32 type) const OVERRIDE
        {
            if (type == DATA_CONSUMPTION_JUNCTION)
                return consumptionJunction ? 1 : 0;

            return 0;
        }

        void KilledUnit(Unit* victim) OVERRIDE
        {
            if (victim->GetTypeId() != TYPEID_PLAYER)
                return;

            Talk(SAY_KILL);
        }

        void JustSummoned(Creature* summon) OVERRIDE
        {
            Summons.Summon(summon);
        }

        private:
            bool consumptionJunction;
            SummonList Summons;
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetDrakTharonKeepAI<boss_trollgoreAI>(creature);
    }
};

class npc_drakkari_invader : public CreatureScript
{
public:
    npc_drakkari_invader() : CreatureScript("npc_drakkari_invader") { }

    struct npc_drakkari_invaderAI : public ScriptedAI
    {
        npc_drakkari_invaderAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            trollgoreGUID = instance->GetData64(DATA_TROLLGORE);
        }

        InstanceScript* instance;
        uint64 trollgoreGUID;

        void WaypointReached(uint32 waypointId) OVERRIDE
        {
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_IMMUNE_TO_PC);
        }
        
        void EnterCombat(Unit* who) OVERRIDE
        {
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_IMMUNE_TO_PC); 
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (me->IsStopped()) {
                me->Dismount();
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_IMMUNE_TO_PC);
            }

            if (!me->IsMounted() && !me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_IMMUNE_TO_PC)) {
                if (Unit* Trollgore = me->GetCreature(*me, trollgoreGUID)) {
                    if (Trollgore->IsAlive()) {
                        AttackStart(Trollgore);
                    }
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetDrakTharonKeepAI<npc_drakkari_invaderAI>(creature);
    }
};

class achievement_consumption_junction : public AchievementCriteriaScript
{
    public:
        achievement_consumption_junction() : AchievementCriteriaScript("achievement_consumption_junction")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target) OVERRIDE
        {
            if (!target)
                return false;

            if (Creature* Trollgore = target->ToCreature())
                if (Trollgore->AI()->GetData(DATA_CONSUMPTION_JUNCTION))
                    return true;

            return false;
        }
};

void AddSC_boss_trollgore()
{
    new boss_trollgore();
    new npc_drakkari_invader();
    new achievement_consumption_junction();
}
