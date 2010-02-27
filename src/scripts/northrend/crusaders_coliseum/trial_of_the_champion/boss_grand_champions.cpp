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
SDName: boss_grand_champions
SD%Complete: 50 %
SDComment: Is missing the ai to make the npcs look for a new mount and use it.
SDCategory: Trial Of the Champion
EndScriptData */

#include "ScriptedPch.h"
#include "ScriptedEscortAI.h"
#include "Vehicle.h"
#include "trial_of_the_champion.h"

enum eSpells
{
    //Vehicle
    SPELL_CHARGE                    = 63010,
    SPELL_SHIELD_BREAKER            = 68504,
    SPELL_SHIELD                    = 66482,

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
    SPELL_MULTI_SHOT                = 66081,
    SPELL_SHOOT                     = 65868,
    SPELL_SHOOT_H                   = 67988,

    // Lana Stouthammer Evensong && Deathstalker Visceri || Rouge
    SPELL_EVISCERATE                = 67709,
    SPELL_EVISCERATE_H              = 68317,
    SPELL_FAN_OF_KNIVES             = 67706,
    SPELL_POISON_BOTTLE             = 67701
};

enum eSeat
{
    SEAT_ID_0                       = 0
};

struct Point
{
    float x,y,z;
};

const Point MovementPoint[] =
{
  {746.84,623.15,411.41},
  {747.96,620.29,411.09},
  {750.23,618.35,411.09}
};

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

bool GrandChampionsOutVehicle(Creature* m_creature)
{
    ScriptedInstance* pInstance = m_creature->GetInstanceData();

    if (!pInstance)
        return false;

    Creature* pGrandChampion1 = Unit::GetCreature(*m_creature, pInstance->GetData64(DATA_GRAND_CHAMPION_1));
    Creature* pGrandChampion2 = Unit::GetCreature(*m_creature, pInstance->GetData64(DATA_GRAND_CHAMPION_2));
    Creature* pGrandChampion3 = Unit::GetCreature(*m_creature, pInstance->GetData64(DATA_GRAND_CHAMPION_3));

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

struct generic_vehicleAI_toc5AI : public npc_escortAI
{
    generic_vehicleAI_toc5AI(Creature* pCreature) : npc_escortAI(pCreature), pVehicle(pCreature->GetVehicleKit())
    {
        SetDespawnAtEnd(false);
        uiWaypointPath = 0;

        pInstance = pCreature->GetInstanceData();
    }

    Vehicle* pVehicle;

    ScriptedInstance* pInstance;

    uint32 uiChargeTimer;
    uint32 uiShieldBreakerTimer;
    uint32 uiBuffTimer;

    uint32 uiWaypointPath;

    void Reset()
    {
        uiChargeTimer = 5000;
        uiShieldBreakerTimer = 8000;
        uiBuffTimer = urand(30000,60000);
    }

    void SetData(uint32 uiType, uint32 uiData)
    {
        switch(uiType)
        {
            case 1:
                AddWaypoint(0,747.36,634.07,411.572);
                AddWaypoint(1,780.43,607.15,411.82);
                AddWaypoint(2,785.99,599.41,411.92);
                AddWaypoint(3,778.44,601.64,411.79);
                uiWaypointPath = 1;
                break;
            case 2:
                AddWaypoint(0,747.35,634.07,411.57);
                AddWaypoint(1,768.72,581.01,411.92);
                AddWaypoint(2,763.55,590.52,411.71);
                uiWaypointPath = 2;
                break;
            case 3:
                AddWaypoint(0,747.35,634.07,411.57);
                AddWaypoint(1,784.02,645.33,412.39);
                AddWaypoint(2,775.67,641.91,411.91);
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
            DoCast(m_creature,SPELL_SHIELD,true);
    }

    void UpdateAI(const uint32 uiDiff)
    {
        npc_escortAI::UpdateAI(uiDiff);

        if (!UpdateVictim())
            return;

        if (uiBuffTimer <= uiDiff)
        {
            if (!m_creature->HasAura(SPELL_SHIELD))
                DoCastSpellShield();

            uiBuffTimer = urand(30000,45000);
        }else uiBuffTimer -= uiDiff;

        if (uiChargeTimer <= uiDiff)
        {
            Map::PlayerList const& players = m_creature->GetMap()->GetPlayers();
            if (m_creature->GetMap()->IsDungeon() && !players.isEmpty())
            {
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    Player* pPlayer = itr->getSource();
                    if (pPlayer && !pPlayer->isGameMaster() && m_creature->IsInRange(pPlayer,8.0f,25.0f,false))
                    {
                        DoResetThreat();
                        m_creature->AddThreat(pPlayer,1.0f);
                        DoCast(pPlayer, SPELL_CHARGE);
                        break;
                    }
                }
            }
            uiChargeTimer = 5000;
        }else uiChargeTimer -= uiDiff;

        //dosen't work at all
        if (uiShieldBreakerTimer <= uiDiff)
        {
            if (!pVehicle)
            {
                pVehicle = m_creature->GetVehicleKit();
                return;
            }

            if (Unit* pPassenger = pVehicle->GetPassenger(SEAT_ID_0))
            {
                Map::PlayerList const& players = m_creature->GetMap()->GetPlayers();
                if (m_creature->GetMap()->IsDungeon() && !players.isEmpty())
                {
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    {
                        Player* pPlayer = itr->getSource();
                        if (pPlayer && !pPlayer->isGameMaster() && m_creature->IsInRange(pPlayer,10.0f,30.0f,false))
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

CreatureAI* GetAI_generic_vehicleAI_toc5(Creature* pCreature)
{
    return new generic_vehicleAI_toc5AI(pCreature);
}

// Marshal Jacob Alerius && Mokra the Skullcrusher || Warrior
struct boss_warrior_toc5AI : public ScriptedAI
{
    boss_warrior_toc5AI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pInstance = pCreature->GetInstanceData();

        bDone = false;
        bHome = false;

        uiPhase = 0;
        uiPhaseTimer = 0;

        m_creature->SetReactState(REACT_PASSIVE);
        // THIS IS A HACK, SHOULD BE REMOVED WHEN THE EVENT IS FULL SCRIPTED
        m_creature->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE);
    }

    ScriptedInstance* pInstance;

    uint8 uiPhase;
    uint32 uiPhaseTimer;

    uint32 uiBladeStormTimer;
    uint32 uiInterceptTimer;
    uint32 uiMortalStrikeTimer;
    uint32 uiAttackTimer;

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
        if (!bDone && GrandChampionsOutVehicle(m_creature))
        {
            bDone = true;

            if (m_creature->GetGUID() == pInstance->GetData64(DATA_GRAND_CHAMPION_1))
                m_creature->SetHomePosition(739.678,662.541,412.393,4.49);
            else if (m_creature->GetGUID() == pInstance->GetData64(DATA_GRAND_CHAMPION_2))
                m_creature->SetHomePosition(746.71,661.02,411.69,4.6);
            else if (m_creature->GetGUID() == pInstance->GetData64(DATA_GRAND_CHAMPION_3))
                m_creature->SetHomePosition(754.34,660.70,412.39,4.79);

            EnterEvadeMode();
            bHome = true;
        }

        if (uiPhaseTimer <= uiDiff)
        {
            if (uiPhase == 1)
            {
                AggroAllPlayers(m_creature);
                uiPhase = 0;
            }
        }else uiPhaseTimer -= uiDiff;

        if (!UpdateVictim() || m_creature->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT))
            return;

        if (uiInterceptTimer <= uiDiff)
        {
            Map::PlayerList const& players = m_creature->GetMap()->GetPlayers();
            if (m_creature->GetMap()->IsDungeon() && !players.isEmpty())
            {
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    Player* pPlayer = itr->getSource();
                    if (pPlayer && !pPlayer->isGameMaster() && m_creature->IsInRange(pPlayer,8.0f,25.0f,false))
                    {
                        DoResetThreat();
                        m_creature->AddThreat(pPlayer,5.0f);
                        DoCast(pPlayer,SPELL_INTERCEPT);
                        break;
                    }
                }
            }
            uiInterceptTimer = 7000;
        } else uiInterceptTimer -= uiDiff;

        if (uiBladeStormTimer <= uiDiff)
        {
            DoCastVictim(SPELL_BLADESTORM);
            uiBladeStormTimer = urand(15000,20000);
        } else uiBladeStormTimer -= uiDiff;

        if (uiMortalStrikeTimer <= uiDiff)
        {
            DoCastVictim(DUNGEON_MODE(SPELL_MORTAL_STRIKE, SPELL_MORTAL_STRIKE_H));
            uiMortalStrikeTimer = urand(8000,12000);
        } else uiMortalStrikeTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* pKiller)
    {
        if (pInstance)
            pInstance->SetData(BOSS_GRAND_CHAMPIONS, DONE);
    }
};

CreatureAI* GetAI_boss_warrior_toc5(Creature* pCreature)
{
    return new boss_warrior_toc5AI(pCreature);
}

// Ambrose Boltspark && Eressea Dawnsinger || Mage
struct boss_mage_toc5AI : public ScriptedAI
{
    boss_mage_toc5AI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pInstance = pCreature->GetInstanceData();

        bDone = false;
        bHome = false;

        uiPhase = 0;
        uiPhaseTimer = 0;

        m_creature->SetReactState(REACT_PASSIVE);
        // THIS IS A HACK, SHOULD BE REMOVED WHEN THE EVENT IS FULL SCRIPTED
        m_creature->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE);
    }

    ScriptedInstance* pInstance;

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
        if (!bDone && GrandChampionsOutVehicle(m_creature))
        {
            bDone = true;

            if (m_creature->GetGUID() == pInstance->GetData64(DATA_GRAND_CHAMPION_1))
                m_creature->SetHomePosition(739.678,662.541,412.393,4.49);
            else if (m_creature->GetGUID() == pInstance->GetData64(DATA_GRAND_CHAMPION_2))
                m_creature->SetHomePosition(746.71,661.02,411.69,4.6);
            else if (m_creature->GetGUID() == pInstance->GetData64(DATA_GRAND_CHAMPION_3))
                m_creature->SetHomePosition(754.34,660.70,412.39,4.79);

            if (pInstance)
                pInstance->SetData(BOSS_GRAND_CHAMPIONS, IN_PROGRESS);

            EnterEvadeMode();
            bHome = true;
        }

        if (uiPhaseTimer <= uiDiff)
        {
            if (uiPhase == 1)
            {
                AggroAllPlayers(m_creature);
                uiPhase = 0;
            }
        }else uiPhaseTimer -= uiDiff;

        if (uiFireBallTimer <= uiDiff)
        {
            if (m_creature->getVictim())
                DoCastVictim(DUNGEON_MODE(SPELL_FIREBALL,SPELL_FIREBALL_H));
            uiFireBallTimer = 5000;
        } else uiFireBallTimer -= uiDiff;


        if (!UpdateVictim() || m_creature->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT))
            return;

        if (uiFireBallTimer <= uiDiff)
        {
            DoCastVictim(DUNGEON_MODE(SPELL_FIREBALL,SPELL_FIREBALL_H));
            uiFireBallTimer = 5000;
        } else uiFireBallTimer -= uiDiff;

        if (uiPolymorphTimer <= uiDiff)
        {
            if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM,0))
                DoCast(pTarget, DUNGEON_MODE(SPELL_POLYMORPH,SPELL_POLYMORPH_H));
            uiPolymorphTimer = 8000;
        } else uiPolymorphTimer -= uiDiff;

        if (uiBlastWaveTimer <= uiDiff)
        {
            DoCastAOE(DUNGEON_MODE(SPELL_BLAST_WAVE,SPELL_BLAST_WAVE_H),false);
            uiBlastWaveTimer = 13000;
        } else uiBlastWaveTimer -= uiDiff;

        if (uiHasteTimer <= uiDiff)
        {
            m_creature->InterruptNonMeleeSpells(true);

            DoCast(m_creature,SPELL_HASTE);
            uiHasteTimer = 22000;
        } else uiHasteTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* pKiller)
    {
        if (pInstance)
            pInstance->SetData(BOSS_GRAND_CHAMPIONS, DONE);
    }
};

CreatureAI* GetAI_boss_mage_toc5(Creature* pCreature)
{
    return new boss_mage_toc5AI(pCreature);
}

// Colosos && Runok Wildmane || Shaman
struct boss_shaman_toc5AI : public ScriptedAI
{
    boss_shaman_toc5AI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pInstance = pCreature->GetInstanceData();

        bDone = false;
        bHome = false;

        uiPhase = 0;
        uiPhaseTimer = 0;

        m_creature->SetReactState(REACT_PASSIVE);
        // THIS IS A HACK, SHOULD BE REMOVED WHEN THE EVENT IS FULL SCRIPTED
        m_creature->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE);
    }

    ScriptedInstance* pInstance;

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
        DoCast(m_creature,SPELL_EARTH_SHIELD);
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
        if (!bDone && GrandChampionsOutVehicle(m_creature))
        {
            bDone = true;

            if (m_creature->GetGUID() == pInstance->GetData64(DATA_GRAND_CHAMPION_1))
                m_creature->SetHomePosition(739.678,662.541,412.393,4.49);
            else if (m_creature->GetGUID() == pInstance->GetData64(DATA_GRAND_CHAMPION_2))
                m_creature->SetHomePosition(746.71,661.02,411.69,4.6);
            else if (m_creature->GetGUID() == pInstance->GetData64(DATA_GRAND_CHAMPION_3))
                m_creature->SetHomePosition(754.34,660.70,412.39,4.79);

            if (pInstance)
                pInstance->SetData(BOSS_GRAND_CHAMPIONS, IN_PROGRESS);

            EnterEvadeMode();
            bHome = true;
        }

        if (uiPhaseTimer <= uiDiff)
        {
            if (uiPhase == 1)
            {
                AggroAllPlayers(m_creature);
                uiPhase = 0;
            }
        }else uiPhaseTimer -= uiDiff;

        if (!UpdateVictim() || m_creature->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT))
            return;

        if (uiChainLightningTimer <= uiDiff)
        {
            if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM,0))
                DoCast(pTarget,DUNGEON_MODE(SPELL_CHAIN_LIGHTNING,SPELL_CHAIN_LIGHTNING_H));

            uiChainLightningTimer = 16000;
        } else uiChainLightningTimer -= uiDiff;

        if (uiHealingWaveTimer <= uiDiff)
        {
            bool bChance = urand(0,1);

            if (!bChance)
            {
                if (Unit* pFriend = DoSelectLowestHpFriendly(40))
                    DoCast(pFriend,DUNGEON_MODE(SPELL_HEALING_WAVE,SPELL_HEALING_WAVE_H));
            } else
                DoCast(m_creature,DUNGEON_MODE(SPELL_HEALING_WAVE,SPELL_HEALING_WAVE_H));

            uiHealingWaveTimer = 12000;
        } else uiHealingWaveTimer -= uiDiff;

        if (uiEartShieldTimer <= uiDiff)
        {
            DoCast(m_creature,SPELL_EARTH_SHIELD);

            uiEartShieldTimer = urand(30000,35000);
        } else uiEartShieldTimer -= uiDiff;

        if (uiHexMendingTimer <= uiDiff)
        {
            DoCastVictim(SPELL_HEX_OF_MENDING,true);

            uiHexMendingTimer = urand(20000,25000);
        } else uiHexMendingTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* pKiller)
    {
        if (pInstance)
            pInstance->SetData(BOSS_GRAND_CHAMPIONS, DONE);
    }
};

CreatureAI* GetAI_boss_shaman_toc5(Creature* pCreature)
{
    return new boss_shaman_toc5AI(pCreature);
}

// Jaelyne Evensong && Zul'tore || Hunter
struct boss_hunter_toc5AI : public ScriptedAI
{
    boss_hunter_toc5AI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pInstance = pCreature->GetInstanceData();

        bDone = false;
        bHome = false;

        uiPhase = 0;
        uiPhaseTimer = 0;

        m_creature->SetReactState(REACT_PASSIVE);
        // THIS IS A HACK, SHOULD BE REMOVED WHEN THE EVENT IS FULL SCRIPTED
        m_creature->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE);
    }

    ScriptedInstance* pInstance;

    uint8 uiPhase;
    uint32 uiPhaseTimer;

    uint32 uiShootTimer;
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
        if (!bDone && GrandChampionsOutVehicle(m_creature))
        {
            bDone = true;

            if (m_creature->GetGUID() == pInstance->GetData64(DATA_GRAND_CHAMPION_1))
                m_creature->SetHomePosition(739.678,662.541,412.393,4.49);
            else if (m_creature->GetGUID() == pInstance->GetData64(DATA_GRAND_CHAMPION_2))
                m_creature->SetHomePosition(746.71,661.02,411.69,4.6);
            else if (m_creature->GetGUID() == pInstance->GetData64(DATA_GRAND_CHAMPION_3))
                m_creature->SetHomePosition(754.34,660.70,412.39,4.79);

            if (pInstance)
                pInstance->SetData(BOSS_GRAND_CHAMPIONS, IN_PROGRESS);

            EnterEvadeMode();
            bHome = true;
        }

        if (uiPhaseTimer <= uiDiff)
        {
            if (uiPhase == 1)
            {
                AggroAllPlayers(m_creature);
                uiPhase = 0;
            }
        }else uiPhaseTimer -= uiDiff;

        if (!UpdateVictim() || m_creature->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT))
            return;

        if (uiLightningArrowsTimer <= uiDiff)
        {
            DoCastAOE(SPELL_LIGHTNING_ARROWS,false);
            uiLightningArrowsTimer = 7000;
        } else uiLightningArrowsTimer -= uiDiff;

        if (uiShootTimer <= uiDiff)
        {
            if (Unit* pTarget = SelectTarget(SELECT_TARGET_FARTHEST,0,30.0f))
            {
                uiTargetGUID = pTarget->GetGUID();
                DoCast(pTarget, DUNGEON_MODE(SPELL_SHOOT,SPELL_SHOOT_H));
            }
            uiShootTimer = 12000;
            uiMultiShotTimer = 3000;
            bShoot = true;
        } else uiShootTimer -= uiDiff;

        if (bShoot && uiMultiShotTimer <= uiDiff)
        {
            m_creature->InterruptNonMeleeSpells(true);
            Unit* pTarget = Unit::GetUnit(*m_creature, uiTargetGUID);

            if (pTarget && m_creature->IsInRange(pTarget,5.0f,30.0f,false))
            {
                DoCast(pTarget,SPELL_MULTI_SHOT);
            } else
            {
                Map::PlayerList const& players = m_creature->GetMap()->GetPlayers();
                if (m_creature->GetMap()->IsDungeon() && !players.isEmpty())
                {
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    {
                        Player* pPlayer = itr->getSource();
                        if (pPlayer && !pPlayer->isGameMaster() && m_creature->IsInRange(pPlayer,5.0f,30.0f,false))
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
        if (pInstance)
            pInstance->SetData(BOSS_GRAND_CHAMPIONS, DONE);
    }
};

CreatureAI* GetAI_boss_hunter_toc5(Creature* pCreature)
{
    return new boss_hunter_toc5AI(pCreature);
}

// Lana Stouthammer Evensong && Deathstalker Visceri || Rouge
struct boss_rouge_toc5AI : public ScriptedAI
{
    boss_rouge_toc5AI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pInstance = pCreature->GetInstanceData();

        bDone = false;
        bHome = false;

        uiPhase = 0;
        uiPhaseTimer = 0;

        m_creature->SetReactState(REACT_PASSIVE);
        // THIS IS A HACK, SHOULD BE REMOVED WHEN THE EVENT IS FULL SCRIPTED
        m_creature->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE);
    }

    ScriptedInstance* pInstance;

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
        if (!bDone && GrandChampionsOutVehicle(m_creature))
        {
            bDone = true;

            if (m_creature->GetGUID() == pInstance->GetData64(DATA_GRAND_CHAMPION_1))
                m_creature->SetHomePosition(739.678,662.541,412.393,4.49);
            else if (m_creature->GetGUID() == pInstance->GetData64(DATA_GRAND_CHAMPION_2))
                m_creature->SetHomePosition(746.71,661.02,411.69,4.6);
            else if (m_creature->GetGUID() == pInstance->GetData64(DATA_GRAND_CHAMPION_3))
                m_creature->SetHomePosition(754.34,660.70,412.39,4.79);

            if (pInstance)
                pInstance->SetData(BOSS_GRAND_CHAMPIONS, IN_PROGRESS);

            EnterEvadeMode();
            bHome = true;
        }

        if (uiPhaseTimer <= uiDiff)
        {
            if (uiPhase == 1)
            {
                AggroAllPlayers(m_creature);
                uiPhase = 0;
            }
        } else uiPhaseTimer -= uiDiff;

        if (!UpdateVictim() || m_creature->HasUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT))
            return;

        if (uiEviscerateTimer <= uiDiff)
        {
            DoCast(m_creature->getVictim(),DUNGEON_MODE(SPELL_EVISCERATE,SPELL_EVISCERATE_H));
            uiEviscerateTimer = 8000;
        } else uiEviscerateTimer -= uiDiff;

        if (uiFanKivesTimer <= uiDiff)
        {
            DoCastAOE(SPELL_FAN_OF_KNIVES,false);
            uiFanKivesTimer = 14000;
        } else uiFanKivesTimer -= uiDiff;

        if (uiPosionBottleTimer <= uiDiff)
        {
            if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM,0))
                DoCast(pTarget,SPELL_POISON_BOTTLE);
            uiPosionBottleTimer = 19000;
        } else uiPosionBottleTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* pKiller)
    {
        if (pInstance)
            pInstance->SetData(BOSS_GRAND_CHAMPIONS, DONE);
    }
};

CreatureAI* GetAI_boss_rouge_toc5(Creature* pCreature)
{
    return new boss_rouge_toc5AI(pCreature);
}

void AddSC_boss_grand_champions()
{
    Script* NewScript;

    NewScript = new Script;
    NewScript->Name = "generic_vehicleAI_toc5";
    NewScript->GetAI = &GetAI_generic_vehicleAI_toc5;
    NewScript->RegisterSelf();

    NewScript = new Script;
    NewScript->Name = "boss_warrior_toc5";
    NewScript->GetAI = &GetAI_boss_warrior_toc5;
    NewScript->RegisterSelf();

    NewScript = new Script;
    NewScript->Name = "boss_mage_toc5";
    NewScript->GetAI = &GetAI_boss_mage_toc5;
    NewScript->RegisterSelf();

    NewScript = new Script;
    NewScript->Name = "boss_shaman_toc5";
    NewScript->GetAI = &GetAI_boss_shaman_toc5;
    NewScript->RegisterSelf();

    NewScript = new Script;
    NewScript->Name = "boss_hunter_toc5";
    NewScript->GetAI = &GetAI_boss_hunter_toc5;
    NewScript->RegisterSelf();

    NewScript = new Script;
    NewScript->Name = "boss_rouge_toc5";
    NewScript->GetAI = &GetAI_boss_rouge_toc5;
    NewScript->RegisterSelf();
}
