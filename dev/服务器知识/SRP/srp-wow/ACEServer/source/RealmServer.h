
#ifndef __REALM_SERVER_H__
#define __REALM_SERVER_H__

#include <ace/singleton.h>
#include <ace/null_mutex.h>

class RealmNetwork_Thread;
class RealmLogic_Thread;
class ACE_Message_Block;

class RealmServer
{
public:
	RealmServer();
	~RealmServer();

	bool open();
	bool close();

	int putq( ACE_Message_Block * message );

	RealmNetwork_Thread * network_thread() const { return this->network_thread_; }
	RealmLogic_Thread * logic_thread() const { return this->logic_thread_; }

private:
	RealmNetwork_Thread * network_thread_;
	RealmLogic_Thread * logic_thread_;
};

typedef ACE_Singleton<RealmServer, ACE_Null_Mutex> RealmServerSingleton;
#define REALM_SERVER RealmServerSingleton::instance()

#endif // __REALM_SERVER_H__
