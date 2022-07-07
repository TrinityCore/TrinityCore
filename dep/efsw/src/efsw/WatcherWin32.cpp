#include <efsw/WatcherWin32.hpp>
#include <efsw/String.hpp>

#if EFSW_PLATFORM == EFSW_PLATFORM_WIN32

namespace efsw
{

/// Unpacks events and passes them to a user defined callback.
void CALLBACK WatchCallback(DWORD dwErrorCode, DWORD dwNumberOfBytesTransfered, LPOVERLAPPED lpOverlapped)
{
	char szFile[MAX_PATH];
	PFILE_NOTIFY_INFORMATION pNotify;
	WatcherStructWin32 * tWatch = (WatcherStructWin32*) lpOverlapped;
	WatcherWin32 * pWatch = tWatch->Watch;
	size_t offset = 0;

	if (dwNumberOfBytesTransfered == 0)
	{
		RefreshWatch(tWatch); // If dwNumberOfBytesTransfered == 0, it means the buffer overflowed (too many changes between GetOverlappedResults calls). Those events are lost, but at least we can refresh so subsequent changes are seen again.
		return;
	}

	if (dwErrorCode == ERROR_SUCCESS)
	{
		do
		{
			bool skip = false;

			pNotify = (PFILE_NOTIFY_INFORMATION) &pWatch->mBuffer[offset];
			offset += pNotify->NextEntryOffset;

			int count = WideCharToMultiByte(CP_UTF8, 0, pNotify->FileName,
				pNotify->FileNameLength / sizeof(WCHAR),
				szFile, MAX_PATH - 1, NULL, NULL);
			szFile[count] = TEXT('\0');

			std::string nfile( szFile );

			if ( FILE_ACTION_MODIFIED == pNotify->Action )
			{
				FileInfo fifile( std::string( pWatch->DirName ) + nfile );

				if ( pWatch->LastModifiedEvent.file.ModificationTime == fifile.ModificationTime && pWatch->LastModifiedEvent.file.Size == fifile.Size && pWatch->LastModifiedEvent.fileName == nfile )
				{
					skip = true;
				}

				pWatch->LastModifiedEvent.fileName	= nfile;
				pWatch->LastModifiedEvent.file		= fifile;
			}

			if ( !skip )
			{
				pWatch->Watch->handleAction(pWatch, nfile, pNotify->Action);
			}
		} while (pNotify->NextEntryOffset != 0);
	}

	if (!pWatch->StopNow)
	{
		RefreshWatch(tWatch);
	}
}

/// Refreshes the directory monitoring.
bool RefreshWatch(WatcherStructWin32* pWatch)
{
	return ReadDirectoryChangesW(
				pWatch->Watch->DirHandle,
				pWatch->Watch->mBuffer,
				sizeof(pWatch->Watch->mBuffer),
				pWatch->Watch->Recursive,
				pWatch->Watch->NotifyFilter,
				NULL,
				&pWatch->Overlapped,
				NULL
	) != 0;
}

/// Stops monitoring a directory.
void DestroyWatch(WatcherStructWin32* pWatch)
{
	if (pWatch)
	{
		WatcherWin32 * tWatch = pWatch->Watch;

		tWatch->StopNow = true;

		CancelIoEx(tWatch->DirHandle, &pWatch->Overlapped);

		RefreshWatch(pWatch);
		CloseHandle(pWatch->Overlapped.hEvent);
		CloseHandle(pWatch->Watch->DirHandle);
		efSAFE_DELETE_ARRAY( pWatch->Watch->DirName );
		efSAFE_DELETE( pWatch->Watch );
		HeapFree(GetProcessHeap(), 0, pWatch);
	}
}

/// Starts monitoring a directory.
WatcherStructWin32* CreateWatch(LPCWSTR szDirectory, bool recursive, DWORD NotifyFilter)
{
	WatcherStructWin32 * tWatch;
	size_t ptrsize = sizeof(*tWatch);
	tWatch = static_cast<WatcherStructWin32*>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, ptrsize));

	WatcherWin32 * pWatch = new WatcherWin32();
	tWatch->Watch = pWatch;

	pWatch->DirHandle = CreateFileW(
							szDirectory,
							GENERIC_READ,
							FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
							NULL,
							OPEN_EXISTING,
							FILE_FLAG_BACKUP_SEMANTICS | FILE_FLAG_OVERLAPPED,
							NULL
						);

	if (pWatch->DirHandle != INVALID_HANDLE_VALUE)
	{
		tWatch->Overlapped.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
		pWatch->NotifyFilter = NotifyFilter;
		pWatch->Recursive = recursive;

		if (RefreshWatch(tWatch))
		{
			return tWatch;
		}
		else
		{
			CloseHandle(tWatch->Overlapped.hEvent);
			CloseHandle(pWatch->DirHandle);
		}
	}

	HeapFree(GetProcessHeap(), 0, tWatch);
	return NULL;
}

}

 #endif
