/*
* Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "CreatureAI.h"
#include "EventMap.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "TemporarySummon.h"
#include "vortex_pinnacle.h"

#define MAX_ENCOUNTER 3

/* The Vortex Pinnacle encounters:
0 - Grand Vizier Ertan
1 - Altairus
2 - Asaad
*/

struct Slipstream
{
    uint32 entry;
    uint32 vehicleId;
    Position position;
    uint32 data;
    uint32 bossData; // boss that has to die/be dead for Slipstream to spawn
};

Slipstream const SlipstreamData[Slipstreams] =
{
    // Grand Vizier Ertan Slipstreams
    { NPC_SLIPSTREAM, 1111, { -775.517f, -70.9323f, 640.3123f, 0.0f }, DATA_SLIPSTREAM_1, DATA_GRAND_VIZIER_ERTAN },
    { NPC_SLIPSTREAM, 1112, { -848.227f, -68.724f, 654.2203f, 0.0f }, DATA_SLIPSTREAM_2, DATA_GRAND_VIZIER_ERTAN },
    { NPC_SLIPSTREAM, 1113, { -844.885f, -205.135f, 660.7083f, 0.0f }, DATA_SLIPSTREAM_3, DATA_GRAND_VIZIER_ERTAN },
    // Grand Vizier Ertan Slipstream Landing Zone
    { NPC_SLIPSTREAM_LANDING_ZONE, 1114, { -906.08f, -176.514f, 664.5053f, 2.86234f }, 0, DATA_GRAND_VIZIER_ERTAN },
    // Altairus Slipstreams
    { NPC_SLIPSTREAM, 1111, { -1190.88f, 125.203f, 737.6243f, 0.0f }, DATA_SLIPSTREAM_4, DATA_ALTAIRUS },
    { NPC_SLIPSTREAM, 1112, { -1138.55f, 178.524f, 711.4943f, 0.0f }, DATA_SLIPSTREAM_5, DATA_ALTAIRUS },
    { NPC_SLIPSTREAM, 1149, { -1245.21f, 230.986f, 690.6083f, 0.0f }, DATA_SLIPSTREAM_6, DATA_ALTAIRUS },
    { NPC_SLIPSTREAM, 1150, { -1282.07f, 344.856f, 660.9873f, 0.0f }, DATA_SLIPSTREAM_7, DATA_ALTAIRUS },
    { NPC_SLIPSTREAM, 1113, { -1229.64f, 412.26f, 641.2933f, 0.0f }, DATA_SLIPSTREAM_8, DATA_ALTAIRUS },
    // Altairus Slipstream Landing Zone
    { NPC_SLIPSTREAM_LANDING_ZONE, 1114, { -1193.67f, 472.835f, 634.8653f, 0.5061455f }, 0, DATA_ALTAIRUS },
    // Asaad Slipstream
    { NPC_SLIPSTREAM, 1551, { -746.9566f, 529.1406f, 644.8316f, 0.0f }, DATA_SLIPSTREAM_9, DATA_ASAAD },
    // Entrance Slipstreams
    { NPC_SLIPSTREAM, 1305, { -310.4583f, -29.74479f, 625.0833f, 0.0f }, DATA_SLIPSTREAM_10, DATA_GRAND_VIZIER_ERTAN },
    { NPC_SLIPSTREAM, 1306, { -382.441f, 42.31597f, 625.0833f, 0.0f }, DATA_SLIPSTREAM_11, DATA_ALTAIRUS },
};

Position const SouthZephyrSummonLocation = { -1070.639f, 432.2814f, 647.0389f, 6.15166f };
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
    { NPC_ALTAIRUS, DATA_ALTAIRUS },
    { NPC_ASAAD, DATA_ASAAD },
    { 0, 0 }
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

                CheckSlipstreams();
                SummonGroundingFieldPrism(FirstPrismGroundingFieldTop, FirstPrismGroundingFieldPoints);
                SummonGroundingFieldPrism(SecondPrismGroundingFieldTop, SecondPrismGroundingFieldPoints);

                events.ScheduleEvent(EVENT_SUMMON_ZEPHYRS, 0);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_HOWLING_GALE:
                        creature->SetReactState(REACT_PASSIVE);
                        break;
                    default:
                        break;
                }

                InstanceScript::OnCreatureCreate(creature);
            }


            bool SetBossState(uint32 type, EncounterState state) override
            {
                InstanceScript::SetBossState(type, state);

                // Spawn Slipstreams
                if (state == DONE)
                    SummonSlipstreams(type);

                return true;
            }

            void Update(uint32 diff) override
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SUMMON_ZEPHYRS: // Summon Zephyrs every 10 seconds. There is no sniff data about trigger npc or spells that would handle summoning.
                            if (TempSummon* zephyr = instance->SummonCreature(NPC_ZEPHYR, SouthZephyrSummonLocation))
                                zephyr->GetMotionMaster()->MovePath(PATH_ZEPHYR_SOUTH, false);
                            if (TempSummon* zephyr = instance->SummonCreature(NPC_ZEPHYR, NorthZephyrSummonLocation))
                                zephyr->GetMotionMaster()->MovePath(PATH_ZEPHYR_NORTH, false);
                            events.ScheduleEvent(EVENT_SUMMON_ZEPHYRS, 10000);
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            // Check which Slipstreams can be spawned on script init
            void CheckSlipstreams()
            {
                if (GetBossState(DATA_GRAND_VIZIER_ERTAN) == DONE)
                    SummonSlipstreams(DATA_GRAND_VIZIER_ERTAN);
                if (GetBossState(DATA_ALTAIRUS) == DONE)
                    SummonSlipstreams(DATA_ALTAIRUS);
                if (GetBossState(DATA_ASAAD) == DONE)
                    SummonSlipstreams(DATA_ASAAD);
            }

            // Spawns Slipstreams belonging bossType
            void SummonSlipstreams(uint32 bossType)
            {
                for (uint8 i = 0; i < Slipstreams; ++i)
                {
                    if (SlipstreamData[i].bossData != bossType)
                        continue;

                    TempSummon* summon = instance->SummonCreature(SlipstreamData[i].entry, SlipstreamData[i].position);
                    if (!summon)
                        continue;

                    AddObject(summon, SlipstreamData[i].data, true);

                    if (SlipstreamData[i].data == DATA_SLIPSTREAM_1 || SlipstreamData[i].data == DATA_SLIPSTREAM_4 ||
                        SlipstreamData[i].data == DATA_SLIPSTREAM_10 || SlipstreamData[i].data == DATA_SLIPSTREAM_11)
                    {
                        summon->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                        summon->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        summon->setActive(true);
                    }

                    WorldPacket data(SMSG_PLAYER_VEHICLE_DATA, summon->GetPackGUID().size() + 4);
                    data << summon->GetPackGUID();
                    data << uint32(SlipstreamData[i].vehicleId);
                    summon->SendMessageToSet(&data, true);
                }
            }

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

            EventMap events;
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
