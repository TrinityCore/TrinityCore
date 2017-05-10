#include <efsw/FileWatcherGeneric.hpp>
#include <efsw/FileSystem.hpp>
#include <efsw/System.hpp>

namespace efsw
{

FileWatcherGeneric::FileWatcherGeneric( FileWatcher * parent ) :
	FileWatcherImpl( parent ),
	mThread( NULL ),
	mLastWatchID( 0 )
{
	mInitOK = true;
	mIsGeneric = true;
}

FileWatcherGeneric::~FileWatcherGeneric()
{
	mInitOK = false;

	mThread->wait();

	efSAFE_DELETE( mThread );

	/// Delete the watches
	WatchList::iterator it = mWatches.begin();

	for ( ; it != mWatches.end(); it++ )
	{
		efSAFE_DELETE( (*it) );
	}
}

WatchID FileWatcherGeneric::addWatch(const std::string& directory, FileWatchListener* watcher, bool recursive)
{
	std::string dir( directory );

	FileSystem::dirAddSlashAtEnd( dir );

	FileInfo fi( dir );

	if ( !fi.isDirectory() )
	{
		return Errors::Log::createLastError( Errors::FileNotFound, dir );
	}
	else if ( !fi.isReadable() )
	{
		return Errors::Log::createLastError( Errors::FileNotReadable, dir );
	}
	else if ( pathInWatches( dir ) )
	{
		return Errors::Log::createLastError( Errors::FileRepeated, dir );
	}

	std::string curPath;
	std::string link( FileSystem::getLinkRealPath( dir, curPath ) );

	if ( "" != link )
	{
		if ( pathInWatches( link ) )
		{
			return Errors::Log::createLastError( Errors::FileRepeated, dir );
		}
		else if ( !linkAllowed( curPath, link ) )
		{
			return Errors::Log::createLastError( Errors::FileOutOfScope, dir );
		}
		else
		{
			dir = link;
		}
	}

	mLastWatchID++;

	WatcherGeneric * pWatch		= new WatcherGeneric( mLastWatchID, dir, watcher, this, recursive );

	mWatchesLock.lock();
	mWatches.push_back(pWatch);
	mWatchesLock.unlock();

	return pWatch->ID;
}

void FileWatcherGeneric::removeWatch( const std::string& directory )
{
	WatchList::iterator it = mWatches.begin();

	for ( ; it != mWatches.end(); it++ )
	{
		if ( (*it)->Directory == directory )
		{
			WatcherGeneric * watch = (*it);

			mWatchesLock.lock();

			mWatches.erase( it );

			efSAFE_DELETE( watch ) ;

			mWatchesLock.unlock();

			return;
		}
	}
}

void FileWatcherGeneric::removeWatch(WatchID watchid)
{
	WatchList::iterator it = mWatches.begin();

	for ( ; it != mWatches.end(); it++ )
	{
		if ( (*it)->ID == watchid )
		{
			WatcherGeneric * watch = (*it);

			mWatchesLock.lock();

			mWatches.erase( it );

			efSAFE_DELETE( watch ) ;

			mWatchesLock.unlock();

			return;
		}
	}
}

void FileWatcherGeneric::watch()
{
	if ( NULL == mThread )
	{
		mThread = new Thread( &FileWatcherGeneric::run, this );
		mThread->launch();
	}
}

void FileWatcherGeneric::run()
{
	do
	{
		mWatchesLock.lock();

		WatchList::iterator it = mWatches.begin();

		for ( ; it != mWatches.end(); it++ )
		{
			(*it)->watch();
		}

		mWatchesLock.unlock();

		if ( mInitOK ) System::sleep( 1000 );
	} while ( mInitOK );
}

void FileWatcherGeneric::handleAction(Watcher * watch, const std::string& filename, unsigned long action, std::string oldFilename)
{
	/// Not used
}

std::list<std::string> FileWatcherGeneric::directories()
{
	std::list<std::string> dirs;

	mWatchesLock.lock();

	WatchList::iterator it = mWatches.begin();

	for ( ; it != mWatches.end(); it++ )
	{
		dirs.push_back( (*it)->Directory );
	}

	mWatchesLock.unlock();

	return dirs;
}

bool FileWatcherGeneric::pathInWatches( const std::string& path )
{
	WatchList::iterator it = mWatches.begin();

	for ( ; it != mWatches.end(); it++ )
	{
		if ( (*it)->Directory == path || (*it)->pathInWatches( path ) )
		{
			return true;
		}
	}

	return false;
}

}
