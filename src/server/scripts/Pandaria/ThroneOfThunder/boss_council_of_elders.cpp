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
#include <array>
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum eCreatures
{
    MOB_LIVING_SAND = 69153, // Summoned when Sandstorm hits a Quicksand
    MOB_BLESSED_LOA_SPIRIT = 69480, // Summoned by Mar'li, heals a councillor
    MOB_SHADOWED_LOA_SPIRIT = 69548, // Summoned by Mar'li, kills player
    MOB_TWISTED_FATE_FIRST = 69740, // First Twisted Fate npc to be summoned, will move toward the second and vice-versa
    MOB_TWISTED_FATE_SECOND = 69746, // Second Twisted Fate npc to be summoned
};

enum eSpells
{
    //===============================================
    // Gara'Jal's Soul
    SPELL_LINGERING_PRESENCE = 136467, // When the spirit of Gara'jal leaves a councillor
    SPELL_POSSESSED = 136442, // When the spirit of Gara'jal merges with a councillor (periodic dummy ? Dark Energy maybe)
    SPELL_DARK_POWER = 136507, // Damages increase with each cast

    // Soul Fragment
    SPELL_SOUL_FRAGMENT_SELECTOR = 137645, // Trigger 137641 (AREA_ENTRY ?)
    SPELL_SOUL_FRAGMENT_PERIODIC = 137641, // Override spells with 137643
    SPELL_SOUL_FRAGMENT_SWITCHER = 137643, // Trigger 137641
    SPELL_SOUL_FRAGMENT_DUMMY = 137670, // Maybe visual
    SPELL_SHADOWED_SOUL = 137650, // Each time 137641 ticks

    //===============================================
    // Frost King Malakk

    // Frigid Assault
    SPELL_FRIGID_ASSAULT = 136904, // Apply trigger auras
    SPELL_FRIGID_ASSAULT_STACK = 136903, // Stun owner when stacks reach 15
    SPELL_FRIGID_ASSAULT_DAMAGES = 136911, // Damages
    SPELL_FRIGID_ASSAULT_STUN = 136910, // When 136903 reaches 15 stacks

    // Biting Cold <=> Frostbite
    SPELL_BITING_COLD = 136917, // Main damages (select random target, need AuraScript or SpellScript) ( caster must take this damage as INTIAL , on apply ) 
    SPELL_BITING_COLD_PERIODIC_DAMAGES = 136992, // Periodically trigger 136991 ( caster is immune to this )
    SPELL_BITING_COLD_ALLY_DAMAGES = 136991, // Periodic damages to allies
    SPELL_BITING_COLD_PERIODIC_DUMMY = 137579, // Periodic trigger 137580
    SPELL_BITING_COLD_DUMMY = 137580, // Visual maybe ?
    // When Malakk has the possessed aura, Biting Cold turns into Frostbite
    SPELL_FROSTBITE = 136990, // Main damages (works like Biting Cold)
    SPELL_FROSTBITE_PERIODIC_DAMAGES = 136922, // Periodic trigger damages to ally (amount must be multiplied to fit stack amount)
    SPELL_FROSTBITE_ALLY_DAMAGES = 136937, // Damages to allies
    SPELL_FROSTBITE_SCREEN_EFFECT = 136926, // Screen effect
    SPELL_FROSTBITE_DUMMY_AURA = 137575, // Before Frostbite is applied, a blue arrow should appear 
    SPELL_FROSTBITE_VISUAL = 136936,
    // Is there something that can stack ?
    // Bodyheat triggers when Frostbite hits an ally in Heroic
    SPELL_BODY_HEAT = 137084, // Triggers 137085 on expire (AuraScript)
    SPELL_CHILLED_TO_THE_BONE = 137085, // Prevents player from reducing Frostbite amount of nearby players (or only caster ?)

    //===============================================
    // Kazra'jin

    // Reckless Charge
    // SPELL_RECKLESS_CHARGE                   = 137117, // Visual on the boss while travelling (launch everything) ("They see me rollin ! FUCK YEAH !")
    SPELL_RECKLESS_CHARGE_GROUND_AT = 138026, // Visual on the ground while boss is travelling (damage dealer ?)
    SPELL_RECKLESS_CHARGE_SHATTER_GROUND = 137122, // Final damages + Knock back and visual of rocks appearing around
    SPELL_RECKLESS_CHARGE_UNIQUE_DAMAGES = 137133, // Damage on unique target (AT ? Kazra'jin ?)
    SPELL_RECKLESS_CHARGE_PRE_PATH = 000000, // TBF: Visual of dark pools on ground before charge

    SPELL_RECKLESS_CHARGE = 137107,
    SPELL_RECKLESS_CHARGE_VISUAL = 137117,
    SPELL_RECKLESS_CHARGE_FACE = 137121, // Forces facing towards target
    SPELL_RECKLESS_CHARGE_SOUND = 137131,

    // Need black visual on ground before cast

    // Overload
    // When Kazra'jin is empowered, he overloads after performing a Reckless Charge
    SPELL_OVERLOAD = 137149, // Dummy aura to handle the strike back (HandleDummyAuraProc ?) (must add UNIT_STATE_STUN manually)
    SPELL_OVERLOAD_DAMAGES = 137151, // Damage spell
    SPELL_OVERLOAD_VISUAL = 137163, // Visual on caster of spell that triggered mirror effect
    // In Heroic, Overload turns into Discharge
    SPELL_DISCHARGE = 137166, // Periodic dummy ? Why ? (must add UNIT_STATE_STUN manually)
    SPELL_DISCHARGE_DAMAGES = 136935, // Damage spell
    SPELL_DISCHARGE_VISUAL = 137172, // Visual on all players when spell ticks

    //===============================================
    // Sul the Sandcrawler

    SPELL_SAND_BOLT = 136189, // Trigger Missile 136190
    SPELL_SAND_BOLT_DAMAGES = 136190, // Damages

    // Quicksand (fuckin AT)
    // Quicksand is an AT, but handling the spell with an AT is too complex... we'll use another mechanism,
    SPELL_QUICKSAND_PERIODIC_DAMAGES = 136860, // Periodic damages to any target within 7 yards : we must handle apply / remove manually
    SPELL_QUICKSAND_AT_VISUAL = 137572, // Visual
    SPELL_QUICKSAND_AT_VISUAL_INIT = 136851,
    SPELL_ENSNARED = 136878, // Slow player and stacks; when it reaches 5 stacks, player is Entrapped
    SPELL_ENTRAPPED = 136857, // Need to prevent second effect... so annoying

    // Sandstorm
    SPELL_SAND_STORM = 136894, // Periodic trigger 136899,
    SPELL_SAND_STORM_DAMAGES = 136899, // Damages
    SPELL_SAND_STORM_DUMMY_AURA = 136895, // Maybe visual since it has the same duration as 136894

    //===============================================
    // High Priestess Mar'li

    // Wrath of the Loa
    SPELL_WRATH_OF_THE_LOA = 137344,
    SPELL_WRATH_OF_THE_LOA_DARK = 137347, // When Possessed

    // Loa Spirit <=> Twisted Fate
    SPELL_BLESSED_LOA_SPIRIT = 137203, // Handle dummy cause Blizzard messed that up
    SPELL_SUMMON_BLESSED_LOA_SPIRIT = 137200, // Summons 69480
    SPELL_SHADOWED_LOA_SPIRIT = 137350, // Handle dummy cause Blizzard messed that up (Possessed version of Loa Spirit)
    SPELL_SUMMON_SHADOWED_LOA_SPIRIT = 137351, // Summons 69548
    // In Heroic, Shadowed Loa Spirit is replaced with Twisted Fate
    SPELL_TWISTED_FATE_PERIODIC = 137986, // Periodic trigger 137972,
    SPELL_TWISTED_FATE_DAMAGES = 137972, // Periodic damages while linked AND while not linked (must update value in handler of 137986)
    SPELL_TWISTED_FATE_DUMMY_AURA = 137967, // Visual maybe ?
    // First npc of Twisted Fate
    SPELL_TWISTED_FATE = 137891, // Launch everything (triggers 137893)
    SPELL_TWISTED_FATE_SUMMON_FIRST = 137893, // Summon the first Twisted Fate -> USE THIS INTO EVENT
    SPELL_TWISTED_FATE_FORCE_FIRST = 137943, // Force cast 137950 on self
    SPELL_TWISTED_FATE_CLONE_FIRST = 137950, // Clone, Dummy, Size... WHAT ELSE ?
    // Second npc of Twisted Fate
    SPELL_TWISTED_FATE_FORCE_SUMMON_SECOND = 137962, // Trigger 137963 on the most distant player (fuck target)
    SPELL_TWISTED_FATE_SUMMON_SECOND = 137963, // Summon the second Twisted Fate -> USE THIS INTO EVENT
    SPELL_TWISTED_FATE_FORCE_SECOND = 137964, // Force cast 137965 on self
    SPELL_TWISTED_FATE_CLONE_SECOND = 137965, // Clone, Dummy, Size... WHAT ELSE ?

    //===============================================
    // Summons
    SPELL_FORTIFIED = 136864, // Living Sand : On hit by Sandstorm
    SPELL_TREACHEROUS_GROUND = 137614, // Living Sand : On emerge from reunited Quicksand
    SPELL_TREACHEROUS_GROUND_SIZE = 137629,
    SPELL_BLESSED_GIFT = 137303, // Blessed Loa Spirit, heal 5% of Max Health on weakest councillor
    SPELL_BLESSED_TIME_OUT = 137204, // Dummy visual for blizz
    SPELL_MARKED_SOUL = 137359, // Shadowed Loa Spirit / Player ? Force Loa to follow player
    SPELL_SHADOWED_GIFT = 137390, // Instantly kills player (Shadowed Loa Spirit)
    SPELL_SHADOWED_TIME_OUT = 137398, // Dummy visual for blizz

    //===============================================
    // Visuals
    SPELL_GARA_JALS_SOUL = 136423, // NPC Visual
    SPELL_BLESSED_TRANSFORMATION = 137181, // NPC Visual
    SPELL_SHADOWED_TRANSFORMATION = 137271, // NPC Visual
    SPELL_GARAJAL_GHOST = 000000, // TBF

    //===============================================
    // Shared
    SPELL_ZERO_POWER = 72242,
};


enum eEvents
{
    //===============================================
    // Frost King Malakk
    EVENT_FRIGID_ASSAULT = 1,
    EVENT_BITING_COLD = 2,
    EVENT_FROSTBITE = 3,

    //===============================================
    // Kazra'jin
    EVENT_RECKLESS_CHARGE_PRE_PATH = 4,
    EVENT_RECKLESS_CHARGE = 5,

    //===============================================
    // Sul the Sandcrawler
    EVENT_SAND_BOLT = 6,
    EVENT_QUICKSAND = 7,
    EVENT_SANDSTORM = 8,

    //===============================================
    // High Priestess Mar'li
    EVENT_WRATH_OF_THE_LOA = 9,
    EVENT_WRATH_OF_THE_LOA_DARK = 10,
    EVENT_BLESSED_LOA_SPIRIT = 11,
    EVENT_SHADOWED_LOA_SPIRIT = 12,
    EVENT_TWISTED_FATE = 13,

    //===============================================
    // Blessed Loa Spirit
    EVENT_BLESSED_GIFT = 14,
    EVENT_FROSTBITE_TRUE,
    EVENT_MOVE_COUNCILLOR = 21,
    EVENT_TARGET_A_RANDOM_PLAYER,
    EVENT_MOVE_TO_PLAYER,
    //===============================================
    // Shadowed Loa Spiri
    EVENT_SHADOWED_GIFT = 15,

    //===============================================
    // Councillots
    EVENT_INCREASE_POWER = 16,
    EVENT_DARK_POWER = 17,

    //===============================================
    // Quicksand Stalker
    EVENT_QUICKSAND_PERIODIC = 18, // This only handles apply of the Quicksand damages aura, which handle the rooting by itself
    EVENT_TRY_MERGE = 19, // Try merge event is used to merge Quicksand when they are summoend by others Quicksand (only scheduled once)
    EVENT_ACTIVATE_SAND = 22,

    //===============================================
    // Garajal
    EVENT_SUMMON_SOUL = 20,
    EVENT_TREACHEROUS_GROUND,
    EVENT_CHECK_POSSESED,
    EVENT_RECKLESS_CHARGE_HELPER,
    EVENT_CHECK_NONPOSSESED,
};

enum eActions
{
    //===============================================
    // Gara'jal
    ACTION_ENTER_COMBAT = 0, // Garajal + Garajal's soul
    ACTION_EXIT_COUNCILLOR = 1, // Garajal's soul
    ACTION_FIGHT_RESET = 2,
    ACTION_FIGHT_BEGIN = 3,
    ACTION_COUNCILLOR_DIED = 4,
    ACTION_BOSS_TIMER_START = 5,
    ACTION_BOSS_TIMER_WIPE = 6,
    ACTION_BOSS_TIMER_DONE = 7,

    //===============================================
    // Councillors
    ACTION_COUNCILLORS_ENTER_COMBAT = 4, // When one enters combat, everybody else must enter combat
    ACTION_SET_POSSESSED = 5, // Initialize the events to possessed phase (called from SpellScript)
    ACTION_SET_UNPOSSESSED = 6, // Reset the events to normal (same as for SET_POSSESED)
    ACTION_DARK_POWER = 7, // Initialize the Dark Power phase (called from the handler of the periodic dummy aura I assume)

    //===============================================
    // Kazra'jin
    ACTION_RESET_DAMAGES = 8, // Must be called each time the periodic aura ticks

    //===============================================
    // Living Sand
    ACTION_FORTIFY = 9,

    //===============================================
    // Twisted Fate Helper
    ACTION_TWISTED_FATE_END_FIGHT = 10, // Used to deallocate memory

    //===============================================
    // Twisted Fate (common)
    ACTION_OTHER_TWISTED_FATE_DIED = 11,

    //===============================================
    // Quicksand
    ACTION_CREATE_LIVING_SAND = 12,

    ACTION_I_WAS_INTERRUPTED = 13,
    ACTION_I_WAS_INTERRUPTED_SECOND = 14,
};


enum eMotions
{
    //===============================================
    // Gara'jal
    POINT_COUNCILLOR = 4343,

    //===============================================
    // Kazra'jin
    POINT_RECKLESS_CHARGE_LAND = 5000, // Position where Kazrajin lands after performing Reckless Charge
    POINT_RECKLESS_CHARGE_PLAYER = 6714, // Position where Kazrajin rolls to after landing from Reckless Charge

    //===============================================
    // Blessed Loa Spirit
    POINT_BLESSED_LOA_SPIRIT_COUNCILLOR = 9413, // Point to identify the councillor the Blessed Loa Spirit is going toward
    // No need to do a point for the Shadowed Loa Spirit since it will not
    // reach the target but only go 6 yards away from him (so we can use MoveFollow)

    //===============================================
    // Twisted Fate (common)
    POINT_MIDDLE = 6653, // Point representing the middle point on the line formed by the two Twisted Fate
};


enum eHelperStatus
{
    STATUS_RESET = 0,
    STATUS_PROGRESS = 1,
    STATUS_DONE = 2,
};


enum eDatas
{
    DATA_DARK_POWER_COUNT = 0,
    DATA_QUICKSAND_MERGE_COUNT = 1,
    DATA_SHADOWED_LOA_SPIRIT_TARGET_GUID = 2, // Accessor to get the GUID of the player the Shadowed Loa Spirit will follow
    DATA_BLESSED_LOA_SPIRIT_TARGET_GUID = 3, // Accessor to get the GUID of the boss the Blessed Loa Spirit will follow
    DATA_TWISTED_FATE_GUID = 4, // Accessor to get the GUID of the twisted fate the caller is linked to
    DATA_TWISTED_FATE_OTHER_DIED = 5, // Accessor to know if one twisted fate has been unlinked from the other
    DATA_RECKLESS_CHARGE_TARGET_GUID = 6, // Accessor to get the GUID of the player Kazrajin is targetting for the purpose of Reckless Charge
    DATA_DAMAGES_PAST_SEC = 7, // Accessor to get the amount of damages Kazrajin received in the last second
};


enum eTalks : uint32
{
    TALK_AGGRO = 0,
    TALK_POSSESS = 1,
    TALK_SPECIAL = 2,
    EMOTE_POSSESS = 6,

    // sul
    TALK_SUL_QUICKSAND = 3,
    TALK_SUL_SLAY = 4,
    TALK_SUL_DEATH = 5,
    TALK_SUL_SANDSTORM = 7,

    // malakk
    TALK_MALAKK_SLAY = 3,
    TALK_MALAKK_DEATH = 4,
    TALK_MALAKK_FROSTBITE = 5,

    // marli
    TALK_MARLI_SLAY = 3,
    TALK_MARLI_DEATH = 4,
    TALK_MARLI_BLESSED = 5,
    TALK_MARLI_SHADOWED = 7,

    // kazra'jin
    TALK_KAZRAJIN_CHARGE = 3,
    TALK_KAZRAJIN_SLAY = 4,
    TALK_KAZRAJIN_DEATH = 5,
    TALK_KAZRAJIN_OVERLOAD = 7
};

//=========================================================
// Helpers

static Creature* GetGarajal(WorldObject* pSource)
{
    return ObjectAccessor::GetCreature(*pSource, pSource->GetInstanceScript()->GetObjectGuid(MOB_GARA_JAL));
}

static Creature* GetGarajalsSoul(WorldObject* pSource)
{
    return ObjectAccessor::GetCreature(*pSource, pSource->GetInstanceScript()->GetObjectGuid(MOB_GARA_JALS_SOUL));
}

static Creature* GetFrostKingMalakk(WorldObject* pSource)
{
    return ObjectAccessor::GetCreature(*pSource, pSource->GetInstanceScript()->GetObjectGuid(BOSS_COUNCIL_FROST_KING_MALAKK));
}

static Creature* GetKazrajin(WorldObject* pSource)
{
    return ObjectAccessor::GetCreature(*pSource, pSource->GetInstanceScript()->GetObjectGuid(BOSS_COUNCIL_KAZRAJIN));
}

static Creature* GetSulTheSandcrawler(WorldObject* pSource)
{
    return ObjectAccessor::GetCreature(*pSource, pSource->GetInstanceScript()->GetObjectGuid(BOSS_COUNCIL_SUL_THE_SANDCRAWLER));
}

static Creature* GetHighPriestessMarli(WorldObject* pSource)
{
    return ObjectAccessor::GetCreature(*pSource, pSource->GetInstanceScript()->GetObjectGuid(BOSS_COUNCIL_HIGH_PRIESTESS_MARLI));
}

static Creature* GetBossByEntry(uint32 uiEntry, WorldObject* pSource)
{
    switch (uiEntry)
    {
    case BOSS_COUNCIL_FROST_KING_MALAKK:
        return GetFrostKingMalakk(pSource);

    case BOSS_COUNCIL_KAZRAJIN:
        return GetKazrajin(pSource);

    case BOSS_COUNCIL_SUL_THE_SANDCRAWLER:
        return GetSulTheSandcrawler(pSource);

    case BOSS_COUNCIL_HIGH_PRIESTESS_MARLI:
        return GetHighPriestessMarli(pSource);

    default:
        return NULL;
    }
}

// Convenient typedef for the accessors
typedef Creature* (*Accessor)(WorldObject* pSource);

static const std::array<uint32, 4> uiBossEntries = { BOSS_COUNCIL_FROST_KING_MALAKK, BOSS_COUNCIL_KAZRAJIN, BOSS_COUNCIL_SUL_THE_SANDCRAWLER, BOSS_COUNCIL_HIGH_PRIESTESS_MARLI };

void AddSC_boss_council_of_elders()
{
   
}
