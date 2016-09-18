/*
* Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "CreatureGroups.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "Player.h"
#include "battle_for_the_undercity.h"

class location_trisfal_glades : public WorldMapZoneScript
{
public:
    location_trisfal_glades() : WorldMapZoneScript("location_trisfal_glades") { }

    struct location_trisfal_glades_WorldMapZoneScript : public LocationScript
    {
        location_trisfal_glades_WorldMapZoneScript() : LocationScript() { }

        void Initialize() override
        {
            for (uint8 i = 0; i < MAX_BATTLING_AREAS; ++i)
            {
                BattleFor[i] = false;
                Secured[i] = false;
            }

            for (uint8 i = 0; i < 2; ++i)
            {
                Preparing[i] = true;
                StartBattle[i] = false;
                BattleTimerState[i] = false;
                BattleTimer[i] = 0;
            }

            ResetBattle = false;
            ResetTimer = 0;

            JainaGUID.Clear();
            SylvanasGUID.Clear();
            WaveTriggerGUID.Clear();

            AllianceSpawns.clear();
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case NPC_JAINA_PROUDMORE:
                    JainaGUID = creature->GetGUID();
                    break;
                case NPC_SYLVANAS:
                    SylvanasGUID = creature->GetGUID();
                    break;
                case NPC_WAVES_TRIGGER:
                    WaveTriggerGUID = creature->GetGUID();
                    break;
                case NPC_STORMWIND_ELITE_A:
                case NPC_ALLIANCE_SIEGE:
                    AllianceSpawns.push_back(creature->GetGUID());
                    break;
                case NPC_FLYING_MACHINE:
                    // ToDo: distance hack, figure something else
                    //creature->m_CombatDistance = 50.0f;
                    break;
            }
        }

        void OnUnitDeath(Unit* unit) override
        {
            std::cout << __FUNCTION__ << std::endl;
            if (unit->GetTypeId() != TYPEID_UNIT)
                return;

            switch (unit->GetEntry())
            {
                case NPC_STORMWIND_ELITE_A:
                case NPC_ALLIANCE_SIEGE:
                    AllianceSpawns.erase(std::remove(AllianceSpawns.begin(), AllianceSpawns.end(), unit->GetGUID()), AllianceSpawns.end());
                    break;
            }
        }

        void FillInitialWorldStates(WorldPacket& data) override
        {
            // alliance
            data << uint32(WORLDSTATE_UNDERCITY_CONTROLLED_A) << uint32(Preparing[TEAM_ALLIANCE]);
            data << uint32(WORLDSTATE_MANHUNT_TIMER_STATE) << uint32(BattleTimerState[TEAM_ALLIANCE]);
            data << uint32(WORLDSTATE_MANHUNT_TIMER) << uint32(BattleTimer[TEAM_ALLIANCE]);
            data << uint32(WORLDSTATE_MANHUNT_BEGUN) << uint32(StartBattle[TEAM_ALLIANCE]);
            data << uint32(WORLDSTATE_BATTLING_SEWERS) << uint32(BattleFor[SEWERS]);
            data << uint32(WORLDSTATE_SECURED_SEWERS) << uint32(Secured[SEWERS]);
            data << uint32(WORLDSTATE_BATTLING_APOTHECARIUM) << uint32(BattleFor[APOTHECARIUM]);
            data << uint32(WORLDSTATE_SECURED_APOTHECARIUM) << uint32(Secured[APOTHECARIUM]);

            // horde
            data << uint32(WORLDSTATE_UNDERCITY_CONTROLLED_H) << uint32(Preparing[TEAM_HORDE]);
            data << uint32(WORLDSTATE_BATTLE_TIMER_STATE) << uint32(BattleTimerState[TEAM_HORDE]);
            data << uint32(WORLDSTATE_BATTLE_TIMER) << uint32(BattleTimer[TEAM_HORDE]);
            data << uint32(WORLDSTATE_BATTLE_BEGUN) << uint32(StartBattle[TEAM_HORDE]);
            data << uint32(WORLDSTATE_BATTLING_COURTYARD) << uint32(BattleFor[COURTYARD]);
            data << uint32(WORLDSTATE_CONTROLL_COURTYARD) << uint32(Secured[COURTYARD]);
            data << uint32(WORLDSTATE_BATTLING_INNER_SANCTUM) << uint32(BattleFor[INNER_SANCTUM]);
            data << uint32(WORLDSTATE_CONTROLL_INNER_SANCTUM) << uint32(Secured[INNER_SANCTUM]);
            data << uint32(WORLDSTATE_BATTLING_ROYAL_QUARTER) << uint32(BattleFor[ROYAL_QUARTER]);
            data << uint32(WORLDSTATE_CONTROLL_ROYAL_QUARTER) << uint32(Secured[ROYAL_QUARTER]);
            data << uint32(WORLDSTATE_RESET_BATTLE) << uint32(ResetBattle);
            data << uint32(WORLDSTATE_RESET_TIMER) << uint32(ResetTimer);
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                // ToDo: change it later, will probably cause warning
                // Alliance
                case WORLDSTATE_UNDERCITY_CONTROLLED_A:
                    Preparing[TEAM_ALLIANCE] = data == 0 ? false : true;
                    break;
                case WORLDSTATE_MANHUNT_TIMER_STATE:
                    BattleTimerState[TEAM_ALLIANCE] = data == 0 ? false : true;
                    break;
                case WORLDSTATE_MANHUNT_TIMER:
                    BattleTimer[TEAM_ALLIANCE] = data;
                    break;
                case WORLDSTATE_MANHUNT_BEGUN:
                    StartBattle[TEAM_ALLIANCE] = data == 0 ? false : true;
                    break;
                case WORLDSTATE_BATTLING_SEWERS:
                    BattleFor[SEWERS] = data == 0 ? false : true;
                    break;
                case WORLDSTATE_SECURED_SEWERS:
                    Secured[SEWERS] = data == 0 ? false : true;
                    break;
                case WORLDSTATE_BATTLING_APOTHECARIUM:
                    BattleFor[APOTHECARIUM] = data == 0 ? false : true;
                    break;
                case WORLDSTATE_SECURED_APOTHECARIUM:
                    Secured[APOTHECARIUM] = data == 0 ? false : true;
                    break;

                // Horde
                case WORLDSTATE_UNDERCITY_CONTROLLED_H:
                    Preparing[TEAM_HORDE] = data == 0 ? false : true;
                    break;
                case WORLDSTATE_BATTLE_TIMER_STATE:
                    BattleTimerState[TEAM_HORDE] = data == 0 ? false : true;
                    break;
                case WORLDSTATE_BATTLE_TIMER:
                    BattleTimer[TEAM_HORDE] = data;
                    break;
                case WORLDSTATE_BATTLE_BEGUN:
                    StartBattle[TEAM_HORDE] = data == 0 ? false : true;
                    break;
                case WORLDSTATE_BATTLING_COURTYARD:
                    BattleFor[COURTYARD] = data == 0 ? false : true;
                    break;
                case WORLDSTATE_CONTROLL_COURTYARD:
                    Secured[COURTYARD] = data == 0 ? false : true;
                    break;
                case WORLDSTATE_BATTLING_INNER_SANCTUM:
                    BattleFor[INNER_SANCTUM] = data == 0 ? false : true;
                    break;
                case WORLDSTATE_CONTROLL_INNER_SANCTUM:
                    Secured[INNER_SANCTUM] = data == 0 ? false : true;
                    break;
                case WORLDSTATE_BATTLING_ROYAL_QUARTER:
                    BattleFor[ROYAL_QUARTER] = data == 0 ? false : true;
                    break;
                case WORLDSTATE_CONTROLL_ROYAL_QUARTER:
                    Secured[ROYAL_QUARTER] = data == 0 ? false : true;
                    break;
                case WORLDSTATE_RESET_BATTLE:
                    ResetBattle = data == 0 ? false : true;
                    break;
                case WORLDSTATE_RESET_TIMER:
                    ResetTimer = data;
                    break;
            }
        }

        ObjectGuid GetGuidData(uint32 data) const override
        {
            switch (data)
            {
                case NPC_JAINA_PROUDMORE:
                    return JainaGUID;
                case NPC_SYLVANAS:
                    return SylvanasGUID;
                case NPC_WAVES_TRIGGER:
                    return WaveTriggerGUID;
                case DATA_GET_ENEMY:
                    return Trinity::Containers::SelectRandomContainerElement(AllianceSpawns);
            }

            return ObjectGuid::Empty;
        }
    private:
        bool Preparing[2];
        bool BattleTimerState[2];
        uint32 BattleTimer[2];
        bool StartBattle[2];
        bool BattleFor[MAX_BATTLING_AREAS];
        bool Secured[MAX_BATTLING_AREAS];
        bool ResetBattle;
        uint32 ResetTimer;

        ObjectGuid JainaGUID;
        ObjectGuid SylvanasGUID;
        ObjectGuid WaveTriggerGUID;

        std::vector<ObjectGuid> AllianceSpawns;
    };

    LocationScript* GetLocationScript() const override
    {
        return new location_trisfal_glades_WorldMapZoneScript();
    }
};


void AddSC_location_trisfal_glades()
{
    new location_trisfal_glades();
}