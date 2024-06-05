#include <efsw/Debug.hpp>
#include <efsw/String.hpp>
#include <efsw/WatcherWin32.hpp>

#if EFSW_PLATFORM == EFSW_PLATFORM_WIN32

#include <algorithm>

namespace efsw {

/// Unpacks events and passes them to a user defined callback.
void CALLBACK WatchCallback( DWORD dwNumberOfBytesTransfered, LPOVERLAPPED lpOverlapped ) {

	if ( NULL == lpOverlapped ) {
		return;
	}

	PFILE_NOTIFY_INFORMATION pNotify;
	WatcherStructWin32* tWatch = (WatcherStructWin32*)lpOverlapped;
	WatcherWin32* pWatch = tWatch->Watch;
	size_t offset = 0;

	if ( dwNumberOfBytesTransfered == 0 ) {
		if ( nullptr != pWatch && !pWatch->StopNow ) {
			RefreshWatch( tWatch );
		} else {
			return;
		}
	}

	do {
		bool skip = false;

		pNotify = (PFILE_NOTIFY_INFORMATION)&pWatch->Buffer[offset];
		offset += pNotify->NextEntryOffset;
		int count =
			WideCharToMultiByte( CP_UTF8, 0, pNotify->FileName,
								 pNotify->FileNameLength / sizeof( WCHAR ), NULL, 0, NULL, NULL );
		if ( count == 0 )
			continue;

		std::string nfile( count, '\0' );

		count = WideCharToMultiByte( CP_UTF8, 0, pNotify->FileName,
									 pNotify->FileNameLength / sizeof( WCHAR ), &nfile[0], count,
									 NULL, NULL );

		if ( FILE_ACTION_MODIFIED == pNotify->Action ) {
			FileInfo fifile( std::string( pWatch->DirName ) + nfile );

			if ( pWatch->LastModifiedEvent.file.ModificationTime == fifile.ModificationTime &&
				 pWatch->LastModifiedEvent.file.Size == fifile.Size &&
				 pWatch->LastModifiedEvent.fileName == nfile ) {
				skip = true;
			}

			pWatch->LastModifiedEvent.fileName = nfile;
			pWatch->LastModifiedEvent.file = fifile;
		}

		if ( !skip ) {
			pWatch->Watch->handleAction( pWatch, nfile, pNotify->Action );
		}
	} while ( pNotify->NextEntryOffset != 0 );

	if ( !pWatch->StopNow ) {
		RefreshWatch( tWatch );
	}
}

/// Refreshes the directory monitoring.
bool RefreshWatch( WatcherStructWin32* pWatch ) {
	bool bRet = ReadDirectoryChangesW( pWatch->Watch->DirHandle, pWatch->Watch->Buffer.data(),
		pWatch->Watch->Buffer.size(), pWatch->Watch->Recursive,
		pWatch->Watch->NotifyFilter, NULL, &pWatch->Overlapped,	NULL ) != 0;

	if ( !bRet ) {
		std::string error = std::to_string( GetLastError() );
		Errors::Log::createLastError( Errors::WatcherFailed, error );
	}

	return bRet;
}

/// Stops monitoring a directory.
void DestroyWatch( WatcherStructWin32* pWatch ) {
	if ( pWatch ) {
		WatcherWin32* tWatch = pWatch->Watch;
		tWatch->StopNow = true;
		CancelIoEx( pWatch->Watch->DirHandle, &pWatch->Overlapped );
		CloseHandle( pWatch->Watch->DirHandle );
		efSAFE_DELETE_ARRAY( pWatch->Watch->DirName );
		efSAFE_DELETE( pWatch->Watch );
	}
}

/// Starts monitoring a directory.
WatcherStructWin32* CreateWatch( LPCWSTR szDirectory, bool recursive,
								 DWORD bufferSize, DWORD notifyFilter, HANDLE iocp ) {
	WatcherStructWin32* tWatch;
	size_t ptrsize = sizeof( *tWatch );
	tWatch = static_cast<WatcherStructWin32*>(
		HeapAlloc( GetProcessHeap(), HEAP_ZERO_MEMORY, ptrsize ) );

	WatcherWin32* pWatch = new WatcherWin32(bufferSize);
	tWatch->Watch = pWatch;

	pWatch->DirHandle = CreateFileW(
		szDirectory, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, NULL,
		OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS | FILE_FLAG_OVERLAPPED, NULL );

	if ( pWatch->DirHandle != INVALID_HANDLE_VALUE &&
		 CreateIoCompletionPort( pWatch->DirHandle, iocp, 0, 1 ) ) {
		pWatch->NotifyFilter = notifyFilter;
		pWatch->Recursive = recursive;

		if ( RefreshWatch( tWatch ) ) {
			return tWatch;
		}
	}

	CloseHandle( pWatch->DirHandle );
	efSAFE_DELETE( pWatch->Watch );
	HeapFree( GetProcessHeap(), 0, tWatch );
	return NULL;
}

} // namespace efsw

#endif
