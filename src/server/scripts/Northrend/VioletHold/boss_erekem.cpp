/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
    H_SPELL_CHAIN_HEAL                          = 59473,
    SPELL_EARTH_SHIELD                          = 54479,
    H_SPELL_EARTH_SHIELD                        = 59471,
    SPELL_EARTH_SHOCK                           = 54511,
    SPELL_LIGHTNING_BOLT                        = 53044,
    SPELL_STORMSTRIKE                           = 51876
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
            instance = creature->GetInstanceScript();
        }

        uint32 uiBloodlustTimer;
        uint32 uiChainHealTimer;
        uint32 uiEarthShockTimer;
        uint32 uiLightningBoltTimer;
        uint32 uiEarthShieldTimer;

        InstanceScript* instance;

        void Reset() override
        {
            uiBloodlustTimer = 15000;
            uiChainHealTimer = 0;
            uiEarthShockTimer = urand(2000, 8000);
            uiLightningBoltTimer = urand(5000, 10000);
            uiEarthShieldTimer = 20000;
            if (instance->GetData(DATA_WAVE_COUNT) == 6)
                instance->SetData(DATA_1ST_BOSS_EVENT, NOT_STARTED);
            else if (instance->GetData(DATA_WAVE_COUNT) == 12)
                instance->SetData(DATA_2ND_BOSS_EVENT, NOT_STARTED);

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
                    pGuard1->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NON_ATTACKABLE);
                    if (!pGuard1->GetVictim() && pGuard1->AI())
                        pGuard1->AI()->AttackStart(who);
                }
                if (Creature* pGuard2 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_EREKEM_GUARD_2)))
                {
                    pGuard2->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NON_ATTACKABLE);
                    if (!pGuard2->GetVictim() && pGuard2->AI())
                        pGuard2->AI()->AttackStart(who);
                }
            }
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
            DoCast(me, SPELL_EARTH_SHIELD);

            if (GameObject* pDoor = instance->instance->GetGameObject(instance->GetGuidData(DATA_EREKEM_CELL)))
                if (pDoor->GetGoState() == GO_STATE_READY)
                {
                    EnterEvadeMode();
                    return;
                }

            if (instance->GetData(DATA_WAVE_COUNT) == 6)
                instance->SetData(DATA_1ST_BOSS_EVENT, IN_PROGRESS);
            else if (instance->GetData(DATA_WAVE_COUNT) == 12)
                instance->SetData(DATA_2ND_BOSS_EVENT, IN_PROGRESS);
        }

        void MoveInLineOfSight(Unit* /*who*/) override { }


        void UpdateAI(uint32 diff) override
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            //spam stormstrike in hc mode if spawns are dead
            if (IsHeroic())
            {
                if (Creature* pGuard1 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_EREKEM_GUARD_1)))
                {
                    if (Creature* pGuard2 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_EREKEM_GUARD_2)))
                    {
                        if (!pGuard1->IsAlive() && !pGuard2->IsAlive())
                            DoCastVictim(SPELL_STORMSTRIKE);
                    }
                }
            }

            if (uiEarthShieldTimer <= diff)
            {
                DoCast(me, SPELL_EARTH_SHIELD);
                uiEarthShieldTimer = 20000;
            } else uiEarthShieldTimer -= diff;

            if (uiChainHealTimer <= diff)
            {
                if (uint64 TargetGUID = GetChainHealTargetGUID())
                {
                    if (Creature* target = ObjectAccessor::GetCreature(*me, TargetGUID))
                        DoCast(target, SPELL_CHAIN_HEAL);

                    //If one of the adds is dead spawn heals faster
                    Creature* pGuard1 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_EREKEM_GUARD_1));
                    Creature* pGuard2 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_EREKEM_GUARD_2));
                    uiChainHealTimer = ((pGuard1 && !pGuard1->IsAlive()) || (pGuard2 && !pGuard2->IsAlive()) ? 3000 : 8000) + rand32() % 3000;
                }
            } else uiChainHealTimer -= diff;

            if (uiBloodlustTimer <= diff)
            {
                DoCast(me, SPELL_BLOODLUST);
                uiBloodlustTimer = urand(35000, 45000);
            } else uiBloodlustTimer -= diff;

            if (uiEarthShockTimer <= diff)
            {
                DoCastVictim(SPELL_EARTH_SHOCK);
                uiEarthShockTimer = urand(8000, 13000);
            } else uiEarthShockTimer -= diff;

            if (uiLightningBoltTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_LIGHTNING_BOLT);
                uiLightningBoltTimer = urand(18000, 24000);
            } else uiLightningBoltTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);

            if (instance->GetData(DATA_WAVE_COUNT) == 6)
            {
                instance->SetData(DATA_1ST_BOSS_EVENT, DONE);
                instance->SetData(DATA_WAVE_COUNT, 7);
            }
            else if (instance->GetData(DATA_WAVE_COUNT) == 12)
            {
                instance->SetData(DATA_2ND_BOSS_EVENT, DONE);
                instance->SetData(DATA_WAVE_COUNT, 13);
            }
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() != TYPEID_PLAYER)
                return;

            Talk(SAY_SLAY);
        }

        uint64 GetChainHealTargetGUID()
        {
            if (HealthBelowPct(85))
                return me->GetGUID();

            Creature* pGuard1 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_EREKEM_GUARD_1));
            if (pGuard1 && pGuard1->IsAlive() && !pGuard1->HealthAbovePct(75))
                return pGuard1->GetGUID();

            Creature* pGuard2 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_EREKEM_GUARD_2));
            if (pGuard2 && pGuard2->IsAlive() && !pGuard2->HealthAbovePct(75))
                return pGuard2->GetGUID();

            return 0;
        }
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
            instance = creature->GetInstanceScript();
        }

        uint32 uiGushingWoundTimer;
        uint32 uiHowlingScreechTimer;
        uint32 uiStrikeTimer;

        InstanceScript* instance;

        void Reset() override
        {
            uiStrikeTimer = urand(4000, 8000);
            uiHowlingScreechTimer = urand(8000, 13000);
            uiGushingWoundTimer = urand(1000, 3000);
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
