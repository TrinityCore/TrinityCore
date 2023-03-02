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

enum eTalks
{
    /// Nok'gar
    SayAggro        = 0,    ///< Start the funeral pyres! (46057)
    SaySlay         = 1,    ///< Hahahaha my blade's thirst for war! (46061) / Revolt.. in the slaughter! (46060)
    SayDeath        = 2,    ///< You.. will burn.. with me. (46058)
    SayIntro        = 3,    ///< Warsong arrows sing from the skies, they'll be the last thing you hear as I crush your skull. (46059)
    SaySpell03      = 6,    ///< Terror overwhelms you.. Death is near! (46064)
    SaySpell04      = 7,    ///< A death worthy of a warrior. (46065)
    /// After Death
    TalkZoggosh01   = 8,    ///< Sir, they've breached the gates! Nok'gar is.. dead!! We should pick anchor and prepare to sail to Talador. Right now! (44047)
    TalkKoramar01   = 23,   ///< Calm yourself.. Zoggosh. We'll do no such thing, if these weaklings are so eager to die then we should obliged! (43899)
    TalkKoramar0222 = 24    ///< Zoggosh.. do not question my authority. This isn't just any Groon, this is Skuloc son of Grool.. the blood of a champion course through his veins.. I'm not concerned with these whelps. (43900)  
};

enum eSpells
{
    SpellRideVehicle                = 47020,
    SpellBarbedArrow                = 164370,
    SpellRecklessProvocation        = 164426,
    SpellIntimidated                = 164504,
    /// MISC
    SpellFeignDeath = 103750,
    SpellCosmeticFeignDeath = 166925
};

enum eMovementInformed
{
    MovementInformDreadfangShreddingStrikes = 1,
    MovementInformDreadfangFranticMauling
};

enum eActions
{
    ActionDismountHeroic    = 1,
    ActionBarbedArrow       = 2,
    ActionStop
};

enum eCreatures
{
    CreatureShreddingSwipes = 81832,
    CreatureWolf            = 81297
};

Position const g_ArchersPos[5] =
{
    { 6882.93f, -694.61f, 55.554f, 3.14270f },
    { 6883.21f, -705.07f, 55.922f, 3.13948f },
    { 6883.21f, -688.00f, 56.686f, 3.16305f },
    { 6884.02f, -676.18f, 56.483f, 3.34997f },
    { 6884.07f, -662.27f, 56.541f, 3.09864f }
};

void AddSC_boss_nokgar()
{
    
}
