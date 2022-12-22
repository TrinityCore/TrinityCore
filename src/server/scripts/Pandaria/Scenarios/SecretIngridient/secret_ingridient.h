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

#ifndef SECRET_INGRIDIENT_H_
#define SECRET_INGRIDIENT_H_

const Position scholarPath[3] =
{
    { -231.36f, 610.79f, 166.79f, 3.20f },
    { -248.50f, 610.50f, 167.54f, 3.16f },
    { -259.12f, 609.47f, 167.54f, 4.47f },
};

const Position seatPlaces[4] =
{
    { -252.4358f, 598.7969f, 167.5478f, 0.0f },
    { -263.7517f, 601.9688f, 167.5478f, 0.0f },
    { -257.2552f, 603.0f, 167.5478f, 0.0f },
    { -258.3993f, 597.5156f, 167.5478f, 0.0f },
};

const Position cholarLeavePath[2] =
{
    { -267.76f, 603.08f, 167.54f, 3.70f },
    { -277.31f, 597.38f, 167.46f, 3.67f },
};

const Position noodleSpawnPos = { -264.1379f, 585.9539f, 167.5478f, 1.038f};

enum Data
{
    DATA_TUTORIAL,
    DATA_NOODLE_TIME,
    DATA_PLAYER,
    DATA_AVAILABLE_COOK_NOODLE,
    DATA_AVAILABLE_COOK_WHOLE,
    DATA_EATEN_COUNT,

    // Misc
    TYPE_CLICK_ON_TRAINING,
    TYPE_QUEUE_PLACE,
    TYPE_HOLD_QUEUE,
    TYPE_EATEN_OR_NOT,
};

enum Creatures
{
    NPC_NOODLE_STAND          = 72952,
    NPC_SHOLAR                = 72916,
    NPC_IMPATIENT_MERCHANT    = 72919,
    NPC_SEAT                  = 72928,
    NPC_SUNGSHIN_IRONPAW      = 73316,
    NPC_QUEUE                 = 72960,
    NPC_NOODLE_SOUP           = 72961,
    NPC_DRAGONS_NOODLE_SOUP   = 72962,
    NPC_PANDARENS_NOODLE_SOUP = 72963,
    NPC_QUEUE_CREDIT          = 73365,
    NPC_INGRIDIENT_CREDIT     = 72984,
};

enum GameObjects
{
    GO_GRILL_TABLE    = 216310,
    GO_OVEN           = 214163,
    GO_BENCH          = 221738,
    GO_BREWERY_DOOR   = 211976,
    GO_BREWERY_DOOR_2 = 211977,
    GO_BREWERY_DOOR_3 = 211981,
    GO_BREWERY_DOOR_4 = 211982,
    GO_STOOL          = 221726,
    GO_TABLE          = 221724,
    GO_STOVE          = 223742,
};

enum Yells
{
    TALK_INTRO,
    TALK_SPECIAL_1,
    TALK_SPECIAL_2,
    TALK_SPECIAL_3,
    TALK_SPECIAL_4,
    TALK_SPECIAL_5,
    TALK_SPECIAL_6,
    TALK_SPECIAL_7,
    TALK_SPECIAL_8,
    TALK_SPECIAL_9,
    TALK_SPECIAL_10,
    TALK_SPECIAL_11,
    TALK_SPECIAL_12,
};

enum Actions
{
    ACTION_INTRO,
    ACTION_SPECIAL_1,
    ACTION_SELECT_SEAT_ON_TRAINING,
    ACTION_MOVE_TO_TABLE,
    ACTION_CUSTOMER_AT_TABLE_TRAINING,
    ACTION_FIRST_NOODLE_IS_READY,
    ACTION_EAT_SENT,
    ACTION_FIRST_NOODLE_EATEN,
    ACTION_SCHOLAR_LEAVE,
};

enum Spells
{
    SPELL_CHAINING_DELIVIRING             = 148794,
    SPELL_CHAINING_SEATING                = 148793,
    SPELL_WAITING_FOR_FOOD                = 146448, // timer while seating
    SPELL_WAITING_IN_LINE                 = 146506, // time while in queue
    SPELL_COOKING_NOODLE_TIME             = 147180,
    SPELL_DELIVER_SOUP                    = 146449,
    SPELL_NOT_IN_LINE                     = 149234, // on scholar click (ping)
    SPELL_NOODLE_STAND                    = 146424, // summon player vehicle
    SPELL_SPAWN_SEAT                      = 146405,
    SPELL_SELECT_SEAT                     = 146398, // ping on spellclick
    SPELL_SEAT_AVAILABLE                  = 146399, // blue beam
    SPELL_GET_IN_LINE                     = 146434, // vehicle
    SPELL_TIMER_VISUAL_40                 = 148811,
    SPELL_TAILY_SCORE                     = 146515,
    SPELL_CLICK_ME                        = 147483, // by iron paw to objects
    SPELL_VEHICLE_SET_UP                  = 134620, // veh for player

    // Coocking
    SPELL_MAKE_NOODLE_SOUP                = 146421,
    SPELL_MAKE_DRAGONS_NEST_SOUP          = 146422,
    SPELL_MAKE_PANDARENS_TREASURES_SOUP   = 146423,
    SPELL_EATING_NOODLE_SOUP              = 146472,
    SPELL_EATING_DRAGONS_NEST_SOUP        = 146473,
    SPELL_EATING_PANDARENS_TREASURES_SOUP = 146474,
    SPELL_NOODLE_SOUP_FIRST               = 149020, // has not timer
    SPELL_NOODLE_SOUP                     = 146440,
    SPELL_DRAGON_NEST_NOODLE_SOUP         = 146441,
    SPELL_PANDARENS_TREASURES_NOODLE_SOUP = 146442,
    SPELL_SOUP_TIMER_30                   = 147621,
};

enum Worldstates
{
    WORLDSTATE_CLIENTS = 8457,
};

enum Quests
{
    QUEST_SECRET_INGRIDIENT_IS = 33027,
};

const std::map<uint32, std::array<uint32, 2>> invSoupVisualType =
{
    { NPC_NOODLE_SOUP,           { SPELL_NOODLE_SOUP,                     SPELL_EATING_NOODLE_SOUP              } },
    { NPC_DRAGONS_NOODLE_SOUP,   { SPELL_DRAGON_NEST_NOODLE_SOUP,         SPELL_EATING_DRAGONS_NEST_SOUP        } },
    { NPC_PANDARENS_NOODLE_SOUP, { SPELL_PANDARENS_TREASURES_NOODLE_SOUP, SPELL_EATING_PANDARENS_TREASURES_SOUP } },
};

#endif // SECRET_INGRIDIENT_H_
