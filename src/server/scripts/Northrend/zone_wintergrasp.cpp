/* Copyright (C) 2008 - 2009 Trinity <http://www.trinitycore.org/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "BattlefieldMgr.h"
#include "BattlefieldWG.h"
#include "Battlefield.h"
#include "ScriptSystem.h"
#include "WorldSession.h"
#include "ObjectMgr.h"
#include "Vehicle.h"
#include "GameObjectAI.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellScript.h"
#include "Player.h"

#define GOSSIP_HELLO_DEMO1  "Build catapult."
#define GOSSIP_HELLO_DEMO2  "Build demolisher."
#define GOSSIP_HELLO_DEMO3  "Build siege engine."
#define GOSSIP_HELLO_DEMO4  "I cannot build more!"

enum WGqueuenpctext
{
    WG_NPCQUEUE_TEXT_H_NOWAR            = 14775,
    WG_NPCQUEUE_TEXT_H_QUEUE            = 14790,
    WG_NPCQUEUE_TEXT_H_WAR              = 14777,
    WG_NPCQUEUE_TEXT_A_NOWAR            = 14782,
    WG_NPCQUEUE_TEXT_A_QUEUE            = 14791,
    WG_NPCQUEUE_TEXT_A_WAR              = 14781,
    WG_NPCQUEUE_TEXTOPTION_JOIN         = 20077,
};

enum Spells
{
    // Demolisher engineers spells
    SPELL_BUILD_SIEGE_VEHICLE_FORCE_HORDE     = 61409,
    SPELL_BUILD_SIEGE_VEHICLE_FORCE_ALLIANCE  = 56662,
    SPELL_BUILD_CATAPULT_FORCE                = 56664,
    SPELL_BUILD_DEMOLISHER_FORCE              = 56659,
    SPELL_ACTIVATE_CONTROL_ARMS               = 49899,
    SPELL_RIDE_WG_VEHICLE                     = 60968,

    SPELL_VEHICLE_TELEPORT                    = 49759,

    // Spirit guide
    SPELL_CHANNEL_SPIRIT_HEAL                 = 22011,
};

enum CreatureIds
{
    NPC_GOBLIN_MECHANIC                             = 30400,
    NPC_GNOMISH_ENGINEER                            = 30499,

    NPC_WINTERGRASP_CONTROL_ARMS                    = 27852,

    NPC_WORLD_TRIGGER_LARGE_AOI_NOT_IMMUNE_PC_NPC   = 23472,
};

enum QuestIds
{
    QUEST_BONES_AND_ARROWS_HORDE_ATT              = 13193,
    QUEST_JINXING_THE_WALLS_HORDE_ATT             = 13202,
    QUEST_SLAY_THEM_ALL_HORDE_ATT                 = 13180,
    QUEST_FUELING_THE_DEMOLISHERS_HORDE_ATT       = 13200,
    QUEST_HEALING_WITH_ROSES_HORDE_ATT            = 13201,
    QUEST_DEFEND_THE_SIEGE_HORDE_ATT              = 13223,

    QUEST_BONES_AND_ARROWS_HORDE_DEF              = 13199,
    QUEST_WARDING_THE_WALLS_HORDE_DEF             = 13192,
    QUEST_SLAY_THEM_ALL_HORDE_DEF                 = 13178,
    QUEST_FUELING_THE_DEMOLISHERS_HORDE_DEF       = 13191,
    QUEST_HEALING_WITH_ROSES_HORDE_DEF            = 13194,
    QUEST_TOPPLING_THE_TOWERS_HORDE_DEF           = 13539,
    QUEST_STOP_THE_SIEGE_HORDE_DEF                = 13185,

    QUEST_BONES_AND_ARROWS_ALLIANCE_ATT           = 13196,
    QUEST_WARDING_THE_WARRIORS_ALLIANCE_ATT       = 13198,
    QUEST_NO_MERCY_FOR_THE_MERCILESS_ALLIANCE_ATT = 13179,
    QUEST_DEFEND_THE_SIEGE_ALLIANCE_ATT           = 13222,
    QUEST_A_RARE_HERB_ALLIANCE_ATT                = 13195,

    QUEST_BONES_AND_ARROWS_ALLIANCE_DEF           = 13154,
    QUEST_WARDING_THE_WARRIORS_ALLIANCE_DEF       = 13153,
    QUEST_NO_MERCY_FOR_THE_MERCILESS_ALLIANCE_DEF = 13177,
    QUEST_SHOUTHERN_SABOTAGE_ALLIANCE_DEF         = 13538,
    QUEST_STOP_THE_SIEGE_ALLIANCE_DEF             = 13186,
    QUEST_A_RARE_HERB_ALLIANCE_DEF                = 13156,
};

uint8 const MAX_WINTERGRASP_VEHICLES = 4;

uint32 const vehiclesList[MAX_WINTERGRASP_VEHICLES] =
{
    NPC_WINTERGRASP_CATAPULT,
    NPC_WINTERGRASP_DEMOLISHER,
    NPC_WINTERGRASP_SIEGE_ENGINE_ALLIANCE,
    NPC_WINTERGRASP_SIEGE_ENGINE_HORDE
};

class npc_wg_demolisher_engineer : public CreatureScript
{
    public:
        npc_wg_demolisher_engineer() : CreatureScript("npc_wg_demolisher_engineer") { }

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            if (creature->IsQuestGiver())
                player->PrepareQuestMenu(creature->GetGUID());

            if (CanBuild(creature))
            {
                if (player->HasAura(SPELL_CORPORAL))
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                else if (player->HasAura(SPELL_LIEUTENANT))
                {
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                }
            }
            else
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);

            player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
        {
            player->CLOSE_GOSSIP_MENU();

            if (CanBuild(creature))
            {
                switch (action - GOSSIP_ACTION_INFO_DEF)
                {
                    case 0:
                        creature->CastSpell(player, SPELL_BUILD_CATAPULT_FORCE, true);
                        break;
                    case 1:
                        creature->CastSpell(player, SPELL_BUILD_DEMOLISHER_FORCE, true);
                        break;
                    case 2:
                        creature->CastSpell(player, player->GetTeamId() == TEAM_ALLIANCE ? SPELL_BUILD_SIEGE_VEHICLE_FORCE_ALLIANCE : SPELL_BUILD_SIEGE_VEHICLE_FORCE_HORDE, true);
                        break;
                }
                if (Creature* controlArms = creature->FindNearestCreature(NPC_WINTERGRASP_CONTROL_ARMS, 30.0f, true))
                    creature->CastSpell(controlArms, SPELL_ACTIVATE_CONTROL_ARMS, true);
            }
            return true;
        }

    private:
        bool CanBuild(Creature* creature)
        {
            Battlefield* wintergrasp = sBattlefieldMgr->GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_WG);
            if (!wintergrasp)
                return false;

            switch (creature->GetEntry())
            {
                case NPC_GOBLIN_MECHANIC:
                    return (wintergrasp->GetData(BATTLEFIELD_WG_DATA_MAX_VEHICLE_H) > wintergrasp->GetData(BATTLEFIELD_WG_DATA_VEHICLE_H));
                case NPC_GNOMISH_ENGINEER:
                    return (wintergrasp->GetData(BATTLEFIELD_WG_DATA_MAX_VEHICLE_A) > wintergrasp->GetData(BATTLEFIELD_WG_DATA_VEHICLE_A));
                default:
                    return false;
            }
        }
};

class npc_wg_spirit_guide : public CreatureScript
{
    public:
        npc_wg_spirit_guide() : CreatureScript("npc_wg_spirit_guide") { }

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            if (creature->IsQuestGiver())
                player->PrepareQuestMenu(creature->GetGUID());

            Battlefield* wintergrasp = sBattlefieldMgr->GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_WG);
            if (!wintergrasp)
                return true;

            GraveyardVect graveyard = wintergrasp->GetGraveyardVector();
            for (uint8 i = 0; i < graveyard.size(); i++)
                if (graveyard[i]->GetControlTeamId() == player->GetTeamId())
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, player->GetSession()->GetTrinityString(((BfGraveyardWG*)graveyard[i])->GetTextId()), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + i);

            player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 action) override
        {
            player->CLOSE_GOSSIP_MENU();

            Battlefield* wintergrasp = sBattlefieldMgr->GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_WG);
            if (wintergrasp)
            {
                GraveyardVect gy = wintergrasp->GetGraveyardVector();
                for (uint8 i = 0; i < gy.size(); i++)
                    if (action - GOSSIP_ACTION_INFO_DEF == i && gy[i]->GetControlTeamId() == player->GetTeamId())
                        if (WorldSafeLocsEntry const* safeLoc = sWorldSafeLocsStore.LookupEntry(gy[i]->GetGraveyardId()))
                            player->TeleportTo(safeLoc->map_id, safeLoc->x, safeLoc->y, safeLoc->z, 0);
            }
            return true;
        }

        struct npc_wg_spirit_guideAI : public ScriptedAI
        {
            npc_wg_spirit_guideAI(Creature* creature) : ScriptedAI(creature) { }

            void UpdateAI(uint32 /*diff*/) override
            {
                if (!me->HasUnitState(UNIT_STATE_CASTING))
                    DoCast(me, SPELL_CHANNEL_SPIRIT_HEAL);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_wg_spirit_guideAI(creature);
        }
};

enum WGQueue
{
    SPELL_FROST_ARMOR                               = 12544
};

class npc_wg_queue : public CreatureScript
{
    public:
        npc_wg_queue() : CreatureScript("npc_wg_queue") { }

    struct npc_wg_queueAI : public ScriptedAI
    {
        npc_wg_queueAI(Creature* creature) : ScriptedAI(creature)
        {
            FrostArmor_Timer = 0;
        }

        uint32 FrostArmor_Timer;

        void Reset() override
        {
            FrostArmor_Timer = 0;
        }

        void EnterCombat(Unit* /*who*/) override { }

        void UpdateAI(uint32 diff) override
        {
            if (FrostArmor_Timer <= diff)
            {
                DoCast(me, SPELL_FROST_ARMOR);
                FrostArmor_Timer = 180000;
            }
            else FrostArmor_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_wg_queueAI(creature);
    }

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            if (creature->IsQuestGiver())
                player->PrepareQuestMenu(creature->GetGUID());

            Battlefield* wintergrasp = sBattlefieldMgr->GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_WG);
            if (!wintergrasp)
                return true;

            if (wintergrasp->IsWarTime())
            {
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, player->GetSession()->GetTrinityString(WG_NPCQUEUE_TEXTOPTION_JOIN), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                player->SEND_GOSSIP_MENU(wintergrasp->GetDefenderTeam() ? WG_NPCQUEUE_TEXT_H_WAR : WG_NPCQUEUE_TEXT_A_WAR, creature->GetGUID());
            }
            else
            {
                uint32 timer = wintergrasp->GetTimer() / 1000;
                player->SendUpdateWorldState(4354, time(NULL) + timer);
                if (timer < 15 * MINUTE)
                {
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, player->GetSession()->GetTrinityString(WG_NPCQUEUE_TEXTOPTION_JOIN), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                    player->SEND_GOSSIP_MENU(wintergrasp->GetDefenderTeam() ? WG_NPCQUEUE_TEXT_H_QUEUE : WG_NPCQUEUE_TEXT_A_QUEUE, creature->GetGUID());
                }
                else
                    player->SEND_GOSSIP_MENU(wintergrasp->GetDefenderTeam() ? WG_NPCQUEUE_TEXT_H_NOWAR : WG_NPCQUEUE_TEXT_A_NOWAR, creature->GetGUID());
            }
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 /*action*/) override
        {
            player->CLOSE_GOSSIP_MENU();

            Battlefield* wintergrasp = sBattlefieldMgr->GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_WG);
            if (!wintergrasp)
                return true;

            if (wintergrasp->IsWarTime())
                wintergrasp->InvitePlayerToWar(player);
            else
            {
                uint32 timer = wintergrasp->GetTimer() / 1000;
                if (timer < 15 * MINUTE)
                    wintergrasp->InvitePlayerToQueue(player);
            }
            return true;
        }
};

class go_wg_vehicle_teleporter : public GameObjectScript
{
    public:
        go_wg_vehicle_teleporter() : GameObjectScript("go_wg_vehicle_teleporter") { }

        struct go_wg_vehicle_teleporterAI : public GameObjectAI
        {
            go_wg_vehicle_teleporterAI(GameObject* gameObject) : GameObjectAI(gameObject), _checkTimer(1000) { }

            void UpdateAI(uint32 diff) override
            {
                if (_checkTimer <= diff)
                {
                    if (Battlefield* wg = sBattlefieldMgr->GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_WG))
                        // Tabulation madness in the hole!
                        for (uint8 i = 0; i < MAX_WINTERGRASP_VEHICLES; i++)
                            if (Creature* vehicleCreature = go->FindNearestCreature(vehiclesList[i], 3.0f, true))
                                if (!vehicleCreature->HasAura(SPELL_VEHICLE_TELEPORT) && vehicleCreature->getFaction() == WintergraspFaction[wg->GetDefenderTeam()])
                                    if (Creature* teleportTrigger = vehicleCreature->FindNearestCreature(NPC_WORLD_TRIGGER_LARGE_AOI_NOT_IMMUNE_PC_NPC, 100.0f, true))
                                        teleportTrigger->CastSpell(vehicleCreature, SPELL_VEHICLE_TELEPORT, true);

                    _checkTimer = 1000;
                }
                else _checkTimer -= diff;
            }

          private:
              uint32 _checkTimer;
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return new go_wg_vehicle_teleporterAI(go);
        }
};

class npc_wg_quest_giver : public CreatureScript
{
    public:
        npc_wg_quest_giver() : CreatureScript("npc_wg_quest_giver") { }

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            Battlefield* wintergrasp = sBattlefieldMgr->GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_WG);
            if (!wintergrasp)
                return true;

            if (creature->IsVendor())
            {
                player->ADD_GOSSIP_ITEM_DB(Player::GetDefaultGossipMenuForSource(creature), 0, GOSSIP_SENDER_MAIN, GOSSIP_OPTION_VENDOR);
                player->PlayerTalkClass->GetGossipMenu().AddGossipMenuItemData(0, 0, 0);
            }

            /// @todo: move this to conditions or something else

            // Player::PrepareQuestMenu(guid)
            if (creature->IsQuestGiver())
            {
                QuestRelationBounds objectQR = sObjectMgr->GetCreatureQuestRelationBounds(creature->GetEntry());
                QuestRelationBounds objectQIR = sObjectMgr->GetCreatureQuestInvolvedRelationBounds(creature->GetEntry());

                QuestMenu& qm = player->PlayerTalkClass->GetQuestMenu();
                qm.ClearMenu();

                for (QuestRelations::const_iterator i = objectQIR.first; i != objectQIR.second; ++i)
                {
                    uint32 questId = i->second;
                    QuestStatus status = player->GetQuestStatus(questId);
                    if (status == QUEST_STATUS_COMPLETE)
                        qm.AddMenuItem(questId, 4);
                    else if (status == QUEST_STATUS_INCOMPLETE)
                        qm.AddMenuItem(questId, 4);
                    //else if (status == QUEST_STATUS_AVAILABLE)
                    //    qm.AddMenuItem(quest_id, 2);
                }

                for (QuestRelations::const_iterator i = objectQR.first; i != objectQR.second; ++i)
                {
                    uint32 questId = i->second;
                    Quest const* quest = sObjectMgr->GetQuestTemplate(questId);
                    if (!quest)
                        continue;

                    if (!player->CanTakeQuest(quest, false))
                        continue;

                    switch (questId)
                    {
                        // Horde attacker
                        case QUEST_BONES_AND_ARROWS_HORDE_ATT:
                        case QUEST_JINXING_THE_WALLS_HORDE_ATT:
                        case QUEST_SLAY_THEM_ALL_HORDE_ATT:
                        case QUEST_FUELING_THE_DEMOLISHERS_HORDE_ATT:
                        case QUEST_HEALING_WITH_ROSES_HORDE_ATT:
                        case QUEST_DEFEND_THE_SIEGE_HORDE_ATT:
                            if (wintergrasp->GetAttackerTeam() != TEAM_HORDE)
                                continue;
                            break;
                        // Horde defender
                        case QUEST_BONES_AND_ARROWS_HORDE_DEF:
                        case QUEST_WARDING_THE_WALLS_HORDE_DEF:
                        case QUEST_SLAY_THEM_ALL_HORDE_DEF:
                        case QUEST_FUELING_THE_DEMOLISHERS_HORDE_DEF:
                        case QUEST_HEALING_WITH_ROSES_HORDE_DEF:
                        case QUEST_TOPPLING_THE_TOWERS_HORDE_DEF:
                        case QUEST_STOP_THE_SIEGE_HORDE_DEF:
                            if (wintergrasp->GetDefenderTeam() != TEAM_HORDE)
                                continue;
                            break;
                        // Alliance attacker
                        case QUEST_BONES_AND_ARROWS_ALLIANCE_ATT:
                        case QUEST_WARDING_THE_WARRIORS_ALLIANCE_ATT:
                        case QUEST_NO_MERCY_FOR_THE_MERCILESS_ALLIANCE_ATT:
                        case QUEST_DEFEND_THE_SIEGE_ALLIANCE_ATT:
                        case QUEST_A_RARE_HERB_ALLIANCE_ATT:
                            if (wintergrasp->GetAttackerTeam() != TEAM_ALLIANCE)
                                continue;
                            break;
                        // Alliance defender
                        case QUEST_BONES_AND_ARROWS_ALLIANCE_DEF:
                        case QUEST_WARDING_THE_WARRIORS_ALLIANCE_DEF:
                        case QUEST_NO_MERCY_FOR_THE_MERCILESS_ALLIANCE_DEF:
                        case QUEST_SHOUTHERN_SABOTAGE_ALLIANCE_DEF:
                        case QUEST_STOP_THE_SIEGE_ALLIANCE_DEF:
                        case QUEST_A_RARE_HERB_ALLIANCE_DEF:
                            if (wintergrasp->GetDefenderTeam() != TEAM_ALLIANCE)
                                continue;
                            break;
                        default:
                            break;
                    }

                    if (quest->IsAutoComplete())
                        qm.AddMenuItem(questId, 4);
                    else if (player->GetQuestStatus(questId) == QUEST_STATUS_NONE)
                        qm.AddMenuItem(questId, 2);
                }
            }

            player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
            return true;
        }
};

class spell_wintergrasp_force_building : public SpellScriptLoader
{
    public:
        spell_wintergrasp_force_building() : SpellScriptLoader("spell_wintergrasp_force_building") { }

        class spell_wintergrasp_force_building_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_wintergrasp_force_building_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_BUILD_CATAPULT_FORCE)
                    || !sSpellMgr->GetSpellInfo(SPELL_BUILD_DEMOLISHER_FORCE)
                    || !sSpellMgr->GetSpellInfo(SPELL_BUILD_SIEGE_VEHICLE_FORCE_HORDE)
                    || !sSpellMgr->GetSpellInfo(SPELL_BUILD_SIEGE_VEHICLE_FORCE_ALLIANCE))
                    return false;
                return true;
            }

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetHitUnit()->CastSpell(GetHitUnit(), GetEffectValue(), false);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_wintergrasp_force_building_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_wintergrasp_force_building_SpellScript();
        }
};

class spell_wintergrasp_grab_passenger : public SpellScriptLoader
{
    public:
        spell_wintergrasp_grab_passenger() : SpellScriptLoader("spell_wintergrasp_grab_passenger") { }

        class spell_wintergrasp_grab_passenger_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_wintergrasp_grab_passenger_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (Player* target = GetHitPlayer())
                    target->CastSpell(GetCaster(), SPELL_RIDE_WG_VEHICLE, false);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_wintergrasp_grab_passenger_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_wintergrasp_grab_passenger_SpellScript();
        }
};

class achievement_wg_didnt_stand_a_chance : public AchievementCriteriaScript
{
public:
    achievement_wg_didnt_stand_a_chance() : AchievementCriteriaScript("achievement_wg_didnt_stand_a_chance") { }

    bool OnCheck(Player* source, Unit* target) override
    {
        if (!target)
            return false;

        if (Player* victim = target->ToPlayer())
        {
            if (!victim->IsMounted())
                return false;

            if (Vehicle* vehicle = source->GetVehicle())
                if (vehicle->GetVehicleInfo()->m_ID == 244) // Wintergrasp Tower Cannon
                    return true;
        }

        return false;
    }
};

enum WgTeleport
{
    SPELL_WINTERGRASP_TELEPORT_TRIGGER = 54643,
};

class spell_wintergrasp_defender_teleport : public SpellScriptLoader
{
public:
    spell_wintergrasp_defender_teleport() : SpellScriptLoader("spell_wintergrasp_defender_teleport") { }

    class spell_wintergrasp_defender_teleport_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_wintergrasp_defender_teleport_SpellScript);

        SpellCastResult CheckCast()
        {
            if (Battlefield* wg = sBattlefieldMgr->GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_WG))
                if (Player* target = GetExplTargetUnit()->ToPlayer())
                    // check if we are in Wintergrasp at all, SotA uses same teleport spells
                    if ((target->GetZoneId() == 4197 && target->GetTeamId() != wg->GetDefenderTeam()) || target->HasAura(SPELL_WINTERGRASP_TELEPORT_TRIGGER))
                        return SPELL_FAILED_BAD_TARGETS;
            return SPELL_CAST_OK;
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_wintergrasp_defender_teleport_SpellScript::CheckCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_wintergrasp_defender_teleport_SpellScript();
    }
};

class spell_wintergrasp_defender_teleport_trigger : public SpellScriptLoader
{
public:
    spell_wintergrasp_defender_teleport_trigger() : SpellScriptLoader("spell_wintergrasp_defender_teleport_trigger") { }

    class spell_wintergrasp_defender_teleport_trigger_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_wintergrasp_defender_teleport_trigger_SpellScript);

        void HandleDummy(SpellEffIndex /*effindex*/)
        {
            if (Unit* target = GetHitUnit())
            {
                WorldLocation loc = target->GetWorldLocation();
                SetExplTargetDest(loc);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_wintergrasp_defender_teleport_trigger_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_wintergrasp_defender_teleport_trigger_SpellScript();
    }
};

void AddSC_wintergrasp()
{
    new npc_wg_queue();
    new npc_wg_spirit_guide();
    new npc_wg_demolisher_engineer();
    new go_wg_vehicle_teleporter();
    new npc_wg_quest_giver();
    new spell_wintergrasp_force_building();
    new spell_wintergrasp_grab_passenger();
    new achievement_wg_didnt_stand_a_chance();
    new spell_wintergrasp_defender_teleport();
    new spell_wintergrasp_defender_teleport_trigger();
}
