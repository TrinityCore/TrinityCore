/*
 * Copyright (C) 2022 BfaCore Reforged
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

#include "GameObject.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "InstanceScript.h"
#include "shadowmoon_burial_grounds.h"

class instance_shadowmoon_burial_grounds : public InstanceMapScript
{
    public:
        instance_shadowmoon_burial_grounds() : InstanceMapScript(CoSScriptName, 1176) { }

        struct instance_shadowmoon_burial_grounds_InstanceMapScript : public InstanceScript
        {
            instance_shadowmoon_burial_grounds_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetBossNumber(EncounterCount);
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch(go->GetEntry())
                {
                    case GO_SADANA_GATE_1:
                        sadanaGate1 = go->GetGUID();
                        break;
                    case GO_SADANA_GATE_2:
                        sadanaGate2 = go->GetGUID();
                        break;
                    case GO_NHALLISH_GATE:
                        nhallishGate = go->GetGUID();
                        break;
                    case GO_BONEMAW_GATE_1:
                        bonemawGate1 = go->GetGUID();
                        break;
                    case GO_BONEMAW_GATE_2:
                        bonemawGate2 = go->GetGUID();
                        break;
                    case GO_BONEMAW_GATE_3:
                        bonemawGate3 = go->GetGUID();
                        break;
                    case GO_NERZHUL_GATE:
                        nerzhulGate = go->GetGUID();
                        break;
                }
            }

            ObjectGuid GetGuidData(uint32 data) const override
            {
                switch (data)
                {
                    case DATA_SADANA_GATE_1:
                        return sadanaGate1;
                    case DATA_SADANA_GATE_2:
                        return sadanaGate2;
                    case DATA_NHALLISH_GATE:
                        return nhallishGate;
                    case DATA_BONEMAW_GATE_1:
                        return bonemawGate1;
                    case DATA_BONEMAW_GATE_2:
                        return bonemawGate2;
                    case DATA_BONEMAW_GATE_3:
                        return bonemawGate3;
                    case DATA_NERZHUL_GATE:
                        return nerzhulGate;
                    default:
                        break;
                }

                return ObjectGuid::Empty;
            }

            private:
                ObjectGuid sadanaGate1;
                ObjectGuid sadanaGate2;
                ObjectGuid nhallishGate;
                ObjectGuid bonemawGate1;
                ObjectGuid bonemawGate2;
                ObjectGuid bonemawGate3;
                ObjectGuid nerzhulGate;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_shadowmoon_burial_grounds_InstanceMapScript(map);
        }
};

void AddSC_instance_shadowmoon_burial_grounds()
{
    new instance_shadowmoon_burial_grounds();
}
