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

#include "Common.h"
#include "GenAI_provider.h"

namespace FSBGenAI
{
    static GenAIProviderPreset const s_presets[] =
    {
        // Custom (0)
        {
            .name = "Custom",
            .host = "",
            .endpoint = "",
            .port = -1,
            .useSSL = false,
            .apiKeyHeader = "Authorization",
            .apiKeyPrefix = "Bearer ",
            .versionHeader = "",
            .requestFormat = GenAIRequestFormat::OpenAIChat,
            .responseFormat = GenAIResponseFormat::OpenAIChoices,
            .supportsTemperature = true,
            .supportsTopP = true,
            .supportsPenalties = true,
            .supportsSystemParameter = false,
            .supportsResponseFormat = true
        },
        // OpenAI (1)
        {
            .name = "OpenAI",
            .host = "api.openai.com",
            .endpoint = "v1/chat/completions",
            .port = -1,
            .useSSL = true,
            .apiKeyHeader = "Authorization",
            .apiKeyPrefix = "Bearer ",
            .versionHeader = "",
            .requestFormat = GenAIRequestFormat::OpenAIChat,
            .responseFormat = GenAIResponseFormat::OpenAIChoices,
            .supportsTemperature = true,
            .supportsTopP = true,
            .supportsPenalties = true,
            .supportsSystemParameter = false,
            .supportsResponseFormat = true
        },
        // Anthropic (2)
        {
            .name = "Anthropic",
            .host = "api.anthropic.com",
            .endpoint = "v1/messages",
            .port = -1,
            .useSSL = true,
            .apiKeyHeader = "x-api-key",
            .apiKeyPrefix = "",
            .versionHeader = "anthropic-version: 2023-06-01",
            .requestFormat = GenAIRequestFormat::AnthropicMessages,
            .responseFormat = GenAIResponseFormat::AnthropicContent,
            .supportsTemperature = false,
            .supportsTopP = true,
            .supportsPenalties = false,
            .supportsSystemParameter = true,
            .supportsResponseFormat = false
        },
        // LlamaServer (3)
        {
            .name = "LlamaServer",
            .host = "127.0.0.1",
            .endpoint = "v1/chat/completions",
            .port = 8080,
            .useSSL = false,
            .apiKeyHeader = "Authorization",
            .apiKeyPrefix = "Bearer ",
            .versionHeader = "",
            .requestFormat = GenAIRequestFormat::OpenAIChat,
            .responseFormat = GenAIResponseFormat::OpenAIChoices,
            .supportsTemperature = true,
            .supportsTopP = true,
            .supportsPenalties = true,
            .supportsSystemParameter = false,
            .supportsResponseFormat = true
        },
        // LMStudio (4)
        {
            .name = "LMStudio",
            .host = "127.0.0.1",
            .endpoint = "v1/chat/completions",
            .port = 1234,
            .useSSL = false,
            .apiKeyHeader = "Authorization",
            .apiKeyPrefix = "Bearer ",
            .versionHeader = "",
            .requestFormat = GenAIRequestFormat::OpenAIChat,
            .responseFormat = GenAIResponseFormat::OpenAIChoices,
            .supportsTemperature = true,
            .supportsTopP = true,
            .supportsPenalties = true,
            .supportsSystemParameter = false,
            .supportsResponseFormat = true
        },
        // OpenRouter (5)
        {
            .name = "OpenRouter",
            .host = "openrouter.ai",
            .endpoint = "api/v1/chat/completions",
            .port = -1,
            .useSSL = true,
            .apiKeyHeader = "Authorization",
            .apiKeyPrefix = "Bearer ",
            .versionHeader = "",
            .requestFormat = GenAIRequestFormat::OpenAIChat,
            .responseFormat = GenAIResponseFormat::OpenAIChoices,
            .supportsTemperature = true,
            .supportsTopP = true,
            .supportsPenalties = true,
            .supportsSystemParameter = false,
            .supportsResponseFormat = true
        },
    };

    static_assert(sizeof(s_presets) / sizeof(s_presets[0]) == 6, "GenAIProviderPreset array size must match GenAIProvider enum count");

    GenAIProviderPreset const& GetPreset(GenAIProvider provider)
    {
        size_t index = static_cast<size_t>(provider);
        if (index >= sizeof(s_presets) / sizeof(s_presets[0]))
            index = 0;
        return s_presets[index];
    }
}
