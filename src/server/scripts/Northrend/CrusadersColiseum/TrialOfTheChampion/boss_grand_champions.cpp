/*
 * Copyright (C) 2008 - 2010 Trinity <http://www.trinitycore.org/>
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
Author: Kuidin Sergey (Ghost)
SDName: boss_grand_champions
SD%Complete: 50 %
SDComment: Is missing the ai to make the npcs look for a new mount and use it.
SDCategory: Trial Of the Champion
EndScriptData */

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"
#include "Vehicle.h"
#include "trial_of_the_champion.h"

enum eSpells
{
    //Vehicle

    SPELL_SHIELD_BREAKER            = 68504,
    SPELL_SHIELD                    = 62544,

    // Marshal Jacob Alerius && Mokra the Skullcrusher || Warrior
    SPELL_MORTAL_STRIKE             = 68783,
    SPELL_MORTAL_STRIKE_H           = 68784,
    SPELL_BLADESTORM                = 63784,
    SPELL_INTERCEPT                 = 67540,
    SPELL_ROLLING_THROW             = 47115, //not implemented in the AI yet...

    // Ambrose Boltspark && Eressea Dawnsinger || Mage
    SPELL_FIREBALL                  = 66042,
    SPELL_FIREBALL_H                = 68310,
    SPELL_BLAST_WAVE                = 66044,
    SPELL_BLAST_WAVE_H              = 68312,
    SPELL_HASTE                     = 66045,
    SPELL_POLYMORPH                 = 66043,
    SPELL_POLYMORPH_H               = 68311,

    // Colosos && Runok Wildmane || Shaman
    SPELL_CHAIN_LIGHTNING           = 67529,
    SPELL_CHAIN_LIGHTNING_H         = 68319,
    SPELL_EARTH_SHIELD              = 67530,
    SPELL_HEALING_WAVE              = 67528,
    SPELL_HEALING_WAVE_H            = 68318,
    SPELL_HEX_OF_MENDING            = 67534,

    // Jaelyne Evensong && Zul'tore || Hunter
    SPELL_DISENGAGE                 = 68340, //not implemented in the AI yet...
    SPELL_LIGHTNING_ARROWS          = 66083,
    SPELL_MULTI_SHOT                = 49047,
    SPELL_SHOOT                     = 65868,
    SPELL_SHOOT_H                   = 67988,

    // Lana Stouthammer Evensong && Deathstalker Visceri || Rouge
    SPELL_EVISCERATE                = 67709,
    SPELL_EVISCERATE_H              = 68317,
    SPELL_FAN_OF_KNIVES             = 67706,
    SPELL_POISON_BOTTLE             = 67701
};
enum eEnums
{
    SAY_START_1                      = -1999939,
    SAY_START_2                      = -1999937
};

enum eSeat
{
    SEAT_ID_0                       = 0
};

/*
struct Point
{
    float x,y,z;
};

const Point MovementPoint[] =
{
  {746.84f,623.15f,411.41f},
  {747.96f,620.29f,411.09f},
  {750.23f,618.35f,411.09f}
};
*/
void AggroAllPlayers(Creature* pTemp)
{
    Map::PlayerList const &PlList = pTemp->GetMap()->GetPlayers();

    if(PlList.isEmpty())
            return;

    for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
    {
        if(Player* pPlayer = i->getSource())
        {
            if(pPlayer->isGameMaster())
                continue;

            if(pPlayer->isAlive())
            {
                pTemp->RemoveFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE);
                pTemp->SetReactState(REACT_AGGRESSIVE);
                pTemp->SetInCombatWith(pPlayer);
                pPlayer->SetInCombatWith(pTemp);
                pTemp->AddThreat(pPlayer, 0.0f);
            }
        }
    }
}

bool GrandChampionsOutVehicle(Creature* me)
{
    InstanceScript* pInstance = me->GetInstanceScript();

    if (!pInstance)
        return false;

    Creature* pGrandChampion1 = Unit::GetCreature(*me, pInstance->GetData64(DATA_GRAND_CHAMPION_1));
    Creature* pGrandChampion2 = Unit::GetCreature(*me, pInstance->GetData64(DATA_GRAND_CHAMPION_2));
    Creature* pGrandChampion3 = Unit::GetCreature(*me, pInstance->GetData64(DATA_GRAND_CHAMPION_3));

    if (pGrandChampion1 && pGrandChampion2 && pGrandChampion3)
    {
        if (!pGrandChampion1->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT) &&
            !pGrandChampion2->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT) &&
            !pGrandChampion3->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT))
            return true;
    }

    return false;
}

/*
* Generic AI for vehicles used by npcs in ToC, it needs more improvements.  *
* Script Complete: 25%.                                                     *
*/

class generic_vehicleAI_toc5 : public CreatureScript
{
public:
    generic_vehicleAI_toc5() : CreatureScript("generic_vehicleAI_toc5") { }

        CreatureAI* GetAI(Creature* pCreature) const
    {
        return new generic_vehicleAI_toc5AI(pCreature);
    }

    struct generic_vehicleAI_toc5AI : public npc_escortAI
    {
        generic_vehicleAI_toc5AI(Creature* pCreature) : npc_escortAI(pCreature)
        {
            SetDespawnAtEnd(false);
            uiWaypointPath = 0;
            pInstance = (InstanceScript*)pCreature->GetInstanceScript();
        }

        InstanceScript* pInstance;

        uint32 uiShieldBreakerTimer;
        uint32 uiBuffTimer;

        uint32 uiWaypointPath;

        void Reset()
        {
            uiShieldBreakerTimer = 8000;
            uiBuffTimer = urand(30000,60000);

            if (me->GetVehicleKit())
                me->GetVehicleKit()->Reset();
        }

        void SetData(uint32 uiType, uint32 uiData)
        {
            switch(uiType)
            {
                case 1:
                    AddWaypoint(0,746.45f,647.03f,411.57f);
                    AddWaypoint(1,771.434f, 642.606f, 411.9f);
                    AddWaypoint(2,779.807f, 617.535f, 411.716f);
                    AddWaypoint(3,771.098f, 594.635f, 411.625f);
                    AddWaypoint(4,746.887f, 583.425f, 411.668f);
                    AddWaypoint(5,715.176f, 583.782f, 412.394f);
                    AddWaypoint(6,720.719f, 591.141f, 411.737f);
                    uiWaypointPath = 1;
                    break;
                case 2:
                    AddWaypoint(0,746.45f,647.03f,411.57f);
                    AddWaypoint(1,771.434f, 642.606f, 411.9f);
                    AddWaypoint(2,779.807f, 617.535f, 411.716f);
                    AddWaypoint(3,771.098f, 594.635f, 411.625f);
                    AddWaypoint(4,746.887f, 583.425f, 411.668f);
                    AddWaypoint(5,746.16f, 571.678f, 412.389f);
                    AddWaypoint(6,746.887f, 583.425f, 411.668f);
                    uiWaypointPath = 2;
                    break;
                case 3:
                    AddWaypoint(0,746.45f,647.03f,411.57f);
                    AddWaypoint(1,771.434f, 642.606f, 411.9f);
                    AddWaypoint(2,779.807f, 617.535f, 411.716f);
                    AddWaypoint(3,771.098f, 594.635f, 411.625f);
                    AddWaypoint(4,777.759f, 584.577f, 412.393f);
                    AddWaypoint(5,772.48f, 592.99f, 411.68f);
                    uiWaypointPath = 3;
                    break;
            }

            if (uiType <= 3)
                Start(false,true,0,NULL);
        }

        void WaypointReached(uint32 i)
        {
            switch(i)
            {
                case 2:
                    if (pInstance && uiWaypointPath == 3 || uiWaypointPath == 2)
                        pInstance->SetData(DATA_MOVEMENT_DONE, pInstance->GetData(DATA_MOVEMENT_DONE)+1);
                    break;
                case 3:
                    if (pInstance)
                        pInstance->SetData(DATA_MOVEMENT_DONE, pInstance->GetData(DATA_MOVEMENT_DONE)+1);
                    break;
            }
        }

        void EnterCombat(Unit* pWho)
        {
            DoCastSpellShield();
        }

        void DoCastSpellShield()
        {
            for (uint8 i = 0; i < 3; ++i)
                DoCast(me,SPELL_SHIELD,true);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            npc_escortAI::UpdateAI(uiDiff);

            if (!UpdateVictim())
                return;

            if (uiBuffTimer <= uiDiff)
            {
                    DoCastSpellShield();
                uiBuffTimer = urand(30000,45000);
            }else uiBuffTimer -= uiDiff;

            //dosen't work at all
            if (uiShieldBreakerTimer <= uiDiff)
            {
                Vehicle *pVehicle = me->GetVehicleKit();
                if (!pVehicle)


                    return;


                if (Unit* pPassenger = pVehicle->GetPassenger(SEAT_ID_0))
                {
                    Map::PlayerList const& players = me->GetMap()->GetPlayers();
                    if (me->GetMap()->IsDungeon() && !players.isEmpty())
                    {
                        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        {
                            Player* pPlayer = itr->getSource();
                            if (pPlayer && !pPlayer->isGameMaster() && me->IsInRange(pPlayer,10.0f,30.0f,false))
                            {
                                pPassenger->CastSpell(pPlayer,SPELL_SHIELD_BREAKER,true);
                                break;
                            }
                        }
                    }
                }
                uiShieldBreakerTimer = 7000;
            }else uiShieldBreakerTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };
};


// Marshal Jacob Alerius && Mokra the Skullcrusher || Warrior
class boss_warrior_toc5 : public CreatureScript
{
public:
    boss_warrior_toc5() : CreatureScript("boss_warrior_toc5") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_warrior_toc5AI(pCreature);
    }

    struct boss_warrior_toc5AI : public ScriptedAI
    {

        boss_warrior_toc5AI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pInstance = (InstanceScript*)pCreature->GetInstanceScript();

            bDone = false;
            bHome = false;

            uiPhase = 0;
            uiPhaseTimer = 0;

            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE);
        }

        InstanceScript* pInstance;

        uint8 uiPhase;
        uint32 uiPhaseTimer;

        uint32 uiBladeStormTimer;
        uint32 uiInterceptTimer;
        uint32 uiMortalStrikeTimer;
        uint32 uiAttackTimer;
        uint32 uiResetTimer;

        bool bDone;
        bool bHome;

        void Reset()
        {
            uiBladeStormTimer = urand(15000,20000);
            uiInterceptTimer  = 7000;
            uiMortalStrikeTimer = urand(8000,12000);
        }

        void JustReachedHome()
        {
            ScriptedAI::JustReachedHome();

            if (!bHome)
                return;

            uiPhaseTimer = 15000;
            uiPhase = 1;

            bHome = false;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!bDone && GrandChampionsOutVehicle(me))
            {
                bDone = true;

             DoScriptText(SAY_START_2, me);

                if (pInstance && me->GetGUID() == pInstance->GetData64(DATA_GRAND_CHAMPION_1))
                    me->SetHomePosition(739.678f,662.541f,412.393f,4.49f);
                else if (pInstance && me->GetGUID() == pInstance->GetData64(DATA_GRAND_CHAMPION_2))
                    me->SetHomePosition(746.71f,661.02f,411.69f,4.6f);
                else if (pInstance && me->GetGUID() == pInstance->GetData64(DATA_GRAND_CHAMPION_3))
                    me->SetHomePosition(754.34f,660.70f,412.39f,4.79f);

                EnterEvadeMode();
                bHome = true;
            }

            if (uiPhaseTimer <= uiDiff)
            {
                if (uiPhase == 1)
                {
                    AggroAllPlayers(me);
                    uiPhase = 0;
                }
            }else uiPhaseTimer -= uiDiff;

            if (!UpdateVictim() || me->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT))
                return;

            if (uiInterceptTimer <= uiDiff)
            {
                Map::PlayerList const& players = me->GetMap()->GetPlayers();
                if (me->GetMap()->IsDungeon() && !players.isEmpty())
                {
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    {
                        Player* pPlayer = itr->getSource();
                        if (pPlayer && !pPlayer->isGameMaster() && me->IsInRange(pPlayer,8.0f,25.0f,false))
                        {
                            DoResetThreat();
                            me->AddThreat(pPlayer,5.0f);
                            DoCast(pPlayer,SPELL_INTERCEPT);
                            break;
                        }
                    }
                }
                uiInterceptTimer = 25000;
            } else uiInterceptTimer -= uiDiff;

            if (uiBladeStormTimer <= uiDiff)
            {
                DoCastVictim(SPELL_BLADESTORM);
                uiBladeStormTimer = urand(25000,35000);
            } else uiBladeStormTimer -= uiDiff;

            if (uiMortalStrikeTimer <= uiDiff)
            {
                DoCastVictim(SPELL_MORTAL_STRIKE);
                uiMortalStrikeTimer = urand(22000,26000);
            } else uiMortalStrikeTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* pKiller)
        {
                 DoScriptText(SAY_START_1, me);
            if (pInstance)
                pInstance->SetData(BOSS_GRAND_CHAMPIONS, DONE);

        }
    };
};


// Ambrose Boltspark && Eressea Dawnsinger || Mage
class boss_mage_toc5 : public CreatureScript
{
public:
    boss_mage_toc5() : CreatureScript("boss_mage_toc5") { }

        CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_mage_toc5AI(pCreature);
    }

    struct boss_mage_toc5AI : public ScriptedAI
    {

        boss_mage_toc5AI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pInstance = (InstanceScript*)pCreature->GetInstanceScript();

            bDone = false;
            bHome = false;

            uiPhase = 0;
            uiPhaseTimer = 0;

            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE);
        }

        InstanceScript* pInstance;

        uint8 uiPhase;
        uint32 uiPhaseTimer;

        uint32 uiFireBallTimer;
        uint32 uiBlastWaveTimer;
        uint32 uiHasteTimer;
        uint32 uiPolymorphTimer;

        bool bDone;
        bool bHome;

        void Reset()
        {
            uiFireBallTimer = 5000;
            uiPolymorphTimer  = 8000;
            uiBlastWaveTimer = 12000;
            uiHasteTimer = 22000;
        }

        void JustReachedHome()
        {
            ScriptedAI::JustReachedHome();

            if (!bHome)
                return;

            uiPhaseTimer = 15000;
            uiPhase = 1;

            bHome = false;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!bDone && GrandChampionsOutVehicle(me))
            {
                bDone = true;

                if (pInstance && me->GetGUID() == pInstance->GetData64(DATA_GRAND_CHAMPION_1))
                    me->SetHomePosition(739.678f,662.541f,412.393f,4.49f);
                else if (pInstance && me->GetGUID() == pInstance->GetData64(DATA_GRAND_CHAMPION_2))
                    me->SetHomePosition(746.71f,661.02f,411.69f,4.6f);
                else if (pInstance && me->GetGUID() == pInstance->GetData64(DATA_GRAND_CHAMPION_3))
                    me->SetHomePosition(754.34f,660.70f,412.39f,4.79f);

                if (pInstance)
                    pInstance->SetData(BOSS_GRAND_CHAMPIONS, IN_PROGRESS);

                EnterEvadeMode();
                bHome = true;
            }

            if (uiPhaseTimer <= uiDiff)
            {
                if (uiPhase == 1)
                {
                    AggroAllPlayers(me);
                    uiPhase = 0;
                }
            }else uiPhaseTimer -= uiDiff;

            if (!UpdateVictim() || me->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT))
                return;

            if (uiFireBallTimer <= uiDiff)
            {
                DoCastVictim(SPELL_FIREBALL);
                uiFireBallTimer = 17000;
            } else uiFireBallTimer -= uiDiff;

            if (uiPolymorphTimer <= uiDiff)
            {
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM,0))
                    DoCast(pTarget, SPELL_POLYMORPH);
                uiPolymorphTimer = 22000;
            } else uiPolymorphTimer -= uiDiff;

            if (uiBlastWaveTimer <= uiDiff)
            {
                DoCastAOE(SPELL_BLAST_WAVE,false);
                uiBlastWaveTimer = 30000;
            } else uiBlastWaveTimer -= uiDiff;

            if (uiHasteTimer <= uiDiff)
            {
                me->InterruptNonMeleeSpells(true);

                DoCast(me,SPELL_HASTE);
                uiHasteTimer = 40000;
            } else uiHasteTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* pKiller)
        {
                 DoScriptText(SAY_START_1, me);
            if (pInstance)
                pInstance->SetData(BOSS_GRAND_CHAMPIONS, DONE);

        }
    };
};


// Colosos && Runok Wildmane || Shaman
class boss_shaman_toc5 : public CreatureScript
{
public:
    boss_shaman_toc5() : CreatureScript("boss_shaman_toc5") { }

        CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_shaman_toc5AI(pCreature);
    }

    struct boss_shaman_toc5AI : public ScriptedAI
    {
        boss_shaman_toc5AI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pInstance = (InstanceScript*)pCreature->GetInstanceScript();

            bDone = false;
            bHome = false;

            uiPhase = 0;
            uiPhaseTimer = 0;

            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE);
        }

        InstanceScript* pInstance;

        uint8 uiPhase;
        uint32 uiPhaseTimer;

        uint32 uiChainLightningTimer;
        uint32 uiEartShieldTimer;
        uint32 uiHealingWaveTimer;
        uint32 uiHexMendingTimer;

        bool bDone;
        bool bHome;

        void Reset()
        {
            uiChainLightningTimer = 16000;
            uiHealingWaveTimer = 12000;
            uiEartShieldTimer = urand(30000,35000);
            uiHexMendingTimer = urand(20000,25000);
        }

        void EnterCombat(Unit* pWho)
        {
            DoCast(me,SPELL_EARTH_SHIELD);
            DoCast(pWho,SPELL_HEX_OF_MENDING);
        };

        void JustReachedHome()
        {
            ScriptedAI::JustReachedHome();

            if (!bHome)
                return;

            uiPhaseTimer = 15000;
            uiPhase = 1;

            bHome = false;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!bDone && GrandChampionsOutVehicle(me))
            {
                bDone = true;

                if (pInstance && me->GetGUID() == pInstance->GetData64(DATA_GRAND_CHAMPION_1))
                    me->SetHomePosition(739.678f,662.541f,412.393f,4.49f);
                else if (pInstance && me->GetGUID() == pInstance->GetData64(DATA_GRAND_CHAMPION_2))
                    me->SetHomePosition(746.71f,661.02f,411.69f,4.6f);
                else if (pInstance && me->GetGUID() == pInstance->GetData64(DATA_GRAND_CHAMPION_3))
                    me->SetHomePosition(754.34f,660.70f,412.39f,4.79f);

                if (pInstance)
                    pInstance->SetData(BOSS_GRAND_CHAMPIONS, IN_PROGRESS);

                EnterEvadeMode();
                bHome = true;
            }

            if (uiPhaseTimer <= uiDiff)
            {
                if (uiPhase == 1)
                {
                    AggroAllPlayers(me);
                    uiPhase = 0;
                }
            }else uiPhaseTimer -= uiDiff;

            if (!UpdateVictim() || me->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT))
                return;

            if (uiChainLightningTimer <= uiDiff)
            {
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM,0))
                    DoCast(pTarget,SPELL_CHAIN_LIGHTNING);

                uiChainLightningTimer = 23000;
            } else uiChainLightningTimer -= uiDiff;

            if (uiHealingWaveTimer <= uiDiff)
            {
                bool bChance = urand(0,1);

                if (!bChance)
                {
                    if (Unit* pFriend = DoSelectLowestHpFriendly(40))
                        DoCast(pFriend,SPELL_HEALING_WAVE);
                } else
                    DoCast(me,SPELL_HEALING_WAVE);

                uiHealingWaveTimer = 19000;
            } else uiHealingWaveTimer -= uiDiff;

            if (uiEartShieldTimer <= uiDiff)
            {
                DoCast(me,SPELL_EARTH_SHIELD);

                uiEartShieldTimer = urand(40000,45000);
            } else uiEartShieldTimer -= uiDiff;

            if (uiHexMendingTimer <= uiDiff)
            {
                DoCastVictim(SPELL_HEX_OF_MENDING,true);

                uiHexMendingTimer = urand(30000,35000);
            } else uiHexMendingTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* pKiller)
        {
                 DoScriptText(SAY_START_1, me);
            if (pInstance)
                pInstance->SetData(BOSS_GRAND_CHAMPIONS, DONE);

        }
    };
};


// Jaelyne Evensong && Zul'tore || Hunter
class boss_hunter_toc5 : public CreatureScript
{
public:
    boss_hunter_toc5() : CreatureScript("boss_hunter_toc5") { }

        CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_hunter_toc5AI(pCreature);
    }

    struct boss_hunter_toc5AI : public ScriptedAI
    {
        boss_hunter_toc5AI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pInstance = (InstanceScript*)pCreature->GetInstanceScript();

            bDone = false;
            bHome = false;

            uiPhase = 0;
            uiPhaseTimer = 0;

            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE);
        }

        InstanceScript* pInstance;

        uint8 uiPhase;
        uint32 uiPhaseTimer;

        uint32 uiShootTimer;
        uint32 uiDisengageCooldown;
        uint32 uiMultiShotTimer;
        uint32 uiLightningArrowsTimer;

        uint64 uiTargetGUID;

        bool bShoot;
        bool bDone;
        bool bHome;

        void Reset()
        {
            uiShootTimer = 12000;
            uiMultiShotTimer = 0;
            uiLightningArrowsTimer = 7000;
            uiDisengageCooldown = 10000;

            uiTargetGUID = 0;

            bShoot = false;
        }

        void JustReachedHome()
        {
            ScriptedAI::JustReachedHome();

            if (!bHome)
                return;

            uiPhaseTimer = 15000;
            uiPhase = 1;

            bHome = false;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!bDone && GrandChampionsOutVehicle(me))
            {
                bDone = true;

                if (pInstance && me->GetGUID() == pInstance->GetData64(DATA_GRAND_CHAMPION_1))
                    me->SetHomePosition(739.678f,662.541f,412.393f,4.49f);
                else if (pInstance && me->GetGUID() == pInstance->GetData64(DATA_GRAND_CHAMPION_2))
                    me->SetHomePosition(746.71f,661.02f,411.69f,4.6f);
                else if (pInstance && me->GetGUID() == pInstance->GetData64(DATA_GRAND_CHAMPION_3))
                    me->SetHomePosition(754.34f,660.70f,412.39f,4.79f);

                if (pInstance)
                    pInstance->SetData(BOSS_GRAND_CHAMPIONS, IN_PROGRESS);

                EnterEvadeMode();
                bHome = true;
            }

            if (uiPhaseTimer <= uiDiff)
            {
                if (uiPhase == 1)
                {
                    AggroAllPlayers(me);
                    uiPhase = 0;
                }
            }else uiPhaseTimer -= uiDiff;

            if (!UpdateVictim() || me->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT))
                return;

            if (uiDisengageCooldown <= uiDiff)
            {
                if (me->IsWithinDistInMap(me->getVictim(), 5) && uiDisengageCooldown == 0)
                {
                    DoCast(me, SPELL_DISENGAGE);
                    uiDisengageCooldown = 35000;
                }
                uiDisengageCooldown = 20000;
            }else uiDisengageCooldown -= uiDiff;

            if (uiLightningArrowsTimer <= uiDiff)
            {
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM,0))
                    DoCast(pTarget,SPELL_LIGHTNING_ARROWS);

                uiLightningArrowsTimer = 15000;

            } else uiLightningArrowsTimer -= uiDiff;

            if (uiShootTimer <= uiDiff)
            {
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_FARTHEST,0,30.0f))
                {
                    uiTargetGUID = pTarget->GetGUID();
                    DoCast(pTarget, SPELL_SHOOT);
                }
                uiShootTimer = 19000;
                uiMultiShotTimer = 8000;
                bShoot = true;
            } else uiShootTimer -= uiDiff;

            if (bShoot && uiMultiShotTimer <= uiDiff)
            {
                me->InterruptNonMeleeSpells(true);
                Unit* pTarget = Unit::GetUnit(*me, uiTargetGUID);

                if (pTarget && me->IsInRange(pTarget,5.0f,30.0f,false))
                {
                    DoCast(pTarget,SPELL_MULTI_SHOT);
                } else
                {
                    Map::PlayerList const& players = me->GetMap()->GetPlayers();
                    if (me->GetMap()->IsDungeon() && !players.isEmpty())
                    {
                        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        {
                            Player* pPlayer = itr->getSource();
                            if (pPlayer && !pPlayer->isGameMaster() && me->IsInRange(pPlayer,5.0f,30.0f,false))
                            {
                                DoCast(pTarget,SPELL_MULTI_SHOT);
                                break;
                            }
                        }
                    }
                }
                bShoot = false;
            } else uiMultiShotTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* pKiller)
        {
             DoScriptText(SAY_START_1, me);
            if (pInstance)
                pInstance->SetData(BOSS_GRAND_CHAMPIONS, DONE);

        }

    };
};


// Lana Stouthammer Evensong && Deathstalker Visceri || Rouge
class boss_rouge_toc5 : public CreatureScript
{
public:
    boss_rouge_toc5() : CreatureScript("boss_rouge_toc5") { }

        CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_rouge_toc5AI(pCreature);
    }

    struct boss_rouge_toc5AI : public ScriptedAI
    {
        boss_rouge_toc5AI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pInstance = (InstanceScript*)pCreature->GetInstanceScript();

            bDone = false;
            bHome = false;

            uiPhase = 0;
            uiPhaseTimer = 0;

            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE);
        }

        InstanceScript* pInstance;

        uint8 uiPhase;
        uint32 uiPhaseTimer;
        uint32 uiEviscerateTimer;
        uint32 uiFanKivesTimer;
        uint32 uiPosionBottleTimer;

        bool bDone;
        bool bHome;

        void Reset()
        {
            uiEviscerateTimer = 8000;
            uiFanKivesTimer   = 14000;
            uiPosionBottleTimer = 19000;
        }

        void JustReachedHome()
        {
            ScriptedAI::JustReachedHome();

            if (!bHome)
                return;

            uiPhaseTimer = 15000;
            uiPhase = 1;

            bHome = false;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!bDone && GrandChampionsOutVehicle(me))
            {
                bDone = true;

                if (pInstance && me->GetGUID() == pInstance->GetData64(DATA_GRAND_CHAMPION_1))
                    me->SetHomePosition(739.678f,662.541f,412.393f,4.49f);
                else if (pInstance && me->GetGUID() == pInstance->GetData64(DATA_GRAND_CHAMPION_2))
                    me->SetHomePosition(746.71f,661.02f,411.69f,4.6f);
                else if (pInstance && me->GetGUID() == pInstance->GetData64(DATA_GRAND_CHAMPION_3))
                    me->SetHomePosition(754.34f,660.70f,412.39f,4.79f);

                if (pInstance)
                    pInstance->SetData(BOSS_GRAND_CHAMPIONS, IN_PROGRESS);

                EnterEvadeMode();
                bHome = true;
            }

            if (uiPhaseTimer <= uiDiff)
            {
                if (uiPhase == 1)
                {
                    AggroAllPlayers(me);
                    uiPhase = 0;
                }
            } else uiPhaseTimer -= uiDiff;

            if (!UpdateVictim() || me->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT))
                return;

            if (uiEviscerateTimer <= uiDiff)
            {
                DoCast(me->getVictim(),SPELL_EVISCERATE);
                uiEviscerateTimer = 22000;
            } else uiEviscerateTimer -= uiDiff;

            if (uiFanKivesTimer <= uiDiff)
            {
                DoCastAOE(SPELL_FAN_OF_KNIVES,false);
                uiFanKivesTimer = 20000;
            } else uiFanKivesTimer -= uiDiff;

            if (uiPosionBottleTimer <= uiDiff)
            {
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM,0))
                DoCast(pTarget,SPELL_POISON_BOTTLE);
                uiPosionBottleTimer = 19000;
            } else uiPosionBottleTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* pKiller)
        {
             DoScriptText(SAY_START_1, me);
            if (pInstance)
                pInstance->SetData(BOSS_GRAND_CHAMPIONS, DONE);

        }
    };
};


void AddSC_boss_grand_champions()
{
    new generic_vehicleAI_toc5();
    new boss_warrior_toc5();
    new boss_mage_toc5();
    new boss_shaman_toc5();
    new boss_hunter_toc5();
    new boss_rouge_toc5();
}
