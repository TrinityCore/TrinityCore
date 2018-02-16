/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "GameObject.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "trial_of_the_champion.h"
#include "Vehicle.h"
#include "Player.h"

enum Texts
{
    // Used by announcers
    SAY_INTRO_2_E               = 0,
    SAY_INTRO_2_P               = 1,
    SAY_INTRO_1                 = 2,
    SAY_INTRO_SHAM_A            = 3,
    SAY_INTRO_MAGE_H            = 3,
    SAY_INTRO_HUN               = 4,
    SAY_INTRO_MAGE_A            = 5,
    SAY_INTRO_WARR_H            = 5,
    SAY_INTRO_WARR_A            = 6,
    SAY_INTRO_ROG_H             = 6,
    SAY_INTRO_ROG_A             = 7,
    SAY_INTRO_SHAM_H            = 7,
    SAY_INTRO_3                 = 8,
    SAY_INTRODUCE_PLR_0         = 9,
    SAY_INTRODUCE_PLR_1         = 10,
    SAY_INTRODUCE_PLR_2         = 11,
    SAY_INTRODUCE_PLR_3         = 12,
    SAY_INTRODUCE_PLR_4         = 13,

    // Used by Tirion
    SAY_TIRION_INTRO_1          = 50,
    SAY_TIRION_INTRO_2          = 51,
    SAY_TIRION_INTRO_3          = 52,
    SAY_TIRION_OUTRO_1          = 53,
    SAY_TIRION_INTRO_4          = 54,
    SAY_TIRION_INTRO_5          = 55,
    SAY_TIRION_INTRO_6          = 56,
    SAY_TIRION_OUTRO_2          = 57,
    SAY_TIRION_OUTRO_3          = 58,

    // Used by Varian
    SAY_VARIAN_INTRO_1          = 50,
    SAY_VARIAN_INTRO_2          = 52,
    SAY_VARIAN_INTRO_3          = 51,
    SAY_VARIAN_OUTRO_1          = 53,

    // Used by Garrosh
    SAY_GARROSH_INTRO_1         = 50,
    SAY_GARROSH_INTRO_2         = 52,
    SAY_GARROSH_INTRO_3         = 51,

    // Used by Jaina
    SAY_JAINA_INTRO_1           = 0,
    SAY_JAINA_INTRO_2           = 1,

    // Used by Thrall
    SAY_THRALL_INTRO_1          = 0,
    SAY_THRALL_INTRO_2          = 2,
    SAY_THRALL_OUTRO_1          = 1,

    // Used by Argent Confessor Paletress
    SAY_PALETRESS_INTRO_1       = 0,
    SAY_PALETRESS_INTRO_2       = 1,

    // Used by Eadric the Pure
    SAY_EADRIC_INTRO_1          = 0,

    // Used by The Black Knight
    SAY_KNIGHT_INTRO_1          = 0,
    SAY_KNIGHT_INTRO_2          = 1,
    SAY_KNIGHT_INTRO_3          = 2,

    // Used by spectators (same id for every spectator)
    EMOTE_SPECTATOR_CHEER       = 0
};

enum BossData
{
    BOSS_WARRIOR,
    BOSS_MAGE,
    BOSS_SHAMAN,
    BOSS_HUNTER,
    BOSS_ROGUE,
    BOSS_EADRIC,
    BOSS_PALETRESS
};

enum GossipTexts
{
    GOSSIP_TEXT_UNMOUNTED_A     = 14757,
    GOSSIP_TEXT_UNMOUNTED_H     = 15043,
    GOSSIP_TEXT_FIRST_BOSS      = 14688,
    GOSSIP_TEXT_SECOND_BOSS     = 14737,
    GOSSIP_TEXT_THIRD_BOSS      = 14738
};

enum GossipMenuOptions
{
    GOSSIP_MENU_ID              = 10614,
    GOSSIP_START_EVENT1         = 0,
    GOSSIP_START_EVENT2         = 1,
    GOSSIP_START_EVENT_SKIP     = 3,
    GOSSIP_GM_START_EVENT1      = 4,
    GOSSIP_GM_START_EVENT_SKIP1 = 5,
    GOSSIP_GM_START_EVENT2_V1	= 6,
    GOSSIP_GM_START_EVENT2_v2	= 7,
    GOSSIP_GM_START_EVENT4      = 8
};

enum Events
{
    EVENT_CHEER_RND             = 1,
    // Grand Champion - roleplaying intro
    EVENT_INTRODUCE,
    EVENT_CHAT_1,
    EVENT_CHAT_2,
    EVENT_CHAT_3,
    EVENT_CHAT_4,
    EVENT_CHAT_5,
    EVENT_CHAT_6,
    EVENT_SUMMON_1,
    EVENT_OPEN_DOOR_1,
    EVENT_INTRODUCE_BOSS_1,
    EVENT_CLOSE_DOOR_1,
    EVENT_SUMMON_2,
    EVENT_OPEN_DOOR_2,
    EVENT_INTRODUCE_BOSS_2,
    EVENT_CLOSE_DOOR_2,
    EVENT_SUMMON_3,
    EVENT_OPEN_DOOR_3,
    EVENT_INTRODUCE_BOSS_3,
    EVENT_CLOSE_DOOR_3,
    EVENT_WAIT_1,
    EVENT_FACING,
    EVENT_CHAT_7,
    EVENT_AGGRO_1,
    EVENT_CHAT_8,
    // Grand Champion - roleplaying skipped
    EVENT_CHAT_9                = 30,
    EVENT_SUMMON_1_SKIP,
    EVENT_SUMMON_2_SKIP,
    EVENT_SUMMON_3_SKIP,
    // Argent Champion
    EVENT_MOVE_MIDDLE           = 40,
    EVENT_SPAWN_ALL,
    EVENT_OPEN_DOOR_4,
    EVENT_INTRODUCE_BOSS_4,
    EVENT_ARGENT_BOSS_WALK,
    EVENT_GO_TO_ARGENT_BOSS,
    EVENT_CHAT_10,
    EVENT_CHAT_11,
    EVENT_WAIT_2,
    EVENT_CHAT_12,
    // The Black Knight
    EVENT_STEP_FORWARD          = 50,
    EVENT_CHAT_13,
    EVENT_FACING_1,
    EVENT_CHAT_14,
    EVENT_START_PATH,
    EVENT_CHAT_15,
    EVENT_FACING_2,
    EVENT_STUN_ANNOUNCER,
    EVENT_CHAT_16,
    EVENT_KNOCK_ANNOUNCER,
    EVENT_CHAT_17,
    EVENT_CHAT_18,
    EVENT_AGGRO_2,
    EVENT_CHAT_19,
    EVENT_CHAT_20,
    EVENT_CHAT_21,
    EVENT_CHAT_22
};

enum Spells
{
    // Both casted by The Black Knight to announcer
    SPELL_DEATHS_RESPITE        = 66798,
    SPELL_DEATHS_PUSH           = 66797
};

enum PointMovement
{
    POINT_ENCOUNTER_1_WAIT      = 0,
    POINT_RETURN_TO_CENTER,
    POINT_START_ARGENT_CHAMP,
    POINT_ENCOUNTER_2_WAIT_1,
    POINT_ENCOUNTER_2_WAIT_2,
    POINT_ENCOUNTER_3_WAIT
};

/*######
## npc_announcer_toc5
######*/

const Position SpawnPosition = {746.261f, 687.0f, 412.374f, 4.65f};
uint32 const IntroducePlrTxt[5] = { SAY_INTRODUCE_PLR_0, SAY_INTRODUCE_PLR_1, SAY_INTRODUCE_PLR_2, SAY_INTRODUCE_PLR_3, SAY_INTRODUCE_PLR_4 };
uint32 const SpectatorData[12] =
{
    0,
    NPC_SPECTATOR_HUMAN,
    NPC_SPECTATOR_ORC,
    NPC_SPECTATOR_DWARF,
    NPC_SPECTATOR_NELF,
    NPC_SPECTATOR_UNDEAD,
    NPC_SPECTATOR_TAUREN,
    NPC_SPECTATOR_GNOME,
    NPC_SPECTATOR_TROLL,
    0,
    NPC_SPECTATOR_BELF,
    NPC_SPECTATOR_DRAENEI
};

// Bases mostly on Joshiwald's work (big thanks)
struct GrandChampionInfo
{
    uint32 GrandChampionEntry[2];
    uint32 FactionChampionEntry[2];
    uint8 AnnounceText[2];
    uint32 GrandChampionRealEntry[2]; // used only for cheering at correct champion if event is skipped
    uint32 SpecatatorEntry[2];
};

GrandChampionInfo const GrandChampionData[5] =
{
    {
        { VEHICLE_MOKRA_SKULLCRUSHER_MOUNT,     VEHICLE_MARSHAL_JACOB_ALERIUS_MOUNT },
        { NPC_ORGRIMMAR_CHAMPION,               NPC_STORMWIND_CHAMPION              },
        { SAY_INTRO_WARR_H,                     SAY_INTRO_WARR_A                    },
        { NPC_MOKRA,                            NPC_JACOB                           },
        { SpectatorData[RACE_ORC],              SpectatorData[RACE_HUMAN]           },
    },
    {
        { VEHICLE_ERESSEA_DAWNSINGER_MOUNT,     VEHICLE_AMBROSE_BOLTSPARK_MOUNT     },
        { NPC_SILVERMOON_CHAMPION,              NPC_GNOMEREGAN_CHAMPION             },
        { SAY_INTRO_MAGE_H,                     SAY_INTRO_MAGE_A                    },
        { NPC_ERESSEA,                          NPC_AMBROSE                         },
        { SpectatorData[RACE_BLOODELF],         SpectatorData[RACE_GNOME]           },
    },
    {
        { VEHICLE_RUNOK_WILDMANE_MOUNT,         VEHICLE_COLOSOS_MOUNT               },
        { NPC_THUNDER_BLUFF_CHAMPION,           NPC_EXODAR_CHAMPION                 },
        { SAY_INTRO_SHAM_H,                     SAY_INTRO_SHAM_A                    },
        { NPC_RUNOK,                            NPC_COLOSOS                         },
        { SpectatorData[RACE_TAUREN],           SpectatorData[RACE_DRAENEI]         },
    },
    {
        { VEHICLE_ZUL_TORE_MOUNT,               VEHICLE_EVENSONG_MOUNT              },
        { NPC_SEN_JIN_CHAMPION,                 NPC_DARNASSUS_CHAMPION              },
        { SAY_INTRO_HUN,                        SAY_INTRO_HUN                       },
        { NPC_ZULTORE,                          NPC_JAELYNE                         },
        { SpectatorData[RACE_TROLL],            SpectatorData[RACE_NIGHTELF]        },
    },
    {
        { VEHICLE_DEATHSTALKER_VESCERI_MOUNT,   VEHICLE_LANA_STOUTHAMMER_MOUNT      },
        { NPC_UNDERCITY_CHAMPION,               NPC_IRONFORGE_CHAMPION              },
        { SAY_INTRO_ROG_H,                      SAY_INTRO_ROG_A                     },
        { NPC_VISCERI,                          NPC_LANA                            },
        { SpectatorData[RACE_UNDEAD_PLAYER],    SpectatorData[RACE_DWARF]           },
    }
};

class npc_announcer_toc5 : public CreatureScript
{
    public:
    npc_announcer_toc5() : CreatureScript("npc_announcer_toc5") { }

    struct npc_announcer_toc5AI : public ScriptedAI
    {
        npc_announcer_toc5AI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();

            uiSummonTimes = 0;
            uiLesserChampions = 0;

            uiFirstBoss = 0;
            uiSecondBoss = 0;
            uiThirdBoss = 0;
            uiArgentChampion = 0;

            SetCombatMovement(false);

            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            me->SetWalk(true);

            SetGrandChampionsForEncounter();
            SetArgentChampion();
        }

        InstanceScript* instance;

        uint8 uiSummonTimes;
        uint8 uiLesserChampions;

        uint32 uiFirstBoss;
        uint32 uiSecondBoss;
        uint32 uiThirdBoss;
        uint32 uiArgentChampion;

        EventMap events;

        GuidList Champion1List;
        GuidList Champion2List;
        GuidList Champion3List;
        GuidList PlayerEventList;

        void NextStep(uint32 uiTimerStep, uint32 currentEvent, bool bNextStep = true, uint8 uiPhaseStep = 0)
        {
            if (bNextStep)
                events.ScheduleEvent(currentEvent + 1, uiTimerStep);
            else
            {
                if (uiPhaseStep > 0)
                    events.ScheduleEvent(uiPhaseStep, uiTimerStep);
            }
        }

        void Reset() override
        {
            events.Reset();
            events.ScheduleEvent(EVENT_CHEER_RND, 120000);
        }

        void SetData(uint32 uiType, uint32 uiData) override
        {
            switch (uiType)
            {
                case DATA_START:
                    if (Creature* tirion = instance->GetCreature(DATA_TIRION))
                        tirion->AI()->Talk(SAY_TIRION_INTRO_1);
                    me->GetMotionMaster()->MovePoint(POINT_ENCOUNTER_1_WAIT, announcerEncounterPos);
                    NextStep(6000, 0, false, EVENT_CHAT_9);
                    break;
                case DATA_LESSER_CHAMPIONS_PREPARE:
                {
                    // Moving lesser champions to right position
                    uint32 TeamInInstance = instance->GetData(DATA_TEAM_IN_INSTANCE);
                    GuidList* TempList = nullptr;
                    uint8 x = 0;
                    switch (uiData)
                    {
                        case WAYPOINT_MAP_BOSS_1:
                            TempList = &Champion1List;
                            if (TeamInInstance == HORDE)
                                x = 9;
                            else
                                x = 0;
                            break;
                        case WAYPOINT_MAP_BOSS_2:
                            TempList = &Champion2List;
                            if (TeamInInstance == HORDE)
                                x = 12;
                            else
                                x = 3;
                            break;
                        case WAYPOINT_MAP_BOSS_3:
                            TempList = &Champion3List;
                            if (TeamInInstance == HORDE)
                                x = 15;
                            else
                                x = 6;
                            break;
                        default:
                            break;
                    }

                    for (ObjectGuid const& guid : *TempList)
                    {
                        if (Creature* add = ObjectAccessor::GetCreature(*me, guid))
                            add->AI()->SetData(DATA_GENERATE_WAYPOINTS_FOR_ADDS, x);
                        x++;
                    }
                    break;
                }
                case DATA_LESSER_CHAMPIONS_DEFEATED:
                {
                    ++uiLesserChampions;
                    GuidList TempList;
                    if (uiLesserChampions == 3 || uiLesserChampions == 6)
                    {
                        switch (uiLesserChampions)
                        {
                            case 3:
                                TempList = Champion2List;
                                break;
                            case 6:
                                TempList = Champion3List;
                                break;
                        }

                        for (GuidList::const_iterator itr = TempList.begin(); itr != TempList.end(); ++itr)
                            if (Creature* summon = ObjectAccessor::GetCreature(*me, *itr))
                                EnterAggressiveMode(summon);
                    }else if (uiLesserChampions == 9)
                        StartGrandChampionsAttack();

                    break;
                }
                case DATA_GRAND_CHAMPIONS_DONE:
                    NextStep(3000, 0, false, EVENT_CHAT_8);
                    break;
                case DATA_ARGENT_CHAMPION_PREPARE:
                    NextStep(500, 0, false, EVENT_GO_TO_ARGENT_BOSS);
                    break;
                case DATA_BLACK_KNIGHT_PREPARE:
                    NextStep(2000, 0, false, EVENT_CHAT_15);
                    break;
                case DATA_BLACK_KNIGHT_PRECAST:
                    NextStep(500, 0, false, EVENT_FACING_2);
                    break;
                case DATA_BLACK_KNIGHT_DONE:
                    NextStep(7000, 0, false, EVENT_CHAT_20);
                    break;
                default:
                    break;
            }
        }

        void StartGrandChampionsAttack()
        {
            Creature* pGrandChampion1 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GRAND_CHAMPION_VEHICLE_1));
            Creature* pGrandChampion2 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GRAND_CHAMPION_VEHICLE_2));
            Creature* pGrandChampion3 = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GRAND_CHAMPION_VEHICLE_3));
            if (pGrandChampion1 && pGrandChampion2 && pGrandChampion3)
            {
                EnterAggressiveMode(pGrandChampion1, true);
                EnterAggressiveMode(pGrandChampion2, true);
                EnterAggressiveMode(pGrandChampion3, true);
            }
        }

        void MovementInform(uint32 uiType, uint32 uiPointId) override
        {
            if (uiType != POINT_MOTION_TYPE)
                return;

            switch (uiPointId)
            {
                case POINT_ENCOUNTER_1_WAIT:
                    NextStep(500, 0, false, EVENT_WAIT_1);
                    break;
                case POINT_RETURN_TO_CENTER:
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    break;
                case POINT_START_ARGENT_CHAMP:
                    me->SetFacingTo(me->GetHomePosition().GetOrientation());
                    NextStep(500, 0, false, EVENT_SPAWN_ALL);
                    break;
                case POINT_ENCOUNTER_2_WAIT_1:
                    NextStep(500, 0, false, EVENT_WAIT_2);
                    break;
                case POINT_ENCOUNTER_2_WAIT_2:
                    me->SetFacingTo(centerOrientation);
                    NextStep(1000, 0, false, EVENT_CHAT_12);
                    break;
                case POINT_ENCOUNTER_3_WAIT:
                    me->SetFacingTo(centerOrientation);
                    NextStep(1000, 0, false, EVENT_CHAT_13);
                    break;
                default:
                    break;
            }
        }

        void DoSummonNextGrandChampion(bool skipEvent = false)
        {
            ++uiSummonTimes;
            uint32 bossId;
            switch (uiSummonTimes)
            {
                case 1:
                    bossId = uiFirstBoss;
                    break;
                case 2:
                    bossId = uiSecondBoss;
                    break;
                case 3:
                    bossId = uiThirdBoss;
                    break;
                default:
                    return;
            }

            if (bossId >= 5)
                return;

            GrandChampionInfo const* info = &GrandChampionData[bossId];
            uint32 TeamInInstance = instance->GetData(DATA_TEAM_IN_INSTANCE);
            uint32 teamIndex = TeamInInstance == HORDE ? 1 : 0;

            // Calculating spawn position for grand champion if event is skipped
            int x = uiSummonTimes - 1;
            if (TeamInInstance == HORDE)
                x += 3;

            // Grand Champions
            Position const spawnPos = skipEvent ? GrandChampFinalLoc[x] : SpawnPosition;
            if (Creature* pBoss = me->SummonCreature(info->GrandChampionEntry[teamIndex], spawnPos))
            {
                instance->SetGuidData(DATA_GRAND_CHAMPION_VEHICLE_1 + uiSummonTimes - 1, pBoss->GetGUID());

                if (!skipEvent)
                    pBoss->AI()->SetData(uiSummonTimes, TeamInInstance);
                else
                {
                    if (TeamInInstance == ALLIANCE)
                        pBoss->SetFacingTo(hordeOrientation);
                    else
                        pBoss->SetFacingTo(allianceOrientation);
                    pBoss->SetHomePosition(pBoss->GetPositionX(), pBoss->GetPositionY(), pBoss->GetPositionZ(), TeamInInstance == ALLIANCE ? hordeOrientation : allianceOrientation);

                    // Specatators cheer for champions even if event is skipped
                    if (Creature* spectator = me->FindNearestCreature(info->SpecatatorEntry[teamIndex], 200.0f))
                    {
                        if (Creature* rider = me->FindNearestCreature(info->GrandChampionRealEntry[teamIndex], 200.0f))
                            spectator->AI()->Talk(EMOTE_SPECTATOR_CHEER, rider);
                    }
                }

                // Lesser Champions
                for (uint8 i = 0; i < 3; ++i)
                {
                    // Calculating waiting positions for lesser champions if event is skipped
                    int m = (uiSummonTimes - 1) * 3 + i;
                    if (TeamInInstance == HORDE)
                        m += 9;

                    if (Creature* pAdd = me->SummonCreature(info->FactionChampionEntry[teamIndex], spawnPos, TEMPSUMMON_DEAD_DESPAWN))
                    {
                        switch (uiSummonTimes)
                        {
                            case 1:
                                Champion1List.push_back(pAdd->GetGUID());
                                break;
                            case 2:
                                Champion2List.push_back(pAdd->GetGUID());
                                break;
                            case 3:
                                Champion3List.push_back(pAdd->GetGUID());
                                break;
                            default:
                                break;
                        }

                        if (!skipEvent)
                        {
                            // Following grand champion
                            switch (i)
                            {
                                case 0:
                                    pAdd->GetMotionMaster()->MoveFollow(pBoss, 2.0f, float(M_PI));
                                    break;
                                case 1:
                                    pAdd->GetMotionMaster()->MoveFollow(pBoss, 2.0f, float(M_PI) / 2);
                                    break;
                                case 2:
                                    pAdd->GetMotionMaster()->MoveFollow(pBoss, 2.0f, float(M_PI) / 2 + float(M_PI));
                                    break;
                                default:
                                    break;
                            }
                        }
                        else
                            // Lesser Champions walk to their final positions
                            pAdd->AI()->SetData(DATA_GENERATE_WAYPOINTS_FOR_ADDS, m);
                    }
                }
            }
        }

        void DoStartArgentChampionEncounter()
        {
            // Removing vehicles (if not already been removed)
            instance->SetData(DATA_REMOVE_VEHICLES, 0);
            // Cleaning chest from arena
            if (GameObject* cache = instance->GetGameObject(DATA_CHAMPION_S_CACHE))
                cache->Delete();
            NextStep(1000, 0, false, EVENT_MOVE_MIDDLE);
        }

        void DoStartBlackKnight()
        {
            // Removing vehicles (if not already been removed)
            instance->SetData(DATA_REMOVE_VEHICLES, 0);
            // Cleaning chest from arena
            if (GameObject* cache = instance->GetGameObject(DATA_EADRIC_S_CACHE))
                cache->Delete();
            else if (GameObject* cache = instance->GetGameObject(DATA_CONFESSOR_S_CACHE))
                cache->Delete();

            NextStep(1000, 0, false, EVENT_STEP_FORWARD);
        }

        void SetGrandChampionsForEncounter()
        {
            uiFirstBoss = urand(BOSS_WARRIOR, BOSS_ROGUE);
            while (uiSecondBoss == uiFirstBoss || uiThirdBoss == uiFirstBoss || uiThirdBoss == uiSecondBoss)
            {
                uiSecondBoss = urand(BOSS_WARRIOR, BOSS_ROGUE);
                uiThirdBoss = urand(BOSS_WARRIOR, BOSS_ROGUE);
            }
        }

        void SetArgentChampion()
        {
           switch (RAND(BOSS_EADRIC, BOSS_PALETRESS))
           {
                case BOSS_EADRIC:
                    uiArgentChampion = NPC_EADRIC;
                    break;
                case BOSS_PALETRESS:
                    uiArgentChampion = NPC_PALETRESS;
                    break;
                default:
                    break;
           }
        }

        void StartEncounter(bool startRp = false)
        {
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            /// @todo: fix this ugly code
            if (instance->GetBossState(DATA_BLACK_KNIGHT) == NOT_STARTED || instance->GetBossState(DATA_BLACK_KNIGHT) == TO_BE_DECIDED)
            {
                if (instance->GetBossState(DATA_ARGENT_CHALLENGE) == NOT_STARTED || instance->GetBossState(DATA_ARGENT_CHALLENGE) == TO_BE_DECIDED)
                {
                    // Starting Grand Champion event (with roleplaying)
                    if (startRp && (instance->GetBossState(DATA_GRAND_CHAMPIONS) == NOT_STARTED || instance->GetBossState(DATA_GRAND_CHAMPIONS) == TO_BE_DECIDED))
                    {
                        Talk(SAY_INTRO_1);
                        NextStep(7000, 0, false, EVENT_INTRODUCE);
                    }

                    // Starting Grand Champion event (skipped roleplaying)
                    if (!startRp && (instance->GetBossState(DATA_GRAND_CHAMPIONS) == NOT_STARTED || instance->GetBossState(DATA_GRAND_CHAMPIONS) == TO_BE_DECIDED))
                        SetData(DATA_START, 0);

                    // Starting Argent Champion event
                    if (instance->GetBossState(DATA_GRAND_CHAMPIONS) == DONE)
                        DoStartArgentChampionEncounter();
                }

                // Starting Black Knight event
                if (instance->GetBossState(DATA_GRAND_CHAMPIONS) == DONE && instance->GetBossState(DATA_ARGENT_CHALLENGE) == DONE)
                    DoStartBlackKnight();
            }
        }

        void IntroduceChampion()
        {
            uint32 bossId;
            switch (uiSummonTimes)
            {
                case 1:
                    bossId = uiFirstBoss;
                    break;
                case 2:
                    bossId = uiSecondBoss;
                    break;
                case 3:
                    bossId = uiThirdBoss;
                    break;
                default:
                    return;
            }

            if (bossId >= 5)
                return;

            GrandChampionInfo const* info = &GrandChampionData[bossId];
            uint32 teamIndex = instance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE ? 1 : 0;

            // Introduces champion
            Talk(info->AnnounceText[teamIndex]);
            // Spectators cheer for the champion
            if (Creature* spectator = me->FindNearestCreature(info->SpecatatorEntry[teamIndex], 200.0f))
            {
                if (Creature* boss = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GRAND_CHAMPION_1 + uiSummonTimes - 1)))
                    spectator->AI()->Talk(EMOTE_SPECTATOR_CHEER, boss);
            }
        }

        void EnterAggressiveMode(Creature* temp, bool riderAlso = false)
        {
            temp->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC);
            temp->SetReactState(REACT_AGGRESSIVE);
            temp->SetWalk(false);
            Map::PlayerList const& players = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
            {
                Player* player = itr->GetSource();
                if (player && !player->IsGameMaster() && player->IsAlive())
                {
                    if (player->GetVehicleBase())
                    {
                        AddThreat(player->GetVehicleBase(), 1.0f);
                        temp->AI()->AttackStart(player->GetVehicleBase());
                    }
                    else
                    {
                        AddThreat(player, 1.0f);
                        temp->AI()->AttackStart(player);
                    }
                    break;
                }
            }
            if (riderAlso)
            {
                if (temp->GetVehicleKit() && temp->GetVehicleKit()->GetPassenger(SEAT_ID_0))
                {
                    if (Creature* rider = temp->GetVehicleKit()->GetPassenger(SEAT_ID_0)->ToCreature())
                    {
                        rider->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC);
                        rider->SetWalk(false);
                        rider->SetReactState(REACT_AGGRESSIVE);
                    }
                }
            }
        }

        void AttackStart(Unit* who) override
        {
            ScriptedAI::AttackStart(who);
            if (me->HasUnitState(UNIT_STATE_MELEE_ATTACKING))
            {
                me->ClearUnitState(UNIT_STATE_MELEE_ATTACKING);
                me->SendMeleeAttackStop(who);
            }
        }

        void UpdateAI(uint32 uiDiff) override
        {
            ScriptedAI::UpdateAI(uiDiff);
            events.Update(uiDiff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CHEER_RND:
                        if (events.GetNextEventTime() == 0 && !me->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP) && !me->isMoving() && !me->HasAura(66804))
                        {
                            // Every 2 minutes a random player is being cheered by his/her race's spectators
                            // cheer should only occur during fights
                            Map::PlayerList const &pList = me->GetMap()->GetPlayers();
                            // Player list is always in the same order so we must "randomize" it
                            if (!pList.isEmpty())
                            {
                                uint32 rand = urand(0, pList.getSize() - 1);
                                for (Map::PlayerList::const_iterator itr = pList.begin(); itr != pList.end(); ++itr)
                                {
                                    if (rand == 0)
                                    {
                                        Player* plr = itr->GetSource();
                                        if (plr && !plr->IsGameMaster() && plr->IsAlive())
                                        {
                                            // 50% chance for race cheering at you or faction cheering at you
                                            uint32 spectatorEntry = RAND(SpectatorData[plr->getRace()], uint32(instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE ? NPC_SPECTATOR_ALLIANCE : NPC_SPECTATOR_HORDE));

                                            if (Creature* spectator = me->FindNearestCreature(spectatorEntry, 200.0f))
                                                spectator->AI()->Talk(EMOTE_SPECTATOR_CHEER, plr);
                                            break;
                                        }
                                        else
                                            continue;
                                    }
                                    else
                                        --rand;
                                }
                            }
                        }
                        events.ScheduleEvent(EVENT_CHEER_RND, 120000);
                        break;
                    // Phases below happen in Grand Champions encounter
                    case EVENT_INTRODUCE:
                    {
                        // Introducing players to spectators
                        bool foundPlr = false;
                        Map::PlayerList const& players = me->GetMap()->GetPlayers();
                        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        {
                            Player* player = itr->GetSource();

                            if (player->IsGameMaster() || !player->IsAlive())
                                continue;

                            GuidList::iterator i = std::find(PlayerEventList.begin(), PlayerEventList.end(), player->GetGUID());
                            if (i != PlayerEventList.end())
                                continue;

                            // player has not been yet introduced
                            uint32 x = PlayerEventList.size();
                            if (IntroducePlrTxt[x])
                                Talk(IntroducePlrTxt[x], player);
                            else
                                continue; // no text found, too many players?

                            if (Creature* spectator = me->FindNearestCreature(SpectatorData[player->getRace()], 200.0f))
                                spectator->AI()->Talk(EMOTE_SPECTATOR_CHEER, player);

                            foundPlr = true;
                            PlayerEventList.push_back(player->GetGUID());
                            NextStep(7000, 0, false, EVENT_INTRODUCE);
                            break;
                        }
                        // All players introduced, moving on
                        if (!foundPlr)
                            NextStep(16000, eventId);
                        break;
                    }
                    case EVENT_CHAT_1:
                        if (Creature* tirion = instance->GetCreature(DATA_TIRION))
                            tirion->AI()->Talk(SAY_TIRION_INTRO_1);
                        NextStep(8000, eventId);
                        break;
                    case EVENT_CHAT_2:
                        // Tirion gets interrupted by Varian Wrynn or Garrosh Hellscream
                        if (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                        {
                            if (Creature* varian = instance->GetCreature(DATA_VARIAN))
                                varian->AI()->Talk(SAY_VARIAN_INTRO_1);
                        }
                        else
                        {
                            if (Creature* garrosh = instance->GetCreature(DATA_GARROSH))
                                garrosh->AI()->Talk(SAY_GARROSH_INTRO_1);
                        }
                        NextStep(6000, eventId);
                        break;
                    case EVENT_CHAT_3:
                        if (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                        {
                            if (Creature* jaina = instance->GetCreature(DATA_JAINA))
                                jaina->AI()->Talk(SAY_JAINA_INTRO_1);
                        }
                        else
                        {
                            if (Creature* thrall = instance->GetCreature(DATA_THRALL))
                                thrall->AI()->Talk(SAY_THRALL_INTRO_1);
                        }
                        NextStep(5000, eventId);
                        break;
                    case EVENT_CHAT_4:
                        if (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                        {
                            if (Creature* garrosh = instance->GetCreature(DATA_GARROSH))
                                garrosh->AI()->Talk(SAY_GARROSH_INTRO_2);
                        }
                        else
                        {
                            if (Creature* varian = instance->GetCreature(DATA_VARIAN))
                                varian->AI()->Talk(SAY_VARIAN_INTRO_2);
                        }
                        NextStep(8000, eventId);
                        break;
                    case EVENT_CHAT_5:
                        if (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                        {
                            if (Creature* thrall = instance->GetCreature(DATA_THRALL))
                                thrall->AI()->Talk(SAY_THRALL_INTRO_2);
                        }
                        else
                        {
                            if (Creature* jaina = instance->GetCreature(DATA_JAINA))
                                jaina->AI()->Talk(SAY_JAINA_INTRO_2);
                        }
                        NextStep(5000, eventId);
                        break;
                    case EVENT_CHAT_6:
                        if (Creature* tirion = instance->GetCreature(DATA_TIRION))
                            tirion->AI()->Talk(SAY_TIRION_INTRO_2);
                        NextStep(6000, eventId);
                        break;
                    case EVENT_SUMMON_1:
                        // Summoning first champion
                        DoSummonNextGrandChampion();
                        me->SetFacingTo(gateOrientation);
                        NextStep(2000, eventId);
                        break;
                    case EVENT_OPEN_DOOR_1:
                        // Opening doors
                        instance->HandleGameObject(instance->GetGuidData(DATA_MAIN_GATE), true);
                        NextStep(500, eventId);
                        break;
                    case EVENT_INTRODUCE_BOSS_1:
                        // Introducing first champion
                        IntroduceChampion();
                        NextStep(7500, eventId);
                        break;
                    case EVENT_CLOSE_DOOR_1:
                        // Closing door
                        instance->HandleGameObject(instance->GetGuidData(DATA_MAIN_GATE), false);
                        NextStep(8000, eventId);
                        break;
                    case EVENT_SUMMON_2:
                        // Summoning second champion
                        DoSummonNextGrandChampion();
                        NextStep(2000, eventId);
                        break;
                    case EVENT_OPEN_DOOR_2:
                        // Opening doors
                        instance->HandleGameObject(instance->GetGuidData(DATA_MAIN_GATE), true);
                        NextStep(500, eventId);
                        break;
                    case EVENT_INTRODUCE_BOSS_2:
                        // Introducing second champion
                        IntroduceChampion();
                        NextStep(7500, eventId);
                        break;
                    case EVENT_CLOSE_DOOR_2:
                        // Closing door
                        instance->HandleGameObject(instance->GetGuidData(DATA_MAIN_GATE), false);
                        NextStep(8000, eventId);
                        break;
                    case EVENT_SUMMON_3:
                        // Summoning third and final champion
                        DoSummonNextGrandChampion();
                        NextStep(2000, eventId);
                        break;
                    case EVENT_OPEN_DOOR_3:
                        // Opening doors
                        instance->HandleGameObject(instance->GetGuidData(DATA_MAIN_GATE), true);
                        NextStep(500, eventId);
                        break;
                    case EVENT_INTRODUCE_BOSS_3:
                        // Introducing third champion
                        IntroduceChampion();
                        NextStep(9500, eventId);
                        break;
                    case EVENT_CLOSE_DOOR_3:
                        // Closing door and announcer walks to the gate
                        instance->HandleGameObject(instance->GetGuidData(DATA_MAIN_GATE), false);
                        me->GetMotionMaster()->MovePoint(POINT_ENCOUNTER_1_WAIT, announcerEncounterPos);
                        NextStep(0, 0, false); // MovementInform continues from this
                        break;
                    case EVENT_WAIT_1:
                        // Lesser champions are moving to their respective positions
                        NextStep(500, eventId);
                        break;
                    case EVENT_FACING:
                        // Correcting facing
                        me->SetFacingTo(centerOrientation);
                        NextStep(5000, eventId);
                        break;
                    case EVENT_CHAT_7:
                        if (Creature* tirion = instance->GetCreature(DATA_TIRION))
                            tirion->AI()->Talk(SAY_TIRION_INTRO_3);
                        NextStep(2000, eventId);
                        break;
                    case EVENT_AGGRO_1:
                        // First wave of lesser champions aggroes
                        for (GuidList::const_iterator itr = Champion1List.begin(); itr != Champion1List.end(); ++itr)
                        {
                            if (Creature* summon = ObjectAccessor::GetCreature(*me, *itr))
                                EnterAggressiveMode(summon);
                        }
                        NextStep(0, 0, false);
                        break;
                    case EVENT_CHAT_8:
                        // Tirion congratulates players
                        if (Creature* tirion = instance->GetCreature(DATA_TIRION))
                            tirion->AI()->Talk(SAY_TIRION_OUTRO_1);
                        NextStep(0, 0, false);
                        break;
                    // Phases below happen only if roleplaying event is skipped
                    case EVENT_CHAT_9:
                        if (Creature* tirion = instance->GetCreature(DATA_TIRION))
                            tirion->AI()->Talk(SAY_TIRION_INTRO_2);
                        NextStep(3000, eventId);
                        break;
                    case EVENT_SUMMON_1_SKIP:
                        // Summoning first champion
                        DoSummonNextGrandChampion(true);
                        NextStep(2000, eventId);
                        break;
                    case EVENT_SUMMON_2_SKIP:
                        // Summoning second champion
                        DoSummonNextGrandChampion(true);
                        NextStep(2000, eventId);
                        break;
                    case EVENT_SUMMON_3_SKIP:
                        // Summoning third champion
                        DoSummonNextGrandChampion(true);
                        NextStep(0, 0, false); // MovementInform continues from this
                        break;
                    // Phases below happen in Argent Champion encounter
                    case EVENT_MOVE_MIDDLE:
                        // Moves into middle of arena
                        me->GetMotionMaster()->MovePoint(POINT_START_ARGENT_CHAMP, me->GetHomePosition());
                        NextStep(0, 0, false); // MovementInform continues from this
                        break;
                    case EVENT_SPAWN_ALL:
                        // Spawns 9 adds and boss
                        // Generating final positions for monks and other 2 adds follow the monk
                        // when monk is in final position, then final positions are generated for other adds
                        if (me->SummonCreature(uiArgentChampion, SpawnPosition))
                        {
                            for (uint8 i = 0; i < 3; ++i)
                            {
                                if (Creature* pMonk = me->SummonCreature(NPC_ARGENT_MONK, SpawnPosition))
                                {
                                    pMonk->AI()->SetData(i, 0);
                                    if (Creature* pLightwielder = me->SummonCreature(NPC_ARGENT_LIGHWIELDER, SpawnPosition))
                                    {
                                        pLightwielder->AI()->SetData(i, 0);
                                        pLightwielder->GetMotionMaster()->MoveFollow(pMonk, 2.0f, float(M_PI));
                                    }
                                    if (Creature* pPriestess = me->SummonCreature(NPC_PRIESTESS, SpawnPosition))
                                    {
                                        pPriestess->AI()->SetData(i, 0);
                                        pPriestess->GetMotionMaster()->MoveFollow(pMonk, 2.0f, float(M_PI) / 2);
                                    }
                                }
                            }
                        }
                        NextStep(2000, eventId);
                        break;
                    case EVENT_OPEN_DOOR_4:
                        // Opening doors
                        instance->HandleGameObject(instance->GetGuidData(DATA_MAIN_GATE), true);
                        NextStep(2000, eventId);
                        break;
                    case EVENT_INTRODUCE_BOSS_4:
                        // Introducing Argent Champion to spectators
                        // Horde and alliance spectators cheer for Argent Champion
                        if (Creature* pBoss = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ARGENT_CHAMPION)))
                        {
                            if (pBoss->GetEntry() == NPC_EADRIC)
                                Talk(SAY_INTRO_2_E, pBoss);
                            else
                                Talk(SAY_INTRO_2_P, pBoss);
                            if (Creature* aSpectator = me->FindNearestCreature(NPC_SPECTATOR_ALLIANCE, 200.0f))
                                aSpectator->AI()->Talk(EMOTE_SPECTATOR_CHEER, pBoss);
                            if (Creature* hSpectator = me->FindNearestCreature(NPC_SPECTATOR_HORDE, 200.0f))
                                hSpectator->AI()->Talk(EMOTE_SPECTATOR_CHEER, pBoss);
                        }
                        NextStep(10000, eventId);
                        break;
                    case EVENT_ARGENT_BOSS_WALK:
                        // Argent Champion starts walking to arena
                        if (Creature* pBoss = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ARGENT_CHAMPION)))
                        {
                            pBoss->SetWalk(true);
                            pBoss->GetMotionMaster()->MovePoint(0, 746.71f, 661.4f, 411.7f);
                        }
                        NextStep(0, 0, false);
                        break;
                    case EVENT_GO_TO_ARGENT_BOSS:
                        // Announcer starts walking to Argent Champion
                        instance->HandleGameObject(instance->GetGuidData(DATA_MAIN_GATE), false);
                        me->GetMotionMaster()->MovePoint(POINT_ENCOUNTER_2_WAIT_1, 746.73f, 653.93f, 411.6f);
                        NextStep(2000, eventId);
                        break;
                    case EVENT_CHAT_10:
                        // Argent Champion talks
                        if (Creature* pBoss = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ARGENT_CHAMPION)))
                        {
                            if (pBoss->GetEntry() == NPC_EADRIC)
                            {
                                pBoss->AI()->Talk(SAY_EADRIC_INTRO_1, me);
                                NextStep(0, 0, false);
                            }
                            else
                            {
                                pBoss->AI()->Talk(SAY_PALETRESS_INTRO_1, me);
                                NextStep(6000, eventId);
                            }
                        }
                        break;
                    case EVENT_CHAT_11:
                        // Paletress talks twice
                        if (Creature* pBoss = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ARGENT_CHAMPION)))
                        {
                            if (pBoss->GetEntry() == NPC_PALETRESS)
                                pBoss->AI()->Talk(SAY_PALETRESS_INTRO_2, me);
                            NextStep(0, 0, false);
                        }
                        break;
                    case EVENT_WAIT_2:
                        // After announcer reached position in front of Champion,
                        // he goes to encounter position
                        me->GetMotionMaster()->MovePoint(POINT_ENCOUNTER_2_WAIT_2, announcerEncounterPos);
                        NextStep(0, 0, false);
                        break;
                    case EVENT_CHAT_12:
                        if (Creature* tirion = instance->GetCreature(DATA_TIRION))
                            tirion->AI()->Talk(SAY_TIRION_INTRO_4);
                        NextStep(0, 0, false);
                        break;
                    // Phases below happen in The Black Knight encounter
                    case EVENT_STEP_FORWARD:
                        // Stepping forward
                        me->GetMotionMaster()->MovePoint(POINT_ENCOUNTER_3_WAIT, 743.65f, 627.6f, 411.17f);
                        NextStep(0, 0, false);
                        break;
                    case EVENT_CHAT_13:
                        // Tirion congratulates champions and meanwhile Black Knight appears
                        if (Creature* tirion = instance->GetCreature(DATA_TIRION))
                            tirion->AI()->Talk(SAY_TIRION_INTRO_5);
                        me->SummonCreature(VEHICLE_BLACK_KNIGHT, 780.69f, 669.61f, 463.66f, 3.77f);
                        NextStep(6000, eventId);
                        break;
                    case EVENT_FACING_1:
                        // Announcer turns towards Black Knight
                        if (Creature* knight = instance->GetCreature(DATA_BLACK_KNIGHT))
                            me->SetFacingToObject(knight);
                        NextStep(2000, eventId);
                        break;
                    case EVENT_CHAT_14:
                        // Announcer notifies everyone that something is near the rafters
                        if (Creature* knight = instance->GetCreature(DATA_BLACK_KNIGHT))
                            Talk(SAY_INTRO_3, knight);
                        NextStep(1000, eventId);
                        break;
                    case EVENT_START_PATH:
                        // Black Knight starts to fly down
                        if (Creature* knightVehicle = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_BLACK_KNIGHT_VEHICLE)))
                        {
                            knightVehicle->AI()->SetData(1, 0);
                            // We start attacking Black Knight without combat movement
                            // so we keep facing him all the time
                            if (knightVehicle->GetVehicleKit() && knightVehicle->GetVehicleKit()->GetPassenger(SEAT_ID_0))
                                AttackStart(knightVehicle->GetVehicleKit()->GetPassenger(SEAT_ID_0));
                        }
                        NextStep(0, 0, false);
                        break;
                    case EVENT_CHAT_15:
                        // Black Knight exits his vehicle and talks
                        if (Creature* knight = instance->GetCreature(DATA_BLACK_KNIGHT))
                        {
                            knight->AI()->Talk(SAY_KNIGHT_INTRO_1, me);
                            knight->ExitVehicle();
                            knight->SetWalk(true);
                            knight->GetMotionMaster()->MovePoint(0, 747.79f, 632.49f, 411.41f);
                        }
                        NextStep(0, 0, false);
                        break;
                    case EVENT_FACING_2:
                        // Black Knight corrects facing and we're stopping attacking
                        if (Creature* knight = instance->GetCreature(DATA_BLACK_KNIGHT))
                            knight->SetFacingToObject(me);
                        me->AttackStop();
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        NextStep(1500, eventId);
                        break;
                    case EVENT_STUN_ANNOUNCER:
                        // Announcer gets strangulated
                        if (Creature* knight = instance->GetCreature(DATA_BLACK_KNIGHT))
                            knight->CastSpell(me, SPELL_DEATHS_RESPITE);
                        NextStep(3000, eventId);
                        break;
                    case EVENT_CHAT_16:
                        if (Creature* tirion = instance->GetCreature(DATA_TIRION))
                            tirion->AI()->Talk(SAY_TIRION_INTRO_6, me);
                        NextStep(1000, eventId);
                        break;
                    case EVENT_KNOCK_ANNOUNCER:
                        // Announcer gets pushed to death and Black Knight's vehicle flies away
                        if (Creature* knight = instance->GetCreature(DATA_BLACK_KNIGHT))
                            knight->CastSpell(me, SPELL_DEATHS_PUSH);
                        if (Creature* knightVehicle = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_BLACK_KNIGHT_VEHICLE)))
                            knightVehicle->AI()->SetData(2, 0);
                        NextStep(3000, eventId);
                        break;
                    case EVENT_CHAT_17:
                        // Black Knight moves to center
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        if (Creature* knight = instance->GetCreature(DATA_BLACK_KNIGHT))
                        {
                            knight->AI()->Talk(SAY_KNIGHT_INTRO_2, me);
                            knight->GetMotionMaster()->MovePoint(1, 747.21f, 622.75f, 411.42f);
                        }
                        NextStep(14000, eventId);
                        break;
                    case EVENT_CHAT_18:
                        if (Creature* knight = instance->GetCreature(DATA_BLACK_KNIGHT))
                            knight->AI()->Talk(SAY_KNIGHT_INTRO_3, me);
                        NextStep(3000, eventId);
                        break;
                    case EVENT_AGGRO_2:
                        // Entering aggressive
                        if (Creature* knight = instance->GetCreature(DATA_BLACK_KNIGHT))
                        {
                            knight->SetWalk(false);
                            knight->SetHomePosition(knight->GetPosition());
                            knight->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC);
                            knight->SetReactState(REACT_AGGRESSIVE);
                        }
                        NextStep(1000, eventId);
                        break;
                    case EVENT_CHAT_19:
                        // Varian or Garrosh tells players to kill him
                        if (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                        {
                            if (Creature* varian = instance->GetCreature(DATA_VARIAN))
                                varian->AI()->Talk(SAY_VARIAN_INTRO_3, me);
                        }
                        else
                        {
                            if (Creature* garrosh = instance->GetCreature(DATA_GARROSH))
                                garrosh->AI()->Talk(SAY_GARROSH_INTRO_3, me);
                        }
                        NextStep(0, 0, false);
                        break;
                    case EVENT_CHAT_20:
                        // After Black Knight is dead, a small outro event happens
                        if (Creature* tirion = instance->GetCreature(DATA_TIRION))
                            tirion->AI()->Talk(SAY_TIRION_OUTRO_2, me);
                        NextStep(6000, eventId);
                        break;
                    case EVENT_CHAT_21:
                        if (Creature* tirion = instance->GetCreature(DATA_TIRION))
                            tirion->AI()->Talk(SAY_TIRION_OUTRO_3, me);
                        NextStep(7000, eventId);
                        break;
                    case EVENT_CHAT_22:
                        if (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                        {
                            if (Creature* varian = instance->GetCreature(DATA_VARIAN))
                                varian->AI()->Talk(SAY_VARIAN_OUTRO_1, me);
                        }
                        else
                        {
                            if (Creature* thrall = instance->GetCreature(DATA_THRALL))
                                thrall->AI()->Talk(SAY_THRALL_OUTRO_1, me);
                        }
                        NextStep(0, 0, false);
                        break;
                    default:
                        break;
                }
            }

            UpdateVictim();
        }

        bool GossipHello(Player* player) override
        {

            InstanceScript* instance = me->GetInstanceScript();
            if (instance)
            {
                /// @todo: fix this ugly code
                if (player->IsGameMaster())
                {
                    // Gamemaster mode on you can choose which encounter you start
                    // you can't though do Grand Champions encounter more than once per instance ID
                    // other encounters you can do as many times as you like
                    if ((instance->GetBossState(DATA_GRAND_CHAMPIONS) == NOT_STARTED || instance->GetBossState(DATA_GRAND_CHAMPIONS) == TO_BE_DECIDED) &&
                        (instance->GetBossState(DATA_ARGENT_CHALLENGE) == NOT_STARTED || instance->GetBossState(DATA_ARGENT_CHALLENGE) == TO_BE_DECIDED) &&
                        (instance->GetBossState(DATA_BLACK_KNIGHT) == NOT_STARTED || instance->GetBossState(DATA_BLACK_KNIGHT) == TO_BE_DECIDED))
                    {
                        AddGossipItemFor(player, GOSSIP_MENU_ID, GOSSIP_GM_START_EVENT1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                        AddGossipItemFor(player, GOSSIP_MENU_ID, GOSSIP_GM_START_EVENT_SKIP1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                    }
                    if (instance->GetBossState(DATA_ARGENT_CHALLENGE) == NOT_STARTED || instance->GetBossState(DATA_ARGENT_CHALLENGE) == TO_BE_DECIDED)
                    {
                        AddGossipItemFor(player, GOSSIP_MENU_ID, GOSSIP_GM_START_EVENT2_V1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                        AddGossipItemFor(player, GOSSIP_MENU_ID, GOSSIP_GM_START_EVENT2_v2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
                    }
                    if (instance->GetBossState(DATA_BLACK_KNIGHT) == NOT_STARTED || instance->GetBossState(DATA_BLACK_KNIGHT) == TO_BE_DECIDED)
                        AddGossipItemFor(player, GOSSIP_MENU_ID, GOSSIP_GM_START_EVENT4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
                    SendGossipMenuFor(player, 1, me->GetGUID());
                }
                else if ((instance->GetBossState(DATA_GRAND_CHAMPIONS) == NOT_STARTED || instance->GetBossState(DATA_GRAND_CHAMPIONS) == TO_BE_DECIDED) && player->GetVehicleBase())
                {
                    // If Grand Champions encounter hasn't been started and the player is mounted
                    AddGossipItemFor(player, GOSSIP_MENU_ID, GOSSIP_START_EVENT1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                    // Patch 3.2.2: "There is now an option in the herald's dialogue to skip the introductory scripted scene if everyone in the party has already seen it."
                    if (HasAllSeenEvent(player))
                        AddGossipItemFor(player, GOSSIP_MENU_ID, GOSSIP_START_EVENT_SKIP, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                    SendGossipMenuFor(player, GOSSIP_TEXT_FIRST_BOSS, me->GetGUID());
                }
                else if ((instance->GetBossState(DATA_GRAND_CHAMPIONS) == NOT_STARTED || instance->GetBossState(DATA_GRAND_CHAMPIONS) == TO_BE_DECIDED) && !player->GetVehicleBase())
                {
                    // If Grand Champions encounter hasn't been started and the player is not mounted
                    if (player->GetTeam() == HORDE)
                        SendGossipMenuFor(player, GOSSIP_TEXT_UNMOUNTED_H, me->GetGUID());
                    else
                        SendGossipMenuFor(player, GOSSIP_TEXT_UNMOUNTED_A, me->GetGUID());
                }
                else if (instance->GetBossState(DATA_GRAND_CHAMPIONS) == DONE && (instance->GetBossState(DATA_ARGENT_CHALLENGE) == NOT_STARTED || instance->GetBossState(DATA_ARGENT_CHALLENGE) == TO_BE_DECIDED))
                {
                    // If Grand Champions encounter is done and Eadric the Pure nor Argent Confessor Paletress encounters have been started
                    AddGossipItemFor(player, GOSSIP_MENU_ID, GOSSIP_START_EVENT2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                    SendGossipMenuFor(player, GOSSIP_TEXT_SECOND_BOSS, me->GetGUID());
                }
                else if (instance->GetBossState(DATA_ARGENT_CHALLENGE) == DONE && (instance->GetBossState(DATA_BLACK_KNIGHT) == NOT_STARTED || instance->GetBossState(DATA_BLACK_KNIGHT) == TO_BE_DECIDED))
                {
                    // If Grand Champions, Eadric the Pure and Argent Confessor Paletress encounters are all done but Black Knight encounter has not been started
                    AddGossipItemFor(player, GOSSIP_MENU_ID, GOSSIP_START_EVENT1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                    SendGossipMenuFor(player, GOSSIP_TEXT_THIRD_BOSS, me->GetGUID());
                }
            }
            return true;
        }

        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);
            CloseGossipMenuFor(player);
            switch (action)
            {
                case GOSSIP_ACTION_INFO_DEF + 1:
                    StartEncounter();
                    break;
                case GOSSIP_ACTION_INFO_DEF + 2:
                    StartEncounter(true);
                    break;
                case GOSSIP_ACTION_INFO_DEF + 3:
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    uiArgentChampion = NPC_EADRIC;
                    DoStartArgentChampionEncounter();
                    break;
                case GOSSIP_ACTION_INFO_DEF + 4:
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    uiArgentChampion = NPC_PALETRESS;
                    DoStartArgentChampionEncounter();
                    break;
                case GOSSIP_ACTION_INFO_DEF + 5:
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    DoStartBlackKnight();
                    break;
                default:
                    break;
            }
            return true;
        }

        bool HasAllSeenEvent(Player* player)
        {
            if (!player)
                return false;

            if (player->IsGameMaster())
                return true;

            bool seen = true;
            Map::PlayerList const& players = player->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
            {
                if (Player const *plr = itr->GetSource())
                {
                    // if everyone from your group have completed one of the Trial of the Champion achievements, you have option to skip the event
                    // maybe not the correct way to do it but I couldn't figure out better
                    if (!plr->HasAchieved(4298) /* Heroic ToC (alliance) */ && !plr->HasAchieved(3778) /* Normal ToC (horde) */ && !plr->HasAchieved(4297) /* Heroic ToC (horde) */ && !plr->HasAchieved(4296) /* Normal ToC (alliance) */)
                    {
                        seen = false;
                        break;
                    }
                }
            }
            return seen;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTrialOfChampionAI<npc_announcer_toc5AI>(creature);
    }
};

void AddSC_trial_of_the_champion()
{
    new npc_announcer_toc5();
}
