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
Position CrystalCoordinates[NUM_CRYSTALS] =
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
                Tornados.reserve(NUM_TORNADOS);
                Instance = creature->GetInstanceScript();
                SaidIntro = false;
                Reset();
            }
            
            std::vector<TempSummon*> Tornados;
            InstanceScript* Instance;
            TempSummon* Trigger;
            GameObject* Crystal;
            uint8 CrystalIterator;
            uint32 SupremeTimer;
            uint32 StompTimer;
            uint32 CycloneTimer;
            uint32 SilenceTimer;
            bool SaidIntro;
            
            void Reset()
            {
                Crystal = 0;
                Trigger = 0;
                CrystalIterator = 0;
                SupremeTimer = 45000;
                StompTimer   = 30000;
                CycloneTimer = 20000;
                SilenceTimer = 30000;
                Tornados.clear();
                
                if (Instance)
                    Instance->SetData(BOSS_OSSIRIAN, NOT_STARTED);
            }

            void SpellHit(Unit* caster, SpellInfo const* spell)
            {
                for (int i = 0; SpellWeakness[i]; ++i)
                {
                    if (spell->Id == SpellWeakness[i])
                    {
                        me->RemoveAurasDueToSpell(SPELL_SUPREME);
                        ((TempSummon*)caster)->UnSummon();
                        Trigger = 0;
                        Crystal = 0;
                        SpawnNextCrystal();
                    }
                }
            }
            
            void DoAction(const int32 action)
            {
                if (action == 0xBEEF)
                {
                    if (CrystalIterator == NUM_CRYSTALS)
                        CrystalIterator = 0;
                    
                    if (Trigger)
                    {
                        Trigger->CastSpell(Trigger, SpellWeakness[urand(0, 4)], false);
                        Trigger = 0;
                        SupremeTimer = 45000;
                    }
                }
            }
            
            void EnterCombat(Unit* who)
            {
                DoCast(me, SPELL_SUPREME);
                Talk(SAY_AGGRO);
                
                if (Instance)
                {
                    Map* map = me->GetMap();
                    if (!map->IsDungeon())
                        return;

                    WorldPacket data(SMSG_WEATHER, (4+4+4));
                    data << uint32(WEATHER_STATE_HEAVY_SANDSTORM) << float(1) << uint8(0); // ??
                    map->SendToPlayers(&data);
                    
                    Instance->SetData(BOSS_OSSIRIAN, IN_PROGRESS);
                    
                    for (int i = 0; i < NUM_TORNADOS; ++i)
                    {
                        Position Point;
                        me->GetRandomPoint(RoomCenter, RoomRadius, Point);
                        TempSummon* Tornado = me->SummonCreature(NPC_SAND_VORTEX, Point, TEMPSUMMON_MANUAL_DESPAWN, -1);
                        Tornado->GetAI()->DoCast(Tornado, SPELL_SAND_STORM);
                        Tornados.push_back(Tornado);
                    }
                    
                    SpawnNextCrystal();
                }
            }
            
            void KilledUnit(Unit* victim)
            {
                Talk(SAY_SLAY);
            }
            
            void EnterEvadeMode()
            {                
                if (Instance)
                {
                    Instance->SetData(BOSS_OSSIRIAN, NOT_STARTED);
                    Cleanup();
                }
                ScriptedAI::EnterEvadeMode();
            }
            
            void JustDied(Unit* killer)
            {
                Talk(SAY_DEATH);
                
                if (Instance)
                {
                    Instance->SetData(BOSS_OSSIRIAN, DONE);
                    Cleanup();
                }
            }
            
            void Cleanup()
            {
                if (Crystal)
                    Crystal->Use(me);
                if (Trigger)
                    Trigger->UnSummon();
                for (int i = 0; i < NUM_TORNADOS; ++i)
                {
                    Tornados[i]->UnSummon();
                }
            }
            
            void SpawnNextCrystal()
            {
                Trigger = me->GetMap()->SummonCreature(NPC_OSSIRIAN_TRIGGER, CrystalCoordinates[CrystalIterator]);
                Crystal = Trigger->SummonGameObject(GO_OSSIRIAN_CRYSTAL,
                                                    CrystalCoordinates[CrystalIterator].GetPositionX(),
                                                    CrystalCoordinates[CrystalIterator].GetPositionY(),
                                                    CrystalCoordinates[CrystalIterator].GetPositionZ(),
                                                    0, 0, 0, 0, 0, -1);
                ++CrystalIterator;
            }
            
            void MoveInLineOfSight(Unit* who)
            {
                if (!SaidIntro)
                {
                    Talk(SAY_INTRO);
                    SaidIntro = true;
                }
            }
            
            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;
                
                // No kiting!
                if (me->GetDistance(me->getVictim()) > 60.00f && me->GetDistance(me->getVictim()) < 120.00f)
                    DoCast(me->getVictim(), SPELL_SUMMON);
                
                // Supreme mode
                if (SupremeTimer <= diff)
                {
                    if (!me->HasAura(SPELL_SUPREME))
                        DoCast(me, SPELL_SUPREME);
                        
                    Talk(SAY_SUPREME);
                    SupremeTimer = 45000;
                }
                else
                    SupremeTimer -= diff;
                
                // Stomp
                if (StompTimer < diff)
                {
                    DoCast(me, SPELL_STOMP);
                    StompTimer = 30000;
                }
                else
                    StompTimer -= diff;
                
                // Cyclone
                if (CycloneTimer < diff)
                {
                    DoCast(me->getVictim(), SPELL_CYCLONE);
                    CycloneTimer = 20000;
                }
                else
                    CycloneTimer -= diff;
                    
                // Silence
                if (SilenceTimer < diff)
                {
                    DoCast(me, SPELL_SILENCE);
                    SilenceTimer = urand(20000, 30000);
                }
                else 
                    SilenceTimer -= diff;
                    
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_ossirianAI (creature);
        }
};

class ossirian_crystal : public GameObjectScript
{
    public:
        ossirian_crystal() : GameObjectScript("go_ossirian_crystal")
        {
        }

        bool OnGossipHello(Player* player, GameObject* go)
        {            
            InstanceScript* Instance = player->GetInstanceScript();

            if (!Instance)
                return false;
            
            Creature* Ossirian = player->FindNearestCreature(NPC_OSSIRIAN, 30.0f);
            
            if (!Ossirian)
                return false;

            Ossirian->AI()->DoAction(0xBEEF);
            return true;
        }
};

void AddSC_boss_ossirian()
{
    new boss_ossirian();
    new ossirian_crystal();
}
