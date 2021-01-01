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

#include "Banner.h"
#include "GitRevision.h"
#include "StringFormat.h"

void Trinity::Banner::Show(char const* applicationName, void(*log)(char const* text), void(*logExtraInfo)())
{
    log(Trinity::StringFormat("%s (%s)", GitRevision::GetFullVersion(), applicationName).c_str());
    log("<Ctrl-C> to stop.\n");
    log("\n");
    log("################################################################################");
    log("################################################################################");
    log(" Core Shadowlands bas� sur Trinity http://TrinityCore.org - Stitch D�cembre 2020");
    log(" Remerciements a Noc et Galathil pour leurs aides");
    log(" ");
    log(" Modifications principales :");
    log(" - Races Alli�es Activ�es par d�faut (by Galathil)");
    log(" - Action suite a un �v�nement Joueur (Apprentissage,connexion,levelup,zone...");
    log(" - PNJ change race , faction , apparence");
    log(" - PNJ Lieux de depart chez une race alli� ou instant level 10");
    log(" - Aubergiste donne foyer et une pierre de foyer");
    log("################################################################################");
    log("################################################################################");
    log(" ");
    if (logExtraInfo)
        logExtraInfo();
}
