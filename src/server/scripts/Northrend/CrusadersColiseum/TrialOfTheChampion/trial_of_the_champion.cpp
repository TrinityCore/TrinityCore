/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "TemporarySummon.h"
#include "trial_of_the_champion.h"
#include "Vehicle.h"

enum Yells
{
    SAY_INTRO_1         = 0,
    SAY_INTRO_2         = 1,
    SAY_INTRO_3         = 2,
    SAY_AGGRO           = 3,
    SAY_PHASE_2         = 4,
    SAY_PHASE_3         = 5,
    SAY_KILL_PLAYER     = 6,
    SAY_DEATH           = 7
};

#define GOSSIP_START_EVENT1     "I'm ready to start challenge."
#define GOSSIP_START_EVENT2     "I'm ready for the next challenge."

#define ORIENTATION             4.714f

/*######
## npc_announcer_toc5
######*/

const Position SpawnPosition = {746.261f, 657.401f, 411.681f, 4.65f};

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

            me->SetReactState(REACT_PASSIVE);
            me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);

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

        ObjectGuid uiVehicle1GUID;
        ObjectGuid uiVehicle2GUID;
        ObjectGuid uiVehicle3GUID;

        GuidList Champion1List;
        GuidList Champion2List;
        GuidList Champion3List;

        void NextStep(uint32 uiTimerStep, bool bNextStep = true, uint8 uiPhaseStep = 0)
        {
            uiTimer = uiTimerStep;
            if (bNextStep)
                ++uiPhase;
            else
                uiPhase = uiPhaseStep;
        }

        void SetData(uint32 uiType, uint32 /*uiData*/) override
        {
            switch (uiType)
            {
                case DATA_START:
                    DoSummonGrandChampion(uiFirstBoss);
                    NextStep(10000, false, 1);
                    break;
                case DATA_IN_POSITION: //movement done.
                    me->GetMotionMaster()->MovePoint(1, 735.81f, 661.92f, 412.39f);
                    if (GameObject* go = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_MAIN_GATE)))
                        instance->HandleGameObject(go->GetGUID(), false);
                    NextStep(10000, false, 3);
                    break;
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
                                AggroAllPlayers(summon);
                    }else if (uiLesserChampions == 9)
                        StartGrandChampionsAttack();

                    break;
                }
            }
        }

        void StartGrandChampionsAttack()
        {
            Creature* pGrandChampion1 = ObjectAccessor::GetCreature(*me, uiVehicle1GUID);
            Creature* pGrandChampion2 = ObjectAccessor::GetCreature(*me, uiVehicle2GUID);
            Creature* pGrandChampion3 = ObjectAccessor::GetCreature(*me, uiVehicle3GUID);

            if (pGrandChampion1 && pGrandChampion2 && pGrandChampion3)
            {
                AggroAllPlayers(pGrandChampion1);
                AggroAllPlayers(pGrandChampion2);
                AggroAllPlayers(pGrandChampion3);
            }
        }

        void MovementInform(uint32 uiType, uint32 uiPointId) override
        {
            if (uiType != POINT_MOTION_TYPE)
                return;

            if (uiPointId == 1)
                me->SetFacingTo(ORIENTATION);
        }

        void DoSummonGrandChampion(uint32 uiBoss)
        {
            ++uiSummonTimes;
            uint32 VEHICLE_TO_SUMMON1 = 0;
            uint32 VEHICLE_TO_SUMMON2 = 0;
            switch (uiBoss)
            {
                case 0:
                    VEHICLE_TO_SUMMON1 = VEHICLE_MOKRA_SKILLCRUSHER_MOUNT;
                    VEHICLE_TO_SUMMON2 = VEHICLE_ORGRIMMAR_WOLF;
                    break;
                case 1:
                    VEHICLE_TO_SUMMON1 = VEHICLE_ERESSEA_DAWNSINGER_MOUNT;
                    VEHICLE_TO_SUMMON2 = VEHICLE_SILVERMOON_HAWKSTRIDER;
                    break;
                case 2:
                    VEHICLE_TO_SUMMON1 = VEHICLE_RUNOK_WILDMANE_MOUNT;
                    VEHICLE_TO_SUMMON2 = VEHICLE_THUNDER_BLUFF_KODO;
                    break;
                case 3:
                    VEHICLE_TO_SUMMON1 = VEHICLE_ZUL_TORE_MOUNT;
                    VEHICLE_TO_SUMMON2 = VEHICLE_DARKSPEAR_RAPTOR;
                    break;
                case 4:
                    VEHICLE_TO_SUMMON1 = VEHICLE_DEATHSTALKER_VESCERI_MOUNT;
                    VEHICLE_TO_SUMMON2 = VEHICLE_FORSAKE_WARHORSE;
                    break;
                default:
                    return;
            }

            if (Creature* pBoss = me->SummonCreature(VEHICLE_TO_SUMMON1, SpawnPosition))
            {
                switch (uiSummonTimes)
                {
                    case 1:
                    {
                        uiVehicle1GUID = pBoss->GetGUID();
                        ObjectGuid uiGrandChampionBoss1;
                        if (Vehicle* pVehicle = pBoss->GetVehicleKit())
                            if (Unit* unit = pVehicle->GetPassenger(0))
                                uiGrandChampionBoss1 = unit->GetGUID();
                        instance->SetGuidData(DATA_GRAND_CHAMPION_VEHICLE_1, uiVehicle1GUID);
                        instance->SetGuidData(DATA_GRAND_CHAMPION_1, uiGrandChampionBoss1);
                        pBoss->AI()->SetData(1, 0);
                        break;
                    }
                    case 2:
                    {
                        uiVehicle2GUID = pBoss->GetGUID();
                        ObjectGuid uiGrandChampionBoss2;
                        if (Vehicle* pVehicle = pBoss->GetVehicleKit())
                            if (Unit* unit = pVehicle->GetPassenger(0))
                                uiGrandChampionBoss2 = unit->GetGUID();
                        instance->SetGuidData(DATA_GRAND_CHAMPION_VEHICLE_2, uiVehicle2GUID);
                        instance->SetGuidData(DATA_GRAND_CHAMPION_2, uiGrandChampionBoss2);
                        pBoss->AI()->SetData(2, 0);
                        break;
                    }
                    case 3:
                    {
                        uiVehicle3GUID = pBoss->GetGUID();
                        ObjectGuid uiGrandChampionBoss3;
                        if (Vehicle* pVehicle = pBoss->GetVehicleKit())
                            if (Unit* unit = pVehicle->GetPassenger(0))
                                uiGrandChampionBoss3 = unit->GetGUID();
                        instance->SetGuidData(DATA_GRAND_CHAMPION_VEHICLE_3, uiVehicle3GUID);
                        instance->SetGuidData(DATA_GRAND_CHAMPION_3, uiGrandChampionBoss3);
                        pBoss->AI()->SetData(3, 0);
                        break;
                    }
                    default:
                        return;
                }

                for (uint8 i = 0; i < 3; ++i)
                {
                    if (Creature* pAdd = me->SummonCreature(VEHICLE_TO_SUMMON2, SpawnPosition, TEMPSUMMON_CORPSE_DESPAWN))
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
                        }

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
                        }
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
            me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);

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

        void AggroAllPlayers(Creature* temp)
        {
            Map::PlayerList const &PlList = me->GetMap()->GetPlayers();

            if (PlList.isEmpty())
                return;

            for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
            {
                if (Player* player = i->GetSource())
                {
                    if (player->IsGameMaster())
                        continue;

                    if (player->IsAlive())
                    {
                        temp->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
                        temp->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                        temp->SetReactState(REACT_AGGRESSIVE);
                        temp->SetInCombatWith(player);
                        player->SetInCombatWith(temp);
                        temp->AddThreat(player, 0.0f);
                    }
                }
            }
        }

       void UpdateAI(uint32 uiDiff) override
        {
            ScriptedAI::UpdateAI(uiDiff);

            if (uiTimer <= uiDiff)
            {
                switch (uiPhase)
                {
                    case 1:
                        DoSummonGrandChampion(uiSecondBoss);
                        NextStep(10000, true);
                        break;
                    case 2:
                        DoSummonGrandChampion(uiThirdBoss);
                        NextStep(0, false);
                        break;
                    case 3:
                        if (!Champion1List.empty())
                        {
                            for (GuidList::const_iterator itr = Champion1List.begin(); itr != Champion1List.end(); ++itr)
                                if (Creature* summon = ObjectAccessor::GetCreature(*me, *itr))
                                    AggroAllPlayers(summon);
                            NextStep(0, false);
                        }
                        break;
                }
            } else uiTimer -= uiDiff;

            if (!UpdateVictim())
                return;
        }

        void JustSummoned(Creature* summon) override
        {
            if (instance->GetData(BOSS_GRAND_CHAMPIONS) == NOT_STARTED)
            {
                summon->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                summon->SetReactState(REACT_PASSIVE);
            }
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            switch (summon->GetEntry())
            {
                case VEHICLE_DARNASSIA_NIGHTSABER:
                case VEHICLE_EXODAR_ELEKK:
                case VEHICLE_STORMWIND_STEED:
                case VEHICLE_GNOMEREGAN_MECHANOSTRIDER:
                case VEHICLE_IRONFORGE_RAM:
                case VEHICLE_FORSAKE_WARHORSE:
                case VEHICLE_THUNDER_BLUFF_KODO:
                case VEHICLE_ORGRIMMAR_WOLF:
                case VEHICLE_SILVERMOON_HAWKSTRIDER:
                case VEHICLE_DARKSPEAR_RAPTOR:
                    SetData(DATA_LESSER_CHAMPIONS_DEFEATED, 0);
                    break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTrialOfTheChampionAI<npc_announcer_toc5AI>(creature);
    }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        InstanceScript* instance = creature->GetInstanceScript();

        if (instance &&
            ((instance->GetData(BOSS_GRAND_CHAMPIONS) == DONE &&
            instance->GetData(BOSS_BLACK_KNIGHT) == DONE &&
            instance->GetData(BOSS_ARGENT_CHALLENGE_E) == DONE) ||
            instance->GetData(BOSS_ARGENT_CHALLENGE_P) == DONE))
            return false;

        if (instance &&
            instance->GetData(BOSS_GRAND_CHAMPIONS) == NOT_STARTED &&
            instance->GetData(BOSS_ARGENT_CHALLENGE_E) == NOT_STARTED &&
            instance->GetData(BOSS_ARGENT_CHALLENGE_P) == NOT_STARTED &&
            instance->GetData(BOSS_BLACK_KNIGHT) == NOT_STARTED)
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_START_EVENT1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        else if (instance)
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_START_EVENT2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        SendGossipMenuFor(player, player->GetGossipTextId(creature), creature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        ClearGossipMenuFor(player);
        if (action == GOSSIP_ACTION_INFO_DEF+1)
        {
            CloseGossipMenuFor(player);
            ENSURE_AI(npc_announcer_toc5::npc_announcer_toc5AI, creature->AI())->StartEncounter();
        }

        return true;
    }
};

void AddSC_trial_of_the_champion()
{
    new npc_announcer_toc5();
}
