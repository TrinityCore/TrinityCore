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

extern std::vector<FSBSpellDefinition> WarlockSpellsTable;

enum FSB_WARLOCK_SPECIAL_SPELLS
{

    SPELL_WARLOCK_UNENDING_BREATH = 5697,

    SPELL_WARLOCK_HEALTHSTONE = 6262,
    SPELL_WARLOCK_SOULSTONE = 20707,
    SPELL_WARLOCK_SOULSTONE_VISUAL = 73704, // needed for npcs

    SPELL_WARLOCK_FELSTEED = 5784,
    SPELL_WARLOCK_DREADSTEED = 23161
};

enum FSB_WARLOCK_COMBAT_SPELLS
{
    SPELL_WARLOCK_UNENDING_RESOLVE = 104773,
    SPELL_WARLOCK_FEAR = 12096, //5782,

    SPELL_WARLOCK_SHADOW_BOLT = 686, //20825
    SPELL_WARLOCK_DRAIN_LIFE = 234153, //17173

    SPELL_WARLOCK_MORTAL_COIL = 6789,
    SPELL_WARLOCK_DARK_PACT = 108416,
    SPELL_WARLOCK_BLIGHT_WEAKNESS = 1271798,
    
};

enum FSB_WARLOCK_AFFLICTION_SPELLS
{
    SPELL_WARLOCK_CORRUPTION = 172, //31405, //21068 //31405 //30938
    SPELL_WARLOCK_AGONY = 37334, //980,
    SPELL_WARLOCK_CURSE_WEAKNESS = 702,
    SPELL_WARLOCK_CURSE_TONGUES = 1714,
    SPELL_WARLOCK_CURSE_EXHAUSTION = 334275,
    SPELL_WARLOCK_HAUNT = 48181, //171788,
    SPELL_WARLOCK_SEED_CORRUPTION = 44141,
    SPELL_WARLOCK_UNSTABLE_AFFLICTION = 34438,
    SPELL_WARLOCK_HOWL_TERROR = 5484,
    SPELL_WARLOCK_DRAIN_SOUL = 198590,
};

enum FSB_WARLOCK_DEMONOLOGY_SPELLS
{
    SPELL_WARLOCK_DEMON_ARMOR = 285933,

    SPELL_WARLOCK_SUMMON_IMP = 11939, //688, //11939,
    SPELL_WARLOCK_SUMMON_SUCCUBUS = 78060, //366222, //712,
    SPELL_WARLOCK_SUMMON_VOIDWALKER = 344692, //43896 //697
    SPELL_WARLOCK_SUMMON_FELHUNTER = 344744,
    SPELL_WARLOCK_SUMMON_FELGUARD = 79958,
    SPELL_WARLOCK_SUMMON_DOOMGUARD = 22865,

    SPELL_WARLOCK_CALL_DREADSTALKERS = 193332,
    SPELL_WARLOCK_DEMONIC_TYRANT = 265187,
    SPELL_WARLOCK_WILD_IMPS = 138685, // 399319

    SPELL_WARLOCK_DEMONBOLT = 264178, //464915

    SPELL_WARLOCK_SHADOWFURY = 30283,
};

enum FSB_WARLOCK_DESTRUCTION_SPELLS
{
    SPELL_WARLOCK_SUMMON_INFERNAL = 269774,
    SPELL_WARLOCK_CATACLYSM = 152108, //242943,
    SPELL_WARLOCK_IMMOLATE = 348, //11962,
    SPELL_WARLOCK_INCINERATE = 29722, //100229,
    SPELL_WARLOCK_CHAOS_BOLT = 216095,
    SPELL_WARLOCK_CHAOS_BOLT_PERIODIC = 183227,
    SPELL_WARLOCK_CONFLAGRATE = 17962, //154083,
    SPELL_WARLOCK_RAIN_FIRE = 43440,
    SPELL_WARLOCK_SHADOWBURN = 295422,
    SPELL_WARLOCK_SOUL_FIRE = 6353, //131381
    SPELL_WARLOCK_HAVOC = 80240,

};

namespace FSBWarlock
{
    bool BotOOCBuffSelf(Creature* bot, uint32& globalCooldown, uint32& selfBuffTimer, uint32& outSpellId);

    bool BotSummonRandomDemon(Creature* bot);

    bool BotHasUnendingResolve(Creature* bot);

    void HandleOnSpellCast(Creature* bot, uint32 spellId);

    void AdjustSummonHealth(Creature* bot, Creature* summon);

    void BotSetRoleAuras(Creature* bot, FSB_Roles role);
}
