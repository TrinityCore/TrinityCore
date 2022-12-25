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

#include "thenighthold.h"
#include "AreaTriggerAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerTemplate.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"
#include "G3D/Vector3.h"

enum Says
{
    SAY_INTRO                               = 0,
    SAY_AGGRO                               = 1,
    SAY_ARCANETIC_RING                      = 2,
    SAY_ARCANETIC_RING_WARN                 = 3,
    SAY_SPANNING_SINGULARITY                = 4,
    SAY_CHANGE_PHASE_2                      = 5,
    SAY_CHANGE_PHASE_3                      = 6,
    SAY_EPOCHERIC_ORB                       = 7,
    SAY_EPOCHERIC_ORB_WARN                  = 8,
    SAY_DELPHURIC_BEAM                      = 9,
    SAY_DELPHURIC_BEAM_WARN                 = 10,
    SAY_CONFLEXIVE_BURST                    = 11,
    SAY_CONFLEXIVE_BURST_WARN               = 12,
    SAY_PLAYER_DEATH                        = 13,
    SAY_DEATH                               = 14,
    SAY_EVADE                               = 15,
    SAY_UNK_16                              = 16,
    SAY_UNK_17                              = 17,
    SAY_UNK_18                              = 18,
};

enum Spells
{
    SPELL_CONVERS_INTRODUCTION              = 210739, //Enter room or kill all trash?
    SPELL_TERMINATE                         = 229886, //Berserk
    SPELL_TERMINATE_AT                      = 229889,
    SPELL_TERMINATE_KILL                    = 229887,

    SPELL_ETCHED_IN_TIME                    = 208861,
    SPELL_LEAVE_NIGHTWELL_FILTER            = 208863,
    SPELL_LEAVE_NIGHTWELL                   = 208866,
    SPELL_LEAVE_NIGHTWELL_END               = 208867,
    SPELL_LEAVE_NIGHTWELL_REMOVE_DISSOLVE   = 225485,
    SPELL_CLEARALLDEBUFFS                   = 34098,
    SPELL_TIME_STOP                         = 208944,
    SPELL_TIME_STOP_ENERGY_COST             = 211647,
    SPELL_DISAPPEAR_VISUAL                  = 209026,
    SPELL_TIME_LAYER_CHANGE                 = 209030, //From player visual

    SPELL_SUM_TIME_ELEMENTAL_SLOW_DUMMY     = 211614,
    SPELL_SUM_TIME_ELEMENTAL_SLOW           = 209005,
    SPELL_SUM_TIME_ELEMENTAL_FAST_DUMMY     = 211616,
    SPELL_SUM_TIME_ELEMENTAL_FAST           = 209007,

    SPELL_SPANNING_SINGULARITY_AT           = 209500,
    SPELL_SPANNING_SINGULARITY_FILTER       = 209168,
    SPELL_SPANNING_SINGULARITY_NORMAL_2S    = 209169, //Normal, cast 2secs
    SPELL_SPANNING_SINGULARITY_NORMAL_0S    = 233010, //Normal, cast 0secs
    SPELL_SPANNING_SINGULARITY_LFR_2S       = 209186, //LFR, cast 2secs
    SPELL_SPANNING_SINGULARITY_LFR_0S       = 233009, //LFR, cast 0secs
    SPELL_SPANNING_SINGULARITY_HEROIC_2S    = 209170, //Heroic, cast 2secs
    SPELL_SPANNING_SINGULARITY_HEROIC_0S    = 233011, //Heroic, cast 0secs
    SPELL_SPANNING_SINGULARITY_MYTHIC_2S    = 209171, //Mythic, cast 2secs
    SPELL_SPANNING_SINGULARITY_MYTHIC_0S    = 233013, //Mythic, cast 0secs

    SPELL_CASCADENT_STAR                    = 229738,
    SPELL_CASCADENT_STAR_FILTER             = 229739,
    SPELL_CASCADENT_STAR_VISUAL             = 229740,
    SPELL_CASCADENT_STAR_DMG                = 229741,

    SPELL_ABLATION                          = 209615, //Phase 1
    SPELL_ABLATING_EXPLOSION                = 209973, //Phase 2
    SPELL_ABLATING_EXPLOSION_DMG            = 211799,
    SPELL_ABLATIVE_PULSE                    = 209971, //Phase 3
    SPELL_ABLATIVE_PULSE_ABLATED            = 211887,

    SPELL_ARCANETIC_TELEPORT                = 228879,
    SPELL_ARCANETIC_RING_DUMMY              = 208807,
    SPELL_ARCANETIC_RING_DUMMY_CAST         = 228877,
    SPELL_ARCANETIC_RING_FILTER             = 208808,
    SPELL_ARCANETIC_RING_AT                 = 208666,

    SPELL_DELPHURIC_BEAM_FILTER             = 209242,
    SPELL_DELPHURIC_BEAM_MARK               = 209244, //On Player
    SPELL_DELPHURIC_BEAM                    = 214278, //On Boss
    SPELL_DELPHURIC_BEAM_DMG                = 209248,

    SPELL_EPOCHERIC_ORB_FILTER              = 210022,
    SPELL_EPOCHERIC_ORB_MISSLE_NORMAL       = 210588, //108
    SPELL_EPOCHERIC_ORB_MISSLE_HEROIC       = 228949, //107
    SPELL_EPOCHERIC_ORB_MISSLE_MYTHIC       = 210589, //106
    SPELL_EPOCHERIC_ORB_SMALL_DMG           = 210024,
    SPELL_EPOCHERIC_ORB_BIG_DMG             = 210546,
    SPELL_EPOCHERIC_VULNERABILITY           = 227856, //Mythic

    SPELL_PERMELIATIVE_TORMENT_FILTER       = 210387, //2 targets
    SPELL_PERMELIATIVE_TORMENT_FILTER_2     = 225653, //Unlimited targets. wtf?
    SPELL_PERMELIATIVE_TORMENT_DOT          = 211261,

    SPELL_CONFLEXIVE_BURST_FILTER           = 209597,
    SPELL_CONFLEXIVE_BURST_AURA             = 209598,
    SPELL_CONFLEXIVE_BURST_DMG              = 209599,

    //Echo Elisande
    SPELL_TIME_ECHO_VISUAL                  = 209292,
    SPELL_DISSOLVE_VISUAL                   = 209267,
    SPELL_TIME_ECHO_WAIT_STATE_SINGULAR     = 225712,
    SPELL_TIME_ECHO_WAIT_STATE_RING         = 225471,
    SPELL_ECHO_ARCANETIC_RING               = 209330,
    SPELL_TIME_ECHO_WAIT_STATE_BEAM         = 225494,
    SPELL_ECHO_DELPHURIC_BEAM               = 214295,
    SPELL_TIME_ECHO_WAIT_STATE_ORB          = 225508,
    SPELL_ECHO_EPOCHERIC_ORB                = 213739,

    //Recursive Elemental
    SPELL_CHANGE_MODE_TIME_ELEMENTAL_SLOW   = 208914,
    SPELL_BLAST                             = 221864,
    SPELL_TIME_ELEMENTAL_DIES_SLOW_AT       = 209881,
    SPELL_TIME_SLOW                         = 209165,
    SPELL_RECURSION                         = 209620, //Mythic

    //Expedient Elemental
    SPELL_CHANGE_MODE_TIME_ELEMENTAL_FAST   = 208916,
    SPELL_EXOTHERMIC_RELEASE_FILTER         = 209571, //Deprecated?
    SPELL_EXOTHERMIC_RELEASE                = 209568,
    SPELL_TIME_ELEMENTAL_DIES_FAST_AT       = 209882,
    SPELL_TIME_FAST                         = 209166,
    SPELL_EXPEDITE_FILTER                   = 209617, //Mythic
    SPELL_EXPEDITE                          = 209618,

    //Epocheric Orb
    SPELL_EPOCHERIC_ORB_VISUAL              = 213955,
    SPELL_EPOCHERIC_ORB_AT                  = 213956,
};

enum eEvents
{
    EVENT_CHANGE_PHASE_1                    = 1,
    EVENT_CHANGE_PHASE_2                    = 2,
    EVENT_CHANGE_PHASE_3                    = 3,
    EVENT_CHANGE_PHASE_4                    = 4,
    EVENT_SPANNING_SINGULARITY              = 5,
    EVENT_CASCADENT_STAR                    = 6,
    EVENT_ABLATION                          = 7,
    EVENT_ARCANETIC_RING                    = 8,
    EVENT_SUM_SLOW_ELEMENTAL                = 9,
    EVENT_SUM_FAST_ELEMENTAL                = 10,
    EVENT_DELPHURIC_BEAM                    = 11,
    EVENT_EPOCHERIC_ORB                     = 12,
    EVENT_ABLATING_EXPLOSION                = 13,
    EVENT_ABLATIVE_PULSE                    = 14,
    EVENT_PERMELIATIVE_TORMENT              = 15,
    EVENT_CONFLEXIVE_BURST                  = 16,
};

Position const centrPos = { 282.31f, 3135.51f, 226.84f };

Position const ringPos[25] =
{
    {224.39f, 3128.61f, 226.84f, 0.12f},
    {224.39f, 3143.15f, 226.84f, 6.15f},
    {228.01f, 3114.53f, 226.84f, 0.37f},
    {228.01f, 3157.23f, 226.84f, 5.90f},
    {235.01f, 3169.97f, 226.84f, 5.65f},
    {235.01f, 3101.79f, 226.84f, 0.62f},
    {244.96f, 3091.19f, 226.84f, 0.87f},
    {244.96f, 3180.57f, 226.84f, 5.40f},
    {257.24f, 3083.40f, 226.84f, 1.13f},
    {257.24f, 3188.36f, 226.84f, 5.15f},
    {271.07f, 3192.85f, 226.84f, 4.90f},
    {271.07f, 3078.91f, 226.84f, 1.38f},
    {285.58f, 3077.99f, 226.84f, 1.63f},
    {285.58f, 3193.76f, 226.84f, 4.64f},
    {299.86f, 3191.04f, 226.84f, 4.39f},
    {299.86f, 3080.72f, 226.84f, 1.88f},
    {313.01f, 3086.91f, 226.84f, 2.13f},
    {313.01f, 3184.85f, 226.84f, 4.14f},
    {324.21f, 3175.58f, 226.84f, 3.89f},
    {324.21f, 3096.18f, 226.84f, 2.38f},
    {332.76f, 3107.94f, 226.84f, 2.63f},
    {332.76f, 3163.82f, 226.84f, 3.64f},
    {338.11f, 3150.30f, 226.84f, 3.39f},
    {338.11f, 3121.46f, 226.84f, 2.89f},
    {339.93f, 3135.88f, 226.84f, 3.14f}
};

enum Misc
{
    ACTION_1 = 1,
    ACTION_2,
    ACTION_3,
    ACTION_4,
    ACTION_5,

    EVENT_1,
    EVENT_2,
    EVENT_3,
};

void AddSC_boss_elisande()
{
    
}
