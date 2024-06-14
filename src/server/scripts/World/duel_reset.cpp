/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "GameTime.h"
#include "Pet.h"
#include "Player.h"
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
                player1->RemoveArenaSpellCooldowns(true);
                player2->RemoveArenaSpellCooldowns(true);
            }

            // Health and mana reset
            if (sWorld->getBoolConfig(CONFIG_RESET_DUEL_HEALTH_MANA))
            {
                player1->ResetAllPowers();
                player2->ResetAllPowers();
                player1->SetFullPower(POWER_MANA);
                player2->SetFullPower(POWER_MANA);
            }
        }

        // Called when a duel ends
        void OnDuelEnd(Player* winner, Player* loser, DuelCompleteType type) override
        {
            // Cooldown restore
            if (sWorld->getBoolConfig(CONFIG_RESET_DUEL_COOLDOWNS))
            {
                winner->RemoveArenaSpellCooldowns(true);
                loser->RemoveArenaSpellCooldowns(true);
            }

            // Health and mana restore
            if (sWorld->getBoolConfig(CONFIG_RESET_DUEL_HEALTH_MANA))
            {
                winner->ResetAllPowers();
                loser->ResetAllPowers();

                winner->SetFullPower(POWER_MANA);
                loser->SetFullPower(POWER_MANA);

                // pet cooldowns
                if (Pet* winpet = winner->GetPet())
                    winpet->SetHealth(winpet->GetMaxHealth());

                if (Pet* losepet = loser->GetPet())
                    losepet->SetHealth(losepet->GetMaxHealth());
            }
        }
};

void AddSC_duel_reset()
{
    new DuelResetScript();
}
