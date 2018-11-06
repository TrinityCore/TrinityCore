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

#include "PlayerTaxi.h"
#include "DBCStores.h"
#include "ObjectMgr.h"
#include "Player.h"
#include <sstream>

void PlayerTaxi::InitTaxiNodesForLevel(uint32 race, uint32 chrClass, uint8 level)
{
    // class specific initial known nodes
    switch (chrClass)
    {
        case CLASS_DEATH_KNIGHT:
        {
            for (uint8 i = 0; i < TaxiMaskSize; ++i)
                m_taximask[i] |= sOldContinentsNodesMask[i];
            break;
        }
    }

    // race specific initial known nodes: capital and taxi hub masks
    switch (race)
    {
        case RACE_HUMAN:
            SetTaximaskNode(2);
            break;
        case RACE_ORC:
            SetTaximaskNode(23);
            break;
        case RACE_DWARF:
            SetTaximaskNode(6);
            break;
        case RACE_NIGHTELF:
            SetTaximaskNode(26);
            SetTaximaskNode(27);
            break;
        case RACE_UNDEAD_PLAYER:
            SetTaximaskNode(11);
            break;
        case RACE_TAUREN:
            SetTaximaskNode(22);
            break;
        case RACE_GNOME:
            SetTaximaskNode(6);
            break;
        case RACE_TROLL:
            SetTaximaskNode(23);
            break;
        case RACE_BLOODELF:
            SetTaximaskNode(82);
            break;
        case RACE_DRAENEI:
            SetTaximaskNode(94);
            break;
    }

    // new continent starting masks (It will be accessible only at new map)
    switch (Player::TeamForRace(race))
    {
        case ALLIANCE:
            SetTaximaskNode(100); // Honor Hold
            SetTaximaskNode(245); // Valiance Keep
            break;
        case HORDE:
            SetTaximaskNode(99); // Thrallmar
            SetTaximaskNode(257); // Warsong Hold
            break;
    }
    // level dependent taxi hubs
    if (level >= 68)
        SetTaximaskNode(213); // Shattered Sun Staging Area

    if (level >= 78)
        SetTaximaskNode(310); // Dalaran
}

void PlayerTaxi::LoadTaxiMask(std::string const &data)
{
    Tokenizer tokens(data, ' ');

    uint8 index = 0;
    for (Tokenizer::const_iterator iter = tokens.begin(); index < TaxiMaskSize && iter != tokens.end(); ++iter, ++index)
    {
        // load and set bits only for existing taxi nodes
        m_taximask[index] = sTaxiNodesMask[index] & atoul(*iter);
    }
}

void PlayerTaxi::AppendTaximaskTo(ByteBuffer& data, bool all)
{
    data << uint32(TaxiMaskSize);
    if (all)
    {
        for (uint8 i = 0; i < TaxiMaskSize; ++i)
            data << uint8(sTaxiNodesMask[i]);              // all existing nodes
    }
    else
    {
        for (uint8 i = 0; i < TaxiMaskSize; ++i)
            data << uint8(m_taximask[i]);                  // known nodes
    }
}

bool PlayerTaxi::LoadTaxiDestinationsFromString(std::string const& values, uint32 team)
{
    ClearTaxiDestinations();

    Tokenizer Tokenizer(values, ' ');

    for (Tokenizer::const_iterator iter = Tokenizer.begin(); iter != Tokenizer.end(); ++iter)
    {
        uint32 node = atoul(*iter);
        AddTaxiDestination(node);
    }

    if (m_TaxiDestinations.empty())
        return true;

    // Check integrity
    if (m_TaxiDestinations.size() < 2)
        return false;

    for (size_t i = 1; i < m_TaxiDestinations.size(); ++i)
    {
        uint32 cost;
        uint32 path;
        sObjectMgr->GetTaxiPath(m_TaxiDestinations[i - 1], m_TaxiDestinations[i], path, cost);
        if (!path)
            return false;
    }

    // can't load taxi path without mount set (quest taxi path?)
    if (!sObjectMgr->GetTaxiMountDisplayId(GetTaxiSource(), team, true))
        return false;

    return true;
}

std::string PlayerTaxi::SaveTaxiDestinationsToString()
{
    if (m_TaxiDestinations.empty())
        return "";

    std::ostringstream ss;

    for (size_t i = 0; i < m_TaxiDestinations.size(); ++i)
        ss << m_TaxiDestinations[i] << ' ';

    return ss.str();
}

uint32 PlayerTaxi::GetCurrentTaxiPath() const
{
    if (m_TaxiDestinations.size() < 2)
        return 0;

    uint32 path;
    uint32 cost;

    sObjectMgr->GetTaxiPath(m_TaxiDestinations[0], m_TaxiDestinations[1], path, cost);

    return path;
}

std::ostringstream& operator<<(std::ostringstream& ss, PlayerTaxi const& taxi)
{
    for (uint8 i = 0; i < TaxiMaskSize; ++i)
        ss << uint32(taxi.m_taximask[i]) << ' ';
    return ss;
}
