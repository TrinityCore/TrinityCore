/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

ObjectData const objectData[] =
{
    { GO_NAXX_PORTAL_ARACHNID,  DATA_NAXX_PORTAL_ARACHNID  },
    { GO_NAXX_PORTAL_CONSTRUCT, DATA_NAXX_PORTAL_CONSTRUCT },
    { GO_NAXX_PORTAL_PLAGUE,    DATA_NAXX_PORTAL_PLAGUE    },
    { GO_NAXX_PORTAL_MILITARY,  DATA_NAXX_PORTAL_MILITARY  },
    { 0,                        0,                         }
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
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);
                LoadMinionData(minionData);
                LoadObjectData(nullptr, objectData);

                minHorsemenDiedTime     = 0;
                maxHorsemenDiedTime     = 0;
                AbominationCount        = 0;
                CurrentWingTaunt        = SAY_KELTHUZAD_FIRST_WING_TAUNT;

                playerDied              = 0;
            }

            void OnCreatureCreate(Creature* creature) override
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
                    case NPC_LICH_KING:
                        LichKingGUID = creature->GetGUID();
                        break;
                    default:
                        break;
                }

                AddMinion(creature, true);
            }

            void OnCreatureRemove(Creature* creature) override
            {
                AddMinion(creature, false);
            }

            void OnGameObjectCreate(GameObject* go) override
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
                    case GO_ROOM_KELTHUZAD:
                        KelthuzadDoorGUID = go->GetGUID();
                        break;
                    case GO_NAXX_PORTAL_ARACHNID:
                        if (GetBossState(BOSS_MAEXXNA) == DONE)
                            go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        break;
                    case GO_NAXX_PORTAL_CONSTRUCT:
                        if (GetBossState(BOSS_THADDIUS) == DONE)
                            go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        break;
                    case GO_NAXX_PORTAL_PLAGUE:
                        if (GetBossState(BOSS_LOATHEB) == DONE)
                            go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        break;
                    case GO_NAXX_PORTAL_MILITARY:
                        if (GetBossState(BOSS_HORSEMEN) == DONE)
                            go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        break;
                    default:
                        break;
                }

                InstanceScript::OnGameObjectCreate(go);
            }

            void OnGameObjectRemove(GameObject* go) override
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

                InstanceScript::OnGameObjectRemove(go);
            }

            void OnUnitDeath(Unit* unit) override
            {
                if (unit->GetTypeId() == TYPEID_PLAYER && IsEncounterInProgress())
                {
                    playerDied = 1;
                    SaveToDB();
                }

                if (Creature* creature = unit->ToCreature())
                    if (creature->GetEntry() == NPC_BIGGLESWORTH)
                    {
                        // Loads Kel'Thuzad's grid. We need this as he must be active in order for his texts to work.
                        instance->LoadGrid(3749.67f, -5114.06f);
                        if (Creature* kelthuzad = instance->GetCreature(KelthuzadGUID))
                            kelthuzad->AI()->Talk(SAY_KELTHUZAD_CAT_DIED);
                    }
            }

            void SetData(uint32 id, uint32 value) override
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

            uint32 GetData(uint32 id) const override
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

            ObjectGuid GetGuidData(uint32 id) const override
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
                    case DATA_LICH_KING:
                        return LichKingGUID;
                }

                return ObjectGuid::Empty;
            }

            bool SetBossState(uint32 id, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(id, state))
                    return false;

                switch (id)
                {
                    case BOSS_MAEXXNA:
                        if (state == DONE)
                        {
                            if (GameObject* teleporter = GetGameObject(DATA_NAXX_PORTAL_ARACHNID))
                                teleporter->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);

                            events.ScheduleEvent(EVENT_KELTHUZAD_WING_TAUNT, 6000);
                        }
                        break;
                    case BOSS_LOATHEB:
                        if (state == DONE)
                        {
                            if (GameObject* teleporter = GetGameObject(DATA_NAXX_PORTAL_PLAGUE))
                                teleporter->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);

                            events.ScheduleEvent(EVENT_KELTHUZAD_WING_TAUNT, 6000);
                        }
                        break;
                    case BOSS_THADDIUS:
                        if (state == DONE)
                        {
                            if (GameObject* teleporter = GetGameObject(DATA_NAXX_PORTAL_CONSTRUCT))
                                teleporter->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);

                            events.ScheduleEvent(EVENT_KELTHUZAD_WING_TAUNT, 6000);
                        }
                        break;
                    case BOSS_GOTHIK:
                        if (state == DONE)
                            events.ScheduleEvent(EVENT_DIALOGUE_GOTHIK_KORTHAZZ, 10000);
                        break;
                    case BOSS_HORSEMEN:
                        if (state == DONE)
                        {
                            if (GameObject* horsemenChest = instance->GetGameObject(HorsemenChestGUID))
                            {
                                horsemenChest->SetRespawnTime(horsemenChest->GetRespawnDelay());
                                horsemenChest->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                            }

                            if (GameObject* teleporter = GetGameObject(DATA_NAXX_PORTAL_MILITARY))
                                teleporter->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);

                            events.ScheduleEvent(EVENT_KELTHUZAD_WING_TAUNT, 6000);
                        }
                        break;
                    case BOSS_SAPPHIRON:
                        if (state == DONE)
                            events.ScheduleEvent(EVENT_DIALOGUE_SAPPHIRON_KELTHUZAD, 6000);
                        break;
                    default:
                        break;
                }

                return true;
            }

            void Update(uint32 diff) override
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_DIALOGUE_GOTHIK_KORTHAZZ:
                            if (Creature* korthazz = instance->GetCreature(ThaneGUID))
                                korthazz->AI()->Talk(SAY_DIALOGUE_GOTHIK_HORSEMAN);
                            events.ScheduleEvent(EVENT_DIALOGUE_GOTHIK_ZELIEK, 5000);
                            break;
                        case EVENT_DIALOGUE_GOTHIK_ZELIEK:
                            if (Creature* zeliek = instance->GetCreature(SirGUID))
                                zeliek->AI()->Talk(SAY_DIALOGUE_GOTHIK_HORSEMAN);
                            events.ScheduleEvent(EVENT_DIALOGUE_GOTHIK_BLAUMEUX, 6000);
                            break;
                        case EVENT_DIALOGUE_GOTHIK_BLAUMEUX:
                            if (Creature* blaumeux = instance->GetCreature(LadyGUID))
                                blaumeux->AI()->Talk(SAY_DIALOGUE_GOTHIK_HORSEMAN);
                            events.ScheduleEvent(EVENT_DIALOGUE_GOTHIK_RIVENDARE, 6000);
                            break;
                        case EVENT_DIALOGUE_GOTHIK_RIVENDARE:
                            if (Creature* rivendare = instance->GetCreature(BaronGUID))
                                rivendare->AI()->Talk(SAY_DIALOGUE_GOTHIK_HORSEMAN);
                            events.ScheduleEvent(EVENT_DIALOGUE_GOTHIK_BLAUMEUX2, 6000);
                            break;
                        case EVENT_DIALOGUE_GOTHIK_BLAUMEUX2:
                            if (Creature* blaumeux = instance->GetCreature(LadyGUID))
                                blaumeux->AI()->Talk(SAY_DIALOGUE_GOTHIK_HORSEMAN2);
                            events.ScheduleEvent(EVENT_DIALOGUE_GOTHIK_ZELIEK2, 6000);
                            break;
                        case EVENT_DIALOGUE_GOTHIK_ZELIEK2:
                            if (Creature* zeliek = instance->GetCreature(SirGUID))
                                zeliek->AI()->Talk(SAY_DIALOGUE_GOTHIK_HORSEMAN2);
                            events.ScheduleEvent(EVENT_DIALOGUE_GOTHIK_KORTHAZZ2, 6000);
                            break;
                        case EVENT_DIALOGUE_GOTHIK_KORTHAZZ2:
                            if (Creature* korthazz = instance->GetCreature(ThaneGUID))
                                korthazz->AI()->Talk(SAY_DIALOGUE_GOTHIK_HORSEMAN2);
                            events.ScheduleEvent(EVENT_DIALOGUE_GOTHIK_RIVENDARE2, 6000);
                            break;
                        case EVENT_DIALOGUE_GOTHIK_RIVENDARE2:
                            if (Creature* rivendare = instance->GetCreature(BaronGUID))
                                rivendare->AI()->Talk(SAY_DIALOGUE_GOTHIK_HORSEMAN2);
                            break;
                        case EVENT_KELTHUZAD_WING_TAUNT:
                            // Loads Kel'Thuzad's grid. We need this as he must be active in order for his texts to work.
                            instance->LoadGrid(3749.67f, -5114.06f);
                            if (Creature* kelthuzad = instance->GetCreature(KelthuzadGUID))
                                kelthuzad->AI()->Talk(CurrentWingTaunt);
                            ++CurrentWingTaunt;
                            break;
                        case EVENT_DIALOGUE_SAPPHIRON_KELTHUZAD:
                            if (Creature* kelthuzad = instance->GetCreature(KelthuzadGUID))
                                kelthuzad->AI()->Talk(SAY_DIALOGUE_SAPPHIRON_KELTHUZAD);
                            HandleGameObject(KelthuzadDoorGUID, false);
                            events.ScheduleEvent(EVENT_DIALOGUE_SAPPHIRON_LICHKING, 6000);
                            break;
                        case EVENT_DIALOGUE_SAPPHIRON_LICHKING:
                            if (Creature* lichKing = instance->GetCreature(LichKingGUID))
                                lichKing->AI()->Talk(SAY_DIALOGUE_SAPPHIRON_LICH_KING);
                            events.ScheduleEvent(EVENT_DIALOGUE_SAPPHIRON_KELTHUZAD2, 16000);
                            break;
                        case EVENT_DIALOGUE_SAPPHIRON_KELTHUZAD2:
                            if (Creature* kelthuzad = instance->GetCreature(KelthuzadGUID))
                                kelthuzad->AI()->Talk(SAY_DIALOGUE_SAPPHIRON_KELTHUZAD2);
                            events.ScheduleEvent(EVENT_DIALOGUE_SAPPHIRON_LICHKING2, 9000);
                            break;
                        case EVENT_DIALOGUE_SAPPHIRON_LICHKING2:
                            if (Creature* lichKing = instance->GetCreature(LichKingGUID))
                                lichKing->AI()->Talk(SAY_DIALOGUE_SAPPHIRON_LICH_KING2);
                            events.ScheduleEvent(EVENT_DIALOGUE_SAPPHIRON_KELTHUZAD3, 12000);
                            break;
                        case EVENT_DIALOGUE_SAPPHIRON_KELTHUZAD3:
                            if (Creature* kelthuzad = instance->GetCreature(KelthuzadGUID))
                                kelthuzad->AI()->Talk(SAY_DIALOGUE_SAPPHIRON_KELTHUZAD3);
                            events.ScheduleEvent(EVENT_DIALOGUE_SAPPHIRON_KELTHUZAD4, 6000);
                            break;
                        case EVENT_DIALOGUE_SAPPHIRON_KELTHUZAD4:
                            if (Creature* kelthuzad = instance->GetCreature(KelthuzadGUID))
                                kelthuzad->AI()->Talk(SAY_DIALOGUE_SAPPHIRON_KELTHUZAD4);
                            HandleGameObject(KelthuzadDoorGUID, true);
                            break;
                        default:
                            break;
                    }
                }
            }

            void HeiganErupt(uint32 section)
            {
                for (uint32 i = 0; i < 4; ++i)
                {
                    if (i == section)
                        continue;

                    for (ObjectGuid guid : HeiganEruptionGUID[i])
                    {
                        if (GameObject* heiganEruption = instance->GetGameObject(guid))
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

            bool CheckAchievementCriteriaMeet(uint32 criteria_id, Player const* /*source*/, Unit const* /*target = NULL*/, uint32 /*miscvalue1 = 0*/) override
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

        protected:
            /* The Arachnid Quarter */
            // Grand Widow Faerlina
            ObjectGuid FaerlinaGUID;

            /* The Plague Quarter */
            // Heigan the Unclean
            GuidSet HeiganEruptionGUID[4];
            ObjectGuid HeiganGUID;

            /* The Military Quarter */
            // Gothik the Harvester
            ObjectGuid GothikGateGUID;
            // The Four Horsemen
            ObjectGuid ThaneGUID;
            ObjectGuid LadyGUID;
            ObjectGuid BaronGUID;
            ObjectGuid SirGUID;
            ObjectGuid HorsemenChestGUID;
            time_t minHorsemenDiedTime;
            time_t maxHorsemenDiedTime;

            /* The Construct Quarter */
            // Thaddius
            ObjectGuid ThaddiusGUID;
            ObjectGuid FeugenGUID;
            ObjectGuid StalaggGUID;

            /* Frostwyrm Lair */
            // Sapphiron
            ObjectGuid SapphironGUID;
            // Kel'Thuzad
            ObjectGuid KelthuzadGUID;
            ObjectGuid KelthuzadTriggerGUID;
            ObjectGuid PortalsGUID[4];
            ObjectGuid KelthuzadDoorGUID;
            ObjectGuid LichKingGUID;
            uint8 AbominationCount;
            uint8 CurrentWingTaunt;

            /* The Immortal / The Undying */
            uint32 playerDied;

            EventMap events;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_naxxramas_InstanceMapScript(map);
        }
};

void AddSC_instance_naxxramas()
{
    new instance_naxxramas();
}
