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

#include "eternal_palace.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"
#include "AreaTriggerAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerTemplate.h"

enum Spells
{
    SPELL_DRIBBLING_ICHOR_MISSILE = 298077,
    SPELL_DRIBBLING_ICHOR_CAST = 299095,
    SPELL_DRIBBLING_ICHOR_DAMAGE = 298087,
    SPELL_INCUBATION_FLUID_DUMMY = 298242,
    SPELL_INCUBATION_FLUID_DAMAGE = 298314,
    SPELL_INCUBATION_FLUID_AURA = 298306,
    SPELL_ARCING_CURRENT = 295825,
    SPELL_CHAOTIC_GROWTH = 296914,
    SPELL_PERVASIVE_SHOCK = 295161,
    SPELL_AMNIOTIC_SPLATTER_AT = 307253,
    SPELL_AMNIOTIC_SPLATTER_DAMAGE = 298458,
    SPELL_AMNIOTIC_ERRUPTION = 298459,
    SPELL_AMNIOTIC_SPLATTER_VISUAL = 298435,
    SPELL_DESENSITIZING_STING = 298156,
    SPELL_HEART_STOPPING_PARALYSIS = 298164,
    SPELL_MASSIVE_INCUBATOR_AURA = 305347,
    SPELL_MASSIVE_INCUBATOR_CAST = 298548,
    SPELL_HATCHERY_MOULTING_AURA = 298522,
    SPELL_HATCHERY_MOULTING_MISSILE = 298525,
    SPELL_HATCHERY_MOULTING_DAMAGE = 298526,
    SPELL_HATCHERY_EGG_AT_MARK = 300276,
    SPELL_EGGSPLOSION = 300308,
    SPELL_AQUA_LANCE_MISSILE = 295799,
    SPELL_AQUA_LANCE_AURA = 295779,
    SPELL_AQUA_LANCE_AT = 295808,
    SPELL_RAGING_RAPIDS_AURA = 300244,
    SPELL_SHOCKING_LIGHTNING = 295818,
    SPELL_CONDUCTIVE_PULSE = 295822,
    SPELL_POWERFUL_STOMP = 296691,
    SPELL_REVERBERATING_TREMOR = 296698,
};

enum OrgozoaEvents
{
    EVENT_INCUBATION_FLUID = 1,
    EVENT_ARCING_CURRENT,
    EVENT_DRIBBLING_ICHOR_PHASE_1,
    EVENT_DRIBBLING_ICHOR_PHASE_2,
    EVENT_ENERGY_CHECK,
    EVENT_SUMMON_ADDS_PHASE_1,
    EVENT_DESENSITIZING_STING,
    EVENT_SUMMON_ADDS_PHASE_2,
    EVENT_AQUA_LANCE,
    EVENT_SHOCKING_LIGHTNING,
    EVENT_CONDUCTIVE_PULSE,
    EVENT_POWERFUL_STOMP,
    EVENT_PERVASIVE_SHOCK,
};

enum Timers
{
    TIMER_INCUBATION_FLUID = 23 * IN_MILLISECONDS,
    TIMER_ARCING_CURRENT = 9 * IN_MILLISECONDS,
    TIMER_DRIBBLING_ICHON = 1 * IN_MILLISECONDS,
    TIMER_ENERGY_CHECK = 2 * IN_MILLISECONDS,
    TIMER_SUMMON_ADDS_PHASE_1 = 15 * IN_MILLISECONDS,
    TIMER_DESENSITIZING_STING = 7 * IN_MILLISECONDS,
    TIMER_SUMMON_ADDS_PHASE_2 = 15 * IN_MILLISECONDS,
    TIMER_AQUA_LANCE = 15 * IN_MILLISECONDS,
    TIMER_POWERFUL_STOMP = 30 * IN_MILLISECONDS,
    TIMER_SHOCKING_LIGHTNING = 15 * IN_MILLISECONDS,
    TIMER_CONDUCTIVE_PULSE = 15 * IN_MILLISECONDS,
    TIMER_PERVASIVE_SHOCK = 10 * IN_MILLISECONDS,
};

enum MovementEvents
{
    EVENT_ACTION_MOVE_2 = 20,
    EVENT_ACTION_MOVE_3,
    EVENT_ACTION_MOVE_4,
    EVENT_ACTION_MOVE_5,
    EVENT_ACTION_MOVE_6,
    EVENT_ACTION_MOVE_7,
    EVENT_ACTION_MOVE_8,
};

enum Points
{
    POINT_1 = 200,
    POINT_2,
    POINT_3,
    POINT_4,
    POINT_5,
    POINT_6,
    POINT_7,
    POINT_8_FINAL, // cast
};

Position phase1Adds[2] =
{
    {236.22f, 707.51f, 1060.93f},
    {290.85f, 700.58f, 1060.94f},
};

Position phase2Adds[2] =
{
    {192.17f, 823.58f, 1010.77f},
    {252.74f, 818.31f, 1010.98f},
};

Position phase2Intermission[8] =
{
    {268.44f, 721.32f, 1060.82f},
    {272.97f, 741.00f, 1060.25f},
    {326.45f, 737.38f, 1051.20f},
    {346.47f, 762.44f, 1043.44f},
    {326.42f, 798.75f, 1034.46f},
    {212.08f, 774.73f, 1010.85f},
    {211.57f, 809.72f, 1010.75f},
    {220.20f, 818.42f, 1010.81f},
};

const Position firstPlatform = { 267.31f, 703.25f, 1060.80f }; //30y
const Position secondPlatform = { 220.20f, 818.42f, 1010.81f }; //50y 

Position hatcheryEgg[25] =
{
    { 218.68f, 778.92f, 1010.92f },
    {231.12f, 774.02f, 1014.37f},
    {238.68f, 782.15f, 1017.11f},
    {245.94f, 776.49f, 1019.71f},
    {259.33f, 774.78f, 1023.61f,},
    {273.67f, 779.43f, 1025.80f},
    {267.61f, 787.05f, 1025.38f},
    {283.98f, 796.09f, 1026.94f},
    {296.16f, 790.87f, 1028.03f},
    {304.71f, 799.31f, 1029.78f},
    {316.43f, 793.76f, 1032.32f},
    {321.22f, 800.04f, 1033.25f},
    {327.51f, 790.89f, 1035.81f},
    {336.40f, 783.79f, 1038.50f},
    {346.83f, 778.13f, 1040.27f},
    {337.77f, 763.72f, 1043.83f},
    {344.07f, 753.08f, 1045.55f},
    {334.71f, 748.83f, 1047.64f},
    {325.72f, 739.09f, 1051.20f},
    {314.48f, 741.38f, 1053.99f,},
    {311.12f, 729.96f, 1054.75f},
    {302.14f, 737.68f, 1057.32f},
    {292.33f, 741.42f, 1059.23f},
    {284.90f, 737.96f, 1060.05f},
    {279.57f, 745.14f, 1060.55f},
};

void AddSC_boss_orgozoa()
{
    
}
