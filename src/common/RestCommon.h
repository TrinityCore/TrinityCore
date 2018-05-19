/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#ifndef TRINITYCORE_REST_COMMON_H
#define TRINITYCORE_REST_COMMON_H

class RestResponse
{
public:
    std::unordered_map<std::string, std::string> datas;

    RestResponse()
    {
        datas["success"] = "false";
        datas["message"] = "";
    }

    void setSuccess(std::string successData = "")
    {
        datas["success"] = "true";
        datas["message"] = successData;
    }

    void setError(std::string errorMessage)
    {
        datas["success"] = "false";
        datas["message"] = errorMessage;
    }

    std::string serialize()
    {
        std::ostringstream serializedData;
        serializedData << "{";
        bool first = true;

        for (std::pair<std::string, std::string> data : datas)
        {
            if (!first)
            {
                serializedData << ",";
            }

            serializedData << '"' << data.first << '"' << ":" << '"' << data.second << '"';
            first = false;
        }
        serializedData << "}";

        return serializedData.str();
    }
};

#endif
