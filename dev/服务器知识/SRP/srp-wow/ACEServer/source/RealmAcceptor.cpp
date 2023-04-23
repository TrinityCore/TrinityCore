
#include "RealmAcceptor.h"

Realm_Acceptor::Realm_Acceptor( ACE_Proactor * proactor )
{
	this->proactor( proactor );
}

Realm_Acceptor::~Realm_Acceptor()
{
}

Realm_Service * Realm_Acceptor::make_handler()
{
	Realm_Service * service;
	ACE_NEW_RETURN( service, Realm_Service( this->proactor() ), 0 );

	return service;
}
