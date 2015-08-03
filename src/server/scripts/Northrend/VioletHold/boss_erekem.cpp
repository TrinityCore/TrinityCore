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
    SPELL_BLOODLUST                             = 54516,
    SPELL_BREAK_BONDS                           = 59463,
    SPELL_CHAIN_HEAL                            = 54481,
    SPELL_EARTH_SHIELD                          = 54479,
    SPELL_EARTH_SHOCK                           = 54511,
    SPELL_LIGHTNING_BOLT                        = 53044,
    SPELL_STORMSTRIKE                           = 51876,
    SPELL_WINDFURY                              = 54493
};

enum Yells
{
    SAY_AGGRO                                   = 0,
    SAY_SLAY                                    = 1,
    SAY_DEATH                                   = 2,
    SAY_SPAWN                                   = 3,
    SAY_ADD_KILLED                              = 4,
    SAY_BOTH_ADDS_KILLED                        = 5
};

enum ErekemEvents
{
    EVENT_EARTH_SHIELD                          = 1,
    EVENT_CHAIN_HEAL,
    EVENT_BLOODLUST,
    EVENT_LIGHTNING_BOLT,
    EVENT_EARTH_SHOCK,
    EVENT_WINDFURY,
    EVENT_STORMSTRIKE
};

class boss_erekem : public CreatureScript
{
public:
    boss_erekem() : CreatureScript("boss_erekem") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_erekemAI>(creature);
    }

    struct boss_erekemAI : public ScriptedAI
    {
        boss_erekemAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            phase = 0;
            breakBondsCd = 0;
        }

        void Reset() override
        {
            Initialize();

            if (instance->GetData(DATA_WAVE_COUNT) == 6)
                instance->SetBossState(DATA_1ST_BOSS_EVENT, NOT_STARTED);
            else if (instance->GetData(DATA_WAVE_COUNT) == 12)
                instance->SetBossState(DATA_2ND_BOSS_EVENT, NOT_STARTED);

            if (instance->GetData(DATA_MAIN_EVENT_PHASE) == IN_PROGRESS)
            {
                if (Creature* pGuard1 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_EREKEM_GUARD_1)))
                    pGuard1->DespawnOrUnsummon();
                if (Creature* pGuard2 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_EREKEM_GUARD_2)))
                    pGuard2->DespawnOrUnsummon();
            }
            else
            {
                if (Creature* pGuard1 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_EREKEM_GUARD_1)))
                {
                    if (!pGuard1->IsAlive())
                        pGuard1->Respawn();
                }
                if (Creature* pGuard2 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_EREKEM_GUARD_2)))
                {
                    if (!pGuard2->IsAlive())
                        pGuard2->Respawn();
                }
            }

            events.Reset();
        }

        void JustReachedHome() override
        {
            if (Creature* pGuard1 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_EREKEM_GUARD_1)))
                pGuard1->Respawn();

            if (Creature* pGuard2 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_EREKEM_GUARD_2)))
                pGuard2->Respawn();
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

                if (Creature* pGuard1 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_EREKEM_GUARD_1)))
                {
                    pGuard1->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    if (!pGuard1->GetVictim() && pGuard1->AI())
                        pGuard1->AI()->AttackStart(who);
                }
                if (Creature* pGuard2 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_EREKEM_GUARD_2)))
                {
                    pGuard2->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    if (!pGuard2->GetVictim() && pGuard2->AI())
                        pGuard2->AI()->AttackStart(who);
                }
            }
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
            DoCast(me, SPELL_EARTH_SHIELD);

            if (GameObject* door = instance->GetGameObject(DATA_EREKEM_CELL))
                if (door->GetGoState() == GO_STATE_READY)
                {
                    EnterEvadeMode();
                    return;
                }

            if (instance->GetData(DATA_WAVE_COUNT) == 6)
                instance->SetBossState(DATA_1ST_BOSS_EVENT, IN_PROGRESS);
            else if (instance->GetData(DATA_WAVE_COUNT) == 12)
                instance->SetBossState(DATA_2ND_BOSS_EVENT, IN_PROGRESS);

            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_NPC);

            events.ScheduleEvent(EVENT_EARTH_SHIELD, 20000);
            events.ScheduleEvent(EVENT_BLOODLUST, 15000);
            events.ScheduleEvent(EVENT_CHAIN_HEAL, 10000);
            events.ScheduleEvent(EVENT_LIGHTNING_BOLT, 2000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);

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

            if (phase == 0)
                if (Creature* pGuard1 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_EREKEM_GUARD_1)))
                {
                    if (Creature* pGuard2 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_EREKEM_GUARD_2)))
                    {
                        if (!pGuard1->IsAlive() && !pGuard2->IsAlive())
                        {
                            phase = 1;
                            DoCastVictim(SPELL_STORMSTRIKE);
                            DoCast(SPELL_WINDFURY);
                            events.Reset();
                            events.ScheduleEvent(EVENT_EARTH_SHOCK, urand(2000, 8000));
                            events.ScheduleEvent(EVENT_WINDFURY, urand(1500, 2000));
                            events.ScheduleEvent(EVENT_STORMSTRIKE, urand(1500, 2000));
                        }
                    }
                }

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (breakBondsCd <= 0)
            {
                if (Creature* pGuard1 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_EREKEM_GUARD_1)))
                {
                    if (Creature* pGuard2 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_EREKEM_GUARD_2)))
                    {
                        if (pGuard1->IsAlive())
                        {
                            if (pGuard1->HasAuraType(SPELL_AURA_MOD_STUN) || pGuard1->HasAuraType(SPELL_AURA_MOD_ROOT)
                                || pGuard1->HasAuraType(SPELL_AURA_MOD_CONFUSE) || pGuard1->HasAuraType(SPELL_AURA_MOD_PACIFY)
                                || pGuard1->HasAuraType(SPELL_AURA_MOD_DECREASE_SPEED))
                            {
                                DoCast(SPELL_BREAK_BONDS);
                                breakBondsCd = 10000;
                                return;
                            }
                        }
                        if (pGuard2->IsAlive())
                        {
                            if (pGuard2->HasAuraType(SPELL_AURA_MOD_STUN) || pGuard2->HasAuraType(SPELL_AURA_MOD_ROOT)
                                || pGuard2->HasAuraType(SPELL_AURA_MOD_CONFUSE) || pGuard2->HasAuraType(SPELL_AURA_MOD_PACIFY)
                                || pGuard2->HasAuraType(SPELL_AURA_MOD_DECREASE_SPEED))
                            {
                                DoCast(SPELL_BREAK_BONDS);
                                breakBondsCd = 10000;
                                return;
                            }
                        }
                    }
                }
            }
            else
                breakBondsCd -= diff;

            switch (events.ExecuteEvent())
            {
                case EVENT_EARTH_SHIELD:
                    if (Unit* ally = DoSelectLowestHpFriendly(30.0f))
                        DoCast(ally, SPELL_EARTH_SHIELD);
                    events.ScheduleEvent(EVENT_EARTH_SHIELD, 20000);
                    break;
                case EVENT_BLOODLUST:
                    DoCast(SPELL_BLOODLUST);
                    events.ScheduleEvent(EVENT_BLOODLUST, urand(35000, 45000));
                    break;
                case EVENT_LIGHTNING_BOLT:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_LIGHTNING_BOLT);
                    events.ScheduleEvent(EVENT_LIGHTNING_BOLT, 2500);
                    break;
                case EVENT_CHAIN_HEAL:
                    if (Unit* ally = DoSelectLowestHpFriendly(40.0f))
                        DoCast(ally, SPELL_CHAIN_HEAL);
                    {
                        Creature* pGuard1 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_EREKEM_GUARD_1));
                        Creature* pGuard2 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_EREKEM_GUARD_2));
                        events.ScheduleEvent(EVENT_CHAIN_HEAL, ((pGuard1 && !pGuard1->IsAlive()) || (pGuard2 && !pGuard2->IsAlive()) ? 3000 : 8000 + rand() % 3000));
                    }
                    break;
                case EVENT_EARTH_SHOCK:
                    DoCastVictim(SPELL_EARTH_SHOCK);
                    events.ScheduleEvent(EVENT_EARTH_SHOCK, urand(8000, 13000));
                    break;
                case EVENT_WINDFURY:
                    DoCast(SPELL_WINDFURY);
                    events.ScheduleEvent(EVENT_WINDFURY, urand(1500, 2000));
                    break;
                case EVENT_STORMSTRIKE:
                    DoCastVictim(SPELL_STORMSTRIKE);
                    events.ScheduleEvent(EVENT_STORMSTRIKE, urand(1500, 2000));
                    break;
                default:
                    break;
            }

            DoMeleeAttackIfReady();
        }

    private:
        EventMap events;
        InstanceScript* instance;
        uint8 phase;
        int32 breakBondsCd;
    };
};

enum GuardSpells
{
    SPELL_GUSHING_WOUND                   = 39215,
    SPELL_HOWLING_SCREECH                 = 54462,
    SPELL_STRIKE                          = 14516
};

class npc_erekem_guard : public CreatureScript
{
public:
    npc_erekem_guard() : CreatureScript("npc_erekem_guard") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_erekem_guardAI>(creature);
    }

    struct npc_erekem_guardAI : public ScriptedAI
    {
        npc_erekem_guardAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            uiStrikeTimer = urand(4000, 8000);
            uiHowlingScreechTimer = urand(8000, 13000);
            uiGushingWoundTimer = urand(1000, 3000);
        }

        uint32 uiGushingWoundTimer;
        uint32 uiHowlingScreechTimer;
        uint32 uiStrikeTimer;

        InstanceScript* instance;

        void Reset() override
        {
            Initialize();

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
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

        void MoveInLineOfSight(Unit* /*who*/) override { }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();

            if (uiStrikeTimer <= diff)
            {
                DoCastVictim(SPELL_STRIKE);
                uiStrikeTimer = urand(4000, 8000);
            } else uiStrikeTimer -= diff;

            if (uiHowlingScreechTimer <= diff)
            {
                DoCastVictim(SPELL_HOWLING_SCREECH);
                uiHowlingScreechTimer = urand(8000, 13000);
            } else uiHowlingScreechTimer -= diff;

            if (uiGushingWoundTimer <= diff)
            {
                DoCastVictim(SPELL_GUSHING_WOUND);
                uiGushingWoundTimer = urand(7000, 12000);
            } else uiGushingWoundTimer -= diff;
        }
    };
};

void AddSC_boss_erekem()
{
    new boss_erekem();
    new npc_erekem_guard();
}
