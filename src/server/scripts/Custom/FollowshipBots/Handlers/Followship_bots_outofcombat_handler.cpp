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
#include "DB2Stores.h"
#include "Log.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "SpellHistory.h"
#include "SpellInfo.h"

#include "Followship_bots.h"
#include "Followship_bots_config.h"
#include "Followship_bots_utils.h"
#include "Followship_bots_mgr.h"

#include "Followship_bots_battleground_handler.h"
#include "Followship_bots_buffs_handler.h"
#include "Followship_bots_chatter_handler.h"
#include "GenAI_chatter_prompts.h"
#include "GenAI_client.h"
#include "Followship_bots_chat_handler.h"
#include "Followship_bots_death_handler.h"
#include "Followship_bots_dungeon_handler.h"
#include "Followship_bots_events_handler.h"
#include "Followship_bots_group_handler.h"
#include "Followship_bots_movement_handler.h"
#include "Followship_bots_outofcombat_handler.h"
#include "Followship_bots_pet_handler.h"
#include "Followship_bots_recovery_handler.h"
#include "Followship_bots_spells_handler.h"

namespace FSBOOC
{
    bool ExecuteBotEmote(Creature* bot, FSB_ChatterCategory category, TextEmotes textEmote, Emote visualEmote, Unit* target = nullptr);

    bool BotOOCActions(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return false;

        auto& globalCooldown = baseAI->botGlobalCooldown;
        auto& buffTimer = baseAI->botBuffsTimer;
        auto& selfBuffTimer = baseAI->botSelfBuffsTimer;

        if (FSBCombatUtils::IsCombatActive(bot))
            return false;

        uint32 now = getMSTime();

        if (!FSBSpellsUtils::CanCastNow(bot, now, globalCooldown))
            return false;

        //Clear combat flags and states
        BotOOCClearFlagsStates(bot);

        // This check needs to be here because BotOOCClearFlagsStates will cancel the recovery if no longer needed
        // Moving this above the other will block the cancel check.
        if (FSBRecovery::BotHasRecoveryActive(bot))
            return false;

        //1. Bot Heal Owner
        // If we heal owner this turn return and end tick
        Player* player = FSBMgr::Get()->GetBotOwner(bot);
        if (player && BotOOCHealOwner(bot, player, globalCooldown))
            return true;

        //2. Buffs: self, then group (if hired), then BG allies (if in battleground)
        // If we buff someone this turn return and end tick
        if (FSBBuffs::HandlePeriodicBuffs(bot, selfBuffTimer, buffTimer))
            return true;

        //3. Recover HP/MP
        // One recover action at a time
        if (BotOOCRecovery(bot, globalCooldown))
            return true;

        //5. Warlock Demon Summon
        if (BotOOCSummonPetOrDemon(bot))
            return true;

        //6. Random event
        if (BotOOCDoRandomEvent(bot))
            return true;       

        return false; 
    }

    bool BotOOCDoRandomEvent(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        // We do not want to do AFK actions in BG or dungeon
        if (FSBBattleground::IsInBG(bot))
            return false;

        if (bot->GetMap()->IsDungeon())
            return false;

        if (!FollowshipBotsConfig::configFSBUseAFKActions)
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        auto& botRandomEventCooldown = baseAI->botRandomEventTimer;

        uint32 now = getMSTime();
        if (now < botRandomEventCooldown)
            return false;

        bool check = false;

        if (BotOOCActionPlayerAFK(bot, false))
            check = true;

        if (check)
        {
            //TC_LOG_INFO("scripts.ai.fsb", "FSB Bot {} randomEvent: check true, applied cooldown", bot->GetName());
            uint32 interval = std::max(FollowshipBotsConfig::configFSBAFKInterval, MIN_AFK_INTERVAL_MS);
            botRandomEventCooldown = now + interval;
            return true;
        }

        return false;
    }

    bool BotOOCActionPlayerAFK(Creature* bot, bool force)
    {
        uint32 afkChance = FollowshipBotsConfig::configFSBAFKChance;
        if (urand(1, 100) > afkChance)
            return true; // if roll fails we return true so that cooldown is applied to reduce action spam

        if (!bot || !bot->IsAlive())
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        auto botByFire = baseAI->botSitsByFire;
        auto& isDoingRandomEvent = baseAI->botDoingRandomEvent;
        auto botOwnerNotMoving = baseAI->botOwnerNotMovingTimer;
        auto hired = baseAI->botHired;

        if (!hired)
            return false;

        if (isDoingRandomEvent || botByFire)
            return false;
        //TC_LOG_INFO("scripts.ai.fsb", "FSB Bot {} randomEvent: Player AFK detection step", bot->GetName());
        Player* player = FSBMgr::Get()->GetBotOwner(bot);
        if (!player || !player->IsAlive())
            return false;

        uint32 now = getMSTime();
        uint32 ownerNotMovingTime = now - botOwnerNotMoving;
        uint32 afkInterval = std::max(FollowshipBotsConfig::configFSBAFKInterval, MIN_AFK_INTERVAL_MS);

        bool playerAfk = player->isAFK() || ownerNotMovingTime > afkInterval;
        //TC_LOG_INFO("scripts.ai.fsb", "FSB Bot {} randomEvent: owner not moving for: {}", bot->GetName(), ownerNotMovingTime);
        if (force)
            playerAfk = true;

        if (playerAfk)
        {
            if (bot->HasAura(SPELL_ROGUE_STEALTH))
                bot->RemoveAurasDueToSpell(SPELL_ROGUE_STEALTH);

            //TC_LOG_INFO("scripts.ai.fsb", "FSB Bot {} detected owner AFK", bot->GetName());
            uint8 randomAction = urand(0, FSB_AFK_MAX_ACTIONS - 1);

            if (BotOOCAFKAction(bot, randomAction))
            {
                isDoingRandomEvent = true;
                FSBEvents::ScheduleBotEvent(bot, FSB_EVENT_RANDOM_ACTION_FINISH, 30s, 45s);
                return true;
            }
        }

        return false;
    }

    bool BotOOCAFKAction(Creature* bot, uint8 action)
    {
        if (!bot || !bot->IsAlive())
            return false;

        Player* player = FSBMgr::Get()->GetBotOwner(bot);
        if (!player || !player->IsAlive())
            return false;

        switch (action)
        {
        case FSB_AFK_ACTION_SHAMAN_WOLF:
        {
            auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
            if (!baseAI)
                return false;

            if (baseAI->botClass != FSB_Class::Shaman)
                return false;

            if (FSBSpells::BotCastSpell(bot, SPELL_SHAMAN_GHOST_WOLF, bot))
                return true;

            return false;
        }
        case FSB_AFK_ACTION_MAKE_PICNIC:
        {
            if (bot->GetSpellHistory()->HasCooldown(SPELL_SPECIAL_ROMANTIC_PICNIC))
                return false;

            TC_LOG_INFO("scripts.ai.fsb", "FSB Bot {} randomEvent: picnic", bot->GetName());
            // 0. Check if there is a fire already
            GameObject* picnic = GetClosestGameObjectWithEntry(bot, 187267, 20.f);
            if (picnic)
                return false;

            if (bot->GetStandState() == UNIT_STAND_STATE_STAND)
            {
                // 1. Cast campfire spell
                bot->CastSpell(bot, SPELL_SPECIAL_ROMANTIC_PICNIC, false);
                bot->SetStandState(UNIT_STAND_STATE_SIT);
                return true;
            }

            return false;
        }

        case FSB_AFK_ACTION_MAKE_FIRE:
        {
            if (BotOOCActionCook(bot, SPELL_SPECIAL_CAMP_FIRE, 266354))
                return true;

            return false;
        }

        case FSB_AFK_ACTION_COOKING_POT:
        {
            if (BotOOCActionCook(bot, SPELL_SPECIAL_COOKING_POT, 379147))
                return true;

            return false;
        }

        case FSB_AFK_ACTION_COOK_SAUSAGES:
        {
            if (BotOOCActionCook(bot, SPELL_SPECIAL_COOK_SAUSAGES, 236110))
                return true;

            return false;
        }

        case FSB_AFK_ACTION_BEG:
        {
            if (player)
            {
                bot->SetFacingToObject(player, true);
                TC_LOG_INFO("scripts.ai.fsb", "FSB Bot {} randomEvent: beg", bot->GetName());
                std::string emote = bot->GetName() + " begs " + player->GetName() + ". How pathethic!";
                bot->TextEmote(emote, player);
                bot->HandleEmoteCommand(EMOTE_ONESHOT_BEG, player);
                return true;
            }
            return false;
        }

        case FSB_AFK_ACTION_DANCE:
        {
            if (player)
            {
                bot->SetFacingToObject(player, true);
                TC_LOG_INFO("scripts.ai.fsb", "FSB Bot {} randomEvent: dance", bot->GetName());
                std::string emote = bot->GetName() + " dances with " + player->GetName();
                bot->TextEmote(emote, player);
                bot->HandleEmoteCommand(EMOTE_STATE_DANCE, player);
                return true;
            }
            return false;
        }

        case FSB_AFK_ACTION_KISS:
        {
            if (BotOOCActionKiss(bot))
                return true;

            return false;
        }

        case FSB_AFK_ACTION_WHISTLE:
        {
            TC_LOG_INFO("scripts.ai.fsb", "FSB Bot {} randomEvent: whistle", bot->GetName());
            if (ExecuteBotEmote(bot, FSB_ChatterCategory::emote_whistle, TEXT_EMOTE_BORED, EMOTE_ONESHOT_TALK))
                return true;
            return false;
        }

        case FSB_AFK_ACTION_FLIRT:
        {
            if (BotOOCActionFlirt(bot))
                return true;

            return false;
        }

        case FSB_AFK_ACTION_JOKE:
        {
            if (BotOOCActionJoke(bot))
                return true;

            return false;
        }

        case FSB_AFK_ACTION_SLEEP:
        {
            if (BotOOCActionSleep(bot))
                return true;

            return false;
        }

        case FSB_AFK_ACTION_SIGH:
        {
            if (BotOOCActionSigh(bot))
                return true;

            return false;
        }

        case FSB_AFK_ACTION_REST:
        {
            TC_LOG_INFO("scripts.ai.fsb", "FSB Bot {} randomEvent: rest", bot->GetName());
            auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
            bot->Say("Am gonna rest for a while...", baseAI ? baseAI->botLanguage : LANG_UNIVERSAL);
            bot->SetStandState(UNIT_STAND_STATE_SIT);
            return true;
        }

        case FSB_AFK_ACTION_TALK:
        {
            TC_LOG_INFO("scripts.ai.fsb", "FSB Bot {} randomEvent: talk", bot->GetName());
            bot->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
            FSBGenAIPrompts::DispatchBotTalk(bot);
            return true;
        }

        case FSB_AFK_ACTION_WHISPER:
        {
            if (player)
            {
                TC_LOG_INFO("scripts.ai.fsb", "FSB Bot {} randomEvent: whisper", bot->GetName());
                bot->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                FSBGenAIPrompts::DispatchBotWhisperAFK(bot);
                return true;
            }
            return false;
        }

        case FSB_AFK_ACTION_NOTHING:
        {
            TC_LOG_INFO("scripts.ai.fsb", "FSB Bot {} randomEvent: nothing", bot->GetName());
            return true;
        }

        case FSB_AFK_ACTION_COMPANION:
            if (BotOOCSpawnCompanion(bot))
                return true;
            return false;

        default:
            return false;
        }

        return false;
    }

    bool BotOOCSpawnCompanion(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        auto& botHasCompanion = baseAI->botHasCompanion;
        

        uint32 companionSpell = FSBMgr::Get()->GetBotCompanionSpellForEntry(bot->GetEntry());
        if (companionSpell == 0)
            return false;        

        int32 timerDiff = urandms(45, 60);

        if (FSBCombatUtils::IsOutOfCombatFor(bot, timerDiff) && !botHasCompanion)
        {
            baseAI->botHasCompanion = true;
            FSBSpells::BotCastSpell(bot, companionSpell, bot);
            return true;
        }

        return false;
    }

    void BotOOCClearFlagsStates(Creature* bot)
    {
        if (!bot)
            return;

        if (bot->IsInCombat())
            return;

        FSBRecovery::BotCancelRecoveryAtFull(bot);

        if (FSBRecovery::BotHasRecoveryActive(bot))
            return;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return;

        if (!baseAI->botHired)
            return;

        baseAI->botAnnouncedLowMana = false;
        baseAI->botAnnouncedLowHealth = false;
        baseAI->botAnnouncedVeryLowHealth = false;

        if (baseAI->botDungeonData && baseAI->botDungeonData->mechanicFlagD && !bot->GetVehicle())
            baseAI->botDungeonData->mechanicFlagD = false;

        baseAI->botCastedCombatBuffs = false;
        baseAI->botGenericData.consecutiveSelfHeals = 0;

        // Set bot to follow if move state is follow but we are idle
        if (baseAI->botMoveState == FSB_MOVE_STATE_FOLLOWING && FSBMovement::GetMovementType(bot) != FOLLOW_MOTION_TYPE)
            FSBMovement::ResumeFollow(bot, baseAI->botFollowDistance, baseAI->botFollowAngle);

        Player* player = FSBMgr::Get()->GetBotOwner(bot);

        // Check for dead units after arriving at player (for resurrect-capable classes in dungeons)
        if (baseAI->botNeedsDeadUnitCheck && player)
        {
            float distance = bot->GetDistance(player);
            if (distance < 10.0f) // Close enough to player
            {
                FSBEvents::ScheduleBotEvent(bot, FSB_EVENT_DUNGEON_CHECK_DEAD_UNITS, 3s, 5s);
                baseAI->botNeedsDeadUnitCheck = false;
            }
        }

        // Clear resurrect queue if target is alive
        auto& resurrectQueue = baseAI->botResurrectQueue;
        while (!resurrectQueue.empty())
        {
            ObjectGuid targetGuid = resurrectQueue.front();
            Unit* target = ObjectAccessor::GetUnit(*bot, targetGuid);
            if (target && target->IsAlive())
            {
                resurrectQueue.pop();
                baseAI->botSayMemberDead = false;
            }
            else
            {
                break; // Stop at first invalid target
            }
        }
        auto& botSitsByFire = baseAI->botSitsByFire;
        auto& botRandomEvent = baseAI->botDoingRandomEvent;
        auto fDistance = baseAI->botFollowDistance;
        auto fAngle = baseAI->botFollowAngle;

        auto& botOwnerNotMoving = baseAI->botOwnerNotMovingTimer;
        uint32 now = getMSTime();

        if (player && player->isMoving())
            baseAI->botOwnerNotMovingTimer = now;

        // check if we have a fire to go and sit around
        uint32 afkInterval = std::max(FollowshipBotsConfig::configFSBAFKInterval, MIN_AFK_INTERVAL_MS);
        if (!botSitsByFire && player && (player->isAFK() || (now - botOwnerNotMoving) > afkInterval))
            FSBEvents::ScheduleBotEvent(bot, FSB_EVENT_RANDOM_ACTION_MOVE_FIRE, 1s, 3s);

        // check if we need to make the bot stand again (after random sit event) and player is no longer afk
        if (player && (/*!player->isAFK() || */player->isMoving()))
        {
            if (botSitsByFire || botRandomEvent)
            {
                if (bot->HasAura(SPELL_SHAMAN_GHOST_WOLF))
                    bot->RemoveAurasDueToSpell(SPELL_SHAMAN_GHOST_WOLF);
                //bot->SetEmoteState(Emote(EMOTE_STATE_NONE));
                bot->HandleEmoteCommand(EMOTE_ONESHOT_YES);
                bot->SetStandState(UNIT_STAND_STATE_STAND);
                baseAI->botSitsByFire = false;
                baseAI->botDoingRandomEvent = false;
                FSBMovement::ResumeFollow(bot, fDistance, fAngle);
            }
        }

        
    }

    bool BotOOCSummonPetOrDemon(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        if (bot->IsInCombat())
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        auto isDoingRandomEvent = baseAI->botDoingRandomEvent;

        if (isDoingRandomEvent)
            return false;

        FSB_Class cls = FSBMgr::Get()->GetBotClassForEntry(bot->GetEntry());

        if (cls != FSB_Class::Warlock && cls != FSB_Class::Hunter)
            return false;

        if (FSBWarlock::BotSummonRandomDemon(bot))
            return true;

        if (FSBPet::BotSummonPet(bot))
            return true;

        return false;
    }

    bool BotOOCRecovery(Creature* bot, uint32& globalCooldown)
    {
        if (!bot || !bot->IsAlive())
            return false;

        if (bot->IsInCombat())
            return false;

        BotRecoveryIntent intent = FSBRecovery::DetermineRecoveryIntent(bot);

        switch (intent)
        {
        case BotRecoveryIntent::None:
            return false;
        case BotRecoveryIntent::RecoverHealthAndMana:
        case BotRecoveryIntent::RecoverMana:
        case BotRecoveryIntent::RecoverHealth:
            return FSBRecovery::TryOOCRecovery(bot, intent, globalCooldown);
        default:
            return false;
        }

        return false;
    }

    bool BotOOCHealOwner(Creature* bot, Player* player, uint32& globalCooldown)
    {
        if (!bot || !player || !player->IsAlive())
            return false;

        if (!FSBUtils::BotIsHealerClass(bot))
            return false;

        if (bot->GetStandState() == UNIT_STAND_STATE_SIT)
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        auto isDoingRandomEvent = baseAI->botDoingRandomEvent;

        if (isDoingRandomEvent)
            return false;

        float pHealth = player->GetHealthPct();

        if (pHealth > 90)
            return false;

        FSB_Class botClass = FSBMgr::Get()->GetBotClassForEntry(bot->GetEntry());
        if(botClass == FSB_Class::Druid && (bot->HasAura(SPELL_DRUID_BEAR) || bot->HasAura(SPELL_DRUID_CAT) || bot->HasAura(SPELL_DRUID_TRAVEL)))
            return false;

        bool check = false;

        //FSBMovement::StopFollow(bot);

        switch (botClass)
        {
        case FSB_Class::Priest:
            if (FSBPriest::BotOOCHealOwner(bot, player, globalCooldown))
                check = true;
            break;
        case FSB_Class::Druid:
            if (FSBDruid::BotOOCHealOwner(bot, player, globalCooldown))
                check = true;
            break;
        case FSB_Class::Paladin:
            if (FSBPaladin::BotOOCHealOwner(bot, player, globalCooldown))
                check = true;
            break;
        case FSB_Class::Monk:
            if (FSBMonk::BotOOCHealOwner(bot))
                check = true;
            break;
        case FSB_Class::Shaman:
            if (FSBShaman::BotOOCHealOwner(bot))
                check = true;
            break;
        default:
            break;
        }

        if (check && player)
        {
            if (urand(0, 99) <= FollowshipBotsConfig::configFSBChatterRate)
                FSBGenAIPrompts::DispatchBotHeal(bot, player->GetGUID(), 0);

            return true;
        }

        return false;
    }

    /*
    bool BotOOCBuffSelf(Creature* bot, uint32& selfBuffTimer, uint32& globalCooldown)
    {
        if (!bot || !bot->IsAlive())
            return false;

        if (bot->GetStandState() == UNIT_STAND_STATE_SIT)
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        auto isDoingRandomEvent = baseAI->botDoingRandomEvent;

        if (isDoingRandomEvent)
            return false;

        uint32 now = getMSTime();

        if (now < selfBuffTimer)
            return false;

        FSB_Class botClass = FSBMgr::Get()->GetBotClassForEntry(bot->GetEntry());
        uint32 buffSpellId = 0;
        bool check = false;

        switch (botClass)
        {
        case FSB_Class::Druid:
            if (FSBDruid::BotOOCBuffSelf(bot, globalCooldown, selfBuffTimer, buffSpellId))
                check = true;
            break;
        case FSB_Class::Paladin:
            if (FSBPaladin::BotOOCBuffSelf(bot, globalCooldown, selfBuffTimer, buffSpellId))
                check = true;
            break;
        case FSB_Class::Rogue:
            if (FSBRogue::BotOOCBuffSelf(bot, buffSpellId))
                check = true;
            break;
        case FSB_Class::Warlock:
            if (FSBWarlock::BotOOCBuffSelf(bot, globalCooldown, selfBuffTimer, buffSpellId))
                check = true;
            break;
        case FSB_Class::Shaman:
            if (FSBShaman::BotOOCBuffSelf(bot, buffSpellId))
                check = true;
            break;
        default:
            return false;
        }

        if (check)
        {
            if (buffSpellId)
            {
                if (urand(0, 99) <= FollowshipBotsConfig::configFSBChatterRate)
                    FSBGenAIPrompts::DispatchBotBuff(bot, bot->GetGUID(), buffSpellId);
            }

            return true;
        }
        selfBuffTimer = now + 60000; // 1 minute
        return false;
    }
    */

    /*
    bool BotOOCBuffGroup(Creature* bot, uint32& buffTimer, uint32& globalCooldown)
    {
        if (!bot)
            return false;

        if (bot->GetStandState() == UNIT_STAND_STATE_SIT)
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return false;

        auto isDoingRandomEvent = baseAI->botDoingRandomEvent;

        if (isDoingRandomEvent)
            return false;

        auto group = FSBGroup::ResolveGroup(bot, baseAI->botLogicalGroup);
        if (group.empty())
            return false;

        if (bot->HasAura(SPELL_DRUID_BEAR) || bot->HasAura(SPELL_DRUID_CAT) || bot->HasAura(SPELL_DRUID_TRAVEL))
            return false;

        FSB_Class botClass = FSBMgr::Get()->GetBotClassForEntry(bot->GetEntry());
        std::vector<Unit*> buffTargets;
        uint32 buffSpellId = 0;
        uint32 buffSpellId2 = 0;
        uint32 now = getMSTime();

        switch (botClass)
        {
        case FSB_Class::Druid:
            buffSpellId = SPELL_DRUID_MARK_WILD;
            buffSpellId2 = SPELL_DRUID_THORNS;
            break;
        case FSB_Class::Warrior:
            buffSpellId = SPELL_WARRIOR_BATTLE_SHOUT;
            break;
        case FSB_Class::Priest:
            buffSpellId = SPELL_PRIEST_POWER_WORD_FORTITUDE;
            break;
        case FSB_Class::Mage:
            buffSpellId = SPELL_MAGE_ARCANE_INTELLECT;
            break;
        case FSB_Class::Paladin:
            buffSpellId = SPELL_PALADIN_BLESSING_KINGS;
            break;
        case FSB_Class::Warlock:
            buffSpellId = SPELL_WARLOCK_UNENDING_BREATH;
            break;
        case FSB_Class::Shaman:
            buffSpellId = SPELL_SHAMAN_WATER_WALKING;
            if (baseAI->botRole == FSB_ROLE_HEALER)
                buffSpellId2 = SPELL_SHAMAN_EARTH_SHIELD;
            break;
        default:
            break;
        }

        if (!buffSpellId)
        {
            buffTimer = now + 300000;
            return false;
        }

        GetBotBuffTargets(bot, buffSpellId, 30.0f, buffTargets);
        if (buffSpellId2 && buffTargets.empty())
        {
            buffSpellId = buffSpellId2;
            if (baseAI->botRole == FSB_ROLE_HEALER)
            {
                Unit* tank = FSBGroup::BotGetFirstGroupTank(bot);

                if (tank && !tank->HasAura(buffSpellId))
                    buffTargets.push_back(tank);
                else
                {
                    Player* owner = FSBMgr::Get()->GetBotOwner(bot);
                    if (owner && !owner->HasAura(buffSpellId))
                        buffTargets.push_back(owner);
                }
            }
                
            else GetBotBuffTargets(bot, buffSpellId, 30.0f, buffTargets);
        }

        if (!buffTargets.empty())
        {
            Unit* target = buffTargets.front();

            if (target)
            {
                // we cannot buff bots with stealth aura
                if (target->HasAura(SPELL_ROGUE_STEALTH))
                    return false;

                SpellCastResult result = bot->CastSpell(target, buffSpellId, false);

                // Only continue if the cast succeeded
                if (result != SPELL_CAST_OK)
                {
                    // Optional: debug log
                     TC_LOG_DEBUG("scripts.ai.fsb", "Bot {} failed to cast {} on {} (reason {})",
                         bot->GetName(), buffSpellId, target->GetName(), result);

                    return false; // stop here, no chatter, no GCD
                }

                globalCooldown = now + 1500;

                if (urand(0, 99) <= FollowshipBotsConfig::configFSBChatterRate)
                    FSBGenAIPrompts::DispatchBotBuff(bot, target->GetGUID(), buffSpellId);
            }

            return true;
        }
        else buffTimer = now + 120000;

        return false;
    }
    */

    /*
    void GetBotBuffTargets(Creature* bot, uint32 buffSpellId, float maxRange, std::vector<Unit*>& outTargets)
    {
        if (!bot)
            return;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return;

        auto group = FSBGroup::ResolveGroup(bot, baseAI->botLogicalGroup);
        if (group.empty())
            return;

        for (Unit* member : group)
        {
            if (!member)
                continue;

            if (!member->IsAlive())
                continue;

            if (member->HasAura(buffSpellId))
                continue;

            if (!bot->IsWithinDistInMap(member, maxRange))
                continue;

            if (!bot->IsWithinLOSInMap(member))
                continue;

            outTargets.push_back(member);
        }
    }
    */

    bool ExecuteBotEmote(Creature* bot, FSB_ChatterCategory category, TextEmotes textEmote, Emote visualEmote, Unit* target)
    {
        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return false;

        auto botRace = baseAI->botRace;
        auto botGender = FSBMgr::Get()->GetBotGenderForEntry(bot->GetEntry());
        auto soundInfo = sDB2Manager.GetTextSoundEmoteFor(textEmote, FSBUtils::BotRaceToTC(botRace), botGender, 0);
        uint32 soundId = soundInfo ? soundInfo->SoundID : 0;

        std::string emote;
        if (category == FSB_ChatterCategory::emote_kiss)
            emote = FSBChatter::GetRandomEmoteText(bot, target, FSB_ChatterEmotes::emote_kiss);
        else if (category == FSB_ChatterCategory::emote_flirt)
            emote = FSBChatter::GetRandomEmoteText(bot, target, FSB_ChatterEmotes::emote_flirt);
        else if (category == FSB_ChatterCategory::emote_joke)
            emote = FSBChatter::GetRandomEmoteText(bot, target, FSB_ChatterEmotes::emote_joke);
        else if (category == FSB_ChatterCategory::emote_whistle)
            emote = FSBChatter::GetRandomEmoteText(bot, target, FSB_ChatterEmotes::emote_whistle);
        else if (category == FSB_ChatterCategory::emote_sigh)
            emote = FSBChatter::GetRandomEmoteText(bot, target, FSB_ChatterEmotes::emote_sigh);
        else if (category == FSB_ChatterCategory::emote_sleep)
            emote = FSBChatter::GetRandomEmoteText(bot, target, FSB_ChatterEmotes::emote_sleep);
        else
            emote = FSBChatter::GetRandomReply(bot, target, category, FSB_ChatterType::None, 0);

        if (!emote.empty())
        {
            if (target)
                bot->TextEmote(emote, target);
            else
                bot->TextEmote(emote);
        }

        bot->HandleEmoteCommand(visualEmote);
        if (soundId)
            bot->PlayDistanceSound(soundId);
        else
            TC_LOG_WARN("scripts.fsb.ooc", "FSB: no sound found for race {}", botRace);

        return true;
    }

    bool BotOOCActionSigh(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        TC_LOG_INFO("scripts.fsb.ooc", "FSB: BotOOCActionSigh started for Bot {}", bot->GetName());
        if (ExecuteBotEmote(bot, FSB_ChatterCategory::emote_sigh, TEXT_EMOTE_SIGH, EMOTE_ONESHOT_NONE))
            return true;

        return false;
    }

    bool BotOOCActionSleep(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        TC_LOG_INFO("scripts.fsb.ooc", "FSB: BotOOCActionSleep started for Bot {}", bot->GetName());
        if (ExecuteBotEmote(bot, FSB_ChatterCategory::emote_sleep, TEXT_EMOTE_YAWN, EMOTE_ONESHOT_NONE))
        {
            bot->SetStandState(UNIT_STAND_STATE_SLEEP);
            return true;
        }

        return false;
    }

    bool BotOOCActionJoke(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return false;
        auto& botGroup = baseAI->botLogicalGroup;

        Unit* randomUnit = nullptr;
        Player* player = FSBMgr::Get()->GetBotOwner(bot);

        if (botGroup.size() >= 3)
        {
            do
            {
                randomUnit = ObjectAccessor::GetUnit(*bot, Trinity::Containers::SelectRandomContainerElement(botGroup));
            } while (randomUnit == bot);
        }
        else if (player)
        {
            randomUnit = player;
        }
        else return false;

        if (randomUnit)
        {
            TC_LOG_INFO("scripts.fsb.ooc", "FSB: BotOOCActionJoke started for Bot {}", bot->GetName());

            bot->SetFacingToObject(randomUnit, true);
            ExecuteBotEmote(bot, FSB_ChatterCategory::emote_joke, TEXT_EMOTE_JOKE, EMOTE_ONESHOT_TALK, randomUnit);

            if (!randomUnit->IsPlayer())
                if (Creature* targetCreature = randomUnit->ToCreature())
                    FSBGenAIPrompts::DispatchBotSocialReply(targetCreature, bot->GetGUID(), FSB_ChatterCategory::emote_joke);

            return true;
        }

        return false;
    }

    bool BotOOCActionKiss(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return false;
        auto& botGroup = baseAI->botLogicalGroup;

        Unit* randomUnit = nullptr;
        Player* player = FSBMgr::Get()->GetBotOwner(bot);

        if (botGroup.size() >= 3)
        {
            do
            {
                randomUnit = ObjectAccessor::GetUnit(*bot, Trinity::Containers::SelectRandomContainerElement(botGroup));
            } while (randomUnit == bot);
        }
        else if (player)
        {
            randomUnit = player;
        }
        else return false;

        if (randomUnit)
        {
            TC_LOG_INFO("scripts.fsb.ooc", "FSB: BotOOCActionKiss started for Bot {}", bot->GetName());

            bot->SetFacingToObject(randomUnit, true);
            ExecuteBotEmote(bot, FSB_ChatterCategory::emote_kiss, TEXT_EMOTE_KISS, EMOTE_ONESHOT_KISS, randomUnit);

            if (!randomUnit->IsPlayer())
                if (Creature* targetCreature = randomUnit->ToCreature())
                    FSBGenAIPrompts::DispatchBotSocialReply(targetCreature, bot->GetGUID(), FSB_ChatterCategory::emote_kiss);

            return true;
        }

        return false;
    }

    bool BotOOCActionFlirt(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return false;
        auto& botGroup = baseAI->botLogicalGroup;

        Unit* randomUnit = nullptr;
        Player* player = FSBMgr::Get()->GetBotOwner(bot);

        if (botGroup.size() >= 3)
        {
            do
            {
                randomUnit = ObjectAccessor::GetUnit(*bot, Trinity::Containers::SelectRandomContainerElement(botGroup));
            } while (randomUnit == bot);
        }
        else if (player)
        {
            randomUnit = player;
        }
        else return false;

        if (randomUnit)
        {
            TC_LOG_INFO("scripts.fsb.ooc", "FSB: BotOOCActionFlirt started for Bot {}", bot->GetName());

            bot->SetFacingToObject(randomUnit, true);
            ExecuteBotEmote(bot, FSB_ChatterCategory::emote_flirt, TEXT_EMOTE_FLIRT, EMOTE_ONESHOT_SHY, randomUnit);

            if (!randomUnit->IsPlayer())
                if (Creature* targetCreature = randomUnit->ToCreature())
                    FSBGenAIPrompts::DispatchBotSocialReply(targetCreature, bot->GetGUID(), FSB_ChatterCategory::emote_flirt);

            return true;
        }

        return false;
    }

    bool BotOOCActionCook(Creature* bot, uint32 spellId, uint32 goId)
    {
        if (!bot || !bot->IsAlive())
            return false;

        // 0. Check if there is a fire already
        GameObject* gobject = GetClosestGameObjectWithEntry(bot, goId, 20.f);
        if (gobject)
            return false;

        if (bot->GetSpellHistory()->HasCooldown(spellId))
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return false;

        auto& botByFire = baseAI->botSitsByFire;

        if (!botByFire)
        {
            // 1. Cast campfire spell
            if (FSBSpells::BotCastSpell(bot, spellId, bot))
            {
                TC_LOG_INFO("scripts.fsb.ooc", "FSB: BotOOCActionCook started for bot {} with event {}", bot->GetName(), FSBSpellsUtils::GetSpellName(spellId));
                FSBGenAIPrompts::DispatchBotCooking(bot);
                return true;
            }
        }

        return false;
    }

    bool BotActionsNotHired(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return false;

        if (baseAI->botHired)
            return false;

        if (FSBBattleground::IsInBG(bot))
            return false;

        FSBChat::UpdateBotConversations();

        if (BotChatActionsNotHired(bot))
            return true;

        return false;
    }

    bool BotChatActionsNotHired(Creature* bot)
    {
        if (!FollowshipBotsConfig::configFSBUseChatChannels)
            return false;

        if (!bot || !bot->IsAlive())
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return false;

        if (baseAI->botHired)
            return false;

        uint32 now = getMSTime();

        // 1. If bot is already in a conversation, do nothing
        if (FSBChat::IsBotInConversation(bot))
            return false;

        // 2. Check timer correctly
        if (now < baseAI->botChatChannelsTimer)
            return false;

        int32 offset = urand(1000, 10000);

        // 3.1 Combat message when bot is attacked
        // This is in addition to the JustEngagedWith() trigger
        // Timer should ensure we are not spamming these
        if (bot->IsInCombat())
        {
            FSBChat::StartBotRandomChat(bot, FSBChat::ChatChannelType::CombatDefense);

            baseAI->botChatChannelsTimer = now + FollowshipBotsConfig::configFSBChatChannelsInterval + offset;

            return true;
        }

        // 3.2 Random chance to start a conversation or random chat
        if (urand(0, 99) > FollowshipBotsConfig::configFSBChatChannelsRate)
        {
            baseAI->botChatChannelsTimer = now + FollowshipBotsConfig::configFSBChatChannelsInterval + offset;
            return false;
        }

        int8 action = urand(1, 3);

        // 4. Start conversation
        if (action == 1)
        {
            if (FSBGenAI::IsEnabled())
                FSBChat::StartBotGenAIConversation(bot);
            else
                FSBChat::StartBotConversation(bot);
        }

        // 5. Start Random Chat
        if (action == 2)
            FSBChat::StartBotRandomChat(bot, FSBChat::ChatChannelType::General);

        if (action == 3 && FSBUtils::IsBotInTradeCity(bot))
            FSBChat::StartBotRandomChat(bot, FSBChat::ChatChannelType::Trade);

        // 6. Set next allowed time (store future timestamp)
        baseAI->botChatChannelsTimer = now + FollowshipBotsConfig::configFSBChatChannelsInterval + offset;

        return true;
    }
}

