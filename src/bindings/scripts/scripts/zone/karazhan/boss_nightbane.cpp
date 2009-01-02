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
SDName: Boss_Nightbane
SD%Complete: 50
SDComment: skelleton adds, optimice some "if"s, timers, rain of bones applied self(!?)
SDCategory: Karazhan
EndScriptData */

#include "precompiled.h"
#include "def_karazhan.h"
 
//phase 1
#define SPELL_BELLOWING_ROAR        39427
#define SPELL_CHARRED_EARTH         30129 //Also 30209 (Target Charred Earth) triggers this
#define SPELL_DISTRACTING_ASH       30130
#define SPELL_SMOLDERING_BREATH     30210
#define SPELL_TAIL_SWEEP            25653
//phase 2
#define SPELL_RAIN_OF_BONES         37098
#define SPELL_SMOKING_BLAST         37057
#define SPELL_FIREBALL_BARRAGE      30282
#define SPELL_SEARING_CINDERS       30127

float IntroWay[8][3] = 
{
    {-11053.37,-1794.48,149},
    {-11141.07,-1841.40,125},
    {-11187.28,-1890.23,125},
    {-11189.20,-1931.25,125},
    {-11153.76,-1948.93,125},
    {-11128.73,-1929.75,125},
    {-11140   , -1915  ,122}, 
    {-11163   , -1903  ,91.473}
};

//float IntroWay[5][3] = 
//{
//    {-11000.00, -1765.75, 140.40},
//    {-11000.00, -1765.75, 171.00},
//    {-11173.67, -1832.26, 117.76},
//    {-11142.75, -1916.78, 119.769},
//    {-11161.91, -1911.148, 91.473}
//};

struct TRINITY_DLL_DECL boss_nightbaneAI : public ScriptedAI
{
    boss_nightbaneAI(Creature* c) : ScriptedAI(c)
    {
		pInstance = ((ScriptedInstance*)c->GetInstanceData());
        intro = true;
        Reset();    
    }

	ScriptedInstance* pInstance;

    uint32 phase;

    bool rainbones;

    uint32 bellowingroar_timer;
    uint32 charredearth_timer;
    uint32 distractingash_timer;
    uint32 smolderingbreath_timer;
    uint32 tailsweep_timer;
    uint32 rainofbones_timer;
    uint32 smokingblast_timer;
    uint32 fireballbarrage_timer;
    uint32 searingcinders_timer;

    uint32 fly_count;
    uint32 fly_timer;

    bool intro;
    bool flying;
    uint32 wait_timer;
    uint32 MovePhase;

    void Reset()
    {
        phase =1;
        bellowingroar_timer = 30000;
        charredearth_timer = 15000;
        distractingash_timer = 20000;
        smolderingbreath_timer = 10000;
        tailsweep_timer = 12000;
        rainofbones_timer = 10000;
        smokingblast_timer = 20000;
        fireballbarrage_timer = 13000;
        searingcinders_timer = 14000;

        fly_count = 0;
       
        m_creature->SetSpeed(MOVE_RUN,2);
        m_creature->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT + MOVEMENTFLAG_LEVITATING);
        m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
		m_creature->setActive(true);
        wait_timer = 1000;
        MovePhase = 0;

		if(pInstance)
			pInstance->SetData(DATA_NIGHTBANE_EVENT, NOT_STARTED);

        flying = false;

        if(!intro)
        {
            m_creature->SetHomePosition(IntroWay[7][0],IntroWay[7][1],IntroWay[7][2],0);
            m_creature->GetMotionMaster()->MoveTargetedHome();
        }
    }
    
    void Aggro(Unit *who)
	{
		if(pInstance)
			pInstance->SetData(DATA_NIGHTBANE_EVENT, IN_PROGRESS);
	}
    void AttackStart(Unit* who)
    {
        if(!intro && !flying)
            ScriptedAI::AttackStart(who);
    }

	void JustDied(Unit* killer)
	{
		if(pInstance)
			pInstance->SetData(DATA_NIGHTBANE_EVENT, DONE);
	}
    void MoveInLineOfSight(Unit *who)
    {
        if(!intro && !flying)
        {
            if(!m_creature->getVictim() && m_creature->canStartAttack(who))
                ScriptedAI::AttackStart(who);
        }
    }
    
    void MovementInform(uint32 type, uint32 id)
    {
        if(type != POINT_MOTION_TYPE)
                return;

        if(intro)
        {
            if(id >= 8)
            {
                intro = false;
                m_creature->SetHomePosition(IntroWay[7][0],IntroWay[7][1],IntroWay[7][2],0);
                return;
            }
        
            wait_timer = 1;
        }

        if(flying)
        {
            if(id == 0)
            {
                flying = false;
                phase = 2;
                return;
            }
            if(id == 3)
            {
                MovePhase = 4;
                wait_timer = 1;
                return;
            }
            if(id == 8)
            {
                flying = false;
                phase = 1;
                return;
            }

            wait_timer = 1;
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if(wait_timer)
        if(wait_timer < diff)
        {
            if(intro)
            {
                if(MovePhase >= 7)
                {    
                    m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT + MOVEMENTFLAG_LEVITATING);
                    m_creature->HandleEmoteCommand(EMOTE_ONESHOT_LAND);
                    m_creature->GetMotionMaster()->MovePoint(8,IntroWay[7][0],IntroWay[7][1],IntroWay[7][2]);
                }
                else 
                {
                    m_creature->GetMotionMaster()->MovePoint(MovePhase,IntroWay[MovePhase][0],IntroWay[MovePhase][1],IntroWay[MovePhase][2]);
                    MovePhase++;
                }
            }

            
            if(flying)
            {
                if(MovePhase >= 7)
                {    
                    m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT + MOVEMENTFLAG_LEVITATING);
                    m_creature->HandleEmoteCommand(EMOTE_ONESHOT_LAND);
                    m_creature->GetMotionMaster()->MovePoint(8,IntroWay[7][0],IntroWay[7][1],IntroWay[7][2]);
                }
                else 
                {
                    m_creature->GetMotionMaster()->MovePoint(MovePhase,IntroWay[MovePhase][0],IntroWay[MovePhase][1],IntroWay[MovePhase][2]);
                    MovePhase++;
                }
            }
            
            wait_timer = 0;
        }else wait_timer -= diff;

        if(!m_creature->SelectHostilTarget()) 
            return;

        if(flying)
            return;

        //  Phase 1 "GROUND FIGHT"
        if(phase == 1)
        {
			m_creature->GetMotionMaster()->MoveChase(m_creature->getVictim());
			if (bellowingroar_timer < diff)
                {
                    DoCast(m_creature->getVictim(),SPELL_BELLOWING_ROAR);
                    bellowingroar_timer = 30000+rand()%10000 ; //Timer
                }else bellowingroar_timer -= diff;

            if (smolderingbreath_timer < diff)
                {
                    DoCast(m_creature->getVictim(),SPELL_SMOLDERING_BREATH);
                    smolderingbreath_timer = 20000;//timer

            }else smolderingbreath_timer -= diff;

            if (charredearth_timer < diff)
                {
                    Unit* target = NULL;
                    target = SelectUnit(SELECT_TARGET_RANDOM,0);
                    DoCast(target,SPELL_CHARRED_EARTH);
                    charredearth_timer = 20000; //timer
            }else charredearth_timer -= diff;

            if (tailsweep_timer < diff)
                {
                    Unit* target = NULL;
                    target = SelectUnit(SELECT_TARGET_RANDOM,0);
                    
                    if (!m_creature->HasInArc( M_PI, target)) 
                        DoCast(target,SPELL_TAIL_SWEEP);
                    tailsweep_timer = 15000;//timer
                }else tailsweep_timer -= diff;

            if (searingcinders_timer < diff)
            {
                    Unit* target = NULL;
                    target = SelectUnit(SELECT_TARGET_RANDOM,0);

                    DoCast(target,SPELL_SEARING_CINDERS);
                    searingcinders_timer = 10000; //timer 
            }else searingcinders_timer -= diff;

            uint32 prozent;
            prozent = (m_creature->GetHealth()*100) / m_creature->GetMaxHealth();

            if (prozent < 75 && fly_count == 0) // first take off 75%
            {
                m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
                m_creature->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
                m_creature->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT + MOVEMENTFLAG_LEVITATING);
                (*m_creature).GetMotionMaster()->Clear(false);
                (*m_creature).GetMotionMaster()->MovePoint(0,IntroWay[2][0],IntroWay[2][1],IntroWay[2][2]);
                flying = true;

                fly_timer = 45000+rand()%15000;
                fly_count++;

                rainofbones_timer = 5000;
                rainbones = false;
            }

            if (prozent < 50 && fly_count == 1) // secound take off 50%
            {
                m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
                m_creature->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
                m_creature->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT + MOVEMENTFLAG_LEVITATING);
                (*m_creature).GetMotionMaster()->Clear(false);
                (*m_creature).GetMotionMaster()->MovePoint(0,IntroWay[2][0],IntroWay[2][1],IntroWay[2][2]);
  
                flying = true;
                fly_timer = 45000+rand()%15000;
                fly_count++;

                rainofbones_timer = 5000;
                rainbones = false;
            }

            if (prozent < 25 && fly_count == 2) // third take off 25%
            {
                m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
                m_creature->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
                m_creature->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT + MOVEMENTFLAG_LEVITATING);
                (*m_creature).GetMotionMaster()->Clear(false);
                (*m_creature).GetMotionMaster()->MovePoint(0,IntroWay[2][0],IntroWay[2][1],IntroWay[2][2]);
                
                flying = true;
                //phase = 2;
                fly_timer = 45000+rand()%15000;
                fly_count++;

                rainofbones_timer = 5000;
                rainbones = false;
            }

            DoMeleeAttackIfReady();
        }
    
        //Phase 2 "FLYING FIGHT"
        if (phase == 2)
        {
            if (!rainbones)
            {
                if (rainofbones_timer < diff && !rainbones) // only once at the beginning of phase 2
                {
                    DoCast(m_creature->getVictim(),SPELL_RAIN_OF_BONES);
                    rainbones = true;
                    smokingblast_timer = 20000;
                }else rainofbones_timer -= diff;

                if (distractingash_timer < diff)
                {
                    Unit* target = NULL;
                    target = SelectUnit(SELECT_TARGET_RANDOM,0);

                    DoCast(target,SPELL_DISTRACTING_ASH);
                    distractingash_timer = 2000;//timer wrong
                }else distractingash_timer -= diff;
            }

            if (rainbones)
            {
                if (smokingblast_timer < diff)
                 {
                    DoCast(m_creature->getVictim(),SPELL_SMOKING_BLAST);
                    smokingblast_timer = 1500 ; //timer wrong
                 }else smokingblast_timer -= diff;
            }

            if (fireballbarrage_timer < diff)
            {
                    Unit* target = NULL;
                    target = SelectUnit(SELECT_TARGET_FARTHEST,0);

                    DoCast(target,SPELL_FIREBALL_BARRAGE);
                    fireballbarrage_timer = 20000; //Timer 
            }else fireballbarrage_timer -= diff;

            if (fly_timer < diff) //landing
            {
                //m_creature->HandleEmoteCommand(EMOTE_ONESHOT_LAND);
                //m_creature->SetHover(false);
                (*m_creature).GetMotionMaster()->Clear(false);
                m_creature->GetMotionMaster()->MovePoint(3,IntroWay[3][0],IntroWay[3][1],IntroWay[3][2]);
                flying = true;  
                //wait_timer = 1;
                //phase = 1;
            }else fly_timer -= diff;
        }
    }
};

CreatureAI* GetAI_boss_nightbane(Creature *_Creature)
{
    return new boss_nightbaneAI (_Creature);
}

void AddSC_boss_nightbane()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_nightbane";
    newscript->GetAI = GetAI_boss_nightbane;
    newscript->RegisterSelf();
}