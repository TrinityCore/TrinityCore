/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

/* Script Data Start
SDName: Gnomeregan
SDAuthor: Manuel
SD%Complete: 90%
SDComment: Some visual effects are not implemented.
Script Data End */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "gnomeregan.h"
#include "ScriptedEscortAI.h"

#define GOSSIP_START_EVENT "I am ready to being"

enum BlastmasterEmi
{
    GOSSIP_TEXT_EMI     = 1693,

    SAY_BLASTMASTER_0   = 0,
    SAY_BLASTMASTER_1   = 1,
    SAY_BLASTMASTER_2   = 2,
    SAY_BLASTMASTER_3   = 3,
    SAY_BLASTMASTER_4   = 4,
    SAY_BLASTMASTER_5   = 5,
    SAY_BLASTMASTER_6   = 6,
    SAY_BLASTMASTER_7   = 7,
    SAY_BLASTMASTER_8   = 8,
    SAY_BLASTMASTER_9   = 9,
    SAY_BLASTMASTER_10  = 10,
    SAY_BLASTMASTER_11  = 11,
    SAY_BLASTMASTER_12  = 12,
    SAY_BLASTMASTER_13  = 13,
    SAY_BLASTMASTER_14  = 14,
    SAY_BLASTMASTER_15  = 15,
    SAY_BLASTMASTER_16  = 16,
    SAY_BLASTMASTER_17  = 17,
    SAY_BLASTMASTER_18  = 18,
    SAY_BLASTMASTER_19  = 19,
    SAY_BLASTMASTER_20  = 20,
    SAY_BLASTMASTER_21  = 21,
    SAY_BLASTMASTER_22  = 22,
    SAY_BLASTMASTER_23  = 23,
    SAY_BLASTMASTER_24  = 24,
    SAY_BLASTMASTER_25  = 25,
    SAY_BLASTMASTER_26  = 26,
    SAY_BLASTMASTER_27  = 27,
    SAY_BLASTMASTER_28  = 28,

    SAY_GRUBBIS         = 0
};

const Position SpawnPosition[] =
{
    {-557.630f, -114.514f, -152.209f, 0.641f},
    {-555.263f, -113.802f, -152.737f, 0.311f},
    {-552.154f, -112.476f, -153.349f, 0.621f},
    {-548.692f, -111.089f, -154.090f, 0.621f},
    {-546.905f, -108.340f, -154.877f, 0.729f},
    {-547.736f, -105.154f, -155.176f, 0.372f},
    {-547.274f, -114.109f, -153.952f, 0.735f},
    {-552.534f, -110.012f, -153.577f, 0.747f},
    {-550.708f, -116.436f, -153.103f, 0.679f},
    {-554.030f, -115.983f, -152.635f, 0.695f},
    {-494.595f, -87.516f, -149.116f, 3.344f},
    {-493.349f, -90.845f, -148.882f, 3.717f},
    {-491.995f, -87.619f, -148.197f, 3.230f},
    {-490.732f, -90.739f, -148.091f, 3.230f},
    {-490.554f, -89.114f, -148.055f, 3.230f},
    {-495.240f, -90.808f, -149.493f, 3.238f},
    {-494.195f, -89.553f, -149.131f, 3.254f},
    {-511.3304f, -139.9622f, -152.4761f, 0.7504908f},
    {-510.6754f, -139.4371f, -152.6167f, 3.33359f},
    {-511.8976f, -139.3562f, -152.4785f, 3.961899f}
};

class npc_blastmaster_emi_shortfuse : public CreatureScript
{
public:
    npc_blastmaster_emi_shortfuse() : CreatureScript("npc_blastmaster_emi_shortfuse") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_blastmaster_emi_shortfuseAI(creature);
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF+1)
        {
            if (npc_escortAI* pEscortAI = CAST_AI(npc_blastmaster_emi_shortfuse::npc_blastmaster_emi_shortfuseAI, creature->AI()))
                pEscortAI->Start(true, false, player->GetGUID());

            creature->setFaction(player->getFaction());
            creature->AI()->SetData(1, 0);

            player->CLOSE_GOSSIP_MENU();
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        InstanceScript* instance = creature->GetInstanceScript();

        if (instance && instance->GetData(TYPE_EVENT) == NOT_STARTED)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_START_EVENT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        player->SEND_GOSSIP_MENU(GOSSIP_TEXT_EMI, creature->GetGUID());

        return true;
    }

    struct npc_blastmaster_emi_shortfuseAI : public npc_escortAI
    {
        npc_blastmaster_emi_shortfuseAI(Creature* creature) : npc_escortAI(creature)
        {
            instance = creature->GetInstanceScript();
            creature->RestoreFaction();
            Reset();
        }

        InstanceScript* instance;

        uint8 uiPhase;
        uint32 uiTimer;

        std::list<uint64> SummonList;
        std::list<uint64> GoSummonList;

        void Reset()
        {
            if (!HasEscortState(STATE_ESCORT_ESCORTING))
            {
                uiTimer = 0;
                uiPhase = 0;

                RestoreAll();

                SummonList.clear();
                GoSummonList.clear();
            }
        }

        void NextStep(uint32 uiTimerStep, bool bNextStep = true, uint8 uiPhaseStep = 0)
        {
            uiTimer = uiTimerStep;
            if (bNextStep)
                ++uiPhase;
            else
                uiPhase = uiPhaseStep;
        }

        void CaveDestruction(bool bBool)
        {
            if (GoSummonList.empty())
                return;

            for (std::list<uint64>::const_iterator itr = GoSummonList.begin(); itr != GoSummonList.end(); ++itr)
            {
               if (GameObject* go = GameObject::GetGameObject(*me, *itr))
               {
                    if (go)
                    {
                        if (Creature* trigger = go->SummonTrigger(go->GetPositionX(), go->GetPositionY(), go->GetPositionZ(), 0, 1))
                        {
                            //visual effects are not working!
                            trigger->CastSpell(trigger, 11542, true);
                            trigger->CastSpell(trigger, 35470, true);
                        }
                        go->RemoveFromWorld();
                        //go->CastSpell(me, 12158); makes all die?!
                    }
               }
            }

           if (bBool)
           {
                if (instance)
                    if (GameObject* go = GameObject::GetGameObject(*me, instance->GetData64(DATA_GO_CAVE_IN_RIGHT)))
                        instance->HandleGameObject(0, false, go);
           }else
                if (instance)
                    if (GameObject* go = GameObject::GetGameObject(*me, instance->GetData64(DATA_GO_CAVE_IN_LEFT)))
                        instance->HandleGameObject(0, false, go);
        }

        void SetInFace(bool bBool)
        {
            if (!instance)
                return;

            if (bBool)
            {
                if (GameObject* go = GameObject::GetGameObject(*me, instance->GetData64(DATA_GO_CAVE_IN_RIGHT)))
                    me->SetFacingToObject(go);
            }else
                if (GameObject* go = GameObject::GetGameObject(*me, instance->GetData64(DATA_GO_CAVE_IN_LEFT)))
                    me->SetFacingToObject(go);
        }

        void RestoreAll()
        {
            if (!instance)
                return;

            if (GameObject* go = GameObject::GetGameObject(*me, instance->GetData64(DATA_GO_CAVE_IN_RIGHT)))
                instance->HandleGameObject(0, false, go);

            if (GameObject* go = GameObject::GetGameObject(*me, instance->GetData64(DATA_GO_CAVE_IN_LEFT)))
                instance->HandleGameObject(0, false, go);

            if (!GoSummonList.empty())
                for (std::list<uint64>::const_iterator itr = GoSummonList.begin(); itr != GoSummonList.end(); ++itr)
                {
                    if (GameObject* go = GameObject::GetGameObject(*me, *itr))
                        go->RemoveFromWorld();
                }

            if (!SummonList.empty())
                for (std::list<uint64>::const_iterator itr = SummonList.begin(); itr != SummonList.end(); ++itr)
                {
                    if (Creature* summon = Unit::GetCreature(*me, *itr))
                    {
                        if (summon->isAlive())
                            summon->DisappearAndDie();
                        else
                            summon->RemoveCorpse();
                    }
                }
        }

        void AggroAllPlayers(Creature* temp)
        {
            Map::PlayerList const &PlList = me->GetMap()->GetPlayers();

            if (PlList.isEmpty())
                return;

            for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
            {
                if (Player* player = i->getSource())
                {
                    if (player->isGameMaster())
                        continue;

                    if (player->isAlive())
                    {
                        temp->SetInCombatWith(player);
                        player->SetInCombatWith(temp);
                        temp->AddThreat(player, 0.0f);
                    }
                }
            }
        }

        void WaypointReached(uint32 waypointId)
        {
            //just in case
            if (GetPlayerForEscort())
                if (me->getFaction() != GetPlayerForEscort()->getFaction())
                    me->setFaction(GetPlayerForEscort()->getFaction());

            switch (waypointId)
            {
                case 3:
                    SetEscortPaused(true);
                    NextStep(2000, false, 3);
                    break;
                case 7:
                    SetEscortPaused(true);
                    NextStep(2000, false, 4);
                    break;
                case 9:
                    NextStep(1000, false, 8);
                    break;
                case 10:
                    NextStep(25000, false, 10);
                    break;
                case 11:
                    SetEscortPaused(true);
                    SetInFace(true);
                    NextStep(1000, false, 11);
                    break;
                case 12:
                    NextStep(25000, false, 18);
                    break;
                case 13:
                    Summon(7);
                    NextStep(25000, false, 19);
                    break;
                case 14:
                    SetInFace(false);
                    Talk(SAY_BLASTMASTER_26);
                    SetEscortPaused(true);
                    NextStep(5000, false, 20);
                    break;
            }
        }

        void SetData(uint32 uiI, uint32 uiValue)
        {
            switch (uiI)
            {
                case 1:
                    SetEscortPaused(true);
                    Talk(SAY_BLASTMASTER_0);
                    NextStep(2000, true);
                    break;
                case 2:
                    if (!instance)
                        return;

                    switch (uiValue)
                    {
                        case 1:
                            instance->SetData(TYPE_EVENT, IN_PROGRESS);
                            break;
                        case 2:
                            instance->SetData(TYPE_EVENT, DONE);
                            NextStep(5000, false, 22);
                            break;
                    }
                    break;
            }
        }

        void Summon(uint8 uiCase)
        {
            switch (uiCase)
            {
                case 1:
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[1], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[3], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[4], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[5], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[6], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[7], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[8], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[9], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    break;
                case 2:
                    if (GameObject* go = me->SummonGameObject(183410, -533.140f, -105.322f, -156.016f, 0, 0, 0, 0, 0, 1000))
                    {
                        GoSummonList.push_back(go->GetGUID());
                        go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE); //We can't use it!
                    }
                    Summon(3);
                    break;
                case 3:
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[1], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[3], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    Talk(SAY_BLASTMASTER_19);
                    break;
                case 4:
                    if (GameObject* go = me->SummonGameObject(183410, -542.199f, -96.854f, -155.790f, 0, 0, 0, 0, 0, 1000))
                    {
                        GoSummonList.push_back(go->GetGUID());
                        go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                    }
                    break;
                case 5:
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[1], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    Talk(SAY_BLASTMASTER_15);
                    break;
                case 6:
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[10], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[11], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[12], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[13], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[14], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    break;
                case 7:
                    if (GameObject* go = me->SummonGameObject(183410, -507.820f, -103.333f, -151.353f, 0, 0, 0, 0, 0, 1000))
                    {
                        GoSummonList.push_back(go->GetGUID());
                        go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE); //We can't use it!
                        Summon(6);
                    }
                    break;
                case 8:
                    if (GameObject* go = me->SummonGameObject(183410, -511.829f, -86.249f, -151.431f, 0, 0, 0, 0, 0, 1000))
                    {
                        GoSummonList.push_back(go->GetGUID());
                        go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE); //We can't use it!
                    }
                    break;
                case 9:
                    if (Creature* grubbis = me->SummonCreature(NPC_GRUBBIS, SpawnPosition[15], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000))
                        grubbis->AI()->Talk(SAY_GRUBBIS);
                    me->SummonCreature(NPC_CHOMPER, SpawnPosition[16], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    break;
                case 10:
                    me->SummonGameObject(GO_RED_ROCKET, SpawnPosition[17].GetPositionX(), SpawnPosition[17].GetPositionY(), SpawnPosition[17].GetPositionZ(), SpawnPosition[17].GetOrientation(), 0, 0, 0, 0, 7200);
                    me->SummonGameObject(GO_RED_ROCKET, SpawnPosition[18].GetPositionX(), SpawnPosition[18].GetPositionY(), SpawnPosition[18].GetPositionZ(), SpawnPosition[18].GetOrientation(), 0, 0, 0, 0, 7200);
                    me->SummonGameObject(GO_RED_ROCKET, SpawnPosition[19].GetPositionX(), SpawnPosition[19].GetPositionY(), SpawnPosition[19].GetPositionZ(), SpawnPosition[19].GetOrientation(), 0, 0, 0, 0, 7200);
                    break;
            }
        }

        void UpdateEscortAI(const uint32 uiDiff)
        {
            if (uiPhase)
            {
                if (uiTimer <= uiDiff)
                {
                    switch (uiPhase)
                    {
                        case 1:
                            Talk(SAY_BLASTMASTER_1);
                            NextStep(2000, true);
                            break;
                        case 2:
                            SetEscortPaused(false);
                            NextStep(0, false, 0);
                            break;
                        case 3:
                            Talk(SAY_BLASTMASTER_2);
                            SetEscortPaused(false);
                            NextStep(0, false, 0);
                            break;
                        case 4:
                            Talk(SAY_BLASTMASTER_3);
                            NextStep(3000, true);
                            break;
                        case 5:
                            Talk(SAY_BLASTMASTER_4);
                            NextStep(3000, true);
                            break;
                        case 6:
                            SetInFace(true);
                            Talk(SAY_BLASTMASTER_5);
                            Summon(1);
                            if (instance)
                                if (GameObject* go = GameObject::GetGameObject(*me, instance->GetData64(DATA_GO_CAVE_IN_RIGHT)))
                                    instance->HandleGameObject(0, true, go);
                            NextStep(3000, true);
                            break;
                        case 7:
                            Talk(SAY_BLASTMASTER_6);
                            SetEscortPaused(false);
                            NextStep(0, false, 0);
                            break;
                        case 8:
                            me->HandleEmoteCommand(EMOTE_STATE_USE_STANDING);
                            NextStep(25000, true);
                            break;
                        case 9:
                            Summon(2);
                            NextStep(0, false);
                            break;
                        case 10:
                            Summon(4);
                            NextStep(0, false);
                            break;
                        case 11:
                            Talk(SAY_BLASTMASTER_17);
                            NextStep(5000, true);
                            break;
                        case 12:
                            Talk(SAY_BLASTMASTER_18);
                            NextStep(5000, true);
                            break;
                        case 13:
                            Talk(SAY_BLASTMASTER_20);
                            CaveDestruction(true);
                            NextStep(8000, true);
                            break;
                        case 14:
                            Talk(SAY_BLASTMASTER_21);
                            NextStep(8500, true);
                            break;
                        case 15:
                            Talk(SAY_BLASTMASTER_22);
                            NextStep(2000, true);
                            break;
                        case 16:
                            Talk(SAY_BLASTMASTER_23);
                            SetInFace(false);
                            if (instance)
                                if (GameObject* go = GameObject::GetGameObject(*me, instance->GetData64(DATA_GO_CAVE_IN_LEFT)))
                                    instance->HandleGameObject(0, true, go);
                            NextStep(2000, true);
                            break;
                        case 17:
                            SetEscortPaused(false);
                            Talk(SAY_BLASTMASTER_24);
                            Summon(6);
                            NextStep(0, false);
                            break;
                        case 18:
                            Summon(7);
                            NextStep(0, false);
                            break;
                        case 19:
                            SetInFace(false);
                            Summon(8);
                            Talk(SAY_BLASTMASTER_25);
                            NextStep(0, false);
                            break;
                        case 20:
                            Talk(SAY_BLASTMASTER_27);
                            NextStep(2000, true);
                            break;
                        case 21:
                            Summon(9);
                            NextStep(0, false);
                            break;
                        case 22:
                            CaveDestruction(false);
                            Talk(SAY_BLASTMASTER_20);
                            NextStep(2000, true);
                            break;
                        case 23:
                            Summon(10);
                            Talk(SAY_BLASTMASTER_28);
                            NextStep(0, false);
                            break;
                    }
                } else uiTimer -= uiDiff;
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void JustSummoned(Creature* summon)
        {
            SummonList.push_back(summon->GetGUID());
            AggroAllPlayers(summon);
        }
    };

};

class boss_grubbis : public CreatureScript
{
public:
    boss_grubbis() : CreatureScript("boss_grubbis") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_grubbisAI(creature);
    }

    struct boss_grubbisAI : public ScriptedAI
    {
        boss_grubbisAI(Creature* creature) : ScriptedAI(creature)
        {
            SetDataSummoner();
        }

        void SetDataSummoner()
        {
            if (!me->isSummon())
                return;

            if (Unit* summon = me->ToTempSummon()->GetSummoner())
                CAST_CRE(summon)->AI()->SetData(2, 1);
        }

        void UpdateAI(const uint32 /*diff*/)
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/)
        {
            if (!me->isSummon())
                return;

            if (Unit* summoner = me->ToTempSummon()->GetSummoner())
                if (Creature* summonerCre = summoner->ToCreature())
                    summonerCre->AI()->SetData(2, 2);
        }
    };

};

void AddSC_gnomeregan()
{
    new npc_blastmaster_emi_shortfuse();
    new boss_grubbis();
}
