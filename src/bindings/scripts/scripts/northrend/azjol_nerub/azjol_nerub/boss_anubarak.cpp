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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: boss_anubarak
SD%Complete: 90 %
SDComment: Says are not implemented.
SDCategory: Azjol Nerub
EndScriptData */


#include "precompiled.h"
#include "azjol_nerub.h"

enum Spells
{

    SPELL_CARRION_BEETLES                  =       53520,
    SPELL_SUMMON_CARRION_BEETLES           =       53521,
    SPELL_LEECHING_SWARM                   =       53467,

    SPELL_IMPALE                           =       53454,
    H_SPELL_IMPALE                         =       59446,

    SPELL_POUND                            =       53472,
    H_SPELL_POUND                          =       59433,

    SPELL_SUBMERGE                         =       53421,

    CREATURE_GUARDIAN                      =       29216,
    CREATURE_VENOMANCER                     =       29217,
    CREATURE_DATTER                        =       29213

};

// not in db
enum Yells
{
    SAY_INTRO                                  = -1601010,
    SAY_AGGRO                                  = -1601000,
    SAY_SLAY_1                                 = -1601001,
    SAY_SLAY_2                                 = -1601002,
    SAY_SLAY_3                                 = -1601003,
    SAY_LOCUST_1                               = -1601005,
    SAY_LOCUST_2                               = -1601006,
    SAY_LOCUST_3                               = -1601007,
    SAY_SUBMERGE_1                             = -1601008,
    SAY_SUBMERGE_2                             = -1601009,
    SAY_DEATH                                  = -1601004
};
#define SPAWNPOINT_Z                               224.3

float SpawnPoint[2][2] =
{
    {550.7, 282.8},
    {551.1, 229.4},
};

struct TRINITY_DLL_DECL boss_anub_arakAI : public ScriptedAI
{
    boss_anub_arakAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    bool Channeling;
    bool HeroicMode;
    bool Summoned_Guardian;
    bool Summoned_Venomancer;
    bool Summoned_Datter;
    uint32 Phase;
    uint32 Phase_Time;

    uint32 SPELL_CARRION_BEETLES_Timer;
    uint32 SPELL_LEECHING_SWARM_Timer;
    uint32 SPELL_IMPALE_Timer;
    uint32 SPELL_POUND_Timer;
    uint32 SPELL_SUBMERGE_Timer;
    uint32 UNDERGROUND_Timer;
    uint32 VENOMANCER_Timer;
    uint32 DATTER_Timer;

    void Reset()
    {

        SPELL_CARRION_BEETLES_Timer = 8000;
        SPELL_LEECHING_SWARM_Timer = 20000;
        SPELL_IMPALE_Timer = 9000;
        SPELL_POUND_Timer = 15000;

        Phase = 0;
        Phase_Time = 0;
        Channeling = false;

        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->RemoveAura(SPELL_SUBMERGE);
        
        if (pInstance)
            pInstance->SetData(DATA_ANUBARAK_EVENT, NOT_STARTED);
    }


    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
        
        if (pInstance)
            pInstance->SetData(DATA_ANUBARAK_EVENT, IN_PROGRESS);
    }


    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (Channeling == true)
        {
            for(int ind = 0 ; ind < 4; ind++) DoCast(m_creature->getVictim(), SPELL_SUMMON_CARRION_BEETLES, true);
            Channeling = false;

        }

        if (Phase == 1)
        {

            if (SPELL_IMPALE_Timer <= diff)
            {

                if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                    m_creature->CastSpell(pTarget, HEROIC(SPELL_IMPALE,H_SPELL_IMPALE), true);

                SPELL_IMPALE_Timer = 9000;
            } else SPELL_IMPALE_Timer -= diff;

            if(!Summoned_Guardian)
            {
                Creature* Guardian;
                for(uint8 i=0; i < 2; ++i)
                {
                    Guardian = m_creature->SummonCreature(CREATURE_GUARDIAN,SpawnPoint[i][0],SpawnPoint[i][1],SPAWNPOINT_Z,0,TEMPSUMMON_CORPSE_DESPAWN,0);
                    if(Guardian)
                    {
                        Guardian->AddThreat(m_creature->getVictim(), 0.0f);
                        DoZoneInCombat(Guardian);
                    }
                }
                Summoned_Guardian = true;
            }

            if(!Summoned_Venomancer)
            {
                if (VENOMANCER_Timer <= diff)
                {
                    if(Phase_Time > 1)
                    {

                        Creature* Venomancer;
                        for(uint8 i=0; i < 2; ++i)
                        {
                            Venomancer = m_creature->SummonCreature(CREATURE_VENOMANCER,SpawnPoint[i][0],SpawnPoint[i][1],SPAWNPOINT_Z,0,TEMPSUMMON_CORPSE_DESPAWN,0);
                            if(Venomancer)
                            {
                                Venomancer->AddThreat(m_creature->getVictim(), 0.0f);
                                DoZoneInCombat(Venomancer);
                            }
                        }
                        Summoned_Venomancer = true;
                    }

                } else VENOMANCER_Timer -= diff;
            }

            if(!Summoned_Datter)
            {
                if (DATTER_Timer <= diff)
                {
                    if(Phase_Time > 2)
                    {
                        Creature* Datter;
                        for(uint8 i=0; i < 2; ++i)
                        {
                            Datter = m_creature->SummonCreature(CREATURE_DATTER,SpawnPoint[i][0],SpawnPoint[i][1],SPAWNPOINT_Z,0,TEMPSUMMON_CORPSE_DESPAWN,0);
                            if(Datter)
                            {
                                Datter->AddThreat(m_creature->getVictim(), 0.0f);
                                DoZoneInCombat(Datter);
                            }
                        }
                        Summoned_Datter = true;
                    }
                } else DATTER_Timer -= diff;
            }

            if (UNDERGROUND_Timer <= diff)
            {
                m_creature->RemoveAura(SPELL_SUBMERGE);

                m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                Phase = 0;
            } else UNDERGROUND_Timer -= diff;

        }

        if (Phase == 0)
        {
            if (SPELL_LEECHING_SWARM_Timer <= diff)
            {
                DoCast(m_creature, SPELL_LEECHING_SWARM, true);

                SPELL_LEECHING_SWARM_Timer = 19000;
            } else SPELL_LEECHING_SWARM_Timer -= diff;

            if (SPELL_CARRION_BEETLES_Timer <= diff)
            {
                Channeling = true;
                DoCast(m_creature->getVictim(), SPELL_CARRION_BEETLES, false);

                SPELL_CARRION_BEETLES_Timer = 25000;
            } else SPELL_CARRION_BEETLES_Timer -= diff;

            if (SPELL_POUND_Timer <= diff)
            {
                 DoCast(m_creature->getVictim(), HEROIC(SPELL_POUND, H_SPELL_POUND));
                 SPELL_POUND_Timer = 16500;
            } else SPELL_POUND_Timer -= diff;

        }

        if ((Phase_Time == 0 && (m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) <= 75)
            || (Phase_Time == 1 && (m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) <= 50)
            || (Phase_Time == 2 && (m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) <= 25))
        {
            ++Phase_Time;

            Summoned_Guardian = false;
            Summoned_Venomancer = false;
            Summoned_Datter = false;

            UNDERGROUND_Timer = 40000;
            VENOMANCER_Timer = 25000;
            DATTER_Timer = 32000;

            DoCast(m_creature, SPELL_SUBMERGE, false);

            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

            Phase = 1;

        }

        if (!Phase == 1)
        {
            DoMeleeAttackIfReady();
        }
    }
    
    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH, m_creature);
        
        if (pInstance)
            pInstance->SetData(DATA_ANUBARAK_EVENT, DONE);
    }

    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;
        
        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3), m_creature);
    }
};

CreatureAI* GetAI_boss_anub_arak(Creature* pCreature)
{
    return new boss_anub_arakAI (pCreature);
}

void AddSC_boss_anub_arak()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_anub_arak";
    newscript->GetAI = &GetAI_boss_anub_arak;
    newscript->RegisterSelf();
}
