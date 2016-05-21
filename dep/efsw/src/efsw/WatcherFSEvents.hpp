#ifndef EFSW_WATCHERINOTIFY_HPP
#define EFSW_WATCHERINOTIFY_HPP

#include <efsw/FileWatcherImpl.hpp>

#if EFSW_PLATFORM == EFSW_PLATFORM_FSEVENTS

#include <efsw/WatcherGeneric.hpp>
#include <efsw/FileInfo.hpp>
#include <CoreFoundation/CoreFoundation.h>
#include <CoreServices/CoreServices.h>
#include <set>
#include <vector>

namespace efsw {

class FileWatcherFSEvents;

class FSEvent
{
	public:
		FSEvent( std::string path, long flags, Uint64 id ) :
			Path( path ),
			Flags( flags ),
			Id ( id )
		{
		}

		std::string Path;
		long Flags;
		Uint64 Id;
};

class WatcherFSEvents : public Watcher
{
	public:
		WatcherFSEvents();
		
		WatcherFSEvents( WatchID id, std::string directory, FileWatchListener * listener, bool recursive, WatcherFSEvents * parent = NULL );
		
		~WatcherFSEvents();

		void init();

		void initAsync();

		void handleActions( std::vector<FSEvent> & events );

		void process();

		FileWatcherFSEvents * FWatcher;

		FSEventStreamRef FSStream;
	protected:
		void handleAddModDel( const Uint32 &flags, const std::string &path, std::string &dirPath, std::string &filePath );

		WatcherGeneric * WatcherGen;

		bool initializedAsync;

		std::set<std::string> DirsChanged;

		void sendFileAction( WatchID watchid, const std::string& dir, const std::string& filename, Action action, std::string oldFilename = "" );
};

}

#endif

#endif
