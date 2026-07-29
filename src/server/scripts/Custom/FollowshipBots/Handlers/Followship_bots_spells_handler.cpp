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

#include "Containers.h"
#include "Log.h"
#include "Map.h"
#include "SpellAuras.h"
#include "SpellHistory.h"
#include "SpellInfo.h"

#include "Followship_bots_mgr.h"
#include "Followship_bots_utils.h"

#include "Followship_bots_db.h"
#include "Followship_bots_group_handler.h"
#include "Followship_bots_powers_handler.h"
#include "Followship_bots_spells_handler.h"

std::unordered_map<FSB_Class, FSBSpellTable const*> sBotSpellTables;

namespace FSBSpells
{
    void HandleOnSpellCast(Creature* bot, FSB_Class botClass, uint32 spellId)
    {
        if (!bot || !spellId)
            return;

        HandleOnSpellCastGeneric(bot, spellId);

        switch (botClass)
        {
        case FSB_Class::Warrior:
            FSBWarrior::HandleOnSpellCast(bot, spellId);
            break;
        case FSB_Class::Priest:
            break;
        case FSB_Class::Monk:
            FSBMonk::HandleOnSpellCast(bot, spellId);
            break;
        case FSB_Class::Rogue:
            break;
        case FSB_Class::Druid:
            FSBDruid::HandleOnSpellCast(bot, spellId);
            break;
        case FSB_Class::Paladin:
            FSBPaladin::HandleOnSpellCast(bot, spellId);
            break;
        case FSB_Class::Hunter:
            break;
        case FSB_Class::Warlock:
            FSBWarlock::HandleOnSpellCast(bot, spellId);
            break;
        default:
            break;
        }

    }

    void HandleOnSpellCastGeneric(Creature* bot, uint32 spellId)
    {
        if (!bot || !spellId)
            return;

        // Health potions
        switch (spellId)
        {
        case 439:
            bot->ModifyHealth(120);
            break;
        case 440:
            bot->ModifyHealth(160);
            break;
        case 4042:
            bot->ModifyHealth(500);
            break;
        case 17534:
            bot->ModifyHealth(650);
            break;
        case 28495:
            bot->ModifyHealth(800);
            break;
        case 43185:
            bot->ModifyHealth(1000);
            break;
        default:
            break;
        }
    }

    void InitBotSpellTables()
    {
        sBotSpellTables[FSB_Class::Priest] = &PriestSpellsTable;
        sBotSpellTables[FSB_Class::Mage] = &MageSpellsTable;
        sBotSpellTables[FSB_Class::Warrior] = &WarriorSpellsTable;
        sBotSpellTables[FSB_Class::Paladin] = &PaladinSpellsTable;
        sBotSpellTables[FSB_Class::Warlock] = &WarlockSpellsTable;
        sBotSpellTables[FSB_Class::Druid] = &DruidSpellsTable;
        sBotSpellTables[FSB_Class::Rogue] = &RogueSpellsTable;
        sBotSpellTables[FSB_Class::Hunter] = &HunterSpellsTable;
        sBotSpellTables[FSB_Class::Monk] = &MonkSpellsTable;
        sBotSpellTables[FSB_Class::Shaman] = &ShamanSpellsTable;
    }

    void InitSpellRuntime(Creature* bot, std::vector<FSBSpellRuntime>& _runtimeSpells)
    {
        _runtimeSpells.clear();

        FSB_Class botClass = FSBMgr::Get()->GetBotClassForEntry(bot->GetEntry());
        auto table = GetBotSpellTableForClass(botClass);
        TC_LOG_DEBUG("scripts.fsb.spells", "FSB: InitSpellRuntime() Bot: {} has Class: {}", bot->GetName(), botClass);

        if (!table)
            return;

        for (FSBSpellDefinition const& def : *table)
        {
            FSBSpellRuntime runtime;
            runtime.def = &def;
            runtime.nextReadyMs = 0;
            _runtimeSpells.push_back(runtime);
        }
    }

    FSBSpellTable const* GetBotSpellTableForClass(FSB_Class botClass)
    {
        auto itr = sBotSpellTables.find(botClass);
        if (itr == sBotSpellTables.end())
        {
            TC_LOG_DEBUG("scripts.ai.fsb", "FSB: SpellTableForClass not found");
            return nullptr;
        }

        return itr->second;
    }

    std::vector<FSBSpellRuntime*> BotGetAvailableSpells(Creature* bot, std::vector<FSBSpellRuntime>& runtimeSpells, FSBSpellType desiredType, bool requireSelfCast)
    {
        std::vector<FSBSpellRuntime*> available;
        FSB_Roles botRole = FSBMgr::Get()->GetRole(bot);
        uint32 botRoleMask = RoleToMask(botRole);
        uint32 now = getMSTime();

        for (auto& runtime : runtimeSpells)
        {
            FSBSpellDefinition const* def = runtime.def;
            if (!def)
                continue;

            SpellInfo const* spellInfo =
                sSpellMgr->GetSpellInfo(def->spellId, bot->GetMap()->GetDifficultyID());
            if (!spellInfo)
                continue;

            // 1. Spell type filter
            if (desiredType != FSBSpellType::Any &&
                def->type != desiredType)
                continue;

            // 2. Self-cast filter
            if (requireSelfCast && !def->isSelfCast)
                continue;


            // Role check (STATIC)
            if (def->allowedRoles != FSB_ROLEMASK_ANY &&
                (def->allowedRoles & botRoleMask) == 0)
                continue;

            // Per-spell cooldown (RUNTIME)
            if (runtime.nextReadyMs > now)
                continue;


            //TC_LOG_DEBUG("scripts.ai.fsb", "Bot: {} with role: {} has available spell: {}", bot->GetName(), botRole, FSBSpellsUtils::GetSpellName(def->spellId));
            available.push_back(&runtime);

        }

        return available;
    }

    FSBSpellRuntime* SelectBestHealSpell(Creature* bot, const std::vector<FSBSpellRuntime*>& heals, Unit* target)
    {
        if (!target || !target->IsInWorld() || target->IsDuringRemoveFromWorld() || !target->IsAlive())
            return nullptr;

        float hpPct = target->GetHealthPct();

        FSBSpellRuntime* best = nullptr;
        float bestScore = -1.f;

        for (auto* runtime : heals)
        {
            auto* def = runtime->def;

            if (!FSBSpellsUtils::CheckSpellContextRequirements(bot, def->spellId, target))
                continue;

            // Check if aura present
            if (target->HasAura(def->spellId))
                continue;

            // Check HP threshold
            if (hpPct > def->hpThreshold)
                continue;

            // Chance roll
            if (urand(0, 99) > def->chance)
                continue;

            // Score: lower threshold = more urgent
            float score = 100.f - def->hpThreshold;

            if (score > bestScore)
            {
                bestScore = score;
                best = runtime;
            }
        }

        return best;
    }

    FSBSpellRuntime* SelectRandomHealSpell(Creature* bot, const std::vector<FSBSpellRuntime*>& heals, Unit* target)
    {
        if (!target || !target->IsInWorld() || target->IsDuringRemoveFromWorld() || !target->IsAlive())
            return nullptr;

        float hpPct = target->GetHealthPct();

        std::vector<FSBSpellRuntime*> validHeals;

        for (auto* runtime : heals)
        {
            if (!runtime)
                continue;

            auto* def = runtime->def;
            if (!def)
                continue;

            if (def->isSelfCast && target != bot)
                continue;

            if (!FSBSpellsUtils::CheckSpellContextRequirements(bot, def->spellId, target))
                continue;

            if (target->HasAura(def->spellId))
                continue;

            if (hpPct > def->hpThreshold)
                continue;

            validHeals.push_back(runtime);
        }

        if (validHeals.empty())
            return nullptr;

        Trinity::Containers::RandomShuffle(validHeals);

        for (auto* runtime : validHeals)
        {
            if (urand(0, 99) <= runtime->def->chance)
                return runtime;
        }

        return nullptr;
    }

    FSBSpellRuntime* SelectBestDamageSpell(Creature* bot, const std::vector<FSBSpellRuntime*>& damageSpells, Unit* target)
    {
        if (!bot || !bot->IsAlive())
            return nullptr;

        if (!target || !target->IsAlive())
            return nullptr;

        if (damageSpells.empty())
        {
            TC_LOG_DEBUG("scripts.ai.fsb", "FSB: BotSelectSpell - no available spell");
            return nullptr;
        }

        // =========================================================
        // ================== BUILD SPELL POOL =====================
        // =========================================================

        std::vector<FSBSpellRuntime*> spellPool;

        for (FSBSpellRuntime* runtime : damageSpells)
        {
            if (!runtime || !runtime->def)
                continue;

            SpellInfo const* info = sSpellMgr->GetSpellInfo(runtime->def->spellId, DIFFICULTY_NONE);
            auto costs = info->CalcPowerCost(bot, info->GetSchoolMask());
            int32 amount = 0;
            if (!costs.empty())
            {
                amount = costs[0].Amount;   // usually the primary cost
            }

            if (bot->GetPower(bot->GetPowerType()) < amount)
            {
                //TC_LOG_DEBUG("scripts.ai.fsb", "Bot: {} has not enough power for spell: {}", bot->GetName(), FSBSpellsUtils::GetSpellName(runtime->def->spellId));
                continue;
            }

            if (!FSBSpellsUtils::CheckSpellContextRequirements(bot, runtime->def->spellId, target))
                continue;

            // Check target has aura
            if (target->HasAura(runtime->def->spellId))
                continue;

            if (runtime->def->type == FSBSpellType::Damage)
                spellPool.push_back(runtime);
        }

        if (spellPool.empty())
        {
            TC_LOG_DEBUG("scripts.ai.fsb", "FSB: SelectSpell - damage spell pool empty after filtering");
            return nullptr;
        }

        //TC_LOG_DEBUG("scripts.ai.fsb", "FSB: SelectSpell - spellPool size after filtering: {}", spellPool.size());

        // =========================================================
        // ===================== SPELLS PICK =======================
        // =========================================================
        Trinity::Containers::RandomShuffle(spellPool);

        for (FSBSpellRuntime* runtime : spellPool)
        {
            FSBSpellDefinition const* spell = runtime->def;

            if (!runtime || !runtime->def)
                continue;

            if (spell->isSelfCast)
                target = bot;

            // Chance roll
            uint32 roll = urand(0, 100);
            if (roll > spell->chance)
            {
                //TC_LOG_DEBUG("scripts.ai.fsb", "FSB: SpellSkip - {} chance failed (roll={} chance={})", spell->spellId, roll, spell->chance);
                continue;
            }

            // ================= SUCCESS =================

            /*
            TC_LOG_DEBUG("scripts.ai.fsb",
                "FSB: SpellSelect SUCCESS - spell={} type={} target={} hp={} threshold={}",
                spell->spellId,
                spell->type == FSBSpellType::Heal ? "HEAL" : "DAMAGE",
                target->GetName(),
                target->GetHealthPct(),
                spell->hpThreshold
            );
            */

            return runtime;
        }

        TC_LOG_DEBUG("scripts.ai.fsb", "FSB: SelectSpell - no valid spell found after evaluation");
        return nullptr;
    }

    bool BotTryDispel(Creature* bot)
    {
        if (!bot)
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return false;

        auto cls = baseAI->botClass;
        auto role = baseAI->botRole;

        auto it = DispelTable.find(cls);
        if (it == DispelTable.end())
            return false; // class cannot dispel anything

        const DispelAbility& ability = it->second;

        if (ability.spellId == SPELL_MONK_DETOX_HEAL && role != FSB_ROLE_TANK)
            return false;

        if (ability.spellId == SPELL_SHAMAN_PURIFY_SPIRIT && role != FSB_ROLE_HEALER)
            return false;

        if (!FSBSpellsUtils::IsSpellReady(ability.spellId))
            return false;

        Unit* target = FSBGroup::BotGetDispelMember(bot, ability);
        if (!target)
            return false;

        if (bot->GetDistance(target) > 30.0f)
            return false;

        return BotCastSpellWithCooldown(bot, ability.spellId, target, ability.cooldown);
    }

    bool BotTryOffensiveDispel(Creature* bot)
    {
        if (!bot)
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return false;

        auto cls = baseAI->botClass;
        auto role = baseAI->botRole;

        auto it = OffensiveDispelTable.find(cls);
        if (it == OffensiveDispelTable.end())
            return false; // class cannot offensively dispel

        const OffensiveDispelAbility& ability = it->second;

        Unit* target = bot->GetVictim();
        if (!target || !target->IsInWorld() || target->IsDuringRemoveFromWorld() || !target->IsAlive())
            return false;

        // Check if target has a buff we can remove/steal
        Aura* buff = FSBSpellsUtils::FindEnemyBuffToDispel(target);
        if (!buff)
            return false;

        // Optional: avoid dispelling trivial buffs
        if (buff->GetSpellInfo()->Dispel != DISPEL_MAGIC)
            return false;

        if (ability.spellId == SPELL_MONK_DETOX_ATTACK && role != FSB_ROLE_HEALER)
            return false;

        // Cast the spell
        if (!target || !target->IsInWorld() || target->IsDuringRemoveFromWorld() || !target->IsAlive())
            return false;
        return BotCastSpell(bot, ability.spellId, target);
    }

    bool BotCastSpell(Creature* bot, uint32 spellId, Unit* target)
    {
        if (!bot || !bot->IsInWorld() || bot->IsDuringRemoveFromWorld() || !bot->IsAlive())
            return false;

        if (!target || !target->IsInWorld() || target->IsDuringRemoveFromWorld() || !target->IsAlive())
            return false;

        if (!spellId)
            return false;

        bot->SetFacingToObject(target, true);

        SpellCastResult result = bot->CastSpell(target, spellId);

        if (result == SPELL_CAST_OK)
        {
            TC_LOG_DEBUG("scripts.ai.fsb", "FSB Bot {} casted spell {} on target {}", bot->GetName(), FSBSpellsUtils::GetSpellName(spellId), target->GetName());

            if (spellId == SPELL_MONK_SOOTHING_MIST || spellId == SPELL_MONK_SOOTHING_MIST_CHI)
                FSBMonk::SetSerpentStatueTarget(bot, target->GetGUID());

            return true;
        }
        else TC_LOG_DEBUG("scripts.ai.fsb", "FSB Bot {} Unable to cast spell {} on target {} with result {}", bot->GetName(), FSBSpellsUtils::GetSpellName(spellId), target->GetName(), result);

        return false;
    }

    SpellCastResult BotCastSpellWithResult(Creature* bot, uint32 spellId, Unit* target)
    {
        if (!bot || !bot->IsInWorld() || bot->IsDuringRemoveFromWorld() || !bot->IsAlive())
            return SPELL_FAILED_ERROR;

        if (!target || !target->IsInWorld() || target->IsDuringRemoveFromWorld() || !target->IsAlive())
            return SPELL_FAILED_BAD_TARGETS;

        if (!spellId)
            return SPELL_FAILED_NOT_KNOWN;

        bot->SetFacingToObject(target, true);

        return bot->CastSpell(target, spellId);
    }

    bool BotCastSpellOnDeadTarget(Creature* bot, uint32 spellId, Unit* target)
    {
        if (!bot || !bot->IsInWorld() || bot->IsDuringRemoveFromWorld() || !bot->IsAlive())
            return false;

        if (!target || !target->IsInWorld() || target->IsDuringRemoveFromWorld())
            return false;

        if (!spellId)
            return false;

        bot->SetFacingToObject(target, true);

        SpellCastResult result = bot->CastSpell(target, spellId);

        if (result == SPELL_CAST_OK)
        {
            TC_LOG_DEBUG("scripts.ai.fsb", "FSB Bot {} casted spell {} on dead target {}", bot->GetName(), FSBSpellsUtils::GetSpellName(spellId), target->GetName());
            return true;
        }
        else TC_LOG_DEBUG("scripts.ai.fsb", "FSB Bot {} Unable to cast spell {} on dead target {} with result {}", bot->GetName(), FSBSpellsUtils::GetSpellName(spellId), target->GetName(), result);

        return false;
    }

    bool BotCastSpellatLocation(Creature* bot, uint32 spellId, const Position& pos)
    {
        if (!bot)
            return false;

        if (!spellId)
            return false;

        // Face the location
        bot->SetFacingToPoint(pos, true);

        SpellCastResult result = bot->CastSpell(pos, spellId);

        if (result == SPELL_CAST_OK)
        {
            TC_LOG_DEBUG("scripts.fsb.spells", "FSB Bot {} casted spell {} at location {}", bot->GetName(), FSBSpellsUtils::GetSpellName(spellId), pos.ToString());
            return true;
        }
        else TC_LOG_DEBUG("scripts.fsb.spells", "FSB Bot {} Unable to cast spell {} at location {} with result {}", bot->GetName(), FSBSpellsUtils::GetSpellName(spellId), pos.ToString(), result);

        return false;
    }

    bool BotCastSpellWithCooldown(Creature* bot, uint32 spellId, Unit* target, uint32 cooldown)
    {
        if (!bot || !target)
            return false;

        if (!spellId)
            return false;

        bot->SetFacingToObject(target, true);

        SpellCastResult result = bot->CastSpell(target, spellId, true);

        if (result == SPELL_CAST_OK)
        {
            FSBSpellsUtils::PutSpellOnCooldown(spellId, cooldown);
            TC_LOG_DEBUG("scripts.ai.fsb", "FSB Bot {} casted spell {} on target {}", bot->GetName(), FSBSpellsUtils::GetSpellName(spellId), target->GetName());
            return true;
        }

        return false;
    }

    bool BotCastSpellatLocationWithCooldown(Creature* bot, uint32 spellId, const Position& pos, uint32 cooldown)
    {
        if (!bot || !spellId)
            return false;

        bot->SetFacingToPoint(pos, true);

        SpellCastResult result = bot->CastSpell(pos, spellId);

        if (result == SPELL_CAST_OK)
        {
            FSBSpellsUtils::PutSpellOnCooldown(spellId, cooldown);
            TC_LOG_DEBUG("scripts.ai.fsb", "FSB Bot {} casted spell {} at location {}", bot->GetName(), FSBSpellsUtils::GetSpellName(spellId), pos.ToString());
            return true;
        }
        else TC_LOG_DEBUG("scripts.ai.fsb", "FSB Bot {} Unable to cast spell {} at location {} with result {}", bot->GetName(), FSBSpellsUtils::GetSpellName(spellId), pos.ToString(), result);

        return false;
    }

    Position GetOffensiveAoEPosition(Creature* bot)
    {
        if (Unit* victim = bot->GetVictim())
            return victim->GetPosition();
        return bot->GetPosition();
    }

    Position GetHealingAoEPosition(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return Position{};

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return Position{};

        auto group = FSBGroup::ResolveGroup(bot, baseAI->botLogicalGroup);
        if (group.empty())
            return Position{};

        float sumX = 0.f, sumY = 0.f, sumZ = 0.f;
        uint32 count = 0;
        for (Unit* member : group)
        {
            if (member && member->IsAlive() && member->GetHealthPct() < 85.f)
            {
                sumX += member->GetPositionX();
                sumY += member->GetPositionY();
                sumZ += member->GetPositionZ();
                ++count;
            }
        }
        if (count == 0)
            return bot->GetPosition();
        return Position{ sumX / count, sumY / count, sumZ / count };
    }
}

namespace FSBSpellsDB
{
    static std::vector<FSBSpellDefinition> sBotDBSpells;

    bool LoadBotSpellsFromDB()
    {
        if (!FSBUtilsDB::LoadBotSpellsFromDB(sBotDBSpells))
        {
            TC_LOG_ERROR("scripts.fsb.spells", "FSB: Failed to load bot spells from DB");
            return false;
        }
        return true;
    }

    std::vector<FSBSpellDefinition> const& GetBotSpellCache()
    {
        return sBotDBSpells;
    }

    uint32 GetEffectiveCooldown(Creature* bot, uint32 spellId, uint32 dbCooldownMs)
    {
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId, DIFFICULTY_NONE);
        if (!spellInfo)
            return 0;

        uint32 coreCooldownMs = static_cast<uint32>(bot->GetSpellHistory()->GetRemainingCooldown(spellInfo).count());
        if (coreCooldownMs > 0)
            return coreCooldownMs;

        return dbCooldownMs;
    }

    bool IsSpellReady(Creature* bot, FSBSpellDefinition const& def)
    {
        return GetEffectiveCooldown(bot, def.spellId, def.cooldownMs) == 0;
    }

    std::vector<FSBSpellDefinition const*> QuerySpells(FSBSpellQuery const& query, Creature* bot)
    {
        std::vector<FSBSpellDefinition const*> result;
        if (!bot)
            return result;

        uint32 botRoleMask = RoleToMask(FSBMgr::Get()->GetRole(bot));

        for (FSBSpellDefinition const& def : sBotDBSpells)
        {
            if (query.type != FSBSpellType::Any && def.type != query.type)
                continue;

            if (def.allowedClass != FSB_Class::None &&
                def.allowedClass != FSBMgr::Get()->GetBotClassForEntry(bot->GetEntry()))
                continue;

            if (def.allowedRace != FSB_Race::None &&
                def.allowedRace != FSBMgr::Get()->GetBotRaceForEntry(bot->GetEntry()))
                continue;

            if (def.allowedRoles != FSB_ROLEMASK_ANY && (def.allowedRoles & botRoleMask) == 0)
                continue;

            if (!query.includeSelfCast && def.isSelfCast)
                continue;

            if (query.requireLocationSpell && !def.isLocationSpell)
                continue;

            if (query.respectCooldown && !IsSpellReady(bot, def))
                continue;

            if (query.excludeAlreadyPresentAura && query.target && query.target->HasAura(def.spellId))
                continue;

            result.push_back(&def);
        }

        return result;
    }
}
