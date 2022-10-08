/*
 * Copyright (C) 2022 BfaCore Reforged
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

    void OnQuestAccept(Player* player, const Quest* quest) override
    {
        if (quest->GetQuestId() == TanaanQuests::QuestBlazeOfGlory)
            player->GetSceneMgr().PlaySceneByPackageId(BlazeOfGloryData::SceneId);
    }

    void OnQuestReward(Player* player, const Quest* quest) override
    {
        if (player && quest && quest->GetQuestId() == TanaanQuests::QuestBlazeOfGlory)
            player->GetSceneMgr().CancelSceneByPackageId(BlazeOfGloryData::SceneId);
    }

    void OnSceneTriggerEvent(Player* player, uint32 p_SceneInstanceID, std::string p_Event) override
    {
        if (!player->GetSceneMgr().HasScene(p_SceneInstanceID, BlazeOfGloryData::SceneId))
            return;

        if (p_Event == "Visual" && player->HasQuest(TanaanQuests::QuestBlazeOfGlory))
            player->AddAura(BlazeOfGloryData::SpellTrailOfFlameVisual, player);
        else if (p_Event == "Clear")
            player->RemoveAura(BlazeOfGloryData::SpellTrailOfFlameVisual);
        else if (p_Event == "Credit")
            player->KilledMonsterCredit(81760);
    }
};

/// Passive Scene Object
class playerScript_tanaan_holdout : public PlayerScript
{
public:
    playerScript_tanaan_holdout() : PlayerScript("playerScript_tanaan_holdout") { }

    void OnSceneComplete(Player* player, uint32 p_SceneInstanceID) override
    {
        if (!player->GetSceneMgr().HasScene(p_SceneInstanceID, TanaanSceneObjects::SceneHoldout))
            return;

        // Set les bonnes phases
        player->AddAura(TanaanPhases::PhaseAfterBlazeGlobal, player);
        player->AddAura(TanaanPhases::PhaseAfterBlazeAriok, player);

        if (player->GetTeamId() == TEAM_ALLIANCE)
            player->AddAura(TanaanPhases::PhaseAfterBlazeAlliance, player);
        else
            player->AddAura(TanaanPhases::PhaseAfterBlazeHorde, player);
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

        void SpellHit(Unit* p_Caster, const SpellInfo* spellInfo) override
        {
            if (spellInfo->Id == TanaanSpells::SpellArcaneBarrage)
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

    bool OnGossipHello(Player* player, GameObject* gameObject) override
    {
        if (player->GetQuestStatus(TanaanQuests::QuestBledDryAlly) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(TanaanQuests::QuestBledDryHorde) == QUEST_STATUS_INCOMPLETE)
        {
            /// Eastern Cage
            if (gameObject->GetEntry() == TanaanGameObjects::GobEasternCage)
            {
                if (player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjEasternCageOpened) >= 1)
                    return true;

                player->RemoveAurasDueToSpell(TanaanPhases::PhaseEasternCageAlly);
                player->RemoveAurasDueToSpell(TanaanPhases::PhaseEasternCageHorde);

                player->KilledMonsterCredit(TanaanKillCredits::CreditEasternAllianceCage);
                player->KilledMonsterCredit(TanaanKillCredits::CreditEasternHordeCage);

                player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneEasterCage);

                return false;
            }
            /// Southest Cage
            else if (gameObject->GetEntry() == TanaanGameObjects::GobSouthernCage)
            {
                if (player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjSouthernCageOpened) >= 1)
                    return true;

                player->RemoveAurasDueToSpell(TanaanPhases::PhaseSouthernCageAlly);
                player->RemoveAurasDueToSpell(TanaanPhases::PhaseSouthernCageHorde);

                player->KilledMonsterCredit(TanaanKillCredits::CreditSouthernAllianceCage);
                player->KilledMonsterCredit(TanaanKillCredits::CreditSouthernHordeCage);

                player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneSouthernCage);

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

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 /*action*/) override
    {
        if (player->GetQuestStatus(TanaanQuests::QuestAltarAltercation) == QUEST_STATUS_INCOMPLETE ||
            player->GetQuestStatus(TanaanQuests::QuestAltarAltercation) == QUEST_STATUS_FAILED)
        {
            player->RemoveAurasDueToSpell(TanaanPhases::PhaseAfterBlazeAriok);

            if (player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjAriokGossip))
                return true;

            if (player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjAriokGossip) < 1)
                player->KilledMonsterCredit(TanaanKillCredits::CreditAriokGossip);

            if (TempSummon* l_Ariok = player->SummonCreature(creature->GetEntry(), creature->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0, 0, true))
                if (l_Ariok->GetAI())
                    l_Ariok->AI()->SetGUID(player->GetGUID());
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

        void SetGUID(ObjectGuid guid, int32 /*p_Index*/) override
        {
            m_PlayerGuid = guid;

            if (me->HasNpcFlag(UNIT_NPC_FLAG_GOSSIP))
                me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);

            if (Player* p_Followed = ObjectAccessor::GetPlayer(*me, guid))
                me->GetMotionMaster()->MoveFollow(p_Followed, 0.2f, 5.23f);

            Talk(0);
        }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            m_IsSummoned = true;
            m_playerNeedObjective = true;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!m_IsSummoned)
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (m_playerNeedObjective)
            {
                if (m_checkObjectiveTimer <= diff)
                {
                    if (GetClosestCreatureWithEntry(me, TanaanCreatures::NpcBleedingHollowBloodchosen, 55.0f))
                        if (Player* player = ObjectAccessor::GetPlayer(*me, m_PlayerGuid))
                            if (!player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjBloodRitualOrbDestroyed))
                            {
                                player->KilledMonsterCredit(TanaanKillCredits::CreditAriokEscort);
                                m_playerNeedObjective = false;
                            }

                    m_checkObjectiveTimer = 2000;
                }
                else m_checkObjectiveTimer -= diff;
            }

            if (m_checkMustDespawnTimer <= diff)
            {
                if (Player* player = ObjectAccessor::GetPlayer(*me, m_PlayerGuid))
                    if (player->GetQuestStatus(TanaanQuests::QuestAltarAltercation) != QUEST_STATUS_INCOMPLETE ||
                        player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjBloodRitualOrbDestroyed) == 3)
                        me->DespawnOrUnsummon();

                m_checkMustDespawnTimer = 2000;
            }
            else m_checkMustDespawnTimer -= diff;

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

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (player->GetQuestStatus(TanaanQuests::QuestAltarAltercation) == QUEST_STATUS_INCOMPLETE)
        {
            if (player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjBloodRitualOrbDestroyed) <= 2)
            {
                player->KilledMonsterCredit(TanaanKillCredits::CreditBloodOrb);
                creature->DestroyForPlayer(player);

                if (player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjBloodRitualOrbDestroyed) == 1)
                    player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneSneakyArmy);

                if (player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjBloodRitualOrbDestroyed) == 3)
                {
                    player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneKilRoggRevealed);

                    player->RemoveAurasDueToSpell(TanaanPhases::PhaseAfterBlazeGlobal);
                    player->RemoveAurasDueToSpell(TanaanPhases::PhaseAfterBlazeAlliance);
                    player->RemoveAurasDueToSpell(TanaanPhases::PhaseAfterBlazeHorde);
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
