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

#include "AreaTriggerAI.h"
#include "tomb_of_sargeras.h"
#include "AreaTrigger.h"
#include "AreaTriggerTemplate.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_THUNDERING_SHOCK = 1,
    SAY_HYDRA_SHOT_WARN = 2,
    SAY_SLICING_TORNADO = 3,
    SAY_SLICING_TORNADO_WARN = 4,
    SAY_PHASE_2 = 5,
    SAY_CALL_VELLIUS = 6,
    SAY_BECKON_SARUKEL = 7,
    SAY_BECKON_SARUKEL_WARN = 8,
    SAY_PHASE_3 = 9,
    SAY_DEATH = 10,
};

enum Spells
{
    SPELL_BURDEN_OF_PAIN = 230201,
    SPELL_BURDEN_OF_PAIN_SHARE_DMG = 230214,
    SPELL_FROM_THE_ABYSS = 230227,
    SPELL_HYDRA_SHOT_FILTER = 232753,
    SPELL_HYDRA_SHOT_MARK = 230139,
    SPELL_HYDRA_SHOT_DMG = 230143,
    SPELL_HYDRA_ACID = 232754,
    SPELL_HYDRA_ACID_STUN = 234332,
    SPELL_SLICING_TORNADO_FILTER = 232722,
    SPELL_SLICING_TORNADO_AT_1 = 232723, //unk
    SPELL_SLICING_TORNADO_AT_2 = 234809, //Aura
    SPELL_THUNDERING_SHOCK_FILTER = 230358,
    SPELL_THUNDERING_SHOCK_SUMMON = 230360,
    SPELL_CONSUMING_HUNGER_FILTER = 230384, //Set VehicleID to Player
    SPELL_CONSUMING_HUNGER_SUMMON = 230855,
    SPELL_CONSUMING_HUNGER_RIDE_VEH = 230920,
    SPELL_BECKON_SARUKEL = 232746,
    SPELL_SUMMON_OSSUNET = 232756,
    SPELL_CALL_VELLIUS = 232757,
    SPELL_BERSERK = 47008,

    //Mythic
    SPELL_DELICIOUS_BUFFERFISH_DUMMY = 239369,
    SPELL_DELICIOUS_BUFFERFISH_ENERGIZE = 239362, //Only Healer
    SPELL_DELICIOUS_BUFFERFISH_MOD_DMG = 239375, //Only Damage Dealer
    SPELL_DELICIOUS_BUFFERFISH_AT = 239388,
    SPELL_DELICIOUS_BUFFERFISH_DROP = 239403, //Player drop Bufferfish
    SPELL_SLIPPERY = 239420, //Debuff Penalty
    SPELL_DREAD_SHARK_DUMMY = 239423,
    SPELL_DREAD_SHARK_FILTER_1 = 239434, //Find Player
    SPELL_DREAD_SHARK_FILTER_2 = 239435, //Find Npc
    SPELL_DREAD_SHARK_DMG = 239436,

    //Abyss Stalker
    SPELL_CONCEALING_MURK_AT = 230950,
    SPELL_DARK_DEPTHS_FILTER = 230273, //Heroic+
    SPELL_DARK_DEPTHS_TELEPORT = 230274,
    SPELL_DARK_DEPTHS_DMG = 230276, //Native name: "Jaws from the Deep"

    //Electrifying Jellyfish
    SPELL_THUNDERING_SHOCK = 230362,

    //Razorjaw Waverunner
    SPELL_WATER_BLAST = 241509,
    SPELL_MURLOC_MASH = 242946, //Mythic

    //Sarukel
    SPELL_DEVOURING_MAW_MOVEMENT_AT = 232745, //Force movement. Dmg Spell: 234621
    SPELL_DEVOURING_MAW_CIRCLE_AT = 232886, //Remove Spell: Befouling Ink - 232918
    SPELL_DEVOURING_MAW_CIRCLE_AT_2 = 232884, //Killing players

    //Ossunet
    SPELL_OSSUNET_VISUAL = 234178,
    SPELL_BEFOULING_INK_FILTER = 232903,
    SPELL_BEFOULING_INK_MISSILE = 232902,
    SPELL_BEFOULING_INK_MISSILE_2 = 233302, //Player casting
    SPELL_BEFOULING_INK_AT = 232905,
    SPELL_BEFOULING_DMG = 232913,
    SPELL_BEFOULING_REMOVE = 232918,

    //Piranhado
    SPELL_CRASHING_WAVE_AT = 240759,
    SPELL_CRASHING_WAVE_DMG = 232827,
};

enum eEvents
{
    EVENT_BURDEN_OF_PAIN = 1,
    EVENT_HYDRA_SHOT = 2,
    EVENT_SLICING_TORNADO = 3,
    EVENT_THUNDERING_SHOCK = 4,
    EVENT_CONSUMING_HUNGER = 5,
    EVENT_BECKON_SARUKEL = 6,
    EVENT_SUMMON_OSSUNET = 7,
    EVENT_CALL_VELLIUS = 8,
};

enum Achievement
{
    A_SAUCE,
    A_HYDRA,
    A_TARTAR,
    A_MURLOC,
    A_PLAYER,
};

Position const centrPos = { 5799.70f, -1248.48f, 2786.24f };

Position const sarukelPos[3] =
{
    {5771.40f, -1218.03f, 2785.67f, 5.48f},
    {5826.77f, -1275.80f, 2785.67f, 2.32f},
    {5770.53f, -1275.34f, 2785.67f, 0.76f}
};

Position const ossunetPos[3] =
{
    {5833.75f, -1260.85f, 2785.67f, 2.78f},
    {5762.73f, -1233.02f, 2785.67f, 5.91f},
    {5784.01f, -1282.96f, 2785.67f, 1.17f}
};

Position const piranhadoPos[8] =
{
    {5813.55f, -1211.53f, 2785.97f, 4.35f},
    {5833.01f, -1227.46f, 2785.97f, 3.70f},
    {5781.11f, -1212.40f, 2786.33f, 5.19f},
    {5761.98f, -1231.07f, 2786.33f, 5.84f},
    {5837.62f, -1261.57f, 2786.33f, 2.81f},
    {5818.79f, -1283.59f, 2786.33f, 2.06f},
    {5763.95f, -1267.11f, 2786.33f, 0.47f},
    {5784.16f, -1286.02f, 2786.33f, 1.17f},
};

enum Misc
{
    ACTION_1 = 1,
    ACTION_2,
    ACTION_3,
    ACTION_4,
    ACTION_5,

    EVENT_1,
};

void AddSC_boss_sasszine()
{
  
}
