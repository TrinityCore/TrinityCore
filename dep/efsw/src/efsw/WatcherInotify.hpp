#ifndef EFSW_WATCHERINOTIFY_HPP 
#define EFSW_WATCHERINOTIFY_HPP

#include <efsw/FileWatcherImpl.hpp>
#include <efsw/FileInfo.hpp>

namespace efsw {

class WatcherInotify : public Watcher
{
	public:
		WatcherInotify();
		
		WatcherInotify( WatchID id, std::string directory, FileWatchListener * listener, bool recursive, WatcherInotify * parent = NULL );

		bool inParentTree( WatcherInotify * parent );

		WatcherInotify * Parent;

		FileInfo DirInfo;
};

}

#endif
