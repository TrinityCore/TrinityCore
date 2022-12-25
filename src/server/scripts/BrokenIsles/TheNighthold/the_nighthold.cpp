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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "SpellInfo.h"
#include "Vehicle.h"
#include "CombatAI.h"
#include "thenighthold.h"
#include "InstanceScript.h"
#include "Unit.h"
#include "ObjectAccessor.h"
#include "MotionMaster.h"
#include "CreatureAIImpl.h"
#include "CreatureAI.h"

void AddDelayedEvent(uint64 /*timeOffset*/, std::function<void()>&& /*function*/)
{ 
}

void KillAllDelayedEvents()
{
}

void AddDelayedCombat(uint64 /*timeOffset*/, std::function<void()>&& /*function*/)
{
}

void KillAllDelayedCombats()
{
}

enum Spells
{
    // Torm the Brute
    SPELL_CRASH_DOOR_VISUAL_FIRST       = 230873,
    SPELL_CRASH_DOOR_VISUAL_SECOND      = 230880,
    SPELL_DEVASTATING_STRIKE            = 230438,
    SPELL_BOULDER_STRIKE                = 231086,
    SPELL_RUMBLING_BLOW                 = 230482,
    // Pulsauron
    SPELL_SHIELD                        = 205647,
    SPELL_BEAM                          = 221153,
    // Fulminant
    SPELL_SCATTER                       = 221172,
    SPELL_SCATTER_DAMAGE                = 221173,
    SPELL_SCATTER_VISUAL                = 221191,
    SPELL_SCATTER_ENERGIZE              = 221175,
    SPELL_FULMINATE                     = 221164,
    // Chaotoid
    SPELL_RELEASE_THE_VOID              = 221158,
    SPELL_COMPRESS_THE_VOID_GRIP        = 221160,
    SPELL_COMPRESS_THE_VOID_JUMP        = 221162,
};

enum Events
{
    // Torm the Brute
    EVENT_TORM_CRASH_DOOR               = 1,
    EVENT_DEVASTATING_STRIKE            = 2,
    EVENT_BOULDER_STRIKE                = 3,
    EVENT_RUMBLING_BLOW                 = 4,
    // Pulsauron
    EVENT_PULSAURON_BEAM                = 5,
    // Fulminant
    EVENT_SCATTER                       = 6,
    EVENT_FULMINATE                     = 7,
    // Chaotoid
    EVENT_RELEASE_THE_VOID              = 8,
    EVENT_COMPRESS_THE_VOID_GRIP        = 9
};

enum Misc
{
    DATA_TORM_THE_BRUTE = 1,
};

void AddSC_the_nighthold()
{
    
}
