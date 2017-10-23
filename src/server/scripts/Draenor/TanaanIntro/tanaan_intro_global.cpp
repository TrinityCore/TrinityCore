/*
* Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
* Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#include "tanaan_intro.h"
#include "GameObject.h"
#include "WorldSession.h"

/// Tanaan entering
class playerScript_enter_tanaan : public PlayerScript
{
public:
    playerScript_enter_tanaan() : PlayerScript("playerScript_enter_tanaan") { }

    void OnUpdateArea(Player* p_Player, uint32 p_NewAreaId, uint32 p_OldAreaID) override
    {
        if (p_Player->GetZoneId() != TanaanZones::ZoneTanaanJungle)
            return;

        switch (p_NewAreaId)
        {
            case TanaanZones::AreaTheDarkPortal:
            {
                p_Player->GetSceneMgr().RecreateScene(TanaanSceneObjects::SceneLoomingArmy);
                p_Player->GetSceneMgr().RecreateScene(TanaanSceneObjects::SceneSoulTrain);
                break;
            }
            case TanaanZones::AreaHearthBlood:
            {
                p_Player->GetSceneMgr().RecreateScene(TanaanSceneObjects::SceneCuriousHatchets);
                break;
            }
            case TanaanZones::AreaBleedingAltar:
            {
                p_Player->GetSceneMgr().RecreateScene(TanaanSceneObjects::SceneEyeOfKilrogg);
                p_Player->GetSceneMgr().RecreateScene(TanaanSceneObjects::SceneBloodBowl);
                break;
            }
            case TanaanZones::AreaKargatharProvingGrounds:
            {
                if (p_Player->GetQuestStatus(TanaanQuests::QuestAPotentialAlly) != QUEST_STATUS_COMPLETE &&
                    p_Player->GetQuestStatus(TanaanQuests::QuestAPotentialAlly) != QUEST_STATUS_REWARDED &&
                    p_Player->GetQuestStatus(TanaanQuests::QuestAPotentialAllyHorde) != QUEST_STATUS_COMPLETE &&
                    p_Player->GetQuestStatus(TanaanQuests::QuestAPotentialAllyHorde) != QUEST_STATUS_REWARDED)
                    p_Player->GetSceneMgr().RecreateScene(TanaanSceneObjects::SceneRingOfFire);
                break;
            }
            case TanaanZones::AreaUmbralHalls:
            {
                p_Player->GetSceneMgr().RecreateScene(TanaanSceneObjects::SceneUmbralHallsPortals);
                p_Player->GetSceneMgr().RecreateScene(TanaanSceneObjects::SceneKelidanVisual1);
                p_Player->GetSceneMgr().RecreateScene(TanaanSceneObjects::SceneKelidanVisual2);
                break;
            }
            case TanaanZones::AreaBlackRockQuarry:
            {
                if (p_Player->GetQuestStatus(TanaanQuests::QuestTheBattleOfTheForge) == QUEST_STATUS_INCOMPLETE)
                {
                    p_Player->AddAura(TanaanPhases::PhaseBlackrockKhadgarRock, p_Player);
                    p_Player->GetSceneMgr().RecreateScene(TanaanSceneObjects::SceneKhadgarAtDam);

                    Position playerPosition = p_Player->GetPosition();
                    p_Player->SummonCreature(TanaanCreatures::NpcLadyLiadrinBlackrockSummon, playerPosition);
                    p_Player->SummonCreature(TanaanCreatures::NpcCordanaFelsong, playerPosition);

                    if (p_Player->GetTeamId() == TEAM_ALLIANCE)
                        p_Player->SummonCreature(TanaanCreatures::NpcQiana, playerPosition);
                    else
                        p_Player->SummonCreature(TanaanCreatures::NpcOlin, playerPosition);
                }
                else if (p_Player->GetQuestStatus(TanaanQuests::QuestTheBattleOfTheForge) == QUEST_STATUS_REWARDED)
                {
                    // On met l'eau & le barrage détruit
                    std::set<uint32> l_PhaseId, l_Terrainswap, l_InactiveTerrainSwap;
                    l_Terrainswap.insert((uint32)TanaanZones::TerrainSwapID);
                    l_InactiveTerrainSwap.insert((uint32)TanaanZones::TerrainSwapID);
                    p_Player->GetSession()->SendSetPhaseShift(l_PhaseId, l_Terrainswap, l_InactiveTerrainSwap);
                }
                break;
            }
        }
    }

    void OnObjectiveValidate(Player* p_Player, uint32 p_QuestId, uint32 p_ObjectiveId) override
    {
        if (p_QuestId == TanaanQuests::QuestThePortalPower && p_ObjectiveId == TanaanQuestObjectives::ObjEnterGulDanPrison)
            p_Player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneGulDanReavel);
    }
};

/// Archmage Khadgar - 78558/78559 (Main quest giver/taker)
class npc_archmage_khadgar : public CreatureScript
{
public:
    npc_archmage_khadgar() : CreatureScript("npc_archmage_khadgar") { }

    bool OnQuestAccept(Player* p_Player, Creature* p_Creature, Quest const* p_Quest) override
    {
        switch (p_Quest->GetQuestId())
        {
            case TanaanQuests::QuestCostOfWar:
            {
                p_Player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneCostOfWarEscort);
                p_Player->PlayerTalkClass->SendCloseGossip();
                break;
            }
            case TanaanQuests::QuestBlazeOfGlory:
            {
                p_Player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneHoldout);

                // Les phases seront mises au moment de la completion de la scene
                p_Player->RemoveAurasDueToSpell(TanaanPhases::PhaseAfterBlazeGlobal);
                p_Player->RemoveAurasDueToSpell(TanaanPhases::PhaseAfterBlazeAriok);
                p_Player->RemoveAurasDueToSpell(TanaanPhases::PhaseAfterBlazeAlliance);
                p_Player->RemoveAurasDueToSpell(TanaanPhases::PhaseAfterBlazeHorde);

                p_Player->PlayerTalkClass->SendCloseGossip();
                break;
            }
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

        void Reset()
        {
            go->SetGoState(GO_STATE_ACTIVE);
            go->SetLootState(GO_ACTIVATED);
        }

    };

    GameObjectAI* GetAI(GameObject* p_Go) const
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
