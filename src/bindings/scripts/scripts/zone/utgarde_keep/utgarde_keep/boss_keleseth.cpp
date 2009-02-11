/*
 * Copyright (C) 2009 Trinity <http://www.trinitycore.org/>
 *
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
SDName: Boss_Prince_Keleseth
SD%Complete: 80
SDComment: Normal and Heroic Support. Needs Prince Movements, Needs skeletons resurrection, Needs adjustments to blizzlike timers, Needs adjustments to use spell though. Needs Shadowbolt castbar
SDCategory: Utgarde Keep
EndScriptData */

#include "precompiled.h"
#include "def_keep.h"

#define SPELL_SHADOWBOLT                         43667
#define SPELL_SHADOWBOLT_HEROIC                  59389
#define SPELL_FROST_TOMB                         48400
#define SPELL_FROST_TOMB_SUMMON                  42714
#define CREATURE_FROSTTOMB                       23965
#define CREATURE_SKELETON                        23970

#define SAY_AGGRO                                -1574000
#define SAY_KILL                                 -1574001
#define SAY_DEATH                                -1574002
#define SAY_FROST_TOMB                           -1574003
#define SAY_SKELETONS                            -1574004

#define SKELETONSPAWN_Z                          42.8668

float SkeletonSpawnPoint[5][5]=
{
    {156.2559, 259.2093},
	{156.2559, 259.2093},
	{156.2559, 259.2093},
	{156.2559, 259.2093},
	{156.2559, 259.2093},
};

float AttackLoc[3]={197.636, 194.046, 40.8164};

struct TRINITY_DLL_DECL mob_frost_tombAI : public ScriptedAI
{
    mob_frost_tombAI(Creature *c) : ScriptedAI(c)
    {
        Reset();
    }

    uint64 FrostTombGUID;

    void Reset()
    {
        FrostTombGUID = 0;
    }

    void Aggro(Unit* who) {}
    void AttackStart(Unit* who) {}
    void MoveInLineOfSight(Unit* who) {}

    void JustDied(Unit *killer)
    {
        if(FrostTombGUID)
        {
            Unit* FrostTomb = Unit::GetUnit((*m_creature),FrostTombGUID);
            if(FrostTomb)
                FrostTomb->RemoveAurasDueToSpell(SPELL_FROST_TOMB);
        }
    }
};

struct TRINITY_DLL_DECL boss_kelesethAI : public ScriptedAI
{
    boss_kelesethAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Reset();
		Heroic = c->GetMap()->IsHeroic();
    }
	
    ScriptedInstance* pInstance;

    uint32 FrostTombTimer;
    uint32 SummonSkeletonsTimer;
	uint32 RespawnSkeletonsTimer;
	uint32 ShadowboltTimer;
	uint64 SkeletonGUID[5];
	bool Skeletons;
	bool Heroic;
	bool RespawnSkeletons;
	
    void Reset()
	{
		ShadowboltTimer = 0;
		Skeletons = false;

        ResetTimer();

        if(pInstance)
            pInstance->SetData(DATA_PRINCEKELESETH, NOT_STARTED);
	}
	
    void KilledUnit(Unit *victim)
    {
        if(victim == m_creature)
            return;
			
        DoScriptText(SAY_KILL, m_creature);
    }
	
    void JustDied(Unit* killer)  
    {
        if(pInstance)
            pInstance->SetData(DATA_PRINCEKELESETH, DONE);
			
        DoScriptText(SAY_DEATH, m_creature);
    }
	
    void Aggro(Unit* who) 
    {
        if(pInstance)
            pInstance->SetData(DATA_PRINCEKELESETH, IN_PROGRESS);

        DoScriptText(SAY_AGGRO, m_creature);
        DoZoneInCombat();
    }
	
    void ResetTimer(uint32 inc = 0)
    {
        SummonSkeletonsTimer = 5000 + inc;
        FrostTombTimer = 28000 + inc;
    }
	
    void UpdateAI(const uint32 diff) 
    {
        if (!UpdateVictim())
            return;
		
        if(ShadowboltTimer < diff)
        {
            Unit* target = SelectUnit(SELECT_TARGET_TOPAGGRO, 0);
            if(target && target->isAlive() && target->GetTypeId() == TYPEID_PLAYER)
				m_creature->CastSpell(target, Heroic ? SPELL_SHADOWBOLT:SPELL_SHADOWBOLT_HEROIC, true);
            ShadowboltTimer = 2000;
        }else ShadowboltTimer -= diff;

        if((SummonSkeletonsTimer < diff) && !Skeletons)
        {
            Creature* Skeleton;
            DoScriptText(SAY_SKELETONS, m_creature);
            for(uint8 i = 0; i < 5; ++i)
            {
                Skeleton = m_creature->SummonCreature(CREATURE_SKELETON, SkeletonSpawnPoint[i][0], SkeletonSpawnPoint[i][1] , SKELETONSPAWN_Z, 0, TEMPSUMMON_MANUAL_DESPAWN,0);
                if(Skeleton)
                {
                    Skeleton->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                    Skeleton->GetMotionMaster()->MovePoint(0, m_creature->GetPositionX(), m_creature->GetPositionY() , m_creature->GetPositionZ());
                    Skeleton->AddThreat(m_creature, 0.0f);
                    DoZoneInCombat(Skeleton);
                }
            }				
            Skeletons = true;
        }else SummonSkeletonsTimer -= diff;

        if(FrostTombTimer < diff)
        {
            Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 1);
            if(target && target->isAlive() && target->GetTypeId() == TYPEID_PLAYER)
            {
                DoCast(target, SAY_FROST_TOMB, true);
                Creature* Chains = m_creature->SummonCreature(CREATURE_FROSTTOMB, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 20000);
                if(Chains)
                {
                    ((mob_frost_tombAI*)Chains->AI())->FrostTombGUID = target->GetGUID();
                    Chains->CastSpell(target, SPELL_FROST_TOMB, true);
                    
					DoScriptText(SAY_FROST_TOMB, m_creature);

                    FrostTombTimer = 15000;
                }
            }
        }else FrostTombTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_frost_tomb(Creature *_Creature)
{
    return new mob_frost_tombAI(_Creature);
}

CreatureAI* GetAI_boss_keleseth(Creature *_Creature)
{
    return new boss_kelesethAI (_Creature);
}

void AddSC_boss_keleseth()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_keleseth";
    newscript->GetAI = &GetAI_boss_keleseth;
    newscript->RegisterSelf();
	
    newscript = new Script;
    newscript->Name = "mob_frost_tomb";
    newscript->GetAI = &GetAI_mob_frost_tomb;
    newscript->RegisterSelf();
}
