/*
 * Copyright 2021 ShadowCore
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
#include "Log.h"
#include "Chat.h"

/******************************************************
    NOTE TO DEVS:

    FINISH ALLIED SIDE FIRST!
    LETS ADD HORDE AFTER ALLIED IS COMPLETE.
    -Varjgard
******************************************************/


enum ExileReach
{
    QUEST_WARMING_UP                                = 56775,
    QUEST_STAND_YOUR_GROUND                         = 58209,
    QUEST_BRACE_FOR_IMPACT                          = 58208,
    QUEST_MURLOC_MANIA                              = 55122,
    QUEST_EMERGENCY_FIRST_AID                       = 54951,
    QUEST_FINDING_THE_LOST_EXPEDITION               = 54952,
    QUEST_COOKING_MEAT                              = 55174,
    QUEST_ENHANCED_COMBAT_TACTICS                   = 59254,
    QUEST_NORTHBOUND                                = 55173,
    QUEST_DOWN_WITH_THE_QUILBOAR                    = 55186,
    QUEST_FORBIDDEN_QUILBOAR_NECROMANCY             = 55184,
    QUEST_THE_SCOUT_O_MATIC_5000                    = 55193,
    QUEST_RE_SIZING_THE_SITUATION                   = 56034,
    QUEST_RIDE_OF_THE_SCIENTIFICALLY_ENHANCED_BOAR  = 55879,
    QUEST_THE_HARPY_PROBLEM                         = 55196,
    QUEST_THE_RESCUE_OF_MEREDY_HUNTSWELL            = 55763,
    QUEST_HARPY_CULLING                             = 55764,
    QUEST_PURGE_THE_TOTEMS                          = 55881,
    QUEST_MESSAGE_TO_BASE                           = 55882,
    QUEST_WESTWARD_BOUND                            = 55965,
    QUEST_WHO_LURKS_IN_THE_PIT                      = 55639,
    QUEST_TO_DARKMAUL_CITADEL                       = 56344,
    QUEST_RIGHT_BENEATH_THEIR_EYES                  = 55981,
    QUEST_LIKE_OGRES_TO_THE_SLAUGHTER               = 55988,
    QUEST_CATAPULT_DESTRUCTION                      = 55989,
    QUEST_CONTROLLING_THEIR_STONES                  = 55990,
    QUEST_DUNGEON_DARKMAUL_CITADEL                  = 55992,
    QUEST_AN_END_TO_BEGINNINGS                      = 55991,

    SCENE_ALI_HORDE_CRASHED_ON_ISLAND   = 2708,
    SCENE_HENRY_REUNION                 = 2717,
    SCENE_GRIMAXE_REUNION               = 2905,
    SCENE_GORGROTHS_RITUAL              = 2820,
    SCENE_SKELETON_ARMY_DARKMAUL_PLAINS = 2712,
    SCENE_FLY_AWAY                      = 2908,

    AREA_NORTH_SEA = 10639,
};

class exiles_reach : public PlayerScript
{
public:
    exiles_reach() : PlayerScript("exiles_reach") { }

    void OnLogin(Player* player, bool /*firstLogin*/) override
    {
        // Set zone as sanctuary
        if (player->GetMapId() == MAP_NPE)
            player->AddPvpFlag(UNIT_BYTE2_FLAG_SANCTUARY);
    }

    void OnUpdateArea(Player* player, uint32 /*newArea*/, uint32 /*oldArea*/) 
    {
        // Set zone as sanctuary
        if (player->GetMapId() == MAP_NPE)
            player->AddPvpFlag(UNIT_BYTE2_FLAG_SANCTUARY);
    }
};

class zone_exiles_reach : public ZoneScript
{
public:
    zone_exiles_reach() : ZoneScript("zone_exiles_reach") { }

    void OnPlayerExit(Player* player) override
    {
        // Remove sanctuary flag when leaving exiles reach
        player->RemovePvpFlag(UNIT_BYTE2_FLAG_SANCTUARY);
    }
};

//160737 npc_combat_dummy
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

        me->ForcedDespawn(1000, 5s);
    }
};

//160664 npc_private_cole
struct npc_private_cole : public ScriptedAI
{
    npc_private_cole(Creature* creature) : ScriptedAI(creature)
    {
        SetCombatMovement(false); // tempfix for npc falling through the boat
    }

    void Reset() override
    {
        ScriptedAI::Reset();
    }

    void QuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_STAND_YOUR_GROUND)
        {
            if(Creature* npc = me->SummonCreature(me->GetEntry(), me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0U, 0U, true))
            {
                npc->SetFaction(14);
                npc->SetReactState(REACT_AGGRESSIVE);
            }

            me->DestroyForPlayer(player);
        }
    }

    void DamageTaken(Unit* attacker, uint32& /*damage*/) override
    {
        if (Player* player = attacker->ToPlayer())
            if (me->GetHealth() < me->CountPctFromMaxHealth(20)) // the intent is not to kill but to sparr
                if (player->HasQuest(QUEST_STAND_YOUR_GROUND))
                {
                    player->KilledMonsterCredit(155607);
                    me->DespawnOrUnsummon(10ms);
                    me->SummonCreature(me->GetEntry(), Position(-52.6575f, 0.689299f, 43.4511f, 4.12704f), TEMPSUMMON_MANUAL_DESPAWN, 0U, 0U, true);
                }
    }

    void JustDied(Unit* killer) override
    {
        if (Player* player = killer->ToPlayer())
            if (player->HasQuest(QUEST_STAND_YOUR_GROUND))
            {
                player->KilledMonsterCredit(155607);
                me->DespawnOrUnsummon(10ms);
                me->SummonCreature(me->GetEntry(), Position(-52.6575f, 0.689299f, 43.4511f, 4.12704f), TEMPSUMMON_MANUAL_DESPAWN, 0U, 0U, true);
            }
    }
};

//168410 item_first_aid_kit
class item_first_aid_kit : public ItemScript
{
public:
    item_first_aid_kit() : ItemScript("item_first_aid_kit") { }

    bool OnUse(Player* player, Item* item, SpellCastTargets const& targets, ObjectGuid /*castId*/) override
    {
        std::list<Creature*> spellTargetsList;
        player->GetCreatureListWithEntryInGrid(spellTargetsList, 156609, 5.0f);
        player->GetCreatureListWithEntryInGrid(spellTargetsList, 156610, 5.0f);
        player->GetCreatureListWithEntryInGrid(spellTargetsList, 156612, 5.0f);
        for (auto& targets : spellTargetsList)
        {
            switch (targets->GetEntry())
            {
            case 156609:
            {
                player->KilledMonsterCredit(156609);
                player->KilledMonsterCredit(166796);
                break;
            }
            case 156612:
            {
                player->KilledMonsterCredit(156612);
                player->KilledMonsterCredit(166786);
                break;
            }
            case 156610:
            {
                player->KilledMonsterCredit(156610);
                player->KilledMonsterCredit(166791);
                break;
            }
            }
        }
        return true;
    }
};

//go_campfire_339769
struct go_campfire_339769 : public GameObjectAI
{
    go_campfire_339769(GameObject* go) : GameObjectAI(go) { }

    bool GossipHello(Player* player) override
    {
        if (!player->GetQuestObjectiveData(QUEST_COOKING_MEAT, 0))
        {
            if (player->HasQuest(QUEST_COOKING_MEAT))
                player->ForceCompleteQuest(QUEST_COOKING_MEAT);

            player->AddItem(174074, 1);
        }

        return true;
    }
};

//npc_lindie_springstock_149899
struct npc_lindie_springstock_149899 : public ScriptedAI
{
    npc_lindie_springstock_149899(Creature* c) : ScriptedAI(c) { }

    void QuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_THE_SCOUT_O_MATIC_5000)
            player->SummonCreature(156518, player->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
    }
};

// npc_scout_o_matic_5000
struct npc_scout_o_matic_5000 : public ScriptedAI
{
    npc_scout_o_matic_5000(Creature* creature) : ScriptedAI(creature) 
    { 
        me->CanFly();
        me->SetFlying(true);
    }

private:
    Vehicle* vehicle;

    void IsSummonedBy(Unit* summoner) override
    {
        vehicle = me->GetVehicleKit();
        summoner->EnterVehicle(me);
        Player* player = summoner->ToPlayer();
        me->GetMotionMaster()->MovePoint(1, 206.0f, -2289.0f, 117.0f, true);

        AddTimedDelayedOperation(25000, [this, player]() -> void
        {
            player->GetSceneMgr().PlaySceneByPackageId(SCENE_GORGROTHS_RITUAL);
            player->KilledMonsterCredit(156518);
        });

        AddTimedDelayedOperation(50000, [this]() -> void
        {
            me->GetMotionMaster()->MovePoint(2, 108.609f, -2413.905f, 90.530f, true);
        });

        AddTimedDelayedOperation(75000, [this, player]() -> void
        {
            player->ExitVehicle();
            me->DespawnOrUnsummon(1s);
        });
    }
};

// item 170557 item_resizer_v901
class item_resizer_v901 : public ItemScript
{
public:
    item_resizer_v901() : ItemScript("item_resizer_v901") { }

    bool OnUse(Player* player, Item* item, SpellCastTargets const& targets, ObjectGuid /*castId*/) override
    {
        if (Unit* target = player->GetSelectedUnit())
            if (target->GetEntry() == 156716)
            {
                player->CastSpell(target, 305716, false);
                player->KilledMonsterCredit(156722);
                target->ToCreature()->ForcedDespawn(1000, 15s);
            }
        return true;
    }
};

//156595 npc_giant_boar
struct npc_giant_boar : public ScriptedAI
{
    npc_giant_boar(Creature* creature) : ScriptedAI(creature) 
    { 
        Vehicle* vehicle = me->GetVehicleKit();
    }

    void Reset() override
    {
        me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
    }

    void OnSpellClick(Unit* clicker, bool& result) override
    {
        if (Player* player = clicker->ToPlayer())
        {
            // this first "if" will prevent players from cheating by using the huge pig again :) -Varjgard
            if ((player->GetQuestStatus(QUEST_RIDE_OF_THE_SCIENTIFICALLY_ENHANCED_BOAR) == QUEST_STATUS_COMPLETE) || (player->GetQuestStatus(QUEST_RIDE_OF_THE_SCIENTIFICALLY_ENHANCED_BOAR) == QUEST_STATUS_REWARDED))
            {
                player->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                player->ExitVehicle();
                me->DespawnOrUnsummon(10);
            }
            else if (player->GetQuestStatus(QUEST_RIDE_OF_THE_SCIENTIFICALLY_ENHANCED_BOAR) == QUEST_STATUS_INCOMPLETE)
            {
                me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                me->SetWalk(false);

                player->EnterVehicle(me);
                player->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                player->KilledMonsterCredit(156595); // ride the boar credit
            }
        }
    }

    void IsSummonedBy(Unit* summoner) override
    {
        me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
        me->SetWalk(false);

        if(Player* player = summoner->ToPlayer())
        {
            player->EnterVehicle(me);
            player->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            player->KilledMonsterCredit(156595); // ride the boar credit

            //Pretty weird combination between vehicle and scene, anyway, this is used as damage
            //player->GetSceneMgr().PlaySceneByPackageId(SCENE_SKELETON_ARMY_DARKMAUL_PLAINS);
        }
    }
};

//156799, familiar script will be also for horde version, which is 167128, scene 2905
struct npc_henry_garrick_156799 : public ScriptedAI
{
    npc_henry_garrick_156799(Creature* creature) : ScriptedAI(creature) { }

    void QuestReward(Player* player, Quest const* quest, uint32 /*opt*/) override
    {
        if (quest->GetQuestId() == QUEST_RIDE_OF_THE_SCIENTIFICALLY_ENHANCED_BOAR)
        {
            player->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            //this scene is triggered from somewhere :D but where??? so dont use this part of c++ -Varjgard
            //player->GetSceneMgr().PlaySceneByPackageId(SCENE_HENRY_REUNION);
        }
    }
};

//156943
struct npc_meredy_huntswell_156943 : public ScriptedAI
{
    npc_meredy_huntswell_156943(Creature* creature) : ScriptedAI(creature) { }

    // fix later - Varjgard
    /*void QuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_RIGHT_BENEATH_THEIR_EYES)
        {
            me->CastSpell(player, 313583, false);
            me->AddAura(313583, player);
            AddTimedDelayedOperation(6100, [this, player]() -> void
            {
                //player->SetDisplayId(x, 1.0f);
            });
            //Temp, i set it also to ignore all objectives, since you can't complete even through command, it's using criteria, not specific objects
            if (player->HasQuest(QUEST_RIGHT_BENEATH_THEIR_EYES))
                player->ForceCompleteQuest(QUEST_RIGHT_BENEATH_THEIR_EYES);

            player->NearTeleportTo(700.874f, -1882.962f, 186.508f, 1.208f, false);
        }
    }*/
};

// npc 156651 - captain garrick sparring version
struct npc_captain_garrick_156651 : public ScriptedAI
{
    npc_captain_garrick_156651(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
    }

    void QuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_ENHANCED_COMBAT_TACTICS)
        {
            if(Creature* npc = me->SummonCreature(me->GetEntry(), me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0U, 0U, true))
            {
                npc->SetFaction(14);
                npc->SetReactState(REACT_AGGRESSIVE);
            }

            me->DestroyForPlayer(player);
        }
    }

    void DamageTaken(Unit* attacker, uint32& /*damage*/) override
    {
        if (Player* player = attacker->ToPlayer())
            if (me->GetHealth() < me->CountPctFromMaxHealth(50)) // the intent is not to kill but to sparr
                if (player->HasQuest(QUEST_ENHANCED_COMBAT_TACTICS))
                {
                    player->KilledMonsterCredit(156651);
                    me->SummonCreature(me->GetEntry(), me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0U, 0U, true);
                    me->DespawnOrUnsummon(10ms);
                }
    }

    void JustDied(Unit* killer) override
    {
        if (Player* player = killer->ToPlayer())
            if (player->HasQuest(QUEST_ENHANCED_COMBAT_TACTICS))
            {
                player->KilledMonsterCredit(156651);
                me->SummonCreature(me->GetEntry(), me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0U, 0U, true);
                me->DespawnOrUnsummon(10ms);
            }
    }
};

// npc_captain_garrick_156280
struct npc_captain_garrick_156280 : public ScriptedAI
{
    npc_captain_garrick_156280(Creature* creature) : ScriptedAI(creature) { }

    void QuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_RIDE_OF_THE_SCIENTIFICALLY_ENHANCED_BOAR)
            player->SummonCreature(156595, player->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 60000, 0U, true); //10 minutes to despawn
    }

    void QuestReward(Player* player, Quest const* quest, uint32 /*opt*/) override
    {
        if (quest->GetQuestId() == QUEST_BRACE_FOR_IMPACT)
        {
            player->TeleportTo(2175, -462.722f, -2620.544f, 0.472f, 0.760f);
            player->GetSceneMgr().PlaySceneByPackageId(SCENE_ALI_HORDE_CRASHED_ON_ISLAND);
        }
    }
};

// npc 156626 npc_alaria_175031
struct npc_alaria_175031 : public ScriptedAI
{
    npc_alaria_175031(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
    }

    void QuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_NORTHBOUND)
        {
           if(Creature* npc = player->SummonCreature(156651, Position(-249.059f, -2492.52f, 18.0742f, 0.659374f), TEMPSUMMON_MANUAL_DESPAWN, 0U, 0U, true))
           {
                //npc->PlayDirectSound(154040, player); // TODO: find correct text and sound
                npc->Talk("Captain Garrick says: Let's go. Those monsters have my son.", CHAT_MSG_MONSTER_EMOTE, LANG_UNIVERSAL, 25, player);

                npc->GetScheduler().Schedule(Milliseconds(2000), [npc](TaskContext context)
                {
                    npc->GetMotionMaster()->MovePoint(1, -181.259f, -2575.281f, 31.0f, true);
                    npc->ForcedDespawn(10000);
                });
            }
        }
    }
};

// npc_geolord_grekog_151091
struct npc_geolord_grekog_151091 : public ScriptedAI
{
    npc_geolord_grekog_151091(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
    }

    void JustDied(Unit* attacker) override
    {
        if (Player* player = attacker->ToPlayer())
        {
            if (player->HasQuest(QUEST_DOWN_WITH_THE_QUILBOAR))
            {   // lindie springstock
                if(Creature* npc = player->SummonCreature(149899, Position(16.4271f, -2511.82f, 78.8215f, 5.66398f), TEMPSUMMON_MANUAL_DESPAWN, 0U, 0U, true))
                {
                    //npc->PlayDirectSound(165353, player); // TODO: find correct text and sound
                    npc->Talk("Lindie Springstock says: We will show these ogres the power of science!", CHAT_MSG_MONSTER_EMOTE, LANG_UNIVERSAL, 25, player);

                    npc->GetScheduler().Schedule(Milliseconds(1000), [npc](TaskContext context)
                    {
                        npc->GetMotionMaster()->MovePoint(1, 74.0192f, -2461.207764f, 88.0f, true);
                        npc->ForcedDespawn(4000);
                    });
                }
            }
        }
    }
};

//156929 npc_ralia_dreamchacer_156929
struct npc_ralia_dreamchacer_156929 : public ScriptedAI
{
    npc_ralia_dreamchacer_156929(Creature* creature) : ScriptedAI(creature) 
    { 
        Vehicle* vehicle = me->GetVehicleKit();
    }

    void Reset() override
    {
        me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
    }

    void OnSpellClick(Unit* clicker, bool& result) override
    {
        if (Player* player = clicker->ToPlayer())
        {
            // this first "if" will prevent players from cheating by using ralia again :) -Varjgard
            if (player->GetQuestStatus(QUEST_WHO_LURKS_IN_THE_PIT) == QUEST_STATUS_REWARDED)
            {
                player->ExitVehicle();
                me->DespawnOrUnsummon(10);
            }
            else if (player->HasQuest(QUEST_WHO_LURKS_IN_THE_PIT))
            {
                me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                me->SetWalk(false);

                player->EnterVehicle(me);
                player->ForceCompleteQuest(QUEST_WHO_LURKS_IN_THE_PIT);
            }
        }
    }

    void IsSummonedBy(Unit* summoner) override
    {
        me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
        me->SetWalk(false);

        if(Player* player = summoner->ToPlayer())
        {
            player->EnterVehicle(me);
            player->ForceCompleteQuest(QUEST_WHO_LURKS_IN_THE_PIT);
        }
    }
};

//npc_alliance_gryphon_154155
struct npc_alliance_gryphon_154155 : public ScriptedAI
{
    npc_alliance_gryphon_154155(Creature* creature) : ScriptedAI(creature) 
    { 
        Vehicle* vehicle = me->GetVehicleKit();
    }

    void Reset() override
    {
        me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
    }

    void OnSpellClick(Unit* clicker, bool& result) override
    {
        if (Player* player = clicker->ToPlayer())
        {
            if (player->HasQuest(QUEST_AN_END_TO_BEGINNINGS))
            {
                player->EnterVehicle(me);
                player->ForceCompleteQuest(QUEST_AN_END_TO_BEGINNINGS);

                player->GetSceneMgr().PlaySceneByPackageId(SCENE_FLY_AWAY);
                AddTimedDelayedOperation(66000, [this, player]() -> void
                {
                    player->GetSceneMgr().CancelSceneByPackageId(SCENE_FLY_AWAY); // there will be black screen without this

                    switch (player->GetTeam())
                    {
                    case ALLIANCE:
                        player->TeleportTo(0, -9060.474f, 438.164f, 93.055f, 0.657f); // stormwind
                        break;

                    case HORDE:
                        player->TeleportTo(1, 1458.339f, -4420.480f, 25.453f, 0.161f); // orgrimmar
                        break;
                    }
                });
            }
        }
    }
};

//go_ogre_runestone_339865
struct go_ogre_runestone_339865 : public GameObjectAI
{
    go_ogre_runestone_339865(GameObject* go) : GameObjectAI(go) { }

    bool GossipHello(Player* player) override
    {
        if (player->HasQuest(QUEST_CONTROLLING_THEIR_STONES))
        {
            if (player->GetQuestObjectiveData(QUEST_CONTROLLING_THEIR_STONES, 4) == 2)
            {
                player->ForceCompleteQuest(QUEST_CONTROLLING_THEIR_STONES);

                // TODO: kelra waypoints etc here
            }
            else
            {
                player->KillCreditGO(339865);
            }
        }

        return true;
    }
};

//npc_coulston_nereus
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

// npc_gutgruck_the_tough
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

    void EnterCombat(Unit* /*who*/) override
    {
        me->Say("Me strong! You can hurt!", LANG_UNIVERSAL);
    }
};

// at_for_gutgruck_the_tough
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

// hrun_the_exiled_156900
struct hrun_the_exiled_156900 : public ScriptedAI
{
    hrun_the_exiled_156900(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
    }

    void JustDied(Unit* attacker) override
    {
        if (Player* player = attacker->ToPlayer())
        {
            if (player->HasQuest(QUEST_WHO_LURKS_IN_THE_PIT))
            {
                // ralia
                // this one is not triggering..... -Varjgard
                if (Creature* npc = me->FindNearestCreature(156902, 100.0f, false))
                {
                    npc->DestroyForPlayer(player);
                }

                // ralia mount
                if (Creature* npc2 = player->SummonCreature(156929, player->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 60000, 0U, true)) //10 minutes to despawn
                {
                    //npc2->PlayDirectSound(165353, player); // TODO: find correct text and sound
                    npc2->Talk("Ralia Dreamchaser says: Out of the way, little spiders!", CHAT_MSG_MONSTER_EMOTE, LANG_UNIVERSAL, 25, player);
                }
            }
        }
    }
};

/* ExilesReach phasehandler */
class phasehandler_exiles_reach : public PlayerScript
{
public:
    phasehandler_exiles_reach() : PlayerScript("phasehandler_exiles_reach") { }


    uint32 PLAYER_CHAPTER = 1;         // starts from chapter 1, value updated by quest progress

    uint32 PHASE_UPDATE_DELAY      = 1000; // phase update delay in milliseconds
    uint32 PHASE_UPDATE_DELAY_DIFF = PHASE_UPDATE_DELAY;

    uint32 PHASE_GENERIC   = 12940;    // generic phase, active always
    uint32 PHASE_GENERIC_Z = 16752;    // generic phase for zombies etc. removed on chapter 7
    uint32 PHASE_CHAPTER1  = 13157;    // active only on start
    uint32 PHASE_CHAPTER2  = 13317;    // after 54951 QUEST_EMERGENCY_FIRST_AID is rewarded, phase 1 removed
    uint32 PHASE_CHAPTER3  = 13443;    // after 54952 QUEST_FINDING_THE_LOST_EXPEDITION is rewarded, phase 1,2 removed
    uint32 PHASE_CHAPTER4  = 13503;    // after 55174 QUEST_COOKING_MEAT is rewarded, phase 1,2,3 removed
    uint32 PHASE_CHAPTER5  = 13566;    // after 59254 QUEST_ENHANCED_COMBAT_TACTICS is rewarded, phase 1,2,3,4 removed
    uint32 PHASE_CHAPTER6  = 13619;    // after 55186 QUEST_DOWN_WITH_THE_QUILBOAR is rewarded or objectives are completed, phase 1,2,3,4,5 removed
    uint32 PHASE_CHAPTER7  = 13757;    // after 55879 QUEST_RIDE_OF_THE_SCIENTIFICALLY_ENHANCED_BOAR objectives are completed, phase 1,2,3,4,5,6,g_z removed
    uint32 PHASE_CHAPTER8  = 13758;    // after 55879 QUEST_RIDE_OF_THE_SCIENTIFICALLY_ENHANCED_BOAR is rewarded, phase 1,2,3,4,5,6,7,g_z removed
    uint32 PHASE_CHAPTER9  = 13762;    // when  55196 QUEST_THE_HARPY_PROBLEM is accepted or when it is rewarded, phase 1,2,3,4,5,6,7,8,g_z removed
    uint32 PHASE_CHAPTER10 = 13776;    // after 55763 QUEST_THE_RESCUE_OF_MEREDY_HUNTSWELL is rewarded or objectives are completed, phase 1,2,3,4,5,6,7,8,9,g_z removed
    uint32 PHASE_CHAPTER11 = 13779;    // when  55882 QUEST_MESSAGE_TO_BASE is accepted or when it is rewarded, phase 1,2,3,4,5,6,7,8,9,10,g_z removed
    uint32 PHASE_CHAPTER12 = 13780;    // when  55965 QUEST_WESTWARD_BOUND is accepted or when it is rewarded, phase 1,2,3,4,5,6,7,8,9,10,11,g_z removed
    uint32 PHASE_CHAPTER13 = 13783;    // when  55639 QUEST_WHO_LURKS_IN_THE_PIT is accepted, phase 1,2,3,4,5,6,7,8,9,10,11,12,g_z removed
    uint32 PHASE_CHAPTER14 = 13784;    // after 55639 QUEST_WHO_LURKS_IN_THE_PIT is rewarded, phase 1,2,3,4,5,6,7,8,9,10,11,12,13,g_z removed
    uint32 PHASE_CHAPTER15 = 13845;    // after 56344 QUEST_TO_DARKMAUL_CITADEL accepted or rewarded, phase 1,2,3,4,5,6,7,8,9,10,11,12,13,14,g_z removed
    uint32 PHASE_CHAPTER16 = 13878;    // when  55990 QUEST_CONTROLLING_THEIR_STONES is accepted, phase 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,g_z removed
    uint32 PHASE_CHAPTER17 = 14677;    // after 55990 QUEST_CONTROLLING_THEIR_STONES is rewarded, phase 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,g_z removed
    uint32 PHASE_CHAPTER18 = 15274;    // after 55992 QUEST_DUNGEON_DARKMAUL_CITADEL is rewarded, phase 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,g_z removed
    uint32 PHASE_CHAPTER19 = 15279;    // not used
    uint32 PHASE_CHAPTER20 = 15356;    // not used


    void OnUpdate(Player* player, uint32 diff) override
    {
        if (PHASE_UPDATE_DELAY_DIFF <= diff)
        {
            if ( (player->GetMapId() == MAP_NPE) && (player->GetAreaId() != AREA_NORTH_SEA) )
            {
                /* Update current chapter of player */
                if      ((player->GetQuestStatus(QUEST_DUNGEON_DARKMAUL_CITADEL) == QUEST_STATUS_COMPLETE) || (player->GetQuestStatus(QUEST_DUNGEON_DARKMAUL_CITADEL) == QUEST_STATUS_REWARDED))
                     PLAYER_CHAPTER = 18;
                else  if((player->GetQuestStatus(QUEST_CONTROLLING_THEIR_STONES) == QUEST_STATUS_COMPLETE) || (player->GetQuestStatus(QUEST_CONTROLLING_THEIR_STONES) == QUEST_STATUS_REWARDED))
                     PLAYER_CHAPTER = 17;
                else  if (player->HasQuest(QUEST_CONTROLLING_THEIR_STONES))
                     PLAYER_CHAPTER = 16;
                else  if((player->HasQuest(QUEST_TO_DARKMAUL_CITADEL)) || (player->GetQuestStatus(QUEST_TO_DARKMAUL_CITADEL) == QUEST_STATUS_REWARDED))
                     PLAYER_CHAPTER = 15;
                else if (player->GetQuestStatus(QUEST_WHO_LURKS_IN_THE_PIT) == QUEST_STATUS_REWARDED)
                     PLAYER_CHAPTER = 14;
                else if (player->HasQuest(QUEST_WHO_LURKS_IN_THE_PIT))
                     PLAYER_CHAPTER = 13;
                else if((player->HasQuest(QUEST_WESTWARD_BOUND)) || (player->GetQuestStatus(QUEST_WESTWARD_BOUND) == QUEST_STATUS_REWARDED))
                     PLAYER_CHAPTER = 12;
                else if((player->HasQuest(QUEST_MESSAGE_TO_BASE)) || (player->GetQuestStatus(QUEST_MESSAGE_TO_BASE) == QUEST_STATUS_REWARDED))
                     PLAYER_CHAPTER = 11;
                else if((player->GetQuestStatus(QUEST_THE_RESCUE_OF_MEREDY_HUNTSWELL) == QUEST_STATUS_COMPLETE) || (player->GetQuestStatus(QUEST_THE_RESCUE_OF_MEREDY_HUNTSWELL) == QUEST_STATUS_REWARDED))
                     PLAYER_CHAPTER = 10;
                else if((player->HasQuest(QUEST_THE_HARPY_PROBLEM)) || (player->GetQuestStatus(QUEST_THE_HARPY_PROBLEM) == QUEST_STATUS_REWARDED))
                     PLAYER_CHAPTER = 9;
                else if (player->GetQuestStatus(QUEST_RIDE_OF_THE_SCIENTIFICALLY_ENHANCED_BOAR) == QUEST_STATUS_REWARDED)
                     PLAYER_CHAPTER = 8;
                else if (player->GetQuestStatus(QUEST_RIDE_OF_THE_SCIENTIFICALLY_ENHANCED_BOAR) == QUEST_STATUS_COMPLETE)
                     PLAYER_CHAPTER = 7;
                else if((player->GetQuestStatus(QUEST_DOWN_WITH_THE_QUILBOAR) == QUEST_STATUS_COMPLETE) || (player->GetQuestStatus(QUEST_DOWN_WITH_THE_QUILBOAR) == QUEST_STATUS_REWARDED))
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


                /* Handle chapter phase shifts in exiles reach */
                /* Chapter 1 phase */
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

                /* Chapter 2 phase */
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

                /* Chapter 3 phase */
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

                /* Chapter 4 phase */
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

                /* Chapter 5 phase */
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

                /* Chapter 6 phase */
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

                /* Chapter 7 phase */
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
                    if (player->GetPhaseShift().HasPhase(PHASE_GENERIC_Z))PhasingHandler::RemovePhase(player, PHASE_GENERIC_Z,true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_CHAPTER7))PhasingHandler::AddPhase(player, PHASE_CHAPTER7, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC)) PhasingHandler::AddPhase(player, PHASE_GENERIC, true);
                }

                /* Chapter 8 phase */
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
                    if (player->GetPhaseShift().HasPhase(PHASE_GENERIC_Z))PhasingHandler::RemovePhase(player, PHASE_GENERIC_Z,true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_CHAPTER8))PhasingHandler::AddPhase(player, PHASE_CHAPTER8, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC)) PhasingHandler::AddPhase(player, PHASE_GENERIC, true);
                }

                /* Chapter 9 phase */
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
                    if (player->GetPhaseShift().HasPhase(PHASE_GENERIC_Z))PhasingHandler::RemovePhase(player, PHASE_GENERIC_Z,true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_CHAPTER9))PhasingHandler::AddPhase(player, PHASE_CHAPTER9, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC)) PhasingHandler::AddPhase(player, PHASE_GENERIC, true);
                }

                /* Chapter 10 phase */
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
                    if (player->GetPhaseShift().HasPhase(PHASE_GENERIC_Z))PhasingHandler::RemovePhase(player, PHASE_GENERIC_Z,true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_CHAPTER10))PhasingHandler::AddPhase(player, PHASE_CHAPTER10, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC)) PhasingHandler::AddPhase(player, PHASE_GENERIC, true);
                }

                /* Chapter 11 phase */
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
                    if (player->GetPhaseShift().HasPhase(PHASE_GENERIC_Z))PhasingHandler::RemovePhase(player, PHASE_GENERIC_Z,true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_CHAPTER11))PhasingHandler::AddPhase(player, PHASE_CHAPTER11, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC)) PhasingHandler::AddPhase(player, PHASE_GENERIC, true);
                }

                /* Chapter 12 phase */
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
                    if (player->GetPhaseShift().HasPhase(PHASE_GENERIC_Z))PhasingHandler::RemovePhase(player, PHASE_GENERIC_Z,true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_CHAPTER12))PhasingHandler::AddPhase(player, PHASE_CHAPTER12, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC)) PhasingHandler::AddPhase(player, PHASE_GENERIC, true);
                }

                /* Chapter 13 phase */
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
                    if (player->GetPhaseShift().HasPhase(PHASE_GENERIC_Z))PhasingHandler::RemovePhase(player, PHASE_GENERIC_Z,true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_CHAPTER13))PhasingHandler::AddPhase(player, PHASE_CHAPTER13, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC)) PhasingHandler::AddPhase(player, PHASE_GENERIC, true);
                }

                /* Chapter 14 phase */
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
                    if (player->GetPhaseShift().HasPhase(PHASE_GENERIC_Z))PhasingHandler::RemovePhase(player, PHASE_GENERIC_Z,true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_CHAPTER14))PhasingHandler::AddPhase(player, PHASE_CHAPTER14, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC)) PhasingHandler::AddPhase(player, PHASE_GENERIC, true);
                }

                /* Chapter 15 phase */
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
                    if (player->GetPhaseShift().HasPhase(PHASE_GENERIC_Z))PhasingHandler::RemovePhase(player, PHASE_GENERIC_Z,true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_CHAPTER15))PhasingHandler::AddPhase(player, PHASE_CHAPTER15, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC)) PhasingHandler::AddPhase(player, PHASE_GENERIC, true);
                }

                /* Chapter 16 phase */
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
                    if (player->GetPhaseShift().HasPhase(PHASE_GENERIC_Z))PhasingHandler::RemovePhase(player, PHASE_GENERIC_Z,true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_CHAPTER16))PhasingHandler::AddPhase(player, PHASE_CHAPTER16, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC)) PhasingHandler::AddPhase(player, PHASE_GENERIC, true);
                }

                /* Chapter 17 phase */
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
                    if (player->GetPhaseShift().HasPhase(PHASE_GENERIC_Z))PhasingHandler::RemovePhase(player, PHASE_GENERIC_Z,true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_CHAPTER17))PhasingHandler::AddPhase(player, PHASE_CHAPTER17, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC)) PhasingHandler::AddPhase(player, PHASE_GENERIC, true);
                }

                /* Chapter 18 phase */
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
                    if (player->GetPhaseShift().HasPhase(PHASE_GENERIC_Z))PhasingHandler::RemovePhase(player, PHASE_GENERIC_Z,true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_CHAPTER18))PhasingHandler::AddPhase(player, PHASE_CHAPTER18, true);
                    if (!player->GetPhaseShift().HasPhase(PHASE_GENERIC)) PhasingHandler::AddPhase(player, PHASE_GENERIC, true);
                }
            }
            PHASE_UPDATE_DELAY_DIFF = PHASE_UPDATE_DELAY;
        }
        else
            PHASE_UPDATE_DELAY_DIFF -= diff;
    }
};

void AddSC_zone_exiles_reach()
{    
    RegisterPlayerScript(exiles_reach);
    //RegisterZoneScript(zone_exiles_reach);
    RegisterCreatureAI(npc_combat_dummy);
    RegisterCreatureAI(npc_private_cole);
    //RegisterItemScript(item_first_aid_kit);
    RegisterGameObjectAI(go_campfire_339769);
    RegisterCreatureAI(npc_lindie_springstock_149899);
    RegisterCreatureAI(npc_scout_o_matic_5000);
   // RegisterItemScript(item_resizer_v901);
    RegisterCreatureAI(npc_giant_boar);
    RegisterCreatureAI(npc_meredy_huntswell_156943);
    RegisterCreatureAI(npc_henry_garrick_156799);
    RegisterCreatureAI(npc_captain_garrick_156651);
    RegisterCreatureAI(npc_captain_garrick_156280);
    RegisterCreatureAI(npc_alaria_175031);
    RegisterCreatureAI(npc_geolord_grekog_151091);
    RegisterCreatureAI(npc_ralia_dreamchacer_156929);
    RegisterCreatureAI(npc_alliance_gryphon_154155);
    RegisterGameObjectAI(go_ogre_runestone_339865);
    RegisterCreatureAI(npc_coulston_nereus);
    RegisterCreatureAI(hrun_the_exiled_156900);
    RegisterPlayerScript(phasehandler_exiles_reach);
    RegisterCreatureAI(npc_gutgruck_the_tough);
    RegisterAreaTriggerAI(at_for_gutgruck_the_tough);
}
