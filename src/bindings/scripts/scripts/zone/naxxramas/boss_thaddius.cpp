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
SDName: Boss_Thaddius
SD%Complete: 0
SDComment: Merge Feugen & Stalagg with this script
SDCategory: Naxxramas
EndScriptData */

#include "precompiled.h"

//Thaddus
//8873 Lamnt01 - Pleeease!
//8874 Lamnt02 - Stop, make it stop!
//8875 Lamnt03 - Help me! Save me!
//8876 Lamnt04 - Please, nooo!
//8872 greet - You are too late... I... must... OBEY!
//8867 aggro1 - KILL!
//8868 aggro2 - EAT YOUR BONES!
//8869 aggro3 - BREAK YOU!
//8871 elect - Now YOU feel pain!
//8877 slay - You die now!
//8870 die - Thank... you...

#define SPELL_BALL_LIGHTNING                28299

#define SPELL_CHARGE_POSITIVE_DMGBUFF       29659
#define SPELL_CHARGE_POSITIVE_NEARDMG       28059

#define SPELL_CHARGE_NEGATIVE_DMGBUFF       29660
#define SPELL_CHARGE_NEGATIVE_NEARDMG       28084

#define SPELL_CHAIN_LIGHTNING               28900

#define SPELL_BESERK                        26662
