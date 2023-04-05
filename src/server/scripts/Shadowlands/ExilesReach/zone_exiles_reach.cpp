/*
 * Copyright 2023 AzgathCore
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

#include "ScriptMgr.h"
#include "Player.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTriggerAI.h"
#include "AreaTrigger.h"
#include "InstanceScript.h"
#include "CombatAI.h"
#include "PhasingHandler.h"
#include "TemporarySummon.h"
#include "Log.h"
#include "Chat.h"
#include "ZoneScript.h"
#include "ScriptedGossip.h"

enum ExileReach
{
    QUEST_WARMING_UP = 56775,
    QUEST_STAND_YOUR_GROUND = 58209,
    QUEST_BRACE_FOR_IMPACT = 58208,
    QUEST_MURLOC_MANIA = 55122,
    QUEST_EMERGENCY_FIRST_AID = 54951,
    QUEST_FINDING_THE_LOST_EXPEDITION = 54952,
    QUEST_COOKING_MEAT = 55174,
    QUEST_ENHANCED_COMBAT_TACTICS = 59254,
    QUEST_NORTHBOUND = 55173,
    QUEST_DOWN_WITH_THE_QUILBOAR = 55186,
    QUEST_FORBIDDEN_QUILBOAR_NECROMANCY = 55184,
    QUEST_THE_SCOUT_O_MATIC_5000 = 55193,
    QUEST_RE_SIZING_THE_SITUATION = 56034,
    QUEST_RIDE_OF_THE_SCIENTIFICALLY_ENHANCED_BOAR = 55879,
    QUEST_THE_HARPY_PROBLEM = 55196,
    QUEST_THE_RESCUE_OF_MEREDY_HUNTSWELL = 55763,
    QUEST_HARPY_CULLING = 55764,
    QUEST_PURGE_THE_TOTEMS = 55881,
    QUEST_MESSAGE_TO_BASE = 55882,
    QUEST_WESTWARD_BOUND = 55965,
    QUEST_WHO_LURKS_IN_THE_PIT = 55639,
    QUEST_TO_DARKMAUL_CITADEL = 56344,
    QUEST_RIGHT_BENEATH_THEIR_EYES = 55981,
    QUEST_LIKE_OGRES_TO_THE_SLAUGHTER = 55988,
    QUEST_CATAPULT_DESTRUCTION = 55989,
    QUEST_CONTROLLING_THEIR_STONES = 55990,
    QUEST_DUNGEON_DARKMAUL_CITADEL = 55992,
    QUEST_AN_END_TO_BEGINNINGS = 55991,

    SCENE_ALI_HORDE_CRASHED_ON_ISLAND = 2708,
    SCENE_HENRY_REUNION = 2717,
    SCENE_GRIMAXE_REUNION = 2905,
    SCENE_GORGROTHS_RITUAL = 2820,
    SCENE_SKELETON_ARMY_DARKMAUL_PLAINS = 2712,
    SCENE_FLY_AWAY = 2908,

    AREA_NORTH_SEA = 10639,
};

class exiles_reach : public PlayerScript
{
public:
    exiles_reach() : PlayerScript("exiles_reach") { }

    void OnLogin(Player* /*player*/, bool /*firstLogin*/) override
    {
       /* if (player->GetMapId() == MAP_NPE)
            player->AddPvpFlag(UNIT_BYTE2_FLAG_SANCTUARY);*///tmp
    }

    void OnUpdateArea(Player* /*player*/, uint32 /*newArea*/, uint32 /*oldArea*/)
    {
       /* if (player->GetMapId() == MAP_NPE)
            player->AddPvpFlag(UNIT_BYTE2_FLAG_SANCTUARY);*///tmp
    }
};

class zone_exiles_reach : public ZoneScript
{
public:

    void OnPlayerExit(Player* player)
    {
        player->RemovePvpFlag(UNIT_BYTE2_FLAG_SANCTUARY);
    }
};

struct npc_combat_dummy : public ScriptedAI
{
    npc_combat_dummy(Creature* creature) : ScriptedAI(creature)
    {
        SetCombatMovement(false);
        me->SetReactState(REACT_PASSIVE);
    }

    void JustDied(Unit* killer) override
    {
        if (Player* player = killer->ToPlayer())
            player->KilledMonsterCredit(174954);
    }
};

struct npc_private_cole : public ScriptedAI
{
    npc_private_cole(Creature* creature) : ScriptedAI(creature)
    {
        SetCombatMovement(false);
    }

    void Reset() override
    {
        ScriptedAI::Reset();
    }

    void JustDied(Unit* /*killer*/) override
    {
        //if (Player* player = killer->ToPlayer())//tmp
          /*  if (player->HasQuest(QUEST_STAND_YOUR_GROUND))
            {
                player->KilledMonsterCredit(155607);
                me->DespawnOrUnsummon(10ms);
                (me->GetEntry(), Position(-52.6575f, 0.689299f, 43.4511f, 4.12704f), TEMPSUMMON_MANUAL_DESPAWN, 0U, 0U);
            }*///tmp
    }
};

struct npc_lindie_springstock_149899 : public ScriptedAI
{
    npc_lindie_springstock_149899(Creature* c) : ScriptedAI(c) { }

    void QuestAccept(Player* player, Quest const* quest)
    {
        if (quest->GetQuestId() == QUEST_THE_SCOUT_O_MATIC_5000)
            player->SummonCreature(156518, player->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
    }
};

struct npc_scout_o_matic_5000 : public ScriptedAI
{
    npc_scout_o_matic_5000(Creature* creature) : ScriptedAI(creature)
    {
        me->CanFly();
    }

private:
    Vehicle* vehicle;

    void IsSummonedBy(WorldObject* /*summoner*/)
    {
        vehicle = me->GetVehicleKit();
        //Player* player = summoner->ToPlayer();    //NO USE
        me->GetMotionMaster()->MovePoint(1, 206.0f, -2289.0f, 117.0f, true);

        //AddTimedDelayedOperation(25000, [this, player]() -> void
        //{
        //    player->KilledMonsterCredit(156518);
        //});//tmp

        /*AddTimedDelayedOperation(50000, [this]() -> void
        {
            me->GetMotionMaster()->MovePoint(2, 108.609f, -2413.905f, 90.530f, true);
        });*///tmp

       /* AddTimedDelayedOperation(75000, [this, player]() -> void
        {
            player->ExitVehicle();
            me->DespawnOrUnsummon(1s);
        });*///tmp
    }
};

class item_resizer_v901 : public ItemScript
{
public:
    item_resizer_v901() : ItemScript("item_resizer_v901") { }

    bool OnUse(Player* player, Item* /*item*/, SpellCastTargets const& /*targets*/, ObjectGuid /*castId*/) override
    {
        if (Unit* target = player->GetSelectedUnit())
            if (target->GetEntry() == 156716)
            {
                player->CastSpell(target, 305716, false);
                player->KilledMonsterCredit(156722);
            }
        return true;
    }
};

struct npc_giant_boar : public ScriptedAI
{
    npc_giant_boar(Creature* creature) : ScriptedAI(creature)
    {
    }

    void Reset() override
    {
//        me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);//tmp
    }

    void IsSummonedBy(WorldObject* summoner)
    {
        me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
        me->SetWalk(false);

        if (Player* player = summoner->ToPlayer())
        {
            player->EnterVehicle(me);
            player->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            player->KilledMonsterCredit(156595);
        }
    }
};

struct npc_henry_garrick_156799 : public ScriptedAI
{
    npc_henry_garrick_156799(Creature* creature) : ScriptedAI(creature) { }

    void QuestReward(Player* player, Quest const* quest, LootItemType /*type*/, uint32 /*opt*/)
    {
        if (quest->GetQuestId() == QUEST_RIDE_OF_THE_SCIENTIFICALLY_ENHANCED_BOAR)
        {
            player->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
        }
    }
};

struct npc_meredy_huntswell_156943 : public ScriptedAI
{
    npc_meredy_huntswell_156943(Creature* creature) : ScriptedAI(creature) { }
};

struct npc_captain_garrick_156651 : public ScriptedAI
{
    npc_captain_garrick_156651(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
    }

    void QuestAccept(Player* /*player*/, Quest const* quest)
    {
        if (quest->GetQuestId() == QUEST_ENHANCED_COMBAT_TACTICS)
        {
        }
    }

    void JustDied(Unit* killer)
    {
        if (Player* player = killer->ToPlayer())
//            if (player->HasQuest(QUEST_ENHANCED_COMBAT_TACTICS))//tmp
            {
                player->KilledMonsterCredit(156651);
                (me->GetEntry(), me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0U, 0U);
                me->DespawnOrUnsummon(10ms);
            }
    }
};

struct npc_captain_garrick_156280 : public ScriptedAI
{
    npc_captain_garrick_156280(Creature* creature) : ScriptedAI(creature) { }

    void QuestAccept(Player* player, Quest const* quest)
    {
        if (quest->GetQuestId() == QUEST_RIDE_OF_THE_SCIENTIFICALLY_ENHANCED_BOAR)
            (156595, player->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 60000, 0U, player->GetGUID());
    }

    void QuestReward(Player* player, Quest const* quest, LootItemType /*type*/, uint32 /*opt*/)
    {
        if (quest->GetQuestId() == QUEST_BRACE_FOR_IMPACT)
        {
            player->TeleportTo(2175, -462.722f, -2620.544f, 0.472f, 0.760f);
        }
    }
};

struct npc_ralia_dreamchacer_156929 : public ScriptedAI
{
    npc_ralia_dreamchacer_156929(Creature* creature) : ScriptedAI(creature)
    {
        /*Vehicle* vehicle = me->GetVehicleKit();*/
    }

    void Reset() override
    {
       // me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);//tmp
    }

    void IsSummonedBy(WorldObject* summoner)
    {
        me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
        me->SetWalk(false);

        if (Player* player = summoner->ToPlayer())
        {
            player->EnterVehicle(me);
//            player->ForceCompleteQuest(QUEST_WHO_LURKS_IN_THE_PIT);//tmp
        }
    }
};

struct npc_alliance_gryphon_154155 : public ScriptedAI
{
    npc_alliance_gryphon_154155(Creature* creature) : ScriptedAI(creature)
    {
        
    }

    void Reset() override
    {
//        me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);//tmp
    }

    void OnSpellClick(Unit*, bool)
    {
    }
};

struct npc_coulston_nereus : public ScriptedAI
{
    npc_coulston_nereus(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (player->GetQuestStatus(58917) == QUEST_STATUS_INCOMPLETE)
            {
                if (player->IsInDist(me, 30.0f))
                {
                    player->KilledMonsterCredit(162972, ObjectGuid::Empty);
                }
            }
        }
    }
};

struct npc_gutgruck_the_tough : public ScriptedAI
{
    npc_gutgruck_the_tough(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->Yell("Me gonna get more sacrifices for ritual", LANG_UNIVERSAL);
        me->GetMotionMaster()->MoveRandom(20.0f);
    }

    void JustDied(Unit* killer) override
    {
        if (Player* player = killer->ToPlayer())
        {
            player->KilledMonsterCredit(175015);
        }

        me->Say("You... Cheat...", LANG_UNIVERSAL);
        me->DespawnOrUnsummon(1000ms);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        me->Say("Me strong! You can hurt!", LANG_UNIVERSAL);
    }
};

struct at_for_gutgruck_the_tough : public AreaTriggerAI
{
    at_for_gutgruck_the_tough(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();

        if (!player)
            return;

        if (player->GetQuestStatus(58933) == QUEST_STATUS_INCOMPLETE)
            at->SummonCreature(163031, Position(282.236420f, -2148.987793f, 103.455276f, 3.317860f), TEMPSUMMON_MANUAL_DESPAWN);
    }
};

class phasehandler_exiles_reach : public PlayerScript
{
public:
    phasehandler_exiles_reach() : PlayerScript("phasehandler_exiles_reach") { }


    uint32 PLAYER_CHAPTER = 1;

    uint32 PHASE_UPDATE_DELAY = 1000;
    uint32 PHASE_UPDATE_DELAY_DIFF = PHASE_UPDATE_DELAY;

    uint32 PHASE_GENERIC = 12940;
    uint32 PHASE_GENERIC_Z = 16752;
    uint32 PHASE_CHAPTER1 = 13157;
    uint32 PHASE_CHAPTER2 = 13317;
    uint32 PHASE_CHAPTER3 = 13443;
    uint32 PHASE_CHAPTER4 = 13503;
    uint32 PHASE_CHAPTER5 = 13566;
    uint32 PHASE_CHAPTER6 = 13619;
    uint32 PHASE_CHAPTER7 = 13757;
    uint32 PHASE_CHAPTER8 = 13758;
    uint32 PHASE_CHAPTER9 = 13762;
    uint32 PHASE_CHAPTER10 = 13776;
    uint32 PHASE_CHAPTER11 = 13779;
    uint32 PHASE_CHAPTER12 = 13780;
    uint32 PHASE_CHAPTER13 = 13783;
    uint32 PHASE_CHAPTER14 = 13784;
    uint32 PHASE_CHAPTER15 = 13845;
    uint32 PHASE_CHAPTER16 = 13878;
    uint32 PHASE_CHAPTER17 = 14677;
    uint32 PHASE_CHAPTER18 = 15274;
    uint32 PHASE_CHAPTER19 = 15279;
    uint32 PHASE_CHAPTER20 = 15356;


    void OnUpdate(Player* /*player*/, uint32 /*diff*/)
    {
        /*if (PHASE_UPDATE_DELAY_DIFF <= diff)
        {
            if ((player->GetMapId() == MAP_NPE) && (player->GetAreaId() != AREA_NORTH_SEA))
            {
                if ((player->GetQuestStatus(QUEST_DUNGEON_DARKMAUL_CITADEL) == QUEST_STATUS_COMPLETE) || (player->GetQuestStatus(QUEST_DUNGEON_DARKMAUL_CITADEL) == QUEST_STATUS_REWARDED))
                    PLAYER_CHAPTER = 18;
                else  if ((player->GetQuestStatus(QUEST_CONTROLLING_THEIR_STONES) == QUEST_STATUS_COMPLETE) || (player->GetQuestStatus(QUEST_CONTROLLING_THEIR_STONES) == QUEST_STATUS_REWARDED))
                    PLAYER_CHAPTER = 17;
                else  if (player->HasQuest(QUEST_CONTROLLING_THEIR_STONES))
                    PLAYER_CHAPTER = 16;
                else  if ((player->HasQuest(QUEST_TO_DARKMAUL_CITADEL)) || (player->GetQuestStatus(QUEST_TO_DARKMAUL_CITADEL) == QUEST_STATUS_REWARDED))
                    PLAYER_CHAPTER = 15;
                else if (player->GetQuestStatus(QUEST_WHO_LURKS_IN_THE_PIT) == QUEST_STATUS_REWARDED)
                    PLAYER_CHAPTER = 14;
                else if (player->HasQuest(QUEST_WHO_LURKS_IN_THE_PIT))
                    PLAYER_CHAPTER = 13;
                else if ((player->HasQuest(QUEST_WESTWARD_BOUND)) || (player->GetQuestStatus(QUEST_WESTWARD_BOUND) == QUEST_STATUS_REWARDED))
                    PLAYER_CHAPTER = 12;
                else if ((player->HasQuest(QUEST_MESSAGE_TO_BASE)) || (player->GetQuestStatus(QUEST_MESSAGE_TO_BASE) == QUEST_STATUS_REWARDED))
                    PLAYER_CHAPTER = 11;
                else if ((player->GetQuestStatus(QUEST_THE_RESCUE_OF_MEREDY_HUNTSWELL) == QUEST_STATUS_COMPLETE) || (player->GetQuestStatus(QUEST_THE_RESCUE_OF_MEREDY_HUNTSWELL) == QUEST_STATUS_REWARDED))
                    PLAYER_CHAPTER = 10;
                else if ((player->HasQuest(QUEST_THE_HARPY_PROBLEM)) || (player->GetQuestStatus(QUEST_THE_HARPY_PROBLEM) == QUEST_STATUS_REWARDED))
                    PLAYER_CHAPTER = 9;
                else if (player->GetQuestStatus(QUEST_RIDE_OF_THE_SCIENTIFICALLY_ENHANCED_BOAR) == QUEST_STATUS_REWARDED)
                    PLAYER_CHAPTER = 8;
                else if (player->GetQuestStatus(QUEST_RIDE_OF_THE_SCIENTIFICALLY_ENHANCED_BOAR) == QUEST_STATUS_COMPLETE)
                    PLAYER_CHAPTER = 7;
                else if ((player->GetQuestStatus(QUEST_DOWN_WITH_THE_QUILBOAR) == QUEST_STATUS_COMPLETE) || (player->GetQuestStatus(QUEST_DOWN_WITH_THE_QUILBOAR) == QUEST_STATUS_REWARDED))
                    PLAYER_CHAPTER = 6;
                else if (player->GetQuestStatus(QUEST_ENHANCED_COMBAT_TACTICS) == QUEST_STATUS_REWARDED)
                    PLAYER_CHAPTER = 5;
                else if (player->GetQuestStatus(QUEST_COOKING_MEAT) == QUEST_STATUS_REWARDED)
                    PLAYER_CHAPTER = 4;
                else if (player->GetQuestStatus(QUEST_FINDING_THE_LOST_EXPEDITION) == QUEST_STATUS_REWARDED)
                    PLAYER_CHAPTER = 3;
                else if (player->GetQuestStatus(QUEST_EMERGENCY_FIRST_AID) == QUEST_STATUS_REWARDED)
                    PLAYER_CHAPTER = 2;
                else PLAYER_CHAPTER = 1;


                if (PLAYER_CHAPTER == 1)
                {
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER2)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER2, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER3)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER3, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER4)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER4, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER5)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER5, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER6)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER6, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER7)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER7, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER8)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER8, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER9)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER9, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER10)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER10, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER11)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER11, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER12)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER12, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER13)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER13, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER14)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER14, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER15)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER15, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER16)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER16, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER17)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER17, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER18)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER18, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_CHAPTER1))PhasingHandler::AddPhase(player, PHASE_CHAPTER1, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC)) PhasingHandler::AddPhase(player, PHASE_GENERIC, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC_Z)) PhasingHandler::AddPhase(player, PHASE_GENERIC_Z, true);
                }

                if (PLAYER_CHAPTER == 2)
                {
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER1)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER1, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER3)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER3, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER4)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER4, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER5)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER5, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER6)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER6, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER7)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER7, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER8)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER8, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER9)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER9, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER10)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER10, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER11)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER11, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER12)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER12, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER13)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER13, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER14)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER14, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER15)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER15, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER16)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER16, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER17)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER17, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER18)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER18, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_CHAPTER2))PhasingHandler::AddPhase(player, PHASE_CHAPTER2, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC)) PhasingHandler::AddPhase(player, PHASE_GENERIC, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC_Z)) PhasingHandler::AddPhase(player, PHASE_GENERIC_Z, true);
                }

                if (PLAYER_CHAPTER == 3)
                {
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER1)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER1, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER2)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER2, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER4)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER4, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER5)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER5, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER6)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER6, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER7)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER7, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER8)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER8, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER9)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER9, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER10)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER10, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER11)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER11, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER12)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER12, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER13)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER13, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER14)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER14, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER15)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER15, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER16)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER16, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER17)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER17, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER18)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER18, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_CHAPTER3))PhasingHandler::AddPhase(player, PHASE_CHAPTER3, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC)) PhasingHandler::AddPhase(player, PHASE_GENERIC, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC_Z)) PhasingHandler::AddPhase(player, PHASE_GENERIC_Z, true);
                }

                if (PLAYER_CHAPTER == 4)
                {
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER1)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER1, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER2)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER2, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER3)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER3, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER5)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER5, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER6)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER6, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER7)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER7, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER8)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER8, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER9)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER9, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER10)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER10, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER11)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER11, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER12)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER12, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER13)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER13, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER14)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER14, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER15)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER15, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER16)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER16, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER17)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER17, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER18)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER18, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_CHAPTER4))PhasingHandler::AddPhase(player, PHASE_CHAPTER4, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC)) PhasingHandler::AddPhase(player, PHASE_GENERIC, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC_Z)) PhasingHandler::AddPhase(player, PHASE_GENERIC_Z, true);
                }

                if (PLAYER_CHAPTER == 5)
                {
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER1)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER1, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER2)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER2, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER3)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER3, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER4)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER4, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER6)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER6, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER7)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER7, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER8)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER8, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER9)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER9, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER10)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER10, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER11)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER11, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER12)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER12, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER13)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER13, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER14)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER14, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER15)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER15, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER16)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER16, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER17)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER17, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER18)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER18, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_CHAPTER5))PhasingHandler::AddPhase(player, PHASE_CHAPTER5, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC)) PhasingHandler::AddPhase(player, PHASE_GENERIC, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC_Z)) PhasingHandler::AddPhase(player, PHASE_GENERIC_Z, true);
                }

                if (PLAYER_CHAPTER == 6)
                {
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER1)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER1, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER2)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER2, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER3)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER3, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER4)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER4, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER5)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER5, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER7)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER7, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER8)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER8, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER9)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER9, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER10)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER10, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER11)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER11, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER12)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER12, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER13)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER13, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER14)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER14, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER15)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER15, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER16)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER16, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER17)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER17, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER18)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER18, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_CHAPTER6))PhasingHandler::AddPhase(player, PHASE_CHAPTER6, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC)) PhasingHandler::AddPhase(player, PHASE_GENERIC, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC_Z)) PhasingHandler::AddPhase(player, PHASE_GENERIC_Z, true);
                }

                if (PLAYER_CHAPTER == 7)
                {
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER1)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER1, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER2)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER2, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER3)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER3, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER4)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER4, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER5)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER5, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER6)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER6, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER8)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER8, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER9)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER9, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER10)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER10, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER11)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER11, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER12)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER12, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER13)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER13, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER14)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER14, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER15)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER15, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER16)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER16, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER17)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER17, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER18)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER18, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_GENERIC_Z))PhasingHandler::RemovePhase(player, PHASE_GENERIC_Z, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_CHAPTER7))PhasingHandler::AddPhase(player, PHASE_CHAPTER7, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC)) PhasingHandler::AddPhase(player, PHASE_GENERIC, true);
                }

                if (PLAYER_CHAPTER == 8)
                {
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER1)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER1, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER2)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER2, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER3)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER3, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER4)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER4, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER5)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER5, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER6)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER6, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER7)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER7, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER9)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER9, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER10)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER10, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER11)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER11, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER12)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER12, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER13)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER13, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER14)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER14, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER15)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER15, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER16)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER16, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER17)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER17, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER18)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER18, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_GENERIC_Z))PhasingHandler::RemovePhase(player, PHASE_GENERIC_Z, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_CHAPTER8))PhasingHandler::AddPhase(player, PHASE_CHAPTER8, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC)) PhasingHandler::AddPhase(player, PHASE_GENERIC, true);
                }

                if (PLAYER_CHAPTER == 9)
                {
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER1)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER1, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER2)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER2, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER3)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER3, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER4)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER4, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER5)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER5, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER6)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER6, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER7)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER7, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER8)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER8, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER10)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER10, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER11)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER11, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER12)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER12, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER13)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER13, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER14)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER14, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER15)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER15, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER16)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER16, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER17)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER17, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER18)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER18, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_GENERIC_Z))PhasingHandler::RemovePhase(player, PHASE_GENERIC_Z, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_CHAPTER9))PhasingHandler::AddPhase(player, PHASE_CHAPTER9, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC)) PhasingHandler::AddPhase(player, PHASE_GENERIC, true);
                }

                if (PLAYER_CHAPTER == 10)
                {
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER1)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER1, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER2)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER2, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER3)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER3, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER4)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER4, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER5)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER5, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER6)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER6, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER7)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER7, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER8)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER8, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER9)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER9, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER11)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER11, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER12)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER12, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER13)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER13, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER14)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER14, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER15)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER15, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER16)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER16, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER17)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER17, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER18)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER18, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_GENERIC_Z))PhasingHandler::RemovePhase(player, PHASE_GENERIC_Z, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_CHAPTER10))PhasingHandler::AddPhase(player, PHASE_CHAPTER10, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC)) PhasingHandler::AddPhase(player, PHASE_GENERIC, true);
                }

                if (PLAYER_CHAPTER == 11)
                {
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER1)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER1, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER2)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER2, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER3)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER3, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER4)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER4, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER5)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER5, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER6)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER6, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER7)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER7, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER8)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER8, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER9)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER9, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER10)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER10, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER12)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER12, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER13)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER13, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER14)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER14, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER15)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER15, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER16)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER16, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER17)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER17, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER18)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER18, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_GENERIC_Z))PhasingHandler::RemovePhase(player, PHASE_GENERIC_Z, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_CHAPTER11))PhasingHandler::AddPhase(player, PHASE_CHAPTER11, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC)) PhasingHandler::AddPhase(player, PHASE_GENERIC, true);
                }

                if (PLAYER_CHAPTER == 12)
                {
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER1)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER1, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER2)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER2, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER3)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER3, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER4)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER4, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER5)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER5, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER6)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER6, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER7)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER7, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER8)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER8, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER9)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER9, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER10)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER10, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER11)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER11, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER13)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER13, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER14)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER14, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER15)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER15, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER16)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER16, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER17)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER17, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER18)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER18, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_GENERIC_Z))PhasingHandler::RemovePhase(player, PHASE_GENERIC_Z, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_CHAPTER12))PhasingHandler::AddPhase(player, PHASE_CHAPTER12, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC)) PhasingHandler::AddPhase(player, PHASE_GENERIC, true);
                }

                if (PLAYER_CHAPTER == 13)
                {
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER1)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER1, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER2)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER2, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER3)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER3, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER4)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER4, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER5)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER5, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER6)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER6, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER7)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER7, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER8)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER8, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER9)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER9, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER10)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER10, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER11)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER11, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER12)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER12, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER14)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER14, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER15)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER15, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER16)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER16, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER17)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER17, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER18)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER18, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_GENERIC_Z))PhasingHandler::RemovePhase(player, PHASE_GENERIC_Z, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_CHAPTER13))PhasingHandler::AddPhase(player, PHASE_CHAPTER13, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC)) PhasingHandler::AddPhase(player, PHASE_GENERIC, true);
                }

                if (PLAYER_CHAPTER == 14)
                {
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER1)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER1, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER2)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER2, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER3)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER3, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER4)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER4, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER5)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER5, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER6)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER6, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER7)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER7, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER8)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER8, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER9)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER9, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER10)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER10, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER11)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER11, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER12)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER12, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER13)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER13, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER15)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER15, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER16)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER16, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER17)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER17, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER18)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER18, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_GENERIC_Z))PhasingHandler::RemovePhase(player, PHASE_GENERIC_Z, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_CHAPTER14))PhasingHandler::AddPhase(player, PHASE_CHAPTER14, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC)) PhasingHandler::AddPhase(player, PHASE_GENERIC, true);
                }

                if (PLAYER_CHAPTER == 15)
                {
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER1)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER1, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER2)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER2, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER3)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER3, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER4)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER4, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER5)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER5, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER6)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER6, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER7)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER7, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER8)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER8, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER9)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER9, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER10)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER10, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER11)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER11, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER12)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER12, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER13)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER13, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER14)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER14, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER16)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER16, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER17)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER17, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER18)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER18, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_GENERIC_Z))PhasingHandler::RemovePhase(player, PHASE_GENERIC_Z, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_CHAPTER15))PhasingHandler::AddPhase(player, PHASE_CHAPTER15, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC)) PhasingHandler::AddPhase(player, PHASE_GENERIC, true);
                }

                if (PLAYER_CHAPTER == 16)
                {
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER1)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER1, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER2)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER2, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER3)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER3, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER4)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER4, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER5)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER5, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER6)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER6, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER7)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER7, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER8)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER8, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER9)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER9, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER10)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER10, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER11)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER11, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER12)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER12, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER13)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER13, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER14)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER14, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER15)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER15, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER17)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER17, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER18)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER18, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_GENERIC_Z))PhasingHandler::RemovePhase(player, PHASE_GENERIC_Z, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_CHAPTER16))PhasingHandler::AddPhase(player, PHASE_CHAPTER16, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC)) PhasingHandler::AddPhase(player, PHASE_GENERIC, true);
                }

                if (PLAYER_CHAPTER == 17)
                {
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER1)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER1, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER2)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER2, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER3)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER3, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER4)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER4, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER5)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER5, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER6)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER6, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER7)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER7, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER8)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER8, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER9)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER9, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER10)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER10, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER11)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER11, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER12)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER12, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER13)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER13, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER14)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER14, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER15)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER15, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER16)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER16, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER18)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER18, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_GENERIC_Z))PhasingHandler::RemovePhase(player, PHASE_GENERIC_Z, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_CHAPTER17))PhasingHandler::AddPhase(player, PHASE_CHAPTER17, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC)) PhasingHandler::AddPhase(player, PHASE_GENERIC, true);
                }

                if (PLAYER_CHAPTER == 18)
                {
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER1)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER1, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER2)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER2, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER3)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER3, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER4)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER4, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER5)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER5, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER6)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER6, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER7)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER7, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER8)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER8, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER9)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER9, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER10)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER10, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER11)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER11, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER12)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER12, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER13)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER13, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER14)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER14, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER15)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER15, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER16)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER16, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_CHAPTER17)) PhasingHandler::RemovePhase(player, PHASE_CHAPTER17, true);
                    if (player->GetPhaseShift().HasPhase(PHASE_GENERIC_Z))PhasingHandler::RemovePhase(player, PHASE_GENERIC_Z, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_CHAPTER18))PhasingHandler::AddPhase(player, PHASE_CHAPTER18, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC)) PhasingHandler::AddPhase(player, PHASE_GENERIC, true);
                }
            }
            PHASE_UPDATE_DELAY_DIFF = PHASE_UPDATE_DELAY;
        }
        else
            PHASE_UPDATE_DELAY_DIFF -= diff;*///tmp
    }
};

void AddSC_zone_exiles_reach()
{
    RegisterPlayerScript(exiles_reach);
    //RegisterZoneScript(zone_exiles_reach);
    RegisterCreatureAI(npc_combat_dummy);
    RegisterCreatureAI(npc_private_cole);
    RegisterCreatureAI(npc_lindie_springstock_149899);
    RegisterCreatureAI(npc_scout_o_matic_5000);
    //RegisterItemScript(item_resizer_v901);
    RegisterCreatureAI(npc_giant_boar);
    RegisterCreatureAI(npc_meredy_huntswell_156943);
    RegisterCreatureAI(npc_henry_garrick_156799);
    RegisterCreatureAI(npc_captain_garrick_156651);
    RegisterCreatureAI(npc_captain_garrick_156280);
    RegisterCreatureAI(npc_ralia_dreamchacer_156929);
    RegisterCreatureAI(npc_alliance_gryphon_154155);
    RegisterCreatureAI(npc_coulston_nereus);
    RegisterPlayerScript(phasehandler_exiles_reach);
    RegisterCreatureAI(npc_gutgruck_the_tough);
    RegisterAreaTriggerAI(at_for_gutgruck_the_tough);
}
