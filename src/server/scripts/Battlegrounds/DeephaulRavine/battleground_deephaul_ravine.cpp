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
#include "GameObject.h"
#include "Language.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "TaskScheduler.h"
#include "TemporarySummon.h"
#include "Vehicle.h"

namespace DeephaulRavine
{
    namespace Actions
    {
        static constexpr uint32 CaptureMineCart = 1;
        static constexpr uint32 ConsumeBuff = 2;
        static constexpr uint32 AllianceCartAppearedInitial = 3;
        static constexpr uint32 HordeCartAppearedInitial = 4;
        static constexpr uint32 CommanderStartIntro = 5;
    }

    namespace AreaTriggers
    {
        static constexpr uint32 CapturePointAlliance = 30;
        static constexpr uint32 CapturePointHorde = 31;

        static constexpr uint32 RuneOfFrequency = 33926;
        static constexpr uint32 BerserkerBuff = 21077;
        static constexpr uint32 HealingBuff = 21076;
    }

    namespace BroadcastTexts
    {
        static constexpr uint32 CrystalCapturedAlliance = 18375;
        static constexpr uint32 CrystalCapturedHorde = 18384;

        static constexpr uint32 AllianceControlMineCart = 60441; // copied from Silvershard Mines
        static constexpr uint32 HordeControlMineCart = 60442; // copied from Silvershard Mines

        static constexpr uint32 AllianceCaptureMineCart = 59689; // copied from Silvershard Mines
        static constexpr uint32 HordeCaptureMineCart = 59690; // copied from Silvershard Mines

        static constexpr uint32 FlagDropped = 18361;
    }

    namespace Creatures
    {
        static constexpr uint32 MineCartEast = 214690;
        static constexpr uint32 MineCartWest = 217346;
        static constexpr uint32 GenericBunny = 214731;

        static constexpr uint32 ForemanUzjax = 224086;
        static constexpr uint32 Ruffious = 224087;

        static constexpr uint32 EarthenMineCartHorde = 211155;
        static constexpr uint32 EarthenMineCartAlliance = 211271;
    }

    namespace CreatureTexts
    {
        static constexpr uint8 Intro1 = 0;
        static constexpr uint8 Intro2 = 1;
        static constexpr uint8 CrystalSpawn = 2;
        static constexpr uint8 CartSpawn = 3;
        static constexpr uint8 Lost = 4;
        static constexpr uint8 Win = 5;
    }

    namespace Events
    {
        static constexpr uint32 ProgressEventHordeWest = 88514;
        static constexpr uint32 ProgressEventAllianceWest = 88515;
        static constexpr uint32 ProgressEventHordeEast = 88510;
        static constexpr uint32 ProgressEventAllianceEast = 88511;

        static constexpr uint32 BattlegroundStarted = 35912;
    }

    namespace GameObjects
    {
        static constexpr uint32 DeephaulCrystal = 422413; // Flag

        static constexpr uint32 EarthenworksStartingGateX = 437274;
        static constexpr uint32 WaterworksStartingGateX = 446147;
    }

    namespace PathIds
    {
        static constexpr int32 EastCart = 214690 * 100;
        static constexpr int32 WestCart = 217346 * 100;

        namespace Ruffious
        {
            static constexpr uint32 Path1 = 224087 * 100;
            static constexpr uint32 Path2 = 224087 * 100 + 1;
            static constexpr uint32 Path3 = 224087 * 100 + 2;
            static constexpr uint32 Path4 = 224087 * 100 + 3;
        }

        namespace ForemanUzjax
        {
            static constexpr uint32 Path1 = 224086 * 100;
            static constexpr uint32 Path2 = 224086 * 100 + 1;
            static constexpr uint32 Path3 = 224086 * 100 + 2;
            static constexpr uint32 Path4 = 224086 * 100 + 3;
        }
    }

    namespace Positions
    {
        static constexpr Position WestMineCartSpawn = { 4250.3647f, -2751.066f, 239.46973f, static_cast<float>(M_PI) };
        static constexpr Position EastMineCartSpawn = { 3875.0f, -3150.0f, 240.2913f, 0.0f };

        static constexpr std::array<Position, 5> EarthenMineCartsHorde =
        {{
            { 4179.265625f, -2788.0712890625f, 240.7358856201171875f, 4.05515289306640625f },
            { 4163.166015625f, -2809.192626953125f, 240.86444091796875f, 4.05515289306640625f },
            { 4171.251953125f, -2798.54345703125f, 240.8136138916015625f, 4.05515289306640625f },
            { 4175.2255859375f, -2793.239501953125f, 240.7935028076171875f, 4.091466903686523437f },
            { 4167.109375f, -2803.795166015625f, 240.978973388671875f, 4.05515289306640625f }
        }};

        static constexpr std::array<Position, 5> EarthenMineCartsAlliance =
        {{
            { 3949.052978515625f, -3106.71875f, 240.960845947265625f, 4.05515289306640625f },
            { 3961.213623046875f, -3090.671875f, 241.0115814208984375f, 4.05515289306640625f },
            { 3957.064208984375f, -3095.954833984375f, 240.8014068603515625f, 4.05515289306640625f },
            { 3965.46875f, -3084.96533203125f, 240.85400390625f, 4.068012237548828125f },
            { 3953.146728515625f, -3101.30029296875f, 240.928680419921875f, 4.05515289306640625f },
        }};
    }

    namespace PvpStats
    {
        static constexpr int32 FlagCaptures = 1020;
        static constexpr int32 CartsControlled = 1021;
    }

    namespace Sounds
    {
        static constexpr uint32 PvpFlagTakenAlliance = 8174;
        static constexpr uint32 PvpFlagTakenHorde = 8212;
        static constexpr uint32 PvpFlagCapturedAlliance = 8173;
        static constexpr uint32 PvpFlagCapturedHorde = 8213;
    }

    namespace Spells
    {
        static constexpr uint32 DeephaulCrystal = 434339;

        static constexpr uint32 ControlVisualHorde = 430220;
        static constexpr uint32 ControlVisualNeutral = 430178;
        static constexpr uint32 ControlVisualAlliance = 430221;

        static constexpr uint32 CartControlCapturePointUnitEast = 430211;
        static constexpr uint32 CartControlCapturePointUnitWest = 430216;

        static constexpr uint32 CartCap = 430207;

        static constexpr uint32 DefendingCartAura = 128646;

        static constexpr uint32 Restoration = 296575;
        static constexpr uint32 Berserking = 296576;
        static constexpr uint32 RuneOfFrequency = 422968;

        static constexpr uint32 CartExhaustion = 456466;

        static constexpr uint32 RecentlyDroppedFlag = 50327;
    }

    namespace WorldStates
    {
        static constexpr int32 FlagEnabled = 25412; // when this is 3, the flag is spawned

        static constexpr int32 HordeTeamScore = 24959;
        static constexpr int32 AllianceTeamScore = 24958;

        static constexpr int32 MaxTeamScore = 24960;

        static constexpr int32 BattleBegun = 7852;

        static constexpr int32 AllianceControlsEastMineCart = 25415;
        static constexpr int32 HordeControlsEastMineCart = 25414;

        static constexpr int32 AllianceControlsWestMineCart = 25421;
        static constexpr int32 HordeControlsWestMineCart = 25420;

        static constexpr std::array<int32, 2> AllianceControlWorldStates = { AllianceControlsEastMineCart, AllianceControlsWestMineCart };
        static constexpr std::array<int32, 2> HordeControlWorldStates = { HordeControlsEastMineCart, HordeControlsWestMineCart };

        /*
         * 1; on reset; dropped
         * 2; when taken
         */
        static constexpr int32 HordeFlagState = 1546;
        /*
         * 1; on reset; dropped
         * 2; when taken
         */
        static constexpr int32 AllianceFlagState = 1545;

        // WSE: 12385, "(WorldState(6954) + WorldState(6955)) == 1")
        // values might be swapped, they are not send to client
        // See SilvershardMines
        static constexpr int32 AllianceCapturedCart = 6954;
        static constexpr int32 HordeCapturedCart = 6955;

        namespace Values
        {
            static constexpr int32 FlagClaimed = 2; // On Player
            static constexpr int32 FlagUnclaimed = 1; // Not on player (in base, dropped, respawning)
        }
    }
}

struct battleground_deephaul_ravine : BattlegroundScript
{
    explicit battleground_deephaul_ravine(BattlegroundMap* map) : BattlegroundScript(map), _cartsReached(0), _cartGUIDs({ }), _capturePointAreaTriggers({ }), _leaderGUIDs({ }) { }

    void OnInit() override
    {
        BattlegroundScript::OnInit();

        for (Position const& pos : DeephaulRavine::Positions::EarthenMineCartsHorde)
            battlegroundMap->SummonCreature(DeephaulRavine::Creatures::EarthenMineCartHorde, pos);

        for (Position const& pos : DeephaulRavine::Positions::EarthenMineCartsAlliance)
            battlegroundMap->SummonCreature(DeephaulRavine::Creatures::EarthenMineCartAlliance, pos);
    }

    void OnStart() override
    {
        BattlegroundScript::OnStart();
        _scheduler.Schedule(15s, [&](TaskContext)
        {
            UpdateWorldState(DeephaulRavine::WorldStates::FlagEnabled, 3);
        });

        UpdateWorldState(DeephaulRavine::WorldStates::BattleBegun, 1);

        _scheduler.Schedule(2s, [&](TaskContext context)
        {
            uint32 const underAllianceControl = std::ranges::count_if(DeephaulRavine::WorldStates::AllianceControlWorldStates, [&](int32 worldState)
            {
                return battlegroundMap->GetWorldStateValue(worldState) == 1;
            });

            uint32 const underHordeControl = std::ranges::count_if(DeephaulRavine::WorldStates::HordeControlWorldStates, [&](int32 worldState)
            {
                return battlegroundMap->GetWorldStateValue(worldState) == 1;
            });

            int32 const maxTeamScore = battlegroundMap->GetWorldStateValue(DeephaulRavine::WorldStates::MaxTeamScore);

            uint32 const hordeScoreToAdd = std::min<uint32>(maxTeamScore - battleground->GetTeamScore(TEAM_HORDE), underHordeControl * 3);
            uint32 const allianceScoreToAdd = std::min<uint32>(maxTeamScore - battleground->GetTeamScore(TEAM_ALLIANCE), underAllianceControl * 3);

            battleground->AddPoint(HORDE, hordeScoreToAdd);
            battleground->AddPoint(ALLIANCE, allianceScoreToAdd);

            SendTeamScores();

            if (!CheckWinner())
                context.Repeat();
        });

        _scheduler.Schedule(5s, [&](TaskContext context)
        {
            RespawnEarthenMineCarts();
            context.Repeat();
        });

        for (ObjectGuid const& guid : _doorGUIDs)
        {
            if (GameObject* gameobject = battlegroundMap->GetGameObject(guid))
            {
                gameobject->UseDoorOrButton();
                gameobject->DespawnOrUnsummon(3s);
            }
        }

        TriggerGameEvent(DeephaulRavine::Events::BattlegroundStarted);
    }

    void OnPrepareStage3() override
    {
        BattlegroundScript::OnPrepareStage3();

        _scheduler.Schedule(2s, [&](TaskContext)
        {
            SpawnMineCarts();
        });

        _scheduler.Schedule(15s, [&](TaskContext)
        {
            DoForLeaders([&](Creature const* creature)
            {
                creature->AI()->DoAction(DeephaulRavine::Actions::CommanderStartIntro);
            });
        });
    }

    void OnUpdate(uint32 diff) override
    {
        BattlegroundScript::OnUpdate(diff);
        _scheduler.Update(diff);
    }

    void OnGameObjectCreate(GameObject* gameobject) override
    {
        BattlegroundScript::OnGameObjectCreate(gameobject);

        switch (gameobject->GetEntry())
        {
            case DeephaulRavine::GameObjects::DeephaulCrystal:
                _flagGUID = gameobject->GetGUID();
                break;
            case DeephaulRavine::GameObjects::WaterworksStartingGateX:
            case DeephaulRavine::GameObjects::EarthenworksStartingGateX:
                _doorGUIDs.emplace_back(gameobject->GetGUID());
                break;
            default:
                break;
        }
    }

    bool CanCaptureFlag(AreaTrigger* areaTrigger, Player* player) override
    {
        Team const team = battleground->GetPlayerTeam(player->GetGUID());
        TeamId const teamId = Battleground::GetTeamIndexByTeamId(team);

        if (areaTrigger->GetGUID() != _capturePointAreaTriggers[teamId])
            return false;

        if (GameObject const* flag = battlegroundMap->GetGameObject(_flagGUID))
            return player->GetGUID() == flag->GetFlagCarrierGUID();

        return false;
    }

    void OnCaptureFlag(AreaTrigger* areaTrigger, Player* player) override
    {
        BattlegroundScript::OnCaptureFlag(areaTrigger, player);

        if (GameObject const* gameObject = battlegroundMap->GetGameObject(_flagGUID))
            gameObject->HandleCustomTypeCommand(GameObjectType::SetNewFlagState(FlagState::Respawning, player));

        player->RemoveAurasDueToSpell(DeephaulRavine::Spells::DeephaulCrystal);
        battleground->UpdatePvpStat(player, DeephaulRavine::PvpStats::FlagCaptures, 1);

        battleground->AddPoint(player->GetBGTeam(), 100);
        if (player->GetBGTeam() == ALLIANCE)
        {
            battleground->SendBroadcastText(DeephaulRavine::BroadcastTexts::CrystalCapturedAlliance, CHAT_MSG_BG_SYSTEM_ALLIANCE, player);
            battleground->PlaySoundToAll(DeephaulRavine::Sounds::PvpFlagCapturedAlliance);
        }
        else if (player->GetBGTeam() == HORDE)
        {
            battleground->SendBroadcastText(DeephaulRavine::BroadcastTexts::CrystalCapturedHorde, CHAT_MSG_BG_SYSTEM_HORDE, player);
            battleground->PlaySoundToAll(DeephaulRavine::Sounds::PvpFlagCapturedHorde);
        }
    }

    void OnFlagStateChange(GameObject* flagInBase, FlagState oldValue, FlagState newValue, Player* player) override
    {
        BattlegroundScript::OnFlagStateChange(flagInBase, oldValue, newValue, player);

        switch (newValue)
        {
            case FlagState::Taken:
                battleground->SendMessageToAll(LANG_BG_DR_CRYSTAL_TAKEN, player->GetBGTeam() == HORDE ? CHAT_MSG_BG_SYSTEM_HORDE : CHAT_MSG_BG_SYSTEM_ALLIANCE, player);
                battleground->SendMessageToAll(LANG_BG_DR_CRYSTAL_TAKEN_TUTORIAL, CHAT_MSG_RAID_BOSS_EMOTE, player); // player should also be the sender
                battleground->PlaySoundToAll(player->GetBGTeam() == HORDE ? DeephaulRavine::Sounds::PvpFlagTakenHorde : DeephaulRavine::Sounds::PvpFlagTakenAlliance);
                UpdateWorldState(DeephaulRavine::WorldStates::HordeFlagState, player->GetBGTeam() == HORDE ? DeephaulRavine::WorldStates::Values::FlagClaimed : DeephaulRavine::WorldStates::Values::FlagUnclaimed);
                UpdateWorldState(DeephaulRavine::WorldStates::AllianceFlagState, player->GetBGTeam() == ALLIANCE ? DeephaulRavine::WorldStates::Values::FlagClaimed : DeephaulRavine::WorldStates::Values::FlagUnclaimed);
                break;
            case FlagState::Dropped:
                if (player->GetBGTeam() == ALLIANCE)
                    battleground->SendBroadcastText(DeephaulRavine::BroadcastTexts::FlagDropped, CHAT_MSG_BG_SYSTEM_ALLIANCE, player);
                else
                    battleground->SendBroadcastText(DeephaulRavine::BroadcastTexts::FlagDropped, CHAT_MSG_BG_SYSTEM_HORDE, player);
                player->CastSpell(player, DeephaulRavine::Spells::RecentlyDroppedFlag, true);
                UpdateWorldState(DeephaulRavine::WorldStates::HordeFlagState, DeephaulRavine::WorldStates::Values::FlagUnclaimed);
                UpdateWorldState(DeephaulRavine::WorldStates::AllianceFlagState, DeephaulRavine::WorldStates::Values::FlagUnclaimed);
                break;
            case FlagState::Respawning:
                UpdateWorldState(DeephaulRavine::WorldStates::HordeFlagState, DeephaulRavine::WorldStates::Values::FlagUnclaimed);
                UpdateWorldState(DeephaulRavine::WorldStates::AllianceFlagState, DeephaulRavine::WorldStates::Values::FlagUnclaimed);

                _scheduler.Schedule(Milliseconds(flagInBase->GetGOInfo()->newflag.RespawnTime) - 5s, [&](TaskContext)
                {
                    DoForLeaders([&](Creature const* creature)
                    {
                        creature->AI()->Talk(DeephaulRavine::CreatureTexts::CrystalSpawn);
                    });
                });
                break;
            case FlagState::InBase:
                UpdateWorldState(DeephaulRavine::WorldStates::HordeFlagState, DeephaulRavine::WorldStates::Values::FlagUnclaimed);
                UpdateWorldState(DeephaulRavine::WorldStates::AllianceFlagState, DeephaulRavine::WorldStates::Values::FlagUnclaimed);
                break;
            default:
                break;
        }
    }

    void DoAction(uint32 actionId, WorldObject* source, WorldObject* target) override
    {
        BattlegroundScript::DoAction(actionId, source, target);

        switch (actionId)
        {
            case DeephaulRavine::Actions::CaptureMineCart:
                HandleMineCartCaptured();
                break;
            case DeephaulRavine::Actions::ConsumeBuff:
                HandleConsumeBuff(Object::ToAreaTrigger(source), Object::ToPlayer(target));
                break;
            case DeephaulRavine::Actions::HordeCartAppearedInitial:
                battleground->SendBroadcastText(DeephaulRavine::BroadcastTexts::HordeControlMineCart, CHAT_MSG_BG_SYSTEM_HORDE, source);
                break;
            case DeephaulRavine::Actions::AllianceCartAppearedInitial:
                battleground->SendBroadcastText(DeephaulRavine::BroadcastTexts::AllianceControlMineCart, CHAT_MSG_BG_SYSTEM_ALLIANCE, source);
                break;
            default:
                break;
        }
    }

    void HandleConsumeBuff(AreaTrigger* trigger, Player* player)
    {
        if (!trigger || !player)
            return;

        switch (trigger->GetCreateProperties()->Template->Id.Id)
        {
            case DeephaulRavine::AreaTriggers::BerserkerBuff:
                player->CastSpell(player, DeephaulRavine::Spells::Berserking, true);
                break;
            case DeephaulRavine::AreaTriggers::RuneOfFrequency:
                player->CastSpell(player, DeephaulRavine::Spells::RuneOfFrequency, true);
                break;
            case DeephaulRavine::AreaTriggers::HealingBuff:
                player->CastSpell(player, DeephaulRavine::Spells::Restoration, true);
                break;
            default:
                break;
        }

        AreaTriggerCreatePropertiesId const createPropertiesId = trigger->GetCreateProperties()->Id;
        Position pos = trigger->GetPosition();

        _scheduler.Schedule(90s, [&, createPropertiesId, pos](TaskContext)
        {
            if (Creature* genericBunny = battlegroundMap->GetCreature(_genericBunnyGUID))
                AreaTrigger::CreateAreaTrigger(createPropertiesId, pos, -1, genericBunny, nullptr);
        });

        trigger->Remove();
    }

    void OnCreatureCreate(Creature* creature) override
    {
        BattlegroundScript::OnCreatureCreate(creature);

        switch (creature->GetEntry())
        {
            case DeephaulRavine::Creatures::GenericBunny:
                _genericBunnyGUID = creature->GetGUID();
                break;
            case DeephaulRavine::Creatures::ForemanUzjax:
                _leaderGUIDs[TEAM_HORDE] = creature->GetGUID();
                break;
            case DeephaulRavine::Creatures::Ruffious:
                _leaderGUIDs[TEAM_ALLIANCE] = creature->GetGUID();
                break;
            default:
                break;
        }
    }

    void OnCreatureRemove(Creature* creature) override
    {
        switch (creature->GetEntry())
        {
            case DeephaulRavine::Creatures::EarthenMineCartAlliance:
                _allianceDespawnedMineCarts.push(creature->GetPosition());
                break;
            case DeephaulRavine::Creatures::EarthenMineCartHorde:
                _hordeDespawnedMineCarts.push(creature->GetPosition());
                break;
            default:
                break;
        }
    }

    void ProcessEvent(WorldObject* obj, uint32 eventId, WorldObject* invoker) override
    {
        BattlegroundScript::ProcessEvent(obj, eventId, invoker);

        switch (eventId)
        {
            case DeephaulRavine::Events::ProgressEventAllianceEast:
            case DeephaulRavine::Events::ProgressEventAllianceWest:
                HandleProgressEvent(Object::ToGameObject(invoker), ALLIANCE, DeephaulRavine::Spells::ControlVisualAlliance, DeephaulRavine::BroadcastTexts::AllianceControlMineCart, CHAT_MSG_BG_SYSTEM_ALLIANCE);
                break;
            case DeephaulRavine::Events::ProgressEventHordeEast:
            case DeephaulRavine::Events::ProgressEventHordeWest:
                HandleProgressEvent(Object::ToGameObject(invoker), HORDE, DeephaulRavine::Spells::ControlVisualHorde, DeephaulRavine::BroadcastTexts::HordeControlMineCart, CHAT_MSG_BG_SYSTEM_HORDE);
                break;
            default:
                break;
        }
    }

    void OnAreaTriggerCreate(AreaTrigger* areaTrigger) override
    {
        BattlegroundScript::OnAreaTriggerCreate(areaTrigger);
        if (!areaTrigger->IsStaticSpawn())
            return;

        switch (areaTrigger->GetEntry())
        {
            case DeephaulRavine::AreaTriggers::CapturePointAlliance:
                _capturePointAreaTriggers[TEAM_ALLIANCE] = areaTrigger->GetGUID();
                break;
            case DeephaulRavine::AreaTriggers::CapturePointHorde:
                _capturePointAreaTriggers[TEAM_HORDE] = areaTrigger->GetGUID();
                break;
            default:
                break;
        }
    }

    void HandleProgressEvent(GameObject const* controlZone, Team team, uint32 controlVisualSpell, uint32 textId, ChatMsg msgType) const
    {
        if (!controlZone)
            return;

        Creature* mineCart = Object::ToCreature(controlZone->GetOwner());
        if (!mineCart)
            return;

        mineCart->RemoveAurasDueToSpell(DeephaulRavine::Spells::ControlVisualNeutral);
        mineCart->RemoveAurasDueToSpell(DeephaulRavine::Spells::ControlVisualAlliance);
        mineCart->RemoveAurasDueToSpell(DeephaulRavine::Spells::ControlVisualHorde);
        mineCart->CastSpell(mineCart, controlVisualSpell, true);
        UpdateCartWorldStates(controlZone);
        battleground->SendBroadcastText(textId, msgType, controlZone);

        for (ObjectGuid const& guid : *controlZone->GetInsidePlayers())
            if (Player* player = ObjectAccessor::FindPlayer(guid))
                if (player->GetBGTeam() == team)
                    battleground->UpdatePvpStat(player, DeephaulRavine::PvpStats::CartsControlled, 1);
    }

    void HandleMineCartCaptured()
    {
        _cartsReached++;
        if (_cartsReached != 2)
            return;

        for (ObjectGuid const& cartGUID : _cartGUIDs)
        {
            if (Creature* creature = battlegroundMap->GetCreature(cartGUID))
            {
                GameObject* controlZone = nullptr;
                if (creature->HasAura(DeephaulRavine::Spells::CartControlCapturePointUnitEast))
                    controlZone = creature->GetGameObject(DeephaulRavine::Spells::CartControlCapturePointUnitEast);
                else if (creature->HasAura(DeephaulRavine::Spells::CartControlCapturePointUnitWest))
                    controlZone = creature->GetGameObject(DeephaulRavine::Spells::CartControlCapturePointUnitWest);

                if (controlZone)
                {
                    uint32 const scoreToAdd = std::min<uint32>(1500 - battleground->GetTeamScore(controlZone->GetControllingTeam()), 100);
                    if (controlZone->GetControllingTeam() == TEAM_HORDE)
                    {
                        if (battlegroundMap->GetWorldStateValue(DeephaulRavine::WorldStates::HordeCapturedCart) != 1)
                            UpdateWorldState(DeephaulRavine::WorldStates::HordeCapturedCart, 1, true);

                        battleground->SendBroadcastText(DeephaulRavine::BroadcastTexts::HordeCaptureMineCart, CHAT_MSG_BG_SYSTEM_HORDE, creature);
                        if (battleground->GetStatus() != STATUS_WAIT_LEAVE)
                            battleground->AddPoint(HORDE, scoreToAdd);
                    }
                    else if (controlZone->GetControllingTeam() == TEAM_ALLIANCE)
                    {
                        if (battlegroundMap->GetWorldStateValue(DeephaulRavine::WorldStates::AllianceCapturedCart) != 1)
                            UpdateWorldState(DeephaulRavine::WorldStates::AllianceCapturedCart, 1, true);

                        battleground->SendBroadcastText(DeephaulRavine::BroadcastTexts::AllianceCaptureMineCart, CHAT_MSG_BG_SYSTEM_ALLIANCE, creature);
                        if (battleground->GetStatus() != STATUS_WAIT_LEAVE)
                            battleground->AddPoint(ALLIANCE, scoreToAdd);
                    }
                }

                creature->DespawnOrUnsummon();
            }
        }

        UpdateWorldState(DeephaulRavine::WorldStates::AllianceControlsWestMineCart, 0);
        UpdateWorldState(DeephaulRavine::WorldStates::AllianceControlsEastMineCart, 0);
        UpdateWorldState(DeephaulRavine::WorldStates::HordeControlsWestMineCart, 0);
        UpdateWorldState(DeephaulRavine::WorldStates::HordeControlsEastMineCart, 0);

        CheckWinner();

        _scheduler.Schedule(2s, [&](TaskContext)
        {
            SpawnMineCarts();
        });
    }

    void SpawnMineCarts()
    {
        _cartsReached = 0;

        // both mine carts spawn with Neutral aura; while they are controlled by their faction, this gets overriden a few moments later
        if (TempSummon* creature = battlegroundMap->SummonCreature(DeephaulRavine::Creatures::MineCartEast, DeephaulRavine::Positions::EastMineCartSpawn))
        {
            _cartGUIDs[0] = creature->GetGUID();

            creature->CastSpell(creature, DeephaulRavine::Spells::CartControlCapturePointUnitEast, true);
            creature->CastSpell(creature, DeephaulRavine::Spells::ControlVisualNeutral, true);
            creature->CastSpell(creature, DeephaulRavine::Spells::DefendingCartAura, true);
            creature->GetMotionMaster()->MovePath(DeephaulRavine::PathIds::EastCart, false);

            UpdateWorldState(DeephaulRavine::WorldStates::AllianceControlsWestMineCart, 0);
            UpdateWorldState(DeephaulRavine::WorldStates::AllianceControlsEastMineCart, 1);
        }

        if (TempSummon* creature = battlegroundMap->SummonCreature(DeephaulRavine::Creatures::MineCartWest, DeephaulRavine::Positions::WestMineCartSpawn))
        {
            _cartGUIDs[1] = creature->GetGUID();

            creature->CastSpell(creature, DeephaulRavine::Spells::CartControlCapturePointUnitWest, true);
            creature->CastSpell(creature, DeephaulRavine::Spells::ControlVisualNeutral, true);
            creature->CastSpell(creature, DeephaulRavine::Spells::DefendingCartAura, true);
            creature->GetMotionMaster()->MovePath(DeephaulRavine::PathIds::WestCart, false);

            UpdateWorldState(DeephaulRavine::WorldStates::HordeControlsWestMineCart, 1);
            UpdateWorldState(DeephaulRavine::WorldStates::HordeControlsEastMineCart, 0);
        }

        DoForLeaders([&](Creature const* creature)
        {
            creature->AI()->Talk(DeephaulRavine::CreatureTexts::CartSpawn);
        });
    }

    void SendTeamScores() const
    {
        UpdateWorldState(DeephaulRavine::WorldStates::HordeTeamScore, battleground->GetTeamScore(TEAM_HORDE));
        UpdateWorldState(DeephaulRavine::WorldStates::AllianceTeamScore, battleground->GetTeamScore(TEAM_ALLIANCE));
    }

    void UpdateCartWorldStates(GameObject const* controlZone) const
    {
        if (!controlZone)
            return;

        Creature const* creature = Object::ToCreature(controlZone->GetOwner());
        if (!creature)
            return;

        TeamId const controllingTeam = controlZone->GetControllingTeam();

        switch (creature->GetEntry())
        {
            case DeephaulRavine::Creatures::MineCartEast:
                UpdateWorldState(DeephaulRavine::WorldStates::AllianceControlsEastMineCart, controllingTeam == TEAM_ALLIANCE);
                UpdateWorldState(DeephaulRavine::WorldStates::HordeControlsEastMineCart, controllingTeam == TEAM_HORDE);
                break;
            case DeephaulRavine::Creatures::MineCartWest:
                UpdateWorldState(DeephaulRavine::WorldStates::AllianceControlsWestMineCart, controllingTeam == TEAM_ALLIANCE);
                UpdateWorldState(DeephaulRavine::WorldStates::HordeControlsWestMineCart, controllingTeam == TEAM_HORDE);
                break;
            default:
                break;
        }
    }

    bool CheckWinner() const
    {
        uint32 const hordeScore = battleground->GetTeamScore(TEAM_HORDE);
        uint32 const allianceScore = battleground->GetTeamScore(TEAM_ALLIANCE);
        uint32 const maxScore = static_cast<uint32>(battlegroundMap->GetWorldStateValue(DeephaulRavine::WorldStates::MaxTeamScore));

        if (hordeScore >= maxScore || allianceScore >= maxScore)
        {
            SendTeamScores();

            if (hordeScore >= maxScore && allianceScore >= maxScore)
            {
                battleground->EndBattleground(TEAM_OTHER);
                return true;
            }

            if (hordeScore >= maxScore)
            {
                battleground->EndBattleground(HORDE);
                if (Creature const* uzjax = battlegroundMap->GetCreature(_leaderGUIDs[TEAM_HORDE]))
                    uzjax->AI()->Talk(DeephaulRavine::CreatureTexts::Win);
                if (Creature const* ruffious = battlegroundMap->GetCreature(_leaderGUIDs[TEAM_ALLIANCE]))
                    ruffious->AI()->Talk(DeephaulRavine::CreatureTexts::Lost);
                return true;
            }

            if (allianceScore >= maxScore)
            {
                battleground->EndBattleground(ALLIANCE);
                if (Creature const* uzjax = battlegroundMap->GetCreature(_leaderGUIDs[TEAM_HORDE]))
                    uzjax->AI()->Talk(DeephaulRavine::CreatureTexts::Lost);
                if (Creature const* ruffious = battlegroundMap->GetCreature(_leaderGUIDs[TEAM_ALLIANCE]))
                    ruffious->AI()->Talk(DeephaulRavine::CreatureTexts::Win);
                return true;
            }
        }

        return false;
    }

    void DoForLeaders(std::function<void(Creature*)> const& fn) const
    {
        for (ObjectGuid const& guid : _leaderGUIDs)
            if (Creature* creature = battlegroundMap->GetCreature(guid))
                fn(creature);
    }

    void RespawnEarthenMineCarts()
    {
        size_t allianceDespawnedMineCartCount = _allianceDespawnedMineCarts.size();
        size_t hordeDespawnedMineCartCount = _hordeDespawnedMineCarts.size();

        while (allianceDespawnedMineCartCount > 0 && !_hordeDespawnedMineCarts.empty())
        {
            --allianceDespawnedMineCartCount;
            Position pos = _hordeDespawnedMineCarts.front();
            _hordeDespawnedMineCarts.pop();
            battlegroundMap->SummonCreature(DeephaulRavine::Creatures::EarthenMineCartHorde, pos);
        }

        while (hordeDespawnedMineCartCount > 0 && !_allianceDespawnedMineCarts.empty())
        {
            --hordeDespawnedMineCartCount;
            Position pos = _allianceDespawnedMineCarts.front();
            _allianceDespawnedMineCarts.pop();
            battlegroundMap->SummonCreature(DeephaulRavine::Creatures::EarthenMineCartAlliance, pos);
        }
    }

private:
    TaskScheduler _scheduler;
    ObjectGuid _flagGUID;
    uint8 _cartsReached;
    std::array<ObjectGuid, 2> _cartGUIDs;
    std::array<ObjectGuid, 2> _controlZoneGUIDs;
    std::array<ObjectGuid, 2> _capturePointAreaTriggers;
    ObjectGuid _genericBunnyGUID;
    std::array<ObjectGuid, 2> _leaderGUIDs; // Foreman Uzjax &  Ruffious

    std::queue<Position> _hordeDespawnedMineCarts;
    std::queue<Position> _allianceDespawnedMineCarts;

    GuidVector _doorGUIDs;
};

// 214690 - Mine Cart
// 217346 - Mine Cart
class npc_bg_deephaul_cavern_mine_cart : public ScriptedAI
{
public:
    explicit npc_bg_deephaul_cavern_mine_cart(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        DoCastSelf(DeephaulRavine::Spells::ControlVisualNeutral, true);
        DoCastSelf(DeephaulRavine::Spells::DefendingCartAura, true);

        switch (me->GetEntry())
        {
            case DeephaulRavine::Creatures::MineCartEast:
                me->RemoveAurasDueToSpell(DeephaulRavine::Spells::ControlVisualNeutral);
                DoCastSelf(DeephaulRavine::Spells::ControlVisualAlliance, true);
                if (ZoneScript* zonescript = me->GetZoneScript())
                    zonescript->DoAction(DeephaulRavine::Actions::AllianceCartAppearedInitial, me, me);
                break;
            case DeephaulRavine::Creatures::MineCartWest:
                me->RemoveAurasDueToSpell(DeephaulRavine::Spells::ControlVisualNeutral);
                DoCastSelf(DeephaulRavine::Spells::ControlVisualHorde, true);
                if (ZoneScript* zonescript = me->GetZoneScript())
                    zonescript->DoAction(DeephaulRavine::Actions::HordeCartAppearedInitial, me, me);
                break;
            default:
                break;
        }
    }

    void WaypointPathEnded(uint32 nodeId, uint32 pathId) override
    {
        ScriptedAI::WaypointPathEnded(nodeId, pathId);

        switch (pathId)
        {
            case DeephaulRavine::PathIds::WestCart:
            case DeephaulRavine::PathIds::EastCart:
                OnCapture();
                break;
            default:
                break;
        }
    }

    void OnCapture()
    {
        DoCastSelf(DeephaulRavine::Spells::CartCap, true);
    }
};

// 430207 - Cart Cap
class spell_bg_deephaul_ravine_cart_cap final : public SpellScript
{
    void HandleScript(SpellEffIndex /*effIndex*/) const
    {
        Creature* hitCreature = GetHitCreature();
        if (!hitCreature)
            return;

        if (ZoneScript* zoneScript = hitCreature->GetZoneScript())
            zoneScript->DoAction(DeephaulRavine::Actions::CaptureMineCart, hitCreature, hitCreature);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_bg_deephaul_ravine_cart_cap::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 211271 - Earthen Mine Cart
// 211155 - Earthen Mine Cart
class npc_bg_deephaul_ravine_earthen_mine_cart final : public ScriptedAI
{
public:
    explicit npc_bg_deephaul_ravine_earthen_mine_cart(Creature* creature) : ScriptedAI(creature) { }

    void OnSpellClick(Unit* clicker, bool spellClickHandled) override
    {
        ScriptedAI::OnSpellClick(clicker, spellClickHandled);

        if (!spellClickHandled)
            return;

        me->DespawnOrUnsummon();
    }
};

// 211153 - Earthen Mine Cart
class npc_bg_deephaul_ravine_earthen_mine_cart_horde final : public ScriptedAI
{
public:
    explicit npc_bg_deephaul_ravine_earthen_mine_cart_horde(Creature* creature) : ScriptedAI(creature)
    {
    }

    static constexpr int32 Path1 = 211153 * 100;
    static constexpr int32 Path2 = 211153 * 100 + 1;
    static constexpr int32 Path3 = 211153 * 100 + 2;

    void JustAppeared() override
    {
        me->ToTempSummon()->GetSummoner()->ToPlayer()->EnterVehicle(me);
        _scheduler.Schedule(1500ms, [&](TaskContext)
        {
            // teleport packet sends same x & y for some reason
            // teleport and movement start at same time
            me->NearTeleportTo({ 4160.4297f, -2812.3852f, 240.29422f });
            me->GetMotionMaster()->MovePath(Path1, false);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        switch (pathId)
        {
            case Path1:
                _scheduler.Schedule(500ms, [&](TaskContext)
                {
                    if (Vehicle* vehicle = me->GetVehicleKit())
                        vehicle->RemoveAllPassengers();
                    me->GetMotionMaster()->MovePath(Path2, false);
                });
                break;
            case Path2:
                _scheduler.Schedule(1s, [&](TaskContext)
                {
                    me->GetMotionMaster()->MovePath(Path3, false);
                });
                break;
            case Path3:
                me->DespawnOrUnsummon();
                break;
            default:
                break;
        }
    }

private:
    TaskScheduler _scheduler;
};

// 211270 - Earthen Mine Cart
class npc_bg_deephaul_ravine_earthen_mine_cart_alliance final : public ScriptedAI
{
public:
    explicit npc_bg_deephaul_ravine_earthen_mine_cart_alliance(Creature* creature) : ScriptedAI(creature)
    {
    }

    static constexpr int32 Path1 = 211270 * 100;
    static constexpr int32 Path2 = 211270 * 100 + 1;

    void JustAppeared() override
    {
        me->ToTempSummon()->GetSummoner()->ToPlayer()->EnterVehicle(me);
        _scheduler.Schedule(1500ms, [&](TaskContext)
        {
            // teleport packet sends same x & y for some reason
            // teleport and movement start at same time
            me->NearTeleportTo({ 3968.5852f, -3080.5815f, 240.14261f, 0.0f });
            me->GetMotionMaster()->MovePath(Path1, false);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        switch (pathId)
        {
            case Path1:
                _scheduler.Schedule(500ms, [&](TaskContext)
                {
                    if (Vehicle* vehicle = me->GetVehicleKit())
                    {
                        for (auto const& [_, seat] : vehicle->Seats)
                        {
                            if (Unit* passenger = ObjectAccessor::GetUnit(*me, seat.Passenger.Guid))
                            {
                                passenger->CastSpell(passenger, DeephaulRavine::Spells::CartExhaustion, true);
                                passenger->_ExitVehicle();
                            }
                        }
                    }
                    me->GetMotionMaster()->MovePath(Path2, false);
                });
                break;
            case Path2:
                _scheduler.Schedule(1s, [&](TaskContext)
                {
                    me->DespawnOrUnsummon();
                });
                break;
            default:
                break;
        }
    }

private:
    TaskScheduler _scheduler;
};

// 21076 - PvP Rune Rejuv Visual (New)
// 21077 - PvP Rune Berserking Visual (New)
// 33926 - PvP Rune Cooldown Visual (New)
struct at_bg_deephaul_ravine_buff final : AreaTriggerAI
{
    explicit at_bg_deephaul_ravine_buff(AreaTrigger* areaTrigger) : AreaTriggerAI(areaTrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (Player* player = unit->ToPlayer())
            if (ZoneScript* zonescript = at->GetZoneScript())
                zonescript->DoAction(DeephaulRavine::Actions::ConsumeBuff, at, player);
    }
};

// 224087 - Ruffious
// 224086 - Foreman Uzjax
template<uint32 Path1, uint32 Path2, uint32 Path3, uint32 Path4>
class npc_bg_deephaul_ravine_commander : public ScriptedAI
{
public:
    explicit npc_bg_deephaul_ravine_commander(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        ScriptedAI::JustAppeared();
        me->SetHover(true);
        me->SetDisableGravity(true);
    }

    void DoAction(int32 actionId) override
    {
        if (actionId == DeephaulRavine::Actions::CommanderStartIntro)
        {
            Talk(DeephaulRavine::CreatureTexts::Intro1);
            me->GetMotionMaster()->MovePath(Path1, false);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        ScriptedAI::UpdateAI(diff);
        _scheduler.Update(diff);
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        switch (pathId)
        {
            case Path1:
                _scheduler.Schedule(10s, [this](TaskContext)
                {
                    me->GetMotionMaster()->MovePath(Path2, false);
                    Talk(DeephaulRavine::CreatureTexts::Intro2);
                });
                break;
            case Path2:
                _scheduler.Schedule(3s, [this](TaskContext)
                {
                    me->GetMotionMaster()->MovePath(Path3, false);
                });
                break;
            case Path3:
                _scheduler.Schedule(5s, [this](TaskContext)
                {
                    me->GetMotionMaster()->MovePath(Path4, false);
                });
                break;
            default:
                break;
        }
    }

private:
    TaskScheduler _scheduler;
};

// 424383 - Earthen Mine Cart Ride
// 424166 - Earthen Mine Cart Ride
class spell_bg_deephaul_ravine_earthen_mine_cart_ride : public AuraScript
{
    void OnApply(AuraEffect const* /*auraEffect*/, AuraEffectHandleModes /*mode*/) const
    {
        // instantly remove this aura
        GetTarget()->RemoveAura(GetAura());
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_bg_deephaul_ravine_earthen_mine_cart_ride::OnApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_battleground_deephaul_ravine()
{
    RegisterBattlegroundMapScript(battleground_deephaul_ravine, 2656);
    RegisterCreatureAI(npc_bg_deephaul_cavern_mine_cart);
    RegisterSpellScript(spell_bg_deephaul_ravine_cart_cap);
    RegisterCreatureAI(npc_bg_deephaul_ravine_earthen_mine_cart);
    RegisterCreatureAI(npc_bg_deephaul_ravine_earthen_mine_cart_horde);
    RegisterCreatureAI(npc_bg_deephaul_ravine_earthen_mine_cart_alliance);
    RegisterAreaTriggerAI(at_bg_deephaul_ravine_buff);
    RegisterSpellScript(spell_bg_deephaul_ravine_earthen_mine_cart_ride);

    new GenericCreatureScript<npc_bg_deephaul_ravine_commander<DeephaulRavine::PathIds::ForemanUzjax::Path1, DeephaulRavine::PathIds::ForemanUzjax::Path2, DeephaulRavine::PathIds::ForemanUzjax::Path3, DeephaulRavine::PathIds::ForemanUzjax::Path4>>("npc_bg_deephaul_ravine_foreman_uzjax");
    new GenericCreatureScript<npc_bg_deephaul_ravine_commander<DeephaulRavine::PathIds::Ruffious::Path1, DeephaulRavine::PathIds::Ruffious::Path2, DeephaulRavine::PathIds::Ruffious::Path3, DeephaulRavine::PathIds::Ruffious::Path4>>("npc_bg_deephaul_ravine_ruffious");
}
