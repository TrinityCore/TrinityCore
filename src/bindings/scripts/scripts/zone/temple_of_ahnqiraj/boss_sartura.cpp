/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: Boss_Sartura
SD%Complete: 95
SDComment:
SDCategory: Temple of Ahn'Qiraj
EndScriptData */

#include "precompiled.h"

#define SAY_AGGRO                   -1531008
#define SAY_SLAY                    -1531009
#define SAY_DEATH                   -1531010

#define SPELL_WHIRLWIND                              26083
#define SPELL_ENRAGE                                 28747            //Not sure if right ID.
#define SPELL_ENRAGEHARD                             28798

//Guard Spell
#define SPELL_WHIRLWINDADD                           26038
#define SPELL_KNOCKBACK                              26027


struct TRINITY_DLL_DECL boss_sarturaAI : public ScriptedAI
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

    void Aggro(Unit *who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
    }

     void JustDied(Unit* Killer)
     {
         DoScriptText(SAY_DEATH, m_creature);
     }

     void KilledUnit(Unit* victim)
     {
         DoScriptText(SAY_SLAY, m_creature);
     }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (WhirlWind)
        {
            if (WhirlWindRandom_Timer < diff)
            {
                //Attack random Gamers
                Unit* target = NULL;
                target = SelectUnit(SELECT_TARGET_RANDOM,1);
                if (target)
                m_creature->AddThreat(target, 1.0f);
                m_creature->TauntApply(target);
                AttackStart(target);

                WhirlWindRandom_Timer = 3000 + rand()%4000;
            }else WhirlWindRandom_Timer -= diff;

            if (WhirlWindEnd_Timer < diff)
            {
                WhirlWind = false;
                WhirlWind_Timer = 25000 + rand()%15000;
            }else WhirlWindEnd_Timer -= diff;
        }

        if (!WhirlWind)
        {
            if (WhirlWind_Timer < diff)
            {
                DoCast(m_creature, SPELL_WHIRLWIND);
                WhirlWind = true;
                WhirlWindEnd_Timer = 15000;
            }else WhirlWind_Timer -= diff;

            if (AggroReset_Timer < diff)
            {
                //Attack random Gamers
                Unit* target = NULL;
                target = SelectUnit(SELECT_TARGET_RANDOM,1);
                if (target)
                m_creature->AddThreat(target, 1.0f);
                m_creature->TauntApply(target);
                AttackStart(target);

                    AggroReset = true;
                    AggroReset_Timer = 2000 + rand()%3000;
            }else AggroReset_Timer -= diff;

            if (AggroReset)
            {
                if (AggroResetEnd_Timer <diff)
                {
                    AggroReset = false;
                    AggroResetEnd_Timer = 5000;
                    AggroReset_Timer = 35000 + rand()%10000;
                } else AggroResetEnd_Timer -= diff;
            }

            //If she is 20% enrage
            if (!Enraged)
            {
                if (m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 20 && !m_creature->IsNonMeleeSpellCasted(false))
                {
                    DoCast(m_creature, SPELL_ENRAGE);
                    Enraged = true;
                }
            }

            //After 10 minutes hard enrage
            if (!EnragedHard)
            {
                if (EnrageHard_Timer < diff)
                {
                    DoCast(m_creature, SPELL_ENRAGEHARD);
                    EnragedHard = true;
                } else EnrageHard_Timer -= diff;
            }

            DoMeleeAttackIfReady();
        }
    }
};


struct TRINITY_DLL_DECL mob_sartura_royal_guardAI : public ScriptedAI
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

    void Aggro(Unit *who)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (!WhirlWind && WhirlWind_Timer < diff)
        {
            DoCast(m_creature, SPELL_WHIRLWINDADD);
            WhirlWind = true;
            WhirlWind_Timer = 25000 + rand()%15000;
            WhirlWindEnd_Timer = 15000;
        }else WhirlWind_Timer -= diff;

        if (WhirlWind)
        {
            if (WhirlWindRandom_Timer < diff)
            {
                //Attack random Gamers
                Unit* target = NULL;
                target = SelectUnit(SELECT_TARGET_RANDOM,1);
                if (target)
                m_creature->AddThreat(target, 1.0f);
                m_creature->TauntApply(target);
                AttackStart(target);

                WhirlWindRandom_Timer = 3000 + rand()%4000;
            }else WhirlWindRandom_Timer -= diff;

            if (WhirlWindEnd_Timer < diff)
            {
                WhirlWind = false;
            }else WhirlWindEnd_Timer -= diff;
        }

        if (!WhirlWind)
        {
            if (AggroReset_Timer < diff)
            {
                //Attack random Gamers
                Unit* target = NULL;
                target = SelectUnit(SELECT_TARGET_RANDOM,1);
                if (target)
                m_creature->AddThreat(target, 1.0f);
                m_creature->TauntApply(target);
                AttackStart(target);

                AggroReset = true;
                AggroReset_Timer = 2000 + rand()%3000;
            }else AggroReset_Timer -= diff;

            if (KnockBack_Timer < diff)
            {
                DoCast(m_creature, SPELL_WHIRLWINDADD);
                KnockBack_Timer = 10000 + rand()%10000;
            }else KnockBack_Timer -= diff;
        }

        if (AggroReset)
        {
            if (AggroResetEnd_Timer <diff)
            {
                AggroReset = false;
                AggroResetEnd_Timer = 5000;
                AggroReset_Timer = 30000 + rand()%10000;
            } else AggroResetEnd_Timer -= diff;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_sartura(Creature *_Creature)
{
    return new boss_sarturaAI (_Creature);
}

CreatureAI* GetAI_mob_sartura_royal_guard(Creature *_Creature)
{
    return new mob_sartura_royal_guardAI (_Creature);
}

void AddSC_boss_sartura()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_sartura";
    newscript->GetAI = &GetAI_boss_sartura;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_sartura_royal_guard";
    newscript->GetAI = &GetAI_mob_sartura_royal_guard;
    newscript->RegisterSelf();
}

