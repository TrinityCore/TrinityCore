/*
 * Copyright (C) 2022 BfaCore Reforged
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

 /*scenario_you_cant_take_the_sky_from_me*/
struct scenario_you_cant_take_the_sky_from_me : public InstanceScript
{
    scenario_you_cant_take_the_sky_from_me(InstanceMap* map) : InstanceScript(map) { }

};

void AddSC_scenario_you_cant_take_the_sky_from_me()
{
    RegisterInstanceScript(scenario_you_cant_take_the_sky_from_me, 1731);
}
