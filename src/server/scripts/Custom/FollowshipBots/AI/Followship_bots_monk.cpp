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
#include "SpellAuras.h"

#include "Followship_bots_mgr.h"
#include "Followship_bots_utils.h"

#include "Followship_bots_stats_handler.h"

std::vector<FSBSpellDefinition> MonkSpellsTable =
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

    { SPELL_MONK_FORTIFYING_BREW,           FSBSpellType::Heal,     0.f,        20.f,           100.f,           0.f,           true,       90000,          FSB_RoleMask::FSB_ROLEMASK_ANY },

    { SPELL_MONK_SPEAR_HAND_STRIKE,         FSBSpellType::Damage,   0.f,        0.f,            100.f,           2.f,           false,      15000,          FSB_RoleMask::FSB_ROLEMASK_ANY },
    { SPELL_MONK_LEG_SWEEP,                 FSBSpellType::Damage,   0.f,        0.f,            50.f,            6.f,           false,      60000,          FSB_RoleMask::FSB_ROLEMASK_ANY },

    //TANK
    { SPELL_MONK_VIVIFY,                    FSBSpellType::Heal,     0.3f,       50.f,           100.f,           40.f,          false,      2000,           FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_MONK_BLACK_OX_BREW,             FSBSpellType::Heal,     0.f,        30.f,           50.f,            0.f,           true,       120000,         FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_MONK_CELESTIAL_INFUSION,        FSBSpellType::Heal,     0.f,        70.f,           50.f,            0.f,           true,       45000,          FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_MONK_CELESTIAL_BREW,            FSBSpellType::Heal,     0.f,        30.f,           50.f,            0.f,           true,       45000,          FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_MONK_EXPEL_HARM,                FSBSpellType::Heal,     0.15f,      40.f,           100.f,           0.f,           true,       15000,          FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_MONK_PURIFYING_BREW,            FSBSpellType::Heal,     0.f,        70.f,           50.f,            0.f,           true,       10000,          FSB_RoleMask::FSB_ROLEMASK_TANK },

    { SPELL_MONK_PROVOKE,                   FSBSpellType::Damage,   0.f,        0.f,            100.f,           30.f,          false,      30000,          FSB_RoleMask::FSB_ROLEMASK_TANK },

    // cc
    { SPELL_MONK_SPINNING_CRANE,            FSBSpellType::Damage,   0.4f,       0.f,            100.f,           6.f,           false,      1000,           FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_MONK_BLACK_OX_STATUE,           FSBSpellType::Damage,   0.f,        0.f,            100.f,           2.f,           true,       10000,          FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_MONK_RUSHING_JADE_WIND,         FSBSpellType::Damage,   0.f,        0.f,            100.f,           8.f,           false,      6000,           FSB_RoleMask::FSB_ROLEMASK_TANK },
    // dmg
    { SPELL_MONK_TIGER_PALM,                FSBSpellType::Damage,   0.5f,       0.f,            100.f,           2.f,           false,      1000,           FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_MONK_INVOKE_NIUZAO,             FSBSpellType::Damage,   0.f,        0.f,            100.f,           40.f,          false,      120000,         FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_MONK_EXPLODING_KEG,             FSBSpellType::Damage,   0.f,        0.f,            100.f,           40.f,          false,      60000,          FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_MONK_CHI_BURST,                 FSBSpellType::Damage,   0.f,        0.f,            100.f,           40.f,          false,      30000,          FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_MONK_BREATH_FIRE,               FSBSpellType::Damage,   0.f,        0.f,            100.f,           2.f,           false,      15000,          FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_MONK_KEG_SMASH,                 FSBSpellType::Damage,   0.f,        0.f,            100.f,           15.f,          false,      8000,           FSB_RoleMask::FSB_ROLEMASK_TANK },

    { SPELL_MONK_BLACKOUT_KICK,             FSBSpellType::Damage,   0.f,        0.f,            80.f,            2.f,           false,      4000,           FSB_RoleMask::FSB_ROLEMASK_TANK },
    { SPELL_MONK_DISABLE,                   FSBSpellType::Damage,   0.15f,      0.f,            40.f,            2.f,           false,      1000,           FSB_RoleMask::FSB_ROLEMASK_TANK },


    //HEAL
    { SPELL_MONK_SOOTHING_MIST,             FSBSpellType::Heal,     0.f,        75.f,           100.f,           40.f,          false,      8000,           FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_MONK_EXPEL_HARM,                FSBSpellType::Heal,     0.15f,      40.f,           100.f,           0.f,           true,       15000,          FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_MONK_RENEWING_MIST,             FSBSpellType::Heal,     0.02f,      75.f,           100.f,           40.f,          false,      5000,           FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_MONK_VIVIFY,                    FSBSpellType::Heal,     0.03f,      50.f,           100.f,           40.f,          false,      2000,           FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_MONK_ENVELOPING_MIST,           FSBSpellType::Heal,     0.f,        70.f,           80.f,            40.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_MONK_SHEILUN_GIFT,              FSBSpellType::Heal,     0.f,        60.f,           80.f,            40.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_MONK_LIFE_COCOON,               FSBSpellType::Heal,     0.f,        30.f,           50.f,            40.f,          false,      120000,         FSB_RoleMask::FSB_ROLEMASK_HEALER },

    // mass heal
    { SPELL_MONK_RESTORAL,                  FSBSpellType::Heal,     0.f,        100.f,          50.f,            0.f,           true,       180000,         FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_MONK_REVIVAL,                   FSBSpellType::Heal,     0.f,        100.f,          50.f,            0.f,           true,       180000,         FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_MONK_CELESTIAL_CONDUIT,         FSBSpellType::Heal,     0.05f,      100.f,          50.f,            0.f,           true,       90000,          FSB_RoleMask::FSB_ROLEMASK_HEALER },

    // cc
    { SPELL_MONK_SPINNING_CRANE,            FSBSpellType::Damage,   0.1f,       0.f,            100.f,           6.f,           false,      1000,           FSB_RoleMask::FSB_ROLEMASK_HEALER },

    { SPELL_MONK_BLACKOUT_KICK,             FSBSpellType::Damage,   0.f,        0.f,            80.f,            2.f,           false,      4000,           FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_MONK_RUSHING_WIND_KICK,         FSBSpellType::Damage,   0.02f,      0.f,            80.f,            2.f,           false,      10000,          FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_MONK_SUMMON_SERPENT_STATUE,     FSBSpellType::Damage,   0.05f,      0.f,            50.f,            40.f,          false,      10000,          FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_MONK_INVOKE_CHIJI,              FSBSpellType::Damage,   0.f,        0.f,            30.f,            40.f,          false,      120000,         FSB_RoleMask::FSB_ROLEMASK_HEALER },
    { SPELL_MONK_INVOKE_YULON,              FSBSpellType::Damage,   0.f,        0.f,            30.f,            40.f,          false,      120000,         FSB_RoleMask::FSB_ROLEMASK_HEALER },

    //DPS
    { SPELL_MONK_TIGER_LUST,                FSBSpellType::Heal,     0.f,        100.f,          100.f,           20.f,          false,      30000,          FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_MONK_SOOTHING_MIST_CHI,         FSBSpellType::Heal,     0.2f,       70.f,           100.f,           40.f,          false,      1000,           FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },

    { SPELL_MONK_PARALYSIS_CHI,             FSBSpellType::Damage,   0.f,        0.f,            100.f,           20.f,          false,      45000,          FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },

    { SPELL_MONK_BLACKOUT_KICK_CHI,         FSBSpellType::Damage,   0.f,        0.f,            80.f,            2.f,           false,      4000,           FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_MONK_TIGER_PALM_CHI,            FSBSpellType::Damage,   0.f,        0.f,            80.f,            2.f,           false,      1000,           FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },


    { SPELL_MONK_STRIKE_WINDLORD,           FSBSpellType::Damage,   0.f,        0.f,            100.f,           9.f,           false,      35000,          FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_MONK_SLICING_WINDS_1,           FSBSpellType::Damage,   0.4f,       0.f,            100.f,           2.f,           false,      30000,          FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_MONK_FISTS_FURY,                FSBSpellType::Damage,   0.f,        0.f,            100.f,           8.f,           false,      24000,          FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_MONK_RISING_SUN_KICK,           FSBSpellType::Damage,   0.40f,      0.f,            60.f,            2.f,           false,      10000,          FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_MONK_RUSHING_WIND,              FSBSpellType::Damage,   0.f,        0.f,            60.f,            6.f,           false,      6000,           FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
    { SPELL_MONK_SPINNING_CRANE,            FSBSpellType::Damage,   0.40f,      0.f,            60.f,            6.f,           false,      1000,           FSB_RoleMask::FSB_ROLEMASK_MELEE_DAMAGE },
};

namespace FSBMonk
{
    void HandleOnSpellCast(Creature* bot, uint32 spellId)
    {
        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return;

        auto botRole = baseAI->botRole;

        switch (spellId)
        {
        case SPELL_MONK_SLICING_WINDS_1:
            if (Unit* target = bot->GetVictim())
            {
                FSBSpells::BotCastSpell(bot, SPELL_MONK_SLICING_WINDS_2, target);
                FSBSpells::BotCastSpell(bot, SPELL_MONK_SLICING_WINDS_3, target);
            }
            break;

        case SPELL_MONK_BLACKOUT_KICK_CHI:
            if (botRole == FSB_ROLE_MELEE_DAMAGE)
                bot->ModifyPower(POWER_CHI, 1, true);
            break;

        case SPELL_MONK_TIGER_PALM_CHI:
            if (botRole == FSB_ROLE_MELEE_DAMAGE)
                bot->ModifyPower(POWER_CHI, 2, true);
            break;

        case SPELL_MONK_PURIFYING_BREW:
            bot->ModifyHealth(bot->GetMaxHealth() * 0.08f);
            break;

        case SPELL_MONK_CELESTIAL_CONDUIT:
            FSBSpells::BotCastSpell(bot, SPELL_MONK_CELESTIAL_HEAL, bot);
            break;

        default:
            break;
        }
    }

    bool BotOnAuraApplied(Creature* bot, AuraApplication const* aurApp, bool applied, FSBBotStats& /*botStats*/)
    {
        if (!bot)
            return false;

        if (!aurApp || !aurApp->GetBase())
            return false;

        switch (aurApp->GetBase()->GetId())
        {
        case SPELL_MONK_FORTIFYING_BREW:
        {
            float hpPct = bot->GetPctModifierValue(UNIT_MOD_HEALTH, TOTAL_PCT);

            if (applied)
            {
                bot->SetStatPctModifier(UNIT_MOD_HEALTH, TOTAL_PCT, hpPct + 0.2f);
                bot->ModifyHealth(bot->GetMaxHealth() * 0.2f);
            }
            else if (!applied)
            {
                bot->SetStatPctModifier(UNIT_MOD_HEALTH, TOTAL_PCT, hpPct - 0.2f);
            }
            FSBStats::RecalculateStats(bot, false, false);
            return true;
        }
        default:
            return false;
        }
    }

    bool BotHasFortifyingBrew(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        if (bot->HasAura(SPELL_MONK_FORTIFYING_BREW))
            return true;

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

        auto botRole = baseAI->botRole;
        uint32 spellId = SPELL_MONK_VIVIFY;
        if (botRole == FSB_ROLE_MELEE_DAMAGE)
            spellId = SPELL_MONK_SOOTHING_MIST_CHI;

        uint32 now = getMSTime();

        if (player->GetHealthPct() <= 50)
        {
            FSBSpells::BotCastSpell(bot, spellId, player);
            baseAI->botGlobalCooldown = now + 1500;

            TC_LOG_DEBUG("scripts.fsb.ooc", "FSB: Monk BotOOCHealOwner Bot: {} Player Heal < 50", bot->GetName());

            return true;

        }

        return false;
    }

    void SetSerpentStatueTarget(Creature* bot, ObjectGuid targetGuid)
    {
        if (!bot || targetGuid.IsEmpty())
            return;

        if (Creature* statue = bot->FindNearestCreature(Creatures::NPC_JADE_SERPENT_STATUE, 40.f))
            statue->AI()->SetGUID(targetGuid, 0);
    }
}
