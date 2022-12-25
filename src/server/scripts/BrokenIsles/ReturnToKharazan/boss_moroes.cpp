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

#include "new_karazhan.h"
#include "CreatureGroups.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_GHASTLY_PURGE = 1,
    SAY_DEATH = 2,
};

enum Spells
{
    //Moroes
    SPELL_VANISH_FILTER = 227737,
    SPELL_VANISH = 227736,
    SPELL_GARROTE = 227742,
    SPELL_CONVERS_COAT = 229848,
    SPELL_COAT_CHECK = 227851,
    SPELL_COAT_CHECK_RESIST = 227832,
    SPELL_GHASTLY_PURGE = 227872,

    SPELL_SUMMON_KEYS = 233989,

    ///Trash
    SPELL_DINNER_PARTY = 233669,
    SPELL_DINNER_PARTY_AT = 233671,

    //Baroness Dorothea Millstipe
    SPELL_ARCANE_BLAST = 227575,
    SPELL_MANA_DRAIN = 227545,

    //Lady Catriona Von'Indi
    SPELL_SMITE = 227542,
    SPELL_HEALING_STREAM = 227578,

    //Baron Rafe Dreuger
    SPELL_IRON_WHIRLWIND = 227637,

    //Lady Keira Berrybuck
    SPELL_EMPOWERED_ARMS = 227616,

    //Lord Robin Daris
    SPELL_WHIRLING_EDGE = 227463,
    SPELL_WHIRLING_EDGE_AT = 227472,

    //Lord Crispin Ference
    SPELL_WILL_BREAKER = 227672,

    ///Event scene after death Moroes

    SPELL_VISION = 229485,

    //Medivh
    SPELL_UNCONTROLLABLE_ENERGY = 229571,
    SPELL_UNLEASHED_POWER = 232697,
    SPELL_KNOCKBACK_SELF = 66033,

    //Nielas Aran
    SPELL_PLAY_SCENE = 232486,
    SPELL_FEIGN_DEATH = 145363,
};

enum eEvents
{
    EVENT_VANISH = 1,
    EVENT_COAT_CHECK = 2,
};

//SMSG_SET_AI_ANIM_KIT
enum eAnimKit
{
    //Medivh
    ANIM_MEDIVH_1 = 5874,
    ANIM_MEDIVH_2 = 12168,
    ANIM_MEDIVH_3 = 9569,

    //Nielas Aran
    ANIM_NIELAS_1 = 12310
};

enum MedivhEvents
{
    EVENT_1 = 1,
    EVENT_2, 
    EVENT_3,
    EVENT_4,
    EVENT_5,
    EVENT_6,
    EVENT_7,
    EVENT_8,
};

void AddSC_boss_moroes_new()
{
   
}
