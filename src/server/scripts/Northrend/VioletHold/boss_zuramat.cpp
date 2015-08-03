/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
#include "violet_hold.h"

enum Spells
{
    SPELL_SHROUD_OF_DARKNESS                    = 54524,
    SPELL_SUMMON_VOID_SENTRY                    = 54369,
    SPELL_VOID_SHIFT                            = 54361,
    SPELL_VOID_SHIFTED                          = 54343,
};

enum Yells
{
    SAY_AGGRO                                   = 0,
    SAY_SLAY                                    = 1,
    SAY_DEATH                                   = 2,
    SAY_SPAWN                                   = 3,
    SAY_SHIELD                                  = 4,
    SAY_WHISPER                                 = 5
};

enum Misc
{
    DATA_VOID_DANCE                             = 2153
};

enum ZuramatEvents
{
    EVENT_VOID_SHIFT                            = 1,
    EVENT_SUMMON_VOID,
    EVENT_SHROUD_OF_DARKNESS
};

class boss_zuramat : public CreatureScript
{
public:
    boss_zuramat() : CreatureScript("boss_zuramat") { }

    struct boss_zuramatAI : public ScriptedAI
    {
        boss_zuramatAI(Creature* creature) : ScriptedAI(creature), sentries(me)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            voidDance = true;
        }

        void DespawnSentries()
        {
            sentries.DespawnAll();
            std::list<Creature*> sentrylist;
            GetCreatureListWithEntryInGrid(sentrylist, me, NPC_VOID_SENTRY_BALL, 200.0f);
            if (!sentrylist.empty())
                for (std::list<Creature*>::const_iterator itr = sentrylist.begin(); itr != sentrylist.end(); ++itr)
                    (*itr)->DespawnOrUnsummon();
        }

        void Reset() override
        {
            if (instance->GetData(DATA_WAVE_COUNT) == 6)
                instance->SetData(DATA_1ST_BOSS_EVENT, NOT_STARTED);
            else if (instance->GetData(DATA_WAVE_COUNT) == 12)
                instance->SetData(DATA_2ND_BOSS_EVENT, NOT_STARTED);

            Initialize();
            events.Reset();
            DespawnSentries();
        }

        void AttackStart(Unit* who) override
        {
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC) || me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                return;

            if (me->Attack(who, true))
            {
                me->AddThreat(who, 0.0f);
                me->SetInCombatWith(who);
                who->SetInCombatWith(me);
                DoStartMovement(who);
            }
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (GameObject* door = instance->GetGameObject(DATA_ZURAMAT_CELL))
                if (door->GetGoState() == GO_STATE_READY)
                {
                    EnterEvadeMode();
                    return;
                }

            Talk(SAY_AGGRO);

            if (instance->GetData(DATA_WAVE_COUNT) == 6)
                instance->SetBossState(DATA_1ST_BOSS_EVENT, IN_PROGRESS);
            else if (instance->GetData(DATA_WAVE_COUNT) == 12)
                instance->SetData(DATA_2ND_BOSS_EVENT, IN_PROGRESS);

            me->SetInCombatWithZone();
            events.ScheduleEvent(EVENT_SHROUD_OF_DARKNESS, urand(18000, 20000));
            events.ScheduleEvent(EVENT_VOID_SHIFT, 9000);
            events.ScheduleEvent(EVENT_SUMMON_VOID, 4000);
        }

        void JustSummoned(Creature* summon) override
        {
            sentries.Summon(summon);
        }

        void SummonedCreatureDies(Creature* summoned, Unit* /*who*/) override
        {
            if (summoned->GetEntry() == NPC_VOID_SENTRY)
                voidDance = false;
        }

        uint32 GetData(uint32 type) const override
        {
            if (type == DATA_VOID_DANCE)
                return voidDance ? 1 : 0;

            return 0;
        }

        void JustDied(Unit* /*killer*/) override
        {
            instance->SetData(DATA_ZURAMAT, 1);

            Talk(SAY_DEATH);

            DespawnSentries();

            if (instance->GetData(DATA_WAVE_COUNT) == 6)
            {
                instance->SetBossState(DATA_1ST_BOSS_EVENT, DONE);
                instance->SetData(DATA_WAVE_COUNT, 7);
            }
            else if (instance->GetData(DATA_WAVE_COUNT) == 12)
            {
                instance->SetBossState(DATA_2ND_BOSS_EVENT, DONE);
                instance->SetData(DATA_WAVE_COUNT, 13);
            }
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_SLAY);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
                case EVENT_SUMMON_VOID:
                    DoCast(SPELL_SUMMON_VOID_SENTRY);
                    events.ScheduleEvent(EVENT_SUMMON_VOID, urand(7000, 10000));
                    break;
                case EVENT_VOID_SHIFT:
                    if (Unit* unit = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(unit, SPELL_VOID_SHIFT);
                    events.ScheduleEvent(EVENT_VOID_SHIFT, 15000);
                    break;
                case EVENT_SHROUD_OF_DARKNESS:
                    DoCast(SPELL_SHROUD_OF_DARKNESS);
                    events.ScheduleEvent(EVENT_SHROUD_OF_DARKNESS, urand(18000, 20000));
                    break;
                default:
                    break;
            }

            DoMeleeAttackIfReady();
        }

    private:
        InstanceScript* instance;
        EventMap events;
        SummonList sentries;
        bool voidDance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_zuramatAI>(creature);
    }
};

class achievement_void_dance : public AchievementCriteriaScript
{
    public:
        achievement_void_dance() : AchievementCriteriaScript("achievement_void_dance")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* Zuramat = target->ToCreature())
                if (Zuramat->AI()->GetData(DATA_VOID_DANCE))
                    return true;

            return false;
        }
};

void AddSC_boss_zuramat()
{
    new boss_zuramat();
    new achievement_void_dance();
}
