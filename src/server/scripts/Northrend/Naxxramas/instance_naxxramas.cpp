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

#include "ScriptMgr.h"
#include "AreaBoundary.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "EventMap.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "naxxramas.h"
#include "TemporarySummon.h"

BossBoundaryData const boundaries =
{
    /* Arachnid Quarter */
    { BOSS_ANUBREKHAN, new CircleBoundary(Position(3273.376709f, -3475.876709f), Position(3195.668213f, -3475.930176f)) },
    { BOSS_FAERLINA, new RectangleBoundary(3315.0f, 3402.0f, -3727.0f, -3590.0f) },
    { BOSS_FAERLINA, new CircleBoundary(Position(3372.68f, -3648.2f), Position(3316.0f, -3704.26f)) },
    { BOSS_MAEXXNA, new CircleBoundary(Position(3502.2587f, -3892.1697f), Position(3418.7422f, -3840.271f)) },

    /* Plague Quarter */
    { BOSS_NOTH, new RectangleBoundary(2618.0f, 2754.0f, -3557.43f, -3450.0f) },
    { BOSS_HEIGAN, new CircleBoundary(Position(2772.57f, -3685.28f), 56.0f) },
    { BOSS_LOATHEB, new CircleBoundary(Position(2909.0f, -3997.41f), 57.0f) },

    /* Military Quarter */
    { BOSS_RAZUVIOUS, new ZRangeBoundary(260.0f, 287.0f) }, // will not chase onto the upper floor
    { BOSS_GOTHIK, new RectangleBoundary(2627.0f, 2764.0f, -3440.0f, -3275.0f) },
    { BOSS_HORSEMEN, new ParallelogramBoundary(Position(2646.0f, -2959.0f), Position(2529.0f, -3075.0f), Position(2506.0f, -2854.0f)) },

    /* Construct Quarter */
    { BOSS_PATCHWERK, new CircleBoundary(Position(3204.0f, -3241.4f), 240.0f) },
    { BOSS_PATCHWERK, new CircleBoundary(Position(3130.8576f, -3210.36f), Position(3085.37f, -3219.85f), true) }, // entrance slime circle blocker
    { BOSS_GROBBULUS, new CircleBoundary(Position(3204.0f, -3241.4f), 240.0f) },
    { BOSS_GROBBULUS, new RectangleBoundary(3295.0f, 3340.0f, -3254.2f, -3230.18f, true) }, // entrance door blocker
    { BOSS_GLUTH, new CircleBoundary(Position(3293.0f, -3142.0f), 80.0) },
    { BOSS_GLUTH, new ParallelogramBoundary(Position(3401.0f, -3149.0f), Position(3261.0f, -3028.0f), Position(3320.0f, -3267.0f)) },
    { BOSS_GLUTH, new ZRangeBoundary(285.0f, 310.0f) },
    { BOSS_THADDIUS, new ParallelogramBoundary(Position(3478.3f, -3070.0f), Position(3370.0f, -2961.5f), Position(3580.0f, -2961.5f)) },

    /* Frostwyrm Lair */
    { BOSS_SAPPHIRON, new CircleBoundary(Position(3517.627f, -5255.5f), 110.0) },
    { BOSS_KELTHUZAD, new CircleBoundary(Position(3716.0f, -5107.0f), 85.0) }
};

DoorData const doorData[] =
{
    { GO_ROOM_ANUBREKHAN,       BOSS_ANUBREKHAN,    DOOR_TYPE_ROOM },
    { GO_PASSAGE_ANUBREKHAN,    BOSS_ANUBREKHAN,    DOOR_TYPE_PASSAGE },
    { GO_PASSAGE_FAERLINA,      BOSS_FAERLINA,      DOOR_TYPE_PASSAGE },
    { GO_ROOM_MAEXXNA,          BOSS_FAERLINA,      DOOR_TYPE_PASSAGE },
    { GO_ROOM_MAEXXNA,          BOSS_MAEXXNA,       DOOR_TYPE_ROOM },
    { GO_ROOM_NOTH,             BOSS_NOTH,          DOOR_TYPE_ROOM },
    { GO_PASSAGE_NOTH,          BOSS_NOTH,          DOOR_TYPE_PASSAGE },
    { GO_ROOM_HEIGAN,           BOSS_NOTH,          DOOR_TYPE_PASSAGE },
    { GO_ROOM_HEIGAN,           BOSS_HEIGAN,        DOOR_TYPE_ROOM },
    { GO_PASSAGE_HEIGAN,        BOSS_HEIGAN,        DOOR_TYPE_PASSAGE },
    { GO_ROOM_LOATHEB,          BOSS_HEIGAN,        DOOR_TYPE_PASSAGE },
    { GO_ROOM_LOATHEB,          BOSS_LOATHEB,       DOOR_TYPE_ROOM },
    { GO_ROOM_GROBBULUS,        BOSS_PATCHWERK,     DOOR_TYPE_PASSAGE },
    { GO_ROOM_GROBBULUS,        BOSS_GROBBULUS,     DOOR_TYPE_ROOM },
    { GO_PASSAGE_GLUTH,         BOSS_GLUTH,         DOOR_TYPE_PASSAGE },
    { GO_ROOM_THADDIUS,         BOSS_GLUTH,         DOOR_TYPE_PASSAGE },
    { GO_ROOM_THADDIUS,         BOSS_THADDIUS,      DOOR_TYPE_ROOM },
    { GO_ROOM_GOTHIK,           BOSS_RAZUVIOUS,     DOOR_TYPE_PASSAGE },
    { GO_ROOM_GOTHIK,           BOSS_GOTHIK,        DOOR_TYPE_ROOM },
    { GO_PASSAGE_GOTHIK,        BOSS_GOTHIK,        DOOR_TYPE_PASSAGE },
    { GO_ROOM_HORSEMEN,         BOSS_GOTHIK,        DOOR_TYPE_PASSAGE },
    { GO_GOTHIK_GATE,           BOSS_GOTHIK,        DOOR_TYPE_ROOM },
    { GO_ROOM_HORSEMEN,         BOSS_HORSEMEN,      DOOR_TYPE_ROOM },
    { GO_PASSAGE_SAPPHIRON,     BOSS_SAPPHIRON,     DOOR_TYPE_PASSAGE },
    { GO_ROOM_KELTHUZAD,        BOSS_KELTHUZAD,     DOOR_TYPE_ROOM },
    { GO_ARAC_EYE_RAMP,         BOSS_MAEXXNA,       DOOR_TYPE_PASSAGE },
    { GO_ARAC_EYE_RAMP_BOSS,    BOSS_MAEXXNA,       DOOR_TYPE_PASSAGE },
    { GO_PLAG_EYE_RAMP,         BOSS_LOATHEB,       DOOR_TYPE_PASSAGE },
    { GO_PLAG_EYE_RAMP_BOSS,    BOSS_LOATHEB,       DOOR_TYPE_PASSAGE },
    { GO_MILI_EYE_RAMP,         BOSS_HORSEMEN,      DOOR_TYPE_PASSAGE },
    { GO_MILI_EYE_RAMP_BOSS,    BOSS_HORSEMEN,      DOOR_TYPE_PASSAGE },
    { GO_CONS_EYE_RAMP,         BOSS_THADDIUS,      DOOR_TYPE_PASSAGE },
    { GO_CONS_EYE_RAMP_BOSS,    BOSS_THADDIUS,      DOOR_TYPE_PASSAGE },
    { 0,                        0,                  DOOR_TYPE_ROOM }
};

ObjectData const objectData[] =
{
    { GO_NAXX_PORTAL_ARACHNID,  DATA_NAXX_PORTAL_ARACHNID  },
    { GO_NAXX_PORTAL_CONSTRUCT, DATA_NAXX_PORTAL_CONSTRUCT },
    { GO_NAXX_PORTAL_PLAGUE,    DATA_NAXX_PORTAL_PLAGUE    },
    { GO_NAXX_PORTAL_MILITARY,  DATA_NAXX_PORTAL_MILITARY  },
    { GO_KELTHUZAD_THRONE,      DATA_KELTHUZAD_THRONE      },
    { 0,                        0,                         }
};

class instance_naxxramas : public InstanceMapScript
{
    public:
        instance_naxxramas() : InstanceMapScript(NaxxramasScriptName, 533) { }

        struct instance_naxxramas_InstanceMapScript : public InstanceScript
        {
            instance_naxxramas_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadBossBoundaries(boundaries);
                LoadDoorData(doorData);
                LoadObjectData(nullptr, objectData);

                hadAnubRekhanGreet      = false;
                hadFaerlinaGreet        = false;
                hadThaddiusGreet        = false;
                hadSapphironBirth       = false;
                CurrentWingTaunt        = SAY_KELTHUZAD_FIRST_WING_TAUNT;

                playerDied              = 0;

                nextFroggerWave         = 0;
                events.ScheduleEvent(EVENT_SUMMON_FROGGER_WAVE, Seconds(1));
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_ANUBREKHAN:
                        AnubRekhanGUID = creature->GetGUID();
                        break;
                    case NPC_FAERLINA:
                        FaerlinaGUID = creature->GetGUID();
                        break;
                    case NPC_RAZUVIOUS:
                        RazuviousGUID = creature->GetGUID();
                        break;
                    case NPC_GOTHIK:
                        GothikGUID = creature->GetGUID();
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
                    case NPC_GLUTH:
                        GluthGUID = creature->GetGUID();
                        break;
                    case NPC_HEIGAN:
                        HeiganGUID = creature->GetGUID();
                        break;
                    case NPC_THADDIUS:
                        ThaddiusGUID = creature->GetGUID();
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
            }

            void OnGameObjectCreate(GameObject* go) override
            {
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
                            go->RemoveFlag(GO_FLAG_NOT_SELECTABLE);
                        break;
                    case GO_NAXX_PORTAL_CONSTRUCT:
                        if (GetBossState(BOSS_THADDIUS) == DONE)
                            go->RemoveFlag(GO_FLAG_NOT_SELECTABLE);
                        break;
                    case GO_NAXX_PORTAL_PLAGUE:
                        if (GetBossState(BOSS_LOATHEB) == DONE)
                            go->RemoveFlag(GO_FLAG_NOT_SELECTABLE);
                        break;
                    case GO_NAXX_PORTAL_MILITARY:
                        if (GetBossState(BOSS_HORSEMEN) == DONE)
                            go->RemoveFlag(GO_FLAG_NOT_SELECTABLE);
                        break;
                    case GO_KELTHUZAD_THRONE:
                        if (GetBossState(BOSS_KELTHUZAD) == DONE)
                            go->RemoveFlag(GO_FLAG_NOT_SELECTABLE);
                        break;
                    case GO_BIRTH:
                        if (hadSapphironBirth || GetBossState(BOSS_SAPPHIRON) == DONE)
                        {
                            hadSapphironBirth = true;
                            go->Delete();
                        }
                        break;
                    default:
                        break;
                }

                InstanceScript::OnGameObjectCreate(go);
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
                    case DATA_GOTHIK_GATE:
                        if (GameObject* gate = instance->GetGameObject(GothikGateGUID))
                            gate->SetGoState(GOState(value));
                        break;
                    case DATA_HAD_ANUBREKHAN_GREET:
                        hadAnubRekhanGreet = (value == 1u);
                        break;
                    case DATA_HAD_FAERLINA_GREET:
                        hadFaerlinaGreet = (value == 1u);
                        break;
                    case DATA_HAD_THADDIUS_GREET:
                        hadThaddiusGreet = (value == 1u);
                        break;
                    case DATA_HAD_SAPPHIRON_BIRTH:
                        hadSapphironBirth = (value == 1u);
                        break;
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 id) const override
            {
                switch (id)
                {
                    case DATA_HAD_ANUBREKHAN_GREET:
                        return hadAnubRekhanGreet ? 1u : 0u;
                    case DATA_HAD_FAERLINA_GREET:
                        return hadFaerlinaGreet ? 1u : 0u;
                    case DATA_HAD_THADDIUS_GREET:
                        return hadThaddiusGreet ? 1u : 0u;
                    case DATA_HAD_SAPPHIRON_BIRTH:
                        return hadSapphironBirth ? 1u : 0u;
                    default:
                        break;
                }

                return 0;
            }

            ObjectGuid GetGuidData(uint32 id) const override
            {
                switch (id)
                {
                    case DATA_ANUBREKHAN:
                        return AnubRekhanGUID;
                    case DATA_FAERLINA:
                        return FaerlinaGUID;
                    case DATA_RAZUVIOUS:
                        return RazuviousGUID;
                    case DATA_GOTHIK:
                        return GothikGUID;
                    case DATA_THANE:
                        return ThaneGUID;
                    case DATA_LADY:
                        return LadyGUID;
                    case DATA_BARON:
                        return BaronGUID;
                    case DATA_SIR:
                        return SirGUID;
                    case DATA_HEIGAN:
                        return HeiganGUID;
                    case DATA_GLUTH:
                        return GluthGUID;
                    case DATA_FEUGEN:
                        return FeugenGUID;
                    case DATA_STALAGG:
                        return StalaggGUID;
                    case DATA_THADDIUS:
                        return ThaddiusGUID;
                    case DATA_SAPPHIRON:
                        return SapphironGUID;
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
                                teleporter->RemoveFlag(GO_FLAG_NOT_SELECTABLE);

                            events.ScheduleEvent(EVENT_KELTHUZAD_WING_TAUNT, Seconds(6));
                        }
                        break;
                    case BOSS_LOATHEB:
                        if (state == DONE)
                        {
                            if (GameObject* teleporter = GetGameObject(DATA_NAXX_PORTAL_PLAGUE))
                                teleporter->RemoveFlag(GO_FLAG_NOT_SELECTABLE);

                            events.ScheduleEvent(EVENT_KELTHUZAD_WING_TAUNT, Seconds(6));
                        }
                        break;
                    case BOSS_THADDIUS:
                        if (state == DONE)
                        {
                            if (GameObject* teleporter = GetGameObject(DATA_NAXX_PORTAL_CONSTRUCT))
                                teleporter->RemoveFlag(GO_FLAG_NOT_SELECTABLE);

                            events.ScheduleEvent(EVENT_KELTHUZAD_WING_TAUNT, Seconds(6));
                        }
                        break;
                    case BOSS_GOTHIK:
                        if (state == DONE)
                            events.ScheduleEvent(EVENT_DIALOGUE_GOTHIK_KORTHAZZ, Seconds(10));
                        break;
                    case BOSS_HORSEMEN:
                        if (state == DONE)
                        {
                            if (GameObject* horsemenChest = instance->GetGameObject(HorsemenChestGUID))
                            {
                                horsemenChest->SetRespawnTime(horsemenChest->GetRespawnDelay());
                                horsemenChest->RemoveFlag(GO_FLAG_NOT_SELECTABLE);
                            }

                            if (GameObject* teleporter = GetGameObject(DATA_NAXX_PORTAL_MILITARY))
                                teleporter->RemoveFlag(GO_FLAG_NOT_SELECTABLE);

                            events.ScheduleEvent(EVENT_KELTHUZAD_WING_TAUNT, Seconds(6));
                        }
                        break;
                    case BOSS_SAPPHIRON:
                        if (state == DONE)
                            events.ScheduleEvent(EVENT_DIALOGUE_SAPPHIRON_KELTHUZAD, Seconds(6));
                        HandleGameObject(KelthuzadDoorGUID, false);
                        break;
                    case BOSS_KELTHUZAD:
                        if (state == DONE)
                            if (GameObject* throne = GetGameObject(DATA_KELTHUZAD_THRONE))
                                throne->RemoveFlag(GO_FLAG_NOT_SELECTABLE);
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
                            events.ScheduleEvent(EVENT_DIALOGUE_GOTHIK_ZELIEK, Seconds(5));
                            break;
                        case EVENT_DIALOGUE_GOTHIK_ZELIEK:
                            if (Creature* zeliek = instance->GetCreature(SirGUID))
                                zeliek->AI()->Talk(SAY_DIALOGUE_GOTHIK_HORSEMAN);
                            events.ScheduleEvent(EVENT_DIALOGUE_GOTHIK_BLAUMEUX, Seconds(6));
                            break;
                        case EVENT_DIALOGUE_GOTHIK_BLAUMEUX:
                            if (Creature* blaumeux = instance->GetCreature(LadyGUID))
                                blaumeux->AI()->Talk(SAY_DIALOGUE_GOTHIK_HORSEMAN);
                            events.ScheduleEvent(EVENT_DIALOGUE_GOTHIK_RIVENDARE, Seconds(6));
                            break;
                        case EVENT_DIALOGUE_GOTHIK_RIVENDARE:
                            if (Creature* rivendare = instance->GetCreature(BaronGUID))
                                rivendare->AI()->Talk(SAY_DIALOGUE_GOTHIK_HORSEMAN);
                            events.ScheduleEvent(EVENT_DIALOGUE_GOTHIK_BLAUMEUX2, Seconds(6));
                            break;
                        case EVENT_DIALOGUE_GOTHIK_BLAUMEUX2:
                            if (Creature* blaumeux = instance->GetCreature(LadyGUID))
                                blaumeux->AI()->Talk(SAY_DIALOGUE_GOTHIK_HORSEMAN2);
                            events.ScheduleEvent(EVENT_DIALOGUE_GOTHIK_ZELIEK2, Seconds(6));
                            break;
                        case EVENT_DIALOGUE_GOTHIK_ZELIEK2:
                            if (Creature* zeliek = instance->GetCreature(SirGUID))
                                zeliek->AI()->Talk(SAY_DIALOGUE_GOTHIK_HORSEMAN2);
                            events.ScheduleEvent(EVENT_DIALOGUE_GOTHIK_KORTHAZZ2, Seconds(6));
                            break;
                        case EVENT_DIALOGUE_GOTHIK_KORTHAZZ2:
                            if (Creature* korthazz = instance->GetCreature(ThaneGUID))
                                korthazz->AI()->Talk(SAY_DIALOGUE_GOTHIK_HORSEMAN2);
                            events.ScheduleEvent(EVENT_DIALOGUE_GOTHIK_RIVENDARE2, Seconds(6));
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
                        case EVENT_SUMMON_FROGGER_WAVE:
                        {
                            std::list<TempSummon*> spawns;
                            instance->SummonCreatureGroup(nextFroggerWave, &spawns);
                            if (!spawns.empty())
                                (*spawns.begin())->GetMotionMaster()->MovePath(10 * NPC_FROGGER + nextFroggerWave, false);
                            events.Repeat(Seconds(1) + Milliseconds(666));
                            nextFroggerWave = (nextFroggerWave+1) % 3;
                            break;
                        }
                        case EVENT_DIALOGUE_SAPPHIRON_KELTHUZAD:
                            if (Creature* kelthuzad = instance->GetCreature(KelthuzadGUID))
                                kelthuzad->AI()->Talk(SAY_DIALOGUE_SAPPHIRON_KELTHUZAD);
                            events.ScheduleEvent(EVENT_DIALOGUE_SAPPHIRON_LICHKING, Seconds(6));
                            break;
                        case EVENT_DIALOGUE_SAPPHIRON_LICHKING:
                            if (Creature* lichKing = instance->GetCreature(LichKingGUID))
                                lichKing->AI()->Talk(SAY_DIALOGUE_SAPPHIRON_LICH_KING);
                            events.ScheduleEvent(EVENT_DIALOGUE_SAPPHIRON_KELTHUZAD2, Seconds(16));
                            break;
                        case EVENT_DIALOGUE_SAPPHIRON_KELTHUZAD2:
                            if (Creature* kelthuzad = instance->GetCreature(KelthuzadGUID))
                                kelthuzad->AI()->Talk(SAY_DIALOGUE_SAPPHIRON_KELTHUZAD2);
                            events.ScheduleEvent(EVENT_DIALOGUE_SAPPHIRON_LICHKING2, Seconds(9));
                            break;
                        case EVENT_DIALOGUE_SAPPHIRON_LICHKING2:
                            if (Creature* lichKing = instance->GetCreature(LichKingGUID))
                                lichKing->AI()->Talk(SAY_DIALOGUE_SAPPHIRON_LICH_KING2);
                            events.ScheduleEvent(EVENT_DIALOGUE_SAPPHIRON_KELTHUZAD3, Seconds(12));
                            break;
                        case EVENT_DIALOGUE_SAPPHIRON_KELTHUZAD3:
                            if (Creature* kelthuzad = instance->GetCreature(KelthuzadGUID))
                                kelthuzad->AI()->Talk(SAY_DIALOGUE_SAPPHIRON_KELTHUZAD3);
                            events.ScheduleEvent(EVENT_DIALOGUE_SAPPHIRON_KELTHUZAD4, Seconds(6));
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

            // This Function is called in CheckAchievementCriteriaMeet and CheckAchievementCriteriaMeet is called before SetBossState(bossId, DONE),
            // so to check if all bosses are done the checker must exclude 1 boss, the last done, if there is at most 1 encouter in progress when is
            // called this function then all bosses are done. The one boss that check is the boss that calls this function, so it is dead.
            bool AreAllEncountersDone()
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
                    // And They Would All Go Down Together (kill 4HM within 15sec of each other)
                    case 7600: // 25-man
                    case 7601: // 10-man
                        if (Creature* baron = instance->GetCreature(BaronGUID)) // it doesn't matter which one we use, really
                            return (baron->AI()->GetData(DATA_HORSEMEN_CHECK_ACHIEVEMENT_CREDIT) == 1u);
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
                        if (AreAllEncountersDone() && !playerDied)
                            return true;
                        return false;
                }

                return false;
            }

        protected:
            /* The Arachnid Quarter */
            // Anub'rekhan
            ObjectGuid AnubRekhanGUID;
            // Grand Widow Faerlina
            ObjectGuid FaerlinaGUID;

            /* The Plague Quarter */
            // Heigan the Unclean
            ObjectGuid HeiganGUID;

            /* The Military Quarter */
            // Instructor Razuvious
            ObjectGuid RazuviousGUID;
            // Gothik the Harvester
            ObjectGuid GothikGUID;
            ObjectGuid GothikGateGUID;
            // The Four Horsemen
            ObjectGuid ThaneGUID;
            ObjectGuid LadyGUID;
            ObjectGuid BaronGUID;
            ObjectGuid SirGUID;
            ObjectGuid HorsemenChestGUID;

            /* The Construct Quarter */
            // Gluth
            ObjectGuid GluthGUID;
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
            bool hadAnubRekhanGreet;
            bool hadFaerlinaGreet;
            bool hadThaddiusGreet;
            bool hadSapphironBirth;
            uint8 CurrentWingTaunt;

            /* The Immortal / The Undying */
            uint32 playerDied;

            int8 nextFroggerWave;

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
