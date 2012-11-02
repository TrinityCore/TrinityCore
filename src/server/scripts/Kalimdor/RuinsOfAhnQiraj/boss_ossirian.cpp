/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ruins_of_ahnqiraj.h"
#include "WeatherMgr.h"

enum
{
    SAY_SUPREME_1           = -1509018,
    SAY_SUPREME_2           = -1509019,
    SAY_SUPREME_3           = -1509020,
    SAY_RAND_INTRO_1        = -1509021,
    SAY_RAND_INTRO_2        = -1509023,
    SAY_RAND_INTRO_3        = -1509024,
    SAY_AGGRO               = -1509025,
    SAY_SLAY                = -1509026,
    SAY_DEATH               = -1509027,

    SPELL_SILENCE           = 25195,
    SPELL_CYCLONE           = 25189,
    SPELL_STOMP             = 25188,
    SPELL_SUPREME           = 25176,
    SPELL_SUMMON            = 20477,

    SPELL_SAND_STORM        = 25160,
    
    NPC_SAND_VORTEX         = 15428,
    GO_OSSIRIAN_CRYSTAL     = 180619
};

// You spin me right round, baby
// right round like a record, baby
// right round round round
const float CrystalCoordinates[NUM_CRYSTALS][3] =
{
    { -9394.230469, 1951.808594, 85.977333 },
    { -9357.931641, 1930.596802, 85.556198 },
    { -9383.113281, 2011.042725, 85.556389 },
    { -9243.36, 1979.04, 85.556 },
    { -9281.68, 1886.66, 85.5558 },
    { -9241.8, 1806.39, 85.5557 },
    { -9366.78, 1781.76, 85.5561 },
    { -9430.37, 1786.86, 85.557 },
    { -9406.73, 1863.13, 85.5558 }
};
float RoomRadius = 0; // TODO
const uint8 NUM_TORNADOS = 5; // TODO: This number is completly random!
const uint8 NUM_CRYSTALS = 9;
const uint32 SpellWeakness[5] = { 25177, 25178, 25180, 25181, 25183 };
const Position RoomCenter = { 0, 0, 0 }; // TODO

class boss_ossirian : public CreatureScript
{
    public:
        boss_ossirian() : CreatureScript("boss_ossirian") { }

        struct boss_ossirianAI : public ScriptedAI
        {
            boss_ossirianAI(Creature* creature) : ScriptedAI(creature)
            {
                vCrystals.reserve(NUM_CRYSTALS);
                vTornados.reserve(NUM_TORNADOS);
                pInstance = creature->GetInstanceScript();
                m_bSaidIntro = false;
                Reset();
            }
            
            InstanceScript* pInstance;
            
            uint8 m_uiCrystalIterator;
            uint32 m_uiSupremeTimer;
            uint32 m_uiStompTimer;
            uint32 m_uiCycloneTimer;
            uint32 m_uiSilenceTimer;
            bool m_bSaidIntro;
            
            std::vector<GameObject*> vCrystals;
            std::vector<Creature*> vTornados;
            
            void Reset()
            {
                m_uiCrystalIterator = 0;
                m_uiSupremeTimer = 45000;
                m_uiStompTimer   = 30000;
                m_uiCycloneTimer = 20000;
                m_uiSilenceTimer = 30000;
                
                if (pInstance)
                    pInstance->SetData(BOSS_OSSIRIAN, NOT_STARTED);
            }
            
            void EnterCombat(Unit* who)
            {
                DoCast(me, SPELL_SUPREME);
                Talk(SAY_AGGRO);
                
                if (pInstance)
                {
                    WeatherMgr::FindWeather(me->GetMap()->GetId())->SetWeather(WEATHER_TYPE_STORM, 1.0f);
                    pInstance->SetData(BOSS_OSSIRIAN, IN_PROGRESS);
                    
                    for(int i = 0; i < NUM_CRYSTALS; ++i)
                    {
                        GameObject* pCrystal = me->SummonGameObject(GO_OSSIRIAN_CRYSTAL, 
                                                                    CrystalCoordinates[i][0],
                                                                    CrystalCoordinates[i][1],
                                                                    CrystalCoordinates[i][2],
                                                                    0, 0, 0, 0, 0, -1);
                        vCrystals.push_back(pCrystal);
                    }
                    pInstance->DoRespawnGameObject(vCrystals[m_uiCrystalIterator++]->GetGUID(), -1);
                    
                    for (int i = 0; i < NUM_TORNADOS; ++i) // TODO: This number is completly random!
                    {
                        Position Point;
                        me->GetRandomPoint(RoomCenter, RoomRadius, Point);
                        Creature* pTornado = me->SummonCreature(NPC_SAND_VORTEX, Point, TEMPSUMMON_MANUAL_DESPAWN, -1);
                        vTornados.push_back(pTornado);
                    }
                }
            }
            
            void CleanupTornados()
            {
                for (int i = 0; i < NUM_TORNADOS; ++i)
                {
                    ((TempSummon*)vTornados[i])->UnSummon();
                }
            }
            
            void KilledUnit(Unit* victim)
            {
                Talk(SAY_SLAY);
            }
            
            void EnterEvadeMode()
            {
                if (pInstance)
                {
                    pInstance->SetData(BOSS_OSSIRIAN, NOT_STARTED);
                    vCrystals[m_uiCrystalIterator]->UseDoorOrButton();
                    CleanupTornados();
                }
            }
            
            void JustDied(Unit* killer)
            {
                Talk(SAY_DEATH);
                
                if (pInstance)
                {
                    pInstance->SetData(BOSS_OSSIRIAN, DONE);
                    vCrystals[m_uiCrystalIterator]->Use(killer);
                    CleanupTornados();
                }
            }
            
            void OnCrystalUse()
            {
                if (m_uiCrystalIterator == NUM_CRYSTALS)
                    m_uiCrystalIterator = 0;
                pInstance->DoRespawnGameObject(vCrystals[m_uiCrystalIterator]->GetGUID(), -1);
                vCrystals[m_uiCrystalIterator]->CastSpell(me, SpellWeakness[urand(0, 4)]);
                ++m_uiCrystalIterator;
                me->RemoveAurasDueToSpell(SPELL_SUPREME);
                m_uiSupremeTimer = 45000;
            }
            
            void MoveInLineOfSight(Unit* who)
            {
                if (!m_bSaidIntro)
                {
                    switch (urand(0, 2))
                    {
                        case 0: Talk(SAY_RAND_INTRO_1); break;
                        case 1: Talk(SAY_RAND_INTRO_2); break;
                        case 2: Talk(SAY_RAND_INTRO_3); break;
                    }
                    m_bSaidIntro = true;
                }
            }
            
            void UpdateAI(const uint32 uiDiff)
            {
                if (!UpdateVictim())
                    return;
                
                // No kiting!
                if (me->GetDistance(me->getVictim()) > 60.00f && me->GetDistance(me->getVictim()) < 120.00f)
                    DoCast(me->getVictim(), SPELL_SUMMON);
                
                // Supreme mode
                if (m_uiSupremeTimer <= uiDiff)
                {
                    if (!me->HasAura(SPELL_SUPREME))
                        DoCast(me, SPELL_SUPREME);
                        
                    switch (urand(0, 2))
                    {
                        case 0: Talk(SAY_SUPREME_1); break;
                        case 1: Talk(SAY_SUPREME_2); break;
                        case 2: Talk(SAY_SUPREME_3); break;
                    }
                    m_uiSupremeTimer = 45000;
                }
                else
                    m_uiSupremeTimer -= uiDiff;
                
                // Stomp
                if (m_uiStompTimer < uiDiff)
                {
                    DoCast(me, SPELL_STOMP);
                    m_uiStompTimer = 30000;
                }
                else
                    m_uiStompTimer -= uiDiff;
                
                // Cyclone
                if (m_uiCycloneTimer < uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_CYCLONE);
                    m_uiCycloneTimer = 20000;
                }
                else
                    m_uiCycloneTimer -= uiDiff;
                    
                // Silence
                if (m_uiSilenceTimer < uiDiff)
                {
                    DoCast(me, SPELL_SILENCE);
                    m_uiSilenceTimer = urand(20000, 30000);
                }
                else 
                    m_uiSilenceTimer -= uiDiff;
                    
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_ossirianAI (creature);
        }
};

class npc_sand_vortex : public CreatureScript
{
    public:
        npc_sand_vortex() : CreatureScript("npc_sand_vortex")
        {
        }

        struct npc_sand_vortexAI : public ScriptedAI
        {            
            npc_sand_vortexAI(Creature* creature) : ScriptedAI(creature)
            {
                DoCast(me, SPELL_SAND_STORM);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_sand_vortexAI (creature);
        }
};

typedef boss_ossirian::boss_ossirianAI OssirianAI;

class go_ossirian_crystal : public GameObjectScript
{
    public:
        go_ossirian_crystal() : GameObjectScript("go_ossirian_crystal")
        {
        }

        void OnStateChanged(uint32 state, Unit* unit)
        {
            InstanceScript* pInstance = unit->GetInstanceScript();
            
            if (!pInstance)
                return;

            if (pInstance->GetData(BOSS_OSSIRIAN) != IN_PROGRESS)
                return;

            Creature* pOssirian = unit->GetMap()->GetCreature(pInstance->GetData64(BOSS_OSSIRIAN));
            OssirianAI* pOssirianAI = (OssirianAI*)pOssirian->AI();
            pOssirianAI->OnCrystalUse();
        }
};

void AddSC_boss_ossirian()
{
    new boss_ossirian();
    new go_ossirian_crystal();
    new npc_sand_vortex();
}
