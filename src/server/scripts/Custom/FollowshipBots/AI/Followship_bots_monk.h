/*
 * This file is part of the Stefal WoW Project.
 * It is designed to work exclusively with the TrinityCore framework.
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
 * This code is provided for personal and educational use within the
 * Stefal WoW Project. It is not intended for commercial distribution,
 * resale, or any form of monetization.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "Followship_bots_spells_handler.h"

extern std::vector<FSBSpellDefinition> MonkSpellsTable;

enum FSB_MONK_GENERIC_SPELLS
{
    SPELL_MONK_BLACKOUT_KICK = 205523, //4s, 0f, //ANY
    SPELL_MONK_LEG_SWEEP = 119381, //1m, 6f, //ANY

    SPELL_MONK_RESUSCITATE = 461537, //458698, //157202, //10s 40f res //217703

    SPELL_MONK_FORTIFYING_BREW = 120954, //6m 0f
};

enum FSB_MONK_HEALER_SPELLS
{
    SPELL_MONK_VIVIFY = 116670, //2s, 40f, 3% mana
    SPELL_MONK_EXPEL_HARM = 322101, //15s, 0f, 1.4% mana
    SPELL_MONK_SPINNING_CRANE = 101546, //0s, 8f cc, 1% mana

    SPELL_MONK_ENVELOPING_MIST = 124682, //0s, 40f
    SPELL_MONK_LIFE_COCOON = 116849, //2m, 40f
    SPELL_MONK_RENEWING_MIST = 448430, //5s, 40f, 2% mana

    SPELL_MONK_CELESTIAL_CONDUIT = 443028, //90s, 0f, 5% mana
    SPELL_MONK_CELESTIAL_HEAL = 443039, // actual mass heal for celestial conduit
    SPELL_MONK_RESTORAL = 388615, //3m, 0f mass
    SPELL_MONK_REVIVAL = 115310, //3m, 0f, mass
    SPELL_MONK_SHEILUN_GIFT = 399491, //0s, 40f

    SPELL_MONK_RUSHING_WIND_KICK = 467307, //10s, 2f, 2% mana
    SPELL_MONK_INVOKE_CHIJI = 325197, //2m, 40f
    SPELL_MONK_INVOKE_YULON = 322118, //2m, 40f
    SPELL_MONK_SUMMON_SERPENT_STATUE = 115313, //10s, 40f 5% mana

    SPELL_MONK_DETOX_ATTACK = 115450, //8s 40f

    SPELL_MONK_SOOTHING_MIST = 115175 //8s 40f
};

enum FSB_MONK_TANK_SPELLS
{
    SPELL_MONK_PROVOKE = 115546, //8s, 30f

    SPELL_MONK_PARALYSIS = 115078, //45s, 20f, cc

    SPELL_MONK_DETOX_HEAL = 218164, //8s, 40f

    //SPELL_MONK_VIVFY = 116670, //2s, 40f, 30 energy
    //SPELL_MONK_EXPEL_HARM = 322101, //15s, 0f, 15 energy
    //SPELL_MONK_SPINNING_CRANE = 101546, //0s, 8f cc, 40 energy
    SPELL_MONK_TIGER_PALM = 100780, //0s, 2f, 50 energy
    SPELL_MONK_EXPLODING_KEG = 325153, //1m, 40f,
    SPELL_MONK_CHI_BURST = 123986, //30s, 40f
    SPELL_MONK_INVOKE_NIUZAO = 132578, //2m, 40f
    SPELL_MONK_KEG_SMASH = 121253, //8s, 15f
    SPELL_MONK_RUSHING_JADE_WIND = 261715, //6s, 8f cc
    SPELL_MONK_BREATH_FIRE = 115181, //15s, 2f

    SPELL_MONK_CELESTIAL_INFUSION = 1241059, //45s, 0f,
    SPELL_MONK_CELESTIAL_BREW = 322507, //45s, 0f
    SPELL_MONK_BLACK_OX_BREW = 115399, //2m, 0f energy refill
    SPELL_MONK_BLACK_OX_STATUE = 115315, //10s, 0f cc
    SPELL_MONK_PURIFYING_BREW = 119582, //10s, 0f, 8% hp

    SPELL_MONK_SPEAR_HAND_STRIKE = 116705, //15s, 2f interrupt

    SPELL_MONK_DISABLE = 116095, //15 energy
};

enum FSB_MONK_DPS_SPELLS
{
    //Generates CHI
    SPELL_MONK_TIGER_PALM_CHI = 346602, //
    SPELL_MONK_BLACKOUT_KICK_CHI = 205523, //4s, 0f, //ANY

    //SPELL_MONK_SPINNING_CRANE = 101546, //0s, 8f cc, 2 chi
    SPELL_MONK_RUSHING_WIND = 116847, //6s, 8f cc

    SPELL_MONK_RISING_SUN_KICK = 107428, //10s, 2f, 2 chi
    SPELL_MONK_FISTS_FURY = 113656, //24s, 8f, 3 chi
    SPELL_MONK_STRIKE_WINDLORD = 392983, //35s, 9f 2 chi
    SPELL_MONK_SLICING_WINDS_1 = 1217413, //30s 2f, 2 chi
    SPELL_MONK_SLICING_WINDS_2 = 1217409, //follows 1
    SPELL_MONK_SLICING_WINDS_3 = 1217411, //follows 2

    SPELL_MONK_TIGER_LUST = 116841, //30s 20f
    SPELL_MONK_PARALYSIS_CHI = 357768, //45, 20f 1 chi

    SPELL_MONK_SOOTHING_MIST_CHI = 198533, //0s, 40f 1 chi
};

namespace FSBMonk
{
    namespace Creatures
    {
        static constexpr uint32 NPC_JADE_SERPENT_STATUE = 60849;
    }

    void HandleOnSpellCast(Creature* bot, uint32 spellId);
    bool BotOnAuraApplied(Creature* bot, AuraApplication const* aurApp, bool applied, FSBBotStats& botStats);

    bool BotHasFortifyingBrew(Creature* bot);

    bool BotOOCHealOwner(Creature* bot);

    void SetSerpentStatueTarget(Creature* bot, ObjectGuid targetGuid);
}
