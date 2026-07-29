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
#include "MotionMaster.h"

#include "Followship_bots_config.h"
#include "Followship_bots_mgr.h"
#include "Followship_bots_utils.h"

#include "Followship_bots_chatter_handler.h"
#include "GenAI_chatter_prompts.h"
#include "Followship_bots_combat_handler.h"
#include "Followship_bots_dungeon_handler.h"
#include "Followship_bots_events_handler.h"
#include "Followship_bots_group_handler.h"
#include "Followship_bots_incombat_handler.h"
#include "Followship_bots_movement_handler.h"
#include "Followship_bots_powers_handler.h"
#include "Followship_bots_spells_handler.h"
#include "Followship_bots_battleground_handler.h"

namespace FSBIC
{
    bool BotICActions(Creature* bot, uint32& globalCooldown, bool& botCastedCombatBuffs)
    {
        if (!bot || !bot->IsAlive())
            return false;

        if (!bot->IsInCombat())
            return false;

        if (bot->HasUnitState(UNIT_STATE_CASTING))
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return false;

        if (FSBDungeon::CheckDungeonInCombatHandlingNeeded(bot))
            return true;

        //1. IC Potions
        // These can be cast instant with no GCD
        if (BotICPotions(bot))
            return true;

        //2. IC (initial)Buffs
        // These are cast when combat starts
        if (BotICInitialBuffs(bot, globalCooldown, botCastedCombatBuffs))
            return true;

        //3. IC Go melee when OOM
        if (BotICMeleeMode(bot))
            return true;

        if (BotICHealSelf(bot))
            return true;

        if (BotICHealGroup(bot))
            return true;

        if (BotICHealBattlegroundAllies(bot))
            return true;

        if (BotICTryDispel(bot))
            return true;

        if (BotICTryOffensiveDispel(bot))
            return true;

        if (BotICTryOffensiveSpell(bot))
            return true;

        if (BotICRandomActions(bot))
            return true;

        return false;
    }

    bool BotICRandomActions(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        if (BotICAnnounceLowManaHealth(bot))
            return true;

        return false;
    }

    bool BotICAnnounceLowManaHealth(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return false;
        auto& botLowMana = baseAI->botAnnouncedLowMana;
        auto& botLowHealth = baseAI->botAnnouncedLowHealth;
        auto& botVeryLowHealth = baseAI->botAnnouncedVeryLowHealth;

        FSB_ChatterCategory emoteReply = FSB_ChatterCategory::chatter_none;

        bool check = false;

        if (!botLowMana)
        {
            if (bot->GetPowerType() == POWER_MANA && bot->GetPowerPct(POWER_MANA) <= 10)
            {
                botLowMana = true;
                emoteReply = FSB_ChatterCategory::emote_oom;
                check = true;
            }
        }

        else if (!botLowHealth && bot->GetHealthPct() <= 50)
        {
            botLowHealth = true;
            emoteReply = FSB_ChatterCategory::emote_help;
            check = true;
        }

        else if (!botVeryLowHealth && bot->GetHealthPct() <= 20)
        {
            botLowHealth = true;
            botVeryLowHealth = true;
            emoteReply = FSB_ChatterCategory::emote_heal;
            check = true;
        }

        if (check)
        {
            switch (emoteReply)
            {
                case FSB_ChatterCategory::emote_oom:
                    FSBGenAIPrompts::DispatchBotDistress(bot, FSBGenAIPrompts::FSB_DistressContext::OutOfMana);
                    break;
                case FSB_ChatterCategory::emote_help:
                    FSBGenAIPrompts::DispatchBotDistress(bot, FSBGenAIPrompts::FSB_DistressContext::LowHealth);
                    break;
                case FSB_ChatterCategory::emote_heal:
                    FSBGenAIPrompts::DispatchBotDistress(bot, FSBGenAIPrompts::FSB_DistressContext::CriticalHealth);
                    break;
                default:
                    break;
            }

            return true;
        }

        return false;
        
    }

    bool BotICTryOffensiveSpell(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        if (FSBDungeon::ShouldPreserveMana(bot))
            return false;

        Unit* target = bot->GetVictim();
        if (!target || !target->IsInWorld() || target->IsDuringRemoveFromWorld() || !target->IsAlive())
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return false;

        auto& globalCooldown = baseAI->botGlobalCooldown;
        uint32 now = getMSTime();

        if (!FSBSpellsUtils::CanCastNow(bot, now, globalCooldown))
            return false;

        auto& runtimeSpells = baseAI->botRuntimeSpells;

        auto spells = FSBSpells::BotGetAvailableSpells(bot, runtimeSpells, FSBSpellType::Damage, false);

        FSBSpellRuntime* dmgSpell = FSBSpells::SelectBestDamageSpell(bot, spells, target);
        if (!dmgSpell || !dmgSpell->def)
            return false;

        if (dmgSpell && dmgSpell->def->isSelfCast)
            target = bot;

        float dist = bot->GetDistance(target);
        float spellDist = dmgSpell->def->dist;
        if (dmgSpell && spellDist && target)
        {
            if (dist > spellDist)
            {
                if (!target || !target->IsInWorld() || target->IsDuringRemoveFromWorld() || !target->IsAlive())
                    return false;

                // Move into spell range
                if (FSBMovement::EnsureInRange(bot, target, spellDist))
                {
                    TC_LOG_DEBUG("scripts.fsb.combat", "FSB: BotICTryOffensiveSpell Bot {} target too far for spell {} with distances ({}/{}). Trying to chase.", bot->GetName(), dmgSpell->def->spellId, dist, spellDist);
                    return false;
                }
            }
        }

        if (FSBSpellsUtils::IsCrowdControlWithRandomTarget(dmgSpell->def->spellId))
            target = FSBCombatUtils::GetRandomAttacker(bot);

        if (target && (!target->IsInWorld() || target->IsDuringRemoveFromWorld() || !target->IsAlive()))
            return false;

        if (dmgSpell && target)
        {
            if (dmgSpell->def->manaCostOverride != 0.f && !FSBPowers::SpendPowerPct(bot, dmgSpell->def->manaCostOverride))
                return false; // not enough mana

            bool castSuccess = false;

            if (dmgSpell->def->isLocationSpell)
            {
                Position pos = FSBSpells::GetOffensiveAoEPosition(bot);
                castSuccess = FSBSpells::BotCastSpellatLocation(bot, dmgSpell->def->spellId, pos);
            }
            else
            {
                if (!target || !target->IsInWorld() || target->IsDuringRemoveFromWorld() || !target->IsAlive())
                    return false;

                castSuccess = FSBSpells::BotCastSpell(bot, dmgSpell->def->spellId, target);
            }

            if (castSuccess)
            {
                dmgSpell->nextReadyMs = now + dmgSpell->def->cooldownMs;
                globalCooldown = now + 1500;

                if (!target || !target->IsInWorld() || target->IsDuringRemoveFromWorld() || !target->IsAlive())
                    target = nullptr;

                if (target && target == bot)
                {
                    if (urand(0, 99) <= FollowshipBotsConfig::configFSBChatterRate)
                        FSBGenAIPrompts::DispatchBotHeal(bot, bot->GetGUID(), dmgSpell->def->spellId);
                }
                else if (target && target != bot)
                    if (urand(0, 99) <= FollowshipBotsConfig::configFSBChatterRate)
                        FSBGenAIPrompts::DispatchBotCombatSpell(bot, target->GetGUID(), dmgSpell->def->spellId);
                return true;
            }
        }
        return false;
    }

    bool BotICHealGroup(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        if (!FSBSpellsUtils::BotHasHealSpells(bot))
            return false;

        if (FSBDungeon::ShouldDPSInExecutePhase(bot, bot->GetVictim()))
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return false;

        auto& globalCooldown = baseAI->botGlobalCooldown;
        uint32 now = getMSTime();

        if (!FSBSpellsUtils::CanCastNow(bot, now, globalCooldown))
            return false;

        auto& runtimeSpells = baseAI->botRuntimeSpells;
        auto botRole = baseAI->botRole;

        float hpPct = FSBDungeon::IsBotInDungeon(bot) ? DungeonHealPCT : DefaultHealPCT;
        if (botRole == FSB_ROLE_HEALER)
            hpPct = FSBDungeon::IsBotInDungeon(bot) ? DungeonHealPCTHealer : DefaultHealPCTHealer;

        auto healTargets = FSBGroup::BotGetMembersToHeal(bot, hpPct);
        if (healTargets.empty())
            return false;

        auto sortedHealTargets = healTargets;
        if (botRole == FSB_ROLE_HEALER)
            FSBGroup::SortEmergencyTargets(sortedHealTargets);

        Unit* target = sortedHealTargets.front();
        if (!target || !target->IsInWorld() || target->IsDuringRemoveFromWorld() || !target->IsAlive())
            return false;

        auto heals = FSBSpells::BotGetAvailableSpells(bot, runtimeSpells, FSBSpellType::Heal, false);
        FSBSpellRuntime* healSpell = FSBSpells::SelectBestHealSpell(bot, heals, target);

        if (healSpell && target)
        {
            if (healSpell->def->isSelfCast && target != bot)
                return false;
            // check other requirements here

            bool castSuccess = false;

            if (healSpell->def->isLocationSpell)
            {
                Position pos = FSBSpells::GetHealingAoEPosition(bot);
                castSuccess = FSBSpells::BotCastSpellatLocation(bot, healSpell->def->spellId, pos);
            }
            else
            {
                castSuccess = FSBSpells::BotCastSpell(bot, healSpell->def->spellId, target);
            }

            if (castSuccess)
            {
                healSpell->nextReadyMs = now + healSpell->def->cooldownMs;
                baseAI->botGlobalCooldown = now + 1500;
                if (urand(0, 99) <= FollowshipBotsConfig::configFSBChatterRate)
                {
                    if (target == bot)
                        FSBGenAIPrompts::DispatchBotHeal(bot, bot->GetGUID(), healSpell->def->spellId);
                    else
                        FSBGenAIPrompts::DispatchBotHeal(bot, target->GetGUID(), healSpell->def->spellId);
                }
                return true;
            }
        }

        return false;
    }

    bool BotICHealBattlegroundAllies(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        if (!FSBBattleground::IsInBG(bot))
            return false;

        if (!FSBBattleground::IsInProgress(bot))
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return false;

        if (baseAI->botRole != FSB_ROLE_HEALER)
            return false;

        if (!FSBSpellsUtils::BotHasHealSpells(bot))
            return false;

        if (FSBDungeon::ShouldDPSInExecutePhase(bot, bot->GetVictim()))
            return false;

        auto& globalCooldown = baseAI->botGlobalCooldown;
        uint32 now = getMSTime();

        if (!FSBSpellsUtils::CanCastNow(bot, now, globalCooldown))
            return false;

        auto& runtimeSpells = baseAI->botRuntimeSpells;

        float hpPct = 50.0f;

        Unit* target = FSBBattleground::FindBattlegroundAllyToHeal(bot, 40.0f, hpPct);
        if (!target || !target->IsInWorld() || target->IsDuringRemoveFromWorld() || !target->IsAlive())
            return false;

        auto heals = FSBSpells::BotGetAvailableSpells(bot, runtimeSpells, FSBSpellType::Heal, false);
        FSBSpellRuntime* healSpell = FSBSpells::SelectRandomHealSpell(bot, heals, target);

        if (healSpell && target)
        {
            if (healSpell->def->isSelfCast && target != bot)
                return false;

            bool castSuccess = false;

            if (healSpell->def->isLocationSpell)
            {
                Position pos = FSBSpells::GetHealingAoEPosition(bot);
                castSuccess = FSBSpells::BotCastSpellatLocation(bot, healSpell->def->spellId, pos);
            }
            else
            {
                castSuccess = FSBSpells::BotCastSpell(bot, healSpell->def->spellId, target);
            }

            if (castSuccess)
            {
                healSpell->nextReadyMs = now + healSpell->def->cooldownMs;
                baseAI->botGlobalCooldown = now + 1500;
                if (urand(0, 99) <= FollowshipBotsConfig::configFSBChatterRate)
                    FSBGenAIPrompts::DispatchBotHeal(bot, target->GetGUID(), healSpell->def->spellId);
                return true;
            }
        }

        return false;
    }

    bool BotICHealSelf(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        if (!FSBSpellsUtils::BotHasHealSpellsForSelf(bot))
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return false;

        auto& globalCooldown = baseAI->botGlobalCooldown;
        uint32 now = getMSTime();

        if (!FSBSpellsUtils::CanCastNow(bot, now, globalCooldown))
            return false;

        auto& runtimeSpells = baseAI->botRuntimeSpells;

        auto selfHeals = FSBSpells::BotGetAvailableSpells(bot, runtimeSpells, FSBSpellType::Heal, false);

        FSBSpellRuntime* healSpell = FSBSpells::SelectBestHealSpell(bot, selfHeals, bot);

        if (healSpell)
        {
            // Interleave attacks between self-heals unless health is critical
            if (bot->GetHealthPct() > BOT_IC_SELFHEAL_EMERGENCY_HP)
            {
                bool forceAttack = baseAI->botGenericData.consecutiveSelfHeals >= BOT_IC_SELFHEAL_MAX_CONSECUTIVE;
                bool rollAttack = urand(0, 99) < BOT_IC_SELFHEAL_ATTACK_CHANCE;

                if (forceAttack || rollAttack)
                {
                    if (BotICTryOffensiveSpell(bot))
                    {
                        baseAI->botGenericData.consecutiveSelfHeals = 0;
                        return true;
                    }
                    // no attack possible -> fall through and heal
                }
            }

            if (FSBSpells::BotCastSpell(bot, healSpell->def->spellId, bot))
            {
                ++baseAI->botGenericData.consecutiveSelfHeals;
                healSpell->nextReadyMs = now + healSpell->def->cooldownMs;
                baseAI->botGlobalCooldown = now + 1500;
                if (urand(0, 99) <= FollowshipBotsConfig::configFSBChatterRate)
                    FSBGenAIPrompts::DispatchBotHeal(bot, bot->GetGUID(), healSpell->def->spellId);
                return true;
            }
        }
        else
            baseAI->botGenericData.consecutiveSelfHeals = 0;


        return false;
    }

    bool BotICTryDispel(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        if (bot->GetPower(POWER_MANA) < 10)
            return false;

        uint32 now = getMSTime();

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return false;

        auto& globalCooldown = baseAI->botGlobalCooldown;

        if (!FSBSpellsUtils::CanCastNow(bot, now, globalCooldown))
            return false;

        if (FSBSpells::BotTryDispel(bot))
        {
            baseAI->botGlobalCooldown = now + 1500;
            return true;
        }

        return false;
    }

    bool BotICTryOffensiveDispel(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        if (bot->GetPower(POWER_MANA) < 10)
            return false;

        uint32 now = getMSTime();

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return false;

        auto& globalCooldown = baseAI->botGlobalCooldown;

        if (!FSBSpellsUtils::CanCastNow(bot, now, globalCooldown))
            return false;

        if (FSBSpells::BotTryOffensiveDispel(bot))
        {
            baseAI->botGlobalCooldown = now + 1500;
            return true;
        }

        return false;
    }

    bool BotICMeleeMode(Creature* bot)
    {
        if (!bot)
            return false;

        if (bot->GetPowerType() != POWER_MANA)
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());

        if (FSBCombat::ShouldSwitchToMelee(bot))
        {
            baseAI->botMeleeMode = true;
            FSBCombat::EnterMeleeMode(bot);
            return true;
        }
        else baseAI->botMeleeMode = false;

        return false;
    }

    bool BotICInitialBuffs(Creature* bot, uint32 globalCooldown, bool& botCastedCombatBuffs)
    {
        if (!bot)
            return false;

        uint32 now = getMSTime();

        if (!FSBSpellsUtils::CanCastNow(bot, now, globalCooldown))
            return false;

        if (!bot->IsInCombat())
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return false;

        switch (baseAI->botClass)
        {
        case FSB_Class::Priest:
            if(FSBPriest::BotInitialCombatSpells(bot, globalCooldown, botCastedCombatBuffs, baseAI->botRole))
                return true;
            break;
        case FSB_Class::Druid:
            if (FSBDruid::BotInitialCombatSpells(bot, globalCooldown, botCastedCombatBuffs, baseAI->botRole))
                return true;
            break;
        case FSB_Class::Shaman:
            if (FSBShaman::BotInitialCombatSpells(bot))
                return true;
            break;
        default:
            return false;
        }

        return false;
    }

    bool BotICPotions(Creature* bot)
    {
        if (!FollowshipBotsConfig::configFSBUseICPotions)
            return false;

        if (!bot || !bot->IsAlive())
            return false;

        if (!bot->IsInCombat())
            return false;

        if (bot->HasUnitState(UNIT_STATE_CASTING))
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return false;

        // 1. Generic mana potions for bots with mana
        if (bot->GetPowerType() == POWER_MANA && bot->GetPowerPct(POWER_MANA) < BOT_IC_THRESHOLD_POTION_MP)
        {
            if (!baseAI->botGenericData.manaPotionUsed)
            {
                uint32 ManaPotionSpellId = FSBSpellsUtils::GetManaPotionSpellForLevel(bot->GetLevel());

                if (ManaPotionSpellId)
                {
                    // Global Cooldown does NOT apply for potions
                    // Limit of 1 potion per type (MP or HP) per combat 
                    bot->CastSpell(bot, ManaPotionSpellId, false);
                    baseAI->botGenericData.manaPotionUsed = true;

                    std::string spellName = FSBSpellsUtils::GetSpellName(ManaPotionSpellId);

                    if (urand(0, 99) <= FollowshipBotsConfig::configFSBChatterRate)
                        FSBGenAIPrompts::DispatchBotPotion(bot, ManaPotionSpellId, true);

                    TC_LOG_DEBUG("scripts.fsb.combat", "FSB: BotICPotions: Bot {} used potion spell: {}", bot->GetName(), spellName);
                    return true;
                }
            }

        }

        // 2. Generic health potions for non healer bots 
        if (bot->GetHealthPct() < BOT_IC_THRESHOLD_POTION_HP)
        {
            if (FSBUtils::BotIsHealerClass(bot) || baseAI->botGenericData.healthPotionUsed)
                return false;

            uint32 HealthPotionSpellId = 0;
            FSB_Class cls = FSBMgr::Get()->GetBotClassForEntry(bot->GetEntry());

            if (cls == FSB_Class::Warlock)
            {
                HealthPotionSpellId = SPELL_WARLOCK_HEALTHSTONE;
            }
            else HealthPotionSpellId = FSBSpellsUtils::GetHealthPotionSpellForLevel(bot->GetLevel());

            bot->CastSpell(bot, HealthPotionSpellId, false);
            baseAI->botGenericData.healthPotionUsed = true;

            std::string spellName = FSBSpellsUtils::GetSpellName(HealthPotionSpellId);

            if (urand(0, 99) <= FollowshipBotsConfig::configFSBChatterRate)
                FSBGenAIPrompts::DispatchBotPotion(bot, HealthPotionSpellId, false);

            TC_LOG_DEBUG("scripts.fsb.combat", "FSB: BotICPotions: Bot {} used potion spell: {}", bot->GetName(), spellName);
            return true;
        }
        return false;
    }
}
