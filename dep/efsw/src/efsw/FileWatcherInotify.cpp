#include <algorithm>
#include <efsw/FileWatcherInotify.hpp>

#if EFSW_PLATFORM == EFSW_PLATFORM_INOTIFY

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#ifdef EFSW_INOTIFY_NOSYS
#include <efsw/inotify-nosys.h>
#else
#include <sys/inotify.h>
#endif

#include <efsw/Debug.hpp>
#include <efsw/FileSystem.hpp>
#include <efsw/Lock.hpp>
#include <efsw/String.hpp>
#include <efsw/System.hpp>

#define BUFF_SIZE ( ( sizeof( struct inotify_event ) + FILENAME_MAX ) * 1024 )

namespace efsw {

FileWatcherInotify::FileWatcherInotify( FileWatcher* parent ) :
	FileWatcherImpl( parent ), mFD( -1 ), mThread( NULL ), mIsTakingAction( false ) {
	mFD = inotify_init();

	if ( mFD < 0 ) {
		efDEBUG( "Error: %s\n", strerror( errno ) );
	} else {
		mInitOK = true;
	}
}

FileWatcherInotify::~FileWatcherInotify() {
	mInitOK = false;
	// There is deadlock when release FileWatcherInotify instance since its handAction
	// function is still running and hangs in requiring lock without init lock captured.
	while ( mIsTakingAction ) {
		// It'd use condition-wait instead of sleep. Actually efsw has no such
		// implementation so we just skip and sleep while for that to avoid deadlock.
		usleep( 1000 );
	};
	Lock initLock( mInitLock );

	efSAFE_DELETE( mThread );

	Lock l( mWatchesLock );
	Lock l2( mRealWatchesLock );

	WatchMap::iterator iter = mWatches.begin();
	WatchMap::iterator end = mWatches.end();

	for ( ; iter != end; ++iter ) {
		efSAFE_DELETE( iter->second );
	}

	mWatches.clear();

	if ( mFD != -1 ) {
		close( mFD );
		mFD = -1;
	}
}

WatchID FileWatcherInotify::addWatch( const std::string& directory, FileWatchListener* watcher,
									  bool recursive, const std::vector<WatcherOption>& ) {
	if ( !mInitOK )
		return Errors::Log::createLastError( Errors::Unspecified, directory );
	Lock initLock( mInitLock );
	return addWatch( directory, watcher, recursive, NULL );
}

WatchID FileWatcherInotify::addWatch( const std::string& directory, FileWatchListener* watcher,
									  bool recursive, WatcherInotify* parent ) {
	std::string dir( directory );

	FileSystem::dirAddSlashAtEnd( dir );

	FileInfo fi( dir );

	if ( !fi.isDirectory() ) {
		return Errors::Log::createLastError( Errors::FileNotFound, dir );
	} else if ( !fi.isReadable() ) {
		return Errors::Log::createLastError( Errors::FileNotReadable, dir );
	} else if ( pathInWatches( dir ) ) {
		return Errors::Log::createLastError( Errors::FileRepeated, directory );
	} else if ( NULL != parent && FileSystem::isRemoteFS( dir ) ) {
		return Errors::Log::createLastError( Errors::FileRemote, dir );
	}

	/// Check if the directory is a symbolic link
	std::string curPath;
	std::string link( FileSystem::getLinkRealPath( dir, curPath ) );

	if ( "" != link ) {
		/// Avoid adding symlinks directories if it's now enabled
		if ( NULL != parent && !mFileWatcher->followSymlinks() ) {
			return Errors::Log::createLastError( Errors::FileOutOfScope, dir );
		}

		/// If it's a symlink check if the realpath exists as a watcher, or
		/// if the path is outside the current dir
		if ( pathInWatches( link ) ) {
			return Errors::Log::createLastError( Errors::FileRepeated, directory );
		} else if ( !linkAllowed( curPath, link ) ) {
			return Errors::Log::createLastError( Errors::FileOutOfScope, dir );
		} else {
			dir = link;
		}
	}

	int wd = inotify_add_watch( mFD, dir.c_str(),
								IN_CLOSE_WRITE | IN_MOVED_TO | IN_CREATE | IN_MOVED_FROM |
									IN_DELETE | IN_MODIFY );

	if ( wd < 0 ) {
		if ( errno == ENOENT ) {
			return Errors::Log::createLastError( Errors::FileNotFound, dir );
		} else {
			return Errors::Log::createLastError( Errors::Unspecified,
												 std::string( strerror( errno ) ) );
		}
	}

	efDEBUG( "Added watch %s with id: %d\n", dir.c_str(), wd );

	WatcherInotify* pWatch = new WatcherInotify();
	pWatch->Listener = watcher;
	pWatch->ID = parent ? parent->ID : wd;
	pWatch->InotifyID = wd;
	pWatch->Directory = dir;
	pWatch->Recursive = recursive;
	pWatch->Parent = parent;

	{
		Lock lock( mWatchesLock );
		mWatches.insert( std::make_pair( wd, pWatch ) );
		mWatchesRef[pWatch->Directory] = wd;
	}

	if ( NULL == pWatch->Parent ) {
		Lock l( mRealWatchesLock );
		mRealWatches[pWatch->InotifyID] = pWatch;
	}

	if ( pWatch->Recursive ) {
		std::map<std::string, FileInfo> files = FileSystem::filesInfoFromPath( pWatch->Directory );
		std::map<std::string, FileInfo>::iterator it = files.begin();

		for ( ; it != files.end(); ++it ) {
			if ( !mInitOK )
				break;

			const FileInfo& cfi = it->second;

			if ( cfi.isDirectory() && cfi.isReadable() ) {
				addWatch( cfi.Filepath, watcher, recursive, pWatch );
			}
		}
	}

	return wd;
}

void FileWatcherInotify::removeWatchLocked( WatchID watchid ) {
	WatchMap::iterator iter = mWatches.find( watchid );
	if ( iter == mWatches.end() )
		return;

	WatcherInotify* watch = iter->second;

	for ( std::vector<std::pair<WatcherInotify*, std::string>>::iterator itm =
			  mMovedOutsideWatches.begin();
		  mMovedOutsideWatches.end() != itm; ++itm ) {
		if ( itm->first == watch ) {
			mMovedOutsideWatches.erase( itm );
			break;
		}
	}

	if ( watch->Recursive && NULL == watch->Parent ) {
		WatchMap::iterator it = mWatches.begin();
		std::vector<WatchID> eraseWatches;

		for ( ; it != mWatches.end(); ++it )
			if ( it->second != watch && it->second->inParentTree( watch ) )
				eraseWatches.push_back( it->second->InotifyID );

		for ( std::vector<WatchID>::iterator eit = eraseWatches.begin(); eit != eraseWatches.end();
			  ++eit ) {
			removeWatch( *eit );
		}
	}

	mWatchesRef.erase( watch->Directory );
	mWatches.erase( iter );

	if ( NULL == watch->Parent ) {
		WatchMap::iterator eraseit = mRealWatches.find( watch->InotifyID );

		if ( eraseit != mRealWatches.end() ) {
			mRealWatches.erase( eraseit );
		}
	}

	int err = inotify_rm_watch( mFD, watchid );

	if ( err < 0 ) {
		efDEBUG( "Error removing watch %d: %s\n", watchid, strerror( errno ) );
	} else {
		efDEBUG( "Removed watch %s with id: %d\n", watch->Directory.c_str(), watchid );
	}

	efSAFE_DELETE( watch );
}

void FileWatcherInotify::removeWatch( const std::string& directory ) {
	if ( !mInitOK )
		return;
	Lock initLock( mInitLock );
	Lock lock( mWatchesLock );
	Lock l( mRealWatchesLock );

	std::unordered_map<std::string, WatchID>::iterator ref = mWatchesRef.find( directory );
	if ( ref == mWatchesRef.end() )
		return;

	removeWatchLocked( ref->second );
}

void FileWatcherInotify::removeWatch( WatchID watchid ) {
	if ( !mInitOK )
		return;
	Lock initLock( mInitLock );
	Lock lock( mWatchesLock );
	removeWatchLocked( watchid );
}

void FileWatcherInotify::watch() {
	if ( NULL == mThread ) {
		mThread = new Thread( &FileWatcherInotify::run, this );
		mThread->launch();
	}
}

Watcher* FileWatcherInotify::watcherContainsDirectory( std::string dir ) {
	FileSystem::dirRemoveSlashAtEnd( dir );
	std::string watcherPath = FileSystem::pathRemoveFileName( dir );
	FileSystem::dirAddSlashAtEnd( watcherPath );
	Lock lock( mWatchesLock );

	for ( WatchMap::iterator it = mWatches.begin(); it != mWatches.end(); ++it ) {
		Watcher* watcher = it->second;
		if ( watcher->Directory == watcherPath )
			return watcher;
	}

	return NULL;
}

void FileWatcherInotify::run() {
	char* buff = new char[BUFF_SIZE];
	memset( buff, 0, BUFF_SIZE );
	WatchMap::iterator wit;

	WatcherInotify* currentMoveFrom = NULL;
	u_int32_t currentMoveCookie = -1;
	bool lastWasMovedFrom = false;
	std::string prevOldFileName;

	do {
		fd_set rfds;
		FD_ZERO( &rfds );
		FD_SET( mFD, &rfds );
		timeval timeout;
		timeout.tv_sec = 0;
		timeout.tv_usec = 100000;

		if ( select( FD_SETSIZE, &rfds, NULL, NULL, &timeout ) > 0 ) {
			ssize_t len;

			len = read( mFD, buff, BUFF_SIZE );

			if ( len != -1 ) {
				ssize_t i = 0;

				while ( i < len ) {
					struct inotify_event* pevent = (struct inotify_event*)&buff[i];

					{
						{
							Lock lock( mWatchesLock );

							wit = mWatches.find( pevent->wd );
						}

						if ( wit != mWatches.end() ) {
							handleAction( wit->second, (char*)pevent->name, pevent->mask );

							if ( ( pevent->mask & IN_MOVED_TO ) && wit->second == currentMoveFrom &&
								 pevent->cookie == currentMoveCookie ) {
								/// make pair success
								currentMoveFrom = NULL;
								currentMoveCookie = -1;
							} else if ( pevent->mask & IN_MOVED_FROM ) {
								// Previous event was moved from and current event is moved from
								// Treat it as a DELETE or moved ouside watches
								if ( lastWasMovedFrom && currentMoveFrom ) {
									mMovedOutsideWatches.push_back(
										std::make_pair( currentMoveFrom, prevOldFileName ) );
								}

								currentMoveFrom = wit->second;
								currentMoveCookie = pevent->cookie;
							} else {
								/// Keep track of the IN_MOVED_FROM events to know
								/// if the IN_MOVED_TO event is also fired
								if ( currentMoveFrom ) {
									mMovedOutsideWatches.push_back(
										std::make_pair( currentMoveFrom, prevOldFileName ) );
								}

								currentMoveFrom = NULL;
								currentMoveCookie = -1;
							}
						}

						lastWasMovedFrom = ( pevent->mask & IN_MOVED_FROM ) != 0;
						if ( pevent->mask & IN_MOVED_FROM )
							prevOldFileName = std::string( (char*)pevent->name );
					}

					i += sizeof( struct inotify_event ) + pevent->len;
				}
			}
		} else {
			// Here means no event received
			// If last event is IN_MOVED_FROM, we assume no IN_MOVED_TO
			if ( currentMoveFrom ) {
				mMovedOutsideWatches.push_back(
					std::make_pair( currentMoveFrom, currentMoveFrom->OldFileName ) );
			}

			currentMoveFrom = NULL;
			currentMoveCookie = -1;
		}

		if ( !mMovedOutsideWatches.empty() ) {
			// We need to make a copy since the element mMovedOutsideWatches could be modified
			// during the iteration.
			std::vector<std::pair<WatcherInotify*, std::string>> movedOutsideWatches(
				mMovedOutsideWatches );

			/// In case that the IN_MOVED_TO is never fired means that the file was moved to other
			/// folder
			for ( std::vector<std::pair<WatcherInotify*, std::string>>::iterator it =
					  movedOutsideWatches.begin();
				  it != movedOutsideWatches.end(); ++it ) {

				// Skip if the watch has already being removed
				if ( mMovedOutsideWatches.size() != movedOutsideWatches.size() ) {
					bool found = false;
					for ( std::vector<std::pair<WatcherInotify*, std::string>>::iterator itm =
							  mMovedOutsideWatches.begin();
						  mMovedOutsideWatches.end() != itm; ++itm ) {
						if ( itm->first == it->first ) {
							found = true;
							break;
						}
					}
					if ( !found )
						continue;
				}

				Watcher* watch = ( *it ).first;
				const std::string& oldFileName = ( *it ).second;

				/// Check if the file move was a folder already being watched
				std::vector<Watcher*> eraseWatches;

				{
					Lock lock( mWatchesLock );

					for ( ; wit != mWatches.end(); ++wit ) {
						Watcher* oldWatch = wit->second;

						if ( oldWatch != watch &&
							 -1 != String::strStartsWith( watch->Directory + oldFileName + "/",
														  oldWatch->Directory ) ) {
							eraseWatches.push_back( oldWatch );
						}
					}
				}

				/// Remove invalid watches
				std::stable_sort( eraseWatches.begin(), eraseWatches.end(),
								  []( const Watcher* left, const Watcher* right ) {
									  return left->Directory < right->Directory;
								  } );

				if ( eraseWatches.empty() ) {
					handleAction( watch, oldFileName, IN_DELETE );
				} else {
					for ( std::vector<Watcher*>::reverse_iterator eit = eraseWatches.rbegin();
						  eit != eraseWatches.rend(); ++eit ) {
						Watcher* rmWatch = *eit;

						/// Create Delete event for removed watches that have been moved too
						if ( Watcher* cntWatch = watcherContainsDirectory( rmWatch->Directory ) ) {
							handleAction( cntWatch,
										  FileSystem::fileNameFromPath( rmWatch->Directory ),
										  IN_DELETE );
						}
					}
				}
			}

			mMovedOutsideWatches.clear();
		}
	} while ( mInitOK );

	delete[] buff;
}

void FileWatcherInotify::checkForNewWatcher( Watcher* watch, std::string fpath ) {
	FileSystem::dirAddSlashAtEnd( fpath );

	/// If the watcher is recursive, checks if the new file is a folder, and creates a watcher
	if ( watch->Recursive && FileSystem::isDirectory( fpath ) ) {
		bool found = false;

		{
			Lock lock( mWatchesLock );

			/// First check if exists
			for ( WatchMap::iterator it = mWatches.begin(); it != mWatches.end(); ++it ) {
				if ( it->second->Directory == fpath ) {
					found = true;
					break;
				}
			}
		}

		if ( !found ) {
			addWatch( fpath, watch->Listener, watch->Recursive,
					  static_cast<WatcherInotify*>( watch ) );
		}
	}
}

void FileWatcherInotify::handleAction( Watcher* watch, const std::string& filename,
									   unsigned long action, std::string ) {
	if ( !watch || !watch->Listener || !mInitOK ) {
		return;
	}
	mIsTakingAction = true;
	Lock initLock( mInitLock );

	std::string fpath( watch->Directory + filename );

	if ( ( IN_CLOSE_WRITE & action ) || ( IN_MODIFY & action ) ) {
		watch->Listener->handleFileAction( watch->ID, watch->Directory, filename,
										   Actions::Modified );
	} else if ( IN_MOVED_TO & action ) {
		/// If OldFileName doesn't exist means that the file has been moved from other folder, so we
		/// just send the Add event
		if ( watch->OldFileName.empty() ) {
			watch->Listener->handleFileAction( watch->ID, watch->Directory, filename,
											   Actions::Add );

			watch->Listener->handleFileAction( watch->ID, watch->Directory, filename,
											   Actions::Modified );

			checkForNewWatcher( watch, fpath );
		} else {
			watch->Listener->handleFileAction( watch->ID, watch->Directory, filename,
											   Actions::Moved, watch->OldFileName );
		}

		if ( watch->Recursive && FileSystem::isDirectory( fpath ) ) {
			/// Update the new directory path
			std::string opath( watch->Directory + watch->OldFileName );
			FileSystem::dirAddSlashAtEnd( opath );
			FileSystem::dirAddSlashAtEnd( fpath );

			Lock lock( mWatchesLock );

			for ( WatchMap::iterator it = mWatches.begin(); it != mWatches.end(); ++it ) {
				if ( it->second->Directory == opath ) {
					it->second->Directory = fpath;
					it->second->DirInfo = FileInfo( fpath );
				} else if ( -1 != String::strStartsWith( opath, it->second->Directory ) ) {
					it->second->Directory = fpath + it->second->Directory.substr( opath.size() );
					it->second->DirInfo.Filepath = it->second->Directory;
				}
			}
		}

		watch->OldFileName = "";
	} else if ( IN_CREATE & action ) {
		watch->Listener->handleFileAction( watch->ID, watch->Directory, filename, Actions::Add );

		checkForNewWatcher( watch, fpath );
	} else if ( IN_MOVED_FROM & action ) {
		watch->OldFileName = filename;
	} else if ( IN_DELETE & action ) {
		watch->Listener->handleFileAction( watch->ID, watch->Directory, filename, Actions::Delete );

		FileSystem::dirAddSlashAtEnd( fpath );

		/// If the file erased is a directory and recursive is enabled, removes the directory erased
		if ( watch->Recursive ) {
			Lock l( mWatchesLock );

			for ( WatchMap::iterator it = mWatches.begin(); it != mWatches.end(); ++it ) {
				if ( it->second->Directory == fpath ) {
					removeWatchLocked( it->second->InotifyID );
					break;
				}
			}
		}
	}
	mIsTakingAction = false;
}

std::vector<std::string> FileWatcherInotify::directories() {
	std::vector<std::string> dirs;

	Lock l( mRealWatchesLock );

	dirs.reserve( mRealWatches.size() );

	WatchMap::iterator it = mRealWatches.begin();

	for ( ; it != mRealWatches.end(); ++it )
		dirs.push_back( it->second->Directory );

	return dirs;
}

bool FileWatcherInotify::pathInWatches( const std::string& path ) {
	Lock l( mRealWatchesLock );

	/// Search in the real watches, since it must allow adding a watch already watched as a subdir
	WatchMap::iterator it = mRealWatches.begin();

	for ( ; it != mRealWatches.end(); ++it )
		if ( it->second->Directory == path )
			return true;

	return false;
}

} // namespace efsw

#endif
