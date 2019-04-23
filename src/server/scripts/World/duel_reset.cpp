/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "Player.h"
#include "Pet.h"
#include "SpellHistory.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "World.h"

class DuelResetScript : public PlayerScript
{
    public:
        DuelResetScript() : PlayerScript("DuelResetScript") { }

        // Called when a duel starts (after 3s countdown)
        void OnDuelStart(Player* player1, Player* player2) override
        {
            // Cooldowns reset
            if (sWorld->getBoolConfig(CONFIG_RESET_DUEL_COOLDOWNS))
            {
                player1->GetSpellHistory()->SaveCooldownStateBeforeDuel();
                player2->GetSpellHistory()->SaveCooldownStateBeforeDuel();

                ResetSpellCooldowns(player1, true);
                ResetSpellCooldowns(player2, true);
            }

            // Health and mana reset
            if (sWorld->getBoolConfig(CONFIG_RESET_DUEL_HEALTH_MANA))
            {
                player1->SaveHealthBeforeDuel();
                player1->SaveManaBeforeDuel();
                player1->ResetAllPowers();

                player2->SaveHealthBeforeDuel();
                player2->SaveManaBeforeDuel();
                player2->ResetAllPowers();
            }
        }

        // Called when a duel ends
        void OnDuelEnd(Player* winner, Player* loser, DuelCompleteType type) override
        {
            // do not reset anything if DUEL_INTERRUPTED or DUEL_FLED
            if (type == DUEL_WON)
            {
                // Cooldown restore
                if (sWorld->getBoolConfig(CONFIG_RESET_DUEL_COOLDOWNS))
                {
                    ResetSpellCooldowns(winner, false);
                    ResetSpellCooldowns(loser, false);

                    winner->GetSpellHistory()->RestoreCooldownStateAfterDuel();
                    loser->GetSpellHistory()->RestoreCooldownStateAfterDuel();
                }

                // Health and mana restore
                if (sWorld->getBoolConfig(CONFIG_RESET_DUEL_HEALTH_MANA))
                {
                    winner->RestoreHealthAfterDuel();
                    loser->RestoreHealthAfterDuel();

                    // check if player1 class uses mana
                    if (winner->GetPowerType() == POWER_MANA || winner->getClass() == CLASS_DRUID)
                        winner->RestoreManaAfterDuel();

                    // check if player2 class uses mana
                    if (loser->GetPowerType() == POWER_MANA || loser->getClass() == CLASS_DRUID)
                        loser->RestoreManaAfterDuel();
                }
            }
        }

        static void ResetSpellCooldowns(Player* player, bool onStartDuel)
        {
            if (onStartDuel)
            {
                // remove cooldowns on spells that have < 10 min CD > 30 sec and has no onHold
                player->GetSpellHistory()->ResetCooldowns([](SpellHistory::CooldownStorageType::iterator itr) -> bool
                {
                    SpellHistory::Clock::time_point now = SpellHistory::Clock::now();
                    uint32 cooldownDuration = itr->second.CooldownEnd > now ? std::chrono::duration_cast<std::chrono::milliseconds>(itr->second.CooldownEnd - now).count() : 0;
                    SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(itr->first);
                    return spellInfo->RecoveryTime < 10 * MINUTE * IN_MILLISECONDS
                           && spellInfo->CategoryRecoveryTime < 10 * MINUTE * IN_MILLISECONDS
                           && !itr->second.OnHold
                           && cooldownDuration > 0
                           && ( spellInfo->RecoveryTime - cooldownDuration ) > (MINUTE / 2) * IN_MILLISECONDS
                           && ( spellInfo->CategoryRecoveryTime - cooldownDuration ) > (MINUTE / 2) * IN_MILLISECONDS;
                }, true);
            }
            else
            {
                // remove cooldowns on spells that have < 10 min CD and has no onHold
                player->GetSpellHistory()->ResetCooldowns([](SpellHistory::CooldownStorageType::iterator itr) -> bool
                {
                    SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(itr->first);
                    return spellInfo->RecoveryTime < 10 * MINUTE * IN_MILLISECONDS
                           && spellInfo->CategoryRecoveryTime < 10 * MINUTE * IN_MILLISECONDS
                           && !itr->second.OnHold;
                }, true);
            }

            // pet cooldowns
            if (Pet* pet = player->GetPet())
                pet->GetSpellHistory()->ResetAllCooldowns();
        }
};

void AddSC_duel_reset()
{
    new DuelResetScript();
}
