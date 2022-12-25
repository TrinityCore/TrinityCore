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

#include "trial_of_valor.h"
#include "AreaTriggerAI.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

namespace
{
    enum Says
    {
        //Hymdall && Hyrja
        SAY_RAID_CAST = 5,
        SAY_CAST_SPELL,
        SAY_ANN_AGGRO_MYTHIC,
        SAY_DIE_TANK,
        SAY_AGGRO_MYTHIC,

        // ODYN
        SAY_AGGRO = 15,
        SAY_DEFEATED,
        SAY_EVADE_ODYN,
        SAY_STORM_FERGED_SPEAR_RAID,
        SAY_STORM_FERGED_SPEAR,
        SAY_START_3_PHASE = 5,
        SAY_RAID_FELMAGNARON_RUNE = 7,
        SAY_FELMAGNARON_RUNE,
        SAY_DEATH_TANK,
        SAY_STORM_OF_JUSTICE = 14,
        SAY_UNNERING_BLAST = 12
    };

    enum Spells
    {
        // SPELLS FOR ODYN
        SpellIntroConverstaion = 227863,
        SpellLeapIntoBattle = 227882,
        SpellTestForPlayersMythic = 229169,
        SpellTestOfTheChosen = 232301,
        SpellRunicBrandCleanUp = 228242,
        SpellSkyJump = 231166,
        SpellValarjarsBondDummy = 229530,
        SpellValarjarsBondHeroic = 229529,
        SpellValarjarsBondProc = 229469,
        // SPELLS FOR EVENT "Runic" (1 && 2 PHASE)
        SpellDrawPower = 227503,
        SpellDrawPowerDummy = 227888,
        SpellUnneringBlast = 227629,
        SpellUnneringBlastWipe = 231277,
        SpellUnneringBlastDmg = 230989,
        SpellProtected = 229584, // MYTHIC MODE
        SpellDrawPowerMythicCleanUp = 233002, // MYTHIC MODE
        // Spells for Player Runic Event. (MYTHIC MODE)
        SpellBrandedPlayerBlue = 231345,//Phase 3
        SpellBrandedPlayerGreen = 231346,
        SpellBrandedPlayerOrange = 231342,
        SpellBrandedPlayerPurple = 231311,
        SpellBrandedPlayerYellow = 231344,
        SpellBrandedOdynBlue = 229582,//Phase 1,2
        SpellBrandedOdynGreen = 229583,
        SpellBrandedOdynOrange = 229580,
        SpellBrandedOdynPurple = 229579,
        SpellBrandedOdynYellow = 229581,
        // Spells for Valarjar Runebearer. (trash)
        SpellBrandedValarjarOrange = 227491,
        SpellBrandedValarjarPurple = 227490,
        SpellBrandedValarjarYellow = 227498,
        SpellBrandedValarjarBlue = 227499,
        SpellBrandedValarjarGreen = 227500,
        SpellBrandedValarjarDummy = 227602,
        SpellRunicShieldOrange = 227597,
        SpellRunicShieldPurple = 227598,
        SpellRunicShieldYellow = 227596,
        SpellRunicShieldBlue = 227595,
        SpellRunicShieldGreen = 227594,
        // Spells for Create AT Runic Event.
        SpellBrandedOdynBlueAT = 227487,
        SpellBrandedOdynGreenAT = 227488,
        SpellBrandedOdynOrangeAT = 227484,
        SpellBrandedOdynPurpleAT = 227483,
        SpellBrandedOdynYellowAT = 227485,
        // Spells for Odyn Runic Event
        SpellDrawPowerOnOdynPurple = 227961,
        SpellDrawPowerOnOdynOrange = 227973,
        SpellDrawPowerOnOdynYellow = 227974,
        SpellDrawPowerOnOdynBlue = 227975,
        SpellDrawPowerOnOdynGreen = 227976,
        // ODYN PHASE 2
        SpellSpearTransitionHoly = 228734,
        SpellOdynsTestProc = 227626,
        SpellOdynsTest = 228911,
        SpellSpearOfLight = 228870,
        SpellSpearOfLight2 = 233270,
        SpellSpearOfLight3 = 227712,
        SpellSpearOfLight2Missile = 227697,
        SpellGlowingFragment = 227782,
        SpellShatteredSpearsDummy = 231013, // ?
        SpellShatteredSpears = 231019, // ?
        // ODYN PHASE 3
        SpellSpearTransitionThunder = 228740,
        SpellArcingStorm = 229255,
        SpellArcingStormBuff = 229256,
        SpellArcingStormProc = 229254,
        SpellCleancingFlame = 228683,
        SpellCleansingFlame = 227475,
        SpellStormForgedSpear = 228914,
        SpellStormForgedSpearPlayer = 228932,
        SpellStormOfJustice = 227807,
        SpellStormOfJustice2 = 227959, // UNK ?
        SpellRagingTempest = 227804,
        SpellRunicBrandMythic = 231384,
        SpellRadiantSmiteDummy = 231350, // MYTHIC MODE
        SpellCleansingFlameAT_1 = 227448,
        SpellCleansingFlameAT_2 = 227455,
        SpellCleansingFlameAT_3 = 227456,
        // ------[SPELLS FOR ODYN END]-------

        // SPELLS FOR HYMDALL
        SpellDancingBlade = 228003,
        SpellDancingBlade2 = 228007,
        SpellDancingBlade3 = 228006,
        SpellHornOfValour = 228012,
        SpellHornOfValourPlayer = 228871,

        // SPELLS FOR HYRJA
        SpellExpelLight = 228028,
        SpellExpelLight2 = 228029,
        SpellExpelLight3 = 228030,
        SpellShieldOfLight = 228162,
        SpellShieldOfLight2 = 228270,
        SpellShieldOfLight3 = 228272,
        SpellHyrjaConversation = 232132,
        SpellHoverModeAnimState = 90766,

        // SPELLS FOR HYMDALL && HYRJA
        SpellRevivify = 228171,
        SpellValarjarsBond = 228016,
        SpellValarjarsBond2 = 228018,
        SpellHeal = 163492,
        SpellClearAllDebuffs = 34098,

        // SPELLS FOR VALARJAR RUNEBEARER
        SpellRunebearerSpawn = 230415
    };

    enum Phase
    {
        PHASE_1 = 1,
        PHASE_2,
        PHASE_3
    };

    enum Events
    {
        EVENT_INTRO = 1,
        EVENT_START_ODYN = 2,
        EVENT_START_SECOND_PHASE = 3,
        EVENT_START_THIRD_PHASE = 4,
        EVENT_SPEAR_OF_LIGHT = 5,
        EVENT_FELMAGNARON_RUNE = 6,
        EVENT_ODYNS_TEST = 7,
        EVENT_STORM_OF_JUSTICE = 8,
        EVENT_STORM_FORGED_SPEAR = 9,
        EVENT_CLEANSING_FLAME_AT_1 = 10,
        EVENT_CLEANSING_FLAME_AT_2 = 11,
        EVENT_CLEANSING_FLAME_AT_3 = 12,
        EVENT_PHASE_TWO_HYMDALL = 13,
        EVENT_PHASE_TWO_HYRJA = 14,
        EVENT_ARCING_STORM_BUFF = 15,

        // Hymdall
        EVENT_HORN_OF_VALOUR = 16,
        EVENT_DANCING_BLADE = 17,

        //Hyrja
        EVENT_EXPEL_LIGHT = 18,
        EVENT_SHIELD_OF_LIGHT = 19,
        EVENT_SHIELD_OF_LIGHT_REACT = 20
    };
}

enum Miscs
{
    ACTION_1 = 1,
    ACTION_2,
    ACTION_3,
    ACTION_4,

    EVENT_1,
};

void AddSC_boss_odyn_tov()
{
    
}
