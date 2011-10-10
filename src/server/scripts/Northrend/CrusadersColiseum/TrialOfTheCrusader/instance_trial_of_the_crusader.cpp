/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: instance_trial_of_the_crusader
SD%Complete: 80%
SDComment: by /dev/rsa
SDCategory: Trial of the Crusader
EndScriptData */

#include "ScriptPCH.h"
#include "trial_of_the_crusader.h"

class instance_trial_of_the_crusader : public InstanceMapScript
{
    public:
        instance_trial_of_the_crusader() : InstanceMapScript("instance_trial_of_the_crusader", 649) { }

        struct instance_trial_of_the_crusader_InstanceMapScript : public InstanceScript
        {
            instance_trial_of_the_crusader_InstanceMapScript(Map* map) : InstanceScript(map) {}

            uint32 EncounterStatus[MAX_ENCOUNTERS];
            uint32 TrialCounter;
            uint32 EventStage;
            uint32 EventTimer;
            uint32 EventNPCId;
            uint32 NorthrendBeasts;
            std::string SaveDataBuffer;
            bool   NeedSave;

            uint64 BarrentGUID;
            uint64 TirionGUID;
            uint64 FizzlebangGUID;
            uint64 GarroshGUID;
            uint64 VarianGUID;

            uint64 GormokGUID;
            uint64 AcidmawGUID;
            uint64 DreadscaleGUID;
            uint64 IcehowlGUID;
            uint64 JaraxxusGUID;
            uint64 ChampionsControllerGUID;
            uint64 DarkbaneGUID;
            uint64 LightbaneGUID;
            uint64 AnubarakGUID;

            uint64 CrusadersCacheGUID;
            uint64 FloorGUID;

            uint64 TributeChestGUID;

            uint64 MainGateDoorGUID;
            uint64 EastPortcullisGUID;
            uint64 WebDoorGUID;

            // Achievement stuff
            uint32 NotOneButTwoJormungarsTimer;
            uint32 ResilienceWillFixItTimer;
            uint8  SnoboldCount;
            uint8  MistressOfPainCount;
            bool   TributeToImmortalityElegible;

            void Initialize()
            {
                for (uint8 i = 0; i < MAX_ENCOUNTERS; ++i)
                    EncounterStatus[i] = NOT_STARTED;

                TrialCounter = 50;
                EventStage = 0;

                TributeChestGUID = 0;

                MainGateDoorGUID = 0;
                EastPortcullisGUID = 0;
                WebDoorGUID = 0;

                NorthrendBeasts = NOT_STARTED;

                EventTimer = 1000;

                NotOneButTwoJormungarsTimer = 0;
                ResilienceWillFixItTimer = 0;
                SnoboldCount = 0;
                MistressOfPainCount = 0;
                TributeToImmortalityElegible = true;

                NeedSave = false;
            }

            bool IsEncounterInProgress() const
            {
                for (uint8 i = 0; i < MAX_ENCOUNTERS ; ++i)
                    if (EncounterStatus[i] == IN_PROGRESS)
                        return true;
                return false;
            }

            void OnPlayerEnter(Player* player)
            {
                if (instance->IsHeroic())
                {
                    player->SendUpdateWorldState(UPDATE_STATE_UI_SHOW, 1);
                    player->SendUpdateWorldState(UPDATE_STATE_UI_COUNT, GetData(TYPE_COUNTER));
                }
            }

            void OpenDoor(uint64 guid)
            {
                if (!guid)
                    return;
                if (GameObject* go = instance->GetGameObject(guid))
                    go->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
            }

            void CloseDoor(uint64 guid)
            {
                if (!guid)
                    return;
                if (GameObject* go = instance->GetGameObject(guid))
                    go->SetGoState(GO_STATE_READY);
            }

            void OnCreatureCreate(Creature* creature)
            {
                switch (creature->GetEntry())
                {
                    case NPC_BARRENT:
                        BarrentGUID = creature->GetGUID();
                        break;
                    case NPC_TIRION:
                        TirionGUID = creature->GetGUID();
                        break;
                    case NPC_FIZZLEBANG:
                        FizzlebangGUID = creature->GetGUID();
                        break;
                    case NPC_GARROSH:
                        GarroshGUID = creature->GetGUID();
                        break;
                    case NPC_VARIAN:
                        VarianGUID = creature->GetGUID();
                        break;

                    case NPC_GORMOK:
                        GormokGUID = creature->GetGUID();
                        break;
                    case NPC_ACIDMAW:
                        AcidmawGUID = creature->GetGUID();
                        break;
                    case NPC_DREADSCALE:
                        DreadscaleGUID = creature->GetGUID();
                        break;
                    case NPC_ICEHOWL:
                        IcehowlGUID = creature->GetGUID();
                        break;
                    case NPC_JARAXXUS:
                        JaraxxusGUID = creature->GetGUID();
                        break;
                    case NPC_CHAMPIONS_CONTROLLER:
                        ChampionsControllerGUID = creature->GetGUID();
                        break;
                    case NPC_DARKBANE:
                        DarkbaneGUID = creature->GetGUID();
                        break;
                    case NPC_LIGHTBANE:
                        LightbaneGUID = creature->GetGUID();
                        break;
                    case NPC_ANUBARAK:
                        AnubarakGUID = creature->GetGUID();
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go)
            {
                switch (go->GetEntry())
                {
                    case GO_CRUSADERS_CACHE_10:
                        if (instance->GetSpawnMode() == RAID_DIFFICULTY_10MAN_NORMAL)
                            CrusadersCacheGUID = go->GetGUID();
                        break;
                    case GO_CRUSADERS_CACHE_25:
                        if (instance->GetSpawnMode() == RAID_DIFFICULTY_25MAN_NORMAL)
                            CrusadersCacheGUID = go->GetGUID();
                        break;
                    case GO_CRUSADERS_CACHE_10_H:
                        if (instance->GetSpawnMode() == RAID_DIFFICULTY_10MAN_HEROIC)
                            CrusadersCacheGUID = go->GetGUID();
                        break;
                    case GO_CRUSADERS_CACHE_25_H:
                        if (instance->GetSpawnMode() == RAID_DIFFICULTY_25MAN_HEROIC)
                            CrusadersCacheGUID = go->GetGUID();
                        break;
                    case GO_ARGENT_COLISEUM_FLOOR:
                        FloorGUID = go->GetGUID();
                        break;
                    case GO_MAIN_GATE_DOOR:
                        MainGateDoorGUID = go->GetGUID();
                        break;
                    case GO_EAST_PORTCULLIS:
                        EastPortcullisGUID = go->GetGUID();
                        break;
                    case GO_WEB_DOOR:
                        WebDoorGUID = go->GetGUID();
                        break;

                    case GO_TRIBUTE_CHEST_10H_25:
                    case GO_TRIBUTE_CHEST_10H_45:
                    case GO_TRIBUTE_CHEST_10H_50:
                    case GO_TRIBUTE_CHEST_10H_99:
                    case GO_TRIBUTE_CHEST_25H_25:
                    case GO_TRIBUTE_CHEST_25H_45:
                    case GO_TRIBUTE_CHEST_25H_50:
                    case GO_TRIBUTE_CHEST_25H_99:
                        TributeChestGUID = go->GetGUID();
                        break;
                }
            }

            void SetData(uint32 type, uint32 data)
            {
                switch (type)
                {
                    case TYPE_JARAXXUS:
                        if (data == DONE)
                            EventStage = 2000;
                        break;
                    case TYPE_CRUSADERS:
                        switch (data)
                        {
                            case IN_PROGRESS:
                                ResilienceWillFixItTimer = 0;
                                break;
                            case SPECIAL: //Means the first blood
                                ResilienceWillFixItTimer = 60*IN_MILLISECONDS;
                                data = IN_PROGRESS;
                                break;
                            case DONE:
                                DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_DEFEAT_FACTION_CHAMPIONS);
                                if (ResilienceWillFixItTimer > 0)
                                    DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_CHAMPIONS_KILLED_IN_MINUTE);
                                DoRespawnGameObject(CrusadersCacheGUID, 7*DAY);
                                EventStage = 3100;
                                break;
                        }
                        break;
                    case TYPE_VALKIRIES:
                        switch (data)
                        {
                            case FAIL:
                                if (EncounterStatus[TYPE_VALKIRIES] == NOT_STARTED)
                                    data = NOT_STARTED;
                                break;
                            case SPECIAL:
                                if (EncounterStatus[TYPE_VALKIRIES] == SPECIAL)
                                    data = DONE;
                                break;
                            case DONE:
                                if (instance->GetPlayers().getFirst()->getSource()->GetTeam() == ALLIANCE)
                                    EventStage = 4020;
                                else
                                    EventStage = 4030;
                                break;
                        }
                        break;
                    case TYPE_ANUBARAK:
                        switch (data)
                        {
                            case DONE:
                                EventStage = 6000;
                                break;
                            case SPECIAL:
                                uint32 tributeChest = 0;
                                if (instance->GetSpawnMode() == RAID_DIFFICULTY_10MAN_HEROIC)
                                {
                                    if (TrialCounter >= 50)
                                        tributeChest = GO_TRIBUTE_CHEST_10H_99;
                                    else
                                        if (TrialCounter >= 45)
                                            tributeChest = GO_TRIBUTE_CHEST_10H_50;
                                        else
                                            if (TrialCounter >= 25)
                                                tributeChest = GO_TRIBUTE_CHEST_10H_45;
                                            else
                                                tributeChest = GO_TRIBUTE_CHEST_10H_25;
                                }
                                else if (instance->GetSpawnMode() == RAID_DIFFICULTY_25MAN_HEROIC)
                                {
                                    if (TrialCounter >= 50)
                                        tributeChest = GO_TRIBUTE_CHEST_25H_99;
                                    else
                                        if (TrialCounter >= 45)
                                            tributeChest = GO_TRIBUTE_CHEST_25H_50;
                                        else
                                            if (TrialCounter >= 25)
                                                tributeChest = GO_TRIBUTE_CHEST_25H_45;
                                            else
                                                tributeChest = GO_TRIBUTE_CHEST_25H_25;
                                }
                                if (tributeChest)
                                    if (Creature* tirion =  instance->GetCreature(TirionGUID))
                                        if (GameObject* chest = tirion->SummonGameObject(tributeChest, 805.62f, 134.87f, 142.16f, 3.27f, 0, 0, 0, 0, 90000000))
                                            chest->SetRespawnTime(chest->GetRespawnDelay());
                                break;
                        }
                        break;
                    case TYPE_COUNTER:
                        TrialCounter = data;
                        data = DONE;
                        break;
                    case TYPE_EVENT:
                        EventStage = data;
                        data = NOT_STARTED;
                        break;
                    case TYPE_EVENT_TIMER:
                        EventTimer = data;
                        data = NOT_STARTED;
                        break;
                    case TYPE_NORTHREND_BEASTS:
                        NorthrendBeasts = data;
                        switch (data)
                        {
                            case GORMOK_DONE:
                                EventStage = 200;
                                SetData(TYPE_NORTHREND_BEASTS, IN_PROGRESS);
                                SetData(TYPE_BEASTS, IN_PROGRESS);
                                break;
                            case SNAKES_IN_PROGRESS:
                                NotOneButTwoJormungarsTimer = 0;
                                break;
                            case SNAKES_SPECIAL:
                                NotOneButTwoJormungarsTimer = 10*IN_MILLISECONDS;
                                break;
                            case SNAKES_DONE:
                                if (NotOneButTwoJormungarsTimer > 0)
                                    DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_WORMS_KILLED_IN_10_SECONDS);
                                EventStage = 300;
                                SetData(TYPE_NORTHREND_BEASTS, IN_PROGRESS);
                                SetData(TYPE_BEASTS, IN_PROGRESS);
                                break;
                            case ICEHOWL_DONE:
                                EventStage = 400;
                                SetData(TYPE_NORTHREND_BEASTS, DONE);
                                SetData(TYPE_BEASTS, DONE);
                                break;
                            case FAIL:
                                SetData(TYPE_BEASTS, FAIL);
                                break;
                        }
                        break;
                    //Achievements
                    case DATA_SNOBOLD_COUNT:
                        if (data == INCREASE)
                            ++SnoboldCount;
                        else if (data == DECREASE)
                            --SnoboldCount;
                        break;
                    case DATA_MISTRESS_OF_PAIN_COUNT:
                        if (data == INCREASE)
                            ++MistressOfPainCount;
                        else if (data == DECREASE)
                            --MistressOfPainCount;
                        break;
                    case DATA_TRIBUTE_TO_IMMORTALITY_ELEGIBLE:
                        TributeToImmortalityElegible = false;
                        break;
                }
                if (IsEncounterInProgress())
                {
                    CloseDoor(GetData64(GO_EAST_PORTCULLIS));
                    CloseDoor(GetData64(GO_WEB_DOOR));
                }
                else
                {
                    OpenDoor(GetData64(GO_EAST_PORTCULLIS));
                    OpenDoor(GetData64(GO_WEB_DOOR));
                }

                if (type < MAX_ENCOUNTERS)
                {
                    sLog->outDetail("[ToCr] EncounterStatus[type %u] %u = data %u;", type, EncounterStatus[type], data);
                    if (data == FAIL)
                    {
                        --TrialCounter;
                        NeedSave = true;
                        EventStage = (type == TYPE_BEASTS ? 666 : 0);
                        data = NOT_STARTED;
                    }

                    EncounterStatus[type] = data;

                    if (data == DONE || NeedSave == true)
                    {
                        if (Unit* announcer = instance->GetCreature(GetData64(NPC_BARRENT)))
                            announcer->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                        Save();
                    }
                }
            }

            uint64 GetData64(uint32 type)
            {
                switch (type)
                {
                    case NPC_BARRENT:
                        return BarrentGUID;
                    case NPC_TIRION:
                        return TirionGUID;
                    case NPC_FIZZLEBANG:
                        return FizzlebangGUID;
                    case NPC_GARROSH:
                        return GarroshGUID;
                    case NPC_VARIAN:
                        return VarianGUID;

                    case NPC_GORMOK:
                        return GormokGUID;
                    case NPC_ACIDMAW:
                        return AcidmawGUID;
                    case NPC_DREADSCALE:
                        return DreadscaleGUID;
                    case NPC_ICEHOWL:
                        return IcehowlGUID;
                    case NPC_JARAXXUS:
                        return JaraxxusGUID;
                    case NPC_CHAMPIONS_CONTROLLER:
                        return ChampionsControllerGUID;
                    case NPC_DARKBANE:
                        return DarkbaneGUID;
                    case NPC_LIGHTBANE:
                        return LightbaneGUID;
                    case NPC_ANUBARAK:
                        return AnubarakGUID;

                    case GO_ARGENT_COLISEUM_FLOOR:
                        return FloorGUID;
                    case GO_MAIN_GATE_DOOR:
                        return MainGateDoorGUID;
                    case GO_EAST_PORTCULLIS:
                        return EastPortcullisGUID;
                    case GO_WEB_DOOR:
                        return WebDoorGUID;
                    default:
                        break;
                }

                return 0;
            }

            uint32 GetData(uint32 type)
            {
                switch (type)
                {
                    case TYPE_BEASTS:
                        return EncounterStatus[TYPE_BEASTS];
                    case TYPE_JARAXXUS:
                        return EncounterStatus[TYPE_JARAXXUS];
                    case TYPE_CRUSADERS:
                        return EncounterStatus[TYPE_CRUSADERS];
                    case TYPE_VALKIRIES:
                        return EncounterStatus[TYPE_VALKIRIES];
                    case TYPE_LICH_KING:
                        return EncounterStatus[TYPE_LICH_KING];
                    case TYPE_ANUBARAK:
                        return EncounterStatus[TYPE_ANUBARAK];
                    case TYPE_COUNTER:
                        return TrialCounter;
                    case TYPE_EVENT:
                        return EventStage;
                    case TYPE_NORTHREND_BEASTS:
                        return NorthrendBeasts;
                    case TYPE_EVENT_TIMER:
                        return EventTimer;
                    case TYPE_EVENT_NPC:
                        switch (EventStage)
                        {
                            case 110:
                            case 140:
                            case 150:
                            case 155:
                            case 200:
                            case 205:
                            case 210:
                            case 220:
                            case 300:
                            case 305:
                            case 310:
                            case 315:
                            case 400:
                            case 666:
                            case 1010:
                            case 1180:
                            case 2000:
                            case 2030:
                            case 3000:
                            case 3001:
                            case 3060:
                            case 3061:
                            case 3090:
                            case 3091:
                            case 3092:
                            case 3100:
                            case 3110:
                            case 4000:
                            case 4010:
                            case 4015:
                            case 4016:
                            case 4040:
                            case 4050:
                            case 5000:
                            case 5005:
                            case 5020:
                            case 6000:
                            case 6005:
                            case 6010:
                                EventNPCId = NPC_TIRION;
                                break;
                            case 5010:
                            case 5030:
                            case 5040:
                            case 5050:
                            case 5060:
                            case 5070:
                            case 5080:
                                EventNPCId = NPC_LICH_KING_1;
                                break;
                            case 120:
                            case 122:
                            case 2020:
                            case 3080:
                            case 3051:
                            case 3071:
                            case 4020:
                                EventNPCId = NPC_VARIAN;
                                break;
                            case 130:
                            case 132:
                            case 2010:
                            case 3050:
                            case 3070:
                            case 3081:
                            case 4030:
                                EventNPCId = NPC_GARROSH;
                                break;
                            case 1110:
                            case 1120:
                            case 1130:
                            case 1132:
                            case 1134:
                            case 1135:
                            case 1140:
                            case 1142:
                            case 1144:
                            case 1150:
                                EventNPCId = NPC_FIZZLEBANG;
                                break;
                            default:
                                EventNPCId = NPC_TIRION;
                                break;
                        };
                        return EventNPCId;
                    default:
                        break;
                }

                return 0;
            }

            void Update(uint32 diff)
            {
                if (GetData(TYPE_NORTHREND_BEASTS) == SNAKES_SPECIAL && NotOneButTwoJormungarsTimer)
                {
                    if (NotOneButTwoJormungarsTimer <= diff)
                        NotOneButTwoJormungarsTimer = 0;
                    else
                        NotOneButTwoJormungarsTimer -= diff;
                }

                if (GetData(TYPE_CRUSADERS) == IN_PROGRESS && ResilienceWillFixItTimer)
                {
                    if (ResilienceWillFixItTimer <= diff)
                        ResilienceWillFixItTimer = 0;
                    else
                        ResilienceWillFixItTimer -= diff;
                }
            }

            void Save()
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;

                for (uint8 i = 0; i < MAX_ENCOUNTERS; ++i)
                    saveStream << EncounterStatus[i] << ' ';

                saveStream << TrialCounter;
                SaveDataBuffer = saveStream.str();

                SaveToDB();
                OUT_SAVE_INST_DATA_COMPLETE;
                NeedSave = false;
            }

            std::string GetSaveData()
            {
                return SaveDataBuffer;
            }

            void Load(const char* strIn)
            {
                if (!strIn)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }

                OUT_LOAD_INST_DATA(strIn);

                std::istringstream loadStream(strIn);

                for (uint8 i = 0; i < MAX_ENCOUNTERS; ++i)
                {
                    loadStream >> EncounterStatus[i];

                    if (EncounterStatus[i] == IN_PROGRESS)
                        EncounterStatus[i] = NOT_STARTED;
                }

                loadStream >> TrialCounter;
                EventStage = 0;

                OUT_LOAD_INST_DATA_COMPLETE;
            }

            bool CheckAchievementCriteriaMeet(uint32 criteria_id, Player const* /*source*/, Unit const* /*target*/, uint32 /*miscvalue1*/)
            {
                switch (criteria_id)
                {
                    case UPPER_BACK_PAIN_10_PLAYER:
                    case UPPER_BACK_PAIN_10_PLAYER_HEROIC:
                        return SnoboldCount >= 2;
                    case UPPER_BACK_PAIN_25_PLAYER:
                    case UPPER_BACK_PAIN_25_PLAYER_HEROIC:
                        return SnoboldCount >= 4;
                    case THREE_SIXTY_PAIN_SPIKE_10_PLAYER:
                    case THREE_SIXTY_PAIN_SPIKE_10_PLAYER_HEROIC:
                    case THREE_SIXTY_PAIN_SPIKE_25_PLAYER:
                    case THREE_SIXTY_PAIN_SPIKE_25_PLAYER_HEROIC:
                        return MistressOfPainCount >= 2;
                    case A_TRIBUTE_TO_SKILL_10_PLAYER:
                    case A_TRIBUTE_TO_SKILL_25_PLAYER:
                        return TrialCounter >= 25;
                    case A_TRIBUTE_TO_MAD_SKILL_10_PLAYER:
                    case A_TRIBUTE_TO_MAD_SKILL_25_PLAYER:
                        return TrialCounter >= 45;
                    case A_TRIBUTE_TO_INSANITY_10_PLAYER:
                    case A_TRIBUTE_TO_INSANITY_25_PLAYER:
                    case REALM_FIRST_GRAND_CRUSADER:
                        return TrialCounter == 50;
                    case A_TRIBUTE_TO_IMMORTALITY_HORDE:
                    case A_TRIBUTE_TO_IMMORTALITY_ALLIANCE:
                        return TrialCounter == 50 && TributeToImmortalityElegible;
                    case A_TRIBUTE_TO_DEDICATED_INSANITY:
                        return false/*uiGrandCrusaderAttemptsLeft == 50 && !bHasAtAnyStagePlayerEquippedTooGoodItem*/;
                }

                return false;
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_trial_of_the_crusader_InstanceMapScript(map);
        }
};

void AddSC_instance_trial_of_the_crusader()
{
    new instance_trial_of_the_crusader();
}
