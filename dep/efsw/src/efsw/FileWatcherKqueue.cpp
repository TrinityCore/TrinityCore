#include <efsw/FileWatcherKqueue.hpp>

#if EFSW_PLATFORM == EFSW_PLATFORM_KQUEUE || EFSW_PLATFORM == EFSW_PLATFORM_FSEVENTS

#include <sys/time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <efsw/FileSystem.hpp>
#include <efsw/System.hpp>
#include <efsw/Debug.hpp>
#include <efsw/WatcherGeneric.hpp>

namespace efsw
{

FileWatcherKqueue::FileWatcherKqueue( FileWatcher * parent ) :
	FileWatcherImpl( parent ),
	mLastWatchID(0),
	mThread( NULL ),
	mFileDescriptorCount( 1 ),
	mAddingWatcher( false )
{
	mTimeOut.tv_sec		= 0;
	mTimeOut.tv_nsec	= 0;
	mInitOK				= true;
}

FileWatcherKqueue::~FileWatcherKqueue()
{
	WatchMap::iterator iter = mWatches.begin();

	for(; iter != mWatches.end(); ++iter)
	{
		efSAFE_DELETE( iter->second );
	}

	mWatches.clear();

	mInitOK = false;

	mThread->wait();

	efSAFE_DELETE( mThread );
}

WatchID FileWatcherKqueue::addWatch(const std::string& directory, FileWatchListener* watcher, bool recursive)
{
	static bool s_ug = false;

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
		return Errors::Log::createLastError( Errors::FileRepeated, directory );
	}

	std::string curPath;
	std::string link( FileSystem::getLinkRealPath( dir, curPath ) );

	if ( "" != link )
	{
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

	/// Check first if are enough file descriptors available to create another kqueue watcher, otherwise it creates a generic watcher
	if ( availablesFD() )
	{
		mAddingWatcher = true;

		WatcherKqueue * watch = new WatcherKqueue( ++mLastWatchID, dir, watcher, recursive, this );

		mWatchesLock.lock();
		mWatches.insert(std::make_pair(mLastWatchID, watch));
		mWatchesLock.unlock();

		watch->addAll();

		// if failed to open the directory... erase the watcher
		if ( !watch->initOK() )
		{
			int le = watch->lastErrno();

			mWatches.erase( watch->ID );

			efSAFE_DELETE( watch );

			mLastWatchID--;

			// Probably the folder has too many files, create a generic watcher
			if ( EACCES != le )
			{
				WatcherGeneric * watch = new WatcherGeneric( ++mLastWatchID, dir, watcher, this, recursive );

				mWatchesLock.lock();
				mWatches.insert(std::make_pair(mLastWatchID, watch));
				mWatchesLock.unlock();
			}
			else
			{
				return Errors::Log::createLastError( Errors::Unspecified, link );
			}
		}

		mAddingWatcher = false;
	}
	else
	{
		if ( !s_ug )
		{
			efDEBUG( "Started using generic watcher, file descriptor limit reached: %ld\n", mFileDescriptorCount );
			s_ug = true;
		}

		WatcherGeneric * watch = new WatcherGeneric( ++mLastWatchID, dir, watcher, this, recursive );

		mWatchesLock.lock();
		mWatches.insert(std::make_pair(mLastWatchID, watch));
		mWatchesLock.unlock();
	}

	return mLastWatchID;
}

void FileWatcherKqueue::removeWatch(const std::string& directory)
{
	mWatchesLock.lock();

	WatchMap::iterator iter = mWatches.begin();

	for(; iter != mWatches.end(); ++iter)
	{
		if(directory == iter->second->Directory)
		{
			removeWatch(iter->first);
			return;
		}
	}

	mWatchesLock.unlock();
}

void FileWatcherKqueue::removeWatch(WatchID watchid)
{
	mWatchesLock.lock();

	WatchMap::iterator iter = mWatches.find(watchid);

	if(iter == mWatches.end())
		return;

	Watcher* watch = iter->second;

	mWatches.erase(iter);

	efSAFE_DELETE( watch );

	mWatchesLock.unlock();
}

bool FileWatcherKqueue::isAddingWatcher() const
{
	return mAddingWatcher;
}

void FileWatcherKqueue::watch()
{
	if ( NULL == mThread )
	{
		mThread = new Thread( &FileWatcherKqueue::run, this );
		mThread->launch();
	}
}

void FileWatcherKqueue::run()
{
	do
	{
		mWatchesLock.lock();

		for ( WatchMap::iterator it = mWatches.begin(); it != mWatches.end(); ++it )
		{
			it->second->watch();
		}

		mWatchesLock.unlock();

		System::sleep( 500 );
	} while( mInitOK );
}

void FileWatcherKqueue::handleAction(Watcher* watch, const std::string& filename, unsigned long action, std::string oldFilename)
{
}

std::list<std::string> FileWatcherKqueue::directories()
{
	std::list<std::string> dirs;

	mWatchesLock.lock();

	WatchMap::iterator it = mWatches.begin();

	for ( ; it != mWatches.end(); it++ )
	{
		dirs.push_back( it->second->Directory );
	}

	mWatchesLock.unlock();

	return dirs;
}

bool FileWatcherKqueue::pathInWatches( const std::string& path )
{
	WatchMap::iterator it = mWatches.begin();

	for ( ; it != mWatches.end(); it++ )
	{
		if ( it->second->Directory == path )
		{
			return true;
		}
	}

	return false;
}

void FileWatcherKqueue::addFD()
{
	mFileDescriptorCount++;
}

void FileWatcherKqueue::removeFD()
{
	mFileDescriptorCount--;
}

bool FileWatcherKqueue::availablesFD()
{
	return mFileDescriptorCount <= (Int64)System::getMaxFD() - 500;
}

}

#endif
