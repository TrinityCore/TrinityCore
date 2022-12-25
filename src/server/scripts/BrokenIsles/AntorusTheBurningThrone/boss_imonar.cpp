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

#include "antorus.h"
#include "GameObject.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_WARN_SLEEP_CANISTER = 1,
    SAY_SLEEP_CANISTER = 2,
    SAY_CHARGED_BLASTS = 3,
    SAY_EMPOWERED_SHRAPNEL_BLAST = 4,
    SAY_SWITCH_PHASE_1 = 5,
    SAY_SWITCH_PHASE_2 = 6,
    SAY_SWITCH_PHASE_3 = 7,
    SAY_SWITCH_PHASE_4 = 8,
    SAY_DEATH = 9,
};

enum Spells
{
    SPELL_OUTRO_CONV = 251475,
    SPELL_SPAWN_VISUAL = 249569,
    SPELL_INFERNAL_ROCKETS_1 = 248252,
    SPELL_INFERNAL_ROCKETS_2 = 248255,
    SPELL_BERSERK = 26662,
    SPELL_DAILY_ESSENCE_IMONAR = 305312,

    //Phase 1
    SPELL_SHOCK_LANCE = 247367,
    SPELL_SLEEP_CANISTER_FILTER = 254244,
    SPELL_SLEEP_CANISTER_MARK = 255029,
    SPELL_SLUMBER_GAS_STUN = 247565,
    SPELL_PULSE_GRENADE = 247376,
    SPELL_PULSE_GRENADE_FILTER_1 = 247373,
    SPELL_PULSE_GRENADE_FILTER_2 = 247375,
    SPELL_PULSE_GRENADE_SUMMON = 247381,
    SPELL_PULSE_GRENADE_AT = 247397,
    SPELL_SHOCKED = 250224,

    //Phase 2
    SPELL_SEVER = 247687,
    SPELL_SHRAPNEL_BLAST = 247923,
    SPELL_SHRAPNEL_BLAST_AT = 247939,
    SPELL_CHARGED_BLASTS = 248254,
    SPELL_CHARGED_BLASTS_AT = 247707, //>Ship casts
    SPELL_CHARGED_BLASTS_FILTER = 247711,
    SPELL_CHARGED_BLASTS_MARK = 247704, //Target Mark
    SPELL_CHARGED_BLASTS_DUMMY = 247727, //unk
    SPELL_CHARGED_BLASTS_DUMMY_MARK = 248968, //Hide untarget mark
    SPELL_CHARGED_BLASTS_SCALE = 257197, // Mod Size Player
    SPELL_CHARGED_BLASTS_DMG = 247716,
    SPELL_SHIP_SPAWN_VISUAL = 251446, //<

    //Phase 3
    SPELL_EMPOWERED_SHOCK_LANCE = 250255,
    SPELL_EMPOWERED_PULSE_GRENADE = 248068,
    SPELL_EMPOWERED_SHRAPNEL_BLAST = 248070,
    SPELL_SHIP_SHRAPNEL_BLAST = 248076, //>Ship casts
    SPELL_SHIP_SHRAPNEL_BLAST_MISSILE_1 = 248077,
    SPELL_SHIP_SHRAPNEL_BLAST_MISSILE_2 = 248080, //<

    //Change phase 1
    SPELL_P1_JETPACKS = 248995,
    SPELL_P1_PULSE_GRENADE_FILTER = 248223,
    SPELL_P1_PULSE_GRENADE_AT = 247668,
    SPELL_P1_PULSE_GRENADE_KNOCK = 250002,
    SPELL_P1_STASIS_TRAP_FILTER = 248224,
    SPELL_P1_STASIS_TRAP_AT = 247637,
    SPELL_P1_INFERNAL_LANDING = 255472,
    SPELL_P1_CONFLAGRATION = 248233,
    SPELL_P1_CONFLAGRATION_FILTER = 248313,
    SPELL_P1_P2_CONFLAGRATION_DUMMY = 248315,
    SPELL_P1_CONFLAGRATION_AT = 248208,

    //Change phase 2
    SPELL_P2_JETPACKS = 248194,
    SPELL_P2_BLASTWIRE_FILTER = 248237,
    SPELL_P2_BLASTWIRE_AT = 247955,
    SPELL_P2_SHRAPNEL_FILTER = 248238,
    SPELL_P2_SHRAPNEL_AT = 247944,
    SPELL_P2_CONFLAGRATION = 250135,
    SPELL_P2_CONFLAGRATION_FILTER = 250136,
    SPELL_P2_CONFLAGRATION_AT = 250138,
    SPELL_P2_INFERNAL_LANDING = 248250,
};

enum Events
{
    //Phase 1
    EVENT_SHOCK_LANCE = 1,
    EVENT_SLEEP_CANISTER = 2,
    EVENT_PULSE_GRENADE = 3,

    //Phase 2
    EVENT_SEVER = 4,
    EVENT_SHRAPNEL_BLAST = 5,
    EVENT_CHARGED_BLASTS = 6,

    //Phase 3
    EVENT_EMPOWERED_SHOCK_LANCE = 7,
    EVENT_EMPOWERED_PULSE_GRENADE = 8,
    EVENT_EMPOWERED_SHRAPNEL_BLAST = 9,
};

enum Misc
{
    PHASE_1 = 0,
    PHASE_2,
    PHASE_3,
    PHASE_4,
    PHASE_5,

    PATH_CHANGE_PHASE_FIRST = 12415800,
    PATH_CHANGE_PHASE_SECOND = 12415801,
};

Position const centrPlatformPos[2] =
{
    {-10574.5f, 8723.3f, 1871.56f},
    {-10575.8f, 8538.3f, 1871.53f}
};

Position const bFirePos[9] =
{
    {-10561.67f, 8664.34f, 1878.7f, 1.36f}, //Left
    {-10554.88f, 8641.35f, 1878.7f, 2.33f},
    {-10560.06f, 8630.49f, 1878.7f, 1.53f},
    {-10560.54f, 8600.84f, 1878.8f, 1.57f},
    {-10560.57f, 8595.66f, 1878.8f, 1.57f},
    {-10588.57f, 8595.09f, 1878.7f, 1.57f}, //Right
    {-10589.34f, 8652.25f, 1878.7f, 1.58f},
    {-10588.86f, 8624.69f, 1878.7f, 1.58f},
    {-10588.45f, 8664.40f, 1878.7f, 1.58f}
};

Position const bigShipPos[2] =
{
    {-10533.5f, 8757.92f, 1892.45f, 4.14f},
    {-10616.6f, 8708.64f, 1904.49f, 0.57f},
};

std::list<Position> smallShipPos =
{
    {-10627.9f, 8495.83f, 1878.13f, 0.64f},
    {-10625.3f, 8535.34f, 1878.15f, 0.01f},
    {-10621.7f, 8571.31f, 1878.13f, 5.63f},
    {-10538.6f, 8499.77f, 1878.13f, 2.35f},
    {-10531.3f, 8555.84f, 1878.13f, 3.56f}
};

void AddSC_boss_imonar()
{
   
}
