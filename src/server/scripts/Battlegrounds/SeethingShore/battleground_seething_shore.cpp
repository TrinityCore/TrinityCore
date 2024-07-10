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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "Battleground.h"
#include "BattlegroundPackets.h"
#include "BattlegroundScript.h"
#include "Containers.h"
#include "CreatureAI.h"
#include "G3DPosition.hpp"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "SpellHistory.h"
#include "TaskScheduler.h"
#include "TemporarySummon.h"
#include "WaypointDefines.h"

#include <unordered_map>

namespace SeethingShore
{
    namespace Actions
    {
        static constexpr uint32 CaptureAzeriteNode = 1;
        static constexpr uint32 ConsumeBuff = 2;
        static constexpr uint32 SpawnBuff = 3;
        static constexpr uint32 CommanderText1 = 4;
    }

    namespace Areas
    {
        static constexpr uint32 Shipwreck = 9511;
        static constexpr uint32 Waterfall = 9512;
        static constexpr uint32 CrashSite = 9513;
        static constexpr uint32 Overlook = 9514;
        static constexpr uint32 TarPits = 9515;
        static constexpr uint32 Ruins = 9516;
        static constexpr uint32 Tower = 9517;
        static constexpr uint32 Plunge = 9518;
        static constexpr uint32 TidePools = 9519;
        static constexpr uint32 Bonfire = 9520;
        static constexpr uint32 Ridge = 9521;
        static constexpr uint32 Temple = 9522;

        static constexpr std::array<uint32, 12> AzeriteNodes =
        {
            Ruins, Ridge, Plunge, Shipwreck, CrashSite, TidePools, Tower, Bonfire, TarPits, Temple, Overlook, Waterfall
        };
    }

    namespace Creatures
    {
        static constexpr uint32 Controller = 125269;
        static constexpr uint32 AirSupplies = 133532;
        static constexpr uint32 AirSupplyGroundDummy = 133542;

        static constexpr uint32 NathanosBlightCaller = 131773;
        static constexpr uint32 MathiasShaw = 130532;
        static constexpr uint32 AzeriteFissure = 125253;
    }

    namespace CommanderTexts
    {
        static constexpr uint8 Intro1 = 0;
        static constexpr uint8 Intro2 = 1;
        static constexpr uint8 Intro3 = 2;
        static constexpr uint8 Intro4 = 3;

        static constexpr uint8 SuppliesSpawned = 4;
        static constexpr uint8 CapturedAzerite = 5;
    }

    namespace GameObjects
    {
        static constexpr uint32 AllianceAirshipPrepCollision = 281224;
        static constexpr uint32 HordeAirshipPrepCollision = 281226;

        static constexpr uint32 BerserkBuff = 206564;
        static constexpr uint32 FoodBuff = 206565;
        static constexpr uint32 SpeedBuff = 206566;

        static constexpr std::array<uint32, 3> Buffs = { BerserkBuff, FoodBuff, SpeedBuff };
    }

    namespace PvpStats
    {
        static constexpr uint32 CapturedAzerite = 744;
    }

    namespace Sounds
    {
        static constexpr uint32 PvpFlagCapturedAlliance = 8173;
        static constexpr uint32 PvpFlagCapturedHorde = 8213;
    }

    namespace Spells
    {
        static constexpr uint32 ActivateAzerite = 248688;
        static constexpr uint32 AzeriteGeyser = 248668;
        static constexpr uint32 SummonAzeriteCaptureNode1 = 262749;
        static constexpr uint32 SummonAzeriteCaptureNode2 = 248674;
        static constexpr uint32 SummonAzeriteCaptureNode3 = 262748;
        static constexpr uint32 AzeriteKnockBack = 262385;
        static constexpr uint32 EarthQuakeCameraShake = 248719;
        static constexpr uint32 CapturedAllianceCosmeticFx = 262508;
        static constexpr uint32 CapturedHordeCosmeticFx = 262512;

        static constexpr uint32 AchievementCredit = 261968; // on capture azerite node
        static constexpr uint32 AchievementTrackerDeathFromAbove = 261954; // Death from Above achievement
        static constexpr uint32 AchievementCreditClaimJumper = 261953; // to cast when capturing an azerite node when less than 30s on ground
        static constexpr uint32 AchievementTrackerCreditClaimJumper = 261955;

        static constexpr uint32 RocketParachute = 250917;
        static constexpr uint32 RocketParachute2 = 250921;

        static constexpr uint32 NoFallingDamage = 262359;
        static constexpr uint32 Parachute = 269779;

        static constexpr std::array<uint32, 3> SummonAzeriteCaptureNodeSpells = { SummonAzeriteCaptureNode1, SummonAzeriteCaptureNode2, SummonAzeriteCaptureNode3 };

        static constexpr uint32 RopeBeam = 115048;
        static constexpr uint32 PingVehicle = 115050;

        static constexpr uint32 CreateHasteRuneBuffAreaTrigger = 295663;

        static constexpr uint32 DustCloudImpactBigger = 54740;
        static constexpr uint32 SpeedUp = 294701;
    }

    namespace SpellVisuals
    {
        static constexpr uint32 HasteRuneBuff = 85696;
        static constexpr uint32 AzeriteBirth = 74145;
    }

    namespace StringIds
    {
        static constexpr std::string_view AirSupplyGroundDummy1 = "air_supply_ground_dummy_1";
        static constexpr std::string_view AirSupplyGroundDummy2 = "air_supply_ground_dummy_2";
        static constexpr std::string_view AirSupplyGroundDummy3 = "air_supply_ground_dummy_3";
        static constexpr std::string_view AirSupplyGroundDummy4 = "air_supply_ground_dummy_4";
        static constexpr std::string_view AirSupplyGroundDummy5 = "air_supply_ground_dummy_5";
        static constexpr std::string_view AirSupplyGroundDummy6 = "air_supply_ground_dummy_6";

        static constexpr std::array<std::string_view, 6> AirSupplyGroundDummies = { AirSupplyGroundDummy1, AirSupplyGroundDummy2, AirSupplyGroundDummy3, AirSupplyGroundDummy4, AirSupplyGroundDummy5, AirSupplyGroundDummy6 };
    }

    namespace WorldStates
    {
        static constexpr uint32 AllianceScore = 13845;
        static constexpr uint32 HordeScore = 13844;
        static constexpr uint32 MaxScore = 13846;
    }

    namespace Texts
    {
        static constexpr uint32 AzeriteSpawning = 134097;
        static constexpr uint32 AllianceNearVictory = 10598;
        static constexpr uint32 HordeNearVictory = 10599;
    }
}

struct battleground_seething_shore final : BattlegroundScript
{
    static constexpr uint32 WARNING_NEAR_VICTORY_SCORE = 1200;
    static constexpr uint8 MAX_AZERITE_SPAWNS = 3;
    static constexpr uint8 MAX_BUFF_SPAWNS = 3;

    explicit battleground_seething_shore(BattlegroundMap* map) : BattlegroundScript(map), _firstSetDone(false)
    {
        _isInformedNearVictory = { false, false };
        _commanderGUIDs = { };
    }

    void OnUpdate(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void OnPrepareStage2() override
    {
        for (ObjectGuid const& guid : _commanderGUIDs)
            if (Creature const* creature = battlegroundMap->GetCreature(guid))
                creature->AI()->DoAction(SeethingShore::Actions::CommanderText1);
    }

    void OnPrepareStage3() override
    {
        _scheduler.Schedule(2s, [this](TaskContext context)
        {
            if (_activeAzeriteNodes.size() < MAX_AZERITE_SPAWNS)
            {
                SpawnAzeriteNodes();
                context.Repeat(100ms);
            }
            else
                context.Repeat(2s);
        });
    }

    void OnStart() override
    {
        for (ObjectGuid const& guid : _doors)
        {
            if (GameObject* gameObject = battlegroundMap->GetGameObject(guid))
            {
                gameObject->UseDoorOrButton();
                gameObject->DespawnOrUnsummon(3s);
            }
        }

        _scheduler.Schedule(30s, 2min, [this](TaskContext context)
        {
            SpawnBuffs();
            context.Repeat();
        });
    }

    void HandleAssaultPoint(GameObject* capturePoint, Player* player)
    {
        if (!player)
            return;

        capturePoint->SendCustomAnim(1);
        Team const team = battleground->GetPlayerTeam(player->GetGUID());
        TeamId const teamId = GetTeamIdForTeam(team);

        if (team == ALLIANCE)
        {
            battleground->PlaySoundToAll(SeethingShore::Sounds::PvpFlagCapturedAlliance);
            player->CastSpell(player, SeethingShore::Spells::CapturedAllianceCosmeticFx, true);
        }
        else if (team == HORDE)
        {
            battleground->PlaySoundToAll(SeethingShore::Sounds::PvpFlagCapturedHorde);
            player->CastSpell(player, SeethingShore::Spells::CapturedHordeCosmeticFx, true);
        }

        battleground->AddPoint(team, 100);
        UpdateWorldState(SeethingShore::WorldStates::AllianceScore, battleground->GetTeamScore(TEAM_ALLIANCE));
        UpdateWorldState(SeethingShore::WorldStates::HordeScore, battleground->GetTeamScore(TEAM_HORDE));
        player->CastSpell(player, SeethingShore::Spells::AchievementCredit, true);

        // the achievement criteria doesn't have a aura condition so we do it manually here
        if (player->HasAura(SeethingShore::Spells::AchievementTrackerCreditClaimJumper))
            player->CastSpell(player, SeethingShore::Spells::AchievementCreditClaimJumper, true);

        if (battleground->GetTeamScore(teamId) >= WARNING_NEAR_VICTORY_SCORE && _isInformedNearVictory[teamId])
        {
            _isInformedNearVictory[teamId] = true;
            if (teamId == TEAM_ALLIANCE)
                battleground->SendBroadcastText(SeethingShore::Texts::AllianceNearVictory, CHAT_MSG_BG_SYSTEM_NEUTRAL);
            else
                battleground->SendBroadcastText(SeethingShore::Texts::HordeNearVictory, CHAT_MSG_BG_SYSTEM_NEUTRAL);
        }

        battleground->UpdatePvpStat(player, SeethingShore::PvpStats::CapturedAzerite, 1);
        capturePoint->SetAnimKitId(2560, false);
        capturePoint->DespawnOrUnsummon(2s);

        _activeAzeriteNodes.erase(capturePoint->GetAreaId());

        if (Creature const* commander = battlegroundMap->GetCreature(_commanderGUIDs[teamId]))
            commander->AI()->DoAction(SeethingShore::Actions::CaptureAzeriteNode);

        if (team == HORDE && battleground->GetTeamScore(TEAM_HORDE) >= static_cast<uint32>(battlegroundMap->GetWorldStateValue(SeethingShore::WorldStates::MaxScore)))
            battleground->EndBattleground(HORDE);
        else if (team == ALLIANCE && battleground->GetTeamScore(TEAM_ALLIANCE) >= static_cast<uint32>(battlegroundMap->GetWorldStateValue(SeethingShore::WorldStates::MaxScore)))
            battleground->EndBattleground(ALLIANCE);
    }

    void OnCreatureCreate(Creature* creature) override
    {
        switch (creature->GetEntry())
        {
            case SeethingShore::Creatures::Controller:
                _controllerGUID = creature->GetGUID();
                break;
            case SeethingShore::Creatures::AirSupplyGroundDummy:
                _airSupplyGroundDummyGUIDs.emplace_back(creature->GetGUID());
                break;
            case SeethingShore::Creatures::NathanosBlightCaller:
                _commanderGUIDs[TEAM_HORDE] = creature->GetGUID();
                break;
            case SeethingShore::Creatures::MathiasShaw:
                _commanderGUIDs[TEAM_ALLIANCE] = creature->GetGUID();
                break;
            default:
                break;
        }
    }

    void OnGameObjectCreate(GameObject* gameobject) override
    {
        switch (gameobject->GetEntry())
        {
            case SeethingShore::GameObjects::AllianceAirshipPrepCollision:
            case SeethingShore::GameObjects::HordeAirshipPrepCollision:
                _doors.emplace_back(gameobject->GetGUID());
                break;
            default:
                break;
        }
    }

    void OnGameObjectRemove(GameObject* gameobject) override
    {
        switch (gameobject->GetEntry())
        {
            case SeethingShore::GameObjects::BerserkBuff:
            case SeethingShore::GameObjects::FoodBuff:
            case SeethingShore::GameObjects::SpeedBuff:
                DoAction(SeethingShore::Actions::ConsumeBuff, gameobject, nullptr);
                break;
            default:
                break;
        }
    }

    void DoAction(uint32 actionId, WorldObject* source, WorldObject* target) override
    {
        switch (actionId)
        {
            case SeethingShore::Actions::CaptureAzeriteNode:
                HandleAssaultPoint(WorldObject::ToGameObject(target), WorldObject::ToPlayer(source));
                break;
            case SeethingShore::Actions::ConsumeBuff:
                if (source)
                    if (Creature const* groundDummy = source->FindNearestCreature(SeethingShore::Creatures::AirSupplyGroundDummy, 20.0f))
                        _activeBuffs.erase(groundDummy->GetStringId(StringIdType::Spawn));
                break;
            default:
                break;
        }
    }

    void SpawnAzeriteNodes()
    {
        if (Creature* controller = battlegroundMap->GetCreature(_controllerGUID))
        {
            std::vector<uint32> targets = SelectAzeriteNodesToSpawn();

            CastSpellExtraArgs const args = CastSpellExtraArgs(true)
                .SetCustomArg(targets);
            controller->CastSpell(nullptr, SeethingShore::Spells::ActivateAzerite, args);
            _firstSetDone = true;

            for (uint32 const node : targets)
                _activeAzeriteNodes.insert(node);
        }

        battleground->SendBroadcastText(SeethingShore::Texts::AzeriteSpawning, CHAT_MSG_BG_SYSTEM_NEUTRAL);
        battlegroundMap->DoOnPlayers([&](Player* player)
        {
            player->CastSpell(player, SeethingShore::Spells::EarthQuakeCameraShake, true);
        });
    }

    std::vector<uint32> SelectAzeriteNodesToSpawn() const
    {
        if (!_firstSetDone)
        {
            return {
                SeethingShore::Areas::Ruins,
                SeethingShore::Areas::TarPits,
                SeethingShore::Areas::Ridge
            };
        }

        std::vector<uint32> selected;
        std::ranges::copy_if(SeethingShore::Areas::AzeriteNodes.begin(), SeethingShore::Areas::AzeriteNodes.end(), std::back_inserter(selected), [this](uint32 node)
        {
            return !_activeAzeriteNodes.contains(node);
        });

        uint32 const maxSpawns = MAX_AZERITE_SPAWNS - _activeAzeriteNodes.size();
        Trinity::Containers::RandomResize(selected, std::max<uint32>(maxSpawns, 0));
        return selected;
    }

    void SpawnBuffs()
    {
        std::vector<std::string_view> toSpawn = SelectBuffsToSpawn();
        if (toSpawn.empty())
            return;

        for (ObjectGuid const& guid : _commanderGUIDs)
            if (Creature const* creature = battlegroundMap->GetCreature(guid))
                creature->AI()->DoAction(SeethingShore::Actions::SpawnBuff);

        for (ObjectGuid const& guid : _airSupplyGroundDummyGUIDs)
        {
            if (Creature* creature = battlegroundMap->GetCreature(guid))
            {
                bool const isValid = std::ranges::any_of(toSpawn.begin(), toSpawn.end(), [&](std::string_view stringId)
                {
                    return creature->HasStringId(stringId);
                });

                if (!isValid)
                    continue;

                _activeBuffs.insert(creature->GetStringId(StringIdType::Spawn));
                creature->AI()->DoAction(SeethingShore::Actions::SpawnBuff);
            }
        }
    }

    std::vector<std::string_view> SelectBuffsToSpawn() const
    {
        std::vector<std::string_view> selected;
        std::ranges::copy_if(SeethingShore::StringIds::AirSupplyGroundDummies.begin(), SeethingShore::StringIds::AirSupplyGroundDummies.end(), std::back_inserter(selected), [this](std::string_view buff)
        {
            return !_activeBuffs.contains(buff);
        });

        uint32 const maxSpawns = MAX_BUFF_SPAWNS - _activeBuffs.size();
        Trinity::Containers::RandomResize(selected, std::max<uint32>(maxSpawns, 0));
        return selected;
    }

private:
    bool _firstSetDone;
    GuidVector _doors;

    TaskScheduler _scheduler;
    ObjectGuid _controllerGUID;
    std::array<bool, PVP_TEAMS_COUNT> _isInformedNearVictory;

    std::set<uint32> _activeAzeriteNodes;
    std::set<std::string_view> _activeBuffs;
    GuidVector _airSupplyGroundDummyGUIDs;
    std::array<ObjectGuid, PVP_TEAMS_COUNT> _commanderGUIDs;
};

// 248688 - Activate Azerite
class spell_bg_seething_shore_activate_azerite : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SeethingShore::Spells::AzeriteGeyser,
            SeethingShore::Spells::ActivateAzerite
        });
    }

    void FilterTargets(std::list<WorldObject*>& targets) const
    {
        std::vector<uint32> const* nodesToActivate = std::any_cast<std::vector<uint32>>(&GetSpell()->m_customArg);
        if (!nodesToActivate)
        {
            targets.clear();
            return;
        }

        auto itr = targets.begin();
        while (itr != targets.end())
        {
            Creature const* creature = (*itr)->ToCreature();
            if (!creature)
            {
                targets.erase(itr++);
                continue;
            }

            bool const shouldActivate = std::ranges::any_of(*nodesToActivate, [&creature](uint32 areaId)
            {
                return creature->GetAreaId() == areaId;
            });

            if (!shouldActivate)
                targets.erase(itr++);
            else
                ++itr;
        }
    }

    void HandleDummy(SpellEffIndex /*effIndex*/) const
    {
        GetHitCreature()->CastSpell(GetHitUnit(), SeethingShore::Spells::AzeriteGeyser, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_bg_seething_shore_activate_azerite::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectLaunchTarget += SpellEffectFn(spell_bg_seething_shore_activate_azerite::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 248668 - Azerite Geyser
class spell_bg_seething_shore_azerite_geyser : public AuraScript
{
    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        if (Unit* unitOwner = GetUnitOwner())
        {
            unitOwner->CastSpell(unitOwner, Trinity::Containers::SelectRandomContainerElement(SeethingShore::Spells::SummonAzeriteCaptureNodeSpells), true);
            unitOwner->CastSpell(unitOwner, SeethingShore::Spells::AzeriteKnockBack, true);
            unitOwner->GetMotionMaster()->MoveTargetedHome();
        }
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_bg_seething_shore_azerite_geyser::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 250917 - Rocket Parachute
class spell_bg_seething_shore_rocket_parachute_trigger : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SeethingShore::Spells::RocketParachute2
        });
    }

    void HandlePeriodic(AuraEffect const* /*auraEffect*/) const
    {
        CastSpellExtraArgs args;
        args.TriggerFlags = TRIGGERED_FULL_MASK;
        args.OriginalCastId = GetAura()->GetCastId();
        GetTarget()->CastSpell(GetTarget(), SeethingShore::Spells::RocketParachute2, args);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_bg_seething_shore_rocket_parachute_trigger::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 250921 - Rocket Parachute
class spell_bg_seething_shore_rocket_parachute_ground_check : public AuraScript
{
public:
    spell_bg_seething_shore_rocket_parachute_ground_check() : AuraScript(), _parachuteDeployed(false) { }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SeethingShore::Spells::Parachute
        });
    }

    void HandlePeriodicTrigger(AuraEffect const* /*auraEffect*/)
    {
        if (_parachuteDeployed)
            return;

        Unit* target = GetTarget();
        float const delta = target->GetPositionZ() - target->GetFloorZ();
        if (delta <= 30.0f)
        {
            SpellCastResult const castResult = target->CastSpell(target, SeethingShore::Spells::Parachute, true);
            _parachuteDeployed = castResult == SPELL_CAST_OK;
        }
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        // this should prevent next tick from re-applying this aura
        if (Unit* unitOwner = GetUnitOwner())
            unitOwner->RemoveAurasDueToSpell(SeethingShore::Spells::RocketParachute);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_bg_seething_shore_rocket_parachute_ground_check::HandlePeriodicTrigger, EFFECT_2, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        OnEffectRemove += AuraEffectRemoveFn(spell_bg_seething_shore_rocket_parachute_ground_check::HandleRemove, EFFECT_0, SPELL_AURA_CAN_TURN_WHILE_FALLING, AURA_EFFECT_HANDLE_REAL);
    }

private:
    bool _parachuteDeployed;
};

// 269779 - Parachute
class spell_bg_seething_shore_parachute : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_0 } })
            && ValidateSpellInfo(
                {
                    static_cast<uint32>(spellInfo->GetEffect(EFFECT_0).CalcValue()),
                    SeethingShore::Spells::AchievementTrackerCreditClaimJumper,
                    SeethingShore::Spells::AchievementTrackerDeathFromAbove
                });
    }

    void ApplyParachuteAura(SpellEffIndex /*effIndex*/) const
    {
        if (Player* player = GetHitPlayer())
        {
            CastSpellExtraArgs args;
            args.TriggerFlags = TRIGGERED_FULL_MASK;
            args.OriginalCastId = GetSpell()->m_castId;

            player->CastSpell(player, static_cast<uint32>(GetEffectInfo().CalcValue(player)), args);
            player->CastSpell(player, SeethingShore::Spells::AchievementTrackerCreditClaimJumper, true);
            player->CastSpell(player, SeethingShore::Spells::AchievementTrackerDeathFromAbove, true);
        }
    }

    void ResetFallDamage(SpellEffIndex /*effIndex*/) const
    {
        if (Player* player = GetHitPlayer())
            player->SetFallInformation(0, player->GetPositionZ());
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_bg_seething_shore_parachute::ApplyParachuteAura, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
        OnEffectHitTarget += SpellEffectFn(spell_bg_seething_shore_parachute::ResetFallDamage, EFFECT_1, SPELL_EFFECT_KNOCK_BACK);
    }
};

// 294701 - Speed Up
class spell_bg_seething_shore_speed_up : public SpellScript
{
    void ResetCooldowns(SpellEffIndex /*effIndex*/) const
    {
        // Unsure about which spells should reset and which not
        // It's not the same list as the ones that reset on encounter reset
        if (Player* player = GetCaster()->ToPlayer())
            player->GetSpellHistory()->ResetAllCooldowns();
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_bg_seething_shore_speed_up::ResetCooldowns, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 272471 - Azerite
// 281306 - Azerite
// 281307 - Azerite
struct go_bg_seething_shore_azerite : GameObjectAI
{
    explicit go_bg_seething_shore_azerite(GameObject* go) : GameObjectAI(go) { }

    bool OnCapturePointAssaulted(Player* player) override
    {
        if (me->GetGoState() != GO_STATE_READY || me->HasFlag(GO_FLAG_NOT_SELECTABLE))
            return true;

        if (ZoneScript* zoneScript = me->GetZoneScript())
        {
            zoneScript->DoAction(SeethingShore::Actions::CaptureAzeriteNode, player, me);
            return false;
        }

        return true;
    }
};

// 278407 - Sword of Dawn
// 279254 - The Warbringer
struct transport_seething_shore : TransportScript
{
    explicit transport_seething_shore() : TransportScript("transport_seething_shore") { }

    void OnRemovePassenger(Transport* /*transport*/, Player* player) override
    {
        if (Battleground const* bg = player->GetBattleground())
        {
            if (bg->GetStatus() != STATUS_IN_PROGRESS)
            {
                WorldSafeLocsEntry const* pos = bg->GetTeamStartPosition(Battleground::GetTeamIndexByTeamId(player->GetBGTeam()));
                player->TeleportTo({ .Location = pos->Loc, .TransportGuid = pos->TransportSpawnId ? ObjectGuid::Create<HighGuid::Transport>(*pos->TransportSpawnId) : ObjectGuid::Empty });
                return;
            }

            player->CastSpell(player, SeethingShore::Spells::RocketParachute, true);
            player->CastSpell(player, SeethingShore::Spells::NoFallingDamage, true);
        }
    }
};

// 133533 - Air Supplies
struct npc_bg_seething_shore_air_supplies_crate : ScriptedAI
{
    explicit npc_bg_seething_shore_air_supplies_crate(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        DoCastAOE(SeethingShore::Spells::RopeBeam);
        DoCastAOE(SeethingShore::Spells::PingVehicle);
    }
};

struct AirSupplyData
{
    Position Spawn;
    Position Destination;
};

// 133542 - Air Supply Ground Dummy
struct npc_bg_seething_shore_air_supply_ground_dummy : ScriptedAI
{
    explicit npc_bg_seething_shore_air_supply_ground_dummy(Creature* creature) : ScriptedAI(creature) { }

    static constexpr uint32 PATH_ID_GROUND = 1;

    static WaypointPath ConvertPosToPath(Position const& position)
    {
        return {
            PATH_ID_GROUND,
            {
                { 0, position.GetPositionX(), position.GetPositionY(), position.GetPositionZ() }
            },
            WaypointMoveType::Run,
            WaypointPathFlags::FlyingPath
        };
    }

    static inline const std::unordered_map<std::string_view, AirSupplyData> AIR_SUPPLY_DATA =
    {
        { SeethingShore::StringIds::AirSupplyGroundDummy1, { { 1398.8298f, 2727.5322f, 121.74067f, 1.789716362953186035f }, { 1398.7153f, 2728.0469f, 28.024399f } } },
        { SeethingShore::StringIds::AirSupplyGroundDummy2, { { 1226.2812f, 2934.0356f, 152.03821f, 2.737864494323730468f }, { 1224.4445f, 2934.8203f, 72.7618f } } },
        { SeethingShore::StringIds::AirSupplyGroundDummy3, { { 1226.276f, 2826.9246f, 145.53375f,5.083248138427734375f }, { 1226.9896f, 2825.0894f, 39.256886f } } },
        { SeethingShore::StringIds::AirSupplyGroundDummy4, { { 1384.7483f, 2847.356f, 113.422775f, 2.29029250144958496f }, { 1384.2257f, 2847.9524f, 38.665867f } } },
        { SeethingShore::StringIds::AirSupplyGroundDummy5, { { 1323.1545f, 2627.9531f, 99.90129f, 3.868808984756469726f }, { 1322.7587f, 2627.6008f, 0.9027778f } } },
        { SeethingShore::StringIds::AirSupplyGroundDummy6, { { 1423.8021f, 2870.2188f, 115.70237f, 1.629547119140625f }, { 1423.7188f, 2871.6362f, 36.968292f } } }
    };

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void SpawnAirSupplyParachute() const
    {
        std::string_view const stringId = me->GetStringId(StringIdType::Spawn);
        if (!AIR_SUPPLY_DATA.contains(stringId))
            return;

        auto const& [spawn, destination] = AIR_SUPPLY_DATA.at(stringId);
        if (TempSummon* supplies = me->GetMap()->SummonCreature(SeethingShore::Creatures::AirSupplies, spawn))
            supplies->GetMotionMaster()->MovePath(ConvertPosToPath(destination), false);
    }

    void DoAction(int32 actionId) override
    {
        if (actionId == SeethingShore::Actions::SpawnBuff)
        {
            _scheduler.Schedule(5s, [&](TaskContext)
            {
                SpawnAirSupplyParachute();
            });
        }
    }

private:
    TaskScheduler _scheduler;
};

// 133532 - Air Supplies
struct npc_bg_seething_shore_air_supplies_drop : ScriptedAI
{
    explicit npc_bg_seething_shore_air_supplies_drop(Creature* creature) : ScriptedAI(creature) { }

    void WaypointPathEnded(uint32 /*pointId*/, uint32 pathId) override
    {
        if (pathId != npc_bg_seething_shore_air_supply_ground_dummy::PATH_ID_GROUND)
            return;

        Creature* groundDummy = me->FindNearestCreature(SeethingShore::Creatures::AirSupplyGroundDummy, 20.0f);
        if (!groundDummy)
            return;

        QuaternionData const rot = QuaternionData::fromEulerAnglesZYX(groundDummy->GetOrientation(), 0.f, 0.f);
        uint8 const action = urand(0, 3);
        switch (action)
        {
            case 0:
            case 1:
            case 2:
                // pretty sure some serverside spell is used, and we could drop this whole switch
                if (GameObject* buff = GameObject::CreateGameObject(SeethingShore::GameObjects::Buffs[action], groundDummy->GetMap(), groundDummy->GetPosition(), rot, 255, GO_STATE_READY))
                {
                    buff->SetSpawnedByDefault(false);
                    buff->SetRespawnTime(300); // this is equal to the haste rune buff area trigger
                    groundDummy->GetMap()->AddToMap(buff);
                }
                break;
            case 3:
                groundDummy->CastSpell(groundDummy, SeethingShore::Spells::CreateHasteRuneBuffAreaTrigger, true);
                break;
            default:
                break;
        }

        groundDummy->CastSpell(nullptr, SeethingShore::Spells::DustCloudImpactBigger, true);
        me->DespawnOrUnsummon();
    }
};

struct at_bg_seething_shore_haste_rune_buff : AreaTriggerAI
{
    explicit at_bg_seething_shore_haste_rune_buff(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnCreate(Spell const* /*creatingSpell*/) override
    {
        at->PlaySpellVisual(SeethingShore::SpellVisuals::HasteRuneBuff);
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (Player* player = unit->ToPlayer())
        {
            if (ZoneScript* zonescript = at->GetZoneScript())
            {
                player->CastSpell(player, SeethingShore::Spells::SpeedUp, true);
                zonescript->DoAction(SeethingShore::Actions::ConsumeBuff, at);
                at->Remove();
            }
        }
    }
};

// 131773 - Nathanos Blightcaller
// 130532 - Master Mathias Shaw
struct npc_bg_seething_shore_commander : ScriptedAI
{
    explicit npc_bg_seething_shore_commander(Creature* creature) : ScriptedAI(creature) { }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void DoAction(int32 actionId) override
    {
        switch (actionId)
        {
            case SeethingShore::Actions::CommanderText1:
                Talk(SeethingShore::CommanderTexts::Intro1);
                _scheduler.Schedule(30s, [this](TaskContext context)
                {
                    Talk(SeethingShore::CommanderTexts::Intro2);
                    context.Schedule(15s, [this](TaskContext context2)
                    {
                        Talk(SeethingShore::CommanderTexts::Intro3);
                        context2.Schedule(12s, [this](TaskContext)
                        {
                            Talk(SeethingShore::CommanderTexts::Intro4);
                        });
                    });
                });
                break;
            case SeethingShore::Actions::CaptureAzeriteNode:
                if (urand(0, 1))
                    Talk(SeethingShore::CommanderTexts::CapturedAzerite);
                break;
            case SeethingShore::Actions::SpawnBuff:
                Talk(SeethingShore::CommanderTexts::SuppliesSpawned);
                break;
            default:
                break;
        }
    }

private:
    TaskScheduler _scheduler;
};

// 129344 - Vignette Dummy
struct npc_bg_seething_shore_vignette_dummy : ScriptedAI
{
    explicit npc_bg_seething_shore_vignette_dummy(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        _scheduler.Schedule(38s, [this](TaskContext)
        {
            if (Creature* fissure = me->FindNearestCreature(SeethingShore::Creatures::AzeriteFissure, 5.0f))
                me->SendPlaySpellVisual(fissure, SeethingShore::SpellVisuals::AzeriteBirth, 0, 0, 0.0f);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

void AddSC_battleground_seething_shore()
{
    RegisterBattlegroundMapScript(battleground_seething_shore, 1803);
    RegisterSpellScript(spell_bg_seething_shore_activate_azerite);
    RegisterSpellScript(spell_bg_seething_shore_azerite_geyser);
    RegisterGameObjectAI(go_bg_seething_shore_azerite);

    RegisterSpellScript(spell_bg_seething_shore_rocket_parachute_trigger);
    RegisterSpellScript(spell_bg_seething_shore_rocket_parachute_ground_check);
    RegisterSpellScript(spell_bg_seething_shore_parachute);

    RegisterCreatureAI(npc_bg_seething_shore_air_supplies_crate);
    RegisterCreatureAI(npc_bg_seething_shore_air_supply_ground_dummy);

    RegisterAreaTriggerAI(at_bg_seething_shore_haste_rune_buff);
    RegisterCreatureAI(npc_bg_seething_shore_air_supplies_drop);
    RegisterCreatureAI(npc_bg_seething_shore_commander);

    RegisterSpellScript(spell_bg_seething_shore_speed_up);

    RegisterCreatureAI(npc_bg_seething_shore_vignette_dummy);

    new transport_seething_shore();
}
