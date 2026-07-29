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
#include "ObjectAccessor.h"
#include "SpellAuras.h"

#include "Followship_bots_utils.h"
#include "Followship_bots_mgr.h"
#include "Followship_bots_db.h"

#include "Followship_bots_group_handler.h"

namespace FSBGroup
{
    void BuildLogicalBotGroup(Creature* bot, std::vector<ObjectGuid>& outGroup)
    {
        outGroup.clear();

        if (!bot)
            return;

        Player* owner = FSBMgr::Get()->GetBotOwner(bot);
        if (!owner)
            return;

        outGroup.push_back(owner->GetGUID());

        auto botsPtr = FSBMgr::Get()->GetPersistentBotsForPlayer(owner);
        if (!botsPtr)
        {
            TC_LOG_DEBUG("scripts.fsb.general", "FSB: BuildLogicalBotGroup Player has no bots");
            return;
        }

        for (auto const& botData : *botsPtr)
            if (!botData.runtimeGuid.IsEmpty())
                outGroup.push_back(botData.runtimeGuid);        
    }

    // Resolves a stored guid group to valid, alive Unit* for use within a single tick
    std::vector<Unit*> ResolveGroup(WorldObject* context, const std::vector<ObjectGuid>& guids, bool requireAlive)
    {
        std::vector<Unit*> resolved;
        resolved.reserve(guids.size());

        for (const ObjectGuid& guid : guids)
        {
            Unit* unit = ObjectAccessor::GetUnit(*context, guid);
            if (!unit || !unit->IsInWorld() || unit->IsDuringRemoveFromWorld())
                continue;
            if (requireAlive && !unit->IsAlive())
                continue;
            resolved.push_back(unit);
        }

        return resolved;
    }

    Unit* BotGetFirstMemberToAssist(Creature* bot)
    {
        if (!bot || !bot->IsInWorld() || bot->IsDuringRemoveFromWorld())
            return nullptr;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return nullptr;

        auto group = ResolveGroup(bot, baseAI->botLogicalGroup);
        if (group.empty())
            return nullptr;

        Unit* bestTarget = nullptr;
        float lowestHpPct = 100.f;

        for (Unit* member : group)
        {
            if (!member || member == bot)
                continue;

            if (!member->IsAlive() || !member->IsInWorld() || member->IsDuringRemoveFromWorld())
                continue;

            // Case 1: Member is being attacked
            Unit* attacker = member->getAttackerForHelper();
            if (attacker && attacker->IsAlive() && attacker->IsInWorld() && !attacker->IsDuringRemoveFromWorld())
            {
                // Skip CC
                if (!attacker->HasBreakableByDamageCrowdControlAura() &&
                    !member->HasBreakableByDamageCrowdControlAura())
                {
                    float hpPct = member->GetHealthPct();
                    if (hpPct < lowestHpPct)
                    {
                        lowestHpPct = hpPct;
                        bestTarget = attacker;
                    }
                }
            }

            // Case 2: Member is attacking something (victim)
            Unit* victim = member->GetVictim();
            if (victim && victim->IsAlive() && victim->IsInWorld() && !victim->IsDuringRemoveFromWorld())
            {
                // Skip CC
                if (!victim->HasBreakableByDamageCrowdControlAura() &&
                    !member->HasBreakableByDamageCrowdControlAura())
                {
                    float hpPct = member->GetHealthPct();
                    if (hpPct < lowestHpPct)
                    {
                        lowestHpPct = hpPct;
                        bestTarget = victim;
                    }
                }
            }
        }

        return bestTarget;
    }

    Unit* BotGetFirstGroupHealer(Creature* bot)
    {
        if (!bot || !bot->IsInWorld() || bot->IsDuringRemoveFromWorld())
            return nullptr;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return nullptr;

        auto group = ResolveGroup(bot, baseAI->botLogicalGroup);
        if (group.empty())
            return nullptr;

        for (Unit* member : group)
        {
            if (!member || !member->IsAlive())
                continue;

            // Check healer role
            if (member->ToCreature() && FSBUtils::BotIsHealerClass(member->ToCreature()))
            {
                return member; // first healer found
            }
        }

        return nullptr; // no healer in group
    }

    Unit* BotGetFirstGroupTank(Creature* bot)
    {
        if (!bot || !bot->IsInWorld() || bot->IsDuringRemoveFromWorld())
            return nullptr;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return nullptr;

        auto group = ResolveGroup(bot, baseAI->botLogicalGroup);
        if (group.empty())
            return nullptr;

        for (Unit* member : group)
        {
            if (!member || !member->IsAlive())
                continue;

            FSB_Roles role = FSBMgr::Get()->GetRole(member->ToCreature());

            // Check healer role
            if (role == FSB_Roles::FSB_ROLE_TANK)
            {
                return member; // first healer found
            }
        }

        return nullptr; // no healer in group
    }

    Unit* BotGetFirstDeadMember(Creature* bot)
    {
        if (!bot || !bot->IsInWorld() || bot->IsDuringRemoveFromWorld())
            return nullptr;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return nullptr;

        for (const ObjectGuid& guid : baseAI->botLogicalGroup)
        {
            Unit* unit = ObjectAccessor::GetUnit(*bot, guid);
            if (!unit || !unit->IsInWorld() || unit->IsDuringRemoveFromWorld())
                continue;
            if (!unit->IsAlive())
                return unit;
        }

        return nullptr;
    }

    Unit* BotGetDispelMember(Creature* bot, const DispelAbility& ability)
    {
        if (!bot || !bot->IsInWorld() || bot->IsDuringRemoveFromWorld())
            return nullptr;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return nullptr;

        auto group = ResolveGroup(bot, baseAI->botLogicalGroup);
        if (group.empty())
            return nullptr;

        for (Unit* member : group)
        {
            if (!member || !member->IsInWorld() || member->IsDuringRemoveFromWorld())
                continue;

            // Scan all auras on the member
            for (auto const& auraPair : member->GetAppliedAuras())
            {
                Aura* aura = auraPair.second->GetBase();
                if (!aura)
                    continue;

                SpellInfo const* info = aura->GetSpellInfo();
                if (!info)
                    continue;

                // Only negative auras
                if (info->IsPositive())
                    continue;

                DispelType type = FSBSpellsUtils::ConvertAuraToDispelType(aura);
                if (std::find(ability.dispels.begin(), ability.dispels.end(), type) != ability.dispels.end())
                    return member; // Found someone we can dispel
            }
        }

        return nullptr;
    }

    std::vector<Unit*> BotGetMembersToHeal(Creature* bot, float lowHpThreshold)
    {
        if (!bot || !bot->IsInWorld() || bot->IsDuringRemoveFromWorld())
            return {};

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return {};

        auto group = ResolveGroup(bot, baseAI->botLogicalGroup);
        if (group.empty())
            return {};

        std::vector<Unit*> candidates;

        for (Unit* unit : group)
        {
            if (!unit || !unit->IsAlive())
                continue;

            // Emergency 1: HP below threshold
            if (unit->GetHealthPct() <= lowHpThreshold)
                candidates.push_back(unit);
        }

        return candidates;
    }

    float CalculateEmergencyPriority(Unit* unit)
    {
        if (!unit)
            return 0.f;

        float hpUrgency = 100.f - unit->GetHealthPct();

        // Get role (works for any bot)
        FSB_Roles role = FSBMgr::Get()->GetRole(unit->ToCreature());

        // Assign base priority values (higher = more urgent)
        float rolePriority = 50.f;
        if (role == FSB_ROLE_HEALER)           // healer
            rolePriority = 80.f;
        else if (role == FSB_ROLE_TANK)        // tank
            rolePriority = 100.f;
        else if (unit->IsPlayer())             // player
            rolePriority = 90.f;

        // Combine role priority with HP urgency
        return rolePriority + hpUrgency;
    }
    void SortEmergencyTargets(std::vector<Unit*>& targets)
    {
        std::sort(targets.begin(), targets.end(), [](Unit* a, Unit* b)
            {
                return CalculateEmergencyPriority(a) > CalculateEmergencyPriority(b);
            });
    }

    bool BotGroupIsHealthy_Average(Creature* bot, uint32 groupHP)
    {
        if (!bot || !bot->IsAlive())
            return true;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return true;

        auto group = ResolveGroup(bot, baseAI->botLogicalGroup);
        if (group.empty())
            return true;

        float totalPct = 0.f;
        uint32 count = 0;

        for (Unit* u : group)
        {
            totalPct += u->GetHealthPct();
            count++;
        }

        float avg = totalPct / count;
        return avg >= groupHP;
    }
}
