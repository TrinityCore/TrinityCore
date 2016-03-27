#ifndef EFSW_WATCHERWIN32_HPP
#define EFSW_WATCHERWIN32_HPP

#include <efsw/FileWatcherImpl.hpp>
#include <efsw/FileInfo.hpp>

#if EFSW_PLATFORM == EFSW_PLATFORM_WIN32

#include <windows.h>

#ifdef EFSW_COMPILER_MSVC
	#pragma comment(lib, "comctl32.lib")
	#pragma comment(lib, "user32.lib")
	#pragma comment(lib, "ole32.lib")

	// disable secure warnings
	#pragma warning (disable: 4996)
#endif

namespace efsw
{

class WatcherWin32;

/// Internal watch data
struct WatcherStructWin32
{
	OVERLAPPED Overlapped;
	WatcherWin32 *	Watch;
};

class cLastModifiedEvent
{
	public:
		cLastModifiedEvent() {}
		FileInfo	file;
		std::string fileName;
};

bool RefreshWatch(WatcherStructWin32* pWatch);

void CALLBACK WatchCallback(DWORD dwErrorCode, DWORD dwNumberOfBytesTransfered, LPOVERLAPPED lpOverlapped);

void DestroyWatch(WatcherStructWin32* pWatch);

WatcherStructWin32* CreateWatch(LPCWSTR szDirectory, bool recursive, DWORD NotifyFilter);

class WatcherWin32 : public Watcher
{
	public:
		WatcherWin32() :
			Struct( NULL ),
			DirHandle( NULL ),
			lParam( 0 ),
			NotifyFilter( 0 ),
			StopNow( false ),
			Watch( NULL ),
			DirName( NULL )
		{
		}

		WatcherStructWin32 * Struct;
		HANDLE DirHandle;
		BYTE mBuffer[63 * 1024]; // do NOT make this bigger than 64K because it will fail if the folder being watched is on the network! (see http://msdn.microsoft.com/en-us/library/windows/desktop/aa365465(v=vs.85).aspx)
		LPARAM lParam;
		DWORD NotifyFilter;
		bool StopNow;
		FileWatcherImpl* Watch;
		char* DirName;
		cLastModifiedEvent LastModifiedEvent;
};

}

#endif

#endif
