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

#include "GenAI_response_parser.h"
#include "GenAI_provider.h"
#include "Log.h"
#include "Errors.h"

#include <rapidjson/document.h>

namespace FSBGenAI
{
    namespace
    {
        class OpenAIResponseParser : public IGenAIResponseParser
        {
        public:
            std::string ExtractContent(std::string const& responseJson) const override
            {
                rapidjson::Document doc;
                doc.Parse(responseJson.c_str(), responseJson.length());

                if (doc.HasParseError() || !doc.IsObject())
                {
                    TC_LOG_ERROR("scripts.fsb.genai", "FSB GenAI: JSON parse error: {}", responseJson);
                    return {};
                }

                if (doc.HasMember("choices") && doc["choices"].IsArray() && !doc["choices"].Empty())
                {
                    rapidjson::Value const& choice = doc["choices"][0];
                    if (choice.IsObject() && choice.HasMember("message") && choice["message"].IsObject())
                    {
                        rapidjson::Value const& message = choice["message"];
                        if (message.HasMember("content") && message["content"].IsString())
                            return message["content"].GetString();
                    }
                }

                TC_LOG_ERROR("scripts.fsb.genai", "FSB GenAI: unrecognized OpenAI response format: {}", responseJson);
                return {};
            }

            bool ExtractStructured(
                std::string const& jsonStr,
                std::string& reply, std::string& action, uint32& amount,
                uint8* questState = nullptr) const override
            {
                reply.clear();
                action = "none";
                amount = 0;
                if (questState)
                    *questState = 0;

                if (jsonStr.empty())
                    return false;

                rapidjson::Document doc;
                doc.Parse(jsonStr.c_str(), jsonStr.length());

                if (doc.HasParseError() || !doc.IsObject())
                {
                    TC_LOG_ERROR("scripts.fsb.genai", "FSB GenAI: structured JSON parse error: {}", jsonStr);
                    return false;
                }

                if (!doc.HasMember("reply") || !doc["reply"].IsString())
                {
                    TC_LOG_ERROR("scripts.fsb.genai", "FSB GenAI: missing/invalid 'reply' field: {}", jsonStr);
                    return false;
                }

                reply = doc["reply"].GetString();

                if (doc.HasMember("action") && doc["action"].IsString())
                    action = doc["action"].GetString();

                if (doc.HasMember("amount") && doc["amount"].IsUint())
                    amount = doc["amount"].GetUint();
                else if (doc.HasMember("amount") && doc["amount"].IsInt() && doc["amount"].GetInt() >= 0)
                    amount = static_cast<uint32>(doc["amount"].GetInt());

                if (questState && doc.HasMember("questState") && doc["questState"].IsUint())
                    *questState = static_cast<uint8>(doc["questState"].GetUint());

                return true;
            }
        };

        class AnthropicResponseParser : public IGenAIResponseParser
        {
        public:
            std::string ExtractContent(std::string const& responseJson) const override
            {
                rapidjson::Document doc;
                doc.Parse(responseJson.c_str(), responseJson.length());

                if (doc.HasParseError() || !doc.IsObject())
                {
                    TC_LOG_ERROR("scripts.fsb.genai", "FSB GenAI: JSON parse error: {}", responseJson);
                    return {};
                }

                // Check for Anthropic error format
                if (doc.HasMember("error") && doc["error"].IsObject())
                {
                    rapidjson::Value const& errorObj = doc["error"];
                    std::string errorType = "unknown";
                    std::string errorMsg = "unknown error";
                    if (errorObj.HasMember("type") && errorObj["type"].IsString())
                        errorType = errorObj["type"].GetString();
                    if (errorObj.HasMember("message") && errorObj["message"].IsString())
                        errorMsg = errorObj["message"].GetString();
                    TC_LOG_ERROR("scripts.fsb.genai", "FSB GenAI: Anthropic error ({}): {}", errorType, errorMsg);
                    return {};
                }

                // Iterate content blocks and concatenate all text blocks
                if (doc.HasMember("content") && doc["content"].IsArray())
                {
                    rapidjson::Value const& contentArray = doc["content"];
                    std::string result;
                    for (rapidjson::SizeType i = 0; i < contentArray.Size(); ++i)
                    {
                        rapidjson::Value const& block = contentArray[i];
                        if (block.IsObject() && block.HasMember("type") && block["type"].IsString())
                        {
                            std::string blockType = block["type"].GetString();
                            if (blockType == "text" && block.HasMember("text") && block["text"].IsString())
                            {
                                if (!result.empty())
                                    result += "\n";
                                result += block["text"].GetString();
                            }
                        }
                    }
                    if (!result.empty())
                        return result;
                }

                TC_LOG_ERROR("scripts.fsb.genai", "FSB GenAI: unrecognized Anthropic response format: {}", responseJson);
                return {};
            }

            bool ExtractStructured(
                std::string const& jsonStr,
                std::string& reply, std::string& action, uint32& amount,
                uint8* questState = nullptr) const override
            {
                // GetStructuredBotResponse already called ExtractContent on the raw Anthropic envelope,
                // so jsonStr here is the plain text extracted from the content block.
                if (jsonStr.empty())
                    return false;

                rapidjson::Document doc;
                doc.Parse(jsonStr.c_str(), jsonStr.length());

                if (doc.HasParseError() || !doc.IsObject())
                {
                    TC_LOG_ERROR("scripts.fsb.genai", "FSB GenAI: structured content parse error: {}", jsonStr);
                    return false;
                }

                if (!doc.HasMember("reply") || !doc["reply"].IsString())
                {
                    TC_LOG_ERROR("scripts.fsb.genai", "FSB GenAI: missing/invalid 'reply' field in structured content: {}", jsonStr);
                    return false;
                }

                reply = doc["reply"].GetString();

                if (doc.HasMember("action") && doc["action"].IsString())
                    action = doc["action"].GetString();

                if (doc.HasMember("amount") && doc["amount"].IsUint())
                    amount = doc["amount"].GetUint();
                else if (doc.HasMember("amount") && doc["amount"].IsInt() && doc["amount"].GetInt() >= 0)
                    amount = static_cast<uint32>(doc["amount"].GetInt());

                if (questState && doc.HasMember("questState") && doc["questState"].IsUint())
                    *questState = static_cast<uint8>(doc["questState"].GetUint());

                return true;
            }
        };

        static OpenAIResponseParser s_openAIParser;
        static AnthropicResponseParser s_anthropicParser;
    }

    IGenAIResponseParser const* GetResponseParser(GenAIProvider provider)
    {
        GenAIProviderPreset const& preset = GetPreset(provider);
        switch (preset.responseFormat)
        {
            case GenAIResponseFormat::AnthropicContent:
                return &s_anthropicParser;
            case GenAIResponseFormat::OpenAIChoices:
            default:
                return &s_openAIParser;
        }
    }
}
