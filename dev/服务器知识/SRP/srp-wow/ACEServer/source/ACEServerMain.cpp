
#include <ace/os_main.h>
#include <ace/os_ns_unistd.h>
#include <ace/Log_Msg.h>
#include "SystemConfig.h"
#include "RealmServer.h"
#include <iostream>

int ACE_TMAIN( int, ACE_TCHAR *[] )
{
	// start realmserver
	if( !REALM_SERVER->open() )
		return -1;

	int x;
	std::cin >> x;

	REALM_SERVER->close();

	return 0;
}
