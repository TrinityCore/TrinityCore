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

#pragma once

#include <string>
#include <cstdint>
#include "GenAI_provider.h"

namespace FSBGenAI
{
    class IGenAIResponseParser
    {
    public:
        virtual std::string ExtractContent(std::string const& responseJson) const = 0;
        virtual bool ExtractStructured(
            std::string const& jsonStr,
            std::string& reply, std::string& action, uint32& amount,
            uint8* questState = nullptr) const = 0;
        virtual ~IGenAIResponseParser() = default;
    };

    IGenAIResponseParser const* GetResponseParser(GenAIProvider provider);
}
