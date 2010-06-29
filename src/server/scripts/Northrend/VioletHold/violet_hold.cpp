/*
 * Copyright (C) 2009 - 2010 Trinity <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"
#include "violet_hold.h"

#define GOSSIP_START_EVENT  "Get your people to safety, we'll keep the Blue Dragonflight's forces at bay."
#define GOSSIP_ITEM_1       "Activate the crystals when we get in trouble, right"
#define SPAWN_TIME          20000

enum PortalCreatures
{
    CREATURE_AZURE_INVADER_1          = 30661,
    CREATURE_AZURE_INVADER_2          = 30961,
    CREATURE_AZURE_SPELLBREAKER_1     = 30662,
    CREATURE_AZURE_SPELLBREAKER_2     = 30962,
    CREATURE_AZURE_BINDER_1           = 30663,
    CREATURE_AZURE_BINDER_2           = 30918,
    CREATURE_AZURE_MAGE_SLAYER_1      = 30664,
    CREATURE_AZURE_MAGE_SLAYER_2      = 30963,
    CREATURE_AZURE_CAPTAIN            = 30666,
    CREATURE_AZURE_SORCEROR           = 30667,
    CREATURE_AZURE_RAIDER             = 30668,
    CREATURE_AZURE_STALKER            = 32191
};

enum AzureInvaderSpells
{
    SPELL_CLEAVE                = 15496,
    SPELL_IMPALE                = 58459,
    H_SPELL_IMPALE              = 59256,
    SPELL_BRUTAL_STRIKE         = 58460,
    SPELL_SUNDER_ARMOR          = 58461
};

enum AzureSellbreakerSpells
{
    SPELL_ARCANE_BLAST          = 58462,
    H_SPELL_ARCANE_BLAST        = 59257,
    SPELL_SLOW                  = 25603,
    SPELL_CHAINS_OF_ICE         = 58464,
    SPELL_CONE_OF_COLD          = 58463,
    H_SPELL_CONE_OF_COLD        = 59258
};

enum AzureBinderSpells
{
    SPELL_ARCANE_BARRAGE        = 58456,
    H_SPELL_ARCANE_BARRAGE      = 59248,
    SPELL_ARCANE_EXPLOSION      = 58455,
    H_SPELL_ARCANE_EXPLOSION    = 59245,
    SPELL_FROST_NOVA            = 58458,
    H_SPELL_FROST_NOVA          = 59253,
    SPELL_FROSTBOLT             = 58457,
    H_SPELL_FROSTBOLT           = 59251,
};

enum AzureMageSlayerSpells
{
    SPELL_ARCANE_EMPOWERMENT    = 58469,
    SPELL_SPELL_LOCK            = 30849
};

enum AzureCaptainSpells
{
    SPELL_MORTAL_STRIKE         = 32736,
    SPELL_WHIRLWIND_OF_STEEL    = 41057
};

enum AzureSorcerorSpells
{
    SPELL_ARCANE_STREAM         = 60181,
    H_SPELL_ARCANE_STREAM       = 60204,
    SPELL_MANA_DETONATION       = 60182,
    H_SPELL_MANA_DETONATION     = 60205
};

enum AzureRaiderSpells
{
    SPELL_CONCUSSION_BLOW       = 52719,
    SPELL_MAGIC_REFLECTION      = 60158
};

enum AzureStalkerSpells
{
    SPELL_BACKSTAB              = 58471,
    SPELL_TACTICAL_BLINK        = 58470
};

enum AzureSaboteurSpells
{
    SABOTEUR_SHIELD_DISRUPTION        = 58291,
    SABOTEUR_SHIELD_EFFECT            = 45775
};

enum TrashDoorSpell
{
    SPELL_DESTROY_DOOR_SEAL     = 58040
};

enum Spells
{
    SPELL_PORTAL_CHANNEL              = 58012,
    SPELL_CRYSTALL_ACTIVATION         = 57804
};

enum eSinclari
{
    SAY_SINCLARI_1                    = -1608045
};

float FirstPortalWPs [6][3] =
{
    {1877.670288, 842.280273, 43.333591},
    {1877.338867, 834.615356, 38.762287},
    {1872.161011, 823.854309, 38.645401},
    {1864.860474, 815.787170, 38.784843},
    {1858.953735, 810.048950, 44.008759},
    {1843.707153, 805.807739, 44.135197}
    //{1825.736084, 807.305847, 44.363785}
};

float SecondPortalFirstWPs [9][3] =
{
    {1902.561401, 853.334656, 47.106117},
    {1895.486084, 855.376404, 44.334591},
    {1882.805176, 854.993286, 43.333591},
    {1877.670288, 842.280273, 43.333591},
    {1877.338867, 834.615356, 38.762287},
    {1872.161011, 823.854309, 38.645401},
    {1864.860474, 815.787170, 38.784843},
    {1858.953735, 810.048950, 44.008759},
    {1843.707153, 805.807739, 44.135197}
    //{1825.736084, 807.305847, 44.363785}
};

float SecondPortalSecondWPs [8][3] =
{
    {1929.392212, 837.614990, 47.136166},
    {1928.290649, 824.750427, 45.474411},
    {1915.544922, 826.919373, 38.642811},
    {1900.933960, 818.855652, 38.801647},
    {1886.810547, 813.536621, 38.490490},
    {1869.079712, 808.701538, 38.689003},
    {1860.843384, 806.645020, 44.008789},
    {1843.707153, 805.807739, 44.135197}
    //{1825.736084, 807.305847, 44.363785}
};

float ThirdPortalWPs [8][3] =
{
    {1934.049438, 815.778503, 52.408699},
    {1928.290649, 824.750427, 45.474411},
    {1915.544922, 826.919373, 38.642811},
    {1900.933960, 818.855652, 38.801647},
    {1886.810547, 813.536621, 38.490490},
    {1869.079712, 808.701538, 38.689003},
    {1860.843384, 806.645020, 44.008789},
    {1843.707153, 805.807739, 44.135197}
    //{1825.736084, 807.305847, 44.363785}
};

float FourthPortalWPs [9][3] =
{
    {1921.658447, 761.657043, 50.866741},
    {1910.559814, 755.780457, 47.701447},
    {1896.664673, 752.920898, 47.667004},
    {1887.398804, 763.633240, 47.666851},
    {1879.020386, 775.396973, 38.705990},
    {1872.439087, 782.568604, 38.808292},
    {1863.573364, 791.173584, 38.743660},
    {1857.811890, 796.765564, 43.950329},
    {1845.577759, 800.681152, 44.104248}
    //{1827.100342, 801.605957, 44.363358}
};

float FifthPortalWPs [6][3] =
{
    {1887.398804, 763.633240, 47.666851},
    {1879.020386, 775.396973, 38.705990},
    {1872.439087, 782.568604, 38.808292},
    {1863.573364, 791.173584, 38.743660},
    {1857.811890, 796.765564, 43.950329},
    {1845.577759, 800.681152, 44.104248}
    //{1827.100342, 801.605957, 44.363358}
};

float SixthPoralWPs [4][3] =
{
    {1888.861084, 805.074768, 38.375790},
    {1869.793823, 804.135804, 38.647018},
    {1861.541504, 804.149780, 43.968292},
    {1843.567017, 804.288208, 44.139091}
    //{1826.889648, 803.929993, 44.363239}
};

const float SaboteurFinalPos1[3][3] =
{
    {1892.502319, 777.410767, 38.630402},
    {1891.165161, 762.969421, 47.666920},
    {1893.168091, 740.919189, 47.666920}
};
const float SaboteurFinalPos2[3][3] =
{
    {1882.242676, 834.818726, 38.646786},
    {1879.220825, 842.224854, 43.333641},
    {1873.842896, 863.892456, 43.333641}
};
const float SaboteurFinalPos3[2][3] =
{
    {1904.298340, 792.400391, 38.646782},
    {1935.716919, 758.437073, 30.627895}
};
const float SaboteurFinalPos4[3] =
{
    1855.006104, 760.641724, 38.655266
};
const float SaboteurFinalPos5[3] =
{
    1906.667358, 841.705566, 38.637894
};
const float SaboteurFinalPos6[5][3] =
{
    {1911.437012, 821.289246, 38.684128},
    {1920.734009, 822.978027, 41.525414},
    {1928.262939, 830.836609, 44.668266},
    {1929.338989, 837.593933, 47.137596},
    {1931.063354, 848.468445, 47.190434}
 };

const Position MovePosition = { 1806.955566, 803.851807, 44.363323};

struct npc_sinclariAI : public ScriptedAI
{
    npc_sinclariAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
       pInstance = pCreature->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    uint8  uiPhase;
    uint32 uiTimer;

    void Reset()
    {
        uiPhase = 0;
        uiTimer = 0;

        me->SetVisibility(VISIBILITY_ON);
        me->SetReactState(REACT_AGGRESSIVE);

        std::list<Creature*> GuardList;
        me->GetCreatureListWithEntryInGrid(GuardList, NPC_VIOLET_HOLD_GUARD, 40.0f);
        if (!GuardList.empty())
        {
            for (std::list<Creature*>::const_iterator itr = GuardList.begin(); itr != GuardList.end(); ++itr)
            {
                if (Creature* pGuard = *itr)
                {
                    pGuard->DisappearAndDie();
                    pGuard->Respawn();
                    pGuard->SetVisibility(VISIBILITY_ON);
                    pGuard->SetReactState(REACT_AGGRESSIVE);
                }
            }
        }
    }

    void UpdateAI(const uint32 uiDiff)
    {
        ScriptedAI::UpdateAI(uiDiff);

        if (uiPhase)
        {
            if (uiTimer <= uiDiff)
            {
                switch(uiPhase)
                {
                    case 1:
                        me->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NOT_SELECTABLE);
                        DoScriptText(SAY_SINCLARI_1, me);
                        uiTimer = 4000;
                        uiPhase = 2;
                        break;
                    case 2:
                    {
                        std::list<Creature*> GuardList;
                        me->GetCreatureListWithEntryInGrid(GuardList, NPC_VIOLET_HOLD_GUARD, 40.0f);
                        if (!GuardList.empty())
                            for (std::list<Creature*>::const_iterator itr = GuardList.begin(); itr != GuardList.end(); ++itr)
                            {
                                if (Creature* pGuard = *itr)
                                {
                                    pGuard->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                                    pGuard->GetMotionMaster()->MovePoint(0, MovePosition);
                                }
                            }
                        uiTimer = 6000;
                        uiPhase = 3;
                        break;
                    }
                    case 3:
                    {
                        std::list<Creature*> GuardList;
                        me->GetCreatureListWithEntryInGrid(GuardList, NPC_VIOLET_HOLD_GUARD, 40.0f);
                        if (!GuardList.empty())
                            for (std::list<Creature*>::const_iterator itr = GuardList.begin(); itr != GuardList.end(); ++itr)
                            {
                                if (Creature* pGuard = *itr)
                                {
                                    pGuard->SetVisibility(VISIBILITY_OFF);
                                    pGuard->SetReactState(REACT_PASSIVE);
                                }
                            }
                        uiTimer = 2000;
                        uiPhase = 4;
                        break;
                    }
                    case 4:
                        me->GetMotionMaster()->MovePoint(0, MovePosition);
                        uiTimer = 4000;
                        uiPhase = 5;
                        break;
                    case 5:
                        if (pInstance)
                            pInstance->SetData(DATA_MAIN_EVENT_PHASE,IN_PROGRESS);
                        me->SetVisibility(VISIBILITY_OFF);
                        me->SetReactState(REACT_PASSIVE);
                        uiTimer = 0;
                        uiPhase = 0;
                        break;
                }
            }
            else uiTimer -= uiDiff;
        }

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_sinclari(Creature* pCreature)
{
    return new npc_sinclariAI(pCreature);
}

struct mob_azure_saboteurAI : public npc_escortAI
{
    mob_azure_saboteurAI(Creature *c):npc_escortAI(c)
    {
        pInstance           = c->GetInstanceData();
        bHasGotMovingPoints = false;
        uiBoss = 0;
        Reset();
    }

    ScriptedInstance* pInstance;
    bool bHasGotMovingPoints;
    uint32 uiBoss;

    void Reset()
    {
        if (pInstance && !uiBoss)
            uiBoss = pInstance->GetData(DATA_WAVE_COUNT) == 6 ? pInstance->GetData(DATA_FIRST_BOSS) : pInstance->GetData(DATA_SECOND_BOSS);
    }

    void WaypointReached(uint32 uiWPointId)
    {
        switch(uiBoss)
        {
            case 1:
                if(uiWPointId == 2)
                    FinishPointReached();
                break;
            case 2:
                if(uiWPointId == 2)
                    FinishPointReached();
                break;
            case 3:
                if(uiWPointId == 1)
                    FinishPointReached();
                break;
            case 4:
                if(uiWPointId == 0)
                    FinishPointReached();
                break;
            case 5:
                if(uiWPointId == 0)
                    FinishPointReached();
                break;
            case 6:
                if(uiWPointId == 4)
                    FinishPointReached();
                break;
        }
    }
    
    void UpdateAI(const uint32 diff)
    {
        if (pInstance && pInstance->GetData(DATA_MAIN_EVENT_PHASE != IN_PROGRESS))
            me->CastStop();
        
        npc_escortAI::UpdateAI(diff);

        if(!bHasGotMovingPoints)
        {
            bHasGotMovingPoints = true;
            switch(uiBoss)
            {
                case 1:
                    for(int i=0;i<3;i++)
                        AddWaypoint(i,SaboteurFinalPos1[i][0],SaboteurFinalPos1[i][1],SaboteurFinalPos1[i][2],0);
                    me->SetHomePosition(SaboteurFinalPos1[2][0],SaboteurFinalPos1[2][1],SaboteurFinalPos1[2][2],4.762346);
                    break;
                case 2:
                    for(int i=0;i<3;i++)
                        AddWaypoint(i,SaboteurFinalPos2[i][0],SaboteurFinalPos2[i][1],SaboteurFinalPos2[i][2],0);
                    me->SetHomePosition(SaboteurFinalPos2[2][0],SaboteurFinalPos2[2][1],SaboteurFinalPos2[2][2],1.862674);
                    break;
                case 3:
                    for(int i=0;i<2;i++)
                        AddWaypoint(i,SaboteurFinalPos3[i][0],SaboteurFinalPos3[i][1],SaboteurFinalPos3[i][2],0);
                    me->SetHomePosition(SaboteurFinalPos3[1][0],SaboteurFinalPos3[1][1],SaboteurFinalPos3[1][2],5.500638);
                    break;
                case 4:
                    AddWaypoint(0,SaboteurFinalPos4[0],SaboteurFinalPos4[1],SaboteurFinalPos4[2],0);
                    me->SetHomePosition(SaboteurFinalPos4[0],SaboteurFinalPos4[1],SaboteurFinalPos4[2],3.991108);
                    break;
                case 5:
                    AddWaypoint(0,SaboteurFinalPos5[0],SaboteurFinalPos5[1],SaboteurFinalPos5[2],0);
                    me->SetHomePosition(SaboteurFinalPos5[0],SaboteurFinalPos5[1],SaboteurFinalPos5[2],1.100841);
                    break;
                case 6:
                    for(int i=0;i<5;i++)
                        AddWaypoint(i,SaboteurFinalPos6[i][0],SaboteurFinalPos6[i][1],SaboteurFinalPos6[i][2],0);
                    me->SetHomePosition(SaboteurFinalPos6[4][0],SaboteurFinalPos6[4][1],SaboteurFinalPos6[4][2],0.983031);
                    break;
            }

            SetDespawnAtEnd(false);
            Start(true,true);
        }
    }

    void FinishPointReached()
    {
        me->CastSpell(me, SABOTEUR_SHIELD_DISRUPTION, false);
        me->DisappearAndDie();
        Creature* pSaboPort = Unit::GetCreature((*me),pInstance->GetData64(DATA_SABOTEUR_PORTAL));
        if (pSaboPort)
            pSaboPort->DisappearAndDie();
        pInstance->SetData(DATA_START_BOSS_ENCOUNTER, 1);
    }
};

CreatureAI* GetAI_mob_azure_saboteur(Creature* pCreature)
{
    return new mob_azure_saboteurAI (pCreature);
}

bool GossipHello_npc_sinclari(Player* pPlayer, Creature* pCreature)
{
    if (ScriptedInstance* pInstance = pCreature->GetInstanceData())
    {
        uint8 uiInstancePhase = pInstance->GetData(DATA_MAIN_EVENT_PHASE);
        if (uiInstancePhase == NOT_STARTED || uiInstancePhase == FAIL) // Allow to start event if not started or wiped
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,GOSSIP_ITEM_1,GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+2);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,GOSSIP_START_EVENT,GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+1);
            pPlayer->SEND_GOSSIP_MENU(13853, pCreature->GetGUID());
        } else
            pPlayer->SEND_GOSSIP_MENU(13910, pCreature->GetGUID());
    }
    return true;
}

bool GossipSelect_npc_sinclari(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            if (pPlayer)
                pPlayer->CLOSE_GOSSIP_MENU();
            CAST_AI(npc_sinclariAI, (pCreature->AI()))->uiPhase = 1;
            if (ScriptedInstance *pInstance = pCreature->GetInstanceData())
                pInstance->SetData(DATA_MAIN_EVENT_PHASE,SPECIAL);
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            pPlayer->SEND_GOSSIP_MENU(13854, pCreature->GetGUID());
            break;
    }
    return true;
}

struct npc_teleportation_portalAI : public ScriptedAI
{
    npc_teleportation_portalAI(Creature *c) : ScriptedAI(c), listOfMobs(me)
    {
        pInstance = c->GetInstanceData();
        uiTypeOfMobsPortal = urand(0,1);    // 0 - elite mobs   1 - portal guardian or portal keeper with regular mobs
        bPortalGuardianOrKeeperOrEliteSpawn = false;
    }

    uint32 uiSpawnTimer;
    bool bPortalGuardianOrKeeperOrEliteSpawn;
    uint8 uiTypeOfMobsPortal;
    
    SummonList listOfMobs;

    ScriptedInstance *pInstance;

    void Reset()
    {
        uiSpawnTimer = 10000;
        bPortalGuardianOrKeeperOrEliteSpawn = false;
    }

    void EnterCombat(Unit * /*who*/) {}
    
    void MoveInLineOfSight(Unit * /*who*/) {}

    void UpdateAI(const uint32 diff)
    {
        if (!pInstance) //Massive usage of pInstance, global check
            return;
        
        if (pInstance->GetData(DATA_REMOVE_NPC) == 1)
        {
            me->ForcedDespawn();
            pInstance->SetData(DATA_REMOVE_NPC, 0);
        }

        uint8 uiWaveCount = pInstance->GetData(DATA_WAVE_COUNT);
        if ((uiWaveCount == 6) || (uiWaveCount == 12)) //Don't spawn mobs on boss encounters
            return;

        switch(uiTypeOfMobsPortal)
        {
            // spawn elite mobs and then set portals visibility to make it look like it dissapeard
            case 0:
                if (!bPortalGuardianOrKeeperOrEliteSpawn)
                {
                    if (uiSpawnTimer <= diff)
                    {
                        bPortalGuardianOrKeeperOrEliteSpawn = true;
                        uint8 k = uiWaveCount < 12 ? 2 : 3;
                        for (uint8 i = 0; i < k; ++i)
                        {
                            uint32 entry = RAND(CREATURE_AZURE_CAPTAIN,CREATURE_AZURE_RAIDER,CREATURE_AZURE_STALKER,CREATURE_AZURE_SORCEROR);
                            DoSummon(entry, me, 2.0f, 20000, TEMPSUMMON_DEAD_DESPAWN);
                        }
                        me->SetVisibility(VISIBILITY_OFF);
                    } else uiSpawnTimer -= diff;
                }
                else
                {
                    // if all spawned elites have died kill portal
                    if (listOfMobs.empty())
                    {
                        me->Kill(me, false);
                        me->RemoveCorpse();
                    }
                }
                break;
            // spawn portal guardian or portal keeper with regular mobs
            case 1:
                if (uiSpawnTimer <= diff)
                {
                    if (bPortalGuardianOrKeeperOrEliteSpawn)
                    {
                        uint8 k = pInstance->GetData(DATA_WAVE_COUNT) < 12 ? 3 : 4;
                        for (uint8 i = 0; i < k; ++i)
                        {
                            uint32 entry = RAND(CREATURE_AZURE_INVADER_1,CREATURE_AZURE_INVADER_2,CREATURE_AZURE_SPELLBREAKER_1,CREATURE_AZURE_SPELLBREAKER_2,CREATURE_AZURE_MAGE_SLAYER_1,CREATURE_AZURE_MAGE_SLAYER_2,CREATURE_AZURE_BINDER_1,CREATURE_AZURE_BINDER_2);
                            DoSummon(entry, me, 2.0f, 20000, TEMPSUMMON_DEAD_DESPAWN);
                        }
                    }
                    else
                    {
                        bPortalGuardianOrKeeperOrEliteSpawn = true;
                        uint32 entry = RAND(CREATURE_PORTAL_GUARDIAN, CREATURE_PORTAL_KEEPER);
                        if (Creature *pPortalKeeper = DoSummon(entry, me, 2.0f, 0, TEMPSUMMON_DEAD_DESPAWN))
                            me->CastSpell(pPortalKeeper, SPELL_PORTAL_CHANNEL, false);
                    }
                    uiSpawnTimer = SPAWN_TIME;
                } else uiSpawnTimer -= diff;

                if (bPortalGuardianOrKeeperOrEliteSpawn && !me->IsNonMeleeSpellCasted(false))
                {
                    me->Kill(me, false);
                    me->RemoveCorpse();
                }
                break;
        }
    }

    void JustDied(Unit* /*killer*/)
    {
        if (pInstance)
            pInstance->SetData(DATA_WAVE_COUNT,pInstance->GetData(DATA_WAVE_COUNT)+1);
    }

    void JustSummoned(Creature *pSummoned)
    {
        listOfMobs.Summon(pSummoned);
        if (pSummoned)
            pInstance->SetData64(DATA_ADD_TRASH_MOB,pSummoned->GetGUID());
    }

    void SummonedMobDied(Creature *pSummoned)
    {
        listOfMobs.Despawn(pSummoned);
        if (pSummoned)
            pInstance->SetData64(DATA_DEL_TRASH_MOB,pSummoned->GetGUID());
    }
};

CreatureAI* GetAI_npc_teleportation_portal(Creature *pCreature)
{
    return new npc_teleportation_portalAI(pCreature);
}

struct violet_hold_trashAI : public npc_escortAI
{
    violet_hold_trashAI(Creature *c):npc_escortAI(c)
    {
        pInstance = c->GetInstanceData();
        bHasGotMovingPoints = false;
        if (pInstance)
            portalLocationID = pInstance->GetData(DATA_PORTAL_LOCATION);
        Reset();
    }

    public:
        ScriptedInstance* pInstance;
        bool bHasGotMovingPoints;
        uint32 portalLocationID;
        uint32 secondPortalRouteID;

    void WaypointReached(uint32 uiPointId)
    {
        switch(portalLocationID)
        {
            case 0:
                if (uiPointId == 5)
                   CreatureStartAttackDoor(me->GetGUID());
                break;
            case 1:
                if ((uiPointId == 8 && secondPortalRouteID == 0) || (uiPointId == 7 && secondPortalRouteID == 1))
                    CreatureStartAttackDoor(me->GetGUID());
                break;
            case 2:
                if (uiPointId == 7)
                   CreatureStartAttackDoor(me->GetGUID());
                break;
            case 3:
                if (uiPointId == 8)
                    CreatureStartAttackDoor(me->GetGUID());
                break;
            case 4:
                if (uiPointId == 5)
                    CreatureStartAttackDoor(me->GetGUID());
                break;
            case 5:
                if (uiPointId == 3)
                    CreatureStartAttackDoor(me->GetGUID());
                break;
        }
    }

    void UpdateAI(const uint32)
    {
        if (pInstance && pInstance->GetData(DATA_MAIN_EVENT_PHASE != IN_PROGRESS))
                me->CastStop();

        if (!bHasGotMovingPoints)
        {
            bHasGotMovingPoints = true;
                switch(portalLocationID)
            {
                case 0:
                    for(int i=0;i<6;i++)
                        AddWaypoint(i,FirstPortalWPs[i][0]+irand(-1,1),FirstPortalWPs[i][1]+irand(-1,1),FirstPortalWPs[i][2]+irand(-1,1),0);
                    me->SetHomePosition(FirstPortalWPs[5][0],FirstPortalWPs[5][1],FirstPortalWPs[5][2],3.149439);
                    break;
                case 1:
                    secondPortalRouteID = urand(0,1);
                    switch(secondPortalRouteID)
                    {
                        case 0:
                            for(int i=0;i<9;i++)
                                AddWaypoint(i,SecondPortalFirstWPs[i][0]+irand(-1,1),SecondPortalFirstWPs[i][1]+irand(-1,1),SecondPortalFirstWPs[i][2],0);
                            me->SetHomePosition(SecondPortalFirstWPs[8][0]+irand(-1,1),SecondPortalFirstWPs[8][1]+irand(-1,1),SecondPortalFirstWPs[8][2]+irand(-1,1),3.149439);
                            break;
                        case 1:
                            for(int i=0;i<8;i++)
                                AddWaypoint(i,SecondPortalSecondWPs[i][0]+irand(-1,1),SecondPortalSecondWPs[i][1]+irand(-1,1),SecondPortalSecondWPs[i][2],0);
                            me->SetHomePosition(SecondPortalSecondWPs[7][0],SecondPortalSecondWPs[7][1],SecondPortalSecondWPs[7][2],3.149439);
                            break;
                    }
                    break;
                case 2:
                    for(int i=0;i<8;i++)
                        AddWaypoint(i,ThirdPortalWPs[i][0]+irand(-1,1),ThirdPortalWPs[i][1]+irand(-1,1),ThirdPortalWPs[i][2],0);
                        me->SetHomePosition(ThirdPortalWPs[7][0],ThirdPortalWPs[7][1],ThirdPortalWPs[7][2],3.149439);
                    break;
                case 3:
                    for(int i=0;i<9;i++)
                        AddWaypoint(i,FourthPortalWPs[i][0]+irand(-1,1),FourthPortalWPs[i][1]+irand(-1,1),FourthPortalWPs[i][2],0);
                    me->SetHomePosition(FourthPortalWPs[8][0],FourthPortalWPs[8][1],FourthPortalWPs[8][2],3.149439);
                    break;
                case 4:
                    for(int i=0;i<6;i++)
                        AddWaypoint(i,FifthPortalWPs[i][0]+irand(-1,1),FifthPortalWPs[i][1]+irand(-1,1),FifthPortalWPs[i][2],0);
                    me->SetHomePosition(FifthPortalWPs[5][0],FifthPortalWPs[5][1],FifthPortalWPs[5][2],3.149439);
                    break;
                case 5:
                    for(int i=0;i<4;i++)
                        AddWaypoint(i,SixthPoralWPs[i][0]+irand(-1,1),SixthPoralWPs[i][1]+irand(-1,1),SixthPoralWPs[i][2],0);
                    me->SetHomePosition(SixthPoralWPs[3][0],SixthPoralWPs[3][1],SixthPoralWPs[3][2],3.149439);
                    break;
            }
            SetDespawnAtEnd(false);
            Start(true,true);
        }
    }

    void JustDied(Unit *unit)
    {
        if (Creature* portal = Unit::GetCreature((*me),pInstance->GetData64(DATA_TELEPORTATION_PORTAL)))
            CAST_AI(npc_teleportation_portalAI,portal->AI())->SummonedMobDied(me);
        if (pInstance)
            pInstance->SetData(DATA_NPC_PRESENCE_AT_DOOR_REMOVE,1);
    }

    void CreatureStartAttackDoor(uint32 creature_guid)
    {
        me->SetReactState(REACT_PASSIVE);
        DoCast(SPELL_DESTROY_DOOR_SEAL);
        if (pInstance)
            pInstance->SetData(DATA_NPC_PRESENCE_AT_DOOR_ADD,1);
    }

};

struct mob_azure_invaderAI : public violet_hold_trashAI
{
    mob_azure_invaderAI(Creature *c) : violet_hold_trashAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiCleaveTimer;
    uint32 uiImpaleTimer;
    uint32 uiBrutalStrikeTimer;
    uint32 uiSunderArmorTimer;

    void Reset()
    {
        uiCleaveTimer = 5000;
        uiImpaleTimer = 4000;
        uiBrutalStrikeTimer = 5000;
        uiSunderArmorTimer = 4000;
    }

    void UpdateAI(const uint32 diff)
    {
        violet_hold_trashAI::UpdateAI(diff);
        npc_escortAI::UpdateAI(diff);

        if (!UpdateVictim())
            return;

        if (me->GetEntry() == CREATURE_AZURE_INVADER_1)
        {
            if (uiCleaveTimer <= diff)
            {
                DoCast(me->getVictim(),SPELL_CLEAVE);
                uiCleaveTimer = 5000;
            } else uiCleaveTimer -= diff;

            if (uiImpaleTimer <= diff)
            {
                Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);
                if (pTarget)
                    DoCast(pTarget,SPELL_IMPALE);
                uiImpaleTimer = 4000;
            } else uiImpaleTimer -= diff;
        }

        if (me->GetEntry() == CREATURE_AZURE_INVADER_2)
        {
            if (uiBrutalStrikeTimer <= diff)
            {
                DoCast(me->getVictim(),SPELL_BRUTAL_STRIKE);
                uiBrutalStrikeTimer = 5000;
            } else uiBrutalStrikeTimer -= diff;

            if (uiSunderArmorTimer <= diff)
            {
                DoCast(me->getVictim(),SPELL_SUNDER_ARMOR);
                uiSunderArmorTimer = urand(8000,10000);
            } else uiSunderArmorTimer -= diff;

            DoMeleeAttackIfReady();
        }

        DoMeleeAttackIfReady();
    }

};

struct mob_azure_spellbreakerAI : public violet_hold_trashAI
{
    mob_azure_spellbreakerAI(Creature* c) : violet_hold_trashAI(c)
    {
         pInstance = c->GetInstanceData();
    }

    uint32 uiArcaneBlastTimer;
    uint32 uiSlowTimer;
    uint32 uiChainsOfIceTimer;
    uint32 uiConeOfColdTimer;

    void Reset()
    {
        uiArcaneBlastTimer = 5000;
        uiSlowTimer = 4000;
        uiChainsOfIceTimer = 5000;
        uiConeOfColdTimer = 4000;
    }

    void UpdateAI(const uint32 diff)
    {
        violet_hold_trashAI::UpdateAI(diff);
        npc_escortAI::UpdateAI(diff);

        if (!UpdateVictim())
            return;

        if (me->GetEntry() == CREATURE_AZURE_SPELLBREAKER_1)
        {
            if (uiArcaneBlastTimer <= diff)
            {
                Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);
                if (pTarget)
                    DoCast(pTarget,DUNGEON_MODE(SPELL_ARCANE_BLAST,H_SPELL_ARCANE_BLAST));
                uiArcaneBlastTimer = 6000;
            } else uiArcaneBlastTimer -= diff;

            if (uiSlowTimer <= diff)
            {
                Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);
                    if (pTarget)
                    DoCast(pTarget,SPELL_SLOW);
                uiSlowTimer = 5000;
            } else uiSlowTimer -= diff;
        }

        if (me->GetEntry() == CREATURE_AZURE_SPELLBREAKER_2)
        {
            if (uiChainsOfIceTimer <= diff)
            {
                Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);
                if (pTarget)
                    DoCast(pTarget,SPELL_CHAINS_OF_ICE);
                uiChainsOfIceTimer = 7000;
            } else uiChainsOfIceTimer -= diff;

            if (uiConeOfColdTimer <= diff)
            {
               DoCast(DUNGEON_MODE(SPELL_CONE_OF_COLD,H_SPELL_CONE_OF_COLD));
                uiConeOfColdTimer = 5000;
            } else uiConeOfColdTimer -= diff;
        }

        DoMeleeAttackIfReady();
    }
};

struct mob_azure_binderAI : public violet_hold_trashAI
{
    mob_azure_binderAI(Creature *c) : violet_hold_trashAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiArcaneExplosionTimer;
    uint32 uiArcainBarrageTimer;
    uint32 uiFrostNovaTimer;
    uint32 uiFrostboltTimer;

    void Reset()
    {
        uiArcaneExplosionTimer = 5000;
        uiArcainBarrageTimer = 4000;
        uiFrostNovaTimer = 5000;
        uiFrostboltTimer = 4000;
    }

    void UpdateAI(const uint32 diff)
    {
        violet_hold_trashAI::UpdateAI(diff);
        npc_escortAI::UpdateAI(diff);

        if (!UpdateVictim())
            return;

        if (me->GetEntry() == CREATURE_AZURE_BINDER_1)
        {
            if (uiArcaneExplosionTimer <= diff)
            {
                DoCast(DUNGEON_MODE(SPELL_ARCANE_EXPLOSION,H_SPELL_ARCANE_EXPLOSION));
                uiArcaneExplosionTimer = 5000;
            } else uiArcaneExplosionTimer -= diff;

                if (uiArcainBarrageTimer <= diff)
            {
                    Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);
                if (pTarget)
                        DoCast(pTarget,DUNGEON_MODE(SPELL_ARCANE_BARRAGE,H_SPELL_ARCANE_BARRAGE));
                uiArcainBarrageTimer = 6000;
            } else uiArcainBarrageTimer -= diff;
        }

        if (me->GetEntry() == CREATURE_AZURE_BINDER_2)
        {
            if (uiFrostNovaTimer <= diff)
            {
                DoCast(DUNGEON_MODE(SPELL_FROST_NOVA,H_SPELL_FROST_NOVA));
                uiFrostNovaTimer = 5000;
            } else uiFrostNovaTimer -= diff;

            if (uiFrostboltTimer <= diff)
            {
                Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);
                if (pTarget)
                    DoCast(pTarget,DUNGEON_MODE(SPELL_FROSTBOLT,H_SPELL_FROSTBOLT));
                uiFrostboltTimer = 6000;
            } else uiFrostboltTimer -= diff;
        }

        DoMeleeAttackIfReady();
    }
};

struct mob_azure_mage_slayerAI : public violet_hold_trashAI
{
    mob_azure_mage_slayerAI(Creature *c) : violet_hold_trashAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiArcaneEmpowermentTimer;
    uint32 uiSpellLockTimer;

    void Reset()
    {
        uiArcaneEmpowermentTimer = 5000;
        uiSpellLockTimer = 5000;
    }

    void UpdateAI(const uint32 diff)
    {
        violet_hold_trashAI::UpdateAI(diff);
        npc_escortAI::UpdateAI(diff);

        if (!UpdateVictim())
            return;

        if (me->GetEntry() == CREATURE_AZURE_MAGE_SLAYER_1)
        {
            if (uiArcaneEmpowermentTimer <= diff)
            {
                DoCast(me,SPELL_ARCANE_EMPOWERMENT);
                    uiArcaneEmpowermentTimer = 14000;
            } else uiArcaneEmpowermentTimer -= diff;
        }

        if (me->GetEntry() == CREATURE_AZURE_MAGE_SLAYER_2)
        {
            if (uiSpellLockTimer <= diff)
            {
                Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);
                if (pTarget)
                    DoCast(pTarget,SPELL_SPELL_LOCK);
                uiSpellLockTimer = 9000;
            } else uiSpellLockTimer -= diff;
        }

        DoMeleeAttackIfReady();
    }
};

struct  mob_azure_captainAI : public violet_hold_trashAI
{
    mob_azure_captainAI(Creature *c) : violet_hold_trashAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiMortalStrikeTimer;
    uint32 uiWhirlwindTimer;

    void Reset()
    {
        uiMortalStrikeTimer = 5000;
        uiWhirlwindTimer = 8000;
    }

    void UpdateAI(const uint32 diff)
    {
        violet_hold_trashAI::UpdateAI(diff);
        npc_escortAI::UpdateAI(diff);

        if (!UpdateVictim())
            return;

        if (uiMortalStrikeTimer <= diff)
        {
            DoCast(me->getVictim(),SPELL_MORTAL_STRIKE);
            uiMortalStrikeTimer = 5000;
        } else uiMortalStrikeTimer -= diff;

        if (uiWhirlwindTimer <= diff)
        {
            DoCast(me,SPELL_WHIRLWIND_OF_STEEL);
            uiWhirlwindTimer = 8000;
        } else uiWhirlwindTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

struct  mob_azure_sorcerorAI : public violet_hold_trashAI
{
    mob_azure_sorcerorAI(Creature *c) : violet_hold_trashAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiArcaneStreamTimer;
    uint32 uiArcaneStreamTimerStartingValueHolder;
    uint32 uiManaDetonationTimer;

    void Reset()
    {
        uiArcaneStreamTimer = 4000;
        uiArcaneStreamTimerStartingValueHolder = uiArcaneStreamTimer;
        uiManaDetonationTimer = 5000;
    }

    void UpdateAI(const uint32 diff)
    {
        violet_hold_trashAI::UpdateAI(diff);
        npc_escortAI::UpdateAI(diff);

        if (!UpdateVictim())
            return;

        if (uiArcaneStreamTimer <= diff)
        {
            Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);
            if (pTarget)
                DoCast(pTarget,DUNGEON_MODE(SPELL_ARCANE_STREAM,H_SPELL_ARCANE_STREAM));
            uiArcaneStreamTimer = urand(0,5000)+5000;
            uiArcaneStreamTimerStartingValueHolder = uiArcaneStreamTimer;
        } else uiArcaneStreamTimer -= diff;

        if (uiManaDetonationTimer <= diff && uiArcaneStreamTimer >=1500 && uiArcaneStreamTimer <= uiArcaneStreamTimerStartingValueHolder/2)
        {
            DoCast(DUNGEON_MODE(SPELL_MANA_DETONATION,H_SPELL_MANA_DETONATION));
            uiManaDetonationTimer = urand(2000,6000);
        } else uiManaDetonationTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

struct mob_azure_raiderAI : public violet_hold_trashAI
{
    mob_azure_raiderAI(Creature *c) : violet_hold_trashAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiConcussionBlowTimer;
    uint32 uiMagicReflectionTimer;

    void Reset()
    {
        uiConcussionBlowTimer = 5000;
        uiMagicReflectionTimer = 8000;
    }

    void UpdateAI(const uint32 diff)
    {
        violet_hold_trashAI::UpdateAI(diff);
        npc_escortAI::UpdateAI(diff);

        if (!UpdateVictim())
            return;

        if (uiConcussionBlowTimer <= diff)
        {
            DoCast(me->getVictim(),SPELL_CONCUSSION_BLOW);
            uiConcussionBlowTimer = 5000;
        } else uiConcussionBlowTimer -= diff;

        if (uiMagicReflectionTimer <= diff)
        {
            DoCast(SPELL_MAGIC_REFLECTION);
            uiMagicReflectionTimer = urand(10000,15000);
        } else uiMagicReflectionTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

struct mob_azure_stalkerAI : public violet_hold_trashAI
{
    mob_azure_stalkerAI(Creature *c) : violet_hold_trashAI(c)
    {
        pInstance = c->GetInstanceData();
    }
    uint32 uiBackstabTimer;
    uint32 uiTacticalBlinkTimer;
    bool TacticalBlinkCasted;

    void Reset()
    {
        uiBackstabTimer = 1300;
        uiTacticalBlinkTimer = 8000;
        TacticalBlinkCasted =false;
    }

    void UpdateAI(const uint32 diff)
    {
        violet_hold_trashAI::UpdateAI(diff);
        npc_escortAI::UpdateAI(diff);

        if (!UpdateVictim())
            return;

        if (!TacticalBlinkCasted)
        {
            if (uiTacticalBlinkTimer <= diff)
            {
                Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 40, true);
                if (pTarget)
                    DoCast(pTarget,SPELL_TACTICAL_BLINK);
                    uiTacticalBlinkTimer = 6000;
                TacticalBlinkCasted = true;
            } else uiTacticalBlinkTimer -= diff;
        }

        else
        {
            if (uiBackstabTimer <= diff)
            {
                Unit* pTarget = SelectTarget(SELECT_TARGET_NEAREST, 0, 10, true);
                DoCast(pTarget,SPELL_BACKSTAB);
                TacticalBlinkCasted = false;
                uiBackstabTimer =1300;
            } else uiBackstabTimer -= diff;
        }

        DoMeleeAttackIfReady();
    }
};


CreatureAI* GetAI_mob_azure_invader(Creature* pCreature)
{
    return new mob_azure_invaderAI (pCreature);
}

CreatureAI* GetAI_mob_azure_spellbreaker(Creature* pCreature)
{
    return new mob_azure_spellbreakerAI (pCreature);
}

CreatureAI* GetAI_mob_azure_binder(Creature* pCreature)
{
    return new mob_azure_binderAI (pCreature);
}

CreatureAI* GetAI_mob_azure_mage_slayer(Creature* pCreature)
{
    return new mob_azure_mage_slayerAI (pCreature);
}

CreatureAI* GetAI_mob_azure_captain(Creature* pCreature)
{
    return new mob_azure_captainAI (pCreature);
}

CreatureAI* GetAI_mob_azure_sorceror(Creature* pCreature)
{
    return new mob_azure_sorcerorAI (pCreature);
}

CreatureAI* GetAI_mob_azure_raider(Creature* pCreature)
{
    return new mob_azure_raiderAI (pCreature);
}

CreatureAI* GetAI_mob_azure_stalker(Creature* pCreature)
{
    return new mob_azure_stalkerAI (pCreature);
}

void AddSC_violet_hold()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_sinclari_vh";
    newscript->GetAI = &GetAI_npc_sinclari;
    newscript->pGossipHello = &GossipHello_npc_sinclari;
    newscript->pGossipSelect = &GossipSelect_npc_sinclari;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_teleportation_portal_vh";
    newscript->GetAI = &GetAI_npc_teleportation_portal;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_azure_invader";
    newscript->GetAI = &GetAI_mob_azure_invader;
    newscript->RegisterSelf();
    
    newscript = new Script;
    newscript->Name = "mob_azure_spellbreaker";
    newscript->GetAI = &GetAI_mob_azure_invader;
    newscript->RegisterSelf();
    
    newscript = new Script;
    newscript->Name = "mob_azure_binder";
    newscript->GetAI = &GetAI_mob_azure_binder;
    newscript->RegisterSelf();
    
    newscript = new Script;
    newscript->Name = "mob_azure_mage_slayer";
    newscript->GetAI = &GetAI_mob_azure_mage_slayer;
    newscript->RegisterSelf();
    
    newscript = new Script;
    newscript->Name = "mob_azure_captain";
    newscript->GetAI = &GetAI_mob_azure_captain;
    newscript->RegisterSelf();
    
    newscript = new Script;
    newscript->Name = "mob_azure_sorceror";
    newscript->GetAI = &GetAI_mob_azure_sorceror;
    newscript->RegisterSelf();
    
    newscript = new Script;
    newscript->Name = "mob_azure_raider";
    newscript->GetAI = &GetAI_mob_azure_raider;
    newscript->RegisterSelf();
    
    newscript = new Script;
    newscript->Name = "mob_azure_stalker";
    newscript->GetAI = &GetAI_mob_azure_stalker;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_azure_saboteur";
    newscript->GetAI = &GetAI_mob_azure_saboteur;
    newscript->RegisterSelf();
}
