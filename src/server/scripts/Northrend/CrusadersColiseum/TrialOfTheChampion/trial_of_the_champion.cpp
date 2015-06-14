/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
    ANNOUNCER_INTRO = 0,
    ANNOUNCER_MAGE,
    ANNOUNCER_SHAMAN,
    ANNOUNCER_HUNTER,
    ANNOUNCER_WARRIOR,
    ANNOUNCER_ROUGUE,
    ANNOUNCER_EADRIC,
    ANNOUNCER_PELETRESS,
    ANNOUNCER_BLACK_KNIGHT,

    TIRION_CHAMPIONS_INTRO = 50,
    TIRION_CHAMPIONS_INTRO_1,
    TIRION_CHAMPIONS_INTRO_2,
    TIRION_ARGENT_INTRO,
    TIRION_ARGENT_INTRO_1,
    TIRION_KNIGHT_INTRO,
    TIRION_KNIGHT_INTRO_1,

    VARIAN_INTRO_A = 50,
    VARIAN_INTRO_H,
    VARIAN_KNIGHT_INTRO,
    VARIAN_KNIGHT_OUTRO,

    GARROSH_INTRO_A = 50,
    GARROSH_INTRO_H,
    GARROSH_KNIGHT_INTRO,
    GARROSH_KNIGHT_OUTRO,

    JAINA_INTRO_A = 0,
    JAINA_INTRO_H,

    THRALL_INTRO_A = 0,
    THRALL_INTRO_H,

    BLACK_KNIGHT_INTRO = 0,
    BLACK_KNIGHT_INTRO_1,
    BLACK_KNIGHT_INTRO_2
};

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
                    NextStep(3000, false, 1);
                    break;
                case DATA_IN_POSITION: //movement done.
                    me->GetMotionMaster()->MovePoint(1, 735.81f, 661.92f, 412.39f);
                    if (GameObject* go = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_MAIN_GATE)))
                        instance->HandleGameObject(go->GetGUID(), false);
                    NextStep(10000, false, 11);
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
                    VEHICLE_TO_SUMMON2 = NPC_ORGRIMMAR_CHAMPION;
                    break;
                    Talk(ANNOUNCER_WARRIOR);
                case 1:
                    VEHICLE_TO_SUMMON1 = VEHICLE_ERESSEA_DAWNSINGER_MOUNT;
                    VEHICLE_TO_SUMMON2 = NPC_SILVERMOON_CHAMPION;
                    Talk(ANNOUNCER_MAGE);
                    break;
                case 2:
                    VEHICLE_TO_SUMMON1 = VEHICLE_RUNOK_WILDMANE_MOUNT;
                    VEHICLE_TO_SUMMON2 = NPC_THUNDERBLUFF_CHAMPION;
                    Talk(ANNOUNCER_SHAMAN);
                    break;
                case 3:
                    VEHICLE_TO_SUMMON1 = VEHICLE_ZUL_TORE_MOUNT;
                    VEHICLE_TO_SUMMON2 = NPC_SENJIN_CHAMPION;
                    Talk(ANNOUNCER_HUNTER);
                    break;
                case 4:
                    VEHICLE_TO_SUMMON1 = VEHICLE_DEATHSTALKER_VESCERI_MOUNT;
                    VEHICLE_TO_SUMMON2 = NPC_UNDERCITY_CHAMPION;
                    Talk(ANNOUNCER_ROUGUE);
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
                        instance->SetGuidData(DATA_GRAND_CHAMPION_VEHICLE_1, uiVehicle1GUID);
                        pBoss->AI()->SetData(1, 0);
                        break;
                    }
                    case 2:
                    {
                        uiVehicle2GUID = pBoss->GetGUID();
                        instance->SetGuidData(DATA_GRAND_CHAMPION_VEHICLE_2, uiVehicle2GUID);
                        pBoss->AI()->SetData(2, 0);
                        break;
                    }
                    case 3:
                    {
                        uiVehicle3GUID = pBoss->GetGUID();
                        instance->SetGuidData(DATA_GRAND_CHAMPION_VEHICLE_3, uiVehicle3GUID);
                        pBoss->AI()->SetData(3, 0);
                        break;
                    }
                    default:
                        return;
                }

                for (uint8 i = 0; i < 3; ++i)
                {
                    if (Creature* pAdd = me->SummonCreature(VEHICLE_TO_SUMMON2, SpawnPosition))
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

            if (Creature* champion = me->SummonCreature(uiArgentChampion, SpawnPosition))
            {
                if (champion->GetEntry() == NPC_EADRIC)
                    Talk(ANNOUNCER_EADRIC);
                else
                    Talk(ANNOUNCER_PELETRESS);

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
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

            if (instance->GetBossState(BOSS_BLACK_KNIGHT) != DONE)
            {
                if (instance->GetBossState(BOSS_ARGENT_CHALLENGE_E) != DONE && instance->GetBossState(BOSS_ARGENT_CHALLENGE_P) != DONE)
                {
                    if (instance->GetBossState(BOSS_GRAND_CHAMPIONS) != DONE)
                        SetData(DATA_START, 0);

                    if (instance->GetBossState(BOSS_GRAND_CHAMPIONS) == DONE)
                        NextStep(2000, false, 12);
                }

                if ((instance->GetBossState(BOSS_GRAND_CHAMPIONS) == DONE &&
                    instance->GetBossState(BOSS_ARGENT_CHALLENGE_E) == DONE) ||
                    instance->GetBossState(BOSS_ARGENT_CHALLENGE_P) == DONE)
                    NextStep(2000, false, 15);
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

       void UpdateAI(uint32 diff) override
        {
            ScriptedAI::UpdateAI(diff);

            if (uiTimer <= diff)
            {
                switch (uiPhase)
                {
                case 1:
                    Talk(ANNOUNCER_INTRO);
                    NextStep(5000, true);
                    break;
                case 2: // missing solo text?  Words can scarce describe the deeds that this $class has performed on the battefield. We are proud to present $name.   Emote clap from gnomes(alliance).
                    if (Creature* tirion = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_TIRION)))
                        tirion->AI()->Talk(TIRION_CHAMPIONS_INTRO);
                    NextStep(4000, true);
                    break;
                case 3:
                    if (instance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE)
                    {
                        if (Creature* thrall = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_THRALL)))
                            thrall->AI()->Talk(THRALL_INTRO_H);
                    }
                    else
                        if (Creature* varian = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_VARIAN)))
                            varian->AI()->Talk(VARIAN_INTRO_A);
                    NextStep(3000, true);
                    break;
                case 4:
                    if (instance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE)
                    {
                        if (Creature* garrosh = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GARROSH)))
                            garrosh->AI()->Talk(GARROSH_INTRO_H);
                    }
                    else
                        if (Creature* jaina = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_JAINA)))
                            jaina->AI()->Talk(JAINA_INTRO_A);
                    NextStep(3000, true);
                    break;
                case 5:
                    if (instance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE)
                    {
                        if (Creature* varian = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_VARIAN)))
                            varian->AI()->Talk(VARIAN_INTRO_H);
                    }
                    else
                        if (Creature* garrosh = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GARROSH)))
                            garrosh->AI()->Talk(GARROSH_INTRO_A);
                    NextStep(3000, true);
                    break;
                case 6:
                    if (instance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE)
                    {
                        if (Creature* jaina = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_JAINA)))
                            jaina->AI()->Talk(JAINA_INTRO_H);
                    }
                    else
                        if (Creature* thrall = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_THRALL)))
                            thrall->AI()->Talk(THRALL_INTRO_A);
                    NextStep(3000, true);
                    break;
                case 7:
                    if (Creature* tirion = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_TIRION)))
                        tirion->AI()->Talk(TIRION_CHAMPIONS_INTRO_1);
                    NextStep(6000, true);
                    break;
                case 8:
                    DoSummonGrandChampion(uiFirstBoss);
                    NextStep(10000, true);
                    break;
                case 9:
                    DoSummonGrandChampion(uiSecondBoss);
                    NextStep(10000, true);
                    break;
                case 10:
                    DoSummonGrandChampion(uiThirdBoss);
                    NextStep(0, false);
                    break;
                case 11:
                    if (!Champion1List.empty())
                    {
                        for (GuidList::const_iterator itr = Champion1List.begin(); itr != Champion1List.end(); ++itr)
                            if (Creature* summon = ObjectAccessor::GetCreature(*me, *itr))
                                AggroAllPlayers(summon);
                        NextStep(0, false);
                    }
                    break;
                case 12: // Argent
                    if (Creature* tirion = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_TIRION)))
                        tirion->AI()->Talk(TIRION_ARGENT_INTRO);
                    NextStep(3000, true);
                    break;
                case 13:
                    if (Creature* tirion = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_TIRION)))
                        tirion->AI()->Talk(TIRION_ARGENT_INTRO_1);
                    NextStep(3000, true);
                    break;
                case 14:
                    DoStartArgentChampionEncounter();
                    NextStep(0, false);
                    break;
                case 15: // Black knight
                    if (Creature* tirion = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_TIRION)))
                        tirion->AI()->Talk(TIRION_KNIGHT_INTRO);
                    NextStep(4000, true);
                    break;
                case 16:
                    Talk(ANNOUNCER_BLACK_KNIGHT);
                    me->SummonCreature(VEHICLE_BLACK_KNIGHT, 769.834f, 651.915f, 447.035f, 0);
                    NextStep(2500, true);
                    break;
                case 17:
                    if (Creature* knight = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_BLACK_KNIGHT)))
                        knight->AI()->Talk(BLACK_KNIGHT_INTRO);
                    NextStep(3000, true);
                    break;
                case 18:
                    if (Creature* tirion = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_TIRION)))
                        tirion->AI()->Talk(TIRION_KNIGHT_INTRO_1);
                    NextStep(3000, true);
                    break;
                case 19:
                    if (Creature* knight = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_BLACK_KNIGHT)))
                        knight->AI()->Talk(BLACK_KNIGHT_INTRO_1);
                    NextStep(3000, true);
                    break;
                case 20:
                    if (Creature* knight = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_BLACK_KNIGHT)))
                        knight->AI()->Talk(BLACK_KNIGHT_INTRO_2);
                    NextStep(3000, true);
                    break;
                case 21:
                    if (Creature* garrosh = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_GARROSH)))
                        garrosh->AI()->Talk(GARROSH_KNIGHT_INTRO);
                    if (Creature* varian = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_VARIAN)))
                        varian->AI()->Talk(VARIAN_KNIGHT_INTRO);
                    NextStep(0, false);
                    break;
                }

            } else uiTimer -= diff;
        }

        void JustSummoned(Creature* summon) override
        {
            if (instance->GetBossState(BOSS_GRAND_CHAMPIONS) != DONE)
                summon->SetReactState(REACT_PASSIVE);
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            switch (summon->GetEntry())
            {
                case NPC_DARNASSUS_CHAMPION:
                case NPC_EXODAR_CHAMPION:
                case NPC_STORMWIND_CHAMPION:
                case NPC_GNOMEREGAN_CHAMPION:
                case NPC_IRONFORGE_CHAMPION:
                case NPC_UNDERCITY_CHAMPION:
                case NPC_THUNDERBLUFF_CHAMPION:
                case NPC_ORGRIMMAR_CHAMPION:
                case NPC_SILVERMOON_CHAMPION:
                case NPC_SENJIN_CHAMPION:
                    SetData(DATA_LESSER_CHAMPIONS_DEFEATED, 0);
                    break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_announcer_toc5AI>(creature);
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 /*action*/) override
    {
        player->PlayerTalkClass->ClearMenus();
        player->CLOSE_GOSSIP_MENU();
        ENSURE_AI(npc_announcer_toc5::npc_announcer_toc5AI, creature->AI())->StartEncounter();

        return true;
    }
};

void AddSC_trial_of_the_champion()
{
    new npc_announcer_toc5();
}
