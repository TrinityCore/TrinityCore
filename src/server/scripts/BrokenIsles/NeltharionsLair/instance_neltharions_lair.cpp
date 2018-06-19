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
#include "neltharions_lair.h"

class instance_neltharions_lair : public InstanceMapScript
{
    public:
        instance_neltharions_lair() : InstanceMapScript("instance_neltharions_lair", 1458) { }

        struct instance_neltharions_lair_InstanceMapScript : public InstanceScript
        {
            instance_neltharions_lair_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }

            void Initialize() override
            {
                SetBossNumber(DATA_MAX_ENCOUNTERS);
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_neltharions_lair_InstanceMapScript(map);
        }
};

void AddSC_instance_neltharions_lair()
{
    new instance_neltharions_lair();
}