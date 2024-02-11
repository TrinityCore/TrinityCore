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

#ifndef TRINITYCORE_HTTP_COMMON_H
#define TRINITYCORE_HTTP_COMMON_H

#include "Define.h"
#include <boost/beast/http/message.hpp>
#include <boost/beast/http/string_body.hpp>

namespace Trinity::Net::Http
{
using RequestBody = boost::beast::http::string_body;
using ResponseBody = boost::beast::http::string_body;

using Request = boost::beast::http::request<RequestBody>;
using Response = boost::beast::http::response<ResponseBody>;

struct RequestContext
{
    Request request;
    Response response;
    struct RequestHandler const* handler = nullptr;
};

TC_SHARED_API bool CanLogRequestContent(RequestContext const& context);
TC_SHARED_API bool CanLogResponseContent(RequestContext const& context);

inline std::string_view ToStdStringView(boost::beast::string_view bsw)
{
    return { bsw.data(), bsw.size() };
}

enum class RequestHandlerResult
{
    Handled,
    Error,
    Async,
};
}
#endif // TRINITYCORE_HTTP_COMMON_H
