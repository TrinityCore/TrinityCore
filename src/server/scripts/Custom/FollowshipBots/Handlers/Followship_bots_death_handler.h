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

namespace FSBDeath
{
    void HandlerJustDied(Creature* bot, Unit* killer);

    void HandleDeathWithSoulstone(Creature* bot, bool& hasSS);
    void HandleDeathWithGraveyard(Creature* bot, Position botCorpse);
    void HandleBattlegroundGraveyardResurrect(Creature* bot);
    void HandleDeathInDungeon(Creature* bot, float fDistance, float fAngle);
    void BotSetStateAfterCorpseRevive(Creature* bot);
    // Add dead unit (bot or player) to healer's resurrect queue
    void AddToHealerResurrectQueue(Unit* deadUnit, Creature* healer);
    // Process resurrect queue (called by event)
    void ProcessResurrectQueue(Creature* healer);
    // Actions when bot is hit with resurrect spell
    void HandleSpellResurrection(Creature* bot, uint32 spellId);
    // Timed actions after bot is hit with resurrect spell
    void HandleSpellResurrectionDelayedAction(Creature* bot);
}
