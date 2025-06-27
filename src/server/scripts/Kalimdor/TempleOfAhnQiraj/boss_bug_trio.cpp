/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
SDName: boss_kri, boss_yauj, boss_vem : The Bug Trio
SD%Complete: 100
SDComment:
SDCategory: Temple of Ahn'Qiraj
EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "temple_of_ahnqiraj.h"
#include "TemporarySummon.h"

enum Spells
{
    SPELL_CLEAVE       = 26350,
    SPELL_TOXIC_VOLLEY = 25812,
    SPELL_POISON_CLOUD = 38718, //Only Spell with right dmg.
    SPELL_ENRAGE       = 34624, //Changed cause 25790 is cast on gamers too. Same prob with old explosion of twin emperors.

    SPELL_CHARGE       = 26561,
    SPELL_KNOCKBACK    = 26027,

    SPELL_HEAL         = 25807,
    SPELL_FEAR         = 19408
};

class boss_kri : public CreatureScript
{
public:
    boss_kri() : CreatureScript("boss_kri") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetAQ40AI<boss_kriAI>(creature);
    }

    struct boss_kriAI : public BossAI
    {
        boss_kriAI(Creature* creature) : BossAI(creature, DATA_BUG_TRIO)
        {
            Initialize();
        }

        void Initialize()
        {
            Cleave_Timer = urand(4000, 8000);
            ToxicVolley_Timer = urand(6000, 12000);
            Check_Timer = 2000;

            VemDead = false;
            Death = false;
        }

        uint32 Cleave_Timer;
        uint32 ToxicVolley_Timer;
        uint32 Check_Timer;

        bool VemDead;
        bool Death;

        void Reset() override
        {
            Initialize();
            _Reset();
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (instance->GetData(DATA_BUG_TRIO_DEATH) < 2)// Unlootable if death
                me->RemoveDynamicFlag(UNIT_DYNFLAG_LOOTABLE);

            instance->SetData(DATA_BUG_TRIO_DEATH, 1);
        }
        void UpdateAI(uint32 diff) override
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            //Cleave_Timer
            if (Cleave_Timer <= diff)
            {
                DoCastVictim(SPELL_CLEAVE);
                Cleave_Timer = urand(5000, 12000);
            } else Cleave_Timer -= diff;

            //ToxicVolley_Timer
            if (ToxicVolley_Timer <= diff)
            {
                DoCastVictim(SPELL_TOXIC_VOLLEY);
                ToxicVolley_Timer = urand(10000, 15000);
            } else ToxicVolley_Timer -= diff;

            if (!HealthAbovePct(5) && !Death)
            {
                DoCastVictim(SPELL_POISON_CLOUD);
                Death = true;
            }

            if (!VemDead)
            {
                //Checking if Vem is dead. If yes we will enrage.
                if (Check_Timer <= diff)
                {
                    if (instance->GetData(DATA_VEMISDEAD))
                    {
                        DoCast(me, SPELL_ENRAGE);
                        VemDead = true;
                    }
                    Check_Timer = 2000;
                } else Check_Timer -=diff;
            }

            DoMeleeAttackIfReady();
        }
    };

};

class boss_vem : public CreatureScript
{
public:
    boss_vem() : CreatureScript("boss_vem") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetAQ40AI<boss_vemAI>(creature);
    }

    struct boss_vemAI : public BossAI
    {
        boss_vemAI(Creature* creature) : BossAI(creature, DATA_BUG_TRIO)
        {
            Initialize();
        }

        void Initialize()
        {
            Charge_Timer = urand(15000, 27000);
            KnockBack_Timer = urand(8000, 20000);
            Enrage_Timer = 120000;

            Enraged = false;
        }

        uint32 Charge_Timer;
        uint32 KnockBack_Timer;
        uint32 Enrage_Timer;

        bool Enraged;

        void Reset() override
        {
            Initialize();
            _Reset();
        }

        void JustDied(Unit* /*killer*/) override
        {
            instance->SetData(DATA_VEM_DEATH, 0);
            if (instance->GetData(DATA_BUG_TRIO_DEATH) < 2)// Unlootable if death
                me->RemoveDynamicFlag(UNIT_DYNFLAG_LOOTABLE);
            instance->SetData(DATA_BUG_TRIO_DEATH, 1);
        }

        void UpdateAI(uint32 diff) override
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            //Charge_Timer
            if (Charge_Timer <= diff)
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                {
                    DoCast(target, SPELL_CHARGE);
                    //me->SendMonsterMove(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0, true, 1);
                    AttackStart(target);
                }

                Charge_Timer = urand(8000, 16000);
            } else Charge_Timer -= diff;

            //KnockBack_Timer
            if (KnockBack_Timer <= diff)
            {
                DoCastVictim(SPELL_KNOCKBACK);
                if (GetThreat(me->GetVictim()))
                    ModifyThreatByPercent(me->GetVictim(), -80);
                KnockBack_Timer = urand(15000, 25000);
            } else KnockBack_Timer -= diff;

            //Enrage_Timer
            if (!Enraged && Enrage_Timer <= diff)
            {
                DoCast(me, SPELL_ENRAGE);
                Enraged = true;
            } else Charge_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

class boss_yauj : public CreatureScript
{
public:
    boss_yauj() : CreatureScript("boss_yauj") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetAQ40AI<boss_yaujAI>(creature);
    }

    struct boss_yaujAI : public BossAI
    {
        boss_yaujAI(Creature* creature) : BossAI(creature, DATA_BUG_TRIO)
        {
            Initialize();
        }

        void Initialize()
        {
            Heal_Timer = urand(25000, 40000);
            Fear_Timer = urand(12000, 24000);
            Check_Timer = 2000;

            VemDead = false;
        }

        uint32 Heal_Timer;
        uint32 Fear_Timer;
        uint32 Check_Timer;

        bool VemDead;

        void Reset() override
        {
            Initialize();
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (instance->GetData(DATA_BUG_TRIO_DEATH) < 2)// Unlootable if death
                me->RemoveDynamicFlag(UNIT_DYNFLAG_LOOTABLE);
            instance->SetData(DATA_BUG_TRIO_DEATH, 1);

            for (uint8 i = 0; i < 10; ++i)
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                {
                    if (Creature* Summoned = me->SummonCreature(15621, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 90s))
                        Summoned->AI()->AttackStart(target);
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            //Fear_Timer
            if (Fear_Timer <= diff)
            {
                DoCastVictim(SPELL_FEAR);
                ResetThreatList();
                Fear_Timer = 20000;
            } else Fear_Timer -= diff;

            //Casting Heal to other twins or herself.
            if (Heal_Timer <= diff)
            {
                switch (urand(0, 2))
                {
                    case 0:
                        if (Creature* kri = instance->GetCreature(DATA_KRI))
                            DoCast(kri, SPELL_HEAL);
                        break;
                    case 1:
                        if (Creature* vem = instance->GetCreature(DATA_VEM))
                            DoCast(vem, SPELL_HEAL);
                        break;
                    case 2:
                        DoCast(me, SPELL_HEAL);
                        break;
                }

                Heal_Timer = 15000 + rand32() % 15000;
            } else Heal_Timer -= diff;

            //Checking if Vem is dead. If yes we will enrage.
            if (Check_Timer <= diff)
            {
                if (!VemDead)
                {
                    if (instance->GetData(DATA_VEMISDEAD))
                    {
                        DoCast(me, SPELL_ENRAGE);
                        VemDead = true;
                    }
                }
                Check_Timer = 2000;
            } else Check_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_bug_trio()
{
    new boss_kri();
    new boss_vem();
    new boss_yauj();
}
