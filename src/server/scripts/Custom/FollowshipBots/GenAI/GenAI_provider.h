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

#include <string_view>
#include <cstdint>
#include "Common.h"

namespace FSBGenAI
{
    enum class GenAIProvider : uint8
    {
        Custom      = 0,
        OpenAI      = 1,
        Anthropic   = 2,
        LlamaServer = 3,
        LMStudio    = 4,
        OpenRouter  = 5,
    };

    enum class GenAIRequestFormat : uint8
    {
        OpenAIChat,
        AnthropicMessages,
    };

    enum class GenAIResponseFormat : uint8
    {
        OpenAIChoices,
        AnthropicContent,
    };

    struct GenAIProviderPreset
    {
        std::string_view name;
        std::string_view host;
        std::string_view endpoint;
        int32 port;
        bool useSSL;
        std::string_view apiKeyHeader;
        std::string_view apiKeyPrefix;
        std::string_view versionHeader;
        GenAIRequestFormat requestFormat;
        GenAIResponseFormat responseFormat;
        bool supportsTemperature;
        bool supportsTopP;
        bool supportsPenalties;
        bool supportsSystemParameter;
        bool supportsResponseFormat;
    };

    GenAIProviderPreset const& GetPreset(GenAIProvider provider);
}
