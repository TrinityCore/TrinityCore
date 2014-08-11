/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Boss_Midnight
SD%Complete: 100
SDComment:
SDCategory: Karazhan
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"

enum Midnight
{
    SAY_MIDNIGHT_KILL           = 0,
    SAY_APPEAR                  = 1,
    SAY_MOUNT                   = 2,

    SAY_KILL                    = 0,
    SAY_DISARMED                = 1,
    SAY_DEATH                   = 2,
    SAY_RANDOM                  = 3,

    SPELL_SHADOWCLEAVE          = 29832,
    SPELL_INTANGIBLE_PRESENCE   = 29833,
    SPELL_BERSERKER_CHARGE      = 26561,                   //Only when mounted

    MOUNTED_DISPLAYID           = 16040,

    //Attumen (@todo Use the summoning spell instead of Creature id. It works, but is not convenient for us)
    SUMMON_ATTUMEN              = 15550,
};

class boss_attumen : public CreatureScript
{
public:
    boss_attumen() : CreatureScript("boss_attumen") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_attumenAI(creature);
    }

    struct boss_attumenAI : public ScriptedAI
    {
        boss_attumenAI(Creature* creature) : ScriptedAI(creature)
        {
            Phase = 1;

            CleaveTimer = urand(10000, 15000);
            CurseTimer = 30000;
            RandomYellTimer = urand(30000, 60000);              //Occasionally yell
            ChargeTimer = 20000;
            ResetTimer = 0;
        }

        uint64 Midnight;
        uint8 Phase;
        uint32 CleaveTimer;
        uint32 CurseTimer;
        uint32 RandomYellTimer;
        uint32 ChargeTimer;                                     //only when mounted
        uint32 ResetTimer;

        void Reset() override
        {
            ResetTimer = 0;
            Midnight = 0;
        }

        void EnterEvadeMode() override
        {
            ScriptedAI::EnterEvadeMode();
            ResetTimer = 2000;
        }

        void EnterCombat(Unit* /*who*/) override { }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(SAY_KILL);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            if (Unit* midnight = ObjectAccessor::GetUnit(*me, Midnight))
                midnight->Kill(midnight);
        }

        void UpdateAI(uint32 diff) override;

        void SpellHit(Unit* /*source*/, const SpellInfo* spell) override
        {
            if (spell->Mechanic == MECHANIC_DISARM)
                Talk(SAY_DISARMED);
        }
    };
};

class boss_midnight : public CreatureScript
{
public:
    boss_midnight() : CreatureScript("boss_midnight") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_midnightAI(creature);
    }

    struct boss_midnightAI : public ScriptedAI
    {
        boss_midnightAI(Creature* creature) : ScriptedAI(creature) { }

        uint64 Attumen;
        uint8 Phase;
        uint32 Mount_Timer;

        void Reset() override
        {
            Phase = 1;
            Attumen = 0;
            Mount_Timer = 0;

            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetVisible(true);
        }

        void EnterCombat(Unit* /*who*/) override { }

        void KilledUnit(Unit* /*victim*/) override
        {
            if (Phase == 2)
            {
                if (Unit* unit = ObjectAccessor::GetUnit(*me, Attumen))
                    Talk(SAY_MIDNIGHT_KILL, unit);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (Phase == 1 && HealthBelowPct(95))
            {
                Phase = 2;
                if (Creature* attumen = me->SummonCreature(SUMMON_ATTUMEN, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 30000))
                {
                    Attumen = attumen->GetGUID();
                    attumen->AI()->AttackStart(me->GetVictim());
                    SetMidnight(attumen, me->GetGUID());
                    Talk(SAY_APPEAR, attumen);
                }
            }
            else if (Phase == 2 && HealthBelowPct(25))
            {
                if (Unit* pAttumen = ObjectAccessor::GetUnit(*me, Attumen))
                    Mount(pAttumen);
            }
            else if (Phase == 3)
            {
                if (Mount_Timer)
                {
                    if (Mount_Timer <= diff)
                    {
                        Mount_Timer = 0;
                        me->SetVisible(false);
                        me->GetMotionMaster()->MoveIdle();
                        if (Unit* pAttumen = ObjectAccessor::GetUnit(*me, Attumen))
                        {
                            pAttumen->SetDisplayId(MOUNTED_DISPLAYID);
                            pAttumen->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            if (pAttumen->GetVictim())
                            {
                                pAttumen->GetMotionMaster()->MoveChase(pAttumen->GetVictim());
                                pAttumen->SetTarget(pAttumen->EnsureVictim()->GetGUID());
                            }
                            pAttumen->SetObjectScale(1);
                        }
                    } else Mount_Timer -= diff;
                }
            }

            if (Phase != 3)
                DoMeleeAttackIfReady();
        }

        void Mount(Unit* pAttumen)
        {
            Talk(SAY_MOUNT, pAttumen);
            Phase = 3;
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            pAttumen->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            float angle = me->GetAngle(pAttumen);
            float distance = me->GetDistance2d(pAttumen);
            float newX = me->GetPositionX() + std::cos(angle)*(distance/2);
            float newY = me->GetPositionY() + std::sin(angle)*(distance/2);
            float newZ = 50;
            //me->Relocate(newX, newY, newZ, angle);
            //me->SendMonsterMove(newX, newY, newZ, 0, true, 1000);
            me->GetMotionMaster()->Clear();
            me->GetMotionMaster()->MovePoint(0, newX, newY, newZ);
            distance += 10;
            newX = me->GetPositionX() + std::cos(angle)*(distance/2);
            newY = me->GetPositionY() + std::sin(angle)*(distance/2);
            pAttumen->GetMotionMaster()->Clear();
            pAttumen->GetMotionMaster()->MovePoint(0, newX, newY, newZ);
            //pAttumen->Relocate(newX, newY, newZ, -angle);
            //pAttumen->SendMonsterMove(newX, newY, newZ, 0, true, 1000);
            Mount_Timer = 1000;
        }

        void SetMidnight(Creature* pAttumen, uint64 value)
        {
            ENSURE_AI(boss_attumen::boss_attumenAI, pAttumen->AI())->Midnight = value;
        }
    };
};

void boss_attumen::boss_attumenAI::UpdateAI(uint32 diff)
{
    if (ResetTimer)
    {
        if (ResetTimer <= diff)
        {
            ResetTimer = 0;
            Unit* pMidnight = ObjectAccessor::GetUnit(*me, Midnight);
            if (pMidnight)
            {
                pMidnight->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                pMidnight->SetVisible(true);
            }
            Midnight = 0;
            me->SetVisible(false);
            me->Kill(me);
        } else ResetTimer -= diff;
    }

    //Return since we have no target
    if (!UpdateVictim())
        return;

    if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE))
        return;

    if (CleaveTimer <= diff)
    {
        DoCastVictim(SPELL_SHADOWCLEAVE);
        CleaveTimer = urand(10000, 15000);
    } else CleaveTimer -= diff;

    if (CurseTimer <= diff)
    {
        DoCastVictim(SPELL_INTANGIBLE_PRESENCE);
        CurseTimer = 30000;
    } else CurseTimer -= diff;

    if (RandomYellTimer <= diff)
    {
        Talk(SAY_RANDOM);
        RandomYellTimer = urand(30000, 60000);
    } else RandomYellTimer -= diff;

    if (me->GetUInt32Value(UNIT_FIELD_DISPLAYID) == MOUNTED_DISPLAYID)
    {
        if (ChargeTimer <= diff)
        {
            Unit* target = NULL;
            ThreatContainer::StorageType const &t_list = me->getThreatManager().getThreatList();
            std::vector<Unit*> target_list;
            for (ThreatContainer::StorageType::const_iterator itr = t_list.begin(); itr != t_list.end(); ++itr)
            {
                target = ObjectAccessor::GetUnit(*me, (*itr)->getUnitGuid());
                if (target && !target->IsWithinDist(me, ATTACK_DISTANCE, false))
                    target_list.push_back(target);
                target = NULL;
            }
            if (!target_list.empty())
                target = *(target_list.begin() + rand32() % target_list.size());

            DoCast(target, SPELL_BERSERKER_CHARGE);
            ChargeTimer = 20000;
        } else ChargeTimer -= diff;
    }
    else
    {
        if (HealthBelowPct(25))
        {
            Creature* pMidnight = ObjectAccessor::GetCreature(*me, Midnight);
            if (pMidnight && pMidnight->GetTypeId() == TYPEID_UNIT)
            {
                ENSURE_AI(boss_midnight::boss_midnightAI, (pMidnight->AI()))->Mount(me);
                me->SetHealth(pMidnight->GetHealth());
                DoResetThreat();
            }
        }
    }

    DoMeleeAttackIfReady();
}

void AddSC_boss_attumen()
{
    new boss_attumen();
    new boss_midnight();
}
