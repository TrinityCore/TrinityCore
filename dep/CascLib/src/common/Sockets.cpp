/*****************************************************************************/
/* Sockets.cpp                            Copyright (c) Ladislav Zezula 2021 */
/*---------------------------------------------------------------------------*/
/* Don't call this module "Socket.cpp", otherwise VS 2019 will not link it   */
/* Socket functions for CascLib.                                             */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 13.02.21  1.00  Lad  Created                                              */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "../CascLib.h"
#include "../CascCommon.h"

//-----------------------------------------------------------------------------
// Local variables

CASC_SOCKET_CACHE SocketCache;

//-----------------------------------------------------------------------------
// CASC_SOCKET functions

// Guarantees that there is zero terminator after the response
char * CASC_SOCKET::ReadResponse(const char * request, size_t request_length, size_t * PtrLength)
{
    CASC_MIME_HTTP HttpInfo;
    char * server_response = NULL;
    size_t total_received = 0;
    size_t block_increment = 0x8000;
    size_t buffer_size = block_increment;
    int bytes_received = 0;

    // Pre-set the result length
    if(PtrLength != NULL)
        PtrLength[0] = 0;
    if(request_length == 0)
        request_length = strlen(request);

    // Lock the socket
    CascLock(Lock);

    // Send the request to the remote host. On Linux, this call may send signal(SIGPIPE),
    // we need to prevend that by using the MSG_NOSIGNAL flag. On Windows, it fails normally.
    while(send(sock, request, (int)request_length, MSG_NOSIGNAL) == SOCKET_ERROR)
    {
        // If the connection was closed by the remote host, we try to reconnect
        if(ReconnectAfterShutdown(sock, remoteItem) == INVALID_SOCKET)
        {
            SetCascError(ERROR_NETWORK_NOT_AVAILABLE);
            CascUnlock(Lock);
            return NULL;
        }
    }

    // Allocate buffer for server response. Allocate one extra byte for zero terminator
    if((server_response = CASC_ALLOC<char>(buffer_size + 1)) != NULL)
    {
        for(;;)
        {
            // Reallocate the buffer size, if needed
            if(total_received == buffer_size)
            {
                if((server_response = CASC_REALLOC(char, server_response, buffer_size + block_increment + 1)) == NULL)
                {
                    SetCascError(ERROR_NOT_ENOUGH_MEMORY);
                    CascUnlock(Lock);
                    return NULL;
                }
                buffer_size += block_increment;
            }

            // Receive the next part of the response, up to buffer size
            // Return value 0 means "connection closed", -1 means an error
            bytes_received = recv(sock, server_response + total_received, (int)(buffer_size - total_received), 0);
            if(bytes_received <= 0)
                break;

            // Append the number of bytes received. Also terminate response with zero
            total_received += bytes_received;
            server_response[total_received] = 0;

            // On a HTTP protocol, we need to check whether we received all data
            if(HttpInfo.IsDataComplete(server_response, total_received))
                break;
        }
    }

    // Unlock the socket
    CascUnlock(Lock);

    // Give the result to the caller
    if(PtrLength != NULL)
        PtrLength[0] = total_received;
    return server_response;
}

DWORD CASC_SOCKET::AddRef()
{
    return CascInterlockedIncrement(&dwRefCount);
}

void CASC_SOCKET::Release()
{
    // Note: If this is a cached socket, there will be extra reference from the cache
    if(CascInterlockedDecrement(&dwRefCount) == 0)
    {
        Delete();
    }
}

int CASC_SOCKET::GetSockError()
{
#ifdef PLATFORM_WINDOWS
    return WSAGetLastError();
#else
    return errno;
#endif
}

DWORD CASC_SOCKET::GetAddrInfoWrapper(const char * hostName, unsigned portNum, PADDRINFO hints, PADDRINFO * ppResult)
{
    char portNumString[16];

    // Prepare the port number
    CascStrPrintf(portNumString, _countof(portNumString), "%d", portNum);

    // Attempt to connect
    for(;;)
    {
        // Attempt to call the addrinfo
        DWORD dwErrCode = getaddrinfo(hostName, portNumString, hints, ppResult);

        // Error-specific handling
        switch(dwErrCode)
        {
#ifdef PLATFORM_WINDOWS
            case WSANOTINITIALISED:     // Windows-specific: WSAStartup not called
            {
                WSADATA wsd;

                WSAStartup(MAKEWORD(2, 2), &wsd);
                continue;
            }
#endif
            case EAI_AGAIN:             // Temporary error, try again
                continue;

            default:                    // Any other result, incl. ERROR_SUCCESS
                return dwErrCode;
        }
    }
}

SOCKET CASC_SOCKET::CreateAndConnect(addrinfo * remoteItem)
{
    SOCKET sock;

    // Create new socket
    // On error, returns returns INVALID_SOCKET (-1) on Windows, -1 on Linux
    if((sock = socket(remoteItem->ai_family, remoteItem->ai_socktype, remoteItem->ai_protocol)) > 0)
    {
        // Connect to the remote host
        // On error, returns SOCKET_ERROR (-1) on Windows, -1 on Linux
        if(connect(sock, remoteItem->ai_addr, (int)remoteItem->ai_addrlen) == 0)
            return sock;

        // Failed. Close the socket and return 0
        closesocket(sock);
        sock = INVALID_SOCKET;
    }

    return sock;
}

SOCKET CASC_SOCKET::ReconnectAfterShutdown(SOCKET & sock, addrinfo * remoteItem)
{
    // Retrieve the error code related to previous socket operation
    switch(GetSockError())
    {
        case EPIPE:         // Non-Windows
        case WSAECONNRESET: // Windows
        {
            // Close the old socket
            if(sock != INVALID_SOCKET)
                closesocket(sock);

            // Attempt to reconnect
            sock = CreateAndConnect(remoteItem);
            return sock;
        }
    }

    // Another problem
    return INVALID_SOCKET;
}

PCASC_SOCKET CASC_SOCKET::New(addrinfo * remoteList, addrinfo * remoteItem, const char * hostName, unsigned portNum, SOCKET sock)
{
    PCASC_SOCKET pSocket;
    size_t length = strlen(hostName);

    // Allocate enough bytes
    pSocket = (PCASC_SOCKET)CASC_ALLOC<BYTE>(sizeof(CASC_SOCKET) + length);
    if(pSocket != NULL)
    {
        // Fill the entire object with zero
        memset(pSocket, 0, sizeof(CASC_SOCKET) + length);
        pSocket->remoteList = remoteList;
        pSocket->remoteItem = remoteItem;
        pSocket->dwRefCount = 1;
        pSocket->portNum = portNum;
        pSocket->sock = sock;

        // Init the remote host name
        CascStrCopy((char *)pSocket->hostName, length + 1, hostName);

        // Init the socket lock
        CascInitLock(pSocket->Lock);
    }

    return pSocket;
}

PCASC_SOCKET CASC_SOCKET::Connect(const char * hostName, unsigned portNum)
{
    PCASC_SOCKET pSocket;
    addrinfo * remoteList;
    addrinfo * remoteItem;
    addrinfo hints = {0};
    SOCKET sock;
    int nErrCode;

    // Retrieve the information about the remote host
    // This will fail immediately if there is no connection to the internet
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    nErrCode = GetAddrInfoWrapper(hostName, portNum, &hints, &remoteList);

    // Handle error code
    if(nErrCode == 0)
    {
        // Try to connect to any address provided by the getaddrinfo()
        for(remoteItem = remoteList; remoteItem != NULL; remoteItem = remoteItem->ai_next)
        {
            // Create new socket and connect to the remote host
            if((sock = CreateAndConnect(remoteItem)) != 0)
            {
                // Create new instance of the CASC_SOCKET structure
                if((pSocket = CASC_SOCKET::New(remoteList, remoteItem, hostName, portNum, sock)) != NULL)
                {
                    return pSocket;
                }

                // Close the socket
                closesocket(sock);
            }
        }

        // Couldn't find a network
        nErrCode = ERROR_NETWORK_NOT_AVAILABLE;
    }

    SetCascError(nErrCode);
    return NULL;
}

void CASC_SOCKET::Delete()
{
    PCASC_SOCKET pThis = this;

    // Remove the socket from the cache
    if(pCache != NULL)
        pCache->UnlinkSocket(this);
    pCache = NULL;

    // Close the socket, if any
    if(sock != 0)
        closesocket(sock);
    sock = 0;

    // Free the lock
    CascFreeLock(Lock);

    // Free the socket itself
    CASC_FREE(pThis);
}

//-----------------------------------------------------------------------------
// The CASC_SOCKET_CACHE class

CASC_SOCKET_CACHE::CASC_SOCKET_CACHE()
{
    pFirst = pLast = NULL;
    dwRefCount = 0;
}

CASC_SOCKET_CACHE::~CASC_SOCKET_CACHE()
{
    PurgeAll();
}

PCASC_SOCKET CASC_SOCKET_CACHE::Find(const char * hostName, unsigned portNum)
{
    PCASC_SOCKET pSocket;

    for(pSocket = pFirst; pSocket != NULL; pSocket = pSocket->pNext)
    {
        if(!_stricmp(pSocket->hostName, hostName) && (pSocket->portNum == portNum))
            break;
    }

    return pSocket;
}

PCASC_SOCKET CASC_SOCKET_CACHE::InsertSocket(PCASC_SOCKET pSocket)
{
    if(pSocket != NULL && pSocket->pCache == NULL)
    {
        // Do we have caching turned on?
        if(dwRefCount > 0)
        {
            // Insert one reference to the socket to mark it as cached
            pSocket->AddRef();

            // Insert the socket to the chain
            if(pFirst == NULL && pLast == NULL)
            {
                pFirst = pLast = pSocket;
            }
            else
            {
                pSocket->pPrev = pLast;
                pLast->pNext = pSocket;
                pLast = pSocket;
            }

            // Mark the socket as cached
            pSocket->pCache = this;
        }
    }

    return pSocket;
}

void CASC_SOCKET_CACHE::UnlinkSocket(PCASC_SOCKET pSocket)
{
    // Only if it's a valid socket
    if(pSocket != NULL)
    {
        // Check the first and the last items
        if(pSocket == pFirst)
            pFirst = pSocket->pNext;
        if(pSocket == pLast)
            pLast = pSocket->pPrev;

        // Disconnect the socket from the chain
        if(pSocket->pPrev != NULL)
            pSocket->pPrev->pNext = pSocket->pNext;
        if(pSocket->pNext != NULL)
            pSocket->pNext->pPrev = pSocket->pPrev;
    }
}

void CASC_SOCKET_CACHE::SetCaching(bool bAddRef)
{
    PCASC_SOCKET pSocket;
    PCASC_SOCKET pNext;

    // We need to increment reference count for each enabled caching
    if(bAddRef)
    {
        // Add one reference to all currently held sockets
        if(dwRefCount == 0)
        {
            for(pSocket = pFirst; pSocket != NULL; pSocket = pSocket->pNext)
                pSocket->AddRef();
        }

        // Increment of references for the future sockets
        CascInterlockedIncrement(&dwRefCount);
    }
    else
    {
        // Sanity check for multiple calls to dereference
        assert(dwRefCount > 0);

        // Dereference the reference count. If drops to zero, dereference all sockets as well
        if(CascInterlockedDecrement(&dwRefCount) == 0)
        {
            for(pSocket = pFirst; pSocket != NULL; pSocket = pNext)
            {
                pNext = pSocket->pNext;
                pSocket->Release();
            }
        }
    }
}

void CASC_SOCKET_CACHE::PurgeAll()
{
    PCASC_SOCKET pSocket;
    PCASC_SOCKET pNext;

    // Dereference all current sockets
    for(pSocket = pFirst; pSocket != NULL; pSocket = pNext)
    {
        pNext = pSocket->pNext;
        pSocket->Delete();
    }
}

//-----------------------------------------------------------------------------
// Public functions

PCASC_SOCKET sockets_connect(const char * hostName, unsigned portNum)
{
    PCASC_SOCKET pSocket;

    // Try to find the item in the cache
    if((pSocket = SocketCache.Find(hostName, portNum)) != NULL)
    {
        pSocket->AddRef();
    }
    else
    {
        // Create new socket and connect it to the remote host
        pSocket = CASC_SOCKET::Connect(hostName, portNum);

        // Insert it to the cache, if it's a HTTP connection
        if(pSocket->portNum == CASC_PORT_HTTP)
            pSocket = SocketCache.InsertSocket(pSocket);
    }

    return pSocket;
}

void sockets_set_caching(bool caching)
{
    SocketCache.SetCaching(caching);
}
