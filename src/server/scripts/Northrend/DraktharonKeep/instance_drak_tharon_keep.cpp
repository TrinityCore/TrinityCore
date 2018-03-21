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
#include "Creature.h"
#include "CreatureAI.h"
#include "drak_tharon_keep.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"

class instance_drak_tharon_keep : public InstanceMapScript
{
    public:
        instance_drak_tharon_keep() : InstanceMapScript(DrakTharonKeepScriptName, 600) { }

        struct instance_drak_tharon_keep_InstanceScript : public InstanceScript
        {
            instance_drak_tharon_keep_InstanceScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_TROLLGORE:
                        TrollgoreGUID = creature->GetGUID();
                        break;
                    case NPC_NOVOS:
                        NovosGUID = creature->GetGUID();
                        break;
                    case NPC_KING_DRED:
                        KingDredGUID = creature->GetGUID();
                        break;
                    case NPC_THARON_JA:
                        TharonJaGUID = creature->GetGUID();
                        break;
                    case NPC_WORLD_TRIGGER:
                        InitializeTrollgoreInvaderSummoner(creature);
                        break;
                    case NPC_CRYSTAL_CHANNEL_TARGET:
                        InitializeNovosSummoner(creature);
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_NOVOS_CRYSTAL_1:
                        NovosCrystalGUIDs[0] = go->GetGUID();
                        break;
                    case GO_NOVOS_CRYSTAL_2:
                        NovosCrystalGUIDs[1] = go->GetGUID();
                        break;
                    case GO_NOVOS_CRYSTAL_3:
                        NovosCrystalGUIDs[2] = go->GetGUID();
                        break;
                    case GO_NOVOS_CRYSTAL_4:
                        NovosCrystalGUIDs[3] = go->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void InitializeTrollgoreInvaderSummoner(Creature* creature)
            {
                float y = creature->GetPositionY();
                float z = creature->GetPositionZ();

                if (z < 50.0f)
                    return;

                if (y < -650.0f && y > -660.0f)
                    TrollgoreInvaderSummonerGuids[0] = creature->GetGUID();
                else if (y < -660.0f && y > -670.0f)
                    TrollgoreInvaderSummonerGuids[1] = creature->GetGUID();
                else if (y < -675.0f && y > -685.0f)
                    TrollgoreInvaderSummonerGuids[2] = creature->GetGUID();
            }

            void InitializeNovosSummoner(Creature* creature)
            {
                float x = creature->GetPositionX();
                float y = creature->GetPositionY();
                float z = creature->GetPositionZ();

                if (x < -374.0f && x > -379.0f && y > -820.0f && y < -815.0f && z < 60.0f && z > 58.0f)
                    NovosSummonerGUIDs[0] = creature->GetGUID();
                else if (x < -379.0f && x > -385.0f && y > -820.0f && y < -815.0f && z < 60.0f && z > 58.0f)
                    NovosSummonerGUIDs[1] = creature->GetGUID();
                else if (x < -374.0f && x > -385.0f && y > -827.0f && y < -820.0f && z < 60.0f && z > 58.0f)
                    NovosSummonerGUIDs[2] = creature->GetGUID();
                else if (x < -338.0f && x > -344.0f && y > -727.0f && y < 721.0f && z < 30.0f && z > 26.0f)
                    NovosSummonerGUIDs[3] = creature->GetGUID();
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_TROLLGORE:
                        return TrollgoreGUID;
                    case DATA_NOVOS:
                        return NovosGUID;
                    case DATA_KING_DRED:
                        return KingDredGUID;
                    case DATA_THARON_JA:
                        return TharonJaGUID;
                    case DATA_TROLLGORE_INVADER_SUMMONER_1:
                    case DATA_TROLLGORE_INVADER_SUMMONER_2:
                    case DATA_TROLLGORE_INVADER_SUMMONER_3:
                        return TrollgoreInvaderSummonerGuids[type - DATA_TROLLGORE_INVADER_SUMMONER_1];
                    case DATA_NOVOS_CRYSTAL_1:
                    case DATA_NOVOS_CRYSTAL_2:
                    case DATA_NOVOS_CRYSTAL_3:
                    case DATA_NOVOS_CRYSTAL_4:
                        return NovosCrystalGUIDs[type - DATA_NOVOS_CRYSTAL_1];
                    case DATA_NOVOS_SUMMONER_1:
                    case DATA_NOVOS_SUMMONER_2:
                    case DATA_NOVOS_SUMMONER_3:
                    case DATA_NOVOS_SUMMONER_4:
                        return NovosSummonerGUIDs[type - DATA_NOVOS_SUMMONER_1];
                }

                return ObjectGuid::Empty;
            }

            void OnUnitDeath(Unit* unit) override
            {
                if (unit->GetEntry() == NPC_CRYSTAL_HANDLER)
                    if (Creature* novos = instance->GetCreature(NovosGUID))
                        novos->AI()->DoAction(ACTION_CRYSTAL_HANDLER_DIED);
            }

        protected:
            ObjectGuid TrollgoreGUID;
            ObjectGuid NovosGUID;
            ObjectGuid KingDredGUID;
            ObjectGuid TharonJaGUID;

            ObjectGuid TrollgoreInvaderSummonerGuids[3];
            ObjectGuid NovosCrystalGUIDs[4];
            ObjectGuid NovosSummonerGUIDs[4];
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_drak_tharon_keep_InstanceScript(map);
        }
};

void AddSC_instance_drak_tharon_keep()
{
    new instance_drak_tharon_keep();
}
