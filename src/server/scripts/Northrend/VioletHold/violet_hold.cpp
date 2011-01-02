/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"
#include "violet_hold.h"

#define GOSSIP_START_EVENT  "Get your people to safety, we'll keep the Blue Dragonflight's forces at bay."
#define GOSSIP_ITEM_1       "Activate the crystals when we get in trouble, right"
#define GOSSIP_I_WANT_IN    "Sorry, I'm late! Can I get in to help my friends?"
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
    {1877.670288f, 842.280273f, 43.333591f},
    {1877.338867f, 834.615356f, 38.762287f},
    {1872.161011f, 823.854309f, 38.645401f},
    {1864.860474f, 815.787170f, 38.784843f},
    {1858.953735f, 810.048950f, 44.008759f},
    {1843.707153f, 805.807739f, 44.135197f}
    //{1825.736084f, 807.305847f, 44.363785f}
};

float SecondPortalFirstWPs [9][3] =
{
    {1902.561401f, 853.334656f, 47.106117f},
    {1895.486084f, 855.376404f, 44.334591f},
    {1882.805176f, 854.993286f, 43.333591f},
    {1877.670288f, 842.280273f, 43.333591f},
    {1877.338867f, 834.615356f, 38.762287f},
    {1872.161011f, 823.854309f, 38.645401f},
    {1864.860474f, 815.787170f, 38.784843f},
    {1858.953735f, 810.048950f, 44.008759f},
    {1843.707153f, 805.807739f, 44.135197f}
    //{1825.736084f, 807.305847f, 44.363785f}
};

float SecondPortalSecondWPs [8][3] =
{
    {1929.392212f, 837.614990f, 47.136166f},
    {1928.290649f, 824.750427f, 45.474411f},
    {1915.544922f, 826.919373f, 38.642811f},
    {1900.933960f, 818.855652f, 38.801647f},
    {1886.810547f, 813.536621f, 38.490490f},
    {1869.079712f, 808.701538f, 38.689003f},
    {1860.843384f, 806.645020f, 44.008789f},
    {1843.707153f, 805.807739f, 44.135197f}
    //{1825.736084f, 807.305847f, 44.363785f}
};

float ThirdPortalWPs [8][3] =
{
    {1934.049438f, 815.778503f, 52.408699f},
    {1928.290649f, 824.750427f, 45.474411f},
    {1915.544922f, 826.919373f, 38.642811f},
    {1900.933960f, 818.855652f, 38.801647f},
    {1886.810547f, 813.536621f, 38.490490f},
    {1869.079712f, 808.701538f, 38.689003f},
    {1860.843384f, 806.645020f, 44.008789f},
    {1843.707153f, 805.807739f, 44.135197f}
    //{1825.736084f, 807.305847f, 44.363785f}
};

float FourthPortalWPs [9][3] =
{
    {1921.658447f, 761.657043f, 50.866741f},
    {1910.559814f, 755.780457f, 47.701447f},
    {1896.664673f, 752.920898f, 47.667004f},
    {1887.398804f, 763.633240f, 47.666851f},
    {1879.020386f, 775.396973f, 38.705990f},
    {1872.439087f, 782.568604f, 38.808292f},
    {1863.573364f, 791.173584f, 38.743660f},
    {1857.811890f, 796.765564f, 43.950329f},
    {1845.577759f, 800.681152f, 44.104248f}
    //{1827.100342f, 801.605957f, 44.363358f}
};

float FifthPortalWPs [6][3] =
{
    {1887.398804f, 763.633240f, 47.666851f},
    {1879.020386f, 775.396973f, 38.705990f},
    {1872.439087f, 782.568604f, 38.808292f},
    {1863.573364f, 791.173584f, 38.743660f},
    {1857.811890f, 796.765564f, 43.950329f},
    {1845.577759f, 800.681152f, 44.104248f}
    //{1827.100342f, 801.605957f, 44.363358f}
};

float SixthPoralWPs [4][3] =
{
    {1888.861084f, 805.074768f, 38.375790f},
    {1869.793823f, 804.135804f, 38.647018f},
    {1861.541504f, 804.149780f, 43.968292f},
    {1843.567017f, 804.288208f, 44.139091f}
    //{1826.889648f, 803.929993f, 44.363239f}
};

const float SaboteurFinalPos1[3][3] =
{
    {1892.502319f, 777.410767f, 38.630402f},
    {1891.165161f, 762.969421f, 47.666920f},
    {1893.168091f, 740.919189f, 47.666920f}
};
const float SaboteurFinalPos2[3][3] =
{
    {1882.242676f, 834.818726f, 38.646786f},
    {1879.220825f, 842.224854f, 43.333641f},
    {1873.842896f, 863.892456f, 43.333641f}
};
const float SaboteurFinalPos3[2][3] =
{
    {1904.298340f, 792.400391f, 38.646782f},
    {1935.716919f, 758.437073f, 30.627895f}
};
const float SaboteurFinalPos4[3] =
{
    1855.006104f, 760.641724f, 38.655266f
};
const float SaboteurFinalPos5[3] =
{
    1906.667358f, 841.705566f, 38.637894f
};
const float SaboteurFinalPos6[5][3] =
{
    {1911.437012f, 821.289246f, 38.684128f},
    {1920.734009f, 822.978027f, 41.525414f},
    {1928.262939f, 830.836609f, 44.668266f},
    {1929.338989f, 837.593933f, 47.137596f},
    {1931.063354f, 848.468445f, 47.190434f}
 };

const Position MovePosition = {1806.955566f, 803.851807f, 44.363323f, 0.0f};
const Position playerTeleportPosition = {1830.531006f, 803.939758f, 44.340508f, 6.281611f};
const Position sinclariOutsidePosition = {1817.315674f, 804.060608f, 44.363998f, 0.0f};

class npc_sinclari_vh : public CreatureScript
{
public:
    npc_sinclari_vh() : CreatureScript("npc_sinclari_vh") { }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        switch(uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                pPlayer->CLOSE_GOSSIP_MENU();
                CAST_AI(npc_sinclari_vh::npc_sinclariAI, (pCreature->AI()))->uiPhase = 1;
                if (InstanceScript *pInstance = pCreature->GetInstanceScript())
                    pInstance->SetData(DATA_MAIN_EVENT_PHASE,SPECIAL);
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                pPlayer->SEND_GOSSIP_MENU(13854, pCreature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+3:
                pPlayer->NearTeleportTo(playerTeleportPosition.GetPositionX(),playerTeleportPosition.GetPositionY(),playerTeleportPosition.GetPositionZ(),playerTeleportPosition.GetOrientation(),true);
                pPlayer->CLOSE_GOSSIP_MENU();
                break;
        }
        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (InstanceScript* pInstance = pCreature->GetInstanceScript())
        {
            switch (pInstance->GetData(DATA_MAIN_EVENT_PHASE))
            {
                case NOT_STARTED:
                case FAIL: // Allow to start event if not started or wiped
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,GOSSIP_ITEM_1,GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+2);
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,GOSSIP_START_EVENT,GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+1);
                    pPlayer->SEND_GOSSIP_MENU(13853, pCreature->GetGUID());
                    break;
                case IN_PROGRESS: // Allow to teleport inside if event is in progress
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,GOSSIP_I_WANT_IN,GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+3);
                    pPlayer->SEND_GOSSIP_MENU(13853, pCreature->GetGUID());
                    break;
                default:
                    pPlayer->SEND_GOSSIP_MENU(13910, pCreature->GetGUID());
            }
        }
        return true;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_sinclariAI(pCreature);
    }

    struct npc_sinclariAI : public ScriptedAI
    {
        npc_sinclariAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
           pInstance = pCreature->GetInstanceScript();
        }

        InstanceScript* pInstance;

        uint8  uiPhase;
        uint32 uiTimer;

        void Reset()
        {
            uiPhase = 0;
            uiTimer = 0;

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
                        pGuard->SetVisible(true);
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
                                        pGuard->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
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
                                        pGuard->SetVisible(false);
                                        pGuard->SetReactState(REACT_PASSIVE);
                                    }
                                }
                            uiTimer = 2000;
                            uiPhase = 4;
                            break;
                        }
                        case 4:
                            me->GetMotionMaster()->MovePoint(0, sinclariOutsidePosition);
                            uiTimer = 4000;
                            uiPhase = 5;
                            break;
                        case 5:
                            if (pInstance)
                                pInstance->SetData(DATA_MAIN_EVENT_PHASE,IN_PROGRESS);
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

};




class mob_azure_saboteur : public CreatureScript
{
public:
    mob_azure_saboteur() : CreatureScript("mob_azure_saboteur") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_azure_saboteurAI (pCreature);
    }

    struct mob_azure_saboteurAI : public npc_escortAI
    {
        mob_azure_saboteurAI(Creature *c):npc_escortAI(c)
        {
            pInstance           = c->GetInstanceScript();
            bHasGotMovingPoints = false;
            uiBoss = 0;
            Reset();
        }

        InstanceScript* pInstance;
        bool bHasGotMovingPoints;
        uint32 uiBoss;

        void Reset()
        {
            if (pInstance && !uiBoss)
                uiBoss = pInstance->GetData(DATA_WAVE_COUNT) == 6 ? pInstance->GetData(DATA_FIRST_BOSS) : pInstance->GetData(DATA_SECOND_BOSS);
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE|UNIT_FLAG_NON_ATTACKABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
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
            if (pInstance && pInstance->GetData(DATA_MAIN_EVENT_PHASE) != IN_PROGRESS)
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
                        me->SetHomePosition(SaboteurFinalPos1[2][0],SaboteurFinalPos1[2][1],SaboteurFinalPos1[2][2],4.762346f);
                        break;
                    case 2:
                        for(int i=0;i<3;i++)
                            AddWaypoint(i,SaboteurFinalPos2[i][0],SaboteurFinalPos2[i][1],SaboteurFinalPos2[i][2],0);
                        me->SetHomePosition(SaboteurFinalPos2[2][0],SaboteurFinalPos2[2][1],SaboteurFinalPos2[2][2],1.862674f);
                        break;
                    case 3:
                        for(int i=0;i<2;i++)
                            AddWaypoint(i,SaboteurFinalPos3[i][0],SaboteurFinalPos3[i][1],SaboteurFinalPos3[i][2],0);
                        me->SetHomePosition(SaboteurFinalPos3[1][0],SaboteurFinalPos3[1][1],SaboteurFinalPos3[1][2],5.500638f);
                        break;
                    case 4:
                        AddWaypoint(0,SaboteurFinalPos4[0],SaboteurFinalPos4[1],SaboteurFinalPos4[2],0);
                        me->SetHomePosition(SaboteurFinalPos4[0],SaboteurFinalPos4[1],SaboteurFinalPos4[2],3.991108f);
                        break;
                    case 5:
                        AddWaypoint(0,SaboteurFinalPos5[0],SaboteurFinalPos5[1],SaboteurFinalPos5[2],0);
                        me->SetHomePosition(SaboteurFinalPos5[0],SaboteurFinalPos5[1],SaboteurFinalPos5[2],1.100841f);
                        break;
                    case 6:
                        for(int i=0;i<5;i++)
                            AddWaypoint(i,SaboteurFinalPos6[i][0],SaboteurFinalPos6[i][1],SaboteurFinalPos6[i][2],0);
                        me->SetHomePosition(SaboteurFinalPos6[4][0],SaboteurFinalPos6[4][1],SaboteurFinalPos6[4][2],0.983031f);
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

};


class npc_teleportation_portal_vh : public CreatureScript
{
public:
    npc_teleportation_portal_vh() : CreatureScript("npc_teleportation_portal_vh") { }

    CreatureAI* GetAI(Creature *pCreature) const
    {
        return new npc_teleportation_portalAI(pCreature);
    }

    struct npc_teleportation_portalAI : public ScriptedAI
    {
        npc_teleportation_portalAI(Creature *c) : ScriptedAI(c), listOfMobs(me)
        {
            pInstance = c->GetInstanceScript();
            uiTypeOfMobsPortal = urand(0,1);    // 0 - elite mobs   1 - portal guardian or portal keeper with regular mobs
            bPortalGuardianOrKeeperOrEliteSpawn = false;
        }

        uint32 uiSpawnTimer;
        bool bPortalGuardianOrKeeperOrEliteSpawn;
        uint8 uiTypeOfMobsPortal;

        SummonList listOfMobs;

        InstanceScript *pInstance;

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
                me->DespawnOrUnsummon();
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
                            me->SetVisible(false);
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

};

struct violet_hold_trashAI : public npc_escortAI
{
    violet_hold_trashAI(Creature *c):npc_escortAI(c)
    {
        pInstance = c->GetInstanceScript();
        bHasGotMovingPoints = false;
        if (pInstance)
            portalLocationID = pInstance->GetData(DATA_PORTAL_LOCATION);
        Reset();
    }

    public:
        InstanceScript* pInstance;
        bool bHasGotMovingPoints;
        uint32 portalLocationID;
        uint32 secondPortalRouteID;

    void WaypointReached(uint32 uiPointId)
    {
        switch(portalLocationID)
        {
            case 0:
                if (uiPointId == 5)
                   CreatureStartAttackDoor();
                break;
            case 1:
                if ((uiPointId == 8 && secondPortalRouteID == 0) || (uiPointId == 7 && secondPortalRouteID == 1))
                    CreatureStartAttackDoor();
                break;
            case 2:
                if (uiPointId == 7)
                   CreatureStartAttackDoor();
                break;
            case 3:
                if (uiPointId == 8)
                    CreatureStartAttackDoor();
                break;
            case 4:
                if (uiPointId == 5)
                    CreatureStartAttackDoor();
                break;
            case 5:
                if (uiPointId == 3)
                    CreatureStartAttackDoor();
                break;
        }
    }

    void UpdateAI(const uint32)
    {
        if (pInstance && pInstance->GetData(DATA_MAIN_EVENT_PHASE) != IN_PROGRESS)
            me->CastStop();

        if (!bHasGotMovingPoints)
        {
            bHasGotMovingPoints = true;
                switch(portalLocationID)
            {
                case 0:
                    for(int i=0;i<6;i++)
                        AddWaypoint(i,FirstPortalWPs[i][0]+irand(-1,1),FirstPortalWPs[i][1]+irand(-1,1),FirstPortalWPs[i][2]+irand(-1,1),0);
                    me->SetHomePosition(FirstPortalWPs[5][0],FirstPortalWPs[5][1],FirstPortalWPs[5][2],3.149439f);
                    break;
                case 1:
                    secondPortalRouteID = urand(0,1);
                    switch(secondPortalRouteID)
                    {
                        case 0:
                            for(int i=0;i<9;i++)
                                AddWaypoint(i,SecondPortalFirstWPs[i][0]+irand(-1,1),SecondPortalFirstWPs[i][1]+irand(-1,1),SecondPortalFirstWPs[i][2],0);
                            me->SetHomePosition(SecondPortalFirstWPs[8][0]+irand(-1,1),SecondPortalFirstWPs[8][1]+irand(-1,1),SecondPortalFirstWPs[8][2]+irand(-1,1),3.149439f);
                            break;
                        case 1:
                            for(int i=0;i<8;i++)
                                AddWaypoint(i,SecondPortalSecondWPs[i][0]+irand(-1,1),SecondPortalSecondWPs[i][1]+irand(-1,1),SecondPortalSecondWPs[i][2],0);
                            me->SetHomePosition(SecondPortalSecondWPs[7][0],SecondPortalSecondWPs[7][1],SecondPortalSecondWPs[7][2],3.149439f);
                            break;
                    }
                    break;
                case 2:
                    for(int i=0;i<8;i++)
                        AddWaypoint(i,ThirdPortalWPs[i][0]+irand(-1,1),ThirdPortalWPs[i][1]+irand(-1,1),ThirdPortalWPs[i][2],0);
                        me->SetHomePosition(ThirdPortalWPs[7][0],ThirdPortalWPs[7][1],ThirdPortalWPs[7][2],3.149439f);
                    break;
                case 3:
                    for(int i=0;i<9;i++)
                        AddWaypoint(i,FourthPortalWPs[i][0]+irand(-1,1),FourthPortalWPs[i][1]+irand(-1,1),FourthPortalWPs[i][2],0);
                    me->SetHomePosition(FourthPortalWPs[8][0],FourthPortalWPs[8][1],FourthPortalWPs[8][2],3.149439f);
                    break;
                case 4:
                    for(int i=0;i<6;i++)
                        AddWaypoint(i,FifthPortalWPs[i][0]+irand(-1,1),FifthPortalWPs[i][1]+irand(-1,1),FifthPortalWPs[i][2],0);
                    me->SetHomePosition(FifthPortalWPs[5][0],FifthPortalWPs[5][1],FifthPortalWPs[5][2],3.149439f);
                    break;
                case 5:
                    for(int i=0;i<4;i++)
                        AddWaypoint(i,SixthPoralWPs[i][0]+irand(-1,1),SixthPoralWPs[i][1]+irand(-1,1),SixthPoralWPs[i][2],0);
                    me->SetHomePosition(SixthPoralWPs[3][0],SixthPoralWPs[3][1],SixthPoralWPs[3][2],3.149439f);
                    break;
            }
            SetDespawnAtEnd(false);
            Start(true,true);
        }
    }

    void JustDied(Unit * /*unit*/)
    {
        if (Creature* portal = Unit::GetCreature((*me),pInstance->GetData64(DATA_TELEPORTATION_PORTAL)))
            CAST_AI(npc_teleportation_portal_vh::npc_teleportation_portalAI,portal->AI())->SummonedMobDied(me);
        if (pInstance)
            pInstance->SetData(DATA_NPC_PRESENCE_AT_DOOR_REMOVE,1);
    }

    void CreatureStartAttackDoor()
    {
        me->SetReactState(REACT_PASSIVE);
        DoCast(SPELL_DESTROY_DOOR_SEAL);
        if (pInstance)
            pInstance->SetData(DATA_NPC_PRESENCE_AT_DOOR_ADD,1);
    }

};

class mob_azure_invader : public CreatureScript
{
public:
    mob_azure_invader() : CreatureScript("mob_azure_invader") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_azure_invaderAI (pCreature);
    }

    struct mob_azure_invaderAI : public violet_hold_trashAI
    {
        mob_azure_invaderAI(Creature *c) : violet_hold_trashAI(c)
        {
            pInstance = c->GetInstanceScript();
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

};

class mob_azure_binder : public CreatureScript
{
public:
    mob_azure_binder() : CreatureScript("mob_azure_binder") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_azure_binderAI (pCreature);
    }

    struct mob_azure_binderAI : public violet_hold_trashAI
    {
        mob_azure_binderAI(Creature *c) : violet_hold_trashAI(c)
        {
            pInstance = c->GetInstanceScript();
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

};

class mob_azure_mage_slayer : public CreatureScript
{
public:
    mob_azure_mage_slayer() : CreatureScript("mob_azure_mage_slayer") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_azure_mage_slayerAI (pCreature);
    }

    struct mob_azure_mage_slayerAI : public violet_hold_trashAI
    {
        mob_azure_mage_slayerAI(Creature *c) : violet_hold_trashAI(c)
        {
            pInstance = c->GetInstanceScript();
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

};

class mob_azure_raider : public CreatureScript
{
public:
    mob_azure_raider() : CreatureScript("mob_azure_raider") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_azure_raiderAI (pCreature);
    }

    struct mob_azure_raiderAI : public violet_hold_trashAI
    {
        mob_azure_raiderAI(Creature *c) : violet_hold_trashAI(c)
        {
            pInstance = c->GetInstanceScript();
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

};

class mob_azure_stalker : public CreatureScript
{
public:
    mob_azure_stalker() : CreatureScript("mob_azure_stalker") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_azure_stalkerAI (pCreature);
    }

    struct mob_azure_stalkerAI : public violet_hold_trashAI
    {
        mob_azure_stalkerAI(Creature *c) : violet_hold_trashAI(c)
        {
            pInstance = c->GetInstanceScript();
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

};

class mob_azure_spellbreaker : public CreatureScript
{
public:
    mob_azure_spellbreaker() : CreatureScript("mob_azure_spellbreaker") { }

    struct mob_azure_spellbreakerAI : public violet_hold_trashAI
    {
        mob_azure_spellbreakerAI(Creature* c) : violet_hold_trashAI(c)
        {
             pInstance = c->GetInstanceScript();
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

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_azure_spellbreakerAI (pCreature);
    }
};

class mob_azure_captain : public CreatureScript
{
public:
    mob_azure_captain() : CreatureScript("mob_azure_captain") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_azure_captainAI (pCreature);
    }

    struct  mob_azure_captainAI : public violet_hold_trashAI
    {
        mob_azure_captainAI(Creature *c) : violet_hold_trashAI(c)
        {
            pInstance = c->GetInstanceScript();
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

};

class mob_azure_sorceror : public CreatureScript
{
public:
    mob_azure_sorceror() : CreatureScript("mob_azure_sorceror") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_azure_sorcerorAI (pCreature);
    }

    struct  mob_azure_sorcerorAI : public violet_hold_trashAI
    {
        mob_azure_sorcerorAI(Creature *c) : violet_hold_trashAI(c)
        {
            pInstance = c->GetInstanceScript();
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

};

void AddSC_violet_hold()
{
    new npc_sinclari_vh();
    new npc_teleportation_portal_vh();
    new mob_azure_invader();
    new mob_azure_spellbreaker();
    new mob_azure_binder();
    new mob_azure_mage_slayer();
    new mob_azure_captain();
    new mob_azure_sorceror();
    new mob_azure_raider();
    new mob_azure_stalker();
    new mob_azure_saboteur();
}
