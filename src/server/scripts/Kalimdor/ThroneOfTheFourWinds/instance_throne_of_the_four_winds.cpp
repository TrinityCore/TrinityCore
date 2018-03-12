/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#include "throne_of_the_four_winds.h"
#include "AchievementMgr.h"
#include "GameObject.h"
#include "SpellAuras.h"

#define ENCOUNTERS 2

enum InstanceEnums
{
    // Spells
    SPELL_SLIPSTREAM_BUFF               = 87740,
    SPELL_SLIPSTREAM_PLAYER_VISUAL      = 85063,
    SPELL_RELENTLESS_STORM_VISUAL       = 89428,
    SPELL_STAY_CHILL_ACHIEVEMENT_CREDIT = 94119,
    SPELL_WIND_CHILL_10                 = 84645,
    SPELL_WIND_CHILL_25                 = 93123,
    SPELL_WIND_CHILL_10H                = 93124,
    SPELL_WIND_CHILL_25H                = 93125,
};

Position const GoBackPositions[8] =
{
    {-16, 1021, 205, 0},
    {-80, 1021, 205, 0},
    {-256, 850, 205, 0},
    {-256, 785, 205, 0},
    {-83, 610, 205, 0},
    {-18, 610, 205, 0},
    {156, 780, 205, 0},
    {156, 850, 205, 0},
};

Position const AlakirSlipstreamPositions[4] =
{
    {-51.0972f, 576.807f, 200.7063f, 1.553343f},
    {-287.604f, 816.51f, 200.7063f, 0.0f},
    {188.823f, 813.54f, 200.7063f, 3.124139f},
    {-47.9531f, 1053.3f, 200.7063f, 4.694936f},
};

class instance_throne_of_the_four_winds : public InstanceMapScript
{
public:
    instance_throne_of_the_four_winds() : InstanceMapScript("instance_throne_of_the_four_winds", 754) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_throne_of_the_four_winds_InstanceMapScript(map);
    }

    struct instance_throne_of_the_four_winds_InstanceMapScript: public InstanceScript
    {
        instance_throne_of_the_four_winds_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetBossNumber(MAX_BOSSES);
        }

        uint32 Encounter[ENCOUNTERS];

        ObjectGuid uiAnshal;
        ObjectGuid uiNezir;
        ObjectGuid uiRohash;

        ObjectGuid uiAlakir;

        ObjectGuid AnshalPlatform;
        ObjectGuid NezirPlatform;
        ObjectGuid RohashPlatform;
        ObjectGuid SkyWallRaid;
        ObjectGuid SkyWallWind;
        ObjectGuid HeartOfWindGUID;

        uint8 GatheringStrength;
        uint8 WeatherData;
        uint8 AlakirFlightData;


        void Initialize() override
        {
            for (uint8 i = 0; i < ENCOUNTERS; ++i)
                Encounter[i] = NOT_STARTED;

            GatheringStrength = 0;
            WeatherData = 0;
            AlakirFlightData = 0;
        }

        void Update(uint32 /*diff*/) override { }

        void OnPlayerEnter(Player* player) override
        {
            if (GetData(DATA_ALAKIR_EVENT) == DONE)
            {
                // fly buff on kill Al'akir
                player->CastSpell(player, 89107, true);
            }
        }

        bool IsEncounterInProgress() const override 
        {
            for (uint8 i = 0; i < ENCOUNTERS; ++i)
            {
                if (Encounter[i] == IN_PROGRESS)
                    return true;
            }
            return false;
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case GO_NAZIR_PLATFORM:
                    NezirPlatform = go->GetGUID();
                    go->setActive(true);
                    break;

                case GO_ANSHAL_PLATFORM:
                    AnshalPlatform = go->GetGUID();
                    go->setActive(true);
                    break;

                case GO_ROHASH_PLATFORM:
                    RohashPlatform = go->GetGUID();
                    go->setActive(true);
                    break;
                case GO_SKYWALL_RAID:
                    SkyWallRaid = go->GetGUID();
                    go->setActive(true);
                    break;
                case GO_SKYWALL_WIND:
                    SkyWallWind = go->GetGUID();
                    go->setActive(true);
                    break;
                case GO_HEART_OF_WIND_10:
                    if (instance->GetDifficultyID() == DIFFICULTY_10_N)
                        HeartOfWindGUID = go->GetGUID();
                    break;
                case GO_HEART_OF_WIND_25:
                    if (instance->GetDifficultyID() == DIFFICULTY_25_N)
                        HeartOfWindGUID = go->GetGUID();
                    break;
            }
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case BOSS_ANSHAL:
                    uiAnshal = creature->GetGUID();
                    break;
                case BOSS_NEZIR:
                    uiNezir = creature->GetGUID();
                    break;
                case BOSS_ROHASH:
                    uiRohash = creature->GetGUID();
                    break;
                case BOSS_ALAKIR:
                    uiAlakir = creature->GetGUID();
                    if (GetData(DATA_CONCLAVE_OF_WIND_EVENT) == DONE)
                        SummonSplistreamAlakir();
                    break;
            }
        }

        ObjectGuid GetGuidData(uint32 identifier) const override
        {
            switch (identifier)
            {
                case DATA_ANSHAL:
                    return uiAnshal;
                case DATA_NEZIR:
                    return uiNezir;
                case DATA_ROHASH:
                    return uiRohash;
                case DATA_ALAKIR:
                    return uiAlakir;
            }
            return ObjectGuid::Empty;
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case DATA_GATHERING_STRENGTH:
                    GatheringStrength = data;
                    break;
                case DATA_CONCLAVE_OF_WIND_EVENT:
                    switch (data)
                    {
                        case IN_PROGRESS:
                            if (Creature* Anshal = instance->GetCreature(uiAnshal))
                            {
                                if (Anshal->IsAlive())
                                {
                                    Anshal->SetInCombatWithZone();
                                    SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, Anshal);
                                }
                            }
                            if (Creature* Nezir = instance->GetCreature(uiNezir))
                            {
                                if (Nezir->IsAlive())
                                {
                                    Nezir->SetInCombatWithZone();
                                    SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, Nezir);
                                }
                            }
                            if (Creature* Rohash = instance->GetCreature(uiRohash))
                            {
                                if (Rohash->IsAlive())
                                {
                                    Rohash->SetInCombatWithZone();
                                    SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, Rohash);
                                }
                            }
                            break;

                        case FAIL:
                            if (Creature* Anshal = instance->GetCreature(uiAnshal))
                            {
                                SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, Anshal);
                                Anshal->Respawn(true);
                            }
                            if (Creature* Nezir = instance->GetCreature(uiNezir))
                            {
                                SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, Nezir);
                                Nezir->Respawn(true);
                            }
                            if (Creature* Rohash = instance->GetCreature(uiRohash))
                            {
                                SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, Rohash);
                                Rohash->Respawn(true);
                            }
                            break;

                        case DONE:

                            bool achievementReadytoGet = CheckAchivementStayChill();

                            if (Creature* Anshal = instance->GetCreature(uiAnshal))
                            {
                                Anshal->LowerPlayerDamageReq(Anshal->GetMaxHealth());
                                SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, Anshal);
                                if (Anshal->IsAlive())
                                {
                                    if (achievementReadytoGet == true)
                                        Anshal->CastSpell(Anshal, SPELL_STAY_CHILL_ACHIEVEMENT_CREDIT, true);
                                    if (Player* pPlayer = Anshal->SelectNearestPlayer(1000))
                                        pPlayer->DealDamage(Anshal, Anshal->GetHealth());
                                }
                            }
                            if (Creature* Nezir = instance->GetCreature(uiNezir))
                            {
                                Nezir->LowerPlayerDamageReq(Nezir->GetMaxHealth());
                                SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, Nezir);
                                if (Nezir->IsAlive())
                                {
                                    if (achievementReadytoGet == true)
                                        Nezir->CastSpell(Nezir, SPELL_STAY_CHILL_ACHIEVEMENT_CREDIT, true);
                                    if (Player* pPlayer = Nezir->SelectNearestPlayer(1000))
                                        pPlayer->DealDamage(Nezir, Nezir->GetHealth());
                                }
                            }
                            if (Creature* Rohash = instance->GetCreature(uiRohash))
                            {
                                Rohash->LowerPlayerDamageReq(Rohash->GetMaxHealth());
                                SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, Rohash);
                                if (Rohash->IsAlive())
                                {
                                    if (achievementReadytoGet == true)
                                        Rohash->CastSpell(Rohash, SPELL_STAY_CHILL_ACHIEVEMENT_CREDIT, true);
                                    if (Player* pPlayer = Rohash->SelectNearestPlayer(1000))
                                        pPlayer->DealDamage(Rohash, Rohash->GetHealth());
                                }
                            }
                            SummonSplistreamAlakir();

                            break;
                    }
                    Encounter[0] = data;
                    break;
                case DATA_ALAKIR_EVENT:
                    switch (data)
                    {
                        case DONE:
                            DoRespawnGameObject(HeartOfWindGUID, 7*DAY);

                            Map::PlayerList const &players = instance->GetPlayers();
                            if (players.isEmpty())
                                break;
                            for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
                            {
                                if (Player* player = i->GetSource())
                                {
                                    player->GetAchievementMgr()->UpdateCriteria(CRITERIA_TYPE_KILL_CREATURE, 46753, 1);
                                    player->ModifyCurrency(396, 70 * CURRENCY_PRECISION);
                                }
                            }
                            break;
                    }
                    Encounter[1] = data;
                    break;
                case DATA_WEATHER_EVENT:
                    WeatherData = data;
                    break;
                case DATA_ALAKIR_FLIGHT_PHASE:
                    if (data == NOT_STARTED)
                    {
                        if (GameObject* go1 = instance->GetGameObject(AnshalPlatform))
                        if (GameObject* go2 = instance->GetGameObject(NezirPlatform))
                        if (GameObject* go3 = instance->GetGameObject(RohashPlatform))
                        if (GameObject* go4 = instance->GetGameObject(SkyWallRaid))
                        {
                            go1->SetGoState(GO_STATE_READY);
                            go2->SetGoState(GO_STATE_READY);
                            go3->SetGoState(GO_STATE_READY);
                            go4->SetGoState(GO_STATE_READY);
                        }
                    }

                    if (data == IN_PROGRESS)
                    {
                        if (GameObject* go = instance->GetGameObject(SkyWallRaid))
                            go->SetDestructibleState(GO_DESTRUCTIBLE_DESTROYED);
                    }

                    if (data == FAIL)
                    {
                        if (GameObject* go = instance->GetGameObject(SkyWallRaid))
                            go->SetDestructibleState(GO_DESTRUCTIBLE_REBUILDING);
                    }

                    if (data == DONE)
                    {
                        if (GameObject* go = instance->GetGameObject(SkyWallWind))
                            go->Delete();
                    }
                    AlakirFlightData = data;
                    break;
            }

            if (data == DONE)
                SaveToDB();

            if (data == IN_PROGRESS)
            {
                if (Creature* Anshal = instance->GetCreature(uiAnshal))
                    Anshal->RemoveAura(SPELL_PRE_COMBAT_EFFECT_ANSHAL);

                if (Creature* Nezir = instance->GetCreature(uiNezir))
                    Nezir->RemoveAura(SPELL_PRE_COMBAT_EFFECT_NEZIR);

                if (Creature* Rohash = instance->GetCreature(uiRohash))
                    Rohash->RemoveAura(SPELL_PRE_COMBAT_EFFECT_ROHASH);

            }
            else if (data == FAIL || data == NOT_STARTED)
            {
                if (Creature* Anshal = instance->GetCreature(uiAnshal))
                    if (!Anshal->HasAura(SPELL_PRE_COMBAT_EFFECT_ANSHAL))
                        Anshal->CastSpell(Anshal, SPELL_PRE_COMBAT_EFFECT_ANSHAL, true);

                if (Creature* Nezir = instance->GetCreature(uiNezir))
                    if (!Nezir->HasAura(SPELL_PRE_COMBAT_EFFECT_NEZIR))
                        Nezir->CastSpell(Nezir, SPELL_PRE_COMBAT_EFFECT_NEZIR, true);

                if (Creature* Rohash = instance->GetCreature(uiRohash))
                    if (!Rohash->HasAura(SPELL_PRE_COMBAT_EFFECT_ROHASH))
                        Rohash->CastSpell(Rohash, SPELL_PRE_COMBAT_EFFECT_ROHASH, true);
            }
        }

        bool SetBossState(uint32 id, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(id, state))
                return false;

            return true;
        }

        uint32 GetData(uint32 type) const override 
        {
            switch (type)
            {
                case DATA_CONCLAVE_OF_WIND_EVENT:
                    return Encounter[0];
                case DATA_ALAKIR_EVENT:
                    return Encounter[1];
                case DATA_GATHERING_STRENGTH:
                    return GatheringStrength;
                case DATA_WEATHER_EVENT:
                    return WeatherData;
                case DATA_ALAKIR_FLIGHT_PHASE:
                    return AlakirFlightData;
            }
            return 0;
        }

        bool CheckAchivementStayChill()
        {
            uint32 spellid = GetSpellWindChill();
            Map::PlayerList const& players = instance->GetPlayers();
            if (!players.isEmpty())
            {
                for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
                {
                    if (Player* player = i->GetSource())
                    {
                        if (Aura *aur = player->GetAura(spellid))
                        {
                            if (aur->GetStackAmount() < 7)
                                return false;
                        }
                        else
                            return false;
                    }
                }
                return true;
            }
            return false;
        }

        uint32 GetSpellWindChill()
        {
            switch(instance->GetDifficultyID())
            {
                case DIFFICULTY_10_N:
                    return SPELL_WIND_CHILL_10;
                case DIFFICULTY_25_N:
                    return SPELL_WIND_CHILL_25;
                case DIFFICULTY_10_HC:
                    return SPELL_WIND_CHILL_10H;
                case DIFFICULTY_25_HC:
                    return SPELL_WIND_CHILL_25H;
                default:
                    break;
            }
            return 0;
        }

        void SummonSplistreamAlakir()
        {
            for (int i=0; i<4; ++i)
                instance->SummonCreature(NPC_SLIPSTREAM_ALAKIR, AlakirSlipstreamPositions[i]);
        }

    };
};

class AreaTrigger_at_return_wind : public AreaTriggerScript
{
    public:

        AreaTrigger_at_return_wind()
            : AreaTriggerScript("at_return_wind") {}

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/, bool /*entered*/) override
        {
            InstanceScript* instance = player->GetInstanceScript();
            if (instance)
            {
                if (player->IsAlive())
                {
                    if (instance->GetData(DATA_ALAKIR_EVENT) != IN_PROGRESS)
                    {
                        float smallestDist = player->GetDistance2d(GoBackPositions[0].GetPositionX(), GoBackPositions[0].GetPositionY());
                        int PointToGo = 0;
                        for (int i = 0; i < 8; i++)
                        {
                            float distance = player->GetDistance2d(GoBackPositions[i].GetPositionX(), GoBackPositions[i].GetPositionY());
                            if (distance < smallestDist)
                            {
                                smallestDist = distance;
                                PointToGo = i;
                            }
                        }
                        player->GetMotionMaster()->MoveJump(GoBackPositions[PointToGo], 50, 10);
                        player->AddAura(SPELL_SLIPSTREAM_BUFF, player);
                        player->AddAura(SPELL_SLIPSTREAM_PLAYER_VISUAL, player);
                    }
                    else if (instance->GetData(DATA_ALAKIR_EVENT) == IN_PROGRESS && (instance->GetData(DATA_ALAKIR_FLIGHT_PHASE) == NOT_STARTED || instance->GetData(DATA_ALAKIR_FLIGHT_PHASE) == FAIL))
                    {
                        if (player->HasAura(SPELL_RELENTLESS_STORM_VISUAL))
                            return false;

                        player->CastSpell(player, SPELL_RELENTLESS_STORM_VISUAL, true);
                        float speedFly = (210.0f - player->GetPositionZ()) / 15;
                        player->GetMotionMaster()->MoveJump(player->GetPositionX(), player->GetPositionY(), 220.0f, speedFly, speedFly);
                    }
                }
            }

        return true;
        }
};

void AddSC_instance_throne_of_the_four_winds()
{
    new instance_throne_of_the_four_winds();
    new AreaTrigger_at_return_wind();
}
