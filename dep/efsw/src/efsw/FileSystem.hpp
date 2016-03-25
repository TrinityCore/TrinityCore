#ifndef EFSW_FILESYSTEM_HPP
#define EFSW_FILESYSTEM_HPP

#include <efsw/base.hpp>
#include <efsw/FileInfo.hpp>
#include <map>

namespace efsw {

class FileSystem
{
	public:
		static bool isDirectory( const std::string& path );

		static FileInfoMap filesInfoFromPath( std::string path );

		static char getOSSlash();

		static bool slashAtEnd( std::string& dir );

		static void dirAddSlashAtEnd( std::string& dir );

		static void dirRemoveSlashAtEnd( std::string& dir );

		static std::string fileNameFromPath( std::string filepath );

		static std::string pathRemoveFileName( std::string filepath );

		static void realPath( std::string curdir, std::string& path );

		static std::string getLinkRealPath( std::string dir, std::string& curPath );

		static std::string precomposeFileName(const std::string& name);

		static bool isRemoteFS( const std::string& directory );
};

}

#endif
