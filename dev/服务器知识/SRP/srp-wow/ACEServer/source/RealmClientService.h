
#ifndef __REALM_CLIENT_SERVICE_H__
#define __REALM_CLIENT_SERVICE_H__

#include <ace/asynch_io.h>
#include "Utility/BigNumber.h"

class Realm_Service;
class ACE_Message_Block;

class Realm_Client_Service
{
public:
	Realm_Client_Service( Realm_Service * network );
	~Realm_Client_Service();

	int process( ACE_Message_Block * msg );

private:
	void process_logon_request( ACE_Message_Block & mb );
	void process_logon_check( ACE_Message_Block & mb );
	void process_realm_list( ACE_Message_Block & mb );

private:
	// used for auth
	BigNumber N, s, g, v;
	BigNumber b, B;
	BigNumber rs;

	BigNumber K;
	std::string login_;

	Realm_Service * network_service_;
};

#endif // __REALM_CLIENT_SERVICE_H__
