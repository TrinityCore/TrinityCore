
#include "RealmServer.h"
#include "RealmNetworkThread.h"
#include "RealmLogicThread.h"

RealmServer::RealmServer()
{
	this->network_thread_ = 0;
	this->logic_thread_ = 0;
}

RealmServer::~RealmServer()
{
	this->close();
}

bool RealmServer::open()
{
	ACE_NEW_RETURN( this->network_thread_, RealmNetwork_Thread(), false );
	std::auto_ptr<RealmNetwork_Thread> network( this->network_thread_ );

	ACE_NEW_RETURN( this->logic_thread_, RealmLogic_Thread(), false );
	std::auto_ptr<RealmLogic_Thread> logic( this->logic_thread_ );

	if( this->network_thread_->open() == -1 )
		return false;

	if( this->logic_thread_->open() == -1 )
		return false;

	ACE_DEBUG ((LM_DEBUG, "RealmServer::open Server Started OK\n"));

	network.release();
	logic.release();

	return true;
}

bool RealmServer::close()
{
	if( this->network_thread_ && this->network_thread_->close() == 0 )
	{
		ACE_DEBUG ((LM_DEBUG, "<RealmServer::close> network thread close ok"));

		delete this->network_thread_;
		this->network_thread_ = 0;
	}

	if( this->logic_thread_ && this->logic_thread_->close() == 0 )
	{
		ACE_DEBUG ((LM_DEBUG, "<RealmServer::close> logic thread close ok"));

		delete this->logic_thread_;
		this->logic_thread_ = 0;
	}

	return true;
}

int RealmServer::putq( ACE_Message_Block * message )
{
	return this->logic_thread_->putq( message );
}
