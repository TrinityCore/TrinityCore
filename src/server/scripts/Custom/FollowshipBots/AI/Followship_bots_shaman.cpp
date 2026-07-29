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

#include "Log.h"
#include "ScriptedCreature.h"
#include "SpellHistory.h"

#include "Followship_bots_mgr.h"
#include "Followship_bots_utils.h"

#include "Followship_bots_spells_handler.h"

std::vector<FSBSpellDefinition> ShamanSpellsTable =
{
    // Spell ID                             Spell Type              ManaCost %  HP % for heal   Chance           Dist/Range     SelfCast    Cooldown Ms     RoleMask                                                        LocationSpell

    // ===================== RACIALS (ANY) =====================
    { SPELL_HUMAN_WILL_TO_SURVIVE,          FSBSpellType::Heal,     0.f,        80.f,           100.f,           0.f,           true,       180000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_DWARF_STONEFORM,                FSBSpellType::Heal,     0.f,        80.f,           100.f,           0.f,           true,       120000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_DRAENEI_GIFT_NAARU,             FSBSpellType::Heal,     0.f,        50.f,           100.f,           30.f,          false,      120000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_PANDAREN_QUAKING_PALM,          FSBSpellType::Damage,   0.f,        0.f,            100.f,           2.f,           false,      120000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_ORC_BLOOD_FURY,                 FSBSpellType::Damage,   0.f,        0.f,            100.f,           0.f,           true,       120000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_UNDEAD_WILL_OF_FORSAKEN,        FSBSpellType::Heal,     0.f,        80.f,           100.f,           0.f,           true,        30000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_TAUREN_WAR_STOMP,               FSBSpellType::Damage,   0.f,        0.f,            100.f,           8.f,           false,       90000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_TROLL_BERSERKING,               FSBSpellType::Damage,   0.f,        0.f,            100.f,           0.f,           true,       180000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_BLOODELF_ARCANE_TORRENT,        FSBSpellType::Damage,   0.f,        0.f,            100.f,           8.f,           false,      120000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_GOBLIN_ROCKET_BARRAGE,          FSBSpellType::Damage,   0.f,        0.f,            100.f,          30.f,           false,       90000,         FSB_RoleMask::FSB_ROLEMASK_ANY },

    // ===================== SHARED (ANY ROLE) =====================
    { SPELL_SHAMAN_HEALING_SURGE,           FSBSpellType::Heal,     0.1f,       50.f,           100.f,           40.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_SHAMAN_FLAME_SHOCK,             FSBSpellType::Damage,   0.f,        0.f,            70.f,            25.f,          false,      6000,           FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_SHAMAN_FROST_SHOCK,             FSBSpellType::Damage,   0.f,        0.f,            50.f,            25.f,          false,      6000,           FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_SHAMAN_HEROISM,                 FSBSpellType::Damage,   0.f,        0.f,            50.f,            0.f,           true,       600000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_SHAMAN_WIND_SHEAR,              FSBSpellType::Damage,   0.f,        0.f,            100.f,           25.f,          false,      12000,          FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_SHAMAN_HEX,                     FSBSpellType::Damage,   0.f,        0.f,            100.f,           30.f,          false,      30000,          FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_SHAMAN_ASTRAL_SHIFT,            FSBSpellType::Heal,     0.f,        30.f,           100.f,           0.f,           true,       90000,          FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_SHAMAN_THUNDERSTORM,            FSBSpellType::Damage,   0.f,        0.f,            100.f,           0.f,           true,       30000,          FSB_RoleMask::FSB_ROLEMASK_ANY },

    // ===================== ELEMENTAL (RANGED DAMAGE) =====================
    { SPELL_SHAMAN_LIGHTNING_BOLT,          FSBSpellType::Damage,   0.f,        0.f,            70.f,            40.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_RANGED_DAMAGE },
    { SPELL_SHAMAN_LAVA_BURST,              FSBSpellType::Damage,   0.f,        0.f,            80.f,            40.f,          false,      8000,           FSB_RoleMask::FSB_ROLEMASK_RANGED_DAMAGE },
    { SPELL_SHAMAN_EARTH_SHOCK,             FSBSpellType::Damage,   0.f,        0.f,            70.f,            25.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_RANGED_DAMAGE },
    { SPELL_SHAMAN_CHAIN_LIGHTNING,         FSBSpellType::Damage,   0.f,        0.f,            60.f,            40.f,          false,      3000,           FSB_RoleMask::FSB_ROLEMASK_RANGED_DAMAGE },
    { SPELL_SHAMAN_ELEMENTAL_BLAST,         FSBSpellType::Damage,   0.f,        0.f,            70.f,            40.f,          false,      12000,          FSB_RoleMask::FSB_ROLEMASK_RANGED_DAMAGE },
    { SPELL_SHAMAN_STORMKEEPER,             FSBSpellType::Damage,   0.f,        0.f,            50.f,            40.f,          true,       60000,          FSB_RoleMask::FSB_ROLEMASK_RANGED_DAMAGE },
    //{ SPELL_SHAMAN_EARTHQUAKE,              FSBSpellType::Damage,   0.f,        0.f,            60.f,            40.f,          false,      6000,           FSB_RoleMask::FSB_ROLEMASK_RANGED_DAMAGE,                        true },

    // ===================== ENHANCEMENT (MELEE DAMAGE) =====================
    { SPELL_SHAMAN_ASCENDANCE_AIR,          FSBSpellType::Damage,     0.f,      0.f,            50.f,            2.f,           true,       180000,         FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },

    { SPELL_SHAMAN_STORMSTRIKE,             FSBSpellType::Damage,   0.f,        0.f,            80.f,            2.f,           false,      7500,           FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_SHAMAN_LAVA_LASH,               FSBSpellType::Damage,   0.f,        0.f,            70.f,            2.f,           false,      18000,          FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_SHAMAN_CRASH_LIGHTNING,         FSBSpellType::Damage,   0.f,        0.f,            60.f,            2.f,           false,      12000,          FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_SHAMAN_PRIMAL_STRIKE,           FSBSpellType::Damage,   0.f,        0.f,            70.f,            2.f,           false,      1000,           FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_SHAMAN_SUNDERING,               FSBSpellType::Damage,   0.f,        0.f,            50.f,            2.f,           false,      40000,          FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_SHAMAN_DOOM_WINDS,              FSBSpellType::Damage,   0.f,        0.f,            50.f,            2.f,           true,       40000,          FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    //{ SPELL_SHAMAN_FERAL_SPIRIT,            FSBSpellType::Damage,   0.f,        0.f,            100.f,           0.f,           true,       120000,         FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },

    // ===================== RESTORATION (HEALER) =====================
    { SPELL_SHAMAN_ASCENDANCE,              FSBSpellType::Heal,     0.f,        90.f,           50.f,            0.f,           true,       180000,         FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_SHAMAN_HEALING_RAIN,            FSBSpellType::Heal,     0.f,        40.f,           100.f,           40.f,          false,      18000,          FSB_RoleMask::FSB_ROLEMASK_HEALER,                               true },
    { SPELL_SHAMAN_HEALING_WAVE,            FSBSpellType::Heal,     0.f,        40.f,           100.f,           40.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_SHAMAN_CHAIN_HEAL,              FSBSpellType::Heal,     0.f,        50.f,           80.f,            40.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_SHAMAN_UNLEASH_LIFE,            FSBSpellType::Heal,     0.f,        70.f,           50.f,            40.f,          false,      20000,          FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_SHAMAN_RIPTIDE,                 FSBSpellType::Heal,     0.f,        70.f,           100.f,           40.f,          false,      6000,           FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_SHAMAN_DOWNPOUR,                FSBSpellType::Heal,     0.f,        30.f,           80.f,            35.f,          false,      35000,          FSB_RoleMask::FSB_ROLEMASK_HEALER,                               true },
    //{ SPELL_SHAMAN_SPIRIT_LINK_TOTEM,       FSBSpellType::Heal,     0.f,        25.f,           100.f,           40.f,          false,      180000,         FSB_RoleMask::FSB_ROLEMASK_HEALER,                               true },

    // Healer filler damage (when group is healthy)
    { SPELL_SHAMAN_LIGHTNING_BOLT,          FSBSpellType::Damage,   0.f,        0.f,            40.f,            40.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_HEALER },
};

namespace FSBShaman
{
    bool BotOOCBuffSelf(Creature* bot, uint32& outSpellId)
    {
        if (!bot || !bot->IsAlive())
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return false;

        auto& buffTimer = baseAI->botBuffsTimer;
        auto& cooldown = baseAI->botGlobalCooldown;

        uint32 now = getMSTime();

        if (!bot->HasAura(SPELL_SHAMAN_SKYFURY))
        {
            Unit* target = nullptr;
            if (Player* player = FSBMgr::Get()->GetBotOwner(bot))
                target = player;
            else target = bot;

            uint32 spellId = SPELL_SHAMAN_SKYFURY;
            if (FSBSpells::BotCastSpell(bot, spellId, target))
            {
                //buffTimer = now + 60000; // 1 minute we set it after the second buff is set
                cooldown = now + 1500; // 
                outSpellId = spellId;
                TC_LOG_DEBUG("scripts.fsb.buffs", "FSB: Bot {} Shaman Spell Cast: Skyfury on self.", bot->GetName());
                return true;
            }
        }

        uint32 shieldSpell = SPELL_SHAMAN_LIGHTNING_SHIELD;
        if (baseAI->botRole == FSB_ROLE_HEALER)
            shieldSpell = SPELL_SHAMAN_WATER_SHIELD;

        if (!bot->HasAura(shieldSpell))
        {
            if (FSBSpells::BotCastSpell(bot, shieldSpell, bot))
            {
                buffTimer = now + 60000; // 1 minute
                cooldown = now + 1500; // 
                outSpellId = shieldSpell;
                TC_LOG_DEBUG("scripts.fsb.buffs", "FSB: Bot {} Shaman Spell Cast: {} on self", bot->GetName(), FSBSpellsUtils::GetSpellName(shieldSpell));
                return true;
            }
        }

        if ((baseAI->botRole == FSB_ROLE_MELEE_DAMAGE || baseAI->botRole == FSB_ROLE_RANGED_DAMAGE) && !bot->HasAura(SPELL_SHAMAN_FLAMETONGUE_WEAPON))
        {
            if (FSBSpells::BotCastSpell(bot, SPELL_SHAMAN_FLAMETONGUE_WEAPON, bot))
            {
                buffTimer = now + 60000; // 1 minute
                cooldown = now + 1500; // 
                outSpellId = SPELL_SHAMAN_FLAMETONGUE_WEAPON;
                TC_LOG_DEBUG("scripts.fsb.buffs", "FSB: Bot {} Shaman Spell Cast: {} on self", bot->GetName(), FSBSpellsUtils::GetSpellName(SPELL_SHAMAN_FLAMETONGUE_WEAPON));
                return true;
            }
        }

        return false;
    }

    bool BotInitialCombatSpells(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        if (!bot->IsInCombat())
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return false;

        if (baseAI->botCastedCombatBuffs)
            return false;

        uint32 totem1Spell = SPELL_SHAMAN_EARTH_TOTEM; // all roles
        uint32 totem2Spell = 0;
        uint32 totem3Spell = 0;
        uint32 totem4Spell = 0;

        // Place totems near the enemy for offensive totems, near bot for defensive/healing
        Position offensivePos = FSBSpells::GetOffensiveAoEPosition(bot);
        Position defensivePos = Position{ bot->GetPositionX() + frand(-2.f, 2.f), bot->GetPositionY() + frand(-2.f, 2.f), bot->GetPositionZ() };

        switch (baseAI->botRole)
        {
        case FSB_ROLE_HEALER:
            totem2Spell = SPELL_SHAMAN_HEALING_STREAM_TOTEM;
            totem3Spell = SPELL_SHAMAN_MANA_TIDE_TOTEM;
            totem4Spell = SPELL_SHAMAN_HEALING_TIDE_TOTEM;
            break;
        case FSB_ROLE_TANK:
            totem2Spell = SPELL_SHAMAN_EARTHGRAB_TOTEM;
            totem3Spell = SPELL_SHAMAN_FIRE_NOVA_TOTEM;
            totem4Spell = SPELL_SHAMAN_CAPACITATOR_TOTEM;
            break;
        case FSB_ROLE_MELEE_DAMAGE:
            totem2Spell = SPELL_SHAMAN_WIND_RUSH_TOTEM;
            totem3Spell = SPELL_SHAMAN_LIQUID_MAGMA_TOTEM;
            totem4Spell = SPELL_SHAMAN_SCORCHING_TOTEM;
            break;
        case FSB_ROLE_RANGED_DAMAGE:
            totem2Spell = SPELL_SHAMAN_LIQUID_MAGMA_TOTEM;
            totem3Spell = SPELL_SHAMAN_SCORCHING_TOTEM;
            totem4Spell = SPELL_SHAMAN_CAPACITATOR_TOTEM;
            break;
        default:
            break;
        }

        uint32 now = getMSTime();

        auto TryCastTotem = [&](uint32 spell, bool useOffensivePos) -> bool
        {
            if (!spell || bot->GetSpellHistory()->HasCooldown(spell))
                return false;

            // Self-target totems (Healing Stream, Mana Tide, Healing Tide, Fire Nova, Scorching)
            if (spell == SPELL_SHAMAN_HEALING_STREAM_TOTEM)
            {
                Unit* existing = bot->FindNearestCreature(3527, 40.f);
                if (existing)
                    return false;
                return FSBSpells::BotCastSpell(bot, spell, bot);
            }
            if (spell == SPELL_SHAMAN_MANA_TIDE_TOTEM || spell == SPELL_SHAMAN_HEALING_TIDE_TOTEM
                || spell == SPELL_SHAMAN_FIRE_NOVA_TOTEM || spell == SPELL_SHAMAN_SCORCHING_TOTEM)
            {
                return FSBSpells::BotCastSpell(bot, spell, bot);
            }

            // Location-target totems
            Position const& pos = useOffensivePos ? offensivePos : defensivePos;
            return FSBSpells::BotCastSpellatLocation(bot, spell, pos);
        };

        // Determine if offensive totems should use enemy position
        bool isOffensiveRole = (baseAI->botRole == FSB_ROLE_TANK
            || baseAI->botRole == FSB_ROLE_MELEE_DAMAGE
            || baseAI->botRole == FSB_ROLE_RANGED_DAMAGE);

        uint32 totems[] = { totem1Spell, totem2Spell, totem3Spell, totem4Spell };
        for (uint32 spell : totems)
        {
            if (TryCastTotem(spell, isOffensiveRole))
            {
                baseAI->botGlobalCooldown = now + 1500;
                TC_LOG_DEBUG("scripts.fsb.combat", "FSB: Shaman Initial Totem Spell Cast: {}", FSBSpellsUtils::GetSpellName(spell));
                return true;
            }
        }

        return false;
    }

    bool BotOOCHealOwner(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return false;

        Player* player = FSBMgr::Get()->GetBotOwner(bot);

        if (!player || !player->IsAlive())
            return false;

        uint32 spellId = SPELL_SHAMAN_HEALING_SURGE;

        uint32 now = getMSTime();

        if (player->GetHealthPct() <= 50)
        {
            FSBSpells::BotCastSpell(bot, spellId, player);
            baseAI->botGlobalCooldown = now + 1500;

            TC_LOG_DEBUG("scripts.fsb.ooc", "FSB: Shaman BotOOCHealOwner Bot: {} Player Heal < 50", bot->GetName());

            return true;

        }

        return false;
    }
}
