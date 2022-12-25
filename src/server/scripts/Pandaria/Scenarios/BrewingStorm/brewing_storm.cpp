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

#include "GameObjectAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "GridNotifiers.h"
#include "brewing_storm.h"

enum Spells
{
    SPELL_BLANSHES_BOOMER_BREW_POWER_BAR = 112038,
    SPELL_LIGHTNING_IMPACT = 111544, // triggered by lightning channel
    SPELL_ON_FIRE = 111995, // impale kegs
    SPELL_BREW = 112040, // cosmetic brew bubbles...
    SPELL_LIGHTNING_CHANNEL = 111828,
    SPELL_EXTINGUISHING = 111961,
    SPELL_BLANCHES_ELIXIR_OF_REPLENISHMENT = 114663,
    SPELL_HONORARY_BREWMASTER_KEG = 136288,
    SPELL_BOOMER_BREW_STRIKE_BUTTON = 115101, // at 3td chapter
    SPELL_BOOMER_BREW_STRIKE = 115058,
    SPELL_VILETONGUE_STING = 127280,
    SPELL_LEAPING_CLEAVE = 132247,
    SPELL_TORCH_TOSS = 141771,
    SPELL_WIND_SLASH = 131594,
    SPELL_WIND_SLASH_AUR = 131596,
    SPELL_SWAMP_SMASH = 115013,
    SPELL_EARTH_SHATTERING = 122142,
    SPELL_BLANCHES_ELEXIR_EFF = 121951,
    SPELL_PERFECT_POUR_ACHIEV = 114876,
    SPELL_PARTY_OF_SIX_ACHIEV = 127411,
};

enum Events
{
    EVENT_PREPARE_TO_STORM = 1,
    EVENT_LIGHTNING_ROD,
    EVENT_VILETONGUE_SAUROKS,
    EVENT_CHAPTER_2_PREPARE,
    EVENT_ESCORT,
    EVENT_TORCH_TOSS,
    EVENT_BLANCHE_POTION,
    EVENT_BREATHING,
    EVENT_TOSS,
    EVENT_WIND_SLASH,
    EVENT_SWAMP_SMASH,
    EVENT_EARTH_SHATTERING,
};

enum Yells
{
    TALK_INTRO,
    TALK_KEGS,
    TALK_LIGHTNING_STRIKE,
    TALK_SAUROKS,
    TALK_STORM,
    TALK_POTION_ANN,
    TALK_LIGHTNING_HIT_PLAYER,
    TALK_CHAPTER_2_PREPARE,
    TALK_CHAPTER_2_OUTRO,
    TALK_CHAPTER_2_BEGUN,
    TALK_SAUROKS_AT_HIGH_CLIFF,
    TALK_PLAYER_LOW,
    TALK_AT_CLIFF,
    TALK_AT_WALL_CLIFF,
    TALK_JOKE,
    TALK_BREATHING,
    TALK_READY_TO_MOVE,
    TALK_CHAPTER_THREE_INTRO,
    TALK_CHAPTER_THREE_BEGIN,
    TALK_BOOMERS_BREW_ANN,
    TALK_BOROKHALA_INTRO,
    TALK_BOROKHALA_LOW,
    TALK_SCENARIO_END,
};

void AddSC_brewing_storm_scenario()
{
    
}
