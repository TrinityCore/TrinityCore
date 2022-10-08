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

#include "Conversation.h"
#include "GameObject.h"
#include "MapManager.h"
#include "ObjectMgr.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "Log.h"
#include "World.h"
#include "WorldSession.h"
#include "ScriptedGossip.h"
#include "SceneHelper.h"
#include "Spell.h"

enum
{
    QUEST_THE_LEGION_RETURNS_A = 40519,
    QUEST_THE_FALLEN_LION = 40517,

    QUEST_THE_LEGION_RETURNS_H = 43926,
    QUEST_FATE_OF_THE_HORDE = 40522,

    PHASE_DALARAN_KARAZHAN = 5829,
    QUEST_BLINK_OF_AN_EYE = 44663,
    QUEST_KHADGARS_DISCOVERY = 44555,
    SPELL_LEGION_LAUNCH_PATCH_QUEST_LAUNCH = 258792,
    SPELL_LEGION_7_2_PATCH_QUEST_LAUNCH = 239624,
    SPELL_WHISPERS_OF_A_FRIGHTENED_WORLD_PUSH = 240549,

    PHASE_STORMHEIM_HORDE = 5277,
    PHASE_STORMHEIM_ALLIANCE = 7048,
};

// 228329 & 228330 - T??ortation
class spell_dalaran_teleportation : public SpellScript
{
    PrepareSpellScript(spell_dalaran_teleportation);

    void EffectTeleportDalaranKarazhan(SpellEffIndex effIndex)
    {
        if (Player* player = GetCaster()->ToPlayer())
        {
            if (player->getLevel() < 100 || player->GetQuestStatus(QUEST_BLINK_OF_AN_EYE) != QUEST_STATUS_INCOMPLETE)
                PreventHitEffect(effIndex);
            else
            {
                if (SpellTargetPosition const* targetPosition = sSpellMgr->GetSpellTargetPosition(GetSpellInfo()->Id, effIndex))
                    if (Map* map = sMapMgr->FindMap(targetPosition->target_mapId, 0))
                        map->LoadGrid(targetPosition->target_X, targetPosition->target_Y);
            }
        }
    }

    void EffectTeleportDalaranLegion(SpellEffIndex effIndex)
    {
        if (Player* player = GetCaster()->ToPlayer())
            if (player->getLevel() < 100 || player->GetQuestStatus(QUEST_BLINK_OF_AN_EYE) == QUEST_STATUS_INCOMPLETE)
                PreventHitEffect(effIndex);
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_dalaran_teleportation::EffectTeleportDalaranKarazhan, EFFECT_0, SPELL_EFFECT_TRIGGER_SPELL);
        OnEffectLaunch += SpellEffectFn(spell_dalaran_teleportation::EffectTeleportDalaranLegion, EFFECT_1, SPELL_EFFECT_TRIGGER_SPELL);
    }
};

// 113986 - Khadgar
class npc_dalaran_karazhan_khadgar : public CreatureScript
{
public:
    npc_dalaran_karazhan_khadgar() : CreatureScript("npc_dalaran_karazhan_khadgar") { }

    enum
    {
        SPELL_PLAY_DALARAN_TELEPORTATION_SCENE = 227861
    };

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*uiSender*/, uint32 /*uiAction*/) override
    {
        player->CastSpell(player, SPELL_PLAY_DALARAN_TELEPORTATION_SCENE, true);
        return true;
    }
};

class scene_dalaran_kharazan_teleportion : public SceneScript
{
public:
    scene_dalaran_kharazan_teleportion() : SceneScript("scene_dalaran_kharazan_teleportion") { }

    void OnSceneTriggerEvent(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/, std::string const& triggerName) override
    {
        if (triggerName == "invisibledalaran")
            PhasingHandler::AddPhase(player, PHASE_DALARAN_KARAZHAN);
    }

    void OnSceneEnd(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->KilledMonsterCredit(114506);
        player->TeleportTo(1220, -827.82f, 4369.25f, 738.64f, 1.893364f);
    }
};

/*
 * Legion Dalaran
 */

 // Zone 8392
class zone_legion_dalaran_underbelly : public ZoneScript
{
public:
    zone_legion_dalaran_underbelly() : ZoneScript("zone_legion_dalaran_underbelly") { }

    void OnPlayerEnter(Player* player) override
    {
        player->SeamlessTeleportToMap(MAP_DALARAN_UNDERBELLY);
    }

    void OnPlayerExit(Player* player) override
    {
        if (player->GetMapId() == MAP_DALARAN_UNDERBELLY)
            player->SeamlessTeleportToMap(MAP_BROKEN_ISLANDS);
    }
};

enum
{
    ///Druid Quest
    ///start  from Archdruid Hamuul Runetotem once you arrive in Dalaran
    QUEST_A_SUMMONS_FROM_MOONGLADE = 40643,
    NPC_ARCHDRUID_HAMUUL_RUNETOTEM = 101061,

    ///quest 47221 The Hand of Fate
    QUEST_A_THE_HAND_OF_FATE = 47221,
    QUEST_H_THE_HAND_OF_FATE = 47835,
    CONVERSATION_A_THE_HAND_OF_FATE = 4904,
    CONVERSATION_H_THE_HAND_OF_FATE = 5337,

    QUEST_THE_DALARAN_FOUNTAIN = 40961,
    NPC_NAT_PAGLE = 102639, //88317,
    QUEST_FISH_FRENZY = 41010,

    ///Paradin Quest
    ///start  from Archdruid Hamuul Runetotem once you arrive in Dalaran
    QUEST_AN_URGENT_GATHERING = 38710,
    NPC_LORD_MAXWELL_TYROSUS = 92909,

    ///Mage Quest
    NPC_EMISSARY_AULDBRIDGE_111109 = 111109,
    NPC_MERYL_FELSTORM_102700 = 102700,

    CONVERSATION_MAGE_QUEST_START = 1263,
    QUEST_FELSTORMS_PLEA = 41035, /// after quest 44184 In the Blink of an Eye complete

    ///Death Knight Quest
    QUEST_THE_CALL_TO_WAR = 40714,
    SEPLL_CONVERSATION_THE_CALL_TO_WAR = 200226,

    ///Roge Quest
    NPC_RAVENHOLDT_COURIER_102018 = 102018,
    QUEST_CALL_OF_THE_UNCROWNED = 40832,

    ///Hunter Quest
    NPC_SNOWFEATHER_100786 = 100786,
    QUEST_NEEDS_OF_THE_HUNTERS = 40384,

    ///DH Quest
    NPC_KORVAS_BLOODTHORN_99343 = 99343,
    QUEST_CALL_OF_THE_ILLIDARI_39261 = 39261,
    QUEST_CALL_OF_THE_ILLIDARI_39047 = 39047,

    ///Monk Quest before the storm
    NPC_INITIATE_DA_NEL = 98519,
    QUEST_DA_NEL = 12103,

    ///Priest Quest
    NPC_A_HOODED_PRIESTESS = 102333, ///A
    NPC_H_HOODED_PRIESTESS = 101344, ///H
    QUEST_PRIESTLY_MATTERS = 40705,

    ///WARLOCK Quest 
    NPC_RITSSYN_FLAMESCOWL_103506 = 103506,
    QUEST_THE_SIXTH = 40716,

    ///WARRIOR Quest
    NPC_EITRIGG_93775 = 93775,
    NPC_SERGEANT_DALTON_108961 = 108961,
    QUEST_H_A_DESPERATE_PLEA = 41052,
    QUEST_A_AN_IMPORTANT_MISSION = 42814,
    QUEST_H_RETURN_TO_THE_BROKEN_SHORE = 38904,
    QUEST_A_RETURN_TO_THE_BROKEN_SHORE = 42815,

    ///Shaman
    NPC_WHISPERING_WINDS = 99549,

};
//
class zone_legion_dalaran : public ZoneScript
{
public:
    zone_legion_dalaran() : ZoneScript("zone_legion_dalaran") { }
    uint32 _insideNpc;
    uint32 _killCredit;
    Creature* creature;
    Position _positon;


    void OnTempSummonNPC(uint32 insideNpc, Player* player)
    {
        _insideNpc = insideNpc;
        if (creature = player->FindNearestCreature(_insideNpc, 100.0f))
            creature->DestroyForPlayer(player);

        _positon = Position(player->GetPositionX() + 20, player->GetPositionY() + 20, player->GetPositionZ());
        TempSummon* personalCreature = player->SummonCreature(_insideNpc, _positon, TEMPSUMMON_TIMED_DESPAWN, 60000, 0, true);
    }

    void OnTempSummonNPCOnPOS(uint32 insideNpc, Player* player, Position npcPos)
    {
        _insideNpc = insideNpc;
        if (creature = player->FindNearestCreature(_insideNpc, 100.0f))
        {
            // TODO : Remove this line when phasing is done properly
            creature->DestroyForPlayer(player);
        }

        _positon = npcPos;
        TempSummon* personalCreature = player->SummonCreature(_insideNpc, _positon, TEMPSUMMON_TIMED_DESPAWN, 3600000, 0, true);
    }
    enum BROKEN_ISLES_PATHFINDE
    {
        SPELL_BROKEN_ISLES_PATHFINDER_1 = 226342,
        SPELL_BROKEN_ISLES_PATHFINDER_2 = 233368,
    };

    void OnPlayerEnter(Player* player) override
    {
        if (player->HasAchieved(11190))//[BROKEN_ISLES_PATHFINDER]
            player->LearnSpell(SPELL_BROKEN_ISLES_PATHFINDER_1, true);
        if (player->HasAchieved(11446))//[BROKEN_ISLES_PATHFINDER]
            player->LearnSpell(SPELL_BROKEN_ISLES_PATHFINDER_2, true);

        //AGUS ARRAIVE
        if (player->IsInAlliance() && player->GetQuestStatus(QUEST_A_THE_HAND_OF_FATE) != QUEST_STATUS_REWARDED && player->getLevel() >= 110 && player->GetZoneId() == 7502)
        {
            if (const Quest* quest = sObjectMgr->GetQuestTemplate(QUEST_A_THE_HAND_OF_FATE))
                if (player->GetQuestStatus(QUEST_A_THE_HAND_OF_FATE) == QUEST_STATUS_NONE)
                {
                    player->AddQuest(quest, nullptr);
                    Conversation::CreateConversation(CONVERSATION_A_THE_HAND_OF_FATE, player, player->GetPosition(), { player->GetGUID() });
                }
        }
        if (player->IsInHorde() && player->GetQuestStatus(QUEST_H_THE_HAND_OF_FATE) != QUEST_STATUS_REWARDED && player->getLevel() >= 110 && player->GetZoneId() == 7502)
        {
            if (const Quest* quest = sObjectMgr->GetQuestTemplate(QUEST_H_THE_HAND_OF_FATE))
                if (player->GetQuestStatus(QUEST_H_THE_HAND_OF_FATE) == QUEST_STATUS_NONE)
                {
                    player->AddQuest(quest, nullptr);
                    Conversation::CreateConversation(CONVERSATION_H_THE_HAND_OF_FATE, player, player->GetPosition(), { player->GetGUID() });
                }
        }

        if (player->GetQuestStatus(QUEST_BLINK_OF_AN_EYE) == QUEST_STATUS_REWARDED && player->getLevel() >= 98 && player->GetZoneId() == 7502)
        {
            //Druid Quest
            if (player->getClass() == CLASS_DRUID && player->GetQuestStatus(QUEST_A_SUMMONS_FROM_MOONGLADE) == QUEST_STATUS_NONE)
                OnTempSummonNPC(NPC_ARCHDRUID_HAMUUL_RUNETOTEM, player);

            //Paladin Quest
            if (player->getClass() == CLASS_PALADIN && player->GetQuestStatus(QUEST_AN_URGENT_GATHERING) == QUEST_STATUS_NONE)
                OnTempSummonNPC(NPC_LORD_MAXWELL_TYROSUS, player);

            //Mage Quest phase 4598
            if (player->getClass() == CLASS_MAGE && player->GetQuestStatus(QUEST_FELSTORMS_PLEA) == QUEST_STATUS_NONE)
            {
                Conversation::CreateConversation(CONVERSATION_MAGE_QUEST_START, player, player->GetPosition(), { player->GetGUID() });

                if (const Quest* quest = sObjectMgr->GetQuestTemplate(QUEST_FELSTORMS_PLEA))
                    player->AddQuest(quest, nullptr);
            }
            //Death Knight Quest ServerToClient: SMSG_SPELL_START (0x2C3A) Length: 101 ConnIdx: 0 Time: 06/06/2018 13:41:43.782 Number: 6386
            if (player->getClass() == CLASS_DEATH_KNIGHT && player->GetQuestStatus(QUEST_THE_CALL_TO_WAR) == QUEST_STATUS_NONE)
            {
                player->CastSpell(player, SEPLL_CONVERSATION_THE_CALL_TO_WAR, true);
                if (const Quest* quest = sObjectMgr->GetQuestTemplate(QUEST_THE_CALL_TO_WAR))
                    player->AddQuest(quest, nullptr);
            }
            //Hunter Quest
            if (player->getClass() == CLASS_HUNTER && player->GetQuestStatus(QUEST_NEEDS_OF_THE_HUNTERS) == QUEST_STATUS_NONE)
                OnTempSummonNPC(NPC_SNOWFEATHER_100786, player);

            //DEMON_HUNTER Quest
            if (player->getClass() == CLASS_DEMON_HUNTER && (player->GetQuestStatus(QUEST_CALL_OF_THE_ILLIDARI_39261) == QUEST_STATUS_NONE && player->GetQuestStatus(QUEST_CALL_OF_THE_ILLIDARI_39047) == QUEST_STATUS_NONE))
                OnTempSummonNPC(NPC_KORVAS_BLOODTHORN_99343, player);

            //WARRIOR Quest
            if (player->getClass() == CLASS_WARRIOR)
            {
                if (player->IsInAlliance() && player->GetQuestStatus(QUEST_A_AN_IMPORTANT_MISSION) == QUEST_STATUS_NONE)
                    OnTempSummonNPC(NPC_SERGEANT_DALTON_108961, player);
                if (player->IsInHorde() && player->GetQuestStatus(QUEST_H_A_DESPERATE_PLEA) == QUEST_STATUS_NONE)
                    OnTempSummonNPC(NPC_EITRIGG_93775, player);
            }
            //ROGUE Quest
            if (player->getClass() == CLASS_ROGUE && player->GetQuestStatus(QUEST_CALL_OF_THE_UNCROWNED) == QUEST_STATUS_NONE)
                OnTempSummonNPC(NPC_RAVENHOLDT_COURIER_102018, player);

            //Priest Quest
            if (player->getClass() == CLASS_PRIEST && player->GetQuestStatus(QUEST_PRIESTLY_MATTERS) == QUEST_STATUS_NONE)
            {
                uint32 priestNpc = player->IsInAlliance() ? NPC_A_HOODED_PRIESTESS : NPC_H_HOODED_PRIESTESS;
                OnTempSummonNPC(priestNpc, player);
            }
            //SHAMAN Quest
            if (player->getClass() == CLASS_SHAMAN && player->GetQuestStatus(QUEST_THE_CALL_TO_WAR) == QUEST_STATUS_NONE)
                player->SummonCreature(NPC_WHISPERING_WINDS, Position(-828.6302f, 4386.04f, 738.7358f, 1.828947f), TEMPSUMMON_TIMED_DESPAWN, 60000, 0, true);

            //WARLOCK Quest
            if (player->getClass() == CLASS_WARLOCK && player->GetQuestStatus(QUEST_THE_SIXTH) == QUEST_STATUS_NONE)
                OnTempSummonNPC(NPC_RITSSYN_FLAMESCOWL_103506, player);

            //MONK Quest
            if (player->getClass() == CLASS_MONK && player->GetQuestStatus(QUEST_DA_NEL) == QUEST_STATUS_NONE)
                OnTempSummonNPC(NPC_INITIATE_DA_NEL, player);

            //achievement 10596 npc 88317,102639
            if (player->HasAchieved(10596) && player->GetQuestStatus(QUEST_THE_DALARAN_FOUNTAIN) == QUEST_STATE_COMPLETE && player->GetQuestStatus(QUEST_FISH_FRENZY) == QUEST_STATUS_NONE)
                OnTempSummonNPC(NPC_NAT_PAGLE, player);
        }

    }

    void OnPlayerExit(Player* player) override
    {
        if (creature = player->FindNearestCreature(_insideNpc, 100.0f))
        {
            // TODO : Remove this line when phasing is done properly
            creature->DestroyForPlayer(player);
        }
    }
};

enum CLASS_PHASE
{
    PHASE_CLASS_WARRIOR_HORDE = 7300,
    PHASE_CLASS_WARRIOR = 7301,
    PHASE_CLASS_WARRIOR_ALIANCE = 7302,
    PHASE_CLASS_PALADIN = 7319,
    PHASE_CLASS_HUNTER_1 = 7341,
    PHASE_CLASS_HUNTER_2 = 6763,
    PHASE_CLASS_ROGUE = 4,
    PHASE_CLASS_PRIEST = 7947,
    PHASE_CLASS_DEATH_KNIGHT = 7162,
    PHASE_CLASS_SHAMAN = 6762,
    PHASE_CLASS_MAGE = 4918,
    PHASE_CLASS_WARLOCK = 6811,
    PHASE_CLASS_MONK = 10,
    //PHASE_CLASS_DRUID = 11,
    PHASE_CLASS_DEMON_HUNTER = 5015,
    PHASE_CLASS_DEMON_HUNTER_ALLIANCE = 5020,
    PHASE_CLASS_DEMON_HUNTER_HORDE = 5021,
    PHASE_CLASS_DEMON_HUNTER_READY_TO = 5022,
    PHASE_QUEST_AZUNA = 5704,
    PHASE_QUEST_ASSAULT_ON_BROKEN_SHORE = 5705,
    PHASE_QUEST_VALSHARAH = 5706,
};
class PhaseOnDaralanArea : public PlayerScript
{
public:
    PhaseOnDaralanArea() : PlayerScript("PhaseOnDaralanArea") { }

    void OnQuestStatusChange(Player* player, uint32 /*questId*/)
    {
    //    OnCheckPhase(player);
    }
/*
    void OnCheckPhase(Player* player) AÑADIR FUNCIONES
    { 
        if (player->GetMapId() == 1220)
        {
            if (player->GetAreaId() == 7505 && player->getClass() == CLASS_PALADIN)
            {
                PhasingHandler::AddPhase(player, PHASE_CLASS_PALADIN);
                if (player->CheckQuestStatus(42120, CHECK_QUEST_COMPLETE_AND_REWARDED) && player->CheckQuestStatus(42017, CHECK_QUEST_COMPLETE_AND_REWARDED) && player->CheckQuestStatus(38376, CHECK_QUEST_COMPLETE_AND_REWARDED))
                    PhasingHandler::RemovePhase(player, PHASE_CLASS_PALADIN);
            }
            if (player->getClass() == CLASS_HUNTER)
            {
                if (player->GetAreaId() == 7502 || player->GetAreaId() == 7505)
                    PhasingHandler::AddPhase(player, PHASE_CLASS_HUNTER_1);
                if (player->GetAreaId() == 7505)
                    PhasingHandler::AddPhase(player, PHASE_CLASS_HUNTER_2);
            }
            if (player->GetAreaId() == 7505 && player->getClass() == CLASS_WARRIOR)
            {
                if (player->IsInHorde() && (player->HasQuest(QUEST_H_A_DESPERATE_PLEA) || player->HasQuest(QUEST_H_RETURN_TO_THE_BROKEN_SHORE)))
                    PhasingHandler::AddPhase(player, PHASE_CLASS_WARRIOR_HORDE);
                if (player->IsInAlliance() && (player->HasQuest(QUEST_A_AN_IMPORTANT_MISSION) || player->HasQuest(QUEST_A_RETURN_TO_THE_BROKEN_SHORE)))
                    PhasingHandler::AddPhase(player, PHASE_CLASS_WARRIOR_ALIANCE);
                PhasingHandler::AddPhase(player, PHASE_CLASS_WARRIOR);
            }
            if (player->getClass() == CLASS_DEMON_HUNTER)
            {
                if ((player->GetAreaId() == 7505) || (player->GetAreaId() == 7592))
                {
                    PhasingHandler::AddPhase(player, PHASE_CLASS_DEMON_HUNTER);
                    PhasingHandler::AddPhase(player, player->IsInAlliance() ? PHASE_CLASS_DEMON_HUNTER_ALLIANCE : PHASE_CLASS_DEMON_HUNTER_HORDE);
                    // The Hunt (Obtain the Twinblades of the Deceiver from Varedis Felsoul in Suramar.) OR Vengeance Will Be Ours (Take the Aldrachi Warblades from Caria Felsoul.)
                    if (player->CheckQuestStatus(41119, CHECK_QUEST_COMPLETE_AND_REWARDED) || player->CheckQuestStatus(39247, CHECK_QUEST_COMPLETE_AND_REWARDED) || player->CheckQuestStatus(40249, CHECK_QUEST_COMPLETE_AND_REWARDED) || player->CheckQuestStatus(41863, CHECK_QUEST_COMPLETE_AND_REWARDED))
                        PhasingHandler::AddPhase(player, PHASE_CLASS_DEMON_HUNTER_READY_TO);
                    // Eternal Vigil
                    if (player->CheckQuestStatus(42869, CHECK_QUEST_REWARDED) && !player->HasQuest(41119) && !player->HasQuest(39247) && !player->HasQuest(40249) && !player->HasQuest(41863))
                        PhasingHandler::RemovePhase(player, PHASE_CLASS_DEMON_HUNTER_READY_TO);
                }
                if (player->GetAreaId() == 8284)
                {
                    if (player->GetQuestStatus(42869) == QUEST_STATUS_INCOMPLETE)
                        player->ForceCompleteQuest(42869);
                    if (player->CheckQuestStatus(42869, CHECK_QUEST_TAKEN_AND_COMPLETE_AND_REWARDED))
                        PhasingHandler::AddPhase(player, PHASE_CLASS_DEMON_HUNTER_READY_TO);

                    if (player->CheckQuestStatus(42872, CHECK_QUEST_TAKEN))
                        PhasingHandler::AddPhase(player, 5023);
                    if (player->CheckQuestStatus(42872, CHECK_QUEST_COMPLETE_AND_REWARDED))
                    {
                        PhasingHandler::RemovePhase(player, 5023);
                        PhasingHandler::AddPhase(player, 5024);
                    }

                }
            }
            if (player->getClass() == CLASS_SHAMAN)
            {
                if ((player->GetAreaId() == 7505) || (player->GetAreaId() == 7592) || (player->GetAreaId() == 7581))
                    PhasingHandler::AddPhase(player, PHASE_CLASS_SHAMAN);
            }
            if (player->getClass() == CLASS_WARLOCK)
            {
                if ((player->GetAreaId() == 7505) || (player->GetAreaId() == 7592))
                    PhasingHandler::AddPhase(player, PHASE_CLASS_WARLOCK);
            }
            if (player->getClass() == CLASS_PRIEST)
            {
                if (player->GetAreaId() == 7596)
                {
                    if (player->CheckQuestStatus(41957, CHECK_QUEST_TAKEN_AND_COMPLETE_AND_REWARDED))
                        PhasingHandler::AddPhase(player, PHASE_CLASS_PRIEST);
                    if (player->CheckQuestStatus(41967, CHECK_QUEST_COMPLETE_AND_REWARDED))
                        PhasingHandler::RemovePhase(player, PHASE_CLASS_PRIEST);
                }
                if (player->GetAreaId() == 7505)
                {
                    if (player->CheckQuestStatus(41967, CHECK_QUEST_TAKEN_AND_COMPLETE))
                        PhasingHandler::AddPhase(player, PHASE_CLASS_PRIEST);
                    if (player->CheckQuestStatus(41967, CHECK_QUEST_REWARDED))
                        PhasingHandler::RemovePhase(player, PHASE_CLASS_PRIEST);
                }
                //6266 6298 6265 6310 6317 6330
                if (player->GetAreaId() == 8143)
                {
                    if (player->CheckQuestStatus(41967, CHECK_QUEST_TAKEN))
                        PhasingHandler::AddPhase(player, 6266);
                    if (player->CheckQuestStatus(41967, CHECK_QUEST_COMPLETE_AND_REWARDED))
                    {
                        PhasingHandler::RemovePhase(player, 6266);
                        PhasingHandler::AddPhase(player, 6265);
                    }
                    if (player->CheckQuestStatus(41993, CHECK_QUEST_TAKEN))
                    {
                        PhasingHandler::RemovePhase(player, 6265);
                        PhasingHandler::AddPhase(player, 6310);
                    }
                    if (player->CheckQuestStatus(41993, CHECK_QUEST_COMPLETE_AND_REWARDED))
                    {
                        PhasingHandler::RemovePhase(player, 6265);
                        PhasingHandler::RemovePhase(player, 6310);
                        PhasingHandler::AddPhase(player, 6330);
                    }

                    if (player->CheckQuestStatus(42074, CHECK_QUEST_COMPLETE_AND_REWARDED))
                    {
                        PhasingHandler::RemovePhase(player, 6265);
                        PhasingHandler::RemovePhase(player, 6310);
                        PhasingHandler::RemovePhase(player, 6330);
                    }
                }
            }
            if (player->getClass() == CLASS_DEATH_KNIGHT)
            {
                if ((player->GetAreaId() == 7505) || (player->GetAreaId() == 7592))
                    if (player->CheckQuestStatus(40714, CHECK_QUEST_TAKEN_AND_COMPLETE_AND_REWARDED))
                        PhasingHandler::AddPhase(player, PHASE_CLASS_DEATH_KNIGHT);
            }
            if (player->GetAreaId() == 7502)
            {
                if (player->GetQuestStatus(39864) == QUEST_STATUS_INCOMPLETE)
                    player->KilledMonsterCredit(97377);
                if (player->GetQuestStatus(39735) == QUEST_STATUS_INCOMPLETE)
                    player->KilledMonsterCredit(97377);
            }
        }
        if (player->GetAreaId() == 7505)
        {
            if (player->CheckQuestStatus(46734, CHECK_QUEST_NOT_REWARDED))
                PhasingHandler::AddPhase(player, PHASE_QUEST_ASSAULT_ON_BROKEN_SHORE);
            else if (player->CheckQuestStatus(46734, CHECK_QUEST_REWARDED))
                PhasingHandler::RemovePhase(player, PHASE_QUEST_ASSAULT_ON_BROKEN_SHORE);
            if (player->CheckQuestStatus(39731, CHECK_QUEST_TAKEN_AND_COMPLETE_AND_REWARDED) || player->CheckQuestStatus(39861, CHECK_QUEST_TAKEN))
                PhasingHandler::AddPhase(player, PHASE_QUEST_VALSHARAH);
            if (player->CheckQuestStatus(39861, CHECK_QUEST_REWARDED))
                PhasingHandler::RemovePhase(player, PHASE_QUEST_VALSHARAH);

            if (player->CheckQuestStatus(39718, CHECK_QUEST_TAKEN_AND_COMPLETE_AND_REWARDED) || player->CheckQuestStatus(41220, CHECK_QUEST_TAKEN))
                PhasingHandler::AddPhase(player, PHASE_QUEST_AZUNA);
            if (player->CheckQuestStatus(41220, CHECK_QUEST_REWARDED))
                PhasingHandler::RemovePhase(player, PHASE_QUEST_AZUNA);
        }
        if (player->GetAreaId() == 7502)
        {
            //horde            
         /*   if (player->CheckQuestStatus(39864, CHECK_QUEST_TAKEN_AND_COMPLETE_AND_REWARDED) || player->CheckQuestStatus(44701, CHECK_QUEST_TAKEN_AND_COMPLETE_AND_REWARDED))
                PhasingHandler::AddPhase(player, PHASE_STORMHEIM_HORDE);
            if (player->CheckQuestStatus(39801, CHECK_QUEST_REWARDED))
                PhasingHandler::RemovePhase(player, PHASE_STORMHEIM_HORDE);
            //alliance
            if (player->CheckQuestStatus(39735, CHECK_QUEST_TAKEN_AND_COMPLETE_AND_REWARDED) || player->CheckQuestStatus(44700, CHECK_QUEST_TAKEN_AND_COMPLETE_AND_REWARDED))
                PhasingHandler::AddPhase(player, PHASE_STORMHEIM_ALLIANCE);
            if (player->CheckQuestStatus(38052, CHECK_QUEST_REWARDED))
                PhasingHandler::RemovePhase(player, PHASE_STORMHEIM_ALLIANCE);
        }
    }
    */
    void OnSpellCast(Player* player, Spell* spell, bool /*skipCheck*/)
    {
        if (spell->GetSpellInfo()->Id == 220513)
            player->TeleportTo(1624, Position(-4242.29f, -11480.4f, 9.495f, 5.97674f));
    }
};

struct npc_emissary_auldbridge_111109 : public ScriptedAI
{
    npc_emissary_auldbridge_111109(Creature* creature) : ScriptedAI(creature) { Initialize(); }
    enum Texts
    {
        SAY_FIRST_LINE = 0, ///
        SAY_SECOND_LINE = 1,///
        SAY_THIRD_LINE = 2, ///
    };
    enum DataTypes
    {
        DATA_TALK_1 = 1,
        DATA_TALK_2 = 2,
        DATA_TALK_3 = 3,
        DATA_GIVE_QUEST_CHECK = 4,
    };

    void Initialize()
    {
        m_playerGUID = ObjectGuid::Empty;
    }

    void sQuestReward(Player* player, Quest const* quest, uint32 /*opt*/)  override
    {
        if (quest->GetQuestId() == QUEST_BLINK_OF_AN_EYE)
        {
            m_playerGUID = player->GetGUID();
            events.ScheduleEvent(DATA_TALK_1, 1s);
        }
    }
    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);
        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case DATA_TALK_1:
            {
                Talk(SAY_FIRST_LINE);
                events.ScheduleEvent(DATA_TALK_2, 3s);
                break;
            }
            case DATA_TALK_2:
            {
                Talk(SAY_SECOND_LINE);
                events.ScheduleEvent(DATA_TALK_3, 3s);
                break;
            }
            case DATA_TALK_3:
            {
                if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                    Talk(SAY_THIRD_LINE, player);
                events.ScheduleEvent(DATA_GIVE_QUEST_CHECK, 3s);
                break;
            }
            case DATA_GIVE_QUEST_CHECK:
            {
                CheckQuestGive();
                break;
            }
            }
        }
    }
    void OnTempSummonNPC(uint32 insideNpc, Player* player)
    {
        if (Creature* creature = player->FindNearestCreature(insideNpc, 100.0f))
            creature->DespawnOrUnsummon(1000);

        Position _positon = me->GetPosition();
        GetPositionWithDistInFront(me, 15.f, _positon);

        if (TempSummon* personalCreature = player->SummonCreature(insideNpc, _positon, TEMPSUMMON_TIMED_DESPAWN, 60000, 0, true))
            personalCreature->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, personalCreature->GetFollowAngle());
    }
    void CheckQuestGive()
    {

        if (!m_playerGUID.IsEmpty())
        {
            if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                if (player->GetQuestStatus(QUEST_BLINK_OF_AN_EYE) == QUEST_STATUS_REWARDED && player->getLevel() >= 98 && player->GetZoneId() == 7502 && player->IsInWorld() || player->IsAlive())
                {
                    //Druid Quest
                    if (player->getClass() == CLASS_DRUID && player->GetQuestStatus(QUEST_A_SUMMONS_FROM_MOONGLADE) == QUEST_STATUS_NONE)
                        OnTempSummonNPC(NPC_ARCHDRUID_HAMUUL_RUNETOTEM, player);

                    //Paladin Quest
                    if (player->getClass() == CLASS_PALADIN && player->GetQuestStatus(QUEST_AN_URGENT_GATHERING) == QUEST_STATUS_NONE)
                        OnTempSummonNPC(NPC_LORD_MAXWELL_TYROSUS, player);

                    //Mage Quest phase 4598
                    if (player->getClass() == CLASS_MAGE && player->GetQuestStatus(QUEST_FELSTORMS_PLEA) == QUEST_STATUS_NONE)
                    {
                        Conversation::CreateConversation(CONVERSATION_MAGE_QUEST_START, player, player->GetPosition(), { player->GetGUID() });

                        if (const Quest* quest = sObjectMgr->GetQuestTemplate(QUEST_FELSTORMS_PLEA))
                            player->AddQuest(quest, nullptr);
                    }
                    //Death Knight Quest ServerToClient: SMSG_SPELL_START (0x2C3A) Length: 101 ConnIdx: 0 Time: 06/06/2018 13:41:43.782 Number: 6386
                    if (player->getClass() == CLASS_DEATH_KNIGHT && player->GetQuestStatus(QUEST_THE_CALL_TO_WAR) == QUEST_STATUS_NONE)
                    {
                        player->CastSpell(player, SEPLL_CONVERSATION_THE_CALL_TO_WAR, true);
                        if (const Quest* quest = sObjectMgr->GetQuestTemplate(QUEST_THE_CALL_TO_WAR))
                            player->AddQuest(quest, nullptr);

                    }
                    //Hunter Quest
                    if (player->getClass() == CLASS_HUNTER && player->GetQuestStatus(QUEST_NEEDS_OF_THE_HUNTERS) == QUEST_STATUS_NONE)
                        OnTempSummonNPC(NPC_SNOWFEATHER_100786, player);

                    //DEMON_HUNTER Quest
                    if (player->getClass() == CLASS_DEMON_HUNTER && (player->GetQuestStatus(QUEST_CALL_OF_THE_ILLIDARI_39261) == QUEST_STATUS_NONE || player->GetQuestStatus(QUEST_CALL_OF_THE_ILLIDARI_39047) == QUEST_STATUS_NONE))
                        OnTempSummonNPC(NPC_KORVAS_BLOODTHORN_99343, player);

                    //WARRIOR Quest
                    if (player->getClass() == CLASS_WARRIOR)
                    {
                        if (player->IsInAlliance() && player->GetQuestStatus(QUEST_A_AN_IMPORTANT_MISSION) == QUEST_STATUS_NONE)
                            OnTempSummonNPC(NPC_SERGEANT_DALTON_108961, player);
                        if (player->IsInHorde() && player->GetQuestStatus(QUEST_H_A_DESPERATE_PLEA) == QUEST_STATUS_NONE)
                            OnTempSummonNPC(NPC_EITRIGG_93775, player);
                    }
                    //ROGUE Quest
                    if (player->getClass() == CLASS_ROGUE && player->GetQuestStatus(QUEST_CALL_OF_THE_UNCROWNED) == QUEST_STATUS_NONE)
                        OnTempSummonNPC(NPC_RAVENHOLDT_COURIER_102018, player);

                    //Priest Quest
                    if (player->getClass() == CLASS_PRIEST && player->GetQuestStatus(QUEST_PRIESTLY_MATTERS) == QUEST_STATUS_NONE)
                    {
                        uint32 priestNpc = player->IsInAlliance() ? NPC_A_HOODED_PRIESTESS : NPC_H_HOODED_PRIESTESS;
                        OnTempSummonNPC(priestNpc, player);
                    }
                    //SHAMAN Quest
                    if (player->getClass() == CLASS_SHAMAN && player->GetQuestStatus(QUEST_THE_CALL_TO_WAR) == QUEST_STATUS_NONE)
                        player->SummonCreature(NPC_WHISPERING_WINDS, Position(-828.6302f, 4386.04f, 738.7358f, 1.828947f), TEMPSUMMON_TIMED_DESPAWN, 60000, 0, true);

                    //WARLOCK Quest
                    if (player->getClass() == CLASS_WARLOCK && player->GetQuestStatus(QUEST_THE_SIXTH) == QUEST_STATUS_NONE)
                        OnTempSummonNPC(NPC_RITSSYN_FLAMESCOWL_103506, player);

                    //MONK Quest
                    if (player->getClass() == CLASS_MONK && player->GetQuestStatus(QUEST_DA_NEL) == QUEST_STATUS_NONE)
                        OnTempSummonNPC(NPC_INITIATE_DA_NEL, player);
                }

        }

        //RemovePlayer();  
    }
private:
    EventMap events;
    std::set<ObjectGuid> pList;
    ObjectGuid   m_playerGUID;
};


/*******************************************************
* npc_guard_dalaran_legion
*******************************************************/

enum Spells
{
    SPELL_TRESPASSER_A = 225512,
    SPELL_TRESPASSER_H = 225574,
};

enum NPCs // All outdoor guards are within 35.0f of these NPCs
{
    NPC_APPLEBOUGH_A = 96990,
    NPC_SWEETBERRY_H = 96784,
    NPC_GILNEAN_GUARD = 108323,
    NPC_FORSAKEN_GUARD = 103626,
};

struct npc_guard_dalaran_legion : public ScriptedAI
{
    npc_guard_dalaran_legion(Creature* creature) : ScriptedAI(creature)
    {
        creature->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
        creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_NORMAL, true);
        creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, true);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld() || who->GetZoneId() != 7502)
            return;

        if (!me->IsWithinDist(who, 65.0f, false))
            return;

        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();

        if (!player || player->IsGameMaster() || player->IsBeingTeleported())
            return;

        switch (me->GetEntry())
        {
        case NPC_GILNEAN_GUARD:
            if (player->GetTeam() == HORDE)              // Horde unit found in Alliance area
            {
                if (GetClosestCreatureWithEntry(me, NPC_APPLEBOUGH_A, 32.0f))
                {
                    if (me->isInBackInMap(who, 12.0f))   // In my line of sight, "outdoors", and behind me
                        player->CastSpell(player, SPELL_TRESPASSER_A, true); // Teleport the Horde unit out                          
                }
                else                                      // In my line of sight, and "indoors"
                {
                    if (me->isInFrontInMap(who, 12.0f))
                        player->CastSpell(player, SPELL_TRESPASSER_A, true);    // Teleport the Horde unit out
                }

            }
            break;
        case NPC_FORSAKEN_GUARD:
            if (player->GetTeam() == ALLIANCE)           // Alliance unit found in Horde area
            {
                if (GetClosestCreatureWithEntry(me, NPC_SWEETBERRY_H, 32.0f))
                {
                    if (me->isInBackInMap(who, 12.0f))   // In my line of sight, "outdoors", and behind me
                        player->CastSpell(player, SPELL_TRESPASSER_H, true); // Teleport the Alliance unit out
                }
                else                                      // In my line of sight, and "indoors"
                {
                    if (me->isInFrontInMap(who, 12.0f))
                        player->CastSpell(player, SPELL_TRESPASSER_H, true);     // Teleport the Alliance unit out
                }
            }
            break;
        }
        return;
    }
};

///A Mysterious Note 266619 QUEST 45185
class go_a_mysterious_note : public GameObjectScript
{
public:
    go_a_mysterious_note() : GameObjectScript("go_a_mysterious_note") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/) override
    {
        if (player->HasQuest(45185))
            player->CastSpell(player, 231604, true);
        return false;
    }
};

struct npc_credit_portal_taken_110409 : public ScriptedAI
{
    npc_credit_portal_taken_110409(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld())
            return;
        if (!me->IsWithinDist(who, 15.0f, false))
            return;
        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
        player->KilledMonsterCredit(me->GetEntry());
        player->KilledMonsterCredit(97481);
    }
};

struct npc_nat_pagle_102639 : public ScriptedAI
{
    npc_nat_pagle_102639(Creature* creature) : ScriptedAI(creature) { }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        CloseGossipMenuFor(player);
        player->KilledMonsterCredit(102639);
        if (player->HasQuest(QUEST_FISH_FRENZY))
            player->TeleportTo(1553, Position(2570.71f, 8273.89f, 1.93f, 2.79253f));
    }
};

class CastEventTP : public BasicEvent
{
public:
    CastEventTP(Unit* caster, uint32 spellId, bool trigger) :
        _caster(caster), _spellId(spellId), _trigger(trigger) { }

    bool Execute(uint64 /*time*/, uint32 /*diff*/)
    {
        if (_caster)
            _caster->CastSpell(_caster, _spellId, _trigger);
        return true;
    }

private:
    Unit* _caster;
    uint32 _spellId;
    bool _trigger;
};

// 108868 7.x.x
struct npc_hunter_talua : public ScriptedAI
{
    npc_hunter_talua(Creature* creature) : ScriptedAI(creature) {  }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        CloseGossipMenuFor(player);
        if (player->getLevel() < 98 || player->getClass() != CLASS_HUNTER)
            return;

        if (Pet* pet = player->GetPet())
            player->RemovePet(nullptr, PET_SAVE_DISMISS, false);

        player->CastSpell(player, 216213, true);
        player->m_Events.AddEvent(new CastEventTP(player, 216216, true), player->m_Events.CalculateTime(10000));

    }
};

//108853
struct npc_great_eagle : public ScriptedAI
{
    npc_great_eagle(Creature* creature) : ScriptedAI(creature) { }

    uint8 curID;
    void Reset()
    {
    }

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        me->GetMotionMaster()->MoveDistract(1000);
        me->GetMotionMaster()->MovePoint(1, -854.9718f, 4185.322f, 754.1122f);
    }

    void MovementInform(uint32 type, uint32 id)
    {
        if (type != POINT_MOTION_TYPE)
            return;

        switch (id)
        {
        case 1:
            me->DespawnOrUnsummon(0);
            break;
        }
    }
};

Position const npc_archmage_khadgar_90417_q41804_pos[8] =
{
 { -845.3344f, 4665.4f, 767.28f },
 { -836.413f, 4666.54f, 767.689f },
 { -832.677f, 4662.761f, 767.738f },//t
 { -833.2926f, 4660.763f, 767.687f },//check t delay t
 { -829.08f, 4655.322f, 767.797f },//check t delay t delay t summcreature or go kill
 { -837.088f, 4666.4f, 767.667f },
 { -845.3344f, 4665.4f, 767.28f },
 { -848.462f, 4638.85f, 749.547f },
};

struct npc_archmage_khadgar_90417 : public ScriptedAI
{
    npc_archmage_khadgar_90417(Creature* creature) : ScriptedAI(creature), sceneHelper(creature->GetGUID(), creature->GetMap()) {  }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == 39986)
        {
            if (IsLock)
                IsLock = false;
            Talk(1);//Any disturbance should catalyze the sequence. Just, uh, give it a poke or something.
            if (Creature* npc = me->FindNearestCreature(98266, 50.0f, true))
                npc->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
        }
        if (quest->GetQuestId() == 39987)
        {
            player->SummonGameObject(244874, Position(-851.257f, 4631.811f, 749.6389f, 1.389102f), QuaternionData(0.0f, 0.0f, 0.6400404f, 0.7683412f), 60000, true);
            Talk(2);
        }
        if (quest->GetQuestId() == 41804)
        {
            me->Say(13874, player);
            sceneHelper.Clear();
            sceneHelper.SetDefaultActorGuid(me->GetGUID());
          //  sceneHelper.SetDefaultPlayerGuid(player->GetGUID());

            sceneHelper.AddSceneActionMovePos(npc_archmage_khadgar_90417_q41804_pos[0], 100);
            sceneHelper.AddSceneActionMovePos(npc_archmage_khadgar_90417_q41804_pos[1], 2500);
            sceneHelper.AddSceneActionMovePos(npc_archmage_khadgar_90417_q41804_pos[2], 2500);
            //sceneHelper.AddSceneActionSay(130254, 500);//Hold on just a moment.I frea I'm a bit of a packrat.
            sceneHelper.AddSceneActionMovePos(npc_archmage_khadgar_90417_q41804_pos[3], 2500);
            //sceneHelper.AddSceneActionSay(86873, 500);//Now let's see...apexis crystals? No,no,those won't do at all. 
           // sceneHelper.AddSceneActionSay(86873, 500);//Hmm,I must've put it over here.
            sceneHelper.AddSceneActionMovePos(npc_archmage_khadgar_90417_q41804_pos[4], 2500);
            //sceneHelper.AddSceneActionSay(86873, 500);//Arcane powder...soul shards...that's definitely not it...
            //sceneHelper.AddSceneActionSay(86873, 500);//A-ha!Here we are...a crystallized soul. That ought to do the trick!
            //sceneHelper.AddSceneActionSay(86873, 500);//Would you mind grabbing it?These crystals tend to have an adverse effect on non-demonic beings.
            //sceneHelper.AddSceneActionKillCreditMonster(90417, 1, 500);
            //sceneHelper.AddSceneSummonGameObject(248521, Position(-830.549f, 4654.773f, 767.65f, 4.5352f), 500);
            sceneHelper.AddSceneActionMovePos(npc_archmage_khadgar_90417_q41804_pos[5], 2500);
            sceneHelper.AddSceneActionMovePos(npc_archmage_khadgar_90417_q41804_pos[6], 2500);
            sceneHelper.AddSceneActionMovePos(npc_archmage_khadgar_90417_q41804_pos[7], 2500);
            sceneHelper.Activate();
        }
        if (quest->GetQuestId() == 41806)
            me->Say(100062, player);

    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                if (!IsLock && (player->HasQuest(39985) || player->HasQuest(44555)))
                {
                    IsLock = true;
                    Talk(0);// Nobody touch it! Not until our guest arrives.
                    SetUnlock(60000);
                }
                if (!IsLock && player->HasQuest(41803))
                {
                    IsLock = true;
                    me->Say(107409, player);
                    SetUnlock(60000);
                }
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        sceneHelper.UpdateSceneHelper(diff);
    }
private:
    SceneHelper sceneHelper;
};

struct npc_arcane_anomaly_98266 : public ScriptedAI
{
    npc_arcane_anomaly_98266(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
    }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {
            if (player->GetQuestStatus(39986) == QUEST_STATUS_INCOMPLETE)
            {
                me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
                me->UpdateEntry(98267);
                me->RemoveAurasDueToSpell(193606);
                DoCastSelf(164233, true);
                me->Say(100088);//Ith'el kanesh!

                me->GetScheduler().Schedule(Milliseconds(3000), [this](TaskContext context)
                {
                    me->Say(100089);//I am Thalyssra of the shal'dorei... the Nightborne. First Arcanist in the court of Suramar.
                });
                me->GetScheduler().Schedule(Milliseconds(10000), [this](TaskContext context)
                {
                    me->Say(100091);//My people have made a dire pact. One that spells doom for this world.
                });
                me->GetScheduler().Schedule(Milliseconds(16000), [this](TaskContext context)
                {
                    me->Say(100094);//Time is short. If you have found this message, you are capable of finding me as well.
                });
                me->GetScheduler().Schedule(Milliseconds(21000), [this, player](TaskContext context)
                {
                    me->Say(100096);//Make haste for Suramar. You may be our last hope.
                });
                me->GetScheduler().Schedule(Milliseconds(26000), [this, player](TaskContext context)
                {
                    player->KilledMonsterCredit(98266);
                    me->Say(100256);//Ith\'nala kanesh!
                    DoCastSelf(164233, true);
                    me->UpdateEntry(98266);
                    me->AddAura(193606);
                });
            }
        }
    }
};

struct npc_timofey_oshenko_92194 : public ScriptedAI
{
    npc_timofey_oshenko_92194(Creature* creature) : ScriptedAI(creature) { }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == 38506)
        {
            me->SetWalk(true);
            me->RemoveNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);
            Talk(0);
            player->AddItem(123978, 1);
            me->GetMotionMaster()->MovePoint(1, Position(-723.837f, 4560.88f, 729.931f, 1.07241f), true);
        }
    }

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        switch (id)
        {
        case 1:
            me->HandleEmoteCommand(606);
            me->GetScheduler().Schedule(5s, [this](TaskContext /*context*/)
            {
                Talk(1);
                me->GetMotionMaster()->MovePoint(2, Position(-726.594f, 4561.29f, 729.72f, 4.70967f), true);
            });
            break;
        case 2:
            me->SetOrientation(4.682536f);
            me->AddNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);
            me->GetScheduler().Schedule(1s, [this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MoveTargetedHome();
            });
            break;
        default:
            break;
        }
    }
};

struct npc_archmage_khadgar_112130 : public ScriptedAI
{
    npc_archmage_khadgar_112130(Creature* creature) : ScriptedAI(creature) { }

    void sQuestReward(Player* player, Quest const* quest, uint32 /*opt*/)  override
    {
        if (quest->GetQuestId() == 44009 || quest->GetQuestId() == 44257)
            player->CastSpell(player, 228548, true);
    }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == 44004)
        {
            //220513 target pos -4242.29, -11480.4, 9.495 1624
            player->SummonGameObject(253930, Position(-805.065f, 4516.756f, 603.943f, 3.9149f), QuaternionData(), 0, true);
        }
    }
};

struct npc_wyrmtongue_hoarder_89407 : public ScriptedAI
{
    npc_wyrmtongue_hoarder_89407(Creature* creature) : ScriptedAI(creature) {  }

    void OnSpellCasted(SpellInfo const* spellInfo) override
    {
        //178997/escape-portal
        if (spellInfo->Id == 178997)
        {
            //122291 reward item
            std::list<Player*> _list = me->SelectNearestPlayers(25.f, true);
            if (!_list.empty())
                for (Player* player : _list)
                    player->AddItem(122291, 1);

            //me->DespawnOrUnsummon(6000);
        }
    }

    void EnterCombat(Unit* /*attacker*/) override
    {
        events.Reset();
        events.ScheduleEvent(1, 5s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (me->getThreatManager().isThreatListEmpty())
        {
            if (roll_chance_i(25))
                me->GetMotionMaster()->MoveRandom(10.f);
            return;
        }
        if (!UpdateVictim())
            return;
        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;
        events.Update(diff);
        switch (events.ExecuteEvent())
        {
        case 1:
            if (roll_chance_i(25))
            {
                me->GetMotionMaster()->MoveFleeing(me->GetVictim(), 5000);
            }
            else
            {
                me->StopMoving();
                DoCast(178997);
            }
            events.Repeat(5s);
            break;
        }
    }
};

void AddSC_dalaran_legion()
{
    RegisterSpellScript(spell_dalaran_teleportation);
    new npc_dalaran_karazhan_khadgar();
    new scene_dalaran_kharazan_teleportion();
    new zone_legion_dalaran_underbelly();
    new zone_legion_dalaran();
    new PhaseOnDaralanArea();
    RegisterCreatureAI(npc_emissary_auldbridge_111109);
    RegisterCreatureAI(npc_guard_dalaran_legion);
    new go_a_mysterious_note();
    RegisterCreatureAI(npc_credit_portal_taken_110409);
    RegisterCreatureAI(npc_nat_pagle_102639);
    RegisterCreatureAI(npc_hunter_talua);
    RegisterCreatureAI(npc_great_eagle);
    RegisterCreatureAI(npc_archmage_khadgar_90417);
    RegisterCreatureAI(npc_arcane_anomaly_98266);
    RegisterCreatureAI(npc_timofey_oshenko_92194);
    RegisterCreatureAI(npc_archmage_khadgar_112130);
    RegisterCreatureAI(npc_wyrmtongue_hoarder_89407);
}
