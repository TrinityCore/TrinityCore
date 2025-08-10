#include <efsw/Debug.hpp>
#include <efsw/FileSystem.hpp>
#include <efsw/FileWatcherFSEvents.hpp>
#include <efsw/WatcherFSEvents.hpp>

#if EFSW_PLATFORM == EFSW_PLATFORM_FSEVENTS

namespace efsw {

WatcherFSEvents::WatcherFSEvents() :
	Watcher(), FWatcher( NULL ), FSStream( NULL ), WatcherGen( NULL ) {}

WatcherFSEvents::WatcherFSEvents( WatchID id, std::string directory, FileWatchListener* listener,
								  bool recursive, WatcherFSEvents* parent ) :
	Watcher( id, directory, listener, recursive ),
	FWatcher( NULL ),
	FSStream( NULL ),
	WatcherGen( NULL ) {}

WatcherFSEvents::~WatcherFSEvents() {
	if ( NULL != FSStream ) {
		FSEventStreamStop( FSStream );
		FSEventStreamInvalidate( FSStream );
		FSEventStreamRelease( FSStream );
	}

	efSAFE_DELETE( WatcherGen );
}

void WatcherFSEvents::init() {
	CFStringRef CFDirectory =
		CFStringCreateWithCString( NULL, Directory.c_str(), kCFStringEncodingUTF8 );
	CFArrayRef CFDirectoryArray = CFArrayCreate( NULL, (const void**)&CFDirectory, 1, NULL );

	Uint32 streamFlags = kFSEventStreamCreateFlagNone;

	if ( FileWatcherFSEvents::isGranular() ) {
		streamFlags = efswFSEventStreamCreateFlagFileEvents | efswFSEventStreamCreateFlagNoDefer;
	} else {
		WatcherGen = new WatcherGeneric( ID, Directory, Listener, FWatcher.load(), Recursive );
	}

	FSEventStreamContext ctx;
	/* Initialize context */
	ctx.version = 0;
	ctx.info = this;
	ctx.retain = NULL;
	ctx.release = NULL;
	ctx.copyDescription = NULL;

	dispatch_queue_t queue = dispatch_queue_create(NULL, NULL);

	FSStream =
		FSEventStreamCreate( kCFAllocatorDefault, &FileWatcherFSEvents::FSEventCallback, &ctx,
							 CFDirectoryArray, kFSEventStreamEventIdSinceNow, 0., streamFlags );

	FSEventStreamSetDispatchQueue(FSStream, queue);

	FSEventStreamStart( FSStream );

	CFRelease( CFDirectoryArray );
	CFRelease( CFDirectory );
}

void WatcherFSEvents::sendFileAction( WatchID watchid, const std::string& dir,
									  const std::string& filename, Action action,
									  std::string oldFilename ) {
	Listener->handleFileAction( watchid, FileSystem::precomposeFileName( dir ),
								FileSystem::precomposeFileName( filename ), action, FileSystem::precomposeFileName( oldFilename ) );
}

void WatcherFSEvents::handleAddModDel( const Uint32& flags, const std::string& path,
									   std::string& dirPath, std::string& filePath ) {
	if ( flags & efswFSEventStreamEventFlagItemCreated ) {
		if ( FileInfo::exists( path ) ) {
			sendFileAction( ID, dirPath, filePath, Actions::Add );
		}
	}

	if ( flags & efswFSEventsModified ) {
		sendFileAction( ID, dirPath, filePath, Actions::Modified );
	}

	if ( flags & efswFSEventStreamEventFlagItemRemoved ) {
		// Since i don't know the order, at least i try to keep the data consistent with the real
		// state
		if ( !FileInfo::exists( path ) ) {
			sendFileAction( ID, dirPath, filePath, Actions::Delete );
		}
	}
}

void WatcherFSEvents::handleActions( std::vector<FSEvent>& events ) {
	size_t esize = events.size();

	for ( size_t i = 0; i < esize; i++ ) {
		FSEvent& event = events[i];

		if ( event.Flags &
			 ( kFSEventStreamEventFlagUserDropped | kFSEventStreamEventFlagKernelDropped |
			   kFSEventStreamEventFlagEventIdsWrapped | kFSEventStreamEventFlagHistoryDone |
			   kFSEventStreamEventFlagMount | kFSEventStreamEventFlagUnmount |
			   kFSEventStreamEventFlagRootChanged ) ) {
			continue;
		}

		if ( !Recursive ) {
			/** In case that is not recursive the watcher, ignore the events from subfolders */
			if ( event.Path.find_last_of( FileSystem::getOSSlash() ) != Directory.size() - 1 ) {
				continue;
			}
		}

		if ( FileWatcherFSEvents::isGranular() ) {
			std::string dirPath( FileSystem::pathRemoveFileName( event.Path ) );
			std::string filePath( FileSystem::fileNameFromPath( event.Path ) );

			if ( event.Flags &
				 ( efswFSEventStreamEventFlagItemCreated | efswFSEventStreamEventFlagItemRemoved |
				   efswFSEventStreamEventFlagItemRenamed ) ) {
				if ( dirPath != Directory ) {
					DirsChanged.insert( dirPath );
				}
			}

			// This is a mess. But it's FSEvents faults, because shrinks events from the same file
			// in one single event ( so there's no order for them ) For example a file could have
			// been added modified and erased, but i can't know if first was erased and then added
			// and modified, or added, then modified and then erased. I don't know what they were
			// thinking by doing this...
			efDEBUG( "Event in: %s - flags: %ld\n", event.Path.c_str(), event.Flags );

			if ( event.Flags & efswFSEventStreamEventFlagItemRenamed ) {
				if ( ( i + 1 < esize ) &&
					 ( events[i + 1].Flags & efswFSEventStreamEventFlagItemRenamed ) &&
					 ( events[i + 1].Id == event.Id + 1 ) ) {
					FSEvent& nEvent = events[i + 1];
					std::string newDir( FileSystem::pathRemoveFileName( nEvent.Path ) );
					std::string newFilepath( FileSystem::fileNameFromPath( nEvent.Path ) );

					if ( event.Path != nEvent.Path ) {
						if ( dirPath == newDir ) {
							if ( !FileInfo::exists( event.Path ) ) {
								sendFileAction( ID, dirPath, newFilepath, Actions::Moved,
												filePath );
							} else {
								sendFileAction( ID, dirPath, filePath, Actions::Moved,
												newFilepath );
							}
						} else {
							sendFileAction( ID, dirPath, filePath, Actions::Delete );
							sendFileAction( ID, newDir, newFilepath, Actions::Add );

							if ( nEvent.Flags & efswFSEventsModified ) {
								sendFileAction( ID, newDir, newFilepath, Actions::Modified );
							}
						}
					} else {
						handleAddModDel( nEvent.Flags, nEvent.Path, dirPath, filePath );
					}

					if ( nEvent.Flags & ( efswFSEventStreamEventFlagItemCreated |
										  efswFSEventStreamEventFlagItemRemoved |
										  efswFSEventStreamEventFlagItemRenamed ) ) {
						if ( newDir != Directory ) {
							DirsChanged.insert( newDir );
						}
					}

					// Skip the renamed file
					i++;
				} else if ( FileInfo::exists( event.Path ) ) {
					sendFileAction( ID, dirPath, filePath, Actions::Add );

					if ( event.Flags & efswFSEventsModified ) {
						sendFileAction( ID, dirPath, filePath, Actions::Modified );
					}
				} else {
					sendFileAction( ID, dirPath, filePath, Actions::Delete );
				}
			} else {
				handleAddModDel( event.Flags, event.Path, dirPath, filePath );
			}
		} else {
			efDEBUG( "Directory: %s changed\n", event.Path.c_str() );
			DirsChanged.insert( event.Path );
		}
	}
}

void WatcherFSEvents::process() {
	std::set<std::string>::iterator it = DirsChanged.begin();

	for ( ; it != DirsChanged.end(); it++ ) {
		if ( !FileWatcherFSEvents::isGranular() ) {
			WatcherGen->watchDir( ( *it ) );
		} else {
			sendFileAction( ID, FileSystem::pathRemoveFileName( ( *it ) ),
							FileSystem::fileNameFromPath( ( *it ) ), Actions::Modified );
		}
	}

	DirsChanged.clear();
}

} // namespace efsw

#endif
