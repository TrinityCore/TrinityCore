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

#include "ScriptMgr.h"
#include "Player.h"
#include "InstanceScript.h"
#include "eye_of_azshara.h"

class instance_eye_of_azshara : public InstanceMapScript
{
    public:
        instance_eye_of_azshara() : InstanceMapScript(EoAScriptName, 1456) { }

        struct instance_eye_of_azshara_InstanceMapScript : public InstanceScript
        {
            instance_eye_of_azshara_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_eye_of_azshara_InstanceMapScript(map);
        }
};

void AddSC_instance_eye_of_azshara()
{
    new instance_eye_of_azshara();
}
