#ifndef EFSW_FILEWATCHERFSEVENTS_HPP
#define EFSW_FILEWATCHERFSEVENTS_HPP

#include <efsw/FileWatcherImpl.hpp>

#if EFSW_PLATFORM == EFSW_PLATFORM_FSEVENTS

#include <CoreFoundation/CoreFoundation.h>
#include <CoreServices/CoreServices.h>
#include <efsw/WatcherFSEvents.hpp>
#include <map>
#include <list>
#include <vector>

namespace efsw
{

/* OSX < 10.7 has no file events */
/* So i declare the events constants */
enum FSEventEvents
{
	efswFSEventStreamCreateFlagFileEvents			= 0x00000010,
	efswFSEventStreamEventFlagItemCreated			= 0x00000100,
	efswFSEventStreamEventFlagItemRemoved			= 0x00000200,
	efswFSEventStreamEventFlagItemInodeMetaMod		= 0x00000400,
	efswFSEventStreamEventFlagItemRenamed			= 0x00000800,
	efswFSEventStreamEventFlagItemModified			= 0x00001000,
	efswFSEventStreamEventFlagItemFinderInfoMod		= 0x00002000,
	efswFSEventStreamEventFlagItemChangeOwner		= 0x00004000,
	efswFSEventStreamEventFlagItemXattrMod			= 0x00008000,
	efswFSEventStreamEventFlagItemIsFile			= 0x00010000,
	efswFSEventStreamEventFlagItemIsDir				= 0x00020000,
	efswFSEventStreamEventFlagItemIsSymlink			= 0x00040000,
	efswFSEventsModified							= efswFSEventStreamEventFlagItemFinderInfoMod	|
													  efswFSEventStreamEventFlagItemModified		|
													  efswFSEventStreamEventFlagItemInodeMetaMod	|
													  efswFSEventStreamEventFlagItemChangeOwner		|
													  efswFSEventStreamEventFlagItemXattrMod
};

/// Implementation for Win32 based on ReadDirectoryChangesW.
/// @class FileWatcherFSEvents
class FileWatcherFSEvents : public FileWatcherImpl
{
	friend class WatcherFSEvents;
	public:
		/// @return If FSEvents supports file-level notifications ( true if OS X >= 10.7 )
		static bool isGranular();
		
		/// type for a map from WatchID to WatcherWin32 pointer
		typedef std::map<WatchID, WatcherFSEvents*> WatchMap;

		FileWatcherFSEvents( FileWatcher * parent );

		virtual ~FileWatcherFSEvents();

		/// Add a directory watch
		/// On error returns WatchID with Error type.
		WatchID addWatch(const std::string& directory, FileWatchListener* watcher, bool recursive);

		/// Remove a directory watch. This is a brute force lazy search O(nlogn).
		void removeWatch(const std::string& directory);

		/// Remove a directory watch. This is a map lookup O(logn).
		void removeWatch(WatchID watchid);

		/// Updates the watcher. Must be called often.
		void watch();

		/// Handles the action
		void handleAction(Watcher* watch, const std::string& filename, unsigned long action, std::string oldFilename = "");

		/// @return Returns a list of the directories that are being watched
		std::list<std::string> directories();
	protected:
		static void FSEventCallback(	ConstFSEventStreamRef streamRef,
										void *userData, 
										size_t numEvents, 
										void *eventPaths, 
										const FSEventStreamEventFlags eventFlags[], 
										const FSEventStreamEventId eventIds[]
		);
		
		CFRunLoopRef mRunLoopRef;
		
		/// Vector of WatcherWin32 pointers
		WatchMap mWatches;
		
		/// The last watchid
		WatchID mLastWatchID;

		Thread * mThread;

		Mutex mWatchesLock;

		bool pathInWatches( const std::string& path );

		std::list<WatcherFSEvents*> mNeedInit;
	private:
		void run();
};

}

#endif

#endif
