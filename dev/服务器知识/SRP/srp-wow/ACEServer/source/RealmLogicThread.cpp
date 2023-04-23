
#include "RealmLogicThread.h"
#include "RealmClientService.h"
#include "SystemConfig.h"

RealmLogic_Thread::RealmLogic_Thread() : ACE_Task<ACE_MT_SYNCH>()
{
	this->running_ = false;
}

RealmLogic_Thread::~RealmLogic_Thread()
{
	if( this->running_ )
		this->close();
}

int RealmLogic_Thread::svc()
{
	for( ACE_Message_Block * message = 0; ; )
	{
		if( this->getq(message) == -1 )
			ACE_ERROR_RETURN ((LM_ERROR,ACE_TEXT("%p\n"), ACE_TEXT("getq")), -1);

		if( message->msg_type() == ACE_Message_Block::MB_HANGUP )
		{
			ACE_DEBUG ((LM_DEBUG, ACE_TEXT("RealmLogic_Thread::svc hangup\n")));
			message->release();
			break;
		}

		// ...
		switch( message->msg_type() ) 
		{
		case MB_NORMAL_PACKET:
			{
				if( message->length() < 4 )
				{
					message->release();
					ACE_ERROR ((LM_ERROR, ACE_TEXT("RealmLogic_Thread::svc normal packet length error\n")));
					continue;
				}
				unsigned int handle = *reinterpret_cast<unsigned int *>( message->rd_ptr() );
				message->rd_ptr( 4 );

				ClientServiceMap::iterator itr = client_service_map_.find( handle );
				if( itr != client_service_map_.end() )
				{
					Realm_Client_Service * client_service = itr->second;
					if( client_service->process( message ) == -1 )
						ACE_ERROR ((LM_ERROR, ACE_TEXT("RealmLogic_Thread::svc normal packet process error\n")));
					message->release();
				}
				else
				{
					message->release();
					ACE_ERROR ((LM_ERROR, ACE_TEXT("RealmLogic_Thread::svc normal packet error. cannot find the client_service\n")));
				}
			}
			break;

		case MB_CONNECT_PACKET:
			{
				if( message->length() != 8 )
				{
					message->release();
					ACE_ERROR ((LM_ERROR, ACE_TEXT("RealmLogic_Thread::svc connect packet length error\n")));
					continue;
				}
				unsigned int handle = *reinterpret_cast<unsigned int *>( message->rd_ptr() );
				message->rd_ptr( 4 );
				unsigned int service_addr = *reinterpret_cast<unsigned int *>( message->rd_ptr() );
				Realm_Service * service = reinterpret_cast<Realm_Service *>( service_addr );

				Realm_Client_Service * client_service;
				ACE_NEW_NORETURN (client_service, Realm_Client_Service(service));
				std::auto_ptr<Realm_Client_Service> auto_service( client_service );
				message->release();

				if( !client_service )
				{
					ACE_ERROR ((LM_ERROR, ACE_TEXT("RealmLogic_Thread::svc no more memory to accept new connect\n")));
					continue;
				}

				auto_service.release();
				client_service_map_[ handle ] = client_service;
			}
			break;

		case MB_CLOSE_PACKET:
			{
				if( message->length() != 4 )
				{
					message->release();
					ACE_ERROR ((LM_ERROR, ACE_TEXT("RealmLogic_Thread::svc close packet length error\n")));
					continue;
				}
				unsigned int handle = *reinterpret_cast<unsigned int *>( message->rd_ptr() );
				message->rd_ptr( 4 );

				ClientServiceMap::iterator itr = client_service_map_.find( handle );
				if( itr != client_service_map_.end() )
				{
					Realm_Client_Service * client_service = itr->second;
					delete client_service;
					message->release();
				}
				else
				{
					message->release();
					ACE_ERROR ((LM_ERROR, ACE_TEXT("RealmLogic_Thread::svc close packet error. cannot find the client_service\n")));
				}
			}
			break;

		default:
			ACE_ERROR ((LM_ERROR, ACE_TEXT("RealmLogic_Thread::svc unkown msg_type %d"), message->msg_type()));
			message->release();
			break;
		}
	}

	return 0;
}

int RealmLogic_Thread::open()
{
	// avtivate thread
	if( this->activate(THR_NEW_LWP) == -1 )
	{
		ACE_ERROR ((LM_ERROR, "%N:%l:%p\n", "RealmLogic_Thread:open: <activate> failed"));
		return -1;
	}

	this->running_ = true;

	return 0;
}

int RealmLogic_Thread::close()
{
	if( !this->running_ )
		return 0;

	ACE_Message_Block * hangup;
	ACE_NEW_RETURN (hangup, ACE_Message_Block(0, ACE_Message_Block::MB_HANGUP), -1);
	if( this->putq( hangup->duplicate() ) == -1 )
		ACE_ERROR_RETURN ((LM_ERROR, ACE_TEXT("%p\n"), ACE_TEXT("RealmLogic_Thread::close")), -1);
	hangup->release();

	if( this->wait() == -1 )
		ACE_ERROR ((LM_ERROR, ACE_TEXT ("%p.\n"), ACE_TEXT ("RealmLogic_Thread::close unable to stop thread")));

	this->running_ = false;

	return 0;
}
