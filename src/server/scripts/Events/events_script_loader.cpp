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

// This is where scripts' loading functions should be declared:
void AddSC_event_brewfest();
void AddSC_event_childrens_week();
void AddSC_event_fireworks();
void AddSC_event_hallows_end();
void AddSC_event_love_is_in_the_air();
void AddSC_event_lunar_festival();
void AddSC_event_midsummer();
void AddSC_event_operation_gnomeregan();
void AddSC_event_pilgrims_bounty();
void AddSC_event_winter_veil();
void AddSC_event_zalazane_fall();

// The name of this function should match:
// void Add${NameOfDirectory}Scripts()
void AddEventsScripts()
{
    AddSC_event_brewfest();
    AddSC_event_childrens_week();
    AddSC_event_fireworks();
    AddSC_event_hallows_end();
    AddSC_event_love_is_in_the_air();
    AddSC_event_lunar_festival();
    AddSC_event_midsummer();
    AddSC_event_operation_gnomeregan();
    AddSC_event_pilgrims_bounty();
    AddSC_event_winter_veil();
    AddSC_event_zalazane_fall();
}
