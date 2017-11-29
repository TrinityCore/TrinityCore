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

    void OnSceneCancel(Player* p_Player, uint32 p_SceneInstanceId) override
    {
        if (!p_Player->GetSceneMgr().HasScene(p_SceneInstanceId, TanaanSceneObjects::SceneShootingGallery))
            return;

        p_Player->AddAura(TanaanPhases::PhaseFinalSideCanons, p_Player);
        p_Player->AddAura(TanaanPhases::PhaseFinalCanonDeco, p_Player);
        p_Player->RemoveAurasDueToSpell(TanaanSpells::SpellTasteOfIronGameAura);
    }

    void OnQuestAbandon(Player* p_Player, const Quest* p_Quest) override
    {
        if (p_Player && p_Quest && p_Quest->GetQuestId() == TanaanQuests::QuestATasteOfIron)
        {
            p_Player->GetSceneMgr().CancelSceneByPackageId(TanaanSceneObjects::SceneShootingGallery);
            p_Player->AddAura(TanaanPhases::PhaseFinalSideCanons, p_Player);
            p_Player->AddAura(TanaanPhases::PhaseFinalCanonDeco, p_Player);
            p_Player->RemoveAurasDueToSpell(TanaanSpells::SpellTasteOfIronGameAura);
        }
    }

    void OnSceneTriggerEvent(Player* p_Player, uint32 p_SceneInstanceId, std::string p_Event) override
    {
        if (!p_Player->GetSceneMgr().HasScene(p_SceneInstanceId, TanaanSceneObjects::SceneShootingGallery))
            return;

        if (p_Event == "Credit")
            p_Player->KilledMonsterCredit(TanaanKillCredits::CreditIronHordeSlain);
        else if (p_Event == "CancelGame")
            p_Player->RemoveAurasDueToSpell(TanaanSpells::SpellTasteOfIronGameAura);
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

    void OnQuestReward(Player* p_Player, const Quest* p_Quest) override
    {
        if (p_Player && p_Quest && (p_Quest->GetQuestId() == TanaanQuests::QuestTheHomeStretchAlly || p_Quest->GetQuestId() == TanaanQuests::QuestTheHomeStretchHorde))
        {
            p_Player->GetSceneMgr().CancelSceneByPackageId(TanaanSceneObjects::SceneFinaleIronBastion);

            if (p_Player->GetTeamId() == TEAM_ALLIANCE)
                p_Player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneAllianceBoat);
            else
                p_Player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneHordeBoat);
        }
    }

    void OnQuestAbandon(Player* p_Player, const Quest* p_Quest) override
    {
        if (p_Player && p_Quest && (p_Quest->GetQuestId() == TanaanQuests::QuestTheHomeStretchAlly || p_Quest->GetQuestId() == TanaanQuests::QuestTheHomeStretchHorde))
            p_Player->GetSceneMgr().CancelSceneByPackageId(TanaanSceneObjects::SceneFinaleIronBastion);
    }
 
    void OnSceneStart(Player* p_Player, uint32 p_ScenePackageId, uint32 /*p_SceneInstanceId*/) override
    {
        if (p_ScenePackageId != TanaanSceneObjects::SceneFinaleIronBastion)
            return;

        Clean(p_Player);
    }

    void OnSceneComplete(Player* p_Player, uint32 p_SceneInstanceId) override
    {
        if (!p_Player->GetSceneMgr().HasScene(p_SceneInstanceId, TanaanSceneObjects::SceneFinaleIronBastion))
            return;

        p_Player->KilledMonsterCredit(TanaanKillCredits::CreditBoatsReached);

        if (p_Player->GetPositionX() > 3558.0f)
            p_Player->TeleportTo(TanaanZones::MapTanaan, 3558.0f, -2119.70f, 17.74f, 3.396844f);

        Clean(p_Player);
    }

    void OnSceneCancel(Player* p_Player, uint32 p_SceneInstanceId) override
    {
        if (!p_Player->GetSceneMgr().HasScene(p_SceneInstanceId, TanaanSceneObjects::SceneFinaleIronBastion))
            return;

        Clean(p_Player);
    }

    void OnSceneTriggerEvent(Player* p_Player, uint32 p_SceneInstanceId, std::string p_Event) override
    {
        if (!p_Player->GetSceneMgr().HasScene(p_SceneInstanceId, TanaanSceneObjects::SceneFinaleIronBastion))
            return;

        if (p_Event == "Damage")
            p_Player->EnvironmentalDamage(DAMAGE_FIRE, urand(11230, 14320));
    }

    void OnUpdate(Player* p_Player, uint32 p_Diff) override
    {
        if (m_timer > p_Diff)
        {
            m_timer -= p_Diff;
            return;
        }

        m_timer = 1000;

        if (!p_Player->GetSceneMgr().HasScene(TanaanSceneObjects::SceneFinaleIronBastion))
            return;

        for (uint8 i = 0; i < MAX_IRON_BASTION_PROGRESS; ++i)
            if (p_Player->GetPositionX() < m_minX[i] && !p_Player->HasAura(m_Auras[i]))
                p_Player->AddAura(m_Auras[i], p_Player);
    }

    void Clean(Player* p_Player)
    {
        for (uint8 i = 0; i < MAX_IRON_BASTION_PROGRESS; ++i)
            p_Player->RemoveAurasDueToSpell(m_Auras[i]);
    }
};

/// Passive Scene Object
class playerScript_tanaan_scene_boat : public PlayerScript
{
public:
    playerScript_tanaan_scene_boat() : PlayerScript("playerScript_tanaan_scene_boat") { }

    void OnSceneTriggerEvent(Player* p_Player, uint32 p_SceneInstanceId, std::string p_Event) override
    {
        if (p_Event == "Teleport")
        {
            if (p_Player->GetSceneMgr().HasScene(p_SceneInstanceId, TanaanSceneObjects::SceneAllianceBoat))
            {
                p_Player->TeleportTo(TanaanZones::MapDraenor, 2308.9621f, 454.9409f, 6.0f, p_Player->GetOrientation());
                p_Player->CompletedAchievement(TanaanAchievements::AchievementWelcomeToDreanorA);
            }
            else if (p_Player->GetSceneMgr().HasScene(p_SceneInstanceId, TanaanSceneObjects::SceneHordeBoat))
            {
                p_Player->TeleportTo(TanaanZones::MapDraenor, 5538.213379f, 5015.2690f, 13.0f, p_Player->GetOrientation());
                p_Player->CompletedAchievement(TanaanAchievements::AchievementWelcomeToDreanorH);
            }
        }
    }

    void OnSceneCancel(Player* p_Player, uint32 p_SceneInstanceId) override
    {
        if (p_Player->GetSceneMgr().HasScene(p_SceneInstanceId, TanaanSceneObjects::SceneAllianceBoat))
        {
            p_Player->TeleportTo(TanaanZones::MapDraenor, 2308.9621f, 454.9409f, 6.0f, p_Player->GetOrientation());
            p_Player->CompletedAchievement(TanaanAchievements::AchievementWelcomeToDreanorA);
        }
        else if (p_Player->GetSceneMgr().HasScene(p_SceneInstanceId, TanaanSceneObjects::SceneHordeBoat))
        {
            p_Player->TeleportTo(TanaanZones::MapDraenor, 5538.213379f, 5015.2690f, 13.0f, p_Player->GetOrientation());
            p_Player->CompletedAchievement(TanaanAchievements::AchievementWelcomeToDreanorH);
        }
    }
};

/// 78568 - Thaelin Darkanvil
class npc_thaelin_darkanvil_tanaan : public CreatureScript
{
public:
    npc_thaelin_darkanvil_tanaan() : CreatureScript("npc_thaelin_darkanvil_tanaan") { }

    bool OnGossipHello(Player* p_Player, Creature* p_Creature) override
    {
        if (p_Player->GetQuestStatus(TanaanQuests::QuestTakingATripToTheTopOfTheTank) == QUEST_STATUS_INCOMPLETE)
        {
            AddGossipItemFor(p_Player, GOSSIP_ICON_CHAT, "Yes, I need you to help me operate that enormous tank.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(p_Player, 1, p_Creature->GetGUID());
            return true;
        }

        return false;
    }

    bool OnGossipSelect(Player* p_Player, Creature* p_Creature, uint32 /*sender*/, uint32 p_Action) override
    {
        p_Player->PlayerTalkClass->ClearMenus();

        if (p_Action == GOSSIP_ACTION_INFO_DEF + 1)
        {
            if (p_Player->GetQuestStatus(TanaanQuests::QuestTakingATripToTheTopOfTheTank) != QUEST_STATUS_INCOMPLETE && p_Player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjTopOfTheTank) >= 1)
            {
                CloseGossipMenuFor(p_Player);
                return true;
            }

            p_Player->KilledMonsterCredit(TanaanKillCredits::CreditSpeakWithThaelin);
            CloseGossipMenuFor(p_Player);

            p_Player->SummonCreature(p_Creature->GetEntry(), p_Creature->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0, 0, true);
            p_Player->RemoveAurasDueToSpell(TanaanPhases::PhaseBlackrockThaelinLow);
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

        void IsSummonedBy(Unit* p_Summoner) override
        {
            m_Summoned = true;
            m_PlayerGuid = p_Summoner->GetGUID();
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_VENDOR);
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);

            /// TALK
            Talk(0);

            if (Player* l_Player = p_Summoner->ToPlayer())
                me->GetMotionMaster()->MoveFollow(l_Player, 0, 1.0f);

            m_Events.ScheduleEvent(eEvents::EventCheckTalk,     5000);
            m_Events.ScheduleEvent(eEvents::EventCheckSummoner, 500);
        }

        void DamageTaken(Unit* /*p_Attacker*/, uint32& p_Damage) override
        {
            if (p_Damage >= me->GetHealth())
                me->SetFullHealth();
        }

        void MovementInform(uint32 p_Type, uint32 p_Id) override
        {
            if (p_Type == FOLLOW_MOTION_TYPE)
            {
                if (me->GetPositionZ() >= 67.0f)
                {
                    /// TALK
                    Talk(3);

                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MovePoint(1, 4072.98f, -2006.38f, 67.97f);
                }

                if (Player* l_EscortedPlayer = ObjectAccessor::FindPlayer(m_PlayerGuid))
                    me->SetSpeed(MOVE_RUN, l_EscortedPlayer->GetSpeed(MOVE_RUN));
            }
            else if (p_Type == POINT_MOTION_TYPE)
            {
                switch (p_Id)
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

                        if (Player* l_Player = ObjectAccessor::GetPlayer(*me, m_PlayerGuid))
                            l_Player->KilledMonsterCredit(TanaanKillCredits::CreditEscortThaelin);

                        break;
                    }

                }
            }
        }

        void UpdateAI(uint32 const p_Diff) override
        {
            m_Events.Update(p_Diff);

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
                        if (Unit* l_Target = l_EscortedPlayer->GetVictim())
                        {
                            if (!me->IsWithinMeleeRange(l_Target))
                            {
                                Position l_Pos = l_EscortedPlayer->GetPosition();
                                me->GetMotionMaster()->MoveCharge(l_Pos.m_positionX, l_Pos.m_positionY, l_Pos.m_positionZ, me->GetSpeed(MOVE_RUN));
                                return;
                            }

                            me->Attack(l_Target, true);
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

        void SetPassengersFightingOrDespawn(uint8 p_Seat, bool p_Despawn, Vehicle* p_Vehicle, Unit* p_Target = nullptr)
        {
            if (Unit* l_Passenger = p_Vehicle->GetPassenger(p_Seat))
            {
                if (Creature* l_Creature = l_Passenger->ToCreature())
                {
                    if (l_Creature->GetAI())
                    {
                        if (!p_Despawn)
                        {
                            l_Creature->SetInCombatWith(p_Target);
                            l_Creature->AI()->DoAction(1);
                        }
                        else
                            l_Creature->DespawnOrUnsummon();
                    }
                }
            }
        }

        void EnterCombat(Unit* p_Attacker) override
        {
            if (me->IsVehicle())
            {
                if (Vehicle* l_Vehicle = me->GetVehicleKit())
                {
                    SetPassengersFightingOrDespawn(0, false, l_Vehicle, p_Attacker);
                    SetPassengersFightingOrDespawn(1, false, l_Vehicle, p_Attacker);
                }
            }
        }

        void JustDied(Unit* /*p_Killer*/) override
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

        void DoAction(int32 const /*p_Action*/) override
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

        void UpdateAI(uint32 const p_Diff) override
        {
            m_Events.Update(p_Diff);

            switch (m_Events.ExecuteEvent())
            {
                case eEvents::EventCannonBarrage:
                    if (Unit* l_Target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(l_Target, TanaanSpells::SpellCannonBarrage, false);
                    m_Events.ScheduleEvent(eEvents::EventCannonBarrage, 80000);
                    break;
                case eEvents::EventMachineGun:
                    if (Unit* l_Target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(l_Target, TanaanSpells::SpellMachineGun, true);
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

    bool OnQuestAccept(Player* p_Player, Creature* p_Creature, const Quest* p_Quest) override
    {
        if (p_Quest->GetQuestId() == TanaanQuests::QuestATasteOfIron)
        {
            // On enlève Thaelin avant le début de la cinématique, pour qu'il revienne correctement après coté client
            p_Player->RemoveAurasDueToSpell(TanaanPhases::PhaseFinalThaelinCanon);

            p_Player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneShootingGallery, SCENEFLAG_NOT_CANCELABLE | SCENEFLAG_UNK16);
        }
        else if (p_Quest->GetQuestId() == TanaanQuests::QuestTheHomeStretchAlly || p_Quest->GetQuestId() == TanaanQuests::QuestTheHomeStretchHorde)
        {
            p_Player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneFinaleIronBastion, SCENEFLAG_NOT_CANCELABLE | SCENEFLAG_UNK16);

            if (p_Creature->GetAI())
                p_Creature->GetAI()->SetGUID(p_Player->GetGUID());
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

    bool OnGossipHello(Player* p_Player, GameObject* /*p_Gameobject*/) override
    {
        if (p_Player->GetQuestStatus(34445) == QUEST_STATUS_INCOMPLETE && p_Player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjIronHordeSlain) < 200)
        {
            p_Player->RemoveAurasDueToSpell(TanaanPhases::PhaseFinalSideCanons);
            p_Player->GetSceneMgr().RecreateScene(TanaanSceneObjects::SceneShootingGallery);
            p_Player->AddAura(TanaanSpells::SpellTasteOfIronGameAura, p_Player); // Aura pour lancer le scene object
            p_Player->KilledMonsterCredit(TanaanKillCredits::CreditEnterWorldbreakerTurret);
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

    bool OnGossipHello(Player* p_Player, GameObject* /*p_Gameobject*/) override
    {
        if (p_Player->GetQuestStatus(TanaanQuests::QuestATasteOfIron) == QUEST_STATUS_INCOMPLETE && p_Player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjIronHordeSlain) >= 200)
        {
            p_Player->GetSceneMgr().CancelSceneByPackageId(TanaanSceneObjects::SceneShootingGallery);
            p_Player->AddAura(TanaanPhases::PhaseFinalSideCanons, p_Player);
            p_Player->AddAura(TanaanPhases::PhaseFinalCanonDeco, p_Player);

            p_Player->KillCreditGO(TanaanKillCredits::CreditMainCannonTrigger);
            p_Player->CastSpell(p_Player, TanaanSpells::SpellFinaleCinematic, true);
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
