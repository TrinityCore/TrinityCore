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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "halls_of_valor.h"

enum Says
{
    SAY_UNNERVING_HOWL = 0,
    SAY_END = 1,
    SAY_BLOOD = 1,
};

enum Spells
{
    SPELL_UNNERVING_HOWL = 196543,
    SPELL_RAVENOUS_LEAP = 197558,
    SPELL_RAVENOUS_LEAP_FILTER = 197549,
    SPELL_RAVENOUS_LEAP_T_1 = 197560,
    SPELL_RAVENOUS_LEAP_JUMP = 196495,
    SPELL_RAVENOUS_LEAP_DOT = 196497,
    SPELL_RAVENOUS_LEAP_AOE = 196496,
    SPELL_CLAW_FRENZY = 196512,
    SPELL_SCENT_OF_BLOOD = 198800,
    //Heroic
    SPELL_SPAWN_WOLVES = 207708,
    SPELL_STEALTH_WOLFS = 207707,
    SPELL_STRENGTH_PACK = 199186,
    SPELL_STRENGTH_PACK_MOD_DMG = 199184,

    //Cosmetic
    SPELL_STEALTH = 196567,
    SPELL_LICKING_WOUNDS = 200561,
    SPELL_BLOOD_SPLAT = 200553,

    //Conversation
    SPELL_ODYN_HUNTING_GROUND = 202153,
};

enum eEvents
{
    EVENT_UNNERVING_HOWL = 1,
    EVENT_RAVENOUS_LEAP = 2,
    EVENT_CLAW_FRENZY = 3,
    EVENT_SCENT_OF_BLOOD = 4,
    EVENT_SPAWN_WOLVES = 5,

    EVENT_LOW_HP_MOVE_LAIR = 5,
};

Position const oneTrashPos[12] =
{
    {3006.39f, 2980.55f, 618.48f, 2.26f},
    {3075.17f, 3008.41f, 609.65f, 5.10f},
    {3088.34f, 2989.26f, 614.69f, 5.63f},
    {3016.72f, 3009.90f, 609.72f, 0.35f},
    {3036.83f, 3021.59f, 607.72f, 0.31f},
    {3066.19f, 3016.52f, 609.92f, 5.52f},
    {2999.78f, 2996.95f, 615.46f, 1.04f},
    {3048.63f, 3021.88f, 607.67f, 0.19f},
    {3078.62f, 2995.89f, 612.31f, 5.37f},
    {3029.34f, 3013.41f, 608.78f, 0.58f},
    {3058.14f, 3023.87f, 607.94f, 6.06f},
    {3009.28f, 3003.14f, 612.59f, 0.64f}
};

Position const secondTrashPos[13] =
{
    {3154.69f, 3166.24f, 593.60f, 3.29f},
    {3130.42f, 3104.78f, 597.30f, 4.24f},
    {3088.16f, 2989.61f, 614.72f, 5.46f},
    {3078.62f, 2996.61f, 612.20f, 5.23f},
    {3076.25f, 3009.70f, 609.88f, 4.60f},
    {3075.56f, 3029.13f, 606.97f, 4.30f},
    {3093.55f, 3041.78f, 605.68f, 3.84f},
    {3098.51f, 3055.33f, 603.27f, 4.06f},
    {3109.60f, 3063.75f, 604.57f, 4.21f},
    {3113.69f, 3076.36f, 602.11f, 4.15f},
    {3126.08f, 3089.76f, 600.51f, 4.22f},
    {3140.12f, 3117.60f, 597.83f, 4.38f},
    {3142.36f, 3131.53f, 596.98f, 4.36f}
};

void AddSC_boss_fenryr()
{
   
}
