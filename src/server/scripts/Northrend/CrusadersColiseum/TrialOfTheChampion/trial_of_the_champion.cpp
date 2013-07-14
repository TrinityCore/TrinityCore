/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

            uiVehicle1GUID = 0;
            uiVehicle2GUID = 0;
            uiVehicle3GUID = 0;

            Champion1List.clear();
            Champion2List.clear();
            Champion3List.clear();

            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

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

        uint64 uiVehicle1GUID;
        uint64 uiVehicle2GUID;
        uint64 uiVehicle3GUID;

        uint64 uiGrandChampionBoss1;

        std::list<uint64> Champion1List;
        std::list<uint64> Champion2List;
        std::list<uint64> Champion3List;

        void NextStep(uint32 uiTimerStep, bool bNextStep = true, uint8 uiPhaseStep = 0)
        {
            uiTimer = uiTimerStep;
            if (bNextStep)
                ++uiPhase;
            else
                uiPhase = uiPhaseStep;
        }

        void SetData(uint32 uiType, uint32 /*uiData*/) OVERRIDE
        {
            switch (uiType)
            {
                case DATA_START:
                    DoSummonGrandChampion(uiFirstBoss);
                    NextStep(10000, false, 1);
                    break;
                case DATA_IN_POSITION: //movement done.
                    me->GetMotionMaster()->MovePoint(1, 735.81f, 661.92f, 412.39f);
                    if (GameObject* go = GameObject::GetGameObject(*me, instance->GetData64(DATA_MAIN_GATE)))
                        instance->HandleGameObject(go->GetGUID(), false);
                    NextStep(10000, false, 3);
                    break;
                case DATA_LESSER_CHAMPIONS_DEFEATED:
                {
                    ++uiLesserChampions;
                    std::list<uint64> TempList;
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

                        for (std::list<uint64>::const_iterator itr = TempList.begin(); itr != TempList.end(); ++itr)
                            if (Creature* summon = Unit::GetCreature(*me, *itr))
                                AggroAllPlayers(summon);
                    }else if (uiLesserChampions == 9)
                        StartGrandChampionsAttack();

                    break;
                }
            }
        }

        void StartGrandChampionsAttack()
        {
            Creature* pGrandChampion1 = Unit::GetCreature(*me, uiVehicle1GUID);
            Creature* pGrandChampion2 = Unit::GetCreature(*me, uiVehicle2GUID);
            Creature* pGrandChampion3 = Unit::GetCreature(*me, uiVehicle3GUID);

            if (pGrandChampion1 && pGrandChampion2 && pGrandChampion3)
            {
                AggroAllPlayers(pGrandChampion1);
                AggroAllPlayers(pGrandChampion2);
                AggroAllPlayers(pGrandChampion3);
            }
        }

        void MovementInform(uint32 uiType, uint32 uiPointId) OVERRIDE
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
                        uint64 uiGrandChampionBoss1 = 0;
                        if (Vehicle* pVehicle = pBoss->GetVehicleKit())
                            if (Unit* unit = pVehicle->GetPassenger(0))
                                uiGrandChampionBoss1 = unit->GetGUID();
                        if (instance)
                        {
                            instance->SetData64(DATA_GRAND_CHAMPION_VEHICLE_1, uiVehicle1GUID);
                            instance->SetData64(DATA_GRAND_CHAMPION_1, uiGrandChampionBoss1);
                        }
                        pBoss->AI()->SetData(1, 0);
                        break;
                    }
                    case 2:
                    {
                        uiVehicle2GUID = pBoss->GetGUID();
                        uint64 uiGrandChampionBoss2 = 0;
                        if (Vehicle* pVehicle = pBoss->GetVehicleKit())
                            if (Unit* unit = pVehicle->GetPassenger(0))
                                uiGrandChampionBoss2 = unit->GetGUID();
                        if (instance)
                        {
                            instance->SetData64(DATA_GRAND_CHAMPION_VEHICLE_2, uiVehicle2GUID);
                            instance->SetData64(DATA_GRAND_CHAMPION_2, uiGrandChampionBoss2);
                        }
                        pBoss->AI()->SetData(2, 0);
                        break;
                    }
                    case 3:
                    {
                        uiVehicle3GUID = pBoss->GetGUID();
                        uint64 uiGrandChampionBoss3 = 0;
                        if (Vehicle* pVehicle = pBoss->GetVehicleKit())
                            if (Unit* unit = pVehicle->GetPassenger(0))
                                uiGrandChampionBoss3 = unit->GetGUID();
                        if (instance)
                        {
                            instance->SetData64(DATA_GRAND_CHAMPION_VEHICLE_3, uiVehicle3GUID);
                            instance->SetData64(DATA_GRAND_CHAMPION_3, uiGrandChampionBoss3);
                        }
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
                                pAdd->GetMotionMaster()->MoveFollow(pBoss, 2.0f, M_PI);
                                break;
                            case 1:
                                pAdd->GetMotionMaster()->MoveFollow(pBoss, 2.0f, M_PI / 2);
                                break;
                            case 2:
                                pAdd->GetMotionMaster()->MoveFollow(pBoss, 2.0f, M_PI / 2 + M_PI);
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
            if (!instance)
                return;

            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

            if (instance->GetData(BOSS_BLACK_KNIGHT) == NOT_STARTED)
            {
                if (instance->GetData(BOSS_ARGENT_CHALLENGE_E) == NOT_STARTED && instance->GetData(BOSS_ARGENT_CHALLENGE_P) == NOT_STARTED)
                {
                    if (instance->GetData(BOSS_GRAND_CHAMPIONS) == NOT_STARTED)
                        me->AI()->SetData(DATA_START, 0);

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
                        temp->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        temp->SetReactState(REACT_AGGRESSIVE);
                        temp->SetInCombatWith(player);
                        player->SetInCombatWith(temp);
                        temp->AddThreat(player, 0.0f);
                    }
                }
            }
        }

       void UpdateAI(uint32 uiDiff) OVERRIDE
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
                            for (std::list<uint64>::const_iterator itr = Champion1List.begin(); itr != Champion1List.end(); ++itr)
                                if (Creature* summon = Unit::GetCreature(*me, *itr))
                                    AggroAllPlayers(summon);
                            NextStep(0, false);
                        }
                        break;
                }
            } else uiTimer -= uiDiff;

            if (!UpdateVictim())
                return;
        }

        void JustSummoned(Creature* summon) OVERRIDE
        {
            if (instance && instance->GetData(BOSS_GRAND_CHAMPIONS) == NOT_STARTED)
            {
                summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                summon->SetReactState(REACT_PASSIVE);
            }
        }

        void SummonedCreatureDespawn(Creature* summon) OVERRIDE
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
                    me->AI()->SetData(DATA_LESSER_CHAMPIONS_DEFEATED, 0);
                    break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_announcer_toc5AI(creature);
    }

    bool OnGossipHello(Player* player, Creature* creature) OVERRIDE
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
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_START_EVENT1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        else if (instance)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_START_EVENT2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) OVERRIDE
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF+1)
        {
            player->CLOSE_GOSSIP_MENU();
            CAST_AI(npc_announcer_toc5::npc_announcer_toc5AI, creature->AI())->StartEncounter();
        }

        return true;
    }
};

void AddSC_trial_of_the_champion()
{
    new npc_announcer_toc5();
}
