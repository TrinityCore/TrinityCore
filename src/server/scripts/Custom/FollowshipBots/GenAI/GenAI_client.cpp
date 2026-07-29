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

#include "GenAI_client.h"
#include "GenAI_provider.h"
#include "GenAI_request_builder.h"
#include "GenAI_response_parser.h"
#include "Followship_bots_config.h"

#include "Log.h"

#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/beast/core.hpp>

#include <openssl/ssl.h>
#include <boost/beast/http.hpp>

namespace FSBGenAI
{
    bool IsEnabled()
    {
        return FollowshipBotsConfig::configFSBGenAIEnabled;
    }

    namespace
    {
        void CancelSocket(boost::asio::ip::tcp::socket& s) { s.cancel(); }
        void CancelSocket(boost::asio::ssl::stream<boost::asio::ip::tcp::socket>& s) { s.next_layer().cancel(); }

        void ShutdownSocket(boost::asio::ip::tcp::socket& s, boost::beast::error_code& ec)
        {
            s.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ec);
        }
        void ShutdownSocket(boost::asio::ssl::stream<boost::asio::ip::tcp::socket>& s, boost::beast::error_code& ec)
        {
            s.shutdown(ec);
        }

        template<typename Stream>
        std::string DoHttpExchange(Stream& stream, boost::asio::io_context& ioContext,
            std::string const& requestBody, std::string const& host,
            std::string const& target, std::string const& apiKey,
            std::string const& apiKeyHeader, std::string const& apiKeyPrefix,
            std::string const& versionHeader, int32 timeoutMs)
        {
            boost::beast::http::request<boost::beast::http::string_body> req;
            req.method(boost::beast::http::verb::post);
            req.target(target);
            req.version(11);
            req.set(boost::beast::http::field::host, host);
            req.set(boost::beast::http::field::content_type, "application/json");
            req.set(boost::beast::http::field::accept, "application/json");

            if (!apiKey.empty())
            {
                std::string headerValue = apiKeyPrefix + apiKey;
                if (apiKeyHeader == "Authorization")
                    req.set(boost::beast::http::field::authorization, headerValue);
                else
                    req.set(apiKeyHeader, headerValue);
            }

            if (!versionHeader.empty())
            {
                auto pos = versionHeader.find(':');
                if (pos != std::string::npos)
                {
                    std::string name = versionHeader.substr(0, pos);
                    std::string value = versionHeader.substr(pos + 1);
                    auto valStart = value.find_first_not_of(" \t");
                    if (valStart != std::string::npos)
                        value = value.substr(valStart);
                    if (!name.empty())
                        req.set(name, value);
                }
            }

            req.body() = requestBody;
            req.prepare_payload();

            boost::beast::http::write(stream, req);

            boost::beast::flat_buffer buffer;
            boost::beast::http::response<boost::beast::http::string_body> res;

            boost::asio::steady_timer timer(ioContext);
            timer.expires_after(std::chrono::milliseconds(timeoutMs));

            bool timedOut = false;
            boost::system::error_code readEc;

            timer.async_wait([&stream, &timedOut](boost::system::error_code ec) {
                if (!ec)
                {
                    timedOut = true;
                    CancelSocket(stream);
                }
            });

            boost::beast::http::async_read(stream, buffer, res,
                [&timer, &readEc](boost::system::error_code ec, std::size_t) {
                    readEc = ec;
                    timer.cancel();
                });

            ioContext.run();

            if (timedOut)
            {
                TC_LOG_ERROR("scripts.fsb.genai", "FSB GenAI: request timed out after {}ms", timeoutMs);
                boost::beast::error_code closeEc;
                ShutdownSocket(stream, closeEc);
                return {};
            }

            if (readEc)
            {
                TC_LOG_ERROR("scripts.fsb.genai", "FSB GenAI: HTTP read error: {}", readEc.message());
                boost::beast::error_code closeEc;
                ShutdownSocket(stream, closeEc);
                return {};
            }

            if (res.result() != boost::beast::http::status::ok)
            {
                TC_LOG_ERROR("scripts.fsb.genai", "FSB GenAI: HTTP status {} - body: {}",
                    static_cast<int>(res.result()), res.body());
                boost::beast::error_code closeEc;
                ShutdownSocket(stream, closeEc);
                return {};
            }

            boost::beast::error_code closeEc;
            ShutdownSocket(stream, closeEc);

            return res.body();
        }
    }

    std::string SendChatRequest(std::string const& requestBody)
    {
        try
        {
            TC_LOG_INFO("scripts.fsb.genai", "FSB GenAI: sending request...");

            std::string const& host = FollowshipBotsConfig::configFSBGenAIHost;
            int32 port = FollowshipBotsConfig::configFSBGenAIPort;
            std::string target = "/" + FollowshipBotsConfig::configFSBGenAIEndpoint;
            int32 timeoutMs = FollowshipBotsConfig::configFSBGenAITimeoutMs;
            bool useSSL = FollowshipBotsConfig::configFSBGenAIUseSSL;

            std::string service = (port == -1)
                ? (useSSL ? "https" : "http")
                : std::to_string(port);

            std::string hostHeader = host;
            if (port != -1)
                hostHeader += ":" + std::to_string(port);

            std::string const& apiKey = FollowshipBotsConfig::configFSBGenAIApiKey;
            std::string const& apiKeyHeader = FollowshipBotsConfig::configFSBGenAIApiKeyHeader;
            std::string const& apiKeyPrefix = FollowshipBotsConfig::configFSBGenAIApiKeyPrefix;
            std::string const& versionHeader = FollowshipBotsConfig::configFSBGenAIRequestHeader;

            TC_LOG_INFO("scripts.fsb.genai", "FSB GenAI: connecting to {}://{} (service={})",
                useSSL ? "https" : "http", host, service);

            boost::asio::io_context ioContext;
            boost::asio::ip::tcp::resolver resolver(ioContext);
            auto const results = resolver.resolve(host, service);

            if (useSSL)
            {
                boost::asio::ssl::context sslCtx(boost::asio::ssl::context::tlsv12_client);
                sslCtx.set_verify_mode(boost::asio::ssl::verify_none);

                boost::asio::ssl::stream<boost::asio::ip::tcp::socket> stream(ioContext, sslCtx);
                boost::asio::connect(stream.next_layer(), results);

                if (!SSL_set_tlsext_host_name(stream.native_handle(), host.c_str()))
                {
                    boost::system::error_code ec{static_cast<int>(::ERR_get_error()), boost::asio::error::get_ssl_category()};
                    TC_LOG_ERROR("scripts.fsb.genai", "FSB GenAI: SSL_set_tlsext_host_name failed: {}", ec.message());
                    return {};
                }

                stream.handshake(boost::asio::ssl::stream_base::client);

                return DoHttpExchange(stream, ioContext, requestBody, hostHeader, target, apiKey,
                    apiKeyHeader, apiKeyPrefix, versionHeader, timeoutMs);
            }
            else
            {
                boost::asio::ip::tcp::socket socket(ioContext);
                boost::asio::connect(socket, results);

                return DoHttpExchange(socket, ioContext, requestBody, hostHeader, target, apiKey,
                    apiKeyHeader, apiKeyPrefix, versionHeader, timeoutMs);
            }
        }
        catch (std::exception const& e)
        {
            TC_LOG_ERROR("scripts.fsb.genai", "FSB GenAI: Request exception: {}", e.what());
            return {};
        }
    }

    std::string GetBotResponse(std::string const& systemPrompt, std::string const& userMessage)
    {
        GenAIProviderPreset const& preset = GetPreset(static_cast<GenAIProvider>(FollowshipBotsConfig::configFSBGenAIProvider));
        IGenAIRequestBuilder const* builder = GetRequestBuilder(static_cast<GenAIProvider>(FollowshipBotsConfig::configFSBGenAIProvider));

        std::string requestBody = builder->BuildChatRequest(
            FollowshipBotsConfig::configFSBGenAIModel,
            FollowshipBotsConfig::configFSBGenAIMaxTokens,
            preset.supportsTemperature ? FollowshipBotsConfig::configFSBGenAITemperature : -1.0f,
            preset.supportsTopP ? FollowshipBotsConfig::configFSBGenAITopP : -1.0f,
            FollowshipBotsConfig::configFSBGenAIFrequencyPenalty,
            FollowshipBotsConfig::configFSBGenAIPresencePenalty,
            systemPrompt, userMessage,
            preset.supportsPenalties);

        TC_LOG_DEBUG("scripts.fsb.genai", "FSB GenAI: === REQUEST BODY ===\n{}", requestBody);

        std::string responseJson = SendChatRequest(requestBody);
        TC_LOG_DEBUG("scripts.fsb.genai", "FSB GenAI: === RESPONSE BODY ===\n{}", responseJson);

        IGenAIResponseParser const* parser = GetResponseParser(static_cast<GenAIProvider>(FollowshipBotsConfig::configFSBGenAIProvider));
        return parser->ExtractContent(responseJson);
    }

    std::string GetStructuredBotResponse(std::string const& systemPrompt, std::string const& userMessage)
    {
        return GetStructuredBotResponse(systemPrompt, userMessage, FollowshipBotsConfig::configFSBGenAIMaxTokens);
    }

    std::string GetStructuredBotResponse(std::string const& systemPrompt, std::string const& userMessage, int32 maxTokens)
    {
        GenAIProviderPreset const& preset = GetPreset(static_cast<GenAIProvider>(FollowshipBotsConfig::configFSBGenAIProvider));
        IGenAIRequestBuilder const* builder = GetRequestBuilder(static_cast<GenAIProvider>(FollowshipBotsConfig::configFSBGenAIProvider));

        std::string requestBody = builder->BuildStructuredRequest(
            FollowshipBotsConfig::configFSBGenAIModel,
            maxTokens,
            preset.supportsTemperature ? FollowshipBotsConfig::configFSBGenAITemperature : -1.0f,
            preset.supportsTopP ? FollowshipBotsConfig::configFSBGenAITopP : -1.0f,
            FollowshipBotsConfig::configFSBGenAIFrequencyPenalty,
            FollowshipBotsConfig::configFSBGenAIPresencePenalty,
            systemPrompt, userMessage,
            preset.supportsPenalties,
            preset.supportsResponseFormat);

        TC_LOG_DEBUG("scripts.fsb.genai", "FSB GenAI: === STRUCTURED REQUEST BODY ===\n{}", requestBody);

        std::string responseJson = SendChatRequest(requestBody);
        TC_LOG_DEBUG("scripts.fsb.genai", "FSB GenAI: === STRUCTURED RESPONSE BODY ===\n{}", responseJson);

        IGenAIResponseParser const* parser = GetResponseParser(static_cast<GenAIProvider>(FollowshipBotsConfig::configFSBGenAIProvider));
        return parser->ExtractContent(responseJson);
    }

    bool ParseStructuredResponse(std::string const& jsonStr, std::string& reply, std::string& action, uint32& amount,
        uint8* questState)
    {
        IGenAIResponseParser const* parser = GetResponseParser(static_cast<GenAIProvider>(FollowshipBotsConfig::configFSBGenAIProvider));
        return parser->ExtractStructured(jsonStr, reply, action, amount, questState);
    }
}
