/*
* Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "InstanceScript.h"
#include "violet_hold_legion.h"

class instance_violet_hold_legion : public InstanceMapScript
{
    public:
        instance_violet_hold_legion() : InstanceMapScript("instance_violet_hold_legion", 1544) { }

        struct instance_violet_hold_legion_InstanceMapScript : public InstanceScript
        {
            instance_violet_hold_legion_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }

            void Initialize() override
            {
                SetBossNumber(EncounterCount);
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_violet_hold_legion_InstanceMapScript(map);
        }
};

void AddSC_instance_violet_hold_legion()
{
    new instance_violet_hold_legion();
}