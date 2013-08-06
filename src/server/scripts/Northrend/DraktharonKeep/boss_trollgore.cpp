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
    SPELL_CONSUME_AURA                            = 49381
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

    struct boss_trollgoreAI : public ScriptedAI
    {
        boss_trollgoreAI(Creature* creature) : ScriptedAI(creature), Summons(me)
        {
            instance = creature->GetInstanceScript();
        }

        uint32 uiConsumeTimer;
        uint32 uiAuraCountTimer;
        uint32 uiCrushTimer;
        uint32 uiInfectedWoundTimer;
        uint32 uiExplodeCorpseTimer;
        uint32 uiSpawnTimer;

        bool consumptionJunction;

        SummonList Summons;

        InstanceScript* instance;

        void Reset() OVERRIDE
        {
            uiConsumeTimer = 15000;
            uiAuraCountTimer = 15500;
            uiCrushTimer = urand(1000, 5000);
            uiInfectedWoundTimer = urand(10000, 60000);
            uiExplodeCorpseTimer = 3000;
            uiSpawnTimer = urand(30000, 40000);

            consumptionJunction = true;

            Summons.DespawnAll();

            me->RemoveAura(SPELL_CONSUME_AURA);

            instance->SetData(DATA_TROLLGORE, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            Talk(SAY_AGGRO);
            instance->SetBossState(DATA_TROLLGORE, IN_PROGRESS);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            if (uiSpawnTimer <= diff)
            {
                for (uint8 i = 0; i < 3; ++i)
                {
                    Unit* target = DoSummon(RAND(NPC_DRAKKARI_INVADER_1, NPC_DRAKKARI_INVADER_2), Spawn[i], 0, TEMPSUMMON_DEAD_DESPAWN);
                    target->Mount(MOUNT_DRAKKARI_BAT_DISPLAY);
                    target->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_IMMUNE_TO_PC);
                    target->GetMotionMaster()->MovePoint(0, Landing);
                }

                uiSpawnTimer = urand(30000, 40000);
            } else uiSpawnTimer -= diff;

            if (uiConsumeTimer <= diff)
            {
                Talk(SAY_CONSUME);
                DoCast(SPELL_CONSUME);
                me->AddAura(SPELL_CONSUME_AURA, me);
                uiConsumeTimer = 15000;
            } else uiConsumeTimer -= diff;

            if (consumptionJunction)
            {
                Aura* ConsumeAura = me->GetAura(SPELL_CONSUME_AURA);
                if (ConsumeAura && ConsumeAura->GetStackAmount() > 9)
                    consumptionJunction = false;
            }

            if (uiCrushTimer <= diff)
            {
                DoCastVictim(SPELL_CRUSH);
                uiCrushTimer = urand(10000, 15000);
            } else uiCrushTimer -= diff;

            if (uiInfectedWoundTimer <= diff)
            {
                DoCastVictim(SPELL_INFECTED_WOUND);
                uiInfectedWoundTimer = urand(25000, 35000);
            } else uiInfectedWoundTimer -= diff;

            if (uiExplodeCorpseTimer <= diff)
            {
                DoCast(SPELL_CORPSE_EXPLODE);
                Talk(SAY_EXPLODE);
                uiExplodeCorpseTimer = urand(15000, 19000);
            } else uiExplodeCorpseTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            Talk(SAY_DEATH);

            Summons.DespawnAll();

            instance->SetBossState(DATA_TROLLGORE, DONE);
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
            if (instance)
            {
                trollgoreGUID = instance->GetData64(DATA_TROLLGORE);
            }
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
        return new npc_drakkari_invaderAI(creature);
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
