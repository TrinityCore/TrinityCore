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
    SPELL_DRAINED                               = 59820,
    SPELL_FRENZY                                = 54312,
    SPELL_PROTECTIVE_BUBBLE                     = 54306,
    SPELL_WATER_BLAST                           = 54237,
    SPELL_WATER_BOLT_VOLLEY                     = 54241,
    SPELL_SPLASH                                = 59516,
    SPELL_BURST                                 = 54379,
    SPELL_WATER_GLOBULE                         = 54268,
    SPELL_MERGE                                 = 54269,
    SPELL_WATER_GLOBULE_VISUAL                  = 54260
};

enum IchoronCreatures
{
    NPC_ICHOR_GLOBULE                           = 29321,
    NPC_ICHORON_SUMMON_TARGET                   = 29326
};

enum Yells
{
    SAY_AGGRO                                   = 0,
    SAY_SLAY                                    = 1,
    SAY_DEATH                                   = 2,
    SAY_SPAWN                                   = 3,
    SAY_ENRAGE                                  = 4,
    SAY_SHATTER                                 = 5,
    SAY_BUBBLE                                  = 6
};

enum Actions
{
    ACTION_WATER_ELEMENT_HIT                    = 1
};

enum IchoronEvents
{
    EVENT_WATER_BLAST                           = 1,
    EVENT_WATER_BOLT_VOLLEY
};

enum GlobuleEvents
{
    EVENT_GLOBULE_MOVE                          = 1
};

enum Misc
{
    DATA_GLOBULE_PATH                           = 0,
    DATA_DEHYDRATION                            = 1
};


#define MAX_GLOBULE_PATHS   10

Position const globulePaths[MAX_GLOBULE_PATHS] =
{
    // first target
    { 1861.357f, 804.039f, 44.008f, 6.268f },
    { 1869.375f, 803.976f, 38.781f, 0.009f },
    // second target
    { 1888.063f, 763.488f, 47.667f, 1.744f },
    { 1882.865f, 776.385f, 38.824f, 1.882f },
    // third target
    { 1935.140f, 817.752f, 52.181f, 1.885f },
    { 1916.642f, 826.337f, 39.139f, 2.851f },
    // fourth target
    { 1930.257f, 833.053f, 46.906f, 4.579f },
    { 1916.642f, 826.337f, 39.139f, 2.851f },
    // fifth target
    { 1878.248f, 841.883f, 43.334f, 4.717f },
    { 1879.438f, 834.443f, 38.699f, 4.831f }
};

class boss_ichoron : public CreatureScript
{
public:
    boss_ichoron() : CreatureScript("boss_ichoron") { }

    struct boss_ichoronAI : public ScriptedAI
    {
        boss_ichoronAI(Creature* creature) : ScriptedAI(creature), m_waterElements(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            bIsExploded = false;
            bIsFrenzy = false;
            bIsDrained = false;
            dehydration = true;
            drainedTimer = 50;
            burstTimer = 15000;
        }

        void Reset() override
        {
            Initialize();

            events.Reset();
            me->SetVisible(true);
            DespawnWaterElements();

            if (instance->GetData(DATA_WAVE_COUNT) == 6)
                instance->SetBossState(DATA_1ST_BOSS_EVENT, NOT_STARTED);
            else if (instance->GetData(DATA_WAVE_COUNT) == 12)
                instance->SetBossState(DATA_2ND_BOSS_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);

            DoCast(me, SPELL_PROTECTIVE_BUBBLE);

            if (GameObject* door = instance->GetGameObject(DATA_ICHORON_CELL))
                if (door->GetGoState() == GO_STATE_READY)
                {
                    EnterEvadeMode();
                    return;
                }

            if (instance->GetData(DATA_WAVE_COUNT) == 6)
                instance->SetBossState(DATA_1ST_BOSS_EVENT, IN_PROGRESS);
            else if (instance->GetData(DATA_WAVE_COUNT) == 12)
                instance->SetBossState(DATA_2ND_BOSS_EVENT, IN_PROGRESS);

            events.ScheduleEvent(EVENT_WATER_BOLT_VOLLEY, urand(10000, 15000));
            events.ScheduleEvent(EVENT_WATER_BLAST, urand(6000, 9000));
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

        void DoAction(int32 param) override
        {
            if (!me->IsAlive())
                return;

            switch (param)
            {
                case ACTION_WATER_ELEMENT_HIT:
                {
                    if (bIsExploded)
                        DoExplodeCompleted();

                    me->SetHealth(me->GetHealth() + me->CountPctFromMaxHealth(3));
                    dehydration = false;
                }
                break;
            }
        }

        void DespawnWaterElements()
        {
            m_waterElements.DespawnAll();
        }

        // call when explode shall stop.
        // either when "hit" by a bubble, or when there is no bubble left.
        void DoExplodeCompleted()
        {
            bIsExploded = false;
            bIsDrained = false;

            if (!HealthBelowPct(25))
            {
                Talk(SAY_BUBBLE);
                DoCast(me, SPELL_PROTECTIVE_BUBBLE, true);
            }

            me->SetVisible(true);
            me->GetMotionMaster()->MoveChase(me->GetVictim());
        }

        uint32 GetData(uint32 type) const override
        {
            if (type == DATA_DEHYDRATION)
                return dehydration ? 1 : 0;

            return 0;
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (!who->ToCreature())
                return;

            if (who->GetEntry() != NPC_ICHOR_GLOBULE)
                return;

            if (!me->IsWithinDist(who, 4.0f, false))
                return;

            if (who->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE))
                return;

            who->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            who->CastSpell(who, SPELL_MERGE);
            DoAction(ACTION_WATER_ELEMENT_HIT);
            who->ToCreature()->DespawnOrUnsummon(1000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);

            if (bIsExploded)
            {
                bIsExploded = false;
                me->SetVisible(true);
            }

            DespawnWaterElements();

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

        void JustSummoned(Creature* summoned) override
        {
            summoned->SetSpeed(MOVE_RUN, 0.3f);
            m_waterElements.Summon(summoned);

            instance->SetGuidData(DATA_ADD_TRASH_MOB, summoned->GetGUID());
        }

        void SummonedCreatureDespawn(Creature* summoned) override
        {
            m_waterElements.Despawn(summoned);

            if (m_waterElements.empty() && bIsExploded)
            {
                me->RemoveAllAuras();
                DoExplodeCompleted();
            }

            instance->SetGuidData(DATA_DEL_TRASH_MOB, summoned->GetGUID());
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

            if (!bIsFrenzy && HealthBelowPct(25) && !bIsExploded)
            {
                Talk(SAY_ENRAGE);
                DoCast(me, SPELL_FRENZY, true);
                bIsFrenzy = true;
            }

            if (!bIsFrenzy)
            {
                if (!bIsExploded)
                {
                    if (!me->HasAura(SPELL_PROTECTIVE_BUBBLE))
                    {
                        bIsExploded = true;
                        Talk(SAY_SHATTER);
                        DoCast(SPELL_BURST);
                        me->RemoveAllAuras();
                        burstTimer = 15000;

                        std::list<Creature*> summonTargets;
                        GetCreatureListWithEntryInGrid(summonTargets, me, NPC_ICHORON_SUMMON_TARGET, 200.0f);
                        std::list<Creature*>::iterator itr = summonTargets.begin();

                        for (uint8 i = 0; i < MAX_GLOBULE_PATHS; i++)
                        {
                            std::advance(itr, urand(0, summonTargets.size() - 1)); // I take a random minion in the list
                            Position targetPos = (*itr)->GetRandomNearPosition(10.0f);
                            itr = summonTargets.begin();
                            TempSummon* globule = me->SummonCreature(NPC_ICHOR_GLOBULE, targetPos, TEMPSUMMON_CORPSE_DESPAWN);
                            DoCast(globule, SPELL_WATER_GLOBULE_VISUAL);

                            float minDistance = 1000.0f;
                            uint8 nextPath = 0;
                            // I move the globules to next position. the 10 positions are in couples, defined in globulePaths, so i have to increase by 2.
                            for (uint8 gpath = 0; gpath < MAX_GLOBULE_PATHS; gpath += 2)
                            {
                                if (globule->GetDistance(globulePaths[gpath]) < minDistance)
                                {
                                    minDistance = globule->GetDistance(globulePaths[gpath]);
                                    nextPath = gpath;
                                }
                            }

                            globule->GetAI()->SetData(DATA_GLOBULE_PATH, nextPath);
                        }
                        return;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;

                    events.Update(diff);

                    switch (events.ExecuteEvent())
                    {
                        case EVENT_WATER_BLAST:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_WATER_BLAST);
                            events.ScheduleEvent(EVENT_WATER_BLAST, urand(6000, 9000));
                            break;
                        case EVENT_WATER_BOLT_VOLLEY:
                            DoCast(SPELL_WATER_BOLT_VOLLEY);
                            events.ScheduleEvent(EVENT_WATER_BOLT_VOLLEY, urand(10000, 15000));
                            break;
                    }

                    DoMeleeAttackIfReady();
                }
                else if (!bIsDrained)
                {
                    if (drainedTimer <= 0)
                    {
                        bIsDrained = true;
                        drainedTimer = 50;
                        uint32 damage = me->CountPctFromMaxHealth(30);
                        if (me->GetHealth() < damage)
                            me->SetHealth(me->CountPctFromMaxHealth(1));
                        else
                        {
                            me->SetHealth(me->GetHealth() - damage);
                            me->LowerPlayerDamageReq(damage);
                        }
                        DoCast(SPELL_DRAINED);
                        me->SetVisible(false);
                        me->AttackStop();
                    }
                    else
                        drainedTimer -= diff;
                }
                else if (bIsDrained)
                {
                    if (burstTimer <= 0)
                    {
                        DoExplodeCompleted();
                    }
                    else
                        burstTimer -= diff;
                }
            }
            else
            {
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                switch (events.ExecuteEvent())
                {
                    case EVENT_WATER_BLAST:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_WATER_BLAST);
                        events.ScheduleEvent(EVENT_WATER_BLAST, urand(6000, 9000));
                        break;
                    case EVENT_WATER_BOLT_VOLLEY:
                        DoCast(SPELL_WATER_BOLT_VOLLEY);
                        events.ScheduleEvent(EVENT_WATER_BOLT_VOLLEY, urand(10000, 15000));
                        break;
                }

                DoMeleeAttackIfReady();
            }
        }

    private:
        InstanceScript* instance;
        SummonList m_waterElements;
        EventMap events;
        bool bIsExploded;
        bool bIsFrenzy;
        bool bIsDrained;
        bool dehydration;
        int32 drainedTimer;
        int32 burstTimer;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_ichoronAI>(creature);
    }
};

class npc_ichor_globule : public CreatureScript
{
public:
    npc_ichor_globule() : CreatureScript("npc_ichor_globule") { }

    struct npc_ichor_globuleAI : public ScriptedAI
    {
        npc_ichor_globuleAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            pathId = 0;
        }

        void Reset() override
        {
            Initialize();
            events.Reset();
            DoCast(SPELL_WATER_GLOBULE);
            me->SetReactState(REACT_PASSIVE);
        }

        void SetData(uint32 id, uint32 data) override
        {
            if (id == DATA_GLOBULE_PATH)
            {
                pathId = data;
                me->GetMotionMaster()->MovePoint(0, globulePaths[pathId]);
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            switch (id)
            {
                case 0:
                    me->GetMotionMaster()->Clear();
                    events.ScheduleEvent(EVENT_GLOBULE_MOVE, 500);
                    break;
                case 1:
                    me->GetMotionMaster()->Clear();
                    if (Creature* ichoron = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ICHORON)))
                        me->GetMotionMaster()->MoveFollow(ichoron, 0.0f, 0.0f);
                    break;
            }
        }

        // on retail spell casted on a creature's death are not casted after death but keeping mob at 1 health, casting it and then letting the mob die.
        // this feature should be still implemented
        void DamageTaken(Unit* /*attacker*/, uint32 &damage) override
        {
            int32 actualHp = me->GetHealth();
            actualHp -= damage;

            if (actualHp <= 0)
                DoCast(SPELL_SPLASH);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (events.ExecuteEvent() == EVENT_GLOBULE_MOVE)
                me->GetMotionMaster()->MovePoint(1, globulePaths[pathId + 1]);
        }

    private:
        InstanceScript* instance;
        EventMap events;
        uint8 pathId;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_ichor_globuleAI>(creature);
    }
};

class achievement_dehydration : public AchievementCriteriaScript
{
    public:
        achievement_dehydration() : AchievementCriteriaScript("achievement_dehydration")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* Ichoron = target->ToCreature())
                if (Ichoron->AI()->GetData(DATA_DEHYDRATION))
                    return true;

            return false;
        }
};

void AddSC_boss_ichoron()
{
    new boss_ichoron();
    new npc_ichor_globule();
    new achievement_dehydration();
}
