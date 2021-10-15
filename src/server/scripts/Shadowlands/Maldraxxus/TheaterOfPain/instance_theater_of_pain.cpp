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

#include "ScriptMgr.h"
#include "Player.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "InstanceScript.h"
#include "theater_of_pain.h"
#include "InstanceScript.h"

 //2293

class instance_theater_of_pain : public InstanceMapScript
{
public:
    instance_theater_of_pain() : InstanceMapScript(ABTScriptName, 2293) { }

    struct instance_theater_of_pain_InstanceMapScript : public InstanceScript
    {
        instance_theater_of_pain_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_theater_of_pain_InstanceMapScript(map);
        }
    };
};

void AddSC_instance_theater_of_pain()
{
    new instance_theater_of_pain();
}
