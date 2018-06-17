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
#include "vault_of_the_wardens.h"

class instance_vault_of_the_wardens : public InstanceMapScript
{
    public:
        instance_vault_of_the_wardens() : InstanceMapScript("instance_vault_of_the_wardens", 1493) { }

        struct instance_vault_of_the_wardens_InstanceMapScript : public InstanceScript
        {
            instance_vault_of_the_wardens_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }

            void Initialize() override
            {
                SetBossNumber(DATA_MAX_ENCOUNTERS);
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_vault_of_the_wardens_InstanceMapScript(map);
        }
};

void AddSC_instance_vault_of_the_wardens()
{
    new instance_vault_of_the_wardens();
}