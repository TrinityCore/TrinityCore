#include "AuthCodes.h"

namespace AuthHelper
{
    bool IsAcceptedBuild(int build)
    {
        static int accepted_versions[] = TRINITYCORE_ACCEPTED_CLIENT_BUILD;

        for (int i = 0; accepted_versions[i]; ++i)
            if (build == accepted_versions[i])
                return true;

        return false;
    }

    bool IsAcceptedClientBuild(int build)
    {
        return (IsAcceptedBuild(build));
    }
};
