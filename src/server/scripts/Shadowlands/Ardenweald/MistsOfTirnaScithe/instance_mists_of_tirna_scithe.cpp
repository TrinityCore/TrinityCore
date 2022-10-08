/*
 * Copyright 2021 ShadowCore
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
#include <SmartAI.h>
#include <DungeonFinding/LFGMgr.h>
#include <OutdoorPvP/OutdoorPvP.h>
#include <Globals/ObjectMgr.h>

struct instance_mists_of_tirna_scithe : public InstanceScript
{
    instance_mists_of_tirna_scithe(InstanceMap* map) : InstanceScript(map) { }
};

void AddSC_instance_mists_of_tirna_scithe()
{
    RegisterInstanceScript(instance_mists_of_tirna_scithe, 2290);
}

struct mist_of_tirna_scithe : public InstanceScript
{
  //  mist_of_tirna_scithe(InstanceMap*) : InstanceScript(mist_of_tirna_scithe()) { }
};	
void AddSC_mist_of_tirna_scithe()
{
    void AddSC_mist_of_tirna_scithe();
//	RegisterInstanceScript(mists_of_tirna_scithe,2291);
};
