/*
 * Copyright 2021 
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
#include "SpellAuraEffects.h"
#include "Map.h"
#include "InstanceScript.h"
#include "Transport.h"
#include "TransportMgr.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "zone_the_maw.cpp"
#include "objects_Sanctum_of_Domination.h"
#include "npc_Sanctum_of_Domination.h"
#include "Sanctum_of_Domination.h"
#include "zone_Sanctum_of_Domination.cpp"
#include "zone_Sanctum_of_Domination.h"
#include "instance_Sanctum_of_Domination.cpp"
#include "Sanctum_of_Domination.h"
#include "Boss_The_Tarragrue.cpp"
#include "Boss_The_Eye_of_the_Jailer.cpp"
#include "Boss_The_Nine"
#include "Boss_Remnant_of_Nerzhul.cpp"
#include "Boss_Soulrender_Dormazain.cpp"
#include "Boss_Painsmith_Raznal.cpp"
#include "Boss_Guardian_of_the_First_Ones.cpp"
#include "Boss_Fatescribe_Roh_Kalo.cpp"
#include "Boss_KelThuzad.cpp"
#include "Boss_Sylvanas_Windrunner.cpp"
 
const Position SpawnPosition[] =
{
    {-557.630f, -114.514f, -152.209f, 0.641f},
    {-555.263f, -113.802f, -152.737f, 0.311f},
    {-552.154f, -112.476f, -153.349f, 0.621f},
    {-548.692f, -111.089f, -154.090f, 0.621f},
    {-546.905f, -108.340f, -154.877f, 0.729f},
    {-547.736f, -105.154f, -155.176f, 0.372f},
    {-547.274f, -114.109f, -153.952f, 0.735f},
    {-552.534f, -110.012f, -153.577f, 0.747f},
    {-550.708f, -116.436f, -153.103f, 0.679f},
    {-554.030f, -115.983f, -152.635f, 0.695f},
    {-494.595f, -87.516f, -149.116f, 3.344f},
    {-493.349f, -90.845f, -148.882f, 3.717f},
    {-491.995f, -87.619f, -148.197f, 3.230f},
    {-490.732f, -90.739f, -148.091f, 3.230f},
    {-490.554f, -89.114f, -148.055f, 3.230f},
    {-495.240f, -90.808f, -149.493f, 3.238f},
    {-494.195f, -89.553f, -149.131f, 3.254f},
    {-511.3304f, -139.9622f, -152.4761f, 0.7504908f},
    {-510.6754f, -139.4371f, -152.6167f, 3.33359f},
    {-511.8976f, -139.3562f, -152.4785f, 3.961899f}
};
 
enum ObjectsDataScript
{
  void ObjectsData();
};
 
enum ObjectsSpawnsScript
{
  void ObjectsSpawns();
};

void AddSC_Objects_Data_Ardenweald()
{
  RegisterObjectsSpawnsScript(ObjectsSpawns); 
  RegisterObjectsDataScript(ObjectsData);
};