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

#include "Creature.h"
#include "Log.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"

#include "Followship_bots.h"
#include "Followship_bots_config.h"
#include "Followship_bots_mgr.h"
#include "Followship_bots_utils.h"

#include "Followship_bots_chatter_handler.h"
#include "GenAI_chatter_prompts.h"
#include "Followship_bots_battleground_handler.h"
#include "Followship_bots_death_handler.h"
#include "Followship_bots_dungeon_handler.h"
#include "Followship_bots_events_handler.h"
#include "Followship_bots_group_handler.h"
#include "Followship_bots_movement_handler.h"
#include "Followship_bots_spells_handler.h"
#include "Followship_bots_teleport_handler.h"
#include "Followship_bots_utils.h"

using namespace FSBUtils;

namespace FSBDeath
{
    void SetBotCorpseImmunity(Creature* bot, bool immune)
    {
        if (!bot)
            return;

        if (immune)
        {
            bot->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
            bot->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
            bot->SetReactState(REACT_PASSIVE);
        }
        else
        {
            bot->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
            bot->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
            bot->SetReactState(REACT_AGGRESSIVE);
        }
    }

    void HandlerJustDied(Creature* bot, Unit* killer)
    {
        if (!bot || bot->IsAlive())
            return;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return;

        auto& hasSS = baseAI->botHasSoulstone;
        auto& botGroup = baseAI->botLogicalGroup;

        // Ensure group is built before checking for healer
        FSBGroup::BuildLogicalBotGroup(bot, botGroup);

        if (killer)
            TC_LOG_DEBUG("scripts.fsb.death", "FSB: Death Bot {} JustDied from attacker {}.", bot->GetName(), killer->GetName());
        else
            TC_LOG_DEBUG("scripts.fsb.death", "FSB: Death Bot {} JustDied with no attacker.", bot->GetName());

        // Make the corpse immune to attacks while awaiting resurrection.
        SetBotCorpseImmunity(bot, true);

        // handle chatter after death
        if (killer && urand(0, 99) <= FollowshipBotsConfig::configFSBChatterRate)
            FSBGenAIPrompts::DispatchBotDeath(bot, killer->GetGUID());

        // handle death with soulstone or Self Resurrect (Shaman)
        if (hasSS)
        {
            TC_LOG_DEBUG("scripts.fsb.death", "FSB: Death Bot {} JustDied with Soulstone and will self resurrect.", bot->GetName());
            bot->AI()->DoAction(FSB_ACTION_SOULSTONE_RESSURECT);
            return;
        }

        // For arena we do not allow bots to revive
        if (bot->GetMap()->IsBattleArena())
            return;

        // handle death in battleground
        if (bot->GetMap()->IsBattleground())
        {
            FSBEvents::ScheduleBotEvent(bot, FSB_EVENT_BATTLEGROUND_TELEPORT_GRAVEYARD, 2s);
            return;
        }

        // handle death with healer present
        Unit* healer = FSBGroup::BotGetFirstGroupHealer(bot);
        if (healer)
        {
            TC_LOG_DEBUG("scripts.fsb.death", "FSB: Death Bot {} JustDied, found healer: {}", bot->GetName(), healer->GetName());
            AddToHealerResurrectQueue(bot, healer->ToCreature());
            bot->AI()->DoAction(FSB_ACTION_WAIT_HEALER_RESSURECT);
            return;
        }

        // handle death with graveyard teleport
        if (!bot->GetMap()->IsDungeon())
        {
            FSBEvents::ScheduleBotEvent(bot, FSB_EVENT_GENERIC_TELEPORT_GRAVEYARD, 4s, 6s);
            return;
        }
        else bot->AI()->DoAction(FSB_ACTION_TELEPORT_DUNGEON);
        
    }

    void HandleDeathWithGraveyard(Creature* bot, Position botCorpse)
    {
        if (!bot || bot->IsAlive())
            return;

        bot->setDeathState(ALIVE);
        bot->SetHealth(1);

        bot->GetMotionMaster()->Clear();
        bot->GetMotionMaster()->MovePoint(FSBMovement::MOVEMENT_POINT_CORPSE, botCorpse, false);
        TC_LOG_DEBUG("scripts.fsb.death", "FSB: Death Bot {} Started the corpse run from graveyard.", bot->GetName());

    }

    void HandleBattlegroundGraveyardResurrect(Creature* bot)
    {
        if (!bot || bot->IsAlive())
            return;

        // The bot has already been teleported to the graveyard by
        // FSBTeleport::BotTeleportToBattlegroundGraveyard. Just revive it here.
        bot->setDeathState(ALIVE);

        // Remove the ghost aura (and any other death-related auras) before restoring health.
        bot->RemoveAllAuras();

        bot->SetFullHealth();

        if (bot->GetPowerType() == POWER_MANA)
            bot->SetPower(POWER_MANA, bot->GetMaxPower(POWER_MANA));

        // Remove corpse immunity now that the bot is alive.
        SetBotCorpseImmunity(bot, false);

        bot->GetMotionMaster()->Clear();

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (baseAI)
        {
            // Re-apply class forms/stances/auras after the full aura wipe.
            FSBMgr::Get()->ApplyRoleAuras(bot, baseAI->botRole);

            if (baseAI->botHired)
            {
                FSBMovement::ResumeFollow(bot, baseAI->botFollowDistance, baseAI->botFollowAngle);
            }
            else if (FSB_BattlegroundData* bgData = baseAI->GetBattlegroundData())
            {
                if (bgData->bgTypeId == BATTLEGROUND_WS || bgData->bgTypeId == BATTLEGROUND_WG_CTF)
                {
                    FSBBattleground::WarsongGulch::SetBotState(bot, bgData,
                        FSBBattleground::WarsongGulch::GetWSGBotState(bot, bgData->wsgState));
                    bot->GetMotionMaster()->Clear();
                    bgData->wsgMovePhase = FSBBattleground::WarsongGulch::WSGMovePhase::ReviveMove;
                    FSBBattleground::WarsongGulch::UpdateBot(bot, bgData);
                }
            }
        }

        TC_LOG_DEBUG("scripts.fsb.death", "FSB: Death Bot {} resurrected at battleground graveyard.", bot->GetName());
    }

    void HandleDeathWithSoulstone(Creature* bot, bool& hasSS)
    {
        if (!bot || bot->IsAlive())
            return;

        bot->CastSpell(bot, SPELL_WARLOCK_SOULSTONE_VISUAL, true);
        bot->setDeathState(ALIVE);
        bot->SetNpcFlag(UNIT_NPC_FLAG_GOSSIP);
        bot->RemoveAllAuras();

        // Restore health and mana after revival, but before removing corpse immunity
        uint64 maxHealth = bot->GetMaxHealth();
        uint64 maxMana = bot->GetMaxPower(POWER_MANA);
        bot->SetHealth(maxHealth * 0.60f);
        if (maxMana > 1)
            bot->SetPower(POWER_MANA, maxMana * 0.20f);

        // Remove corpse immunity now that the bot is alive.
        SetBotCorpseImmunity(bot, false);

        if (urand(0, 99) <= FollowshipBotsConfig::configFSBChatterRate)
            FSBGenAIPrompts::DispatchBotRevivedSelf(bot);

        hasSS = false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (baseAI)
        {
            // Resume follow movement
            FSBMovement::ResumeFollow(bot, baseAI->botFollowDistance, baseAI->botFollowAngle);

            // Re-apply role specific auras/forms/stances after revival
            FSBMgr::Get()->ApplyRoleAuras(bot, baseAI->botRole);

            // Set flag for healer classes to check dead units after arriving at player
            if (BotIsHealerClass(bot))
                baseAI->botNeedsDeadUnitCheck = true;
        }

        TC_LOG_DEBUG("scripts.fsb.death", "FSB: Death Bot {} Revived from Soulstone.", bot->GetName());
    }

    void HandleDeathInDungeon(Creature* bot, float fDistance, float fAngle)
    {
        if (!bot || bot->IsAlive())
            return;

        bot->GetThreatManager().ResetAllThreat();

        bot->setDeathState(ALIVE);
        bot->SetNpcFlag(UNIT_NPC_FLAG_GOSSIP);

        // Remove corpse immunity now that the bot is alive.
        SetBotCorpseImmunity(bot, false);

        // Restore health and mana to proper values
        uint64 maxHealth = bot->GetMaxHealth();
        uint64 maxMana = bot->GetMaxPower(POWER_MANA);
        bot->SetHealth(maxHealth * 0.35f);
        if (maxMana > 1)
            bot->SetPower(POWER_MANA, maxMana * 0.35f);
        
        // Remove any death-related auras
        bot->RemoveAllAuras();

        FSBMovement::ResumeFollow(bot, fDistance, fAngle);

        // Re-apply role specific auras/forms/stances after revival
        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (baseAI)
            FSBMgr::Get()->ApplyRoleAuras(bot, baseAI->botRole);

        // Set flag for resurrect-capable classes to check dead units after arriving at player
        if (baseAI && BotIsHealerClass(bot))
            baseAI->botNeedsDeadUnitCheck = true;

        if (urand(0, 99) <= FollowshipBotsConfig::configFSBChatterRate)
            FSBGenAIPrompts::DispatchBotRevived(bot);
        TC_LOG_DEBUG("scripts.fsb.death", "FSB: Death Bot {} Revived at dungeon entrance.", bot->GetName());
    }

    void BotSetStateAfterCorpseRevive(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return;

        bot->RemoveAllAuras();

        // Remove corpse immunity now that the bot is revived at its corpse.
        SetBotCorpseImmunity(bot, false);

        bot->SetNpcFlag(UNIT_NPC_FLAG_GOSSIP);
        if (urand(0, 99) <= FollowshipBotsConfig::configFSBChatterRate)
            FSBGenAIPrompts::DispatchBotRevived(bot);
        TC_LOG_DEBUG("scripts.fsb.death", "FSB: Death Bot {} Revived at corpse location after graveyard run.", bot->GetName());

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return;

        // Re-apply role specific auras/forms/stances after revival
        FSBMgr::Get()->ApplyRoleAuras(bot, baseAI->botRole);
    }

    void AddToHealerResurrectQueue(Unit* deadUnit, Creature* healer)
    {
        if (!deadUnit || !healer)
            return;

        auto healerAI = dynamic_cast<FSB_BaseAI*>(healer->AI());
        if (!healerAI)
            return;

        // Add dead unit GUID to healer's queue
        healerAI->botResurrectQueue.push(deadUnit->GetGUID());
        TC_LOG_DEBUG("scripts.fsb.death", "FSB: AddToHealerResurrectQueue Added dead unit {} to healer {} resurrect queue", deadUnit->GetName(), healer->GetName());

        // Chatter announcement (once when added to queue)
        if (urand(0, 99) <= FollowshipBotsConfig::configFSBChatterRate)
            FSBGenAIPrompts::DispatchBotMemberDied(healer, deadUnit->GetGUID());

        // Schedule resurrect event
        FSBEvents::ScheduleBotEvent(healer, FSB_EVENT_HIRED_RESURRECT_TARGET, 3s, 5s);
    }

    void ProcessResurrectQueue(Creature* healer)
    {
        if (!healer || !healer->IsAlive())
            return;

        auto healerAI = dynamic_cast<FSB_BaseAI*>(healer->AI());
        if (!healerAI)
            return;

        auto& resurrectQueue = healerAI->botResurrectQueue;
        if (resurrectQueue.empty())
            return;

        // Check if healer can resurrect (out of combat, or Druid for combat res)
        bool canCombatRes = healerAI->botClass == FSB_Class::Druid;
        if (healer->IsInCombat() && !canCombatRes)
        {
            FSBEvents::ScheduleBotEvent(healer, FSB_EVENT_HIRED_RESURRECT_TARGET, 5s);
            return;
        }

        if (healer->HasUnitState(UNIT_STATE_CASTING))
        {
            FSBEvents::ScheduleBotEvent(healer, FSB_EVENT_HIRED_RESURRECT_TARGET, 2s);
            return;
        }

        // Get next target from queue
        ObjectGuid targetGuid = resurrectQueue.front();
        Unit* target = ObjectAccessor::GetUnit(*healer, targetGuid);

        // Validate target
        if (!target || target->IsAlive() || !target->IsInWorld() || target->IsDuringRemoveFromWorld())
        {
            resurrectQueue.pop();
            if (!resurrectQueue.empty())
                FSBEvents::ScheduleBotEvent(healer, FSB_EVENT_HIRED_RESURRECT_TARGET, 1s);
            return;
        }

        // Check distance
        if (healer->GetMapId() == target->GetMapId() && healer->GetDistance(target) > 30.0f)
        {
            healer->GetMotionMaster()->Clear();
            healer->GetMotionMaster()->MoveCloserAndStop(4, target, 28.f);
            FSBEvents::ScheduleBotEvent(healer, FSB_EVENT_HIRED_RESURRECT_TARGET, 5s);
            return;
        }

        // Determine spell based on class
        uint32 spellId = 0;
        switch (healerAI->botClass)
        {
        case FSB_Class::Priest:
            spellId = SPELL_PRIEST_RESURRECTION;
            break;
        case FSB_Class::Druid:
            if (canCombatRes && healer->IsInCombat())
                spellId = SPELL_DRUID_REBIRTH;
            else
                spellId = SPELL_DRUID_REVIVE;
            break;
        case FSB_Class::Monk:
            spellId = SPELL_MONK_RESUSCITATE;
            break;
        case FSB_Class::Paladin:
            spellId = SPELL_PALADIN_REDEMPTION;
            break;
        case FSB_Class::Shaman:
            spellId = SPELL_SHAMAN_ANCESTRAL_SPIRIT;
            break;
        default:
            resurrectQueue.pop();
            if (!resurrectQueue.empty())
                FSBEvents::ScheduleBotEvent(healer, FSB_EVENT_HIRED_RESURRECT_TARGET, 1s);
            return;
        }

        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId, DIFFICULTY_NONE);
        if (!spellInfo)
        {
            resurrectQueue.pop();
            if (!resurrectQueue.empty())
                FSBEvents::ScheduleBotEvent(healer, FSB_EVENT_HIRED_RESURRECT_TARGET, 1s);
            return;
        }

        int32 castTimeMs = spellInfo->CalcCastTime();
        auto costs = spellInfo->CalcPowerCost(healer, spellInfo->GetSchoolMask());
        uint32 manaCost = 0;
        if (!costs.empty())
        {
            auto manaIt = std::find_if(costs.begin(), costs.end(), [](SpellPowerCost const& cost) { return cost.Power == POWER_MANA; });
            if (manaIt != costs.end())
                manaCost = manaIt->Amount;
            else
                manaCost = costs[0].Amount;
        }
        uint32 currentMana = healer->GetPower(POWER_MANA);

        // Check if healer has enough mana
        if (currentMana < manaCost)
        {
            FSBEvents::ScheduleBotEvent(healer, FSB_EVENT_HIRED_RESURRECT_TARGET, 10s);
            return;
        }

        // Cast resurrection on dead target
        if (FSBSpells::BotCastSpellOnDeadTarget(healer, spellId, target))
        {
            uint32 now = getMSTime();
            healerAI->botGlobalCooldown = now + 1500;
            resurrectQueue.pop();

            TC_LOG_DEBUG("scripts.fsb.death", "FSB: ProcessResurrectQueue Healer {} resurrected {}", healer->GetName(), target->GetName());

            if (urand(0, 99) <= FollowshipBotsConfig::configFSBChatterRate)
                FSBGenAIPrompts::DispatchBotRevivedTarget(healer, target->GetGUID());

            FSBEvents::ScheduleBotEvent(healer, FSB_EVENT_HIRED_RESUME_FOLLOW, std::chrono::milliseconds(castTimeMs + 1000));

            if (!resurrectQueue.empty())
                FSBEvents::ScheduleBotEvent(healer, FSB_EVENT_HIRED_RESURRECT_TARGET, std::chrono::milliseconds(castTimeMs + 2000));
        }
        else
        {
            FSBEvents::ScheduleBotEvent(healer, FSB_EVENT_HIRED_RESURRECT_TARGET, 5s);
        }
    }

    void HandleSpellResurrection(Creature* bot, uint32 spellId)
    {
        if (!bot || bot->IsAlive())
            return;

        switch (spellId)
        {
        case SPELL_SHAMAN_ANCESTRAL_SPIRIT:
        case SPELL_MONK_RESUSCITATE:
        case SPELL_PALADIN_REDEMPTION:
        case SPELL_PRIEST_RESURRECTION:
        case SPELL_DRUID_REVIVE:
        case SPELL_DRUID_REBIRTH:
            FSBEvents::ScheduleBotEvent(bot, FSB_EVENT_HIRED_SPELL_RESURRECT_STATE, 3s, 5s);
            TC_LOG_DEBUG("scripts.fsb.death", "FSB: Death Bot {} was resurrected by spell {}", bot->GetName(), FSBSpellsUtils::GetSpellName(spellId));
            break;
        default:
            break;
        }
    }

    void HandleSpellResurrectionDelayedAction(Creature* bot)
    {
        if (!bot || bot->IsAlive())
            return;

        bool isCombatRes = FSBCombatUtils::IsCombatActive(bot);

        // When bot is resurrected we need to set it back to death state alive
        bot->setDeathState(ALIVE);
        bot->SetNpcFlag(UNIT_NPC_FLAG_GOSSIP);

        // Remove corpse immunity now that the bot is alive.
        SetBotCorpseImmunity(bot, false);

        uint64 maxHealth = bot->GetMaxHealth();
        uint64 maxMana = bot->GetMaxPower(POWER_MANA);
        float healthPct = 0.35f;
        float manaPct = 0.35f;

        if (isCombatRes)
        {
            healthPct = 1.f;
            manaPct = 0.2f;
        }


        bot->SetHealth(maxHealth * healthPct);
        if (maxMana > 1) bot->SetPower(POWER_MANA, maxMana * manaPct);

        if (auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI()))
            FSBMgr::Get()->ApplyRoleAuras(bot, baseAI->botRole);
    }
}
