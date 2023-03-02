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

#include "throne_of_thunder.h"
#include "GridNotifiers.h"
#include "Vehicle.h"
#include "GameObjectAI.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum eSpells
{
    //===============================================
    // Horridon

    // Triple Puncture
    SPELL_TRIPLE_PUNCTURE = 136767, // Casted on Main Tank

    // Double Swipe
    SPELL_DOUBLE_SWIPE = 136741, // Launch everything
    SPELL_DOUBLE_SWIPE_FRONT = 136740, // Frontal damages
    SPELL_DOUBLE_SWIPE_BACK = 136739, // Back damages

    // Charge
    SPELL_CHARGE = 136769,

    // Dire Call
    SPELL_DIRE_CALL = 137458, // Launch everything
    SPELL_SUMMON_DIREHORN_SPIRIT_SELECTOR = 140947,
    SPELL_SUMMON_DIREHORN_SPIRIT = 140945,

    // After a charge at a door
    SPELL_HEADACHE = 137294,
    SPELL_CRACKED_SHELL = 137240,

    // Enrage
    SPELL_RAMPAGE = 136821,

    //===============================================
    // Farraki
    SPELL_STONE_GAZE = 136708, // Stonegazer
    SPELL_BLAZING_SUNLIGHT = 136719, // Wastewalker
    SPELL_SUMMON_SAND_TRAP = 136725, // Wastewalker

    //===============================================
    // Gurubashi
    SPELL_RENDING_CHARGE = 136653, // Bloodlord
    SPELL_RENDING_CHARGE_DAMAGES = 136654, // Bloodlord 
    SPELL_VENOM_BOLT_VOLLEY = 136587, // Venom Priest
    SPELL_SUMMON_VENOMOUS_EFFUSION = 136644, // Venom Priest

    //===============================================
    // Drakkari
    SPELL_UNCONTROLLED_ABOMINATION = 136709, // Risen Drakkari Champion / Warrior
    SPELL_DEADLY_PLAGUE = 136710, // Risen Drakkari Champion / Warrior 
    SPELL_MORTAL_STRIKE = 136670, // Frozen Warlord
    SPELL_SUMMON_FROZEN_ORB = 136564, // Frozen Warlord

    //===============================================
    // Amani
    SPELL_FIREBALL = 136465, // Flame Caster
    SPELL_SWIPE = 136463, // Warbear
    SPELL_CHAIN_LIGHTNING = 136480, // Beast Shaman
    SPELL_HEX_OF_CONFUSION = 136512, // 
    SPELL_SUMMON_LIGHTNING_NOVA_TOTEM = 136487, // 

    //===============================================
    // Zandalari
    SPELL_DINO_MENDING = 136797, // Dinomancer
    SPELL_DINO_FORM = 137237, // 
    SPELL_SUMMON_ORB_OF_CONTROL_FARRAKI = 137445, // 
    SPELL_SUMMON_ORB_OF_CONTROL_GURUBASHI = 137447, // 
    SPELL_SUMMON_ORB_OF_CONTROL_DRAKKARI = 137448, // 
    SPELL_SUMMON_ORB_OF_CONTROL_AMANI = 137449, // 

    //===============================================
    // Summons
    SPELL_DIRE_FIXATION = 140946, // Dire Horn Spirit
    SPELL_WEAK_LINK = 140948, // Dire Horn Spirit
    SPELL_SAND_TRAP_PERIODIC = 136724,
    SPELL_SAND_TRAP = 136723, // SpellScript needed (radius)
    SPELL_SUMMON_LIVING_POISON = 136644, // Three times ?
    SPELL_LIVING_POISON_PERIODIC = 136645,
    SPELL_LIVING_POISON = 136646,
    SPELL_FROZEN_BOLT_PERIODIC = 136572,
    SPELL_FROZEN_BOLT = 136573, // Frozen Orb
    SPELL_LIGHTNING_NOVA_PERIODIC = 136489, // Lightning Nova Totem
    SPELL_LIGHTNING_NOVA = 136490,

    //===============================================
    // Jalak
    SPELL_BESTIAL_CRY = 136817,

    //===============================================
    // Orb of Control
    SPELL_CONTROL_HORRIDON_FARRAKI = 137433,
    SPELL_CONTROL_HORRIDON_GURUBASHI = 137442,
    SPELL_CONTROL_HORRIDON_DRAKKARI = 137443,
    SPELL_CONTROL_HORRIDON_AMANI = 137444,
};

enum eEvents
{
    //===============================================
    // Horridon
    EVENT_TRIPLE_PUNCTURE = 1,
    EVENT_DOUBLE_SWIPE = 2,
    EVENT_HORRIDON_CHARGE = 3, // 
    EVENT_DIRE_CALL = 4,
    EVENT_PREPARE_CHARGE = 5, // Pseudo hack
    EVENT_CHARGE_AT_DOOR = 6,
    EVENT_BERSERK = 34,
    EVENT_EVADE_CHECK = 35,

    //===============================================
    // Farraki
    EVENT_STONE_GAZE = 7,
    EVENT_BLAZING_LIGHT = 8,
    EVENT_SUMMON_SAND_TRAP = 9,

    //===============================================
    // Gurubashi
    EVENT_RENDING_CHARGE = 10,
    EVENT_GURUBASHI_VENOM_BOLT_VOLLEY = 11,
    EVENT_SUMMON_VENOMOUS_EFFUSION = 12,

    //===============================================
    // Drakkari
    EVENT_SWITCH_TARGET = 13, // Risen Drakkari doesn't have a real threat list
    EVENT_MORTAL_STRIKE = 14,
    EVENT_SUMMON_FROZEN_ORB = 15,

    //===============================================
    // Amani
    EVENT_FIREBALL = 16,
    EVENT_SWIPE = 17,
    EVENT_CHAIN_LIGHTNING = 18,
    EVENT_HEX_OF_CONFUSION = 19,
    EVENT_SUMMON_LIGHTNING_NOVA_TOTEM = 20,

    //===============================================
    // Zandalari
    EVENT_DINO_MENDING = 21,

    //===============================================
    // Summons
    EVENT_EFFUSION_VENOM_BOLT_VOLLEY = 22,

    //===============================================
    // Jalak
    EVENT_BESTIAL_CRY = 23,

    //===============================================
    // Helper
    EVENT_SUMMON_MINOR = 24, // 
    EVENT_SUMMON_MAJOR = 25, // 
    EVENT_SUMMON_ZANDALARI_DINOMANCER = 26, // 
    EVENT_SUMMON_MINOR_DRAKKARI = 27, // 
    EVENT_TRANSITION = 28, // 

    //===============================================
    // RP Event Helper
    EVENT_CHECK_PLAYERS = 29, // Every 500 ms to not flood the world
    EVENT_INTRO_PART_I = 30, // Jalak begins it's speech... 
    EVENT_INTRO_PART_II = 31, // Continues
    EVENT_INTRO_PART_III = 32, // Horridon breaks free and go and kill every... oh wait... that's not the time
    EVENT_INTRO_PART_IV = 33, // Now Horridon breaks free 

    //===============================================
    // Direhorn
    EVENT_TARGET_A_RANDOM_PLAYER,
    EVENT_DAMAGE_IF_NEARBY,
    EVENT_RETURN_TO_COMBAT,
    EVENT_CALL_JALAK,
    EVENT_DOUBLE_SWIPE_ACTION,
};

enum eCreatures
{
    //===============================================
    // Farraki
    MOB_SUL_LITHUZ_STONEGAZER = 69172,
    MOB_FARRAKI_SKIRMISHER = 69173,
    MOB_FARRAKI_WASTEWALKER = 69175, // Total of three will be called to action

    //===============================================
    // Gurubashi
    MOB_GURUBASHI_BLOODLORD = 69167,
    MOB_GURUBASHI_VENOM_PRIEST = 69164, // Total of three will be called to action

    //===============================================
    // Drakkari
    MOB_RISEN_DRAKKARI_WARRIOR = 69184,
    MOB_RISEN_DRAKKARI_CHAMPION = 69185,
    MOB_DRAKKARI_FROZEN_WARLORD = 69178, // Total of three will be called to action

    //===============================================
    // Amani
    MOB_AMANI_SHI_PROTECTOR = 69169,
    MOB_AMANI_SHI_FLAME_CASTER = 69168,
    MOB_AMANI_WARBEAR = 69177, // Total of three will be called to action
    MOB_AMANI_SHI_BEAST_SHAMAN = 69176, // Riding Amani Warbears, attackable once Amani Warbear has fallen

    //===============================================
    // Zandalari
    MOB_ZANDALARI_DINOMANCER = 69221, // Jumping periodically during subphases

    //===============================================
    // Summons
    MOB_DIREHORN_SPIRIT = 70688, // Only spawn in Heroic
    MOB_SAND_TRAP = 69346, // Summoned by Farraki Wastewalker
    MOB_VENOMOUS_EFFUSION = 69314, // Summoned by Gurubashi Venom Priests
    MOB_LIVING_POISON = 69313, // Created when a Venomous Effusion is created
    MOB_FROZEN_ORB = 69268, // Summoned by Drakkari Frozen Warlords
    MOB_LIGHTNING_NOVA_TOTEM = 69215, // Summoned by Amani'Shi Beast Shaman

    //===============================================
    // Others
};

enum eActions
{
    //===============================================
    // Controller
    ACTION_FIGHT_BEGIN = 0,
    ACTION_FIGHT_RESET = 1,
    ACTION_ENTER_NEXT_TRASH_PHASE = 2,
    ACTION_FIGHT_END = 3,
    ACTION_PREPARE_TRANSITION = 4,
    ACTION_RESET_AFTER_CRASH = 10,

    //===============================================
    // Jalak
    ACTION_ENTER_PHASE_TWO = 5,

    //===============================================
    // Horridon
    ACTION_INTRO = 6,
    ACTION_PREPARE_CHARGE = 7,
    ACTION_CONTROL_APPLY = 8,

    //===============================================
    //Living Poison
    ACTION_LIVING_POISON_DESPAWN = 9,
    ACTION_DOUBLE_SWIPE = 12,
    ACTION_FORCE_RESET = 13,
};


enum eMotions
{
    //===============================================
    // Majors
    MOTION_MAJOR_JUMP = 6845,

    //===============================================
    // Zandalari Dinomancers
    MOTION_DINOMANCER_JUMP = 7849,

    //===============================================
    // Horridon
    MOTION_HORRIDON_CHARGE = 4551,
    MOTION_HORRIDON_DOOR_CHARGE = 3205,

};


enum eTalks : uint32
{
    TALK_INTRO_FIRST = 0, // Welcome weaklings
    TALK_INTRO_SECOND = 1, // The tribes have assembled
    TALK_INTRO_THIRD = 2, // Now, witness the true might
    TALK_ENTER_PHASE_2 = 3, // Hahaha, now it be my turn
    TALK_DRAKKARI = 4, // Drakkari tribe
    TALK_GURUBASHI = 5,
    TALK_FARRAKI = 6,
    TALK_AMANI = 7,
    TALK_ON_JALAK_KILLED_UNIT = 8, // Ya skull
    TALK_ON_HORRIDON_KILLED_UNIT = 9, // Da'kala koraste

    EMOTE_FARRAKI = 0,
    EMOTE_GURUBASHI = 1,
    EMOTE_DRAKKARI = 2,
    EMOTE_AMANI = 3,
    EMOTE_CHARGE = 4,
    EMOTE_FARAKKI_DOOR = 5,
    EMOTE_GURUBASHI_DOOR = 6,
    EMOTE_DRAKKARI_DOOR = 7,
    EMOTE_AMANI_DOOR = 8,
};

enum eGameObjects
{
    //===============================================
    // Orbs of Control
    GOB_ORB_OF_CONTROL_FARRAKI = 218193,
    GOB_ORB_OF_CONTROL_GURUBASHI = 218374,
    GOB_ORB_OF_CONTROL_DRAKKARI = 218375,
    GOB_ORB_OF_CONTROL_AMANI = 218376,

    //===============================================
    // Others
    GOB_HORRIDON_PRISON_DOOR = 218674,
};

enum eDatas : uint32
{
    DATA_AMANI_BEAST_SHAMAN_LIGHTNING_COUNT = 0, // To know how many time we stroke
};


enum eBossPhases : uint32
{
    BOSS_PHASE_SUMMONS = 0,
    BOSS_PHASE_JALAK = 1
};
#define MAX_BOSS_PHASE BOSS_PHASE_JALAK + 1

enum eTrashPhases : uint32
{
    TRASH_PHASE_FARRAKI = 0,
    TRASH_PHASE_GURUBASHI = 1,
    TRASH_PHASE_DRAKKARI = 2,
    TRASH_PHASE_AMANI = 3,

    MAX_TRASH_PHASE = TRASH_PHASE_AMANI + 1,
};


enum eMajorsCycle
{
    MAJOR_CYCLE_FIRST = 0,
    MAJOR_CYCLE_SECOND = 1,

    MAX_MAJOR_CYCLE = 2,
};


enum eDrakkariCycle
{
    DRAKKARI_CYCLE_FIRST = 0,
    DRAKKARI_CYCLE_SECOND = 1,

    MAX_DRAKKARI_CYCLE = 2,
};

//=========================================================
// Positions

#define MAX_SUMMON_POSITIONS_BY_PHASE   3
#define MAX_JUMP_POSITIONS_BY_PHASE     3

// Major trashes jump positions
static const Position farrakiWastewalkerJumpPositions[MAX_JUMP_POSITIONS_BY_PHASE] =
{
    { 5467.25f, 5816.40f, 129.9f, 4.08f },
    { 5483.03f, 5790.85f, 129.9f, 3.16f },
    { 5468.46f, 5797.77f, 129.9f, 3.94f },
};

static const Position gurubashiVenomPriestJumpPositions[MAX_JUMP_POSITIONS_BY_PHASE] =
{
    { 5501.31f, 5709.33f, 129.9f, 2.12f },
    { 5474.69f, 5712.25f, 129.9f, 2.58f },
    { 5459.25f, 5694.25f, 129.9f, 1.09f },
};

static const Position drakkariFrozenWarlordJumpPositions[MAX_JUMP_POSITIONS_BY_PHASE] =
{
    { 5400.35f, 5693.92f, 129.9f, 0.72f },
    { 5392.05f, 5711.79f, 129.9f, 0.91f },
    { 5371.40f, 5728.19f, 129.9f, 0.60f },
};

static const Position amaniWarbearJumpPositions[MAX_JUMP_POSITIONS_BY_PHASE] =
{
    { 5363.80f, 5787.88f, 129.90f, 5.38f },
    { 5385.03f, 5793.05f, 129.90f, 5.62f },
    { 5397.14f, 5811.65f, 129.90f, 5.16f },
};


// Summoning of minor and medium trashes positions
static const Position farrakiTrashSummonPositions[MAX_SUMMON_POSITIONS_BY_PHASE] =
{
    { 5505.863281f, 5841.025391f, 130.537231f, 0.000000f },
    { 5514.541992f, 5841.049316f, 130.537231f, 0.000000f },
    { 5513.420898f, 5827.835938f, 130.537231f, 0.000000f },
};

static const Position gurubashiTrashSummonPositions[MAX_SUMMON_POSITIONS_BY_PHASE] =
{
    { 5520.958008f, 5675.670898f, 130.537231f, 0.000000f },
    { 5519.500000f, 5667.600098f, 130.537231f, 0.000000f },
    { 5509.516113f, 5668.375000f, 130.537231f, 0.000000f },
};

static const Position drakkariTrashSummonPositions[MAX_SUMMON_POSITIONS_BY_PHASE] =
{
    { 5358.775391f, 5662.011719f, 130.537231f, 0.000000f },
    { 5346.132324f, 5668.255859f, 130.537231f, 0.000000f },
    { 5346.598633f, 5677.144043f, 130.537231f, 0.000000f },
};

static const Position amaniTrashSummonPositions[MAX_SUMMON_POSITIONS_BY_PHASE] =
{
    { 5346.283203f, 5824.987305f, 130.537231f, 0.000000f },
    { 5348.529785f, 5839.762207f, 130.537231f, 0.000000f },
    { 5360.542969f, 5844.966309f, 130.537231f, 0.000000f },
};


// Jump positions for Zandalari Dinomancers
static const Position zandalariDinomancersJumpPositions[MAX_TRASH_PHASE][MAX_JUMP_POSITIONS_BY_PHASE] =
{
    {
        { 5467.25f, 5816.40f, 129.9f, 4.08f },
        { 5483.03f, 5790.85f, 129.9f, 3.16f },
        { 5468.46f, 5797.77f, 129.9f, 3.94f },
    },
    {
        { 5501.31f, 5709.33f, 129.9f, 2.12f },
        { 5474.69f, 5712.25f, 129.9f, 2.58f },
        { 5459.25f, 5694.25f, 129.9f, 1.09f },
    },
    {
        { 5400.35f, 5693.92f, 129.9f, 0.72f },
        { 5392.05f, 5711.79f, 129.9f, 0.91f },
        { 5371.40f, 5728.19f, 129.9f, 0.60f },
    },
    {
        { 5363.80f, 5787.88f, 129.90f, 5.38f },
        { 5385.03f, 5793.05f, 129.90f, 5.62f },
        { 5397.14f, 5811.65f, 129.90f, 5.16f },
    }
};

// Summoning positions for Zandalari Dinomancers
static const Position zandalariDinomancersSummonPositions[] =
{
    { 5326.83f, 5787.72f, 169.237f, 6.10253f },
    { 5536.14f, 5721.06f, 169.238f, 2.95279f },
    { 5325.51f, 5720.81f, 169.237f, 0.32948f },
    { 5418.50f, 5666.55f, 192.349f, 1.45472f },
    { 5447.01f, 5667.53f, 192.352f, 1.64919f },
    { 5340.08f, 5648.40f, 190.758f, 0.87616f },
    { 5521.05f, 5649.76f, 190.653f, 2.39193f },
    { 5537.03f, 5784.27f, 169.238f, 3.67703f },
    { 5534.14f, 5838.86f, 190.416f, 3.98585f },
    { 5377.32f, 5884.95f, 190.356f, 5.23621f },
};

// Relocation of Horridon's Home Position
static const Position middlePosition = { 5431.621094f, 5763.865723f, 129.606461f, 1.57860f };

static uint32 GetNewEmoteBySpell(uint32 spellId)
{
    switch (spellId)
    {
    case SPELL_CONTROL_HORRIDON_FARRAKI:
        return EMOTE_FARAKKI_DOOR;
    case SPELL_CONTROL_HORRIDON_GURUBASHI:
        return EMOTE_GURUBASHI_DOOR;
    case SPELL_CONTROL_HORRIDON_DRAKKARI:
        return EMOTE_DRAKKARI_DOOR;
    case SPELL_CONTROL_HORRIDON_AMANI:
        return EMOTE_AMANI_DOOR;
    }
    return 0;
}

static uint32 GetSummoningOrbSpellByPhase(uint32 phase)
{
    switch (phase)
    {
    case TRASH_PHASE_FARRAKI:
        return SPELL_SUMMON_ORB_OF_CONTROL_FARRAKI;

    case TRASH_PHASE_GURUBASHI:
        return SPELL_SUMMON_ORB_OF_CONTROL_GURUBASHI;

    case TRASH_PHASE_DRAKKARI:
        return SPELL_SUMMON_ORB_OF_CONTROL_DRAKKARI;

    case TRASH_PHASE_AMANI:
        return SPELL_SUMMON_ORB_OF_CONTROL_AMANI;

    default:
        return 0;
    }
}

static uint32 GetControlSpellByOrb(GameObject* pOrb)
{
    switch (pOrb->GetEntry())
    {
    case GOB_ORB_OF_CONTROL_FARRAKI:
        return SPELL_CONTROL_HORRIDON_FARRAKI;

    case GOB_ORB_OF_CONTROL_GURUBASHI:
        return SPELL_CONTROL_HORRIDON_GURUBASHI;

    case GOB_ORB_OF_CONTROL_DRAKKARI:
        return SPELL_CONTROL_HORRIDON_DRAKKARI;

    case GOB_ORB_OF_CONTROL_AMANI:
        return SPELL_CONTROL_HORRIDON_AMANI;

    default:
        return 0;
    }
}

static uint32 GetControlSpellByPhase(eTrashPhases ePhase)
{
    switch (ePhase)
    {
    case TRASH_PHASE_FARRAKI:
        return SPELL_CONTROL_HORRIDON_FARRAKI;

    case TRASH_PHASE_GURUBASHI:
        return SPELL_CONTROL_HORRIDON_GURUBASHI;

    case TRASH_PHASE_DRAKKARI:
        return SPELL_CONTROL_HORRIDON_DRAKKARI;

    case TRASH_PHASE_AMANI:
        return SPELL_CONTROL_HORRIDON_AMANI;

    default:
        return 0;
    }
}

static Position GetChargePositionByDoor(GameObject* pDoor)
{
    switch (pDoor->GetEntry())
    {
    case GOB_TRIBAL_DOOR_FARRAKI:
        return { 5502.53f, 5826.19f, 130.53f, 0.82f };

    case GOB_TRIBAL_DOOR_GURUBASHI:
        return { 5501.19f, 5865.15f, 130.53f, 5.39f };

    case GOB_TRIBAL_DOOR_DRAKKARI:
        return { 5361.72f, 5863.75f, 130.53f, 3.89f };

    case GOB_TRIBAL_DOOR_AMANI:
        return { 5363.09f, 5823.77f, 130.53f, 2.35f };

    default:
        return { 0.0f, 0.0f, 0.0f, 0.0f };
    }
}

void AddSC_boss_horridon()
{
   
}
