/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

/* ScriptData
SDName: Trial Of the Champion
SD%Complete:
SDComment:
SDCategory: trial_of_the_champion
EndScriptData */

/* ContentData
npc_announcer_toc5
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "trial_of_the_champion.h"
#include "Vehicle.h"
#include "Player.h"

#define GOSSIP_START_EVENT1     "I am ready."
#define GOSSIP_START_EVENT2     "I am ready for the next challenge."
#define GOSSIP_START_EVENT_SKIP "I am ready. However I'd like to skip the pageantry."

#define ORIENTATION             4.714f
#define ORIENTATION_2           1.582f

enum Texts
{
    // Used by announcer
    SAY_INTRO_2_E = 0,
    SAY_INTRO_2_P = 1,
    SAY_INTRO_1 = 2,
    SAY_INTRO_SHAM_A = 3,
    SAY_INTRO_MAGE_H = 3,
    SAY_INTRO_HUN = 4,
    SAY_INTRO_MAGE_A = 5,
    SAY_INTRO_WARR_H = 5,
    SAY_INTRO_WARR_A = 6,
    SAY_INTRO_ROG_H = 6,
    SAY_INTRO_ROG_A = 7,
    SAY_INTRO_SHAM_H = 7,
    SAY_INTRO_3 = 8,
    SAY_INTRODUCE_PLR_0 = 9,
    SAY_INTRODUCE_PLR_1 = 10,
    SAY_INTRODUCE_PLR_2 = 11,
    SAY_INTRODUCE_PLR_3 = 12,
    SAY_INTRODUCE_PLR_4 = 13,

    // Used by Tirion
    SAY_TIRION_INTRO_1 = 50,
    SAY_TIRION_INTRO_2 = 51,
    SAY_TIRION_INTRO_3 = 52,

    // Used by Varian
    SAY_VARIAN_INTRO_1 = 50,
    SAY_VARIAN_INTRO_2 = 52,

    // Used by Garrosh
    SAY_GARROSH_INTRO_1 = 50,
    SAY_GARROSH_INTRO_2 = 52,

    // Used by Jaina
    SAY_JAINA_INTRO_1 = 0,
    SAY_JAINA_INTRO_2 = 1,

    // Used by Thrall
    SAY_THRALL_INTRO_1 = 0,
    SAY_THRALL_INTRO_2 = 2,

    // Used by spectators (same id for every spectator)
    EMOTE_SPECTATOR = 0
};

/*######
## npc_announcer_toc5
######*/

const Position SpawnPosition = {746.261f, 687.0f, 412.374f, 4.65f};
uint32 const IntroducePlrTxt[5] = { SAY_INTRODUCE_PLR_0, SAY_INTRODUCE_PLR_1, SAY_INTRODUCE_PLR_2, SAY_INTRODUCE_PLR_3, SAY_INTRODUCE_PLR_4 };

uint32 const IntroduceChampInfo[10][4] =
{
    /*  Structure:
    BossId  Player's Team  TextId  SpectatorId         */
    { 0, ALLIANCE, SAY_INTRO_WARR_H, NPC_SPECTATOR_ORC },
    { 0, HORDE, SAY_INTRO_WARR_A, NPC_SPECTATOR_HUMAN },
    { 1, ALLIANCE, SAY_INTRO_MAGE_H, NPC_SPECTATOR_BELF },
    { 1, HORDE, SAY_INTRO_MAGE_A, NPC_SPECTATOR_GNOME },
    { 2, ALLIANCE, SAY_INTRO_SHAM_H, NPC_SPECTATOR_TAUREN },
    { 2, HORDE, SAY_INTRO_SHAM_A, NPC_SPECTATOR_DRAENEI },
    { 3, ALLIANCE, SAY_INTRO_HUN, NPC_SPECTATOR_TROLL },
    { 3, HORDE, SAY_INTRO_HUN, NPC_SPECTATOR_NELF },
    { 4, ALLIANCE, SAY_INTRO_ROG_H, NPC_SPECTATOR_UNDEAD },
    { 4, HORDE, SAY_INTRO_ROG_A, NPC_SPECTATOR_DWARF }
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
            uiPosition = 0;
            uiLesserChampions = 0;

            uiFirstBoss = 0;
            uiSecondBoss = 0;
            uiThirdBoss = 0;

            uiArgentChampion = 0;

            uiPhase = 0;
            uiTimer = 0;
            uiBoss = 0;

            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            me->SetWalk(true);

            SetGrandChampionsForEncounter();
            SetArgentChampion();
        }

        InstanceScript* instance;

        uint8 uiSummonTimes;
        uint8 uiPosition;
        uint8 uiLesserChampions;

        uint32 uiArgentChampion;

        uint32 uiFirstBoss;
        uint32 uiSecondBoss;
        uint32 uiThirdBoss;

        uint32 uiPhase;
        uint32 uiTimer;
        uint32 uiBoss;

        uint32 GrandChampionList[3];
        GuidList Champion1List;
        GuidList Champion2List;
        GuidList Champion3List;
        GuidList PlayerEventList;

        void NextStep(uint32 uiTimerStep, bool bNextStep = true, uint8 uiPhaseStep = 0)
        {
            uiTimer = uiTimerStep;
            if (bNextStep)
                ++uiPhase;
            else
                uiPhase = uiPhaseStep;
        }

        void SetData(uint32 uiType, uint32 uiData) override
        {
            switch (uiType)
            {
                case DATA_START:
                    if (Creature* tirion = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_TIRION)))
                        tirion->AI()->Talk(SAY_TIRION_INTRO_1);
                    me->GetMotionMaster()->MovePoint(2, 732.5243f, 663.007f, 412.3932f);
                    NextStep(2000, false, 30);
                    break;
                case DATA_LESSER_CHAMPIONS_PREPARE:
                {
                    // Moving lesser champions to right position
                    uint32 TeamInInstance = instance->GetData(DATA_PLAYERS_TEAM);
                    GuidList TempList;
                    uint8 x;
                    switch (uiData)
                    {
                        case WAYPOINT_MAP_BOSS_1:
                            TempList = Champion1List;
                            if (TeamInInstance == HORDE)
                                x = 9;
                            else
                                x = 0;
                            break;
                        case WAYPOINT_MAP_BOSS_2:
                            TempList = Champion2List;
                            if (TeamInInstance == HORDE)
                                x = 12;
                            else
                                x = 3;
                            break;
                        case WAYPOINT_MAP_BOSS_3:
                            TempList = Champion3List;
                            if (TeamInInstance == HORDE)
                                x = 15;
                            else
                                x = 6;
                            break;
                        default:
                            break;
                    }

                    for (GuidList::const_iterator itr = TempList.begin(); itr != TempList.end(); ++itr)
                    {
                        if (Creature* add = ObjectAccessor::GetCreature(*me, *itr))
                            add->AI()->SetData(4, x);
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

            if (uiPointId == 1)
                me->SetFacingTo(ORIENTATION);
            else if (uiPointId == 2)
                NextStep(500, false, 20);
        }

        void DoSummonNextGrandChampion(bool skipEvent = false)
        {
            ++uiSummonTimes;
            uint32 VEHICLE_TO_SUMMON1 = 0;
            uint32 VEHICLE_TO_SUMMON2 = 0;
            uint32 TeamInInstance = instance->GetData(DATA_PLAYERS_TEAM);

            // should not happen
            if (uiSummonTimes > 3)
                return;

            switch (GrandChampionList[uiBoss-1])
            {
                case 0:
                    if (TeamInInstance == ALLIANCE)
                    {
                        VEHICLE_TO_SUMMON1 = VEHICLE_MOKRA_SKILLCRUSHER_MOUNT;
                        VEHICLE_TO_SUMMON2 = VEHICLE_ORGRIMMAR_CHAMPION;
                    }
                    else
                    {
                        VEHICLE_TO_SUMMON1 = VEHICLE_MARSHAL_JACOB_ALERIUS_MOUNT;
                        VEHICLE_TO_SUMMON2 = VEHICLE_STORMWIND_CHAMPION;
                    }
                    break;
                case 1:
                    if (TeamInInstance == ALLIANCE)
                    {
                        VEHICLE_TO_SUMMON1 = VEHICLE_ERESSEA_DAWNSINGER_MOUNT;
                        VEHICLE_TO_SUMMON2 = VEHICLE_SILVERMOON_CHAMPION;
                    }
                    else
                    {
                        VEHICLE_TO_SUMMON1 = VEHICLE_AMBROSE_BOLTSPARK_MOUNT;
                        VEHICLE_TO_SUMMON2 = VEHICLE_GNOMEREGAN_CHAMPION;
                    }
                    break;
                case 2:
                    if (TeamInInstance == ALLIANCE)
                    {
                        VEHICLE_TO_SUMMON1 = VEHICLE_RUNOK_WILDMANE_MOUNT;
                        VEHICLE_TO_SUMMON2 = VEHICLE_THUNDER_BLUFF_CHAMPION;
                    }
                    else
                    {
                        VEHICLE_TO_SUMMON1 = VEHICLE_COLOSOS_MOUNT;
                        VEHICLE_TO_SUMMON2 = VEHICLE_EXODAR_CHAMPION;
                    }
                    break;
                case 3:
                    if (TeamInInstance == ALLIANCE)
                    {
                        VEHICLE_TO_SUMMON1 = VEHICLE_ZUL_TORE_MOUNT;
                        VEHICLE_TO_SUMMON2 = VEHICLE_SENJIN_CHAMPION;
                    }
                    else
                    {
                        VEHICLE_TO_SUMMON1 = VEHICLE_EVENSONG_MOUNT;
                        VEHICLE_TO_SUMMON2 = VEHICLE_DARNASSUS_CHAMPION;
                    }
                    break;
                case 4:
                    if (TeamInInstance == ALLIANCE)
                    {
                        VEHICLE_TO_SUMMON1 = VEHICLE_DEATHSTALKER_VESCERI_MOUNT;
                        VEHICLE_TO_SUMMON2 = VEHICLE_UNDERCITY_CHAMPION;
                    }
                    else
                    {
                        VEHICLE_TO_SUMMON1 = VEHICLE_LANA_STOUTHAMMER_MOUNT;
                        VEHICLE_TO_SUMMON2 = VEHICLE_IRONFORGE_CHAMPION;
                    }
                    break;
                default:
                    return;
            }

            if (!skipEvent)
            {
                if (Creature* pBoss = me->SummonCreature(VEHICLE_TO_SUMMON1, SpawnPosition))
                {
                    if (uiSummonTimes == 1)
                        instance->SetGuidData(DATA_GRAND_CHAMPION_VEHICLE_1, pBoss->GetGUID());
                    else if (uiSummonTimes == 2)
                        instance->SetGuidData(DATA_GRAND_CHAMPION_VEHICLE_2, pBoss->GetGUID());
                    else if (uiSummonTimes == 3)
                        instance->SetGuidData(DATA_GRAND_CHAMPION_VEHICLE_3, pBoss->GetGUID());
                    pBoss->AI()->SetData(uiSummonTimes, TeamInInstance);

                    for (uint8 i = 0; i < 3; ++i)
                    {
                        if (Creature* pAdd = me->SummonCreature(VEHICLE_TO_SUMMON2, SpawnPosition, TEMPSUMMON_DEAD_DESPAWN))
                        {
                            if (uiSummonTimes == 1)
                                Champion1List.push_back(pAdd->GetGUID());
                            else if (uiSummonTimes == 2)
                                Champion2List.push_back(pAdd->GetGUID());
                            else if (uiSummonTimes == 3)
                                Champion3List.push_back(pAdd->GetGUID());

                            if (i == 0)
                                pAdd->GetMotionMaster()->MoveFollow(pBoss, 2.0f, float(M_PI));
                            else if (i == 1)
                                pAdd->GetMotionMaster()->MoveFollow(pBoss, 2.0f, float(M_PI) / 2);
                            else if (i == 2)
                                pAdd->GetMotionMaster()->MoveFollow(pBoss, 2.0f, float(M_PI) / 2 + float(M_PI));
                        }
                    }
                }
            }
            else
            {
                // Grand Champion
                int x = uiSummonTimes - 1;
                if (TeamInInstance == HORDE)
                    x += 3;

                if (Creature* pBoss = me->SummonCreature(VEHICLE_TO_SUMMON1, GrandChampFinalLoc[x]))
                {
                    if (uiSummonTimes == 1)
                        instance->SetGuidData(DATA_GRAND_CHAMPION_VEHICLE_1, pBoss->GetGUID());
                    else if (uiSummonTimes == 2)
                        instance->SetGuidData(DATA_GRAND_CHAMPION_VEHICLE_2, pBoss->GetGUID());
                    else if (uiSummonTimes == 3)
                        instance->SetGuidData(DATA_GRAND_CHAMPION_VEHICLE_3, pBoss->GetGUID());

                    if (TeamInInstance == ALLIANCE)
                        pBoss->SetFacingTo(hordeOrientation);
                    else
                        pBoss->SetFacingTo(allianceOrientation);
                }

                // Lesser Champions
                for (uint8 i = 0; i < 3; ++i)
                {
                    int m = (uiSummonTimes - 1) * 3 + i; // magic number
                    if (TeamInInstance == HORDE)
                        m += 9;
                    if (Creature* pAdd = me->SummonCreature(VEHICLE_TO_SUMMON2, LesserChampLoc[m], TEMPSUMMON_DEAD_DESPAWN))
                    {
                        if (uiSummonTimes == 1)
                            Champion1List.push_back(pAdd->GetGUID());
                        else if (uiSummonTimes == 2)
                            Champion2List.push_back(pAdd->GetGUID());
                        else if (uiSummonTimes == 3)
                            Champion3List.push_back(pAdd->GetGUID());

                        if (TeamInInstance == ALLIANCE)
                            pAdd->SetFacingTo(hordeOrientation);
                        else
                            pAdd->SetFacingTo(allianceOrientation);
                    }
                }
            }
        }

        void DoStartArgentChampionEncounter()
        {
            me->GetMotionMaster()->MovePoint(1, 735.81f, 661.92f, 412.39f);

            if (me->SummonCreature(uiArgentChampion, SpawnPosition))
            {
                for (uint8 i = 0; i < 3; ++i)
                {
                    if (Creature* pTrash = me->SummonCreature(NPC_ARGENT_LIGHWIELDER, SpawnPosition))
                        pTrash->AI()->SetData(i, 0);
                    if (Creature* pTrash = me->SummonCreature(NPC_ARGENT_MONK, SpawnPosition))
                        pTrash->AI()->SetData(i, 0);
                    if (Creature* pTrash = me->SummonCreature(NPC_PRIESTESS, SpawnPosition))
                        pTrash->AI()->SetData(i, 0);
                }
            }
        }

        void SetGrandChampionsForEncounter()
        {
            uiFirstBoss = urand(0, 4);
            while (uiSecondBoss == uiFirstBoss || uiThirdBoss == uiFirstBoss || uiThirdBoss == uiSecondBoss)
            {
                uiSecondBoss = urand(0, 4);
                uiThirdBoss = urand(0, 4);
            }

            GrandChampionList[0] = uiFirstBoss;
            GrandChampionList[1] = uiSecondBoss;
            GrandChampionList[2] = uiThirdBoss;
        }

        void SetArgentChampion()
        {
           uint8 uiTempBoss = urand(0, 1);

           switch (uiTempBoss)
           {
                case 0:
                    uiArgentChampion = NPC_EADRIC;
                    break;
                case 1:
                    uiArgentChampion = NPC_PALETRESS;
                    break;
           }
        }

        void StartEncounter()
        {
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

            if (instance->GetData(BOSS_BLACK_KNIGHT) == NOT_STARTED)
            {
                if (instance->GetData(BOSS_ARGENT_CHALLENGE_E) == NOT_STARTED && instance->GetData(BOSS_ARGENT_CHALLENGE_P) == NOT_STARTED)
                {
                    if (instance->GetData(BOSS_GRAND_CHAMPIONS) == NOT_STARTED)
                        SetData(DATA_START, 0);

                    if (instance->GetData(BOSS_GRAND_CHAMPIONS) == DONE)
                        DoStartArgentChampionEncounter();
                }

               if ((instance->GetData(BOSS_GRAND_CHAMPIONS) == DONE &&
                   instance->GetData(BOSS_ARGENT_CHALLENGE_E) == DONE) ||
                   instance->GetData(BOSS_ARGENT_CHALLENGE_P) == DONE)
                    me->SummonCreature(VEHICLE_BLACK_KNIGHT, 769.834f, 651.915f, 447.035f, 0);
            }
        }

        void StartRpEvent()
        {
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            me->AI()->Talk(SAY_INTRO_1);
            NextStep(7000, false, 1);
        }

        void IntroduceChampion()
        {
            uint32 TeamInInstance = instance->GetData(DATA_PLAYERS_TEAM);
            for (int i = 0; i < 10; i++)
            {
                if (IntroduceChampInfo[i] && IntroduceChampInfo[i][0] == GrandChampionList[uiBoss - 1] && IntroduceChampInfo[i][1] == TeamInInstance)
                {
                    uint32 textId = IntroduceChampInfo[i][2];
                    uint32 spectatorId = IntroduceChampInfo[i][3];

                    me->AI()->Talk(textId);
                    if (Creature* spectator = me->FindNearestCreature(spectatorId, 100.0f))
                    {
                        if (uiSummonTimes == 1)
                        {
                            if (Creature* boss = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GRAND_CHAMPION_1)))
                                spectator->AI()->Talk(EMOTE_SPECTATOR, boss);
                        }
                        else if (uiSummonTimes == 2)
                        {
                            if (Creature* boss = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GRAND_CHAMPION_2)))
                                spectator->AI()->Talk(EMOTE_SPECTATOR, boss);
                        }
                        else if (uiSummonTimes == 3)
                        {
                            if (Creature* boss = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GRAND_CHAMPION_3)))
                                spectator->AI()->Talk(EMOTE_SPECTATOR, boss);
                        }
                    }
                }
            }
        }

        void EnterAggressiveMode(Creature* temp, bool riderAlso = false)
        {
            temp->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC);
            temp->SetReactState(REACT_AGGRESSIVE);
            temp->SetWalk(false);
            temp->GetMotionMaster()->MovePoint(0, me->GetHomePosition());
            if (riderAlso)
            {
                if (temp->GetVehicleKit())
                {
                    if (Unit* rider = temp->GetVehicleKit()->GetPassenger(0))
                    {
                        rider->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC);
                        rider->SetWalk(false);
                        if (rider->ToCreature())
                            rider->ToCreature()->SetReactState(REACT_AGGRESSIVE);
                    }
                }
            }
        }

       void UpdateAI(uint32 uiDiff) override
        {
            ScriptedAI::UpdateAI(uiDiff);
            if (uiTimer <= uiDiff)
            {
                Map::PlayerList const &pList = me->GetMap()->GetPlayers();
                uint32 TeamInInstance = instance->GetData(DATA_PLAYERS_TEAM);

                switch (uiPhase)
                {
                    case 1: // Introducing players to spectators
                    {
                        bool foundPlr = false;
                        for (Map::PlayerList::const_iterator itr = pList.begin(); itr != pList.end(); ++itr)
                        {
                            if (Player* plr = itr->GetSource())
                            {
                                if (plr->IsGameMaster() || !plr->IsAlive())
                                    continue;

                                std::list<ObjectGuid>::iterator i = std::find(PlayerEventList.begin(), PlayerEventList.end(), plr->GetGUID());
                                if (i != PlayerEventList.end())
                                    continue;

                                // player has not been yet introduced
                                uint32 x = PlayerEventList.size();
                                if (IntroducePlrTxt[x])
                                    me->AI()->Talk(IntroducePlrTxt[x], plr);
                                else
                                    continue; // no text found, too many players?

                                uint32 spectatorId = 0;
                                switch (plr->getRace())
                                {
                                    case RACE_HUMAN:
                                        spectatorId = NPC_SPECTATOR_HUMAN;
                                        break;
                                    case RACE_ORC:
                                        spectatorId = NPC_SPECTATOR_ORC;
                                        break;
                                    case RACE_DWARF:
                                        spectatorId = NPC_SPECTATOR_DWARF;
                                        break;
                                    case RACE_NIGHTELF:
                                        spectatorId = NPC_SPECTATOR_NELF;
                                        break;
                                    case RACE_UNDEAD_PLAYER:
                                        spectatorId = NPC_SPECTATOR_UNDEAD;
                                        break;
                                    case RACE_TAUREN:
                                        spectatorId = NPC_SPECTATOR_TAUREN;
                                        break;
                                    case RACE_GNOME:
                                        spectatorId = NPC_SPECTATOR_GNOME;
                                        break;
                                    case RACE_TROLL:
                                        spectatorId = NPC_SPECTATOR_TROLL;
                                        break;
                                    case RACE_BLOODELF:
                                        spectatorId = NPC_SPECTATOR_BELF;
                                        break;
                                    case RACE_DRAENEI:
                                        spectatorId = NPC_SPECTATOR_DRAENEI;
                                        break;
                                    default:
                                        break;
                                }

                                if (Creature* spectator = me->FindNearestCreature(spectatorId, 100.0f))
                                    spectator->AI()->Talk(EMOTE_SPECTATOR, plr);

                                foundPlr = true;
                                PlayerEventList.push_back(plr->GetGUID());
                                NextStep(7000, false, 1);
                                break;
                            }
                        }

                        // All players introduced, moving on
                        if (!foundPlr)
                            NextStep(16000);

                        break;
                    }
                    // Tirion gets interrupted by Varian Wrynn or Garrosh Hellscream
                    case 2:
                        if (Creature* tirion = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_TIRION)))
                            tirion->AI()->Talk(SAY_TIRION_INTRO_1);
                        NextStep(8000);
                        break;
                    case 3:
                        if (TeamInInstance == ALLIANCE)
                        {
                            if (Creature* varian = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_VARIAN)))
                                varian->AI()->Talk(SAY_VARIAN_INTRO_1);
                        }
                        else
                        {
                            if (Creature* garrosh = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GARROSH)))
                                garrosh->AI()->Talk(SAY_GARROSH_INTRO_1);
                        }
                        NextStep(6000);
                        break;
                    case 4:
                        if (TeamInInstance == ALLIANCE)
                        {
                            if (Creature* jaina = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_JAINA)))
                                jaina->AI()->Talk(SAY_JAINA_INTRO_1);
                        }
                        else
                        {
                            if (Creature* thrall = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_THRALL)))
                                thrall->AI()->Talk(SAY_THRALL_INTRO_1);
                        }
                        NextStep(5000);
                        break;
                    case 5:
                        if (TeamInInstance == ALLIANCE)
                        {
                            if (Creature* garrosh = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GARROSH)))
                                garrosh->AI()->Talk(SAY_GARROSH_INTRO_2);
                        }
                        else
                        {
                            if (Creature* varian = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_VARIAN)))
                                varian->AI()->Talk(SAY_VARIAN_INTRO_2);
                        }
                        NextStep(8000);
                        break;
                    case 6:
                        if (TeamInInstance == ALLIANCE)
                        {
                            if (Creature* thrall = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_THRALL)))
                                thrall->AI()->Talk(SAY_THRALL_INTRO_2);
                        }
                        else
                        {
                            if (Creature* jaina = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_JAINA)))
                                jaina->AI()->Talk(SAY_JAINA_INTRO_2);
                        }
                        NextStep(5000);
                        break;
                    case 7:
                        if (Creature* tirion = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_TIRION)))
                            tirion->AI()->Talk(SAY_TIRION_INTRO_2);
                        NextStep(6000);
                        break;
                    case 8:
                        // Summoning first champion
                        uiBoss = 1;
                        DoSummonNextGrandChampion();
                        me->SetFacingTo(ORIENTATION_2);
                        NextStep(2000);
                        break;
                    case 9:
                        // Opening doors
                        if (GameObject* gate = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_MAIN_GATE)))
                            instance->HandleGameObject(gate->GetGUID(), true);
                        NextStep(500);
                        break;
                    case 10:
                        // Introducing first champion
                        IntroduceChampion();
                        NextStep(7500);
                        break;
                    case 11:
                        // Closing door
                        if (GameObject* gate = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_MAIN_GATE)))
                            instance->HandleGameObject(gate->GetGUID(), false);
                        NextStep(8000);
                        break;
                    case 12:
                        // Summoning second champion
                        uiBoss = 2;
                        DoSummonNextGrandChampion();
                        NextStep(2000);
                        break;
                    case 13:
                        // Opening doors
                        if (GameObject* gate = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_MAIN_GATE)))
                            instance->HandleGameObject(gate->GetGUID(), true);
                        NextStep(500);
                        break;
                    case 14:
                        // Introducing second champion
                        IntroduceChampion();
                        NextStep(7500);
                        break;
                    case 15:
                        // Closing door
                        if (GameObject* gate = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_MAIN_GATE)))
                            instance->HandleGameObject(gate->GetGUID(), false);
                        NextStep(8000);
                        break;
                    case 16:
                        // Summoning third and final champion
                        uiBoss = 3;
                        DoSummonNextGrandChampion();
                        NextStep(2000);
                        break;
                    case 17:
                        // Opening doors
                        if (GameObject* gate = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_MAIN_GATE)))
                            instance->HandleGameObject(gate->GetGUID(), true);
                        NextStep(500);
                        break;
                    case 18:
                        // Introducing third champion
                        IntroduceChampion();
                        NextStep(9500);
                        break;
                    case 19:
                        // Closing door and announcer walks to the gate
                        if (GameObject* gate = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_MAIN_GATE)))
                            instance->HandleGameObject(gate->GetGUID(), false);

                        me->GetMotionMaster()->MovePoint(2, 732.5243f, 663.007f, 412.3932f);
                        NextStep(0, false);
                        break;
                    case 20:
                        // Lesser champions are moving to their respective positions
                        NextStep(500);
                        break;
                    case 21:
                        // Correcting facing
                        me->SetFacingTo(ORIENTATION);
                        if (TeamInInstance == ALLIANCE)
                            NextStep(2000);
                        else // Alliance champions are slower to correct their positions
                            NextStep(5000);
                        break;
                    case 22:
                        // First wave of lesser champions aggroes
                        if (Creature* tirion = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_TIRION)))
                            tirion->AI()->Talk(SAY_TIRION_INTRO_3);

                        for (GuidList::const_iterator itr = Champion1List.begin(); itr != Champion1List.end(); ++itr)
                            if (Creature* summon = ObjectAccessor::GetCreature(*me, *itr))
                                EnterAggressiveMode(summon);
                        NextStep(0, false);
                        break;
                    // Phases below happens only if event is skipped
                    case 30:
                        // Summoning first champion
                        uiBoss = 1;
                        DoSummonNextGrandChampion(true);
                        NextStep(4000);
                        break;
                    case 31:
                        // Summoning second champion
                        uiBoss = 2;
                        DoSummonNextGrandChampion(true);
                        NextStep(4000);
                        break;
                    case 32:
                        // Summoning third champion
                        if (Creature* tirion = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_TIRION)))
                            tirion->AI()->Talk(SAY_TIRION_INTRO_2);
                        uiBoss = 3;
                        DoSummonNextGrandChampion(true);
                        NextStep(0, false); // MovementInform continues from this
                        break;
                }
            } else uiTimer -= uiDiff;

            if (!UpdateVictim())
                return;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_announcer_toc5AI>(creature);
    }

    bool HasAllSeenEvent(Player* player)
    {
        if (!player)
            return false;

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

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        InstanceScript* instance = creature->GetInstanceScript();

        // TODO: put gossip menu texts into database, I just don't know how to play with conditions
        // Gossip menus are already set, conditions are only missing
        // - Appled
        if (instance)
        {
            if (instance->GetData(BOSS_GRAND_CHAMPIONS) == NOT_STARTED && (player->GetVehicleBase() || player->IsGameMaster())) // Game Master mode enabled you can skip the roleplaying event
            {
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_START_EVENT1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                // Patch 3.2.2: "There is now an option in the herald's dialogue to skip the introductory scripted scene if everyone in the party has already seen it."
                if (HasAllSeenEvent(player))
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_START_EVENT_SKIP, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                player->SEND_GOSSIP_MENU(14688, creature->GetGUID());
            }
            else if (instance->GetData(BOSS_GRAND_CHAMPIONS) == NOT_STARTED && !player->GetVehicleBase())
            {
                if (player->GetTeam() == HORDE)
                    player->SEND_GOSSIP_MENU(15043, creature->GetGUID());
                else
                    player->SEND_GOSSIP_MENU(14757, creature->GetGUID());
            }
            else if (instance->GetData(BOSS_GRAND_CHAMPIONS) == DONE && instance->GetData(BOSS_ARGENT_CHALLENGE_E) == NOT_STARTED && instance->GetData(BOSS_ARGENT_CHALLENGE_P) == NOT_STARTED)
            {
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_START_EVENT2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                player->SEND_GOSSIP_MENU(14737, creature->GetGUID());
            }
            else if ((instance->GetData(BOSS_ARGENT_CHALLENGE_E) == DONE || instance->GetData(BOSS_ARGENT_CHALLENGE_P) == DONE) && instance->GetData(BOSS_BLACK_KNIGHT) == NOT_STARTED)
            {
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_START_EVENT1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                player->SEND_GOSSIP_MENU(14738, creature->GetGUID());
            }
        }
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        ClearGossipMenuFor(player);
        if (action == GOSSIP_ACTION_INFO_DEF + 1)
        {
            CloseGossipMenuFor(player);
            ENSURE_AI(npc_announcer_toc5::npc_announcer_toc5AI, creature->AI())->StartEncounter();
        }
        else if (action == GOSSIP_ACTION_INFO_DEF + 2)
        {
            player->CLOSE_GOSSIP_MENU();
            ENSURE_AI(npc_announcer_toc5::npc_announcer_toc5AI, creature->AI())->StartRpEvent();
        }

        return true;
    }
};

void AddSC_trial_of_the_champion()
{
    new npc_announcer_toc5();
}
