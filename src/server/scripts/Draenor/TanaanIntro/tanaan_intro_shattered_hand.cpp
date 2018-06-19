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
#include "ObjectAccessor.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "tanaan_intro.h"
#include "TemporarySummon.h"

Position g_ShatteredHandSpawn[4] =
{
    { 4419.8500f, -2783.7099f, 15.9326f, 4.84f }, ///< Pos 0, extreme right
    { 4408.6499f, -2786.5200f, 14.3980f, 4.82f }, ///< Pos 1, right
    { 4395.9501f, -2786.4499f, 14.4047f, 4.82f }, ///< Pos 2, left
    { 4384.6699f, -2781.9299f, 15.9378f, 4.58f }  ///< Pos 3, extreme left
};

/// Passive Scene Object
class playerscript_bridge_destruction : public PlayerScript
{
public:
    playerscript_bridge_destruction() : PlayerScript("playerscript_bridge_destruction") { }

    void OnSceneTriggerEvent(Player* player, uint32 sceneInstanceId, std::string triggerEvent) override
    {
        if (!player->GetSceneMgr().HasScene(sceneInstanceId, TanaanSceneObjects::SceneBridgeDestruction))
            return;

        if (triggerEvent == "Bridge")
        {
            player->RemoveAurasDueToSpell(TanaanPhases::PhaseBridgeIntact);
            player->AddAura(TanaanPhases::PhaseBridgeDestroyed, player);
        }
    }
};

/// Passive Scene Object
class playerScript_a_potential_ally : public PlayerScript
{
public:
    playerScript_a_potential_ally() : PlayerScript("playerScript_a_potential_ally") { }

    void OnQuestReward(Player* player, const Quest* quest) override
    {
        switch (quest->GetQuestId())
        {
            case TanaanQuests::QuestAPotentialAlly:
            case TanaanQuests::QuestAPotentialAllyHorde:
                player->GetSceneMgr().CancelSceneByPackageId(TanaanSceneObjects::SceneRingOfFire);
            default:
                break;
        }
    }

    void OnQuestAbandon(Player* player, const Quest* quest) override
    {
        switch (quest->GetQuestId())
        {
            case TanaanQuests::QuestAPotentialAlly:
            case TanaanQuests::QuestAPotentialAllyHorde:
                player->GetSceneMgr().CancelSceneByPackageId(TanaanSceneObjects::SceneRingOfFire);
                player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneRingOfFire);
            default:
                break;
        }
    }

    void OnSceneTriggerEvent(Player* player, uint32 sceneInstanceId, std::string triggerEvent) override
    {
        if (!player->GetSceneMgr().HasScene(sceneInstanceId, TanaanSceneObjects::SceneRingOfFire))
            return;

        if (triggerEvent == "Fire Gone" || triggerEvent == "Credit")
        {
            if (player->GetTeamId() == TEAM_ALLIANCE)
            {
                if (!player->GetQuestObjectiveCounter(272833))
                    player->KilledMonsterCredit(79537);
            }
            else
            {
                if (!player->GetQuestObjectiveCounter(272869))
                    player->KilledMonsterCredit(78996);
            }
        }
    }
};

/// Passive Scene Object
class playerScript_kill_your_hundred : public PlayerScript
{
public:
    playerScript_kill_your_hundred() : PlayerScript("playerScript_kill_your_hundred") { }

    void OnQuestAbandon(Player* player, const Quest* quest) override
    {
        if (player && quest && quest->GetQuestId() == TanaanQuests::QuestKillYourHundred)
        {
            player->GetSceneMgr().CancelSceneByPackageId(TanaanSceneObjects::SceneEnterKarGathArena);
            player->TeleportTo(1265, 4234.09f, -2813.26f, 17.13f, 3.092513f);
        }
    }

    void OnSceneTriggerEvent(Player* player, uint32 sceneInstanceId, std::string triggerEvent) override
    {
        if (player->GetSceneMgr().HasScene(sceneInstanceId, TanaanSceneObjects::SceneEnterKarGathArena))
        {
            if (triggerEvent == "Phase")
            {
                if (!player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjEnterTheArena))
                    player->KilledMonsterCredit(TanaanKillCredits::CreditEnterTheArena);

                player->AddAura(TanaanPhases::PhaseArenaFight, player);
                player->AddAura(player->GetTeamId() == TEAM_ALLIANCE ? TanaanPhases::PhaseArenaFightAlliance : TanaanPhases::PhaseArenaFightHorde, player);
                player->AddAura(TanaanPhases::PhaseArenaEntranceGateClose, player);
                player->AddAura(TanaanPhases::PhaseArenaExitGateClose, player);
            }
            else if (triggerEvent == "Credit")
                player->GetSceneMgr().CancelSceneByPackageId(TanaanSceneObjects::SceneEnterKarGathArena);
        }

        if (player->GetSceneMgr().HasScene(sceneInstanceId, TanaanSceneObjects::SceneEscapingTheArena))
        {
            if (triggerEvent == "Hundred")
                player->KilledMonsterCredit(TanaanKillCredits::CreditCombattantSlainInArena);
            else if (triggerEvent == "Update")
                player->AddAura(TanaanPhases::PhaseArenaIced, player);
            else if (triggerEvent == "Credit")
            {
                player->GetSceneMgr().CancelScene(sceneInstanceId);
                // Scene flags taken from sniffs except SCENEFLAG_NOT_CANCELABLE
                player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneCaveIn, SCENEFLAG_UNK1 | SCENEFLAG_NOT_CANCELABLE | SCENEFLAG_UNK8 | SCENEFLAG_UNK16);
            }
        }
    }
};

/// Passive Scene Object
class playerScript_cave_in : public PlayerScript
{
public:
    playerScript_cave_in() : PlayerScript("playerScript_cave_in") { }

    void OnSceneTriggerEvent(Player* player, uint32 sceneInstanceId, std::string triggerEvent) override
    {
        if (!player->GetSceneMgr().HasScene(sceneInstanceId, TanaanSceneObjects::SceneCaveIn))
            return;

        if (triggerEvent == "EarlyPhase")
            player->KilledMonsterCredit(TanaanKillCredits::CreditEscapeKargathArena);
    }
};

/// 78560 - Archmage Khadgar
class npc_archmage_khadgar_bridge : public CreatureScript
{
public:
    npc_archmage_khadgar_bridge() : CreatureScript("npc_archmage_khadgar_bridge") { }

    bool OnQuestAccept(Player* player, Creature* creature, const Quest* quest) override
    {
        switch (quest->GetQuestId())
        {
            case TanaanQuests::QuestKargatharProvingGrounds:
            {
                if (TempSummon* summon = player->SummonCreature(TanaanCreatures::NpcArchmageKhadgarSum, creature->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0, 0, true))
                {
                    summon->AI()->SetGUID(player->GetGUID());
                    player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneBridgeDestruction);
                }

                break;
            }
            case TanaanQuests::QuestKillYourHundred:
            {
                player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneEnterKarGathArena, SCENEFLAG_NOT_CANCELABLE | SCENEFLAG_UNK16);
                break;
            }
            default:
                break;
        }

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_archmage_khadgar_bridgeAI(creature);
    }

    struct npc_archmage_khadgar_bridgeAI : public ScriptedAI
    {
        npc_archmage_khadgar_bridgeAI(Creature* creature) : ScriptedAI(creature) { }

        // TODO : GossipSelect
        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
            {
                if (player->GetQuestStatus(TanaanQuests::QuestAltarAltercation) == QUEST_STATUS_INCOMPLETE)
                {
                    if (player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjBloodRitualOrbDestroyed) >= 3)
                        player->KilledMonsterCredit(TanaanKillCredits::CreditFindKhadgarAtBridge);
                }
            }
        }
    };
};

/// 80244 - Archmage Khadgar (summoned)
class npc_tanaan_khadgar_bridge : public CreatureScript
{
public:
    npc_tanaan_khadgar_bridge() : CreatureScript("npc_tanaan_khadgar_bridge") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_tanaan_khadgar_bridgeAI(creature);
    }

    struct npc_tanaan_khadgar_bridgeAI : public ScriptedAI
    {
        npc_tanaan_khadgar_bridgeAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 m_DestroyTimer;
        ObjectGuid m_SummonerGuid;

        void Reset() override
        {
            m_DestroyTimer = 0;
            m_SummonerGuid = ObjectGuid::Empty;
        }

        void SetGUID(ObjectGuid guid, int32 /*id*/) override
        {
            m_SummonerGuid = guid;
            DoCastAOE(TanaanSpells::SpellMeteorShower);
            m_DestroyTimer = 8000;
        }

        void UpdateAI(uint32 diff) override
        {
            if (m_DestroyTimer)
            {
                if (m_DestroyTimer <= diff)
                {
                    if (!m_SummonerGuid)
                        return;

                    me->GetMotionMaster()->MovePoint(1, 4213.2266f, -2786.2f, 23.398f);
                    m_DestroyTimer = 0;
                }
                else
                    m_DestroyTimer -= diff;
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id == 1)
                me->GetMotionMaster()->MovePoint(2, 4229.7402f, -2812.96f, 17.2016f);
            else
            {
                me->SetFacingTo(6.242590f);

                if (Player* pSummoner = ObjectAccessor::FindPlayer(m_SummonerGuid))
                    if (pSummoner && !pSummoner->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjFollowKhadgar))
                        pSummoner->KilledMonsterCredit(TanaanKillCredits::CreditFollowKhadgar);

                me->DespawnOrUnsummon();
            }
        }
    };
};

class npc_tanaan_mandragora : public CreatureScript
{
public:
    npc_tanaan_mandragora() : CreatureScript("npc_tanaan_mandragora")
    {
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_tanaan_mandragoraAI(creature);
    }

    struct npc_tanaan_mandragoraAI : public ScriptedAI
    {
        npc_tanaan_mandragoraAI(Creature* creature) : ScriptedAI(creature) { }

        EventMap m_Events;

        enum eDatas
        {
            EventChomp          = 1,
            EventImpactSplit    = 2,

            SpellChomp          = 161533,
            SpellImpactSplit    = 161299
        };

        void Reset() override
        {
            m_Events.Reset();
        }

        void EnterCombat(Unit* /*target*/) override
        {
            m_Events.ScheduleEvent(eDatas::EventChomp, 3000);
            m_Events.ScheduleEvent(eDatas::EventImpactSplit, 10000);
        }

        void UpdateAI(uint32 diff) override
        {
            m_Events.Update(diff);

            if (m_Events.ExecuteEvent() == EventChomp)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                    me->CastSpell(target, SpellChomp, false);
                m_Events.ScheduleEvent(EventChomp, 20000);
            }
            else if (m_Events.ExecuteEvent() == eDatas::EventImpactSplit)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                    me->CastSpell(target, SpellImpactSplit, false);
                m_Events.ScheduleEvent(EventImpactSplit, 20000);
            }
        }
    };
};

Position handBrawlerSpawnPositions[7] =
{
    { 4419.56f, -2784.02f, 15.874543f, 4.777872f },
    { 4408.34f, -2785.99f, 12.051762f, 4.982073f },
    { 4395.61f, -2785.14f, 13.067164f, 4.408731f },
    { 4384.75f, -2782.45f, 15.851576f, 4.718962f },
    { 4410.30f, -2869.00f, 4.622890f, 1.534178f },
    { 4436.10f, -2791.20f, 18.259199f, 4.055340f },
    { 4367.85f, -2789.80f, 18.218470f, 5.481587f }
};

std::map<ObjectGuid, std::list<ObjectGuid> > arenaFighterCountByNpc;

/// 79097 - Kargath Bladefist
class npc_kargath_bladefist : public CreatureScript
{
public:
    npc_kargath_bladefist() : CreatureScript("npc_kargath_bladefist") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_kargath_bladefistAI(creature);
    }

    struct npc_kargath_bladefistAI : public ScriptedAI
    {
        npc_kargath_bladefistAI(Creature* creature) : ScriptedAI(creature) { }

        const uint8 MAX_INITIAL_SPAWN = 30;

        EventMap m_Events;

        enum eDatas
        {
            EventCleararenaFighterCountByNpc = 1,

            MaxInitialSpawn = 30
        };


        void Reset() override
        {
            m_Events.Reset();
            m_Events.ScheduleEvent(EventCleararenaFighterCountByNpc, Seconds(10));

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);

            for (uint8 i = 0; i < MAX_INITIAL_SPAWN; ++i)
                me->SummonCreature(TanaanCreatures::NpcShatteredHandBrawler, handBrawlerSpawnPositions[urand(0, 6)], TEMPSUMMON_CORPSE_DESPAWN);
        }

        void UpdateAI(uint32 diff) override
        {
            m_Events.Update(diff);
            UpdateOperations(diff);

            std::list<ObjectGuid> guidsToRemove;

            if (m_Events.ExecuteEvent() == eDatas::EventCleararenaFighterCountByNpc)
            {
                for (auto attackerGuids : arenaFighterCountByNpc)
                {
                    for (ObjectGuid brawlerGuid : arenaFighterCountByNpc[attackerGuids.first])
                    {
                        Creature* brawler = ObjectAccessor::GetCreature(*me, brawlerGuid);

                        if (brawler && brawler->IsAlive())
                            continue;

                        guidsToRemove.push_back(brawlerGuid);
                    }
                }

                for (auto attackerGuids : arenaFighterCountByNpc)
                {
                    for (ObjectGuid guid : guidsToRemove)
                    {
                        arenaFighterCountByNpc[attackerGuids.first].remove(guid);
                    }
                }

                m_Events.Repeat(Seconds(10));
            }
        }

        void DoAction(int32 const action) override
        {
            // Spawn next brawler
            if (action == 1)
            {
                me->GetScheduler().Schedule(Milliseconds(500), [](TaskContext context) -> void
                {
                    GetContextUnit()->SummonCreature(TanaanCreatures::NpcShatteredHandBrawler, handBrawlerSpawnPositions[urand(0, 6)], TEMPSUMMON_CORPSE_DESPAWN);
                });
            }
        }
    };
};

/// 82057 - Shattered Hand Brawler
class npc_shattered_hand_brawler : public CreatureScript
{
public:
    npc_shattered_hand_brawler() : CreatureScript("npc_shattered_hand_brawler") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_shattered_hand_brawlerAI(creature);
    }

    struct npc_shattered_hand_brawlerAI : public ScriptedAI
    {
        npc_shattered_hand_brawlerAI(Creature* creature) : ScriptedAI(creature) { }

        Creature* GetNpcToAttack()
        {
            std::list<Creature*> creatureList;
            me->GetCreatureListInGrid(creatureList, 100.0f);

            creatureList.remove_if([](Creature* creature) -> bool
            {
                if (creature->getFaction() != 2580)
                    return true;

                if (creature->GetPositionX() > 4450.0f ||
                    creature->GetPositionX() < 4350.0f)
                    return true;

                if (creature->GetPositionY() > -2775.0f ||
                    creature->GetPositionY() < -2875.0f)
                    return true;

                if (arenaFighterCountByNpc[creature->GetGUID()].size() >= 2)
                    return true;

                return false;
            });

            if (!creatureList.size())
                return nullptr;

            Creature* npcToAttack = Trinity::Containers::SelectRandomContainerElement(creatureList);
            AddToAttackerList(npcToAttack);
            return npcToAttack;
        }

        void AddToAttackerList(Creature* npc)
        {
            if (npc)
                arenaFighterCountByNpc[npc->GetGUID()].push_back(me->GetGUID());
        }

        void RemoveFromAttackerListOnDeath()
        {
            for (auto attackerGuids : arenaFighterCountByNpc)
                arenaFighterCountByNpc[attackerGuids.first].remove(me->GetGUID());
        }

        void Reset() override
        {
            PhasingHandler::AddPhase(me, 180);
            PhasingHandler::AddPhase(me, 183);
            PhasingHandler::AddPhase(me, 184);
        }

        void JustReachedHome() override
        {
            me->Kill(me);
        }

        void DamageDealt(Unit* victim, uint32& damage, DamageEffectType /*damageType*/) override
        {
            if (victim->GetTypeId() == TYPEID_UNIT)
                if (victim->GetHealthPct() <= 80)
                    damage = 0;
        }

        void JustDied(Unit* killer) override
        {
            RemoveFromAttackerListOnDeath();

            if (Creature* kargath = ObjectAccessor::GetCreature(*me, kargathGuid))
                if (kargath->AI())
                    kargath->AI()->DoAction(1);

            // Si il s'est tué lui-même car il ne trouvait pas de pnjs, on ne donne pas de crédit au joueur
            if (killer == me)
                return;

            std::list<Player*> playerList;
            GetPlayerListInGrid(playerList, me, 80.0f);

            for (Player* player : playerList)
            {
                if (!player->HasQuest(TanaanQuests::QuestKillYourHundred) || !player->IsInPhase(me))
                    continue;

                if (player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjCombattantSlainAddHidden) == 99)
                    continue;

                if (player->GetQuestObjectiveCounter(TanaanQuestObjectives::ObjCombattantSlainAddHidden) == 98)
                {
                    player->RemoveAurasDueToSpell(TanaanPhases::PhaseArenaFight);
                    player->RemoveAurasDueToSpell(TanaanPhases::PhaseArenaFightAlliance);
                    player->RemoveAurasDueToSpell(TanaanPhases::PhaseArenaFightHorde);
                    player->RemoveAurasDueToSpell(TanaanPhases::PhaseArenaExitGateClose);
                    player->GetSceneMgr().PlaySceneByPackageId(TanaanSceneObjects::SceneEscapingTheArena, SCENEFLAG_NOT_CANCELABLE | SCENEFLAG_UNK16);
                }

                player->KilledMonsterCredit(TanaanKillCredits::CreditCombattantSlainInArena);
                player->KilledMonsterCredit(TanaanKillCredits::CreditCombattantSlainAdd);
            }
        }

        void IsSummonedBy(Unit* summoner) override
        {
            kargathGuid = summoner->GetGUID();

            // Si il est déjà au sol, on ne le fait pas sauter, il passe directement à l'attaque sur un PNJ
            if (me->GetPositionZ() < 10.0f)
            {
                MovementInform(EFFECT_MOTION_TYPE, 1);
                return;
            }

            Position jumpPosition;
            Position creaturePosition = me->GetPosition();
            GetPositionWithDistInFront(&creaturePosition, 5.0f, jumpPosition);
            jumpPosition.m_positionZ = 4.75f;
            me->GetMotionMaster()->MoveJump(jumpPosition, 10.0f, 10.0f, 1);
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != EFFECT_MOTION_TYPE && type != POINT_MOTION_TYPE)
                return;

            if (id == 1)
            {
                if (Creature* npcToAttack = GetNpcToAttack())
                {
                    AttackStart(npcToAttack);
                    me->getThreatManager().addThreat(npcToAttack, 20000.0f);
                }
                else
                {
                    // Pas de mob à attaquer, on le fait bouger un peu
                    // pour un visuel plus joli avant de le supprimer
                    me->GetMotionMaster()->MovePoint(2, frand(4376.39f, 4428.70f), frand(-2846.56f, -2804.52f), 5.0f);
                }
            }
            else if (id == 2)
            {
                me->Kill(me);
            }
        }

        ObjectGuid kargathGuid;
    };
};

// Est aussi utilisé par les PNJS après l'arène
class npc_tanaan_arena_helper : public CreatureScript
{
public:
    npc_tanaan_arena_helper() : CreatureScript("npc_tanaan_arena_helper")
    {
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_tanaan_arena_helperAI(creature);
    }

    struct npc_tanaan_arena_helperAI : public ScriptedAI
    {
        npc_tanaan_arena_helperAI(Creature* creature) : ScriptedAI(creature) { }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (me->GetHealthPct() <= 80)
                damage = 0;
        }
    };
};

/// 300006 - Final Tanaan Trigger
class npc_tanaan_napestone_riverbeast : public CreatureScript
{
public:
    npc_tanaan_napestone_riverbeast() : CreatureScript("npc_tanaan_napestone_riverbeast")
    {
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_tanaan_napestone_riverbeastAI(creature);
    }

    struct npc_tanaan_napestone_riverbeastAI : public ScriptedAI
    {
        npc_tanaan_napestone_riverbeastAI(Creature* creature) : ScriptedAI(creature) { }

        EventMap m_Events;

        enum eDatas
        {
            EventWhipSplash = 1,
            SpellWhipSplash = 167439
        };

        void Reset() override
        {
            m_Events.Reset();
        }

        void EnterCombat(Unit* /*target*/) override
        {
            m_Events.ScheduleEvent(eDatas::EventWhipSplash, Seconds(3));
        }

        void UpdateAI(uint32 diff) override
        {
            m_Events.Update(diff);

            if (m_Events.ExecuteEvent() == eDatas::EventWhipSplash)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                    me->CastSpell(target, eDatas::SpellWhipSplash, false);

                m_Events.Repeat(Seconds(12));
            }
        }
    };
};

void AddSC_tanaan_intro_shattered_hand()
{
    new npc_archmage_khadgar_bridge();
    new npc_tanaan_khadgar_bridge();
    new npc_kargath_bladefist();
    new npc_shattered_hand_brawler();
    new npc_tanaan_arena_helper();
    new npc_tanaan_napestone_riverbeast();
    new npc_tanaan_mandragora();

    new playerscript_bridge_destruction();
    new playerScript_a_potential_ally();
    new playerScript_kill_your_hundred();
    new playerScript_cave_in();
}
