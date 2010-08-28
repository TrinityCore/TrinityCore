/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
#include "culling_of_stratholme.h"
#include "ScriptedEscortAI.h"

enum Says
{
    //First Act - Uther and Jaina Dialog
    SAY_PHASE101                                = -1595070,  //Arthas
    SAY_PHASE102                                = -1595071,  //Uther
    SAY_PHASE103                                = -1595072,  //Arthas
    SAY_PHASE104                                = -1595073,  //Arthas
    SAY_PHASE105                                = -1595074,  //Uther
    SAY_PHASE106                                = -1595075,  //Arthas
    SAY_PHASE107                                = -1595076,  //Uther
    SAY_PHASE108                                = -1595077,  //Arthas
    SAY_PHASE109                                = -1595078,  //Arthas
    SAY_PHASE110                                = -1595079,  //Uther
    SAY_PHASE111                                = -1595080,  //Arthas
    SAY_PHASE112                                = -1595081,  //Uther
    SAY_PHASE113                                = -1595082,  //Jaina
    SAY_PHASE114                                = -1595083,  //Arthas
    SAY_PHASE115                                = -1595084,  //Uther
    SAY_PHASE116                                = -1595085,  //Arthas
    SAY_PHASE117                                = -1595086,  //Jaina
    SAY_PHASE118                                = -1595087,  //Arthas
    //Second Act - City Streets
    SAY_PHASE201                                = -1595088,  //Arthas
    SAY_PHASE202                                = -1595089,  //Cityman
    SAY_PHASE203                                = -1595090,  //Arthas
    SAY_PHASE204                                = -1595091,  //Crazyman
    SAY_PHASE205                                = -1595092,  //Arthas
    SAY_PHASE206                                = -1595009,  //Malganis
    SAY_PHASE207                                = -1595010,  //Malganis
    SAY_PHASE208                                = -1595093,  //Arthas
    SAY_PHASE209                                = -1595094,  //Arthas
    SAY_PHASE210                                = -1595095,  //Arthas
    //Third Act - Town Hall
    SAY_PHASE301                               = -1595096,  //Arthas
    SAY_PHASE302                               = -1595097,  //Drakonian
    SAY_PHASE303                               = -1595098,  //Arthas
    SAY_PHASE304                               = -1595099,  //Arthas
    SAY_PHASE305                               = -1595100,  //Drakonian
    SAY_PHASE306                               = -1595101,  //Arthas
    SAY_PHASE307                               = -1595102,  //Arthas
    SAY_PHASE308                               = -1595103,  //Arthas
    SAY_PHASE309                               = -1595104,  //Arthas
    SAY_PHASE310                               = -1595105,  //Arthas
    SAY_PHASE311                               = -1595106,  //Arthas
    SAY_PHASE312                               = -1595107,  //Arthas
    SAY_PHASE313                               = -1595108,  //Arthas
    SAY_PHASE314                               = -1595000,  //Epoch
    SAY_PHASE315                               = -1595109,  //Arthas
    //Fourth Act - Fire Corridor
    SAY_PHASE401                               = -1595110,  //Arthas
    SAY_PHASE402                               = -1595111,  //Arthas
    SAY_PHASE403                               = -1595112,  //Arthas
    SAY_PHASE404                               = -1595113,  //Arthas
    SAY_PHASE405                               = -1595114,  //Arthas
    SAY_PHASE406                               = -1595115,  //Arthas
    SAY_PHASE407                               = -1595116,  //Arthas
    //Fifth Act - Mal'Ganis Fight
    SAY_PHASE501                               = -1595117,  //Arthas
    SAY_PHASE502                               = -1595118,  //Arthas
    SAY_PHASE503                               = -1595119,  //Arthas
    SAY_PHASE504                               = -1595120,  //Arthas
};

enum NPCs
{
    NPC_INFINITE_ADVERSARY                     = 27742,
    NPC_INFINITE_HUNTER                        = 27743,
    NPC_INFINITE_AGENT                         = 27744,
    NPC_TIME_RIFT                              = 28409,
    NPC_ZOMBIE                                 = 27737,
    NPC_GHOUL                                  = 28249,
    NPC_NECROMANCER                            = 28200,
    NPC_STALKER                                = 28199,
    NPC_FIEND                                  = 27734,
    NPC_GOLEM                                  = 28201,
    NPC_EGHOUL                                 = 27729,
    NPC_CONSTRUCT                              = 27736,

    NPC_INVIS_TARGET                           = 20562,

    NPC_KNIGHT_ESCORT                          = 27745,
    NPC_PRIEST_ESCORT                          = 27747,
    NPC_CITY_MAN                               = 28167,
    NPC_CITY_MAN2                              = 28169,
    NPC_CITY_MAN3                              = 31126,
    NPC_CITY_MAN4                              = 31127,
};

enum Spells
{
    SPELL_FEAR                                 = 39176,
    SPELL_ARTHAS_AURA                          = 52442,
    SPELL_EXORCISM_N                           = 52445,
    SPELL_EXORCISM_H                           = 58822,
    SPELL_HOLY_LIGHT                           = 52444,
};

enum GossipMenuArthas
{
   GOSSIP_MENU_ARTHAS_1                        = 100001,
   GOSSIP_MENU_ARTHAS_2                        = 100002,
   GOSSIP_MENU_ARTHAS_3                        = 100003,
   GOSSIP_MENU_ARTHAS_4                        = 100004,
   GOSSIP_MENU_ARTHAS_5                        = 100005
};

enum
{
    ENCOUNTER_WAVES_NUMBER                      = 8,
    ENCOUNTER_WAVES_MAX_SPAWNS                  = 5,
    ENCOUNTER_DRACONIAN_NUMBER                  = 4,
    ENCOUNTER_CHRONO_SPAWNS                     = 19
};

// Locations for necromancers and add to spawn
float WavesLocations[ENCOUNTER_WAVES_NUMBER][ENCOUNTER_WAVES_MAX_SPAWNS][5]=
{
    {
        {NPC_ZOMBIE, 2164.698975f, 1255.392944f, 135.040878f, 0.490202f},
        {NPC_ZOMBIE, 2183.501465f, 1263.079102f, 134.859055f, 3.169981f},
        {NPC_GHOUL, 2177.512939f, 1247.313843f, 135.846695f, 1.696574f},
        {NPC_GHOUL, 2171.991943f, 1246.615845f, 135.745026f, 1.696574f},
        {0, 0, 0, 0, 0}
    },
    {
        {NPC_GHOUL, 2254.434326f, 1163.427612f, 138.055038f, 2.077358f},
        {NPC_GHOUL, 2254.703613f, 1158.867798f, 138.212234f, 2.345532f},
        {NPC_GHOUL, 2257.615723f, 1162.310913f, 138.091202f, 2.077358f},
        {NPC_NECROMANCER, 2258.258057f, 1157.250732f, 138.272873f, 2.387766f},
        {0, 0, 0, 0, 0}
    },
    {
        {NPC_STALKER, 2348.120117f, 1202.302490f, 130.491104f, 4.698538f},
        {NPC_GHOUL, 2352.863525f, 1207.819092f, 130.424271f, 4.949865f},
        {NPC_GHOUL, 2343.593750f, 1207.915039f, 130.781311f, 4.321547f},
        {NPC_NECROMANCER, 2348.257324f, 1212.202515f, 130.670135f, 4.450352f},
        {0, 0, 0, 0, 0}
    },
    {
        {NPC_STALKER, 2139.825195f, 1356.277100f, 132.199615f, 5.820131f},
        {NPC_GHOUL, 2137.073486f, 1362.464844f, 132.271637f, 5.820131f},
        {NPC_GHOUL, 2134.075684f, 1354.148071f, 131.885864f, 5.820131f},
        {NPC_NECROMANCER, 2133.302246f, 1358.907837f, 132.037689f, 5.820131f},
        {0, 0, 0, 0, 0}
    },
    {
        {NPC_NECROMANCER, 2264.013428f, 1174.055908f, 138.093094f, 2.860481f},
        {NPC_GHOUL, 2264.207764f, 1170.892700f, 138.034973f, 2.860481f},
        {NPC_GHOUL, 2266.948975f, 1176.898926f, 137.976929f, 2.860481f},
        {NPC_STALKER, 2269.215576f, 1170.109253f, 137.742691f, 2.860481f},
        {NPC_FIEND, 2273.106689f, 1176.101074f, 137.880508f, 2.860481f}
    },
    {
        {NPC_GOLEM, 2349.701660f, 1188.436646f, 130.428864f, 3.908642f},
        {NPC_GHOUL, 2349.909180f, 1194.582642f, 130.417816f, 3.577001f},
        {NPC_EGHOUL, 2354.662598f, 1185.692017f, 130.552032f, 3.577001f},
        {NPC_EGHOUL, 2354.716797f, 1191.614380f, 130.539810f, 3.577001f},
        {0, 0, 0, 0, 0}
    },
    {
        {NPC_CONSTRUCT, 2145.212891f, 1355.288086f, 132.288773f, 6.004838f},
        {NPC_NECROMANCER, 2137.078613f, 1357.612671f, 132.173340f, 6.004838f},
        {NPC_EGHOUL, 2139.402100f, 1352.541626f, 132.127518f, 5.812850f},
        {NPC_EGHOUL, 2142.408447f, 1360.760620f, 132.321564f, 5.812850f},
        {0, 0, 0, 0, 0}
    },
    {
        {NPC_GHOUL, 2172.686279f, 1259.618164f, 134.391754f, 1.865499f},
        {NPC_FIEND, 2177.649170f, 1256.061157f, 135.096512f, 1.849572f},
        {NPC_CONSTRUCT, 2170.782959f, 1253.594849f, 134.973022f, 1.849572f},
        {NPC_NECROMANCER, 2175.595703f, 1249.041992f, 135.603531f, 1.849572f},
        {0, 0, 0, 0, 0}
    }
};

// Locations for rifts to spawn and draconians to go
float RiftAndSpawnsLocations[ENCOUNTER_CHRONO_SPAWNS][5]=
{
    {NPC_TIME_RIFT, 2431.790039f, 1190.670044f, 148.076004f, 0.187923f},
    {NPC_INFINITE_ADVERSARY, 2433.857910f, 1185.612061f, 148.075974f, 4.566168f},
    {NPC_INFINITE_ADVERSARY, 2437.577881f, 1188.241089f, 148.075974f, 0.196999f},
    {NPC_INFINITE_AGENT, 2437.165527f, 1192.294922f, 148.075974f, 0.169247f},
    {NPC_INFINITE_HUNTER, 2434.989990f, 1197.679565f, 148.075974f, 0.715971f},
    {NPC_TIME_RIFT, 2403.954834f, 1178.815430f, 148.075943f, 4.966126f},
    {NPC_INFINITE_AGENT, 2403.676758f, 1171.495850f, 148.075607f, 4.902797f},
    {NPC_INFINITE_HUNTER, 2407.691162f, 1172.162720f, 148.075607f, 4.963010f},
    {NPC_TIME_RIFT, 2414.217041f, 1133.446167f, 148.076050f, 1.706972f},
    {NPC_INFINITE_ADVERSARY, 2416.024658f, 1139.456177f, 148.076431f, 1.752129f},
    {NPC_INFINITE_HUNTER, 2410.866699f, 1139.680542f, 148.076431f, 1.752129f},
    {NPC_TIME_RIFT, 2433.081543f, 1099.869751f, 148.076157f, 1.809509f},
    {NPC_INFINITE_ADVERSARY, 2426.947998f, 1107.471680f, 148.076019f, 1.877580f},
    {NPC_INFINITE_HUNTER, 2432.944580f, 1108.896362f, 148.208160f, 2.199241f},
    {NPC_TIME_RIFT, 2444.077637f, 1114.366089f, 148.076157f, 3.049565f},
    {NPC_INFINITE_ADVERSARY, 2438.190674f, 1118.368164f, 148.076172f, 3.139232f},
    {NPC_INFINITE_AGENT, 2435.861328f, 1113.402954f, 148.169327f, 2.390271f},
    {NPC_TIME_RIFT, 2463.131592f, 1115.391724f, 152.473129f, 3.409651f},
    {NPC_EPOCH, 2451.809326f, 1112.901245f, 149.220459f, 3.363617f}
};

#define GOSSIP_ITEM_ARTHAS_0 "I'm ready to start Culling of Stratholme."
#define GOSSIP_ITEM_ARTHAS_1 "Yes, my Prince. We're ready."
#define GOSSIP_ITEM_ARTHAS_2 "We're only doing what is best for Loarderon your Highness."
#define GOSSIP_ITEM_ARTHAS_3 "I'm ready."
#define GOSSIP_ITEM_ARTHAS_4 "For Lordaeron!"
#define GOSSIP_ITEM_ARTHAS_5 "I'm ready to battle the dreadlord, sire."

class npc_arthas : public CreatureScript
{
public:
    npc_arthas() : CreatureScript("npc_arthas") { }

    bool OnGossipSelect(Player *pPlayer, Creature *pCreature, uint32 /*sender*/, uint32 action)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        npc_arthasAI* pAI = CAST_AI(npc_arthas::npc_arthasAI,pCreature->AI());

        if (!pAI)
            return false;

        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF:
                pAI->Start(true,true,pPlayer->GetGUID(),0,false,false);
                pAI->SetDespawnAtEnd(false);
                pAI->bStepping = false;
                pAI->uiStep = 1;
                break;
            case GOSSIP_ACTION_INFO_DEF+1:
                pAI->bStepping = true;
                pAI->uiStep = 24;
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                pAI->SetHoldState(false);
                pAI->bStepping = false;
                pAI->uiStep = 61;
                break;
            case GOSSIP_ACTION_INFO_DEF+3:
                pAI->SetHoldState(false);
                break;
            case GOSSIP_ACTION_INFO_DEF+4:
                pAI->bStepping = true;
                pAI->uiStep = 84;
                break;
            case GOSSIP_ACTION_INFO_DEF+5:
                pAI->bStepping = true;
                pAI->uiStep = 85;
                break;
        }
        pPlayer->CLOSE_GOSSIP_MENU();
        pAI->SetDespawnAtFar(true);
        pCreature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        npc_arthasAI* pAI = CAST_AI(npc_arthas::npc_arthasAI,pCreature->AI());

        if (pAI && pAI->bStepping == false)
        {
            switch (pAI->uiGossipStep)
            {
                case 0: //This one is a workaround since the very beggining of the script is wrong.
                    if (pPlayer->GetQuestStatus(13149) != QUEST_STATUS_COMPLETE)
                        return false;
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_ARTHAS_0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                    pPlayer->SEND_GOSSIP_MENU(907, pCreature->GetGUID());
                    break;
                case 1:
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_ARTHAS_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                    pPlayer->SEND_GOSSIP_MENU(GOSSIP_MENU_ARTHAS_1, pCreature->GetGUID());
                    break;
                case 2:
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_ARTHAS_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                    pPlayer->SEND_GOSSIP_MENU(GOSSIP_MENU_ARTHAS_2, pCreature->GetGUID());
                    break;
                case 3:
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_ARTHAS_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
                    pPlayer->SEND_GOSSIP_MENU(GOSSIP_MENU_ARTHAS_3, pCreature->GetGUID());
                    break;
                case 4:
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_ARTHAS_4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
                    pPlayer->SEND_GOSSIP_MENU(GOSSIP_MENU_ARTHAS_4, pCreature->GetGUID());
                    break;
                case 5:
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_ARTHAS_5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+5);
                    pPlayer->SEND_GOSSIP_MENU(GOSSIP_MENU_ARTHAS_5, pCreature->GetGUID());
                    break;
                default:
                    return false;
            }
        }
        return true;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_arthasAI(pCreature);
    }

    struct npc_arthasAI : public npc_escortAI
    {
        npc_arthasAI(Creature *pCreature) : npc_escortAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();
            Reset();
        }

        InstanceScript* pInstance;

        bool bStepping;
        uint32 uiStep;
        uint32 uiPhaseTimer;
        uint32 uiGossipStep;
        uint32 uiPlayerFaction;
        uint32 uiBossEvent;
        uint32 uiWave;

        uint64 uiUtherGUID;
        uint64 uiJainaGUID;
        uint64 uiCitymenGUID[2];
        uint64 uiWaveGUID[ENCOUNTER_WAVES_MAX_SPAWNS];
        uint64 uiInfiniteDraconianGUID[ENCOUNTER_DRACONIAN_NUMBER];
        uint64 uiStalkerGUID;

        uint64 uiBossGUID; //uiMeathookGUID || uiSalrammGUID
        uint64 uiEpochGUID;
        uint64 uiMalganisGUID;
        uint64 uiInfiniteGUID;

        uint32 uiExorcismTimer;

        void Reset()
        {
            uiUtherGUID = 0;
            uiJainaGUID = 0;

            for (uint8 i = 0; i < 2; ++i)
                uiCitymenGUID[i] = 0;

            for (uint8 i = 0; i < ENCOUNTER_WAVES_MAX_SPAWNS; ++i)
                uiWaveGUID[i] = 0;

            for (uint8 i = 0; i < ENCOUNTER_DRACONIAN_NUMBER; ++i)
                uiInfiniteDraconianGUID[i] = 0;

            uiStalkerGUID = 0;
            uiBossGUID = 0;
            uiEpochGUID = 0;
            uiMalganisGUID = 0;
            uiInfiniteGUID = 0;

            if (pInstance) {
                pInstance->SetData(DATA_ARTHAS_EVENT, NOT_STARTED);
                switch(pInstance->GetData(DATA_ARTHAS_EVENT))
                {
                    case NOT_STARTED:
                        bStepping = true;
                        uiStep = 0;
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                        uiBossEvent = DATA_MEATHOOK_EVENT;
                        uiGossipStep = 0;
                        break;
                }
                uiPhaseTimer = 1000;
                uiExorcismTimer = 7300;
                uiWave = 0;
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoCast(me, SPELL_ARTHAS_AURA);
        }

        void JustDied(Unit * /*killer*/)
        {
            if (pInstance)
                pInstance->SetData(DATA_ARTHAS_EVENT, FAIL);
        }

        void SpawnTimeRift(uint32 timeRiftID, uint64* guidVector)
        {
            me->SummonCreature((uint32)RiftAndSpawnsLocations[timeRiftID][0],RiftAndSpawnsLocations[timeRiftID][1],RiftAndSpawnsLocations[timeRiftID][2],RiftAndSpawnsLocations[timeRiftID][3],RiftAndSpawnsLocations[timeRiftID][4],TEMPSUMMON_TIMED_DESPAWN,11000);

            for (uint32 i = timeRiftID+1; i < ENCOUNTER_CHRONO_SPAWNS; ++i)
            {
                if ((uint32)RiftAndSpawnsLocations[i][0] == NPC_TIME_RIFT) break;
                if (Creature* pTemp = me->SummonCreature((uint32)RiftAndSpawnsLocations[i][0],RiftAndSpawnsLocations[timeRiftID][1],RiftAndSpawnsLocations[timeRiftID][2],RiftAndSpawnsLocations[timeRiftID][3],RiftAndSpawnsLocations[timeRiftID][4],TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,900000))
                {
                    guidVector[i-timeRiftID-1] = pTemp->GetGUID();
                    pTemp->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_UNK_9);
                    pTemp->SetReactState(REACT_PASSIVE);
                    pTemp->GetMotionMaster()->MovePoint(0, RiftAndSpawnsLocations[i][1],RiftAndSpawnsLocations[i][2],RiftAndSpawnsLocations[i][3]);
                    if ((uint32)RiftAndSpawnsLocations[i][0] == NPC_EPOCH)
                        uiEpochGUID = pTemp->GetGUID();
                }
            }
        }

        void SpawnWaveGroup(uint32 waveID, uint64* guidVector)
        {
            for (uint32 i = 0; i < ENCOUNTER_WAVES_MAX_SPAWNS; ++i)
            {
                if ((uint32)WavesLocations[waveID][i][0] == 0) break;
                if (Creature* pTemp = me->SummonCreature((uint32)WavesLocations[waveID][i][0],WavesLocations[waveID][i][1],WavesLocations[waveID][i][2],WavesLocations[waveID][i][3],WavesLocations[waveID][i][4],TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,900000))
                {
                    guidVector[i] = pTemp->GetGUID();
                }
            }
        }

        void SetHoldState(bool bOnHold)
        {
            SetEscortPaused(bOnHold);
        }

        void JumpToNextStep(uint32 uiTimer)
        {
            uiPhaseTimer = uiTimer;
            ++uiStep;
        }

        void WaypointReached(uint32 uiPointId)
        {
            switch(uiPointId)
            {
                case 0:
                case 1:
                case 3:
                case 9:
                case 10:
                case 11:
                case 22:
                case 23:
                case 26:
                case 55:
                case 56:
                    SetHoldState(true);
                    bStepping = true;
                    break;
                case 7:
                    if (Unit* pCityman0 = me->SummonCreature(NPC_CITY_MAN,2091.977f,1275.021f,140.757f,0.558f,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,60000))
                        uiCitymenGUID[0] = pCityman0->GetGUID();
                    if (Unit* pCityman1 = me->SummonCreature(NPC_CITY_MAN2,2093.514f,1275.842f,140.408f,3.801f,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,60000))
                        uiCitymenGUID[1] = pCityman1->GetGUID();
                    break;
                case 8:
                    uiGossipStep = 1;
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    SetHoldState(true);
                    break;
                case 12:
                    SetRun(true);
                    DoScriptText(SAY_PHASE210, me);
                    if (Unit* pDisguised0 = me->SummonCreature(NPC_CITY_MAN3,2398.14f,1207.81f,134.04f,5.155249f,TEMPSUMMON_DEAD_DESPAWN,180000))
                    {
                        uiInfiniteDraconianGUID[0] = pDisguised0->GetGUID();
                        if (Unit* pDisguised1 = me->SummonCreature(NPC_CITY_MAN4,2403.22f,1205.54f,134.04f,3.311264f,TEMPSUMMON_DEAD_DESPAWN,180000))
                        {
                            uiInfiniteDraconianGUID[1] = pDisguised1->GetGUID();

                            if (Unit* pDisguised2 = me->SummonCreature(NPC_CITY_MAN,2400.82f,1201.69f,134.01f,1.534082f,TEMPSUMMON_DEAD_DESPAWN,180000))
                            {
                                uiInfiniteDraconianGUID[2] = pDisguised2->GetGUID();
                                pDisguised0->SetUInt64Value(UNIT_FIELD_TARGET, uiInfiniteDraconianGUID[1]);
                                pDisguised1->SetUInt64Value(UNIT_FIELD_TARGET, uiInfiniteDraconianGUID[0]);
                                pDisguised2->SetUInt64Value(UNIT_FIELD_TARGET, uiInfiniteDraconianGUID[1]);
                            }
                        }
                    }
                    break;
                case 20:
                    uiGossipStep = 2;
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    SetRun(false);
                    SetHoldState(true);
                    break;
                case 21:
                    DoScriptText(SAY_PHASE301, me);
                    break;
                case 25:
                    SetRun(false);
                    SpawnTimeRift(0,&uiInfiniteDraconianGUID[0]);
                    DoScriptText(SAY_PHASE307,me);
                    break;
                case 29:
                    SetRun(false);
                    SpawnTimeRift(5,&uiInfiniteDraconianGUID[0]);
                    SpawnTimeRift(8,&uiInfiniteDraconianGUID[2]);
                    DoScriptText(SAY_PHASE309,me);
                    SetHoldState(true);
                    bStepping = true;
                    break;
                case 31:
                    SetRun(false);
                    SpawnTimeRift(11,&uiInfiniteDraconianGUID[0]);
                    SpawnTimeRift(14,&uiInfiniteDraconianGUID[2]);
                    DoScriptText(SAY_PHASE311,me);
                    SetHoldState(true);
                    bStepping = true;
                    break;
                case 32:
                    DoScriptText(SAY_PHASE401,me);
                    break;
                case 34:
                    DoScriptText(SAY_PHASE402,me);
                    break;
                case 35:
                    DoScriptText(SAY_PHASE403,me);
                    break;
                case 36:
                    if (pInstance)
                        if (GameObject* pGate = pInstance->instance->GetGameObject(pInstance->GetData64(DATA_SHKAF_GATE)))
                            pGate->SetGoState(GO_STATE_ACTIVE);
                    break;
                case 45:
                    SetRun(true);
                    SetDespawnAtFar(false);
                    uiGossipStep = 4;
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    SetHoldState(true);
                    break;
                case 47:
                    SetRun(false);
                    DoScriptText(SAY_PHASE405,me);
                    break;
                case 48:
                    SetRun(true);
                    DoScriptText(SAY_PHASE406,me);
                    break;
                case 53:
                    DoScriptText(SAY_PHASE407,me);
                    break;
                case 54:
                    uiGossipStep = 5;
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    SetHoldState(true);
                    break;
             }
        }

        void UpdateAI(const uint32 diff)
        {
            npc_escortAI::UpdateAI(diff);

            DoMeleeAttackIfReady();

            if (bStepping)
            {
                if (uiPhaseTimer <= diff)
                {
                    switch(uiStep)
                    {
                        //After reset
                        case 0:
                            if (Unit* pJaina = GetClosestCreatureWithEntry(me, NPC_JAINA, 50.0f))
                                uiJainaGUID = pJaina->GetGUID();
                            else if (Unit* pJaina = me->SummonCreature(NPC_JAINA,1895.48f,1292.66f,143.706f,0.023475f,TEMPSUMMON_DEAD_DESPAWN,180000))
                                uiJainaGUID = pJaina->GetGUID();
                            bStepping = false;
                            JumpToNextStep(0);
                            break;
                        //After waypoint 0
                        case 1:
                            me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                            if (Unit* pUther = me->SummonCreature(NPC_UTHER,1794.357f,1272.183f,140.558f,1.37f,TEMPSUMMON_DEAD_DESPAWN,180000))
                            {
                                uiUtherGUID = pUther->GetGUID();
                                pUther->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                                pUther->GetMotionMaster()->MovePoint(0, 1897.018f, 1287.487f, 143.481f);
                                pUther->SetUInt64Value(UNIT_FIELD_TARGET, me->GetGUID());
                                me->SetUInt64Value(UNIT_FIELD_TARGET, uiUtherGUID);
                            }
                            JumpToNextStep(17000);
                            break;
                        case 2:
                            DoScriptText(SAY_PHASE101, me);
                            JumpToNextStep(2000);
                            break;
                        case 3:
                            if (Creature* pUther = Unit::GetCreature(*me, uiUtherGUID))
                            {
                                DoScriptText(SAY_PHASE102, pUther);
                            }
                            JumpToNextStep(8000);
                            break;
                        case 4:
                            SetEscortPaused(false);
                            bStepping = false;
                            SetRun(false);
                            DoScriptText(SAY_PHASE103, me);
                            JumpToNextStep(0);
                            break;
                        //After waypoint 1
                        case 5:
                            if (Creature* pJaina = Unit::GetCreature(*me, uiJainaGUID))
                                pJaina->SetUInt64Value(UNIT_FIELD_TARGET, me->GetGUID());
                            DoScriptText(SAY_PHASE104, me);
                            JumpToNextStep(10000);
                            break;
                        case 6:
                            if (Creature* pUther = Unit::GetCreature(*me, uiUtherGUID))
                                DoScriptText(SAY_PHASE105, pUther);
                            JumpToNextStep(1000);
                            break;
                        case 7:
                            DoScriptText(SAY_PHASE106, me);
                            JumpToNextStep(4000);
                            break;
                        case 8:
                            if (Creature* pUther = Unit::GetCreature(*me, uiUtherGUID))
                                DoScriptText(SAY_PHASE107, pUther);
                            JumpToNextStep(6000);
                            break;
                        case 9:
                            DoScriptText(SAY_PHASE108, me);
                            JumpToNextStep(4000);
                            break;
                        case 10:
                            if (Creature* pUther = Unit::GetCreature(*me, uiUtherGUID))
                                DoScriptText(SAY_PHASE109, pUther);
                            JumpToNextStep(8000);
                            break;
                        case 11:
                            DoScriptText(SAY_PHASE110, me);
                            JumpToNextStep(4000);
                            break;
                        case 12:
                            if (Creature* pUther = Unit::GetCreature(*me, uiUtherGUID))
                                DoScriptText(SAY_PHASE111, pUther);
                            JumpToNextStep(4000);
                            break;
                        case 13:
                            DoScriptText(SAY_PHASE112, me);
                            JumpToNextStep(11000);
                            break;
                        case 14:
                            if (Creature* pJaina = Unit::GetCreature(*me, uiJainaGUID))
                                DoScriptText(SAY_PHASE113, pJaina);
                            JumpToNextStep(3000);
                            break;
                        case 15:
                            DoScriptText(SAY_PHASE114, me);
                            JumpToNextStep(9000);
                            break;
                        case 16:
                            if (Creature* pUther = Unit::GetCreature(*me, uiUtherGUID))
                                DoScriptText(SAY_PHASE115, pUther);
                            JumpToNextStep(4000);
                            break;
                        case 17:
                            if (Creature* pUther = Unit::GetCreature(*me, uiUtherGUID))
                            {
                                pUther->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                                pUther->GetMotionMaster()->MovePoint(0, 1794.357f,1272.183f,140.558f);
                            }
                            JumpToNextStep(1000);
                            break;
                        case 18:
                            if (Creature* pJaina = Unit::GetCreature(*me, uiJainaGUID))
                            {
                                me->SetUInt64Value(UNIT_FIELD_TARGET, uiJainaGUID);
                                pJaina->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                                pJaina->GetMotionMaster()->MovePoint(0, 1794.357f,1272.183f,140.558f);
                            }
                            JumpToNextStep(1000);
                            break;
                        case 19:
                            DoScriptText(SAY_PHASE116, me);
                            JumpToNextStep(1000);
                            break;
                        case 20:
                            if (Creature* pJaina = Unit::GetCreature(*me, uiJainaGUID))
                                DoScriptText(SAY_PHASE117, pJaina);
                            JumpToNextStep(3000);
                            break;
                        case 21:
                            SetEscortPaused(false);
                            bStepping = false;
                            me->SetUInt64Value(UNIT_FIELD_TARGET, 0);
                            JumpToNextStep(0);
                            break;
                        //After waypoint 3
                        case 22:
                            DoScriptText(SAY_PHASE118, me);
                            me->SetUInt64Value(UNIT_FIELD_TARGET, uiJainaGUID);
                            JumpToNextStep(10000);
                            break;
                        case 23:
                            SetEscortPaused(false);
                            bStepping = false;
                            SetRun(true);

                            if (Creature* pJaina = Unit::GetCreature(*me, uiJainaGUID))
                                pJaina->DisappearAndDie();

                            if (Creature* pUther = Unit::GetCreature(*me, uiUtherGUID))
                                pUther->DisappearAndDie();

                            me->SetUInt64Value(UNIT_FIELD_TARGET, 0);
                            JumpToNextStep(0);
                            break;
                        //After Gossip 1 (waypoint 8)
                        case 24:
                            if (Unit* pStalker = me->SummonCreature(NPC_INVIS_TARGET,2026.469f,1287.088f,143.596f,1.37f,TEMPSUMMON_TIMED_DESPAWN,14000))
                            {
                                uiStalkerGUID = pStalker->GetGUID();
                                me->SetUInt64Value(UNIT_FIELD_TARGET, uiStalkerGUID);
                            }
                            JumpToNextStep(1000);
                            break;
                        case 25:
                            DoScriptText(SAY_PHASE201, me);
                            JumpToNextStep(12000);
                            break;
                        case 26:
                            SetEscortPaused(false);
                            bStepping = false;
                            SetRun(false);
                            me->SetUInt64Value(UNIT_FIELD_TARGET, 0);
                            JumpToNextStep(0);
                            break;
                        //After waypoint 9
                        case 27:
                            me->SetUInt64Value(UNIT_FIELD_TARGET, uiCitymenGUID[0]);
                            if (Creature* pCityman = Unit::GetCreature(*me, uiCitymenGUID[0]))
                            {
                                pCityman->SetUInt64Value(UNIT_FIELD_TARGET, me->GetGUID());
                                pCityman->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                                pCityman->GetMotionMaster()->MovePoint(0, 2088.625f,1279.191f,140.743f);
                            }
                            JumpToNextStep(2000);
                            break;
                        case 28:
                            if (Creature* pCityman = Unit::GetCreature(*me, uiCitymenGUID[0]))
                                DoScriptText(SAY_PHASE202, pCityman);
                            JumpToNextStep(4000);
                            break;
                        case 29:
                            SetEscortPaused(false);
                            bStepping = false;
                            DoScriptText(SAY_PHASE203, me);
                            JumpToNextStep(0);
                            break;
                        //After waypoint 10
                        case 30:
                            me->HandleEmoteCommand(37);
                            JumpToNextStep(1000);
                            break;
                        case 31:
                            SetEscortPaused(false);
                            bStepping = false;
                            if (Creature* pCityman1 = Unit::GetCreature(*me, uiCitymenGUID[1]))
                            {
                                DoScriptText(SAY_PHASE204, pCityman1);
                                pCityman1->SetUInt64Value(UNIT_FIELD_TARGET, me->GetGUID());
                                if (Creature* pCityman0 = Unit::GetCreature(*me, uiCitymenGUID[0]))
                                    pCityman0->Kill(pCityman0);
                                me->SetUInt64Value(UNIT_FIELD_TARGET, uiCitymenGUID[1]);
                            }
                            JumpToNextStep(0);
                            break;
                        //After waypoint 11
                        case 32:
                            me->HandleEmoteCommand(37);
                            JumpToNextStep(1000);
                            break;
                        case 33:
                            if (Creature* pCityman1 = Unit::GetCreature(*me, uiCitymenGUID[1]))
                                pCityman1->Kill(pCityman1);
                            JumpToNextStep(1000);
                            break;
                        case 34:
                            if (Unit* pStalker = me->SummonCreature(NPC_INVIS_TARGET,2081.447f,1287.770f,141.3241f,1.37f,TEMPSUMMON_TIMED_DESPAWN,10000))
                            {
                                uiStalkerGUID = pStalker->GetGUID();
                                me->SetUInt64Value(UNIT_FIELD_TARGET, uiStalkerGUID);
                            }
                            DoScriptText(SAY_PHASE205, me);
                            JumpToNextStep(3000);
                            break;
                        case 35:
                            if (Unit* pStalkerM = me->SummonCreature(NPC_INVIS_TARGET,2117.349f,1288.624f,136.271f,1.37f,TEMPSUMMON_TIMED_DESPAWN,60000))
                            {
                                uiStalkerGUID = pStalkerM->GetGUID();
                                me->SetUInt64Value(UNIT_FIELD_TARGET, uiStalkerGUID);
                            }
                            JumpToNextStep(1000);
                            break;
                        case 36:
                            if (Creature* pMalganis = me->SummonCreature(NPC_MAL_GANIS,2117.349f,1288.624f,136.271f,1.37f,TEMPSUMMON_TIMED_DESPAWN,60000))
                            {
                                if (Creature* pStalkerM = Unit::GetCreature(*me, uiStalkerGUID))
                                    pMalganis->CastSpell(pStalkerM,63793,false);

                                uiMalganisGUID = pMalganis->GetGUID();
                                DoScriptText(SAY_PHASE206, pMalganis);
                                pMalganis->SetUInt64Value(UNIT_FIELD_TARGET, me->GetGUID());
                                pMalganis->SetReactState(REACT_PASSIVE);
                            }
                            JumpToNextStep(11000);
                            break;
                        case 37:
                            if (Creature* pMalganis = Unit::GetCreature(*me, uiMalganisGUID))
                            {
                                if (Creature* pZombie = GetClosestCreatureWithEntry(pMalganis, NPC_CITY_MAN, 100.0f))
                                    pZombie->UpdateEntry(NPC_ZOMBIE, 0);
                                else if (Creature* pZombie = GetClosestCreatureWithEntry(pMalganis, NPC_CITY_MAN2, 100.0f))
                                    pZombie->UpdateEntry(NPC_ZOMBIE, 0);
                                else //There's no one else to transform
                                    uiStep++;
                            }
                            else
                                uiStep++;
                            uiPhaseTimer = 500;
                            break;
                        case 38:
                            if (Creature* pMalganis = Unit::GetCreature(*me, uiMalganisGUID))
                                DoScriptText(SAY_PHASE207, pMalganis);
                            JumpToNextStep(17000);
                            break;
                        case 39:
                            if (Creature* pMalganis = Unit::GetCreature(*me, uiMalganisGUID))
                                pMalganis->SetVisibility(VISIBILITY_OFF);
                            DoScriptText(SAY_PHASE208, me);
                            JumpToNextStep(7000);
                            break;
                        case 40:
                            if (Unit* pStalker = me->SummonCreature(NPC_INVIS_TARGET,2081.447f,1287.770f,141.3241f,1.37f,TEMPSUMMON_TIMED_DESPAWN,10000))
                            {
                                uiStalkerGUID = pStalker->GetGUID();
                                me->SetUInt64Value(UNIT_FIELD_TARGET, uiStalkerGUID);
                            }
                            DoScriptText(SAY_PHASE209, me);

                            uiBossEvent = DATA_MEATHOOK_EVENT;
                            if (pInstance)
                                pInstance->SetData(DATA_ARTHAS_EVENT, IN_PROGRESS);

                            me->SetReactState(REACT_DEFENSIVE);
                            SetDespawnAtFar(false);
                            JumpToNextStep(5000);
                            break;
                        case 41: //Summon wave group
                        case 43:
                        case 45:
                        case 47:
                        case 51:
                        case 53:
                        case 55:
                        case 57:
                            if (pInstance->GetData(uiBossEvent) != DONE)
                            {
                                SpawnWaveGroup(uiWave, uiWaveGUID);
                                uiWave++;
                            }
                            JumpToNextStep(500);
                            break;
                        case 42: //Wait group to die
                        case 44:
                        case 46:
                        case 48:
                        case 52:
                        case 54:
                        case 56:
                        case 58:
                            if (pInstance->GetData(uiBossEvent) != DONE)
                            {
                                uint32 mobCounter = 0;
                                uint32 deadCounter = 0;
                                for (uint8 i = 0; i < ENCOUNTER_WAVES_MAX_SPAWNS; ++i)
                                {
                                    if (uiWaveGUID[i] == 0)
                                        break;
                                    ++mobCounter;
                                    Unit* pTemp = Unit::GetCreature(*me, uiWaveGUID[i]);
                                    if (!pTemp || pTemp->isDead())
                                        ++deadCounter;
                                }

                                if (mobCounter <= deadCounter) //If group is dead
                                    JumpToNextStep(1000);
                                else
                                    uiPhaseTimer = 1000;
                            }
                            else
                                JumpToNextStep(500);
                            break;
                        case 49: //Summon Boss
                        case 59:
                            if (pInstance->GetData(uiBossEvent) != DONE)
                            {
                                uint32 uiBossID = 0;
                                if (uiBossEvent == DATA_MEATHOOK_EVENT)
                                    uiBossID = NPC_MEATHOOK;
                                else if (uiBossEvent == DATA_SALRAMM_EVENT)
                                    uiBossID = NPC_SALRAMM;

                                if (Unit* pBoss = me->SummonCreature(uiBossID,2232.19f,1331.933f,126.662f,3.15f,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,900000))
                                {
                                    uiBossGUID = pBoss->GetGUID();
                                    pBoss->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                                    pBoss->GetMotionMaster()->MovePoint(0, 2194.110f,1332.00f,130.00f);
                                }
                            }
                            JumpToNextStep(30000);
                            break;
                        case 50: //Wait Boss death
                        case 60:
                            if (pInstance)
                            {
                                if (pInstance->GetData(uiBossEvent) == DONE)
                                {
                                    JumpToNextStep(1000);
                                    if (uiBossEvent == DATA_MEATHOOK_EVENT)
                                        uiBossEvent = DATA_SALRAMM_EVENT;
                                    else if (uiBossEvent == DATA_SALRAMM_EVENT)
                                    {
                                        SetHoldState(false);
                                        bStepping = false;
                                        uiBossEvent = DATA_EPOCH_EVENT;
                                    }
                                }
                                else if (pInstance->GetData(uiBossEvent) == FAIL)
                                    npc_escortAI::EnterEvadeMode();
                                else
                                    uiPhaseTimer = 10000;
                            }
                            break;
                        //After Gossip 2 (waypoint 22)
                        case 61:
                            me->SetReactState(REACT_AGGRESSIVE);
                            if (Creature* pDisguised0 = Unit::GetCreature(*me, uiInfiniteDraconianGUID[0]))
                                pDisguised0->SetUInt64Value(UNIT_FIELD_TARGET, me->GetGUID());
                            if (Creature* pDisguised1 = Unit::GetCreature(*me, uiInfiniteDraconianGUID[1]))
                                pDisguised1->SetUInt64Value(UNIT_FIELD_TARGET, me->GetGUID());
                            if (Creature* pDisguised2 = Unit::GetCreature(*me, uiInfiniteDraconianGUID[2]))
                                pDisguised2->SetUInt64Value(UNIT_FIELD_TARGET, me->GetGUID());
                            JumpToNextStep(1000);
                            break;
                        case 62:
                            if (Creature* pDisguised0 = Unit::GetCreature(*me, uiInfiniteDraconianGUID[0]))
                                DoScriptText(SAY_PHASE302, pDisguised0);
                            JumpToNextStep(7000);
                            break;
                        case 63:
                            DoScriptText(SAY_PHASE303, me);
                            SetHoldState(false);
                            bStepping = false;
                            JumpToNextStep(0);
                            break;
                        //After waypoint 23
                        case 64:
                            me->HandleEmoteCommand(54);
                            JumpToNextStep(1000);
                            break;
                        case 65:
                            if (Creature* pDisguised0 = Unit::GetCreature(*me, uiInfiniteDraconianGUID[0]))
                                pDisguised0->HandleEmoteCommand(11);
                            JumpToNextStep(1000);
                            break;
                        case 66:
                            DoScriptText(SAY_PHASE304,me);
                            JumpToNextStep(2000);
                            break;
                        case 67:
                            if (Creature* pDisguised0 = Unit::GetCreature(*me, uiInfiniteDraconianGUID[0]))
                                DoScriptText(SAY_PHASE305,pDisguised0);
                            JumpToNextStep(1000);
                            break;
                        case 68:
                            if (Creature* pDisguised2 = Unit::GetCreature(*me, uiInfiniteDraconianGUID[2]))
                            {
                                pDisguised2->UpdateEntry(NPC_INFINITE_HUNTER, 0);
                                //Make them unattackable
                                pDisguised2->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_UNK_9);
                                pDisguised2->SetReactState(REACT_PASSIVE);
                            }
                            JumpToNextStep(2000);
                            break;
                        case 69:
                            if (Creature* pDisguised1 = Unit::GetCreature(*me, uiInfiniteDraconianGUID[1]))
                            {
                                pDisguised1->UpdateEntry(NPC_INFINITE_AGENT, 0);
                                //Make them unattackable
                                pDisguised1->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_UNK_9);
                                pDisguised1->SetReactState(REACT_PASSIVE);
                            }
                            JumpToNextStep(2000);
                            break;
                        case 70:
                            if (Creature* pDisguised0 = Unit::GetCreature(*me, uiInfiniteDraconianGUID[0]))
                            {
                                pDisguised0->UpdateEntry(NPC_INFINITE_ADVERSARY, 0);
                                //Make them unattackable
                                pDisguised0->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_UNK_9);
                                pDisguised0->SetReactState(REACT_PASSIVE);
                            }
                            JumpToNextStep(2000);
                            break;
                        case 71:
                        //After waypoint 26,29,31
                        case 73:
                        case 75:
                        case 77:
                            //Make cratures attackable
                            for (uint32 i = 0; i< ENCOUNTER_DRACONIAN_NUMBER; ++i)
                                if (Creature* pTemp = Unit::GetCreature(*me, uiInfiniteDraconianGUID[i]))
                                {
                                    pTemp->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_UNK_9);
                                    pTemp->SetReactState(REACT_AGGRESSIVE);
                                }
                            JumpToNextStep(5000);
                            break;
                        case 72:
                        case 74:
                        case 76:
                            if (me->isInCombat())
                                uiPhaseTimer = 1000;
                            else
                            {
                                if (uiStep == 72) DoScriptText(SAY_PHASE308,me);
                                if (uiStep == 74) DoScriptText(SAY_PHASE308,me);
                                if (uiStep == 76) DoScriptText(SAY_PHASE310,me);
                                SetHoldState(false);
                                bStepping = false;
                                SetRun(true);
                                JumpToNextStep(2000);
                            }
                            break;
                        case 78:
                            if (me->isInCombat())
                                uiPhaseTimer = 1000;
                            else
                            {
                                DoScriptText(SAY_PHASE312,me);
                                JumpToNextStep(5000);
                            }
                            break;
                        case 79:
                            DoScriptText(SAY_PHASE313,me);
                            JumpToNextStep(1000);
                            break;
                        case 80:
                            if (pInstance)
                                if (pInstance->GetData(DATA_EPOCH_EVENT) != DONE)
                                {
                                    SpawnTimeRift(17,&uiEpochGUID);
                                    if (Creature* pEpoch = Unit::GetCreature(*me, uiEpochGUID))
                                        DoScriptText(SAY_PHASE314,pEpoch);
                                    me->SetUInt64Value(UNIT_FIELD_TARGET, uiEpochGUID);
                                }
                            JumpToNextStep(18000);
                            break;
                        case 81:
                            if (pInstance)
                                if (pInstance->GetData(DATA_EPOCH_EVENT) != DONE)
                                    DoScriptText(SAY_PHASE315, me);
                            JumpToNextStep(6000);
                            break;
                        case 82:
                            if (pInstance)
                                if (pInstance->GetData(DATA_EPOCH_EVENT) != DONE)
                                {
                                    if (Creature* pEpoch = Unit::GetCreature(*me, uiEpochGUID))
                                    {
                                        //Make Epoch attackable
                                        pEpoch->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_UNK_9);
                                        pEpoch->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                        pEpoch->SetReactState(REACT_AGGRESSIVE);
                                    }

                                }
                            JumpToNextStep(1000);
                            break;
                        case 83:
                            if (pInstance)
                            {
                                if (pInstance->GetData(DATA_EPOCH_EVENT) == DONE)
                                {
                                    uiGossipStep = 3;
                                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                                    bStepping = false;
                                    uiBossEvent = DATA_MAL_GANIS_EVENT;
                                    JumpToNextStep(15000);
                                }
                                else if (pInstance->GetData(DATA_EPOCH_EVENT) == FAIL)
                                    npc_escortAI::EnterEvadeMode();
                                else
                                    uiPhaseTimer = 10000;
                            }
                            break;
                        //After Gossip 4
                        case 84:
                            DoScriptText(SAY_PHASE404,me);
                            SetHoldState(false);
                            bStepping = false;
                            break;
                        //After Gossip 5
                        case 85:
                            DoScriptText(SAY_PHASE501, me);
                            if (Creature* pMalganis = me->SummonCreature(NPC_MAL_GANIS,2296.665f,1502.362f,128.362f,4.961f,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,900000))
                            {
                                uiMalganisGUID = pMalganis->GetGUID();
                                pMalganis->SetReactState(REACT_PASSIVE);
                            }
                            if (pInstance)
                                if (GameObject* pGate = pInstance->instance->GetGameObject(pInstance->GetData64(DATA_MAL_GANIS_GATE_1)))
                                    pGate->SetGoState(GO_STATE_ACTIVE);
                            SetHoldState(false);
                            bStepping = false;
                            JumpToNextStep(0);
                            break;
                        //After waypoint 55
                        case 86:
                            DoScriptText(SAY_PHASE502, me);
                            JumpToNextStep(6000);
                            me->SetUInt64Value(UNIT_FIELD_TARGET, uiMalganisGUID);
                            break;
                        case 87:
                            if (Creature* pMalganis = Unit::GetCreature(*me, uiMalganisGUID))
                            {
                                pMalganis->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_UNK_6 | UNIT_FLAG_UNK_9 | UNIT_FLAG_UNK_15);
                                pMalganis->SetReactState(REACT_AGGRESSIVE);
                            }
                            JumpToNextStep(1000);
                            break;
                        case 88:
                            if (pInstance)
                            {
                                if (pInstance->GetData(DATA_MAL_GANIS_EVENT) == DONE)
                                {
                                    SetHoldState(false);
                                    JumpToNextStep(1000);
                                }
                                else if (pInstance->GetData(DATA_MAL_GANIS_EVENT) == FAIL)
                                    npc_escortAI::EnterEvadeMode();
                                else
                                    uiPhaseTimer = 10000;
                            }
                            break;
                        //After waypoint 56
                        case 89:
                            SetRun(true);
                            me->SetUInt64Value(UNIT_FIELD_TARGET, uiMalganisGUID);
                            DoScriptText(SAY_PHASE503, me);
                            JumpToNextStep(7000);
                            break;
                        case 90:
                            if (pInstance)
                            {
                                pInstance->SetData(DATA_ARTHAS_EVENT, DONE); //Rewards: Achiev & Chest ;D
                                me->SetUInt64Value(UNIT_FIELD_TARGET, pInstance->GetData64(DATA_MAL_GANIS_GATE_2)); //Look behind
                            }
                            DoScriptText(SAY_PHASE504, me);
                            bStepping = false;
                            break;
                    }
                } else uiPhaseTimer -= diff;
            }

            //Battling skills
            if (!me->getVictim())
                return;

            if (uiExorcismTimer < diff)
            {
                if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM,0))
                    DoCast(target, SPELL_EXORCISM_N);
                uiExorcismTimer = 7300;
            } else uiExorcismTimer -= diff;

            if (HealthBelowPct(40))
                DoCast(me, SPELL_HOLY_LIGHT);
        }
    };

};

void AddSC_culling_of_stratholme()
{
    new npc_arthas();
}
