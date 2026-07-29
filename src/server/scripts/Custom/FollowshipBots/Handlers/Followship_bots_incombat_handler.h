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

constexpr float BOT_IC_THRESHOLD_POTION_MP = 20.0f;
constexpr float BOT_IC_THRESHOLD_POTION_HP = 10.0f;

static constexpr float DefaultHealPCT = 50.f;
static constexpr float DefaultHealPCTHealer = 70.f;
static constexpr float DungeonHealPCT = 70.f;
static constexpr float DungeonHealPCTHealer = 90.f;

static constexpr float  BOT_IC_SELFHEAL_EMERGENCY_HP = 25.0f;
static constexpr uint32 BOT_IC_SELFHEAL_ATTACK_CHANCE = 30;
static constexpr uint32 BOT_IC_SELFHEAL_MAX_CONSECUTIVE = 3;

namespace FSBIC
{
    bool BotICActions(Creature* bot, uint32& globalCooldown, bool& botCastedCombatBuffs);
    bool BotICPotions(Creature* bot);
    bool BotICInitialBuffs(Creature* bot, uint32 globalCooldown, bool& botCastedCombatBuffs);
    bool BotICMeleeMode(Creature* bot);
    bool BotICTryDispel(Creature* bot);
    bool BotICTryOffensiveDispel(Creature* bot);
    bool BotICHealSelf(Creature* bot);
    bool BotICHealGroup(Creature* bot);
    bool BotICHealBattlegroundAllies(Creature* bot);
    bool BotICTryOffensiveSpell(Creature* bot);

    bool BotICRandomActions(Creature* bot);
    bool BotICAnnounceLowManaHealth(Creature* bot);

}
