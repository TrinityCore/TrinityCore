
#include <ace/Proactor.h>
#include <ace/WIN32_Proactor.h>

#include "RealmNetworkThread.h"
#include "RealmAcceptor.h"
#include "SystemConfig.h"

RealmNetwork_Thread::RealmNetwork_Thread() : ACE_Task_Base()
{
	this->running_ = false;
	this->proactor_ = 0;
}

RealmNetwork_Thread::~RealmNetwork_Thread()
{
	if( this->running_ )
		this->close();
}

int RealmNetwork_Thread::svc()
{
	ACE_NEW_RETURN (proactor_, ACE_Proactor, -1);
	ACE_DEBUG ((LM_DEBUG, ACE_TEXT("(%t) RealmNetwork_Thread::svc Create Proactor OK\n")));

	// start acceptor
	Realm_Acceptor acceptor( proactor_ );
	ACE_INET_Addr listen_addr( SERVER_LISTEN_PORT );

	if (acceptor.open( listen_addr,
		0,
		1,						// address
		5,						// backlog
		1,						// reuse address
		this->proactor_) != 0)
	{
		ACE_ERROR_RETURN ((LM_ERROR, ACE_TEXT("%p\n"), ACE_TEXT("RealmNetwork_Thread acceptor open")), -1);
	}

	// run event loop
	if( this->proactor_->proactor_run_event_loop() == -1 )
		ACE_ERROR_RETURN ((LM_ERROR, "(%P|%t):%p.\n", "RealmNetwork_Thread <Proactor::run_event_loop> failed"), -1);

	return 0;
}

int RealmNetwork_Thread::open()
{
	// avtivate thread
	if( this->activate() == -1 )
	{
		ACE_ERROR ((LM_ERROR, "%N:%l:%p\n", "RealmNetwork_Thread:open: <activate> failed"));
		return -1;
	}

	this->running_ = true;

	return 0;
}

int RealmNetwork_Thread::close()
{
	if( !this->running_ )
		return 0;

	if( this->proactor_->proactor_end_event_loop() == -1 )
		ACE_ERROR_RETURN ((LM_ERROR, "(%P|%t):%p.\n", "RealmNetwork_Thread <Proactor::proactor_end_event_loop> failed"), -1);

	delete this->proactor_;
	this->proactor_ = 0;

	if( this->wait() == -1 )
		ACE_ERROR ((LM_ERROR, ACE_TEXT ("%p.\n"), ACE_TEXT ("RealmNetwork_Thread unable to stop thread pool")));

	this->running_ = false;

	return 0;
}
