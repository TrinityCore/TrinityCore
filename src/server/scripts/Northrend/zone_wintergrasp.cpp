/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "ConditionMgr.h"
#include "Creature.h"
#include "DBCStructure.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SharedDefines.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "Timer.h"
#include "Unit.h"
#include "Vehicle.h"
#include <array>

enum ZoneWintergraspNPCTexts
{
    NPC_TEXT_HORDE_HOW_CAN_I_HELP        = 13759,
    NPC_TEXT_HORDE_SORRY_ONLY_OFFICER    = 13761,
    NPC_TEXT_ALLIANCE_HOW_CAN_I_HELP     = 13798,
    NPC_TEXT_ALLIANCE_SORRY_ONLY_OFFICER = 14172,
    NPC_TEXT_SORRY_USED_ALL_PARTS        = 13786,

    NPC_TEXT_HORDE_NOWAR                 = 14775,
    NPC_TEXT_HORDE_QUEUE                 = 14790,
    NPC_TEXT_HORDE_WAR                   = 14777,
    NPC_TEXT_ALLIANCE_NOWAR              = 14782,
    NPC_TEXT_ALLIANCE_QUEUE              = 14791,
    NPC_TEXT_ALLIANCE_WAR                = 14781
};

enum ZoneWintergraspGossipMenuIds
{
    GOSSIP_MENU_ENGINEER_HORDE    = 9904,
    GOSSIP_MENU_ENGINEER_ALLIANCE = 9923,
};

enum ZoneWintergraspGossipMenuOptionIds
{
    GOSSIP_MENU_OPTION_ENGINEER_CATAPULT     = 0,
    GOSSIP_MENU_OPTION_ENGINEER_DEMOLISHER   = 1,
    GOSSIP_MENU_OPTION_ENGINEER_SIEGE_ENGINE = 2
};

enum ZoneWintergraspSpells
{
    SPELL_BUILD_SIEGE_VEHICLE_FORCE_HORDE    = 61409, // Demolisher engineers spells
    SPELL_BUILD_SIEGE_VEHICLE_FORCE_ALLIANCE = 56662,
    SPELL_BUILD_CATAPULT_FORCE               = 56664,
    SPELL_BUILD_DEMOLISHER_FORCE             = 56659,
    SPELL_ACTIVATE_CONTROL_ARMS              = 49899,
    SPELL_RIDE_WINTERGRASP_VEHICLE           = 60968,
    SPELL_VEHICLE_TELEPORT                   = 49759,
    SPELL_CHANNEL_SPIRIT_HEAL                = 22011, // Spirit guide
    SPELL_WINTERGRASP_TELEPORT_TRIGGER       = 54643,
};

enum ZoneWintergraspCreatureEntries
{
    NPC_WORLD_TRIGGER_LARGE_AOI_NOT_IMMUNE_PC_NPC = 23472,
};

enum ZoneWintergraspQuestIds
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

static size_t constexpr MAX_WINTERGRASP_VEHICLES = 4;
static std::array<uint32, MAX_WINTERGRASP_VEHICLES> constexpr wintergraspVehicleIds =
{
    NPC_WINTERGRASP_CATAPULT,
    NPC_WINTERGRASP_DEMOLISHER,
    NPC_WINTERGRASP_SIEGE_ENGINE_ALLIANCE,
    NPC_WINTERGRASP_SIEGE_ENGINE_HORDE
};

struct npc_wg_demolisher_engineer : public ScriptedAI
{
    npc_wg_demolisher_engineer(Creature* creature) : ScriptedAI(creature)
    {
    }

    void Reset() override
    {
    }

    bool GossipHello(Player* player) override
    {
        if (CanBuild())
        {
            if (player->HasAura(SPELL_WINTERGRASP_CORPORAL))
            {
                AddGossipItemFor(player, me->GetEntry() == NPC_WINTERGRASP_GOBLIN_MECHANIC ? GOSSIP_MENU_ENGINEER_HORDE : GOSSIP_MENU_ENGINEER_ALLIANCE, GOSSIP_MENU_OPTION_ENGINEER_CATAPULT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                SendGossipMenuFor(player, me->GetEntry() == NPC_WINTERGRASP_GOBLIN_MECHANIC ? NPC_TEXT_HORDE_HOW_CAN_I_HELP : NPC_TEXT_ALLIANCE_HOW_CAN_I_HELP, me);
                return true;
            }
            else if (player->HasAura(SPELL_WINTERGRASP_LIEUTENANT))
            {
                AddGossipItemFor(player, me->GetEntry() == NPC_WINTERGRASP_GOBLIN_MECHANIC ? GOSSIP_MENU_ENGINEER_HORDE : GOSSIP_MENU_ENGINEER_ALLIANCE, GOSSIP_MENU_OPTION_ENGINEER_CATAPULT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                AddGossipItemFor(player, me->GetEntry() == NPC_WINTERGRASP_GOBLIN_MECHANIC ? GOSSIP_MENU_ENGINEER_HORDE : GOSSIP_MENU_ENGINEER_ALLIANCE, GOSSIP_MENU_OPTION_ENGINEER_DEMOLISHER, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                AddGossipItemFor(player, me->GetEntry() == NPC_WINTERGRASP_GOBLIN_MECHANIC ? GOSSIP_MENU_ENGINEER_HORDE : GOSSIP_MENU_ENGINEER_ALLIANCE, GOSSIP_MENU_OPTION_ENGINEER_SIEGE_ENGINE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                SendGossipMenuFor(player, me->GetEntry() == NPC_WINTERGRASP_GOBLIN_MECHANIC ? NPC_TEXT_HORDE_HOW_CAN_I_HELP : NPC_TEXT_ALLIANCE_HOW_CAN_I_HELP, me);
                return true;
            }
            else
            {
                SendGossipMenuFor(player, me->GetEntry() == NPC_WINTERGRASP_GOBLIN_MECHANIC ? NPC_TEXT_HORDE_SORRY_ONLY_OFFICER : NPC_TEXT_ALLIANCE_SORRY_ONLY_OFFICER, me);
                return true;
            }
        }

        SendGossipMenuFor(player, NPC_TEXT_SORRY_USED_ALL_PARTS, me);
        return true;
    }

    bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
    {
        uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
        CloseGossipMenuFor(player);

        if (CanBuild())
        {
            uint32 const selection = action - GOSSIP_ACTION_INFO_DEF;
            if (selection >= 0 && selection < 3)
                player->CastSpell(player, SPELL_ACTIVATE_CONTROL_ARMS, true);

            switch (selection)
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
                default:
                    break;
            }
        }
        return true;
    }

private:
    bool CanBuild() const
    {
        Battlefield* wintergrasp = sBattlefieldMgr->GetEnabledBattlefield(me->GetZoneId());
        if (!wintergrasp || !wintergrasp->IsWarTime())
            return false;

        switch (me->GetEntry())
        {
            case NPC_WINTERGRASP_GOBLIN_MECHANIC:
                //return (wintergrasp->GetData(BATTLEFIELD_WG_DATA_MAX_VEHICLE_H) > wintergrasp->GetData(BATTLEFIELD_WG_DATA_VEHICLE_H));
            case NPC_WINTERGRASP_GNOMISH_ENGINEER:
                //return (wintergrasp->GetData(BATTLEFIELD_WG_DATA_MAX_VEHICLE_A) > wintergrasp->GetData(BATTLEFIELD_WG_DATA_VEHICLE_A));
            default:
                return false;
        }
    }
};

struct go_wg_vehicle_teleporter : public GameObjectAI
{
    go_wg_vehicle_teleporter(GameObject* gameObject) : GameObjectAI(gameObject), _checkTimer(1000) { }

    void UpdateAI(uint32 diff)
    {
        _checkTimer.Update(diff);
        if (_checkTimer.Passed())
        {
            Battlefield* wintergrasp = sBattlefieldMgr->GetEnabledBattlefield(me->GetZoneId());
            if (!wintergrasp || !wintergrasp->IsWarTime())
            {
                _checkTimer.Reset(60000);
                return;
            }

            Creature* teleportTrigger = me->FindNearestCreature(NPC_WORLD_TRIGGER_LARGE_AOI_NOT_IMMUNE_PC_NPC, 5.0f, true);
            if (!teleportTrigger)
            {
                _checkTimer.Reset(60000);
                return;
            }

            for (uint32 entry : wintergraspVehicleIds)
            {
                if (Creature* vehicle = me->FindNearestCreature(entry, 5.0f, true))
                    HandleTeleport(vehicle, teleportTrigger, wintergrasp);
            }

            _checkTimer.Reset(2000);
        }
    }

private:
    void HandleTeleport(Creature* vehicle, Creature* teleportTrigger, Battlefield* wintergrasp)
    {
        if (vehicle->HasAura(SPELL_VEHICLE_TELEPORT))
            return;

        Player* owner = vehicle->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!owner)
            return;

        if (wintergrasp->GetAttackingTeamId() != owner->GetTeamId())
            return;

        teleportTrigger->CastSpell(vehicle, SPELL_VEHICLE_TELEPORT, true);
    }

    TimeTracker _checkTimer;
};

// 56659 - Build Demolisher (Force)
// 56662 - Build Siege Vehicle (Force)
// 56664 - Build Catapult (Force)
// 61409 - Build Siege Vehicle (Force)
class spell_wintergrasp_force_building : public SpellScript
{
    PrepareSpellScript(spell_wintergrasp_force_building);

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
        OnEffectHitTarget += SpellEffectFn(spell_wintergrasp_force_building::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 61178 - Grab Passenger
class spell_wintergrasp_grab_passenger : public SpellScript
{
    PrepareSpellScript(spell_wintergrasp_grab_passenger);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Player* target = GetHitPlayer())
            target->CastSpell(GetCaster(), SPELL_RIDE_WINTERGRASP_VEHICLE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_wintergrasp_grab_passenger::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 54640 - Teleport (Used also in Strand of the Ancients)
class spell_wintergrasp_defender_teleport : public SpellScript
{
    PrepareSpellScript(spell_wintergrasp_defender_teleport);

    SpellCastResult CheckCast()
    {
        if (Player* target = GetExplTargetUnit()->ToPlayer())
        {
            if (target->GetZoneId() == BATTLEFIELD_ZONEID_WINTERGRASP)
            {
                if (Battlefield* wintergrasp = sBattlefieldMgr->GetBattlefield(target->GetZoneId()))
                {
                    if (wintergrasp->GetControllingTeam() != PVP_TEAM_NEUTRAL && target->GetTeamId() != wintergrasp->GetControllingTeamId())
                        return SPELL_FAILED_BAD_TARGETS;

                    if (target->HasAura(SPELL_WINTERGRASP_TELEPORT_TRIGGER))
                        return SPELL_FAILED_BAD_TARGETS;

                    return SPELL_CAST_OK;
                }

                return SPELL_FAILED_DONT_REPORT;
            }
        }

        return SPELL_CAST_OK;
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_wintergrasp_defender_teleport::CheckCast);
    }
};

// 54643 - Teleport
class spell_wintergrasp_defender_teleport_trigger : public SpellScript
{
    PrepareSpellScript(spell_wintergrasp_defender_teleport_trigger);

    void HandleDummy(SpellEffIndex /*effindex*/)
    {
        if (Unit* target = GetHitUnit())
        {
            WorldLocation destination = target->GetWorldLocation();
            SetExplTargetDest(destination);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_wintergrasp_defender_teleport_trigger::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 58549 Tenacity
// 59911 Tenacity
class spell_wintergrasp_tenacity_refresh : public AuraScript
{
    PrepareAuraScript(spell_wintergrasp_tenacity_refresh);

    bool Validate(SpellInfo const* spellInfo) override
    {
        uint32 triggeredSpellId = spellInfo->Effects[EFFECT_2].CalcValue();
        return !triggeredSpellId || ValidateSpellInfo({ triggeredSpellId });
    }

    void Refresh(AuraEffect const* aurEff)
    {
        PreventDefaultAction();

        if (uint32 triggeredSpellId = GetSpellInfo()->Effects[aurEff->GetEffIndex()].CalcValue())
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
        if (uint32 triggeredSpellId = GetSpellInfo()->Effects[aurEff->GetEffIndex()].CalcValue())
            GetTarget()->RemoveAurasDueToSpell(triggeredSpellId);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_wintergrasp_tenacity_refresh::Refresh, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY);
        AfterEffectRemove += AuraEffectRemoveFn(spell_wintergrasp_tenacity_refresh::OnRemove, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 2584 - Waiting to Resurrect
class spell_wintergrasp_waiting_to_resurrect : public AuraScript
{
    PrepareAuraScript(spell_wintergrasp_waiting_to_resurrect);

    bool Load() override
    {
        Unit* owner = GetUnitOwner();
        return owner && owner->GetTypeId() == TYPEID_PLAYER && owner->GetZoneId() == BATTLEFIELD_ZONEID_WINTERGRASP;
    }

    void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (!owner)
            return;

        if (Battlefield* wintergrasp = sBattlefieldMgr->GetBattlefield(owner->GetZoneId()))
            wintergrasp->HandleRemovePlayerFromResurrectionQueue(owner->ToPlayer());
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_wintergrasp_waiting_to_resurrect::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
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

class condition_is_wintergrasp_horde : public ConditionScript
{
    public:
        condition_is_wintergrasp_horde() : ConditionScript("condition_is_wintergrasp_horde") { }

        bool OnConditionCheck(Condition const* /*condition*/, ConditionSourceInfo& /*sourceInfo*/)
        {
            Battlefield* wintergrasp = sBattlefieldMgr->GetEnabledBattlefield(BATTLEFIELD_BATTLEID_WINTERGRASP);
            if (wintergrasp && wintergrasp->GetControllingTeam() == PVP_TEAM_HORDE)
                return true;
            return false;
        }
};

class condition_is_wintergrasp_alliance : public ConditionScript
{
    public:
        condition_is_wintergrasp_alliance() : ConditionScript("condition_is_wintergrasp_alliance") { }

        bool OnConditionCheck(Condition const* /*condition*/, ConditionSourceInfo& /*sourceInfo*/)
        {
            Battlefield* wintergrasp = sBattlefieldMgr->GetEnabledBattlefield(BATTLEFIELD_BATTLEID_WINTERGRASP);
            if (wintergrasp && wintergrasp->GetControllingTeam() == PVP_TEAM_ALLIANCE)
                return true;
            return false;
        }
};

void AddSC_wintergrasp()
{
    RegisterCreatureAI(npc_wg_demolisher_engineer);
    RegisterGameObjectAI(go_wg_vehicle_teleporter);
    RegisterSpellScript(spell_wintergrasp_force_building);
    RegisterSpellScript(spell_wintergrasp_grab_passenger);
    RegisterSpellScript(spell_wintergrasp_defender_teleport);
    RegisterSpellScript(spell_wintergrasp_defender_teleport_trigger);
    RegisterAuraScript(spell_wintergrasp_tenacity_refresh);
    RegisterAuraScript(spell_wintergrasp_waiting_to_resurrect);
    new achievement_wg_didnt_stand_a_chance();
    new condition_is_wintergrasp_horde();
    new condition_is_wintergrasp_alliance();
}
