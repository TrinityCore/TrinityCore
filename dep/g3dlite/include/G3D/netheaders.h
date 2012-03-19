#ifndef G3D_netheaders_h
#define G3D_netheaders_h

#include "G3D/platform.h"

#ifdef G3D_WIN32
#   if (G3D_WINSOCK_MAJOR_VERSION == 2)
#       include <winsock2.h>
#   elif (G3D_WINSOCK_MAJOR_VERSION == 1)
#       include <winsock.h>
#   endif
#else
#   include <sys/types.h>
#   include <sys/socket.h>
#   include <netinet/in.h>
#   ifndef SOCKADDR_IN
#       define SOCKADDR_IN struct sockaddr_in
#   endif
#   ifndef SOCKET
#       define SOCKET int
#   endif
#endif

#endif
