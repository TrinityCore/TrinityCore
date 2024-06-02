#include <efsw/FileSystem.hpp>
#include <efsw/FileWatcherWin32.hpp>
#include <efsw/Lock.hpp>
#include <efsw/String.hpp>
#include <efsw/System.hpp>

#if EFSW_PLATFORM == EFSW_PLATFORM_WIN32

namespace efsw {

FileWatcherWin32::FileWatcherWin32( FileWatcher* parent ) :
	FileWatcherImpl( parent ), mLastWatchID( 0 ), mThread( NULL ) {
	mIOCP = CreateIoCompletionPort( INVALID_HANDLE_VALUE, NULL, 0, 1 );
	if ( mIOCP && mIOCP != INVALID_HANDLE_VALUE )
		mInitOK = true;
}

FileWatcherWin32::~FileWatcherWin32() {
	mInitOK = false;

	if ( mIOCP && mIOCP != INVALID_HANDLE_VALUE ) {
		PostQueuedCompletionStatus( mIOCP, 0, reinterpret_cast<ULONG_PTR>( this ), NULL );
	}

	efSAFE_DELETE( mThread );

	removeAllWatches();

	CloseHandle( mIOCP );
}

WatchID FileWatcherWin32::addWatch( const std::string& directory, FileWatchListener* watcher,
									bool recursive, const std::vector<WatcherOption> &options ) {
	std::string dir( directory );

	FileInfo fi( dir );

	if ( !fi.isDirectory() ) {
		return Errors::Log::createLastError( Errors::FileNotFound, dir );
	} else if ( !fi.isReadable() ) {
		return Errors::Log::createLastError( Errors::FileNotReadable, dir );
	}

	FileSystem::dirAddSlashAtEnd( dir );

	Lock lock( mWatchesLock );

	if ( pathInWatches( dir ) ) {
		return Errors::Log::createLastError( Errors::FileRepeated, dir );
	}

	WatchID watchid = ++mLastWatchID;

	DWORD bufferSize = static_cast<DWORD>( getOptionValue(options, Option::WinBufferSize, 63 * 1024) );
	DWORD notifyFilter = static_cast<DWORD>( getOptionValue(options, Option::WinNotifyFilter,
		FILE_NOTIFY_CHANGE_CREATION | FILE_NOTIFY_CHANGE_LAST_WRITE |
		FILE_NOTIFY_CHANGE_FILE_NAME | FILE_NOTIFY_CHANGE_DIR_NAME |
		FILE_NOTIFY_CHANGE_SIZE) );

	WatcherStructWin32* watch = CreateWatch( String::fromUtf8( dir ).toWideString().c_str(),
											 recursive, bufferSize, notifyFilter, mIOCP );

	if ( NULL == watch ) {
		return Errors::Log::createLastError( Errors::FileNotFound, dir );
	}

	// Add the handle to the handles vector
	watch->Watch->ID = watchid;
	watch->Watch->Watch = this;
	watch->Watch->Listener = watcher;
	watch->Watch->DirName = new char[dir.length() + 1];
	strcpy( watch->Watch->DirName, dir.c_str() );

	mWatches.insert( watch );

	return watchid;
}

void FileWatcherWin32::removeWatch( const std::string& directory ) {
	Lock lock( mWatchesLock );

	Watches::iterator iter = mWatches.begin();

	for ( ; iter != mWatches.end(); ++iter ) {
		if ( directory == ( *iter )->Watch->DirName ) {
			removeWatch( *iter );
			break;
		}
	}
}

void FileWatcherWin32::removeWatch( WatchID watchid ) {
	Lock lock( mWatchesLock );

	Watches::iterator iter = mWatches.begin();

	for ( ; iter != mWatches.end(); ++iter ) {
		// Find the watch ID
		if ( ( *iter )->Watch->ID == watchid ) {
			removeWatch( *iter );
			return;
		}
	}
}

void FileWatcherWin32::removeWatch( WatcherStructWin32* watch ) {
	Lock lock( mWatchesLock );

	DestroyWatch( watch );
	mWatches.erase( watch );
}

void FileWatcherWin32::watch() {
	if ( NULL == mThread ) {
		mThread = new Thread( &FileWatcherWin32::run, this );
		mThread->launch();
	}
}

void FileWatcherWin32::removeAllWatches() {
	Lock lock( mWatchesLock );

	Watches::iterator iter = mWatches.begin();

	for ( ; iter != mWatches.end(); ++iter ) {
		DestroyWatch( ( *iter ) );
	}

	mWatches.clear();
}

void FileWatcherWin32::run() {
	do {
		if ( mInitOK && !mWatches.empty() ) {
			DWORD numOfBytes = 0;
			OVERLAPPED* ov = NULL;
			ULONG_PTR compKey = 0;
			BOOL res = FALSE;

			while ( ( res = GetQueuedCompletionStatus( mIOCP, &numOfBytes, &compKey, &ov,
													   INFINITE ) ) != FALSE ) {
				if ( compKey != 0 && compKey == reinterpret_cast<ULONG_PTR>( this ) ) {
					break;
				} else {
					Lock lock( mWatchesLock );
					WatchCallback( numOfBytes, ov );
				}
			}
		} else {
			System::sleep( 10 );
		}
	} while ( mInitOK );

	removeAllWatches();
}

void FileWatcherWin32::handleAction( Watcher* watch, const std::string& filename,
									 unsigned long action, std::string /*oldFilename*/ ) {
	Action fwAction;

	switch ( action ) {
		case FILE_ACTION_RENAMED_OLD_NAME:
			watch->OldFileName = filename;
			return;
		case FILE_ACTION_ADDED:
			fwAction = Actions::Add;
			break;
		case FILE_ACTION_RENAMED_NEW_NAME: {
			fwAction = Actions::Moved;

			std::string fpath( watch->Directory + filename );

			// Update the directory path
			if ( watch->Recursive && FileSystem::isDirectory( fpath ) ) {
				// Update the new directory path
				std::string opath( watch->Directory + watch->OldFileName );
				FileSystem::dirAddSlashAtEnd( opath );
				FileSystem::dirAddSlashAtEnd( fpath );

				for ( Watches::iterator it = mWatches.begin(); it != mWatches.end(); ++it ) {
					if ( ( *it )->Watch->Directory == opath ) {
						( *it )->Watch->Directory = fpath;

						break;
					}
				}
			}

			std::string folderPath( static_cast<WatcherWin32*>( watch )->DirName );
			std::string realFilename = filename;
			std::size_t sepPos = filename.find_last_of( "/\\" );
			std::string oldFolderPath =
				static_cast<WatcherWin32*>( watch )->DirName +
				watch->OldFileName.substr( 0, watch->OldFileName.find_last_of( "/\\" ) );

			if ( sepPos != std::string::npos ) {
				folderPath +=
					filename.substr( 0, sepPos + 1 < filename.size() ? sepPos + 1 : sepPos );
				realFilename = filename.substr( sepPos + 1 );
			}

			if ( folderPath == oldFolderPath ) {
				watch->Listener->handleFileAction(
					watch->ID, folderPath, realFilename, fwAction,
					FileSystem::fileNameFromPath( watch->OldFileName ) );
			} else {
				watch->Listener->handleFileAction( watch->ID,
												   static_cast<WatcherWin32*>( watch )->DirName,
												   filename, fwAction, watch->OldFileName );
			}
			return;
		}
		case FILE_ACTION_REMOVED:
			fwAction = Actions::Delete;
			break;
		case FILE_ACTION_MODIFIED:
			fwAction = Actions::Modified;
			break;
		default:
			return;
	};

	std::string folderPath( static_cast<WatcherWin32*>( watch )->DirName );
	std::string realFilename = filename;
	std::size_t sepPos = filename.find_last_of( "/\\" );

	if ( sepPos != std::string::npos ) {
		folderPath += filename.substr( 0, sepPos + 1 < filename.size() ? sepPos + 1 : sepPos );
		realFilename = filename.substr( sepPos + 1 );
	}

	FileSystem::dirAddSlashAtEnd( folderPath );

	watch->Listener->handleFileAction( watch->ID, folderPath, realFilename, fwAction );
}

std::vector<std::string> FileWatcherWin32::directories() {
	std::vector<std::string> dirs;

	Lock lock( mWatchesLock );

	dirs.reserve( mWatches.size() );

	for ( Watches::iterator it = mWatches.begin(); it != mWatches.end(); ++it ) {
		dirs.push_back( std::string( ( *it )->Watch->DirName ) );
	}

	return dirs;
}

bool FileWatcherWin32::pathInWatches( const std::string& path ) {
	Lock lock( mWatchesLock );

	for ( Watches::iterator it = mWatches.begin(); it != mWatches.end(); ++it ) {
		if ( ( *it )->Watch->DirName == path ) {
			return true;
		}
	}

	return false;
}

} // namespace efsw

#endif
