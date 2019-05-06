/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "GameObject.h"
#include "gnomeregan.h"
#include "InstanceScript.h"
#include "Log.h"
#include "Map.h"
#include "Player.h"

class instance_gnomeregan : public InstanceMapScript
{
public:
    instance_gnomeregan() : InstanceMapScript(GNOScriptName, 90) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_gnomeregan_InstanceMapScript(map);
    }

    struct instance_gnomeregan_InstanceMapScript : public InstanceScript
    {
        instance_gnomeregan_InstanceMapScript(Map* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(MAX_ENCOUNTER);
        }

        ObjectGuid uiCaveInLeftGUID;
        ObjectGuid uiCaveInRightGUID;

        ObjectGuid uiBlastmasterEmiShortfuseGUID;

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case NPC_BLASTMASTER_EMI_SHORTFUSE:
                    uiBlastmasterEmiShortfuseGUID = creature->GetGUID();
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case GO_CAVE_IN_LEFT:
                    uiCaveInLeftGUID = go->GetGUID();
                    break;
                case GO_CAVE_IN_RIGHT:
                    uiCaveInRightGUID = go->GetGUID();
                    break;
            }
        }

        void OnUnitDeath(Unit* unit) override
        {
            Creature* creature = unit->ToCreature();
            if (creature)
                switch (creature->GetEntry())
                {
                    case NPC_VICIOUS_FALLOUT:
                        SetBossState(DATA_VICIOUS_FALLOUT, DONE);
                        break;
                    case NPC_ELECTROCUTIONER:
                        SetBossState(DATA_ELECTROCUTIONER, DONE);
                        break;
                    case NPC_CROWD_PUMMELER:
                        SetBossState(DATA_CROWD_PUMMELER, DONE);
                        break;
                    case NPC_MEKGINEER:
                        SetBossState(DATA_THERMAPLUGG, DONE);
                        break;
                }
        }

        ObjectGuid GetGuidData(uint32 uiType) const override
        {
            switch (uiType)
            {
                case DATA_GO_CAVE_IN_LEFT:              return uiCaveInLeftGUID;
                case DATA_GO_CAVE_IN_RIGHT:             return uiCaveInRightGUID;
                case DATA_NPC_BASTMASTER_EMI_SHORTFUSE: return uiBlastmasterEmiShortfuseGUID;
            }

            return ObjectGuid::Empty;
        }
    };

};

void AddSC_instance_gnomeregan()
{
    new instance_gnomeregan();
}
