/*
 * Copyright 2023 AzgathCore
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

#include "siege_of_orgrimmar.hpp"

Position npcAfterShaOfPridePos2[7] =
{
    { 750.75f, 1131.48f, 356.08f, 1.73f}, // Jaina
    { 740.28f, 1129.70f, 356.08f, 1.73f}, // Lor'themar
    { 744.46f, 1134.51f, 356.08f, 1.73f}, // Gorehowl
    { 785.54f, 1171.07f, 356.08f, 4.14f}, // Portal to Orgrimmar (alliance)
    { 782.49f, 1165.84f, 356.08f, 0.82f}, // Jaina near portal
    { 688.79f, 1151.24f, 356.08f, 5.81f}, // Portal to Orgrimmar (horde)
    { 695.27f, 1146.95f, 356.08f, 2.62f}  // Lor'themar near portal
};

Position galakrasPlayersPos2[3] =
{
    { 1366.50f, -5416.54f, 10.47f, 1.59f}, // alliance intro position
    { 1767.58f, -5265.74f, 6.97f, 2.90f},  // horde intro position
    { 1440.49f, -5015.87f, 12.11f, 1.67f}  // position at the docks
};

Position norushenTeleportPos = { 800.0f, 866.0f, 371.1f, 1.82f };
Position immersusTeleportPos = { 1459.0883f, 1037.2127f, 340.2553f, 3.12f };
Position afterIronJuggernautPos = { 1384.97f, -4369.95f, 25.80f, 0.15f };
Position afterGeneralNazgrimPos = { 1799.07f, -4779.58f, -255.24f, 5.31f };
Position afterMalkorokPos = { 1982.62f, -5177.68f, -271.88f, 3.74f };
Position afterParagonsPos = { 1494.18f, -5744.90f, -306.73f, 3.72f };

DoorData const doorData[] =
{
    {GO_IMMERSEUS_DOOR,          DATA_IMMERSEUS,          DOOR_TYPE_PASSAGE},
    {GO_SHA_ENERGY_WALL,         DATA_FALLEN_PROTECTORS,  DOOR_TYPE_PASSAGE},
    {GO_NORUSHEN_EXIT,           DATA_NORUSHEN,           DOOR_TYPE_PASSAGE},
    {GO_PRIDE_ENTRANCE,          DATA_SHA_OF_PRIDE,       DOOR_TYPE_ROOM},
    {GO_WIND_DOOR,               DATA_IRON_JUGGERNAUT,    DOOR_TYPE_ROOM},
    // temporary hack untill we scripts the event
    {GO_ORGRIMMAR_FRONT_GATE,    DATA_IRON_JUGGERNAUT,    DOOR_TYPE_PASSAGE},
    {GO_GATES_OF_ORGRIMMAR,      DATA_IRON_JUGGERNAUT,    DOOR_TYPE_PASSAGE},
    {GO_OGRAID_FRONT_GATE_BACK,  DATA_KORKRON_DARK_SHAMANS, DOOR_TYPE_ROOM},
    {GO_RUSTED_IRON_PORTCULLIS,  DATA_KORKRON_DARK_SHAMANS, DOOR_TYPE_PASSAGE},
    {GO_NAZGRIM_ENTRY_DOOR,      DATA_GENERAL_NAZGRIM,    DOOR_TYPE_ROOM},
    {GO_MASSIVE_IRONBOUND_DOOR_1,DATA_GENERAL_NAZGRIM,    DOOR_TYPE_PASSAGE},
    {GO_MASSIVE_IRONBOUND_DOOR_4,DATA_MALKOROK,           DOOR_TYPE_PASSAGE},
    {GO_MASSIVE_IRONBOUND_DOOR_5,DATA_MALKOROK,           DOOR_TYPE_PASSAGE},
    {GO_MASSIVE_IRONBOUND_DOOR_2,DATA_MALKOROK,           DOOR_TYPE_PASSAGE},
    {GO_MASSIVE_IRONBOUND_DOOR_2,DATA_SPOILS_OF_PANDARIA, DOOR_TYPE_ROOM},
    {GO_MASSIVE_IRONBOUND_DOOR_6,DATA_MALKOROK,           DOOR_TYPE_PASSAGE},
    {GO_MASSIVE_IRONBOUND_DOOR_6,DATA_SIEGECRAFTER_BLACKFUSE,DOOR_TYPE_ROOM},
    {GO_IRON_GATE_OUT_1,         DATA_SPOILS_OF_PANDARIA, DOOR_TYPE_PASSAGE},
    {GO_IRON_GATE_OUT_2,         DATA_SPOILS_OF_PANDARIA, DOOR_TYPE_PASSAGE},
    {GO_IRON_GATE_OUT_3,         DATA_SPOILS_OF_PANDARIA, DOOR_TYPE_PASSAGE},
    {GO_IRON_GATE_OUT_4,         DATA_SPOILS_OF_PANDARIA, DOOR_TYPE_PASSAGE},
    {GO_MASSIVE_IRONBOUND_DOOR_3,DATA_SPOILS_OF_PANDARIA, DOOR_TYPE_PASSAGE},
    {GO_OGRAID_LARGE_DOOR,       DATA_THOK_THE_BLOODTHIRSTY,DOOR_TYPE_ROOM},
    ///< To open this door both data required
    {GO_MASSIVE_IRONBOUND_DOOR_7,DATA_SIEGECRAFTER_BLACKFUSE,DOOR_TYPE_PASSAGE},
    {GO_MASSIVE_IRONBOUND_DOOR_7,DATA_THOK_THE_BLOODTHIRSTY, DOOR_TYPE_PASSAGE},
    {GO_MASSIVE_IRONBOUND_DOOR_7,DATA_SPOILS_OF_PANDARIA,    DOOR_TYPE_PASSAGE},
    {GO_MASSIVE_IRONBOUND_DOOR_7,DATA_PARAGONS_OF_THE_KLAXXI,DOOR_TYPE_ROOM},
    {GO_MASSIVE_IRONBOUND_DOOR_8,DATA_PARAGONS_OF_THE_KLAXXI,DOOR_TYPE_PASSAGE},
    {GO_ENTRANCE_1,              DATA_GARROSH_HELLSCREAM, DOOR_TYPE_ROOM},
    {GO_ENTRANCE_2,              DATA_GARROSH_HELLSCREAM, DOOR_TYPE_ROOM},
    {GO_SANCTUM_DOOR,            DATA_GARROSH_HELLSCREAM, DOOR_TYPE_ROOM},
    {GO_SOUTH_EAST_DOOR,         DATA_GARROSH_HELLSCREAM, DOOR_TYPE_SPAWN_HOLE},
    {GO_SOUTH_WEST_DOOR,         DATA_GARROSH_HELLSCREAM, DOOR_TYPE_SPAWN_HOLE},
    {0,                                      0,           DOOR_TYPE_ROOM},// END
};

void ApplySpellToPlayersInRange(Unit* searcher, uint32 spellId, float range, bool isAura)
{
    std::list<Player*> players;
    searcher->GetPlayerListInGrid(players, range);

    if (!players.empty())
    {
        for (std::list<Player*>::const_iterator itr = players.begin(); itr != players.end(); ++itr)
        {
            Player* player = (*itr);

            // 'GetPlayerListInGrid' check 'GetDistance' but not 'GetExactDistance'
            if (searcher->GetExactDist(player) > range)
                continue;

            if (isAura)
            {
                if (player->HasAura(spellId))
                    continue;

                searcher->AddAura(spellId, player);
            }
            else
            {
                searcher->CastSpell(player, spellId, true);
            }
        }
    }
}

CombatAuraHelper::CombatAuraHelper(Creature* owner) :
    m_Owner(owner), m_CombatAurasTimer(5000)
{
}

void CombatAuraHelper::RegisterCombatAura(uint32 spellId)
{
    m_CombatAuras.push_back(spellId);
}

void CombatAuraHelper::UnregisterCombatAura(uint32 p_SpellId)
{
    m_CombatAuras.remove(p_SpellId);
}

void AddSC_instance_siege_of_orgrimmar()
{
   
}
