/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "Battlefield/BattlefieldWG.h"
#include "DBCStores.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "GameTime.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptSystem.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
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

            bool OnGossipHello(Player* player) override
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

            bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
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
                Battlefield* wintergrasp = sBattlefieldMgr->GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_WG);
                if (!wintergrasp)
                    return false;

                switch (me->GetEntry())
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
            npc_wg_spirit_guideAI(Creature* creature) : ScriptedAI(creature) { }

            void UpdateAI(uint32 /*diff*/) override
            {
                if (!me->HasUnitState(UNIT_STATE_CASTING))
                    DoCast(me, SPELL_CHANNEL_SPIRIT_HEAL);
            }

            bool OnGossipHello(Player* player) override
            {
                if (me->IsQuestGiver())
                    player->PrepareQuestMenu(me->GetGUID());

                Battlefield* wintergrasp = sBattlefieldMgr->GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_WG);
                if (!wintergrasp)
                    return true;

                GraveyardVect graveyard = wintergrasp->GetGraveyardVector();
                for (uint8 i = 0; i < graveyard.size(); i++)
                    if (graveyard[i]->GetControlTeamId() == player->GetTeamId())
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, player->GetSession()->GetTrinityString(((BfGraveyardWG*)graveyard[i])->GetTextId()), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + i);

                SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
                return true;
            }

            bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
            {
                uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
                CloseGossipMenuFor(player);

                Battlefield* wintergrasp = sBattlefieldMgr->GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_WG);
                if (wintergrasp)
                {
                    GraveyardVect gy = wintergrasp->GetGraveyardVector();
                    for (uint8 i = 0; i < gy.size(); i++)
                        if (action - GOSSIP_ACTION_INFO_DEF == i && gy[i]->GetControlTeamId() == player->GetTeamId())
                            if (WorldSafeLocsEntry const* safeLoc = sWorldSafeLocsStore.LookupEntry(gy[i]->GetGraveyardId()))
                                player->TeleportTo(safeLoc->Continent, safeLoc->Loc.X, safeLoc->Loc.Y, safeLoc->Loc.Z, 0);
                }
                return true;
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

            void JustEngagedWith(Unit* /*who*/) override { }

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

            bool OnGossipHello(Player* player) override
            {
                if (me->IsQuestGiver())
                    player->PrepareQuestMenu(me->GetGUID());

                Battlefield* wintergrasp = sBattlefieldMgr->GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_WG);
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
                    player->SendUpdateWorldState(4354, GameTime::GetGameTime() + timer);
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

            bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
            {
                CloseGossipMenuFor(player);

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

            bool IsFriendly(Unit* passenger)
            {
                return ((me->GetFaction() == FACTION_HORDE_GENERIC_WG && passenger->GetFaction() == HORDE) ||
                        (me->GetFaction() == FACTION_ALLIANCE_GENERIC_WG && passenger->GetFaction() == ALLIANCE));
            }

            Creature* GetValidVehicle(Creature* cVeh)
            {
                if (!cVeh->HasAura(SPELL_VEHICLE_TELEPORT))
                    if (Vehicle* vehicle = cVeh->GetVehicleKit())
                        if (Unit* passenger = vehicle->GetPassenger(0))
                            if (IsFriendly(passenger))
                                if (Creature* teleportTrigger = passenger->SummonTrigger(me->GetPositionX()-60.0f, me->GetPositionY(), me->GetPositionZ()+1.0f, cVeh->GetOrientation(), 1s))
                                    return teleportTrigger;

                return nullptr;
            }

            void UpdateAI(uint32 diff) override
            {
                _checkTimer += diff;
                if (_checkTimer >= 1000)
                {
                    for (uint8 i = 0; i < MAX_WINTERGRASP_VEHICLES; i++)
                        if (Creature* vehicleCreature = me->FindNearestCreature(vehiclesList[i], 3.0f, true))
                            if (Creature* teleportTrigger = GetValidVehicle(vehicleCreature))
                                teleportTrigger->CastSpell(vehicleCreature, SPELL_VEHICLE_TELEPORT, true);

                    _checkTimer = 0;
                }
            }
          private:
              uint32 _checkTimer;
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return new go_wg_vehicle_teleporterAI(go);
        }
};

/* 49899 - Activate Robotic Arms
   56659 - Build Demolisher (Force)
   56662 - Build Siege Vehicle (Force)
   56664 - Build Catapult (Force)
   61409 - Build Siege Vehicle (Force) */
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

// 61178 - Grab Passenger
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
                    if (vehicle->GetVehicleInfo()->ID == 244) // Wintergrasp Tower Cannon
                        return true;
            }

            return false;
        }
};

enum WgTeleport
{
    SPELL_WINTERGRASP_TELEPORT_TRIGGER = 54643,
};

// 54640 - Teleport
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
                        if ((target->GetZoneId() == AREA_WINTERGRASP && target->GetTeamId() != wg->GetDefenderTeam()) || target->HasAura(SPELL_WINTERGRASP_TELEPORT_TRIGGER))
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

// 54643 - Teleport
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

// 58549 - Tenacity
// 59911 - Tenacity
class spell_wintergrasp_tenacity_refresh : public AuraScript
{
    PrepareAuraScript(spell_wintergrasp_tenacity_refresh);

    bool Validate(SpellInfo const* spellInfo) override
    {
        uint32 triggeredSpellId = spellInfo->GetEffect(EFFECT_2).CalcValue();
        return !triggeredSpellId || ValidateSpellInfo({ triggeredSpellId });
    }

    void Refresh(AuraEffect const* aurEff)
    {
        PreventDefaultAction();

        if (uint32 triggeredSpellId = aurEff->GetSpellEffectInfo().CalcValue())
        {
            int32 bp = 0;
            if (AuraEffect const* healEffect = GetEffect(EFFECT_0))
                bp = healEffect->GetAmount();

            CastSpellExtraArgs args(aurEff);
            args
                .AddSpellMod(SPELLVALUE_BASE_POINT0, bp)
                .AddSpellMod(SPELLVALUE_BASE_POINT1, bp);
            GetTarget()->CastSpell(nullptr, triggeredSpellId, args);
        }

        RefreshDuration();
    }

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (uint32 triggeredSpellId = aurEff->GetSpellEffectInfo().CalcValue())
            GetTarget()->RemoveAurasDueToSpell(triggeredSpellId);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_wintergrasp_tenacity_refresh::Refresh, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY);
        AfterEffectRemove += AuraEffectRemoveFn(spell_wintergrasp_tenacity_refresh::OnRemove, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class condition_is_wintergrasp_horde : public ConditionScript
{
    public:
        condition_is_wintergrasp_horde() : ConditionScript("condition_is_wintergrasp_horde") { }

        bool OnConditionCheck(Condition const* /* condition */, ConditionSourceInfo& /* sourceInfo */) override
        {
            Battlefield* wintergrasp = sBattlefieldMgr->GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_WG);
            if (wintergrasp && wintergrasp->IsEnabled() && wintergrasp->GetDefenderTeam() == TEAM_HORDE)
                return true;
            return false;
        }
};

class condition_is_wintergrasp_alliance : public ConditionScript
{
    public:
        condition_is_wintergrasp_alliance() : ConditionScript("condition_is_wintergrasp_alliance") { }

        bool OnConditionCheck(Condition const* /* condition */, ConditionSourceInfo& /* sourceInfo */) override
        {
            Battlefield* wintergrasp = sBattlefieldMgr->GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_WG);
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
    new spell_wintergrasp_force_building();
    new spell_wintergrasp_grab_passenger();
    new achievement_wg_didnt_stand_a_chance();
    new spell_wintergrasp_defender_teleport();
    new spell_wintergrasp_defender_teleport_trigger();
    RegisterSpellScript(spell_wintergrasp_tenacity_refresh);
    new condition_is_wintergrasp_horde();
    new condition_is_wintergrasp_alliance();
}
