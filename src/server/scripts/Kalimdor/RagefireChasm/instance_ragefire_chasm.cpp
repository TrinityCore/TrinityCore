/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

/*
This placeholder for the instance is needed for dungeon finding to be able
to give credit after the boss defined in lastEncounterDungeon is killed.
Without it, the party doing random dungeon won't get satchel of spoils and
gets instead the deserter debuff.
*/

#include "ScriptMgr.h"
#include "InstanceScript.h"

class instance_ragefire_chasm : public InstanceMapScript
{
public:
    instance_ragefire_chasm() : InstanceMapScript("instance_ragefire_chasm", 389) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_ragefire_chasm_InstanceMapScript(map);
    }

    struct instance_ragefire_chasm_InstanceMapScript : public InstanceScript
    {
        instance_ragefire_chasm_InstanceMapScript(Map* map) : InstanceScript(map) { }
    };
};

void AddSC_instance_ragefire_chasm()
{
    new instance_ragefire_chasm();
}
