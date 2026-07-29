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

#include "Followship_bots_mgr.h"

#include "Followship_bots_combat_handler.h"
#include "Followship_bots_group_handler.h"
#include "Followship_bots_movement_handler.h"
#include "Followship_bots_dungeon_handler.h"
#include "Followship_bots_battleground_handler.h"

namespace FSBCombat
{
    void EvaluateAttackNeeded(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return;

        if (bot->HasAura(SPELL_SPECIAL_GHOST))
            return;

        if (FSB_BaseAI* baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI()))
            if (baseAI->botDungeonData && baseAI->botDungeonData->mechanicFlagA)
                return;

        Unit* victim = bot->GetVictim();
        // Prevent bot from disengaging from current target
        if (victim)
        {
            if (!victim || !victim->IsInWorld() || victim->IsDuringRemoveFromWorld() || !victim->IsAlive())
            {
                bot->AttackStop();
                return;
            }

            // Bot must still consider this its real victim
            Unit* ensured = bot->EnsureVictim();
            if (!ensured || ensured != victim || !ensured->IsAlive() || !ensured->IsInWorld() || ensured->IsDuringRemoveFromWorld())
                return;

            if (bot->GetDistance(victim) > 100.f)
            {
                BotTerminateCombat(bot);
                return;
            }

            // Owner may be null (non-hired bots) OR on another map; owner-specific logic only applies when valid
            Player* owner = FSBMgr::Get()->GetBotOwner(bot);
            if (owner && owner->IsInWorld() && !owner->IsDuringRemoveFromWorld() && owner->GetMapId() == victim->GetMapId())
            {
                // Now safe to check combat state
                if ((!bot->IsValidAttackTarget(victim) && owner->IsInCombatWith(victim)) ||
                    (!bot->IsHostileTo(victim) && owner->IsInCombatWith(victim)))
                {
                    // Do not remove this or bots cant cast spells on neutral mobs
                    victim->SetFaction(14);
                    bot->GetCombatManager().SetInCombatWith(victim);
                    victim->GetCombatManager().SetInCombatWith(bot);
                }
            }

            // Dungeon target override: switch to adds when boss enters special phase
            if (Unit* overrideTarget = FSBDungeon::GetDungeonTargetOverride(bot, victim))
            {
                if (overrideTarget != victim)
                {
                    bot->AttackStop();
                    BotDoAttack(bot, overrideTarget);
                    return;
                }
            }

            FSBMovement::EnsureInRange(bot, victim);
            return;
        }

        Unit* target = GetNextAttackTarget(bot);

        if (!target || !target->IsInWorld() || target->IsDuringRemoveFromWorld() || !BotCanAttack(bot, target))
            return;

        BotDoAttack(bot, target);
    }

    void BotTerminateCombat(Creature* bot)
    {
        if (!bot || !bot->IsInCombat())
            return;

        bot->RemoveUnitFlag(UNIT_FLAG_IN_COMBAT);
        bot->AttackStop();
        bot->InterruptNonMeleeSpells(false);
        bot->CombatStop(true);
        bot->ClearInCombat();
        FSBMovement::BotHandleReturnMovement(bot);
    }

    void BotDoAttack(Creature* bot, Unit* target)
    {
        if (!bot || !bot->IsInWorld() || bot->IsDuringRemoveFromWorld() || !bot->IsAlive())
            return;

        // Handles attack with or without chase and also resets flags
        // for next update / creature kill

        if (!target || !target->IsInWorld() || target->IsDuringRemoveFromWorld() || !target->IsAlive())
            return;

        if (bot->Attack(target, true))
        {
            bot->SetUnitFlag(UNIT_FLAG_IN_COMBAT); // on player bots, this flag indicates we're actively going after a target - that's what we're doing, so set it

            if (auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI()))
                if (baseAI->botGenericData.pauseCombatChase)
                    return;

            bot->GetMotionMaster()->Clear();

            if (bot->HasUnitState(UNIT_STATE_FOLLOW))
                bot->GetMotionMaster()->Remove(FOLLOW_MOTION_TYPE);

            if (FSBMovement::EnsureInRange(bot, target))
            {
                // say some text here
            }
        }
    }

    // result false means bot cannot attack
    bool BotCanAttack(Creature* bot, Unit* target)
    {
        // Evaluates wether a bot can attack a specific target based on MoveState, ReactState and other flags
        // IMPORTANT: The order in which things are checked is important, be careful if you add or remove checks

        // Hmmm...
        if (!bot->IsAlive())
            return false;

        if (!target || !target->IsAlive())
            return false;

        // Passive - passive bots cannot attack
        if (bot->HasReactState(REACT_PASSIVE))
            return false;

        if (target->HasAura(SPELL_SPECIAL_GHOST))
            return false;

        if (target->HasBreakableByDamageCrowdControlAura())
            return false;

        if (target->HasUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC) ||
            target->HasUnitFlag(UNIT_FLAG_UNINTERACTIBLE) ||
            target->HasUnitFlag(UNIT_FLAG_PACIFIED) ||
            target->HasUnitFlag(UNIT_FLAG_NON_ATTACKABLE))
            return false;

        // Stay - can attack if target is within range or commanded to
        if (auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI()))
        {
            if (baseAI->botMoveState == FSB_MOVE_STATE_STAY)
                return bot->IsWithinMeleeRange(target) || bot->IsWithinCombatRange(target, FSBCombatUtils::GetBotChaseDistance(bot));
        }

        return true;
    }

    Unit* GetNextAttackTarget(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return nullptr;

        // 0. Dungeon-specific target override
        if (Unit* currentVictim = bot->GetVictim())
            if (Unit* overrideTarget = FSBDungeon::GetDungeonTargetOverride(bot, currentVictim))
                return overrideTarget;

        // 1. Check own victim
        Unit* victim = bot->GetVictim();
        if (victim && victim->IsAlive())
        {
            if (!victim->IsInWorld() || victim->IsDuringRemoveFromWorld())
                return nullptr;

            TC_LOG_DEBUG("scripts.fsb.combat", "FSB: GetNextAttackTarget Bot {} next target is their victim {}", bot->GetName(), victim->GetName());
            return victim;
        }

        // 2. Check own attacker
        Unit* attacker = bot->getAttackerForHelper();
        if (attacker && attacker->IsAlive())
        {
            if (!attacker || !attacker->IsInWorld() || attacker->IsDuringRemoveFromWorld() || !attacker->IsAlive())
                return nullptr;

            TC_LOG_DEBUG("scripts.fsb.combat", "FSB: GetNextAttackTarget Bot {} next target is their attacker {}", bot->GetName(), attacker->GetName());
            return attacker;
        }

        // 3. Check owner victim & attacker
        if (auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI()))
        {
            if (baseAI->botHired)
            {
                Player* player = FSBMgr::Get()->GetBotOwner(bot);
                if (player)
                {
                    Unit* ownerVictim = player->GetVictim();
                    if (ownerVictim && ownerVictim->IsAlive())
                    {
                        if (!ownerVictim || !ownerVictim->IsInWorld() || ownerVictim->IsDuringRemoveFromWorld() || !ownerVictim->IsAlive())
                            return nullptr;

                        TC_LOG_DEBUG("scripts.fsb.combat", "FSB: GetNextAttackTarget Bot {} next target is their owner victim {}", bot->GetName(), ownerVictim->GetName());
                        return ownerVictim;
                    }

                    Unit* ownerAttacker = player->getAttackerForHelper();
                    if (ownerAttacker && ownerAttacker->IsAlive())
                    {
                        if (!ownerAttacker || !ownerAttacker->IsInWorld() || ownerAttacker->IsDuringRemoveFromWorld() || !ownerAttacker->IsAlive())
                            return nullptr;

                        TC_LOG_DEBUG("scripts.fsb.combat", "FSB: GetNextAttackTarget Bot {} next target is their owner attacker {}", bot->GetName(), ownerAttacker->GetName());
                        return ownerAttacker;
                    }

                }
            }
        }

        // 4. Group assist logic
        Unit* assistTarget = FSBGroup::BotGetFirstMemberToAssist(bot);
        if (assistTarget && assistTarget->IsAlive())
        {
            if (!assistTarget || !assistTarget->IsInWorld() || assistTarget->IsDuringRemoveFromWorld() || !assistTarget->IsAlive())
                return nullptr;

            TC_LOG_DEBUG("scripts.fsb.combat", "FSB: GetNextAttackTarget Bot {} next target is their member attacker/victim {}", bot->GetName(), assistTarget->GetName());
            return assistTarget;
        }

        // 5. Battleground friendly assist
        if (Unit* bgFriendlyAssistTarget = FSBBattleground::FindFriendlyAssistTarget(bot, 30.f))
        {
            TC_LOG_DEBUG("scripts.fsb.combat", "FSB: GetNextAttackTarget Bot {} next target is battleground friendly assist target {}", bot->GetName(), bgFriendlyAssistTarget->GetName());
            return bgFriendlyAssistTarget;
        }

        // 6. Battleground hostile target scan
        if (Unit* bgTarget = FSBBattleground::FindHostileTargetInBattleground(bot))
        {
            TC_LOG_DEBUG("scripts.fsb.combat", "FSB: GetNextAttackTarget Bot {} next target is battleground hostile {}", bot->GetName(), bgTarget->GetName());
            return bgTarget;
        }

        return nullptr;
    }

    bool ShouldSwitchToMelee(Creature* bot)
    {
        if (!bot)
            return false;

        if (!bot->IsInCombat())
            return false;

        if (FSBDungeon::IsBotInDungeon(bot))
            return false;

        Unit* target = bot->GetVictim();
        if (!target)
            return false;

        // Mana threshold - tweak as needed
        uint32 mana = bot->GetPower(POWER_MANA);
        uint32 maxMana = bot->GetMaxPower(POWER_MANA);

        if (maxMana > 0 && mana > maxMana * 0.05f) // >5% mana
            return false;

        // Already in melee range?
        if (bot->IsWithinMeleeRange(target))
            return false;

        return true;
    }

    void EnterMeleeMode(Creature* bot)
    {
        if (!bot)
            return;

        if (auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI()))
            if (baseAI->botGenericData.pauseCombatChase)
                return;

        Unit* target = bot->GetVictim();
        if (!target)
            return;

        // Stop casting
        bot->InterruptNonMeleeSpells(false);

        // Move into melee range
        bot->GetMotionMaster()->Clear();
        bot->GetMotionMaster()->MoveChase(target, 0.5f);

        // Enable auto-attack
        bot->Attack(target, true);

        TC_LOG_DEBUG("scripts.ai.fsb", "FSB: {} switching to melee mode (OOM)", bot->GetName());
    }

    void SetOwnerTapToVictim(Creature* bot)
    {
        if (!bot)
            return;

        Player* owner = FSBMgr::Get()->GetBotOwner(bot);
        if (!owner || !owner->IsInWorld())
            return;

        Unit* victim = bot->GetVictim();
        if (!victim || !victim->IsAlive())
            return;

        Creature* mob = victim->ToCreature();
        if (!mob)
            return;

        // If owner already has tap, do nothing
        if (mob->isTappedBy(owner))
            return;

        // Otherwise, give owner tap
        mob->SetTappedBy(owner);
    }

    void BotSyncShapeshift(Creature* bot, bool inCombat)
    {
        if (!bot)
            return;

        if (!bot->IsInCombat())
            return;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return;

        if (!inCombat)
        {
            if (baseAI->botRace == FSB_Race::Worgen)
            {
                bot->RemoveAurasDueToSpell(49561);
                bot->DeMorph();
            }
        }

        if (inCombat)
        {
            if (bot->HasAura(SPELL_SHAMAN_GHOST_WOLF))
                bot->RemoveAurasDueToSpell(SPELL_SHAMAN_GHOST_WOLF);

            if (baseAI->botRace == FSB_Race::Worgen)
            {
                bot->CastSpell(bot, 49561); // Worgen Transform
                switch (baseAI->botGender)
                {
                    case GENDER_MALE:
                        bot->SetDisplayId(RAND(26787, 37696, 36777, 36778, 36779, 33672, 36770, 36771,
                            36772, 63721, 63722, 63726, 63727, 63730, 63731));
                        break;
                    case GENDER_FEMALE:
                        bot->SetDisplayId(RAND(37441, 37442, 37443, 37444, 37445, 37446, 37447, 37448,
                            37449, 33954, 33955, 33956, 33957, 63723, 63724, 63728, 63729, 63732, 63733));
                        break;

                default:
                    break;
                }
            }
        }
    }
}
