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
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "SpellInfo.h"
#include "tanaan_intro.h"
#include "TemporarySummon.h"

/// Passive Scene Object
class playerScript_cost_of_war : public PlayerScript
{
public:
    playerScript_cost_of_war() : PlayerScript("playerScript_cost_of_war") {}

    void OnSceneComplete(Player* player, uint32 sceneInstanceId) override
    {
        if (!player->GetSceneMgr().HasScene(sceneInstanceId, TanaanSceneObjects::SceneCostOfWarEscort))
            return;

        player->CompleteQuest(TanaanQuests::QuestCostOfWar);
    }
};

/// Passive Scene Object
class playerScript_blaze_of_glory : public PlayerScript
{
public:
    playerScript_blaze_of_glory() : PlayerScript("playerScript_blaze_of_glory") { }

    void OnLogin(Player* player, bool /*firstLogin*/) override
    {
        if (player->HasQuest(TanaanQuests::QuestBlazeOfGlory))
            player->GetSceneMgr().PlaySceneByPackageId(BlazeOfGloryData::SceneId);
    }

    void OnQuestAccept(Player* p_Player, const Quest* p_Quest) override
    {
        if (p_Quest->GetQuestId() == TanaanQuests::QuestBlazeOfGlory)
            p_Player->GetSceneMgr().PlaySceneByPackageId(BlazeOfGloryData::SceneId);
    }

    void OnQuestReward(Player* p_Player, const Quest* p_Quest) override
    {
        if (p_Player && p_Quest && p_Quest->GetQuestId() == TanaanQuests::QuestBlazeOfGlory)
            p_Player->GetSceneMgr().CancelSceneByPackageId(BlazeOfGloryData::SceneId);
    }

    void OnSceneTriggerEvent(Player* p_Player, uint32 p_SceneInstanceID, std::string p_Event) override
    {
        if (!p_Player->GetSceneMgr().HasScene(p_SceneInstanceID, BlazeOfGloryData::SceneId))
            return;

        if (p_Event == "Visual" && p_Player->HasQuest(TanaanQuests::QuestBlazeOfGlory))
            p_Player->AddAura(BlazeOfGloryData::SpellTrailOfFlameVisual, p_Player);
        else if (p_Event == "Clear")
            p_Player->RemoveAura(BlazeOfGloryData::SpellTrailOfFlameVisual);
        else if (p_Event == "Credit")
            p_Player->KilledMonsterCredit(81760);
    }
};

/// Passive Scene Object
class playerScript_tanaan_holdout : public PlayerScript
{
public:
    playerScript_tanaan_holdout() : PlayerScript("playerScript_tanaan_holdout") { }

    void OnSceneComplete(Player* p_Player, uint32 p_SceneInstanceID) override
    {
        if (!p_Player->GetSceneMgr().HasScene(p_SceneInstanceID, TanaanSceneObjects::SceneHoldout))
            return;

        // Set les bonnes phases
        p_Player->AddAura(TanaanPhases::PhaseAfterBlazeGlobal, p_Player);
        p_Player->AddAura(TanaanPhases::PhaseAfterBlazeAriok, p_Player);

        if (p_Player->GetTeamId() == TEAM_ALLIANCE)
            p_Player->AddAura(TanaanPhases::PhaseAfterBlazeAlliance, p_Player);
        else
            p_Player->AddAura(TanaanPhases::PhaseAfterBlazeHorde, p_Player);
    }
};

/// 78507 - Bleeding Hollow Savage
class npc_bleeding_hollow_sauvage : public CreatureScript
{
public:
    npc_bleeding_hollow_sauvage() : CreatureScript("npc_bleeding_hollow_sauvage") { }

    struct npc_bleeding_hollow_sauvageAI : public ScriptedAI
    {
        npc_bleeding_hollow_sauvageAI(Creature* creature) : ScriptedAI(creature) { }

        void SpellHit(Unit* p_Caster, const SpellInfo* p_SpellInfo) override
        {
            if (p_SpellInfo->Id == TanaanSpells::SpellArcaneBarrage)
            {
                p_Caster->DealDamage(me, me->GetHealth());
                me->DespawnOrUnsummon();
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_bleeding_hollow_sauvageAI(creature);
    }
};

/// 229325/229350 - Bleeding Hollow Cages
class go_bleeding_hollow_cage : public GameObjectScript
{
public:
    go_bleeding_hollow_cage() : GameObjectScript("go_bleeding_hollow_cage") { }

    bool OnGossipHello(Player* p_Player, GameObject* p_Gameobject) override
    {
        if (p_Player->GetQuestStatus(TanaanQuests::QuestBledDryAlly) == QUEST_STATUS_INCOMPLETE || p_Player->GetQuestStatus(TanaanQuests::QuestBledDryHorde) == QUEST_STATUS_INCOMPLETE)
        {
            /// Eastern Cage
            if (p_Gameobject->GetEntry() == TanaanGameObjects::GobEasternCage)
            {
                if (p_Player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjEasternCageOpened) >= 1)
                    return true;

                p_Player->RemoveAurasDueToSpell(TanaanPhases::PhaseEasternCageAlly);
                p_Player->RemoveAurasDueToSpell(TanaanPhases::PhaseEasternCageHorde);

                p_Player->KilledMonsterCredit(TanaanKillCredits::CreditEasternAllianceCage);
                p_Player->KilledMonsterCredit(TanaanKillCredits::CreditEasternHordeCage);

                p_Player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneEasterCage);

                return false;
            }
            /// Southest Cage
            else if (p_Gameobject->GetEntry() == TanaanGameObjects::GobSouthernCage)
            {
                if (p_Player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjSouthernCageOpened) >= 1)
                    return true;

                p_Player->RemoveAurasDueToSpell(TanaanPhases::PhaseSouthernCageAlly);
                p_Player->RemoveAurasDueToSpell(TanaanPhases::PhaseSouthernCageHorde);

                p_Player->KilledMonsterCredit(TanaanKillCredits::CreditSouthernAllianceCage);
                p_Player->KilledMonsterCredit(TanaanKillCredits::CreditSouthernHordeCage);

                p_Player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneSouthernCage);

                return false;
            }
        }

        return true;
    }
};

/// 78556 - Ariok
class npc_tanaan_ariok : public CreatureScript
{
public:
    npc_tanaan_ariok() : CreatureScript("npc_tanaan_ariok") { }

    enum eDatas
    {
        ActionStartEscort = 1
    };

    bool OnGossipSelect(Player* p_Player, Creature* p_Creature, uint32 /*sender*/, uint32 /*action*/) override
    {
        if (p_Player->GetQuestStatus(TanaanQuests::QuestAltarAltercation) == QUEST_STATUS_INCOMPLETE ||
            p_Player->GetQuestStatus(TanaanQuests::QuestAltarAltercation) == QUEST_STATUS_FAILED)
        {
            p_Player->RemoveAurasDueToSpell(TanaanPhases::PhaseAfterBlazeAriok);

            if (p_Player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjAriokGossip))
                return true;

            if (p_Player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjAriokGossip) < 1)
                p_Player->KilledMonsterCredit(TanaanKillCredits::CreditAriokGossip);

            if (TempSummon* l_Ariok = p_Player->SummonCreature(p_Creature->GetEntry(), p_Creature->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0, 0, true))
                if (l_Ariok->GetAI())
                    l_Ariok->AI()->SetGUID(p_Player->GetGUID());
        }

        return true;
    }

    struct npc_tanaan_ariokAI : public ScriptedAI
    {
        npc_tanaan_ariokAI(Creature* creature) : ScriptedAI(creature) { }

        bool m_IsSummoned;
        bool m_playerNeedObjective;
        ObjectGuid m_PlayerGuid;
        uint32 m_checkObjectiveTimer;
        uint32 m_checkMustDespawnTimer;

        void Reset() override
        {
            m_IsSummoned            = false;
            m_PlayerGuid            = ObjectGuid::Empty;
            m_checkObjectiveTimer   = 2000;
            m_checkMustDespawnTimer = 2000;
        }

        void SetGUID(ObjectGuid p_Guid, int32 /*p_Index*/) override
        {
            m_PlayerGuid = p_Guid;

            if (me->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP))
                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

            if (Player* p_Followed = ObjectAccessor::GetPlayer(*me, p_Guid))
                me->GetMotionMaster()->MoveFollow(p_Followed, 0.2f, 5.23f);

            Talk(0);
        }

        void IsSummonedBy(Unit* /*p_Summoner*/) override
        {
            m_IsSummoned = true;
            m_playerNeedObjective = true;
        }

        void UpdateAI(uint32 p_Diff) override
        {
            if (!m_IsSummoned)
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (m_playerNeedObjective)
            {
                if (m_checkObjectiveTimer <= p_Diff)
                {
                    if (GetClosestCreatureWithEntry(me, TanaanCreatures::NpcBleedingHollowBloodchosen, 55.0f))
                        if (Player* l_Player = ObjectAccessor::GetPlayer(*me, m_PlayerGuid))
                            if (!l_Player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjBloodRitualOrbDestroyed))
                            {
                                l_Player->KilledMonsterCredit(TanaanKillCredits::CreditAriokEscort);
                                m_playerNeedObjective = false;
                            }

                    m_checkObjectiveTimer = 2000;
                }
                else m_checkObjectiveTimer -= p_Diff;
            }

            if (m_checkMustDespawnTimer <= p_Diff)
            {
                if (Player* l_Player = ObjectAccessor::GetPlayer(*me, m_PlayerGuid))
                    if (l_Player->GetQuestStatus(TanaanQuests::QuestAltarAltercation) != QUEST_STATUS_INCOMPLETE ||
                        l_Player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjBloodRitualOrbDestroyed) == 3)
                        me->DespawnOrUnsummon();

                m_checkMustDespawnTimer = 2000;
            }
            else m_checkMustDespawnTimer -= p_Diff;

        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_tanaan_ariokAI(creature);
    }
};

/// 83670 - Blood Ritual Orb
class npc_blood_ritual_orb : public CreatureScript
{
public:
    npc_blood_ritual_orb() : CreatureScript("npc_blood_ritual_orb") { }

    bool OnGossipHello(Player* p_Player, Creature* p_Creature) override
    {
        if (p_Player->GetQuestStatus(TanaanQuests::QuestAltarAltercation) == QUEST_STATUS_INCOMPLETE)
        {
            if (p_Player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjBloodRitualOrbDestroyed) <= 2)
            {
                p_Player->KilledMonsterCredit(TanaanKillCredits::CreditBloodOrb);
                p_Creature->DestroyForPlayer(p_Player);

                if (p_Player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjBloodRitualOrbDestroyed) == 1)
                    p_Player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneSneakyArmy);

                if (p_Player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjBloodRitualOrbDestroyed) == 3)
                {
                    p_Player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneKilRoggRevealed);

                    p_Player->RemoveAurasDueToSpell(TanaanPhases::PhaseAfterBlazeGlobal);
                    p_Player->RemoveAurasDueToSpell(TanaanPhases::PhaseAfterBlazeAlliance);
                    p_Player->RemoveAurasDueToSpell(TanaanPhases::PhaseAfterBlazeHorde);
                }
            }
        }

        return true;
    }

    struct npc_blood_ritual_orbAI : public ScriptedAI
    {
        npc_blood_ritual_orbAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            me->SetDisableGravity(true);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_blood_ritual_orbAI(creature);
    }
};

void AddSC_tanaan_intro_bleeding_hollow()
{
    new npc_bleeding_hollow_sauvage();
    new go_bleeding_hollow_cage();
    new npc_tanaan_ariok();
    new npc_blood_ritual_orb();

    new playerScript_cost_of_war();
    new playerScript_blaze_of_glory();
    new playerScript_tanaan_holdout();
}
