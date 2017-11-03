/*
* Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#include "Creature.h"
#include "InstanceScript.h"
#include "the_vortex_pinnacle.h"
#include "ScriptMgr.h"
#include "ScriptMgr.h"

#define MAX_ENCOUNTER 3

class instance_the_vortex_pinnacle : public InstanceMapScript
{
    public:
        instance_the_vortex_pinnacle() : InstanceMapScript("instance_the_vortex_pinnacle", 657) { }

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_the_vortex_pinnacle_InstanceMapScript(map);
        }

        struct instance_the_vortex_pinnacle_InstanceMapScript: public InstanceScript
        {
            instance_the_vortex_pinnacle_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }

            ObjectGuid uiGrandVizierErtanGUID;
            ObjectGuid uiAltairusGUID;
            ObjectGuid uiAsaadGUID;

            void Initialize() override
            {
                SetBossNumber(MAX_ENCOUNTER);
            }

            void OnCreatureCreate(Creature* pCreature) override
            {
                switch(pCreature->GetEntry())
                {
                    case NPC_GRAND_VIZIER_ERTAN:
                        uiGrandVizierErtanGUID = pCreature->GetGUID();
                        break;
                    case NPC_ALTAIRUS:
                        uiAltairusGUID = pCreature->GetGUID();
                        break;
                    case NPC_ASAAD:
                        uiAsaadGUID = pCreature->GetGUID();
                        break;
                }

            }

            ObjectGuid GetGuidData(uint32 identifier) const override
            {
                switch(identifier)
                {
                    case DATA_ERTAN:
                        return uiGrandVizierErtanGUID;
                    case DATA_ALTAIRUS:
                        return uiAltairusGUID;
                    case DATA_ASAAD:
                        return uiAsaadGUID;
                }

                return ObjectGuid::Empty;
            }
        };
};

void AddSC_instance_the_vortex_pinnacle()
{
    new instance_the_vortex_pinnacle();
}
