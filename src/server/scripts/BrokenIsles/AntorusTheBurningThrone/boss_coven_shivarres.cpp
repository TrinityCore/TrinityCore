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
#include "AreaTriggerAI.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    //Asara
    SAY_STORM_OF_DARKNESS = 0,

    //Noura
    SAY_AGGRO = 0,
    SAY_WHIRLING_SABER = 1,

    //Diima
    SAY_ORB_OF_FROST = 0,

    //Thuraya
    SAY_COSMIC_GLARE = 0,

    //Coven
    SAY_TORMENT_OF_GOLGANNETH = 0,
    SAY_TORMENT_OF_KHAZGOROTH = 1,
    SAY_TORMENT_OF_NORGANNON = 2,
};

enum Spells
{
    SPELL_OUTRO_CONV = 250806,
    SPELL_DAILY_ESSENCE_SHIVARRES = 305315,

    SPELL_SHARED_HEALTH = 144224,
    SPELL_SHIVAN_PACT_AT = 253189,
    SPELL_SENSE_OF_DREAD = 253752,
    SPELL_SENSE_OF_DREAD_REMOVE = 253759,
    SPELL_TORMENT_OF_GOLGANNETH = 249793,
    SPELL_TORMENT_OF_KHAZGOROTH = 250333,
    SPELL_TORMENT_OF_NORGANNON = 250334,
    SPELL_TORMENT_OF_AMANTHUL = 250335,

    //Asara
    SPELL_TOUCH_OF_DARKNESS = 245303,
    SPELL_SHADOW_BLADES = 246329,
    SPELL_SHADOW_BLADES_SUMMON = 245281,
    SPELL_SHADOW_BLADES_VISUAL = 258932,
    SPELL_SHADOW_BLADES_AURA = 245290,
    SPELL_STORM_OF_DARKNESS = 252861, //Heroic+
    SPELL_STORM_OF_DARKNESS_AT = 252919,
    SPELL_STORM_OF_DARKNESS_UNK_AT = 254018, //Unk
    SPELL_STORM_OF_DARKNESS_VISUAL_AT = 254574,
    SPELL_STORM_OF_DARKNESS_SAVE_AT = 255232,

    //Noura
    SPELL_FIERY_STRIKE = 244899,
    SPELL_WHIRLING_SABER_FILTER = 246486,
    SPELL_WHIRLING_SABER_AT = 245630,
    SPELL_FULMINATING_PULSE_FILTER = 253429, //Heroic+
    SPELL_FULMINATING_PULSE_AURA = 253520,
    SPELL_FULMINATING_BURST = 253588,

    //Diima
    SPELL_FLASHFREEZE = 245518,
    SPELL_CHILLED_BLOOD_FILTER = 245520,
    SPELL_CHILLED_BLOOD_ABSORB = 245586,
    SPELL_CHILLED_BLOOD_STUN = 256356,
    SPELL_ORB_OF_FROST_FILTER = 253649, //Heroic+
    SPELL_ORB_OF_FROST_AT = 253650,

    //Thuraya
    SPELL_TOUCH_OF_THE_COSMOS = 250648,
    SPELL_COSMIC_GLARE_MARK_FILTER = 250752,
    SPELL_COSMIC_GLARE_MARK = 250755,
    SPELL_COSMIC_GLARE_SCALE = 250757,
    SPELL_COSMIC_GLARE_SEARCH_MARK = 250758,
    SPELL_COSMIC_GLARE_SUMMON = 250763,
    SPELL_COSMIC_GLARE_DMG_FILTER = 250824,
    SPELL_COSMIC_GLARE_DUMMY = 250900,
    SPELL_COSMIC_GLARE_DMG = 250912,

    //Torments
    SPELL_MACHINATIONS_OF_AMANTHUL = 250095,
    SPELL_FURY_OF_GOLGANNETH = 246739,
    SPELL_FURY_OF_GOLGANNETH_FILTER = 246772,
    SPELL_FURY_OF_GOLGANNETH_FILTER_2 = 258065,
    SPELL_FURY_OF_GOLGANNETH_AT = 246763,
    SPELL_FURY_OF_GOLGANNETH_DMG_FILTER = 246769,
    SPELL_FURY_OF_GOLGANNETH_DMG = 246770,
    SPELL_FURY_OF_GOLGANNETH_REMOVE = 258069,
    SPELL_FURY_OF_GOLGANNETH_MARK = 260806,
    SPELL_FLAMES_OF_KHAZGOROTH = 245671,
    SPELL_VISAGE_OF_THE_TITAN = 249863,
    SPELL_SPECTRAL_ARMY_OF_NORGANNON_AT = 245910,
};

enum Events
{
    //Asara
    EVENT_SHADOW_BLADES = 1,
    EVENT_STORM_OF_DARKNESS = 2,

    //Noura
    EVENT_FIERY_STRIKE = 3,
    EVENT_WHIRLING_SABER = 4,
    EVENT_FULMINATING_PULSE = 5, //Heroic+

    //Diima
    EVENT_FLASHFREEZE = 6,
    EVENT_CHILLED_BLOOD = 7,
    EVENT_ORB_OF_FROST = 8,

    //Thuraya
    EVENT_COSMIC_GLARE = 9
};

enum eActions
{
    ACTION_ENCOUNTERS_SUMMON = 1,
    ACTION_ENCOUNTERS_RESTART,
    ACTION_ENCOUNTERS_ENTER_COMBAT,
    ACTION_ENCOUNTERS_SWITCH_BOSS,

    ACTION_TORMENT_SWITCH,
    ACTION_TORMENT_END,
    ACTION_THURAYA_JUMP
};

enum Misc
{
    TORMENT_ASARA = 0,
    TORMENT_NOURA = 1,
    TORMENT_DIIMA = 2,
    TORMENT_THURAYA = 3,

    DATA_TORMENT_STAGE,

    INVISIBLE_MODEL = 27823,
};

uint32 covenEntry[4] =
{
    NPC_ASARA,
    NPC_NOURA,
    NPC_DIIMA,
    NPC_THURAYA
};

uint32 tormentSpellId[4] =
{
    SPELL_TORMENT_OF_KHAZGOROTH,
    SPELL_TORMENT_OF_NORGANNON,
    SPELL_TORMENT_OF_GOLGANNETH,
    SPELL_TORMENT_OF_AMANTHUL
};

Position const covenPos[5] =
{
    {-12626.5f, -2811.43f, 2475.55f, 3.88f}, //Asara
    {-12644.2f, -2819.47f, 2475.56f, 6.19f}, //Noura
    {-12626.4f, -2827.51f, 2475.55f, 2.35f}, //Diima
    {-12641.5f, -2826.68f, 2475.55f, 0.74f}, //Mythic: Thuraya
    {-12642.6f, -2811.89f, 2475.55f, 5.51f}  //Mythic: Noura
};

Position const tormentPos[4] =
{
    {-12663.24f, -2791.05f, 2480.8f, 2.36f}, //Khaz'goroth's Soul
    {-12605.61f, -2791.02f, 2480.8f, 0.73f}, //Norgannon's Soul
    {-12605.71f, -2848.49f, 2480.8f, 5.46f}, //Golganneth's Soul
    {-12662.43f, -2847.72f, 2480.8f, 3.88f}  //Aman'Thul's Soul
};

Position const amanthulPos[4] =
{
    {-12667.2f, -2834.27f, 2475.08f, 0.42f},
    {-12649.5f, -2787.94f, 2475.15f, 5.16f},
    {-12602.6f, -2804.43f, 2475.37f, 3.58f},
    {-12618.8f, -2851.78f, 2475.34f, 2.01f}
};

Position const golgannethPos[4] =
{
    {-12634.49f, -2780.56f, 2475.22f, 4.71f},
    {-12676.59f, -2820.14f, 2475.34f, 0.01f},
    {-12634.44f, -2860.37f, 2475.22f, 1.57f},
    {-12590.45f, -2820.04f, 2475.17f, 3.14f}
};

Position const khazgorothPos[8] =
{
    {-12676.9f, -2820.13f, 2476.93f,  0.0f},
    {-12656.8f, -2842.03f, 2475.54f, 0.80f},
    {-12634.3f, -2859.33f, 2476.88f, 1.57f},
    {-12612.0f, -2842.17f, 2475.54f, 2.31f},
    {-12586.8f, -2819.73f, 2476.91f, 3.13f},
    {-12612.1f, -2797.80f, 2475.54f, 3.95f},
    {-12634.9f, -2781.53f, 2476.91f, 4.72f},
    {-12656.6f, -2797.45f, 2475.54f, 5.48f},
};

Position const norgannonPos[20] =
{
    {-12623.6f, -2780.66f, 2476.1f,  4.70f},
    {-12673.6f, -2829.97f, 2476.13f, 6.22f},
    {-12644.8f, -2780.8f,  2476.1f,  4.70f},
    {-12672.8f, -2819.89f, 2476.12f, 6.22f},
    {-12593.7f, -2809.54f, 2476.12f, 3.12f},
    {-12634.3f, -2781.25f, 2476.1f,  4.70f},
    {-12594.2f, -2819.78f, 2476.11f, 3.12f},
    {-12592.7f, -2800.43f, 2476.11f, 3.12f},
    {-12634.7f, -2858.38f, 2476.08f, 1.56f},
    {-12614.1f, -2859.72f, 2476.07f, 1.56f},
    {-12592.7f, -2840.41f, 2476.11f, 3.12f},
    {-12673.5f, -2839.49f, 2476.13f, 6.22f},
    {-12654.7f, -2860.16f, 2476.11f, 1.56f},
    {-12654.9f, -2779.8f,  2476.1f,  4.70f},
    {-12593.7f, -2830.61f, 2476.12f, 3.12f},
    {-12673.5f, -2799.74f, 2476.12f, 6.22f},
    {-12645.1f, -2859.03f, 2476.1f,  1.56f},
    {-12614.0f, -2779.59f, 2476.1f,  4.70f},
    {-12672.9f, -2809.39f, 2476.12f, 6.22f},
    {-12624.0f, -2858.77f, 2476.07f, 1.56f}
};

void AddSC_boss_coven_shivarres()
{
    
}
