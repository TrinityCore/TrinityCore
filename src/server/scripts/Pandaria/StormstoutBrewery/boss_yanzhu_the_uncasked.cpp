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

#include "stormstout_brewery.h"

struct ValuePair
{
    uint32 entry_1;
    uint32 entry_2;
};

static const Position gaoWaypoints[] =
{
    { 0.f, 0.f, 0.f                    },
    { -703.3f, 1187.5f, 166.7f         },
    { -707.4f, 1189.8f, 166.7f         },
    { -709.6f, 1185.0f, 166.7f, 4.905f }
};

static const Position chenWaypoints[] =
{
    { -673.7f, 1155.7f, 166.7f          },
    { 0.f,     0.f,     0.f             }, // empty
    { -708.1f, 1180.2f, 166.7f, 1.832f  }
};

enum Spells
{
    // Boss
    SPELL_BREW_BOLT = 114548,
    SPELL_ROOT = 42716,  // Self root forever, used when Bubble Shield is up.

    // One of two from each category of the following abilities:

    // Brewmastery: Stout.
    SPELL_BLOAT = 106546, // (1).
    SPELL_BLOAT_DUMMY = 114929, // Tooltip says "Can use the Bloat ability."
    SPELL_BLOATED = 106549, // Player aura triggering 106560 Gushing Brew - damage.
    SPELL_BLACKOUT_BREW = 106851, // (2).
    SPELL_BLACKOUT_BREW_DUMMY = 114930, // Tooltip says "Can use the Blackout Brew ability."
    SPELL_BLACKOUT_DRUNK = 106857, // At 10 stacks of SPELL_BLACKOUT_BREW.

    // Bremastery: Ale.
    SPELL_BUBBLE_SHIELD = 106563, // (1).
    SPELL_BUBBLE_SHIELD_DUMMY = 114931, // Tooltip says "Can use the Bubble Shield ability."
    // Summons multiple NPC_YEASTY_BREW_ALEMENTAL_Y (2).
    SPELL_YEASTY_BREW_DUMMY = 114932, // Tooltip says "Can summon Yeasty Brew minions."

    // Bremastery: Wheat.
    SPELL_CARBONATION = 115003, // Triggers 114386 damage (1).
    SPELL_CARBONATION_DAMAGE = 114386, // Triggered by above.
    SPELL_CARBONATION_DUMMY = 114934, // Tooltip says "Can use the Carbonation ability."
    // Summons multiple NPC_FIZZY_BUBBLE (if uses Carbonation).
    SPELL_FIZZY_BUBBLE_VISUAL = 114458, // Dummy visual for NPC.
    SPELL_FIZZY_BUBBLE = 114459, // Player fly aura on spellclick.
    // Summons multiple NPC_WALL_OF_SUDS (if uses Wall of Suds) (2).
    SPELL_SUDSY = 114468, // If uses Wall of Suds. Triggers 114470 multiple Jump height at Jumping. Player aura.
    SPELL_SUDSY_JUMP = 114470, // Triggered by above.
    SPELL_WALL_OF_SUDS_DUMMY = 114933, // Tooltip says "Can summon walls of suds."

    // NPCs
    SPELL_YEASTY_BREW_BOLT = 116155, // Yeasty Brew Alementals can cast a less powerful version of Brew Bolt, inflicting 9750 to 10250 Frost damage.
    SPELL_YEASTY_SUMMON_VIS = 116259, // Yeasty Brew Alemental spawn visual.
    SPELL_FERMENT = 106859, // Channeled beam, triggers 114451 - 1% Hp / Mana restore on target.
    SPELL_FERMENT_HEAL = 114451, // Heal.
    SPELL_WALL_OF_SUDS = 114467, // Triggers 114466 damage and stun.
    SPELL_WALL_OF_SUDS_DAMAGE = 114466, // Triggered by above.

    // Boss intro (Uncle Gao).
    SPELL_BREW_FINALE_DARK = 128257, // First wave of spawns, Bloated / Stout Alementals. From Left cauldron (first).
    SPELL_DARK_SPAWN_EFF = 128244, // Visual for first wave spawn.
    SPELL_BREW_FINALE_MED = 128255, // Second wave of spawns, Yeasty / Bubbling Alementals. From Middle cauldron.
    SPELL_MED_SPAWN_EFF = 128243, // Visual for second wave spawn.
    SPELL_BREW_FINALE_WHEAT = 128253, // Third wave of spawns, Fizzy / Sudsy Alementals. From Right cauldron (last).
    SPELL_WHEAT_SPAWN_EFF = 128242  // Visual for third wave spawn.
};

static const Position largeBrewPos[] =
{
    { -702.09f, 1158.76f, 166.22f, 0.24f },
    { -704.20f, 1166.94f, 166.22f, 0.24f }
};

static const Position smallBrewPos[] =
{
    { -709.23f, 1152.57f, 166.22f, 0.17f },
    { -711.52f, 1160.55f, 166.22f, 0.17f },
    { -713.58f, 1168.67f, 166.22f, 0.17f },
    { -701.03f, 1154.85f, 166.22f, 0.17f },
    { -703.38f, 1162.76f, 166.22f, 0.17f },
    { -705.75f, 1170.97f, 166.22f, 0.17f },
    { -693.20f, 1157.04f, 166.22f, 0.17f },
    { -695.33f, 1165.07f, 166.22f, 0.17f },
    { -697.44f, 1173.05f, 166.22f, 0.17f },
};

static const Position middleBrewPos[] =
{
    { -700.52f, 1167.84f, 166.22f, 0.25f },
    { -698.25f, 1159.97f, 166.22f, 0.25f },
    { -708.61f, 1165.69f, 166.22f, 0.25f },
    { -706.43f, 1157.70f, 166.22f, 0.25f },
};

static const Position yanzhuPos[] = { -703.44f, 1162.43f, 166.22f, 0.24f };
static const Position gaoPotPos[] = { -676.96f, 1193.96f, 166.79f, 1.82f };

static const Position sudsPos[2] =
{
    { -696.25f, 1138.78f, 166.75f, 1.82f },
    { -663.20f, 1172.84f, 166.74f, 3.38f }
};

const uint32 brewSpells[3] =
{
    128253,
    128255,
    128257,
};

void AddSC_boss_yanzhu()
{
    
}