/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#ifndef SiegeOfOrgrimmar_H
#define SiegeOfOrgrimmar_H

#define DataHeader "SOO"

uint32 const EncounterCount       = 14;

enum Data
{
    // Encounter States/Boss GUIDs
    DATA_Immerseus                 = 0,
    DATA_TheFallenProtectors       = 1,
    DATA_Norushen                  = 2,
    DATA_ShaOfPride                = 3,
    DATA_Galakras                  = 4,
    DATA_IronJuggernaut            = 5,
    DATA_KorKron                   = 6,
    DATA_GeneralNazgrim            = 7,
    DATA_Malkorok                  = 8,
    DATA_SpoilsOfPandaria          = 9,
    DATA_Thok                      = 10,
    DATA_SiegecrafterBlackfuse     = 11,
    DATA_ParagonsOfTheKlaxxi       = 12,
    DATA_GarroshHellscream         = 13
};

enum CreatureIds
{
    BOSS_Immerseus                 = 71543,
    BOSS_TheFallenProtectors       = 71480,
    BOSS_Norushen                  = 71967,
    BOSS_ShaOfPride                = 71734,
    BOSS_Galakras                  = 72249,
    BOSS_IronJuggernaut            = 71466,
    BOSS_KorKron                   = 71859,
    BOSS_GeneralNazgrim            = 71515,
    BOSS_Malkorok                  = 71454,
    BOSS_SpoilsOfPandaria          = 73152,
    BOSS_Thok                      = 71529,
    BOSS_SiegecrafterBlackfuse     = 71504,
    BOSS_ParagonsOfTheKlaxxi       = 71161,
    BOSS_GarroshHellscream         = 71865
};

enum GameObjectIds
{
};

#endif
