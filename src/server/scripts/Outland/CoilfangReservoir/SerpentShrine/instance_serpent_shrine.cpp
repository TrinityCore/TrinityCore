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

/* ScriptData
SDName: Instance_Serpent_Shrine
SD%Complete: 100
SDComment: Instance Data Scripts and functions to acquire mobs and set encounter status for use in various Serpent Shrine Scripts
SDCategory: Coilfang Resevoir, Serpent Shrine Cavern
EndScriptData */

#include "ScriptMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "Map.h"
#include "Player.h"
#include "serpent_shrine.h"
#include "TemporarySummon.h"

#define MAX_ENCOUNTER 6

enum Misc
{
    // Spells
    SPELL_SCALDINGWATER             = 37284,

    // Creatures
    NPC_COILFANG_FRENZY             = 21508,
    NPC_COILFANG_PRIESTESS          = 21220,
    NPC_COILFANG_SHATTERER          = 21301,

    // Misc
    MIN_KILLS                       = 30
};

//NOTE: there are 6 platforms
//there should be 3 shatterers and 2 priestess on all platforms, total of 30 elites, else it won't work!
//delete all other elites not on platforms! these mobs should only be on those platforms nowhere else.

/* Serpentshrine cavern encounters:
0 - Hydross The Unstable event
1 - Leotheras The Blind Event
2 - The Lurker Below Event
3 - Fathom-Lord Karathress Event
4 - Morogrim Tidewalker Event
5 - Lady Vashj Event
*/

static constexpr ObjectData creatureData[] =
{
    { NPC_LADY_VASHJ,          BOSS_LADY_VASHJ },
    { 0,                       0               } // END
};

static constexpr ObjectData gameObjectData[] =
{
    { GO_BRIDGE_PART_1,           DATA_BRIDGE_PART_1      },
    { GO_BRIDGE_PART_2,           DATA_BRIDGE_PART_2      },
    { GO_BRIDGE_PART_3,           DATA_BRIDGE_PART_3      },
    { GO_SHIELD_GENERATOR_1,      DATA_SHIELD_GENERATOR_1 },
    { GO_SHIELD_GENERATOR_2,      DATA_SHIELD_GENERATOR_2 },
    { GO_SHIELD_GENERATOR_3,      DATA_SHIELD_GENERATOR_3 },
    { GO_SHIELD_GENERATOR_4,      DATA_SHIELD_GENERATOR_4 },
    { 0,                          0                       } //END
};

class instance_serpent_shrine : public InstanceMapScript
{
    public:
        instance_serpent_shrine() : InstanceMapScript(SSCScriptName, 548) { }

        struct instance_serpentshrine_cavern_InstanceMapScript : public InstanceScript
        {
            instance_serpentshrine_cavern_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(MAX_ENCOUNTER);
                LoadObjectData(creatureData, gameObjectData);

                StrangePool = 0;
                Water = WATERSTATE_FRENZY;

                FishingTimer = 1000;
                WaterCheckTimer = 500;
                FrenzySpawnTimer = 2000;
                DoSpawnFrenzy = false;
                TrashCount = 0;
            }

            void Update(uint32 diff) override
            {
                //Water checks
                if (WaterCheckTimer <= diff)
                {
                    if (TrashCount >= MIN_KILLS)
                        Water = WATERSTATE_SCALDING;
                    else
                        Water = WATERSTATE_FRENZY;

                    Map::PlayerList const& PlayerList = instance->GetPlayers();
                    if (PlayerList.isEmpty())
                        return;
                    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    {
                        if (Player* player = i->GetSource())
                        {
                            if (player->IsAlive() && /*i->GetSource()->GetPositionZ() <= -21.434931f*/player->IsInWater())
                            {
                                if (Water == WATERSTATE_SCALDING)
                                {
                                    if (!player->HasAura(SPELL_SCALDINGWATER))
                                        player->CastSpell(player, SPELL_SCALDINGWATER, true);

                                }
                                else
                                {
                                    //spawn frenzy
                                    if (DoSpawnFrenzy)
                                    {
                                        if (Creature* frenzy = player->SummonCreature(NPC_COILFANG_FRENZY, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), player->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 2s))
                                        {
                                            frenzy->Attack(player, false);
                                            frenzy->SetSwim(true);
                                            frenzy->SetDisableGravity(true);
                                        }
                                        DoSpawnFrenzy = false;
                                    }
                                }
                            }
                            if (!player->IsInWater())
                                player->RemoveAurasDueToSpell(SPELL_SCALDINGWATER);
                        }

                    }
                    WaterCheckTimer = 500;//remove stress from core
                }
                else
                    WaterCheckTimer -= diff;

                if (FrenzySpawnTimer <= diff)
                {
                    DoSpawnFrenzy = true;
                    FrenzySpawnTimer = 2000;
                }
                else
                    FrenzySpawnTimer -= diff;
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                switch (creature->GetEntry())
                {
                    case 21214:
                        Karathress = creature->GetGUID();
                        break;
                    case 21966:
                        Sharkkis = creature->GetGUID();
                        break;
                    case 21217:
                        LurkerBelow = creature->GetGUID();
                        break;
                    case 21965:
                        Tidalvess = creature->GetGUID();
                        break;
                    case 21964:
                        Caribdis = creature->GetGUID();
                        break;
                    case 21215:
                        LeotherasTheBlind = creature->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void SetGuidData(uint32 type, ObjectGuid data) override
            {
                if (type == DATA_LEOTHERAS_EVENT_STARTER)
                    LeotherasEventStarter = data;
            }

            ObjectGuid GetGuidData(uint32 identifier) const override
            {
                switch (identifier)
                {
                    case DATA_THELURKERBELOW:
                        return LurkerBelow;
                    case DATA_SHARKKIS:
                        return Sharkkis;
                    case DATA_TIDALVESS:
                        return Tidalvess;
                    case DATA_CARIBDIS:
                        return Caribdis;
                    case DATA_KARATHRESS:
                        return Karathress;
                    case DATA_LEOTHERAS:
                        return LeotherasTheBlind;
                    case DATA_LEOTHERAS_EVENT_STARTER:
                        return LeotherasEventStarter;
                    default:
                        break;
                }
                return ObjectGuid::Empty;
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_STRANGE_POOL:
                        StrangePool = data;
                        break;
                    case DATA_TRASH:
                        if (data == 1 && TrashCount < MIN_KILLS)
                            ++TrashCount;//+1 died
                        SaveToDB();
                        break;
                    case DATA_WATER:
                        Water = data;
                        break;
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_STRANGE_POOL:
                        return StrangePool;
                    case DATA_WATER:
                        return Water;
                    default:
                        break;
                }

                return 0;
            }

            void WriteSaveDataMore(std::ostringstream& stream) override
            {
                stream << TrashCount;
            }

            void ReadSaveDataMore(std::istringstream& stream) override
            {
                stream >> TrashCount;
            }

        private:
            ObjectGuid LurkerBelow;
            ObjectGuid Sharkkis;
            ObjectGuid Tidalvess;
            ObjectGuid Caribdis;
            ObjectGuid Karathress;
            ObjectGuid LeotherasTheBlind;
            ObjectGuid LeotherasEventStarter;

            uint32 StrangePool;
            uint32 FishingTimer;
            uint32 WaterCheckTimer;
            uint32 FrenzySpawnTimer;
            uint32 Water;
            uint32 TrashCount;

            bool DoSpawnFrenzy;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_serpentshrine_cavern_InstanceMapScript(map);
        }
};

void AddSC_instance_serpentshrine_cavern()
{
    new instance_serpent_shrine();
}
