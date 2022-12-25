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

#include "black_rook_hold.h"

enum Says
{
    //Kurtalos
    SAY_AGGRO = 0,

    //Latosius
    SAY_DARK_BLAST = 0,
    SAY_WARN_DREADLORDS_GUILE = 1,
    SAY_DREADLORDS_GUILE = 2,
    SAY_CLOUD_OF_HYPNOSIS = 3,
};

enum Spells
{
    //Kurtalos
        //Phase 1
    SPELL_UNERRING_SHEAR = 198635,
    SPELL_WHIRLING_BLADE = 198641,
    SPELL_WHIRLING_BLADE_AT = 198782,
    SPELL_SUICIDE = 117624,

    //Phase 2
    SPELL_KURTALOS_GHOST_VISUAL = 199243,
    SPELL_LEGACY_RAVENCREST = 199368,

    //Latosius
        //Phase 1
        SPELL_TELEPORT_1 = 198835,
        SPELL_TELEPORT_2 = 199058,
        SPELL_SHADOW_BOLT = 198833,
        SPELL_DARK_BLAST = 198820,

        //Phase 2
        SPELL_CONVERSATION = 199239, // Dreadlord Conversation
        SPELL_SAP_SOUL = 198961,
        SPELL_TRANSFORM = 199064,
        SPELL_SHADOW_BOLT_VOLLEY = 202019,
        SPELL_CLOUD_OF_HYPNOSIS = 199143,
        SPELL_DREADLORDS_GUILE = 199193,
        SPELL_BREAK_PLR_TARGETTING = 140562,
        SPELL_DARK_OBLITERATION = 199567,
        SPELL_DARK_OBLITERATION_AT = 241672,

        //Heroic
        SPELL_STINGING_SWARM = 201733,
        SPELL_ITCHY_STUN = 199168,
};

enum eEvents
{
    //Kurtalos
        //Phase 1
    EVENT_UNERRING_SHEAR = 1,
    EVENT_WHIRLING_BLADE = 2,

    //Latosius
        //Phase 1
        EVENT_LATOSIUS_TP = 1,
        EVENT_SHADOW_BOLT = 2,
        EVENT_DARK_BLAST = 3,

        //Phase 2
        EVENT_LATOSIUS_TP_2 = 4,
        EVENT_SAP_SOUL = 5,
        EVENT_TRANSFORM = 6,
        EVENT_SHADOW_BOLT_VOLLEY = 7,
        EVENT_CLOUD_OF_HYPNOSIS = 8,
        EVENT_DREADLORDS_GUILE = 9,
        EVENT_SUM_IMAGE = 10,
        EVENT_IMAGE_END = 11,
        EVENT_STINGING_SWARM = 12, //Heroic

        EVENT_1,
        EVENT_2,
        EVENT_3,

        ACTION_1,
};

enum ePhase
{
    PHASE_1 = 0,
    PHASE_2 = 1,
};

Position const tpPos[12] =
{
    {3169.09f, 7432.38f, 271.60f, 5.42f},
    {3165.53f, 7421.75f, 271.60f, 5.85f},
    {3158.29f, 7414.00f, 271.60f, 0.0f },
    {3164.16f, 7395.63f, 271.60f, 0.62f},
    {3173.76f, 7387.44f, 271.60f, 1.08f},
    {3184.47f, 7383.66f, 271.60f, 1.49f},
    {3200.61f, 7390.41f, 271.60f, 2.14f},
    {3205.70f, 7400.89f, 271.60f, 2.61f},
    {3210.50f, 7409.22f, 271.60f, 3.02f},
    {3204.84f, 7427.28f, 271.60f, 3.84f},
    {3195.91f, 7430.39f, 271.60f, 4.24f},
    {3186.87f, 7436.26f, 271.60f, 4.70f}
};

void AddSC_boss_lord_kurtalos_ravencrest()
{
    
}
