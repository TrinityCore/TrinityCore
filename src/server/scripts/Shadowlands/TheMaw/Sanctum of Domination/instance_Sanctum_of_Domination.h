/*
 * Copyright 2021 FuzionCore Project
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

/* Script Data Start
SDName: 
SDAuthor: Frozen
SD%Complete: %
SDComment: still working on structure.
Script Data End */

struct instance_Sanctum_of_Domination : public InstanceScript
{
    instance_Sanctum_of_Domination(InstanceMap* map) : InstanceScript(map) { }
};

void AddSC_instance_Sanctum_of_Domination()
{
    RegisterInstanceScript(instance_Sanctum_of_Domination, 13561);
};