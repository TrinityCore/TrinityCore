#include "Revision.h"
#include "CompilerDefs.h"
#include "revision_data.h"

char const* Revision::GetHash()
{
    return _HASH;
}

char const* Revision::GetDate()
{
    return _DATE;
}

char const* Revision::GetBranch()
{
    return _BRANCH;
}

char const* Revision::GetSourceDirectory()
{
    return _SOURCE_DIRECTORY;
}

char const* Revision::GetMySQLExecutable()
{
    return _MYSQL_EXECUTABLE;
}

char const* Revision::GetFullDatabase()
{
    return _FULL_DATABASE;
}

#define _PACKAGENAME "TrinityCore"

char const* Revision::GetFullVersion()
{
#if PLATFORM == PLATFORM_WINDOWS
# ifdef _WIN64
    return _PACKAGENAME " rev. " VER_PRODUCTVERSION_STR " (Win64, " _BUILD_DIRECTIVE ")";
# else
    return _PACKAGENAME " rev. " VER_PRODUCTVERSION_STR " (Win32, " _BUILD_DIRECTIVE ")";
# endif
#else
    return _PACKAGENAME " rev. " VER_PRODUCTVERSION_STR " (Unix, " _BUILD_DIRECTIVE ")";
#endif
}

char const* GetCompanyNameStr()
{
    return VER_COMPANYNAME_STR;
}

char const* GetLegalCopyrightStr()
{
    return VER_LEGALCOPYRIGHT_STR;
}

char const* GetFileVersionStr()
{
    return VER_FILEVERSION_STR;
}

char const* GetProductVersionStr()
{
    return VER_PRODUCTVERSION_STR;
}
