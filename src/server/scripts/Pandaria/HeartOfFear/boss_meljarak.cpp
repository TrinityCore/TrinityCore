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
#include "GameObjectAI.h"

#include "heart_of_fear.h"

enum Yells
{
    /*** Boss ***/
    SAY_INTRO = 0, // Your defiance of the empress ends here!

    SAY_AGGRO = 1, // All of Pandaria will fall beneath the Wings of the Empress!
    SAY_SLAY = 2, // 0 - The Empress commands it!; 1 - Pitiful.
    SAY_DEATH = 3, // Empress... I have... failed you...

    SAY_WHIRLING_BLADES = 4, // My blade never misses its mark!
    SAY_RAIN_OF_BLADES = 5, // The skies belong to the Empress!

    SAY_WATCHFUL_EYE = 6, // 0 - You fight like cowards!; 1 - Aid me brethren!

    SAY_ADD_GROUP_DIES = 7, // 0 - To die for the empress is an honor!; 1 - The wings of the empress cannot fail!; 2 - You will pay for your transgressions!
    SAY_SUMMON_REINFORCE = 8,  // 0 - The Kor'thik have no equal in combat!; 1 - The mighty Zar'thik bend the wind to their will!; 2 - The Sra'thik command the elements of this land, leaving their foes imprisoned for all time!

    ANN_WHIRLING_BLADES = 9, // Wind Lord Mel'jarak begins to cast [Whirling Blades]!
    ANN_RAIN_OF_BLADES = 10,// Wind Lord Mel'jarak begins to cast [Rain of Blades]!
    ANN_REINFORCEMENTS = 11 // Wind Lord Mel'jarak calls for reinforcements!
};

enum Spells
{
    /*** Boss ***/
    SPELL_WHIRLING_BLADE = 121896, // Triggers 121898 damage every 0.25s and 121897, 122083 dummy location spells (visuals?).
    SPELL_WB_SWORD = 121897, // Visual thrown sword
    SPELL_WB_LIGHT = 122083, // Light effect around thrown sword
    SPELL_WB_SUMMON = 124851, // Summons Whirling Blade NPC at target pos, which will trigger spell back to Mel'jarak
    SPELL_RAIN_OF_BLADES = 122406, // Triggers 122407 damage spell every 0.5s.
    SPELL_WIND_BOMB = 131813, // Triggers 131814 bomb summon npc 67053.

    SPELL_WATCHFUL_EYE_1 = 125933, // Starting Normal and always Heroic aura - 9 adds alive, can control 4 / 3 on Heroic.
    SPELL_WATCHFUL_EYE_2 = 125935, // 6 adds alive, can control 2.
    SPELL_WATCHFUL_EYE_3 = 125936, // 3 adds alive, can control 0.
    SPELL_COWARDS = 122399, // Remove crowd control from Mel'jarak's allies.

    SPELL_RECKLESNESS_N = 122354, // Normal stackable version.
    SPELL_RECKLESNESS_H = 125873, // Heroic 30 sec version.

    SPELL_BERSERK_MELJARAK = 120207, // 480 seconds or 8 mins Enrage.

    /*** Misc / Impaling Spear ***/
    SPELL_IMPALING_SPEAR = 122220, // Aura player receives when clicking on the racks. Gives Action Bar with button 1 to throw spear.
    SPELL_BROWN_MANTID_WINGS = 140633,
    SPELL_RED_MANTID_WINGS = 138392,
    SPELL_BLUE_MANTID_WINGS = 138393,

    /*** Adds ***/
    // Wind Bomb
    SPELL_WIND_BOMB_THR_DMG = 131830, // Damage in 5 yards at throwing.
    SPELL_WIND_BOMB_ARM = 131835, // Visual bomb arm.
    SPELL_WIND_BOMB_EXPLODE = 131842, // If a player goes in 6 yards (on off checked with 131836).

    // The Swarm
    SPELL_FATE_OF_THE_KORT = 121774, // Share Damage spell for Kor'thik Elite Blademasters.
    SPELL_FATE_OF_THE_SRAT = 121802, // Share Damage spell for Sra'thik Amber-Trappers.
    SPELL_FATE_OF_THE_ZART = 121807, // Share Damage spell for Zar'thik Battle-Menders.

    // - Kor'thik Elite Blademaster
    SPELL_KORTHIK_STRIKE = 123962, // All 3 use this at once on the same player.

    // - Sra'thik Amber-Trapper
    SPELL_AMBER_PRISON = 121876, // Initial cast, triggers 121881 after 3 seconds.
    SPELL_AMBER_PRISON_TRIG = 121881, // Triggers 121874 cast.
    SPELL_AMBER_PRISON_FC = 121874, // Triggers 121885 aura.
    SPELL_AMBER_PRISON_AURA = 121885, // Stun, root, visual etc. !ADD THIS: /* insert into spell_linked_spell values (121885, 129078, 1, 'Summon Amber Prison when hit by aura'); */
    SPELL_AMBER_PRISON_SUMM = 129078, // Summons 62531 Amber Prison npc.

    SPELL_RESIDUE = 122055, // Residue afflicts players who destroy Amber Prisons.

    SPELL_CORROSIVE_RESIN = 122064,

    // !-  Moving while afflicted by Corrosive Resin removes a stack of Corrosive Resin and creates a Corrosive Resin Pool at the player's location. -!
    SPELL_CORR_RESIN_POOL_S = 122123, // Summons Corrosive Resin Pool npc 67046.
    SPELL_CORR_RESIN_POOL_A = 129005, // Aura for Corrosive Resin Pool, triggers 122125 dmg each sec.

    // - Zar'thik Battle-Mender
    SPELL_MENDING = 122193, // Triggers a 200 yard dummy + heal spell 122147.
    SPELL_QUICKENING = 122149, // All Swarm gets boost 25% dmg + as.

    SPELL_MELJARAK_BONUS = 132197
};

enum Events
{
    /*** Boss ***/
    EVENT_WHIRLING_BLADE = 1, // 36 secs after pull
    EVENT_WHIRLING_BLADE_REM,
    EVENT_RAIN_OF_BLADES,         // 60 secs after pull
    EVENT_WIND_BOMB,

    // Respawn in HM
    EVENT_SUMMON_KORTHIK,
    EVENT_SUMMON_SRATHIK,
    EVENT_SUMMON_ZARTHIK,

    EVENT_BERSERK_MELJARAK,

    /*** Adds ***/
    // Wind Bomb
    EVENT_ARM,                    // 3 secs after spawn

    // - Kor'thik Elite Blademaster
    EVENT_KORTHIK_STRIKE,         // 19s after pull.

    // - Sra'thik Amber-Trapper
    EVENT_AMBER_PRISON,
    EVENT_CORROSIVE_RESIN,

    // - Zar'thik Battle-Mender
    EVENT_MENDING,
    EVENT_QUICKENING,

    // - Whirling Blade
    EVENT_WB_BACK
};

enum Adds
{
    NPC_KORTHIK_ELITE_BLADEMASTER = 62402,
    NPC_SRATHIK_AMBER_TRAPPER = 62405,
    NPC_ZARTHIK_BATTLE_MENDER = 62408,
    NPC_WIND_BOMB = 67053,
    NPC_AMBER_PRISON = 62531,
    NPC_WHIRLING_BLADE = 63930,
    NPC_CORROSIVE_RESIN_POOL = 67046
};

enum Types
{
    TYPE_WHIRLING_BLADE = 1,
    TYPE_WB_DEAL_DMG,
    TYPE_IS_IN_COMBAT,
    TYPE_NO_RESPAWN
};

enum eMeljarakActions
{
    ACTION_KORTHIK_DIED = 1,
    ACTION_SRATHIK_DIED,
    ACTION_ZARTHIK_DIED,
    ACTION_ADDGROUP_DIED,
    ACTION_CHECK_CONTROLLED_ADDS
};

#define DISPLAYID_WINDBOMB 45684

// Starting Positions for Kor'thik Elite Blademaster (62402)
Position PosKorthikEliteMaster[3] =
{
    {-2084.55f, 483.10f, 503.57f, 3.141593f},
    {-2089.31f, 475.97f, 503.57f, 3.141593f},
    {-2084.55f, 467.61f, 503.57f, 3.141593f}
};

Position PosSrathikAmberTrapper[3] =
{
    {-2077.00f, 490.33f, 503.57f, 3.141593f},
    {-2083.78f, 495.89f, 503.57f, 3.141593f},
    {-2079.33f, 502.90f, 503.57f, 3.141593f}
};

Position PosZarthikBattleMender[3] =
{
    {-2077.00f, 461.88f, 503.57f, 3.141593f},
    {-2083.78f, 456.09f, 503.57f, 3.141593f},
    {-2079.33f, 449.28f, 503.57f, 3.141593f}
};

void AddSC_boss_meljarak()
{
   
}
