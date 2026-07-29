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
#include "SpellHistory.h"

#include "Followship_bots_utils.h"
#include "Followship_bots_mgr.h"

std::vector<FSBSpellDefinition> WarlockSpellsTable =
{
    // Spell ID                             Spell Type              ManaCost %  HP % for heal   Chance           Dist/Range     SelfCast    Cooldown Ms     RoleMask

    // ANY
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

    { SPELL_WARLOCK_UNENDING_RESOLVE,       FSBSpellType::Heal,     0.f,        50.f,           50.f,            0.f,           true,       180000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    
    { SPELL_WARLOCK_FEAR,                   FSBSpellType::Damage,   0.03f,      0.f,            70.f,            20.f,          false,      8000,           FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_WARLOCK_MORTAL_COIL,            FSBSpellType::Heal,     0.f,        60.f,           80.f,            20.f,          false,      45000,          FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_WARLOCK_DARK_PACT,              FSBSpellType::Heal,     0.f,        50.f,           60.f,            0.f,           true,       60000,          FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_WARLOCK_BLIGHT_WEAKNESS,        FSBSpellType::Damage,   0.05f,      0.f,            80.f,            40.f,          false,      120000,         FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_WARLOCK_DRAIN_LIFE,             FSBSpellType::Damage,   0.f,        0.f,            40.f,            40.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_ANY },
    
    // AFFLICTION
    { SPELL_WARLOCK_HOWL_TERROR,            FSBSpellType::Damage,   0.f,        0.f,        100.f,        5.f,           true,       40000,          FSB_RoleMask::FSB_ROLEMASK_RANGED_AFFLICTION },
    { SPELL_WARLOCK_CURSE_TONGUES,          FSBSpellType::Damage,   0.f,        0.f,        100.f,        40.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_RANGED_AFFLICTION },
    { SPELL_WARLOCK_CURSE_EXHAUSTION,       FSBSpellType::Damage,   0.f,        0.f,        100.f,        40.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_RANGED_AFFLICTION },

    { SPELL_WARLOCK_HAUNT,                  FSBSpellType::Damage,   0.f,        0.f,        90.f,         40.f,          false,      15000,          FSB_RoleMask::FSB_ROLEMASK_RANGED_AFFLICTION },

    { SPELL_WARLOCK_CORRUPTION,             FSBSpellType::Damage,   0.f,        0.f,        90.f,         40.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_RANGED_AFFLICTION },
    { SPELL_WARLOCK_AGONY,                  FSBSpellType::Damage,   0.f,        0.f,        90.f,         40.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_RANGED_AFFLICTION },
    { SPELL_WARLOCK_CURSE_WEAKNESS,         FSBSpellType::Damage,   0.f,        0.f,        90.f,         40.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_RANGED_AFFLICTION },

    { SPELL_WARLOCK_DRAIN_SOUL,             FSBSpellType::Damage,   0.f,        0.f,        80.f,         40.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_RANGED_AFFLICTION },

    { SPELL_WARLOCK_SEED_CORRUPTION,        FSBSpellType::Damage,   0.f,        0.f,        70.f,         30.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_RANGED_AFFLICTION },
    { SPELL_WARLOCK_UNSTABLE_AFFLICTION,    FSBSpellType::Damage,   0.f,        0.f,        70.f,         30.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_RANGED_AFFLICTION },

    // DEMONOLOGY
    { SPELL_WARLOCK_DEMONIC_TYRANT,         FSBSpellType::Damage,   0.f,        0.f,        100.f,        40.f,          false,      60000,          FSB_RoleMask::FSB_ROLEMASK_RANGED_DEMONOLOGY },
    { SPELL_WARLOCK_CALL_DREADSTALKERS,     FSBSpellType::Damage,   0.05f,      0.f,        100.f,        40.f,          false,      20000,          FSB_RoleMask::FSB_ROLEMASK_RANGED_DEMONOLOGY },
    { SPELL_WARLOCK_DEMONBOLT,              FSBSpellType::Damage,   0.f,        0.f,        80.f,         40.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_RANGED_DEMONOLOGY },
    { SPELL_WARLOCK_SHADOW_BOLT,            FSBSpellType::Damage,   0.f,        0.f,        80.f,         40.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_RANGED_DEMONOLOGY },
    { SPELL_WARLOCK_WILD_IMPS,              FSBSpellType::Damage,   0.5f,       0.f,        20.f,         40.f,          false,      1800000,        FSB_RoleMask::FSB_ROLEMASK_RANGED_DEMONOLOGY },
    { SPELL_WARLOCK_SHADOWFURY,             FSBSpellType::Damage,   0.f,        0.f,        100.f,        35.f,          false,      60000,          FSB_RoleMask::FSB_ROLEMASK_RANGED_DEMONOLOGY },

    // DESTRO
    { SPELL_WARLOCK_SUMMON_INFERNAL,        FSBSpellType::Damage,   0.3f,       0.f,        100.f,        40.f,          false,      180000,         FSB_RoleMask::FSB_ROLEMASK_RANGED_DESTRUCTION },
    { SPELL_WARLOCK_CHAOS_BOLT,             FSBSpellType::Damage,   0.04f,      0.f,         90.f,        40.f,          false,      10000,          FSB_RoleMask::FSB_ROLEMASK_RANGED_DESTRUCTION },
    { SPELL_WARLOCK_SOUL_FIRE,              FSBSpellType::Damage,   0.f,        0.f,         90.f,        40.f,          false,      45000,          FSB_RoleMask::FSB_ROLEMASK_RANGED_DESTRUCTION },
    { SPELL_WARLOCK_SHADOW_BOLT,            FSBSpellType::Damage,   0.f,        0.f,        80.f,         40.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_RANGED_DESTRUCTION },
    { SPELL_WARLOCK_IMMOLATE,               FSBSpellType::Damage,   0.f,        0.f,         80.f,        40.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_RANGED_DESTRUCTION },
    { SPELL_WARLOCK_SHADOWBURN,             FSBSpellType::Damage,   0.f,        0.f,         80.f,        40.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_RANGED_DESTRUCTION },
    { SPELL_WARLOCK_CONFLAGRATE,            FSBSpellType::Damage,   0.f,        0.f,         70.f,        40.f,          false,      13000,          FSB_RoleMask::FSB_ROLEMASK_RANGED_DESTRUCTION },
    { SPELL_WARLOCK_INCINERATE,             FSBSpellType::Damage,   0.f,        0.f,         70.f,        40.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_RANGED_DESTRUCTION },
    { SPELL_WARLOCK_HAVOC,                  FSBSpellType::Damage,   0.f,        0.f,         80.f,        40.f,          false,      30000,          FSB_RoleMask::FSB_ROLEMASK_RANGED_DESTRUCTION },
    { SPELL_WARLOCK_CATACLYSM,              FSBSpellType::Damage,   0.f,        0.f,         30.f,        40.f,          false,      30000,          FSB_RoleMask::FSB_ROLEMASK_RANGED_DESTRUCTION },




};

namespace FSBWarlock
{
    void HandleOnSpellCast(Creature* bot, uint32 spellId)
    {
        Unit* target = bot->GetVictim();

        switch (spellId)
        {
        case SPELL_WARLOCK_CHAOS_BOLT:
            if(target)
                bot->CastSpell(target, SPELL_WARLOCK_CHAOS_BOLT_PERIODIC);
            break;

        default:
            break;
        }
    }

    bool BotOOCBuffSelf(Creature* bot, uint32& globalCooldown, uint32& selfBuffTimer, uint32& outSpellId)
    {
        if (!bot)
            return false;

        uint32 now = getMSTime();

        bool isDemonology = FSBMgr::Get()->GetRole(bot) == FSB_ROLE_RANGED_DEMONOLOGY;

        if (isDemonology && !bot->HasAura(SPELL_WARLOCK_DEMON_ARMOR))
        {

            bot->CastSpell(bot, SPELL_WARLOCK_DEMON_ARMOR, false);
            selfBuffTimer = now + 60000; // 1 minute
            globalCooldown = now + 1500; // use 10s cooldown to not interrup duration of channel spell
            outSpellId = SPELL_WARLOCK_DEMON_ARMOR;

            return true;
        }

        return false;
    }

    bool BotSummonRandomDemon(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return false;

        auto& botHasDemon = baseAI->botHasDemon;
        if (botHasDemon)
            return false;

        auto botClass = baseAI->botClass;
        if (botClass != FSB_Class::Warlock)
            return false;

        auto role = baseAI->botRole;
        auto& globalCooldown = baseAI->botGlobalCooldown;

        

        uint32 spellId = SPELL_WARLOCK_SUMMON_IMP;

        if(role == FSB_ROLE_RANGED_DEMONOLOGY)
            spellId = RAND(
                SPELL_WARLOCK_SUMMON_IMP,
                SPELL_WARLOCK_SUMMON_SUCCUBUS,
                SPELL_WARLOCK_SUMMON_VOIDWALKER,
                SPELL_WARLOCK_SUMMON_FELHUNTER,
                SPELL_WARLOCK_SUMMON_FELGUARD,
                SPELL_WARLOCK_SUMMON_DOOMGUARD);

        SpellCastResult result = bot->CastSpell(bot, spellId, false);

        TC_LOG_DEBUG("scripts.ai.fsb", "FSB BotSummonRandomDemon result {} for bot {}", result, bot->GetName());

        

        if (result == SPELL_CAST_OK)
        {
            uint32 now = getMSTime();

            //demonDead = false;
            globalCooldown = now + 1500;
            

            return true;
        }

        return false;
    }

    bool BotHasUnendingResolve(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        if (bot->HasAura(SPELL_WARLOCK_UNENDING_RESOLVE))
            return true;

        return false;

    }

    void AdjustSummonHealth(Creature* bot, Creature* summon)
    {
        if (!bot || !summon)
            return;

        switch (summon->GetEntry())
        {
        case 42874:
        {
            uint64 maxHealth = bot->GetMaxHealth() * 1.5f;
            summon->SetMaxHealth(maxHealth);
            summon->SetHealth(maxHealth);
            break;
        }
        case 175190:
        {
            uint64 maxHealth = bot->GetMaxHealth() * 0.8f;
            summon->SetMaxHealth(maxHealth);
            summon->SetHealth(maxHealth);
            break;
        }
        case 54303: // Doomguard
        {
            uint64 maxHealth = bot->GetMaxHealth();
            summon->SetMaxHealth(maxHealth);
            summon->SetHealth(maxHealth);
            break;
        }
        default:
            break;
        }
    }

    void BotSetRoleAuras(Creature* bot, FSB_Roles role)
    {
        if (!bot)
            return;

        switch (role)
        {
        case FSB_ROLE_RANGED_DEMONOLOGY:
            if (!bot->HasAura(SPELL_WARLOCK_DEMON_ARMOR))
                bot->CastSpell(bot, SPELL_WARLOCK_DEMON_ARMOR, false);
            break;
        case FSB_ROLE_RANGED_AFFLICTION:
        case FSB_ROLE_RANGED_DESTRUCTION:
            if (bot->HasAura(SPELL_WARLOCK_DEMON_ARMOR))
                bot->RemoveAurasDueToSpell(SPELL_WARLOCK_DEMON_ARMOR);
            break;
        default:
            break;
        }
    }
}
