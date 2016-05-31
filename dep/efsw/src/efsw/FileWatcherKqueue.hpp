#ifndef EFSW_FILEWATCHEROSX_HPP
#define EFSW_FILEWATCHEROSX_HPP

#include <efsw/FileWatcherImpl.hpp>

#if EFSW_PLATFORM == EFSW_PLATFORM_KQUEUE || EFSW_PLATFORM == EFSW_PLATFORM_FSEVENTS

#include <efsw/WatcherKqueue.hpp>

namespace efsw
{

/// Implementation for OSX based on kqueue.
/// @class FileWatcherKqueue
class FileWatcherKqueue : public FileWatcherImpl
{
	friend class WatcherKqueue;
	public:
		FileWatcherKqueue( FileWatcher * parent );

		virtual ~FileWatcherKqueue();

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
		/// Map of WatchID to WatchStruct pointers
		WatchMap mWatches;

		/// time out data
		struct timespec mTimeOut;

		/// WatchID allocator
		int mLastWatchID;

		Thread * mThread;

		Mutex mWatchesLock;

		std::list<WatchID> mRemoveList;

		long mFileDescriptorCount;

		bool mAddingWatcher;

		bool isAddingWatcher() const;

		bool pathInWatches( const std::string& path );

		void addFD();

		void removeFD();

		bool availablesFD();
	private:
		void run();
};

}

#endif

#endif
