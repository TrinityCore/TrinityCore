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
SDName: Boss_Stalagg
SD%Complete: 0
SDComment: Merge with Thaddius
SDCategory: Naxxramas
EndScriptData */

#include "precompiled.h"

//Stalagg
//8864 aggro - Stalagg crush you!
//8866 slay - Stalagg Kill!
//8865 death - Master save me...

#define SPELL_WARSTOMP          28125
#define SPELL_POWERSURGE        28134
#define SPELL_CHAIN_LIGHTNING   28900

//Not sure how to "force" crushing blows or to knock tank to the opposite platform
