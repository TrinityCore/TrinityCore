/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: Boss_Midnight
SD%Complete: 100
SDComment:
SDCategory: Karazhan
EndScriptData */

#include "precompiled.h"

#define SAY_MIDNIGHT_KILL           -1532000
#define SAY_APPEAR1                 -1532001
#define SAY_APPEAR2                 -1532002
#define SAY_APPEAR3                 -1532003
#define SAY_MOUNT                   -1532004
#define SAY_KILL1                   -1532005
#define SAY_KILL2                   -1532006
#define SAY_DISARMED                -1532007
#define SAY_DEATH                   -1532008
#define SAY_RANDOM1                 -1532009
#define SAY_RANDOM2                 -1532010

#define SPELL_SHADOWCLEAVE          29832
#define SPELL_INTANGIBLE_PRESENCE   29833
#define SPELL_BERSERKER_CHARGE      26561                   //Only when mounted

#define MOUNTED_DISPLAYID           16040

//Attumen (TODO: Use the summoning spell instead of creature id. It works , but is not convenient for us)
#define SUMMON_ATTUMEN 15550

struct TRINITY_DLL_DECL boss_midnightAI : public ScriptedAI
{
    boss_midnightAI(Creature *c) : ScriptedAI(c) {}

    uint64 Attumen;
    uint8 Phase;
    uint32 Mount_Timer;

    void Reset()
    {
        Phase = 1;
        Attumen = 0;
        Mount_Timer = 0;

        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->SetVisibility(VISIBILITY_ON);
    }

    void Aggro(Unit* who) {}

    void KilledUnit(Unit *victim)
    {
        if(Phase == 2)
        {
            if (Unit *pUnit = Unit::GetUnit(*m_creature, Attumen))
            DoScriptText(SAY_MIDNIGHT_KILL, pUnit);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if(Phase == 1 && (m_creature->GetHealth()*100)/m_creature->GetMaxHealth() < 95)
        {
            Phase = 2;
            Creature *pAttumen = DoSpawnCreature(SUMMON_ATTUMEN, 0, 0, 0, 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 30000);
            if(pAttumen)
            {
                Attumen = pAttumen->GetGUID();
                pAttumen->AI()->AttackStart(m_creature->getVictim());
                SetMidnight(pAttumen, m_creature->GetGUID());
                switch(rand()%3)
                {
                case 0: DoScriptText(SAY_APPEAR1, pAttumen); break;
                case 1: DoScriptText(SAY_APPEAR2, pAttumen); break;
                case 2: DoScriptText(SAY_APPEAR3, pAttumen); break;
                }
            }
        }
        else if(Phase == 2 && (m_creature->GetHealth()*100)/m_creature->GetMaxHealth() < 25)
        {
            if (Unit *pAttumen = Unit::GetUnit(*m_creature, Attumen))
                Mount(pAttumen);
        }
        else if(Phase ==3)
        {
            if(Mount_Timer)
            {
                if(Mount_Timer <= diff)
                {
                    Mount_Timer = 0;
                    m_creature->SetVisibility(VISIBILITY_OFF);
                    m_creature->GetMotionMaster()->MoveIdle();
                    if (Unit *pAttumen = Unit::GetUnit(*m_creature, Attumen))
                    {
                        pAttumen->SetUInt32Value(UNIT_FIELD_DISPLAYID, MOUNTED_DISPLAYID);
                        pAttumen->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        if(pAttumen->getVictim())
                        {
                            pAttumen->GetMotionMaster()->MoveChase(pAttumen->getVictim());
                            pAttumen->SetUInt64Value(UNIT_FIELD_TARGET, pAttumen->getVictim()->GetGUID());
                        }
                        pAttumen->SetFloatValue(OBJECT_FIELD_SCALE_X,1);
                    }
                } else Mount_Timer -= diff;
            }
        }

        if(Phase != 3)
            DoMeleeAttackIfReady();
    }

    void Mount(Unit *pAttumen)
    {
        DoScriptText(SAY_MOUNT, pAttumen);
        Phase = 3;
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        pAttumen->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        float angle = m_creature->GetAngle(pAttumen);
        float distance = m_creature->GetDistance2d(pAttumen);
        float newX = m_creature->GetPositionX() + cos(angle)*(distance/2) ;
        float newY = m_creature->GetPositionY() + sin(angle)*(distance/2) ;
        float newZ = 50;
        //m_creature->Relocate(newX,newY,newZ,angle);
        //m_creature->SendMonsterMove(newX, newY, newZ, 0, true, 1000);
        m_creature->GetMotionMaster()->Clear();
        m_creature->GetMotionMaster()->MovePoint(0, newX, newY, newZ);
        distance += 10;
        newX = m_creature->GetPositionX() + cos(angle)*(distance/2) ;
        newY = m_creature->GetPositionY() + sin(angle)*(distance/2) ;
        pAttumen->GetMotionMaster()->Clear();
        pAttumen->GetMotionMaster()->MovePoint(0, newX, newY, newZ);
        //pAttumen->Relocate(newX,newY,newZ,-angle);
        //pAttumen->SendMonsterMove(newX, newY, newZ, 0, true, 1000);
        Mount_Timer = 1000;
    }

    void SetMidnight(Creature *, uint64);                   //Below ..
};

CreatureAI* GetAI_boss_midnight(Creature *_Creature)
{
    return new boss_midnightAI(_Creature);
}

struct TRINITY_DLL_DECL boss_attumenAI : public ScriptedAI
{
    boss_attumenAI(Creature *c) : ScriptedAI(c)
    {
        Phase = 1;

        CleaveTimer = 10000 + (rand()%6)*1000;
        CurseTimer = 30000;
        RandomYellTimer = 30000 + (rand()%31)*1000;         //Occasionally yell
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

    void Reset()
    {
        ResetTimer = 2000;
    }

    void Aggro(Unit* who) {}

    void KilledUnit(Unit *victim)
    {
        switch(rand()%2)
        {
        case 0: DoScriptText(SAY_KILL1, m_creature); break;
        case 1: DoScriptText(SAY_KILL2, m_creature); break;
        }
    }

    void JustDied(Unit *victim)
    {
        DoScriptText(SAY_DEATH, m_creature);
        if (Unit *pMidnight = Unit::GetUnit(*m_creature, Midnight))
            pMidnight->DealDamage(pMidnight, pMidnight->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
    }

    void UpdateAI(const uint32 diff)
    {
        if(ResetTimer)
        {
            if(ResetTimer <= diff)
            {
                ResetTimer = 0;
                Unit *pMidnight = Unit::GetUnit(*m_creature, Midnight);
                if(pMidnight)
                {
                    pMidnight->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    pMidnight->SetVisibility(VISIBILITY_ON);
                }
                Midnight = 0;
                m_creature->SetVisibility(VISIBILITY_OFF);
                m_creature->DealDamage(m_creature, m_creature->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            }
        } else ResetTimer -= diff;

        //Return since we have no target
        if (!UpdateVictim())
            return;

        if(m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE ))
            return;

        if(CleaveTimer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_SHADOWCLEAVE);
            CleaveTimer = 10000 + (rand()%6)*1000;
        } else CleaveTimer -= diff;

        if(CurseTimer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_INTANGIBLE_PRESENCE);
            CurseTimer = 30000;
        } else CurseTimer -= diff;

        if(RandomYellTimer < diff)
        {
            switch(rand()%2)
            {
            case 0: DoScriptText(SAY_RANDOM1, m_creature); break;
            case 1: DoScriptText(SAY_RANDOM2, m_creature); break;
            }
            RandomYellTimer = 30000 + (rand()%31)*1000;
        } else RandomYellTimer -= diff;

        if(m_creature->GetUInt32Value(UNIT_FIELD_DISPLAYID) == MOUNTED_DISPLAYID)
        {
            if(ChargeTimer < diff)
            {
                Unit *target;
                std::list<HostilReference *> t_list = m_creature->getThreatManager().getThreatList();
                std::vector<Unit *> target_list;
                for(std::list<HostilReference *>::iterator itr = t_list.begin(); itr!= t_list.end(); ++itr)
                {
                    target = Unit::GetUnit(*m_creature, (*itr)->getUnitGuid());
                    if(target && target->GetDistance2d(m_creature) > 5)
                        target_list.push_back(target);
                    target = NULL;
                }
                if(target_list.size())
                    target = *(target_list.begin()+rand()%target_list.size());

                DoCast(target, SPELL_BERSERKER_CHARGE);
                ChargeTimer = 20000;
            } else ChargeTimer -= diff;
        }
        else
        {
            if( (m_creature->GetHealth()*100)/m_creature->GetMaxHealth() < 25)
            {
                Creature *pMidnight = Unit::GetCreature(*m_creature, Midnight);
                if(pMidnight && pMidnight->GetTypeId() == TYPEID_UNIT)
                {
                    ((boss_midnightAI*)(pMidnight->AI()))->Mount(m_creature);
                    m_creature->SetHealth(pMidnight->GetHealth());
                }
            }
        }

        DoMeleeAttackIfReady();
    }

    void SpellHit(Unit *source, const SpellEntry *spell)
    {
        if(spell->Mechanic == MECHANIC_DISARM)
            DoScriptText(SAY_DISARMED, m_creature);
    }
};

void boss_midnightAI::SetMidnight(Creature *pAttumen, uint64 value)
{
    ((boss_attumenAI*)pAttumen->AI())->Midnight = value;
}

CreatureAI* GetAI_boss_attumen(Creature *_Creature)
{
    return new boss_attumenAI (_Creature);
}

void AddSC_boss_attumen()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_attumen";
    newscript->GetAI = &GetAI_boss_attumen;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="boss_midnight";
    newscript->GetAI = &GetAI_boss_midnight;
    newscript->RegisterSelf();
}

