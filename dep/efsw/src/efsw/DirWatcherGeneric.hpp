#ifndef EFSW_DIRWATCHERGENERIC_HPP
#define EFSW_DIRWATCHERGENERIC_HPP

#include <efsw/WatcherGeneric.hpp>
#include <efsw/FileInfo.hpp>
#include <efsw/DirectorySnapshot.hpp>
#include <map>

namespace efsw {

class DirWatcherGeneric
{
	public:
		typedef std::map<std::string, DirWatcherGeneric*> DirWatchMap;

		DirWatcherGeneric *	Parent;
		WatcherGeneric *	Watch;
		DirectorySnapshot	DirSnap;
		DirWatchMap			Directories;
		bool				Recursive;

		DirWatcherGeneric( DirWatcherGeneric * parent, WatcherGeneric * ws, const std::string& directory, bool recursive, bool reportNewFiles = false );

		~DirWatcherGeneric();

		void watch( bool reportOwnChange = false );

		void watchDir( std::string& dir );

		static bool isDir( const std::string& directory );

		bool pathInWatches( std::string path );

		void addChilds( bool reportNewFiles = true );

		DirWatcherGeneric * findDirWatcher( std::string dir );

		DirWatcherGeneric * findDirWatcherFast( std::string dir );
	protected:
		bool				Deleted;

		DirWatcherGeneric * createDirectory( std::string newdir );

		void removeDirectory( std::string dir );

		void moveDirectory( std::string oldDir, std::string newDir );

		void resetDirectory( std::string directory );

		void handleAction( const std::string& filename, unsigned long action, std::string oldFilename = "");
};

}

#endif
