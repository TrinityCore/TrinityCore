#include <efsw/WatcherInotify.hpp>

namespace efsw {

WatcherInotify::WatcherInotify() :
	Watcher(),
	Parent( NULL )
{
}

WatcherInotify::WatcherInotify( WatchID id, std::string directory, FileWatchListener * listener, bool recursive, WatcherInotify * parent ) :
	Watcher( id, directory, listener, recursive ),
	Parent( parent ),
	DirInfo( directory )
{
}

bool WatcherInotify::inParentTree( WatcherInotify * parent )
{
	WatcherInotify * tNext = Parent;

	while ( NULL != tNext )
	{
		if ( tNext == parent )
		{
			return true;
		}

		tNext = tNext->Parent;
	}

	return false;
}
	
} 
