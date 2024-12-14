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
#include "BattlegroundScript.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "ObjectGuid.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "TaskScheduler.h"
#include "WorldStateMgr.h"

namespace TempleOfKotmogu
{
    namespace Achievements
    {
        static constexpr uint32 Powerball = 6950;
    }

    namespace Actions
    {
        static constexpr uint32 CheckScore = 1;
        static constexpr uint32 ConsumeAreaTrigger = 2;
    }

    namespace AreaTriggerCreateProperties
    {
        static constexpr uint32 PvpRuneRejuv = 86;
    }

    namespace BroadcastTexts
    {
        static constexpr uint32 BlueOrbTaken = 62279;
        static constexpr uint32 OrangeOrbTaken = 62280;
        static constexpr uint32 GreenOrbTaken = 62281;
        static constexpr uint32 PurpleOrbTaken = 62282;
    }

    namespace Creatures
    {
        static constexpr uint32 Trigger = 58951; // used for sounds, texts, etc.
    }

    namespace CreatureTexts::Trigger
    {
        static constexpr uint8 OrangeOrbReturned = 0;
        static constexpr uint8 BlueOrbReturned = 1;
        static constexpr uint8 PurpleOrbReturned = 2;
        static constexpr uint8 GreenOrbReturned = 3;
    }

    namespace GameObjects
    {
        static constexpr uint32 GreatWall = 215760;
        static constexpr uint32 Collision = 215787;

        static constexpr uint32 OrbOfPowerBlue = 212091;
        static constexpr uint32 OrbOfPowerPurple = 212092;
        static constexpr uint32 OrbOfPowerGreen = 212093;
        static constexpr uint32 OrbOfPowerOrange = 212094;
    }

    namespace Positions
    {
        static constexpr std::array<Position, 4> HealingBuffs
        {{
            { 1868.2396f, 1391.1198f, 11.52903f, 6.2601f },
            { 1697.9149f, 1275.7673f, 12.16028f, 3.1154f },
            { 1698.4271f, 1391.7951f, 11.75756f, 3.1675f },
            { 1867.8836f, 1274.8872f, 11.85079f, 0.0331f }
        }};

        static constexpr Position PurpleOrb = { 1850.2170f, 1416.8229f, 13.3382f };
        static constexpr Position GreenOrb = { 1716.8923f, 1416.6180f, 13.2056f};
        static constexpr Position BlueOrb = { 1716.9479f, 1250.0173f, 13.3266f};
        static constexpr Position OrangeOrb = { 1850.1666f, 1250.1180f, 13.2056f};
    }

    namespace PvpStats
    {
        static constexpr uint32 OrbPossessions = 418;
        static constexpr uint32 VictoryPoints = 419;
    }

    namespace SoundKits
    {
        static constexpr uint32 PVPFlagTakenAlliance = 8174;
    }

    namespace Spells
    {
        static constexpr uint32 PowerOrbScalePeriodic = 127163;
        static constexpr uint32 PowerOrbImmunityPeriodic = 116524; // also used for achievement to check if player has power orb (Blackout, can't stop won't stop)
        static constexpr uint32 Plus3VictoryPoints = 112912; // adds 2 victory points (not a typo)
        static constexpr uint32 Plus4VictoryPoints = 112913; // adds 4 victory points
        static constexpr uint32 Plus5VictoryPoints = 112914; // adds 6 victory points (not a typo)

        static constexpr uint32 SmallAura = 112052;
        static constexpr uint32 MediumAura = 112053;
        static constexpr uint32 LargeAura = 112054;

        // Achievement Powerball
        // Hold an Orb of Power in the center of the Temple of Kotmogu for 90 seconds.
        static constexpr uint32 PowerballCredit = 128768; // serverside spell

        static constexpr uint32 HordeInsigniaVisual = 131528;
        static constexpr uint32 AllianceInsigniaVisual = 131527;
        static constexpr uint32 Restoration = 294564;
    }

    namespace WorldStates
    {
        static constexpr int32 MaxPoints = 17388;
        static constexpr int32 AlliancePoints = 6303;
        static constexpr int32 HordePoints = 6304;

        static constexpr int32 BlueOrbInBase = 6714;
        static constexpr int32 BlueOrbHorde = 6969;
        static constexpr int32 BlueOrbAlliance = 6970;

        static constexpr int32 OrangeOrbInBase = 6717;
        static constexpr int32 OrangeOrbHorde = 6963;
        static constexpr int32 OrangeOrbAlliance = 6964;

        static constexpr int32 PurpleOrbInBase = 6715;
        static constexpr int32 PurpleOrbHorde = 6967;
        static constexpr int32 PurpleOrbAlliance = 6968;

        static constexpr int32 GreenOrbInBase = 6716;
        static constexpr int32 GreenOrbHorde = 6965;
        static constexpr int32 GreenOrbAlliance = 6966;
    }

    struct StaticOrbData
    {
        constexpr StaticOrbData(Position spawnPosition, uint32 entry, uint32 broadcastText, uint8 triggerText, int32 worldStateInBase, int32 worldStateHorde, int32 worldStateAlliance) :
            SpawnPosition(spawnPosition), Entry(entry), BroadcastText(broadcastText), TriggerText(triggerText), WorldStateInBase(worldStateInBase), WorldStateHorde(worldStateHorde), WorldStateAlliance(worldStateAlliance)
        {
        }

        Position SpawnPosition;
        uint32 Entry;
        uint32 BroadcastText; // when picked up
        uint8 TriggerText; // when dropped, not a broadcast text but group from creature_text
        int32 WorldStateInBase;
        int32 WorldStateHorde;
        int32 WorldStateAlliance;
    };

    namespace StaticOrbDataValue
    {
        static constexpr StaticOrbData OrangeOrb = {
            Positions::OrangeOrb,
            GameObjects::OrbOfPowerOrange,
            BroadcastTexts::OrangeOrbTaken,
            CreatureTexts::Trigger::OrangeOrbReturned,
            WorldStates::OrangeOrbInBase,
            WorldStates::OrangeOrbHorde,
            WorldStates::OrangeOrbAlliance
        };
        static constexpr StaticOrbData BlueOrb = {
            Positions::BlueOrb,
            GameObjects::OrbOfPowerBlue,
            BroadcastTexts::BlueOrbTaken,
            CreatureTexts::Trigger::BlueOrbReturned,
            WorldStates::BlueOrbInBase,
            WorldStates::BlueOrbHorde,
            WorldStates::BlueOrbAlliance
        };
        static constexpr StaticOrbData GreenOrb = {
            Positions::GreenOrb,
            GameObjects::OrbOfPowerGreen,
            BroadcastTexts::GreenOrbTaken,
            CreatureTexts::Trigger::GreenOrbReturned,
            WorldStates::GreenOrbInBase,
            WorldStates::GreenOrbHorde,
            WorldStates::GreenOrbAlliance
        };
        static constexpr StaticOrbData PurpleOrb = {
            Positions::PurpleOrb,
            GameObjects::OrbOfPowerPurple,
            BroadcastTexts::PurpleOrbTaken,
            CreatureTexts::Trigger::PurpleOrbReturned,
            WorldStates::PurpleOrbInBase,
            WorldStates::PurpleOrbHorde,
            WorldStates::PurpleOrbAlliance
        };

        static constexpr std::array<StaticOrbData, 4> Orbs =
        {
            OrangeOrb,
            BlueOrb,
            GreenOrb,
            PurpleOrb
        };
    }
}

struct battleground_temple_of_kotmogu final : BattlegroundScript
{
    explicit battleground_temple_of_kotmogu(BattlegroundMap* map) : BattlegroundScript(map),
        _healingBuffs({ })
    {
    }

    void OnInit() override
    {
        for (TempleOfKotmogu::StaticOrbData const& data : TempleOfKotmogu::StaticOrbDataValue::Orbs)
            SpawnOrb(&data);
    }

    void OnUpdate(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void OnPrepareStage3() override
    {
        _scheduler.Schedule(24s, [&](TaskContext)
        {
            for (ObjectGuid const& door : _walls)
                if (GameObject* gameObject = battlegroundMap->GetGameObject(door))
                    gameObject->UseDoorOrButton();
        });
    }

    void OnStart() override
    {
        for (ObjectGuid const& door : _collisions)
            if (GameObject* gameObject = battlegroundMap->GetGameObject(door))
                gameObject->UseDoorOrButton();

        _scheduler.Schedule(5s, [&](TaskContext context)
        {
            for (ObjectGuid const& guid : _orbHolders)
            {
                if (Player* player = ObjectAccessor::FindPlayer(guid))
                {
                    if (player->HasAura(TempleOfKotmogu::Spells::SmallAura))
                        player->CastSpell(player, TempleOfKotmogu::Spells::Plus5VictoryPoints, true);
                    else if (player->HasAura(TempleOfKotmogu::Spells::MediumAura))
                        player->CastSpell(player, TempleOfKotmogu::Spells::Plus4VictoryPoints, true);
                    else if (player->HasAura(TempleOfKotmogu::Spells::LargeAura))
                        player->CastSpell(player, TempleOfKotmogu::Spells::Plus3VictoryPoints, true);
                }
            }

            bool const winner = CheckWinner();
            if (!winner)
                context.Repeat();
        });
    }

    void OnGameObjectCreate(GameObject* gameobject) override
    {
        switch (gameobject->GetEntry())
        {
            case TempleOfKotmogu::GameObjects::GreatWall:
                _walls.emplace_back(gameobject->GetGUID());
                break;
            case TempleOfKotmogu::GameObjects::Collision:
                _collisions.emplace_back(gameobject->GetGUID());
                break;
            default:
                break;
        }
    }

    void OnCreatureCreate(Creature* creature) override
    {
        switch (creature->GetEntry())
        {
            case TempleOfKotmogu::Creatures::Trigger:
                _triggerGuid = creature->GetGUID();
                for (std::size_t i = 0; i < TempleOfKotmogu::Positions::HealingBuffs.size(); i++)
                    SpawnHealingBuff(i);
                break;
            default:
                break;
        }
    }

    void OnFlagTaken(GameObject* flag, Player* player) override
    {
        battleground->UpdatePvpStat(player, TempleOfKotmogu::PvpStats::OrbPossessions, 1);
        player->CastSpell(player, TempleOfKotmogu::Spells::PowerOrbScalePeriodic, true);
        player->CastSpell(player, TempleOfKotmogu::Spells::PowerOrbImmunityPeriodic, true);

        Team const team = player->GetBGTeam();

        ChatMsg chatMsg = CHAT_MSG_BG_SYSTEM_NEUTRAL;

        if (team == HORDE)
        {
            player->CastSpell(player, TempleOfKotmogu::Spells::HordeInsigniaVisual, true);
            chatMsg = CHAT_MSG_BG_SYSTEM_HORDE;
        }
        else if (team == ALLIANCE)
        {
            player->CastSpell(player, TempleOfKotmogu::Spells::AllianceInsigniaVisual, true);
            chatMsg = CHAT_MSG_BG_SYSTEM_ALLIANCE;
        }

        TempleOfKotmogu::StaticOrbData const* orbData = GetOrbData(flag->GetEntry());
        if (!orbData)
            return;

        UpdateWorldState(orbData->WorldStateInBase, 0);
        UpdateWorldState(orbData->WorldStateAlliance, team == ALLIANCE);
        UpdateWorldState(orbData->WorldStateHorde, team == HORDE);
        battleground->SendBroadcastText(orbData->BroadcastText, chatMsg, player);
        battleground->PlaySoundToAll(TempleOfKotmogu::SoundKits::PVPFlagTakenAlliance);

        _orbHolders.insert(player->GetGUID());
        battlegroundMap->UpdateSpawnGroupConditions();
    }

    void OnFlagDropped(ObjectGuid const& flagGuid, Player* player) override
    {
        if (!flagGuid.IsGameObject())
            return;

        player->RemoveAurasDueToSpell(TempleOfKotmogu::Spells::PowerOrbScalePeriodic);
        player->RemoveAurasDueToSpell(TempleOfKotmogu::Spells::PowerOrbImmunityPeriodic);
        _orbHolders.erase(player->GetGUID());

        TempleOfKotmogu::StaticOrbData const* orbData = GetOrbData(flagGuid.GetEntry());
        if (!orbData)
            return;

        UpdateWorldState(orbData->WorldStateInBase, 1);
        UpdateWorldState(orbData->WorldStateAlliance, 0);
        UpdateWorldState(orbData->WorldStateHorde, 0);
        SpawnOrb(orbData);
        battlegroundMap->UpdateSpawnGroupConditions();

        if (Creature const* trigger = battlegroundMap->GetCreature(_triggerGuid))
            trigger->AI()->Talk(orbData->TriggerText, player);
    }

    void DoAction(uint32 actionId, WorldObject* source, WorldObject* target) override
    {
        switch (actionId)
        {
            case TempleOfKotmogu::Actions::CheckScore:
                // ReSharper disable once CppExpressionWithoutSideEffects
                CheckWinner();
                break;
            case TempleOfKotmogu::Actions::ConsumeAreaTrigger:
                HandleConsumeAreaTrigger(Object::ToAreaTrigger(source), Object::ToPlayer(target));
                break;
            default:
                break;
        }
    }

    void HandleConsumeAreaTrigger(AreaTrigger* trigger, Player* player)
    {
        // find index
        std::size_t index = 0;
        for (std::size_t i = 0; i < _healingBuffs.size(); i++)
        {
            if (_healingBuffs[i] == trigger->GetGUID())
            {
                index = i;
                break;
            }
        }

        player->CastSpell(player, TempleOfKotmogu::Spells::Restoration, true);
        trigger->Remove();

        _scheduler.Schedule(90s, [&, index](TaskContext)
        {
            SpawnHealingBuff(index);
        });
    }

    bool CheckWinner() const
    {
        uint32 const maxScore = sWorldStateMgr->GetValue(TempleOfKotmogu::WorldStates::MaxPoints, battlegroundMap);
        if (battleground->GetTeamScore(TEAM_HORDE) == maxScore && battleground->GetTeamScore(TEAM_ALLIANCE) == maxScore)
        {
            UpdateWorldState(TempleOfKotmogu::WorldStates::AlliancePoints, maxScore);
            UpdateWorldState(TempleOfKotmogu::WorldStates::HordePoints, maxScore);
            battleground->EndBattleground(TEAM_OTHER);
            return true;
        }

        if (battleground->GetTeamScore(TEAM_HORDE) == maxScore)
        {
            UpdateWorldState(TempleOfKotmogu::WorldStates::HordePoints, maxScore);
            battleground->EndBattleground(HORDE);
            return true;
        }

        if (battleground->GetTeamScore(TEAM_ALLIANCE) == maxScore)
        {
            UpdateWorldState(TempleOfKotmogu::WorldStates::AlliancePoints, maxScore);
            battleground->EndBattleground(ALLIANCE);
            return true;
        }

        return false;
    }

    void SpawnHealingBuff(std::size_t index)
    {
        if (Creature* creature = battlegroundMap->GetCreature(_triggerGuid))
            if (AreaTrigger const* trigger = AreaTrigger::CreateAreaTrigger({ TempleOfKotmogu::AreaTriggerCreateProperties::PvpRuneRejuv, true }, TempleOfKotmogu::Positions::HealingBuffs[index], -1, creature, nullptr))
                _healingBuffs[index] = trigger->GetGUID();
    }

    static constexpr TempleOfKotmogu::StaticOrbData const* GetOrbData(uint32 orbEntry)
    {
        switch (orbEntry)
        {
            case TempleOfKotmogu::GameObjects::OrbOfPowerBlue:
                return &TempleOfKotmogu::StaticOrbDataValue::BlueOrb;
            case TempleOfKotmogu::GameObjects::OrbOfPowerGreen:
                return &TempleOfKotmogu::StaticOrbDataValue::GreenOrb;
            case TempleOfKotmogu::GameObjects::OrbOfPowerOrange:
                return &TempleOfKotmogu::StaticOrbDataValue::OrangeOrb;
            case TempleOfKotmogu::GameObjects::OrbOfPowerPurple:
                return &TempleOfKotmogu::StaticOrbDataValue::PurpleOrb;
            default:
                return nullptr;
        }
    }

    void SpawnOrb(TempleOfKotmogu::StaticOrbData const* orbData) const
    {
        if (GameObject* orb = GameObject::CreateGameObject(orbData->Entry, battlegroundMap, orbData->SpawnPosition, QuaternionData::fromEulerAnglesZYX(orbData->SpawnPosition.GetOrientation(), 0.f, 0.f), 255, GO_STATE_READY))
        {
            orb->SetSpawnedByDefault(false);
            orb->SetRespawnTime(7200);
            battlegroundMap->AddToMap(orb);
        }
    }

private:
    TaskScheduler _scheduler;
    GuidVector _walls;
    GuidVector _collisions;
    GuidSet _orbHolders;
    ObjectGuid _triggerGuid;

    std::array<ObjectGuid, 4> _healingBuffs;
};

// 127163 - Power Orb
class spell_bg_temple_of_kotmogu_power_orb_scale_periodic : public AuraScript
{
    void HandlePeriodic(AuraEffect const* /*aurEff*/) const
    {
        if (AuraEffect* effect = GetAura()->GetEffect(EFFECT_0))
            effect->ChangeAmount(effect->GetAmount() + effect->GetSpellEffectInfo().CalcValue());
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_bg_temple_of_kotmogu_power_orb_scale_periodic::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 121164 - Orb of Power
// 121175 - Orb of Power
// 121176 - Orb of Power
// 121177 - Orb of Power
class spell_bg_temple_of_kotmogu_orb_of_power_periodic : public AuraScript
{
    void UpdateEffectIndexAmount(uint32 index) const
    {
        if (AuraEffect* effect = GetAura()->GetEffect(index))
            effect->ChangeAmount(effect->GetAmount() + effect->GetSpellEffectInfo().CalcValue());
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/) const
    {
        UpdateEffectIndexAmount(EFFECT_0);
        UpdateEffectIndexAmount(EFFECT_1);
        UpdateEffectIndexAmount(EFFECT_2);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_bg_temple_of_kotmogu_orb_of_power_periodic::HandlePeriodic, EFFECT_3, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 112912 - +3 Victory Points!
// 112913 - +4 Victory Points!
// 112914 - +5 Victory Points!
// 112910 - +10 Victory Points!
template<int32 Points>
class spell_bg_temple_of_kotmogu_victory_points_periodic : public SpellScript
{
public:
    virtual void OnHit(SpellEffIndex /*effIndex*/) const
    {
        Player* player = GetHitPlayer();
        if (!player)
            return;

        Battleground* bg = player->GetBattleground();
        if (!bg)
            return;

        uint32 const maxScore = sWorldStateMgr->GetValue(TempleOfKotmogu::WorldStates::MaxPoints, player->GetMap());
        bg->UpdatePvpStat(player, TempleOfKotmogu::PvpStats::VictoryPoints, Points);
        Team const team = player->GetBGTeam();
        uint32 const score = bg->GetTeamScore(GetTeamIdForTeam(team));

        int32 const amount = std::min(maxScore, score + Points);
        bg->SetTeamPoint(team, amount);
        sWorldStateMgr->SetValue(TempleOfKotmogu::WorldStates::AlliancePoints, bg->GetTeamScore(TEAM_ALLIANCE), false, player->GetMap());
        sWorldStateMgr->SetValue(TempleOfKotmogu::WorldStates::HordePoints, bg->GetTeamScore(TEAM_HORDE), false, player->GetMap());
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_bg_temple_of_kotmogu_victory_points_periodic::OnHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 112910 - +10 Victory Points!
template<int32 Points>
class spell_bg_temple_of_kotmogu_victory_points_kill : public spell_bg_temple_of_kotmogu_victory_points_periodic<Points>
{
    void OnHit(SpellEffIndex effIndex) const override
    {
        spell_bg_temple_of_kotmogu_victory_points_periodic<Points>::OnHit(effIndex);
        Player* player = SpellScript::GetHitPlayer();
        if (!player)
            return;

        if (ZoneScript* zonescript = player->FindZoneScript())
            zonescript->DoAction(TempleOfKotmogu::Actions::CheckScore, player, player);
    }

    void Register() override
    {
        SpellScript::OnEffectHitTarget += SpellScript::SpellEffectFn(spell_bg_temple_of_kotmogu_victory_points_kill::OnHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

struct at_bg_temple_of_kotmogu_healing_buff : AreaTriggerAI
{
    explicit at_bg_temple_of_kotmogu_healing_buff(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (Player* player = unit->ToPlayer())
            if (ZoneScript* zonescript = at->GetZoneScript())
                zonescript->DoAction(TempleOfKotmogu::Actions::ConsumeAreaTrigger, at, player);
    }
};

struct at_bg_temple_of_kotmogu_small_area : AreaTriggerAI
{
    explicit at_bg_temple_of_kotmogu_small_area(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (Player* player = unit->ToPlayer())
        {
            if (!_totalTimeInAreaWithOrb.contains(player->GetGUID()))
                _totalTimeInAreaWithOrb[player->GetGUID()] = 0;

            player->CastSpell(player, TempleOfKotmogu::Spells::SmallAura, true);
        }
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAurasDueToSpell(TempleOfKotmogu::Spells::SmallAura);
    }

    void OnUpdate(uint32 diff) override
    {
        for (ObjectGuid const& guid : at->GetInsideUnits())
        {
            if (Player* player = ObjectAccessor::FindPlayer(guid))
            {
                if (player->HasAura(TempleOfKotmogu::Spells::PowerOrbImmunityPeriodic))
                {
                    _totalTimeInAreaWithOrb[player->GetGUID()] += diff;
                    if (_totalTimeInAreaWithOrb[player->GetGUID()] >= 90000 && !player->HasAchieved(TempleOfKotmogu::Achievements::Powerball))
                        player->CastSpell(player, TempleOfKotmogu::Spells::PowerballCredit, true);
                }
            }
        }
    }

private:
    std::unordered_map<ObjectGuid, uint32 /*milliseconds*/> _totalTimeInAreaWithOrb;
};

struct at_bg_temple_of_kotmogu_medium_area : AreaTriggerAI
{
    explicit at_bg_temple_of_kotmogu_medium_area(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (Player* player = unit->ToPlayer())
            player->CastSpell(player, TempleOfKotmogu::Spells::MediumAura, true);
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAurasDueToSpell(TempleOfKotmogu::Spells::MediumAura);
    }
};

void AddSC_battleground_temple_of_kotmogu()
{
    RegisterBattlegroundMapScript(battleground_temple_of_kotmogu, 998);

    RegisterSpellScript(spell_bg_temple_of_kotmogu_power_orb_scale_periodic);
    RegisterSpellScript(spell_bg_temple_of_kotmogu_orb_of_power_periodic);
    RegisterSpellScriptWithArgs(spell_bg_temple_of_kotmogu_victory_points_periodic<2>, "spell_bg_temple_of_kotmogu_victory_points_periodic_2_points");
    RegisterSpellScriptWithArgs(spell_bg_temple_of_kotmogu_victory_points_periodic<4>, "spell_bg_temple_of_kotmogu_victory_points_periodic_4_points");
    RegisterSpellScriptWithArgs(spell_bg_temple_of_kotmogu_victory_points_periodic<6>, "spell_bg_temple_of_kotmogu_victory_points_periodic_6_points");
    RegisterSpellScriptWithArgs(spell_bg_temple_of_kotmogu_victory_points_kill<10>, "spell_bg_temple_of_kotmogu_victory_points_kill");
    RegisterAreaTriggerAI(at_bg_temple_of_kotmogu_healing_buff);
    RegisterAreaTriggerAI(at_bg_temple_of_kotmogu_small_area);
    RegisterAreaTriggerAI(at_bg_temple_of_kotmogu_medium_area);
}
