#include <efsw/FileWatcherFSEvents.hpp>
#include <efsw/FileSystem.hpp>
#include <efsw/System.hpp>
#include <efsw/Debug.hpp>
#include <efsw/String.hpp>

#if EFSW_PLATFORM == EFSW_PLATFORM_FSEVENTS

#include <sys/utsname.h>

namespace efsw
{

int getOSXReleaseNumber()
{
	static int osxR = -1;

	if ( -1 == osxR )
	{
		struct utsname os;

		if ( -1 != uname( &os ) ) {
			std::string release( os.release );
			
			size_t pos = release.find_first_of( '.' );
			
			if ( pos != std::string::npos )
			{
				release = release.substr( 0, pos );
			}
			
			int rel = 0;
			
			if ( String::fromString<int>( rel, release ) )
			{
				osxR = rel;
			}
		}
	}
	
	return osxR;
}

bool FileWatcherFSEvents::isGranular()
{
	return getOSXReleaseNumber() >= 11;
}

void FileWatcherFSEvents::FSEventCallback(	ConstFSEventStreamRef streamRef,
												void *userData, 
												size_t numEvents, 
												void *eventPaths, 
												const FSEventStreamEventFlags eventFlags[], 
												const FSEventStreamEventId eventIds[] )
{
	WatcherFSEvents * watcher = static_cast<WatcherFSEvents*>( userData );

	std::vector<FSEvent> events;
	events.reserve( numEvents );

	for ( size_t i = 0; i < numEvents; i++ )
	{
		events.push_back( FSEvent( std::string( ((char**)eventPaths)[i] ), (long)eventFlags[i], (Uint64)eventIds[i] ) );
	}

	watcher->handleActions( events );

	watcher->process();

	efDEBUG( "\n" );
}

FileWatcherFSEvents::FileWatcherFSEvents( FileWatcher * parent ) :
	FileWatcherImpl( parent ),
	mRunLoopRef( NULL ),
	mLastWatchID(0),
	mThread( NULL )
{
	mInitOK = true;
	
	watch();
}

FileWatcherFSEvents::~FileWatcherFSEvents()
{
	WatchMap::iterator iter = mWatches.begin();

	for( ; iter != mWatches.end(); ++iter )
	{
		WatcherFSEvents * watch = iter->second;
		
		efSAFE_DELETE( watch );
	}

	mWatches.clear();

	mInitOK = false;
	
	if ( NULL != mRunLoopRef )
	{
		CFRunLoopStop( mRunLoopRef );
	}

	efSAFE_DELETE( mThread );
}

WatchID FileWatcherFSEvents::addWatch( const std::string& directory, FileWatchListener* watcher, bool recursive )
{
	/// Wait to the RunLoopRef to be ready
	while ( NULL == mRunLoopRef )
	{
		System::sleep( 1 );
	}
	
	std::string dir( directory );

	FileInfo fi( dir );

	if ( !fi.isDirectory() )
	{
		return Errors::Log::createLastError( Errors::FileNotFound, dir );
	}
	else if ( !fi.isReadable() )
	{
		return Errors::Log::createLastError( Errors::FileNotReadable, dir );
	}

	FileSystem::dirAddSlashAtEnd( dir );

	if ( pathInWatches( dir ) )
	{
		return Errors::Log::createLastError( Errors::FileRepeated, directory );
	}

	/// Check if the directory is a symbolic link
	std::string curPath;
	std::string link( FileSystem::getLinkRealPath( dir, curPath ) );

	if ( "" != link )
	{
		/// If it's a symlink check if the realpath exists as a watcher, or
		/// if the path is outside the current dir
		if ( pathInWatches( link ) )
		{
			return Errors::Log::createLastError( Errors::FileRepeated, directory );
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

	WatcherFSEvents * pWatch	= new WatcherFSEvents();
	pWatch->Listener			= watcher;
	pWatch->ID					= mLastWatchID;
	pWatch->Directory			= dir;
	pWatch->Recursive			= recursive;
	pWatch->FWatcher			= this;
	
	pWatch->init();

	mWatchesLock.lock();
	mWatches.insert(std::make_pair(mLastWatchID, pWatch));
	mWatchesLock.unlock();

	return pWatch->ID;
}

void FileWatcherFSEvents::removeWatch(const std::string& directory)
{
	mWatchesLock.lock();

	WatchMap::iterator iter = mWatches.begin();

	for(; iter != mWatches.end(); ++iter)
	{
		if( directory == iter->second->Directory )
		{
			removeWatch( iter->second->ID );
			return;
		}
	}

	mWatchesLock.unlock();
}

void FileWatcherFSEvents::removeWatch(WatchID watchid)
{
	mWatchesLock.lock();

	WatchMap::iterator iter = mWatches.find( watchid );

	if( iter == mWatches.end() )
		return;

	WatcherFSEvents * watch = iter->second;

	mWatches.erase( iter );

	efDEBUG( "Removed watch %s\n", watch->Directory.c_str() );

	efSAFE_DELETE( watch );

	mWatchesLock.unlock();
}

void FileWatcherFSEvents::watch()
{
	if ( NULL == mThread )
	{
		mThread = new Thread( &FileWatcherFSEvents::run, this );
		mThread->launch();
	}
}

void FileWatcherFSEvents::run()
{
	mRunLoopRef = CFRunLoopGetCurrent();
	
	while ( mInitOK )
	{
		if ( !mNeedInit.empty() )
		{
			for ( std::list<WatcherFSEvents*>::iterator it = mNeedInit.begin(); it != mNeedInit.end(); it++ )
			{
				(*it)->initAsync();
			}

			mNeedInit.clear();
		}

		CFRunLoopRunInMode( kCFRunLoopDefaultMode, 0.5, kCFRunLoopRunTimedOut );
	}
}

void FileWatcherFSEvents::handleAction(Watcher* watch, const std::string& filename, unsigned long action, std::string oldFilename)
{
	/// Not used
}

std::list<std::string> FileWatcherFSEvents::directories()
{
	std::list<std::string> dirs;

	mWatchesLock.lock();

	for ( WatchMap::iterator it = mWatches.begin(); it != mWatches.end(); it++ )
	{
		dirs.push_back( std::string( it->second->Directory ) );
	}

	mWatchesLock.unlock();

	return dirs;
}

bool FileWatcherFSEvents::pathInWatches( const std::string& path )
{
	for ( WatchMap::iterator it = mWatches.begin(); it != mWatches.end(); it++ )
	{
		if ( it->second->Directory == path )
		{
			return true;
		}
	}

	return false;
}

}

#endif
