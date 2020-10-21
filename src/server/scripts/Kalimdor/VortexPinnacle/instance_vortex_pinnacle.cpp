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
#include "CreatureAI.h"
#include "EventMap.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "TemporarySummon.h"
#include "WorldStatePackets.h"
#include "vortex_pinnacle.h"

#define MAX_ENCOUNTER 3

/* The Vortex Pinnacle encounters:
0 - Grand Vizier Ertan
1 - Altairus
2 - Asaad
*/

struct SlipstreamVehicleData
{
    uint32 VehicleId;
    uint32 GuidDataId;
    Position const SpawnPosition;
};

std::vector<SlipstreamVehicleData> SlipStreamInfo =
{
    // Grandvizier Ertan Slipstream Link
    { 1111, DATA_SLIPSTREAM_ERTAN_1, { -775.517f, -70.9323f, 640.3123f, 0.0f } },
    { 1112, DATA_SLIPSTREAM_ERTAN_2, { -848.227f, -68.724f,  654.2203f, 0.0f } },
    { 1113, DATA_SLIPSTREAM_ERTAN_3, { -844.885f, -205.135f, 660.7083f, 0.0f } },

    // Altairus Slipstream Link
    { 1111, DATA_SLIPSTREAM_ALTAIRUS_1, { -1190.88f, 125.203f, 737.6243f, 0.0f } },
    { 1112, DATA_SLIPSTREAM_ALTAIRUS_2, { -1138.55f, 178.524f, 711.4943f, 0.0f } },
    { 1149, DATA_SLIPSTREAM_ALTAIRUS_3, { -1245.21f, 230.986f, 690.6083f, 0.0f } },
    { 1150, DATA_SLIPSTREAM_ALTAIRUS_4, { -1282.07f, 344.856f, 660.9873f, 0.0f } },
    { 1113, DATA_SLIPSTREAM_ALTAIRUS_5, { -1229.64f, 412.26f,  641.2933f, 0.0f } },

    // Asaad Slipstream Link
    { 1551, DATA_SLIPSTREAM_ASAAD_1, { -746.9566f, 529.1406f, 644.8316f, 0.0f } },

    // Entrance Slipstream Link
    { 1305, DATA_SLIPSTREAM_ENTRANCE_1, { -310.4583f, -29.74479f, 625.0833f, 0.0f } },
    { 1306, DATA_SLIPSTREAM_ENTRANCE_2, { -382.441f,  42.31597f,  625.0833f, 0.0f } }
};

Position const SouthZephyrSummonLocation = { -1072.87f,  432.4446f, 646.7279f, 6.157519f  };
Position const NorthZephyrSummonLocation = { -781.4438f, 491.1446f, 698.0991f, 0.3193802f };

Position const FirstPrismGroundingFieldTop = { -1008.997f, 474.3663f, 708.1033f, 0.0f };
Position const FirstPrismGroundingFieldPoints[PrismGroundingFieldPoints] =
{
    {  -990.934f, 466.7552f, 700.0436f, 0.0f },
    { -1021.677f, 461.6684f, 700.1023f, 0.0f },
    { -1016.434f, 492.8455f, 700.0325f, 0.0f },
};

Position const SecondPrismGroundingFieldTop = { -829.7674f, 477.9531f, 708.1063f, 4.328416f };
Position const SecondPrismGroundingFieldPoints[PrismGroundingFieldPoints] =
{
    { -851.3368f, 469.3629f, 700.0286f, 4.328416f },
    { -820.2327f, 468.5017f, 700.1062f, 4.328416f },
    { -821.4792f, 500.3004f, 700.0289f, 4.328416f },
};

ObjectData const creatureData[] =
{
    { BOSS_GRAND_VIZIER_ERTAN,  DATA_GRAND_VIZIER_ERTAN },
    { BOSS_ALTAIRUS,            DATA_ALTAIRUS           },
    { BOSS_ASAAD,               DATA_ASAAD              },
    { 0,                        0                       } // END
};

enum Events
{
    EVENT_SUMMON_ZEPHYRS = 1
};

BossBoundaryData const boundaries =
{
    { DATA_GRAND_VIZIER_ERTAN, new CircleBoundary(Position(-719.430f,   4.329f), 60.0f) },
    { DATA_ALTAIRUS,           new CircleBoundary(Position(-1215.796f, 64.425f), 50.0f) },
    { DATA_ASAAD,              new CircleBoundary(Position(-622.729f, 503.509f), 45.0f) }
};

class instance_vortex_pinnacle : public InstanceMapScript
{
    public:
        instance_vortex_pinnacle() : InstanceMapScript(VPScriptName, 657) { }

        struct instance_vortex_pinnacle_InstanceScript : public InstanceScript
        {
            instance_vortex_pinnacle_InstanceScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(MAX_ENCOUNTER);
                LoadObjectData(creatureData, nullptr);
                LoadBossBoundaries(boundaries);

                SummonGroundingFieldPrism(FirstPrismGroundingFieldTop, FirstPrismGroundingFieldPoints);
                SummonGroundingFieldPrism(SecondPrismGroundingFieldTop, SecondPrismGroundingFieldPoints);

                _events.ScheduleEvent(EVENT_SUMMON_ZEPHYRS, 1s);
                _collectedGoldenOrbs = 0;
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                switch (creature->GetEntry())
                {
                    case NPC_HOWLING_GALE:
                        creature->SetDisplayId(creature->GetCreatureTemplate()->Modelid2);
                        break;
                    case NPC_AIR_CURRENT:
                        _airCurrentGUIDs.push_back(creature->GetGUID());
                        break;
                    case NPC_SLIPSTREAM:
                        for (SlipstreamVehicleData info : SlipStreamInfo)
                        {
                            if (creature->GetExactDist2d(info.SpawnPosition) < 1.0f)
                            {
                                /*
                                    Get rid of the old vehicleId and install a new vehicle kit based on the real one.
                                    We have to keep a vehicleId in the creature_template entry so the update_object packet
                                    will send a initial vehicle id so the clientside visuals wont break.
                                */
                                if (creature->GetVehicleKit())
                                    creature->RemoveVehicleKit();

                                creature->CreateVehicleKit(info.VehicleId, creature->GetEntry());
                                if (info.GuidDataId != DATA_SLIPSTREAM_ERTAN_1 && info.GuidDataId != DATA_SLIPSTREAM_ALTAIRUS_1 &&
                                    info.GuidDataId != DATA_SLIPSTREAM_ASAAD_1 && info.GuidDataId != DATA_SLIPSTREAM_ENTRANCE_1 &&
                                    info.GuidDataId != DATA_SLIPSTREAM_ENTRANCE_2)
                                    creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                                else
                                {
                                    creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                    creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                                }
                                AddObject(creature, info.GuidDataId, true);
                                break;
                            }
                        }
                        break;
                    case NPC_GOLDEN_ORB:
                        creature->SetDisplayId(creature->GetCreatureTemplate()->Modelid2);
                        break;
                    default:
                        break;
                }
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                InstanceScript::SetBossState(type, state);

                if (type == DATA_ALTAIRUS && (state == DONE || state == FAIL))
                {
                    for (ObjectGuid guid : _airCurrentGUIDs)
                        if (Creature* air = instance->GetCreature(guid))
                            air->DespawnOrUnsummon(0, 30s);

                    _airCurrentGUIDs.clear();
                }

                return true;
            }

            void SetData(uint32 type, uint32 /*value*/) override
            {
                switch (type)
                {
                    case DATA_COLLECTED_GOLDEN_ORB:
                        _collectedGoldenOrbs++;
                        DoUpdateWorldState(WS_GOLDEN_ORBS_COLLECTED, _collectedGoldenOrbs);
                        if (_collectedGoldenOrbs == 5)
                            DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET2, SPELL_ACHIEVEMENT_CHECK);
                        SaveToDB();
                        break;
                    default:
                        break;
                }
            }

            void Update(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SUMMON_ZEPHYRS:
                            if (instance->IsGridLoaded(SouthZephyrSummonLocation))
                                if (TempSummon* zephyr = instance->SummonCreature(NPC_ZEPHYR, SouthZephyrSummonLocation, nullptr, 18 * IN_MILLISECONDS))
                                    zephyr->GetMotionMaster()->MovePath(PATH_ZEPHYR_SOUTH, false);
                            if (instance->IsGridLoaded(NorthZephyrSummonLocation))
                                if (TempSummon* zephyr = instance->SummonCreature(NPC_ZEPHYR, NorthZephyrSummonLocation, nullptr, 18 * IN_MILLISECONDS))
                                    zephyr->GetMotionMaster()->MovePath(PATH_ZEPHYR_NORTH, false);
                            _events.Repeat(10s);
                            break;
                        default:
                            break;
                    }
                }
            }

            void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& data) override
            {
                data.Worldstates.emplace_back(uint32(WS_GOLDEN_ORBS_COLLECTED), uint32(_collectedGoldenOrbs));
            }

            void WriteSaveDataMore(std::ostringstream& data) override
            {
                data << _collectedGoldenOrbs;
            }

            void ReadSaveDataMore(std::istringstream& data) override
            {
                data >> _collectedGoldenOrbs;
            }

        private:
            // Spawns Grounding Field prism
            void SummonGroundingFieldPrism(Position positionTop, const Position positionPoints[PrismGroundingFieldPoints])
            {
                // Spawn lower three grounding fields
                TempSummon* points[PrismGroundingFieldPoints];
                for (uint32 i = 0; i < PrismGroundingFieldPoints; i++)
                    points[i] = instance->SummonCreature(NPC_GROUNDING_FIELD, positionPoints[i]);

                // If all three grounding fields spawned, cast beams and spawn the upper grounding field
                if (points[0] && points[1] && points[2])
                {
                    points[1]->CastSpell(points[0], SPELL_BEAM_A, true);
                    points[2]->CastSpell(points[1], SPELL_BEAM_B, true);
                    points[0]->CastSpell(points[2], SPELL_BEAM_C, true);

                    if (TempSummon* top = instance->SummonCreature(NPC_GROUNDING_FIELD, positionTop))
                        top->AI()->DoAction(ACTION_GROUNDING_FIELD_TOP);
                }
            }

            EventMap _events;
            GuidVector _airCurrentGUIDs;
            uint8 _collectedGoldenOrbs;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_vortex_pinnacle_InstanceScript(map);
        }
};

void AddSC_instance_vortex_pinnacle()
{
    new instance_vortex_pinnacle();
}
