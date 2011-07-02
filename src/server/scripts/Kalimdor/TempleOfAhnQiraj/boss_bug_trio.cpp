/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
SDName: boss_kri, boss_yauj, boss_vem : The Bug Trio
SD%Complete: 100
SDComment:
SDCategory: Temple of Ahn'Qiraj
EndScriptData */

#include "ScriptPCH.h"
#include "temple_of_ahnqiraj.h"

#define SPELL_CLEAVE        26350
#define SPELL_TOXIC_VOLLEY  25812
#define SPELL_POISON_CLOUD  38718                           //Only Spell with right dmg.
#define SPELL_ENRAGE        34624                           //Changed cause 25790 is casted on gamers too. Same prob with old explosion of twin emperors.

#define SPELL_CHARGE        26561
#define SPELL_KNOCKBACK     26027

#define SPELL_HEAL      25807
#define SPELL_FEAR      19408

class boss_kri : public CreatureScript
{
public:
    boss_kri() : CreatureScript("boss_kri") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_kriAI (creature);
    }

    struct boss_kriAI : public ScriptedAI
    {
        boss_kriAI(Creature* c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript *pInstance;

        uint32 Cleave_Timer;
        uint32 ToxicVolley_Timer;
        uint32 Check_Timer;

        bool VemDead;
        bool Death;

        void Reset()
        {
            Cleave_Timer = 4000 + rand()%4000;
            ToxicVolley_Timer = 6000 + rand()%6000;
            Check_Timer = 2000;

            VemDead = false;
            Death = false;
        }

        void EnterCombat(Unit* /*who*/)
        {
        }

        void JustDied(Unit* /*killer*/)
        {
            if (pInstance)
            {
                if (pInstance->GetData(DATA_BUG_TRIO_DEATH) < 2)
                                                                // Unlootable if death
                    me->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);

                pInstance->SetData(DATA_BUG_TRIO_DEATH, 1);
            }
        }
        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            //Cleave_Timer
            if (Cleave_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_CLEAVE);
                Cleave_Timer = 5000 + rand()%7000;
            } else Cleave_Timer -= diff;

            //ToxicVolley_Timer
            if (ToxicVolley_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_TOXIC_VOLLEY);
                ToxicVolley_Timer = 10000 + rand()%5000;
            } else ToxicVolley_Timer -= diff;

            if (!HealthAbovePct(5) && !Death)
            {
                DoCast(me->getVictim(), SPELL_POISON_CLOUD);
                Death = true;
            }

            if (!VemDead)
            {
                //Checking if Vem is dead. If yes we will enrage.
                if (Check_Timer <= diff)
                {
                    if (pInstance && pInstance->GetData(DATA_VEMISDEAD))
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

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_vemAI (creature);
    }

    struct boss_vemAI : public ScriptedAI
    {
        boss_vemAI(Creature* c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript *pInstance;

        uint32 Charge_Timer;
        uint32 KnockBack_Timer;
        uint32 Enrage_Timer;

        bool Enraged;

        void Reset()
        {
            Charge_Timer = 15000 + rand()%12000;
            KnockBack_Timer = 8000 + rand()%12000;
            Enrage_Timer = 120000;

            Enraged = false;
        }

        void JustDied(Unit* /*Killer*/)
        {
            if (pInstance)
            {
                pInstance->SetData(DATA_VEM_DEATH, 0);
                if (pInstance->GetData(DATA_BUG_TRIO_DEATH) < 2)
                                                                // Unlootable if death
                    me->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
                pInstance->SetData(DATA_BUG_TRIO_DEATH, 1);
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            //Charge_Timer
            if (Charge_Timer <= diff)
            {
                Unit* target = NULL;
                target = SelectTarget(SELECT_TARGET_RANDOM, 0);
                if (target)
                {
                    DoCast(target, SPELL_CHARGE);
                    //me->SendMonsterMove(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0, true, 1);
                    AttackStart(target);
                }

                Charge_Timer = 8000 + rand()%8000;
            } else Charge_Timer -= diff;

            //KnockBack_Timer
            if (KnockBack_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_KNOCKBACK);
                if (DoGetThreat(me->getVictim()))
                    DoModifyThreatPercent(me->getVictim(), -80);
                KnockBack_Timer = 15000 + rand()%10000;
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

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_yaujAI (creature);
    }

    struct boss_yaujAI : public ScriptedAI
    {
        boss_yaujAI(Creature* c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript *pInstance;

        uint32 Heal_Timer;
        uint32 Fear_Timer;
        uint32 Check_Timer;

        bool VemDead;

        void Reset()
        {
            Heal_Timer = 25000 + rand()%15000;
            Fear_Timer = 12000 + rand()%12000;
            Check_Timer = 2000;

            VemDead = false;
        }

        void JustDied(Unit* /*Killer*/)
        {
            if (pInstance)
            {
                if (pInstance->GetData(DATA_BUG_TRIO_DEATH) < 2)
                                                                // Unlootable if death
                    me->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
                pInstance->SetData(DATA_BUG_TRIO_DEATH, 1);
            }

            for (uint8 i = 0; i < 10; ++i)
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0);
                Creature* Summoned = me->SummonCreature(15621, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 90000);
                if (Summoned && target)
                    Summoned->AI()->AttackStart(target);
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            //Fear_Timer
            if (Fear_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_FEAR);
                DoResetThreat();
                Fear_Timer = 20000;
            } else Fear_Timer -= diff;

            //Casting Heal to other twins or herself.
            if (Heal_Timer <= diff)
            {
                if (pInstance)
                {
                    Unit* pKri = Unit::GetUnit((*me), pInstance->GetData64(DATA_KRI));
                    Unit* pVem = Unit::GetUnit((*me), pInstance->GetData64(DATA_VEM));

                    switch (urand(0, 2))
                    {
                        case 0:
                            if (pKri)
                                DoCast(pKri, SPELL_HEAL);
                            break;
                        case 1:
                            if (pVem)
                                DoCast(pVem, SPELL_HEAL);
                            break;
                        case 2:
                            DoCast(me, SPELL_HEAL);
                            break;
                    }
                }

                Heal_Timer = 15000+rand()%15000;
            } else Heal_Timer -= diff;

            //Checking if Vem is dead. If yes we will enrage.
            if (Check_Timer <= diff)
            {
                if (!VemDead)
                {
                    if (pInstance)
                    {
                        if (pInstance->GetData(DATA_VEMISDEAD))
                        {
                            DoCast(me, SPELL_ENRAGE);
                            VemDead = true;
                        }
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
