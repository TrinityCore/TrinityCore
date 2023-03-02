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

#include "siege_of_orgrimmar.hpp"
#include "GameObjectAI.h"
#include "GossipDef.h"
#include "ScriptedCreature.h"
#include "SceneHelper.h"

enum ScriptedTextJaina
{
    SAY_JAINA_GALAKRAS_INTRO_1 = 0,
    SAY_JAINA_GALAKRAS_INTRO_2 = 1,
    SAY_JAINA_GALAKRAS_INTRO_3 = 2,
    SAY_JAINA_GALAKRAS_INTRO_4 = 3,
    SAY_JAINA_GALAKRAS_SPELL = 4,
};

enum ScriptedTextWrynn
{
    SAY_WRYNN_GALAKRAS_INTRO_1 = 0,
    SAY_WRYNN_GALAKRAS_INTRO_2 = 1,
    SAY_WRYNN_GALAKRAS_INTRO_3 = 2,
    SAY_WRYNN_GALAKRAS_INTRO_4 = 3,
    SAY_WRYNN_GALAKRAS_INTRO_5 = 4,
    SAY_WRYNN_GALAKRAS_INTRO_6 = 5,
    SAY_WRYNN_GALAKRAS_SPELL = 6,
};

enum ScriptedTextLorthemar
{
    SAY_LORTHEMAR_GALAKRAS_INTRO_1 = 0,
    SAY_LORTHEMAR_GALAKRAS_INTRO_2 = 1,
    SAY_LORTHEMAR_GALAKRAS_INTRO_3 = 2,
    SAY_LORTHEMAR_GALAKRAS_INTRO_4 = 3,
    SAY_LORTHEMAR_GALAKRAS_INTRO_5 = 4,
    SAY_LORTHEMAR_GALAKRAS_INTRO_6 = 5,
    SAY_LORTHEMAR_GALAKRAS_INTRO_7 = 6,
    SAY_LORTHEMAR_GALAKRAS_INTRO_8 = 7,
};

enum ScriptedTextSylvanas
{
    SAY_SYLVANAS_GALAKRAS_INTRO_1 = 0,
    SAY_SYLVANAS_GALAKRAS_INTRO_2 = 1,
    SAY_SYLVANAS_GALAKRAS_INTRO_3 = 2,
    SAY_SYLVANAS_GALAKRAS_INTRO_4 = 3,
    SAY_SYLVANAS_GALAKRAS_INTRO_5 = 4,
    SAY_SYLVANAS_GALAKRAS_INTRO_6 = 5,
    SAY_SYLVANAS_GALAKRAS_INTRO_7 = 6,
    SAY_SYLVANAS_GALAKRAS_INTRO_8 = 7,
};

enum ScriptedTextVoljin
{
    SAY_VOLJIN_EVENT_1 = 0,
    SAY_VOLJIN_EVENT_2 = 1,
    SAY_VOLJIN_INTRO_1 = 2,
    SAY_VOLJIN_INTRO_2 = 3,
    SAY_VOLJIN_INTRO_3 = 4,
};

enum ScriptedTextBaine
{
    SAY_BAINE_EVENT_1 = 0,
    SAY_BAINE_INTRO_1 = 1,
    SAY_BAINE_INTRO_2 = 2,
    SAY_BAINE_INTRO_3 = 3,
};

enum ScriptedTextAysa
{
    SAY_AYSA_EVENT_1 = 0,
    SAY_AYSA_EVENT_2 = 1,
    SAY_AYSA_EVENT_3 = 2,
    SAY_AYSA_EVENT_4 = 3,
    SAY_AYSA_EVENT_5 = 4,
    SAY_AYSA_EVENT_6 = 5,
    SAY_AYSA_EVENT_7 = 6,

    SAY_KOMAK_EVENT_1 = 0,
    SAY_KOMAK_EVENT_2 = 1,
    SAY_KOMAK_EVENT_3 = 2,
};

enum Spells
{
    // Dragonmaw Bonecrusher
    SPELL_FRACTURE_AOE = 147201,
    SPELL_FRACTURE_STUN = 147200,
    SPELL_FRACTURE_CHANNEL = 147202,
    SPELL_FRACTURE_DMG = 147203,
    SPELL_SHATTERING_ROAR = 146897,

    // Dragonmaw Tidal Shaman
    SPELL_CHAIN_HEAL = 146728,
    SPELL_HEALING_TIDE_TOTEM = 146722,
    SPELL_HEALING_TIDE_AURA = 146725,
    SPELL_HEALING_TIDE_HEAL = 146726,
    SPELL_TIDAL_WAVE_AOE = 149187,
    SPELL_TIDAL_WAVE_DUMMY = 148519,
    SPELL_TIDAL_WAVE_DMG = 149188,

    // Dragonmaw Elite Grunt
    SPELL_THROW_AXE = 147669,

    // Dragonmaw Flagbearer
    SPELL_DRAGONMAW_FLAGBEARER = 145232,

    // Kor'kron Cannon
    SPELL_SPIKE_MINE_DETONATION = 145752,

    // Blind Blademaster
    SPELL_BLIND_CLEAVE = 141192,
    SPELL_WANDER = 141191,
    SPELL_BLIND_STRIKE = 141189,
    SPELL_CLEAVE_TRIGGER = 141197,
    SPELL_CHARGE = 141193,
    SPELL_CHARGE_AURA = 141202,
    SPELL_CHARGE_AURA_TRIGGER = 141198,
    SPELL_SWIFT_STRIKE = 141199, // while charge
    SPELL_SWIFT_STRIKE_2 = 141190, // while blind strike
};

enum Events
{
    // Dragonmaw Bonecrusher
    EVENT_FRACTURE = 1,
    EVENT_SHATTERING_ROAR,

    // Dragonmaw Tidal Shaman
    EVENT_CHAIN_HEAL,
    EVENT_HEALING_TIDE_TOTEM,
    EVENT_TIDAL_WAVE,

    // Dragonmaw Elite Grunt
    EVENT_THROW_AXE,

    // Blind Blademaster
    EVENT_BLIND_CLEAVE,
    EVENT_SWIFT_STRIKE,
};

enum Adds
{
    // Before Galakras
    NPC_DRAGONMAW_BONECRUSHER = 72354,
    NPC_DRAGONMAW_CANNONEER = 72365,
    NPC_DRAGONMAW_TIDAL_SHAMAN = 72367,
    NPC_HEALING_TIDE_TOTEM = 73086,
    NPC_DRAGONMAW_ELITE_GRUNT = 72350,
    NPC_DRAGONMAW_FLAGBEARER = 72351,
    NPC_KORKRON_CANNON = 72358,
    NPC_SPIKE_MINE = 72656,

    // After Galakras, before Iron Juggernaut
    NPC_DARK_SPEAR_WARRIOR_1 = 73908,
    NPC_DARK_SPEAR_WARRIOR_2 = 73855, // attacks the juggernaut
    NPC_DARK_SPEAR_RECRUIT = 73936, // moving near sentries 1
    NPC_DARK_SPEAR_SENTRY_1 = 73871, // rides
    NPC_DARK_SPEAR_SENTRY_2 = 73874, // don't rides
    NPC_DARK_SPEAR_MARKSMAN = 73900,
    NPC_DARK_SPEAR_BATTLEDRUMMER = 73858,
    NPC_DARK_SPEAR_EMERGENCY_MEDIC = 73850,
    NPC_DARK_SPEAR_ENGINEER = 73860,

    // Before Kor'kron Dark Shaman
    NPC_KORKRON_DARK_SHAMAN = 72451,
    NPC_KORKRON_OVERSEER = 72421,
    NPC_OGRRIMMAR_PEON = 72427,
    NPC_KORKRON_SHADOWMAGE = 72150,
    NPC_KORKRON_GRUNT = 72412,
    NPC_DIRE_WOLF = 72452,
    NPC_KORKRON_PROVISIONER = 72411,
    NPC_TREASURY_GUARD = 72434,
};

enum Actions
{
    ACTION_AYSA_START_INTRO = 1,
    ACTION_AYSA_START_EVENT,
    ACTION_AYSA_KOMAK_DIED,
};

Position galakrasNpcPos2[4] =
{
    { 1360.96f, -5404.39f, 10.32f, 1.75f}, // jaina moves at the ship
    { 1360.96f, -5404.39f, 10.32f, 4.89f}, // jaina's orientation

    { 1431.70f, -4898.23f, 11.34f, 1.75f}, // jaina/lor'themar position after intro
    { 1421.77f, -4901.12f, 11.36f, 1.76f}  // wrynn/sylvanas position after intro
};

Position voljinIronJuggernautPos[3] =
{
    {1234.65f, -4402.92f, 25.94f, 0.08f},
    {1250.27f, -4401.60f, 26.04f, 0.08f},
    {1331.09f, -4382.75f, 26.04f, 0.24f}
};

Position baineBloodHoofIronJuggernautPos[3] =
{
    {1234.53f, -4407.77f, 25.64f, 0.06f},
    {1251.90f, -4406.57f, 26.03f, 0.06f},
    {1337.32f, -4388.00f, 26.13f, 0.22f}
};

Position aysaPos[3] =
{
    { 1485.46f, -4412.06f, 25.35f, 0.05f }, // first position
    { 1493.71f, -4411.01f, 23.93f, 0.08f }, // position after intro
    { 1541.17f, -4404.84f, 18.47f, 0.10f }  // position near Ji
};

void AddSC_siege_of_orgrimmar_part_b()
{
    
}
