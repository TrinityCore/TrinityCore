#include <efsw/platform/win/FileSystemImpl.hpp>

#if EFSW_PLATFORM == EFSW_PLATFORM_WIN32

#ifndef WIN32_LEAN_AND_MEAN
	#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

#ifndef EFSW_COMPILER_MSVC
#include <dirent.h>
#endif

namespace efsw { namespace Platform {

FileInfoMap FileSystem::filesInfoFromPath( const std::string& path )
{
	FileInfoMap files;

	String tpath( path );

	if ( tpath[ tpath.size() - 1 ] == '/' || tpath[ tpath.size() - 1 ] == '\\' )
	{
		tpath += "*";
	}
	else
	{
		tpath += "\\*";
	}

	WIN32_FIND_DATAW findFileData;
	HANDLE hFind = FindFirstFileW( (LPCWSTR)tpath.toWideString().c_str(), &findFileData );

	if( hFind != INVALID_HANDLE_VALUE )
	{
		std::string name( String( findFileData.cFileName ).toUtf8() );
		std::string fpath( path + name );

		if ( name != "." && name != ".." )
		{
			files[ name ] = FileInfo( fpath );
		}

		while( FindNextFileW( hFind, &findFileData ) )
		{
			name = String( findFileData.cFileName ).toUtf8();
			fpath = path + name;

			if ( name != "." && name != ".." )
			{
				files[ name ] = FileInfo( fpath );
			}
		}

		FindClose( hFind );
	}

	return files;
}

char FileSystem::getOSSlash()
{
	return '\\';
}

bool FileSystem::isDirectory( const std::string& path )
{
	return 0 != ( GetFileAttributesW( String( path ).toWideString().c_str() ) & FILE_ATTRIBUTE_DIRECTORY );
}

bool FileSystem::isRemoteFS( const std::string& directory )
{
	if ((directory[0] == '\\' || directory[0] == '/')  &&
		(directory[1] == '\\' || directory[1] == '/'))
	{
		return true;
	}

	if ( directory.size() >= 3 )
	{
		return 4 == GetDriveTypeA( directory.substr( 0, 3 ).c_str() );
	}

	return false;
}

}}

#endif
