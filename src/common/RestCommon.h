/*
 */

#ifndef TRINITYCORE_REST_COMMON_H
#define TRINITYCORE_REST_COMMON_H

class TC_GAME_API RestResponse
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
