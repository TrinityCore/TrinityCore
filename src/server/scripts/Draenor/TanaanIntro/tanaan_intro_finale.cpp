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

#include "MotionMaster.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "tanaan_intro.h"

/// Passive Scene Object
class playerScript_taste_of_iron : public PlayerScript
{
public:
    playerScript_taste_of_iron() : PlayerScript("playerScript_taste_of_iron") { }

    void OnSceneCancel(Player* player, uint32 sceneInstanceId) override
    {
        if (!player->GetSceneMgr().HasScene(sceneInstanceId, TanaanSceneObjects::SceneShootingGallery))
            return;

        ResetAurasOnCancel(player);
    }

    void OnQuestAbandon(Player* player, const Quest* quest) override
    {
        if (player && quest && quest->GetQuestId() == TanaanQuests::QuestATasteOfIron)
        {
            player->GetSceneMgr().CancelSceneByPackageId(TanaanSceneObjects::SceneShootingGallery);
            ResetAurasOnCancel(player);
        }
    }

    void OnSceneTriggerEvent(Player* player, uint32 sceneInstanceId, std::string triggerEvent) override
    {
        if (!player->GetSceneMgr().HasScene(sceneInstanceId, TanaanSceneObjects::SceneShootingGallery))
            return;

        if (triggerEvent == "Credit")
            player->KilledMonsterCredit(TanaanKillCredits::CreditIronHordeSlain);
        else if (triggerEvent == "CancelGame")
        {
            player->GetSceneMgr().CancelScene(sceneInstanceId);
            ResetAurasOnCancel(player);
        }
    }

    void ResetAurasOnCancel(Player* player)
    {
        player->AddAura(TanaanPhases::PhaseFinalSideCanons, player);
        player->AddAura(TanaanPhases::PhaseFinalCanonDeco, player);
        player->RemoveAurasDueToSpell(TanaanSpells::SpellTasteOfIronGameAura);
    }
};

/// Passive Scene Object
class playerScript_the_home_stretch : public PlayerScript
{
public:
    playerScript_the_home_stretch() : PlayerScript("playerScript_the_home_stretch")
    {
        m_timer = 1000;
    }

    #define MAX_IRON_BASTION_PROGRESS 6
    uint32 m_timer;

    std::vector<float> m_minX =
    {
        4032.81f,
        3948.38f,
        3868.31f,
        3787.45f,
        3752.40f,
        3662.74f
    };

    std::vector<float> m_Auras =
    {
        TanaanSpells::SpellIronBastionProgressA,
        TanaanSpells::SpellIronBastionProgressB,
        TanaanSpells::SpellIronBastionProgressC,
        TanaanSpells::SpellIronBastionProgressD,
        TanaanSpells::SpellIronBastionProgressE,
        TanaanSpells::SpellIronBastionProgressF
    };

    void OnQuestReward(Player* player, const Quest* quest) override
    {
        if (player && quest && (quest->GetQuestId() == TanaanQuests::QuestTheHomeStretchAlly || quest->GetQuestId() == TanaanQuests::QuestTheHomeStretchHorde))
        {
            player->GetSceneMgr().CancelSceneByPackageId(TanaanSceneObjects::SceneFinaleIronBastion);

            if (player->GetTeamId() == TEAM_ALLIANCE)
                player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneAllianceBoat);
            else
                player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneHordeBoat);
        }
    }

    void OnQuestAbandon(Player* player, const Quest* quest) override
    {
        if (player && quest && (quest->GetQuestId() == TanaanQuests::QuestTheHomeStretchAlly || quest->GetQuestId() == TanaanQuests::QuestTheHomeStretchHorde))
            player->GetSceneMgr().CancelSceneByPackageId(TanaanSceneObjects::SceneFinaleIronBastion);
    }

    void OnSceneStart(Player* player, uint32 scenePackageID, uint32 /*sceneInstanceId*/) override
    {
        if (scenePackageID != TanaanSceneObjects::SceneFinaleIronBastion)
            return;

        Clean(player);
    }

    void OnSceneComplete(Player* player, uint32 sceneInstanceId) override
    {
        if (!player->GetSceneMgr().HasScene(sceneInstanceId, TanaanSceneObjects::SceneFinaleIronBastion))
            return;

        player->KilledMonsterCredit(TanaanKillCredits::CreditBoatsReached);

        if (player->GetPositionX() > 3558.0f)
            player->TeleportTo(TanaanZones::MapTanaan, 3558.0f, -2119.70f, 17.74f, 3.396844f);

        Clean(player);
    }

    void OnSceneCancel(Player* player, uint32 sceneInstanceId) override
    {
        if (!player->GetSceneMgr().HasScene(sceneInstanceId, TanaanSceneObjects::SceneFinaleIronBastion))
            return;

        Clean(player);
    }

    void OnSceneTriggerEvent(Player* player, uint32 sceneInstanceId, std::string triggerEvent) override
    {
        if (!player->GetSceneMgr().HasScene(sceneInstanceId, TanaanSceneObjects::SceneFinaleIronBastion))
            return;

        if (triggerEvent == "Damage")
            player->EnvironmentalDamage(DAMAGE_FIRE, urand(11230, 14320));
    }

    void OnUpdate(Player* player, uint32 diff) override
    {
        if (m_timer > diff)
        {
            m_timer -= diff;
            return;
        }

        m_timer = 1000;

        if (!player->GetSceneMgr().HasSceneWithPackageId(TanaanSceneObjects::SceneFinaleIronBastion))
            return;

        for (uint8 i = 0; i < MAX_IRON_BASTION_PROGRESS; ++i)
            if (player->GetPositionX() < m_minX[i] && !player->HasAura(m_Auras[i]))
                player->AddAura(m_Auras[i], player);
    }

    void Clean(Player* player)
    {
        for (uint8 i = 0; i < MAX_IRON_BASTION_PROGRESS; ++i)
            player->RemoveAurasDueToSpell(m_Auras[i]);
    }
};

/// Passive Scene Object
class playerScript_tanaan_scene_boat : public PlayerScript
{
public:
    playerScript_tanaan_scene_boat() : PlayerScript("playerScript_tanaan_scene_boat") { }

    void OnSceneTriggerEvent(Player* player, uint32 sceneInstanceId, std::string triggerEvent) override
    {
        if (triggerEvent == "Teleport")
        {
            if (player->GetSceneMgr().HasScene(sceneInstanceId, TanaanSceneObjects::SceneAllianceBoat))
            {
                player->TeleportTo(TanaanZones::MapDraenor, 2308.9621f, 454.9409f, 6.0f, player->GetOrientation());
                player->CompletedAchievement(TanaanAchievements::AchievementWelcomeToDreanorA);
            }
            else if (player->GetSceneMgr().HasScene(sceneInstanceId, TanaanSceneObjects::SceneHordeBoat))
            {
                player->TeleportTo(TanaanZones::MapDraenor, 5538.213379f, 5015.2690f, 13.0f, player->GetOrientation());
                player->CompletedAchievement(TanaanAchievements::AchievementWelcomeToDreanorH);
            }
        }
    }

    void OnSceneCancel(Player* player, uint32 sceneInstanceId) override
    {
        if (player->GetSceneMgr().HasScene(sceneInstanceId, TanaanSceneObjects::SceneAllianceBoat))
        {
            player->TeleportTo(TanaanZones::MapDraenor, 2308.9621f, 454.9409f, 6.0f, player->GetOrientation());
            player->CompletedAchievement(TanaanAchievements::AchievementWelcomeToDreanorA);
        }
        else if (player->GetSceneMgr().HasScene(sceneInstanceId, TanaanSceneObjects::SceneHordeBoat))
        {
            player->TeleportTo(TanaanZones::MapDraenor, 5538.213379f, 5015.2690f, 13.0f, player->GetOrientation());
            player->CompletedAchievement(TanaanAchievements::AchievementWelcomeToDreanorH);
        }
    }
};

/// 78568 - Thaelin Darkanvil
class npc_thaelin_darkanvil_tanaan : public CreatureScript
{
public:
    npc_thaelin_darkanvil_tanaan() : CreatureScript("npc_thaelin_darkanvil_tanaan") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (player->GetQuestStatus(TanaanQuests::QuestTakingATripToTheTopOfTheTank) == QUEST_STATUS_INCOMPLETE)
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Yes, I need you to help me operate that enormous tank.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, 1, creature->GetGUID());
            return true;
        }

        return false;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();

        if (action == GOSSIP_ACTION_INFO_DEF + 1)
        {
            if (player->GetQuestStatus(TanaanQuests::QuestTakingATripToTheTopOfTheTank) != QUEST_STATUS_INCOMPLETE && player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjTopOfTheTank) >= 1)
            {
                CloseGossipMenuFor(player);
                return true;
            }

            player->KilledMonsterCredit(TanaanKillCredits::CreditSpeakWithThaelin);
            CloseGossipMenuFor(player);

            player->SummonCreature(creature->GetEntry(), creature->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0, 0, true);
            player->RemoveAurasDueToSpell(TanaanPhases::PhaseBlackrockThaelinLow);
        }


        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_thaelin_darkanvil_tanaanAI(creature);
    }

    struct npc_thaelin_darkanvil_tanaanAI : public ScriptedAI
    {
        npc_thaelin_darkanvil_tanaanAI(Creature* creature) : ScriptedAI(creature) { }

        enum eEvents
        {
            EventCheckTalk      = 1,
            EventCheckSummoner  = 2
        };

        EventMap m_Events;
        ObjectGuid m_PlayerGuid;
        bool m_Summoned;

        void Reset() override
        {
            m_Summoned = false;
            m_Events.Reset();
        }

        void IsSummonedBy(Unit* summoner) override
        {
            m_Summoned = true;
            m_PlayerGuid = summoner->GetGUID();
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_VENDOR);
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);

            /// TALK
            Talk(0);

            if (Player* player = summoner->ToPlayer())
                me->GetMotionMaster()->MoveFollow(player, 0, 1.0f);

            m_Events.ScheduleEvent(eEvents::EventCheckTalk,     5000);
            m_Events.ScheduleEvent(eEvents::EventCheckSummoner, 500);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (damage >= me->GetHealth())
                me->SetFullHealth();
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == FOLLOW_MOTION_TYPE)
            {
                if (Player* escortedPlayer = ObjectAccessor::FindPlayer(m_PlayerGuid))
                {
                    if (me->GetPositionZ() >= 67.0f ||
                        escortedPlayer->GetPositionZ() >= 67.0f)
                    {
                        Talk(3);

                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MovePoint(1, 4072.98f, -2006.38f, 67.97f);
                    }

                    me->SetSpeed(MOVE_RUN, escortedPlayer->GetSpeed(MOVE_RUN));
                }
            }
            else if (type == POINT_MOTION_TYPE)
            {
                switch (id)
                {
                    case 1:
                        me->GetMotionMaster()->MovePoint(2, 4073.19f, -2012.47f, 72.41f);
                        break;
                    case 2:
                        me->GetMotionMaster()->MovePoint(3, 4069.64f, -2013.99f, 72.57f);
                        break;
                    case 3:
                        me->GetMotionMaster()->MovePoint(4, 4066.15f, -2014.03f, 75.06f);
                        break;
                    case 4:
                        me->GetMotionMaster()->MovePoint(5, 4065.71f, -2019.11f, 75.31f);
                        break;
                    case 5:
                        me->GetMotionMaster()->MovePoint(6, 4063.77f, -2020.11f, 75.47f);
                        break;
                    case 6:
                    {
                        me->SetFacingTo(2.5f);
                        me->DespawnOrUnsummon();

                        if (Player* player = ObjectAccessor::GetPlayer(*me, m_PlayerGuid))
                            player->KilledMonsterCredit(TanaanKillCredits::CreditEscortThaelin);

                        break;
                    }

                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            m_Events.Update(diff);

            if (!m_Summoned)
                return;

            switch (m_Events.ExecuteEvent())
            {
                case eEvents::EventCheckTalk:
                    if (GetClosestCreatureWithEntry(me, TanaanCreatures::NpcGogluk, 85.0f))
                        Talk(1); ///< TALK
                    else
                        m_Events.ScheduleEvent(eEvents::EventCheckTalk, 800);
                    break;
                case eEvents::EventCheckSummoner:
                {
                    if (Player* l_EscortedPlayer = ObjectAccessor::FindPlayer(m_PlayerGuid))
                    {
                        if (Unit* target = l_EscortedPlayer->GetVictim())
                        {
                            if (!me->IsWithinMeleeRange(target))
                            {
                                Position pos = l_EscortedPlayer->GetPosition();
                                me->GetMotionMaster()->MoveCharge(pos.m_positionX, pos.m_positionY, pos.m_positionZ, me->GetSpeed(MOVE_RUN));
                                return;
                            }

                            me->Attack(target, true);
                            DoMeleeAttackIfReady();
                            return;
                        }

                        if (l_EscortedPlayer->GetQuestStatus(TanaanQuests::QuestTakingATripToTheTopOfTheTank) != QUEST_STATUS_INCOMPLETE)
                        {
                            me->DespawnOrUnsummon();
                            return;
                        }
                    }

                    m_Events.ScheduleEvent(eEvents::EventCheckSummoner, 500);
                    break;
                }
                default:
                    break;
            }
        }
    };
};

/// 86039 - Gogluk
class npc_tanaan_gogluk : public CreatureScript
{
public:
    npc_tanaan_gogluk() : CreatureScript("npc_tanaan_gogluk")
    {
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_tanaan_goglukAI(creature);
    }

    struct npc_tanaan_goglukAI : public ScriptedAI
    {
        npc_tanaan_goglukAI(Creature* creature) : ScriptedAI(creature) { }

        void SetPassengersFightingOrDespawn(uint8 p_Seat, bool p_Despawn, Vehicle* p_Vehicle, Unit* target = nullptr)
        {
            if (Unit* l_Passenger = p_Vehicle->GetPassenger(p_Seat))
            {
                if (Creature* creature = l_Passenger->ToCreature())
                {
                    if (creature->GetAI())
                    {
                        if (!p_Despawn)
                        {
                            creature->SetInCombatWith(target);
                            creature->AI()->DoAction(1);
                        }
                        else
                            creature->DespawnOrUnsummon();
                    }
                }
            }
        }

        void EnterCombat(Unit* attacker) override
        {
            if (me->IsVehicle())
            {
                if (Vehicle* l_Vehicle = me->GetVehicleKit())
                {
                    SetPassengersFightingOrDespawn(0, false, l_Vehicle, attacker);
                    SetPassengersFightingOrDespawn(1, false, l_Vehicle, attacker);
                }
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (me->IsVehicle())
            {
                if (Vehicle* l_Vehicle = me->GetVehicleKit())
                {
                    SetPassengersFightingOrDespawn(0, true, l_Vehicle);
                    SetPassengersFightingOrDespawn(1, true, l_Vehicle);
                }
            }
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            if (me->IsVehicle())
            {
                if (Vehicle* l_Vehicle = me->GetVehicle())
                {
                    if (Unit* l_Passenger = l_Vehicle->GetPassenger(0))
                        l_Passenger->CombatStop(true);

                    if (Unit* l_Passenger = l_Vehicle->GetPassenger(1))
                        l_Passenger->CombatStop(true);
                }
            }
        }
    };
};

/// 86690/86691 - Gogluk Adds
class npc_tanaan_gogluk_adds : public CreatureScript
{
public:
    npc_tanaan_gogluk_adds() : CreatureScript("npc_tanaan_gogluk_adds")
    {
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_tanaan_gogluk_addsAI(creature);
    }

    struct npc_tanaan_gogluk_addsAI : public ScriptedAI
    {
        npc_tanaan_gogluk_addsAI(Creature* creature) : ScriptedAI(creature) { }

        EventMap m_Events;

        enum eEvents
        {
            EventCannonBarrage = 1,
            EventMachineGun = 2
        };

        void DoAction(int32 const /*action*/) override
        {
            switch (me->GetEntry())
            {
                case TanaanCreatures::NpcCannonTurret:
                    m_Events.ScheduleEvent(eEvents::EventCannonBarrage, 1000);
                    break;
                case TanaanCreatures::NpcGunTurret:
                    m_Events.ScheduleEvent(eEvents::EventMachineGun, 3000);
                    break;
                default:
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            m_Events.Update(diff);

            switch (m_Events.ExecuteEvent())
            {
                case eEvents::EventCannonBarrage:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, TanaanSpells::SpellCannonBarrage, false);
                    m_Events.ScheduleEvent(eEvents::EventCannonBarrage, 80000);
                    break;
                case eEvents::EventMachineGun:
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, TanaanSpells::SpellMachineGun, true);
                    m_Events.ScheduleEvent(eEvents::EventMachineGun, 8000);
                    break;
                default:
                    break;
            }
        }
    };
};

/// 80521 - Thaelin Darkanvil
class npc_thaelin_tanaan_questgiver : public CreatureScript
{
public:
    npc_thaelin_tanaan_questgiver() : CreatureScript("npc_thaelin_tanaan_questgiver")
    {
    }

    bool OnQuestAccept(Player* player, Creature* creature, const Quest* quest) override
    {
        if (quest->GetQuestId() == TanaanQuests::QuestATasteOfIron)
        {
            // On enlève Thaelin avant le début de la cinématique, pour qu'il revienne correctement après coté client
            player->RemoveAurasDueToSpell(TanaanPhases::PhaseFinalThaelinCanon);

            player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneShootingGallery, SCENEFLAG_NOT_CANCELABLE | SCENEFLAG_UNK16);
        }
        else if (quest->GetQuestId() == TanaanQuests::QuestTheHomeStretchAlly || quest->GetQuestId() == TanaanQuests::QuestTheHomeStretchHorde)
        {
            player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneFinaleIronBastion, SCENEFLAG_NOT_CANCELABLE | SCENEFLAG_UNK16);

            if (creature->GetAI())
                creature->GetAI()->SetGUID(player->GetGUID());
        }

        return false;
    }
};

/// 231261 - Worldbreaker Side Turret
class gob_worldbreaker_side_turret : public GameObjectScript
{
public:
    gob_worldbreaker_side_turret() : GameObjectScript("gob_worldbreaker_side_turret")
    {
    }

    bool OnGossipHello(Player* player, GameObject* /*gameObject*/) override
    {
        if (player->GetQuestStatus(TanaanQuests::QuestATasteOfIron) == QUEST_STATUS_INCOMPLETE && player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjIronHordeSlain) < 200)
        {
            player->RemoveAurasDueToSpell(TanaanPhases::PhaseFinalSideCanons);
            player->GetSceneMgr().RecreateScene(TanaanSceneObjects::SceneShootingGallery, SCENEFLAG_NOT_CANCELABLE | SCENEFLAG_UNK16);
            player->AddAura(TanaanSpells::SpellTasteOfIronGameAura, player); // Aura pour lancer le scene object
            player->KilledMonsterCredit(TanaanKillCredits::CreditEnterWorldbreakerTurret);
        }
        return true;
    }

    struct gob_worldbreaker_side_turretAI : public GameObjectAI
    {
        gob_worldbreaker_side_turretAI(GameObject* p_Go) : GameObjectAI(p_Go)
        {
            //go->SetCancelAnim(true);

            if (go->GetPositionX() > 4060.0f || go->GetPositionY() > -2020.0f)
                go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
        }
    };

    GameObjectAI* GetAI(GameObject* p_Go) const override
    {
        return new gob_worldbreaker_side_turretAI(p_Go);
    }
};

/// 232538 - Main Cannon Trigger
class gob_main_cannon_trigger : public GameObjectScript
{
public:
    gob_main_cannon_trigger() : GameObjectScript("gob_main_cannon_trigger")
    {
    }

    bool OnGossipHello(Player* player, GameObject* /*gameObject*/) override
    {
        if (player->GetQuestStatus(TanaanQuests::QuestATasteOfIron) == QUEST_STATUS_INCOMPLETE && player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjIronHordeSlain) >= 200)
        {
            player->GetSceneMgr().CancelSceneByPackageId(TanaanSceneObjects::SceneShootingGallery);
            player->AddAura(TanaanPhases::PhaseFinalSideCanons, player);
            player->AddAura(TanaanPhases::PhaseFinalCanonDeco, player);

            player->KillCreditGO(TanaanKillCredits::CreditMainCannonTrigger);
            player->CastSpell(player, TanaanSpells::SpellFinaleCinematic, true);
        }

        return true;
    }
};

void AddSC_tanaan_intro_finale()
{
    new npc_thaelin_darkanvil_tanaan();
    new npc_tanaan_gogluk();
    new npc_tanaan_gogluk_adds();
    new npc_thaelin_tanaan_questgiver();
    new gob_worldbreaker_side_turret();
    new gob_main_cannon_trigger();

    new playerScript_taste_of_iron();
    new playerScript_the_home_stretch();
    new playerScript_tanaan_scene_boat();
}
