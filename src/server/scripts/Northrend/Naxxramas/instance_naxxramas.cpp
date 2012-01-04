/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "naxxramas.h"

const DoorData doorData[] =
{
    {181126,    BOSS_ANUBREKHAN, DOOR_TYPE_ROOM,     BOUNDARY_S},
    {181195,    BOSS_ANUBREKHAN, DOOR_TYPE_PASSAGE,  0},
    {194022,    BOSS_FAERLINA,  DOOR_TYPE_PASSAGE,  0},
    {181209,    BOSS_FAERLINA,  DOOR_TYPE_PASSAGE,  0},
    {181209,    BOSS_MAEXXNA,   DOOR_TYPE_ROOM,     BOUNDARY_SW},
    {181200,    BOSS_NOTH,      DOOR_TYPE_ROOM,     BOUNDARY_N},
    {181201,    BOSS_NOTH,      DOOR_TYPE_PASSAGE,  BOUNDARY_E},
    {181202,    BOSS_NOTH,      DOOR_TYPE_PASSAGE,  0},
    {181202,    BOSS_HEIGAN,    DOOR_TYPE_ROOM,     BOUNDARY_N},
    {181203,    BOSS_HEIGAN,    DOOR_TYPE_PASSAGE,  BOUNDARY_E},
    {181241,    BOSS_HEIGAN,    DOOR_TYPE_PASSAGE,  0},
    {181241,    BOSS_LOATHEB,   DOOR_TYPE_ROOM,     BOUNDARY_W},
    {181123,    BOSS_PATCHWERK, DOOR_TYPE_PASSAGE,  0},
    {181123,    BOSS_GROBBULUS, DOOR_TYPE_ROOM,     0},
    {181120,    BOSS_GLUTH,     DOOR_TYPE_PASSAGE,  BOUNDARY_NW},
    {181121,    BOSS_GLUTH,     DOOR_TYPE_PASSAGE,  0},
    {181121,    BOSS_THADDIUS,  DOOR_TYPE_ROOM,     0},
    {181124,    BOSS_RAZUVIOUS, DOOR_TYPE_PASSAGE,  0},
    {181124,    BOSS_GOTHIK,    DOOR_TYPE_ROOM,     BOUNDARY_N},
    {181125,    BOSS_GOTHIK,    DOOR_TYPE_PASSAGE,  BOUNDARY_S},
    {181119,    BOSS_GOTHIK,    DOOR_TYPE_PASSAGE,  0},
    {181119,    BOSS_HORSEMEN,  DOOR_TYPE_ROOM,     BOUNDARY_NE},
    {181225,    BOSS_SAPPHIRON, DOOR_TYPE_PASSAGE,  BOUNDARY_W},
    {181228,    BOSS_KELTHUZAD, DOOR_TYPE_ROOM,     BOUNDARY_S},
    {0,         0,              DOOR_TYPE_ROOM,     0}, // EOF
};

const MinionData minionData[] =
{
    //{16573,     BOSS_ANUBREKHAN},     there is no spawn point in db, so we do not add them here
    {16506,     BOSS_FAERLINA},
    {16803,     BOSS_RAZUVIOUS},
    {16063,     BOSS_HORSEMEN},
    {16064,     BOSS_HORSEMEN},
    {16065,     BOSS_HORSEMEN},
    {30549,     BOSS_HORSEMEN},
    {0,         0, }
};

enum eEnums
{
    GO_HORSEMEN_CHEST_HERO  = 193426,
    GO_HORSEMEN_CHEST       = 181366,                   //four horsemen event, DoRespawnGameObject() when event == DONE
    GO_GOTHIK_GATE          = 181170,
    GO_KELTHUZAD_PORTAL01   = 181402,
    GO_KELTHUZAD_PORTAL02   = 181403,
    GO_KELTHUZAD_PORTAL03   = 181404,
    GO_KELTHUZAD_PORTAL04   = 181405,
    GO_KELTHUZAD_TRIGGER    = 181444,

    SPELL_ERUPTION          = 29371
};

const float HeiganPos[2] = {2796, -3707};
const float HeiganEruptionSlope[3] =
{
    (-3685 - HeiganPos[1]) /(2724 - HeiganPos[0]),
    (-3647 - HeiganPos[1]) /(2749 - HeiganPos[0]),
    (-3637 - HeiganPos[1]) /(2771 - HeiganPos[0]),
};

// 0  H      x
//  1        ^
//   2       |
//    3  y<--o
inline uint32 GetEruptionSection(float x, float y)
{
    y -= HeiganPos[1];
    if (y < 1.0f)
        return 0;

    x -= HeiganPos[0];
    if (x > -1.0f)
        return 3;

    float slope = y/x;
    for (uint32 i = 0; i < 3; ++i)
        if (slope > HeiganEruptionSlope[i])
            return i;
    return 3;
}

class instance_naxxramas : public InstanceMapScript
{
public:
    instance_naxxramas() : InstanceMapScript("instance_naxxramas", 533) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_naxxramas_InstanceMapScript(map);
    }

    struct instance_naxxramas_InstanceMapScript : public InstanceScript
    {
        instance_naxxramas_InstanceMapScript(Map* map) : InstanceScript(map)
        {
            SetBossNumber(MAX_BOSS_NUMBER);
            LoadDoorData(doorData);
            LoadMinionData(minionData);
        }

        std::set<uint64> heiganEruptionGUID[4];
        uint64 gothikGateGUID;
        uint64 horsemenChestGUID;
        uint64 sapphironGUID;
        uint64 faerlinaGUID;
        uint64 thaneGUID;
        uint64 ladyGUID;
        uint64 baronGUID;
        uint64 sirGUID;

        uint64 thaddiusGUID;
        uint64 heiganGUID;
        uint64 feugenGUID;
        uint64 stalaggGUID;

        uint64 kelthuzadGUID;
        uint64 kelthuzadTriggerGUID;
        uint64 portalsGUID[4];

        uint32 AbominationCount;

        GOState gothikDoorState;

        time_t minHorsemenDiedTime;
        time_t maxHorsemenDiedTime;

        uint32 playerDied;

        void Initialize()
        {
            gothikGateGUID            = 0;
            horsemenChestGUID         = 0;
            sapphironGUID             = 0;
            faerlinaGUID              = 0;
            thaneGUID                 = 0;
            ladyGUID                  = 0;
            baronGUID                 = 0;
            sirGUID                   = 0;
            thaddiusGUID              = 0;
            heiganGUID                = 0;
            feugenGUID                = 0;
            stalaggGUID               = 0;
            kelthuzadGUID             = 0;
            kelthuzadTriggerGUID      = 0;

            playerDied        = 0;
            gothikDoorState   = GO_STATE_ACTIVE;

            memset(portalsGUID, 0, sizeof(portalsGUID));
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case 15989: sapphironGUID = creature->GetGUID(); return;
                case 15953: faerlinaGUID = creature->GetGUID(); return;
                case 16064: thaneGUID = creature->GetGUID(); return;
                case 16065: ladyGUID = creature->GetGUID(); return;
                case 30549: baronGUID = creature->GetGUID(); return;
                case 16063: sirGUID = creature->GetGUID(); return;
                case 15928: thaddiusGUID = creature->GetGUID(); return;
                case 15936: heiganGUID = creature->GetGUID(); return;
                case 15930: feugenGUID = creature->GetGUID(); return;
                case 15929: stalaggGUID = creature->GetGUID(); return;
                case 15990: kelthuzadGUID = creature->GetGUID(); return;
            }

            AddMinion(creature, true);
        }

        void OnCreatureRemove(Creature* creature)
        {
            AddMinion(creature, false);
        }

        void OnGameObjectCreate(GameObject* go)
        {
            if (go->GetGOInfo()->displayId == 6785 || go->GetGOInfo()->displayId == 1287)
            {
                uint32 section = GetEruptionSection(go->GetPositionX(), go->GetPositionY());
                heiganEruptionGUID[section].insert(go->GetGUID());

                return;
            }

            switch (go->GetEntry())
            {
                case GO_GOTHIK_GATE:
                    gothikGateGUID = go->GetGUID();
                    go->SetGoState(gothikDoorState);
                    break;
                case GO_HORSEMEN_CHEST:
                    horsemenChestGUID = go->GetGUID();
                    break;
                case GO_HORSEMEN_CHEST_HERO:
                    horsemenChestGUID = go->GetGUID();
                    break;
                case GO_KELTHUZAD_PORTAL01:
                    portalsGUID[0] = go->GetGUID();
                    break;
                case GO_KELTHUZAD_PORTAL02:
                    portalsGUID[1] = go->GetGUID();
                    break;
                case GO_KELTHUZAD_PORTAL03:
                    portalsGUID[2] = go->GetGUID();
                    break;
                case GO_KELTHUZAD_PORTAL04:
                    portalsGUID[3] = go->GetGUID();
                    break;
                case GO_KELTHUZAD_TRIGGER:
                    kelthuzadTriggerGUID = go->GetGUID();
                    break;
                default:
                    break;
            }

            AddDoor(go, true);
        }

        void OnGameObjectRemove(GameObject* go)
        {
            if (go->GetGOInfo()->displayId == 6785 || go->GetGOInfo()->displayId == 1287)
            {
                uint32 section = GetEruptionSection(go->GetPositionX(), go->GetPositionY());

                heiganEruptionGUID[section].erase(go->GetGUID());
                return;
            }

            switch (go->GetEntry())
            {
                case GO_BIRTH:
                    if (sapphironGUID)
                    {
                        if (Creature* pSapphiron = instance->GetCreature(sapphironGUID))
                            pSapphiron->AI()->DoAction(DATA_SAPPHIRON_BIRTH);
                        return;
                    }
                    break;
                default:
                    break;
            }

            AddDoor(go, false);
        }

        void OnUnitDeath(Unit* unit)
        {
            if (unit->GetTypeId() == TYPEID_PLAYER && IsEncounterInProgress())
            {
                playerDied = 1;
                SaveToDB();
            }
        }

        void SetData(uint32 id, uint32 value)
        {
            switch (id)
            {
                case DATA_HEIGAN_ERUPT:
                    HeiganErupt(value);
                    break;
                case DATA_GOTHIK_GATE:
                    if (GameObject* gothikGate = instance->GetGameObject(gothikGateGUID))
                        gothikGate->SetGoState(GOState(value));
                    gothikDoorState = GOState(value);
                    break;
                case DATA_HORSEMEN0:
                case DATA_HORSEMEN1:
                case DATA_HORSEMEN2:
                case DATA_HORSEMEN3:
                    if (value == NOT_STARTED)
                    {
                        minHorsemenDiedTime = 0;
                        maxHorsemenDiedTime = 0;
                    }
                    else if (value == DONE)
                    {
                        time_t now = time(NULL);

                        if (minHorsemenDiedTime == 0)
                            minHorsemenDiedTime = now;

                        maxHorsemenDiedTime = now;
                    }
                    break;
                case DATA_ABOMINATION_KILLED:
                    AbominationCount = value;
                    break;
            }
        }

        uint32 GetData(uint32 id)
        {
            switch (id)
            {
                case DATA_ABOMINATION_KILLED:
                    return AbominationCount;
                default:
                    break;
            }

            return 0;
        }

        uint64 GetData64(uint32 id)
        {
            switch (id)
            {
            case DATA_FAERLINA:
                return faerlinaGUID;
            case DATA_THANE:
                return thaneGUID;
            case DATA_LADY:
                return ladyGUID;
            case DATA_BARON:
                return baronGUID;
            case DATA_SIR:
                return sirGUID;
            case DATA_THADDIUS:
                return thaddiusGUID;
            case DATA_HEIGAN:
                return heiganGUID;
            case DATA_FEUGEN:
                return feugenGUID;
            case DATA_STALAGG:
                return stalaggGUID;
            case DATA_KELTHUZAD:
                return kelthuzadGUID;
            case DATA_KELTHUZAD_PORTAL01:
                return portalsGUID[0];
            case DATA_KELTHUZAD_PORTAL02:
                return portalsGUID[1];
            case DATA_KELTHUZAD_PORTAL03:
                return portalsGUID[2];
            case DATA_KELTHUZAD_PORTAL04:
                return portalsGUID[3];
            case DATA_KELTHUZAD_TRIGGER:
                return kelthuzadTriggerGUID;
            }
            return 0;
        }

        bool SetBossState(uint32 id, EncounterState state)
        {
            if (!InstanceScript::SetBossState(id, state))
                return false;

            if (id == BOSS_HORSEMEN && state == DONE)
            {
                if (GameObject* pHorsemenChest = instance->GetGameObject(horsemenChestGUID))
                    pHorsemenChest->SetRespawnTime(pHorsemenChest->GetRespawnDelay());
            }

            return true;
        }

        void HeiganErupt(uint32 section)
        {
            for (uint32 i = 0; i < 4; ++i)
            {
                if (i == section)
                    continue;

                for (std::set<uint64>::const_iterator itr = heiganEruptionGUID[i].begin(); itr != heiganEruptionGUID[i].end(); ++itr)
                {
                    if (GameObject* pHeiganEruption = instance->GetGameObject(*itr))
                    {
                        pHeiganEruption->SendCustomAnim(pHeiganEruption->GetGoAnimProgress());
                        pHeiganEruption->CastSpell(NULL, SPELL_ERUPTION);
                    }
                }
            }
        }

        // This Function is called in CheckAchievementCriteriaMeet and CheckAchievementCriteriaMeet is called before SetBossState(bossId, DONE),
        // so to check if all bosses are done the checker must exclude 1 boss, the last done, if there is at most 1 encouter in progress when is
        // called this function then all bosses are done. The one boss that check is the boss that calls this function, so it is dead.
        bool AreAllEncoutersDone()
        {
            uint32 numBossAlive = 0;
            for (uint32 i = 0; i < MAX_BOSS_NUMBER; ++i)
                if (GetBossState(i) != DONE)
                    numBossAlive++;

            if (numBossAlive > 1)
                return false;
            return true;
        }

        bool CheckAchievementCriteriaMeet(uint32 criteria_id, Player const* /*source*/, Unit const* /*target = NULL*/, uint32 /*miscvalue1 = 0*/)
        {
            switch (criteria_id)
            {
                case 7600:  // Criteria for achievement 2176: And They Would All Go Down Together 15sec of each other 10-man
                    if (Difficulty(instance->GetSpawnMode()) == RAID_DIFFICULTY_10MAN_NORMAL && (maxHorsemenDiedTime - minHorsemenDiedTime) < 15)
                        return true;
                    return false;
                case 7601:  // Criteria for achievement 2177: And They Would All Go Down Together 15sec of each other 25-man
                    if (Difficulty(instance->GetSpawnMode()) == RAID_DIFFICULTY_25MAN_NORMAL && (maxHorsemenDiedTime - minHorsemenDiedTime) < 15)
                        return true;
                    return false;
                // Difficulty checks are done on DB.
                // Criteria for achievement 2186: The Immortal (25-man)
                case 13233: // The Four Horsemen
                case 13234: // Maexxna
                case 13235: // Thaddius
                case 13236: // Loatheb
                case 7616:  // Kel'Thuzad
                // Criteria for achievement 2187: The Undying (10-man)
                case 13237: // The Four Horsemen
                case 13238: // Maexxna
                case 13239: // Loatheb
                case 13240: // Thaddius
                case 7617:  // Kel'Thuzad
                    if (AreAllEncoutersDone() && !playerDied)
                        return true;
                    return false;
            }
            return false;
        }

        std::string GetSaveData()
        {
            std::ostringstream saveStream;
            saveStream << GetBossSaveData() << gothikDoorState << ' ' << playerDied;
            return saveStream.str();
        }

        void Load(const char * data)
        {
            std::istringstream loadStream(LoadBossState(data));
            uint32 temp, buff, buff2;

            for (uint32 i = 0; i < MAX_BOSS_NUMBER; ++i)
                loadStream >> temp;

            loadStream >> buff;
            gothikDoorState = GOState(buff);
            loadStream >> buff2;
            playerDied = buff2;
        }
    };

};

void AddSC_instance_naxxramas()
{
    new instance_naxxramas();
}
