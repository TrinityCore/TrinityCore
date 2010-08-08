/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Sartura
SD%Complete: 95
SDComment:
SDCategory: Temple of Ahn'Qiraj
EndScriptData */

#include "ScriptPCH.h"

#define SAY_AGGRO                   -1531008
#define SAY_SLAY                    -1531009
#define SAY_DEATH                   -1531010

#define SPELL_WHIRLWIND                              26083
#define SPELL_ENRAGE                                 28747            //Not sure if right ID.
#define SPELL_ENRAGEHARD                             28798

//Guard Spell
#define SPELL_WHIRLWINDADD                           26038
#define SPELL_KNOCKBACK                              26027

class boss_sartura : public CreatureScript
{
public:
    boss_sartura() : CreatureScript("boss_sartura") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_sarturaAI (pCreature);
    }

    struct boss_sarturaAI : public ScriptedAI
    {
        boss_sarturaAI(Creature *c) : ScriptedAI(c) {}

        uint32 WhirlWind_Timer;
        uint32 WhirlWindRandom_Timer;
        uint32 WhirlWindEnd_Timer;
        uint32 AggroReset_Timer;
        uint32 AggroResetEnd_Timer;
        uint32 EnrageHard_Timer;

        bool Enraged;
        bool EnragedHard;
        bool WhirlWind;
        bool AggroReset;

        void Reset()
        {
            WhirlWind_Timer = 30000;
            WhirlWindRandom_Timer = 3000 + rand()%4000;
            WhirlWindEnd_Timer = 15000;
            AggroReset_Timer = 45000 + rand()%10000;
            AggroResetEnd_Timer = 5000;
            EnrageHard_Timer = 10*60000;

            WhirlWind = false;
            AggroReset = false;
            Enraged = false;
            EnragedHard = false;

        }

        void EnterCombat(Unit * /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);
        }

         void JustDied(Unit* /*Killer*/)
         {
             DoScriptText(SAY_DEATH, me);
         }

         void KilledUnit(Unit* /*victim*/)
         {
             DoScriptText(SAY_SLAY, me);
         }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (WhirlWind)
            {
                if (WhirlWindRandom_Timer <= diff)
                {
                    //Attack random Gamers
                    Unit *pTarget = NULL;
                    pTarget = SelectUnit(SELECT_TARGET_RANDOM,1);
                    if (pTarget)
                    me->AddThreat(pTarget, 1.0f);
                    me->TauntApply(pTarget);
                    AttackStart(pTarget);

                    WhirlWindRandom_Timer = 3000 + rand()%4000;
                } else WhirlWindRandom_Timer -= diff;

                if (WhirlWindEnd_Timer <= diff)
                {
                    WhirlWind = false;
                    WhirlWind_Timer = 25000 + rand()%15000;
                } else WhirlWindEnd_Timer -= diff;
            }

            if (!WhirlWind)
            {
                if (WhirlWind_Timer <= diff)
                {
                    DoCast(me, SPELL_WHIRLWIND);
                    WhirlWind = true;
                    WhirlWindEnd_Timer = 15000;
                } else WhirlWind_Timer -= diff;

                if (AggroReset_Timer <= diff)
                {
                    //Attack random Gamers
                    Unit *pTarget = NULL;
                    pTarget = SelectUnit(SELECT_TARGET_RANDOM,1);
                    if (pTarget)
                    me->AddThreat(pTarget, 1.0f);
                    me->TauntApply(pTarget);
                    AttackStart(pTarget);

                        AggroReset = true;
                        AggroReset_Timer = 2000 + rand()%3000;
                } else AggroReset_Timer -= diff;

                if (AggroReset)
                {
                    if (AggroResetEnd_Timer <= diff)
                    {
                        AggroReset = false;
                        AggroResetEnd_Timer = 5000;
                        AggroReset_Timer = 35000 + rand()%10000;
                    } else AggroResetEnd_Timer -= diff;
                }

                //If she is 20% enrage
                if (!Enraged)
                {
                    if (me->GetHealth()*100 / me->GetMaxHealth() <= 20 && !me->IsNonMeleeSpellCasted(false))
                    {
                        DoCast(me, SPELL_ENRAGE);
                        Enraged = true;
                    }
                }

                //After 10 minutes hard enrage
                if (!EnragedHard)
                {
                    if (EnrageHard_Timer <= diff)
                    {
                        DoCast(me, SPELL_ENRAGEHARD);
                        EnragedHard = true;
                    } else EnrageHard_Timer -= diff;
                }

                DoMeleeAttackIfReady();
            }
        }
    };

};

class mob_sartura_royal_guard : public CreatureScript
{
public:
    mob_sartura_royal_guard() : CreatureScript("mob_sartura_royal_guard") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_sartura_royal_guardAI (pCreature);
    }

    struct mob_sartura_royal_guardAI : public ScriptedAI
    {
        mob_sartura_royal_guardAI(Creature *c) : ScriptedAI(c) {}

        uint32 WhirlWind_Timer;
        uint32 WhirlWindRandom_Timer;
        uint32 WhirlWindEnd_Timer;
        uint32 AggroReset_Timer;
        uint32 AggroResetEnd_Timer;
        uint32 KnockBack_Timer;

        bool WhirlWind;
        bool AggroReset;

        void Reset()
        {
            WhirlWind_Timer = 30000;
            WhirlWindRandom_Timer = 3000 + rand()%4000;
            WhirlWindEnd_Timer = 15000;
            AggroReset_Timer = 45000 + rand()%10000;
            AggroResetEnd_Timer = 5000;
            KnockBack_Timer = 10000;

            WhirlWind = false;
            AggroReset = false;
        }

        void EnterCombat(Unit * /*who*/)
        {
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (!WhirlWind && WhirlWind_Timer <= diff)
            {
                DoCast(me, SPELL_WHIRLWINDADD);
                WhirlWind = true;
                WhirlWind_Timer = 25000 + rand()%15000;
                WhirlWindEnd_Timer = 15000;
            } else WhirlWind_Timer -= diff;

            if (WhirlWind)
            {
                if (WhirlWindRandom_Timer <= diff)
                {
                    //Attack random Gamers
                    Unit *pTarget = NULL;
                    pTarget = SelectUnit(SELECT_TARGET_RANDOM,1);
                    if (pTarget)
                    me->AddThreat(pTarget, 1.0f);
                    me->TauntApply(pTarget);
                    AttackStart(pTarget);

                    WhirlWindRandom_Timer = 3000 + rand()%4000;
                } else WhirlWindRandom_Timer -= diff;

                if (WhirlWindEnd_Timer <= diff)
                {
                    WhirlWind = false;
                } else WhirlWindEnd_Timer -= diff;
            }

            if (!WhirlWind)
            {
                if (AggroReset_Timer <= diff)
                {
                    //Attack random Gamers
                    Unit *pTarget = NULL;
                    pTarget = SelectUnit(SELECT_TARGET_RANDOM,1);
                    if (pTarget)
                    me->AddThreat(pTarget, 1.0f);
                    me->TauntApply(pTarget);
                    AttackStart(pTarget);

                    AggroReset = true;
                    AggroReset_Timer = 2000 + rand()%3000;
                } else AggroReset_Timer -= diff;

                if (KnockBack_Timer <= diff)
                {
                    DoCast(me, SPELL_WHIRLWINDADD);
                    KnockBack_Timer = 10000 + rand()%10000;
                } else KnockBack_Timer -= diff;
            }

            if (AggroReset)
            {
                if (AggroResetEnd_Timer <= diff)
                {
                    AggroReset = false;
                    AggroResetEnd_Timer = 5000;
                    AggroReset_Timer = 30000 + rand()%10000;
                } else AggroResetEnd_Timer -= diff;
            }

            DoMeleeAttackIfReady();
        }
    };

};



void AddSC_boss_sartura()
{
    new boss_sartura();
    new mob_sartura_royal_guard();
}
