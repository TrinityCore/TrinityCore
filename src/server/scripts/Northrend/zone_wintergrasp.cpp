/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "Battlefield.h"
#include "BattlefieldMgr.h"
#include "BattlefieldWG.h"
#include "DBCStores.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "GameObjectData.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptSystem.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "Vehicle.h"
#include "WorldSession.h"

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

        struct npc_wg_demolisher_engineerAI : public ScriptedAI
        {
            npc_wg_demolisher_engineerAI(Creature* creature) : ScriptedAI(creature) { }

            bool GossipHello(Player* player) override
            {
                if (me->IsQuestGiver())
                    player->PrepareQuestMenu(me->GetGUID());

                if (CanBuild())
                {
                    if (player->HasAura(SPELL_CORPORAL))
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                    else if (player->HasAura(SPELL_LIEUTENANT))
                    {
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                    }
                }
                else
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);

                SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
                return true;
            }

            bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
            {
                uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
                CloseGossipMenuFor(player);

                if (CanBuild())
                {
                    switch (action - GOSSIP_ACTION_INFO_DEF)
                    {
                        case 0:
                            DoCast(player, SPELL_BUILD_CATAPULT_FORCE, true);
                            break;
                        case 1:
                            DoCast(player, SPELL_BUILD_DEMOLISHER_FORCE, true);
                            break;
                        case 2:
                            DoCast(player, player->GetTeamId() == TEAM_ALLIANCE ? SPELL_BUILD_SIEGE_VEHICLE_FORCE_ALLIANCE : SPELL_BUILD_SIEGE_VEHICLE_FORCE_HORDE, true);
                            break;
                    }
                    if (Creature* controlArms = me->FindNearestCreature(NPC_WINTERGRASP_CONTROL_ARMS, 30.0f, true))
                        DoCast(controlArms, SPELL_ACTIVATE_CONTROL_ARMS, true);
                }
                return true;
            }

        private:
            bool CanBuild() const
            {
                Battlefield* wintergrasp = sBattlefieldMgr->GetBattlefield(BATTLEFIELD_BATTLEID_WINTERGRASP);
                if (!wintergrasp)
                    return false;

                switch (me->GetEntry())
                {
                    case NPC_GOBLIN_MECHANIC:
                        return (wintergrasp->GetData(DATA_WINTERGRASP_MAX_VEHICLE_HORDE) > wintergrasp->GetData(DATA_WINTERGRASP_VEHICLE_HORDE));
                    case NPC_GNOMISH_ENGINEER:
                        return (wintergrasp->GetData(DATA_WINTERGRASP_MAX_VEHICLE_ALLIANCE) > wintergrasp->GetData(DATA_WINTERGRASP_VEHICLE_ALLIANCE));
                    default:
                        return false;
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_wg_demolisher_engineerAI(creature);
        }
};

class npc_wg_spirit_guide : public CreatureScript
{
    public:
        npc_wg_spirit_guide() : CreatureScript("npc_wg_spirit_guide") { }

        struct npc_wg_spirit_guideAI : public ScriptedAI
        {
            npc_wg_spirit_guideAI(Creature* creature) : ScriptedAI(creature), _graveyardId(0), _teamId(TEAM_NEUTRAL), _needSearch(false), _searchTimer(0) { }

            void InitializeAI() override
            {
                BattlefieldWintergrasp* wintergrasp = static_cast<BattlefieldWintergrasp*>(sBattlefieldMgr->GetBattlefield(BATTLEFIELD_BATTLEID_WINTERGRASP));
                if (wintergrasp && wintergrasp->IsEnabled())
                {
                    for (uint8 itr = 0; itr < GRAVEYARDID_MAX && _needSearch == false; ++itr)
                    {
                        if (WintergraspGraveyard* graveyard = static_cast<WintergraspGraveyard*>(wintergrasp->GetGraveyard(itr)))
                        {
                            if (graveyard->IsSpellAreaForced() && graveyard->GetSpiritTeamId(me->GetGUID()) != TEAM_NEUTRAL)
                            {
                                _graveyardId = itr;
                                _needSearch = true;
                            }
                        }
                    }
                }

                ScriptedAI::InitializeAI();
            }

            bool GossipHello(Player* player) override
            {
                if (me->IsQuestGiver())
                    player->PrepareQuestMenu(me->GetGUID());

                if (BattlefieldWintergrasp* wintergrasp = static_cast<BattlefieldWintergrasp*>(sBattlefieldMgr->GetBattlefield(BATTLEFIELD_BATTLEID_WINTERGRASP)))
                {
                    for (uint8 itr = 0; itr < GRAVEYARDID_MAX; itr++)
                    {
                        if (WintergraspGraveyard* graveyard = static_cast<WintergraspGraveyard*>(wintergrasp->GetGraveyard(itr)))
                            if (graveyard->GetControlTeamId() == player->GetTeamId())
                                AddGossipItemFor(player, GOSSIP_ICON_CHAT, player->GetSession()->GetTrinityString(graveyard->GetTextId()), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + itr);
                    }

                    SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
                }

                return true;
            }

            bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
            {
                uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
                CloseGossipMenuFor(player);
                if (BattlefieldWintergrasp* wintergrasp = static_cast<BattlefieldWintergrasp*>(sBattlefieldMgr->GetBattlefield(BATTLEFIELD_BATTLEID_WINTERGRASP)))
                {
                    if (WintergraspGraveyard* graveyard = static_cast<WintergraspGraveyard*>(wintergrasp->GetGraveyard(action - GOSSIP_ACTION_INFO_DEF)))
                        if (graveyard->GetControlTeamId() == player->GetTeamId())
                            if (WorldSafeLocsEntry const* safeLoc = sWorldSafeLocsStore.LookupEntry(graveyard->GetId()))
                                player->TeleportTo(safeLoc->map_id, safeLoc->x, safeLoc->y, safeLoc->z, 0);
                }

                return true;
            }

            void UpdateAI(uint32 diff) override
            {
                if (!me->HasUnitState(UNIT_STATE_CASTING))
                    DoCastSelf(SPELL_CHANNEL_SPIRIT_HEAL);

                if (!_needSearch)
                    return;

                _searchTimer.Update(diff);
                if (_searchTimer.Passed())
                {
                    BattlefieldWintergrasp* wintergrasp = static_cast<BattlefieldWintergrasp*>(sBattlefieldMgr->GetBattlefield(BATTLEFIELD_BATTLEID_WINTERGRASP));
                    if (!wintergrasp)
                        return;

                    if (WintergraspGraveyard* graveyard = static_cast<WintergraspGraveyard*>(wintergrasp->GetGraveyard(_graveyardId)))
                        _teamId = graveyard->GetControlTeamId();

                    if ((_teamId == TEAM_ALLIANCE && me->GetEntry() == NPC_DWARVEN_SPIRIT_GUIDE) || (_teamId == TEAM_HORDE && me->GetEntry() == NPC_TAUNKA_SPIRIT_GUIDE))
                    {
                        std::list<Player*> players = wintergrasp->GetPlayerListInSourceRange(me, 10.f, _teamId);
                        for (Player* player : players)
                        {
                            if (!player->IsAlive() && _handledPlayers.find(player->GetGUID()) == _handledPlayers.end())
                            {
                                player->AddAura(_teamId == TEAM_ALLIANCE ? SPELL_ALLIANCE_CONTROLS_FACTORY_PHASE_SHIFT : SPELL_HORDE_CONTROLS_FACTORY_PHASE_SHIFT, player);
                                _handledPlayers.insert(player->GetGUID());
                            }
                        }

                        if (!_handledPlayers.empty())
                        {
                            GuidUnorderedSet handledPlayersTemp;
                            for (ObjectGuid playerGuid : _handledPlayers)
                            {
                                if (Player* player = ObjectAccessor::GetPlayer(*me, playerGuid))
                                {
                                    if (player->IsAlive() || !player->IsInMap(me) || !player->IsWithinDist(me, 7.0f))
                                    {
                                        RemoveAuras(player);
                                        player->UpdateAreaDependentAuras(player->GetAreaId());
                                    }
                                    else
                                        handledPlayersTemp.insert(player->GetGUID());
                                }
                            }
                            _handledPlayers = handledPlayersTemp;
                        }
                    }
                    _searchTimer.Reset(1 * IN_MILLISECONDS);
                }
            }

            void RemoveAuras(Player* player)
            {
                if (!player)
                    return;

                player->RemoveAurasDueToSpell(SPELL_ALLIANCE_CONTROLS_FACTORY_PHASE_SHIFT);
                player->RemoveAurasDueToSpell(SPELL_HORDE_CONTROLS_FACTORY_PHASE_SHIFT);
            }

        private:
            uint32 _graveyardId;
            TeamId _teamId;
            bool _needSearch;
            TimeTracker _searchTimer;
            GuidUnorderedSet _handledPlayers;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_wg_spirit_guideAI(creature);
        }
};

enum WGQueueMisc
{
    SPELL_FROST_ARMOR = 12544,
    GO_WINTERGRASP_PORTAL = 193772,
    EVENT_CHECK_WINTERGRASP_DEFENDER = 1,
    EVENT_FROST_ARMOR = 2,
    NPC_MAGISTER_SURDIEL = 32170,
    NPC_MAGISTER_BRAEDIN = 32169
};

Position const PortalPos[] =
{
    { 5923.220215f, 570.825317f, 661.087219f, 6.132774f }, // Horde
    { 5686.8f,      773.175f,    647.752f,    1.83259f  }  // Alliance
};

class npc_wg_queue : public CreatureScript
{
    public:
        npc_wg_queue() : CreatureScript("npc_wg_queue") { }

        struct npc_wg_queueAI : public ScriptedAI
        {
            npc_wg_queueAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                _events.ScheduleEvent(EVENT_CHECK_WINTERGRASP_DEFENDER, Seconds(5));
                _events.ScheduleEvent(EVENT_FROST_ARMOR, Seconds(1));
            }

            bool GossipHello(Player* player) override
            {
                if (me->IsQuestGiver())
                    player->PrepareQuestMenu(me->GetGUID());

                Battlefield* wintergrasp = sBattlefieldMgr->GetBattlefield(BATTLEFIELD_BATTLEID_WINTERGRASP);
                if (!wintergrasp)
                    return true;

                if (wintergrasp->IsWarTime())
                {
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, player->GetSession()->GetTrinityString(WG_NPCQUEUE_TEXTOPTION_JOIN), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                    SendGossipMenuFor(player, wintergrasp->GetDefenderTeam() ? WG_NPCQUEUE_TEXT_H_WAR : WG_NPCQUEUE_TEXT_A_WAR, me->GetGUID());
                }
                else
                {
                    uint32 timer = wintergrasp->GetTimer() / 1000;
                    player->SendUpdateWorldState(4354, time(nullptr) + timer);
                    if (timer < 15 * MINUTE)
                    {
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, player->GetSession()->GetTrinityString(WG_NPCQUEUE_TEXTOPTION_JOIN), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                        SendGossipMenuFor(player, wintergrasp->GetDefenderTeam() ? WG_NPCQUEUE_TEXT_H_QUEUE : WG_NPCQUEUE_TEXT_A_QUEUE, me->GetGUID());
                    }
                    else
                        SendGossipMenuFor(player, wintergrasp->GetDefenderTeam() ? WG_NPCQUEUE_TEXT_H_NOWAR : WG_NPCQUEUE_TEXT_A_NOWAR, me->GetGUID());
                }
                return true;
            }

            bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
            {
                CloseGossipMenuFor(player);

                Battlefield* wintergrasp = sBattlefieldMgr->GetBattlefield(BATTLEFIELD_BATTLEID_WINTERGRASP);
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

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                if (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CHECK_WINTERGRASP_DEFENDER:
                            if (Battlefield* wintergrasp = sBattlefieldMgr->GetBattlefield(BATTLEFIELD_BATTLEID_WINTERGRASP))
                            {
                                if (wintergrasp->IsEnabled())
                                {
                                    if (GameObject* portal = me->FindNearestGameObject(GO_WINTERGRASP_PORTAL, 25.f))
                                    {
                                        if ((wintergrasp->GetDefenderTeam() == TEAM_HORDE && me->GetEntry() == NPC_MAGISTER_BRAEDIN) || (wintergrasp->GetDefenderTeam() == TEAM_ALLIANCE && me->GetEntry() == NPC_MAGISTER_SURDIEL))
                                            portal->Delete();
                                    }
                                    else
                                    {
                                        if (wintergrasp->GetDefenderTeam() == TEAM_ALLIANCE && me->GetEntry() == NPC_MAGISTER_BRAEDIN)
                                            me->SummonGameObject(GO_WINTERGRASP_PORTAL, PortalPos[1], QuaternionData(), 1000);
                                        else if (wintergrasp->GetDefenderTeam() == TEAM_HORDE && me->GetEntry() == NPC_MAGISTER_SURDIEL)
                                            me->SummonGameObject(GO_WINTERGRASP_PORTAL, PortalPos[0], QuaternionData(), 1000);
                                    }
                                    _events.Repeat(Seconds(5));
                                }
                                else
                                {
                                    if (!me->FindNearestGameObject(GO_WINTERGRASP_PORTAL, 25.f))
                                    {
                                        if (me->GetEntry() == NPC_MAGISTER_BRAEDIN)
                                            me->SummonGameObject(GO_WINTERGRASP_PORTAL, PortalPos[1], QuaternionData(), 1000);
                                        else if (me->GetEntry() == NPC_MAGISTER_SURDIEL)
                                            me->SummonGameObject(GO_WINTERGRASP_PORTAL, PortalPos[0], QuaternionData(), 1000);
                                    }
                                    _events.Repeat(Minutes(5));
                                }
                            }
                            break;
                        case EVENT_FROST_ARMOR:
                            DoCastSelf(SPELL_FROST_ARMOR);
                            _events.Repeat(Minutes(3));
                            break;
                        default:
                            break;
                    }
                }

                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_wg_queueAI(creature);
        }
};

class go_wg_vehicle_teleporter : public GameObjectScript
{
    public:
        go_wg_vehicle_teleporter() : GameObjectScript("go_wg_vehicle_teleporter") { }

        struct go_wg_vehicle_teleporterAI : public GameObjectAI
        {
            go_wg_vehicle_teleporterAI(GameObject* gameObject) : GameObjectAI(gameObject), _checkTimer(0) { }

            Creature* GetTeleportTrigger(Creature* vehicle)
            {
                if (!vehicle->HasAura(SPELL_VEHICLE_TELEPORT))
                {
                    if (Player* owner = vehicle->GetCharmerOrOwnerPlayerOrPlayerItself())
                        if (me->GetFaction() == WintergraspFaction[owner->GetTeamId()])
                            if (Creature* teleportTrigger = owner->SummonTrigger(me->GetPositionX() - 60.f, me->GetPositionY(), me->GetPositionZ() + 1.f, vehicle->GetOrientation(), 1000))
                                return teleportTrigger;
                }

                return nullptr;
            }

            void UpdateAI(uint32 diff)
            {
                _checkTimer.Update(diff);
                if (_checkTimer.Passed())
                {
                    for (uint8 itr = 0; itr < MAX_WINTERGRASP_VEHICLES; ++itr)
                    {
                        if (Creature* vehicleCreature = me->FindNearestCreature(vehiclesList[itr], 3.0f, true))
                            if (Creature* teleportTrigger = GetTeleportTrigger(vehicleCreature))
                                teleportTrigger->CastSpell(vehicleCreature, SPELL_VEHICLE_TELEPORT, true);
                    }

                    _checkTimer.Reset(2000);
                }
            }

          private:
              TimeTracker _checkTimer;
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return new go_wg_vehicle_teleporterAI(go);
        }
};

class npc_wg_give_promotion_credit : public CreatureScript
{
    public:
        npc_wg_give_promotion_credit() : CreatureScript("npc_wg_give_promotion_credit") { }

        struct npc_wg_give_promotion_creditAI : public ScriptedAI
        {
            npc_wg_give_promotion_creditAI(Creature* creature) : ScriptedAI(creature) { }

            void JustDied(Unit* killer) override
            {
                if (killer->GetTypeId() != TYPEID_PLAYER)
                    return;

                BattlefieldWintergrasp* wintergrasp = static_cast<BattlefieldWintergrasp*>(sBattlefieldMgr->GetBattlefield(BATTLEFIELD_BATTLEID_WINTERGRASP));
                if (!wintergrasp)
                    return;

                wintergrasp->HandlePromotion(killer->ToPlayer(), me);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_wg_give_promotion_creditAI(creature);
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
                return ValidateSpellInfo(
                {
                    SPELL_BUILD_CATAPULT_FORCE,
                    SPELL_BUILD_DEMOLISHER_FORCE,
                    SPELL_BUILD_SIEGE_VEHICLE_FORCE_HORDE,
                    SPELL_BUILD_SIEGE_VEHICLE_FORCE_ALLIANCE
                });
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
                if (Battlefield* wintergrasp = sBattlefieldMgr->GetBattlefield(BATTLEFIELD_BATTLEID_WINTERGRASP))
                {
                    if (Player* target = GetExplTargetUnit()->ToPlayer())
                        // check if we are in Wintergrasp at all, SotA uses same teleport spells
                        if ((target->GetZoneId() == 4197 && target->GetTeamId() != wintergrasp->GetDefenderTeam()) || target->HasAura(SPELL_WINTERGRASP_TELEPORT_TRIGGER))
                            return SPELL_FAILED_BAD_TARGETS;
                }
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

// 58549 Tenacity
// 59911 Tenacity
class spell_wintergrasp_tenacity_refresh : public AuraScript
{
    PrepareAuraScript(spell_wintergrasp_tenacity_refresh);

    void Refresh(AuraEffect* /*aurEff*/)
    {
        GetAura()->RefreshDuration();
    }

    void Register() override
    {
        OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_wintergrasp_tenacity_refresh::Refresh, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class condition_is_wintergrasp_horde : public ConditionScript
{
    public:
        condition_is_wintergrasp_horde() : ConditionScript("condition_is_wintergrasp_horde") { }

        bool OnConditionCheck(Condition const* /* condition */, ConditionSourceInfo& /* sourceInfo */)
        {
            Battlefield* wintergrasp = sBattlefieldMgr->GetBattlefield(BATTLEFIELD_BATTLEID_WINTERGRASP);
            if (wintergrasp && wintergrasp->IsEnabled() && wintergrasp->GetDefenderTeam() == TEAM_HORDE)
                return true;
            return false;
        }
};

class condition_is_wintergrasp_alliance : public ConditionScript
{
    public:
        condition_is_wintergrasp_alliance() : ConditionScript("condition_is_wintergrasp_alliance") { }

        bool OnConditionCheck(Condition const* /* condition */, ConditionSourceInfo& /* sourceInfo */)
        {
            Battlefield* wintergrasp = sBattlefieldMgr->GetBattlefield(BATTLEFIELD_BATTLEID_WINTERGRASP);
            if (wintergrasp && wintergrasp->IsEnabled() && wintergrasp->GetDefenderTeam() == TEAM_ALLIANCE)
                return true;
            return false;
        }
};

void AddSC_wintergrasp()
{
    new npc_wg_queue();
    new npc_wg_spirit_guide();
    new npc_wg_demolisher_engineer();
    new go_wg_vehicle_teleporter();
    new npc_wg_give_promotion_credit();
    new spell_wintergrasp_force_building();
    new spell_wintergrasp_grab_passenger();
    new achievement_wg_didnt_stand_a_chance();
    new spell_wintergrasp_defender_teleport();
    new spell_wintergrasp_defender_teleport_trigger();
    RegisterAuraScript(spell_wintergrasp_tenacity_refresh);
    new condition_is_wintergrasp_horde();
    new condition_is_wintergrasp_alliance();
}
