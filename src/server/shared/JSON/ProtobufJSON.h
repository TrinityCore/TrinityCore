/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#ifndef ProtobufJSON_h__
#define ProtobufJSON_h__

#include "Define.h"
#include <google/protobuf/message.h>
#include <string>

namespace JSON
{
    TC_SHARED_API std::string Serialize(google::protobuf::Message const& message);
    TC_SHARED_API bool Deserialize(std::string json, google::protobuf::Message* message);
}

#endif // ProtobufJSON_h__
