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

#include "GameObjectAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "heart_of_fear.h"

enum eShekzeerSays
{
    SAY_INTRO,          // Entering Shek'zeer's room
    SAY_AGGRO,          // Entering in combat
    SAY_SPELL_CRY,      // Casting Cry of terror
    SAY_SPELL_SERVANT,  // Turning a player into Servant of the Empress
    SAY_RETREAT,        // Empress returns in chrysalid
    SAY_ADVANCE,        // Empress goes out from chrysalid
    SAY_POWER,          // Empress near 30%
    SAY_WIPE,           // Raid has been wiped
    SAY_SLAY,           // Killing a player
    SAY_DEATH,          // Empress dies
    SAY_START,          // ??? - Said just before SAY_CONTROL (next enum)
};

enum eShaSays
{
    SAY_DEAD_QUEEN,     // Empress is dead
    SAY_LEAVING,        // Leaving boss' room after Empress is defeated
    SAY_LAST_PHASE,     // Entering in phase 3
    SAY_PREPARE_ADVANCE,// Preparing return in phase 1
    SAY_CONTROL,        // ???
};

enum eShekzeedAdds
{
    NPC_SETTHIK_WINDBLADE = 63589,
    NPC_KORTHIK_REAVER = 63591,
    NPC_DISSONANCE_FIELD = 62847,
    NPC_SHA_OF_FEAR_MOB = 63942,
    NPC_STICKY_RESIN = 63730,
    NPC_AMBER_TRAP = 64351,
    NPC_HEART_OF_FEAR = 63445
};

enum eShekzeerSpells
{
    // --- Shek'zeer ---
    // Phase 1
    SPELL_RETREAT = 125098,
    SPELL_ADVANCE = 125304,
    SPELL_END_ADVANCE = 125306,
    SPELL_SUMMON_DISSONANCE = 124856,
    SPELL_CORRUPT_FIELD = 126125, // Heroic mode only
    SPELL_SHA_AURA_DISSONANCE = 125296,
    SPELL_SHA_DISSONANCE = 123819,
    SPELL_CRY_OF_TERROR = 123788,
    SPELL_EYES_OF_THE_EMPRESS = 123707,
    SPELL_SERVANT_OF_THE_EMPRESS = 123723,
    SPELL_DREAD_SCREECH = 123735,
    // Phase 2
    SPELL_SHA_ENERGY = 125464,
    SPELL_CONSUMING_TERROR = 124849,
    SPELL_VISIONS_OF_DEMISE = 124862,
    SPELL_CALAMITY = 124845,
    SPELL_AMASSING_DARKNESS = 124842,
    SPELL_AMASSING_DMG = 124844,
    SPELL_HOF_CHANNELING = 123845,
    SPELL_HOF_SUMMON = 123846, // Heroic mode only

    // --- Set'thik Windblade ---
    SPELL_FIXATE = 125390,
    SPELL_ADD_DISPATCH = 124077,
    SPELL_ADD_SONIC_BLADE = 125886,
    SPELL_STICKY_RESIN = 124092,   // Missile which trigger 124095 which summons NPC_STICKY_RESIN (63730)

    // --- Sticky Resin ---
    SPELL_STICKY_RESIN_VISUAL = 124310,   // Visual of little sticky resin
    SPELL_STICKY_DAMAGES = 124097,
    SPELL_MERGED_RESIN = 125719,   // Visual when 2 little sticky resins merge into 1 big
    SPELL_AMBER_TRAP = 125826,   // Amber trap visual
    SPELL_TRAPPED = 125823,   // Traps the mob into amber trap and freezes the victim
    SPELL_RESIN_SPURT = 124748,   // Little resin spurt when 2 sticky resins merge

    // --- Amber Trap ---
    SPELL_TRAP_DAMAGES = 125822,
    SPELL_FREEZE_ANIM = 16245,

    // --- Kor'thik Reaver
    SPELL_POISON_BOMB = 124777,
    SPELL_TOXIC_SLIME = 124807,
    SPELL_POISON_DRENCHED_ARMOR = 124821,

    // --- Dissonance Field ---
    SPELL_DISSONANCE_FIELDS = 123184,
    SPELL_DISSONANCE_SPELLS = 123627,
    SPELL_CORRUPTED_DISSONANCE = 126122,
    SPELL_DISSONANCE_FIELD_AURA = 123255,
    SPELL_SONIC_DISCHARGE = 123504,
    SPELL_RESONANCE = 123618,

    // --- Sha of fear ---
    SPELL_SHA_OF_FEAR = 124905,
    SPELL_ULTIMATE_CORRUPTION = 125451,

    // --- Heart of Fear - Heroic mode ---
    SPELL_HOF_VISUAL = 123840,
    SPELL_HOF_DMG = 125638,
    SPELL_HOF_RAY = 130680,

    SPELL_SHEKZEER_BONUS = 132199
};

enum eShekzeerEvents
{
    // Shek'zeer
    EVENT_CHANGE_PHASE = 1, // Switching to phase 1 when in phase 2 after 150 secs
    EVENT_DISSONANCE_FIELDS,
    EVENT_CORRUPT_FIELD,    // Heroic mode only
    EVENT_CRY_OF_TERROR,
    EVENT_EYES_OF_THE_EMPRESS,
    EVENT_DREAD_SCREECH,
    EVENT_SHA_ENERGY,
    EVENT_CONSUMING_TERROR,
    EVENT_VISIONS_OF_DEMISE,
    EVENT_CALAMITY,
    EVENT_AMASSING_DARKNESS,
    EVENT_LOAD_PHASE,
    EVENT_CLOSE_CHAMBER,
    EVENT_SUMMON_HOF,       // Heroic mode only
    EVENT_BERSERK,          // 9 min in normal mode, 15 in heroic
    EVENT_POWER,

    // Set'thik Windblade
    EVENT_ADD_DISPATCH,
    EVENT_ADD_SONIC_BLADE,
    EVENT_STICKY_RESIN,

    // Sticky Resin
    EVENT_REARM_TRAP,
    EVENT_CHECK_INTERRACT,

    // Kor'thik Reaver
    EVENT_POISON_BOMB,
    EVENT_TOXIC_SLIME,
    EVENT_POISON_DRENCHED_ARMOR,

    // Dissonance Field
    EVENT_CHECK_CAST,

    // Sha of Fear
    EVENT_LEAVING,

    // Heart of fear
    EVENT_HOF_ATTACK,
    EVENT_HOF_DESTROY
};

enum eShekzeerActions
{
    ACTION_LOAD_PHASE,
    ACTION_RETREAT,
    ACTION_COMBAT,
    ACTION_ALL_ADD_DIED,
    ACTION_RESIN_GROW,
    ACTION_TRAP_END,
    ACTION_FREE_ALLY,
    ACTION_FIGHTBACK,
    ACTION_LAST_PHASE,
    ACTION_WITHDRAW,
    ACTION_LEAVING
};

enum eShekzeerTypes
{
    TYPE_RETREAT,
    TYPE_END_FIGHT
};

#define TIME_PHASE_DELAY 150000

Position chamberPos = { -2478.769f, 1068.421f, 573.1021f, 1.570796f };
Position attackPos = { -2478.769f, 1008.200f, 572.8200f, 4.712389f };
Position leavingPos = { -2478.520f, 1013.510f, 569.6300f, 4.712389f };
Position highPos = { -2478.520f, 1013.510f, 770.0000f, 4.712389f };

Position addSpawnLeft[4] =
{
    {-2360.0f, 1014.0f, 575.90f, 3.141593f},
    {-2352.0f, 1014.0f, 575.90f, 3.141593f},
    {-2352.0f, 1006.0f, 575.90f, 3.141593f},
    {-2352.0f, 1022.0f, 575.90f, 3.141593f}
};

Position addSpawnRight[4] =
{
    {-2600.0f, 1014.0f, 575.90f, 0.0f},
    {-2608.0f, 1014.0f, 575.90f, 0.0f},
    {-2608.0f, 1006.0f, 575.90f, 0.0f},
    {-2608.0f, 1022.0f, 575.90f, 0.0f}
};

void AddSC_boss_shekzeer()
{
    
}
