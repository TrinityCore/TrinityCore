/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "InstanceScript.h"
#include "naxxramas.h"

DoorData const doorData[] =
{
    { GO_ROOM_ANUBREKHAN,       BOSS_ANUBREKHAN,    DOOR_TYPE_ROOM,         BOUNDARY_S      },
    { GO_PASSAGE_ANUBREKHAN,    BOSS_ANUBREKHAN,    DOOR_TYPE_PASSAGE,      BOUNDARY_NONE   },
    { GO_PASSAGE_FAERLINA,      BOSS_FAERLINA,      DOOR_TYPE_PASSAGE,      BOUNDARY_NONE   },
    { GO_ROOM_MAEXXNA,          BOSS_FAERLINA,      DOOR_TYPE_PASSAGE,      BOUNDARY_NONE   },
    { GO_ROOM_MAEXXNA,          BOSS_MAEXXNA,       DOOR_TYPE_ROOM,         BOUNDARY_SW     },
    { GO_ROOM_NOTH,             BOSS_NOTH,          DOOR_TYPE_ROOM,         BOUNDARY_N      },
    { GO_PASSAGE_NOTH,          BOSS_NOTH,          DOOR_TYPE_PASSAGE,      BOUNDARY_E      },
    { GO_ROOM_HEIGAN,           BOSS_NOTH,          DOOR_TYPE_PASSAGE,      BOUNDARY_NONE   },
    { GO_ROOM_HEIGAN,           BOSS_HEIGAN,        DOOR_TYPE_ROOM,         BOUNDARY_N      },
    { GO_PASSAGE_HEIGAN,        BOSS_HEIGAN,        DOOR_TYPE_PASSAGE,      BOUNDARY_E      },
    { GO_ROOM_LOATHEB,          BOSS_HEIGAN,        DOOR_TYPE_PASSAGE,      BOUNDARY_NONE   },
    { GO_ROOM_LOATHEB,          BOSS_LOATHEB,       DOOR_TYPE_ROOM,         BOUNDARY_W      },
    { GO_ROOM_GROBBULUS,        BOSS_PATCHWERK,     DOOR_TYPE_PASSAGE,      BOUNDARY_NONE   },
    { GO_ROOM_GROBBULUS,        BOSS_GROBBULUS,     DOOR_TYPE_ROOM,         BOUNDARY_NONE   },
    { GO_PASSAGE_GLUTH,         BOSS_GLUTH,         DOOR_TYPE_PASSAGE,      BOUNDARY_NW     },
    { GO_ROOM_THADDIUS,         BOSS_GLUTH,         DOOR_TYPE_PASSAGE,      BOUNDARY_NONE   },
    { GO_ROOM_THADDIUS,         BOSS_THADDIUS,      DOOR_TYPE_ROOM,         BOUNDARY_NONE   },
    { GO_ROOM_GOTHIK,           BOSS_RAZUVIOUS,     DOOR_TYPE_PASSAGE,      BOUNDARY_NONE   },
    { GO_ROOM_GOTHIK,           BOSS_GOTHIK,        DOOR_TYPE_ROOM,         BOUNDARY_N      },
    { GO_PASSAGE_GOTHIK,        BOSS_GOTHIK,        DOOR_TYPE_PASSAGE,      BOUNDARY_S      },
    { GO_ROOM_HORSEMEN,         BOSS_GOTHIK,        DOOR_TYPE_PASSAGE,      BOUNDARY_NONE   },
    { GO_GOTHIK_GATE,           BOSS_GOTHIK,        DOOR_TYPE_ROOM,         BOUNDARY_NONE   },
    { GO_ROOM_HORSEMEN,         BOSS_HORSEMEN,      DOOR_TYPE_ROOM,         BOUNDARY_NE     },
    { GO_PASSAGE_SAPPHIRON,     BOSS_SAPPHIRON,     DOOR_TYPE_PASSAGE,      BOUNDARY_W      },
    { GO_ROOM_KELTHUZAD,        BOSS_KELTHUZAD,     DOOR_TYPE_ROOM,         BOUNDARY_S      },
    { GO_ARAC_EYE_RAMP,         BOSS_MAEXXNA,       DOOR_TYPE_PASSAGE,      BOUNDARY_NONE   },
    { GO_ARAC_EYE_RAMP_BOSS,    BOSS_MAEXXNA,       DOOR_TYPE_PASSAGE,      BOUNDARY_NONE   },
    { GO_PLAG_EYE_RAMP,         BOSS_LOATHEB,       DOOR_TYPE_PASSAGE,      BOUNDARY_NONE   },
    { GO_PLAG_EYE_RAMP_BOSS,    BOSS_LOATHEB,       DOOR_TYPE_PASSAGE,      BOUNDARY_NONE   },
    { GO_MILI_EYE_RAMP,         BOSS_HORSEMEN,      DOOR_TYPE_PASSAGE,      BOUNDARY_NONE   },
    { GO_MILI_EYE_RAMP_BOSS,    BOSS_HORSEMEN,      DOOR_TYPE_PASSAGE,      BOUNDARY_NONE   },
    { GO_CONS_EYE_RAMP,         BOSS_THADDIUS,      DOOR_TYPE_PASSAGE,      BOUNDARY_NONE   },
    { GO_CONS_EYE_RAMP_BOSS,    BOSS_THADDIUS,      DOOR_TYPE_PASSAGE,      BOUNDARY_NONE   },
    { 0,                        0,                  DOOR_TYPE_ROOM,         BOUNDARY_NONE   }
};

MinionData const minionData[] =
{
    { NPC_FOLLOWER_WORSHIPPER,  BOSS_FAERLINA   },
    { NPC_DK_UNDERSTUDY,        BOSS_RAZUVIOUS  },
    { NPC_SIR,                  BOSS_HORSEMEN   },
    { NPC_THANE,                BOSS_HORSEMEN   },
    { NPC_LADY,                 BOSS_HORSEMEN   },
    { NPC_BARON,                BOSS_HORSEMEN   },
    { 0,                        0,              }
};

float const HeiganPos[2] = { 2796.0f, -3707.0f };
float const HeiganEruptionSlope[3] =
{
    (-3685.0f - HeiganPos[1]) / (2724.0f - HeiganPos[0]),
    (-3647.0f - HeiganPos[1]) / (2749.0f - HeiganPos[0]),
    (-3637.0f - HeiganPos[1]) / (2771.0f - HeiganPos[0])
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

        struct instance_naxxramas_InstanceMapScript : public InstanceScript
        {
            instance_naxxramas_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);
                LoadMinionData(minionData);

                GothikGateGUID          = 0;
                HorsemenChestGUID       = 0;
                FaerlinaGUID            = 0;
                ThaneGUID               = 0;
                LadyGUID                = 0;
                BaronGUID               = 0;
                SirGUID                 = 0;
                ThaddiusGUID            = 0;
                HeiganGUID              = 0;
                FeugenGUID              = 0;
                StalaggGUID             = 0;
                SapphironGUID           = 0;
                KelthuzadGUID           = 0;
                KelthuzadTriggerGUID    = 0;

                playerDied              = 0;

                memset(PortalsGUID, 0, sizeof(PortalsGUID));
            }

            void OnCreatureCreate(Creature* creature) OVERRIDE
            {
                switch (creature->GetEntry())
                {
                    case NPC_FAERLINA:
                        FaerlinaGUID = creature->GetGUID();
                        break;
                    case NPC_THANE:
                        ThaneGUID = creature->GetGUID();
                        break;
                    case NPC_LADY:
                        LadyGUID = creature->GetGUID();
                        break;
                    case NPC_BARON:
                        BaronGUID = creature->GetGUID();
                        break;
                    case NPC_SIR:
                        SirGUID = creature->GetGUID();
                        break;
                    case NPC_THADDIUS:
                        ThaddiusGUID = creature->GetGUID();
                        break;
                    case NPC_HEIGAN:
                        HeiganGUID = creature->GetGUID();
                        break;
                    case NPC_FEUGEN:
                        FeugenGUID = creature->GetGUID();
                        break;
                    case NPC_STALAGG:
                        StalaggGUID = creature->GetGUID();
                        break;
                    case NPC_SAPPHIRON:
                        SapphironGUID = creature->GetGUID();
                        break;
                    case NPC_KEL_THUZAD:
                        KelthuzadGUID = creature->GetGUID();
                        break;
                    default:
                        break;
                }

                AddMinion(creature, true);
            }

            void OnCreatureRemove(Creature* creature) OVERRIDE
            {
                AddMinion(creature, false);
            }

            void OnGameObjectCreate(GameObject* go) OVERRIDE
            {
                if (go->GetGOInfo()->displayId == 6785 || go->GetGOInfo()->displayId == 1287)
                {
                    uint32 section = GetEruptionSection(go->GetPositionX(), go->GetPositionY());
                    HeiganEruptionGUID[section].insert(go->GetGUID());
                    return;
                }

                switch (go->GetEntry())
                {
                    case GO_GOTHIK_GATE:
                        GothikGateGUID = go->GetGUID();
                        break;
                    case GO_HORSEMEN_CHEST:
                    case GO_HORSEMEN_CHEST_HERO:
                        HorsemenChestGUID = go->GetGUID();
                        break;
                    case GO_KELTHUZAD_PORTAL01:
                        PortalsGUID[0] = go->GetGUID();
                        break;
                    case GO_KELTHUZAD_PORTAL02:
                        PortalsGUID[1] = go->GetGUID();
                        break;
                    case GO_KELTHUZAD_PORTAL03:
                        PortalsGUID[2] = go->GetGUID();
                        break;
                    case GO_KELTHUZAD_PORTAL04:
                        PortalsGUID[3] = go->GetGUID();
                        break;
                    case GO_KELTHUZAD_TRIGGER:
                        KelthuzadTriggerGUID = go->GetGUID();
                        break;
                    default:
                        break;
                }

                AddDoor(go, true);
            }

            void OnGameObjectRemove(GameObject* go) OVERRIDE
            {
                if (go->GetGOInfo()->displayId == 6785 || go->GetGOInfo()->displayId == 1287)
                {
                    uint32 section = GetEruptionSection(go->GetPositionX(), go->GetPositionY());

                    HeiganEruptionGUID[section].erase(go->GetGUID());
                    return;
                }

                switch (go->GetEntry())
                {
                    case GO_BIRTH:
                        if (SapphironGUID)
                        {
                            if (Creature* sapphiron = instance->GetCreature(SapphironGUID))
                                sapphiron->AI()->DoAction(DATA_SAPPHIRON_BIRTH);
                            return;
                        }
                        break;
                    default:
                        break;
                }

                AddDoor(go, false);
            }

            void OnUnitDeath(Unit* unit) OVERRIDE
            {
                if (unit->GetTypeId() == TYPEID_PLAYER && IsEncounterInProgress())
                {
                    playerDied = 1;
                    SaveToDB();
                }
            }

            void SetData(uint32 id, uint32 value) OVERRIDE
            {
                switch (id)
                {
                    case DATA_HEIGAN_ERUPT:
                        HeiganErupt(value);
                        break;
                    case DATA_GOTHIK_GATE:
                        if (GameObject* gate = instance->GetGameObject(GothikGateGUID))
                            gate->SetGoState(GOState(value));
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

            uint32 GetData(uint32 id) const OVERRIDE
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

            uint64 GetData64(uint32 id) const OVERRIDE
            {
                switch (id)
                {
                    case DATA_FAERLINA:
                        return FaerlinaGUID;
                    case DATA_THANE:
                        return ThaneGUID;
                    case DATA_LADY:
                        return LadyGUID;
                    case DATA_BARON:
                        return BaronGUID;
                    case DATA_SIR:
                        return SirGUID;
                    case DATA_THADDIUS:
                        return ThaddiusGUID;
                    case DATA_HEIGAN:
                        return HeiganGUID;
                    case DATA_FEUGEN:
                        return FeugenGUID;
                    case DATA_STALAGG:
                        return StalaggGUID;
                    case DATA_KELTHUZAD:
                        return KelthuzadGUID;
                    case DATA_KELTHUZAD_PORTAL01:
                        return PortalsGUID[0];
                    case DATA_KELTHUZAD_PORTAL02:
                        return PortalsGUID[1];
                    case DATA_KELTHUZAD_PORTAL03:
                        return PortalsGUID[2];
                    case DATA_KELTHUZAD_PORTAL04:
                        return PortalsGUID[3];
                    case DATA_KELTHUZAD_TRIGGER:
                        return KelthuzadTriggerGUID;
                }

                return 0;
            }

            bool SetBossState(uint32 id, EncounterState state) OVERRIDE
            {
                if (!InstanceScript::SetBossState(id, state))
                    return false;

                if (id == BOSS_HORSEMEN && state == DONE)
                {
                    if (GameObject* horsemenChest = instance->GetGameObject(HorsemenChestGUID))
                    {
                        horsemenChest->SetRespawnTime(horsemenChest->GetRespawnDelay());
                        horsemenChest->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                    }
                }

                return true;
            }

            void HeiganErupt(uint32 section)
            {
                for (uint32 i = 0; i < 4; ++i)
                {
                    if (i == section)
                        continue;

                    for (std::set<uint64>::const_iterator itr = HeiganEruptionGUID[i].begin(); itr != HeiganEruptionGUID[i].end(); ++itr)
                    {
                        if (GameObject* heiganEruption = instance->GetGameObject(*itr))
                        {
                            heiganEruption->SendCustomAnim(heiganEruption->GetGoAnimProgress());
                            heiganEruption->CastSpell(NULL, SPELL_ERUPTION);
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
                for (uint32 i = 0; i < EncounterCount; ++i)
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

            std::string GetSaveData() OVERRIDE
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "N X " << GetBossSaveData() << playerDied;

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(const char* strIn) OVERRIDE
            {
                if (!strIn)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }

                OUT_LOAD_INST_DATA(strIn);

                char dataHead1, dataHead2;

                std::istringstream loadStream(strIn);
                loadStream >> dataHead1 >> dataHead2;

                if (dataHead1 == 'N' && dataHead2 == 'X')
                {
                    for (uint8 i = 0; i < EncounterCount; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;

                        SetBossState(i, EncounterState(tmpState));
                    }

                    loadStream >> playerDied;
                }

                OUT_LOAD_INST_DATA_COMPLETE;
            }

        protected:
            /* The Arachnid Quarter */
            // Grand Widow Faerlina
            uint64 FaerlinaGUID;

            /* The Plague Quarter */
            // Heigan the Unclean
            std::set<uint64> HeiganEruptionGUID[4];
            uint64 HeiganGUID;

            /* The Military Quarter */
            // Gothik the Harvester
            uint64 GothikGateGUID;
            // The Four Horsemen
            uint64 ThaneGUID;
            uint64 LadyGUID;
            uint64 BaronGUID;
            uint64 SirGUID;
            uint64 HorsemenChestGUID;
            uint64 HorsemenTeleporterGUID;
            time_t minHorsemenDiedTime;
            time_t maxHorsemenDiedTime;

            /* The Construct Quarter */
            // Thaddius
            uint64 ThaddiusGUID;
            uint64 FeugenGUID;
            uint64 StalaggGUID;

            /* Frostwyrm Lair */
            // Sapphiron
            uint64 SapphironGUID;
            // Kel'Thuzad
            uint64 KelthuzadGUID;
            uint64 KelthuzadTriggerGUID;
            uint64 PortalsGUID[4];
            uint8 AbominationCount;

            /* The Immortal / The Undying */
            uint32 playerDied;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const OVERRIDE
        {
            return new instance_naxxramas_InstanceMapScript(map);
        }
};

void AddSC_instance_naxxramas()
{
    new instance_naxxramas();
}
