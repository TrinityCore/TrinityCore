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

#include "emerald_nightmare.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_NIGHTMARE_BLADES = 1,
    SAY_MANIFEST_CORRUPTION = 2,
    SAY_DARKENING_SOUL = 3,
    SAY_PEREPHASE = 4,
    SAY_DEATH = 5,
};

enum Spells
{
    SPELL_XAVIUS_ENERGIZE = 226192,
    SPELL_XAVIUS_ENERGIZE_PHASE_1 = 226184,
    SPELL_XAVIUS_ENERGIZE_PHASE_2 = 226193,
    SPELL_XAVIUS_ENERGIZE_PHASE_3 = 226185,
    SPELL_UNFATHOMABLE_REALITY = 207160,

    //Phase 1
    SPELL_LURKING_ERUPTION = 208322,
    SPELL_MANIFEST_CORRUPTION = 210264,
    SPELL_DARKENING_SOUL = 206651,
    SPELL_DARKENING_SOUL_AOE = 207859,
    SPELL_DARKENING_SOUL_ENERGY = 206652,
    SPELL_NIGHTMARE_BLADES_FILTER = 209000,
    SPELL_NIGHTMARE_BLADES_FILTER_2 = 211579,
    SPELL_NIGHTMARE_BLADES_SUM = 206653,
    SPELL_NIGHTMARE_BLADES_MARK = 209001,
    SPELL_NIGHTMARE_BLADES_MARK_2 = 211802,
    SPELL_NIGHTMARE_BLADES_DMG = 206656,

    //Phase 2
    SPELL_BLACKENING_SOUL = 209158,
    SPELL_BLACKENED = 205612,
    SPELL_BLACKENED_TAINTING_ENERGY = 207853,
    SPELL_NIGHTMARE_INFUSION = 209443,
    SPELL_CALL_OF_NIGHTMARES = 205588,
    SPELL_SPAWN_INCONCEIVABLE = 205739,
    SPELL_TAINTED_DISCHARGE_TRIG_AT = 208362,
    SPELL_TAINTED_DISCHARGE_AT = 208363,
    SPELL_CORRUPTION_METEOR = 206308,

    //Phase 3
    SPELL_WRITHING_DEEP = 226194,

    //Phase 2: Heroic
    SPELL_BONDS_OF_TERROR = 209032,
    SPELL_BONDS_OF_TERROR_AURA = 209034,
    SPELL_BONDS_OF_TERROR_AURA_2 = 210451,

    //Player spells
    SPELL_NIGHTMARE_TORMENT_ALT_POWER = 189960,
    SPELL_NIGHTMARE_TORMENT_TICK = 226227,
    SPELL_THE_DREAMING_SUM_CLONE = 206000,
    SPELL_THE_DREAMING_CLONE_IMAGE = 206002,
    SPELL_DREAM_SIMULACRUM = 206005,
    SPELL_AWAKENING_DREAM = 207634,
    SPELL_INSANITY_LEVEL_1 = 210203,
    SPELL_INSANITY_LEVEL_2 = 210204,
    SPELL_DESCENT_INTO_MADNESS = 208431,
    SPELL_CORRUPTION_MADNESS = 207409,

    //Player clone spells
    SPELL_DREAMING_CLONE_ABORB = 189449,

    //Dread Abomination
    SPELL_CORRUPTION_CRUSHING_SHADOWS = 208748,

    //Lurking Terror
    SPELL_TORMENTING_FIXATION_FILTER = 205770,
    SPELL_TORMENTING_FIXATION = 205771,
    SPELL_TORMENTING_INFECTION_AT = 217989,
    SPELL_TORMENTING_INFECTION_DMG = 217990,
    SPELL_TORMENTING_DETONATION_AT = 205780,
    SPELL_TORMENTING_DETONATION_DMG = 205782,

    //Corruption Horror
    SPELL_CORRUPTION_HORROR_BIRTH = 213345,
    SPELL_TORMENTING_SWIPE = 224649,
    SPELL_CORRUPTING_NOVA = 207830,

    //Inconceivable Horror
    SPELL_DARK_RUINATION = 209288,
    SPELL_TAINTED_DISCHARGE_SUM = 212124,

    //Nightmare Tentacle
    SPELL_NIGHTMARE_BOLT = 206920,
};

enum eEvents
{
    EVENT_ABOMINATION_CRUSHING = 1,
    EVENT_DARKENING_SOUL = 2,
    EVENT_NIGHTMARE_BLADES = 3,
    EVENT_BLACKENING_SOUL = 4,
    EVENT_NIGHTMARE_INFUSION = 5,
    EVENT_CORRUPTION_METEOR = 6,
    EVENT_CHECK_ALT_POWER = 7,

    //Heroic
    EVENT_BONDS_OF_TERROR,
};

enum ePhase
{
    PHASE_1 = 0,
    PHASE_2,
    PHASE_3
};

Position const dreadPos[8] =
{
    {-3061.0f, -4959.0f, 147.78f, 5.4f},
    {-2919.0f, -5101.0f, 147.78f, 2.3f},
    {-3090.0f, -5030.0f, 147.78f, 0.0f},
    {-3061.0f, -5101.0f, 147.78f, 0.7f},
    {-2990.0f, -5130.0f, 147.78f, 1.5f},
    {-2919.0f, -4959.0f, 147.78f, 3.9f},
    {-2990.0f, -4930.0f, 147.78f, 4.7f},
    {-2890.0f, -5030.0f, 147.78f, 3.1f}
};

Position const centrPos = { -2990.16f, -5029.85f, 147.78f };

Position const eventPos[10] =
{
    {-2953.67f, -5117.50f, 147.70f, 0.0f},
    {-2938.12f, -4980.82f, 147.70f, 0.0f},
    {-3069.40f, -4997.82f, 147.70f, 0.0f},

    {-2960.12f, -5043.86f, 147.70f, 0.0f},
    {-2995.12f, -4992.84f, 147.70f, 0.0f},
    {-3015.60f, -5056.74f, 147.70f, 0.0f},

    {-3030.53f, -5054.32f, 147.70f, 0.0f},
    {-2971.15f, -5066.08f, 147.70f, 0.0f},
    {-2956.51f, -4994.40f, 147.70f, 0.0f},
    {-3030.22f, -4992.07f, 147.70f, 0.0f}

};

enum Misc
{
    EVENT_1 = 1,
    EVENT_2,
    EVENT_3,
    EVENT_4,
    EVENT_5,
    EVENT_6,

    ACTION_1,
};

void AddSC_xavius()
{
    
}
