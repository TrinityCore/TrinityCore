#include <efsw/FileWatcherWin32.hpp>
#include <efsw/FileSystem.hpp>
#include <efsw/System.hpp>
#include <efsw/String.hpp>
#include <efsw/Lock.hpp>

#if EFSW_PLATFORM == EFSW_PLATFORM_WIN32

namespace efsw
{

FileWatcherWin32::FileWatcherWin32( FileWatcher * parent ) :
	FileWatcherImpl( parent ),
	mLastWatchID(0),
	mThread( NULL )
{
	mInitOK = true;
}

FileWatcherWin32::~FileWatcherWin32()
{
	mInitOK = false;
	efSAFE_DELETE( mThread );
	removeAllWatches();
}

WatchID FileWatcherWin32::addWatch(const std::string& directory, FileWatchListener* watcher, bool recursive)
{
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

	Lock lock( mWatchesLock );

	if ( pathInWatches( dir ) )
	{
		return Errors::Log::createLastError( Errors::FileRepeated, dir );
	}

	WatchID watchid = ++mLastWatchID;

	WatcherStructWin32 * watch = CreateWatch( String::fromUtf8( dir ).toWideString().c_str(), recursive,		FILE_NOTIFY_CHANGE_CREATION |
																			FILE_NOTIFY_CHANGE_LAST_WRITE |
																			FILE_NOTIFY_CHANGE_FILE_NAME |
																			FILE_NOTIFY_CHANGE_DIR_NAME |
																			FILE_NOTIFY_CHANGE_SIZE
	);

	if( NULL == watch )
	{
		return Errors::Log::createLastError( Errors::FileNotFound, dir );
	}

	// Add the handle to the handles vector
	watch->Watch->ID = watchid;
	watch->Watch->Watch = this;
	watch->Watch->Listener = watcher;
	watch->Watch->DirName = new char[dir.length()+1];
	strcpy(watch->Watch->DirName, dir.c_str());

	mWatchesNew.insert( watch );
	mWatches.insert( watch );

	return watchid;
}

void FileWatcherWin32::removeWatch(const std::string& directory)
{
	Lock lock( mWatchesLock );

	Watches::iterator iter = mWatches.begin();

	for(; iter != mWatches.end(); ++iter)
	{
		if(directory == (*iter)->Watch->DirName)
		{
			removeWatch(*iter);
			break;
		}
	}
}

void FileWatcherWin32::removeWatch(WatchID watchid)
{
	Lock lock( mWatchesLock );

	Watches::iterator iter = mWatches.begin();

	for(; iter != mWatches.end(); ++iter)
	{
		// Find the watch ID
		if ( (*iter)->Watch->ID == watchid )
		{
			removeWatch(*iter);
			return;
		}
	}
}

void FileWatcherWin32::removeWatch(WatcherStructWin32* watch)
{
	mWatchesRemoved.insert(watch);

	if( NULL == mThread )
	{
		removeWatches();
	}
}

void FileWatcherWin32::removeWatches()
{
	Lock lock( mWatchesLock );

	Watches::iterator remWatchIter = mWatchesRemoved.begin();

	for( ; remWatchIter != mWatchesRemoved.end(); ++remWatchIter )
	{
		Watches::iterator iter = mWatches.find(*remWatchIter);

		if( iter != mWatches.end() )
		{
			DestroyWatch(*iter);

			mWatches.erase( iter );
		}

		iter = mWatchesNew.find(*remWatchIter);

		if( iter != mWatchesNew.end() )
		{
			mWatchesNew.erase( iter );
		}
	}

	mWatchesRemoved.clear();
}

void FileWatcherWin32::watch()
{
	if ( NULL == mThread )
	{
		mThread = new Thread( &FileWatcherWin32::run, this );
		mThread->launch();
	}
}

void FileWatcherWin32::removeAllWatches()
{
	Lock lock( mWatchesLock );

	Watches::iterator iter = mWatches.begin();

	for( ; iter != mWatches.end(); ++iter )
	{
		DestroyWatch((*iter));
	}

	mWatches.clear();
	mWatchesRemoved.clear();
	mWatchesNew.clear();
}

void FileWatcherWin32::run()
{
	do
	{
		if ( !mWatches.empty() )
		{
			{
				Lock lock( mWatchesLock );

				for( Watches::iterator iter = mWatches.begin() ; iter != mWatches.end(); ++iter )
				{
					WatcherStructWin32 * watch = *iter;

					if ( HasOverlappedIoCompleted( &watch->Overlapped ) )
					{
						DWORD bytes;

						if ( GetOverlappedResult( watch->Watch->DirHandle, &watch->Overlapped, &bytes, FALSE ) )
						{
							WatchCallback( ERROR_SUCCESS, bytes, &watch->Overlapped );
						}
					}
				}
			}

			if ( mInitOK )
			{
				System::sleep( 10 );
			}
		}
		else
		{
			// Wait for a new handle to be added
			System::sleep( 10 );
		}

		removeWatches();

		for ( Watches::iterator it = mWatchesNew.begin(); it != mWatchesNew.end(); it++ )
		{
			RefreshWatch(*it);
		}

		mWatchesNew.clear();
	} while ( mInitOK );

	removeAllWatches();
}

void FileWatcherWin32::handleAction(Watcher* watch, const std::string& filename, unsigned long action, std::string oldFilename)
{
	Action fwAction;

	switch(action)
	{
	case FILE_ACTION_RENAMED_OLD_NAME:
		watch->OldFileName = filename;
		return;
	case FILE_ACTION_ADDED:
		fwAction = Actions::Add;
		break;
	case FILE_ACTION_RENAMED_NEW_NAME:
	{
		fwAction = Actions::Moved;

		std::string fpath( watch->Directory + filename );

		// Update the directory path
		if ( watch->Recursive && FileSystem::isDirectory( fpath ) )
		{
			// Update the new directory path
			std::string opath( watch->Directory + watch->OldFileName );
			FileSystem::dirAddSlashAtEnd( opath );
			FileSystem::dirAddSlashAtEnd( fpath );

			for ( Watches::iterator it = mWatches.begin(); it != mWatches.end(); it++ )
			{
				if ( (*it)->Watch->Directory == opath )
				{
					(*it)->Watch->Directory = fpath;

					break;
				}
			}
		}

		watch->Listener->handleFileAction(watch->ID, static_cast<WatcherWin32*>( watch )->DirName, filename, fwAction, watch->OldFileName);
		return;
	}
	case FILE_ACTION_REMOVED:
		fwAction = Actions::Delete;
		break;
	case FILE_ACTION_MODIFIED:
		fwAction = Actions::Modified;
		break;
	};

	std::string folderPath( static_cast<WatcherWin32*>( watch )->DirName );
	std::string realFilename = filename;
	std::size_t sepPos = filename.find_last_of("/\\");

	if ( sepPos != std::string::npos )
	{
		folderPath += filename.substr( 0, sepPos );
		realFilename = filename.substr( sepPos + 1 );
	}

	watch->Listener->handleFileAction(watch->ID, folderPath, realFilename, fwAction);
}

std::list<std::string> FileWatcherWin32::directories()
{
	std::list<std::string> dirs;

	Lock lock( mWatchesLock );

	for ( Watches::iterator it = mWatches.begin(); it != mWatches.end(); it++ )
	{
		dirs.push_back( std::string( (*it)->Watch->DirName ) );
	}

	return dirs;
}

bool FileWatcherWin32::pathInWatches( const std::string& path )
{
	for ( Watches::iterator it = mWatches.begin(); it != mWatches.end(); it++ )
	{
		if ( (*it)->Watch->DirName == path )
		{
			return true;
		}
	}

	return false;
}

}

#endif
