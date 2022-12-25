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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "SpellScript.h"

#define BOSS_NALAK 0

enum eSpells
{
    SPELL_STATIC_SHIELD = 136341,
    SPELL_ARC_NOVA = 136338,
    SPELL_LIGHTNING_TETHER = 136339,
    SPELL_LIGHTNING_TETHER_10K = 136353,
    SPELL_LIGHTNING_TETHER_20K = 136349,
    SPELL_STORM_CLOUD = 136340
};

enum eEvents
{
    EVENT_ARC_NOVA = 1,
    EVENT_LIGHTNING_TETHER,
    EVENT_STORM_CLOUD
};

enum eSays
{
    TALK_INTRO,         // I am born of thunder!
    TALK_AGGRO,         // Can you feel a chill wind blow? The storm is coming...
    TALK_ARC_NOVA,      // The clouds arc with vengeance!
    TALK_STORMCLOUD,    // The air crackles with anger!
    TALK_SLAY,          // The sky weeps for your demise!
    TALK_DEATH          // I am but...the darkness...before the storm...
};

void AddSC_boss_nalak()
{
    
}
