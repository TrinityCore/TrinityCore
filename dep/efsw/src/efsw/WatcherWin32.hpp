#ifndef EFSW_WATCHERWIN32_HPP
#define EFSW_WATCHERWIN32_HPP

#include <efsw/FileInfo.hpp>
#include <efsw/FileWatcherImpl.hpp>
#include <vector>

#if EFSW_PLATFORM == EFSW_PLATFORM_WIN32

#include <windows.h>

#ifdef EFSW_COMPILER_MSVC
#pragma comment( lib, "comctl32.lib" )
#pragma comment( lib, "user32.lib" )
#pragma comment( lib, "ole32.lib" )

// disable secure warnings
#pragma warning( disable : 4996 )
#endif

namespace efsw {

class WatcherWin32;

/// Internal watch data
struct WatcherStructWin32 {
	OVERLAPPED Overlapped;
	WatcherWin32* Watch;
};

struct sLastModifiedEvent {
	FileInfo file;
	std::string fileName;
};

bool RefreshWatch( WatcherStructWin32* pWatch );

void CALLBACK WatchCallback( DWORD dwNumberOfBytesTransfered, LPOVERLAPPED lpOverlapped );

void DestroyWatch( WatcherStructWin32* pWatch );

WatcherStructWin32* CreateWatch( LPCWSTR szDirectory, bool recursive,
							     DWORD bufferSize, DWORD notifyFilter, HANDLE iocp );

class WatcherWin32 : public Watcher {
  public:
	WatcherWin32(DWORD dwBufferSize) :
		Struct( NULL ),
		DirHandle( NULL ),
		Buffer(),
		lParam( 0 ),
		NotifyFilter( 0 ),
		StopNow( false ),
		Watch( NULL ),
		DirName( NULL ) {
			Buffer.resize(dwBufferSize);
		}

	WatcherStructWin32* Struct;
	HANDLE DirHandle;
	std::vector<BYTE> Buffer;
	LPARAM lParam;
	DWORD NotifyFilter;
	bool StopNow;
	FileWatcherImpl* Watch;
	char* DirName;
	sLastModifiedEvent LastModifiedEvent;
};

} // namespace efsw

#endif

#endif
