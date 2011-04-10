/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2011 gmlt.A
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
 
enum eSpells
{

    SPELL_MUSIC_START           = 75760,
    SPELL_MUSIC                 = 75765,
    SPELL_MUSIC_END             = 75767,

    SPELL_HEALTH_REGEN          = 74503,
    // SPELL_BRILLIANT_TACTICS  = 74719 or 74501 ? I'll check it later.

    SPELL_CANNON_SHIELD         = 74458,

};

enum eCreatures
{

///----------------Allies---------------
    NPC_MEKKATORQUE             = 39271,
    NPC_BATTLE_SUIT             = 39902,
    NPC_INFANTRY                = 39252,
    NPC_BOMBER                  = 39735,
    NPC_ELGIN                   = 40478,
    NPC_TANK                    = 39860,

///----------------Enemies---------------
    NPC_I_INFANTRY              = 39755,
    NPC_I_CAVALRY               = 39836,
    NPC_BRAG_BOT                = 39901,
    NPC_GASERIKK                = 39799,
    NPC_BOLTCOG                 = 39837,
    NPC_I_TROGG                 = 39826,
    NPC_I_TANK                  = 39819,
    NPC_CANNON                  = 39759, // Tankbuster Cannon
    NPC_RL                      = 39820, // Rocket Launcher

};

enum eMisc
{

    QUEST_OPERATION_GNOMEREGAN  = 25393,
    DATA_MOUNT                  = 31692,

};
