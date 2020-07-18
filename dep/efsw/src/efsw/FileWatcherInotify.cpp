#include <efsw/FileWatcherInotify.hpp>

#if EFSW_PLATFORM == EFSW_PLATFORM_INOTIFY

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

#ifdef EFSW_INOTIFY_NOSYS
#include <efsw/inotify-nosys.h>
#else
#include <sys/inotify.h>
#endif

#include <efsw/FileSystem.hpp>
#include <efsw/System.hpp>
#include <efsw/Debug.hpp>
#include <efsw/Lock.hpp>
#include <efsw/String.hpp>

#define BUFF_SIZE ((sizeof(struct inotify_event)+FILENAME_MAX)*1024)

namespace efsw
{

FileWatcherInotify::FileWatcherInotify( FileWatcher * parent ) :
	FileWatcherImpl( parent ),
	mFD(-1),
	mThread(NULL)
{
	mFD = inotify_init();

	if (mFD < 0)
	{
		efDEBUG( "Error: %s\n", strerror(errno) );
	}
	else
	{
		mInitOK = true;
	}
}

FileWatcherInotify::~FileWatcherInotify()
{
	mInitOK = false;

	efSAFE_DELETE( mThread );
	
	WatchMap::iterator iter = mWatches.begin();
	WatchMap::iterator end = mWatches.end();

	for(; iter != end; ++iter)
	{
		efSAFE_DELETE( iter->second );
	}

	mWatches.clear();

	if ( mFD != -1 )
	{
		close(mFD);
		mFD = -1;
	}
}

WatchID FileWatcherInotify::addWatch( const std::string& directory, FileWatchListener* watcher, bool recursive )
{
	return addWatch( directory, watcher, recursive, NULL );
}

WatchID FileWatcherInotify::addWatch( const std::string& directory, FileWatchListener* watcher, bool recursive, WatcherInotify * parent )
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
		return Errors::Log::createLastError( Errors::FileRepeated, directory );
	}
	else if ( NULL != parent && FileSystem::isRemoteFS( dir ) )
	{
		return Errors::Log::createLastError( Errors::FileRemote, dir );
	}

	/// Check if the directory is a symbolic link
	std::string curPath;
	std::string link( FileSystem::getLinkRealPath( dir, curPath ) );

	if ( "" != link )
	{
		/// Avoid adding symlinks directories if it's now enabled
		if ( NULL != parent && !mFileWatcher->followSymlinks() )
		{
			return Errors::Log::createLastError( Errors::FileOutOfScope, dir );
		}

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

	int wd = inotify_add_watch (mFD, dir.c_str(), IN_CLOSE_WRITE | IN_MOVED_TO | IN_CREATE | IN_MOVED_FROM | IN_DELETE | IN_MODIFY);

	if ( wd < 0 )
	{
		if( errno == ENOENT )
		{
			return Errors::Log::createLastError( Errors::FileNotFound, dir );
		}
		else
		{
			return Errors::Log::createLastError( Errors::Unspecified, std::string(strerror(errno)) );
		}
	}

	efDEBUG( "Added watch %s with id: %d\n", dir.c_str(), wd );

	WatcherInotify * pWatch	= new WatcherInotify();
	pWatch->Listener	= watcher;
	pWatch->ID			= wd;
	pWatch->Directory	= dir;
	pWatch->Recursive	= recursive;
	pWatch->Parent		= parent;

	{
		Lock lock( mWatchesLock );
		mWatches.insert(std::make_pair(wd, pWatch));
	}

	if ( NULL == pWatch->Parent )
	{
		mRealWatches[ pWatch->ID ] = pWatch;
	}

	if ( pWatch->Recursive )
	{
		std::map<std::string, FileInfo> files = FileSystem::filesInfoFromPath( pWatch->Directory );
		std::map<std::string, FileInfo>::iterator it = files.begin();

		for ( ; it != files.end(); ++it )
		{
			const FileInfo& cfi = it->second;

			if ( cfi.isDirectory() && cfi.isReadable() )
			{
				addWatch( cfi.Filepath, watcher, recursive, pWatch );
			}
		}
	}

	return wd;
}

void FileWatcherInotify::removeWatchLocked(WatchID watchid)
{
	WatchMap::iterator iter = mWatches.find( watchid );

	WatcherInotify * watch = iter->second;

	if ( watch->Recursive )
	{
		WatchMap::iterator it = mWatches.begin();
		std::list<WatchID> eraseWatches;

		for(; it != mWatches.end(); ++it)
		{
			if ( it->second != watch &&
				 it->second->inParentTree( watch )
			)
			{
				eraseWatches.push_back( it->second->ID );
			}
		}

		for ( std::list<WatchID>::iterator eit = eraseWatches.begin(); eit != eraseWatches.end(); ++eit )
		{
			removeWatch( *eit );
		}
	}

	mWatches.erase( iter );

	if ( NULL == watch->Parent )
	{
		WatchMap::iterator eraseit = mRealWatches.find( watch->ID );

		if ( eraseit != mRealWatches.end() )
		{
			mRealWatches.erase( eraseit );
		}
	}

	int err = inotify_rm_watch(mFD, watchid);

	if ( err < 0 )
	{
		efDEBUG( "Error removing watch %d: %s\n", watchid, strerror(errno) );
	}
	else
	{
		efDEBUG( "Removed watch %s with id: %d\n", watch->Directory.c_str(), watchid );
	}

	efSAFE_DELETE( watch );
}

void FileWatcherInotify::removeWatch(const std::string& directory)
{
	Lock lock( mWatchesLock );

	WatchMap::iterator iter = mWatches.begin();

	for(; iter != mWatches.end(); ++iter)
	{
		if( directory == iter->second->Directory )
		{
			WatcherInotify * watch = iter->second;

			if ( watch->Recursive )
			{
				WatchMap::iterator it = mWatches.begin();
				std::list<WatchID> eraseWatches;

				for(; it != mWatches.end(); ++it)
				{
					if ( it->second->inParentTree( watch ) )
					{
						eraseWatches.push_back( it->second->ID );
					}
				}

				for ( std::list<WatchID>::iterator eit = eraseWatches.begin(); eit != eraseWatches.end(); ++eit )
				{
					removeWatchLocked( *eit );
				}
			}

			mWatches.erase( iter );

			if ( NULL == watch->Parent )
			{
				WatchMap::iterator eraseit = mRealWatches.find( watch->ID );

				if ( eraseit != mRealWatches.end() )
				{
					mRealWatches.erase( eraseit );
				}
			}

			int err = inotify_rm_watch(mFD, watch->ID);

			if ( err < 0 )
			{
				efDEBUG( "Error removing watch %d: %s\n", watch->ID, strerror(errno) );
			}
			else
			{
				efDEBUG( "Removed watch %s with id: %d\n", watch->Directory.c_str(), watch->ID );
			}

			efSAFE_DELETE( watch );

			break;
		}
	}
}

void FileWatcherInotify::removeWatch( WatchID watchid )
{
	Lock lock( mWatchesLock );

	WatchMap::iterator iter = mWatches.find( watchid );

	if( iter == mWatches.end() )
	{
		return;
	}

	removeWatchLocked( watchid );
}

void FileWatcherInotify::watch()
{
	if ( NULL == mThread )
	{
		mThread = new Thread( &FileWatcherInotify::run, this );
		mThread->launch();
	}
}

Watcher * FileWatcherInotify::watcherContainsDirectory( std::string dir )
{
	FileSystem::dirRemoveSlashAtEnd( dir );
	std::string watcherPath = FileSystem::pathRemoveFileName( dir );
	FileSystem::dirAddSlashAtEnd( watcherPath );

	for ( WatchMap::iterator it = mWatches.begin(); it != mWatches.end(); ++it )
	{
		Watcher * watcher = it->second;

		if ( watcher->Directory == watcherPath )
		{
			return watcher;
		}
	}

	return NULL;
}

void FileWatcherInotify::run()
{
	static char buff[BUFF_SIZE] = {0};
	WatchMap::iterator wit;
	std::list<WatcherInotify*> movedOutsideWatches;

	do
	{
		fd_set rfds;
		FD_ZERO (&rfds);
		FD_SET (mFD, &rfds);
		timeval timeout;
		timeout.tv_sec=0;
		timeout.tv_usec=100000;

		if( select (FD_SETSIZE, &rfds, NULL, NULL, &timeout) > 0 )
		{
			ssize_t len;

			len = read (mFD, buff, BUFF_SIZE);

			if (len != -1)
			{
				ssize_t i = 0;

				while (i < len)
				{
					struct inotify_event *pevent = (struct inotify_event *)&buff[i];

					{
						Lock lock( mWatchesLock );

						wit = mWatches.find( pevent->wd );

						if ( wit != mWatches.end() )
						{
							handleAction(wit->second, pevent->name, pevent->mask);

							/// Keep track of the IN_MOVED_FROM events to know if the IN_MOVED_TO event is also fired
							if ( !wit->second->OldFileName.empty() )
							{
								movedOutsideWatches.push_back( wit->second );
							}
						}
					}

					i += sizeof(struct inotify_event) + pevent->len;
				}

				if ( !movedOutsideWatches.empty() )
				{
					/// In case that the IN_MOVED_TO is never fired means that the file was moved to other folder
					for ( std::list<WatcherInotify*>::iterator it = movedOutsideWatches.begin(); it != movedOutsideWatches.end(); ++it )
					{
						Watcher * watch = (*it);

						if ( !watch->OldFileName.empty() )
						{
							/// Check if the file move was a folder already being watched
							std::list<Watcher*> eraseWatches;

							for(; wit != mWatches.end(); ++wit)
							{
								Watcher * oldWatch = wit->second;

								if ( oldWatch != watch &&
									-1 != String::strStartsWith( watch->Directory + watch->OldFileName + "/", oldWatch->Directory ) )
								{
									eraseWatches.push_back( oldWatch );
								}
							}

							/// Remove invalid watches
							eraseWatches.sort();

							for ( std::list<Watcher*>::reverse_iterator eit = eraseWatches.rbegin(); eit != eraseWatches.rend(); ++eit )
							{
								Watcher * rmWatch = *eit;

								/// Create Delete event for removed watches that have been moved too
								if ( Watcher * cntWatch = watcherContainsDirectory( rmWatch->Directory ) )
								{
									handleAction( cntWatch, FileSystem::fileNameFromPath( rmWatch->Directory ), IN_DELETE );
								}

								removeWatch( rmWatch->ID );
							}

							/// Remove the OldFileName
							watch->OldFileName = "";
						}
					}

					movedOutsideWatches.clear();
				}
			}
		}
	} while( mInitOK );
}

void FileWatcherInotify::checkForNewWatcher( Watcher* watch, std::string fpath )
{
	FileSystem::dirAddSlashAtEnd( fpath );

	/// If the watcher is recursive, checks if the new file is a folder, and creates a watcher
	if ( watch->Recursive && FileSystem::isDirectory( fpath ) )
	{
		bool found = false;

		/// First check if exists
		for ( WatchMap::iterator it = mWatches.begin(); it != mWatches.end(); ++it )
		{
			if ( it->second->Directory == fpath )
			{
				found = true;
				break;
			}
		}

		if ( !found )
		{
			addWatch( fpath, watch->Listener, watch->Recursive, static_cast<WatcherInotify*>( watch ) );
		}
	}
}

void FileWatcherInotify::handleAction( Watcher* watch, const std::string& filename, unsigned long action, std::string )
{
	if ( !watch || !watch->Listener )
	{
		return;
	}

	std::string fpath( watch->Directory + filename );

	if ( ( IN_CLOSE_WRITE & action ) || ( IN_MODIFY & action ) )
	{
		watch->Listener->handleFileAction( watch->ID, watch->Directory, filename, Actions::Modified );
	}
	else if( IN_MOVED_TO & action )
	{
		/// If OldFileName doesn't exist means that the file has been moved from other folder, so we just send the Add event
		if ( watch->OldFileName.empty() )
		{
			watch->Listener->handleFileAction( watch->ID, watch->Directory, filename, Actions::Add );

			watch->Listener->handleFileAction( watch->ID, watch->Directory, filename, Actions::Modified );

			checkForNewWatcher( watch, fpath );
		}
		else
		{
			watch->Listener->handleFileAction( watch->ID, watch->Directory, filename, Actions::Moved, watch->OldFileName );
		}

		if ( watch->Recursive && FileSystem::isDirectory( fpath ) )
		{
			/// Update the new directory path
			std::string opath( watch->Directory + watch->OldFileName );
			FileSystem::dirAddSlashAtEnd( opath );
			FileSystem::dirAddSlashAtEnd( fpath );

			for ( WatchMap::iterator it = mWatches.begin(); it != mWatches.end(); ++it )
			{
				if ( it->second->Directory == opath && it->second->DirInfo.Inode == FileInfo( opath ).Inode )
				{
					it->second->Directory	= fpath;
					it->second->DirInfo		= FileInfo( fpath );

					break;
				}
			}
		}

		watch->OldFileName = "";
	}
	else if( IN_CREATE & action )
	{
		watch->Listener->handleFileAction( watch->ID, watch->Directory, filename, Actions::Add );

		checkForNewWatcher( watch, fpath );
	}
	else if ( IN_MOVED_FROM & action )
	{
		watch->OldFileName = filename;
	}
	else if( IN_DELETE & action )
	{
		watch->Listener->handleFileAction( watch->ID, watch->Directory, filename, Actions::Delete );

		FileSystem::dirAddSlashAtEnd( fpath );

		/// If the file erased is a directory and recursive is enabled, removes the directory erased
		if ( watch->Recursive )
		{
			for ( WatchMap::iterator it = mWatches.begin(); it != mWatches.end(); ++it )
			{
				if ( it->second->Directory == fpath )
				{
					removeWatch( it->second->ID );
					break;
				}
			}
		}
	}
}

std::list<std::string> FileWatcherInotify::directories()
{
	std::list<std::string> dirs;

	Lock lock( mWatchesLock );

	WatchMap::iterator it = mRealWatches.begin();

	for ( ; it != mRealWatches.end(); ++it )
	{
		dirs.push_back( it->second->Directory );
	}

	return dirs;
}

bool FileWatcherInotify::pathInWatches( const std::string& path )
{
	/// Search in the real watches, since it must allow adding a watch already watched as a subdir
	WatchMap::iterator it = mRealWatches.begin();

	for ( ; it != mRealWatches.end(); ++it )
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
