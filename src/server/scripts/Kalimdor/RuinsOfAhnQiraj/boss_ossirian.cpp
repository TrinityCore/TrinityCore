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

enum
{
    SAY_SUPREME             = 0,
    SAY_INTRO               = 1,
    SAY_AGGRO               = 2,
    SAY_SLAY                = 3,
    SAY_DEATH               = 4,
    SAY_KURINAXX_DEATH      = 5, // NYI: Instance yell when Kurinaxx dies

    SPELL_SILENCE           = 25195,
    SPELL_CYCLONE           = 25189,
    SPELL_STOMP             = 25188,
    SPELL_SUPREME           = 25176,
    SPELL_SUMMON            = 20477,

    SPELL_SAND_STORM        = 25160,
    SPELL_SUMMON_CRYSTAL    = 25192
};

const uint8 NUM_CRYSTALS = 9;

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

float RoomRadius = 165.0f;
const uint8 NUM_TORNADOS = 5; // TODO: This number is completly random!
const uint32 SpellWeakness[5] = { 25177, 25178, 25180, 25181, 25183 };
const Position RoomCenter = { -9343.041992f, 1923.278198f, 85.555984f };

class boss_ossirian : public CreatureScript
{
    public:
        boss_ossirian() : CreatureScript("boss_ossirian") { }

        struct boss_ossirianAI : public ScriptedAI
        {
            boss_ossirianAI(Creature* creature) : ScriptedAI(creature)
            {
                vTornados.reserve(NUM_TORNADOS);
                pInstance = creature->GetInstanceScript();
                m_bSaidIntro = false;
                Reset();
            }
            
            InstanceScript* pInstance;
            Creature* pTrigger;
            GameObject* pCrystal;
            uint8 m_uiCrystalIterator;
            uint32 m_uiSupremeTimer;
            uint32 m_uiStompTimer;
            uint32 m_uiCycloneTimer;
            uint32 m_uiSilenceTimer;
            bool m_bSaidIntro;
            
            std::vector<Creature*> vTornados;
            
            void Reset()
            {
				pCrystal = 0;
				pTrigger = 0;
                m_uiCrystalIterator = 0;
                m_uiSupremeTimer = 45000;
                m_uiStompTimer   = 30000;
                m_uiCycloneTimer = 20000;
                m_uiSilenceTimer = 30000;
                
                if (pInstance)
                    pInstance->SetData(BOSS_OSSIRIAN, NOT_STARTED);
            }
            
            void DoAction(const int32 action)
            {
                if(action == 0xBEEF)
                    OnCrystalUse();
            }
            
            void EnterCombat(Unit* who)
            {
                DoCast(me, SPELL_SUPREME);
                Talk(SAY_AGGRO);
                
                if (pInstance)
                {
                    Map* pMap = me->GetMap();
                    if (!pMap->IsDungeon())
                        return;

                    WorldPacket data(SMSG_WEATHER, (4+4+4));
                    data << uint32(WEATHER_STATE_HEAVY_SANDSTORM) << float(1) << uint8(0); // ??
                    pMap->SendToPlayers(&data);
                    
                    pInstance->SetData(BOSS_OSSIRIAN, IN_PROGRESS);
                    
                    for (int i = 0; i < NUM_TORNADOS; ++i)
                    {
                        Position Point;
                        me->GetRandomPoint(RoomCenter, RoomRadius, Point);
                        Creature* pTornado = me->SummonCreature(NPC_SAND_VORTEX, Point, TEMPSUMMON_MANUAL_DESPAWN, -1);
                        pTornado->GetAI()->DoCast(pTornado, SPELL_SAND_STORM);
                        vTornados.push_back(pTornado);
                    }
                    
                    SpawnNextCrystal();
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
                ScriptedAI::EnterEvadeMode();
                
                if (pInstance)
                {
                    pInstance->SetData(BOSS_OSSIRIAN, NOT_STARTED);
                    if(pCrystal)
                        pCrystal->Use(pTrigger);
                    CleanupTornados();
                }
            }
            
            void JustDied(Unit* killer)
            {
                Talk(SAY_DEATH);
                
                if (pInstance)
                {
                    pInstance->SetData(BOSS_OSSIRIAN, DONE);
                    if(pCrystal)
                        pCrystal->Use(pTrigger);
                    CleanupTornados();
                }
            }
            
            void SpawnNextCrystal()
            {
                pTrigger = me->SummonCreature(NPC_OSSIRIAN_TRIGGER, 
                                              CrystalCoordinates[m_uiCrystalIterator][0],
                                              CrystalCoordinates[m_uiCrystalIterator][1],
                                              CrystalCoordinates[m_uiCrystalIterator][2]);
                
                pCrystal = pTrigger->SummonGameObject(GO_OSSIRIAN_CRYSTAL,
                                                      CrystalCoordinates[m_uiCrystalIterator][0],
                                                      CrystalCoordinates[m_uiCrystalIterator][1],
                                                      CrystalCoordinates[m_uiCrystalIterator][2],
                                                      0, 0, 0, 0, 0, -1);

                ++m_uiCrystalIterator;
            }
            
            void OnCrystalUse()
            {
                if (m_uiCrystalIterator == NUM_CRYSTALS)
                    m_uiCrystalIterator = 0;
                    
                pTrigger->CastSpell(me, SpellWeakness[urand(0, 4)]);
                ((TempSummon*)pTrigger)->UnSummon();
                SpawnNextCrystal();
                me->RemoveAurasDueToSpell(SPELL_SUPREME);
                m_uiSupremeTimer = 45000;
            }
            
            void MoveInLineOfSight(Unit* who)
            {
                if (!m_bSaidIntro)
                {
                    Talk(SAY_INTRO);
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
                        
                    Talk(SAY_SUPREME);
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

class GO_ossirian_crystal : public GameObjectScript
{
    public:
        GO_ossirian_crystal() : GameObjectScript("go_ossirian_crystal")
        {
        }

        bool OnGossipHello(Player* player, GameObject* go)
        {
            InstanceScript* pInstance = player->GetInstanceScript();

            if(!pInstance)
                return false;
                
            Creature* pOssirian = player->FindNearestCreature(NPC_OSSIRIAN, 30.0f);
            
            if(!pOssirian || pInstance->GetData(BOSS_OSSIRIAN) != IN_PROGRESS)
                return false;
            
            pOssirian->AI()->DoAction(0xBEEF);
            
            return true;
        }
};

void AddSC_boss_ossirian()
{
    new boss_ossirian();
    new GO_ossirian_crystal();
}
