#ifndef EFSW_FILEWATCHERWIN32_HPP
#define EFSW_FILEWATCHERWIN32_HPP

#include <efsw/base.hpp>

#if EFSW_PLATFORM == EFSW_PLATFORM_WIN32

#include <efsw/WatcherWin32.hpp>
#include <vector>
#include <map>

namespace efsw
{

/// Implementation for Win32 based on ReadDirectoryChangesW.
/// @class FileWatcherWin32
class FileWatcherWin32 : public FileWatcherImpl
{
	public:
		/// type for a map from WatchID to WatcherWin32 pointer
		typedef std::vector<WatcherStructWin32*> WatchVector;
		typedef std::vector<HANDLE>	HandleVector;

		FileWatcherWin32( FileWatcher * parent );

		virtual ~FileWatcherWin32();

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
		/// Vector of WatcherWin32 pointers
		WatchVector mWatches;

		/// Keeps an updated handles vector
		HandleVector mHandles;

		/// The last watchid
		WatchID mLastWatchID;

		Thread * mThread;

		Mutex mWatchesLock;

		bool pathInWatches( const std::string& path );
	private:
		void run();
};

}

#endif

#endif
