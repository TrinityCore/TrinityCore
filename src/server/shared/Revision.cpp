#include "Revision.h"
#include "CompilerDefs.h"
#include "revision_data.h"

std::string Revision::GetPackageName()
{
    return "TrinityCore";
}

std::string Revision::GetHash()
{
    return _HASH;
}

std::string Revision::GetDate()
{
    return _DATE;
}

std::string Revision::GetBranch()
{
    return _BRANCH;
}

std::string Revision::GetSourceDirectory()
{
    return _SOURCE_DIRECTORY;
}

std::string Revision::GetMySQLExecutable()
{
    return _MYSQL_EXECUTABLE;
}

std::string Revision::GetFullDatabase()
{
    return _FULL_DATABASE;
}

std::string Revision::GetFullVersion()
{
#if PLATFORM == PLATFORM_WINDOWS
# ifdef _WIN64
    return GetPackageName() + " rev. " + VER_PRODUCTVERSION_STR + " (Win64, " + _BUILD_DIRECTIVE + ")";
# else
    return GetPackageName() + " rev. " + VER_PRODUCTVERSION_STR + " (Win32, " + _BUILD_DIRECTIVE + ")";
# endif
#else
    return GetPackageName() + " rev. " + VER_PRODUCTVERSION_STR + " (Unix, " + _BUILD_DIRECTIVE + ")";
#endif
}

std::string GetCompanyNameStr()
{
    return VER_COMPANYNAME_STR;
}

std::string GetLegalCopyrightStr()
{
    return VER_LEGALCOPYRIGHT_STR;
}

std::string GetFileVersionStr()
{
    return VER_FILEVERSION_STR;
}

std::string GetProductVersionStr()
{
    return VER_PRODUCTVERSION_STR;
}
