/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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
#include "PhasingHandler.h"
#include "Player.h"
#include "tanaan_intro.h"
#include "WorldSession.h"

/// Tanaan entering
class playerScript_enter_tanaan : public PlayerScript
{
public:
    playerScript_enter_tanaan() : PlayerScript("playerScript_enter_tanaan") { }

    void OnUpdateArea(Player* player, uint32 newAreaId, uint32 /*oldAreaID*/) override
    {
        if (player->GetZoneId() != TanaanZones::ZoneTanaanJungle)
            return;

        switch (newAreaId)
        {
            case TanaanZones::AreaTheDarkPortal:
            {
                player->GetSceneMgr().RecreateScene(TanaanSceneObjects::SceneLoomingArmy);
                player->GetSceneMgr().RecreateScene(TanaanSceneObjects::SceneSoulTrain);
                break;
            }
            case TanaanZones::AreaHearthBlood:
            {
                player->GetSceneMgr().RecreateScene(TanaanSceneObjects::SceneCuriousHatchets);
                break;
            }
            case TanaanZones::AreaBleedingAltar:
            {
                player->GetSceneMgr().RecreateScene(TanaanSceneObjects::SceneEyeOfKilrogg);
                player->GetSceneMgr().RecreateScene(TanaanSceneObjects::SceneBloodBowl);
                break;
            }
            case TanaanZones::AreaKargatharProvingGrounds:
            {
                if (player->GetQuestStatus(TanaanQuests::QuestAPotentialAlly) != QUEST_STATUS_COMPLETE &&
                    player->GetQuestStatus(TanaanQuests::QuestAPotentialAlly) != QUEST_STATUS_REWARDED &&
                    player->GetQuestStatus(TanaanQuests::QuestAPotentialAllyHorde) != QUEST_STATUS_COMPLETE &&
                    player->GetQuestStatus(TanaanQuests::QuestAPotentialAllyHorde) != QUEST_STATUS_REWARDED)
                    player->GetSceneMgr().RecreateScene(TanaanSceneObjects::SceneRingOfFire);
                break;
            }
            case TanaanZones::AreaUmbralHalls:
            {
                player->GetSceneMgr().RecreateScene(TanaanSceneObjects::SceneUmbralHallsPortals);
                player->GetSceneMgr().RecreateScene(TanaanSceneObjects::SceneKelidanVisual1);
                player->GetSceneMgr().RecreateScene(TanaanSceneObjects::SceneKelidanVisual2);
                break;
            }
            case TanaanZones::AreaBlackRockQuarry:
            {
                if (player->GetQuestStatus(TanaanQuests::QuestTheBattleOfTheForge) == QUEST_STATUS_INCOMPLETE)
                {
                    player->AddAura(TanaanPhases::PhaseBlackrockKhadgarRock, player);
                    player->GetSceneMgr().RecreateScene(TanaanSceneObjects::SceneKhadgarAtDam);

                    player->SummonCreature(TanaanCreatures::NpcLadyLiadrinBlackrockSummon, *player);
                    player->SummonCreature(TanaanCreatures::NpcCordanaFelsong, *player);
                    player->SummonCreature(player->GetTeamId() == TEAM_ALLIANCE ? TanaanCreatures::NpcQiana: TanaanCreatures::NpcOlin, *player);
                }
                break;
            }
            default:
                break;
        }

        if (player->GetQuestStatus(TanaanQuests::QuestTheBattleOfTheForge) == QUEST_STATUS_REWARDED)
        {
            PhaseShift phaseShift;
            phaseShift.AddUiWorldMapAreaIdSwap((uint32)TanaanZones::TerrainSwapID);
            PhasingHandler::SendToPlayer(player, phaseShift);
        }
    }

    void OnObjectiveValidate(Player* player, uint32 questId, uint32 objectiveId) override
    {
        if (questId == TanaanQuests::QuestThePortalPower && objectiveId == TanaanQuestObjectives::ObjEnterGulDanPrison)
            player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneGulDanReavel);
    }
};

/// Archmage Khadgar - 78558/78559 (Main quest giver/taker)
class npc_archmage_khadgar : public CreatureScript
{
public:
    npc_archmage_khadgar() : CreatureScript("npc_archmage_khadgar") { }

    bool OnQuestAccept(Player* player, Creature* /*creature*/, Quest const* quest) override
    {
        switch (quest->GetQuestId())
        {
            case TanaanQuests::QuestCostOfWar:
            {
                player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneCostOfWarEscort);
                player->PlayerTalkClass->SendCloseGossip();
                break;
            }
            case TanaanQuests::QuestBlazeOfGlory:
            {
                player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneHoldout);

                // Phases will be set at quest completion
                player->RemoveAurasDueToSpell(TanaanPhases::PhaseAfterBlazeGlobal);
                player->RemoveAurasDueToSpell(TanaanPhases::PhaseAfterBlazeAriok);
                player->RemoveAurasDueToSpell(TanaanPhases::PhaseAfterBlazeAlliance);
                player->RemoveAurasDueToSpell(TanaanPhases::PhaseAfterBlazeHorde);

                player->PlayerTalkClass->SendCloseGossip();
                break;
            }
            default:
                break;
        }

        return false;
    }
};

/// 237670/237667 - Dark Portal
class go_platform_tanaan : public GameObjectScript
{
public:
    go_platform_tanaan() : GameObjectScript("go_platform_tanaan") { }

    struct go_platform_tanaanAI : public GameObjectAI
    {
        go_platform_tanaanAI(GameObject* p_Go) : GameObjectAI(p_Go) { }

        void Reset() override
        {
            go->SetGoState(GO_STATE_ACTIVE);
            go->SetLootState(GO_ACTIVATED);
        }

    };

    GameObjectAI* GetAI(GameObject* p_Go) const override
    {
        return new go_platform_tanaanAI(p_Go);
    }
};

void AddSC_tanaan_intro_global()
{
    new npc_archmage_khadgar();
    new playerScript_enter_tanaan();
    new go_platform_tanaan();
}
