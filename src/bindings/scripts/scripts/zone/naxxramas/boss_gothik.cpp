/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: Boss_Gothik
SD%Complete: 0
SDComment: Placeholder
SDCategory: Naxxramas
EndScriptData */

//Gothik
//8806 spch - Foolishly you have sought your own demise. Brazenly you have disregarded powers beyond your understanding. You have fought hard to invade the realm of the harvester. Now there is only one way out - to walk the lonely path of the damned.
//8808 tlpt - I have waited long enough! Now, you face the harvester of souls!
//8806 slay - Death is the only escape.
//8805 death - I... am... undone!

#include "precompiled.h"

//Gothik
#define SPELL_HARVESTSOUL           28679
#define SPELL_SHADOWBOLT            19729

//Unrelenting Trainee
#define SPELL_EAGLECLAW             30285
#define SPELL_KNOCKDOWN_PASSIVE     6961

//Unrelenting Deathknight
#define SPELL_CHARGE                22120
#define SPELL_SHADOW_MARK           27825

//Unrelenting Rider
#define SPELL_UNHOLY_AURA           28340
#define SPELL_SHADOWBOLT            19729                   //Search thru targets and find those who have the SHADOW_MARK to cast this on

//Spectral Trainee
#define SPELL_ARCANE_EXPLOSION      27989

//Spectral Deathknight
#define SPELL_WHIRLWIND             28334
#define SPELL_SUNDER_ARMOR          25051                   //cannot find sunder that reduces armor by 2950
#define SPELL_CLEAVE                20677
#define SPELL_MANA_BURN             17631

//Spectral Rider
#define SPELL_LIFEDRAIN             24300
//USES SAME UNHOLY AURA AS UNRELENTING RIDER

//Spectral Horse
#define SPELL_STOMP                 27993
