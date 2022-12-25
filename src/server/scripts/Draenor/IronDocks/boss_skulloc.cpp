/*
 * Copyright 2023 AzgathCore
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

#include "iron_docks.hpp"

enum eCreatures
{
    CreatureBackdraft = 432551,
    CreatureCannon    = 84030
};

enum eTalks
{
    TalkKoramarDeath    = 90,         ///< Inconcieveable... (43898)
    TalkKoramar12       = 50,         ///< How dare you marching into my docks, and so bravery set foot onto my ship.. nothing will stop the Iron Horde least of all you.. enjoy your death weaklings. (46911)
    TalkKoramar13       = 51,         ///< Zoggosh.. ready the ready the rocks! This.. Ends... Now! (46912)
    TalkZoggosh03       = 11,         ///< Yes sir.. (44049)
    TalkKoramarVengence = 60,

    TalkZoggoshDeath    = 91,         ///< (44063)


    /// Bombardmenet Bridge Event
    TalkZoggoshBombardmenet01 = 12,   ///< Sir.. they're messing with the Iron Stars (44050)
    TalkKoramarBombardmenet01 = 25,   ///< Hah! will you look on that, maybe I understimated them.. Zoggosh, prepare Skuloc let them have a taste of what he has to offer. (46901)
    TalkZoggoshBombardmenet02 = 13,   ///< Igniting the cannon sir! (44051)

    /// Past Bombardmement Bridge Event (Upon Grimrail Encounter)
    TalkKoramarPastBombardment01 = 27, ///< What is wrong with you?! keep firing you all! (46904)
    TalkZoggoshPastBombardment01 = 14, ///< Sir.. he's out of ammunition. I'm reloading.. I'm reloading!! (44052)
    TalkKoramarPastBombardment02 = 28  ///< Arghh.. forget it, they'll never make it pass the tracks.. (unknown message) (46905)
};

enum eMovementInformed
{
    MovementInformedKoramarJump = 1,
    MovementInformedKoramarBladestorm
};

enum eActions
{
    ActionKoramarStopBladestorming = 1
};

Position const g_BackdraftNpcPos = { 6859.93f, -989.91f, 23.054f, 3.000260f };

Position const g_HomeSkullcHomePos = { 6729.220f, -977.335f, 23.046f, 6.230830f};

Position const g_BladestormPositions[8] =
{
    {6730.51f, -986.184f, 23.046f},
    {6770.27f, -999.860f, 23.047f},
    {6740.20f, -1002.999f, 23.046f},
    {6783.170f, -967.849f, 23.180f},
    {6807.46f, -1001.870f, 23.048f},
    {6785.44f, -1001.138f, 23.046f},
    {6839.651f, -968.411f, 23.046f},
    {6757.62f, -986.855f,  22.815f}
};

void AddSC_boss_skulloc()
{
   
}
