
#ifndef __REALM_ACCEPTOR_H__
#define __REALM_ACCEPTOR_H__

#include <ace/Asynch_Acceptor.h>
#include <ace/INET_Addr.h>

#include "RealmService.h"

class ACE_Proactor;

class Realm_Acceptor : public ACE_Asynch_Acceptor<Realm_Service>
{
public:
	Realm_Acceptor( ACE_Proactor * proactor );
	virtual ~Realm_Acceptor();

private:
	Realm_Service * make_handler();
};

#endif // __REALM_ACCEPTOR_H__
