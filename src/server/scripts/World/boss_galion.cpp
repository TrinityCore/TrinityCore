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

#include "Creature.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "SpellScript.h"
#include "ScriptMgr.h"
#include "TemporarySummon.h"
#include "Vehicle.h"

enum eBosses
{
    BOSS_GALION
};

enum eSpells
{
    SPELL_FIRE_SHOT = 121673,
    SPELL_STOMP = 121787,

    SPELL_CANON_1 = 121577,
    SPELL_CANON_2 = 121605,
    SPELL_CANON_3 = 121607,
    SPELL_CANON_4 = 121608,
    SPELL_CANON_5 = 121609,
    SPELL_CANON_6 = 121610,
    SPELL_CANON_7 = 121611,
    SPELL_CANON_8 = 121613,
    SPELL_CANON_DMG = 121600,

    SPELL_IMPALING_PULL = 121747,
    SPELL_GRIP_TARGET = 75686,

    SPELL_GALLEON_BONUS = 132206
};

uint32 const CanonSpells[8] = { SPELL_CANON_1, SPELL_CANON_2, SPELL_CANON_3, SPELL_CANON_4, SPELL_CANON_5, SPELL_CANON_6, SPELL_CANON_7, SPELL_CANON_8 };

enum eEvents
{
    EVENT_FIRE_SHOT = 1,
    EVENT_WARN_STOMP,
    EVENT_STOMP,
    EVENT_CANON_BARRAGE,
    EVENT_WARMONGER,
    EVENT_IMPALING_PULL
};

enum eCreatures
{
    NPC_GALLEON = 62351,
    NPC_GALLEON_CANON = 62355,
    NPC_SALYIN_WARMONGER = 62351,
    NPC_CHIEF_SALYIS = 62352     // Seat ID: 2
};

enum eSays
{
    TALK_SPAWN,     // Chief Salyis yells: Loot and pillage, bwahahaha!
    TALK_AGGRO,     // Chief Salyis yells: Bring me their corpses!
    TALK_CANON,     // Chief Salyis yells: Arm the cannons! Ready! Aim! FIRE!
    TALK_SLAY,      // Chief Salyis yells: They are soft, weak!
    TALK_DEATH      // Chief Salyis yells: Retreat to the hills!
};

enum eActions
{
    ACTION_TALK_INTRO
};

void AddSC_boss_galion()
{
    
}
