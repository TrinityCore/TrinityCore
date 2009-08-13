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
SDName: Boss_Warchief_Kargath_Bladefist
SD%Complete: 90
SDComment:
SDCategory: Hellfire Citadel, Shattered Halls
EndScriptData */

/* ContentData
boss_warchief_kargath_bladefist
EndContentData */

#include "precompiled.h"

#define SAY_AGGRO1                      -1540042
#define SAY_AGGRO2                      -1540043
#define SAY_AGGRO3                      -1540044
#define SAY_SLAY1                       -1540045
#define SAY_SLAY2                       -1540046
#define SAY_DEATH                       -1540047

#define SPELL_BLADE_DANCE               30739
#define H_SPELL_CHARGE                  25821

#define TARGET_NUM                      5

#define MOB_SHATTERED_ASSASSIN          17695
#define MOB_HEARTHEN_GUARD              17621
#define MOB_SHARPSHOOTER_GUARD          17622
#define MOB_REAVER_GUARD                17623

float AssassEntrance[3] = {275.136,-84.29,2.3}; // y -8
float AssassExit[3] = {184.233,-84.29,2.3}; // y -8
float AddsEntrance[3] = {306.036,-84.29,1.93};

struct TRINITY_DLL_DECL boss_warchief_kargath_bladefistAI : public ScriptedAI
{
    boss_warchief_kargath_bladefistAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
        HeroicMode = m_creature->GetMap()->IsHeroic();
    }

    ScriptedInstance* pInstance;
    bool HeroicMode;

    std::vector<uint64> adds;
    std::vector<uint64> assassins;

    uint32 Charge_timer;
    uint32 Blade_Dance_Timer;
    uint32 Summon_Assistant_Timer;
    uint32 resetcheck_timer;
    uint32 Wait_Timer;

    uint32 Assassins_Timer;

    uint32 summoned;
    bool InBlade;

    uint32 target_num;

    void Reset()
    {
        removeAdds();

        m_creature->SetSpeed(MOVE_RUN,2);
        m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);

        summoned = 2;
        InBlade = false;
        Wait_Timer = 0;

        Charge_timer = 0;
        Blade_Dance_Timer = 45000;
        Summon_Assistant_Timer = 30000;
        Assassins_Timer = 5000;
        resetcheck_timer = 5000;
    }

    void EnterCombat(Unit *who)
    {
        switch (rand()%3)
        {
            case 0:DoScriptText(SAY_AGGRO1, m_creature);break;
            case 1:DoScriptText(SAY_AGGRO2, m_creature);break;
            case 2:DoScriptText(SAY_AGGRO3, m_creature);break;
        }
    }

    void JustSummoned(Creature *summoned)
    {
        switch(summoned->GetEntry())
        {
            case MOB_HEARTHEN_GUARD:
            case MOB_SHARPSHOOTER_GUARD:
            case MOB_REAVER_GUARD:
                summoned->AI()->AttackStart(SelectUnit(SELECT_TARGET_RANDOM,0));
                adds.push_back(summoned->GetGUID());
                break;
            case MOB_SHATTERED_ASSASSIN:
                assassins.push_back(summoned->GetGUID());
                break;
        }
    }

    void KilledUnit(Unit *victim)
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
        {
            switch(rand()%2)
            {
                case 0: DoScriptText(SAY_SLAY1, m_creature); break;
                case 1: DoScriptText(SAY_SLAY2, m_creature); break;
            }
        }
    }

    void JustDied(Unit* Killer)
    {
        DoScriptText(SAY_DEATH, m_creature);
        removeAdds();
    }

    void MovementInform(uint32 type, uint32 id)
    {
        if (InBlade)
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id != 1)
                return;

            if (target_num > 0) // to prevent loops
            {
                Wait_Timer = 1;
                DoCast(m_creature,SPELL_BLADE_DANCE,true);
                target_num--;
            }
        }
    }

    void removeAdds()
    {
        for(std::vector<uint64>::iterator itr = adds.begin(); itr!= adds.end(); ++itr)
        {
            Unit* temp = Unit::GetUnit((*m_creature),*itr);
            if (temp && temp->isAlive())
            {
                (*temp).GetMotionMaster()->Clear(true);
                m_creature->DealDamage(temp,temp->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                CAST_CRE(temp)->RemoveCorpse();
            }
        }
        adds.clear();

        for(std::vector<uint64>::iterator itr = assassins.begin(); itr!= assassins.end(); ++itr)
        {
            Unit* temp = Unit::GetUnit((*m_creature),*itr);
            if (temp && temp->isAlive())
            {
                (*temp).GetMotionMaster()->Clear(true);
                m_creature->DealDamage(temp,temp->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                CAST_CRE(temp)->RemoveCorpse();
            }
        }
        assassins.clear();
    }
    void SpawnAssassin()
    {
        m_creature->SummonCreature(MOB_SHATTERED_ASSASSIN,AssassEntrance[0],AssassEntrance[1]+8, AssassEntrance[2], 0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,30000);
        m_creature->SummonCreature(MOB_SHATTERED_ASSASSIN,AssassEntrance[0],AssassEntrance[1]-8, AssassEntrance[2], 0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,30000);
        m_creature->SummonCreature(MOB_SHATTERED_ASSASSIN,AssassExit[0],AssassExit[1]+8, AssassExit[2], 0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,30000);
        m_creature->SummonCreature(MOB_SHATTERED_ASSASSIN,AssassExit[0],AssassExit[1]-8, AssassExit[2], 0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,30000);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (Assassins_Timer)
            if (Assassins_Timer < diff)
            {
                SpawnAssassin();
                Assassins_Timer = 0;
            }else Assassins_Timer -= diff;

        if (InBlade)
        {
            if (Wait_Timer)
                if (Wait_Timer < diff)
                {
                    if (target_num <= 0)
                    {
                        // stop bladedance
                        InBlade = false;
                        m_creature->SetSpeed(MOVE_RUN,2);
                        (*m_creature).GetMotionMaster()->MoveChase(m_creature->getVictim());
                        Blade_Dance_Timer = 30000;
                        Wait_Timer = 0;
                        if (HeroicMode)
                            Charge_timer = 5000;
                    }
                    else
                    {
                        //move in bladedance
                        float x,y,randx,randy;
                        randx = (rand()%40);
                        randy = (rand()%40);
                        x = 210+ randx ;
                        y = -60- randy ;
                        (*m_creature).GetMotionMaster()->MovePoint(1,x,y,m_creature->GetPositionZ());
                        Wait_Timer = 0;
                    }
                }else Wait_Timer -= diff;
        }
        else
        {
            if (Blade_Dance_Timer)
                if (Blade_Dance_Timer < diff)
                {
                    target_num = TARGET_NUM;
                    Wait_Timer = 1;
                    InBlade = true;
                    Blade_Dance_Timer = 0;
                    m_creature->SetSpeed(MOVE_RUN,4);
                    return;
                }else Blade_Dance_Timer -= diff;

            if (Charge_timer)
                if (Charge_timer < diff)
                {
                    DoCast(SelectUnit(SELECT_TARGET_RANDOM,0),H_SPELL_CHARGE);
                    Charge_timer = 0;
                }else Charge_timer -= diff;

            if (Summon_Assistant_Timer < diff)
            {
                Unit* target = NULL;

                for(uint8 i = 0; i < summoned; ++i)
                {
                    switch(rand()%3)
                    {
                        case 0: m_creature->SummonCreature(MOB_HEARTHEN_GUARD,AddsEntrance[0],AddsEntrance[1], AddsEntrance[2], 0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,30000); break;
                        case 1: m_creature->SummonCreature(MOB_SHARPSHOOTER_GUARD,AddsEntrance[0],AddsEntrance[1], AddsEntrance[2], 0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,30000); break;
                        case 2: m_creature->SummonCreature(MOB_REAVER_GUARD,AddsEntrance[0],AddsEntrance[1], AddsEntrance[2], 0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,30000); break;
                    }
                }
                if (rand()%100 < 20) summoned++;
                    Summon_Assistant_Timer = 25000 + (rand()%10000) ;
            }else Summon_Assistant_Timer -= diff;

            DoMeleeAttackIfReady();
        }

        if (resetcheck_timer < diff)
        {
            uint32 tempx,tempy;
            tempx = uint32(m_creature->GetPositionX());
            tempy = uint32(m_creature->GetPositionY());
            if (tempx > 255 || tempx < 205)
            {
                EnterEvadeMode();
                return;
            }
            resetcheck_timer = 5000;
        }else resetcheck_timer -= diff;
    }
};

CreatureAI* GetAI_boss_warchief_kargath_bladefist(Creature *_Creature)
{
    return new boss_warchief_kargath_bladefistAI (_Creature);
}

void AddSC_boss_warchief_kargath_bladefist()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_warchief_kargath_bladefist";
    newscript->GetAI = &GetAI_boss_warchief_kargath_bladefist;
    newscript->RegisterSelf();
}

