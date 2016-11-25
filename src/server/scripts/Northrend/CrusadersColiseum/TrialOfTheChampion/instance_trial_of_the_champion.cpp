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

/* ScriptData
SDName: Instance Trial of the Champion
SDComment:
SDCategory: Trial Of the Champion
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "InstanceScript.h"
#include "trial_of_the_champion.h"
#include "Player.h"

class instance_trial_of_the_champion : public InstanceMapScript
{
public:
    instance_trial_of_the_champion() : InstanceMapScript("instance_trial_of_the_champion", 650) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_trial_of_the_champion_InstanceMapScript(map);
    }

    struct instance_trial_of_the_champion_InstanceMapScript : public InstanceScript
    {
        instance_trial_of_the_champion_InstanceMapScript(Map* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            uiMovementDone = 0;
            uiGrandChampionsDeaths = 3;
            uiArgentSoldierDeaths = 0;
            uiChampMountsDeaths = 3;
            TeamInInstance = 0;
            grandChampionEntry = 0;
            memoryEntry = 0;

            achievementHadWorse = true;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            if (!TeamInInstance)
            {
                Map::PlayerList const &players = instance->GetPlayers();
                if (!players.isEmpty())
                    if (Player* player = players.begin()->GetSource())
                        TeamInInstance = player->GetTeam();
            }

            switch (creature->GetEntry())
            {
                // Champions mount
                case VEHICLE_MOKRA_SKILLCRUSHER_MOUNT:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_MARSHAL_JACOB_ALERIUS_MOUNT);
                    break;
                case VEHICLE_ERESSEA_DAWNSINGER_MOUNT:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_AMBROSE_BOLTSPARK_MOUNT);
                    break;
                case VEHICLE_RUNOK_WILDMANE_MOUNT:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_COLOSOS_MOUNT);
                    break;
                case VEHICLE_ZUL_TORE_MOUNT:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_EVENSONG_MOUNT);
                    break;
                case VEHICLE_DEATHSTALKER_VESCERI_MOUNT:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_LANA_STOUTHAMMER_MOUNT);
                    break;
                //
                case VEHICLE_FORSAKE_WARHORSE:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_IRONFORGE_RAM);
                    break;
                case VEHICLE_THUNDER_BLUFF_KODO:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_EXODAR_ELEKK);
                    break;
                case VEHICLE_ORGRIMMAR_WOLF:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_STORMWIND_STEED);
                    break;
                case VEHICLE_SILVERMOON_HAWKSTRIDER:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_GNOMEREGAN_MECHANOSTRIDER);
                    break;
                case VEHICLE_DARKSPEAR_RAPTOR:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_DARNASSIA_NIGHTSABER);
                    break;
                // Grand champions
                case NPC_MOKRA:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_JACOB);
                    break;
                case NPC_ERESSEA:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_AMBROSE);
                    break;
                case NPC_RUNOK:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_COLOSOS);
                    break;
                case NPC_ZULTORE:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_JAELYNE);
                    break;
                case NPC_VISCERI:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_LANA);
                    break;
                // Coliseum Announcer || Just NPC_JAEREN must be spawned.
                case NPC_JAEREN:
                    uiAnnouncerGUID = creature->GetGUID();
                    if (TeamInInstance == ALLIANCE)
                        creature->UpdateEntry(NPC_ARELAS);
                    break;
                case VEHICLE_ARGENT_WARHORSE:
                case VEHICLE_ARGENT_BATTLEWORG:
                    VehicleList.push_back(creature->GetGUID());
                    break;
                case NPC_EADRIC:
                case NPC_PALETRESS:
                    uiArgentChampionGUID = creature->GetGUID();
                    break;
                // Talkers
                case NPC_TIRION:
                    uiTirionGUID = creature->GetGUID();
                    break;
                case NPC_THRALL:
                    uiThrallGUID = creature->GetGUID();
                    break;
                case NPC_GARROSH:
                    uiGarroshGUID = creature->GetGUID();
                    break;
                case NPC_VARIAN:
                    uiVarianGUID = creature->GetGUID();
                    break;
                case NPC_JAINA:
                    uiJainaGUID = creature->GetGUID();
                    break;
                case NPC_BLACK_KNIGHT:
                    uiKnightGUID = creature->GetGUID();
                    break;
            }
        }

        void OnUnitDeath(Unit* unit) override
        {
            Creature* creature = unit->ToCreature();
            if (!creature)
                return;
            
            switch (creature->GetEntry())
            {
            case VEHICLE_MARSHAL_JACOB_ALERIUS_MOUNT:
            case VEHICLE_AMBROSE_BOLTSPARK_MOUNT:
            case VEHICLE_COLOSOS_MOUNT:
            case VEHICLE_EVENSONG_MOUNT:
            case VEHICLE_LANA_STOUTHAMMER_MOUNT:
            case VEHICLE_MOKRA_SKILLCRUSHER_MOUNT:
            case VEHICLE_ERESSEA_DAWNSINGER_MOUNT:
            case VEHICLE_RUNOK_WILDMANE_MOUNT:
            case VEHICLE_ZUL_TORE_MOUNT:
            case VEHICLE_DEATHSTALKER_VESCERI_MOUNT:
                uiChampMountsDeaths--;
                if (!uiChampMountsDeaths)
                {
                    Creature* champion1 = instance->GetCreature(uiGrandChampion1GUID);
                    Creature* champion2 = instance->GetCreature(uiGrandChampion2GUID);
                    Creature* champion3 = instance->GetCreature(uiGrandChampion3GUID);
                    if (champion1 && champion2 && champion2)
                    {
                        champion1->AI()->DoAction(1);
                        champion2->AI()->DoAction(1);
                        champion3->AI()->DoAction(1);
                        
                        for (GuidList::const_iterator itr = VehicleList.begin(); itr != VehicleList.end(); ++itr)
                            if (Creature* vehicles = instance->GetCreature(*itr))
                                vehicles->DespawnOrUnsummon();
                    }
                    DoRemoveAurasDueToSpellOnPlayers(66482); // Defender
                }
                break;
            default:
                break;
            }
        }
        
        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case GO_MAIN_GATE:
                    uiMainGateGUID = go->GetGUID();
                    break;
                case GO_CHAMPIONS_LOOT:
                case GO_CHAMPIONS_LOOT_H:
                    uiChampionLootGUID = go->GetGUID();
                    break;
            }
        }

        bool SetBossState(uint32 type, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            switch (type)
            {
            case BOSS_GRAND_CHAMPIONS:
                if (state == IN_PROGRESS)
                {
                    for (GuidList::const_iterator itr = VehicleList.begin(); itr != VehicleList.end(); ++itr)
                        if (Creature* summon = instance->GetCreature(*itr))
                            summon->RemoveFromWorld();
                }
                break;
            case BOSS_ARGENT_CHALLENGE_E:
                if (state == DONE)
                    if (Creature* pAnnouncer = instance->GetCreature(uiAnnouncerGUID))
                    {
                        DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_ACHIEVEMENT_EADRIC);
                        pAnnouncer->GetMotionMaster()->MovePoint(0, 748.309f, 619.487f, 411.171f);
                        pAnnouncer->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                        pAnnouncer->SummonGameObject(instance->IsHeroic() ? GO_EADRIC_LOOT_H : GO_EADRIC_LOOT, 746.59f, 618.49f, 411.09f, 1.42f, 0, 0, 0, 0, 90000);
                    }
                break;
            case BOSS_ARGENT_CHALLENGE_P:
                if (state == DONE)
                    if (Creature* pAnnouncer = instance->GetCreature(uiAnnouncerGUID))
                    {
                        DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_ACHIEVEMENT_PALETRESS);
                        DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_ACHIEVEMENT_MEMORIES);
                        pAnnouncer->GetMotionMaster()->MovePoint(0, 748.309f, 619.487f, 411.171f);
                        pAnnouncer->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                        pAnnouncer->SummonGameObject(instance->IsHeroic() ? GO_PALETRESS_LOOT_H : GO_PALETRESS_LOOT, 746.59f, 618.49f, 411.09f, 1.42f, 0, 0, 0, 0, 90000);
                    }
                break;
            case BOSS_BLACK_KNIGHT:
                if (state == DONE)
                    DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_ACHIEVEMENT_BLACK_KNIGHT);
                break;
            default:
                break;
            }
            return true;
        }

        void SetData(uint32 uiType, uint32 uiData) override
        {
            switch (uiType)
            {
                case DATA_MOVEMENT_DONE:
                    uiMovementDone = uiData;
                    if (uiMovementDone == 3)
                    {
                        if (Creature* pAnnouncer =  instance->GetCreature(uiAnnouncerGUID))
                            pAnnouncer->AI()->SetData(DATA_IN_POSITION, 0);
                    }
                    break;
                case DATA_ARGENT_SOLDIER_DEFEATED:
                    uiArgentSoldierDeaths = uiData;
                    if (uiArgentSoldierDeaths == 9)
                    {
                        if (Creature* pBoss =  instance->GetCreature(uiArgentChampionGUID))
                        {
                            pBoss->GetMotionMaster()->MovePoint(0, 746.88f, 618.74f, 411.06f);
                            pBoss->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            pBoss->SetReactState(REACT_AGGRESSIVE);
                        }
                    }
                    break;
                case DATA_GRAND_CHAMPION_ENTRY:
                    grandChampionEntry = uiData;
                    DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_ACHIEVEMENT_CHAMPIONS);
                    uiGrandChampionsDeaths--;
                    if (!uiGrandChampionsDeaths)
                    {
                        if (Creature* pAnnouncer = instance->GetCreature(uiAnnouncerGUID))
                        {
                            pAnnouncer->GetMotionMaster()->MovePoint(0, 748.309f, 619.487f, 411.171f);
                            pAnnouncer->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                            pAnnouncer->SummonGameObject(instance->IsHeroic() ? GO_CHAMPIONS_LOOT_H : GO_CHAMPIONS_LOOT, 746.59f, 618.49f, 411.09f, 1.42f, 0, 0, 0, 0, 90000);
                        }
                    }
                    break;
                case DATA_MEMORY_ENTRY:
                    memoryEntry = uiData;
                    break;
                case DATA_I_VE_HAD_WORSE:
                    achievementHadWorse = uiData ? true : false;
                    break;
            }

            if (uiData == DONE)
                SaveToDB();
        }

        uint32 GetData(uint32 uiData) const override
        {
            switch (uiData)
            {
                case DATA_MOVEMENT_DONE: return uiMovementDone;
                case DATA_ARGENT_SOLDIER_DEFEATED: return uiArgentSoldierDeaths;
                case DATA_TEAM_IN_INSTANCE: return TeamInInstance;
            }

            return 0;
        }

        ObjectGuid GetGuidData(uint32 uiData) const override
        {
            switch (uiData)
            {
                case DATA_ANNOUNCER: return uiAnnouncerGUID;
                case DATA_MAIN_GATE: return uiMainGateGUID;

                case DATA_GRAND_CHAMPION_1: return uiGrandChampion1GUID;
                case DATA_GRAND_CHAMPION_2: return uiGrandChampion2GUID;
                case DATA_GRAND_CHAMPION_3: return uiGrandChampion3GUID;
                case DATA_GRAND_CHAMPION_VEHICLE_1: return uiGrandChampionVehicle1GUID;
                case DATA_GRAND_CHAMPION_VEHICLE_2: return uiGrandChampionVehicle2GUID;
                case DATA_GRAND_CHAMPION_VEHICLE_3: return uiGrandChampionVehicle3GUID;
                case DATA_TIRION: return uiTirionGUID;
                case DATA_THRALL: return uiThrallGUID;
                case DATA_GARROSH: return uiGarroshGUID;
                case DATA_VARIAN: return uiVarianGUID;
                case DATA_JAINA: return uiJainaGUID;
                case DATA_BLACK_KNIGHT: return uiKnightGUID;
            }

            return ObjectGuid::Empty;
        }

        void SetGuidData(uint32 uiType, ObjectGuid uiData) override
        {
            switch (uiType)
            {
                case DATA_GRAND_CHAMPION_1:
                    uiGrandChampion1GUID = uiData;
                    break;
                case DATA_GRAND_CHAMPION_2:
                    uiGrandChampion2GUID = uiData;
                    break;
                case DATA_GRAND_CHAMPION_3:
                    uiGrandChampion3GUID = uiData;
                    break;
                case DATA_GRAND_CHAMPION_VEHICLE_1:
                    uiGrandChampionVehicle1GUID = uiData;
                    break;
                case DATA_GRAND_CHAMPION_VEHICLE_2:
                    uiGrandChampionVehicle2GUID = uiData;
                    break;
                case DATA_GRAND_CHAMPION_VEHICLE_3:
                    uiGrandChampionVehicle3GUID = uiData;
                    break;
            }
        }

        bool CheckAchievementCriteriaMeet(uint32 criteria_id, Player const* /*source*/, Unit const* /*target*/, uint32 /*miscvalue1*/)
        {
            switch (criteria_id)
            {
            case CRITERIA_CHAMPION_JACOB:
            case CRITERIA_CHAMPION_LANA:
            case CRITERIA_CHAMPION_COLOSOS:
            case CRITERIA_CHAMPION_AMBROSE:
            case CRITERIA_CHAMPION_JAELYNE:
            case CRITERIA_CHAMPION_MOKRA:
            case CRITERIA_CHAMPION_VISCERI:
            case CRITERIA_CHAMPION_RUNOK:
            case CRITERIA_CHAMPION_ERESSEA:
            case CRITERIA_CHAMPION_ZULTORE:
            case CRITERIA_CHAMPION_JACOB_H:
            case CRITERIA_CHAMPION_LANA_H:
            case CRITERIA_CHAMPION_COLOSOS_H:
            case CRITERIA_CHAMPION_AMBROSE_H:
            case CRITERIA_CHAMPION_JAELYNE_H:
            case CRITERIA_CHAMPION_MOKRA_H:
            case CRITERIA_CHAMPION_VISCERI_H:
            case CRITERIA_CHAMPION_RUNOK_H:
            case CRITERIA_CHAMPION_ERESSEA_H:
            case CRITERIA_CHAMPION_ZULTORE_H:
                if (grandChampionEntry == GetRelatedCreatureEntry(criteria_id))
                    return true;
                return false;
            case CRITERIA_MEMORY_HOGGER:
            case CRITERIA_MEMORY_VANCLEEF:
            case CRITERIA_MEMORY_MUTANUS:
            case CRITERIA_MEMORY_HEROD:
            case CRITERIA_MEMORY_LUCIFROM:
            case CRITERIA_MEMORY_THUNDERAAN:
            case CRITERIA_MEMORY_CHROMAGGUS:
            case CRITERIA_MEMORY_HAKKAR:
            case CRITERIA_MEMORY_VEKNILASH:
            case CRITERIA_MEMORY_KALITHRESH:
            case CRITERIA_MEMORY_MALCHEZAAR:
            case CRITERIA_MEMORY_GRUUL:
            case CRITERIA_MEMORY_VASHJ:
            case CRITERIA_MEMORY_ARCHIMONDE:
            case CRITERIA_MEMORY_ILLIDAN:
            case CRITERIA_MEMORY_DELRISSA:
            case CRITERIA_MEMORY_MURU:
            case CRITERIA_MEMORY_INGVAR:
            case CRITERIA_MEMORY_CYANIGOSA:
            case CRITERIA_MEMORY_ECK:
            case CRITERIA_MEMORY_ONYXIA:
            case CRITERIA_MEMORY_HEIGAN:
            case CRITERIA_MEMORY_IGNIS:
            case CRITERIA_MEMORY_VEZAX:
            case CRITERIA_MEMORY_ALGALON:
                return (memoryEntry == GetRelatedCreatureEntry(criteria_id));
            case CRITERIA_I_VE_HAD_WORSE:
                return achievementHadWorse;
            }

            return false;
        }
        
        uint32 GetRelatedCreatureEntry(uint32 criteria_id)
        {
            switch (criteria_id)
            {
            case CRITERIA_CHAMPION_JACOB:
            case CRITERIA_CHAMPION_JACOB_H:
                return NPC_JACOB;
            case CRITERIA_CHAMPION_LANA:
            case CRITERIA_CHAMPION_LANA_H:
                return NPC_LANA;
            case CRITERIA_CHAMPION_COLOSOS:
            case CRITERIA_CHAMPION_COLOSOS_H:
                return NPC_COLOSOS;
            case CRITERIA_CHAMPION_AMBROSE:
            case CRITERIA_CHAMPION_AMBROSE_H:
                return NPC_AMBROSE;
            case CRITERIA_CHAMPION_JAELYNE:
            case CRITERIA_CHAMPION_JAELYNE_H:
                return NPC_JAELYNE;
            case CRITERIA_CHAMPION_MOKRA:
            case CRITERIA_CHAMPION_MOKRA_H:
                return NPC_MOKRA;
            case CRITERIA_CHAMPION_VISCERI:
            case CRITERIA_CHAMPION_VISCERI_H:
                return NPC_VISCERI;
            case CRITERIA_CHAMPION_RUNOK:
            case CRITERIA_CHAMPION_RUNOK_H:
                return NPC_RUNOK;
            case CRITERIA_CHAMPION_ERESSEA:
            case CRITERIA_CHAMPION_ERESSEA_H:
                return NPC_ERESSEA;
            case CRITERIA_CHAMPION_ZULTORE:
            case CRITERIA_CHAMPION_ZULTORE_H:
                return NPC_ZULTORE;
            case CRITERIA_MEMORY_HOGGER:        return NPC_MEMORY_HOGGER;
            case CRITERIA_MEMORY_VANCLEEF:      return NPC_MEMORY_VANCLEEF;
            case CRITERIA_MEMORY_MUTANUS:       return NPC_MEMORY_MUTANUS;
            case CRITERIA_MEMORY_HEROD:         return NPC_MEMORY_HEROD;
            case CRITERIA_MEMORY_LUCIFROM:      return NPC_MEMORY_LUCIFROM;
            case CRITERIA_MEMORY_THUNDERAAN:    return NPC_MEMORY_THUNDERAAN;
            case CRITERIA_MEMORY_CHROMAGGUS:    return NPC_MEMORY_CHROMAGGUS;
            case CRITERIA_MEMORY_HAKKAR:        return NPC_MEMORY_HAKKAR;
            case CRITERIA_MEMORY_VEKNILASH:     return NPC_MEMORY_VEKNILASH;
            case CRITERIA_MEMORY_KALITHRESH:    return NPC_MEMORY_KALITHRESH;
            case CRITERIA_MEMORY_MALCHEZAAR:    return NPC_MEMORY_MALCHEZAAR;
            case CRITERIA_MEMORY_GRUUL:         return NPC_MEMORY_GRUUL;
            case CRITERIA_MEMORY_VASHJ:         return NPC_MEMORY_VASHJ;
            case CRITERIA_MEMORY_ARCHIMONDE:    return NPC_MEMORY_ARCHIMONDE;
            case CRITERIA_MEMORY_ILLIDAN:       return NPC_MEMORY_ILLIDAN;
            case CRITERIA_MEMORY_DELRISSA:      return NPC_MEMORY_DELRISSA;
            case CRITERIA_MEMORY_MURU:          return NPC_MEMORY_MURU;
            case CRITERIA_MEMORY_INGVAR:        return NPC_MEMORY_INGVAR;
            case CRITERIA_MEMORY_CYANIGOSA:     return NPC_MEMORY_CYANIGOSA;
            case CRITERIA_MEMORY_ECK:           return NPC_MEMORY_ECK;
            case CRITERIA_MEMORY_ONYXIA:        return NPC_MEMORY_ONYXIA;
            case CRITERIA_MEMORY_HEIGAN:        return NPC_MEMORY_HEIGAN;
            case CRITERIA_MEMORY_IGNIS:         return NPC_MEMORY_IGNIS;
            case CRITERIA_MEMORY_VEZAX:         return NPC_MEMORY_VEZAX;
            case CRITERIA_MEMORY_ALGALON:       return NPC_MEMORY_ALGALON;
            }

            return 0;
        }        

        private:
            ObjectGuid uiAnnouncerGUID;
            ObjectGuid uiMainGateGUID;
            ObjectGuid uiGrandChampionVehicle1GUID;
            ObjectGuid uiGrandChampionVehicle2GUID;
            ObjectGuid uiGrandChampionVehicle3GUID;
            ObjectGuid uiGrandChampion1GUID;
            ObjectGuid uiGrandChampion2GUID;
            ObjectGuid uiGrandChampion3GUID;
            ObjectGuid uiChampionLootGUID;
            ObjectGuid uiArgentChampionGUID;
            ObjectGuid uiTirionGUID;
            ObjectGuid uiThrallGUID;
            ObjectGuid uiGarroshGUID;
            ObjectGuid uiVarianGUID;
            ObjectGuid uiJainaGUID;
            ObjectGuid uiKnightGUID;

            GuidList VehicleList;

            uint32 grandChampionEntry;
            uint32 memoryEntry;
            uint32 TeamInInstance;
            uint16 uiMovementDone;
            uint16 uiGrandChampionsDeaths;
            uint8 uiArgentSoldierDeaths;
            uint8 uiChampMountsDeaths;
            bool achievementHadWorse;
    };

};

void AddSC_instance_trial_of_the_champion()
{
    new instance_trial_of_the_champion();
}
