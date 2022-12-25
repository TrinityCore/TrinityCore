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
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "MapManager.h"
#include "Spell.h"
#include "Vehicle.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CreatureTextMgr.h"
#include "MoveSplineInit.h"
#include "Weather.h"

#include "heart_of_fear.h"

enum eTayakSpells
{
    SPELL_VISINTRO_TAYAK = 128788,
    SPELL_TEMP_SLASH_AURA = 122854,   // Visual + Periodic trigger aura for SPELL_TEMP_SLASH_DAMAGE.
    SPELL_TEMP_SLASH_DAMAGE = 122853,   // Aura Damage + Knock back
    SPELL_WIND_STEP_B_DMG = 123180,   // Bleed damage for 8y targets.
    SPELL_WIND_STEP_DUMMY = 123459,   // Aura Dummy.
    SPELL_WIND_STEP_TP_BACK = 123460,   // Teleport back to the main target.
    SPELL_INTENSIFY_NORMAL = 123470,   // Add spell 123471 every 1 minute, phase 1
    SPELL_INTENSIFY_TORNADO = 132254,   // Add spell 123471 every 10 secs, phase 2
    SPELL_BLADE_TEMPEST_AUR = 125310,   // Triggers SPELL_BLADE_TEMPEST_DMG each 0.5s, SPELL_BLADE_TEMPEST_AT.
    SPELL_BLADE_TEMPES_J_FC = 125325,   // Force Cast SPELL_BLADE_TEMPES_JUMP in 200 yards.
    SPELL_STORM_UNLEASHED_D = 123814,   // Boss Dummy Visual.
    SPELL_SU_AURA = 123598,   // Aura for the tornadoes, triggers SPELL_SU_RV_SE each 0.1 secs.
    SPELL_SU_RV = 123599,   // Control Vehicle aura.
    SPELL_SU_DUMMY_VIS = 124024,   // Some dummy visual (for tornadoes?).
    SPELL_SU_DMG_AURA = 124785,   // Triggers SPELL_SU_DMG every 1 sec.
    SPELL_SU_WIND_GALE = 123633,
    SPELL_SU_DUMMY_CRAP = 123616,   // Applies a dummy aura on a target.
    SPELL_TAYAK_BERSERK = 26662,    // Enrage, 490 seconds, or 8:10 minutes.

    SPELL_LORD_TAYAK_BONUS = 132195
};

enum Yells
{
    // Blade Lord Ta'yak
    SAY_AGGRO = 0,    // On your guard, invaders. I, Ta'yak, Lord of Blades, will be your opponent.
    SAY_DEATH = 1,    // I'd always hoped to cut someone like that someday, to hear that sound. But to have it happen to my own prothorax is ridiculous.
    SAY_KILL_TRASH = 2,    // 0 - Mere initiates. ; 1 - They should have studied harder. ; 2 - One technique alone is not enough. ; 3 - They failed their test. Will you?
    SAY_INTRO = 3,    // They approach? Good. Now, if only my students were here to see and learn from the coming display of martial prowess...
    SAY_SLAY = 4,    // 0 - A perfect cut. ; 1 - This is the technique of a Blade Lord.
    SAY_STORM_UNLEASHED = 5,    // Can you follow my blade?
    ANN_UNSEEN = 6,    // Blade Lord Ta'yak marks $N for [Unseen Strike]!
    SAY_ENTER_ROOM = 7,    // Now go, impart my techniques to the initiates.
};

enum Events
{
    // Blade Lord Ta'yak
    EVENT_TEMPEST_SLASH = 1,    // 10 seconds from pull. Every 15.5 seconds.
    EVENT_UNSEEN_STRIKE,            // 30.5 seconds from pull. Every 53 - 61 seconds.
    EVENT_UNSEEN_STRIKE_RETURN,
    EVENT_TAYAK_WIND_STEP,          // 20.5 seconds from pull. Every 25 seconds.
    EVENT_WIND_STEP_RETURN,
    EVENT_OVERWHELMING_ASS,         // 15.5 seconds from pull. Every 20.5 seconds, delayable by up to 15 seconds.

    EVENT_BLADE_TEMPEST,            // Every 60 seconds. Heroic only.
    EVENT_TAYAK_BT_END,

    EVENT_STORM_UNLEASHED,          // 20%
    EVENT_SUMMON_TORNADOES,

    EVENT_TAYAK_BERSERK,            // Enrage at 8 minutes, or, more precisely, 490 seconds.
    EVENT_STORM_MOVE,
    EVENT_STORM_REMOVE
};

enum TayakPhases
{
    PHASE_NORMAL = 1,
    PHASE_STORM_UNLEASHED = 2
};

enum eTayakAdds
{
    NPC_US_TORNADO = 63278,
    NPC_GALE_WINDS_STALKER = 63292,
    NPC_SETTHIK_TEMPEST = 64358
};

enum eTayakActions
{
    ACTION_WIND = 1,
    ACTION_STOP_WIND = 2,
    ACTION_TAYAK_BT_PULL = 7
};

enum eTayakPhases
{
    PHASE_TAYAK1 = 2,
    PHASE_TAYAK2 = 3
};

enum eTayakTypes
{
    TYPE_STORM_POINT = 3,
    TYPE_PHASE_TAYAK = 4,
    TYPE_STORM_PHASE = 5
};

Position TayakStormPoints[2] =
{
    { -2119.072f, 184.985f, 422.162f, 1.585f }, // 20 - 10% TP point
    { -2119.072f, 379.372f, 422.162f, 4.703f }  // 10 -  0% TP point
};

Position PlayerTelePos = { -2124.063f, 281.056f, 420.901f, 0.053f }; // Tele point for players on P2 start.

// StormPoint1 Tornado summon points.
Position const Tornado1[3] =
{
    { -2123.702f, 198.023f, 420.910f, 1.561f }, // Left
    { -2119.503f, 198.023f, 420.910f, 1.561f }, // Center
    { -2114.113f, 198.023f, 420.910f, 1.561f }, // Right
};

// StormPoint2 Tornado summon points.
Position const Tornado2[3] =
{
    { -2114.113f, 363.058f, 420.910f, 4.710f }, // Left
    { -2119.503f, 363.058f, 420.910f, 4.710f }, // Center
    { -2123.702f, 363.058f, 420.910f, 4.710f }, // Right
};

void AddSC_boss_tayak()
{
    
}
