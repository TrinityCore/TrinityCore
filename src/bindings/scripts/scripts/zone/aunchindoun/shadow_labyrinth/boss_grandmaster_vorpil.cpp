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
SDName: Boss_Grandmaster_Vorpil
SD%Complete: 100
SDComment: 
SDCategory: Auchindoun, Shadow Labyrinth
EndScriptData */

#include "precompiled.h"
#include "def_shadow_labyrinth.h"

#define SAY_INTRO                       -1555028
#define SAY_AGGRO1                      -1555029
#define SAY_AGGRO2                      -1555030
#define SAY_AGGRO3                      -1555031
#define SAY_HELP                        -1555032
#define SAY_SLAY1                       -1555033
#define SAY_SLAY2                       -1555034
#define SAY_DEATH                       -1555035

#define SPELL_RAIN_OF_FIRE          33617
#define H_SPELL_RAIN_OF_FIRE        39363

#define SPELL_DRAWN_SHADOWS         33563
#define SPELL_SHADOWBOLT_VOLLEY     33841

#define MOB_VOID_TRAVELER           19226
#define SPELL_SACRIFICE             33587
#define SPELL_SHADOW_NOVA           33846
#define SPELL_HEALVORPIL            33783
#define H_SPELL_HEALVORPIL          39364

#define MOB_VOID_PORTAL             19224
#define SPELL_VOID_PORTAL_VISUAL    33569

float VorpilPosition[1][3] =
{
    {-252.8820,-264.3030,17.1}
};

float VoidPortalCoords[5][3] = 
{
    {-283.5894, -239.5718, 12.7},
    {-306.5853, -258.4539, 12.7},
    {-295.8789, -269.0899, 12.7},
    {-209.3401, -262.7564, 17.1},
    {-261.4533, -297.3298, 17.1}
};

struct TRINITY_DLL_DECL boss_grandmaster_vorpilAI : public ScriptedAI
{
    boss_grandmaster_vorpilAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Intro = false;
        Reset();
    }

    ScriptedInstance *pInstance;
    bool Intro;
    bool sumportals;
    bool HeroicMode;
   
    uint32 ShadowBoltVolley_Timer;
    uint32 DrawnShadows_Timer;
    uint32 sumportals_Timer;
    uint32 summonTraveler_Timer;
    uint64 PortalsGuid[5]; 

    void summonPortals()
    {
        for (int i = 0;i<5;i++)
        {
            Creature *Portal = NULL;
            Portal = m_creature->SummonCreature(MOB_VOID_PORTAL,VoidPortalCoords[i][0],VoidPortalCoords[i][1],VoidPortalCoords[i][2],0,TEMPSUMMON_CORPSE_DESPAWN,3000000);
            PortalsGuid[i] = Portal->GetGUID();
            Portal->CastSpell(Portal,SPELL_VOID_PORTAL_VISUAL,false);
        }
        sumportals = true;
        summonTraveler_Timer = 5000;
    }

    void destroyPortals()
    {
        for (int i = 0;i < 5; i ++)
        {
            Unit *Portal = Unit::GetUnit((*m_creature), PortalsGuid[i]);
            if (Portal)
                if (Portal->isAlive())
                    Portal->DealDamage(Portal, Portal->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            PortalsGuid[i] = 0;
        }     
    }

    void spawnVoidTraveler()
    {
        srand( (unsigned) time(NULL) ) ; 
        int pos = rand()%5;
        Creature *traveler;
        traveler = m_creature->SummonCreature(MOB_VOID_TRAVELER,VoidPortalCoords[pos][0],VoidPortalCoords[pos][1],VoidPortalCoords[pos][2],0,TEMPSUMMON_CORPSE_TIMED_DESPAWN,10000);
    }

    void Reset()
    {
        HeroicMode = m_creature->GetMap()->IsHeroic();
        if( HeroicMode )
            debug_log("SD2: creature %u is in heroic mode",m_creature->GetEntry());

        ShadowBoltVolley_Timer = 15000;
        DrawnShadows_Timer = 45000;
        sumportals_Timer = 10000;
        summonTraveler_Timer = 90000;

        InCombat = false;
        sumportals = false;
        destroyPortals();

        if(pInstance)
            pInstance->SetData(DATA_GRANDMASTERVORPILEVENT, NOT_STARTED);
    }

    void KilledUnit(Unit *victim)
    {
        switch(rand()%2)
        {
            case 0: DoScriptText(SAY_SLAY1, m_creature); break;
            case 1: DoScriptText(SAY_SLAY2, m_creature); break;
        }
    }

    void JustDied(Unit *victim)
    {
        DoScriptText(SAY_DEATH, m_creature);
        destroyPortals();
        if(pInstance)
            pInstance->SetData(DATA_GRANDMASTERVORPILEVENT, DONE);
    }

    void StartEvent()
    {
        switch(rand()%3)
        {
            case 0: DoScriptText(SAY_AGGRO1, m_creature); break;
            case 1: DoScriptText(SAY_AGGRO2, m_creature); break;
            case 2: DoScriptText(SAY_AGGRO3, m_creature); break;
        }

        if(pInstance)
            pInstance->SetData(DATA_GRANDMASTERVORPILEVENT, IN_PROGRESS);
    }

    void Aggro(Unit *who)
    {
        if(!InCombat)
        {   
            InCombat = true;
            StartEvent();
        }
    }

    void MoveInLineOfSight(Unit *who)
    {
        if (!who || m_creature->getVictim())
            return;

        if (who->isTargetableForAttack() && who->isInAccessiblePlaceFor(m_creature) && m_creature->IsHostileTo(who))
        {
            float attackRadius = m_creature->GetAttackDistance(who);
            if (m_creature->IsWithinDistInMap(who, attackRadius) && m_creature->GetDistanceZ(who) <= CREATURE_Z_ATTACK_RANGE && m_creature->IsWithinLOSInMap(who))
            {
                if(who->HasStealthAura())
                    who->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);

                AttackStart(who);
            }
        }
        else if (!Intro && m_creature->IsWithinLOSInMap(who)&& m_creature->IsWithinDistInMap(who, 100) ) //not sure about right radius
        {
            DoScriptText(SAY_INTRO, m_creature);
            Intro = true;
        }

    }
   
    void UpdateAI(const uint32 diff)
    {

        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;
        
        if (!sumportals)
        if (sumportals_Timer < diff)
        {
            DoScriptText(SAY_HELP, m_creature);
            summonPortals();
            sumportals_Timer = 1000000;
                    
        }else sumportals_Timer -= diff;

        if (ShadowBoltVolley_Timer < diff)
        {
            DoCast(m_creature,SPELL_SHADOWBOLT_VOLLEY);
            ShadowBoltVolley_Timer = 15000;
        }else ShadowBoltVolley_Timer -= diff;

        if ( DrawnShadows_Timer < diff)
        {
            DoTeleportAll(VorpilPosition[0][0],VorpilPosition[0][1],VorpilPosition[0][2],0);
            m_creature->Relocate(VorpilPosition[0][0],VorpilPosition[0][1],VorpilPosition[0][2],0);
            DoCast(m_creature,SPELL_DRAWN_SHADOWS,true);

            if(!HeroicMode) DoCast(m_creature,SPELL_RAIN_OF_FIRE);
            else DoCast(m_creature,H_SPELL_RAIN_OF_FIRE);

            ShadowBoltVolley_Timer = 6000;
            DrawnShadows_Timer = 45000;    
        }else DrawnShadows_Timer -= diff;

        if ( summonTraveler_Timer < diff)
        {
            spawnVoidTraveler();
            summonTraveler_Timer = 10000;
        }else summonTraveler_Timer -=diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_grandmaster_vorpil(Creature *_Creature)
{
    return new boss_grandmaster_vorpilAI (_Creature);
}

struct TRINITY_DLL_DECL mob_voidtravelerAI : public ScriptedAI
{
    mob_voidtravelerAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Reset();
    }

    ScriptedInstance *pInstance;
    uint32 VorpilCheck_Timer;
    uint32 eventCheck_Timer;
    bool sacrifice;
    bool sacrificed;
    bool oneTarget;
    bool HeroicMode;

    uint32 target_timer;

    void Reset()
    {
        HeroicMode = m_creature->GetMap()->IsHeroic();
        if( HeroicMode )
            debug_log("SD2: creature %u is in heroic mode",m_creature->GetEntry());

        VorpilCheck_Timer = 5000;
        eventCheck_Timer = 1000;
        target_timer = 2000;
        oneTarget = false;
        sacrificed = false;
        sacrifice = false;       
    }
    void EnterEvadeMode(){}
    void Aggro(Unit *who) {}
    void AttackStart(Unit *who){}
    void MoveInLineOfSight(Unit *who){}

    void UpdateAI(const uint32 diff)
    {
        if (eventCheck_Timer < diff)
        {
            if(pInstance)
            {
                Unit *Vorpil = Unit::GetUnit((*m_creature),pInstance->GetData64(DATA_GRANDMASTERVORPIL));
                if (Vorpil)
                {
                    if (Vorpil->isDead())
                    {
                         m_creature->DealDamage(m_creature, m_creature->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                    }

                    if (Vorpil->getVictim())
                    {    
                        if((*m_creature).GetMotionMaster()->GetCurrentMovementGeneratorType() != TARGETED_MOTION_TYPE)
                            (*m_creature).GetMotionMaster()->MoveFollow(Vorpil,1,0);
                    }
                }  
                if(pInstance->GetData(DATA_GRANDMASTERVORPILEVENT) != IN_PROGRESS)
                {
                    m_creature->DealDamage(m_creature, m_creature->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                }
            }
            eventCheck_Timer = 5000;
        }else eventCheck_Timer -=diff;

        if (VorpilCheck_Timer < diff)
        {
            if (pInstance)
            {
                if (!sacrificed)
                {
                    if (!sacrifice)
                    {
                        Unit *Vorpil = Unit::GetUnit((*m_creature), pInstance->GetData64(DATA_GRANDMASTERVORPIL));
                        if (Vorpil)
                            if (Vorpil->isAlive())
                            {
                                if (m_creature->IsWithinDistInMap(Vorpil, 2))
                                {
                                    sacrifice = true;
                                    DoCast(m_creature,SPELL_SACRIFICE);
                                    VorpilCheck_Timer = 2000;
                                }
                            }

                        if (!sacrifice)
                            VorpilCheck_Timer = 3000;
                    }
                    else
                    { 
                        Unit *Vorpil = Unit::GetUnit((*m_creature),pInstance->GetData64(DATA_GRANDMASTERVORPIL));
                        if (Vorpil)
                            if (Vorpil->isAlive())
                            {
                                if(!HeroicMode) Vorpil->CastSpell(Vorpil,SPELL_HEALVORPIL,true);
                                else Vorpil->CastSpell(Vorpil,H_SPELL_HEALVORPIL,true);
                            };
                        DoCast(m_creature,SPELL_SHADOW_NOVA); 
                        sacrificed = true;
                        m_creature->DealDamage(m_creature, m_creature->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                        VorpilCheck_Timer = 100000;
                    }
                }
            }
         }else VorpilCheck_Timer -= diff;
    }
};

CreatureAI* GetAI_mob_voidtraveler(Creature *_Creature)
{
    return new mob_voidtravelerAI (_Creature);
}

void AddSC_boss_grandmaster_vorpil()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_grandmaster_vorpil";
    newscript->GetAI = GetAI_boss_grandmaster_vorpil;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="mob_voidtraveler";
    newscript->GetAI = GetAI_mob_voidtraveler;
    m_scripts[nrscripts++] = newscript;
}
