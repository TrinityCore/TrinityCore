/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedGossip.h"
#include "culling_of_stratholme.h"
#include "ScriptedEscortAI.h"
#include "PassiveAI.h"
#include "Player.h"
#include "SpellInfo.h"

enum Says
{
    //Arthas
    //First Act
    SAY_PHASE101                                = 0,
    SAY_PHASE103                                = 1,
    SAY_PHASE104                                = 2,
    SAY_PHASE106                                = 3,
    SAY_PHASE108                                = 4,
    SAY_PHASE110                                = 5,
    SAY_PHASE112                                = 6,
    SAY_PHASE114                                = 7,
    SAY_PHASE116                                = 8,
    SAY_PHASE118                                = 9,

    //Second Act - City Streets
    SAY_PHASE201                                = 10,
    SAY_PHASE203                                = 11,
    SAY_PHASE205                                = 12,
    SAY_PHASE208                                = 13,
    SAY_PHASE209                                = 14,
    SAY_PHASE210                                = 15,

    //Third Act - Town Hall
    SAY_PHASE301                                = 16,
    SAY_PHASE303                                = 17,
    SAY_PHASE304                                = 18,
    SAY_PHASE306                                = 19,
    SAY_PHASE307                                = 20,
    SAY_PHASE308                                = 21,
    SAY_PHASE309                                = 22,
    SAY_PHASE310                                = 23,
    SAY_PHASE311                                = 24,
    SAY_PHASE312                                = 25,
    SAY_PHASE313                                = 26,
    SAY_PHASE315                                = 27,

    //Fourth Act - Fire Corridor
    SAY_PHASE401                                = 28,
    SAY_PHASE402                                = 29,
    SAY_PHASE403                                = 30,
    SAY_PHASE404                                = 31,
    SAY_PHASE405                                = 32,
    SAY_PHASE406                                = 33,
    SAY_PHASE407                                = 34,

    //Fifth Act - Mal'Ganis Fight
    SAY_PHASE501                                = 35,
    SAY_PHASE502                                = 36,
    SAY_PHASE503                                = 37,
    SAY_PHASE504                                = 38,

    //Malganis
    SAY_PHASE206                                = 0,
    SAY_PHASE207                                = 1,

    //Epoch
    SAY_PHASE314                                = 0,

    //Uther
    SAY_PHASE102                                = 0,
    SAY_PHASE105                                = 1,
    SAY_PHASE107                                = 2,
    SAY_PHASE109                                = 3,
    SAY_PHASE111                                = 4,
    SAY_PHASE115                                = 5,

    //Jaina
    SAY_PHASE113                                = 0,
    SAY_PHASE117                                = 1,

    //Cityman
    SAY_PHASE202                                = 0,

    //Crazyman
    SAY_PHASE204                                = 0,

    //Drakonian
    SAY_PHASE302                                = 0,
    SAY_PHASE305                                = 1,
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
    SPELL_ARCANE_DISRUPTION                    = 49590,
};

enum GossipMenuArthas
{
   GOSSIP_MENU_ARTHAS_1                        = 100001,
   GOSSIP_MENU_ARTHAS_2                        = 100002,
   GOSSIP_MENU_ARTHAS_3                        = 100003,
   GOSSIP_MENU_ARTHAS_4                        = 100004,
   GOSSIP_MENU_ARTHAS_5                        = 100005
};

enum EncounterData
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

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();
        npc_arthasAI* ai = CAST_AI(npc_arthas::npc_arthasAI, creature->AI());

        if (!ai)
            return false;

        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF:
                ai->Start(true, true, player->GetGUID(), 0, false, false);
                ai->SetDespawnAtEnd(false);
                ai->bStepping = false;
                ai->step = 1;
                break;
            case GOSSIP_ACTION_INFO_DEF+1:
                ai->bStepping = true;
                ai->step = 24;
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                ai->SetHoldState(false);
                ai->bStepping = false;
                ai->step = 61;
                break;
            case GOSSIP_ACTION_INFO_DEF+3:
                ai->SetHoldState(false);
                break;
            case GOSSIP_ACTION_INFO_DEF+4:
                ai->bStepping = true;
                ai->step = 84;
                break;
            case GOSSIP_ACTION_INFO_DEF+5:
                ai->bStepping = true;
                ai->step = 85;
                break;
        }
        player->CLOSE_GOSSIP_MENU();
        ai->SetDespawnAtFar(true);
        creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        npc_arthasAI* ai = CAST_AI(npc_arthas::npc_arthasAI, creature->AI());

        if (ai && ai->bStepping == false)
        {
            switch (ai->gossipStep)
            {
                case 0: //This one is a workaround since the very beggining of the script is wrong.
                {
                    QuestStatus status = player->GetQuestStatus(13149);
                    if (status != QUEST_STATUS_COMPLETE && status != QUEST_STATUS_REWARDED)
                        return false;
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_ARTHAS_0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                    player->SEND_GOSSIP_MENU(907, creature->GetGUID());
                    break;
                }
                case 1:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_ARTHAS_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                    player->SEND_GOSSIP_MENU(GOSSIP_MENU_ARTHAS_1, creature->GetGUID());
                    break;
                case 2:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_ARTHAS_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                    player->SEND_GOSSIP_MENU(GOSSIP_MENU_ARTHAS_2, creature->GetGUID());
                    break;
                case 3:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_ARTHAS_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
                    player->SEND_GOSSIP_MENU(GOSSIP_MENU_ARTHAS_3, creature->GetGUID());
                    break;
                case 4:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_ARTHAS_4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
                    player->SEND_GOSSIP_MENU(GOSSIP_MENU_ARTHAS_4, creature->GetGUID());
                    break;
                case 5:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_ARTHAS_5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+5);
                    player->SEND_GOSSIP_MENU(GOSSIP_MENU_ARTHAS_5, creature->GetGUID());
                    break;
                default:
                    return false;
            }
        }
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_arthasAI>(creature);
    }

    struct npc_arthasAI : public npc_escortAI
    {
        npc_arthasAI(Creature* creature) : npc_escortAI(creature)
        {
            instance = creature->GetInstanceScript();
            Reset();
        }

        InstanceScript* instance;

        bool bStepping;
        uint32 step;
        uint32 phaseTimer;
        uint32 gossipStep;
        uint32 playerFaction;
        uint32 bossEvent;
        uint32 wave;

        uint64 utherGUID;
        uint64 jainaGUID;
        uint64 citymenGUID[2];
        uint64 waveGUID[ENCOUNTER_WAVES_MAX_SPAWNS];
        uint64 infiniteDraconianGUID[ENCOUNTER_DRACONIAN_NUMBER];
        uint64 stalkerGUID;

        uint64 bossGUID;
        uint64 epochGUID;
        uint64 malganisGUID;
        uint64 infiniteGUID;

        uint32 exorcismTimer;

        void Reset() override
        {
            utherGUID = 0;
            jainaGUID = 0;

            for (uint8 i = 0; i < 2; ++i)
                citymenGUID[i] = 0;

            for (uint8 i = 0; i < ENCOUNTER_WAVES_MAX_SPAWNS; ++i)
                waveGUID[i] = 0;

            for (uint8 i = 0; i < ENCOUNTER_DRACONIAN_NUMBER; ++i)
                infiniteDraconianGUID[i] = 0;

            stalkerGUID = 0;
            bossGUID = 0;
            epochGUID = 0;
            malganisGUID = 0;
            infiniteGUID = 0;

            instance->SetData(DATA_ARTHAS_EVENT, NOT_STARTED);
            switch (instance->GetData(DATA_ARTHAS_EVENT))
            {
                case NOT_STARTED:
                    bStepping = true;
                    step = 0;
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    bossEvent = DATA_MEATHOOK_EVENT;
                    gossipStep = 0;
                    break;
            }
            phaseTimer = 1000;
            exorcismTimer = 7300;
            wave = 0;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            DoCast(me, SPELL_ARTHAS_AURA);
        }

        void JustDied(Unit* /*killer*/) override
        {
            instance->SetData(DATA_ARTHAS_EVENT, FAIL);
        }

        void SpawnTimeRift(uint32 timeRiftID, uint64* guidVector)
        {
            me->SummonCreature((uint32)RiftAndSpawnsLocations[timeRiftID][0], RiftAndSpawnsLocations[timeRiftID][1], RiftAndSpawnsLocations[timeRiftID][2], RiftAndSpawnsLocations[timeRiftID][3], RiftAndSpawnsLocations[timeRiftID][4], TEMPSUMMON_TIMED_DESPAWN, 11000);

            for (uint32 i = timeRiftID+1; i < ENCOUNTER_CHRONO_SPAWNS; ++i)
            {
                if ((uint32)RiftAndSpawnsLocations[i][0] == NPC_TIME_RIFT) break;
                if (Creature* temp = me->SummonCreature((uint32)RiftAndSpawnsLocations[i][0], RiftAndSpawnsLocations[timeRiftID][1], RiftAndSpawnsLocations[timeRiftID][2], RiftAndSpawnsLocations[timeRiftID][3], RiftAndSpawnsLocations[timeRiftID][4], TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 900000))
                {
                    guidVector[i-timeRiftID-1] = temp->GetGUID();
                    temp->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                    temp->SetReactState(REACT_PASSIVE);
                    temp->GetMotionMaster()->MovePoint(0, RiftAndSpawnsLocations[i][1], RiftAndSpawnsLocations[i][2], RiftAndSpawnsLocations[i][3]);
                    if ((uint32)RiftAndSpawnsLocations[i][0] == NPC_EPOCH)
                        epochGUID = temp->GetGUID();
                }
            }
        }

        void SpawnWaveGroup(uint32 waveID, uint64* guidVector)
        {
            for (uint32 i = 0; i < ENCOUNTER_WAVES_MAX_SPAWNS; ++i)
            {
                if ((uint32)WavesLocations[waveID][i][0] == 0) break;
                if (Creature* temp = me->SummonCreature((uint32)WavesLocations[waveID][i][0], WavesLocations[waveID][i][1], WavesLocations[waveID][i][2], WavesLocations[waveID][i][3], WavesLocations[waveID][i][4], TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 900000))
                {
                    guidVector[i] = temp->GetGUID();
                }
            }
        }

        void SetHoldState(bool bOnHold)
        {
            SetEscortPaused(bOnHold);
        }

        void JumpToNextStep(uint32 uiTimer)
        {
            phaseTimer = uiTimer;
            ++step;
        }

        void WaypointReached(uint32 waypointId) override
        {
            switch (waypointId)
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
                    if (Unit* cityman0 = me->SummonCreature(NPC_CITY_MAN, 2091.977f, 1275.021f, 140.757f, 0.558f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 60000))
                        citymenGUID[0] = cityman0->GetGUID();
                    if (Unit* cityman1 = me->SummonCreature(NPC_CITY_MAN2, 2093.514f, 1275.842f, 140.408f, 3.801f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 60000))
                        citymenGUID[1] = cityman1->GetGUID();
                    break;
                case 8:
                    gossipStep = 1;
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    SetHoldState(true);
                    break;
                case 12:
                    SetRun(true);
                    Talk(SAY_PHASE210);
                    if (Unit* disguised0 = me->SummonCreature(NPC_CITY_MAN3, 2398.14f, 1207.81f, 134.04f, 5.155249f, TEMPSUMMON_DEAD_DESPAWN, 180000))
                    {
                        infiniteDraconianGUID[0] = disguised0->GetGUID();
                        if (Unit* disguised1 = me->SummonCreature(NPC_CITY_MAN4, 2403.22f, 1205.54f, 134.04f, 3.311264f, TEMPSUMMON_DEAD_DESPAWN, 180000))
                        {
                            infiniteDraconianGUID[1] = disguised1->GetGUID();

                            if (Unit* disguised2 = me->SummonCreature(NPC_CITY_MAN, 2400.82f, 1201.69f, 134.01f, 1.534082f, TEMPSUMMON_DEAD_DESPAWN, 180000))
                            {
                                infiniteDraconianGUID[2] = disguised2->GetGUID();
                                disguised0->SetTarget(infiniteDraconianGUID[1]);
                                disguised1->SetTarget(infiniteDraconianGUID[0]);
                                disguised2->SetTarget(infiniteDraconianGUID[1]);
                            }
                        }
                    }
                    break;
                case 20:
                    gossipStep = 2;
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    SetRun(false);
                    SetHoldState(true);
                    break;
                case 21:
                    Talk(SAY_PHASE301);
                    break;
                case 25:
                    SetRun(false);
                    SpawnTimeRift(0, &infiniteDraconianGUID[0]);
                    Talk(SAY_PHASE307);
                    break;
                case 29:
                    SetRun(false);
                    SpawnTimeRift(5, &infiniteDraconianGUID[0]);
                    SpawnTimeRift(8, &infiniteDraconianGUID[2]);
                    Talk(SAY_PHASE309);
                    SetHoldState(true);
                    bStepping = true;
                    break;
                case 31:
                    SetRun(false);
                    SpawnTimeRift(11, &infiniteDraconianGUID[0]);
                    SpawnTimeRift(14, &infiniteDraconianGUID[2]);
                    Talk(SAY_PHASE311);
                    SetHoldState(true);
                    bStepping = true;
                    break;
                case 32:
                    Talk(SAY_PHASE401);
                    break;
                case 34:
                    Talk(SAY_PHASE402);
                    break;
                case 35:
                    Talk(SAY_PHASE403);
                    break;
                case 36:
                    if (GameObject* pGate = instance->instance->GetGameObject(instance->GetData64(DATA_SHKAF_GATE)))
                        pGate->SetGoState(GO_STATE_ACTIVE);
                    break;
                case 45:
                    SetRun(true);
                    SetDespawnAtFar(false);
                    gossipStep = 4;
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    SetHoldState(true);
                    break;
                case 47:
                    SetRun(false);
                    Talk(SAY_PHASE405);
                    break;
                case 48:
                    SetRun(true);
                    Talk(SAY_PHASE406);
                    break;
                case 53:
                    Talk(SAY_PHASE407);
                    break;
                case 54:
                    gossipStep = 5;
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    SetHoldState(true);
                    break;
             }
        }

        void UpdateAI(uint32 diff) override
        {
            npc_escortAI::UpdateAI(diff);

            DoMeleeAttackIfReady();

            if (bStepping)
            {
                if (phaseTimer <= diff)
                {
                    switch (step)
                    {
                        //After reset
                        case 0:
                        {
                            Unit* jaina = GetClosestCreatureWithEntry(me, NPC_JAINA, 50.0f);
                            if (!jaina)
                                jaina = me->SummonCreature(NPC_JAINA, 1895.48f, 1292.66f, 143.706f, 0.023475f, TEMPSUMMON_DEAD_DESPAWN, 180000);
                            if (jaina)
                                jainaGUID = jaina->GetGUID();
                            bStepping = false;
                            JumpToNextStep(0);
                            break;
                        }
                        //After waypoint 0
                        case 1:
                            me->SetWalk(false);
                            if (Unit* uther = me->SummonCreature(NPC_UTHER, 1794.357f, 1272.183f, 140.558f, 1.37f, TEMPSUMMON_DEAD_DESPAWN, 180000))
                            {
                                utherGUID = uther->GetGUID();
                                uther->SetWalk(false);
                                uther->GetMotionMaster()->MovePoint(0, 1897.018f, 1287.487f, 143.481f);
                                uther->SetTarget(me->GetGUID());
                                me->SetTarget(utherGUID);
                            }
                            JumpToNextStep(17000);
                            break;
                        case 2:
                            Talk(SAY_PHASE101);
                            JumpToNextStep(2000);
                            break;
                        case 3:
                            if (Creature* uther = ObjectAccessor::GetCreature(*me, utherGUID))
                            {
                                uther->AI()->Talk(SAY_PHASE102);
                            }
                            JumpToNextStep(8000);
                            break;
                        case 4:
                            SetEscortPaused(false);
                            bStepping = false;
                            SetRun(false);
                            Talk(SAY_PHASE103);
                            JumpToNextStep(0);
                            break;
                        //After waypoint 1
                        case 5:
                            if (Creature* jaina = ObjectAccessor::GetCreature(*me, jainaGUID))
                                jaina->SetTarget(me->GetGUID());
                            Talk(SAY_PHASE104);
                            JumpToNextStep(10000);
                            break;
                        case 6:
                            if (Creature* uther = ObjectAccessor::GetCreature(*me, utherGUID))
                                uther->AI()->Talk(SAY_PHASE105);
                            JumpToNextStep(1000);
                            break;
                        case 7:
                            Talk(SAY_PHASE106);
                            JumpToNextStep(4000);
                            break;
                        case 8:
                            if (Creature* uther = ObjectAccessor::GetCreature(*me, utherGUID))
                                 uther->AI()->Talk(SAY_PHASE107);
                            JumpToNextStep(6000);
                            break;
                        case 9:
                            Talk(SAY_PHASE108);
                            JumpToNextStep(4000);
                            break;
                        case 10:
                            if (Creature* uther = ObjectAccessor::GetCreature(*me, utherGUID))
                                 uther->AI()->Talk(SAY_PHASE109);
                            JumpToNextStep(8000);
                            break;
                        case 11:
                            Talk(SAY_PHASE110);
                            JumpToNextStep(4000);
                            break;
                        case 12:
                            if (Creature* uther = ObjectAccessor::GetCreature(*me, utherGUID))
                                 uther->AI()->Talk(SAY_PHASE111);
                            JumpToNextStep(4000);
                            break;
                        case 13:
                            Talk(SAY_PHASE112);
                            JumpToNextStep(11000);
                            break;
                        case 14:
                            if (Creature* jaina = ObjectAccessor::GetCreature(*me, jainaGUID))
                                 jaina->AI()->Talk(SAY_PHASE113);
                            JumpToNextStep(3000);
                            break;
                        case 15:
                            Talk(SAY_PHASE114);
                            JumpToNextStep(9000);
                            break;
                        case 16:
                            if (Creature* uther = ObjectAccessor::GetCreature(*me, utherGUID))
                                uther->AI()->Talk(SAY_PHASE115);
                            JumpToNextStep(4000);
                            break;
                        case 17:
                            if (Creature* uther = ObjectAccessor::GetCreature(*me, utherGUID))
                            {
                                uther->SetWalk(true);
                                uther->GetMotionMaster()->MovePoint(0, 1794.357f, 1272.183f, 140.558f);
                            }
                            JumpToNextStep(1000);
                            break;
                        case 18:
                            if (Creature* jaina = ObjectAccessor::GetCreature(*me, jainaGUID))
                            {
                                me->SetTarget(jainaGUID);
                                jaina->SetWalk(true);
                                jaina->GetMotionMaster()->MovePoint(0, 1794.357f, 1272.183f, 140.558f);
                            }
                            JumpToNextStep(1000);
                            break;
                        case 19:
                            Talk(SAY_PHASE116);
                            JumpToNextStep(1000);
                            break;
                        case 20:
                            if (Creature* jaina = ObjectAccessor::GetCreature(*me, jainaGUID))
                                jaina->AI()->Talk(SAY_PHASE117);
                            JumpToNextStep(3000);
                            break;
                        case 21:
                            SetEscortPaused(false);
                            bStepping = false;
                            me->SetTarget(0);
                            JumpToNextStep(0);
                            break;
                        //After waypoint 3
                        case 22:
                            Talk(SAY_PHASE118);
                            me->SetTarget(jainaGUID);
                            JumpToNextStep(10000);
                            break;
                        case 23:
                            SetEscortPaused(false);
                            bStepping = false;
                            SetRun(true);

                            if (Creature* jaina = ObjectAccessor::GetCreature(*me, jainaGUID))
                                jaina->DisappearAndDie();

                            if (Creature* uther = ObjectAccessor::GetCreature(*me, utherGUID))
                                uther->DisappearAndDie();

                            me->SetTarget(0);
                            JumpToNextStep(0);
                            break;
                        //After Gossip 1 (waypoint 8)
                        case 24:
                            if (Unit* pStalker = me->SummonCreature(NPC_INVIS_TARGET, 2026.469f, 1287.088f, 143.596f, 1.37f, TEMPSUMMON_TIMED_DESPAWN, 14000))
                            {
                                stalkerGUID = pStalker->GetGUID();
                                me->SetTarget(stalkerGUID);
                            }
                            JumpToNextStep(1000);
                            break;
                        case 25:
                            Talk(SAY_PHASE201);
                            JumpToNextStep(12000);
                            break;
                        case 26:
                            SetEscortPaused(false);
                            bStepping = false;
                            SetRun(false);
                            me->SetTarget(0);
                            JumpToNextStep(0);
                            break;
                        //After waypoint 9
                        case 27:
                            me->SetTarget(citymenGUID[0]);
                            if (Creature* cityman = ObjectAccessor::GetCreature(*me, citymenGUID[0]))
                            {
                                cityman->SetTarget(me->GetGUID());
                                cityman->SetWalk(true);
                                cityman->GetMotionMaster()->MovePoint(0, 2088.625f, 1279.191f, 140.743f);
                            }
                            JumpToNextStep(2000);
                            break;
                        case 28:
                            if (Creature* cityman = ObjectAccessor::GetCreature(*me, citymenGUID[0]))
                                cityman->AI()->Talk(SAY_PHASE202);
                            JumpToNextStep(4000);
                            break;
                        case 29:
                            SetEscortPaused(false);
                            bStepping = false;
                            Talk(SAY_PHASE203);
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
                            if (Creature* cityman1 = ObjectAccessor::GetCreature(*me, citymenGUID[1]))
                            {
                                cityman1->AI()->Talk(SAY_PHASE204);
                                cityman1->SetTarget(me->GetGUID());
                                if (Creature* cityman0 = ObjectAccessor::GetCreature(*me, citymenGUID[0]))
                                    cityman0->Kill(cityman0);
                                me->SetTarget(citymenGUID[1]);
                            }
                            JumpToNextStep(0);
                            break;
                        //After waypoint 11
                        case 32:
                            me->HandleEmoteCommand(37);
                            JumpToNextStep(1000);
                            break;
                        case 33:
                            if (Creature* cityman1 = ObjectAccessor::GetCreature(*me, citymenGUID[1]))
                                cityman1->Kill(cityman1);
                            JumpToNextStep(1000);
                            break;
                        case 34:
                            if (Unit* pStalker = me->SummonCreature(NPC_INVIS_TARGET, 2081.447f, 1287.770f, 141.3241f, 1.37f, TEMPSUMMON_TIMED_DESPAWN, 10000))
                            {
                                stalkerGUID = pStalker->GetGUID();
                                me->SetTarget(stalkerGUID);
                            }
                            Talk(SAY_PHASE205);
                            JumpToNextStep(3000);
                            break;
                        case 35:
                            if (Unit* pStalkerM = me->SummonCreature(NPC_INVIS_TARGET, 2117.349f, 1288.624f, 136.271f, 1.37f, TEMPSUMMON_TIMED_DESPAWN, 60000))
                            {
                                stalkerGUID = pStalkerM->GetGUID();
                                me->SetTarget(stalkerGUID);
                            }
                            JumpToNextStep(1000);
                            break;
                        case 36:
                            if (Creature* malganis = me->SummonCreature(NPC_MAL_GANIS, 2117.349f, 1288.624f, 136.271f, 1.37f, TEMPSUMMON_TIMED_DESPAWN, 60000))
                            {
                                if (Creature* pStalkerM = ObjectAccessor::GetCreature(*me, stalkerGUID))
                                    malganis->CastSpell(pStalkerM, 63793, false);

                                malganisGUID = malganis->GetGUID();
                                malganis->AI()->Talk(SAY_PHASE206);
                                malganis->SetTarget(me->GetGUID());
                                malganis->SetReactState(REACT_PASSIVE);
                            }
                            JumpToNextStep(11000);
                            break;
                        case 37:
                            if (Creature* malganis = ObjectAccessor::GetCreature(*me, malganisGUID))
                            {
                                Creature* pZombie = GetClosestCreatureWithEntry(malganis, NPC_CITY_MAN, 100.0f);
                                if (!pZombie)
                                    pZombie = GetClosestCreatureWithEntry(malganis, NPC_CITY_MAN2, 100.0f);
                                if (pZombie)
                                    pZombie->UpdateEntry(NPC_ZOMBIE);
                                else //There's no one else to transform
                                    step++;
                            }
                            else
                                step++;
                            phaseTimer = 500;
                            break;
                        case 38:
                            if (Creature* malganis = ObjectAccessor::GetCreature(*me, malganisGUID))
                                malganis->AI()->Talk(SAY_PHASE207);
                            JumpToNextStep(17000);
                            break;
                        case 39:
                            if (Creature* malganis = ObjectAccessor::GetCreature(*me, malganisGUID))
                                malganis->SetVisible(false);
                            Talk(SAY_PHASE208);
                            JumpToNextStep(7000);
                            break;
                        case 40:
                            if (Unit* pStalker = me->SummonCreature(NPC_INVIS_TARGET, 2081.447f, 1287.770f, 141.3241f, 1.37f, TEMPSUMMON_TIMED_DESPAWN, 10000))
                            {
                                stalkerGUID = pStalker->GetGUID();
                                me->SetTarget(stalkerGUID);
                            }
                            Talk(SAY_PHASE209);

                            bossEvent = DATA_MEATHOOK_EVENT;
                            instance->SetData(DATA_ARTHAS_EVENT, IN_PROGRESS);

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
                            if (instance->GetData(bossEvent) != DONE)
                            {
                                SpawnWaveGroup(wave, waveGUID);
                                wave++;
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
                            if (instance->GetData(bossEvent) != DONE)
                            {
                                uint32 mobCounter = 0;
                                uint32 deadCounter = 0;
                                for (uint8 i = 0; i < ENCOUNTER_WAVES_MAX_SPAWNS; ++i)
                                {
                                    if (waveGUID[i] == 0)
                                        break;
                                    ++mobCounter;
                                    Unit* temp = ObjectAccessor::GetCreature(*me, waveGUID[i]);
                                    if (!temp || temp->isDead())
                                        ++deadCounter;
                                }

                                if (mobCounter <= deadCounter) //If group is dead
                                    JumpToNextStep(1000);
                                else
                                    phaseTimer = 1000;
                            }
                            else
                                JumpToNextStep(500);
                            break;
                        case 49: //Summon Boss
                        case 59:
                            if (instance->GetData(bossEvent) != DONE)
                            {
                                uint32 uiBossID = 0;
                                if (bossEvent == DATA_MEATHOOK_EVENT)
                                    uiBossID = NPC_MEATHOOK;
                                else if (bossEvent == DATA_SALRAMM_EVENT)
                                    uiBossID = NPC_SALRAMM;

                                if (Unit* pBoss = me->SummonCreature(uiBossID, 2232.19f, 1331.933f, 126.662f, 3.15f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 900000))
                                {
                                    bossGUID = pBoss->GetGUID();
                                    pBoss->SetWalk(true);
                                    pBoss->GetMotionMaster()->MovePoint(0, 2194.110f, 1332.00f, 130.00f);
                                }
                            }
                            JumpToNextStep(30000);
                            break;
                        case 50: //Wait Boss death
                        case 60:
                            if (instance->GetData(bossEvent) == DONE)
                            {
                                JumpToNextStep(1000);
                                if (bossEvent == DATA_MEATHOOK_EVENT)
                                    bossEvent = DATA_SALRAMM_EVENT;
                                else if (bossEvent == DATA_SALRAMM_EVENT)
                                {
                                    SetHoldState(false);
                                    bStepping = false;
                                    bossEvent = DATA_EPOCH_EVENT;
                                }
                            }
                            else if (instance->GetData(bossEvent) == FAIL)
                                npc_escortAI::EnterEvadeMode();
                            else
                                phaseTimer = 10000;
                            break;
                        //After Gossip 2 (waypoint 22)
                        case 61:
                            me->SetReactState(REACT_AGGRESSIVE);
                            if (Creature* disguised0 = ObjectAccessor::GetCreature(*me, infiniteDraconianGUID[0]))
                                disguised0->SetTarget(me->GetGUID());
                            if (Creature* disguised1 = ObjectAccessor::GetCreature(*me, infiniteDraconianGUID[1]))
                                disguised1->SetTarget(me->GetGUID());
                            if (Creature* disguised2 = ObjectAccessor::GetCreature(*me, infiniteDraconianGUID[2]))
                                disguised2->SetTarget(me->GetGUID());
                            JumpToNextStep(1000);
                            break;
                        case 62:
                            if (Creature* disguised0 = ObjectAccessor::GetCreature(*me, infiniteDraconianGUID[0]))
                                disguised0->AI()->Talk(SAY_PHASE302);
                            JumpToNextStep(7000);
                            break;
                        case 63:
                            Talk(SAY_PHASE303);
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
                            if (Creature* disguised0 = ObjectAccessor::GetCreature(*me, infiniteDraconianGUID[0]))
                                disguised0->HandleEmoteCommand(11);
                            JumpToNextStep(1000);
                            break;
                        case 66:
                            Talk(SAY_PHASE304);
                            JumpToNextStep(2000);
                            break;
                        case 67:
                            if (Creature* disguised0 = ObjectAccessor::GetCreature(*me, infiniteDraconianGUID[0]))
                                disguised0->AI()->Talk(SAY_PHASE305);
                            JumpToNextStep(1000);
                            break;
                        case 68:
                            if (Creature* disguised2 = ObjectAccessor::GetCreature(*me, infiniteDraconianGUID[2]))
                            {
                                disguised2->UpdateEntry(NPC_INFINITE_HUNTER);
                                //Make them unattackable
                                disguised2->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                                disguised2->SetReactState(REACT_PASSIVE);
                            }
                            JumpToNextStep(2000);
                            break;
                        case 69:
                            if (Creature* disguised1 = ObjectAccessor::GetCreature(*me, infiniteDraconianGUID[1]))
                            {
                                disguised1->UpdateEntry(NPC_INFINITE_AGENT);
                                //Make them unattackable
                                disguised1->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                                disguised1->SetReactState(REACT_PASSIVE);
                            }
                            JumpToNextStep(2000);
                            break;
                        case 70:
                            if (Creature* disguised0 = ObjectAccessor::GetCreature(*me, infiniteDraconianGUID[0]))
                            {
                                disguised0->UpdateEntry(NPC_INFINITE_ADVERSARY);
                                //Make them unattackable
                                disguised0->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                                disguised0->SetReactState(REACT_PASSIVE);
                            }
                            JumpToNextStep(2000);
                            break;
                        case 71:
                        //After waypoint 26, 29, 31
                        case 73:
                        case 75:
                        case 77:
                            //Make cratures attackable
                            for (uint32 i = 0; i< ENCOUNTER_DRACONIAN_NUMBER; ++i)
                                if (Creature* temp = ObjectAccessor::GetCreature(*me, infiniteDraconianGUID[i]))
                                {
                                    temp->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                                    temp->SetReactState(REACT_AGGRESSIVE);
                                }
                            JumpToNextStep(5000);
                            break;
                        case 72:
                        case 74:
                        case 76:
                            if (me->IsInCombat())
                                phaseTimer = 1000;
                            else
                            {
                                if (step == 72) Talk(SAY_PHASE308);
                                if (step == 74) Talk(SAY_PHASE308);
                                if (step == 76) Talk(SAY_PHASE310);
                                SetHoldState(false);
                                bStepping = false;
                                SetRun(true);
                                JumpToNextStep(2000);
                            }
                            break;
                        case 78:
                            if (me->IsInCombat())
                                phaseTimer = 1000;
                            else
                            {
                                Talk(SAY_PHASE312);
                                JumpToNextStep(5000);
                            }
                            break;
                        case 79:
                            Talk(SAY_PHASE313);
                            JumpToNextStep(1000);
                            break;
                        case 80:
                            if (instance->GetData(DATA_EPOCH_EVENT) != DONE)
                            {
                                SpawnTimeRift(17, &epochGUID);
                                if (Creature* epoch = ObjectAccessor::GetCreature(*me, epochGUID))
                                    epoch->AI()->Talk(SAY_PHASE314);
                                me->SetTarget(epochGUID);
                            }
                            JumpToNextStep(18000);
                            break;
                        case 81:
                            if (instance->GetData(DATA_EPOCH_EVENT) != DONE)
                                Talk(SAY_PHASE315);
                            JumpToNextStep(6000);
                            break;
                        case 82:
                            if (instance->GetData(DATA_EPOCH_EVENT) != DONE)
                            {
                                if (Creature* epoch = ObjectAccessor::GetCreature(*me, epochGUID))
                                {
                                    //Make Epoch attackable
                                    epoch->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                                    epoch->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                    epoch->SetReactState(REACT_AGGRESSIVE);
                                }

                            }
                            JumpToNextStep(1000);
                            break;
                        case 83:
                            if (instance->GetData(DATA_EPOCH_EVENT) == DONE)
                            {
                                gossipStep = 3;
                                me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                                bStepping = false;
                                bossEvent = DATA_MAL_GANIS_EVENT;
                                JumpToNextStep(15000);
                            }
                            else if (instance->GetData(DATA_EPOCH_EVENT) == FAIL)
                                npc_escortAI::EnterEvadeMode();
                            else
                                phaseTimer = 10000;
                            break;
                        //After Gossip 4
                        case 84:
                            Talk(SAY_PHASE404);
                            SetHoldState(false);
                            bStepping = false;
                            break;
                        //After Gossip 5
                        case 85:
                            Talk(SAY_PHASE501);
                            if (Creature* malganis = me->SummonCreature(NPC_MAL_GANIS, 2296.665f, 1502.362f, 128.362f, 4.961f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 900000))
                            {
                                malganisGUID = malganis->GetGUID();
                                malganis->SetReactState(REACT_PASSIVE);
                            }
                            if (GameObject* pGate = instance->instance->GetGameObject(instance->GetData64(DATA_MAL_GANIS_GATE_1)))
                                pGate->SetGoState(GO_STATE_ACTIVE);
                            SetHoldState(false);
                            bStepping = false;
                            JumpToNextStep(0);
                            break;
                        //After waypoint 55
                        case 86:
                            Talk(SAY_PHASE502);
                            JumpToNextStep(6000);
                            me->SetTarget(malganisGUID);
                            break;
                        case 87:
                            if (Creature* malganis = ObjectAccessor::GetCreature(*me, malganisGUID))
                            {
                                malganis->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNK_6 | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_UNK_15);
                                malganis->SetReactState(REACT_AGGRESSIVE);
                            }
                            JumpToNextStep(1000);
                            break;
                        case 88:
                            if (instance->GetData(DATA_MAL_GANIS_EVENT) == DONE)
                            {
                                SetHoldState(false);
                                JumpToNextStep(1000);
                            }
                            else if (instance->GetData(DATA_MAL_GANIS_EVENT) == FAIL)
                                npc_escortAI::EnterEvadeMode();
                            else
                                phaseTimer = 10000;
                            break;
                        //After waypoint 56
                        case 89:
                            SetRun(true);
                            me->SetTarget(malganisGUID);
                            Talk(SAY_PHASE503);
                            JumpToNextStep(7000);
                            break;
                        case 90:
                            instance->SetData(DATA_ARTHAS_EVENT, DONE); //Rewards: Achiev & Chest ;D
                            me->SetTarget(instance->GetData64(DATA_MAL_GANIS_GATE_2)); //Look behind
                            Talk(SAY_PHASE504);
                            bStepping = false;
                            break;
                    }
                } else phaseTimer -= diff;
            }

            //Battling skills
            if (!me->GetVictim())
                return;

            if (exorcismTimer < diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_EXORCISM_N);
                exorcismTimer = 7300;
            } else exorcismTimer -= diff;

            if (HealthBelowPct(40))
                DoCast(me, SPELL_HOLY_LIGHT);
        }
    };

};

class npc_crate_helper : public CreatureScript
{
    public:
        npc_crate_helper() : CreatureScript("npc_create_helper_cot") { }

        struct npc_crate_helperAI : public NullCreatureAI
        {
            npc_crate_helperAI(Creature* creature) : NullCreatureAI(creature)
            {
                _marked = false;
            }

            void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
            {
                if (spell->Id == SPELL_ARCANE_DISRUPTION && !_marked)
                {
                    _marked = true;
                    if (InstanceScript* instance = me->GetInstanceScript())
                        instance->SetData(DATA_CRATE_COUNT, instance->GetData(DATA_CRATE_COUNT) + 1);
                    if (GameObject* crate = me->FindNearestGameObject(GO_SUSPICIOUS_CRATE, 5.0f))
                    {
                        crate->SummonGameObject(GO_PLAGUED_CRATE, crate->GetPositionX(), crate->GetPositionY(), crate->GetPositionZ(), crate->GetOrientation(), 0.0f, 0.0f, 0.0f, 0.0f, DAY);
                        crate->Delete();
                    }
                }
            }

        private:
            bool _marked;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_crate_helperAI(creature);
        }
};

void AddSC_culling_of_stratholme()
{
    new npc_arthas();
    new npc_crate_helper();
}
