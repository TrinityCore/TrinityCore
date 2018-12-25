/*
 * Copyright (C) 2008-2018 TrinityCore <http://www.trinitycore.org/>
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

#ifndef DEF_SHADOWFANG_H
#define DEF_SHADOWFANG_H

#include "SpellScript.h"

#define DataHeader "SK"
#define SKScriptName "instance_shadowfang_keep"

uint32 const EncounterCount = 7;

enum SKSpells
{
    // Ivar Bloodfang
    SPELL_CLEAVE                = 87719,

    // High Warlord Cromush
    SPELL_TELEPORT_VISUAL       = 12980,

    // Bloodfang Berserker
    SPELL_STEALTH               = 58506,
    SPELL_PERMANENT_FEIGN_DEATH = 29266,

    // Plague Dummy
    SPELL_DISEASE_CLOUD         = 88198
};

enum SKCreatures
{
    // Baron Ashbury
    BOSS_BARON_ASHBURY          = 46962,

    // Baron Silverlaine
    BOSS_BARON_SILVERLAINE      = 3887,

    NPC_NANDOS_DUMMY            = 51047,
    NPC_WOLF_MASTER_NANDOS      = 50851,
    NPC_LUPINE_SPECTRE          = 50923,
    NPC_ODO_DUMMY               = 50934,
    NPC_ODO_THE_BLINDWATCHER    = 50857,
    NPC_RAZORCLAW_DUMMY         = 51080,
    NPC_RAZORCLAW_THE_BUTCHER   = 50869,
    NPC_RETHILGORE_DUMMY        = 51085,
    NPC_RETHILGORE              = 50834,

    // Commander Springvale
    BOSS_COMMANDER_SPRINGVALE   = 4278,
    NPC_TORMENTED_OFFICER       = 50615,
    NPC_WAILING_GUARDSMAN       = 50613,
    NPC_SHIELD_FOCUS            = 50547,
    NPC_DESECRATION_STALKER     = 50503,

    // Lord Walden
    BOSS_LORD_WALDEN            = 46963,
    NPC_MYSTERY_MIXTURE         = 50522,

    // Lord Godfrey
    BOSS_LORD_GODFREY           = 46964,
    NPC_BLOODTHIRSTY_GHOUL      = 50561,
    NPC_PISTOL_BARRAGE_DUMMY    = 52065,

        // Generic NPCs
    NPC_VETERAN_FORSAKEN_TROOPER = 47030,
    NPC_DEATHSTALKER_BELMONT    = 47293,
    NPC_FORSAKEN_BLIGHTSPREADER = 47031,
    NPC_HIGH_WARLORD_CROMUSH    = 47294,
    NPC_DISEASE_BUNNY           = 23837,
    NPC_BLOODFANG_BERSERKER     = 47027,
    NPC_PACKLEADER_IVAR         = 47006,
    NPC_HIGH_MAGISTRATE_HENRY   = 47862
};

enum SKGameObjectIds
{
    GO_COURTYARD_DOOR   = 18895,
    GO_SORCERER_DOOR    = 18972,
    GO_ARUGAL_DOOR      = 18971
};

enum SKDataTypes
{
    DATA_BARON_ASHBURY          = 0,
    DATA_BARON_SILVERLAINE      = 1,
    DATA_COMMANDER_SPRINGVALE   = 2,
    DATA_LORD_WALDEN            = 3,
    DATA_LORD_GODFREY           = 4,
    DATA_APOTHECARY_HUMMEL      = 5,

    DATA_TEAM_IN_INSTANCE       = 6,
    DATA_PACKLEADER_IVAR        = 7,
    DATA_DEATHSTALKER_BELMONT   = 8,
    DATA_ASHBURY_OUTRO          = 9,
    DATA_WALDEN_INTRO           = 10,
    DATA_WALDEN_OUTRO           = 11,
    DATA_GODFREY_INTRO          = 12,
    DATA_ARUGAL_DOOR            = 13,
    DATA_SORCERER_GATE          = 14,
    DATA_COURTYARD_DOOR         = 15,
    DATA_HIGH_WARLORD_CROMUSH   = 16
};

enum SKSummonGroups
{
    SUMMON_GROUP_BLIGHT_ENTRANCE    = 0,
    SUMMON_GROUP_BLIGHT_ASHBURY     = 1,
    SUMMON_GROUP_BLIGHT_SPRINGVALE  = 2,
    SUMMON_GROUP_BLIGHT_WALDEN      = 3
};

enum SKActions
{
    ACTION_ASHBURY_DEAD = 1,
    ACTION_SILVERLAINE_DEAD,
    ACTION_SPRINGVALE_DEAD,
    ACTION_WALDEN_INTRO,
    ACTION_WALDEN_DEAD,
    ACTION_GODFREY_INTRO,

    ACTION_WORGEN_1 = 6,
    ACTION_WORGEN_2,
    ACTION_WORGEN_3,
    ACTION_WORGEN_4,
    ACTION_WORGEN_5,
    ACTION_WORGEN_6,
    ACTION_WORGEN_7,
    ACTION_WORGEN_8,
    ACTION_WORGEN_9,
    ACTION_WORGEN_10 = 18,
    ACTION_WORGEN_11,
    ACTION_WORGEN_12,
    ACTION_WORGEN_13,
    ACTION_WORGEN_14,
    ACTION_WORGEN_15,
    ACTION_WORGEN_16,
    ACTION_WORGEN_17,
    ACTION_WORGEN_18,
    ACTION_WORGEN_19,
    ACTION_DESPAWN,
    ACTION_DESPAWN_BERSERKERS,

    ACTION_CROMUSH_SUMMONED_1,
    ACTION_CROMUSH_SUMMONED_2,
    ACTION_CROMUSH_SUMMONED_3,
    ACTION_CHEER,
    ACTION_CROMUSH_POISONED
};

Position const SKIvarSpawnPositions[] =
{
    // -- Initial Position
    { -219.417f, 2137.05f, 80.97094f, 4.485496f },

    // -- After Baron Ashbury
    { -239.936f, 2116.16f, 87.08714f, 2.740167f },

    // After Baron Silverlaine
    { -275.7328f, 2297.717f, 98.45776f, 5.873963f },

    // Lord Walden Intro
    { -241.7769f, 2216.979f, 106.4597f, 4.622139f },

    // After Lord Walden
    { -171.4323f, 2179.851f, 129.3079f, 0.6615827f },

    // Lord Godfrey Intro
    { -158.8089f, 2177.924f, 153.1174f, 5.883088f }
};

Position const SKBelmontSpawnPositions[] =
{
    // -- Initial Position
    { -220.958f, 2129.48f, 80.78983f, 4.607669f },

    // -- After Baron Ashbury
    { -240.5535f, 2130.556f, 87.04115f, 4.047379f },

    // -- After Baron Silverlaine Death
    { -260.385f, 2290.04f, 75.08263f, 2.775074f },

    // After Commander Springvale
    { -264.7126f, 2269.896f, 97.17555f, 5.929502f },

    // After Lord Walden
    { -171.7906f, 2180.634f, 129.2917f, 1.069335f },

    // Lord Godfrey Intro
    { -168.978f, 2185.792f, 151.9715f, 4.799315f }
};

Position const SKCromushSpawnPos1 = { -269.828f, 2293.46f, 77.56844f, 5.951573f };
Position const SKCromushSpawnPos2 = { -137.918f, 2169.69f, 136.6613f, 2.775074f };
Position const SKCromushSpawnPos3 = { -110.026f, 2158.99f, 155.7623f, 6.178465f };

Position const SKAllianceSpawnPositions[] =
{
    // -- Initial Positions
    { -215.484f, 2126.58f, 80.70493f, 4.468043f },
    { -214.123f, 2132.59f, 80.90813f, 4.468043f },
    { -225.997f, 2135.15f, 80.93173f, 4.660029f },
    { -216.786f, 2121.5f, 80.34393f, 4.468043f },
    { -226.573f, 2128.72f, 80.74143f, 4.660029f },
    { -227.486f, 2124.11f, 80.37684f, 4.660029f },
    // -- After Baron Ashbury
    { -246.389f, 2112.02f, 87.09373f, 2.775074f },
    { -247.602f, 2112.6f, 87.09563f, 2.775074f },
    { -248.965f, 2113.26f, 87.09624f, 2.984513f },
    { -229.707f, 2144.31f, 90.70734f, 2.792527f },
    { -227.457f, 2149.91f, 90.70734f, 2.792527f },
    { -235.0097f, 2136.43f, 87.09737f, 4.719248f },
    // -- After Baron Silverlaine
    { -218.0156f, 2279.316f, 97.33107f, 2.986222f },
    { -231.9997f, 2276.49f, 97.51645f, 2.454399f },
    { -243.6083f, 2282.398f, 97.77464f, 2.64016f },
    { -287.359f, 2313.4f, 92.71404f, 4.39823f },
    { -293.95f, 2316.14f, 92.78304f, 4.433136f },
    { -292.418f, 2310.59f, 90.83453f, 4.34587f },
    // -- After Commander Springvale
    { -263.906f, 2269.6f, 97.62373f, 5.88176f },
    { -262.012f, 2268.67f, 98.67534f, 5.934119f },
    { -259.929f, 2267.86f, 99.79284f, 5.934119f },
    // -- After Lord Walden
    { -148.575f, 2178.92f, 128.2843f, 5.078908f },
    { -152.111f, 2170.61f, 128.2843f, 0.3665192f },
    { -143.906f, 2167.56f, 128.2843f, 1.972222f },
    { -156.882f, 2177.6f, 128.7793f, 5.864306f },
    { -136.068f, 2168.84f, 128.7793f, 2.722714f },
    { -151.531f, 2162.95f, 128.7793f, 1.082104f },
    { -141.684f, 2183.09f, 128.7793f, 4.29351f },
    // -- Lord Godfrey Corpses
    { -94.9236f, 2128.72f, 145.0043f, 3.665191f },
    { -76.5694f, 2138.99f,154.2303f, 0.296706f },
    { -87.4427f, 2152.68f, 145.0043f, 3.141593f },
    { -74.6024f, 2152.2f, 155.7893f, 2.827433f }
};

Position const SKHordeSpawnPositions[] =
{
    // -- Initial Positions
    { -228.497f, 2122.73f, 80.25184f, 4.782202f},
    { -216.899f, 2120.18f, 80.24763f, 4.276057f },
    { -226.722f, 2124.83f, 80.44633f, 4.625123f },
    { -217.365f, 2122.68f, 80.41753f, 4.34587f },
    { -214.486f, 2134.03f, 80.94864f, 4.485496f },
    { -225.693f, 2136.02f, 80.95454f, 4.677482f },
    // -- After Baron Ashbury
    { -237.592f, 2150.78f, 90.70734f, 4.555309f },
    { -240.047f, 2143.16f, 87.09624f, 4.45059f },
    { -233.597f, 2140.91f, 87.09624f, 4.39823f },
    { -233.04f, 2149.04f, 90.70734f, 4.34587f },
    { -218.477f, 2146.08f, 90.70734f, 2.897247f },
    { -220.705f, 2140.32f, 90.70734f, 2.75762f },
    // -- After Baron Silverlaine
    { -287.7312f, 2299.908f, 89.64044f, 4.768981f },
    { -285.8244f, 2304.515f, 89.64634f, 0.6435287f },
    { -288.9552f, 2300.522f, 89.72758f, 4.921014f },
    { -287.1191f, 2305.041f, 89.74182f, 0.5727214f },
    { -223.637f, 2275.91f, 77.13573f, 5.585053f },
    { -217.88f, 2285.48f, 77.13573f, 1.448623f },
    // -- After Lord Walden
    { -136.833f, 2161.72f, 138.7803f, 2.059489f },
    { -134.288f, 2164.36f, 138.7803f, 2.373648f },
    { -131.498f, 2170.57f, 138.7803f, 3.124139f },
    { -131.438f, 2174.3f, 138.7803f, 3.473205f },
    { -132.72f, 2166.21f, 138.7803f, 2.80998f },
    { -131.734f, 2167.9f, 138.7803f, 2.80998f },
    // Godfrey Corpses
    { -91.5174f, 2148.32f, 145.0043f, 0.0f },
    { -111.995f, 2133.53f, 145.0043f, 1.692969f },
    { -75.3976f, 2143.99f, 155.6093f, 3.577925f },
    { -94.2517f, 2138.56f, 145.0043f, 5.148721f },
    { -87.6441f, 2126.23f, 145.0043f, 2.443461f },
    { -102.142f, 2123.2f, 155.7383f, 5.864306f }
};

template<class AI>
AI* GetShadowfangKeepAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, SKScriptName);
}

#define RegisterShadowfangKeepCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetShadowfangKeepAI)

#endif
